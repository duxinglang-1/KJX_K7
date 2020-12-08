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
 * vapp_worldclock_cui.cpp
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
#include "vapp_worldclock_cui.h"
#include "vapp_worldclock.h"
#include "vapp_worldclock_select_city.h"
#include "vapp_worldclock_gprot.h"
//#include "mmi_rp_vapp_worldclock_def.h"
#include "mmi_rp_vapp_clock_def.h"
#include "GlobalResDef.h"
extern "C"
{

#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
#include "dcmgr.h" //DCM
#endif			
}
//VFX_IMPLEMENT_CLASS("VappWCCuiMainScr", VappWCCuiMainScr, VfxMainScr);
#pragma arm section code = "DYNAMIC_CODE_CLOCK_ROCODE", rodata = "DYNAMIC_CODE_CLOCK_RODATA"
VappWCCuiMainScr::VappWCCuiMainScr()
{
}

void VappWCCuiMainScr ::on1stReady()
{
    VfxMainScr::on1stReady();

	//mmi_wc_init();
	
    showSelectCityPage();
}

void VappWCCuiMainScr::onCmdPopCallback(VfxObject *obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        ((VappWCCui*)getParent())->onCitySelect(this, m_citySelect);
    }
}

void VappWCCuiMainScr ::showSelectCityPage()
{
    m_title = ((VappWCCui *)getParent())->getTitle();
    VappWCSelectCityPage *selectCity;
    VFX_OBJ_CREATE_EX(selectCity, VappWCSelectCityPage, this,(VFX_FALSE));
    selectCity->setTitleText(m_title);
    selectCity->m_signalCitySelected.connect(this, &VappWCCuiMainScr::onCitySelected);
    pushPage(0, selectCity);
}

void VappWCCuiMainScr::onCitySelected(VfxObject *sender, VfxU16 cityIndex)
{
    m_citySelect = cityIndex;
    VappWCDataControl data;
    cui_wc_launch_struct arg = ((VappWCCui *)getParent())->getArg();
    //confirm pop up when home city will change
    if (arg.isSetHomeCity && cityIndex != data.getHomeCityIndex())
    {
        VcpConfirmPopup *cfPopup;
        VFX_OBJ_CREATE(cfPopup, VcpConfirmPopup, this);
        cfPopup->setText(STR_ID_VAPP_WC_HOMECICY_CHANGE_POP);
        cfPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
        cfPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        cfPopup->setCustomButton(
                    STR_GLOBAL_CONTINUE,
                    STR_GLOBAL_CANCEL,
                    VCP_POPUP_BUTTON_TYPE_WARNING,
                    VCP_POPUP_BUTTON_TYPE_CANCEL
                    );
        cfPopup->m_signalButtonClicked.connect(this, &VappWCCuiMainScr::onCmdPopCallback);
        cfPopup->show(VFX_TRUE);
    }
    else
    {
        ((VappWCCui*)getParent())->onCitySelect(this, m_citySelect);
    }
}

VFX_IMPLEMENT_CLASS("VappWCCui", VappWCCui, VfxCui);

void VappWCCui::onRun(void * args, VfxU32 argSize)
{
    VfxCui::onRun(args, argSize);
    m_arg.isSetHomeCity = ((cui_wc_launch_struct *)args)->isSetHomeCity;
    VFX_ASSERT(sizeof(cui_wc_launch_struct) == argSize);
    VFX_OBJ_CREATE(m_mainScr, VappWCCuiMainScr, this);
    m_mainScr->show();
}
void VappWCCui::onDeinit()
{
		VfxCui::onDeinit();
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
		DCM_Unload(DYNAMIC_CODE_COMPRESS_CLOCK);
#endif				

}
void VappWCCui::onCitySelect(VfxObject *sender, VfxU16 cityIndex)
{
    VappWCDataControl data;
    if (m_arg.isSetHomeCity)
    {
        if (cityIndex != data.getHomeCityIndex())
        {
            VfxS8 dstFlag = 0 - data.getHomeCityDst();
            data.updateSysTime(cityIndex, dstFlag);
            data.saveHomeCityIdx(cityIndex);
            data.saveHomeCityDst(0);
        }
    }

    cui_wc_event_struct evt;
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_WC_CITY_SELECTED, m_groupId);
    evt.cityIndex = cityIndex;
    evt.cityName = data.getCityString(cityIndex);
    evt.timeZone = data.getTimeZone(cityIndex);
    if (cityIndex == data.getHomeCityIndex())
    {
        evt.dst = data.getHomeCityDst();
    }
    else if (cityIndex == data.getFrnCityIndex(0))
    {
        evt.dst = data.getFrnCityDst(0);
    }
    else if (cityIndex == data.getFrnCityIndex(1))
    {
        evt.dst = data.getFrnCityDst(1);
    }
    else
    {
        evt.dst = 0;
    }
    postToCaller((mmi_group_event_struct *)&evt);
}

#pragma arm section code, rodata
//cui creat function
MMI_ID vcui_wc_select_city_create(MMI_ID parent_id, cui_wc_launch_struct arg)
{
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
		DCM_Load(DYNAMIC_CODE_COMPRESS_CLOCK, 0, 0);
#endif	
    MMI_ID cui_id = VfxAppLauncher::createCui(
                                        VCUI_WORLDCLOCK,
                                        VFX_OBJ_CLASS_INFO(VappWCCui),
                                        parent_id,
                                        &arg,
                                        sizeof(cui_wc_launch_struct)
                                        );
    return cui_id;
}
#pragma arm section code = "DYNAMIC_CODE_CLOCK_ROCODE", rodata = "DYNAMIC_CODE_CLOCK_RODATA"
void vcui_wc_select_city_run(MMI_ID cui_id)
{
    VfxAppLauncher::runCui(cui_id);
}

void vcui_wc_select_city_set_title(MMI_ID cui_id, const VfxWString &text)
{
    VappWCCui *obj = (VappWCCui *)VfxApp::getObject(cui_id);
    obj->setTitle(text);
}

void vcui_wc_select_city_set_user_data(MMI_ID cui_id, void *user_data)
{
    VappWCCui *obj = (VappWCCui*) VfxApp::getObject(cui_id);
    obj->setUsrData(user_data);
}

void* vcui_wc_select_city_get_user_data(MMI_ID cui_id)
{
    VappWCCui *obj = (VappWCCui*) VfxApp::getObject(cui_id);
    return obj->getUsrData();
}

void vcui_wc_select_city_close(MMI_ID cui_id)
{
    VappWCCui *obj = (VappWCCui*) VfxApp::getObject(cui_id);
    VfxAppLauncher::terminate(cui_id);
}
#pragma arm section code, rodata
