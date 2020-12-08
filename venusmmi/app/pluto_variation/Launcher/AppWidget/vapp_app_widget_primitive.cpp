/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vapp_app_widget_primitive.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include <string.h>

#include "vfx_uc_include.h"
#include "vapp_app_widget_def.h"
#include "vapp_app_widget_primitive.h"


/*****************************************************************************
 * Widget Id Class
 *****************************************************************************/

VappAppWidgetId::VappAppWidgetId() :
    m_source(VAPP_APP_WIDGET_SRC_INVALID),
    m_typeKind(TYPE_KIND_UNKNOWN)
{
    // Do nothing.
}


VappAppWidgetId::VappAppWidgetId(VappAppWidgetSrcEnum source, VfxS32 type) :
    m_source(VAPP_APP_WIDGET_SRC_INVALID),
    m_typeKind(TYPE_KIND_UNKNOWN)
{
    assignWith(source, type);
}


VappAppWidgetId::VappAppWidgetId(VappAppWidgetSrcEnum source, const VfxChar *typeString) :
    m_source(VAPP_APP_WIDGET_SRC_INVALID),
    m_typeKind(TYPE_KIND_UNKNOWN)
{
    assignWith(source, typeString);
}


VappAppWidgetId::VappAppWidgetId(const VappAppWidgetId &other) :
    m_source(VAPP_APP_WIDGET_SRC_INVALID),
    m_typeKind(TYPE_KIND_UNKNOWN)
{
    assignWith(other);
}


VappAppWidgetId::~VappAppWidgetId()
{
    clear();
}


VappAppWidgetId &VappAppWidgetId::operator =(const VappAppWidgetId &other)
{
    assignWith(other);

    return *this;
}


VfxBool VappAppWidgetId::operator ==(const VappAppWidgetId &other) const
{
    return compareWith(other);
}


VfxBool VappAppWidgetId::operator !=(const VappAppWidgetId &other) const
{
    return compareWith(other) ? VFX_FALSE : VFX_TRUE;
}


void VappAppWidgetId::assignWith(const VappAppWidgetId &other)
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


void VappAppWidgetId::assignWith(VappAppWidgetSrcEnum source, VfxS32 type)
{
    clear();

    m_source = source;
    m_typeKind = TYPE_KIND_INTEGER;
    m_type.ival = type;
}


void VappAppWidgetId::assignWith(
    VappAppWidgetSrcEnum source,
    const VfxChar *typeString)
{
    clear();

    m_source = source;
    m_typeKind = TYPE_KIND_STRING;
    assignTypeString(typeString);
}


VfxBool VappAppWidgetId::compareWith(const VappAppWidgetId &other) const
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


VappAppWidgetSrcEnum VappAppWidgetId::getSource() const
{
    return m_source;
}


VappAppWidgetId::TypeKindEnum VappAppWidgetId::getTypeKind() const
{
    return m_typeKind;
}


VfxS32 VappAppWidgetId::getIntType() const
{
    VFX_ASSERT(m_typeKind == TYPE_KIND_INTEGER);

    return m_type.ival;
}


const VfxChar *VappAppWidgetId::getStringType() const
{
    VFX_ASSERT(m_typeKind == TYPE_KIND_STRING);

    return m_type.sval;
}


VappAppWidgetId **VappAppWidgetId::newArray(VfxS32 size, VfxObject *parent)
{
    VappAppWidgetId **array;

    VFX_ALLOC_MEM(array, size * sizeof(VappAppWidgetId *), parent);

    for (VfxS32 i = 0; i < size; i++)
    {
        VFX_ALLOC_NEW(array[i], VappAppWidgetId, parent);
    }

    return array;
}



void VappAppWidgetId::deleteArray(VappAppWidgetId **array, VfxS32 size)
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


void VappAppWidgetId::clear()
{
    m_typeKind = TYPE_KIND_UNKNOWN;
}


void VappAppWidgetId::assignTypeString(const VfxChar *typeString)
{
    if (typeString)
    {
        VfxS32 len = strlen(typeString);
        if(len > MMI_APP_NAME_MAX_LEN-1)
        {
            len = MMI_APP_NAME_MAX_LEN-1;
        }
        strncpy(m_type.sval, typeString, len);
        m_type.sval[len] = '\0';
    }
}


/*****************************************************************************
 * Pre-installed Widget
 *****************************************************************************/

VappAppWidgetPreInstalled &VappAppWidgetPreInstalled::operator =(
    const VappAppWidgetPreInstalled &other)
{
    m_id = other.m_id;
    m_pageIdx = other.m_pageIdx;
    m_pos = other.m_pos;

    return *this;
}


VfxBool VappAppWidgetPreInstalled::operator ==(const VappAppWidgetPreInstalled &other)
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


VfxBool VappAppWidgetPreInstalled::operator !=(const VappAppWidgetPreInstalled &other)
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

VFX_IMPLEMENT_CLASS("VappAppWidgetStickyButton", VappAppWidgetStickyButton, VfxControl);


VappAppWidgetStickyButton::VappAppWidgetStickyButton() :
    m_id(0),
    m_imgId(0),
    m_button(NULL),
    m_watchFrame(),
    m_offset()
{
}


void VappAppWidgetStickyButton::onInit()
{
    VfxControl::onInit();

    //
    // Button
    //
    VFX_OBJ_CREATE(m_button, VcpImageButton, this);
    m_button->m_signalClicked.connect(this, &VappAppWidgetStickyButton::onButtonClicked);

    //
    // This frame
    //
    setAnchor(0.5f, 0.5f);
}


void VappAppWidgetStickyButton::onDeinit()
{
    VfxControl::onDeinit();
}


void VappAppWidgetStickyButton::setPos(const VfxPoint &value)
{
    // Do nothing.
    //
    // Sticky button's position is set by the frame it is sticky to using
    // another API "setStickyPos". To avoid from the complication, override
    // 'setPos' to do nothing.
}


void VappAppWidgetStickyButton::setStickyPos(const VfxPoint &watchFramePos)
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


void VappAppWidgetStickyButton::setImgId(VfxResId imgId)
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


void VappAppWidgetStickyButton::setStickyTo(
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


void VappAppWidgetStickyButton::onButtonClicked(VfxObject *obj, VfxId id)
{
    m_signalClicked.emit(this);
}


vrt_render_dirty_type_enum VappAppWidgetStickyButton::onTargetFpeChanged(
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

#endif /* defined(__MMI_VUI_LAUNCHER__) */

