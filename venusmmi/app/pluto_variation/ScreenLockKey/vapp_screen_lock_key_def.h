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
 *  vapp_screen_lock_key_def.h
 *
 * Project:
 * --------
 *  MAUI
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_SCREEN_LOCK_KEY_DEF_H
#define VAPP_SCREEN_LOCK_KEY_DEF_H

#include "MMI_features.h"

#ifdef __MMI_VUI_SCREEN_LOCK_KEY__

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_include.h"
#include "vfx_basic_type.h"
#include "vfx_sys_config.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "SST_sla.h"
#include "lcd_sw_inc.h"
#include "MMIDataType.h"
#include "ScrLockerGprot.h"
#include "MMI_common_app_trc.h"
#include "ScrlockerScreenLockKey.h"

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * Debug
 *****************************************************************************/

//#define VAPP_SCREEN_LOCK_KEY_DEBUG
#define VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK

/*
 * Catcher logging:
 */
#if defined(__MTK_TARGET__)
#define VAPP_LOCK_LOG_EX(...) MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, __VA_ARGS__)
#define VAPP_LOCK_LOG(_x)     VAPP_LOCK_LOG_EX _x
#else
#define VAPP_LOCK_LOG(_x)  
#endif /* defined(__MTK_TARGET__) */

/*
 * SWLA logging:
 */
#if defined(__MTK_TARGET__)
#define VAPP_LOCK_SLA(_x)       SLA_CustomLogging _x
#else
#define VAPP_LOCK_SLA(_x)
#endif

/*
 * Animation Lock:
 */
#define VAPP_LOCK_LOCK_ANIMATION()      (vapp_screen_lock_key_lock_state_machine())
#define VAPP_LOCK_UNLOCK_ANIMATION()    (vapp_screen_lock_key_unlock_state_machine())
#define VAPP_LOCK_CHECK_ANIMATION()     {if(!vapp_screen_lock_key_check_state_machine())return;}


/*****************************************************************************
 * Defines
 *****************************************************************************/

#define VAPP_SCREEN_LOCK_KEY_RUN_MEM_SIZE       (VFX_SYS_MEM_DEFAULT_SCR_ASM_SIZE + VFX_SYS_MEM_VRT_SIZE)


/* HQVGA */
#if defined(__MMI_MAINLCD_320X480__)
    
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_CENTRY_WIDTH        (40)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_CENTRY_HEIGHT       (40)
    /* centry */
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_BG_CENTRY_X         (118)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_BG_CENTRY_Y         (394)
    /* up */
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_BG_UP_X             (89)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_BG_UP_Y             (251)    
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_UP_X                (140)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_UP_Y                (296)
    /* left */
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT_X              (6)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT_Y              (437)    
    #define VAPP_SCREEN_LOCK_KEY_NOTIFY_LEFT_X              (48)
    #define VAPP_SCREEN_LOCK_KEY_NOTIFY_LEFT_Y              (464)
    /* right */
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT_X             (276)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT_Y             (437)    
    #define VAPP_SCREEN_LOCK_KEY_NOTIFY_RIGHT_X             (256)
    #define VAPP_SCREEN_LOCK_KEY_NOTIFY_RIGHT_Y             (465)
    /* arrow */
    #define VAPP_SCREEN_LOCK_KEY_ARROW_UP1_X                (153)
    #define VAPP_SCREEN_LOCK_KEY_ARROW_UP1_Y                (372)
    #define VAPP_SCREEN_LOCK_KEY_ARROW_LEFT_X               (89)
    #define VAPP_SCREEN_LOCK_KEY_ARROW_LEFT_Y               (437)
    #define VAPP_SCREEN_LOCK_KEY_ARROW_RIGHT_X              (207)
    #define VAPP_SCREEN_LOCK_KEY_ARROW_RIGHT_Y              (437)
    /* font */
    #define VAPP_SCREEN_LOCK_KEY_NOTIFY_FONT_SIZE           (12)

/* QVGA */    
#elif defined(__MMI_MAINLCD_240X320__)

    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_CENTRY_WIDTH        (30)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_CENTRY_HEIGHT       (30)
    /* centry */
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_BG_CENTRY_X         (87)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_BG_CENTRY_Y         (255)
    /* up */
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_BG_UP_X             (68)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_BG_UP_Y             (149)    
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_UP_X                (105)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_UP_Y                (181)
    /* left */
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT_X              (4)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT_Y              (287)    
    #define VAPP_SCREEN_LOCK_KEY_NOTIFY_LEFT_X              (35)
    #define VAPP_SCREEN_LOCK_KEY_NOTIFY_LEFT_Y              (307)
    /* right */
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT_X             (207)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT_Y             (287)    
    #define VAPP_SCREEN_LOCK_KEY_NOTIFY_RIGHT_X             (192)
    #define VAPP_SCREEN_LOCK_KEY_NOTIFY_RIGHT_Y             (307)
    /* arrow */
    #define VAPP_SCREEN_LOCK_KEY_ARROW_UP1_X                (115)
    #define VAPP_SCREEN_LOCK_KEY_ARROW_UP1_Y                (237)
    #define VAPP_SCREEN_LOCK_KEY_ARROW_LEFT_X               (66)
    #define VAPP_SCREEN_LOCK_KEY_ARROW_LEFT_Y               (287)
    #define VAPP_SCREEN_LOCK_KEY_ARROW_RIGHT_X              (154)
    #define VAPP_SCREEN_LOCK_KEY_ARROW_RIGHT_Y              (287)
    /* font */
    #define VAPP_SCREEN_LOCK_KEY_NOTIFY_FONT_SIZE           (9)

/* WQVGA */    
#elif defined(__MMI_MAINLCD_240X400__)

    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_CENTRY_WIDTH        (30)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_CENTRY_HEIGHT       (30)
    /* centry */
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_BG_CENTRY_X         (87)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_BG_CENTRY_Y         (335)
    /* up */
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_BG_UP_X             (68)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_BG_UP_Y             (229)    
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_UP_X                (105)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_UP_Y                (261)
    /* left */
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT_X              (4)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT_Y              (367)    
    #define VAPP_SCREEN_LOCK_KEY_NOTIFY_LEFT_X              (36)
    #define VAPP_SCREEN_LOCK_KEY_NOTIFY_LEFT_Y              (387)
    /* right */
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT_X             (207)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT_Y             (367)    
    #define VAPP_SCREEN_LOCK_KEY_NOTIFY_RIGHT_X             (192)
    #define VAPP_SCREEN_LOCK_KEY_NOTIFY_RIGHT_Y             (387)
    /* arrow */
    #define VAPP_SCREEN_LOCK_KEY_ARROW_UP1_X                (115)
    #define VAPP_SCREEN_LOCK_KEY_ARROW_UP1_Y                (315)
    #define VAPP_SCREEN_LOCK_KEY_ARROW_LEFT_X               (66)
    #define VAPP_SCREEN_LOCK_KEY_ARROW_LEFT_Y               (367)
    #define VAPP_SCREEN_LOCK_KEY_ARROW_RIGHT_X              (154)
    #define VAPP_SCREEN_LOCK_KEY_ARROW_RIGHT_Y              (367)
    /* font */
    #define VAPP_SCREEN_LOCK_KEY_NOTIFY_FONT_SIZE           (9)

/* LQVGA */    
#elif defined(__MMI_MAINLCD_320X240__)

    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_CENTRY_WIDTH        (30)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_CENTRY_HEIGHT       (30)
    /* centry */
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_BG_CENTRY_X         (128)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_BG_CENTRY_Y         (179)
    /* up */
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_BG_UP_X             (107)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_BG_UP_Y             (93)    
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_UP_X                (145)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_UP_Y                (116)
    /* left */
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT_X              (2)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT_Y              (209)    
    #define VAPP_SCREEN_LOCK_KEY_NOTIFY_LEFT_X              (34)
    #define VAPP_SCREEN_LOCK_KEY_NOTIFY_LEFT_Y              (230)
    /* right */
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT_X             (288)
    #define VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT_Y             (209)    
    #define VAPP_SCREEN_LOCK_KEY_NOTIFY_RIGHT_X             (274)
    #define VAPP_SCREEN_LOCK_KEY_NOTIFY_RIGHT_Y             (230)
    /* arrow */
    #define VAPP_SCREEN_LOCK_KEY_ARROW_UP1_X                (155)
    #define VAPP_SCREEN_LOCK_KEY_ARROW_UP1_Y                (163)
    #define VAPP_SCREEN_LOCK_KEY_ARROW_LEFT_X               (107)
    #define VAPP_SCREEN_LOCK_KEY_ARROW_LEFT_Y               (207)
    #define VAPP_SCREEN_LOCK_KEY_ARROW_RIGHT_X              (195)
    #define VAPP_SCREEN_LOCK_KEY_ARROW_RIGHT_Y              (207)
    /* font */
    #define VAPP_SCREEN_LOCK_KEY_NOTIFY_FONT_SIZE           (9)

#endif

#define VAPP_SCREEN_LOCK_KEY_FONT_COLOR                     VFX_COLOR_WHITE

/*****************************************************************************
 * aniamtion duration
 *****************************************************************************/

#define VAPP_SCREEN_LOCK_KEY_WATCHDOG_DURATION                          (8)
#define VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_CENTRY_RESIZE_DURATION      (200)
#define VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_BG_DURATION                 (500)
#define VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_CARD_DURATION               (200)
#define VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_NOTIFY_DURATION             (200)
#define VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_BREATH_DURATION             (200)
#define VAPP_SCREEN_LOCK_KEY_ANIMATE_ARROW_DURATION                     (200)
#define VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_DURATION                    (200)
#define VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_RESIZE_DURATION             (200)
#define VAPP_SCREEN_LOCK_KEY_ANIMATE_ARROW_STEP                         (4)
#define VAPP_SCREEN_LOCK_KEY_ANIMATE_UNLOCK_BREATH_STEP                 (6)


/*****************************************************************************
 * enums
 *****************************************************************************/

typedef enum{

    VAPP_SCREEN_LOCK_KEY_UNLOCK_UP,
    VAPP_SCREEN_LOCK_KEY_UNLOCK_LEFT,
    VAPP_SCREEN_LOCK_KEY_UNLOCK_RIGHT,
    VAPP_SCREEN_LOCK_KEY_UNLOCK_CENTRY,
    VAPP_SCREEN_LOCK_KEY_UNLOCK_TOTAL,

}VappScreenLockKeyDirectionEnum;

typedef enum{

    VAPP_SCREEN_LOCK_KEY_STATE_IDLE,
    VAPP_SCREEN_LOCK_KEY_STATE_NORMAL,
    VAPP_SCREEN_LOCK_KEY_STATE_OPERATION,
    VAPP_SCREEN_LOCK_KEY_STATE_CENTRY_TAP,
#ifdef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK
    VAPP_SCREEN_LOCK_KEY_STATE_BACK_TO_NORMAL,
    VAPP_SCREEN_LOCK_KEY_STATE_CENTRY_MOVE,
    VAPP_SCREEN_LOCK_KEY_STATE_UNLOCK_SELECT,
    VAPP_SCREEN_LOCK_KEY_STATE_UNLOCK_UNSELECT,
    VAPP_SCREEN_LOCK_KEY_STATE_CENTRY_RESTORE,
#else
    VAPP_SCREEN_LOCK_KEY_STATE_CENTRY_TAP_FROM_NORMAL,
    VAPP_SCREEN_LOCK_KEY_STATE_UNLOCK_TAP,
    VAPP_SCREEN_LOCK_KEY_STATE_UNLOCK_RESTORE, 
#endif       
    VAPP_SCREEN_LOCK_KEY_STATE_UNLOCK,
    VAPP_SCREEN_LOCK_KEY_STATE_EXIT,
    VAPP_SCREEN_LOCK_KEY_STATE_TOTAL
    
}VappScreenLockKeyStateEnum;


/*****************************************************************************
 * push notification
 *****************************************************************************/
#if defined(__MMI_NCENTER_SUPPORT__)

/* HQVGA */ 
#if defined(__MMI_MAINLCD_320X480__)

    #define MAX_CELL_NUM                (5)
    #define NOTI_WIDTH                  (250)
    #define NOTI_HEIGHT                 (50)

    #define NOTI_LIST_UP_GAP            (12)
    #define NOTI_ICON_UP_GAP            (11)
    #define NOTI_ICON_LEFT_GAP          (18)
    #define NOTI_ICON_RIGHT_GAP         (15)
    #define NOTI_TEXT_UP_GAP            (7)
    #define NOTI_TEXT_MID_GAP           (6)
    #define NOTI_TIME_LEFT_GAP          (20)

    #define NOTI_LIST_WIDTH             (NOTI_WIDTH-NOTI_ICON_LEFT_GAP)

    #define NOTI_SUB_WIDTH              (100)
    #define NOTI_TIME_WIDTH             (60)

    #define NOTI_MAIN_FONT_SIZE         (18)
    #define NOTI_SUB_FONT_SIZE          (12)
    
/* QVGA */    
#elif defined(__MMI_MAINLCD_240X320__)

    #define MAX_CELL_NUM                (4)
    #define NOTI_WIDTH                  (200)
    #define NOTI_HEIGHT                 (40)

    #define NOTI_LIST_UP_GAP            (12)
    #define NOTI_ICON_UP_GAP            (5)
    #define NOTI_ICON_LEFT_GAP          (14)
    #define NOTI_ICON_RIGHT_GAP         (10)
    #define NOTI_TEXT_UP_GAP            (3)
    #define NOTI_TEXT_MID_GAP           (4)
    #define NOTI_TIME_LEFT_GAP          (0)

    #define NOTI_LIST_WIDTH             (NOTI_WIDTH-NOTI_ICON_LEFT_GAP)

    #define NOTI_SUB_WIDTH              (87)
    #define NOTI_TIME_WIDTH             (47)

    #define NOTI_MAIN_FONT_SIZE         (14)
    #define NOTI_SUB_FONT_SIZE          (10)
    
/* WQVGA */    
#elif defined(__MMI_MAINLCD_240X400__)

    #define MAX_CELL_NUM                (5)
    #define NOTI_WIDTH                  (200)
    #define NOTI_HEIGHT                 (40)

    #define NOTI_LIST_UP_GAP            (12)
    #define NOTI_ICON_UP_GAP            (5)
    #define NOTI_ICON_LEFT_GAP          (14)
    #define NOTI_ICON_RIGHT_GAP         (10)
    #define NOTI_TEXT_UP_GAP            (3)
    #define NOTI_TEXT_MID_GAP           (4)
    #define NOTI_TIME_LEFT_GAP          (0)

    #define NOTI_LIST_WIDTH             (NOTI_WIDTH-NOTI_ICON_LEFT_GAP)

    #define NOTI_SUB_WIDTH              (87)
    #define NOTI_TIME_WIDTH             (47)

    #define NOTI_MAIN_FONT_SIZE         (14)
    #define NOTI_SUB_FONT_SIZE          (10)
    
/* LQVGA */    
#elif defined(__MMI_MAINLCD_320X240__)

    #define MAX_CELL_NUM                (3)
    #define NOTI_WIDTH                  (250)
    #define NOTI_HEIGHT                 (40)

    #define NOTI_LIST_UP_GAP            (12)
    #define NOTI_ICON_UP_GAP            (5)
    #define NOTI_ICON_LEFT_GAP          (11)
    #define NOTI_ICON_RIGHT_GAP         (11)
    #define NOTI_TEXT_UP_GAP            (3)
    #define NOTI_TEXT_MID_GAP           (4)
    #define NOTI_TIME_LEFT_GAP          (0)

    #define NOTI_LIST_WIDTH             (NOTI_WIDTH-NOTI_ICON_LEFT_GAP)

    #define NOTI_SUB_WIDTH              (87)
    #define NOTI_TIME_WIDTH             (47)

    #define NOTI_MAIN_FONT_SIZE         (14)
    #define NOTI_SUB_FONT_SIZE          (10)
    
#endif

enum VappScreenLockKeyNotificationSupportEnum
{
    VAPP_SCREEN_LOCK_KEY_NOTIFICATION_CALLLOG,
    VAPP_SCREEN_LOCK_KEY_NOTIFICATION_MSG,
#if defined(__MMI_EMAIL__)
    VAPP_SCREEN_LOCK_KEY_NOTIFICATION_MAIL,
#endif
#if defined(__MMI_SNS_CENTER__)
    VAPP_SCREEN_LOCK_KEY_NOTIFICATION_SNS,
#endif
#if defined(__MRE_AM__)
    VAPP_SCREEN_LOCK_KEY_NOTIFICATION_MRE,
#endif
    VAPP_SCREEN_LOCK_KEY_NOTIFICATION_TOTAL,
    VAPP_SCREEN_LOCK_KEY_NOTIFICATION_INVALID

};

#endif  /*__MMI_NCENTER_SUPPORT__*/

#endif  /*__MMI_VUI_SCREEN_LOCK_KEY__*/
#endif

