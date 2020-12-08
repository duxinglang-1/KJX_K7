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

/*******************************************************************************
 * Filename:
 * ---------
 *  wgui_categories_stopwatch.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Stop Watch related categories.
 *
 *  Author:
 * -------
 *  Leo Hu (MTK00563)
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
 
/* DOM-NOT_FOR_SDK-BEGIN */
#ifndef __WGUI_CATEGORIES_STOPWATCH_H__
#define __WGUI_CATEGORIES_STOPWATCH_H__
/* DOM-NOT_FOR_SDK-END */

#include "wgui_categories_multimedia.h"

//RHR
    #include "MMIDataType.h"
    #include "MMI_features.h"
    #include "kal_general_types.h"
    #include "mmi_frm_input_gprot.h"

/***************************************************************************** 
* Macro define
*****************************************************************************/

/* The typical stopwatch state flag, for the timer is continued from the last time. */
#define CONTINUE_TIMER                 0
/* The typical stopwatch state flag, for the timer is re-started. */
#define STOP_START_AGAIN               1
/* The stopwatch state flag, for the timer is stop. */
#define TIMER_STOP                     0
/* The stopwatch state flag, for the timer is start. */
#define TIMER_START                    1
/* The records of the timer in history, just for typical stopwatch. */
#define MAX_TIMER_RECORDS              20
/* The flag for display milisec. */
#define DISPLAY_MILISEC_TRUE           1
/* The flag for not display milisec. */
#define DISPLAY_MILISEC_FALSE          0
/* The max of multipurpose timer. */
#define MAX_MULTIPURPOSE_TIMER         4
/* Text size for one timer. */
#define TIMER_TEXT_SIZE                60

#ifdef __MMI_FTE_SUPPORT__
#define WGUI_CAT307_NUM_NUMERIC_IMAGE                (10)
#define WGUI_CAT307_NUM_MAIN_TIMER                    (6)
#define WGUI_CAT307_NUM_SYMBOL                        (3)

#if defined (__MMI_MAINLCD_240X320__)
#define WGUI_CAT307_NUM_LIST_ITEMS                    (3)
#elif defined (__MMI_MAINLCD_240X400__)
#define WGUI_CAT307_NUM_LIST_ITEMS                    (4)
#elif defined (__MMI_MAINLCD_320X480__)
#define WGUI_CAT307_NUM_LIST_ITEMS                    (4)
#elif defined (__MMI_MAINLCD_480X800__)
#define WGUI_CAT307_NUM_LIST_ITEMS                    (4)
#elif defined (__MMI_MAINLCD_320X240__)
#define WGUI_CAT307_NUM_LIST_ITEMS                    (4)
#endif

#define WGUI_CAT307_CONTROL_AREA_H                    (UI_DEVICE_HEIGHT - MMI_STATUS_BAR_HEIGHT - MMI_SOFTKEY_BAR_HEIGHT - MMI_ICON_BAR_HEIGHT - (MMI_MENUITEM_HEIGHT * WGUI_CAT307_NUM_LIST_ITEMS))
#endif /* __MMI_FTE_SUPPORT__ */

#ifdef __MMI_FTE_SUPPORT__
#define WGUI_CAT307_LIST_TEXT_GAP_X                    (UI_DEVICE_WIDTH >> 2)
#else
#define WGUI_CAT307_LIST_TEXT_GAP_X                    (0)
#endif /* __MMI_FTE_SUPPORT__ */


/* DOM-NOT_FOR_SDK-BEGIN */
/* the coordinates-infor within control area */
#if defined (__MMI_MAINLCD_128X128__)
/* Nway stopwatch */
#define STPWACH_NWAY_CONTROL_AREA_X          0
#define STPWACH_NWAY_CONTROL_AREA_Y          0
#define STPWACH_NWAY_MAINTIMER_START_X       0
#define STPWACH_NWAY_MAINTIMER_START_Y       0
#define STPWACH_NWAY_MAINTIMER_END_X         MAIN_LCD_DEVICE_WIDTH
#define STPWACH_NWAY_MAINTIMER_END_Y         MMI_MENUITEM_HEIGHT
#define STPWACH_NWAY_LISTTIMER_START_X       0
#define STPWACH_NWAY_LISTTIMER_START_Y       MMI_MENUITEM_HEIGHT
#define STPWACH_NWAY_LISTTIMER_END_X         MAIN_LCD_DEVICE_WIDTH
#define STPWACH_NWAY_LISTTIMER_END_Y         (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3)
#define STPWACH_NWAY_SEPARATOR_HEIGHT        0
#define STPWACH_NW_SPAC_SIDE                 0
#define STPWACH_NW_SPAC_TOP                  0
#define STPWACH_NW_FRAM_BORDER               3
/* Typical stopwatch */
#define WGUI_CAT_SW_TYP_MENUITEM_NUM         2
#define WGUI_CAT_SW_TYP_CONTROL_AREA_HEIGH   (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT + MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM) / 2
#define WGUI_CAT_SW_TYP_TIMER_X              (MAIN_LCD_DEVICE_WIDTH >> 1)
#define WGUI_CAT_SW_TYP_TIMER_Y              ((MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM) + MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT) / 2
#define WGUI_CAT_SW_TYP_MILSEC_X             (MAIN_LCD_DEVICE_WIDTH >> 1)
#define WGUI_CAT_SW_TYP_MILSEC_Y             (MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM) + 48

#elif defined (__MMI_MAINLCD_128X160__)
/* Nway stopwatch */
#define STPWACH_NWAY_CONTROL_AREA_X          6
#define STPWACH_NWAY_CONTROL_AREA_Y          5
#define STPWACH_NWAY_MAINTIMER_START_X       40
#define STPWACH_NWAY_MAINTIMER_START_Y       0
#define STPWACH_NWAY_MAINTIMER_END_X         MAIN_LCD_DEVICE_WIDTH
#define STPWACH_NWAY_MAINTIMER_END_Y         (MMI_MENUITEM_HEIGHT * 2)
#define STPWACH_NWAY_LISTTIMER_START_X       0
#define STPWACH_NWAY_LISTTIMER_START_Y       MMI_MENUITEM_HEIGHT
#define STPWACH_NWAY_LISTTIMER_END_X         MAIN_LCD_DEVICE_WIDTH
#define STPWACH_NWAY_LISTTIMER_END_Y         (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 3)
#define STPWACH_NWAY_SEPARATOR_HEIGHT        MMI_MENUITEM_HEIGHT
#define STPWACH_NW_SPAC_SIDE                 0
#define STPWACH_NW_SPAC_TOP                  0
#define STPWACH_NW_FRAM_BORDER               1
/* Typical stopwatch */
#define WGUI_CAT_SW_TYP_MENUITEM_NUM         2
#define WGUI_CAT_SW_TYP_CONTROL_AREA_HEIGH   (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT + MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM) / 2
#define WGUI_CAT_SW_TYP_TIMER_X              (MAIN_LCD_DEVICE_WIDTH >> 1)
#define WGUI_CAT_SW_TYP_TIMER_Y              ((MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM) + MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT) / 2
#define WGUI_CAT_SW_TYP_MILSEC_X             (MAIN_LCD_DEVICE_WIDTH >> 1)
#define WGUI_CAT_SW_TYP_MILSEC_Y             (MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM) + 68

#elif defined (__MMI_MAINLCD_176X220__)
/* Nway stopwatch */
#define STPWACH_NWAY_CONTROL_AREA_X          14
#define STPWACH_NWAY_CONTROL_AREA_Y          16
#define STPWACH_NWAY_MAINTIMER_START_X       40
#define STPWACH_NWAY_MAINTIMER_START_Y       10
#define STPWACH_NWAY_MAINTIMER_END_X         (MAIN_LCD_DEVICE_WIDTH - 10)
#define STPWACH_NWAY_MAINTIMER_END_Y         50
#define STPWACH_NWAY_LISTTIMER_START_X       10
#define STPWACH_NWAY_LISTTIMER_START_Y       30
#define STPWACH_NWAY_LISTTIMER_END_X         (MAIN_LCD_DEVICE_WIDTH - 10)
#define STPWACH_NWAY_LISTTIMER_END_Y         (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT)
#define STPWACH_NWAY_SEPARATOR_HEIGHT        30
#define STPWACH_NW_SPAC_SIDE                 0
#define STPWACH_NW_SPAC_TOP                  0
#define STPWACH_NW_FRAM_BORDER               3
/* Typical stopwatch */
#define WGUI_CAT_SW_TYP_MENUITEM_NUM         4
#define WGUI_CAT_SW_TYP_CONTROL_AREA_HEIGH   (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT + MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM) / 2
#define WGUI_CAT_SW_TYP_TIMER_X              (MAIN_LCD_DEVICE_WIDTH >> 1)
#define WGUI_CAT_SW_TYP_TIMER_Y              ((MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM) + MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT) / 2
#define WGUI_CAT_SW_TYP_MILSEC_X             (MAIN_LCD_DEVICE_WIDTH >> 1)
#define WGUI_CAT_SW_TYP_MILSEC_Y             (MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM) + 68

#elif defined (__MMI_MAINLCD_240X320__) 
/* Nway stopwatch */
#define STPWACH_NWAY_CONTROL_AREA_X          19
#define STPWACH_NWAY_CONTROL_AREA_Y          18
#define STPWACH_NWAY_MAINTIMER_START_X       40
#define STPWACH_NWAY_MAINTIMER_START_Y       20
#define STPWACH_NWAY_MAINTIMER_END_X         (MAIN_LCD_DEVICE_WIDTH - 10)
#define STPWACH_NWAY_MAINTIMER_END_Y         60
#define STPWACH_NWAY_LISTTIMER_START_X       10
#define STPWACH_NWAY_LISTTIMER_START_Y       40
#define STPWACH_NWAY_LISTTIMER_END_X         (MAIN_LCD_DEVICE_WIDTH - 10)
#define STPWACH_NWAY_LISTTIMER_END_Y         (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 10)
#define STPWACH_NWAY_SEPARATOR_HEIGHT        30
#define STPWACH_NW_SPAC_SIDE                 0
#define STPWACH_NW_SPAC_TOP                  0
#define STPWACH_NW_FRAM_BORDER               3
/* Typical stopwatch */
#define WGUI_CAT_SW_TYP_MENUITEM_NUM         4
#define WGUI_CAT_SW_TYP_CONTROL_AREA_HEIGH   (MAIN_LCD_DEVICE_HEIGHT + MMI_STATUS_BAR_HEIGHT - MMI_BUTTON_BAR_HEIGHT + MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM) / 2
#define WGUI_CAT_SW_TYP_TIMER_X              (MAIN_LCD_DEVICE_WIDTH >> 1)
#define WGUI_CAT_SW_TYP_TIMER_Y              (MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM) + MMI_STATUS_BAR_HEIGHT + 66
#define WGUI_CAT_SW_TYP_MILSEC_X             (MAIN_LCD_DEVICE_WIDTH >> 1)
#define WGUI_CAT_SW_TYP_MILSEC_Y             (MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM) + MMI_STATUS_BAR_HEIGHT + 88

#elif defined (__MMI_MAINLCD_320X240__) 
/* Nway stopwatch */
#define STPWACH_NWAY_CONTROL_AREA_X          36
#define STPWACH_NWAY_CONTROL_AREA_Y          15
#define STPWACH_NW_SPAC_SIDE                 0
#define STPWACH_NW_SPAC_TOP                  0
#define STPWACH_NW_FRAM_BORDER               3
#define STPWACH_NWAY_MAINTIMER_START_X       40
#define STPWACH_NWAY_MAINTIMER_START_Y       20
#define STPWACH_NWAY_MAINTIMER_END_X         (MAIN_LCD_DEVICE_WIDTH - 10)
#define STPWACH_NWAY_MAINTIMER_END_Y         60
#define STPWACH_NWAY_LISTTIMER_START_X       10
#define STPWACH_NWAY_LISTTIMER_START_Y       40
#define STPWACH_NWAY_LISTTIMER_END_X         (MAIN_LCD_DEVICE_WIDTH - 10)
#define STPWACH_NWAY_LISTTIMER_END_Y         (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 10)
#define STPWACH_NWAY_SEPARATOR_HEIGHT        30
/* Typical stopwatch */
#define WGUI_CAT_SW_TYP_MENUITEM_NUM         4
#define WGUI_CAT_SW_TYP_CONTROL_AREA_HEIGH   (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT + MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM) / 2
#define WGUI_CAT_SW_TYP_TIMER_X              (MAIN_LCD_DEVICE_WIDTH >> 1)
#define WGUI_CAT_SW_TYP_TIMER_Y              (MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM) + 39
#define WGUI_CAT_SW_TYP_MILSEC_X             (MAIN_LCD_DEVICE_WIDTH >> 1) + 98
#define WGUI_CAT_SW_TYP_MILSEC_Y             (MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM) + 39

#elif defined (__MMI_MAINLCD_240X400__) 
/* Nway stopwatch */
#define STPWACH_NWAY_CONTROL_AREA_X          10
#define STPWACH_NWAY_CONTROL_AREA_Y          18
#define STPWACH_NWAY_MAINTIMER_START_X       20
#define STPWACH_NWAY_MAINTIMER_START_Y       20
#define STPWACH_NWAY_MAINTIMER_END_X         (MAIN_LCD_DEVICE_WIDTH - 10)
#define STPWACH_NWAY_MAINTIMER_END_Y         60
#define STPWACH_NWAY_LISTTIMER_START_X       10
#define STPWACH_NWAY_LISTTIMER_START_Y       40
#define STPWACH_NWAY_LISTTIMER_END_X         (MAIN_LCD_DEVICE_WIDTH - 10)
#define STPWACH_NWAY_LISTTIMER_END_Y         (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 10)
#define STPWACH_NWAY_SEPARATOR_HEIGHT        30
#define STPWACH_NW_SPAC_SIDE                 0
#define STPWACH_NW_SPAC_TOP                  0
#define STPWACH_NW_FRAM_BORDER               3
/* Typical stopwatch */
#define WGUI_CAT_SW_TYP_MENUITEM_NUM         6
#define WGUI_CAT_SW_TYP_CONTROL_AREA_HEIGH   (MAIN_LCD_DEVICE_HEIGHT + MMI_STATUS_BAR_HEIGHT - MMI_BUTTON_BAR_HEIGHT + MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM) / 2
#define WGUI_CAT_SW_TYP_TIMER_X              (MAIN_LCD_DEVICE_WIDTH >> 1)
#define WGUI_CAT_SW_TYP_TIMER_Y              (MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM) + MMI_STATUS_BAR_HEIGHT + 52
#define WGUI_CAT_SW_TYP_MILSEC_X             (MAIN_LCD_DEVICE_WIDTH >> 1) + 70
#define WGUI_CAT_SW_TYP_MILSEC_Y             (MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM) + MMI_STATUS_BAR_HEIGHT + 52

#elif defined (__MMI_MAINLCD_320X480__) 
/* Nway stopwatch */
#define STPWACH_NWAY_CONTROL_AREA_X          0
#define STPWACH_NWAY_CONTROL_AREA_Y          103
#define STPWACH_NWAY_MAINTIMER_START_X       0
#define STPWACH_NWAY_MAINTIMER_START_Y       0
#define STPWACH_NWAY_MAINTIMER_END_X         MAIN_LCD_DEVICE_WIDTH
#define STPWACH_NWAY_MAINTIMER_END_Y         120
#define STPWACH_NWAY_LISTTIMER_START_X       0
#define STPWACH_NWAY_LISTTIMER_START_Y       120
#define STPWACH_NWAY_LISTTIMER_END_X         MAIN_LCD_DEVICE_WIDTH
#define STPWACH_NWAY_LISTTIMER_END_Y         (MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 58)
#define STPWACH_NWAY_SEPARATOR_HEIGHT        0
#define STPWACH_NW_SPAC_SIDE                 0
#define STPWACH_NW_SPAC_TOP                  0
#define STPWACH_NW_FRAM_BORDER               3
/* Typical stopwatch */
#define WGUI_CAT_SW_TYP_MENUITEM_NUM         5
#define WGUI_CAT_SW_TYP_CONTROL_AREA_HEIGH   (MAIN_LCD_DEVICE_HEIGHT + MMI_STATUS_BAR_HEIGHT - MMI_BUTTON_BAR_HEIGHT + MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM - 58) / 2
#define WGUI_CAT_SW_TYP_TIMER_X              140
#define WGUI_CAT_SW_TYP_TIMER_Y              (MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM) + MMI_STATUS_BAR_HEIGHT + 50
#define WGUI_CAT_SW_TYP_MILSEC_X             275
#define WGUI_CAT_SW_TYP_MILSEC_Y             (MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM) + MMI_STATUS_BAR_HEIGHT + 50

#else
/* Nway stopwatch */
#define STPWACH_NWAY_CONTROL_AREA_X          0
#define STPWACH_NWAY_CONTROL_AREA_Y          0
#define STPWACH_NW_SPAC_SIDE                 0
#define STPWACH_NW_SPAC_TOP                  0
#define STPWACH_NW_FRAM_BORDER               0
#define STPWACH_NWAY_MAINTIMER_START_X       0
#define STPWACH_NWAY_MAINTIMER_START_Y       0
#define STPWACH_NWAY_MAINTIMER_END_X         0
#define STPWACH_NWAY_MAINTIMER_END_Y         0
#define STPWACH_NWAY_LISTTIMER_START_X       0
#define STPWACH_NWAY_LISTTIMER_START_Y       0
#define STPWACH_NWAY_LISTTIMER_END_X         0
#define STPWACH_NWAY_LISTTIMER_END_Y         0
#define STPWACH_NWAY_SEPARATOR_HEIGHT        0
/* Typical stopwatch */
#define WGUI_CAT_SW_TYP_MENUITEM_NUM         0
#define WGUI_CAT_SW_TYP_CONTROL_AREA_HEIGH   0
#define WGUI_CAT_SW_TYP_TIMER_X              0
#define WGUI_CAT_SW_TYP_TIMER_Y              0
#define WGUI_CAT_SW_TYP_MILSEC_X             0
#define WGUI_CAT_SW_TYP_MILSEC_Y             0
#endif 

#define STPWACH_UI_UPDATE_PERIOD          100   /* nWay Timer Refresh rate */
#define STOP_WATCH_ANIMATION_DELAY        1000  /* Use to draw the typical stopwatch background image */

#if defined (__MMI_MAINLCD_320X480__)
#define __MMI_CAT_STOPWATCH_PANEL__
#endif
/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */
/***************************************************************************** 
* Enum define
*****************************************************************************/
/* The flag for current screen. */
typedef enum _SCREEN_NAME
{
    NOT_STOPWATCH_SCR = 0,  /* Current screen is not stopwatch screen. */
    MP_TIMER_SCR,           /* Current screen is Nway stopwatch screen. */
    TYPICAL_TIMER_SCR       /* Current screen is Typical stopwatch screen. */
} SCREEN_NAME;

/* The flag for increasing timer. */
typedef enum _INCREMENT_TYPE
{
    NO_INCREMENT,             /* No timer increment. */
    TYP_TIMER_INCREMENT,      /* THe typical stopwatch is increasing. */
    MP_TITLE_TIME_INCREMENT,  /* The title timer of Nway stopwatch is increasing. */
    MP_LIST_TIMER_INCREMENT   /* The list timer of Nway stopwatch is increasing. */
} INCREMENT_TYPE;
/* DOM-NOT_FOR_SDK-END */

/***************************************************************************** 
* Structure define
*****************************************************************************/

/* The structure for one timer in stopwatch. */
typedef struct _UI_stop_watch
{
    S32 mili_sec;                     /* The counter for milliseconds. */
    S32 sec;                          /* The counter for seconds. */
    S32 min;                          /* The counter for minutes. */
    S32 hour;                         /* The counter for hours. */
    PS8 normalimagedata;              /* The image for normal list timer in multipurpose timer. */
    PS8 highlightimagedata;           /* The image for highlight timer in multipurpose timer. */
    U8 watch_string[TIMER_TEXT_SIZE]; /* Printable stopwatch timer string. */
} UI_stop_watch;

/* DOM-NOT_FOR_SDK-BEGIN */
typedef struct _stop_watch_history
{
    U16 history_ID;
    S32 highlight_item;
    U8 cur_stop_play_flag;
} UI_stop_watch_history;

typedef struct _wtch_coor_type
{
    U16 x;
    U16 y;
    U32 width;
    U32 height;
} wtch_coor_type;

typedef struct _wtchSkinResStruct
{
    /* typical stopwatch */
    wtch_coor_type typ_timer;
    wtch_coor_type typ_milsec;

    /* nWay stopwatch */
    U16 separator_height;
    wtch_coor_type nWay_maintimer_start;
    wtch_coor_type nWay_maintimer_end;
    wtch_coor_type nWay_dialog_start;
    wtch_coor_type nWay_dialog_end;  
} wtchSkinResStruct;

typedef struct _cat306_screen_info_cntx
{
    S32 text_x_offset;          /* Active indivial timer text x coordinate */
    S32 text_y_offset;          /* Active indivial timer text y coordinate */
    S32 img_x_offset;           /* Active indivial timer image x coordinate */
    S32 img_y_offset;           /* Active indivial timer image y coordinate */
    S32 area_height;            /* Active indivial timer area height */
    S32 img_width;              /* Active indivial timer image height */
    S32 img_height;             /* Active indivial timer image height */
    S32 text_width;             /* Active indivial timer text height */
    S32 text_height;            /* Active indivial timer text height */
    S32 text_hilite_height;     /* Active indivial timer text height */
} cat306_screen_info_cntx;      /* nWay stopwatch position variable */

typedef struct _cat307_screen_info_cntx
{
    S32 image_x;
    S32 image_y;
    S32 image_width;
    S32 image_height;
    U16 bkg_img;
    S32 center_mili;
    S32 center_sec;
    S32 center_hr;
    S32 center_min;
    U8  watch_string[MAX_TIMER_RECORDS][TIMER_TEXT_SIZE];
#ifdef __MMI_FTE_SUPPORT__
    PU8 num_image[WGUI_CAT307_NUM_NUMERIC_IMAGE];
    PU8 colon_image;
    PU8 dot_image;
    
    S32 num_image_x[WGUI_CAT307_NUM_MAIN_TIMER];
    S32 num_image_y;
    S32 num_image_w;
    S32 num_image_h;
    
    S32 symbol_image_x[WGUI_CAT307_NUM_SYMBOL];
    S32 symbol_image_w;
#endif
} cat307_screen_info_cntx;      /* Typical stopwatch position variable */
/* DOM-NOT_FOR_SDK-END */


/***************************************************************************** 
* Function define
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  wgui_catsw_update_panel
 * DESCRIPTION
 *  Update the panel area for stopwatch.
 *  This function depended on the compile option: __MMI_CAT_STOPWATCH_PANEL__
 * PARAMETERS
 *  panel_area_data       : [IN] (N/A) The information of the panel.
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_catsw_update_panel(wgui_panel_area_struct *panel_area_data);

/*************************************************************************************************
  * FUNCTION:  ShowCategory306Screen
  * Description
  * Displays the multipurpose timer.
  * 
  * <img name="wgui_cat306_img1" />
  * Parameters
  * title_values :        [IN] (N/A) Value to be shown in the title.
  * left_softkey :        [IN] (LSK) String ID of left softkey.
  * left_softkey_icon :   [IN] (N/A) Image ID of left softkey.
  * right_softkey :       [IN] (RSK) String ID of right softkey.
  * right_softkey_icon :  [IN] (N/A) Image ID of right softkey.
  * stop_watch_list :     [IN] (N/A) List timer of stop watchs in the display area.
  * history_buffer :      [IN] (N/A) History buffer.
  * highlight_item :      [IN] (N/A) Currently highlighted list timer.
  * Returns
  *  void
  * Example
  * <code>
  *  void EntryScreen_306(void)
  *  {
  *       U8 index;
  *       U8 *guiBuffer = NULL;
  *       UI_stop_watch stopWatchBuffer[MAX_TIMER_RECORDS];
  *       UI_stop_watch lastStopWatchBuffer;
  * 
  *       EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  *       memset(stopWatchBuffer, 0, sizeof(stopWatchBuffer));
  *       memset(&amp;lastStopWatchBuffer, 0, sizeof(lastStopWatchBuffer));
  * 
  *       for (index = 0; index &lt; MAX_TIMER_RECORDS; index++)
  *       {
  *           stopWatchBuffer[index].normalimagedata = GetImage((U16) (IMG_GLOBAL_L1 + index));
  *           stopWatchBuffer[index].highlightimagedata = GetImage((U16) (IMG_GLOBAL_L1 + index));
  *       }
  * 
  *       ShowCategory306Screen(
  *           lastStopWatchBuffer,
  *           0,
  *           STR_ID_CSB_DUMMY_TEXT,
  *           STR_ID_CSB_LSK_TEXT,
  *           0,
  *           STR_ID_CSB_RSK_TEXT,
  *           0,
  *           4,
  *           stopWatchBuffer,
  *           0,
  *           STR_ID_CSB_DUMMY_TEXT,
  *           guiBuffer,
  *           0);
  * 
  *       csb_set_key_handlers();
  *   }
  * </code>                                                                                       
  *************************************************************************************************/
extern void ShowCategory306Screen(
                UI_stop_watch *title_values,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                UI_stop_watch *stop_watch_list,
                U8 *history_buffer,
                S32 highlight_item);

/****************************************************************************
  * FUNCTION
  *  ShowCategory306PanelScreen
  * Description
  *  Displays the multipurpose timer with panel area.
  *  This function depended on the compile option: __MMI_CAT_STOPWATCH_PANEL__
  *
  *  <img name="wgui_cat306_img2" />
  * Parameters
  * title_values :          [IN] (N/A) Value to be shown in the title.
  * left_softkey :          [IN] (LSK) String ID of left softkey.
  * left_softkey_icon :     [IN] (N/A) Image ID of left softkey.
  * right_softkey :         [IN] (RSK) String ID of right softkey.
  * right_softkey_icon :    [IN] (N/A) Image ID of right softkey.
  * stop_watch_list :       [IN] (N/A) List timer of stop watchs in the display area.
  * panel_area_data :       [IN] (N/A) The information of the panel.
  * history_buffer :        [IN] (N/A) History buffer.
  * highlight_item :        [IN] (N/A) Currently highlighted list timer.
  * Returns
  *  void                                                                    
  ****************************************************************************/
extern void ShowCategory306PanelScreen(
                UI_stop_watch *title_values,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                UI_stop_watch *stop_watch_list,
                wgui_panel_area_struct *panel_area_data, 
                U8 *history_buffer,
                S32 highlight_item);

/* DOM-NOT_FOR_SDK-BEGIN */
extern void ExitCategory306Screen(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  GetMultipurposeTimeValues
 * DESCRIPTION
 *  Get the index of current highlight timer in multipurpose stopwatch.
 * PARAMETERS
 *  high_light       : [OUT] (N/A) The index of the highlight list timer.
 * RETURNS
 *  void
 *****************************************************************************/
extern void GetMultipurposeTimeValues(S32 *high_light);

/*****************************************************************************
 * FUNCTION
 *  stop_multipurpose_timers
 * DESCRIPTION
 *  Stop the multipurpose stopwatch.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void stop_multipurpose_timers(void);

/*****************************************************************************
 * FUNCTION
 *  start_multipurpose_list_watch
 * DESCRIPTION
 *  This function is to start certain list timer in multipurpose stopwatch.
 * PARAMETERS
 *  index       : [IN] (N/A) The index of the list timer which will be start.
 * RETURNS
 *  void
 *****************************************************************************/
extern void start_multipurpose_list_watch(U8 index);

/*****************************************************************************
 * FUNCTION
 *  reset_all_multipurpose_time
 * DESCRIPTION
 *  Stop and reset all the timer in multipurpose stopwatch.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void reset_all_multipurpose_time(void);

/* DOM-NOT_FOR_SDK-BEGIN */
extern U8 *get_category306_history(U8 *history_buffer);
extern S32 get_category306_history_size(void);
/* DOM-NOT_FOR_SDK-END */

#if defined (__MMI_FTE_SUPPORT__) 
/****************************************************************************
 * FUNCTION
 *  ShowCategory307Screen
 * Description
 *  Displays the typical stopwatch.
 *  [FTE]: support(tool bar is avaiable)
 *
 *  <img name="wgui_cat307_img_1_FTE" />
 * Parameters
 * left_softkey :          [IN] (LSK) String ID of left softkey.
 * left_softkey_icon :     [IN] (N/A) Image ID of left softkey.
 * right_softkey :         [IN] (RSK) String ID of right softkey.
 * right_softkey_icon :    [IN] (N/A) Image ID of right softkey.
 * number_of_items :       [IN] (N/A) Number of the records.
 * list_watch      :       [IN] (ICONTEXT) The records list of the timer.
 * highlight_item :        [IN] (N/A) Currently highlighted list item.
 * history_buffer :        [IN] (N/A) History buffer.
 * bkg_image :             [IN] (N/A) Image ID of background image.
 *  num_image :            [IN] (N/A) number image.
 *  colon_image :          [IN] (N/A) colon image.
 *  dot_image :            [IN] (N/A) dot image.
 * start_continue_flag :   [IN] (N/A) Status of the stopwatch.
 * Returns
 *  void    
 * Example
 * <code>
 *  void EntryScreen_307(void)
 *  {
 *      U8 *guiBuffer = NULL;
 *      EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 *
 *      ShowCategory307Screen(
 *          STR_ID_CSB_LSK_TEXT,
 *          0,
 *          STR_ID_CSB_RSK_TEXT,
 *          0,
 *          0,
 *          NULL,
 *          0,
 *          guiBuffer,
 *          STOPWATCH_BG,
 *          number_image,
 *          colon_image,
 *          dot_image,
 *          0);
 *
 *       csb_set_key_handlers();
 *   }
 * </code>                                                           
****************************************************************************/
extern void ShowCategory307Screen(
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        UI_stop_watch *list_watch,
        S32 highlighted_item,
        U8 *history_buffer,
        U16 bkg_image,
        PU8* num_image,
        PU8 colon_image,
        PU8 dot_image,
        S32 start_continue_flag);
#else
/****************************************************************************
  * FUNCTION
  *  ShowCategory307Screen
  * Description
  *  Displays the typical stopwatch.
  *
  *  <img name="wgui_cat307_img1" />
  * Parameters
  * left_softkey :          [IN] (LSK) String ID of left softkey.
  * left_softkey_icon :     [IN] (N/A) Image ID of left softkey.
  * right_softkey :         [IN] (RSK) String ID of right softkey.
  * right_softkey_icon :    [IN] (N/A) Image ID of right softkey.
  * number_of_items :       [IN] (N/A) Number of the records.
  * list_watch      :       [IN] (ICONTEXT) The records list of the timer.
  * highlight_item :        [IN] (N/A) Currently highlighted list item.
  * history_buffer :        [IN] (N/A) History buffer.
  * bkg_image :             [IN] (N/A) Image ID of background image.
  * start_continue_flag :   [IN] (N/A) Status of the stopwatch.
  * Returns
  *  void    
  * Example
  * <code>
  *  void EntryScreen_307(void)
  *  {
  *      U8 *guiBuffer = NULL;
  *      EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  *
  *      ShowCategory307Screen(
  *          STR_ID_CSB_LSK_TEXT,
  *          0,
  *          STR_ID_CSB_RSK_TEXT,
  *          0,
  *          0,
  *          NULL,
  *          0,
  *          guiBuffer,
  *          STOPWATCH_BG,
  *          0);
  *
  *       csb_set_key_handlers();
  *   }
  * </code>                                                           
  ****************************************************************************/
extern void ShowCategory307Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                UI_stop_watch *list_watch,
                S32 highlighted_item,
                U8 *history_buffer,
                U16 bkg_image,
                S32 start_stop_flag);
#endif

/****************************************************************************
  * FUNCTION
  *  ShowCategory307PanelScreen
  * Description
  *  Displays the typical stopwatch with panel area.
  *  This function depended on the compile option: __MMI_CAT_STOPWATCH_PANEL__
  *
  *  <img name="wgui_cat307_img2" />
  * Parameters
  * left_softkey :          [IN] (LSK) String ID of left softkey.
  * left_softkey_icon :     [IN] (N/A) Image ID of left softkey.
  * right_softkey :         [IN] (RSK) String ID of right softkey.
  * right_softkey_icon :    [IN] (N/A) Image ID of right softkey.
  * number_of_items :       [IN] (N/A) Number of the records.
  * list_watch      :       [IN] (ICONTEXT) The records list of the timer.
  * highlight_item :        [IN] (N/A) Currently highlighted list item.
  * bkg_image :             [IN] (N/A) Image ID of background image.
  * panel_area_data :       [IN] (N/A) The information of the panel.
  * start_continue_flag :   [IN] (N/A) Status of the stopwatch.
  * history_buffer :        [IN] (N/A) History buffer.
  * Returns
  *  void                                                                    
  ****************************************************************************/
extern void ShowCategory307PanelScreen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                UI_stop_watch *list_watch,
                S32 highlighted_item,
                U16 bkg_image,
                wgui_panel_area_struct *panel_area_data, 
                S32 start_continue_flag,
                U8 *history_buffer);

/* DOM-NOT_FOR_SDK-BEGIN */
extern void ExitCategory307Screen(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  UpdateHistoryValue
 * DESCRIPTION
 *  This function is to add a new record to history list.
 * PARAMETERS
 *  mili       : [IN] (N/A) The millisecond for the record.
 *  hr         : [IN] (N/A) The hour for the record.
 *  min        : [IN] (N/A) The minute for the record.
 *  sec        : [IN] (N/A) The second for the record.
 * RETURNS
 *  void
 *****************************************************************************/
extern void UpdateHistoryValue(S32 *mili, S32 *hr, S32 *min, S32 *sec);

/*****************************************************************************
 * FUNCTION
 *  reset_timer
 * DESCRIPTION
 *  Stop and reset the timer in typical stopwatch.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void reset_timer(void);

/*****************************************************************************
 * FUNCTION
 *  start_stop_watch_timer
 * DESCRIPTION
 *  This function is to start or stop the timer for typical stopwatch.
 * PARAMETERS
 *  start_stop_flag     : [IN] (N/A) The flag for start or stop.
 * RETURNS
 *  void
 *****************************************************************************/
extern void start_stop_watch_timer(U8 start_stop_flag);

/* DOM-NOT_FOR_SDK-BEGIN */
extern void change_stopwatchtime_to_string(S32, S32, S32, S32, U8 *, U8);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  initialize_stop_watch_timer
 * DESCRIPTION
 *  Initialize the typical stopwatch.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void initialize_stop_watch_timer(void);

/* DOM-NOT_FOR_SDK-BEGIN */
extern U8 *get_category307_history(U8 *history_buffer);
extern S32 get_category307_history_size(void);

///TODO: START should be delete after "wgui_draw_manage.c" is revised    
extern void show_nway_stop_watch(void);
extern void show_typical_stop_watch(void);
///TODO: END


#ifdef __MMI_TOUCH_SCREEN__

///TODO: START should be delete after "Wgui_touch_screen.c" is revised    
extern MMI_BOOL wgui_stopwatch_pen_down_hdlr(mmi_pen_point_struct point, S32 *index);
///TODO: END
extern MMI_BOOL wgui_stopwatch_get_active_timer_index(mmi_pen_point_struct point, S32 *index);
extern MMI_BOOL gui_stopwatch_translate_penevent(S32 x, S32 y, S32 *index);
extern void wgui_stopwatch_pen_down_handler(mmi_pen_point_struct point);

#endif /* __MMI_TOUCH_SCREEN__ */ 
/* DOM-NOT_FOR_SDK-END */

#endif /* __WGUI_CATEGORIES_STOPWATCH_H__ */ 


