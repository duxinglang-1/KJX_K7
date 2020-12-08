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
 *  vfx_draw_context.cpp
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_draw_context.h"

#include "vfx_frame.h"
#ifdef __VENUS_3D_UI_ENGINE__
#include "vfx_world.h"
#endif

#include "vfx_basic_type.h"
#include "vfx_datatype.h"
#include "vfx_image_src.h"
#include "vrt_canvas.h"
#include "vrt_system.h"
#include "vrt_datatype.h"
#include "vfx_font_desc.h"
#include "vfx_object.h"

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
#include "vpi_system.h"
#endif

/***************************************************************************** 
 * Class VfxDrawContext
 *****************************************************************************/

VfxDrawContext::VfxDrawContext() : m_textOffset(VFX_POINT_ZERO)
{
}


void VfxDrawContext::drawImage(VfxS32 x, VfxS32 y, const VfxImageSrc &imgSrc)
{
    if (imgSrc.isEmpty() && imgSrc.getType() != VFX_IMAGE_SRC_TYPE_PATH)
    {
        return;
    }

    switch (imgSrc.getType())
    {
        case VFX_IMAGE_SRC_TYPE_NULL:
            // Do nothing.
            break;
                
        case VFX_IMAGE_SRC_TYPE_RES_ID:
        {
            vrt_canvas_draw_image_from_res_id(x, y, imgSrc.getResId());
            break;
        }

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
        case VFX_IMAGE_SRC_TYPE_MRE_RES_ID:
        {
            const void *mem = vpi_sys_get_vm_resource(imgSrc.getHandle(), imgSrc.getMreResId(), VFX_FALSE);
            vrt_canvas_draw_image_from_mem(x, y, mem);
            break;
        }
#endif

        case VFX_IMAGE_SRC_TYPE_MEM:
        {
            const VfxU8 *mem = imgSrc.getMem();
            vrt_canvas_draw_image_from_mem(x, y, mem);
            break;
        }

        case VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER:
        {
            vrt_image_buffer_struct vrtImageBuf;
            imgSrc.getImageBuffer().initVrtImageBuffer(vrtImageBuf);
            vrt_canvas_draw_img_buf(x, y, &vrtImageBuf);
            break;
        }

        case VFX_IMAGE_SRC_TYPE_PATH:
        {
            const VfxWChar *path = imgSrc.getPath().getBuf();
            const vrt_sys_image_info_struct *info = imgSrc.getImageFileInfo();
            vrt_canvas_draw_image_from_file(x, y, path, info);
            break;
        }

        case VFX_IMAGE_SRC_TYPE_FILE_RAW_DATA:
        {
            vrt_file_raw_data_buffer_struct vrtRawData;
            imgSrc.getImageRawDataBuffer().initVrtImageBuffer(vrtRawData);
            vrt_canvas_draw_img_raw_data(x, y, &vrtRawData);
            break;
        }

        default:
            // Do nothing
            break;
    }
}


void VfxDrawContext::drawResizedImage(const VfxRect &rect, const VfxImageSrc &imgSrc)
{
    if (imgSrc.isEmpty() && imgSrc.getType() != VFX_IMAGE_SRC_TYPE_PATH)
    {
        return;
    }

    switch (imgSrc.getType())
    {
        case VFX_IMAGE_SRC_TYPE_NULL:
            // Do nothing.
            break;
                
        case VFX_IMAGE_SRC_TYPE_RES_ID:
        {
            vrt_rect_struct vrtRect = rect;
            vrt_canvas_draw_resized_image_from_res_id(&vrtRect, imgSrc.getResId());
            break;
        }

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
        case VFX_IMAGE_SRC_TYPE_MRE_RES_ID:
        {
            vrt_rect_struct vrtRect = rect;
            const void *mem = vpi_sys_get_vm_resource(imgSrc.getHandle(), imgSrc.getMreResId(), VFX_FALSE);
            vrt_canvas_draw_resized_image_from_mem(&vrtRect, mem);
            break;
        }
#endif

        case VFX_IMAGE_SRC_TYPE_MEM:
        {
            vrt_rect_struct vrtRect = rect;
            const VfxU8 *mem = imgSrc.getMem();
            vrt_canvas_draw_resized_image_from_mem(&vrtRect, mem);
            break;
        }

        case VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER:
        {
            vrt_rect_struct vrtRect = rect;
            vrt_image_buffer_struct vrtImageBuf;
            imgSrc.getImageBuffer().initVrtImageBuffer(vrtImageBuf);
            vrt_canvas_draw_resized_img_buf(&vrtRect, &vrtImageBuf);
            break;
        }

        case VFX_IMAGE_SRC_TYPE_PATH:
        {
            vrt_rect_struct vrtRect = rect;
            const VfxWChar *path = imgSrc.getPath().getBuf();
            const vrt_sys_image_info_struct *info = imgSrc.getImageFileInfo();
            vrt_canvas_draw_resized_image_from_file(&vrtRect, path, info);
            break;
        }

        case VFX_IMAGE_SRC_TYPE_FILE_RAW_DATA:
        {
            vrt_rect_struct vrtRect = rect;
            vrt_file_raw_data_buffer_struct vrtRawData;
            imgSrc.getImageRawDataBuffer().initVrtImageBuffer(vrtRawData);
            vrt_canvas_draw_resized_raw_data(&vrtRect, &vrtRawData);
            break;
        }

        default:
            // Do nothing
            break;
    }
}


void VfxDrawContext::setFont(const VfxFontDesc &fontDesc)
{
    vrt_font_struct vrtFont;
    fontDesc.initVrtFont(vrtFont);
    vrt_canvas_set_font(&vrtFont);
    
    if(fontDesc.effect == VFX_FONT_DESC_EFFECT_BORDER)
    {
        vrt_text_dir_type_enum dir = vrt_sys_get_text_dir();
        if (dir == MG_TEXT_DIR_TYPE_L2R)
        {
            m_textOffset.x = 1;
            m_textOffset.y = 1;
        }
        else
        {
            m_textOffset.x = -1;
            m_textOffset.y = 1;
        }
    }
    else
    {
        m_textOffset.setZero();
    }
}


void VfxDrawContext::setEllipsis(const VfxWChar *ellipsis)
{
    // We don't know the string is static or dynamic,
    //  so we suggest it is dynamic string for safety
    vrt_canvas_set_ellipsis(
        ellipsis,
        VRT_TRUE);
}


void VfxDrawContext::setEllipsis(const VfxWString &ellipsis)
{
    vrt_canvas_set_ellipsis(
        ellipsis.getBuf(),
        ellipsis.isDynamic() ? VRT_TRUE : VRT_FALSE);
}


void VfxDrawContext::drawText(VfxS32 x, VfxS32 y, const VfxWChar *string)
{
    // We don't know the string is static or dynamic,
    //  so we suggest it is dynamic string for safety
    vrt_canvas_draw_text(
        x + m_textOffset.x, 
        y + m_textOffset.y, 
        string, 
        VRT_TRUE);
}


void VfxDrawContext::drawText(const VfxPoint &pos, const VfxWChar *string)
{
    // We don't know the string is static or dynamic,
    //  so we suggest it is dynamic string for safety
    vrt_canvas_draw_text(
        pos.x + m_textOffset.x, 
        pos.y + m_textOffset.y, 
        string, 
        VRT_TRUE);
}


void VfxDrawContext::drawText(const VfxPoint &pos, const VfxWString &string)
{
    vrt_canvas_draw_text(
        pos.x + m_textOffset.x, 
        pos.y + m_textOffset.y, 
        string.getBuf(), 
        string.isDynamic() ? VRT_TRUE : VRT_FALSE);
}


void VfxDrawContext::drawText(VfxS32 x, VfxS32 y, const VfxWString &string)
{
    vrt_canvas_draw_text(
        x + m_textOffset.x, 
        y + m_textOffset.y, 
        string.getBuf(), 
        string.isDynamic() ? VRT_TRUE : VRT_FALSE);
}


void VfxDrawContext::drawText(VfxS32 x, VfxS32 y, const VfxWChar *string, VfxU32 strLen)
{
    // We don't know the string is static or dynamic,
    //  so we suggest it is dynamic string for safety
    vrt_point_struct vrtPos;
    vrtPos.x = x + m_textOffset.x;
    vrtPos.y = y + m_textOffset.y;
    vrt_canvas_draw_text_n(
        &vrtPos, 
        string, 
        strLen,
        VRT_TRUE);
}


void VfxDrawContext::drawText(const VfxPoint &pos, const VfxWChar *string, VfxU32 strLen)
{
    // We don't know the string is static or dynamic,
    //  so we suggest it is dynamic string for safety
    vrt_point_struct vrtPos;
    vrtPos.x = pos.x + m_textOffset.x;
    vrtPos.y = pos.y + m_textOffset.y;
    vrt_canvas_draw_text_n(
        &vrtPos, 
        string, 
        strLen,
        VRT_TRUE);
}


void VfxDrawContext::drawTextBaseline(VfxS32 x, VfxS32 y, VfxS32 width, VfxS32 height, VfxS32 baseline, const VfxWChar *string, VfxU32 strLen)
{
    drawTextBaseline(VfxRect(x, y, width, height), baseline, string, strLen);
}


void VfxDrawContext::drawTextBaseline(const VfxRect &rect, VfxS32 baseline, const VfxWChar *string, VfxU32 strLen)
{
    // We don't know the string is static or dynamic,
    //  so we suggest it is dynamic string for safety
    vrt_rect_struct vrtRect = rect;
    vrtRect.origin.x += m_textOffset.x;
    vrtRect.origin.y += m_textOffset.y;
    vrt_canvas_draw_text_n_baseline(
        &vrtRect, 
        baseline, 
        string, 
        strLen,
        VRT_TRUE);
}


void VfxDrawContext::drawTextTruncated(VfxS32 x, VfxS32 y, const VfxWChar *string, VfxS32 width)
{
    drawTextTruncated(VfxPoint(x, y), string, width);
}


void VfxDrawContext::drawTextTruncated(const VfxPoint &pos, const VfxWChar *string, VfxS32 width)
{
    // We don't know the string is static or dynamic,
    //  so we suggest it is dynamic string for safety
    vrt_canvas_draw_text_truncated(
        pos.x + m_textOffset.x, 
        pos.y + m_textOffset.y, 
        string, 
        width - VFX_ABS(m_textOffset.x) * 2,
        VRT_TRUE);
}


void VfxDrawContext::drawTextTruncatedBaseline(const VfxRect &rect, const VfxWChar *string, VfxS32 width, VfxS32 baseline)
{
    // We don't know the string is static or dynamic,
    //  so we suggest it is dynamic string for safety
    vrt_rect_struct vrtRect = rect;
    vrtRect.origin.x += m_textOffset.x;
    vrtRect.origin.y += m_textOffset.y;
    vrt_canvas_draw_text_truncated_baseline(
        &vrtRect,
        baseline, 
        string, 
        width - VFX_ABS(m_textOffset.x) * 2,
        VRT_TRUE);
}


void VfxDrawContext::pushAndSetActiveFrame(VfxFrame *frame)
{
    vrt_frame_handle handle = frame->getHandle();
    VFX_ASSERT(handle != NULL);
    
    vrt_canvas_push_and_set_active_frame(handle);

    // TODO: need to restore
    m_textOffset.setZero();
}


void VfxDrawContext::popAndRestoreFrame()
{
    vrt_canvas_pop_and_restore_frame();
}


VfxU32 VfxDrawContext::drawImageContent(const VfxImageSrc &imgSrc, VfxFrameContentPlacementTypeEnum placementType)
{
    VfxU32 ret = 0;
    
    VFX_DEV_ASSERT(placementType < VFX_FRAME_CONTENT_PLACEMENT_TYPE_END_OF_ENUM);

    if (imgSrc.isEmpty() && imgSrc.getType() != VFX_IMAGE_SRC_TYPE_PATH)
    {
        return 0;
    }

    switch (imgSrc.getType())
    {
        case VFX_IMAGE_SRC_TYPE_NULL:
            // Do nothing.
            break;
                
        case VFX_IMAGE_SRC_TYPE_RES_ID:
        {
            vrt_canvas_draw_image_content_from_res_id(
                imgSrc.getResId(),
                (vrt_frame_content_placement_type_enum)placementType);
            break;
        }

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
        case VFX_IMAGE_SRC_TYPE_MRE_RES_ID:
        {
            const void *mem = vpi_sys_get_vm_resource(imgSrc.getHandle(), imgSrc.getMreResId(), VFX_FALSE);
            vrt_canvas_draw_image_content_from_mem(
                mem, 
                (vrt_frame_content_placement_type_enum)placementType,
                (const vrt_size_struct *)&imgSrc.getSize());                
            break;
        }
#endif

        case VFX_IMAGE_SRC_TYPE_MEM:
        {
            const VfxU8 *mem = imgSrc.getMem();
            vrt_canvas_draw_image_content_from_mem(
                mem, 
                (vrt_frame_content_placement_type_enum)placementType,
                (const vrt_size_struct *)&imgSrc.getSize());                
            break;
        }

        case VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER:
        {
            vrt_image_buffer_struct vrtImageBuf;
            imgSrc.getImageBuffer().initVrtImageBuffer(vrtImageBuf);
            ret = vrt_canvas_draw_image_content_from_img_buf(
                &vrtImageBuf, 
                (vrt_frame_content_placement_type_enum)placementType,
                (const vrt_size_struct *)&imgSrc.getSize());                
            break;
        }

        case VFX_IMAGE_SRC_TYPE_PATH:
        {
            const VfxWChar *path = imgSrc.getPath().getBuf();
            const vrt_sys_image_info_struct *info = imgSrc.getImageFileInfo();
            vrt_canvas_draw_image_content_from_file(
                path, 
                (vrt_frame_content_placement_type_enum)placementType,
                info);
            break;
        }

        case VFX_IMAGE_SRC_TYPE_FILE_RAW_DATA:
        {
            vrt_file_raw_data_buffer_struct vrtRawData;
            imgSrc.getImageRawDataBuffer().initVrtImageBuffer(vrtRawData);
            vrt_canvas_draw_image_content_from_raw_data(
                &vrtRawData, 
                (vrt_frame_content_placement_type_enum)placementType,
                (const vrt_size_struct *)&imgSrc.getSize());
            break;
        }

        default:
            // Do nothing
            break;
    }

    return ret;
}


void VfxDrawContext::setResource(const VfxImageSrc &imgSrc)
{
    vrt_image_source_struct vrtImageSrc;
    
    switch (imgSrc.getType())
    {
    case VFX_IMAGE_SRC_TYPE_RES_ID:
        vrtImageSrc.type = VRT_IMAGE_SOURCE_TYPE_MEMORY;
        vrtImageSrc.data.img_ptr = vrt_sys_res_image_lock(imgSrc.getResId());
        break;
#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    case VFX_IMAGE_SRC_TYPE_MRE_RES_ID:
        vrtImageSrc.type = VRT_IMAGE_SOURCE_TYPE_MEMORY;
        vrtImageSrc.data.img_ptr = vpi_sys_get_vm_resource(imgSrc.getHandle(), imgSrc.getMreResId(), VFX_FALSE);
        break;
#endif
    case VFX_IMAGE_SRC_TYPE_MEM:
        vrtImageSrc.type = VRT_IMAGE_SOURCE_TYPE_MEMORY;
        vrtImageSrc.data.img_ptr = imgSrc.getMem();
        break;
    case VFX_IMAGE_SRC_TYPE_PATH:
        {
            const VfxWChar *filename = imgSrc.getPath().getBuf(); 
            vrtImageSrc.type = VRT_IMAGE_SOURCE_TYPE_FILE;
            vrtImageSrc.data.filename.hash = vrt_wstr_hash(filename);
            vrtImageSrc.data.filename.str = filename;
            break;
        }
    case VFX_IMAGE_SRC_TYPE_FILE_RAW_DATA:
        {
            const VfxFileRawData &fileRawData = imgSrc.getImageRawDataBuffer();
            vrtImageSrc.type = VRT_IMAGE_SOURCE_TYPE_IMG_RAW_DATA;
            vrtImageSrc.data.raw_data.buf_p = fileRawData.ptr;
            vrtImageSrc.data.raw_data.image_format =(vrt_raw_data_image_format_enum)fileRawData.imageFormat;
            vrtImageSrc.data.raw_data.image_size = fileRawData.imageSize;
            break;
        }
    default:
        // Do nothing
        return;
    }


    vrt_canvas_set_resource(&vrtImageSrc);
}


#ifdef __VENUS_3D_UI_ENGINE__
void VfxDrawContext::drawWorld(const VfxWorld *world)
{
    VFX_OBJ_ASSERT_VALID(world);

    vrt_object_handle handle = world->getSyncHandle();
    vrt_canvas_draw_world(handle);
}
#endif

