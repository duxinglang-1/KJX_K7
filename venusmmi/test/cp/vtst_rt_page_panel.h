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
 *  vtst_rt_page_panel.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Description 
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
#ifndef __VTST_RT_PAGE_PANEL_H__
#define __VTST_RT_PAGE_PANEL_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vcp_button.h"
#include "vtst_rt_main.h"
#include "vcp_page_panel.h"
#include "vcp_frame_effect.h"
#include "vcp_list_menu.h"
#include "vfx_control.h"
#include "vfx_frame.h"
#include "vfx_text_frame.h"
#include "vfx_animation.h"
#include "vfx_cpp_base.h"
#include "vfx_input_event.h"
#include "vfx_datatype.h"
#include "vfx_string.h"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

class VtstRtPagePanel : public VtstRtScr, public IVcpListMenuContentProvider
{
public:
    /*
     * Child objects
     */
    VcpPagePanel *m_page;
    VfxControl *m_control1;
    VfxControl *m_control2;
    VfxFrame   *m_frame1;
    VfxFrame   *m_frame2;
    VfxFrame   *m_frame3;
    VfxFrame   *m_test;
    VfxTextFrame *m_controlText;
    VfxPointTimeline *m_pointTimeline[2];
    VfxFrame *m_targetFrame;

    VcpFrameEffect *m_frameEffect;

    VcpPageEffectType  m_transitionType;

    VcpButton        *m_rotateButton;
    VcpButton        *m_changeIconButton;
    VcpButton        *m_changeButtonButton;
    VcpButton        *m_showButton;
    VcpListMenu      *m_list;

public:
    /*
     * Constructor / Destructor
     */
    VtstRtPagePanel();

protected:
    /*
     * Virtual functions
     */
    virtual void onInit();
    virtual VfxBool onKeyInput(VfxKeyEvent &event);

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    { 
        VFX_UNUSED(idx);
        confirm(VFX_WSTR("Result is correct?"));
        return -1;
    }

    void onButtonClick(VfxObject* sender, VfxId id);

    void onItemSelected(VcpListMenu *sender, VfxU32 index);
    void updateText();

public:
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color);
    virtual VfxU32 getCount() const {return VCP_PAGE_EFFECT_END - 1; }

};

VtstTestResultEnum vtst_rt_page_panel(VfxU32 param);

#endif /* __VFX_RT_TEST__ */

#endif /* __VTST_RT_PAGE_PANEL_H__ */

