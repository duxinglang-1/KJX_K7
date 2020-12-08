/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_op01_launcher_key_mainmenu.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines OP01 specific APP resources for key launcher mainmenu screen.
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
#include "CustResDef.h"

#if defined(__OP01_3G__) && defined(__MMI_VUI_LAUNCHER_KEY__)

<?xml version="1.0" encoding="UTF-8"?>
    <!--Icons are used in FTE launcher and key launcher icons are replaced in vappkeyMainmenuMapTAble-->    
    #define ROOT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\MainMenu\\\\"

    #ifdef BROWSER_SUPPORT
        <!--Mobile portal in mainmenu-->
        <APP id = "VAPP_OP01_MOBILE_PORTAL" package_name="native.mtk.op01_mobile_portal"
            name = "STR_ID_VAPP_OP01_MOBILE_PORTAL" img="IMG_ID_VAPP_OP01_MOBILE_PORTAL"
            launch="vapp_op01_mobile_portal_launch">

            <STRING id="STR_ID_VAPP_OP01_MOBILE_PORTAL"/>
            <IMAGE id="IMG_ID_VAPP_OP01_MOBILE_PORTAL">ROOT_PATH"10086.png"</IMAGE>
        </APP>

        <!--Monternet in mainmenu-->
        <APP id = "VAPP_OP01_MONTERNET" package_name="native.mtk.op01_monternet"
            name = "STR_ID_VAPP_OP01_MONTERNET" img="IMG_ID_VAPP_OP01_MONTERNET"
            launch="vapp_op01_monternet_launch">

            <STRING id="STR_ID_VAPP_OP01_MONTERNET"/>
            <IMAGE id="IMG_ID_VAPP_OP01_MONTERNET">ROOT_PATH"MO.png"</IMAGE>
        </APP>
    #endif /* BROWSER_SUPPORT */
        
    #ifdef __MMI_OP01_MIDLET_FETION__
        <!--Fetion in mainmenu-->
        <APP id = "VAPP_OP01_FETION" package_name="native.mtk.op01_fetion"
            name = "STR_ID_VAPP_OP01_FETION" img="IMG_ID_VAPP_OP01_FETION"
            launch="vapp_op01_fetion_launch">

            <STRING id="STR_ID_VAPP_OP01_FETION"/>
            <IMAGE id="IMG_ID_VAPP_OP01_FETION">ROOT_PATH"Fetion.png"</IMAGE>
        </APP>
    #endif
        
    #ifdef __MMI_OP01_MIDLET_MUSIC_WALKMAN__
        <!--Music walkman in mainmenu-->
        <APP id = "VAPP_OP01_MUSIC_WALKMAN" package_name="native.mtk.op01_music_walkman"
            name = "STR_ID_VAPP_OP01_MUSIC_WALKMAN" img="IMG_ID_VAPP_OP01_MUSIC_WALKMAN"
            launch="vapp_op01_music_walkman_launch">

            <STRING id="STR_ID_VAPP_OP01_MUSIC_WALKMAN"/>
            <IMAGE id="IMG_ID_VAPP_OP01_MUSIC_WALKMAN">ROOT_PATH"Music.png"</IMAGE>
        </APP>
    #endif
        
    #ifdef __MMI_OP01_MIDLET_MOBILE_MARKET__
        <!--Mobile market in mainmenu-->
        <APP id = "VAPP_OP01_MOBILE_MARKET" package_name="native.mtk.op01_mobile_market"
            name = "STR_ID_VAPP_OP01_MOBILE_MARKET" img="IMG_ID_VAPP_OP01_MOBILE_MARKET"
            launch="vapp_op01_mobile_market_launch">

            <STRING id="STR_ID_VAPP_OP01_MOBILE_MARKET"/>
            <IMAGE id="IMG_ID_VAPP_OP01_MOBILE_MARKET">ROOT_PATH"Store.png"</IMAGE>
        </APP>
    #endif
        
    #ifdef __MMI_OP01_MIDLET_CMREAD__
        <!--Mobile read in mainmenu-->
        <APP id = "VAPP_OP01_MOBILE_READ" package_name="native.mtk.op01_mobile_read"
            name = "STR_ID_VAPP_OP01_MOBILE_READER" img="IMG_ID_VAPP_OP01_MOBILE_READ"
            launch="vapp_op01_mobile_read_launch">

            <STRING id="STR_ID_VAPP_OP01_MOBILE_READER"/>
            <IMAGE id="IMG_ID_VAPP_OP01_MOBILE_READ">ROOT_PATH"Read.png"</IMAGE>
        </APP>
    #endif

    #ifdef __MMI_OP01_MIDLET_139MAIL__
        <!--139 push mail in mainmenu-->
        <APP id = "VAPP_OP01_139_PUSH_MAIL" package_name="native.mtk.op01_139_push_mail"
            name = "STR_ID_VAPP_OP01_139_PUSH_MAIL" img="IMG_ID_VAPP_OP01_139_PUSH_MAIL"
            launch="vapp_op01_139_push_mail_launch">

            <STRING id="STR_ID_VAPP_OP01_139_PUSH_MAIL"/>
            <IMAGE id="IMG_ID_VAPP_OP01_139_PUSH_MAIL">ROOT_PATH"139.png"</IMAGE>
        </APP>
    #endif

    #ifdef __MMI_OP01_MIDLET_MOBILE_GAME__
        <!--Mobile game in mainmenu-->
        <APP id = "VAPP_OP01_MOBILE_GAME" package_name="native.mtk.op01_mobile_game"
            name = "STR_ID_VAPP_OP01_MOBILE_GAME" img="IMG_ID_VAPP_OP01_MOBILE_GAME"
            launch="vapp_op01_mobile_game_launch">

            <STRING id="STR_ID_VAPP_OP01_MOBILE_GAME"/>
            <IMAGE id="IMG_ID_VAPP_OP01_MOBILE_GAME">ROOT_PATH"Game.png"</IMAGE>
        </APP>
    #endif

    #ifdef __MMI_OP01_MIDLET_MOBILE_STOCK__
        <!--Mobile game in mainmenu-->
        <APP id = "VAPP_OP01_MOBILE_STOCK" package_name="native.mtk.op01_mobile_stock"
            name = "STR_ID_VAPP_OP01_MOBILE_STOCK" img="IMG_ID_VAPP_OP01_MOBILE_STOCK"
            launch="vapp_op01_mobile_stock_launch">

            <STRING id="STR_ID_VAPP_OP01_MOBILE_STOCK"/>
            <IMAGE id="IMG_ID_VAPP_OP01_MOBILE_STOCK">ROOT_PATH"Stock.png"</IMAGE>
        </APP>
    #endif

#endif /* defined(__OP01_3G__) && defined(__MMI_VUI_LAUNCHER_KEY__) */

