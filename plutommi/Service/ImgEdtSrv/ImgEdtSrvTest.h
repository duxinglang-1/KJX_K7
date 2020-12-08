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
 *  ImgEdtSrvTest.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Image Editing Service test, based on FmgrSrvTest.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __SRV_IMGEDT_TEST_H__
#define __SRV_IMGEDT_TEST_H__

#ifdef SRV_IES_TESTBED_ENABLE

#include "ImgEdtSrvGprot.h"
#include "FileMgrSrvGprot.h"

extern "C"
{
#include "MMI_Include.h"
#include "med_utility.h"
}

enum IESTestTypeEnum
{
    SRV_IES_TST_TT_DO, 
    SRV_IES_TST_TT_MENU,
    SRV_IES_TST_TT_TEST,
    SRV_IES_TST_TT_END_OF_ENUM
};

enum IESTestResultEnum
{
    SRV_IES_TST_TR_FAIL = 0, 
    SRV_IES_TST_TR_OK, 
    SRV_IES_TST_TR_END_OF_ENUM
};

typedef IESTestResultEnum (*IESTestFunc)(U32 caseID);                   // Test invoke function pointer type

struct IESTestMenuItem
{
    const WCHAR             *title;                                     // Test title
    IESTestFunc             testFunc;                                   // Test function
    U32                     param;                                      // Test user data
    IESTestTypeEnum         type;                                       // Test type
};

struct IESTestMenu
{
    const WCHAR             *title;
    const IESTestMenuItem   *items;
    S32                     count;
};

struct IESTestMenuStack
{
    const IESTestMenu       *menu;
    S32                     focusID;
};

class IESTestBase;


/*
 * End running the test case
 */
void srv_ies_tst_rt_end(void);

/*
 * Create and enter a test group
 */
void srv_ies_tst_rt_enter(void);

/*
 * Start running the test case
 */
void srv_ies_tst_rt_start(IESTestBase  *pTestObject,
                          U32           caseID,
                          MMI_BOOL      isCategory);

/*
 * Start running the specified menu
 */
void srv_ies_tst_rt_menu_run(const IESTestMenuItem *pItem);

/*
 * Enter the selected menu item
 */
IESTestResultEnum srv_ies_tst_rt_menu_select(U32 param);

/*
 * Create canvas buffer for render
 */
void* srv_ies_tst_rt_create_canvas(U32 width,
                                   U32 height);

/*
 * Auto step to next phase
 */
void srv_ies_tst_rt_auto_test_step(void);


/*****************************************************************************
 * Define Menu Macro:
 * Example:
 *   SRV_IES_TST_BEGIN_DEF_MENU(L"Venus RT", main)
 *     SRV_IES_TST_DEF_ITEM_DO(L"Auto test",      srv_ftst_rt_auto_test, 0)
 *     SRV_IES_TST_DEF_ITEM_MENU(L"Test Item",    venustest)
 *   SRV_IES_TST_END_DEF_MENU(main)
 *****************************************************************************/
#define SRV_IES_TST_BEGIN_DEF_MENU(_title, _name)               \
    const WCHAR* g_menu_title_##_name = (WCHAR*)_title;         \
                                                                \
    static const IESTestMenuItem g_items_##_name[] = {

#define SRV_IES_TST_END_DEF_MENU(_name)                         \
    };                                                          \
                                                                \
    static const IESTestMenu g_menu_##_name = {                 \
        g_menu_title_##_name,                                   \
        g_items_##_name,                                        \
        (sizeof(g_items_##_name) / sizeof(g_items_##_name[0]))  \
    };

#define SRV_IES_TST_DEF_ITEM_MENU(_title, _submenu)             \
{                                                               \
    (WCHAR*)_title,                                             \
    srv_ies_tst_rt_menu_select,                                 \
    (U32)&g_menu_##_submenu,                                    \
    SRV_IES_TST_TT_MENU                                         \
},

#define SRV_IES_TST_DEF_ITEM_TEST(_title, _func, _param)        \
{                                                               \
    (WCHAR*)_title, _func, (U32)_param, SRV_IES_TST_TT_TEST     \
},

#define SRV_IES_TST_DEF_ITEM_DO(_title, _func, _param)          \
{                                                               \
    (WCHAR*)_title, _func, (U32)_param, SRV_IES_TST_TT_DO       \
},

#define SRV_IES_TST_MENU(_name) g_menu_##_name

#define SRV_IES_TST_START(_class, _caseID)                      \
do                                                              \
{                                                               \
    IESTestBase *pObject;                                       \
                                                                \
    srv_ies_tst_rt_enter();                                     \
    pObject = new _class();                                     \
    ASSERT(NULL != pObject);                                    \
                                                                \
    srv_ies_tst_rt_start(pObject, _caseID, MMI_TRUE);           \
} while(0)


/*****************************************************************************
 * Class ISrvFtstRtScreenInterface
 *****************************************************************************/
#define SRV_IES_TST_RT_END_TEST_CASE            (0)
#define SRV_IES_TST_RT_RUN_CUR_PHASE            (1)
#define SRV_IES_TST_RT_DO_NEXT_PHASE            (2)

#define SCR_SRV_IES_TST_BASE                    SRV_FILEMANAGER
#define SCR_SRV_IES_TST_VSCR_BASE               SRV_FILEMANAGER + 16
#define SRV_IES_TST_MEM_POOL_SIZE               4096
#define SRV_IES_TST_MENU_MAX_DEPTH              10
#define SRV_IES_TST_LOG_MAX_LENGTH              1024

/*****************************************************************************
 * Class IESTestItem implements the testing interface
 *****************************************************************************/
class IESTestItem
{
protected:
    static U8           s_testMemPool[SRV_IES_TST_MEM_POOL_SIZE];
    static bool         s_testMemUsed;
    static IESTestItem  *s_pCurTest;

    S32                 m_phaseCount;
    S32                 m_phaseProg;
    bool                m_phaseRunning;
    U16                 m_testReport[SRV_IES_TST_LOG_MAX_LENGTH];
    FS_HANDLE           m_fileHandle;

    static void timerCallback(void)
    {
        if (NULL != s_pCurTest)
        {
            s_pCurTest->step();
        }
    }

public:
    /* 
     * Operator new for allocating memory
     * PARAMETER
     *  [IN] The memory size to allocate
     */
    void *operator new(size_t size)
    {
        ASSERT(size <= SRV_IES_TST_MEM_POOL_SIZE);
        ASSERT(false == s_testMemUsed);

        s_testMemUsed = true;
        memset(s_testMemPool, 0, sizeof(s_testMemPool));

        return s_testMemPool;
    }

    /*
     * Operator new to release memory
     * PARAMETER
     *  [IN] pointer to instance
     */
    void operator delete(void *pBuffer)
    {
        ASSERT(true == s_testMemUsed);
        s_testMemUsed = false;
    }

    IESTestItem() 
        : m_phaseCount(0),
          m_phaseProg(0),
          m_phaseRunning(false),
          m_fileHandle(0)
    {
    }

    virtual ~IESTestItem() 
    {
        if(NULL != m_fileHandle)
        {
            FS_Close(m_fileHandle);
        }
    }

protected:
    static void onJobFinished(srv_ies_result jobResult, void *pData)
    {
        IESTestItem *pThis;

        pThis = reinterpret_cast<IESTestItem*>(pData);

        if(SRV_IES_OK != jobResult)
        {
            pThis->fail((WCHAR*)L"Processing asynchronous job failed\n");
        }

        pThis->end();

        pThis->m_phaseRunning = false;
    }

    // Set the test case to fail
    void fail(const WCHAR *pString)
    {
        mmi_wcsncat(m_testReport, (WCHAR*)L"\n ", SRV_IES_TST_LOG_MAX_LENGTH);
        mmi_wcsncat(m_testReport, pString, SRV_IES_TST_LOG_MAX_LENGTH);
        mmi_wcsncat(m_testReport, (WCHAR*)L": fail", SRV_IES_TST_LOG_MAX_LENGTH);
    }

    // Timer handler to triggle phase change
    void step()
    {
        S32 timeOut;

        if (((m_phaseCount > 0) && (m_phaseProg >= m_phaseCount)) || (m_phaseProg < 0))
        {
            end();

            m_phaseRunning = false;
            srv_ies_tst_rt_end();
            return;
        }

        timeOut = phase(m_phaseProg);

        if (SRV_IES_TST_RT_END_TEST_CASE == timeOut)
        {
            end();

            m_phaseRunning = false;
            srv_ies_tst_rt_end();
            return;
        }
        else if (SRV_IES_TST_RT_DO_NEXT_PHASE == timeOut)
        {
            m_phaseProg += 1;
        }

        m_phaseRunning = true;

        if (timeOut > 0)
        {
            gui_start_timer(timeOut, timerCallback);
        }
    }

    /*
     * Start test case, and return how many phase you need to test
     * RETURNS:
     *  How many phase about this testcase
     */
    virtual S32 start(U32 caseID)
    {
        return 0;
    }

    /*
     * Start test case phase, and return how long time (ms) you need to take
     * PARAMETER
     *  [IN] the phase index, this value is zero based
     * RETURNS:
     *  How many time the phase takes, after this time, 
     *  Return < 0 means the phase time is not fixed.
     *  Maybe the testcase needs user's input. 
     *  After the phase is end, you should call endPhase.
     */
    virtual S32 phase(S32 phaseID)
    { 
        if(true == m_phaseRunning)
        {
            return SRV_IES_TST_RT_RUN_CUR_PHASE;
        }
        else if (m_phaseProg < m_phaseCount)
        {
            m_phaseRunning = false;
            return SRV_IES_TST_RT_DO_NEXT_PHASE;
        }
        else
        {
            return SRV_IES_TST_RT_END_TEST_CASE;
        }
    }

    /*
     * Verify whether the testcase is success
     */
    virtual void end()
    {
    }

    /*
     * Copy the result to the output buffer
     */
public:
    // Start the test case
    void testStart(U32 caseID)
    {
        s_pCurTest      = this;

        m_phaseProg     = 0;
        m_phaseCount    = start(caseID);
        m_phaseRunning  = true;

        gui_start_timer(0, timerCallback);
    }

    // End the test case
    void testEnd()
    {
        s_pCurTest = NULL;

        delete this;
    }

    void testReport(WCHAR *pString)
    {
        mmi_wcsncat(pString, m_testReport, SRV_IES_TST_LOG_MAX_LENGTH);
    }

};


class IESTestBase : public IESTestItem
{
protected:
    srv_ies_app_session_handle  m_hCurApp;
    srv_ies_image_handle        m_hCurImg;
    srv_ies_job_handle          m_hCurJob;
    U32                         m_heapSize;
    void                        *m_pHeapChunk;
    WCHAR                       m_testInput[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    WCHAR                       m_testOutput[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];

// Constructor / Destructor
public:
    IESTestBase():
        m_hCurApp(NULL),
        m_hCurImg(NULL),
        m_hCurJob(NULL),
        m_heapSize(1024 * 1024 * 5),
        m_pHeapChunk(NULL)
    {
        m_testInput[0]  = NULL;
        m_testOutput[0] = NULL;
    }

protected:
    void initTestFilePath()
    {
        const WCHAR *pCardPath;

        pCardPath = srv_fmgr_drv_get_path_by_type(SRV_FMGR_DRV_CARD_TYPE);
        mmi_wcsncat(m_testInput, pCardPath, SRV_FMGR_PATH_MAX_FILE_NAME_LEN); 
        mmi_wcsncat(m_testInput, (const WCHAR*)L"test_input.jpg", SRV_FMGR_PATH_MAX_FILE_NAME_LEN); 

        mmi_wcsncat(m_testOutput, pCardPath, SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
        mmi_wcsncat(m_testOutput, (const WCHAR*)L"test_output.jpg", SRV_FMGR_PATH_MAX_FILE_NAME_LEN); 
    }

    void initSession()
    {
        srv_ies_result result;

        initTestFilePath();

        // For testing, we simply MED alloc + ADM create
        m_pHeapChunk = (void*)med_alloc_ext_mem(m_heapSize);
        ASSERT(NULL != m_pHeapChunk);

        result = srv_ies_app_session_create(0,
                                            SRV_IES_FEATURE_ALL,
                                            m_pHeapChunk,
                                            m_heapSize,
                                            &m_hCurApp);
        ASSERT(SRV_IES_OK == result);
    }

    void initTestImage()
    {
        srv_ies_result result;

        initSession();

        result = srv_ies_image_create_from_file(m_hCurApp,
                                                (const WCHAR*)m_testInput,
                                                NULL,
                                                &m_hCurImg);
        ASSERT(SRV_IES_OK == result);
    }

    virtual S32 start(U32 caseID) 
    {
        srv_ies_result result;

        initTestImage();
 
        // TODO: currently m_hJob is unused.
        result = srv_ies_image_render_file_async(m_hCurImg,
                                                 (const WCHAR*)m_testOutput,
                                                 GDI_LCD_WIDTH,
                                                 GDI_LCD_HEIGHT,
                                                 SRV_IES_RENDER_KEEP_AR,
                                                 &onJobFinished,
                                                 this,
                                                 &m_hCurJob);
        if(SRV_IES_OK != result)
        {
            m_phaseRunning = false;
            fail((WCHAR*)L"srv_ies_image_render_file_async failed");

            return 0;
        }

        return 1;
    }

    virtual void end() 
    {
        if(m_hCurImg)
        {
            srv_ies_image_destroy(m_hCurImg);
            m_hCurImg = NULL;
        }

        if (NULL != m_hCurApp)
        {
            srv_ies_app_session_destroy(m_hCurApp);
            m_hCurApp = NULL;
        }

        if (NULL != m_pHeapChunk)
        {
            med_free_ext_mem(&m_pHeapChunk);
            m_pHeapChunk = NULL;
        }
    }
};

#endif  // SRV_IES_TESTBED_ENABLE
#endif  // __SRV_IMGEDT_TEST_H__
