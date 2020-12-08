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
 *  vtst_rt_timer.cpp
 *
 * Project:
 * --------
 *  Venus Regression Test for timer
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

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

extern "C" {
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "AlertScreen.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "mmi_res_range_def.h"
#include "CustDataRes.h"
#include "kal_public_api.h"
}

#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_string.h"
#include "vfx_app_launcher.h"   
#include "vtst_rt_main.h"

/***************************************************************************** 
 * Test bed for app 
 *****************************************************************************/
class VtstRtAppLaunchTest;
class VtstRtAppBasicTest;

typedef struct {
    VtstRtAppBasicTest *rtApp;
    VfxU32 ackNumber;
} AppLaunchTestStruct;


class VtstRtAppLaunchTest : public VfxApp
{
    VFX_DECLARE_CLASS(VtstRtAppLaunchTest);

public:
    VtstRtAppLaunchTest() {};
    virtual ~VtstRtAppLaunchTest() {};

    virtual void onRun(void* args, VfxU32 argSize);
};
VFX_IMPLEMENT_CLASS("VtstRtAppLaunchTest", VtstRtAppLaunchTest, VfxApp);


class VtstRtAppScrTest : public VtstRtAppScr
{
    VFX_DECLARE_CLASS(VtstRtAppScrTest);
    
// Constructor / Destructor
public:
    // Default constructor
    VtstRtAppScrTest()
    {
    }

// Override
protected:
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);
};

VFX_IMPLEMENT_CLASS("RtAppScrTest", VtstRtAppScrTest, VtstRtAppScr);


class VtstRtAppBasicTest : public VtstRtApp
{
    VFX_DECLARE_CLASS(VtstRtAppBasicTest);

    friend class VtstRtAppScrTest;

// Constructor / Destructor
public:
    // Default constructor
    VtstRtAppBasicTest() : 
        m_scrnID1(0), m_scrnID2(0), m_scrnID3(0), m_scrnID4(0), m_scrnID5(0), 
        m_pScr7(NULL)
    {
    }

    void launchAck(VfxU32 ackNumber)
    {
        m_launchAckNumber = ackNumber;
    }

// Override
protected:
    virtual void onRun(void* args, VfxU32 argSize)
    {
        VFX_TRACE(("APP: %d %X\n", int(getGroupId()), this));

        VtstRtApp::onRun(args, argSize);
        
        vtst_testcase_start(this, VFX_FALSE);        
    }

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
            // launch by context
            VfxU32 poolSize = 300*1024;
            void *memPool = mmi_frm_asm_alloc_anonymous(poolSize);
            check(memPool, VFX_WSTR("mem pool is ready"));
            if (memPool)
            {
                const VfxU32 testCount = 3;
                VfxContext *ctx;
                AppLaunchTestStruct arg;
                VfxU32 i;
                mmi_id appId[testCount] = {0};
                
                VFX_OBJ_CREATE(ctx, VfxContext, VFX_SYS_GLOBAL_CONTEXT);
                ctx->assignPool((VfxU8 *)memPool, poolSize);

                arg.rtApp = this;
                for (i=0; i<testCount; i++)
                {
                    VfxU32 ackNumber;
                    VfxWString str;
                    
                    ackNumber = arg.ackNumber = getRand(10000);
                    appId[i] = VfxAppLauncher::launchWithCtx(
                                                    APP2_BASE, 
                                                    VFX_OBJ_CLASS_INFO(VtstRtAppLaunchTest), 
                                                    getGroupId(),
                                                    ctx,
                                                    &arg,
                                                    sizeof(arg));
                    str.format("%d launch check", i);
                    check(m_launchAckNumber == ackNumber, str); // app is launched
                    check(ctx == VfxApp::getObject(appId[i])->getParent(), VFX_WSTR("same parent for launchByCtx"));
                }

                // free app and context
                for (i=0; i<testCount; i++)
                {
                    VfxAppLauncher::terminate(appId[i]);
                }
                VFX_OBJ_CLOSE(ctx);
            }
        }
        else if (idx == 1)
        {
            // create 1st screen

            VtstRtAppScr *pAppScr;
            VFX_OBJ_CREATE(pAppScr, VtstRtAppScr, this);
            pAppScr->setTitle(VFX_WSTR("Screen 1"));
            pAppScr->setSerializable(VFX_TRUE);
            m_scrnID1 = pAppScr->show();
        }
        else if (idx == 2)
        {
            // create 2nd screen and check relation w/ 1st screen

            VtstRtAppScr *pAppScr;
            VFX_OBJ_CREATE(pAppScr, VtstRtAppScr, this);
            pAppScr->setTitle(VFX_WSTR("Screen 2"));
            m_scrnID2 = pAppScr->show();

            check(getTopScreenId() == m_scrnID2, VFX_WSTR("Top screen"));
            check(getBottomScreenId() == m_scrnID1, VFX_WSTR("Bottom screen"));
        }
        else if (idx == 3)
        {
            // close 2nd screen

            closeScreen(m_scrnID2);
            check(getScreen(m_scrnID2) == NULL, VFX_WSTR("Close Top Screen"));
        }
        else if (idx == 4)
        {
            // close 1st screen

            closeScreen(m_scrnID1);
            check(getScreen(m_scrnID1) == NULL, VFX_WSTR("Goback and close screen"));
        }
        else if (idx == 5)
        {
            // create 3 screen at a same time
            VtstRtAppScr *pAppScr;
            VFX_OBJ_CREATE(pAppScr, VtstRtAppScr, this);
            pAppScr->setTitle(VFX_WSTR("Screen 3"));
            m_scrnID3 = pAppScr->show();

            VFX_OBJ_CREATE(pAppScr, VtstRtAppScr, this);
            pAppScr->setTitle(VFX_WSTR("Screen 4"));
            pAppScr->setSerializable(VFX_FALSE);
            m_scrnID4 = pAppScr->show();

            VFX_OBJ_CREATE(pAppScr, VtstRtAppScr, this);
            pAppScr->setTitle(VFX_WSTR("Screen 5"));
            m_scrnID5 = pAppScr->show();

            return 100; // wait a while to see the result on the screen
        }
        else if (idx == 6)
        {
            closeScreen(m_scrnID3); // the screen is in history
            check(getScreen(m_scrnID3) == NULL, VFX_WSTR("Screen is in history"));

            closeScreen(m_scrnID5); // the screen is active screen
            check(getScreen(m_scrnID5) == NULL, VFX_WSTR("Screen is active screen"));

            closeScreen(m_scrnID4); // the screen is back from history
            check(getScreen(m_scrnID4) == NULL, VFX_WSTR("Screen is back from history"));
        }
        else if (idx == 7)
        {
            VFX_OBJ_CREATE(m_pScr7, VtstRtAppScr, this);
            m_pScr7->setTitle(VFX_WSTR("Screen 7"));
            m_pScr7->show();
            m_scrnID7 = m_pScr7->getScreenId();
        }
        else if (idx == 8)
        {
            VFX_OBJ_CLOSE(m_pScr7);
            check(getScreen(m_scrnID7) == NULL, VFX_WSTR("Close screen pointer"));
        }
        else if (idx == 9)
        {
            VtstRtAppScr *pAppScr;
            mmi_popup_property_struct arg;
            VFX_OBJ_CREATE(pAppScr, VtstRtAppScr, this);
            pAppScr->setTitle(VFX_WSTR("Screen 8"));
            pAppScr->setSerializable(VFX_FALSE);
            m_scrnID8 = pAppScr->show();
            
            mmi_popup_property_init(&arg);
            arg.duration = 100;
            mmi_popup_display((WCHAR*)get_string(STR_GLOBAL_OK), MMI_EVENT_INFO, &arg);
            check(getScreen(m_scrnID8) != NULL, VFX_WSTR("UnSerializable"));
        }
        else if (idx == 10)
        {
            closeScreen(m_scrnID8);
        }
        else if (idx == 11)
        {
            // Close with show
            VtstRtAppScr *pAppScr;
            VFX_OBJ_CREATE(pAppScr, VtstRtAppScr, this);

            pAppScr->setTitle(VFX_WSTR("Open and close right away"));
            pAppScr->show();
            
            VFX_OBJ_CLOSE(pAppScr);

            // Close without show
            VFX_OBJ_CREATE(pAppScr, VtstRtAppScr, this);

            pAppScr->setTitle(VFX_WSTR("Open and close right away"));
            VFX_OBJ_CLOSE(pAppScr);
        }
        else if (idx == 12)
        {
            VtstRtAppScrTest *pAppScr1;
            VFX_OBJ_CREATE(pAppScr1, VtstRtAppScrTest, this);

            pAppScr1->setTitle(VFX_WSTR("Create 1st scr"));
            m_scrnID1 = pAppScr1->show();
            return 500;
        }
        else if (idx == 13)
        {
            VtstRtAppScr *pAppScr2;
            VFX_OBJ_CREATE(pAppScr2, VtstRtAppScr, this);

            pAppScr2->setTitle(VFX_WSTR("Create 2nd scr"));
            m_scrnID2 = pAppScr2->show();
            return 500;
        }
        else if (idx == 14)
        {
            // close 2nd scr and will back to 1st scr, then create scr during goback history
            closeScreen(m_scrnID2);
            return 500;
        }
        else if (idx == 15)
        {
            VFX_OBJ_CLOSE(m_pScr7);
            //closeScreen(m_scrnID3);
            closeScreen(m_scrnID1);
        }
        else
        {
            return VTST_RT_END_TESTCASE;
        }
        return 30;
    }

    virtual void end()
    {
    }

    VfxU32 getRand(VfxU32 normalizeTo)
    {
        VfxU32 tick;
        kal_get_time(&tick);
        srand(tick);
        return rand() % normalizeTo;
    }

// Variable
protected:
    mmi_id m_scrnID1, m_scrnID2, m_scrnID3, m_scrnID4, m_scrnID5, m_scrnID7, m_scrnID8;
    VtstRtAppScr *m_pScr7;
    VfxU32 m_launchAckNumber;
};

VFX_IMPLEMENT_CLASS("RtAppBasicTest", VtstRtAppBasicTest, VtstRtApp);


void VtstRtAppScrTest::onEnter(VfxBool isBackward)
{
    VtstRtAppScr::onEnter(isBackward);
    
    VtstRtAppBasicTest *pApp = (VtstRtAppBasicTest *)getParent();
    VFX_OBJ_CREATE(pApp->m_pScr7, VtstRtAppScr, pApp);

    VFX_TRACE(("==> %d.onActived show scr (isBackward=%d)\n", getGroupId(), isBackward));
    if (isBackward)
    {
        pApp->m_pScr7->setTitle(VFX_WSTR("show new scr during back history"));
        pApp->m_scrnID3 = pApp->m_pScr7->show();
        pApp->check(pApp->m_scrnID3 != 0, VFX_WSTR("goback/entry scr should exist"));
    }
    else
    {
        pApp->m_pScr7->setTitle(VFX_WSTR("show another new scr while entry"));
        pApp->m_scrnID3 = pApp->m_pScr7->show();
        VFX_OBJ_CLOSE(pApp->m_pScr7);
        pApp->check(pApp->m_scrnID3 != 0, VFX_WSTR("entry/entry scr should exist"));
        pApp->m_scrnID3 = 0;
        pApp->m_pScr7 = NULL;
    }
}


void VtstRtAppScrTest::onExit(VfxBool isBackward)
{
    VtstRtAppScr::onExit(isBackward);    
}


void VtstRtAppLaunchTest::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);
    
    VFX_ASSERT(sizeof(AppLaunchTestStruct) == argSize);
    AppLaunchTestStruct *launchArg = (AppLaunchTestStruct *)args;
    launchArg->rtApp->launchAck(launchArg->ackNumber);
}


static void vtst_rt_free_mem_cb(void *memPtr, void *userData)
{
    mmi_frm_asm_free_anonymous(memPtr);
}


VtstTestResultEnum vtst_rt_appscreen(VfxU32 param)
{
    VtstRtAppStartupParam startup;
    startup.memSize = 300*1024;
    startup.buffer  = (VfxU8 *)mmi_frm_asm_alloc_anonymous(startup.memSize);

    mmi_id app_id = VfxAppLauncher::launchWithMem( 
                            APP1_BASE, 
                            VFX_OBJ_CLASS_INFO(VtstRtAppBasicTest),
                            GRP_ID_ROOT,
                            (void *)startup.buffer,startup.memSize,
                            vtst_rt_free_mem_cb, NULL,
                            &startup,
                            sizeof(VtstRtAppStartupParam));

    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

