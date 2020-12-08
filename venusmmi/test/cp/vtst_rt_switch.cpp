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
 *  vtst_rt_switch.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for VcpSwitch
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
#include "vcp_switch.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_basic_type.h"
#include "vfx_signal.h"
#include "vfx_text_frame.h"
#include "vrt_datatype.h"
#include "vfx_string.h"
#include "vfx_datatype.h"
#include "vfx_app_cat_scr.h"

/***************************************************************************** 
 * Control Test Implementation
 *****************************************************************************/

class VtstRtSwitch : public VtstRtScr
{
// Variable
public:

// Constructor / Destructor
public:
    VtstRtSwitch()
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setBgColor(VFX_COLOR_WHITE);

        VcpSwitch *sw;

        VFX_OBJ_CREATE(sw, VcpSwitch, this);
        sw->setPos(VfxPoint(50, 50));
        sw->m_signalSwitchChanged.connect(this, &VtstRtSwitch::testSwitchSignal);
        sw->setChecked(VFX_TRUE);
        
        VcpSwitch *sw2;
        VFX_OBJ_CREATE(sw2, VcpSwitch, this);
        sw2->setPos(VfxPoint(50, 50 + sw->getSize().height * 3 / 2) );
        sw2->setChecked(VFX_FALSE);

        VFX_OBJ_CREATE(m_switchState, VfxTextFrame, this);
        m_switchState->setPos(VfxPoint(50, 20));
        m_switchState->setBgColor(VFX_COLOR_WHITE);
        m_switchState->setColor(VFX_COLOR_BLACK); 
        
        testSwitchSignal(sw, sw->getChecked());

        check(sw->getChecked() == VFX_TRUE, VFX_WSTR("INITIAL SET FALSE"));

        // return 0;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        setTitle(VFX_WSTR("Switch Test"));
        confirm(VFX_WSTR("Result is correct?"));
        
        return -1;
    }

    virtual VfxS32 start() {return 1;}

private:
    void testSwitchSignal(VcpSwitch *sw, VfxBool isChecked)
    {
        m_switchState->setString(isChecked ? VFX_WSTR("ON") : VFX_WSTR("OFF"));    
    }

    VfxTextFrame *m_switchState;
};


VtstTestResultEnum vtst_rt_switch(VfxU32 param)
{
    VTST_START_SCRN(VtstRtSwitch);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

