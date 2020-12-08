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
 *  vapp_op_launcher_key_hs.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the key launcher OP homescreen resources.
 *
 * Author:
 * -------
 *  Guoyi Zhao (mtk80128)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 04 23 2012 guoyi.zhao
 * [MAUI_03173668] [手机游戏] 安装手机游戏midlet 之后， 点击手机游戏icon， 仍然提示文件未找到， 在mainmenu 重新生成一个游戏大厅的图标
 * .
 *
 * 03 31 2012 guoyi.zhao
 * [MAUI_03160247] No need to have the menu Connectivity in Settings
 * .
 *
 * 03 25 2012 guoyi.zhao
 * [MAUI_03155822] CMCC TD key launcher homescreen and mainmenu check in
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#if defined(__OP01_3G__) && defined(__MMI_VUI_LAUNCHER_KEY__)
#include "CustResDef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_OP_LAUNCHER_KEY_HS">

    <!-- String Resource Area--------------------------------------------------->
    <STRING id="STR_ID_VAPP_OP_KEYLAUNCHER_ECC"/>
    <STRING id="STR_ID_VAPP_OP_KEYLAUNCHER_FLIGHT_MODE"/>

    <!-- Image Resource Area--------------------------------------------------->
    #define ROOT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\HS\\\\"

    <IMAGE id="IMG_ID_VAPP_SHORTCUT_LEFT_ARROW_ENABLE">ROOT_PATH"shortcut_arrow_left_enable.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SHORTCUT_LEFT_ARROW_DISABLE">ROOT_PATH"shortcut_arrow_left_disable.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SHORTCUT_RIGHT_ARROW_ENABLE">ROOT_PATH"shortcut_arrow_right_enable.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SHORTCUT_RIGHT_ARROW_DISABLE">ROOT_PATH"shortcut_arrow_right_disable.png"</IMAGE>

#ifdef __MMI_OP01_WIFI__
    <IMAGE id="IMG_ID_VAPP_WLAN_BUTTON_NORMAL_BG">ROOT_PATH"Button_BG.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WLAN_BUTTON_PRESSED_BG">ROOT_PATH"Button_BG_Active.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WLAN_ENABLE_ICON_NORMAL">ROOT_PATH"Icon_WiFi.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WLAN_ENABLE_ICON_PRESSED">ROOT_PATH"Icon_WiFi_Active.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WLAN_PROGRESS_DOT">ROOT_PATH"WiFi_dot.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WLAN_DISABLE_ICON_NORMAL">ROOT_PATH"Icon_WiFi_Disable.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WLAN_DISABLE_ICON_PRESSED">ROOT_PATH"Icon_WiFi_Disable_Active.png"</IMAGE>
#endif /* __MMI_OP01_WIFI__ */

</APP>

#endif /* defined(__OP01_3G__) && defined(__MMI_VUI_LAUNCHER_KEY__) */


