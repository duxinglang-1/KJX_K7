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
 *  vapp_hs_widget_pet.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: pet
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
#ifndef __VAPP_HS_WIDGET_PET_H__
#define __VAPP_HS_WIDGET_PET_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_PET__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_hs_widget_base.h"

#include "vfx_cpp_base.h"
#include "vapp_hs_widget_cfg.h"
#include "vapp_hs_def.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_datatype.h"
#include "mmi_rp_app_venus_homescreen_wg_pet_def.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"
#include "vfx_timer.h"
#include "vfx_animation.h"
#include "vfx_transform.h"
#include "vfx_primitive_frame.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
class VappHsWidgetPet;


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef void (VappHsWidgetPet::*ActionFuncPtr) ();


/***************************************************************************** 
 * Home screen widget: analog clock
 *****************************************************************************/
class VappHsWidgetPet : public VappHsWidget
{
    VAPP_HS_WIDGET_CREATE(VappHsWidgetPet);

// Declaration
private:
    enum LifeStateEnum
    {
        STATE_INACTIVE,     // inactive
        STATE_DRAG,         // drag
        STATE_DROP,         // drop
        STATE_CONFUSED,     // confused
        STATE_IDLE,         // idle
        STATE_WALKING,      // walking
        STATE_RUNNING,      // running
        STATE_EATING,       // eating
        STATE_SLEEPING,     // sleeping
        STATE_WATCHING,     // watching user pen input or butterfly
        STATE_SHAKING       // shaking
    };

    enum
    {
        CONFUSED_TIME = 1500,   // confused time
        MAX_DROP_TIME = 500,    // maximum drop time from top to bottom
        WALKING_TIME = 250,     // walking time for each step
        RUNNING_TIME = 150,     // running time for each step
        EATING_TIME = 250,      // eating time for each step
        SLEEPING_TIME = 500,    // sleeping time for each step
        SHAKING_TIME = 250,     // shaking time for each step
        IDLE_TIME = 250,        // idle time for each step
        SCENARIO_TIME = 2000,   // time for next scenario
        FLY_TIME = 250,         // butterfly time
        LINE_GAP = 0            // stand line gap under desktop valid region
    };

// Constructor / Destructor
public:
    // Default constructor
    VappHsWidgetPet();

// Override
public:
    // get the image ID of widget bar icon
    // RETURNS: image ID
    virtual VfxU16 getIcon() { return VAPP_HS_IMG_WG_ICON_PET; }

    // get the name of the widget
    // RETURNS: string ID
    virtual VfxU16 getName() { return VAPP_HS_STR_WG_PET; }

    // create the whole widget content
    virtual void onCreateView();

    // release the whole widget content
    virtual void onReleaseView();

    // Widget is added to desktop (after createView and is sure to put on desktop)
    virtual void onAddToDesktop();

    // Widget is removed from desktop (not yet releaseView while dragging)
    virtual void onRemoveFromDesktop();

// Method
public:
    void startMotion();

// Slot
protected:
    // backlight switch handler
    void onBacklightSwitch(
        VfxBool on          // [IN] backlight on or off
    );

private:
    // On bounds value change
    void onBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds);

    // start drag
    void startDrag();

    // start drop
    void startDrop();

    // start confused
    void startConfused();

    // start idle
    void startIdle();

    // start walking
    void startWalking();

    // start running
    void startRunning();

    // start eating
    void startEating();

    // start sleeping
    void startSleeping();

    // start shaking
    void startShaking();

    // idle handler
    // RETURNS: void
    void idleHandler(
        VfxTimer *timer             // [IN] timer
    );

    // action handler
    // RETURNS: void
    void actionHandler(
        VfxTimer *timer             // [IN] timer
    );

    // fly handler
    // RETURNS: void
    void flyHandler(
        VfxTimer *timer             // [IN] timer
    );

    // callback when timeline is stopped
    // RETURNS: void
    void onTimelineStop(
        VfxBaseTimeline *timeline,  // [IN] time line
        VfxBool isCompleted         // [IN] normal stop
    );

// Variables
private:
    // life state
    LifeStateEnum   m_lifeState;

    // left / right mirror transform matrix
    VfxTransform    m_transformLR;

    // background image
    VfxImageFrame   *m_imageBg;

    // body image
    VfxImageFrame   *m_imageBody;

    // foreground image
    VfxImageFrame   *m_imageFg;

    // background butterfly image
    VfxImageFrame   *m_imageFly;

    // drop timeline
    VfxS32Timeline  *m_timelineDrop;

    // idle timer
    VfxTimer        *m_timerIdle;

    // action timer
    VfxTimer        *m_timerAction;

    // action timer
    VfxTimer        *m_timerFly;

    // next action
    ActionFuncPtr   m_action;

    // walking steps
    VfxS32          m_steps;

    // pixel per step
    VfxS32          m_pps;

    // confuse time
    VfxS32          m_confuseTime;
};

#endif /* __MMI_VUI_HOMESCREEN_PET__ */
#endif /* __VAPP_HS_WIDGET_PET_H__ */

