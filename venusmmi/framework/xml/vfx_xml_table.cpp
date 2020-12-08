/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vfx_xml_table.cpp
 *
 * Project:
 * --------
 *  Venus XML
 *
 * Description:
 * ------------
 *  Venus XML Tables
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_xml_table.h"

#include "vrt_datatype.h"

#include "vfx_object.h"
#include "vfx_xml_prop_handler.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/*
 * Venus XML enum support
 */

#define VFX_XML_DEFINE_ENUM_VALUE_TABLE_BEGIN(_tableName) \
    const VfxXmlEnumValueTableEntry _tableName[] = \
    { \
        { 0, 0, NULL },

#define VFX_XML_DEFINE_ENUM_VALUE_TABLE_END() \
        { 0, 0, NULL } \
    }

#define VFX_XML_DEFINE_ENUM_VALUE(_id, _enumType, _enumValue) \
        { \
            (VfxU32)(_enumValue), \
            sizeof(_enumType), \
            VfxXmlEnumSettingHelper <_enumType>::setObjEnumValue \
        },
            

/*
 * Venus XML classes support
 */

#define VFX_XML_CLASS_MEM_OFFSET(_className, _member) \
    ((VfxU32)&(((_className *)NULL)->_member) - (VfxU32)(_className *)NULL)

#ifdef __VXML_DEBUG_INFO__
#define VFX_XML_STR(s)  ,#s
#define VFX_XML_NULL  ,NULL
#else
#define VFX_XML_STR(s)  
#define VFX_XML_NULL  
#endif

#define VFX_XML_DEFINE_CLASS_TABLE_BEGIN(_tableName) \
    const VfxXmlClassTableEntry _tableName[] = \
    { \
        { NULL VFX_XML_NULL },

#define VFX_XML_DEFINE_CLASS_TABLE_END() \
        { NULL VFX_XML_NULL } \
    }
      
#define VFX_XML_DEFINE_CLASS(_id, _className) \
    { \
        _className##::get##_className##ClassInfo \
        VFX_XML_STR(_className) \
    },


#define VFX_XML_DEFINE_PROP_TABLE_BEGIN(_tableName) \
    const VfxXmlPropertyTableEntry _tableName[] = \
    { \
        { NULL, 0, NULL VFX_XML_NULL },
    
#define VFX_XML_DEFINE_PROP_TABLE_END() \
        { NULL, 0, NULL VFX_XML_NULL } \
    }

#define VFX_XML_DEFINE_HANDLER_PROP(_id, _typeName) \
    { \
        vfxXmlPropType##_typeName##Handler, \
        0, \
        NULL \
        VFX_XML_STR(_id) \
    },

#define VFX_XML_DEFINE_ENUM_PROP(_id, _typeName, _memFunc) \
    { \
        vfxXmlPropTypeEnumHandler, \
        0, \
        (VfxXmlSetPropMemFuncPtr)(void (VfxObject::*)(_typeName))(_memFunc) \
        VFX_XML_STR(_id) \
    },

#define VFX_XML_DEFINE_TYPE_PROP(_id, _typeName, _memFunc) \
    { \
        vfxXmlPropType##_typeName##Handler, \
        0, \
        (VfxXmlSetPropMemFuncPtr)(VfxXmlPropType##_typeName##HandlerPtr)(_memFunc) \
        VFX_XML_STR(_id) \
    },

#define VFX_XML_DEFINE_STRUCT_PROP(_id, _typeName, _memFunc) \
    { \
        vfxXmlPropTypeStructHandler, \
        (VfxU32)VFX_XML_STRUCT_ID_##_typeName, \
        (VfxXmlSetPropMemFuncPtr)(void (VfxObject::*)(const _typeName &))(_memFunc) \
        VFX_XML_STR(_id) \
    },

#define VFX_XML_DEFINE_OBJECT_PROP(_id, _typeName, _memFunc) \
    { \
        vfxXmlPropTypeObjectHandler, \
        (VfxU32)VFX_XML_CLASS_ID_##_typeName, \
        (VfxXmlSetPropMemFuncPtr)(void (VfxObject::*)(_typeName *))(_memFunc) \
        VFX_XML_STR(_id) \
    },

#define VFX_XML_DEFINE_SIGNAL_PROP(_id, _typeName, _className, _member) \
    { \
        vfxXmlPropType##_typeName##Handler, \
        VFX_XML_CLASS_MEM_OFFSET(_className, _member), \
        NULL \
        VFX_XML_STR(_id) \
    },

/*
 * Venus XML structures support
 */

#define VFX_XML_DEFINE_STRUCT_TABLE_BEGIN(_tableName) \
    const VfxXmlStructTableEntry _tableName[] = \
    { \
        { NULL },

#define VFX_XML_DEFINE_STRUCT_TABLE_END() \
        { NULL } \
    }
        
#define VFX_XML_DEFINE_STRUCT(_id, _className) \
    { \
        VfxXmlCreateStructHelper <_className>::createInstance \
    },


#define VFX_XML_DEFINE_STRUCT_MEMBER_TABLE_BEGIN(_tableName) \
    const VfxXmlStructMemberTableEntry _tableName[] = \
    { \
        { 0, NULL },
    
#define VFX_XML_DEFINE_STRUCT_MEMBER_TABLE_END() \
        { 0, NULL } \
    }

#define VFX_XML_STRUCT_MEMBER_TYPE_HANDLER_PTR(_typeName) \
    vfxXmlStructType##_typeName##Handler

#define VFX_XML_DEFINE_STRUCT_MEMBER(_id, _typeName, _className, _member) \
    { \
        VFX_XML_CLASS_MEM_OFFSET(_className, _member), \
        VFX_XML_STRUCT_MEMBER_TYPE_HANDLER_PTR(_typeName) \
    },


#define VFX_XML_DEFINE_SLOT_TABLE_BEGIN(_tableName) \
    const VfxXmlSlotTableEntry _tableName[] = \
    { \
        { NULL },
    
#define VFX_XML_DEFINE_SLOT_TABLE_END() \
        { NULL } \
    }

/*
 * Venus XML slots support
 */

#define VFX_XML_DEFINE_OBJECT_SLOT(_id, _typeName, _memFunc) \
    { \
        (VfxXmlSlotMemFuncPtr)(_typeName)(_memFunc) \
    }, 


/***************************************************************************** 
 * Template VfxXmlEnumSettingFunc
 *****************************************************************************/

template <class _EnumType>
class VfxXmlEnumSettingHelper
{
private:
    typedef void (VfxObject::*SetProeprtyMemFunc)(_EnumType value);
        
public:
    static void setObjEnumValue(
        VfxObject *obj,
        VfxXmlPropTypeUnknownHandlerPtr memFuncPtr,
        VfxU32 value)
    {
        VFX_DEV_ASSERT(obj != NULL);
        SetProeprtyMemFunc mf = (SetProeprtyMemFunc)memFuncPtr;
        (obj->*mf)((_EnumType)value);
    }
};


/***************************************************************************** 
 * Template VfxXmlCreateStructHelper
 *****************************************************************************/

template <class _T>
class VfxXmlCreateStructHelper
{
public:
    static VfxBase *createInstance()
    {
        // Creates for a temp usage 
        //  and will be deleted in vfxXmlPropTypeStructHandler()
        _T *ptr;
        VFX_SYS_NEW(ptr, _T);
        return ptr;
    }
};


/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_xml_table.i"

