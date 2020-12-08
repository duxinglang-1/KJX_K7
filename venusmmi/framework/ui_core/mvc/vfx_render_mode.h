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
 *  vfx_render_mode.h
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_RENDER_MODE_H__
#define __VFX_RENDER_MODE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_object_3d.h"
#include "vfx_weak_ptr.h"
#include "vfx_3d_enum.h"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

class VfxCamera;


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_RENDER_MODE_BEGIN_FLAG                  (VFX_OBJECT3D_END_FLAG)
#define VFX_RENDER_MODE_CAMERA_DIRTY                (VFX_RENDER_MODE_BEGIN_FLAG << 1)
#define VFX_RENDER_MODE_SCOPE_DIRTY                 (VFX_RENDER_MODE_BEGIN_FLAG << 2)
#define VFX_RENDER_MODE_END_FLAG                    (VFX_RENDER_MODE_SCOPE_DIRTY)
#define VFX_RENDER_MODE_ALL_DIRTY                   (VFX_RENDER_MODE_CAMERA_DIRTY | \
                                                     VFX_RENDER_MODE_SCOPE_DIRTY)


/***************************************************************************** 
 * Class VfxRenderMode
 *****************************************************************************/

/*
 * VfxRenderMode is used to control 3D rendering.
 */
class VfxRenderMode : public VfxObject3D
{
// Constructor / Destructor
public:
    // Default constructor
    VfxRenderMode();

// Override
public:
    virtual void createHandle() const;

    virtual void disposeHandle() const;

    virtual void syncData() const;

// Property
public:
    // Set render camera.
    //
    // NOTE: Default value is NULL, i.e., uses the world active camera.
    void setRenderCamera(VfxCamera *camera);

    // Set render scope.
    //
    // NOTE: Default value is VFX_RENDER_SCOPE_DEFAULT.
    void setScope(VfxU32 scope);

    // Get render camera.
    //
    // NOTE: Default value is NULL, i.e., uses the world active camera.
    VfxCamera *getRenderCamera() const;

    // Get render scope.
    //
    // NOTE: Default value is VFX_RENDER_SCOPE_DEFAULT.
    VfxU32 getScope() const;

// Implementation
private:

    VfxWeakPtr<VfxCamera> m_renderCamera;
    VfxU32 m_scope;
};


inline VfxCamera *VfxRenderMode::getRenderCamera() const
{
    return m_renderCamera.get();
}

inline VfxU32 VfxRenderMode::getScope() const
{
    return m_scope;
}


#endif /* __VFX_RENDER_MODE_H__ */

