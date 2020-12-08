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
 *  vfx_rect_frame.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Rectangle frame class
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_rect_frame.h"

#include "vfx_draw_context.h"
#include "vfx_auto_animate.h"

#include "vfx_datatype.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_cpp_base.h"
#include "vrt_system.h"

extern "C"
{
#include "gui_data_types.h"
#include "CustThemesRes.h"
}


/***************************************************************************** 
 * Define
 *****************************************************************************/

/*
 * Redefine flags in UI filled area structure
 * -------------------
 * bits 0-7:        filler types
 * bit    8:        1=vertical filler, 0=horizontal filler (used for gradients and textures)
 * bit    9:        flip filler
 * bit   10:        (reserved)
 * bit   11:        (reserved)
 * bit   12:        border yes/no
 * bit   13:        border size 0=single line, 1=double line
 * bit   14:        3D border
 * bit   15:        rounded border
 * bit   16:        1=elevated border, 0=depressed border
 * bit   17:        1=filled area with shadow
 * bit   18:        1=filled area with double line shadow, 0=single line shadow
 * bit   19:        (reserved)
 * bit   20:        left rounded border
 * bit   21:        right rounded border
 * bit   22:        Draw only horizontal lines in borders
 * bit   24:        transparent color
 */

/* Bits 0-7: filler type */
#define VFRM_FILLED_AREA_MASK_TYPE                            0x000000FF
#define VFRM_FILLED_AREA_TYPE_COLOR                           0x00000000
#define VFRM_FILLED_AREA_TYPE_GRADIENT_COLOR                  0x00000001
#define VFRM_FILLED_AREA_TYPE_TEXTURE                         0x00000002
#define VFRM_FILLED_AREA_TYPE_BITMAP                          0x00000003
#define VFRM_FILLED_AREA_TYPE_HATCH_COLOR                     0x00000004
#define VFRM_FILLED_AREA_TYPE_ALTERNATE_HATCH_COLOR           0x00000005
#define VFRM_FILLED_AREA_TYPE_CROSS_HATCH_COLOR               0x00000006
#define VFRM_FILLED_AREA_TYPE_ALTERNATE_CROSS_HATCH_COLOR     0x00000007
#define VFRM_FILLED_AREA_TYPE_NO_BACKGROUND                   0x00000008
#define VFRM_FILLED_AREA_TYPE_CUSTOM_FILL_TYPE1               0x00000009  /* Popup description 1 */
#define VFRM_FILLED_AREA_TYPE_CUSTOM_FILL_TYPE2               0x0000000A  /* Popup description 2 */
#define VFRM_FILLED_AREA_TYPE_3D_BORDER                       0x0000000B
#define VFRM_FILLED_AREA_TYPE_IMAGE_RIGHT_ALIGN               0x0000000C
#define VFRM_FILLED_AREA_TYPE_IMAGE_LEFT_ALIGN                0x0000000D

/* Bit 8: horiztonal or vertical fill for gradient color */
#define VFRM_FILLED_AREA_MASK_FILL_DIRECTION                  0x00000100
#define VFRM_FILLED_AREA_HORIZONTAL_FILL                      0x00000000
#define VFRM_FILLED_AREA_VERTICAL_FILL                        0x00000100

/* Bit 9: flip fill or not */
#define VFRM_FILLED_AREA_FLIP_FILL                            0x00000200

/* Bits 12-13: single-double-border */
#define VFRM_FILLED_AREA_MASK_BORDER_WIDTH                    0x00003000
#define VFRM_FILLED_AREA_TYPE_NO_BORDER                       0x00000000
#define VFRM_FILLED_AREA_BORDER                               0x00001000
#define VFRM_FILLED_AREA_SINGLE_BORDER                        0x00001000  /* Contain UI_FILLED_AREA_BORDER */
#define VFRM_FILLED_AREA_DOUBLE_BORDER                        0x00003000  /* Contain UI_FILLED_AREA_BORDER */

/* Bits 14: 3D border */
#define VFRM_FILLED_AREA_3D_BORDER                            0x00004000
/* Bits 15: Rounded border */
#define VFRM_FILLED_AREA_ROUNDED_BORDER                       0x00008000

/* Bits 16: Elevated or depressed border */
#define VFRM_FILLED_AREA_MASK_ELEVATION                       0x00010000
#define VFRM_FILLED_AREA_ELEVATED_BORDER                      0x00010000
#define VFRM_FILLED_AREA_DEPRESSED_BORDER                     0x00000000

/* Combination of Bit 14 and 16 */
#define VFRM_FILLED_AREA_3D_ELEVATED_BORDER                   (VFRM_FILLED_AREA_ELEVATED_BORDER | VFRM_FILLED_AREA_3D_BORDER)
#define VFRM_FILLED_AREA_3D_DEPRESSED_BORDER                  (VFRM_FILLED_AREA_DEPRESSED_BORDER | VFRM_FILLED_AREA_3D_BORDER)

/* Bits 17-18: single-double-shadown */
#define VFRM_FILLED_AREA_MASK_SHADOW                          0x00060000
#define VFRM_FILLED_AREA_SHADOW                               0x00020000
#define VFRM_FILLED_AREA_SHADOW_DOUBLE_LINE                   0x00040000

/* Bit 20: Left rounded border for Dalmatian style */
#define VFRM_FILLED_AREA_LEFT_ROUNDED_BORDER                  0x00100000
/* Bit 21: Right rounded border for Dalmatian style */
#define VFRM_FILLED_AREA_RIGHT_ROUNDED_BORDER                 0x00200000

/* Bit 22: Draw only horizontal lines w/o vertical lines in UI_FILLED_AREA_BORDER */
#define VFRM_FILLED_AREA_NO_VERTICAL_LINE                     0x00400000

/* Bit 24: Transparent color filler */
#define VFRM_FILLED_AREA_TYPE_TRANSPARENT_COLOR               0x01000000

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Global function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  VfxRectFrame::VfxRectFrame
 * DESCRIPTION
 *  Constructor of rectangle frame class.
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
VfxRectFrame::VfxRectFrame() :
    m_filler(NULL)
{
}


/*****************************************************************************
 * FUNCTION
 *  VfxFrame::setFilledArea
 * DESCRIPTION
 *  Set the filled area to rectangle class.
 * PARAMETERS
 *  f               [IN] Is the pointer of UI_filled_area
 * RETURNS
 *
 *****************************************************************************/
void VfxRectFrame::setFilledArea(UI_filled_area *f)
{
    m_filler = f;
    invalidate();
}


/*****************************************************************************
 * FUNCTION
 *  VfxRectFrame::onDraw
 * DESCRIPTION
 *  Display the filled area of rectangle frame.
 * PARAMETERS
 *  dc              [IN] Is a reference of draw context class
 * RETURNS
 *  void
 *****************************************************************************/
void VfxRectFrame::onDraw(VfxDrawContext &dc)
{
    VfxU32 flags = 0;
    VfxS32 border_width = 0;
    VfxRect bounds;
    vrt_size_struct image_size;
    VfxU32 i = 0, j = 0;
    VfxU32 texture_x_times = 0, texture_y_times = 0;

    bounds = getBounds();
    if (m_filler == NULL)
    {
        return;
    }

    flags = m_filler->flags;

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    /* set border property of rectangle frame */
    /* At present, we only support no border, single border & double border */
    if (flags & VFRM_FILLED_AREA_BORDER)
    {
        setBorderColor(VfxColor(
                     VFX_RECT_CONVERT_ALPHA(m_filler->border_color.alpha),
                     m_filler->border_color.r,
                     m_filler->border_color.g,
                     m_filler->border_color.b));


        if ((flags & VFRM_FILLED_AREA_MASK_BORDER_WIDTH) == VFRM_FILLED_AREA_SINGLE_BORDER)
        {
            setBorderWidth(
                (VfxS32)VFX_RECT_FRAME_FILLED_AREA_SINGLE_BORDER_WIDTH);
        }
        else if ((flags & VFRM_FILLED_AREA_MASK_BORDER_WIDTH) == VFRM_FILLED_AREA_DOUBLE_BORDER)
        {
            setBorderWidth(
                (VfxS32)VFX_RECT_FRAME_FILLED_AREA_DOUBLE_BORDER_WIDTH);
        }
    }
    else if (flags & VFRM_FILLED_AREA_TYPE_NO_BORDER)
    {
        setBorderWidth((VfxS32)VFX_RECT_FRAME_FILLED_AREA_NO_BORDER_WIDTH);
    }

    /* Dispaly filler of UI filled area */
    switch (flags & VFRM_FILLED_AREA_MASK_TYPE)
    {
        case VFRM_FILLED_AREA_TYPE_TEXTURE:
            {
                if (m_filler->b != NULL)
                {
                    border_width = getBorderWidth();

                    if (bounds.getWidth() < 2 * border_width || bounds.getHeight() < 2 * border_width)
                    {
                        break;
                    }

                    image_size = vrt_sys_image_get_size_from_mem(m_filler->b);
                    if (image_size.width > (bounds.getWidth() - 2 * border_width) &&
                        image_size.height > (bounds.getHeight() - 2 * border_width))
                    {
                        dc.drawImageFromMem(border_width, border_width, m_filler->b);
                    }
                    else
                    {
                        texture_x_times = (bounds.getWidth() - 2 * border_width) / image_size.width + 1;
                        texture_y_times = (bounds.getHeight() - 2 * border_width) / image_size.height + 1;
                        for (i = 1; i <= texture_y_times; i++)
                        {
                            for (j = 1; j <= texture_x_times; j++)
                            {
                                dc.drawImageFromMem(
                                    border_width + image_size.width * (j - 1),
                                    border_width + image_size.width * (i - 1),
                                    m_filler->b);
                            }
                        }
                    }
                }
            }
            break;

        case VFRM_FILLED_AREA_TYPE_BITMAP:
            {
                if (m_filler->b != NULL)
                {
                    dc.drawImageFromMem(0, 0, m_filler->b);
                }                 
            }
            break;

        case VFRM_FILLED_AREA_TYPE_IMAGE_LEFT_ALIGN:
             {
                 if (m_filler->b != NULL)
                 {
                     dc.drawImageFromMem(0, 0, m_filler->b);
                 }
             }
             break;

        case VFRM_FILLED_AREA_TYPE_IMAGE_RIGHT_ALIGN:
            {
                 if (m_filler->b != NULL)
                 {
                     image_size = vrt_sys_image_get_size_from_mem(m_filler->b);
                     dc.drawImageFromMem(bounds.getWidth() - image_size.width, 0, m_filler->b);
                 }
             }
             break;

        case VFRM_FILLED_AREA_TYPE_COLOR:
        default:
             {
                 setBgColor(VfxColor(
                              VFX_RECT_CONVERT_ALPHA(m_filler->c.alpha),
                              m_filler->c.r,
                              m_filler->c.g,
                              m_filler->c.b));
             }
             break;
    }
    VfxAutoAnimate::commit();
}




