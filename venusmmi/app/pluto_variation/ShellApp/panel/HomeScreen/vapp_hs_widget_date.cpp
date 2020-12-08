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
 *  vapp_hs_widget_date.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: date
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

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_DATE__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_hs_widget_date.h"

#include "vfx_datatype.h"
#include "vdat_systime.h"
#include "vfx_date_time.h"
#include "mmi_rp_app_venus_homescreen_wg_date_def.h"
#include "vfx_cpp_base.h"           
#include "vfx_sys_memory.h"         
#include "vfx_object.h"             
#include "vfx_basic_type.h"         
#include "vfx_primitive_frame.h"    
#include "vfx_signal.h" 

/***************************************************************************** 
 * Home screen widget: date
 *****************************************************************************/
VappHsWidgetDate::VappHsWidgetDate() :
    m_imageMonth(NULL),
    m_imageWeek(NULL),
    m_imageBg(NULL)
{
    for (VfxS32 i = 0 ; i < 2 ; i++)
    {
        m_imageDay[i] = NULL;
        m_imageIconDigits[i] = NULL;
    }
}


void VappHsWidgetDate::timeUpdateIcon(VfxU32 flag)
{
    if (flag & VDAT_SYSTIME_CHANGED_DAY)
    {
        VfxDateTime date;

        date.setCurrentTime();

        VfxU32 day = date.getDay();

        for (VfxS32 i = 1 ; i >= 0 ; i--)
        {
            m_imageIconDigits[i]->setResId(VAPP_HS_IMG_WG_ICON_DATE_D0 + (day % 10));
            day /= 10;
        }
    }
}


VfxBool VappHsWidgetDate::onCreateIconView()
{
    // background image
    m_controlIcon->setImgContent(VfxImageSrc(VAPP_HS_IMG_WG_ICON_DATE_BG));
    m_controlIcon->setBounds(VfxRect(VFX_POINT_ZERO, m_controlIcon->getImgContent().getSize()));

    for (VfxS32 i = 0 ; i < 2 ; i++)
    {
        VFX_OBJ_CREATE(m_imageIconDigits[i], VfxImageFrame, m_controlIcon);
        m_imageIconDigits[i]->setAnchor(VfxFPoint((VfxFloat)(1 - i), 0.5));
        m_imageIconDigits[i]->setPos(VfxPoint((m_controlIcon->getImgContent().getSize().width / 2),
                                              (m_controlIcon->getImgContent().getSize().height / 2)));
    }

    timeUpdateIcon(VDAT_SYSTIME_CHANGED_DAY);

    // connect signal to refresh the time string
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappHsWidgetDate::timeUpdateIcon);

    return VFX_TRUE;
}


void VappHsWidgetDate::onReleaseIconView()
{
    m_controlIcon->setImgContent(VFX_IMAGE_SRC_NULL);

    // Disconnect system time signal
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.disconnect(this, &VappHsWidgetDate::timeUpdateIcon);

    for (VfxS32 i = 0 ; i < 2 ; i++)
    {
        VFX_OBJ_CLOSE(m_imageIconDigits[i]);
    }
}


void VappHsWidgetDate::onCreateView()
{
    // set background image
    VFX_OBJ_CREATE(m_imageBg, VfxImageFrame, this);
    m_imageBg->setResId(VAPP_HS_IMG_WG_DATE);
#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    m_imageBg->setIsOpaque(VFX_TRUE);
    setIsOpaque(VFX_TRUE);
#endif /* defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

    setBounds(m_imageBg->getBounds());

    VFX_OBJ_CREATE(m_imageMonth, VfxImageFrame, this);
    m_imageMonth->setAnchor(VfxFPoint(0.5, 0.5));

    VFX_OBJ_CREATE(m_imageWeek, VfxImageFrame, this);
    m_imageWeek->setAnchor(VfxFPoint(0.5, 0.5));

    VFX_OBJ_CREATE(m_imageDay[0], VfxImageFrame, this);
    m_imageDay[0]->setAnchor(VfxFPoint(0.5, 0.5));

    VFX_OBJ_CREATE(m_imageDay[1], VfxImageFrame, this);
    m_imageDay[1]->setAnchor(VfxFPoint(0.5, 0.5));

    timeUpdate(VDAT_SYSTIME_CHANGED_DAY);

    // connect signal to refresh the time string
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappHsWidgetDate::timeUpdate);
}


void VappHsWidgetDate::onReleaseView()
{
    // Disconnect system time signal
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.disconnect(this, &VappHsWidgetDate::timeUpdate);

    VFX_OBJ_CLOSE(m_imageMonth);
    VFX_OBJ_CLOSE(m_imageWeek);
    
    for (VfxS32 i = 0 ; i < 2 ; i++)
    {
        VFX_OBJ_CLOSE(m_imageDay[i]);
    }

    VFX_OBJ_CLOSE(m_imageBg);
}


void VappHsWidgetDate::timeUpdate(VfxU32 flag)
{
    if (flag & VDAT_SYSTIME_CHANGED_DAY)
    {
        VfxDateTime date;

        date.setCurrentTime();

        VfxDateTime::DayOfWeekEnum week;
        VfxU32 day = date.getDay();
    
        // set month
        m_imageMonth->setResId(VAPP_HS_IMG_WG_DATE_M1 + date.getMonth() - 1);
    
        // set week
        // TODO: revise this
        date.getDayOfWeek(&week);
        m_imageWeek->setResId(VAPP_HS_IMG_WG_DATE_W0 + (VfxS32)week);
    
        // set day
        m_imageDay[0]->setResId(VAPP_HS_IMG_WG_DATE_D0 + day / 10);
        m_imageDay[1]->setResId(VAPP_HS_IMG_WG_DATE_D0 + day % 10);
    
        // get widget bounds for auto-layout
        VfxRect bounds = getBounds();
    
        // layout month, week, and day text
        VfxS32 y1 = (bounds.getHeight() - 2 * GAP - m_imageWeek->getBounds().getHeight()) / 2;
        VfxS32 y2 = y1 + m_imageMonth->getBounds().getHeight() / 2 + 2 * GAP + (m_imageWeek->getBounds().getHeight()) / 2;
    
        m_imageMonth->setPos(VfxPoint(bounds.getWidth() / 4, y1));
        m_imageWeek->setPos(VfxPoint(bounds.getWidth() / 4, y2));
    
        m_imageDay[0]->setPos(VfxPoint(3 * bounds.getWidth() / 4 - 1 - (m_imageDay[0]->getBounds().getWidth() / 2), bounds.getHeight() / 2));
        m_imageDay[1]->setPos(VfxPoint(3 * bounds.getWidth() / 4 + 1 + (m_imageDay[1]->getBounds().getWidth() / 2), bounds.getHeight() / 2));
    }
}

#endif /* __MMI_VUI_HOMESCREEN_DATE__ */

