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
 *  vrt_vector.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VRT_VECTOR_H__
#define __VRT_VECTOR_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vrt_datatype.h"
#include "vrt_math.h"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 
template <typename T> struct VrtVector2;
template <typename T> struct VrtVector3;
template <typename T> struct VrtVector4;


/***************************************************************************** 
 * Template VrtVector2
 *****************************************************************************/
 
template <typename T>
struct VrtVector2
{
    VrtVector2();

    VrtVector2(T v);

    VrtVector2(const T *v);

    VrtVector2(T _x, T _y);

    VrtVector2(const VrtVector3<T> & v);

    T & operator [] (vrt_u32 i);

    const T & operator [] (vrt_u32 i) const;

    template <typename S>
    VrtVector2 & operator += (S v);

    template <typename S>
    VrtVector2 & operator -= (S v);
    
    template <typename S>
    VrtVector2 & operator *= (S v);

    template <typename S>
    VrtVector2 & operator /= (S v);

    VrtVector2 & operator += (const VrtVector2 &v);
                              
    VrtVector2 & operator -= (const VrtVector2 &v);
                              
    VrtVector2 & operator *= (const VrtVector2 &v);
                              
    VrtVector2 & operator /= (const VrtVector2 &v);
 
    T x, y;
};


template <typename T>
vrt_bool operator == (const VrtVector2<T> &a, const VrtVector2<T> &b);
                                              
template <typename T>                         
vrt_bool operator != (const VrtVector2<T> &a, const VrtVector2<T> &b);

template <typename T>
VrtVector2<T> operator - (const VrtVector2<T> &a);
                          
template <typename T, typename S>
VrtVector2<T> operator + (const VrtVector2<T> &a, S v);
                          
template <typename T, typename S>
VrtVector2<T> operator - (const VrtVector2<T> &a, S v);
                          
template <typename T, typename S>
VrtVector2<T> operator * (const VrtVector2<T> &a, S v);
                          
template <typename T, typename S>
VrtVector2<T> operator / (const VrtVector2<T> &a, S v);

template <typename T>
VrtVector2<T> operator + (const VrtVector2<T> &a, const VrtVector2<T> &b);
                                                  
template <typename T>                             
VrtVector2<T> operator - (const VrtVector2<T> &a, const VrtVector2<T> &b);
                                                  
template <typename T>                             
VrtVector2<T> operator * (const VrtVector2<T> &a, const VrtVector2<T> &b);
                                                  
template <typename T>                             
VrtVector2<T> operator / (const VrtVector2<T> &a, const VrtVector2<T> &b);

template <typename T>
T dot(const VrtVector2<T> &a, const VrtVector2<T> &b);

template <typename T>
T length(const VrtVector2<T> &v);

template <typename T>
T length2(const VrtVector2<T> &v);

template <typename T>
T distance(const VrtVector2<T> &a, const VrtVector2<T> &b);

template <typename T>
T distance2(const VrtVector2<T> &a, const VrtVector2<T> &b);

template <typename T>
VrtVector2<T> normalize(const VrtVector2<T> &v);


/***************************************************************************** 
 * Template VrtVector3
 *****************************************************************************/
 
template <typename T>
struct VrtVector3
{
    VrtVector3();

    VrtVector3(T v);

    VrtVector3(const T *v);

    VrtVector3(T _x, T _y, T _z);

    VrtVector3(const VrtVector4<T> &v);

    T & operator [] (vrt_u32 i);

    const T & operator [] (vrt_u32 i) const;

    VrtVector3 & operator = (const VrtVector4<T> &v);

    template <typename S>
    VrtVector3 & operator += (S s);

    template <typename S>
    VrtVector3 & operator -= (S s);

    template <typename S>
    VrtVector3 & operator *= (S s);

    template <typename S>
    VrtVector3 & operator /= (S s);

    VrtVector3 & operator += (const VrtVector3 &v);
                                         
    VrtVector3 & operator -= (const VrtVector3 &v);
                                         
    VrtVector3 & operator *= (const VrtVector3 &v);
                                         
    VrtVector3 & operator /= (const VrtVector3 &v);
    
    VrtVector2<T> & xy();

    const VrtVector2<T> & xy() const;

    T x, y, z;
};


template <typename T>
vrt_bool operator == (const VrtVector3<T> &a, const VrtVector3<T> &b);

template <typename T>
vrt_bool operator != (const VrtVector3<T> &a, const VrtVector3<T> &b);

template <typename T>
VrtVector3<T> operator - (const VrtVector3<T> &a);

template <typename T, typename S>
VrtVector3<T> operator + (const VrtVector3<T> &a, S v);

template <typename T, typename S>
VrtVector3<T> operator - (const VrtVector3<T> &a, S v);

template <typename T, typename S>
VrtVector3<T> operator * ( const VrtVector3<T>&a, S v);

template <typename T, typename S>
VrtVector3<T> operator / (const VrtVector3<T> &a, S v);

template <typename T>
VrtVector3<T> operator + (const VrtVector3<T> &a, const VrtVector3<T> &b);

template <typename T>
VrtVector3<T> operator - (const VrtVector3<T> &a, const VrtVector3<T> &b);

template <typename T>
VrtVector3<T> operator * (const VrtVector3<T> &a, const VrtVector3<T> &b);

template <typename T>
VrtVector3<T> operator / (const VrtVector3<T> &a, const VrtVector3<T> &b);

template <typename T>
T dot(const VrtVector3<T> &a, const VrtVector3<T> &b);

template <typename T>
T length(const VrtVector3<T> &v);

template <typename T>
T length2(const VrtVector3<T> &v);

template <typename T>
T distance(const VrtVector3<T> &a, const VrtVector3<T> &b);

template <typename T>
T distance2(const VrtVector3<T> &a, const VrtVector3<T> &b);

template <typename T>
VrtVector3<T> cross(const VrtVector3<T> &a, const VrtVector3<T> &b);

template <typename T>
VrtVector3<T> normalize(const VrtVector3<T> &a);


/***************************************************************************** 
 * Template VrtVector4
 *****************************************************************************/
 
template <typename T>
struct VrtVector4
{
    VrtVector4();

    VrtVector4(T v);

    VrtVector4(const T *v);

    VrtVector4(T _x, T _y, T _z, T _w);

    VrtVector4(VrtVector3<T> _v, T _w);

    T & operator [] (vrt_u32 i);

    const T & operator [] (vrt_u32 i) const;

    template <typename S>
    VrtVector4 & operator += (S v);

    template <typename S>
    VrtVector4 & operator -= (S v);

    template <typename S>
    VrtVector4 & operator *= (S v);

    template <typename S>
    VrtVector4 & operator /= (S v);

    VrtVector4 & operator += (const VrtVector4 &v);
                                        
    VrtVector4 & operator -= (const VrtVector4 &v);
                                        
    VrtVector4 & operator *= (const VrtVector4 &v);
                                        
    VrtVector4 & operator /= (const VrtVector4 &v);
    
    VrtVector2<T> & xy();

    const VrtVector2<T> & xy() const;
    
    VrtVector3<T> & xyz();

    const VrtVector3<T> & xyz() const;

    T x, y, z, w;
};


template <typename T>
vrt_bool operator == (const VrtVector4<T> &a, const VrtVector4<T> &b);

template <typename T>
vrt_bool operator != (const VrtVector4<T> &a, const VrtVector4<T> &b);

template <typename T>
VrtVector4<T> operator - (const VrtVector4<T> &a);

template <typename T, typename S>
VrtVector4<T> operator + (const VrtVector4<T> &a, S v);

template <typename T, typename S>
VrtVector4<T> operator - (const VrtVector4<T> &a, S v);

template <typename T, typename S>
VrtVector4<T> operator * (const VrtVector4<T> &a, S v);

template <typename T, typename S>
VrtVector4<T> operator / (const VrtVector4<T> &a, S v);

template <typename T>
VrtVector4<T> operator + (const VrtVector4<T> &a, const VrtVector4<T> &b);

template <typename T>
VrtVector4<T> operator - (const VrtVector4<T> &a, const VrtVector4<T> &b);

template <typename T>
VrtVector4<T> operator * (const VrtVector4<T> &a, const VrtVector4<T> &b);

template <typename T>
VrtVector4<T> operator / (const VrtVector4<T> &a, const VrtVector4<T> &b);

template <typename T>
T dot(const VrtVector4<T> &a, const VrtVector4<T> &b);

template <typename T>
T length(const VrtVector4<T> &v);

template <typename T>
T length2(const VrtVector4<T> &v);

template <typename T>
T distance(const VrtVector4<T> &a, const VrtVector4<T> &b);

template <typename T>
T distance2(const VrtVector4<T> &a, const VrtVector4<T> &b);

template <typename T>
VrtVector4<T> normalize(const VrtVector4<T> &a);


/***************************************************************************** 
 * Template VrtVector2 Implementation
 *****************************************************************************/
 
template <typename T>
VrtVector2<T>::VrtVector2()
: x(0), y(0)
{
}

template <typename T>
VrtVector2<T>::VrtVector2(T v) 
: x(v), y(v)
{
}

template <typename T>
VrtVector2<T>::VrtVector2(const T *v)
: x(v[0]), y(v[1])
{
}

template <typename T>
VrtVector2<T>::VrtVector2(T _x, T _y) 
: x(_x), y(_y)
{
}

template <typename T>
VrtVector2<T>::VrtVector2(const VrtVector3<T> & v)
: x(v.x), y(v.y)
{
}

template <typename T>
T & VrtVector2<T>::operator [] (vrt_u32 i)
{
    return ((T *)this)[i];
}

template <typename T>
const T & VrtVector2<T>::operator [] (vrt_u32 i) const
{
    return ((T *)this)[i];
}


template <typename T> template <typename S>
VrtVector2<T> & VrtVector2<T>::operator += (S v)
{
    x += v;
    y += v;
    return *this;
}


template <typename T> template <typename S>
VrtVector2<T> & VrtVector2<T>::operator -= (S v)
{
    x -= v;
    y -= v;
    return *this;
}

template <typename T> template <typename S>
VrtVector2<T> & VrtVector2<T>::operator *= (S v)
{
    x *= v;
    y *= v;
    return *this;
}


template <typename T> template <typename S>
VrtVector2<T> & VrtVector2<T>::operator /= (S v)
{
    x /= v;
    y /= v;
    return *this;
}

template <typename T>
VrtVector2<T> & VrtVector2<T>::operator += (const VrtVector2<T> &v)
{                                           
    x += v.x;                               
    y += v.y;                               
    return *this;                           
}                                           
                                            
template <typename T>                       
VrtVector2<T> & VrtVector2<T>::operator -= (const VrtVector2<T> &v)
{                                           
    x -= v.x;                               
    y -= v.y;                               
    return *this;                           
}                                           
                                            
template <typename T>                       
VrtVector2<T> & VrtVector2<T>::operator *= (const VrtVector2<T> &v)
{                                           
    x *= v.x;                               
    y *= v.y;                               
    return *this;                           
}                                           
                                            
template <typename T>                       
VrtVector2<T> & VrtVector2<T>::operator /= (const VrtVector2<T> &v)
{
    x /= v.x;
    y /= v.y;
    return *this;
}



template <typename T>
VrtVector2<T> operator - (VrtVector2<T> const &a)
{
    return VrtVector2<T>(-a.x, -a.y);
}

template <typename T, typename S>
VrtVector2<T> operator + (const VrtVector2<T> &a, S v)
{
    return VrtVector2<T>(a.x + v, a.y + v);
}

template <typename T, typename S>
VrtVector2<T> operator - (const VrtVector2<T> &a, S v)
{
    return VrtVector2<T>(a.x - v, a.y - v);
}

template <typename T, typename S>
VrtVector2<T> operator * (const VrtVector2<T> &a, S v)
{
    return VrtVector2<T>(a.x * v, a.y * v);
}

template <typename T, typename S>
VrtVector2<T> operator / (const VrtVector2<T> &a, S v)
{
    return VrtVector2<T>(a.x / v, a.y / v);
}


template <typename T>
VrtVector2<T> operator + (const VrtVector2<T> &a, const VrtVector2<T> &b)
{                                                 
    return VrtVector2<T>(a.x + b.x, a.y + b.y);   
}                                                 
                                                  
template <typename T>                             
VrtVector2<T> operator - (const VrtVector2<T> &a, const VrtVector2<T> &b)
{                                                 
    return VrtVector2<T>(a.x - b.x, a.y - b.y);   
}                                                 
                                                  
template <typename T>                             
VrtVector2<T> operator * (const VrtVector2<T> &a, const VrtVector2<T> &b)
{                                                 
    return VrtVector2<T>(a.x * b.x, a.y * b.y);   
}                                                 
                                                  
template <typename T>                             
VrtVector2<T> operator / (const VrtVector2<T> &a, const VrtVector2<T> &b)
{
    return VrtVector2<T>(a.x / b.x, a.y / b.y);
}

template <typename T>
vrt_bool operator == (const VrtVector2<T> &a, const VrtVector2<T> &b)
{                                             
    return (a.x == b.x) && (a.y == b.y);
}                                             
                                              
template <typename T>                         
vrt_bool operator != (const VrtVector2<T> &a, const VrtVector2<T> &b)
{
    return (a.x != b.x) || (a.y != b.y);
}

template <typename T>
T dot(const VrtVector2<T> &a, const VrtVector2<T> &b)
{
    return a.x * b.x + a.y * b.y;
}

template <typename T>
T length(const VrtVector2<T> &v)
{
    return T( vrt_sqrt( dot(v, v) ) );
}

template <typename T>
T length2(const VrtVector2<T> &v)
{
    return T( dot(v, v) );
}

template <typename T>
T distance(const VrtVector2<T> &a, const VrtVector2<T> &b)
{
    return length(a - b);
}

template <typename T>
T distance2(const VrtVector2<T> &a, const VrtVector2<T> &b)
{
    return length2(a - b);
}

template <typename T>
VrtVector2<T> normalize(const VrtVector2<T> &v)
{
    T l = length(v);
    if( l > 0 )
    {
        return v / l;
    }
    else
    {
        VRT_DEV_ASSERT(l == 0);
        return v;
    }
}


/***************************************************************************** 
 * Template VrtVector3 Implementation
 *****************************************************************************/
 
template <typename T>
VrtVector3<T>::VrtVector3()
: x(0), y(0), z(0)
{
}

template <typename T>
VrtVector3<T>::VrtVector3(T v)
: x(v), y(v), z(v)
{
}

template <typename T>
VrtVector3<T>::VrtVector3(const T *v)
: x(v[0]), y(v[1]), z(v[2])
{
}

template <typename T>
VrtVector3<T>::VrtVector3(T _x, T _y, T _z)
: x(_x), y(_y), z(_z)
{
}

template <typename T>
VrtVector3<T>::VrtVector3(const VrtVector4<T> & v)
: x(v.x), y(v.y), z(v.z)
{
}

template <typename T>
VrtVector3<T> & VrtVector3<T>::operator = (const VrtVector4<T> & v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

template <typename T>
T & VrtVector3<T>::operator [] (vrt_u32 i)
{
    return ((T *)this)[i];
}

template <typename T>
const T & VrtVector3<T>::operator [] (vrt_u32 i) const
{
    return ((T *)this)[i];
}

template <typename T> template <typename S>
VrtVector3<T> & VrtVector3<T>::operator += (S v)
{
    x += v;
    y += v;
    z += v;
    return *this;
}

template <typename T> template <typename S>
VrtVector3<T> & VrtVector3<T>::operator -= (S v)
{
    x -= v;
    y -= v;
    z -= v;
    return *this;
}

template <typename T> template <typename S>
VrtVector3<T> & VrtVector3<T>::operator *= (S v)
{
    x *= v;
    y *= v;
    z *= v;
    return *this;
}

template <typename T> template <typename S>
VrtVector3<T> & VrtVector3<T>::operator /= (S v)
{
    x /= v;
    y /= v;
    z /= v;
    return *this;
}

template <typename T>
VrtVector3<T> & VrtVector3<T>::operator += (VrtVector3<T> const &v)
{                                                         
    x += v.x;                                             
    y += v.y;                                             
    z += v.z;                                             
    return *this;                                         
}                                                         
                                                          
template <typename T>                                     
VrtVector3<T> & VrtVector3<T>::operator -= (VrtVector3<T> const &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

template <typename T>
VrtVector3<T> & VrtVector3<T>::operator *= (const VrtVector3<T> &v)
{
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
}

template <typename T>
VrtVector3<T> & VrtVector3<T>::operator /= (const VrtVector3<T> &v)
{
    x /= v.x;
    y /= v.y;
    z /= v.z;
    return *this;
}

template <typename T>
VrtVector2<T> & VrtVector3<T>::xy()
{
    return *(VrtVector2<T> *)this;
}

template <typename T>
const VrtVector2<T> & VrtVector3<T>::xy() const
{
    return *(const VrtVector2<T> *)this;
}


template <typename T>
vrt_bool operator == (const VrtVector3<T> &a, const VrtVector3<T> &b)
{
    return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
}

template <typename T>
vrt_bool operator != (const VrtVector3<T> &a, const VrtVector3<T> &b)
{
    return (a.x != b.x) || (a.y != b.y) || (a.z != b.z);
}

template <typename T>
VrtVector3<T> operator - (const VrtVector3<T> &a)
{
    return VrtVector3<T>(-a.x, -a.y, -a.z);
}

template <typename T, typename S>
VrtVector3<T> operator + (const VrtVector3<T> &a, S v)
{
    return VrtVector3<T>(a.x + v, a.y + v, a.z + v);
}

template <typename T, typename S>
VrtVector3<T> operator - (const VrtVector3<T> &a, S v)
{
    return VrtVector3<T>(a.x - v, a.y - v, a.z - v);
}

template <typename T, typename S>
VrtVector3<T> operator * ( const VrtVector3<T>&a, S v)
{
    return VrtVector3<T>(a.x * v, a.y * v, a.z * v);
}

template <typename T, typename S>
VrtVector3<T> operator / (const VrtVector3<T> &a, S v)
{
    return VrtVector3<T>(a.x / v, a.y / v, a.z / v);
}

template <typename T>
VrtVector3<T> operator + (const VrtVector3<T> &a, const VrtVector3<T> &b)
{
    return VrtVector3<T>(a.x + b.x, a.y + b.y, a.z + b.z);
}

template <typename T>
VrtVector3<T> operator - (const VrtVector3<T> &a, const VrtVector3<T> &b)
{
    return VrtVector3<T>(a.x - b.x, a.y - b.y, a.z - b.z);
}

template <typename T>
VrtVector3<T> operator * (const VrtVector3<T> &a, const VrtVector3<T> &b)
{
    return VrtVector3<T>(a.x * b.x, a.y * b.y, a.z * b.z);
}

template <typename T>
VrtVector3<T> operator / (const VrtVector3<T> &a, const VrtVector3<T> &b)
{
    return VrtVector3<T>(a.x / b.x, a.y / b.y, a.z / b.z);
}

template <typename T>
T dot(const VrtVector3<T> &a, const VrtVector3<T> &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

template <typename T>
T length(const VrtVector3<T> &v)
{
    return T( vrt_sqrt( dot(v, v) ) );
}

template <typename T>
T length2(const VrtVector3<T> &v)
{
    return T( dot(v, v) );
}

template <typename T>
T distance(const VrtVector3<T> &a, const VrtVector3<T> &b)
{
    return length(a - b);
}

template <typename T>
T distance2(const VrtVector3<T> &a, const VrtVector3<T> &b)
{
    return length2(a - b);
}

template <typename T>
VrtVector3<T> cross(const VrtVector3<T> &a, const VrtVector3<T> &b)
{
    return VrtVector3<T>( a.y * b.z - b.y * a.z,
                          b.x * a.z - a.x * b.z,
                          a.x * b.y - b.x * a.y );
}

template <typename T>
VrtVector3<T> normalize(const VrtVector3<T> &a)
{
    T l = length(a);
    if( l > T(0) )
    {
        return a / l;
    }
    else
    {
        VRT_DEV_ASSERT(l == 0);
        return a;
    }
}


/***************************************************************************** 
 * Template VrtVector4 Implementation
 *****************************************************************************/
 
template <typename T>
VrtVector4<T>::VrtVector4()
: x(0), y(0), z(0), w(0)
{
}

template <typename T>
VrtVector4<T>::VrtVector4(T v)
: x(v), y(v), z(v), w(v)
{
}

template <typename T>
VrtVector4<T>::VrtVector4(const T *v)
: x(v[0]), y(v[1]), z(v[2]), w(v[3])
{
}

template <typename T>
VrtVector4<T>::VrtVector4(T _x, T _y, T _z, T _w)
: x(_x), y(_y), z(_z), w(_w)
{
}

template <typename T>
VrtVector4<T>::VrtVector4(VrtVector3<T> _v, T _w)
: x(_v.x), y(_v.y), z(_v.z), w(_w)
{
}


template <typename T>
T & VrtVector4<T>::operator [] (vrt_u32 i)
{
    return ((T *)this)[i];
}

template <typename T>
const T & VrtVector4<T>::operator [] (vrt_u32 i) const
{
    return ((T *)this)[i];
}


template <typename T> template <typename S>
VrtVector4<T> & VrtVector4<T>::operator += (S v)
{
    x += v;
    y += v;
    z += v;
    w += v;
    return *this;
}


template <typename T> template <typename S>
VrtVector4<T> & VrtVector4<T>::operator -= (S v)
{
    x -= v;
    y -= v;
    z -= v;
    w -= v;
    return *this;
}


template <typename T> template <typename S>
VrtVector4<T> & VrtVector4<T>::operator *= (S v)
{
    x *= v;
    y *= v;
    z *= v;
    w *= v;
    return *this;
}


template <typename T> template <typename S>
VrtVector4<T> & VrtVector4<T>::operator /= (S v)
{
    x /= v;
    y /= v;
    z /= v;
    w /= v;
    return *this;
}


template <typename T>
VrtVector4<T> & VrtVector4<T>::operator += (const VrtVector4<T> &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
}

template <typename T>
VrtVector4<T> & VrtVector4<T>::operator -= (const VrtVector4<T> &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return *this;
}


template <typename T>
VrtVector4<T> & VrtVector4<T>::operator *= (const VrtVector4<T> &v)
{
    x *= v.x;
    y *= v.y;
    z *= v.z;
    w *= v.w;
    return *this;
}

template <typename T>
VrtVector4<T> & VrtVector4<T>::operator /= (const VrtVector4<T> &v)
{
    x /= v.x;
    y /= v.y;
    z /= v.z;
    w /= v.w;
    return *this;
}

template <typename T>
VrtVector2<T> & VrtVector4<T>::xy()
{
    return *(VrtVector2<T> *)this;
}

template <typename T>
const VrtVector2<T> & VrtVector4<T>::xy() const
{
    return *(const VrtVector2<T> *)this;
}

template <typename T>
VrtVector3<T> & VrtVector4<T>::xyz()
{
    return *(VrtVector3<T> *)this;
}

template <typename T>
const VrtVector3<T> & VrtVector4<T>::xyz() const
{
    return *(const VrtVector3<T> *)this;
}


template <typename T>
vrt_bool operator == (const VrtVector4<T> &a, const VrtVector4<T> &b)
{
    return (a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w);
}

template <typename T>
vrt_bool operator != (const VrtVector4<T> &a, const VrtVector4<T> &b)
{
    return (a.x != b.x) || (a.y != b.y) || (a.z != b.z) || (a.w != b.w);
}

template <typename T>
VrtVector4<T> operator - (const VrtVector4<T> &a)
{
    return VrtVector4<T>(-a.x, -a.y, -a.z, -a.w);
}

template <typename T, typename S>
VrtVector4<T> operator + (const VrtVector4<T> &a, S v)
{
    return VrtVector4<T>(a.x + v, a.y + v, a.z + v, a.w + v);
}

template <typename T, typename S>
VrtVector4<T> operator - (const VrtVector4<T> &a, S v)
{
    return VrtVector4<T>(a.x - v, a.y - v, a.z - v, a.w - v);
}

template <typename T, typename S>
VrtVector4<T> operator * (const VrtVector4<T> &a, S v)
{
    return VrtVector4<T>(a.x * v, a.y * v, a.z * v, a.w * v);
}

template <typename T, typename S>
VrtVector4<T> operator / (const VrtVector4<T> &a, S v)
{
    return VrtVector4<T>(a.x / v, a.y / v, a.z / v, a.w / v);
}

template <typename T>
VrtVector4<T> operator + (const VrtVector4<T> &a, const VrtVector4<T> &b)
{
    return VrtVector4<T>(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

template <typename T>
VrtVector4<T> operator - (const VrtVector4<T> &a, const VrtVector4<T> &b)
{
    return VrtVector4<T>(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

template <typename T>
VrtVector4<T> operator * (const VrtVector4<T> &a, const VrtVector4<T> &b)
{
    return VrtVector4<T>(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
}

template <typename T>
VrtVector4<T> operator / (const VrtVector4<T> &a, const VrtVector4<T> &b)
{
    return VrtVector4<T>(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
}

template <typename T>
T dot(const VrtVector4<T> &a, const VrtVector4<T> &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

template <typename T>
T length(const VrtVector4<T> &v)
{
    return T( vrt_sqrt( dot(v, v) ) );
}

template <typename T>
T length2(const VrtVector4<T> &v)
{
    return T( dot(v, v) );
}

template <typename T>
T distance(const VrtVector4<T> &a, const VrtVector4<T> &b)
{
    return length(a - b);
}

template <typename T>
T distance2(const VrtVector4<T> &a, const VrtVector4<T> &b)
{
    return length2(a - b);
}

template <typename T>
VrtVector4<T> normalize(const VrtVector4<T> &a)
{
    T l = length(a);
    if( l > T(0) )
    {
        return a / l;
    }
    else
    {
        VRT_DEV_ASSERT(l == 0);
        return a;
    }
}


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 
typedef VrtVector2<vrt_bool> VrtVector2b;
typedef VrtVector3<vrt_bool> VrtVector3b;
typedef VrtVector4<vrt_bool> VrtVector4b;

typedef VrtVector2<vrt_s16> VrtVector2s;
typedef VrtVector3<vrt_s16> VrtVector3s;
typedef VrtVector4<vrt_s16> VrtVector4s;

typedef VrtVector2<vrt_u16> VrtVector2us;
typedef VrtVector3<vrt_u16> VrtVector3us;
typedef VrtVector4<vrt_u16> VrtVector4us;

typedef VrtVector2<vrt_s32> VrtVector2i;
typedef VrtVector3<vrt_s32> VrtVector3i;
typedef VrtVector4<vrt_s32> VrtVector4i;

typedef VrtVector2<vrt_u32> VrtVector2ui;
typedef VrtVector3<vrt_u32> VrtVector3ui;
typedef VrtVector4<vrt_u32> VrtVector4ui;

typedef VrtVector2<vrt_float> VrtVector2f;
typedef VrtVector3<vrt_float> VrtVector3f;
typedef VrtVector4<vrt_float> VrtVector4f;


#endif /* __VRT_VECTOR_H__ */


