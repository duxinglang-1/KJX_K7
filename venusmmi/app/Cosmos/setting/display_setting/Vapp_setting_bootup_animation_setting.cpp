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
 *  vapp_setting_bootup_animation_setting.cpp
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
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
 
#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__ 
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "mmi_rp_vapp_setting_def.h"

#include "vapp_wallpaper_setting_method_gprot.h"
#include "vapp_setting_wallpaper_setting_gprot.h"
#include "vapp_setting_wallpaper_setting.h"
#include "vapp_live_wallpaper_content_provider.h"

#include "vcui_gallery_gprot.h"
#include "vapp_wallpaper_cfg.h"
#include "vapp_setting_framework_gprot.h"

#include "vcui_wallpaper_setting_gprot.h"
#include "Vapp_usb_gprot.h"
extern "C"
{
#include "PhoneSetupResList.h"
#include "mmi_rp_file_type_def.h"
#include "Mmi_rp_app_usbsrv_def.h"
#ifdef __MMI_USB_SUPPORT__
#include "UsbSrvGprot.h"
#endif
}


/***************************************************************************** 
 * Class 
 *****************************************************************************/
/***************************************************************************** 
 * VappPowerOnAnimationSettingCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappPowerOnAnimationSettingCell", VappPowerOnAnimationSettingCell, VcpFormItemLauncherCell);
VappPowerOnAnimationSettingCell::VappPowerOnAnimationSettingCell()
{
}


void VappPowerOnAnimationSettingCell::onInit()
{
    VcpFormItemLauncherCell::onInit();
    setMainText(VFX_WSTR_RES(STR_ID_VAPP_SETTING_PWR_ON_VIDEO));
    setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_signalTap.connect(this, &VappPowerOnAnimationSettingCell::onTap);

}

void VappPowerOnAnimationSettingCell::onTap(VcpFormItemCell* sender, VfxId senderId)
{
    VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);

    if (mainScr != NULL)
    {
        // Entry a new page 
        VappSettingSystemVideoPage *pwrOnPage;
        VFX_OBJ_CREATE_EX(pwrOnPage, VappSettingSystemVideoPage, mainScr,(VAPP_VIDEO_PWR_ON_SCREEN));
        mainScr->pushPage('PWON', pwrOnPage); 
    }


}

/***************************************************************************** 
 * VappPowerOffAnimationSettingCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappPowerOffAnimationSettingCell", VappPowerOffAnimationSettingCell, VcpFormItemLauncherCell);

VappPowerOffAnimationSettingCell::VappPowerOffAnimationSettingCell()
{
}

void VappPowerOffAnimationSettingCell::onInit()
{
    VcpFormItemLauncherCell::onInit();
    setMainText(VFX_WSTR_RES(STR_ID_VAPP_SETTING_PWR_OFF_VIDEO));
    setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_signalTap.connect(this, &VappPowerOffAnimationSettingCell::onTap);

}

void VappPowerOffAnimationSettingCell::onTap(VcpFormItemCell* sender, VfxId senderId)
{
    VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);

    if (mainScr != NULL)
    {
        // Entry a new page 
        VappSettingSystemVideoPage *pwrOffPage;
        VFX_OBJ_CREATE_EX(pwrOffPage, VappSettingSystemVideoPage, mainScr,(VAPP_VIDEO_PWR_OFF_SCREEN));
        mainScr->pushPage('PWOF', pwrOffPage); 
    }
}
#endif
