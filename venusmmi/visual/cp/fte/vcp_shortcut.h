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
 *  vcp_shortcut.h
 *
 * Project:
 * --------
 *  Venus UI Component
 *
 * Description:
 * ------------
 *  Basic class to handle shortcut
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCP_SHORTCUT_H__
#define __VCP_SHORTCUT_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"

#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vfx_timer.h"
#include "vfx_cpp_base.h"
#include "vfx_signal.h"
#include "vfx_input_event.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VCP_SHORTCUT_MAX_INPUT_LENGTH   2
/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/*****************************************************************************
 * Class VcpImageFlow
 *****************************************************************************/

/*
 * VcpSimpleMatrixIcon is a class which provided basic operation of matrix item.
 *
 * EXAMPLE
 * <code>
 *  VFRM_OBJ_CREATE(m_shortcut, VcpShortcut, NULL);
 * </code>
 */
class VcpShortcut : public VfxControl
{
//variable
private:
    // The maximized number 
    VfxS32                  m_count;
    // The input number buffer
    VfxS32                  M_inputBuf[VCP_SHORTCUT_MAX_INPUT_LENGTH];
    // The timer for input
    VfxTimer                *m_inputTimer;
    VfxBool                 m_isFull;

// Constructor / Destructor
public:
    // Default constructor.
    VcpShortcut();  

// Signal
public:
    // To handle key input.
    VfxSignal1 <VfxS32> m_input;
    // To stop drag & move mode.
    VfxSignal0  m_keydown;

// Method  
protected:
    // Key input function
    virtual VfxBool onKeyInput(
        VfxKeyEvent &event  //[IN] Key event
        );
    // The call back function of Input 
    void onInputTimerTick(
        VfxTimer *source    //[IN] Timer source
        );

// Override
protected:
    // Init function.
    virtual void onInit();
    // Deinit function.
    virtual void onDeinit();

};


#endif /* __VCP_SHORTCUT_H__ */
