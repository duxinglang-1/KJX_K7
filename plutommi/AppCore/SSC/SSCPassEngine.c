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
 * SSCSrv.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for SSC service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "MMIDataType.h"
#include "SSCGprot.h"
#include "idleappdef.h"
#include "sscresdef.h"
#include "SSCStringTable.h"
#include "SSCprot.h"
#include "FontDcl.h"
#include "PhoneSetup.h"
#include "IdleGprot.h"
#include "SmlMenuGprot.h"
#include "FontRes.h"
#include "kal_general_types.h"
#include "string.h"
#include "CustDataRes.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "wgui_categories_util.h"
#include "mmi_frm_events_gprot.h"
#include "Unicodexdcl.h"
#include "stdlib.h"
#include "stdio.h"
#include "GlobalConstants.h"
#include "phonesetupgprots.h"

#include "Lang_interface.h"

#if defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__) && !defined(__MTK_TARGET__)
#include "vapp_launcher_develop.h" // vapp_launcher_dev_get_app_icon_screenshot
#endif

#ifdef __COSMOS_MMI_PACKAGE__
extern void vapp_dialer_language_switch(void *scr, U8 language_id);
#endif

CHAR ssc_dialpad_buffer[MAX_DIAL_PAD * ENCODING_LENGTH];

#ifdef __COSMOS_MMI_PACKAGE__
void *mmi_ssc_main_screen_g;
extern WCHAR mmi_dialer_ssc_string[];
#endif

/*
 * For SSC disable
 * MMI_FALSE (0): ssc string unchanged
 * MMI_TRUE  (1): before executing ssc, check the 'ssc_disable_ctrl' flag first
 * 0xFF: read NVRAM first 
 */
extern U8 ssc_disable_flag;

extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;
extern void RefreshNwProviderName(U8 *UpdatePlmn);

#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
extern void MTPNP_PFAL_RefreshNwProviderName(U8 *UpdatePlmn);
#endif

#ifdef __COSMOS_MMI_PACKAGE__
extern void vapp_app_manager_entry(void);
extern void vapp_mre_app_launch(CHAR* appName);
extern void vapp_mre_app_install(WCHAR* appPath);
void vapp_mre_app_launch_ex(void)
{
	vapp_mre_app_launch(0);
}
void vapp_mre_app_install_ex(void)
{
	vapp_mre_app_install(L"E:\\mre\\kaixin-0618.vxp");
}
#endif
SSCSTRINGTBL mmi_ssc_phone_table[] = 
{
	{"*#06#", MMI_FALSE, SSCHandleIMEI},
	{SSC_SW_VERSION, MMI_FALSE, mmi_SSC_handle_software_version_summary},
#ifdef __MMI_HW_VERSION__
	{SSC_HW_VERSION, MMI_FALSE, mmi_SSC_handle_hardware_version},
#endif
#ifdef __MMI_ENGINEER_MODE__
	{SSC_ENGINEERING_MODE, MMI_FALSE, mmi_em_pre_entry_engineermode_menu},
#endif
#ifdef __MMI_FACTORY_MODE__
	{SSC_FACTORY_MODE, MMI_FALSE, EntryFMMenu},
	{SSC_FACTORY_MODE_AUTOTEST, MMI_FALSE, EntryFMMenuAutoTest},
#endif

#ifdef __MMI_FM_LCD_CONTRAST__
	{SSC_SET_LCD_CONTRAST, MMI_FALSE, mmi_SSC_handle_LCD_contrast_setting},
#endif

	{SSC_DISABLE_FOR_SHIPMENT, MMI_FALSE, SSCHandleDisable},
#ifdef __MMI_SML_MENU__
#ifdef __MMI_DUAL_SIM_MASTER__
	{SSC_SML_LOCK_CODE,	MMI_FALSE, mmi_sml_entry_lock_category_sim_interface},
	{SSC_SML_UNLOCK_CODE, MMI_FALSE, mmi_sml_entry_unlock_category_sim_interface},
	{SSC_SML_ADD_CODE, MMI_FALSE, mmi_sml_entry_add_category_sim_interface},
	{SSC_SML_REMOVE_CODE, MMI_FALSE, mmi_sml_entry_remove_category_sim_interface},
	{SSC_SML_DEACTIVATE_CODE, MMI_FALSE, mmi_sml_entry_permanent_unlock_sim_interface},
#else
	{SSC_SML_LOCK_CODE,	MMI_FALSE, mmi_sml_entry_lock_category_selection},
	{SSC_SML_UNLOCK_CODE, MMI_FALSE, mmi_sml_entry_unlock_category_selection},
	{SSC_SML_ADD_CODE, MMI_FALSE, mmi_sml_entry_add_category_data},
	{SSC_SML_REMOVE_CODE, MMI_FALSE, mmi_sml_entry_remove_category_data},
	{SSC_SML_DEACTIVATE_CODE, MMI_FALSE, mmi_sml_entry_permanent_unlock_selection},
#endif
#endif /* __MMI_SML_MENU__ */
#ifdef __MMI_A2DP_SUPPORT__
	{SSC_BT_A2DP_TOGGLE_PTS_MODE, MMI_FALSE, SSCHandle_BT_A2DP_Toggle_PTS_Mode},
#endif /* __MMI_A2DP_SUPPORT__ */ 
#ifdef __BTMTK__
	{BT_PTS_SIMAP_GRACEFUL_DISC_TYPE_ON, MMI_FALSE, SSCHandle_BT_PTS_SIMAP_Graceful_Disc_Type},
	{BT_PTS_SIMAP_IMMEDIATE_DISC_TYPE_ON, MMI_FALSE, SSCHandle_BT_PTS_SIMAP_Immediate_Disc_Type},    
	{BT_PTS_SIMAP_UNAVAILABLE_SIM_SEND_STATUS_IND, MMI_FALSE, SSCHandle_BT_PTS_SIMAP_PRS},    
#endif /* __BTMTK__ */ 
#ifdef __MMI_BT_SUPPORT__
	/* for pts V2.1.0.4 */
	/* cannot update indicators to remote bluetooth headset while HFP is connected */
	/* indicators shall be retrieved by remote HF AT+CIND? */
	/* so for pts V2.1.0.4, host will not udpate indicators while HFP is just connected */
	{BT_PTS_ON, MMI_FALSE, mmi_bt_enable_pts_test},
	{BT_PTS_OFF, MMI_FALSE, mmi_bt_disable_pts_test},
#endif /* __MMI_BT_SUPPORT__ */ 
#ifdef __DRM_V02__
	{"*#6221#", MMI_TRUE, OSD_STime_Switch},
	{"*#6237#", MMI_TRUE, OSD_PKI_Format_Switch},
	{"*#6248#", MMI_TRUE, mmi_rmgr_switch_cermgr},
#endif
#if defined(__AGPS_SUPPORT__) && defined(__SUPL_SUPPORT__)
	{"*#2008#", MMI_FALSE, em_gps_open_soc},
	{"*#2009#", MMI_FALSE, em_gps_close_soc},
	{"*#1040#", MMI_FALSE, em_gps_gps_reset_chip_off_104},
	{"*#1041#", MMI_FALSE, em_gps_gps_reset_chip_on_104},
	{"*#1042#", MMI_FALSE, em_gps_reset_data_104},
	{"*#1030#", MMI_FALSE, em_gps_gps_reset_chip_off_103},
	{"*#1031#", MMI_FALSE, em_gps_gps_reset_chip_on_103},
	{"*#1032#", MMI_FALSE, em_gps_reset_data_103},
	{"*#1022#", MMI_FALSE, em_gps_reset_data_102},
#endif

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
	{SSC_OP11_HOMESCREEN, MMI_TRUE, mmi_op11_hs32_activate_by_ssc},
#endif

	{SSC_DISABLE_KEYPAD_LOCK_BY_END_KEY, MMI_TRUE, mmi_idle_disable_lock_by_end_key},

#ifdef __VENUS_UI_ENGINE__
	{"*#28146#", MMI_TRUE, mmi_SSC_handle_venus_UI_test},
#endif
#if defined (__FLAVOR_VENDOR_SDK__) || defined(__MAUI_SDK_TEST__)
	{SSC_AVKAPP, MMI_TRUE, SSCHandleAvkApp},
#endif
#if defined (__MMI_FILE_MANAGER__)
	{"*#28144#", MMI_TRUE, srv_fmgr_testbed_launch},
#endif        
	{SSC_VENDORAPP, MMI_TRUE, SSCHandleVendorApp},
	{"*#63342835#", MMI_FALSE, ssc_show_logo_screen},

#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
	{"*#47825#", MMI_TRUE, gui_sse_test},
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
#ifdef __COSMOS_MMI_PACKAGE__
	{"*##*110#",MMI_TRUE,vapp_app_manager_entry},
	{"*##*111#",MMI_TRUE,vapp_mre_app_launch_ex},
	{"*##*112#",MMI_TRUE,vapp_mre_app_install_ex},
#endif
#ifdef __MMI_EM_PROFILING_VENUS_DEBUG_PANEL__
	{"*#83093#",MMI_TRUE,mmi_ssc_venus_debug_panel},
#endif

#if defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__) && !defined(__MTK_TARGET__)
    {"*#521588#", MMI_TRUE, vapp_launcher_dev_get_app_icon_screenshot}
#endif
};

SIMSTRINGTBL mmi_ssc_sim_table[] = 
{
	{"**04*", 5, mmi_ssc_process_chv},
	{"**042*", 6, mmi_ssc_process_chv},
	{"**05*", 5, mmi_ssc_process_chv},
	{"**052*", 6, mmi_ssc_process_chv}
#ifdef __MMI_SML_MENU__
#ifdef __MMI_DUAL_SIM_MASTER__
	,{SSC_SML_LOCK_CMD, 6, mmi_sml_entry_lock_req_sim_interface}
	,{SSC_SML_UNLOCK_CMD, 6, mmi_sml_entry_unlock_req_sim_interface}
	,{SSC_SML_QUERY_CMD, 7, mmi_sml_entry_query_req_sim_interface}
#else
	,{SSC_SML_LOCK_CMD, 6, mmi_sml_send_lock_req_by_ssc}
	,{SSC_SML_UNLOCK_CMD, 6, mmi_sml_send_unlock_req_by_ssc}
	,{SSC_SML_QUERY_CMD, 7, mmi_sml_send_query_req_by_ssc}
#endif
#endif /* __MMI_SML_MENU__ */
};


SSCStringTableEx mmi_ssc_language_table[] = 
{
    
		{SSC_AUTO, MMI_FALSE, SSC_STR_ERR_SET_DEFAULT, SSC_SCR_LANGUAGE_DEFAULT_STR_ID},
		{SSC_ENGLISH, MMI_FALSE, SSC_STR_ERR_SET_ENGLISH, SSC_SCR_LANGUAGE_ENGLISH_STR_ID},
#if defined(__MMI_LANG_TR_CHINESE__)
		{SSC_TCHINESE, MMI_FALSE,	 SSC_STR_ERR_SET_TCHINESE, SSC_SCR_LANGUAGE_TCHINESE_STR_ID},
#endif
#if defined(__MMI_LANG_SPANISH__)
		{SSC_SPANISH,	MMI_FALSE, SSC_STR_ERR_SET_SPANISH, SSC_SCR_LANGUAGE_SPANISH_STR_ID},
#endif 
#if defined(__MMI_LANG_DANISH__)
		{SSC_DANISH, MMI_FALSE,	SSC_STR_ERR_SET_DANISH, SSC_SCR_LANGUAGE_DANISH_STR_ID},
#endif 
#if defined(__MMI_LANG_POLISH__)
		{SSC_POLISH, MMI_FALSE,	SSC_STR_ERR_SET_POLISH, SSC_SCR_LANGUAGE_POLISH_STR_ID},
#endif 
#if defined(__MMI_LANG_FRENCH__)
		{SSC_FRENCH, MMI_FALSE,	SSC_STR_ERR_SET_FRENCH, SSC_SCR_LANGUAGE_FRENCH_STR_ID},
#endif 
#if defined(__MMI_LANG_GERMAN__)
		{SSC_GERMAN, MMI_FALSE,	SSC_STR_ERR_SET_GERMAN, SSC_SCR_LANGUAGE_GERMAN_STR_ID},
#endif 
#if defined(__MMI_LANG_KOREAN__)
		{SSC_KOREAN, MMI_FALSE,	SSC_STR_ERR_SET_KOREAN, SSC_SCR_LANGUAGE_KOREAN_STR_ID},
#endif 
#if defined(__MMI_LANG_ITALIAN__)
		{SSC_ITALIAN,	MMI_FALSE, SSC_STR_ERR_SET_ITALIAN,SSC_SCR_LANGUAGE_ITALIAN_STR_ID},
#endif 
#if defined(__MMI_LANG_THAI__)
		{SSC_THAI, MMI_FALSE,	SSC_STR_ERR_SET_THAI,SSC_SCR_LANGUAGE_THAI_STR_ID},
#endif 
#if defined(__MMI_LANG_RUSSIAN__)
		{SSC_RUSSIAN,	MMI_FALSE, SSC_STR_ERR_SET_RUSSIAN,SSC_SCR_LANGUAGE_RUSSIAN_STR_ID},
#endif 
#if defined(__MMI_LANG_BULGARIAN__)
		{SSC_BULGARIAN,	MMI_FALSE, SSC_STR_ERR_SET_BULGARIAN,SSC_SCR_LANGUAGE_BULGARIAN_STR_ID},
#endif 
#if defined(__MMI_LANG_UKRAINIAN__)
		{SSC_UKRAINIAN,	MMI_FALSE, SSC_STR_ERR_SET_UKRAINIAN,SSC_SCR_LANGUAGE_UKRAINIAN_STR_ID},
#endif 
#if defined(__MMI_LANG_PORTUGUESE__)
		{SSC_PORTUGUESE, MMI_FALSE,	SSC_STR_ERR_SET_PORTUGUESE,SSC_SCR_LANGUAGE_PORTUGUESE_STR_ID},
#endif 
#if defined(__MMI_LANG_TURKISH__)
		{SSC_TURKISH,	MMI_FALSE, SSC_STR_ERR_SET_TURKISH,SSC_SCR_LANGUAGE_TURKISH_STR_ID},
#endif 
#if defined(__MMI_LANG_VIETNAMESE__)
		{SSC_VIETNAMESE, MMI_FALSE,	SSC_STR_ERR_SET_VIETNAMESE,SSC_SCR_LANGUAGE_VIETNAMESE_STR_ID},
#endif 
#if defined(__MMI_LANG_INDONESIAN__)
		{SSC_INDONESIAN, MMI_FALSE,	SSC_STR_ERR_SET_INDONESIAN,SSC_SCR_LANGUAGE_INDONESIAN_STR_ID},
#endif 
#if defined(__MMI_LANG_CZECH__)
		{SSC_CZECH,	MMI_FALSE, SSC_STR_ERR_SET_CZECH,SSC_SCR_LANGUAGE_CZECH_STR_ID},
#endif 
#if defined(__MMI_LANG_MALAY__)
		{SSC_MALAY,	MMI_FALSE, SSC_STR_ERR_SET_MALAY,SSC_SCR_LANGUAGE_MALAY_STR_ID},
#endif 
#if defined(__MMI_LANG_FINNISH__)
		{SSC_FINNISH,	MMI_FALSE, SSC_STR_ERR_SET_FINNISH,SSC_SCR_LANGUAGE_FINNISH_STR_ID},
#endif 
#if defined(__MMI_LANG_HUNGARIAN__)
		{SSC_HUNGARIAN,	MMI_FALSE, SSC_STR_ERR_SET_HUNGARIAN,SSC_SCR_LANGUAGE_HUNGARIAN_STR_ID},
#endif 
#if defined(__MMI_LANG_SLOVAK__)
		{SSC_SLOVAK, MMI_FALSE,	SSC_STR_ERR_SET_SLOVAK,SSC_SCR_LANGUAGE_SLOVAK_STR_ID},
#endif 
#if defined(__MMI_LANG_DUTCH__)
		{SSC_DUTCH,	MMI_FALSE, SSC_STR_ERR_SET_DUTCH,SSC_SCR_LANGUAGE_DUTCH_STR_ID},
#endif 
#if defined(__MMI_LANG_NORWEGIAN__)
		{SSC_NORWEGIAN,	MMI_FALSE, SSC_STR_ERR_SET_NORWEGIAN,SSC_SCR_LANGUAGE_NORWEGIAN_STR_ID},
#endif 
#if defined(__MMI_LANG_SWEDISH__)
		{SSC_SWEDISH,	MMI_FALSE, SSC_STR_ERR_SET_SWEDISH,SSC_SCR_LANGUAGE_SWEDISH_STR_ID},
#endif 
#if defined(__MMI_LANG_CROATIAN__)
		{SSC_CROATIAN, MMI_FALSE, SSC_STR_ERR_SET_CROATIAN, SSC_SCR_LANGUAGE_CROATIAN_STR_ID},
#endif 
#if defined(__MMI_LANG_ROMANIAN__)
		{SSC_ROMANIAN, MMI_FALSE, SSC_STR_ERR_SET_ROMANIAN, SSC_SCR_LANGUAGE_ROMANIAN_STR_ID},
#endif 
#if defined(__MMI_LANG_SLOVENIAN__)
		{SSC_SLOVENIAN, MMI_FALSE, SSC_STR_ERR_SET_SLOVENIAN, SSC_SCR_LANGUAGE_SLOVENIAN_STR_ID},
#endif 
#if defined(__MMI_LANG_GREEK__)
		{SSC_GREEK, MMI_FALSE, SSC_STR_ERR_SET_GREEK, SSC_SCR_LANGUAGE_GREEK_STR_ID},
#endif 
#if defined(__MMI_LANG_HEBREW__)
		{SSC_HEBREW, MMI_FALSE,	SSC_STR_ERR_SET_HEBREW,SSC_SCR_LANGUAGE_HEBREW_STR_ID},
#endif /*defined(__MMI_LANG_HEBREW__)*/ 
#if defined(__MMI_LANG_ARABIC__)
		{SSC_ARABIC, MMI_FALSE,	SSC_STR_ERR_SET_ARABIC,SSC_SCR_LANGUAGE_ARABIC_STR_ID},
#endif /*defined(__MMI_LANG_ARABIC__)*/ 
#if defined(__MMI_LANG_PERSIAN__)
		{SSC_PERSIAN, MMI_FALSE, SSC_STR_ERR_SET_PERSIAN, SSC_SCR_LANGUAGE_PERSIAN_STR_ID},
#endif 
#if defined(__MMI_LANG_URDU__)
		{SSC_URDU, MMI_FALSE, SSC_STR_ERR_SET_URDU, SSC_SCR_LANGUAGE_URDU_STR_ID},
#endif
#if defined(__MMI_LANG_HINDI__)
		{SSC_HINDI,	MMI_FALSE, SSC_STR_ERR_SET_HINDI, SSC_SCR_LANGUAGE_HINDI_STR_ID},
#endif /*defined	(__MMI_LANG_HINDI__) */	
#if defined(__MMI_LANG_MARATHI__)
		{SSC_MARATHI,	MMI_FALSE, SSC_STR_ERR_SET_MARATHI, SSC_SCR_LANGUAGE_MARATHI_STR_ID},
#endif 
#if defined(__MMI_LANG_TAMIL__)
		{SSC_TAMIL,	MMI_FALSE, SSC_STR_ERR_SET_TAMIL, SSC_SCR_LANGUAGE_TAMIL_STR_ID},
#endif
#if defined(__MMI_LANG_UK_ENGLISH__)
		{SSC_UK_ENGLISH, MMI_FALSE,	SSC_STR_ERR_SET_UK_ENGLISH,SSC_SCR_LANGUAGE_UK_ENGLISH_STR_ID},
#endif
#if defined(__MMI_LANG_HK_CHINESE__)
		{SSC_HK_CHINESE, MMI_FALSE, SSC_STR_ERR_SET_HK_CHINESE, SSC_SCR_LANGUAGE_HK_CHINESE_STR_ID},
#endif
#if defined(__MMI_LANG_CA_FRENCH__)
		{SSC_CA_FRENCH, MMI_FALSE, SSC_STR_ERR_SET_CA_FRENCH, SSC_SCR_LANGUAGE_CA_FRENCH_STR_ID},
#endif
#if defined(__MMI_LANG_SA_SPANISH__)
		{SSC_SA_SPANISH, MMI_FALSE, SSC_STR_ERR_SET_SA_SPANISH, SSC_SCR_LANGUAGE_SA_SPANISH_STR_ID},
#endif
#if defined(__MMI_LANG_SA_PORTUGUESE__)
		{SSC_SA_PORTUGUESE, MMI_FALSE, SSC_STR_ERR_SET_SA_PORTUGUESE, SSC_SCR_LANGUAGE_SA_PORTUGUESE_STR_ID},
#endif
#if defined(__MMI_LANG_ICELANDIC__)
		{SSC_ICELANDIC, MMI_FALSE, SSC_STR_ERR_SET_ICELANDIC, SSC_SCR_LANGUAGE_ICELANDIC_STR_ID},
#endif
#if defined(__MMI_LANG_SERBIAN__)
		{SSC_SERBIAN, MMI_FALSE, SSC_STR_ERR_SET_SERBIAN, SSC_SCR_LANGUAGE_SERBIAN_STR_ID},
#endif
#if defined(__MMI_LANG_AZERBAIJANI__)
		{SSC_AZERBAIJANI, MMI_FALSE, SSC_STR_ERR_SET_AZERBAIJANI, SSC_SCR_LANGUAGE_AZERBAIJANI_STR_ID},
#endif
#if defined(__MMI_LANG_CATALAN__)
		{SSC_CATALAN, MMI_FALSE, SSC_STR_ERR_SET_CATALAN, SSC_SCR_LANGUAGE_CATALAN_STR_ID},
#endif
#if defined(__MMI_LANG_KAZAKH__)
		{SSC_KAZAKH, MMI_FALSE, SSC_STR_ERR_SET_KAZAKH, SSC_SCR_LANGUAGE_KAZAKH_STR_ID},
#endif
#if defined(__MMI_LANG_HAUSA__)
		{SSC_HAUSA, MMI_FALSE, SSC_STR_ERR_SET_HAUSA, SSC_SCR_LANGUAGE_HAUSA_STR_ID},
#endif
#if defined(__MMI_LANG_MACEDONIAN__)
		{SSC_MACEDONIAN, MMI_FALSE, SSC_STR_ERR_SET_MACEDONIAN, SSC_SCR_LANGUAGE_MACEDONIAN_STR_ID},
#endif
#if defined(__MMI_LANG_SESOTHO__)
		{SSC_SESOTHO, MMI_FALSE, SSC_STR_ERR_SET_SESOTHO,SSC_SCR_LANGUAGE_SESOTHO_STR_ID},
#endif
#if defined(__MMI_LANG_TAGALOG__)
		{SSC_TAGALOG, MMI_FALSE, SSC_STR_ERR_SET_TAGALOG,SSC_SCR_LANGUAGE_TAGALOG_STR_ID},
#endif
#if defined(__MMI_LANG_YORUBA__)
		{SSC_YORUBA, MMI_FALSE, SSC_STR_ERR_SET_YORUBA,SSC_SCR_LANGUAGE_YORUBA_STR_ID},
#endif
#if defined(__MMI_LANG_GALICIAN__)
		{SSC_GALICIAN, MMI_FALSE, SSC_STR_ERR_SET_GALICIAN,SSC_SCR_LANGUAGE_GALICIAN_STR_ID},
#endif
#if defined(__MMI_LANG_BASQUE__)
		{SSC_BASQUE, MMI_FALSE, SSC_STR_ERR_SET_BASQUE, SSC_SCR_LANGUAGE_BASQUE_STR_ID},
#endif
#if defined(__MMI_LANG_IGBO__)
		{SSC_IGBO, MMI_FALSE, SSC_STR_ERR_SET_IGBO, SSC_SCR_LANGUAGE_IGBO_STR_ID},
#endif
#if defined(__MMI_LANG_FILIPINO__)
		{SSC_FILIPINO, MMI_FALSE, SSC_STR_ERR_SET_FILIPINO, SSC_SCR_LANGUAGE_FILIPINO_STR_ID},
#endif
#if defined(__MMI_LANG_IRISH__)
		{SSC_IRISH,	MMI_FALSE, SSC_STR_ERR_SET_IRISH, SSC_SCR_LANGUAGE_IRISH_STR_ID},
#endif
#if defined(__MMI_LANG_BENGALI__)
		{SSC_BENGALI,	MMI_FALSE, SSC_STR_ERR_SET_BENGALI, SSC_SCR_LANGUAGE_BENGALI_STR_ID},
#endif /*defined(__MMI_LANG_BENGALI__) */
#if defined(__MMI_LANG_ASSAMESE__)
		{SSC_ASSAMESE, MMI_FALSE, SSC_STR_ERR_SET_ASSAMESE, SSC_SCR_LANGUAGE_ASSAMESE_STR_ID},
#endif /*defined(__MMI_LANG_ASSAMESE__)*/ 
#if defined(__MMI_LANG_PUNJABI__)
		{SSC_PUNJABI, MMI_FALSE, SSC_STR_ERR_SET_PUNJABI, SSC_SCR_LANGUAGE_PUNJABI_STR_ID},
#endif
#if defined(__MMI_LANG_TELUGU__)
		{SSC_TELUGU, MMI_FALSE, SSC_STR_ERR_SET_TELUGU, SSC_SCR_LANGUAGE_TELUGU_STR_ID},
#endif
#if defined(__MMI_LANG_KANNADA__)
		{SSC_KANNADA, MMI_FALSE, SSC_STR_ERR_SET_KANNADA, SSC_SCR_LANGUAGE_KANNADA_STR_ID},
#endif
#if defined(__MMI_LANG_MALAYALAM__)
		{SSC_MALAYALAM, MMI_FALSE, SSC_STR_ERR_SET_MALAYALAM, SSC_SCR_LANGUAGE_MALAYALAM_STR_ID},
#endif
#if defined(__MMI_LANG_LAO__)
		{SSC_LAO, MMI_FALSE, SSC_STR_ERR_SET_LAO, SSC_SCR_LANGUAGE_LAO_STR_ID},
#endif
#if defined(__MMI_LANG_KHMER__)
		{SSC_KHMER, MMI_FALSE, SSC_STR_ERR_SET_KHMER, SSC_SCR_LANGUAGE_KHMER_STR_ID},
#endif
#if defined(__MMI_LANG_MYANMAR__)
		{SSC_MYANMAR, MMI_FALSE, SSC_STR_ERR_SET_MYANMAR, SSC_SCR_LANGUAGE_MYANMAR_STR_ID},
#endif
#if defined(__MMI_LANG_GUJARATI__)
		{SSC_GUJARATI, MMI_FALSE, SSC_STR_ERR_SET_GUJARATI, SSC_SCR_LANGUAGE_GUJARATI_STR_ID},
#endif
#if defined(__MMI_LANG_ORIYA__)
		{SSC_ORIYA, MMI_FALSE, SSC_STR_ERR_SET_ORIYA, SSC_SCR_LANGUAGE_ORIYA_STR_ID},
#endif
#if defined(__MMI_LANG_XHOSA__)
		{SSC_XHOSA, MMI_FALSE, SSC_STR_ERR_SET_XHOSA, SSC_SCR_LANGUAGE_XHOSA_STR_ID},
#endif
#if defined(__MMI_LANG_SWAHILI__)
		{SSC_SWAHILI, MMI_FALSE, SSC_STR_ERR_SET_SWAHILI, SSC_SCR_LANGUAGE_SWAHILI_STR_ID},
#endif
#if defined(__MMI_LANG_AFRIKAANS__)
		{SSC_AFRIKAANS, MMI_FALSE, SSC_STR_ERR_SET_AFRIKAANS, SSC_SCR_LANGUAGE_AFRIKAANS_STR_ID},
#endif
#if defined(__MMI_LANG_ZULU__)
		{SSC_ZULU, MMI_FALSE, SSC_STR_ERR_SET_ZULU, SSC_SCR_LANGUAGE_ZULU_STR_ID},
#endif
#if defined(__MMI_LANG_LITHUANIAN__)
		{SSC_LITHUANIAN, MMI_FALSE, SSC_STR_ERR_SET_LITHUANIAN, SSC_SCR_LANGUAGE_LITHUANIAN_STR_ID},
#endif
#if defined(__MMI_LANG_LATVIAN__)
		{SSC_LATVIAN, MMI_FALSE, SSC_STR_ERR_SET_LATVIAN, SSC_SCR_LANGUAGE_LATVIAN_STR_ID},
#endif
#if defined(__MMI_LANG_ESTONIAN__)
		{SSC_ESTONIAN, MMI_FALSE, SSC_STR_ERR_SET_ESTONIAN, SSC_SCR_LANGUAGE_ESTONIAN_STR_ID},
#endif
#if defined(__MMI_LANG_ALBANIAN__)
		{SSC_ALBANIAN, MMI_FALSE, SSC_STR_ERR_SET_ALBANIAN,SSC_SCR_LANGUAGE_ALBANIAN_STR_ID},
#endif
#if defined(__MMI_LANG_ARMENIAN__)
		{SSC_ARMENIAN, MMI_FALSE, SSC_STR_ERR_SET_ARMENIAN, SSC_SCR_LANGUAGE_ARMENIAN_STR_ID},
#endif
#if defined(__MMI_LANG_GEORGIAN__)
		{SSC_GEORGIAN, MMI_FALSE, SSC_STR_ERR_SET_GEORGIAN, SSC_SCR_LANGUAGE_GEORGIAN_STR_ID},
#endif
#if defined(__MMI_LANG_MOLDOVAN__)
		{SSC_MOLDOVAN, MMI_FALSE, SSC_STR_ERR_SET_MOLDOVAN, SSC_SCR_LANGUAGE_MOLDOVAN_STR_ID},
#endif
#if defined(__MMI_LANG_SM_CHINESE__)
		{SSC_SCHINESE, MMI_FALSE, SSC_STR_ERR_SET_SCHINESE, SSC_SCR_LANGUAGE_SCHINESE_STR_ID}
#endif
};


/*****************************************************************************
 * FUNCTION
 *  SSCHandleSSCString
 * DESCRIPTION
 *  Handle SSC string for all the languages.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleSSCString(const CHAR* ssc_string, S32 error, S32 success)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8 count = 0;
	S16 i;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	for (count = 0; count < MAX_LANGUAGES; count++)
	{
		if (strcmp((CHAR*) gLanguageArray[count].aLangSSC, ssc_string) == 0)
		{
			i = mmi_lang_support((U8 *)ssc_string);
			if (i < 0)
			{
				break;
			}
				
		#ifndef __COSMOS_MMI_PACKAGE__
			if (gCurrLangIndex != count)
			{
				mmi_setting_set_language(count);
				mmi_idle_update_service_area();
			}
            
			mmi_idle_display();
			
			mmi_ssc_popup(
				get_string(success),
				MMI_EVENT_SUCCESS);

			return;
		#else
            #ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
			vapp_dialer_language_switch(mmi_ssc_main_screen_g, (U8 *) ssc_string);
            #else
			vapp_dialer_language_switch(mmi_ssc_main_screen_g, count);
            #endif
			return;
		#endif
		}
	}

#ifndef __COSMOS_MMI_PACKAGE__
	mmi_idle_display();
#endif	

	mmi_ssc_popup(
		get_string(error),
		MMI_EVENT_FAILURE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_phone_string_pass
 * DESCRIPTION
 *  Check the Supplement Service Control String table 1
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_ssc_phone_string_pass(WCHAR *str)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8 index = 0;

#ifdef __UCS2_ENCODING
	U8 temp_str[MAX_SSC_STRING];
#endif 
	U8 *pTemp;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	for (index = 0; index < (sizeof(mmi_ssc_phone_table) / sizeof(mmi_ssc_phone_table[0])); index++)
	{
	#ifdef __UCS2_ENCODING
		mmi_asc_to_ucs2((CHAR*) temp_str, (CHAR*) mmi_ssc_phone_table[index].ssc_string);
		pTemp = (U8*) temp_str;
	#endif /* __UCS2_ENCODING */ 
	#ifdef __ASCII
		pTemp = (U8*) mmi_ssc_phone_table[index].ssc_string;
	#endif 

		if (mmi_ucs2cmp((CHAR*) pTemp, (CHAR*) str) == 0)
		{
			if (!mmi_ssc_phone_table[index].ssc_disable_ctrl
			#ifdef __MTK_INTERNAL__
/* under construction !*/
			#endif
				)
			{
				if (mmi_ssc_phone_table[index].func_ptr != NULL)
				{
					if (ssc_disable_flag && mmi_ssc_phone_table[index].ssc_disable_ctrl)     /* diamond, 2005/05/13 for SSC disable */
					{
						return MMI_FALSE;
					}
				#if defined(__MMI_SML_MENU__) && !defined(__MMI_DUAL_SIM_MASTER__)
					mmi_sml_reset_menu_content();
				#endif
					mmi_ssc_phone_table[index].func_ptr();
					return MMI_TRUE;
				}
			}
		}
	}

#if defined __VENUS_UI_ENGINE__ /*Only triggered if __VFX_HEAP_PROFILE__ defined in vfx_config.h*/
{
	extern MMI_BOOL vfx_heap_profiling_ssc_check(WCHAR* str /*user key in data*/,
				CHAR* temp_str /*temp buffer*/, 
				CHAR* pattern_disable, 
				CHAR* pattern_enable, CHAR* pattern_enable_cfg1, CHAR* pattern_enable_cfg2);
	if ( MMI_TRUE == vfx_heap_profiling_ssc_check(str,
								 (CHAR*)temp_str, 
								 VFX_HEAP_PROFILE_DISABLE,
								 VFX_HEAP_PROFILE_ENABLE,
								 VFX_HEAP_PROFILE_ENABLE_CFG1,
								 VFX_HEAP_PROFILE_ENABLE_CFG2
								 ) )
	{
		return MMI_TRUE;
	}
}
#endif

	mmi_asc_to_ucs2((CHAR*) temp_str, (CHAR*) MEM_CTRL_BUF_DBG);
	if (mmi_ucs2ncmp
		((const CHAR*)temp_str, (const CHAR*)str,
		 (U32) mmi_ucs2strlen((const CHAR*)temp_str)) == 0)
	{
		U8 temp_str2[100], temp_str3[100];
		U32 value;
		extern void kal_monitor_buffer(kal_uint32 index);

		memset(temp_str2, 0, sizeof(temp_str2));
		mmi_ucs2ncpy(
			(CHAR*) temp_str2,
			(const CHAR*)&str[strlen(MEM_CTRL_BUF_DBG)],
			(U32) (mmi_wcslen(str) - strlen(MEM_CTRL_BUF_DBG)));
	#ifdef __UCS2_ENCODING
		mmi_ucs2_to_asc((CHAR*) temp_str3, (CHAR*) temp_str2);
		value = atoi((CHAR*) temp_str3);
	#else /* __UCS2_ENCODING */ 
		value = atoi((CHAR*) temp_str2);
	#endif /* __UCS2_ENCODING */ 
    
		mmi_ssc_popup(
			(WCHAR *)temp_str2,
			MMI_EVENT_SUCCESS);

		kal_monitor_buffer(value);

		return MMI_TRUE;
	}
	mmi_asc_to_ucs2((CHAR*) temp_str, (CHAR*) MEM_CTRL_BUF_QRY);
	if (mmi_ucs2cmp((const CHAR*)temp_str, (const CHAR*)str) == 0)
	{
		U8 temp_str[100], temp_str2[100];
		extern kal_uint32 kal_query_buffer_monitor(void);

		sprintf((CHAR*) temp_str, "Ctrl Buffer=%d", kal_query_buffer_monitor());
	#ifdef __UCS2_ENCODING
		mmi_asc_to_ucs2((CHAR*) temp_str2, (CHAR*) temp_str);
		mmi_ssc_popup(
			(WCHAR *)temp_str2,
			MMI_EVENT_SUCCESS);
	#else /* __UCS2_ENCODING */ 
		mmi_ssc_popup(
			(WCHAR *)temp_str,
			MMI_EVENT_SUCCESS);
	#endif /* __UCS2_ENCODING */ 
		SetLeftSoftkeyFunction(mmi_idle_display, KEY_EVENT_UP);
		return MMI_TRUE;
	}

	mmi_asc_to_ucs2((CHAR*) temp_str, (CHAR*) TASK_CTRL_BUF_DBG);
	if (mmi_ucs2ncmp
		((const CHAR*)temp_str, (const CHAR*)str,
		 (U32) mmi_ucs2strlen((const CHAR*)temp_str)) == 0)
	{
		U8 temp_str2[100], temp_str3[100];
		U32 value;
		extern kal_uint32 task_debug_mask_g[];

		memset(temp_str2, 0, sizeof(temp_str2));
		mmi_ucs2ncpy(
			(CHAR*) temp_str2,
			(const CHAR*)&str[strlen(TASK_CTRL_BUF_DBG)],
			(U32) (mmi_wcslen(str) - strlen(TASK_CTRL_BUF_DBG)));
	#ifdef __UCS2_ENCODING
		mmi_ucs2_to_asc((CHAR*) temp_str3, (CHAR*) temp_str2);
		value = atoi((CHAR*) temp_str3);
	#else /* __UCS2_ENCODING */ 
		value = atoi((CHAR*) temp_str2);
	#endif /* __UCS2_ENCODING */ 
    
		mmi_ssc_popup(
			(WCHAR *)temp_str2,
			MMI_EVENT_SUCCESS);

		task_debug_mask_g[0] = value;

		return MMI_TRUE;
	}
	mmi_asc_to_ucs2((CHAR*) temp_str, (CHAR*) TASK_CTRL_BUF_QRY);
	if (mmi_ucs2cmp((const CHAR*)temp_str, (const CHAR*)str) == 0)
	{
		U8 temp_str[100], temp_str2[100];
		extern kal_uint32 task_debug_mask_g[];

		sprintf((CHAR*) temp_str, "Task dbg mask=%d", task_debug_mask_g[0]);
	#ifdef __UCS2_ENCODING
		mmi_asc_to_ucs2((CHAR*) temp_str2, (CHAR*) temp_str);
		mmi_ssc_popup(
			(WCHAR *)temp_str2,
			MMI_EVENT_SUCCESS);
	#else /* __UCS2_ENCODING */
		mmi_ssc_popup(
			(WCHAR *)temp_str,
			MMI_EVENT_SUCCESS);
	#endif /* __UCS2_ENCODING */ 
		SetLeftSoftkeyFunction(mmi_idle_display, KEY_EVENT_UP);
		return MMI_TRUE;
	}

	return MMI_FALSE;
}


#ifdef __COSMOS_MMI_PACKAGE__
MMI_BOOL mmi_ssc_phone_string_pass_ex(WCHAR *str, void* scr)
{
	mmi_ssc_main_screen_g = scr;
	return mmi_ssc_phone_string_pass(str);
}


MMI_BOOL mmi_ssc_lauguage_string_pass_ex(WCHAR *str, void* scr)
{
	mmi_ssc_main_screen_g = scr;
	return mmi_ssc_lauguage_string_pass(str);
}


MMI_BOOL mmi_ssc_sim_string_pass_ex(WCHAR *str, void* scr)
{
	mmi_ssc_main_screen_g = scr;
	mmi_wcscpy(mmi_dialer_ssc_string, str);
	return mmi_ssc_sim_string_pass(str);
}


#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_lauguage_string_pass
 * DESCRIPTION
 *  Check the Supplement Service Control String table 2
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_ssc_lauguage_string_pass(WCHAR *str)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8 index = 0;

#ifdef __UCS2_ENCODING
	U8 temp_str[MAX_SSC_STRING];
#endif 
	U8 *pTemp;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	for (index = 0; index < (sizeof(mmi_ssc_language_table) / sizeof(mmi_ssc_language_table[0])); index++)
	{

	#ifdef __UCS2_ENCODING
		mmi_asc_to_ucs2((CHAR*) temp_str, (CHAR*) mmi_ssc_language_table[index].ssc_string);
		pTemp = (U8*) temp_str;
	#endif /* __UCS2_ENCODING */ 
	#ifdef __ASCII
		pTemp = (U8*) mmi_ssc_language_table[index].ssc_string;
	#endif 

		if (mmi_ucs2cmp((CHAR*) pTemp, (CHAR*) str) == 0)
		{
			/*if (ssc_table2[index].func_ptr != NULL)
			{
				ssc_table2[index].func_ptr();
			}*/
			if (strcmp((CHAR*)mmi_ssc_language_table[index].ssc_string, (CHAR*)SSC_AUTO) == 0)
			{
				SSCHandleSSCString(SSC_DEFAULT, mmi_ssc_language_table[index].error_string, mmi_ssc_language_table[index].success_string);  
			}
			else
			{
				SSCHandleSSCString(mmi_ssc_language_table[index].ssc_string, mmi_ssc_language_table[index].error_string, mmi_ssc_language_table[index].success_string);  
			}

			return MMI_TRUE;
		}
	}
	return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_sim_string_pass
 * DESCRIPTION
 *  Chech the Supplement Service Control String table 3
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_ssc_sim_string_pass(WCHAR *str)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8 index = 0, rtn = 0;

#ifdef __UCS2_ENCODING
	U8 temp_str[MAX_SSC_STRING];
#endif 
	U8 *pTemp;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	for (index = 0; index < (sizeof(mmi_ssc_sim_table) / sizeof(mmi_ssc_sim_table[0])); index++)
	{
	#ifdef __UCS2_ENCODING
		mmi_asc_to_ucs2((CHAR*) temp_str, (CHAR*) mmi_ssc_sim_table[index].sim_string);
		pTemp = (U8*) temp_str;
	#endif /* __UCS2_ENCODING */ 
	#ifdef __ASCII
		pTemp = (U8*) mmi_ssc_sim_table[index].sim_string;
	#endif 

		if (mmi_ucs2ncmp((CHAR*) pTemp, (CHAR*) str, mmi_ssc_sim_table[index].sim_length) == 0)
		{
			if (mmi_ssc_sim_table[index].func_ptr != NULL)
			{
				/* temporarily copy the dialed buffer to dial pad if UCM ask to check sim operation */
				if (index == 2 || index == 3)
				{
					mmi_ucs2cpy(ssc_dialpad_buffer, (CHAR*) str);
				}
				rtn = mmi_ssc_sim_table[index].func_ptr();
			}
			return (MMI_BOOL) rtn;
		}
	}

	return MMI_FALSE;

}



