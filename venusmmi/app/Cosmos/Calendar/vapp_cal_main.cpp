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
 *  vapp_cal_main.cpp
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h" 

#include "GlobalResDef.h"
#include "mmi_rp_vapp_calendar_def.h"

#ifdef __SYNCML_SUPPORT__   
#include "vapp_sync_gprot.h"
#endif
#ifdef SUPPORT_JSR_75_PIM
#include "vapp_cal_java_entry.h"
#endif

#include "vfx_app_launcher.h"

#include "vapp_cal_main.h"
#include "vapp_cal_main_view.h"
#include "vapp_cal_view_detail_ext.h"
#include "vapp_cal_reminder.h"
#include "vapp_cal_at_entry.h"

extern "C"
{
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__) 
#include "dcmgr.h" // DCM
#endif
}


extern "C"
{
    void vapp_calendar_init(void)
    {
#ifdef __MMI_VCALENDAR__
        vapp_vcal_view_detail_register_message();

#ifdef SUPPORT_JSR_75_PIM
        vapp_cal_java_data_handler_init();
#endif

        vapp_cal_at_data_handler_init();
#endif
    }

    mmi_id vapp_calendar_launch(void* args, U32 argSize)
    {
#ifdef __SYNCML_SUPPORT__   	
        if (vapp_sync_is_cal_synchronizing(1))
        {
            return GRP_ID_INVALID;
        }    
#endif

#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
        DCM_Load(DYNAMIC_CODE_COMPRESS_CLNDR, 0, 0);
#endif

        vapp_cal_launch_struct context;
        context.type = VAPP_CAL_LAUNCH_BY_CAL;

        mmi_id grpId = VfxAppLauncher::launch(
                                VAPP_CALENDAR,
                                VFX_OBJ_CLASS_INFO(VappCalendarApp),
                                GRP_ID_ROOT,
                                &context,
                                sizeof(vapp_cal_launch_struct));

        return grpId;
    }

#ifdef __MMI_VUI_WIDGET_CALENDAR__
    void vapp_calendar_launch_by_widget(applib_time_struct *currDt)
    {
#ifdef __SYNCML_SUPPORT__   	
        if (vapp_sync_is_cal_synchronizing(1))
        {
            return;
        }    
#endif

#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
        DCM_Load(DYNAMIC_CODE_COMPRESS_CLNDR, 0, 0);
#endif
        vapp_cal_launch_struct context; 

        context.dateTime = *currDt;
        context.type = VAPP_CAL_LAUNCH_BY_WIDGET;

        VfxAppLauncher::launch( 
                        VAPP_CALENDAR,
                        VFX_OBJ_CLASS_INFO(VappCalendarApp),
                        GRP_ID_ROOT,
                        &context,
                        sizeof(vapp_cal_launch_struct));
    }
#endif  /*__MMI_VUI_WIDGET_CALENDAR__*/

}

void VappCalendarApp::onDeinit()
{
	VFX_TRACE(("\n[VappCalendarApp::onDeinit()]\n"));

    VfxApp::onDeinit();

#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
    DCM_Unload(DYNAMIC_CODE_COMPRESS_CLNDR);
#endif
}
#ifndef __MMI_VCALENDAR__
#pragma arm section code = "DYNAMIC_CODE_CLNDR_ROCODE", rodata = "DYNAMIC_CODE_CLNDR_RODATA"
#endif
/***************************************************************************** 
 * Class  VappCalMainScr implement
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappCalMainScr", VappCalMainScr, VfxMainScr);
void VappCalMainScr::on1stReady()
{
    VfxMainScr::on1stReady();

	VfxDateTime currDateTime;
	currDateTime.setCurrentTime();

	
	VFX_OBJ_CREATE_EX(m_mainViewPage, VappCalMainViewPage, this, (currDateTime));
    pushPage(0, m_mainViewPage);
	
}


void VappCalMainScr::on2ndReady()
{
  m_mainViewPage->creatpage();
 

}



/***************************************************************************** 
 * Class  VappCalendarApp implement
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappCalendarApp", VappCalendarApp, VfxApp);
void VappCalendarApp::onRun(void * args, VfxU32 argSize)
{
	VfxApp::onRun(args, argSize);

	vapp_cal_launch_struct *context = (vapp_cal_launch_struct*)args; 

	m_ctx.type = context->type;
	m_ctx.dateTime = context->dateTime;
	
	VappCalMainScr *screen;
	VFX_OBJ_CREATE(screen, VappCalMainScr, this);
	screen->show();
}
#ifndef __MMI_VCALENDAR__
#pragma arm section code, rodata
#endif

