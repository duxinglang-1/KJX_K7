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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vfx_animatable.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Description
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VFX_ANIMATABLE_H__
#define __VFX_ANIMATABLE_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxObject
#include "vfx_object.h"
// For List
#include "vfx_container.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

 
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 
// Predefine Classes
class VfxBaseTimeline;


/***************************************************************************** 
 * Class VfxAnimatableCustomVar
 *****************************************************************************/

class VfxAnimatableCustomVar : public VfxBase
{
// Constructor / Destructor
public:
    // Default constructor
    VfxAnimatableCustomVar(vrt_type_id_enum typeId, vrt_allocator_handle allocator);

    // Destructor
    ~VfxAnimatableCustomVar();

// Method
public:
    void *getDataBuffer() const
    {
        return m_data;
    }
    
// Implementaion
private:
    vrt_type_id_enum m_typeId;
    void *m_data;
};


/***************************************************************************** 
 * Class VfxAnimatable
 *****************************************************************************/

/*
 * VfxAnimatable is the base unit of scene graph.
 */
class VfxAnimatable : public VfxObject
{
    VFX_DECLARE_CLASS(VfxAnimatable);

// Constructor / Destructor
public:
    // Default constructor
    VfxAnimatable();

// Method
public:
    // Enable auto animation or not.
    void setAutoAnimate(VfxBool value);

    // Whether auto animation is enabled
    // NOTE: The default value is VFX_FALSE.
    VfxBool getAutoAnimate() const;

// Framework method
public:
    // Internal used. Enable a timeline
    void addTimeline(VfxBaseTimeline *timeline);

    // Internal used. Disable a timeline
    void removeTimeline(VfxBaseTimeline *timeline);

    // Internal used. Disable all timeline of the frame
    void removeAllTimeline();

    // Internal used.
    void removeAllApplyingTimeline(vrt_object_property_id_enum targetPropertyId);

    // Internal used. Prepare all timeline of the frame
    void prepareAllTimeline() const;

    // Internal used. Dispose all timeline of the frame
    void disposeAllTimeline() const;

    // Internal used. Create a custom variable.
    VfxAnimatableCustomVar *addCustomVariable(vrt_type_id_enum typeId, vrt_allocator_handle allocator);

    // Internal used. Remove a custom variable.
    void removeCustomVariable(VfxAnimatableCustomVar *var);

    // Internal used. Remove all custom variable.
    void removeAllCustomVariable();

    // Return the VRT object handle.
    //
    // RETURNS: The VRT object handle.
    vrt_object_handle getHandle() const;

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

// Overridable
public:
    // Internal used. For VfxBaseTimeline to enable VRT object timeline.
    virtual void processCreateHandle();
    virtual void processReleaseHandle();

// Overridable
protected:
    // Internal used. For timeline to reset property in onDeinit.
    virtual void resetProperty(vrt_object_property_id_enum propertyId) = 0;

    virtual void onAddTimeline();
    virtual void onRemoveTimeline();

// Implementation
protected:
    friend class VfxRenderer;
    friend class VfxBaseTimeline;
    friend class VfxAutoAnimate;
    
    // Internal used. Prepare all animation timeline.
    void prepareAnimationHandle() const;

    // Internal used. Dispose all animation timeline and varible.
    void disposeAnimationHandle() const;

    // object handle. Internal used.
    mutable vrt_object_handle m_handle;

    // Enabled timeline list on the frame
    VfxBaseTimeline *m_enabledTimelineListHead;
    VfxBaseTimeline *m_enabledTimelineListTail;

    // Custom variable list
    VfxList <VfxAnimatableCustomVar *> m_customVariableList;

protected:
    enum
    {
        // The frame has been initialized
        FLAGS_INITIALIZED       = 1 << 0,
        // Enable auto-animation
        FLAGS_AUTO_ANIMATE      = 1 << 1,
    };
    VfxFlag m_animatableFlags;        // Flags to save status.

    // Return VFX_TRUE if the frame has never been committed
    VfxBool isInitializing() const
    {
        return !VFX_FLAG_HAS(m_animatableFlags, FLAGS_INITIALIZED);
    }

private:
    // Initial
    typedef struct 
    {
        VfxAnimatable *prev;
        VfxAnimatable *next;
    } frameLinkEntry;

    frameLinkEntry m_initframelink;

    const frameLinkEntry &getInitFrame(void) const;
    void setPrevInitFrame(VfxAnimatable *frame);
    void setNextInitFrame(VfxAnimatable *frame);
    void resetInitFrame(void);

private:
    // Initial
    static VfxAnimatable *s_initFrameListHead;
    static VfxAnimatable *s_initFrameListTail;
    static void finishInitialingFrameList();
};


inline vrt_object_handle VfxAnimatable::getHandle() const
{
    return m_handle;
}




#endif /* __VFX_ANIMATABLE_H__ */

