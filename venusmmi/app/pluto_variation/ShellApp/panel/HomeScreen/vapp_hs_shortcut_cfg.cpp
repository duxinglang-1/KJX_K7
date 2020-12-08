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
 *  vapp_hs_shortcut_cfg.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file configures the shortcuts on the Venus home screen.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vapp_hs_shortcut_cfg.h"
#include "vadp_v2p_hs.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "mmi_rp_app_venus_homescreen_def.h"
#include "AMGprot.h"
#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VAPP_HS_NEW_SHORTCUT(_a, _b, _c)    {_a, _b, _c}


/***************************************************************************** 
 * Shortcut Configuration Table
 *****************************************************************************/

const VappHsShortcutCfg g_vapp_hs_shortcut_tbl[] = 
{
    VAPP_HS_NEW_SHORTCUT(
        VAPP_HS_IMG_SC_SETTING,
        VAPP_HS_SHORTCUT_OPTION_IN_BAR,
        NULL),
        
    VAPP_HS_NEW_SHORTCUT(
        VAPP_HS_IMG_SC_MAIN_MENU, 
        VAPP_HS_SHORTCUT_OPTION_NULL,
        vadp_v2p_hs_launch_main_menu),
        
    VAPP_HS_NEW_SHORTCUT(
        VAPP_HS_IMG_SC_DIALER, 
        VAPP_HS_SHORTCUT_OPTION_NULL,
        vadp_v2p_hs_launch_dialer),

#ifdef BROWSER_SUPPORT
    VAPP_HS_NEW_SHORTCUT(
        VAPP_HS_IMG_SC_BROWSER,
        VAPP_HS_SHORTCUT_OPTION_NULL,
        vadp_v2p_hs_launch_broswer),
#endif /* BROWSER_SUPPORT */

#ifdef __MMI_FILE_MANAGER__
    VAPP_HS_NEW_SHORTCUT(
        VAPP_HS_IMG_SC_FILE_MANAGER,
        VAPP_HS_SHORTCUT_OPTION_NULL,
        vadp_v2p_hs_launch_file_manager),
#endif /* __MMI_FILE_MANAGER__ */

    VAPP_HS_NEW_SHORTCUT(
        VAPP_HS_IMG_SC_PHONE_SETTING, 
        VAPP_HS_SHORTCUT_OPTION_NULL,
        vadp_v2p_hs_launch_phone_settting),

    VAPP_HS_NEW_SHORTCUT(
        VAPP_HS_IMG_SC_PROFILES, 
        VAPP_HS_SHORTCUT_OPTION_NULL,
        vadp_v2p_hs_launch_profiles),

    VAPP_HS_NEW_SHORTCUT(
        VAPP_HS_IMG_SC_PHONEBOOK,
        VAPP_HS_SHORTCUT_OPTION_NULL,
        vadp_v2p_hs_launch_phonebook),

    VAPP_HS_NEW_SHORTCUT(
        VAPP_HS_IMG_SC_CALL_HISTORY,
        VAPP_HS_SHORTCUT_OPTION_NULL,
        vadp_v2p_hs_launch_call_history),

#if defined(__MOD_SMSAL__)
    VAPP_HS_NEW_SHORTCUT(
        VAPP_HS_IMG_SC_MESSAGE_CENTER,
        VAPP_HS_SHORTCUT_OPTION_NULL,
        vadp_v2p_hs_launch_message_center),
#endif /* defined(__MOD_SMSAL__) */

#ifdef __MMI_CALENDAR__
    VAPP_HS_NEW_SHORTCUT(
        VAPP_HS_IMG_SC_CALENDAR,
        VAPP_HS_SHORTCUT_OPTION_NULL,
        vadp_v2p_hs_launch_calendar),
#endif /* __MMI_CALENDAR__ */

#ifdef __MMI_TODOLIST__
    VAPP_HS_NEW_SHORTCUT(
        VAPP_HS_IMG_SC_TODO,
        VAPP_HS_SHORTCUT_OPTION_NULL,
        vadp_v2p_hs_launch_todo),
#endif /* __MMI_TODOLIST__ */

    VAPP_HS_NEW_SHORTCUT(
        VAPP_HS_IMG_SC_ALARM,
        VAPP_HS_SHORTCUT_OPTION_NULL,
        vadp_v2p_hs_launch_alarm),

#if defined(__MMI_CALCULATOR__) || defined(__MMI_VRE_CALCULATOR__)
    VAPP_HS_NEW_SHORTCUT(
        VAPP_HS_IMG_SC_CALCULATOR,
        VAPP_HS_SHORTCUT_OPTION_NULL,
        vadp_v2p_hs_launch_calculator),
#endif /* __MMI_CALCULATOR__ */

#ifdef __MMI_AUDIO_PLAYER__
    VAPP_HS_NEW_SHORTCUT(
        VAPP_HS_IMG_SC_AUDIO_PLAYER,
        VAPP_HS_SHORTCUT_OPTION_NULL,
        vadp_v2p_hs_launch_audio_player),
#endif /* __MMI_AUDIO_PLAYER__ */

#ifdef __MMI_VIDEO_PLAYER__
    VAPP_HS_NEW_SHORTCUT(
        VAPP_HS_IMG_SC_VIDEO_PLAYER,
        VAPP_HS_SHORTCUT_OPTION_NULL,
        vadp_v2p_hs_launch_video_player),
#endif /* __MMI_VIDEO_PLAYER__ */

#if defined(__MMI_KURO_SUPPORT__)
    VAPP_HS_NEW_SHORTCUT(
        VAPP_HS_IMG_SC_KURO, 
        VAPP_HS_SHORTCUT_OPTION_NULL, 
        vadp_v2p_hs_launch_media_player),
#elif defined(__MMI_MEDIA_PLAYER__)
    VAPP_HS_NEW_SHORTCUT(
        VAPP_HS_IMG_SC_MEDIA_PLAYER, 
        VAPP_HS_SHORTCUT_OPTION_NULL, 
        vadp_v2p_hs_launch_media_player),
#endif /* __MMI_MEDIA_PLAYER__ */

#ifdef __MMI_VUI_3D_CUBE_APP__
    VAPP_HS_NEW_SHORTCUT(
        VAPP_HS_IMG_SC_CUBE, 
        VAPP_HS_SHORTCUT_OPTION_NULL, 
        vadp_v2p_hs_launch_3d_cube),
#endif /* __MMI_VUI_3D_CUBE_APP__ */

#ifdef __MMI_GADGET_SUPPORT__
    VAPP_HS_NEW_SHORTCUT(
        VAPP_HS_IMG_SC_WIDGET_MANAGER, 
        VAPP_HS_SHORTCUT_OPTION_NULL, 
        vadp_v2p_hs_launch_widget_manager),
#endif /* __MMI_GADGET_SUPPORT__ */

#if defined(__MMI_MRE_APP_OPERA__) 
      VAPP_HS_NEW_SHORTCUT(
        VAPP_HS_IMG_SC_MRE_OPERA, 
        VAPP_HS_SHORTCUT_OPTION_NULL, 
        mmi_am_la_launch_opera),
#endif


#if defined(__MMI_MRE_APP_OPERA_EN__)
      VAPP_HS_NEW_SHORTCUT(
        VAPP_HS_IMG_SC_MRE_OPERA, 
        VAPP_HS_SHORTCUT_OPTION_NULL, 
        mmi_am_la_launch_opera_en),
#endif

#ifdef __MMI_MRE_APP_YAHOO__
      VAPP_HS_NEW_SHORTCUT(
        VAPP_HS_IMG_SC_MRE_YM, 
        VAPP_HS_SHORTCUT_OPTION_NULL, 
        mmi_am_la_launch_Yahoo),
#endif



    VAPP_HS_NEW_SHORTCUT(0, 0, 0)
};


/***************************************************************************** 
 * External Interface
 *****************************************************************************/

const VappHsShortcutCfg *VappHsGetShortcutCfgTable()
{
    return g_vapp_hs_shortcut_tbl;
}

#endif /* __MMI_VUI_HOMESCREEN__ */

