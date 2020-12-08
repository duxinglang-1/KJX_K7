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
 *  vapp_setting_wallpaper_type_def_gprot.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_SETTING_WALLPAPER_TYPE_DEF_GPROT_H__
#define __VAPP_SETTING_WALLPAPER_TYPE_DEF_GPROT_H__
/***************************************************************************** 
 * Include
 *****************************************************************************/
//#include "mmi_features.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifndef	MMI_WP_THEME_NUM
#define MMI_WP_THEME_NUM 1
#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum 
{
    VAPP_WALLPAPER_HOME_SCREEN,
    VAPP_WALLPAPER_LOCK_SCREEN,
//    VAPP_WALLPAPER_MAIN_MENU,

//#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
    VAPP_VIDEO_PWR_ON_SCREEN,    
    VAPP_VIDEO_PWR_OFF_SCREEN,
//#endif
    
    VAPP_WALLPAPER_TYPE_END
    
} VappWallpaperType;

typedef enum
{
    VAPP_WALLPAPER_STATIC_WALLPAPER,
    VAPP_WALLPAPER_LIVE_WALLPAPER,
//#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
    VAPP_WALLPAPER_VIDEO_WALLPAPER,
//#endif
    VAPP_WALLPAPER_USER_FILE,

    VAPP_WALLPAPER_RESOURCE_TYPE_END
} VappWpResType;

typedef enum
{
    VAPP_WALLPAPER_SETTING_NO_ERROR,
    VAPP_WALLPAPER_SETTING_DISK_SIZE_NOT_ENOUGH,
    VAPP_WALLPAPER_SETTING_COPY_FILE_FAIL,
    VAPP_WALLPAPER_SETTING_FILE_LIMIT_CHECK_FAIL,
    VAPP_WALLPAPER_SETTING_DRM_CHECK_FAIL,
    VAPP_WALLPAPER_SETTING_UNSUPPORT_FORMAT,
    VAPP_WALLPAPER_SETTING_FILE_IS_NOT_EXSIT,
    // Internal used
    VAPP_WALLPAPER_SETTING_DELETE_FILE_FAIL,
    VAPP_WALLPAPER_SETTING_OPEN_FILE_FAIL,
    VAPP_WALLPAPER_SETTING_EMPTY_FILE,    
    VAPP_WALLPAPER_SETTING_PREPARE_FOLDER_FAIL,
    VAPP_WALLPAPER_SETTING_GET_DISK_INFO_FAIL     
} VappWpSetErrorCode;
#endif /*__VAPP_SETTING_WALLPAPER_TYPE_DEF_GPROT_H__*/
