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
 *  FileMgrSrvTest.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager service internal prototype header.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef SRV_FMGR_TEST_H
#define SRV_FMGR_TEST_H

#ifndef _FMGR_INTERNAL_SOURCE_C_
#error "This header is only for FileManager source!"
#endif

#if defined(SRV_FMGR_TESTBED_ENABLE)

enum SrvFtstTestTypeEnum
{
    SRV_FTST_TT_DO, 
    SRV_FTST_TT_MENU,
    SRV_FTST_TT_TEST,
    SRV_FTST_TT_END_OF_ENUM
};

enum SrvFtstTestResultEnum
{
    SRV_FTST_TR_FAIL = 0, 
    SRV_FTST_TR_OK, 
    SRV_FTST_TR_END_OF_ENUM
};

typedef SrvFtstTestResultEnum (*SrvFtstTestFuncPtr)(U32 param);  // Test invoke function pointer type

struct SrvFtstMenuItem
{
    const WCHAR*        title;          // Test title string
    SrvFtstTestFuncPtr  testFuncPtr;    // Test invoke function
    U32                 param;          // Test userdata
    SrvFtstTestTypeEnum tt;             // Test type
};

struct SrvFtstMenu
{
    const WCHAR         *title;
    const SrvFtstMenuItem  *items;
    S32                 count;
};

struct SrvFtstMenuStack
{
    const SrvFtstMenu      *menu;
    S32                 focusIdx;
};

// Define Menu Macro:
// Example:
// SRV_FTST_BEGIN_DEF_MENU(L"Venus RT", main)
//     SRV_FTST_DEF_ITEM_DO(L"Auto test",      srv_ftst_rt_auto_test, 0)
//     SRV_FTST_DEF_ITEM_MENU(L"Test Item",    venustest)
// SRV_FTST_END_DEF_MENU(main)


#define SRV_FTST_BEGIN_DEF_MENU(_title, _name) \
const WCHAR* g_menu_title_##_name = (WCHAR*)_title; \
static const SrvFtstMenuItem g_items_##_name[] = {

#define SRV_FTST_END_DEF_MENU(_name) \
}; \
static const SrvFtstMenu g_menu_##_name = { \
    g_menu_title_##_name, g_items_##_name, (sizeof(g_items_##_name) / sizeof(g_items_##_name[0])) \
};

#define SRV_FTST_DEF_ITEM_DO(_title, _func, _param) {(WCHAR*)_title, _func, (U32)_param, SRV_FTST_TT_DO},
#define SRV_FTST_DEF_ITEM_TEST(_title, _func, _param) {(WCHAR*)_title, _func, (U32)_param, SRV_FTST_TT_TEST},
#define SRV_FTST_DEF_ITEM_MENU(_title, _submenu) {(WCHAR*)_title, srv_ftst_rt_menu_enter, (U32)&g_menu_##_submenu, SRV_FTST_TT_MENU},

#define SRV_FTST_MENU(_name) g_menu_##_name

#define SRV_FTST_START(_class) \
do \
{ \
    srv_ftst_rt_entry(); \
    SrvFtstTestItem* scr = new _class(); \
    srv_ftst_testcase_start(scr, MMI_TRUE); \
} while(0)

#define SRV_FTST_CHECK(x)   check(x, NULL, __FILE__, __LINE__)

#if defined(SRV_FMGR_TESTBED_ENABLE) && !defined(__MTK_TARGET__)    /* Modis */
#define SRV_FMGR_TEST_PRINT0(str)           kal_printf(str)
#define SRV_FMGR_TEST_PRINT1(str,p1)        kal_printf(str,p1)
#define SRV_FMGR_TEST_PRINT2(str,p1,p2)     kal_printf(str,p1,p2)
#define SRV_FMGR_TEST_PRINT3(str,p1,p2,p3)  kal_printf(str,p1,p2,p3)
#elif 0 //defined(SRV_FMGR_TESTBED_ENABLE)                              /* Target */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define SRV_FMGR_TEST_PRINT0(str)           
#define SRV_FMGR_TEST_PRINT1(str,p1)        
#define SRV_FMGR_TEST_PRINT2(str,p1,p2)     
#define SRV_FMGR_TEST_PRINT3(str,p1,p2,p3)  
#endif


/*****************************************************************************
 * Class ISrvFtstRtScreenInterface
 *****************************************************************************/
#define SRV_FTST_RT_TESTCASE_NEEDCONFIRM (-1)
#define SRV_FTST_RT_END_TESTCASE (-5000)

class ISrvFtstTestItemInterface
{
// Method
public:
    // Query the final test result
    // RETURNS:
    //  MMI_TRUE if the test is successful
    virtual MMI_BOOL getTestResult() = 0;

    // Timer handler to triggle phase change
    virtual void step() = 0;

    // Start the test case
    virtual void testStart() = 0;

    // End the test case
    virtual void testEnd() = 0;

    // start test case, and return how many phase you need to test
    // RETURNS:
    //  How many phase about this testcase.
    virtual S32 start() = 0;

    // start test case phase, and return how long time (ms) you need to take
    // RETURNS:
    //  How many time the phase takes, after this time, 
    //  Return SRV_FTST_RT_TESTCASE_NEEDCONFIRM means the phase time is not fixed.
    //  Maybe the testcase needs user's input. 
    //  After the phase is end, you should call endPhase API.
    //  Return SRV_FTST_RT_END_TESTCASE you want to end the testcase.
    virtual S32 phase(
        S32 idx  // [IN] the phase index, this value is Zero index
    ) = 0;

    // Verify whether the testcase is success
    virtual void end() = 0;
};



/*****************************************************************************
 * Class SrvFtstRtScr
 *****************************************************************************/

class SrvFtstTestItem : public ISrvFtstTestItemInterface
{
// Variable
public:
    //VfxTextFrame    *m_title;
    //VfxTextFrame    *m_status;
    MMI_BOOL        m_fail;
    S32             m_phaseCount, m_phase;
    MMI_BOOL        m_phasePendding;
    MMI_BOOL        m_waitConfirm;

    FS_HANDLE       m_fp;

    static void *operator new (
        size_t size    // [IN] The memory size to allocate
    );

    static void operator delete (
        void *ptr      // [IN] pointer to instance
    );

// Constructor / Destructor
public:
    // Default constructor
    SrvFtstTestItem() 
        : m_fail(MMI_FALSE)
        , m_phaseCount(0), m_phase(0), m_phasePendding(MMI_FALSE)
        , m_waitConfirm(MMI_FALSE)
        , m_fp(0)
    {
    }
    virtual ~SrvFtstTestItem() 
    {
        if(m_fp)
            FS_Close(m_fp);
    }
        
// Method
public:
    // Set the test case to fail
    void fail()
    {
        m_fail = MMI_TRUE;
    }

    // Verify the result. If the statement is false, the testcase fail.
    // And then the report will show testName is fail.
    MMI_BOOL check(
        bool statement,              // [IN] The check statement
        const WCHAR *testName,       // [IN] The test item name
        const char *filename,
        S32 fileline
    );

    // Query the final test result
    // RETURNS:
    //  MMI_TRUE if the test is successful
    MMI_BOOL getTestResult()
    {
        return m_fail ? MMI_FALSE : MMI_TRUE;
    }

    // Timer handler to triggle phase change
    void step();

    // Triggle to next phase when phase return 0, if bFatalError = True, 
    // it will end directly
    void endPhase(MMI_BOOL bFatalError = MMI_FALSE);

    S32 getPhase()
    {
        if(m_phasePendding)
            return m_phase - 1;
        return m_phase;
    }

    void writeString(const WCHAR* buffer, MMI_BOOL newline = MMI_TRUE);
    void verifyOutput(void);
    
// Overridable
public:
    // start test case, and return how many phase you need to test
    // RETURNS:
    //  How many phase about this testcase
    virtual S32 start() { return 0; }

    // start test case phase, and return how long time (ms) you need to take
    // RETURNS:
    //  How many time the phase takes, after this time, 
    //  Return < 0 means the phase time is not fixed.
    //  Maybe the testcase needs user's input. 
    //  After the phase is end, you should call endPhase.
    virtual S32 phase(
        S32 idx  // [IN] the phase index, this value is Zero index
    )
    { 
        return SRV_FTST_RT_END_TESTCASE; 
    }

    // Verify whether the testcase is success
    virtual void end() {}

    virtual mmi_ret onProc(mmi_event_struct *param)
    {
        return MMI_RET_OK;
    }

    virtual const WCHAR* getWritePath(WCHAR* path, S32 size)
    {
        return NULL;
    }

    virtual const WCHAR* getCheckPath(WCHAR* path, S32 size)
    {
        return NULL;
    }

// Override
public:
    // Start the test case
    void testStart();

    // End the test case
    void testEnd();

protected:
    static mmi_ret _Proc(mmi_event_struct *param)
    {
        SrvFtstTestItem* self = reinterpret_cast<SrvFtstTestItem*>(param->user_data);
        return self->onProc(param);
    }
};

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

void srv_ftst_rt_entry(void);
void srv_ftst_rt_entry_rotate(void);
void srv_ftst_rt_leave(void);
void srv_ftst_rt_autotest_trigger(void);
void srv_ftst_rt_autotest_result_entry(void);
void srv_ftst_rt_proc_call(media_in_proc_call_type func, kal_uint32 func_arg1, void *func_arg2);
void srv_ftst_add_fail_log(const WCHAR *testName);
void srv_ftst_rt_verify(void);
void srv_ftst_rt_autotest_step(void);
void srv_ftst_rt_autotest_result_entry(void);
void srv_ftst_rt_autotest_trigger(void);
void srv_ftst_rt_testcase_step(void);
void srv_ftst_testcase_start(ISrvFtstTestItemInterface* testcase, MMI_BOOL isCategory);
void srv_ftst_testcase_end();
S32  srv_ftst_rt_compare_file(const WCHAR* src_path, const WCHAR* dest_path);

#ifdef __cplusplus
extern "C"
{
#endif

// This is main entry function for our testing
extern void srv_ftst_rt_main_entry(void);

#ifdef __cplusplus
}
#endif

#endif

#endif /* SRV_FMGR_TEST_H */
