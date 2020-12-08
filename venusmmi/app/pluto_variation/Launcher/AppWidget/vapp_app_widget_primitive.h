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
 *  vapp_app_widget_primitive.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the widget's primitive class.
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

#ifndef VAPP_APP_WIDGET_PRIMITIVE_H
#define VAPP_APP_WIDGET_PRIMITIVE_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vapp_app_widget_def.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "MMIDataType.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * Widget ID Class
 *****************************************************************************/

class VappAppWidgetId : public VfxBase
{
// Enum
public:
    // Type kind. Each source of the widgets can choose its favorite type kind
    // to distinguish its widgets.
    enum TypeKindEnum
    {
        // Unknown type kind.
        TYPE_KIND_UNKNOWN,

        // Use integer to distinguish different widgets.
        TYPE_KIND_INTEGER,

        // Use string to distinguish different widgets.
        TYPE_KIND_STRING,

        // End of enum
        TYPE_KIND_END_OF_ENUM
    };

// Constructor / Destructor
public:
    // Default constructor
    VappAppWidgetId();

    // Construct a ID using the source and integer type.
    VappAppWidgetId(
        VappAppWidgetSrcEnum source,
        VfxS32 type
    );

    // Construct a ID using the source and string type.
    VappAppWidgetId(
        VappAppWidgetSrcEnum source,
        const VfxChar *type
    );

    // Copy constructor
    VappAppWidgetId(
        const VappAppWidgetId &other
    );

    // Default destructor
    ~VappAppWidgetId();

// Operator
public:
    // Assign operator
    VappAppWidgetId &operator =(
        const VappAppWidgetId &other
    );

    // Equal operator
    VfxBool operator ==(
        const VappAppWidgetId &other
    ) const;

    // Inequal operator
    VfxBool operator !=(
        const VappAppWidgetId &other
    ) const;

// Method
public:
    // This function assigns the widget ID from other widget ID.
    void assignWith(
        const VappAppWidgetId &other   // [IN] Other widget ID
    );

    // This fucntion assigns the widget ID using the integer type.
    void assignWith(
        VappAppWidgetSrcEnum source,   // [IN] Source
        VfxS32 type                 // [IN] Integer type
    );

    // This function assigns the widget ID using the string type.
    void assignWith(
        VappAppWidgetSrcEnum source,   // [IN] Source
        const VfxChar *type         // [IN] String type
    );

    // This function compares the widget ID with other widget ID.
    // RETURNS: On the same, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool compareWith(
        const VappAppWidgetId &other   // [IN] Other widget ID
    ) const;

    // This function gets the widget's source.
    // RETURNS: widget source.
    VappAppWidgetSrcEnum getSource() const;

    // This function gets the type kind used to distinguish different widgets
    // under this source.
    // RETURNS: type kind.
    TypeKindEnum getTypeKind() const;

    // This function gets the integer type. Note that it will assert if this
    // widget ID does not use integer type kind.
    // RETURNS: type using integer.
    VfxS32 getIntType() const;

    // This function gets the string type. Note that it will assert if this
    // widget ID does not use string type kind. Also note that this function
    // directly returns the type string stored in this widget ID, so please pay
    // attention when you manipulate this type string.
    // RETURNS: type using string.
    const VfxChar *getStringType() const;

public:
    // This function news a widget ID array with the specified size.
    // RETURNS: Widget ID array
    static VappAppWidgetId **newArray(
        VfxS32 size,            // [IN] Size of the array
        VfxObject *parent       // [IN] Object parent
    );

    // This function deletes a widget ID array.
    static void deleteArray(
        VappAppWidgetId **array,   // [IN] Widget ID array
        VfxS32 size             // [IN] Size of the array
    );

// Variable
private:
    // The source of the widget.
    VappAppWidgetSrcEnum m_source;

    // Kind of the type.
    TypeKindEnum m_typeKind;

    // The type of the widget. Use union for different type kinds.
    union
    {
        // Integer type kind.
        VfxS32 ival;

        // String type kind.
        VfxChar sval[MMI_APP_NAME_MAX_LEN];
    } m_type;

// Implementation
private:
    // This function clears the type value.
    void clear();

    // This function assign the type string.
    void assignTypeString(
        const VfxChar *typeString   // [IN] Type string
    );
};


/*****************************************************************************
 * Pre-installed Widget
 *****************************************************************************/

class VappAppWidgetPreInstalled : public VfxBase
{
// Constructor / Destructor
public:
    // Default constructor
    VappAppWidgetPreInstalled() :
        m_id(),
        m_pageIdx(0),
        m_pos(VFX_POINT_ZERO)
    {
        // Do nothing.
    }

    // Construct a pre-installed widget by specifying individual field.
    VappAppWidgetPreInstalled(const VappAppWidgetId &id, VfxS32 pageIdx, VfxPoint pos) :
        m_id(id),
        m_pageIdx(pageIdx),
        m_pos(pos)
    {
        // Do nothing.
    }

    // Copy constructor
    VappAppWidgetPreInstalled(const VappAppWidgetPreInstalled &other) :
        m_id(other.m_id),
        m_pageIdx(other.m_pageIdx),
        m_pos(other.m_pos)
    {
        // Do nothing.
    }

// Operator
public:
    VappAppWidgetPreInstalled &operator =(const VappAppWidgetPreInstalled &other);

    VfxBool operator ==(const VappAppWidgetPreInstalled &other);

    VfxBool operator !=(const VappAppWidgetPreInstalled &other);

// Variable
public:
    VappAppWidgetId m_id;

    VfxS32 m_pageIdx;

    VfxPoint m_pos;
};


/*****************************************************************************
 * Widget Delete Button
 *****************************************************************************/

class VappAppWidgetStickyButton : public VfxControl
{
    VFX_DECLARE_CLASS(VappAppWidgetStickyButton);

public:
    VappAppWidgetStickyButton();

public:
    VfxSignal1 <VappAppWidgetStickyButton *> m_signalClicked;

public:
    void setId(VfxId id)
    {
        m_id = id;
    }

    VfxId getId()
    {
        return m_id;
    }

    void setImgId(
        VfxResId imgId
    );

    void setStickyTo(
        VfxFrame *frame,
        const VfxPoint &offset
    );

public:
    virtual void setPos(
        const VfxPoint &value
    );

    void setStickyPos(
        const VfxPoint &watchFramePos
    );

protected:
    virtual void onInit();

    virtual void onDeinit();

private:
    enum
    {
        HALO_WIDTH = 59,
        HALO_HEIGHT = 59,
        HALO_OFFSET_X = 0,
        HALO_OFFSET_Y = -3
    };

private:
    VfxId m_id;
    VfxResId m_imgId;
    VcpImageButton *m_button;
    VfxWeakPtr <VfxFrame> m_watchFrame;
    VfxPoint m_offset;

private:
    void onButtonClicked(
        VfxObject *obj,
        VfxId id
    );

    static vrt_render_dirty_type_enum onTargetFpeChanged(
        vrt_frame_visual_property_struct *targetFrame,
        const vrt_frame_visual_property_struct *watchFrame,
        void *userData,
        vrt_u32 usesrDataSize
    );
};

#endif /* defined(__MMI_VUI_LAUNCHER__) */
#endif /* VAPP_APP_WIDGET_PRIMITIVE_H */

