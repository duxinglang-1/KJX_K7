/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_hs_widget_pet.cpp
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

#ifdef __MMI_VUI_HOMESCREEN_PET__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_hs_widget_pet.h"
#include "stdlib.h"

#include "MMI_features.h"
#if defined(MOTION_SENSOR_SUPPORT)

#ifdef __cplusplus
extern "C"
{
#endif

#include "mdi_datatype.h"
#include "sensorSrvGport.h"

#ifdef __cplusplus
}
#endif

#endif /* MOTION_SENSOR_SUPPORT */

#include "kal_public_api.h"
#include "vfx_datatype.h"
#include "vfx_object.h"
#include "vrt_datatype.h"
#include "kal_general_types.h"
#include "vfx_transform.h"
#include "vfx_auto_animate.h"
#include "vfx_cpp_base.h"
#include "mmi_rp_app_venus_homescreen_wg_pet_def.h"
#include "vfx_basic_type.h"
#include "vfx_timer.h"
#include "vfx_pen.h"
#include "vfx_input_event.h"
#include "vrt_system.h"
#include "vfx_animation.h"
#include "vfx_signal.h"
#include "vfx_sys_memory.h"
#include "vfx_primitive_frame.h"
#include "vfx_frame.h"
#include "vfx_renderer.h"

/***************************************************************************** 
 * Home screen widget: Pet
 *****************************************************************************/

#if defined(MOTION_SENSOR_SUPPORT)
static mdi_handle g_vapp_hs_widget_pet_motion_handle = MDI_RES_MOTION_NO_SLOT;

static void vadp_p2v_hs_widget_pet_motion_cb (srv_sensor_type_enum sensor_type, void *sensor_data, 
	                void *user_data)
	//(mdi_motion_shake_enum action, void *user_data)
{
    VappHsWidgetPet *p = (VappHsWidgetPet *)user_data;

    VFX_OBJ_ASSERT_VALID(p);
    p->startMotion();
}
#endif /* MOTION_SENSOR_SUPPORT */


VappHsWidgetPet::VappHsWidgetPet() :
    m_lifeState(STATE_INACTIVE),
    m_imageBg(NULL),
    m_imageBody(NULL),
    m_imageFg(NULL),
    m_timerIdle(NULL),
    m_timerAction(NULL),
    m_action(NULL),
    m_steps(0),
    m_pps(0),
    m_confuseTime(0)
{
    m_transformLR.init(VRT_TRANSFORM_TYPE_AFFINE);
    m_transformLR.data.affine.sx = -1.0f;
}


void VappHsWidgetPet::startMotion()
{
    if (m_lifeState >= STATE_IDLE)
    {
        // stop timer
        m_timelineDrop->stop();
        m_timerIdle->stop();
        m_timerAction->stop();
    
        // reset property
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        setTransform(VFX_TRANSFORM_IDENTITY);
        m_imageBg->setOpacity(0.0f);
        m_imageFg->setOpacity(0.0f);
        VfxAutoAnimate::commit();
    
        startShaking();
    }
}


void VappHsWidgetPet::startDrag()
{
    // stop timer
    m_timelineDrop->stop();
    m_timerIdle->stop();
    m_timerAction->stop();

    // stop fly
    removeFromBottom(m_imageFly);
    m_timerFly->stop();

    // reset property
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    setTransform(VFX_TRANSFORM_IDENTITY);
    m_imageBg->setOpacity(0.0f);
    m_imageFg->setOpacity(0.0f);
    VfxAutoAnimate::commit();

    // set state
    m_lifeState = STATE_DRAG;

    // drag image
    m_imageBody->setResId(VAPP_HS_IMG_WG_PET_DRAG);
}


void VappHsWidgetPet::startDrop()
{
    // start fly    
    addToBottom(m_imageFly);
    m_timerFly->start();

    // set state
    m_lifeState = STATE_DROP;

    // decide drop position
    VfxRect rect = getCurrentValidRect();
    VfxPoint pos = getPos();

    // to get correct bounds, set idle image first
    m_imageBody->setResId(VAPP_HS_IMG_WG_PET_IDLE0);
    pos.y = rect.getMaxY() - getBounds().getMidY() + LINE_GAP;

    VfxS32 diff = VFX_ABS(pos.y - getPos().y) * 2;

    // if drop gap is smaller than the body height, stand up directly
    // otherwise, fall down and be confused first
    if (diff > getBounds().getHeight())
    {
        // falling image
        m_imageBody->setResId(VAPP_HS_IMG_WG_PET_FALL1);

        // falling time
        VfxS32 time = (diff * MAX_DROP_TIME) / (2 * rect.getHeight());

        // set confuse time
        m_confuseTime = (CONFUSED_TIME >> 2) + ((((CONFUSED_TIME * 3) >> 2) * diff) / (2 * rect.getHeight()));

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
        // TODO: tricky
        VfxPoint oldPos = getPos();
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        m_pos.x += 1;
        setPos(oldPos);
        VfxAutoAnimate::commit();

        m_timelineDrop->setDurationTime(time);
        m_timelineDrop->setToValue(pos.y);
        m_timelineDrop->start();

        // TODO: tricky
        m_pos = pos;
#endif
    }
    else
    {
        // move to the destination directly
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        setPos(pos);
        VfxAutoAnimate::commit();

        // enter idle directly
        startIdle();
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


void VappHsWidgetPet::startConfused()
{
    // set state
    m_lifeState = STATE_CONFUSED;

    // confused image
    m_imageBody->setResId(VAPP_HS_IMG_WG_PET_FALL2);

    // start next action
    m_timerAction->setStartDelay(m_confuseTime);
    m_timerAction->start();
    m_action = &VappHsWidgetPet::startIdle;
}


void VappHsWidgetPet::startIdle()
{
    if (m_lifeState != STATE_IDLE)
    {
        // set state
        m_lifeState = STATE_IDLE;
    
        // reset property
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        m_imageBg->setOpacity(0.0f);
        m_imageFg->setOpacity(0.0f);
        VfxAutoAnimate::commit();
    }

    // idle image
    if (m_imageBody->getResId() == VAPP_HS_IMG_WG_PET_IDLE1)
    {
        m_imageBody->setResId(VAPP_HS_IMG_WG_PET_IDLE0);
    }
    else
    {
        m_imageBody->setResId((rand() % 8 == 1) ? (VAPP_HS_IMG_WG_PET_IDLE1) : (VAPP_HS_IMG_WG_PET_IDLE0));
    }

    // start next action
    m_timerAction->setStartDelay(IDLE_TIME);
    m_timerAction->start();
    m_action = &VappHsWidgetPet::startIdle;

    // start next scenario
    if (!m_timerIdle->getIsEnabled())
    {
        m_timerIdle->start();
    }
}


void VappHsWidgetPet::startWalking()
{
    VfxRect rect = getCurrentValidRect();
    VfxPoint pos = getPos();

    if (m_lifeState != STATE_WALKING)
    {
        // set state
        m_lifeState = STATE_WALKING;
        m_pps = 4;

        // decide direction
        VfxBool is_right = (pos.x < rect.getMidX()) ? (VFX_TRUE) : (VFX_FALSE);
        VfxS32 diff = 0;

        // decide steps
        m_steps = ((rand() % 2) + 1) * 8 + (rand() % 5) * 2;

        if (is_right)
        {
            diff = (rect.getMaxX() - getBounds().getMidX()) - pos.x;
        }
        else
        {
            diff = pos.x - (rect.getMinX() + getBounds().getMidX());
        }
        diff = VFX_ABS(diff) / m_pps;
        m_steps = (m_steps < diff) ? (m_steps) : (diff);

        // mirror image if necessary
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        setTransform((is_right) ? (m_transformLR) : (VFX_TRANSFORM_IDENTITY));
        VfxAutoAnimate::commit();
    }
    else
    {
        m_steps --;
    }

    if (m_steps == 0)
    {
        // finish walking, enter idle
        startIdle();
    }
    else
    {
        // move
        pos.x += (getTransform() == m_transformLR) ? (m_pps) : (-m_pps);
        setPos(pos);

        // walking image
        m_imageBody->setResId((m_steps % 2) ? (VAPP_HS_IMG_WG_PET_WALK1) : (VAPP_HS_IMG_WG_PET_WALK2));

        // start next action
        m_timerAction->setStartDelay(WALKING_TIME);
        m_timerAction->start();
        m_action = &VappHsWidgetPet::startWalking;
    }
}


void VappHsWidgetPet::startRunning()
{
    VfxRect rect = getCurrentValidRect();
    VfxPoint pos = getPos();

    if (m_lifeState != STATE_RUNNING)
    {
        // set state
        m_lifeState = STATE_RUNNING;
        m_pps = 12;

        // decide direction
        VfxBool is_right = (pos.x < rect.getMidX()) ? (VFX_TRUE) : (VFX_FALSE);
        VfxS32 diff = 0;

        if (is_right)
        {
            diff = (rect.getMinX() + rect.getWidth() * 3 / 4) - pos.x;
        }
        else
        {
            diff = (rect.getMinX() + rect.getWidth() / 4) - pos.x;
        }
        m_steps = VFX_ABS(diff) / m_pps;
        // stop pose
        m_steps += 3;

        // mirror image if necessary
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        setTransform((is_right) ? (m_transformLR) : (VFX_TRANSFORM_IDENTITY));
        VfxAutoAnimate::commit();
    }
    else
    {
        m_steps --;
    }

    if (m_steps == 0)
    {
        // finish running, enter idle
        startIdle();
    }
    else
    {
        // move
        pos.x += (getTransform() == m_transformLR) ? (m_pps) : (-m_pps);
        setPos(pos);

#if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
        // running image
        if (m_steps > 8)
        {
            if (m_steps % 4 == 1)
            {
                m_imageBody->setResId(VAPP_HS_IMG_WG_PET_RUN1);
            }
            else if (m_steps % 2 == 0)
            {
                m_imageBody->setResId(VAPP_HS_IMG_WG_PET_RUN2);
            }
            else
            {
                m_imageBody->setResId(VAPP_HS_IMG_WG_PET_RUN3);
            }
        }
        else
        {
            m_imageBody->setResId(VAPP_HS_IMG_WG_PET_RUN_STOP);
            m_pps -= 2;
        }
#endif /* !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

        // start next action
        m_timerAction->setStartDelay(RUNNING_TIME);
        m_timerAction->start();
        m_action = &VappHsWidgetPet::startRunning;
    }
}


void VappHsWidgetPet::startEating()
{
    if (m_lifeState != STATE_EATING)
    {
        // set state
        m_lifeState = STATE_EATING;

        // set background image
        m_imageBg->setResId(VAPP_HS_IMG_WG_PET_EAT_BG);
        m_imageBg->setOpacity(1.0f);

        // set foreground image
        m_imageFg->setResId(VAPP_HS_IMG_WG_PET_EAT_GRASS);
        m_imageFg->setOpacity(1.0f);

        // decide steps
        m_steps = ((rand() % 3) + 2) * 24;
    }
    else
    {
        m_steps --;
    }

    if (m_steps == 0)
    {
        // finish eating, enter idle
        startIdle();
    }
    else
    {
        // eating image
        switch(m_imageBody->getResId())
        {
            case VAPP_HS_IMG_WG_PET_EAT3:
                if (m_steps % 4 != 0)
                {
                    m_imageBody->setResId(VAPP_HS_IMG_WG_PET_EAT2);
                }
                else
                {
                    m_imageBody->setResId((rand() % 8 == 1) ? (VAPP_HS_IMG_WG_PET_EAT1) : (VAPP_HS_IMG_WG_PET_EAT2));
                }    
                break;

            case VAPP_HS_IMG_WG_PET_EAT2:
                if (m_steps % 4 != 0)
                {
                    m_imageBody->setResId(VAPP_HS_IMG_WG_PET_EAT3);
                }
                else
                {
                    m_imageBody->setResId((rand() % 8 == 1) ? (VAPP_HS_IMG_WG_PET_EAT1) : (VAPP_HS_IMG_WG_PET_EAT3));
                }
                break;

            case VAPP_HS_IMG_WG_PET_EAT1:
            default:
                if (m_steps % 4 != 0)
                {
                    m_imageBody->setResId(VAPP_HS_IMG_WG_PET_EAT1);
                }
                else
                {
                    m_imageBody->setResId((rand() % 4 == 1) ? (VAPP_HS_IMG_WG_PET_EAT2) : (VAPP_HS_IMG_WG_PET_EAT1));
                }
                break;
        }

        // start next action
        m_timerAction->setStartDelay(EATING_TIME);
        m_timerAction->start();
        m_action = &VappHsWidgetPet::startEating;
    }
}


void VappHsWidgetPet::startSleeping()
{
    if (m_lifeState != STATE_SLEEPING)
    {
        // set state
        m_lifeState = STATE_SLEEPING;

        // set foreground image
        m_imageFg->setResId(VAPP_HS_IMG_WG_PET_SLEEP_FG);

        // decide steps
        m_steps = ((rand() % 3) + 2) * 24;
    }
    else
    {
        m_steps --;
    }

    if (m_steps == 0)
    {
        // finish sleeping, enter idle
        startIdle();
    }
    else
    {
        // sleeping image
        switch(m_imageBody->getResId())
        {
            case VAPP_HS_IMG_WG_PET_SLEEP1:
                m_imageBody->setResId(VAPP_HS_IMG_WG_PET_SLEEP2);
                break;

            case VAPP_HS_IMG_WG_PET_SLEEP2:
                m_imageBody->setResId(VAPP_HS_IMG_WG_PET_SLEEP3);
                break;

            case VAPP_HS_IMG_WG_PET_SLEEP3:
                if (m_steps % 4 != 0)
                {
                    m_imageBody->setResId(VAPP_HS_IMG_WG_PET_SLEEP3);
                }
                else
                {
                    m_imageBody->setResId((rand() % 6 == 1) ? (VAPP_HS_IMG_WG_PET_SLEEP0) : (VAPP_HS_IMG_WG_PET_SLEEP3));
                }
                break;

            case VAPP_HS_IMG_WG_PET_SLEEP0:
                if (m_steps % 2 != 0)
                {
                    m_imageBody->setResId(VAPP_HS_IMG_WG_PET_SLEEP0);
                }
                else
                {
                    m_imageBody->setResId((rand() % 2 == 1) ? (VAPP_HS_IMG_WG_PET_SLEEP3) : (VAPP_HS_IMG_WG_PET_SLEEP0));
                }
                break;

            default:
                m_imageBody->setResId(VAPP_HS_IMG_WG_PET_SLEEP1);
                break;
        }

        // before finishing sleeping, wakeup first
        if (m_steps == 1)
        {
            m_imageBody->setResId(VAPP_HS_IMG_WG_PET_SLEEP0);
        }

        // if wake-up for a while, no foreground
        if (m_imageBody->getResId() == VAPP_HS_IMG_WG_PET_SLEEP0)
        {
            m_imageFg->setOpacity(0.0f);
        }
        else
        {
            if (m_steps % 3 == 1)
            {
                m_imageFg->setOpacity((rand() % 2 == 1) ? (1.0f) : (0.0f));
            }
        }

        // start next action
        m_timerAction->setStartDelay(SLEEPING_TIME);
        m_timerAction->start();
        m_action = &VappHsWidgetPet::startSleeping;
    }
}


void VappHsWidgetPet::startShaking()
{
    if (m_lifeState != STATE_SHAKING)
    {
        // set state
        m_lifeState = STATE_SHAKING;

        // decide steps
        m_steps = 13;
    }
    else
    {
        m_steps --;
    }

    if (m_steps == 0)
    {
        // finish shaking, enter idle
        startIdle();
    }
    else
    {
        if (m_steps <= 4)
        {
            m_imageBody->setResId(VAPP_HS_IMG_WG_PET_FALL2);
        }
        else
        {
#if defined(MOTION_SENSOR_SUPPORT)
            if (m_imageBody->getResId() == VAPP_HS_IMG_WG_PET_SHAKE1)
            {
                m_imageBody->setResId(VAPP_HS_IMG_WG_PET_SHAKE2);
            }
            else
            {
                m_imageBody->setResId(VAPP_HS_IMG_WG_PET_SHAKE1);
            }
#endif /* defined(MOTION_SENSOR_SUPPORT) */
        }

        // start next action
        m_timerAction->setStartDelay(SHAKING_TIME);
        m_timerAction->start();
        m_action = &VappHsWidgetPet::startShaking;
    }
}


void VappHsWidgetPet::idleHandler(VfxTimer *timer)
{
    m_timelineDrop->stop();
    m_timerIdle->stop();
    m_timerAction->stop();

    VfxRect rect = getCurrentValidRect();
    VfxPoint pos = getPos();
    pos.y = rect.getMidY();

    VfxS32 ind = (VfxS32)rand();
    if (!rect.contains(pos))
    {
#if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
        startRunning();
#else /* !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */
        startWalking();
#endif /* !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */
    }
    else
    {
        VfxPen *pen = VFX_OBJ_GET_INSTANCE(VfxPen);

#if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
        if ((pen->getCurPenEventType() != VFX_PEN_EVENT_TYPE_UNKNOWN) ||
            (m_imageFly->getOpacity() == 1.0f))
        {
            m_lifeState = STATE_WATCHING;
        }
        else
#endif /* !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */
        {
            if (ind % 6 == 1)
            {
                startIdle();
            }
            else if (ind % 6 == 2)
            {
                startEating();
            }
            else if (ind % 6 == 3)
            {
                startSleeping();
            }
            else
            {
                startWalking();
            }
        }
    }
}


void VappHsWidgetPet::actionHandler(VfxTimer *timer)
{
    timer->stop();

    if (m_action != NULL)
    {
        (this->*m_action)();
    }
}


void VappHsWidgetPet::flyHandler(VfxTimer *timer)
{
    VfxPoint pos;
    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;

    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

    VfxS32 miny = main_screen_size.height / 5;
#if defined(__MMI_MAINLCD_320X240__)
    VfxS32 maxy = miny * 2;
#else /* defined(__MMI_MAINLCD_320X240__) */
    VfxS32 maxy = miny * 3;
#endif /* defined(__MMI_MAINLCD_320X240__) */

    if (m_imageFly->getOpacity() == 0.0f)
    {
        if (rand() % 64 == 1)
        {
            m_imageFly->setOpacity(1.0f);

            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);

#if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
            // init butterfly
            m_imageFly->setResId(VAPP_HS_IMG_WG_PET_TURN_FLY1);
            m_imageFly->setTransform((rand() % 2 == 1) ? (VFX_TRANSFORM_IDENTITY) : (m_transformLR));
#endif /* !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

            pos.x = (m_imageFly->getTransform() == m_transformLR) ? (0) : (main_screen_size.width - 1);
            pos.y = miny + rand() % (maxy - miny + 1);
            m_imageFly->setPos(pos);

            VfxAutoAnimate::commit();
        }
    }

    // update butterfly
    if (m_imageFly->getOpacity() == 1.0f)
    {
#if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
        // update butterfly image
        if (m_imageFly->getResId() == VAPP_HS_IMG_WG_PET_TURN_FLY1)
        {
            m_imageFly->setResId(VAPP_HS_IMG_WG_PET_TURN_FLY2);
        }
        else
        {
            m_imageFly->setResId(VAPP_HS_IMG_WG_PET_TURN_FLY1);
        }
#endif /* !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

        // update butterfly position
        pos = m_imageFly->getPos();
        pos.x += (m_imageFly->getTransform() == m_transformLR) ? (6 + (rand() % 3 - 1)) : (- 6 + (rand() % 3 - 1));
        pos.y += (rand() % 11 + 1) - 5;
        pos.y = (pos.y < miny) ? (miny) : (pos.y);
        pos.y = (pos.y > maxy) ? (maxy) : (pos.y);
        m_imageFly->setPos(pos);

        // butterfly is out of screen
        VfxRect rect(0, 0, main_screen_size.width, main_screen_size.height);
        if (!rect.contains(pos))
        {
            m_imageFly->setOpacity(0.0f);
        }
    }

    // watch pen or butterfly
    VfxPen *pen = VFX_OBJ_GET_INSTANCE(VfxPen);
    if (m_lifeState == STATE_WATCHING)
    {
    #if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
        VfxPoint pet_pos = convertPointTo(VfxPoint(getBounds().getMidX(), getBounds().getMidY()), m_imageFly->getParentFrame());
        VfxPoint target_pos = (pen->getCurPenEventType() != VFX_PEN_EVENT_TYPE_UNKNOWN) ? (pen->getCurPenPos()) : (m_imageFly->getPos());
		VfxS32 w = target_pos.x - pet_pos.x;
        VfxS32 h = target_pos.y - pet_pos.y;	
        VfxS32 aw = VFX_ABS(w);
        VfxS32 ah = VFX_ABS(h);
	#endif
        VfxBool isLR = (getTransform() == m_transformLR) ? (VFX_TRUE) : (VFX_FALSE);

        if ((pen->getCurPenEventType() != VFX_PEN_EVENT_TYPE_UNKNOWN) ||
            (m_imageFly->getOpacity() == 1.0f))
        {
		#if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
            if ((h < 0) && (ah >= (aw * 2)) &&
                ((!isLR && (w < 0)) || (isLR && (w > 0))))
            {
                m_imageBody->setResId(VAPP_HS_IMG_WG_PET_TURN1);
            }
            else if ((h > 0) && (ah >= (aw * 2)))
            {
                m_imageBody->setResId(VAPP_HS_IMG_WG_PET_TURN5);
            }
            else if ((w > 0) && (aw >= (ah * 2)))
            {
                m_imageBody->setResId((isLR) ? (VAPP_HS_IMG_WG_PET_TURN7) : (VAPP_HS_IMG_WG_PET_TURN3));
            }
            else if ((w < 0) && (aw >= (ah * 2)))
            {
                m_imageBody->setResId((isLR) ? (VAPP_HS_IMG_WG_PET_TURN3) : (VAPP_HS_IMG_WG_PET_TURN7));
            }
            else if ((w > 0) && (h < 0))
            {
                m_imageBody->setResId((isLR) ? (VAPP_HS_IMG_WG_PET_TURN8) : (VAPP_HS_IMG_WG_PET_TURN2));
            }
            else if ((w > 0) && (h > 0))
            {
                m_imageBody->setResId((isLR) ? (VAPP_HS_IMG_WG_PET_TURN6) : (VAPP_HS_IMG_WG_PET_TURN4));
            }
            else if ((w < 0) && (h > 0))
            {
                m_imageBody->setResId((isLR) ? (VAPP_HS_IMG_WG_PET_TURN4) : (VAPP_HS_IMG_WG_PET_TURN6));
            }
            else
            {
                m_imageBody->setResId((isLR) ? (VAPP_HS_IMG_WG_PET_TURN2) : (VAPP_HS_IMG_WG_PET_TURN8));
            }
		#endif /* !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */
        }
        else
        {
            startIdle();
        }
    }
}


void VappHsWidgetPet::onBacklightSwitch(VfxBool on)
{
#if defined(MOTION_SENSOR_SUPPORT)
    //modify for sensor split
	srv_sensor_motion_shake_cfg_struct shake_sensitive;
	shake_sensitive.sensitive = SRV_SENSOR_MOTION_SHAKE_WEAK;
    if (on)
    {
        if (g_vapp_hs_widget_pet_motion_handle == MDI_RES_MOTION_NO_SLOT)
        {
			//modify for sensor split
			//g_vapp_hs_widget_pet_motion_handle = mdi_motion_start_listen_shake(MDI_MOTION_SENSITIVE_LOW, vadp_p2v_hs_widget_pet_motion_cb, this);
			g_vapp_hs_widget_pet_motion_handle = srv_sensor_start_listen(SRV_SENSOR_MOTION_SHAKE, &shake_sensitive, vadp_p2v_hs_widget_pet_motion_cb, this);
        }
    }
    else
    {
        if (g_vapp_hs_widget_pet_motion_handle != MDI_RES_MOTION_NO_SLOT)
        {
            srv_sensor_stop_listen(g_vapp_hs_widget_pet_motion_handle);
            g_vapp_hs_widget_pet_motion_handle = MDI_RES_MOTION_NO_SLOT;
        }
    }
#endif /* MOTION_SENSOR_SUPPORT */
}


void VappHsWidgetPet::onTimelineStop(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    if (isCompleted)
    {
        startConfused();
    }
}


void VappHsWidgetPet::onCreateView()
{
    // connect backlight event
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->m_signalBacklightSwitch.connect(this, &VappHsWidgetPet::onBacklightSwitch);

#if defined(MOTION_SENSOR_SUPPORT)

    //modify for sensor split
	srv_sensor_motion_shake_cfg_struct shake_sensitive;
	shake_sensitive.sensitive = SRV_SENSOR_MOTION_SHAKE_WEAK;
	
    if (g_vapp_hs_widget_pet_motion_handle == MDI_RES_MOTION_NO_SLOT)
    {
		//modify for sensor split
	   // g_vapp_hs_widget_pet_motion_handle = mdi_motion_start_listen_shake(MDI_MOTION_SENSITIVE_LOW, vadp_p2v_hs_widget_pet_motion_cb, this);
		g_vapp_hs_widget_pet_motion_handle = srv_sensor_start_listen(SRV_SENSOR_MOTION_SHAKE, &shake_sensitive,vadp_p2v_hs_widget_pet_motion_cb,this);
    }
#endif /* MOTION_SENSOR_SUPPORT */

    // create timeline
    VFX_OBJ_CREATE(m_timelineDrop, VfxS32Timeline, this);
    m_timelineDrop->setTarget(this);
    m_timelineDrop->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Y);
    m_timelineDrop->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);
    m_timelineDrop->m_signalStopped.connect(this, &VappHsWidgetPet::onTimelineStop);        

    // create idle timer
    VFX_OBJ_CREATE(m_timerIdle, VfxTimer, this);
    m_timerIdle->setStartDelay(SCENARIO_TIME);
    m_timerIdle->m_signalTick.connect(this, &VappHsWidgetPet::idleHandler);

    // create action timer
    VFX_OBJ_CREATE(m_timerAction, VfxTimer, this);
    m_timerAction->m_signalTick.connect(this, &VappHsWidgetPet::actionHandler);

    // create background image
    VFX_OBJ_CREATE(m_imageBg, VfxImageFrame, this);
    m_imageBg->setOpacity(0.0f);
    m_imageBg->setAutoAnimate(VFX_TRUE);

    // create body images
    VFX_OBJ_CREATE(m_imageBody, VfxImageFrame, this);
    m_imageBody->m_signalBoundsChanged.connect(this, &VappHsWidgetPet::onBoundsValueChange);

    // create foreground image
    VFX_OBJ_CREATE(m_imageFg, VfxImageFrame, this);
    m_imageFg->setOpacity(0.0f);
    m_imageFg->setAutoAnimate(VFX_TRUE);

    // create background butterfly image
    VFX_OBJ_CREATE(m_imageFly, VfxImageFrame, this);
    m_imageFly->setAnchor(VfxFPoint(0.5, 0.5));
    m_imageFly->setOpacity(0.0f);
    m_imageFly->setAutoAnimate(VFX_TRUE);

    // create idle timer
    VFX_OBJ_CREATE(m_timerFly, VfxTimer, this);
    m_timerFly->setDuration(FLY_TIME);
    m_timerFly->m_signalTick.connect(this, &VappHsWidgetPet::flyHandler);

    startDrag();
}


void VappHsWidgetPet::onReleaseView()
{    
    // disconnect backlight event
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->m_signalBacklightSwitch.disconnect(this, &VappHsWidgetPet::onBacklightSwitch);

#if defined(MOTION_SENSOR_SUPPORT)
    if (g_vapp_hs_widget_pet_motion_handle != MDI_RES_MOTION_NO_SLOT)
    {
       srv_sensor_stop_listen(g_vapp_hs_widget_pet_motion_handle);
        g_vapp_hs_widget_pet_motion_handle = MDI_RES_MOTION_NO_SLOT;
    }
#endif /* MOTION_SENSOR_SUPPORT */

    VFX_OBJ_CLOSE(m_timerFly);
    VFX_OBJ_CLOSE(m_imageFly);
    VFX_OBJ_CLOSE(m_imageFg);
    VFX_OBJ_CLOSE(m_imageBody);
    VFX_OBJ_CLOSE(m_imageBg);
    VFX_OBJ_CLOSE(m_timerAction);
    VFX_OBJ_CLOSE(m_timerIdle);
    VFX_OBJ_CLOSE(m_timelineDrop);

    m_lifeState = STATE_INACTIVE;
}


void VappHsWidgetPet::onAddToDesktop()
{
    startDrop();
}


void VappHsWidgetPet::onRemoveFromDesktop()
{
    startDrag();
}


void VappHsWidgetPet::onBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds)
{
    VFX_UNUSED(source);
    VFX_UNUSED(oldBounds);

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    setBounds(m_imageBody->getBounds());
    m_imageBg->setBounds(m_imageBody->getBounds());
    m_imageFg->setBounds(m_imageBody->getBounds());
    VfxAutoAnimate::commit();
}

#endif /* __MMI_VUI_HOMESCREEN_PET__ */

