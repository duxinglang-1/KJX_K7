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
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH???
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
 *  vapp_engineer_mode.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vcp_global_popup.h"
#include "vfx_app_launcher.h"
#include "vfx_main_scr.h"
#include "vfx_app.h"
#include "mmi_rp_app_cosmos_global_def.h"

#ifdef __MMI_ENGINEER_MODE__
#include "vapp_engineer_mode.h"
#include "mmi_rp_vapp_engineer_mode_def.h"
#include "mmi_rp_app_engineermode1_def.h"

/***************************************************************************** 
 * global value
 *****************************************************************************/
mmi_id g_vapp_em_item = NULL;
mmi_em_tone_cntx_struct g_vapp_em_cntx = {0};

/***************************************************************************** 
 * extern function
 *****************************************************************************/
extern "C" void vapp_engineer_mode_app_launch(mmi_id item_id, mmi_em_tone_cntx_struct user_data)
{
    g_vapp_em_item = item_id;
    g_vapp_em_cntx = user_data;

    VfxAppLauncher::launch(
        VAPP_ENGINEER_MODE,
        VFX_OBJ_CLASS_INFO(VappEngineerMode),
        GRP_ID_ROOT);
}

/***************************************************************************** 
 * Class define
 *****************************************************************************/


/*****************************************************************************
 * Class VappProvMsg
 *****************************************************************************/
VfxSignal1<void *> VappEngineerMode::m_eventCallback;

VFX_IMPLEMENT_CLASS("VappEngineerMode", VappEngineerMode, VfxApp);

void VappEngineerMode::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    /* create and display main screen */
    VappEngineerModeScr *scr;
    VFX_OBJ_CREATE(scr, VappEngineerModeScr, this);
    scr->show();
}

mmi_ret VappEngineerMode::onProc(mmi_event_struct *param)
{
    VappEngineerMode::m_eventCallback.emit((void*)param);
    return MMI_RET_OK;
}

/*****************************************************************************
 * Class VappProvMsg end
 *****************************************************************************/

/*****************************************************************************
 * Class VappEngineerModeScr
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappEngineerModeScr", VappEngineerModeScr, VfxMainScr);

void VappEngineerModeScr::on1stReady()
{
    VfxMainScr::on1stReady();

    // create and display first page
    switchPage(g_vapp_em_item);       
}

void VappEngineerModeScr::switchPage(VfxU16 item)
{
    switch(item)
    {
    #ifdef __MMI_EM_NW_EVENT_NOTIFY__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

        case 1:
            break;

        default:
            break;
    }
}
/*****************************************************************************
 * Class VappEngineerModeScr
 *****************************************************************************/

#endif /* __MMI_ENGINEER_MODE__ */
