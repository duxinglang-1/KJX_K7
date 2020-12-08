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
 *  vtst_rt_text_frame.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for VtstRtTextFrame
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vtst_rt_main.h"
#include "vfx_config.h"
#include "vfx_string.h"
#include "vfx_datatype.h"
#include "vfx_frame.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_text_frame.h"
#include "vfx_font_desc.h"
#include "vfx_app_cat_scr.h"


#ifdef __AFX_RT_TEST__

#define VTST_TEXT_X         1

/***************************************************************************** 
 * Text Frame Test Implementation
 *****************************************************************************/

class VtstRtTextFrame : public VtstRtScr
{
// Constructor / Destructor
public:
    VtstRtTextFrame()
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        VfxSize frameSize;
        VfxPoint framePos;

        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

        setTitle(VFX_WSTR("VfxTextFrame Test"));

        VfxFrame *box;
        VFX_OBJ_CREATE(box, VfxFrame, this);
        box->setRect(VfxRect(0, 30, mainScreenSize.width, mainScreenSize.height - 50));
        box->setBgColor(VFX_COLOR_PURPLE);

        VfxTextFrame *tf;
        
        VFX_OBJ_CREATE(tf, VfxTextFrame, this);
        tf->setPos(VfxPoint(VTST_TEXT_X, 30));
        tf->setString(VFX_WSTR("Normal"));
        
        framePos = tf->getPos();
        frameSize = tf->getSize();
        VFX_OBJ_CREATE(tf, VfxTextFrame, this);
        tf->setRect(VfxRect(VTST_TEXT_X, framePos.y + frameSize.height, 200, 10));
        tf->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        tf->setString(VFX_WSTR("Truncate Mode for a very long string"));

        framePos = tf->getPos();
        frameSize = tf->getSize();
        VFX_OBJ_CREATE(tf, VfxTextFrame, this);
        tf->setPos(VfxPoint(mainScreenSize.width/2, framePos.y + frameSize.height));
        tf->setAnchor(VfxFPoint(0.5f, 0.0f));
        tf->setString(VFX_WSTR("Anchor Point Center"));
        
        framePos = tf->getPos();
        frameSize = tf->getSize();
        VFX_OBJ_CREATE(tf, VfxTextFrame, this);
        tf->setRect(VfxRect(VTST_TEXT_X, framePos.y + frameSize.height, mainScreenSize.width - VTST_TEXT_X*2, 25));
        tf->setAutoResized(VFX_FALSE);
        tf->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        tf->setString(VFX_WSTR("Align Center"));

        framePos = tf->getPos();
        frameSize = tf->getSize();
        VFX_OBJ_CREATE(tf, VfxTextFrame, this);
        tf->setRect(VfxRect(VTST_TEXT_X, framePos.y + frameSize.height, mainScreenSize.width - VTST_TEXT_X*2, 25));
        tf->setAutoResized(VFX_FALSE);
        tf->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
        tf->setString(VFX_WSTR("Align Right"));

        framePos = tf->getPos();
        frameSize = tf->getSize();
        VFX_OBJ_CREATE(tf, VfxTextFrame, this);
        tf->setPos(VfxPoint(VTST_TEXT_X, framePos.y + frameSize.height));
        tf->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_SMALL, VFX_FONT_DESC_EFFECT_BORDER));
        tf->setString(VFX_WSTR("Small Font + Color"));
        tf->setColor(VFX_COLOR_RED);
        tf->setBorderColor(VFX_COLOR_YELLOW);

        framePos = tf->getPos();
        frameSize = tf->getSize();
        VFX_OBJ_CREATE(tf, VfxTextFrame, this);
        tf->setPos(VfxPoint(VTST_TEXT_X, framePos.y + frameSize.height + 1));
        tf->setSize(mainScreenSize.width-VTST_TEXT_X*2, 0);
        tf->setBgColor(VFX_COLOR_GREY);
        tf->setString(VFX_WSTR("Multiline Mode with normal attributes + Margins. The frame height will grow according to the real text height"));
        tf->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
        tf->setMargins(10);
        
        framePos = tf->getPos();
        frameSize = tf->getSize();
        VFX_OBJ_CREATE(tf, VfxTextFrame, this);
        tf->setPos(VfxPoint(VTST_TEXT_X, framePos.y + frameSize.height + 1));
        tf->setSize(mainScreenSize.width-VTST_TEXT_X*2, 0);
        tf->setBgColor(VFX_COLOR_GREY);
        tf->setString(VFX_WSTR("Multiline Mode with max lineCount. The frame height will grow according to the real text height"));
        tf->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
        tf->setMaxLines(2);


        framePos = tf->getPos();
        frameSize = tf->getSize();
        VFX_OBJ_CREATE(tf, VfxTextFrame, this);
        tf->setPos(VfxPoint(VTST_TEXT_X, framePos.y + frameSize.height + 1));
        tf->setSize(mainScreenSize.width-VTST_TEXT_X*2, 0);
        tf->setBgColor(VFX_COLOR_GREY);
        tf->setString(VFX_WSTR("Multiline Mode with max lineCount + min LineHeight. The frame height will grow according to the real text height"));
        tf->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
        tf->setMaxLines(2);
        tf->setMinLineHeight(35);     
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
};


VtstTestResultEnum vtst_rt_text_frame(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTextFrame);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

