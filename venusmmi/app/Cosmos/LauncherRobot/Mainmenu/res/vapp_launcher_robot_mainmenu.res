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
 *  vapp_launcher_robot_mainmenu.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the vertical mainmenu resources.
 *
 * Author:
 * -------
 *  Andy Kauo (mtk03823)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 06 18 2012 andy.kauo
 * [MAUI_03195224] pre load apps icons are not present in the rbot launcher
 * .Support pre-loaded MRE shortcut apps.
 *
 * 05 30 2012 andy.kauo
 * [MAUI_03192757] [UE]java midlet icon show abnormal
 * Adaptive java container check in & revise code.
 *
 * 04 29 2012 andy.kauo
 * [MAUI_03115676] [Cosmos2.0] check in Launcher Robot Mainmenu
 * [Code Revision] Remove email app event from resource file.
 *
 * 01 19 2012 andy.kauo
 * [MAUI_03115676] [Cosmos2.0] check in Launcher Robot Mainmenu
 * . Launcher Robot Mainmenu Check In.
 *
 * 01 13 2012 andy.kauo
 * [MAUI_03115676] [Cosmos2.0] check in Launcher Robot Mainmenu
 * . add Mainmenu_Icon resgen
 *
 * 01 13 2012 andy.kauo
 * [MAUI_03115676] [Cosmos2.0] check in Launcher Robot Mainmenu
 * . Fix build error.
 *
 * 01 11 2012 andy.kauo
 * [MAUI_03115676] [Cosmos2.0] check in Launcher Robot Mainmenu
 * . Fix resgen error.
 *
 * 01 11 2012 andy.kauo
 * [MAUI_03115676] [Cosmos2.0] check in Launcher Robot Mainmenu
 * .Robot Mainmenu check in
 *
 * 01 11 2012 weilun.liu
 * [MAUI_03115275] [Cosmos2.0] check in Cosmos HS and Android HS
 * check in cosmos and android launcher
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_LAUNCHER_ROBOT_MAINMENU" type="venus">

     #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Launcher\\\\LauncherRobot\\\\Mainmenu\\\\"
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_MM_ICON_HOME">ROOT_PATH"Home.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_MM_SHADOW_TOP">ROOT_PATH"Mianmenu_Shadow_U.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_MM_SHADOW_BOTTOM">ROOT_PATH"Mianmenu_Shadow_D.9slice.png"</IMAGE>    
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_MM_STATUS_BAR_BG">ROOT_PATH"StatusBar_BG.9slice.png"</IMAGE>    
    
    <THEME>  
        <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_MM_ICON_PREINSTALL_APP">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\App_download.png"</IMAGE>        
    </THEME>

    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Common\\\\"
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_MM_APP_COUNTER_BG">ROOT_PATH"Point_BG.9slice.png"</IMAGE>
</APP>
