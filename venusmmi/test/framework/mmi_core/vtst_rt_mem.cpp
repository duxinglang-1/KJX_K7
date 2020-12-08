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
 *  vtst_rt_mem.cpp
 *
 * Project:
 * --------
 *  Venus Regression Test for memory
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
 * removed!
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

#ifdef __AFX_RT_TEST__

extern "C"
{
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "CustDataRes.h"
#include "mmi_res_range_def.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_mem_gprot.h"
#include "wgui_categories_list.h"
#include "mmi_frm_events_gprot.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
#include "kal_public_defs.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
}

#include "vtst_rt_main.h"
#include "..\Framework\vadp_asm.h"
#include "vfx_datatype.h"
#include "vfx_app.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_cpp_base.h"
#include "vfx_string.h"
#include "vfx_app_launcher.h"
#include "vfx_sys_memory.h"
#include "vfx_signal.h"
#include "string.h"
#include "vrt_datatype.h"

static VfxU32 get_app_extra_size(mmi_id id)
{
    return mmi_res_get_app_fg_mem_size(id) + mmi_res_get_app_base_mem_size(id) - mmi_res_get_app_heap_size(id);
}

/***************************************************************************** 
 * VtstMyApp
 *****************************************************************************/

struct VtstMyAppParam
{
    VtstRtApp*  testcase;
    VfxChar     *str;
};

class VtstMyApp : public VfxApp
{
    VtstRtApp*  m_testcase;
    void*       m_fgPtr;

public:
    VFX_DECLARE_CLASS(VtstMyApp);

    VtstMyApp() : m_testcase(NULL), m_fgPtr(NULL) {};

    void confirmResultCB(VtstRtAppScr* sender, VfxBool result)
    {
        m_testcase->check(result, VFX_WSTR("User Confirm"));
        m_testcase->endPhase();

        VfxAppLauncher::terminate(getGroupId());
    }

    mmi_ret onProc(mmi_event_struct *evt)
    {
        switch (evt->evt_id)
        {
        case EVT_ID_GROUP_ENTER:
            VadpAsmProperty p;
            VadpAsm::getProperty(getGroupId(), p);
            p.f_skip_size_checking = 1;
            VadpAsm::setProperty(getGroupId(), p);
            break;
        }
        return MMI_RET_OK;
    }

    void onGroupActive()
    {
        if (!m_fgPtr)
        {
            // allocate fg memory
            m_fgPtr = vadpAsmAlloc(getGroupId(), mmi_res_get_app_fg_mem_size(getGroupId()));
        }
    }

    void onGroupInactive()
    {
         if (m_fgPtr)
        {
            // free fg memory
            vadpAsmFree(getGroupId(), m_fgPtr);
            m_fgPtr = NULL;
        }
    }

    void onRun(void *arg, VfxU32 argSize)
    {
        VFX_TRACE(("===> [%d][%d] VtstMyApp launched !\n", getGroupId(), (VfxU32)arg));
        
        VtstMyAppParam *param = (VtstMyAppParam *)arg;

        m_testcase = param->testcase;

        // allocate foreground memory
        if (!m_fgPtr)
            m_fgPtr = vadpAsmAlloc(getGroupId(), mmi_res_get_app_fg_mem_size(getGroupId()));

        VtstRtAppScr *scr;
        VFX_OBJ_CREATE(scr, VtstRtAppScr, this);

        VfxWString wstr;
        wstr.format("%s", param->str);
        scr->setTitle(wstr);
        scr->confirm(VFX_WSTR("Is it OK?"), VtstRtAppScrConfirmCB(this, &VtstMyApp::confirmResultCB));
        scr->show();
    }
};
VFX_IMPLEMENT_CLASS("MyApp", VtstMyApp, VfxApp);


/***************************************************************************** 
 * VtstRtASMTest
 *****************************************************************************/

class VtstRtASMTest : public VtstRtApp
{
    VFX_DECLARE_CLASS(VtstRtASMTest);
// Constructor / Destructor
public:
    VtstRtASMTest()        
    {
    }

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize)
    {
        VtstRtApp::onRun(args, argSize);
        
        vtst_testcase_start(this, VFX_FALSE);
    }

protected:
    virtual void onInit()
    {
        VtstRtApp::onInit();
    }

    virtual int start()
    {
        return 0; // unknow phase count
    }

    virtual VfxS32 phase(VfxS32 idx)
    { 
        if (idx == 0)
        {
            VfxU32 heapSize;
            VtstMyAppParam param;
            param.testcase = this;
            param.str = "Please wait until OOM shows";

            VFX_ASSERT(mmi_frm_asm_get_max_alloc_size_r(APP3_BASE) > get_app_extra_size(APP3_BASE) + 1024);
            heapSize = mmi_frm_asm_get_max_alloc_size_r(APP3_BASE) - get_app_extra_size(APP3_BASE) - 1024;

            mmi_id app3_id = VfxAppLauncher::launchWithAsmSize( 
                                    APP3_BASE, 
                                    VFX_OBJ_CLASS_INFO(VtstMyApp),
                                    GRP_ID_ROOT,
                                    heapSize,
                                    &param,
                                    sizeof(param));
            return 1000;
        }
        else if (idx == 1)
        {
            VfxU32 heapSize;
            VtstMyAppParam param;
            param.testcase = this;
            param.str = "New app launched";

            heapSize = applib_mem_ap_get_pool_size() >> 1;
            mmi_id app2_id = VfxAppLauncher::launchWithAsmSize( 
                                    APP2_BASE, 
                                    VFX_OBJ_CLASS_INFO(VtstMyApp),
                                    GRP_ID_ROOT,
                                    heapSize,
                                    &param,
                                    sizeof(param));
            return -1;
        }
        else if (idx == 2)
        {
            U32 heapSize;
            VtstMyAppParam param;
            param.testcase = this;
            param.str = "FG mem alloc test (1)";

            VFX_ASSERT(mmi_frm_asm_get_max_alloc_size_r(APP2_BASE) > get_app_extra_size(APP2_BASE) + 1024);
            heapSize = mmi_frm_asm_get_max_alloc_size_r(APP2_BASE) - get_app_extra_size(APP2_BASE) - 1024;
            
            mmi_id app2_id = VfxAppLauncher::launchWithAsmSize( 
                                    APP2_BASE, 
                                    VFX_OBJ_CLASS_INFO(VtstMyApp),
                                    GRP_ID_ROOT,
                                    heapSize,
                                    &param,
                                    sizeof(param));
            return 1500;
        }
        else if (idx == 3)
        {
            VtstMyAppParam param;
            param.testcase = this;
            param.str = "FG mem alloc test (2)";
            mmi_id app3_id = VfxAppLauncher::launch( 
                                    APP3_BASE, 
                                    VFX_OBJ_CLASS_INFO(VtstMyApp),
                                    GRP_ID_ROOT,
                                    &param,
                                    sizeof(param));
            return -1;
        }
        else
        {
            return VTST_RT_END_TESTCASE;;
        }
    }

    virtual void end()
    {
    }

// Variable
protected:
};
VFX_IMPLEMENT_CLASS("RtASMTest", VtstRtASMTest, VtstRtApp);


#include "app_mem.h"

static void vtst_rt_free_mem_cb(void *memPtr, void *userData)
{
    mmi_frm_asm_free_anonymous(memPtr);
}


VtstTestResultEnum vtst_rt_asm(VfxU32 param)
{
    VtstRtAppStartupParam startup;
    startup.memSize = 300*1024;
    startup.buffer  = (VfxU8 *)mmi_frm_asm_alloc_anonymous(startup.memSize);

    mmi_id app_id = VfxAppLauncher::launchWithMem( 
                            APP1_BASE, 
                            VFX_OBJ_CLASS_INFO(VtstRtASMTest),
                            GRP_ID_ROOT,
                            (void *)startup.buffer,startup.memSize,
                            vtst_rt_free_mem_cb, NULL,
                            &startup,
                            sizeof(VtstRtAppStartupParam));
    return VTST_TR_OK;
}


#define __MMI_NEW_MEM__

#ifdef __MMI_NEW_MEM__

extern "C" {

enum {
    EVT_ID_APP_FINISHED = EVT_ID_SCENARIO_MAX + 1,
};


/***************************************************************************** 
 * SRV1_Gprot.h
 *****************************************************************************/

#define ID_SRV1 1100

typedef struct
{
S32 my_field1;
S32 my_field2[64];
} srv1_context_struct;

#define SRV1_CONTEXT_SIZE sizeof(srv1_context_struct)


/***************************************************************************** 
 * SRV1.c
 *****************************************************************************/

mmi_ret srv1_create(mmi_id parent, mmi_id* ret_id)
{
    srv1_context_struct* context = NULL;
    mmi_id id = mmi_frm_srv_instance_create(parent, ID_SRV1, NULL, NULL);
    
    MMI_ASSERT(ret_id);

    /* allocate memory by service ID */
    context = (srv1_context_struct*)mmi_frm_asm_alloc_r(id, SRV1_CONTEXT_SIZE);

    if (context == NULL)
    {
        mmi_frm_srv_instance_close(id);
        return MMI_RET_ERR;
    }
    
    *ret_id = id;
    // init context data here
    mmi_frm_srv_instance_set_user_data(id, context);
    return MMI_RET_OK;
}

void srv1_close(mmi_id id)
{
    srv1_context_struct* context = (srv1_context_struct*)mmi_frm_srv_instance_get_user_data(id);

    if (!context)
        return;
    
    // do close logic here
    mmi_frm_srv_instance_close(id);
    mmi_frm_asm_free_r(id, context);
}

void srv1_do_something(mmi_id id)
{
    srv1_context_struct* context = (srv1_context_struct*)mmi_frm_srv_instance_get_user_data(id);

    // do something with context data
}

/*************************************************************************
 APP2_Gprot.h
*************************************************************************/

// APP2 just an example that it use only global.

#define APP2_ID APP2_BASE

/*************************************************************************
 APP2.c
*************************************************************************/
mmi_id  g_app_id = GRP_ID_INVALID;
mmi_id  g_srv1_id = GRP_ID_INVALID;
void    *g_mem_pool_p = NULL;

extern mmi_ret app2_launch_prepare(mmi_frm_asm_evt_struct *evt);
extern mmi_ret app2_entry_prepare(mmi_frm_asm_evt_struct *evt);
extern void app2_scrn1_entry();
extern void app2_scrn1_exit();
extern void app2_exit();
extern mmi_ret mmi_app2_group_proc(mmi_event_struct *evt);


mmi_id app2_launch(mmi_id caller_id, const WCHAR *str, MMI_BOOL force_prepare)
{
    mmi_frm_asm_prepare_flag_type flag = force_prepare ? MMI_FRM_ASM_F_FORCE_PREPARE : MMI_FRM_ASM_F_NONE;
    g_app_id = mmi_frm_group_create(GRP_ID_ROOT, APP2_ID, mmi_app2_group_proc, (void *)str);
    // after enter group, app2 becomes foreground
    mmi_frm_group_enter(g_app_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_group_set_caller(g_app_id, caller_id);

    mmi_frm_asm_prepare(g_app_id, 0, (mmi_proc_func)app2_launch_prepare, NULL /*userdata*/, flag);
    return g_app_id;
}

mmi_ret app2_launch_prepare(mmi_frm_asm_evt_struct *evt)
{
    mmi_id id = evt->app_id;
    mmi_ret srv_ret1 = MMI_RET_ERR, ret_val = MMI_RET_OK;
    MMI_ASSERT(id == g_app_id);

    switch (evt->evt_id)
    {
    case EVT_ID_ASM_CANCELED:
        app2_exit();
        break;
        
    case EVT_ID_ASM_PREPARED:
        srv_ret1 = srv1_create(g_app_id, &g_srv1_id);
        
        if (srv_ret1 != MMI_RET_OK)
        {
            app2_exit();
            break;
        }
        
        // the app need to have foreground memory
        mmi_frm_asm_prepare(g_app_id, APP2_POOL_SIZE - APP2_HEAP_SIZE, (mmi_proc_func)app2_entry_prepare, NULL /*userdata*/, MMI_FRM_ASM_F_NONE);
        break;
    }
    return ret_val;
}

mmi_ret app2_entry_prepare(mmi_frm_asm_evt_struct *evt)
{   
    switch (evt->evt_id)
    {
    case EVT_ID_ASM_CANCELED:
        app2_exit();
        break;

    case EVT_ID_ASM_PREPARED:
        app2_scrn1_entry();
        break;
    }
    return MMI_RET_OK;
}

void app2_scrn1_entry()
{   
    if(mmi_frm_scrn_enter(g_app_id, GRP_ID_AUTO_GEN, (FuncPtr) app2_scrn1_exit,
                            (FuncPtr) app2_scrn1_entry, MMI_FRM_FULL_SCRN))
    {
        void *user_data = mmi_frm_group_get_user_data(g_app_id);
        const WCHAR *str = (const WCHAR *) (user_data ? user_data : L"APP2 - SCR1");
        // Now, my app is in active mode now, let's create fg memory        
        if (g_mem_pool_p == NULL)
        {
            g_mem_pool_p = mmi_frm_asm_alloc_r(g_app_id, APP2_POOL_SIZE - APP2_HEAP_SIZE);
            
            // In this case, it is impossible that fail to alloc.
            MMI_ASSERT(g_mem_pool_p);

            // But if your case is more complex and may fragment, you can do as follows:
            if (g_mem_pool_p == NULL)
            {
                // Only happend when fragment
                // You can exit the APP, so just show service is not available.
            }
        }        
        // show category and do your logic
        mmi_confirm_property_struct arg;
        mmi_confirm_property_init(&arg, CNFM_TYPE_OK);
        arg.parent_id = g_app_id;
        mmi_confirm_display((WCHAR *)str, MMI_EVENT_INFO, &arg);
    }
}

void app2_scrn1_exit()
{
    if (g_mem_pool_p)
    {
        mmi_frm_asm_free_r(g_app_id, g_mem_pool_p);
        g_mem_pool_p = NULL;
    }
}

void app2_exit()
{
    if (g_srv1_id != GRP_ID_INVALID)
    {
        srv1_close(g_srv1_id);
        g_srv1_id = GRP_ID_INVALID;
    }
    if (g_app_id != GRP_ID_INVALID)
    {
        mmi_id id = g_app_id;
        mmi_group_event_struct evt;
        g_app_id = GRP_ID_INVALID;
        
        MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_APP_FINISHED, id);
        mmi_frm_group_send_to_caller(id, &evt);
        
        mmi_frm_group_close(id);            
    }
}


mmi_ret mmi_app2_group_proc(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
    case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *quit = (mmi_alert_result_evt_struct *)evt;
            switch(quit->result)
            {
            case MMI_ALERT_CNFM_OK:
                app2_exit();
                break;
            }
        }
        break;

    case EVT_ID_GROUP_EXIT:
        app2_exit();
        break;
    }
    return MMI_RET_OK;
}


/*************************************************************************
 APP3_Gprot.h
*************************************************************************/

// APP3 is just example that its context is in ASM.
// APP3 has no foreground memory.

#define APP3_ID APP3_BASE

typedef struct 
{
    mmi_id  app_id;
    void    *mem_pool_p;
    const WCHAR *str;
} app3_context_struct;

#define APP3_CONTEXT_SIZE sizeof(app3_context_struct)

/*************************************************************************
 APP3.c
*************************************************************************/

extern mmi_ret app3_launch_prepare(mmi_frm_asm_evt_struct *evt);
extern void app3_scrn1_entry(mmi_id app_id);
extern void app3_scrn1_exit();
extern void app3_exit(mmi_id app_id);
extern mmi_ret mmi_app3_group_proc(mmi_event_struct *evt);


mmi_id app3_launch(mmi_id caller_id, const WCHAR *str)
{
    mmi_id app_id = mmi_frm_group_create(GRP_ID_ROOT, APP3_ID, mmi_app3_group_proc, NULL);
    mmi_frm_group_enter(app_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_group_set_caller(app_id, caller_id);

    mmi_frm_asm_prepare(app_id, 0, (mmi_proc_func)app3_launch_prepare, (void *)str, MMI_FRM_ASM_F_NONE);
    return app_id;
}

mmi_ret app3_launch_prepare(mmi_frm_asm_evt_struct *evt)
{
    mmi_ret ret_val = MMI_RET_OK;
    
    switch (evt->evt_id)
    {
    case EVT_ID_ASM_CANCELED:
        app3_exit(evt->app_id);
        break;

    case EVT_ID_ASM_PREPARED:
        app3_context_struct* context = (app3_context_struct*) mmi_frm_asm_alloc_r(evt->app_id, APP3_CONTEXT_SIZE);
        MMI_ASSERT(context); // impossible
        mmi_frm_group_set_user_data(evt->app_id, context);
        
        context->mem_pool_p = mmi_frm_asm_alloc_r(evt->app_id, APP3_HEAP_SIZE - APP3_CONTEXT_SIZE);
        context->str        = (const WCHAR *)evt->user_data;
        MMI_ASSERT(context->mem_pool_p); // impossible
        
        // the app need to have foreground memory
        app3_scrn1_entry(evt->app_id);
        break;
    }
    return ret_val;
}

void app3_exit(mmi_id app_id)
{
    app3_context_struct* context = (app3_context_struct*) mmi_frm_group_get_user_data(app_id);
    mmi_group_event_struct evt;

    // context may NULL when launching or stopping
    if (context)
    {
        if (context->mem_pool_p)
        {
            mmi_frm_asm_free_r(app_id, context->mem_pool_p);
            context->mem_pool_p = NULL;
        }
        MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_APP_FINISHED, app_id);
        mmi_frm_group_send_to_caller(app_id, &evt);
        mmi_frm_group_close(app_id);
        mmi_frm_asm_free_r(app_id, context);
    }

}

void app3_scrn1_entry(mmi_id app_id)
{   
    if(mmi_frm_scrn_enter(app_id, GRP_ID_AUTO_GEN,
        (FuncPtr) app3_scrn1_exit,
        (FuncPtr) app3_scrn1_entry,
        MMI_FRM_FULL_SCRN))
    {
        app3_context_struct *ctx = (app3_context_struct *)mmi_frm_group_get_user_data(app_id);
        const WCHAR *str = (const WCHAR *)(ctx->str ? ctx->str : (const WCHAR *)L"APP3 - SCR1");
        mmi_confirm_property_struct arg;
        mmi_confirm_property_init(&arg, CNFM_TYPE_OK);
        arg.parent_id = app_id;
        arg.user_tag = (void *)app_id;
        mmi_confirm_display((WCHAR *)str, MMI_EVENT_INFO, &arg);
    }
}

void app3_scrn1_exit()
{
}


mmi_ret mmi_app3_group_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
    case EVT_ID_ASM_FORCE_FREE:
        {
            mmi_frm_asm_evt_struct *asmEvt = (mmi_frm_asm_evt_struct *)evt;
            app3_exit(asmEvt->app_id);
        }
        break;
        
    case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *quit = (mmi_alert_result_evt_struct *)evt;
            switch(quit->result)
            {
            case MMI_ALERT_CNFM_OK:
                app3_exit((mmi_id)((U32)(quit->user_tag) & 0xFFFF));
                break;
            }
        }
        break;
    }
    return MMI_RET_OK;
}

/*************************************************************************
 APP1 : simple ex
*************************************************************************/

#define APP1_ID APP1_BASE

typedef struct {
    U32 data;
} mmi_app1_ctx_struct;

extern void app1_exit(mmi_id id);
extern mmi_ret mmi_app1_prepare_proc(mmi_frm_asm_evt_struct *evt);
extern mmi_ret mmi_app1_group_proc(mmi_frm_asm_evt_struct *evt);
extern void app1_scrn1_entry();

void mmi_app1_LSK_hdlr()
{
    mmi_id id;
    id = mmi_frm_group_create(APP1_ID, GRP_ID_AUTO_GEN, (mmi_proc_func)mmi_app1_group_proc, NULL);
    mmi_frm_group_enter(id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_frm_asm_prepare(id, 0 /* whole app required size */, (mmi_proc_func)mmi_app1_prepare_proc, NULL, MMI_FRM_ASM_F_NONE);
}

mmi_ret mmi_app1_prepare_proc(mmi_frm_asm_evt_struct *evt)
{   
    mmi_app1_ctx_struct *ctx_ptr;
    
    switch(evt->evt_id)
    {
    case EVT_ID_ASM_CANCELED:
        /* user cancel it, do nothing */
        break;

    case EVT_ID_ASM_PREPARED:
        /* allocate mem. and show screen */
        ctx_ptr = (mmi_app1_ctx_struct *)mmi_frm_asm_alloc_r(evt->app_id, sizeof(mmi_app1_ctx_struct));
        MMI_ASSERT(ctx_ptr);
        mmi_frm_group_set_user_data(evt->app_id, ctx_ptr);
        app1_scrn1_entry();
        break;
    }
    return MMI_RET_OK;
}

mmi_ret mmi_app1_group_proc(mmi_frm_asm_evt_struct *evt)
{
    mmi_app1_ctx_struct *ctx = (mmi_app1_ctx_struct *)evt->user_data;
    
    if (!ctx)   /* if ctx not ready, just return */
        return MMI_RET_OK;
    
    switch(evt->evt_id)
    {
    case EVT_ID_ASM_FORCE_FREE:
        app1_exit(evt->app_id);
        break;
    }
    return MMI_RET_OK;
}

void app1_exit(mmi_id id)
{
    /* exit app1 and free ctx */
    mmi_app1_ctx_struct *ctx = (mmi_app1_ctx_struct *)mmi_frm_group_get_user_data(id);
    if (ctx)
    {
        mmi_frm_group_close(id);
        mmi_frm_asm_free_r(id, ctx);
    }
}

void app1_scrn1_entry()
{
}

/*************************************************************************
 MRE test case
*************************************************************************/

#define VTST_MRE_ID             (APP1_BASE)
#define VTST_MRE_APP_NUM_MAX    (2)

typedef void (*vtst_mre_app_main_func)(mmi_id caller_id);

typedef struct {
    vtst_mre_app_main_func main;
    U32 heap_size;
} vtst_mre_app_info_struct;

extern void vtst_mre_app1_launch(mmi_id caller_id);
extern void vtst_mre_app2_launch(mmi_id caller_id);
extern mmi_ret vtst_mre_app_proc(mmi_event_struct *evt);
extern void vtst_mre_close(mmi_id mre_id);

const vtst_mre_app_info_struct vtst_mre_app_info[VTST_MRE_APP_NUM_MAX] = {
    {vtst_mre_app1_launch, 200*1024},
    {vtst_mre_app2_launch, 300*1024}
};

typedef struct {
    mmi_id app_id;
    KAL_ADM_ID adm_id;
    void *heap;
} vtst_mre_app_struct;

typedef struct {
    vtst_mre_app_struct app[VTST_MRE_APP_NUM_MAX];
    U32 app_count;
} vtst_mre_ctx_struct;


static mmi_id g_mre_id = GRP_ID_INVALID;
static U32 g_mre_app_idx = (U32)-1;

const kal_uint32 mre_subpool_size[] = {16, 32, 64, 128, 256, 512, 1024, 2048, 0xffffffff, 0};


void *vtst_mre_malloc(U32 size)
{
    vtst_mre_ctx_struct *ctx = (vtst_mre_ctx_struct *)mmi_frm_group_get_user_data(g_mre_id);
    return kal_adm_alloc(ctx->app[g_mre_app_idx].adm_id, size);
}


void vtst_mre_free(void *ptr)
{
    vtst_mre_ctx_struct *ctx = (vtst_mre_ctx_struct *)mmi_frm_group_get_user_data(g_mre_id);
    kal_adm_free(ctx->app[g_mre_app_idx].adm_id, ptr);
}


static void vtst_mre_app_launch(U32 idx)
{
    vtst_mre_ctx_struct *ctx = (vtst_mre_ctx_struct *)mmi_frm_group_get_user_data(g_mre_id);
    void *heap = NULL;
    mmi_frm_asm_property_struct p;

    VFX_ASSERT(idx < VTST_MRE_APP_NUM_MAX);

    ctx->app[idx].app_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, vtst_mre_app_proc, (void *)idx);
    mmi_frm_group_enter(ctx->app[idx].app_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_frm_asm_get_property(ctx->app[idx].app_id, &p);
    p.f_skip_size_checking = 1;
    mmi_frm_asm_set_property(ctx->app[idx].app_id, &p);
    
    heap = mmi_frm_asm_alloc_r(ctx->app[idx].app_id, vtst_mre_app_info[idx].heap_size);
    g_mre_app_idx = idx;

    ctx->app[idx].heap   = heap;
    ctx->app[idx].adm_id = kal_adm_create(heap, vtst_mre_app_info[idx].heap_size, (kal_uint32 *)mre_subpool_size, KAL_FALSE);
    vtst_mre_app_info[idx].main(g_mre_id);    // launch mre app
    ctx->app_count++;
    VFX_ASSERT(ctx->app_count <= VTST_MRE_APP_NUM_MAX);
}


static void vtst_mre_app_close(U32 idx)
{
    vtst_mre_ctx_struct *ctx = (vtst_mre_ctx_struct *)mmi_frm_group_get_user_data(g_mre_id);
    kal_adm_delete(ctx->app[idx].adm_id);
    mmi_frm_group_close(ctx->app[idx].app_id);
    mmi_frm_asm_free_r(ctx->app[idx].app_id, ctx->app[idx].heap);
    ctx->app[idx].heap      = NULL;
    ctx->app[idx].app_id    = GRP_ID_INVALID;
    ctx->app_count--;
    VFX_ASSERT(ctx->app_count >= 0);
}

static void vtst_mre_app_close_all()
{
    vtst_mre_ctx_struct *ctx = (vtst_mre_ctx_struct *)mmi_frm_group_get_user_data(g_mre_id);
    U32 i;

    if (!ctx)
        return;
    
    for (i=0; i<VTST_MRE_APP_NUM_MAX; i++)
    {
        if (ctx->app[i].app_id != GRP_ID_INVALID)
            vtst_mre_app_close(i);
    }
}

mmi_ret vtst_mre_app_proc(mmi_event_struct *evt)
{
    U32 idx = (U32)evt->user_data;
    vtst_mre_ctx_struct *ctx = (vtst_mre_ctx_struct *)mmi_frm_group_get_user_data(g_mre_id);
    
    if (!ctx)
        return MMI_RET_OK;
    
    switch (evt->evt_id)
    {
    case EVT_ID_GROUP_DEINIT:
    case EVT_ID_ASM_FORCE_FREE:
        {
            mmi_group_event_struct grpEvt;
            MMI_FRM_INIT_GROUP_EVENT(&grpEvt, EVT_ID_APP_FINISHED, ctx->app[idx].app_id);
            vtst_mre_app_close(idx);    // close mre app
            mmi_frm_group_send_to_caller(ctx->app[idx].app_id, &grpEvt);
        }
        break;    
    }
    return MMI_RET_OK;
}


mmi_ret vtst_mre_engine_proc(mmi_event_struct *evt)
{
    vtst_mre_ctx_struct *ctx = (vtst_mre_ctx_struct *)mmi_frm_group_get_user_data(g_mre_id);

    if (!ctx)
        return MMI_RET_OK;

    switch(evt->evt_id)
    {
    case EVT_ID_APP_FINISHED:
        if (ctx->app_count == 0)
            vtst_mre_close(g_mre_id);
        break;
        
    case EVT_ID_ASM_FORCE_FREE:
    case EVT_ID_GROUP_DEINIT:
        vtst_mre_app_close_all();
        vtst_mre_close(g_mre_id);
        break;
    }
    return MMI_RET_OK;
}


mmi_ret vtst_mre_prepare_ok(mmi_frm_asm_evt_struct *evt)
{
    vtst_mre_ctx_struct *ctx = NULL;
    
    VFX_ASSERT(evt->evt_id == EVT_ID_ASM_PREPARED);
    
    // prepare context
    ctx = (vtst_mre_ctx_struct *)mmi_frm_asm_alloc_r(evt->app_id, sizeof(vtst_mre_ctx_struct));
    VFX_ASSERT(ctx);
    mmi_frm_group_set_user_data(evt->app_id, ctx);
    memset(ctx, 0, sizeof(ctx));

    // show screen and allow to launch mre app
    vtst_mre_app_launch(0);
    vtst_mre_app_launch(1);
    return MMI_RET_OK;
}


mmi_id vtst_mre_launch(mmi_id caller_id)
{
    mmi_frm_asm_property_struct property;
    g_mre_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, vtst_mre_engine_proc, NULL);
    mmi_frm_asm_property_init(&property);
    property.f_hide_in_oom = 1;
    property.f_skip_size_checking = 1;
    mmi_frm_asm_set_property(g_mre_id, &property);
    mmi_frm_asm_prepare(g_mre_id, 0, (mmi_proc_func)vtst_mre_prepare_ok, NULL, MMI_FRM_ASM_F_NONE);
    return g_mre_id;
}


void vtst_mre_close(mmi_id mre_id)
{
    vtst_mre_ctx_struct *ctx = (vtst_mre_ctx_struct *)mmi_frm_group_get_user_data(mre_id);
    VFX_ASSERT(ctx->app_count == 0);
    mmi_frm_group_close(mre_id);
    mmi_frm_asm_free_r(mre_id, ctx);
}


mmi_id vtst_mre_get_id()
{
    vtst_mre_ctx_struct *ctx = (vtst_mre_ctx_struct *)mmi_frm_group_get_user_data(g_mre_id);
    return ctx->app[g_mre_app_idx].app_id;
}


void vtst_mre_app1_launch(mmi_id caller_id)
{
    // do something
    mmi_id srv_id;  
    void *ptr1, *ptr2;
    
    ptr1 = vtst_mre_malloc(10*1024);
    VFX_ASSERT(ptr1);
    ptr2 = vtst_mre_malloc(20*1024);
    VFX_ASSERT(ptr2);
    
    srv1_create(vtst_mre_get_id(), &srv_id);
    
    vtst_mre_free(ptr1);
    vtst_mre_free(ptr2);
    srv1_close(srv_id);
}


void vtst_mre_app2_launch(mmi_id caller_id)
{
    // do something
    void *ptr1, *ptr2;
    ptr1 = vtst_mre_malloc(10*1024);
    VFX_ASSERT(ptr1);
    ptr2 = vtst_mre_malloc(20*1024);
    VFX_ASSERT(ptr2);
    vtst_mre_free(ptr1);
    vtst_mre_free(ptr2);
}

/*************************************************************************
 video (prepare w/ reserve)
*************************************************************************/

extern mmi_ret mmi_media_player_prepare_ready(mmi_event_struct *evt);
extern mmi_ret mmi_media_player_proc(mmi_event_struct *evt);


mmi_id mmi_media_player_launch(mmi_id caller_id)
{
    mmi_id mp_id;
    mmi_frm_asm_property_struct property;
    mp_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_media_player_proc, NULL);
    
    mmi_frm_asm_property_init(&property);
    property.f_prepare_w_reserve = 1;
    mmi_frm_asm_set_property(mp_id, &property);
    mmi_frm_asm_prepare(mp_id, 0, mmi_media_player_prepare_ready, 0, MMI_FRM_ASM_F_NONE);
    return mp_id;
}

mmi_ret mmi_media_player_prepare_ready(mmi_event_struct *evt)
{
    // call med task to do something
    return MMI_RET_OK;
}


mmi_ret mmi_media_player_proc(mmi_event_struct *evt)
{
    VFX_UNUSED(evt);
    return MMI_RET_OK;
}


void med_xxx_do_something(kal_uint16 app_id)
{
    kal_uint32 size = 10*1024;
    void *mem = mmi_frm_asm_alloc_r(app_id, size);
    ASSERT(mem);
    // do something
}


///////////////////////////////////////////////////////////
// app for async free

typedef struct {
    mmi_id app_id;
    void *mem_ptr;
} async_app_ctx_struct;

static async_app_ctx_struct g_async_app_ctx = {0};

static void async_app_timer_cb(void *arg)
{
    async_app_ctx_struct *ctx = (async_app_ctx_struct *)arg;
    if (ctx->mem_ptr)
    {
        mmi_frm_asm_free_r(ctx->app_id, ctx->mem_ptr);
        ctx->mem_ptr = NULL;
        applib_mem_ap_notify_stop_finished(ctx->app_id, KAL_TRUE);
    }
}

mmi_ret async_app_proc(mmi_event_struct *evt)
{
    async_app_ctx_struct *ctx = (async_app_ctx_struct *)evt->user_data;

    if (!ctx)
        return MMI_RET_OK;

    switch(evt->evt_id)
    {
    case EVT_ID_ASM_FREE_REQ:
    case EVT_ID_ASM_FORCE_FREE:
        // free mem later
        StartTimerEx(KEY_TIMER_ID1, 500, async_app_timer_cb, ctx);
        return MMI_FRM_ASM_WAITING_TO_FREE;       
    }
    return MMI_RET_OK;
}

mmi_id async_app_launch(mmi_id caller_id, U32 mem_size)
{
    mmi_frm_asm_property_struct p;
    g_async_app_ctx.app_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, async_app_proc, &g_async_app_ctx);
    mmi_frm_asm_get_property(g_async_app_ctx.app_id, &p);
    p.f_skip_size_checking = 1;
    mmi_frm_asm_set_property(g_async_app_ctx.app_id, &p);
    g_async_app_ctx.mem_ptr = mmi_frm_asm_alloc_r(g_async_app_ctx.app_id, mem_size);
    return g_async_app_ctx.app_id;
}

}; /* extern "C" */


/***************************************************************************** 
 * VtstRtASMTest
 *****************************************************************************/

class VtstRtNewMemTest;

typedef struct {
    VtstRtNewMemTest *pRt;
    mmi_id appId;
    U32 poolSize;
    U32 allocCount;
} allocate_test_struct;

class VtstRtNewMemTest : public VtstRtApp
{
    VFX_DECLARE_CLASS(VtstRtNewMemTest);
// Constructor / Destructor
public:
    VtstRtNewMemTest() : m_tempPtr(NULL)
    {
    }

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize)
    {
        VtstRtApp::onRun(args, argSize);
        
        vtst_testcase_start(this, VFX_FALSE);
    }

    virtual mmi_ret onProc(mmi_event_struct *e)
    {
        switch (e->evt_id)
        {
        case EVT_ID_APP_FINISHED:
            {
                endPhase();
            }
            break;
        }
        return MMI_RET_OK;
    }

public:

    static void allocate_test(allocate_test_struct *arg)
    {
        VtstRtNewMemTest *pRt = arg->pRt;
        U32 i, count = arg->allocCount;
        void *ptr[10];

        for (i=0; i<count; i++)
        {
            ptr[i] = (U32 *)mmi_frm_asm_alloc_r(arg->appId, (U32)(arg->poolSize / count));
            pRt->check(ptr[i] != NULL, VFX_WSTR("allocate_test check"));
        }
        for (i=0; i<count; i++)
        {
            mmi_frm_asm_free_r(arg->appId, ptr[i]);
            ptr[i] = NULL;
        }

        VFX_FREE_MEM(arg);
        pRt->endPhase();
    }
    
    void prepare_w_reserve_cb(mmi_frm_asm_evt_struct *evt)
    {
        switch(evt->evt_id)
        {
        case EVT_ID_ASM_PREPARED:
            {
                /* prepare w/ reserve, so mem. should be still available after timer timeout */
                allocate_test_struct *arg;
                VFX_ALLOC_MEM(arg, sizeof(allocate_test_struct), this);
                arg->appId      = evt->app_id;
                // since we may allocate in background, only base memory can be used.
                arg->poolSize   = mmi_res_get_app_base_mem_size(evt->app_id);
                arg->allocCount = 3;
                arg->pRt        = this;
                StartTimerEx(KEY_TIMER_ID0, 100, (oslTimerFuncPtr)VtstRtNewMemTest::allocate_test, arg);
            }
            break;

        case EVT_ID_ASM_CANCELED:
            break;
        }
    }

    static mmi_ret dummy_proc(mmi_event_struct *evt)
    {
        VFX_UNUSED(evt);
        return MMI_RET_OK;
    }

protected:
    virtual void onInit()
    {
        VtstRtApp::onInit();
    }

    virtual int start()
    {
        return 0; // unknow phase count
    }

    virtual VfxS32 phase(VfxS32 idx)
    { 
        if  (idx == 0)
        {
            /* set/get property */
            mmi_frm_asm_property_struct p;

            mmi_frm_group_create(GRP_ID_ROOT, APP2_ID, (mmi_proc_func)VtstRtNewMemTest::dummy_proc, NULL);
            mmi_frm_group_enter(APP2_ID, MMI_FRM_NODE_NONE_FLAG);

            memset(&p, 0, sizeof(mmi_frm_asm_property_struct));
            p.f_hide_in_oom = 1;
            mmi_frm_asm_set_property(APP2_ID, &p);
            memset(&p, 0, sizeof(mmi_frm_asm_property_struct));
            mmi_frm_asm_get_property(APP2_ID, &p);
            check(p.f_hide_in_oom == 1, VFX_WSTR("f_hide_in_oom check"));

            memset(&p, 0, sizeof(mmi_frm_asm_property_struct));
            p.f_prepare_w_reserve = 1;
            mmi_frm_asm_set_property(APP2_ID, &p);
            memset(&p, 0, sizeof(mmi_frm_asm_property_struct));
            mmi_frm_asm_get_property(APP2_ID, &p);
            check(p.f_prepare_w_reserve == 1, VFX_WSTR("f_prepare_w_reserve check"));

            memset(&p, 0, sizeof(mmi_frm_asm_property_struct));
            p.f_skip_size_checking= 1;
            mmi_frm_asm_set_property(APP2_ID, &p);
            memset(&p, 0, sizeof(mmi_frm_asm_property_struct));
            mmi_frm_asm_get_property(APP2_ID, &p);
            check(p.f_skip_size_checking == 1, VFX_WSTR("f_skip_size_checking check"));

            mmi_frm_group_close(APP2_ID);

            /* anonymous access */
            VfxU32 size = mmi_frm_asm_get_pool_size_r();
            void *ptr = NULL;
            ptr = mmi_frm_asm_alloc_anonymous(size >> 1);
            check(ptr, VFX_WSTR("anonymous alloc"));
            mmi_frm_asm_free_anonymous(ptr);
            check(mmi_frm_asm_get_pool_size_r() == size, VFX_WSTR("anonymous free"));
            
            return 10;
        }
        else if (idx == 1)
        {
            /* get/set property : VenusFW version */
            VadpAsmProperty pr, pw;

            mmi_frm_group_create(GRP_ID_ROOT, APP2_ID, (mmi_proc_func)VtstRtNewMemTest::dummy_proc, NULL);
            mmi_frm_group_enter(APP2_ID, MMI_FRM_NODE_NONE_FLAG);

            pr.clear();
            pw.clear();

            pw.f_hide_in_oom = 1;
            VadpAsm::setProperty(APP2_ID, pw);
            VadpAsm::getProperty(APP2_ID, pr);
            check(pr.f_hide_in_oom == 1, VFX_WSTR("f_hide_in_oom check"));

            pw.f_prepare_w_reserve = 1;
            VadpAsm::setProperty(APP2_ID, pw);
            VadpAsm::getProperty(APP2_ID, pr);
            check(pr.f_prepare_w_reserve == 1, VFX_WSTR("f_prepare_w_reserve check"));

            pw.f_skip_size_checking = 1;
            VadpAsm::setProperty(APP2_ID, pw);
            VadpAsm::getProperty(APP2_ID, pr);
            check(pr.f_skip_size_checking == 1, VFX_WSTR("f_skip_size_checking check"));

            mmi_frm_group_close(APP2_ID);
            return 10;
        }
        else if (idx == 2)
        {
            /* prepare w/ reserve */
            mmi_frm_group_create(GRP_ID_ROOT, APP2_ID, (mmi_proc_func)&VtstRtNewMemTest::dummy_proc, NULL);
            mmi_frm_group_enter(APP2_ID, MMI_FRM_NODE_NONE_FLAG);

            VadpAsmProperty p;
            p.f_prepare_w_reserve   = 1;
            VadpAsm::setProperty(APP2_ID, p);

            // if callback type is different, may cast it by (void (VfxObject::*)(mmi_frm_asm_evt_struct *))
            VadpAsm::prepare(APP2_ID, 0, VadpAsm::PrepareCb(this, &VtstRtNewMemTest::prepare_w_reserve_cb), 0);

            /* allocate remaining. after this, AP2 still can allocate successfully from reserved pool */
            mmi_frm_group_create(GRP_ID_ROOT, APP3_ID, (mmi_proc_func)&VtstRtNewMemTest::dummy_proc, NULL);
            mmi_frm_group_enter(APP3_ID, MMI_FRM_NODE_NONE_FLAG);
            
            VadpAsm::getProperty(APP3_ID, p);
            p.f_skip_size_checking = 1;
            VadpAsm::setProperty(APP3_ID, p);
            m_tempPtr = vadpAsmAlloc(APP3_ID, VadpAsm::getMaxAllocSize(APP3_ID) - 1024);
            return -1;
        }
        else if (idx == 3)
        {
            if (m_tempPtr)
            {
                vadpAsmFree(APP3_ID, m_tempPtr);
                m_tempPtr = NULL;
            }

            mmi_frm_group_close(APP2_ID);
            mmi_frm_group_close(APP3_ID);
			return 10;
        }
        else if (idx == 4)
        {           
            mmi_frm_asm_property_struct p;
            U32 maxASM = mmi_frm_asm_get_max_alloc_size_r(APP3_ID) - 256;
            U32 app2Fg = mmi_res_get_app_fg_mem_size(APP2_ID);
            mmi_frm_group_create(GRP_ID_ROOT, APP3_ID, mmi_app3_group_proc, NULL);

            mmi_frm_asm_get_property(APP3_ID, &p);
            p.f_skip_size_checking = 1;
            mmi_frm_asm_set_property(APP3_ID, &p);
            void *ptr = mmi_frm_asm_alloc_r(APP3_ID, (maxASM > app2Fg) ? maxASM - app2Fg : maxASM);
            
            mmi_id id = app2_launch(getGroupId(), (const WCHAR *)L"run APP2 directly", MMI_FALSE);
            
            /* free mem. immediately */
            mmi_frm_asm_free_r(APP3_ID, ptr);
            mmi_frm_group_close(APP3_ID);

            return -1;
        }
        else if (idx == 5)
        {
            mmi_frm_asm_property_struct p;
            U32 maxASM = mmi_frm_asm_get_max_alloc_size_r(APP3_ID) - 256;
            U32 app2Fg = mmi_res_get_app_fg_mem_size(APP2_ID);
            U32 size;
            mmi_frm_group_create(GRP_ID_ROOT, APP3_ID, mmi_app3_group_proc, NULL);

            mmi_frm_asm_get_property(APP3_ID, &p);
            p.f_skip_size_checking = 1;
            mmi_frm_asm_set_property(APP3_ID, &p);

            size = (maxASM > app2Fg) ? maxASM - app2Fg : maxASM;
            void *ptr = applib_mem_ap_alloc(APP3_ID, size);
            if (ptr)
            {
                memset(ptr, 0, size);
                mmi_frm_group_set_user_data(APP3_ID, ptr);
            }
            
            mmi_id id = app2_launch(getGroupId(), (const WCHAR *)L"run APP2 after OOM", MMI_FALSE);
         
            return -1;
        }
        else if (idx == 6)
        {
            void *ptr = mmi_frm_group_get_user_data(APP3_ID);
            if (ptr)
            {
                mmi_frm_asm_free_r(APP3_ID, ptr);
                mmi_frm_group_close(APP3_ID);
            }
            return 10;
        }
        else if (idx == 7)
        {
            vtst_mre_launch(getGroupId());
            return 2000;
        }
        else if (idx == 8)
        {
            mmi_id id = app3_launch(getGroupId(), (const WCHAR *)L"run APP3");
            return -1;
        }
        else if (idx == 9)
        {
            VfxU32 size = applib_mem_ap_get_max_alloc_size_int();
            async_app_launch(GRP_ID_ROOT, size - 1024);
            mmi_id id = app2_launch(getGroupId(), (const WCHAR *)L"force prepare APP launched", MMI_TRUE);
            return -1;
        }
        else
        {
            return VTST_RT_END_TESTCASE;;
        }
    }

    virtual void end()
    {
    }

// Variable
protected:
    void *m_tempPtr;
};
VFX_IMPLEMENT_CLASS("NewMemTest", VtstRtNewMemTest, VtstRtApp);


#include "app_mem.h"


VtstTestResultEnum vtst_rt_newMem(VfxU32 param)
{
    VtstRtAppStartupParam startup;
    startup.memSize = APP1_HEAP_SIZE;
    startup.buffer  = (VfxU8 *)mmi_frm_asm_alloc_anonymous(startup.memSize);

    mmi_id app_id = VfxAppLauncher::launchWithMem( 
                            APP1_BASE, 
                            VFX_OBJ_CLASS_INFO(VtstRtNewMemTest),
                            GRP_ID_ROOT,
                            (void *)startup.buffer,startup.memSize,
                            vtst_rt_free_mem_cb, NULL,
                            &startup,
                            sizeof(VtstRtAppStartupParam));
    return VTST_TR_OK;
}

#endif /* __MMI_NEW_MEM__ */

#ifdef APPLIB_MEM_UNIT_TEST
extern "C" void mmi_frm_asm_test_case_entry(U8 index);
#endif // APPLIB_MEM_UNIT_TEST

VtstTestResultEnum vtst_rt_asm_v1(VfxU32 param)
{
#ifdef APPLIB_MEM_UNIT_TEST
    // run all test case
    mmi_frm_asm_test_case_entry(0);
#endif // APPLIB_MEM_UNIT_TEST
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

