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
 *  vapp_gesture_test.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Gesture test header file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_MULTI_TOUCH_TEST_H__
#define __VAPP_MULTI_TOUCH_TEST_H__

#include "MMI_features.h"

#ifdef __MMI_EM_MISC_MULTI_TOUCH__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_pluto_control.h"

extern "C"
{
#include "gdi_include.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_MULTI_TOUCH_TEST_CIRCLE_DIAMETER (VFX_TOUCH_FINGER_WIDTH * 5)

/***************************************************************************** 
 * Multi touch Test
 *****************************************************************************/
class VappMultiTouchTest : public VfxAppCatScr
{
    class TestCircle : public VcpPlutoControl
    {
    public:
        TestCircle() {}
        TestCircle(VfxColor color) : m_color(color) {}

    public:
        VfxColor m_color;

    // Override
    protected:
        virtual void onPlutoCreate() {}
        virtual void onPlutoClose() {}
        virtual void onPlutoDraw()
        {
            gdi_draw_solid_circle(VAPP_MULTI_TOUCH_TEST_CIRCLE_DIAMETER >> 1, VAPP_MULTI_TOUCH_TEST_CIRCLE_DIAMETER >> 1, VAPP_MULTI_TOUCH_TEST_CIRCLE_DIAMETER >> 1, m_color);
        }
        virtual VfxSize onPlutoGetPreferredSize()
        {
            return VfxSize(VAPP_MULTI_TOUCH_TEST_CIRCLE_DIAMETER + 2, VAPP_MULTI_TOUCH_TEST_CIRCLE_DIAMETER + 2);
        }
    };

    class TestPoint : public VfxBase
    {
    public:
        VfxU32      id;
        VfxPoint    pos;
        TestCircle  *circle;

        TestPoint() :
            id((VfxU32)-1),
            circle(NULL)
        {}
    };

// Variable
private:
    TestPoint       m_pos[5];
    TestPoint       m_point1, m_point2;
    VfxTextFrame    *m_text;
    VfxTextFrame    *m_text2;
    VfxColor        m_colors[5];
    VfxWString      m_errStr;
    VfxU32          m_distance;

// Constructor / Destructor
public:
    VappMultiTouchTest();

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual void onDraw(VfxDrawContext &dc);
public:
    void onBack(void *data);
};
#endif /* __MMI_EM_MISC_MULTI_TOUCH__ */

#endif /* __VAPP_MULTI_TOUCH_TEST_H__ */

