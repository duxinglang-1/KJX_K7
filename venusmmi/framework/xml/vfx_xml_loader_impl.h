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
 *  vfx_xml_loader_impl.h
 *
 * Project:
 * --------
 *  Venus XML
 *
 * Description:
 * ------------
 *  Venus XML loader internal implementation
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef __VFX_XML_LOADER_IMPL_H__
#define __VFX_XML_LOADER_IMPL_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_xml_enum.h"

/***************************************************************************** 
 * Class VfxXmlLoader
 *****************************************************************************/

/*
 * VfxXmlLoader is a static class
 */
class VfxXmlLoaderImpl : public VfxBase
{
    friend class VfxXmlLoader;
// Constructor / Destructor
public:
    // Constructor
    VfxXmlLoaderImpl();

    // Destructor
    virtual ~VfxXmlLoaderImpl();

// Implementaion
private:
    VfxBool loadBeginFromStream(
        VfxObject *obj,
        VfxInputStream &is
    );

    VfxObject *createObjectBeginFromStream(
        VfxInputStream &is,
        VfxObject *parent
    );

// Implementaion. Parsing method
public:
    VfxBool parseFileHeader(VfxInputStream &is);
    VfxBool parseClassId(VfxInputStream &is, VfxXmlClassIdEnum &classId);
    VfxBool parseObjList(VfxInputStream &is, VfxObject *parent);
    
    VfxObject *createObjectById(VfxXmlClassIdEnum classId, VfxObject *parent);
    VfxBool parsePropList(VfxInputStream &is, VfxObject *obj);
    VfxBool parseProperty(VfxInputStream &is, VfxObject *obj, VfxXmlPropIdEnum propId, VfxU32 subType);
    
    VfxBase *createStructById(VfxXmlStructIdEnum structId);
    VfxBool parseMemberList(VfxInputStream &is, VfxBase *base);

    VfxObject *getRoot() const
    {
        return m_rootObj;
    };
    
    void addNameTableEntry(const VfxWString &name, VfxObject *objPtr);
    VfxObject *findObjByName(const VfxWString &name) const;

// Implementaion
private:
    VfxClassInfo *getClassInfo(enum VfxXmlClassIdEnum classId);

    void clearNameTable();
    
    class NameTableEntry : public VfxBase
    {
    public:
        NameTableEntry *next;
        VfxWString      name;
        VfxObjWeakPtr   ObjPtr;
    };
    
    VfxObject       *m_rootObj;
    NameTableEntry  *m_nameTableHead;
    VfxS32          m_level;
};


#endif /* __VFX_XML_LOADER_IMPL_H__ */

