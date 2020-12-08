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
 *  vrt_base_type.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VRT_BASE_TYPE__
#define __VRT_BASE_TYPE__

#include "vrt_datatype.h"
#include "vrt_obj_base.h"

template <class T>
class VrtPoint :
    public VrtObjBase
{
public:
    VrtPoint() : x(0), y(0) {}
    VrtPoint(T x, T y) : x(x), y(y) {}

    VrtPoint& operator += (const VrtPoint &p)
    {
        x += p.x;
        y += p.y;
        return *this;
    }
    
    VrtPoint& operator -= (const VrtPoint &p)
    {
        x += p.x;
        y += p.y;
        return *this;
    }

    T x, y;
};

template <class T>
class VrtRect :
    public VrtObjBase
{
public:
    VrtRect() : origin(0), size(0) {}
    VrtRect(T x, T y, T w, T h) : x(x), y(y), w(w), h(h) {}
    VrtRect(VrtPoint<T> origin, VrtPoint<T> size) : origin(origin), size(size) {}

    union
    {
        struct { T x, y, w, h; };
        struct { VrtPoint<T> origin, size; };
    };
};


// Partial Specialization

template <>
class VrtPoint<vrt_s32>
{
public:
    VrtPoint(vrt_point_struct &p) : x(p.x), y(p.y) {}

    operator vrt_point_struct & () const { return *(vrt_point_struct *)this; }

    vrt_s32 x, y;
};


template <>
class VrtPoint<vrt_float>
{
public:
    VrtPoint(vrt_fpoint_struct &p) : x(p.x), y(p.y) {}

    operator vrt_fpoint_struct & () const { return *(vrt_fpoint_struct *)this; }

    vrt_float x, y;
};


template <>
class VrtRect<vrt_s32>
{
public:
    VrtRect(vrt_rect_struct &r) : origin(r.origin), size(r.size) {}

    operator vrt_rect_struct & () const { return *(vrt_rect_struct )this; }

    union
    {
        struct { vrt_s32 x, y, w, h; };
        struct { VrtPoint<vrt_s32> origin;
                 VrtSize<vrt_s32> size; };
    };
};


#endif