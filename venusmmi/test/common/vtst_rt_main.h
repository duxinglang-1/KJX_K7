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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
 
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vtst_rt_main.h
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VTST_RT_MAIN_H__
#define __VTST_RT_MAIN_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
 
#include "vfx_uc_include.h"
#include "vfx_mc_include.h"

extern "C"
{
#include "kal_general_types.h"
#include "med_struct.h"
#include "MMIDataType.h"
}
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_app_cat_scr.h"
#include "vfx_text_frame.h"
#include "vfx_input_event.h"
#include "vfx_string.h"
#include "vfx_context.h"
#include "vfx_app.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_app_scr.h"
#include "vfx_archive.h"
#include "vfx_signal.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

#if defined(VENUS_UI_TEST) && (VENUS_UI_TEST == 1)
#define __MMI_VENUS_UI_TEST__
#endif

#define __AFX_RT_TEST__

enum VtstTestTypeEnum
{
    VTST_TT_DO, 
    VTST_TT_MENU,
    VTST_TT_TEST,
    VTST_TT_END_OF_ENUM
};

enum VtstTestResultEnum
{
    VTST_TR_FAIL = 0, 
    VTST_TR_OK, 
    VTST_TR_END_OF_ENUM
};

typedef VtstTestResultEnum (*VtstTestFuncPtr)(U32 param);  // Test invoke function pointer type

struct VtstMenuItem
{
    const VfxWChar     *title;          // Test title string
    VtstTestFuncPtr     testFuncPtr;    // Test invoke function
    U32                 param;          // Test userdata
    VtstTestTypeEnum    tt;             // Test type
};

struct VtstMenu
{
    const VfxWChar     *title;
    const VtstMenuItem *items;
    int                 count;
};

struct VtstMenuStack
{
    const VtstMenu     *menu;
    int                 focusIdx;
};

// Define Menu Macro:
// Example:
// VTST_BEGIN_DEF_MENU(L"Venus RT", main)
//     VTST_DEF_ITEM_DO(L"Auto test",      vtst_rt_auto_test, 0)
//     VTST_DEF_ITEM_MENU(L"Test Item",    venustest)
// VTST_END_DEF_MENU(main)


#define VTST_BEGIN_DEF_MENU(_title, _name) \
const VfxWChar *g_menu_title_##_name = (const VfxWChar *)(_title); \
static const VtstMenuItem g_items_##_name[] = {

#define VTST_END_DEF_MENU(_name) \
}; \
static const VtstMenu g_menu_##_name = { \
    g_menu_title_##_name, g_items_##_name, (sizeof(g_items_##_name) / sizeof(g_items_##_name[0])) \
};

#define VTST_DEF_ITEM_DO(_title, _func, _param) {(const VfxWChar *)_title, _func, (U32)_param, VTST_TT_DO},
#define VTST_DEF_ITEM_TEST(_title, _func, _param) {(const VfxWChar *)_title, _func, (U32)_param, VTST_TT_TEST},
#define VTST_DEF_ITEM_MENU(_title, _submenu) {(const VfxWChar *)_title, vtst_rt_menu_enter, (U32)&g_menu_##_submenu, VTST_TT_MENU},

#define VTST_MENU(_name) g_menu_##_name

#define VTST_START_SCRN(_SCR) \
do \
{ \
    vtst_rt_entry(); \
    VtstRtScr* scr = NULL; \
    VFX_OBJ_CREATE(scr, _SCR, VfxAppCatScr::getContext()); \
    vtst_testcase_start(scr, VFX_TRUE); \
} while(0)

#define VTST_START_SCRN_ROTATE(_SCR) \
do \
{ \
    vtst_rt_entry_rotate(); \
    VtstRtScr* scr = NULL; \
    VFX_OBJ_CREATE(scr, _SCR, VfxAppCatScr::getContext()); \
    vtst_testcase_start(scr, VFX_TRUE); \
} while(0)


/*****************************************************************************
 * Class IVtstRtScreenInterface
 *****************************************************************************/
#define VTST_RT_TESTCASE_NEEDCONFIRM (-1)
#define VTST_RT_END_TESTCASE (-5000)

class IVtstRtScreenInterface
{
// Method
public:
    // Query the final test result
    // RETURNS:
    //  VFX_TRUE if the test is successful
    virtual VfxBool getTestResult() = 0;

    // Timer handler to triggle phase change
    virtual void step() = 0;

    // Start the test case
    virtual void testStart() = 0;

    // End the test case
    virtual void testEnd() = 0;

    // start test case, and return how many phase you need to test
    // RETURNS:
    //  How many phase about this testcase.
    virtual VfxS32 start() = 0;

    // start test case phase, and return how long time (ms) you need to take
    // RETURNS:
    //  How many time the phase takes, after this time, 
    //  Return VTST_RT_TESTCASE_NEEDCONFIRM means the phase time is not fixed.
    //  Maybe the testcase needs user's input. 
    //  After the phase is end, you should call endPhase API.
    //  Return VTST_RT_END_TESTCASE you want to end the testcase.
    virtual VfxS32 phase(
        VfxS32 idx  // [IN] the phase index, this value is Zero index
    ) = 0;

    // Verify whether the testcase is success
    virtual void end() = 0;
};


/*****************************************************************************
 * Class VtstRtScr
 *****************************************************************************/

class VtstRtScr : public VfxAppCatScr, public IVtstRtScreenInterface
{
// Variable
public:
    VfxTextFrame    *m_title;
    VfxTextFrame    *m_status;
    
    VfxTextFrame    *m_message;
    VfxTextFrame    *m_yes;
    VfxTextFrame    *m_no;
    
    VfxBool         m_fail;
    VfxS32          m_phaseCount, m_phase;
    VfxBool         m_phasePendding;
    VfxBool         m_waitConfirm;

// Constructor / Destructor
public:
    // Default constructor
    VtstRtScr();

// Override
protected:
    virtual void onInit();
    virtual void onRotate(const VfxScreenRotateParam &param);
        
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    virtual VfxBool onPenInput(VfxPenEvent &event);

// Implementation
private:
    void layout();

// Method
public:
    // Set test title
    void setTitle(
        const VfxWString &title         // [IN] test title
    )
    {
        m_title->setString(VFX_WSTR_MEM(title));
    }

    // Set the status on the screen
    void setStatus(
        const VfxWString &status        // [IN] status string show on the screen
    )
    {
        m_status->setString(VFX_WSTR_MEM(status));
    }

    // Set the test case to fail
    void fail()
    {
        m_fail = VFX_TRUE;
    }

    // Verify the result. If the statement is false, the testcase fail.
    // And then the report will show testName is fail.
    VfxBool check(
        VfxBool statement,              // [IN] The check statement
        const VfxWString &testName      // [IN] The test item name
    );

    // Query the final test result
    // RETURNS:
    //  VFX_TRUE if the test is successful
    virtual VfxBool getTestResult()
    {
        return !m_fail;
    }

    // Timer handler to triggle phase change
    virtual void step();

    // Triggle to next phase when phase return 0
    void endPhase();

    // Show confirm string in the screen.
    // If user click LSK, the confirm is successful, and test will be continue.
    // If user click RSK, the test fail.
    void confirm(
        const VfxWString &message // [IN] the message show on the screen
    );

// Overridable
public:
    // start test case, and return how many phase you need to test
    // RETURNS:
    //  How many phase about this testcase
    virtual VfxS32 start() { return 0; }

    // start test case phase, and return how long time (ms) you need to take
    // RETURNS:
    //  How many time the phase takes, after this time, 
    //  Return < 0 means the phase time is not fixed.
    //  Maybe the testcase needs user's input. 
    //  After the phase is end, you should call endPhase.
    virtual VfxS32 phase(
        VfxS32 idx  // [IN] the phase index, this value is Zero index
    )
    { 
        VFX_UNUSED(idx);
        return VTST_RT_END_TESTCASE; 
    }

    // Verify whether the testcase is success
    virtual void end() {}

// Override
public:
    // Start the test case
    virtual void testStart();

    // End the test case
    virtual void testEnd();
};



/***************************************************************************** 
 * Class VtstRtApp
 *****************************************************************************/

struct VtstRtAppStartupParam
{
    VfxS32      memSize;
    VfxU8      *buffer;
    VfxContext *context;
};

class VtstRtApp : public VfxApp, public IVtstRtScreenInterface
{
    VFX_DECLARE_CLASS(VtstRtApp);

// Variables
protected:
    VfxBool         m_fail;
    VfxS32          m_phaseCount, m_phase;
    VfxBool         m_phasePendding;
    VfxBool         m_waitConfirm;
    
    VtstRtAppStartupParam m_startupParam;

// Constructor / Destructor
public:
    VtstRtApp();
    virtual ~VtstRtApp();

// Method
public:
    virtual void onRun(void* args, VfxU32 argSize);

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

public:

    // Set the test case to fail
    void fail();

    // Verify the result. If the statement is false, the testcase fail.
    // And then the report will show testName is fail.
    VfxBool check(
        VfxBool statement,              // [IN] The check statement
        const VfxWString &testName      // [IN] The test item name
    );

    // Query the final test result
    // RETURNS:
    //  VFX_TRUE if the test is successful
    virtual VfxBool getTestResult()
    {
        return !m_fail;
    }

    // Timer handler to triggle phase change
    virtual void step();

    // Triggle to next phase when phase return 0
    void endPhase();


    // Show confirm string in the screen.
    // If user click LSK, the confirm is successful, and test will be continue.
    // If user click RSK, the test fail.
    void confirm(
        const VfxWString &message // [IN] the message show on the screen
    )
    {
        VFX_UNUSED(message);
    }

// Overridable
public:
    // start test case, and return how many phase you need to test
    // RETURNS:
    //  How many phase about this testcase
    virtual VfxS32 start() { return 0; }

    // start test case phase, and return how long time (ms) you need to take
    // RETURNS:
    //  How many time the phase takes, after this time, 
    //  Return < 0 means the phase time is not fixed.
    //  Maybe the testcase needs user's input. 
    //  After the phase is end, you should call endPhase.
    virtual VfxS32 phase(
        VfxS32 idx  // [IN] the phase index, this value is Zero index
    )
    {
        VFX_UNUSED(idx);
        return VTST_RT_END_TESTCASE; 
    }

    // Verify whether the testcase is success
    virtual void end() {}

// Override
public:
    // Start the test case
    virtual void testStart();

    // End the test case
    virtual void testEnd();
};


/***************************************************************************** 
 * class VtstRtAppScr
 *****************************************************************************/

class VtstRtAppScr;

typedef VfxCallback2 <
    VtstRtAppScr*, // sender
    VfxBool             // confirm result
> 
VtstRtAppScrConfirmCB;

class VtstRtAppScr : public VfxAppScr
{
    VFX_DECLARE_CLASS(VtstRtAppScr);

// Constructor / Destructor
public:
    VtstRtAppScr();

// Override
protected:
    virtual void onInit();
    virtual VfxBool onSerialize(VfxArchive &ar);
    virtual void onRestore(VfxArchive &ar);

// Method
public:
    // Set test title
    void setTitle(
        const VfxWString &title     // [IN] test title
    );

    // Set the status on the screen
    void setStatus(
        const VfxWString &status    // [IN] status string show on the screen
    );
    
    // Set whether the screen can be serialized
    void setSerializable(VfxBool v)
    {
        m_bSerializable = v;
    }

    void confirm(
        const VfxWString &message, 
        VtstRtAppScrConfirmCB cb = VFX_CALLBACK_NULL
    );

    virtual VfxBool onKeyInput(VfxKeyEvent &event);

// Variable
public:
    VfxTextFrame            *m_title;
    VfxTextFrame            *m_status;
    VtstRtAppScrConfirmCB   m_confirmCB;

public:
    VfxBool         m_bSerializable;
};


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

extern void vtst_rt_entry(void);
extern void vtst_rt_entry_rotate(void);
extern void vtst_rt_leave(void);
extern void vtst_rt_autotest_trigger(void);
extern void vtst_rt_autotest_result_entry(void);
extern void vtst_rt_proc_call(media_in_proc_call_type func, kal_uint32 func_arg1, void *func_arg2);
extern void vtst_add_fail_log(const VfxWChar *testName);
extern void vtst_rt_verify(void);
extern void vtst_rt_autotest_step(void);
extern void vtst_rt_autotest_result_entry(void);
extern void vtst_rt_autotest_trigger(void);
extern void vtst_rt_testcase_step(void);
extern void vtst_testcase_start(IVtstRtScreenInterface* testcase, VfxBool isCategory);
extern void vtst_testcase_end();

// This is main entry function for our testing
extern "C" void vtst_rt_main_entry(void);


#endif // __VTST_RT_MAIN_H__


