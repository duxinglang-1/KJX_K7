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
 *  vapp_launcher_robot_def.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the internal compile options, constants, and etc.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_LAUNCHER_ROBOT_DEF_H
#define VAPP_LAUNCHER_ROBOT_DEF_H

#include "MMI_features.h"

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "lcd_sw_inc.h"
#include "custom_launcher_config.h" /* CUSTOM_LAUNCHER_ROBOT_PAGE_NUM */


/*****************************************************************************
 * Configuration
 *****************************************************************************/

/* Max. number of pages on the desktop. */
#define VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM              (CUSTOM_LAUNCHER_ROBOT_PAGE_NUM)

/* Max. number of pages on the desktop. */
#define VAPP_LAUNCHER_ROBOT_MAX_SHORTCUT_WIDGET_NUM    (30)

/* Extra cache memory for VRT. The extra memory comes from the foreground
   memory. Enlarge this factor can improve the performance. However, please
   pay attention to the overall ASM memory size if this factor is increased. */
#define VAPP_LAUNCHER_ROBOT_EXTRA_CACHE_MEM_FACTOR    (2.0f * (VAPP_LAUNCHER_ROBOT_MAX_PAGE_NUM))

/* If defined, we will suspend the live wallpaper when the user swipes the
   desktop. This will improve the animation performance. */
#define VAPP_LAUNCHER_ROBOT_SUSPEND_LWP_DURING_SWIPE

/* If defined, we will support swipe loop back between first and last page*/
#define VAPP_LAUNCHER_ROBOT_SWIPE_LOOP_BACK_SUPPORT

#if defined(__LOW_COST_SUPPORT_COMMON__)
/* If defined, we will support resize page during transition animation to reduce cache usage*/
#define VAPP_LAUNCHER_ROBOT_REDUCE_PAGE_SIZE_DURING_TRANSITION

/* If defined, only can flip two page during a swipe*/
#define VAPP_LAUNCHER_ROBOT_SLIDE_ONLY_TWO_PAGE_AT_A_TIME
#endif

/* The layout of the cells on the desktop. */
#if defined(__MMI_MAINLCD_480X800__)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_HORIZ_TILE_NUM                (4)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_VERTI_TILE_NUM                (4)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_TOP_WIDTH        (53)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_BOTTOM_WIDTH     (120)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_LEFT_WIDTH       (0)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_RIGHT_WIDTH      (0)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_AUTO_SLIDE_BORDER_LEFT_WIDTH  (53)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_AUTO_SLIDE_BORDER_RIGHT_WIDTH (53)
#elif defined(__MMI_MAINLCD_320X480__)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_HORIZ_TILE_NUM                (4)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_VERTI_TILE_NUM                (4)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_TOP_WIDTH        (34)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_BOTTOM_WIDTH     (80)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_LEFT_WIDTH       (0)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_RIGHT_WIDTH      (0)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_AUTO_SLIDE_BORDER_LEFT_WIDTH  (35)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_AUTO_SLIDE_BORDER_RIGHT_WIDTH (35)
#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_HORIZ_TILE_NUM                (4)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_VERTI_TILE_NUM                (4)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_TOP_WIDTH        (31)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_BOTTOM_WIDTH     (60)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_LEFT_WIDTH       (0)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_RIGHT_WIDTH      (0)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_AUTO_SLIDE_BORDER_LEFT_WIDTH  (26)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_AUTO_SLIDE_BORDER_RIGHT_WIDTH (26)
#else /* defined(__MMI_MAINLCD_240X320__) */
#define VAPP_LAUNCHER_ROBOT_DESKTOP_HORIZ_TILE_NUM                (4)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_VERTI_TILE_NUM                (3)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_TOP_WIDTH        (25)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_BOTTOM_WIDTH     (58)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_LEFT_WIDTH       (0)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_RIGHT_WIDTH      (0)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_AUTO_SLIDE_BORDER_LEFT_WIDTH  (26)
#define VAPP_LAUNCHER_ROBOT_DESKTOP_AUTO_SLIDE_BORDER_RIGHT_WIDTH (26)
#endif /* defined(__MMI_MAINLCD_240X320__) */


/*****************************************************************************
 * Macro
 *****************************************************************************/

/* Width of the region on the desktop that the user can put widgets on it. */
#define VAPP_LAUNCHER_ROBOT_DESKTOP_VALID_WIDTH               \
    (LCD_WIDTH -                                    \
     VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_LEFT_WIDTH -    \
     VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_RIGHT_WIDTH)

/* Height of the region on the desktop that the user can put widgets on it. */
#define VAPP_LAUNCHER_ROBOT_DESKTOP_VALID_HEIGHT              \
    (LCD_HEIGHT -                                   \
     VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_TOP_WIDTH -     \
     VAPP_LAUNCHER_ROBOT_DESKTOP_OUTER_BORDER_BOTTOM_WIDTH)

/* Width of a tile on the desktop. */
#define VAPP_LAUNCHER_ROBOT_DESKTOP_TILE_WIDTH                                    \
    (VAPP_LAUNCHER_ROBOT_DESKTOP_VALID_WIDTH / VAPP_LAUNCHER_ROBOT_DESKTOP_HORIZ_TILE_NUM)

/* Height of a tile on the desktop. */
#define VAPP_LAUNCHER_ROBOT_DESKTOP_TILE_HEIGHT                                   \
    (VAPP_LAUNCHER_ROBOT_DESKTOP_VALID_HEIGHT / VAPP_LAUNCHER_ROBOT_DESKTOP_VERTI_TILE_NUM)


/*****************************************************************************
 * Configuration (Debug Only)
 *****************************************************************************/

/* Unit-test: desktop tile. */
//#define VAPP_LAUNCHER_ROBOT_UT_DESKTOP_TILE

/* Unit-test: desktop slide. */
//#define VAPP_LAUNCHER_ROBOT_UT_DESKTOP_SLIDE

/* Unit-test: desktop auto-slide. */
//#define VAPP_LAUNCHER_ROBOT_UT_DESKTOP_AUTO_SLIDE

/* Unit-test: control panel to set the page selector auto animation time. */
//#define VAPP_LAUNCHER_ROBOT_UT_PAGE_SELECTOR_DEBUG_PANEL

/* Unit-test: enable catcher logging. */
#define VAPP_LAUNCHER_ROBOT_UT_ENABLE_CATCHER_LOG

/* Unit-test: enable SWLA logging. We don't use __MAUI_SOFTWARE_LA__ to prevent
   from it is opened because other APP defines __MAUI_SOFTWARE_LA__. */
//#define VAPP_LAUNCHER_ROBOT_UT_ENABLE_SWLA_LOG


/*****************************************************************************
 * Macro (Debug Only)
 *****************************************************************************/

/*
 * Catcher logging:
 *
 * Note: Only target compiler supports C99 __VA_ARGS__.
 */
#if defined(__MTK_TARGET__) && defined(VAPP_LAUNCHER_ROBOT_UT_ENABLE_CATCHER_LOG)
#define VAPP_LAUNCHER_ROBOT_LOG_EX(...) MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, __VA_ARGS__)
#define VAPP_LAUNCHER_ROBOT_LOG(_x)     VAPP_LAUNCHER_ROBOT_LOG_EX _x
#else
#define VAPP_LAUNCHER_ROBOT_LOG(_x)
#endif /* defined(__MTK_TARGET__) */

/*
 * SWLA logging:
 */
#if defined(__MTK_TARGET__) && defined(VAPP_LAUNCHER_ROBOT_UT_ENABLE_SWLA_LOG)
#define VAPP_LAUNCHER_ROBOT_SLA(_x)   SLA_CustomLogging _x
#else
#define VAPP_LAUNCHER_ROBOT_SLA(_x)
#endif


#endif /* VAPP_LAUNCHER_ROBOT_DEF_H */

