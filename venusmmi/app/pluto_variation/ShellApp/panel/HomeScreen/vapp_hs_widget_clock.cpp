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
 *  vapp_hs_widget_aclock.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: clock
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_CLOCK__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_hs_widget_clock.h"

#include "vadp_v2p_hs_widget_dualclock.h"
#include "vfx_cpp_base.h"
#include "vfx_date_time.h"
#include "vfx_datatype.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vcp_clock.h"
#include "mmi_rp_app_venus_homescreen_wg_clock_def.h"
#include "vrt_system.h"
#include "vfx_basic_type.h"
#include "vfx_image_src.h"
#include "vfx_primitive_frame.h"
#include "vfx_text_frame.h"
#include "vfx_string.h"
#include "vrt_datatype.h"
#include "vapp_hs_widget_base.h"

#ifdef __cplusplus
extern "C"
{
#endif
    #include "kal_public_api.h"
    #include "kal_general_types.h"
    #include "GlobalResDef.h"
#ifdef __cplusplus
}   /* extern "C" */
#endif

/***************************************************************************** 
 * Home screen widget: clock
 *****************************************************************************/

VappHsWidgetClock::VappHsWidgetClock() :
    m_style(NULL),
    m_type(NULL),
    m_aclock(NULL),
    m_dclock(NULL),
    m_icon_aclock(NULL),
    m_icon_dclock(NULL),    
    m_aclock_ecdemic(NULL),
    m_dclock_ecdemic(NULL),
    m_textCity(NULL),
    m_textCity_ecdemic(NULL),
    m_bg(NULL)
{
    vadp_v2p_hs_clock_read_nvram();
}



#if 1

VfxBool VappHsWidgetClock::onCreateIconView()
{
    VfxDateTime dt;

    m_style = vadp_v2p_hs_clock_get_style();
    m_type = vadp_v2p_hs_clock_get_type();

    if (m_type == CLOCK_ECDEMIC)
    {
        // set city time
        VfxU32 hour = 0, mins = 0, secs = 0;
        vadp_v2p_hs_dualclock_get_time(&hour, &mins, &secs);
        dt.setTime(hour, mins, secs);
    }

    
    if (m_style == CLOCK_ANALOG || m_style == CLOCK_ANALOG2)
    {
        VFX_OBJ_CREATE(m_icon_aclock, VcpAnalogClock, m_controlIcon);
        

        if (m_type == CLOCK_ECDEMIC)
        {
            m_icon_aclock->setTime(dt);
            if (m_style == CLOCK_ANALOG)
            {
                m_icon_aclock->setClockBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_ACLOCK_ICON_E_BG));
                m_icon_aclock->setClockHourHand(VAPP_HS_IMG_WG_ACLOCK_ICON_E_H);
                m_icon_aclock->setClockMinuteHand(VAPP_HS_IMG_WG_ACLOCK_ICON_E_M);
                m_icon_aclock->setClockSecondHand(VAPP_HS_IMG_WG_ACLOCK_ICON_E_S);
                m_icon_aclock->setClockAxis(VAPP_HS_IMG_WG_ACLOCK_ICON_E_CENTER);
                m_icon_aclock->setCenter(VfxPoint(WG_ICON_ANALOG_CENTER_X, WG_ICON_ANALOG_CENTER_Y));
            }
            else if (m_style == CLOCK_ANALOG2)
            {
                m_icon_aclock->setClockBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_ACLOCK2_ICON_E_BG));
                m_icon_aclock->setClockHourHand(VAPP_HS_IMG_WG_ACLOCK2_ICON_E_H);
                m_icon_aclock->setClockMinuteHand(VAPP_HS_IMG_WG_ACLOCK2_ICON_E_M);
                m_icon_aclock->setClockSecondHand(VAPP_HS_IMG_WG_ACLOCK2_ICON_E_S);
                m_icon_aclock->setClockAxis(VAPP_HS_IMG_WG_ACLOCK2_ICON_E_CENTER);
                m_icon_aclock->setCenter(VfxPoint(WG_ICON_ANALOG2_CENTER_X, WG_ICON_ANALOG2_CENTER_Y));
            }
            else
            {
                ASSERT(0);
            }           
        }
        else
        {
            m_icon_aclock->setTime();
            if (m_style == CLOCK_ANALOG)
            {
                m_icon_aclock->setClockBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_ACLOCK_ICON_L_BG));
                m_icon_aclock->setClockHourHand(VAPP_HS_IMG_WG_ACLOCK_ICON_L_H);
                m_icon_aclock->setClockMinuteHand(VAPP_HS_IMG_WG_ACLOCK_ICON_L_M);
                m_icon_aclock->setClockSecondHand(VAPP_HS_IMG_WG_ACLOCK_ICON_L_S);
                m_icon_aclock->setClockAxis(VAPP_HS_IMG_WG_ACLOCK_ICON_L_CENTER);           
                m_icon_aclock->setCenter(VfxPoint(WG_ICON_ANALOG_CENTER_X, WG_ICON_ANALOG_CENTER_Y));
            }
            else if (m_style == CLOCK_ANALOG2)
            {
                m_icon_aclock->setClockBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_ACLOCK2_ICON_L_BG));
                m_icon_aclock->setClockHourHand(VAPP_HS_IMG_WG_ACLOCK2_ICON_L_H);
                m_icon_aclock->setClockMinuteHand(VAPP_HS_IMG_WG_ACLOCK2_ICON_L_M);
                m_icon_aclock->setClockSecondHand(VAPP_HS_IMG_WG_ACLOCK2_ICON_L_S);
                m_icon_aclock->setClockAxis(VAPP_HS_IMG_WG_ACLOCK2_ICON_L_CENTER);  
                m_icon_aclock->setCenter(VfxPoint(WG_ICON_ANALOG2_CENTER_X, WG_ICON_ANALOG2_CENTER_Y));               
            }
            else
            {
                ASSERT(0);
            }           
        }
        

        m_icon_aclock->startClock();
        
        //m_controlIcon->setContent(m_aclock);
        m_controlIcon->setBounds(VfxRect(VFX_POINT_ZERO, m_icon_aclock->getSize()));
    }
    else if (m_style == CLOCK_DIGITAL)
    {
        // background image 
        VfxImageSrc imgsrc(VAPP_HS_IMG_WG_DCLOCK_ICON_L_BG);
        VfxSize size = imgsrc.getSize();

        //VFX_OBJ_CREATE(m_image_bg, VfxImage, this);
        //m_image_bg->setResId(VAPP_HS_IMG_WG_DCLOCK_ICON_L_BG);
        
        VFX_OBJ_CREATE(m_icon_dclock, VcpDigitalImageClock, m_controlIcon);
        m_icon_dclock->setAnchor(VfxFPoint(0.5, 0.5));
        m_icon_dclock->setPos(VfxPoint((size).width / 2, (size).height / 2));
        m_icon_dclock->setGap(GAP_ICON_DIGITAL_NORMAL, GAP_ICON_DIGITAL_SEPARATOR, GAP_ICON_DIGITAL_AMPM);
        
        if (m_type == CLOCK_ECDEMIC)
        {
            m_icon_dclock->setTime(dt);
            m_icon_dclock->setBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_ICON_E_BG));
            m_icon_dclock->setNumber(VAPP_HS_IMG_WG_DCLOCK_ICON_E_NUM_0, VAPP_HS_IMG_WG_DCLOCK_ICON_E_NUM_9);
            m_icon_dclock->setNumberBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_ICON_E_NUM_BG));
            m_icon_dclock->setTimeSeparator(VAPP_HS_IMG_WG_DCLOCK_ICON_E_COLON, VAPP_HS_IMG_WG_DCLOCK_ICON_E_COLON_BG);
        }
        else
        {
            m_icon_dclock->setTime();
            m_icon_dclock->setBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_ICON_L_BG));
            m_icon_dclock->setNumber(VAPP_HS_IMG_WG_DCLOCK_ICON_L_NUM_0, VAPP_HS_IMG_WG_DCLOCK_ICON_L_NUM_9);
            m_icon_dclock->setNumberBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_ICON_L_NUM_BG));
            m_icon_dclock->setTimeSeparator(VAPP_HS_IMG_WG_DCLOCK_ICON_L_COLON, VAPP_HS_IMG_WG_DCLOCK_ICON_L_COLON_BG);
        }

        m_icon_dclock->setAmAndPm(
            vrt_sys_res_image_lock(IMG_NONE), 
            vrt_sys_res_image_lock(IMG_NONE), 
            vrt_sys_res_image_lock(IMG_NONE), 
            vrt_sys_res_image_lock(IMG_NONE));

        m_icon_dclock->startClock();  
        
        //VFX_OBJ_CLOSE(m_image_bg);     
        
        m_controlIcon->setBounds(VfxRect(VFX_POINT_ZERO, m_icon_dclock->getSize()));
    }

    return VFX_TRUE;
}


void VappHsWidgetClock::onReleaseIconView()
{
    if (m_style == CLOCK_ANALOG || m_style == CLOCK_ANALOG2)
    {
        VFX_OBJ_CLOSE(m_icon_aclock);
    }
    else if (m_style == CLOCK_DIGITAL)
    {
        VFX_OBJ_CLOSE(m_icon_dclock);
    }
}
#endif



void VappHsWidgetClock::onCreateView()
{
    VfxDateTime dt;

#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    setIsOpaque(VFX_TRUE);
#endif /* defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

    m_style = vadp_v2p_hs_clock_get_style();
    m_type = vadp_v2p_hs_clock_get_type();

    if (m_type == CLOCK_DUAL)
    {
        if (m_style == CLOCK_ANALOG)
        {
            // background of dual clock
            VFX_OBJ_CREATE(m_bg, VfxImageFrame, this);
            m_bg->setResId(VAPP_HS_IMG_WG_ACLOCK_DUAL_BG);
            m_bg->setPos(VfxPoint(0, DUAL_BG_ANALOG_Y));
        }
        else if (m_style == CLOCK_ANALOG2)
        {
            // background of dual clock
            VFX_OBJ_CREATE(m_bg, VfxImageFrame, this);
            m_bg->setResId(VAPP_HS_IMG_WG_ACLOCK2_DUAL_BG);
            m_bg->setPos(VfxPoint(0, DUAL_BG_ANALOG2_Y));            
        }
        else if (m_style == CLOCK_DIGITAL)
        {
            // background of dual clock
            VFX_OBJ_CREATE(m_bg, VfxImageFrame, this);
            m_bg->setResId(VAPP_HS_IMG_WG_DCLOCK_DUAL_BG);
            m_bg->setPos(VfxPoint(0, DUAL_BG_DIGITAL_Y));
        }
        else
        {
            ASSERT(0);
        }
    }
    
    // city name
    if (m_type == CLOCK_LOCAL || m_type == CLOCK_DUAL)
    {
        VFX_OBJ_CREATE(m_textCity, VfxTextFrame, this);
        m_textCity->setAnchor(VfxFPoint(0.5, 0.5));
        m_textCity->setPos(VfxPoint(0, 0));
        m_textCity->setBounds(VfxRect(0, 0, 0, 0 /* text frame will assign automatically */));
        m_textCity->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_textCity->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        m_textCity->setString(VFX_WSTR_MEM(vadp_v2p_hs_dualclock_get_home_name()));
        m_textCity->forceUpdate();
    }
    
    if (m_type == CLOCK_ECDEMIC || m_type == CLOCK_DUAL)
    {
        VFX_OBJ_CREATE(m_textCity_ecdemic, VfxTextFrame, this);
        m_textCity_ecdemic->setAnchor(VfxFPoint(0.5, 0.5));
        m_textCity_ecdemic->setPos(VfxPoint(0, 0));
        m_textCity_ecdemic->setBounds(VfxRect(0, 0, 0, 0 /* text frame will assign automatically */));
        m_textCity_ecdemic->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_textCity_ecdemic->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        m_textCity_ecdemic->setString(VFX_WSTR_MEM(vadp_v2p_hs_dualclock_get_name()));
        m_textCity_ecdemic->forceUpdate();

        // set city time
        VfxU32 hour = 0, mins = 0, secs = 0;
        vadp_v2p_hs_dualclock_get_time(&hour, &mins, &secs);
        dt.setTime(hour, mins, secs);
    }

    if (m_style == CLOCK_ANALOG || m_style == CLOCK_ANALOG2)
    {
        if (m_type == CLOCK_LOCAL)
        {
            VFX_OBJ_CREATE(m_aclock, VcpAnalogClock, this);
            m_aclock->setTime();
            if (m_style == CLOCK_ANALOG)
            {            
                m_aclock->setClockBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_ACLOCK_LOCAL_BG));
                m_aclock->setClockHourHand(VAPP_HS_IMG_WG_ACLOCK_L_H);
                m_aclock->setClockMinuteHand(VAPP_HS_IMG_WG_ACLOCK_L_M);
                m_aclock->setClockSecondHand(VAPP_HS_IMG_WG_ACLOCK_L_S);
                m_aclock->setClockAxis(VAPP_HS_IMG_WG_ACLOCK_L_CENTER);
                m_aclock->setCenter(VfxPoint(ANALOG_CENTER, ANALOG_CENTER));
            }
            else if (m_style == CLOCK_ANALOG2)
            {
                m_aclock->setClockBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_ACLOCK2_LOCAL_BG));
                m_aclock->setClockHourHand(VAPP_HS_IMG_WG_ACLOCK2_L_H);
                m_aclock->setClockMinuteHand(VAPP_HS_IMG_WG_ACLOCK2_L_M);
                m_aclock->setClockSecondHand(VAPP_HS_IMG_WG_ACLOCK2_L_S);
                m_aclock->setClockAxis(VAPP_HS_IMG_WG_ACLOCK2_L_CENTER);
                m_aclock->setCenter(VfxPoint(ANALOG2_CENTER_X, ANALOG2_CENTER_Y));                
            }
            else
            {
                ASSERT(0);
            }
            m_aclock->startClock();

            setBounds(
                VfxRect(
                    0,0, 
                    (m_aclock->getBounds()).getWidth(), 
                    (m_aclock->getBounds()).getHeight() + (m_textCity->getBounds()).getHeight()));
            
            m_textCity->setPos(VfxPoint((m_aclock->getBounds()).getWidth()/2, (m_aclock->getBounds()).getHeight() + (m_textCity->getBounds()).getHeight()/2));
            m_textCity->setBounds(VfxRect(0, 0, (m_aclock->getBounds()).getWidth(), (m_textCity->getBounds()).getHeight()));
        }
        else if (m_type == CLOCK_ECDEMIC)
        {
            VFX_OBJ_CREATE(m_aclock_ecdemic, VcpAnalogClock, this);
            if (m_style == CLOCK_ANALOG)
            {
                m_aclock_ecdemic->setClockBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_ACLOCK_ECDEMIC_BG));
                m_aclock_ecdemic->setClockHourHand(VAPP_HS_IMG_WG_ACLOCK_E_H);
                m_aclock_ecdemic->setClockMinuteHand(VAPP_HS_IMG_WG_ACLOCK_E_M);
                m_aclock_ecdemic->setClockSecondHand(VAPP_HS_IMG_WG_ACLOCK_E_S);
                m_aclock_ecdemic->setClockAxis(VAPP_HS_IMG_WG_ACLOCK_E_CENTER);
                m_aclock_ecdemic->setCenter(VfxPoint(ANALOG_CENTER, ANALOG_CENTER));                
            }
            else if (m_style == CLOCK_ANALOG2)
            {
                m_aclock_ecdemic->setClockBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_ACLOCK2_ECDEMIC_BG));
                m_aclock_ecdemic->setClockHourHand(VAPP_HS_IMG_WG_ACLOCK2_E_H);
                m_aclock_ecdemic->setClockMinuteHand(VAPP_HS_IMG_WG_ACLOCK2_E_M);
                m_aclock_ecdemic->setClockSecondHand(VAPP_HS_IMG_WG_ACLOCK2_E_S);
                m_aclock_ecdemic->setClockAxis(VAPP_HS_IMG_WG_ACLOCK2_E_CENTER);
                m_aclock_ecdemic->setCenter(VfxPoint(ANALOG2_CENTER_X, ANALOG2_CENTER_Y));                
            }
            else
            {
                ASSERT(0);
            }
            m_aclock_ecdemic->setTime(dt);
            m_aclock_ecdemic->startClock();

            m_aclock_ecdemic->setHourHandColor(VfxColor(VRT_COLOR_WHITE));
            m_aclock_ecdemic->setMinuteHandColor(VfxColor(VRT_COLOR_WHITE));

            setBounds(
                VfxRect(
                0,0, 
                (m_aclock_ecdemic->getBounds()).getWidth(), 
                (m_aclock_ecdemic->getBounds()).getHeight() + (m_textCity_ecdemic->getBounds()).getHeight()));

            m_textCity_ecdemic->setPos(VfxPoint((m_aclock_ecdemic->getBounds()).getWidth()/2, (m_aclock_ecdemic->getBounds()).getHeight() + (m_textCity_ecdemic->getBounds()).getHeight()/2));
            m_textCity_ecdemic->setBounds(VfxRect(0, 0, (m_aclock_ecdemic->getBounds()).getWidth(), (m_textCity_ecdemic->getBounds()).getHeight()));
        }
        else if (m_type == CLOCK_DUAL)
        {

            VFX_OBJ_CREATE(m_aclock, VcpAnalogClock, this);
            m_aclock->setTime();
            m_aclock->startClock();
            if (m_style == CLOCK_ANALOG)
            {            
                m_aclock->setClockBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_ACLOCK_DUAL_LOCAL_BG));
                m_aclock->setClockHourHand(VAPP_HS_IMG_WG_ACLOCK_DUAL_L_H);
                m_aclock->setClockMinuteHand(VAPP_HS_IMG_WG_ACLOCK_DUAL_L_M);
                m_aclock->setClockSecondHand(VAPP_HS_IMG_WG_ACLOCK_DUAL_L_S);
                m_aclock->setClockAxis(VAPP_HS_IMG_WG_ACLOCK_DUAL_L_CENTER);
                m_aclock->setCenter(VfxPoint(ANALOG_DUAL_CENTER, ANALOG_DUAL_CENTER));
            }
            else if (m_style == CLOCK_ANALOG2)
            {
                m_aclock->setClockBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_ACLOCK2_DUAL_LOCAL_BG));
                m_aclock->setClockHourHand(VAPP_HS_IMG_WG_ACLOCK2_DUAL_L_H);
                m_aclock->setClockMinuteHand(VAPP_HS_IMG_WG_ACLOCK2_DUAL_L_M);
                m_aclock->setClockSecondHand(VAPP_HS_IMG_WG_ACLOCK2_DUAL_L_S);
                m_aclock->setClockAxis(VAPP_HS_IMG_WG_ACLOCK2_DUAL_L_CENTER);
                m_aclock->setCenter(VfxPoint(ANALOG2_DUAL_CENTER_X, ANALOG2_DUAL_CENTER_X));                
            }
            else
            {
                ASSERT(0); 
            }         
            
            VFX_OBJ_CREATE(m_aclock_ecdemic, VcpAnalogClock, this);
            if (m_style == CLOCK_ANALOG)
            {            
                m_aclock_ecdemic->setClockBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_ACLOCK_DUAL_ECDEMIC_BG));
                m_aclock_ecdemic->setClockHourHand(VAPP_HS_IMG_WG_ACLOCK_DUAL_E_H);
                m_aclock_ecdemic->setClockMinuteHand(VAPP_HS_IMG_WG_ACLOCK_DUAL_E_M);
                m_aclock_ecdemic->setClockSecondHand(VAPP_HS_IMG_WG_ACLOCK_DUAL_E_S);
                m_aclock_ecdemic->setClockAxis(VAPP_HS_IMG_WG_ACLOCK_DUAL_E_CENTER);
                m_aclock_ecdemic->setCenter(VfxPoint(ANALOG_DUAL_CENTER, ANALOG_DUAL_CENTER));
            }
            else if (m_style == CLOCK_ANALOG2)
            {
                m_aclock_ecdemic->setClockBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_ACLOCK2_DUAL_ECDEMIC_BG));
                m_aclock_ecdemic->setClockHourHand(VAPP_HS_IMG_WG_ACLOCK2_DUAL_E_H);
                m_aclock_ecdemic->setClockMinuteHand(VAPP_HS_IMG_WG_ACLOCK2_DUAL_E_M);
                m_aclock_ecdemic->setClockSecondHand(VAPP_HS_IMG_WG_ACLOCK2_DUAL_E_S);
                m_aclock_ecdemic->setClockAxis(VAPP_HS_IMG_WG_ACLOCK2_DUAL_E_CENTER);
                m_aclock_ecdemic->setCenter(VfxPoint(ANALOG2_DUAL_CENTER_X, ANALOG2_DUAL_CENTER_X));                
            }
            else
            {
                ASSERT(0);
            }              
            m_aclock_ecdemic->setHourHandColor(VfxColor(VRT_COLOR_WHITE));
            m_aclock_ecdemic->setMinuteHandColor(VfxColor(VRT_COLOR_WHITE));
            m_aclock_ecdemic->setTime(dt);
            m_aclock_ecdemic->startClock();

            setBounds(
                VfxRect(
                0,
                0, 
                (m_bg->getSize()).width, 
                (m_bg->getPos()).y + (m_bg->getSize()).height)); 

            m_aclock->setPos(VfxPoint(GAP_ANALOG_BORDER, 0));
            m_aclock_ecdemic->setPos(VfxPoint(GAP_ANALOG_BORDER + (m_aclock->getBounds()).getWidth() + GAP_DUAL_ANALOG_CLOCK, 0));

            m_textCity->setPos(
                VfxPoint(
                GAP_ANALOG_BORDER + (m_aclock->getBounds()).getWidth()/2, 
                (m_aclock->getBounds()).getHeight() + (m_textCity->getBounds()).getHeight()/2 - 1));
            m_textCity->setBounds(VfxRect(0, 0, (m_aclock->getBounds()).getWidth(), (m_textCity->getBounds()).getHeight()));
            
            m_textCity_ecdemic->setPos(
                VfxPoint(
                    GAP_ANALOG_BORDER + (m_aclock->getBounds()).getWidth() + GAP_DUAL_ANALOG_CLOCK + (m_aclock_ecdemic->getBounds()).getWidth()/2, 
                    (m_aclock_ecdemic->getBounds()).getHeight() + (m_textCity_ecdemic->getBounds()).getHeight()/2 - 1));
            m_textCity_ecdemic->setBounds(VfxRect(0, 0, (m_aclock_ecdemic->getBounds()).getWidth(), (m_textCity_ecdemic->getBounds()).getHeight()));


        }
    }
    else if (m_style == CLOCK_DIGITAL)
    {
        if (m_type == CLOCK_LOCAL)
        {
            // background image 
            VfxImageSrc imgsrc(VAPP_HS_IMG_WG_DCLOCK_LOCAL_BG);
            VfxSize size = imgsrc.getSize();
            //VFX_OBJ_CREATE(m_image_bg, VfxImage, this);
            //m_image_bg->setResId(VAPP_HS_IMG_WG_DCLOCK_LOCAL_BG);

            setBounds(
                VfxRect(
                    0,0, 
                    (size).width,
                    (size).height + (m_textCity->getBounds()).getHeight()));

            
            VFX_OBJ_CREATE(m_dclock, VcpDigitalImageClock, this);
            m_dclock->setAnchor(VfxFPoint(0.5, 0.5));
            m_dclock->setPos(VfxPoint(getBounds().getWidth() / 2, (size).height / 2));
            m_dclock->setTime();
            m_dclock->setBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_LOCAL_BG));
            m_dclock->setNumber(VAPP_HS_IMG_WG_DCLOCK_L_NUM_0, VAPP_HS_IMG_WG_DCLOCK_L_NUM_9);
            m_dclock->setNumberBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_L_NUM_BG));
            m_dclock->setTimeSeparator(VAPP_HS_IMG_WG_DCLOCK_L_COLON, VAPP_HS_IMG_WG_DCLOCK_L_COLON_BG);
            m_dclock->setAmAndPm(
                vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_L_AM), 
                vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_L_AM_BG), 
                vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_L_PM), 
                vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_L_PM_BG));
            m_dclock->startClock();  

            m_textCity->setPos(VfxPoint((size).width/2, (size).height + (m_textCity->getBounds()).getHeight()/2));
            m_textCity->setBounds(VfxRect(0, 0, (size).width, (m_textCity->getBounds()).getHeight()));
            //VFX_OBJ_CLOSE(m_image_bg); 
        }
        else if (m_type == CLOCK_ECDEMIC)
        {
            // background image 
            VfxImageSrc imgsrc(VAPP_HS_IMG_WG_DCLOCK_ECDEMIC_BG);
            VfxSize size = imgsrc.getSize();

            //VFX_OBJ_CREATE(m_image_bg, VfxImage, this);
            //m_image_bg->setResId(VAPP_HS_IMG_WG_DCLOCK_ECDEMIC_BG);
            
            setBounds(
                VfxRect(
                0,
                0, 
                (size).width,
                (size).height + (m_textCity_ecdemic->getBounds()).getHeight()));

            VFX_OBJ_CREATE(m_dclock_ecdemic, VcpDigitalImageClock, this);
            m_dclock_ecdemic->setAnchor(VfxFPoint(0.5, 0.5));
            m_dclock_ecdemic->setPos(VfxPoint(getBounds().getWidth() / 2, (size).height / 2));
            m_dclock_ecdemic->setTime();
            m_dclock_ecdemic->setBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_ECDEMIC_BG));
            m_dclock_ecdemic->setNumber(VAPP_HS_IMG_WG_DCLOCK_E_NUM_0, VAPP_HS_IMG_WG_DCLOCK_E_NUM_9);
            m_dclock_ecdemic->setNumberBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_E_NUM_BG));
            m_dclock_ecdemic->setTimeSeparator(VAPP_HS_IMG_WG_DCLOCK_E_COLON, VAPP_HS_IMG_WG_DCLOCK_E_COLON_BG);
            m_dclock_ecdemic->setAmAndPm(
                vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_E_AM), 
                vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_E_AM_BG), 
                vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_E_PM), 
                vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_E_PM_BG));      
            m_dclock_ecdemic->setTime(dt);
            m_dclock_ecdemic->startClock();  

            m_textCity_ecdemic->setPos(VfxPoint((size).width/2, (size).height + (m_textCity_ecdemic->getBounds()).getHeight()/2));
            m_textCity_ecdemic->setBounds(VfxRect(0, 0, (size).width, (m_textCity_ecdemic->getBounds()).getHeight()));
            
            //VFX_OBJ_CLOSE(m_image_bg); 
        }
        else if (m_type == CLOCK_DUAL)
        {


            // background image of digital clock
            VfxImageSrc imgsrc(VAPP_HS_IMG_WG_DCLOCK_DUAL_ECDEMIC_BG);
            VfxSize size = imgsrc.getSize();

            //VFX_OBJ_CREATE(m_image_bg, VfxImage, this);
            //m_image_bg->setResId(VAPP_HS_IMG_WG_DCLOCK_DUAL_ECDEMIC_BG);
            
            setBounds(
                VfxRect(
                0,
                0, 
                (m_bg->getSize()).width,
                (m_bg->getPos()).y + (m_bg->getSize()).height));
            

            VFX_OBJ_CREATE(m_dclock, VcpDigitalImageClock, this);
            m_dclock->setAnchor(VfxFPoint(0.5, 0.5));
            m_dclock->setPos(VfxPoint(GAP_DUAL_BORDER + (size).width / 2, (size).height / 2));
            m_dclock->setTime();
            m_dclock->setBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_DUAL_LOCAL_BG));
            m_dclock->setNumber(VAPP_HS_IMG_WG_DCLOCK_DUAL_L_NUM_0, VAPP_HS_IMG_WG_DCLOCK_DUAL_L_NUM_9);
            m_dclock->setNumberBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_DUAL_L_NUM_BG));
            m_dclock->setTimeSeparator(VAPP_HS_IMG_WG_DCLOCK_DUAL_L_COLON, VAPP_HS_IMG_WG_DCLOCK_DUAL_L_COLON_BG);
            m_dclock->setGap(GAP_DUAL_DIGITAL_NORMAL, GAP_DUAL_DIGITAL_SEPARATOR, GAP_DUAL_DIGITAL_AMPM);
            m_dclock->setAmAndPm(
                vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_DUAL_L_AM), 
                vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_DUAL_L_AM_BG), 
                vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_DUAL_L_PM), 
                vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_DUAL_L_PM_BG));
            m_dclock->startClock();  
            
            m_textCity->setPos(VfxPoint(GAP_DUAL_BORDER + (size).width / 2, (size).height + (m_textCity->getBounds()).getHeight()/2));
            m_textCity->setBounds(VfxRect(0, 0, (size).width, (m_textCity->getBounds()).getHeight()));
            


            VFX_OBJ_CREATE(m_dclock_ecdemic, VcpDigitalImageClock, this);
            m_dclock_ecdemic->setAnchor(VfxFPoint(0.5, 0.5));
            m_dclock_ecdemic->setPos(VfxPoint(getBounds().getWidth() - GAP_DUAL_BORDER - (size).width / 2, (size).height / 2));
            m_dclock_ecdemic->setTime();
            m_dclock_ecdemic->setBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_DUAL_ECDEMIC_BG));
            m_dclock_ecdemic->setNumber(VAPP_HS_IMG_WG_DCLOCK_DUAL_E_NUM_0, VAPP_HS_IMG_WG_DCLOCK_DUAL_E_NUM_9);
            m_dclock_ecdemic->setNumberBackground(vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_DUAL_E_NUM_BG));
            m_dclock_ecdemic->setTimeSeparator(VAPP_HS_IMG_WG_DCLOCK_DUAL_E_COLON, VAPP_HS_IMG_WG_DCLOCK_DUAL_E_COLON_BG);
            m_dclock_ecdemic->setGap(GAP_DUAL_DIGITAL_NORMAL, GAP_DUAL_DIGITAL_SEPARATOR, GAP_DUAL_DIGITAL_AMPM);
            m_dclock_ecdemic->setAmAndPm(
                vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_DUAL_E_AM), 
                vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_DUAL_E_AM_BG), 
                vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_DUAL_E_PM), 
                vrt_sys_res_image_lock(VAPP_HS_IMG_WG_DCLOCK_DUAL_E_PM_BG));   
            
            m_dclock_ecdemic->setTime(dt);
            m_dclock_ecdemic->startClock();  
            
            m_textCity_ecdemic->setPos(VfxPoint(getBounds().getWidth() - GAP_DUAL_BORDER - (size).width / 2, (size).height + (m_textCity_ecdemic->getBounds()).getHeight()/2));
            m_textCity_ecdemic->setBounds(VfxRect(0, 0, (size).width, (m_textCity_ecdemic->getBounds()).getHeight()));
            
            //VFX_OBJ_CLOSE(m_image_bg); 
        }
            
 

    }

}


void VappHsWidgetClock::onReleaseView()
{

    if (m_style == CLOCK_ANALOG || m_style == CLOCK_ANALOG2)
    {
        if (m_type == CLOCK_LOCAL)
        {
            VFX_OBJ_CLOSE(m_textCity);
            VFX_OBJ_CLOSE(m_aclock);  
        }
        else if(m_type == CLOCK_ECDEMIC)
        {
            VFX_OBJ_CLOSE(m_textCity_ecdemic);   
            VFX_OBJ_CLOSE(m_aclock_ecdemic);  
        }
        else if(m_type == CLOCK_DUAL)
        {
            VFX_OBJ_CLOSE(m_bg);
            VFX_OBJ_CLOSE(m_textCity);
            VFX_OBJ_CLOSE(m_textCity_ecdemic);   
            VFX_OBJ_CLOSE(m_aclock);  
            VFX_OBJ_CLOSE(m_aclock_ecdemic);  
        }
        else
        {
            ASSERT(0);
        }
    }
    else if (m_style == CLOCK_DIGITAL)
    {

        if (m_type == CLOCK_LOCAL)
        {
            VFX_OBJ_CLOSE(m_textCity);
            VFX_OBJ_CLOSE(m_dclock);
            //VFX_OBJ_CLOSE(m_image_bg); 
        }
        else if (m_type == CLOCK_ECDEMIC)
        {
            VFX_OBJ_CLOSE(m_textCity_ecdemic); 
            VFX_OBJ_CLOSE(m_dclock_ecdemic);  
            //VFX_OBJ_CLOSE(m_image_bg);           
        }
        else if (m_type == CLOCK_DUAL)
        {
            VFX_OBJ_CLOSE(m_bg);
            VFX_OBJ_CLOSE(m_textCity);
            VFX_OBJ_CLOSE(m_textCity_ecdemic);   
            VFX_OBJ_CLOSE(m_dclock);
            //VFX_OBJ_CLOSE(m_image_bg); 
            VFX_OBJ_CLOSE(m_dclock_ecdemic);  
        }
        else
        {
            ASSERT(0);
        }
    }
    else
    {
        ASSERT(0);
    }
}


VfxBool VappHsWidgetClock::onContainPoint(const VfxPoint &point) const
{
    if (m_style == CLOCK_ANALOG || m_style == CLOCK_ANALOG2)
    {   
		return VappHsWidget::onContainPoint(point);
    }
    else if (m_style == CLOCK_DIGITAL)
    {
        return VappHsWidget::onContainPoint(point);
    }
    else
    {
        ASSERT(0);
    }

    return 0;
}


VfxU16 VappHsWidgetClock::getIcon(void) 
{ 
    m_style = vadp_v2p_hs_clock_get_style();
    m_type = vadp_v2p_hs_clock_get_type();

    /*if (m_type == CLOCK_DUAL)
    {
        if (m_style == CLOCK_ANALOG)
        {    
            return VAPP_HS_IMG_WG_ICON_CLOCK_ANALOG; 
        }
        else if (m_style == CLOCK_ANALOG2)
        {    
            return VAPP_HS_IMG_WG_ICON_CLOCK_ANALOG2; 
        }        
        else if (m_style == CLOCK_DIGITAL)
        {
            return VAPP_HS_IMG_WG_ICON_CLOCK_DIGITAL;
        }
        else
        {
            ASSERT(0);
        }
    }
    else*/
    {
        return 0;
    }


    return 0;
}


VfxU16 VappHsWidgetClock::getName(void) 
{
    return VAPP_HS_STR_WG_CLOCK;
}
#endif /* __MMI_VUI_HOMESCREEN_CLOCK__ */

