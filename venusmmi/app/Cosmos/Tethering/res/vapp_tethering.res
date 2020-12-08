/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 * vapp_tethering.res
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Tethering venusmmi resource.
 *
 * Author:
 * -------
 * Yixiong Zhao(mtk80274)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 05 31 2012 bing.luo
 * [MAUI_03193480] modify the image define of .res file.
 * .
 *
 * 12 22 2011 fred.shen
 * [MAUI_02868261] [Cosmos] Cosmos check-in
 * .
 *
 * 10 27 2011 yixiong.zhao
 * [MAUI_03062905] [sap]SAP connect, the da in wifi tethering show empty name
 * .
 *
 * 04 18 2011 yixiong.zhao
 * [MAUI_02660705] [Tethering] Auto turn off
 * .
 *
 * 02 25 2011 yixiong.zhao
 * [MAUI_02653558] [Tethering] Add entry in mainmenu
 * .
 *
 * 02 22 2011 yixiong.zhao
 * [MAUI_02652793] cosmos dtcnt cui rename
 * .
 *
 * 02 20 2011 yixiong.zhao
 * [MAUI_02652460] [USB Tethering] Check-in
 * .
 *
 * 01 20 2011 yixiong.zhao
 * [MAUI_02649379] [Hotspot][Cosmos] Add set password popup when first use the psk auth mode.
 * .
 *
 * 12 31 2010 yixiong.zhao
 * [MAUI_02645462] [Hotspot] Check in code (TCPIP, DHCPD, MMI)
 * solve resgen error.
 *
 * 12 25 2010 yixiong.zhao
 * [MAUI_02645462] [Hotspot] Check in code (TCPIP, DHCPD, MMI)
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
#ifdef __MMI_TETHERING__
<APP id="VAPP_TETHERING"
    package_name="native.mtk.tethering"
    name="STR_ID_VAPP_TETHERING"
    img="IMG_ID_VAPP_TETHERING_MAINMENU"
    launch="vapp_tethering_launch"
    type="venus">
    <INCLUDE file="mmi_rp_srv_tethering_def.h"/>
    <INCLUDE file="GlobalResDef.h"/>
    <MEMORY base="250*1024 + base(VCUI_DTCNT)" heap="250*1024" fg="fg(VCUI_DTCNT)" />
    //<LAYOUT file="vapp_tethering.xml" />
    <STRING id="STR_ID_VAPP_TETHERING"/>
    <STRING id="STR_ID_VAPP_TETHERING_EXPLANATION"/>
    <STRING id="STR_ID_VAPP_TETHERING_WIFI_SETTINGS_EXPLANATION"/>
    <STRING id="STR_ID_VAPP_TETHERING_WIFI_SET_PASSWORD"/>
    <STRING id="STR_ID_VAPP_TETHERING_WIFI_NEW_PASSWORD"/>
    <STRING id="STR_ID_VAPP_TETHERING_WIFI_CONFIRM_PASSWORD"/>
    <STRING id="STR_ID_VAPP_TETHERING_WIFI_PASSWORD_UNMATCH_WARNING"/>
    <STRING id="STR_ID_VAPP_TETHERING_WIFI_AUTO_TURN_OFF_COUNTDOWN"/>

    <STRING id="STR_ID_VAPP_TETHERING_USB_PROMPT_PLUG_IN"/>
    <STRING id="STR_ID_VAPP_TETHERING_USB_PROMPT_PLUG_OUT"/>

    <THEME>
        <IMAGE id="IMG_ID_VAPP_TETHERING_MAINMENU" desc="Main menu tethering icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\Internet_Tethering.png"</IMAGE>
    </THEME>

    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_NO_SIM_AVAILABLE" proc="vappTetheringNoSimAvailableHdlr"/>

</APP>
#endif /* __MMI_TETHERING__ */
