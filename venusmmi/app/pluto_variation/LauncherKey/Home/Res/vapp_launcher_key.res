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
 *  vapp_launcher_key.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the key launcher homescreen resources.
 *
 * Author:
 * -------
 *  Fachao Zhang (mtk80513)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 04 18 2012 fachao.zhang
 * [MAUI_03170425] [check in] FTE2.0 support landscape
 * .
 *
 * 03 14 2012 fachao.zhang
 * [MAUI_03134160] [Key Launcher]Check in new feature - Key launcher
 * Support baidu or google search bar hint in idle page.
 *
 * 02 24 2012 fachao.zhang
 * [MAUI_03134160] [Key Launcher]Check in new feature - Key launcher
 * Add Trace.
 *
 * 02 21 2012 fachao.zhang
 * [MAUI_03134160] [Key Launcher]Check in new feature - Key launcher
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER_KEY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "CustResDef.h"


/*****************************************************************************
 * XML
 *****************************************************************************/

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_LAUNCHER_KEY">

    <!----- Screen Resource Area ---------------------------------------------->
    //<SCREEN id="SCR_ID_VAPP_KEYLAUNCHER_IDLE"/>


    <!-- String Resource Area-------------------------------------------------->
#ifndef __MMI_MAINLCD_320X240__
    <STRING id="STR_ID_VAPP_KEYLAUNCHER_IDLE"/>
    <STRING id="STR_ID_VAPP_KEYLAUNCHER_WIDGETS"/>
    <STRING id="STR_ID_VAPP_KEYLAUNCHER_MAINMENU"/>
#endif
    <STRING id="STR_ID_VAPP_KEYLAUNCHER_ECC"/>
    <STRING id="STR_ID_VAPP_KEYLAUNCHER_FLIGHT_MODE"/>


    <!-- Image Resource Area--------------------------------------------------->

    <!-- APP Images -->
    #define KEYLAUNCHER_HS_PATH       CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\HS\\\\"
	#define KEYLAUNCHER_COMMON_PATH   CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Common\\\\"
    #define KEYLAUNCHER_WIDGET_PATH   CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Common\\\\widget_common\\\\"

    <IMAGE id="IMG_ID_VAPP_KEYLAUNCHER_SOFTKEY_BG">KEYLAUNCHER_HS_PATH"hone_softkey.9slice.png"</IMAGE>

#ifdef __MMI_MAINLCD_320X240__
	<IMAGE id="IMG_ID_VAPP_KEYLAUNCHER_SOFTKEY_IDLE">KEYLAUNCHER_HS_PATH"home_idle.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_KEYLAUNCHER_SOFTKEY_WIDGET">KEYLAUNCHER_HS_PATH"home_widget.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_KEYLAUNCHER_SOFTKEY_MENU">KEYLAUNCHER_HS_PATH"home_menu.png"</IMAGE>
#endif /* __MMI_MAINLCD_320X240__ */
    
    <IMAGE id="IMG_ID_VAPP_KEYLAUNCHER_WIDGET_N">KEYLAUNCHER_WIDGET_PATH"icon_glass.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_KEYLAUNCHER_WIDGET_P">KEYLAUNCHER_WIDGET_PATH"icon_glass_select.png"</IMAGE>

#ifdef __MMI_SEARCH_WEB__
	<IMAGE id="IMG_ID_VAPP_KEYLAUNCHER_SEARCH_BAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Widget\\\\VIP_contact\\\\contact_glass.9slice.png"</IMAGE>
#endif

</APP>

#endif /* defined(__MMI_VUI_LAUNCHER_KEY__) */


