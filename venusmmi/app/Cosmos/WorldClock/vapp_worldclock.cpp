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
 * vapp_worldclock.cpp
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements world clock application.
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
 *****************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#include "MMIDatatype.h"
#include "GlobalResDef.h"

#include "mmi_rp_vapp_setting_def.h"

#include "vapp_worldclock_gprot.h"
#include "vapp_worldclock.h"

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif
extern "C"
{
#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif
}


MMI_ID vapp_world_clock_launch(void* param, U32 param_size)
{
    MMI_ID worldclock_id;
    worldclock_id = VfxAppLauncher::launch(
                        VAPP_WORLDCLOCK,
                        VFX_OBJ_CLASS_INFO(VappWorldClock),
                        GRP_ID_ROOT
                        );
    return worldclock_id;
}
  
VFX_IMPLEMENT_CLASS("VappWorldClock", VappWorldClock, VfxApp);
 
void VappWorldClock::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);
    /*create and display main screen*/

    VappWorldClockMainScr *mainScr;
    VFX_OBJ_CREATE(mainScr, VappWorldClockMainScr, this);
    mainScr->show();
}

VFX_IMPLEMENT_CLASS("VappWorldClockMainScr", VappWorldClockMainScr, VfxMainScr);
 
void VappWorldClockMainScr::on1stReady()
{
    VfxMainScr::on1stReady();  

	//mmi_wc_init();
	
    /*create and display map page*/
#ifdef __LOW_COST_SUPPORT_COMMON__
    VFX_OBJ_CREATE(m_mapPage, VappWCListViewPage, this);
    pushPage(0, m_mapPage);
#else
    VFX_OBJ_CREATE(m_mapPage, VappWCMapPage, this);
    pushPage(0, m_mapPage);
#endif


}

void VappWorldClockMainScr::on2ndReady()
{
	
#ifndef __LOW_COST_SUPPORT_COMMON__
	if(m_mapPage)
	{
		m_mapPage->map2ndReady();
	}
#endif

}


extern "C"
mmi_ret vapp_worldclock_evt_handlr(mmi_event_struct *evt)
{
	if (evt->evt_id == EVT_ID_VAPP_LANGUAGE_CHANGED)
	{
	
#ifdef __MAUI_SOFTWARE_LA__
	SLA_CustomLogging("win", SA_start);
#endif

	mmi_wc_init();	

#ifdef __MAUI_SOFTWARE_LA__
	SLA_CustomLogging("win", SA_stop);
#endif		
	}

	return MMI_RET_OK;
}


