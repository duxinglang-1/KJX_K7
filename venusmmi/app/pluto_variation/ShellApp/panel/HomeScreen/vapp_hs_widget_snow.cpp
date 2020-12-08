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
 *  vapp_hs_widget_snow.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: falling snow
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_SNOW__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_hs_widget_snow.h"
#include "stdlib.h"

#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_primitive_frame.h"
#include "mmi_rp_app_venus_homescreen_wg_snow_def.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vrt_system.h"
#include "vfx_timer.h"
#include "vfx_signal.h"
#include "vfx_auto_animate.h"

/***************************************************************************** 
 * Home screen widget: falling snow
 *****************************************************************************/

VappHsWidgetSnow::VappHsWidgetSnow() :
    m_imageBg(NULL),
    m_timerRefresh(NULL)
{
    for (VfxS32 i = 0 ; i < MAX_SNOW ; i ++)
    {
        m_imageSnow[i] = NULL;
    }
}


void VappHsWidgetSnow::onCreateView()
{
    // background image
    VFX_OBJ_CREATE(m_imageBg, VfxImageFrame, this);
    m_imageBg->setResId(VAPP_HS_IMG_WG_SNOWMAN);

    // widget size is the same as the background image
    setBounds(m_imageBg->getBounds());

    // init snow
    for (VfxS32 i = 0 ; i < MAX_SNOW ; i ++)
    {
        VfxPoint pos;
        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;

        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        // init positioin
        pos.x = MARGIN + i * (main_screen_size.width - (MARGIN << 1)) / MAX_SNOW + (rand() % (X_RANGE + 1)) - (X_RANGE / 2);
        pos.y = - (rand() % FLOOR_HEIGHT + Y_RANGE) - (i % MAX_FLOOR) * FLOOR_HEIGHT;

        // create snow
        VFX_OBJ_CREATE(m_imageSnow[i], VfxImageFrame, this);
        m_imageSnow[i]->setResId(VAPP_HS_IMG_WG_SNOW1 + (rand() % MAX_VARIANT));
        m_imageSnow[i]->setOpacity(1.0f - 0.2f * (rand() % MAX_VARIANT));
        m_imageSnow[i]->setAutoAnimate(VFX_TRUE);
        m_imageSnow[i]->setPos(pos);
    }

    // init refresh timer
    VFX_OBJ_CREATE(m_timerRefresh, VfxTimer, this);
    m_timerRefresh->setDuration(REFRESH_TIME);
    m_timerRefresh->m_signalTick.connect(this, &VappHsWidgetSnow::onTimerRefresh);
}


void VappHsWidgetSnow::onReleaseView()
{
    for (VfxS32 i = 0 ; i < MAX_SNOW ; i ++)
    {
        VFX_OBJ_CLOSE(m_imageSnow[i]);
    }

    VFX_OBJ_CLOSE(m_imageBg);
    VFX_OBJ_CLOSE(m_timerRefresh);
}


void VappHsWidgetSnow::onAddToDesktop()
{
    for (VfxS32 i = 0 ; i < MAX_SNOW ; i ++)
    {
        addToBottom(m_imageSnow[i]);
    }
    m_timerRefresh->start();
}


void VappHsWidgetSnow::onRemoveFromDesktop()
{
    m_timerRefresh->stop();
    for (VfxS32 i = 0 ; i < MAX_SNOW ; i ++)
    {
        removeFromBottom(m_imageSnow[i]);
    }
}


void VappHsWidgetSnow::onTimerRefresh(VfxTimer *source)
{
    VFX_UNUSED(source);

    for (VfxS32 i = 0 ; i < MAX_SNOW ; i ++)
    {
        VfxFloat opacity = m_imageSnow[i]->getOpacity();
        VfxPoint pos = m_imageSnow[i]->getPos();
        VfxS32 x_diff = (rand() % (X_RANGE + 1)) - (X_RANGE / 2);
        VfxS32 y_diff = 0;
        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;

        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        // falling snow
        x_diff = (x_diff == 0) ? (1) : (x_diff);
        y_diff = (i % MAX_VARIANT + 1) * (Y_RANGE / 2);
        pos.x += x_diff;
        pos.y += y_diff;

        // fade-out
        if (pos.y > ((main_screen_size.height + MARGIN) >> 1))
        {
            opacity -= 0.05f * (rand() % 3);
        }

        // restart snowflake
        if (pos.x > (main_screen_size.width + MARGIN) || pos.y > (main_screen_size.height + MARGIN) || opacity < 0)
        {
            pos.x = MARGIN + i * (main_screen_size.width - (MARGIN << 1)) / MAX_SNOW + (rand() % (X_RANGE + 1)) - (X_RANGE / 2);
            pos.y = - (rand() % FLOOR_HEIGHT + Y_RANGE) - (i % MAX_FLOOR) * FLOOR_HEIGHT;

            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
            m_imageSnow[i]->setPos(pos);
            m_imageSnow[i]->setResId(VAPP_HS_IMG_WG_SNOW1 + (rand() % MAX_VARIANT));
            m_imageSnow[i]->setOpacity(1.0f - 0.2f * (rand() % MAX_VARIANT));
            VfxAutoAnimate::commit();
        }
        else
        {
            opacity = (opacity < 0.05f) ? (0.05f) : (opacity);

            m_imageSnow[i]->setOpacity(opacity);
            m_imageSnow[i]->setPos(pos);
        }
    }
}

#endif /* __MMI_VUI_HOMESCREEN_SNOW__ */

