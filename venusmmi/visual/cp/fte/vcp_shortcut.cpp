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
 *  vcp_shortcut.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Internal UI componets of home screen application category
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vcp_shortcut.h"
#include "stdlib.h"

#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_input_event.h"
#include "vfx_keypad.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_timer.h"
#include "vfx_signal.h"


#define VCP_SHORTCUT_INVALID_VALUE              -1
#define VCP_SHORTCUT_INTERVAL                   600
/***************************************************************************** 
 * Global Function
 *****************************************************************************/
VcpShortcut::VcpShortcut():
m_inputTimer(NULL)
{
}

void VcpShortcut::onInit()
{
    
    VfxControl::onInit();
    
    for (VfxS32 i = 0; i <VCP_SHORTCUT_MAX_INPUT_LENGTH; i++)
    {
        M_inputBuf[i] = VCP_SHORTCUT_INVALID_VALUE;
    }
    m_count = 0;
    m_isFull = VFX_FALSE;
    VfxKeypad::registerHandler(VFX_KEY_CODE_SPECIAL_ALL_ARROW, this);
}


void VcpShortcut::onDeinit()
{
       
    VfxControl::onDeinit();
}


VfxBool VcpShortcut::onKeyInput(VfxKeyEvent &event)
{
    //switch (event.keyCode)
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        VfxS32 num;

        num = event.keyCode - VFX_KEY_CODE_0;

        m_keydown.emit();

        //if (M_inputBuf[0] == VCP_SHORTCUT_INVALID_VALUE && num == 0)
          //  return VFX_TRUE;
        
        if (M_inputBuf[VCP_SHORTCUT_MAX_INPUT_LENGTH - 1] != VCP_SHORTCUT_INVALID_VALUE)
        {
            m_isFull = VFX_TRUE;
        }
        for (VfxS32 i = 0; i <VCP_SHORTCUT_MAX_INPUT_LENGTH; i++)
        {
            if (M_inputBuf[i] == VCP_SHORTCUT_INVALID_VALUE)
            {
                if (!((M_inputBuf[0] == VCP_SHORTCUT_INVALID_VALUE && num == 0) || num > 9 || num < 0))
                {
                    M_inputBuf[i] = num;
                }
                if (m_inputTimer)
                {
                    m_inputTimer->stop();
                    VFX_OBJ_CLOSE(m_inputTimer);
                }
                VFX_OBJ_CREATE(m_inputTimer, VfxTimer, this);
                m_inputTimer->setDuration(0);
                m_inputTimer->setStartDelay(VCP_SHORTCUT_INTERVAL);
                m_inputTimer->m_signalTick.connect(this, &VcpShortcut::onInputTimerTick);
                m_inputTimer->start();
                break;
            }
        }
    }

    return VFX_FALSE;
}

void VcpShortcut::onInputTimerTick(VfxTimer *source)
{
    VfxS32 num = 0;

    VFX_UNUSED(source);

    for (VfxS32 i = 0; i <= VCP_SHORTCUT_MAX_INPUT_LENGTH - 1; i++)
    {
        if (M_inputBuf[i] != VCP_SHORTCUT_INVALID_VALUE)
        {
            num = num * 10;
            num += M_inputBuf[i];
            M_inputBuf[i] = VCP_SHORTCUT_INVALID_VALUE;
        }
    }
    if (m_isFull == VFX_FALSE)
    {
        m_input.emit(num - 1);
    }
    
    m_isFull = VFX_FALSE;
}
