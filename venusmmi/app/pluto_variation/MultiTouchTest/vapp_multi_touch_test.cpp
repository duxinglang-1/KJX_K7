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
 *  
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_EM_MISC_MULTI_TOUCH__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_multi_touch_test.h"
//#include "mmi_rp_app_em_multi_touch_test_def.h"
#include "vcp_pluto_control.h"

/***************************************************************************** 
 * Multi touch Test
 *****************************************************************************/

VappMultiTouchTest::VappMultiTouchTest()
{
    m_colors[0] = VfxColor(128, 255, 0, 0);
    m_colors[1] = VfxColor(128, 0, 0, 255);
    m_colors[2] = VfxColor(128, 0, 255, 0);
    m_colors[3] = VfxColor(128, 255, 255, 0);
    m_colors[4] = VfxColor(128, 128, 0, 128);
    m_errStr = VFX_WSTR_EMPTY;
    m_distance = 0;
}


void VappMultiTouchTest::onInit()
{
    VfxAppCatScr::onInit();
    setBgColor(VFX_COLOR_BLACK);

    VfxPen *pensrv = VFX_OBJ_GET_INSTANCE(VfxPen);
    pensrv->setTouchMode(VFX_PEN_TOUCH_MODE_MULTI_TOUCH);

    VFX_OBJ_CREATE(m_text, VfxTextFrame, this);
    m_text->setPos(0, 0);
    m_text->setSize(getSize().width, 200);
    m_text->setColor(VFX_COLOR_WHITE);
    m_text->setFont(VFX_FONT_DESC_SMALL);
    m_text->setLineMode(VfxTextFrame::LINE_MODE_MULTI);

    VFX_OBJ_CREATE(m_text2, VfxTextFrame, this);
    m_text2->setPos(0, 0);
    m_text2->setSize(getSize().width, 200);
    m_text2->setColor(VFX_COLOR_WHITE);
    m_text2->setFont(VFX_FONT_DESC_SMALL);
    m_text2->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    m_text2->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
}

void VappMultiTouchTest::onDeinit()
{
    VfxPen *pensrv = VFX_OBJ_GET_INSTANCE(VfxPen);
    pensrv->setTouchMode(VFX_PEN_TOUCH_MODE_SINGLE_TOUCH);
    VfxAppCatScr::onDeinit();
}

VfxBool VappMultiTouchTest::onKeyInput(VfxKeyEvent &event)
{
#ifdef __COSMOS_MMI__
    if (event.type == VFX_KEY_EVENT_TYPE_UP && event.keyCode == VFX_KEY_CODE_BACK)
#else
    if (event.type == VFX_KEY_EVENT_TYPE_UP && event.keyCode == VFX_KEY_CODE_RSK)
#endif
    {
        vfxPostInvoke(this, &VappMultiTouchTest::onBack, NULL);
        return VFX_TRUE;
    }

    return VfxAppCatScr::onKeyInput(event);
}

void VappMultiTouchTest::onBack(void *data)
{
    mmi_frm_scrn_close_active_id();
}

VfxBool VappMultiTouchTest::onPenInput(VfxPenEvent &event)
{
    VfxU8 i, j;
    VfxWString str;

    for (i = 0; i < event.touchCount; i++)
    {
        switch (event.touchEvents[i].type)
        {
            case VFX_PEN_EVENT_TYPE_DOWN:
                // test code
                for (j = 0; j < 5; j++)
                {
                    if (m_pos[j].id == event.touchEvents[i].id)
                    {
                        str.format("Down err %d(%d,%d,%d,%d,%d)\n", event.touchEvents[i].id, m_pos[0].id, m_pos[1].id, m_pos[2].id, m_pos[3].id, m_pos[4].id);
                        m_errStr += str;
                        break;
                    }
                }
                // test code end

                for (j = 0; j < 5; j++)
                {
                    if (m_pos[j].id == (VfxU32)-1)
                    {
                        m_pos[j].id = event.touchEvents[i].id;
                        m_pos[j].pos = event.touchEvents[i].pos;
                        VFX_OBJ_CREATE_EX(m_pos[j].circle, TestCircle, this, (m_colors[j]));
                        m_pos[j].circle->setAnchor(0.5, 0.5);
                        m_pos[j].circle->setPos(m_pos[j].pos);
                        m_pos[j].circle->forcePos(m_pos[j].pos);
                        break;
                    }
                }
                if (m_point1.id == (VfxU32)-1)
                {
                    m_point1.id = event.touchEvents[i].id;
                    m_point1.pos = event.touchEvents[i].pos;
                }
                else if (m_point2.id == (VfxU32)-1)
                {
                    m_point2.id = event.touchEvents[i].id;
                    m_point2.pos = event.touchEvents[i].pos;
                }
                break;

            case VFX_PEN_EVENT_TYPE_MOVE:
                for (j = 0; j < 5; j++)
                {
                    if (m_pos[j].id == event.touchEvents[i].id)
                    {
                        m_pos[j].pos = event.touchEvents[i].pos;
                        m_pos[j].circle->setPos(m_pos[j].pos);
                        m_pos[j].circle->forcePos(m_pos[j].pos);
                        break;
                    }
                }

                // test code
                if (j >= 5)
                {
                    str.format("Move err %d(%d,%d,%d,%d,%d)\n", event.touchEvents[i].id, m_pos[0].id, m_pos[1].id, m_pos[2].id, m_pos[3].id, m_pos[4].id);
                    m_errStr += str;
                }
                // test code end
                if (m_point1.id == event.touchEvents[i].id)
                {
                    m_point1.pos = event.touchEvents[i].pos;
                }
                else if (m_point2.id == event.touchEvents[i].id)
                {
                    m_point2.pos = event.touchEvents[i].pos;
                }
                break;

            case VFX_PEN_EVENT_TYPE_UP:
                for (j = 0; j < 5; j++)
                {
                    if (m_pos[j].id == event.touchEvents[i].id)
                    {
                        m_pos[j].id = (VfxU32)-1;
                        VFX_OBJ_CLOSE(m_pos[j].circle);
                        break;
                    }
                }

                // test code
                if (j >= 5)
                {
                    str.format("Up err %d(%d,%d,%d,%d,%d)\n", event.touchEvents[i].id, m_pos[0].id, m_pos[1].id, m_pos[2].id, m_pos[3].id, m_pos[4].id);
                    m_errStr += str;
                }
                // test code end
                if (m_point1.id == event.touchEvents[i].id)
                {
                    m_point1.id = (VfxU32)-1;
                }
                else if (m_point2.id == event.touchEvents[i].id)
                {
                    m_point2.id = (VfxU32)-1;
                }
                break;

            default:
                break;
        }
    }

    /*
    // Debug frame
    str = VFX_WSTR_EMPTY;
    for (i = 0; i < event.touchCount; i++)
    {
        str += VFX_WSTR_EMPTY.format("Point %d: x = %d, y = %d\n", i, event.touchEvents[i].pos.x, event.touchEvents[i].pos.y);
    }
    str += m_errStr;
    m_text->setString(str);
    m_text2->setString(VFX_WSTR_EMPTY);

    if (m_point1.id != -1 && m_point2.id != -1)
    {
        VfxU32 distance = (m_point1.pos.x - m_point2.pos.x) * (m_point1.pos.x - m_point2.pos.x) + (m_point1.pos.y - m_point2.pos.y) * (m_point1.pos.y - m_point2.pos.y);
        if (m_distance && distance > m_distance)
        {
            m_text2->setString(VFX_WSTR("Zoom-In"));
        }
        else if (m_distance && distance < m_distance)
        {
            m_text2->setString(VFX_WSTR("Zoom-Out"));
        }
        m_distance = distance;
    }
    else
    {
        m_distance = 0;
    }
    */
    invalidate();
    return VFX_TRUE;
}

void VappMultiTouchTest::onDraw(VfxDrawContext &dc)
{
    VfxU8 i, j;

    if (m_point1.id != (VfxU32)-1 && m_point2.id != (VfxU32)-1)
    {
        dc.setStrokeColor(VFX_COLOR_BLUE);
        for (j = 0; j < 5; j++)
        {
            dc.drawAaLine(m_point1.pos.x - 2 + j, m_point1.pos.y - 2 + j, m_point2.pos.x - 2 + j, m_point2.pos.y - 2 + j);
        }
    }

    for (i = 0; i < 5; i++)
    {
        if (m_pos[i].id == (VfxU32)-1)
        {
            continue;
        }

        for (j = 0; j < 5; j++)
        {
            dc.setStrokeColor(m_colors[i]);
            dc.drawLine(m_pos[i].pos.x - 2 + j, 0, m_pos[i].pos.x - 2 + j, getSize().height);
            dc.drawLine(0, m_pos[i].pos.y - 2 + j, getSize().width, m_pos[i].pos.y - 2 + j);
        }
//        VfxImageSrc img(VAPP_IMG_EM_MULTI_TOUCH_TEST_CIRCLE1 + i);
//        dc.drawImage(m_pos[i].pos.x - (img.getSize().width >> 1), m_pos[i].pos.y - (img.getSize().height >> 1), img);
    }
}

#endif /* __MMI_EM_MISC_MULTI_TOUCH__ */

