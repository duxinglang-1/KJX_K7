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
 *  vapp_hs_widget_clock.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: multi clock
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_HS_WIDGET_CLOCK_H__
#define __VAPP_HS_WIDGET_CLOCK_H__

#include "MMI_features.h"
#ifdef __MMI_VUI_HOMESCREEN_CLOCK__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_hs_widget_base.h"
#include "vcp_clock.h"
#include "HomeScreen\vadp_v2p_hs_widget_dualclock.h"
#include "vfx_cpp_base.h"
#include "vapp_hs_widget_cfg.h"
#include "vapp_hs_def.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_datatype.h"
#include "vfx_basic_type.h"
#include "vfx_primitive_frame.h"
#include "vfx_text_frame.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef
 *****************************************************************************/



/***************************************************************************** 
 * Home screen widget: analog clock
 *****************************************************************************/
class VappHsWidgetClock : public VappHsWidget
{
    VAPP_HS_WIDGET_CREATE(VappHsWidgetClock);

// Constructor / Destructor
public:
    // Default constructor
    VappHsWidgetClock();

// Method
public:
    // get the image ID of widget bar icon
    // RETURNS: image ID
    virtual VfxU16 getIcon();

    // Get string resource ID for the name of this widget
    // RETURNS: string ID
    virtual VfxU16 getName();
    
#if 1
    // create widget bar icon frame, m_controlIcon
    virtual VfxBool onCreateIconView();

    // release widget bar icon frame
    virtual void onReleaseIconView();
#endif

    // create the whole widget content
    virtual void onCreateView();

    // release the whole widget content
    virtual void onReleaseView();

protected:
    // get the image ID of widget bar icon
    // RETURNS: VfxBool
    virtual VfxBool onContainPoint(
        const VfxPoint &point   // [IN] point
    ) const;

// Override
    // Launch setting
    virtual void onDirectLaunch() {vadp_v2p_hs_clock_entry_setting();}

private:
    // The type of clock
    enum
    {
        CLOCK_LOCAL = 0,      
        CLOCK_ECDEMIC,      
        CLOCK_DUAL
    };

    // The style of clock
    enum
    {
        CLOCK_ANALOG = 0,      
        CLOCK_ANALOG2,
        CLOCK_DIGITAL
    };    
    
    // Constant
    enum
    {
        GAP_CLOCK_TEXT              = 10,   // Gap between Clock and Text
        GAP_DUAL_BORDER             = 8,    // Gap between BG and Clock in dual mode
        GAP_DUAL_DIGITAL_NORMAL     = 2,    // Gap between numbers
        GAP_DUAL_DIGITAL_SEPARATOR  = 1,    // Gap between number and ':'
        GAP_DUAL_DIGITAL_AMPM       = 3,    // Gap between AMPM and number

        GAP_ICON_DIGITAL_NORMAL     = 1,    // Gap between numbers
        GAP_ICON_DIGITAL_SEPARATOR  = 0,    // Gap between number and ':'
        GAP_ICON_DIGITAL_AMPM       = 0,    // Gap between AMPM and number        

        GAP_ANALOG_BORDER           = 9,
        GAP_DUAL_ANALOG_CLOCK       = 3,

        ANALOG_CENTER               = 50,
        ANALOG_DUAL_CENTER          = 40,

        ANALOG2_CENTER_X            = 56,
        ANALOG2_CENTER_Y            = 54,
        ANALOG2_DUAL_CENTER_X       = 42,
        ANALOG2_DUAL_CENTER_Y       = 42,        

#if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)       
        WG_ICON_ANALOG_CENTER_X     = 24,
        WG_ICON_ANALOG_CENTER_Y     = 24,
        WG_ICON_ANALOG2_CENTER_X    = 25,
        WG_ICON_ANALOG2_CENTER_Y    = 26,
#elif defined(__MMI_MAINLCD_320X480__)
        WG_ICON_ANALOG_CENTER_X     = 29,
        WG_ICON_ANALOG_CENTER_Y     = 29,
        WG_ICON_ANALOG2_CENTER_X    = 29,
        WG_ICON_ANALOG2_CENTER_Y    = 28,
#else
        WG_ICON_ANALOG_CENTER_X     = 20,
        WG_ICON_ANALOG_CENTER_Y     = 20,
        WG_ICON_ANALOG2_CENTER_X    = 20,
        WG_ICON_ANALOG2_CENTER_Y    = 20, 
#endif /* LCD size */

        DUAL_BG_DIGITAL_Y           = 25,
        DUAL_BG_ANALOG_Y            = 52,
        DUAL_BG_ANALOG2_Y           = 62        
    };
    
    // clock
    VfxS8 m_type;
    VfxS8 m_style;
    
    VcpAnalogClock *m_aclock;
    VcpAnalogClock *m_aclock_ecdemic;
    VcpAnalogClock *m_icon_aclock;
    
    VcpDigitalImageClock *m_dclock;
    VcpDigitalImageClock *m_dclock_ecdemic;
    VcpDigitalImageClock *m_icon_dclock;
    
    // background image
    VfxImageFrame        *m_bg;


    // local city name text
    VfxTextFrame            *m_textCity;

    // foreign city name text
    VfxTextFrame            *m_textCity_ecdemic;
    
};



#endif /* __MMI_VUI_HOMESCREEN_CLOCK__ */
#endif /* __VAPP_HS_WIDGET_CLOCK_H__ */
