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
 *   vapp_fm_radio.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  FM Radio resource file
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
 * 12 20 2012 feibiao.zhang
 * [MAUI_03295589] [FM Radio] Check in FM Radio Slim code and res.
 * Check in FM Radio Slim source code.
 *
 * 12 10 2012 feibiao.zhang
 * NULL
 * Adjust FM Radio Slim UI to support 320*480 and 240*400 solution.
 *
 * 11 19 2012 feibiao.zhang
 * NULL
 * Check in FM Radio Slim source code.
 * 
 * 09 27 2012 feibiao.zhang
 * [MAUI_03238233] [FM Radio] Develop FM Radio NCenter Widget 2.0
 * Check in FM Radio NCenter Widget.code
 * 
 * 08 21 2012 feibiao.zhang
 * [MAUI_03226489] [Cosmos SLIM 256128 Patchback] Show red x icon for Favorites and Auto Search tab in FM radio
 * Only use *.jpg in slim project, use *.png in nonslim project..
 *
 * 07 12 2012 feibiao.zhang
 * [MAUI_03213897] [FM Via A2DP] Check in FM via A2DP app code
 * Check in FM via  A2DP  new feature app code.
 *
 * 07 06 2012 feibiao.zhang
 * [MAUI_03210699] [Victor 56V10][Cosmos][FM Radio] A black line appears at right side
 * The mirror transform may cause the lack of pixel if the total pixel is even.
 * So resize the width of bg_tab to odd to resolve it.
 *
 * 06 18 2012 feibiao.zhang
 * [MAUI_03204018] [KHAN50_V11][Cosmos-Slim][FM Radio] Set VRT factor
 * Correct the spelling error.
 *
 * 06 10 2012 feibiao.zhang
 * [MAUI_03200338] [FM Radio]Show headset button only in the case of earphone is plug in.
 * Add IMG_ID_VAPP_FM_BTN_EARPHONE_ON to .res.
 *
 * 06 07 2012 feibiao.zhang
 * [MAUI_03198965] [FM Radio] Set VRT factor
 * Set VRT factor.
 *
 * 06 01 2012 feibiao.zhang
 * [MAUI_03195867] Cosmos Slim Dev Check In
 * Change Main menu FM radio icon for slim.
 *
 * 05 23 2012 yufei.shen
 * [MAUI_03189327] [Victor 56V10][Cosmos][FM Radio]   Assert fail: vfx_object.cpp 782 - MMI
 * .
 *
 * 05 17 2012 yufei.shen
 * [MAUI_03184258] [nvram] fm radio nvram discription add
 * .
 *
 * 05 08 2012 yufei.shen
 * [MAUI_03177487] Assert fail: vfx_sys_memory.c 1653 0x3 0xe0002380 0x108 - MMI
 * .
 *
 * 04 26 2012 yufei.shen
 * [MAUI_03173277] [FM] Assert fail: vfx_sys_memory.c 1634 0x3 0xe04ee380 0x110 - MMI
 * .
 *
 * 04 18 2012 yufei.shen
 * [MAUI_03157051] [Fm Radio] Ncenter 2.0 check in
 * .
 *
 * 04 11 2012 yufei.shen
 * [MAUI_03155006] [COSMOS Slim]FM Radio slim
 * .
 *
 * 03 30 2012 yufei.shen
 * [MAUI_03159674] [Cosmos Slim] Button Image slim
 * .
 *
 * 03 29 2012 yufei.shen
 * [MAUI_03155006] [COSMOS Slim]FM Radio slim
 * .
 *
 * 03 15 2012 yufei.shen
 * [MAUI_03149485] [Fm Radio]cosmos slim move memory to asm
 * .
 *
 * 01 10 2012 yufei.shen
 * [MAUI_03114513] [Victor56V10]Assert fail: AppMemMgrCore.c 4235 0xffffffdf 0x94ad 0xe0938000 - MMI
 * .
 *
 * 12 22 2011 fred.shen
 * [MAUI_02868261] [Cosmos] Cosmos check-in
 * .
 *
 * 09 09 2011 kinse.lin
 * [MAUI_03024229] [FM] check in MMv2 memory shrink : close list panel when hidden
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"

#ifdef __MMI_FM_RADIO_SLIM__

#include "custresdef.h"

<?xml version = "1.0" encoding = "UTF-8"?>
<APP id = "VAPP_FM_RADIO" 
     package_name = "native.mtk.fmradio"
     name = "STR_ID_VAPP_FM"
     img = "IMG_ID_VAPP_FM"
     launch = "vapp_fm_radio_launch"
     type="venus">
     
    <MEMORY heap="200*1024"
    vrt_mem_factor = "2.0"/>

<!-----------------------------------------------------String Section------------------------------------------------------>
    <STRING id="STR_ID_VAPP_FM"/>
    <STRING id="STR_ID_VAPP_FM_CHANNEL_LIST"/>
    <STRING id="STR_ID_VAPP_FM_AUTO_SEARCH"/>
    <STRING id="STR_ID_VAPP_FM_AUTO_SEARCH_Q"/>
    <STRING id="STR_ID_VAPP_FM_AUTO_LIST_EMPTY"/>
    <STRING id="STR_ID_VAPP_FM_SEARCHING"/>
    <STRING id="STR_ID_VAPP_FM_FAV"/>
    <STRING id="STR_ID_VAPP_FM_FAV_LIST_EMPTY"/>
    <STRING id="STR_ID_VAPP_FM_ADD_TO_FAV"/>
    <STRING id="STR_ID_VAPP_FM_ADDED_TO_FAV"/>
    <STRING id="STR_ID_VAPP_FM_FAV_LIST_FULL"/>
    <STRING id="STR_ID_VAPP_FM_DELETE_FAV_Q_1"/>
    <STRING id="STR_ID_VAPP_FM_DELETE_FAV_Q_2"/>
    <STRING id="STR_ID_VAPP_FM_PLUG_IN_EARPHONE"/>
    <STRING id="STR_ID_VAPP_FM_ASK_POWER_ON"/>
    <STRING id="STR_ID_VAPP_FM_TO_FAV"/>
    <STRING id="STR_ID_VAPP_FM_EDIT_CHANNEL"/>
    <STRING id="STR_ID_VAPP_FM_CHANNEL_NAME"/>
    <STRING id="STR_ID_VAPP_FM_FQ"/>
    <STRING id="STR_ID_VAPP_FM_INVALID_FQ"/>   
    <STRING id="STR_ID_VAPP_FM_POWER_OFF_FM_Q"/>

<!-----------------------------------------------------Image Section------------------------------------------------------>

    <THEME>
        <IMAGE id="IMG_ID_VAPP_FM" desc="Main menu FM radio icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\FmRadio.png"</IMAGE>
    </THEME>
    
    <IMAGE id="IMG_ID_VAPP_FM_BTN_ARROW_L" >CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Redesign\\\\FMRadio\\\\Arrow_L.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_FM_BTN_ARROW_R" >CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Redesign\\\\FMRadio\\\\Arrow_R.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_FM_BTN_PREV" >CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Redesign\\\\FMRadio\\\\Btn_pre.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_FM_BTN_NEXT" >CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Redesign\\\\FMRadio\\\\Btn_next.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_FM_BTN_SPEAKER" >CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Redesign\\\\FMRadio\\\\Icon_speaker_D.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_FM_BTN_SPEAKER_ON" >CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Redesign\\\\FMRadio\\\\Icon_speaker.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_FM_BTN_FAV" >CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Redesign\\\\FMRadio\\\\Icon_fav_D.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_FM_BTN_FAV_ON" >CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Redesign\\\\FMRadio\\\\Icon_fav.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_FM_BTN_POWER_OFF" >CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Redesign\\\\FMRadio\\\\FM_power_off.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_FM_BTN_POWER_ON" >CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Redesign\\\\FMRadio\\\\FM_power_on.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_FM_BTN_POWER_N" >CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Redesign\\\\FMRadio\\\\FM_BG1.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_FM_BTN_POWER_P" >CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Redesign\\\\FMRadio\\\\FM_BG2.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_FM_TUNER_BG" >CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Redesign\\\\FMRadio\\\\Tune_BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_FM_TUNER_PIN" >CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Redesign\\\\FMRadio\\\\Tune_pin.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_FM_ICON_AUTO_SEARCH" >CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Redesign\\\\FMRadio\\\\TabIcon\\\\Search.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_FM_ICON_FAV" >CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Redesign\\\\FMRadio\\\\TabIcon\\\\Fav.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_FM_FAV_EDIT" >CUST_IMG_PATH_ROOT"\\\\MainLCD\\\\Default\\\\Redesign\\\\FMRadio\\\\Edit.png"</IMAGE>

    <!-----------------------------------------------------Event Section------------------------------------------------------>

    <EVENT id="EVT_ID_VAPP_FM_UPDATE_NCENTER" type="SENDER"/>
    <EVENT id="EVT_ID_VAPP_FM_SCAN_DONE" type="SENDER"/>

	<RECEIVER id="EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE" proc="vadp_fm_radio_evt_proc"/>
	<RECEIVER id="EVT_ID_SRV_PROF_IS_PLAYING" proc="vadp_fm_radio_evt_proc"/>
	<RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_OUT" proc="vadp_fm_radio_evt_proc"/>
	<RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_IN" proc="vadp_fm_radio_evt_proc"/>

//klawmo
#ifdef __DM_LAWMO_SUPPORT__
	<RECEIVER id="EVT_ID_SRV_DM_LAWMO_LOCK_IND" proc="vadp_fm_radio_evt_proc"/>
#endif

    <!----------------------------------------------------- Timer ------------------------------------------------------------>
    <TIMER id= "TIMER_ID_VAPP_FM_STORE_CUR_FREQ"/>

    <!----------------------------------------------------- NVRAM ------------------------------------------------------------>

    <CACHEDATA type="short" id="NVRAM_VAPP_FMRDO_CUR_FREQ" restore_flag="TRUE">
        <DEFAULT_VALUE> [900] </DEFAULT_VALUE>
        <DESCRIPTION> Current frequency </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_VAPP_FMRDO_AUD_PATH" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Current frequency </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_VAPP_FMRDO_AUTO_LIST_NUM" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Auto-List number </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_VAPP_FMRDO_FAV_LIST_NUM" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> FAV-List number </DESCRIPTION>
    </CACHEDATA>

    <!----------------------------------------------------- NCenter ------------------------------------------------------------>
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
    
    <RECEIVER id="EVT_ID_VAPP_FM_UPDATE_NCENTER" proc="vapp_fm_radio_on_ncenter_update"/>
#endif

</APP>
#endif

