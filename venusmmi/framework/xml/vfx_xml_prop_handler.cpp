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
 *  vfx_xml_handler.cpp
 *
 * Project:
 * --------
 *  Venus XML
 *
 * Description:
 * ------------
 *  Venus XML Property Handlers
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "ui_core\base\vfx_base.h"
#include "ui_core\pme\vfx_pme.h"

#include "vfx_xml_prop_handler.h"
#include "vfx_xml_loader.h"
#include "vfx_xml_loader_impl.h"
#include "vfx_xml_table.h"

extern "C"
{
#include "string.h"
}

#include "vrt_datatype.h"

#include "vfx_cpp_base.h"
#include "vfx_stream.h"
#include "vfx_datatype.h"
#include "vfx_xml_enum.h"
#include "vfx_basic_type.h"
#include "vfx_string.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_signal.h"

#include "vcp_state_image.h"
#include "vfx_frame.h"
#include "vfx_frame_aligner.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_XML_LOADER_MAX_STR_LEN          63


/***************************************************************************** 
 * Local Function
 *****************************************************************************/

static VfxFrameAlignerModeEnum vfxXmlMapU8toAlignerMode(VfxU8 mode)
{
    switch(mode)
    {
    case 0:
    default:
        return VFX_FRAME_ALIGNER_MODE_NONE;
    case 1:
        return VFX_FRAME_ALIGNER_MODE_SIDE;
    case 2:
        return VFX_FRAME_ALIGNER_MODE_MID;
    }
}

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

VfxBool vfxXmlStructTypeEnumHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(data != NULL);

    VfxS32 enumValueId;
    is.read((VfxU8 *)&enumValueId, sizeof(enumValueId));

    if (enumValueId == VFX_XML_ENUM_ID_Unknown || 
        enumValueId >= VFX_XML_ENUM_ID_END_OF_ENUM)
    {
        return VFX_FALSE;
    }

    const VfxXmlEnumValueTableEntry &entry = g_vfx_XmlEnumValueTable[enumValueId];    
    if (entry.sizeOfValue == 0)
    {
        return VFX_FALSE;
    }
    
    // Assign enum value
    memcpy(data, &entry.value, entry.sizeOfValue);

    return VFX_TRUE;
}


VfxBool vfxXmlStructTypeVfxBoolHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(data != NULL);

    VfxS32 value;
    is.read((VfxU8 *)&value, sizeof(value));

    *(VfxBool *)data = value != 0;

    return VFX_TRUE;
}


VfxBool vfxXmlStructTypeVfxS32Handler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(data != NULL);

    is.read((VfxU8 *)data, sizeof(VfxS32));

    return VFX_TRUE;
}

VfxBool vfxXmlStructTypeVfxU32Handler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(data != NULL);

    is.read((VfxU8 *)data, sizeof(VfxU32));

    return VFX_TRUE;
}

VfxBool vfxXmlStructTypeVfxIdHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    return vfxXmlStructTypeVfxU32Handler(data, is, param);
}

VfxBool vfxXmlStructTypeVfxMsecHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(data != NULL);

    is.read((VfxU8 *)data, sizeof(VfxMsec));

    return VFX_TRUE;
}


VfxBool vfxXmlStructTypeVfxFloatHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(data != NULL);

    is.read((VfxU8 *)data, sizeof(VfxFloat));

    return VFX_TRUE;
}


VfxBool vfxXmlStructTypeVfxColorHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(data != NULL);

    is.read((VfxU8 *)data, sizeof(VfxColor));

    return VFX_TRUE;
}


VfxBool vfxXmlStructTypeVfxPointHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(data != NULL);

    is.read((VfxU8 *)data, sizeof(VfxPoint));

    return VFX_TRUE;
}


VfxBool vfxXmlStructTypeVfxSizeHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(data != NULL);

    is.read((VfxU8 *)data, sizeof(VfxSize));

    return VFX_TRUE;
}


VfxBool vfxXmlStructTypeVfxRectHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(data != NULL);

    is.read((VfxU8 *)data, sizeof(VfxRect));

    return VFX_TRUE;
}


VfxBool vfxXmlStructTypeVfxFPointHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(data != NULL);

    is.read((VfxU8 *)data, sizeof(VfxFPoint));

    return VFX_TRUE;
}


VfxBool vfxXmlStructTypeVfxWStringHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(data != NULL);

    VfxWString &str = *(VfxWString *)data;

    // Read header
    VfxU32 header;
    is.read((VfxU8 *)&header, sizeof(header));

    VfxU32 headerType = header & 0xffff;
    if (headerType == 0x0000)
    {
        // NULL String
        // Do nothing
    }
    else if (headerType == 0x0001)
    {
        // Resource ID
        str = VFX_WSTR_RES(header >> 16);
    }
    else if (headerType == 0x0002)
    {
        // Constant string
        VfxU32 length = header >> 16;
        VfxU32 readLength = length;
        VfxWChar buffer[VFX_XML_LOADER_MAX_STR_LEN + 1];
        if (readLength >= VFX_XML_LOADER_MAX_STR_LEN)
        {
            readLength = VFX_XML_LOADER_MAX_STR_LEN;
        }

        is.read((VfxU8 *)buffer, sizeof(VfxWChar) * readLength);
        buffer[readLength] = 0;

        VfxU32 totalBytes = sizeof(VfxWChar) * (length + 1);
        VfxU32 ignoreBytes = totalBytes - sizeof(VfxWChar) * readLength;
        if (totalBytes % 4 != 0)
        {
            ignoreBytes += (4 - totalBytes % 4);
        }
        
        is.ignore(ignoreBytes);

        str = VFX_WSTR_MEM(buffer);
    }
    else
    {
        // Unknown type
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


VfxBool vfxXmlStructTypeVfxResIdHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(data != NULL);

    VfxU32 value;
    is.read((VfxU8 *)&value, sizeof(value));

    *(VfxResId *)data = (VfxResId)value;

    return VFX_TRUE;
}


VfxBool vfxXmlStructTypeVfxFrameAlignStructHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(data != NULL);

    VfxU8 value[4];
    is.read((VfxU8 *)value, sizeof(value));

    VfxFrameAlignStruct *ptr = (VfxFrameAlignStruct *)data;
    ptr->modeLeft   = vfxXmlMapU8toAlignerMode(value[0]);
    ptr->modeTop    = vfxXmlMapU8toAlignerMode(value[1]);
    ptr->modeRight  = vfxXmlMapU8toAlignerMode(value[2]);
    ptr->modeBottom = vfxXmlMapU8toAlignerMode(value[3]);

    return VFX_TRUE;
}


VfxBool vfxXmlStructTypeVcpStateImageHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(data != NULL);

    VcpStateImage &img = *(VcpStateImage *)data;

    // Read header
    VfxU32 header;
    is.read((VfxU8 *)&header, sizeof(header));

    VfxU32 headerType = header & 0xffff;
    if (headerType == 0x0000)
    {
        // NULL Image
        // Do nothing
    }
    else if (headerType == 0x0001)
    {
        // only Normal id
        img = VcpStateImage(header >> 16);
    }
    else if (headerType == 0x0002)
    {
        // all 4 id
        VfxU16 ids[4];

        is.read((VfxU8 *)ids, sizeof(VfxU16) * 4);

        img = VcpStateImage(ids[0], ids[1], ids[2], ids[3]);
    }
    else
    {
        // Unknown type
        return VFX_FALSE;
    }

    return VFX_TRUE;

}


VfxBool vfxXmlPropTypeUnknownHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    // Should not be called
    VFX_DEV_ASSERT(0);

    return VFX_FALSE;
}


VfxBool vfxXmlPropTypeStructHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(obj != NULL);
    
    VfxXmlStructIdEnum structId = (VfxXmlStructIdEnum)param.subType;
    VfxBase *base = param.loader->createStructById(structId);
    if (base == NULL)
    {
        return VFX_FALSE;
    }

    if (!param.loader->parseMemberList(is, base))
    {
        return VFX_FALSE;
    }

    VfxXmlPropTypeStructHandlerPtr memFuncPtr = 
        (VfxXmlPropTypeStructHandlerPtr)param.memFuncPtr;
    if (memFuncPtr != NULL)
    {
        (obj->*memFuncPtr)(*(VfxBase *)base);
    }

    VFX_SYS_DELETE(base);

    return VFX_TRUE;
}


VfxBool vfxXmlPropTypeObjectHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(obj != NULL);
    
    VfxXmlClassIdEnum classId = (VfxXmlClassIdEnum)param.subType;
    VfxObject *newObj = param.loader->createObjectById(classId, obj);
    if (newObj == NULL)
    {
        return VFX_FALSE;
    }

    if (!param.loader->parsePropList(is, newObj))
    {
        return VFX_FALSE;
    }

    VfxXmlPropTypeObjectHandlerPtr memFuncPtr = 
        (VfxXmlPropTypeObjectHandlerPtr)param.memFuncPtr;
    if (memFuncPtr != NULL)
    {
        (obj->*memFuncPtr)(newObj);
    }

    return VFX_TRUE;
}


VfxBool vfxXmlPropTypeObjNameHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(obj != NULL);
    
    VfxWString name;
    if (!vfxXmlStructTypeVfxWStringHandler(&name, is, param))
    {
        return VFX_FALSE;
    }

    param.loader->addNameTableEntry(name, obj);
    
    return VFX_TRUE;
}


VfxBool vfxXmlPropTypeEnumHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(obj != NULL);
    VFX_DEV_ASSERT(param.memFuncPtr != NULL);
    VFX_DEV_ASSERT(param.subType == 0);

    VfxS32 enumValueId;
    is.read((VfxU8 *)&enumValueId, sizeof(enumValueId));

    if (enumValueId == VFX_XML_ENUM_ID_Unknown || 
        enumValueId >= VFX_XML_ENUM_ID_END_OF_ENUM)
    {
        return VFX_FALSE;
    }

    const VfxXmlEnumValueTableEntry &entry = g_vfx_XmlEnumValueTable[enumValueId];    
    if (entry.sizeOfValue == 0 || entry.objSettingFuncPtr == NULL)
    {
        return VFX_FALSE;
    }

    entry.objSettingFuncPtr(
        obj,
        param.memFuncPtr,
        entry.value);

    return VFX_TRUE;
}


VfxBool vfxXmlPropTypeVfxBoolHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(obj != NULL);
    VFX_DEV_ASSERT(param.memFuncPtr != NULL);
    VFX_DEV_ASSERT(param.subType == 0);

    VfxBool value = 0;
    if (!vfxXmlStructTypeVfxBoolHandler(&value, is, param))
    {
        return VFX_FALSE;
    }
    
    VfxXmlPropTypeVfxBoolHandlerPtr memFuncPtr = 
        (VfxXmlPropTypeVfxBoolHandlerPtr)param.memFuncPtr;
    (obj->*memFuncPtr)(value);

    return VFX_TRUE;
}


VfxBool vfxXmlPropTypeVfxS32Handler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(obj != NULL);
    VFX_DEV_ASSERT(param.memFuncPtr != NULL);
    VFX_DEV_ASSERT(param.subType == 0);
    
    VfxS32 value = 0;
    if (!vfxXmlStructTypeVfxS32Handler(&value, is, param))
    {
        return VFX_FALSE;
    }
    
    VfxXmlPropTypeVfxS32HandlerPtr memFuncPtr = 
        (VfxXmlPropTypeVfxS32HandlerPtr)param.memFuncPtr;
    (obj->*memFuncPtr)(value);

    return VFX_TRUE;
}

VfxBool vfxXmlPropTypeVfxU32Handler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(obj != NULL);
    VFX_DEV_ASSERT(param.memFuncPtr != NULL);
    VFX_DEV_ASSERT(param.subType == 0);
    
    VfxU32 value = 0;
    if (!vfxXmlStructTypeVfxS32Handler(&value, is, param))
    {
        return VFX_FALSE;
    }
    
    VfxXmlPropTypeVfxU32HandlerPtr memFuncPtr = 
        (VfxXmlPropTypeVfxU32HandlerPtr)param.memFuncPtr;
    (obj->*memFuncPtr)(value);

    return VFX_TRUE;
}

VfxBool vfxXmlPropTypeVfxIdHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    return vfxXmlPropTypeVfxU32Handler(obj, is, param);
}

VfxBool vfxXmlPropTypeVfxMsecHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(obj != NULL);
    VFX_DEV_ASSERT(param.memFuncPtr != NULL);
    VFX_DEV_ASSERT(param.subType == 0);
    
    VfxMsec value = 0;
    if (!vfxXmlStructTypeVfxMsecHandler(&value, is, param))
    {
        return VFX_FALSE;
    }
    
    VfxXmlPropTypeVfxMsecHandlerPtr memFuncPtr = 
        (VfxXmlPropTypeVfxMsecHandlerPtr)param.memFuncPtr;
    (obj->*memFuncPtr)(value);

    return VFX_TRUE;
}


VfxBool vfxXmlPropTypeVfxFloatHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(obj != NULL);
    VFX_DEV_ASSERT(param.memFuncPtr != NULL);
    VFX_DEV_ASSERT(param.subType == 0);
    
    VfxFloat value = 0.0f;
    if (!vfxXmlStructTypeVfxFloatHandler(&value, is, param))
    {
        return VFX_FALSE;
    }
    
    VfxXmlPropTypeVfxFloatHandlerPtr memFuncPtr = 
        (VfxXmlPropTypeVfxFloatHandlerPtr)param.memFuncPtr;
    (obj->*memFuncPtr)(value);

    return VFX_TRUE;
}


VfxBool vfxXmlPropTypeVfxColorHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(obj != NULL);
    VFX_DEV_ASSERT(param.memFuncPtr != NULL);
    VFX_DEV_ASSERT(param.subType == 0);
    
    VfxColor value;
    if (!vfxXmlStructTypeVfxColorHandler(&value, is, param))
    {
        return VFX_FALSE;
    }
    
    VfxXmlPropTypeVfxColorHandlerPtr memFuncPtr = 
        (VfxXmlPropTypeVfxColorHandlerPtr)param.memFuncPtr;
    (obj->*memFuncPtr)(value);
    
    return VFX_TRUE;
}


VfxBool vfxXmlPropTypeVfxPointHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(obj != NULL);
    VFX_DEV_ASSERT(param.memFuncPtr != NULL);
    VFX_DEV_ASSERT(param.subType == 0);
    
    VfxPoint value;
    if (!vfxXmlStructTypeVfxPointHandler(&value, is, param))
    {
        return VFX_FALSE;
    }
    
    VfxXmlPropTypeVfxPointHandlerPtr memFuncPtr = 
        (VfxXmlPropTypeVfxPointHandlerPtr)param.memFuncPtr;
    (obj->*memFuncPtr)(value);
    
    return VFX_TRUE;
}


VfxBool vfxXmlPropTypeVfxSizeHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(obj != NULL);
    VFX_DEV_ASSERT(param.memFuncPtr != NULL);
    VFX_DEV_ASSERT(param.subType == 0);
    
    VfxSize value;
    if (!vfxXmlStructTypeVfxSizeHandler(&value, is, param))
    {
        return VFX_FALSE;
    }
    
    VfxXmlPropTypeVfxSizeHandlerPtr memFuncPtr = 
        (VfxXmlPropTypeVfxSizeHandlerPtr)param.memFuncPtr;
    (obj->*memFuncPtr)(value);
    
    return VFX_TRUE;
}


VfxBool vfxXmlPropTypeVfxRectHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(obj != NULL);
    VFX_DEV_ASSERT(param.memFuncPtr != NULL);
    VFX_DEV_ASSERT(param.subType == 0);
    
    VfxRect value;
    if (!vfxXmlStructTypeVfxRectHandler(&value, is, param))
    {
        return VFX_FALSE;
    }
    
    VfxXmlPropTypeVfxRectHandlerPtr memFuncPtr = 
        (VfxXmlPropTypeVfxRectHandlerPtr)param.memFuncPtr;
    (obj->*memFuncPtr)(value);

    return VFX_TRUE;
}


VfxBool vfxXmlPropTypeVfxFPointHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(obj != NULL);
    VFX_DEV_ASSERT(param.memFuncPtr != NULL);
    VFX_DEV_ASSERT(param.subType == 0);
    
    VfxFPoint value;
    if (!vfxXmlStructTypeVfxFPointHandler(&value, is, param))
    {
        return VFX_FALSE;
    }
    
    VfxXmlPropTypeVfxFPointHandlerPtr memFuncPtr = 
        (VfxXmlPropTypeVfxFPointHandlerPtr)param.memFuncPtr;
    (obj->*memFuncPtr)(value);

    return VFX_TRUE;
}


VfxBool vfxXmlPropTypeVfxWStringHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(obj != NULL);
    VFX_DEV_ASSERT(param.memFuncPtr != NULL);
    VFX_DEV_ASSERT(param.subType == 0);

    VfxWString str;
    if (!vfxXmlStructTypeVfxWStringHandler(&str, is, param))
    {
        return VFX_FALSE;
    }

    // Set property
    VfxXmlPropTypeVfxWStringHandlerPtr memFuncPtr = 
        (VfxXmlPropTypeVfxWStringHandlerPtr)param.memFuncPtr;
    (obj->*memFuncPtr)(str);

    return VFX_TRUE;
}

VfxBool vfxXmlPropTypeVfxResIdHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(obj != NULL);
    VFX_DEV_ASSERT(param.memFuncPtr != NULL);
    VFX_DEV_ASSERT(param.subType == 0);

    VfxResId resId;
    if (!vfxXmlStructTypeVfxResIdHandler(&resId, is, param))
    {
        return VFX_FALSE;
    }

    // Set property
    VfxXmlPropTypeVfxResIdHandlerPtr memFuncPtr = 
        (VfxXmlPropTypeVfxResIdHandlerPtr)param.memFuncPtr;
    (obj->*memFuncPtr)(resId);

    return VFX_TRUE;
}


VfxBool vfxXmlPropTypeVfxFrameAlignStructHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(obj != NULL);
    VFX_DEV_ASSERT(param.memFuncPtr != NULL);
    VFX_DEV_ASSERT(param.subType == 0);
    
    VfxFrameAlignStruct value;
    if (!vfxXmlStructTypeVfxFrameAlignStructHandler(&value, is, param))
    {
        return VFX_FALSE;
    }
    
    VfxXmlPropTypeVfxFrameAlignStructHandlerPtr memFuncPtr = 
        (VfxXmlPropTypeVfxFrameAlignStructHandlerPtr)param.memFuncPtr;
    (obj->*memFuncPtr)(value);

    return VFX_TRUE;
}


VfxBool vfxXmlPropTypeVfxXmlSignalHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(obj != NULL);
    VFX_DEV_ASSERT(param.memFuncPtr == NULL);

    VfxS32 value = 0;
    if (!vfxXmlStructTypeVfxS32Handler(&value, is, param))
    {
        return VFX_FALSE;
    }

    VfxXmlSlotIdEnum slodId = (VfxXmlSlotIdEnum)value;
    if (slodId == VFX_XML_SLOT_ID_Unknown || 
        value >= VFX_XML_SLOT_ID_END_OF_ENUM)
    {
        return VFX_FALSE;
    }

    // Connect signal to slot
    VfxXmlSignal &signal = 
        *(VfxXmlSignal *)(((VfxU8 *)obj) + 
            g_vfxXmlPropertyTable[param.propId].subType);
    
    VfxObject *root = param.loader->getRoot();
    VfxXmlSlot slot = (VfxXmlSlot)g_vfxXmlSlotTable[slodId].memFuncPtr;
    VFX_DEV_ASSERT(root != NULL);
    VFX_DEV_ASSERT(slot != NULL);

    signal.connect(root, slot);

    return VFX_TRUE;
}


VfxBool vfxXmlPropTypeVfxXmlIdSignalHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(obj != NULL);
    VFX_DEV_ASSERT(param.memFuncPtr == NULL);

    VfxS32 value = 0;
    if (!vfxXmlStructTypeVfxS32Handler(&value, is, param))
    {
        return VFX_FALSE;
    }

    VfxXmlSlotIdEnum slodId = (VfxXmlSlotIdEnum)value;
    if (slodId == VFX_XML_SLOT_ID_Unknown || 
        value >= VFX_XML_SLOT_ID_END_OF_ENUM)
    {
        return VFX_FALSE;
    }

    // Connect signal to slot
    VfxXmlIdSignal &signal = 
        *(VfxXmlIdSignal *)(((VfxU8 *)obj) + 
            g_vfxXmlPropertyTable[param.propId].subType);
    
    VfxObject *root = param.loader->getRoot();
    VfxXmlIdSlot slot = (VfxXmlIdSlot)g_vfxXmlSlotTable[slodId].memFuncPtr;
    VFX_DEV_ASSERT(root != NULL);
    VFX_DEV_ASSERT(slot != NULL);
    
    signal.connect(root, slot);

    return VFX_TRUE;
}

VfxBool vfxXmlPropTypeVcpStateImageHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param)
{
    VFX_DEV_ASSERT(obj != NULL);
    VFX_DEV_ASSERT(param.memFuncPtr != NULL);
    VFX_DEV_ASSERT(param.subType == 0);

    VcpStateImage img;
    if (!vfxXmlStructTypeVcpStateImageHandler(&img, is, param))
    {
        return VFX_FALSE;
    }

    // Set property
    VfxXmlPropTypeVcpStateImageHandlerPtr memFuncPtr = 
        (VfxXmlPropTypeVcpStateImageHandlerPtr)param.memFuncPtr;
    (obj->*memFuncPtr)(img);

    return VFX_TRUE;
}

