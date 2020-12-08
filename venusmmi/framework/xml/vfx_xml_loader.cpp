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
 *  vfx_xml_loader.cpp
 *
 * Project:
 * --------
 *  Venus XML
 *
 * Description:
 * ------------
 *  Venus XML Loader
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

#if !defined(__MTK_TARGET__) && defined(WIN32)
#include "windows.h"
#endif

#include "ui_core\base\vfx_base.h"
#include "ui_core\pme\vfx_pme.h"

#include "vfx_xml_enum.h"
#include "vfx_xml_loader.h"
#include "vfx_xml_loader_impl.h"
#include "vfx_xml_table.h"

extern "C"
{
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_debug.h"
}

#include "vfx_object.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_stream.h"
#include "vrt_datatype.h"
#include "vfx_xml_enum.h"
#include "vfx_system.h"
#include "vfx_sys_memory.h"
#include "vfx_string.h"
#include "vfx_xml_prop_handler.h"
#include "vfx_class_info.h"
#include "vfx_object_list.h"

#ifdef __VXML_DEBUG_INFO__
#define VXML_PRINT0(l,f)          vxml_printf(l,f)
#define VXML_PRINT1(l,f,a)        vxml_printf(l,f,a)
#define VXML_PRINT2(l,f,a,b)      vxml_printf(l,f,a,b)
#define VXML_PRINT3(l,f,a,b,c)    vxml_printf(l,f,a,b,c)
#else
#define VXML_PRINT0(l,f)          
#define VXML_PRINT1(l,f,a)        
#define VXML_PRINT2(l,f,a,b)      
#define VXML_PRINT3(l,f,a,b,c)    
#endif


/***************************************************************************** 
 * Global
 *****************************************************************************/

VfxXmlLoaderImpl *VfxXmlLoader::s_xmlLoader = NULL;


/***************************************************************************** 
 * Helper
 *****************************************************************************/

#ifdef __VXML_DEBUG_INFO__

void vxml_printf(VfxS32 level, char* format, ...)
{
    static VfxChar print_buffer[1024];

    va_list     arg_list;
    VfxS32      param_length, i;

    i = level;
    while(i--)
    {
        print_buffer[i*2] = ' ';
        print_buffer[i*2 + 1] = ' ';
    }

    va_start(arg_list, format);
    param_length = vsprintf((print_buffer+level*2), format, arg_list) + level*2;
    VFX_DEV_ASSERT(param_length < 1022);
    print_buffer[param_length] = '\r';
    print_buffer[param_length+1] = '\n';
    print_buffer[param_length+2] = 0;

    kal_printf(print_buffer);
#if !defined(__MTK_TARGET__) && defined(WIN32)
    OutputDebugStringA(print_buffer);
#endif
}

#endif


/***************************************************************************** 
 * Class VfxXmlLoader
 *****************************************************************************/

VfxXmlLoader::VfxXmlLoader():
    m_impl(NULL)
{

}

VfxXmlLoader::~VfxXmlLoader()
{

}

VfxBool VfxXmlLoader::loadXml(const VfxU8* memHead, const VfxU8* memTail /* = NULL */)
{
    if(m_impl)
    {
        VXML_PRINT0(0, "[VfxXmlLoader] Error: loadXml() not support re-entry");
        return VFX_FALSE;
    }

    VXML_PRINT0(0, "[VfxXmlLoader] loadXml");

    VFX_ALLOC_NEW(m_impl, VfxXmlLoaderImpl, this);

    VFX_ASSERT(memHead != NULL);
    VfxMemIstream is;
    is.open((VfxU8 *)memHead, (VfxU8 *)memTail);
    VfxBool ret = m_impl->loadBeginFromStream(getParent(), is);
    is.close();

    if(!ret)
        VFX_DELETE(m_impl);

    return ret;

}

VfxBool VfxXmlLoader::loadXml(VfxResId xmlResId)
{
    if(m_impl)
    {
        VXML_PRINT0(0, "[VfxXmlLoader] Error: loadXml() not support re-entry");
        return VFX_FALSE;
    }
    
    VXML_PRINT0(0, "[VfxXmlLoader] loadXml");
    if (xmlResId == NULL)
    {
        // Do nothing
        VXML_PRINT0(0, "[VfxXmlLoader] Error: Invalid parameter");
        return VFX_FALSE;
    }

    VfxU32 size;
    const VfxU8 *start;
    start = vfx_sys_res_get_binary(xmlResId, &size);
    if(!start)
    {
        VXML_PRINT1(0, "[VfxXmlLoader] Error: Resource id ( %d ) not found", xmlResId);
        return VFX_FALSE;
    }

    VFX_ALLOC_NEW(m_impl, VfxXmlLoaderImpl, this);

    VfxMemIstream is;
    is.open(start, start + size);
    VfxBool ret = m_impl->loadBeginFromStream(getParent(), is);
    is.close();

    if(!ret)
        VFX_DELETE(m_impl);
    
    return VFX_TRUE;
}

VfxBool VfxXmlLoader::loadXml(const VfxWChar *filename)
{
    if(m_impl)
    {
        VXML_PRINT0(0, "[VfxXmlLoader] Error: loadXml() not support re-entry");
        return VFX_FALSE;
    }
    
    VXML_PRINT0(0, "[VfxXmlLoader] loadXml");
    if (filename == NULL)
    {
        // Do nothing
        VXML_PRINT0(0, "[VfxXmlLoader] Error: Invalid parameter");
        return VFX_FALSE;
    }
    
    VfxFileIstream is;
    
    if (!is.open(filename))
    {
        VXML_PRINT0(0, "[VfxXmlLoader] Error: Error opening file");
        return VFX_FALSE;
    }
    
    VFX_ALLOC_NEW(m_impl, VfxXmlLoaderImpl, this);

    VfxBool ret = m_impl->loadBeginFromStream(getParent(), is);
    is.close();
    
    if(!ret)
        VFX_DELETE(m_impl);

    return ret;
}

VfxObject *VfxXmlLoader::findObj(const VfxWString &name)
{
    if(!m_impl)
        return NULL;

    return m_impl->findObjByName(name);
}

void VfxXmlLoader::onDeinit()
{
    VFX_DELETE(m_impl);

    VfxObject::onDeinit();
}


VfxBool VfxXmlLoader::loadBegin(VfxObject *obj, const VfxU8* memHead, const VfxU8* memTail)
{
    if(s_xmlLoader)
    {
        VXML_PRINT0(0, "[VfxXmlLoader] Error: loadBegin() not support re-entry");
        return VFX_FALSE;
    }

    VXML_PRINT0(0, "[VfxXmlLoader] loadBegin");
    VFX_OBJ_ASSERT_VALID(obj);

    VFX_SYS_NEW(s_xmlLoader, VfxXmlLoaderImpl);

    VFX_ASSERT(memHead != NULL);
    VfxMemIstream is;
    is.open((VfxU8 *)memHead, (VfxU8 *)memTail);
    VfxBool ret = s_xmlLoader->loadBeginFromStream(obj, is);
    is.close();

    if(!ret)
        loadEnd();

    return ret;
}


VfxBool VfxXmlLoader::loadBegin(VfxObject *obj, VfxResId xmlResId)
{
    if(s_xmlLoader)
    {
        VXML_PRINT0(0, "[VfxXmlLoader] Error: loadBegin() not support re-entry");
        return VFX_FALSE;
    }
    
    VXML_PRINT0(0, "[VfxXmlLoader] loadBegin");
    if (obj == NULL || xmlResId == NULL)
    {
        // Do nothing
        VXML_PRINT0(0, "[VfxXmlLoader] Error: Invalid parameter");
        return VFX_FALSE;
    }

    VfxU32 size;
    const VfxU8 *start;
    start = vfx_sys_res_get_binary(xmlResId, &size);
    if(!start)
    {
        VXML_PRINT1(0, "[VfxXmlLoader] Error: Resource id ( %d ) not found", xmlResId);
        return VFX_FALSE;
    }

    VFX_SYS_NEW(s_xmlLoader, VfxXmlLoaderImpl);

    VfxMemIstream is;
    is.open(start, start + size);
    VfxBool ret = s_xmlLoader->loadBeginFromStream(obj, is);
    is.close();

    if(!ret)
        loadEnd();
    
    return VFX_TRUE;
}


VfxBool VfxXmlLoader::loadBegin(VfxObject *obj, const VfxWChar *filename)
{
    if(s_xmlLoader)
    {
        VXML_PRINT0(0, "[VfxXmlLoader] Error: loadBegin() not support re-entry");
        return VFX_FALSE;
    }
    
    VXML_PRINT0(0, "[VfxXmlLoader] loadBegin");
    if (obj == NULL || filename == NULL)
    {
        // Do nothing
        VXML_PRINT0(0, "[VfxXmlLoader] Error: Invalid parameter");
        return VFX_FALSE;
    }
    
    VfxFileIstream is;
    
    if (!is.open(filename))
    {
        VXML_PRINT0(0, "[VfxXmlLoader] Error: Error opening file");
        return VFX_FALSE;
    }
    
    VFX_SYS_NEW(s_xmlLoader, VfxXmlLoaderImpl);

    VfxBool ret = s_xmlLoader->loadBeginFromStream(obj, is);
    is.close();
    
    if(!ret)
        loadEnd();

    return ret;
}


void VfxXmlLoader::loadEnd()
{
    VFX_SYS_DELETE(s_xmlLoader);
    VXML_PRINT0(0, "[VfxXmlLoader] loadEnd");
}


VfxObject *VfxXmlLoader::createObjectBegin(const VfxU8* memHead, const VfxU8* memTail, VfxObject *parent)
{
    if(s_xmlLoader)
        return NULL;

    VFX_ASSERT(memHead != NULL);
    
    VFX_SYS_NEW(s_xmlLoader, VfxXmlLoaderImpl);

    VfxMemIstream is;
    is.open((VfxU8 *)memHead, (VfxU8 *)memTail);
    VfxObject *obj = s_xmlLoader->createObjectBeginFromStream(is, parent);
    is.close();

    if(!obj)
        createObjectEnd();

    return obj;
}


VfxObject *VfxXmlLoader::createObjectBegin(VfxResId id, VfxObject *parent)
{
    VfxU32 size;
    const VfxU8 *start;
    start = vfx_sys_res_get_binary(id, &size);
    if(!start)
    {
        return NULL;
    }
    return createObjectBegin(start, start + size, parent);
}


VfxObject *VfxXmlLoader::createObjectBegin(const VfxWChar *filename, VfxObject *parent)
{
    if(s_xmlLoader)
        return NULL;

    VfxFileIstream is;
    
    if (!is.open(filename))
    {
        // Error, do nothing and return NULL
        return NULL;
    }    
    VFX_SYS_NEW(s_xmlLoader, VfxXmlLoaderImpl);
    
    VfxObject *obj = s_xmlLoader->createObjectBeginFromStream(is, parent);
    is.close();

    if(!obj)
        createObjectEnd();

    return obj;
}


void VfxXmlLoader::createObjectEnd()
{
    VFX_SYS_DELETE(s_xmlLoader);
}


VfxObject *VfxXmlLoader::findObjByName(const VfxWString &name)
{
    // Assert if not in loadBegin / loadEnd pair
    VFX_ASSERT(s_xmlLoader != NULL);

    return s_xmlLoader->findObjByName(name);
}


VfxBool VfxXmlLoader::load(VfxObject *obj, const VfxU8* memHead, const VfxU8* memTail)
{
    VfxBool ret = loadBegin(obj, memHead, memTail);
    loadEnd();

    return ret;
}


VfxBool VfxXmlLoader::load(VfxObject *obj, VfxResId xmlResId)
{
    VfxBool ret = loadBegin(obj, xmlResId);
    loadEnd();

    return ret;
}


VfxBool VfxXmlLoader::load(VfxObject *obj, const VfxWChar *filename)
{
    VfxBool ret = loadBegin(obj, filename);
    loadEnd();

    return ret;
}


VfxObject *VfxXmlLoader::createObject(const VfxU8* memHead, const VfxU8* memTail, VfxObject *parent)
{
    VfxObject *ret = createObjectBegin(memHead, memTail, parent);
    createObjectEnd();
    
    return ret;
}


VfxObject *VfxXmlLoader::createObject(VfxResId id, VfxObject *parent)
{
    VfxObject *ret = createObjectBegin(id, parent);
    createObjectEnd();
    
    return ret;
}


VfxObject *VfxXmlLoader::createObject(const VfxWChar *filename, VfxObject *parent)
{
    VfxObject *ret = createObjectBegin(filename, parent);
    createObjectEnd();
    
    return ret;
}

VfxXmlLoaderImpl::VfxXmlLoaderImpl():
    m_rootObj(NULL),
    m_nameTableHead(NULL),
    m_level(0)
{

}

VfxXmlLoaderImpl::~VfxXmlLoaderImpl()
{
    clearNameTable();
}

VfxBool VfxXmlLoaderImpl::loadBeginFromStream(VfxObject *obj, VfxInputStream &is)
{
    VFX_DEV_ASSERT(m_level == 0);

    if (obj == NULL)
    {
        // Do nothing
        return VFX_FALSE;
    }

    if (!parseFileHeader(is))
    {
        // Wrong header
        VXML_PRINT0(m_level, "Error: Wrong header");
        return VFX_FALSE;
    }

    VfxXmlClassIdEnum classId;
    parseClassId(is, classId);
    if (classId == VFX_XML_CLASS_ID_Unknown)
    {
        // Wrong class ID
        VXML_PRINT0(m_level, "Error: Invalid class id");
        return VFX_FALSE;
    }

    if (!obj->isKindOf(getClassInfo(classId)))
    {
        // The object does not match the class ID
        VXML_PRINT0(m_level, "Error: The object does not match the class ID");
        return VFX_FALSE;
    }

    m_rootObj = obj;

    return parsePropList(is, obj);
}


VfxObject *VfxXmlLoaderImpl::createObjectBeginFromStream(VfxInputStream &is, VfxObject *parent)
{
    VFX_DEV_ASSERT(m_level == 0);
    if (!parseFileHeader(is))
    {
        // Wrong header
        return VFX_FALSE;
    }

    VfxXmlClassIdEnum classId;
    parseClassId(is, classId);
    if (classId == VFX_XML_CLASS_ID_Unknown)
    {
        // Wrong class ID
        return NULL;
    }

    VfxObject *obj = createObjectById(classId, parent);
    if (obj == NULL)
    {
        return NULL;
    }

    m_rootObj = obj;

    if (!parsePropList(is, obj))
    {
        // If load the object error, close it
        VFX_OBJ_CLOSE(obj);
    }

    return obj;
}


VfxBool VfxXmlLoaderImpl::parseFileHeader(VfxInputStream &is)
{
    VfxU8 header[4];
    is.read(header, sizeof(header));

    if (header[0] != 'V' || header[1] != 'X')
    {
        return VFX_FALSE;
    }

    if (header[2] != VFX_XML_VER_MAJOR || header[3] != VFX_XML_VER_MINOR)
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


VfxBool VfxXmlLoaderImpl::parseClassId(VfxInputStream &is, VfxXmlClassIdEnum &classId)
{
    VfxU32 classIdValue = (VfxU32)VFX_XML_CLASS_ID_Unknown;
    is.read((VfxU8 *)&classIdValue, sizeof(classIdValue));

    classId = (VfxXmlClassIdEnum)(classIdValue>> 16);

    return VFX_TRUE;
}


VfxBool VfxXmlLoaderImpl::parseObjList(VfxInputStream &is, VfxObject *parent)
{
    // Parse object list
    while (1)
    {
        VfxXmlClassIdEnum classId;
        parseClassId(is, classId);
        if (classId == VFX_XML_CLASS_ID_Unknown)
        {
            // Tail of object list
            break;
        }

        VfxObject *obj = createObjectById(classId, parent);
        if (obj == NULL)
        {
            // Can not create object
            return VFX_FALSE;
        }
        
        if (!parsePropList(is, obj))
        {
            // Got some error
            return VFX_FALSE;
        }
    }

    return VFX_TRUE;
}


VfxBool VfxXmlLoaderImpl::parsePropList(VfxInputStream &is, VfxObject *obj)
{
    VFX_DEV_ASSERT(obj != NULL);

    m_level ++;
    VfxBool bRet = VFX_TRUE;

    // Parse property list
    while (1)
    {
        VfxU32 propIdValue = (VfxU32)VFX_XML_PROP_ID_Unknown;
        is.read((VfxU8 *)&propIdValue, sizeof(propIdValue));

        VfxXmlPropIdEnum propId = (VfxXmlPropIdEnum)(propIdValue & 0xffff);
        if (propId == VFX_XML_PROP_ID_Unknown)
        {
            // Tail of property list
            break;
        }
        if (propId >= VFX_XML_PROP_ID_END_OF_ENUM)
        {
            // Error property ID
            bRet = VFX_FALSE;
            break;
        }

        VfxU32 subType = propIdValue >> 16;
        if (!parseProperty(is, obj, propId, subType))
        {
            // Got some error
            bRet = VFX_FALSE;
            break;
        }
    }    

    m_level --;
    return bRet;
}


VfxBool VfxXmlLoaderImpl::parseProperty(VfxInputStream &is, VfxObject *obj, VfxXmlPropIdEnum propId, VfxU32 subType)
{
    VFX_DEV_ASSERT(obj != NULL);
    VFX_DEV_ASSERT(propId != VFX_XML_PROP_ID_Unknown && propId < VFX_XML_PROP_ID_END_OF_ENUM);    

    const VfxXmlPropertyTableEntry &property = g_vfxXmlPropertyTable[propId];
    if (property.handler == NULL)
    {
        // Not support, do nothing
        return VFX_FALSE;
    }

#ifdef __VXML_DEBUG_INFO__
    if(propId != VFX_XML_PROP_ID_VfxObject_items)
    {
        VXML_PRINT1(m_level, "=>%s", property.propName);
    }
#endif
    VfxXmlTypeHandlerParam param;
    param.memFuncPtr = property.memFuncPtr;
    param.subType = subType;
    param.propId = propId;
    param.loader = this;
    return property.handler(obj, is, param);
}


VfxBase *VfxXmlLoaderImpl::createStructById(VfxXmlStructIdEnum structId)
{
    VFX_DEV_ASSERT(structId != VFX_XML_CLASS_ID_Unknown && structId < VFX_XML_CLASS_ID_END_OF_ENUM);
    
    const VfxXmlStructTableEntry &entry = g_vfxXmlStructTable[structId];
    if (entry.createFuncPtr == NULL)
    {
        return NULL;
    }
    
    return entry.createFuncPtr();
}


VfxBool VfxXmlLoaderImpl::parseMemberList(VfxInputStream &is, VfxBase *base)
{
    VFX_DEV_ASSERT(base != NULL);

    // Parse property list
    while (1)
    {
        VfxU32 structMemberIdValue = (VfxU32)VFX_XML_STRUCT_MEMBER_ID_Unknown;
        is.read((VfxU8 *)&structMemberIdValue, sizeof(structMemberIdValue));

        VfxXmlStructMemberIdEnum structMemberId = (VfxXmlStructMemberIdEnum)(structMemberIdValue & 0xffff);
        if (structMemberId == VFX_XML_STRUCT_MEMBER_ID_Unknown)
        {
            // Tail of structure member list
            break;
        }
        if (structMemberId >= VFX_XML_STRUCT_MEMBER_ID_END_OF_ENUM)
        {
            // Error structure member ID
            return VFX_FALSE;
        }

        const VfxXmlStructMemberTableEntry &entry = g_vfxXmlStructMemberTable[structMemberId];

        VfxXmlTypeHandlerParam param;
        param.memFuncPtr = NULL;
        param.subType = structMemberIdValue >> 16;
        param.loader = this;
        
        void *data = ((VfxU8 *)base) + entry.offset;
        if (!entry.handler(data, is, param))
        {
            return VFX_FALSE;
        }
    }    

    return VFX_TRUE;
}



VfxClassInfo *VfxXmlLoaderImpl::getClassInfo(VfxXmlClassIdEnum classId)
{
    VFX_DEV_ASSERT(classId != VFX_XML_CLASS_ID_Unknown && classId < VFX_XML_CLASS_ID_END_OF_ENUM);
    
    const VfxXmlClassTableEntry &entry = g_vfxXmlClassTable[classId];
    VFX_DEV_ASSERT(entry.funcPtr != NULL);
    
    VfxClassInfo *classInfo = entry.funcPtr();
    VFX_DEV_ASSERT(classInfo != NULL);

    return classInfo;
}


VfxObject *VfxXmlLoaderImpl::createObjectById(VfxXmlClassIdEnum classId, VfxObject *parent)
{
    VfxClassInfo *classInfo = getClassInfo(classId);
    if (classInfo == NULL)
    {
        VXML_PRINT1(m_level, "Error: Invalid class id: %d", classId);
        return NULL;
    }
    

    VfxObject *obj = classInfo->createObject(parent);

    VXML_PRINT2(m_level, "[%s] creation:(%x)", g_vfxXmlClassTable[classId].className, obj);
    
    return obj;
}


void VfxXmlLoaderImpl::addNameTableEntry(const VfxWString &name, VfxObject *objPtr)
{
    VFX_DEV_ASSERT(!name.isNull());
    VFX_DEV_ASSERT(objPtr != NULL);
    
    NameTableEntry *entry;
    VFX_SYS_NEW(entry, NameTableEntry);
    entry->name     = name;
    entry->ObjPtr   = objPtr;

    // Add to table
    entry->next     = m_nameTableHead;
    m_nameTableHead = entry;
}

void VfxXmlLoaderImpl::clearNameTable()
{
    NameTableEntry *entry = m_nameTableHead;
    while (entry != NULL)
    {
        NameTableEntry *next = entry->next;

        VFX_SYS_DELETE(entry);

        entry = next;
    }

    m_nameTableHead = NULL;
}

VfxObject *VfxXmlLoaderImpl::findObjByName(const VfxWString &name) const
{
    // Assert if loader is end
    VFX_ASSERT(m_rootObj != NULL);

    NameTableEntry *entry;
    for (entry = m_nameTableHead; entry != NULL; entry = entry->next)
    {
        if (entry->name == name)
        {
            return entry->ObjPtr.get();
        }
    }

    return NULL;
}
