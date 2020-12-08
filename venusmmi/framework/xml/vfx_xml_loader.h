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
 *  vfx_xml_loader.h
 *
 * Project:
 * --------
 *  Venus XML
 *
 * Description:
 * ------------
 *  Venus XML loader
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_XML_LOADER_H__
#define __VFX_XML_LOADER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxBase
#include "vfx_cpp_base.h"
#include "vfx_object.h"

#include "vfx_object.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_stream.h"
#include "vfx_class_info.h"
#include "vfx_weak_ptr.h"

#include "vfx_xml_enum.h"

/***************************************************************************** 
 * Macro
 *****************************************************************************/

#define VFX_XML_FIND_OBJ(_loader, _name, _className) VFX_OBJ_DYNAMIC_CAST((_loader)->findObj(_name), _className)


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// Predefined classes
class VfxObject;
class VfxClassInfo;
class VfxXmlLoaderImpl;


/***************************************************************************** 
 * Class VfxXmlLoader
 *****************************************************************************/

class VfxXmlLoader : public VfxObject
{
// Constructor / Destructor
public:
    // Constructor
    VfxXmlLoader();

    // Destructor
    virtual ~VfxXmlLoader();

// Method
public:
    VfxBool loadXml(
        const VfxU8* memHead, 
        const VfxU8* memTail = NULL
    );

    VfxBool loadXml(
        VfxResId xmlResId
    );

    VfxBool loadXml(
        const VfxWChar *filename
    );

    VfxObject *findObj(const VfxWString &name);

// Override
protected:
    virtual void onDeinit();

private:
    VfxXmlLoaderImpl *m_impl;

/*****************************************************************************
 * VfxXmlLoader static part
 */
public:
    static VfxBool loadBegin(
        VfxObject *obj,
        const VfxU8* memHead, 
        const VfxU8* memTail = NULL
    );

    static VfxBool loadBegin(
        VfxObject *obj, 
        VfxResId xmlResId
    );
    
    static VfxBool loadBegin(
        VfxObject *obj, 
        const VfxWChar *filename
    );
    
    static void loadEnd();


    static VfxObject *createObjectBegin(
        const VfxU8* memHead, 
        const VfxU8* memTail,
        VfxObject *parent
    );

    static VfxObject *createObjectBegin(
        VfxResId id,
        VfxObject *parent
    );
    
    static VfxObject *createObjectBegin(
        const VfxWChar *filename,
        VfxObject *parent
    );

    static void createObjectEnd();


    static VfxObject *findObjByName(const VfxWString &name);

// Helper methods
public:
    static VfxBool load(
        VfxObject *obj,
        const VfxU8* memHead, 
        const VfxU8* memTail = NULL
    );

    static VfxBool load(
        VfxObject *obj, 
        VfxResId xmlResId
    );
    
    static VfxBool load(
        VfxObject *obj, 
        const VfxWChar *filename
    );
    
    static VfxObject *createObject(
        const VfxU8* memHead, 
        const VfxU8* memTail,
        VfxObject *parent
    );

    static VfxObject *createObject(
        VfxResId id,
        VfxObject *parent
    );
    
    static VfxObject *createObject(
        const VfxWChar *filename,
        VfxObject *parent
    );

    static VfxXmlLoaderImpl *s_xmlLoader;
};


#endif /* __VFX_XML_LOADER_H__ */

