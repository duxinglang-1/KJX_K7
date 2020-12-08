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
 *  vapp_safe_mode.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the safe mode.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_SAFE_MODE__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vcp_global_popup.h"
#include "vfx_adp_device.h"
#include "vapp_safe_mode.h"
#include "mmi_rp_vapp_safe_mode_def.h"

extern "C"
{
#include "wgui_categories_util.h"
#include "SafeModeSrvGprot.h"
#include "BootupSrvGprot.h"
#include "ShutdownSrvGprot.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "app_datetime.h"
#include "ProfilesSrvGprot.h"
#include "GeneralSettingSrvGprot.h" // for EVT_ID_SETTING_LANGUAGE_CHANGED
}


/*****************************************************************************
 * Global Variable
 *****************************************************************************/

static VappSafeModeStruct g_vappSafeMode = {0};


/*****************************************************************************
 * Prototype
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vapp_safe_mode_handle_bootup_early_init
 * DESCRIPTION
 *  This function handles the "bootup-early-init" event.
 * PARAMETERS
 *  event           : [IN]  Event
 * RETURNS
 *  mmi_ret.
 *****************************************************************************/
static mmi_ret vapp_safe_mode_handle_bootup_early_init(
    mmi_event_struct *event);


/*****************************************************************************
 * FUNCTION
 *  vapp_safe_mode_handle_pre_key_routing
 * DESCRIPTION
 *  This function handles the "pre-key-routing" event.
 * PARAMETERS
 *  event           : [IN]  Event
 * RETURNS
 *  mmi_ret.
 *****************************************************************************/
static mmi_ret vapp_safe_mode_handle_pre_key_routing(
    mmi_event_struct *event);


/*****************************************************************************
 * FUNCTION
 *  vapp_safe_mode_handle_language_changed
 * DESCRIPTION
 *  This function handles the "language-changed" event.
 * PARAMETERS
 *  event           : [IN]  Event
 * RETURNS
 *  mmi_ret.
 *****************************************************************************/
static mmi_ret vapp_safe_mode_handle_language_changed(
    mmi_event_struct *event);


/*****************************************************************************
 * FUNCTION
 *  vapp_safe_mode_get_last_time
 * DESCRIPTION
 *  This function gets the last time that the abnormal reset happens.
 * PARAMETERS
 *  time           : [OUT]      Time
 * RETURNS
 *  If it is present, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static VfxBool vapp_safe_mode_get_last_time(
    VfxU32 &time);


/*****************************************************************************
 * FUNCTION
 *  vapp_safe_mode_set_time
 * DESCRIPTION
 *  This function sets the time that the abnormal reset happens.
 * PARAMETERS
 *  time           : [IN]       Time
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_safe_mode_set_time(
    VfxU32 time);


/*****************************************************************************
 * FUNCTION
 *  vapp_safe_mode_activate
 * DESCRIPTION
 *  This function activates the safe mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_safe_mode_activate();


/*****************************************************************************
 * Function
 *****************************************************************************/

mmi_ret vapp_safe_mode_handle_bootup_early_init(mmi_event_struct *event)
{
#if defined(CFG_VAPP_SAFE_MODE_UNIT_TEST)
    vapp_safe_mode_activate();
#else
    //
    // Auto activation of the safe mode:
    //
    // The mobile abnormally resets twices in a short time.
    //

    if (srv_bootup_is_exception_mode())
    {
        // Get the last time that the abnormal reset happens.
        VfxU32 lastTime = 0;
        VfxBool ret = vapp_safe_mode_get_last_time(lastTime);

        // Update the time that the abnromal reset happens.
        VfxU32 currTime = app_getcurrtime();
        vapp_safe_mode_set_time(currTime);

        // Check if criteria is matched to activate safe mode.
        if (ret && currTime < lastTime + VAPP_SAFE_MODE_AUTO_CRITERIA)
        {
            vapp_safe_mode_activate();
        }
    }
#endif /* defined(CFG_VAPP_SAFE_MODE_UNIT_TEST) */

    return MMI_RET_OK;
}


mmi_ret vapp_safe_mode_handle_pre_key_routing(mmi_event_struct *event)
{
    //
    // Manual activation of the safe mode:
    //
    // The user presses the "Power" key and then the "End" key in a short time.
    //

    // If bootup is completed or safe mode is already active, do nothing.
    if (srv_bootup_is_completed() || srv_safe_mode_is_active())
    {
        return MMI_RET_OK;
    }

    mmi_frm_key_evt_struct *evt = (mmi_frm_key_evt_struct *)event;

    if (!g_vappSafeMode.isKeyPressed)
    {
        // Wait until the first power key down event.
        if (evt->key_code != KEY_POWER || evt->key_type != KEY_EVENT_DOWN)
        {
            return MMI_RET_OK;
        }

        g_vappSafeMode.isKeyPressed = VFX_TRUE;
        g_vappSafeMode.keyTime = app_getcurrtime();
    }
    else
    {
        // Power key has been pressed down. Wait until the next key down event.
        if (evt->key_type != KEY_EVENT_DOWN)
        {
            return MMI_RET_OK;
        }

        VfxU32 criteria = g_vappSafeMode.keyTime + VAPP_SAFE_MODE_MANUAL_CRITERIA;

        if (evt->key_code == KEY_END && app_getcurrtime() <= criteria)
        {
            // Play a tone if the user activates it manually.
            srv_prof_play_tone(SRV_PROF_TONE_WARNING, NULL);

            // Activate the safe mode.
            vapp_safe_mode_activate();
        }

        g_vappSafeMode.isKeyPressed = VFX_FALSE;
    }

    return MMI_RET_OK;
}


mmi_ret vapp_safe_mode_handle_language_changed(mmi_event_struct *event)
{
    if (srv_safe_mode_is_active())
    {
        wgui_status_icon_bar_show_warning_info(
            (UI_string_type)vfxSysResGetStr(STR_ID_VAPP_SAFE_MODE_EXIT));
    }

    return MMI_RET_OK;
}


mmi_ret vapp_safe_mode_main_evt_hdlr(mmi_event_struct *event)
{
    mmi_ret ret;

    VFX_ASSERT(event);

    switch (event->evt_id)
    {
        case EVT_ID_SRV_BOOTUP_EARLY_INIT:
            ret = vapp_safe_mode_handle_bootup_early_init(event);
            break;

        case EVT_ID_PRE_KEY_EVT_ROUTING:
            ret = vapp_safe_mode_handle_pre_key_routing(event);
            break;

        case EVT_ID_SETTING_LANGUAGE_CHANGED:
            ret = vapp_safe_mode_handle_language_changed(event);

        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}


VfxBool vapp_safe_mode_get_last_time(VfxU32 &time)
{
    //
    // Check if the last time is available.
    //
    U8 flag;
    S16 err;

    ReadValue(NVRAM_VAPP_SAFE_MODE_FLAG, &flag, DS_BYTE, &err);
    VFX_ASSERT(err == NVRAM_READ_SUCCESS);

    if (!flag)
    {
        return VFX_FALSE;
    }

    //
    // Get the last time.
    //
    VfxU64 tempValue;

    ReadValue(NVRAM_VAPP_SAFE_MODE_TIME, &tempValue, DS_DOUBLE, &err);
    VFX_ASSERT(err == NVRAM_READ_SUCCESS);

    time = (VfxU32)tempValue;

    return VFX_TRUE;
}


void vapp_safe_mode_set_time(VfxU32 time)
{
    //
    // Set flag.
    //
    U8 flag = 0x01;
    S16 err;

    WriteValue(NVRAM_VAPP_SAFE_MODE_FLAG, &flag, DS_BYTE, &err);
    VFX_ASSERT(err == NVRAM_WRITE_SUCCESS);

    //
    // Set the time.
    //
    VfxU64 tempValue = time;

    WriteValue(NVRAM_VAPP_SAFE_MODE_TIME, &tempValue, DS_DOUBLE, &err);
    VFX_ASSERT(err == NVRAM_WRITE_SUCCESS);
}


void vapp_safe_mode_activate()
{
    // Vibrate the phone.
    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN);

    // Set text on the status icon bar.
    wgui_status_icon_bar_show_warning_info(
        (UI_string_type)vfxSysResGetStr(STR_ID_VAPP_SAFE_MODE_EXIT));

    // Activate the service.
    srv_safe_mode_activate();
}

#endif /* defined(__MMI_SAFE_MODE__) */
