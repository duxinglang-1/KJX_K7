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
 *  vfx_basic_type.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus UI Basic Type Classes
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
#ifndef __VFX_BASIC_TYPE_H__
#define __VFX_BASIC_TYPE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxBase 
#include "vfx_cpp_base.h"

#include "vrt_datatype.h"
#include "vfx_datatype.h"
#include "vfx_system.h"

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
#include "vpi_datatype.h"

extern VRT_RET_VALUE_IN_REGS vm_fpoint_struct vm_fpoint_make(VMFLOAT x, VMFLOAT y);
extern VRT_RET_VALUE_IN_REGS vm_point_struct vm_point_make(VMINT32 x, VMINT32 y);
extern VRT_RET_VALUE_IN_REGS vm_size_struct vm_size_make(VMINT32 width, VMINT32 height);
extern VRT_RET_VALUE_IN_REGS vm_rect_struct vm_rect_make(VMINT32 x, VMINT32 y, VMINT32 width, VMINT32 height);

#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/

// Define a VfxFPoint with zero x and y coordinate.
// SEE ALSO: VfxFPoint
#define VFX_FPOINT_ZERO                  VfxFPoint(0.0f, 0.0f)

// Define a VfxPoint with zero x and y coordinate.
// SEE ALSO: VfxPoint
#define VFX_POINT_ZERO                   VfxPoint(0, 0)

// Define a VfxSize with zero width and height.
// SEE ALSO: VfxSize
#define VFX_SIZE_ZERO                    VfxSize(0, 0)

// Define a VfxRect with zero origin and size.
// SEE ALSO: VfxRect
#define VFX_RECT_ZERO                    VfxRect(0, 0, 0, 0)

// Define a VfxColor with opaque black color
// SEE ALSO: VfxColor
#define VFX_COLOR_BLACK                  VRT_COLOR_BLACK
// Define a VfxColor with opaque white color
// SEE ALSO: VfxColor
#define VFX_COLOR_WHITE                  VRT_COLOR_WHITE
// Define a VfxColor with opaque red color
// SEE ALSO: VfxColor
#define VFX_COLOR_RED                    VRT_COLOR_RED
// Define a VfxColor with opaque green color
// SEE ALSO: VfxColor
#define VFX_COLOR_GREEN                  VRT_COLOR_GREEN
// Define a VfxColor with opaque blue color
// SEE ALSO: VfxColor
#define VFX_COLOR_BLUE                   VRT_COLOR_BLUE
// Define a VfxColor with opaque aqua color
// SEE ALSO: VfxColor
#define VFX_COLOR_AQUA                   VRT_COLOR_AQUA
// Define a VfxColor with opaque fuchsia color
// SEE ALSO: VfxColor
#define VFX_COLOR_FUCHSIA                VRT_COLOR_FUCHSIA
// Define a VfxColor with opaque yellow color
// SEE ALSO: VfxColor
#define VFX_COLOR_YELLOW                 VRT_COLOR_YELLOW
// Define a VfxColor with opaque grey color (50% grey)
// SEE ALSO: VfxColor
#define VFX_COLOR_GREY                   VRT_COLOR_GREY
// Define a VfxColor with opaque teal color
// SEE ALSO: VfxColor
#define VFX_COLOR_TEAL                   VRT_COLOR_TEAL
// Define a VfxColor with opaque purple color
// SEE ALSO: VfxColor
#define VFX_COLOR_PURPLE                 VRT_COLOR_PURPLE
// Define a VfxColor with opaque olive color
// SEE ALSO: VfxColor
#define VFX_COLOR_OLIVE                  VRT_COLOR_OLIVE
// Define a VfxColor with opaque silver color (75% grey)
// SEE ALSO: VfxColor
#define VFX_COLOR_SILVER                 VRT_COLOR_SILVER
// Define a VfxColor with full transparent blue color (alpha = 0)
// SEE ALSO: VfxColor
#define VFX_COLOR_TRANSPARENT            VRT_COLOR_TRANSPARENT
// Define a VfxColor with zero value (all = 0)
// SEE ALSO: VfxColor
#define VFX_COLOR_NULL                   VRT_COLOR_NULL

/*
 * Define a VfxColor with a resource ID.
 *
 * EXAMPLE:
 * <code>
 *  color = VFX_COLOR_RES(COLOR_ID_HELLO);
 * </code>
 */
#define VFX_COLOR_RES(_id)                  VfxColor(VfxColorResHelper((VfxResId)(_id)))


/***************************************************************************** 
 * Class VfxFPoint
 *****************************************************************************/

/*
 * Class VfxFPoint is as like as VfxPoint, represents a point in 2D coordinate system. 
 *  Each coordinate data type is VfxFloat.
 *
 * See ALSO: VfxPoint
 */
class VfxFPoint : public VfxBase
{
// Variable
public:
    // The x-coordinate of the point
    VfxFloat x;
    // The y-coordinate of the point
    VfxFloat y;

// Constructor / Destructor   
public:
    // Default constructor
    VfxFPoint() : x(0.0f), y(0.0f)
    {
    }
    
    // Construct a VfxFPoint with coordinate values.
    VfxFPoint(VfxFloat _x, VfxFloat _y) :
        x(_x), y(_y)
    {
    }
        
    // Construct a VfxFPoint with a vrt_fpoint_struct structure.
    VfxFPoint(const vrt_fpoint_struct &other) :
        x(other.x), y(other.y)
    {
    }

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    // Construct a VfxFPoint with a vrt_fpoint_struct structure.
    VfxFPoint(const vm_fpoint_struct &other) :
        x(other.x), y(other.y)
    {
    }
#endif

    // Copy constructor
    VfxFPoint(const VfxFPoint &other) :
        x(other.x), y(other.y)
    {
    }
    

// Operator
public:
    // Assigned with another point.
    //
    // RETURNS: Reference to the point.
    VfxFPoint &operator =(const VfxFPoint &other);
    
    // Compared with another point
    //
    // RETURNS: Return VFX_TRUE the point is equal to the other.    
    VfxBool operator ==(const VfxFPoint &other) const
    {
        return x == other.x && y == other.y;
    }
    
    // Compared with another point.
    //
    // RETURNS: Return VFX_TRUE the point is *NOT* equal to the other.
    VfxBool operator !=(const VfxFPoint &other) const
    {
        return x != other.x || y != other.y;
    }    

    // Internal used. Type cast to vrt_fpoint_struct.
    //
    // RETURNS: The point casted to vrt_fpoint_struct.
    operator vrt_fpoint_struct() const
    {
        return vrt_fpoint_make(x, y);
    }

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    // Internal used. Type cast to vm_fpoint_struct.
    //
    // RETURNS: The point casted to vm_fpoint_struct.
    operator vm_fpoint_struct() const
    {
        return vm_fpoint_make(x, y);
    }
#endif

// Method
public:
    // Check whether this is a zero point.
    //
    // RETURNS: Return VFX_TRUE if the point is a zero point,
    //  otherwise return VFX_FALSE.
    VfxBool isZero() const
    {
        return x == 0.0f && y == 0.0f;
    }

    // Set the point to be a zero point.
    //
    // RETURNS: Reference to the point.
    VfxFPoint &setZero();
};


inline
VfxFPoint &VfxFPoint::operator =(const VfxFPoint &other)
{
    x = other.x;
    y = other.y;
    return *this;
}


inline
VfxFPoint &VfxFPoint::setZero()
{
    x = 0.0f;
    y = 0.0f;
    return *this;
}


/***************************************************************************** 
 * Class VfxPoint
 *****************************************************************************/

/*
 * Class VfxPoint represents a point in 2D coordinate system. 
 *  Each coordinate data type is VfxS32.
 *
 * SEE ALSO: VfxFPoint, VfxRect
 */
class VfxPoint : public VfxBase
{
// Variable
public:
    // The x-coordinate of the point
    VfxS32 x;
    // The y-coordinate of the point
    VfxS32 y;
    
// Constructor / Destructor   
public:
    // Default constructor
    VfxPoint() : x(0), y(0)
    {
    }
    
    // Construct a VfxFPoint with coordinate values
    VfxPoint(VfxS32 _x, VfxS32 _y) :
        x(_x), y(_y)
    {
    }
    
    // Construct a VfxFPoint with a vrt_point_struct structure
    VfxPoint(const vrt_point_struct &other) :
        x(other.x), y(other.y)
    {
    }

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    // Construct a VfxFPoint with coordinate values
    VfxPoint(const vm_point_struct &other) :
        x(other.x), y(other.y)
    {
    }
#endif

    // Copy constructor
    VfxPoint(const VfxPoint &other) :
        x(other.x), y(other.y)
    {
    }

// Operator
public:
    // Assigned with another point.
    //
    // RETURNS: Reference to the point.
    VfxPoint &operator =(const VfxPoint &other);
    
    // Compared with another point.
    //
    // RETURNS: Return VFX_TRUE the point is equal to the other.    
    VfxBool operator ==(const VfxPoint &other) const
    {
        return x == other.x && y == other.y;
    }
    
    // Compared with another point.
    //
    // RETURNS: Return VFX_TRUE the point is *NOT* equal to the other.
    VfxBool operator !=(const VfxPoint &other) const
    {
        return x != other.x || y != other.y;
    }

    // Type cast to VfxFPoint.
    //
    // RETURNS: The point casted to VfxFPoint.
    operator VfxFPoint() const
    {
        return VfxFPoint((VfxFloat)x, (VfxFloat)y);
    }

    // Internal used. Type cast to vrt_point_struct.
    //
    // RETURNS: The point casted to vrt_point_struct.
    operator vrt_point_struct() const
    {
        return vrt_point_make(x, y);
    }

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    operator vm_point_struct() const
    {
        return vm_point_make(x, y);
    }
#endif

// Method
public:
    // Check whether this is a zero point.
    //
    // RETURNS: Return VFX_TRUE if the point is a zero point,
    //  otherwise return VFX_FALSE.
    VfxBool isZero() const
    {
        return x == 0 && y == 0;
    }
    
    // Set the point to be a zero point.
    //
    // RETURNS: Reference to the point.
    VfxPoint &setZero();     
};


inline
VfxPoint &VfxPoint::operator =(const VfxPoint &other)
{
    x = other.x;
    y = other.y;
    return *this;
}


inline
VfxPoint &VfxPoint::setZero()
{
    x = 0;
    y = 0;
    return *this;
}


/***************************************************************************** 
 * Class VfxSize
 *****************************************************************************/

/*
 * Class VfxSize represents the dimension of width and height in 2D coordinate system. 
 *  Each coordinate data type is VfxS32.
 *
 * SEE ALSO: VfxRect
 */
class VfxSize : public VfxBase
{
// Variable
public:
    // The width of the size
    VfxS32 width;
    // The height of the size
    VfxS32 height;
    
// Constructor / Destructor   
public:
    // Default constructor
    VfxSize() : width(0), height(0)
    {
    }

    // Construct a VfxSize with width and height.
    VfxSize(VfxS32 _width, VfxS32 _height) :
        width(_width), height(_height)
    {
    }
        
    // Construct a VfxSize with a vrt_size_struct structure.
    VfxSize(const vrt_size_struct &other) :
        width(other.width), height(other.height)
    {
    }

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    // Construct a VfxSize with a vrt_size_struct structure.
    VfxSize(const vm_size_struct &other) :
        width(other.width), height(other.height)
    {
    }
#endif

    // Copy constructor
    VfxSize(const VfxSize &other) :
        width(other.width), height(other.height)
    {
    }            

// Operator
public:
    // Assigned with another size.
    //
    // RETURNS: Reference to the size.
    VfxSize &operator =(const VfxSize &other);
    
    // Compared with another size.
    //
    // RETURNS: Return VFX_TRUE the size is equal to the other.    
    VfxBool operator ==(const VfxSize &other) const
    {
        return width == other.width && height == other.height;
    }
        
    // Compared with another size.
    //
    // RETURNS: Return VFX_TRUE the size is *NOT* equal to the other.
    VfxBool operator !=(const VfxSize &other) const
    {
        return width != other.width || height != other.height;
    }

    // Internal used. Type cast to vrt_size_struct.
    //
    // RETURNS: The size casted to vrt_size_struct.
    operator vrt_size_struct() const
    {
        return vrt_size_make(width, height);
    }

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    // Internal used. Type cast to vm_size_struct.
    //
    // RETURNS: The point casted to vm_size_struct.
    operator vm_size_struct() const
    {
        return vm_size_make(width, height);
    }
#endif

// Method
public:
    // Check whether this is a zero size, width and height are all zero.
    //
    // RETURNS: Return VFX_TRUE if the size is a zero size,
    //  otherwise return VFX_FALSE.
    //
    // NOTES:
    //  width == 0 && height == 0
    VfxBool isZero() const
    {
        return width == 0 && height == 0;
    }
    
    // Check whether width or height is zero.
    //
    // RETURNS: Return VFX_TRUE if the size is a empty size,
    //  otherwise return VFX_FALSE.
    //
    // NOTES:
    //  width == 0 || height == 0
    VfxBool isEmpty() const
    {
        return width == 0 || height == 0;
    }

    // Set the size to be a zero size.
    //
    // RETURNS: Reference to the size.
    VfxSize &setZero();
};


inline
VfxSize &VfxSize::operator =(const VfxSize &other)
{
    width = other.width;
    height = other.height;
    return *this;
}


inline
VfxSize &VfxSize::setZero()
{
    width = 0;
    height = 0;
    return *this;
}


/***************************************************************************** 
 * Class VfxRect
 *****************************************************************************/

/*
 * Class VfxRect represents a rectangle in 2D coordinate system. 
 *  Each coordinate data type is VfxS32.
 *
 * SEE ALSO: VfxPoint, VfxSize
 */
class VfxRect : public VfxBase
{
// Variable
public:
    // The top-left location of the rectangle
    VfxPoint  origin;
    // The size of the rectangle
    VfxSize   size;
    
// Constructor / Destructor   
public:
    // Default constructor
    VfxRect() : origin(0, 0), size(0, 0)
    {
    }

    // Construct a VfxRect with x, y, width and height value.
    VfxRect(VfxS32 _x, VfxS32 _y, VfxS32 _width, VfxS32 _height) :
        origin(_x, _y), size(_width, _height)
    {
    }

    // Construct a VfxRect with rectangle origin and size
    VfxRect(const VfxPoint &_origin, const VfxSize &_size) :
        origin(_origin), size(_size)
    {
    }

    // Construct a VfxSize with a vrt_rect_struct structure.
    VfxRect(const vrt_rect_struct &other) :
        origin(other.origin),size(other.size)
    {
    }

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    VfxRect(const vm_rect_struct &other) :
        origin(other.origin),size(other.size)
    {
    }
#endif

    // Copy constructor
    VfxRect(const VfxRect &other) :
        origin(other.origin),size(other.size)
    {
    }

// Operator
public:
    // Assigned with another rectangle.
    //
    // RETURNS: Reference to the rectangle.
    VfxRect &operator =(const VfxRect &other);
        
    // Compared with another rectangle.
    //
    // RETURNS: Return VFX_TRUE the rectangle is equal to the other.
    VfxBool operator ==(const VfxRect &other) const
    {
        return origin == other.origin && size == other.size;
    }
    
    // Compared with another rectangle.
    //
    // RETURNS: Return VFX_TRUE the rectangle is *NOT* equal to the other.
    VfxBool operator !=(const VfxRect &other) const
    {
        return origin != other.origin || size != other.size;
    }

    // Internal used. Type cast to vrt_rect_struct.
    //
    // RETURNS: The size casted to vrt_rect_struct.
    operator vrt_rect_struct() const
    {
        return vrt_rect_make(origin.x, origin.y, size.width, size.height);
    }

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    // Internal used. Type cast to vm_rect_struct.
    //
    // RETURNS: The point casted to vm_rect_struct.
    operator vm_rect_struct() const
    {
        return vm_rect_make(origin.x, origin.y, size.width, size.height);
    }
#endif

// Helper Method
public:
    // Return the x-coordinate of the rectangle origin.
    VfxS32 getX() const
    {
        return origin.x;
    }
    
    // Return the y-coordinate of the rectangle origin.
    VfxS32 getY() const
    {
        return origin.y;
    }
    
    // Return the width value of the rectangle.
    VfxS32 getWidth() const
    {
        return size.width;
    }
    
    // Return the height value of the rectangle.
    VfxS32 getHeight() const
    {
        return size.height;
    }

// Method
public:
    // Return the absolute width value of the rectangle.
    VfxS32 getAbsWidth() const
    {
        return vfxAbs(size.width);
    }

    // Return the absolute height value of the rectangle.
    VfxS32 getAbsHeight() const
    {
        return vfxAbs(size.height);
    }

    // Return the x-coordinate of left-side of the rectangle.
    VfxS32 getMinX() const
    {
        return size.width >= 0 ? origin.x : origin.x + size.width - 1;
    }
    
    // Return the y-coordinate of top-side of the rectangle.
    VfxS32 getMinY() const
    {
        return size.height >= 0 ? origin.y : origin.y + size.height - 1;
    }

    // Return the x-coordinate of right-side of the rectangle.
    VfxS32 getMaxX() const
    {
        return size.width < 0 ? origin.x : origin.x + size.width - 1;
    }
    
    // Return the y-coordinate of bottom-side of the rectangle.
    VfxS32 getMaxY() const
    {
        return size.height < 0 ? origin.y : origin.y + size.height - 1;
    }
    
    // Return the x-coordinate of center point of the rectangle.
    VfxS32 getMidX() const
    {
        return origin.x + size.width / 2;
    }
    
    // Return the y-coordinate of center point of the rectangle.
    VfxS32 getMidY() const
    {
        return origin.y + size.height / 2;
    }

    // Return the center point of the rectangle.
    VfxPoint getMidPoint() const
    {
        return VfxPoint(getMidX(), getMidY());
    }
    
    // Return the rectangle with a positive width and height.
    VfxRect getStandardRect() const
    {
        return VfxRect(getMinX(), getMinY(), getAbsWidth(), getAbsHeight());
    }

    // Check whether the rectangle size is a empty size.
    //
    // RETURNS: Return VFX_TRUE if the rect is a empty size,
    //  otherwise return VFX_FALSE.
    //
    // NOTES:
    //  width == 0 || height == 0
    VfxBool isEmpty() const
    {
        return size.isEmpty();
    }
    
    // Test if the rectangle contains the given point.
    //
    // RETURNS: Return VFX_TRUE if the point is in the rectangle,
    //  otherwise return VFX_FALSE.
    VfxBool contains(
        const VfxPoint &point   // [IN] The point to test
    ) const;

    // Set the rectangle with zero size. 
    //
    // RETURNS: Reference to the rectangle.
    VfxRect &setZero();

    // Append a given offset to the rectangle.
    //
    // RETURNS: Reference to the rectangle.
    VfxRect &offsetWith(
        const VfxPoint &offset  // [IN] Offset to append
    );

    // Append a given offset to the rectangle.
    //
    // RETURNS: Reference to the rectangle.
    VfxRect &offsetWith(
        VfxS32 offsetX,         // [IN] x-coordinate to append
        VfxS32 offsetY          // [IN] y-coordinate to append
    );

    // Intersect the rectangle with another rectangle.
    //
    // RETURNS: Reference to the rectangle.
    VfxRect &intersectWith(
        const VfxRect &other    // [IN] The rectangle to intersect
    );
    
    // Union the rectangle with another rectangle.
    //
    // RETURNS: Reference to the rectangle.
    VfxRect &unionWith(
        const VfxRect &other    // [IN] The rectangle to union
    );
};


inline
VfxRect &VfxRect::operator =(const VfxRect &other)
{
    origin = other.origin;
    size = other.size;
    return *this;
}


inline
VfxBool VfxRect::contains(const VfxPoint &point) const
{
    vrt_s32 xInRect = point.x - origin.x;
    vrt_s32 yInRect = point.y - origin.y;
    
    return xInRect >= 0 && xInRect < size.width && 
        yInRect >= 0 && yInRect < size.height;
}


inline
VfxRect &VfxRect::setZero()
{
    origin.x = 0;
    origin.y = 0;
    size.width = 0;
    size.height = 0;
    return *this;
}


inline
VfxRect &VfxRect::offsetWith(const VfxPoint &offset)
{
    origin.x += offset.x;
    origin.y += offset.y;
    return *this;
}


inline
VfxRect &VfxRect::offsetWith(VfxS32 offsetX, VfxS32 offsetY)
{
    origin.x += offsetX;
    origin.y += offsetY;
    return *this;
}


inline
VfxRect &VfxRect::intersectWith(const VfxRect &other)
{
    VfxS32 x0 = vfxMax(origin.x, other.origin.x);
    VfxS32 y0 = vfxMax(origin.y, other.origin.y);
    VfxS32 x1 = vfxMin(origin.x + size.width, other.origin.x + other.size.width);
    VfxS32 y1 = vfxMin(origin.y + size.height, other.origin.y + other.size.height);
    
    origin.x = x0;
    origin.y = y0;
    size.width = x1 - x0;
    size.height = y1 - y0;    
    return *this;
}


inline
VfxRect &VfxRect::unionWith(const VfxRect &other)
{
    VfxS32 x0 = vfxMin(origin.x, other.origin.x);
    VfxS32 y0 = vfxMin(origin.y, other.origin.y);
    VfxS32 x1 = vfxMax(origin.x + size.width, other.origin.x + other.size.width);
    VfxS32 y1 = vfxMax(origin.y + size.height, other.origin.y + other.size.height);
    
    origin.x = x0;
    origin.y = y0;
    size.width = x1 - x0;
    size.height = y1 - y0;    
    return *this;
}


/***************************************************************************** 
 * class VfxColorResHelper
 *****************************************************************************/
/*
 * Internal Used. Use macro VFX_COLOR_RES.
 */
class VfxColorResHelper : public VfxBase
{
// Constructor / Destructor        
public:
    // Default constructor
    VfxColorResHelper(VfxResId resId) : 
        m_resId(resId)
    {
    }

// Method
public:
    VfxResId getResId() const
    {
        return m_resId;
    }

private:
    VfxResId m_resId;
};


/***************************************************************************** 
 * class VfxColor
 *****************************************************************************/

/*
 * Class VfxColor represents a color with red, green, blue and alpha channels.
 *  Each channel represents in VfxU8.
 *
 */
class VfxColor : public VfxBase
{
// Variable
public:
    // The 32-bits value of the color, in format ARGB8888.
    VfxU32 value;
    
// Constructor / Destructor   
public:
    // Default constructor, default color is transparent.
    VfxColor() : value(0x00000000)
    {
    }

    // Initialized with resource ID
    VfxColor(const VfxColorResHelper &initializer)
    {
        setResId(initializer.getResId());
    }

    // Construct a VfxColor with A, R, G, B channels.
    VfxColor(VfxU8 a, VfxU8 r, VfxU8 g, VfxU8 b) :
        value(VRT_COLOR_MAKE(a, r, g, b))
    {
    }

    // Construct a VfxColor with a VfxU32 value, in format ARGB8888.
    //
    // SEE ALSO: value
    VfxColor(VfxU32 _value) :
        value(_value)
    {
    }

    // Copy constructor
    VfxColor(const VfxColor &other) :
        value(other.value)
    {
    }

// Operator
public:
    // Assigned a new color with a VfxU32 value, in format ARGB8888.
    //
    // RETURNS: Reference to the color.
    //
    // SEE ALSO: value
    VfxColor &operator =(VfxU32 _value)
    {
        value = _value;
        return *this;
    }
        
    // Assigned with another color.
    //
    // RETURNS: Reference to the color.
    VfxColor &operator =(const VfxColor &other)
    {
        value = other.value;
        return *this;
    }
    
    // Compared with another color.
    //
    // RETURNS: Return VFX_TRUE the color is equal to the other.
    VfxBool operator ==(const VfxColor &other) const
    {
        return value == other.value;
    }
    
    // Compared with another color.
    //
    // RETURNS: Return VFX_TRUE the color is *NOT* equal to the other.
    VfxBool operator !=(const VfxColor &other) const
    {
        return value != other.value;
    }

    // Type cast the color to a VfxU32 value, in format ARGB8888.
    //
    // RETURNS: The color in VfxU32 data type.
    //
    // SEE ALSO: value
    operator VfxU32() const
    {
        return value;
    }

// Method
public:
    // Assigned a new color with A, R, G, B channels.
    void setARGB(
        VfxU8 a,    // [IN] A channel to assign
        VfxU8 r,    // [IN] R channel to assign 
        VfxU8 g,    // [IN] G channel to assign  
        VfxU8 b     // [IN] B channel to assign
    )
    {
        value = VRT_COLOR_MAKE(a, r, g, b);
    }
    
    // Assigned a new value of alpha channel
    void setA(
        VfxU8 _value // [IN] new value to assign
    )
    {
        value &= 0x00ffffff;
        value |= (_value << 24);
    }
    
    // Assigned a new value of red channel
    void setR(
        VfxU8 _value // [IN] new value to assign
    )
    {
        value &= 0xff00ffff;
        value |= (_value << 16);
    }
    
    // Assigned a new value of green channel
    void setG(
        VfxU8 _value // [IN] new value to assign
    )
    {
        value &= 0xffff00ff;
        value |= (_value << 8);
    }
    
    // Assigned a new value of blue channel
    void setB(
        VfxU8 _value // [IN] new value to assign
    )
    {
        value &= 0xffffff00;
        value |= _value;
    }

    // Return the value of alpha channel
    VfxU8 getA() const
    {
        return (VfxU8)(value >> 24);
    }
    
    // Return the value of red channel
    VfxU8 getR() const
    {
        return (VfxU8)(value >> 16);
    }
    
    // Return the value of green channel
    VfxU8 getG() const
    {
        return (VfxU8)(value >> 8);
    }
    
    // Return the value of blue channel
    VfxU8 getB() const
    {
        return (VfxU8)value;
    }

    // Set the color source to a given resource ID
    void setResId(
        VfxResId resId
    )
    {
        value = vfx_sys_res_get_color(resId);
    }

    // Check whether this is a transparent color
    //
    // RETURNS: Return VFX_TRUE if the alpha channel is zero. Otherwise,
    //  return VFX_FALSE.
    VfxBool isTransparnet() const
    {
        return (value & 0xff000000) == 0x00000000;
    }

    // Check whether this is a opaque color
    //
    // RETURNS: Return VFX_TRUE if the alpha channel is 255. Otherwise,
    //  return VFX_FALSE.
    VfxBool isOpaque() const
    {
        return (value & 0xff000000) == 0xff000000;
    }
};

#endif /* __VFX_BASIC_TYPE_H__ */

