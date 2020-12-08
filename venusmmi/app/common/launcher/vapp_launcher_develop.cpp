/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_launcher_develop.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements some development functions for MoDIS. For example, get
 *  screenshots of all application icons on the MoDIS.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

/*****************************************************************************
 * Include
 *****************************************************************************/

extern "C"
{
#include "gui.h"
#include "gui_effect_oem.h"
#include "gdi_include.h"
#include "wgui_categories_util.h"
#include "CustVenusThemeRes.h"
}

#include "vfx_string.h"
#include "vapp_wallpaper_setting_method_gprot.h"
#include "vapp_launcher_develop.h"
#include "vapp_launcher_gprot.h"


/*****************************************************************************
 * Function
 *****************************************************************************/

#if defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__) && !defined(__MTK_TARGET__)
//
// Index of the current ACO file.
//
static S32 g_vappLauncherDevAppIconIndex;


static void vapp_launcher_dev_get_next_app_icon_screenshot(void)
{
    static mmi_res_theme_handle appIconHandle = 0;

    VfxWString filename;

    if (appIconHandle > 0)
    {
        // Save current app icon from blt layer 0.
        gdi_handle layers[4];
        gdi_layer_get_blt_layer(&layers[0], &layers[1], &layers[2], &layers[3]);

        filename.format("D:\\Theme_%02d.bmp", g_vappLauncherDevAppIconIndex - 1);
        gdi_layer_save_bmp_file(layers[0], (PS8)filename.getBuf());

        // Close previous app icon first.
        mmi_res_close_priority_theme(appIconHandle);
    }

    //
    // Activate next app icon.
    //
    filename.format("D:\\AppIcon\\Theme_%02d.aco", g_vappLauncherDevAppIconIndex++);

    mmi_res_theme_ret_enum ret = mmi_res_set_dlt_priority_theme(
                                    filename.getBuf(),
                                    MMI_RES_THEME_PRIORITY_MEDIUM,
                                    &appIconHandle);

    if (ret != MMI_RES_THEME_RET_INVALID)
    {
        VappWallpaperSettingInterface *iface;

        iface= VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
        iface->restoreWallpaperEx(VAPP_WALLPAPER_HOME_SCREEN, VFX_FALSE);

        vapp_launcher_restart();
    #if defined(__MMI_SCREEN_SWITCH_EFFECT__)
        gui_screen_switch_effect_block(MMI_TRUE);
    #endif
        gui_start_timer(1, vapp_launcher_dev_get_next_app_icon_screenshot);
    }
}
#endif /* defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__) && !defined(__MTK_TARGET__) */


void vapp_launcher_dev_get_app_icon_screenshot(void)
{
#if defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__) && !defined(__MTK_TARGET__)
    //
    // Set signal & battery status icon.
    //
    wgui_status_icon_bar_change_icon_level(STATUS_ICON_SIGNAL_STRENGTH, 100);
#if (MMI_MAX_SIM_NUM >= 2)
    wgui_status_icon_bar_change_icon_level(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, 100);
#endif

    wgui_status_icon_bar_change_icon_level(STATUS_ICON_BATTERY_STRENGTH, 100);

    //
    // Search folder and change app icon.
    //
    g_vappLauncherDevAppIconIndex = 1;
    vapp_launcher_dev_get_next_app_icon_screenshot();
#endif /* defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__) && !defined(__MTK_TARGET__) */
}

