/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vapp_package_res.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the resource for Pluto variation package.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 Definition
*****************************************************************************/

#undef VFX_APP_RES_DECLARE
#define VFX_APP_RES_DECLARE(_app, _range, _path)                            \
    MMI_RES_DECLARE(_app, _range, "..\\venusmmi\\app\\pluto_variation\\" _path)


/*****************************************************************************
 APP resource declaration
*****************************************************************************/

#if defined(__MMI_VUI_LAUNCHER__)
VFX_APP_RES_DECLARE(VAPP_DESKTOP, 30, "Launcher\\Desktop\\res\\")
VFX_APP_RES_DECLARE(VAPP_APP_WIDGET, 5, "Launcher\\AppWidget\\res\\")
VFX_APP_RES_DECLARE(VAPP_APP_WIDGET_CLOCK, 50, "Launcher\\AppWidget\\res\\")
VFX_APP_RES_DECLARE(VAPP_APP_WIDGET_OPERATOR_NAME_COSMOS, 10, "Launcher\\AppWidget\\res\\")
VFX_APP_RES_DECLARE(VAPP_DRAWER, 50, "Launcher\\Drawer\\res\\")
#endif /* defined(__MMI_VUI_LAUNCHER__) */

// Key laucncher Part
#if defined(__MMI_VUI_LAUNCHER_KEY__)
VFX_APP_RES_DECLARE(VAPP_LAUNCHER_KEY, 20, "LauncherKey\\Home\\Res\\")
VFX_APP_RES_DECLARE(VAPP_KEY_MAINMENU, 100, "LauncherKey\\Mainmenu\\res\\")
#endif /* defined(__MMI_VUI_LAUNCHER_KEY__) */

// For OP01 key launcher mainmenu
#if defined(__OP01_3G__) && defined(__MMI_VUI_LAUNCHER_KEY__)
VFX_APP_RES_DECLARE(VAPP_OP01_MOBILE_PORTAL, 5, "LauncherKey\\OPMainmenu\\OP01Mainmenu\\res\\")
VFX_APP_RES_DECLARE(VAPP_OP01_FETION, 5, "LauncherKey\\OPMainmenu\\OP01Mainmenu\\res\\")
VFX_APP_RES_DECLARE(VAPP_OP01_MUSIC_WALKMAN, 5, "LauncherKey\\OPMainmenu\\OP01Mainmenu\\res\\")
VFX_APP_RES_DECLARE(VAPP_OP01_MOBILE_MARKET, 5, "LauncherKey\\OPMainmenu\\OP01Mainmenu\\res\\")
VFX_APP_RES_DECLARE(VAPP_OP01_MOBILE_READ, 5, "LauncherKey\\OPMainmenu\\OP01Mainmenu\\res\\")
VFX_APP_RES_DECLARE(VAPP_OP01_139_PUSH_MAIL, 5, "LauncherKey\\OPMainmenu\\OP01Mainmenu\\res\\")
VFX_APP_RES_DECLARE(VAPP_OP01_MOBILE_GAME, 5, "LauncherKey\\OPMainmenu\\OP01Mainmenu\\res\\")
VFX_APP_RES_DECLARE(VAPP_OP01_MOBILE_STOCK, 5, "LauncherKey\\OPMainmenu\\OP01Mainmenu\\res\\")
VFX_APP_RES_DECLARE(VAPP_OP01_MONTERNET, 5, "LauncherKey\\OPMainmenu\\OP01Mainmenu\\res\\")

VFX_APP_RES_DECLARE(VAPP_OP_LAUNCHER_KEY_HS, 20, "LauncherKey\\OPHome\\Res\\")
#endif /* defined(__OP01_3G__) && defined(__MMI_VUI_LAUNCHER_KEY__) */

#if defined(__MMI_VUI_SCREEN_LOCK_KEY__) || defined(__MMI_VUI_LAUNCHER_KEY__)
VFX_APP_RES_DECLARE(APP_VENUS_SCREEN_LOCK_KEY, 50, "ScreenLockKey\\res")
#endif

#if defined(__MMI_VUI_WIDGET_KEY_VIP_CONTACT__)
VFX_APP_RES_DECLARE(VAPP_WIDGET_FAVORITE_CONTACT, 20, "LauncherKey\\widget\\VipContact\\Res\\")
#endif

#if defined(__MMI_VUI_WIDGET_KEY_MESSAGE__)
VFX_APP_RES_DECLARE(VAPP_WIDGET_MESSAGE, 20, "LauncherKey\\widget\\Message\\Res\\")
#endif


#if defined(__MMI_VUI_WIDGET_KEY_SNS__)
VFX_APP_RES_DECLARE(VAPP_WIDGET_KEY_SNS, 20, "LauncherKey\\widget\\SNS\\Res\\")
#endif

#if defined(__MMI_VUI_WIDGET_KEY_MUSIC_PLAYER__)
VFX_APP_RES_DECLARE(APP_VENUS_KEY_WG_MUSICPLAYER, 20, "LauncherKey\\widget\\MusicPlayer\\Res\\")
#endif

#if defined(__MMI_VUI_WIDGET_KEY_FM_RADIO__)
VFX_APP_RES_DECLARE(APP_VENUS_KEY_WG_FMRADIO, 20, "LauncherKey\\widget\\FmRadio\\Res\\")
#endif

#if defined(__MMI_VUI_WIDGET_KEY_IMAGE_VIEWER__)
VFX_APP_RES_DECLARE(APP_VENUS_WIDGET_KEY_IMAGE_VIEWER, 20, "LauncherKey\\widget\\ImageViewer\\Res\\")
#endif


#if defined(__MMI_VUI_WIDGET_KEY_ALARM__)
VFX_APP_RES_DECLARE(VAPP_WIDGET_KEY_ALARM, 20, "LauncherKey\\widget\\Alarm\\Res\\")
#endif

