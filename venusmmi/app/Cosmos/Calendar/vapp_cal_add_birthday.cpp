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
 *  vapp_cal_add_birthday.CPP
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  implementation add birthday from phonebook
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 

/***************************************************************************** 
* Include
*****************************************************************************/


#include "mmi_features.h"

#ifdef __MMI_PHB_BIRTHDAY_FIELD__
#include "custom_mmi_default_value.h"
#include "globalresdef.h"

extern "C"
{
#include "todolistsrvgprot.h"
#include "vcalsrvgprot.h"
#include "app_datetime.h"
}

#include "mmi_rp_vapp_calendar_def.h"

#include "vapp_cal_add_birthday_gprot.h"
#include "vapp_nmgr_gprot.h"

#include "vfx_system.h"
#include "vfx_app.h"
#include "vfx_app_launcher.h"
#include "vfx_main_scr.h"

#include "vapp_cal_edit.h"


/***************************************************************************** 
 * Class VappCalAddBirthdayScreen
 *****************************************************************************/
class VappCalAddBirthdayScreen : public VfxMainScr
{

// Override
protected:
    void on1stReady();
};


/***************************************************************************** 
 * Class VappCalAddBirthdayApp
 *****************************************************************************/
class VappCalAddBirthdayApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappCalAddBirthdayApp);

public:
    vapp_cal_add_birthday_struct m_contact; 

//override 
protected:
    void onRun(void* args, VfxU32 argSize)
    {
        VfxApp::onRun(args, argSize);

        // create and display main screen
        VappCalAddBirthdayScreen *scr;
        VFX_OBJ_CREATE(scr, VappCalAddBirthdayScreen, this);

        memcpy(&(m_contact), args, sizeof(vapp_cal_add_birthday_struct));

        scr->show();
    }
};

VFX_IMPLEMENT_CLASS("VappCalAddBirthdayApp", VappCalAddBirthdayApp, VfxApp);


/***************************************************************************** 
 * Class VappCalAddBirthdayScreen
 *****************************************************************************/
void VappCalAddBirthdayScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    VappCalAddBirthdayApp *app = (VappCalAddBirthdayApp*)getApp();

    VappCalEditPage *page;
    VFX_OBJ_CREATE_EX(page, VappCalEditPage, this, (&(app->m_contact.date), app->m_contact.name));
    page->setBgColor(VFX_COLOR_WHITE);

    pushPage(0, page);
}


/***************************************************************************** 
 * Interface
 *****************************************************************************/
void vapp_cal_add_birthday_launch(vapp_cal_add_birthday_struct *contact)
{
    if (srv_tdl_is_full(SRV_TDL_VCAL_EVENT))
    {  

        vapp_nmgr_global_popup_show_confirm_one_button_id(
        MMI_SCENARIO_ID_DEFAULT,
        VCP_POPUP_TYPE_FAILURE,
        STR_ID_VAPP_CAL_MEM_FULL,
        STR_GLOBAL_OK,
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        NULL,
        NULL);

        return;
    }
    applib_time_struct minDate;
    memset((void *)&minDate,0,sizeof(applib_time_struct));
    minDate.nYear = 1970;
    minDate.nMonth = 1;
    minDate.nDay = 1;
    if(applib_dt_compare_time((applib_time_struct *)&minDate,
    (applib_time_struct *)&contact->date,
    (applib_time_struct *)NULL) == DT_TIME_GREATER )
    {
        vapp_nmgr_global_popup_show_confirm_one_button_id(
        MMI_SCENARIO_ID_DEFAULT,
        VCP_POPUP_TYPE_WARNING,
        STR_ID_VAPP_CAL_YEAE_BEYOND_MIN,
        STR_GLOBAL_OK,
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        NULL,
        NULL);

        return;
    }
    VfxAppLauncher::launch(
    VAPP_CALENDAR,
    VFX_OBJ_CLASS_INFO(VappCalAddBirthdayApp),
    GRP_ID_ROOT,
    contact, 
    sizeof(vapp_cal_add_birthday_struct));
}


void vapp_cal_add_birthday_close()
{
    VfxApp *app;

    /*----------------------------------------------------------------*/
    /* Code Body 													 */
    /*----------------------------------------------------------------*/
    app = VfxAppLauncher::findApp(
    VAPP_CALENDAR,
    VFX_OBJ_CLASS_INFO(VappCalAddBirthdayApp),
    VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG|VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);
    if(app)
    { 
        VfxAppLauncher::terminate(app->getGroupId());
    }


}
#endif
