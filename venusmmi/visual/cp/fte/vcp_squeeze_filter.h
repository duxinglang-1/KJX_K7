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
 *  vcp_squeeze_filter.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Venus Main Menu Squeeze Effect Header File
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCP_SQUEEZE_FILTER_H__
#define __VCP_SQUEEZE_FILTER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_frame_filter.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_image_src.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VCP_SQUEEZE_FILTER_SQUEEZE_DEFAUL_COEFFICIENT 0.7

typedef enum
{
    VCP_SQUEEZE_FILTER_TRANSITION_DIRECTION_UPWARD,
    VCP_SQUEEZE_FILTER_TRANSITION_DIRECTION_DOWNWARD,
    VCP_SQUEEZE_FILTER_TRANSITION_DIRECTION_LEFTWARD,
    VCP_SQUEEZE_FILTER_TRANSITION_DIRECTION_RIGHTWARD,
    VCP_SQUEEZE_FILTER_TRANSITION_DIRECTION_END_OF_ENUM
} vcp_squeeze_filter_transition_direction_enum;


/***************************************************************************** 
 * Class VcpSqueezeFilter
 *****************************************************************************/
/*
 *  VcpSqueezeFilter provide a switch item effect in main menu screen. App user 
 *  can set the squeeze parameters in x axis or y axis. The 
 *  VcpSqueezeFilter will warp image by the squeeze parameters.
 */
class VcpSqueezeFilter : public VfxFrameFilter
{
// Constructor / Destructor
public:
    // <group DOM_SqueezeFilter_VcpSqueezeFilter_Constructor/Destructor>
    VcpSqueezeFilter();
// Variable
public:
    // <group DOM_SqueezeFilter_VcpSqueezeFilter_Variable>
    // Specify transition direction
    VfxS32   m_transitionDirection;
    // <group DOM_SqueezeFilter_VcpSqueezeFilter_Variable>
    // Specify transition Coefficient. If the value is big, the warp result will be obvious.
    VfxFloat m_squeezeCoefficient;
    // <group DOM_SqueezeFilter_VcpSqueezeFilter_Variable>
    // The input image width
    VfxS32   m_imageWidth;
    // <group DOM_SqueezeFilter_VcpSqueezeFilter_Variable>
    // The input image height
    VfxS32   m_imageHeight;
    // <group DOM_SqueezeFilter_VcpSqueezeFilter_Variable>
    //  Squeeze algorthim use a warp radius. It will affect the area being warped.
    VfxS32   m_warpRadius;
    // <group DOM_SqueezeFilter_VcpSqueezeFilter_Variable>
    //  Squeeze anchor point in x axis. the anchor point is warp center point
    VfxS32   m_anchorX;
    // <group DOM_SqueezeFilter_VcpSqueezeFilter_Variable>
    //  Squeeze anchor point in y axis. the anchor point is warp center point
    VfxS32   m_anchorY;
    // <group DOM_SqueezeFilter_VcpSqueezeFilter_Variable>
    //  Specify the travel length from one item to another.
    VfxS32   m_travelLength; 

    // <group DOM_SqueezeFilter_VcpSqueezeFilter_Variable>
    //  Specify the left margin of image.
    VfxS32   m_leftMargin;   
    // <group DOM_SqueezeFilter_VcpSqueezeFilter_Variable>
    //  Specify the right margin of image.
    VfxS32   m_rightMargin;
    // <group DOM_SqueezeFilter_VcpSqueezeFilter_Variable>
    //  Specify the top margin of image.
    VfxS32   m_topMargin;  
    // <group DOM_SqueezeFilter_VcpSqueezeFilter_Variable>
    //  Specify the bottom margin of image.
    VfxS32   m_bottomMargin;

// Override
protected:
    // <group DOM_SqueezeFilter_VcpSqueezeFilter_Override>
    virtual BufferModeEnum onGetBufferMode() const
    {
        return BUFFER_MODE_OUT_OF_PLACE;
    }
    // <group DOM_SqueezeFilter_VcpSqueezeFilter_Override>
    virtual VfxBool onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat level);

// Implementation
protected:
    // <group DOM_SqueezeFilter_VcpSqueezeFilter_Implementation>
    VfxBool squeezeInX(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat level, VfxS32 squeeze_point);
    // <group DOM_SqueezeFilter_VcpSqueezeFilter_Implementation>
    VfxBool squeezeInY(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat level, VfxS32 squeeze_point);
};

#endif /* __VCP_SQUEEZE_FILTER_H__*/

