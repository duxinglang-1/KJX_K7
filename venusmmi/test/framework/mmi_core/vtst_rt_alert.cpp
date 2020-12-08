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
 *  vtst_rt_popup.cpp
 *
 * Project:
 * --------
 *  Pluto FW
 *
 * Description:
 * ------------
 *  Venus Regression Test for Popup
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vtst_rt_main.h"

extern "C" {
#include "MMIDataType.h"
#include "CommonScreensResDef.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "stack_config.h"
#include "mmi_res_range_def.h"
} /* extern "C" { */

#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vrt_datatype.h"
#include "vfx_string.h"
#include "vfx_sys_memory.h"
#include "vfx_app_launcher.h"

extern "C"
{
#include "AlertScreen.h"
#ifndef __MTK_TARGET__
extern void mmi_frm_dbg_dump_shell(void);
#endif
} /* extern "C" */

extern void print_event(PU8 str_prefix, mmi_event_struct *evt);

/***************************************************************************** 
 * VtstRtAlertTest
 *****************************************************************************/

class VtstRtAlertTest : public VtstRtApp
{
    VFX_DECLARE_CLASS(VtstRtAlertTest);
// Constructor / Destructor
public:
    VtstRtAlertTest() : m_endOfTest(VFX_FALSE), m_confirmCount(0), m_isConfirmCbInvoked(VFX_FALSE), 
                        m_isPopupCbInvoked(VFX_FALSE), m_isParentProcInvoked(VFX_FALSE), m_alertResult(MMI_ALERT_END)
    {
    }
    virtual ~VtstRtAlertTest() {}

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize)
    {
        VtstRtApp::onRun(args, argSize);
        
        vtst_testcase_start(this, VFX_FALSE);       
    }

// static

    static mmi_ret popupCb(mmi_alert_result_evt_struct *evt)
    {
        print_event((PU8)"popupCb", (mmi_event_struct *)evt);

        if (evt->evt_id == EVT_ID_ALERT_QUIT)
        {
            VtstRtAlertTest *obj = (VtstRtAlertTest *)evt->user_tag;

            VFX_ASSERT(obj->isKindOf(VFX_OBJ_CLASS_INFO(VtstRtAlertTest)));

            obj->m_alertResult = evt->result;
            obj->m_isPopupCbInvoked = VFX_TRUE;
        }
        return MMI_RET_OK;
    }

    static mmi_ret confirmCb(mmi_alert_result_evt_struct *evt)
    {
        print_event((PU8)"confirmCb", (mmi_event_struct *)evt);

        if (evt->evt_id == EVT_ID_ALERT_QUIT)
        {
            VtstRtAlertTest *obj = (VtstRtAlertTest *)evt->user_tag;
            VFX_ASSERT(obj->isKindOf(VFX_OBJ_CLASS_INFO(VtstRtAlertTest)));
            
            switch (evt->result)
            {
            case MMI_ALERT_CNFM_1:
            case MMI_ALERT_CNFM_2:
            case MMI_ALERT_CNFM_3:

                obj->m_isConfirmCbInvoked = VFX_TRUE;
            
            case MMI_ALERT_CNFM_OK:
            case MMI_ALERT_CNFM_YES:
            case MMI_ALERT_CNFM_NO:            
            case MMI_ALERT_CNFM_CANCEL:
                
                obj->confirmDecrease();            
                break;           
            }
        }        
        return MMI_RET_OK;
    }

    static mmi_ret confirmCb_doDismissAndEndPhase(mmi_alert_result_evt_struct *evt)
    {
        print_event((PU8)"confirmCb_doDismissAndEndPhase", (mmi_event_struct *)evt);

        if (evt->evt_id == EVT_ID_ALERT_QUIT)
        {
            if (evt->result == MMI_ALERT_CNFM_OK)
            {
                VtstRtAlertTest *obj = (VtstRtAlertTest *)evt->user_tag;
                VFX_ASSERT(obj->isKindOf(VFX_OBJ_CLASS_INFO(VtstRtAlertTest)));

                obj->endPhase();
            }
        }        
        return MMI_RET_OK;
    }

    static mmi_ret confirmCb_autoDismissDisabled(mmi_alert_result_evt_struct *evt)
    {
        print_event((PU8)"confirmCb_autoDismissDisabled", (mmi_event_struct *)evt);

        if (evt->evt_id == EVT_ID_ALERT_QUIT)
        {
            if (evt->result == MMI_ALERT_CNFM_OK)
            {
                mmi_confirm_property_struct arg;
                mmi_confirm_property_init(&arg, CNFM_TYPE_OK);
                arg.callback    = (mmi_proc_func)confirmCb_doDismissAndEndPhase;
                arg.user_tag    = evt->user_tag;
                mmi_confirm_display((WCHAR *)L"confirm again", MMI_EVENT_INFO, &arg);
            }
        }
        return MMI_RET_OK;
    }

    static mmi_ret confirmCb_showAnotherScr(mmi_alert_result_evt_struct *evt)
    {
        if (evt->evt_id == EVT_ID_ALERT_QUIT)
        {
            switch(evt->result)
            {
            case MMI_ALERT_CNFM_YES:
            case MMI_ALERT_CNFM_NO:
                mmi_group_node_struct node;
                mmi_frm_group_get_info(evt->alert_id, &node);

                mmi_confirm_property_struct arg;
                mmi_confirm_property_init(&arg, CNFM_TYPE_CANCEL);
                arg.parent_id   = node.parent;
                arg.callback    = (mmi_proc_func)VtstRtAlertTest::confirmCb;
                arg.user_tag    = (void *)evt->user_tag;
                arg.f_enter_history  = MMI_TRUE;
                mmi_confirm_display((WCHAR *)L"showAnotherScr: waiting", MMI_EVENT_PROGRESS, &arg);
                break;
            }
        }
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

    virtual void onGroupActive()
    {
        if (m_endOfTest && (m_confirmCount == 0))
            endPhase();
    }

    virtual mmi_ret proc(mmi_event_struct *evt)
    {  
        switch (evt->evt_id)
        {
        case EVT_ID_ALERT_QUIT:
            {
                mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)evt;

                switch (alert->result)
                {
                case MMI_ALERT_NORMAL_EXIT:
                    check(alert->user_tag == (void *)'InGA', VFX_WSTR("ParentProc user_tag"));
                    m_isParentProcInvoked = VFX_TRUE;
                    break;

                // for any confirm softkey presses
                case MMI_ALERT_CNFM_YES:
                case MMI_ALERT_CNFM_NO:
                case MMI_ALERT_CNFM_OK:
                case MMI_ALERT_CNFM_CANCEL:

                    confirmDecrease();
                    break;
                }
            }
            break;
        }
        return MMI_RET_OK;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        VfxS32 ret = 2500;
        
        if (idx == 0)
        {
            mmi_confirm_property_struct arg;
            
            mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
            arg.parent_id   = getGroupId();
            arg.user_tag    = (void *)'End';
            arg.f_sliding_effect = MMI_FALSE;
            arg.f_enter_history  = MMI_TRUE;
            mmi_confirm_display((WCHAR *)L"in-group confirm", MMI_EVENT_QUERY, &arg);
            confirmIncrease();
            ret = 2500;
        }      
        else if (idx == 1)
        {
            mmi_confirm_property_struct arg;
            
            mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE);
            arg.parent_id   = getGroupId();
            arg.user_tag    = (void *)'WAIT';
            arg.f_enter_history  = MMI_TRUE;
            m_confirmId = mmi_confirm_display((WCHAR *)L"in-group waiting", MMI_EVENT_PROGRESS, &arg);
            confirmIncrease();
            ret = 5000;           
        }
        else if (idx == 2)
        {
            // waiting complete, dismiss popup
            // since any softkey handler is not registered, we have use this to close popup
            mmi_alert_dismiss(m_confirmId);
            confirmDecrease();
            ret = 1000;
        }
        else if (idx == 3)
        {
            mmi_confirm_property_struct arg;
            
            mmi_confirm_property_init(&arg, CNFM_TYPE_CANCEL);
            arg.parent_id   = getGroupId();
            arg.user_tag    = (void *)'WAIT';
            arg.f_enter_history  = MMI_TRUE;
            m_confirmId = mmi_confirm_display((WCHAR *)L"in-group waiting w/ cancel", MMI_EVENT_PROGRESS, &arg);
            confirmIncrease();
            ret = 5000;
        }
        else if (idx == 4)
        {
            // waiting complete, dismiss popup
            if (mmi_alert_dismiss(m_confirmId))
            {
                // reduce count only when confirm exists
                m_confirmCount--;
            }
            ret = 1000;
        }
        // disable auto-dismiss flag
        else if (idx == 5)
        {
            mmi_confirm_property_struct arg;
            mmi_confirm_property_init(&arg, CNFM_TYPE_OK);
            arg.callback        = (mmi_proc_func)VtstRtAlertTest::confirmCb_autoDismissDisabled;
            arg.user_tag        = this;
            arg.f_auto_dismiss  = MMI_FALSE;
            arg.f_enter_history  = MMI_TRUE;
            m_confirmId = mmi_confirm_display((WCHAR *)L"global confirm - dismiss by ap", MMI_EVENT_QUERY, &arg);
            ret = -1;
        }
        else if (idx == 6)
        {
            // alert should be still there, no auto-dismiss after quit event
            check(mmi_frm_group_is_present(m_confirmId) == MMI_TRUE, VFX_WSTR("disable auto-dismiss"));
            mmi_alert_dismiss(m_confirmId);
            ret = 10;
        }
        else if (idx == 7)
        {
            mmi_popup_property_struct arg;
            
            mmi_popup_property_init(&arg);
            arg.callback = (mmi_proc_func)VtstRtAlertTest::popupCb;
            arg.user_tag = this;
            m_isPopupCbInvoked = VFX_FALSE;
            mmi_popup_display((WCHAR *)L"global popup", MMI_EVENT_FAILURE, &arg);
            ret = 2500;
        }
        else if (idx == 8)
        {
            // popup callback should be invoked
            check(m_isPopupCbInvoked, VFX_WSTR("PopupCb invoke/userTag"));
            check(m_alertResult == MMI_ALERT_NORMAL_EXIT, VFX_WSTR("Popup Normal Exit"));
            ret = 10;
        }       
        else if (idx == 9)
        {
            mmi_popup_property_struct arg;
            
            mmi_popup_property_init(&arg);
            arg.parent_id = getGroupId();
            arg.user_tag = (void *)'InGA';
            m_isParentProcInvoked = VFX_FALSE;
            mmi_popup_display((WCHAR *)L"in-group popup", MMI_EVENT_WARNING, &arg);
            ret = 2500;
        }
        else if (idx == 10)
        {
            // no callback set, so parent proc should be invoked
            check(m_isParentProcInvoked, VFX_WSTR("ParentProc invoke"));
            return 10;
        }
        else if (idx == 11)
        {
            mmi_confirm_property_struct arg;
            
            mmi_confirm_property_init(&arg, CNFM_TYPE_OK);
            arg.callback = (mmi_proc_func)VtstRtAlertTest::confirmCb;
            arg.user_tag = this;
            arg.f_sliding_effect = MMI_FALSE;
            arg.f_enter_history  = MMI_TRUE;
            mmi_confirm_display((WCHAR *)L"global confirm - no sliding", MMI_EVENT_FAILURE, &arg);
            confirmIncrease();
            ret = 10;
        }
        else if (idx == 12)
        {
            // in-group popup will not show for inactive group
            mmi_popup_property_struct arg;
            MMI_ID popup_id;
            
            mmi_popup_property_init(&arg);
            arg.parent_id   = getGroupId();
            arg.user_tag    = (void *)'InGA';  // TODO: check NO_SHOW event
            popup_id = mmi_popup_display((WCHAR *)L"inactive-group popup", MMI_EVENT_WARNING, &arg);
            check(popup_id == GRP_ID_INVALID, VFX_WSTR("InactiveGroup Popup"));
            ret = 3000;
        }
        else if (idx == 13)
        {
            // confirm that does not goes into history
            mmi_confirm_property_struct arg;
            
            mmi_confirm_property_init(&arg, CNFM_TYPE_OK);
            arg.callback        = (mmi_proc_func)VtstRtAlertTest::confirmCb;
            arg.user_tag        = this;
            arg.f_enter_history = MMI_FALSE;
            mmi_confirm_display((WCHAR *)L"global confirm - no history", MMI_EVENT_INFO, &arg);
            ret = 3000;
        }
        else if (idx == 14)
        {
            mmi_confirm_property_struct arg;
            
            MMI_ID grp_id = mmi_frm_group_create(getGroupId(), GRP_ID_AUTO_GEN, NULL, NULL);
            mmi_frm_group_enter(grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
            
            mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
            arg.parent_id   = grp_id;
            arg.callback    = (mmi_proc_func)VtstRtAlertTest::confirmCb_showAnotherScr;
            arg.user_tag    = this;
            arg.f_enter_history  = MMI_TRUE;
            mmi_confirm_display((WCHAR *)L"confirm to show", MMI_EVENT_QUERY, &arg);
            confirmIncrease();
            ret = 2500;
        }
        else if (idx == 15)
        {
            mmi_confirm_property_struct arg;
            
            mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE);
            arg.callback = (mmi_proc_func)VtstRtAlertTest::confirmCb;
            arg.user_tag = this;
            arg.f_enter_history  = MMI_TRUE;
            arg.softkey[0].str = (WCHAR *)L"Delete";
            arg.softkey[1].str = (WCHAR *)L"Read";
            arg.softkey[2].str = (WCHAR *)L"Cancel";
            VtstRtAlertTest::m_isConfirmCbInvoked = VFX_FALSE;
            mmi_confirm_display((WCHAR *)L"global confirm - UserDefine", MMI_EVENT_QUERY, &arg);
            confirmIncrease();
            m_endOfTest = VFX_TRUE; /* add to last phase before return */
            ret = -1;
        }
        // app calls cui, cui fail to run, popup error on parent group, post parent to close when popup quit
        else
        {
            check(VtstRtAlertTest::m_isConfirmCbInvoked, VFX_WSTR("confirmCb"));
            ret = VTST_RT_END_TESTCASE;
        }
        
    #ifndef __MTK_TARGET__
        // debug
        //postInvoke((mmi_proc_func)mmi_frm_dbg_dump_shell, NULL);
    #endif
        return ret;
    }

    virtual void end()
    {
    }

    void confirmIncrease() {m_confirmCount++;}
    void confirmDecrease()
    {
        if (m_confirmCount > 0)
            m_confirmCount--;
        
        if (m_endOfTest && (m_confirmCount == 0))
        {
            endPhase();
        }
    }

// Variable
    mmi_alert_result_enum   m_alertResult;
    VfxBool m_isPopupCbInvoked;
    VfxBool m_isParentProcInvoked; 
    VfxBool m_isConfirmCbInvoked;
    MMI_ID m_confirmId;
    VfxBool m_endOfTest;
    VfxS32 m_confirmCount;
};

VFX_IMPLEMENT_CLASS("RtAlertTest", VtstRtAlertTest, VtstRtApp);


static void vtst_rt_free_mem_cb(void *memPtr, void *userData)
{
    mmi_frm_asm_free_anonymous(memPtr);
}


VtstTestResultEnum vtst_rt_alert(VfxU32 param)
{
    VtstRtAppStartupParam startup;
    startup.memSize = 256 * 1024;
    startup.buffer  = (VfxU8 *)mmi_frm_asm_alloc_anonymous(startup.memSize);

    mmi_id app_id = VfxAppLauncher::launchWithMem( 
                            APP1_BASE, 
                            VFX_OBJ_CLASS_INFO(VtstRtAlertTest),
                            GRP_ID_ROOT,
                            (void *)startup.buffer,startup.memSize,
                            vtst_rt_free_mem_cb, NULL,
                            &startup,
                            sizeof(VtstRtAppStartupParam));

    VFX_UNUSED(app_id);
    VFX_UNUSED(param);
    return VTST_TR_OK;
}


#endif /* __AFX_RT_TEST__ */

