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
 *  vcp_matrix_item.h
 *
 * Project:
 * --------
 *  Venus UI Component
 *
 * Description:
 * ------------
 *  Basic class to handle matrix items
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
#ifndef __VCP_MATRIX_ICON_H__
#define __VCP_MATRIX_ICON_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"

#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_text_frame.h"
#include "vfx_primitive_frame.h"
#include "vfx_string.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MEDIUM_FONT_SIZE 0x0E
#define SMALL_FONT_SIZE  0x0C

/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/*****************************************************************************
 * Class Matrix item
 *****************************************************************************/

/*
 * VcpSimpleMatrixIcon is a class which provided basic operation of matrix item.
 *
 * EXAMPLE
 * <code>
 *  VFRM_OBJ_CREATE(m_imageFrames, VcpSimpleMatrixIcon, NULL);
 * </code>
 */
class VcpSimpleMatrixIcon : public VfxControl
{
// Typedef
public:
    enum
    {
#if defined(__MMI_MAINLCD_240X400__)
        // Widh of text in highlight.
        MATRIX_ICON_HIGHLIGHT_TEXT_WIDTH = 78,
    #ifdef __MMI_VECTOR_FONT_SUPPORT__
        // Y postion of highlight icon. 
        MATRIX_ICON_HIGHLIGHT_Y = 45,
        // X postion of highlight icon.
        MATRIX_ICON_HIGHLIGHT_X = 40,
        // Height of text.
        MATRIX_ICON_TEXT_HEIGHT = 17,
        // Y position of icon.
        MATRIX_ICON_Y = 7 
    #else /* __MMI_VECTOR_FONT_SUPPORT__ */
        // Y postion of highlight icon. 
        MATRIX_ICON_HIGHLIGHT_Y = 40,
        // X postion of highlight icon.
        MATRIX_ICON_HIGHLIGHT_X = 45,
        // Height of text.
        MATRIX_ICON_TEXT_HEIGHT = 22,
        // Y position of icon.
        MATRIX_ICON_Y = 10 
    #endif /* __MMI_VECTOR_FONT_SUPPORT__ */
#elif defined(__MMI_FTE_SUPPORT__)
		
#if defined(__MMI_MAINLCD_240X320__)
        // Widh of text in highlight.
        MATRIX_ICON_HIGHLIGHT_TEXT_WIDTH = 66,
#elif defined(__MMI_MAINLCD_320X480__)
        // Widh of text in highlight.
        MATRIX_ICON_HIGHLIGHT_TEXT_WIDTH = 100,
#else
        // Widh of text in highlight.
        MATRIX_ICON_HIGHLIGHT_TEXT_WIDTH = 64,
#endif
    #ifdef __MMI_VECTOR_FONT_SUPPORT__
#if defined(__MMI_MAINLCD_320X480__)
        // Y postion of highlight icon.
        MATRIX_ICON_HIGHLIGHT_Y = 60,
#elif defined(__MMI_MAINLCD_240X320__)
        // Y postion of highlight icon.
        MATRIX_ICON_HIGHLIGHT_Y = 16,
#else /* defined(__MMI_MAINLCD_240X320__) */
        // Y postion of highlight icon.
        MATRIX_ICON_HIGHLIGHT_Y = 25,
#endif /* defined(__MMI_MAINLCD_240X320__) */
        // X postion of highlight icon. 
        MATRIX_ICON_HIGHLIGHT_X = 20,
#if defined(__MMI_MAINLCD_240X320__)
        // Height of text.
        MATRIX_ICON_TEXT_HEIGHT = 16,
#else
        // Height of text.
        MATRIX_ICON_TEXT_HEIGHT = 18,
#endif
        // Y position of icon.
        MATRIX_ICON_Y = 0 
    #else
#if defined(__MMI_MAINLCD_320X480__)
        // Y postion of highlight icon.
        MATRIX_ICON_HIGHLIGHT_Y = 62,
        // Height of text.
        MATRIX_ICON_TEXT_HEIGHT = 24,
#else
        // Y postion of highlight icon.
        MATRIX_ICON_HIGHLIGHT_Y = 25,
        // Height of text.
        MATRIX_ICON_TEXT_HEIGHT = 17,
#endif
        // X postion of highlight icon. 
        MATRIX_ICON_HIGHLIGHT_X = 20,
        // Y position of icon.
        MATRIX_ICON_Y = 0 
    #endif
#else /* __MMI_MAINLCD_240X400__ */
		
#if defined(__MMI_MAINLCD_320X480__)
        // Widh of text in highlight.
        MATRIX_ICON_HIGHLIGHT_TEXT_WIDTH = 100,
        // X postion of highlight icon. 
        MATRIX_ICON_HIGHLIGHT_X = 20,
#ifdef __MMI_VECTOR_FONT_SUPPORT__
        // Y postion of highlight icon.
        MATRIX_ICON_HIGHLIGHT_Y = 60,
        // Height of text.
        MATRIX_ICON_TEXT_HEIGHT = 18,
#else		
        // Y postion of highlight icon.
        MATRIX_ICON_HIGHLIGHT_Y = 62,
        // Height of text.
        MATRIX_ICON_TEXT_HEIGHT = 24,
#endif
        // Y position of icon.
        MATRIX_ICON_Y = 0 
#else
#if defined(__MMI_MAINLCD_240X320__)
        // Widh of text in highlight.
        MATRIX_ICON_HIGHLIGHT_TEXT_WIDTH = 66,

#else
        // Widh of text in highlight.
        MATRIX_ICON_HIGHLIGHT_TEXT_WIDTH = 64,
#endif
    #ifdef __MMI_VECTOR_FONT_SUPPORT__
        // Y postion of highlight icon.
        MATRIX_ICON_HIGHLIGHT_Y = 25,
        // X postion of highlight icon. 
        MATRIX_ICON_HIGHLIGHT_X = 20,
        // Height of text.
        MATRIX_ICON_TEXT_HEIGHT = 14,
        // Y position of icon.
        MATRIX_ICON_Y = 0 
    #else /* __MMI_VECTOR_FONT_SUPPORT__ */
        // Y postion of highlight icon.
        MATRIX_ICON_HIGHLIGHT_Y = 25,
        // X postion of highlight icon. 
        MATRIX_ICON_HIGHLIGHT_X = 20,
        // Height of text.
        MATRIX_ICON_TEXT_HEIGHT = 18,
        // Y position of icon.
        MATRIX_ICON_Y = 0 
    #endif /* __MMI_VECTOR_FONT_SUPPORT__ */
#endif /* __MMI_MAINLCD_240X400__ */
#endif
    };

//variable
public:
    // The number of row.
    VfxU32                  m_nRow;
    // The number of column.
    VfxU32                  m_nColumn;
    // This item is in highlight mode or not.
    VfxBool                 m_isHighlighted;
    // X position.
    VfxS32                  m_x;
    // Y position.
    VfxS32                  m_y;

//Child objects
public:
    // Text in this item.
    VfxTextFrame     *m_text;
    // Image in thie item.
    VfxImageFrame    *m_image;
    

// Constructor / Destructor
public:
    // Default constructor.
    VcpSimpleMatrixIcon();  
    // Update the string of m_text.
    void updateString(const VfxWString &text);

// Override
protected:
    // Init function.
    virtual void onInit();
    // Deinit function.
    virtual void onDeinit();

// Method    
protected:
    void onBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds);
};


#endif /* __VCP_MATRIX_ICON_H__ */
