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
 *  vfx_class_info.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Define the prototypes of class info and property pointer.
 *  Implement dynamic access to property of C++ objects.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_CLASS_INFO_H__
#define __VFX_CLASS_INFO_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxBase
#include "vfx_cpp_base.h"

#include "vfx_datatype.h"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// Pre-defined classes
class VfxObject;

// Prototype of VfxClassInfo create object function pointer
typedef VfxObject *(*VfxClassInfoCreateObjectFuncPtr)(VfxObject *parent);


/***************************************************************************** 
 * Class VfxClassInfo
 *****************************************************************************/
typedef struct _vfx_class_info_struct
{
    // pointer to the name of the class
    const VfxChar *m_className;
    // pointer to the parent class info of the class
    const struct _vfx_class_info_struct *m_parent;
    // Function pointer to create a object instance
    VfxClassInfoCreateObjectFuncPtr m_createObjectCallback;
} vfx_class_info_struct;

/*
 * Class VfxClassInfo, 
 *  prototype of class information, descript the class name, the parent class, 
 *  and how to create instances of the class
 */
class VfxClassInfo : public _vfx_class_info_struct
{
// Constructor / Destructor    
public:
    // Constructor
    VfxClassInfo(
        const VfxChar *className,
        struct _vfx_class_info_struct *parent,
        VfxClassInfoCreateObjectFuncPtr createObjInstanceCallback
    )
    {
        m_className = className;
        m_parent = parent;
        m_createObjectCallback = createObjInstanceCallback;
    }

// Method
public:
    // Return the class name.
    //
    // RETURNS: Return the class name.
    const VfxChar *getClassName() const
    {
        return m_className;
    }

    // Return the parent class into.
    //
    // RETURNS: Return the parent class. Return NULL if there is no parent class
    VfxClassInfo *getParent() const
    {
        return (VfxClassInfo *)m_parent;
    }

    // Check the class whatever inherit from the given class.
    //
    // RETURNS: Return VFX_TRUE if the class inherit from the given class.
    //  Otherwise, return VFX_FALSE.
    VfxBool isKindOf(
        const VfxClassInfo *classInfo   // [IN] The class to check
    ) const;

    // Create an object instance of the class.
    VfxObject *createObject(
        VfxObject *parent               // [IN] The parent object to create new object
    ) const
    {
        return m_createObjectCallback ? m_createObjectCallback(parent) : NULL;
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
};

#endif /* __VFX_CLASS_INFO_H__ */

