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
 *  vfx_draw_context.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Description
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_DRAW_CONTEXT_H__
#define __VFX_DRAW_CONTEXT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxBase
#include "vfx_cpp_base.h"

#include "vfx_basic_type.h"
#include "vfx_image_src.h"
#include "vfx_datatype.h"
#include "vfx_font_desc.h"
#include "vfx_string.h"
#include "vfx_frame.h"

#include "vrt_datatype.h"
#include "vrt_canvas.h"
#include "vrt_system.h"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 
// Predefine Classes
class VfxImageBuffer;
class VfxImageSrc;
class VfxFrame;

#ifdef __VENUS_3D_UI_ENGINE__
class VfxWorld;
#endif


/***************************************************************************** 
 * Class VfxDrawContext
 *****************************************************************************/

/*
 * VfxDrawContext provides methods to draw a frame content.
 *
 * NOTE: All methods are in frame coordinate system.
 *
 * SEE ALSO: VfxFrame::onDraw
 */
class VfxDrawContext : public VfxBase
{
    VFX_DECLARE_NO_COPY_CLASS(VfxDrawContext);

// Constructor / Destructor     
public:
    // Default constructor.
    VfxDrawContext();

// Method
public:
    // Set clipping rectangle of draw conext.
    void setClip(
        const VfxRect &clipRect     // [IN] The clipping rectangle to set
    );

    // Set fill color of draw conext.
    void setFillColor(
        const VfxColor &color       // [IN] The fill color to set
    );

    // Set stroke color of draw conext.
    void setStrokeColor(
        const VfxColor &color       // [IN] The stroke color to set
    );

    // Set fallback image from resource id to draw context.
    void setFallbackImage(
        VfxResId resId        // [IN] The resource ID of fallback image
    );

    // Draw a filled rectangle with fill color.
    void fillRect(
        VfxS32 x,                   // [IN] The x coordinate of the rectangle origin
        VfxS32 y,                   // [IN] The y coordinate of the rectangle origin
        VfxS32 width,               // [IN] The width of the rectangle 
        VfxS32 height               // [IN] The height of the rectangle 
    );
    
    // Draw a filled rectangle with fill color.
    void fillRect(
        const VfxRect &rect         // [IN] The rectangle to draw
    );
    
    // Draw a image with a VfxImageSrc
    //
    // SEE ALSO: VfxImageSrc
    void drawImage(
        VfxS32 x,                   // [IN] The x coordinate to draw
        VfxS32 y,                   // [IN] The y coordinate to draw
        const VfxImageSrc &imgSrc   // [IN] The image source to draw
    );
    
    // Draw a image with a VfxImageSrc
    //
    // SEE ALSO: VfxImageSrc
    void drawImage(
        const VfxPoint &pos,        // [IN] The position to draw
        const VfxImageSrc &imgSrc   // [IN] The image source to draw
    );
    
    // Draw a image with a resource ID
    void drawImageFromRes(
        VfxS32 x,                   // [IN] The x coordinate to draw
        VfxS32 y,                   // [IN] The y coordinate to draw
        VfxResId res_id             // [IN] The resource ID of the image
    );

    // Draw a image with a resource ID
    void drawImageFromRes(
        const VfxPoint &pos,        // [IN] The position to draw
        VfxResId res_id             // [IN] The resource ID of the image
    );
    
    // Draw a image with a memory pointer
    void drawImageFromMem(
        VfxS32 x,                   // [IN] The x coordinate to draw
        VfxS32 y,                   // [IN] The y coordinate to draw
        const void *image_ptr       // [IN] The memory pointer with 8 bytes header
    );
    
    // Draw a image with a memory pointer
    void drawImageFromMem(
        const VfxPoint &pos,        // [IN] The position to draw
        const void *image_ptr       // [IN] The memory pointer with 8 bytes header
    );
    
    // Draw a resized image with a VfxImageSrc
    //
    // SEE ALSO: VfxImageSrc
    void drawResizedImage(
        const VfxRect &rect,        // [IN] The rectangle to fit the image
        const VfxImageSrc &imgSrc   // [IN] The image source to draw
    );

    // Draw a resized image with a resource ID
    void drawResizedImageFromRes(
        const VfxRect &rect,        // [IN] The rectangle to fit the image
        VfxResId res_id             // [IN] The resource ID of the image
    );

    // Draw a resized image with a memory pointer
    void drawResizedImageFromMem(
        const VfxRect &rect,        // [IN] The rectangle to fit the image
        const void *image_ptr       // [IN] The memory pointer with 8 bytes header
    );
    
    // Draw a GDI layer
    void drawLayer(
        VfxS32 x,                   // [IN] The x coordinate to draw
        VfxS32 y,                   // [IN] The y coordinate to draw
        void *layerHandle           // [IN] The GDI layer to draw
    );
    
    // Draw a GDI layer
    void drawLayer(
        const VfxPoint &pos,        // [IN] The position to draw
        void *layerHandle           // [IN] The GDI layer to draw
    );

    // Draw a resized layer
    void drawResizedLayer(
        const VfxRect &rect,        // [IN] The rectangle to fit the image
        void *layerHandle           // [IN] The GDI layer to draw
    );

    // Draw a image buffer
    void drawImageBuffer(
        VfxS32 x,                       // [IN] The x coordinate to draw
        VfxS32 y,                       // [IN] The y coordinate to draw
        const VfxImageBuffer &imageBuf  // [IN] The image buffer to draw
    );

    // Draw a image buffer
    void drawImageBuffer(
        const VfxPoint &pos,            // [IN] The position to draw
        const VfxImageBuffer &imageBuf  // [IN] The image buffer to draw
    );

    // Draw a resized image buffer
    void drawResizedImageBuffer(
        const VfxRect &rect,            // [IN] The rectangle to fit the image buffer
        const VfxImageBuffer &imageBuf  // [IN] The image buffer to draw
    );

    // Set the current font to draw text
    void setFont(
        const VfxFontDesc &fontDesc // [IN] The font description to set
    );
    
    // Set the truncate string
    void setEllipsis(
        const VfxWChar *ellipsis    // [IN] The truncate string to set
    );

    // Set the truncate string
    void setEllipsis(
        const VfxWString &ellipsis  // [IN] The truncate string to set
    );

    // Draw a text
    //
    // NOTE: The text color is fill color, and the border color is stroke color.
    //
    // SEE ALSO: setFont
    void drawText(
        VfxS32 x,                   // [IN] The x coordinate to draw text
        VfxS32 y,                   // [IN] The y coordinate to draw text
        const VfxWChar *string      // [IN] The string to draw
    );
    
    // Draw a text
    //
    // NOTE: The text color is fill color, and the border color is stroke color.
    //
    // SEE ALSO: setFont
    void drawText(
        const VfxPoint &pos,        // [IN] The position to draw text
        const VfxWChar *string      // [IN] The string to draw
    );
    
    // Draw a text
    //
    // NOTE: The text color is fill color, and the border color is stroke color.
    //
    // SEE ALSO: setFont
    void drawText(
        const VfxPoint &pos,        // [IN] The position to draw text
        const VfxWString &string    // [IN] The string to draw
    );
    
    // Draw a text
    //
    // NOTE: The text color is fill color, and the border color is stroke color.
    //
    // SEE ALSO: setFont
    void drawText(
        VfxS32 x,                   // [IN] The x coordinate to draw text
        VfxS32 y,                   // [IN] The y coordinate to draw text
        const VfxWString &string    // [IN] The string to draw
    );
    
    // Draw a text with string length
    //
    // NOTE: The text color is fill color, and the border color is stroke color.
    //
    // SEE ALSO: setFont
    void drawText(
        VfxS32 x,                   // [IN] The x coordinate to draw text
        VfxS32 y,                   // [IN] The y coordinate to draw text
        const VfxWChar *string,     // [IN] The string to draw
        VfxU32 strLen               // [IN] The string length
    );
    
    // Draw a text with string length
    //
    // NOTE: The text color is fill color, and the border color is stroke color.
    //
    // SEE ALSO: setFont
    void drawText(
        const VfxPoint &pos,        // [IN] The position to draw text
        const VfxWChar *string,     // [IN] The string to draw
        VfxU32 strLen               // [IN] The string length
    );
    
    // Draw a text with baseline
    //
    // NOTE: The text color is fill color, and the border color is stroke color.
    //
    // SEE ALSO: setFont
    void drawTextBaseline(
        VfxS32 x,                   // [IN] The x coordinate to draw text
        VfxS32 y,                   // [IN] The y coordinate to draw text
        VfxS32 width,               // [IN] output width
        VfxS32 height,              // [IN] output height
        VfxS32 baseline,            // [IN] The baseline height
        const VfxWChar *string,     // [IN] The string to draw
        VfxU32 strLen               // [IN] The string length
    );
    
    // Draw a text with baseline
    //
    // NOTE: The text color is fill color, and the border color is stroke color.
    //
    // SEE ALSO: setFont
    void drawTextBaseline(
        const VfxRect &rect,        // [IN] The rect to draw text
        VfxS32 baseline,            // [IN] The baseline height
        const VfxWChar *string,     // [IN] The string to draw
        VfxU32 strLen               // [IN] The string length
    );
    
    // Draw a text with truncated width
    //
    // NOTE: The text color is fill color, and the border color is stroke color.
    //
    // SEE ALSO: setFont, setEllipsis
    void drawTextTruncated(
        VfxS32 x,                   // [IN] The x coordinate to draw text
        VfxS32 y,                   // [IN] The y coordinate to draw text
        const VfxWChar *string,     // [IN] The string to draw
        VfxS32 width                // [IN] The width to truncate
    );
    
    // Draw a text with truncated width
    //
    // NOTE: The text color is fill color, and the border color is stroke color.
    //
    // SEE ALSO: setFont, setEllipsis
    void drawTextTruncated(
        const VfxPoint &pos,        // [IN] The position to draw text
        const VfxWChar *string,     // [IN] The string to draw
        VfxS32 width                // [IN] The width to truncate
    );

    // Draw a text with truncated width
    //
    // NOTE: The text color is fill color, and the border color is stroke color.
    //
    // SEE ALSO: setFont, setEllipsis
    void drawTextTruncatedBaseline(
        const VfxRect &rect,        // [IN] The rect to draw text
        const VfxWChar *string,     // [IN] The string to draw
        VfxS32 width,               // [IN] The width to truncate
        VfxS32 baseline             // [IN] The baseline
    );


    // Draw a pixel with stroke color
    void drawPixel(
        VfxS32 x,                   // [IN] The x coordinate to draw
        VfxS32 y                    // [IN] The y coordinate to draw
    );
    
    // Draw a pixel with stroke color
    void drawPixel(
        const VfxPoint &pos         // [IN] The position to draw
    );
    
    // Draw a line with stroke color
    void drawLine(
        VfxS32 x1,                  // [IN] The x coordinate of the first point
        VfxS32 y1,                  // [IN] The y coordinate of the first point
        VfxS32 x2,                  // [IN] The x coordinate of the second point
        VfxS32 y2                   // [IN] The y coordinate of the second point
    );
    
    // Draw a line with stroke color
    void drawLine(
        const VfxPoint &p1,         // [IN] The the first point to draw
        const VfxPoint &p2          // [IN] The the second point to draw
    );
    
    // Draw a anti-aliased line with stroke color
    void drawAaLine(
        VfxS32 x1,                  // [IN] The x coordinate of the first point
        VfxS32 y1,                  // [IN] The y coordinate of the first point
        VfxS32 x2,                  // [IN] The x coordinate of the second point
        VfxS32 y2                   // [IN] The y coordinate of the second point
    );
    
    // Draw a anti-aliased line with stroke color
    void drawAaLine(
        const VfxPoint &p1,         // [IN] The the first point to draw
        const VfxPoint &p2          // [IN] The the second point to draw
    );

// Framework method
public:
    // Internal used.
    void pushAndSetActiveFrame(VfxFrame *frame);
    
    // Internal used.
    void popAndRestoreFrame();

    // Internal used.
    VfxU32 drawImageContent(const VfxImageSrc &imgSrc, VfxFrameContentPlacementTypeEnum placementType);

    // Internal Used. Set resource from image source to draw context.
    void setResource(
        const VfxImageSrc &imgSrc   // [IN] The pointer of the image source
    );

#ifdef __VENUS_3D_UI_ENGINE__
    // Internal used.
    void drawWorld(const VfxWorld * world);
#endif

// Implementation
private:
    VfxPoint m_textOffset;
};


inline
void VfxDrawContext::setClip(const VfxRect &clipRect)
{
    vrt_rect_struct vrtRect = clipRect;
    vrt_canvas_set_clip(&vrtRect);
}


inline
void VfxDrawContext::setFillColor(const VfxColor &color)
{
    vrt_canvas_set_fill_color(color);
}


inline
void VfxDrawContext::setStrokeColor(const VfxColor &color)
{
    vrt_canvas_set_stroke_color(color);
}


inline
void VfxDrawContext::setFallbackImage(VfxResId resId)
{
    vrt_canvas_set_fallback_image(resId);
}

inline
void VfxDrawContext::fillRect(VfxS32 x, VfxS32 y, VfxS32 width, VfxS32 height)
{
    vrt_canvas_fill_rect(x, y, width, height);
}


inline
void VfxDrawContext::fillRect(const VfxRect &rect)
{
    vrt_canvas_fill_rect(rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
}


inline
void VfxDrawContext::drawImage(const VfxPoint &pos, const VfxImageSrc &imgSrc)
{
    drawImage(pos.x, pos.y, imgSrc);
}


inline
void VfxDrawContext::drawImageFromRes(VfxS32 x, VfxS32 y, VfxResId res_id)
{
    vrt_canvas_draw_image_from_res_id(x, y, res_id);
}


inline
void VfxDrawContext::drawImageFromRes(const VfxPoint &pos, VfxResId res_id)
{
    vrt_canvas_draw_image_from_res_id(pos.x, pos.y, res_id);
}


inline
void VfxDrawContext::drawImageFromMem(VfxS32 x, VfxS32 y, const void *image_ptr)
{
    vrt_canvas_draw_image_from_mem(x, y, image_ptr);
}


inline
void VfxDrawContext::drawImageFromMem(const VfxPoint &pos, const void *image_ptr)
{
    vrt_canvas_draw_image_from_mem(pos.x, pos.y, image_ptr);
}


inline
void VfxDrawContext::drawResizedImageFromRes(const VfxRect &rect, VfxResId res_id)
{
    vrt_rect_struct vrtRect = rect;
    vrt_canvas_draw_resized_image_from_res_id(&vrtRect, res_id);
}


inline
void VfxDrawContext::drawResizedImageFromMem(const VfxRect &rect, const void *image_ptr)
{
    vrt_rect_struct vrtRect = rect;
    vrt_canvas_draw_resized_image_from_mem(&vrtRect, image_ptr);
}


inline
void VfxDrawContext::drawLayer(VfxS32 x, VfxS32 y, void *layerHandle)
{
    vrt_canvas_draw_layer(x, y, layerHandle);
}


inline
void VfxDrawContext::drawLayer(const VfxPoint &pos, void *layerHandle)
{
    vrt_canvas_draw_layer(pos.x, pos.y, layerHandle);
}


inline
void VfxDrawContext::drawResizedLayer(const VfxRect &rect, void *layerHandle)
{
    vrt_rect_struct vrtRect = rect;
    vrt_canvas_draw_resized_layer(&vrtRect, layerHandle);
}


inline
void VfxDrawContext::drawImageBuffer(VfxS32 x, VfxS32 y, const VfxImageBuffer &imageBuf)
{
    vrt_image_buffer_struct vrtImageBuffer;
    imageBuf.initVrtImageBuffer(vrtImageBuffer);
    vrt_canvas_draw_img_buf(x, y, &vrtImageBuffer);
}
    

inline
void VfxDrawContext::drawImageBuffer(const VfxPoint &pos, const VfxImageBuffer &imageBuf)
{
    vrt_image_buffer_struct vrtImageBuffer;
    imageBuf.initVrtImageBuffer(vrtImageBuffer);
    vrt_canvas_draw_img_buf(pos.x, pos.y, &vrtImageBuffer);
}


inline
void VfxDrawContext::drawResizedImageBuffer(const VfxRect &rect, const VfxImageBuffer &imageBuf)
{
    vrt_rect_struct vrtRect = rect;
    vrt_image_buffer_struct vrtImageBuffer;
    imageBuf.initVrtImageBuffer(vrtImageBuffer);
    vrt_canvas_draw_resized_img_buf(&vrtRect, &vrtImageBuffer);
}


inline
void VfxDrawContext::drawPixel(VfxS32 x, VfxS32 y)
{
    vrt_canvas_draw_pixel(x, y);
}


inline
void VfxDrawContext::drawPixel(const VfxPoint &pos)
{
    vrt_canvas_draw_pixel(pos.x, pos.y);
}


inline
void VfxDrawContext::drawLine(VfxS32 x1, VfxS32 y1, VfxS32 x2, VfxS32 y2)
{
    vrt_canvas_draw_line(x1, y1, x2, y2);
}


inline
void VfxDrawContext::drawLine(const VfxPoint &p1, const VfxPoint &p2)
{
    vrt_canvas_draw_line(p1.x, p1.y, p2.x, p2.y);
}


inline
void VfxDrawContext::drawAaLine(VfxS32 x1, VfxS32 y1, VfxS32 x2, VfxS32 y2)
{
    vrt_canvas_draw_aa_line(x1, y1, x2, y2);
}


inline
void VfxDrawContext::drawAaLine(const VfxPoint &p1, const VfxPoint &p2)
{
    vrt_canvas_draw_aa_line(p1.x, p1.y, p2.x, p2.y);
}

#endif /* __VFX_DRAW_CONTEXT_H__ */

