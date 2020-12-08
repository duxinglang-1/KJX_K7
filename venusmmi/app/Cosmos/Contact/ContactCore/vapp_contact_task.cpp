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
 *  vapp_contact_task.cpp
 *
 * Project:
 * --------
 *  Venus
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#include "vapp_contact_task.h"

#ifdef __DM_LAWMO_SUPPORT__
#include "vapp_phb_app.h"
extern srv_dm_lawmo_wipe_report_cb_func_type g_dm_lawmo_wipe_report_cb;
#endif /* __DM_LAWMO_SUPPORT__ */
#include "mmi_rp_app_usbsrv_def.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __DM_LAWMO_SUPPORT__
#include "DmSrvGprot.h"
#endif

#include "PhbSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "FileMgrSrvGprot.h"

#ifdef __cplusplus
}
#endif

const VfxU8 g_phb_task_priority[CONTACT_TASK_TOTAL] =
{
    0xff,       //CONTACT_NONE,
    1,          //CONTACT_START,
    10,         //CONTACT_SAVE,
    10,         //CONTACT_COPY,
    10,         //CONTACT_DELETE,
    10,         //CONTACT_COPY_ALL,
    10,         //CONTACT_DELETE_ALL,
    10,         //CONTACT_BACKUP,
    10,         //CONTACT_RESTORE,
    10,         //CONTACT_IMPORT,
    10,         //CONTACT_SYNC,
    3,          //CONTACT_DM_LOCK
    2           //CONTACT_DM_WIPE
};


/***************************************************************************** 
 * Class ContactTask
 *****************************************************************************/ 
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(ContactTask);

ContactTask::ContactTask()
{
    initTask();
}


void ContactTask::regLisener()
{
    mmi_frm_cb_reg_event(EVT_ID_PHB_READY, ContactTask::lisener, NULL);
    mmi_frm_cb_reg_event(EVT_ID_PHB_ADD_CONTACT, ContactTask::lisener, NULL);
    mmi_frm_cb_reg_event(EVT_ID_PHB_DEL_CONTACT, ContactTask::lisener, NULL);
    mmi_frm_cb_reg_event(EVT_ID_PHB_UPD_CONTACT, ContactTask::lisener, NULL);
    mmi_frm_cb_reg_event(EVT_ID_PHB_STORAGE_CHANGE, ContactTask::lisener, NULL);
#ifdef __MMI_PHB_LAST_NAME_FIELD__
    mmi_frm_cb_reg_event(EVT_ID_PHB_NAME_SEQUENCE_CHANGE, ContactTask::lisener, NULL);
#endif
#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
    mmi_frm_cb_reg_event(EVT_ID_PHB_FIELD_TYPE_CHNAGED_IND, ContactTask::lisener, NULL);
#endif
	mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &ContactTask::lisener, NULL); 
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &ContactTask::lisener, NULL);
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, &ContactTask::lisener, NULL);
    mmi_frm_cb_reg_event(EVT_ID_USB_EXIT_MS_MODE, &ContactTask::lisener, NULL);/* EVT_ID_USB_ENTER/EXIT_MS_MODE */
#endif
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__ /* also can for test phbsrv ready */
    mmi_frm_cb_reg_event(EVT_ID_PHB_TCARD_READY, &ContactTask::lisener, NULL);
#endif /*  __MMI_PHB_TCARD_STORAGE_SUPPORT__ */
}


void ContactTask::deregLisener()
{
    mmi_frm_cb_dereg_event(EVT_ID_PHB_READY, ContactTask::lisener, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_PHB_ADD_CONTACT, ContactTask::lisener, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_PHB_DEL_CONTACT, ContactTask::lisener, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_PHB_UPD_CONTACT, ContactTask::lisener, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_PHB_STORAGE_CHANGE, ContactTask::lisener, NULL);
#ifdef __MMI_PHB_LAST_NAME_FIELD__
    mmi_frm_cb_dereg_event(EVT_ID_PHB_NAME_SEQUENCE_CHANGE, ContactTask::lisener, NULL);
#endif
#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
    mmi_frm_cb_dereg_event(EVT_ID_PHB_FIELD_TYPE_CHNAGED_IND, ContactTask::lisener, NULL);
#endif
	mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &ContactTask::lisener, NULL); 
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &ContactTask::lisener, NULL);
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, &ContactTask::lisener, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_USB_EXIT_MS_MODE, &ContactTask::lisener, NULL);    /* EVT_ID_USB_ENTER/EXIT_MS_MODE */
#endif
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__ /* also can for test phbsrv ready */
    mmi_frm_cb_dereg_event(EVT_ID_PHB_TCARD_READY, &ContactTask::lisener, NULL);
#endif /*  __MMI_PHB_TCARD_STORAGE_SUPPORT__ */
}


mmi_ret ContactTask::lisener(mmi_event_struct* evt)
{
    ContactTask* task = GET_CONTACT_TASK();

    switch (evt->evt_id)
    {
        case EVT_ID_PHB_READY:
        {
            srv_phb_startup_evt_struct *ready = (srv_phb_startup_evt_struct*) evt;

            if (ready->phb_ready)
            {
                task->task(CONTACT_START, CONTACT_FINISH, NULL);
            #ifdef __DM_LAWMO_SUPPORT__ // for wipe cmd is coming, but phb is not ready.
                if (g_dm_lawmo_wipe_report_cb)
                {
                    vapp_phb_dm_wipe_do_format();
                }
            #endif /* __DM_LAWMO_SUPPORT__ */  
            }
            else
            {
                task->task(CONTACT_START, CONTACT_WANT, NULL);
            }

            task->m_signalTask.emit(task, evt);
            break;
        }
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
    #ifdef __MMI_USB_SUPPORT__
        case EVT_ID_USB_ENTER_MS_MODE:
        case EVT_ID_USB_EXIT_MS_MODE:
    #endif
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        case EVT_ID_PHB_TCARD_READY:
    #endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */
        default:
        {
            task->m_signalTask.emit(task, evt);
            break;
        }
    }

    return MMI_RET_OK;
}


void ContactTask::onInit()
{
    VfxObject::onInit();

    regLisener();

    if (!srv_phb_startup_is_phb_ready())
    {
        task(CONTACT_START, CONTACT_WANT, NULL);
    }
}


void ContactTask::onDeinit()
{
    deregLisener();

    VfxObject::onDeinit();
}


void ContactTask::initTask()
{
    m_top = 0;
}


CONTACT_STATE ContactTask::in(CONTACT_TASK task, CONTACT_STATE inState, ContactTaskInterface *op)
{
    VFX_ASSERT(m_top < CONTACT_TASK_MAX);
    
    CONTACT_STATE state = CONTACT_FORBID;

    // compare the current task
    if (m_top > 0)
    {
        // new task high priority
        if (g_phb_task_priority[m_taskStack[m_top - 1].m_task] > g_phb_task_priority[task])
        {
            state = CONTACT_RUN;
            // change current task state
            CONTACT_STATE opState = CONTACT_FINISH;
            if (m_taskStack[m_top - 1].m_op)
            {
                opState = m_taskStack[m_top - 1].m_op->onStateChanged(CONTACT_WAITING);
            }

            // change to waiting
            if (opState == CONTACT_WAITING)
            {
                // do nothing, since it's positon is right
            }
            // finish
            else
            {
                VFX_ASSERT(opState == CONTACT_FINISH);
                //m_top--;
            }
        }
        // new task low priority
        else
        {
            if (op)
            {
                state = op->onStateChanged(CONTACT_FORBID);
                VFX_ASSERT(state != CONTACT_RUN);
            }
        }
    }
    else
    {
        state = CONTACT_RUN;
    }

    // add new task
    if (state == CONTACT_RUN)
    {
        m_taskStack[m_top].m_task = task;
        m_taskStack[m_top].m_state = state;
        m_taskStack[m_top++].m_op = op;
    }
    // insert the new task to stack
    else if (state == CONTACT_WAITING)
    {
        // find the proper position for new task
    }

    return state;
}


CONTACT_STATE ContactTask::out()
{
    VFX_ASSERT(m_top > 0);
    m_top--;

    return CONTACT_FINISH;
}


CONTACT_STATE ContactTask::task(CONTACT_TASK task, CONTACT_STATE state, ContactTaskInterface *op)
{
    CONTACT_STATE resultState = CONTACT_FORBID;

    if (state == CONTACT_WANT)
    {
        resultState = in(task, state, op);
    }
    else if (state == CONTACT_FINISH)
    {
        if (m_top > 0 && task == m_taskStack[m_top - 1].m_task)
        {
            resultState = out();
        }
    }

    return resultState;
}


CONTACT_TASK ContactTask::checkTask()
{
    if (m_top > 0)
    {
        // return the processing task
        return m_taskStack[m_top - 1].m_task;
    }
    else
    {
        return CONTACT_NONE;
    }
}


VfxBool ContactTask::checkReady()
{
    if (checkTask() != CONTACT_START)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

