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
 *  vtst_rt_segment_button.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Description
 *      Screens for segment button cp testing
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
 #include "vcp_segment_button.h"
 #include "vfx_object.h"
 #include "vfx_cpp_base.h"
 #include "vfx_basic_type.h"
 #include "vrt_datatype.h"
 #include "vfx_top_level.h"
 #include "vfx_sys_memory.h"
 #include "GlobalResDef.h"
 #include "vfx_string.h"
 #include "vcp_state_image.h"
 #include "vfx_signal.h"
 #include "vfx_app_cat_scr.h"




/***************************************************************************** 
 * Class VtstRtSegmentButtonScr
 *****************************************************************************/
class VtstRtSegmentButtonScr : public VtstRtScr
{
// Constructor / Destructor
public:
    VtstRtSegmentButtonScr() {}

// Override
protected:
    virtual void onInit();

    virtual VfxS32 start() {return 1;}

    virtual VfxS32 phase(VfxS32 idx);

// Implementation
private:
    VcpSegmentButton *b1;
    VcpSegmentButton *b2;
    VcpSegmentButton *b3;
    VcpSegmentButton *b4;
    void onButtonClicked(VfxObject* sender, VfxId buttonId);
};


void VtstRtSegmentButtonScr::onButtonClicked(VfxObject* sender, VfxId buttonId)
{
    VfxBool test;

    if (sender == b2)
    {
        if (buttonId == 1)
        {
            test = b2->getButtonIsDisabled(0);
            b2->setButtonIsDisabled(0, !test);
        }
    }
}


void VtstRtSegmentButtonScr::onInit()
{
    VtstRtScr::onInit();
    setBgColor(VFX_COLOR_BLUE);

    VfxS32 x = VFX_OBJ_GET_INSTANCE(VfxTopLevel)->getSize().width / 2;
    VfxS32 y = 30;
    VFX_OBJ_CREATE(b1, VcpSegmentButton, this);
    b1->setAnchor(VfxFPoint(0.5f, 0.0f));
    b1->setWidth(100);
    b1->setPos(x, y);
    b1->addButton(0, VcpStateImage(IMG_GLOBAL_L1), VFX_WSTR("item 1"));
    y += b1->getSize().height + 30;

    VFX_OBJ_CREATE(b2, VcpSegmentButton, this);
    b2->setAnchor(VfxFPoint(0.5f, 0.0f));
    b2->setPos(x, y);
    b2->setWidth(100);
    b2->addButton(0, VcpStateImage(IMG_GLOBAL_L1), VFX_WSTR("item 1"));
    b2->addButton(1, VcpStateImage(IMG_GLOBAL_L2), VFX_WSTR("item 2"));
    b2->addButton(2, VcpStateImage(IMG_GLOBAL_L3), VFX_WSTR("item 3"));
    b2->removeButton(1);
    b2->addButton(1, VcpStateImage(IMG_GLOBAL_L2), VFX_WSTR("item 2"), 2);
    b2->setType(VCP_SEGMENT_BUTTON_TYPE_GROUP);
    y += b2->getSize().height + 30;

    VFX_OBJ_CREATE(b3, VcpSegmentButton, this);
    b3->setAnchor(VfxFPoint(0.5f, 0.0f));
    b3->setPos(x, y);
    b3->setWidth((getSize().width*3)/4);
    b3->addButton(0, VcpStateImage(IMG_GLOBAL_L1), VFX_WSTR("item 1"));
    b3->addButton(1, VcpStateImage(IMG_GLOBAL_L2), VFX_WSTR("item 2"));
    b3->addButton(2, VcpStateImage(IMG_GLOBAL_L3), VFX_WSTR("item 3"));
    b3->setType(VCP_SEGMENT_BUTTON_TYPE_RADIO);
    y += b3->getSize().height + 30;

    VFX_OBJ_CREATE(b4, VcpSegmentButton, this);
    b4->setAnchor(VfxFPoint(0.5f, 0.0f));
    b4->setPos(x, y);
    b4->setWidth(200);
    b4->addButton(0, VcpStateImage(IMG_GLOBAL_L1), VFX_WSTR("item 1"));
    b4->addButton(1, VcpStateImage(IMG_GLOBAL_L2), VFX_WSTR("item 2"));
    b4->setType(VCP_SEGMENT_BUTTON_TYPE_RADIO);
    b4->setStyle(VCP_SEGMENT_BUTTON_STYLE_TEXT_ONLY);
}


VfxS32 VtstRtSegmentButtonScr::phase(VfxS32 idx)
{
    setTitle(VFX_WSTR("Segment Button"));
    confirm(VFX_WSTR("Result is correct?"));
    return -1;
}


VtstTestResultEnum vtst_rt_segment_button(VfxU32 param)
{
    VTST_START_SCRN(VtstRtSegmentButtonScr);
    return VTST_TR_OK;
}

#endif /* __AFX_RT_TEST__ */
