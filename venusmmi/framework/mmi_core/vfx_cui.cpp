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
 *  vfx_cui.cpp
 *
 * Project:
 * --------
 *  Venus FW
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "vfx_cui.h"
// by RHR //#include "vadp_sys_trc.h"

extern "C"
{
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
}

#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_app.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_weak_ptr.h"
#include "vfx_signal.h"

#include "vfx_adp_sse.h"
#include "vfx_logger.h"

/***************************************************************************** 
 * Class VfxCui
 *****************************************************************************/

typedef struct {
    VfxCuiWeakPtr cui;
    VfxCuiPostToParentCb cb;
} PostToParentResultCbStruct;

VFX_IMPLEMENT_CLASS("Cui", VfxCui, VfxApp);

VfxCui::VfxCui()
{
}

VfxCui::~VfxCui()
{
}

mmi_ret VfxCui::sendToParent(mmi_group_event_struct *pEvt)
{
    VFX_LOG_FUNC1("%d", pEvt->evt_id);
    return mmi_frm_group_send_to_parent(m_groupId, pEvt);
}

void VfxCui::postToParent(mmi_group_event_struct *pEvt, VfxCuiPostToParentCb cb)
{
    VFX_LOG_FUNC1("%d", pEvt->evt_id);
    mmi_group_node_struct parentNode;

    if (mmi_frm_group_get_info(getParentId(), &parentNode) == MMI_RET_OK)
    {
        VfxCuiPostToParentCb *cbPtr;
        VFX_SYS_NEW_EX(cbPtr, VfxCuiPostToParentCb, (cb));
        MMI_FRM_POST_EVENT_EX(pEvt, parentNode.proc, parentNode.user_data, &VfxCui::static_postToParentResultCb, cbPtr);
    } 
}

mmi_id VfxCui::getParentId()
{
    return getParentGroupId();
}

void VfxCui::processGroupInactive(void)
{
    VfxApp::processGroupInactive();
    
    // Setup SSE for CUI
#ifndef	__MRE_SDK__    
    vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_CUI, VFX_FALSE, VFX_SCR_TRANSIT_PRIORITY_APP);
#endif
}

void VfxCui::static_postToParentResultCb(mmi_post_result_event_struct *evt)
{
    VfxCuiPostToParentCb *cbPtr = (VfxCuiPostToParentCb *)evt->user_data;
    if (cbPtr)
    {
        cbPtr->invoke((mmi_group_event_struct *)evt->evt_p, evt->result);
        VFX_DELETE(cbPtr);
    }
}



 
