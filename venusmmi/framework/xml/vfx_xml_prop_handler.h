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
 *  vfx_xml_prop_handler.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_XML_PROP_HANDLER_H__
#define __VFX_XML_PROP_HANDLER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxObject
#include "vfx_object.h"

#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vfx_basic_type.h"
#include "vfx_transform.h"
#include "vfx_string.h"
#include "vfx_stream.h"
#include "vfx_signal.h"
    
#include "vfx_xml_enum.h"

#include "vcp_state_image.h"
#include "vfx_frame.h"

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

class VfxXmlLoaderImpl;

/*
 * Venus XML Property prototpes
 */

typedef void (VfxObject::*VfxXmlPropTypeUnknownHandlerPtr)();
typedef void (VfxObject::*VfxXmlPropTypeObjectHandlerPtr)(VfxObject *);
typedef void (VfxObject::*VfxXmlPropTypeStructHandlerPtr)(const VfxBase &);

typedef void (VfxObject::*VfxXmlPropTypeVfxBoolHandlerPtr)(VfxBool);
typedef void (VfxObject::*VfxXmlPropTypeVfxS32HandlerPtr)(VfxS32);
typedef void (VfxObject::*VfxXmlPropTypeVfxU32HandlerPtr)(VfxU32);
typedef void (VfxObject::*VfxXmlPropTypeVfxIdHandlerPtr)(VfxId);
typedef void (VfxObject::*VfxXmlPropTypeVfxMsecHandlerPtr)(VfxMsec);
typedef void (VfxObject::*VfxXmlPropTypeVfxFloatHandlerPtr)(VfxFloat);
typedef void (VfxObject::*VfxXmlPropTypeVfxColorHandlerPtr)(const VfxColor &);
typedef void (VfxObject::*VfxXmlPropTypeVfxPointHandlerPtr)(const VfxPoint &);
typedef void (VfxObject::*VfxXmlPropTypeVfxSizeHandlerPtr)(const VfxSize &);
typedef void (VfxObject::*VfxXmlPropTypeVfxRectHandlerPtr)(const VfxRect &);
typedef void (VfxObject::*VfxXmlPropTypeVfxFPointHandlerPtr)(const VfxFPoint &);
typedef void (VfxObject::*VfxXmlPropTypeVfxTransformHandlerPtr)(const VfxTransform &);
typedef void (VfxObject::*VfxXmlPropTypeVfxWStringHandlerPtr)(const VfxWString &);
typedef void (VfxObject::*VfxXmlPropTypeVfxResIdHandlerPtr)(VfxResId);
typedef void (VfxObject::*VfxXmlPropTypeVfxFrameAlignStructHandlerPtr)(const VfxFrameAlignStruct &);

typedef void (VfxObject::*VfxXmlPropTypeVcpStateImageHandlerPtr)(const VcpStateImage &);


/*
 * Venus XML Signal & Slot prototypes
 */

typedef VfxSignal1 <VfxObject *> VfxXmlSignal;
typedef VfxSignal2 <VfxObject *, VfxId> VfxXmlIdSignal;

typedef void (VfxObject::*VfxXmlSlot)(VfxObject *object);
typedef void (VfxObject::*VfxXmlIdSlot)(VfxObject *object, VfxId id);


/*
 * Venus XML Property Handler Parameters
 */
 
typedef void (VfxObject::*VfxXmlSetPropMemFuncPtr)();

struct VfxXmlTypeHandlerParam
{
    VfxXmlSetPropMemFuncPtr memFuncPtr;
    VfxU32 subType;
    VfxXmlPropIdEnum propId;
    VfxXmlLoaderImpl *loader;
};

// Venus XML type handler prototype
typedef VfxBool (*VfxXmlTypeHandlerPtr)(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param);

// Venus XML property type handler prototype
typedef VfxBool (*VfxXmlPropTypeHandlerPtr)(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param);


/***************************************************************************** 
 * Global Functions
 *****************************************************************************/

/*
 * Type handlers
 */

extern VfxBool vfxXmlStructTypeEnumHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param);

extern VfxBool vfxXmlStructTypeVfxBoolHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlStructTypeVfxS32Handler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlStructTypeVfxU32Handler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlStructTypeVfxIdHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlStructTypeVfxMsecHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlStructTypeVfxFloatHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlStructTypeVfxColorHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlStructTypeVfxPointHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlStructTypeVfxSizeHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlStructTypeVfxRectHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlStructTypeVfxFPointHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlStructTypeVfxWStringHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlStructTypeVfxResIdHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlStructTypeVfxFrameAlignStructHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param);

extern VfxBool vfxXmlStructTypeVcpStateImageHandler(void *data, VfxInputStream &is, VfxXmlTypeHandlerParam &param);

/*
 * Property handlers
 */

extern VfxBool vfxXmlPropTypeUnknownHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlPropTypeStructHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlPropTypeObjectHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlPropTypeObjNameHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param);

extern VfxBool vfxXmlPropTypeEnumHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param);

extern VfxBool vfxXmlPropTypeVfxBoolHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlPropTypeVfxS32Handler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlPropTypeVfxU32Handler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlPropTypeVfxIdHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlPropTypeVfxMsecHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlPropTypeVfxFloatHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlPropTypeVfxColorHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlPropTypeVfxPointHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlPropTypeVfxSizeHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlPropTypeVfxRectHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlPropTypeVfxFPointHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlPropTypeVfxWStringHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlPropTypeVfxResIdHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlPropTypeVfxFrameAlignStructHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param);

extern VfxBool vfxXmlPropTypeVcpStateImageHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param);

extern VfxBool vfxXmlPropTypeVfxXmlSignalHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param);
extern VfxBool vfxXmlPropTypeVfxXmlIdSignalHandler(VfxObject *obj, VfxInputStream &is, VfxXmlTypeHandlerParam &param);

#endif /* __VFX_XML_PROP_HANDLER_H__ */

