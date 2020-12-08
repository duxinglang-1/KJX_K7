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
 *  vfx_transform.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
 
#include "vfx_transform.h"

#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_basic_type.h"
#include <string.h>


/***************************************************************************** 
 * VfxMatrix3x3Ex
 *****************************************************************************/

VfxMatrix3x3Ex::VfxMatrix3x3Ex()
{
    setIdentity();
}


VfxMatrix3x3Ex::VfxMatrix3x3Ex(
    VfxFloat _mat0, 
    VfxFloat _mat1, 
    VfxFloat _mat2, 
    VfxFloat _mat3,
    VfxFloat _mat4, 
    VfxFloat _mat5, 
    VfxFloat _mat6, 
    VfxFloat _mat7,
    VfxFloat _mat8)
{
    m[0] = _mat0;
    m[1] = _mat1;
    m[2] = _mat2;
    m[3] = _mat3;
    m[4] = _mat4;
    m[5] = _mat5;
    m[6] = _mat6;
    m[7] = _mat7;
    m[8] = _mat8;
}


VfxMatrix3x3Ex::VfxMatrix3x3Ex(const VfxFloat* input)
{
    memcpy(&m, input, sizeof(VfxFloat) * 9);
}


VfxMatrix3x3Ex::VfxMatrix3x3Ex(const VfxMatrix3x3Ex &other)
{
    memcpy(&m, &other.m, sizeof(VfxFloat) * 9);
}


VfxMatrix3x3Ex::VfxMatrix3x3Ex(const VfxMatrix3x3 &other)
{
    memcpy(&m, &other.m, sizeof(VfxFloat) * 9);
}


VfxMatrix3x3Ex &VfxMatrix3x3Ex::operator =(const VfxMatrix3x3Ex &other)
{
    memcpy(&m, &other.m, sizeof(VfxFloat) * 9);
    return *this;
}


VfxMatrix3x3Ex &VfxMatrix3x3Ex::operator *=(const VfxMatrix3x3Ex &other)
{
    VfxFloat temp[9];
    temp[0] = m[0] * other.m[0] + m[3] * other.m[1] + m[6] * other.m[2];
    temp[3] = m[0] * other.m[3] + m[3] * other.m[4] + m[6] * other.m[5];
    temp[6] = m[0] * other.m[6] + m[3] * other.m[7] + m[6] * other.m[8];

    temp[1] = m[1] * other.m[0] + m[4] * other.m[1] + m[7] * other.m[2];
    temp[4] = m[1] * other.m[3] + m[4] * other.m[4] + m[7] * other.m[5];
    temp[7] = m[1] * other.m[6] + m[4] * other.m[7] + m[7] * other.m[8];

    temp[2] = m[2] * other.m[0] + m[5] * other.m[1] + m[8] * other.m[2];
    temp[5] = m[2] * other.m[3] + m[5] * other.m[4] + m[8] * other.m[5];
    temp[8] = m[2] * other.m[6] + m[5] * other.m[7] + m[8] * other.m[8];

    memcpy(&m, temp, sizeof(VfxFloat) * 9);
    return *this;
}


VfxMatrix3x3Ex VfxMatrix3x3Ex::operator *(const VfxMatrix3x3Ex &other)
{
    VfxMatrix3x3Ex result;
    result.m[0] = m[0] * other.m[0] + m[3] * other.m[1] + m[6] * other.m[2];
    result.m[3] = m[0] * other.m[3] + m[3] * other.m[4] + m[6] * other.m[5];
    result.m[6] = m[0] * other.m[6] + m[3] * other.m[7] + m[6] * other.m[8];

    result.m[1] = m[1] * other.m[0] + m[4] * other.m[1] + m[7] * other.m[2];
    result.m[4] = m[1] * other.m[3] + m[4] * other.m[4] + m[7] * other.m[5];
    result.m[7] = m[1] * other.m[6] + m[4] * other.m[7] + m[7] * other.m[8];

    result.m[2] = m[2] * other.m[0] + m[5] * other.m[1] + m[8] * other.m[2];
    result.m[5] = m[2] * other.m[3] + m[5] * other.m[4] + m[8] * other.m[5];
    result.m[8] = m[2] * other.m[6] + m[5] * other.m[7] + m[8] * other.m[8];
    
    return result;
}


void VfxMatrix3x3Ex::setIdentity(void)
{
    m[0] = 1;
    m[1] = 0;
    m[2] = 0;
    m[3] = 0;
    m[4] = 1;
    m[5] = 0;
    m[6] = 0;
    m[7] = 0;
    m[8] = 1;
}


void VfxMatrix3x3Ex::setScale(float sx, float sy)
{
    setIdentity();
    m[0] = sx;
    m[4] = sy;
}


void VfxMatrix3x3Ex::setTranslation(float tx, float ty)
{
    setIdentity();
    m[6] = tx;
    m[7] = ty;
}


void VfxMatrix3x3Ex::setRotateByZ(float rad)
{
    setIdentity();
    m[0] = m[4] = vfxCos(rad);
    m[1] = vfxSin(rad);
    m[3] = -1 * m[1];
}


void VfxMatrix3x3Ex::setAffine(const VfxAffineParameter &affine)
{
    setIdentity();

    /* rotate */
    if (affine.rz != 0)
    {
        m[0] = m[4] = vfxCos(affine.rz);
        m[1] = vfxSin(affine.rz);
        m[3] = -m[1];
    }
    else
    {
        m[0] = m[4] = 1;
        m[1] = m[3] = 0;
    }

    /* scale */
    m[0] *= affine.sx;
    m[1] *= affine.sx;
    m[3] *= affine.sy;
    m[4] *= affine.sy;

    /* translate */
    m[6] = affine.tx;
    m[7] = affine.ty;
}


void VfxMatrix3x3Ex::initMatrix3x3(VfxMatrix3x3 &out) const
{
    out.m[0] = m[0];
    out.m[1] = m[1];
    out.m[2] = m[2];
    out.m[3] = m[3];
    out.m[4] = m[4];
    out.m[5] = m[5];
    out.m[6] = m[6];
    out.m[7] = m[7];
    out.m[8] = m[8];
}


void VfxMatrix3x3Ex::inverse()
{
    VfxFloat   a, b, c, d, e, f, g, h, i;
    VfxFloat   det, inv_det;
    VfxFloat   m0, m3, m6;

    a = m[0];
    b = m[3];
    c = m[6];
    d = m[1];
    e = m[4];
    f = m[7];
    g = m[2];
    h = m[5];
    i = m[8];

    m0 = e * i - h * f;
    m3 = h * c - b * i;
    m6 = b * f - e * c;

    det = a * m0;
    det += d * m3;
    det += g * m6;

    /* prevent divided by zero */
    // TODO: should assert
    if (!det)
    {
        det = 1;        
    }

    inv_det = 1 / det;

    m[0] = inv_det * m0;
    m[3] = inv_det * m3;
    m[6] = inv_det * m6;
    
    m[1] = inv_det * (g * f - d * i);
    m[2] = inv_det * (d * h - g * e);

    m[4] = inv_det * (a * i - c * g);
    m[5] = inv_det * (g * b - a * h);

    m[7] = inv_det * (d * c - a * f);
    m[8] = inv_det * (a * e - b * d);
}


void VfxMatrix3x3Ex::transpose()
{
    vfxSwap(m[1], m[3]);
    vfxSwap(m[2], m[6]);
    vfxSwap(m[5], m[7]);
}


VfxPoint VfxMatrix3x3Ex::transform(const VfxPoint &in)
{
    VfxFloat tx = m[0] * in.x + m[3] * in.y + m[6];
    VfxFloat ty = m[1] * in.x + m[4] * in.y + m[7];
    VfxFloat tz = m[2] * in.x + m[5] * in.y + m[8];

    return VfxPoint(
        (VfxS32)(tx / tz), 
        (VfxS32)(ty / tz));
}


/***************************************************************************** 
 * VfxMatrix4x4
 *****************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm
#endif

VfxMatrix4x4::VfxMatrix4x4()
{
    m[0] = 1;
    m[1] = 0;
    m[2] = 0;
    m[3] = 0;
    m[4] = 0;
    m[5] = 1;
    m[6] = 0;
    m[7] = 0;
    m[8] = 0;
    m[9] = 0;
    m[10] = 1;
    m[11] = 0;
    m[12] = 0;
    m[13] = 0;
    m[14] = 0;
    m[15] = 1;
}


VfxMatrix4x4::VfxMatrix4x4(
    VfxFloat _mat0, 
    VfxFloat _mat1, 
    VfxFloat _mat2, 
    VfxFloat _mat3,
    VfxFloat _mat4, 
    VfxFloat _mat5, 
    VfxFloat _mat6, 
    VfxFloat _mat7,
    VfxFloat _mat8, 
    VfxFloat _mat9, 
    VfxFloat _mat10, 
    VfxFloat _mat11,
    VfxFloat _mat12, 
    VfxFloat _mat13, 
    VfxFloat _mat14, 
    VfxFloat _mat15)
{
    m[0] = _mat0;
    m[1] = _mat1;
    m[2] = _mat2;
    m[3] = _mat3;
    m[4] = _mat4;
    m[5] = _mat5;
    m[6] = _mat6;
    m[7] = _mat7;
    m[8] = _mat8;
    m[9] = _mat9;
    m[10] = _mat10;
    m[11] = _mat11;
    m[12] = _mat12;
    m[13] = _mat13;
    m[14] = _mat14;
    m[15] = _mat15;
}


VfxMatrix4x4::VfxMatrix4x4(const VfxFloat* input)
{
    memcpy(&m, input, sizeof(VfxFloat)<<4);
}


VfxMatrix4x4::VfxMatrix4x4(const VfxMatrix4x4 &other)
{
    memcpy(&m, &other.m, sizeof(VfxFloat)<<4);
}


VfxMatrix4x4 &VfxMatrix4x4::operator =(const VfxMatrix4x4 &other)
{
    memcpy(&m, &other.m, sizeof(VfxFloat)<<4);
    return *this;
}


VfxMatrix4x4 &VfxMatrix4x4::operator *=(const VfxMatrix4x4 &other)
{
    VfxFloat temp[16];
    temp[0]  = m[0] * other.m[0]  + m[4] * other.m[1]  + m[8] * other.m[2]  + m[12] * other.m[3];
    temp[4]  = m[0] * other.m[4]  + m[4] * other.m[5]  + m[8] * other.m[6]  + m[12] * other.m[7];
    temp[8]  = m[0] * other.m[8]  + m[4] * other.m[9]  + m[8] * other.m[10] + m[12] * other.m[11];
    temp[12] = m[0] * other.m[12] + m[4] * other.m[13] + m[8] * other.m[14] + m[12] * other.m[15];

    temp[1]  = m[1] * other.m[0]  + m[5] * other.m[1]  + m[9] * other.m[2]  + m[13] * other.m[3];
    temp[5]  = m[1] * other.m[4]  + m[5] * other.m[5]  + m[9] * other.m[6]  + m[13] * other.m[7];
    temp[9]  = m[1] * other.m[8]  + m[5] * other.m[9]  + m[9] * other.m[10] + m[13] * other.m[11];
    temp[13] = m[1] * other.m[12] + m[5] * other.m[13] + m[9] * other.m[14] + m[13] * other.m[15];

    temp[2]  = m[2] * other.m[0]  + m[6] * other.m[1]  + m[10] * other.m[2]  + m[14] * other.m[3];
    temp[6]  = m[2] * other.m[4]  + m[6] * other.m[5]  + m[10] * other.m[6]  + m[14] * other.m[7];
    temp[10] = m[2] * other.m[8]  + m[6] * other.m[9]  + m[10] * other.m[10] + m[14] * other.m[11];
    temp[14] = m[2] * other.m[12] + m[6] * other.m[13] + m[10] * other.m[14] + m[14] * other.m[15];

    temp[3]  = m[3] * other.m[0]  + m[7] * other.m[1]  + m[11] * other.m[2]  + m[15] * other.m[3];
    temp[7]  = m[3] * other.m[4]  + m[7] * other.m[5]  + m[11] * other.m[6]  + m[15] * other.m[7];
    temp[11] = m[3] * other.m[8]  + m[7] * other.m[9]  + m[11] * other.m[10] + m[15] * other.m[11];
    temp[15] = m[3] * other.m[12] + m[7] * other.m[13] + m[11] * other.m[14] + m[15] * other.m[15];

    memcpy(&m, temp, sizeof(VfxFloat)<<4);
    return *this;
}


VfxMatrix4x4 VfxMatrix4x4::operator *(const VfxMatrix4x4 &other)
{
    VfxMatrix4x4 result;
    result.m[0]  = m[0] * other.m[0]  + m[4] * other.m[1]  + m[8] * other.m[2]  + m[12] * other.m[3];
    result.m[4]  = m[0] * other.m[4]  + m[4] * other.m[5]  + m[8] * other.m[6]  + m[12] * other.m[7];
    result.m[8]  = m[0] * other.m[8]  + m[4] * other.m[9]  + m[8] * other.m[10] + m[12] * other.m[11];
    result.m[12] = m[0] * other.m[12] + m[4] * other.m[13] + m[8] * other.m[14] + m[12] * other.m[15];

    result.m[1]  = m[1] * other.m[0]  + m[5] * other.m[1]  + m[9] * other.m[2]  + m[13] * other.m[3];
    result.m[5]  = m[1] * other.m[4]  + m[5] * other.m[5]  + m[9] * other.m[6]  + m[13] * other.m[7];
    result.m[9]  = m[1] * other.m[8]  + m[5] * other.m[9]  + m[9] * other.m[10] + m[13] * other.m[11];
    result.m[13] = m[1] * other.m[12] + m[5] * other.m[13] + m[9] * other.m[14] + m[13] * other.m[15];

    result.m[2]  = m[2] * other.m[0]  + m[6] * other.m[1]  + m[10] * other.m[2]  + m[14] * other.m[3];
    result.m[6]  = m[2] * other.m[4]  + m[6] * other.m[5]  + m[10] * other.m[6]  + m[14] * other.m[7];
    result.m[10] = m[2] * other.m[8]  + m[6] * other.m[9]  + m[10] * other.m[10] + m[14] * other.m[11];
    result.m[14] = m[2] * other.m[12] + m[6] * other.m[13] + m[10] * other.m[14] + m[14] * other.m[15];

    result.m[3]  = m[3] * other.m[0]  + m[7] * other.m[1]  + m[11] * other.m[2]  + m[15] * other.m[3];
    result.m[7]  = m[3] * other.m[4]  + m[7] * other.m[5]  + m[11] * other.m[6]  + m[15] * other.m[7];
    result.m[11] = m[3] * other.m[8]  + m[7] * other.m[9]  + m[11] * other.m[10] + m[15] * other.m[11];
    result.m[15] = m[3] * other.m[12] + m[7] * other.m[13] + m[11] * other.m[14] + m[15] * other.m[15];
    
    return result;
}


void VfxMatrix4x4::setIdentity(void)
{
    m[0] = 1;
    m[1] = 0;
    m[2] = 0;
    m[3] = 0;
    m[4] = 0;
    m[5] = 1;
    m[6] = 0;
    m[7] = 0;
    m[8] = 0;
    m[9] = 0;
    m[10] = 1;
    m[11] = 0;
    m[12] = 0;
    m[13] = 0;
    m[14] = 0;
    m[15] = 1;
}


void VfxMatrix4x4::setScale(float sx, float sy, float sz)
{
    setIdentity();
    m[0] = sx;
    m[5] = sy;
    m[10] = sz;
}


void VfxMatrix4x4::setTranslation(float tx, float ty, float tz)
{
    setIdentity();
    m[12] = tx;
    m[13] = ty;
    m[14] = tz;
}


void VfxMatrix4x4::setRotateByX(float rad)
{
    setIdentity();
    m[5] = m[10] = vfxCos(rad);
    m[6] = vfxSin(rad);
    m[9] = -1 * m[6];
}


void VfxMatrix4x4::setRotateByY(float rad)
{
    setIdentity();
    m[0] = m[10] = vfxCos(rad);
    m[8] = vfxSin(rad);
    m[2] = -1 * m[8];
}


void VfxMatrix4x4::setRotateByZ(float rad)
{
    setIdentity();
    m[0] = m[5] = vfxCos(rad);
    m[1] = vfxSin(rad);
    m[4] = -1 * m[1];
}


void VfxMatrix4x4::setCamera(
    VfxFloat scaleX,
    VfxFloat scaleY,
    VfxFloat translateX,
    VfxFloat translateY,
    VfxFloat nearPlane,
    VfxFloat cameraDistance,
    VfxFloat cameraUp,
    VfxFloat tile,
    VfxFloat pan)
{
    // set composite matrix by close form solution    
    m[0] = scaleX * vfxCos(VFX_DEG_TO_RAD(pan)) + (translateX * vfxCos(VFX_DEG_TO_RAD(tile))/nearPlane)* -1 * vfxSin(VFX_DEG_TO_RAD(pan));
    m[4] = translateX * vfxSin(VFX_DEG_TO_RAD(tile))/nearPlane ;
    m[8] = scaleX * vfxSin(VFX_DEG_TO_RAD(pan)) + (translateX * vfxCos(VFX_DEG_TO_RAD(tile))/nearPlane)* vfxCos(VFX_DEG_TO_RAD(pan));
    m[12] = translateX * cameraDistance / nearPlane;

    m[1] = (-1 * scaleY * vfxSin(VFX_DEG_TO_RAD(tile)) + translateY * vfxCos(VFX_DEG_TO_RAD(tile))/nearPlane) * -1 * vfxSin(VFX_DEG_TO_RAD(pan));
    m[5] = scaleY * vfxCos(VFX_DEG_TO_RAD(tile)) + translateY * vfxSin(VFX_DEG_TO_RAD(tile))/nearPlane;
    m[9] = (-1 * scaleY * vfxSin(VFX_DEG_TO_RAD(tile)) + translateY * vfxCos(VFX_DEG_TO_RAD(tile))/nearPlane) * vfxCos(VFX_DEG_TO_RAD(pan));
    m[13] = scaleY * cameraUp + translateY * cameraDistance / nearPlane;

    m[2] = vfxCos(VFX_DEG_TO_RAD(tile)) * -1 * vfxSin(VFX_DEG_TO_RAD(pan));
    m[6] = vfxSin(VFX_DEG_TO_RAD(tile));
    m[10] = vfxCos(VFX_DEG_TO_RAD(tile)) * vfxCos(VFX_DEG_TO_RAD(pan));
    m[14] = cameraDistance;

    m[3] = vfxCos(VFX_DEG_TO_RAD(tile))/nearPlane * -1 * vfxSin(VFX_DEG_TO_RAD(pan));
    m[7] = vfxSin(VFX_DEG_TO_RAD(tile))/nearPlane;
    m[11] = vfxCos(VFX_DEG_TO_RAD(tile))/nearPlane * vfxCos(VFX_DEG_TO_RAD(pan));
    m[15] = cameraDistance/nearPlane;
}


void VfxMatrix4x4::setCamera2(
    VfxFloat scaleX,
    VfxFloat scaleY,
    VfxFloat translateX,
    VfxFloat translateY,
    VfxFloat nearPlane,
    VfxFloat cameraDistance,
    VfxFloat cameraUp,
    VfxFloat cameraLeft,
    VfxFloat cameraTilt,
    VfxFloat cameraPan,
    VfxFloat camearRoll)
{
    VfxFloat cosT, sinT, cosP, sinP, cosR, sinR;
    cosT = vfxCos(VFX_DEG_TO_RAD(cameraTilt));
    sinT = vfxSin(VFX_DEG_TO_RAD(cameraTilt));
    cosP = vfxCos(VFX_DEG_TO_RAD(cameraPan));
    sinP = vfxSin(VFX_DEG_TO_RAD(cameraPan));
    cosR = vfxCos(VFX_DEG_TO_RAD(camearRoll));
    sinR = vfxSin(VFX_DEG_TO_RAD(camearRoll));

    VfxFloat G,H,I;
    G = cosR * cosT * sinP + sinT * sinR;
    H = sinR * cosT * sinP - sinT * cosR;
    I = cosT * cosP;
    // set composite matrix by close form solution    
    m[0] = scaleX * (cosP * cosR) + translateX/nearPlane * G;
    m[4] = scaleX * (cosP * sinR) + translateX/nearPlane * H;
    m[8] = scaleX * (-1.0f * sinP) + translateX/nearPlane * I;
    m[12]= scaleX * cameraLeft + translateX/nearPlane * cameraDistance;

    m[1] = scaleY * (cosR * sinT * sinP - cosT * sinR) + translateY/nearPlane * G;
    m[5] = scaleY * (sinR * sinT * sinP + cosT * cosR) + translateY/nearPlane * H;
    m[9] = scaleY * (cosP * sinT) + translateY/nearPlane * I;
    m[13]= scaleY * cameraUp + translateY/nearPlane * cameraDistance;

    m[2] = G;
    m[6] = H;
    m[10] = I;
    m[14] = cameraDistance;

    m[3]  =  G/nearPlane;
    m[7]  =  H/nearPlane;
    m[11] =  I/nearPlane;
    m[15] =  cameraDistance/nearPlane;
}



void VfxMatrix4x4::initMatrix3x3(VfxMatrix3x3 &out) const
{
    out.m[0] = m[0];
    out.m[3] = m[4];
    out.m[6] = m[12];
    out.m[1] = m[1];
    out.m[4] = m[5];
    out.m[7] = m[13];
    out.m[2] = m[3];
    out.m[5] = m[7];
    out.m[8] = m[15];
}


void VfxMatrix4x4::transpose()
{
    vfxSwap(m[1], m[4]);
    vfxSwap(m[2], m[8]);
    vfxSwap(m[3], m[12]);
    vfxSwap(m[6], m[9]);
    vfxSwap(m[7], m[13]);
    vfxSwap(m[11], m[14]);
}


#ifdef __MTK_TARGET__
#pragma thumb
#endif

/***************************************************************************** 
 * Class VfxTransform
 *****************************************************************************/

VfxTransform::VfxTransform(const vrt_transform_struct &other)
{
    type = other.type;
    
    switch (type)
    {
        case VRT_TRANSFORM_TYPE_IDENTITY:
            type = VFX_TRANSFORM_TYPE_AFFINE;   // affine or matrix3xe ???
            identity();
            break;

        case VFX_TRANSFORM_TYPE_AFFINE:
            memcpy(&data.affine, &other.data.affine, sizeof(VfxAffineParameter));
            break;
            
        case VFX_TRANSFORM_TYPE_MATRIX3X3:
            memcpy(&data.matrix3x3, &other.data.matrix3x3, sizeof(VfxMatrix3x3));
            break;

        default:
            VRT_ASSERT(0);
            break;
    }
}


#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
VfxTransform::VfxTransform(const vm_transform_struct &other)
{
    switch (other.type)
    {
        case VM_TRANSFORM_TYPE_IDENTITY:
            type = VRT_TRANSFORM_TYPE_AFFINE;   // affine or matrix3xe ???
            identity();
            break;

        case VM_TRANSFORM_TYPE_AFFINE:
            type = VRT_TRANSFORM_TYPE_AFFINE;
            memcpy(&data.affine, &other.data.affine, sizeof(VfxAffineParameter));
            break;
            
        case VM_TRANSFORM_TYPE_MATRIX3X3:
            type = VRT_TRANSFORM_TYPE_MATRIX3X3;
            memcpy(&data.matrix3x3, &other.data.matrix3x3, sizeof(VfxMatrix3x3));
            break;

        default:
            VRT_ASSERT(0);
            break;
    }
}


VfxTransform::operator vm_transform_struct() const
{
    vm_transform_struct ret;

    switch(type)
    {
    case VRT_TRANSFORM_TYPE_IDENTITY:
        ret.type = VM_TRANSFORM_TYPE_IDENTITY;
        memset(&ret, 0, sizeof(vm_transform_struct));
        break;
        
    case VRT_TRANSFORM_TYPE_AFFINE:
        ret.type = VM_TRANSFORM_TYPE_AFFINE;
        ret.data.affine.rz = data.affine.rz;
        ret.data.affine.sx = data.affine.sx;
        ret.data.affine.sy = data.affine.sy;
        ret.data.affine.tx = data.affine.tx;
        ret.data.affine.ty = data.affine.ty;
        break;

    case VRT_TRANSFORM_TYPE_MATRIX3X3:
        ret.type = VM_TRANSFORM_TYPE_MATRIX3X3;
        ret.data.matrix3x3.m[0] = data.matrix3x3.m[0];
        ret.data.matrix3x3.m[1] = data.matrix3x3.m[1];
        ret.data.matrix3x3.m[2] = data.matrix3x3.m[2];
        ret.data.matrix3x3.m[3] = data.matrix3x3.m[3];
        ret.data.matrix3x3.m[4] = data.matrix3x3.m[4];
        ret.data.matrix3x3.m[5] = data.matrix3x3.m[5];
        ret.data.matrix3x3.m[6] = data.matrix3x3.m[6];
        ret.data.matrix3x3.m[7] = data.matrix3x3.m[7];
        ret.data.matrix3x3.m[8] = data.matrix3x3.m[8];
        break;

    default:
        VRT_ASSERT(0);
        break;
    }

    return ret;
}
#endif


VfxBool VfxTransform::isIdentity() const
{

    if (type == VFX_TRANSFORM_TYPE_MATRIX3X3)
    {
        const vrt_float *m = data.matrix3x3.m;

        // TODO: should use float error threshold
        if (((m[0] == 1.0) && (m[1] == 0.0) && (m[2] == 0.0)) &&
            ((m[3] == 0.0) && (m[4] == 1.0) && (m[5] == 0.0)) &&
            ((m[6] == 0.0) && (m[7] == 0.0) && (m[8] == 1.0)))
        {
            return VFX_TRUE;    
        }
    }
    else if (type == VFX_TRANSFORM_TYPE_AFFINE)
    {
        const VfxAffineParameter *affine = &data.affine;

        // TODO: should use float error threshold
        if ((affine->sx == 1.0) &&
            (affine->sy == 1.0) &&
            (affine->tx == 0) &&
            (affine->ty == 0) &&
            (affine->rz == 0))
        {
            return VFX_TRUE;
        }
    }
    else
    {
        VFX_ASSERT(0);
    }

    return VFX_FALSE;
}


void VfxTransform::initVrtTransform(vrt_transform_struct &vrt_transform, VfxBool isAutoIdentity) const
{
    if (isAutoIdentity && isIdentity())
    {
        vrt_transform.type = VRT_TRANSFORM_TYPE_IDENTITY;
        return;
    }
    
    switch (type)
    {
        case VFX_TRANSFORM_TYPE_AFFINE:
            vrt_transform.type = VRT_TRANSFORM_TYPE_AFFINE;
            memcpy(&vrt_transform.data.affine, &data.affine, sizeof(VfxAffineParameter));
            break;
            
        case VFX_TRANSFORM_TYPE_MATRIX3X3:
            vrt_transform.type = VRT_TRANSFORM_TYPE_MATRIX3X3;
            memcpy(&vrt_transform.data.matrix3x3, &data.matrix3x3, sizeof(VfxMatrix3x3));
            break;

        default:
            VRT_ASSERT(0);
            break;
    }
}

void VfxTransform::transpose()
{
    switch (type)
    {
        case VFX_TRANSFORM_TYPE_MATRIX3X3:
            vfxSwap(data.matrix3x3.m[1], data.matrix3x3.m[3]);
            vfxSwap(data.matrix3x3.m[2], data.matrix3x3.m[6]);
            vfxSwap(data.matrix3x3.m[5], data.matrix3x3.m[7]);
            break;
    }
}


void VfxTransform::identity()
{
    switch (type)
    {
        case VFX_TRANSFORM_TYPE_AFFINE:
            data.affine.sx = 1.0f;
            data.affine.sy = 1.0f;
            data.affine.rz = 0.0f;
            data.affine.tx = 0.0f;
            data.affine.ty = 0.0f;
            break;
            
        case VFX_TRANSFORM_TYPE_MATRIX3X3:
            memset(&data.matrix3x3, 0, sizeof(VfxMatrix3x3));
            data.matrix3x3.m[0] = 1.0f;
            data.matrix3x3.m[4] = 1.0f;
            data.matrix3x3.m[8] = 1.0f;               
            break;

        default:
            VRT_ASSERT(0);
            break;
    }
}


void VfxTransform::assignWith(const VfxTransform &other)
{
    type = other.type;
    
    switch (type)
    {
        case VFX_TRANSFORM_TYPE_AFFINE:
            memcpy(&data.affine, &other.data.affine, sizeof(VfxAffineParameter));
            break;
            
        case VFX_TRANSFORM_TYPE_MATRIX3X3:
            memcpy(&data.matrix3x3, &other.data.matrix3x3, sizeof(VfxMatrix3x3));
            break;

        default:
            VRT_ASSERT(0);
            break;
    }
}


VfxBool VfxTransform::compareWith(const VfxTransform &other) const
{
    if (type != other.type)
    {
        return VFX_FALSE;
    }
    
    switch (type)
    {
        case VFX_TRANSFORM_TYPE_AFFINE:
            if (memcmp(
                &data.affine, 
                &other.data.affine, 
                sizeof(VfxAffineParameter)) == 0)
            {
                return VFX_TRUE;
            }
            break;
            
        case VFX_TRANSFORM_TYPE_MATRIX3X3:
            if (memcmp(
                &data.matrix3x3, 
                &other.data.matrix3x3, 
                sizeof(VfxMatrix3x3)) == 0)
            {
                return VFX_TRUE;
            }
            break;

        default:
            VRT_ASSERT(0);
            break;
    }

    return VFX_FALSE;
}

