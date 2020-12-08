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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_widget_primitive.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the widget's primitive class
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include <string.h>

#include "vfx_uc_include.h"
#include "vapp_widget_def.h"
#include "vapp_widget_primitive.h"


/*****************************************************************************
 * Widget Id Class
 *****************************************************************************/

VappWidgetId::VappWidgetId() :
    m_source(VAPP_WIDGET_SRC_INVALID),
    m_typeKind(TYPE_KIND_UNKNOWN)
{
    // Do nothing.
}


VappWidgetId::VappWidgetId(VappWidgetSrcEnum source, VfxS32 type) :
    m_source(VAPP_WIDGET_SRC_INVALID),
    m_typeKind(TYPE_KIND_UNKNOWN)
{
    assignWith(source, type);
}


VappWidgetId::VappWidgetId(VappWidgetSrcEnum source, const VfxChar *typeString) :
    m_source(VAPP_WIDGET_SRC_INVALID),
    m_typeKind(TYPE_KIND_UNKNOWN)
{
    assignWith(source, typeString);
}


VappWidgetId::VappWidgetId(const VappWidgetId &other) :
    m_source(VAPP_WIDGET_SRC_INVALID),
    m_typeKind(TYPE_KIND_UNKNOWN)
{
    assignWith(other);
}


VappWidgetId::~VappWidgetId()
{
    clear();
}


VappWidgetId &VappWidgetId::operator =(const VappWidgetId &other)
{
    assignWith(other);

    return *this;
}


VfxBool VappWidgetId::operator ==(const VappWidgetId &other) const
{
    return compareWith(other);
}


VfxBool VappWidgetId::operator !=(const VappWidgetId &other) const
{
    return compareWith(other) ? VFX_FALSE : VFX_TRUE;
}


void VappWidgetId::assignWith(const VappWidgetId &other)
{
    clear();

    m_source = other.m_source;
    m_typeKind = other.m_typeKind;

    switch (other.m_typeKind)
    {
        case TYPE_KIND_INTEGER:
            m_type.ival = other.m_type.ival;
            break;

        case TYPE_KIND_STRING:
            assignTypeString(other.m_type.sval);
            break;

        default:
            VFX_ASSERT(0);
            break;
    }
}


void VappWidgetId::assignWith(VappWidgetSrcEnum source, VfxS32 type)
{
    clear();

    m_source = source;
    m_typeKind = TYPE_KIND_INTEGER;
    m_type.ival = type;
}


void VappWidgetId::assignWith(
    VappWidgetSrcEnum source,
    const VfxChar *typeString)
{
    clear();

    m_source = source;
    m_typeKind = TYPE_KIND_STRING;
    assignTypeString(typeString);
}


VfxBool VappWidgetId::compareWith(const VappWidgetId &other) const
{
    if (m_source != other.m_source || m_typeKind != other.m_typeKind)
    {
        return VFX_FALSE;
    }

    switch (m_typeKind)
    {
        case TYPE_KIND_INTEGER:
            if (m_type.ival != other.m_type.ival)
            {
                return VFX_FALSE;
            }
            break;

        case TYPE_KIND_STRING:
            if (strcmp(m_type.sval, other.m_type.sval) != 0)
            {
                return VFX_FALSE;
            }
            break;

        default:
            break;
    }

    return VFX_TRUE;
}


VappWidgetSrcEnum VappWidgetId::getSource() const
{
    return m_source;
}


VappWidgetId::TypeKindEnum VappWidgetId::getTypeKind() const
{
    return m_typeKind;
}


VfxS32 VappWidgetId::getIntType() const
{
    VFX_ASSERT(m_typeKind == TYPE_KIND_INTEGER);

    return m_type.ival;
}


const VfxChar *VappWidgetId::getStringType() const
{
    VFX_ASSERT(m_typeKind == TYPE_KIND_STRING);

    return m_type.sval;
}


VappWidgetId **VappWidgetId::newArray(VfxS32 size, VfxObject *parent)
{
    VappWidgetId **array;

    VFX_ALLOC_MEM(array, size * sizeof(VappWidgetId *), parent);

    for (VfxS32 i = 0; i < size; i++)
    {
        VFX_ALLOC_NEW(array[i], VappWidgetId, parent);
    }

    return array;
}



void VappWidgetId::deleteArray(VappWidgetId **array, VfxS32 size)
{
    if (array)
    {
        for (VfxS32 i = 0; i < size; i++)
        {
            VFX_DELETE(array[i]);
        }

        VFX_FREE_MEM(array);
    }
}


void VappWidgetId::decodeFromArchive(VfxArchive *ar)
{
    //
    // Source and TypeKind
    //
    VfxU32 source = ar->readU8();
    VfxU32 typeKind = ar->readU8();

    //
    // Type
    //
    switch (typeKind)
    {
        case TYPE_KIND_INTEGER:
        {
            VfxU32 type = ar->readU32();
            assignWith((VappWidgetSrcEnum)source, (VfxS32)type);
            break;
        }
        case TYPE_KIND_STRING:
        {
            VfxU32 length = ar->readU32();

            VfxChar *string;

            VFX_SYS_ALLOC_MEM(string, sizeof(VfxChar) * (length + 1));
            if (length > 0)
            {
                ar->read((VfxU8 *)string, sizeof(VfxChar) * length);
            }

            string[length] = '\0';

            assignWith((VappWidgetSrcEnum)source, string);

            VFX_SYS_FREE_MEM(string);

            break;
        }
        default:
        {
            VFX_ASSERT(0); // Archive file might be corrupted.
            break;
        }
    }
}


void VappWidgetId::encodeToArchive(VfxArchive *ar) const
{
    //
    // Source and TypeKind
    //
    ar->writeU8((VfxU8)m_source);
    ar->writeU8((VfxU8)m_typeKind);

    //
    // Type
    //
    switch (m_typeKind)
    {
        case TYPE_KIND_INTEGER:
        {
            ar->writeU32(m_type.ival);
            break;
        }
        case TYPE_KIND_STRING:
        {
            VfxU32 length = strlen(m_type.sval);

            ar->writeU32(length);

            if (length > 0)
            {
                ar->write((VfxU8 *)m_type.sval, sizeof(VfxChar) * length);
            }
            break;
        }
        default:
        {
            VFX_ASSERT(0);  // ID is invalid.
            break;
        }
    }
}


void VappWidgetId::clear()
{
    m_typeKind = TYPE_KIND_UNKNOWN;
}


void VappWidgetId::assignTypeString(const VfxChar *typeString)
{
    if (typeString)
    {
        strncpy(m_type.sval, typeString, MMI_APP_NAME_MAX_LEN - 1);
        m_type.sval[MMI_APP_NAME_MAX_LEN - 1] = '\0';
    }
}


VfxS32 VappWidgetId::decodeFromMem(VfxU8 *buf, VfxU32 size)
{
    VfxS32 idSize = 0;
    VfxU8 *ptrBuf = buf;
    //
    // Source and TypeKind
    //
    VfxU32 source = *((VfxU32*)ptrBuf); 
    ptrBuf+=4; 
    idSize+=4;

    VfxU32 typeKind = *((VfxU32*)ptrBuf);
    ptrBuf+=4; 
    idSize+=4;

    //
    // Type
    //
    switch (typeKind)
    {
        case TYPE_KIND_INTEGER:
        {
            VfxU32 type = *((VfxU32*)ptrBuf);
            assignWith((VappWidgetSrcEnum)source, (VfxS32)type);
            idSize+=4;
            break;
        }
        case TYPE_KIND_STRING:
        {
            VfxU32 length = *((VfxU32*)ptrBuf);
            ptrBuf+=4; 
            idSize+=4;
            
            VfxChar *string;

            VFX_SYS_ALLOC_MEM(string, sizeof(VfxChar) * (length + 1));
            if (length > 0)
            {
                strncpy(string, (const VfxChar *)ptrBuf, sizeof(VfxChar) * length);
                idSize+=sizeof(VfxChar) * length;
            }

            string[length] = '\0';
            assignWith((VappWidgetSrcEnum)source, string);

            VFX_SYS_FREE_MEM(string);

            break;
        }
        default:
        {
            VFX_ASSERT(0); // Archive file might be corrupted.
            break;
        }
    }

    return idSize;
}


VfxS32 VappWidgetId::encodeToMem(VfxU8 *buf, VfxU32 size)
{
    VfxS32 idSize = 0;
    VfxU8 *ptrBuf = buf;

    if (buf)
    {
        *((VfxU32*)ptrBuf) = m_source;
        ptrBuf += 4;

        *((VfxU32*)ptrBuf) = m_typeKind;
        ptrBuf += 4;

        //
        // Type
        //
        switch (m_typeKind)
        {
            case TYPE_KIND_INTEGER:
            {
                *((VfxU32*)ptrBuf) = m_type.ival;
                ptrBuf += 4;
                break;
            }
            case TYPE_KIND_STRING:
            {
                VfxU32 length = strlen(m_type.sval);

                *((VfxU32*)ptrBuf) = length;
                ptrBuf += 4;

                if (length > 0)
                {
                    strncpy((VfxChar*)ptrBuf, (const VfxChar *)m_type.sval, sizeof(VfxChar) * length);
                    ptrBuf += sizeof(VfxChar) * length;
                }
                break;
            }
            default:
            {
                VFX_ASSERT(0);  // ID is invalid.
                break;
            }        
        }
    }
    
    idSize+=4; // m_source
    idSize+=4; // m_typeKind
    //
    // Type
    //
    switch (m_typeKind)
    {
        case TYPE_KIND_INTEGER:
        {
            idSize+=4;
            break;
        }
        case TYPE_KIND_STRING:
        {
            VfxU32 length = strlen(m_type.sval);
            idSize+=4;
            if (length > 0)
            {
                idSize+=sizeof(VfxChar) * length;
            }
            break;
        }
        default:
        {
            VFX_ASSERT(0);  // ID is invalid.
            break;
        }        
    }
    return idSize;
}


/*****************************************************************************
 * Widget ID Object (for Venus Plug-in Only)
 *****************************************************************************/

VappWidgetIdObject::VappWidgetIdObject() :
    m_id(NULL)
{
    // Do nothing
}


void VappWidgetIdObject::onInit()
{
    VfxObject::onInit();

    VFX_ALLOC_NEW(m_id, VappWidgetId, this);
}


void VappWidgetIdObject::onDeinit()
{
    VFX_DELETE(m_id);

    VfxObject::onDeinit();
}


/*****************************************************************************
 * Pre-installed Widget
 *****************************************************************************/

VappWidgetPreInstalled &VappWidgetPreInstalled::operator =(
    const VappWidgetPreInstalled &other)
{
    m_id = other.m_id;
    m_pageIdx = other.m_pageIdx;
    m_pos = other.m_pos;

    return *this;
}


VfxBool VappWidgetPreInstalled::operator ==(const VappWidgetPreInstalled &other)
{
    if (m_id == other.m_id &&
        m_pageIdx == other.m_pageIdx &&
        m_pos == other.m_pos)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


VfxBool VappWidgetPreInstalled::operator !=(const VappWidgetPreInstalled &other)
{
    if (m_id != other.m_id ||
        m_pageIdx != other.m_pageIdx ||
        m_pos != other.m_pos)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


/*****************************************************************************
 * Sticky Button
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappWidgetStickyButton", VappWidgetStickyButton, VfxControl);


VappWidgetStickyButton::VappWidgetStickyButton() :
    m_id(0),
    m_imgId(0),
    m_button(NULL),
    m_watchFrame(),
    m_offset()
{
}


void VappWidgetStickyButton::onInit()
{
    VfxControl::onInit();

    //
    // Button
    //
    VFX_OBJ_CREATE(m_button, VcpImageButton, this);
    m_button->m_signalClicked.connect(this, &VappWidgetStickyButton::onButtonClicked);

    //
    // This frame
    //
    setAnchor(0.5f, 0.5f);
}


void VappWidgetStickyButton::onDeinit()
{
    VfxControl::onDeinit();
}


void VappWidgetStickyButton::setPos(const VfxPoint &value)
{
    // Do nothing.
    //
    // Sticky button's position is set by the frame it is sticky to using
    // another API "setStickyPos". To avoid from the complication, override
    // 'setPos' to do nothing.
}


void VappWidgetStickyButton::setStickyPos(const VfxPoint &watchFramePos)
{
    //
    // Sticky button should be sticky to the 'watch frame'.
    //
    if (m_watchFrame.isValid())
    {
        VfxSize watchSize = m_watchFrame->getSize();
        VfxFPoint watchAnchor = m_watchFrame->getAnchor();

        watchAnchor.x *= watchSize.width;
        watchAnchor.y *= watchSize.height;

        VfxFloat dx = m_offset.x - watchAnchor.x;
        VfxFloat dy = m_offset.y - watchAnchor.y;

        VfxPoint pos;

        pos.x = (VfxS32)(watchFramePos.x + dx + 0.5f);
        pos.y = (VfxS32)(watchFramePos.y + dy + 0.5f);

        VfxControl::setPos(pos);
    }
}


void VappWidgetStickyButton::setImgId(VfxResId imgId)
{
    VfxImageSrc imgSrc(imgId);

    // Button:
    m_button->setImage(VcpStateImage(imgId));
    m_button->setIsEffect(VFX_TRUE);
    m_button->setEffectSize(VfxSize(HALO_WIDTH, HALO_HEIGHT));
    m_button->setEffectOffset(VfxPoint(HALO_OFFSET_X, HALO_OFFSET_Y));
    m_button->setSize(imgSrc.getSize());

    // This frame:
    setSize(imgSrc.getSize());
}


void VappWidgetStickyButton::setStickyTo(
    VfxFrame *frame,
    const VfxPoint &offset)
{
    //
    // Save the parameters.
    //
    m_watchFrame = frame;
    m_offset = offset;

    //
    // Set the FPE callback.
    //
    vrt_point_struct point;

    point.x = offset.x;
    point.y = offset.y;

    setPropertyEffectCallback(
        frame,
        onTargetFpeChanged,
        &point,
        sizeof(vrt_point_struct),
        VRT_FPE_TRIGGER_TYPE_DIRTY);
}


void VappWidgetStickyButton::onButtonClicked(VfxObject *obj, VfxId id)
{
    m_signalClicked.emit(this);
}


vrt_render_dirty_type_enum VappWidgetStickyButton::onTargetFpeChanged(
    vrt_frame_visual_property_struct *targetFrame,
    const vrt_frame_visual_property_struct *watchFrame,
    void *userData,
    vrt_u32 userDataSize)
{
    //
    // Copy the properties from the 'watch frame'.
    //
    targetFrame->pos = watchFrame->pos;
    targetFrame->transform = watchFrame->transform;
    targetFrame->opacity = watchFrame->opacity;

    //
    // Calculate the offset (dx, dy) of the sticky button.
    //
    VFX_ASSERT(userData);

    vrt_point_struct offset = *(vrt_point_struct *)userData;
    vrt_size_struct size = watchFrame->bounds.size;
    vrt_fpoint_struct anchor = watchFrame->anchor_point;

    anchor.x *= size.width;
    anchor.y *= size.height;

    vrt_float dx = offset.x - anchor.x;
    vrt_float dy = offset.y - anchor.y;

    dx *= watchFrame->transform.data.affine.sx;
    dy *= watchFrame->transform.data.affine.sy;

    targetFrame->pos.x += (vrt_s32)(dx + 0.5f);
    targetFrame->pos.y += (vrt_s32)(dy + 0.5f);

    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}

#endif /* defined(__MMI_VUI_WIDGET_FACTORY__) */
