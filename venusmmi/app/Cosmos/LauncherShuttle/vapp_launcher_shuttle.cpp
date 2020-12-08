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
 *  vapp_launcher_shuttle.cpp
 *
 * Project:
 * --------
 *  Cosmos Launcher 2.0
 *
 * Description:
 * ------------
 *  Launcher Shuttle
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


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "Vapp_setting_launcher_scr_lock_gprot.h"
#include "vapp_launcher_setting_provider.h"
#include "vapp_launcher_kit.h"
#include "vapp_launcher_gprot.h"
#include "vapp_platform_context.h"


/*****************************************************************************
 * Global Function
 *****************************************************************************/

extern "C" MMI_ID vapp_launcher_shuttle_launch(void *param, U32 param_size)
{
    //
    // Get the default launcher.
    //
    VappLauncherSettingProvider *provider;

    provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);

    VappLauncherId id = provider->getDefaultLauncher();

    //
    // set next launcher
    //
    VappLauncherKit *kit;

    kit = VFX_OBJ_GET_INSTANCE(VappLauncherKit);
    VfxS32 totalNum = kit->getTotalNum();

    VappLauncherId **fullList = VappLauncherId::newArray(totalNum,  VFX_OBJ_GET_INSTANCE(VappPlatformContext));

    kit->getAllId(fullList, totalNum);

    VfxS32 nextIndex = -1; 
    for(VfxS32 i=0; i<totalNum; i++)
    {
        if(fullList[i]->compareWith(id))
        {
            nextIndex = i+1;
            nextIndex %= totalNum;
            break;
        }
    }
    VFX_ASSERT(nextIndex != -1);
    
    id.assignWith(*(fullList[nextIndex]));

    provider->setDefaultLauncher(id);

    VappLauncherId::deleteArray(fullList, totalNum);

    return vapp_launcher_reload();
}
