/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 *  vcp_idle_calendar.h
 *
 * Project:
 * --------
 *  Venus UI Components
 *
 * Description:
 * ------------
 *  Idle calendar adaptor to Pluto UI component
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_IDLE_CALENDAR_H__
#define __VCP_IDLE_CALENDAR_H__

#ifndef __cplusplus
#error "This header file can be used in C++ only."
#endif

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_pluto_control.h"

#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_signal.h"
#include "vfx_basic_type.h"
#include "vfx_cpp_base.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Class VcpIdleCalendar
 *****************************************************************************/

/*
 * VcpIdleCalendar is a class which is used to display calendar in idle screen.
 *
 * EXAMPLE
 * <code>
 *  VcpIdleCalendar *calendar = new VcpIdleCalendar();
 * </code>
 */
class VcpIdleCalendar : public VcpPlutoControl
{
    VFX_DECLARE_CLASS(VcpIdleCalendar);

// Constructor/Destructor
public:
    // <group DOM_IdleCalendar_VcpIdleCalendar_Constructor/Destructor>
    // Default constructor.
    VcpIdleCalendar();

// Signal
public:    
    // <group DOM_IdleCalendar_VcpIdleCalendar_Signal>
    // Signal when the idle calendar udate a new day
    VfxSignal0 m_signalUpdate;

// Override
protected:
    // <group DOM_IdleCalendar_VcpIdleCalendar_Override>
    virtual void onPlutoCreate();
    // <group DOM_IdleCalendar_VcpIdleCalendar_Override>
    virtual void onPlutoClose();
    
    // <group DOM_IdleCalendar_VcpIdleCalendar_Override>
    virtual void onPlutoDraw();
    // <group DOM_IdleCalendar_VcpIdleCalendar_Override>
    virtual VfxSize onPlutoGetPreferredSize();
    // <group DOM_IdleCalendar_VcpIdleCalendar_Override>
    virtual VfxBool onPlutoNeedAlphaChannel(); 
    // <group DOM_IdleCalendar_VcpIdleCalendar_Override>
    virtual VfxBool onPlutoNeedDoubleBuffer() {return VFX_TRUE;}

// Method
protected:
    // <group DOM_IdleCalendar_VcpIdleCalendar_Method>
    // Utility function used to update calendar.
    static void updateCalendarForPluto(
        void *object    // the calendar pointer to be refreshed
    );

// Implementation
private:
    // <group DOM_IdleCalendar_VcpIdleCalendar_Implementation>
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        // Is the default width of idle calendar.
        WIDTH  = 182,
        // Is the default height of idle calendar.
        HEIGHT = 154
    #else
        #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
            // Is the default width of idle calendar.
            WIDTH  = 170,
            // Is the default height of idle calendar.
            HEIGHT = 63
        #else
            // Is the default width of idle calendar.
            WIDTH  = 156,
            // Is the default height of idle calendar.
            HEIGHT = 133
        #endif
    #endif
    } PreferredSizeEnum;
};

#endif /* __VCP_IDLE_CALENDAR_H__ */
