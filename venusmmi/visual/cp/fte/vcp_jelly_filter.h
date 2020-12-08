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
 *  vcp_jelly_filter.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Venus Main Menu Jelly Effect Header File
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
#ifndef __VCP_JELLY_FILTER_H__
#define __VCP_JELLY_FILTER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vfx_frame_filter.h"
#include "vfx_image_src.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VCP_JELLY_FILTER_SQUEEZE_DEFAUL_COEFFICIENT 0.7
#define VCP_JELLY_FILTER_NULL_VALUE 0x0FFFFFFF
#define VCP_JELLY_FILTER_CONTINUED_SQUEEZE 0x00FFFFFF
#define VCP_JELLY_FILTER_NULL_LEVEL ((VfxFloat) 2.0)

typedef enum
{
    VCP_JELLY_FILTER_TRANSITION_DIRECTION_UPWARD,
    VCP_JELLY_FILTER_TRANSITION_DIRECTION_DOWNWARD,
    VCP_JELLY_FILTER_TRANSITION_DIRECTION_LEFTWARD,
    VCP_JELLY_FILTER_TRANSITION_DIRECTION_RIGHTWARD,
    VCP_JELLY_FILTER_TRANSITION_DIRECTION_END_OF_ENUM
} vcp_jelly_filter_transition_direction_enum;


typedef enum
{
    VCP_JELLY_FILTER_FUNCTYPE_TYPE_SQUEEZE_IN_X,
    VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X,
    VCP_JELLY_FILTER_FUNCTYPE_TYPE_SQUEEZE_IN_Y,
    VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_Y,
    VCP_JELLY_FILTER_FUNCTYPE_TYPE_END_OF_ENUM
} vcp_jelly_filter_function_type_enum;

typedef VfxBool (*vcp_jelly_filter_func_p)(VfxFloat, VfxS32, VfxS32);

typedef struct
{
    VfxS32 funcType;
    VfxS32 squeezePoint;
    VfxS32 squeezePoint2;
    VfxS32 anchor;
    VfxFloat squeezeCoefficient;
    VfxFloat startLevel;
    VfxFloat endLevel;
} vcp_jelly_filter_key_frame_setting_struct;


/***************************************************************************** 
 * Class VcpJellyFilter
 *****************************************************************************/
 /*
 *  VcpJellyFilter provide a switch item effect in main menu screen. App user 
 *  can set several key frame which is squeezed by x axis or y axis. The 
 *  VcpJellyFilter will warp image by the squeeze parameter and do the 
 *  interpolation of key frame.
 */
class VcpJellyFilter : public VfxFrameFilter
{
// Constructor / Destructor
public:
    // <group DOM_JellFilter_VcpJellyFilter_Constructor/Destructor>
    VcpJellyFilter();
// Variable
public:
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    // Specify transitionDirection
    VfxS32  m_transitionDirection;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    // The input image width
    VfxS32  m_imageWidth;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    // The input image height
    VfxS32  m_imageHeight;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    //  Squeeze algorthim use a warp radius. It will affect the area being warped.
    VfxS32  m_warpRadius;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    //  Specify the key frame by its format
    const vcp_jelly_filter_key_frame_setting_struct *m_keyFrameSettingArray;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    //  Specify the key frame count
    VfxU32  m_keyFrameCount;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    //  Specify the left margin of image.
    VfxS32  m_leftMargin;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    //  Specify the right margin of image.
    VfxS32  m_rightMargin;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    //  Specify the top margin of image.
    VfxS32  m_topMargin;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    //  Specify the bottom margin of image.
    VfxS32  m_bottomMargin;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    //  Specify the travel length from one item to another.
    VfxS32  m_travelLength;

// Variable
protected:
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    VfxU8   *m_inBufP;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    VfxU8   *m_outBufP;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    VfxS32  m_inBufWidth;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    VfxS32  m_inBufHeight;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    VfxS32  m_squeezePoint;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    VfxS32  m_squeezePoint_2;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    VfxS32  m_anchor;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    VfxFloat  m_squeezeCoefficient;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    VfxS32  m_leftBoundary;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    VfxS32  m_rightBoundary;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    VfxS32  m_topBoundary;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    VfxS32  m_bottomBoundary;   
    
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    VfxS32  m_leftNewBoundary;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    VfxS32  m_rightNewBoundary;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    VfxS32  m_topNewBoundary;
    // <group DOM_JellFilter_VcpJellyFilter_Variable>
    VfxS32  m_bottomNewBoundary;
    
// Override
protected:
    // <group DOM_JellFilter_VcpJellyFilter_Override>
    virtual BufferModeEnum onGetBufferMode() const
    {
        return BUFFER_MODE_OUT_OF_PLACE_AND_POLLUTE_INPUT;
    }
    // <group DOM_JellFilter_VcpJellyFilter_Override>
    virtual VfxBool onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat level);

// Implementation
protected:
    // <group DOM_JellFilter_VcpJellyFilter_Implementation>
    VfxBool effectSelector(VfxS32 effectType, VfxFloat level);
    // <group DOM_JellFilter_VcpJellyFilter_Implementation>
    VfxBool twoSqueezeInX(VfxFloat level);
    // <group DOM_JellFilter_VcpJellyFilter_Implementation>
    VfxBool squeezeInX   (VfxFloat level);
    // <group DOM_JellFilter_VcpJellyFilter_Implementation>
    VfxBool twoSqueezeInY(VfxFloat level);
    // <group DOM_JellFilter_VcpJellyFilter_Implementation>
    VfxBool squeezeInY   (VfxFloat level);
    // <group DOM_JellFilter_VcpJellyFilter_Implementation>
    void resetBoundary(VfxImageBuffer &inBuf);
};

#endif /* __VCP_JELLY_FILTER_H__*/

