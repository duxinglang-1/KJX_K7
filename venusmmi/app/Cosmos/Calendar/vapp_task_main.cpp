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
 *  vapp_task_main.cpp
 *
 * Project:
 * --------
 *  Cosmos
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h" 
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "mmi_rp_vapp_task_def.h"
#include "vapp_task_main.h"
#include "vapp_task_all_list.h"

#include "GlobalResDef.h"

#ifdef __SYNCML_SUPPORT__   
#include "vapp_sync_gprot.h"
#endif

extern "C"
{
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__) 
#include "dcmgr.h" // DCM
#endif
}





extern "C" mmi_id vapp_task_launch(void* args, U32 argSize)
{
#ifdef __SYNCML_SUPPORT__   	
    if (vapp_sync_is_task_synchronizing(1))
    {
        return GRP_ID_INVALID;
    }    
#endif
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
            DCM_Load(DYNAMIC_CODE_COMPRESS_CLNDR, 0, 0);
#endif


    mmi_id grpId = VfxAppLauncher::launch(
        VAPP_TASK,
        VFX_OBJ_CLASS_INFO(VappTaskApp),
        GRP_ID_ROOT);

    return grpId;
}


VFX_IMPLEMENT_CLASS("VappTaskApp", VappTaskApp, VfxApp);
void VappTaskApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VfxMainScrEx *screen;
    VFX_OBJ_CREATE_EX(screen, VfxMainScrEx, this, (this));
    screen->show();
}

void VappTaskApp::onScr1stReady(VfxMainScrEx *scr)
{
    VfxDateTime currDateTime;
    currDateTime.setCurrentTime();

    VappTaskAllListPage *listPage;
    VFX_OBJ_CREATE_EX(listPage, VappTaskAllListPage, scr, (VAPP_TASK_ALL_ENTRY_TASK));
    scr->pushPage(0, listPage);
}
void VappTaskApp::onDeinit()
{
	VFX_TRACE(("\n[VappTaskApp::onDeinit()]\n"));

    VfxApp::onDeinit();

#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
    DCM_Unload(DYNAMIC_CODE_COMPRESS_CLNDR);
#endif
}

