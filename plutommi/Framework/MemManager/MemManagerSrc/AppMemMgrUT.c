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
 *  AppMemMgrUT.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Unit Test for App-Based Shared Memory Manager
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "mmi_frm_gprot.h"
#include "GlobalDefs.h"
#include "app_mem.h"
#include "mmi_frm_prot.h"
#include "CommonScreensEnum.h"
#include "CommonScreens.h"
#include "SettingProfile.h"         /* for tone ID */
#include "wgui_categories_fmgr.h"   /* Category 212 */
#include "mmiapi_func.h"
#include "wgui_categories_popup.h"
#include "CallmanagementGprot.h"    /* Check incoming call */
#include "custom_events_notify.h"
#include "UCMGProt.h"
#include "UcmSrvGprot.h"
#include "App_mem.h"
#include "mmi_rp_framework_asm_def.h"
#include "mmi_frm_mem_prot.h"
#include "TimerEvents.h"
#include "CommonScreensResDef.h"
#include "IdleGprot.h"
#include "wgui_categories_util.h"
#include "wgui_categories_text_viewer.h"
#include "wgui_fixed_menus.h"
#include "app_mem_med.h"
//#include "mmi_rp_app_data.h"
//#include "mmi_rp_all_defs.h"
#include "mmi_frm_app_launcher_gprot.h"

#if defined(APPLIB_MEM_UNIT_TEST)
/***************************************************************************** 
 * Unit Test 
 *****************************************************************************/
#include "IdleAppProt.h"
#include "PsCallHelperDef.h"
#include "stdlib.h"

/***************************************************************************** 
 * Define 
 *****************************************************************************/


#define ASM_UT_POOL_SIZE            (mmi_frm_asm_get_pool_size_r())
#define MMI_FRM_APPMEM_TEST1_SIZE   (ASM_UT_POOL_SIZE / 5)
#define MMI_FRM_APPMEM_TEST2_SIZE   (ASM_UT_POOL_SIZE * 2 /5)
#define MMI_FRM_APPMEM_TEST3_SIZE   (ASM_UT_POOL_SIZE * 3 / 5)
#define MMI_FRM_APPMEM_TEST4_SIZE   (ASM_UT_POOL_SIZE * 4 / 5)
#define MMI_FRM_APPMEM_TEST5_SIZE   (ASM_UT_POOL_SIZE)

/* start index of APPs */
#define TEST_ITEM_START     (2)
/* no. of unit-test menu items */
#define TEST_ITEM_NUM       (sizeof(g_appmem_ut_test_func)/sizeof(void*) + TEST_ITEM_START)
/* string length of menu items */
#define TEST_ITEM_STR_LEN   (30)
/* popup time for each APP */
#define TEST_APP_POPUP_TIME (500)   /* ms */

/* UT type */
#define UT_END_PROGRESS_SCRN    1
#define UT_UCM_PROGRESS_SCRN    2
#define UT_UCM_STARTNEW_SCRN    3

/* ASM test timer */

#define ASM_TEST_TIMER(_asm_id)  (KEY_TIMER_ID_NONE + _asm_id - APPLIB_MEM_AP_ID_DUMMY)
typedef void (* sg_func)(MMI_ID sg_id);
/***************************************************************************** 
 * Local function 
 *****************************************************************************/
static void mmi_frm_appmem_ut_2nd_entry(S32 selected_item);
static void mmi_frm_appmem_ut_hilight_hdlr(S32 index);
static void mmi_frm_appmem_ut_start(void);
static void mmi_frm_ut_app_entry(void *arg);
static void mmi_frm_appmem_ut_regress_test(void);
static void mmi_frm_appmem_ut_execute_key_hdlr(S16 key_code);
static MMI_BOOL mmi_frm_appmem_ut_app_is_running(applib_mem_ap_id_enum app_id);
static void mmi_frm_appmem_ut_sg_end_key_start_new_int(sg_func start_app);
static void mmi_frm_appmem_ut_sg_end_key_progressing_int(sg_func callback);
static void mmi_frm_appmem_ut_sg_end_key_start_new_int(sg_func start_app);
static void mmi_frm_appmem_ut_sg_ucm_behavior_startnew_scrn_int(sg_func start_app);
static void mmi_frm_appmem_ut_sg_cancel_goback_from_prompt_int(sg_func start_app);
static void mmi_frm_appmem_ut_sg_interrupt_in_start_new_int(sg_func start_app);
static void mmi_frm_appmem_ut_sg_interrupt_in_stop_popup_int(sg_func start_app);
static void mmi_frm_appmem_ut_sg_interrupt_gobacktoidle_invoke_cancelcb_int(sg_func start_app);
static void mmi_frm_appmem_ut_sg_ucm_behavior_progress_scrn_int(sg_func start_app);
extern void mmi_frm_asm_test_case_entry(U8 index);
extern MMI_BOOL mmi_frm_appmem_unit_test_setup_environment(void);
extern void mmi_frm_appmem_unit_test_prepare_to_enter_test1(void (*run_callback)(void *arg), MMI_BOOL clear_all);
extern void mmi_frm_appmem_unit_test_prepare_to_enter_test2(void (*run_callback)(void *arg), MMI_BOOL clear_all);
extern void mmi_frm_appmem_unit_test_prepare_to_enter_test3(void (*run_callback)(void *arg), MMI_BOOL clear_all);
extern void mmi_frm_appmem_unit_test_prepare_to_enter_test4(void (*run_callback)(void *arg), MMI_BOOL clear_all);
extern void mmi_frm_appmem_unit_test_prepare_to_enter_test5(void (*run_callback)(void *arg), MMI_BOOL clear_all);
/***************************************************************************** 
 * Local variable 
 *****************************************************************************/
/* test function for each APP */
void (*g_appmem_ut_test_func[])(void (*run_callback)(void *), MMI_BOOL) = {
    mmi_frm_appmem_unit_test_prepare_to_enter_test1,
    mmi_frm_appmem_unit_test_prepare_to_enter_test2,
    mmi_frm_appmem_unit_test_prepare_to_enter_test3,
    mmi_frm_appmem_unit_test_prepare_to_enter_test4,
    mmi_frm_appmem_unit_test_prepare_to_enter_test5};


/* structure for appmem unit-test variables */
typedef struct {
    S32 selected_item;
    S32 bg_free_app_index;
    S8 item_list_str[TEST_ITEM_NUM][TEST_ITEM_STR_LEN*ENCODING_LENGTH];
    S8 *item_list[TEST_ITEM_NUM];
} mmi_frm_appmem_ut_context_struct;

/* appmem unit-test context variable */
static mmi_frm_appmem_ut_context_struct g_appmem_ut_cntx = {
    /* selected_item */
    TEST_ITEM_START,
    0,
    /* item_list_str */
    {
    "",
    /* "Free All TEST Memory" */
    "F\0r\0e\0e\0 \0A\0l\0l\0 \0T\0E\0S\0T\0 \0M\0e\0m\0o\0r\0y\0\0\0"}
};

typedef struct
{
    applib_mem_ap_id_enum   app_id;
} mmi_frm_ut_app_entry_arg_struct;

static applib_mem_ap_id_enum g_current_running_app = APPLIB_MEM_AP_ID_DUMMY;
static MMI_BOOL g_mmi_frm_appmem_ut_regress = MMI_FALSE;
/* Some test case will start timer for async working flow, we have to break regress test flow. */
static MMI_BOOL g_mmi_frm_appmem_ut_break_flow = MMI_FALSE;
static S8 g_mmi_frm_appmem_ut_case_idx;
static U8 asm_ut_type;
static MMI_BOOL cancel_cb_is_called;
MMI_BOOL is_group_case = MMI_FALSE;
static mmi_frm_appmem_event_type_enum cui_hasm_cancel_type;
static void (*g_mmi_frm_appmem_unit_test_run_callback1)(void *);
static void (*g_mmi_frm_appmem_unit_test_run_callback2)(void *);
static void (*g_mmi_frm_appmem_unit_test_run_callback3)(void *);
static void (*g_mmi_frm_appmem_unit_test_run_callback4)(void *);
static void (*g_mmi_frm_appmem_unit_test_run_callback5)(void *);
static void mmi_frm_appmem_ut_sg_screen_enter1(void);
static void mmi_frm_appmem_ut_sg_screen_enter2(void);
static void mmi_frm_appmem_ut_sg_screen_enter3(void);
static void mmi_frm_appmem_ut_sg_screen_enter4(void);
static void mmi_frm_appmem_ut_sg_screen_enter5(void);

static FuncPtr mmi_frm_appmem_ut_sg_screen_enter_func[5] = {
                                                         mmi_frm_appmem_ut_sg_screen_enter1,
                                                         mmi_frm_appmem_ut_sg_screen_enter2,
                                                         mmi_frm_appmem_ut_sg_screen_enter3,
                                                         mmi_frm_appmem_ut_sg_screen_enter4,
                                                         mmi_frm_appmem_ut_sg_screen_enter5,
                                                     };




static void mmi_frm_appmem_unit_test_stop_1_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST1);
    if (is_group_case)
    {
        mmi_frm_group_close(APPLIB_MEM_AP_ID_TEST1);
    }
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_TEST1, KAL_TRUE);
}


static void mmi_frm_appmem_unit_test_stop_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST1), 5000, mmi_frm_appmem_unit_test_stop_1_timer_hdlr);
}


static void mmi_frm_appmem_unit_test_stop_2_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST2);
    if (is_group_case)
    {
        mmi_frm_group_close(APPLIB_MEM_AP_ID_TEST2);
    }
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_TEST2, KAL_TRUE);
}


static void mmi_frm_appmem_unit_test_stop_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST2), 300, mmi_frm_appmem_unit_test_stop_2_timer_hdlr);
}


static void mmi_frm_appmem_unit_test_stop_3_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST3);
    if (is_group_case)
    {
        mmi_frm_group_close(APPLIB_MEM_AP_ID_TEST3);
    }   
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_TEST3, KAL_TRUE);
}


static void mmi_frm_appmem_unit_test_stop_3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST3), 3000, mmi_frm_appmem_unit_test_stop_3_timer_hdlr);
}


static void mmi_frm_appmem_unit_test_stop_4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST4);        
    /* Return immediately */
    if (is_group_case)
    {
        mmi_frm_group_close(APPLIB_MEM_AP_ID_TEST4);
    }
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_TEST4, KAL_TRUE);
}


static void mmi_frm_appmem_unit_test_stop_5(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Return immediately */
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_TEST5, KAL_FALSE); /* Fail */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_success_callback1
 * DESCRIPTION
 *  Callback function when memory was released.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_unit_test_success_callback1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_ut_app_entry_arg_struct arg;
    void *ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST1, MMI_FRM_APPMEM_TEST1_SIZE);
    MMI_ASSERT(ptr);
    arg.app_id = APPLIB_MEM_AP_ID_TEST1;
    g_mmi_frm_appmem_unit_test_run_callback1((void *)&arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_prepare_to_enter_test1
 * DESCRIPTION
 *  Simple program to test screen-based ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_unit_test_prepare_to_enter_test1(
    void (*run_callback)(void *),
    MMI_BOOL clear_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clear_all)
        applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST1);
    
    g_mmi_frm_appmem_unit_test_run_callback1 = run_callback;
    if (applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST1, MMI_FRM_APPMEM_TEST1_SIZE))
    {
        mmi_frm_ut_app_entry_arg_struct arg;
        arg.app_id = APPLIB_MEM_AP_ID_TEST1;
        run_callback((void *)&arg);
    }
    else
    {
        mmi_frm_appmem_prompt_to_release_mem(
            APPLIB_MEM_AP_ID_TEST1,
            IMG_GLOBAL_L1,
            MMI_FRM_APPMEM_TEST1_SIZE,
            mmi_frm_appmem_unit_test_success_callback1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_success_callback2
 * DESCRIPTION
 *  Callback function when memory was released.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_unit_test_success_callback2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_ut_app_entry_arg_struct arg;
    void *ptr;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST2, MMI_FRM_APPMEM_TEST2_SIZE);
    MMI_ASSERT(ptr);
    
    arg.app_id = APPLIB_MEM_AP_ID_TEST2;
    g_mmi_frm_appmem_unit_test_run_callback2((void *)&arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_prepare_to_enter_test2
 * DESCRIPTION
 *  Simple program to test screen-based ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_unit_test_prepare_to_enter_test2(
    void (*run_callback)(void *),
    MMI_BOOL clear_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clear_all)
        applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST2);

    g_mmi_frm_appmem_unit_test_run_callback2 = run_callback;    
    if (applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST2, MMI_FRM_APPMEM_TEST2_SIZE))
    {
        mmi_frm_ut_app_entry_arg_struct arg;
        arg.app_id = APPLIB_MEM_AP_ID_TEST2;
        run_callback((void *)&arg);

    }
    else
    {
        mmi_frm_appmem_prompt_to_release_mem(
            APPLIB_MEM_AP_ID_TEST2,
            IMG_GLOBAL_L2,
            MMI_FRM_APPMEM_TEST2_SIZE,
            mmi_frm_appmem_unit_test_success_callback2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_success_callback3
 * DESCRIPTION
 *  Callback function when memory was released.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_unit_test_success_callback3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_ut_app_entry_arg_struct arg;
    void *ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST3, MMI_FRM_APPMEM_TEST3_SIZE);
    MMI_ASSERT(ptr);
    arg.app_id = APPLIB_MEM_AP_ID_TEST3;
    g_mmi_frm_appmem_unit_test_run_callback3((void *)&arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_prepare_to_enter_test3
 * DESCRIPTION
 *  Simple program to test screen-based ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_unit_test_prepare_to_enter_test3(
    void (*run_callback)(void *),
    MMI_BOOL clear_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clear_all)
        applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST3);

    g_mmi_frm_appmem_unit_test_run_callback3 = run_callback;    
    if (applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST3, MMI_FRM_APPMEM_TEST3_SIZE))
    {
        mmi_frm_ut_app_entry_arg_struct arg;
        arg.app_id = APPLIB_MEM_AP_ID_TEST3;
        run_callback((void *)&arg);

    }
    else
    {
        mmi_frm_appmem_prompt_to_release_mem(
            APPLIB_MEM_AP_ID_TEST3,
            IMG_GLOBAL_L3,
            MMI_FRM_APPMEM_TEST3_SIZE,
            mmi_frm_appmem_unit_test_success_callback3);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_success_callback4
 * DESCRIPTION
 *  Callback function when memory was released.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_unit_test_success_callback4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_ut_app_entry_arg_struct arg;
    void *ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST4, MMI_FRM_APPMEM_TEST4_SIZE);
    MMI_ASSERT(ptr);
    arg.app_id = APPLIB_MEM_AP_ID_TEST4;
    g_mmi_frm_appmem_unit_test_run_callback4((void *)&arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_prepare_to_enter_test4
 * DESCRIPTION
 *  Simple program to test screen-based ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_unit_test_prepare_to_enter_test4(
    void (*run_callback)(void *),
    MMI_BOOL clear_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clear_all)
        applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST4);

    g_mmi_frm_appmem_unit_test_run_callback4 = run_callback;    
    if (applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST4, MMI_FRM_APPMEM_TEST4_SIZE))
    {
        mmi_frm_ut_app_entry_arg_struct arg;
        arg.app_id = APPLIB_MEM_AP_ID_TEST4;
        run_callback((void *)&arg);
    }
    else
    {
        mmi_frm_appmem_prompt_to_release_mem(
            APPLIB_MEM_AP_ID_TEST4,
            IMG_GLOBAL_L4,
            MMI_FRM_APPMEM_TEST4_SIZE,
            mmi_frm_appmem_unit_test_success_callback4);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_success_callback5
 * DESCRIPTION
 *  Callback function when memory was released.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_unit_test_success_callback5(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_ut_app_entry_arg_struct arg;
    void *ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST5, MMI_FRM_APPMEM_TEST5_SIZE);
    MMI_ASSERT(ptr);
    arg.app_id = APPLIB_MEM_AP_ID_TEST5;
    g_mmi_frm_appmem_unit_test_run_callback5((void *)&arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_prepare_to_enter_test5
 * DESCRIPTION
 *  Simple program to test screen-based ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_unit_test_prepare_to_enter_test5(void (*run_callback)(void *), MMI_BOOL clear_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clear_all)
        applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST5);

    g_mmi_frm_appmem_unit_test_run_callback5 = run_callback;    
    if (applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST5, MMI_FRM_APPMEM_TEST5_SIZE))
    {
        mmi_frm_ut_app_entry_arg_struct arg;
        arg.app_id = APPLIB_MEM_AP_ID_TEST5;
        run_callback((void *)&arg);
    }
    else
    {
        mmi_frm_appmem_prompt_to_release_mem(
            APPLIB_MEM_AP_ID_TEST5,
            IMG_GLOBAL_L5,
            MMI_FRM_APPMEM_TEST5_SIZE,
            mmi_frm_appmem_unit_test_success_callback5);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_register_app
 * DESCRIPTION
 *  register app 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_frm_appmem_ut_register_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static MMI_BOOL first_time = MMI_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (first_time)
    {
        first_time = MMI_FALSE;
        
        applib_mem_ap_register(
            APPLIB_MEM_AP_ID_TEST1, 
            STR_GLOBAL_1, 
            IMG_GLOBAL_L1, 
            mmi_frm_appmem_unit_test_stop_1);
        applib_mem_ap_register(
            APPLIB_MEM_AP_ID_TEST2, 
            STR_GLOBAL_2, 
            IMG_GLOBAL_L2, 
            mmi_frm_appmem_unit_test_stop_2);
        applib_mem_ap_register(
            APPLIB_MEM_AP_ID_TEST3, 
            STR_GLOBAL_3, 
            IMG_GLOBAL_L3, 
            mmi_frm_appmem_unit_test_stop_3);
        applib_mem_ap_register(
            APPLIB_MEM_AP_ID_TEST4, 
            STR_GLOBAL_4, 
            IMG_GLOBAL_L4, 
            mmi_frm_appmem_unit_test_stop_4);
        applib_mem_ap_register(
            APPLIB_MEM_AP_ID_TEST5, 
            STR_GLOBAL_5, 
            IMG_GLOBAL_L5, 
            mmi_frm_appmem_unit_test_stop_5);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_setup_environment
 * DESCRIPTION
 *  Setup unit test environment, register app and go back to idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  none
 *****************************************************************************/
MMI_BOOL mmi_frm_appmem_unit_test_setup_environment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_register_app();
    g_mmi_frm_appmem_ut_break_flow = MMI_FALSE;

#ifdef __PLUTO_MMI_PACKAGE__
	if (!mmi_idle_is_active())
#else
    if (!vapp_launcher_is_active())
#endif
	{
        mmi_idle_display();
	    StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST5), 500, mmi_frm_appmem_ut_regress_test);
        return MMI_FALSE;
    }

    return MMI_TRUE;
}

static void mmi_frm_ut_app_exit(void *arg)
{
 
    if (mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST2))
        applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST2);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_ut_app_entry
 * DESCRIPTION
 *  entry function for APP N
 * PARAMETERS
 *  none
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_ut_app_entry(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_idx = STR_GLOBAL_1;
    mmi_frm_ut_app_entry_arg_struct *data = (mmi_frm_ut_app_entry_arg_struct *)arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_entry_new_screen((U16)(GLOBAL_SCR_DUMMY + (str_idx - (U16)STR_GLOBAL_0)), mmi_frm_ut_app_exit, mmi_frm_ut_app_entry, NULL);

    if (!CheckIsBackHistory())
	{
		g_current_running_app = data->app_id;
	}
 
    ShowCategory53Screen(
        str_idx + g_current_running_app - APPLIB_MEM_AP_ID_TEST1,
        IMG_GLOBAL_INFO,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        0,
        NULL,
        NULL,
        NULL,
        0, 0, NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    

}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_start
 * DESCRIPTION
 *  key handler to start unit-test function
 * PARAMETERS
 *  none
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_appmem_ut_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* execute selected item */
    if (g_appmem_ut_cntx.selected_item == 0)
    {
        /* update memory info., do nothing here */
    }
    else if (g_appmem_ut_cntx.selected_item == 1)
    {
    }
    else if (g_appmem_ut_cntx.selected_item >= TEST_ITEM_START)
    {
        if (g_appmem_ut_test_func[g_appmem_ut_cntx.selected_item-TEST_ITEM_START])
        {
            g_appmem_ut_test_func[g_appmem_ut_cntx.selected_item-TEST_ITEM_START](
                    mmi_frm_ut_app_entry, MMI_FALSE);
        }
    }
    
    /* redraw screen to update display info */
    if (GetActiveScreenId() == SCR_FRM_UNIT_TEST)
        mmi_frm_appmem_ut_2nd_entry(g_appmem_ut_cntx.selected_item);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_hilight_hdlr
 * DESCRIPTION
 *  high light handler
 * PARAMETERS
 *  index   [IN]    high-lighted item
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_appmem_ut_hilight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_appmem_ut_cntx.selected_item = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_2nd_entry
 * DESCRIPTION
 *  display main appmem unit-test screen
 * PARAMETERS
 *  selected_item   [IN]    selected item
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_appmem_ut_2nd_entry(S32 selected_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 tmp_str[TEST_ITEM_STR_LEN*ENCODING_LENGTH];
    U16 icon_list[TEST_ITEM_NUM+1];
    S32 i;
    U8 *gui_buffer;
    U32 size[] = 
        {
            MMI_FRM_APPMEM_TEST1_SIZE,
            MMI_FRM_APPMEM_TEST2_SIZE, 
            MMI_FRM_APPMEM_TEST3_SIZE,
            MMI_FRM_APPMEM_TEST4_SIZE,
            MMI_FRM_APPMEM_TEST5_SIZE
        };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(TEST_ITEM_NUM < (IMG_GLOBAL_LEND-IMG_GLOBAL_LSTART));

    /* update memory info */
    sprintf(tmp_str, "Max. To Alloc: %d", applib_mem_ap_get_max_alloc_size());
    mmi_asc_to_ucs2(g_appmem_ut_cntx.item_list_str[0], tmp_str);

    /* initialize string data for each menu item */
    for (i=0; i<(TEST_ITEM_NUM-TEST_ITEM_START); i++)
    {
        sprintf(tmp_str, "APP %d, %d ", i+1, size[i]);
        mmi_asc_to_ucs2(g_appmem_ut_cntx.item_list_str[i+TEST_ITEM_START], tmp_str);
        icon_list[TEST_ITEM_START+i] = IMG_GLOBAL_LSTART+(i+1);
    }
    icon_list[TEST_ITEM_NUM] = 0;

    gui_buffer = GetCurrGuiBuffer(SCR_FRM_UNIT_TEST);
    RegisterHighlightHandler(mmi_frm_appmem_ut_hilight_hdlr);

    ShowCategory53Screen(
        0,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        TEST_ITEM_NUM,
        (U8 **)g_appmem_ut_cntx.item_list,
        icon_list,
        NULL,
        0, g_appmem_ut_cntx.selected_item, gui_buffer);

    SetLeftSoftkeyFunction(mmi_frm_appmem_ut_start, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);    
}


static mmi_ret mmi_frm_appmem_ut_pre_key_proc(mmi_event_struct *evt)
{
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;

    if (key_evt->key_code == KEY_VOL_UP && key_evt->key_type == KEY_EVENT_DOWN)
    {
        switch (g_appmem_ut_cntx.bg_free_app_index)
        {
            case 1:
                    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST1);
                    mmi_frm_group_close(APPLIB_MEM_AP_ID_TEST1);
                break;
            case 2:
                applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST2);
                mmi_frm_group_close(APPLIB_MEM_AP_ID_TEST2);

                break;
            case 3:
                applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST3);
                mmi_frm_group_close(APPLIB_MEM_AP_ID_TEST3);

                break;
            case 4:
                applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST4);
                mmi_frm_group_close(APPLIB_MEM_AP_ID_TEST4);

                break;
            case 5:
                applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST5);
                mmi_frm_group_close(APPLIB_MEM_AP_ID_TEST5);

                break;
        }
        
        return MMI_RET_OK;
    }
    switch (key_evt->key_code)
    {
        case KEY_1:
            g_appmem_ut_cntx.bg_free_app_index = 1;
            break;
        case KEY_2:
            g_appmem_ut_cntx.bg_free_app_index = 2;
            break;
        case KEY_3:
            g_appmem_ut_cntx.bg_free_app_index = 3;
            break;
            
        case KEY_4:
            g_appmem_ut_cntx.bg_free_app_index = 4;
            break;
            
        case KEY_5:
            g_appmem_ut_cntx.bg_free_app_index = 5;
            break;
    }
    return MMI_RET_OK;	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_entry
 * DESCRIPTION
 *  appmem unit-test screen entry function.
 * PARAMETERS
 *  none
 * RETURNS
 *  none
 *****************************************************************************/
void mmi_frm_appmem_ut_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_FRM_UNIT_TEST, NULL, mmi_frm_appmem_ut_entry, NULL);

    mmi_frm_cb_reg_event(EVT_ID_PRE_KEY_EVT_ROUTING, mmi_frm_appmem_ut_pre_key_proc, NULL);

    mmi_frm_appmem_ut_register_app();

    /* link item string data */
    for (i=0; i<TEST_ITEM_NUM; i++)
    {
        g_appmem_ut_cntx.item_list[i] = g_appmem_ut_cntx.item_list_str[i];
    }

    /* screen display */
    mmi_frm_appmem_ut_2nd_entry(g_appmem_ut_cntx.selected_item);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_execute_key_hdlr
 * DESCRIPTION
 *  Execute key handler with event down and up.
 * PARAMETERS
 *  key_code    [IN]    key code
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_execute_key_hdlr(S16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecuteCurrKeyHandler(key_code, KEY_EVENT_DOWN);
    ExecuteCurrKeyHandler(key_code, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_start_app
 * DESCRIPTION
 *  Start application registered app asm.
 * PARAMETERS
 *  app_id      [IN]    application id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_start_app(MMI_ID app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 app_idx = app_id - APPLIB_MEM_AP_ID_TEST1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_appmem_ut_test_func[app_idx])
    {
        g_appmem_ut_test_func[app_idx](mmi_frm_ut_app_entry, MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_check_app_in_list_int
 * DESCRIPTION
 *  Check if app has allocated app asm and in prompt screen list.
 * PARAMETERS
 *  app_id          [IN]    application id
 *  will_stop_app   [IN]    if need to stop application
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
static MMI_BOOL mmi_frm_appmem_ut_check_app_in_list_int(applib_mem_ap_id_enum app_id, MMI_BOOL will_stop_app)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hilite_item, curr_hilit_item;
    applib_mem_ap_usage_struct app_list[5];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	curr_hilit_item = GetHighlightedItem();
	hilite_item = curr_hilit_item;
	mmi_frm_asm_get_applist_in_pool(app_list, 5);
    do {
        if (app_list[hilite_item].app_id == (kal_uint32)app_id)
        {
            if (will_stop_app)
            {
                /* Select application */
                mmi_frm_appmem_ut_execute_key_hdlr(KEY_LSK);
                /* Stop application */
                mmi_frm_appmem_ut_execute_key_hdlr(KEY_LSK);
            }
            return MMI_TRUE;
        }
        else
        {
            fixed_list_goto_next_item();
			hilite_item = GetHighlightedItem();
            if (curr_hilit_item == hilite_item) 
                break;
        }
    } while(hilite_item < MMI_FRM_APPMEM_MAX_APP_PROMPTED);

	return MMI_FALSE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_stop_app
 * DESCRIPTION
 *  Stop app which has allocated app asm and in prompt screen list.
 * PARAMETERS
 *  app_id          [IN]    application id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_frm_appmem_ut_stop_app(applib_mem_ap_id_enum app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    return mmi_frm_appmem_ut_check_app_in_list_int(app_id, MMI_TRUE);
#else
    return MMI_TRUE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_app_is_running
 * DESCRIPTION
 *  Check if app is running.
 * PARAMETERS
 *  app_id          [IN]    application id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_frm_appmem_ut_app_is_running(applib_mem_ap_id_enum app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_current_running_app == app_id) ? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_go_back_to_idle
 * DESCRIPTION
 *  This api will make sure going back to idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_frm_appmem_ut_go_back_to_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_display();

	if (!mmi_idle_is_active())
	{
		StartTimer(KEY_TIMER_ID_NONE, 500, (FuncPtr)mmi_frm_appmem_ut_go_back_to_idle);
        return MMI_FALSE;
    }
    else
    {
        StopTimer(KEY_TIMER_ID_NONE);
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_regress_test
 * DESCRIPTION
 *  If regress test has been broken, use this api to continue to test the following 
 *  test cases with g_mmi_frm_appmem_ut_case_idx.
 *  Moreover, this api will make sure the test case must be launched in idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_regress_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_FALSE == mmi_frm_appmem_ut_go_back_to_idle())
    {
		StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST5+1), 3000, mmi_frm_appmem_ut_regress_test);
        return;
    }
    g_mmi_frm_appmem_ut_break_flow = MMI_FALSE;
    mmi_frm_asm_test_case_entry(g_mmi_frm_appmem_ut_case_idx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_reset_context
 * DESCRIPTION
 *  Reset unit test context, free all memory, reset asm manager, go back to idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_reset_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_ap_id_enum app_id;    
    mmi_id g_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (app_id = APPLIB_MEM_AP_ID_TEST1; app_id <= APPLIB_MEM_AP_ID_TEST5; app_id++)
    {
        applib_mem_ap_free_all((kal_uint32)app_id);
    }
    if (mmi_frm_asm_manager_is_launched(&g_id))
    {
        mmi_frm_group_close(g_id);
    }
    /* Reset flag which used for each test case */
    g_current_running_app = APPLIB_MEM_AP_ID_DUMMY;
    cancel_cb_is_called = MMI_FALSE;
    is_group_case = MMI_FALSE;
    asm_ut_type = 0;
    cui_hasm_cancel_type = MMI_FRM_APPMEM_CANCEL_TYPE_TOTAL;
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {/* Make sure go back to idle from incoming call since it'll invoke some popup screens. */
        //g_mmi_frm_appmem_ut_break_flow = MMI_TRUE;
        StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST5+2), 5000, mmi_frm_appmem_ut_regress_test);
    }
    mmi_idle_display();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_behavior_timer_hdlr
 * DESCRIPTION
 *  Async test timer handler, to check the result of test cases.
 *  If regress test flow has been broken, start timer to continue the test flow.
 *  When the regression test end go back to idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_behavior_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (asm_ut_type)
    {
        case UT_END_PROGRESS_SCRN:
        case UT_UCM_PROGRESS_SCRN:
        case UT_UCM_STARTNEW_SCRN:
        {
            MMI_ASSERT(!mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST4));
        #ifdef __MMI_FRM_ASM_OOM_SCREEN__
            MMI_ASSERT(mmi_frm_asm_get_manger_state() == MMI_FRM_ASM_MANAGER_STATE_CANCELED);
        #endif
            MMI_ASSERT(cancel_cb_is_called);
            break;
        }
        default:
            break;
    }

    if (g_mmi_frm_appmem_ut_regress && g_mmi_frm_appmem_ut_break_flow)
    {
        StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST5+4), 100, mmi_frm_appmem_ut_regress_test);
        g_mmi_frm_appmem_ut_break_flow = MMI_FALSE;
    }

    /* Regression test: all cases have been tested, need to reset and go back to idle. */
    if (g_mmi_frm_appmem_ut_regress && g_mmi_frm_appmem_ut_case_idx == -1)
    {
        mmi_frm_appmem_ut_go_back_to_idle();
        g_mmi_frm_appmem_ut_regress = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_end_cancel_cb
 *  mmi_frm_appmem_ut_ucm_cancel_cb
 *  mmi_frm_appmem_ut_back_cancel_cb
 *  mmi_frm_appmem_ut_back_cancel_cb
 * DESCRIPTION
 * Cancel callback for each unit test.
 * PARAMETERS
 *  info        [IN]    cancel info
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_end_cancel_cb(mmi_frm_appmem_evt_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_evt_struct *p = info;

    cancel_cb_is_called = MMI_TRUE;
    MMI_ASSERT(p->evt_type == MMI_FRM_APPMEM_CANCEL_BY_END_KEY);
}

static void mmi_frm_appmem_ut_ucm_cancel_cb(mmi_frm_appmem_evt_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     mmi_frm_appmem_evt_struct *p = info;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_group_case)
        mmi_frm_group_close(info->app_id);
    cancel_cb_is_called = MMI_TRUE;
    MMI_ASSERT(p->evt_type == MMI_FRM_APPMEM_CANCEL_BY_UCM_CALL);
}


static void mmi_frm_appmem_ut_back_cancel_cb(mmi_frm_appmem_evt_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     mmi_frm_appmem_evt_struct *p = info;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_group_case)
        mmi_frm_group_close(info->app_id);
    cancel_cb_is_called = MMI_TRUE;
    MMI_ASSERT(p->evt_type == MMI_FRM_APPMEM_CANCEL_BACK_FROM_PROMPT_SCRN);
}


static void mmi_frm_appmem_ut_interrupt_cancel_cb(mmi_frm_appmem_evt_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     mmi_frm_appmem_evt_struct *p = info;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    cancel_cb_is_called = MMI_TRUE;
    MMI_ASSERT(p->evt_type == MMI_FRM_APPMEM_CANCEL_DEL_BY_INTERRUPT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_end_key_behavior_progress_scrn
 * DESCRIPTION
 * Test END key behavior in asm manager progressing screen. Make sure pressing 
 *  END key will destroy asm manager and call cancel callback.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_end_key_behavior_progress_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_end_key_progressing_int(mmi_frm_appmem_ut_start_app);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_end_key_behavior_startnew_scrn
 * DESCRIPTION
 * Test END key behavior in asm manager start new application screen. Make sure pressing 
 *  END key will destroy asm manager and call cancel callback.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_end_key_behavior_startnew_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_end_key_start_new_int(mmi_frm_appmem_ut_start_app);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_invoke_ucm_call
 * DESCRIPTION
 *  Construct UCM call massage.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_invoke_ucm_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
	mmi_cc_call_ring_ind_struct *data;
	const U8 num_arr[] = {1,0,0,0,0};
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	data = OslIntConstructDataPtr(sizeof(mmi_cc_call_ring_ind_struct));
    data->call_id = 1;
    memcpy(data->num.number, num_arr, sizeof(num_arr)/sizeof(num_arr[0]));
    data->num.type = 145;
    data->num.length = 40;
    strcpy((char *)data->name, "xiaodong");
    Message.oslMsgId = MSG_ID_MMI_CC_CALL_RING_IND;
    Message.oslDataPtr = (oslParaType*)data;
    Message.oslPeerBuffPtr = NULL;
    Message.oslSrcId = MOD_L4C;
    Message.oslDestId = MOD_MMI;
    Message.sap_id = MMI_L4C_SAP;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_ucm_behavior_progress_scrn
 * DESCRIPTION
 *  Test incoming call behavior in asm manager progressing screen. 
 *  Make sure incoming call will destroy asm manager to prevent reentry problem.
 *  And we will call cancel call back and not launch new app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_ucm_behavior_progress_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_ucm_behavior_progress_scrn_int(mmi_frm_appmem_ut_start_app);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_ucm_behavior_startnew_scrn
 * DESCRIPTION
 *  Test incoming call behavior in asm manager start neww application screen. 
 *  Make sure incoming call will destroy asm manager to prevent reentry problem.
 *  And we will call cancel call back and not launch new app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_ucm_behavior_startnew_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_ucm_behavior_startnew_scrn_int(mmi_frm_appmem_ut_start_app);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_interrupt_gobacktoidle_invoke_cancelcb
 * DESCRIPTION
 *  Test interrupt cancel callback, the interrupt will go to idle, and will not 
 *  lauch new app.(MAUI_01606449)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_interrupt_gobacktoidle_invoke_cancelcb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_interrupt_gobacktoidle_invoke_cancelcb_int(mmi_frm_appmem_ut_start_app);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_screen_based_exit_function_release_memory
 * DESCRIPTION
 *  Test some apps will release memory in exit function, the new app memory is
 *  enough, we should launch new app directly.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_screen_based_exit_function_release_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
	mmi_id g_id;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_entry();
    mmi_frm_appmem_ut_start_app(APPLIB_MEM_AP_ID_TEST2);
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST2));
    mmi_frm_appmem_ut_start_app(APPLIB_MEM_AP_ID_TEST4);
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST4));
#ifdef __MMI_FRM_ASM_OOM_SCREEN__	
    MMI_ASSERT(mmi_frm_asm_get_manger_state() == MMI_FRM_ASM_MANAGER_STATE_FINISHED);
    MMI_ASSERT(! mmi_frm_asm_manager_is_launched(&g_id));
#endif
    mmi_idle_display();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_screen_based_cancel_goback_from_prompt
 * DESCRIPTION
 *  Test cancel callback from prompt screen, make sure the cancel callback is called
 *  and our group is closed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_screen_based_cancel_goback_from_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_cancel_goback_from_prompt_int(mmi_frm_appmem_ut_start_app);
}


static void mmi_frm_appmem_ut_interrupt_stop_popup_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_ASSERT(mmi_frm_asm_get_manger_state() == MMI_FRM_ASM_MANAGER_STATE_FINISHED);
	MMI_ASSERT(mmi_frm_scrn_get_active_id() == SCR_APPMEM_STOP_PROMPT);
}


static void mmi_frm_appmem_ut_interrupt_stop_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple((WCHAR*)((PU8) GetString(STR_GLOBAL_ERROR)), MMI_EVENT_WARNING, GRP_ID_ROOT, NULL);

    StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST5), 2000, mmi_frm_appmem_ut_interrupt_stop_popup_check);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_screen_based_interrupt_in_stop_popup
 * DESCRIPTION
 *  When the memory is not enough, even if we stop a app. we should popup "stop", 
 *  Test when there is interrupt in "stop" popup, we also can goback to prompt screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_screen_based_interrupt_in_stop_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_interrupt_in_stop_popup_int(mmi_frm_appmem_ut_start_app);
}


static void mmi_frm_appmem_ut_interrupt_start_new_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST4));
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    MMI_ASSERT(mmi_frm_asm_get_manger_state() == MMI_FRM_ASM_MANAGER_STATE_FINISHED);
#endif
}


static void mmi_frm_appmem_ut_interrupt_start_new(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple((WCHAR*)((PU8) GetString(STR_GLOBAL_ERROR)), MMI_EVENT_WARNING, GRP_ID_ROOT, NULL);
    StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST5), 3000, mmi_frm_appmem_ut_interrupt_start_new_check);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_screen_based_interrupt_in_start_new
 * DESCRIPTION
 *  When the memory is enough, even if we stop a app. we should popup "start new", 
 *  Test when there is interrupt in "start new" popup, we also can launch new app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_screen_based_interrupt_in_start_new(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_interrupt_in_start_new_int(mmi_frm_appmem_ut_start_app);
}



/***********************Screen Group Unit Test Case**************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_show_screen
 * DESCRIPTION
 *  The screen of screen group app.
 * PARAMETERS
 *  screen group id.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_show_screen(MMI_ID sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_running_app = sg_id;
    ShowCategory53Screen(
        STR_GLOBAL_1 + sg_id - APPLIB_MEM_AP_ID_TEST1,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        0,
        NULL,
        NULL,
        NULL,
        0,
        0,
        NULL);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_screen_enter1
 * DESCRIPTION
 *  Enter screen group app1.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_screen_enter1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter
            (APPLIB_MEM_AP_ID_TEST1, 
             GLOBAL_SCR_DUMMY, 
             NULL, 
             mmi_frm_appmem_ut_sg_screen_enter1, 
             MMI_FRM_FULL_SCRN))
    {
        return;
    }

    mmi_frm_appmem_ut_sg_show_screen(APPLIB_MEM_AP_ID_TEST1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_screen_exit2
 * DESCRIPTION
 *  the screen of screen group2 exit function, we will release memory in exit function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_screen_exit2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST2);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_screen_enter2
 * DESCRIPTION
 *  Enter screen group app2.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_screen_enter2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter
            (APPLIB_MEM_AP_ID_TEST2, 
             GLOBAL_SCR_DUMMY + 1 , 
             mmi_frm_appmem_ut_sg_screen_exit2, 
             mmi_frm_appmem_ut_sg_screen_enter2, 
             MMI_FRM_FULL_SCRN))
    {
        return;
    }

    mmi_frm_appmem_ut_sg_show_screen(APPLIB_MEM_AP_ID_TEST2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_screen_enter3
 * DESCRIPTION
 *  Enter screen group app3.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_screen_enter3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter
            (APPLIB_MEM_AP_ID_TEST3, 
             GLOBAL_SCR_DUMMY + 2, 
             NULL, 
             mmi_frm_appmem_ut_sg_screen_enter3, 
             MMI_FRM_FULL_SCRN))
    {
        return;
    }

    mmi_frm_appmem_ut_sg_show_screen(APPLIB_MEM_AP_ID_TEST3);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_screen_enter4
 * DESCRIPTION
 *  Enter screen group app4.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_screen_enter4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter
            (APPLIB_MEM_AP_ID_TEST4, 
             GLOBAL_SCR_DUMMY + 3, 
             NULL, 
             mmi_frm_appmem_ut_sg_screen_enter4, 
             MMI_FRM_FULL_SCRN))
    {
        return;
    }

    mmi_frm_appmem_ut_sg_show_screen(APPLIB_MEM_AP_ID_TEST4);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_screen_enter5
 * DESCRIPTION
 *  Enter screen group app5.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_screen_enter5(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter
            (APPLIB_MEM_AP_ID_TEST5, 
             GLOBAL_SCR_DUMMY + 4, 
             NULL, 
             mmi_frm_appmem_ut_sg_screen_enter5, 
             MMI_FRM_FULL_SCRN))
    {
        return;
    }

    mmi_frm_appmem_ut_sg_show_screen(APPLIB_MEM_AP_ID_TEST5);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_allocate_success_callback
 * DESCRIPTION
 *  The success callback of screen group that first allcoate ASM then create/enter group.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_allocate_success_callback(void)
{
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	void *memptr;
    U16 id = mmi_frm_asm_manager_get_app_id();
	kal_uint32 size = MMI_FRM_APPMEM_TEST1_SIZE + id - APPLIB_MEM_AP_ID_TEST1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    memptr = applib_mem_ap_alloc(id, size);
    MMI_ASSERT(memptr);
    mmi_frm_group_create(GRP_ID_ROOT, id, NULL, NULL);
    mmi_frm_group_enter(mmi_frm_asm_manager_get_app_id(), MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_appmem_ut_sg_screen_enter_func[id - APPLIB_MEM_AP_ID_TEST1]();
#endif        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_enter_success_callback
 * DESCRIPTION
 *  The success callback of screen group that first create/enter group then allocate ASM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_enter_success_callback(void)
{
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	void *memptr;
	U16 id = mmi_frm_asm_manager_get_app_id();
	kal_uint32 size = MMI_FRM_APPMEM_TEST1_SIZE + id - APPLIB_MEM_AP_ID_TEST1;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    memptr = applib_mem_ap_alloc(mmi_frm_asm_manager_get_app_id(), size);
    MMI_ASSERT(memptr);
    mmi_frm_appmem_ut_sg_screen_enter_func[id - APPLIB_MEM_AP_ID_TEST1]();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_start_sg_first_allocate
 * DESCRIPTION
 *  Start the screen group app that first allocate ASM then create/enter group.
 * PARAMETERS
 *  screen group ID.
 * RETURNS
 *  void
 *****************************************************************************/                                  
static void mmi_frm_appmem_ut_start_sg_first_allocate(MMI_ID sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	void *memptr;
	U32 size = MMI_FRM_APPMEM_TEST1_SIZE + (sg_id - APPLIB_MEM_AP_ID_TEST1) * ASM_UT_POOL_SIZE / 5;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_group_case = MMI_TRUE;
    memptr = applib_mem_ap_alloc(sg_id, size);
    if (memptr)
    {
        mmi_frm_group_create(GRP_ID_ROOT, sg_id, NULL, NULL);
        mmi_frm_group_enter(sg_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        mmi_frm_appmem_ut_sg_screen_enter_func[sg_id - APPLIB_MEM_AP_ID_TEST1]();
    }
    else
    {
        mmi_frm_appmem_prompt_to_release_mem(
            sg_id,
            IMG_GLOBAL_L1 + sg_id - APPLIB_MEM_AP_ID_TEST1,
            size,
            mmi_frm_appmem_ut_sg_first_allocate_success_callback);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_start_sg_first_enter
 * DESCRIPTION
 *  Start the screen group app that first create/enter group then allocate ASM.
 * PARAMETERS
 *  screen group ID.
 * RETURNS
 *  void
 *****************************************************************************/  
static void mmi_frm_appmem_ut_start_sg_first_enter(MMI_ID sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	void *memptr;
	kal_uint32 size = MMI_FRM_APPMEM_TEST1_SIZE + (sg_id - APPLIB_MEM_AP_ID_TEST1) * ASM_UT_POOL_SIZE / 5;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_group_case = MMI_TRUE;
    mmi_frm_group_create(GRP_ID_ROOT, sg_id, NULL, NULL);
    mmi_frm_group_enter(sg_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    memptr = applib_mem_ap_alloc(sg_id, size);
    if (memptr)
    {
        mmi_frm_appmem_ut_sg_screen_enter_func[sg_id - APPLIB_MEM_AP_ID_TEST1]();
    }    
    else
    {
        mmi_frm_appmem_prompt_to_release_mem(
            sg_id,
            IMG_GLOBAL_L1 + sg_id - APPLIB_MEM_AP_ID_TEST1,
            size,
            mmi_frm_appmem_ut_sg_first_enter_success_callback);
    }
}


static void mmi_frm_appmem_ut_sg_async_normal_case_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    MMI_ASSERT(mmi_frm_asm_get_manger_state() == MMI_FRM_ASM_MANAGER_STATE_FINISHED);
#endif
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST4));
}


static mmi_ret mmi_frm_appmem_ut_sg_first_allocate_async_normal_case_callback(mmi_event_struct *evt)
{
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    MMI_ASSERT(mmi_frm_asm_get_manger_state() == MMI_FRM_ASM_MANAGER_STATE_WAITING);
#endif
    StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST1), 5500, mmi_frm_appmem_ut_sg_async_normal_case_check);
    g_mmi_frm_appmem_ut_break_flow = MMI_TRUE;
    StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST5+5), 6500, mmi_frm_appmem_ut_behavior_timer_hdlr);
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_allocate_async_normal_case
 * DESCRIPTION
 *  the first allocate(first allocate ASM then create/enter screen group) 
 *  screen group app async test case, means the stopped app cann't release memroy
 *  immediately.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_allocate_async_normal_case(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     mmi_event_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_entry();
    mmi_frm_appmem_ut_start_sg_first_allocate(APPLIB_MEM_AP_ID_TEST3);
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST3));
    mmi_frm_appmem_ut_start_sg_first_allocate(APPLIB_MEM_AP_ID_TEST4);
    MMI_ASSERT(!mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST4));
    mmi_frm_appmem_ut_stop_app(APPLIB_MEM_AP_ID_TEST3);
    MMI_FRM_INIT_EVENT(&evt, 0);
    mmi_frm_post_event(&evt, mmi_frm_appmem_ut_sg_first_allocate_async_normal_case_callback, NULL); 
}

static mmi_ret mmi_frm_appmem_ut_sg_first_allocate_normal_case_proc(mmi_event_struct *evt)
{
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
     MMI_ASSERT(mmi_frm_asm_get_manger_state() == MMI_FRM_ASM_MANAGER_STATE_FINISHED);
#endif
     return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_allocate_normal_case
 * DESCRIPTION
 *  the first allocate(first allocate ASM then create/enter screen group) 
 *  screen group app sync test case, means the stopped app can release memroy
 *  immediately.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_allocate_normal_case(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     mmi_event_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_entry();
    mmi_frm_appmem_ut_start_sg_first_allocate(APPLIB_MEM_AP_ID_TEST4);
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST4));
    mmi_frm_appmem_ut_start_sg_first_allocate(APPLIB_MEM_AP_ID_TEST3);
    MMI_ASSERT(!mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST3));
    mmi_frm_appmem_ut_stop_app(APPLIB_MEM_AP_ID_TEST4);
    MMI_FRM_INIT_EVENT(&evt, 0);
    mmi_frm_post_event(&evt, mmi_frm_appmem_ut_sg_first_allocate_normal_case_proc, NULL); 
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_enter_async_normal_case
 * DESCRIPTION
 *  the first enter(first create/enter screen group then allocate ASM) 
 *  screen group app async test case, means the stopped app cann't release memroy
 *  immediately.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_enter_async_normal_case(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_entry();
    mmi_frm_appmem_ut_start_sg_first_enter(APPLIB_MEM_AP_ID_TEST3);
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST3));
    mmi_frm_appmem_ut_start_sg_first_enter(APPLIB_MEM_AP_ID_TEST4);
    MMI_ASSERT(!mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST4));
    mmi_frm_appmem_ut_stop_app(APPLIB_MEM_AP_ID_TEST3);
    StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST1), 5500, mmi_frm_appmem_ut_sg_async_normal_case_check);
    g_mmi_frm_appmem_ut_break_flow = MMI_TRUE;
    StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST5+6), 3000+2500, mmi_frm_appmem_ut_behavior_timer_hdlr);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_allocate_exit_release
 * DESCRIPTION
 *  The first screen group will release memory in exit function, so the second
 *  screen group app can launch.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_allocate_exit_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_entry();
    mmi_frm_appmem_ut_start_sg_first_allocate(APPLIB_MEM_AP_ID_TEST2);
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST2));
    mmi_frm_appmem_ut_start_sg_first_allocate(APPLIB_MEM_AP_ID_TEST4);
    MMI_ASSERT(mmi_frm_group_get_active_id() == APPLIB_MEM_AP_ID_TEST4);
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    MMI_ASSERT(mmi_frm_asm_get_manger_state() == MMI_FRM_ASM_MANAGER_STATE_FINISHED);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_enter_exit_release
 * DESCRIPTION
 *  The first screen group will release memory in exit function, so the second
 *  screen group app can launch.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_enter_exit_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_entry();
    mmi_frm_appmem_ut_start_sg_first_allocate(APPLIB_MEM_AP_ID_TEST2);
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST2));
    mmi_frm_appmem_ut_start_sg_first_enter(APPLIB_MEM_AP_ID_TEST4);
    MMI_ASSERT(mmi_frm_group_get_active_id() == APPLIB_MEM_AP_ID_TEST4);
    //MMI_ASSERT(mmi_frm_asm_get_manger_state() == MMI_FRM_ASM_MANAGER_STATE_FINISHED);
}


static void mmi_frm_appmem_ut_sg_first_allocate_reentry_lsk(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_start_sg_first_allocate(APPLIB_MEM_AP_ID_TEST5);
    MMI_ASSERT(!mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST5));
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    MMI_ASSERT(mmi_frm_asm_get_manger_state() == MMI_FRM_ASM_MANAGER_STATE_NORMAL);
#endif
}


static void mmi_frm_appmem_ut_sg_first_enter_reentry_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_start_sg_first_enter(APPLIB_MEM_AP_ID_TEST5);
    MMI_ASSERT(!mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST5));
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    MMI_ASSERT(mmi_frm_asm_get_manger_state() == MMI_FRM_ASM_MANAGER_STATE_NORMAL); 
#endif
}


static void mmi_frm_appmem_ut_sg_reentry_check_timer_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    MMI_ASSERT(mmi_frm_asm_get_manger_state() == MMI_FRM_ASM_MANAGER_STATE_FINISHED);
#endif
    mmi_frm_appmem_ut_execute_key_hdlr(KEY_RSK);
     
    //MMI_ASSERT(mmi_frm_group_get_active_id() != APPLIB_MEM_AP_ID_TEST3);    
}


    static mmi_ret mmi_frm_appmem_ut_sg_confirm_callback(mmi_alert_result_evt_struct *evt)
    {
        if (evt->evt_id == EVT_ID_ALERT_QUIT)
        {
            switch (evt->result)
            {
            case MMI_ALERT_CNFM_1:
            case MMI_ALERT_CNFM_2:
            case MMI_ALERT_CNFM_3:
                // handle softkey event here
                break;
            case MMI_ALERT_CNFM_OK:
                // handle softkey event here
                break;
            case MMI_ALERT_CNFM_YES:
                mmi_frm_appmem_ut_sg_first_allocate_reentry_lsk();
                break;
            case MMI_ALERT_CNFM_NO:
                 GoBackHistory();
                break;
            }
        }
        return MMI_RET_OK;
    }

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_allocate_reentry_case
 * DESCRIPTION
 *  when in prompt screen, there may be interrupt and will reentry asm manager again.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_allocate_reentry_case(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_entry();
    mmi_frm_appmem_ut_start_sg_first_allocate(APPLIB_MEM_AP_ID_TEST4);
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST4));
    mmi_frm_appmem_ut_start_sg_first_allocate(APPLIB_MEM_AP_ID_TEST3);//entry prompt screen
    MMI_ASSERT(!mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST3));
    /* in popup lsk start new app, reentry prompt screen again */
	
	mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
	arg.softkey[0].str = (WCHAR *)((U16 *)GetString(STR_GLOBAL_YES));
	arg.softkey[2].str = (WCHAR *)((U16 *)GetString(STR_GLOBAL_NO));
	arg.callback = (mmi_proc_func)mmi_frm_appmem_ut_sg_confirm_callback;
	mmi_confirm_display((WCHAR *)((UI_string_type) GetString(STR_ID_APPMEM_STOP)), MMI_EVENT_QUERY, &arg); 
    mmi_frm_appmem_ut_execute_key_hdlr(KEY_LSK);
    mmi_frm_appmem_ut_stop_app(APPLIB_MEM_AP_ID_TEST4);
   
    StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST4), 2000+500, mmi_frm_appmem_ut_sg_reentry_check_timer_cb); 
    g_mmi_frm_appmem_ut_break_flow = MMI_TRUE;
    StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST5+5), 2500+500, mmi_frm_appmem_ut_behavior_timer_hdlr);
}

static mmi_ret mmi_frm_appmem_ut_sg_first_enter_reentry_callback(mmi_alert_result_evt_struct *evt)
{
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_1:
        case MMI_ALERT_CNFM_2:
        case MMI_ALERT_CNFM_3:
            // handle softkey event here
            break;
        case MMI_ALERT_CNFM_OK:
            // handle softkey event here
            break;
        case MMI_ALERT_CNFM_YES:
            mmi_frm_appmem_ut_sg_first_enter_reentry_lsk();
            break;
        case MMI_ALERT_CNFM_NO:
            GoBackHistory();
            break;
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_allocate_reentry_case
 * DESCRIPTION
 *  when in prompt screen, there may be interrupt and will reentry asm manager again.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_enter_reentry_case(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_confirm_property_struct arg;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_entry();
    mmi_frm_appmem_ut_start_sg_first_allocate(APPLIB_MEM_AP_ID_TEST4);
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST4));
    mmi_frm_appmem_ut_start_sg_first_enter(APPLIB_MEM_AP_ID_TEST3);//entry prompt screen
    MMI_ASSERT(!mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST3));
    /* in popup lsk start new app, reentry prompt screen again */
	mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
	arg.softkey[0].str = (WCHAR *)((U16 *)GetString(STR_GLOBAL_YES));
	arg.softkey[2].str = (WCHAR *)((U16 *)GetString(STR_GLOBAL_NO));
	arg.callback = (mmi_proc_func)mmi_frm_appmem_ut_sg_first_enter_reentry_callback;
	mmi_confirm_display((UI_string_type) GetString(STR_ID_APPMEM_STOP), MMI_EVENT_QUERY, &arg);
    mmi_frm_appmem_ut_execute_key_hdlr(KEY_LSK);
    mmi_frm_appmem_ut_stop_app(APPLIB_MEM_AP_ID_TEST4);
    
    StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST4), 2000+500, mmi_frm_appmem_ut_sg_reentry_check_timer_cb);
    g_mmi_frm_appmem_ut_break_flow = MMI_TRUE;
    StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST5+5), 2500+500, mmi_frm_appmem_ut_behavior_timer_hdlr);
}

static mmi_ret mmi_frm_appmem_ut_sg_end_key_progressing_int_check(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    MMI_ASSERT(mmi_frm_asm_get_manger_state() == MMI_FRM_ASM_MANAGER_STATE_WAITING);
#endif
    mmi_frm_appmem_ut_execute_key_hdlr(KEY_END);
   // MMI_ASSERT(mmi_idle_is_active());
    MMI_ASSERT(cancel_cb_is_called);
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    MMI_ASSERT(mmi_frm_asm_get_manger_state() == MMI_FRM_ASM_MANAGER_STATE_CANCELED);
#endif
    g_mmi_frm_appmem_ut_break_flow = MMI_TRUE;
    StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST5+5), 2000+3500, mmi_frm_appmem_ut_behavior_timer_hdlr);
    return MMI_RET_OK;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_end_key_progressing_int
 * DESCRIPTION
 *  when in progressing screen, user press end key will invoke cancel callback, and
 *  goback to idle.
 * PARAMETERS
 *  start app callback function
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_end_key_progressing_int(sg_func callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    asm_ut_type = UT_END_PROGRESS_SCRN;
    mmi_frm_appmem_ut_entry();
    callback(APPLIB_MEM_AP_ID_TEST3);
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST3));
    callback(APPLIB_MEM_AP_ID_TEST4);
    mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_TEST4, mmi_frm_appmem_ut_end_cancel_cb);
    MMI_ASSERT(!cancel_cb_is_called);
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    MMI_ASSERT(mmi_frm_asm_get_manger_state() == MMI_FRM_ASM_MANAGER_STATE_NORMAL);
#endif
    mmi_frm_appmem_ut_stop_app(APPLIB_MEM_AP_ID_TEST3);
    MMI_FRM_INIT_EVENT(&evt, 0);
    mmi_frm_post_event(&evt, mmi_frm_appmem_ut_sg_end_key_progressing_int_check, NULL); 
    g_mmi_frm_appmem_ut_break_flow = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_enter_end_key_progressing
 * DESCRIPTION
 *  when in progressing screen, user press end key will invoke cancel callback, and
 *  goback to idle.
 * PARAMETERS
 *  start app callback function
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_enter_end_key_progressing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_end_key_progressing_int(mmi_frm_appmem_ut_start_sg_first_enter);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_allocate_end_key_progressing
 * DESCRIPTION
 *  when in progressing screen, user press end key will invoke cancel callback, and
 *  goback to idle.
 * PARAMETERS
 *  start app callback function
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_allocate_end_key_progressing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_end_key_progressing_int(mmi_frm_appmem_ut_start_sg_first_allocate);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_end_key_start_new_int
 * DESCRIPTION
 *  when in start new app popup, user press end key will invoke cancel callback, and
 *  goback to idle.
 * PARAMETERS
 *  start app callback function
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_end_key_start_new_int(sg_func start_app)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_entry();
    MMI_ASSERT(!mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST4));
    start_app(APPLIB_MEM_AP_ID_TEST4);
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST4));
    start_app(APPLIB_MEM_AP_ID_TEST3);
    mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_TEST3, mmi_frm_appmem_ut_end_cancel_cb);
    MMI_ASSERT(!cancel_cb_is_called);
    mmi_frm_appmem_ut_stop_app(APPLIB_MEM_AP_ID_TEST4);
    /* Popup timer will be stopped when exit screen, so could check result immediately */
    mmi_frm_appmem_ut_execute_key_hdlr(KEY_END);
    //MMI_ASSERT(mmi_idle_is_active());
    MMI_ASSERT(cancel_cb_is_called);
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    MMI_ASSERT(mmi_frm_asm_get_manger_state() == MMI_FRM_ASM_MANAGER_STATE_CANCELED);
#endif
    MMI_ASSERT(!mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST3));
    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_allcoate_end_key_start_new
 * DESCRIPTION
 *  when in start new app popup, user press end key will invoke cancel callback, and
 *  goback to idle.
 * PARAMETERS
 *  start app callback function
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_allcoate_end_key_start_new(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_end_key_start_new_int(mmi_frm_appmem_ut_start_sg_first_allocate);    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_allcoate_end_key_start_new
 * DESCRIPTION
 *  when in start new app popup, user press end key will invoke cancel callback, and
 *  goback to idle.
 * PARAMETERS
 *  start app callback function
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_enter_end_key_start_new(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_end_key_start_new_int(mmi_frm_appmem_ut_start_sg_first_enter);       
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_interrupt_gobacktoidle_invoke_cancelcb_int
 * DESCRIPTION
 *  Test interrupt cancel callback, the interrupt will go to idle, and will not 
 *  launch new app, make sure the cancel callback is called.(MAUI_01606449)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_interrupt_gobacktoidle_invoke_cancelcb_int(sg_func start_app)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_entry();
    start_app(APPLIB_MEM_AP_ID_TEST3);
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST3));
    start_app(APPLIB_MEM_AP_ID_TEST4);
    mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_TEST4, mmi_frm_appmem_ut_interrupt_cancel_cb);
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    MMI_ASSERT(mmi_frm_asm_get_manger_state() == MMI_FRM_ASM_MANAGER_STATE_NORMAL);
#endif
    MMI_ASSERT(!cancel_cb_is_called);
    mmi_popup_display_simple((WCHAR*)((PU8) GetString(STR_GLOBAL_ERROR)), MMI_EVENT_WARNING, GRP_ID_ROOT, NULL);
	mmi_idle_display();
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
	MMI_ASSERT(mmi_frm_asm_get_manger_state() == MMI_FRM_ASM_MANAGER_STATE_CANCELED);
#endif
    MMI_ASSERT(cancel_cb_is_called);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_allocate_interrupt_gobacktoidle_invoke_cancelcb
 * DESCRIPTION
 *  Test interrupt cancel callback, the interrupt will go to idle, and will not 
 *  launch new app, make sure the cancel callback is called.(MAUI_01606449)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_allocate_interrupt_gobacktoidle_invoke_cancelcb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_interrupt_gobacktoidle_invoke_cancelcb_int(mmi_frm_appmem_ut_start_sg_first_allocate);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_enter_interrupt_gobacktoidle_invoke_cancelcb
 * DESCRIPTION
 *  Test interrupt cancel callback, the interrupt will go to idle, and will not 
 *  launch new app, make sure the cancel callback is called.(MAUI_01606449)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_enter_interrupt_gobacktoidle_invoke_cancelcb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_interrupt_gobacktoidle_invoke_cancelcb_int(mmi_frm_appmem_ut_start_sg_first_enter);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_interrupt_in_stop_popup_int
 * DESCRIPTION
 *  When the memory is not enough, even if we stop a app. we should popup "stop", 
 *  Test when there is interrupt in "stop" popup, we also can goback to prompt screen.
 * PARAMETERS
 *  start app callback
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_interrupt_in_stop_popup_int(sg_func start_app)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_entry();
    
    start_app(APPLIB_MEM_AP_ID_TEST1);
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST1));
    start_app(APPLIB_MEM_AP_ID_TEST3);    
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST3));
    start_app(APPLIB_MEM_AP_ID_TEST4);
    MMI_ASSERT(!mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST4));
    mmi_frm_appmem_ut_stop_app(APPLIB_MEM_AP_ID_TEST1);
    StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST2), 5000, mmi_frm_appmem_ut_interrupt_stop_popup);
    g_mmi_frm_appmem_ut_break_flow = MMI_TRUE;
    StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST5+5), 5000+3000, mmi_frm_appmem_ut_behavior_timer_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_allocate_interrupt_in_stop_popup
 * DESCRIPTION
 *  When the memory is not enough, even if we stop a app. we should popup "stop", 
 *  Test when there is interrupt in "stop" popup, we also can goback to prompt screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_allocate_interrupt_in_stop_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_interrupt_in_stop_popup_int(mmi_frm_appmem_ut_start_sg_first_allocate);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_enter_interrupt_in_stop_popup
 * DESCRIPTION
 *  When the memory is not enough, even if we stop a app. we should popup "stop", 
 *  Test when there is interrupt in "stop" popup, we also can goback to prompt screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_enter_interrupt_in_stop_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_interrupt_in_stop_popup_int(mmi_frm_appmem_ut_start_sg_first_enter);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_interrupt_in_start_new_int
 * DESCRIPTION
 *  When the memory is enough, even if we stop a app. we should popup "start new", 
 *  Test when there is interrupt in "start new" popup, we also can launch new app.
 * PARAMETERS
 *  start app callback
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_interrupt_in_start_new_int(sg_func start_app)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_entry();
    start_app(APPLIB_MEM_AP_ID_TEST3);    
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST3));
    start_app(APPLIB_MEM_AP_ID_TEST4);
    mmi_frm_appmem_ut_stop_app(APPLIB_MEM_AP_ID_TEST3);
    /*when we should show start new application, but the group is inactive now, also can 
      invke success callback*/
    StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST2), 4000, mmi_frm_appmem_ut_interrupt_start_new);
    g_mmi_frm_appmem_ut_break_flow = MMI_TRUE;
    StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST5+5), 2500+2000, mmi_frm_appmem_ut_behavior_timer_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_allocate_interrupt_in_start_new
 * DESCRIPTION
 *  When the memory is enough, even if we stop a app. we should popup "start new", 
 *  Test when there is interrupt in "start new" popup, we also can launch new app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_allocate_interrupt_in_start_new(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_interrupt_in_start_new_int(mmi_frm_appmem_ut_start_sg_first_allocate);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_enter_interrupt_in_start_new
 * DESCRIPTION
 *  When the memory is enough, even if we stop a app. we should popup "start new", 
 *  Test when there is interrupt in "start new" popup, we also can launch new app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_enter_interrupt_in_start_new(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_interrupt_in_start_new_int(mmi_frm_appmem_ut_start_sg_first_enter);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_cancel_goback_from_prompt_int
 * DESCRIPTION
 *  Test cancel callback from prompt screen, make sure the cancel callback is called
 *  and our group is closed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_cancel_goback_from_prompt_int(sg_func start_app)
{ 
    mmi_id g_id;
    mmi_frm_appmem_ut_entry();
    start_app(APPLIB_MEM_AP_ID_TEST3);
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST3));
    start_app(APPLIB_MEM_AP_ID_TEST4);
    mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_TEST4, mmi_frm_appmem_ut_back_cancel_cb);
    MMI_ASSERT(!cancel_cb_is_called);
    mmi_frm_appmem_ut_execute_key_hdlr(KEY_RSK);
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    MMI_ASSERT(mmi_frm_asm_get_manger_state() == MMI_FRM_ASM_MANAGER_STATE_CANCELED);
#endif
    MMI_ASSERT(cancel_cb_is_called);
    MMI_ASSERT(! mmi_frm_asm_manager_is_launched(&g_id));
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST3));
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_allocate_cancel_goback_from_prompt
 * DESCRIPTION
 *  Test cancel callback from prompt screen, make sure the cancel callback is called
 *  and our group is closed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_allocate_cancel_goback_from_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_cancel_goback_from_prompt_int(mmi_frm_appmem_ut_start_sg_first_allocate);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_enter_cancel_goback_from_prompt
 * DESCRIPTION
 *  Test cancel callback from prompt screen, make sure the cancel callback is called
 *  and our group is closed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_enter_cancel_goback_from_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_cancel_goback_from_prompt_int(mmi_frm_appmem_ut_start_sg_first_enter);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_ucm_behavior_progress_scrn_int
 * DESCRIPTION
 *  Test incoming call behavior in asm manager progressing screen. 
 *  Make sure incoming call will destroy asm manager to prevent reentry problem.
 *  And we will call cancel call back and not launch new app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_ucm_behavior_progress_scrn_int(sg_func start_app)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    asm_ut_type = UT_UCM_PROGRESS_SCRN;
    mmi_frm_appmem_ut_entry();
    start_app(APPLIB_MEM_AP_ID_TEST3);
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST3));
    start_app(APPLIB_MEM_AP_ID_TEST4);
    MMI_ASSERT(mmi_frm_appmem_check_prompt_screen() == APPLIB_MEM_AP_ID_TEST4);
    mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_TEST4, mmi_frm_appmem_ut_ucm_cancel_cb);
    MMI_ASSERT(!cancel_cb_is_called);
    mmi_frm_appmem_ut_stop_app(APPLIB_MEM_AP_ID_TEST3);

    mmi_frm_appmem_ut_invoke_ucm_call();
    /* Since app3 will start timer(3000ms) to launch so that we have to break function flow to check result. */
    g_mmi_frm_appmem_ut_break_flow = MMI_TRUE;
    StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST5+5), 2000+3500, mmi_frm_appmem_ut_behavior_timer_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_allocate_ucm_behavior_progress_scrn
 * DESCRIPTION
 *  Test incoming call behavior in asm manager progressing screen. 
 *  Make sure incoming call will destroy asm manager to prevent reentry problem.
 *  And we will call cancel call back and not launch new app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_allocate_ucm_behavior_progress_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_ucm_behavior_progress_scrn_int(mmi_frm_appmem_ut_start_sg_first_allocate);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_enter_ucm_behavior_progress_scrn
 * DESCRIPTION
 *  Test incoming call behavior in asm manager progressing screen. 
 *  Make sure incoming call will destroy asm manager to prevent reentry problem.
 *  And we will call cancel call back and not launch new app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_enter_ucm_behavior_progress_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_ucm_behavior_progress_scrn_int(mmi_frm_appmem_ut_start_sg_first_enter);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_ucm_behavior_startnew_scrn_int
 * DESCRIPTION
 *  Test incoming call behavior in asm manager start neww application screen. 
 *  Make sure incoming call will destroy asm manager to prevent reentry problem.
 *  And we will call cancel call back and not launch new app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_ucm_behavior_startnew_scrn_int(sg_func start_app)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    asm_ut_type = UT_UCM_STARTNEW_SCRN;
    mmi_frm_appmem_ut_entry();
    start_app(APPLIB_MEM_AP_ID_TEST3);
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST3));
    start_app(APPLIB_MEM_AP_ID_TEST4);
    MMI_ASSERT(mmi_frm_appmem_check_prompt_screen() == APPLIB_MEM_AP_ID_TEST4);
    mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_TEST4, mmi_frm_appmem_ut_ucm_cancel_cb);
    MMI_ASSERT(!cancel_cb_is_called);
    mmi_frm_appmem_ut_stop_app(APPLIB_MEM_AP_ID_TEST3);
    /* Make incoming call when entering start new app screen. */
    StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST5+5), 3000, mmi_frm_appmem_ut_invoke_ucm_call);
    g_mmi_frm_appmem_ut_break_flow = MMI_TRUE;
    StartTimer(ASM_TEST_TIMER(APPLIB_MEM_AP_ID_TEST5+6), 3000+2500, mmi_frm_appmem_ut_behavior_timer_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_allocate_ucm_behavior_startnew_scrn
 * DESCRIPTION
 *  Test incoming call behavior in asm manager start neww application screen. 
 *  Make sure incoming call will destroy asm manager to prevent reentry problem.
 *  And we will call cancel call back and not launch new app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_allocate_ucm_behavior_startnew_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_ucm_behavior_startnew_scrn_int(mmi_frm_appmem_ut_start_sg_first_allocate);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_sg_first_enter_ucm_behavior_startnew_scrn
 * DESCRIPTION
 *  Test incoming call behavior in asm manager start neww application screen. 
 *  Make sure incoming call will destroy asm manager to prevent reentry problem.
 *  And we will call cancel call back and not launch new app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_sg_first_enter_ucm_behavior_startnew_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_sg_ucm_behavior_startnew_scrn_int(mmi_frm_appmem_ut_start_sg_first_enter);
}



/*****************************************************************************  
 * Function for test case driven engine
 *****************************************************************************/
typedef struct
{
    S8 index;
    FuncPtr ut_func;
} _asm_ut_struct;

#define ASM_UT_DB_SIZE  (sizeof(asm_ut_db) / sizeof(asm_ut_db[0]))

static const _asm_ut_struct asm_ut_db[] =
{
    /* Test all cases */
    {0,  NULL},
    {1,  mmi_frm_appmem_ut_entry},
    /* Due to async case of test 5, test case 6 will be executed before result of test 5 in regression test */
	{2,  mmi_frm_appmem_ut_interrupt_gobacktoidle_invoke_cancelcb},

    /* The following test are async cases, check result operation is made in timer callback, non-async test case should be put before these cases */
    {3,  mmi_frm_appmem_ut_end_key_behavior_progress_scrn},
    {4,  mmi_frm_appmem_ut_end_key_behavior_startnew_scrn},
    {5,  mmi_frm_appmem_ut_ucm_behavior_progress_scrn},
    {6,  mmi_frm_appmem_ut_ucm_behavior_startnew_scrn},
    {7,  mmi_frm_appmem_ut_screen_based_exit_function_release_memory},
    {8,  mmi_frm_appmem_ut_screen_based_cancel_goback_from_prompt},
    {9,  mmi_frm_appmem_ut_screen_based_interrupt_in_stop_popup},
    {10, mmi_frm_appmem_ut_screen_based_interrupt_in_start_new},
    {11, mmi_frm_appmem_ut_sg_first_allocate_normal_case},
    {12, mmi_frm_appmem_ut_sg_first_allocate_async_normal_case},
    {13, mmi_frm_appmem_ut_sg_first_enter_async_normal_case},
    {14, mmi_frm_appmem_ut_sg_first_allocate_exit_release},
    {15, mmi_frm_appmem_ut_sg_first_enter_exit_release},
    {16, mmi_frm_appmem_ut_sg_first_allocate_reentry_case},
    {17, mmi_frm_appmem_ut_sg_first_enter_reentry_case},
    {18, mmi_frm_appmem_ut_sg_first_allocate_end_key_progressing},
    {19, mmi_frm_appmem_ut_sg_first_enter_end_key_progressing},
    {20, mmi_frm_appmem_ut_sg_first_allcoate_end_key_start_new},
    {21, mmi_frm_appmem_ut_sg_first_enter_end_key_start_new},
    {22, mmi_frm_appmem_ut_sg_first_allocate_interrupt_gobacktoidle_invoke_cancelcb},
    {23, mmi_frm_appmem_ut_sg_first_enter_interrupt_gobacktoidle_invoke_cancelcb},
    {24, mmi_frm_appmem_ut_sg_first_allocate_interrupt_in_stop_popup},
    {25, mmi_frm_appmem_ut_sg_first_enter_interrupt_in_stop_popup},
    {26, mmi_frm_appmem_ut_sg_first_allocate_interrupt_in_start_new},
    {27, mmi_frm_appmem_ut_sg_first_enter_interrupt_in_start_new},
    {28, mmi_frm_appmem_ut_sg_first_allocate_cancel_goback_from_prompt},
    {29, mmi_frm_appmem_ut_sg_first_enter_cancel_goback_from_prompt},
    {30, mmi_frm_appmem_ut_sg_first_allocate_ucm_behavior_progress_scrn},
    {31, mmi_frm_appmem_ut_sg_first_enter_ucm_behavior_progress_scrn},
    {32, mmi_frm_appmem_ut_sg_first_allocate_ucm_behavior_startnew_scrn},
    {33, mmi_frm_appmem_ut_sg_first_enter_ucm_behavior_startnew_scrn},
};


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_test_case_entry
 * DESCRIPTION
 * Asm test case entry function, could be invoked by catcher inject string
 * in mmi_proc_inject_string (events.c).
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_asm_test_case_entry(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    static U8 cur_ut_idx = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_frm_appmem_ut_case_idx = index;

    if (MMI_FALSE == mmi_frm_appmem_unit_test_setup_environment())
    {/* Fail to setup environment - not in idle screen */
        return ;
    }

    if (0 == index)
    {
        /* Test all cases */
        g_mmi_frm_appmem_ut_regress = MMI_TRUE;
        while (cur_ut_idx < ASM_UT_DB_SIZE)
        {
            mmi_frm_appmem_ut_reset_context();
#ifndef __MTK_TARGET__
            kal_printf("!!%d\n", cur_ut_idx);
#endif
            asm_ut_db[cur_ut_idx].ut_func();
            cur_ut_idx++;
            if (g_mmi_frm_appmem_ut_break_flow)
            {
                break;
            }
        }
    }
    else
    {
        g_mmi_frm_appmem_ut_regress = MMI_FALSE;
        for (i = 1; i < ASM_UT_DB_SIZE; i++)
        {
            if (asm_ut_db[i].index == index && asm_ut_db[i].ut_func)
            {
                mmi_frm_appmem_ut_reset_context();
                if (!g_mmi_frm_appmem_ut_break_flow)
                {
                    asm_ut_db[i].ut_func();
                }
            }
        }
    }

    if (cur_ut_idx == ASM_UT_DB_SIZE && g_mmi_frm_appmem_ut_regress)
    {
        cur_ut_idx = 1;
        g_mmi_frm_appmem_ut_case_idx = -1;
    }
}

/*****************************************************************************
 *
 * ASM2.0 Test
 *
 *****************************************************************************/
typedef enum
{
	SYNC_FREE,
	ASYNC_FREE,
	SYNC_FORCE_FREE,
	ASYNC_FORCE_FREE,
	ACTION_NONE
} asm_test_action_enum;
typedef struct
{
	MMI_ID app_id;
	void *ptr;
	asm_test_action_enum action;
} asm_test_grp_cntx;

static asm_test_grp_cntx asmv10cntx[5];


asm_test_grp_cntx* alloc_asmv10_cntx(void)
{
    U32 i;
	for (i = 0; i < 5; i++)
	{
		if (asmv10cntx[i].app_id == 0)
		{
		    return &asmv10cntx[i];
		}
	}
	ASSERT(0);
    return NULL;
}


asm_test_grp_cntx* get_asmv10_cntx(MMI_ID app_id)
{
    U32 i;
	for (i = 0; i < 5; i++)
	{
		if (asmv10cntx[i].app_id == app_id)
		{
		    return &asmv10cntx[i];
		}
	}
	return NULL;
}



void free_asmv10_cntx(asm_test_grp_cntx* cntx)
{
    U32 i;
	for (i = 0; i < 5; i++)
	{
		if (&asmv10cntx[i] == cntx)
		{
		    asmv10cntx[i].app_id = 0;
			return;
		}
	}    
}

void set_v10_cntx(asm_test_grp_cntx* cntx, MMI_ID app_id, void *ptr, asm_test_action_enum action)
{
    cntx->app_id = app_id;
	cntx->ptr = ptr;
	cntx->action = action;
}


static MMI_RET scrn_group_proc_for_asm_test(mmi_event_struct *evt)
{
	asm_test_grp_cntx *cntx = (asm_test_grp_cntx *)evt->user_data;
	mmi_scenario_evt_struct *p = (mmi_scenario_evt_struct *)evt;
	switch (evt->evt_id)
	{
	    case 0xFFF0:
			ASSERT(cntx != NULL);
			if (cntx->action == ASYNC_FREE || cntx->action == ASYNC_FORCE_FREE)
			{
			    MMI_ID id;
				mmi_frm_asm_free_r(cntx->app_id, cntx->ptr);
				cntx->ptr = NULL;
				id = cntx->app_id;
				if (mmi_frm_get_root_app(cntx->app_id) == GRP_ID_INVALID)
				{
				    free_asmv10_cntx(cntx);
				}
				applib_mem_ap_notify_stop_finished(id, KAL_TRUE);

			}
			break;
			
		case EVT_ID_ASM_FREE_REQ:
			ASSERT(cntx != NULL);
			if (cntx->action == SYNC_FREE)
			{
				mmi_frm_asm_free_r(cntx->app_id, cntx->ptr);
				cntx->ptr = NULL;
			}
			else if (cntx->action == ASYNC_FREE)
			{
				mmi_event_struct temp;
				MMI_FRM_INIT_EVENT(&temp, 0xFFF0);
				MMI_FRM_POST_EVENT(&temp, scrn_group_proc_for_asm_test, evt->user_data);
				return MMI_FRM_ASM_WAITING_TO_FREE;
			}
			break;

		case EVT_ID_ASM_FORCE_FREE:
			ASSERT(cntx != NULL);
			if (cntx->action == SYNC_FORCE_FREE)
			{
				mmi_frm_asm_free_r(cntx->app_id, cntx->ptr);
				cntx->ptr = NULL;
			}
			else if (cntx->action == ASYNC_FORCE_FREE)
			{
				mmi_event_struct temp;
				MMI_FRM_INIT_EVENT(&temp, 0xFFF0);
				MMI_FRM_POST_EVENT(&temp, scrn_group_proc_for_asm_test, evt->user_data);
				return MMI_FRM_ASM_WAITING_TO_FREE;
			}
			break;
			
		case EVT_ID_GROUP_ENTER:
			ASSERT(cntx == NULL);
			cntx = (asm_test_grp_cntx *)mmi_malloc(sizeof(asm_test_grp_cntx));
			cntx->app_id = p->targ_group;
			cntx->ptr = NULL;
			mmi_frm_group_set_user_data(p->targ_group, (void *)cntx);
			break;

		case EVT_ID_GROUP_DEINIT:
			mmi_mfree(cntx);
			break;
	}
	return MMI_RET_OK;
}
static void set_ptr(MMI_ID app_id, void *ptr)
{
	asm_test_grp_cntx *cntx = (asm_test_grp_cntx *)mmi_frm_group_get_user_data(app_id);
	if (cntx != NULL)
	{
		ASSERT(app_id == cntx->app_id);
		cntx->ptr = ptr;
	}
	else
	{
		ASSERT(0);
	}
}

static void set_action(MMI_ID app_id, asm_test_action_enum action)
{
	asm_test_grp_cntx *cntx = (asm_test_grp_cntx *)mmi_frm_group_get_user_data(app_id);
	if (cntx != NULL)
	{
		ASSERT(app_id == cntx->app_id);
		cntx->action = action;
	}
	else
	{
		ASSERT(0);
	}
}

static void asm_test_stop_callback(void)
{
    asm_test_grp_cntx *cntx;
	cntx = get_asmv10_cntx(APPLIB_MEM_AP_ID_TEST3);
	applib_mem_ap_free(cntx->ptr);
    cntx->ptr = NULL;
	free_asmv10_cntx(cntx);
	applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_TEST3, KAL_TRUE);
}

static void asm_test_async_stop_callback(void)
{
    asm_test_grp_cntx *cntx;
	mmi_event_struct temp;
	cntx = get_asmv10_cntx(APPLIB_MEM_AP_ID_TEST4);
	MMI_FRM_INIT_EVENT(&temp, 0xFFF0);
	MMI_FRM_POST_EVENT(&temp, scrn_group_proc_for_asm_test, (void *)cntx);
}

static void test_asmv10_success_callback(void)
{
	kal_uint32 total_size;
	void *ptr;
	total_size = applib_mem_ap_get_max_alloc_size();
	ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST2, total_size);
	ASSERT(ptr != NULL);
	applib_mem_ap_free(ptr);
	mmi_frm_group_close(2000);
	mmi_frm_group_close(1000);
	mmi_frm_group_close(3000);
	mmi_frm_group_close(4000);

}

static MMI_RET test_asm_app_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
    	case EVT_ID_APP_ENTER:
		{
			kal_uint32 total_size;
			void *ptr;
			total_size = mmi_frm_asm_get_max_alloc_size_r(5000);
			ptr = mmi_frm_asm_alloc_r(5000, total_size);
			ASSERT(ptr != NULL);
			mmi_frm_asm_free_r(5000, ptr);
			mmi_frm_group_close(2000);
			mmi_frm_group_close(1000);
			mmi_frm_group_close(3000);
			mmi_frm_group_close(4000);

			break;
    	}

		case EVT_ID_APP_INIT:
			break;
    }
    return MMI_RET_OK;
}

void check_status(void)
{
#ifndef __MMI_FRM_ASM_OOM_SCREEN__
    ASSERT(mmi_frm_group_is_present(1000) == MMI_FALSE);
	ASSERT(mmi_frm_group_is_present(2000) == MMI_FALSE);
	ASSERT(mmi_frm_group_is_present(3000) == MMI_FALSE);
	ASSERT(mmi_frm_group_is_present(4000) == MMI_FALSE);
#endif
}

void test_asm10_trigger()
{
	kal_uint32 total_size;
    void *ptr;
	asm_test_grp_cntx *cntx;
	mmi_frm_asm_property_struct p = {0, 0, 0, 0, 0};
	mmi_frm_group_create_ex(GRP_ID_ROOT, 1000, scrn_group_proc_for_asm_test, NULL, 0);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 2000, scrn_group_proc_for_asm_test, NULL, 0);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 3000, scrn_group_proc_for_asm_test, NULL, 0);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 4000, scrn_group_proc_for_asm_test, NULL, 0);
	
	/* need to clean up cache memory, make sure the ASM pool is empty */
	applib_mem_ap_free_all_cache();

    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_TEST2, 
        STR_GLOBAL_2, 
        IMG_GLOBAL_L2, 
        NULL);
	applib_mem_ap_register(
        APPLIB_MEM_AP_ID_TEST3, 
        STR_GLOBAL_3, 
        IMG_GLOBAL_L3, 
        asm_test_stop_callback);
	applib_mem_ap_register(
        APPLIB_MEM_AP_ID_TEST4, 
        STR_GLOBAL_4, 
        IMG_GLOBAL_L4, 
        asm_test_async_stop_callback);

	ASSERT(0 == applib_mem_ap_get_alloc_count());
	total_size = applib_mem_ap_get_max_alloc_size();
	ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST2, total_size);
	ASSERT(ptr != NULL);
	applib_mem_ap_free(ptr);

    p.f_skip_size_checking = 1;
    mmi_frm_asm_set_property(1000, &p);
	ptr = mmi_frm_asm_alloc_r(1000, 500 * 1024);
	set_ptr(1000, ptr);
	set_action(1000, SYNC_FREE);

	mmi_frm_asm_set_property(2000, &p);
	ptr = mmi_frm_asm_alloc_r(2000, 500 * 1024);
	set_ptr(2000, ptr);
	set_action(2000, SYNC_FORCE_FREE);

	mmi_frm_asm_set_property(3000, &p);
	ptr = mmi_frm_asm_alloc_r(3000, 500 * 1024);
	set_ptr(3000, ptr);
	set_action(3000, ASYNC_FREE);

	mmi_frm_asm_set_property(4000, &p);
	ptr = mmi_frm_asm_alloc_r(4000, 500 * 1024);
	set_ptr(4000, ptr);
	set_action(4000, ASYNC_FORCE_FREE);

	ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST3, 100);
	cntx = alloc_asmv10_cntx();
	set_v10_cntx(cntx, APPLIB_MEM_AP_ID_TEST3, ptr, SYNC_FORCE_FREE);

	ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST4, 100);
	cntx = alloc_asmv10_cntx();
	set_v10_cntx(cntx, APPLIB_MEM_AP_ID_TEST4, ptr, ASYNC_FORCE_FREE);	
	
	ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST2, total_size);
	ASSERT(ptr == NULL);
    mmi_frm_appmem_prompt_to_release_mem(APPLIB_MEM_AP_ID_TEST2, 0, total_size, test_asmv10_success_callback);
	gui_start_timer(10, check_status);
}

void test_asm20_trigger()
{
	kal_uint32 total_size;
    void *ptr;
	asm_test_grp_cntx *cntx;
	mmi_frm_asm_property_struct p = {0, 0, 0, 0, 0};
	mmi_frm_group_create_ex(GRP_ID_ROOT, 1000, scrn_group_proc_for_asm_test, NULL, 0);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 2000, scrn_group_proc_for_asm_test, NULL, 0);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 3000, scrn_group_proc_for_asm_test, NULL, 0);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 4000, scrn_group_proc_for_asm_test, NULL, 0);

	mmi_frm_group_create_ex(GRP_ID_ROOT, 5000, scrn_group_proc_for_asm_test, NULL, 0);
	
	/* need to clean up cache memory, make sure the ASM pool is empty */
	applib_mem_ap_free_all_cache();

	applib_mem_ap_register(
        APPLIB_MEM_AP_ID_TEST3, 
        STR_GLOBAL_3, 
        IMG_GLOBAL_L3, 
        asm_test_stop_callback);
	applib_mem_ap_register(
        APPLIB_MEM_AP_ID_TEST4, 
        STR_GLOBAL_4, 
        IMG_GLOBAL_L4, 
        asm_test_async_stop_callback);

	ASSERT(0 == applib_mem_ap_get_alloc_count());
	p.f_skip_size_checking = 1;
	p.f_prepare_w_reserve = 1;
	mmi_frm_asm_set_property(5000, &p);

    p.f_prepare_w_reserve = 0;
	total_size = mmi_frm_asm_get_max_alloc_size_r(5000);
	ptr = mmi_frm_asm_alloc_r(5000, total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_r(5000, ptr);

    mmi_frm_asm_set_property(1000, &p);
	ptr = mmi_frm_asm_alloc_r(1000, 500 * 1024);
	set_ptr(1000, ptr);
	set_action(1000, SYNC_FREE);

	mmi_frm_asm_set_property(2000, &p);
	ptr = mmi_frm_asm_alloc_r(2000, 500 * 1024);
	set_ptr(2000, ptr);
	set_action(2000, SYNC_FORCE_FREE);

	mmi_frm_asm_set_property(3000, &p);
	ptr = mmi_frm_asm_alloc_r(3000, 500 * 1024);
	set_ptr(3000, ptr);
	set_action(3000, ASYNC_FREE);

	mmi_frm_asm_set_property(4000, &p);
	ptr = mmi_frm_asm_alloc_r(4000, 500 * 1024);
	set_ptr(4000, ptr);
	set_action(4000, ASYNC_FORCE_FREE);

	ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST3, 100);
	cntx = alloc_asmv10_cntx();
	set_v10_cntx(cntx, APPLIB_MEM_AP_ID_TEST3, ptr, SYNC_FORCE_FREE);

	ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST4, 100);
	cntx = alloc_asmv10_cntx();
	set_v10_cntx(cntx, APPLIB_MEM_AP_ID_TEST4, ptr, ASYNC_FORCE_FREE);
	mmi_frm_group_close(5000);
	mmi_frm_app_launch(5000, 0, 0, test_asm_app_proc, NULL, MMI_FRM_APP_SKIP_SIZE_CHECK);
    gui_start_timer(10, check_status);
}

void test_mmi_frm_asm_set_property()
{
    mmi_frm_asm_property_struct p = {0};
	mmi_frm_asm_property_struct q;
	U32 seq1[] = {1, 0, 0, 1, 0};
	U32 seq2[] = {0, 1, 1, 0, 1};
    mmi_frm_group_close(0x1000);
	ASSERT(MMI_FALSE == mmi_frm_asm_set_property(0x1000, &p));
	ASSERT(MMI_FALSE == mmi_frm_asm_set_property(0x1000, &p));
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x1000, NULL, NULL, 0);
	p.f_prepare_w_reserve = seq1[0];
	p.f_hide_in_oom = seq1[1];
	p.f_skip_size_checking = seq1[2];
	p.f_skip_reserve_checking = seq1[3];
	p.f_pluto_launcher = seq1[4];
	ASSERT(MMI_TRUE == mmi_frm_asm_set_property(0x1000, &p));
	ASSERT(MMI_TRUE == mmi_frm_asm_get_property(0x1000, &q));
	ASSERT(q.f_prepare_w_reserve == seq1[0]);
	ASSERT(q.f_hide_in_oom == seq1[1]);
	ASSERT(q.f_skip_size_checking == seq1[2]);
	ASSERT(q.f_skip_reserve_checking == seq1[3]);
	ASSERT(q.f_pluto_launcher == seq1[4]);

	p.f_prepare_w_reserve = seq2[0];
	p.f_hide_in_oom = seq2[1];
	p.f_skip_size_checking = seq2[2];
	p.f_skip_reserve_checking = seq2[3];
	p.f_pluto_launcher = seq2[4];
	ASSERT(MMI_TRUE == mmi_frm_asm_set_property(0x1000, &p));
	ASSERT(MMI_TRUE == mmi_frm_asm_get_property(0x1000, &q));
	ASSERT(q.f_prepare_w_reserve == seq2[0]);
	ASSERT(q.f_hide_in_oom == seq2[1]);
	ASSERT(q.f_skip_size_checking == seq2[2]);
	ASSERT(q.f_skip_reserve_checking == seq2[3]);
	ASSERT(q.f_pluto_launcher == seq2[4]);

	mmi_frm_group_close(0x1000);
}

void test_keep_anonymous_after_back_to_idle()
{
	void *p = NULL;
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x1000, NULL, NULL, 0);
	mmi_frm_close_to_idle_group();
	p = applib_asm_alloc_anonymous(1024);
	ASSERT(p != NULL);
	applib_asm_free_anonymous(p);
	mmi_frm_group_close(0x1000);
}



/*****************************************************************************
 *
 * ASM non-interactive test case
 * test_asm_non_interactive_case is the entry point of this part
 *
 *****************************************************************************/


void applib_mem_screen_other_test(void)
{
    ASSERT(applib_mem_screen_get_pool_size() == 0);
    ASSERT(applib_mem_screen_get_max_alloc_size() == 0);
    ASSERT(applib_mem_screen_get_total_left_size() == 0);
}
void applib_mem_screen_test_venus_java_scrn_mem(void)
{
#if !defined(__MRE_SDK__) && defined(__J2ME__) && defined(__COSMOS_MMI_PACKAGE__)
    void *ptr;
    mmi_frm_group_create_ex(GRP_ID_ROOT, 0x1234, NULL, NULL, 0);
    mmi_frm_scrn_create(0x1234, SCR_JAVA_APP, NULL, NULL);
    ptr = mmi_frm_scrmem_alloc(1024);
    ASSERT(ptr != NULL);
    ASSERT(ptr < mmi_res_get_asm_pool() || ptr > (void *)((CHAR *)mmi_res_get_asm_pool() + mmi_res_get_asm_pool_size()));
    mmi_frm_scrmem_free(ptr);
    mmi_frm_group_close(0x1234);
#endif
}
static MMI_RET scr_asm_test_scrn_proc(mmi_event_struct *evt)
{
    void *ptr = NULL;
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            ptr = mmi_frm_scrmem_alloc(100);
            mmi_frm_scrn_set_user_data(0x1234, 0x1111, ptr);
            mmi_frm_scrmem_disable_debug_leak_check();
            break;
        case EVT_ID_SCRN_INACTIVE:
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}
void applib_mem_screen_debug_leak_disable_check_test(void)
{
    mmi_frm_group_create_ex(GRP_ID_ROOT, 0x1234, NULL, NULL, 0);
    mmi_frm_scrn_create(0x1234, 0x1111, scr_asm_test_scrn_proc, NULL);
    mmi_frm_scrn_create(0x1234, 0x2222, NULL, NULL);
    mmi_frm_scrmem_enable_debug_leak_check();
    mmi_frm_scrmem_free(mmi_frm_scrn_get_user_data(0x1234, 0x1111));
    mmi_frm_scrn_create(0x1234, 0x3333, NULL, NULL);
    mmi_frm_group_close(0x1234);
}
void applib_mem_screen_mmi_name_api_simple_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 *ptr_list[100];
    kal_uint32 i, alloc_count, tmp_size;
    kal_uint32 original_free_space;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    #define ALLOC_MEM_SIZE(_idx)    (_idx + _idx * 32)
    #define PTR_LIST_ARRAY_SIZE       (sizeof(ptr_list) / sizeof(void *))
    mmi_frm_group_create_ex(GRP_ID_ROOT, 0x1234, NULL, NULL, 0);

    ASSERT(applib_mem_ap_get_alloc_count() == 0);
    ASSERT(applib_mem_screen_get_alloc_count() == 0);
    original_free_space = applib_mem_ap_get_total_left_size();

    for (i = 0; i < PTR_LIST_ARRAY_SIZE; i++)
    {
        if (applib_mem_ap_get_total_left_size() < applib_mem_ap_get_max_alloc_size())
        {
            ASSERT(0);
        }
        if ((ptr_list[i] = mmi_frm_scrmem_alloc(ALLOC_MEM_SIZE(i))) == NULL)
        {
            ASSERT(applib_mem_ap_get_max_alloc_size() < ALLOC_MEM_SIZE(i));
            break;
        }
        else
        {
            memset(ptr_list[i], 0, ALLOC_MEM_SIZE(i));
        }
    }
    alloc_count = i;
    ASSERT(applib_mem_ap_get_alloc_count() == alloc_count);
    ASSERT(applib_mem_screen_get_alloc_count() == alloc_count);
    applib_mem_ap_check_integrity();

    tmp_size = 0;
    for (i = 0; i < alloc_count; i++)
    {
        if (i & 0x1)
        {
            /* Keep odd nodes allocated */
            tmp_size += ALLOC_MEM_SIZE(i);
        }
        else
        {
            /* Free even nodes allocated */
            mmi_frm_scrmem_free(ptr_list[i]);
        }
    }
    applib_mem_ap_check_integrity();

    if (alloc_count >= 2)
    {
        for (i = 1; i < alloc_count; i += 2)
        {
            ASSERT(applib_mem_ap_is_valid_block(ptr_list[i]));
        }
    }

    for (i = 0; i < alloc_count; i++)
    {
        if (i & 0x1)
        {
            /* Keep odd nodes allocated */
             mmi_frm_scrmem_free(ptr_list[i]);
        }
    }
    applib_mem_ap_check_integrity();
    ASSERT(applib_mem_ap_get_alloc_count() == 0);
    ASSERT(applib_mem_screen_get_alloc_count() == 0);
    /* Random stress test */
    for (i = 0; i < PTR_LIST_ARRAY_SIZE; i++)
    {
        ptr_list[i] = NULL;
    }

    for ( ; ; )
    {
        kal_uint32 key = rand();                        /* random start position */
        if (key % 1000 == 0)
        {
            break;                                      /* exit for loop */
        }

        i = (key + 1) % PTR_LIST_ARRAY_SIZE;
        if (key % 2 == 0)
        {
            while(i != key % PTR_LIST_ARRAY_SIZE)        /* random operation position */
            {
                if (ptr_list[i])
                {
                    mmi_frm_scrmem_free(ptr_list[i]);
                    ptr_list[i] = NULL;
                    break;
                }
                 i = rand() % PTR_LIST_ARRAY_SIZE;
            }
        }
        else
        {
            for (; i != key % PTR_LIST_ARRAY_SIZE; i++, i %= PTR_LIST_ARRAY_SIZE)
            {
                if (!ptr_list[i])
                {
                    kal_uint32 size = key % applib_mem_ap_get_pool_size();
                    ptr_list[i] = mmi_frm_scrmem_alloc(size);
                    if (ptr_list[i])
                    {
                        memset(ptr_list[i], 0, size);
                    }
                    break;
                }
            }
        }
        applib_mem_ap_check_integrity();
    }
    for (i = 0; i < PTR_LIST_ARRAY_SIZE; i++)
    {
        if (ptr_list[i] != NULL)
        {
            mmi_frm_scrmem_free(ptr_list[i]);
            ptr_list[i] = NULL;
        }
    }    
    applib_mem_ap_check_integrity();
    ASSERT(applib_mem_ap_get_alloc_count() == 0);
    ASSERT(applib_mem_screen_get_alloc_count() == 0);
    mmi_frm_group_close(0x1234);
       
}
/*****************************************************************************
 * FUNCTION
 *  applib_mem_screen_simple_test
 * DESCRIPTION
 *  Simple program to test screen-based ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_screen_simple_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 *ptr_list[100];
    kal_uint32 i, alloc_count, tmp_size;
    kal_uint32 original_free_space;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    #define ALLOC_MEM_SIZE(_idx)    (_idx + _idx * 32)
    #define PTR_LIST_ARRAY_SIZE       (sizeof(ptr_list) / sizeof(void *))
    mmi_frm_group_create_ex(GRP_ID_ROOT, 0x1234, NULL, NULL, 0);

    ASSERT(applib_mem_ap_get_alloc_count() == 0);
    ASSERT(applib_mem_screen_get_alloc_count() == 0);
    original_free_space = applib_mem_ap_get_total_left_size();

    for (i = 0; i < PTR_LIST_ARRAY_SIZE; i++)
    {
        if (applib_mem_ap_get_total_left_size() < applib_mem_ap_get_max_alloc_size())
        {
            ASSERT(0);
        }
        if ((ptr_list[i] = applib_mem_screen_alloc(ALLOC_MEM_SIZE(i))) == NULL)
        {
            ASSERT(applib_mem_ap_get_max_alloc_size() < ALLOC_MEM_SIZE(i));
            break;
        }
        else
        {
            memset(ptr_list[i], 0, ALLOC_MEM_SIZE(i));
        }
    }
    alloc_count = i;
    ASSERT(applib_mem_ap_get_alloc_count() == alloc_count);
    ASSERT(applib_mem_screen_get_alloc_count() == alloc_count);
    applib_mem_ap_check_integrity();

    tmp_size = 0;
    for (i = 0; i < alloc_count; i++)
    {
        if (i & 0x1)
        {
            /* Keep odd nodes allocated */
            tmp_size += ALLOC_MEM_SIZE(i);
        }
        else
        {
            /* Free even nodes allocated */
            applib_mem_screen_free(ptr_list[i]);
        }
    }
    applib_mem_ap_check_integrity();

    if (alloc_count >= 2)
    {
        for (i = 1; i < alloc_count; i += 2)
        {
            ASSERT(applib_mem_ap_is_valid_block(ptr_list[i]));
        }
    }

    for (i = 0; i < alloc_count; i++)
    {
        if (i & 0x1)
        {
            /* Keep odd nodes allocated */
             applib_mem_screen_free(ptr_list[i]);
        }
    }
    applib_mem_ap_check_integrity();
    ASSERT(applib_mem_ap_get_alloc_count() == 0);
    ASSERT(applib_mem_screen_get_alloc_count() == 0);
    /* Random stress test */
    for (i = 0; i < PTR_LIST_ARRAY_SIZE; i++)
    {
        ptr_list[i] = NULL;
    }

    for ( ; ; )
    {
        kal_uint32 key = rand();                        /* random start position */
        if (key % 1000 == 0)
        {
            break;                                      /* exit for loop */
        }

        i = (key + 1) % PTR_LIST_ARRAY_SIZE;
        if (key % 2 == 0)
        {
            while(i != key % PTR_LIST_ARRAY_SIZE)        /* random operation position */
            {
                if (ptr_list[i])
                {
                    applib_mem_screen_free(ptr_list[i]);
                    ptr_list[i] = NULL;
                    break;
                }
                 i = rand() % PTR_LIST_ARRAY_SIZE;
            }
        }
        else
        {
            for (; i != key % PTR_LIST_ARRAY_SIZE; i++, i %= PTR_LIST_ARRAY_SIZE)
            {
                if (!ptr_list[i])
                {
                    kal_uint32 size = key % applib_mem_ap_get_pool_size();
                    ptr_list[i] = applib_mem_screen_alloc(size);
                    if (ptr_list[i])
                    {
                        memset(ptr_list[i], 0, size);
                    }
                    break;
                }
            }
        }
        applib_mem_ap_check_integrity();
    }
    for (i = 0; i < PTR_LIST_ARRAY_SIZE; i++)
    {
        if (ptr_list[i] != NULL)
        {
            applib_mem_screen_free(ptr_list[i]);
            ptr_list[i] = NULL;
        }
    }    
    applib_mem_ap_check_integrity();
    ASSERT(applib_mem_ap_get_alloc_count() == 0);
    ASSERT(applib_mem_screen_get_alloc_count() == 0);
    mmi_frm_group_close(0x1234);
       
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_unit_test_stress_test
 * DESCRIPTION
 *  Stress test for app-based asm synchronization
 * PARAMETERS
 *  app_id    [IN]    application ID
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mem_ap_unit_test_stress_test()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 *ptr_list[100];
    kal_uint32 i, alloc_count, tmp_size;
    kal_uint32 original_free_space, full_pool_size;
    void *full_pool_ptr;
    static kal_uint8 first = 1;
    kal_uint32 app_id = APPLIB_MEM_AP_ID_TEST1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    #define ALLOC_MEM_SIZE(_idx)    (_idx + _idx * 32)
    #define PTR_LIST_ARRAY_SIZE       (sizeof(ptr_list) / sizeof(void *))
    mmi_frm_group_create_ex(GRP_ID_ROOT, 0x1234, NULL, NULL, 0);
    if (first)
    {

        kal_uint32 max_alloc_size;

        max_alloc_size = applib_mem_ap_get_max_alloc_size();
        first = 0;
        ASSERT(applib_mem_ap_get_alloc_count() == 0);

        full_pool_ptr = applib_mem_ap_alloc_full_pool(app_id, &full_pool_size);
        ASSERT(applib_mem_ap_is_valid_block(full_pool_ptr));
        ASSERT(applib_mem_ap_get_alloc_count() == 1);
        ASSERT(full_pool_size == max_alloc_size);
        memset(full_pool_ptr, 0xFF, full_pool_size);
        applib_mem_ap_check_integrity();
        applib_mem_ap_free(full_pool_ptr);
        ASSERT(!applib_mem_ap_is_valid_block(full_pool_ptr));
        ASSERT(applib_mem_ap_get_alloc_count() == 0);
        applib_mem_ap_check_integrity();          
    }
    ASSERT(applib_mem_ap_get_alloc_count() == 0);
  
    applib_mem_ap_free_all(app_id);
    original_free_space = applib_mem_ap_get_total_left_size();

    for (i = 0; i < PTR_LIST_ARRAY_SIZE; i++)
    {
        if (applib_mem_ap_get_total_left_size() < applib_mem_ap_get_max_alloc_size())
        {
            ASSERT(0);
        }
        if ((ptr_list[i] = applib_mem_ap_alloc(app_id, ALLOC_MEM_SIZE(i))) == NULL)
        {
            ASSERT(applib_mem_ap_get_max_alloc_size() < ALLOC_MEM_SIZE(i));
            break;
        }
        else
        {
            memset(ptr_list[i], 0, ALLOC_MEM_SIZE(i));
        }
    }
    alloc_count = i;
    ASSERT(applib_mem_ap_get_alloc_count() == alloc_count);
    applib_mem_ap_check_integrity();

    tmp_size = 0;
    for (i = 0; i < alloc_count; i++)
    {
        if (i & 0x1)
        {
            /* Keep odd nodes allocated */
            tmp_size += ALLOC_MEM_SIZE(i);
        }
        else
        {
            /* Free even nodes allocated */
            applib_mem_ap_free(ptr_list[i]);
        }
    }
    applib_mem_ap_check_integrity();

    if (alloc_count >= 2)
    {
        for (i = 1; i < alloc_count; i += 2)
        {
            ASSERT(applib_mem_ap_is_valid_block(ptr_list[i]));
        }
    }

    applib_mem_ap_free_all(app_id);
    applib_mem_ap_check_integrity();
    ASSERT(applib_mem_ap_get_alloc_count() == 0);
    /* Random stress test */
    for (i = 0; i < PTR_LIST_ARRAY_SIZE; i++)
    {
        ptr_list[i] = NULL;
    }

    for ( ; ; )
    {
        kal_uint32 key = rand();                        /* random start position */
        if (key % 1000 == 0)
        {
            break;                                      /* exit for loop */
        }

        i = (key + 1) % PTR_LIST_ARRAY_SIZE;
        if (key % 2 == 0)
        {
            while(i != key % PTR_LIST_ARRAY_SIZE)        /* random operation position */
            {
                if (ptr_list[i])
                {
                    applib_mem_ap_free(ptr_list[i]);
                    ptr_list[i] = NULL;
                    break;
                }
                 i = rand() % PTR_LIST_ARRAY_SIZE;
            }
        }
        else
        {
            for (; i != key % PTR_LIST_ARRAY_SIZE; i++, i %= PTR_LIST_ARRAY_SIZE)
            {
                if (!ptr_list[i])
                {
                    kal_uint32 size = key % applib_mem_ap_get_pool_size();
                    ptr_list[i] = applib_mem_ap_alloc(app_id, size);
                    if (ptr_list[i])
                    {
                        memset(ptr_list[i], 0, size);
                    }
                    break;
                }
            }
        }
        applib_mem_ap_check_integrity();
    }
    applib_mem_ap_free_all(app_id);
    applib_mem_ap_check_integrity();
    ASSERT(applib_mem_ap_get_alloc_count() == 0);
    mmi_frm_group_close(0x1234);
}

void test_applib_mem_ap_get_name(void)
{
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_TEST1, 
        STR_GLOBAL_1, 
        IMG_GLOBAL_L1, 
        NULL);
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_TEST2, 
        STR_GLOBAL_2, 
        IMG_GLOBAL_L2, 
        NULL);
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_TEST3, 
        STR_GLOBAL_3, 
        IMG_GLOBAL_L3, 
        NULL);
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_TEST4, 
        STR_GLOBAL_4, 
        IMG_GLOBAL_L4, 
        NULL);
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_TEST5, 
        STR_GLOBAL_5, 
        IMG_GLOBAL_L5, 
        NULL);
    //ASSERT(applib_mem_ap_get_name(APP_SDK_TEST) == STR_ID_VS_FW);
    ASSERT(applib_mem_ap_get_name(APPLIB_MEM_AP_ID_TEST1) == STR_GLOBAL_1);
    ASSERT(applib_mem_ap_get_name(APPLIB_MEM_AP_ID_TEST2) == STR_GLOBAL_2);
    ASSERT(applib_mem_ap_get_name(APPLIB_MEM_AP_ID_TEST3) == STR_GLOBAL_3);
    ASSERT(applib_mem_ap_get_name(APPLIB_MEM_AP_ID_TEST4) == STR_GLOBAL_4);
    ASSERT(applib_mem_ap_get_name(APPLIB_MEM_AP_ID_TEST5) == STR_GLOBAL_5);
}

kal_uint32 size_array[] = {32, 64, 128, 256, 512, 1024, 2048, 4096};

void test_applib_mem_ap_get_single_usage(void)
{
    kal_uint32 i;
    kal_uint32 sum = 0;
    MMI_ID group;
    MMI_ID sub_group;
    kal_uint32 count;
    mmi_frm_group_create_ex(GRP_ID_ROOT, 0x1000, NULL, NULL, 0);
    count = applib_mem_ap_get_alloc_count();
    for (i = 0; i < sizeof(size_array) / sizeof(size_array[0]); i++)
    {
        applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST1, size_array[i]);
        applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST2, 110);
        sum += size_array[i]; 
    }

    ASSERT(applib_mem_ap_get_single_usage(APPLIB_MEM_AP_ID_TEST1) == sum + APPLIB_MEM_CHUNK_EXTRA_SIZE * i);
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST1);
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST2);
    applib_mem_ap_check_integrity();
    ASSERT(applib_mem_ap_get_alloc_count() == 0);

    group = mmi_frm_group_create_ex(GRP_ID_ROOT, 1000, NULL, NULL, 0);
    
    sub_group = mmi_frm_group_create_ex(1000, 2000, NULL, NULL, 0);
    sum = 0;
    for (i = 0; i < sizeof(size_array) / sizeof(size_array[0]); i++)
    {
        applib_mem_ap_alloc(group, size_array[i]);
        applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST2, 110);
        applib_mem_ap_alloc(sub_group, size_array[i]);
        sum += size_array[i]; 
    }   

    ASSERT(applib_mem_ap_get_single_usage(group) == 2 * (sum + APPLIB_MEM_CHUNK_EXTRA_SIZE * i));
    applib_mem_ap_free_all(group);
    applib_mem_ap_free_all(sub_group);
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST2);
    mmi_frm_group_close(group);
    mmi_frm_group_close(sub_group);
    applib_mem_ap_check_integrity();
    ASSERT(applib_mem_ap_get_alloc_count() == count);
    mmi_frm_group_close(0x1000);
}

kal_bool asm_test_get_usage_callback(kal_uint16 app_id)
{
    if (app_id == 0x4000 || app_id == 0x1000)
    {
        return KAL_TRUE;
    }
	return KAL_FALSE;
}


void test_applib_mem_ap_get_current_usage_ex(void)
{
    applib_mem_ap_usage_struct * applist = (applib_mem_ap_usage_struct *)mmi_malloc(sizeof(applib_mem_ap_usage_struct) * 10);
	mmi_frm_asm_property_struct p = {0, 0, 0, 0, 0};
	MMI_ID skip_list[] = {0x4000, 0x1000};
	kal_uint32 count;
	void *ptr1;
	void *ptr2;
	void *ptr3;
	void *ptr4;
	void *ptr5;
	applib_mem_ap_register(
        APPLIB_MEM_AP_ID_TEST1, 
        STR_GLOBAL_1, 
        IMG_GLOBAL_L1, 
        NULL);
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_TEST2, 
        STR_GLOBAL_2, 
        IMG_GLOBAL_L2, 
        NULL);

	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x1000, NULL, NULL, 0);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x2000, NULL, NULL, 0);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x3000, NULL, NULL, 0);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 0x4000, NULL, NULL, 0);
	mmi_frm_group_create_ex(0x4000, 0x4001, NULL, NULL, 0);
    ASSERT(applib_mem_ap_get_alloc_count() == 0);
	applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST1, 1024);
	applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST2, 2048);
	p.f_skip_size_checking = 1;
	mmi_frm_asm_set_property(0x1000, &p);
	mmi_frm_asm_set_property(0x2000, &p);
	mmi_frm_asm_set_property(0x3000, &p);
	mmi_frm_asm_set_property(0x4000, &p);
	ptr1 = mmi_frm_asm_alloc_r(0x1000, 512);
	ptr2 = mmi_frm_asm_alloc_r(0x2000, 256);
	ptr3 = mmi_frm_asm_alloc_r(0x3000, 1000);
	ptr4 = mmi_frm_asm_alloc_r(0x4000, 2000);
	ptr5 = mmi_frm_asm_alloc_r(0x4001, 3000);
	applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST2, 2048);

	count = applib_mem_ap_get_current_usage_ex(
		applist,
		10,
		KAL_FALSE,
		KAL_FALSE,
		NULL,
		0,
		NULL);
	ASSERT(count == 6);
	ASSERT(applist[0].app_id == 0x4000);
	ASSERT(applist[1].app_id == APPLIB_MEM_AP_ID_TEST2);
	ASSERT(applist[2].app_id == APPLIB_MEM_AP_ID_TEST1);
	ASSERT(applist[3].app_id == 0x3000);
	ASSERT(applist[4].app_id == 0x1000);
	ASSERT(applist[5].app_id == 0x2000);

	p.f_hide_in_oom = 1;
	mmi_frm_asm_set_property(0x2000, &p);

	count = applib_mem_ap_get_current_usage_ex(
		applist,
		10,
		KAL_TRUE,
		KAL_TRUE,
		skip_list,
		sizeof(skip_list) / sizeof(skip_list[0]),
		NULL);

	ASSERT(count == 2);
	ASSERT(applist[0].app_id == 0x3000);
	ASSERT(applist[1].app_id == 0x2000);

	count = applib_mem_ap_get_current_usage_ex(
		applist,
		10,
		KAL_FALSE,
		KAL_TRUE,
		skip_list,
		sizeof(skip_list) / sizeof(skip_list[0]),
		NULL);	
	ASSERT(count == 1);
	ASSERT(applist[0].app_id == 0x3000);


	count = applib_mem_ap_get_current_usage_ex(
		applist,
		10,
		KAL_FALSE,
		KAL_TRUE,
		NULL,
		0,
		asm_test_get_usage_callback);	
	ASSERT(count == 1);
	ASSERT(applist[0].app_id == 0x3000);

	
	applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST1);
	applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST2);
	mmi_frm_asm_free_r(0x1000,ptr1);
	mmi_frm_asm_free_r(0x2000, ptr2);
	mmi_frm_asm_free_r(0x3000, ptr3);
	mmi_frm_asm_free_r(0x4000, ptr4);
	mmi_frm_asm_free_r(0x4001, ptr5);
	ASSERT(applib_mem_ap_get_alloc_count() == 0);
	mmi_frm_group_close(0x1000);
	mmi_frm_group_close(0x2000);
	mmi_frm_group_close(0x3000);
	mmi_frm_group_close(0x4000);
	mmi_mfree(applist);   
}


void test_applib_mem_ap_get_current_usage(void)
{
    applib_mem_ap_usage_struct * applist = (applib_mem_ap_usage_struct *)mmi_malloc(sizeof(applib_mem_ap_usage_struct) * 10);
    kal_uint32 count;
    kal_uint32 before_count;
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_TEST1, 
        STR_GLOBAL_1, 
        IMG_GLOBAL_L1, 
        NULL);
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_TEST2, 
        STR_GLOBAL_2, 
        IMG_GLOBAL_L2, 
        NULL);
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_TEST3, 
        STR_GLOBAL_3, 
        IMG_GLOBAL_L3, 
        NULL);
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_TEST4, 
        STR_GLOBAL_4, 
        IMG_GLOBAL_L4, 
        NULL);
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_TEST5, 
        STR_GLOBAL_5, 
        IMG_GLOBAL_L5, 
        NULL);
    mmi_frm_group_create_ex(GRP_ID_ROOT, 1000, NULL, NULL, 0);
    before_count = applib_mem_ap_get_alloc_count();
    applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST1, 128);
    applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST2, 256);
    applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST1, 64);
    applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST3, 64);
    applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST4, 1024);
    applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST2, 4096);

    count = applib_mem_ap_get_current_usage(applist, 5);
    ASSERT(count == 4);
    ASSERT(applist[0].app_id == APPLIB_MEM_AP_ID_TEST2);
    ASSERT(applist[0].string_id == STR_GLOBAL_2);
    ASSERT(applist[0].mem_size == 4096 + 256 + 2 * APPLIB_MEM_CHUNK_EXTRA_SIZE);
    ASSERT(applist[0].is_stopping == KAL_FALSE);

    ASSERT(applist[1].app_id == APPLIB_MEM_AP_ID_TEST4);
    ASSERT(applist[1].string_id == STR_GLOBAL_4);
    ASSERT(applist[1].is_stopping == KAL_FALSE);
    ASSERT(applist[1].mem_size == 1024 + APPLIB_MEM_CHUNK_EXTRA_SIZE);

    ASSERT(applist[2].app_id == APPLIB_MEM_AP_ID_TEST1);
    ASSERT(applist[2].string_id == STR_GLOBAL_1);
    ASSERT(applist[2].is_stopping == KAL_FALSE);
    ASSERT(applist[2].mem_size == 128 + 64 + 2 * APPLIB_MEM_CHUNK_EXTRA_SIZE);

    ASSERT(applist[3].app_id == APPLIB_MEM_AP_ID_TEST3);
    ASSERT(applist[3].string_id == STR_GLOBAL_3);
    ASSERT(applist[3].is_stopping == KAL_FALSE);
    ASSERT(applist[3].mem_size == 64 +  APPLIB_MEM_CHUNK_EXTRA_SIZE);

    applib_mem_ap_set_hide(APPLIB_MEM_AP_ID_TEST2, KAL_TRUE);
    count = applib_mem_ap_get_current_usage(applist, 5);
    ASSERT(count == 3);

    ASSERT(applist[0].app_id == APPLIB_MEM_AP_ID_TEST4);
    ASSERT(applist[0].string_id == STR_GLOBAL_4);
    ASSERT(applist[0].is_stopping == KAL_FALSE);
    ASSERT(applist[0].mem_size == 1024 + APPLIB_MEM_CHUNK_EXTRA_SIZE);

    ASSERT(applist[1].app_id == APPLIB_MEM_AP_ID_TEST1);
    ASSERT(applist[1].string_id == STR_GLOBAL_1);
    ASSERT(applist[1].is_stopping == KAL_FALSE);
    ASSERT(applist[1].mem_size == 128 + 64 + 2 * APPLIB_MEM_CHUNK_EXTRA_SIZE);

    ASSERT(applist[2].app_id == APPLIB_MEM_AP_ID_TEST3);
    ASSERT(applist[2].string_id == STR_GLOBAL_3);
    ASSERT(applist[2].is_stopping == KAL_FALSE);
    ASSERT(applist[2].mem_size == 64 +  APPLIB_MEM_CHUNK_EXTRA_SIZE);

    applib_mem_ap_set_hide(APPLIB_MEM_AP_ID_TEST2, KAL_FALSE);

    count = applib_mem_ap_get_current_usage(applist, 5);
    ASSERT(count == 4);
    ASSERT(applist[0].app_id == APPLIB_MEM_AP_ID_TEST2);
    ASSERT(applist[0].string_id == STR_GLOBAL_2);
    ASSERT(applist[0].mem_size == 4096 + 256 + 2 * APPLIB_MEM_CHUNK_EXTRA_SIZE);
    ASSERT(applist[0].is_stopping == KAL_FALSE);

    ASSERT(applist[1].app_id == APPLIB_MEM_AP_ID_TEST4);
    ASSERT(applist[1].string_id == STR_GLOBAL_4);
    ASSERT(applist[1].is_stopping == KAL_FALSE);
    ASSERT(applist[1].mem_size == 1024 + APPLIB_MEM_CHUNK_EXTRA_SIZE);

    ASSERT(applist[2].app_id == APPLIB_MEM_AP_ID_TEST1);
    ASSERT(applist[2].string_id == STR_GLOBAL_1);
    ASSERT(applist[2].is_stopping == KAL_FALSE);
    ASSERT(applist[2].mem_size == 128 + 64 + 2 * APPLIB_MEM_CHUNK_EXTRA_SIZE);

    ASSERT(applist[3].app_id == APPLIB_MEM_AP_ID_TEST3);
    ASSERT(applist[3].string_id == STR_GLOBAL_3);
    ASSERT(applist[3].is_stopping == KAL_FALSE);
    ASSERT(applist[3].mem_size == 64 +  APPLIB_MEM_CHUNK_EXTRA_SIZE);

    applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST5, 128);
    count = applib_mem_ap_get_current_usage(applist, 4);
    ASSERT(count == 4);
    ASSERT(applist[0].app_id == APPLIB_MEM_AP_ID_TEST2);
    ASSERT(applist[0].string_id == STR_GLOBAL_2);
    ASSERT(applist[0].mem_size == 4096 + 256 + 2 * APPLIB_MEM_CHUNK_EXTRA_SIZE);
    ASSERT(applist[0].is_stopping == KAL_FALSE);

    ASSERT(applist[1].app_id == APPLIB_MEM_AP_ID_TEST4);
    ASSERT(applist[1].string_id == STR_GLOBAL_4);
    ASSERT(applist[1].is_stopping == KAL_FALSE);
    ASSERT(applist[1].mem_size == 1024 + APPLIB_MEM_CHUNK_EXTRA_SIZE);

    ASSERT(applist[2].app_id == APPLIB_MEM_AP_ID_TEST5);
    ASSERT(applist[2].string_id == STR_GLOBAL_5);
    ASSERT(applist[2].is_stopping == KAL_FALSE);
    ASSERT(applist[2].mem_size == 128 + APPLIB_MEM_CHUNK_EXTRA_SIZE);

    ASSERT(applist[3].app_id == APPLIB_MEM_AP_ID_TEST3);
    ASSERT(applist[3].string_id == STR_GLOBAL_3);
    ASSERT(applist[3].is_stopping == KAL_FALSE);
    ASSERT(applist[3].mem_size == 64 +  APPLIB_MEM_CHUNK_EXTRA_SIZE);    

    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST1);
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST2);
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST3);
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST4);
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST5);
    
    mmi_frm_group_create_ex(GRP_ID_ROOT, APP_SDK_TEST, NULL, NULL, 0);
    mmi_frm_group_create_ex(APP_SDK_TEST, 2000, NULL, NULL, 0);

    mmi_frm_group_create_ex(GRP_ID_ROOT, 3000, NULL, NULL, 0);

    applib_mem_ap_alloc(APP_SDK_TEST, 2048);
    applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST5, 256);
    applib_mem_ap_alloc(2000, 4096);
    applib_mem_ap_alloc(3000, 51200);

    mmi_frm_group_close(3000);

    count = applib_mem_ap_get_current_usage(applist, 5);
    ASSERT(2 == count);

    ASSERT(applist[0].app_id == APP_SDK_TEST);
    //ASSERT(applist[0].string_id == STR_ID_VS_FW);
    ASSERT(applist[0].mem_size == 4096 + 2048 + 2 * APPLIB_MEM_CHUNK_EXTRA_SIZE);
    ASSERT(applist[0].is_stopping == KAL_FALSE);

    ASSERT(applist[1].app_id == APPLIB_MEM_AP_ID_TEST5);
    ASSERT(applist[1].string_id == STR_GLOBAL_5);
    ASSERT(applist[1].is_stopping == KAL_FALSE);
    ASSERT(applist[1].mem_size == 256 + APPLIB_MEM_CHUNK_EXTRA_SIZE);

    mmi_frm_group_create_ex(GRP_ID_ROOT, 3000, NULL, NULL, 0);

	count = applib_mem_ap_get_current_usage(applist, 5);
    ASSERT(3 == count);
    ASSERT(applist[0].app_id == 3000);
    ASSERT(applist[0].string_id == 0);
    ASSERT(applist[0].mem_size == 51200 + APPLIB_MEM_CHUNK_EXTRA_SIZE);
    ASSERT(applist[0].is_stopping == KAL_FALSE);


    ASSERT(applist[1].app_id == APP_SDK_TEST);
    //ASSERT(applist[1].string_id == STR_ID_VS_FW);
    ASSERT(applist[1].mem_size == 4096 + 2048 + 2 * APPLIB_MEM_CHUNK_EXTRA_SIZE);
    ASSERT(applist[1].is_stopping == KAL_FALSE);

    ASSERT(applist[2].app_id == APPLIB_MEM_AP_ID_TEST5);
    ASSERT(applist[2].string_id == STR_GLOBAL_5);
    ASSERT(applist[2].is_stopping == KAL_FALSE);
    ASSERT(applist[2].mem_size == 256 + APPLIB_MEM_CHUNK_EXTRA_SIZE);

#ifdef __COSMOS_MMI_PACKAGE__
    {   
        mmi_frm_asm_property_struct p;
        p.f_hide_in_oom         = 1;    
        mmi_frm_asm_set_property(3000 , &p);
        ASSERT(2 == count);
        
        ASSERT(applist[0].app_id == APP_SDK_TEST);
        ASSERT(applist[0].string_id == STR_ID_VS_FW);
        ASSERT(applist[0].mem_size == 4096 + 2048 + 2 * APPLIB_MEM_CHUNK_EXTRA_SIZE);
        ASSERT(applist[0].is_stopping == KAL_FALSE);
        
        ASSERT(applist[1].app_id == APPLIB_MEM_AP_ID_TEST5);
        ASSERT(applist[1].string_id == STR_GLOBAL_5);
        ASSERT(applist[1].is_stopping == KAL_FALSE);
        ASSERT(applist[1].mem_size == 256 + APPLIB_MEM_CHUNK_EXTRA_SIZE);
        
    }
#endif
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST5);
    applib_mem_ap_free_all(3000);
    applib_mem_ap_free_all(2000);
    applib_mem_ap_free_all(APP_SDK_TEST);
    mmi_frm_group_close(APP_SDK_TEST);
    mmi_frm_group_close(3000);
    
    ASSERT(applib_mem_ap_get_alloc_count() == before_count);
    mmi_frm_group_close(1000);
    mmi_mfree(applist);
}
extern applib_mem_ut_internal_function(void);
void test_asm_non_interactive_case()
{
    applib_mem_ut_internal_function();
    test_applib_mem_ap_get_current_usage();
    test_applib_mem_ap_get_single_usage();
    test_applib_mem_ap_get_name();
    applib_mem_ap_unit_test_stress_test();
    applib_mem_screen_simple_test();
    applib_mem_screen_mmi_name_api_simple_test();
    applib_mem_screen_debug_leak_disable_check_test();
    applib_mem_screen_other_test();
}
#endif /* APPLIB_MEM_UNIT_TEST */

