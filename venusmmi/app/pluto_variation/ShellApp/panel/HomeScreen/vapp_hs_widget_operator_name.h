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
 *  vapp_hs_widget_operator_name.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: operator name
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_HS_WIDGET_OPERATOR_NAME_H__
#define __VAPP_HS_WIDGET_OPERATOR_NAME_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_OPERATOR_NAME__

/***************************************************************************** 
 * Include
 *****************************************************************************/
 
#include "vapp_hs_widget_base.h"
#include "vfx_control.h"
#include "vfx_string.h"
#include "vfx_datatype.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"
#include "vfx_text_frame.h"
#include "vfx_animation.h"
#include "vrt_datatype.h"
#include "vfx_cpp_base.h"
#include "vapp_hs_widget_cfg.h"
#include "vapp_hs_def.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vdat_network_info.h"


/***************************************************************************** 
 * Network info class
 *****************************************************************************/

class VappHsNetworkInfo : public VfxControl
{
// Declaration
private:
    // Constant
    enum
    {
        DISPLAY_TIME    = 5000,     // Display time
        SLIDING_TIME    = 500,      // Transition time
        TOTAL_TIME      = 11000     // Total time = (DISPLAY_TIME + SLIDING_TIME) * 2 
    };

// Constructor / Destructor
public:
    // Default constructor
    VappHsNetworkInfo();

// Method
public:
    // Set network name string
    void setNetname(
        const VfxWString &str       // [IN] string
    );

    // Set network status string
    void setNetstat(
        const VfxWString &str       // [IN] string
    );

    // Get the network name string
    const VfxWChar *getNetname();

    // Get the network status string
    const VfxWChar *getNetstat();

private:
    // On bounds value change
    void onBoundsValueChange(
        VfxFrame *source,
        const VfxRect &oldBounds
    );

    // Center align string
    void centerAlignment(
        VfxTextFrame *text          // [IN] text frame
    );

    // Display network info:
    //  Show both strings of network info.
    //  If both strings are set, enable scrolling animation, otherwise, disable animation.
    void show();

// Override
protected:
    // On init
    virtual void onInit();

private:
    // Network name string
    VfxTextFrame        *m_netname;

    // Network status string
    VfxTextFrame        *m_netstat;

    // Transition animation
    VfxAnimation        *m_animScroll;

    // Timeline of position transition
    VfxS32Timeline      *m_tlPos[2][2];

    // Timeline of opacity transition
    VfxFloatTimeline    *m_tlOpa[2][2];

    // Font
    static const vrt_font_struct s_font;
};


/***************************************************************************** 
 * Home screen widget: recent event
 *****************************************************************************/

class VappHsWidgetOperatorName : public VappHsWidget
{
    VAPP_HS_WIDGET_CREATE(VappHsWidgetOperatorName);

// Constructor / Destructor    
public:
    // Default constructor.
    VappHsWidgetOperatorName();

// Override
public:
    virtual VfxU16 getIcon();
    virtual VfxU16 getName();
    virtual void onCreateView();
    virtual void onReleaseView();

// Declaration
private:
    enum
    {
        INFO_HEIGHT = 23,
    #if (MMI_MAX_SIM_NUM == 2)
        INFO_Y      = 28,
        INFO_Y1     = 16,
        INFO_Y2     = 42,
    #else /* (MMI_MAX_SIM_NUM == 2) */
        INFO_Y      = 20,
    #endif /* (MMI_MAX_SIM_NUM == 2) */
        GAP_X       = 14
    };

// Variable
private:
#if (MMI_MAX_SIM_NUM == 2)
    // Network information (SIM 2)
    VappHsNetworkInfo               *m_ni2;
#endif /* (MMI_MAX_SIM_NUM == 2) */

    // Network information (SIM 1)
    VappHsNetworkInfo               *m_ni;

// Implementation
private:
    // This function is the event handler when the idle line 1 of the SIM 1 is
    // changed.
    void onNetworkNameChanged(VdatNetworkInfo *networkSrv);

    // This function is the event handler when the idle line 2 of the SIM 1 is
    // changed.
    void onNetworkStatusChanged(VdatNetworkInfo *networkSrv);

#if (MMI_MAX_SIM_NUM == 2)
    // This function is the event handler when the idle line 1 of the SIM 2 is
    // changed.
    void onNetworkNameChanged2(VdatNetworkInfo *networkSrv);

    // This function is the event handler when the idle line 2 of the SIM 2 is
    // changed.
    void onNetworkStatusChanged2(VdatNetworkInfo *networkSrv);
#endif /* (MMI_MAX_SIM_NUM == 2) */

    // This function arranges the position for the dual SIM operator name.
    void arrangePosition();
};

#endif /* __MMI_VUI_HOMESCREEN_OPERATOR_NAME__ */
#endif /* __VAPP_HS_WIDGET_OPERATOR_NAME_H__ */

