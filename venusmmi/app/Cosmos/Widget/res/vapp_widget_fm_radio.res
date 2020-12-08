/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   vapp_widget_fm_radio.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Widget FM Radio resource file
 *
 * Author:
 * -------
 *   Kinse Lin (mtk01393)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision: $
 * $Modtime: $
 * $Log: $
 *
 * 12 16 2012 feibiao.zhang
 * [MAUI_03290596] [FM Radio] Resolve the remained build warnings.
 * Resolve the remained build warnings.
 * 
 * 10 08 2012 feibiao.zhang
 * [MAUI_03238233] [FM Radio] Develop FM Radio NCenter Widget 2.0
 * Modify FM Radio NCenter iocns path.
 * 
 * 09 27 2012 feibiao.zhang
 * [MAUI_03238233] [FM Radio] Develop FM Radio NCenter Widget 2.0
 * Adjust NCenter Widget UI.
 * Not respond to AVRCP command when fm power off in NCenter widget.
 * 
 * 09 27 2012 feibiao.zhang
 * [MAUI_03238233] [FM Radio] Develop FM Radio NCenter Widget 2.0
 * Check in FM Radio NCenter Widget.code
 *
 * 05 04 2012 yufei.shen
 * [MAUI_03180021] [Fm radio] widget option change
 * .
 *
 * 03 30 2012 yufei.shen
 * [MAUI_03159674] [Cosmos Slim] Button Image slim
 * .
 *
 * 01 18 2012 ch.ko
 * [MAUI_03118855] Check-in Cosmos 2.0 launcher and screen lock
 * Check-in patch.
 *
 * 04 21 2011 kinse.lin
 * [MAUI_02661056] [FM radio]the |<,>| should disable when FM power off
 * .
 *
 * 03 30 2011 kinse.lin
 * [MAUI_02904266] [Home] Fix incorrect AP naming
 * .
 *
 * 02 21 2011 kinse.lin
 * [MAUI_02873328] [FM Radio] check in Cosmos Widget and Lock
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "mmi_features.h"

#ifndef __MMI_FM_RADIO_SLIM__

#if defined(__MMI_VUI_WIDGET_FM_RADIO__) || defined(__MMI_NCENTER_SUPPORT__)

#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_WIDGET_FM_RADIO" type="venus">

#if defined(__MMI_VUI_WIDGET_FM_RADIO__)
    <LAYOUT file="vapp_widget_fm_radio.xml" />

<!-----------------------------------------------------String Section------------------------------------------------------>
    <STRING id="STR_ID_VAPP_WIDGET_FMR_RADIO"/>
    <STRING id="STR_ID_VAPP_WIDGET_FMR_SHOW_CONTROL"/>

<!-----------------------------------------------------Image Section------------------------------------------------------>

    <IMAGE id="IMG_ID_VAPP_WIDGET_FMR_ICON">RES_IMG_ROOT"\\\\Widget\\\\FMRadio\\\\icon_fm_widget.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_FMR_BACKGROUND">RES_IMG_ROOT"\\\\Widget\\\\FMRadio\\\\bg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_FMR_LCD_BG">RES_IMG_ROOT"\\\\Widget\\\\FMRadio\\\\LCD_bg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_FMR_LCD_HL">RES_IMG_ROOT"\\\\Widget\\\\FMRadio\\\\LCD_hl.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_FMR_LCD_ON">RES_IMG_ROOT"\\\\Widget\\\\FMRadio\\\\LCD_on_bg.png"</IMAGE>

#ifndef __LOW_COST_SUPPORT_COMMON__
    <IMAGE id="IMG_ID_VAPP_WIDGET_FMR_HOLE">RES_IMG_ROOT"\\\\Widget\\\\FMRadio\\\\speaker.png"</IMAGE>
#endif

    <IMAGE id="IMG_ID_VAPP_WIDGET_FMR_BTN_POWER_ON">RES_IMG_ROOT"\\\\Widget\\\\FMRadio\\\\btn_power_on.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_FMR_BTN_POWER_OFF">RES_IMG_ROOT"\\\\Widget\\\\FMRadio\\\\btn_power_off.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_FMR_BTN_POWER_N">RES_IMG_ROOT"\\\\Widget\\\\FMRadio\\\\btn_power_bg_n.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_FMR_BTN_POWER_P">RES_IMG_ROOT"\\\\Widget\\\\FMRadio\\\\btn_power_bg_p.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_FMR_BTN_BG_N">RES_IMG_ROOT"\\\\Widget\\\\FMRadio\\\\btn_bg_n.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_FMR_BTN_BG_P">RES_IMG_ROOT"\\\\Widget\\\\FMRadio\\\\btn_bg_p.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_FMR_BTN_PREV">RES_IMG_ROOT"\\\\Widget\\\\FMRadio\\\\btn_pre_n.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_FMR_BTN_PREV_D">RES_IMG_ROOT"\\\\Widget\\\\FMRadio\\\\btn_pre_d.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_FMR_BTN_NEXT">RES_IMG_ROOT"\\\\Widget\\\\FMRadio\\\\btn_next_n.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_FMR_BTN_NEXT_D">RES_IMG_ROOT"\\\\Widget\\\\FMRadio\\\\btn_next_d.png"</IMAGE>
    
    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetFmRadioPublisher"/>
#endif
 
#if defined(__MMI_NCENTER_SUPPORT__)  
    <IMAGE id="IMG_ID_VAPP_NCENTER_FM_ICON" >CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\NMGR_Icon\\\\icon_FM.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_NCENTER_FMR_BACKGROUND">RES_IMG_ROOT"\\\\NCenter\\\\FMRadio\\\\Panel_BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_NCENTER_FMR_BTN_POWER_ON">RES_IMG_ROOT"\\\\NCenter\\\\FMRadio\\\\FM_On.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_NCENTER_FMR_BTN_POWER_OFF">RES_IMG_ROOT"\\\\NCenter\\\\FMRadio\\\\FM_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_NCENTER_FMR_BTN_POWER_N">RES_IMG_ROOT"\\\\NCenter\\\\FMRadio\\\\Btn_BG1_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_NCENTER_FMR_BTN_POWER_P">RES_IMG_ROOT"\\\\NCenter\\\\FMRadio\\\\Btn_BG1_P.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_NCENTER_FMR_BTN_BG_N">RES_IMG_ROOT"\\\\NCenter\\\\FMRadio\\\\Btn_BG2_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_NCENTER_FMR_BTN_BG_P">RES_IMG_ROOT"\\\\NCenter\\\\FMRadio\\\\Btn_BG2_P.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_NCENTER_FMR_BTN_PREV">RES_IMG_ROOT"\\\\NCenter\\\\FMRadio\\\\FM_Prev_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_NCENTER_FMR_BTN_PREV_D">RES_IMG_ROOT"\\\\NCenter\\\\FMRadio\\\\FM_Prev_D.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_NCENTER_FMR_BTN_NEXT">RES_IMG_ROOT"\\\\NCenter\\\\FMRadio\\\\FM_Next_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_NCENTER_FMR_BTN_NEXT_D">RES_IMG_ROOT"\\\\NCenter\\\\FMRadio\\\\FM_Next_D.png"</IMAGE>
#endif

</APP>

#endif /* defined(__MMI_VUI_WIDGET_FM_RADIO__) || defined(__MMI_NCENTER_SUPPORT__) */

#endif // __MMI_FM_RADIO_SLIM__
