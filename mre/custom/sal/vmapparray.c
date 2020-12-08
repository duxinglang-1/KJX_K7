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
 * vmapparray.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * apparray
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "vmswitch.h"


#include "mmi_features.h"
#include "string.h"
#include "vmsys.h"
#include "vmopt.h"


#ifdef WIN32
#define __align(x)
#endif 


VMUINT8* mre_buildin_app_array[MRE_BUILDIN_APP_COUNT];
vm_sm_builtin_struct mre_buildin_vsm_array[MRE_BUILDIN_VSM_COUNT];
vm_sm_builtin_struct mre_buildin_vso_array[MRE_BUILDIN_VSO_COUNT];


#ifdef __MMI_MRE_APP_QQ2010__
extern const __align(4) VMUINT8 mre_qq_vsm[];
extern const __align(4) VMUINT8 mre_app_qq2010_vxp[];
#endif

#ifdef __MMI_MRE_APP_QQBROWSER__
extern const __align(4) VMUINT8 mre_app_qqbrowser_vxp[];
#endif

#ifdef __MMI_MRE_APP_RENREN__
extern const __align(4) VMUINT8 mre_app_renren_vsm[];
extern const __align(4) VMUINT8 mre_app_renren_vxp[];
#endif

#ifdef __MMI_MRE_APP_KAIXIN__ 
extern const __align(4) VMUINT8 mre_app_kaixin_vxp[];
#if defined(__MMI_MAINLCD_240X400__)|| defined(__MMI_MAINLCD_320X480__)|| defined(__MMI_MAINLCD_480X800__)
extern const __align(4) VMUINT8 mre_app_kaixin_vsm[];
#endif
#endif

#ifdef __MMI_MRE_APP_YOUKU__
extern const __align(4) VMUINT8 mre_app_youku_vxp[];
#endif

#ifdef __MMI_MRE_APP_FRUITNINJA_SC__
extern const __align(4) VMUINT8 mre_app_FruitNinja_sc_vxp[];
#endif

#ifdef __MMI_MRE_APP_FRUITNINJA_EN__
extern const __align(4) VMUINT8 mre_app_FruitNinja_en_vxp[];
#endif

#ifdef __MMI_MRE_APP_FISHINGFUN_SC__
extern const __align(4) VMUINT8 mre_app_FishingFun_sc_vxp[];
#endif

#ifdef __MMI_MRE_APP_FISHINGFUN_EN__
extern const __align(4) VMUINT8 mre_app_FishingFun_en_vxp[];
#endif

#ifdef __MMI_MRE_APP_ANGRYBIRDS_SC__
extern const __align(4) VMUINT8 mre_app_AngryBird_sc_vxp[];
#endif

#ifdef __MMI_MRE_APP_ANGRYBIRDS_EN__
extern const __align(4) VMUINT8 mre_app_AngryBird_en_vxp[];
#endif

#if defined (__MMI_MRE_APP_YAHOOMV1__)
extern const __align(4) VMUINT8 mre_app_yahoo_messengerv1[];
#endif

#if defined (__MMI_MRE_APP_YAHOOMV2__)
extern const __align(4) VMUINT8 mre_app_yahoo_messengerv1[];
extern const __align(4) VMUINT8 mre_app_yahoo_messenger_ssl_vsm[];
extern const __align(4) VMUINT8 mre_app_yahoo_messenger_ui_vsm[];
#endif

//#ifdef __MMI_MRE_APP_FBLITE__
#if defined(__MMI_MRE_APP_FBLITE__) || defined(__MMI_MRE_APP_FBLITEV11__)
extern const __align(4) VMUINT8 mre_app_facebook_lite[];
#endif

#ifdef __MMI_MRE_APP_YAHOOFINANCE__
extern const __align(4) VMUINT8 mre_app_yahoo_finance[];
#endif

#ifdef __MMI_MRE_APP_YAHOOWEATHER__
extern const __align(4) VMUINT8 mre_app_yahoo_weather[];
#endif

#ifdef __MMI_MRE_APP_YAHOONEWS__
extern const __align(4) VMUINT8 mre_app_yahoo_news[];
#endif

#ifdef __MMI_MRE_APP_YAHOOCRICKET__
extern const __align(4) VMUINT8 mre_app_yahoo_cricket[];
#endif

#ifdef __MMI_MRE_APP_OPERA__
extern const __align(4) VMUINT8 mre_app_opera_vxp[];
#endif

#ifdef __MMI_MRE_APP_OPERA_MINI_V6__
	extern const __align(4) VMUINT8 mre_app_opera_mini_v6_vxp[];
#endif

#ifdef __MRE_CORE_SO__
extern const __align(4) VMUINT8 mre_helloworld_vso[];
#endif
/* zhibo add start for 15 preload app*/
/***********************************************/
#ifdef __MMI_MRE_APP_CALCULATOR__
extern const __align(4) VMUINT8 mre_app_calculator_vxp[];
#endif

#ifdef __MMI_MRE_APP_CONVERTER__
extern const __align(4) VMUINT8 mre_app_converter[];
#endif

#ifdef __MMI_MRE_APP_HEALTH__
extern const __align(4) VMUINT8 mre_app_health[];
#endif

#ifdef __MMI_MRE_APP_STOPWATCH__
extern const __align(4) VMUINT8 mre_app_stopwatch[];
#endif

#ifdef __MMI_MRE_APP_ZAKAT__
extern const __align(4) VMUINT8 mre_app_zakat[];
#endif
/***********************************************/
#ifdef __MMI_MRE_APP_ZY_EBOOK__
extern const __align(4) VMUINT8 mre_app_zy_ebook[];
#endif
#ifdef __MMI_MRE_GAME_HAPPYWAR_EN__
extern const __align(4) VMUINT8 mre_app_happy_war_en_vxp[];
#endif


#ifdef __MMI_MRE_GAME_HAPPYWAR_CHS__
extern const __align(4) VMUINT8 mre_app_happy_war_chs_vxp[];
#endif


#ifdef __MMI_MRE_GAME_EGYPTCODE_EN__
extern const __align(4) VMUINT8 mre_app_egypt_code_en_vxp[];
#endif

#ifdef __MMI_MRE_GAME_EGYPTCODE_CHS__
extern const __align(4) VMUINT8 mre_app_egypt_code_chs_vxp[];
#endif


#ifdef __MMI_MRE_GAME_KINGCOMBAT_EN__
extern const __align(4) VMUINT8 mre_app_king_combat_en_vxp[];
#endif

#ifdef __MMI_MRE_GAME_KINGCOMBAT_CHS__
extern const __align(4) VMUINT8 mre_app_king_combat_chs_vxp[];
#endif


#ifdef __MMI_MRE_GAME_GOLDMINER_EN__
extern const __align(4) VMUINT8 mre_app_gold_miner_en_vxp[];
#endif

#ifdef __MMI_MRE_GAME_GOLDMINER_CHS__
extern const __align(4) VMUINT8 mre_app_gold_miner_chs_vxp[];
#endif

/***********************************************/
#ifdef __MMI_MRE_GAME_MOTO_EN__
extern const __align(4) VMUINT8 mre_app_moto_en_vxp[];
#endif

#ifdef __MMI_MRE_GAME_MOTO_CHS__
extern const __align(4) VMUINT8 mre_app_moto_chs_vxp[];
#endif


#ifdef __MMI_MRE_GAME_GIRLSLOT_EN__
extern const __align(4) VMUINT8 mre_app_girl_slot_en_vxp[];
#endif


#ifdef __MMI_MRE_GAME_GIRLSLOT_CHS__
extern const __align(4) VMUINT8 mre_app_girl_slot_chs_vxp[];
#endif


#ifdef __MMI_MRE_GAME_PARKOUR_EN__
extern const __align(4) VMUINT8 mre_app_parkour_en_vxp[];
#endif


#ifdef __MMI_MRE_GAME_PARKOUR_CHS__
extern const __align(4) VMUINT8 mre_app_parkour_chs_vxp[];
#endif


#ifdef __MMI_MRE_GAME_TEARDRESS_EN__
extern const __align(4) VMUINT8 mre_app_tear_dress_en_vxp[];
#endif

#ifdef __MMI_MRE_GAME_TEARDRESS_CHS__
extern const __align(4) VMUINT8 mre_app_tear_dress_chs_vxp[];
#endif


#ifdef __MMI_MRE_GAME_HAPPYEGG_EN__
extern const __align(4) VMUINT8 mre_app_happy_egg_en_vxp[];
#endif

#ifdef __MMI_MRE_GAME_HAPPYEGG_CHS__
extern const __align(4) VMUINT8 mre_app_happy_egg_chs_vxp[];
#endif


/***********************************************/
/* zhibo add end for 15 preload app*/
/*<---------------------------- ADD 3GT Game START ---------------------------->*/
#ifdef __MMI_MRE_APP_3GT_GAME_BOWLING_ENG__
extern const __align(4) VMUINT8 mre_app_3GT_Game_Bowling_ENG_vxp[];
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BOWLING_CHS__
extern const __align(4) VMUINT8 mre_app_3GT_Game_Bowling_CHS_vxp[];
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BOWLING_CHT__
extern const __align(4) VMUINT8 mre_app_3GT_Game_Bowling_CHT_vxp[];
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_DANDELION__
extern const __align(4) VMUINT8 mre_app_3GT_Game_DanDelion_ALL_vxp[];
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHS__
extern const __align(4) VMUINT8 mre_app_3gt_rash_motor_chs_vxp[];
#endif
#ifdef __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHT__
extern const __align(4) VMUINT8 mre_app_3gt_rash_motor_cht_vxp[];
#endif
#ifdef __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_ENG__
extern const __align(4) VMUINT8 mre_app_3gt_rash_motor_eng_vxp[];
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHS__
extern const __align(4) VMUINT8 mre_app_3gt_balance_ball_chs_vxp[];
#endif
#ifdef __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHT__
extern const __align(4) VMUINT8 mre_app_3gt_balance_ball_cht_vxp[];
#endif
#ifdef __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_ENG__
extern const __align(4) VMUINT8 mre_app_3gt_balance_ball_eng_vxp[];
#endif

/*<---------------------------- ADD 3GT Game END ------------------------------>*/

/* prabhjot: add gameloft games - START */
#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE1__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE1__)
extern const __align(4) VMUINT8 mre_app_gl_asphalt6[];
extern const __align(4) VMUINT8 mre_app_gl_brainchallenge[];
extern const __align(4) VMUINT8 mre_app_gl_blockbreaker[];
extern const __align(4) VMUINT8 mre_app_gl_assassincreed[];
#endif

#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE2__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE2__)
extern const __align(4) VMUINT8 mre_app_gl_asphalt6[];
extern const __align(4) VMUINT8 mre_app_gl_brainchallenge[];
extern const __align(4) VMUINT8 mre_app_gl_blockbreaker[];
#endif

#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE3__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE3__)
extern const __align(4) VMUINT8 mre_app_gl_asphalt6[];
extern const __align(4) VMUINT8 mre_app_gl_blockbreaker[];
extern const __align(4) VMUINT8 mre_app_gl_assassincreed[];
#endif

#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE4__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE4__)
extern const __align(4) VMUINT8 mre_app_gl_asphalt6[];
extern const __align(4) VMUINT8 mre_app_gl_assassincreed[];
extern const __align(4) VMUINT8 mre_app_gl_brainchallenge[];
#endif
/* prabhjot: add gameloft games - END */

#ifdef __MMI_MRE_APP_FACEBOOK_V2__
extern const __align(4) VMUINT8 mre_app_facebook_v2[];
#endif

#ifdef __MMI_MRE_APP_TWITTER__
extern const __align(4) VMUINT8 mre_app_twitter[];
#endif

#ifdef __MMI_MRE_APP_FACEBOOK_V2_STANDARD__
extern const __align(4) VMUINT8 mre_app_facebook_v2[];
extern const __align(4) VMUINT8 mre_app_facebook_v2_camera_vsm[];
#endif

#ifdef __MMI_MRE_APP_GAMELOFT_2ND_PACKAGE__
extern const __align(4) VMUINT8 mre_app_gl_glive[];
extern const __align(4) VMUINT8 mre_app_gl_mortalcombat2[];
#endif

#if defined (__MMI_MRE_APP_GAMELOFT_AS6_CN_MT6250__) || defined (__MMI_MRE_APP_GAMELOFT_AS6_GB_MT6250__)
extern const __align(4) VMUINT8 mre_app_gl_asphalt6[];
extern const __align(4) VMUINT8 mre_app_gl_glive[];
#endif

#ifdef __MMI_MRE_APP_YOUTUBE__
extern const __align(4) VMUINT8 mre_app_YouTube[];
#endif

#ifdef __MMI_MRE_APP_WOCHACHA__
extern const __align(4) VMUINT8 mre_app_wochacha_vxp[];
#endif

#if defined(__MMI_MRE_APP_MITAKE_MSTOCK__) && (__MMI_MRE_APP_MITAKE_MSTOCK__ == __MRE_APP_DEFAULT__)
extern const __align(4) VMUINT8 mre_app_mitake_mstock_vxp[];
#endif

#if defined(__MMI_MRE_APP_SINA_WEIBO__) && (__MMI_MRE_APP_SINA_WEIBO__ == __MRE_APP_DEFAULT__)
extern const __align(4) VMUINT8 mre_app_sina_weibo_vsm[];
extern const __align(4) VMUINT8 mre_app_sina_weibo_vxp[];
#endif

VMUINT vm_init_default_game(VMUINT* appcount, VMUINT* smcount, VMUINT* socount)
{
	VMUINT count = 0;
	VMUINT sm_count = 0;
	VMUINT so_count = 0;

#ifndef __MTK_TARGET__
    *appcount = 0;
	*smcount = 0;
	*socount = 0;
	return count;
#endif

#ifdef __MMI_MRE_APP_QQ2010__
	mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_qq2010_vxp;
	strcpy(mre_buildin_vsm_array[sm_count].file_name,"QQsm");
	mre_buildin_vsm_array[sm_count++].address = (VMUINT)mre_qq_vsm;
#endif

#ifdef __MMI_MRE_APP_QQBROWSER__
		mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_qqbrowser_vxp;
#endif

#ifdef __MMI_MRE_APP_RENREN__
	mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_renren_vxp;
    strcpy(mre_buildin_vsm_array[sm_count].file_name,"Renren");
    mre_buildin_vsm_array[sm_count++].address = (VMUINT)mre_app_renren_vsm;
#endif

#ifdef __MMI_MRE_APP_KAIXIN__
#if defined(__MMI_MAINLCD_240X400__)|| defined(__MMI_MAINLCD_320X480__)|| defined(__MMI_MAINLCD_480X800__)
	mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_kaixin_vxp;
	strcpy(mre_buildin_vsm_array[sm_count].file_name,"kaixin");
	mre_buildin_vsm_array[sm_count++].address = (VMUINT)mre_app_kaixin_vsm;
#else
	mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_kaixin_vxp;
#endif
#endif

#ifdef __MMI_MRE_APP_YOUKU__
		mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_youku_vxp;
#endif

#ifdef __MMI_MRE_APP_FRUITNINJA_SC__
	    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_FruitNinja_sc_vxp;
#endif

#ifdef __MMI_MRE_APP_FRUITNINJA_EN__
	    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_FruitNinja_en_vxp;
#endif

#ifdef __MMI_MRE_APP_FISHINGFUN_SC__
	    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_FishingFun_sc_vxp;
#endif

#ifdef __MMI_MRE_APP_FISHINGFUN_EN__
	    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_FishingFun_en_vxp;
#endif

#ifdef __MMI_MRE_APP_ANGRYBIRDS_SC__
	    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_AngryBird_sc_vxp;
#endif

#ifdef __MMI_MRE_APP_ANGRYBIRDS_EN__
	    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_AngryBird_en_vxp;
#endif

#if defined (__MMI_MRE_APP_YAHOOMV1__)
		mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_yahoo_messengerv1;
#endif

#if defined(__MMI_MRE_APP_YAHOOMV2__)
		mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_yahoo_messengerv1;

		strcpy(mre_buildin_vsm_array[sm_count].file_name, "YMv2_VSM");
		mre_buildin_vsm_array[sm_count++].address = (VMUINT)mre_app_yahoo_messenger_ui_vsm;
		
		strcpy(mre_buildin_vsm_array[sm_count].file_name, "POLAR_SSL_VSM");
		mre_buildin_vsm_array[sm_count++].address = (VMUINT)mre_app_yahoo_messenger_ssl_vsm;
#endif

#if defined(__MMI_MRE_APP_FBLITE__) || defined(__MMI_MRE_APP_FBLITEV11__)
		mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_facebook_lite;
#endif

#ifdef __MMI_MRE_APP_YAHOOFINANCE__
		mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_yahoo_finance;
#endif

#ifdef __MMI_MRE_APP_YAHOOWEATHER__
		mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_yahoo_weather;
#endif

#ifdef __MMI_MRE_APP_YAHOONEWS__
		mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_yahoo_news;
#endif

#ifdef __MMI_MRE_APP_OPERA__
		mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_opera_vxp;
#endif

#ifdef __MMI_MRE_APP_OPERA_MINI_V6__
		mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_opera_mini_v6_vxp;
#endif

#ifdef __MRE_CORE_SO__
		strcpy(mre_buildin_vso_array[so_count].file_name,"so.vso");
		mre_buildin_vso_array[so_count++].address = (VMUINT)mre_helloworld_vso;
#endif

/* zhibo add start for 15 preload app*/
/***********************************************/
#ifdef __MMI_MRE_APP_CALCULATOR__
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_calculator_vxp;
#endif
    
#ifdef __MMI_MRE_APP_CONVERTER__
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_converter;
#endif
    
#ifdef __MMI_MRE_APP_HEALTH__
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_health;
#endif
    
#ifdef __MMI_MRE_APP_STOPWATCH__
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_stopwatch;
#endif
    
#ifdef __MMI_MRE_APP_ZAKAT__
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_zakat;
#endif
    /***********************************************/
#ifdef __MMI_MRE_APP_ZY_EBOOK__
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_zy_ebook;
#endif


#ifdef __MMI_MRE_GAME_HAPPYWAR_EN__
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_happy_war_en_vxp;
#endif

#ifdef __MMI_MRE_GAME_HAPPYWAR_CHS__
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_happy_war_chs_vxp;
#endif

    
#ifdef __MMI_MRE_GAME_EGYPTCODE_EN__
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_egypt_code_en_vxp;
#endif


#ifdef __MMI_MRE_GAME_EGYPTCODE_CHS__
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_egypt_code_chs_vxp;
#endif

#ifdef __MMI_MRE_GAME_KINGCOMBAT_EN__
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_king_combat_en_vxp;
#endif


#ifdef __MMI_MRE_GAME_KINGCOMBAT_CHS__
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_king_combat_chs_vxp;
#endif

#ifdef __MMI_MRE_GAME_GOLDMINER_EN__
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_gold_miner_en_vxp;
#endif

#ifdef __MMI_MRE_GAME_GOLDMINER_CHS__
		mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_gold_miner_chs_vxp;
#endif

    /***********************************************/
#ifdef __MMI_MRE_GAME_MOTO_EN__
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_moto_en_vxp;
#endif

#ifdef __MMI_MRE_GAME_MOTO_CHS__
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_moto_chs_vxp;
#endif

    
#ifdef __MMI_MRE_GAME_GIRLSLOT_EN__
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_girl_slot_en_vxp;
#endif

#ifdef __MMI_MRE_GAME_GIRLSLOT_CHS__
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_girl_slot_chs_vxp;
#endif

    
#ifdef __MMI_MRE_GAME_PARKOUR_EN__
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_parkour_en_vxp;
#endif

#ifdef __MMI_MRE_GAME_PARKOUR_CHS__
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_parkour_chs_vxp;
#endif

    
#ifdef __MMI_MRE_GAME_TEARDRESS_EN__
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_tear_dress_en_vxp;
#endif

#ifdef __MMI_MRE_GAME_TEARDRESS_CHS__
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_tear_dress_chs_vxp;
#endif

    
#ifdef __MMI_MRE_GAME_HAPPYEGG_EN__
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_happy_egg_en_vxp;
#endif

#ifdef __MMI_MRE_GAME_HAPPYEGG_CHS__
		mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_happy_egg_chs_vxp;
#endif

    /***********************************************/
    /* zhibo add end for 15 preload app*/
#ifdef __MMI_MRE_APP_YAHOOCRICKET__
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_yahoo_cricket;
#endif

/*<---------------------------- ADD 3GT Game START ---------------------------->*/

#ifdef __MMI_MRE_APP_3GT_GAME_BOWLING_ENG__
		mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_3GT_Game_Bowling_ENG_vxp;
#endif
	
#ifdef __MMI_MRE_APP_3GT_GAME_BOWLING_CHS__
		mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_3GT_Game_Bowling_CHS_vxp;
#endif
	
#ifdef __MMI_MRE_APP_3GT_GAME_BOWLING_CHT__
		mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_3GT_Game_Bowling_CHT_vxp;
#endif
	
#ifdef __MMI_MRE_APP_3GT_GAME_DANDELION__
		mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_3GT_Game_DanDelion_ALL_vxp;
#endif
	
#ifdef __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHS__
        mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_3gt_rash_motor_chs_vxp;
#endif
#ifdef __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_CHT__
        mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_3gt_rash_motor_cht_vxp;
#endif
#ifdef __MMI_MRE_APP_3GT_GAME_RASH_MOTOR_ENG__
        mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_3gt_rash_motor_eng_vxp;
#endif

#ifdef __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHS__
        mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_3gt_balance_ball_chs_vxp;
#endif
#ifdef __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_CHT__
        mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_3gt_balance_ball_cht_vxp;
#endif
#ifdef __MMI_MRE_APP_3GT_GAME_BALANCE_BALL_ENG__
        mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_3gt_balance_ball_eng_vxp;
#endif
/*<---------------------------- ADD 3GT Game END ------------------------------>*/

/* prabhjot: add gameloft games - START */
#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE1__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE1__)
	mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_gl_asphalt6;
	mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_gl_brainchallenge;
	mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_gl_blockbreaker;
	mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_gl_assassincreed;
#endif

#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE2__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE2__)
	mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_gl_asphalt6;
	mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_gl_brainchallenge;
	mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_gl_blockbreaker;
#endif

#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE3__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE3__)
	mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_gl_asphalt6;
	mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_gl_blockbreaker;
	mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_gl_assassincreed;
#endif

#if defined(__MMI_MRE_APP_GAMELOFT_CN_PACKAGE4__) || defined(__MMI_MRE_APP_GAMELOFT_GB_PACKAGE4__)
	mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_gl_asphalt6;
	mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_gl_assassincreed;
	mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_gl_brainchallenge;
#endif
/* prabhjot: add gameloft games - END */

#ifdef __MMI_MRE_APP_FACEBOOK_V2__
		mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_facebook_v2;
#endif

#ifdef __MMI_MRE_APP_TWITTER__
		mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_twitter;
#endif

#ifdef __MMI_MRE_APP_FACEBOOK_V2_STANDARD__
	mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_facebook_v2;
	strcpy(mre_buildin_vsm_array[sm_count].file_name,"Facebook_Camera_VSM");
	mre_buildin_vsm_array[sm_count++].address = (VMUINT)mre_app_facebook_v2_camera_vsm;
#endif

#ifdef __MMI_MRE_APP_GAMELOFT_2ND_PACKAGE__
	mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_gl_glive;
	mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_gl_mortalcombat2;
#endif

#if defined (__MMI_MRE_APP_GAMELOFT_AS6_CN_MT6250__) || defined (__MMI_MRE_APP_GAMELOFT_AS6_GB_MT6250__)
	mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_gl_asphalt6;
	mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_gl_glive;
#endif

#ifdef __MMI_MRE_APP_YOUTUBE__
        mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_YouTube;        
#endif

#ifdef __MMI_MRE_APP_WOCHACHA__
        mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_wochacha_vxp;        
#endif

#if defined(__MMI_MRE_APP_MITAKE_MSTOCK__) && (__MMI_MRE_APP_MITAKE_MSTOCK__ == __MRE_APP_DEFAULT__)
    mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_mitake_mstock_vxp;
#endif

#if defined(__MMI_MRE_APP_SINA_WEIBO__) && (__MMI_MRE_APP_SINA_WEIBO__ == __MRE_APP_DEFAULT__)
		mre_buildin_app_array[count++] = (VMUINT8 *)mre_app_sina_weibo_vxp;
		strcpy(mre_buildin_vsm_array[sm_count].file_name,"weibo");
		mre_buildin_vsm_array[sm_count++].address = (VMUINT)mre_app_sina_weibo_vsm;
#endif
	
	*appcount = count;
	*smcount = sm_count;
	*socount = so_count;
	return count;
}

VMINT vm_check_buildin_app(VMUINT8* ptr)
{
	VMUINT vxp_count = 0, vsm_count = 0, so_count = 0;
	VMUINT i = 0;
	
	vm_init_default_game(&vxp_count,&vsm_count,&so_count);

	for(i=0; i< vxp_count; i++)
	{
		if(ptr == (VMUINT8*)(mre_buildin_app_array[i] + 4))
			break;
	}
	
	if(i != vxp_count)
		return TRUE;

	for(i=0; i< vsm_count; i++)
	{
		if(ptr == (VMUINT8*)(mre_buildin_vsm_array[i].address + 4))
			break;
	}

	if(i != vsm_count)
		return TRUE;

	return FALSE;
}



