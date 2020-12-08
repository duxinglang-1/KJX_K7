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
 *  vapp_wallpaper_wave.cpp
 *
 * Project:
 * --------
 *  Venus
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
 * removed!
 *
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
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_WAVE__

#include "vapp_wallpaper_3d_wave.h"
#include "mmi_rp_app_venus_wallpaper_3d_wave_def.h"
#include "vfx_timer.h"
#include "vfx_animation.h"

extern "C"
{
#include "gdi_include.h"
#include "gdi_primitive.h" // for gdi_bits_per_pixel
#include "app_mem_med.h" // for applib_asm_free_anonymous
#include "CustDataRes.h" // for GetImage
#include "stdlib.h" // for rand
#include "mmi_frm_mem_gprot.h" // for mmi_frm_asm_alloc_anonymous
}

#ifdef __MTK_TARGET__
#pragma arm
#endif

// constants
static const VfxS32 VAPP_WALLPAPER_3D_WAVE_DROP_MARGIN = 5;
static const VfxS32 VAPP_WALLPAPER_3D_WAVE_START_DELAY = 4000;
static const VfxS32 VAPP_WALLPAPER_3D_WAVE_DURATION = 15000;
static const VfxS32 VAPP_WALLPAPER_3D_WAVE_BUFFER_RATIO = 4;

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
 * help functions
 *****************************************************************************/

///
// Create a shader object, load the shader source, and
// compile the shader.
//
static GLuint waveLoadShader (bool isBinary, GLenum type, const char *shaderSrc, GLsizei size)
{
    GLuint shader;
    GLint compiled;

    // Create the shader object
    shader = glCreateShader ( type );

    if ( shader == 0 )
    {
        VFX_DEV_ASSERT(0);
        return 0;
    }

    if (isBinary)
    {
        GLenum glError;
        GLenum MALI_SHADER_BINARY_ARM = 0x8F60;
        glShaderBinary (1, &shader, MALI_SHADER_BINARY_ARM, (const void* )shaderSrc, size);
        glError = glGetError();
        VRT_DEV_ASSERT(glError == GL_NO_ERROR);
    }
    else
    {
        // Load the shader source
        glShaderSource ( shader, 1, &shaderSrc, NULL );

        // Compile the shader
        glCompileShader ( shader );

        // Check the compile status
        glGetShaderiv ( shader, GL_COMPILE_STATUS, &compiled );

        if ( !compiled ) 
        {
            GLint infoLen = 0;

            glGetShaderiv ( shader, GL_INFO_LOG_LENGTH, &infoLen );

            if ( infoLen > 1 )
            {
                char s_infoLog[1024];
                glGetShaderInfoLog ( shader, infoLen, NULL, s_infoLog );

                VRT_TRACE( (shaderSrc) );
                VRT_TRACE( (s_infoLog) );

                VRT_DEV_ASSERT(0);
            }

           
            glDeleteShader ( shader );
            VFX_DEV_ASSERT(0);
            return 0;
        }
    }

    return shader;

}

static GLuint CreateTexture2D(const WCHAR* str, GLenum type)
{
   // Texture object handle
   GLuint textureId;
   
   S32 imgWidth, imgHeight;
   GDI_RESULT res = GDI_FAILED;
   GDI_HANDLE imgLayer = GDI_LAYER_EMPTY_HANDLE;

   gdi_image_get_dimension_file((CHAR*)str, &imgWidth, &imgHeight);

   PU8 mem_buffer = (PU8)applib_asm_alloc_anonymous_nc(imgWidth * imgHeight * gdi_bits_per_pixel(GDI_COLOR_FORMAT_32) / 8);
     
   res = gdi_layer_create_cf_using_outside_memory(GDI_COLOR_FORMAT_32, 
                                                      0, 0, 
                                                      imgWidth, 
                                                      imgHeight, 
                                                      &imgLayer,
                                                      (PU8)mem_buffer, 
                                                      imgWidth * imgHeight * gdi_bits_per_pixel(GDI_COLOR_FORMAT_32) / 8);
   gdi_layer_push_and_set_active(imgLayer);
   gdi_image_draw_file(0, 0, (U8*)str);
   gdi_layer_pop_and_restore_active();
   gdi_layer_free(imgLayer);

   GLenum error;

   // Use tightly packed data
   glPixelStorei ( GL_UNPACK_ALIGNMENT, 1 );

   // Generate a texture object
   glGenTextures ( 1, &textureId );

   // Bind the texture object
   glBindTexture ( GL_TEXTURE_2D, textureId );

   // Load the texture
   glTexImage2D ( GL_TEXTURE_2D, 0, type, imgWidth, imgHeight, 0, type, GL_UNSIGNED_BYTE, mem_buffer );

   // Set the filtering mode
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

   error = glGetError();

   applib_asm_free_anonymous(mem_buffer);
    

   return textureId;
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

static GLuint CreateTexture2D_Res(const U16 resId, GLenum type, VfxBool isKTX = VFX_FALSE)
{
   // Texture object handle
   GLuint textureId;

   GLenum error;

   // Use tightly packed data
   glPixelStorei ( GL_UNPACK_ALIGNMENT, 1 );

   // Generate a texture object
   glGenTextures ( 1, &textureId );

   // Bind the texture object
   glBindTexture ( GL_TEXTURE_2D, textureId );


   S32 imgWidth, imgHeight;
   PU8 mem_buffer;


   if (!isKTX)
   {
    
       gdi_image_get_dimension_id(resId, &imgWidth, &imgHeight);

       GDI_RESULT res = GDI_FAILED;
       GDI_HANDLE imgLayer = GDI_LAYER_EMPTY_HANDLE;

       mem_buffer = (PU8)applib_asm_alloc_anonymous_nc(imgWidth * imgHeight * gdi_bits_per_pixel(GDI_COLOR_FORMAT_32) / 8);

       res = gdi_layer_create_cf_using_outside_memory(GDI_COLOR_FORMAT_32,
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

        glCompressedTexImage2D ( GL_TEXTURE_2D, 0, header.glInternalFormat, header.pixelWidth, header.pixelHeight, 0, faceLodSize , data_ptr); 
   }
   

 

   // Set the filtering mode
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
   glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

   error = glGetError();

       


   return textureId;

}

// VappWave3DDraw calculation functions

#define GET_POINT(array, x, y) array[(y)*width+(x)]

static inline void processWavePoint(HeightType * pData1, HeightType * pData2, VfxS32 width, VfxS32 height, VfxS32 x, VfxS32 y)
{
    VfxS32 left = vfxMax(0, x - 1);
    VfxS32 right = vfxMin(width- 1, x + 1);
    VfxS32 up = vfxMin(height - 1, y + 1);
    VfxS32 down = vfxMax(0, y - 1);
    HeightType valueCurrent = GET_POINT(pData2, x, y);
    HeightType valueLeft = GET_POINT(pData2, left, y);
    HeightType valueRight = GET_POINT(pData2, right, y);
    HeightType valueUp = GET_POINT(pData2, x, up);
    HeightType valueDown = GET_POINT(pData2, x, down);
    HeightType valuePrev = GET_POINT(pData1, x, y);
    HeightType result = (valueLeft + valueRight + valueUp + valueDown) / 2 - valuePrev;

    result = result - result / 64;
    pData1[y * width + x] = result;
}

static void processWaveImp(HeightType * pData1, HeightType * pData2, const VfxS32 width, const VfxS32 height)
{
    VfxS32 x, y;
    // water propogation
    for (x = 0; x < width; ++x)
    {
        processWavePoint(pData1, pData2, width, height, x, 0);
    }
    for (x = 0; x < width; ++x)
    {
        processWavePoint(pData1, pData2, width, height, x, height - 1);
    }
    for (y = 1; y < height - 1; ++y)
    {
        processWavePoint(pData1, pData2, width, height, 0, y);
    }
    for (y = 1; y < height - 1; ++y)
    {
        processWavePoint(pData1, pData2, width, height, width - 1, y);
    }

    for (y = 1; y < height - 1; ++y)
    {
        HeightType * pValueCurrent = pData2 + y * width + 1;
        HeightType * pValueTarget = pData1 + y * width + 1;
        HeightType * const pValueEnd = pData2 + y * width + width - 1;
        while (pValueCurrent != pValueEnd)
        {
            HeightType result = (*(pValueCurrent - 1) + *(pValueCurrent + 1) + *(pValueCurrent - width) + *(pValueCurrent + width)) / 2 - *pValueTarget;
            result = result - result / 64;
            *pValueTarget = result;
            ++pValueCurrent;
            ++pValueTarget;
        }
    }

    //HeightType laplacian = (valueLeft + valueRight + valueUp + valueDown - 4 * valueCurrent);
    //HeightType c = 0.5f;
    //HeightType result = laplacian * c + 2.0f * valueCurrent - valuePrev;
    //HeightType result = laplacian / 2 + 2 * valueCurrent - valuePrev;
}

static void processTextureImp(HeightType * pData1, VfxS32 width, VfxS32 height, DiffMapType * buffer)
{
    VfxS32 x, y;
#ifdef VAPP_WALLPAPER_WAVE_3D_USE_16BIT_HEIGHT_MAP
    const HeightType descale = 64;
#else
    const HeightType descale = 16384;
#endif
    for (x = 0; x < width; ++x) // y == height - 1
    {
        VfxS32 left = vfxMax(0, x - 1);
        HeightType valueCurrent = GET_POINT(pData1, x, height - 1);
        HeightType valueLeft = GET_POINT(pData1, left, height - 1);
        HeightType xDiff = valueCurrent - valueLeft;
        DiffMapType r = xDiff / descale + 128;
        buffer[(height - 1) * width + x] = r + 128 * 256;
    }
    for (y = 0; y < height - 1; ++y) // x = 0
    {
        VfxS32 up = y + 1;
        HeightType valueCurrent = GET_POINT(pData1, 0, y);
        HeightType valueUp = GET_POINT(pData1, 0, up);
        HeightType yDiff = valueCurrent - valueUp;
        DiffMapType g = yDiff / descale + 128;
        buffer[y * width] = 128 + g * 256;
    }
    for (y = 0; y < height - 1; ++y)
    {
        HeightType * pValueCurrent = pData1 + y * width + 1;
        HeightType * const pValueEnd = pData1 + y * width + width;
        DiffMapType *pBuffer = buffer + y * width + 1;

        while (pValueCurrent != pValueEnd)
        {
            HeightType xDiff = *pValueCurrent - *(pValueCurrent - 1);
            HeightType yDiff = *pValueCurrent - *(pValueCurrent + width);
            DiffMapType r = xDiff / descale + 128;
            DiffMapType g = yDiff / descale + 128;
            *pBuffer = r + g * 256;
            ++pValueCurrent;
            ++pBuffer;
        }
    }
}
#define pi 3.141592653589793238462643383279f


static void processWaterSource(HeightType * pData, VfxS32 width, float currentIncremental, const VappWave3DClick &clickData)
{
    const float increDiff = currentIncremental - clickData.clickIncrement;
    if (increDiff < 0.5)
    {
        const VfxS32 x = clickData.xClick;
        const VfxS32 y = clickData.yClick;
        const VfxS32 xPrev = clickData.xPrevious;
        const VfxS32 yPrev = clickData.yPrevious;
        const VfxS32 xDiff = x - xPrev;
        const VfxS32 yDiff = y - yPrev;
        const VfxS32 distanceSquare = (xDiff * xDiff + yDiff * yDiff);
        bool isOnePoint = (clickData.clickType == VAPP_WAVE_3D_CLICK_ONE_POINT);
        const float scaleModifier = (isOnePoint? 1.0f : 1.0f);
        const float freqModifier = (isOnePoint? 30.0f : 1.0f);
#ifdef VAPP_WALLPAPER_WAVE_3D_USE_16BIT_HEIGHT_MAP
        const float scale = 4.0f * 256 * scaleModifier;
        const float frequency = 2 * 2.0f * pi;
#else
        const float scale = 0.05f * 256 * 256 * 256 * scaleModifier;
        const float frequency = 2.0f * pi;
#endif
        const float valuefDiff = scale * cosf(increDiff * frequency) * expf(-2.0f * increDiff * increDiff / freqModifier / freqModifier);
        const HeightType valueDiff = HeightType(valuefDiff);

        // loop assign values
        if (xDiff == 0 && yDiff == 0)
        {
            HeightType * pDataCurrent = pData + y * width + x;
            *(pDataCurrent) += valueDiff;
            *(pDataCurrent - 1) += valueDiff / 4;
            *(pDataCurrent + 1) += valueDiff / 4;
            *(pDataCurrent - width) += valueDiff / 4;
            *(pDataCurrent + width) += valueDiff / 4;
        }
        else if (vfxAbs(xDiff) > vfxAbs(yDiff) )
        {
            for (VfxS32 ix = xPrev; ix != x + xDiff / vfxAbs(xDiff); ix += xDiff / vfxAbs(xDiff) )
            {
                VfxS32 iy = yPrev + (ix - xPrev) * yDiff / xDiff;
                HeightType * pDataCurrent = pData + iy * width + ix;
                *(pDataCurrent) += valueDiff;
                *(pDataCurrent - width) += valueDiff / 2;
                *(pDataCurrent + width) += valueDiff / 2;
            }
        }
        else
        {
            for (VfxS32 iy = yPrev; iy != y + yDiff / vfxAbs(yDiff); iy += yDiff / vfxAbs(yDiff) )
            {
                VfxS32 ix = xPrev + (iy - yPrev) * xDiff / yDiff;
                HeightType * pDataCurrent = pData + iy * width + ix;
                *(pDataCurrent) += valueDiff;
                *(pDataCurrent - 1) += valueDiff / 2;
                *(pDataCurrent + 1) += valueDiff / 2;
            }
        }
    }
}

void VappWave3DDraw::processWave()
{
    processWaveImp(m_pData1, m_pData2, m_width, m_height);
    // water source
    for (VfxU32 i = 0; i < CLICK_DATA_COUNT; ++i)
    {
        processWaterSource(m_pData1, m_width, m_incremental, clickData[i]);
    }
    processWaterSource(m_pData1, m_width, m_incremental, m_drop);

    m_incremental += 0.03f;

    {
        HeightType * temp = m_pData1;
        m_pData1 = m_pData2;
        m_pData2 = temp;
    }
}

void VappWave3DDraw::processTexture()
{
    processTextureImp(m_pData1, m_width, m_height, m_buffer);
}

void VappWave3DDraw::clickStart(VfxS32 x, VfxS32 y)
{
    VappWave3DClick click = getBaseClick(x, y, VAPP_WAVE_3D_CLICK_START);
    addClick(click);
}

void VappWave3DDraw::click(VfxS32 x, VfxS32 y)
{
    VappWave3DClick click = getBaseClick(x, y, VAPP_WAVE_3D_CLICK_SWIPE);
    const VfxU32 prevIndex = (m_clickIndex + CLICK_DATA_COUNT - 1) % CLICK_DATA_COUNT;
    click.xPrevious = clickData[prevIndex].xClick;
    click.yPrevious = clickData[prevIndex].yClick;
    addClick(click);
}

void VappWave3DDraw::clickOnePoint(VfxS32 x, VfxS32 y)
{
    VappWave3DClick click = getBaseClick(x, y, VAPP_WAVE_3D_CLICK_ONE_POINT);
    VfxPoint bounded = boundedClickPoint(x - VAPP_WALLPAPER_3D_WAVE_DROP_MARGIN,
            y - VAPP_WALLPAPER_3D_WAVE_DROP_MARGIN);
    click.xPrevious = bounded.x;
    click.yPrevious = bounded.y;
    m_drop = click;
}

VfxPoint VappWave3DDraw::boundedClickPoint(VfxS32 x, VfxS32 y)
{
    x = vfxMax(1, x);
    x = vfxMin(m_width -2, x);
    y = vfxMax(1, y);
    y = vfxMin(m_height -2, y);
    return VfxPoint(x, y);
}

void VappWave3DDraw::addClick(VappWave3DClick click)
{
    clickData[m_clickIndex] = click;
    m_clickIndex += 1;
    m_clickIndex = m_clickIndex % CLICK_DATA_COUNT;
}

VappWave3DClick VappWave3DDraw::getBaseClick(VfxS32 x, VfxS32 y, VappWave3DClickType clickType)
{
    VappWave3DClick click;
    VfxPoint bounded = boundedClickPoint(x, y);
    click.xClick = bounded.x;
    click.yClick = bounded.y;
    click.xPrevious = bounded.x;
    click.yPrevious = bounded.y;
    click.clickIncrement = m_incremental;
    click.clickType = clickType;
    return click;
}

VfxS32 VappWave3DDraw::getWidth()
{
    return m_width;
}

VfxS32 VappWave3DDraw::getHeight()
{
    return m_height;
}

/*****************************************************************************
 * Class VappWave3DDraw
 *****************************************************************************/
VappWave3DDraw::VappWave3DDraw(VfxS32 width, VfxS32 height):
    m_width(width),
    m_height(height),
    m_buffer(NULL),
    m_pData1(NULL),
    m_pData2(NULL),
    m_bgTexId(0),
    m_texId(0),
    m_vertexShader(0),
    m_fragmentShader(0),
    m_programObject(0),
    m_positionLoc(0),
    m_texCoordLoc(0),
    m_samplerLoc(0),
    m_baseTexLoc(0),
    m_clickIndex(0),
#ifdef __VAPP_WALLPAPER_3D_WAVE_MOTION_SENSOR_SUPPORT__
    m_xGravity(0.0f),
    m_yGravity(0.0f),
    m_xGravityDiff(0.0f),
    m_yGravityDiff(0.0f),
#endif // __VAPP_WALLPAPER_3D_WAVE_MOTION_SENSOR_SUPPORT__
    m_incremental(0.0f)
{
    for (VfxS32 i = 0; i < VAPP_WALLPAPER_3D_WAVE_LEAVES_COUNT; ++i)
    {
        m_leaves[i] = NULL;
        m_leaveXPos[i] = static_cast<VfxFloat>(rand() % (width * VAPP_WALLPAPER_3D_WAVE_BUFFER_RATIO) );
        m_leaveYPos[i] = static_cast<VfxFloat>(rand() % (height * VAPP_WALLPAPER_3D_WAVE_BUFFER_RATIO) );
        m_leaveXVelocity[i] = 0;
        m_leaveYVelocity[i] = 0;
        m_rotation[i] = 0;
        m_rotationV[i] = 0;
    }
}

//#define VAPP_WALLPAPER_WAVE_3D_USE_STATIC_MEM

#ifdef VAPP_WALLPAPER_WAVE_3D_USE_STATIC_MEM
static DiffMapType g_pBuffer[120*200*VAPP_WALLPAPER_3D_WAVE_BUFFER_RATIO];
static HeightType g_pData1[120*200*VAPP_WALLPAPER_3D_WAVE_BUFFER_RATIO];
static HeightType g_pData2[120*200*VAPP_WALLPAPER_3D_WAVE_BUFFER_RATIO];
#endif
    
void VappWave3DDraw::onInit()
{
    VfxFrame * parentFrame = (VfxFrame*)getParent();

    for (VfxS32 i = 0; i < VAPP_WALLPAPER_3D_WAVE_LEAVES_COUNT; ++i)
    {
        VFX_OBJ_CREATE(m_leaves[i], VfxFrame, this);
        parentFrame->addChildFrame(m_leaves[i]);
        m_leaves[i]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
        m_leaves[i]->setPos(0, 0);
        m_leaves[i]->setAnchor(0.5f, 0.5f);
        m_leaves[i]->setBorderColor(i);

        VappWave3DDraw * self = this;
        m_leaves[i]->setPropertyEffectCallback(
            parentFrame,
            VappWave3DDraw::framePropertyEffectCallback,
            &self,
            sizeof(VappWave3DDraw*) );
    }
    m_leaves[0]->setImgContent(VfxImageSrc(IMG_ID_VAPP_WALLPAPER_3D_WAVE_LEAVE_1));
    m_leaves[1]->setImgContent(VfxImageSrc(IMG_ID_VAPP_WALLPAPER_3D_WAVE_LEAVE_2));
    m_leaves[2]->setImgContent(VfxImageSrc(IMG_ID_VAPP_WALLPAPER_3D_WAVE_LEAVE_3));
    m_leaves[3]->setImgContent(VfxImageSrc(IMG_ID_VAPP_WALLPAPER_3D_WAVE_LEAVE_4));
    for (VfxS32 i = 0; i < VAPP_WALLPAPER_3D_WAVE_LEAVES_COUNT; ++i)
    {
        const VfxImageSrc &src = m_leaves[i]->getImgContent();
        m_leaves[i]->setSize(src.getSize() );
    }
}

static void vappWave3DGetDiff(HeightType * pData, VfxS32 xPos, VfxS32 yPos,
        VfxS32 width, VfxS32 height, VfxFloat & xDiff, VfxFloat &yDiff)
{
    if (xPos < 1 || xPos >= width || yPos < 1 || yPos >= height)
    {
        xDiff = 0.0f;
        yDiff = 0.0f;
        return;
    }
    static VfxFloat descale = 16384.0f / 16.0f;
    HeightType valueCurrent = GET_POINT(pData, xPos, yPos);
    HeightType valueLeft = GET_POINT(pData, xPos - 1, yPos);
    HeightType valueUp = GET_POINT(pData, xPos, yPos - 1);
    VfxFloat xDiffTemp = (VfxFloat)valueCurrent - valueLeft;
    VfxFloat yDiffTemp = (VfxFloat)valueCurrent - valueUp;
    xDiff = xDiffTemp / descale;
    yDiff = yDiffTemp / descale;
}

inline static VfxFloat vapp_wave_3d_draw_random()
{
//#ifdef __MTK_TARGET__
#if 0
/* under construction !*/
#else
    // vc rand() is biased
    return 0.0f;
#endif
}
void VappWave3DDraw::leaveMotions()
{
    // leaf position hard limit -- wallpaper size
    const VfxFloat xLimit = static_cast<VfxFloat>(m_width * VAPP_WALLPAPER_3D_WAVE_BUFFER_RATIO);
    const VfxFloat yLimit = static_cast<VfxFloat>(m_height * VAPP_WALLPAPER_3D_WAVE_BUFFER_RATIO);

    for (VfxS32 i = 0; i < VAPP_WALLPAPER_3D_WAVE_LEAVES_COUNT; ++i)
    {
        VfxFloat xDiff, yDiff; // the difference of the height map on the leaf position

        // leaf position
        const VfxS32 x = static_cast<VfxS32>(m_leaveXPos[i]);
        const VfxS32 y = static_cast<VfxS32>(m_leaveYPos[i]);

        vappWave3DGetDiff(m_pData1, x / VAPP_WALLPAPER_3D_WAVE_BUFFER_RATIO,
                y / VAPP_WALLPAPER_3D_WAVE_BUFFER_RATIO, m_width, m_height, xDiff, yDiff);

        // the original velocity
        const VfxFloat orgXVelocity = m_leaveXVelocity[i];
        const VfxFloat orgYVelocity = m_leaveYVelocity[i];

        // wave curve would affect leaf velocity
        m_leaveXVelocity[i] += 10 * xDiff;
        m_leaveYVelocity[i] += 10 * yDiff;

#ifdef __VAPP_WALLPAPER_3D_WAVE_MOTION_SENSOR_SUPPORT__
        const VfxFloat gravityDiffThreshold = 0.1; // threshold so that small gravity diff would not apply
        const VfxFloat gravityScale = 1.0f;

        // gravity diff decay
        const VfxFloat gravityDiffDecayRate = 1.0f / 128.0f;
        m_xGravityDiff -= m_xGravityDiff * gravityDiffDecayRate;
        m_yGravityDiff -= m_yGravityDiff * gravityDiffDecayRate;
        
        // ratios for calculate gravity intensity
        if (m_xGravityDiff > gravityDiffThreshold)
        {
            m_leaveXVelocity[i] += m_xGravityDiff * gravityScale;
        }
        else if (m_xGravityDiff < -gravityDiffThreshold)
        {
            m_leaveXVelocity[i] += m_xGravityDiff * gravityScale;
        }

        if (m_yGravityDiff > gravityDiffThreshold)
        {
            m_leaveYVelocity[i] -= m_yGravityDiff * gravityScale;
        }
        else if (m_yGravityDiff < -gravityDiffThreshold)
        {
            m_leaveYVelocity[i] -= m_yGravityDiff * gravityScale;
        }
#endif // __VAPP_WALLPAPER_3D_WAVE_MOTION_SENSOR_SUPPORT__

        // random velocity change
        const VfxFloat velocityRandomScale = 0.1f;
        m_leaveXVelocity[i] += vapp_wave_3d_draw_random() * velocityRandomScale;
        m_leaveYVelocity[i] += vapp_wave_3d_draw_random() * velocityRandomScale;


        // limit speed
        const VfxFloat speedLimit = 4.0f;
        m_leaveXVelocity[i] = vfxMin(m_leaveXVelocity[i], speedLimit);
        m_leaveXVelocity[i] = vfxMax(m_leaveXVelocity[i], -speedLimit);
        m_leaveYVelocity[i] = vfxMin(m_leaveYVelocity[i], speedLimit);
        m_leaveYVelocity[i] = vfxMax(m_leaveYVelocity[i], -speedLimit);

        // the velocity would delay
        const VfxFloat decayRate = 1.0f / 64.0f;
        m_leaveXVelocity[i] -= m_leaveXVelocity[i] * decayRate;
        m_leaveYVelocity[i] -= m_leaveYVelocity[i] * decayRate;

        // leaf position boundaries
        const VfxFloat safeMargin = xLimit * 0.05f;
        const VfxFloat safeMarginUp = xLimit * 0.1f; // speical handling for the status bar
        const VfxFloat safeMarginDown = xLimit * 0.25f; // special handling for the home menu bar

        // if hit the boundary, stop the leaf
        if ( (m_leaveXPos[i] > xLimit - safeMargin) && (m_leaveXVelocity[i] > 0.0f) )
        {
            m_leaveXVelocity[i] = 0.0f;
        }
        if ( (m_leaveXPos[i] < safeMargin) && (m_leaveXVelocity[i] < 0.0f) )
        {
            m_leaveXVelocity[i] = 0.0f;
        }

        if ( (m_leaveYPos[i] > yLimit - safeMarginDown) && (m_leaveYVelocity[i] > 0.0f) )
        {
            m_leaveYVelocity[i] = 0.0f;
        }
        if ( (m_leaveYPos[i] < safeMarginUp) && (m_leaveYVelocity[i] < 0.0f) )
        {
            m_leaveYVelocity[i] = 0.0f;
        }

        // position change according to velocity
        m_leaveXPos[i] += m_leaveXVelocity[i];
        m_leaveYPos[i] += m_leaveYVelocity[i];

        // rotation handling
        const VfxFloat rotateVaryScale = 0.000005f * (65536 + rand() % 65536);
        const VfxFloat xVDiff = m_leaveXVelocity[i] - orgXVelocity;
        const VfxFloat yVDiff = m_leaveYVelocity[i] - orgYVelocity;
        const VfxFloat rotateSpeedLimit = 5.0f;

        // apply a magic relation between rotation speed and velocity
        m_rotationV[i] += rotateVaryScale * (xVDiff - yVDiff); 

        const VfxFloat rotateSpeedRandomScale = 0.0002f;
        m_rotationV[i] += vapp_wave_3d_draw_random() * rotateSpeedRandomScale; // add random rotation speed

        // limit rotation speed
        m_rotationV[i] = vfxMin(m_rotationV[i], rotateSpeedLimit);
        m_rotationV[i] = vfxMax(m_rotationV[i], -rotateSpeedLimit);

        const VfxFloat rotateDecayRate = 1.0f / 128.0f;
        m_rotationV[i] -= m_rotationV[i] * rotateDecayRate; // rotation speed delay
        m_rotation[i] += m_rotationV[i]; // rotation change according to rotation speed
    }
}

vrt_render_dirty_type_enum VappWave3DDraw::framePropertyEffectCallback(
    vrt_frame_visual_property_struct *target_frame,
    const vrt_frame_visual_property_struct *watch_frame,
    void *user_data,
    vrt_u32 user_data_size)
{
    VfxMatrix4x4 camera;
    VappWave3DDraw * self = *((VappWave3DDraw**)user_data);

    float drawHeight = static_cast<float>(self->m_height * VAPP_WALLPAPER_3D_WAVE_BUFFER_RATIO);

	camera.setCamera(
                1.0f,
                1.0f,
                0.0f,
                0.0f,
                drawHeight,
                drawHeight,
                VfxFloat(0.0f),
                VfxFloat(0.0f),
                VfxFloat(0.0f) );

    vrt_s32 i = target_frame->border_color;
    VfxS32 x = static_cast<VfxS32>(self->m_leaveXPos[i] );
    VfxS32 y = static_cast<VfxS32>(self->m_leaveYPos[i] );
    HeightType * pData = self->m_pData1;
    VfxFloat xDiff = 0;
    VfxFloat yDiff = 0;
    if (pData)
    {
        vappWave3DGetDiff(pData, x / VAPP_WALLPAPER_3D_WAVE_BUFFER_RATIO,
                y / VAPP_WALLPAPER_3D_WAVE_BUFFER_RATIO, self->m_width, self->m_height, xDiff, yDiff);
    }
    const float rotateThreshold = 0.05f;
    const float rotateLimit = 0.5f;
    if (vfxAbs(xDiff) < rotateThreshold)
    {
        xDiff = 0.0f;
    }
    else
    {
        if (xDiff > 0.0)
        {
            xDiff -= rotateThreshold;
        }
        else
        {
            xDiff += rotateThreshold;
        }
    }
    if (vfxAbs(yDiff) < 0.05f)
    {
        yDiff = 0.0f;
    }
    else
    {
        if (yDiff > 0.0)
        {
            yDiff -= rotateThreshold;
        }
        else
        {
            yDiff += rotateThreshold;
        }
    }
    xDiff = vfxMin(xDiff, rotateLimit);
    xDiff = vfxMax(xDiff, -rotateLimit);
    yDiff = vfxMin(yDiff, rotateLimit);
    yDiff = vfxMax(yDiff, -rotateLimit);

    VfxMatrix4x4 rotateByX;
    rotateByX.setRotateByX(VFX_DEG_TO_RAD(45.0f * yDiff) );
    VfxMatrix4x4 rotateByY;
    rotateByY.setRotateByY(VFX_DEG_TO_RAD(45.0f * xDiff) );
    VfxMatrix4x4 rotateByZ;
    VfxFloat rotation = self->m_rotation[i];
    rotateByZ.setRotateByZ(VFX_DEG_TO_RAD(rotation) );

    float xTrans = target_frame->bounds.size.width / 2.0f;
    float yTrans = target_frame->bounds.size.height / 2.0f;
    VfxMatrix4x4 translate1;
    translate1.setTranslation(xTrans, yTrans, 0);
    VfxMatrix4x4 translate2;
    translate2.setTranslation(-xTrans, -yTrans, 0);
    VfxMatrix4x4 translatePos;
    translatePos.setTranslation(static_cast<float>(x), static_cast<float>(y), 0);
    VfxMatrix4x4 model = camera * translatePos * translate1 * rotateByX * rotateByY * rotateByZ * translate2;

    VfxTransform tempTransform;
    model.initMatrix3x3(tempTransform.data.matrix3x3);
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

    tempTransform.initVrtTransform(target_frame->transform);

    target_frame->pos.x = 0;
    target_frame->pos.y = 0;

	return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

void VappWave3DDraw::onInitResource()
{
    const char vShaderStr[] =  
        "attribute vec4 vPosition;\n"
        "attribute vec2 a_TexCoord;\n"
        "varying vec2 vTexCoord;\n"
        "void main()\n"
        "{\n"
        "gl_Position = vPosition;\n"
        "vTexCoord = a_TexCoord;\n"
        "}\n";

#ifdef __MTK_TARGET__
    bool useBinary = true;
#else
    bool useBinary = false;
#endif


//#define WAVE_3D_USE_FILE_SHADER

#ifdef WAVE_3D_USE_FILE_SHADER
    // load shader
#ifdef __MTK_TARGET__
    const WCHAR * fsFilename = (const WCHAR *)L"c:\\test\\wave2.fsb";
#else
    const WCHAR * fsFilename = (const WCHAR *)L"c:\\test\\wave2.fs";
#endif // __MTK_TARGET__

    char fShaderStr[5000];
    UINT fs,fsize;
    FS_HANDLE handle = FS_Open (fsFilename, FS_READ_ONLY);
    FS_GetFileSize(handle, &fs);
    FS_Read (handle, fShaderStr, fs, &fsize);
    fShaderStr[fsize] = '\0';
    FS_Close (handle);

    m_fragmentShader = waveLoadShader (useBinary, GL_FRAGMENT_SHADER, fShaderStr, fs);

#else // WAVE_3D_USE_FILE_SHADER

    const char *start = (const char*)GetBinary(VAPP_WALLPAPER_3D_WAVE_FRAGMENT_SHADER);
    if (start == NULL)
    {
        VFX_DEV_ASSERT(0);
    }
    /* first byte is type, 2~5 is size */
    const unsigned char *header = (const unsigned char*)start;
    U32 size = *((U32*)(header+1));
    start += 8;

    char *shaderSrc = NULL;

#ifndef __MTK_TARGET__
    char *source = (char *)applib_asm_alloc_anonymous_nc(sizeof(char) * (size + 1));
    memcpy(source, start, size);

    // WORKAROUND: add null-terminal after source from res
    source[size] = 0;
    shaderSrc = source;
#else
    shaderSrc = (vrt_char*)start;
#endif // __MTK_TARGET__

    m_fragmentShader = waveLoadShader (useBinary, GL_FRAGMENT_SHADER, shaderSrc, size);

#endif // WAVE_3D_USE_FILE_SHADER

    GLint linked;

    // Load the vertex/fragment shaders
    m_vertexShader = waveLoadShader (false, GL_VERTEX_SHADER, vShaderStr, 0);

    // Create the program object
    m_programObject = glCreateProgram ( );

    VFX_DEV_ASSERT(m_programObject);

    glAttachShader ( m_programObject, m_vertexShader );
    glAttachShader ( m_programObject, m_fragmentShader );

    glGenTextures ( 1, &m_texId );

    // Link the program
    glLinkProgram ( m_programObject );

    // Check the link status
    glGetProgramiv ( m_programObject, GL_LINK_STATUS, &linked );

    if ( !linked )
    {
        glDeleteProgram ( m_programObject );
        m_programObject = 0;
        VFX_DEV_ASSERT(0);
    }

    // Store the program object

    m_positionLoc = glGetAttribLocation ( m_programObject, "vPosition" );
    m_texCoordLoc = glGetAttribLocation ( m_programObject, "a_TexCoord" );
    m_samplerLoc = glGetUniformLocation ( m_programObject, "s_texture" );
    m_baseTexLoc = glGetUniformLocation ( m_programObject, "s_baseTex" );

    glClearColor ( 0.0f, 0.0f, 0.0f, 0.0f );

#ifdef VAPP_WALLPAPER_WAVE_3D_USE_STATIC_MEM
    m_buffer = g_pBuffer;
    m_pData1 = g_pData1;
    m_pData2 = g_pData2;
#else
    m_buffer = (DiffMapType*)mmi_frm_asm_alloc_anonymous(m_width * m_height * sizeof(DiffMapType) );
    m_pData1 = (HeightType*)mmi_frm_asm_alloc_anonymous(m_width * m_height * sizeof(HeightType) );
    m_pData2 = (HeightType*)mmi_frm_asm_alloc_anonymous(m_width * m_height * sizeof(HeightType) );
#endif
    for (VfxS32 i = 0; i < m_width * m_height; ++i)
    {
        m_pData1[i] = 0;
        m_pData2[i] = 0;
    }

    // create texture
    m_bgTexId = CreateTexture2D_Res (IMG_ID_VAPP_WALLPAPER_3D_WAVE_BG, GL_RGBA, VFX_TRUE);
}

void VappWave3DDraw::onDeinitResource()
{
#ifndef VAPP_WALLPAPER_WAVE_3D_USE_STATIC_MEM
    mmi_frm_asm_free_anonymous(m_buffer);
    mmi_frm_asm_free_anonymous(m_pData1);
    mmi_frm_asm_free_anonymous(m_pData2);
    m_buffer = NULL;
    m_pData1 = NULL;
    m_pData2 = NULL;
#endif
    if (m_bgTexId)
    {
        glDeleteTextures(1, &m_bgTexId);
        m_bgTexId = 0;
    }
    if (m_texId)
    {
        glDeleteTextures(1, &m_texId);
        m_texId = 0;
    }
    if (m_vertexShader)
    {
        glDeleteShader(m_vertexShader);
        m_vertexShader = 0;
    }
    if (m_fragmentShader)
    {
        glDeleteShader(m_fragmentShader);
        m_fragmentShader = 0;
    }
    if (m_programObject)
    {
        glDeleteProgram(m_programObject);
        m_programObject = 0;
    }
}

void VappWave3DDraw::onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect)
{
    GLfloat vVertices[] = {-1.0f,  1.0f, 0.0f, 
                           -1.0f, -1.0f, 0.0f,
                            1.0f,  1.0f, 0.0f,
                            1.0f, -1.0f, 0.0f};

    GLfloat vTexture[] = { 0.0, 0.0,
                           0.0, 1.0,
                           1.0, 0.0,
                           1.0, 1.0};

    // Set the viewport
    glViewport (0, 0, m_width * VAPP_WALLPAPER_3D_WAVE_BUFFER_RATIO, m_height * VAPP_WALLPAPER_3D_WAVE_BUFFER_RATIO);

    // Clear the color buffer
    glClear ( GL_COLOR_BUFFER_BIT );

    // Use the program object
    glUseProgram ( m_programObject );

    // texture
    glActiveTexture ( GL_TEXTURE0 );
    glBindTexture ( GL_TEXTURE_2D, m_bgTexId );
    glUniform1i ( m_baseTexLoc, 0 );

    for (VfxU32 i = 0; i < 3; ++i)
    {
        processWave();
    }
    glActiveTexture ( GL_TEXTURE1 );
    processTexture();

    glBindTexture ( GL_TEXTURE_2D, m_texId );

    //glTexImage2D ( GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_buffer );
    glTexImage2D ( GL_TEXTURE_2D, 0, GL_LUMINANCE_ALPHA, m_width, m_height, 0, GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE, m_buffer );
    glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );

    glUniform1i (m_samplerLoc, 1 );

    // Load the vertex data
    glVertexAttribPointer ( m_positionLoc, 3, GL_FLOAT, GL_FALSE, 0, vVertices );
    glEnableVertexAttribArray ( m_positionLoc );

    glVertexAttribPointer ( m_texCoordLoc, 2, GL_FLOAT, GL_FALSE, 0, vTexture );
    glEnableVertexAttribArray ( m_texCoordLoc );

    glDrawArrays ( GL_TRIANGLE_STRIP, 0, 4 );

    leaveMotions();
}

vrt_bool VappWave3DDraw::isUsingGLAPI() const
{
    return VFX_TRUE;
}

#ifdef __VAPP_WALLPAPER_3D_WAVE_MOTION_SENSOR_SUPPORT__
void VappWave3DDraw::setGravity(VfxFloat xGravity, VfxFloat yGravity)
{
    m_xGravityDiff += xGravity - m_xGravity;
    m_yGravityDiff += yGravity - m_yGravity;
    m_xGravity = xGravity;
    m_yGravity = yGravity;
}

void onWallpaper3DWaveMotionTiltDetailCallback(
        srv_sensor_type_enum sensor_type, void *sensor_data, void *user_data)
{
    srv_sensor_motion_tilt_struct *p_tilt;
    p_tilt = ( srv_sensor_motion_tilt_struct *)sensor_data;

    VappWave3DDraw *ownerDraw = (VappWave3DDraw*)user_data;

    VfxFloat x_gravity = (VfxFloat)p_tilt->acc.x / 980.0f;
    VfxFloat y_gravity = (VfxFloat)p_tilt->acc.y / 980.0f;
    ownerDraw->setGravity(x_gravity, y_gravity);
}
#endif // __VAPP_WALLPAPER_3D_WAVE_MOTION_SENSOR_SUPPORT__


/*****************************************************************************
 * Home screen UI componet: 3D Wave wallpaper
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("3D Wave Wallpaper", VappWallpaper3DWave, VappWallpaper);

VappWallpaper3DWave::VappWallpaper3DWave():
    m_wave(NULL),
    m_randomWaveTimer(NULL)
{
#ifdef __VAPP_WALLPAPER_3D_WAVE_MOTION_SENSOR_SUPPORT__
    m_motionTiltHandle = -1;
#endif // __VAPP_WALLPAPER_3D_WAVE_MOTION_SENSOR_SUPPORT__
}

void VappWallpaper3DWave::onCreateView()
{
    VfxSize screenSize = getScreenSize();
    VfxS32 bufferWidth = screenSize.width / VAPP_WALLPAPER_3D_WAVE_BUFFER_RATIO;
    VfxS32 bufferHeight = screenSize.height / VAPP_WALLPAPER_3D_WAVE_BUFFER_RATIO;
    VFX_OBJ_CREATE_EX(m_wave, VappWave3DDraw, this, (bufferWidth, bufferHeight) );
    setOwnerDraw(m_wave);

    VFX_OBJ_CREATE(m_zTimeline, VfxFloatTimeline, this);
    m_zTimeline->setTarget(this);
    m_zTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Z);
    m_zTimeline->setDurationTime(10000);
    //m_zTimeline->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    m_zTimeline->setFromValue(0.0f);
    m_zTimeline->setToValue(1.0f);
    m_zTimeline->start();

    VFX_OBJ_CREATE(m_randomWaveTimer, VfxTimer, this);
    m_randomWaveTimer->setStartDelay(VAPP_WALLPAPER_3D_WAVE_START_DELAY);
    m_randomWaveTimer->setDuration(VAPP_WALLPAPER_3D_WAVE_DURATION);
    m_randomWaveTimer->m_signalTick.connect(this, &VappWallpaper3DWave::onWaveTimer);
    m_randomWaveTimer->start();

#ifdef __VAPP_WALLPAPER_3D_WAVE_MOTION_SENSOR_SUPPORT__
    m_motionTiltHandle = srv_sensor_start_listen(SRV_SENSOR_MOTION_TILT , 
            NULL, &onWallpaper3DWaveMotionTiltDetailCallback, m_wave);
#endif // __VAPP_WALLPAPER_3D_WAVE_MOTION_SENSOR_SUPPORT__
}


void VappWallpaper3DWave::onReleaseView()
{
#ifdef __VAPP_WALLPAPER_3D_WAVE_MOTION_SENSOR_SUPPORT__
    /* disable motion sensor */
    if (m_motionTiltHandle >= 0)
    {
        srv_sensor_stop_listen(m_motionTiltHandle);
        m_motionTiltHandle = -1;
    }
#endif // __VAPP_WALLPAPER_3D_WAVE_MOTION_SENSOR_SUPPORT__

    m_randomWaveTimer->stop();
    VFX_OBJ_CLOSE(m_randomWaveTimer);
    setOwnerDraw(NULL);
    //VFX_OBJ_CLOSE(m_wave);
    VFX_OBJ_CLOSE(m_zTimeline);
}


MMI_IMG_ID VappWallpaper3DWave::getThumbnail()
{
    return IMG_ID_VAPP_WALLPAPER_3D_WAVE_THUMB;
}

void VappWallpaper3DWave::getName(VfxWString &wallpaperName)
{
    wallpaperName.loadFromRes(STR_ID_WALLPAPER_VUI_LIVE_3D_WAVE);
}

void VappWallpaper3DWave::onSuspend()
{
}

void VappWallpaper3DWave::onResume()
{
}

VfxBool VappWallpaper3DWave::onPenInput(VfxPenEvent &event)
{
    if (getOwnerDraw() == NULL)
    {
        return VfxControl::onPenInput(event);
    }
    VfxSize screenSize = getScreenSize();
    VfxPoint pt = event.getRelPos(this);
    VfxS32 x = pt.x * m_wave->getWidth() / screenSize.width;
    VfxS32 y = pt.y * m_wave->getHeight() / screenSize.height;
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        m_wave->clickStart(x, y);
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        VfxPoint pt = event.getRelPos(this);
        m_wave->click(x, y);
    }

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN || event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        setAnimating();
    }
    return VfxControl::onPenInput(event);
}


void VappWallpaper3DWave::onWaveTimer(VfxTimer *obj)
{
    if (getOwnerDraw() == NULL)
    {
        return;
    }
    const VfxS32 margin = VAPP_WALLPAPER_3D_WAVE_DROP_MARGIN;
    const VfxS32 x = margin + (rand() % (m_wave->getWidth() - margin));
    const VfxS32 y = margin + (rand() % (m_wave->getHeight() - margin));
    m_wave->clickOnePoint(x, y);
    setAnimating();
}


void VappWallpaper3DWave::onWidgetDropped(VfxPoint pos, VfxControl *targetWidget)
{
    VappWallpaper::onWidgetDropped(pos, targetWidget);

    if (getOwnerDraw() == NULL)
    {
        return;
    }

    VfxSize screenSize = getScreenSize();
    VfxS32 x = pos.x * m_wave->getWidth() / screenSize.width;
    VfxS32 y = pos.y * m_wave->getHeight() / screenSize.height;
    m_wave->clickOnePoint(x, y);

    setAnimating();
}

void VappWallpaper3DWave::setAnimating()
{
    if (m_zTimeline)
    {
        m_zTimeline->stop();
        m_zTimeline->setDurationTime(30000);
        m_zTimeline->setToValue(1.0f);
        m_zTimeline->start();
    }
}

void VappWallpaper3DWave::onDesktopBoundsChanged(
        const VfxU32 totalPage,
        VfxFrame *source,
        const VfxRect &oldBounds)
{
    if (getTotalPage() <= 1)
    {
        return;
    }
}

VfxBool VappWallpaper3DWave::onAllowSuspendOnSwipe()
{
    return VFX_FALSE;
}


#endif // __COSMOS_3D_V10__

