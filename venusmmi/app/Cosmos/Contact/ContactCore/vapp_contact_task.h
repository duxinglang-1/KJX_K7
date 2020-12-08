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
 *  vapp_contact_task.h
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

#ifndef __CONTACT_TASK_H__
#define __CONTACT_TASK_H__

#include "vfx_uc_include.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "mmi_cb_mgr_gprot.h"

#ifdef __cplusplus
}
#endif


// contact task, current task
enum CONTACT_TASK
{
    CONTACT_NONE,
    CONTACT_START,
    CONTACT_SAVE,
    CONTACT_COPY,
    CONTACT_DELETE,
    CONTACT_COPY_ALL,
    CONTACT_DELETE_ALL,
    CONTACT_BACKUP,
    CONTACT_RESTORE,
    CONTACT_IMPORT,
    CONTACT_SYNC,
    CONTACT_DM_LOCK,
    CONTACT_DM_WIPE,
    CONTACT_TASK_TOTAL
};

// the state of Todo task
enum CONTACT_STATE
{
    CONTACT_WANT,
    CONTACT_FORBID,
    CONTACT_WAITING,
    CONTACT_RUN,
    CONTACT_FINISH,
    CONTACT_STATE_TOTAL
};

#define CONTACT_TASK_MAX    (10)        /* support 10 task together */

#define CONTACT_TASK_INIT() VFX_OBJ_GET_INSTANCE(ContactTask)

#define GET_CONTACT_TASK() VFX_OBJ_GET_INSTANCE(ContactTask)

/***************************************************************************** 
 * Class ContactTaskInterface
 *****************************************************************************/ 
class ContactTaskInterface
{
public:
    virtual CONTACT_STATE prepare(CONTACT_TASK task, CONTACT_STATE state) = 0;

    // do the operation
    virtual void run() = 0;

    // cancel the operation
    virtual void cancel() = 0;

    // finish the operation
    virtual void complete() = 0;

    // on state changed
    virtual CONTACT_STATE onStateChanged(CONTACT_STATE state) = 0;
};


/***************************************************************************** 
 * Class ContactTask
 *****************************************************************************/ 
class ContactTask: public VfxObject
{
    // singal instance
    VFX_OBJ_DECLARE_SINGLETON_CLASS(ContactTask);

public:
    class Task: public VfxBase
    {
    public:
        CONTACT_TASK m_task;
        CONTACT_STATE m_state;
        ContactTaskInterface *m_op;
    };

public:
    // default constructor
    ContactTask();

    // init
    void initTask();

    // task to do
    CONTACT_STATE task(CONTACT_TASK task, CONTACT_STATE state, ContactTaskInterface *op);

    // check task
    CONTACT_TASK checkTask();

    // check ready
    VfxBool checkReady();

protected:
    virtual void onInit();

    virtual void onDeinit();

private:
    // enqueue
    CONTACT_STATE in(CONTACT_TASK task, CONTACT_STATE state, ContactTaskInterface* op);

    // outqueue
    CONTACT_STATE out();

public:
    // singal to UI component
    VfxSignal2 <ContactTask*, mmi_event_struct*> m_signalTask;

private:
    Task m_taskStack[CONTACT_TASK_MAX];
    VfxU8 m_top;

    void regLisener();
    void deregLisener();

    static mmi_ret lisener(mmi_event_struct* param);
};

#endif /* __CONTACT_TASK_H__ */

