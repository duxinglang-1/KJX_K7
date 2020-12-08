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
 *  SSCSrvIprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains prototypes for Phonebook internal service layer.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef SSCSTRINGTABLE_H
#define SSCSTRINGTABLE_H

#include "MMIDataType.h"

/* auto add by kw_check begin */
#include "MMI_features.h"
/* auto add by kw_check end */

#define MMI_FRM_SSC_REG(_cb) extern void _cb(void);
#define MMI_FRM_SSC_U8_REG(_cb) extern U8 _cb(void);

#define SSC_TABLE_1

MMI_FRM_SSC_REG(SSCHandleIMEI)
MMI_FRM_SSC_REG(mmi_SSC_handle_software_version_summary)
#ifdef __MMI_HW_VERSION__
MMI_FRM_SSC_REG(mmi_SSC_handle_hardware_version}
#endif
#ifdef __MMI_ENGINEER_MODE__
MMI_FRM_SSC_REG(mmi_em_pre_entry_engineermode_menu)
#endif
#ifdef __MMI_FACTORY_MODE__ 
MMI_FRM_SSC_REG(EntryFMMenu)
MMI_FRM_SSC_REG(EntryFMMenuAutoTest)
#endif

#ifdef __MMI_FM_LCD_CONTRAST__
MMI_FRM_SSC_REG(mmi_SSC_handle_LCD_contrast_setting)
#endif

MMI_FRM_SSC_REG(SSCHandleDisable)
#ifdef __MMI_SML_MENU__
#ifdef __MMI_DUAL_SIM_MASTER__
MMI_FRM_SSC_REG(mmi_sml_entry_lock_category_sim_interface)
MMI_FRM_SSC_REG(mmi_sml_entry_unlock_category_sim_interface)
MMI_FRM_SSC_REG(mmi_sml_entry_add_category_sim_interface)
MMI_FRM_SSC_REG(mmi_sml_entry_remove_category_sim_interface)
MMI_FRM_SSC_REG(mmi_sml_entry_permanent_unlock_sim_interface)
#else
MMI_FRM_SSC_REG(mmi_sml_entry_lock_category_selection)
MMI_FRM_SSC_REG(mmi_sml_entry_unlock_category_selection)
MMI_FRM_SSC_REG(mmi_sml_entry_add_category_data)
MMI_FRM_SSC_REG(mmi_sml_entry_remove_category_data)
MMI_FRM_SSC_REG(mmi_sml_entry_permanent_unlock_selection)
#endif
#endif /* __MMI_SML_MENU__ */
#ifdef __MMI_A2DP_SUPPORT__
MMI_FRM_SSC_REG(SSCHandle_BT_A2DP_Toggle_PTS_Mode)
#endif /* __MMI_A2DP_SUPPORT__ */
#ifdef __BTMTK__
MMI_FRM_SSC_REG(SSCHandle_BT_PTS_SIMAP_Graceful_Disc_Type)
MMI_FRM_SSC_REG(SSCHandle_BT_PTS_SIMAP_Immediate_Disc_Type)
MMI_FRM_SSC_REG(SSCHandle_BT_PTS_SIMAP_PRS)
#endif /* __BTMTK__ */ 
#ifdef __MMI_BT_SUPPORT__
MMI_FRM_SSC_REG(mmi_bt_enable_pts_test)
MMI_FRM_SSC_REG(mmi_bt_disable_pts_test)
#endif /* __MMI_BT_SUPPORT__ */ 
#ifdef __DRM_V02__
MMI_FRM_SSC_REG(OSD_STime_Switch)
MMI_FRM_SSC_REG(OSD_PKI_Format_Switch)
MMI_FRM_SSC_REG(mmi_rmgr_switch_cermgr)
#endif
#if defined(__AGPS_SUPPORT__) && defined(__SUPL_SUPPORT__)
MMI_FRM_SSC_REG(em_gps_open_soc)
MMI_FRM_SSC_REG(em_gps_close_soc)
MMI_FRM_SSC_REG(em_gps_gps_reset_chip_off_104)
MMI_FRM_SSC_REG(em_gps_gps_reset_chip_on_104)
MMI_FRM_SSC_REG(em_gps_reset_data_104)
MMI_FRM_SSC_REG(em_gps_gps_reset_chip_off_103)
MMI_FRM_SSC_REG(em_gps_gps_reset_chip_on_103)
MMI_FRM_SSC_REG(em_gps_reset_data_103)
MMI_FRM_SSC_REG(em_gps_reset_data_102)
#endif
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
MMI_FRM_SSC_REG(mmi_op11_hs32_activate_by_ssc)
#endif
#if defined(__MMI_TOUCH_SCREEN__)
MMI_FRM_SSC_REG(mmi_idle_disable_lock_by_end_key)
#endif
#ifdef __VENUS_UI_ENGINE__
MMI_FRM_SSC_REG(mmi_SSC_handle_venus_UI_test)
#endif
#if defined (__FLAVOR_VENDOR_SDK__) || defined(__MAUI_SDK_TEST__)
MMI_FRM_SSC_REG(SSCHandleAvkApp)
#endif
MMI_FRM_SSC_REG(srv_fmgr_testbed_launch)
MMI_FRM_SSC_REG(SSCHandleVendorApp)
MMI_FRM_SSC_REG(ssc_show_logo_screen)
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
MMI_FRM_SSC_REG(gui_sse_test)
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
#if defined(__MMI_EM_PROFILING_VENUS_DEBUG_PANEL__)
MMI_FRM_SSC_REG(mmi_ssc_venus_debug_panel)
#endif

#define SSC_TABLE_3

MMI_FRM_SSC_U8_REG(mmi_ssc_process_chv)
#ifdef __MMI_SML_MENU__
#ifdef __MMI_DUAL_SIM_MASTER__
MMI_FRM_SSC_U8_REG(mmi_sml_entry_lock_req_sim_interface)
MMI_FRM_SSC_U8_REG(mmi_sml_entry_unlock_req_sim_interface)
MMI_FRM_SSC_U8_REG(mmi_sml_entry_query_req_sim_interface)
#else
MMI_FRM_SSC_U8_REG(mmi_sml_send_lock_req_by_ssc)
MMI_FRM_SSC_U8_REG(mmi_sml_send_unlock_req_by_ssc)
MMI_FRM_SSC_U8_REG(mmi_sml_send_query_req_by_ssc)
#endif
#endif /* __MMI_SML_MENU__ */


/*  Table1 String Define */
#define SSC_SW_VERSION             "*#8375#"
#define SSC_HW_VERSION             "*#357#" //Not used if __MMI_HW_VERSION__ is not turned on
#ifdef __MMI_ENGINEER_MODE__
#define SSC_ENGINEERING_MODE       "*#3646633#"
#endif
#ifdef __MMI_FACTORY_MODE__
#define SSC_FACTORY_MODE           "*#66*#"
#define SSC_FACTORY_MODE_AUTOTEST  "*#87#"
#endif
#define SSC_SET_LCD_CONTRAST       "*#523#"
#define SSC_DISABLE_FOR_SHIPMENT   "*#6810#"
#ifdef __MMI_SML_MENU__
#define SSC_SML_ADD_CODE           "###765*02#"
#define SSC_SML_REMOVE_CODE        "###765*07#"
#define SSC_SML_LOCK_CODE          "###765*05#"
#define SSC_SML_UNLOCK_CODE        "###765*08#"
#define SSC_SML_DEACTIVATE_CODE    "###765*78#" /* permanent unlock */
#endif /* __MMI_SML_MENU__ */
#if defined(__MMI_A2DP_SUPPORT__)
#define SSC_BT_A2DP_TOGGLE_PTS_MODE "*#1234#"
#endif
#define BT_POWER_ON "*#900#"
#define BT_POWER_OFF "*#901#"
#define BT_PTS_SIMAP_GRACEFUL_DISC_TYPE_ON  "*#931#" 
#define BT_PTS_SIMAP_IMMEDIATE_DISC_TYPE_ON "*#932#"
#define BT_PTS_SIMAP_UNAVAILABLE_SIM_SEND_STATUS_IND    "*#933#"
#define BT_PTS_ON                       "*#902#"
#define BT_PTS_OFF                      "*#903#"
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) 
#define SSC_OP11_HOMESCREEN        "*#20801#"
#endif /* __MMI_OP11_HOMESCREEN__ */

#define SSC_DISABLE_KEYPAD_LOCK_BY_END_KEY  "*#5566183#"

#if defined (__FLAVOR_VENDOR_SDK__) || defined(__MAUI_SDK_TEST__)
#define SSC_AVKAPP                 "*#87285*#"
#endif
#define SSC_VENDORAPP              "*#3366*#"

/*  Table3 String Define */
#ifdef __MMI_SML_MENU__
#define SSC_SML_LOCK_CMD           "*7525#"
#define SSC_SML_UNLOCK_CMD         "#7525#"
#define SSC_SML_QUERY_CMD          "*#7525#"
#endif


/* Table2 String define */
#define SSC_AUTO "*#0000#"
#define SSC_SCHINESE "*#0086#"
#define SSC_TCHINESE "*#0886#"
#define SSC_ENGLISH     "*#0044#"
#define SSC_DEFAULT     "*#0044#"
#define SSC_SPANISH  "*#0034#"
#define SSC_DANISH   "*#0045#"
#define SSC_POLISH   "*#0048#"
#define SSC_THAI  "*#0066#"
#define SSC_FRENCH      "*#0033#"
#define SSC_GERMAN   "*#0049#"
#define SSC_ITALIAN  "*#0039#"
#define SSC_RUSSIAN  "*#0007#"
#define SSC_BULGARIAN   "*#0359#"
#define SSC_UKRAINIAN   "*#0380#"
#define SSC_PORTUGUESE  "*#0351#"
#define SSC_TURKISH  "*#0090#"
#define SSC_VIETNAMESE     "*#0084#"
#define SSC_INDONESIAN  "*#0062#"
#define SSC_CZECH "*#0420#"
#define SSC_MALAY "*#0060#"
#define SSC_NORWEGIAN   "*#0047#"
#define SSC_ARABIC "*#0966#"
#define SSC_PERSIAN "*#0098#"
#define SSC_URDU "*#0092#"
#define SSC_HINDI "*#0091#"
#define SSC_TAMIL "*#9144#"
#define SSC_BENGALI "*#9133#"
#define SSC_AZERBAIJANI "*#0994#" /* Azerbaijan*/
#define SSC_CATALAN "*#0376#"/* Andorra */
#define SSC_KAZAKH "*#0071#" /* Kazakstan*/
#define SSC_MACEDONIAN "*#0389#" /* Macedonia*/
#define SSC_YORUBA "*#2341#"/* Nigeria is 0234*/
#define SSC_HAUSA "*#2342#"/* Nigeria is 0234*/
#define SSC_SESOTHO "*#0266#"/* Lesotho*/
#define SSC_TAGALOG "*#0631#" /* Phillipines is 0063 */
#define SSC_SA_PORTUGUESE "*#0055#" /* from Brazil */
#define SSC_CA_FRENCH "*#0001#" /* from canada */
#define SSC_HK_CHINESE "*#0852#" /* from Hong Kong */
#define SSC_UK_ENGLISH "*#0441#" /* from UK */
#define SSC_SA_SPANISH "*#0054#" /* from Argentina */
#define SSC_ICELANDIC "*#0354#" /* from Iceland */
#define SSC_SERBIAN "*#0381#" /* from Serbia */
#define SSC_GALICIAN "*#3498#"
#define SSC_BASQUE "*#3495#"
#define SSC_IGBO "*#2343#" /* Nigeria is 0234*/
#define SSC_FILIPINO "*#0063#" /* Phillipines is 0063 */
#define SSC_IRISH "*#0353#"
#define SSC_KOREAN "*#0082#"

#if defined (__MMI_LANG_ASSAMESE__)
#define SSC_ASSAMESE "*#9161#"
#endif
#if defined (__MMI_LANG_PUNJABI__)
#define SSC_PUNJABI "*#9172#"
#endif
#if defined (__MMI_LANG_TELUGU__)
#define SSC_TELUGU "*#9140#"
#endif
#if defined (__MMI_LANG_KANNADA__)
#define SSC_KANNADA "*#9180#"
#endif
#if defined (__MMI_LANG_MALAYALAM__)
#define SSC_MALAYALAM "*#9171#"
#endif

#define SSC_LAO "*#0856#"
#define SSC_KHMER "*#0855#"
#define SSC_MYANMAR "*#0095#"

#if defined (__MMI_LANG_GUJARATI__)
#define SSC_GUJARATI "*#9127#"
#endif
#if defined (__MMI_LANG_ORIYA__)
#define SSC_ORIYA "*#9174#"
#endif
#define SSC_MARATHI  "*#9122#"
#define SSC_HEBREW "*#0972#"

#define SSC_FINNISH  "*#0358#"
#define SSC_HUNGARIAN   "*#0036#"
#define SSC_SLOVAK   "*#0421#"
#define SSC_DUTCH "*#0031#"
#define SSC_SWEDISH  "*#0046#"
#define SSC_CROATIAN "*#0385#"
#define SSC_ROMANIAN "*#0040#"
#define SSC_SLOVENIAN   "*#0386#"
#define SSC_GREEK "*#0030#"

#define SSC_XHOSA        "*#0027#" /* South Africa */
#define SSC_SWAHILI      "*#0255#" /* Tanzania */
#define SSC_AFRIKAANS    "*#0264#" /* Namibia */
#define SSC_ZULU         "*#0268#" /* Swaziland */
#define SSC_LITHUANIAN   "*#0370#"
#define SSC_LATVIAN      "*#0371#"
#define SSC_ESTONIAN     "*#0372#"
#define SSC_ARMENIAN     "*#0374#"
#define SSC_ALBANIAN     "*#0355#"
#define SSC_GEORGIAN     "*#0995#"
#define SSC_MOLDOVAN     "*#0373#"


#endif /* SSCSTRINGTABLE_H */


