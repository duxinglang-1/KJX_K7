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
 *  vtst_rt_command_title.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Description
 *      Screens for command title cp testing
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_config.h"

#if defined(__AFX_RT_TEST__)
#include "vtst_rt_main.h"

#include "vfx_datatype.h"
#include "vcp_command_title.h"
#include "vcp_button.h"
#include "vfx_object.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_string.h"
#include "vfx_signal.h"
#include "GlobalResDef.h"
#include "vcp_state_image.h"
#include "vfx_app_cat_scr.h"

/***************************************************************************** 
 * Class VtstRtCommandTitleScr
 *****************************************************************************/
class VtstRtCommandTitleScr : public VtstRtScr
{
// Constructor / Destructor
public:
    VtstRtCommandTitleScr() {}

// Override
protected:
    virtual void onInit();

    virtual VfxS32 start() {return 1;}

    virtual VfxS32 phase(VfxS32 idx);

// Implementation
private:
    VcpCommandTitle *m_title;    
    VcpButton* m_button1;
    VcpButton* m_button2;

    void buttonClick(VfxObject* sender, VfxId id);
    void buttonClick2(VfxObject* sender, VfxId id);
};


void VtstRtCommandTitleScr::onInit()
{
    VtstRtScr::onInit();
    setBgColor(VFX_COLOR_BLUE);

    VFX_OBJ_CREATE(m_title, VcpCommandTitle, this);
    m_title->setAnchor(VfxFPoint(0.5, 0.0));
    m_title->setPos(VfxPoint(120, 30));
    m_title->setText(VFX_WSTR("Title"));
    m_title->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_button1, VcpButton, this);
    m_button1->setText(VFX_WSTR("Options"));
    m_button1->setIsAutoResized(VFX_TRUE);
    m_button1->m_signalClicked.connect(this, &VtstRtCommandTitleScr::buttonClick);
    m_button1->setAutoAnimate(VFX_TRUE);
    m_title->setAddOnFrame(0, m_button1);

    VFX_OBJ_CREATE(m_button2, VcpButton, this);
    m_button2->setText(VFX_WSTR("Done"));
    m_button2->m_signalClicked.connect(this, &VtstRtCommandTitleScr::buttonClick);
    m_button2->setAutoAnimate(VFX_TRUE);
    m_title->setAddOnFrame(1, m_button2);
    

    VcpCommandTitle *title;
    VFX_OBJ_CREATE(title, VcpCommandTitle, this);
    title->setAnchor(VfxFPoint(0.5, 0.0));
    title->setPos(VfxPoint(120, 80));
    title->setText(VFX_WSTR("abcdefghijklmnopqrstuvwxyz"));
    title->setAddOnTextButton(0, VFX_WSTR("+"), 0, VcpCommandTitleButtonCB(this, &VtstRtCommandTitleScr::buttonClick2));
    title->setAddOnTextButton(1, VFX_WSTR("-"), 1, VcpCommandTitleButtonCB(this, &VtstRtCommandTitleScr::buttonClick2));
    title->setAutoAnimate(VFX_TRUE);

    VcpCommandTitle *title2;
    VFX_OBJ_CREATE(title2, VcpCommandTitle, this);
    title2->setAnchor(VfxFPoint(0.5, 0.0));
    title2->setPos(VfxPoint(120, 130));
    title2->setText(VFX_WSTR("title"));
    title2->setAddOnImageButton(0, VcpStateImage(IMG_GLOBAL_L1), 0, VcpCommandTitleButtonCB(this, &VtstRtCommandTitleScr::buttonClick2));
    title2->setAddOnImageButton(1, VcpStateImage(IMG_GLOBAL_L2), 1, VcpCommandTitleButtonCB(this, &VtstRtCommandTitleScr::buttonClick2));
    title2->setAutoAnimate(VFX_TRUE);
}


void VtstRtCommandTitleScr::buttonClick(VfxObject* sender, VfxId id)
{
    VcpButton* button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);
    VfxSize size = m_title->getSize();

    if (button == m_button1)
    {
        size.width += 10;
    }

    if (button == m_button2)
    {
        size.width -= 10;
    }

    m_title->setSize(size);
}


void VtstRtCommandTitleScr::buttonClick2(VfxObject* sender, VfxId id)
{
    VcpCommandTitle* title = VFX_OBJ_DYNAMIC_CAST(sender, VcpCommandTitle);
    VfxSize size = title->getSize();

    if (id == 0)
    {
        size.width += 10;
    }

    if (id == 1)
    {
        size.width -= 10;
    }

    title->setSize(size);
}


VfxS32 VtstRtCommandTitleScr::phase(VfxS32 idx)
{
    setTitle(VFX_WSTR("Command Title"));
    confirm(VFX_WSTR("Result is correct?"));
    return -1;
}


VtstTestResultEnum vtst_rt_command_title(VfxU32 param)
{
    VTST_START_SCRN(VtstRtCommandTitleScr);
    return VTST_TR_OK;
}

#endif /* __AFX_RT_TEST__ */
