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
 *  vtst_rt_cache_mem.cpp
 *
 * Project:
 * --------
 *  Venus FW
 *
 * Description:
 * ------------
 *  Regression Test for cache memory
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
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

extern "C" {
#include "MMIDataType.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_res_range_def.h"
#include "CustDataRes.h"
}

#include "vtst_rt_main.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_string.h"
#include "vfx_sys_memory.h"
#include "vfx_app_launcher.h"

/***************************************************************************** 
 * VtstRtCacheMemTest
 *****************************************************************************/
class VtstRtCacheMemTest;

struct CacheCbStruct {
    VtstRtCacheMemTest *appPtr;
    VfxU32 idx;
};

class VtstRtCacheMemTest : public VtstRtApp
{
    VFX_DECLARE_CLASS(VtstRtCacheMemTest);
// Constructor / Destructor
public:
    VtstRtCacheMemTest() {}
    virtual ~VtstRtCacheMemTest() {}

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
        }
        return MMI_RET_OK;
    }

    static void static_freeCb(void *memPtr)
    {
        CacheCbStruct *pCbData = (CacheCbStruct *)memPtr;
        pCbData->appPtr->check(pCbData->appPtr->m_cachePtr[pCbData->idx] == memPtr, VFX_WSTR("cache cb check"));
        // release use of cache
        // callback don't have to free cache memory, it will be freed by framework
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
            void *cachePtr = NULL;
            VfxU32 asmMax = mmi_frm_asm_get_max_alloc_size_r(GRP_ID_INVALID);
            mmi_frm_asm_property_struct p;

            VfxU32 cacheSize = (asmMax >> 1) >> 1;
            for (VfxU32 i=0; i<2; i++)
            {
                VFX_ASSERT(sizeof(CacheCbStruct) < cacheSize);
                if (m_cachePtr[i] = mmi_frm_cache_alloc(cacheSize, static_freeCb, 0))
                {
                    ((CacheCbStruct *)m_cachePtr[i])->appPtr    = this;
                    ((CacheCbStruct *)m_cachePtr[i])->idx       = i;
                }
                VfxWString str;
                str.format("cache alloc %d", i+1);
                check(m_cachePtr[i], str);
            }

            mmi_id appId = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, NULL, NULL);
            mmi_frm_asm_get_property(appId, &p);
            p.f_skip_size_checking = 1;
            mmi_frm_asm_set_property(appId, &p);
            check(mmi_frm_asm_get_max_alloc_size_r(appId) < asmMax - 1024, VFX_WSTR("ASM occupied by cache"));
            void *asmPtr = mmi_frm_asm_alloc_r(appId, asmMax - 1024);

            check(asmPtr, VFX_WSTR("alloc asm -> free cache"));
            mmi_frm_asm_free_r(appId, asmPtr);
            mmi_frm_group_close(appId);

            return 10;
        }
        else
        {
            check(applib_mem_ap_cache_get_size() == 0, VFX_WSTR("cache all freed"));
            return VTST_RT_END_TESTCASE;;
        }
    }

    virtual void end()
    {
    }

// Variable
protected:
    void *m_cachePtr[2];
};
VFX_IMPLEMENT_CLASS("RtCacheMemTest", VtstRtCacheMemTest, VtstRtApp);


VtstTestResultEnum vtst_rt_cache_mem(VfxU32 param)
{
    VtstRtAppStartupParam startup;
    startup.memSize = APP1_HEAP_SIZE;
    startup.buffer  = NULL;

    mmi_id app_id = VfxAppLauncher::launchWithAsmSize( 
                            APP1_BASE, 
                            VFX_OBJ_CLASS_INFO(VtstRtCacheMemTest),
                            GRP_ID_ROOT,
                            startup.memSize,
                            &startup,
                            sizeof(VtstRtAppStartupParam));

    VFX_UNUSED(app_id);
    VFX_UNUSED(param);
    return VTST_TR_OK;
}

#endif /* __AFX_RT_TEST__ */

