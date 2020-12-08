/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  IdleMemCfg.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the internal interface of the idle application.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef _IDLEMEMCFG_H_
#define _IDLEMEMCFG_H_

#include "MMI_features.h"

/*
this file is config for pluto mmi asm2.0. 
if need, please add your config as below.

Note:  VRT_MEM_FACTOR must be Integer not Float. 


#ifdef __MMI_VUI_LAUNCHER__

    #define IDLE_SHELL_ASM_HEAP_SIZE        1000
    #define IDLE_SHELL_ASM_FG_SIZE          2000

    #define IDLE_SHELL_ASM_VRT_MEM_FACTOR   (2)

    #if (IDLE_ASM_HEAP_SIZE < IDLE_SHELL_ASM_HEAP_SIZE)
    #undef IDLE_ASM_HEAP_SIZE
    #define IDLE_ASM_HEAP_SIZE IDLE_SHELL_ASM_HEAP_SIZE
    #endif

    #if (IDLE_ASM_FG_SIZE < IDLE_SHELL_ASM_FG_SIZE)
    #undef IDLE_ASM_FG_SIZE
    #define IDLE_ASM_FG_SIZE IDLE_SHELL_ASM_FG_SIZE
    #endif

    #if (IDLE_ASM_VRT_MEM_FACTOR < IDLE_SHELL_ASM_VRT_MEM_FACTOR)
    #undef IDLE_ASM_VRT_MEM_FACTOR 
    #define IDLE_ASM_VRT_MEM_FACTOR IDLE_SHELL_ASM_VRT_MEM_FACTOR 
    #endif    
#endif

*/




#define IDLE_ASM_HEAP_SIZE 0
#define IDLE_ASM_FG_SIZE 0
#define IDLE_ASM_VRT_MEM_FACTOR 0  /* can not be float, must be integer */
#define IDLE_MM_ASM_VRT_MEM_FACTOR (0)

/* You can not add your configuration above. */

/*
 * Idle Shell memory configuration:
 */
#if defined(__MMI_VUI_SHELL_APP__)
    #if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__)
        #undef  IDLE_SHELL_LWP_MEM_SIZE
        #define IDLE_SHELL_LWP_MEM_SIZE (40 * 1024)
    #else
        #undef  IDLE_SHELL_LWP_MEM_SIZE
        #define IDLE_SHELL_LWP_MEM_SIZE (0)
    #endif /* defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__) */

    #if defined(__MMI_VUI_SHELL_MULTI_PAGE__)
        #undef  IDLE_SHELL_MAX_FG_SIZE
        #define IDLE_SHELL_MAX_FG_SIZE (300 * 1024 + IDLE_SHELL_LWP_MEM_SIZE)
    #else
        #undef  IDLE_SHELL_MAX_FG_SIZE
        #define IDLE_SHELL_MAX_FG_SIZE (200 * 1024 + IDLE_SHELL_LWP_MEM_SIZE)
    #endif /* defined(__MMI_VUI_SHELL_MULTI_PAGE__) */

    #if (IDLE_ASM_FG_SIZE < IDLE_SHELL_MAX_FG_SIZE)
        #undef IDLE_ASM_FG_SIZE
        #define IDLE_ASM_FG_SIZE IDLE_SHELL_MAX_FG_SIZE
    #endif /* (IDLE_ASM_FG_SIZE < IDLE_SHELL_MAX_FG_SIZE) */
#endif /* defined(__MMI_VUI_SHELL_APP__) */


/*
 * FTE Launcher memory configuration:
 */
#ifdef __MMI_VUI_LAUNCHER__
    #define FTE_LAUNCHER_ASM_FG_SIZE (300 * 1024)

    #if (IDLE_ASM_FG_SIZE < FTE_LAUNCHER_ASM_FG_SIZE)
    #undef IDLE_ASM_FG_SIZE
    #define IDLE_ASM_FG_SIZE FTE_LAUNCHER_ASM_FG_SIZE
    #endif
#endif /* __MMI_VUI_LAUNCHER__ */


/*
 * Key Launcher memory configuration:
 */
#ifdef __MMI_VUI_LAUNCHER_KEY__
#include "vapp_widget_key_musicplayer_def.h"

	#define KEY_LAUNCHER_HOME_ASM_FG_SIZE   (450 * 1024)
    #define KEY_LAUNCHER_ASM_FG_SIZE (KEY_LAUNCHER_HOME_ASM_FG_SIZE + KL_WG_MP_MEMORY_SIZE)

    #if (IDLE_ASM_FG_SIZE < KEY_LAUNCHER_ASM_FG_SIZE)
    #undef IDLE_ASM_FG_SIZE
    #define IDLE_ASM_FG_SIZE KEY_LAUNCHER_ASM_FG_SIZE
    #endif
    
    #if (IDLE_MM_ASM_VRT_MEM_FACTOR < 3) && !defined(__MMI_FTE_SUPPORT_SLIM__)
    #undef IDLE_MM_ASM_VRT_MEM_FACTOR
    #define IDLE_MM_ASM_VRT_MEM_FACTOR (3)
    #endif
    
    #if (IDLE_ASM_VRT_MEM_FACTOR < IDLE_MM_ASM_VRT_MEM_FACTOR)
    #undef IDLE_ASM_VRT_MEM_FACTOR
    #define IDLE_ASM_VRT_MEM_FACTOR (IDLE_MM_ASM_VRT_MEM_FACTOR)
    #endif
    
#endif /* __MMI_VUI_LAUNCHER_KEY__ */

/*
 * Applist Launcher memory configuration:
 */
#ifdef __MMI_LAUNCHER_APP_LIST__
#include "nvram_common_defs.h"
#include "AppListDef.h"

    #define MMI_APPLIST_BAR_APP_NUM (NVRAM_EF_APPLIST_BAR_APP_NUM)
    #define MMI_APPLIST_PANEL_APP_NUM (NVRAM_EF_APPLIST_PANEL_APP_NUM) 
    #define MMI_APPLIST_ENTRY_NUM (MMI_APPLIST_BAR_APP_NUM + MMI_APPLIST_PANEL_APP_NUM)

    /* Status bar */
    #define MMI_APPLIST_STATUS_BAR_BUFFER_SIZE ((LCD_WIDTH*MMI_STATUS_BAR_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL*2)>>3)

    /* Panel buffer */
    #define MMI_APPLIST_PANEL_LAYER_BUFFER_SIZE ((LCD_WIDTH*LCD_HEIGHT*24)>>3)
    
    /* AppName list : temporal allocation to load data and sync */
    //#define MMI_APPLIST_APP_NAME_MEM_SIZE (MMI_APP_NAME_MAX_LEN * MMI_APPLIST_PANEL_APP_NUM)

    /* Cell info list */
    #define MMI_APPLIST_APP_CELL_INFO_SIZE (700)
    #define MMI_APPLIST_APP_CELL_INFO_MEM_SIZE (MMI_APPLIST_APP_CELL_INFO_SIZE * MMI_APPLIST_ENTRY_NUM)

    /* Anima node */    
    #define MMI_APPLIST_APP_ANIMA_NODE_SIZE (50)
    #define MMI_APPLIST_APP_ANIMA_NODE_NUM (50)
    #define MMI_APPLIST_APP_ANIMA_NODE_MEM_SIZE (MMI_APPLIST_APP_ANIMA_NODE_SIZE * MMI_APPLIST_APP_ANIMA_NODE_NUM)

    /* Indicator cache */
    #define MMI_APPLIST_INDICATOR_SIZE (MMI_APPLIST_INDICATOR_SIDE * MMI_APPLIST_INDICATOR_SIDE * (24>>3))
    #define MMI_APPLIST_INDICATOR_CACHE_SIZE ((MMI_APPLIST_INDICATOR_SIZE*2+31)/32*32)

    /* Cache */
    #define MMI_APPLIST_APP_CACHE_SIZE ((MMI_APPLIST_CELL_WIDTH * MMI_APPLIST_CELL_HEIGHT * (24>>3)+31)/32*32)

    #ifdef __MMI_APPLIST_ONLY_ICON_SUPPORT__
    /* Title layer */
    #define MMI_APPLIST_TITLE_LAYER_BUFFER_SIZE (LCD_WIDTH * 34 * 2)
    #endif

    #ifdef __MMI_APPLIST_ONLY_ICON_SUPPORT__
    #define MMI_APPLIST_APP_CACHE_PAGE_NUM (2)
    #else
    #define MMI_APPLIST_APP_CACHE_PAGE_NUM (3)
    #endif
    
    #if defined(__MMI_APPLIST_EDIT_WITH_BG__) && defined(__MMI_APPLIST_APP_UNINSTALL_SUPPORT__)
    #define MMI_APPLIST_APP_CACHE_NUM (MMI_APPLIST_APP_CACHE_PAGE_NUM * MMI_APPLIST_APP_COUNT_PER_PAGE + MMI_APPLIST_BAR_APP_NUM + 4) /* highlight frame + app download icon + cell bg icon + app uninstall icon */
    #elif defined(__MMI_APPLIST_EDIT_WITH_BG__) || defined(__MMI_APPLIST_APP_UNINSTALL_SUPPORT__)
    #define MMI_APPLIST_APP_CACHE_NUM (MMI_APPLIST_APP_CACHE_PAGE_NUM * MMI_APPLIST_APP_COUNT_PER_PAGE + MMI_APPLIST_BAR_APP_NUM + 3) /* highlight frame + app download icon + cell bg icon /app uninstall icon */
    #else
    #define MMI_APPLIST_APP_CACHE_NUM (MMI_APPLIST_APP_CACHE_PAGE_NUM * MMI_APPLIST_APP_COUNT_PER_PAGE + MMI_APPLIST_BAR_APP_NUM + 2) /* highlight frame + app download icon */
    #endif
    
    #define MMI_APPLIST_BASE_LAYER_CAN_CACHE_APP_NUM LCD_WIDTH * LCD_HEIGHT * 2 / MMI_APPLIST_APP_CACHE_SIZE
    #define MMI_APPLIST_BASE_LAYER_CAN_CACHE_APP_SIZE MMI_APPLIST_APP_CACHE_SIZE * MMI_APPLIST_BASE_LAYER_CAN_CACHE_APP_NUM
    #define MMI_APPLIST_APP_CACHE_MEM_SIZE ((MMI_APPLIST_APP_CACHE_NUM - MMI_APPLIST_BASE_LAYER_CAN_CACHE_APP_NUM) * MMI_APPLIST_APP_CACHE_SIZE)
    
    #ifdef __MMI_APPLIST_ONLY_ICON_SUPPORT__
    #define MMI_APPLIST_MEM_SIZE ((256+32*6)+ \
        MMI_APPLIST_STATUS_BAR_BUFFER_SIZE + \
        MMI_APPLIST_PANEL_LAYER_BUFFER_SIZE + \
        MMI_APPLIST_APP_CELL_INFO_MEM_SIZE + \
        MMI_APPLIST_APP_ANIMA_NODE_MEM_SIZE + \
        MMI_APPLIST_APP_CACHE_MEM_SIZE + \
        MMI_APPLIST_INDICATOR_CACHE_SIZE + \
        MMI_APPLIST_TITLE_LAYER_BUFFER_SIZE)
	#else
    #define MMI_APPLIST_MEM_SIZE ((256+32*6)+ \
        MMI_APPLIST_STATUS_BAR_BUFFER_SIZE + \
        MMI_APPLIST_PANEL_LAYER_BUFFER_SIZE*2 + \
        MMI_APPLIST_APP_CELL_INFO_MEM_SIZE + \
        MMI_APPLIST_APP_ANIMA_NODE_MEM_SIZE + \
        MMI_APPLIST_APP_CACHE_MEM_SIZE + \
        MMI_APPLIST_INDICATOR_CACHE_SIZE)
    #endif


    #if (IDLE_ASM_FG_SIZE < MMI_APPLIST_MEM_SIZE)
    #undef IDLE_ASM_FG_SIZE
    #define IDLE_ASM_FG_SIZE MMI_APPLIST_MEM_SIZE
    #endif
    
#endif /* __MMI_LAUNCHER_APP_LIST__ */

/*
 * Venus live wallpaper memory configuration:
 */
#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__
    #if defined(__MMI_VUI_LAUNCHER_KEY__)&& !defined(__MMI_FTE_SUPPORT_SLIM__)
    #define MMI_VUI_WALLPAPER_EXTRA_VRT_MEM_FACTOR (2)
    #else
    #define MMI_VUI_WALLPAPER_EXTRA_VRT_MEM_FACTOR (0)
    #endif
    
    #define MMI_VUI_WALLPAPER_VRT_MEM_FACTOR (0 + MMI_VUI_WALLPAPER_EXTRA_VRT_MEM_FACTOR)
    
    #if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WILDWORLD__) && (MMI_VUI_WALLPAPER_VRT_MEM_FACTOR < (2 + MMI_VUI_WALLPAPER_EXTRA_VRT_MEM_FACTOR))
    #undef MMI_VUI_WALLPAPER_VRT_MEM_FACTOR
    #define MMI_VUI_WALLPAPER_VRT_MEM_FACTOR (2 + MMI_VUI_WALLPAPER_EXTRA_VRT_MEM_FACTOR)
    #endif
    
    #if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SAKURA__) && (MMI_VUI_WALLPAPER_VRT_MEM_FACTOR < (2 + MMI_VUI_WALLPAPER_EXTRA_VRT_MEM_FACTOR))
    #undef MMI_VUI_WALLPAPER_VRT_MEM_FACTOR
    #define MMI_VUI_WALLPAPER_VRT_MEM_FACTOR (2 + MMI_VUI_WALLPAPER_EXTRA_VRT_MEM_FACTOR)
    #endif

    #if (IDLE_ASM_VRT_MEM_FACTOR < MMI_VUI_WALLPAPER_VRT_MEM_FACTOR)
    #undef IDLE_ASM_VRT_MEM_FACTOR 
    #define IDLE_ASM_VRT_MEM_FACTOR MMI_VUI_WALLPAPER_VRT_MEM_FACTOR 
    #endif 

    #if (IDLE_ASM_VRT_MEM_FACTOR < (MMI_VUI_WALLPAPER_VRT_MEM_FACTOR + IDLE_MM_ASM_VRT_MEM_FACTOR))
    #undef IDLE_ASM_VRT_MEM_FACTOR 
    #define IDLE_ASM_VRT_MEM_FACTOR (MMI_VUI_WALLPAPER_VRT_MEM_FACTOR + IDLE_MM_ASM_VRT_MEM_FACTOR) 
    #endif 
#endif /* __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER__ */

/// for 3D
#if defined(__VENUS_3D_UI_ENGINE__) && defined(__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER__)

    #if defined(__MMI_MAINLCD_480X800__)
        #define MMI_VUI_IG_WALLPAPER_VRT_MEM_FACTOR  10
    #elif defined(__MMI_MAINLCD_320X480__)
        #define MMI_VUI_IG_WALLPAPER_VRT_MEM_FACTOR  18
    #else
        #define MMI_VUI_IG_WALLPAPER_VRT_MEM_FACTOR  18
    #endif

    #if (IDLE_ASM_VRT_MEM_FACTOR < MMI_VUI_IG_WALLPAPER_VRT_MEM_FACTOR)
    #undef IDLE_ASM_VRT_MEM_FACTOR
    #define IDLE_ASM_VRT_MEM_FACTOR MMI_VUI_IG_WALLPAPER_VRT_MEM_FACTOR
    #endif

#endif

#endif /* _IDLEMEMCFG_H_ */

