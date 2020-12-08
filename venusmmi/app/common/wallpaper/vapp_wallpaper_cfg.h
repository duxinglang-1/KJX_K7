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
 *  vapp_wallpaper_cfg.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen wallpaper configuration file
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef __VAPP_WALLPAPER_CFG_H__
#define __VAPP_WALLPAPER_CFG_H__

#include "MMI_features.h"

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vfx_datatype.h"

#if defined(WALLPAPER_DEFINE_IN_CFG)
#include "vfx_base.h"

/* RHR start */
#include "vapp_wallpaper.h"
/* RHR end */
#endif

/*****************************************************************************
 * Wallpaper include
 *****************************************************************************/

#if defined(WALLPAPER_DEFINE_IN_CFG)

#include "vapp_wallpaper_wide.h"

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WAVE__
#include "vapp_wallpaper_wave.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_CHIPSET__
#include "vapp_wallpaper_chipset.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_COMET__
#include "vapp_wallpaper_comet.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_FIREFLY__
#include "vapp_wallpaper_firefly.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MATRIX__
#include "vapp_wallpaper_matrix.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPACE__
#include "vapp_wallpaper_space.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPANGLE__
#include "vapp_wallpaper_spangle.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WILDWORLD__
#include "vapp_wallpaper_wildworld.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_MIMOSA__
    #include "vapp_wallpaper_mimosa.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_GIRL__
    #include "vapp_wallpaper_girl.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_CLOCK__
    #include "vapp_wallpaper_clock.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_HORSE__
    #include "vapp_wallpaper_horse.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_DAYDREAM__
    #include "vapp_wallpaper_daydream.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_LIGHTHOUSE__
    #include "vapp_wallpaper_lighthouse.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_PUPPY__
    #include "vapp_wallpaper_puppy.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_SOLAR__
    #include "vapp_wallpaper_solar.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_FISH__
    #include "vapp_wallpaper_fish.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_TRANSFORMER__
    #include "vapp_wallpaper_transformer.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
    #include "vapp_wallpaper_video.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SAKURA__
    #include "vapp_wallpaper_sakura.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_EARTH__
#include "vapp_wallpaper_3d_earth.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_WAVE__
#include "vapp_wallpaper_3d_wave.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO__
    #include "vapp_wallpaper_frame_video.h"
    #include "vapp_wallpaper_interactive_video.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV__
    #include "vapp_wallpaper_mav.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_SAKURA__
#include "vapp_wallpaper_3d_sakura.h"
#endif

#ifdef __MMI_VUI_WALLPAPER_MRE__
#include "vapp_wallpaper_mre.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_MAPLE__
#include "vapp_wallpaper_3d_maple.h"
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_CASSIA__
#include "vapp_wallpaper_3d_cassia.h"
#endif

#define VAPP_WALLPAPER_TABLE    static const vapp_wallpaper_cfg_struct g_vapp_wallpaper_create_tbl[] =

#define VAPP_NEW_WALLPAPER(_class)           \
    {                                           \
        VAPP_WALLPAPER_ID(_class),           \
        _class##::createWallpaper               \
    }

#define VAPP_WALLPAPER_LAST_ITEM
#define VAPP_WALLPAPER_TOTAL        (sizeof(g_vapp_wallpaper_create_tbl) / sizeof(vapp_wallpaper_cfg_struct))

#else /* defined(WALLPAPER_DEFINE_IN_CFG) */

typedef void *(*vapp_wallpaper_create_cb)(void *parentObj);

typedef struct
{
    VfxS32                          id;
    vapp_wallpaper_create_cb     create;
} vapp_wallpaper_cfg_struct;

#define VAPP_WALLPAPER_TABLE        enum
#define VAPP_NEW_WALLPAPER(_class)  VAPP_WALLPAPER_ENUM_##_class
#define VAPP_WALLPAPER_LAST_ITEM    VAPP_WALLPAPER_TOTAL

#endif /* defined(WALLPAPER_DEFINE_IN_CFG) */


/*****************************************************************************
 * Wallpaper table
 *****************************************************************************/

VAPP_WALLPAPER_TABLE
{
    // register widget here
    VAPP_NEW_WALLPAPER(
        VappWallpaperWide),

#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
    VAPP_NEW_WALLPAPER(
        VappWallpaperVideo),
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO__
    VAPP_NEW_WALLPAPER(
        VappWallpaperFrameVideo),
    VAPP_NEW_WALLPAPER(
        VappWallpaperInteractiveVideo),        
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV__
    VAPP_NEW_WALLPAPER(
        VappWallpaperMAV),
#endif

#ifdef __MMI_VUI_WALLPAPER_MRE__
    VAPP_NEW_WALLPAPER(
        VappWallpaperMre),
#endif 

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WAVE__
    VAPP_NEW_WALLPAPER(
        VappWallpaperWave),
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_SAKURA__
    VAPP_NEW_WALLPAPER(
        VappWallpaper3DSakura),
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_MAPLE__
    VAPP_NEW_WALLPAPER(
        VappWallpaper3DMaple),
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_CASSIA__
    VAPP_NEW_WALLPAPER(
        VappWallpaper3DCassia),
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPANGLE__
    VAPP_NEW_WALLPAPER(
        VappWallpaperSpangleGold),
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_CHIPSET__
    VAPP_NEW_WALLPAPER(
        VappWallpaperChipset),
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_COMET__
    VAPP_NEW_WALLPAPER(
        VappWallpaperComet),
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPACE__
    VAPP_NEW_WALLPAPER(
        VappWallpaperSpace),
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MATRIX__
    VAPP_NEW_WALLPAPER(
        VappWallpaperMatrix),
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WILDWORLD__
    VAPP_NEW_WALLPAPER(
        VappWallpaperWildWorld),
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SAKURA__
    VAPP_NEW_WALLPAPER(
        VappWallpaperSakura),
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_FIREFLY__
    VAPP_NEW_WALLPAPER(
        VappWallpaperFirefly),
#endif

#ifdef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_MIMOSA__
    VAPP_NEW_WALLPAPER(
        VappWallpaperMimosa),
#endif
        
#ifdef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_GIRL__
    VAPP_NEW_WALLPAPER(
        VappWallpaperGirl),
#endif
        
#ifdef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_CLOCK__
    VAPP_NEW_WALLPAPER(
        VappWallpaperClock),
#endif
        
#ifdef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_HORSE__
    VAPP_NEW_WALLPAPER(
         VappWallpaperHorse),
#endif
        
#ifdef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_DAYDREAM__
    VAPP_NEW_WALLPAPER(
         VappWallpaperDaydream),
#endif
        
#ifdef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_LIGHTHOUSE__
     VAPP_NEW_WALLPAPER(
         VappWallpaperLighthouse),
#endif
        
#ifdef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_PUPPY__
     VAPP_NEW_WALLPAPER(
          VappWallpaperPuppy),
#endif
        
#ifdef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_SOLAR__
     VAPP_NEW_WALLPAPER(
         VappWallpaperSolar),
#endif
        
#ifdef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_FISH__
     VAPP_NEW_WALLPAPER(
         VappWallpaperFish),
#endif
        
#ifdef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_TRANSFORMER__
     VAPP_NEW_WALLPAPER(
         VappWallpaperTransformer),
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_EARTH__
    VAPP_NEW_WALLPAPER(
        VappWallpaper3DEarth),
#endif

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_WAVE__
    VAPP_NEW_WALLPAPER(
        VappWallpaper3DWave),
#endif

    VAPP_WALLPAPER_LAST_ITEM
};

#if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WAVE__) || defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPANGLE__) || defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_CHIPSET__)|| defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_COMET__) \
    || defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPACE__)|| defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MATRIX__)|| defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WILDWORLD__)|| defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SAKURA__) \
    || defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_FIREFLY__)|| defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_MIMOSA__)|| defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_GIRL__) || defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_CLOCK__) \
    || defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_HORSE__)|| defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_DAYDREAM__)|| defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_LIGHTHOUSE__)|| defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_PUPPY__)\
    || defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_SOLAR__)|| defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_FISH__)|| defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_TRANSFORMER__)
#define __MMI_VUI_NATIVE_LIVE_WALLPAPER__
#endif 
/*****************************************************************************
 * External interface
 *****************************************************************************/

// This function returns the pointer to the i-th device shortcut configuration.
// RETURNS: the pointer to the shortcut configuration table.
extern const vapp_wallpaper_cfg_struct *vapp_wallpaper_get_cfg_table(void);

#endif /* __VAPP_WALLPAPER_CFG_H__ */

