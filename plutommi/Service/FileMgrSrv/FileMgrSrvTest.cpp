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
 *  FileMgrSrvTest.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Testbed of File manager service
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#define _FMGR_INTERNAL_SOURCE_C_
#define _FMGR_GPROT_H_

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
extern "C"
{
#include "MMI_include.h"
#include "FileMgrSrvProt.h"
}

#if defined(SRV_FMGR_TESTBED_ENABLE)

#include "FileMgrSrvTest.h"

extern "C"
{
#include "CommonScreens.h"
extern void (*gui_start_timer) (S32 count, void (*callback) (void));
}

/***************************************************************************** 
 * Local Variable
 *****************************************************************************/

#define SCR_SRV_FTST_BASE       SRV_FILEMANAGER
#define SCR_SRV_FTST_VSCR_BASE  SRV_FILEMANAGER + 16

#define SRV_FTST_LOG_LENGTH     1024

#define SRV_FTST_MENU_MAX_DEPTH 10

#define SRV_FTST_MEM_POOL_SIZE  4096


static SrvFtstMenuStack         g_focusStack[SRV_FTST_MENU_MAX_DEPTH] = {0};
static int                      g_focusStackTop  = -1;

#define TOP                     (g_focusStack[g_focusStackTop])
#define TOPMENU                 (g_focusStack[g_focusStackTop].menu)

#define SETTOP(_page)           do { TOP.menu = _page; TOP.focusIdx = 0; } while(0)

static kal_uint32               g_nKTick = 0;

// Auto test stack
static SrvFtstMenuStack         g_testStack[SRV_FTST_MENU_MAX_DEPTH] = {0};
static int                      g_testStackTop  = -1;

static U16                      g_testLog[SRV_FTST_LOG_LENGTH] = {0};

// Test Venus Screen
static ISrvFtstTestItemInterface *g_rt_testcase = NULL;
static mmi_id                   g_cat_id;

static U8                       g_testMemPool[SRV_FTST_MEM_POOL_SIZE];
static MMI_BOOL                 g_testMemPoolInUse = MMI_FALSE;

/***************************************************************************** 
 * Predeclaration
 *****************************************************************************/
extern SrvFtstTestResultEnum srv_ftst_rt_menu_enter(U32 param);
extern SrvFtstTestResultEnum srv_ftst_rt_auto_test(U32 param);

extern U8 srv_ftst_rt_menu_del_scrn_cb(void *ptr);

// This is main entry function for menu
extern void srv_ftst_rt_menu_entry(void);

// This is exit function for menu
extern void srv_ftst_rt_menu_exit(void);

// Our GoBack, this will decrease the top index
extern void srv_ftst_rt_goback(void);

// high light handler for main menu
extern void srv_ftst_rt_menu_highlight_handler(
    S32 index   // [IN] the highlight index
);

// Do action when click item
extern void srv_ftst_rt_menu_action(void);
extern void srv_ftst_rt_menu_doaction(const SrvFtstMenuItem* item);

/***************************************************************************** 
 * Autotest Item Predeclaration
 *****************************************************************************/
// For easing add test items, we split this file into another file.
#include "FileMgrSrvTestTable.h"

/***************************************************************************** 
 * Autotest Item Implementation
 *****************************************************************************/

extern "C"
void srv_ftst_rt_main_entry(void)
{
    g_testStackTop = -1;
    g_focusStackTop = 0; // init value

    SETTOP(&SRV_FTST_MENU(main));
    
    srv_ftst_rt_menu_entry();
}

void srv_ftst_rt_entry(void)
{
    EntryNewScreen(SCR_SRV_FTST_VSCR_BASE + g_testStackTop, srv_ftst_rt_leave, NULL, NULL);
    ASSERT(g_rt_testcase == NULL);

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
        (PU8) GetString(STR_GLOBAL_PLEASE_WAIT),
        IMG_GLOBAL_PROGRESS,
        NULL);
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    gui_screen_switch_effect_force_block(MMI_FALSE);
#endif
}

void srv_ftst_rt_leave(void)
{
    /*
     * Leave the screen
     */
    if (g_cat_id && g_rt_testcase)
    {
        g_rt_testcase->testEnd();
        srv_ftst_testcase_end();
    }
}


void srv_ftst_rt_verify(void)
{
    if (g_rt_testcase)
    {
        if (g_rt_testcase->getTestResult())
        {
            mmi_wcsncat(g_testLog, (WCHAR*)L" OK\n", SRV_FTST_LOG_LENGTH);
        }
        else
        {
            mmi_wcsncat(g_testLog, (WCHAR*)L"\n", SRV_FTST_LOG_LENGTH);
        }

        if (g_testStackTop < 0)
        {
            srv_ftst_rt_autotest_result_entry();
        }
        else
        {
            srv_ftst_rt_autotest_trigger();
        }
    }
    // After verify the result, we can end the test case 
    if (g_rt_testcase)
    {
        g_rt_testcase->testEnd();
        srv_ftst_testcase_end();
    }
}

void srv_ftst_testcase_start(ISrvFtstTestItemInterface* testcase, MMI_BOOL isCategory)
{
    ASSERT(g_rt_testcase == NULL);
    g_rt_testcase = testcase;
    g_rt_testcase->testStart();
    if (isCategory)
    {
        g_cat_id = SCR_SRV_FTST_VSCR_BASE + g_testStackTop;
    }
    else
    {
        g_cat_id = 0;
    }
}

void srv_ftst_testcase_end()
{
    g_rt_testcase = NULL;
    g_cat_id = 0;
}

void srv_ftst_add_fail_log(const WCHAR *testName)
{
    if(!testName)
        return;
    
    mmi_wcsncat(g_testLog, (WCHAR*)L"\n ", SRV_FTST_LOG_LENGTH);
    mmi_wcsncat(g_testLog, testName, SRV_FTST_LOG_LENGTH);
    mmi_wcsncat(g_testLog, (WCHAR*)L": fail", SRV_FTST_LOG_LENGTH);
}

S32 srv_ftst_rt_compare_file(const WCHAR* src_path, const WCHAR* dest_path)
{
    U8 src_buf[512], dest_buf[512];
    FS_HANDLE src_fh, dest_fh;
    S32 fs_ret;
    U32 src_read, dest_read;

    src_fh = dest_fh = 0;
    
    do {
        fs_ret = -1;
        src_fh = FS_Open(src_path, FS_READ_ONLY | FS_OPEN_SHARED);
        if(src_fh < 0)
            break;
        dest_fh = FS_Open(dest_path, FS_READ_ONLY | FS_OPEN_SHARED);
        if(dest_fh < 0)
            break;

        FS_GetFileSize(src_fh, &src_read);
        FS_GetFileSize(dest_fh, &dest_read);
        if(src_read != dest_read)
            break;

        do 
        {
            fs_ret = FS_Read(src_fh, src_buf, 512, &src_read);
            if(fs_ret < 0)
                break;
            fs_ret = FS_Read(dest_fh, dest_buf, 512, &dest_read);
            if(fs_ret < 0)
                break;
            if(src_read != dest_read)
                break;
            if(kal_mem_cmp(src_buf, dest_buf, src_read) != 0)
                break;
        } while(src_read == 512);

        if(src_read == 512) /* error */
            break;

        fs_ret = 0;
    } while(0);

    if(src_fh > 0)  FS_Close(src_fh);
    if(dest_fh > 0) FS_Close(dest_fh);
    
    return fs_ret;
}
/***************************************************************************** 
 * Global Function
 *****************************************************************************/

void srv_ftst_rt_testcase_step(void)
{
    if (g_rt_testcase)
    {
        g_rt_testcase->step();
    }
}

void srv_ftst_rt_autotest_step(void)
{
    // All item is completed
    if (g_testStackTop < 0)
    {
        srv_ftst_rt_autotest_trigger(); 
        return;
    }

    SrvFtstMenuStack* top = &g_testStack[g_testStackTop];
    
    // This item has completed
    if (top->focusIdx >= top->menu->count)
    {
        g_testStackTop--;
        srv_ftst_rt_autotest_trigger(); 
        return;
    }
    
    if (top->menu->items[top->focusIdx].tt == SRV_FTST_TT_TEST)
    {
        // Do test item, don't triggle step, the test item will do it later
        srv_ftst_rt_menu_doaction(&top->menu->items[top->focusIdx]);
    }
    else if (top->menu->items[top->focusIdx].tt == SRV_FTST_TT_MENU)
    {
        // enter next sub menu
        g_testStackTop += 1;
        g_testStack[g_testStackTop].menu = (const SrvFtstMenu*)top->menu->items[top->focusIdx].param;
        g_testStack[g_testStackTop].focusIdx = 0;

        mmi_wcsncat(g_testLog, (WCHAR*)L"[ ", SRV_FTST_LOG_LENGTH);
        mmi_wcsncat(g_testLog, g_testStack[g_testStackTop].menu->title, SRV_FTST_LOG_LENGTH);
        mmi_wcsncat(g_testLog, (WCHAR*)L" ]\n", SRV_FTST_LOG_LENGTH);
        
        srv_ftst_rt_autotest_trigger();
    }

    top->focusIdx += 1;
}

void srv_ftst_rt_autotest_result_entry(void)
{
    U16 screenID = SCR_SRV_FTST_VSCR_BASE;
    
    EntryNewScreen(screenID, NULL, srv_ftst_rt_autotest_result_entry, NULL);

    ShowCategory74Screen(
        STR_GLOBAL_CONTENT,
        0,
        0, //STR_GLOBAL_OK,
        0, //IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*)g_testLog,
        mmi_wcslen(g_testLog),
        GetCurrGuiBuffer(screenID)
    );

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    //SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    //SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);    
}

void srv_ftst_rt_autotest_trigger(void)
{
    if (g_testStackTop < 0)
    {
        // All test item is completed
        srv_ftst_rt_autotest_result_entry();
        return;
    }
    gui_start_timer(0, srv_ftst_rt_autotest_step);
}


void srv_ftst_rt_autotest_start(const SrvFtstMenu* list)
{
    //WCHAR* local_category_name[100] = {0};
    //kal_wsprintf(local_category_name, "%w[%w]", category_name, list->title);


    memset(g_testLog, NULL, SRV_FTST_LOG_LENGTH * 2);
    g_testStack[0].menu = list;
    g_testStack[0].focusIdx = 0;
    g_testStackTop  = 0;
    srv_ftst_rt_autotest_step();
}


SrvFtstTestResultEnum srv_ftst_rt_auto_test(U32 param)
{
    const SrvFtstMenu* list = reinterpret_cast<const SrvFtstMenu*>(param);
    srv_ftst_rt_autotest_start(list);
    return SRV_FTST_TR_OK;
}


SrvFtstTestResultEnum srv_ftst_rt_menu_enter(U32 param)
{
    g_focusStackTop++;
    SrvFtstMenu* page = reinterpret_cast<SrvFtstMenu*>(param);
    SETTOP(page);

    srv_ftst_rt_menu_entry();

    return SRV_FTST_TR_OK;
}

U8 srv_ftst_rt_menu_del_scrn_cb(void *ptr)
{
    
    return MMI_HIST_ALLOW_DELETING;
}

void srv_ftst_rt_menu_entry()
{
    U16 screenID = (U16)(SCR_SRV_FTST_BASE + g_focusStackTop);
    
    EntryNewScreen(screenID, srv_ftst_rt_menu_exit, srv_ftst_rt_menu_entry, NULL);

    SetDelScrnIDCallbackHandler(screenID, srv_ftst_rt_menu_del_scrn_cb);

    U8 *guiBuffer = GetCurrGuiBuffer(screenID);

    const WCHAR *nStrItemList[20];
    PU8         nIcoItemList[20];    
    int         offset;

    if(TOPMENU == &SRV_FTST_MENU(main))
    {
        offset = 0;
    }
    else
    {
        nStrItemList[0] = (WCHAR*)L"* All *";
        nIcoItemList[0] = NULL;
        offset = 1;
    }

    for (int i = 0; i < TOPMENU->count; i++)
    {
        nStrItemList[i+offset] = TOPMENU->items[i].title;
        nIcoItemList[i+offset] = (PU8)GetImage(gIndexIconsImageList[i]);
    }
    RegisterHighlightHandler(srv_ftst_rt_menu_highlight_handler);

    ShowCategory170Screen(
        (U8*) TOPMENU->title,
        0,
        (PU8) GetString(STR_GLOBAL_OK),
        (PU8) GetImage(IMG_GLOBAL_OK),
        (PU8) GetString(STR_GLOBAL_BACK),
        (PU8) GetImage(IMG_GLOBAL_BACK),
        TOPMENU->count+offset,
        (PU8*) nStrItemList,
        (PU8*) nIcoItemList,
        0,
        TOP.focusIdx,
        guiBuffer);

    SetRightSoftkeyFunction(srv_ftst_rt_goback, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(srv_ftst_rt_menu_action, KEY_EVENT_UP);
}

void srv_ftst_rt_goback(void)
{
    g_focusStackTop--;
    GoBackHistory();
}

void srv_ftst_rt_menu_exit(void)
{
}

void srv_ftst_rt_menu_highlight_handler(S32 index)
{
    TOP.focusIdx = (int)index;
}

void srv_ftst_rt_menu_action(void)
{
    int ret = 0;
    kal_uint32 preTick = 0, tick = 0;
    SrvFtstTestTypeEnum tt;
    SrvFtstMenuItem testitem;
    const SrvFtstMenuItem *ti;
    int offset;
        
    g_nKTick = 0;

    if(TOPMENU == &SRV_FTST_MENU(main))
        offset = 0;
    else
        offset = 1;

    if (TOP.focusIdx < 0 || TOP.focusIdx >= TOPMENU->count + offset)
    {
        mmi_popup_display((WCHAR*)L"Internal Error", MMI_EVENT_FAILURE, NULL);
        return;
    }

    if(offset && TOP.focusIdx == 0)
    {
        testitem.title = TOPMENU->title;
        testitem.testFuncPtr = srv_ftst_rt_auto_test;
        testitem.param = (U32)TOPMENU;
        testitem.tt = SRV_FTST_TT_DO;
        ti = &testitem;
    }   
    else
    {
        ti = &TOPMENU->items[TOP.focusIdx-offset];
    }
    
    tt = ti->tt;

    memset(g_testLog, NULL, SRV_FTST_LOG_LENGTH * 2);
    srv_ftst_rt_menu_doaction(ti);
}

void srv_ftst_rt_menu_doaction(const SrvFtstMenuItem* item)
{
    SrvFtstTestResultEnum ret = SRV_FTST_TR_FAIL;
    kal_uint32 preTick = 0, tick = 0;
    SrvFtstTestTypeEnum tt;

    mmi_wcsncat(g_testLog, item->title, SRV_FTST_LOG_LENGTH);
    mmi_wcsncat(g_testLog, (WCHAR*)L":", SRV_FTST_LOG_LENGTH);

    g_nKTick = 0;

    tt = item->tt;

    kal_get_time(&preTick);
    ret = item->testFuncPtr(item->param);
    kal_get_time(&tick);

    tick -= preTick;
}

/*****************************************************************************
 * Class SrvFtstTestItem
 *****************************************************************************/

void SrvFtstTestItem::testStart()
{
    S32 phase = start();
    m_phaseCount = phase;
    m_phase = 0;
    m_phasePendding = MMI_FALSE;
    gui_start_timer(0, srv_ftst_rt_testcase_step);
}

void SrvFtstTestItem::testEnd()
{
    delete this;
}

void SrvFtstTestItem::step()
{
    if ((m_phaseCount > 0 && m_phase >= m_phaseCount) ||
        (m_phase < 0))
    {
        verifyOutput();
        end();
        srv_ftst_rt_verify();
        return;
    }

    S32 timeout = phase(m_phase);

    if (timeout == SRV_FTST_RT_END_TESTCASE)
    {
        verifyOutput();
        end();
        srv_ftst_rt_verify();
        return;
    }

    m_phase += 1;
    if (timeout >= 0)
    {
        gui_start_timer(timeout, srv_ftst_rt_testcase_step);
    }
    else
    {
        m_phasePendding = MMI_TRUE;
    }
}

void SrvFtstTestItem::endPhase(MMI_BOOL bFatalError /* = MMI_FALSE */)
{
    if (m_phasePendding)
    {
        if(bFatalError)
            m_phase = SRV_FTST_RT_END_TESTCASE;
        gui_start_timer(0, srv_ftst_rt_testcase_step);
        m_phasePendding = MMI_FALSE;
    }
}

MMI_BOOL SrvFtstTestItem::check(bool statement, const WCHAR *testName, const char *filename, S32 fileline)
{
    if (!statement)
    {
        fail();

        WCHAR buf[256];

        kal_wsprintf(buf, "(%d)", getPhase());
        if(filename)
        {
            S32 pos = strlen(filename);
            while(pos > 0 && filename[pos] != '\\')
                pos --;
            pos++;
        
            S32 len = mmi_wcslen(buf);
            if (len + strlen(filename+pos) + 8 < 256)
                kal_wsprintf(buf + len, "%s:%d ", filename+pos, fileline);
        }
        if(testName)
            mmi_wcsncat(buf, testName, 255);

        srv_ftst_add_fail_log(buf);
        return MMI_FALSE;
    }
    return MMI_TRUE;
}

void *SrvFtstTestItem::operator new (
    size_t size    // [IN] The memory size to allocate
)
{
    ASSERT(size <= SRV_FTST_MEM_POOL_SIZE);
    ASSERT(!g_testMemPoolInUse);
    g_testMemPoolInUse = MMI_TRUE;
    memset(g_testMemPool, 0, sizeof(g_testMemPool));
    return g_testMemPool;
}

void SrvFtstTestItem::operator delete (
    void *ptr       // [IN] pointer to instance
)
{
    ASSERT(g_testMemPoolInUse);
    g_testMemPoolInUse = MMI_FALSE;
}

void SrvFtstTestItem::writeString(const WCHAR* buffer, MMI_BOOL newline)
{
    if(!m_fp)
    {
        WCHAR path[SRV_FMGR_PATH_MAX_LEN + 1];
        
        if(!getWritePath(path, sizeof(path)))
            return;
            
        m_fp = FS_Open(path, FS_CREATE_ALWAYS | FS_READ_WRITE);
        if(m_fp < 0)
        {
            m_fp = 0;
            return;
        }
        
        U8 head[2];
        head[0] = 0xFF;
        head[1] = 0xFE;
        FS_Write(m_fp, (void*)&head, 2, NULL);
    }
    
    if(m_fp && buffer)
    {
        FS_Write(m_fp, (void*)buffer, (mmi_wcslen(buffer))*2, NULL);
        if(newline)
        {
            WCHAR ln[2];
            ln[0] = 0x0D;
            ln[1] = 0x0A;
            FS_Write(m_fp, (void*)ln, sizeof(ln), NULL);
        }
    }
}

void SrvFtstTestItem::verifyOutput(void)
{
    S32 fs_ret;
    WCHAR write_path[(SRV_FMGR_PATH_MAX_LEN + 1)/2];
    WCHAR check_path[(SRV_FMGR_PATH_MAX_LEN + 1)/2];

    if(!getWritePath(write_path, sizeof(write_path)))
        return;

    if(!getCheckPath(check_path, sizeof(check_path)))
        return;
    
    if(m_fp)
    {
        FS_Close(m_fp);
        m_fp = 0;
    }

    fs_ret = srv_ftst_rt_compare_file(write_path, check_path);

    check((fs_ret == 0), (WCHAR*)L"verifyOutput", NULL, 0);
}



#endif
