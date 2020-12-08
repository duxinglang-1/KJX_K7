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
 *  vtst_rt_waiting_icon.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for VcpWaitingIcon
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vtst_rt_main.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vcp_waiting_icon.h"
#include "vfx_input_event.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_app_cat_scr.h"

/***************************************************************************** 
 * VtstWaitingIcon Test Implementation
 *****************************************************************************/
class VtstRtWaitingIcon : public VtstRtScr
{
// Variable
public:

// Constructor / Destructor
public:
    VtstRtWaitingIcon() {}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        VFX_OBJ_CREATE(m_icon1, VcpWaitingIcon, this);
        m_icon1->setPos(100, 100);
        m_icon1->start();

        VFX_OBJ_CREATE(m_icon2, VcpWaitingIcon, this);
        m_icon2->setPos(160, 200);
        m_icon2->setSize(100, 100);
        m_icon2->start();

        VFX_OBJ_CREATE(m_icon3, VcpWaitingIcon, this);
        m_icon3->setPos(100, 300);
        m_icon3->setSize(100, 30);
        m_icon3->setHiddenWhenStopped(VFX_FALSE);
        m_icon3->start();        
    }

    virtual VfxBool onPenInput(VfxPenEvent &event)
    {
        if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
        {
            return VFX_TRUE;
        }
        else if (event.type == VFX_PEN_EVENT_TYPE_UP)
        {
            if (m_icon1->isAnimating())
            {
                m_icon1->stop();
            }
            else if (m_icon2->isAnimating())
            {
                m_icon2->stop();
            }
            else if (m_icon3->isAnimating())
            {
                m_icon3->stop();                
            }

            return VFX_TRUE;
        }
    
        return VFX_FALSE;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        VFX_UNUSED(idx);
        
        setTitle(VFX_WSTR("Waiting Icon Test"));
        confirm(VFX_WSTR("PEN UP THREE TIMES. Result is correct?"));
        
        return -1;
    }

    virtual VfxS32 start() {return 1;}

// Variable
private:
    VcpWaitingIcon *m_icon1, *m_icon2, *m_icon3;
};


VtstTestResultEnum vtst_rt_waiting_icon(VfxU32 param)
{
    VFX_UNUSED(param);

    VTST_START_SCRN(VtstRtWaitingIcon);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

