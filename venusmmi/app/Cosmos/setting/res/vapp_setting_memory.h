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
 *  Vapp_setting_memory.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_SETTING_MEMORY_H__
#define __VAPP_SETTING_MEMORY_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "Mmi_features.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__MMI_THEMES_APPLICATION__)|| defined(__MMI_VUI_APP_ICON_ROBOT__) || defined(__MMI_VUI_APP_ICON_MM__) || defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__)\
			 || defined(__MMI_VUI_SETTING_LAUNCHER_SELECTION__) || defined(__MMI_VUI_SETTING_SCREEN_LOCK_SELECTION__)
    #ifndef __MMI_SETTING_THEME_SETTINGS__
	#define __MMI_SETTING_THEME_SETTINGS__
	#endif
#endif

#if defined(__LOW_COST_SUPPORT_COMMON__)
/* HEAP */
#define VAPP_MOBILE_NETWORK_SETTINGS_HEAP    (150 * 1024)

#define VAPP_CALL_SETTINGS_HEAP (250 *1024)

#define VAPP_CONTACT_SETTINGS_HEAP (0 * 1024)

#define VAPP_MESSAGE_SETTINGS_HEAP (150 * 1024)

#else

/* HEAP */
#define VAPP_MOBILE_NETWORK_SETTINGS_HEAP    (400 * 1024)

#define VAPP_CALL_SETTINGS_HEAP (500 *1024)

#define VAPP_CONTACT_SETTINGS_HEAP (400 * 1024)

#define VAPP_MESSAGE_SETTINGS_HEAP (400 * 1024)

#endif

/* MAX HEAP MEMORY CONFIG */
#define VAPP_SETTINGS_MAX_HEAP (max(max(max(VAPP_MOBILE_NETWORK_SETTINGS_HEAP, VAPP_CALL_SETTINGS_HEAP), VAPP_CONTACT_SETTINGS_HEAP), VAPP_MESSAGE_SETTINGS_HEAP))

#if defined(__MMI_MAINLCD_320X480__)
    enum
    {
        ICON_MAX_WIDTH    = 46,
        ICON_MAX_HEIGHT    = 46 
    };
#elif defined(__MMI_MAINLCD_480X800__)
    enum
    {
        ICON_MAX_WIDTH    = 72,
        ICON_MAX_HEIGHT    = 72        
    };
#else
    enum
    {
        ICON_MAX_WIDTH    = 36,  
        ICON_MAX_HEIGHT    = 36   
    };
#endif       


#if !defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__)
/* CUI */
#define SETTINGS_MAX_COMMON_UI_MEMORY "max(max(max(max(max(max(max(VCUI_GALLERY_WALLPAPER_PICKER, (VCUI_GALLERY_IMAGE_PICKER + VCUI_WALLPAPER_SETTING)), VAPP_CALLSET), VAPP_THEME),VCUI_DATA_ACCOUNT_WLAN_SETTING),VCUI_MOBILE_NW_SETTING),VAPP_LAUNCHER_SETTING),VAPP_SCR_LOCK_SETTING)"

/* CUI FOR WALLPAPER*/
#define DLWP_SETTING_MAX_UI_MEMORY "max(VCUI_GALLERY_WALLPAPER_PICKER, (VCUI_GALLERY_IMAGE_PICKER + VCUI_WALLPAPER_SETTING))"

/* EXTRA BASE */
#define VAPP_SETTINGS_MAX_EXTRA_BASE "0+$(SRV_CLOUD_ASM_SIZE)"

/* FG MEMORY */
#define VAPP_SETTINGS_MAX_FG_MEMORY  "0"

#else
/* CUI */
#define SETTINGS_MAX_COMMON_UI_MEMORY "max(max(max(max(max(max(max(max(VCUI_GALLERY_WALLPAPER_PICKER, VCUI_GALLERY_VIDEO_PICKER), (VCUI_GALLERY_IMAGE_PICKER + VCUI_WALLPAPER_SETTING)), VAPP_CALLSET), VAPP_THEME),VCUI_DATA_ACCOUNT_WLAN_SETTING),VCUI_MOBILE_NW_SETTING),VAPP_LAUNCHER_SETTING),VAPP_SCR_LOCK_SETTING)"

/* CUI FOR WALLPAPER*/
#define DLWP_SETTING_MAX_UI_MEMORY "max(max(VCUI_GALLERY_WALLPAPER_PICKER, VCUI_GALLERY_VIDEO_PICKER), (VCUI_GALLERY_IMAGE_PICKER + VCUI_WALLPAPER_SETTING))"

/* EXTRA BASE */
#define VAPP_SETTINGS_MAX_EXTRA_BASE "(ICON_MAX_WIDTH*ICON_MAX_HEIGHT*4+100)+$(SRV_CLOUD_ASM_SIZE)"

/* FG MEMORY */
#define VAPP_SETTINGS_MAX_FG_MEMORY  "fg(SRV_MDI_VDOPLY_MP4)"

#endif /* !defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__) */


#endif /* __VAPP_SETTING_MEMORY_H__ */
 
