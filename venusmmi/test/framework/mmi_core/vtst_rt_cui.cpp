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
 *  vtst_rt_cui.cpp
 *
 * Project:
 * --------
 *  Venus FW
 *
 * Description:
 * ------------
 *  Venus Regression Test for CUI
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "string.h"
#include "stdio.h"

extern "C" {
#include "MMIDataType.h"
#include "mmi_res_range_def.h"
#include "mmi_frm_events_gprot.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "app_mem.h"
#include "stack_config.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
}

#include "vtst_rt_cui.h"
#include "vtst_rt_main.h"
#include "vfx_app_launcher.h"
#include "vfx_object.h"
#include "vfx_datatype.h"
#include "vfx_app.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_cui.h"
#include "vfx_timer.h"
#include "vrt_datatype.h"
#include "vfx_string.h"
#include "vfx_signal.h"

/***************************************************************************** 
 * CUI Scenario Interface
 *****************************************************************************/

extern "C"
{

mmi_id cui_cui1_create(mmi_id parent_id, VtstCuiLaunchStruct *arg)
{
    mmi_id cui_id = VfxAppLauncher::createCui(
                                        CUI1_BASE,
                                        VFX_OBJ_CLASS_INFO(VtstCui),
                                        parent_id,
                                        arg,
                                        sizeof(VtstCuiLaunchStruct));
    return cui_id;
}

void cui_cui1_run(mmi_id cui_id)
{
    VfxAppLauncher::runCui(cui_id);
}

void cui_cui1_set_flag(mmi_id cui_id, VfxU32 flag)
{
    VtstCui *obj = (VtstCui *)VfxApp::getObject(cui_id);
    obj->setFlag(flag);
}

void cui_cui1_set_path(mmi_id cui_id, VfxChar *path, VfxU32 pathLen)
{
    VtstCui *obj = (VtstCui *)VfxApp::getObject(cui_id);
    obj->setPath(path, pathLen);
}

PS8 cui_cui1_get_result(mmi_id cui_id)
{
    VtstCui *obj = (VtstCui *)VfxApp::getObject(cui_id);
    return obj->getResult();
}

void cui_cui1_close(mmi_id cui_id)
{
    VfxAppLauncher::terminate(cui_id);
}


} /* extern "C" */


/***************************************************************************** 
 * VtstCui
 *****************************************************************************/

#define VTST_CUI_FILE_PATH  "d:\\camera\\"
#define VTST_CUI_FILENAME  "test.mp3"
#define VTST_CUI_ACK        (28324)

VFX_IMPLEMENT_CLASS("VtstCui", VtstCui, VfxCui);


void VtstCui::sendResultTimerCb(VfxTimer *timer)
{
    timer->stop();
    
    mmi_group_event_struct evt;

    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_VTST_FINISHED, m_groupId);
    sendToParent(&evt);
}


void VtstCui::cuiStartPostResultCb(mmi_group_event_struct *originalEvt, mmi_ret result)
{
    VFX_ASSERT(EVT_ID_CUI_VTST_STARTED == originalEvt->evt_id);
    VFX_ASSERT(VTST_CUI_ACK == result);
}


void VtstCui::onRun(void *arg, VfxU32 argSize)
{
    VtstCuiLaunchStruct *cuiArg = (VtstCuiLaunchStruct *)arg;
    VFX_ASSERT(sizeof(VtstCuiLaunchStruct) == argSize);

    m_testcase  = cuiArg->testcase;
    m_flag      = cuiArg->flag;
    strncpy(m_startPath, cuiArg->startPath, sizeof(m_startPath));

    VtstRtAppScr *scr;
    VFX_OBJ_CREATE(scr, VtstRtAppScr, this);
    
    VfxWString wstr;
    wstr.format("VtstCui %d scr", m_groupId);
    scr->setTitle(wstr);
    wstr.format("(%d)(%s)", cuiArg->flag, cuiArg->startPath);
    scr->setStatus(wstr);
    scr->show();

    VfxTimer *timer;
    VFX_OBJ_CREATE(timer, VfxTimer, this);
    timer->setStartDelay(1000);
    timer->m_signalTick.connect(this, &VtstCui::sendResultTimerCb);
    timer->start();

    // notify CUI is started
    mmi_group_event_struct evt;
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_VTST_STARTED, m_groupId);
    postToParent(&evt, VfxCuiPostToParentCb(this, &VtstCui::cuiStartPostResultCb));
}


void VtstCui::setFlag(VfxU32 flag)
{
    m_flag = flag;
}


VfxU32 VtstCui::getFlag()
{
    return m_flag;
}


void VtstCui::setPath(VfxChar *path, VfxU32 pathLen)
{
    VFX_ASSERT(path);
    VfxU32 len = (sizeof(m_startPath)-1 > pathLen) ? pathLen : sizeof(m_startPath)-1;
    memcpy(m_startPath, path, len);
    m_startPath[len] = '\0';
}


void VtstCui::getPath(VfxChar *buff, VfxU32 buffSize)
{
    VFX_ASSERT(buff);
    VFX_ASSERT(buffSize > strlen(m_startPath));
    strcpy(buff, m_startPath);
}


VfxChar *VtstCui::getResult()
{
    VfxChar *str = &m_startPath[strlen(m_startPath)];
    VFX_ASSERT(strlen(m_startPath) + strlen(VTST_CUI_FILENAME) < sizeof(m_startPath));
    
    sprintf(str, "%s", VTST_CUI_FILENAME);
    return m_startPath;
}

/***************************************************************************** 
 * VtstRtCuiTest
 *****************************************************************************/

static void *app_mem_ptr = NULL;

class VtstRtCuiTest : public VtstRtApp
{
    VFX_DECLARE_CLASS(VtstRtCuiTest);
// Constructor / Destructor
public:
    VtstRtCuiTest() {}
    virtual ~VtstRtCuiTest() 
    {
        if (app_mem_ptr)
        {
            applib_mem_ap_free(app_mem_ptr);
            app_mem_ptr = NULL;
        }
    }

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize)
    {
        VtstRtApp::onRun(args, argSize);
        
        vtst_testcase_start(this, VFX_FALSE);       
    }

    virtual mmi_ret onProc(mmi_event_struct *evt)
    {
        switch(evt->evt_id)
        {
        case EVT_ID_CUI_VTST_STARTED:
            return VTST_CUI_ACK;
            
        case EVT_ID_CUI_VTST_FINISHED:

            VfxWString str, result;
            str.format("%s%s", VTST_CUI_FILE_PATH, VTST_CUI_FILENAME);
            result.format("%s", cui_cui1_get_result(m_cuiId));          
            VFX_ASSERT(str == result);
            
            cui_cui1_close(m_cuiId);
            displayResult(VFX_WSTR("CUI result:"), result);
            endPhase();
            break;
        }
        return MMI_RET_OK;
    }

    void displayResult(const VfxWString &title, const VfxWString &status)
    {
        VtstRtAppScr *scr;
        VFX_OBJ_CREATE(scr, VtstRtAppScr, this);
        scr->setTitle(title);
        scr->setStatus(status);
        scr->show();
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
            // create then close (w/o run)
            
            //VtstCuiLaunchStruct arg;
            //arg.testcase = this;

            mmi_id cuiId = cui_cui1_create(getGroupId(), NULL);
            check(VfxApp::getObject(cuiId), VFX_WSTR("Cui instance is ready after create"));
            cui_cui1_close(cuiId);
            return 10;
        }
        else if (idx == 1)
        {
            // create, set property, then run, close
            
            VtstCuiLaunchStruct arg;
            VtstCui *cui = NULL;
            VfxU32 flag = 0x26598088;

            // initial data for create arg
            arg.testcase    = this;
            arg.flag        = 1234;
            strncpy(arg.startPath, VTST_CUI_FILE_PATH, sizeof(arg.startPath));
                
            // create and run a CUI
            m_cuiId = cui_cui1_create(getGroupId(), &arg);

            // change property here
            cui_cui1_set_flag(m_cuiId, flag);
            cui = (VtstCui *)VfxApp::getObject(m_cuiId);
            check(cui->getFlag() == flag, VFX_WSTR("flag check"));

            // start CUI             
            cui_cui1_run(m_cuiId);

            return -1;  // wait for CUI result
        }
        else if (idx == 1)
        {
            return 1000;
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
    mmi_id m_cuiId;
};
VFX_IMPLEMENT_CLASS("RtCuiTest", VtstRtCuiTest, VtstRtApp);


static void vtst_rt_free_mem_cb(void *memPtr, void *userData)
{
    mmi_frm_asm_free_anonymous(memPtr);
}


VtstTestResultEnum vtst_rt_cui(VfxU32 param)
{
    VtstRtAppStartupParam startup;
    startup.memSize = APP1_HEAP_SIZE;
    startup.buffer  = (VfxU8 *)mmi_frm_asm_alloc_anonymous(startup.memSize);

    mmi_id app_id = VfxAppLauncher::launchWithMem( 
                            APP1_BASE, 
                            VFX_OBJ_CLASS_INFO(VtstRtCuiTest),
                            GRP_ID_ROOT,
                            (void *)startup.buffer, startup.memSize,
                            vtst_rt_free_mem_cb, NULL,
                            &startup,
                            sizeof(VtstRtAppStartupParam));

    VFX_UNUSED(app_id);
    VFX_UNUSED(param);
    return VTST_TR_OK;
}

static void app_stop_cb(void)
{
    if (app_mem_ptr)
    {
        applib_mem_ap_free(app_mem_ptr);
        app_mem_ptr = NULL;
        applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_CLIPBOARD, KAL_TRUE);
    }
}

// in this case, someone allocates app-ASM already
VtstTestResultEnum vtst_rt_manifest(VfxU32 param)
{
    VfxU32 maxPoolSize = applib_mem_ap_get_max_alloc_size();
    VfxU32 depCuiSize = APP1_POOL_SIZE - APP1_HEAP_SIZE;

    if(maxPoolSize > depCuiSize)
    {
        applib_mem_ap_register(APPLIB_MEM_AP_ID_CLIPBOARD, STR_GLOBAL_CLIPBOARD, 0, app_stop_cb);
        app_mem_ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_CLIPBOARD, maxPoolSize - depCuiSize + 1024);
    }
        
    vtst_rt_cui(param);

    VFX_UNUSED(param);
    return VTST_TR_OK;
}


#endif /* __AFX_RT_TEST__ */

