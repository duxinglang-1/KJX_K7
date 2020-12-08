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
 *   gui_font_size.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Adaptation layer of vector font
 *
 * Author:
 * -------
 * -------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/


#ifndef __GUI_FONT_SIZE_H__
#define __GUI_FONT_SIZE_H__

#include "MMI_features.h"
#include "gui_data_types.h"

typedef enum
{
    GUI_FONT_SIZE_DEFAULT,                              //default font
    GUI_FONT_SIZE_BUTTON,                               //button font
    GUI_FONT_SIZE_MULTITAP,                             //multitap font
    GUI_FONT_SIZE_INPUTBOX,                             //inputbox font
    GUI_FONT_SIZE_LIST,                                 //list font
    GUI_FONT_SIZE_MATRIX,                               //matrix font
    GUI_FONT_SIZE_MENUBAR_INDEX,                        //menubar index font
    GUI_FONT_SIZE_MENUBAR_ITEM,                         //menubar item font
    GUI_FONT_SIZE_SHORTCUT,                             //shortcut font
    GUI_FONT_SIZE_TITLE,                                //title font
    GUI_FONT_SIZE_DROPDOWN,                             //dropdown font
    GUI_FONT_SIZE_LIST_MAINMENU,                        // list main menu font
    GUI_FONT_SIZE_MATRIX_MAINMENU,                      //matrix main menu font
    GUI_FONT_SIZE_VIRTUAL_KEYBOARD,                     //virtual keyboard font
    GUI_FONT_SIZE_DATE,                                 //date font
    GUI_FONT_SIZE_TIME,                                 //time font
    GUI_FONT_SIZE_SUB_DATE,                             //sublcd date font
    GUI_FONT_SIZE_SUB_TIME,                             //sublcd time font
    GUI_FONT_SIZE_TAB_TITLE,                            //tab title font
    GUI_FONT_SIZE_CALENDAR_INFOBOX,                     //infobox font in calendar
    GUI_FONT_SIZE_CALENDAR_HORIZONTAL_STRING,           //horizontal string font in calendar
    GUI_FONT_SIZE_CALENDAR_CELL,                        //cell font in calendar
    GUI_FONT_SIZE_IDLE_CALENDAR_HORIZONTAL,             //horizontal font in idle calendar
    GUI_FONT_SIZE_IDLE_CALENDAR_CELL,                   //cell font in calendar
    GUI_FONT_SIZE_DCD_IDLE,                             //dcd font
    GUI_FONT_SIZE_IME_TEXT,                             //ime text font
    GUI_FONT_SIZE_IME_LABEL,                            //ime label font
    GUI_FONT_SIZE_DURATION,                             //duration font
    GUI_FONT_SIZE_DAY,                                  //day font
    GUI_FONT_SIZE_DATE_IDLESCREEN1,                     //date font of idle screen1
    GUI_FONT_SIZE_TIME_IDLESCREEN1,                     //time font of idle screen1
#ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__
    GUI_FONT_SIZE_DT_STATUS_BAR_AT_BOTTOM,              //datetime font of idle screen when status bar at bottom
#endif
    GUI_FONT_SIZE_TIME_NETWORK_SEARCH,                  //time font of network search
    GUI_FONT_SIZE_DURATION_ACTIVE_CALL,                 //duration of active call
    GUI_FONT_SIZE_DURATION_CONF_CALL,                   //duration font of conf call

#ifdef __MMI_SUBLCD_DATE_LARGE_FONT__
    GUI_FONT_SIZE_SUB_LARGE_DATE,                       //sublcd large date font
#endif
#ifdef __MMI_SUBLCD_TIME_LARGE_FONT__
    GUI_FONT_SIZE_SUB_LARGE_TIME,                       //sublcd large time font
    GUI_FONT_SIZE_SUB_LARGE_TIME_IDLESCREEN3,           //sublcd large time font for sublcd idlescreen3
#endif
    GUI_FONT_SIZE_SUB_DATE_IDLESCREEN4,                 //sublcd date font for sublcd idlescreen4
    GUI_FONT_SIZE_SUB_TIME_IDLESCREEN4,                 //sublcd time font for sublcd idlescreen4
    GUI_FONT_SIZE_TIME_DIGITAL_CLOCK_SC,                //time font for digital clock screen
    GUI_FONT_SIZE_DURATION_AUDIO_PLAY,                  //duration font for audio player
    GUI_FONT_SIZE_DOW_SELECT,                           //DOW select font


    GUI_FONT_SIZE_IDLE_NETWORK_NAME,                     //network name font
    GUI_FONT_SIZE_IDLE_NETWORK_STATUS,                   //network status name font
    GUI_FONT_SIZE_IDLE_DATE,                             //network date font
    GUI_FONT_SIZE_DIALER,                               //dialer font
    GUI_FONT_SIZE_INFOBOX,                              //infobox font
    GUI_FONT_SIZE_DIALER_LARGE,                         //large dialer font
    GUI_FONT_SIZE_DIALER_SMALL,                         //small dialer font
    GUI_FONT_SIZE_CALENDAR_TITLE,                       //title font in calendar
    GUI_FONT_SIZE_CALENDAR_HORIZONTAL_SELECT,           //horizontal select font in calendar
    GUI_FONT_SIZE_CALENDAR_POPUP,                       //popup font in calendar

    GUI_FONT_SIZE_CALENDAR_IDLE_L_CUR_DAY,              //calendar idle large current day 
    GUI_FONT_SIZE_CALENDAR_IDLE_L_CUR_DATE,             //calendar idle large current date 
    GUI_FONT_SIZE_CALENDAR_VERTICAL_SELECT,             //calendar vertical select font
    GUI_FONT_SIZE_CALENDAR_CURRENT,                     //calendar curent font
    GUI_FONT_SIZE_ICONBAR_HINT,                         //icon bar hint font
    GUI_FONT_SIZE_VK_LARGE_ICON,                        //virtual keyboard key large icon font
    GUI_FONT_SIZE_STATUS_BAR_TIME,                      //status icon bar time
    GUI_FONT_SIZE_POPUP_EMBEDDED_SOFTKEY,               //popup embeded softkey text
    GUI_FONT_SIZE_LIST_HIGHLIGHT,                       //highlight list font

    GUI_FONT_SIZE_STOPWATCH_DURATION,                   //Main timer in Stopwatch
    GUI_FONT_SIZE_STOPWATCH_NWAY_TIME,                  //Nway stopwatch stoped timer
    GUI_FONT_SIZE_STOPWATCH_NWAY_HILITE,                //Nway stopwatch running timer
    
    GUI_FONT_SIZE_ICONBAR_ITEM_TEXT,                   //item's text in icon bar

    GUI_FONT_SIZE_IDLE_CALENDAR_TITLE,                   //calendar idle title text
    GUI_FONT_SIZE_TOTAL
} gui_font_size_enum;

extern /*const*/ UI_font_type gui_font_get_type(gui_font_size_enum index);

#endif /* __GUI_FONT_SIZE_H__ */ 


