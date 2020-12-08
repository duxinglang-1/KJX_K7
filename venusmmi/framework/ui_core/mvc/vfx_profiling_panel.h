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
 *  vfx_profiling_panel.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  The frm profiling panel of Venus UI engine
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VFX_PROFILING_PANEL_H__
#define __VFX_PROFILING_PANEL_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_text_frame.h"

class VfxTimer;


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Class VfxProfilingPanel
 *****************************************************************************/

/*
 * Internal used. FRM_Profiling panel in engineering mode.
 */
class VfxProfilingPanel : public VfxTextFrame
{
// Define
public:

    enum DisplayPlace
    {
        DISPLAY_PLACE_TOP = 0,
        DISPLAY_PLACE_BOTTOM,
        DISPLAY_PLACE_END_OF_ENUM
    };

// Constructor / Destructor
public:
    // Default constructor
    VfxProfilingPanel();

    // Default destructor
    virtual ~VfxProfilingPanel();

// Method
public:
    void registerProfilingCallback();
    void unregisterProfilingCallback();

    // set the position of display the profiling panel
    void setDisplayPlace(
        DisplayPlace placement
    );

    // get the position of display the profiling panel
    DisplayPlace getDisplayPlace() const
    {
        return m_placement;
    }

    // set auto-hidding timeout of the profiling panel
    void setAutoHideTimeout(
        VfxMsec timeout
    );

    // get auto-hidding timeout of the profiling panel
    VfxMsec getAutoHideTimeout() const
    {
        return m_autohideTimeout;
    }

    // reset auto-hidding timer
    void resetAutoHide();

// Override
protected:
    virtual void onInit();

// Implementation
private:
    DisplayPlace m_placement;
    VfxMsec m_autohideTimeout;
    VfxTimer *m_autohideTimer;

    void onAutoHide(VfxTimer *timer);

    //static VfxProfilingPanel *s_curProfilingPanel;
    static void profilingCallback(U8 *str, void *user_data);
};

#endif /* __VFX_PROFILING_PANEL_H__ */

