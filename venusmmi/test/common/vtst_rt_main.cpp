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
 *  vtst_rt_main.cpp
 *
 * Project:
 * --------
 *  Venus Regression Test
 *
 * Description:
 * ------------
 *  
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
 * removed!
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
#include "vfx_config.h"

#ifndef __AFX_RT_TEST__

extern "C"
void vtst_rt_main_entry(void)
{
}

#else // __AFX_RT_TEST__

#include "vtst_rt_main.h"

extern "C"
{
#include "GlobalDefs.h"
#include "SettingProfileEnum.h"
#include "MMIDataType.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "Unicodexdcl.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "mmi_frm_history_gprot.h"
#include "GlobalConstants.h"
#include "string.h"
#include "DebugInitDef_Int.h"
#include "CustDataRes.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_categories_list.h"
#include "wgui_categories_text_viewer.h"

typedef void (*SoftkeyFuncPtr) (void);
typedef S32 MMI_key_event_type;

extern const U16 gIndexIconsImageList[];
extern void RegisterHighlightHandler(void (*f) (S32 item_index));
extern void SetLeftSoftkeyFunction(SoftkeyFuncPtr f, MMI_key_event_type k);
extern void SetRightSoftkeyFunction(SoftkeyFuncPtr f, MMI_key_event_type k);
extern void (*gui_start_timer) (S32 count, void (*callback) (void));

// Check if Keypad is in AT mode.
extern MMI_BOOL mmi_is_keypad_in_at_mode(void);
} // extern "C"

#include "vfx_datatype.h"
#include "vfx_app_cat_scr.h"
#include "vrt_system.h"
#include "vfx_cpp_base.h"
#include "vrt_datatype.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_string.h"
#include "vfx_text_frame.h"
#include "vfx_basic_type.h"
#include "vfx_font_desc.h"
#include "vfx_input_event.h"
#include "vfx_screen.h"
#include "vfx_app.h"
#include "vfx_class_info.h"
#include "vfx_signal.h"
#include "vfx_app_scr.h"
#include "vfx_control.h"

/***************************************************************************** 
 * Local Variable
 *****************************************************************************/

#define SCR_VTST_BASE       0x7F70
#define SCR_VTST_VSCR_BASE  0x7F80

static MMI_ID           g_vtst_rt_group_id = 0;
static VtstMenuStack    g_focusStack[10] = {0};
static int              g_focusStackTop  = -1;

#define TOP         (g_focusStack[g_focusStackTop])
#define TOPMENU     (g_focusStack[g_focusStackTop].menu)
#define TOPITEM     (TOPMENU->items[TOP.focusIdx])

#define SETTOP(_page)   do { TOP.menu = _page; TOP.focusIdx = 0; } while(0)

// Auto test stack
static VtstMenuStack    g_testStack[10] = {0};
static int              g_testStackTop  = -1;

#define VTST_LOG_LENGTH 1024
static U16              g_testLog[VTST_LOG_LENGTH] = {0};

// Test Venus Screen
IVtstRtScreenInterface *g_rt_testcase = NULL;
mmi_id                  g_cat_id;

// max RT menu item count
#define RT_MENU_MAX_ITEM_COUNT  64


/***************************************************************************** 
 * Predeclaration
 *****************************************************************************/
extern VtstTestResultEnum vtst_rt_menu_enter(VfxU32 param);
extern VtstTestResultEnum vtst_rt_auto_test(VfxU32 param);

extern U8 vtst_rt_menu_del_scrn_cb(void *ptr);

// This is main entry function for menu
extern void vtst_rt_menu_entry(void);

// This is exit function for menu
extern void vtst_rt_menu_exit(void);

// Our GoBack, this will decrease the top index
extern void vtst_rt_goback(void);

// high light handler for main menu
extern void vtst_rt_menu_highlight_handler(
    S32 index   // [IN] the highlight index
);

// Do action when click item
extern void vtst_rt_menu_action(void);
extern void vtst_rt_menu_doaction(const VtstMenuItem* item);


/***************************************************************************** 
 * Autotest Item Predeclaration
 *****************************************************************************/

// For easing add test items, we split this file into another file.
#include "vtst_rt.h"


/***************************************************************************** 
 * Autotest Item Implementation
 *****************************************************************************/

static mmi_ret vtst_rt_menu_group_proc(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}


extern "C"
void vtst_rt_main_entry(void)
{
    // Exit if entering in ART test. (Will exit form here when any key command is received from Catcher)
#ifdef __MMI_TOUCH_SCREEN__
    if(mmi_is_keypad_in_at_mode() || mmi_pen_is_in_at_mode())
#else
    if(mmi_is_keypad_in_at_mode())
#endif
    {
        return;
    }

    g_testStackTop = -1;
    g_focusStackTop = 0; // init value

    SETTOP(&VTST_MENU(main));
    
    g_vtst_rt_group_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, vtst_rt_menu_group_proc, NULL);
    mmi_frm_group_enter(g_vtst_rt_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    vtst_rt_menu_entry();
}


extern "C"
MMI_ID vapp_rt_launch(void *param, U32 param_size)
{
    vtst_rt_main_entry();
    return MMI_RET_OK;
}


void vtst_rt_entry(void)
{
    U16 screenID = (U16)(SCR_VTST_VSCR_BASE + g_testStackTop);
    if (!mmi_frm_scrn_enter(g_vtst_rt_group_id, screenID, vtst_rt_leave, NULL, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    ASSERT(g_rt_testcase == NULL);

    VfxAppCatScr::initalize();
}


void vtst_rt_entry_rotate(void)
{
    U16 screenID = (U16)(SCR_VTST_VSCR_BASE + g_testStackTop);
    if (!mmi_frm_scrn_enter(g_vtst_rt_group_id, screenID, vtst_rt_leave, NULL, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    ASSERT(g_rt_testcase == NULL);
    
    vrt_sys_set_screen_rotation(VRT_SYS_SCREEN_ROTATE_270);
    
    VfxAppCatScr::initalize();
}


void vtst_rt_leave(void)
{
    /*
     * Leave the screen
     */
    if (g_cat_id && g_rt_testcase)
    {
        g_rt_testcase->testEnd();
        vtst_testcase_end();
    }
}


void vtst_rt_verify(void)
{
    if (g_rt_testcase)
    {
        if (g_rt_testcase->getTestResult())
        {
            mmi_wcsncat(g_testLog, (const WCHAR *)L" OK\n", VTST_LOG_LENGTH);
        }
        else
        {
            mmi_wcsncat(g_testLog, (const WCHAR *)L"\n", VTST_LOG_LENGTH);
        }

        if (g_testStackTop < 0)
        {
            vtst_rt_autotest_result_entry();
        }
        else
        {
            vtst_rt_autotest_trigger();
        }
    }
    // After verify the result, we can end the test case 
    if (g_rt_testcase)
    {
        g_rt_testcase->testEnd();
        vtst_testcase_end();
    }
}


void vtst_testcase_start(IVtstRtScreenInterface* testcase, VfxBool isCategory)
{
    ASSERT(g_rt_testcase == NULL);
    g_rt_testcase = testcase;
    g_rt_testcase->testStart();
    if (isCategory)
    {
        g_cat_id = SCR_VTST_VSCR_BASE + g_testStackTop;
    }
    else
    {
        g_cat_id = 0;
    }
}


void vtst_testcase_end()
{
    g_rt_testcase = NULL;
    g_cat_id = 0;
}


void vtst_add_fail_log(const VfxWChar *testName)
{
    mmi_wcsncat(g_testLog, (const WCHAR *)L"\n  ", VTST_LOG_LENGTH);
    mmi_wcsncat(g_testLog, (const WCHAR *)testName, VTST_LOG_LENGTH);
    mmi_wcsncat(g_testLog, (const WCHAR *)L": fail", VTST_LOG_LENGTH);
}


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

void vtst_rt_testcase_step(void)
{
    if (g_rt_testcase)
    {
        g_rt_testcase->step();
    }
}


void vtst_rt_autotest_step(void)
{
    // All item is completed
    if (g_testStackTop < 0)
    {
        vtst_rt_autotest_trigger(); 
        return;
    }

    VtstMenuStack* top = &g_testStack[g_testStackTop];
    
    // This item has completed
    if (top->focusIdx >= top->menu->count)
    {
        g_testStackTop--;
        vtst_rt_autotest_trigger(); 
        return;
    }
    
    if (top->menu->items[top->focusIdx].tt == VTST_TT_TEST)
    {
        // Do test item, don't triggle step, the test item will do it later
        vtst_rt_menu_doaction(&top->menu->items[top->focusIdx]);
    }
    else if (top->menu->items[top->focusIdx].tt == VTST_TT_MENU)
    {
        // enter next sub menu
        g_testStackTop += 1;
        g_testStack[g_testStackTop].menu = (const VtstMenu*)top->menu->items[top->focusIdx].param;
        g_testStack[g_testStackTop].focusIdx = 0;

        mmi_wcsncat(g_testLog, (const WCHAR *)L"[ ", VTST_LOG_LENGTH);
        mmi_wcsncat(g_testLog, (const WCHAR *)g_testStack[g_testStackTop].menu->title, VTST_LOG_LENGTH);
        mmi_wcsncat(g_testLog, (const WCHAR *)L" ]\n", VTST_LOG_LENGTH);
        
        vtst_rt_autotest_trigger();
    }

    top->focusIdx += 1;
}


void vtst_rt_autotest_result_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  *guiBuffer;
    U16 screenID = SCR_VTST_VSCR_BASE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (!mmi_frm_scrn_enter(g_vtst_rt_group_id, screenID, NULL, vtst_rt_autotest_result_entry, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    ShowCategory74Screen(
        STR_GLOBAL_CONTENT,
        0,
        0, //STR_GLOBAL_OK,
        0, //IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*)g_testLog,
        mmi_wcslen(g_testLog),
        guiBuffer
    );

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


void vtst_rt_autotest_trigger(void)
{
    if (g_testStackTop < 0)
    {
        // All test item is completed
        vtst_rt_autotest_result_entry();
        return;
    }
    gui_start_timer(0, vtst_rt_autotest_step);
}


void vtst_rt_autotest_start(const VtstMenu* list)
{
    //WCHAR* local_category_name[100] = {0};
    //kal_wsprintf(local_category_name, "%w[%w]", category_name, list->title);


    memset(g_testLog, NULL, VTST_LOG_LENGTH * 2);
    g_testStack[0].menu = list;
    g_testStack[0].focusIdx = 0;
    g_testStackTop  = 0;
    vtst_rt_autotest_step();
}


VtstTestResultEnum vtst_rt_auto_test(VfxU32 param)
{
    const VtstMenu* list = reinterpret_cast<const VtstMenu*>(param);
    vtst_rt_autotest_start(list);
    return VTST_TR_OK;
}


VtstTestResultEnum vtst_rt_menu_enter(VfxU32 param)
{
    g_focusStackTop++;
    VtstMenu* page = reinterpret_cast<VtstMenu*>(param);
    SETTOP(page);

    vtst_rt_menu_entry();

    return VTST_TR_OK;
}


U8 vtst_rt_menu_del_scrn_cb(void *ptr)
{
    return MMI_HIST_ALLOW_DELETING;
}


static void vtst_rt_menu_entry_ext()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16         screenID;
    U8          *guiBuffer;
    const WCHAR *nStrItemList[RT_MENU_MAX_ITEM_COUNT];
    PU8         nIcoItemList[RT_MENU_MAX_ITEM_COUNT];    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    screenID = (U16)(SCR_VTST_BASE + g_focusStackTop);
    if (!mmi_frm_scrn_enter(g_vtst_rt_group_id, screenID, vtst_rt_menu_exit, vtst_rt_menu_entry_ext, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    MMI_ASSERT(TOPMENU->count <= RT_MENU_MAX_ITEM_COUNT);
    for (int i = 0; i < TOPMENU->count; i++)
    {
        nStrItemList[i] = TOPMENU->items[i].title;
        nIcoItemList[i] = (PU8)GetImage(gIndexIconsImageList[i]);
    }

    RegisterHighlightHandler(vtst_rt_menu_highlight_handler);
    ShowCategory170Screen(
        (U8*) TOPMENU->title,
        0,
        (PU8) GetString(STR_GLOBAL_OK),
        (PU8) GetImage(IMG_GLOBAL_OK),
        (PU8) GetString(STR_GLOBAL_BACK),
        (PU8) GetImage(IMG_GLOBAL_BACK),
        TOPMENU->count,
        (PU8*) nStrItemList,
        (PU8*) nIcoItemList,
        0,
        TOP.focusIdx,
        guiBuffer);

    SetRightSoftkeyFunction(vtst_rt_goback, KEY_EVENT_UP);
    SetKeyHandler(vtst_rt_goback, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(vtst_rt_menu_action, KEY_EVENT_UP);
}


void vtst_rt_menu_entry()
{
    U16 screenID = (U16)(SCR_VTST_BASE + g_focusStackTop);

    mmi_frm_scrn_first_enter(g_vtst_rt_group_id, screenID, vtst_rt_menu_entry_ext, NULL);
}


void vtst_rt_goback(void)
{
    g_focusStackTop--;
    mmi_frm_scrn_close_active_id();
}


void vtst_rt_menu_exit(void)
{
}


void vtst_rt_menu_highlight_handler(S32 index)
{
    TOP.focusIdx = (int)index;
}


void vtst_rt_menu_action(void)
{
    // Out of index range
    VFX_DEV_ASSERT(TOP.focusIdx >= 0 && TOP.focusIdx < TOPMENU->count);
    
    memset(g_testLog, NULL, VTST_LOG_LENGTH * 2);
    vtst_rt_menu_doaction(&TOPITEM);
}


void vtst_rt_menu_doaction(const VtstMenuItem* item)
{
    kal_uint32 preTick = 0, tick = 0;

    mmi_wcsncat(g_testLog, (const WCHAR *)item->title, VTST_LOG_LENGTH);
    mmi_wcsncat(g_testLog, (const WCHAR *)L":", VTST_LOG_LENGTH);

    kal_get_time(&preTick);
    item->testFuncPtr(item->param);
    kal_get_time(&tick);

    tick -= preTick;
}


/*****************************************************************************
 * Class VtstRtScr
 *****************************************************************************/

VtstRtScr::VtstRtScr() : 
    m_title(NULL), 
    m_status(NULL), 
    m_message(NULL),
    m_yes(NULL),
    m_no(NULL),
    m_fail(VFX_FALSE),
    m_phaseCount(0), 
    m_phase(0), 
    m_phasePendding(VFX_FALSE), 
    m_waitConfirm(VFX_FALSE)
{
}


void VtstRtScr::testStart()
{
    VfxS32 phase = start();
    m_phaseCount = phase;
    m_phase = 0;
    m_phasePendding = VFX_FALSE;
    
    gui_start_timer(0, vtst_rt_testcase_step);
}


void VtstRtScr::testEnd()
{
    VtstRtScr* _this = this;
    VFX_OBJ_CLOSE(_this);
    
    VfxAppCatScr::deinitalize();
}


void VtstRtScr::step()
{
    if (m_phaseCount > 0 && m_phase >= m_phaseCount)
    {
        end();
        vtst_rt_verify();
        return;
    }

    VfxS32 timeout = phase(m_phase);

    if (timeout == VTST_RT_END_TESTCASE)
    {
        end();
        vtst_rt_verify();
        return;
    }

    m_phase += 1;
    if (timeout >= 0)
    {
        gui_start_timer(timeout, vtst_rt_testcase_step);
    }
    else
    {
        m_phasePendding = VFX_TRUE;
    }
}


void VtstRtScr::endPhase()
{
    if (m_phasePendding)
    {
        gui_start_timer(0, vtst_rt_testcase_step);
        m_phasePendding = VFX_FALSE;
    }
}


VfxBool VtstRtScr::check(bool statement, const VfxWString &testName)
{
    if (!statement)
    {
        fail();
        vtst_add_fail_log(testName.getBuf());
        return VFX_FALSE;
    }
    return VFX_TRUE;
}


void VtstRtScr::confirm(const VfxWString &message)
{
    if (m_message == NULL)
    {
        VFX_OBJ_CREATE(m_message, VfxTextFrame, this);
        m_message->setAutoResized(VFX_FALSE);
        m_message->setColor(VFX_COLOR_BLACK);
        m_message->setBgColor(VFX_COLOR_GREY);
        m_message->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        m_message->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_message->setFont(VFX_FONT_DESC_SMALL);
        m_message->setAutoAnimate(VFX_TRUE);
    }    
    m_message->setString(message);

    if (m_yes == NULL)
    {
        VFX_OBJ_CREATE(m_yes, VfxTextFrame, this);
        m_yes->setColor(VFX_COLOR_BLACK);
        m_yes->setBgColor(VFX_COLOR_GREY);
        m_yes->setString(VFX_WSTR("YES"));
        m_yes->setAutoAnimate(VFX_TRUE);
    }

    if (m_no == NULL)
    {
        VFX_OBJ_CREATE(m_no, VfxTextFrame, this);
        m_no->setColor(VFX_COLOR_BLACK);
        m_no->setBgColor(VFX_COLOR_GREY);
        m_no->setString(VFX_WSTR("NO"));
        m_no->setAutoAnimate(VFX_TRUE);
    }

    layout();
    
    m_waitConfirm = VFX_TRUE;
}


VfxBool VtstRtScr::onKeyInput(VfxKeyEvent &event)
{
    if (m_waitConfirm && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        if (event.keyCode == VFX_KEY_CODE_LSK)
        {
            endPhase();
            return VFX_TRUE;
        }
        else if (event.keyCode == VFX_KEY_CODE_RSK)
        {
            check(VFX_FALSE, VFX_WSTR("User confirm"));
            endPhase();
            return VFX_TRUE;
        }
    }
    
    return VfxAppCatScr::onKeyInput(event);
}


VfxBool VtstRtScr::onPenInput(VfxPenEvent &event)
{
    if (m_waitConfirm && event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        VfxPoint point = convertPointTo(event.pos, m_yes);
        if (m_yes->getBounds().contains(point))
        {
            endPhase();
            return VFX_TRUE;
        }

        point = convertPointTo(event.pos, m_no);
        if (m_no->getBounds().contains(point))
        {
            check(VFX_FALSE, VFX_WSTR("User confirm"));
            endPhase();
            return VFX_TRUE;
        }
    }
    return VfxAppCatScr::onPenInput(event);
}


void VtstRtScr::onInit()
{
    VfxAppCatScr::onInit();

    // Set background color
    setBgColor(VFX_COLOR_BLUE);

    // Add text frame to screen
    VFX_OBJ_CREATE(m_title, VfxTextFrame, this);

    VFX_OBJ_CREATE(m_status, VfxTextFrame, this);
    
    layout();
}


void VtstRtScr::onRotate(const VfxScreenRotateParam &param)
{
    VfxAppCatScr::onRotate(param);
        
    layout();
}


void VtstRtScr::layout()
{
    VFX_DEV_ASSERT(m_title != NULL);
    VFX_DEV_ASSERT(m_status != NULL);
    
    VfxSize scrSize = getSize();
        
    m_title->setPos(10, 10);
    m_status->setPos(10, 30);    

    if (m_message != NULL)
    {
        m_message->setPos(0, scrSize.height - 60);
        m_message->setSize(scrSize.width, 40);
    }

    if (m_yes != NULL)
    {
        m_yes->setPos(10, scrSize.height - 20);    
    }

    if (m_no != NULL)
    {
        m_no->setPos(3 * (scrSize.width / 4), scrSize.height - 20);
    }
}


#ifdef __COSMOS_MMI_PACKAGE__
/***************************************************************************** 
 * Class VtstRtApp
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("RtApp", VtstRtApp, VfxApp);

VtstRtApp::VtstRtApp() : 
    m_fail(VFX_FALSE), 
    m_phaseCount(0), m_phase(0), m_phasePendding(VFX_FALSE), 
    m_waitConfirm(VFX_FALSE)
{
    memset(&m_startupParam, 0, sizeof(VtstRtAppStartupParam));
}


VtstRtApp::~VtstRtApp() 
{
    vtst_testcase_end();
}


void VtstRtApp::onRun(void* args, VfxU32 argSize)
{
    ASSERT(argSize == sizeof(VtstRtAppStartupParam));
    VtstRtAppStartupParam* pStartupParam = (VtstRtAppStartupParam*) args;
    m_startupParam = *pStartupParam;
}


void VtstRtApp::onInit()
{
    VfxApp::onInit();
}


void VtstRtApp::onDeinit()
{
    VfxApp::onDeinit();
}


void VtstRtApp::fail()
{
    m_fail = VFX_TRUE;
}


VfxBool VtstRtApp::check(VfxBool statement, const VfxWString &testName)
{
    if (!statement)
    {
        fail();
        vtst_add_fail_log(testName.getBuf());
        return VFX_FALSE;
    }
    return VFX_TRUE;
}


void VtstRtApp::step()
{
    if (m_phaseCount > 0 && m_phase >= m_phaseCount)
    {
        end();
        vtst_rt_verify();
        return;
    }

    VfxS32 timeout = phase(m_phase);

    if (timeout == VTST_RT_END_TESTCASE)
    {
        end();
        vtst_rt_verify();
        return;
    }

    m_phase += 1;
    if (timeout >= 0)
    {
        gui_start_timer(timeout, vtst_rt_testcase_step);
    }
    else
    {
        m_phasePendding = VFX_TRUE;
    }
}


void VtstRtApp::endPhase()
{
    if (m_phasePendding)
    {
        gui_start_timer(0, vtst_rt_testcase_step);
        m_phasePendding = VFX_FALSE;
    }
}


void VtstRtApp::testStart()
{
    VfxS32 phase = start();
    m_phaseCount = phase;
    m_phase = 0;
    m_phasePendding = VFX_FALSE;
    gui_start_timer(0, vtst_rt_testcase_step);
}


void VtstRtApp::testEnd()
{
    //VfxContext* pContext = m_startupParam.context;
    //VfxU8*      pBuffer = m_startupParam.buffer;

    VtstRtApp* _this = this;
    _this->exit();
    vtst_testcase_end();
    
    //VFX_OBJ_CLOSE(pContext);
    //media_free_ext_buffer(stack_int_get_active_module_id(), (void**)&pBuffer);
}


/***************************************************************************** 
 * Test bed for app screen
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("RtAppScrBasic", VtstRtAppScr, VfxAppScr);

VtstRtAppScr::VtstRtAppScr() : m_bSerializable(VFX_FALSE) 
{
}


void VtstRtAppScr::onInit()
{
    VfxAppScr::onInit();

    // Set background color
    setBgColor(VFX_COLOR_BLUE);

    // Add text frame to screen
    VFX_OBJ_CREATE(m_title, VfxTextFrame, this);
    m_title->setPos(VfxPoint(10, 10));
    m_title->setString(VFX_WSTR("VtstRtAppScr"));

    VFX_OBJ_CREATE(m_status, VfxTextFrame, this);
    m_status->setPos(VfxPoint(10, 30));
    m_status->setString(VFX_WSTR("..."));
}


VfxBool VtstRtAppScr::onSerialize(VfxArchive &ar)
{
    VFX_UNUSED(ar);

    return m_bSerializable;
}


void VtstRtAppScr::onRestore(VfxArchive &ar)
{
    VFX_UNUSED(ar);
}


void VtstRtAppScr::setTitle(const VfxWString &title)
{
    m_title->setString(title);
}


void VtstRtAppScr::setStatus(const VfxWString &status)
{
    m_status->setString(status);
}


void VtstRtAppScr::confirm(const VfxWString &message, VtstRtAppScrConfirmCB cb)
{
    // Create a text
    VfxTextFrame     *controlText;
    VfxWString display(message);

    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;
    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

    VFX_OBJ_CREATE(controlText, VfxTextFrame, this);
    controlText->setPos(VfxPoint(0, main_screen_size.height - 60));
    controlText->setBounds(VfxRect(0, 0, main_screen_size.width, 40));
    controlText->setColor(VFX_COLOR_BLACK);
    controlText->setBgColor(VFX_COLOR_GREY);
    controlText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    controlText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    controlText->setString(message);

    VFX_OBJ_CREATE(controlText, VfxTextFrame, this);
    controlText->setPos(VfxPoint(10, main_screen_size.height - 20));
    controlText->setColor(VFX_COLOR_BLACK);
    controlText->setBgColor(VFX_COLOR_GREY);
    controlText->setString(VFX_WSTR("YES"));

    VFX_OBJ_CREATE(controlText, VfxTextFrame, this);
    controlText->setPos(VfxPoint(3 * (main_screen_size.width / 4), main_screen_size.height - 20));
    controlText->setColor(VFX_COLOR_BLACK);
    controlText->setBgColor(VFX_COLOR_GREY);
    controlText->setString(VFX_WSTR("NO"));

    m_confirmCB = cb;
}


VfxBool VtstRtAppScr::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        if (event.keyCode == VFX_KEY_CODE_LSK)
        {
            m_confirmCB.invoke(this, VFX_TRUE);
            return VFX_TRUE;
        }
        else if (event.keyCode == VFX_KEY_CODE_RSK)
        {
            m_confirmCB.invoke(this, VFX_FALSE);
            return VFX_TRUE;
        }
    }
    return VfxAppScr::onKeyInput(event);
}
#endif


/***************************************************************************** 
 * Dummy Test Implementation
 *****************************************************************************/

class VtstRtDummy : public VtstRtScr
{
// Constructor / Destructor
public:
    VtstRtDummy() {}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("Dummy Test"));
    }

    virtual int start()
    {
        check(VFX_FALSE, VFX_WSTR("Not yet implement"));
        return 0;
    }

    virtual VfxS32 phase(VfxS32 idx)
    { 
        return VTST_RT_END_TESTCASE; 
    }

    virtual void end()
    {
    }
};

VtstTestResultEnum vtst_rt_dummy(VfxU32 param)
{
    VTST_START_SCRN(VtstRtDummy);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * Hittest Test Implementation
 *****************************************************************************/

class VtstRtHittest : public VtstRtScr
{
    class VfxMyControl : public VfxControl
    {
    public:
        VfxBool m_hitable;
        virtual void onInit()
        {
            VfxControl::onInit();
            m_hitable = VFX_FALSE;
        }

        virtual VfxBool onPenInput(VfxPenEvent &event)
        {
            VtstRtHittest* scr = (VtstRtHittest*) getParentFrame();
            scr->check(m_hitable, VFX_WSTR("Hit test"));
            if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
            {
                scr->endPhase();
            }
            return VFX_TRUE;
        }
        
        virtual VfxBool onContainPoint(const VfxPoint &point) const
        {
            if (!m_hitable)
                return VFX_FALSE;
            return VfxControl::onContainPoint(point);
        }

        void setHitable(VfxBool v) { m_hitable = v; }
    };

// Variable
public:
    VfxMyControl *m_testCtl1, *m_testCtl2;

// Constructor / Destructor
public:
    VtstRtHittest() : m_testCtl1(NULL), m_testCtl2(NULL) {}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("Hitest Test"));
    }

    void onVfxMyControl2PenInput(VfxControl* sender, VfxPenEvent &event, VfxBool &handled)
    {
        handled = VFX_TRUE; // TO block the control's pen input
        if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
        {
            endPhase();
        }
    }

    virtual int start()
    {      
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        if (idx == 0)
        {
            setStatus(VFX_WSTR("Please hit box"));

            // Create a color rectangle
            VFX_OBJ_CREATE(m_testCtl1, VfxMyControl, this);
            m_testCtl1->setPos(VfxPoint(120, 200));
            m_testCtl1->setBounds(VfxRect(0, 0, 100, 100));
            m_testCtl1->setAnchor(VfxFPoint(0.5, 0.5));
            m_testCtl1->setBgColor(VFX_COLOR_RED);
        
            VFX_OBJ_CREATE(m_testCtl2, VfxMyControl, this);
            m_testCtl2->setPos(VfxPoint(120, 200));
            m_testCtl2->setBounds(VfxRect(0, 0, 100, 100));
            m_testCtl2->setAnchor(VfxFPoint(0.5, 0.5));
            m_testCtl2->setBgColor(VFX_COLOR_RED);

            // we cannot complete the test since there is no way to overwrite hittest
            m_testCtl1->setHitable(VFX_TRUE);
            m_testCtl2->setHitable(VFX_FALSE);
        }
        return -1;
    }
};

VtstTestResultEnum vtst_rt_hittest(VfxU32 param)
{
    VTST_START_SCRN(VtstRtHittest);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * Focus Test Implementation
 *****************************************************************************/

class VtstRtFocus : public VtstRtScr
{

    class MyObj : public VfxControl
    {
    public:
        VfxBool m_latestFocusedValue;
        VfxS32  m_keyCount;

        virtual void onInit()
        {
            VfxControl::onInit();
            m_latestFocusedValue = VFX_FALSE;
            m_keyCount = 0;
        }

        virtual void onFocusChanged(VfxBool value)
        {
            m_latestFocusedValue = value;
        }

        void verify(VtstRtScr *scr, VfxBool value)
        {
            scr->check(m_latestFocusedValue == getFocused(), VFX_WSTR("Focus State"));
            scr->check(value == getFocused(), VFX_WSTR("Expect Focus State"));
        }
    };

// Variable
public:
    /*   
     *            / F
     *           D
     *          / \ G
     *         B 
     *        / \ / H
     *       /   E
     *     A      \ I
     *       \
     *        \
     *         C
     */
    

    MyObj       *m_pA, *m_pB, *m_pC, *m_pD, *m_pE;
    MyObj       *m_pF, *m_pG, *m_pH, *m_pI;


// Constructor / Destructor
public:
    VtstRtFocus() {}

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("Focus Test"));
        
        VFX_OBJ_CREATE(m_pA, MyObj, this);
        VFX_OBJ_CREATE(m_pB, MyObj, m_pA);
        VFX_OBJ_CREATE(m_pC, MyObj, m_pA);
        VFX_OBJ_CREATE(m_pD, MyObj, m_pB);
        VFX_OBJ_CREATE(m_pE, MyObj, m_pB);
        VFX_OBJ_CREATE(m_pF, MyObj, m_pD);
        VFX_OBJ_CREATE(m_pG, MyObj, m_pD);
        VFX_OBJ_CREATE(m_pH, MyObj, m_pE);
        VFX_OBJ_CREATE(m_pI, MyObj, m_pE);
    }

    virtual int start()
    {
        m_pG->setFocused(VFX_TRUE);
        m_pA->verify(this, VFX_TRUE);
        m_pB->verify(this, VFX_TRUE);
        m_pC->verify(this, VFX_FALSE);
        m_pD->verify(this, VFX_TRUE);
        m_pE->verify(this, VFX_FALSE);
        m_pF->verify(this, VFX_FALSE);
        m_pG->verify(this, VFX_TRUE);
        m_pH->verify(this, VFX_FALSE);
        m_pI->verify(this, VFX_FALSE);

        m_pI->setFocused(VFX_TRUE);
        m_pA->verify(this, VFX_TRUE);
        m_pB->verify(this, VFX_TRUE);
        m_pC->verify(this, VFX_FALSE);
        m_pD->verify(this, VFX_FALSE);
        m_pE->verify(this, VFX_TRUE);
        m_pF->verify(this, VFX_FALSE);
        m_pG->verify(this, VFX_FALSE);
        m_pH->verify(this, VFX_FALSE);
        m_pI->verify(this, VFX_TRUE);

        return 0;
    }
    
    virtual VfxS32 phase(VfxS32 idx)
    {
        if (idx == 0)
        {
            // make it very short
            // Post Emit should be process before timer
            return 1; 
        }
        return VTST_RT_END_TESTCASE;
    }

    virtual void end()
    {
    }


};

VtstTestResultEnum vtst_rt_focus(VfxU32 param)
{
    VTST_START_SCRN(VtstRtFocus);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

