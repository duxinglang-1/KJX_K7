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
 *  vapp_launcher_robot_page_transition_setting.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the launcher page transition resources.
 *
 * Author:
 * -------
 *  Weilun Liu (mtk02772)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 06 08 2012 ch.ko
 * [MAUI_03165607] [Cosmos Slim] Check-in patch
 * Fixing incorrect application icon.
 *
 * 05 31 2012 weilun.liu
 * [MAUI_03162182] [Cosmos Slim]
 * integrate app icon with theme and change image default path
 *
 * 05 28 2012 weilun.liu
 * [MAUI_03188145] [Cosmos 2.0 enhancement]
 * support page transition with reduce page size to reduce cache memory usage
 *
 * 05 18 2012 weilun.liu
 * [MAUI_03188145] [Cosmos 2.0 enhancement]
 * check in new page transition effect and HS FX setting app
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_HOME_SCREEN_SWITCH_EFFECT__)

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "CustResDef.h"


/*****************************************************************************
 * XML
 *****************************************************************************/

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_SETTING" name="STR_ID_VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_SETTING" 
    package_name = "native.mtk.launcher_robot_page_transition_setting"
    img = "IMG_ID_VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_SETTING_APP_ICON"
    launch="vapp_launcher_robot_page_transition_setting_launch"
    hidden_in_mainmenu="true"
    type="venus">
    
    <MEMORY base="0"/>

    <!-- String Resource Area-------------------------------------------------->
    <STRING id="STR_ID_VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_SETTING"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_SETTING_CLASSIC"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_SETTING_CYLINDER"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_SETTING_WINDMILL"/> 
    <STRING id="STR_ID_VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_SETTING_PAGEFLOW"/>  


    <!-- Image Resource Area--------------------------------------------------->
    <THEME>
        <IMAGE id="IMG_ID_VAPP_LAUNCHER_ROBOT_PAGE_TRANSITION_SETTING_APP_ICON" desc="HS Switch effect setting">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\HomeSwitch.png"</IMAGE>
    </THEME>

    <!------------------------------------------------------MMI Cache Resource---------------------------------------------------------->    
    <CACHEDATA type="byte" id="NVRAM_SETTING_PAGE_TRANSITION_EFFECT_ZOOM_IN_TYPE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X02] </DEFAULT_VALUE>
        <DESCRIPTION> Robot launcher page transition zoom in type </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_SETTING_PAGE_TRANSITION_EFFECT_ZOOM_OUT_TYPE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X05] </DEFAULT_VALUE>
        <DESCRIPTION> Robot launcher page transition zoom out type </DESCRIPTION>
    </CACHEDATA>

    <!-- Event Area--------------------------------------------------->

</APP>

#endif
