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
 *  vrt_matrix.h
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VRT_MATRIX__
#define __VRT_MATRIX__

#include "vrt_datatype.h"
#include "vrt_vector.h"


template <typename T>
inline void vrt_swap(T &a, T &b)
{
    const T c(a);
    a = b;
    b = c;
}

template <typename T> struct VrtMatrix3;
template <typename T> struct VrtMatrix4;
template <typename T> struct VrtQuaternion;


/*
 * VrtMatrix3 (column-major matrix)
 */
template <typename T>
struct VrtMatrix3
{
    VrtMatrix3();

    VrtMatrix3(T m0, T m1, T m2, T m3, T m4, T m5, T m6, T m7, T m8);

    VrtMatrix3(const T* m);

    VrtMatrix3(const VrtVector3<T> &c0, const VrtVector3<T> &c1, const VrtVector3<T> &c2);

    VrtMatrix3(const VrtMatrix4<T> &m);

    VrtVector3<T>& operator [] (vrt_u32 i);

    const VrtVector3<T>& operator [] (vrt_u32 i) const;

    VrtVector3<T> row(vrt_u32 i) const;

    VrtMatrix3 & operator = (const VrtMatrix4<T> &m);

    VrtMatrix3 & operator += (const VrtMatrix3 &m);

    VrtMatrix3 & operator -= (const VrtMatrix3 &m);

    VrtMatrix3 & operator *= (const VrtMatrix3 &m);

    void setIdentity();

    void transpose();

    void inverse();

    void inverse_transpose();

    VrtVector3<T> col[3];
};

template <typename T>
vrt_bool operator == (const VrtMatrix3<T> &a, const VrtMatrix3<T> &b);

template <typename T>
vrt_bool operator != (const VrtMatrix3<T> &a, const VrtMatrix3<T> &b);

template <typename T>
VrtVector3<T> operator * (const VrtMatrix3<T> &m, const VrtVector3<T> &v);

template <typename T>
VrtVector3<T> operator * (const VrtVector3<T> &v, const VrtMatrix3<T> &m);

template <typename T>
VrtMatrix3<T> operator + (const VrtMatrix3<T> &a, const VrtMatrix3<T> &b);

template <typename T>
VrtMatrix3<T> operator - (const VrtMatrix3<T> &a, const VrtMatrix3<T> &b);

template <typename T>
VrtMatrix3<T> operator * (const VrtMatrix3<T> &a, const VrtMatrix3<T> &b);

template <typename T>
VrtMatrix3<T> transpose(const VrtMatrix3<T> &m);

template <typename T>
VrtMatrix3<T> inverse(const VrtMatrix3<T> &m);

template <typename T>
VrtMatrix3<T> inverse_transpose(const VrtMatrix3<T> &m);


/*
 * VrtMatrix4
 */
template <typename T>
struct VrtMatrix4
{

    VrtMatrix4();

    VrtMatrix4(T m0, T m1, T m2, T m3, T m4, T m5, T m6, T m7, T m8, T m9, T m10, T m11, T m12, T m13, T m14, T m15);

    VrtMatrix4(const T* m);

    VrtMatrix4(const VrtVector4<T> &c0, const VrtVector4<T> &c1, const VrtVector4<T> &c2, const VrtVector4<T> &c3);

    VrtVector4<T>& operator [] (vrt_u32 i);

    const VrtVector4<T>& operator [] (vrt_u32 i) const;

    VrtVector4<T> row(vrt_u32 i) const;

    VrtMatrix4 & operator += (const VrtMatrix4 &m);

    VrtMatrix4 & operator -= (const VrtMatrix4 &m);

    VrtMatrix4 & operator *= (const VrtMatrix4 &m);

    VrtMatrix4 & operator *= (const T v);

    void transpose();

    void inverse();
    
    /* set */

    void setIdentity();

    void setScale(T s);

    void setScale(T x, T y, T z);

    void setScale(const VrtVector3<T> &v);

    void setTranslation(T x, T y, T z);

    void setTranslation(const VrtVector3<T> &v);

    void setRotationX(T a);

    void setRotationY(T a);

    void setRotationZ(T a);

    void setRotation(const VrtVector3<T> &axis, T angle);

    void setRotation(const VrtQuaternion<T> &quat);

    void setLookAt(const VrtVector3<T>& pos, const VrtVector3<T>& target, const VrtVector3<T>& up);

    void setPerspective(T fovy, T aspect_ratio, T n, T f);

    void setInversePerspective(T fovy, T aspect_ratio, T n, T f);    

    void setParallel(T fovy, T aspect_ratio, T n, T f);

    void setScreen(T x, T y, T w, T h);
    
    void setScreen(T x, T y, T w, T h, T n, T f);

    void setShadow(const VrtVector3<T> &l, const VrtVector3<T> &n, T d);

    /* transform */
    void scale(T s);

    void scale(T x, T y, T z);

    void scale(const VrtVector3<T> &v);

    void translate(T x, T y, T z);

    void translate(const VrtVector3<T> &v);

    void rotateX(T angle);

    void rotateY(T angle);

    void rotateZ(T angle);

    void rotate(const VrtVector3<T> &axis, T angle);

    void rotate(const VrtQuaternion<T> &q);

    void localScale(T s);

    void localScale(T x, T y , T z);

    void localScale(const VrtVector3<T> &v);

    void localTranslate(T x, T y , T z);

    void localTranslate(const VrtVector3<T> &v);

    void localRotateX(T angle);

    void localRotateY(T angle);

    void localRotateZ(T angle);

    void localRotate(const VrtVector3<T> &axis, T angle);

    void localRotate(const VrtQuaternion<T> &q);


    VrtVector4<T> col[4];
};


template <typename T>
vrt_bool operator == (const VrtMatrix4<T> &a, const VrtMatrix4<T> &b);

template <typename T>
vrt_bool operator != (const VrtMatrix4<T> &a, const VrtMatrix4<T> &b);

template <typename T>
VrtVector4<T> operator * (const VrtMatrix4<T> &m, const VrtVector4<T> &v );

template <typename T>
VrtVector4<T> operator * (const VrtVector4<T> &v, const VrtMatrix4<T> &m );

template <typename T>
VrtMatrix4<T> operator + (const VrtMatrix4<T> &a, const VrtMatrix4<T> &b);

template <typename T>
VrtMatrix4<T> operator - (const VrtMatrix4<T> &a, const VrtMatrix4<T> &b);

template <typename T>
VrtMatrix4<T> operator * (const VrtMatrix4<T> &m, const T v);

template <typename T>
VrtMatrix4<T> operator * (const VrtMatrix4<T> &a, const VrtMatrix4<T> &b);

template <typename T>
VrtMatrix4<T> transpose(const VrtMatrix4<T> &m);

template <typename T>
VrtMatrix4<T> inverse43(const VrtMatrix4<T> &m);

template <typename T>
VrtMatrix4<T> inverse(const VrtMatrix4<T> &m);

template <typename T>
VrtMatrix3<T> inverse_transpose_33(const VrtMatrix4<T> &m);

template <typename T>
VrtMatrix4<T> inverse_transpose_43(const VrtMatrix4<T> &m);

template <typename T>
VrtMatrix4<T> inverse_transpose(const VrtMatrix4<T> &m);





/*
 * VrtMatrix3
 */
template <typename T>
VrtMatrix3<T>::VrtMatrix3()
{
    setIdentity();
}

template <typename T>
VrtMatrix3<T>::VrtMatrix3(T m0, T m1, T m2, T m3, T m4, T m5, T m6, T m7, T m8)
{
    col[0] = VrtVector3<T>(m0, m1, m2);
    col[1] = VrtVector3<T>(m3, m4, m5);
    col[2] = VrtVector3<T>(m6, m7, m8);
}

template <typename T>
VrtMatrix3<T>::VrtMatrix3(const T* m)
{
    col[0] = VrtVector3<T>(m[0], m[1], m[2]);
    col[1] = VrtVector3<T>(m[3], m[4], m[5]);
    col[2] = VrtVector3<T>(m[6], m[7], m[8]);
}

template <typename T>
VrtMatrix3<T>::VrtMatrix3(const VrtVector3<T> &c0, const VrtVector3<T> &c1, const VrtVector3<T> &c2)
{
    col[0] = c0;
    col[1] = c1;
    col[2] = c2;
}

template <typename T>
VrtMatrix3<T>::VrtMatrix3(const VrtMatrix4<T> &m)
{
    col[0] = m[0];
    col[1] = m[1];
    col[2] = m[2];
}

template <typename T>
VrtVector3<T> & VrtMatrix3<T>::operator [] (vrt_u32 i)
{
    return col[i];
}

template <typename T>
const VrtVector3<T> & VrtMatrix3<T>::operator [] (vrt_u32 i) const
{
    return col[i];
}

template <typename T>
VrtVector3<T> VrtMatrix3<T>::row(vrt_u32 i) const
{
    return VrtVector3<T>(col[0][i], col[1][i], col[2][i]);
}

template <typename T>
VrtMatrix3<T> & VrtMatrix3<T>::operator = (const VrtMatrix4<T> &m)
{
    col[0] = m.col[0];
    col[1] = m.col[1];
    col[2] = m.col[2];
    return *this;
}

template <typename T>
VrtMatrix3<T> & VrtMatrix3<T>::operator += (const VrtMatrix3<T> &m)
{
    *this = *this + m;
    return *this;
}

template <typename T>
VrtMatrix3<T> & VrtMatrix3<T>::operator -= (const VrtMatrix3<T> &m)
{
    *this = *this - m;
    return *this;
}

template <typename T>
VrtMatrix3<T> & VrtMatrix3<T>::operator *= (const VrtMatrix3<T> &m)
{
    *this = *this * m;
    return *this;
}

template <typename T>
void VrtMatrix3<T>::setIdentity()
{
    col[0] = VrtVector3<T>(1, 0, 0);
    col[1] = VrtVector3<T>(0, 1, 0);
    col[2] = VrtVector3<T>(0, 0, 1);
}

template <typename T>
void VrtMatrix3<T>::transpose()
{
    vrt_swap(col[0][1], col[1][0]);
    vrt_swap(col[0][2], col[2][0]);
    vrt_swap(col[1][2], col[2][1]);
}

template <typename T>
void VrtMatrix3<T>::inverse()
{
    *this = ::inverse(*this);
}

template <typename T>
void VrtMatrix3<T>::inverse_transpose()
{
    *this = ::inverse_transpose(*this);
}

template <typename T>
vrt_bool operator == (const VrtMatrix3<T> &a, const VrtMatrix3<T> &b)
{
    return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
}

template <typename T>
vrt_bool operator != (const VrtMatrix3<T> &a, const VrtMatrix3<T> &b)
{
    return a[0] != b[0] || a[1] != b[1] || a[2] != b[2];
}

template <typename T>
VrtVector3<T> operator * (const VrtMatrix3<T> &m, const VrtVector3<T> &v )
{
    return m[0] * v.x + m[1] * v.y + m[2] * v.z;
}

template <typename T>
VrtVector3<T> operator * (const VrtVector3<T> &v, const VrtMatrix3<T> &m )
{
    return VrtVector3<T>(dot(v, m[0]), dot(v, m[1]), dot(v, m[2]));    
}

template <typename T>
VrtMatrix3<T> operator + (const VrtMatrix3<T> &a, const VrtMatrix3<T> &b)
{
    return VrtMatrix3<T>(a[0] + b[0], a[1] + b[1], a[2] + b[2]);
}

template <typename T>
VrtMatrix3<T> operator - (const VrtMatrix3<T> &a, const VrtMatrix3<T> &b)
{
    return VrtMatrix3<T>(a[0] - b[0], a[1] - b[1], a[2] - b[2]);
}

template <typename T>
VrtMatrix3<T> operator * (const VrtMatrix3<T> &a, const VrtMatrix3<T> &b)
{
    return VrtMatrix3<T>(a * b[0], a * b[1], a * b[2]);
}

template <typename T>
VrtMatrix3<T> transpose(const VrtMatrix3<T> &m)
{
    return VrtMatrix3<T>(VrtVector3<T>( m[0][0], m[1][0], m[2][0] ),
                         VrtVector3<T>( m[0][1], m[1][1], m[2][1] ),
                         VrtVector3<T>( m[0][2], m[1][2], m[2][2] ));
}

template <typename T>
VrtMatrix3<T> inverse(const VrtMatrix3<T> &m)
{
    return transpose(inverse_transpose(m));
}

template <typename T>
VrtMatrix3<T> inverse_transpose(const VrtMatrix3<T> &m)
{
    /* determinant is triple product of the column vectors */
    T det = dot( m[0], cross( m[1], m[2] ) );
    if( det != T(0) )
    {
        T scale = T(1) / det;
        return VrtMatrix3<T>( cross( m[1], m[2] ) * scale,
                              cross( m[2], m[0] ) * scale,
                              cross( m[0], m[1] ) * scale );
    }
    else
    {
        /* we couldn't invert matrix so return the original */
        VRT_DEV_ASSERT(0);
        return m;
    }
}


/*
 * VrtMatrix4
 */
template <typename T>
VrtMatrix4<T>::VrtMatrix4()
{
    setIdentity();
}

template <typename T>
VrtMatrix4<T>::VrtMatrix4(T m0, T m1, T m2, T m3, T m4, T m5, T m6, T m7, T m8, T m9, T m10, T m11, T m12, T m13, T m14, T m15)
{
    col[0] = VrtVector4<T>(m0, m1, m2, m3);
    col[1] = VrtVector4<T>(m4, m5, m6, m7);
    col[2] = VrtVector4<T>(m8, m9, m10, m11);
    col[3] = VrtVector4<T>(m12, m13, m14, m15);
}

template <typename T>
VrtMatrix4<T>::VrtMatrix4(const T* m)
{
    col[0] = VrtVector4<T>(m[0], m[1], m[2], m[3]);
    col[1] = VrtVector4<T>(m[4], m[5], m[6], m[7]);
    col[2] = VrtVector4<T>(m[8], m[9], m[10], m[11]);
    col[3] = VrtVector4<T>(m[12], m[13], m[14], m[15]);
}

template <typename T>
VrtMatrix4<T>::VrtMatrix4(const VrtVector4<T> &c0, const VrtVector4<T> &c1, const VrtVector4<T> &c2, const VrtVector4<T> &c3)
{
    col[0] = c0;
    col[1] = c1;
    col[2] = c2;
    col[3] = c3;
}

template <typename T>
VrtVector4<T>& VrtMatrix4<T>::operator [] (vrt_u32 i)
{
    return col[i];
}

template <typename T>
const VrtVector4<T>& VrtMatrix4<T>::operator [] (vrt_u32 i) const
{
    return col[i];
}

template <typename T>
VrtVector4<T> VrtMatrix4<T>::row(vrt_u32 i) const
{
    return VrtVector4<T>(col[0][i], col[1][i], col[2][i], col[3][i]);
}

template <typename T>
VrtMatrix4<T> & VrtMatrix4<T>::operator += (const VrtMatrix4<T> &m)
{
    *this = *this + m;
    return *this;
}

template <typename T>
VrtMatrix4<T> & VrtMatrix4<T>::operator -= (const VrtMatrix4<T> &m)
{
    *this = *this - m;
    return *this;
}

template <typename T>
VrtMatrix4<T> & VrtMatrix4<T>::operator *= (const VrtMatrix4<T> &m)
{
    *this = *this * m;
    return *this;
}

template <typename T>
VrtMatrix4<T> & VrtMatrix4<T>::operator *= (const T v)
{
    *this = *this * v;
    return *this;
}

template <typename T>
void VrtMatrix4<T>::setIdentity()
{
    col[0] = VrtVector4<T>(1, 0, 0, 0);
    col[1] = VrtVector4<T>(0, 1, 0, 0);
    col[2] = VrtVector4<T>(0, 0, 1, 0);
    col[3] = VrtVector4<T>(0, 0, 0, 1);
}

template <typename T>
void VrtMatrix4<T>::setScale(T s)
{
    setScale(s, s, s);
}

template <typename T>
void VrtMatrix4<T>::setScale(T x, T y, T z)
{
    col[0] = VrtVector4<T>(x, 0, 0, 0);
    col[1] = VrtVector4<T>(0, y, 0, 0);
    col[2] = VrtVector4<T>(0, 0, z, 0);
    col[3] = VrtVector4<T>(0, 0, 0, 1);
}

template <typename T>
void VrtMatrix4<T>::setScale(const VrtVector3<T> &v)
{
    setScale(v.x, v.y, v.z);
}

template <typename T>
void VrtMatrix4<T>::setTranslation(T x, T y, T z)
{
    col[0] = VrtVector4<T>(1, 0, 0, 0);
    col[1] = VrtVector4<T>(0, 1, 0, 0);
    col[2] = VrtVector4<T>(0, 0, 1, 0);
    col[3] = VrtVector4<T>(x, y, z, 1);
}

template <typename T>
void VrtMatrix4<T>::setTranslation(const VrtVector3<T> &v)
{
    setTranslation(v.x, v.y, v.z);
}

template <typename T>
void VrtMatrix4<T>::setRotationX(T a)
{
    T s = vrt_sin(a);
    T c = vrt_cos(a);
    col[0] = VrtVector4<T>(1, 0, 0, 0);
    col[1] = VrtVector4<T>(0, c, s, 0);
    col[2] = VrtVector4<T>(0, -s, c, 0);
    col[3] = VrtVector4<T>(0, 0, 0, 1);
}

template <typename T>
void VrtMatrix4<T>::setRotationY(T a)
{
    T s = vrt_sin(a);
    T c = vrt_cos(a);
    col[0] = VrtVector4<T>(c, 0, -s, 0);
    col[1] = VrtVector4<T>(0, 1, 0, 0);
    col[2] = VrtVector4<T>(s, 0, c, 0);
    col[3] = VrtVector4<T>(0, 0, 0, 1);
}

template <typename T>
void VrtMatrix4<T>::setRotationZ(T a)
{
    T s = vrt_sin(a);
    T c = vrt_cos(a);
    col[0] = VrtVector4<T>(c, s, 0, 0);
    col[1] = VrtVector4<T>(-s, c, 0, 0);
    col[2] = VrtVector4<T>(0, 0, 1, 0);
    col[3] = VrtVector4<T>(0, 0, 0, 1);
}

template <typename T>
void VrtMatrix4<T>::setRotation(const VrtVector3<T> &axis, T angle)
{
    VRT_DEV_ASSERT(VRT_ABS(length(axis) - 1.0) < 0.001);
    // r should be normalized vector
    const VrtVector3<T> &r = axis;
    T c = vrt_cos(angle);
    T s = vrt_sin(angle);
    T d = T(1) - c;

    col[0] = VrtVector4<T>(d*r.x*r.x + c,     d*r.x*r.y + s*r.z, d*r.x*r.z - s*r.y, T(0));
    col[1] = VrtVector4<T>(d*r.x*r.y - s*r.z, d*r.y*r.y + c,     d*r.y*r.z + s*r.x, T(0));
    col[2] = VrtVector4<T>(d*r.x*r.z + s*r.y, d*r.y*r.z - s*r.x, d*r.z*r.z + c,     T(0));
    col[3] = VrtVector4<T>(T(0),              T(0),              T(0),              T(1));
}

template <typename T>
void VrtMatrix4<T>::setLookAt(const VrtVector3<T>& pos, const VrtVector3<T>& target, const VrtVector3<T>& up)
{
    VrtVector3<T> dir = normalize(pos - target);
    VrtVector3<T> right = normalize(cross(up, dir));
    VrtVector3<T> up_fix = normalize(cross(dir, right));

    col[0] = VrtVector4<T>(right, 0);
    col[1] = VrtVector4<T>(up_fix, 0);
    col[2] = VrtVector4<T>(dir, 0);
    col[3] = VrtVector4<T>(pos, 1.0f);
}

template <typename T>
void VrtMatrix4<T>::setPerspective(T fovy, T aspect_ratio, T n, T f)
{
    T h = vrt_tan(fovy / 2);
    T w = h * aspect_ratio;
    T d = f - n;
    col[0] = VrtVector4<T>(1/w, 0, 0, 0);
    col[1] = VrtVector4<T>(0, 1/h, 0, 0);
    col[2] = VrtVector4<T>(0, 0, -(n+f)/d, -1);
    col[3] = VrtVector4<T>(0, 0, -2*n*f/d, 0);    
}

template <typename T>
void VrtMatrix4<T>::setInversePerspective(T fovy, T aspect_ratio, T n, T f)
{
    T h = vrt_tan(fovy / 2);
    T w = h * aspect_ratio;
    T d = f - n;
    col[0] = VrtVector4<T>(w, 0, 0, 0);
    col[1] = VrtVector4<T>(0, h, 0, 0);
    col[2] = VrtVector4<T>(0, 0, 0, -d/(2*n*f));
    col[3] = VrtVector4<T>(0, 0, -1, (n+f)/(2*n*f));
}

template <typename T>
void VrtMatrix4<T>::setParallel(T fovy, T aspect_ratio, T n, T f)
{
    T h = fovy;
    T w = h * aspect_ratio;
    T d = f - n;
    col[0] = VrtVector4<T>(2/w, 0, 0, 0);
    col[1] = VrtVector4<T>(0, 2/h, 0, 0);
    col[2] = VrtVector4<T>(0, 0, -2/d, 0);
    col[3] = VrtVector4<T>(0, 0, -(n+f)/d, 1);
}

template <typename T>
void VrtMatrix4<T>::setScreen(T x, T y, T w, T h)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    T tx = -(2 * x + w) / w;
    T ty =  (2 * y + h) / h;
    col[0] = VrtVector4<T>(2/w, 0, 0, 0);
    col[1] = VrtVector4<T>(0, -2/h, 0, 0);
    col[2] = VrtVector4<T>(0, 0, -1, 0);
    col[3] = VrtVector4<T>(tx, ty, 0, 1);
#endif
}

template <typename T>
void VrtMatrix4<T>::setScreen(T x, T y, T w, T h, T n, T f)
{
    T tx = -(2 * x + w) / w;
    T ty =  (2 * y + h) / h;
    T d = f - n;
    col[0] = VrtVector4<T>(2/w, 0, 0, 0);
    col[1] = VrtVector4<T>(0, -2/h, 0, 0);
    col[2] = VrtVector4<T>(0, 0, -1/d, 0);
    col[3] = VrtVector4<T>(tx, ty, -n/d, 1);
}


template <typename T>
void VrtMatrix4<T>::setShadow(const VrtVector3<T> &l, const VrtVector3<T> &n, T d)
{
    T nl = dot(n, l);
    col[0] = VrtVector4<T>(nl+d-l.x*n.x,     -l.y*n.x,     -l.z*n.x, -n.x);
    col[1] = VrtVector4<T>(    -l.x*n.y, nl+d-l.y*n.y,     -l.z*n.y, -n.y);
    col[2] = VrtVector4<T>(    -l.x*n.z,     -l.y*n.z, nl+d-l.z*n.z, -n.z);
    col[3] = VrtVector4<T>(      -l.x*d,       -l.y*d,       -l.z*d,   nl);
}

template <typename T>
void VrtMatrix4<T>::scale(T s)
{
    scale(VrtVector3<T>(s, s, s));
}

template <typename T>
void VrtMatrix4<T>::scale(T x, T y, T z)
{
    scale(VrtVector3<T>(x, y, z));
}

template <typename T>
void VrtMatrix4<T>::scale(const VrtVector3<T> &v)
{
    col[0].xyz() *= v;
    col[1].xyz() *= v;
    col[2].xyz() *= v;
    col[3].xyz() *= v;
}

template <typename T>
void VrtMatrix4<T>::translate(T x, T y, T z)
{
    translate(VrtVector3<T>(x, y, z));
}

template <typename T>
void VrtMatrix4<T>::translate(const VrtVector3<T> &v)
{
    col[3].xyz() += v;
}

template <typename T>
void VrtMatrix4<T>::rotateX(T angle)
{
    VrtMatrix4<T> rot;
    rot.setRotationX(angle);
    (*this) = rot * (*this);
}

template <typename T>
void VrtMatrix4<T>::rotateY(T angle)
{
    VrtMatrix4<T> rot;
    rot.setRotationY(angle);
    (*this) = rot * (*this);
}

template <typename T>
void VrtMatrix4<T>::rotateZ(T angle)
{
    VrtMatrix4<T> rot;
    rot.setRotationZ(angle);
    (*this) = rot * (*this);
}

template <typename T>
void VrtMatrix4<T>::rotate(const VrtVector3<T> &axis, T angle)
{
    VrtMatrix4<T> rot;
    rot.setRotation(axis, angle);
    (*this) = rot * (*this);
}

template <typename T>
void VrtMatrix4<T>::localScale(T s)
{
    localScale(VrtVector3<T>(s, s, s));
}

template <typename T>
void VrtMatrix4<T>::localScale(T x, T y, T z)
{
    localScale(VrtVector3<T>(x, y, z));
}

template <typename T>
void VrtMatrix4<T>::localScale(const VrtVector3<T> &v)
{
    col[0] *= v.x;
    col[1] *= v.y;
    col[2] *= v.z;
}

template <typename T>
void VrtMatrix4<T>::localTranslate(T x, T y, T z)
{
    localTranslate(VrtVector3<T>(x, y, z));
}

template <typename T>
void VrtMatrix4<T>::localTranslate(const VrtVector3<T> &v)
{
    col[3].xyz() += (col[0].xyz() * v.x +
                     col[1].xyz() * v.y +
                     col[2].xyz() * v.z);
}

template <typename T>
void VrtMatrix4<T>::localRotateX(T angle)
{
    VrtMatrix4<T> rot;
    rot.setRotationX(angle);
    (*this) *= rot;
}

template <typename T>
void VrtMatrix4<T>::localRotateY(T angle)
{
    VrtMatrix4<T> rot;
    rot.setRotationY(angle);
    (*this) *= rot;
}

template <typename T>
void VrtMatrix4<T>::localRotateZ(T angle)
{
    VrtMatrix4<T> rot;
    rot.setRotationZ(angle);
    (*this) *= rot;
}

template <typename T>
void VrtMatrix4<T>::localRotate(const VrtVector3<T> &axis, T angle)
{
    VrtMatrix4<T> rot;
    rot.setRotation(axis, angle);
    (*this) *= rot;
}

template <typename T>
void VrtMatrix4<T>::transpose()
{
    vrt_swap(col[0][1], col[1][0]);
    vrt_swap(col[0][2], col[2][0]);
    vrt_swap(col[0][3], col[3][0]);
    vrt_swap(col[1][2], col[2][1]);
    vrt_swap(col[1][3], col[3][1]);
    vrt_swap(col[2][3], col[3][2]);
}

template <typename T>
void VrtMatrix4<T>::inverse()
{
    *this = ::inverse(*this);
}

template <typename T>
vrt_bool operator == (const VrtMatrix4<T> &a, const VrtMatrix4<T> &b)
{
    return a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3];
}

template <typename T>
vrt_bool operator != (const VrtMatrix4<T> &a, const VrtMatrix4<T> &b)
{
    return a[0] != b[0] || a[1] != b[1] || a[2] != b[2] || a[3] != b[3];
}

template <typename T>
VrtVector4<T> operator * (const VrtMatrix4<T> &m, const VrtVector4<T> &v )
{
    return m[0] * v.x + m[1] * v.y + m[2] * v.z + m[3] * v.w;
}

template <typename T>
VrtVector4<T> operator * (const VrtVector4<T> &v, const VrtMatrix4<T> &m )
{
    return VrtVector4<T>(dot(v, m[0]), dot(v, m[1]), dot(v, m[2]), dot(v, m[3]));
}

template <typename T>
VrtMatrix4<T> operator + (const VrtMatrix4<T> &a, const VrtMatrix4<T> &b)
{
    return VrtMatrix4<T>(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}

template <typename T>
VrtMatrix4<T> operator - (const VrtMatrix4<T> &a, const VrtMatrix4<T> &b)
{
    return VrtMatrix4<T>(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

template <typename T>
VrtMatrix4<T> operator * (const VrtMatrix4<T> &m, const T v)
{
    return VrtMatrix4<T>(m[0] * v, m[1] * v, m[2] * v, m[3] * v);
}

template <typename T>
VrtMatrix4<T> operator * (const VrtMatrix4<T> &a, const VrtMatrix4<T> &b)
{
    return VrtMatrix4<T>(a * b[0], a * b[1], a * b[2], a * b[3]);
}

template <typename T>
VrtMatrix4<T> transpose(const VrtMatrix4<T> &m)
{
    return VrtMatrix4<T>(
            VrtVector4<T>( m[0][0], m[1][0], m[2][0], m[3][0] ),
            VrtVector4<T>( m[0][1], m[1][1], m[2][1], m[3][1] ),
            VrtVector4<T>( m[0][2], m[1][2], m[2][2], m[3][2] ),
            VrtVector4<T>( m[0][3], m[1][3], m[2][3], m[3][3] ) );
}

template <typename T>
VrtMatrix4<T> inverse43(const VrtMatrix4<T> &m)
{
    T det = -m[0][2] * m[1][1] * m[2][0] +
             m[0][1] * m[1][2] * m[2][0] +
             m[0][2] * m[1][0] * m[2][1] -
             m[0][0] * m[1][2] * m[2][1] -
             m[0][1] * m[1][0] * m[2][2] +
             m[0][0] * m[1][1] * m[2][2];

    /* This does not protect against overflow when det is very small, but does
       at least guard against singular matrices with e.g. all zero elements */
    if( det != T( 0 ) )
    {
        T scale = T( 1 ) / det;
        VrtMatrix4<T> inv;
        inv[0][0] = -m[1][2]*m[2][1] + m[1][1]*m[2][2];
        inv[0][1] =  m[0][2]*m[2][1] - m[0][1]*m[2][2];
        inv[0][2] = -m[0][2]*m[1][1] + m[0][1]*m[1][2];
        inv[0][3] = T(0);
        inv[1][0] =  m[1][2]*m[2][0] - m[1][0]*m[2][2];
        inv[1][1] = -m[0][2]*m[2][0] + m[0][0]*m[2][2];
        inv[1][2] =  m[0][2]*m[1][0] - m[0][0]*m[1][2];
        inv[1][3] = T(0);
        inv[2][0] = -m[1][1]*m[2][0] + m[1][0]*m[2][1];
        inv[2][1] =  m[0][1]*m[2][0] - m[0][0]*m[2][1];
        inv[2][2] = -m[0][1]*m[1][0] + m[0][0]*m[1][1];
        inv[2][3] = T(0);
        inv[3][0] = m[1][2]*m[2][1]*m[3][0] - m[1][1]*m[2][2]*m[3][0] - m[1][2]*m[2][0]*m[3][1] +
                    m[1][0]*m[2][2]*m[3][1] + m[1][1]*m[2][0]*m[3][2] - m[1][0]*m[2][1]*m[3][2];
        inv[3][1] = m[0][1]*m[2][2]*m[3][0] - m[0][2]*m[2][1]*m[3][0] + m[0][2]*m[2][0]*m[3][1] -
                    m[0][0]*m[2][2]*m[3][1] - m[0][1]*m[2][0]*m[3][2] + m[0][0]*m[2][1]*m[3][2];
        inv[3][2] = m[0][2]*m[1][1]*m[3][0] - m[0][1]*m[1][2]*m[3][0] - m[0][2]*m[1][0]*m[3][1] +
                    m[0][0]*m[1][2]*m[3][1] + m[0][1]*m[1][0]*m[3][2] - m[0][0]*m[1][1]*m[3][2];
        inv[3][3] = det; /* will scale back to 1 */
        
        inv *= scale;
        inv[3][3] = T(1); /* set exactly to that comparisons in future will work */
        return inv;
    }
    /* we couldn't invert matrix so return the original */
    return m;
}


template <typename T>
VrtMatrix4<T> inverse(const VrtMatrix4<T> &m)
{
    /* If the bottom row is 0 0 0 1 do a much cheaper inverse */
    if( ( m[0][3] == T(0) ) && ( m[1][3] == T(0) ) &&
        ( m[2][3] == T(0) ) && ( m[3][3] == T(1) ) )
    {
        return inverse43( m );
    }

    T det = m[0][3] * m[1][2] * m[2][1] * m[3][0] - m[0][2] * m[1][3] * m[2][1] * m[3][0] -
            m[0][3] * m[1][1] * m[2][2] * m[3][0] + m[0][1] * m[1][3] * m[2][2] * m[3][0] +
            m[0][2] * m[1][1] * m[2][3] * m[3][0] - m[0][1] * m[1][2] * m[2][3] * m[3][0] -
            m[0][3] * m[1][2] * m[2][0] * m[3][1] + m[0][2] * m[1][3] * m[2][0] * m[3][1] +
            m[0][3] * m[1][0] * m[2][2] * m[3][1] - m[0][0] * m[1][3] * m[2][2] * m[3][1] -
            m[0][2] * m[1][0] * m[2][3] * m[3][1] + m[0][0] * m[1][2] * m[2][3] * m[3][1] +
            m[0][3] * m[1][1] * m[2][0] * m[3][2] - m[0][1] * m[1][3] * m[2][0] * m[3][2] -
            m[0][3] * m[1][0] * m[2][1] * m[3][2] + m[0][0] * m[1][3] * m[2][1] * m[3][2] +
            m[0][1] * m[1][0] * m[2][3] * m[3][2] - m[0][0] * m[1][1] * m[2][3] * m[3][2] -
            m[0][2] * m[1][1] * m[2][0] * m[3][3] + m[0][1] * m[1][2] * m[2][0] * m[3][3] +
            m[0][2] * m[1][0] * m[2][1] * m[3][3] - m[0][0] * m[1][2] * m[2][1] * m[3][3] -
            m[0][1] * m[1][0] * m[2][2] * m[3][3] + m[0][0] * m[1][1] * m[2][2] * m[3][3];

    /* This does not protect against overflow when det is very small, but does
       at least guard against singular matrices with e.g. all zero elements */
    if( det != T( 0 ) )
    {
      T scale = T( 1 ) / det;
      VrtMatrix4<T> inv;
      inv[0][0] = m[1][2]*m[2][3]*m[3][1] - m[1][3]*m[2][2]*m[3][1] + m[1][3]*m[2][1]*m[3][2] -
                  m[1][1]*m[2][3]*m[3][2] - m[1][2]*m[2][1]*m[3][3] + m[1][1]*m[2][2]*m[3][3];
      inv[0][1] = m[0][3]*m[2][2]*m[3][1] - m[0][2]*m[2][3]*m[3][1] - m[0][3]*m[2][1]*m[3][2] +
                  m[0][1]*m[2][3]*m[3][2] + m[0][2]*m[2][1]*m[3][3] - m[0][1]*m[2][2]*m[3][3];
      inv[0][2] = m[0][2]*m[1][3]*m[3][1] - m[0][3]*m[1][2]*m[3][1] + m[0][3]*m[1][1]*m[3][2] -
                  m[0][1]*m[1][3]*m[3][2] - m[0][2]*m[1][1]*m[3][3] + m[0][1]*m[1][2]*m[3][3];
      inv[0][3] = m[0][3]*m[1][2]*m[2][1] - m[0][2]*m[1][3]*m[2][1] - m[0][3]*m[1][1]*m[2][2] +
                  m[0][1]*m[1][3]*m[2][2] + m[0][2]*m[1][1]*m[2][3] - m[0][1]*m[1][2]*m[2][3];
      inv[1][0] = m[1][3]*m[2][2]*m[3][0] - m[1][2]*m[2][3]*m[3][0] - m[1][3]*m[2][0]*m[3][2] +
                  m[1][0]*m[2][3]*m[3][2] + m[1][2]*m[2][0]*m[3][3] - m[1][0]*m[2][2]*m[3][3];
      inv[1][1] = m[0][2]*m[2][3]*m[3][0] - m[0][3]*m[2][2]*m[3][0] + m[0][3]*m[2][0]*m[3][2] -
                  m[0][0]*m[2][3]*m[3][2] - m[0][2]*m[2][0]*m[3][3] + m[0][0]*m[2][2]*m[3][3];
      inv[1][2] = m[0][3]*m[1][2]*m[3][0] - m[0][2]*m[1][3]*m[3][0] - m[0][3]*m[1][0]*m[3][2] +
                  m[0][0]*m[1][3]*m[3][2] + m[0][2]*m[1][0]*m[3][3] - m[0][0]*m[1][2]*m[3][3];
      inv[1][3] = m[0][2]*m[1][3]*m[2][0] - m[0][3]*m[1][2]*m[2][0] + m[0][3]*m[1][0]*m[2][2] -
                  m[0][0]*m[1][3]*m[2][2] - m[0][2]*m[1][0]*m[2][3] + m[0][0]*m[1][2]*m[2][3];
      inv[2][0] = m[1][1]*m[2][3]*m[3][0] - m[1][3]*m[2][1]*m[3][0] + m[1][3]*m[2][0]*m[3][1] -
                  m[1][0]*m[2][3]*m[3][1] - m[1][1]*m[2][0]*m[3][3] + m[1][0]*m[2][1]*m[3][3];
      inv[2][1] = m[0][3]*m[2][1]*m[3][0] - m[0][1]*m[2][3]*m[3][0] - m[0][3]*m[2][0]*m[3][1] +
                  m[0][0]*m[2][3]*m[3][1] + m[0][1]*m[2][0]*m[3][3] - m[0][0]*m[2][1]*m[3][3];
      inv[2][2] = m[0][1]*m[1][3]*m[3][0] - m[0][3]*m[1][1]*m[3][0] + m[0][3]*m[1][0]*m[3][1] -
                  m[0][0]*m[1][3]*m[3][1] - m[0][1]*m[1][0]*m[3][3] + m[0][0]*m[1][1]*m[3][3];
      inv[2][3] = m[0][3]*m[1][1]*m[2][0] - m[0][1]*m[1][3]*m[2][0] - m[0][3]*m[1][0]*m[2][1] +
                  m[0][0]*m[1][3]*m[2][1] + m[0][1]*m[1][0]*m[2][3] - m[0][0]*m[1][1]*m[2][3];
      inv[3][0] = m[1][2]*m[2][1]*m[3][0] - m[1][1]*m[2][2]*m[3][0] - m[1][2]*m[2][0]*m[3][1] +
                  m[1][0]*m[2][2]*m[3][1] + m[1][1]*m[2][0]*m[3][2] - m[1][0]*m[2][1]*m[3][2];
      inv[3][1] = m[0][1]*m[2][2]*m[3][0] - m[0][2]*m[2][1]*m[3][0] + m[0][2]*m[2][0]*m[3][1] -
                  m[0][0]*m[2][2]*m[3][1] - m[0][1]*m[2][0]*m[3][2] + m[0][0]*m[2][1]*m[3][2];
      inv[3][2] = m[0][2]*m[1][1]*m[3][0] - m[0][1]*m[1][2]*m[3][0] - m[0][2]*m[1][0]*m[3][1] +
                  m[0][0]*m[1][2]*m[3][1] + m[0][1]*m[1][0]*m[3][2] - m[0][0]*m[1][1]*m[3][2];
      inv[3][3] = m[0][1]*m[1][2]*m[2][0] - m[0][2]*m[1][1]*m[2][0] + m[0][2]*m[1][0]*m[2][1] -
                  m[0][0]*m[1][2]*m[2][1] - m[0][1]*m[1][0]*m[2][2] + m[0][0]*m[1][1]*m[2][2];
      
      inv *= scale;
      return inv;
    }
    /* we couldn't invert matrix so return the original */
    return m;

}


template <typename T>
VrtMatrix3<T> inverse_transpose_33(const VrtMatrix4<T> &m)
{
    /* determinant is triple product of the column vectors */
    T det = dot( m[0].xyz(), cross( m[1].xyz(), m[2].xyz() ) );
    if( det != T(0) )
    {
        T scale = T(1) / det;
        return VrtMatrix3<T>( cross( m[1].xyz(), m[2].xyz() ) * scale,
                              cross( m[2].xyz(), m[0].xyz() ) * scale,
                              cross( m[0].xyz(), m[1].xyz() ) * scale );
    }
    else
    {
        VrtMatrix3<T> ret = m;
        /* we couldn't invert matrix so return the original */
        VRT_DEV_ASSERT(0);
        return ret;
    }
}


template <typename T>
VrtMatrix4<T> inverse_transpose_43(const VrtMatrix4<T> &m)
{
    T det = -m[0][2] * m[1][1] * m[2][0] +
             m[0][1] * m[1][2] * m[2][0] +
             m[0][2] * m[1][0] * m[2][1] -
             m[0][0] * m[1][2] * m[2][1] -
             m[0][1] * m[1][0] * m[2][2] +
             m[0][0] * m[1][1] * m[2][2];

    /* This does not protect against overflow when det is very small, but does
       at least guard against singular matrices with e.g. all zero elements */
    if( det != T( 0 ) )
    {
        T scale = T( 1 ) / det;
        VrtMatrix4<T> inv;
        inv[0][0] = -m[1][2]*m[2][1] + m[1][1]*m[2][2];
        inv[1][0] =  m[0][2]*m[2][1] - m[0][1]*m[2][2];
        inv[2][0] = -m[0][2]*m[1][1] + m[0][1]*m[1][2];
        inv[3][0] = T(0);
        inv[0][1] =  m[1][2]*m[2][0] - m[1][0]*m[2][2];
        inv[1][1] = -m[0][2]*m[2][0] + m[0][0]*m[2][2];
        inv[2][1] =  m[0][2]*m[1][0] - m[0][0]*m[1][2];
        inv[3][1] = T(0);
        inv[0][2] = -m[1][1]*m[2][0] + m[1][0]*m[2][1];
        inv[1][2] =  m[0][1]*m[2][0] - m[0][0]*m[2][1];
        inv[2][2] = -m[0][1]*m[1][0] + m[0][0]*m[1][1];
        inv[3][2] = T(0);
        inv[0][3] = m[1][2]*m[2][1]*m[3][0] - m[1][1]*m[2][2]*m[3][0] - m[1][2]*m[2][0]*m[3][1] +
                    m[1][0]*m[2][2]*m[3][1] + m[1][1]*m[2][0]*m[3][2] - m[1][0]*m[2][1]*m[3][2];
        inv[1][3] = m[0][1]*m[2][2]*m[3][0] - m[0][2]*m[2][1]*m[3][0] + m[0][2]*m[2][0]*m[3][1] -
                    m[0][0]*m[2][2]*m[3][1] - m[0][1]*m[2][0]*m[3][2] + m[0][0]*m[2][1]*m[3][2];
        inv[2][3] = m[0][2]*m[1][1]*m[3][0] - m[0][1]*m[1][2]*m[3][0] - m[0][2]*m[1][0]*m[3][1] +
                    m[0][0]*m[1][2]*m[3][1] + m[0][1]*m[1][0]*m[3][2] - m[0][0]*m[1][1]*m[3][2];
        inv[3][3] = det; /* will scale back to 1 */
        
        inv *= scale;
        inv[3][3] = T(1); /* set exactly to that comparisons in future will work */
        return inv;
    }
    /* we couldn't invert matrix so return the original */
    return m;
}


template <typename T>
VrtMatrix4<T> inverse_transpose(const VrtMatrix4<T> &m)
{
    /* If the bottom row is 0 0 0 1 do a much cheaper inverse */
    if( ( m[0][3] == T(0) ) && ( m[1][3] == T(0) ) &&
        ( m[2][3] == T(0) ) && ( m[3][3] == T(1) ) )
    {
        return inverse_transpose_43( m );
    }

    T det = m[0][3] * m[1][2] * m[2][1] * m[3][0] - m[0][2] * m[1][3] * m[2][1] * m[3][0] -
            m[0][3] * m[1][1] * m[2][2] * m[3][0] + m[0][1] * m[1][3] * m[2][2] * m[3][0] +
            m[0][2] * m[1][1] * m[2][3] * m[3][0] - m[0][1] * m[1][2] * m[2][3] * m[3][0] -
            m[0][3] * m[1][2] * m[2][0] * m[3][1] + m[0][2] * m[1][3] * m[2][0] * m[3][1] +
            m[0][3] * m[1][0] * m[2][2] * m[3][1] - m[0][0] * m[1][3] * m[2][2] * m[3][1] -
            m[0][2] * m[1][0] * m[2][3] * m[3][1] + m[0][0] * m[1][2] * m[2][3] * m[3][1] +
            m[0][3] * m[1][1] * m[2][0] * m[3][2] - m[0][1] * m[1][3] * m[2][0] * m[3][2] -
            m[0][3] * m[1][0] * m[2][1] * m[3][2] + m[0][0] * m[1][3] * m[2][1] * m[3][2] +
            m[0][1] * m[1][0] * m[2][3] * m[3][2] - m[0][0] * m[1][1] * m[2][3] * m[3][2] -
            m[0][2] * m[1][1] * m[2][0] * m[3][3] + m[0][1] * m[1][2] * m[2][0] * m[3][3] +
            m[0][2] * m[1][0] * m[2][1] * m[3][3] - m[0][0] * m[1][2] * m[2][1] * m[3][3] -
            m[0][1] * m[1][0] * m[2][2] * m[3][3] + m[0][0] * m[1][1] * m[2][2] * m[3][3];

    /* This does not protect against overflow when det is very small, but does
       at least guard against singular matrices with e.g. all zero elements */
    if( det != T( 0 ) )
    {
      T scale = T( 1 ) / det;
      VrtMatrix4<T> inv;
      inv[0][0] = m[1][2]*m[2][3]*m[3][1] - m[1][3]*m[2][2]*m[3][1] + m[1][3]*m[2][1]*m[3][2] -
                  m[1][1]*m[2][3]*m[3][2] - m[1][2]*m[2][1]*m[3][3] + m[1][1]*m[2][2]*m[3][3];
      inv[1][0] = m[0][3]*m[2][2]*m[3][1] - m[0][2]*m[2][3]*m[3][1] - m[0][3]*m[2][1]*m[3][2] +
                  m[0][1]*m[2][3]*m[3][2] + m[0][2]*m[2][1]*m[3][3] - m[0][1]*m[2][2]*m[3][3];
      inv[2][0] = m[0][2]*m[1][3]*m[3][1] - m[0][3]*m[1][2]*m[3][1] + m[0][3]*m[1][1]*m[3][2] -
                  m[0][1]*m[1][3]*m[3][2] - m[0][2]*m[1][1]*m[3][3] + m[0][1]*m[1][2]*m[3][3];
      inv[3][0] = m[0][3]*m[1][2]*m[2][1] - m[0][2]*m[1][3]*m[2][1] - m[0][3]*m[1][1]*m[2][2] +
                  m[0][1]*m[1][3]*m[2][2] + m[0][2]*m[1][1]*m[2][3] - m[0][1]*m[1][2]*m[2][3];
      inv[0][1] = m[1][3]*m[2][2]*m[3][0] - m[1][2]*m[2][3]*m[3][0] - m[1][3]*m[2][0]*m[3][2] +
                  m[1][0]*m[2][3]*m[3][2] + m[1][2]*m[2][0]*m[3][3] - m[1][0]*m[2][2]*m[3][3];
      inv[1][1] = m[0][2]*m[2][3]*m[3][0] - m[0][3]*m[2][2]*m[3][0] + m[0][3]*m[2][0]*m[3][2] -
                  m[0][0]*m[2][3]*m[3][2] - m[0][2]*m[2][0]*m[3][3] + m[0][0]*m[2][2]*m[3][3];
      inv[2][1] = m[0][3]*m[1][2]*m[3][0] - m[0][2]*m[1][3]*m[3][0] - m[0][3]*m[1][0]*m[3][2] +
                  m[0][0]*m[1][3]*m[3][2] + m[0][2]*m[1][0]*m[3][3] - m[0][0]*m[1][2]*m[3][3];
      inv[3][1] = m[0][2]*m[1][3]*m[2][0] - m[0][3]*m[1][2]*m[2][0] + m[0][3]*m[1][0]*m[2][2] -
                  m[0][0]*m[1][3]*m[2][2] - m[0][2]*m[1][0]*m[2][3] + m[0][0]*m[1][2]*m[2][3];
      inv[0][2] = m[1][1]*m[2][3]*m[3][0] - m[1][3]*m[2][1]*m[3][0] + m[1][3]*m[2][0]*m[3][1] -
                  m[1][0]*m[2][3]*m[3][1] - m[1][1]*m[2][0]*m[3][3] + m[1][0]*m[2][1]*m[3][3];
      inv[1][2] = m[0][3]*m[2][1]*m[3][0] - m[0][1]*m[2][3]*m[3][0] - m[0][3]*m[2][0]*m[3][1] +
                  m[0][0]*m[2][3]*m[3][1] + m[0][1]*m[2][0]*m[3][3] - m[0][0]*m[2][1]*m[3][3];
      inv[2][2] = m[0][1]*m[1][3]*m[3][0] - m[0][3]*m[1][1]*m[3][0] + m[0][3]*m[1][0]*m[3][1] -
                  m[0][0]*m[1][3]*m[3][1] - m[0][1]*m[1][0]*m[3][3] + m[0][0]*m[1][1]*m[3][3];
      inv[3][2] = m[0][3]*m[1][1]*m[2][0] - m[0][1]*m[1][3]*m[2][0] - m[0][3]*m[1][0]*m[2][1] +
                  m[0][0]*m[1][3]*m[2][1] + m[0][1]*m[1][0]*m[2][3] - m[0][0]*m[1][1]*m[2][3];
      inv[0][3] = m[1][2]*m[2][1]*m[3][0] - m[1][1]*m[2][2]*m[3][0] - m[1][2]*m[2][0]*m[3][1] +
                  m[1][0]*m[2][2]*m[3][1] + m[1][1]*m[2][0]*m[3][2] - m[1][0]*m[2][1]*m[3][2];
      inv[1][3] = m[0][1]*m[2][2]*m[3][0] - m[0][2]*m[2][1]*m[3][0] + m[0][2]*m[2][0]*m[3][1] -
                  m[0][0]*m[2][2]*m[3][1] - m[0][1]*m[2][0]*m[3][2] + m[0][0]*m[2][1]*m[3][2];
      inv[2][3] = m[0][2]*m[1][1]*m[3][0] - m[0][1]*m[1][2]*m[3][0] - m[0][2]*m[1][0]*m[3][1] +
                  m[0][0]*m[1][2]*m[3][1] + m[0][1]*m[1][0]*m[3][2] - m[0][0]*m[1][1]*m[3][2];
      inv[3][3] = m[0][1]*m[1][2]*m[2][0] - m[0][2]*m[1][1]*m[2][0] + m[0][2]*m[1][0]*m[2][1] -
                  m[0][0]*m[1][2]*m[2][1] - m[0][1]*m[1][0]*m[2][2] + m[0][0]*m[1][1]*m[2][2];
      
      inv *= scale;
      return inv;
    }
    /* we couldn't invert matrix so return the original */
    return m;
}



typedef VrtMatrix3<vrt_float> VrtMatrix3f;
typedef VrtMatrix4<vrt_float> VrtMatrix4f;

#endif

