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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_features.h"
#include "vapp_screen_lock_def.h"

#ifdef __COSMOS_3D_SCREEN_LOCK__

#include "vfx_config.h"

#include <stdio.h>
#include "vtst_rt_main.h"
#include "vfx_frame.h"
#include "vfx_owner_draw.h"
#include "gles2\gl2.h"
#include "gles2\gl2ext.h"

#include "fs_type.h"
#include "fs_func.h"

#include "vapp_screen_lock_steam_owner_draw.h"
//#include "mmi_rp_vapp_screen_lock_def.h"
#include "mmi_rp_vapp_screen_lock_steam_def.h"

extern "C"
{
#include "CustDataRes.h"   // for GetImage
#include "gdi_include.h"
#include "app_mem_med.h"   // for applib_asm_free_anonymous
#include "gdi_primitive.h" // for gdi_bits_per_pixel
#include "Wgui_categories_util.h"
}

//the use of read the stroke ccontent back
PU8 g_mem_buffer = NULL;
GLint g_readType, g_readFormat;
VfxS32 g_bytesPerPixel=0;
VfxS32 g_gdi_type = 0;


extern "C" GDI_RESULT gdi_image_parse_info(
                gdi_image_src_enum src_type,
                U8 *img_src,
                U8 **data_ptr,
                U8 *img_type,
                S32 *img_size,
                S32 *frame_number,
                S32 *width,
                S32 *height);


/*****************************************************************************
 * Define
 *****************************************************************************/

//#define GL_SHADER_FILE_MODE_TEST 

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

#define VERTEX_POS_SIZE 3
#define VERTEX_COLOR_SIZE 4
#define VERTEX_TEXCOOR_SIZE 3

///
// Create a shader object, load the shader source, and
// compile the shader.
//
GLuint VappScreenLockLoadShader ( GLenum type, const U16 resId)
{
    GLuint shader;
    GLint compiled;
    U32 size = 0;
    char *shaderSrc = NULL;
    vrt_bool isBinary = VRT_FALSE;
    GLenum glError;

    // Create the shader object
    shader = glCreateShader ( type );

    if ( shader == 0 )
    {
        return 0;
    }

    // TODO: implement vrt_sys_res_shader_lock
    //shaderSrc = (vrt_char *)vrt_sys_res_shader_lock(vrtshader->getResourceId());

    const char *start = (const char*)GetBinary(resId);
    if (start == NULL)
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
        GL_CHECK( glShaderBinary (1, &shader, MALI_SHADER_BINARY_ARM, (const void* )shaderSrc, size) );
    }
    else
    {
        // Load the shader source
        GL_CHECK( glShaderSource ( shader, 1, (const char **)&shaderSrc, NULL ) );

        // Compile the shader
        GL_CHECK( glCompileShader ( shader ) );

        // Check the compile status
        GL_CHECK( glGetShaderiv ( shader, GL_COMPILE_STATUS, &compiled ) );

        if ( !compiled )
        {
            GL_CHECK( glDeleteShader ( shader ) );
            return 0;
        }
    }
    return shader;
}


///
// Create a shader object, load the shader source, and
// compile the shader.
//
GLuint VappScreenLockLoadShaderFileMode ( GLenum type, const char *shaderSrc )
{
   GLuint shader;
   GLint compiled;
   
   // Create the shader object
   shader = glCreateShader ( type );

   if ( shader == 0 )
    return 0;

   // Load the shader source
   GL_CHECK( glShaderSource ( shader, 1, &shaderSrc, NULL ) );
   
   // Compile the shader
   GL_CHECK( glCompileShader ( shader ) );

   // Check the compile status
   GL_CHECK( glGetShaderiv ( shader, GL_COMPILE_STATUS, &compiled ) );

   if ( !compiled ) 
   {
      GL_CHECK( glDeleteShader ( shader ) );
      return 0;
   }
   return shader;
}

typedef struct KTX_header_t {
    vrt_u8  identifier[12];
    vrt_u32 endianness;
    vrt_u32 glType;
    vrt_u32 glTypeSize;
    vrt_u32 glFormat;
    vrt_u32 glInternalFormat;
    vrt_u32 glBaseInternalFormat;
    vrt_u32 pixelWidth;
    vrt_u32 pixelHeight;
    vrt_u32 pixelDepth;
    vrt_u32 numberOfArrayElements;
    vrt_u32 numberOfFaces;
    vrt_u32 numberOfMipmapLevels;
    vrt_u32 bytesOfKeyValueData;
} KTX_header;

GLuint CreateTexture2D(const U16 resId, GLenum type, VfxBool isKTX = VFX_FALSE)
{
   // Texture object handle
   GLuint textureId;

   GLenum error;

   // Use tightly packed data
   GL_CHECK( glPixelStorei ( GL_UNPACK_ALIGNMENT, 1 ) );

   // Generate a texture object
   GL_CHECK( glGenTextures ( 1, &textureId ) );

   // Bind the texture object
   GL_CHECK( glBindTexture ( GL_TEXTURE_2D, textureId ) );


   S32 imgWidth, imgHeight;
   PU8 mem_buffer;


   if (!isKTX)
   {
    
       gdi_image_get_dimension_id(resId, &imgWidth, &imgHeight);

       GDI_RESULT res = GDI_FAILED;
       GDI_HANDLE imgLayer = GDI_LAYER_EMPTY_HANDLE;

       if(type == GL_RGB)
       {
           mem_buffer = (PU8)applib_asm_alloc_anonymous_nc(imgWidth * imgHeight * gdi_bits_per_pixel(GDI_COLOR_FORMAT_16) / 8);
           res = gdi_layer_create_cf_using_outside_memory(GDI_COLOR_FORMAT_16 ,
                                                              0, 0,
                                                              imgWidth,
                                                              imgHeight,
                                                              &imgLayer,
                                                              (PU8)mem_buffer,
                                                              imgWidth * imgHeight * gdi_bits_per_pixel(GDI_COLOR_FORMAT_16) / 8);
           gdi_layer_push_and_set_active(imgLayer);
           gdi_image_draw_id(0, 0, resId);
           gdi_layer_pop_and_restore_active();
           gdi_layer_free(imgLayer);

            glTexImage2D ( GL_TEXTURE_2D, 0, type, imgWidth, imgHeight, 0, type, GL_UNSIGNED_SHORT_5_6_5, mem_buffer );
       }
       else
       {
           mem_buffer = (PU8)applib_asm_alloc_anonymous_nc(imgWidth * imgHeight * gdi_bits_per_pixel(GDI_COLOR_FORMAT_32) / 8);
           res = gdi_layer_create_cf_using_outside_memory(GDI_COLOR_FORMAT_32 ,
                                                              0, 0,
                                                              imgWidth,
                                                              imgHeight,
                                                              &imgLayer,
                                                              (PU8)mem_buffer,
                                                              imgWidth * imgHeight * gdi_bits_per_pixel(GDI_COLOR_FORMAT_32) / 8);
           gdi_layer_push_and_set_active(imgLayer);
           gdi_image_draw_id(0, 0, resId);
           gdi_layer_pop_and_restore_active();
           gdi_layer_free(imgLayer);

           glTexImage2D ( GL_TEXTURE_2D, 0, type, imgWidth, imgHeight, 0, type, GL_UNSIGNED_BYTE, mem_buffer );
       }
       
       applib_asm_free_anonymous(mem_buffer);
   }
   else
   {   
        mem_buffer = (U8 *)GetImage(resId);
        vrt_u8 img_type = mem_buffer[0]; //GDI_IMAGE_TYPE_KTX;
        vrt_u8 *data_ptr;
        vrt_u32 faceLodSize = 0;
        S32 img_size;
        S32 frame_number;
        
        gdi_image_parse_info(GDI_IMAGE_SRC_FROM_RESOURCE, mem_buffer, &data_ptr, &img_type, &img_size, &frame_number, &imgWidth, &imgHeight);

        KTX_header header;        
        memcpy(&header, data_ptr, sizeof(KTX_header));
        data_ptr += sizeof(KTX_header) + header.bytesOfKeyValueData;
        memcpy(&faceLodSize, data_ptr, sizeof(vrt_u32));
        data_ptr += sizeof(vrt_u32);

        GL_CHECK( glCompressedTexImage2D ( GL_TEXTURE_2D, 0, header.glInternalFormat, header.pixelWidth, header.pixelHeight, 0, faceLodSize , data_ptr) ); 
   }
   
   // Set the filtering mode
   GL_CHECK( glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST ) );
   GL_CHECK( glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST ) );

   GL_CHECK( glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE) );
   GL_CHECK( glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE) );

   return textureId;

}


/*****************************************************************************
 * Class VappSteamScreenLockDroplet
 *****************************************************************************/
VappSteamScreenLockDroplet::VappSteamScreenLockDroplet()
{
    m_weight = 0;
    m_acceleration = 0;
}


VappSteamScreenLockDroplet::~VappSteamScreenLockDroplet()
{
}


/*****************************************************************************
 * Class VappSteamScreenLockOwenerDraw
 *****************************************************************************/
 
VappSteamScreenLockOwenerDraw::VappSteamScreenLockOwenerDraw(VfxSize size)
{
    m_dataStroke.programObject = 0;
    m_dataGlass.programObject = 0;
    m_dataDroplet.programObject = 0;

    m_isInit = VFX_TRUE;
    m_gravity[0] = 0; 
    m_gravity[1] = -1;
    m_gravity[2] = 0;
    m_redrawWaterDrop = VFX_TRUE;

    m_acceleration = 7; 
    m_frictionFactor = 0.3;
    m_defaultNormalForce = 500;
    m_fogUpTimes = 0;
    m_size = size;
}


void VappSteamScreenLockOwenerDraw::onInit()
{
    VfxOwnerDraw::onInit();

    m_dropWaterList.init(this);
}


void VappSteamScreenLockOwenerDraw::onInitResource()
{
    GLenum error;
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint programObject;
    GLint linked;

/******************/
/* Stroke Program */
/******************/

#ifdef GL_SHADER_FILE_MODE_TEST
    FS_HANDLE handle;
    char vShaderStr[5000];
    char fShaderStr[5000];
    UINT fs,fsize;

    handle = FS_Open ((const WCHAR *) L"c:\\stroke.vs",FS_READ_ONLY);
    FS_GetFileSize(handle,&fs);
    FS_Read (handle, vShaderStr,fs,&fsize);
    vShaderStr[fsize] = '\0';
    FS_Close (handle);

    handle = FS_Open ((const WCHAR *) L"c:\\stroke.fs",FS_READ_ONLY);
    FS_GetFileSize(handle,&fs);
    FS_Read (handle, fShaderStr,fs,&fsize);
    fShaderStr[fsize] = '\0';
    FS_Close (handle);

    // file mode
    vertexShader = VappScreenLockLoadShaderFileMode( GL_VERTEX_SHADER, vShaderStr );
    fragmentShader = VappScreenLockLoadShaderFileMode( GL_FRAGMENT_SHADER, fShaderStr );
#else
    // Load the vertex/fragment shaders
    vertexShader = VappScreenLockLoadShader ( GL_VERTEX_SHADER, VAPP_STEAM_SCREEN_LOCK_STROKE_VERTEX_SHADER );
    fragmentShader = VappScreenLockLoadShader ( GL_FRAGMENT_SHADER, VAPP_STEAM_SCREEN_LOCK_STROKE_FRAGMENT_SHADER );
#endif

    // Create the program object
    programObject = GL_CHECK( glCreateProgram ( ) );

    VFX_DEV_ASSERT(programObject);

    GL_CHECK( glAttachShader ( programObject, vertexShader ) );
    GL_CHECK( glAttachShader ( programObject, fragmentShader ) );

    // Link the program
    GL_CHECK( glLinkProgram ( programObject ) );

    // Check the link status
    GL_CHECK( glGetProgramiv ( programObject, GL_LINK_STATUS, &linked ) );

    if ( !linked )
    {
        GLint infoLen = 0;
        GL_CHECK( glGetProgramiv(programObject, GL_INFO_LOG_LENGTH, &infoLen) );
        if(infoLen > 1)
        {
//            glGetProgramInfoLog(programObject, infoLen, NULL, vShaderStr);
//            kal_printf("Error linking program:\n%s\n", vShaderStr);
        }
        GL_CHECK( glDeleteProgram(programObject) );

        VFX_DEV_ASSERT(0);
    }

    m_dataStroke.uTextureLoc = GL_CHECK( glGetUniformLocation ( programObject, "uTexture" ) );
    m_dataStroke.uTextureLevelLoc = GL_CHECK( glGetUniformLocation ( programObject, "uTextureLevel" ) );
    m_dataStroke.uViewPortSizeLoc = GL_CHECK( glGetUniformLocation(programObject, "uViewportSize") );
    m_dataStroke.uBackgroundLoc = GL_CHECK( glGetUniformLocation(programObject, "uBackground") );
    m_dataStroke.uConstAlphaLoc = GL_CHECK( glGetUniformLocation(programObject, "uConstAlpha") );
    m_dataStroke.uNeedFogUpLoc = GL_CHECK( glGetUniformLocation(programObject, "uNeedsFogUp") );
    m_dataStroke.aPositionLoc = GL_CHECK( glGetAttribLocation (programObject, "aPosition" ) );
    m_dataStroke.aTexCoordLoc = GL_CHECK( glGetAttribLocation (programObject, "aTexCoord" ) );
    m_dataStroke.textureId = CreateTexture2D(IMG_ID_VAPP_STEAM_SCREEN_LOCK_BRUSH_TEX, GL_RGB);
    m_dataStroke.textureLevelId = CreateTexture2D (IMG_ID_VAPP_STEAM_SCREEN_LOCK_LEVEL_MAP, GL_RGB, VFX_TRUE);
    m_dataStroke.uFrameAnchorLoc = GL_CHECK( glGetUniformLocation ( programObject, "uFrameAnchor" ) );

    GL_CHECK( glPixelStorei ( GL_UNPACK_ALIGNMENT, 1 ) );
    GL_CHECK( glGenFramebuffers(1, &m_dataStroke.frameBuffer) );
    GL_CHECK( glGenTextures(1,&m_dataStroke.textureBuffer) );
    GL_CHECK( glBindTexture(GL_TEXTURE_2D, m_dataStroke.textureBuffer) );
    //GL_CHECK( glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_size.width/VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO, m_size.height/VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL) );
    
    //the use of read the stroke content back
    GL_CHECK( glBindTexture ( GL_TEXTURE_2D, m_dataStroke.textureBuffer) );
    if(g_mem_buffer != NULL)
    { 
        GL_CHECK( glTexImage2D(GL_TEXTURE_2D, 0, g_readFormat, m_size.width/VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO, m_size.height/VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO, 0, g_readFormat, g_readType, g_mem_buffer) );
        applib_asm_free_anonymous(g_mem_buffer);
        g_mem_buffer = NULL;
    }
    else
    {
    GL_CHECK( glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_size.width/VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO, m_size.height/VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, NULL) );
    }

    GL_CHECK( glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST ) );
    GL_CHECK( glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST ) );
    GL_CHECK( glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE) );
    GL_CHECK( glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE) );

    GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);

    // Store the program object
    if(status == GL_FRAMEBUFFER_COMPLETE)
        m_dataStroke.programObject = programObject;


/******************/
/* Steam Program */
/******************/

#ifdef GL_SHADER_FILE_MODE_TEST
    handle = FS_Open ((const WCHAR *) L"c:\\steam.fs",FS_READ_ONLY);
    FS_GetFileSize(handle,&fs);
    FS_Read (handle, fShaderStr,fs,&fsize);
    fShaderStr[fsize] = '\0';
    FS_Close (handle);

    // file mode
    fragmentShader = VappScreenLockLoadShaderFileMode ( GL_FRAGMENT_SHADER, fShaderStr);
#else
    // Load the vertex/fragment shaders
    fragmentShader = VappScreenLockLoadShader ( GL_FRAGMENT_SHADER, VAPP_STEAM_SCREEN_LOCK_STEAM_FRAGMENT_SHADER);
#endif

    // Create the program object
    programObject = GL_CHECK( glCreateProgram ( ) );

    VFX_DEV_ASSERT(programObject);

    GL_CHECK( glAttachShader ( programObject, vertexShader ) );
    GL_CHECK( glAttachShader ( programObject, fragmentShader ) );

    // Link the program
    GL_CHECK( glLinkProgram ( programObject ) );

    // Check the link status
    GL_CHECK( glGetProgramiv ( programObject, GL_LINK_STATUS, &linked ) );

    if ( !linked )
    {
        GLint infoLen = 0;
        GL_CHECK( glGetProgramiv(programObject, GL_INFO_LOG_LENGTH, &infoLen) );
        if(infoLen > 1)
        {
//        glGetProgramInfoLog(programObject, infoLen, NULL, vShaderStr);
//        kal_printf("Error linking program:\n%s\n", vShaderStr);
        }
        GL_CHECK( glDeleteProgram(programObject) );

        VFX_DEV_ASSERT(0);
    }

    m_dataGlass.uTextureLoc = GL_CHECK( glGetUniformLocation ( programObject, "uTexture" ) );
    m_dataGlass.uTextureStrokeLoc = GL_CHECK( glGetUniformLocation ( programObject, "uTextureStroke" ) );
    m_dataGlass.uViewPortSizeLoc =  GL_CHECK( glGetUniformLocation(programObject, "uViewportSize") );
    m_dataGlass.aPositionLoc = GL_CHECK( glGetAttribLocation (programObject, "aPosition" ) );
    m_dataGlass.aTexCoordLoc = GL_CHECK( glGetAttribLocation (programObject, "aTexCoord" ) );
    m_dataGlass.textureId = CreateTexture2D(IMG_ID_VAPP_STEAM_SCREEN_LOCK_STEAM, GL_RGB, VFX_TRUE);
    m_dataGlass.uFrameAnchorLoc = GL_CHECK( glGetUniformLocation ( programObject, "uFrameAnchor" ) );
    m_dataGlass.programObject = programObject;


/******************/
/* Drop Program */
/******************/

#ifdef GL_SHADER_FILE_MODE_TEST
    handle = FS_Open ((const WCHAR *) L"c:\\droplet.fs",FS_READ_ONLY);
    FS_GetFileSize(handle,&fs);
    FS_Read (handle, fShaderStr,fs,&fsize);
    fShaderStr[fsize] = '\0';
    FS_Close (handle);

    // file mode
    fragmentShader = VappScreenLockLoadShaderFileMode ( GL_FRAGMENT_SHADER, fShaderStr);

#else
    // Load the vertex/fragment shaders
    fragmentShader = VappScreenLockLoadShader ( GL_FRAGMENT_SHADER, VAPP_STEAM_SCREEN_LOCK_DROPLET_FRAGMENT_SHADER);
#endif

    // Create the program object
    programObject = GL_CHECK( glCreateProgram ( ) );

    VFX_DEV_ASSERT(programObject);

    GL_CHECK( glAttachShader ( programObject, vertexShader ) );
    GL_CHECK( glAttachShader ( programObject, fragmentShader ) );

    // Link the program
    GL_CHECK( glLinkProgram ( programObject ) );

    // Check the link status
    GL_CHECK( glGetProgramiv ( programObject, GL_LINK_STATUS, &linked ) );

    if ( !linked )
    {
        GLint infoLen = 0;
        GL_CHECK( glGetProgramiv(programObject, GL_INFO_LOG_LENGTH, &infoLen) );
        if(infoLen > 1)
        {
          //glGetProgramInfoLog(programObject, infoLen, NULL, vShaderStr);
          //kal_printf("Error linking program:\n%s\n", vShaderStr);
        }
        GL_CHECK( glDeleteProgram(programObject) );

        VFX_DEV_ASSERT(0);
    }

    m_dataDroplet.uTextureLoc = GL_CHECK( glGetUniformLocation ( programObject, "uTexture" ) );
    m_dataDroplet.uViewPortSizeLoc =  GL_CHECK( glGetUniformLocation(programObject, "uViewportSize") );
    m_dataDroplet.aPositionLoc = GL_CHECK( glGetAttribLocation (programObject, "aPosition" ) );
    m_dataDroplet.aTexCoordLoc = GL_CHECK( glGetAttribLocation (programObject, "aTexCoord" ) );
    m_dataDroplet.textureId = CreateTexture2D(IMG_ID_VAPP_STEAM_SCREEN_LOCK_WATER_DROP, GL_RGBA);
    m_dataDroplet.uFrameAnchorLoc = GL_CHECK( glGetUniformLocation ( programObject, "uFrameAnchor" ) );
    m_dataDroplet.programObject = programObject;

    //reset();
}

void VappSteamScreenLockOwenerDraw::onDeinitResource()
{
    //MAUI_03075805, after suspend 'video live' wallpaper, the flow goes as onDeinit->init->ondraw,
    //so cause the ownerdraw frame messed.
    //solution: read the back stroke content before init resource again

        // get current frame buffer
        GLint fbo;
        GL_CHECK( glGetIntegerv(GL_FRAMEBUFFER_BINDING, &fbo) );

        // bind stroke frame buffer
        GL_CHECK( glBindFramebuffer(GL_FRAMEBUFFER, m_dataStroke.frameBuffer) );
        GL_CHECK( glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_dataStroke.textureBuffer, 0) );

        glGetIntegerv(GL_IMPLEMENTATION_COLOR_READ_TYPE, &g_readType);
        glGetIntegerv(GL_IMPLEMENTATION_COLOR_READ_FORMAT, &g_readFormat);    
           
        switch(g_readType)
        {
            case GL_UNSIGNED_BYTE:
                switch(g_readFormat)
                {
                    case GL_RGBA:
                        g_bytesPerPixel = 4;
                        break;
                    case GL_RGB:
                        g_bytesPerPixel = 3;
                        break;
                    case GL_LUMINANCE_ALPHA:
                        g_bytesPerPixel = 2;
                        break;            
                    case GL_ALPHA:
                    case GL_LUMINANCE:
                        g_bytesPerPixel = 1;
                        break;                
                }
                 g_gdi_type = GDI_COLOR_FORMAT_32;
                break;
            case GL_UNSIGNED_SHORT_5_6_5:
            case GL_UNSIGNED_SHORT_4_4_4_4:
            case GL_UNSIGNED_SHORT_5_5_5_1:    
                g_bytesPerPixel = 2;
                g_gdi_type = GDI_COLOR_FORMAT_16;
                break;                               
        }

        g_mem_buffer = (PU8)applib_asm_alloc_anonymous_nc(m_size.width / VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO * m_size.height / VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO * g_bytesPerPixel);        

        GL_CHECK( glReadPixels(0, 0, m_size.width / VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO, m_size.height / VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO, g_readFormat, g_readType, g_mem_buffer));
        GL_CHECK( glBindFramebuffer(GL_FRAMEBUFFER, fbo) );

       #if 0 // the use of debug
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
       #endif
    
    glDeleteFramebuffers(1, &m_dataStroke.frameBuffer);
    glDeleteTextures(1, &m_dataStroke.textureBuffer);
    glDeleteTextures(1, &m_dataGlass.textureId);
    glDeleteTextures(1, &m_dataDroplet.textureId);

    if (m_dataStroke.programObject)
    {
        glDeleteProgram(m_dataStroke.programObject);
        m_dataStroke.programObject = 0;
    }
    if (m_dataGlass.programObject)
    {
        glDeleteProgram(m_dataGlass.programObject);
        m_dataGlass.programObject = 0;
    }
    if (m_dataDroplet.programObject)
    {
        glDeleteProgram(m_dataDroplet.programObject);
        m_dataDroplet.programObject = 0;
    }
}


void VappSteamScreenLockOwenerDraw::addWaterDrop(VfxPoint pos, VfxS32 weight)
{
    if(m_dropWaterList.size() >= VAPP_STEAM_SCREEN_LOCK_MAX_WATER_DROP)
    {
        return;
    }
    
    VappSteamScreenLockDroplet droplet;
    droplet.m_pos = pos;
    droplet.m_weight = weight; // weight base = 100, max = 1000
    droplet.m_acceleration = 0;
    VfxFloat tmp = ((VfxFloat)(rand()%1000))/1000;
    if(tmp < 0.3)
    {
        droplet.m_gravityAcceleration = ((VfxFloat)(rand()%1000))/1000*4 + 10.0;
    }
    else
    {
        droplet.m_gravityAcceleration = ((VfxFloat)(rand()%1000))/1000*5 + 4.0;
    }
    VfxFloat ratio = ((VfxFloat)(rand()%1000))/250 + 1.0;
    droplet.m_distanceToWeightRatio = ratio;
    m_dropWaterList.pushBack(droplet);
}


VfxSize VappSteamScreenLockOwenerDraw::getScreenSize()
{
    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;
    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

    return VfxSize(main_screen_size.width, main_screen_size.height);
}


void VappSteamScreenLockOwenerDraw::setGravity(VfxFloat g_x, VfxFloat g_y, VfxFloat g_z)
{
    // Put the target in lying position on the desk,
    // the g_x & g_y might both be zero which sent by motion sensor framework,
    // it might cause overflow since length = sqrt(m_gravity[0]*m_gravity[0] + m_gravity[1]*m_gravity[1])
    // see MAUI_03161112.
    if(g_x ==0.0f && g_y == 0.0f)
    {
        g_y =-1.0f;
    }
    
    m_gravity[0] = g_x;
    m_gravity[1] = g_y;
    m_gravity[2] = g_z;
}


void VappSteamScreenLockOwenerDraw::clearBuffer(
    vrt_color_type color)
{
    GL_CHECK( glClearDepthf(1.0f) );
    GL_CHECK( glClearStencil(0) );
    GL_CHECK( glClearColor(
                VRT_COLOR_GET_R(color) / 255.0f,
                VRT_COLOR_GET_G(color) / 255.0f,
                VRT_COLOR_GET_B(color) / 255.0f,
                VRT_COLOR_GET_A(color) / 255.0f) );
    
    GL_CHECK( glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT) );

#ifdef GL_FLUSH_DRAW_CALL
    GL_CHECK( glFlush() );
#endif
}

void VappSteamScreenLockOwenerDraw::releaseResource()
{
    m_dropWaterList.clear();
    applib_asm_free_anonymous(g_mem_buffer);
    g_mem_buffer = NULL;
}

void VappSteamScreenLockOwenerDraw::reset()
{
    m_isInit = VFX_TRUE;
    m_dropWaterList.clear();
}

void VappSteamScreenLockOwenerDraw::onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect)
{
    //return;
    GLenum error;
    GLfloat vVertices[] = {  0.0f,  0.0f, 0.0f, 
                           0.0f, m_size.height, 0.0f,
                            m_size.width, 0.0f, 0.0f,
                            m_size.width, m_size.height, 0.0f};
    
    GLfloat vVerticesHalf[] = {  0.0f,  0.0f, 0.0f, 
                                 0.0f, m_size.height /VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO, 0.0f,
                                 m_size.width/VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO, 0.0f, 0.0f,
                                 m_size.width/VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO, m_size.height/VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO, 0.0f};

    GLfloat vTexcoord[] = { 0.0f,0.0f,
                            0.0f,1.0f,
                            1.0f,0.0f,
                            1.0f,1.0f};

    GLfloat vVerticesD[3 * 4] ;        
    
    // Set the viewport
    GLint viewportsize[4];
    GLint scissorboxsize[4];
    GLint ORI_GL_SRC_RGB;
    GLint ORI_GL_DST_RGB;
    GLint ORI_GL_SRC_ALPHA;
    GLint ORI_GL_DST_ALPHA;

    GL_CHECK( glGetIntegerv(GL_VIEWPORT, viewportsize) );
    GL_CHECK( glGetIntegerv(GL_SCISSOR_BOX, scissorboxsize) );
    GL_CHECK( glGetIntegerv(GL_BLEND_SRC_RGB, &ORI_GL_SRC_RGB) );
    GL_CHECK( glGetIntegerv(GL_BLEND_DST_RGB, &ORI_GL_DST_RGB) );
    GL_CHECK( glGetIntegerv(GL_BLEND_SRC_ALPHA, &ORI_GL_SRC_ALPHA) );
    GL_CHECK( glGetIntegerv(GL_BLEND_DST_ALPHA, &ORI_GL_DST_ALPHA) );

    GL_CHECK( glViewport ( 0, 0, m_size.width / VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO, m_size.height / VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO) );
    GL_CHECK( glScissor(0,0,m_size.width / VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO, m_size.height / VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO) );

    // get current frame buffer
    GLint fbo;
    GL_CHECK( glGetIntegerv(GL_FRAMEBUFFER_BINDING, &fbo) );

    // bind stroke frame buffer
    GL_CHECK( glBindFramebuffer(GL_FRAMEBUFFER, m_dataStroke.frameBuffer) );
    GL_CHECK( glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_dataStroke.textureBuffer, 0) );

    GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);

    VRT_EXT_ASSERT(status == GL_FRAMEBUFFER_COMPLETE, status, status, status);

    if(m_isInit)
    {
        // Clear the color buffer
        //GL_CHECK( glColorMask(GL_TRUE,GL_TRUE,GL_TRUE,GL_TRUE) ); 
        clearBuffer(VRT_COLOR_MAKE(0.0, 0.0, 0.0, 0.0));
        //GL_CHECK( glClearColor ( 1.0f, 1.0f, 1.0f, 1.0f ) );
        //GL_CHECK( glClear ( GL_COLOR_BUFFER_BIT ) );
        //m_isInit = VFX_FALSE;
    }

    GLboolean result = glIsProgram(m_dataStroke.programObject);
    VRT_EXT_ASSERT( result == GL_TRUE, result, result, result);


    /******************/
    /* Stroke Program */
    /******************/

    // Use the program object
    GL_CHECK( glUseProgram ( m_dataStroke.programObject ) );

    GL_CHECK( glUniform2i(m_dataStroke.uViewPortSizeLoc, m_size.width / VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO, m_size.height / VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO) );
    GL_CHECK( glUniform2i(m_dataStroke.uFrameAnchorLoc, 0, 0) );

    // Bind the texture
    GL_CHECK( glActiveTexture ( GL_TEXTURE0 ) );
    GL_CHECK( glUniform1i ( m_dataStroke.uTextureLoc, 0 ) );// Set the sampler texture unit to 0
    GL_CHECK( glBindTexture ( GL_TEXTURE_2D, m_dataStroke.textureBuffer) );

    GL_CHECK( glActiveTexture ( GL_TEXTURE1 ) );
    GL_CHECK( glUniform1i ( m_dataStroke.uTextureLevelLoc, 1 ) );// Set the sampler texture unit to 0
    GL_CHECK( glBindTexture ( GL_TEXTURE_2D, m_dataStroke.textureLevelId) );        

    GL_CHECK( glUniform1i(m_dataStroke.uBackgroundLoc, 1) );

    
    if (m_fogUpTimes==0 && !m_isInit)
    {
        GL_CHECK( glUniform1i(m_dataStroke.uNeedFogUpLoc, 0) );
    }
    else
    {
        GL_CHECK( glUniform1i(m_dataStroke.uNeedFogUpLoc, 1) );      
    }

    if (m_isInit)
    {
        GL_CHECK( glUniform1f(m_dataStroke.uConstAlphaLoc, 1.0) );
        m_isInit = VFX_FALSE;
    }
    else
    {
        GL_CHECK( glUniform1f(m_dataStroke.uConstAlphaLoc, 0.01) );      
    }

    GL_CHECK( glVertexAttribPointer(m_dataStroke.aPositionLoc, VERTEX_POS_SIZE, GL_FLOAT, GL_FALSE, 0, vVerticesHalf) );
    GL_CHECK( glEnableVertexAttribArray(m_dataStroke.aPositionLoc) );
    GL_CHECK( glVertexAttribPointer(m_dataStroke.aTexCoordLoc, 2, GL_FLOAT, GL_FALSE, 0, vTexcoord) );
    GL_CHECK( glEnableVertexAttribArray(m_dataStroke.aTexCoordLoc) );
    GL_CHECK( glDrawArrays ( GL_TRIANGLE_STRIP, 0, 4 ) );
    GL_CHECK( glDisableVertexAttribArray (m_dataStroke.aPositionLoc) );
    GL_CHECK( glDisableVertexAttribArray (m_dataStroke.aTexCoordLoc) );

    GL_CHECK( glEnable ( GL_BLEND ) );
    //glBlendFunc ( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    GL_CHECK( glBlendFuncSeparate ( GL_ONE, GL_ONE_MINUS_SRC_COLOR, GL_ONE, GL_ONE_MINUS_SRC_ALPHA) );
    GL_CHECK( glActiveTexture ( GL_TEXTURE0 ) );
    GL_CHECK( glUniform1i ( m_dataStroke.uTextureLoc, 0 ) );// Set the sampler texture unit to 0               
    GL_CHECK( glBindTexture ( GL_TEXTURE_2D, m_dataStroke.textureId) );

    GL_CHECK( glUniform1i(m_dataStroke.uBackgroundLoc, 0) );        

    m_stroke.m_radius = VAPP_STEAM_SCREEN_LOCK_STROKE_RADIUS;    
    m_stroke.m_vertexPosIndx = m_dataStroke.aPositionLoc;
    m_stroke.m_vertexTexIndx = m_dataStroke.aTexCoordLoc;
    m_stroke.render();

    VfxFloat baseHalfWidth = VAPP_STEAM_SCREEN_LOCK_WATER_DROP_BASE_HALF_WIDTH , baseHalfHeight = VAPP_STEAM_SCREEN_LOCK_WATER_DROP_BASE_HALF_HEIGHT;
    VfxFloat maxHalfWidth = VAPP_STEAM_SCREEN_LOCK_WATER_DROP_MAX_HALF_WIDTH , maxHalfHeight = VAPP_STEAM_SCREEN_LOCK_WATER_DROP_MAX_HALF_HEIGHT;
    VfxFloat baseweight = 100;
    VfxFloat maxweight = 1000;
    VfxFloat ratio = 1.5;

    VfxList <VappSteamScreenLockDroplet>::It itr;
    for (itr = m_dropWaterList.begin(); !itr.isNull(); ++itr)
    {
        VappSteamScreenLockDroplet droplet = *itr;
        VfxFloat weight = VFX_MIN(droplet.m_weight, maxweight - 1);
        if (weight>0)
        {
            VfxFloat f = (weight - baseweight) / (weight - maxweight);
            m_stroke.m_radius = 0.7*((baseHalfWidth - maxHalfWidth * f) / (1 - f)) / VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO;
            m_stroke.add(droplet.m_pos.x / VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO, droplet.m_pos.y / VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO, droplet.m_pos.x / VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO +0.01, droplet.m_pos.y / VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO +0.01);                
            m_stroke.render();
        }
    }
        
    GL_CHECK( glDisable(GL_BLEND) );

    // bind origin frame buffer
    GL_CHECK( glBindFramebuffer(GL_FRAMEBUFFER, fbo) );
    GL_CHECK( glScissor(scissorboxsize[0],scissorboxsize[1],scissorboxsize[2], scissorboxsize[3]) );
    GL_CHECK( glViewport (dstRect.origin.x, dstBuffer.height - (dstRect.origin.y + dstRect.size.height),
                dstRect.size.width, dstRect.size.height ) );
        
    /******************/
    /* Steam Program */
    /******************/

    GL_CHECK( glUseProgram ( m_dataGlass.programObject ) );
    GL_CHECK( glEnable ( GL_BLEND ) );
    GL_CHECK( glBlendFuncSeparate( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE_MINUS_SRC_ALPHA) );

    GL_CHECK( glUniform2i(m_dataGlass.uViewPortSizeLoc, dstRect.size.width, dstRect.size.height) );
    GL_CHECK( glUniform2i(m_dataGlass.uFrameAnchorLoc, srcRect.origin.x  , m_size.height - (srcRect.origin.y + srcRect.size.height)) );

    // Bind the texture
    GL_CHECK( glActiveTexture ( GL_TEXTURE0 ) );
    GL_CHECK( glUniform1i ( m_dataGlass.uTextureLoc, 0 ) );// Set the sampler texture unit to 0
    GL_CHECK( glBindTexture ( GL_TEXTURE_2D, m_dataGlass.textureId) );

    // Bind the texture
    GL_CHECK( glActiveTexture ( GL_TEXTURE1 ) );
    GL_CHECK( glUniform1i ( m_dataGlass.uTextureStrokeLoc, 1 ) );// Set the sampler texture unit to 1
    GL_CHECK( glBindTexture ( GL_TEXTURE_2D, m_dataStroke.textureBuffer) );

    GL_CHECK( glVertexAttribPointer(m_dataGlass.aPositionLoc, VERTEX_POS_SIZE, GL_FLOAT, GL_FALSE, 0, vVertices) );
    GL_CHECK( glEnableVertexAttribArray(m_dataGlass.aPositionLoc) );

    GL_CHECK( glVertexAttribPointer(m_dataGlass.aTexCoordLoc, 2, GL_FLOAT, GL_FALSE, 0, vTexcoord) );
    GL_CHECK( glEnableVertexAttribArray(m_dataGlass.aTexCoordLoc) );

    GL_CHECK( glDrawArrays ( GL_TRIANGLE_STRIP, 0, 4 ) );

    GL_CHECK( glDisableVertexAttribArray (m_dataGlass.aPositionLoc) );
    GL_CHECK( glDisableVertexAttribArray (m_dataGlass.aTexCoordLoc) );

    GL_CHECK( glDisable(GL_BLEND) );


    /******************/
    /* Drop Program */
    /******************/

    GL_CHECK( glUseProgram ( m_dataDroplet.programObject ) );
    GL_CHECK( glEnable ( GL_BLEND ) );
    GL_CHECK( glBlendFuncSeparate ( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE_MINUS_SRC_ALPHA) );
    GL_CHECK( glUniform2i(m_dataDroplet.uViewPortSizeLoc, dstRect.size.width, dstRect.size.height) );
    glUniform2i(m_dataDroplet.uFrameAnchorLoc, srcRect.origin.x  , m_size.height - (srcRect.origin.y + srcRect.size.height));

    // Bind the texture
    GL_CHECK( glActiveTexture ( GL_TEXTURE0 ) );
    GL_CHECK( glUniform1i ( m_dataDroplet.uTextureLoc, 0 ) );// Set the sampler texture unit to 0
    GL_CHECK( glBindTexture ( GL_TEXTURE_2D, m_dataDroplet.textureId) );

    GL_CHECK( glVertexAttribPointer(m_dataDroplet.aTexCoordLoc, 2, GL_FLOAT, GL_FALSE, 0, vTexcoord) );
    GL_CHECK( glEnableVertexAttribArray(m_dataDroplet.aTexCoordLoc) );
    
    VfxFloat length = sqrt(m_gravity[0]*m_gravity[0] + m_gravity[1]*m_gravity[1]+ m_gravity[2]*m_gravity[2]);
    
    m_gravity[0] /= length;
    m_gravity[1] /= length;
    m_gravity[2] /= length;

    m_redrawWaterDrop = VFX_FALSE;
 
    itr = m_dropWaterList.begin();
    while(!itr.isNull())
    { 
        VfxList <VappSteamScreenLockDroplet>::It droplet = itr++;
        VfxFloat weight = VFX_MIN(droplet->m_weight, maxweight - 1);

        if (weight>0)
        {
            VfxFPoint pos = droplet->m_pos;         
            VfxFloat acceleration = droplet->m_acceleration;
                      
            VfxFloat f = (weight - baseweight) / (weight - maxweight);
            VfxFloat halfWidth = (baseHalfWidth - maxHalfWidth * f) / (1 - f);
            VfxFloat halfHeight = (baseHalfHeight - maxHalfHeight * f) / (1 - f);

            VfxFloat S = 0.5 * acceleration; //t = 1
           
            VfxFloat shift = (VfxFloat)(rand()%5 - 2)/2;
            droplet->m_pos = VfxFPoint(pos.x + S*m_gravity[0] + shift* m_gravity[1], pos.y + S*m_gravity[1] + shift* m_gravity[0]);                

            VfxFloat length = sqrt(m_gravity[0]*m_gravity[0] + m_gravity[1]*m_gravity[1]);
            VfxFPoint norm = VfxFPoint( m_gravity[0] / length, m_gravity[1] / length);

            vVerticesD[0] = droplet->m_pos.x + norm.x * halfHeight + norm.y * halfWidth;
            vVerticesD[1] = droplet->m_pos.y + norm.y * halfHeight - norm.x * halfWidth;          
            vVerticesD[2] = 0;
            vVerticesD[3] = droplet->m_pos.x -norm.x * halfHeight + norm.y * halfWidth;
            vVerticesD[4] = droplet->m_pos.y -norm.y * halfHeight - norm.x * halfWidth;
            vVerticesD[5] = 0;
            vVerticesD[6] = droplet->m_pos.x + norm.x * halfHeight - norm.y * halfWidth;
            vVerticesD[7] = droplet->m_pos.y + norm.y * halfHeight + norm.x * halfWidth;
            vVerticesD[8] = 0;
            vVerticesD[9] = droplet->m_pos.x -norm.x * halfHeight - norm.y * halfWidth;
            vVerticesD[10] = droplet->m_pos.y -norm.y * halfHeight + norm.x * halfWidth;
            vVerticesD[11] = 0;
    
            glVertexAttribPointer(m_dataDroplet.aPositionLoc, VERTEX_POS_SIZE, GL_FLOAT, GL_FALSE, 0, vVerticesD);
            glEnableVertexAttribArray(m_dataDroplet.aPositionLoc);
            glDrawArrays ( GL_TRIANGLE_STRIP, 0, 4 );           

            //droplet->m_weight =  droplet->m_weight + S*ratio;
            droplet->m_weight =  droplet->m_weight + S*droplet->m_distanceToWeightRatio;
                
            //VfxFloat downForce = m_acceleration * droplet->m_weight * (m_gravity[0]*m_gravity[0] + m_gravity[1]*m_gravity[1]);
            VfxFloat downForce = droplet->m_gravityAcceleration * droplet->m_weight * (m_gravity[0]*m_gravity[0] + m_gravity[1]*m_gravity[1]);
            VfxFloat upForce = m_frictionFactor * ( droplet->m_weight * m_gravity[2]*m_gravity[2] + m_defaultNormalForce);
            VfxFloat F = downForce - upForce;
            droplet->m_acceleration = F / droplet->m_weight;

            
            if (((vVerticesD[0] >= 0 && vVerticesD[0] <= m_size.width) && (vVerticesD[1] >= 0 && vVerticesD[1] <= m_size.height)) ||
                ((vVerticesD[3] >= 0 && vVerticesD[3] <= m_size.width) && (vVerticesD[4] >= 0 && vVerticesD[4] <= m_size.height)) || 
                ((vVerticesD[6] >= 0 && vVerticesD[6] >= m_size.width) && (vVerticesD[7] >= 0 && vVerticesD[7] <= m_size.height)) ||
                ((vVerticesD[9] >= 0 && vVerticesD[9] <= m_size.width) && (vVerticesD[10] >= 0 && vVerticesD[10] <= m_size.height)))
            {
                m_redrawWaterDrop =VFX_TRUE;
            }
            else
            {
                m_dropWaterList.erase(droplet);

            }            
        }
    }

    m_fogUpTimes-=1;
    if(m_fogUpTimes <=0)
    {
        m_fogUpTimes = 0;
    }
             
    GL_CHECK( glDisable(GL_BLEND) );
    GL_CHECK( glDisableVertexAttribArray (m_dataDroplet.aPositionLoc) );
    GL_CHECK( glDisableVertexAttribArray (m_dataDroplet.aTexCoordLoc) );         
    GL_CHECK( glBlendFuncSeparate ( ORI_GL_SRC_RGB, ORI_GL_DST_RGB, ORI_GL_SRC_ALPHA, ORI_GL_DST_ALPHA) );
    GL_CHECK( glViewport( viewportsize[0], viewportsize[1], viewportsize[2], viewportsize[3]) );
}


void VappSteamScreenLockOwenerDraw::addStrokeLine(VfxFloat x0, VfxFloat y0, VfxFloat x1, VfxFloat y1)
{
    x0 = x0 / VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO;
    x1 = x1 / VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO;
    y0 = y0 / VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO;
    y1 = y1 / VAPP_STEAM_SCREEN_LOCK_STROKE_BUFFER_RESIZE_RATIO;

    m_stroke.add(x0, y0, x1, y1); 
}

#endif /* __COSMOS_3D_SCREEN_LOCK__*/
