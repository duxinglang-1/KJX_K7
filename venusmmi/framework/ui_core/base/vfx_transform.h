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
 *  vfx_transform.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus UI Transform Type Classes
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_TRANSFORM_H__
#define __VFX_TRANSFORM_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxBase 
#include "vfx_cpp_base.h"
// For VfxPoint
#include "vfx_basic_type.h"
// For vrt_matrix3x3_struct, etc.
#include "vrt_datatype.h"
#include "vfx_datatype.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

// Affine transform type
#define VFX_TRANSFORM_TYPE_AFFINE        VRT_TRANSFORM_TYPE_AFFINE
// Matrix3x3 transform type
#define VFX_TRANSFORM_TYPE_MATRIX3X3     VRT_TRANSFORM_TYPE_MATRIX3X3
#define VFX_TRANSFORM_TYPE_END_OF_ENUM   VRT_TRANSFORM_TYPE_END_OF_ENUM

// Identity transform
#define VFX_TRANSFORM_IDENTITY           VfxTransform()


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef vrt_matrix3x3_struct            VfxMatrix3x3;           // Matrix 3x3
typedef vrt_affine_parameter_struct     VfxAffineParameter;     // Parameters for affine transform
typedef vrt_transform_type_enum         VfxTransformTypeEnum;   // Transform type. Either affine or matrix3x3 type


/***************************************************************************** 
 * Class VfxMatrix3x3Ex
 *****************************************************************************/

/*
 * Class VfxMatrix3x3Ex provide some basic arithmatic for 3x3 matrix. The data 
 * sequence is column major. The matrix is form as follow:
 *     |   m0,  m3,  m6  |
 *     |   m1,  m4,  m7, |
 *     |   m2,  m5,  m8, |
 */

class VfxMatrix3x3Ex : public VfxBase
{
// Constructor / Destructor
public:

    // Default Constructor
    VfxMatrix3x3Ex();

    // Construct with each element
    VfxMatrix3x3Ex(
        VfxFloat _mat0, 
        VfxFloat _mat1, 
        VfxFloat _mat2, 
        VfxFloat _mat3,
        VfxFloat _mat4, 
        VfxFloat _mat5, 
        VfxFloat _mat6, 
        VfxFloat _mat7,
        VfxFloat _mat8
        );

    // Copy with a float point arary.
    VfxMatrix3x3Ex(
        const VfxFloat* input   // [IN] poiter to an float point array which represents a 3x3 matrix.
    );

    // Copy Constructor
    VfxMatrix3x3Ex(const VfxMatrix3x3Ex &other);

    // Copy Constructor
    VfxMatrix3x3Ex(const VfxMatrix3x3 &other);

// Varialbe
public:
    VfxFloat m[9];     // Elements of matrix

// Method
public:
    // set Identity matrix
    void setIdentity(void);
    // set scale matrix
    void setScale(
        float sx, // [IN] scale parameter in X 
        float sy  // [IN] scale parameter in Y
        );
    // set translation matrix
    void setTranslation(
        float tx, // [IN] translate parameter in X 
        float ty  // [IN] translate parameter in Y
        );
    
    // set rotate matrix by Z axis
    void setRotateByZ(
        float theta // [IN] rotate angle by Z axis
        );
    
    void setAffine(
        const VfxAffineParameter &affine   // [IN] affine transform parameters
        );

    // Initialize 3x3 matrix with 4x4 matrix
    void initMatrix3x3(
        VfxMatrix3x3 &out   // [OUT] 3x3 matrix to be initialized. 
        ) const;
    // inverse matrix;
    void inverse();

    // transpose matrix;
    void transpose();

    // transform Point
    VfxPoint transform(const VfxPoint &in); 

// Operator    
    // Assigns with another matrix.
    // 
    // RETURNS: Reference to the new assigned matrix (self).
    VfxMatrix3x3Ex &operator =(const VfxMatrix3x3Ex &other);

    // Multiples with another matrix
    //
    // RETURNS: Reference to the new assigned matrix (self).
    VfxMatrix3x3Ex &operator *=(const VfxMatrix3x3Ex &other);

    // Multiples with another matrix.
    //
    // RETURNS: New multipled matrix.
    VfxMatrix3x3Ex operator *(const VfxMatrix3x3Ex &other);

};


/***************************************************************************** 
 * Class VfxMatrix4x4
 *****************************************************************************/

/*
 * Class VfxMatrix4x4 provide some basic arithmatic for 4x4 matrix. The data 
 * sequence is column major. The matrix is form as follow:
 *     |  m0, m4,  m8, m12 |
 *     |  m1, m5,  m9, m13 |
 *     |  m2, m6, m10, m14 |
 *     |  m3, m7, m11, m15 |
 */
class VfxMatrix4x4 : public VfxBase
{
// Constructor / Destructor
public:

    // Default Constructor
    VfxMatrix4x4();

    // Construct with each element
    VfxMatrix4x4(
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
        VfxFloat _mat15);

    // Copy with a float point arary.
    VfxMatrix4x4(
        const VfxFloat* input   // [IN] poiter to an float point array which represents a 4x4 matrix.
    );

    // Copy Constructor
    VfxMatrix4x4(const VfxMatrix4x4 &other);

// Varialbe
public:
    VfxFloat m[16];     // Elements of matrix
    
// Method
public:
    // set Identity matrix
    void setIdentity(void);
    // set scale matrix
    void setScale(
        float sx, // [IN] scale parameter in X 
        float sy, // [IN] scale parameter in Y
        float sz  // [IN] scale parameter in Z
        );
    // set translation matrix
    void setTranslation(
        float tx, // [IN] translate parameter in X 
        float ty, // [IN] translate parameter in Y
        float tz  // [IN] translate parameter in Z
        );
    // set rotate matrix by X axis
    void setRotateByX(
        float theta // [IN] rotate angle by X axis
        ); 
    // set rotate matrix by Y axis
    void setRotateByY(
        float theta // [IN] rotate angle by Y axis
        ); 
    // set rotate matrix by Z axis
    void setRotateByZ(
        float theta // [IN] rotate angle by Z axis
        );
    // set compositeMatrix for general 3D use.
    void setCamera(
        VfxFloat scaleX,
        VfxFloat scaleY,
        VfxFloat translateX,
        VfxFloat translateY,
        VfxFloat nearPlane,
        VfxFloat cameraDistance,
        VfxFloat cameraUp,
        VfxFloat tile,
        VfxFloat pan
        );
    // set camera parameters
    void setCamera2(
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
        VfxFloat camearRoll
        );
    // Initialize 3x3 matrix with 4x4 matrix
    void initMatrix3x3(
        VfxMatrix3x3 &out   // [OUT] 3x3 matrix to be initialized. 
        ) const;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    // transpose matrix;
    void transpose();

// Operator    
    // Assigns with another matrix.
    // 
    // RETURNS: Reference to the new assigned matrix (self).
    VfxMatrix4x4 &operator =(const VfxMatrix4x4 &other);

    // Multiples with another matrix
    //
    // RETURNS: Reference to the new assigned matrix (self).
    VfxMatrix4x4 &operator *=(const VfxMatrix4x4 &other);

    // Multiples with another matrix.
    //
    // RETURNS: New multipled matrix.
    VfxMatrix4x4 operator *(const VfxMatrix4x4 &other);

};


/***************************************************************************** 
 * Class VfxTransform
 *****************************************************************************/

/*
 * VfxTransform defines the translation, rotation and scaling of a frame. It is
 * based on affine parameters or a 3x3 matrix.
 *
 * SEE ALSO: VfxAffineParameter, VfxMatrix3x3
 */
class VfxTransform : public VfxBase
{
// Declaration
public:
    VfxTransformTypeEnum type;              // transform type.

    // data union for transform
    union
    {
        VfxAffineParameter  affine;         // data for affine transfrom type
        VfxMatrix3x3        matrix3x3;      // data for matrix 3x3 transfrom type
    } data;                                 // data for affine or matrix 3x3 transform


// Constructor / Destructor    
public:
    // Default constructor
    VfxTransform() :
        type(VFX_TRANSFORM_TYPE_AFFINE)
    {
        identity();
    }

    VfxTransform(VfxTransformTypeEnum _type) :
        type(_type)
    {
        identity();
    }

    // Construct with VRT transform.
    VfxTransform(
        const vrt_transform_struct &other   // [IN] VRT transform
    );

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    // Construct with VM transform.
    VfxTransform(
        const vm_transform_struct &other   // [IN] VM transform
    );
#endif

    // Copy constructor
    VfxTransform(const VfxTransform &other)
    {
        assignWith(other);
    }

// Operator
public:
    // Assigns with another transform.
    //
    // RETURNS: Reference to new assigned transform.
    VfxTransform &operator =(const VfxTransform &other)
    {   
        assignWith(other);
        return *this;
    }

    // Equality operator
    VfxBool operator ==(const VfxTransform &other) const
    {
        return compareWith(other);
    }

    // Inequality operator
    VfxBool operator !=(const VfxTransform &other) const
    {
        return !compareWith(other);
    }

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    operator vm_transform_struct() const;
#endif

// Method
public:

    // Initialize transform with specified type
    //
    // RETURNS: Reference to initialized transform (self).
    VfxTransform &init(
        VfxTransformTypeEnum _type = VFX_TRANSFORM_TYPE_AFFINE  //[IN] transform type.
    );

    // Reset transform to be indentity.
    //
    // RETURNS: Reference to initialized transform (self).
    VfxTransform &setIdentity()
    {
        identity();    
        return *this;
    }

    // Check if the transform is indentity.
    //
    // RETURNS: True if the transform is identity otherwise return false.
    VfxBool isIdentity() const;

    // Internal Used. Initializes VRT transform.    
    void initVrtTransform(
        vrt_transform_struct &vrt_transform,     // [OUT] new initialized VRT transform
        VfxBool isAutoIdentity = VFX_FALSE       // [IN] Automatically convert to VRT identity tranfrom or not.
    ) const;

    // Transpose transform. It only works for VFX_TRANSFORM_TYPE_MATRIX3X3 type.
    void transpose();

// Implementation
private:
    void identity();
    void assignWith(const VfxTransform &other);
    VfxBool compareWith(const VfxTransform &other) const;
};


inline
VfxTransform &VfxTransform::init(VfxTransformTypeEnum _type)
{
    type = _type;
    identity();
    return *this;
}


#endif /* __VFX_TRANSFORM_H__ */

