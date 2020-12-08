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
 *  vfx_xml_table.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_XML_TABLE_H__
#define __VFX_XML_TABLE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxObject
#include "vfx_object.h"

#include "vfx_datatype.h"
#include "vfx_class_info.h"
#include "vfx_cpp_base.h"

#include "vfx_xml_prop_handler.h"


/***************************************************************************** 
 * Macro
 *****************************************************************************/

#if !defined(__MTK_TARGET__) && defined(WIN32)
#define __VXML_DEBUG_INFO__
#endif


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/*
 * Venus XML enum support
 */

typedef void (*VfxXmlEnumObjSettingFuncPtr)(
    VfxObject *obj,
    VfxXmlPropTypeUnknownHandlerPtr memFuncPtr,
    VfxU32 value);

struct VfxXmlEnumValueTableEntry
{
    VfxU32 value;
    VfxU32 sizeOfValue;
    VfxXmlEnumObjSettingFuncPtr objSettingFuncPtr;
};


/*
 * Venus XML class table data types
 */

typedef VfxClassInfo *(*VfxXmlLoaderGetClassInfoFuncPtr)();

struct VfxXmlClassTableEntry
{
    VfxXmlLoaderGetClassInfoFuncPtr funcPtr;
#ifdef __VXML_DEBUG_INFO__
    const VfxChar *className;
#endif
};


/*
 * Venus XML property table data types
 */

struct VfxXmlPropertyTableEntry
{
    VfxXmlPropTypeHandlerPtr handler;
    VfxU32 subType;
    VfxXmlSetPropMemFuncPtr memFuncPtr;
#ifdef __VXML_DEBUG_INFO__
    const VfxChar *propName;
#endif
};

typedef void (VfxObject::*VfxXmlSlotMemFuncPtr)();


/*
 * Venus XML slot table data types
 */

struct VfxXmlSlotTableEntry
{
    VfxXmlSlotMemFuncPtr memFuncPtr;
};

typedef VfxBase *(*VfxXmlCreateStructFuncPtr)();


/*
 * Venus XML structure table data types
 */

struct VfxXmlStructTableEntry
{
    VfxXmlCreateStructFuncPtr createFuncPtr;    
};

struct VfxXmlStructMemberTableEntry
{
    VfxU32 offset;
    VfxXmlTypeHandlerPtr handler;
};


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
 
extern const VfxXmlEnumValueTableEntry g_vfx_XmlEnumValueTable[];

extern const VfxXmlClassTableEntry g_vfxXmlClassTable[];
extern const VfxXmlPropertyTableEntry g_vfxXmlPropertyTable[];
extern const VfxXmlSlotTableEntry g_vfxXmlSlotTable[];

extern const VfxXmlStructTableEntry g_vfxXmlStructTable[];
extern const VfxXmlStructMemberTableEntry g_vfxXmlStructMemberTable[];

#endif /* __VFX_XML_TABLE_H__ */

