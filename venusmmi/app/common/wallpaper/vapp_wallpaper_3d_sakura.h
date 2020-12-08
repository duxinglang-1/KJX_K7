/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *  vapp_wallpaper_frame_video.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen frame video wallpaper class header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_SAKURA__

#ifndef __VAPP_WALLPAPER_3D_SAKURA_H__
#define __VAPP_WALLPAPER_3D_SAKURA_H__

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vapp_wallpaper.h"

/* RHR start */
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vapp_wallpaper_cfg.h"
#include "vfx_sys_memory.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"
#include "vfx_input_event.h"
#include "vfx_primitive_frame.h"
#include "vfx_animation.h"
#include "vrt_datatype.h"
#include "vfx_image_src.h"
/* RHR end */

// 3D related
#include "vfx_asset_loader.h"
#include "vfx_world.h"
#include "vfx_camera.h"
#include "vfx_mesh.h"
#include "vfx_material.h"
#include "vfx_pass.h"
#include "vfx_shader_uniforms.h"
#include "vfx_shader.h"
#include "vfx_texture.h"
#include "vfx_light.h"


#ifdef __cplusplus
extern "C"
{
#endif

#include "SensorSrvGport.h"

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * Home screen UI componet: frame video wallpaper class
 *****************************************************************************/
class VappWallpaper3DSakura : public VappWallpaper
{
    VFX_DECLARE_CLASS(VappWallpaper3DSakura);

    VAPP_WALLPAPER_CREATE(VappWallpaper3DSakura);

// Constructor / Destructor
public:
    // Default constructor
    VappWallpaper3DSakura();

// Override
    // This function used to get image id of wallpaper thumbnail
    virtual MMI_IMG_ID getThumbnail();

protected:

    virtual void onCreateView();
    virtual void onReleaseView();
    virtual void onSerializeView();
    virtual void onRestoreView();

    virtual VfxBool onAllowSuspendOnSwipe();
    virtual VfxBool onAllowSuspendOnPenDown();

    // callback for suspend and resume wallpaper
    virtual void onSuspend();
    virtual void onResume();
    virtual void onDesktopBoundsChanged(
        const VfxU32 totalPage,
        VfxFrame *source,
        const VfxRect &oldBounds
    );

    void onEndOfButterflyTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted);

    static void onMotionSensorEvent(srv_sensor_type_enum type, void *sensor_data, void *user_data);

    //Override
    virtual VfxBool onPenInput(VfxPenEvent & event);

private:
    VfxFloat                 m_targetLoc;

    VfxFrame                *m_worldFrame;
    VfxWorld                *m_world;
    VfxGroup                *m_tree;
    VfxGroup                *m_butterfly;
    VfxGroup                *m_petals;
    VfxGroup                *m_petals2;

public:

    VfxFloatTimeline        *m_worldTimeline;
    VfxAnimation            *m_worldAnim ;
    VfxFloatTimeline        *m_worldCameraTimeline;
    VfxAnimation            *m_worldCameraAnim ;
    VfxFloatTimeline        *m_treetimeline;
    VfxAnimation            *m_treeAnim;
    VfxFloatTimeline        *m_butterflytimeline;
    VfxAnimation            *m_butterflyAnim;
    VfxFloatTimeline        *m_petalstimeline;
    VfxAnimation            *m_petalsAnim;
    VfxFloatTimeline        *m_petals2timeline;
    VfxAnimation            *m_petals2Anim;

    VfxVector3fTimeline     *m_gSensorTimeline;
    SRV_SENSOR_HANDLE        m_motionSensorHandle;
    VfxVector3f              m_petalsTargetPos;
};


#endif /* __VAPP_WALLPAPER_3D_SAKURA_H__ */
#endif /* __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_SAKURA__ */

