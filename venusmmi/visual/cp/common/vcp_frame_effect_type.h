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
 *  vcp_page.h
 *
 * Project:
 * --------
 *  Venus UI Component
 *
 * Description:
 * ------------
 *  Venus Cube Component
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
#ifndef __VCP_FRAME_EFFECT_TYPE_H__
#define __VCP_FRAME_EFFECT_TYPE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vfx_transform.h"
#include "vfx_basic_type.h"

#include "vfx_frame.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// The type can be chosen for frame effect
enum VcpEffectType
{
    VCP_EFFECT_NONE,
    VCP_EFFECT_FADE_IN,
    VCP_EFFECT_FADE_OUT,
    VCP_EFFECT_FADE_OUT_WAVE,
    VCP_EFFECT_FLIP,
    VCP_EFFECT_PHOTOWALL,
    VCP_EFFECT_POPUP,
    VCP_EFFECT_MORPH_FADE_IN,
    VCP_EFFECT_FLY_OUT,
    VCP_EFFECT_RECTANGLE_ROTATE_OUT,
    VCP_EFFECT_SMALL_FLIP,
    VCP_EFFECT_TRANSFORMER,
    VCP_EFFECT_TVCLOSE,
    VCP_EFFECT_3D_CIRCLE,
    VCP_EFFECT_TITLE_BAR_LIGHT,
    VCP_EFFECT_3D_BLING,
    VCP_EFFECT_3D_BLUR,
    VCP_EFFECT_END
};

// The direction of frame effect, note some effect may not support all direction.
// But it will show default direction.
enum VcpEffectTypeDirection
{
    VCP_EFFECT_DIRECTION_FROM_NONE,
    VCP_EFFECT_DIRECTION_FROM_RIGHT,
    VCP_EFFECT_DIRECTION_FROM_LEFT,
    VCP_EFFECT_DIRECTION_FROM_UP,
    VCP_EFFECT_DIRECTION_FROM_BOTTOM
};


class VcpFlipPara : public VfxBase
{
public:
    VfxS32 frameWidth;
    VfxS32 frameHeight;
    VfxMatrix4x4 relativeMatrix;
    VfxS32 direction;
    VfxFloat cameraDistance;
    VfxFloat angle;
    VfxBool isReverse;
    VfxBool isVertical;
};

// The input parameter for VCP_EFFECT_FLIP and VCP_EFFECT_SMALL_FLIP
struct VcpEffectFilpData
{
    VfxFloat cameraDistance;    // Camera distance affect degree of perspective
    VfxBool  isBackCulling;     // isBackCulling = False, you can see the back side of frame
};

// The input parameter for VCP_EFFECT_PHOTOWALL
struct VcpEffectPhotoWallData
{
    VfxFloat cameraDistance;    // Camera distance affect degree of perspective
    VfxFloat angle;             // rotation angle
};

// the input parameter for VCP_EFFECT_MORPH_FADE_IN
struct VcpEffectMorphFadeInData
{
    VfxRect fromRect;           // the Rect come from
};

struct Vcp3DEffectBlingData
{
    VfxFloat width;
    VfxFloat sheer;
    VfxS32 repeat;
    VfxFloat bright;
};

struct Vcp3DEffectBlurData
{
   VfxFrame* background;
   VfxFloat darkness;
   VfxFloat from;
   VfxBool isFrameTexture;
};
#endif /* __VCP_FRAME_EFFECT_TYPE_H__ */
