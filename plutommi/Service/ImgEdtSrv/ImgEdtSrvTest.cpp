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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  ImgEdtSrvTest.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Testbed of Image Editing service
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

#ifdef __MMI_SRV_IES__
#ifdef SRV_IES_TESTBED_ENABLE

#include "ImgEdtSrvTest.h"

extern "C"
{
#include "CommonScreens.h"
#include "gdi_primitive.h"
#include "wgui_categories_util.h"

extern void (*gui_start_timer) (S32 count, void (*callback) (void));
}

/***************************************************************************** 
 * Base class implementation for testing
 *****************************************************************************/
U8                      IESTestItem::s_testMemPool[SRV_IES_TST_MEM_POOL_SIZE] = { 0 };
bool                    IESTestItem::s_testMemUsed  = false;
IESTestItem             *IESTestItem::s_pCurTest    = NULL;

/***************************************************************************** 
 * Global variables for auto testing
 *****************************************************************************/
static IESTestBase      *g_rt_cur_test = NULL;
static mmi_id           g_rt_cat_ID;
static IESTestMenuStack g_testStack[SRV_IES_TST_MENU_MAX_DEPTH] = { 0 };
static int              g_testStackTop  = -1;
static U16              g_testLog[SRV_IES_TST_LOG_MAX_LENGTH] = { 0 };
static void             *g_testBuf  = NULL;
static gdi_handle       g_testLayer = NULL;


/***************************************************************************** 
 * Auto test mechanism implementation
 *****************************************************************************/
static void _srv_ies_tst_on_finish_draw_result(void)
{
    S32             srcWidth;
    S32             srcHeight;
    S32             dstWidth;
    S32             dstHeight;
    S32             offsetX;
    S32             offsetY;

    if(g_testLayer)
    {
        gdi_layer_get_dimension(&srcWidth, &srcHeight);
        gdi_layer_push_and_set_active(g_testLayer);
        gdi_layer_get_dimension(&dstWidth, &dstHeight);
        offsetX = (srcWidth  - dstWidth)  / 2;
        offsetY = (srcHeight - dstHeight) / 2;
        gdi_layer_pop_and_restore_active();

        gdi_bitblt_resized(g_testLayer,
                           0,
                           0,
                           dstWidth,
                           dstHeight,
                           offsetX,
                           offsetY,
                           dstWidth,
                           dstHeight);
    }
}


static void _srv_ies_tst_on_finish_view_result(void)
{
    // Clear testing result
    if(NULL != g_testLayer)
    {
        gdi_layer_free(g_testLayer);
        g_testLayer = NULL;
    }

    GoBackHistory();
}


void srv_ies_tst_rt_auto_test_end(void)
{
#if !defined(__COSMOS_MMI_PACKAGE__)
    U16 screenID;

    screenID = SCR_SRV_IES_TST_VSCR_BASE;
    
    mmi_frm_scrn_enter(GRP_ID_ROOT, screenID, NULL, srv_ies_tst_rt_auto_test_end, MMI_FRM_FULL_SCRN);
    // If there is a resulting layer,
    // draw the pixel buffer output
    if(NULL != g_testLayer)
    {
        ShowCategory221Screen(STR_GLOBAL_OK,
                              NULL,
                              0,  //STR_GLOBAL_OK,
                              0,  //IMG_GLOBAL_OK,
                              STR_GLOBAL_BACK,
                              IMG_GLOBAL_BACK,
                              GDI_COLOR_BLACK,
                              _srv_ies_tst_on_finish_draw_result);

        SetRightSoftkeyFunction(_srv_ies_tst_on_finish_view_result, KEY_EVENT_UP);
    }
    else 
    {
        // Text log output
        ShowCategory74Screen(STR_GLOBAL_CONTENT,
                             0,
                             0,  //STR_GLOBAL_OK,
                             0,  //IMG_GLOBAL_OK,
                             STR_GLOBAL_BACK,
                             IMG_GLOBAL_BACK,
                             (U8*)g_testLog,
                             mmi_wcslen(g_testLog),
                             mmi_frm_scrn_get_active_gui_buf());

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }  
#endif  // !defined(__COSMOS_MMI_PACKAGE__)
}


void srv_ies_tst_rt_auto_test_trigger(void)
{
    if (g_testStackTop < 0)
    {
        // All test item is completed
        srv_ies_tst_rt_auto_test_end();
        return;
    }

    gui_start_timer(0, srv_ies_tst_rt_auto_test_step);
}

void srv_ies_tst_rt_auto_test_step(void)
{
    IESTestMenuStack *pTop;

    // All item is completed
    if (g_testStackTop < 0)
    {
        srv_ies_tst_rt_auto_test_trigger(); 
        return;
    }

    pTop = &g_testStack[g_testStackTop];

    // This item has completed
    if (pTop->focusID >= pTop->menu->count)
    {
        g_testStackTop--;
        srv_ies_tst_rt_auto_test_trigger(); 
        return;
    }

    if (SRV_IES_TST_TT_TEST == pTop->menu->items[pTop->focusID].type)
    {
        // Do test item, don't triggle step, the test item will do it later
        srv_ies_tst_rt_menu_run(&pTop->menu->items[pTop->focusID]);
    }
    else
    {
        // Enter next sub menu
        g_testStackTop += 1;
        g_testStack[g_testStackTop].menu    = (const IESTestMenu*)pTop->menu->items[pTop->focusID].param;
        g_testStack[g_testStackTop].focusID = 0;

        mmi_wcsncat(g_testLog, (WCHAR*)L"[ ", SRV_IES_TST_LOG_MAX_LENGTH);
        mmi_wcsncat(g_testLog, g_testStack[g_testStackTop].menu->title, SRV_IES_TST_LOG_MAX_LENGTH);
        mmi_wcsncat(g_testLog, (WCHAR*)L" ]\n", SRV_IES_TST_LOG_MAX_LENGTH);
        
        srv_ies_tst_rt_auto_test_trigger();
    }
}


void srv_ies_tst_rt_auto_test_start(const IESTestMenu    *pList)
{
    memset(g_testLog, NULL, SRV_IES_TST_LOG_MAX_LENGTH * 2);

    g_testStack[0].menu     = pList;
    g_testStack[0].focusID  = 0;

    g_testStackTop  = 0;

    srv_ies_tst_rt_auto_test_step();
}


/***************************************************************************** 
 * Base class implementation for testing
 *****************************************************************************/
void srv_ies_tst_rt_leave(void)
{
    /*
     * Leave the screen
     */
    if ((0 != g_rt_cat_ID) && (NULL != g_rt_cur_test))
    {
        g_rt_cur_test->testEnd();
        srv_ies_tst_rt_end();
    }
}


void srv_ies_tst_rt_enter(void)
{
#if !defined(__COSMOS_MMI_PACKAGE__)
    mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_SRV_IES_TST_VSCR_BASE + g_testStackTop, srv_ies_tst_rt_leave, NULL, MMI_FRM_FULL_SCRN);
    ASSERT(g_rt_cur_test == NULL);

#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    gui_screen_switch_effect_force_block(MMI_TRUE);
#endif
    ShowCategory66Screen(
        0,
        0,
        0,
        0,
        0,
        0,
        (PU8)GetString(STR_GLOBAL_PLEASE_WAIT),
        IMG_GLOBAL_PROGRESS,
        NULL);
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    gui_screen_switch_effect_force_block(MMI_FALSE);
#endif
#endif  // !defined(__COSMOS_MMI_PACKAGE__)
}


void srv_ies_tst_rt_start(IESTestBase  *pTestObject,
                          U32           caseID,
                          MMI_BOOL      isCategory)
{
    ASSERT(NULL == g_rt_cur_test);

    g_rt_cur_test = pTestObject;
    g_rt_cur_test->testStart(caseID);

    if (MMI_TRUE == isCategory)
    {
        g_rt_cat_ID = SCR_SRV_IES_TST_VSCR_BASE + g_testStackTop;
    }
    else
    {
        g_rt_cat_ID = 0;
    }
}


void srv_ies_tst_rt_end(void)
{
    if (NULL != g_rt_cur_test)
    {
        g_rt_cur_test->testReport(g_testLog);
        
        g_rt_cur_test->testEnd();
        g_rt_cur_test = NULL;
        g_rt_cat_ID   = 0;

        if (g_testStackTop < 0)
        {
            srv_ies_tst_rt_auto_test_end();
        }
        else
        {
            srv_ies_tst_rt_auto_test_trigger();
        }
    }
}


/***************************************************************************** 
 * Auto test Item pre-declaration
 *****************************************************************************/
// For easing add test items, we split this file into another file.
#include "ImgEdtSrvTestTable.h"

/***************************************************************************** 
 * Autotest Item Mechanism Implementation
 *****************************************************************************/
#define TOPMENU                     (g_focusStack[g_focusStackTop].menu)
#define TOP                         (g_focusStack[g_focusStackTop])
#define SETTOP(_page)               do { TOP.menu = _page; TOP.focusID = 0; } while(0)

static IESTestMenuStack             g_focusStack[SRV_IES_TST_MENU_MAX_DEPTH] = {0};
static S32                          g_focusStackTop  = -1;


void srv_ies_tst_rt_menu_exit(void)
{
}



void srv_ies_tst_rt_menu_highlight_cb(S32 index)
{
    TOP.focusID = (S32)index;
}


void srv_ies_tst_rt_goback(void)
{
    g_focusStackTop--;
    GoBackHistory();
}


void srv_ies_tst_rt_menu_run(const IESTestMenuItem *pItem)
{
    kal_uint32          preTick;
    kal_uint32          duration;

    mmi_wcsncat(g_testLog, pItem->title, SRV_IES_TST_LOG_MAX_LENGTH);
    mmi_wcsncat(g_testLog, (WCHAR*)L":", SRV_IES_TST_LOG_MAX_LENGTH);

    kal_get_time(&preTick);
    pItem->testFunc(pItem->param);
    kal_get_time(&duration);

    duration -= preTick;
}


void* srv_ies_tst_rt_create_canvas(U32 width, U32 height)
{
    if (NULL != g_testBuf)
    {
        med_free_ext_mem(&g_testBuf);
        g_testBuf = NULL;
    }

    if(g_testLayer)
    {
        gdi_layer_free(g_testLayer);
        g_testLayer = NULL;
    }

    if(NULL == g_testBuf)
    {
        g_testBuf = (U8*)med_alloc_ext_mem(width * height * 2);
        ASSERT(NULL != g_testBuf);

        memset(g_testBuf, 0x0, width * height * 2);
    }
 
    gdi_layer_create_cf_using_outside_memory(GDI_COLOR_FORMAT_16,
                                             0,
                                             0,
                                             width,
                                             height,
                                             &g_testLayer,
                                             (U8*)g_testBuf,
                                             width * height * 2);

    return g_testBuf;
}


IESTestResultEnum srv_ies_tst_rt_auto_test(U32 param)
{
    const IESTestMenu* pList;

    pList = reinterpret_cast<const IESTestMenu*>(param);
    srv_ies_tst_rt_auto_test_start(pList);

    return SRV_IES_TST_TR_OK;
}


void srv_ies_tst_rt_start(void)
{
    IESTestMenuItem         testitem;
    const IESTestMenuItem   *pCurTest;
    S32                     offset;
        
    if(TOPMENU == &SRV_IES_TST_MENU(srv_ies_testbed_main))
    {
        offset = 0;
    }
    else
    {
        offset = 1;
    }

    if (TOP.focusID < 0 || TOP.focusID >= TOPMENU->count + offset)
    {
        mmi_popup_display((WCHAR*)L"Internal Error", MMI_EVENT_FAILURE, NULL);
        return;
    }

    if(offset && TOP.focusID == 0)
    {
        testitem.title      = TOPMENU->title;
        testitem.testFunc   = srv_ies_tst_rt_auto_test;
        testitem.param      = (U32)TOPMENU;
        testitem.type       = SRV_IES_TST_TT_DO;
        pCurTest = &testitem;
    }   
    else
    {
        pCurTest = &TOPMENU->items[TOP.focusID - offset];
    }
    
    memset(g_testLog, NULL, SRV_IES_TST_LOG_MAX_LENGTH * 2);

    srv_ies_tst_rt_menu_run(pCurTest);
}


void srv_ies_tst_rt_menu_enter(void)
{
#if !defined(__COSMOS_MMI_PACKAGE__)
    U16         screenID;
    U8          *pGUIBuffer;
    WCHAR       *pStrItem[30];
    PU8         icoItem[30];    
    S32         offset;
    S32         index;

    screenID = (U16)(SCR_SRV_IES_TST_BASE + g_focusStackTop);
    
    mmi_frm_scrn_enter(GRP_ID_ROOT, screenID, srv_ies_tst_rt_menu_exit, srv_ies_tst_rt_menu_enter, MMI_FRM_FULL_SCRN);


    pGUIBuffer = mmi_frm_scrn_get_active_gui_buf();

    if(TOPMENU == &SRV_IES_TST_MENU(srv_ies_testbed_main))
    {
        offset = 0;
    }
    else
    {
        pStrItem[0] = (WCHAR*)L"* All *";
        icoItem[0]  = NULL;
        offset = 1;
    }

    for (index = 0; index < TOPMENU->count; index++)
    {
        pStrItem[index + offset] = (WCHAR*)TOPMENU->items[index].title;
        icoItem[index + offset]  = (PU8)GetImage(gIndexIconsImageList[index]);
    }

    RegisterHighlightHandler(srv_ies_tst_rt_menu_highlight_cb);

    ShowCategory170Screen((U8*)TOPMENU->title,
                          0,
                          (PU8)GetString(STR_GLOBAL_OK),
                          (PU8)GetImage(IMG_GLOBAL_OK),
                          (PU8)GetString(STR_GLOBAL_BACK),
                          (PU8)GetImage(IMG_GLOBAL_BACK),
                          TOPMENU->count + offset,
                          (PU8*)pStrItem,
                          (PU8*)icoItem,
                          0,
                          TOP.focusID,
                          pGUIBuffer);

    SetRightSoftkeyFunction(srv_ies_tst_rt_goback, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(srv_ies_tst_rt_start, KEY_EVENT_UP);
#endif  // !defined(__COSMOS_MMI_PACKAGE__)
}


IESTestResultEnum srv_ies_tst_rt_menu_select(U32 param)
{
    IESTestMenu* pPage;

    g_focusStackTop++;
    
    pPage = reinterpret_cast<IESTestMenu*>(param);
    SETTOP(pPage);

    srv_ies_tst_rt_menu_enter();

    return SRV_IES_TST_TR_OK;
}


extern "C" void srv_ies_tst_rt_main_entry(void)
{
    g_testStackTop  = -1;
    g_focusStackTop = 0; // init value

    SETTOP(&SRV_IES_TST_MENU(srv_ies_testbed_main));

    srv_ies_tst_rt_menu_enter();
}

/*****************************************************************************
 * FUNCTION
 *  srv_ies_testbed_launch
 * DESCRIPTION
 *  SSC (*#72252#) entry function, enter testbed Pluto screen
 *****************************************************************************/
extern "C" void srv_ies_testbed_launch(void)
{
    srv_ies_tst_rt_main_entry();
}

#else 
/*****************************************************************************
 * FUNCTION
 *  srv_ies_testbed_launch
 * DESCRIPTION
 *  SSC (*#72252#) entry function, do nothing when test bed is not compiled.
 *****************************************************************************/
extern "C" void srv_ies_testbed_launch(void)
{

}

#endif /* SRV_IES_TESTBED_ENABLE */
#endif /* __MMI_SRV_IES__ */
