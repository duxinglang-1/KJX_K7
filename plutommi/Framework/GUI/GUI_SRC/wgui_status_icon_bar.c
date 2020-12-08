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
 * wgui_status_icon_bar.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for status icon bars control.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "StatusIconRes.h"
#include "WguiCategoryGprot.h"
#include "CustDataRes.h"
#include "wgui_status_icon_bar.h"


#ifdef __MMI_WLAN_FEATURES__
#include "DataAccountResDef.h"
#endif /* __MMI_WLAN_FEATURES__ */

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gui_typedef.h"
#include "gui_status_icon.h"
#include "gui_status_icon_bar.h"
#include "mmi_rp_srv_status_icons_def.h"
#include "gui.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "wgui_include.h"
#include "gdi_const.h"
#include "wgui.h"
#include "wgui_categories_util.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "wgui_categories_list.h"
#include "mmi_frm_input_gprot.h"
#include "gui_windows.h"
#include "gui_status_icon_bar_pre_oem.h"
#include "gpiosrvgprot.h"
#ifdef __MCARE_COMMON__
#include "MAdpMenuDef.h" 
#endif

#include "GlobalResDef.h"// baiwenlin 20130830  
extern S32 MAIN_LCD_device_width;
extern S32 MAIN_LCD_device_height;
extern S32 SUB_LCD_device_width;
extern S32 Sub_lcd_title_height;
/* For Mode switch revise IT */

#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3) && !defined(__COSMOS_MMI_PACKAGE__))
extern void wgui_cat9010_update_status_icon(S32 icon_id);
#endif
/****************************************************************************
 * Global variable
 ****************************************************************************/
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
MMI_BOOL  g_balloon_need_update = MMI_FALSE;
static MMI_BOOL wgui_status_icon_bar_freeze = MMI_FALSE;
#endif
MMI_BOOL g_wgui_status_icon_bar_warning_mode = MMI_FALSE;
static MMI_BOOL wgui_status_icon_bar_is_hide = MMI_FALSE;

/* The array of status icon */
gui_status_icon_bar_icon_struct wgui_status_icon_bar_icons[MAX_STATUS_ICONS];
/* The array of status icon bar */
gui_status_icon_bar_struct wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_TOTAL_BAR];
/* The array of status icon bar's element */
gui_status_icon_bar_element_struct wgui_status_icon_bar_elements[WGUI_STATUS_ICON_BAR_ELEMENT_NUM];

/* save the icon id of mainlcd horizontal status icon bar */
S32 wgui_status_icon_bar_horizontal_icon_list[WGUI_STATUS_ICON_BAR_MAINLCD_H_ICON_LIST_NUM];
/* save the icon id of mainlcd vertical status icon bar */
S32 wgui_status_icon_bar_vertical_icon_list[WGUI_STATUS_ICON_BAR_MAINLCD_V_ICON_LIST_NUM];
/* save the icon id of sublcd horizontal status icon bar */
S32 wgui_status_icon_bar_sublcd_horizontal_icon_list[WGUI_STATUS_ICON_BAR_SUBLCD_ICON_LIST_NUM];
/* save the element id of mainlcd horizontal status icon bar */
S32 wgui_status_icon_bar_mainlcd_horizontal_element_list[WGUI_STATUS_ICON_BAR_ELEMENT_MAINLCD_H_LIST_NUM];

#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
S32 wgui_status_icon_bar_clock_element_id = WGUI_STATUS_ICON_BAR_INVALID_ELEMENT_ID;
#endif

#ifdef __MMI_LCD_PARTIAL_ON__
S32 wgui_status_icon_bar_partial_list_display[WGUI_STATUS_ICON_BAR_PARTIAL_ICON_LIST_NUM];
S16 wgui_status_icon_bar_partial_display_icon_number;
#endif

static void wgui_status_icon_bar_set_double_buffer_int(wgui_status_icon_bar_enum bar_id);

/****************************************************************************
 * Local variable
 ****************************************************************************/
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
/* The array of status icon and image map */
static const wgui_status_icon_bar_icon_image_map_struct wgui_status_icon_bar_icon_image_maps[MAX_STATUS_ICONS]=
{

    {STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_SIGNAL_STRENGTH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    #if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2))
    {STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_CLOSED, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    #endif
    #if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    {STATUS_ICON_SIM3_SIGNAL_STRENGTH, IMG_SI_SIM3_SIGNAL_CLOSED, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    #endif
    #if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 4))
    {STATUS_ICON_SIM4_SIGNAL_STRENGTH, IMG_SI_SIM4_SIGNAL_CLOSED, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif


    {STATUS_ICON_BATTERY_STRENGTH, IMG_SI_BATTERY_STRENGTH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#if defined(__MCARE_COMMON__)
    {STATUS_ICON_MCARE, 			IMG_MCARE_STAT_MCR, 		    GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_QQ_ONLINE, 		IMG_MCARE_STAT_QQ_ON, 		    GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_QQ_OFFLINE, 		IMG_MCARE_STAT_QQ_OFF, 	        GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_QQ_AWAYLINE, 		IMG_MCARE_STAT_QQ_AWAY, 		GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_QQ_INVISBLE, 		IMG_MCARE_STAT_QQ_INVISBLE, 	GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_QQ_HAVEMSG, 		IMG_MCARE_STAT_QQ_MESSEGE, 	    GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_CONTACT_ON, 		IMG_MCARE_STAT_CONTACT_ON, 	    GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_RESERVED1, 		IMG_MCARE_STAT_MCR, 	    GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_RESERVED2, 		IMG_MCARE_STAT_MCR, 	    GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_RESERVED3, 		IMG_MCARE_STAT_MCR, 	    GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
 #endif  

#ifdef __MMI_CALL_INDICATOR__
    {STATUS_ICON_CALL_INDICATOR, IMG_SI_CALL_INDICATOR_ACTIVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_ATV_SUPPORT__
    {STATUS_ICON_MTV_SIGNAL, IMG_SI_MTV_SIGNAL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#ifdef __MMI_MOBILE_TV_CMMB_SUPPORT__
    {STATUS_ICON_DTV_SIGNAL, IMG_SI_DTV_SIGNAL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_WLAN_FEATURES__
    {STATUS_ICON_WLAN_SIGNAL, IMG_ID_DTCNT_WLAN_STATUS_DISCONNECT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifndef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
    {STATUS_ICON_ALTERNATE_LINE_L1, IMG_SI_LINE_L1, GUI_STATUS_ICON_BAR_ICON_LINE_SWITCH_GROUP},
    {STATUS_ICON_ALTERNATE_LINE_L2, IMG_SI_LINE_L2, GUI_STATUS_ICON_BAR_ICON_LINE_SWITCH_GROUP},
#endif

#if defined(__GSM_RAT__) && (defined(__UMTS_RAT__) || defined(__OP01_3G__))
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__  
    {STATUS_ICON_3G, IMG_SI_3G, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_2G, IMG_SI_2G, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SLAVE_2G, IMG_SI_2G, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif    
#endif

#ifdef __MMI_VOIP__
    {STATUS_ICON_VOIP, IMG_SI_VOIP, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#ifdef __MMI_AUDIO_PLAYER__
    {STATUS_ICON_AUDPLY, IMG_SI_AUDPLY, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#if defined(__MMI_MEDIA_PLAYER__) || defined(__COSMOS_MUSICPLY__) || defined(__MMI_MUSIC_PLAYER_SLIM__)
    {STATUS_ICON_MEDPLY, IMG_SI_MEDPLY, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
    {STATUS_ICON_FM, IMG_SI_FM, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

    {STATUS_ICON_ROAMING, IMG_SI_ROAMING_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2))
    {STATUS_ICON_SLAVE_ROAMING, IMG_SI_SLAVE_ROAMING_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    {STATUS_ICON_SIM3_ROAMING, IMG_SI_SIM3_ROAMING_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 4))
    {STATUS_ICON_SIM4_ROAMING, IMG_SI_SIM4_ROAMING_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif 

#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 1))
    {STATUS_ICON_CALL_FORWARD, IMG_SI_CALL_FORWARD, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP},
#else

    {STATUS_ICON_CALL_DIVERT_L1L2, IMG_SI_CALL_DIVERT_L1L2, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP},
    {STATUS_ICON_CALL_DIVERT_L1, IMG_SI_CALL_DIVERT_L1, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP},
    {STATUS_ICON_CALL_DIVERT_L2, IMG_SI_CALL_DIVERT_L2, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP},
#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_SLAVE_CALLFORWARD, IMG_SLAVE_CALL_FORWARD, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SLAVE_CALLFORWARD_L1, IMG_SLAVE_CALL_FORWARD_L1, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SLAVE_CALLFORWARD_L2, IMG_SLAVE_CALL_FORWARD_L2, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#endif /* (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3)) */

    {STATUS_ICON_MUTE, IMG_SI_MUTE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

    {STATUS_ICON_INCOMING_SMS, IMG_SI_MESSAGE_UNREAD, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_SLAVE_INCOMING_SMS, IMG_SI_MESSAGE_UNREAD, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

    {STATUS_ICON_MMS_UNREAD, IMG_SI_MMS_UNREAD_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MMS_BUSY, IMG_SI_MMS_BUSY_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

#ifdef __MMI_MMS_2__
    {STATUS_ICON_MMS_RECEIVING, IMG_SI_MMS_RECEIVING, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
    
#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_MMS_UNREAD_SIM_1, IMG_SI_MMS_UNREAD_INDICATOR_SIM1, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MMS_UNREAD_SIM_2, IMG_SI_MMS_UNREAD_INDICATOR_SIM2, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MMS_BUSY_SIM_1, IMG_SI_MMS_BUSY_INDICATOR_SIM1, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MMS_BUSY_SIM_2, IMG_SI_MMS_BUSY_INDICATOR_SIM2, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    {STATUS_ICON_OUTBOX_INDICATOR, IMG_SI_OUTBOX_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__           
    {STATUS_ICON_SMS_SENDING, IMG_SI_MESSAGE_SENDING, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MESSAGE_SENDING, IMG_SI_MESSAGE_SENDING, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
	{STATUS_ICON_MESSAGE_SEND_FAIL, IMG_SI_MESSAGE_SEND_FAIL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#else
    {STATUS_ICON_SMS_SENDING, IMG_SI_COMMON_SENDING, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MESSAGE_SENDING, IMG_SI_COMMON_SENDING, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
	{STATUS_ICON_MESSAGE_SEND_FAIL, IMG_SI_COMMON_ERROR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif    
    {STATUS_ICON_MESSAGE_UNREAD, IMG_SI_MESSAGE_UNREAD, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#ifdef __MMI_COSMOS_STATUS_BAR_SLIM__    
	{STATUS_ICON_SNS_UPLOAD, IMG_SI_COMMON_SENDING, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
	{STATUS_ICON_SNS_FAIL, IMG_SI_COMMON_ERROR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#else
	{STATUS_ICON_SNS_UPLOAD, IMG_SI_SNS_UPLOAD, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
	{STATUS_ICON_SNS_FAIL, IMG_SI_SNS_FAIL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif    
    {STATUS_ICON_SNS_COMMENT, IMG_SI_SNS_COMMENT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#ifdef __MMI_COSMOS_STATUS_BAR_SLIM__               
    {STATUS_ICON_SNS_REFRESH, IMG_SI_COMMON_SYNC, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#else
	{STATUS_ICON_SNS_REFRESH, IMG_SI_SNS_REFRESH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
    {STATUS_ICON_UPGRADE, IMG_SI_UPGRADE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

//#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    {STATUS_ICON_MSG_FULL, IMG_SI_MSG_FULL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

//#else

    {STATUS_ICON_MMS_FULL, IMG_SI_MMS_FULL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

//#endif /* (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3)) */

    {STATUS_ICON_VIBRATION, IMG_SI_VIBRATE, GUI_STATUS_ICON_BAR_ICON_RING_GROUP},
    {STATUS_ICON_SILENT, IMG_SI_SILENT, GUI_STATUS_ICON_BAR_ICON_RING_GROUP},
    {STATUS_ICON_VIBRATE_AND_RING, IMG_SI_VIBRATE_AND_RING, GUI_STATUS_ICON_BAR_ICON_RING_GROUP},
    {STATUS_ICON_FLIGHT_MODE, IMG_SI_FLIGHT_MODE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

#ifdef __NFC_SUPPORT__
    {STATUS_ICON_NFC, IMG_SI_NFC, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2))
    {STATUS_ICON_EDGE, IMG_SI_EDGE_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_GPRS_SERVICE, IMG_SI_GPRS_SERVICE_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__               
    {STATUS_ICON_EDGEC, IMG_SI_EDGEC_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
    {STATUS_ICON_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
#endif    
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    {STATUS_ICON_EDGE_UPLINK, IMG_SI_EDGE_UPLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_EDGE_DOWNLINK, IMG_SI_EDGE_DOWNLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_EDGE_UPDOWNLINK, IMG_SI_EDGE_UPDOWNLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_GPRS_UPLINK, IMG_SI_GPRS_UPLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_GPRS_DOWNLINK, IMG_SI_GPRS_DOWNLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_GPRS_UPDOWNLINK, IMG_SI_GPRS_UPDOWNLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif
    {STATUS_ICON_SLAVE_EDGE, IMG_SI_EDGE_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_GPRS_SERVICE, IMG_SI_GPRS_SERVICE_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__               
    {STATUS_ICON_SLAVE_EDGEC, IMG_SI_EDGEC_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
    {STATUS_ICON_SLAVE_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
#endif    
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    {STATUS_ICON_SLAVE_EDGE_UPLINK, IMG_SI_EDGE_UPLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_EDGE_DOWNLINK, IMG_SI_EDGE_DOWNLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_EDGE_UPDOWNLINK, IMG_SI_EDGE_UPDOWNLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_GPRS_UPLINK, IMG_SI_GPRS_UPLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_GPRS_DOWNLINK, IMG_SI_GPRS_DOWNLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_GPRS_UPDOWNLINK, IMG_SI_GPRS_UPDOWNLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif
#else
    {STATUS_ICON_EDGE, IMG_SI_EDGE, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_GPRS_SERVICE, IMG_SI_GPRS_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__               
    {STATUS_ICON_EDGEC, IMG_SI_EDGEC, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
    {STATUS_ICON_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
#endif    
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    {STATUS_ICON_EDGE_UPLINK, IMG_SI_EDGE_UPLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_EDGE_DOWNLINK, IMG_SI_EDGE_DOWNLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_EDGE_UPDOWNLINK, IMG_SI_EDGE_UPDOWNLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_GPRS_UPLINK, IMG_SI_GPRS_UPLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_GPRS_DOWNLINK, IMG_SI_GPRS_DOWNLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_GPRS_UPDOWNLINK, IMG_SI_GPRS_UPDOWNLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif
#endif

#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    {STATUS_ICON_SIM3_EDGE, IMG_SI_EDGE_SIM3, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM3_GPRS_SERVICE, IMG_SI_GPRS_SERVICE_SIM3, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__               
    {STATUS_ICON_SIM3_EDGEC, IMG_SI_EDGEC_SIM3, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM3_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM3, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif    
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    {STATUS_ICON_SIM3_EDGE_UPLINK, IMG_SI_EDGE_UPLINK_SIM3, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM3_EDGE_DOWNLINK, IMG_SI_EDGE_DOWNLINK_SIM3, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM3_EDGE_UPDOWNLINK, IMG_SI_EDGE_UPDOWNLINK_SIM3, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM3_GPRS_UPLINK, IMG_SI_GPRS_UPLINK_SIM3, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM3_GPRS_DOWNLINK, IMG_SI_GPRS_DOWNLINK_SIM3, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM3_GPRS_UPDOWNLINK, IMG_SI_GPRS_UPDOWNLINK_SIM3, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif
#endif

#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 4))
    {STATUS_ICON_SIM4_EDGE, IMG_SI_EDGE_SIM4, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM4_GPRS_SERVICE, IMG_SI_GPRS_SERVICE_SIM4, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__               
    {STATUS_ICON_SIM4_EDGEC, IMG_SI_EDGEC_SIM4, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM4_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM4, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif    
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    {STATUS_ICON_SIM4_EDGE_UPLINK, IMG_SI_EDGE_UPLINK_SIM4, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM4_EDGE_DOWNLINK, IMG_SI_EDGE_DOWNLINK_SIM4, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM4_EDGE_UPDOWNLINK, IMG_SI_EDGE_UPDOWNLINK_SIM4, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM4_GPRS_UPLINK, IMG_SI_GPRS_UPLINK_SIM4, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM4_GPRS_DOWNLINK, IMG_SI_GPRS_DOWNLINK_SIM4, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM4_GPRS_UPDOWNLINK, IMG_SI_GPRS_UPDOWNLINK_SIM4, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif
#endif

#ifdef __OP01_3G__
    {STATUS_ICON_TD_NO_PDP, IMG_SI_TDC, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
    {STATUS_ICON_TD_PDP_ACTIVATED, IMG_SI_TD, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    {STATUS_ICON_TD_UPLINK, IMG_SI_TD_UPLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_TD_DOWNLINK, IMG_SI_TD_DOWNLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_TD_UPDOWNLINK, IMG_SI_TD_UPDOWNLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif
#endif /* __OP01_3G__ */

#if ((defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))) && (MMI_MAX_SIM_NUM == 1)
    {STATUS_ICON_HSPA_NO_PDP, IMG_SI_HSPA_NO_PDP, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_HSPA_PDP_ACTIVATED, IMG_SI_HSPA_PDP_ACTIVATED, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    {STATUS_ICON_HSPA_UPLINK, IMG_SI_HSPA_UPLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_HSPA_DOWNLINK, IMG_SI_HSPA_DOWNLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_HSPA_UPDOWNLINK, IMG_SI_HSPA_UPDOWNLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif
#endif

#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2))    
#if (defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))
    {STATUS_ICON_HSPA_NO_PDP, IMG_SI_HSPA_NO_PDP_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_HSPA_PDP_ACTIVATED, IMG_SI_HSPA_PDP_ACTIVATED_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    {STATUS_ICON_HSPA_UPLINK, IMG_SI_HSPA_UPLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_HSPA_DOWNLINK, IMG_SI_HSPA_DOWNLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_HSPA_UPDOWNLINK, IMG_SI_HSPA_UPDOWNLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif
    {STATUS_ICON_SLAVE_HSPA_NO_PDP, IMG_SI_HSPA_NO_PDP_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_HSPA_PDP_ACTIVATED, IMG_SI_HSPA_PDP_ACTIVATED_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    {STATUS_ICON_SLAVE_HSPA_UPLINK, IMG_SI_HSPA_UPLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_HSPA_DOWNLINK, IMG_SI_HSPA_DOWNLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_HSPA_UPDOWNLINK, IMG_SI_HSPA_UPDOWNLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif
#endif
#endif



#ifndef __MMI_DUAL_SIM_MASTER__
    
    {STATUS_ICON_CSD, IMG_SI_CSD, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    
    #if (defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))
    
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__  
    {STATUS_ICON_35G, IMG_SI_35G, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#endif
        
#else
    {STATUS_ICON_CSD, IMG_SI_CSD_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#if (defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__  
    {STATUS_ICON_35G, IMG_SI_35G_SIM1, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#endif

    {STATUS_ICON_SLAVE_CSD, IMG_SI_CSD_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    
#if (defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))
    
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__  
    {STATUS_ICON_SLAVE_35G, IMG_SI_35G_SIM2, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#endif 

#endif

#if defined(OBIGO_Q05A) && defined(WAP_SUPPORT)
    {STATUS_ICON_SECURITY, IMG_SI_SECURITY, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

    {STATUS_ICON_WIFI_TETHERING, IMG_SI_WIFI_TETHERING, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_EARPHONE_INDICATOR, IMG_SI_EARPHONE_INDICATOR, GUI_STATUS_ICON_BAR_ICON_EARPHONE_GROUP},
    {STATUS_ICON_BT_EARPHONE_INDICATOR, IMG_SI_EARPHONE_INDICATOR, GUI_STATUS_ICON_BAR_ICON_EARPHONE_GROUP},
    {STATUS_ICON_USB, IMG_SI_USB, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SPEAKER_CALL, IMG_SI_SPEAKER_CALL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SPEAKER_MUTE, IMG_SI_SPEAKER_MUTE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_ALARM, IMG_SI_ALARM_ACTIVATED, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_STOPWATCH, IMG_SI_STOPWATCH_ACTIVATED, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_TIMER, IMG_SI_TIMER_ACTIVATED, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_VOICE_RECORD, IMG_SI_VOICE_RECORD, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_KEYPAD_LOCK, IMG_SI_KEYPAD_LOCK, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#if defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__)
    {STATUS_ICON_CONTACTS_BACKUP, IMG_SI_CONTACTS_BACKUP, GUI_STATUS_ICON_BAR_ICON_CONTACT_GROUP},
    {STATUS_ICON_CONTACTS_RESTORE, IMG_SI_CONTACTS_RESTORE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
    {STATUS_ICON_DOWNLOADING, IMG_SI_DOWNLOADING, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#ifdef __MMI_COSMOS_STATUS_BAR_SLIM__    
    {STATUS_ICON_DOWNLOAD_FAILED, IMG_SI_COMMON_ERROR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#else
	{STATUS_ICON_DOWNLOAD_FAILED, IMG_SI_DOWNLOAD_ERROR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif    
    {STATUS_ICON_DOWNLOAD_COMPLETED, IMG_SI_DOWNLOAD_COMPLETE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_DOWNLOAD_MEMORY_FAIL, IMG_SI_DOWNLOAD_FULL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

#ifndef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_MISSED_CALL, IMG_SI_MISSED_CALL_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#else
    {STATUS_ICON_MISSED_CALL, IMG_SI_CARD1MISSED_CALL_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_CARD2MISSED_CALL, IMG_SI_CARD2MISSED_CALL_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_EMAIL__
    {STATUS_ICON_UNREAD_EMAIL, IMG_SI_UNREAD_EMAIL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#ifdef __MMI_COSMOS_STATUS_BAR_SLIM__     
    {STATUS_ICON_EMAIL_SEND, IMG_SI_COMMON_SENDING, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},      
    {STATUS_ICON_EMAIL_SEND_ERROR, IMG_SI_COMMON_ERROR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_EMAIL_REF, IMG_SI_COMMON_SYNC, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},       
    {STATUS_ICON_EMAIL_FAIL, IMG_SI_COMMON_ERROR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#else
	{STATUS_ICON_EMAIL_SEND, IMG_SI_EMAIL_SENDING, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},		
	{STATUS_ICON_EMAIL_SEND_ERROR, IMG_SI_EMAIL_SEND_ERROR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
	{STATUS_ICON_EMAIL_REF, IMG_SI_EMAIL_REFRESHING, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},	   
	{STATUS_ICON_EMAIL_FAIL, IMG_SI_EMAIL_FAIL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif  
  
#ifdef __MMI_COSMOS_STATUS_BAR_SLIM__       
    {STATUS_ICON_EMAIL_FULL, IMG_SI_COMMON_ERROR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#else
	{STATUS_ICON_EMAIL_FULL, IMG_SI_EMAIL_FULL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif  /* __MMI_COSMOS_STATUS_BAR_SLIM__ */
  
#endif /* __MMI_EMAIL__ */ 
  
#ifdef __MMI_COSMOS_STATUS_BAR_SLIM__    
    {STATUS_ICON_PUSHED_OBJ, IMG_SI_COMMON_NEW, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#else
	  {STATUS_ICON_PUSHED_OBJ, IMG_SI_PUSHED_OBJ, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif  

    {STATUS_ICON_PUSH_CONNECT, IMG_SI_PUSH_CONNECT, GUI_STATUS_ICON_BAR_ICON_PUSH_GROUP},
    {STATUS_ICON_PUSH_RECEIVE, IMG_SI_PUSH_RECEIVE, GUI_STATUS_ICON_BAR_ICON_PUSH_GROUP},
    {STATUS_ICON_PUSH_FAIL, IMG_SI_PUSH_FAIL, GUI_STATUS_ICON_BAR_ICON_PUSH_GROUP},
#ifdef __MMI_COSMOS_STATUS_BAR_SLIM__ 
    {STATUS_ICON_UNREAD_VOICE,IMG_SI_COMMON_NEW, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_FAX, IMG_SI_COMMON_NEW, GUI_STATUS_ICON_BAR_ICON_NO_GROUP}, 
    {STATUS_ICON_UNREAD_SIM_EMAIL, IMG_SI_COMMON_NEW, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_NET, IMG_SI_COMMON_NEW, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO, IMG_SI_COMMON_NEW, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#else
	{STATUS_ICON_UNREAD_VOICE,IMG_SI_UNREAD_VOICE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
	{STATUS_ICON_UNREAD_FAX, IMG_SI_UNREAD_FAX, GUI_STATUS_ICON_BAR_ICON_NO_GROUP}, 
	{STATUS_ICON_UNREAD_SIM_EMAIL, IMG_SI_UNREAD_SIM_EMAIL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
	{STATUS_ICON_UNREAD_NET, IMG_SI_UNREAD_NET, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
	{STATUS_ICON_UNREAD_VIDEO, IMG_SI_UNREAD_VIDEO, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

#endif

#ifdef __MMI_AUTO_ANSWER_MACHINE__
    {STATUS_ICON_AUTOAM_REC, IMG_SI_AUTOAM_REC, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_AUTOAM_UNREAD, IMG_SI_AUTOAM_UNREAD, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_AUTOAM_ON, IMG_SI_AUTOAM_ON, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_IMPS__
/* under construction !*/
/* under construction !*/
#endif

    {STATUS_ICON_WAP1, IMG_SI_WAP1, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_WAP2, IMG_SI_WAP2, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_WAP, IMG_SI_WAP, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

    {STATUS_ICON_BT, IMG_SI_BT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_BT_CON, IMG_SI_BT_CON, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__       
    {STATUS_ICON_BT_TRANS, IMG_SI_BT_TRANSFERRING, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif    

    {STATUS_ICON_IR, IMG_SI_IR_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

    {STATUS_ICON_STOP_WATCH, IMG_SI_STOPWATCH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_NETWORK_CIPHER_GSM, IMG_SI_MASTER_NETWORK_CIPHER_GSM, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SLAVE_NETWORK_CIPHER_GSM, IMG_SI_SLAVE_NETWORK_CIPHER_GSM, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#else
    {STATUS_ICON_NETWORK_CIPHER_GSM, IMG_SI_NETWORK_CIPHER_GSM, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

    {STATUS_ICON_NETWORK_CIPHER_GPRS, IMG_SI_NETWORK_CIPHER_GPRS, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

#if defined(__J2ME__) && defined(J2ME_SUPPORT_BACKGROUND)
    {STATUS_ICON_JAVA_BG_VM, IMG_SI_JAVA_BG_VM, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_JAVA_BG_VM_AUDIO, IMG_SI_JAVA_BG_VM_AUDIO, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_JAVA, IMG_SI_JAVA, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#ifdef __MMI_COSMOS_STATUS_BAR_SLIM__    
    {STATUS_ICON_JAVA_AUDIO, IMG_SI_JAVA, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#else
	{STATUS_ICON_JAVA_AUDIO, IMG_SI_JAVA_AUDIO, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif    
#endif
#ifdef __J2ME__
#ifdef __MMI_COSMOS_STATUS_BAR_SLIM__
    {STATUS_ICON_JAVA_PUSH, IMG_SI_COMMON_NEW, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#else
	{STATUS_ICON_JAVA_PUSH, IMG_SI_JAVA_PUSH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif    
#endif

#ifdef __MMI_BG_SOUND_EFFECT__
    {STATUS_ICON_BG_SOUND, IMG_SI_BGSND, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_AUDIO_REVERB_EFFECT__
    {STATUS_ICON_REVERB_SOUND, IMG_SI_REVERBSND, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    {STATUS_ICON_AUD_SURROUND, IMG_SI_SURROUNDSND, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __HOMEZONE_SUPPORT__ 
    {STATUS_ICON_HOMEZONE, IMG_SI_HZONE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_SLAVE_HOMEZONE, IMG_SI_HZONE_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
    {STATUS_ICON_CITYZONE, IMG_SI_CZONE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif /* __HOMEZONE_SUPPORT__  */

#ifdef __CTM_SUPPORT__
    {STATUS_ICON_TTY_INDICATOR, IMG_SI_TTY_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_PICT_BRIDGE_SUPPORT__
    {STATUS_ICON_PRINT, IMG_SI_PRINT, GUI_STATUS_ICON_BAR_ICON_PRINT_GROUP},
    {STATUS_ICON_PRINT_FAIL, IMG_SI_PRINT_FAIL, GUI_STATUS_ICON_BAR_ICON_PRINT_GROUP},
#endif

#if defined(__AGPS_SUPPORT__) && defined(__SUPL_SUPPORT__)
    {STATUS_ICON_AGPS_STATE, IMG_SI_AGPS_STATE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#ifdef __MMI_COSMOS_STATUS_BAR_SLIM__  
    {STATUS_ICON_SYNCML, IMG_SI_COMMON_SYNC, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},   
    {STATUS_ICON_SYNCML_ERROR, IMG_SI_COMMON_ERROR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#else
	{STATUS_ICON_SYNCML, IMG_SI_SYNCML_PROCESS, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},   
	{STATUS_ICON_SYNCML_ERROR, IMG_SI_SYNCML_ERROR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif    

    {STATUS_ICON_PROVMSG_STATE, IMG_SI_PROVMSG, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

#if defined(__QQIM_SUPPORT__)
    {STATUS_ICON_QQIM_AWAY, IMG_SI_QQIM_AWAY, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_QQIM_INVISIBLE, IMG_SI_QQIM_INVISIBLE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_QQIM_MSG, IMG_SI_QQIM_MSG, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_QQIM_OFFLINE, IMG_SI_QQIM_OFFLINE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_QQIM_ONLINE, IMG_SI_QQIM_ONLINE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

    {STATUS_ICON_MRE_DEFAULT, IMG_SI_MRE_DEFAULT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MRE_FETION, IMG_SI_MRE_FETION, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MRE_MSN, IMG_SI_MRE_MSN, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MRE_PUSHMAIL, IMG_SI_MRE_PUSHMAIL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MRE_QQ, IMG_SI_MRE_QQ, GUI_STATUS_ICON_BAR_ICON_NO_GROUP}, 
    {STATUS_ICON_MRE_1, IMG_SI_MRE_DEFAULT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MRE_2, IMG_SI_MRE_DEFAULT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MRE_3, IMG_SI_MRE_DEFAULT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MRE_4, IMG_SI_MRE_DEFAULT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MRE_5, IMG_SI_MRE_DEFAULT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MRE_6, IMG_SI_MRE_DEFAULT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MRE_PUSH, IMG_SI_MRE_PUSH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

    {STATUS_ICON_LEFT_HIDE,IMG_SI_LEFT_HIDE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

    /* Sublcd start */
#ifdef __MMI_SUBLCD__
    {STATUS_ICON_SUBLCD_SIGNAL_STRENGTH, IMG_SLSI_SIGNAL_STRENGTH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SUBLCD_BATTERY_STRENGTH, IMG_SLSI_BATTERY_STRENGTH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_SUBLCD_SLAVE_SIGNAL_STRENGTH, IMG_SLSI_SLAVE_SIGNAL_STRENGTH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    {STATUS_ICON_SUBLCD_SMS, IMG_SLSI_SMS_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_SUBLCD_SLAVE_SMS, IMG_SLSI_SLAVE_SMS_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    {STATUS_ICON_SUBLCD_RING, IMG_SLSI_RING, GUI_STATUS_ICON_BAR_ICON_SUBLCD_RING_GROUP},
    {STATUS_ICON_SUBLCD_VIBRATE, IMG_SLSI_VIBRATE, GUI_STATUS_ICON_BAR_ICON_SUBLCD_RING_GROUP},
    {STATUS_ICON_SUBLCD_VIBRATE_AND_RING, IMG_SLSI_VIBRATE_AND_RING, GUI_STATUS_ICON_BAR_ICON_SUBLCD_RING_GROUP},
    {STATUS_ICON_SUBLCD_VIBRATE_THEN_RING, IMG_SLSI_VIBRATE_THEN_RING, GUI_STATUS_ICON_BAR_ICON_SUBLCD_RING_GROUP},
    {STATUS_ICON_SUBLCD_SILENT, IMG_SLSI_SILENT, GUI_STATUS_ICON_BAR_ICON_SUBLCD_RING_GROUP},
    {STATUS_ICON_SUBLCD_ALARM, IMG_SLSI_ALARM, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SUBLCD_MISSED_CALL, IMG_SLSI_MISSED_CALL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP}
#ifdef __MMI_DUAL_SIM_MASTER__
    ,
    {STATUS_ICON_SUBLCD_SLAVE_MISSED_CALL, IMG_SLSI_SLAVE_MISSED_CALL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP}
#endif  /* __MMI_DUAL_SIM_MASTER__ */
#endif
};
#else /* __MMI_STATUS_ICONBAR_COSMOS_STYLE__ */

/* The array of status icon and image map */
static const wgui_status_icon_bar_icon_image_map_struct wgui_status_icon_bar_icon_image_maps[MAX_STATUS_ICONS]=
{
#if (defined(__MMI_DUAL_SIM_MASTER__) || (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2)))
    {STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_CLOSED, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#else
    {STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_SIGNAL_STRENGTH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

    {STATUS_ICON_BATTERY_STRENGTH, IMG_SI_BATTERY_STRENGTH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

#if (defined(__MMI_DUAL_SIM_MASTER__) || (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2)))
    {STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_CLOSED, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    {STATUS_ICON_SIM3_SIGNAL_STRENGTH, IMG_SI_SIM3_SIGNAL_CLOSED, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 4))
    {STATUS_ICON_SIM4_SIGNAL_STRENGTH, IMG_SI_SIM4_SIGNAL_CLOSED, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_CALL_INDICATOR__
    {STATUS_ICON_CALL_INDICATOR, IMG_SI_CALL_INDICATOR_ACTIVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_ATV_SUPPORT__
    {STATUS_ICON_MTV_SIGNAL, IMG_SI_MTV_SIGNAL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#ifdef __MMI_MOBILE_TV_CMMB_SUPPORT__
    {STATUS_ICON_DTV_SIGNAL, IMG_SI_DTV_SIGNAL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_WLAN_FEATURES__
    {STATUS_ICON_WLAN_SIGNAL, IMG_ID_DTCNT_WLAN_STATUS_DISCONNECT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifndef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
#if !defined(__KJX_FUN__)	//xb add 2017-08-07 不再显示通话线路
    {STATUS_ICON_ALTERNATE_LINE_L1, IMG_SI_LINE_L1, GUI_STATUS_ICON_BAR_ICON_LINE_SWITCH_GROUP},
    {STATUS_ICON_ALTERNATE_LINE_L2, IMG_SI_LINE_L2, GUI_STATUS_ICON_BAR_ICON_LINE_SWITCH_GROUP},
#endif
#endif

#if defined(__GSM_RAT__) && (defined(__UMTS_RAT__) || defined(__OP01_3G__))
    {STATUS_ICON_3G, IMG_SI_3G, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_2G, IMG_SI_2G, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SLAVE_2G, IMG_SI_2G, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_VOIP__
    {STATUS_ICON_VOIP, IMG_SI_VOIP, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#ifdef __MMI_AUDIO_PLAYER__
    {STATUS_ICON_AUDPLY, IMG_SI_AUDPLY, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#if defined(__MMI_MEDIA_PLAYER__) || defined(__COSMOS_MUSICPLY__)
    {STATUS_ICON_MEDPLY, IMG_SI_MEDPLY, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#if (defined(__MMI_DUAL_SIM_MASTER__) || (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2)))
    #ifdef __MMI_NW_INFO_DN_STATUS_SLIM__ 
    {STATUS_ICON_ROAMING, IMG_SI_ROAMING_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    #else
    {STATUS_ICON_ROAMING, IMG_SI_ROAMING_INDICATOR_SIM1, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    #endif    
#else
#if !defined(__KJX_FUN__)	//xb add 2017-08-07 不再显示漫游状态图标
    {STATUS_ICON_ROAMING, IMG_SI_ROAMING_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#endif
#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    {STATUS_ICON_SLAVE_ROAMING, IMG_SI_ROAMING_INDICATOR_SIM2, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SIM3_ROAMING, IMG_SI_ROAMING_INDICATOR_SIM3, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SIM4_ROAMING, IMG_SI_ROAMING_INDICATOR_SIM4, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#else
#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_SLAVE_ROAMING, IMG_SI_ROAMING_INDICATOR_SIM2, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#endif
#endif /* __MMI_NW_INFO_DN_STATUS_SLIM__ */

#if !defined(__KJX_FUN__)	//xb add 2017-08-07 不再显示通话线路
    {STATUS_ICON_CALL_DIVERT_L1L2, IMG_SI_CALL_DIVERT_L1L2, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP},
    {STATUS_ICON_CALL_DIVERT_L1, IMG_SI_CALL_DIVERT_L1, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP},
    {STATUS_ICON_CALL_DIVERT_L2, IMG_SI_CALL_DIVERT_L2, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP},
#endif
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    {STATUS_ICON_SLAVE_CALLFORWARD, IMG_SLAVE_CALL_FORWARD, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP},
    {STATUS_ICON_SLAVE_CALLFORWARD_L1, IMG_SI_CALL_DIVERT_L1, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP},
    {STATUS_ICON_SLAVE_CALLFORWARD_L2, IMG_SI_CALL_DIVERT_L2, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP},
    {STATUS_ICON_SIM3_CALL_DIVERT, IMG_SI_CALL_DIVERT_L1L2, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP},
    {STATUS_ICON_SIM3_CALL_DIVERT_L1, IMG_SI_CALL_DIVERT_L1, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP},
    {STATUS_ICON_SIM3_CALL_DIVERT_L2, IMG_SLAVE_CALL_FORWARD_L2, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP},
    {STATUS_ICON_SIM4_CALL_DIVERT, IMG_SI_CALL_DIVERT_L1L2, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP},
    {STATUS_ICON_SIM4_CALL_DIVERT_L1, IMG_SI_CALL_DIVERT_L1, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP},
    {STATUS_ICON_SIM4_CALL_DIVERT_L2, IMG_SI_CALL_DIVERT_L2, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP},
#else
#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_SLAVE_CALLFORWARD, IMG_SLAVE_CALL_FORWARD, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP},
    {STATUS_ICON_SLAVE_CALLFORWARD_L1, IMG_SI_CALL_DIVERT_L1, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP},
    {STATUS_ICON_SLAVE_CALLFORWARD_L2, IMG_SI_CALL_DIVERT_L2, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP},
#endif
#endif

    {STATUS_ICON_MUTE, IMG_SI_MUTE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

    {STATUS_ICON_INCOMING_SMS, IMG_SI_SMS_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_SLAVE_INCOMING_SMS, IMG_SI_SMS_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2))
    {STATUS_ICON_FULL_SMS, IMG_SI_MASTER_FULL_SMS_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#else /* 2 */
    {STATUS_ICON_FULL_SMS, IMG_SI_FULL_SMS_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif /* 2 */
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2))
    {STATUS_ICON_SLAVE_FULL_SMS, IMG_SI_SLAVE_FULL_SMS_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    {STATUS_ICON_SIM3_FULL_SMS, IMG_SI_SIM3_FULL_SMS_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SIM4_FULL_SMS, IMG_SI_SIM4_FULL_SMS_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif /* 3 */
#endif /* 2 */

    #ifdef __MMI_MMS_2__
    {STATUS_ICON_MMS_UNREAD, IMG_SI_MMS_UNREAD_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MMS_BUSY, IMG_SI_MMS_BUSY_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    #endif
    
#ifdef __MMI_DUAL_SIM_MASTER__
#ifndef __MMI_STATUS_ICON_BAR_SLIM__ 
    {STATUS_ICON_MMS_UNREAD_SIM_1, IMG_SI_MMS_UNREAD_INDICATOR_SIM1, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MMS_UNREAD_SIM_2, IMG_SI_MMS_UNREAD_INDICATOR_SIM2, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif   
#endif

#ifndef __MMI_UM_SLIM__
    {STATUS_ICON_OUTBOX_INDICATOR, IMG_SI_OUTBOX_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

    {STATUS_ICON_SMS_SENDING, IMG_SI_SMS_SENDING, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

    {STATUS_ICON_SNS_UPLOAD, IMG_SI_SNS_UPLOAD, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SNS_FAIL, IMG_SI_SNS_FAIL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SNS_COMMENT, IMG_SI_SNS_COMMENT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SNS_REFRESH, IMG_SI_SNS_REFRESH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SNS_MESSAGE, IMG_SI_SNS_MESSAGE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SNS_FRIEND, IMG_SI_SNS_FRIEND, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UPGRADE, IMG_SI_UPGRADE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

#if !defined(__KJX_FUN__)	//xb add 2017-08-07 不再显示情景模式状态图标
    {STATUS_ICON_VIBRATION, IMG_SI_VIBRATE, GUI_STATUS_ICON_BAR_ICON_RING_GROUP},
    {STATUS_ICON_SILENT, IMG_SI_SILENT, GUI_STATUS_ICON_BAR_ICON_RING_GROUP},
    {STATUS_ICON_RING, IMG_SI_RING, GUI_STATUS_ICON_BAR_ICON_RING_GROUP},
    {STATUS_ICON_VIBRATE_AND_RING, IMG_SI_VIBRATE_AND_RING, GUI_STATUS_ICON_BAR_ICON_RING_GROUP},
    {STATUS_ICON_VIBRATE_THEN_RING, IMG_SI_VIBRATE_THEN_RING, GUI_STATUS_ICON_BAR_ICON_RING_GROUP},
#endif

#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    {STATUS_ICON_CSD, IMG_SI_CSD_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#ifndef __MMI_STATUS_ICON_BAR_SLIM__
    {STATUS_ICON_EDGE, IMG_SI_EDGE_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_GPRS_SERVICE, IMG_SI_GPRS_SERVICE_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#else
	{STATUS_ICON_EDGE, IMG_SI_EDGE, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
	{STATUS_ICON_GPRS_SERVICE, IMG_SI_GPRS_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif
#if (defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))
    {STATUS_ICON_HSPA_NO_PDP, IMG_SI_HSPA_NO_PDP_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_HSPA_PDP_ACTIVATED, IMG_SI_HSPA_PDP_ACTIVATED_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_35G, IMG_SI_35G_SIM1, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#ifndef __MMI_STATUS_ICON_BAR_SLIM__
    {STATUS_ICON_EDGEC, IMG_SI_EDGEC_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
	{STATUS_ICON_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
#else
    {STATUS_ICON_EDGEC, IMG_SI_EDGEC, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
	{STATUS_ICON_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
#endif
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    {STATUS_ICON_EDGE_UPLINK, IMG_SI_EDGE_UPLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_EDGE_DOWNLINK, IMG_SI_EDGE_DOWNLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_EDGE_UPDOWNLINK, IMG_SI_EDGE_UPDOWNLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_GPRS_UPLINK, IMG_SI_GPRS_UPLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_GPRS_DOWNLINK, IMG_SI_GPRS_DOWNLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_GPRS_UPDOWNLINK, IMG_SI_GPRS_UPDOWNLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#if (defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))
    {STATUS_ICON_HSPA_UPLINK, IMG_SI_HSPA_UPLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_HSPA_DOWNLINK, IMG_SI_HSPA_DOWNLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_HSPA_UPDOWNLINK, IMG_SI_HSPA_UPDOWNLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif
#endif
    {STATUS_ICON_SLAVE_CSD, IMG_SI_CSD_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__    
    {STATUS_ICON_SLAVE_EDGE, IMG_SI_EDGE_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_GPRS_SERVICE, IMG_SI_GPRS_SERVICE_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif    
#if (defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))
    {STATUS_ICON_SLAVE_HSPA_NO_PDP, IMG_SI_HSPA_NO_PDP_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_HSPA_PDP_ACTIVATED, IMG_SI_HSPA_PDP_ACTIVATED_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_35G, IMG_SI_35G_SIM2, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif 
#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__
    {STATUS_ICON_SLAVE_EDGEC, IMG_SI_EDGEC_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
    {STATUS_ICON_SLAVE_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
#endif

#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    {STATUS_ICON_SLAVE_EDGE_UPLINK, IMG_SI_EDGE_UPLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_EDGE_DOWNLINK, IMG_SI_EDGE_DOWNLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_EDGE_UPDOWNLINK, IMG_SI_EDGE_UPDOWNLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_GPRS_UPLINK, IMG_SI_GPRS_UPLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_GPRS_DOWNLINK, IMG_SI_GPRS_DOWNLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_GPRS_UPDOWNLINK, IMG_SI_GPRS_UPDOWNLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#if (defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))
    {STATUS_ICON_SLAVE_HSPA_UPLINK, IMG_SI_HSPA_UPLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_HSPA_DOWNLINK, IMG_SI_HSPA_DOWNLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_HSPA_UPDOWNLINK, IMG_SI_HSPA_UPDOWNLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif
#endif
    {STATUS_ICON_SIM3_CSD, IMG_SI_CSD_SIM3, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__    
    {STATUS_ICON_SIM3_EDGE, IMG_SI_EDGE_SIM3, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM3_GPRS_SERVICE, IMG_SI_GPRS_SERVICE_SIM3, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif    
#if (defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))
    {STATUS_ICON_SIM3_HSPA_NO_PDP, IMG_SI_HSPA_NO_PDP_SIM3, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM3_HSPA_PDP_ACTIVATED, IMG_SI_HSPA_PDP_ACTIVATED_SIM3, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM3_35G, IMG_SI_35G_SIM3, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__
    {STATUS_ICON_SIM3_EDGEC, IMG_SI_EDGEC_SIM3, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},  
    {STATUS_ICON_SIM3_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM3, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
#endif  

#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    {STATUS_ICON_SIM3_EDGE_UPLINK, IMG_SI_EDGE_UPLINK_SIM3, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM3_EDGE_DOWNLINK, IMG_SI_EDGE_DOWNLINK_SIM3, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM3_EDGE_UPDOWNLINK, IMG_SI_EDGE_UPDOWNLINK_SIM3, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM3_GPRS_UPLINK, IMG_SI_GPRS_UPLINK_SIM3, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM3_GPRS_DOWNLINK, IMG_SI_GPRS_DOWNLINK_SIM3, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM3_GPRS_UPDOWNLINK, IMG_SI_GPRS_UPDOWNLINK_SIM3, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif
    {STATUS_ICON_SIM4_CSD, IMG_SI_CSD_SIM4, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__    
    {STATUS_ICON_SIM4_EDGE, IMG_SI_EDGE_SIM4, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM4_GPRS_SERVICE, IMG_SI_GPRS_SERVICE_SIM4, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif    
#if (defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))
    {STATUS_ICON_SIM4_HSPA_NO_PDP, IMG_SI_HSPA_NO_PDP_SIM4, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM4_HSPA_PDP_ACTIVATED, IMG_SI_HSPA_PDP_ACTIVATED_SIM4, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM4_35G, IMG_SI_35G_SIM4, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__
    {STATUS_ICON_SIM4_EDGEC, IMG_SI_EDGEC_SIM4, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
    {STATUS_ICON_SIM4_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM4, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
#endif    

#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    {STATUS_ICON_SIM4_EDGE_UPLINK, IMG_SI_EDGE_UPLINK_SIM4, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM4_EDGE_DOWNLINK, IMG_SI_EDGE_DOWNLINK_SIM4, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM4_EDGE_UPDOWNLINK, IMG_SI_EDGE_UPDOWNLINK_SIM4, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM4_GPRS_UPLINK, IMG_SI_GPRS_UPLINK_SIM4, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM4_GPRS_DOWNLINK, IMG_SI_GPRS_DOWNLINK_SIM4, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SIM4_GPRS_UPDOWNLINK, IMG_SI_GPRS_UPDOWNLINK_SIM4, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif
#else /* (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3)) */
#ifndef __MMI_DUAL_SIM_MASTER__
#if !defined(__KJX_FUN__)	//xb add 2017-07-19 GPRS自主显示
    {STATUS_ICON_CSD, IMG_SI_CSD, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_EDGE, IMG_SI_EDGE, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_GPRS_SERVICE, IMG_SI_GPRS_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif
#ifdef __OP01_3G__
    {STATUS_ICON_TD_NO_PDP, IMG_SI_TDC, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_TD_PDP_ACTIVATED, IMG_SI_TD, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif
#if (defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))
    {STATUS_ICON_HSPA_NO_PDP, IMG_SI_HSPA_NO_PDP, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_HSPA_PDP_ACTIVATED, IMG_SI_HSPA_PDP_ACTIVATED, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_35G, IMG_SI_35G, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#if !defined(__KJX_FUN__)	//xb add 2017-07-20 GPRS自主显示
    {STATUS_ICON_EDGEC, IMG_SI_EDGEC, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
    {STATUS_ICON_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
#endif
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    {STATUS_ICON_EDGE_UPLINK, IMG_SI_EDGE_UPLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_EDGE_DOWNLINK, IMG_SI_EDGE_DOWNLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_EDGE_UPDOWNLINK, IMG_SI_EDGE_UPDOWNLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_GPRS_UPLINK, IMG_SI_GPRS_UPLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_GPRS_DOWNLINK, IMG_SI_GPRS_DOWNLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_GPRS_UPDOWNLINK, IMG_SI_GPRS_UPDOWNLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#ifdef __OP01_3G__
    {STATUS_ICON_TD_UPLINK, IMG_SI_TD_UPLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_TD_DOWNLINK, IMG_SI_TD_DOWNLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_TD_UPDOWNLINK, IMG_SI_TD_UPDOWNLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif
#if (defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))
    {STATUS_ICON_HSPA_UPLINK, IMG_SI_HSPA_UPLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_HSPA_DOWNLINK, IMG_SI_HSPA_DOWNLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_HSPA_UPDOWNLINK, IMG_SI_HSPA_UPDOWNLINK, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif
#endif
#else
    {STATUS_ICON_CSD, IMG_SI_CSD_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    #ifndef __MMI_NW_INFO_DN_STATUS_SLIM__ 
    {STATUS_ICON_EDGE, IMG_SI_EDGE_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_GPRS_SERVICE, IMG_SI_GPRS_SERVICE_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    #else
    {STATUS_ICON_EDGE, IMG_SI_EDGE, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_GPRS_SERVICE, IMG_SI_GPRS_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    #endif
#ifdef __OP01_3G__
    {STATUS_ICON_TD_NO_PDP, IMG_SI_TDC_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_TD_PDP_ACTIVATED, IMG_SI_TD_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif
#if (defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))
    {STATUS_ICON_HSPA_NO_PDP, IMG_SI_HSPA_NO_PDP_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_HSPA_PDP_ACTIVATED, IMG_SI_HSPA_PDP_ACTIVATED_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_35G, IMG_SI_35G_SIM1, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__ 
    {STATUS_ICON_EDGEC, IMG_SI_EDGEC_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
    {STATUS_ICON_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
#else
    {STATUS_ICON_EDGEC, IMG_SI_EDGEC, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
    {STATUS_ICON_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
#endif
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    {STATUS_ICON_EDGE_UPLINK, IMG_SI_EDGE_UPLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_EDGE_DOWNLINK, IMG_SI_EDGE_DOWNLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_EDGE_UPDOWNLINK, IMG_SI_EDGE_UPDOWNLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_GPRS_UPLINK, IMG_SI_GPRS_UPLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_GPRS_DOWNLINK, IMG_SI_GPRS_DOWNLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_GPRS_UPDOWNLINK, IMG_SI_GPRS_UPDOWNLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#ifdef __OP01_3G__
    {STATUS_ICON_TD_UPLINK, IMG_SI_TD_UPLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_TD_DOWNLINK, IMG_SI_TD_DOWNLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_TD_UPDOWNLINK, IMG_SI_TD_UPDOWNLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif
#if (defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))
    {STATUS_ICON_HSPA_UPLINK, IMG_SI_HSPA_UPLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_HSPA_DOWNLINK, IMG_SI_HSPA_DOWNLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_HSPA_UPDOWNLINK, IMG_SI_HSPA_UPDOWNLINK_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif
#endif
    {STATUS_ICON_SLAVE_CSD, IMG_SI_CSD_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    #ifndef __MMI_NW_INFO_DN_STATUS_SLIM__ 
    {STATUS_ICON_SLAVE_EDGE, IMG_SI_EDGE_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_GPRS_SERVICE, IMG_SI_GPRS_SERVICE_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    #endif
#if (defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))
    {STATUS_ICON_SLAVE_HSPA_NO_PDP, IMG_SI_HSPA_NO_PDP_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_HSPA_PDP_ACTIVATED, IMG_SI_HSPA_PDP_ACTIVATED_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_35G, IMG_SI_35G_SIM2, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif 
#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__
    {STATUS_ICON_SLAVE_EDGEC, IMG_SI_EDGEC_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
    {STATUS_ICON_SLAVE_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
#endif

#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    {STATUS_ICON_SLAVE_EDGE_UPLINK, IMG_SI_EDGE_UPLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_EDGE_DOWNLINK, IMG_SI_EDGE_DOWNLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_EDGE_UPDOWNLINK, IMG_SI_EDGE_UPDOWNLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_GPRS_UPLINK, IMG_SI_GPRS_UPLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_GPRS_DOWNLINK, IMG_SI_GPRS_DOWNLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_GPRS_UPDOWNLINK, IMG_SI_GPRS_UPDOWNLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#if (defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))
    {STATUS_ICON_SLAVE_HSPA_UPLINK, IMG_SI_HSPA_UPLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_HSPA_DOWNLINK, IMG_SI_HSPA_DOWNLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_HSPA_UPDOWNLINK, IMG_SI_HSPA_UPDOWNLINK_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
#endif
#endif
#endif
#endif /* (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2))*/

#if defined(OBIGO_Q05A) && defined(WAP_SUPPORT)
    {STATUS_ICON_SECURITY, IMG_SI_SECURITY, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

    #ifdef __MMI_TETHERING__
    {STATUS_ICON_WIFI_TETHERING, IMG_SI_WIFI_TETHERING, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    #endif
    
    {STATUS_ICON_EARPHONE_INDICATOR, IMG_SI_EARPHONE_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_ALARM, IMG_SI_ALARM_ACTIVATED, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
//#ifndef __MMI_STATUS_ICON_BAR_SLIM__   
//    {STATUS_ICON_VOICE_RECORD, IMG_SI_VOICE_RECORD, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
//#endif    
    {STATUS_ICON_KEYPAD_LOCK, IMG_SI_KEYPAD_LOCK, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

    #if defined(__MMI_USB_SUPPORT__)
    {STATUS_ICON_USB, IMG_SI_USB, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    #endif


    {STATUS_ICON_MISSED_CALL, IMG_SI_MISSED_CALL_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

#ifdef __MMI_EMAIL__
    {STATUS_ICON_UNREAD_EMAIL, IMG_SI_UNREAD_EMAIL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_NEW_EMAIL, IMG_SI_NEW_EMAIL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
    
    
    {STATUS_ICON_PUSH_CONNECT, IMG_SI_PUSH_CONNECT, GUI_STATUS_ICON_BAR_ICON_PUSH_GROUP},
    {STATUS_ICON_PUSH_RECEIVE, IMG_SI_PUSH_RECEIVE, GUI_STATUS_ICON_BAR_ICON_PUSH_GROUP},
    {STATUS_ICON_PUSH_FAIL, IMG_SI_PUSH_FAIL, GUI_STATUS_ICON_BAR_ICON_PUSH_GROUP},

#ifdef __MMI_NCENTER_SUPPORT__
	{STATUS_ICON_UNREAD_VOICE,IMG_SI_UNREAD_VOICE, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},
#ifndef __MMI_STATUS_ICON_BAR_SLIM__ 	
	{STATUS_ICON_UNREAD_FAX, IMG_SI_UNREAD_FAX, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},
	{STATUS_ICON_UNREAD_EMAIL_MSG, IMG_SI_UNREAD_EMAIL_MSG, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},
	{STATUS_ICON_UNREAD_NET, IMG_SI_UNREAD_NET, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},
	{STATUS_ICON_UNREAD_VIDEO, IMG_SI_UNREAD_VIDEO, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif	
#elif (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    #if defined(__MMI_SLIM_IMG_RES__)
    {STATUS_ICON_UNREAD_VOICE_MASTER, IMG_SI_UNREAD_VOICE, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},
    {STATUS_ICON_UNREAD_VOICE_SLAVE, IMG_SI_UNREAD_VOICE, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},
    {STATUS_ICON_UNREAD_VOICE_SIM3, IMG_SI_UNREAD_VOICE, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},
    {STATUS_ICON_UNREAD_VOICE_SIM4, IMG_SI_UNREAD_VOICE, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},
#ifndef __MMI_STATUS_ICON_BAR_SLIM__ 	   
    {STATUS_ICON_UNREAD_FAX_MASTER, IMG_SI_UNREAD_FAX, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},
    {STATUS_ICON_UNREAD_FAX_SLAVE, IMG_SI_UNREAD_FAX, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},
    {STATUS_ICON_UNREAD_FAX_SIM3, IMG_SI_UNREAD_FAX, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},
    {STATUS_ICON_UNREAD_FAX_SIM4, IMG_SI_UNREAD_FAX, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},
    
    {STATUS_ICON_UNREAD_EMAIL_MASTER, IMG_SI_UNREAD_EMAIL_MSG, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_SLAVE, IMG_SI_UNREAD_EMAIL_MSG, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_SIM3, IMG_SI_UNREAD_EMAIL_MSG, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_SIM4, IMG_SI_UNREAD_EMAIL_MSG, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},
    
    {STATUS_ICON_UNREAD_NET_MASTER, IMG_SI_UNREAD_NET, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},
    {STATUS_ICON_UNREAD_NET_SLAVE, IMG_SI_UNREAD_NET, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},
    {STATUS_ICON_UNREAD_NET_SIM3, IMG_SI_UNREAD_NET, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},
    {STATUS_ICON_UNREAD_NET_SIM4, IMG_SI_UNREAD_NET, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},

    {STATUS_ICON_UNREAD_VIDEO_MASTER, IMG_SI_UNREAD_VIDEO, GUI_STATUS_ICON_BAR_ICON_VIDEO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_SLAVE, IMG_SI_UNREAD_VIDEO, GUI_STATUS_ICON_BAR_ICON_VIDEO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_SIM3, IMG_SI_UNREAD_VIDEO, GUI_STATUS_ICON_BAR_ICON_VIDEO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_SIM4, IMG_SI_UNREAD_VIDEO, GUI_STATUS_ICON_BAR_ICON_VIDEO_GROUP},
#endif
    #else
    {STATUS_ICON_UNREAD_VOICE_L1_MASTER, IMG_SI_UNREAD_VOICE_L1, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},
    {STATUS_ICON_UNREAD_VOICE_L2_MASTER, IMG_SI_UNREAD_VOICE_L2, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},
    {STATUS_ICON_UNREAD_VOICE_L1L2_MASTER, IMG_SI_UNREAD_VOICE_L1L2, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},
    {STATUS_ICON_UNREAD_VOICE_L1_SLAVE, IMG_SI_UNREAD_VOICE_L1, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},
    {STATUS_ICON_UNREAD_VOICE_L2_SLAVE, IMG_SI_UNREAD_VOICE_L2, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},
    {STATUS_ICON_UNREAD_VOICE_L1L2_SLAVE, IMG_SI_UNREAD_VOICE_L1L2, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},
    {STATUS_ICON_UNREAD_VOICE_L1_SIM3, IMG_SI_UNREAD_VOICE_L1, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},
    {STATUS_ICON_UNREAD_VOICE_L2_SIM3, IMG_SI_UNREAD_VOICE_L2, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},
    {STATUS_ICON_UNREAD_VOICE_L1L2_SIM3, IMG_SI_UNREAD_VOICE_L1L2, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},
    {STATUS_ICON_UNREAD_VOICE_L1_SIM4, IMG_SI_UNREAD_VOICE_L1, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},
    {STATUS_ICON_UNREAD_VOICE_L2_SIM4, IMG_SI_UNREAD_VOICE_L2, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},
    {STATUS_ICON_UNREAD_VOICE_L1L2_SIM4, IMG_SI_UNREAD_VOICE_L1L2, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},

#ifndef __MMI_STATUS_ICON_BAR_SLIM__ 	       
    {STATUS_ICON_UNREAD_FAX_L1_MASTER, IMG_SI_UNREAD_FAX_L1, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},
    {STATUS_ICON_UNREAD_FAX_L2_MASTER, IMG_SI_UNREAD_FAX_L2, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},
    {STATUS_ICON_UNREAD_FAX_L1L2_MASTER, IMG_SI_UNREAD_FAX_L1L2, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},
    {STATUS_ICON_UNREAD_FAX_L1_SLAVE, IMG_SI_UNREAD_FAX_L1, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},
    {STATUS_ICON_UNREAD_FAX_L2_SLAVE, IMG_SI_UNREAD_FAX_L2, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},
    {STATUS_ICON_UNREAD_FAX_L1L2_SLAVE, IMG_SI_UNREAD_FAX_L1L2, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},
    {STATUS_ICON_UNREAD_FAX_L1_SIM3, IMG_SI_UNREAD_FAX_L1, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},
    {STATUS_ICON_UNREAD_FAX_L2_SIM3, IMG_SI_UNREAD_FAX_L2, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},
    {STATUS_ICON_UNREAD_FAX_L1L2_SIM3, IMG_SI_UNREAD_FAX_L1L2, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},
    {STATUS_ICON_UNREAD_FAX_L1_SIM4, IMG_SI_UNREAD_FAX_L1, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},
    {STATUS_ICON_UNREAD_FAX_L2_SIM4, IMG_SI_UNREAD_FAX_L2, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},
    {STATUS_ICON_UNREAD_FAX_L1L2_SIM4, IMG_SI_UNREAD_FAX_L1L2, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},

    
    {STATUS_ICON_UNREAD_EMAIL_L1_MASTER, IMG_SI_UNREAD_EMAIL_L1, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L2_MASTER, IMG_SI_UNREAD_EMAIL_L2, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L1L2_MASTER, IMG_SI_UNREAD_EMAIL_L1L2, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L1_SLAVE, IMG_SI_UNREAD_EMAIL_L1, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L2_SLAVE, IMG_SI_UNREAD_EMAIL_L2, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L1L2_SLAVE, IMG_SI_UNREAD_EMAIL_L1L2, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L1_SIM3, IMG_SI_UNREAD_EMAIL_L1, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L2_SIM3, IMG_SI_UNREAD_EMAIL_L2, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L1L2_SIM3, IMG_SI_UNREAD_EMAIL_L1L2, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L1_SIM4, IMG_SI_UNREAD_EMAIL_L1, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L2_SIM4, IMG_SI_UNREAD_EMAIL_L2, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L1L2_SIM4, IMG_SI_UNREAD_EMAIL_L1L2, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},

    
    {STATUS_ICON_UNREAD_NET_L1_MASTER, IMG_SI_UNREAD_NET_L1, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},
    {STATUS_ICON_UNREAD_NET_L2_MASTER, IMG_SI_UNREAD_NET_L2, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},
    {STATUS_ICON_UNREAD_NET_L1L2_MASTER, IMG_SI_UNREAD_NET_L1L2, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},
    {STATUS_ICON_UNREAD_NET_L1_SLAVE, IMG_SI_UNREAD_NET_L1, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},
    {STATUS_ICON_UNREAD_NET_L2_SLAVE, IMG_SI_UNREAD_NET_L2, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},
    {STATUS_ICON_UNREAD_NET_L1L2_SLAVE, IMG_SI_UNREAD_NET_L1L2, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},
    {STATUS_ICON_UNREAD_NET_L1_SIM3, IMG_SI_UNREAD_NET_L1, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},
    {STATUS_ICON_UNREAD_NET_L2_SIM3, IMG_SI_UNREAD_NET_L2, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},
    {STATUS_ICON_UNREAD_NET_L1L2_SIM3, IMG_SI_UNREAD_NET_L1L2, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},
    {STATUS_ICON_UNREAD_NET_L1_SIM4, IMG_SI_UNREAD_NET_L1, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},
    {STATUS_ICON_UNREAD_NET_L2_SIM4, IMG_SI_UNREAD_NET_L2, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},
    {STATUS_ICON_UNREAD_NET_L1L2_SIM4, IMG_SI_UNREAD_NET_L1L2, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},

    {STATUS_ICON_UNREAD_VIDEO_L1_MASTER, IMG_SI_UNREAD_VIDEO_L1, GUI_STATUS_ICON_BAR_ICON_VIDEO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L2_MASTER, IMG_SI_UNREAD_VIDEO_L2, GUI_STATUS_ICON_BAR_ICON_VIDEO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L1L2_MASTER, IMG_SI_UNREAD_VIDEO_L1L2, GUI_STATUS_ICON_BAR_ICON_VIDEO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L1_SLAVE, IMG_SI_UNREAD_VIDEO_L1, GUI_STATUS_ICON_BAR_ICON_VIDEO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L2_SLAVE, IMG_SI_UNREAD_VIDEO_L2, GUI_STATUS_ICON_BAR_ICON_VIDEO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L1L2_SLAVE, IMG_SI_UNREAD_VIDEO_L1L2, GUI_STATUS_ICON_BAR_ICON_VIDEO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L1_SIM3, IMG_SI_UNREAD_VIDEO_L1, GUI_STATUS_ICON_BAR_ICON_VIDEO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L2_SIM3, IMG_SI_UNREAD_VIDEO_L2, GUI_STATUS_ICON_BAR_ICON_VIDEO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L1L2_SIM3, IMG_SI_UNREAD_VIDEO_L1L2, GUI_STATUS_ICON_BAR_ICON_VIDEO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L1_SIM4, IMG_SI_UNREAD_VIDEO_L1, GUI_STATUS_ICON_BAR_ICON_VIDEO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L2_SIM4, IMG_SI_UNREAD_VIDEO_L2, GUI_STATUS_ICON_BAR_ICON_VIDEO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L1L2_SIM4, IMG_SI_UNREAD_VIDEO_L1L2, GUI_STATUS_ICON_BAR_ICON_VIDEO_GROUP},
#endif
    #endif
#else
    #if defined(__MMI_SLIM_IMG_RES__)
    {STATUS_ICON_UNREAD_VOICE,IMG_SI_UNREAD_VOICE, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},
#ifndef __MMI_STATUS_ICON_BAR_SLIM__ 
    {STATUS_ICON_UNREAD_FAX, IMG_SI_UNREAD_FAX, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_MSG, IMG_SI_UNREAD_EMAIL_MSG, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},
    {STATUS_ICON_UNREAD_NET, IMG_SI_UNREAD_NET, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},
    {STATUS_ICON_UNREAD_VIDEO, IMG_SI_UNREAD_VIDEO, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif    
    #else
    {STATUS_ICON_UNREAD_VOICE_L1L2,IMG_SI_UNREAD_VOICE_L1L2, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},
    {STATUS_ICON_UNREAD_VOICE_L1, IMG_SI_UNREAD_VOICE_L1, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},
    {STATUS_ICON_UNREAD_VOICE_L2, IMG_SI_UNREAD_VOICE_L2, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},
#ifndef __MMI_STATUS_ICON_BAR_SLIM__         
    {STATUS_ICON_UNREAD_FAX_L1, IMG_SI_UNREAD_FAX_L1, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},
    {STATUS_ICON_UNREAD_FAX_L2, IMG_SI_UNREAD_FAX_L2, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},    
    {STATUS_ICON_UNREAD_FAX_L1L2, IMG_SI_UNREAD_FAX_L1L2, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L1, IMG_SI_UNREAD_EMAIL_L1, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L2, IMG_SI_UNREAD_EMAIL_L2, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},    
    {STATUS_ICON_UNREAD_EMAIL_L1L2, IMG_SI_UNREAD_EMAIL_L1L2, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},
    {STATUS_ICON_UNREAD_NET_L1, IMG_SI_UNREAD_NET_L1, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},
    {STATUS_ICON_UNREAD_NET_L2, IMG_SI_UNREAD_NET_L2, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},
    {STATUS_ICON_UNREAD_NET_L1L2, IMG_SI_UNREAD_NET_L1L2, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L1, IMG_SI_UNREAD_VIDEO_L1, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L2, IMG_SI_UNREAD_VIDEO_L2, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L1L2, IMG_SI_UNREAD_VIDEO_L1L2, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif    
    #endif
#ifdef __MMI_DUAL_SIM_MASTER__
    #if defined(__MMI_SLIM_IMG_RES__)
   
    #else
    {STATUS_ICON_UNREAD_VOICE_L1_MASTER, IMG_SI_UNREAD_VOICE_L1_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VOICE_L2_MASTER, IMG_SI_UNREAD_VOICE_L2_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VOICE_L1L2_MASTER, IMG_SI_UNREAD_VOICE_L1L2_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#ifndef __MMI_STATUS_ICON_BAR_SLIM__             
    {STATUS_ICON_UNREAD_FAX_L1_MASTER, IMG_SI_UNREAD_FAX_L1_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_FAX_L2_MASTER, IMG_SI_UNREAD_FAX_L2_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_FAX_L1L2_MASTER, IMG_SI_UNREAD_FAX_L1L2_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L1_MASTER, IMG_SI_UNREAD_EMAIL_L1_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L2_MASTER, IMG_SI_UNREAD_EMAIL_L2_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L1L2_MASTER, IMG_SI_UNREAD_EMAIL_L1L2_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_NET_L1_MASTER, IMG_SI_UNREAD_NET_L1_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_NET_L2_MASTER, IMG_SI_UNREAD_NET_L2_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_NET_L1L2_MASTER, IMG_SI_UNREAD_NET_L1L2_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L1_MASTER, IMG_SI_UNREAD_VIDEO_L1_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L2_MASTER, IMG_SI_UNREAD_VIDEO_L2_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L1L2_MASTER, IMG_SI_UNREAD_VIDEO_L1L2_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
    {STATUS_ICON_UNREAD_VOICE_L1_SLAVE, IMG_SI_UNREAD_VOICE_L1_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VOICE_L2_SLAVE, IMG_SI_UNREAD_VOICE_L2_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VOICE_L1L2_SLAVE, IMG_SI_UNREAD_VOICE_L1L2_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#ifndef __MMI_STATUS_ICON_BAR_SLIM__                 
    {STATUS_ICON_UNREAD_FAX_L1_SLAVE, IMG_SI_UNREAD_FAX_L1_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_FAX_L2_SLAVE, IMG_SI_UNREAD_FAX_L2_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_FAX_L1L2_SLAVE, IMG_SI_UNREAD_FAX_L1L2_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L1_SLAVE, IMG_SI_UNREAD_EMAIL_L1_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L2_SLAVE, IMG_SI_UNREAD_EMAIL_L2_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L1L2_SLAVE, IMG_SI_UNREAD_EMAIL_L1L2_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_NET_L1_SLAVE, IMG_SI_UNREAD_NET_L1_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_NET_L2_SLAVE, IMG_SI_UNREAD_NET_L2_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_NET_L1L2_SLAVE, IMG_SI_UNREAD_NET_L1L2_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L1_SLAVE, IMG_SI_UNREAD_VIDEO_L1_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L2_SLAVE, IMG_SI_UNREAD_VIDEO_L2_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L1L2_SLAVE, IMG_SI_UNREAD_VIDEO_L1L2_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif    
    #endif
#endif
#endif

#ifdef __MMI_AUTO_ANSWER_MACHINE__
    {STATUS_ICON_AUTOAM_REC, IMG_SI_AUTOAM_REC, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_AUTOAM_UNREAD, IMG_SI_AUTOAM_UNREAD, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_AUTOAM_ON, IMG_SI_AUTOAM_ON, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_IMPS__
/* under construction !*/
/* under construction !*/
#endif

#ifdef WAP_SUPPORT
//#ifndef __MMI_STATUS_ICON_BAR_SLIM__ //kavin_modify_for_slim_status    
//    {STATUS_ICON_WAP1, IMG_SI_WAP1, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
//    {STATUS_ICON_WAP2, IMG_SI_WAP2, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
//#endif    
    {STATUS_ICON_WAP, IMG_SI_WAP, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

    {STATUS_ICON_BT, IMG_SI_BT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_BT_CON, IMG_SI_BT_CON, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

#ifdef __KJX_FUN__
	{STATUS_ICON_GPS_OFF, IMG_SI_GPS_OFF, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
	{STATUS_ICON_GPS_ON, IMG_SI_GPS_ON, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
	{STATUS_ICON_GPS_OK, IMG_SI_GPS_OK, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
	{STATUS_ICON_GPRS_CHECK, IMG_SI_GPRS_CHECK, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
	{STATUS_ICON_GPRS_UNLINK, IMG_SI_GPRS_UNLINK, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
	{STATUS_ICON_GPRS_LINK, IMG_SI_GPRS_LINK, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
	{STATUS_ICON_NO_SIM, IMG_SI_SIGNAL_NO_SIM, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},	
	{STATUS_ICON_RFID_ON, IMG_SI_RFID_ON, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
	{STATUS_ICON_BLE_ON, IMG_SI_BLE_ON, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},	
#endif

#ifdef __NFC_SUPPORT__
	{STATUS_ICON_NFC, IMG_SI_NFC, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif    

    {STATUS_ICON_IR, IMG_SI_IR_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
        
#ifdef __MMI_STOPWATCH__
    {STATUS_ICON_STOP_WATCH, IMG_SI_STOPWATCH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
    
    {STATUS_ICON_DOWNLOADING, IMG_SI_DOWNLOADING, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_DOWNLOAD_FAILED, IMG_SI_DOWNLOAD_ERROR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_DOWNLOAD_COMPLETED, IMG_SI_DOWNLOAD_COMPLETE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

    #if defined(__MMI_NETWORK_CIPHER_SUPPORT__)
    
    #ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_NETWORK_CIPHER_GSM, IMG_SI_MASTER_NETWORK_CIPHER_GSM, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SLAVE_NETWORK_CIPHER_GSM, IMG_SI_SLAVE_NETWORK_CIPHER_GSM, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    #else
    {STATUS_ICON_NETWORK_CIPHER_GSM, IMG_SI_NETWORK_CIPHER_GSM, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    #endif
    
    {STATUS_ICON_NETWORK_CIPHER_GPRS, IMG_SI_NETWORK_CIPHER_GPRS, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    #endif

#if defined(__J2ME__) && defined(J2ME_SUPPORT_BACKGROUND)
    {STATUS_ICON_JAVA_BG_VM, IMG_SI_JAVA_BG_VM, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_JAVA_BG_VM_AUDIO, IMG_SI_JAVA_BG_VM_AUDIO, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __J2ME__
    {STATUS_ICON_JAVA_PUSH, IMG_SI_JAVA_PUSH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_BG_SOUND_EFFECT__
    {STATUS_ICON_BG_SOUND, IMG_SI_BGSND, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_AUDIO_REVERB_EFFECT__
    {STATUS_ICON_REVERB_SOUND, IMG_SI_REVERBSND, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    {STATUS_ICON_AUD_SURROUND, IMG_SI_SURROUNDSND, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __HOMEZONE_SUPPORT__
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2))
    {STATUS_ICON_HOMEZONE, IMG_SI_HZONE_SIM1, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#else
    {STATUS_ICON_HOMEZONE, IMG_SI_HZONE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    {STATUS_ICON_SLAVE_HOMEZONE, IMG_SI_HZONE_SIM2, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SIM3_HOMEZONE, IMG_SI_HZONE_SIM3, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SIM4_HOMEZONE, IMG_SI_HZONE_SIM4, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#else
#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_SLAVE_HOMEZONE, IMG_SI_HZONE_SIM2, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#endif
    {STATUS_ICON_CITYZONE, IMG_SI_CZONE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif /* __HOMEZONE_SUPPORT__  */

#ifdef __CTM_SUPPORT__
    {STATUS_ICON_TTY_INDICATOR, IMG_SI_TTY_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

    #ifdef __MMI_EMAIL__
    {STATUS_ICON_EMAIL_REF, IMG_SI_EMAIL_REF, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    #endif
    {STATUS_ICON_PUSHED_OBJ, IMG_SI_PUSHED_OBJ, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

#ifdef __MMI_PICT_BRIDGE_SUPPORT__
    {STATUS_ICON_PRINT, IMG_SI_PRINT, GUI_STATUS_ICON_BAR_ICON_PRINT_GROUP},
    {STATUS_ICON_PRINT_FAIL, IMG_SI_PRINT_FAIL, GUI_STATUS_ICON_BAR_ICON_PRINT_GROUP},
#endif

#if defined(__AGPS_SUPPORT__) && defined(__SUPL_SUPPORT__)
    {STATUS_ICON_AGPS_STATE, IMG_SI_AGPS_STATE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_SYNCML_STATUS_ICON_SUPPORT__
    {STATUS_ICON_SYNCML, IMG_SI_SYNCML, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifndef __MMI_STATUS_ICON_BAR_SLIM__ 
    {STATUS_ICON_PROVMSG_STATE, IMG_SI_PROVMSG, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
//#ifdef __MMI_DUAL_SIM_MASTER__
//    {STATUS_ICON_PROVMSG_SIM1, IMG_SI_PROVMSG_SIM1, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
//    {STATUS_ICON_PROVMSG_SIM2, IMG_SI_PROVMSG_SIM2, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
//#endif
#endif

#if defined(__QQIM_SUPPORT__)
    {STATUS_ICON_QQIM_AWAY, IMG_SI_QQIM_AWAY, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_QQIM_INVISIBLE, IMG_SI_QQIM_INVISIBLE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_QQIM_MSG, IMG_SI_QQIM_MSG, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_QQIM_OFFLINE, IMG_SI_QQIM_OFFLINE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_QQIM_ONLINE, IMG_SI_QQIM_ONLINE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

    {STATUS_ICON_MRE_DEFAULT, IMG_SI_MRE_DEFAULT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MRE_FETION, IMG_SI_MRE_FETION, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MRE_MSN, IMG_SI_MRE_MSN, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MRE_PUSHMAIL, IMG_SI_MRE_PUSHMAIL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MRE_QQ, IMG_SI_MRE_QQ, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MRE_1, IMG_SI_MRE_DEFAULT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MRE_2, IMG_SI_MRE_DEFAULT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MRE_3, IMG_SI_MRE_DEFAULT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MRE_4, IMG_SI_MRE_DEFAULT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MRE_5, IMG_SI_MRE_DEFAULT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MRE_6, IMG_SI_MRE_DEFAULT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MRE_PUSH, IMG_SI_MRE_PUSH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#if defined(__MCARE_COMMON__)
    {STATUS_ICON_MCARE, 			IMG_MCARE_STAT_MCR, 		    GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_QQ_ONLINE, 		IMG_MCARE_STAT_QQ_ON, 		    GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_QQ_OFFLINE, 		IMG_MCARE_STAT_QQ_OFF, 	        GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_QQ_AWAYLINE, 		IMG_MCARE_STAT_QQ_AWAY, 		GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_QQ_INVISBLE, 		IMG_MCARE_STAT_QQ_INVISBLE, 	GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_QQ_HAVEMSG, 		IMG_MCARE_STAT_QQ_MESSEGE, 	    GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_CONTACT_ON, 		IMG_MCARE_STAT_CONTACT_ON, 	    GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_RESERVED1, 		IMG_MCARE_STAT_MCR, 	    GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_RESERVED2, 		IMG_MCARE_STAT_MCR, 	    GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_RESERVED3, 		IMG_MCARE_STAT_MCR, 	    GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
 #endif  

    /* Sublcd start */
#ifdef __MMI_SUBLCD__
#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_SUBLCD_SIGNAL_STRENGTH, IMG_SLSI_MASTER_SIGNAL_STRENGTH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#else
    {STATUS_ICON_SUBLCD_SIGNAL_STRENGTH, IMG_SLSI_SIGNAL_STRENGTH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
    {STATUS_ICON_SUBLCD_BATTERY_STRENGTH, IMG_SLSI_BATTERY_STRENGTH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_SUBLCD_SLAVE_SIGNAL_STRENGTH, IMG_SLSI_SLAVE_SIGNAL_STRENGTH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    {STATUS_ICON_SUBLCD_SMS, IMG_SLSI_SMS_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_SUBLCD_SLAVE_SMS, IMG_SLSI_SMS_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    {STATUS_ICON_SUBLCD_RING, IMG_SLSI_RING, GUI_STATUS_ICON_BAR_ICON_SUBLCD_RING_GROUP},
    {STATUS_ICON_SUBLCD_VIBRATE, IMG_SLSI_VIBRATE, GUI_STATUS_ICON_BAR_ICON_SUBLCD_RING_GROUP},
    {STATUS_ICON_SUBLCD_VIBRATE_AND_RING, IMG_SLSI_VIBRATE_AND_RING, GUI_STATUS_ICON_BAR_ICON_SUBLCD_RING_GROUP},
    {STATUS_ICON_SUBLCD_VIBRATE_THEN_RING, IMG_SLSI_VIBRATE_THEN_RING, GUI_STATUS_ICON_BAR_ICON_SUBLCD_RING_GROUP},
    {STATUS_ICON_SUBLCD_SILENT, IMG_SLSI_SILENT, GUI_STATUS_ICON_BAR_ICON_SUBLCD_RING_GROUP},
    {STATUS_ICON_SUBLCD_ALARM, IMG_SLSI_ALARM, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SUBLCD_MISSED_CALL, IMG_SLSI_MISSED_CALL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP}
#ifdef __MMI_DUAL_SIM_MASTER__
    ,
    {STATUS_ICON_SUBLCD_SLAVE_MISSED_CALL, IMG_SLSI_SLAVE_MISSED_CALL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP}
#endif  /* __MMI_DUAL_SIM_MASTER__ */
#endif
};


#endif /* __MMI_STATUS_ICONBAR_COSMOS_STYLE__ */

#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
static MMI_BOOL wgui_status_icon_bar_integrated_enable = MMI_FALSE;
static void (*wgui_status_icon_bar_integrated_redraw)(void) = NULL;
#endif
static MMI_BOOL wgui_status_icon_bar_need_arrange = MMI_TRUE;
static MMI_BOOL wgui_status_icon_bar_need_initialize = MMI_TRUE;
static U32 wgui_status_icon_bar_clock_index = WGUI_CLOCK_INVALID_INDEX;
static MMI_BOOL wgui_status_icon_bar_clock_close_by_app = MMI_FALSE;
static void (*wgui_status_icon_bar_update_callback)(void);

#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
static MMI_BOOL wgui_inNCenter = MMI_FALSE;
#endif


/****************************************************************************
 * Local function
 ****************************************************************************/
mmi_ret wgui_status_icon_bar_sleepout_callback_handler(mmi_event_struct* param)
{
    wgui_status_icon_bar_update();
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_whether_have_blink_or_animate_icon
 * DESCRIPTION
 *  To check whether there are some icon set blink or animate flag
 * PARAMETERS
 *  void
 * RETURNS
 *  Whether have some icon set blink or animate flag
 *****************************************************************************/
static MMI_BOOL wgui_status_icon_bar_whether_have_blink_or_animate_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_enum bar_id;
    gui_status_icon_bar_struct *bar;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (bar_id = WGUI_STATUS_ICON_BAR_H_BAR;
         bar_id < WGUI_STATUS_ICON_BAR_TOTAL_BAR;
         bar_id++)
    {
        bar = &wgui_status_icon_bar_bars[bar_id];
        for (i = 0; i < bar->n_icons; i++)
        {
            if ((wgui_status_icon_bar_icons[bar->icon_list[i]].flags & GUI_STATUS_ICON_BAR_ICON_ANIMATE) ||
                (wgui_status_icon_bar_icons[bar->icon_list[i]].flags & GUI_STATUS_ICON_BAR_ICON_BLINK))
            {
                return MMI_TRUE;
            }
        }
 
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_icon_blink_and_animate_timer_callback
 * DESCRIPTION
 *  The timer callback function of status icon blink and animate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_status_icon_bar_icon_blink_and_animate_timer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))        
    S32 old_sms_full;
#endif
    wgui_status_icon_bar_enum bar_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    if(wgui_status_icon_bar_freeze)
    {
        return;
    }
#endif
    for (i = 0; i < MAX_STATUS_ICONS; i++)
    {
        if (wgui_status_icon_bar_icons[i].flags & GUI_STATUS_ICON_BAR_ICON_ANIMATE)
        {
            wgui_status_icon_bar_icons[i].current_frame++;
            if (wgui_status_icon_bar_icons[i].current_frame >= wgui_status_icon_bar_icons[i].n_frames)
            {
                wgui_status_icon_bar_icons[i].current_frame = 0;
            }
        }
        else if (wgui_status_icon_bar_icons[i].flags & GUI_STATUS_ICON_BAR_ICON_BLINK)
        {
            wgui_status_icon_bar_icons[i].flags ^= GUI_STATUS_ICON_BAR_ICON_BLINK_ON;
        }
    }

#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    if (!((wgui_status_icon_bar_get_flag(WGUI_STATUS_ICON_BAR_H_BAR) & WGUI_STATUS_ICON_BAR_FLAG_BAR_DISPLAY))&&
        wgui_status_icon_bar_integrated_enable)
    {
        if (wgui_status_icon_bar_integrated_redraw)
        {
            wgui_status_icon_bar_integrated_redraw();
        }
#ifdef __MMI_SUBLCD__
        wgui_status_icon_bar_update();
#endif
        gui_start_timer(WGUI_STATUS_ICON_BAR_TIMER_RATE, wgui_status_icon_bar_icon_blink_and_animate_timer_callback);
    }
    else
#endif
    {
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))    
        wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].n_signal ++;
        if (wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].n_signal >= MMI_MAX_SIM_NUM)
        {
            wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].n_signal = 0;
        }
        if (!(wgui_status_icon_bar_icons[STATUS_ICON_FULL_SMS + wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].n_sms_full].flags & GUI_STATUS_ICON_BAR_ICON_BLINK_ON))
        {
            old_sms_full =wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].n_sms_full;
            do
            {
               wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].n_sms_full ++;
                if(wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].n_sms_full >= 4)
                {
                   wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].n_sms_full = 0;
                }
                if (old_sms_full ==wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].n_sms_full)
                    break;
            }while(!(wgui_status_icon_bar_icons[STATUS_ICON_FULL_SMS +wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].n_sms_full].flags & GUI_STATUS_ICON_BAR_ICON_BLINK));
        }       
#endif


        for (bar_id = WGUI_STATUS_ICON_BAR_H_BAR;
                bar_id < WGUI_STATUS_ICON_BAR_TOTAL_BAR;
                bar_id++)
        {
            if(WGUI_STATUS_ICON_BAR_UPDATE_AUTO == wgui_status_icon_bar_bars[bar_id].update_type)
            {
                wgui_status_icon_bar_bars[bar_id].update_type = WGUI_STATUS_ICON_BAR_UPDATE_ALL_EXCEPT_CLOCK;
            }
            wgui_status_icon_bar_update_screen(bar_id);
        }
        gui_start_timer(
            WGUI_STATUS_ICON_BAR_TIMER_RATE,
            wgui_status_icon_bar_icon_blink_and_animate_timer_callback);
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_setup_blink_animate
 * DESCRIPTION
 *  Start or stop the timer for blinking or animating icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_status_icon_bar_setup_blink_animate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if !( defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3) && (!defined(__MMI_FTE_SUPPORT__)) && (!defined(__MMI_STATUS_ICONBAR_COSMOS_STYLE__)))
    if (wgui_status_icon_bar_whether_have_blink_or_animate_icon())
    {
        gui_start_timer(
            WGUI_STATUS_ICON_BAR_TIMER_RATE,
            wgui_status_icon_bar_icon_blink_and_animate_timer_callback);
    }
    else
    {
        gui_cancel_timer(wgui_status_icon_bar_icon_blink_and_animate_timer_callback);
    }
#endif
}

#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT

/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_time_small_hide_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_status_icon_bar_time_small_hide_callback(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cx1, cy1, cx2, cy2;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_lcd_handle =
        gui_status_icon_bar_setup_target_lcd_and_layer(
            &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR]);
    wgui_status_icon_bar_get_clip(WGUI_STATUS_ICON_BAR_H_BAR, &cx1, &cy1, &cx2, &cy2);
    wgui_status_icon_bar_set_clip(WGUI_STATUS_ICON_BAR_H_BAR, x1, y1, x2, y2);
    if(gui_status_icon_bar_hide)
    {
        gui_status_icon_bar_hide(&wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR]);
    }
    wgui_status_icon_bar_set_clip(WGUI_STATUS_ICON_BAR_H_BAR, cx1, cy1, cx2, cy2);
    gui_status_icon_bar_restore_target_lcd_and_layer(
        &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR],
        old_lcd_handle);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_close_clock_callback
 * DESCRIPTION
 *  When other application close status icon bar's clock, this function will be call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_status_icon_bar_close_clock_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_clock_index = WGUI_CLOCK_INVALID_INDEX;
}
#endif /* WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT */


/****************************************************************************
 * Global function
 ****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_set_rotate_for_wap
 * DESCRIPTION
 *  Set the mainlcd horizontal status icon bar's rotate for wap
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_set_rotate_for_wap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_enable_rotate_for_wap(
        &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR],
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset_rotate_for_wap
 * DESCRIPTION
 *  Reset the mainlcd horizontal status icon bar's rotate flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_reset_rotate_for_wap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_enable_rotate_for_wap(
        &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR],
        MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_set_display
 * DESCRIPTION
 *  Set the status icon bar's display flag
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_set_display(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__    
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    if (bar_id == WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR)
    {
        return;
    }
#endif
#endif

    gui_status_icon_bar_enable_display(
        &wgui_status_icon_bar_bars[bar_id],
        MMI_TRUE);
#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    if ((bar_id == WGUI_STATUS_ICON_BAR_H_BAR) &&
        (wgui_status_icon_bar_clock_element_id != WGUI_STATUS_ICON_BAR_INVALID_ELEMENT_ID) &&
        (wgui_status_icon_bar_clock_index == WGUI_CLOCK_INVALID_INDEX))
    {
        wgui_clock_create(
            &wgui_status_icon_bar_clock_index,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].x + wgui_status_icon_bar_bars[bar_id].x,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].y + wgui_status_icon_bar_bars[bar_id].y,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].width,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].height,
            GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_SMALL);
        wgui_clock_set_hide_function(wgui_status_icon_bar_clock_index, wgui_status_icon_bar_time_small_hide_callback);
        wgui_clock_set_close_callback(wgui_status_icon_bar_clock_index, wgui_status_icon_bar_close_clock_callback);
    }
#endif /* WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT */
}



/*****************************************************************************
 * <group dom_status_icon_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_status_icon_bar_is_display
 * DESCRIPTION
 *  Query the status icon bar's display flag
 * PARAMETERS
 *  bar_id          : [IN]        The id of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_status_icon_bar_is_display(wgui_status_icon_bar_enum bar_id)
{
    if (wgui_status_icon_bar_is_hide)
    {
        return MMI_FALSE;
    }
    else
    {
        return gui_status_icon_bar_is_display(&wgui_status_icon_bar_bars[bar_id]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset_display
 * DESCRIPTION
 *  Reset the status icon bar's display flag
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_reset_display(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_enable_display(
        &wgui_status_icon_bar_bars[bar_id],
        MMI_FALSE);

#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    if ((bar_id == WGUI_STATUS_ICON_BAR_H_BAR) &&
        (wgui_status_icon_bar_clock_index != WGUI_CLOCK_INVALID_INDEX))
    {
        wgui_clock_close(wgui_status_icon_bar_clock_index);
        wgui_status_icon_bar_clock_index = WGUI_CLOCK_INVALID_INDEX;
    }
#endif /* WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_set_background
 * DESCRIPTION
 *  Set the status icon bar background eanble
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_set_background(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_enable_background(
        &wgui_status_icon_bar_bars[bar_id],
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset_background
 * DESCRIPTION
 *  Reset the status icon bar background eanble
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_reset_background(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_enable_background(
        &wgui_status_icon_bar_bars[bar_id],
        MMI_FALSE);
}



#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__ 
/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_set_special_style
 * DESCRIPTION
 *  Set the status icon bar background eanble
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_set_special_style(wgui_status_icon_bar_enum bar_id, MMI_BOOL transparent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_enable_special_style(
        &wgui_status_icon_bar_bars[bar_id],
        MMI_TRUE,
        transparent);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset_special_style
 * DESCRIPTION
 *  Reset the status icon bar background eanble
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_reset_special_style(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_enable_special_style(
        &wgui_status_icon_bar_bars[bar_id],
        MMI_FALSE,
        MMI_FALSE);
}

/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset_special_style
 * DESCRIPTION
 *  Reset the status icon bar background eanble
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_set_background_id(wgui_status_icon_bar_enum bar_id, S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_set_background_id(
        &wgui_status_icon_bar_bars[bar_id],
        id);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_set_double_buffer
 * DESCRIPTION
 *  Set the status icon bar's double buffer flag
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *
 *****************************************************************************/
void wgui_status_icon_bar_set_double_buffer(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_enable_double_buffer(
        &wgui_status_icon_bar_bars[bar_id],
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset_double_buffer
 * DESCRIPTION
 *  Set the status icon bar's double buffer flag
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *
 *****************************************************************************/
void wgui_status_icon_bar_reset_double_buffer(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_enable_double_buffer(
        &wgui_status_icon_bar_bars[bar_id],
        MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_whether_double_buffer
 * DESCRIPTION
 *  To check the status icon bar's double buffer flag set or not
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *
 *****************************************************************************/
MMI_BOOL wgui_status_icon_bar_whether_double_buffer(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_status_icon_bar_whether_double_buffer(&wgui_status_icon_bar_bars[bar_id]);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_set_flag
 * DESCRIPTION
 *  Set status icon bar's flag
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 *  flag            [IN]        New flag of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_set_flag(wgui_status_icon_bar_enum bar_id, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    if (bar_id == WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR)
    {
        return;
    }
#endif

    gui_status_icon_bar_set_flag(
        &wgui_status_icon_bar_bars[bar_id],
        flag);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_get_flag
 * DESCRIPTION
 *  Get status icon bar's flag
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *  The flag of status icon bar
 *****************************************************************************/
U32 wgui_status_icon_bar_get_flag(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_status_icon_bar_get_flag(&wgui_status_icon_bar_bars[bar_id]);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_set_clip
 * DESCRIPTION
 *  Set the clip of status icon bar
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 *  x1              [IN]        The x coordinate of left-top corner
 *  y1              [IN]        The y coordinate of left-top corner
 *  x2              [IN]        The x coordinate of right-bottom corner
 *  y2              [IN]        The y coordinate of right-bottom corner
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_set_clip(wgui_status_icon_bar_enum bar_id, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_set_clip(
        &wgui_status_icon_bar_bars[bar_id], x1, y1, x2, y2);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_get_clip
 * DESCRIPTION
 *  Get the clip of status icon bar
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 *  x1              [OUT]       Pointer to restore the x coordinate of left-top corner
 *  y1              [OUT]       Pointer to restore the y coordinate of left-top corner
 *  x2              [OUT]       Pointer to restore the x coordinate of right-bottom corner
 *  y2              [OUT]       Pointer to restore the y coordinate of right-bottom corner
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_get_clip(wgui_status_icon_bar_enum bar_id, S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_get_clip(
        &wgui_status_icon_bar_bars[bar_id],
        x1, y1, x2, y2);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_set_target_layer
 * DESCRIPTION
 *  Set the status icon bar's target layer
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 *  target_layer    [IN]        New target layer of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_set_target_layer(wgui_status_icon_bar_enum bar_id, gdi_handle target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_set_target_layer(
        &wgui_status_icon_bar_bars[bar_id],
        target_layer);

#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    if ((bar_id == WGUI_STATUS_ICON_BAR_H_BAR) &&
        (wgui_status_icon_bar_clock_index != WGUI_CLOCK_INVALID_INDEX))
    {
        wgui_clock_set_target_layer(wgui_status_icon_bar_clock_index, target_layer);
    }
#endif /* WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_get_target_layer
 * DESCRIPTION
 *  Get the target layer of status icon bar
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *  The target layer of status icon bar
 *****************************************************************************/
gdi_handle wgui_status_icon_bar_get_target_layer(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_status_icon_bar_get_target_layer(&wgui_status_icon_bar_bars[bar_id]);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset_target_layer
 * DESCRIPTION
 *  Reset the status icon bar target layer
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_reset_target_layer(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_set_target_layer(&wgui_status_icon_bar_bars[bar_id], GDI_NULL_HANDLE);

#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    if ((bar_id == WGUI_STATUS_ICON_BAR_H_BAR) &&
        (wgui_status_icon_bar_clock_index != WGUI_CLOCK_INVALID_INDEX))
    {
        wgui_clock_set_target_layer(wgui_status_icon_bar_clock_index, GDI_NULL_HANDLE);
    }
#endif /* WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_set_alpha_blend_layer
 * DESCRIPTION
 *  Set the alpha blending(abm) layer of status icon bar
 * PARAMETERS
 *  bar_id              [IN]        The id of status icon bar
 *  alpha_blend_layer   [IN]        New alpha blending(abm) layer of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_set_alpha_blend_layer(wgui_status_icon_bar_enum bar_id, gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_set_alpha_blend_layer(
        &wgui_status_icon_bar_bars[bar_id],
        alpha_blend_layer);

#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    if ((bar_id == WGUI_STATUS_ICON_BAR_H_BAR) &&
        (wgui_status_icon_bar_clock_index != WGUI_CLOCK_INVALID_INDEX))
    {
        wgui_clock_set_abm_layer(wgui_status_icon_bar_clock_index, alpha_blend_layer);
    }
#endif /* WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_stats_icon_bar_get_alpha_blend_layer
 * DESCRIPTION
 *  Get the status icon bar's alpha blending(abm) layer
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *  The alpha blending(abm) layer of status icon bar
 *****************************************************************************/
gdi_handle wgui_status_icon_bar_get_alpha_blend_layer(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_status_icon_bar_get_alpha_blend_layer(&wgui_status_icon_bar_bars[bar_id]);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset_alpha_blend_layer
 * DESCRIPTION
 *  Reset the alpha blending(abm) layer of status icon bar
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_reset_alpha_blend_layer(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_set_alpha_blend_layer(
        &wgui_status_icon_bar_bars[bar_id],
        GDI_NULL_HANDLE);

#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    if ((bar_id == WGUI_STATUS_ICON_BAR_H_BAR) &&
        (wgui_status_icon_bar_clock_index != WGUI_CLOCK_INVALID_INDEX))
    {
        wgui_clock_set_abm_layer(wgui_status_icon_bar_clock_index, GDI_NULL_HANDLE);
    }
#endif /* WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_move
 * DESCRIPTION
 *  Move the status icon bar and set the clip of status icon bar
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 *  x               [IN]        The x coordinate of status icon bar
 *  y               [IN]        The y coordinate of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_move(wgui_status_icon_bar_enum bar_id, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_move(&wgui_status_icon_bar_bars[bar_id], x, y);
    wgui_status_icon_bar_set_clip(
        bar_id,
        x,
        y,
        x + wgui_status_icon_bar_bars[bar_id].width - 1,
        y + wgui_status_icon_bar_bars[bar_id].height - 1);
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_resize
 * DESCRIPTION
 *  Resize the status icon bar
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 *  width           [IN]        The width coordinate of status icon bar
 *  height          [IN]        The height coordinate of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_resize(wgui_status_icon_bar_enum bar_id, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_resize(&wgui_status_icon_bar_bars[bar_id], width, height);
    wgui_status_icon_bar_set_clip(
        bar_id,
        wgui_status_icon_bar_bars[bar_id].x,
        wgui_status_icon_bar_bars[bar_id].y,
        wgui_status_icon_bar_bars[bar_id].x + width - 1,
        wgui_status_icon_bar_bars[bar_id].y + height - 1);
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_register_hide_callback
 * DESCRIPTION
 *  Register the hide callback of status icon bar
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 *  hide_callback   [IN]        The new hide callback function of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_register_hide_callback(wgui_status_icon_bar_enum bar_id, void (*hide_callback)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_register_hide_callback(&wgui_status_icon_bar_bars[bar_id], hide_callback);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_initialize
 * DESCRIPTION
 *  Initialize all status icon bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_initialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 icon_id;
    gui_status_icon_bar_struct *bar;
    wgui_status_icon_bar_enum bar_id;
#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    S32 clock_width, clock_height;
    U32 temp_clock_id;
#endif
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__ 
    S32 old_width;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__ 
    bar = &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR];
    old_width = bar->width;
#endif
    gui_status_icon_bar_initialize();

    /* Main lcd horizontal status icon bar */
    bar_id = WGUI_STATUS_ICON_BAR_H_BAR;
    bar = &wgui_status_icon_bar_bars[bar_id];
    bar->x = 0;
    bar->y = 0;
    bar->width = MAIN_LCD_device_width;
    bar->height = MMI_status_bar_height;
    bar->x1 = 0;
    bar->y1 = 0;
    bar->x2 = MAIN_LCD_device_width - 1;
    bar->y2 = MMI_status_bar_height - 1;
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2))
    bar->n_signal = 0;
    bar->n_sms_full = 0;
#endif
#if (defined(__MMI_FTE_SUPPORT__) && defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    bar->new_icon_id = -1;
#endif
    bar->update_type = WGUI_STATUS_ICON_BAR_UPDATE_AUTO;
    gui_status_icon_bar_set_target_lcd(bar, GDI_LCD_MAIN_LCD_HANDLE);
#ifdef WGUI_STATUS_ICON_ALIGN_RIGHT
    wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].flags |= WGUI_STATUS_ICON_BAR_ALIGN_BAR_RIGHT;
#endif

#ifndef __MMI_STATUS_ICONBAR_COSMOS_STYLE__ 
#ifdef WGUI_STATUS_ICON_SHOW_V_BAR
    /* Main lcd vertical status icon bar */
    bar_id = WGUI_STATUS_ICON_BAR_V_BAR;
    bar = &wgui_status_icon_bar_bars[bar_id];
    bar->x = MAIN_LCD_device_width - 17;
    bar->y = MMI_status_bar_height;
    bar->width = 17;
    bar->height = MAIN_LCD_device_height - MMI_status_bar_height - MMI_button_bar_height;
    bar->x1 = MAIN_LCD_device_width - 17;
    bar->y1 = MMI_status_bar_height;
    bar->x2 = MAIN_LCD_device_width;
#ifdef __MMI_KLG__
    bar->y2 = MAIN_LCD_device_height >> 1;
#else
    bar->y2 = MAIN_LCD_device_height - MMI_button_bar_height - 1;
#endif
    bar->update_type = WGUI_STATUS_ICON_BAR_UPDATE_AUTO;
    gui_status_icon_bar_set_target_lcd(bar, GDI_LCD_MAIN_LCD_HANDLE);
#endif

    /* Sub lcd status icon bar */
#ifdef __MMI_SUBLCD__	
    bar_id = WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR;
    bar = &wgui_status_icon_bar_bars[bar_id];
    bar->x = 0;
    bar->y = 0;
    bar->width = SUB_LCD_device_width;
    bar->height = 14;
    bar->x1 = 0;
    bar->y1 = 0;
    bar->x2 = SUB_LCD_device_width - 1;
    bar->y2 = 14;
    bar->update_type = WGUI_STATUS_ICON_BAR_UPDATE_AUTO;
    gui_status_icon_bar_set_target_lcd(bar, GDI_LCD_SUB_LCD_HANDLE);
#endif /* #ifdef __MMI_SUBLCD__	*/	
#endif /* #ifndef __MMI_STATUS_ICONBAR_COSMOS_STYLE__  */

    for (i = WGUI_STATUS_ICON_BAR_H_BAR;
         i < WGUI_STATUS_ICON_BAR_TOTAL_BAR;
         i++)
    {
        wgui_status_icon_bar_bars[i].rotate_flag_for_wap = MMI_FALSE;
        wgui_status_icon_bar_bars[i].alpha_blend_layer = GDI_NULL_HANDLE;
        wgui_status_icon_bar_bars[i].target_layer = GDI_NULL_HANDLE;
    }

    for (i = STATUS_ICON_MAINLCD_START; i < MAX_STATUS_ICONS; i++)
    {
        icon_id = wgui_status_icon_bar_icon_image_maps[i].icon_id;
        if(wgui_status_icon_bar_need_initialize)
        {
            if (wgui_status_icon_bar_icon_image_maps[i].image_id)
            {
                wgui_status_icon_bar_icons[icon_id].image_id =
                    wgui_status_icon_bar_icon_image_maps[i].image_id;
            }
            wgui_status_icon_bar_icons[icon_id].group =
                wgui_status_icon_bar_icon_image_maps[i].group;
        }

        wgui_status_icon_bar_icons[icon_id].image_data =
            get_image((MMI_ID_TYPE)(wgui_status_icon_bar_icons[icon_id].image_id));
        wgui_status_icon_bar_icons[icon_id].n_frames =
            (S16)gui_image_n_frames(wgui_status_icon_bar_icons[icon_id].image_data);
        gui_measure_image(
            wgui_status_icon_bar_icons[icon_id].image_data,
            &wgui_status_icon_bar_icons[icon_id].width,
            &wgui_status_icon_bar_icons[icon_id].height);
    }

    wgui_status_icon_bar_need_arrange = MMI_TRUE;
    wgui_status_icon_bar_need_initialize = MMI_FALSE;
#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    wgui_clock_create(
        &temp_clock_id,
        0,
        0,
        0,
        0,
        GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_SMALL);
    wgui_clock_measure_digital_small_clock(
        temp_clock_id,
        &clock_width,
        &clock_height);
    wgui_clock_close(temp_clock_id);
    if(wgui_status_icon_bar_clock_element_id == WGUI_STATUS_ICON_BAR_INVALID_ELEMENT_ID)
    {
        wgui_status_icon_bar_clock_element_id =
            wgui_status_icon_bar_create_element(
                clock_width,
                MMI_status_bar_height,
                wgui_status_icon_bar_show_clock,
            #ifdef __OP11__
                WGUI_STATUS_ICON_BAR_ELEMENT_ALIGN_LEFT
            #else
                #ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__ 
                    WGUI_STATUS_ICON_BAR_ELEMENT_ALIGN_RIGHT //WGUI_STATUS_ICON_BAR_ELEMENT_ALIGN_CENTER
                #else /* __MMI_STATUS_ICONBAR_COSMOS_STYLE__ */
                    WGUI_STATUS_ICON_BAR_ELEMENT_ALIGN_RIGHT
                #endif /* __MMI_STATUS_ICONBAR_COSMOS_STYLE__ */
            #endif
                );
    }
#endif

#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__ 
    bar->bar_id = NULL;
    if (old_width)
    {
        wgui_status_icon_bar_update();
    }
#endif
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3)) && (!defined(__MMI_FTE_SUPPORT__)) && (!defined(__MMI_STATUS_ICONBAR_COSMOS_STYLE__))   
        gui_start_timer(
            WGUI_STATUS_ICON_BAR_TIMER_RATE,
            wgui_status_icon_bar_icon_blink_and_animate_timer_callback);
#endif
}

#ifdef __MMI_VUI_ENGINE__
/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_add_instance
 * DESCRIPTION
 *  Add instance to status icon bar chain
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 *  chain_node      [IN]        the instance chain node struct
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_add_instance(wgui_status_icon_bar_enum bar_id, status_icon_bar_chain_node_struct* chain_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_struct *bar;
    status_icon_bar_chain_node_struct *ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bar = &wgui_status_icon_bar_bars[bar_id];
    ptr = bar->chain_head;
    if(ptr != NULL)
    {
        while(ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = chain_node;
        chain_node->prev = ptr;
        chain_node->next = NULL;
    }
    else
    {
        bar->chain_head = chain_node;
        bar->chain_head->next = NULL;
        bar->chain_head->prev = NULL;
    }
    bar->instance_count++;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_del_instance
 * DESCRIPTION
 *  Delete instance from status icon bar chain
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 *  chain_node      [IN]        the instance chain node struct
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_del_instance(wgui_status_icon_bar_enum bar_id, status_icon_bar_chain_node_struct* chain_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_struct *bar;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(chain_node == NULL)
    {
        return;
    }
    bar = &wgui_status_icon_bar_bars[bar_id];
    if(bar->instance_count == 0)
    {
        bar->chain_head = NULL;
        return;
    }
    if(chain_node->prev == NULL)
    {
        bar->chain_head = NULL;
    }
    else
    {
        (chain_node->prev)->next = chain_node->next;
    }
    if(chain_node->next)
    {
        (chain_node->next)->prev = chain_node->prev;
    }
    bar->instance_count--;
    wgui_status_icon_bar_reset();

}
#endif

/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_redraw
 * DESCRIPTION
 *  Register the hide callback of status icon bar
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 *  hide_callback   [IN]        The new hide callback function of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_redraw(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_update_screen(bar_id);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_show_horizontal_bar
 * DESCRIPTION
 *  Show status icon bar for video player
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_show_horizontal_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_status_icon_bar_need_arrange && (gui_status_icon_bar_arrange != NULL))
    {
        gui_status_icon_bar_arrange();
        wgui_status_icon_bar_need_arrange = MMI_FALSE;
    }

    old_lcd_handle = gui_status_icon_bar_setup_target_lcd_and_layer(&wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR]);

#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    if ((wgui_status_icon_bar_clock_element_id != WGUI_STATUS_ICON_BAR_INVALID_ELEMENT_ID) &&
        (wgui_status_icon_bar_clock_index == WGUI_CLOCK_INVALID_INDEX) &&
        (wgui_status_icon_bar_clock_close_by_app == MMI_FALSE))
    {
        wgui_clock_create(
            &wgui_status_icon_bar_clock_index,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].x + wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].x,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].y + wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].y,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].width,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].height,
            GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_SMALL);
        wgui_clock_set_hide_function(wgui_status_icon_bar_clock_index, wgui_status_icon_bar_time_small_hide_callback);
        wgui_clock_set_close_callback(wgui_status_icon_bar_clock_index, wgui_status_icon_bar_close_clock_callback);
    }

    if (wgui_status_icon_bar_clock_index != WGUI_CLOCK_INVALID_INDEX)
    {
        wgui_clock_move(
            wgui_status_icon_bar_clock_index,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].x + wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].x,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].y + wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].y);
        wgui_clock_set_target_layer(
            wgui_status_icon_bar_clock_index,
            wgui_status_icon_bar_get_target_layer(WGUI_STATUS_ICON_BAR_H_BAR));
        wgui_clock_set_abm_layer(
            wgui_status_icon_bar_clock_index,
            wgui_status_icon_bar_get_alpha_blend_layer(WGUI_STATUS_ICON_BAR_H_BAR));
    }
#endif /* WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT */

    if (gui_status_icon_bar_show != NULL)
    {
        gui_status_icon_bar_show(&wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR]);
    }

    gui_status_icon_bar_restore_target_lcd_and_layer (&wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR], old_lcd_handle);
	wgui_status_icon_bar_set_double_buffer_int(WGUI_STATUS_ICON_BAR_H_BAR);
}

/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_show
 * DESCRIPTION
 *  Show the status icon bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_show(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_lcd_handle = gui_status_icon_bar_setup_target_lcd_and_layer(&wgui_status_icon_bar_bars[bar_id]);
#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    if ((bar_id == WGUI_STATUS_ICON_BAR_H_BAR) &&
         (wgui_status_icon_bar_clock_element_id != WGUI_STATUS_ICON_BAR_INVALID_ELEMENT_ID) &&
         (wgui_status_icon_bar_clock_index == WGUI_CLOCK_INVALID_INDEX) &&
         (wgui_status_icon_bar_clock_close_by_app == MMI_FALSE))
    {
        wgui_clock_create(
            &wgui_status_icon_bar_clock_index,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].x + wgui_status_icon_bar_bars[bar_id].x,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].y + wgui_status_icon_bar_bars[bar_id].y,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].width,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].height,
            GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_SMALL);
        wgui_clock_set_hide_function(wgui_status_icon_bar_clock_index, wgui_status_icon_bar_time_small_hide_callback);
        wgui_clock_set_close_callback(wgui_status_icon_bar_clock_index, wgui_status_icon_bar_close_clock_callback);
    }

    if ((bar_id == WGUI_STATUS_ICON_BAR_H_BAR) &&
        (wgui_status_icon_bar_clock_index != WGUI_CLOCK_INVALID_INDEX))
    {
        wgui_clock_move(
            wgui_status_icon_bar_clock_index,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].x + wgui_status_icon_bar_bars[bar_id].x,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].y + wgui_status_icon_bar_bars[bar_id].y);
        wgui_clock_set_target_layer(
            wgui_status_icon_bar_clock_index,
            wgui_status_icon_bar_get_target_layer(bar_id));
        wgui_clock_set_abm_layer(
            wgui_status_icon_bar_clock_index,
            wgui_status_icon_bar_get_alpha_blend_layer(bar_id));
    }
#endif /* WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT */

    if (gui_status_icon_bar_show != NULL)
    {
        gui_status_icon_bar_show(&wgui_status_icon_bar_bars[bar_id]);
    }
#ifdef __MMI_VUI_ENGINE__
    if(wgui_status_icon_bar_bars[bar_id].instance_count == 0)
#endif
    {
        gdi_layer_blt_previous(
            wgui_status_icon_bar_bars[bar_id].x,
            wgui_status_icon_bar_bars[bar_id].y,
            wgui_status_icon_bar_bars[bar_id].x + wgui_status_icon_bar_bars[bar_id].width - 1,
            wgui_status_icon_bar_bars[bar_id].y + wgui_status_icon_bar_bars[bar_id].height - 1);
    }
    gui_status_icon_bar_restore_target_lcd_and_layer (&wgui_status_icon_bar_bars[bar_id], old_lcd_handle);
    wgui_status_icon_bar_set_double_buffer_int(bar_id);
}

void wgui_status_icon_bar_set_double_buffer_int(wgui_status_icon_bar_enum bar_id)
{
    if (wgui_status_icon_bar_whether_double_buffer(bar_id))
    {
        if(wgui_status_icon_bar_get_target_layer(bar_id) != GDI_NULL_HANDLE)
        {
            gdi_layer_push_and_set_active(wgui_status_icon_bar_get_target_layer(bar_id));
            gdi_layer_toggle_double();
            gdi_layer_copy_double();
            gdi_layer_pop_and_restore_active();
        }
    }
}
/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_update_screen
 * DESCRIPTION
 *  update screen
 * PARAMETERS
 *  bar_id          [IN]            bar id
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_update_screen(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VUI_ENGINE__
    status_icon_bar_chain_node_struct *chain_ptr;
    S32 i;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (srv_backlight_is_lcd_sleep() == MMI_TRUE)
    {
        return;
    }

    if (!(wgui_status_icon_bar_bars[bar_id].flags & WGUI_STATUS_ICON_BAR_FLAG_BAR_DISPLAY))
    {
        return;
    }

#ifdef __MMI_VUI_ENGINE__
    if(wgui_status_icon_bar_bars[bar_id].instance_count > 0)
    {
        chain_ptr = wgui_status_icon_bar_bars[bar_id].chain_head;
        for(i = 0; i < wgui_status_icon_bar_bars[bar_id].instance_count; i++)
        {
            if(chain_ptr != NULL && chain_ptr->update_screen_callback != NULL)
            {
                chain_ptr->update_screen_callback(chain_ptr->instance);
                chain_ptr = chain_ptr->next;
            }
        }
    }
    else
#endif
    {
        wgui_status_icon_bar_show(bar_id);
    }
}
#if defined(__GGT_TASK__)
#if defined(__OLED_BW_MMI__)
extern void mmi_show_idle_screen(void);
extern MMI_BOOL mmi_idle_is_active(void);
kal_bool idle_need_update = KAL_FALSE;
void mmi_idle_set_status_status(kal_bool s)
{
	idle_need_update = s;
}
kal_bool mmi_idle_need_update_status(void)
{
	return idle_need_update;
}
#endif /* __OLED_BW_MMI__ */
#endif
/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_update
 * DESCRIPTION
 *  Update all display status icon bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_enum bar_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_backlight_is_lcd_sleep() == MMI_TRUE)
    {
        return;
    }
#if defined(__GGT_TASK__)
// baiwenlin 20130902  更新状态
#if defined(__OLED_BW_MMI__)
	if(mmi_idle_need_update_status()&&mmi_idle_is_active())
	{
		mmi_show_idle_screen();
		mmi_idle_set_status_status(KAL_FALSE);
	}
	return;
#endif /* __OLED_BW_MMI__ */
#endif

    if (wgui_status_icon_bar_update_callback)
    {
        /* this update callback for java to update status icon in java screen */
        wgui_status_icon_bar_update_callback();
    }

    if (wgui_status_icon_bar_need_arrange && (gui_status_icon_bar_arrange != NULL))
    {
        gui_status_icon_bar_arrange();
        wgui_status_icon_bar_need_arrange = MMI_FALSE;
    }
    for (bar_id = WGUI_STATUS_ICON_BAR_H_BAR;
         bar_id < WGUI_STATUS_ICON_BAR_TOTAL_BAR;
         bar_id++)
    {
        wgui_status_icon_bar_bars[bar_id].update_type = WGUI_STATUS_ICON_BAR_UPDATE_ALL;
        wgui_status_icon_bar_update_screen(bar_id);
    }
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    if (g_balloon_need_update)
    {
        mmi_frm_nmgr_status_bar_balloon_update();
        g_balloon_need_update = MMI_FALSE;
    }
#endif

}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_hide
 * DESCRIPTION
 *  Hide the status icon bar, show the background of status icon bar
 * PARAMETERS
 *  bar_id      [IN]    The Id of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_hide(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_struct *bar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bar = &wgui_status_icon_bar_bars[bar_id];
    gdi_layer_push_and_set_clip(bar->x1, bar->y1, bar->x2, bar->y2);
    if(gui_status_icon_bar_hide)
    {
        gui_status_icon_bar_hide(bar);
    }
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_close
 * DESCRIPTION
 *  Close all status icon bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset
 * DESCRIPTION
 *  reset all status icon bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_enum bar_id;
    gdi_handle active_lcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&active_lcd);
    for (bar_id = WGUI_STATUS_ICON_BAR_H_BAR;
         bar_id < WGUI_STATUS_ICON_BAR_TOTAL_BAR;
         bar_id++)
    {

        if (wgui_status_icon_bar_bars[bar_id].target_lcd == active_lcd)
        {
            wgui_status_icon_bar_reset_display(bar_id);
            wgui_status_icon_bar_reset_double_buffer(bar_id);
            wgui_status_icon_bar_reset_target_layer(bar_id);
            wgui_status_icon_bar_reset_alpha_blend_layer(bar_id);
            wgui_status_icon_bar_register_hide_callback(bar_id, NULL);
            wgui_status_icon_bar_set_background(bar_id);
//            wgui_status_icon_bar_reset_IME_callback(bar_id); 
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__ 
            wgui_status_icon_bar_reset_special_style(bar_id);
#endif
        }
    }

    if (active_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        wgui_status_icon_bar_reset_update_callback();
//        wgui_status_icon_bar_reset_rotate_for_wap();
#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
        if (wgui_status_icon_bar_clock_close_by_app)
        {
            S32 clock_width;
            S32 clock_height;
            U32 temp_clock_index;
            MMI_ASSERT(wgui_status_icon_bar_clock_element_id == WGUI_STATUS_ICON_BAR_INVALID_ELEMENT_ID);
            MMI_ASSERT(wgui_status_icon_bar_clock_index == WGUI_CLOCK_INVALID_INDEX);
            wgui_clock_create(
                &temp_clock_index,
                0,
                0,
                0,
                0,
                GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_SMALL);
            wgui_clock_measure_digital_small_clock(
                temp_clock_index,
                &clock_width,
                &clock_height);
            wgui_clock_close(temp_clock_index);
            if(wgui_status_icon_bar_clock_element_id == WGUI_STATUS_ICON_BAR_INVALID_ELEMENT_ID)
            {
                wgui_status_icon_bar_clock_element_id =
                    wgui_status_icon_bar_create_element(
                        clock_width,
                        MMI_status_bar_height,
                        wgui_status_icon_bar_show_clock,
                    #ifdef __OP11__
                        WGUI_STATUS_ICON_BAR_ELEMENT_ALIGN_LEFT
                    #else
                        #ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__ 
                            WGUI_STATUS_ICON_BAR_ELEMENT_ALIGN_RIGHT //WGUI_STATUS_ICON_BAR_ELEMENT_ALIGN_CENTER
                        #else /* __MMI_STATUS_ICONBAR_COSMOS_STYLE__ */
                            WGUI_STATUS_ICON_BAR_ELEMENT_ALIGN_RIGHT
                        #endif /* __MMI_STATUS_ICONBAR_COSMOS_STYLE__ */
                    #endif
                        );
            }
            wgui_status_icon_bar_clock_close_by_app = MMI_FALSE;
        }
#endif        
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_register_update_callback
 * DESCRIPTION
 *  Register the update callback function, this callback function used by java,
 *  When update status icon bar, will invoke the update callback function for java
 * PARAMETERS
 *  update_callback     [IN]        The register update callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_register_update_callback(void (*update_callback)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_update_callback = update_callback;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_register_update_callback
 * DESCRIPTION
 *  Register the update callback function, this callback function used by java,
 *  When update status icon bar, will invoke the update callback function for java
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_reset_update_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_update_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_get_clock
 * DESCRIPTION
 *  Get the clock in status icon bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 wgui_status_icon_bar_get_clock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_status_icon_bar_clock_index;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_close_clock
 * DESCRIPTION
 *  Close the clock element
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_close_clock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    if (wgui_status_icon_bar_clock_element_id != WGUI_STATUS_ICON_BAR_INVALID_ELEMENT_ID)
    {
        wgui_status_icon_bar_close_element(wgui_status_icon_bar_clock_element_id);
        if (wgui_status_icon_bar_clock_index != WGUI_CLOCK_INVALID_INDEX)
        {
            wgui_status_icon_bar_need_arrange = MMI_TRUE;
            wgui_clock_close (wgui_status_icon_bar_clock_index);
            wgui_status_icon_bar_clock_index = WGUI_CLOCK_INVALID_INDEX;
        }
        
        wgui_status_icon_bar_clock_element_id = WGUI_STATUS_ICON_BAR_INVALID_ELEMENT_ID;
        wgui_status_icon_bar_clock_close_by_app = MMI_TRUE;
    }    
#endif /* WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_change_timer_format_callback
 * DESCRIPTION
 *  When change timer format, this callback function will be invoke to resize element and clock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_change_timer_format_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    S32 clock_width, clock_height;
    U32 temp_clock_id;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    wgui_clock_create(
        &temp_clock_id,
        0,
        0,
        0,
        0,
        GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_SMALL);
    wgui_clock_measure_digital_small_clock(
        temp_clock_id,
        &clock_width,
        &clock_height);
    wgui_clock_close(temp_clock_id);
    if(wgui_status_icon_bar_clock_element_id != WGUI_STATUS_ICON_BAR_INVALID_ELEMENT_ID)
    {
        wgui_status_icon_bar_resize_element(
            wgui_status_icon_bar_clock_element_id,
            clock_width,
            MMI_status_bar_height);
        if(wgui_status_icon_bar_clock_index != WGUI_CLOCK_INVALID_INDEX)
        {
            if (wgui_status_icon_bar_need_arrange && (gui_status_icon_bar_arrange != NULL))
            {
                gui_status_icon_bar_arrange();
                wgui_status_icon_bar_need_arrange = MMI_FALSE;
            }
            wgui_clock_resize(wgui_status_icon_bar_clock_index, clock_width, MMI_status_bar_height);
            wgui_clock_move(
                wgui_status_icon_bar_clock_index,
                wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].x + wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].x,
                wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].y+ wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].y);
        }
    }
    wgui_status_icon_bar_update();
#endif    
}

/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_register_IME_callback
 * DESCRIPTION
 *  Register IME callback of status icon bar
 * PARAMETERS
 *  bar_id          [IN]        Id of status icon bar
 *  IME_callback    [IN]        The new IME callback of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_register_IME_callback(wgui_status_icon_bar_enum bar_id, void (*IME_callback)(S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_register_IME_callback(
        &wgui_status_icon_bar_bars[bar_id],
        IME_callback);
#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    if ((bar_id == WGUI_STATUS_ICON_BAR_H_BAR) &&
        (wgui_status_icon_bar_clock_index != WGUI_CLOCK_INVALID_INDEX))
    {
         wgui_clock_set_post_display_callback(
             wgui_status_icon_bar_clock_index,
             IME_callback);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset_IME_callback
 * DESCRIPTION
 *  Reset IME callback of status icon bar
 * PARAMETERS
 *  bar_id             [IN]        Id of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_reset_IME_callback(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_reset_IME_callback(&wgui_status_icon_bar_bars[bar_id]);
#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    if ((bar_id == WGUI_STATUS_ICON_BAR_H_BAR) &&
        (wgui_status_icon_bar_clock_index != WGUI_CLOCK_INVALID_INDEX))
    {
         wgui_clock_set_post_display_callback(
             wgui_status_icon_bar_clock_index,
             NULL);
    }
#endif
}


/****************************************************************************
 * Status icon function
 ****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_set_icon_display
 * DESCRIPTION
 *  Set the status icon's display flag
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_set_icon_display(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
	S32 i;
	gui_status_icon_bar_struct *bar;
#endif /* __MMI_STATUS_ICONBAR_COSMOS_STYLE__ */


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
	bar = &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR];
	if (icon_id > STATUS_ICON_MAINLCD_LEFT_REGION_START && icon_id < STATUS_ICON_MAINLCD_LEFT_REGION_END)
	{
        for (i = 0; i < bar->n_all_events; i++)
        {
            if (bar->all_show_events[i] == icon_id)
                break;
        }
        if (i >= bar->n_all_events)
        {
            bar->all_show_events[bar->n_all_events] = icon_id;
            bar->n_all_events++;
        }
        else
        {
            while(i < bar->n_all_events - 1)
            {
                bar->all_show_events[i] = bar->all_show_events[i + 1];
                i++;
            }
            bar->all_show_events[bar->n_all_events - 1] = icon_id;
        }
    }
#endif /* __MMI_STATUS_ICONBAR_COSMOS_STYLE__ */
    
    if ((icon_id < 0) || (icon_id >= MAX_STATUS_ICONS))
    {
        return;
    }
    gui_status_icon_bar_enable_icon_display(&wgui_status_icon_bar_icons[icon_id], MMI_TRUE);
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
#if (defined(__MMI_FTE_SUPPORT__) && defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    if(icon_id >= STATUS_ICON_MAINLCD_START && icon_id < STATUS_ICON_MAINLCD_END)
    {
        if(!wgui_status_icon_bar_whether_icon_real_display(icon_id))
        {
            wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].new_icon_id = icon_id;
        }
    }
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3) */

#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3) && !defined(__COSMOS_MMI_PACKAGE__))
    wgui_cat9010_update_status_icon(icon_id);
#endif
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    g_balloon_need_update = MMI_TRUE;
#endif

}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset_icon_display
 * DESCRIPTION
 *  Reset status icon's display flag
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_reset_icon_display(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
	S32 i;
	gui_status_icon_bar_struct *bar;
#endif /* __MMI_STATUS_ICONBAR_COSMOS_STYLE__ */


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((icon_id < 0) || (icon_id >= MAX_STATUS_ICONS))
    {
        return;
    }

    gui_status_icon_bar_enable_icon_display(&wgui_status_icon_bar_icons[icon_id], MMI_FALSE);
    gui_status_icon_bar_enable_icon_blink(&wgui_status_icon_bar_icons[icon_id], MMI_FALSE);
    gui_status_icon_bar_enable_icon_animate(&wgui_status_icon_bar_icons[icon_id], MMI_FALSE);
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
    wgui_status_icon_bar_setup_blink_animate();

#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
	bar = &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR];
	if (icon_id > STATUS_ICON_MAINLCD_LEFT_REGION_START && icon_id < STATUS_ICON_MAINLCD_LEFT_REGION_END)
	{
        for (i = 0; i < bar->n_all_events; i++)
	    {
		    if (bar->all_show_events[i] == icon_id)
	        {
			    break;
		    }
	    }
        if (i < bar->n_all_events)
        {
            while (i < bar->n_all_events - 1)
            {
                bar->all_show_events[i] = bar->all_show_events[i + 1];
                i++;
            }            
            bar->n_all_events --;
            bar->all_show_events[bar->n_all_events] = 0;
        }
    }
#endif /* __MMI_STATUS_ICONBAR_COSMOS_STYLE__ */
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3) && !defined(__COSMOS_MMI_PACKAGE__))
    wgui_cat9010_update_status_icon(icon_id);
#endif
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    g_balloon_need_update = MMI_TRUE;
#endif


}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_set_icon_animate
 * DESCRIPTION
 *  Set status icon's animate flag
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_set_icon_animate(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((icon_id < 0) || (icon_id >= MAX_STATUS_ICONS))
    {
        return;
    }

    gui_status_icon_bar_enable_icon_animate(&wgui_status_icon_bar_icons[icon_id], MMI_TRUE);
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
    
#if !( defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3) && (!defined(__MMI_FTE_SUPPORT__)) && (!defined(__MMI_STATUS_ICONBAR_COSMOS_STYLE__)))
    gui_start_timer(
        WGUI_STATUS_ICON_BAR_TIMER_RATE,
        wgui_status_icon_bar_icon_blink_and_animate_timer_callback);
#endif
#if (defined(__MMI_FTE_SUPPORT__) && defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
        if(icon_id >= STATUS_ICON_MAINLCD_START && icon_id < STATUS_ICON_MAINLCD_END)
        {
            if(!wgui_status_icon_bar_whether_icon_real_display(icon_id))
            {
                wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].new_icon_id = icon_id;
            }
        }
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2) */


}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset_icon_animate
 * DESCRIPTION
 *  Reset status icon's animate flag
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_reset_icon_animate(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((icon_id < 0) || (icon_id >= MAX_STATUS_ICONS))
    {
        return;
    }
    gui_status_icon_bar_enable_icon_animate(&wgui_status_icon_bar_icons[icon_id], MMI_FALSE);
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
    wgui_status_icon_bar_setup_blink_animate();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_show_icon
 * DESCRIPTION
 *  Show the status icon
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_show_icon(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((icon_id < 0) || (icon_id >= MAX_STATUS_ICONS))
    {
        return;
    }

    wgui_status_icon_bar_set_icon_display(icon_id);
    wgui_status_icon_bar_update();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_hide_icon
 * DESCRIPTION
 *  Hide the status icon
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_hide_icon(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_reset_icon_display (icon_id);
    wgui_status_icon_bar_update();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_animate_icon
 * DESCRIPTION
 *  animate status icon
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_animate_icon(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((icon_id < 0) || (icon_id >= MAX_STATUS_ICONS))
    {
        return;
    }

    wgui_status_icon_bar_set_icon_animate(icon_id);
    wgui_status_icon_bar_update();
}

/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_blink_icon
 * DESCRIPTION
 *  Blinking status icon
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_blink_icon(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((icon_id < 0) || (icon_id >= MAX_STATUS_ICONS))
    {
        return;
    }
    gui_status_icon_bar_enable_icon_blink(&wgui_status_icon_bar_icons[icon_id], MMI_TRUE);
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
#if (defined(__MMI_FTE_SUPPORT__) && defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
        if(icon_id >= STATUS_ICON_MAINLCD_START && icon_id < STATUS_ICON_MAINLCD_END)
        {
            if(!wgui_status_icon_bar_whether_icon_real_display(icon_id))
            {
                wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].new_icon_id = icon_id;
            }
        }
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2) */

    wgui_status_icon_bar_update();
    wgui_status_icon_bar_setup_blink_animate();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_set_icon_flag
 * DESCRIPTION
 *  Set status icon's flag
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 *  flag            [IN]    New flag of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_set_icon_flag(S32 icon_id, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((icon_id < 0) || (icon_id >= MAX_STATUS_ICONS))
    {
        return;
    }
    gui_status_icon_bar_set_icon_flag(&wgui_status_icon_bar_icons[icon_id], flag);
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_get_icon_flag
 * DESCRIPTION
 *  Get status icon's flag
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  void
 *****************************************************************************/
U32 wgui_status_icon_bar_get_icon_flag(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_status_icon_bar_get_icon_flag(&wgui_status_icon_bar_icons[icon_id]);
}

/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_get_icon_area
 * DESCRIPTION
 *  Get status icon's flag
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_status_icon_bar_get_icon_area(S32 icon_id, S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    S32 i;
    gui_status_icon_bar_struct *bar;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    bar = &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR];
    if (icon_id >= STATUS_ICON_MAINLCD_LEFT_REGION_START && icon_id < STATUS_ICON_MAINLCD_LEFT_REGION_END)
    {
        for(i = 0; i < bar->n_icons; i++)
        {
            if(bar->icon_list[i] == icon_id)
            {
                break;
            }
        }
        if(i == bar->n_icons)
        {
            for(i = 0; i < bar->n_all_events; i++)
            {
                if(bar->all_show_events[i] == icon_id)
                {
                    break;
                }
            }
            if(i == bar->n_all_events)
            {
                return MMI_FALSE;
            }
            else
            {
                *x1 = wgui_status_icon_bar_icons[STATUS_ICON_LEFT_HIDE].x;
                *x2 = wgui_status_icon_bar_icons[STATUS_ICON_LEFT_HIDE].x + wgui_status_icon_bar_icons[STATUS_ICON_LEFT_HIDE].width - 1;
                *y1 = wgui_status_icon_bar_icons[STATUS_ICON_LEFT_HIDE].y;
                *y2 = wgui_status_icon_bar_icons[STATUS_ICON_LEFT_HIDE].y + wgui_status_icon_bar_icons[STATUS_ICON_LEFT_HIDE].height - 1;
                return MMI_TRUE;
            }
        }
    }
#endif
    return gui_status_icon_bar_get_icon_area(&wgui_status_icon_bar_icons[icon_id], x1, y1, x2, y2);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_whether_icon_display
 * DESCRIPTION
 *  To check whether icon display or not
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  MMI_TRUE    :   The status icon display
 *  MMI_FALSE   :   The status icon not display
 *****************************************************************************/
MMI_BOOL wgui_status_icon_bar_whether_icon_display(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_status_icon_bar_whether_icon_display(&wgui_status_icon_bar_icons[icon_id]);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_whether_icon_real_display
 * DESCRIPTION
 *  To check whether icon real display or not
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  MMI_TRUE    :   The status icon genuine display
 *  MMI_FALSE   :   The status icon not display
 *****************************************************************************/
MMI_BOOL wgui_status_icon_bar_whether_icon_real_display(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    gui_status_icon_bar_struct *bar;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(gui_status_icon_bar_whether_icon_display(&wgui_status_icon_bar_icons[icon_id]))
    {
        for(j = 0; j < WGUI_STATUS_ICON_BAR_TOTAL_BAR; j++)
        {
            bar = &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR + j];
            for(i = 0; i < bar->n_icons; i++)
            {
                if((bar->icon_list[i] == icon_id) || 
                    ((wgui_status_icon_bar_icons[icon_id].group != GUI_STATUS_ICON_BAR_ICON_NO_GROUP) && (wgui_status_icon_bar_icons[bar->icon_list[i]].group == wgui_status_icon_bar_icons[icon_id].group)))
                {
                    return MMI_TRUE;
                }
            }
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_change_icon_level
 * DESCRIPTION
 *  Change status icon level, usually for battery or signal to change strength
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 *  level           [IN]    The new level of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_change_icon_level(S32 icon_id, S32 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((icon_id < 0) || (icon_id >= MAX_STATUS_ICONS))
    {
        return;
    }
#if defined(__GGT_TASK__)
#if defined(__OLED_BW_MMI__)
	if((icon_id == STATUS_ICON_SIGNAL_STRENGTH)||(icon_id == STATUS_ICON_BATTERY_STRENGTH))
	{
		mmi_idle_set_status_status(KAL_TRUE);
		if(icon_id == STATUS_ICON_SIGNAL_STRENGTH)
		{
		}
		else if(icon_id == STATUS_ICON_BATTERY_STRENGTH)
		{
		}
		else
		{
			
		}
	}
#endif /* __OLED_BW_MMI__ */
#endif

#ifdef __OP01_3G__
    if ((icon_id == STATUS_ICON_SIGNAL_STRENGTH)
        ||(icon_id == STATUS_ICON_SUBLCD_SIGNAL_STRENGTH)
    #if (defined(__MMI_DUAL_SIM_MASTER__) || (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2)))
        ||(icon_id == STATUS_ICON_SLAVE_SIGNAL_STRENGTH)
        ||(icon_id == STATUS_ICON_SUBLCD_SLAVE_SIGNAL_STRENGTH)
    #endif    
    #if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
        ||(icon_id == STATUS_ICON_SIM3_SIGNAL_STRENGTH)
    #endif
    #if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 4))
        ||(icon_id == STATUS_ICON_SIM4_SIGNAL_STRENGTH)
    #endif
    )
    {
        if(level == 0)
        {
            wgui_status_icon_bar_icons[icon_id].state = 0;
        }
        else
        {
            wgui_status_icon_bar_icons[icon_id].state = 
                (level * (wgui_status_icon_bar_icons[icon_id].n_frames - 1)) / 100 + 1;
            if(wgui_status_icon_bar_icons[icon_id].state < 0)
            {
                wgui_status_icon_bar_icons[icon_id].state = 0;
            }
            else if(wgui_status_icon_bar_icons[icon_id].state >= wgui_status_icon_bar_icons[icon_id].n_frames)
            {
                wgui_status_icon_bar_icons[icon_id].state = wgui_status_icon_bar_icons[icon_id].n_frames - 1;
            }
        }
    }
    else
#endif /* __OP01_3G__ */
    {
        gui_status_icon_bar_change_icon_level(&wgui_status_icon_bar_icons[icon_id], level);
    }
#if (defined(__MMI_FTE_SUPPORT__) && defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    if(icon_id >= STATUS_ICON_MAINLCD_START && icon_id < STATUS_ICON_MAINLCD_END)
    {
        if((!wgui_status_icon_bar_whether_icon_real_display(icon_id)) && 
            (wgui_status_icon_bar_whether_icon_display(icon_id)))
        {
            wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].new_icon_id = icon_id;
        }
    }
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3) */

    if ((icon_id == STATUS_ICON_SIGNAL_STRENGTH) 
        ||(icon_id == STATUS_ICON_BATTERY_STRENGTH)
    #if (defined(__MMI_DUAL_SIM_MASTER__) || (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3)))
        ||(icon_id == STATUS_ICON_SLAVE_SIGNAL_STRENGTH)
    #endif    
    #if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
        ||(icon_id == STATUS_ICON_SIM3_SIGNAL_STRENGTH)
    #endif
    #if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 4))
        ||(icon_id == STATUS_ICON_SIM4_SIGNAL_STRENGTH)
    #endif
        )
    {
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
        if (!(wgui_status_icon_bar_get_flag(WGUI_STATUS_ICON_BAR_H_BAR) & WGUI_STATUS_ICON_BAR_FLAG_BAR_DISPLAY) &&
            wgui_status_icon_bar_integrated_enable)
        {
            if (wgui_status_icon_bar_integrated_redraw)
            {
                wgui_status_icon_bar_integrated_redraw();
            }
        }
        else
#endif
        {
            wgui_status_icon_bar_update();
        }
    }

#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3) && !defined(__COSMOS_MMI_PACKAGE__))
    wgui_cat9010_update_status_icon(icon_id);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_get_icon_frame_number
 * DESCRIPTION
 *  Change status icon level, usually for battery or signal to change strength
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  void
 *****************************************************************************/
S32 wgui_status_icon_bar_get_icon_frame_number(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_icon_struct *icon;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    icon = &wgui_status_icon_bar_icons[icon_id];
    return gui_status_icon_bar_get_icon_frame_number(icon);
}



/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_change_icon_image
 * DESCRIPTION
 *  Change status icon image
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 *  image_id        [IN]    New image of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_change_icon_image(S32 icon_id, S32 image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((icon_id < 0) || (icon_id >= MAX_STATUS_ICONS))
    {
        return;
    }
    gui_status_icon_bar_change_icon_image(&wgui_status_icon_bar_icons[icon_id], image_id);
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
#if (defined(__MMI_FTE_SUPPORT__) && defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    if(icon_id >= STATUS_ICON_MAINLCD_START && icon_id < STATUS_ICON_MAINLCD_END)
    {
        if((!wgui_status_icon_bar_whether_icon_real_display(icon_id)) && 
            (wgui_status_icon_bar_whether_icon_display(icon_id)))
        {
            wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].new_icon_id = icon_id;
        }
    }
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2) */
    wgui_status_icon_bar_update();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_change_icon_image_ex
 * DESCRIPTION
 *  Change status icon image
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 *  image_data       [IN]    New image of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_change_icon_image_ex(S32 icon_id, PU8 image_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((icon_id < 0) || (icon_id >= MAX_STATUS_ICONS))
    {
        return;
    }
    gui_status_icon_bar_change_icon_image_ex(&wgui_status_icon_bar_icons[icon_id], image_data);
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
#if (defined(__MMI_FTE_SUPPORT__) && defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    if(icon_id >= STATUS_ICON_MAINLCD_START && icon_id < STATUS_ICON_MAINLCD_END)
    {
        if((!wgui_status_icon_bar_whether_icon_real_display(icon_id)) && 
            (wgui_status_icon_bar_whether_icon_display(icon_id)))
        {
            wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].new_icon_id = icon_id;
        }
    }
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2) */
    wgui_status_icon_bar_update();
}



/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_get_icon_image_id
 * DESCRIPTION
 *  Get status icon image id
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  The image id of status icon
 *****************************************************************************/
S32 wgui_status_icon_bar_get_icon_image_id(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_status_icon_bar_get_icon_image_id(&wgui_status_icon_bar_icons[icon_id]);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_get_integrated_icon_size
 * DESCRIPTION
 *  Get the status icon's size for integrated title
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 *  width           [OUT]   Pointer to restore the width of status icon
 *  height          [OUT]   Pointer to restore the height of status icon
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
void wgui_status_icon_bar_get_integrated_icon_size(S32 icon_id, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    if (!(wgui_status_icon_bar_get_flag(WGUI_STATUS_ICON_BAR_H_BAR) & WGUI_STATUS_ICON_BAR_FLAG_BAR_DISPLAY) &&
        (wgui_status_icon_bar_integrated_enable))
    {
        gui_status_icon_bar_get_icon_size(
            &wgui_status_icon_bar_icons[icon_id],
            width,
            height);
    }
    else
#endif
    {
        *width = 0;
        *height = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_show_integrated_icon
 * DESCRIPTION
 *  Show status icon for integrated title
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 *  x               [IN]    X coordinate of show
 *  y               [IN]    Y coordinate of show
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_show_integrated_icon(S32 icon_id, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    if (!(wgui_status_icon_bar_get_flag(WGUI_STATUS_ICON_BAR_H_BAR) & WGUI_STATUS_ICON_BAR_FLAG_BAR_DISPLAY) &&
        (wgui_status_icon_bar_integrated_enable))
    {
        gui_status_icon_bar_show_integrated_icon(
            &wgui_status_icon_bar_icons[icon_id],
            x,
            y);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_register_integrated_redraw
 * DESCRIPTION
 *  Register redraw status icon bar redraw function for integrated
 * PARAMETERS
 *  redraw          [IN]    The new redraw function of integrated title
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_register_integrated_redraw(void (*redraw)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_status_icon_bar_integrated_enable)
    {
        wgui_status_icon_bar_integrated_redraw = redraw;
    }
    else if(redraw == NULL)
    {
        wgui_status_icon_bar_integrated_redraw = NULL;
    }
}


/*****************************************************************************
* FUNCTION
*  wgui_status_icon_bar_is_register_integrated_redraw
* DESCRIPTION
*  To check the integrated redraw be register or not
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL wgui_status_icon_bar_is_register_integrated_redraw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_status_icon_bar_integrated_redraw)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_integrated_enable
 * DESCRIPTION
 *  Enable integrated title or not
 * PARAMETERS
 *  enable          [IN]    Enable integrated title or not
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_enable_integrated(MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_integrated_enable = enable;
    if (wgui_status_icon_bar_integrated_enable)
    {
        if (wgui_status_icon_bar_whether_have_blink_or_animate_icon())
        {
            gui_start_timer(WGUI_STATUS_ICON_BAR_TIMER_RATE, wgui_status_icon_bar_icon_blink_and_animate_timer_callback);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_whether_integrated_enable
 * DESCRIPTION
 *  To check integrated title enable or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_status_icon_bar_whether_integrated_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_status_icon_bar_integrated_enable;
}

#endif /*#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE*/

#ifdef __MMI_TOUCH_SCREEN__

#if (defined(__MMI_STATUS_ICONBAR_COSMOS_STYLE__) || defined(__MMI_NCENTER_SUPPORT__)) 
static MMI_BOOL wgui_status_icon_bar_enable_pen_event = MMI_TRUE;
#else
static MMI_BOOL wgui_status_icon_bar_enable_pen_event = MMI_FALSE;
#endif
static FuncPtr wgui_status_icon_bar_pen_event_handler[MAX_STATUS_ICONS][WGUI_STATUS_ICON_BAR_PEN_EVENT_MAX];
static S32 wgui_status_icon_bar_pen_icon_id = STATUS_ICON_INVALID_ID;
#ifdef __MMI_TOUCH_SCREEN__
static FuncPtr wgui_status_icon_bar_tap_handler;
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_register_pen_event_handler
 * DESCRIPTION
 *  Register status icon's pen event handler
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 *  event_type      [IN]    The pen event of handler
 *  f               [IN]    The pointer of register handler
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_register_pen_event_handler(
        S32 icon_id,
        wgui_status_icon_bar_pen_enum event_type,
        FuncPtr handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_pen_event_handler[icon_id][event_type] = handler;
#ifdef __LOW_COST_SUPPORT_COMMON__
    if(event_type == WGUI_STATUS_ICON_BAR_PEN_LONG_PRESS_ICON)
    {
        wgui_status_icon_bar_pen_event_handler[icon_id][WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON] = handler;
    }
#endif
    wgui_status_icon_bar_enable_pen_event = MMI_TRUE;
}

#if (defined(__MMI_STATUS_ICONBAR_COSMOS_STYLE__) || defined(__MMI_NCENTER_SUPPORT__)) 
/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_register_pen_event_handler
 * DESCRIPTION
 *  Register status icon's pen event handler
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 *  event_type      [IN]    The pen event of handler
 *  f               [IN]    The pointer of register handler
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_register_tap_proc(FuncPtr handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_tap_handler = handler;
}
#endif /* defined(__MMI_STATUS_ICONBAR_COSMOS_STYLE__) || defined(__MMI_NCENTER_SUPPORT__) */



/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset_all_pen_event_handler
 * DESCRIPTION
 *  Reset all icon's pen event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_reset_all_pen_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 icon_id;
    S32 event_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (icon_id = 0; icon_id < MAX_STATUS_ICONS; icon_id++)
    {
        for (event_index = 0; event_index < WGUI_STATUS_ICON_BAR_PEN_EVENT_MAX; event_index++)
        {
            wgui_status_icon_bar_pen_event_handler[icon_id][event_index] = NULL;
        }
    }
    wgui_status_icon_bar_enable_pen_event = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_execute_pen_event_handler
 * DESCRIPTION
 *  Execute the icon's pen event handler
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 *  event_type      [IN]    The pen event type
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_status_icon_bar_execute_pen_event_handler(S32 icon_id, wgui_status_icon_bar_pen_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_status_icon_bar_pen_event_handler[icon_id][event_type] != NULL)
    {
        wgui_status_icon_bar_pen_event_handler[icon_id][event_type]();
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

#if (defined(__MMI_STATUS_ICONBAR_COSMOS_STYLE__) || defined(__MMI_NCENTER_SUPPORT__))

/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_abort_enter_ncenter
 * DESCRIPTION
 *  Set the flag of entering ncenter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_abort_enter_ncenter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 flags;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    flags = wgui_status_icon_bar_get_flag(WGUI_STATUS_ICON_BAR_H_BAR);
    flags |= WGUI_STATUS_ICON_BAR_FLAG_BAR_ABORT_ENTER_NCENTER;
    wgui_status_icon_bar_set_flag(WGUI_STATUS_ICON_BAR_H_BAR, flags);
}

extern void vapp_ncenter_entry(void* bar);
// can't find the path
//#include "venusmmi\app\cosmos\ncenter\Vapp_ncenter.h"
/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_tap_proc
 * DESCRIPTION
 *  Execute the icon's pen tap proc
 * PARAMETERS
 *  para         [IN]    The parameter of event
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret wgui_status_icon_bar_tap_proc(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 flags;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_status_icon_bar_tap_handler != NULL)
    {
        wgui_status_icon_bar_tap_handler();
        return MMI_TRUE;
    }
    else
    {
        flags = wgui_status_icon_bar_get_flag(WGUI_STATUS_ICON_BAR_H_BAR);
        if(flags & WGUI_STATUS_ICON_BAR_FLAG_BAR_ABORT_ENTER_NCENTER)
        {
            flags &= ~WGUI_STATUS_ICON_BAR_FLAG_BAR_ABORT_ENTER_NCENTER;
            wgui_status_icon_bar_set_flag(WGUI_STATUS_ICON_BAR_H_BAR, flags);
            return MMI_TRUE;
        }
        else
        {
#ifdef __MMI_VUI_ENGINE__
            vapp_ncenter_entry(NULL);
#endif
            return MMI_FALSE;
        }
    }
}
#endif /* defined(__MMI_STATUS_ICONBAR_COSMOS_STYLE__) || defined(__MMI_NCENTER_SUPPORT__) */


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_translate_pen_position
 * DESCRIPTION
 *  Translate the pen event position to icon's id
 * PARAMETERS
 *  x           [IN]    x coordinate of pen event
 *  y           [IN]    y coordinate of pen event
 * RETURNS
 *  Id of status icon to reponse the pen event
 *****************************************************************************/
static S32 wgui_status_icon_bar_translate_pen_position(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_STATUS_ICONBAR_COSMOS_STYLE__ )
    S32 i;
    S32 icon_id;
#endif
    S32 x1, y1, x2, y2;
    wgui_status_icon_bar_enum bar_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_STATUS_ICONBAR_COSMOS_STYLE__ )
    for (bar_id = WGUI_STATUS_ICON_BAR_H_BAR; bar_id < WGUI_STATUS_ICON_BAR_TOTAL_BAR; bar_id++)
    {
        if ((wgui_status_icon_bar_bars[bar_id].flags & WGUI_STATUS_ICON_BAR_FLAG_BAR_DISPLAY) &&
            (wgui_status_icon_bar_bars[bar_id].icon_list != NULL))
        {
            x1 = wgui_status_icon_bar_bars[bar_id].x1;
            y1 = wgui_status_icon_bar_bars[bar_id].y1;
            x2 = wgui_status_icon_bar_bars[bar_id].x2;
            y2 = wgui_status_icon_bar_bars[bar_id].y2;
            if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
            {
               return MAX_STATUS_ICONS + bar_id;
            }
        }
    }
    return STATUS_ICON_INVALID_ID;
#else
    for (bar_id = WGUI_STATUS_ICON_BAR_H_BAR; bar_id < WGUI_STATUS_ICON_BAR_TOTAL_BAR; bar_id++)
    {
        if ((wgui_status_icon_bar_bars[bar_id].flags & WGUI_STATUS_ICON_BAR_FLAG_BAR_DISPLAY) &&
            (wgui_status_icon_bar_bars[bar_id].icon_list != NULL))
        {
            x1 = wgui_status_icon_bar_bars[bar_id].x1;
            y1 = wgui_status_icon_bar_bars[bar_id].y1;
            x2 = wgui_status_icon_bar_bars[bar_id].x2;
            y2 = wgui_status_icon_bar_bars[bar_id].y2;
            if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
            {
#ifdef __MMI_NCENTER_SUPPORT__
                if(wgui_status_icon_bar_bars[bar_id].info_state != WGUI_STATUS_ICON_BAR_INFO_HIDE)
                {
                    return MAX_STATUS_ICONS + bar_id;
                }
#endif 
                for (i = 0; i < wgui_status_icon_bar_bars[bar_id].n_icons; i++)
                {
                    icon_id = wgui_status_icon_bar_bars[bar_id].icon_list[i];
                    if (((wgui_status_icon_bar_icons[icon_id].flags & GUI_STATUS_ICON_BAR_ICON_DISPLAY) ||
                        (wgui_status_icon_bar_icons[icon_id].flags & GUI_STATUS_ICON_BAR_ICON_BLINK) ||
                        (wgui_status_icon_bar_icons[icon_id].flags & GUI_STATUS_ICON_BAR_ICON_ANIMATE))
                        && (wgui_status_icon_bar_icons[icon_id].image_id != IMAGE_ID_NULL))
                    {
                        x1 = wgui_status_icon_bar_bars[bar_id].x + wgui_status_icon_bar_icons[icon_id].x;
                        x2 = x1 + wgui_status_icon_bar_icons[icon_id].width - 1;
                        y1 = wgui_status_icon_bar_bars[bar_id].y + wgui_status_icon_bar_icons[icon_id].y;
                        y2 = y1 + wgui_status_icon_bar_icons[icon_id].height - 1;
                        if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
                        {
                            return icon_id;
                        }
                    }
#ifdef __MMI_NCENTER_SUPPORT__
                            return MAX_STATUS_ICONS + bar_id;
                            
#endif
                }
            }
        }
    }
    return STATUS_ICON_INVALID_ID;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_translate_pen_event
 * DESCRIPTION
 *  Translate pen event of status icon bar
 * PARAMETERS
 *  pen_event       [IN]    The pen event of response by status icon bar
 *  x               [IN]    X coordinate of pen event
 *  y               [IN]    Y coordinate of pen event
 *  icon_id         [OUT]   Pointer to restore the icon id of response the pen event
 *  event_type      [OUT]   Pointer to restoe the status icon bar's event
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_status_icon_bar_translate_pen_event(
            mmi_pen_event_type_enum pen_event,
            S32 x,
            S32 y,
            S32 *icon_id,
            wgui_status_icon_bar_pen_enum *event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_wait_longpress_enum w;
#if (defined(__MMI_STATUS_ICONBAR_COSMOS_STYLE__) || defined(__MMI_NCENTER_SUPPORT__))
    mmi_event_struct evt;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *event_type = WGUI_STATUS_ICON_BAR_PEN_NONE;
    *icon_id = STATUS_ICON_INVALID_ID;

    if (wgui_status_icon_bar_enable_pen_event == MMI_FALSE)
    {
        return MMI_FALSE;
    }

    if (wgui_status_icon_bar_pen_icon_id < 0 && pen_event != MMI_PEN_EVENT_DOWN)
    {
        return MMI_FALSE;
    }

    if (pen_event == MMI_PEN_EVENT_DOWN || pen_event == MMI_PEN_EVENT_UP)
    {
        wgui_status_icon_bar_pen_icon_id = wgui_status_icon_bar_translate_pen_position(x, y);
        if (wgui_status_icon_bar_pen_icon_id < 0)
        {
            return MMI_FALSE;
        }
    }
    if(wgui_status_icon_bar_pen_icon_id < MAX_STATUS_ICONS)
    {
    *icon_id = wgui_status_icon_bar_pen_icon_id;
    if (wgui_status_icon_bar_pen_event_handler[wgui_status_icon_bar_pen_icon_id][WGUI_STATUS_ICON_BAR_PEN_LONG_PRESS_ICON] != NULL)
    {
        w = gui_pen_wait_longpress(pen_event, (S16)x, (S16)y);
        if (w == GUI_WAIT_LONGPRESS_READY)
        {
         #ifndef __LOW_COST_SUPPORT_COMMON__
            *event_type = WGUI_STATUS_ICON_BAR_PEN_LONG_PRESS_ICON;
         #else
            *event_type = WGUI_STATUS_ICON_BAR_PEN_NONE;
         #endif
        }
    }
    }
    if(pen_event == MMI_PEN_EVENT_UP)
    {
        if(wgui_status_icon_bar_pen_icon_id >= MAX_STATUS_ICONS)
        {
            if(wgui_status_icon_bar_tap_handler != NULL)
            {
                wgui_status_icon_bar_tap_handler();
            }
        }
        else if(*event_type == WGUI_STATUS_ICON_BAR_PEN_NONE)
    {
        if (wgui_status_icon_bar_pen_icon_id == wgui_status_icon_bar_translate_pen_position(x, y))
        {
            *event_type = WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON;
        }
    }
    }
#if (defined(__MMI_STATUS_ICONBAR_COSMOS_STYLE__) || defined(__MMI_NCENTER_SUPPORT__))
    else if(pen_event == MMI_PEN_EVENT_MOVE)
    {
        if(wgui_status_icon_bar_pen_icon_id >= MAX_STATUS_ICONS && y > wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].y2)
    {
#ifdef __MMI_VUI_ENGINE__
            vapp_ncenter_entry(NULL);
            wgui_status_icon_bar_pen_icon_id = STATUS_ICON_INVALID_ID;
#endif
        }
    }
#endif
    return MMI_TRUE;
}

#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_show_sublcd_background
 * DESCRIPTION
 *  Displays the SUBLCD background screen
 * PARAMETERS
 *  start_x             [IN]        Left top position
 *  start_y             [IN]        Left top position
 *  end_x               [IN]        Right bottom position
 *  end_y               [IN]        Right bottom position
 *  is_status_bar       [IN]        Is status bar to draw or not.
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__ 
void wgui_status_icon_bar_show_sublcd_background(S32 x1, S32 y1, S32 x2, S32 y2, U8 is_status_bar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* draw all screen of background display. */

    if (!is_status_bar)
    {
    #if defined(__MMI_SUBLCD_COLOR__)
        y1 = (U16) Sub_lcd_title_height;
    #endif
    }

    if(gui_status_icon_bar_show_sublcd_horizontal_background)
    {
        gui_status_icon_bar_show_sublcd_horizontal_background(x1, y1, x2, y2);
    }
}
#endif

/*****************************************************************************
 * Element functions
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_create_element
 * DESCRIPTION
 *  Create a element
 * PARAMETERS
 *  width       [IN]    The width of element
 *  height      [IN]    The height of element
 *  show        [IN]    The show function of element
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef WGUI_STATUS_ICON_SHOW_ELEMENT 
S32 wgui_status_icon_bar_create_element(S32 width, S32 height, void(* show)(S32 x1, S32 y1, S32 x2, S32 y2), U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    gui_status_icon_bar_struct *bar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Only support element in mainlcd horizontal status icon bar currently,
    if want to support in sublcd horizontal status icon bar,should be process
    the element range in arrange function*/
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
    bar = &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR];
    for (i = 0; i < WGUI_STATUS_ICON_BAR_ELEMENT_NUM; i++)
    {
        if (wgui_status_icon_bar_elements[i].active == MMI_FALSE)
        {
            gui_status_icon_bar_create_element(
                &wgui_status_icon_bar_elements[i],
                width,
                height,
                show,
                flag);
            bar->element_list[bar->n_elements] = i;
            bar->n_elements++;
            return i;
        }
    }

    return WGUI_STATUS_ICON_BAR_INVALID_ELEMENT_ID;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_resize_element
 * DESCRIPTION
 *  Resize the element
 * PARAMETERS
 *  element_id          [IN]    The id of element
 *  width               [IN]    The new width of element
 *  height              [IN]    The new height of element
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_resize_element(S32 element_id, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (element_id < 0)
    {
        return;
    }
    MMI_ASSERT(element_id < WGUI_STATUS_ICON_BAR_ELEMENT_NUM);
    gui_status_icon_bar_resize_element(&wgui_status_icon_bar_elements[element_id], width, height);
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_register_element_show
 * DESCRIPTION
 *  Register element's show function
 * PARAMETERS
 *  element_id          [IN]    The id of element
 *  show                [IN]    New show function of element
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_register_element_show(S32 element_id, void (*show)(S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (element_id < 0)
    {
        return;
    }
    MMI_ASSERT(element_id < WGUI_STATUS_ICON_BAR_ELEMENT_NUM);
    gui_status_icon_bar_register_element_show(&wgui_status_icon_bar_elements[element_id], show);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_close_element
 * DESCRIPTION
 *  Close the element
 * PARAMETERS
 *  element_id         [IN]    The id of element
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_close_element(S32 element_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_struct *bar;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (element_id < 0)
    {
        return;
    }    
    MMI_ASSERT(element_id < WGUI_STATUS_ICON_BAR_ELEMENT_NUM);
    gui_status_icon_bar_close_element(&wgui_status_icon_bar_elements[element_id]);
    bar = &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR];

    for (i = 0; i < bar->n_elements; i++)
    {
        if (bar->element_list[i] == element_id)
        {
            break;
        }
    }

    for (; i < bar->n_elements - 1; i++)
    {
        bar->element_list[i] = bar->element_list[i + 1];
    }
    bar->n_elements--;
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
}

#endif /* #ifdef WGUI_STATUS_ICON_SHOW_ELEMENT*/

#if (defined(__MMI_STATUS_ICONBAR_COSMOS_STYLE__) || defined(__MMI_NCENTER_SUPPORT__))
/*****************************************************************************
 * <group dom_status_icon_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_status_icon_bar_show_info_ex
 * DESCRIPTION
 *  Set the information shown in status icon bar
 * PARAMETERS
 *  icon_image       : [IN]    The image data with 8 byte header
 *  string          : [IN]    The string of information
 *  count           : [IN]    Timer duration in ms
 *  param          : [IN]    Paramter of callback
 * call_back       : [IN]    Call back function after show information
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_status_icon_bar_show_info_int(PU8 icon_image, UI_string_type string, S32 count, void* param, void(*call_back)(status_icon_bar_info_enum, void*))
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_struct *bar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bar = &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR];
    bar->previous_state = bar->info_state;
    bar->info_state = WGUI_STATUS_ICON_BAR_INFO_FADE_IN;
    bar->info_icon_image = icon_image;
    bar->info_string = string;
    bar->count = count;
    bar->fade_step = 0;
    bar->info_callback = call_back;
    wgui_status_icon_bar_update();
}

/*****************************************************************************
 * <group dom_status_icon_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_status_icon_bar_show_info_ex
 * DESCRIPTION
 *  Set the information shown in status icon bar
 * PARAMETERS
 *  icon_image       : [IN]    The image data with 8 byte header
 *  string          : [IN]    The string of information
 *  count           : [IN]    Timer duration in ms
 *  param          : [IN]    Paramter of callback
 * call_back       : [IN]    Call back function after show information
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_show_info_ex(PU8 icon_image, UI_string_type string, S32 count, void* param, void(*call_back)(status_icon_bar_info_enum, void*))
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_struct *bar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bar = &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR];
    bar->info_icon_type = WGUI_STATUS_ICON_BAR_ICON_TYPE_RESOURCE;
    wgui_status_icon_bar_show_info_int(icon_image, string, count, param, call_back);
}

/*****************************************************************************
 * <group dom_status_icon_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_status_icon_bar_show_info
 * DESCRIPTION
 *  Set the information shown in status icon bar
 * PARAMETERS
 *  icon_id         : [IN]    The icon of information
 *  string          : [IN]    The string of information
 *  count           : [IN]    Timer duration in ms
 *  param          : [IN]    Paramter of callback
 * call_back       : [IN]    Call back function after show information
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_show_info(S32 icon_id, UI_string_type string, S32 count, void* param, void(*call_back)(status_icon_bar_info_enum, void*))
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_struct *bar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bar = &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR];
    bar->info_icon_type = WGUI_STATUS_ICON_BAR_ICON_TYPE_RESOURCE;
    wgui_status_icon_bar_show_info_int(get_image(icon_id), string, count, param, call_back);

}

/*****************************************************************************
 * <group dom_status_icon_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_status_icon_bar_show_info_file
 * DESCRIPTION
 *  Set the information shown in status icon bar
 * PARAMETERS
 *  icon_file         : [IN]    The icon file path of information
 *  string          : [IN]    The string of information
 *  count           : [IN]    Timer duration in ms
 *  param          : [IN]    Paramter of callback
 * call_back       : [IN]    Call back function after show information
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_show_info_file(S8 *icon_file, UI_string_type string, S32 count, void* param, void(*call_back)(status_icon_bar_info_enum, void*))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_struct *bar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bar = &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR];
    bar->info_icon_type = WGUI_STATUS_ICON_BAR_ICON_TYPE_FILE;
    wgui_status_icon_bar_show_info_int((PU8)icon_file, string, count, param, call_back);
    
}

/*****************************************************************************
 * <group dom_status_icon_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_status_icon_bar_show_info_mem
 * DESCRIPTION
 *  Set the information shown in status icon bar
 * PARAMETERS
 *  icon_image       : [IN]    The image data without 8 byte header
 *  image_size       : [IN]     Image size
 *  image_format     : [IN]    image format
 *  string          : [IN]    The string of information
 *  count           : [IN]    Timer duration in ms
 *  param          : [IN]    Paramter of callback
 * call_back       : [IN]    Call back function after show information
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_show_info_mem(PU8 icon_image, S32 image_size, U8 image_format, UI_string_type string, S32 count, void* param, void(*call_back)(status_icon_bar_info_enum, void*))
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_struct *bar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bar = &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR];
    bar->info_icon_size = image_size;
    bar->info_icon_type = WGUI_STATUS_ICON_BAR_ICON_TYPE_MEM;
    bar->info_icon_format = image_format;
    wgui_status_icon_bar_show_info_int(icon_image, string, count, param, call_back);
}

#endif /* defined(__MMI_STATUS_ICONBAR_COSMOS_STYLE__) || defined(__MMI_NCENTER_SUPPORT__) */

#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
/*****************************************************************************
 * <group dom_status_icon_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_status_icon_bar_hide_events
 * DESCRIPTION
 *  Set the information shown in status icon bar
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_hide_events(void)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_struct *bar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bar = &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR];
    if(bar->info_state == WGUI_STATUS_ICON_BAR_INFO_HIDE)
    {
        bar->info_state = WGUI_STATUS_ICON_BAR_EVENTS_HIDE;
    }
    else
    {
        bar->previous_state = WGUI_STATUS_ICON_BAR_EVENTS_HIDE;
    }
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
    wgui_status_icon_bar_update();
}


/*****************************************************************************
 * <group dom_status_icon_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_status_icon_bar_show_events
 * DESCRIPTION
 *  Set the information shown in status icon bar
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_show_events(void)

{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_struct *bar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bar = &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR];
    if(bar->info_state == WGUI_STATUS_ICON_BAR_EVENTS_HIDE)
    {
        bar->info_state = WGUI_STATUS_ICON_BAR_INFO_HIDE;
    }
    else
    {
        bar->previous_state = WGUI_STATUS_ICON_BAR_INFO_HIDE;
    }
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
    wgui_status_icon_bar_update();
}


/*****************************************************************************
 * <group dom_status_icon_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_status_icon_bar_enter_ncenter
 * DESCRIPTION
 *  Set the information shown in status icon bar
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_enter_ncenter(void)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_hide_events();
    wgui_inNCenter = MMI_TRUE;
}



/*****************************************************************************
 * <group dom_status_icon_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_status_icon_bar_enter_ncenter
 * DESCRIPTION
 *  Set the information shown in status icon bar
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_leave_ncenter(void)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inNCenter = MMI_FALSE;
    wgui_status_icon_bar_show_events();
}


/*****************************************************************************
 * <group dom_status_icon_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_status_icon_bar_enter_ncenter
 * DESCRIPTION
 *  Set the information shown in status icon bar
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_status_icon_bar_is_in_ncenter(void)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_inNCenter;
}

/*****************************************************************************
 * <group dom_status_icon_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_status_icon_bar_enter_ncenter
 * DESCRIPTION
 *  Set the information shown in status icon bar
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_freeze_animate(MMI_BOOL bFreeze)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_freeze = bFreeze;
    if (!bFreeze)
    {
        wgui_status_icon_bar_setup_blink_animate();
    }
}

/*****************************************************************************
 * <group dom_status_icon_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_status_icon_bar_hide_bar
 * DESCRIPTION
 *  Set the information shown in status icon bar
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_hide_bar(MMI_BOOL bHide)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_is_hide = bHide;
}
#endif /* __MMI_STATUS_ICONBAR_COSMOS_STYLE__ */

/*****************************************************************************
 * <group dom_status_icon_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_status_icon_bar_show_warning_info
 * DESCRIPTION
 *  Show warning info at left area of status icon bar
 * PARAMETERS
 *  string          : [IN]    The string of information
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_show_warning_info(UI_string_type warning_string)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_struct *bar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_status_icon_bar_warning_mode = MMI_TRUE;
    bar = &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR];
    bar->warning_info_string = warning_string;
    wgui_status_icon_bar_update();
}
/*****************************************************************************
 * <group dom_status_icon_wgui_layer_property_setting>
 * FUNCTION
 *  wgui_status_icon_bar_hide_warning_info
 * DESCRIPTION
 *  Show warning info at left area of status icon bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_hide_warning_info(void)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_struct *bar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_status_icon_bar_warning_mode = MMI_FALSE;
    bar = &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR];
    bar->warning_info_string = NULL;
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
    wgui_status_icon_bar_update();
}

/*****************************************************************************
 * Partial function
 ****************************************************************************/
#ifdef __MMI_LCD_PARTIAL_ON__

#define WGUI_STATUS_ICON_BAR_PARTIAL_POOL_NUM (sizeof(wgui_status_icon_bar_partial_display_pool)/sizeof(wgui_status_icon_bar_partial_display_pool[1]))
const S16 wgui_status_icon_bar_partial_display_pool[] =
{
    STATUS_ICON_INCOMING_SMS,
#ifdef __MMI_DUAL_SIM_MASTER__
    STATUS_ICON_SLAVE_INCOMING_SMS,
#endif /* __MMI_DUAL_SIM_MASTER__ */

    #ifdef __MMI_MMS_2__
    STATUS_ICON_MMS_UNREAD,
    #endif

#ifdef __MMI_DUAL_SIM_MASTER__
#ifndef __MMI_STATUS_ICON_BAR_SLIM__ 
    STATUS_ICON_MMS_UNREAD_SIM_1,
    STATUS_ICON_MMS_UNREAD_SIM_2,
#endif    
#endif  /* __MMI_DUAL_SIM_MASTER__ */

    STATUS_ICON_MISSED_CALL,

    #ifdef __MMI_EMAIL__
    STATUS_ICON_UNREAD_EMAIL,
    #endif

#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__

    STATUS_ICON_UNREAD_VOICE,
    STATUS_ICON_UNREAD_SIM_EMAIL,
    STATUS_ICON_UNREAD_NET,
    STATUS_ICON_UNREAD_VIDEO,
#else /* __MMI_STATUS_ICONBAR_COSMOS_STYLE__ */

#ifdef __MMI_NCENTER_SUPPORT__
    STATUS_ICON_UNREAD_VOICE,
#ifndef __MMI_STATUS_ICON_BAR_SLIM__             
    STATUS_ICON_UNREAD_FAX,
    STATUS_ICON_UNREAD_EMAIL_MSG,
    STATUS_ICON_UNREAD_NET,
    STATUS_ICON_UNREAD_VIDEO,
#endif    
#elif (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    #ifdef __MMI_SLIM_IMG_RES__
    STATUS_ICON_UNREAD_VOICE_MASTER,
    STATUS_ICON_UNREAD_VOICE_SLAVE, 
    STATUS_ICON_UNREAD_VOICE_SIM3,
    STATUS_ICON_UNREAD_VOICE_SIM4,
#ifndef __MMI_STATUS_ICON_BAR_SLIM__         
    STATUS_ICON_UNREAD_FAX_MASTER,
    STATUS_ICON_UNREAD_FAX_SLAVE, 
    STATUS_ICON_UNREAD_FAX_SIM3,
    STATUS_ICON_UNREAD_FAX_SIM4,

    STATUS_ICON_UNREAD_EMAIL_MASTER,
    STATUS_ICON_UNREAD_EMAIL_SLAVE, 
    STATUS_ICON_UNREAD_EMAIL_SIM3,
    STATUS_ICON_UNREAD_EMAIL_SIM4,

    STATUS_ICON_UNREAD_NET_MASTER,
    STATUS_ICON_UNREAD_NET_SLAVE, 
    STATUS_ICON_UNREAD_NET_SIM3,
    STATUS_ICON_UNREAD_NET_SIM4,

    STATUS_ICON_UNREAD_VIDEO_MASTER,
    STATUS_ICON_UNREAD_VIDEO_SLAVE, 
    STATUS_ICON_UNREAD_VIDEO_SIM3,
    STATUS_ICON_UNREAD_VIDEO_SIM4,
#endif    
    #else
    STATUS_ICON_UNREAD_VOICE_L1_MASTER,
    STATUS_ICON_UNREAD_VOICE_L2_MASTER,
    STATUS_ICON_UNREAD_VOICE_L1L2_MASTER,
    STATUS_ICON_UNREAD_VOICE_L1_SLAVE,
    STATUS_ICON_UNREAD_VOICE_L2_SLAVE,
    STATUS_ICON_UNREAD_VOICE_L1L2_SLAVE,
    STATUS_ICON_UNREAD_VOICE_L1_SIM3,
    STATUS_ICON_UNREAD_VOICE_L2_SIM3,
    STATUS_ICON_UNREAD_VOICE_L1L2_SIM3,
    STATUS_ICON_UNREAD_VOICE_L1_SIM4,
    STATUS_ICON_UNREAD_VOICE_L2_SIM4,
    STATUS_ICON_UNREAD_VOICE_L1L2_SIM4,
#ifndef __MMI_STATUS_ICON_BAR_SLIM__         
    STATUS_ICON_UNREAD_FAX_L1_MASTER,
    STATUS_ICON_UNREAD_FAX_L2_MASTER,
    STATUS_ICON_UNREAD_FAX_L1L2_MASTER,
    STATUS_ICON_UNREAD_FAX_L1_SLAVE,
    STATUS_ICON_UNREAD_FAX_L2_SLAVE,
    STATUS_ICON_UNREAD_FAX_L1L2_SLAVE,
    STATUS_ICON_UNREAD_FAX_L1_SIM3,
    STATUS_ICON_UNREAD_FAX_L2_SIM3,
    STATUS_ICON_UNREAD_FAX_L1L2_SIM3,
    STATUS_ICON_UNREAD_FAX_L1_SIM4,
    STATUS_ICON_UNREAD_FAX_L2_SIM4,
    STATUS_ICON_UNREAD_FAX_L1L2_SIM4,

    STATUS_ICON_UNREAD_EMAIL_L1_MASTER,
    STATUS_ICON_UNREAD_EMAIL_L2_MASTER,
    STATUS_ICON_UNREAD_EMAIL_L1L2_MASTER,
    STATUS_ICON_UNREAD_EMAIL_L1_SLAVE,
    STATUS_ICON_UNREAD_EMAIL_L2_SLAVE,
    STATUS_ICON_UNREAD_EMAIL_L1L2_SLAVE,
    STATUS_ICON_UNREAD_EMAIL_L1_SIM3,
    STATUS_ICON_UNREAD_EMAIL_L2_SIM3,
    STATUS_ICON_UNREAD_EMAIL_L1L2_SIM3,
    STATUS_ICON_UNREAD_EMAIL_L1_SIM4,
    STATUS_ICON_UNREAD_EMAIL_L2_SIM4,
    STATUS_ICON_UNREAD_EMAIL_L1L2_SIM4,

    STATUS_ICON_UNREAD_NET_L1_MASTER,
    STATUS_ICON_UNREAD_NET_L2_MASTER,
    STATUS_ICON_UNREAD_NET_L1L2_MASTER,
    STATUS_ICON_UNREAD_NET_L1_SLAVE,
    STATUS_ICON_UNREAD_NET_L2_SLAVE,
    STATUS_ICON_UNREAD_NET_L1L2_SLAVE,
    STATUS_ICON_UNREAD_NET_L1_SIM3,
    STATUS_ICON_UNREAD_NET_L2_SIM3,
    STATUS_ICON_UNREAD_NET_L1L2_SIM3,
    STATUS_ICON_UNREAD_NET_L1_SIM4,
    STATUS_ICON_UNREAD_NET_L2_SIM4,
    STATUS_ICON_UNREAD_NET_L1L2_SIM4,

    STATUS_ICON_UNREAD_VIDEO_L1_MASTER,
    STATUS_ICON_UNREAD_VIDEO_L2_MASTER,
    STATUS_ICON_UNREAD_VIDEO_L1L2_MASTER,
    STATUS_ICON_UNREAD_VIDEO_L1_SLAVE,
    STATUS_ICON_UNREAD_VIDEO_L2_SLAVE,
    STATUS_ICON_UNREAD_VIDEO_L1L2_SLAVE,
    STATUS_ICON_UNREAD_VIDEO_L1_SIM3,
    STATUS_ICON_UNREAD_VIDEO_L2_SIM3,
    STATUS_ICON_UNREAD_VIDEO_L1L2_SIM3,
    STATUS_ICON_UNREAD_VIDEO_L1_SIM4,
    STATUS_ICON_UNREAD_VIDEO_L2_SIM4,
    STATUS_ICON_UNREAD_VIDEO_L1L2_SIM4,
#endif
    #endif
#else

    #ifdef __MMI_SLIM_IMG_RES__
    STATUS_ICON_UNREAD_VOICE,
#ifndef __MMI_STATUS_ICON_BAR_SLIM__
    STATUS_ICON_UNREAD_FAX,
    STATUS_ICON_UNREAD_EMAIL_MSG,
    STATUS_ICON_UNREAD_NET,
    STATUS_ICON_UNREAD_VIDEO,
#endif    
    #else
    STATUS_ICON_UNREAD_VOICE_L1L2,
    STATUS_ICON_UNREAD_VOICE_L1,
    STATUS_ICON_UNREAD_VOICE_L2,
#ifndef __MMI_STATUS_ICON_BAR_SLIM__    
    STATUS_ICON_UNREAD_EMAIL_L1L2,
    STATUS_ICON_UNREAD_EMAIL_L1,
    STATUS_ICON_UNREAD_EMAIL_L2,
    STATUS_ICON_UNREAD_NET_L1,
    STATUS_ICON_UNREAD_NET_L2,
    STATUS_ICON_UNREAD_NET_L1L2,
    STATUS_ICON_UNREAD_VIDEO_L1,
    STATUS_ICON_UNREAD_VIDEO_L2,
    STATUS_ICON_UNREAD_VIDEO_L1L2,
#endif    
    #endif

#ifdef __MMI_DUAL_SIM_MASTER__
#ifndef __MMI_SLIM_IMG_RES__
    STATUS_ICON_UNREAD_VOICE_L1_MASTER,
    STATUS_ICON_UNREAD_VOICE_L2_MASTER,
    STATUS_ICON_UNREAD_VOICE_L1L2_MASTER,
#ifndef __MMI_STATUS_ICON_BAR_SLIM__        
    STATUS_ICON_UNREAD_FAX_L1_MASTER,
    STATUS_ICON_UNREAD_FAX_L2_MASTER,
    STATUS_ICON_UNREAD_FAX_L1L2_MASTER,
    STATUS_ICON_UNREAD_EMAIL_L1_MASTER,
    STATUS_ICON_UNREAD_EMAIL_L2_MASTER,
    STATUS_ICON_UNREAD_EMAIL_L1L2_MASTER,
    STATUS_ICON_UNREAD_NET_L1_MASTER,
    STATUS_ICON_UNREAD_NET_L2_MASTER,
    STATUS_ICON_UNREAD_NET_L1L2_MASTER,
    STATUS_ICON_UNREAD_VIDEO_L1_MASTER,
    STATUS_ICON_UNREAD_VIDEO_L2_MASTER,
    STATUS_ICON_UNREAD_VIDEO_L1L2_MASTER,
#endif
    STATUS_ICON_UNREAD_VOICE_L1_SLAVE,
    STATUS_ICON_UNREAD_VOICE_L2_SLAVE,
    STATUS_ICON_UNREAD_VOICE_L1L2_SLAVE,
#ifndef __MMI_STATUS_ICON_BAR_SLIM__            
    STATUS_ICON_UNREAD_FAX_L1_SLAVE,
    STATUS_ICON_UNREAD_FAX_L2_SLAVE,
    STATUS_ICON_UNREAD_FAX_L1L2_SLAVE,
    STATUS_ICON_UNREAD_EMAIL_L1_SLAVE,
    STATUS_ICON_UNREAD_EMAIL_L2_SLAVE,
    STATUS_ICON_UNREAD_EMAIL_L1L2_SLAVE,
    STATUS_ICON_UNREAD_NET_L1_SLAVE,
    STATUS_ICON_UNREAD_NET_L2_SLAVE,
    STATUS_ICON_UNREAD_NET_L1L2_SLAVE,
    STATUS_ICON_UNREAD_VIDEO_L1_SLAVE,
    STATUS_ICON_UNREAD_VIDEO_L2_SLAVE,
    STATUS_ICON_UNREAD_VIDEO_L1L2_SLAVE,
#endif    
#endif
#endif  /*__MMI_DUAL_SIM_MASTER__*/
#endif
#endif /* __MMI_STATUS_ICONBAR_COSMOS_STYLE__ */


#ifdef __MMI_AUTO_ANSWER_MACHINE__
    STATUS_ICON_AUTOAM_REC,
    STATUS_ICON_AUTOAM_UNREAD,
#endif /* __MMI_AUTO_ANSWER_MACHINE__ */

#ifdef __MMI_IMPS__
/* under construction !*/
#endif

#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    STATUS_ICON_PROVMSG_STATE,
#else
#ifndef __MMI_STATUS_ICON_BAR_SLIM__ 
    STATUS_ICON_PROVMSG_STATE,
//#ifdef __MMI_DUAL_SIM_MASTER__
//    STATUS_ICON_PROVMSG_SIM1,
//    STATUS_ICON_PROVMSG_SIM2,
//#endif    
#endif
#endif

    #ifdef WAP_SUPPORT
//#ifndef __MMI_STATUS_ICON_BAR_SLIM__ //kavin_modify_for_slim_status    
//    STATUS_ICON_WAP1,
//    STATUS_ICON_WAP2,
//#endif    
    STATUS_ICON_WAP
    #endif

};


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_arrange_partial
 * DESCRIPTION
 *  Arrange status icon for partial display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_arrange_partial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 j = 0; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_partial_display_icon_number = 0;
    while (i < WGUI_STATUS_ICON_BAR_PARTIAL_POOL_NUM)
    {
        j = wgui_status_icon_bar_partial_display_pool[i];
        if (GUI_STATUS_ICON_BAR_ICON_DISPLAY_ON(wgui_status_icon_bar_icons[j].flags))
        {
            wgui_status_icon_bar_partial_list_display[wgui_status_icon_bar_partial_display_icon_number] = j;
            wgui_status_icon_bar_partial_display_icon_number++;
            if (wgui_status_icon_bar_partial_display_icon_number >= WGUI_STATUS_ICON_BAR_PARTIAL_ICON_LIST_NUM)
            {
                break;
            }
        }
        i++;
    }
}


#endif /* __MMI_LCD_PARTIAL_ON__ */


