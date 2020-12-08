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
 * Filename:
 * ---------
 *	 Res_Game.c
 *
 * Project:
 * --------
 *  Maui
 *
 * Description:
 * ------------
 *  Game Resource
 *
 * Author:
 * -------
 *	 Bear Wang (MTK00612)
 *   Vincent Cho (MTK01166)
 *   Yingchun Zhang (MTK80069)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 25 2012 shengxi.xu
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * - Patch back to 11B
 *
 * 02 19 2011 yiping.xie
 * [MAUI_02652442] [game] __mmi_motion_app__ roll back
 * .
 *
 * 11 17 2010 yiping.xie
 * [MAUI_02641274] [Game,VdoRec] NVRAM move to resource file
 * .
 *
 * 10 11 2010 yiping.xie
 * [MAUI_02725093] The title should be "Options "
 * .
 *
 * 09 19 2010 yiping.xie
 * [MAUI_02323105] the number's background show abnormal
 * .
 *
 * 08 03 2010 yiping.xie
 * [MAUI_02317815] [GAME] button should not display out border
 * .
 *
 * 08 03 2010 yiping.xie
 * [MAUI_02317811] [GAME] display wrong line
 * .
 *
 * 07 27 2010 yiping.xie
 * [MAUI_02597958] Games_The game display "X".
 * .
 *
 * Jul 11 2010 mtk80069
 * [MAUI_02309900] [FTE-VID]the csk no use
 * 
 *
 * Jul 11 2010 mtk80069
 * [MAUI_02309900] [FTE-VID]the csk no use
 * 
 *
 * Apr 28 2010 mtk80069
 * [MAUI_02186528] [Need Patch] [Build Error] MAUI.W10.17 build error for MT6253_EVB_gprs [MAUI_0240878
 * 
 *
 * Apr 26 2010 mtk80069
 * [MAUI_02184841] [Need Patch] [Build Error] MAUI.W10.17 build error for MT6235_EVB_gprs [MAUI_0240561
 * 
 *
 * Apr 13 2010 mtk80069
 * [MAUI_02178875] 10A modify  slideshow + Funandgame + motion Dice + motion DJ
 * 
 *
 * Apr 13 2010 mtk80069
 * [MAUI_02178875] 10A modify  slideshow + Funandgame + motion Dice + motion DJ
 * 
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "MMI_features.h"
#include "GameResDef.h"
#include "GameProts.h"
#include "CustResDef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

#if defined(__MMI_GAME__)
/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_GAMES">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="mmi_rp_app_mainmenu_def.h,GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
#ifdef IS_DANCE_BASE_GAME
   <IMAGE id="IMG_ID_GX_DANCE_GAME_ICON">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_icon.bmp"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_BACKGROUND">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_display.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_LIVEDISPLAY">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_live_display.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_LIGHTDISPLAY">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_light_display.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_SCOREDISPLAY">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_score_display.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_COMPUTER_STANDBY">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_computer_standby.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_COMPUTER_RIGHT_UP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_computer_right_up.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_COMPUTER_RIGHT_DOWN">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_computer_right_down.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_COMPUTER_LEFT_UP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_computer_left_up.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_COMPUTER_LEFT_DOWN">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_computer_left_down.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_USER_STANDBY">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_user_standby.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_USER_RIGHT_UP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_user_right_up.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_USER_RIGHT_DOWN">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_user_right_down.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_USER_LEFT_UP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_user_left_up.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_USER_LEFT_DOWN">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_user_left_down.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_USER_LIVE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_user_live.gif"</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
   <IMAGE id="IMG_ID_GX_DANCE_GAME_OVER">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gameover\\\\gx_dance_gameover.gif"</IMAGE>
#else
   <IMAGE id="IMG_ID_GX_DANCE_GAMEOVER_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\multi_lan\\\\gameover.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_GAMEOVER_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\multi_lan\\\\gameover_C.gif"</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
   <IMAGE id="IMG_ID_GX_DANCE_GRADESMAP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gameover\\\\gx_dance_gradesmap.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_PIC">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gameover\\\\gx_dance_pic.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_NUM_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_num_0.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_NUM_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_num_1.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_NUM_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_num_2.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_NUM_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_num_3.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_NUM_4">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_num_4.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_NUM_5">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_num_5.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_NUM_6">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_num_6.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_NUM_7">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_num_7.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_NUM_8">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_num_8.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_NUM_9">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_num_9.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_LIGHT_TRUE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_light_true.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_LIGHT_FALSE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_light_false.gif"</IMAGE>
   <IMAGE id="IMG_ID_GX_DANCE_LIGHT_EMPTY">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dance\\\\gx_dance_light_empty.gif"</IMAGE>
   <STRING id="STR_ID_GX_DANCE_GAME_NAME"/>
#if defined(__MMI_TOUCH_SCREEN__)
   <STRING id="STR_ID_GX_DANCE_HELP_DESCRIPTION_TP"/>
#else
   <STRING id="STR_ID_GX_DANCE_HELP_DESCRIPTION"/>
#endif /*__MMI_TOUCH_SCREEN__*/

    /* Dance NVRAM */
    <CACHEDATA type="short" id="NVRAM_GX_DANCE_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif /*IS_DANCE_BASE_GAME*/



#ifdef IS_DOLL_BASE_GAME
	<IMAGE id="IMG_GX_DOLL_GAME_ICON">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\doll_icon.bmp"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_SEAL_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\d01.bmp"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_SEAL_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\d02.bmp"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_SEAL_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\d03.bmp"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_SEAL_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\d04.bmp"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_ARM">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\arm.bmp"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_ARM_BASE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\arm_base.bmp"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_CATCHED">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\catched_doll.bmp"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_CLAW_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\claw_0.bmp"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_CLAW_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\claw_1.bmp"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_CLAW_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\claw_2.bmp"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_CLAW_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\claw_3.bmp"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_CAN_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\can_0.bmp"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_CAN_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\can_1.bmp"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_CAN_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\can_2.bmp"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_CAN_BOX">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\can_coin_box.bmp"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_NUM_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\num0.gif"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_NUM_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\num1.gif"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_NUM_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\num2.gif"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_NUM_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\num3.gif"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_NUM_4">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\num4.gif"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_NUM_5">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\num5.gif"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_NUM_6">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\num6.gif"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_NUM_7">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\num7.gif"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_NUM_8">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\num8.gif"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_NUM_9">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\num9.gif"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_NUM_10">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\num10.gif"</IMAGE>
	<IMAGE id="IMG_GX_DOLL_SMALLDOLL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\dollsmall.bmp"</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_GX_DOLL_GOTEXT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\gameover\\\\gameover.bmp"</IMAGE>
#else
       <IMAGE id="IMG_GX_DOLL_GOTEXT_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\multi_lan\\\\gameover.bmp"</IMAGE>
       <IMAGE id="IMG_GX_DOLL_GOTEXT_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\multi_lan\\\\gameover_C.bmp"</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
	<IMAGE id="IMG_GX_DOLL_GRADESMAP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Doll\\\\gameover\\\\gradesmap.bmp"</IMAGE>
	<STRING id="STR_GX_DOLL_GAME_NAME"/>
	<STRING id="STR_GX_DOLL_HELP_DESCRIPTION"/>

    /* Doll NVRAM */
    <CACHEDATA type="short" id="NVRAM_GAME_DOLL_GRADE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif /*IS_DOLL_BASE_GAME*/



#ifdef __MMI_GAME_F1RACE__
	<STRING id="STR_GX_F1RACE_GAME_NAME"/>
	<STRING id="STR_GX_F1RACE_HELP_DESCRIPTION"/>
	<IMAGE id="IMG_GX_F1RACE_GAME_ICON">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\Race.BMP"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_PLAYER_CAR">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_PLAYER_CAR.GIF"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_PLAYER_CAR_FLY">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_PLAYER_CAR_FLY.GIF"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_PLAYER_CAR_FLY_DOWN">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_PLAYER_CAR_FLY_DOWN.GIF"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_PLAYER_CAR_FLY_UP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_PLAYER_CAR_FLY_UP.GIF"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_PLAYER_CAR_CRASH">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_PLAYER_CAR_CRASH.GIF"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_OPPOSITE_CAR_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_OPPOSITE_CAR_0.GIF"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_OPPOSITE_CAR_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_OPPOSITE_CAR_1.GIF"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_OPPOSITE_CAR_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_OPPOSITE_CAR_2.GIF"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_OPPOSITE_CAR_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_OPPOSITE_CAR_3.GIF"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_OPPOSITE_CAR_4">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_OPPOSITE_CAR_4.GIF"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_OPPOSITE_CAR_5">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_OPPOSITE_CAR_5.GIF"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_OPPOSITE_CAR_6">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_OPPOSITE_CAR_6.GIF"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_PLAYER_CAR_HEAD_LIGHT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_PLAYER_CAR_HEAD_LIGHT.GIF"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_STATUS_LOGO">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_LOGO.BMP"</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_GX_F1RACE_STATUS_SCORE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_STATUS_SCORE.GIF"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_STATUS_LEVEL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_STATUS_LEVEL.GIF"</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
	<IMAGE id="IMG_GX_F1RACE_STATUS_BOX">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_STATUS_BOX.GIF"</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_GX_F1RACE_STATUS_FLY">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_STATUS_FLY.GIF"</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
	<IMAGE id="IMG_GX_F1RACE_NUMBER_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_0.gif"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_NUMBER_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_1.gif"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_NUMBER_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_2.gif"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_NUMBER_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_3.gif"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_NUMBER_4">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_4.gif"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_NUMBER_5">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_5.gif"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_NUMBER_6">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_6.gif"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_NUMBER_7">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_7.gif"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_NUMBER_8">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_8.gif"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_NUMBER_9">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_9.gif"</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_GX_F1RACE_GOTEXT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\gameover\\\\gameover.bmp"</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
	<IMAGE id="IMG_GX_F1RACE_GRADESMAP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\gameover\\\\gradesmap.bmp"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_GOPIC">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\gameover\\\\pic.bmp"</IMAGE>
#ifdef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_GX_F1RACE_STATUS_SCORE_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\GAME_F1RACE_STATUS_SCORE.gif"</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_STATUS_LEVEL_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\GAME_F1RACE_STATUS_LEVEL.GIF"</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_STATUS_FLY_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\GAME_F1RACE_STATUS_FLY.GIF"</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_GOTEXT_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\gameover.bmp"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_STATUS_SCORE_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\GAME_F1RACE_STATUS_SCORE_C.GIF"</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_STATUS_LEVEL_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\GAME_F1RACE_STATUS_LEVEL_C.GIF"</IMAGE>
	<IMAGE id="IMG_GX_F1RACE_STATUS_FLY_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\GAME_F1RACE_STATUS_FLY_C.GIF"</IMAGE>
    <IMAGE id="IMG_GX_F1RACE_GOTEXT_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\gameover_C.bmp"</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

    /* F1RACE NVRAM */
    <CACHEDATA type="short" id="NVRAM_F1RACE_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif /*__MMI_GAME_F1RACE__*/



#ifdef __MMI_GAME_SMASH__
	<STRING id="STR_GX_SMASH_GAME_NAME"/>
	<STRING id="STR_GX_SMASH_TIME_SEC"/>
	<STRING id="STR_GX_SMASH_NORMAL"/>
	<STRING id="STR_GX_SMASH_SPEEDY"/>
	<STRING id="STR_GX_SMASH_ACCURACY"/>
	<STRING id="STR_GX_SMASH_HELP_DESCRIPTION"/>
	<IMAGE id="IMG_GX_SMASH_GAME_ICON">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\smash.BMP"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_BG_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_0.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_BG_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_1.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_BG_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_2.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_BG_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_3.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_BG_4">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_4.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_BG_5">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_5.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_BG_6">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_6.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_BG_7">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_7.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_BG_8">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_8.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_MOUSE_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\mouse\\\\m_01.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_MOUSE_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\mouse\\\\m_02.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_MOUSE_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\mouse\\\\m_03.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_MOUSE_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\mouse\\\\m_04.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_MOUSE_4">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\mouse\\\\m_05.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_MOUSE_5">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\mouse\\\\m_06.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_COW_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\cow\\\\c_01.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_COW_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\cow\\\\c_02.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_COW_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\cow\\\\c_03.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_COW_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\cow\\\\c_04.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_COW_4">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\cow\\\\c_05.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_COW_5">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\cow\\\\c_06.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_BONE_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bone\\\\b_01.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_BONE_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bone\\\\b_02.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_BONE_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bone\\\\b_03.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_BONE_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bone\\\\b_04.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_BONE_4">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bone\\\\b_05.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_BONE_5">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bone\\\\b_06.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_PIG_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\pig\\\\p_01.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_PIG_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\pig\\\\p_02.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_PIG_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\pig\\\\p_03.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_PIG_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\pig\\\\p_04.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_PIG_4">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\pig\\\\p_05.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_PIG_5">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\pig\\\\p_06.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_HAND_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\hand\\\\hand01.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_HAND_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\hand\\\\hand03.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_GRADESMAP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\gameover\\\\gradesmap.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_GOPIC">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\gameover\\\\pic.bmp"</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__   
    <IMAGE id="IMG_GX_SMASH_HITTHIS">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\hitthis.gif"</IMAGE>
    <IMAGE id="IMG_GX_SMASH_GOTEXT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\gameover\\\\gameover.bmp"</IMAGE>
#else /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_GX_SMASH_SCORE_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_1.bmp"</IMAGE>
    <IMAGE id="IMG_GX_SMASH_HITTHIS_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\hitthis.gif"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_GOTEXT_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\gameover\\\\gameover.bmp"</IMAGE>
    <IMAGE id="IMG_GX_SMASH_SCORE_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\multi_lan\\\\bg_1_C.bmp"</IMAGE>
    <IMAGE id="IMG_GX_SMASH_HITTHIS_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\multi_lan\\\\hitthis_C.gif"</IMAGE>
	<IMAGE id="IMG_GX_SMASH_GOTEXT_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\multi_lan\\\\gameover_C.bmp"</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

    /* Smash NVRAM */    
    <CACHEDATA type="byte" id="SMASH_CURRENT_LEVEL">
        <DEFAULT_VALUE> [0XFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_SMASH_NORMAL_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_SMASH_SPEEDY_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_SMASH_ACCURACY_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif /*__MMI_GAME_SMASH__*/

#ifdef IS_RICHES_BASE_GAME
	<STRING id="STR_GX_RICHES_GAME_NAME"/>
	<STRING id="STR_GX_RICHES_EASY"/>
	<STRING id="STR_GX_RICHES_NORMAL"/>
	<STRING id="STR_GX_RICHES_HARD"/>
	<STRING id="STR_GX_RICHES_HELP_DESCRIPTION"/>
	<IMAGE id="IMG_GX_RICHES_GAME_ICON">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\riches.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_BASKET">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\basket.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_OBJECT_APPLE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\apple.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_OBJECT_BOMB">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\bomb.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_OBJECT_GIFT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\gift.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_OBJECT_GOLDNOTE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\goldnote.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_OBJECT_SPIDER">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\spider.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_OBJECT_ANGLE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\angel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_OBJECT_BATTERY20">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\bluebattery.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_OBJECT_DENONATOR">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\detonator.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_OBJECT_EVIL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\evil.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_OBJECT_MONEY">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\money.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_OBJECT_BATTERYFULL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\redbattery.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_OBJECT_THEIF">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\thief.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_ENERGYBG">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\energy\\\\energybg.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_ENERGYBAR">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\energy\\\\enerygybar.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_OBJECT_BAT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\bat.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_OBJECT_ENERGY20">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\energy\\\\1.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_OBJECT_ENERGY40">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\energy\\\\2.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_OBJECT_ENERGY60">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\energy\\\\3.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_OBJECT_ENERGY80">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\energy\\\\4.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_OBJECT_ENERGY100">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\energy\\\\5.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_OBJECT_LEVEL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\level\\\\basket.bmp"</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_GX_RICHES_BACKGROUND">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\map\\\\bg.gif"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_BACKGROUND_TIMER">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\map\\\\timer.gif"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_BACKGROUND_LEVEL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\map\\\\level.gif"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_GOTEXT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\gameover\\\\gameover.bmp"</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
	<IMAGE id="IMG_GX_RICHES_GRADESMAP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\gameover\\\\gradesmap.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_GOPIC">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\gameover\\\\pic.bmp"</IMAGE>
#ifdef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_GX_RICHES_BACKGROUND_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\map\\\\bg.gif"</IMAGE>
    <IMAGE id="IMG_GX_RICHES_BACKGROUND_TIMER_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\map\\\\timer.gif"</IMAGE>
    <IMAGE id="IMG_GX_RICHES_BACKGROUND_LEVEL_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\map\\\\level.gif"</IMAGE>
    <IMAGE id="IMG_GX_RICHES_GOTEXT_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\multi_lan\\\\gameover.bmp"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_BACKGROUND_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\multi_lan\\\\bg_C.gif"</IMAGE>
    <IMAGE id="IMG_GX_RICHES_BACKGROUND_TIMER_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\multi_lan\\\\timer_C.gif"</IMAGE>
	<IMAGE id="IMG_GX_RICHES_BACKGROUND_LEVEL_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\multi_lan\\\\level_C.gif"</IMAGE>
    <IMAGE id="IMG_GX_RICHES_GOTEXT_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\multi_lan\\\\gameover_C.bmp"</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

    /* Riches NVRAM */
    <CACHEDATA type="byte" id="NVRAM_GAME_RICHES_STATUS" restore_flag="TRUE">
        <DEFAULT_VALUE> [0XFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_RICHES_OPTION_STATUS" restore_flag="TRUE">
        <DEFAULT_VALUE> [0XFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_RICHES_EASY_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_RICHES_NORMAL_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_RICHES_HARD_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif /*IS_RICHES_BASE_GAME*/


#ifdef IS_SNAKE_BASE_GAME
	<IMAGE id="IMG_GX_SNAKE_GAME_ICON">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\snake.BMP"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_SNAKE_HEAD_UP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_HEAD_UP.BMP"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_SNAKE_HEAD_DOWN">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_HEAD_DOWN.BMP"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_SNAKE_HEAD_RIGHT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_HEAD_RIGHT.BMP"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_SNAKE_HEAD_LEFT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_HEAD_LEFT.BMP"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_SNAKE_BODY_UP_DOWN">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_BODY_UP_DOWN.BMP"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_SNAKE_BODY_RIGHT_LEFT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_BODY_RIGHT_LEFT.BMP"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_SNAKE_BODY_UP_RIGHT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_BODY_UP_RIGHT.BMP"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_SNAKE_BODY_UP_LEFT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_BODY_UP_LEFT.BMP"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_SNAKE_BODY_DOWN_RIGHT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_BODY_DOWN_RIGHT.BMP"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_SNAKE_BODY_DOWN_LEFT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_BODY_DOWN_LEFT.BMP"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_SNAKE_TAIL_UP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_TAIL_UP.BMP"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_SNAKE_TAIL_DOWN">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_TAIL_DOWN.BMP"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_SNAKE_TAIL_RIGHT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_TAIL_RIGHT.BMP"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_SNAKE_TAIL_LEFT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_SNAKE_TAIL_LEFT.BMP"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_EGG">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_EGG.BMP"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_EGG_NEXT_STAGE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_EGG_NEXT_STAGE.BMP"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_NUMBER_0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_NUMBER_0.gif"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_NUMBER_1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_NUMBER_1.gif"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_NUMBER_2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_NUMBER_2.gif"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_NUMBER_3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_NUMBER_3.gif"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_NUMBER_4">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_NUMBER_4.gif"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_NUMBER_5">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_NUMBER_5.gif"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_NUMBER_6">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_NUMBER_6.gif"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_NUMBER_7">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_NUMBER_7.gif"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_NUMBER_8">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_NUMBER_8.gif"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_NUMBER_9">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_NUMBER_9.gif"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_WALL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_WALL.bmp"</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_GX_SNAKE_GOTEXT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\gameover\\\\gameover.bmp"</IMAGE>
        <IMAGE id="IMG_GX_SNAKE_STAGE_TXT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_STAGE_TXT.gif"</IMAGE>
#else /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_GX_SNAKE_GOTEXT_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\multi_lan\\\\gameover.bmp"</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_STAGE_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\GAME_SNAKE_STAGE_TXT.gif"</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_GOTEXT_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\multi_lan\\\\gameover_C.bmp"</IMAGE>
    <IMAGE id="IMG_GX_SNAKE_STAGE_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\multi_lan\\\\STAGE_C.gif"</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
	<IMAGE id="IMG_GX_SNAKE_GRADESMAP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\gameover\\\\gradesmap.bmp"</IMAGE>
	<IMAGE id="IMG_GX_SNAKE_GOPIC">CUST_IMG_BASE_PATH"\\\\GameImages\\\\snake\\\\gameover\\\\pic.bmp"</IMAGE>
	<STRING id="STR_GX_SNAKE_GAME_NAME"/>
	<STRING id="STR_GX_SNAKE_EASY"/>
	<STRING id="STR_GX_SNAKE_NORMAL"/>
	<STRING id="STR_GX_SNAKE_HARD"/>
	<STRING id="STR_GX_SNAKE_HELP_DESCRIPTION"/>

    /* Snake NVRAM */
    <CACHEDATA type="byte" id="NVRAM_GAME_SNAKE_LEVEL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0XFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_SNAKE_LEVEL1_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_SNAKE_LEVEL2_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0X00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_SNAKE_LEVEL3_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_SNAKE_LEVEL4_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif /*IS_SNAKE_BASE_GAME*/

#ifdef IS_HANOI_BASE_GAME
	<STRING id="STR_GX_TOH_GAME_NAME"/>
	<STRING id="STR_GX_TOH_TITLE"/>
	<STRING id="STR_GX_TOH_LEVEL"/>
	<STRING id="STR_GX_TOH_SEC"/>
	<STRING id="STR_GX_TOH_LEVEL1"/>
	<STRING id="STR_GX_TOH_LEVEL2"/>
	<STRING id="STR_GX_TOH_LEVEL3"/>
	<STRING id="STR_GX_TOH_LEVEL4"/>
	<STRING id="STR_GX_TOH_HELP_DESCRIPTION"/>
	<IMAGE id="IMG_GX_TOH_GAME_ICON">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\hanoi.BMP"</IMAGE>
	<IMAGE id="IMG_GX_TOH_BRICK1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\1brick.bmp"</IMAGE>
	<IMAGE id="IMG_GX_TOH_BRICK1_HL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\1brick_h.bmp"</IMAGE>
	<IMAGE id="IMG_GX_TOH_BRICK2">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\2brick.bmp"</IMAGE>
	<IMAGE id="IMG_GX_TOH_BRICK2_HL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\2brick_h.bmp"</IMAGE>
	<IMAGE id="IMG_GX_TOH_BRICK3">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\3brick.bmp"</IMAGE>
	<IMAGE id="IMG_GX_TOH_BRICK3_HL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\3brick_h.bmp"</IMAGE>
	<IMAGE id="IMG_GX_TOH_BRICK4">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\4brick.bmp"</IMAGE>
	<IMAGE id="IMG_GX_TOH_BRICK4_HL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\4brick_h.bmp"</IMAGE>
	<IMAGE id="IMG_GX_TOH_BRICK5">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\5brick.bmp"</IMAGE>
	<IMAGE id="IMG_GX_TOH_BRICK5_HL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\5brick_h.bmp"</IMAGE>
	<IMAGE id="IMG_GX_TOH_BRICK6">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\6brick.bmp"</IMAGE>
	<IMAGE id="IMG_GX_TOH_BRICK6_HL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\bricks\\\\6brick_h.bmp"</IMAGE>
	<IMAGE id="IMG_GX_TOH_LEVEL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\level\\\\2.bmp"</IMAGE>
	<IMAGE id="IMG_GX_TOH_LEVEL_HL">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\level\\\\1.bmp"</IMAGE>
	<IMAGE id="IMG_GX_TOH_BG">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\map\\\\bgpicture.bmp"</IMAGE>
	<IMAGE id="IMG_GX_TOH_TOWER">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\tower bar\\\\tower bar.bmp"</IMAGE>
	<IMAGE id="IMG_GX_TOH_TOWER_IN">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\Indicator\\\\finger.bmp"</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_GX_TOH_GOTEXT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\gameover\\\\gameover.bmp"</IMAGE>
#else /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_GX_TOH_GOTEXT_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\gameover\\\\gameover.bmp"</IMAGE>
    <IMAGE id="IMG_GX_TOH_LEVEL_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\multi_lan\\\\level_E.gif"</IMAGE>
    <IMAGE id="IMG_GX_TOH_GOTEXT_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\multi_lan\\\\gameover_C.bmp"</IMAGE>
    <IMAGE id="IMG_GX_TOH_LEVEL_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\multi_lan\\\\level_C.gif"</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
	<IMAGE id="IMG_GX_TOH_GRADESMAP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\gameover\\\\gradesmap.bmp"</IMAGE>
	<IMAGE id="IMG_GX_TOH_GOPIC">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\gameover\\\\pic.bmp"</IMAGE>
	<IMAGE id="IMG_GX_TOH_TITLEBAR">CUST_IMG_BASE_PATH"\\\\GameImages\\\\Hanoi\\\\titlebar\\\\titlebar.bmp"</IMAGE>

    /* Hanoi NVRAM */
    <CACHEDATA type="byte" id="TOH_CURRENT_LEVEL" restore_flag="TRUE">
            <DEFAULT_VALUE> [0XFF] </DEFAULT_VALUE>
            <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="TOH_LEVEL1_HIGHEST_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="TOH_LEVEL2_HIGHEST_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="TOH_LEVEL3_HIGHEST_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="TOH_LEVEL4_HIGHEST_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif /*IS_HANOI_BASE_GAME*/


#ifdef IS_COLORBALL_BASE_GAME
	<STRING id="STR_GX_COLORBALLS_GAME_NAME"/>
	<STRING id="STR_GX_COLORBALLS_EASY"/>
	<STRING id="STR_GX_COLORBALLS_NORMAL"/>
	<STRING id="STR_GX_COLORBALLS_HARD"/>
	<STRING id="STR_GX_COLORBALLS_DESCRIPTION"/>
	<IMAGE id="IMG_GX_COLORBALLS_GAME_ICON">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\colorball.bmp"</IMAGE>
	<IMAGE id="IMG_GX_COLORBALLS_BIG_BLUE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\bigball\\\\blue.bmp"</IMAGE>
	<IMAGE id="IMG_GX_COLORBALLS_BIG_GREEN">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\bigball\\\\green.bmp"</IMAGE>
	<IMAGE id="IMG_GX_COLORBALLS_BIG_LIGHT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\bigball\\\\light.bmp"</IMAGE>
	<IMAGE id="IMG_GX_COLORBALLS_BIG_PINK">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\bigball\\\\pink.bmp"</IMAGE>
	<IMAGE id="IMG_GX_COLORBALLS_SMALL_BLUE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\smallball\\\\blue.bmp"</IMAGE>
	<IMAGE id="IMG_GX_COLORBALLS_SMALL_GREEN">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\smallball\\\\green.bmp"</IMAGE>
	<IMAGE id="IMG_GX_COLORBALLS_SMALL_LIGHT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\smallball\\\\light.bmp"</IMAGE>
	<IMAGE id="IMG_GX_COLORBALLS_SMALL_PINK">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\smallball\\\\pink.bmp"</IMAGE>
	<IMAGE id="IMG_GX_COLORBALLS_SCORE">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\map\\\\gradesmap.bmp"</IMAGE>
	<IMAGE id="IMG_GX_COLORBALLS_LAUNCH">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\map\\\\indicator.bmp"</IMAGE>
	<IMAGE id="IMG_GX_COLORBALLS_ENERGYBG">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\map\\\\energymap.bmp"</IMAGE>
	<IMAGE id="IMG_GX_COLORBALLS_GRADEBG">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\map\\\\gradesmap.bmp"</IMAGE>
	<IMAGE id="IMG_GX_COLORBALLS_LEVELBG">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\map\\\\levelmap.bmp"</IMAGE>
	<IMAGE id="IMG_GX_COLORBALLS_ENERGYBAR">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\energy\\\\bar.bmp"</IMAGE>
#ifndef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_GX_COLORBALLS_GOTEXT">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\gameover\\\\gameover.bmp"</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_BG">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\map\\\\bg.gif"</IMAGE>
#else /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_GX_COLORBALLS_BG">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\multi_lan\\\\bg.gif"</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_LEVEL_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\multi_lan\\\\level_E.gif"</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_GRADE_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\multi_lan\\\\grade_E.gif"</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_ENERGY_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\multi_lan\\\\power_E.gif"</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_GOTEXT_LANGUAGE0">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\multi_lan\\\\gameover.bmp"</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_LEVEL_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\multi_lan\\\\level_C.gif"</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_GRADE_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\multi_lan\\\\grade_C.gif"</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_ENERGY_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\multi_lan\\\\power_C.gif"</IMAGE>
    <IMAGE id="IMG_GX_COLORBALLS_GOTEXT_LANGUAGE1">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\multi_lan\\\\gameover_C.bmp"</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
	<IMAGE id="IMG_GX_COLORBALLS_GRADESMAP">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\gameover\\\\gradesmap.bmp"</IMAGE>
	<IMAGE id="IMG_GX_COLORBALLS_GOPIC">CUST_IMG_BASE_PATH"\\\\GameImages\\\\colorball\\\\gameover\\\\pic.bmp"</IMAGE>

    /* ColorBalls NVRAM */
    <CACHEDATA type="byte" id="NVRAM_COLORBALLS_OPTION_STATUS" restore_flag="TRUE">
        <DEFAULT_VALUE> [0XFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_COLORBALLS_EASY_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_COLORBALLS_NORMAL_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_COLORBALLS_HARD_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif /*IS_COLORBALL_BASE_GAME*/


#ifdef IS_MAJUNG_BASE_GAME
#if defined(__MMI_GAME_MAJUNG_176x220__)
	#define MAJUNG_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\majung\\\\majung_176x220_majung\\\\"
#elif defined(__MMI_GAME_MAJUNG_240x320__)
	#define MAJUNG_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\majung\\\\majung_240x320_majung\\\\"
#elif defined(__MMI_GAME_MAJUNG_320x240__)
	#define MAJUNG_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\majung\\\\majung_320x240_majung\\\\"
#elif defined(__MMI_GAME_MAJUNG_240x400__)
	#define MAJUNG_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\majung\\\\majung_240x400_majung\\\\"
#elif defined(__MMI_GAME_MAJUNG_320x480__)
	#define MAJUNG_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\majung\\\\majung_320x480_majung\\\\"
#endif
	<STRING id="STR_GX_MAJUNG_GAME_NAME"/>
	<STRING id="STR_GX_MAJUNG_LEVEL_EASY"/>
	<STRING id="STR_GX_MAJUNG_LEVEL_NORMAL"/>
	<STRING id="STR_GX_MAJUNG_LEVEL_HARD"/>
	<STRING id="STR_GX_MAJUNG_HELP_DESCRIPTION"/>
	<IMAGE id="IMG_GX_MAJUNG_GAME_ICON">MAJUNG_IMG_PATH"majung_icon.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_1W">MAJUNG_IMG_PATH"brick_1w.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_2W">MAJUNG_IMG_PATH"brick_2w.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_3W">MAJUNG_IMG_PATH"brick_3w.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_4W">MAJUNG_IMG_PATH"brick_4w.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_5W">MAJUNG_IMG_PATH"brick_5w.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_6W">MAJUNG_IMG_PATH"brick_6w.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_7W">MAJUNG_IMG_PATH"brick_7w.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_8W">MAJUNG_IMG_PATH"brick_8w.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_9W">MAJUNG_IMG_PATH"brick_9w.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_2S">MAJUNG_IMG_PATH"brick_2s.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_3S">MAJUNG_IMG_PATH"brick_3s.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_4S">MAJUNG_IMG_PATH"brick_4s.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_5S">MAJUNG_IMG_PATH"brick_5s.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_6S">MAJUNG_IMG_PATH"brick_6s.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_7S">MAJUNG_IMG_PATH"brick_7s.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_8S">MAJUNG_IMG_PATH"brick_8s.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_9S">MAJUNG_IMG_PATH"brick_9s.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_1T">MAJUNG_IMG_PATH"brick_1t.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_2T">MAJUNG_IMG_PATH"brick_2t.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_3T">MAJUNG_IMG_PATH"brick_3t.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_4T">MAJUNG_IMG_PATH"brick_4t.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_5T">MAJUNG_IMG_PATH"brick_5t.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_6T">MAJUNG_IMG_PATH"brick_6t.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_7T">MAJUNG_IMG_PATH"brick_7t.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_8T">MAJUNG_IMG_PATH"brick_8t.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_9T">MAJUNG_IMG_PATH"brick_9t.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_A">MAJUNG_IMG_PATH"brick_a.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_B">MAJUNG_IMG_PATH"brick_b.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_C">MAJUNG_IMG_PATH"brick_c.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_D">MAJUNG_IMG_PATH"brick_d.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_F">MAJUNG_IMG_PATH"brick_f.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_G">MAJUNG_IMG_PATH"brick_g.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_H">MAJUNG_IMG_PATH"brick_h.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_1W_SEL">MAJUNG_IMG_PATH"brick_1w_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_2W_SEL">MAJUNG_IMG_PATH"brick_2w_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_3W_SEL">MAJUNG_IMG_PATH"brick_3w_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_4W_SEL">MAJUNG_IMG_PATH"brick_4w_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_5W_SEL">MAJUNG_IMG_PATH"brick_5w_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_6W_SEL">MAJUNG_IMG_PATH"brick_6w_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_7W_SEL">MAJUNG_IMG_PATH"brick_7w_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_8W_SEL">MAJUNG_IMG_PATH"brick_8w_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_9W_SEL">MAJUNG_IMG_PATH"brick_9w_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_2S_SEL">MAJUNG_IMG_PATH"brick_2s_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_3S_SEL">MAJUNG_IMG_PATH"brick_3s_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_4S_SEL">MAJUNG_IMG_PATH"brick_4s_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_5S_SEL">MAJUNG_IMG_PATH"brick_5s_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_6S_SEL">MAJUNG_IMG_PATH"brick_6s_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_7S_SEL">MAJUNG_IMG_PATH"brick_7s_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_8S_SEL">MAJUNG_IMG_PATH"brick_8s_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_9S_SEL">MAJUNG_IMG_PATH"brick_9s_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_1T_SEL">MAJUNG_IMG_PATH"brick_1t_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_2T_SEL">MAJUNG_IMG_PATH"brick_2t_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_3T_SEL">MAJUNG_IMG_PATH"brick_3t_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_4T_SEL">MAJUNG_IMG_PATH"brick_4t_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_5T_SEL">MAJUNG_IMG_PATH"brick_5t_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_6T_SEL">MAJUNG_IMG_PATH"brick_6t_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_7T_SEL">MAJUNG_IMG_PATH"brick_7t_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_8T_SEL">MAJUNG_IMG_PATH"brick_8t_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_9T_SEL">MAJUNG_IMG_PATH"brick_9t_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_A_SEL">MAJUNG_IMG_PATH"brick_a_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_B_SEL">MAJUNG_IMG_PATH"brick_b_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_C_SEL">MAJUNG_IMG_PATH"brick_c_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_D_SEL">MAJUNG_IMG_PATH"brick_d_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_F_SEL">MAJUNG_IMG_PATH"brick_f_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_G_SEL">MAJUNG_IMG_PATH"brick_g_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BRICK_H_SEL">MAJUNG_IMG_PATH"brick_h_sel.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_CONNECT_HOR">MAJUNG_IMG_PATH"connect_hor.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_CONNECT_VER">MAJUNG_IMG_PATH"connect_ver.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_CONNECT_LU">MAJUNG_IMG_PATH"connect_lu.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_CONNECT_RU">MAJUNG_IMG_PATH"connect_ru.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_CONNECT_LD">MAJUNG_IMG_PATH"connect_ld.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_CONNECT_RD">MAJUNG_IMG_PATH"connect_rd.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_THICK">MAJUNG_IMG_PATH"thick.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_FILL_1">MAJUNG_IMG_PATH"bar_fill_01.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_FILL_2">MAJUNG_IMG_PATH"bar_fill_02.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_FILL_3">MAJUNG_IMG_PATH"bar_fill_03.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_FILL_4">MAJUNG_IMG_PATH"bar_fill_04.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_FILL_5">MAJUNG_IMG_PATH"bar_fill_05.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_FILL_6">MAJUNG_IMG_PATH"bar_fill_06.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_FILL_7">MAJUNG_IMG_PATH"bar_fill_07.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_FILL_8">MAJUNG_IMG_PATH"bar_fill_08.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_FILL_9">MAJUNG_IMG_PATH"bar_fill_09.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_FILL_10">MAJUNG_IMG_PATH"bar_fill_10.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_FILL_11">MAJUNG_IMG_PATH"bar_fill_11.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_FILL_12">MAJUNG_IMG_PATH"bar_fill_12.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_FILL_13">MAJUNG_IMG_PATH"bar_fill_13.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_FILL_14">MAJUNG_IMG_PATH"bar_fill_14.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_FILL_15">MAJUNG_IMG_PATH"bar_fill_15.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_FILL_16">MAJUNG_IMG_PATH"bar_fill_16.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_FILL_17">MAJUNG_IMG_PATH"bar_fill_17.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_FILL_18">MAJUNG_IMG_PATH"bar_fill_18.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_FILL_19">MAJUNG_IMG_PATH"bar_fill_19.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_FILL_20">MAJUNG_IMG_PATH"bar_fill_20.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_1">MAJUNG_IMG_PATH"bar_empty_01.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_2">MAJUNG_IMG_PATH"bar_empty_02.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_3">MAJUNG_IMG_PATH"bar_empty_03.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_4">MAJUNG_IMG_PATH"bar_empty_04.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_5">MAJUNG_IMG_PATH"bar_empty_05.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_6">MAJUNG_IMG_PATH"bar_empty_06.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_7">MAJUNG_IMG_PATH"bar_empty_07.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_8">MAJUNG_IMG_PATH"bar_empty_08.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_9">MAJUNG_IMG_PATH"bar_empty_09.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_10">MAJUNG_IMG_PATH"bar_empty_10.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_11">MAJUNG_IMG_PATH"bar_empty_11.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_12">MAJUNG_IMG_PATH"bar_empty_12.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_13">MAJUNG_IMG_PATH"bar_empty_13.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_14">MAJUNG_IMG_PATH"bar_empty_14.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_15">MAJUNG_IMG_PATH"bar_empty_15.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_16">MAJUNG_IMG_PATH"bar_empty_16.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_17">MAJUNG_IMG_PATH"bar_empty_17.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_18">MAJUNG_IMG_PATH"bar_empty_18.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_19">MAJUNG_IMG_PATH"bar_empty_19.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_BAR_EMPTY_20">MAJUNG_IMG_PATH"bar_empty_20.bmp"</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_GX_MAJUNG_GAMEOVER">MAJUNG_IMG_PATH"gameover.bmp"</IMAGE>
#else /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_GX_MAJUNG_GAMEOVER_LANGUAGE0">MAJUNG_IMG_PATH"gameover.bmp"</IMAGE>
    <IMAGE id="IMG_GX_MAJUNG_GAMEOVER_LANGUAGE1">MAJUNG_IMG_PATH"multi_lan\\\\gameover_c.bmp"</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
	<IMAGE id="IMG_GX_MAJUNG_GRADESMAP">MAJUNG_IMG_PATH"gradesmap.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_COUNT">MAJUNG_IMG_PATH"count.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_0">MAJUNG_IMG_PATH"MAJUNG_NUMBER_0.gif"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_1">MAJUNG_IMG_PATH"MAJUNG_NUMBER_1.gif"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_2">MAJUNG_IMG_PATH"MAJUNG_NUMBER_2.gif"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_3">MAJUNG_IMG_PATH"MAJUNG_NUMBER_3.gif"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_4">MAJUNG_IMG_PATH"MAJUNG_NUMBER_4.gif"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_5">MAJUNG_IMG_PATH"MAJUNG_NUMBER_5.gif"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_6">MAJUNG_IMG_PATH"MAJUNG_NUMBER_6.gif"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_7">MAJUNG_IMG_PATH"MAJUNG_NUMBER_7.gif"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_8">MAJUNG_IMG_PATH"MAJUNG_NUMBER_8.gif"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_9">MAJUNG_IMG_PATH"MAJUNG_NUMBER_9.gif"</IMAGE>
	
	<IMAGE id="IMG_GX_MAJUNG_BOX">MAJUNG_IMG_PATH"MAJUNG_box.gif"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_EXIT_UP">MAJUNG_IMG_PATH"MAJUNG_exit_up.bmp"</IMAGE>
	<IMAGE id="IMG_GX_MAJUNG_EXIT_DOWN">MAJUNG_IMG_PATH"MAJUNG_exit_down.bmp"</IMAGE>

    /* Majung NVRAM */
    <CACHEDATA type="byte" id="NVRAM_GX_MAJUNG_LEVEL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_MAJUNG_EASY_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_MAJUNG_NORMAL_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_MAJUNG_HARD_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif /*IS_MAJUNG_BASE_GAME*/


#ifdef IS_COPTER_BASE_GAME
#if defined(__MMI_GAME_COPTER_128x128__)
	#define COPTER_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\copter\\\\copter_128x128_copter\\\\"
#elif defined(__MMI_GAME_COPTER_128x160__)
	#define COPTER_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\copter\\\\copter_128x160_copter\\\\"
#elif defined(__MMI_GAME_COPTER_176x220__)
	#define COPTER_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\copter\\\\copter_176x220_copter\\\\"
#elif defined(__MMI_GAME_SUBMARINE_128x128__)
	#define COPTER_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\copter\\\\copter_128x128_submarine\\\\"
#elif defined(__MMI_GAME_SUBMARINE_128x160__)
	#define COPTER_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\copter\\\\copter_128x160_submarine\\\\"
#elif defined(__MMI_GAME_SUBMARINE_176x220__)
	#define COPTER_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\copter\\\\copter_176x220_submarine\\\\"
#elif defined(__MMI_GAME_JET_128x128__)
	#define COPTER_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\copter\\\\copter_128x128_jet\\\\"
#elif defined(__MMI_GAME_JET_128x160__)
	#define COPTER_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\copter\\\\copter_128x160_jet\\\\"
#elif defined(__MMI_GAME_JET_176x220__)
	#define COPTER_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\copter\\\\copter_176x220_jet\\\\"
#endif
#if defined(__MMI_GAME_COPTER_128x128__) || defined(__MMI_GAME_COPTER_128x160__) || defined(__MMI_GAME_COPTER_176x220__)
	<STRING id="STR_ID_GX_COPTER_GAME_NAME"/>
	#if defined(__MMI_TOUCH_SCREEN__)
	<STRING id="STR_ID_GX_COPTER_HELP_DESCRIPTION_TP"/>
	#else
	<STRING id="STR_ID_GX_COPTER_HELP_DESCRIPTION"/>
	#endif
#elif defined(__MMI_GAME_SUBMARINE_128x128__) || defined(__MMI_GAME_SUBMARINE_128x160__) || defined(__MMI_GAME_SUBMARINE_176x220__)
	<STRING id="STR_ID_GX_COPTER_GAME_NAME_SUBMARINE"/>
	#if defined(__MMI_TOUCH_SCREEN__)
	<STRING id="STR_ID_GX_COPTER_HELP_DESCRIPTION_SUBMARINE_TP"/>
	#else
	<STRING id="STR_ID_GX_COPTER_HELP_DESCRIPTION_SUBMARINE"/>
	#endif
#elif defined(__MMI_GAME_JET_128x128__) || defined(__MMI_GAME_JET_128x160__) || defined(__MMI_GAME_JET_176x220__)
	<STRING id="STR_ID_GX_COPTER_GAME_NAME_JET"/>
	#if defined(__MMI_TOUCH_SCREEN__)
	<STRING id="STR_ID_GX_COPTER_HELP_DESCRIPTION_JET_TP"/>
	#else
	<STRING id="STR_ID_GX_COPTER_HELP_DESCRIPTION_JET"/>
	#endif
#endif
	<IMAGE id="IMG_ID_GX_COPTER_GAME_ICON">COPTER_IMG_PATH"gx_copter_copter_icon.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_COPTER_OBSTACLE">COPTER_IMG_PATH"gx_copter_obstacle.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_COPTER_NUMBER_0">COPTER_IMG_PATH"gx_copter_number_0.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_COPTER_NUMBER_1">COPTER_IMG_PATH"gx_copter_number_1.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_COPTER_NUMBER_2">COPTER_IMG_PATH"gx_copter_number_2.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_COPTER_NUMBER_3">COPTER_IMG_PATH"gx_copter_number_3.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_COPTER_NUMBER_4">COPTER_IMG_PATH"gx_copter_number_4.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_COPTER_NUMBER_5">COPTER_IMG_PATH"gx_copter_number_5.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_COPTER_NUMBER_6">COPTER_IMG_PATH"gx_copter_number_6.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_COPTER_NUMBER_7">COPTER_IMG_PATH"gx_copter_number_7.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_COPTER_NUMBER_8">COPTER_IMG_PATH"gx_copter_number_8.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_COPTER_NUMBER_9">COPTER_IMG_PATH"gx_copter_number_9.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_COPTER_BOX">COPTER_IMG_PATH"gx_copter_box.gif"</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_ID_GX_COPTER_SCORE">COPTER_IMG_PATH"gx_copter_number_score.gif"</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
#if defined(__MMI_GAME_COPTER_128x160__) || defined(__MMI_GAME_COPTER_176x220__) || defined(__MMI_GAME_SUBMARINE_128x160__) || defined(__MMI_GAME_SUBMARINE_176x220__) || defined(__MMI_GAME_JET_128x160__) || defined(__MMI_GAME_JET_176x220__)
    <IMAGE id="IMG_ID_GX_COPTER_TITLE">COPTER_IMG_PATH"gx_copter_title.bmp"</IMAGE>
#endif
	<IMAGE id="IMG_ID_GX_COPTER_BACKGROUND">COPTER_IMG_PATH"gx_copter_bg.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_COPTER_0">COPTER_IMG_PATH"gx_copter_frame_0.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_COPTER_1">COPTER_IMG_PATH"gx_copter_frame_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_COPTER_2">COPTER_IMG_PATH"gx_copter_frame_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_COPTER_CRASHED_0">COPTER_IMG_PATH"gx_copter_crashed_0.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_COPTER_CRASHED_1">COPTER_IMG_PATH"gx_copter_crashed_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_COPTER_CRASHED_2">COPTER_IMG_PATH"gx_copter_crashed_2.bmp"</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_ID_GX_COPTER_GOTEXT">COPTER_IMG_PATH"gameover\\\\gx_copter_gameover.gif"</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
	<IMAGE id="IMG_ID_GX_COPTER_GRADESMAP">COPTER_IMG_PATH"gameover\\\\gx_copter_gradesmap.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_COPTER_GOPIC">COPTER_IMG_PATH"gameover\\\\gx_copter_pic.gif"</IMAGE>
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_ID_GX_COPTER_GOTEXT_LANGUAGE0">COPTER_IMG_PATH"multi_lan\\\\gameover.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_COPTER_GOTEXT_LANGUAGE1">COPTER_IMG_PATH"multi_lan\\\\gameover_c.gif"</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

    /* Copter NVRAM */
    <CACHEDATA type="short" id="NVRAM_GX_COPTER_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif /*IS_COPTER_BASE_GAME*/


#ifdef IS_PUZZLE_BASE_GAME
#if defined(__MMI_GAME_PUZZLE_128x128__)
	#define PUZZLE_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\puzzle\\\\puzzle_128x128_puzzle\\\\"
#elif defined(__MMI_GAME_PUZZLE_128x160__)
	#define PUZZLE_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\puzzle\\\\puzzle_128x160_puzzle\\\\"
#elif defined(__MMI_GAME_PUZZLE_176x220__)
	#define PUZZLE_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\puzzle\\\\puzzle_176x220_puzzle\\\\"
#elif  defined(__MMI_GAME_PUZZLE_240x320__)
	#define PUZZLE_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\puzzle\\\\puzzle_240x320_puzzle\\\\"
#elif  defined(__MMI_GAME_PUZZLE_320x240__)
	#define PUZZLE_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\puzzle\\\\puzzle_320x240_puzzle\\\\"
#elif  defined(__MMI_GAME_PUZZLE_240x400__)
	#define PUZZLE_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\puzzle\\\\puzzle_240x400_puzzle\\\\"
#elif  defined(__MMI_GAME_PUZZLE_320x480__)
	#define PUZZLE_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\puzzle\\\\puzzle_320x480_puzzle\\\\"
#endif
	<STRING id="STR_ID_GX_PUZZLE_GAME_NAME"/>
#if defined(__MMI_TOUCH_SCREEN__)
    <STRING id="STR_ID_GX_PUZZLE_HELP_DESCRIPTION_TP"/>
#elif defined(__MMI_GAME_PUZZLE_128x128__)
    <STRING id="STR_ID_GX_PUZZLE_HELP_DESCRIPTION_128"/>
#else
    <STRING id="STR_ID_GX_PUZZLE_HELP_DESCRIPTION"/>
#endif
	<STRING id="STR_ID_GX_PUZZLE_LEVEL_EASY"/>
	<STRING id="STR_ID_GX_PUZZLE_LEVEL_NORMAL"/>
	<STRING id="STR_ID_GX_PUZZLE_LEVEL_HARD"/>
	<IMAGE id="IMG_ID_GX_PUZZLE_GAME_ICON">PUZZLE_IMG_PATH"gx_puzzle_icon.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_NUMBER_0">PUZZLE_IMG_PATH"gx_puzzle_number_0.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_NUMBER_1">PUZZLE_IMG_PATH"gx_puzzle_number_1.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_NUMBER_2">PUZZLE_IMG_PATH"gx_puzzle_number_2.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_NUMBER_3">PUZZLE_IMG_PATH"gx_puzzle_number_3.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_NUMBER_4">PUZZLE_IMG_PATH"gx_puzzle_number_4.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_NUMBER_5">PUZZLE_IMG_PATH"gx_puzzle_number_5.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_NUMBER_6">PUZZLE_IMG_PATH"gx_puzzle_number_6.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_NUMBER_7">PUZZLE_IMG_PATH"gx_puzzle_number_7.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_NUMBER_8">PUZZLE_IMG_PATH"gx_puzzle_number_8.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_NUMBER_9">PUZZLE_IMG_PATH"gx_puzzle_number_9.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_BOX">PUZZLE_IMG_PATH"gx_puzzle_box.gif"</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_ID_GX_PUZZLE_STEP">PUZZLE_IMG_PATH"gx_puzzle_step.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_TIME">PUZZLE_IMG_PATH"gx_puzzle_time.gif"</IMAGE>
#endif
	<IMAGE id="IMG_ID_GX_PUZZLE_LEFT_BAR">PUZZLE_IMG_PATH"gx_puzzle_left_bar.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_RIGHT_BAR">PUZZLE_IMG_PATH"gx_puzzle_right_bar.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_TOP_BAR">PUZZLE_IMG_PATH"gx_puzzle_top_bar.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_BOTTOM_BAR">PUZZLE_IMG_PATH"gx_puzzle_bottom_bar.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_3_SPACE">PUZZLE_IMG_PATH"gx_puzzle_3_space.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_4_SPACE">PUZZLE_IMG_PATH"gx_puzzle_4_space.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_SPACE">PUZZLE_IMG_PATH"gx_puzzle_5_space.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_SMALL_3">PUZZLE_IMG_PATH"gx_puzzle_small_3.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_SMALL_4">PUZZLE_IMG_PATH"gx_puzzle_small_4.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_SMALL_5">PUZZLE_IMG_PATH"gx_puzzle_small_5.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_3_1">PUZZLE_IMG_PATH"gx_puzzle_3_1.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_3_2">PUZZLE_IMG_PATH"gx_puzzle_3_2.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_3_3">PUZZLE_IMG_PATH"gx_puzzle_3_3.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_3_4">PUZZLE_IMG_PATH"gx_puzzle_3_4.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_3_5">PUZZLE_IMG_PATH"gx_puzzle_3_5.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_3_6">PUZZLE_IMG_PATH"gx_puzzle_3_6.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_3_7">PUZZLE_IMG_PATH"gx_puzzle_3_7.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_3_8">PUZZLE_IMG_PATH"gx_puzzle_3_8.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_4_1">PUZZLE_IMG_PATH"gx_puzzle_4_1.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_4_2">PUZZLE_IMG_PATH"gx_puzzle_4_2.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_4_3">PUZZLE_IMG_PATH"gx_puzzle_4_3.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_4_4">PUZZLE_IMG_PATH"gx_puzzle_4_4.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_4_5">PUZZLE_IMG_PATH"gx_puzzle_4_5.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_4_6">PUZZLE_IMG_PATH"gx_puzzle_4_6.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_4_7">PUZZLE_IMG_PATH"gx_puzzle_4_7.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_4_8">PUZZLE_IMG_PATH"gx_puzzle_4_8.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_4_9">PUZZLE_IMG_PATH"gx_puzzle_4_9.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_4_10">PUZZLE_IMG_PATH"gx_puzzle_4_10.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_4_11">PUZZLE_IMG_PATH"gx_puzzle_4_11.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_4_12">PUZZLE_IMG_PATH"gx_puzzle_4_12.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_4_13">PUZZLE_IMG_PATH"gx_puzzle_4_13.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_4_14">PUZZLE_IMG_PATH"gx_puzzle_4_14.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_4_15">PUZZLE_IMG_PATH"gx_puzzle_4_15.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_1">PUZZLE_IMG_PATH"gx_puzzle_5_1.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_2">PUZZLE_IMG_PATH"gx_puzzle_5_2.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_3">PUZZLE_IMG_PATH"gx_puzzle_5_3.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_4">PUZZLE_IMG_PATH"gx_puzzle_5_4.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_5">PUZZLE_IMG_PATH"gx_puzzle_5_5.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_6">PUZZLE_IMG_PATH"gx_puzzle_5_6.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_7">PUZZLE_IMG_PATH"gx_puzzle_5_7.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_8">PUZZLE_IMG_PATH"gx_puzzle_5_8.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_9">PUZZLE_IMG_PATH"gx_puzzle_5_9.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_10">PUZZLE_IMG_PATH"gx_puzzle_5_10.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_11">PUZZLE_IMG_PATH"gx_puzzle_5_11.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_12">PUZZLE_IMG_PATH"gx_puzzle_5_12.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_13">PUZZLE_IMG_PATH"gx_puzzle_5_13.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_14">PUZZLE_IMG_PATH"gx_puzzle_5_14.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_15">PUZZLE_IMG_PATH"gx_puzzle_5_15.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_16">PUZZLE_IMG_PATH"gx_puzzle_5_16.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_17">PUZZLE_IMG_PATH"gx_puzzle_5_17.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_18">PUZZLE_IMG_PATH"gx_puzzle_5_18.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_19">PUZZLE_IMG_PATH"gx_puzzle_5_19.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_20">PUZZLE_IMG_PATH"gx_puzzle_5_20.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_21">PUZZLE_IMG_PATH"gx_puzzle_5_21.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_22">PUZZLE_IMG_PATH"gx_puzzle_5_22.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_23">PUZZLE_IMG_PATH"gx_puzzle_5_23.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_5_24">PUZZLE_IMG_PATH"gx_puzzle_5_24.gif"</IMAGE>
#if defined(__MMI_GAME_PUZZLE_240x320__) || defined(__MMI_GAME_PUZZLE_320x240__) || defined(__MMI_GAME_PUZZLE_240x400__) || defined(__MMI_GAME_PUZZLE_320x480__)
    <IMAGE id="IMG_ID_GX_PUZZLE_BG">PUZZLE_IMG_PATH"gx_puzzle_bg.gif"</IMAGE>
#endif
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_ID_GX_PUZZLE_GOTEXT">PUZZLE_IMG_PATH"gameover\\\\gx_puzzle_complete.gif"</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
	<IMAGE id="IMG_ID_GX_PUZZLE_GRADESMAP">PUZZLE_IMG_PATH"gameover\\\\gx_puzzle_gradesmap.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_GOPIC">PUZZLE_IMG_PATH"gameover\\\\gx_puzzle_pic.gif"</IMAGE>
#if defined(__MMI_TOUCH_SCREEN__)
#ifdef __MMI_GAME_PUZZLE_320x240__
    <IMAGE id="IMG_ID_GX_PUZZLE_UP">PUZZLE_IMG_PATH"gx_puzzle_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_DOWN">PUZZLE_IMG_PATH"gx_puzzle_down.bmp"</IMAGE>
#else defined(__MMI_GAME_PUZZLE_240x320__) || defined(__MMI_GAME_PUZZLE_320x240__) || \
     defined(__MMI_GAME_PUZZLE_240x400__) || defined(__MMI_GAME_PUZZLE_320x480__)
	<IMAGE id="IMG_ID_GX_PUZZLE_UP">PUZZLE_IMG_PATH"gx_puzzle_button_off.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_DOWN">PUZZLE_IMG_PATH"gx_puzzle_button_down.gif"</IMAGE>
#endif
#endif
	
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_ID_GX_PUZZLE_GOTEXT_LANGUAGE0">PUZZLE_IMG_PATH"multi_lan\\\\gx_puzzle_complete.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_TIME_LANGUAGE0">PUZZLE_IMG_PATH"multi_lan\\\\gx_puzzle_time.gif"</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_STEP_LANGUAGE0">PUZZLE_IMG_PATH"multi_lan\\\\gx_puzzle_step.gif"</IMAGE>
    
	<IMAGE id="IMG_ID_GX_PUZZLE_GOTEXT_LANGUAGE1">PUZZLE_IMG_PATH"multi_lan\\\\gx_puzzle_complete_c.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PUZZLE_TIME_LANGUAGE1">PUZZLE_IMG_PATH"multi_lan\\\\gx_puzzle_time_c.gif"</IMAGE>
    <IMAGE id="IMG_ID_GX_PUZZLE_STEP_LANGUAGE1">PUZZLE_IMG_PATH"multi_lan\\\\gx_puzzle_step_c.gif"</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

    /* Puzzle NVRAM */
    <CACHEDATA type="byte" id="NVRAM_GX_PUZZLE_LEVEL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="short" id="NVRAM_GX_PUZZLE_EASY_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_PUZZLE_NORMAL_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_PUZZLE_HARD_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif /*IS_PUZZLE_BASE_GAME*/


#ifdef IS_PANDA_BASE_GAME
#if defined(__MMI_GAME_PANDA_128x128__)
	#define PANDA_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\panda\\\\panda_128x128_panda\\\\"
#elif defined(__MMI_GAME_PANDA_128x160__)
	#define PANDA_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\panda\\\\panda_128x160_panda\\\\"
#elif defined(__MMI_GAME_PANDA_176x220__)
	#define PANDA_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\panda\\\\panda_176x220_panda\\\\"
#elif defined(__MMI_GAME_MONKEY_128x128__)
	#define PANDA_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\panda\\\\panda_128x128_monkey\\\\"
#elif defined(__MMI_GAME_MONKEY_128x160__)
	#define PANDA_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\panda\\\\panda_128x160_monkey\\\\"
#elif defined(__MMI_GAME_MONKEY_176x220__)
	#define PANDA_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\panda\\\\panda_176x220_monkey\\\\"
#endif
#if defined(__MMI_GAME_PANDA_128x128__) || defined(__MMI_GAME_PANDA_128x160__) || defined(__MMI_GAME_PANDA_176x220__)
	<STRING id="STR_ID_GX_PANDA_GAME_NAME"/>
	<STRING id="STR_ID_GX_PANDA_HELP_DESCRIPTION"/>
#elif defined(__MMI_GAME_MONKEY_128x128__) || defined(__MMI_GAME_MONKEY_128x160__) || defined(__MMI_GAME_MONKEY_176x220__)
	<STRING id="STR_ID_GX_PANDA_GAME_NAME_MONKEY"/>
	<STRING id="STR_ID_GX_PANDA_HELP_DESCRIPTION_MONKEY"/>
#endif
	<IMAGE id="IMG_ID_GX_PANDA_GAME_ICON">PANDA_IMG_PATH"gx_panda_icon.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_BACKGROUND">PANDA_IMG_PATH"gx_panda_background.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_CLOCK">PANDA_IMG_PATH"gx_panda_clock.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_ROLE_JUMP">PANDA_IMG_PATH"gx_panda_role_jump.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_ROLE_FALL_FRAME_0">PANDA_IMG_PATH"gx_panda_role_fall_frame_0.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_ROLE_FALL_FRAME_1">PANDA_IMG_PATH"gx_panda_role_fall_frame_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_ROLE_LEFT_FRAME_0">PANDA_IMG_PATH"gx_panda_role_left_frame_0.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_ROLE_LEFT_FRAME_1">PANDA_IMG_PATH"gx_panda_role_left_frame_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_ROLE_RIGHT_FRAME_0">PANDA_IMG_PATH"gx_panda_role_right_frame_0.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_ROLE_RIGHT_FRAME_1">PANDA_IMG_PATH"gx_panda_role_right_frame_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_ROLE_ATTACK_L_FRAME_0">PANDA_IMG_PATH"gx_panda_role_attack_l_frame_0.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_ROLE_ATTACK_L_FRAME_1">PANDA_IMG_PATH"gx_panda_role_attack_l_frame_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_ROLE_ATTACK_R_FRAME_0">PANDA_IMG_PATH"gx_panda_role_attack_r_frame_0.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_ROLE_ATTACK_R_FRAME_1">PANDA_IMG_PATH"gx_panda_role_attack_r_frame_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_ENEMY_1_LEFT">PANDA_IMG_PATH"gx_panda_enemy_1_left.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_ENEMY_2_LEFT">PANDA_IMG_PATH"gx_panda_enemy_2_left.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_ENEMY_3_LEFT">PANDA_IMG_PATH"gx_panda_enemy_3_left.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_ENEMY_1_LEFT_FRAME_2">PANDA_IMG_PATH"gx_panda_enemy_1_left_frame_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_ENEMY_2_LEFT_FRAME_2">PANDA_IMG_PATH"gx_panda_enemy_2_left_frame_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_ENEMY_3_LEFT_FRAME_2">PANDA_IMG_PATH"gx_panda_enemy_3_left_frame_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_ENEMY_1_RIGHT">PANDA_IMG_PATH"gx_panda_enemy_1_right.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_ENEMY_2_RIGHT">PANDA_IMG_PATH"gx_panda_enemy_2_right.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_ENEMY_3_RIGHT">PANDA_IMG_PATH"gx_panda_enemy_3_right.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_ENEMY_1_RIGHT_FRAME_2">PANDA_IMG_PATH"gx_panda_enemy_1_right_frame_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_ENEMY_2_RIGHT_FRAME_2">PANDA_IMG_PATH"gx_panda_enemy_2_right_frame_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_ENEMY_3_RIGHT_FRAME_2">PANDA_IMG_PATH"gx_panda_enemy_3_right_frame_2.bmp"</IMAGE>
	
	<IMAGE id="IMG_ID_GX_PANDA_DIGIT_0">PANDA_IMG_PATH"gx_panda_digit_0.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_DIGIT_1">PANDA_IMG_PATH"gx_panda_digit_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_DIGIT_2">PANDA_IMG_PATH"gx_panda_digit_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_DIGIT_3">PANDA_IMG_PATH"gx_panda_digit_3.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_DIGIT_4">PANDA_IMG_PATH"gx_panda_digit_4.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_DIGIT_5">PANDA_IMG_PATH"gx_panda_digit_5.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_DIGIT_6">PANDA_IMG_PATH"gx_panda_digit_6.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_DIGIT_7">PANDA_IMG_PATH"gx_panda_digit_7.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_DIGIT_8">PANDA_IMG_PATH"gx_panda_digit_8.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_DIGIT_9">PANDA_IMG_PATH"gx_panda_digit_9.bmp"</IMAGE>
	
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
        <IMAGE id="IMG_ID_GX_PANDA_SCORE">PANDA_IMG_PATH"gx_panda_score.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_GOTEXT">PANDA_IMG_PATH"gameover\\\\gx_panda_gameover.gif"</IMAGE>
#else /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_ID_GX_PANDA_SCORE_LANGUAGE0">PANDA_IMG_PATH"gx_panda_score.bmp"</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_SCORE_LANGUAGE1">PANDA_IMG_PATH"multi_lan\\\\gx_panda_score_c.bmp"</IMAGE>
    
    <IMAGE id="IMG_ID_GX_PANDA_GOTEXT_LANGUAGE0">PANDA_IMG_PATH"gameover\\\\gx_panda_gameover.gif"</IMAGE>
    <IMAGE id="IMG_ID_GX_PANDA_GOTEXT_LANGUAGE1">PANDA_IMG_PATH"multi_lan\\\\gameover_c.gif"</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
	<IMAGE id="IMG_ID_GX_PANDA_GRADESMAP">PANDA_IMG_PATH"gameover\\\\gx_panda_gradesmap.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_PANDA_GOPIC">PANDA_IMG_PATH"gameover\\\\gx_panda_pic.gif"</IMAGE>

    /* Panda NVRAM */
    <CACHEDATA type="short" id="NVRAM_GX_PANDA_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif /*IS_PANDA_BASE_GAME*/


#ifdef IS_STAIR_BASE_GAME
#if defined(__MMI_GAME_STAIR_128x128__)
	#define STAIR_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\stair\\\\stair_128x128_stair\\\\"
#elif defined(__MMI_GAME_STAIR_128x160__)
	#define STAIR_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\stair\\\\stair_128x160_stair\\\\"
#elif defined(__MMI_GAME_STAIR_176x220__)
	#define STAIR_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\stair\\\\stair_176x220_stair\\\\"
#elif defined(__MMI_GAME_CHICKEN_128x128__)
	#define STAIR_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\stair\\\\stair_128x128_chicken\\\\"
#elif defined(__MMI_GAME_CHICKEN_128x160__)
	#define STAIR_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\stair\\\\stair_128x160_chicken\\\\"
#elif defined(__MMI_GAME_ROBOT_176x220__)
	#define STAIR_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\stair\\\\stair_176x220_robot\\\\"
#elif defined(__MMI_GAME_ROBOT_128x160__)
	#define STAIR_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\stair\\\\stair_128x160_robot\\\\"
#endif
#if defined(__MMI_GAME_STAIR_128x160__) || defined(__MMI_GAME_STAIR_128x128__) || defined(__MMI_GAME_STAIR_176x220__)
	<STRING id="STR_ID_GX_STAIR_GAME_NAME"/>
	<STRING id="STR_ID_GX_STAIR_HELP_DESCRIPTION"/>
#elif defined(__MMI_GAME_CHICKEN_128x128__) || defined(__MMI_GAME_CHICKEN_128x160__)
	<STRING id="STR_ID_GX_STAIR_GAME_NAME_CHICKEN"/>
	<STRING id="STR_ID_GX_STAIR_HELP_DESCRIPTION_CHICKEN"/>
#elif defined(__MMI_GAME_ROBOT_176x220__) || defined(__MMI_GAME_ROBOT_128x160__)
	<STRING id="STR_ID_GX_STAIR_GAME_NAME_ROBOT"/>
	<STRING id="STR_ID_GX_STAIR_HELP_DESCRIPTION_ROBOT"/>
#endif
	<STRING id="STR_ID_GX_STAIR_LEVEL_EASY"/>
	<STRING id="STR_ID_GX_STAIR_LEVEL_NORMAL"/>
	<STRING id="STR_ID_GX_STAIR_LEVEL_HARD"/>
	<IMAGE id="IMG_ID_GX_STAIR_BOX">STAIR_IMG_PATH"gx_stair_box.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_FLOAT_STAIR_1">STAIR_IMG_PATH"gx_stair_float_stair_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_FLOAT_STAIR_2">STAIR_IMG_PATH"gx_stair_float_stair_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_GAME_ICON">STAIR_IMG_PATH"gx_stair_icon.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_ROLE">STAIR_IMG_PATH"gx_stair_role.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_ROLE_DYING">STAIR_IMG_PATH"gx_stair_role_dying.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_ROLE_FALLING_0">STAIR_IMG_PATH"gx_stair_role_falling_0.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_ROLE_FALLING_1">STAIR_IMG_PATH"gx_stair_role_falling_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_ROLE_LEFT_0">STAIR_IMG_PATH"gx_stair_role_left_0.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_ROLE_LEFT_1">STAIR_IMG_PATH"gx_stair_role_left_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_ROLE_RIGHT_0">STAIR_IMG_PATH"gx_stair_role_right_0.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_ROLE_RIGHT_1">STAIR_IMG_PATH"gx_stair_role_right_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_STAIR">STAIR_IMG_PATH"gx_stair_stair.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_THORN">STAIR_IMG_PATH"gx_stair_thorn.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_THORN_STAIR">STAIR_IMG_PATH"gx_stair_thorn_stair.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_TITLE">STAIR_IMG_PATH"gx_stair_title.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_WALL">STAIR_IMG_PATH"gx_stair_wall.bmp"</IMAGE>
	#if defined(__MMI_GAME_STAIR_128x160__) || defined(__MMI_GAME_STAIR_176x220__) || defined(__MMI_GAME_CHICKEN_128x160__) || defined(__MMI_GAME_ROBOT_176x220__) || defined(__MMI_GAME_ROBOT_128x160__)
	<IMAGE id="IMG_ID_GX_STAIR_ENERGY_BAR">STAIR_IMG_PATH"gx_stair_energy_bar.bmp"</IMAGE>
	#elif defined(__MMI_GAME_STAIR_128x128__) || defined(__MMI_GAME_CHICKEN_128x128__)
	<IMAGE id="IMG_ID_GX_STAIR_ENERGY_BAR_HORIZONTAL">STAIR_IMG_PATH"gx_stair_energy_bar_horizontal.bmp"</IMAGE>
	#endif
	<IMAGE id="IMG_ID_GX_STAIR_ROLE_FLYING_0">STAIR_IMG_PATH"gx_stair_role_flying_0.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_ROLE_FLYING_1">STAIR_IMG_PATH"gx_stair_role_flying_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_NUMBER_0">STAIR_IMG_PATH"gx_stair_number_0.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_NUMBER_1">STAIR_IMG_PATH"gx_stair_number_1.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_NUMBER_2">STAIR_IMG_PATH"gx_stair_number_2.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_NUMBER_3">STAIR_IMG_PATH"gx_stair_number_3.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_NUMBER_4">STAIR_IMG_PATH"gx_stair_number_4.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_NUMBER_5">STAIR_IMG_PATH"gx_stair_number_5.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_NUMBER_6">STAIR_IMG_PATH"gx_stair_number_6.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_NUMBER_7">STAIR_IMG_PATH"gx_stair_number_7.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_NUMBER_8">STAIR_IMG_PATH"gx_stair_number_8.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_NUMBER_9">STAIR_IMG_PATH"gx_stair_number_9.gif"</IMAGE>
        <IMAGE id="IMG_ID_GX_STAIR_GRADESMAP">STAIR_IMG_PATH"gameover\\\\gx_stair_gradesmap.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_GOPIC">STAIR_IMG_PATH"gameover\\\\gx_stair_pic.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_BACKGROUND">STAIR_IMG_PATH"gx_stair_bg.bmp"</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
        <IMAGE id="IMG_ID_GX_STAIR_SCORE">STAIR_IMG_PATH"gx_stair_score.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_STAIR_GOTEXT">STAIR_IMG_PATH"gameover\\\\gx_stair_gameover.gif"</IMAGE>
        <IMAGE id="IMG_ID_GX_STAIR_FLYING_MARK">STAIR_IMG_PATH"gx_stair_flying_mark.bmp"</IMAGE>
#else /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
    <IMAGE id="IMG_ID_GX_STAIR_SCORE">STAIR_IMG_PATH"multi_lan\\\\score_C.gif"</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_GOTEXT_LANGUAGE0">STAIR_IMG_PATH"multi_lan\\\\gameover.gif"</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_FLYING_MARK_LANGUAGE0">STAIR_IMG_PATH"gx_stair_flying_mark.bmp"</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_GOTEXT_LANGUAGE1">STAIR_IMG_PATH"multi_lan\\\\gameover_C.gif"</IMAGE>
    <IMAGE id="IMG_ID_GX_STAIR_FLYING_MARK_LANGUAGE1">STAIR_IMG_PATH"multi_lan\\\\flying_mark_C.bmp"</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

    /* stair NVRAM */
    <CACHEDATA type="byte" id="NVRAM_GX_STAIR_LEVEL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="short" id="NVRAM_GX_STAIR_EASY_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_STAIR_NORMAL_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_STAIR_HARD_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

#endif /*IS_STAIR_BASE_GAME*/


#ifdef IS_UFO_BASE_GAME
#if defined(__MMI_GAME_UFO_128x128__)
	#define UFO_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\ufo\\\\ufo_128x128_ufo\\\\"
#elif defined(__MMI_GAME_UFO_128x160__)
	#define UFO_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\ufo\\\\ufo_128x160_ufo\\\\"
#elif defined(__MMI_GAME_UFO_176x220__)
	#define UFO_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\ufo\\\\ufo_176x220_ufo\\\\"
#endif
	<STRING id="STR_ID_GX_UFO_GAME_NAME"/>
	<STRING id="STR_ID_GX_UFO_HELP_DESCRIPTION"/>
	<IMAGE id="IMG_ID_GX_UFO_GAME_ICON">UFO_IMG_PATH"gx_ufo_icon.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_DIGIT_0">UFO_IMG_PATH"gx_ufo_digit_0.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_DIGIT_1">UFO_IMG_PATH"gx_ufo_digit_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_DIGIT_2">UFO_IMG_PATH"gx_ufo_digit_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_DIGIT_3">UFO_IMG_PATH"gx_ufo_digit_3.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_DIGIT_4">UFO_IMG_PATH"gx_ufo_digit_4.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_DIGIT_5">UFO_IMG_PATH"gx_ufo_digit_5.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_DIGIT_6">UFO_IMG_PATH"gx_ufo_digit_6.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_DIGIT_7">UFO_IMG_PATH"gx_ufo_digit_7.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_DIGIT_8">UFO_IMG_PATH"gx_ufo_digit_8.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_DIGIT_9">UFO_IMG_PATH"gx_ufo_digit_9.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_BACKGROUND_1">UFO_IMG_PATH"gx_ufo_background_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_BACKGROUND_2">UFO_IMG_PATH"gx_ufo_background_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_BACKGROUND_3">UFO_IMG_PATH"gx_ufo_background_3.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_BACKGROUND_4">UFO_IMG_PATH"gx_ufo_background_4.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_BACKGROUND_5">UFO_IMG_PATH"gx_ufo_background_5.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_BACKGROUND_6">UFO_IMG_PATH"gx_ufo_background_6.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_BOSS">UFO_IMG_PATH"gx_ufo_boss.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_BOSS_HIT">UFO_IMG_PATH"gx_ufo_boss_hit.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_ENEMY_1">UFO_IMG_PATH"gx_ufo_enemy_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_ENEMY_2">UFO_IMG_PATH"gx_ufo_enemy_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_ENEMY_3">UFO_IMG_PATH"gx_ufo_enemy_3.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_ENEMY_4">UFO_IMG_PATH"gx_ufo_enemy_4.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_ENEMY_1_HIT">UFO_IMG_PATH"gx_ufo_enemy_1_hit.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_ENEMY_2_HIT">UFO_IMG_PATH"gx_ufo_enemy_2_hit.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_ENEMY_3_HIT">UFO_IMG_PATH"gx_ufo_enemy_3_hit.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_ENEMY_4_HIT">UFO_IMG_PATH"gx_ufo_enemy_4_hit.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_ENEMY_BULLET_1">UFO_IMG_PATH"gx_ufo_enemy_bullet_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_ENEMY_BULLET_2">UFO_IMG_PATH"gx_ufo_enemy_bullet_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_ENEMY_BULLET_3">UFO_IMG_PATH"gx_ufo_enemy_bullet_3.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_ENEMY_BULLET_4">UFO_IMG_PATH"gx_ufo_enemy_bullet_4.bmp"</IMAGE>
#ifndef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_ID_GX_UFO_ENERGY">UFO_IMG_PATH"gx_ufo_energy.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_SCORE">UFO_IMG_PATH"gx_ufo_score.bmp"</IMAGE>
#endif
	<IMAGE id="IMG_ID_GX_UFO_ENERGY_UNIT">UFO_IMG_PATH"gx_ufo_energy_unit.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_WEAPON_1">UFO_IMG_PATH"gx_ufo_weapon_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_WEAPON_2">UFO_IMG_PATH"gx_ufo_weapon_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_ENERGY_FILL_1">UFO_IMG_PATH"gx_ufo_energy_fill_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_ENERGY_FILL_2">UFO_IMG_PATH"gx_ufo_energy_fill_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_BOMB_1">UFO_IMG_PATH"gx_ufo_bomb_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_BOMB_2">UFO_IMG_PATH"gx_ufo_bomb_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_FLAME_1">UFO_IMG_PATH"gx_ufo_flame_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_FLAME_2">UFO_IMG_PATH"gx_ufo_flame_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_FLAME_3">UFO_IMG_PATH"gx_ufo_flame_3.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_ROLE">UFO_IMG_PATH"gx_ufo_role.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_ROLE_HIT">UFO_IMG_PATH"gx_ufo_role_hit.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_ROLE_BULLET">UFO_IMG_PATH"gx_ufo_role_bullet.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_INVINCIBLE_1">UFO_IMG_PATH"gx_ufo_invincible_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_INVINCIBLE_2">UFO_IMG_PATH"gx_ufo_invincible_2.bmp"</IMAGE>
#ifndef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_ID_GX_UFO_LEVEL_CLEAR">UFO_IMG_PATH"gx_ufo_level_clear.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_GOTEXT">UFO_IMG_PATH"gameover\\\\gx_ufo_gameover.gif"</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
	<IMAGE id="IMG_ID_GX_UFO_GRADESMAP">UFO_IMG_PATH"gameover\\\\gx_ufo_gradesmap.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_GOPIC">UFO_IMG_PATH"gameover\\\\gx_ufo_pic.gif"</IMAGE>
#ifdef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_ID_GX_UFO_LEVEL_CLEAR_LANGUAGE0">UFO_IMG_PATH"gx_ufo_level_clear.bmp"</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_GOTEXT_LANGUAGE0">UFO_IMG_PATH"multi_lan\\\\gx_dance_gameover.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_UFO_LEVEL_CLEAR_LANGUAGE1">UFO_IMG_PATH"multi_lan\\\\gx_ufo_level_clear_C.bmp"</IMAGE>
    <IMAGE id="IMG_ID_GX_UFO_GOTEXT_LANGUAGE1">UFO_IMG_PATH"multi_lan\\\\gx_dance_gameover_C.gif"</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

    /* UFO NVRAM */
    <CACHEDATA type="short" id="NVRAM_GX_UFO_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif /*IS_UFO_BASE_GAME*/


#ifdef IS_MAGICSUSHI_BASE_GAME
#if defined(__MMI_GAME_MAGICSUSHI_240x320__)
	#define MAGICSUSHI_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Magicsushi\\\\magicsushi_240x320_magicsushi\\\\"
#elif defined(__MMI_GAME_MAGICSUSHI_320x240__)
	#define MAGICSUSHI_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Magicsushi\\\\magicsushi_320x240_magicsushi\\\\"
#elif defined(__MMI_GAME_MAGICSUSHI_240x400__)
	#define MAGICSUSHI_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Magicsushi\\\\magicsushi_240x400_magicsushi\\\\"
#elif defined(__MMI_GAME_MAGICSUSHI_320x480__)
    #define MAGICSUSHI_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Magicsushi\\\\magicsushi_320x480_magicsushi\\\\"
#endif
	<STRING id="STR_ID_GX_MAGICSUSHI_GAME_NAME"/>
	<STRING id="STR_ID_GX_MAGICSUSHI_HELP_DESCRIPTION"/>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_GAME_ICON">MAGICSUSHI_IMG_PATH"Magicsushi.BMP"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_NUMBER_0">MAGICSUSHI_IMG_PATH"gx_magicsushi_num_0.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_NUMBER_1">MAGICSUSHI_IMG_PATH"gx_magicsushi_num_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_NUMBER_2">MAGICSUSHI_IMG_PATH"gx_magicsushi_num_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_NUMBER_3">MAGICSUSHI_IMG_PATH"gx_magicsushi_num_3.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_NUMBER_4">MAGICSUSHI_IMG_PATH"gx_magicsushi_num_4.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_NUMBER_5">MAGICSUSHI_IMG_PATH"gx_magicsushi_num_5.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_NUMBER_6">MAGICSUSHI_IMG_PATH"gx_magicsushi_num_6.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_NUMBER_7">MAGICSUSHI_IMG_PATH"gx_magicsushi_num_7.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_NUMBER_8">MAGICSUSHI_IMG_PATH"gx_magicsushi_num_8.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_NUMBER_9">MAGICSUSHI_IMG_PATH"gx_magicsushi_num_9.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_NULL">MAGICSUSHI_IMG_PATH"gx_magicsushi_item_null.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_SELECTED">MAGICSUSHI_IMG_PATH"gx_magicsushi_select.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_PROGRESS">MAGICSUSHI_IMG_PATH"gx_magicsushi_progress.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_0">MAGICSUSHI_IMG_PATH"gx_magicsushi_item_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_1">MAGICSUSHI_IMG_PATH"gx_magicsushi_item_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_2">MAGICSUSHI_IMG_PATH"gx_magicsushi_item_3.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_3">MAGICSUSHI_IMG_PATH"gx_magicsushi_item_4.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_4">MAGICSUSHI_IMG_PATH"gx_magicsushi_item_5.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_5">MAGICSUSHI_IMG_PATH"gx_magicsushi_item_6.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_6">MAGICSUSHI_IMG_PATH"gx_magicsushi_item_7.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_7">MAGICSUSHI_IMG_PATH"gx_magicsushi_item_8.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_MAGIC1">MAGICSUSHI_IMG_PATH"gx_magicsushi_magic_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_MAGIC2">MAGICSUSHI_IMG_PATH"gx_magicsushi_magic_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_TYPE_MAGIC3">MAGICSUSHI_IMG_PATH"gx_magicsushi_magic_3.bmp"</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_GAME_BACKGROUND">MAGICSUSHI_IMG_PATH"gx_magicsushi_background.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_GAMEOVER">MAGICSUSHI_IMG_PATH"gx_magicsushi_gameover_TimeOut_E.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_UPLEVEL">MAGICSUSHI_IMG_PATH"gx_magicsushi_uplevel.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_NOMOREMOVE">MAGICSUSHI_IMG_PATH"gx_magicsushi_nomoremove.gif"</IMAGE>
#else
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_BACKGROUND_LANGUAGE0">MAGICSUSHI_IMG_PATH"gx_magicsushi_background.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_GAMEOVER_LANGUAGE0">MAGICSUSHI_IMG_PATH"gx_magicsushi_gameover_TimeOut_E.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_UPLEVEL_LANGUAGE0">MAGICSUSHI_IMG_PATH"gx_magicsushi_uplevel.gif"</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_NOMOREMOVE_LANGUAGE0">MAGICSUSHI_IMG_PATH"gx_magicsushi_nomoremove.gif"</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_BACKGROUND_LANGUAGE1">MAGICSUSHI_IMG_PATH"multi_lan\\\\bkg_C.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_GAMEOVER_LANGUAGE1">MAGICSUSHI_IMG_PATH"multi_lan\\\\gx_magicsushi_gameover_TimeOut_C.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_UPLEVEL_LANGUAGE1">MAGICSUSHI_IMG_PATH"multi_lan\\\\uplevel_C.gif"</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_NOMOREMOVE_LANGUAGE1">MAGICSUSHI_IMG_PATH"multi_lan\\\\nomoremove_C.gif"</IMAGE>
#endif
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_CURSOR">MAGICSUSHI_IMG_PATH"gx_magicsushi_select1.bmp"</IMAGE>
#ifdef __MMI_TOUCH_SCREEN__
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_UP">MAGICSUSHI_IMG_PATH"gx_magicsushi_up.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_MAGICSUSHI_DOWN">MAGICSUSHI_IMG_PATH"gx_magicsushi_down.bmp"</IMAGE>
#endif
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_GRADEMAP">MAGICSUSHI_IMG_PATH"gx_magicsushi_ScoreBG.bmp"</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_GOPIC">MAGICSUSHI_IMG_PATH"gx_magicsushi_Food.bmp"</IMAGE>
    <IMAGE id="IMG_ID_GX_MAGICSUSHI_GAMEOVER_BG">MAGICSUSHI_IMG_PATH"gx_magicsushi_BG.gif"</IMAGE>

    /* Magicsushi NVRAM */
    <CACHEDATA type="short" id="NVRAM_GX_MAGICSUSHI_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif /*IS_MAGICSUSHI_BASE_GAME*/


#ifdef IS_FRUIT_BASE_GAME
	#define FRUIT_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Fruit\\\\fruit_176x220_fruit\\\\"
	<STRING id="STR_ID_GX_FRUIT_GAME_NAME"/>
	<STRING id="STR_ID_GX_FRUIT_HELP_DESCRIPTION"/>
	<STRING id="STR_ID_GX_FRUIT_LEVEL_EASY"/>
	<STRING id="STR_ID_GX_FRUIT_LEVEL_NORMAL"/>
	<STRING id="STR_ID_GX_FRUIT_LEVEL_HARD"/>
	<IMAGE id="IMG_ID_GX_FRUIT_GAME_ICON">FRUIT_IMG_PATH"gx_fruit_icon.bmp"</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_ID_GX_FRUIT_GOTEXT">FRUIT_IMG_PATH"gx_fruit_gameover_title.bmp"</IMAGE>
#endif
	<IMAGE id="IMG_ID_GX_FRUIT_GRADESMAP">FRUIT_IMG_PATH"gx_fruit_gradesmap.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_GOPIC">FRUIT_IMG_PATH"gx_fruit_gameover_pic.bmp"</IMAGE>
#if defined(__MMI_GAME_FRUIT_176x220__)
	<IMAGE id="IMG_ID_GX_FRUIT_FOODA_ONE_PIECE">FRUIT_IMG_PATH"gx_fruit_fooda1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_FOODA_TWO_PIECE">FRUIT_IMG_PATH"gx_fruit_fooda2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_FOODA_THREE_PIECE">FRUIT_IMG_PATH"gx_fruit_fooda3.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_FOODA_MAX_PIECE">FRUIT_IMG_PATH"gx_fruit_fooda4.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_FOODB_ONE_PIECE">FRUIT_IMG_PATH"gx_fruit_foodb1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_FOODB_TWO_PIECE">FRUIT_IMG_PATH"gx_fruit_foodb2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_FOODB_THREE_PIECE">FRUIT_IMG_PATH"gx_fruit_foodb3.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_FOODB_MAX_PIECE">FRUIT_IMG_PATH"gx_fruit_foodb4.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_FOODC_ONE_PIECE">FRUIT_IMG_PATH"gx_fruit_foodc1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_FOODC_TWO_PIECE">FRUIT_IMG_PATH"gx_fruit_foodc2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_FOODC_THREE_PIECE">FRUIT_IMG_PATH"gx_fruit_foodc3.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_FOODC_MAX_PIECE">FRUIT_IMG_PATH"gx_fruit_foodc4.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_ROCK_ONEPIECE">FRUIT_IMG_PATH"gx_fruit_rock.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_TREASURE_1">FRUIT_IMG_PATH"gx_fruit_item_treasure_01.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_TREASURE_2">FRUIT_IMG_PATH"gx_fruit_item_treasure_02.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_TREASURE_3">FRUIT_IMG_PATH"gx_fruit_item_treasure_03.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_TREASURE_4">FRUIT_IMG_PATH"gx_fruit_item_treasure_04.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_TREASURE_5">FRUIT_IMG_PATH"gx_fruit_item_treasure_05.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_SWDWAVELOW_LEFT_A">FRUIT_IMG_PATH"gx_fruit_item_wave_left_1a.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_SWDWAVELOW_LEFT_B">FRUIT_IMG_PATH"gx_fruit_item_wave_left_1b.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEMID_LEFT_A">FRUIT_IMG_PATH"gx_fruit_item_wave_left_2a.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEMID_LEFT_B">FRUIT_IMG_PATH"gx_fruit_item_wave_left_2b.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEMAX_LEFT_A">FRUIT_IMG_PATH"gx_fruit_item_wave_left_3a.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEMAX_LEFT_B">FRUIT_IMG_PATH"gx_fruit_item_wave_left_3b.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_SWDWAVELOW_RIGHT_A">FRUIT_IMG_PATH"gx_fruit_item_wave_right_1a.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_SWDWAVELOW_RIGHT_B">FRUIT_IMG_PATH"gx_fruit_item_wave_right_1b.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEMID_RIGHT_A">FRUIT_IMG_PATH"gx_fruit_item_wave_right_2a.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEMID_RIGHT_B">FRUIT_IMG_PATH"gx_fruit_item_wave_right_2b.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEMAX_RIGHT_A">FRUIT_IMG_PATH"gx_fruit_item_wave_right_3a.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEMAX_RIGHT_B">FRUIT_IMG_PATH"gx_fruit_item_wave_right_3b.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEKICK_LEFT_A">FRUIT_IMG_PATH"gx_fruit_kickwavela.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEKICK_LEFT_B">FRUIT_IMG_PATH"gx_fruit_kickwavelb.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEKICK_RIGHT_A">FRUIT_IMG_PATH"gx_fruit_kickwavera.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_SWDWAVEKICK_RIGHT_B">FRUIT_IMG_PATH"gx_fruit_kickwaverb.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_CHEF_GAMEOVER">FRUIT_IMG_PATH"gx_fruit_chef_gameover.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_CHEF_RIGHT_CUTPREP">FRUIT_IMG_PATH"gx_fruit_chef_right_cutprep.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_CHEF_RIGHT_CUT">FRUIT_IMG_PATH"gx_fruit_chef_right_cut.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_CHEF_RIGHT_KICKPREP">FRUIT_IMG_PATH"gx_fruit_chef_right_kickprep.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_CHEF_RIGHT_KICK">FRUIT_IMG_PATH"gx_fruit_chef_right_kick.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_CHEF_LEFT_CUTPREP">FRUIT_IMG_PATH"gx_fruit_chef_left_cutprep.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_CHEF_LEFT_CUT">FRUIT_IMG_PATH"gx_fruit_chef_left_cut.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_CHEF_LEFT_KICKPREP">FRUIT_IMG_PATH"gx_fruit_chef_left_kickprep.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_CHEF_LEFT_KICK">FRUIT_IMG_PATH"gx_fruit_chef_left_kick.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_CHEF_FAINTA">FRUIT_IMG_PATH"gx_fruit_chef_fainta.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_CHEF_FAINTB">FRUIT_IMG_PATH"gx_fruit_chef_faintb.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_CHEF_RIGHT_WALKA">FRUIT_IMG_PATH"gx_fruit_chef_right_walka.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_CHEF_RIGHT_WALKB">FRUIT_IMG_PATH"gx_fruit_chef_right_walkb.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_CHEF_LEFT_WALKA">FRUIT_IMG_PATH"gx_fruit_chef_left_walka.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_CHEF_LEFT_WALKB">FRUIT_IMG_PATH"gx_fruit_chef_left_walkb.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_PLATFORM">FRUIT_IMG_PATH"gx_fruit_platform.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_TRACKA">FRUIT_IMG_PATH"gx_fruit_tracka.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_TRACKB">FRUIT_IMG_PATH"gx_fruit_trackb.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_SHAKER_OKA">FRUIT_IMG_PATH"gx_fruit_shaker_ok_a.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_SHAKER_OKB">FRUIT_IMG_PATH"gx_fruit_shaker_ok_b.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_SHAKER_PBLVA_A">FRUIT_IMG_PATH"gx_fruit_shaker_pblva_a.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_SHAKER_PBLVA_B">FRUIT_IMG_PATH"gx_fruit_shaker_pblva_b.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_SHAKER_PBLVB_A">FRUIT_IMG_PATH"gx_fruit_shaker_pblvb_a.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_SHAKER_PBLVB_B">FRUIT_IMG_PATH"gx_fruit_shaker_pblvb_b.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_SHAKER_BROKEN">FRUIT_IMG_PATH"gx_fruit_shaker_broken.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_WORKER_STEPA">FRUIT_IMG_PATH"gx_fruit_worker_walka.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_WORKER_STEPB">FRUIT_IMG_PATH"gx_fruit_worker_walkb.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_WORKER_FIXA">FRUIT_IMG_PATH"gx_fruit_worker_fixa.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_WORKER_FIXB">FRUIT_IMG_PATH"gx_fruit_worker_fixb.bmp"</IMAGE>
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_ID_GX_FRUIT_BGROUND">FRUIT_IMG_PATH"gx_fruit_bg.gif"</IMAGE>
#endif
#ifdef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_ID_GX_FRUIT_BGROUND_LANGUAGE0">FRUIT_IMG_PATH"gx_fruit_bg.gif"</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_GOTEXT_LANGUAGE0">FRUIT_IMG_PATH"gx_fruit_gameover_title.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_FRUIT_BGROUND_LANGUAGE1">FRUIT_IMG_PATH"multi_lan\\\\gx_fruit_bg_C.gif"</IMAGE>
    <IMAGE id="IMG_ID_GX_FRUIT_GOTEXT_LANGUAGE1">FRUIT_IMG_PATH"multi_lan\\\\gx_fruit_gameover_C.bmp"</IMAGE>
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
#endif /*__MMI_GAME_FRUIT_176x220__*/

    /* Fruit NVRAM */
    <CACHEDATA type="byte" id="NVRAM_GX_FRUIT_LEVEL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_FRUIT_NO_USE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_FRUIT_EASY_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_FRUIT_NORMAL_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_FRUIT_HARD_SCORE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif /*IS_FRUIT_BASE_GAME*/


#ifdef IS_VSMJ_BASE_GAME
#if defined(__MMI_GAME_VSMJ_240x320__)
	#define VSMJ_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Vsmj\\\\vsmj_240x320_vsmj\\\\"
#elif defined(__MMI_GAME_VSMJ_320x240__)
	#define VSMJ_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Vsmj\\\\vsmj_320x240_vsmj\\\\"
#elif defined(__MMI_GAME_VSMJ_240x400__)
	#define VSMJ_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Vsmj\\\\vsmj_240x400_vsmj\\\\"
#elif defined(__MMI_GAME_VSMJ_320x480__)
    #define VSMJ_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Vsmj\\\\vsmj_320x480_vsmj\\\\"
#endif
	<STRING id="STR_ID_GX_VSMJ_GAME_NAME"/>
	<STRING id="STR_ID_GX_VSMJ_HELP_DESCRIPTION"/>
	<STRING id="STR_ID_GX_VSMJ_LEVEL_NORMAL"/>
	<STRING id="STR_ID_GX_VSMJ_LEVEL_CPUVSCPU"/>
	<STRING id="STR_ID_GX_VSMJ_LEVEL1"/>
	<STRING id="STR_ID_GX_VSMJ_LEVEL2"/>
	<STRING id="STR_ID_GX_VSMJ_LEVEL3"/>
	<STRING id="STR_ID_GX_VSMJ_CUR_GAME"/>
	<IMAGE id="IMG_ID_GX_VSMJ_GAME_ICON">VSMJ_IMG_PATH"gx_vsmj_icon.gif"</IMAGE>
#ifndef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	<IMAGE id="IMG_ID_GX_VSMJ_GOTEXT">VSMJ_IMG_PATH"gx_vsmj_gameover_title.gif"</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_YOU_WIN">VSMJ_IMG_PATH"multi_lan\\\\gx_vsmj_complete.gif"</IMAGE>
#else
	<IMAGE id="IMG_ID_GX_VSMJ_GOTEXT_LANGUAGE0">VSMJ_IMG_PATH"gameover.gif"</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_YOU_WIN_LANGUAGE0">VSMJ_IMG_PATH"multi_lan\\\\gx_vsmj_complete.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_GOTEXT_LANGUAGE1">VSMJ_IMG_PATH"multi_lan\\\\gameover_c.gif"</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_YOU_WIN_LANGUAGE1">VSMJ_IMG_PATH"multi_lan\\\\gx_vsmj_complete_c.gif"</IMAGE>
#endif
	<IMAGE id="IMG_ID_GX_VSMJ_GRADESMAP">VSMJ_IMG_PATH"gx_vsmj_gradesmap.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_GOPIC">VSMJ_IMG_PATH"gx_vsmj_gameover_pic.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_EAST">VSMJ_IMG_PATH"T28.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_WEST">VSMJ_IMG_PATH"T29.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_SOUTH">VSMJ_IMG_PATH"T30.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_NORTH">VSMJ_IMG_PATH"T31.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_CHUNG">VSMJ_IMG_PATH"T32.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_FA">VSMJ_IMG_PATH"T33.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_BAI">VSMJ_IMG_PATH"T34.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_1W">VSMJ_IMG_PATH"T1.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_2W">VSMJ_IMG_PATH"T2.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_3W">VSMJ_IMG_PATH"T3.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_4W">VSMJ_IMG_PATH"T4.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_5W">VSMJ_IMG_PATH"T5.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_6W">VSMJ_IMG_PATH"T6.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_7W">VSMJ_IMG_PATH"T7.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_8W">VSMJ_IMG_PATH"T8.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_9W">VSMJ_IMG_PATH"T9.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_1S">VSMJ_IMG_PATH"T19.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_2S">VSMJ_IMG_PATH"T20.gif"</IMAGE>
 	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_3S">VSMJ_IMG_PATH"T21.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_4S">VSMJ_IMG_PATH"T22.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_5S">VSMJ_IMG_PATH"T23.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_6S">VSMJ_IMG_PATH"T24.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_7S">VSMJ_IMG_PATH"T25.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_8S">VSMJ_IMG_PATH"T26.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_9S">VSMJ_IMG_PATH"T27.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_1T">VSMJ_IMG_PATH"T10.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_2T">VSMJ_IMG_PATH"T11.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_3T">VSMJ_IMG_PATH"T12.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_4T">VSMJ_IMG_PATH"T13.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_5T">VSMJ_IMG_PATH"T14.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_6T">VSMJ_IMG_PATH"T15.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_7T">VSMJ_IMG_PATH"T16.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_8T">VSMJ_IMG_PATH"T17.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_9T">VSMJ_IMG_PATH"T18.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_SPRING">VSMJ_IMG_PATH"T35.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_SUMMER">VSMJ_IMG_PATH"T36.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_AUTUMN">VSMJ_IMG_PATH"T37.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_WINTER">VSMJ_IMG_PATH"T38.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_M">VSMJ_IMG_PATH"T39.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_L">VSMJ_IMG_PATH"T40.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_Z">VSMJ_IMG_PATH"T41.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_J">VSMJ_IMG_PATH"T42.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_TABLE_VER_BACK">VSMJ_IMG_PATH"table_ver_back.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_TABLE_HOR_BACK">VSMJ_IMG_PATH"table_hor_back.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_USER_LEFT_BACK">VSMJ_IMG_PATH"user_left_back.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_USER_RIGHT_BACK">VSMJ_IMG_PATH"user_right_back.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_USER_UP_BACK">VSMJ_IMG_PATH"user_up_back.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_USER_LR_HIDE_BACK">VSMJ_IMG_PATH"user_lr_hide_back.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BRICK_USER_UD_HIDE_BACK">VSMJ_IMG_PATH"user_ud_hide_back.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_EAT_BASE">VSMJ_IMG_PATH"gx_vsmj_sign_eat_base.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_EAT_INVALID">VSMJ_IMG_PATH"gx_vsmj_sign_eat_invalid.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_EAT_HIGHLIGHT">VSMJ_IMG_PATH"gx_vsmj_sign_eat_highlight.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_EAT_0">VSMJ_IMG_PATH"gx_vsmj_sign_eat_0.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_EAT_1">VSMJ_IMG_PATH"gx_vsmj_sign_eat_1.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_EAT_2">VSMJ_IMG_PATH"gx_vsmj_sign_eat_2.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_PON_BASE">VSMJ_IMG_PATH"gx_vsmj_sign_pon_1.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_PON_INVALID">VSMJ_IMG_PATH"gx_vsmj_sign_pon_invalid.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_PON_HIGHLIGHT">VSMJ_IMG_PATH"gx_vsmj_sign_pon_highlight.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_GUN_BASE">VSMJ_IMG_PATH"gx_vsmj_sign_gun_base.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_GUN_INVALID">VSMJ_IMG_PATH"gx_vsmj_sign_gun_invalid.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_GUN_HIGHLIGHT">VSMJ_IMG_PATH"gx_vsmj_sign_gun_highlight.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_HOU_BASE">VSMJ_IMG_PATH"gx_vsmj_sign_hou_1.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_HOU_INVALID">VSMJ_IMG_PATH"gx_vsmj_sign_hou_invalid.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_HOU_HIGHLIGHT">VSMJ_IMG_PATH"gx_vsmj_sign_hou_highlight.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_CANCEL_BASE">VSMJ_IMG_PATH"gx_vsmj_sign_cancel.GIF"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_CANCEL_HIGHLIGHT">VSMJ_IMG_PATH"gx_vsmj_sign_cancel_highlight.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SPECIAL_LIOU_GU">VSMJ_IMG_PATH"gx_vsmj_sign_liou_gu.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_PEN_CURSOR_OFF">VSMJ_IMG_PATH"gx_vsmj_pen_cursor_off.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_PEN_CURSOR_ON">VSMJ_IMG_PATH"gx_vsmj_pen_cursor_on.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_8_FLOWER">VSMJ_IMG_PATH"score_8_flower.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_7_1_FLOWER">VSMJ_IMG_PATH"score_7_1_flower.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_ZE_MO">VSMJ_IMG_PATH"score_ze_mo.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_HUO_BY_GUN">VSMJ_IMG_PATH"score_hou_by_gun.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_MEN_CHIN">VSMJ_IMG_PATH"score_men_chin.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_MENCHIN_ZEMO">VSMJ_IMG_PATH"score_menchin_zemo.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_FLOWER_SEASON_SET">VSMJ_IMG_PATH"score_flower_season_set.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_FLOWER_PLANT_SET">VSMJ_IMG_PATH"score_flower_plant_set.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_SEA_MOON">VSMJ_IMG_PATH"score_sea_moon.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_ALL_ASK">VSMJ_IMG_PATH"score_chuan_chio.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_BIG_3_YUANG">VSMJ_IMG_PATH"score_big_3_yuang.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_SMALL_3_YUANG">VSMJ_IMG_PATH"score_small_3_yuang.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_CHUNG">VSMJ_IMG_PATH"score_chung.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_FA">VSMJ_IMG_PATH"score_fa.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_BAI">VSMJ_IMG_PATH"score_bai.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_BIG_4_WIND">VSMJ_IMG_PATH"score_big_4_shi.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_SMALL_4_WIND">VSMJ_IMG_PATH"score_small_4_shi.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_3_ENKE">VSMJ_IMG_PATH"score_3_enke.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_4_ENKE">VSMJ_IMG_PATH"score_4_enke.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_5_ENKE">VSMJ_IMG_PATH"score_5_enke.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_NUM_1_COLOR">VSMJ_IMG_PATH"score_chin_1_color.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_MIX_1_COLOR">VSMJ_IMG_PATH"score_mix_1_color.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_PAIR_PAIR_HOU">VSMJ_IMG_PATH"score_pair_pair_hou.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_SCORE_NOTHING">VSMJ_IMG_PATH"score_nothing.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_NUMBER_0">VSMJ_IMG_PATH"gx_VSMJ_number_0.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_NUMBER_1">VSMJ_IMG_PATH"gx_VSMJ_number_1.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_NUMBER_2">VSMJ_IMG_PATH"gx_VSMJ_number_2.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_NUMBER_3">VSMJ_IMG_PATH"gx_VSMJ_number_3.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_NUMBER_4">VSMJ_IMG_PATH"gx_VSMJ_number_4.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_NUMBER_5">VSMJ_IMG_PATH"gx_VSMJ_number_5.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_NUMBER_6">VSMJ_IMG_PATH"gx_VSMJ_number_6.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_NUMBER_7">VSMJ_IMG_PATH"gx_VSMJ_number_7.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_NUMBER_8">VSMJ_IMG_PATH"gx_VSMJ_number_8.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_NUMBER_9">VSMJ_IMG_PATH"gx_VSMJ_number_9.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_ARROWHEAD">VSMJ_IMG_PATH"gx_vsmj_arrowhead.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_TOP_SOLID">VSMJ_IMG_PATH"gx_vsmj_user_top_solid.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_BOTTOM_SOLID">VSMJ_IMG_PATH"gx_vsmj_user_bottom_solid.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_EATCASE_BG1">VSMJ_IMG_PATH"gx_vsmj_sign_eatcase_BG1.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_EATCASE_BG2">VSMJ_IMG_PATH"gx_vsmj_sign_eatcase_BG2.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_EATCASE_BG3">VSMJ_IMG_PATH"gx_vsmj_sign_eatcase_BG3.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_EATCASE_HIGHLIGHT">VSMJ_IMG_PATH"gx_vsmj_sign_eatcase_highlight.gif"</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_GUNCASE_BG1">VSMJ_IMG_PATH"gx_vsmj_sign_guncase_BG1.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_GUNCASE_BG2">VSMJ_IMG_PATH"gx_vsmj_sign_guncase_BG2.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_GUNCASE_BG3">VSMJ_IMG_PATH"gx_vsmj_sign_guncase_BG3.gif"</IMAGE>
	<IMAGE id="IMG_ID_GX_VSMJ_GUNCASE_HIGHLIGHT">VSMJ_IMG_PATH"gx_vsmj_sign_guncase_highlight.gif"</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_GAMES">VSMJ_IMG_PATH"gx_vsmj_Games.gif"</IMAGE>
#if defined(__MMI_TOUCH_SCREEN__)
#if defined(__MMI_GAME_VSMJ_240x400__) || defined(__MMI_GAME_VSMJ_320x480__)
    <IMAGE id="IMG_ID_GX_VSMJ_BACK_UP">VSMJ_IMG_PATH"gx_vsmj_back_up.bmp"</IMAGE>
    <IMAGE id="IMG_ID_GX_VSMJ_BACK_DOWN">VSMJ_IMG_PATH"gx_vsmj_back_down.bmp"</IMAGE>
#endif /*__MMI_GAME_VSMJ_240x400__) || defined(__MMI_GAME_VSMJ_320x480__*/
#endif /*__MMI_TOUCH_SCREEN__*/

    /* VSMJ NVRAM */
    <CACHEDATA type="byte" id="NVRAM_GX_VSMJ_LEVEL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_VSMJ_LEVEL1" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_VSMJ_LEVEL2" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_GX_VSMJ_LEVEL3" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
#endif /* IS_VSMJ_BASE_GAME */


#ifdef __MMI_MOTION_APP__

<INCLUDE file="mmi_rp_app_mainmenu_def.h,GlobalResDef.h"/>

extern void mmi_motion_dice_highlight_start(void);
extern void mmi_motion_dice_highlight_game_setting(void);
extern void mmi_motion_dice_highlight_event_setting(void);
extern void mmi_motion_dice_highlight_help(void);
extern void mmi_motion_dice_highlight_event_add(void);
extern void mmi_motion_dice_highlight_event_remove(void);
extern void mmi_motion_dice_highlight_event_remove_all(void);
extern void mmi_motion_dice_highlight_event_edit(void);
extern void mmi_motion_dice_highlight_event_view_image(void);
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
extern void mmi_motion_dice_highlight_event_play_video(void);
#endif
extern void mmi_motion_dice_highlight_event_file_select(void);

#ifdef IS_DICE_BASE_MOTIONGAME
#if defined(__MMI_MOTIONGAME_DICE_176x220__)
    #define MMI_MOTIONDICE_IMAGE_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\Dice_176x220\\\\"
#elif defined(__MMI_MOTIONGAME_DICE_240x320__)
    #define MMI_MOTIONDICE_IMAGE_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\Dice_240x320\\\\"
#elif defined(__MMI_MOTIONGAME_DICE_320x240__)
    #define MMI_MOTIONDICE_IMAGE_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\Dice_320x240\\\\"
#elif defined(__MMI_MOTIONGAME_DICE_240x400__)
    #define MMI_MOTIONDICE_IMAGE_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\Dice_240x400\\\\"
#elif defined(__MMI_MOTIONGAME_DICE_320x480__)
    #define MMI_MOTIONDICE_IMAGE_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\Dice_320x480\\\\"
#endif

    <SCREEN id="SCR_ID_MOTION_DICE_APP"/>
    <SCREEN id="SCR_ID_MOTION_DICE_PLAY"/>
    <SCREEN id="SCR_ID_MOTION_DICE_SHOW_EVENT"/>
    <SCREEN id="SCR_ID_MOTION_DICE_GAME_SETTING"/>
    <SCREEN id="SCR_ID_MOTION_DICE_EVENT_SETTING"/>
    <SCREEN id="SCR_ID_MOTION_DICE_HELP"/>
    <SCREEN id="SCR_ID_MOTION_DICE_EVENT_OPTION"/>
    <SCREEN id="SCR_ID_MOTION_DICE_EVENT_EDIT"/>
    <SCREEN id="SCR_ID_MOTION_DICE_EVENT_TEXT_EDITOR"/>
    <SCREEN id="SCR_ID_MOTION_DICE_EVENT_TEXT_EDITOR_OPTION"/>
    <SCREEN id="SCR_ID_MOTION_DICE_EVENT_FILE_SELECT_OPTION"/>
    <SCREEN id="SCR_ID_MOTION_DICE_EVENT_FILE_VIEW_IMAGE"/>
    <SCREEN id="SCR_ID_MOTION_DICE_EVENT_FILE_PLAY_VIDEO"/>
    <SCREEN id="NUM_OF_MOTION_DICE_SCR_ID"/>
    
    <STRING id="STR_ID_MOTION_DICE_APP"/>
    <STRING id="STR_ID_MOTION_DICE_GAME_SETTING"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_SETTING"/>
    <STRING id="STR_ID_MOTION_DICE_DICE_COUNT"/>
    <STRING id="STR_ID_MOTION_DICE_SHOW_EVENT"/>
    <STRING id="STR_ID_MOTION_DICE_SOUND_SWITCH"/>
    <STRING id="STR_ID_MOTION_DICE_OPTION_ADD"/>
    <STRING id="STR_ID_MOTION_DICE_OPTION_REMOVE"/>
    <STRING id="STR_ID_MOTION_DICE_OPTION_EDIT"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_EDIT"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_MATCH_NUM"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_TEXT"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_DEFAULT_TEXT"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_EFFECT_FILE"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_FILE_SELECT"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_EDITOR_TITLE"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_PLAY_VIDEO"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_PLAY_AUDIO"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_VIEW_IMAGE"/>
    <STRING id="STR_ID_MOTION_DICE_REMOVE_CONFIRM"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_REMOVED"/>
    <STRING id="STR_ID_MOTION_DICE_NUMBER_REGION"/>
    <STRING id="STR_ID_MOTION_DICE_DUP_NUMBER"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_FULL"/>
    <STRING id="STR_ID_MOTION_DICE_1"/>
    <STRING id="STR_ID_MOTION_DICE_2"/>
    <STRING id="STR_ID_MOTION_DICE_3"/>
    <STRING id="STR_ID_MOTION_DICE_4"/>
    <STRING id="STR_ID_MOTION_DICE_5"/>
    <STRING id="STR_ID_MOTION_DICE_INVALID_FILE"/>
    <STRING id="STR_ID_MOTION_DICE_OPTION_REMOVE_ALL"/>
    <STRING id="STR_ID_MOTION_DICE_EVENT_ALL_REMOVED"/>
    <STRING id="STR_ID_MOTION_DICE_REMOVE_ALL_CONFIRM"/>
    <STRING id="STR_ID_MOTION_DICE_HELP_START"/>
    <STRING id="STR_ID_MOTION_DICE_HELP_CONTENT_1"/>
    <STRING id="STR_ID_MOTION_DICE_HELP_CONTENT_2"/>
    <STRING id="STR_ID_MOTION_DICE_HELP_CONTENT_3"/>
    <STRING id="STR_ID_MOTION_DICE_HELP_END"/>
    
	<IMAGE id="IMG_ID_MOTION_DICE_APP">MMI_MOTIONDICE_IMAGE_PATH"dice_app.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_1">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_2">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_3">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_3.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_4">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_4.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_5">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_5.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_6">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_6.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_7">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_7.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_8">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_8.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_9">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_9.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_10">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_10.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_11">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_11.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_12">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_12.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_13">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_13.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_14">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_14.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_15">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_15.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_16">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_16.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_17">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_17.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_18">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_18.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_19">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_19.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_20">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_20.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_21">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_21.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_22">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_22.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_23">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_23.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_24">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_24.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_25">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_25.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_26">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_26.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_27">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_27.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_28">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_28.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_29">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_29.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ICON_30">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_30.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_1">MMI_MOTIONDICE_IMAGE_PATH"dice_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_2">MMI_MOTIONDICE_IMAGE_PATH"dice_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_3">MMI_MOTIONDICE_IMAGE_PATH"dice_3.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_4">MMI_MOTIONDICE_IMAGE_PATH"dice_4.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_5">MMI_MOTIONDICE_IMAGE_PATH"dice_5.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_6">MMI_MOTIONDICE_IMAGE_PATH"dice_6.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ROLL_1">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_01.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ROLL_2">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_02.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ROLL_3">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_03.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ROLL_4">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_04.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ROLL_5">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_05.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ROLL_6">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_06.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ROLL_7">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_07.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ROLL_8">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_08.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ROLL_9">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_09.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ROLL_10">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_10.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ROLL_11">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_11.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_ROLL_12">MMI_MOTIONDICE_IMAGE_PATH"dice_roll_12.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_EVENT_1">MMI_MOTIONDICE_IMAGE_PATH"dice_event_1.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_EVENT_2">MMI_MOTIONDICE_IMAGE_PATH"dice_event_2.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_EVENT_3">MMI_MOTIONDICE_IMAGE_PATH"dice_event_3.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_EVENT_4">MMI_MOTIONDICE_IMAGE_PATH"dice_event_4.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_EVENT_5">MMI_MOTIONDICE_IMAGE_PATH"dice_event_5.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_EVENT_6">MMI_MOTIONDICE_IMAGE_PATH"dice_event_6.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_PLAY_BG">MMI_MOTIONDICE_IMAGE_PATH"dice_bg.gif"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_EVENT_BG">MMI_MOTIONDICE_IMAGE_PATH"dice_event_bg.gif"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_EVENT_DEFAULT_IMG">MMI_MOTIONDICE_IMAGE_PATH"dice_event_def.gif"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_FX_ICON_DUMMY">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_dummy.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_FX_ICON_AUD">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_aud.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_FX_ICON_VDO">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_vdo.bmp"</IMAGE>
	<IMAGE id="IMG_ID_MOTION_DICE_FX_ICON_IMG">MMI_MOTIONDICE_IMAGE_PATH"dice_icon_img.bmp"</IMAGE>
#ifdef __MMI_TOUCH_SCREEN__
    <IMAGE id="IMG_ID_MOTION_DICE_EVENT_BACK">MMI_MOTIONDICE_IMAGE_PATH"dice_back.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DICE_EVENT_BACK_DOWN">MMI_MOTIONDICE_IMAGE_PATH"dice_back_down.bmp"</IMAGE>
#endif
#ifdef __MMI_BACKGROUND_CALL__
    <IMAGE id="IMG_ID_MOTION_DICE_BG_CALL_VIDEO">MMI_MOTIONDICE_IMAGE_PATH"dice_event_Video.gif"</IMAGE>
#endif

    <MENU id="MENU_ID_MOTION_DICE_APP" type="OPTION" str="STR_ID_MOTION_DICE_APP">
        <MENUITEM_ID>MENU_ID_MOTION_DICE_START</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_GAME_SETTING</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_EVENT_SETTING</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_HELP</MENUITEM_ID></MENU>
	<MENUITEM id="MENU_ID_MOTION_DICE_START" str="STR_GLOBAL_START"/>
	<MENUITEM id="MENU_ID_MOTION_DICE_GAME_SETTING" str="STR_ID_MOTION_DICE_GAME_SETTING"/>
	<MENUITEM id="MENU_ID_MOTION_DICE_EVENT_SETTING" str="STR_ID_MOTION_DICE_EVENT_SETTING"/>
    <MENUITEM id="MENU_ID_MOTION_DICE_HELP" str="STR_GLOBAL_HELP"/>

	<MENU id="MENU_ID_MOTION_DICE_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_MOTION_DICE_OPTION_ADD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_OPTION_REMOVE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_OPTION_REMOVE_ALL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_OPTION_EDIT</MENUITEM_ID></MENU>
	<MENUITEM id="MENU_ID_MOTION_DICE_OPTION_ADD" str="STR_ID_MOTION_DICE_OPTION_ADD"/>
	<MENUITEM id="MENU_ID_MOTION_DICE_OPTION_REMOVE" str="STR_ID_MOTION_DICE_OPTION_REMOVE"/>
    <MENUITEM id="MENU_ID_MOTION_DICE_OPTION_REMOVE_ALL" str="STR_ID_MOTION_DICE_OPTION_REMOVE_ALL"/>
	<MENUITEM id="MENU_ID_MOTION_DICE_OPTION_EDIT" str="STR_ID_MOTION_DICE_EVENT_EDIT"/>

	<MENU id="MENU_ID_MOTION_DICE_EDT_OPT_ROOT" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_MOTION_DICE_EDT_OPT_DONE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_EDT_OPT_CANCEL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_EDT_OPT_INPUT</MENUITEM_ID></MENU>
	<MENUITEM id="MENU_ID_MOTION_DICE_EDT_OPT_DONE" str="STR_GLOBAL_DONE"/>
	<MENUITEM id="MENU_ID_MOTION_DICE_EDT_OPT_CANCEL" str="STR_GLOBAL_CANCEL"/>
	<MENUITEM id="MENU_ID_MOTION_DICE_EDT_OPT_INPUT" str="STR_GLOBAL_INPUT_METHOD"/>

	<MENU id="MENU_ID_MOTION_DICE_EVENT_FILE_SELECT_ROOT" type="OPTION" str="STR_GLOBAL_OPTIONS" /* str="STR_ID_MOTION_DICE_EVENT_EFFECT_FILE" */>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_EVENT_FILE_SELECT</MENUITEM_ID></MENU>
	<MENUITEM id="MENU_ID_MOTION_DICE_EVENT_FILE_SELECT" str="STR_ID_MOTION_DICE_EVENT_FILE_SELECT" highlight="mmi_motion_dice_highlight_event_file_select"/>

	<MENU id="MENU_ID_MOTION_DICE_EVENT_VIEW_IMAGE_ROOT" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_MOTION_DICE_EVENT_VIEW_IMAGE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_EVENT_FILE_SELECT</MENUITEM_ID></MENU>
	<MENUITEM id="MENU_ID_MOTION_DICE_EVENT_VIEW_IMAGE" str="STR_ID_MOTION_DICE_EVENT_VIEW_IMAGE" highlight="mmi_motion_dice_highlight_event_view_image"/>

	<MENU id="MENU_ID_MOTION_DICE_EVENT_PLAY_VIDEO_ROOT" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_MOTION_DICE_EVENT_PLAY_VIDEO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_EVENT_FILE_SELECT</MENUITEM_ID></MENU>
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
	<MENUITEM id="MENU_ID_MOTION_DICE_EVENT_PLAY_VIDEO" str="STR_ID_MOTION_DICE_EVENT_PLAY_VIDEO" highlight="mmi_motion_dice_highlight_event_play_video"/>
#endif

	<MENU id="MENU_ID_MOTION_DICE_EVENT_PLAY_AUDIO_ROOT" type="OPTION" str="STR_ID_MOTION_DICE_EVENT_EFFECT_FILE">
        <MENUITEM_ID>MENU_ID_MOTION_DICE_EVENT_PLAY_AUDIO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DICE_EVENT_FILE_SELECT</MENUITEM_ID></MENU>
	<MENUITEM id="MENU_ID_MOTION_DICE_EVENT_PLAY_AUDIO" str="STR_ID_MOTION_DICE_EVENT_PLAY_AUDIO"/>

    /* Motion Dice NVRAM */
    <CACHEDATA type="byte" id="NVRAM_MOTION_DICE_DICE_COUNT" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_MOTION_DICE_EVENT_ON" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_MOTION_DICE_SOUND_ON" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_MOTION_DICE_VOL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
#endif /* IS_DICE_BASE_MOTIONGAME */


#ifdef IS_DJ_BASE_MOTIONGAME
#include "MotionDJGprots.h"
#if defined(__MMI_MOTIONGAME_DJ_176x220__)
    #define MOTION_DJ_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\DJ_176x220\\\\"
#elif defined(__MMI_MOTIONGAME_DJ_240x320__)
    #define MOTION_DJ_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\DJ_240x320\\\\"
#elif defined(__MMI_MOTIONGAME_DJ_320x240__)
    #define MOTION_DJ_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\DJ_320x240\\\\"
#elif defined(__MMI_MOTIONGAME_DJ_240x400__)
    #define MOTION_DJ_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\DJ_240x400\\\\"
#elif defined(__MMI_MOTIONGAME_DJ_320x480__)
    #define MOTION_DJ_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\DJ_320x480\\\\"
#endif
#if defined(__MMI_MOTIONGAME_DJ_320x480__)
    #define MOTION_DJ_IMG_TYPE ".png"
#else
    #define MOTION_DJ_IMG_TYPE ".bmp"
#endif
    <SCREEN id="SCR_ID_MOTION_DJ_APP"/>
    <SCREEN id="SCR_ID_MOTION_DJ_SETTING"/>
    <SCREEN id="SCR_ID_MOTION_DJ_EDIT"/>
    <SCREEN id="SCR_ID_MOTION_DJ_PLAY"/>
    <SCREEN id="SCR_ID_MOTION_DJ_DUMMY"/>
    <SCREEN id="SCR_ID_MOTION_DJ_VOL_SETTING"/>
    <SCREEN id="SCR_ID_MOTION_DJ_HELP"/>
    <SCREEN id="NUM_OF_MOTION_DJ_SCR_ID"/>
    
    <STRING id="STR_ID_MOTION_DJ_APP"/>
    <STRING id="STR_ID_MOTION_DJ_START"/>
    <STRING id="STR_ID_MOTION_DJ_SETTING"/>
    <STRING id="STR_ID_MOTION_DJ_VOL_SETTING"/>
    <STRING id="STR_ID_MOTION_DJ_HELP"/>
    <STRING id="STR_ID_MOTION_DJ_HELP_CONTENT"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_TITLE_1"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_TITLE_2"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_TITLE_3"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_TITLE_1"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_TITLE_2"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_TITLE_3"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_0"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_1"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_2"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_3"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_4"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_5"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_6"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_7"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_8"/>
    <STRING id="STR_ID_MOTION_DJ_INSTRUMENT_9"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_0"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_1"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_2"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_3"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_4"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_5"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_6"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_7"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_8"/>
    <STRING id="STR_ID_MOTION_DJ_VOCAL_9"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_0"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_1"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_2"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_3"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_4"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_5"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_6"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_7"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_8"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_9"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_STAR"/>
    <STRING id="STR_ID_MOTION_DJ_KEY_POUND"/>
    <STRING id="STR_ID_MOTION_DJ_EDIT_AUDIO"/>
    <STRING id="STR_ID_MOTION_DJ_EDIT_TRIGGER"/>
    <STRING id="STR_ID_MOTION_DJ_EDIT_KEY"/>
    <STRING id="STR_ID_MOTION_DJ_EDIT_TRIGGER_AUTO"/>
    <STRING id="STR_ID_MOTION_DJ_EDIT_TRIGGER_SHAKE"/>
    <STRING id="STR_ID_MOTION_DJ_EDIT_TRIGGER_KEY_PRESS"/>
    <STRING id="STR_ID_MOTION_DJ_NOTIFY_HAS_AUTO"/>
    <STRING id="STR_ID_MOTION_DJ_NOTIFY_HAS_SHAKE"/>
    <STRING id="STR_ID_MOTION_DJ_NOTIFY_HAS_SHAKE_SAME_KEY"/>
    <STRING id="STR_ID_MOTION_DJ_NOTIFY_HAS_PRESS_SAME_KEY"/>
    <STRING id="STR_ID_MOTION_DJ_NOTIFY_EMPTY_TRIGGER"/>
    <STRING id="STR_ID_MOTION_DJ_NOTIFY_EMPTY_KEY"/>

    <IMAGE id="IMG_ID_MOTION_DJ_APP">MOTION_DJ_IMG_PATH"dj_app.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_TRIGGER_NONE">MOTION_DJ_IMG_PATH"dj_icon_none.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_TRIGGER_AUTO">MOTION_DJ_IMG_PATH"dj_icon_auto.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_TRIGGER_SHAKE">MOTION_DJ_IMG_PATH"dj_icon_shake.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_TRIGGER_PRESS">MOTION_DJ_IMG_PATH"dj_icon_press.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_DUMMY">MOTION_DJ_IMG_PATH"dj_key_dummy.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_0">MOTION_DJ_IMG_PATH"dj_key_0.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_1">MOTION_DJ_IMG_PATH"dj_key_1.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_2">MOTION_DJ_IMG_PATH"dj_key_2.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_3">MOTION_DJ_IMG_PATH"dj_key_3.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_4">MOTION_DJ_IMG_PATH"dj_key_4.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_5">MOTION_DJ_IMG_PATH"dj_key_5.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_6">MOTION_DJ_IMG_PATH"dj_key_6.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_7">MOTION_DJ_IMG_PATH"dj_key_7.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_8">MOTION_DJ_IMG_PATH"dj_key_8.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_9">MOTION_DJ_IMG_PATH"dj_key_9.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_STAR">MOTION_DJ_IMG_PATH"dj_key_star.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_ICON_KEY_POUND">MOTION_DJ_IMG_PATH"dj_key_pound.bmp"</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_BG">MOTION_DJ_IMG_PATH"dj_play_bg.gif"</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_NONE">MOTION_DJ_IMG_PATH"dj_play_none"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_AUTO">MOTION_DJ_IMG_PATH"dj_play_auto"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_SHAKE">MOTION_DJ_IMG_PATH"dj_play_shake"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_PRESS">MOTION_DJ_IMG_PATH"dj_play_press"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_NONE_SEL">MOTION_DJ_IMG_PATH"dj_play_auto_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_AUTO_SEL">MOTION_DJ_IMG_PATH"dj_play_auto_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_SHAKE_SEL">MOTION_DJ_IMG_PATH"dj_play_shake_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_PRESS_SEL">MOTION_DJ_IMG_PATH"dj_play_press_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_0">MOTION_DJ_IMG_PATH"dj_play_key_0"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_1">MOTION_DJ_IMG_PATH"dj_play_key_1"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_2">MOTION_DJ_IMG_PATH"dj_play_key_2"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_3">MOTION_DJ_IMG_PATH"dj_play_key_3"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_4">MOTION_DJ_IMG_PATH"dj_play_key_4"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_5">MOTION_DJ_IMG_PATH"dj_play_key_5"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_6">MOTION_DJ_IMG_PATH"dj_play_key_6"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_7">MOTION_DJ_IMG_PATH"dj_play_key_7"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_8">MOTION_DJ_IMG_PATH"dj_play_key_8"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_9">MOTION_DJ_IMG_PATH"dj_play_key_9"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_STAR">MOTION_DJ_IMG_PATH"dj_play_key_star"MOTION_DJ_IMG_TYPE</IMAGE>    
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_POUND">MOTION_DJ_IMG_PATH"dj_play_key_pound"MOTION_DJ_IMG_TYPE</IMAGE>
    
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_0_SEL">MOTION_DJ_IMG_PATH"dj_play_key_0_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_1_SEL">MOTION_DJ_IMG_PATH"dj_play_key_1_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_2_SEL">MOTION_DJ_IMG_PATH"dj_play_key_2_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_3_SEL">MOTION_DJ_IMG_PATH"dj_play_key_3_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_4_SEL">MOTION_DJ_IMG_PATH"dj_play_key_4_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_5_SEL">MOTION_DJ_IMG_PATH"dj_play_key_5_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_6_SEL">MOTION_DJ_IMG_PATH"dj_play_key_6_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_7_SEL">MOTION_DJ_IMG_PATH"dj_play_key_7_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_8_SEL">MOTION_DJ_IMG_PATH"dj_play_key_8_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_9_SEL">MOTION_DJ_IMG_PATH"dj_play_key_9_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_STAR_SEL">MOTION_DJ_IMG_PATH"dj_play_key_star_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_KEY_POUND_SEL">MOTION_DJ_IMG_PATH"dj_play_key_pound_sel"MOTION_DJ_IMG_TYPE</IMAGE>
    
#ifdef __MMI_TOUCH_SCREEN__
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_BACK">MOTION_DJ_IMG_PATH"Dj_back.gif"</IMAGE>
    <IMAGE id="IMG_ID_MOTION_DJ_PLAY_BACK_DOWN">MOTION_DJ_IMG_PATH"Dj_back_down.gif"</IMAGE>
#endif

    <MENU id="MENU_ID_MOTION_DJ_APP" type="OPTION" str="STR_ID_MOTION_DJ_APP">
        <MENUITEM_ID>MENU_ID_MOTION_DJ_START</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DJ_SETTING</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DJ_VOL_SETTING</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_MOTION_DJ_HELP</MENUITEM_ID></MENU>
    <MENUITEM id="MENU_ID_MOTION_DJ_START" str="STR_ID_MOTION_DJ_START" highlight="mmi_motion_dj_highlight_start"/>
    <MENUITEM id="MENU_ID_MOTION_DJ_SETTING" str="STR_ID_MOTION_DJ_SETTING" highlight="mmi_motion_dj_highlight_setting"/>
    <MENUITEM id="MENU_ID_MOTION_DJ_VOL_SETTING" str="STR_ID_MOTION_DJ_VOL_SETTING" highlight="mmi_motion_dj_highlight_vol_setting"/>
    <MENUITEM id="MENU_ID_MOTION_DJ_HELP" str="STR_GLOBAL_HELP" highlight="mmi_motion_dj_highlight_help"/>
    
    /* Motion DJ NVRAM */
    <CACHEDATA type="byte" id="NVRAM_MOTION_DJ_VOLUMN" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
#endif /* IS_DJ_BASE_MOTIONGAME */    
#endif /* __MMI_MOTION_APP__ */

/******************************************************* Motion Game End ****************************************************/


/******************************************************* Game Framework Start ****************************************************/
    <SCREEN id="SCR_ID_GAME"/>
    <SCREEN id="SCR_ID_GAME_SETTING"/>
    <SCREEN id="SCR_ID_MOTION_APP"/>
    <SCREEN id="SCR_ID_3D_GAME_LIST"/>
    <SCREEN id="SCR_ID_3D_GAME"/>
    
    <SCREEN id="GFX_MENU_SCREEN"/>
    <SCREEN id="GFX_GAME_SCREEN"/>
    <SCREEN id="GFX_LEVEL_SCREEN"/>
    <SCREEN id="GFX_GRADE_SCREEN"/>
    <SCREEN id="GFX_HELP_SCREEN"/>
    <SCREEN id="GFX_GAMEOVER_SCREEN"/>
    
	<STRING id="STR_GAME_CAPTION"/>
	<STRING id="STR_GAME_LSK"/>
	<STRING id="STR_GAME_NEW"/>
	<STRING id="STR_GAME_LEVEL"/>
	<STRING id="STR_GAME_GRADE"/>
	<STRING id="STR_GAME_RESET_GRADE_CONFIRM"/>
	<STRING id="STR_GAME_HELP"/>
	<STRING id="STR_GAME_RESUME"/>
	<STRING id="STR_GAME_SCORE"/>
	<STRING id="STR_MENU3105_GAMES"/>
	<STRING id="STR_ID_GAME_SETTING"/>
	<IMAGE id="IMG_ID_GAME_SETTING">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Funandgame\\\\Gamesetting\\\\SB_FGST.bmp"</IMAGE>
	<STRING id="STR_ID_GAME_SETTING_AUD"/>
#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
	<STRING id="STR_ID_GAME_SETTING_MULTICHANNEL_BACKGROUND_MUSIC"/>
	<STRING id="STR_ID_GAME_SETTING_MULTICHANNEL_SOUND_EFFECT"/>
#endif
	<STRING id="STR_ID_GAME_SETTING_VIB"/>
	<IMAGE id="IMG_ID_GAME_SETTING_AUD">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Funandgame\\\\Gamesetting\\\\SB_GAMEAUD.bmp"</IMAGE>
	#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
		<IMAGE id="IMG_ID_GAME_SETTING_BACK_AUD">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Funandgame\\\\Gamesetting\\\\SB_GAMEBACKAUD.bmp"</IMAGE>
#endif
	<IMAGE id="IMG_ID_GAME_SETTING_VIB">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Funandgame\\\\Gamesetting\\\\SB_GAMEVIB.bmp"</IMAGE>
    <IMAGE id="IMG_ID_GAME_SETTING_VOL">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Funandgame\\\\Gamesetting\\\\SB_GAMEVOLUME.bmp"</IMAGE>
	<IMAGE id="IMG_MENU3105_GAMES">CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\FunANDGame\\\\SB_FGGAME.bmp"</IMAGE>
	<IMAGE id="IMG_ID_GAME_SUBLCD_ICON">CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\sb_game.bmp"</IMAGE>

#if defined(__MMI_GAME_MENU__) || defined(__MMI_GAME__)
	////TODO
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU3105_GAMES, mmi_game_highlight_app);
#endif

    /* Game Framework NVRAM */
    <CACHEDATA type="byte" id="NVRAM_GFX_AUDIO_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> 2D/Motion Game </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_GFX_AUDIO_VOLUMN" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> 2D/Motion Game </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_GFX_VIBRATION_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> 2D/Motion Game </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_GFX_BACKGROUND_MUSIC_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> 2D/Motion Game </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_GFX_SOUND_EFFECT_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> 2D/Motion Game </DESCRIPTION>
    </CACHEDATA>
    
</APP>
#endif


