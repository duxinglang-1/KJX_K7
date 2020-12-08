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
 *  vfx_object_3d.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_OBJECT_3D_H__
#define __VFX_OBJECT_3D_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_animatable.h"
#include "vrt_interface.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_OBJECT3D_BEGIN_FLAG         (1 << 0)
#define VFX_OBJECT3D_PROPERTY_DIRTY     (VFX_OBJECT3D_BEGIN_FLAG << 0)
#define VFX_OBJECT3D_TIMELINE_DIRTY     (VFX_OBJECT3D_BEGIN_FLAG << 1)
#define VFX_OBJECT3D_END_FLAG           (VFX_OBJECT3D_TIMELINE_DIRTY)
#define VFX_OBJECT3D_ALL_DIRTY          (VFX_OBJECT3D_PROPERTY_DIRTY | VFX_OBJECT3D_TIMELINE_DIRTY)


/***************************************************************************** 
 * Class VfxObject3D
 *****************************************************************************/

/*
 * VfxObject3D is the base class of all Venus 3D UI objects.
 */
class VfxObject3D : public VfxAnimatable, public IVrtSyncObject
{
    VFX_DECLARE_CLASS(VfxObject3D);

// Constructor / Destructor
public:
    // Default constructor
    VfxObject3D();

// Method
public:
    // Set property dirty flag.
    void setPropertyDirty(VfxU32 flag) const;

    // Clear property dirty flag.
    void clearPropertyDirty(VfxU32 flag) const;

    // Whether property flag is dirty.
    VfxBool isPropertyDirty(VfxU32 flag) const;

    // Internal used. Get or create vrt handle. This method can only be used in syncData().
    vrt_object_handle getSyncHandle() const;

// Override
public:
    // VfxAnimatable
    virtual void processCreateHandle();
    virtual void processReleaseHandle();
    // IVrtSyncObject
    virtual void syncData() const;
    virtual void destroy() const;

// Override
protected:
    // VfxObject
    virtual void onDeinit();
    virtual void onObjectNotify(VfxId eventId, void *userData);
    // VfxAnimatable
    virtual void resetProperty(vrt_object_property_id_enum propertyId);
    void onAddTimeline();

// Overridable
public:
    // Create VRT object 3D handle.
    virtual void createHandle() const = 0;

    // Dispose VRT object 3D handle.
    virtual void disposeHandle() const;

// Variable
protected:
    mutable VfxU32 m_dirtyFlag;
};


inline void VfxObject3D::setPropertyDirty(VfxU32 flag) const
{
    VFX_FLAG_SET(m_dirtyFlag, flag | VFX_OBJECT3D_PROPERTY_DIRTY);
    vrt_frame_set_need_commit();
}

inline void VfxObject3D::clearPropertyDirty(VfxU32 flag) const
{
    VFX_FLAG_CLEAR(m_dirtyFlag, flag);
}


inline VfxBool VfxObject3D::isPropertyDirty(VfxU32 flag) const
{
    return VFX_FLAG_HAS(m_dirtyFlag, flag);
}

#endif /* __VFX_OBJECT_3D_H__ */

