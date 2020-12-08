/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_hs_widget_cfg.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget configuration file
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
#ifndef __VAPP_HS_WIDGET_CFG_H__
#define __VAPP_HS_WIDGET_CFG_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "ui_core\base\vfx_base.h"
#include "vfx_datatype.h"
#include "mmi_rp_app_venus_homescreen_wg_operator_name_def.h"
#include "mmi_rp_app_venus_homescreen_wg_date_def.h"
#include "mmi_rp_app_venus_homescreen_wg_calendar_def.h"
#include "mmi_rp_app_venus_homescreen_wg_snow_def.h"
#include "mmi_rp_app_venus_homescreen_wg_photo_def.h"
#include "mmi_rp_app_venus_homescreen_wg_memo_def.h"
#include "mmi_rp_app_venus_homescreen_wg_audioplayer_def.h"
#include "mmi_rp_app_venus_homescreen_wg_fmradio_def.h"
#include "mmi_rp_app_venus_homescreen_wg_pet_def.h"
#include "mmi_rp_app_venus_homescreen_wg_clock_def.h"
#include "mmi_rp_app_venus_hs_wg_baidu_def.h"
#include "mmi_rp_app_venus_homescreen_wg_profile_def.h"
#include "mmi_rp_app_venus_homescreen_wg_next_alarm_def.h"
#include "mmi_rp_app_venus_homescreen_wg_event_inbox_def.h"
#include "mmi_rp_app_venus_homescreen_wg_mre_def.h"
#include "mmi_rp_app_venus_hs_todo_def.h"
#include "mmi_rp_app_venus_hs_wg_bkm_def.h"
#include "mmi_rp_app_venus_homescreen_wg_mobile_internet_def.h"
#include "mmi_rp_app_venus_homescreen_wg_wo_store_def.h"


/***************************************************************************** 
 * Widget include
 *****************************************************************************/

#if defined(WIDGET_DEFINE_IN_CFG)

#include "vapp_hs_widget_date.h"
#include "vapp_hs_widget_calendar.h"
#include "vapp_hs_widget_snow.h"
#include "vapp_hs_widget_photo.h"
#include "vapp_hs_widget_memo.h"
#include "vapp_hs_widget_audplayer.h"
#include "vapp_hs_widget_fmradio.h"
#include "vapp_hs_widget_pet.h"
#include "vapp_hs_widget_baidu_search.h"
#include "vapp_hs_widget_profile.h"
#include "vapp_hs_widget_operator_name.h"
#include "vapp_hs_widget_next_alarm.h"
#include "vapp_hs_widget_event_inbox.h"
#include "vapp_hs_widget_mre.h"
#include "vapp_hs_widget_todo.h"
#include "vapp_hs_widget_clock.h"
#include "vapp_hs_widget_bookmark.h"
#include "Vapp_hs_widget_op02.h"

#define VAPP_HS_WIDGET_TABLE    static const vapp_hs_widget_cfg_struct g_vapp_hs_widget_create_tbl[] =

#define VAPP_HS_NEW_WIDGET(_class, _icon, _name, _attr)     \
    {                                                       \
        VAPP_HS_WIDGET_ENUM_##_class,                       \
        _icon,                                              \
        _name,                                              \
        _attr,                                              \
        _class##::createWidget                              \
    }

#define VAPP_HS_WIDGET_LAST_ITEM
#define VAPP_HS_WIDGET_TOTAL        (sizeof(g_vapp_hs_widget_create_tbl) / sizeof(vapp_hs_widget_cfg_struct))

#else /* defined(WIDGET_DEFINE_IN_CFG) */

#define VAPP_HS_WIDGET_ATTR_NULL            (0)
#define VAPP_HS_WIDGET_ATTR_NEED_NETWORK    (1 < 0)

typedef void *(*vapp_hs_widget_create_cb)(void *parentObj);

typedef struct
{
    VfxS32                      id;
    VfxU16                      icon;
    VfxU16                      name;
    VfxU32                      attr;
    vapp_hs_widget_create_cb    create;
} vapp_hs_widget_cfg_struct;

#define VAPP_HS_WIDGET_TABLE        enum
#define VAPP_HS_NEW_WIDGET(_class, _icon, _name, _attr)  VAPP_HS_WIDGET_ENUM_##_class
#define VAPP_HS_WIDGET_LAST_ITEM    VAPP_HS_WIDGET_TOTAL        

#endif /* defined(WIDGET_DEFINE_IN_CFG) */


/***************************************************************************** 
 * Widget table
 *****************************************************************************/

VAPP_HS_WIDGET_TABLE
{
    // register widget here
#if defined(__MMI_VUI_HOMESCREEN_OPERATOR_NAME__)
    VAPP_HS_NEW_WIDGET(
        VappHsWidgetOperatorName,
        VAPP_HS_IMG_WG_ICON_OPERATOR_NAME,
        VAPP_HS_STR_WG_OPERATOR_NAME,
        VAPP_HS_WIDGET_ATTR_NULL),
#endif /* defined(__MMI_VUI_HOMESCREEN_OPERATOR_NAME__) */

#if defined(__MMI_VUI_HOMESCREEN_DATE__)
    VAPP_HS_NEW_WIDGET(
        VappHsWidgetDate,
        VAPP_HS_IMG_WG_ICON_DATE,
        VAPP_HS_STR_WG_DATE,
        VAPP_HS_WIDGET_ATTR_NULL),
#endif /* defined(__MMI_VUI_HOMESCREEN_DATE__) */

#if defined(__MMI_VUI_HOMESCREEN_CALENDAR__)
    VAPP_HS_NEW_WIDGET(
        VappHsWidgetCalendar,
        VAPP_HS_IMG_WG_ICON_CALENDAR,
        VAPP_HS_STR_WG_CALENDAR,
        VAPP_HS_WIDGET_ATTR_NULL),
#endif /* defined(__MMI_VUI_HOMESCREEN_CALENDAR__) */
    
#if defined(__MMI_VUI_HOMESCREEN_SNOW__)
    VAPP_HS_NEW_WIDGET(
        VappHsWidgetSnow,
        VAPP_HS_IMG_WG_ICON_SNOW,
        VAPP_HS_STR_WG_SNOW,
        VAPP_HS_WIDGET_ATTR_NULL),
#endif /* defined(__MMI_VUI_HOMESCREEN_SNOW__) */

#ifdef __MMI_VUI_HOMESCREEN_PHOTO__
    VAPP_HS_NEW_WIDGET(
        VappHsWidgetPhoto,
        VAPP_HS_IMG_WG_ICON_PHOTO,
        VAPP_HS_STR_WG_PHOTO,
        VAPP_HS_WIDGET_ATTR_NULL),
#endif /* __MMI_VUI_HOMESCREEN_PHOTO__ */   

#if defined(__MMI_VUI_HOMESCREEN_MEMO__)
    VAPP_HS_NEW_WIDGET(
        VappHsWidgetMemo,
        VAPP_HS_IMG_WG_ICON_MEMO,
        VAPP_HS_STR_WG_MEMO,
        VAPP_HS_WIDGET_ATTR_NULL),
#endif /* defined(__MMI_VUI_HOMESCREEN_MEMO__) */

#ifdef __MMI_VUI_HOMESCREEN_AUDIO_PLAYER__    
    VAPP_HS_NEW_WIDGET(
        VappHsWidgetAudplayer,
        VAPP_HS_IMG_WG_ICON_AUDPLY,
        VAPP_HS_STR_WG_AUDIO_PLAYER,
        VAPP_HS_WIDGET_ATTR_NULL),
#endif /* __MMI_VUI_HOMESCREEN_AUDIO_PLAYER__ */

#ifdef __MMI_VUI_HOMESCREEN_FM_RADIO__    
    VAPP_HS_NEW_WIDGET(
        VappHsWidgetFmr,
        VAPP_HS_IMG_WG_ICON_FMR,
        VAPP_HS_STR_WG_FM_RADIO,
        VAPP_HS_WIDGET_ATTR_NULL),
#endif /* __MMI_VUI_HOMESCREEN_FM_RADIO__ */   

#ifdef __MMI_VUI_HOMESCREEN_PET__
    VAPP_HS_NEW_WIDGET(
        VappHsWidgetPet,
        VAPP_HS_IMG_WG_ICON_PET,
        VAPP_HS_STR_WG_PET,
        VAPP_HS_WIDGET_ATTR_NULL),
#endif /* __MMI_VUI_HOMESCREEN_PET__ */   

#if defined(__MMI_VUI_HOMESCREEN_CLOCK__)
    VAPP_HS_NEW_WIDGET(
        VappHsWidgetClock,
        VAPP_HS_IMG_WG_ICON_CLOCK,
        VAPP_HS_STR_WG_CLOCK,
        VAPP_HS_WIDGET_ATTR_NULL),
#endif /* defined(__MMI_VUI_HOMESCREEN_CLOCK__) */

#ifdef __MMI_VUI_HOMESCREEN_BAIDU_SEARCH__
    VAPP_HS_NEW_WIDGET(
        VappHsWidgetBaiduSearch,
        VAPP_HS_IMG_WG_BAIDU_SEARCH,
        VAPP_HS_STR_WG_BAIDU_SEARCH_TITLE,
        VAPP_HS_WIDGET_ATTR_NEED_NETWORK),
#endif /* __MMI_VUI_HOMESCREEN_BAIDU_SEARCH__ */

#ifdef __MMI_VUI_HOMESCREEN_PROFILE__
    VAPP_HS_NEW_WIDGET(
        VappHsWidgetProfile,
        VAPP_HS_IMG_WG_ICON_PROFILE,
        VAPP_HS_STR_WG_PROFILE,
        VAPP_HS_WIDGET_ATTR_NULL),
#endif /* __MMI_VUI_HOMESCREEN_PROFILE__ */   

#if defined(__MMI_VUI_HOMESCREEN_NEXT_ALARM__)
    VAPP_HS_NEW_WIDGET(
        VappHsWidgetNextAlarm,
        VAPP_HS_IMG_WG_ICON_NEXT_ALARM,
        VAPP_HS_STR_WG_NEXT_ALARM,
        VAPP_HS_WIDGET_ATTR_NULL),
#endif /* defined(__MMI_VUI_HOMESCREEN_NEXT_ALARM__) */

#if defined(__MMI_VUI_HOMESCREEN_EVENT_INBOX__)
    VAPP_HS_NEW_WIDGET(
        VappHsWidgetEventInbox,
        VAPP_HS_IMG_WG_ICON_EVENT_INBOX,
        VAPP_HS_STR_WG_EVENT_INBOX,
        VAPP_HS_WIDGET_ATTR_NULL),
#endif /* defined(__MMI_VUI_HOMESCREEN_EVENT_INBOX__) */

#ifdef __MMI_VUI_HOMESCREEN_MRE_LINK__
    VAPP_HS_NEW_WIDGET(
        VappHsWidgetVre,
        VAPP_HS_IMG_WG_ICON_MRE,
        VAPP_HS_STR_WG_MRE,
        VAPP_HS_WIDGET_ATTR_NULL),
#endif /* __MMI_VUI_HOMESCREEN_MRE_LINK__ */

#ifdef __MMI_VUI_HOMESCREEN_TODO__
    VAPP_HS_NEW_WIDGET(
        VappHsWidgetTodo,
        VAPP_HS_IMG_WG_ICON_TODO,
        VAPP_HS_STR_WG_TODO,
        VAPP_HS_WIDGET_ATTR_NULL),
#endif /* __MMI_VUI_HOMESCREEN_TODO__ */

#ifdef __MMI_VUI_HOMESCREEN_BOOKMARK__
    VAPP_HS_NEW_WIDGET(
        VappHsWidgetBookmark,
        VAPP_HS_IMG_WG_ICON_BOOKMARK,
        VAPP_HS_STR_WG_BOOKMARKS,
        VAPP_HS_WIDGET_ATTR_NULL),
#endif /* __MMI_VUI_HOMESCREEN_BOOKMARK__ */   
        
#ifdef __MMI_VUI_HOMESCREEN_WO_STORE__
    VAPP_HS_NEW_WIDGET(
        VappHsWidgetWoStore,
        VAPP_HS_IMG_WG_ICON_WO_STORE,
        VAPP_HS_STR_WG_WO_STORE,
        VAPP_HS_WIDGET_ATTR_NULL),
#endif /* __MMI_VUI_HOMESCREEN_WO_STORE__ */
        
#ifdef __MMI_VUI_HOMESCREEN_MOBILE_INTERNET__
    VAPP_HS_NEW_WIDGET(
        VappHsWidgetMobileInternet,
        VAPP_HS_IMG_WG_ICON_MOBILE_INTERNET,
        VAPP_HS_STR_WG_MOBILE_INTERNET,
        VAPP_HS_WIDGET_ATTR_NULL),
#endif /* __MMI_VUI_HOMESCREEN_MOBILE_INTERNET__ */ 
        
    VAPP_HS_WIDGET_LAST_ITEM
};

/***************************************************************************** 
 * External interface
 *****************************************************************************/

// This function returns the pointer to the i-th device shortcut configuration.
// RETURNS: the pointer to the shortcut configuration table.
extern const vapp_hs_widget_cfg_struct *vapp_hs_get_widget_cfg_table(void);

#endif /* __MMI_VUI_HOMESCREEN__ */
#endif /* __VAPP_HS_WIDGET_CFG_H__ */

