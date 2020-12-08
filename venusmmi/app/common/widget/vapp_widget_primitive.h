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
 *  vapp_widget_primitive.h
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

#ifndef VAPP_WIDGET_PRIMITIVE_H
#define VAPP_WIDGET_PRIMITIVE_H

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vapp_widget_def.h"

/* Pluto MMI headers: */
extern "C"
{
#include "MMIDataType.h"
}


/*****************************************************************************
 * Widget ID Class
 *****************************************************************************/

class VappWidgetId : public VfxBase
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
    VappWidgetId();

    // Construct a ID using the source and integer type.
    VappWidgetId(
        VappWidgetSrcEnum source,
        VfxS32 type
    );

    // Construct a ID using the source and string type.
    VappWidgetId(
        VappWidgetSrcEnum source,
        const VfxChar *type
    );

    // Copy constructor
    VappWidgetId(
        const VappWidgetId &other
    );

    // Default destructor
    ~VappWidgetId();

// Operator
public:
    // Assign operator
    VappWidgetId &operator =(
        const VappWidgetId &other
    );

    // Equal operator
    VfxBool operator ==(
        const VappWidgetId &other
    ) const;

    // Inequal operator
    VfxBool operator !=(
        const VappWidgetId &other
    ) const;

// Method
public:
    // This function assigns the widget ID from other widget ID.
    void assignWith(
        const VappWidgetId &other   // [IN] Other widget ID
    );

    // This fucntion assigns the widget ID using the integer type.
    void assignWith(
        VappWidgetSrcEnum source,   // [IN] Source
        VfxS32 type                 // [IN] Integer type
    );

    // This function assigns the widget ID using the string type.
    void assignWith(
        VappWidgetSrcEnum source,   // [IN] Source
        const VfxChar *type         // [IN] String type
    );

    // This function compares the widget ID with other widget ID.
    // RETURNS: On the same, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool compareWith(
        const VappWidgetId &other   // [IN] Other widget ID
    ) const;

    // This function gets the widget's source.
    // RETURNS: widget source.
    VappWidgetSrcEnum getSource() const;

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

// Method
public:
    // This function news a widget ID array with the specified size.
    // RETURNS: Widget ID array
    static VappWidgetId **newArray(
        VfxS32 size,            // [IN] Size of the array
        VfxObject *parent       // [IN] Object parent
    );

    // This function deletes a widget ID array.
    static void deleteArray(
        VappWidgetId **array,   // [IN] Widget ID array
        VfxS32 size             // [IN] Size of the array
    );

// Method
public:
    // This function decodes the widget ID from the archive.
    void decodeFromArchive(
        VfxArchive *ar      // [IN] Archive
    );

    // This function encodes the widget ID to the archive.
    void encodeToArchive(
        VfxArchive *ar      // [OUT] Archive
    ) const;

    // This function decodes the widget ID from the memory buffer.
    // RETURNS: the number of decoded bytes.
    VfxS32 decodeFromMem(
        VfxU8 *buf,         // [IN] Memory buffer
        VfxU32 size         // [IN] Size of the buffer
    );

    // This function encodes the widget ID to the memory buffer.
    // RETURNS: the number of encoded bytes.
    VfxS32 encodeToMem(
        VfxU8 *buf,         // [IN] Memory buffer
        VfxU32 size         // [IN] Size of the buffer
    );
    
// Variable
private:
    // The source of the widget.
    VappWidgetSrcEnum m_source;

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
 * Widget ID Object (for Venus Plug-in Only)
 *****************************************************************************/

class VappWidgetIdObject : public VfxObject
{
// Constructor / Destructor
public:
    // Default constructor
    VappWidgetIdObject();

// Override
public:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

// Variable
public:
    // The real widget ID.
    VappWidgetId *m_id;
};


/*****************************************************************************
 * Pre-installed Widget
 *****************************************************************************/

class VappWidgetPreInstalled : public VfxBase
{
// Constructor / Destructor
public:
    // Default constructor
    VappWidgetPreInstalled() :
        m_id(),
        m_pageIdx(0),
        m_pos(VFX_POINT_ZERO)
    {
        // Do nothing.
    }

    // Construct a pre-installed widget by specifying individual field.
    VappWidgetPreInstalled(const VappWidgetId &id, VfxS32 pageIdx, VfxPoint pos) :
        m_id(id),
        m_pageIdx(pageIdx),
        m_pos(pos)
    {
        // Do nothing.
    }

    // Copy constructor
    VappWidgetPreInstalled(const VappWidgetPreInstalled &other) :
        m_id(other.m_id),
        m_pageIdx(other.m_pageIdx),
        m_pos(other.m_pos)
    {
        // Do nothing.
    }

// Operator
public:
    VappWidgetPreInstalled &operator =(const VappWidgetPreInstalled &other);

    VfxBool operator ==(const VappWidgetPreInstalled &other);

    VfxBool operator !=(const VappWidgetPreInstalled &other);

// Variable
public:
    VappWidgetId m_id;

    VfxS32 m_pageIdx;

    VfxPoint m_pos;
};


/*****************************************************************************
 * Widget Delete Button
 *****************************************************************************/

class VappWidgetStickyButton : public VfxControl
{
    VFX_DECLARE_CLASS(VappWidgetStickyButton);

public:
    VappWidgetStickyButton();

public:
    VfxSignal1 <VappWidgetStickyButton *> m_signalClicked;

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
    #if defined(__MMI_MAINLCD_480X800__)
        HALO_WIDTH = 97,
        HALO_HEIGHT = 97,
        HALO_OFFSET_X = 0,
        HALO_OFFSET_Y = -3
    #elif defined(__MMI_MAINLCD_320X480__)
        HALO_WIDTH = 56,
        HALO_HEIGHT = 56,
        HALO_OFFSET_X = 0,
        HALO_OFFSET_Y = -2
    #elif defined(__MMI_MAINLCD_240X400__)
        HALO_WIDTH = 59,
        HALO_HEIGHT = 59,
        HALO_OFFSET_X = 0,
        HALO_OFFSET_Y = -3
    #else /* defined(__MMI_MAINLCD_240X320__) */
        HALO_WIDTH = 59,
        HALO_HEIGHT = 59,
        HALO_OFFSET_X = 0,
        HALO_OFFSET_Y = -3
    #endif /* defined(__MMI_MAINLCD_240X320__) */
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

#endif /* defined(__MMI_VUI_WIDGET_FACTORY__) */
#endif /* VAPP_WIDGET_PRIMITIVE_H */

