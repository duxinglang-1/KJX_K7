/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vrt_quaternion.h
 *
 * Project:
 * --------
 *  Venus Rendering Task
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VRT_QUATERNION__
#define __VRT_QUATERNION__

#include "vrt_vector.h"
#include "vrt_matrix.h"




/*
 * VrtQuaternion
 */
template <typename T>
struct VrtQuaternion
{
    VrtQuaternion();

    VrtQuaternion(T _x, T _y, T _z, T _w);

    VrtQuaternion(const VrtVector3<T> &_v, T _w);

    VrtQuaternion & operator *= (const T v);

    VrtQuaternion & operator /= (const T v);

    VrtQuaternion & operator += (const VrtQuaternion &b);

    VrtQuaternion & operator -= (const VrtQuaternion &b);

    VrtQuaternion & operator *= (const VrtQuaternion &v);

   	VrtVector3<T> v;
    T w;
};

template <typename T>
vrt_bool operator == (const VrtQuaternion<T> &q, const VrtQuaternion<T> &r);

template <typename T>
vrt_bool operator != (const VrtQuaternion<T> &q, const VrtQuaternion<T> &r);

template <typename T>
VrtQuaternion<T> operator - (const VrtQuaternion<T> &q);

template <typename T>
VrtQuaternion<T> operator + (const VrtQuaternion<T> &q, const VrtQuaternion<T> &r);

template <typename T>
VrtQuaternion<T> operator - (const VrtQuaternion<T> &q, const VrtQuaternion<T> &r);

template <typename T, typename S>
VrtQuaternion<T> operator * (const VrtQuaternion<T> &q, S s);

template <typename T, typename S>
VrtQuaternion<T> operator / (const VrtQuaternion<T> &q, S s);

template <typename T, typename S>
VrtQuaternion<T> operator * (S s, const VrtQuaternion<T> &q);

template <typename T>
VrtQuaternion<T> operator * (const VrtQuaternion<T> &q, const VrtQuaternion<T> &r);

template <typename T>
T norm(const VrtQuaternion<T> & q);

template <typename T>
VrtQuaternion<T> normalize(const VrtQuaternion<T> & q);

template <typename T>
VrtQuaternion<T> conjugate(const VrtQuaternion<T> & q);

template <typename T>
VrtQuaternion<T> inverse(const VrtQuaternion<T> & q);

template <typename T>
VrtQuaternion<T> convert(const VrtMatrix4<T> &m);

template <typename T>
VrtMatrix4<T> convert(const VrtQuaternion<T> &q);

template <typename T>
VrtQuaternion<T> log(const VrtQuaternion<T> & q);

template <typename T>
VrtQuaternion<T> exp(const VrtQuaternion<T> & q);

template <typename T>
VrtQuaternion<T> lerp(const VrtQuaternion<T> &q, const VrtQuaternion<T> &r, vrt_float t);

template <typename T>
VrtQuaternion<T> slerp(const VrtQuaternion<T> &q, const VrtQuaternion<T> &r, vrt_float t);

template <typename T>
VrtQuaternion<T> squad(
    const VrtQuaternion<T> &q0,
    const VrtQuaternion<T> &q1,
    const VrtQuaternion<T> &q2,
    const VrtQuaternion<T> &q3,
    T t0,
    T t1,
    T t2,
    T t3,
    vrt_float t);


/*
 * Implementation
 */
template <typename T>
VrtQuaternion<T>::VrtQuaternion()
: v(0, 0, 0)
, w(1)
{
}

template <typename T>
VrtQuaternion<T>::VrtQuaternion(T _x, T _y, T _z, T _w)
: v(_x, _y, _z)
, w(_w)
{
}

template <typename T>
VrtQuaternion<T>::VrtQuaternion(const VrtVector3<T> &_v, T _w)
: v(_v)
, w(_w)
{
}

template <typename T>
VrtQuaternion<T> & VrtQuaternion<T>::operator *= (const T s)
{
    v *= s;
    w *= s;    
    return *this;
}

template <typename T>
VrtQuaternion<T> & VrtQuaternion<T>::operator /= (const T s)
{
    return (*this) *= (1.0f / s);
}

template <typename T>
VrtQuaternion<T> & VrtQuaternion<T>::operator += (const VrtQuaternion<T> &q)
{
    v += q.v;
    w += q.w;
    return *this;
}


template <typename T>
VrtQuaternion<T> & VrtQuaternion<T>::operator -= (const VrtQuaternion<T> &q)
{
    v -= q.v;
    w -= q.w;
    return *this;
}


template <typename T>
VrtQuaternion<T> & VrtQuaternion<T>::operator *= (const VrtQuaternion<T> &q)
{
    *this = *this * q;
    return *this;
}



template <typename T>
vrt_bool operator == (const VrtQuaternion<T> &q, const VrtQuaternion<T> &r)
{
    return q.w == r.w && q.v == r.v;
}

template <typename T>
vrt_bool operator != (const VrtQuaternion<T> &q, const VrtQuaternion<T> &r)
{
    return q.w != r.w || q.v != r.v;
}

template <typename T>
VrtQuaternion<T> operator - (const VrtQuaternion<T> &q)
{
    return VrtQuaternion<T>(-q.v, -q.w);
}

template <typename T>
VrtQuaternion<T> operator + (const VrtQuaternion<T> &q, const VrtQuaternion<T> &r)
{
    return VrtQuaternion<T>(q.v + r.v, q.w + r.w);
}

template <typename T>
VrtQuaternion<T> operator - (const VrtQuaternion<T> &q, const VrtQuaternion<T> &r)
{
    return VrtQuaternion<T>(q.v - r.v, q.w - r.w);
}

template <typename T, typename S>
VrtQuaternion<T> operator * (const VrtQuaternion<T> &q, S s)
{
    return VrtQuaternion<T>(q.v * s, q.w * s);
}

template <typename T, typename S>
VrtQuaternion<T> operator / (const VrtQuaternion<T> &q, S s)
{
    return VrtQuaternion<T>(q.v / s, q.w / s);
}

template <typename T, typename S>
VrtQuaternion<T> operator * (S s, const VrtQuaternion<T> &q)
{
    return q * s;
}

template <typename T>
VrtQuaternion<T> operator * (const VrtQuaternion<T> &q, const VrtQuaternion<T> &r)
{
    return VrtQuaternion<T>(cross(q.v, r.v) + q.v * r.w + r.v * q.w, q.w * r.w - dot(q.v, r.v));
}

template <typename T>
T norm(const VrtQuaternion<T> & q)
{
    return dot(q.v, q.v) + q.w * q.w;
}

template <typename T>
VrtQuaternion<T> normalize(const VrtQuaternion<T> & q)
{
    return q / vrt_sqrt(norm(q));
}

template <typename T>
VrtQuaternion<T> conjugate(const VrtQuaternion<T> & q)
{
    return VrtQuaternion<T>(-q.v, q.w);
}

template <typename T>
VrtQuaternion<T> inverse(const VrtQuaternion<T> & q)
{
    return conjugate(q) / norm(q);
}

template <typename T>
VrtQuaternion<T> convert(const VrtMatrix4<T> &m)
{
    VrtQuaternion<T> q;
    T tr = m[0][0] + m[1][1] + m[2][2];
    if (tr > 0)
    {
        tr = vrt_sqrt(tr + m[3][3]);
        T s = 0.5f / tr;
        q.v.x = (m[1][2] - m[2][1]) * s;
        q.v.y = (m[2][0] - m[0][2]) * s;
        q.v.z = (m[0][1] - m[1][0]) * s;
        q.w   = tr * 0.5f;
    }
    else if ((m[0][0] > m[1][1]) && (m[0][0] > m[2][2]))
    {
        tr = vrt_sqrt(m[0][0] - m[1][1] - m[2][2] + m[3][3]);
        T s = 0.5f / tr;
        q.v.x = tr * 0.5f;
        q.v.y = (m[1][0] + m[0][1]) * s;
        q.v.z = (m[2][0] + m[0][2]) * s;
        q.w   = (m[1][2] - m[2][1]) * s;
    }
    else if ((m[1][1] > m[2][2]))
    {
        tr = vrt_sqrt(-m[0][0] + m[1][1] - m[2][2] + m[3][3]);
        T s = 0.5f / tr;
        q.v.x = (m[1][0] + m[0][1]) * s;
        q.v.y = tr * 0.5f;
        q.v.z = (m[2][1] + m[1][2]) * s;
        q.w   = (m[2][0] - m[0][2]) * s;
    }
    else
    {
        tr = vrt_sqrt(-m[0][0] - m[1][1] + m[2][2] + m[3][3]);
        T s = 0.5f / tr;
        q.v.x = (m[2][0] + m[0][2]) * s;
        q.v.y = (m[2][1] + m[1][2]) * s;
        q.v.z = tr * 0.5f;
        q.w   = (m[0][1] - m[1][0]) * s;
    }
    return q;
}

template <typename T>
VrtMatrix4<T> convert(const VrtQuaternion<T> &q)
{
    VrtMatrix4<T> m;
    VRT_DEV_ASSERT(VRT_ABS(norm(q) - 1) < 0.1f);
    // none-unit quaternion
    /*
    T s = 2 / norm(q);
    m[0] = VrtVector4<T>(1 - s * (q.y * q.y + q.z * q.z),     s * (q.x * q.y + q.w * q.z),     s * (q.x * q.z - q.w * q.y),  0);
    m[1] = VrtVector4<T>(    s * (q.x * q.y - q.w * q.z), 1 - s * (q.x * q.x + q.z * q.z),     s * (q.y * q.z + q.w * q.x),  0);
    m[2] = VrtVector4<T>(    s * (q.x * q.z + q.w * q.y),     s * (q.y * q.z - q.w * q.x), 1 - s * (q.x * q.x + q.y * q.y),  0);
    m[3] = VrtVector4<T>(                              0,                               0,                               0,  1);
    */

    // unit quaternion
    m[0] = VrtVector4<T>(1 - 2 * (q.v.y * q.v.y + q.v.z * q.v.z),     2 * (q.v.x * q.v.y +   q.w * q.v.z),     2 * (q.v.x * q.v.z -   q.w * q.v.y),  0);
    m[1] = VrtVector4<T>(    2 * (q.v.x * q.v.y -   q.w * q.v.z), 1 - 2 * (q.v.x * q.v.x + q.v.z * q.v.z),     2 * (q.v.y * q.v.z +   q.w * q.v.x),  0);
    m[2] = VrtVector4<T>(    2 * (q.v.x * q.v.z +   q.w * q.v.y),     2 * (q.v.y * q.v.z -   q.w * q.v.x), 1 - 2 * (q.v.x * q.v.x + q.v.y * q.v.y),  0);
    m[3] = VrtVector4<T>(                                      0,                                       0,                                       0,  1);
    return m;
}

template <typename T>
VrtMatrix3<T> convert3(const VrtQuaternion<T> &q)
{
    VrtMatrix3<T> m;
    VRT_DEV_ASSERT(VRT_ABS(norm(q) - 1) < 0.1f);
    // none-unit quaternion
    /*
    T s = 2 / norm(q);
    m[0] = VrtVector3<T>(1 - s * (q.y * q.y + q.z * q.z),     s * (q.x * q.y + q.w * q.z),     s * (q.x * q.z - q.w * q.y));
    m[1] = VrtVector3<T>(    s * (q.x * q.y - q.w * q.z), 1 - s * (q.x * q.x + q.z * q.z),     s * (q.y * q.z + q.w * q.x));
    m[2] = VrtVector3<T>(    s * (q.x * q.z + q.w * q.y),     s * (q.y * q.z - q.w * q.x), 1 - s * (q.x * q.x + q.y * q.y));
    */

    // unit quaternion
    m[0] = VrtVector3<T>(1 - 2 * (q.v.y * q.v.y + q.v.z * q.v.z),     2 * (q.v.x * q.v.y +   q.w * q.v.z),     2 * (q.v.x * q.v.z -   q.w * q.v.y));
    m[1] = VrtVector3<T>(    2 * (q.v.x * q.v.y -   q.w * q.v.z), 1 - 2 * (q.v.x * q.v.x + q.v.z * q.v.z),     2 * (q.v.y * q.v.z +   q.w * q.v.x));
    m[2] = VrtVector3<T>(    2 * (q.v.x * q.v.z +   q.w * q.v.y),     2 * (q.v.y * q.v.z -   q.w * q.v.x), 1 - 2 * (q.v.x * q.v.x + q.v.y * q.v.y));
    return m;
}

template <typename T>
VrtQuaternion<T> log(const VrtQuaternion<T> & q)
{
    VrtQuaternion<T> ret;

    vrt_float theta;
    if (q.w >= 1.0f)
    {
        theta = 0.0f;
    }
    else if (q.w <= -1.0f)
    {
        theta = VRT_PI;
    }
    else
    {
        theta = vrt_acos(q.w);
    }    
    vrt_float sin_theta = vrt_sin(theta);

    ret.w = 0;
    if (sin_theta != 0)
    {
        ret.v = q.v * theta / sin_theta;
    }
    return ret;
}

template <typename T>
VrtQuaternion<T> exp(const VrtQuaternion<T> & q)
{
    VrtQuaternion<T> ret;
    vrt_float theta = vrt_sqrt(norm(q));
    vrt_float sin_theta = vrt_sin(theta);
    vrt_float cos_theta = vrt_cos(theta);

    if (theta != 0)
    {
        ret.v = q.v * sin_theta / theta;
        ret.w = cos_theta;
    }
    return ret;
}

template <typename T>
VrtQuaternion<T> lerp(const VrtQuaternion<T> &q, const VrtQuaternion<T> &r, vrt_float t)
{
    VRT_DEV_ASSERT(VRT_ABS(norm(q) - 1) < 0.1f);
    VRT_DEV_ASSERT(VRT_ABS(norm(r) - 1) < 0.1f);

    return normalize(q + (r - q) * t);
}

template <typename T>
VrtQuaternion<T> slerp(const VrtQuaternion<T> &q, const VrtQuaternion<T> &r, vrt_float t)
{
    VRT_DEV_ASSERT(VRT_ABS(norm(q) - 1) < 0.1f);
    VRT_DEV_ASSERT(VRT_ABS(norm(r) - 1) < 0.1f);

    T dot_res = dot(q.v, r.v) + q.w * r.w;
    if (dot_res > 0.9995)
    {
        return normalize(q + (r - q) * t);
    }

    T theta = vrt_acos(dot_res);
    T sin_theta = vrt_sin(theta);
    if (sin_theta != 0)
    {
        return (q * vrt_sin((1 - t) * theta) + r * vrt_sin(t * theta)) * (1 / sin_theta);
    }
    else
    {
        return t < 0.5 ? q : r;
    }
}

template <typename T, typename S>
VrtQuaternion<T> squad(
    const VrtQuaternion<T> &q0,
    const VrtQuaternion<T> &q1,
    const VrtQuaternion<T> &q2,
    const VrtQuaternion<T> &q3,
    S t0,
    S t1,
    S t2,
    S t3,
    vrt_float t)
{
    VRT_DEV_ASSERT(VRT_ABS(norm(q0) - 1) < 0.1f);
    VRT_DEV_ASSERT(VRT_ABS(norm(q1) - 1) < 0.1f);
    VRT_DEV_ASSERT(VRT_ABS(norm(q2) - 1) < 0.1f);
    VRT_DEV_ASSERT(VRT_ABS(norm(q3) - 1) < 0.1f);

    vrt_float f1 = 2 * (vrt_float)(t2 - t1) / (vrt_float)(t2 - t0);
    vrt_float f2 = 2 * (vrt_float)(t2 - t1) / (vrt_float)(t3 - t1);
    VrtQuaternion<T> a1 = q1 * exp( (f1 * (log(inverse(q1) * q2) + log(inverse(q0) * q1)) * 0.5f - log(inverse(q1) * q2)) * 0.5f );
    VrtQuaternion<T> b2 = q2 * exp( (log(inverse(q1) * q2) - f2 * (log(inverse(q2) * q3) + log(inverse(q1) * q2)) * 0.5f) * 0.5f );

    return slerp(slerp(q1, q2, t), slerp(a1, b2, t), 2 * t * (1 - t));
}



template <typename T>
void VrtMatrix4<T>::setRotation(const VrtQuaternion<T> &q)
{
    (*this) = convert(q);
}

template <typename T>
void VrtMatrix4<T>::rotate(const VrtQuaternion<T> &q)
{
    // TODO: optimize it
    VrtMatrix4<T> rot = convert(q);
    (*this) = rot * (*this);
}

template <typename T>
void VrtMatrix4<T>::localRotate(const VrtQuaternion<T> &q)
{
    // TODO: optimize it
    VrtMatrix4<T> rot = convert(q);
    (*this) *= rot;
}

typedef VrtQuaternion<vrt_float> VrtQuaternionf;


#endif

