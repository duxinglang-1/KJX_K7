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
 *  vapp_wallpaper_def.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen wallpaper enum 
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_WALLPAPER_DEF_H__
#define __VAPP_WALLPAPER_DEF_H__

#include "MMI_features.h"

/***************************************************************************** 
 * C-style API for PLUTO compatibility
 *****************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "FileMgrSrvGprot.h"    // SRV_FMGR_SYSTEM_DRV


/*****************************************************************************
 * Define
 *****************************************************************************/


/* Path of the wallpaper archive archive. 
   Capital 'Z' in Path means the primary system drive
   If this path is changed, you must also change
   LIVE_WALLPAPER_SETTING_FOLDER in
   custom\common\custom_nvram_config.c
   custom\common\fs_quota.c
   so that factory setting can be properly restored.
*/
#define VAPP_WALLPAPER_ARCHIVE_DRIVE      'Z'
#define VAPP_WALLPAPER_ARCHIVE_PATH       "@wallpaper"

/* Extension of file in the wallpaper archive. */
#define VAPP_WALLPAPER_ARCHIVE_FILE_EXT   "bin"

/* File to store wallpaper system's setting. */
#define VAPP_WALLPAPER_SYS_ARCHIVE_FILE   "system"

/* Maximum length of wallpaper name */
#define VAPP_WALLPAPER_MAX_NAME_LEN (30)

/* Use factory mechanism*/
#define __MMI_VUI_WALLPAPER_FACTORY__

/*****************************************************************************
 * Enum
 *****************************************************************************/

/*
 * Wallpaper Factory Source:
 */
typedef enum
{
    VAPP_WALLPAPER_FACTORY_NATIVE,      // Native code liave wallpaper, e.g. Wildworld, Chipset
    VAPP_WALLPAPER_FACTORY_IMAGE,       // Native image wallpaper, e.g. resource images
    VAPP_WALLPAPER_FACTORY_VIDEO,       // Native video wallpaper, e.g. resource videos
    VAPP_WALLPAPER_FACTORY_FILE,        // File-based wallpaper, e.g. MWP/LWP wallpapers
    VAPP_WALLPAPER_FACTORY_MRE,         // MRE wallpapers
    VAPP_WALLPAPER_FACTORY_USERFILE,    // User image/video wallpaper, e.g. MAV file wallpapers
    VAPP_WALLPAPER_FACTORY_LAST_ITEM,
    VAPP_WALLPAPER_FACTORY_UNKNOWN = VAPP_WALLPAPER_FACTORY_LAST_ITEM,
} VappWallpaperFactorySrcEnum;


/*
 * Wallpaper AP Source:
 */
typedef enum
{
    VAPP_WALLPAPER_SRC_HOMESCREEN,
    VAPP_WALLPAPER_SRC_LOCK,
    VAPP_WALLPAPER_SRC_LAST_ITEM,
} VappWallpaperSrcEnum;


#ifdef __cplusplus
}
#endif

#endif  //__VAPP_WALLPAPER_DEF_H__

