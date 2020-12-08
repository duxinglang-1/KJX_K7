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
 *  vtst_rt_marquee.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for VcpMarquee
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vtst_rt_main.h"
#include "vcp_marquee.h"
#include "vfx_string.h"
#include "vfx_datatype.h"
#include "vfx_basic_type.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_signal.h"
#include "vfx_font_desc.h"
#include "vrt_datatype.h"
#include "vfx_app_cat_scr.h"


/***************************************************************************** 
 * Marquee Test Implementation
 *****************************************************************************/

class VtstRtMarquee : public VtstRtScr
{
    
// Constructor / Destructor
public:
    VtstRtMarquee()
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        
        setTitle(VFX_WSTR("Marquee Test"));

        VcpMarquee *m1, *m2, *m3, *m4, *m5, *m6, *m7;
        VfxPoint pos(20, 50);

        // Marquee 1
        VFX_OBJ_CREATE(m1, VcpMarquee, this);        
        m1->setRect(VfxRect(pos.x, pos.y, 200, 20));
        m1->setStartDelay(3000);
        m1->setLoop(1);
        m1->setMovableFrame(VFX_WSTR("Start delay 3 sec. Natural align. 1 Loop."));        
        m1->startScroll();

        // Marquee 2
        pos.y += m1->getBounds().getHeight() + 5;

        VFX_OBJ_CREATE(m2, VcpMarquee, this);        
        m2->setRect(VfxRect(pos.x, pos.y, 200, 15));
        m2->setMovableFrame(VFX_WSTR("Aligned Left-Top. 2 Loops. Smaller."));
        m2->setHalign(VcpMarquee::HALIGN_LEFT);
        m2->setValign(VcpMarquee::VALIGN_TOP);
        m2->setLoop(2);
        m2->setBorderWidth(1);
        m2->startScroll();

        // Marquee 3
        pos.y += m2->getBounds().getHeight() + 5;

        VFX_OBJ_CREATE(m3, VcpMarquee, this);        
        m3->setRect(VfxRect(pos.x, pos.y, 20, 20));
        m3->setMovableFrame(VFX_WSTR("Aligned Center-Center. Faster. 3 Loops. (aligned Left actually) "));
        m3->setHalign(VcpMarquee::HALIGN_CENTER);
        m3->setValign(VcpMarquee::VALIGN_CENTER);
        m3->setSpeed(VcpMarquee::DEFAULT_SPEED * 3);
        m3->setBorderWidth(1);
        m3->setLoop(3);
        m3->startScroll();
        // Test change bounds after startScroll
        m3->setBounds(VfxRect(0, 0, 200, 40));

        // Marquee 4
        pos.y += m3->getBounds().getHeight() + 5;

        // TODO: now we have a bug that the text position is not properly restored after scrolling finished 
        VFX_OBJ_CREATE(m4, VcpMarquee, this);
        m4->setRect(VfxRect(pos.x, pos.y, 200, 20)); 
        m4->setMovableFrame(VFX_WSTR("Aligned Right-Bottom. Direction Right. 4 Loops. Hide on stopped. "));
        m4->setHalign(VcpMarquee::HALIGN_RIGHT);
        m4->setValign(VcpMarquee::VALIGN_BOTTOM);
        m4->setDirection(VcpMarquee::DIRECTION_RIGHT);    
        m4->setSpeed(VcpMarquee::DEFAULT_SPEED * 4);
        m4->setLoop(4);
        m4->setBorderWidth(1);
        m4->m_signalScrollFinished.connect(m4, &VtstRtMarquee::onUnitTestBecomeHidden);
        m4->startScroll();
        
        // Marquee 5
        pos.y += m4->getBounds().getHeight() + 5;

        VFX_OBJ_CREATE(m5, VcpMarquee, this);        
        m5->setRect(VfxRect(pos.x, pos.y, 150, 20));
        m5->setMovableFrame(VFX_WSTR("Normal Mode. Infinite Loop. "));
        m5->setBorderWidth(1);
        m5->startScroll();

        // Marquee 6
        pos.y += m5->getBounds().getHeight() + 5;

        VFX_OBJ_CREATE(m6, VcpMarquee, this);        
        m6->setRect(VfxRect(pos.x, pos.y, 150, 20));
        m6->setMovableFrame(VFX_WSTR("Slide Mode. 1 Loop. "));
        m6->setScrollMode(VcpMarquee::SCROLL_MODE_SLIDE); 
        m6->setBorderWidth(1);
        m6->setLoop(1);
        m6->startScroll();

        // Marquee 7
        pos.y += m5->getBounds().getHeight() + 5;

        VFX_OBJ_CREATE(m7, VcpMarquee, this);        
        m7->setRect(VfxRect(pos.x, pos.y, 150, 20));
        m7->setMovableFrame(
            VFX_WSTR("Red, Border. Alternate Mode. Infinite Loop. "), 
            VfxFontDesc(VFX_FONT_DESC_SIZE_MEDIUM, VFX_FONT_DESC_EFFECT_BORDER));
        m7->setTextColor(VFX_COLOR_RED, VFX_COLOR_BLACK);
        m7->setScrollMode(VcpMarquee::SCROLL_MODE_ALTERNATE); 
        m7->setBorderWidth(1);
        m7->setLoop(0);
        m7->startScroll();
    }

    virtual int start()
    {      
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Does it work?"));
        return -1;
    }

    void onUnitTestBecomeHidden(VcpMarquee *target)
    {
        target->setHidden(VFX_TRUE);
    }
};


VtstTestResultEnum vtst_rt_marquee(VfxU32 param)
{
    VTST_START_SCRN(VtstRtMarquee);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

