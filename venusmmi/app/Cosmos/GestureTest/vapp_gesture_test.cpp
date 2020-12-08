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

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_EM_MISC_TOUCH_SCREEN__

#include "vapp_gesture_test.h"
#include "vapp_gesture_test_gprot.h"
#include "mmi_rp_vapp_em_gesture_test_def.h"
#include "PhoneSetupGProts.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_GESTURE_TEST_AREA_WIDTH             (VFX_MIN(getSize().height, getSize().width))
#define VAPP_GESTURE_TEST_FRAME_GAP              10             // the gap between two test frames
#define VAPP_GESTURE_TEST_FRAME_WIDTH            ((VAPP_GESTURE_TEST_AREA_WIDTH - (VAPP_GESTURE_TEST_FRAME_GAP * 4)) / 3)
#define VAPP_GESTURE_TEST_COLOR_DONE             VfxColor(VFX_COLOR_RED)
#define VAPP_GESTURE_TEST_COLOR_NOTTEST          VfxColor(VFX_COLOR_TRANSPARENT)
#define VAPP_GESTURE_TEST_DISTANCE(pos1, pos2)   sqrt((VfxFloat)((pos1).x - (pos2).x) * ((pos1).x - (pos2).x) + ((pos1).y - (pos2).y) * ((pos1).y - (pos2).y))

/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C" void vapp_gesture_test_launch(void)
{
    VfxAppLauncher::launch( 
        VAPP_EM_GESTURE_TEST,
        VFX_OBJ_CLASS_INFO(VappGestureTestApp),
        GRP_ID_ROOT);
}

/*****************************************************************************
 * gesture test menu class
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappGestureTestMenu" ,VappGestureTestMenu, VfxPage);

void VappGestureTestMenu::onInit()
{
    VfxPage::onInit();

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR("Gesture Test"));
    setTopBar(bar);
    setStatusBar(VFX_FALSE);
    setBgColor(VFX_COLOR_WHITE);

    VFX_OBJ_CREATE(m_menu, VcpListMenu, this);
    m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_menu->setContentProvider(this);
	m_menu->setSize(getSize().width, getSize().height - bar->getRect().getMaxY());
    m_menu->enableSeekBar(VFX_TRUE);
    m_menu->m_signalItemTapped.connect(this, &VappGestureTestMenu::onTapItem);
}

VfxBool VappGestureTestMenu::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
    const wchar_t* items[] =
    {
        L"Calibration",
        L"Pen test",
        L"Gesture"
    };

    text = VFX_WSTR_STATIC((VfxWChar*)items[index]);
    return VFX_TRUE;
}

VfxU32 VappGestureTestMenu::getCount() const
{
    return 3;
}

void VappGestureTestMenu::onTapItem(VcpListMenu *menu, VfxU32 index)
{
    VfxPage *page = NULL;

    switch (index)
    {
        case 0:
            VFX_OBJ_CREATE(page, VappGestureTestCaliMenu, getMainScr());
            break;

        case 1:
            VFX_OBJ_CREATE(page, VappGestureTestPenTrackScr, getMainScr());
            break;

        case 2:
            VFX_OBJ_CREATE(page, VappGestureTestGestureMenu, getMainScr());
            break;

        default:
            VFX_ASSERT(0);
    }
    getMainScr()->pushPage(0, page);
}

//VFX_IMPLEMENT_CLASS("VappGestureTestCaliMenu" ,VappGestureTestCaliMenu, VfxPage);

void VappGestureTestCaliMenu::onInit()
{
    VfxPage::onInit();

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR("Calibration"));
    setTopBar(bar);
    setStatusBar(VFX_FALSE);
    setBgColor(VFX_COLOR_WHITE);

    VFX_OBJ_CREATE(m_menu, VcpListMenu, this);
    m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_menu->setContentProvider(this);
    m_menu->setSize(getSize().width, getSize().height - bar->getRect().getMaxY());
    m_menu->enableSeekBar(VFX_TRUE);
    m_menu->m_signalItemTapped.connect(this, &VappGestureTestCaliMenu::onTapItem);
}

VfxBool VappGestureTestCaliMenu::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
    const wchar_t* items[] =
    {
        L"Settings",
        L"Start"
    };

    text = VFX_WSTR_STATIC((VfxWChar*)items[index]);
    return VFX_TRUE;
}

void VappGestureTestCaliMenu::onTapItem(VcpListMenu *menu, VfxU32 index)
{
    VfxPage *page = NULL;

    switch (index)
    {
        case 0:
            VFX_OBJ_CREATE(page, VappGestureTestCaliSetting, getMainScr());
            break;

        case 1:
            VFX_OBJ_CREATE_EX(page, VappGestureTestCalibrationScr, getMainScr(), (VappGestureTestApp::m_settings[VAPP_GESTURE_TEST_DIMETER]));
            break;

        default:
            VFX_ASSERT(0);
    }
    getMainScr()->pushPage(0, page);
}

//VFX_IMPLEMENT_CLASS("VappGestureTestGestureMenu" ,VappGestureTestGestureMenu, VfxPage);

void VappGestureTestGestureMenu::onInit()
{
    VfxPage::onInit();

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR("Gesture"));
    setTopBar(bar);
    setStatusBar(VFX_FALSE);
    setBgColor(VFX_COLOR_WHITE);

    VFX_OBJ_CREATE(m_menu, VcpListMenu, this);
    m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_menu->setContentProvider(this);
	m_menu->setSize(getSize().width, getSize().height - bar->getRect().getMaxY());
    m_menu->enableSeekBar(VFX_TRUE);
    m_menu->m_signalItemTapped.connect(this, &VappGestureTestGestureMenu::onTapItem);
}

VfxBool VappGestureTestGestureMenu::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
    const wchar_t* items[] =
    {
        L"Settings",
        L"Tap",
        L"Double tap",
        L"Hold",
        L"Drag",
        L"Slide",
        L"List SSP",
        L"Nudge"
    };

    text = VFX_WSTR_STATIC((VfxWChar*)items[index]);
    return VFX_TRUE;
}

void VappGestureTestGestureMenu::onTapItem(VcpListMenu *menu, VfxU32 index)
{
    VfxPage *page = NULL;

    switch (index)
    {
        case 0:
            VFX_OBJ_CREATE(page, VappGestureTestGestureSetting, getMainScr());
            break;

        case 1:
            VFX_OBJ_CREATE_EX(page, VappGestureTestTapScr, getMainScr(), (VappGestureTestApp::m_settings[VAPP_GESTURE_TEST_TAP_INTERVAL]));
            break;

        case 2:
            VFX_OBJ_CREATE_EX(page, VappGestureTestDoubleTapScr, getMainScr(), (VappGestureTestApp::m_settings[VAPP_GESTURE_TEST_DOUBLETAP_INTERVAL], VappGestureTestApp::m_settings[VAPP_GESTURE_TEST_DOUBLETAP_DISTANCE]));
            break;

        case 3:
            VFX_OBJ_CREATE_EX(page, VappGestureTestHoldScr, getMainScr(), (VappGestureTestApp::m_settings[VAPP_GESTURE_TEST_HOLD_INTERVAL], VappGestureTestApp::m_settings[VAPP_GESTURE_TEST_HOLD_DISTANCE]));
            break;

        case 4:
            VFX_OBJ_CREATE_EX(page, VappGestureTestDragScr, getMainScr(), (VappGestureTestApp::m_settings[VAPP_GESTURE_TEST_DRAG_INTERVAL], VappGestureTestApp::m_settings[VAPP_GESTURE_TEST_DRAG_DISTANCE]));
            break;

        case 5:
            VFX_OBJ_CREATE_EX(page, VappGestureTestSlideScr, getMainScr(), (VappGestureTestApp::m_settings[VAPP_GESTURE_TEST_SLIDE_INTERVAL], VappGestureTestApp::m_settings[VAPP_GESTURE_TEST_SLIDE_DISTANCE]));
            break;

        case 6:
            VFX_OBJ_CREATE(page, VappGestureTestSSPScr, getMainScr());
            break;

        case 7:
            VFX_OBJ_CREATE_EX(page, VappGestureTestNudgeScr, getMainScr(), (VappGestureTestApp::m_settings[VAPP_GESTURE_TEST_NUDGE_DISTANCE]));
            break;

        default:
            VFX_ASSERT(0);
    }
    getMainScr()->pushPage(0, page);
}

//VFX_IMPLEMENT_CLASS("VappGestureTestCaliSetting" ,VappGestureTestCaliSetting, VfxPage);

void VappGestureTestCaliSetting::onInit()
{
    VfxPage::onInit();

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR("Settings"));
    setTopBar(bar);
    setStatusBar(VFX_FALSE);
    setBgColor(VFX_COLOR_WHITE);

    VFX_OBJ_CREATE(m_menu, VcpListMenu, this);
    m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
    m_menu->setContentProvider(this);
	m_menu->setSize(getSize().width, getSize().height - bar->getRect().getMaxY());
    m_menu->enableSeekBar(VFX_TRUE);
    m_menu->m_signalItemTapped.connect(this, &VappGestureTestCaliSetting::onTapItem);
}

VfxBool VappGestureTestCaliSetting::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        text = VFX_WSTR("Diameter");
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        text = VfxWString().format("%d", VappGestureTestApp::m_settings[VAPP_GESTURE_TEST_DIMETER]);
    }
    return VFX_TRUE;
}

void VappGestureTestCaliSetting::onTapItem(VcpListMenu *menu, VfxU32 index)
{
    VappGestureTestSetting *page;
    VFX_OBJ_CREATE_EX(page, VappGestureTestSetting, getMainScr(), (VAPP_GESTURE_TEST_DIMETER));
    getMainScr()->pushPage(0, page);
}


//VFX_IMPLEMENT_CLASS("VappGestureTestGestureSetting" ,VappGestureTestGestureSetting, VfxPage);

void VappGestureTestGestureSetting::onInit()
{
    VfxPage::onInit();

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR("Settings"));
    setTopBar(bar);
    setStatusBar(VFX_FALSE);
    setBgColor(VFX_COLOR_WHITE);

    VFX_OBJ_CREATE(m_menu, VcpListMenu, this);
    m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
    m_menu->setContentProvider(this);
    m_menu->setSize(getSize().width, getSize().height - bar->getRect().getMaxY() - 1);
    m_menu->enableSeekBar(VFX_TRUE);
    m_menu->m_signalItemTapped.connect(this, &VappGestureTestGestureSetting::onTapItem);
}

VfxBool VappGestureTestGestureSetting::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
    const wchar_t* items[] =
    {
        L"Tap Inteval(ms)",
        L"Double tap Inteval(ms)",
        L"Double tap Distance",
        L"Hold Inteval(ms)",
        L"Hold Distance",
        L"Drag Inteval(ms)",
        L"Drag Distance",
        L"Slide Inteval(ms)",
        L"Slide Distance",
        L"Nudge Distance"
    };

    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        text = VFX_WSTR_STATIC((VfxWChar*)items[index]);
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        text = VfxWString().format("%d", VappGestureTestApp::m_settings[index]);
    }
    return VFX_TRUE;
}

void VappGestureTestGestureSetting::onTapItem(VcpListMenu *menu, VfxU32 index)
{
    VappGestureTestSetting *page;
    VFX_OBJ_CREATE_EX(page, VappGestureTestSetting, getMainScr(), (index));
    getMainScr()->pushPage(0, page);
}

//VFX_IMPLEMENT_CLASS("VappGestureTestSetting" ,VappGestureTestSetting, VfxPage);

void VappGestureTestSetting::onInit()
{
    VfxPage::onInit();

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR("Settings"));
    setTopBar(bar);
    setStatusBar(VFX_FALSE);
    setBgColor(VFX_COLOR_WHITE);

    VFX_OBJ_CREATE(m_menu, VcpListMenu, this);
    m_menu->setMenuMode(VCP_LIST_MENU_MODE_SINGLE_SELECTION);
    m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_menu->setContentProvider(this);
	m_menu->setSize(getSize().width, getSize().height - bar->getRect().getMaxY());
    m_menu->enableSeekBar(VFX_TRUE);
    m_menu->m_signalItemTapped.connect(this, &VappGestureTestSetting::onTapItem);
}

VfxBool VappGestureTestSetting::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
    text = VfxWString().format("%d", VappGestureTestApp::m_settings_list[m_index][index]);
    return VFX_TRUE;
}

VcpListMenuItemStateEnum VappGestureTestSetting::getItemState(VfxU32 index) const
{
    if (VappGestureTestApp::m_settings_list[m_index][index] == VappGestureTestApp::m_settings[m_index])
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

void VappGestureTestSetting::onTapItem(VcpListMenu *menu, VfxU32 index)
{
    VappGestureTestApp::m_settings[m_index] = VappGestureTestApp::m_settings_list[m_index][index];
    getMainScr()->popPage();
}

/*****************************************************************************
 * gesture test app class
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappGestureTestScr" ,VappGestureTestScr, VfxMainScr);

void VappGestureTestScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VappGestureTestMenu *page;
    VFX_OBJ_CREATE(page, VappGestureTestMenu, this);
    pushPage(0, page);
}

VFX_IMPLEMENT_CLASS("VappGestureTestApp" ,VappGestureTestApp, VfxApp);

const VfxU32 VappGestureTestApp::m_settings_list[][VAPP_GESTURE_TEST_MAX_SETTINGS] =
{
    {50, 60, 70, 80, 90, 100, 110, 120, 130, 140},
    {200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100},
    {3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
    {1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500},
    {3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {50, 100, 150, 200, 250, 300, 350, 400, 450, 500},
    {300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200},
    {200, 250, 300, 350, 400, 450, 500, 550, 600, 650},
    {10, 20, 30, 40, 50, 60, 70, 80, 90, 100},
    {5, 6, 7, 8, 9, 10, 11, 12, 13, 14}
};

VfxU32 VappGestureTestApp::m_settings[] = {50, 200, 3, 1000, 3, 1, 50, 300, 200, 10, 5};

void VappGestureTestApp::onRun(void * args,VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VappGestureTestScr* scr;
    VFX_OBJ_CREATE(scr, VappGestureTestScr, this);
    scr->show();
}

/*****************************************************************************
 * pen track class
 *****************************************************************************/
void VappGestureTestPenTrack::addPoint(VfxPenEvent &event)
{
    if (m_count >= VAPP_GESTURE_TEST_MAX_POINTS) return;
    m_point[m_count].type = event.type;
    m_point[m_count].pos = event.pos;
    m_count++;
    invalidate();
}

void VappGestureTestPenTrack::clearPenTrack()
{
    m_count = 0;
    invalidate();
}

void VappGestureTestPenTrack::onDraw(VfxDrawContext &dc)
{
    VfxS32 i;
    for (i = 0; i < m_count; i++)
    {
        switch (m_point[i].type)
        {
            // draw pen down point
            case VFX_PEN_EVENT_TYPE_DOWN:
                dc.setStrokeColor(VFX_COLOR_RED);
                dc.drawLine(m_point[i].pos.x - 2, m_point[i].pos.y - 2, m_point[i].pos.x + 2, m_point[i].pos.y + 2);
                dc.drawLine(m_point[i].pos.x - 2, m_point[i].pos.y + 2, m_point[i].pos.x + 2, m_point[i].pos.y - 2);
                break;

            // draw pen move track
            case VFX_PEN_EVENT_TYPE_MOVE:
                dc.setStrokeColor(VFX_COLOR_GREEN);
                dc.drawLine(m_point[i].pos, m_point[i-1].pos);
                break;

            // draw pen up point
            case VFX_PEN_EVENT_TYPE_UP:
                dc.setStrokeColor(VFX_COLOR_GREEN);
                dc.drawLine(m_point[i].pos, m_point[i-1].pos);
                dc.setStrokeColor(VFX_COLOR_BLUE);
                dc.drawLine(m_point[i].pos.x - 2, m_point[i].pos.y - 2, m_point[i].pos.x + 2, m_point[i].pos.y + 2);
                dc.drawLine(m_point[i].pos.x - 2, m_point[i].pos.y + 2, m_point[i].pos.x + 2, m_point[i].pos.y - 2);
                break;

            default:
                break;
        }
    }
}


/*****************************************************************************
 * pen track test screen
 *****************************************************************************/
void VappGestureTestPenTrackScr::onInit()
{
//    VfxAppCatScr::onInit();
    VfxPage::onInit();
    setStatusBar(VFX_FALSE);

    mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_2, MMI_PEN_SAMPLING_PERIOD_2);

    setBgColor(VFX_COLOR_WHITE);
    VFX_OBJ_CREATE(m_pentrack, VappGestureTestPenTrack, this);
    m_pentrack->setPos(0, 0);
    m_pentrack->setSize(getSize());
    m_pentrack->setBgColor(VFX_COLOR_TRANSPARENT);
    m_pentrack->setIsUnhittable(VFX_TRUE);

    // Text frame to display some info
    VFX_OBJ_CREATE(m_parameters, VfxTextFrame, this);
    m_parameters->setRect(getSize().width / 2, 0, getSize().width / 2, 32);
    m_parameters->setColor(VFX_COLOR_BLACK);
    m_parameters->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    m_parameters->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
    m_parameters->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_SMALL));
    m_parameters->setIsUnhittable(VFX_TRUE);
}


VfxBool VappGestureTestPenTrackScr::onPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN ||
        event.type == VFX_PEN_EVENT_TYPE_MOVE ||
        event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        // display pen down position, pen position, duration on screen
        m_parameters->setString(VfxWString().format("Down pos:(%d,%d)\nLast pos:(%d,%d)\nDuration:%dms\n", event.downPos.x, event.downPos.y, event.pos.x, event.pos.y, event.timeStamp - event.downTimeStamp));

        // let pen track frame know it
        m_pentrack->addPoint(event);
    }
    return VFX_TRUE;
}


/*****************************************************************************
 * calibration test screen
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappGestureTestCalibrationScr", VappGestureTestCalibrationScr, VfxPage);

void VappGestureTestCalibrationScr::onInit()
{
    VappGestureTestPenTrackScr::onInit();

    // 3 calibratin points
    m_caliState = CALIBRATION_WELCOME_STATE;
    m_caliPoint[0].x = getSize().width / 10;
    m_caliPoint[0].y = getSize().height / 10;
    m_caliPoint[1].x = getSize().width * 17 / 20;
    m_caliPoint[1].y = getSize().height * 17 / 20;
    m_caliPoint[2].x = getSize().width / 2;
    m_caliPoint[2].y = getSize().height / 2;

    // Show current dimeter setting
    VFX_OBJ_CREATE(m_settings, VfxTextFrame, this);
    m_settings->setRect(0, 0, getSize().width / 2, 0);
    m_settings->setColor(VFX_COLOR_BLACK);
    m_settings->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    m_settings->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_SMALL));
    m_settings->setIsUnhittable(VFX_TRUE);
    m_settings->setString(VfxWString().format("Dimeter=%dpixel", m_dimeter));

    m_parameters->setString(VFX_WSTR("Click anywhere to start"));
}


VfxBool VappGestureTestCalibrationScr::onPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        switch (m_caliState)
        {
            case CALIBRATION_WELCOME_STATE:
                m_caliState = CALIBRATION_TOP_LEFT_POINT_STATE;
                VFX_OBJ_CREATE(m_caliImage, VappGestureTestCalibrationImage, this);
                m_caliImage->setSize(50, 50);
                m_caliImage->setAnchor(0.5, 0.5);
                m_caliImage->setPos(m_caliPoint[0]);
                m_caliImage->dimeter = m_dimeter;
                break;

            case CALIBRATION_TOP_LEFT_POINT_STATE:
                m_caliState = CALIBRATION_BOTTOM_RIGHT_POINT_STATE;
                m_inputPoint[0] = event.pos;
                m_caliImage->setPos(m_caliPoint[1]);
                break;

            case CALIBRATION_BOTTOM_RIGHT_POINT_STATE:
                m_caliState = CALIBRATION_CENTER_POINT_STATE;
                m_inputPoint[1] = event.pos;
                m_caliImage->setPos(m_caliPoint[2]);
                break;

            case CALIBRATION_CENTER_POINT_STATE:
                m_inputPoint[2] = event.pos;
                handleResult();
                break;

            default:
                break;
        }
    }

    return VappGestureTestPenTrackScr::onPenInput(event);
}


void VappGestureTestCalibrationScr::handleResult()
{
    VfxU8 i;
    VfxBool result = VFX_TRUE;
    for (i = 0; i < 3; i++)
    {
        // check if all 3 pen down are in the calibration circle
        if (VAPP_GESTURE_TEST_DISTANCE(m_caliPoint[i], m_inputPoint[i]) > m_dimeter / 2)
            result = VFX_FALSE;
    }

    if (result)
    {
        VcpConfirmPopup *popup;
        VFX_OBJ_CREATE(popup, VcpConfirmPopup, this);
        popup->setInfoType(VCP_POPUP_TYPE_SUCCESS);
        popup->setText(VFX_WSTR("Test success"));
        popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        popup->setAutoDestory(VFX_TRUE);
        popup->show(VFX_TRUE);
        getMainScr()->popPage();
    }
    else
    {
        m_caliState = CALIBRATION_TOP_LEFT_POINT_STATE;
        m_caliImage->setPos(m_caliPoint[0]);
    }
}


/*****************************************************************************
 * gesture test screen base class
 *****************************************************************************/
VappGestureTestBaseScr::VappGestureTestBaseScr(VfxMsec interval, VfxS16 distance) :
    m_testArea(NULL),
    m_interval(interval),
    m_distance(distance)
{
    VfxU8 i;
    for (i = 0; i < VAPP_GESTURE_TEST_FRAMES; i++)
    {
        m_testFrames[i] = NULL;
    }
}


void VappGestureTestBaseScr::onInit()
{
    VappGestureTestPenTrackScr::onInit();

    VfxU8 i = 0;
    VfxS8 row, col;
    VfxPoint pos;
    VfxWString settings;

    setBgColor(VFX_COLOR_WHITE);

    // Test area
    VFX_OBJ_CREATE(m_testArea, VfxFrame, this);
    m_testArea->setAnchor(0.5, 0.5);
    m_testArea->setPos(getRect().getMidPoint());
    m_testArea->setSize(VAPP_GESTURE_TEST_AREA_WIDTH, VAPP_GESTURE_TEST_AREA_WIDTH);
    m_testArea->sendToBack();

    // Show 9 test frames
    for (row = 0; row < VAPP_GESTURE_TEST_FRAMES_ROW; row++)
    {
        for (col = 0; col < VAPP_GESTURE_TEST_FRAMES_COL; col++)
        {
            VFX_OBJ_CREATE(m_testFrames[i], VfxFrame, m_testArea);
            m_testFrames[i]->setSize(VAPP_GESTURE_TEST_FRAME_WIDTH, VAPP_GESTURE_TEST_FRAME_WIDTH);
            pos.x = col * (VAPP_GESTURE_TEST_FRAME_WIDTH + VAPP_GESTURE_TEST_FRAME_GAP) + VAPP_GESTURE_TEST_FRAME_GAP;
            pos.y = row * (VAPP_GESTURE_TEST_FRAME_WIDTH + VAPP_GESTURE_TEST_FRAME_GAP) + VAPP_GESTURE_TEST_FRAME_GAP;
            m_testFrames[i]->setPos(pos);
            m_testFrames[i]->setBorder(VFX_COLOR_BLACK);
            m_testFrames[i]->setBgColor(VAPP_GESTURE_TEST_COLOR_NOTTEST);
            i++;
        }
    }

    // Show current time interval and distance settings
    VFX_OBJ_CREATE(m_settings, VfxTextFrame, this);
    m_settings->setRect(0, 0, getSize().width / 2, 0);
    m_settings->setColor(VFX_COLOR_BLACK);
    m_settings->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    m_settings->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_SMALL));
    m_settings->setIsUnhittable(VFX_TRUE);
    settings = VFX_WSTR_EMPTY;
    if (m_interval != 0)
    {
        settings += VfxWString().format("interval=%dms\n", m_interval);
    }
    if (m_distance != 0)
    {
        settings += VfxWString().format("distance=%dpixel", m_distance);
    }
    m_settings->setString(settings);
}


VfxBool VappGestureTestBaseScr::isTestFinished()
{
    VfxU8 i;

    // check if all 9 test frames have been tested
    for (i = 0; i < VAPP_GESTURE_TEST_FRAMES; i++)
    {
        if (m_testFrames[i]->getBgColor() == VAPP_GESTURE_TEST_COLOR_NOTTEST)
        {
            return VFX_FALSE;
        }
    }
    return VFX_TRUE;
}


void VappGestureTestBaseScr::testSuccess()
{
    VcpConfirmPopup *popup;
    VFX_OBJ_CREATE(popup, VcpConfirmPopup, this);
    popup->setInfoType(VCP_POPUP_TYPE_SUCCESS);
    popup->setText(VFX_WSTR("Test success"));
    popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    popup->setAutoDestory(VFX_TRUE);
    popup->show(VFX_TRUE);
}


void VappGestureTestBaseScr::testFailed(VfxWString &str)
{
    VcpConfirmPopup *popup;
    VFX_OBJ_CREATE(popup, VcpConfirmPopup, this);
    popup->setInfoType(VCP_POPUP_TYPE_WARNING);
    popup->setText(str);
    popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    popup->setAutoDestory(VFX_TRUE);
    popup->show(VFX_TRUE);
}


void VappGestureTestBaseScr::drawArrow(VfxDrawContext &dc, VfxPoint &start, VfxPoint &end)
{
    VfxPoint pos1, pos2;

    if (start.x == end.x)
    {
        if (start.y > end.y)
        {
            pos1 = VfxPoint(end.x - 5, end.y + 5);
            pos2 = VfxPoint(end.x + 5, end.y + 5);
        }
        else
        {
            pos1 = VfxPoint(end.x - 5, end.y - 5);
            pos2 = VfxPoint(end.x + 5, end.y - 5);
        }
    }
    else if (start.x > end.x)
    {
        if (start.y == end.y)
        {
            pos1 = VfxPoint(end.x + 5, end.y - 5);
            pos2 = VfxPoint(end.x + 5, end.y + 5);
        }
        else if (start.y > end.y)
        {
            pos1 = VfxPoint(end.x + 10, end.y);
            pos2 = VfxPoint(end.x, end.y + 10);
        }
        else
        {
            pos1 = VfxPoint(end.x + 10, end.y);
            pos2 = VfxPoint(end.x, end.y - 10);
        }
    }
    else
    {
        if (start.y == end.y)
        {
            pos1 = VfxPoint(end.x - 5, end.y - 5);
            pos2 = VfxPoint(end.x - 5, end.y + 5);
        }
        else if (start.y > end.y)
        {
            pos1 = VfxPoint(end.x - 10, end.y);
            pos2 = VfxPoint(end.x, end.y + 10);
        }
        else
        {
            pos1 = VfxPoint(end.x - 10, end.y);
            pos2 = VfxPoint(end.x, end.y - 10);
        }
    }
    dc.drawLine(start, end);
    dc.drawLine(pos1, end);
    dc.drawLine(pos2, end);
}


/*****************************************************************************
 * tap test screen
 *****************************************************************************/
void VappGestureTestTapScr::onInit()
{
    VappGestureTestBaseScr::onInit();
    m_parameters->setString(VFX_WSTR("Please click each button quickly."));
}


VfxBool VappGestureTestTapScr::onPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        // check if a test frame is clicked
        VfxFrame *frame = hitTest(event.downPos);
        if (frame->getParentFrame() != m_testArea || frame->getBgColor() == VAPP_GESTURE_TEST_COLOR_DONE)
        {
            return VappGestureTestBaseScr::onPenInput(event);
        }
        // check time interval between pen down and up
        if (event.timeStamp - event.downTimeStamp > m_interval)
        {
            VfxWString str = VFX_WSTR("Pen down time too long");
            testFailed(str);
        }
        else
        {
            frame->setBgColor(VAPP_GESTURE_TEST_COLOR_DONE);
            if (isTestFinished())
            {
                testSuccess();
            }
        }
    }

    return VappGestureTestBaseScr::onPenInput(event);
}


/*****************************************************************************
 * double tap test screen
 *****************************************************************************/
VappGestureTestDoubleTapScr::VappGestureTestDoubleTapScr(VfxMsec interval, VfxS16 distance) :
    VappGestureTestBaseScr(interval, distance),
    m_firstDownFrame(NULL),
    m_firstDownTime(0),
    m_waitSecondTap(VFX_FALSE)
{
}


void VappGestureTestDoubleTapScr::onInit()
{
    VappGestureTestBaseScr::onInit();
    m_parameters->setString(VFX_WSTR("Please click twice on each button"));
}


VfxBool VappGestureTestDoubleTapScr::onPenInput(VfxPenEvent &event)
{
    VappGestureTestBaseScr::onPenInput(event);

    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_UP:
        {
            // check if a test frame is clicked
            VfxFrame *frame = hitTest(event.downPos);
            if (frame->getParentFrame() != m_testArea || frame->getBgColor() == VAPP_GESTURE_TEST_COLOR_DONE)
            {
                m_waitSecondTap = VFX_FALSE;
                break;
            }

            if (!m_waitSecondTap || frame != m_firstDownFrame)
            {
                // record the first pen down info
                m_firstDownFrame = frame;
                m_firstDownTime = event.downTimeStamp;
                m_firstDownPos = event.downPos;
                m_waitSecondTap = VFX_TRUE;
            }
            else
            {
                // display duration between two pen downs
                m_parameters->setString(VfxWString().format("1st pos:(%d,%d)\n2nd pos:(%d,%d)\nDuration:%dms\n", m_firstDownPos.x, m_firstDownPos.y, event.downPos.x, event.downPos.y, event.downTimeStamp - m_firstDownTime));

                // check time interval between the two pen downs
                if (event.downTimeStamp - m_firstDownTime > m_interval)
                {
                    VfxWString str = VFX_WSTR("Duration between two pen down too long");
                    testFailed(str);
                }
                else if (VAPP_GESTURE_TEST_DISTANCE(m_firstDownPos, event.downPos) > m_distance)
                {
                    VfxWString str = VFX_WSTR("Distance between two pen down too long");
                    testFailed(str);
                }
                else
                {
                    frame->setBgColor(VAPP_GESTURE_TEST_COLOR_DONE);
                    if (isTestFinished())
                    {
                        testSuccess();
                    }
                }
                m_waitSecondTap = VFX_FALSE;
            }
            break;
        }

        default:
            break;
    }

    return VFX_TRUE;
}


/*****************************************************************************
 * hold test screen
 *****************************************************************************/
void VappGestureTestHoldScr::onInit()
{
    VappGestureTestBaseScr::onInit();
    m_parameters->setString(VFX_WSTR("Please hold on each button for a while"));
}


VfxBool VappGestureTestHoldScr::onPenInput(VfxPenEvent &event)
{
    VfxFrame *frame = hitTest(event.downPos);

    // check if a test frame is clicked
    if (frame->getParentFrame() != m_testArea || frame->getBgColor() == VAPP_GESTURE_TEST_COLOR_DONE)
    {
        return VappGestureTestBaseScr::onPenInput(event);
    }
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_MOVE:
            // check if pen move two much
            if (VAPP_GESTURE_TEST_DISTANCE(event.downPos, event.pos) > m_distance)
            {
                VfxWString str = VFX_WSTR("Distance between pen down and pen move too long");
                testFailed(str);
            }
            break;

        case VFX_PEN_EVENT_TYPE_UP:
            // check time interval and distance between pen down and up
            if (event.timeStamp - event.downTimeStamp < m_interval)
            {
                VfxWString str = VFX_WSTR("Pen down time too short");
                testFailed(str);
            }
            else if (VAPP_GESTURE_TEST_DISTANCE(event.downPos, event.pos) > m_distance)
            {
                VfxWString str = VFX_WSTR("Distance between pen down and pen up too long");
                testFailed(str);
            }
            else
            {
                frame->setBgColor(VAPP_GESTURE_TEST_COLOR_DONE);
                if (isTestFinished())
                {
                    testSuccess();
                }
            }
            break;

        default:
            break;
    }

    return VappGestureTestBaseScr::onPenInput(event);
}


/*****************************************************************************
 * drag test screen
 *****************************************************************************/
VappGestureTestDragScr::VappGestureTestDragScr(VfxMsec interval, VfxS16 distance) :
    VappGestureTestBaseScr(interval, distance),
    m_currRoute(NULL),
    m_tempFrame(NULL)
{
}


void VappGestureTestDragScr::onInit()
{
    VappGestureTestBaseScr::onInit();

    // init all test routes
    m_testRoute[0].src = m_testFrames[0];
    m_testRoute[0].dst = m_testFrames[1];

    m_testRoute[1].src = m_testFrames[2];
    m_testRoute[1].dst = m_testFrames[5];

    m_testRoute[2].src = m_testFrames[8];
    m_testRoute[2].dst = m_testFrames[7];

    m_testRoute[3].src = m_testFrames[6];
    m_testRoute[3].dst = m_testFrames[3];

    m_testRoute[4].src = m_testFrames[0];
    m_testRoute[4].dst = m_testFrames[8];

    m_testRoute[5].src = m_testFrames[2];
    m_testRoute[5].dst = m_testFrames[6];

    m_testRoute[6].src = m_testFrames[8];
    m_testRoute[6].dst = m_testFrames[0];

    m_testRoute[7].src = m_testFrames[6];
    m_testRoute[7].dst = m_testFrames[2];

    m_currRoute = m_testRoute;

    m_parameters->setString(VFX_WSTR("Please drag the button according the route"));
}


void VappGestureTestDragScr::onDeinit()
{
    VfxU8 i;
    for (i = 0; i < VAPP_GESTURE_TEST_DRAG_ROUTES; i++)
    {
        m_testRoute[i].src = m_testRoute[i].dst = NULL;
    }
    m_currRoute = NULL;

    VappGestureTestBaseScr::onDeinit();
}


void VappGestureTestDragScr::onDraw(VfxDrawContext & dc)
{
    // draw an arrow to show the test route
    VfxPoint start = convertPointFrom(m_currRoute->src->getRect().getMidPoint(), m_testArea);
    VfxPoint end = convertPointFrom(m_currRoute->dst->getRect().getMidPoint(), m_testArea);
    drawArrow(dc, start, end);
}


VfxBool VappGestureTestDragScr::onPenInput(VfxPenEvent &event)
{
    VfxU8 i;

    // check if a test frame is clicked
    VfxFrame *frame = hitTest(event.downPos);
    if (frame->getParentFrame() != m_testArea || frame != m_currRoute->src)
    {
        return VappGestureTestBaseScr::onPenInput(event);
    }

    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
        {
            VFX_OBJ_CREATE(m_tempFrame, VfxFrame, m_testArea);
            m_tempFrame->setRect(frame->getRect());
            m_tempFrame->setBgColor(frame->getBgColor());
            m_tempFrame->setBorder(frame->getBorderColor());
            m_tempFrame->setIsUnhittable(VFX_TRUE);
            frame->setBgColor(VAPP_GESTURE_TEST_COLOR_NOTTEST);
        }

        case VFX_PEN_EVENT_TYPE_MOVE:
        {
            VfxTransform trans(VFX_TRANSFORM_TYPE_AFFINE);
            trans.data.affine.tx = (VfxFloat)event.pos.x - event.downPos.x;
            trans.data.affine.ty = (VfxFloat)event.pos.y - event.downPos.y;
            m_tempFrame->setTransform(trans);
            break;
        }

        case VFX_PEN_EVENT_TYPE_UP:
        {
            // check time interval and distance between pen down and up
            VfxMsec diffTime = event.timeStamp - event.downTimeStamp;
            VFX_OBJ_CLOSE(m_tempFrame);
            if (hitTest(event.pos) != m_currRoute->dst)
            {
                VfxWString str = VFX_WSTR("Please drag according the suggested route");
                testFailed(str);
            }
            else if ((VfxFloat)VAPP_GESTURE_TEST_DISTANCE(event.downPos, event.pos) / diffTime > (VfxFloat)m_distance / m_interval)
            {
                VfxWString str = VFX_WSTR("Drag speed too fast");
                testFailed(str);
            }
            else
            {
                // set the color of src test frame and dst test frame
                for (i = 0; i < VAPP_GESTURE_TEST_FRAMES; i++)
                {
                    m_testFrames[i]->setBgColor(VAPP_GESTURE_TEST_COLOR_NOTTEST);
                }
                frame->setBgColor(VAPP_GESTURE_TEST_COLOR_DONE);
                hitTest(event.pos)->setBgColor(VAPP_GESTURE_TEST_COLOR_DONE);

                // if all routes have been tested
                if (m_currRoute == &m_testRoute[VAPP_GESTURE_TEST_DRAG_ROUTES - 1])
                {
                    m_currRoute = m_testRoute;
                    testSuccess();
                }
                else
                {
                    m_currRoute++;
                }
                invalidate();
            }
            break;
        }

        default:
            break;
    }

    return VappGestureTestBaseScr::onPenInput(event);
}


/*****************************************************************************
 * slide test screen
 *****************************************************************************/
void VappGestureTestSlideScr::onInit()
{
    VappGestureTestBaseScr::onInit();
    m_parameters->setString(VFX_WSTR("Please slide according the route quickly"));
}


VfxBool VappGestureTestSlideScr::onPenInput(VfxPenEvent &event)
{
    VfxS32 i;
    VfxS32 distance = 0;
    VfxMsec diffTime = 0;

    if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        // check if slide direction correct
        switch (m_direction)
        {
            case VAPP_GESTURE_SLIDE_DOWN:
                distance = event.pos.y - event.downPos.y;
                break;

            case VAPP_GESTURE_SLIDE_UP:
                distance = event.downPos.y - event.pos.y;
                break;

            case VAPP_GESTURE_SLIDE_RIGHT: 
                distance = event.pos.x - event.downPos.x;
                break;

            case VAPP_GESTURE_SLIDE_LEFT: 
                distance = event.downPos.x - event.pos.x;
                break;

            default:
                break;
        }

        diffTime = event.timeStamp - event.downTimeStamp;
        if (distance <= 0)
        {
            VfxWString str = VFX_WSTR("Please slide according the suggested route");
            testFailed(str);
        }
        else if ((VfxFloat)VAPP_GESTURE_TEST_DISTANCE(event.downPos, event.pos) / diffTime < (VfxFloat)m_distance / m_interval)
        {
            VfxWString str = VFX_WSTR("Slide speed too slow");
            testFailed(str);
        }
        else
        {
            // set the color of all test frames
            for (i = 0; i < VAPP_GESTURE_TEST_FRAMES; i++)
            {
                if (m_direction == VAPP_GESTURE_SLIDE_DOWN || m_direction == VAPP_GESTURE_SLIDE_RIGHT)
                {
                    m_testFrames[i]->setBgColor(VAPP_GESTURE_TEST_COLOR_DONE);
                }
                else
                {
                    m_testFrames[i]->setBgColor(VAPP_GESTURE_TEST_COLOR_NOTTEST);
                }
            }

            m_direction++;
            invalidate();

            // if all directions have been tested
            if (m_direction == VAPP_GESTURE_SLIDE_ENUM_MAX)
            {
                m_direction = VAPP_GESTURE_SLIDE_DOWN;
                testSuccess();
            }
        }
    }

    return VappGestureTestBaseScr::onPenInput(event);
}


void VappGestureTestSlideScr::onDraw(VfxDrawContext &dc)
{
    VfxPoint pos1(m_testArea->getRect().getMaxX() - VAPP_GESTURE_TEST_FRAME_GAP / 2, m_testArea->getRect().getMinY() + VAPP_GESTURE_TEST_FRAME_GAP / 2);
    VfxPoint pos2(m_testArea->getRect().getMaxX() - VAPP_GESTURE_TEST_FRAME_GAP / 2, m_testArea->getRect().getMaxY() - VAPP_GESTURE_TEST_FRAME_GAP / 2);
    VfxPoint pos3(m_testArea->getRect().getMinX() + VAPP_GESTURE_TEST_FRAME_GAP / 2, m_testArea->getRect().getMaxY() - VAPP_GESTURE_TEST_FRAME_GAP / 2);

    // draw an arrow to show current test route
    if (m_direction == VAPP_GESTURE_SLIDE_DOWN)
    {
        drawArrow(dc, pos1, pos2);
    }
    else if (m_direction == VAPP_GESTURE_SLIDE_UP)
    {
        drawArrow(dc, pos2, pos1);
    }
    else if (m_direction == VAPP_GESTURE_SLIDE_RIGHT)
    {
        drawArrow(dc, pos3, pos2);
    }
    else
    {
        drawArrow(dc, pos2, pos3);
    }
}


/*****************************************************************************
 * ssp test screen
 *****************************************************************************/
void VappGestureTestSSPScr::notifyScrollEnd(VcpScrollable* sender)
{
    VFX_UNUSED(sender);
    VcpConfirmPopup *popup;

    VFX_OBJ_CREATE(popup, VcpConfirmPopup, this);
    popup->setInfoType(VCP_POPUP_TYPE_SUCCESS);
    popup->setText(VFX_WSTR("Test success"));
    popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    popup->setAutoDestory(VFX_TRUE);
    popup->show(VFX_TRUE);

    m_testMenu->m_signalScrollStopped.disconnect(this, &VappGestureTestSSPScr::notifyScrollEnd);
}


void VappGestureTestSSPScr::onInit()
{
    VfxPage::onInit();
    setStatusBar(VFX_FALSE);
    setBgColor(VFX_COLOR_WHITE);

    VFX_OBJ_CREATE(m_testMenu, VcpListMenu, this);
    m_testMenu->setSize(getSize().width, getSize().height);
    m_testMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_testMenu->setFocusStyle(VCP_LIST_MENU_FOCUS_BEHAVIOR_NONE);
    m_testMenu->setContentProvider(this);
}


VfxBool VappGestureTestSSPScr::onPreviewPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        m_testMenu->m_signalScrollStopped.connect(this, &VappGestureTestSSPScr::notifyScrollEnd);
    }

    return VFX_FALSE;
}


/*****************************************************************************
 * nudge test screen
 *****************************************************************************/
void VappGestureTestNudgeScr::onInit()
{
    VfxU8 i;
    VfxPoint pos;
    VappGestureTestBaseScr::onInit();

    // init all test routes
    for (i = 0; i < VAPP_GESTURE_TEST_FRAMES; i++)
    {
        m_testRoute[i].src = m_testFrames[i];
        m_testRoute[i].dir = (i < VAPP_GESTURE_TEST_ENUM_MAX ? i : 0);
    }
    m_parameters->setString(VFX_WSTR("Please move a little according the route"));
}


void VappGestureTestNudgeScr::onDeinit()
{
    VfxU8 i;
    for (i = 0; i < VAPP_GESTURE_TEST_FRAMES; i++)
    {
        m_testRoute[i].src = NULL;
    }

    VappGestureTestBaseScr::onDeinit();
}


VfxBool VappGestureTestNudgeScr::checkDirection(VfxPoint &downPos, VfxPoint &pos, VfxFrame *frame)
{
    VfxU8 i;
    for (i = 0; i < VAPP_GESTURE_TEST_FRAMES; i++)
    {
        if (m_testRoute[i].src == frame)
        {
            break;
        }
    }
    VFX_ASSERT(i < VAPP_GESTURE_TEST_FRAMES);

    switch (m_testRoute[i].dir)
    {
        case VAPP_GESTURE_TEST_DOWN:
            if (pos.y > downPos.y)
            {
                return VFX_TRUE;
            }
            break;
        case VAPP_GESTURE_TEST_UP:
            if (pos.y < downPos.y)
            {
                return VFX_TRUE;
            }
            break;
        case VAPP_GESTURE_TEST_RIGHT:
            if (pos.x > downPos.x)
            {
                return VFX_TRUE;
            }
            break;
        case VAPP_GESTURE_TEST_LEFT:
            if (pos.x < downPos.x)
            {
                return VFX_TRUE;
            }
            break;
        case VAPP_GESTURE_TEST_DOWNLEFT:
            if (pos.y > downPos.y && pos.x < downPos.x)
            {
                return VFX_TRUE;
            }
            break;
        case VAPP_GESTURE_TEST_DOWNRIGHT:
            if (pos.y > downPos.y && pos.x > downPos.x)
            {
                return VFX_TRUE;
            }
            break;
        case VAPP_GESTURE_TEST_UPLEFT:
            if (pos.y < downPos.y && pos.x < downPos.x)
            {
                return VFX_TRUE;
            }
            break;
        case VAPP_GESTURE_TEST_UPRIGHT:
            if (pos.y < downPos.y && pos.x > downPos.x)
            {
                return VFX_TRUE;
            }
            break;
        default:
            VFX_ASSERT(0);
    }

    return VFX_FALSE;
}


VfxBool VappGestureTestNudgeScr::onPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_MOVE:
        {
            VfxFrame *frame = hitTest(event.downPos);
            if (frame == NULL || frame->getBgColor() == VAPP_GESTURE_TEST_COLOR_DONE || frame->getParentFrame() != m_testArea)
            {
                break;
            }
            VfxTransform trans;
            trans.data.affine.tx = (VfxFloat)event.pos.x - event.downPos.x;
            trans.data.affine.ty = (VfxFloat)event.pos.y - event.downPos.y;
            frame->setTransform(trans);
            break;
        }

        case VFX_PEN_EVENT_TYPE_UP:
        {
            // check if a test frame is clicked
            VfxFrame *frame = hitTest(event.downPos);
            if (frame == NULL || frame->getBgColor() == VAPP_GESTURE_TEST_COLOR_DONE || frame->getParentFrame() != m_testArea)
            {
                break;
            }
            frame->setTransform(VFX_TRANSFORM_IDENTITY);
            if (!checkDirection(event.downPos, event.pos, frame))
            {
                VfxWString str = VFX_WSTR("Please drag according the suggested route");
                testFailed(str);
            }
            else if (VAPP_GESTURE_TEST_DISTANCE(event.downPos, event.pos) > m_distance)
            {
                VfxWString str = VFX_WSTR("Distance between pen down and pen up too long");
                testFailed(str);
            }
            else
            {
                frame->setBgColor(VAPP_GESTURE_TEST_COLOR_DONE);
                if (isTestFinished())
                {
                    testSuccess();
                }
            }
            break;
        }

        default:
            break;
        }

    return VappGestureTestBaseScr::onPenInput(event);
}


void VappGestureTestNudgeScr::onDraw(VfxDrawContext &dc)
{
    VfxU8 i;
    VfxPoint start, end;
    for (i = 0; i < VAPP_GESTURE_TEST_FRAMES; i++)
    {
        // draw arrow to show nudge direction
        start = convertPointFrom(m_testFrames[i]->getRect().getMidPoint(), m_testArea);
        switch (m_testRoute[i].dir)
        {
            case VAPP_GESTURE_TEST_DOWN:
                end = VfxPoint(start.x, start.y + 10);
                break;

            case VAPP_GESTURE_TEST_UP:
                end = VfxPoint(start.x, start.y - 10);
                break;

            case VAPP_GESTURE_TEST_RIGHT:
                end = VfxPoint(start.x + 10, start.y);
                break;

            case VAPP_GESTURE_TEST_LEFT:
                end = VfxPoint(start.x - 10, start.y);
                break;

            case VAPP_GESTURE_TEST_DOWNLEFT:
                end = VfxPoint(start.x - 10, start.y + 10);
                break;

            case VAPP_GESTURE_TEST_DOWNRIGHT:
                end = VfxPoint(start.x + 10, start.y + 10);
                break;

            case VAPP_GESTURE_TEST_UPLEFT:
                end = VfxPoint(start.x - 10, start.y - 10);
                break;

            case VAPP_GESTURE_TEST_UPRIGHT:
                end = VfxPoint(start.x + 10, start.y - 10);
                break;

            default:
                VFX_ASSERT(0);
        }
        drawArrow(dc, start, end);
    }
}

#endif /* __MMI_EM_MISC_TOUCH_SCREEN__ */

