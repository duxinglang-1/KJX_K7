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
 *  callback_mgr.res
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Resource file.
 *
 * Author:
 * -------
 *  Yan Liang (mtk80499)
 *
 *                      
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 25 2012 yake.yang
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * Pluto slim pach back to 11B: add mmi ap DCM load/unload event and handler.
 *
 * 12 25 2012 kavin.ma
 * [MAUI_03295611] Check in Pluto slim modification into 11B
 * .
 *
 * 12 25 2012 yanchao.yang
 * [MAUI_03257448] [phbsrv]SLIM check in
 * .
 *
 * 07 10 2012 muyi.lan
 * [MAUI_03213393] [New feature] NCenter support pure key
 * .
 *
 * 06 18 2012 hua.tian
 * [MAUI_03204333] [Cosmos SLIM] restore launcher history if OOM happens
 * .
 *
 * 06 17 2012 hua.tian
 * [MAUI_03200489] [KHAN50][COSMOS][Camcorder]  "Stop" function can't work this case
 * If no more application to stop in oom list, just display a popup don't make the assert happen.
 *
 * 05 24 2012 hongxi.shi
 * [MAUI_03187622] [check in] MRE autostart and safe mode
 * .
 *
 * 05 15 2012 linyong.shi
 * [MAUI_03185316] MMI Timer Expansion for user custom timer
 * .MMI Timer Expansion for user custom timer
 *
 * 05 10 2012 avinash.vyas
 * [MAUI_03177383] should update backlight level at once after change backlight at n-center
 * .
 *
 * 04 25 2012 hua.tian
 * [MAUI_03175060] Fix touch build error
 * add compile option for touch clam handler.
 *
 * 04 23 2012 fachao.zhang
 * [MAUI_03170281] [Pre-SQC] Brigtness settings should change in Home quick setting widget also
 * .
 *
 * 04 18 2012 yan.liang
 * [MAUI_03120665] [MMI FRM] Touch enhance check in
 * power off touch panel when clam is close
 *
 * 04 13 2012 fachao.zhang
 * [MAUI_03167062] after insert USB,should not lock screen at once
 * .
 *
 * 03 27 2012 zhenhai.zhao
 * [MAUI_03157575] sleep In / Out mode for VFX
 * contain sleep in/out mode state for vfx instead check backlight state.
 *
 * 03 26 2012 mengmeng.cao
 * [MAUI_03065523] [FM Request] 2-mic NR test mode
 * .
 *
 * 01 24 2012 inderpreet.singh
 * [MAUI_03114975] [Representative CR] Feature Name: MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM
 * Check-in Feature Name: MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM.
 *
 * 01 04 2012 sijia.long
 * [MAUI_03077314] [CTP][CapPXS] Implement CapPXS on GOODIX CTP
 * .
 *
 * 12 28 2011 chuangjie.xia
 * [MAUI_03106629] [UE]subLCD show wallpaper before showing Logo when open subLCD
 * .
 *
 * 11 10 2011 wenyan.yang
 * [MAUI_03077421] [Image viewer refine]enable close
 * .
 *
 * 09 23 2011 paul.deng
 * [MAUI_03035532] Opera compile option change
 * .
 *
 * 09 20 2011 viki.hung
 * [MAUI_03032474] [VFX] Backlight off animation
 * .
 *
 * 09 04 2011 wenke.zhou
 * [MAUI_03017486] CR for WLAN prefer stage-I check-in
 * .
 *
 * 09 04 2011 fachao.zhang
 * [MAUI_03020093] [GPIO] backlight off event notify to show fancy animation
 * .
 *
 * 09 02 2011 ning.gu
 * [MAUI_03012122] MMI TASK execute too long under backlight off
 * .
 *
 * 08 30 2011 ying.fang
 * [MAUI_03016263] [ProvBox] Support new code of ProvBox Split
 * .
 *
 * 08 23 2011 huilong.yin
 * [MAUI_03011220] [Need Patch][Build Error] 11B.W11.36 build error for LUFFY76V2_1G512_hspa(COSMOS_HVGA)
 * .
 *
 * 08 15 2011 yiquan.he
 * [MAUI_03004472] Launch pen calibration only on first-time touch
 * .
 *
 * 08 11 2011 aidan.hung
 * [MAUI_03003259] [FTO FMGR] Remove some dummy functions
 * Remove Pluto dummy functions
 *
 * 07 07 2011 guochang.fan
 * [MAUI_02977661] Slim code revise
 * .
 *
 * 06 28 2011 sijia.long
 * [MAUI_02944292] For CMCC BWFWT
 * .
 *
 * 06 22 2011 fachao.zhang
 * [MAUI_02940571] [CMCC TD Black White FWT] check in for calllog/gpio
 * .
 *
 * 06 11 2011 hua.tian
 * [MAUI_02960481] [COSMOS1.1] ASM2.1 check in
 * .
 *
 * 05 31 2011 hua.tian
 * [MAUI_02952867] [Remove Block Interrupt Mechanism] Step1, wrap by compile option
 * .
 *
 * 05 25 2011 sijia.long
 * [MAUI_02928835] For Gemini+ build error
 * .
 *
 * 05 16 2011 jishu.lv
 * [MAUI_02942989] [check-in]Softkey default proc
 * default proc.
 *
 * 03 25 2011 inderpreet.singh
 * [MAUI_02871859] [Cosmos Remove Useless Code] plutommi\mmi\unifiedcomposer\unifiedcomposersrc\DummyFileForCosmos.c
 * Remove useless code.
 *
 * 03 22 2011 weilun.liu
 * [MAUI_02899518] [Idle] add screen saver compile option
 * add compile option __MMI_SCREEN_SAVER__
 *
 * 02 25 2011 jianhua.zhao
 * [MAUI_02653570] [USB] Remove split
 * .
 *
 * 02 21 2011 ch.ko
 * [MAUI_02871894] [Cosmos Remove Useless Code] plutommi\MMI\ShellApp\ShellAppSrc\ShellApp.c
 * Wrap Cosmos compile option.
 *
 * 02 11 2011 cong.zhou
 * [MAUI_02651286] Check in netset service revise
 * .
 *
 * 02 11 2011 kefeng.lian
 * [MAUI_02651125] [EM] remove __MMI_EM_V2_SUPPORT__
 * .
 *
 * 02 08 2011 ray.wu
 * [MAUI_02867812] [Removed Files from p4 service]
 * .
 *
 * 01 18 2011 yan.liang
 * [MAUI_02648783] [MMI FRM] Pre/Post Touch event check in
 * .
 *
 * 01 07 2011 ch.ko
 * [MAUI_02859234] [Home] Wrap shell source codes with package compile option
 * Check-in patch.
 *
 * 01 07 2011 vikas.srivastava
 * [MAUI_02448102] DLAgent Check-in to MAUI and 11A
 * .
 *
 * 12 31 2010 yan.liang
 * [MAUI_02643275] [MMI FRM]Key Touch HAL check in
 * Do not play key tone in  COSMOS
 *
 * 12 27 2010 julie.cheng
 * [MAUI_02836514] Cosmos check in MAUI
 * .
 *
 * 12 23 2010 diamond.lee
 * [MAUI_02732666] Gemini+][SZ][CMCC]should have a CSK icon and press CSK can work
 * .
 *
 * 12 21 2010 diamond.lee
 * [MAUI_02851627] [MMI][Gemini+] phase out bootupmenuctrl.c
 * .
 *
 * 12 14 2010 yan.liang
 * [MAUI_02644068] [MMI FRM]Volumn key new requirement
 * <saved by Perforce>
 *
 * 12 14 2010 diamond.lee
 * [MAUI_02846075] [MMI][Gemini+] 10A and MAUI check in
 * .
 *
 * 12 01 2010 fachao.zhang
 * [MAUI_02640419] [FTO] calllog check in
 * .
 *
 * 12 01 2010 jianhua.zhao
 * [MAUI_02642540] Fix MAUIW1049 build error
 * .
 *
 * 11 26 2010 yiruei.wu
 * [MAUI_02836047] FTO check-in
 * FTO check in
 *
 * 11 25 2010 kinse.lin
 * [MAUI_02837562] Player should not play audio from speaker before pop up show.
 * .
 *
 * 11 23 2010 yiruei.wu
 * [MAUI_02411639] Remove obsolete code
 * Remove obsolete code in SimDetection.c & ShutdownApp.c
 *
 * 11 19 2010 avinash.vyas
 * [MAUI_02445082] Check in for Push FTO
 * .
 *
 * 11 16 2010 emily.lin
 * [MAUI_02838711] [Opera ADP][USB FTO revise] Add wrapper opera_adp_exit_usb_ms_callback as the callback of EVT_ID_USB_EXIT_MS_MODE
 * .
 *
 * 11 15 2010 julie.cheng
 * [MAUI_02836514] Cosmos check in MAUI
 * fix potential issues on non-Cosmos projects
 *
 * 11 11 2010 yiruei.wu
 * [MAUI_02837028] Revise resource
 * Move back event resource from callback_mgr.res
 *
 * 11 10 2010 yenhung.chen
 * [MAUI_02836686] [SML Menu] move callback manager
 * .
 *
 * 11 09 2010 julie.cheng
 * [MAUI_02836514] Cosmos check in MAUI
 * .
 *
 * 11 05 2010 hongxi.shi
 * [MAUI_02638187] [check in] mmi auto rotate check in
 * .
 *
 * 11 04 2010 diamond.lee
 * [MAUI_02833993] [MMI][Gemini+] MTPNP code remove
 * .
 *
 * 11 03 2010 leo.hu
 * [MAUI_02834494] Use callback manager instead of callback in shutdownapp.c
 * .
 *
 * 11 02 2010 diamond.lee
 * [MAUI_02833993] [MMI][Gemini+] MTPNP code remove
 * .
 *
 * 11 02 2010 weilun.liu
 * [MAUI_02833901] [Idle] support SIM Refresh
 * revise callback register event.
 *
 * 11 01 2010 avinash.vyas
 * [MAUI_02444520] W10.45  features check in
 * .
 *
 * 11 01 2010 sameer.sethi
 * [MAUI_02444616] [Plutommi] moving cb handlers into res file of application
 * .
 *
 * 11 01 2010 satish.chandra
 * [MAUI_02444360] The Screen pop-ups is not functioning properly
 * .
 *
 * 11 01 2010 yaling.fang
 * [MAUI_02639242] [callback res] callback res change
 * .
 *
 * 11 01 2010 baoqi.liu
 * [MAUI_02639240] [@general]check in for mediaplayer callback manager revise
 * .
 *
 * 10 31 2010 harpal.singh
 * [MAUI_02444608] Call Back Manager Revision
 * .
 *
 * 10 30 2010 phoebe.tsai
 * [MAUI_02833356] Fix link error
 * .
 *
 * 10 30 2010 kamal.sharma
 * [MAUI_02444520] W10.45  features check in
 * Various W10.45 feature check ins.
 *
 * 10 30 2010 cong.zhou
 * [MAUI_02639211] [Setting] Move callback handler to res file
 * .
 *
 * 10 30 2010 wen.wu
 * [MAUI_02639216] [Change feature] move event handler to internal AP
 * .
 *
 * 10 30 2010 aidan.hung
 * [MAUI_02833318] [FMGR] Revise event callback callback.
 * Move event callback from callback res file to fmgr res file
 *
 * 10 30 2010 julie.cheng
 * [MAUI_02832869] [Callback Manager] move to gcall callset ss ctm resource files
 * .
 *
 * 10 29 2010 ankush.sharma
 * [MAUI_02444569] [Ecompass - MAUI] Call back manager registration in the XML file
 * Checkins done for updating the Call back manager registration in the .res file.
 *
 * 10 29 2010 vaibhav.kumar
 * [MAUI_02444505] callbackmanger registration in res file
 * .
 *
 * 10 29 2010 vaibhav.kumar
 * [MAUI_02444505] callbackmanger registration in res file
 * .
 *
 * 10 29 2010 yan.liang
 * [MAUI_02831491] New MMI Cache Mechanism (MBJ site)
 * .
 *
 * 10 28 2010 vaibhav.kumar
 * [MAUI_02444505] callbackmanger registration in res file
 * moving  event id and procs to res file
 *
 * 10 28 2010 cs.kuo
 * [MAUI_02832609] Move SENDER and RECEIVER of Callback Manager to MDI resource folder
 * .
 *
 * 10 28 2010 kefeng.lian
 * [MAUI_02639064] [CallLog] Call log code revise
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 

/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_CB_MGR">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
   

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>


    <!------------------------------------------------------Other Resource---------------------------------------------------------->
	<SENDER id="EVT_ID_PRE_PROTOCOL" hfile="GlobalResDef.h"/>
	<SENDER id="EVT_ID_PRE_KEY_EVT_ROUTING" hfile="GlobalResDef.h"/>
	<SENDER id="EVT_ID_POST_KEY_EVT_ROUTING" hfile="GlobalResDef.h"/>
	<SENDER id="EVT_ID_KEY_DEFAULT_HANDLER" hfile="GlobalResDef.h"/>
	<SENDER id="EVT_ID_PRE_TOUCH_EVT_ROUTING" hfile="GlobalResDef.h"/>
	<SENDER id="EVT_ID_POST_TOUCH_EVT_ROUTING" hfile="GlobalResDef.h"/>
	<SENDER id="EVT_ID_WGUI_LSK_CLICK" hfile="GlobalResDef.h"/>
	<SENDER id="EVT_ID_WGUI_RSK_CLICK" hfile="GlobalResDef.h"/>
	<SENDER id="EVT_ID_WGUI_CSK_CLICK" hfile="GlobalResDef.h"/>

	<SENDER id="EVT_ID_APP_TERMINATED" hfile="GlobalResDef.h"/>
	<SENDER id="EVT_ID_PRE_ACTIVE_IDLE_APP_IN_END_KEY" hfile="GlobalResDef.h"/>
	<SENDER id="EVT_ID_POST_ACTIVE_IDLE_APP_IN_END_KEY" hfile="GlobalResDef.h"/>
	#ifdef MMI_CB_MGR_UT
	<SENDER id="EVT_ID_IDLE_XXX" hfile="mmi_cb_test_app_gprot.h"/>
	<SENDER id="EVT_ID_IDLE_YYY" hfile="mmi_cb_test_app_gprot.h"/>
	<SENDER id="EVT_ID_FMGR_COPY" hfile="mmi_cb_test_app_gprot.h"/>
	<SENDER id="EVT_ID_FMGR_PASTE" hfile="mmi_cb_test_app_gprot.h"/>
	<SENDER id="EVT_ID_FMGR_NO_REG" hfile="mmi_cb_test_app_gprot.h"/>
	<SENDER id="EVT_ID_FMGR_STEP_1" hfile="mmi_cb_test_app_gprot.h"/>
	<SENDER id="EVT_ID_FMGR_STEP_2" hfile="mmi_cb_test_app_gprot.h"/>
	<SENDER id="EVT_ID_FMGR_STEP_3" hfile="mmi_cb_test_app_gprot.h"/>
	<SENDER id="EVT_ID_NON_REG" hfile="mmi_cb_test_app_gprot.h"/>
	#endif
	
#if defined(__BLE_MODULE_SUPPORT__)
	<SENDER id="EVT_ID_GPIO_BLE_MOD_SPI_OPEN" hfile="GpioSrvGprot.h"/>
	<SENDER id="EVT_ID_GPIO_BLE_MOD_SPI_CLOSE" hfile="GpioSrvGprot.h"/>               
#endif
#if !defined(__COSMOS_MMI_PACKAGE__) && defined(__PXS_APP_ENABLE__)
    <RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="mmi_ucm_pxs_key_proc"/>
#endif /* !defined(__COSMOS_MMI_PACKAGE__) && defined(__PXS_APP_ENABLE__) */

	<RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="mmi_frm_nmgr_control_end_callback"/>	
#if defined(__MMI_SCREEN_SAVER__)
	<RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="mmi_ssv_main_evt_hdlr"/>
#endif
	#ifndef __COSMOS_MMI_PACKAGE__
	<RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="mmi_key_tone_pre_key_routing_cb"/>
	#endif
	#ifdef __MMI_SCREEN_ROTATE__
    <RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="mmi_auto_rotate_ssq_handler"/>
  #endif
#if !defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_SAFE_MODE__)
    <RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="mmi_safe_mode_main_evt_hdlr"/>
#endif
	<RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="mmi_slk_main_evt_hdlr"/>
	#ifdef __MMI_INTERACTIVE_PROFILNG__
	<RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="mmi_frm_profiling_pre_key_routing_cb"/>
	#endif
	#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
	<RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="mmi_qwerty_pre_key_routing_cb"/>
	#endif
	<RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="mmi_ucm_bk_call_key_proc"/>
	#ifdef __MMI_WGUI_MINI_TAB_BAR__
	<RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="wgui_mini_tab_bar_key_handle_cb"/>
	#endif
#ifdef __OP01_FWPBW__
	<RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="mmi_ucm_handfree_key_hdlr"/>
#endif /* __OP01_FWPBW__ */
	
#if defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_KEY_ONLY_NCENTER__)
    <RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="vapp_ncenter_pure_key_routing_cb"/>
#endif

	<RECEIVER id="EVT_ID_WGUI_LSK_CLICK" proc="wgui_softkey_default_proc"/>
	<RECEIVER id="EVT_ID_WGUI_RSK_CLICK" proc="wgui_softkey_default_proc"/>
	<RECEIVER id="EVT_ID_WGUI_CSK_CLICK" proc="wgui_softkey_default_proc"/>

	#ifdef __MMI_INTERACTIVE_PROFILNG__
	<RECEIVER id="EVT_ID_POST_KEY_EVT_ROUTING" proc="mmi_frm_profiling_post_key_routing_cb"/>
	#endif
	#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
	<RECEIVER id="EVT_ID_POST_KEY_EVT_ROUTING" proc="mmi_qwerty_post_key_routing_cb"/>
	#endif
	#ifdef __MMI_MEMORY_MONITOR__
	<RECEIVER id="EVT_ID_POST_KEY_EVT_ROUTING" proc="mmi_mem_monitor_post_key_routing_cb"/>
	#endif

#ifdef __COSMOS_MMI_PACKAGE__
    <RECEIVER id="EVT_ID_PRE_TOUCH_EVT_ROUTING" proc="vapp_screen_lock_main_evt_hdlr"/>
#if (defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__))
	<RECEIVER id="EVT_ID_PRE_TOUCH_EVT_ROUTING" proc="vapp_pen_calibration_pen_evt_hdlr"/>
#endif	/* (defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)) */
#endif	
	
		
#if defined(__BLE_MODULE_SUPPORT__)
	<RECEIVER id="EVT_ID_GPIO_BLE_MOD_SPI_OPEN" proc="mmi_ble_mod_eint_notify_hdlr"/>
	<RECEIVER id="EVT_ID_GPIO_BLE_MOD_SPI_CLOSE" proc="mmi_ble_mod_eint_notify_hdlr"/>            
#endif
	#ifdef MMI_CB_MGR_UT
	<RECEIVER id="EVT_ID_IDLE_XXX" proc="mmi_cb_ut_static_a"/>
	<RECEIVER id="EVT_ID_IDLE_XXX" proc="mmi_cb_ut_static_b"/>
	<RECEIVER id="EVT_ID_IDLE_XXX" proc="mmi_cb_ut_static_c"/>
	<RECEIVER id="EVT_ID_IDLE_YYY" proc="mmi_cb_ut_static_j"/>
	<RECEIVER id="EVT_ID_IDLE_YYY" proc="mmi_cb_ut_static_f"/>
	#endif
	
	/*********************************************** UCM call************************************/
	<SENDER id="EVT_ID_SRV_UCM_ACTION_NOTIFY" hfile="UcmSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_UCM_INDICATION" hfile="UcmSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_UCM_CNF_INDICATION" hfile="UcmSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_UCM_STATUS_CHANGE" hfile="UcmSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_UCM_APP_EXIT_QUERY" hfile="UcmSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_UCM_INTERCEPT_QUERY" hfile="UcmSrvGprot.h"/>
	
	#ifdef __NMC_SUPPORT__
	<RECEIVER id="EVT_ID_SRV_UCM_INTERCEPT_QUERY" proc="mmi_nmc_intercept_call_hdlr"/>
	#endif
	<RECEIVER id="EVT_ID_SRV_UCM_INTERCEPT_QUERY" proc="srv_ucm_short_string_crss"/>
    #ifndef __COSMOS_MMI_PACKAGE__
	<RECEIVER id="EVT_ID_SRV_UCM_INTERCEPT_QUERY" proc="mmi_ss_intercept"/>
    #else /* __COSMOS_MMI_PACKAGE__ */
	<RECEIVER id="EVT_ID_SRV_UCM_INTERCEPT_QUERY" proc="vapp_ss_intercept"/>
    #endif /* __COSMOS_MMI_PACKAGE__ */
	
	/****************************** MDI AUDIO***************************************/
	
	/*********************************phonebook***********************************************/
	
	
	
/*	<RECEIVER id="EVT_ID_PHB_UPD_CONTACT" proc="srv_phb_sse_updata_qcache"/> */


	
	#ifdef __MMI_VUI_3D_CUBE_APP__
	<RECEIVER id="EVT_ID_PHB_DEL_CONTACT" proc="vadp_p2v_cube_vip_contact_phb_evt_handler"/>
	#endif


	
	/*************************SMS Service Events**************************************************/
	#ifdef __MMI_DM_SELF_REGISTER_SUPPORT__
	<RECEIVER id="EVT_ID_SRV_SMS_READY" proc="mmi_dm_sr_handle_sms_ready_ind"/>
	#endif
	#if defined(__MMI_OP11_HOMESCREEN__)
	<RECEIVER id="EVT_ID_SRV_SMS_READY" proc="mmi_hs_main_evt_hdlr"/>
	#endif
	#if defined(__MMI_OP11_HOMESCREEN__)
	<RECEIVER id="EVT_ID_SRV_SMS_ADD_MSG" proc="mmi_hs_main_evt_hdlr"/>
	#endif
	
	#if defined(__MMI_OP11_HOMESCREEN__)
	<RECEIVER id="EVT_ID_SRV_SMS_DEL_MSG" proc="mmi_hs_main_evt_hdlr"/>
	#endif
	#if defined(__MMI_OP11_HOMESCREEN__)
	<RECEIVER id="EVT_ID_SRV_SMS_UPDATE_MSG" proc="mmi_hs_main_evt_hdlr"/>
	#endif
	


	
/******************************Wgui Events****************************************************/

	<RECEIVER id="EVT_ID_GUI_INPUTS_CURSOR_CHANGED" proc="mmi_imc_editor_cursor_movement_handler"/>
	<RECEIVER id="EVT_ID_IME_CURSOR_UPDATED" proc="mmi_imc_editor_cursor_movement_handler"/>
	<RECEIVER id="EVT_ID_IME_INVOKE_SPELL_WORD_SCREEN" proc="mmi_imc_enter_spell_word_screen_handler"/>
	<RECEIVER id="EVT_ID_IME_ENTRY_INPUT_METHOD_SCREEN" proc="mmi_imc_input_method_screen_handler"/>

	
	
	
	
/************************************************ UM app event *******************************************/
	<RECEIVER id="EVT_ID_INLINE_IMAGETEXT_PEN_UP" proc="wgui_inline_proc_post_event"/>
/*****************************************UM Service event******************************************/

/*********************************************MMS Events********************************************/

	
	
	#if defined(__MMI_OP11_HOMESCREEN__)
	<RECEIVER id="EVT_ID_SRV_MMS_READY" proc="mmi_hs_main_evt_hdlr"/>
	#endif

	#if defined(__MMI_OP11_HOMESCREEN__)
	<RECEIVER id="EVT_ID_JSR_DELETE_MMS" proc="mmi_hs_main_evt_hdlr"/>
	#endif
	


#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
	<SENDER id="EVT_ID_FONT_MGR_ERROR" hfile="FontManagerResDefs.h"/>
	<RECEIVER id="EVT_ID_FONT_MGR_ERROR" proc="mmi_font_mgr_display_error_popup"/>
#endif

/***************************************** NMGR *********************/
  <SENDER id="EVT_ID_NMGR_SUBLCD_NOTIFY" hfile="GlobalResDef.h"/>
	<SENDER id="EVT_ID_SCENARIO_END" hfile="GlobalResDef.h"/>
	<SENDER id="EVT_ID_NMGR_PLAY_TONE" hfile="GlobalResDef.h"/>
	<SENDER id="EVT_ID_NMGR_PLAY_VIB" hfile="GlobalResDef.h"/>
	<SENDER id="EVT_ID_NMGR_IDLE_CANCEL" hfile="GlobalResDef.h"/>
	<RECEIVER id="EVT_ID_SCENARIO_END" proc="mmi_frm_nmgr_invoke_defer_event_callback"/>

/***********************************************UMMS Events start*************************/

/************************************************** Filemgr service event - start**********************************/
	

#ifdef OPERA_BROWSER
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="opera_adp_platform_fmgr_notify_hdlr"/>	
#endif


   
//#if defined(__MMI_MEDIA_PLAYER__) && !defined(__PLST_SERVICE_DB_SUPPORT__)
//	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="mmi_medply_plst_notify_hdlr"/>
//#endif



	#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="mmi_op11_hs32_fmgr_notify_hdlr"/>
	#endif
	

	#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_op11_hs32_fmgr_notify_hdlr"/>
	#endif


#ifdef OPERA_BROWSER
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="opera_adp_platform_fmgr_notify_hdlr"/>
#endif



#ifdef __MMI_PHOTOEDITOR__
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_phoedt_fmgr_notify_handler"/>
#endif

//#if defined(__MMI_MEDIA_PLAYER__) && !defined(__PLST_SERVICE_DB_SUPPORT__)
//	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_medply_plst_notify_hdlr"/>
//#endif


#if defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_RECORD__)
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_fmgr_fmrdo_notify_hdlr"/>
#endif /*__MMI_FM_RADIO__  & __MMI_FM_RADIO_RECORD__ */




//#if defined(__MMI_MEDIA_PLAYER__) && !defined(__PLST_SERVICE_DB_SUPPORT__)
//	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT" proc="mmi_medply_plst_notify_hdlr"/>
//#endif







#ifdef OPERA_BROWSER
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="opera_adp_platform_fmgr_notify_hdlr"/>
#endif
#if defined(OBIGO_Q05A)
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="wap_fmgr_notify_hdlr"/>
#endif


#ifdef __MMI_RMGR__
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="mmi_rmgr_format_notify_hdlr"/>
#endif

//#ifdef __MMI_MMS_2__
//	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="mmi_umms_drv_format_hdlr_cb"/>
//#endif
//#if defined(__MMI_MEDIA_PLAYER__) && !defined(__PLST_SERVICE_DB_SUPPORT__)
//	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="mmi_medply_plst_notify_hdlr"/>
//#endif






#if defined(__MMI_SOUND_RECORDER__) && defined(__MMI_FMGR_SUPPORT_DEFAULT_STORAGE__)
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE" proc="mmi_fmgr_sound_recorder_def_storage_hdlr"/>
#endif



/* #if defined(__MMI_BT_RECV_DRV_SWITCH__) && defined(__MMI_FMGR_SUPPORT_DEFAULT_STORAGE__)     */
/*     <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE" proc="mmi_bt_setting_storage_fmgr_notify_hdlr"/> */
/* #endif */

//#if defined(__MMI_MEDIA_PLAYER__) && !defined(__PLST_SERVICE_DB_SUPPORT__)
//	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE" proc="mmi_medply_plst_notify_hdlr"/>
//#endif



#if defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_RECORD__)
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE" proc="mmi_fmgr_fmrdo_notify_hdlr"/>
#endif /*__MMI_FM_RADIO__  & __MMI_FM_RADIO_RECORD__ */



#if defined(__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE" proc="mmi_vdorec_notify_storage_change_evt_hdlr"/>
#endif



#ifdef __MMI_VIDEO_PLAYER__
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE" proc="mmi_vdoply_notify_storage_change_evt_hdlr"/>
#endif /* __MMI_VIDEO_PLAYER__ */

#ifdef __MMI_FMGR_CUSTICON_SUPPORT__
<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION" proc="srv_fmgr_cidb_notify_hdlr"/>
#endif

//#if defined(__MMI_MEDIA_PLAYER__) && !defined(__PLST_SERVICE_DB_SUPPORT__)
//	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION" proc="mmi_medply_plst_notify_hdlr"/>
//#endif


	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION" proc="srv_prof_notify_hdlr"/>


/************************************************** Filemgr service event - end**********************************/

/*********************************************** GPIO event *********************************************/
	<SENDER id="EVT_ID_GPIO_EXT_DEV_KEY_1" hfile="GpioSrvGprot.h"/>
	<SENDER id="EVT_ID_GPIO_EARPHONE_PLUG_IN" hfile="GpioSrvGprot.h"/>
	<SENDER id="EVT_ID_GPIO_EARPHONE_PLUG_OUT" hfile="GpioSrvGprot.h"/>
	<SENDER id="EVT_ID_GPIO_EARPHONE_QUERY_CTRL" hfile="GpioSrvGprot.h"/>
	<SENDER id="EVT_ID_GPIO_BACKLIGHT_DIMMING" hfile="GpioSrvGprot.h"/>
	<SENDER id="EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN" hfile="GpioSrvGprot.h"/>
	<SENDER id="EVT_ID_GPIO_BACKLIGHT_OFF" hfile="GpioSrvGprot.h"/>
	<SENDER id="EVT_ID_GPIO_BACKLIGHT_ON" hfile="GpioSrvGprot.h"/>
	<SENDER id="EVT_ID_GPIO_LCD_SLEEP_IN" hfile="GpioSrvGprot.h"/>
	<SENDER id="EVT_ID_GPIO_LCD_SLEEP_OUT" hfile="GpioSrvGprot.h"/>
	<SENDER id="EVT_ID_GPIO_AFTER_LCD_SLEEP_IN" hfile="GpioSrvGprot.h"/>
	<SENDER id="EVT_ID_GPIO_BACKLIGHT_LEVEL_UPDATE" hfile="GpioSrvGprot.h"/>
	<SENDER id="EVT_ID_GPIO_ENABLE_HAND_FREE" hfile="GpioSrvGprot.h"/>
	<SENDER id="EVT_ID_GPIO_DISABLE_HAND_FREE" hfile="GpioSrvGprot.h"/>
	<SENDER id="EVT_ID_GPIO_MUTE_PHONE" hfile="GpioSrvGprot.h"/>
	<SENDER id="EVT_ID_GPIO_UNMUTE_PHONE" hfile="GpioSrvGprot.h"/>
#if defined(__KJX_RFID__)
	<SENDER id="EVT_ID_GPIO_RFID_OPEN" hfile="GpioSrvGprot.h"/>
	<SENDER id="EVT_ID_GPIO_RFID_CLOSE" hfile="GpioSrvGprot.h"/>               
#endif
#ifdef __OP01_FWPBW__
    <SENDER id="EVT_ID_GPIO_TRANSMITTER_HOLD_ON" hfile="GpioSrvGprot.h"/>
	<SENDER id="EVT_ID_GPIO_TRANSMITTER_PUT_DOWN" hfile="GpioSrvGprot.h"/>
#endif /* __OP01_FWPBW__ */
/* about plug in and plug out these fun should first deal with please note*/
#ifdef __MMI_FM_DUAL_MIC_ECHO_LOOP__	
	<RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_IN" proc="mmi_fm_2micnr_hdlr_earphone_plug_in"/>
	<RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_OUT" proc="mmi_fm_2micnr_hdlr_earphone_plug_out"/>
#endif /* __MMI_FM_DUAL_MIC_ECHO_LOOP__	*/

	#if defined(__MMI_FM_RADIO__)
	<RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_IN" proc="mmi_fmrdo_earphone_notify_hdlr"/>
	#endif /*__MMI_FM_RADIO__*/
#ifdef __PLUTO_MMI_PACKAGE__	
	<RECEIVER id="EVT_ID_GPIO_BACKLIGHT_LEVEL_UPDATE" proc="mmi_phnset_gpio_set_bl_level_ncenter"/>
#endif	
#ifdef __CTM_SUPPORT__
	<RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_IN" proc="srv_ctm_hdlr_earphone_plug_in"/>
#endif /* __CTM_SUPPORT__ */
	<RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_IN" proc="srv_prof_notify_hdlr"/>
#ifndef __COSMOS_MMI_PACKAGE__
	<RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_IN" proc="mmi_gpio_handle_earphone_plug_in"/>
#else
    <RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_IN" proc="vapp_gpio_main_evt_hdlr"/>
#endif /* __COSMOS_MMI_PACKAGE__ */
	
	#if defined(__MMI_FM_RADIO__)
	<RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_OUT" proc="mmi_fmrdo_earphone_notify_hdlr"/>
	#endif /*__MMI_FM_RADIO__*/
	
#ifdef __CTM_SUPPORT__
	<RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_OUT" proc="srv_ctm_hdlr_earphone_plug_out"/>
#endif
#ifndef __COSMOS_MMI_PACKAGE__
	<RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_OUT" proc="mmi_gpio_handle_earphone_plug_out"/>
#else
    <RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_OUT" proc="vapp_gpio_main_evt_hdlr"/>
#endif /* __COSMOS_MMI_PACKAGE__ */
	<RECEIVER id="EVT_ID_GPIO_EARPHONE_PLUG_OUT" proc="srv_prof_notify_hdlr"/>
#ifdef __CTM_SUPPORT__	
	<RECEIVER id="EVT_ID_GPIO_EARPHONE_QUERY_CTRL" proc="srv_ctm_hdlr_earphone_query_ctrl"/>
#endif

#ifdef __MMI_CLAMSHELL__
	<SENDER id="EVT_ID_GPIO_CLAM_OPEN" hfile="GpioSrvGprot.h"/>
	<SENDER id="EVT_ID_GPIO_CLAM_CLOSE" hfile="GpioSrvGprot.h"/>
	<SENDER id="EVT_ID_GPIO_CLAM_OPEN_CLOSE_QUERY_TONE" hfile="GpioSrvGprot.h"/>
	<RECEIVER id="EVT_ID_GPIO_CLAM_OPEN" proc="mmi_idle_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_GPIO_CLAM_CLOSE" proc="mmi_idle_main_evt_hdlr"/>
#ifndef __COSMOS_MMI_PACKAGE__
	<RECEIVER id="EVT_ID_GPIO_CLAM_OPEN" proc="mmi_gpio_handle_clam_open"/>
#else
    <RECEIVER id="EVT_ID_GPIO_CLAM_OPEN" proc="vapp_gpio_main_evt_hdlr"/>
#endif /* __COSMOS_MMI_PACKAGE__ */

#ifdef __PLUTO_MMI_PACKAGE__
	<RECEIVER id="EVT_ID_GPIO_CLAM_OPEN" proc="mmi_ucm_clam_open_hdlr"/>
	<RECEIVER id="EVT_ID_GPIO_CLAM_CLOSE" proc="mmi_ucm_clam_close_hdlr"/>
#endif /* __PLUTO_MMI_PACKAGE__ */

#ifndef __COSMOS_MMI_PACKAGE__
	<RECEIVER id="EVT_ID_GPIO_CLAM_CLOSE" proc="mmi_gpio_handle_clam_close"/>
#else
    <RECEIVER id="EVT_ID_GPIO_CLAM_CLOSE" proc="vapp_gpio_main_evt_hdlr"/>
#endif /* __COSMOS_MMI_PACKAGE__ */

#ifdef __MMI_TOUCH_SCREEN__
	<RECEIVER id="EVT_ID_GPIO_CLAM_OPEN" proc="mmi_touch_clam_hdlr"/>
	<RECEIVER id="EVT_ID_GPIO_CLAM_CLOSE" proc="mmi_touch_clam_hdlr"/>
#endif

#ifdef __MMI_VIDEO_PLAYER__
	<RECEIVER id="EVT_ID_GPIO_CLAM_OPEN_CLOSE_QUERY_TONE" proc="mmi_vdoply_gpio_clam_open_close_query_tone"/>
#endif	
#endif

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
	<RECEIVER id="EVT_ID_GPIO_BACKLIGHT_DIMMING" proc="mmi_op11_hs32_proc_gpio_dimming"/>
#endif

#ifdef __VENUS_UI_ENGINE__
	<RECEIVER id="EVT_ID_GPIO_BACKLIGHT_OFF" proc="vfx_mmi_lcd_backlight_off_handler"/>
#endif
	
#ifdef __VENUS_UI_ENGINE__
	<RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_IN" proc="vfx_adp_lcd_sleepin_handler"/>
#endif



#ifdef __DRM_SUPPORT_SCAN_DISK__
	<RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_IN" proc="mmi_rmgr_scan_disk_turnoff"/>
#endif

#if defined(__MMI_RMGR__) && defined (__MMI_RMGR_SWEEP_DB_PERIODICALLY__)
	<RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_IN" proc="mmi_rmgr_period_sweep_db"/>
#endif



#if defined(__WIFI_SUPPORT__) && defined (__MTK_TARGET__)
	<RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_IN" proc="wndrv_hdl_lcd_sleep_in"/>
#endif

#ifndef __COSMOS_MMI_PACKAGE__
	<RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="mmi_gpio_lcd_sleep_out_update_dt"/>
    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="mmi_gpio_lcd_sleep_out_repaint_screen"/>
#else
    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="vapp_gpio_main_evt_hdlr"/>
#endif /* __COSMOS_MMI_PACKAGE__ */

#ifdef __VENUS_UI_ENGINE__
	<RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="vfx_adp_lcd_sleepout_handler"/>
#endif
    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="wgui_status_icon_bar_sleepout_callback_handler"/>

#if defined(__MMI_RMGR__) && defined (__MMI_RMGR_SWEEP_DB_PERIODICALLY__)
	<RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="mmi_rmgr_period_sweep_db_cancel"/>
#endif

#ifdef __DRM_SUPPORT_SCAN_DISK__
	<RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="mmi_rmgr_scan_disk_turnon"/>
#endif



#if defined(__WIFI_SUPPORT__) && defined (__MTK_TARGET__)
	<RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="wndrv_hdl_lcd_sleep_out"/>
#endif

#ifdef __MMI_VIDEO_PLAYER__
	<RECEIVER id="EVT_ID_GPIO_AFTER_LCD_SLEEP_IN" proc="mmi_vdoply_gpio_after_lcd_leep_in"/>
#endif

#ifndef __COSMOS_MMI_PACKAGE__
	<RECEIVER id="EVT_ID_GPIO_MUTE_PHONE" proc="mmi_gpio_handle_mute_phone"/>
	<RECEIVER id="EVT_ID_GPIO_UNMUTE_PHONE" proc="mmi_gpio_handle_unmute_phone"/>
#else
    <RECEIVER id="EVT_ID_GPIO_MUTE_PHONE" proc="vapp_gpio_main_evt_hdlr"/>
	<RECEIVER id="EVT_ID_GPIO_UNMUTE_PHONE" proc="vapp_gpio_main_evt_hdlr"/>
#endif /* __COSMOS_MMI_PACKAGE__ */


/********************************************** SIM control event callbacks *****************************/
	<RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="srv_nw_usab_on_sim_availability_changed"/>

#if (MMI_MAX_SIM_NUM >= 2) && !defined(__COSMOS_MMI_PACKAGE__)
	<RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="mmi_mode_switch_menu_update_hdlr"/>
#endif



/************************************ Network information callbacks ************************/
	

	
	#ifdef __MMI_DM_SELF_REGISTER_SUPPORT__
	<RECEIVER id="EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED" proc="mmi_dm_sr_nw_availability_changed_notify"/>
#endif

#ifdef MMS_SUPPORT
	<RECEIVER id="EVT_ID_SRV_NW_INFO_ROAMING_STATUS_CHANGED" proc="mmi_mms_on_roaming_status_changed"/>
#endif


/*************************************** Shutdown callbacks *********************************************/

#if !defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_VUI_SHELL_MULTI_PAGE__)
    <RECEIVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="mmi_shell_deinit_apps"/>
#endif
#ifdef __MMI_VOIP__
    <RECEIVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="mmi_voip_main_evt_hdlr"/>
#endif

#ifdef __MMI_BT_SUPPORT__
	<RECEIVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="mmi_bt_power_off_pre_process"/>
#endif
#ifdef __USB_IN_NORMAL_MODE__
	<RECEIVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="srv_usb_shutdown_handler"/>
#endif
	<RECEIVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="srv_ucm_shutdown_proc"/>
	
	#ifdef __NMC_SUPPORT__
	<RECEIVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="mmi_nmc_finalize"/>
	#endif
	
	<RECEIVER id="EVT_ID_SRV_SHUTDOWN_HANDLER_RESET" proc="srv_gpio_shutdown_hdlr"/>


/********************************* call setting service event ***********************************/
#ifdef __CTM_SUPPORT__
	/* EVT_ID_SRV_CALLSET_CTM_SETTING_CHANGED */
	<RECEIVER id="EVT_ID_SRV_CALLSET_CTM_SETTING_CHANGED" proc="srv_ctm_hdlr_ctm_setting_changed"/>
    #ifndef __COSMOS_MMI_PACKAGE__
	<RECEIVER id="EVT_ID_SRV_CALLSET_CTM_SETTING_CHANGED" proc="mmi_callset_hdlr_ctm_setting_changed"/>
    #endif /* __COSMOS_MMI_PACKAGE__ */
#endif



/*******************************************************************************************************/
	<SENDER id="EVT_ID_SCRN_ENTER_SUCCESS_NOFITY" hfile="GlobalResDef.h"/>
	<SENDER id="EVT_ID_SRV_NW_USAB_CHANGED" hfile="NwUsabSrvGprot.h"/>

	/* Mode switch GSM switch begin*/

#ifdef __MMI_IMPS__
	<RECEIVER id="EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY" proc="mmi_imps_main_evt_hdlr"/>
#endif




	/* Mode switch GSM switch finish*/
#if (MMI_MAX_SIM_NUM >= 2) && !defined(__COSMOS_MMI_PACKAGE__)
	<RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="mmi_mode_switch_menu_update_hdlr"/>
#endif

#ifdef __MMI_IMPS__ 
	<RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="srv_imps_main_evt_hdlr"/>
#endif

#if defined(__KJX_RFID__)
	<RECEIVER id="EVT_ID_GPIO_RFID_OPEN" proc="mmi_rfid_eint_notify_hdlr"/>
	<RECEIVER id="EVT_ID_GPIO_RFID_CLOSE" proc="mmi_rfid_eint_notify_hdlr"/>        
#endif
	
/* USB split*/
#ifdef __MMI_USB_SUPPORT__
	
	#ifdef OPERA_BROWSER
		<RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="opera_adp_enter_usb_ms_callback"/>
		<RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="opera_adp_exit_usb_ms_callback"/>
	#endif
	
	<RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="srv_fmgr_ms_handler"/>
	
	#ifdef __FLAVOR_VENDOR_SDK__
		<RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="mmi_devapp_usb_mode_check"/>
	#endif
		
	
//	#if defined(__MMI_MEDIA_PLAYER__) && !defined(__PLST_SERVICE_DB_SUPPORT__)
//		<RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="mmi_medply_plst_notify_hdlr"/>
//	#endif

	/* #if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */
	/* 	<RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="mmi_ftp_enter_usb_ms_callback"/> */

	

	
	<RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="srv_fmgr_ms_handler"/>
	
//	#if defined(__MMI_MEDIA_PLAYER__) && !defined(__PLST_SERVICE_DB_SUPPORT__)
//		<RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="mmi_medply_plst_notify_hdlr"/>
//	#endif


	

#endif

/******************************** MMI Timer Begin *************************************/
    <SENDER id="EVT_ID_MMI_TIMER_EXPIRY_PROC_EXT" hfile="GlobalResDef.h"/>
    <SENDER id="EVT_ID_MMI_TIMER_INIT_EXT" hfile="GlobalResDef.h"/>
    
/******************************** MMI Timer End ***************************************/
	<SENDER id="EVT_ID_OOM_HANDLE_FAIL" hfile="GlobalResDef.h"/>

/******************************mmi ap DCM Events****************************************************/
#if defined (__DCM_WITH_COMPRESSION_MMI_AP__)
    <SENDER id="EVT_ID_MMI_AP_DCM_LOAD" hfile="GlobalResDef.h"/>
    <SENDER id="EVT_ID_MMI_AP_DCM_UNLOAD" hfile="GlobalResDef.h"/>

    <RECEIVER id="EVT_ID_MMI_AP_DCM_LOAD" proc="mmi_ap_dcm_evt_hdlr"/>
    <RECEIVER id="EVT_ID_MMI_AP_DCM_UNLOAD" proc="mmi_ap_dcm_evt_hdlr"/>
#endif
/******************************mmi ap DCM Events end****************************************************/	

</APP>


