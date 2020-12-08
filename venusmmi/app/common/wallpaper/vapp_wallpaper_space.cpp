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
 *  vapp_wallpaper_space.cpp
 *
 * Project:
 * --------
 *  Venus Live Wallpaper
 *
 * Description:
 * ------------
 *  Home screen wave wallpaper class
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPACE__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_wallpaper_space.h"
#include "mmi_rp_app_venus_wallpaper_space_def.h"
#include "stdlib.h"
extern "C"
{
#include "cache_sw.h"
#include "custom_scatstruct.h"
#include "kal_general_types.h"
#include "gdi_const.h"
#include "gdi_lcd_config.h"
#include "lcd_sw_inc.h"
#include "kal_public_api.h"
#include "gdi_include.h"
#include "gdi_image.h"
#include "gdi_datatype.h"
#include "vrt_datatype.h"
#include "vrt_canvas.h"
}
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vapp_wallpaper.h"
#include "vapp_hs_def.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_frame.h"
#include "vfx_image_src.h"
#include "vfx_animation.h"
#include "vfx_draw_context.h"
#include "vfx_control.h"
#include "vfx_basic_type.h"
#include "vfx_input_event.h"
#include "vfx_auto_animate.h"
#include "vfx_frame_filter.h"

#ifdef __VENUS_3D_UI_ENGINE__
#include "gles2\gl2.h"
#include "vfx_owner_draw.h"

#ifdef WIN32
    #define GL_CHECK(x) \
            x; \
            { \
                GLenum glError = glGetError(); \
                VRT_EXT_ASSERT(glError == GL_NO_ERROR, glError, glError, glError); \
            }
#else
    #define GL_CHECK(x)    x;
#endif

#endif // #ifdef __VENUS_3D_UI_ENGINE__

/***************************************************************************** 
 * Constants
 *****************************************************************************/
static const int SCRN_W = GDI_LCD_WIDTH;
static const int SCRN_H = GDI_LCD_HEIGHT;
static const int FILTER_PROG_MAX = 1000;
static const int DURATION = 1000;
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
static const int BG_W = GDI_LCD_HEIGHT;     // Multi-page case
#else
static const int BG_W = GDI_LCD_WIDTH;      // Single-page case
#endif
/***************************************************************************** 
 * SpaceStar Implementations
 *****************************************************************************/
SpaceStar::SpaceStar():
    x(0), 
    y(0),
    m_z(0), 
    m_timeResidual(0), 
    m_bVisible(VFX_FALSE)
{

}

void SpaceStar::init(VfxBool bStartup)
{
    if(bStartup)
    {
        // during startup, make starts far, far away.
        const int initialRadius = 30;
        x = (rand() % SCRN_W) - H;
        y = (rand() % SCRN_H) - V;

        // if too far away from center, 
        // make it invisible at first.
        m_bVisible = (vfxAbs(x) < initialRadius) && (vfxAbs(y) < initialRadius);
        m_z = MAX_DEPTH * (rand() % 3);
    }
    else
    {
        // normal case
        m_bVisible = VFX_TRUE;
        x = (rand() % SCRN_W) - H;
        y = (rand() % SCRN_H) - V;
        m_z = rand() % MAX_DEPTH;
    }

    if((x == 0) && (y == 0 ))
    {
        x = 3;
    }
}

void SpaceStar::setVisible(VfxBool bVisible)
{
    m_bVisible = bVisible;
}

void SpaceStar::calculateXY(int z, int &xOut, int &yOut, int vanishPointOffsetX) const
{
    const float hh = ((x + vanishPointOffsetX) * NEAR_PLANE * 1.0) / (1.0 * NEAR_PLANE + z);
    const float vv = (y * NEAR_PLANE * 1.0) / (1.0 * NEAR_PLANE + z);
    xOut = hh + (H - vanishPointOffsetX);
    yOut = vv + V;
}

void SpaceStar::update(VfxMsec timePassed, VfxS32 viewOffsetX)
{
    timePassed += m_timeResidual;
    m_timeResidual = timePassed % timeStep;
    // update depth
    m_z -= timePassed / timeStep;
    
    if( m_z <= -NEAR_PLANE )
        m_z = MAX_DEPTH;
    
    int h, v;
    calculateXY(m_z, h, v, viewOffsetX);

    if( (h < 0) || (h > SCRN_W) ||
        (v < 0) || (v > SCRN_H) )
    {
        // re-init the star after it passed
        init();
        return;
    }
}

void SpaceStar::getCanonicalLine(VfxS32 viewOffsetX, VfxFloat &srcX, VfxFloat &srcY, VfxFloat &dstX, VfxFloat &dstY)
{
    if(!m_bVisible)
    {
        // put outside of view space
        srcX = srcY = dstX = dstY = -1.1f;
        return;
    }

    // Draw a line from "past" position to current position
    int h, v;
    calculateXY(m_z, h, v, viewOffsetX);
    int hOld, vOld;
    calculateXY(m_z + PAST_TRAIL_DEPTH, hOld, vOld, viewOffsetX);

    srcX = 2.0f * hOld / SCRN_W - 1.0f;
    srcY = 2.0f * vOld / SCRN_H - 1.0f;
    dstX = 2.0f * h / SCRN_W - 1.0f;
    dstY = 2.0f * v / SCRN_H - 1.0f;
    return;
}

void SpaceStar::drawToActiveGDILayer(VfxS32 viewOffsetX) const
{
    if(!m_bVisible)
        return;
    // Draw a line from "past" position to current position
    int h, v;
    calculateXY(m_z, h, v, viewOffsetX);
    int hOld, vOld;
    calculateXY(m_z + PAST_TRAIL_DEPTH, hOld, vOld, viewOffsetX);
    // TODO: change color according to distance to view plane. (should be blue-shift?)
    // int brightness = MIN(255, 170 - (m_z * 128 / (MAX_DEPTH + NEAR_PLANE)));
    // gdi_color c = gdi_act_color_from_rgb(255, 128 + brightness / 2, brightness, brightness);
    const gdi_color c = GDI_COLOR_WHITE;
    gdi_draw_antialiasing_line(h, v, hOld, vOld, c);
}

#ifdef __VENUS_3D_UI_ENGINE__
/***************************************************************************** 
 * VappHsSpaceOwnerDrawGL Implementations
 * For Venus 3D only
 *****************************************************************************/
class VappHsSpaceOwnerDrawGL : public VfxOwnerDraw
{
// definitions
private:
    static const int STAR_NUM = 50;
private:
    SpaceStar m_stars[STAR_NUM];
    VfxFloat m_lastUpdateTiming;
    VfxS32 m_viewOffsetX;
    VfxFloat m_bgOffsetX;
    VfxFloat m_bgWidth;
    VfxBool m_suspended;

// member data
public:
    

public:
	VappHsSpaceOwnerDrawGL();

public:
    void setSuspended(VfxBool bSuspended);
    static vrt_render_dirty_type_enum onUpdate(vrt_frame_visual_property_struct *target_frame,
                                            const vrt_frame_visual_property_struct *watch_frame,
                                            void *user_data,
                                            vrt_u32 user_data_size);
    
// Overridable
protected:
	virtual void onInit();
    virtual void onDeinit();

    virtual vrt_bool isUsingGLAPI() const;
    virtual void onInitResource();
    virtual void onDeinitResource();
    virtual void onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect);


// implementations
private:
    VfxMsec calculateOffsetTime(const VfxFloat timing) const;

private:
    GLuint m_progBg;        // draws background
    GLuint m_vsBg;
    GLuint m_fsBg;
    GLuint m_texBg;         // background texture ID
    int m_aBgPositionLoc;
    int m_uBgTexLoc;
    int m_uBgOffsetX;
    int m_uBgWidth;
    
    GLuint m_progLine;      // draws line
    int m_aPositionLoc;
    GLuint m_vsLine;      // draws line
    GLuint m_fsLine;      // draws line
};


VappHsSpaceOwnerDrawGL::VappHsSpaceOwnerDrawGL():
    m_lastUpdateTiming(0.0f),
    m_viewOffsetX(0),
    m_suspended(VFX_FALSE),
    m_progBg(0),
    m_progLine(0),
    m_aPositionLoc(-1),
    m_vsBg(0),
    m_fsBg(0),
    m_texBg(0),
    m_aBgPositionLoc(0),
    m_uBgTexLoc(0),
    m_bgOffsetX(0.0f),
    m_bgWidth(1.0f),
    m_uBgOffsetX(0),
    m_uBgWidth(0)
{
}

void VappHsSpaceOwnerDrawGL::onInit()
{
    VfxOwnerDraw::onInit();

    // we assume that wallpaper is created as same width of LCD
    m_bgWidth = GDI_LCD_WIDTH *1.0f / BG_W;

    for(int i = 0; i < STAR_NUM; ++i)
    {
        m_stars[i].init(VFX_TRUE);
    }
}

void VappHsSpaceOwnerDrawGL::setSuspended(VfxBool bSuspended)
{
    m_suspended = bSuspended;
}

void VappHsSpaceOwnerDrawGL::onDeinit()
{
	return VfxOwnerDraw::onDeinit();
}

vrt_bool VappHsSpaceOwnerDrawGL::isUsingGLAPI() const
{
    return VFX_TRUE;
}

VfxMsec VappHsSpaceOwnerDrawGL::calculateOffsetTime(const VfxFloat timing) const
{
	VfxFloat timeOffset = timing - m_lastUpdateTiming;
	if(timeOffset < 0.f)
		timeOffset = FILTER_PROG_MAX + timeOffset;
	return static_cast<VfxMsec>(timeOffset * DURATION / FILTER_PROG_MAX);
}

vrt_render_dirty_type_enum VappHsSpaceOwnerDrawGL::onUpdate(vrt_frame_visual_property_struct *target_frame,
                                                       const vrt_frame_visual_property_struct *watch_frame,
                                                       void *user_data,
                                                       vrt_u32 user_data_size)
{
    // retrieve this pointer
    VFX_DEV_ASSERT(sizeof(VappHsSpaceOwnerDrawGL*) == user_data_size);
    VappHsSpaceOwnerDrawGL *pThis = *reinterpret_cast<VappHsSpaceOwnerDrawGL**>(user_data);

    if(pThis->m_suspended && pThis->m_bgOffsetX == watch_frame->pos_z)
    {
        return VRT_RENDER_DIRTY_TYPE_NONE;
    }

    // update view point center
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    pThis->m_viewOffsetX = watch_frame->fpe_user_0;
#else
    pThis->m_viewOffsetX = 0;
#endif
 
    pThis->m_bgOffsetX = watch_frame->pos_z;
    pThis->m_bgWidth = watch_frame->bounds.size.width *1.0f / BG_W;

    // update star state
    const float timing = watch_frame->filter_timing;
    const VfxMsec timeOffset = pThis->calculateOffsetTime(timing);
    pThis->m_lastUpdateTiming = timing;

    for(int i = 0; i < pThis->STAR_NUM; ++i)
    {
        pThis->m_stars[i].update(timeOffset, pThis->m_viewOffsetX);
    }
    
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

static GLuint loadResourceShader(GLenum type, VfxResId resId)
{
    GLuint shader = 0;
    // Create the shader object
    shader = glCreateShader(type);
    if(shader == 0)
        return 0;

    const char *start = (const char*)GetBinary(resId);
    if(start == NULL)
    {
        VFX_DEV_ASSERT(0);
        return 0;
    }
    // first byte is type, 2~5 is size
    const unsigned char *header = (const unsigned char*)start;
    U32 size = *((U32*)(header+1));
    start += 8;

#ifdef __MTK_TARGET__
    char *shaderSrc = (vrt_char*)start;
    GLenum MALI_SHADER_BINARY_ARM = 0x8F60;
    GL_CHECK(glShaderBinary (1, &shader, MALI_SHADER_BINARY_ARM, (const void* )shaderSrc, size));
#else
    char *source = (char *)applib_asm_alloc_anonymous_nc(sizeof(char) * (size + 1));
    memcpy(source, start, size);
    // WORKAROUND: add null-terminal after source from res
    source[size] = 0;

    // Load the shader source
    glShaderSource ( shader, 1, (const GLchar**)&source, NULL );
    GLint glError = glGetError();
    VRT_DEV_ASSERT(glError == GL_NO_ERROR);

    // Compile the shader
    glCompileShader ( shader );
#endif

    // Check the compile status
    GLint compiled = 0;
    glGetShaderiv ( shader, GL_COMPILE_STATUS, &compiled );
    if(!compiled) 
    {
        glDeleteShader ( shader );
        return 0;
    }
    return shader;
}

static void createShaderProgramFromResource(VfxResId vertShaderId, VfxResId fragShaderId,
                                            GLuint &vertShader, GLuint &fragShader, GLuint &shaderProg)
{
    GLuint vertexShader = 0;
    GLuint fragmentShader = 0;
    GLuint programObject = 0;
    GLint linked = 0;

    // Load the vertex/fragment shaders
    vertexShader = loadResourceShader( GL_VERTEX_SHADER, vertShaderId );
    fragmentShader = loadResourceShader( GL_FRAGMENT_SHADER, fragShaderId );    

    // Create the program object
    programObject = GL_CHECK(glCreateProgram());
    VFX_DEV_ASSERT(programObject);
    GL_CHECK(glAttachShader(programObject, vertexShader));
    GL_CHECK(glAttachShader(programObject, fragmentShader));
    GL_CHECK(glLinkProgram(programObject));
    
    // Check the link status
    GL_CHECK(glGetProgramiv (programObject, GL_LINK_STATUS, &linked ));
    if(!linked) 
    {
        VFX_DEV_ASSERT(0);
        glDeleteProgram (programObject);
        if(vertexShader)
        {
            glDeleteShader(vertexShader);
        }
        if(fragmentShader)
        {
            glDeleteShader(fragmentShader);
        }
    }
    
    vertShader = vertexShader;
    fragShader = fragmentShader;
    shaderProg = programObject;
    return;
}

void VappHsSpaceOwnerDrawGL::onInitResource()
{
    // Program to draw line
    createShaderProgramFromResource(VAPP_WALLPAPER_SPACE_LINE_VS, VAPP_WALLPAPER_SPACE_LINE_FS,
                                    m_vsLine, m_fsLine, m_progLine);
    m_aPositionLoc = GL_CHECK( glGetAttribLocation (m_progLine, "aPosition" ) );
    
    // Program to draw background
    createShaderProgramFromResource(VAPP_WALLPAPER_SPACE_BG_VS, VAPP_WALLPAPER_SPACE_BG_FS,
                                    m_vsBg, m_fsBg, m_progBg);
    m_aBgPositionLoc = GL_CHECK(glGetAttribLocation(m_progBg, "aPosition" ) );
    m_uBgTexLoc = GL_CHECK(glGetUniformLocation(m_progBg, "uBgTex"));
    m_uBgOffsetX = GL_CHECK(glGetUniformLocation(m_progBg, "bgOffsetX"));
    m_uBgWidth = GL_CHECK(glGetUniformLocation(m_progBg, "bgWidth"));
    m_texBg = VappWallpaper::loadResourceTexture(VAPP_WALLPAPER_IMG_SPACE_BG);
}

void VappHsSpaceOwnerDrawGL::onDeinitResource()
{
    if (m_texBg)
    {
        glDeleteTextures(1, &m_texBg);
        m_texBg = 0;
    }

    if(m_vsBg)
    {
        glDeleteShader(m_vsBg);
        m_vsBg = 0;
    }
    
    if(m_fsBg)
    {
        glDeleteShader(m_fsBg);
        m_fsBg = 0;
    }
    
    if(m_progBg)
    {
        glDeleteProgram(m_progBg);
        m_progBg = 0;
    }
    
    if(m_vsLine)
    {
        glDeleteShader(m_vsLine);
        m_vsLine = 0;
    }
    
    if(m_fsLine)
    {
        glDeleteShader(m_fsLine);
        m_fsLine = 0;
    }
    
    if(m_progLine)
    {
        glDeleteProgram(m_progLine);
        m_progLine = 0;
    }

    glClearColor ( 0.0f, 0.0f, 0.0f, 1.0f );
}

void VappHsSpaceOwnerDrawGL::onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect)
{
    // store original viewport
    GLint viewportsize[4];    
    GL_CHECK( glGetIntegerv(GL_VIEWPORT, viewportsize) );
    
    // Set the viewport
    GL_CHECK(glViewport(dstRect.origin.x, 
                        dstBuffer.height - (dstRect.origin.y + dstRect.size.height),
                        dstRect.size.width, 
                        dstRect.size.height));

    // Clear the color buffer
    glClearColor ( 0.0f, 0.0f, 1.0f, 1.0f );
    glClear ( GL_COLOR_BUFFER_BIT );

    // Draw background
    // bind texture & program
    GL_CHECK (glUseProgram ( m_progBg ) );
    glActiveTexture ( GL_TEXTURE0 );
    glBindTexture ( GL_TEXTURE_2D, m_texBg );
    glUniform1i ( m_uBgTexLoc, 0 );
    glUniform1f (m_uBgOffsetX, m_bgOffsetX);
    glUniform1f (m_uBgWidth, m_bgWidth);

    // draw a rect
    GLfloat vVertices[] = {-1.0f,  1.0f, 
                           -1.0f, -1.0f,
                            1.0f,  1.0f,
                            1.0f, -1.0f,};
    GL_CHECK (glVertexAttribPointer(m_aBgPositionLoc, 2, GL_FLOAT, GL_FALSE, 0, vVertices));
    GL_CHECK (glEnableVertexAttribArray(m_aBgPositionLoc));
    GL_CHECK (glDrawArrays(GL_TRIANGLE_STRIP, 0, 4));
    
    
    // Draw stars
    GL_CHECK (glUseProgram ( m_progLine ) );

    // Load the vertex data
    GLfloat starVertices[STAR_NUM * 2 * 2];
    for(VfxS32 i = 0; i < STAR_NUM; ++i)
    {
        m_stars[i].getCanonicalLine(m_viewOffsetX, 
                                    starVertices[i * 4 + 0],
                                    starVertices[i * 4 + 1],
                                    starVertices[i * 4 + 2],
                                    starVertices[i * 4 + 3]);
    }
    GL_CHECK (glVertexAttribPointer(m_aPositionLoc, 2, GL_FLOAT, GL_FALSE, 0, starVertices));
    GL_CHECK (glEnableVertexAttribArray(m_aPositionLoc));
    GL_CHECK (glLineWidth(1.0f));
    GL_CHECK (glDrawArrays(GL_LINES, 0, STAR_NUM));

    // restore viewport
    GL_CHECK( glViewport( viewportsize[0], viewportsize[1], viewportsize[2], viewportsize[3]) );
}

#else
/***************************************************************************** 
 * VappHsSpaceFilter
 * For Venus 2D
 *****************************************************************************/
class VappHsSpaceFilter : public VfxFrameFilter
{
// definitions
private:
    static const int STAR_NUM = 50;
private:
    SpaceStar m_stars[STAR_NUM];
    VfxFloat m_lastUpdateTiming;
    VfxS32 m_viewOffsetX;
    VfxBool m_suspended;

public:
	VappHsSpaceFilter();

public:
    void setSuspended(VfxBool bSuspended);
    static vrt_render_dirty_type_enum onUpdate(vrt_frame_visual_property_struct *target_frame,
                                            const vrt_frame_visual_property_struct *watch_frame,
                                            void *user_data,
                                            vrt_u32 user_data_size);
    
// Overridable
protected:
    virtual BufferModeEnum onGetBufferMode() const;
    virtual VfxBool onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat timing);
	virtual void onInit();
    virtual void onDeinit();

// implementations
private:
    VfxMsec calculateOffsetTime(const VfxFloat timing) const;
};

VappHsSpaceFilter::VappHsSpaceFilter():
    m_lastUpdateTiming(0.0f),
    m_viewOffsetX(0),
    m_suspended(VFX_FALSE)
{
}

void VappHsSpaceFilter::onInit()
{
    VfxFrameFilter::onInit();

    for(int i = 0; i < STAR_NUM; ++i)
    {
        m_stars[i].init(VFX_TRUE);
    }
}

void VappHsSpaceFilter::setSuspended(VfxBool bSuspended)
{
    m_suspended = bSuspended;
}

void VappHsSpaceFilter::onDeinit()
{
	return VfxFrameFilter::onDeinit();
}

VfxFrameFilter::BufferModeEnum VappHsSpaceFilter::onGetBufferMode() const
{
    return VfxFrameFilter::BUFFER_MODE_IN_PLACE;
}

VfxMsec VappHsSpaceFilter::calculateOffsetTime(const VfxFloat timing) const
{
	VfxFloat timeOffset = timing - m_lastUpdateTiming;
	if(timeOffset < 0.f)
		timeOffset = FILTER_PROG_MAX + timeOffset;
	return static_cast<VfxMsec>(timeOffset * DURATION / FILTER_PROG_MAX);
}

vrt_render_dirty_type_enum VappHsSpaceFilter::onUpdate(vrt_frame_visual_property_struct *target_frame,
                                                       const vrt_frame_visual_property_struct *watch_frame,
                                                       void *user_data,
                                                       vrt_u32 user_data_size)
{
    // retrieve this pointer
    VFX_DEV_ASSERT(sizeof(VappHsSpaceFilter*) == user_data_size);
    VappHsSpaceFilter *pThis = *reinterpret_cast<VappHsSpaceFilter**>(user_data);

    if(pThis->m_suspended)
    {
        return VRT_RENDER_DIRTY_TYPE_NONE;
    }

    // update view point center
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    pThis->m_viewOffsetX = watch_frame->fpe_user_0;
#else
    pThis->m_viewOffsetX = 0;
#endif

    // update star state
    const float timing = watch_frame->filter_timing;
    const VfxMsec timeOffset = pThis->calculateOffsetTime(timing);
    pThis->m_lastUpdateTiming = timing;

    if(0 == timeOffset)
    {
        return VRT_RENDER_DIRTY_TYPE_NONE;
    }

    for(int i = 0; i < pThis->STAR_NUM; ++i)
    {
        pThis->m_stars[i].update(timeOffset, pThis->m_viewOffsetX);
    }
    
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

VfxBool VappHsSpaceFilter::onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat timing)
{
    VFX_DEV_ASSERT(VRT_COLOR_TYPE_RGB565 == inBuf.colorFormat ||
                   VRT_COLOR_TYPE_RGB888 == inBuf.colorFormat);
    

    // must use physical address here to prevent GDI create layer assertion since 
    // it will verify the layer buffer address is not cached.
    
    VfxU8 *physicalAddr = outBuf;
    
    // unroll the definition of VRT_RENDER_DCACHED_LAYER because
    // VRT_RENDER_DCACHED_LAYER is broken under Libra35 build.
    #if (defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__))
    
    #if VRT_RENDER_DCACHED_LAYER 
        #define VRT_RENDER_DCACHE_LINE_SIZE 32
    #else
        #define VRT_RENDER_DCACHE_LINE_SIZE 1
    #endif
        // flush buffer
        const VfxU32 line_start_addr = (VfxU32)outBuf;
        const VfxU32 line_end_addr = line_start_addr + inBuf.height * inBuf.pitchBytes;
        
        /* align line start addr to 32-byte */
        const VfxU32 line_aligned_start_addr = line_start_addr & ~(VRT_RENDER_DCACHE_LINE_SIZE - 1);
        /* clean size must be mutiples of cache line size */
        const VfxU32 line_cache_line_size = (((line_end_addr - line_aligned_start_addr) + (VRT_RENDER_DCACHE_LINE_SIZE - 1)) / VRT_RENDER_DCACHE_LINE_SIZE) * VRT_RENDER_DCACHE_LINE_SIZE;            
        
        /* clean (flush) values to physical adress and invalidate the cache */
        clean_and_invalidate_dcache((kal_uint32)line_aligned_start_addr, (kal_uint32)line_cache_line_size);
        
        physicalAddr = (VfxU8*)virt_to_phys((U32*)line_start_addr);
        
    #endif /* VRT_RENDER_DCACHED_LAYER */

    // accquire GDI layer.
    // so that SpaceStar can draw line on the canvas.
    // note: VRT task should own GDI lock by now.
    GDI_RESULT res = GDI_FAILED;
    GDI_HANDLE layer = GDI_LAYER_EMPTY_HANDLE;
    gdi_color_format cf = GDI_COLOR_FORMAT_16;
    switch(inBuf.colorFormat)
    {
        case VRT_COLOR_TYPE_RGB565:
            cf = GDI_COLOR_FORMAT_16;
            break;
        case VRT_COLOR_TYPE_RGB888:
            cf = GDI_COLOR_FORMAT_24;
            break;
    }
    
    res = gdi_layer_create_cf_using_outside_memory(cf, 
                                                   0, 0, 
                                                   inBuf.width, inBuf.height, 
                                                   &layer,
                                                   physicalAddr, 
                                                   inBuf.height * inBuf.pitchBytes);
    VFX_ASSERT(GDI_SUCCEED == res);
    gdi_layer_push_and_set_active(layer);

    // draw the stars with GDI
    for(int i = 0; i < STAR_NUM; ++i)
    {
        m_stars[i].drawToActiveGDILayer(m_viewOffsetX);
    }
    
    gdi_layer_pop_and_restore_active();
    gdi_layer_free(layer);
    layer = GDI_LAYER_EMPTY_HANDLE;

    return VFX_TRUE;
}

#endif  // __VENUS_3D_UI_ENGINE__

/***************************************************************************** 
 * Home screen UI componet: Space wallpaper
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("Space Wallpaper", VappWallpaperSpace, VappWallpaper);

VappWallpaperSpace::VappWallpaperSpace():
    m_wallpaperFilter(NULL),
    m_animTimeline(NULL),
    m_centerMoveTimeline(NULL),
    m_bgFrame(NULL)
{
}

void VappWallpaperSpace::onCreateView()
{
#ifdef __VENUS_3D_UI_ENGINE__
    // Then, we attach the filter to wallpaper itself
    VFX_OBJ_CREATE(m_wallpaperFilter, VappHsSpaceOwnerDrawGL, this);
    setOwnerDraw(m_wallpaperFilter);
    // 3D case does not need BG frame
    m_bgFrame = NULL;
    // in 3D case, posZ is the background offset.
    // init to center.
    setPosZ(0.5);
#else
    VFX_OBJ_CREATE(m_wallpaperFilter, VappHsSpaceFilter, this);
    setFilter(m_wallpaperFilter);
    // force RGB565 format
    setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
    // create the wallpaper "background" frame
    // Note: so that the background can be cached
    m_bgFrame = NULL;
    VFX_OBJ_CREATE(m_bgFrame, VfxFrame, this);
    VfxImageSrc bgImg(VAPP_WALLPAPER_IMG_SPACE_BG);
    m_bgFrame->setImgContent(bgImg);
    m_bgFrame->setPos(0, 0);
    m_bgFrame->setSize(bgImg.getSize());
    // force RGB565 format
    m_bgFrame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    m_bgFrame->setAutoAnimate(VFX_TRUE);
#endif
#endif

    // initilaize timeline for filter animation
    VfxFloatTimeline *timeline = NULL;
    VFX_OBJ_CREATE(timeline, VfxFloatTimeline, this);
    timeline->setTarget(this);
    timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
    timeline->setFromValue(0.0f);
    timeline->setToValue(FILTER_PROG_MAX);
    timeline->setDurationTime(DURATION);
    timeline->setAutoReversed(VFX_FALSE);
    timeline->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    m_animTimeline = timeline;

    // update function
    setPropertyEffectCallback(this, &VappHsSpaceDrawer::onUpdate, &m_wallpaperFilter, sizeof(m_wallpaperFilter), VRT_FPE_TRIGGER_TYPE_EVERYTIME);

#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    // timeline for viewpoint movement animation
    // this timeline is triggered when desktop is changing
    VFX_OBJ_CREATE(m_centerMoveTimeline, VfxFloatTimeline, this);
    m_centerMoveTimeline->setTarget(this);
    m_centerMoveTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FPE_USER_0);
    m_centerMoveTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
    // TODO: query total page count through HomeScreen API
    const int totalPage = 3;
    // assume we're in leftmost desktop
    const int initialScreenOffset = -(SCRN_W * (totalPage - 1)) / 2;
    const int initialStarOffset = screenOffsetToStarOffset(initialScreenOffset);
    setFpeUser0(initialStarOffset);
    m_centerMoveTimeline->setIsFromCurrent(VFX_TRUE);
    m_centerMoveTimeline->setFromValue(initialStarOffset); // workaround timeline
    m_centerMoveTimeline->setToValue(initialStarOffset);
    m_centerMoveTimeline->setDurationTime(400);
#else
    m_centerMoveTimeline = NULL;
#endif 
    
}

void VappWallpaperSpace::onReleaseView()
{
}

VfxBool VappWallpaperSpace::onAllowSuspendOnSwipe()
{
    return VFX_FALSE;
}

MMI_IMG_ID VappWallpaperSpace::getThumbnail()
{
    return IMG_ID_VAPP_WALLPAPER_SPACE_THUMBNAIL;
}

void VappWallpaperSpace::getName(VfxWString &wallpaperName)
{
    wallpaperName.loadFromRes(STR_ID_WALLPAPER_VUI_LIVE_SPACE);
    return;
}

void VappWallpaperSpace::onDraw(VfxDrawContext &dc)
{
    VappWallpaper::onDraw(dc);
}

void VappWallpaperSpace::onWidgetDropped(VfxPoint pos, VfxControl *targetWidget)
{
    VappWallpaper::onWidgetDropped(pos, targetWidget);
}

VfxBool VappWallpaperSpace::onPenInput(VfxPenEvent &e)
{
    if(VFX_PEN_EVENT_TYPE_DOWN == e.type)
	{
        const VfxPoint &pos = e.getRelDownPos(this);
    }   
    // Bypass pen event since we're wallpaper
    return VappWallpaper::onPenInput(e);
}

void VappWallpaperSpace::onSuspend()
{
    m_animTimeline->stop();
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    m_centerMoveTimeline->stop();
#endif
    m_wallpaperFilter->setSuspended(VFX_TRUE);
    VappWallpaper::onSuspend();
}

void VappWallpaperSpace::onResume()
{
    m_animTimeline->start();
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    if(m_centerMoveTimeline)
    {
        const VfxFloat fromVal = m_centerMoveTimeline->getToValue();
        m_centerMoveTimeline->setFromValue(fromVal);
        m_centerMoveTimeline->start();
    }
#endif
    m_wallpaperFilter->setSuspended(VFX_FALSE);
    VappWallpaper::onResume();
}
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
static void moveDesktop(VfxFrame* targetFrame, VfxFloat cursor, VfxS32 frameWidth)
{ 
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
#ifdef __VENUS_3D_UI_ENGINE__
    // 3D case, use pos_z for owner draw background move
    cursor = vfxMax(0.0f, vfxMin(1.0f, cursor));
    const float newX = ((VfxS32)SCRN_W - frameWidth) * cursor;
    if(targetFrame)
    {
        targetFrame->setPosZ(newX / frameWidth);
    }
#else
    const float newX = ((VfxS32)SCRN_W - frameWidth) * cursor;
    // 2D case, move BG frame directly
    if(targetFrame)
    {
        targetFrame->setPos(newX, targetFrame->getPos().y);
    }
#endif     
    VfxAutoAnimate::commit();
}
#endif 
void VappWallpaperSpace::onDesktopCursorChanged(VfxFloat curPos, VfxFloat oldPos)
{
#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_HOMESCREEN_WALLPAPER_LITE_DISPLAY__)
    // change star moving direction
    VFX_DEV_ASSERT(m_centerMoveTimeline);
    if(m_centerMoveTimeline)
    {
        #ifndef __VENUS_3D_UI_ENGINE__
        const float newOffsetX = screenOffsetToStarOffset((curPos - 0.5f) * (m_bgFrame ? m_bgFrame->getSize().width : BG_W));
        #else
        const float newOffsetX = screenOffsetToStarOffset((curPos - 0.5f) * BG_W);
        #endif
        m_centerMoveTimeline->setIsFromCurrent(VFX_TRUE);
        m_centerMoveTimeline->setToValue(newOffsetX);
        m_centerMoveTimeline->start();
    }
#ifndef __VENUS_3D_UI_ENGINE__
    moveDesktop(m_bgFrame, curPos, m_bgFrame->getSize().width);
#else
    // we assume that KTX width is the LCD height.
    moveDesktop(this, curPos, BG_W);
#endif
#endif
}

float VappWallpaperSpace::screenOffsetToStarOffset(int screenOffset)
{

#if defined(__MMI_MAINLCD_240X320__)
    // for MAUI_02639247: 
    // on smaller screen, the center of galaxy is 
    // quite small, so if we don't reduce the movement
    // it would look strange.
    // This is bakcground image dependent.
    return screenOffset / 4;
#else
    return screenOffset * 2 / 5;
#endif

}

#endif /* __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPACE__ */
