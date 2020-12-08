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
 *  gui_font_oem.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  OEM layer of vector font
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *     HISTORY
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
 *==============================================================================
 *******************************************************************************/


#include "MMI_features.h"
#include "gui_font_oem.h"
#include "gui_font_size.h"


#ifdef __MMI_VECTOR_FONT_SUPPORT__
/*****************************************************************************              
 * Local Function                                                                    
 *****************************************************************************/
#define GUI_XXSMALL_FONT_SIZE    4
#define GUI_XSMALL_FONT_SIZE     8
#define GUI_SMALL_FONT_SIZE     14
#define GUI_MEDIUM_FONT_SIZE    19
#define GUI_LARGE_FONT_SIZE     24
#define GUI_XLARGE_FONT_SIZE    27
#define GUI_XXLARGE_FONT_SIZE    29
#define GUI_XXXLARGE_FONT_SIZE   31

#define GUI_FONT_TYPE_BOLD      0x80
#define GUI_FONT_TYPE_ITALIC    0x40

#if defined(__MMI_MAINLCD_480X800__)



const static U8 g_gui_font_type_data[GUI_FONT_SIZE_TOTAL] = 
{
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DEFAULT
    GUI_LARGE_FONT_SIZE,                                      //GUI_FONT_SIZE_BUTTON
    GUI_LARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_MULTITAP
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_INPUTBOX
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_LIST
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_MATRIX
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_MENUBAR_INDEX
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_MENUBAR_ITEM
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_SHORTCUT
    GUI_LARGE_FONT_SIZE,                                      //GUI_FONT_SIZE_TITLE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DROPDOWN
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_LIST_MAINMENU
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_MATRIX_MAINMENU
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_VIRTUAL_KEYBOARD
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DATE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_TIME
    GUI_SMALL_FONT_SIZE,                                        //GUI_FONT_SIZE_SUB_DATE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_SUB_TIME
    GUI_LARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_TAB_TITLE
    GUI_SMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_INFOBOX
    GUI_SMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_HORIZONTAL_STRING
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_CELL
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_CALENDAR_HORIZONTAL
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_CALENDAR_CELL
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DCD_IDLE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_IME_TEXT
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_IME_LABEL
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_DURATION
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DAY

#if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)                   //GUI_FONT_SIZE_DATE_IDLESCREEN1
    GUI_XXLARGE_FONT_SIZE,
#else
    GUI_MEDIUM_FONT_SIZE,
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */

#if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)                    //GUI_FONT_SIZE_TIME_IDLESCREEN1
    GUI_XXLARGE_FONT_SIZE,
#else
    GUI_MEDIUM_FONT_SIZE,
#endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */

#ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__                          //GUI_FONT_SIZE_DT_STATUS_BAR_AT_BOTTOM
    GUI_SMALL_FONT_SIZE,
#endif
    GUI_XSMALL_FONT_SIZE,                                        //GUI_FONT_SIZE_TIME_NETWORK_SEARCH
    GUI_XSMALL_FONT_SIZE,                                        //GUI_FONT_SIZE_DURATION_ACTIVE_CALL
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_DURATION_CONF_CALL
#ifdef __MMI_SUBLCD_DATE_LARGE_FONT__
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_SUB_LARGE_DATE
#endif
#ifdef __MMI_SUBLCD_TIME_LARGE_FONT__
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_SUB_LARGE_TIME
    GUI_XXSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_SUB_LARGE_TIME_IDLESCREEN3
#endif /* __MMI_SUBLCD_TIME_LARGE_FONT__ */
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_SUB_DATE_IDLESCREEN4
    GUI_XXSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_SUB_TIME_IDLESCREEN4
#ifdef __MMI_UI_DALMATIAN_IDLESCREEN__                          //GUI_FONT_SIZE_TIME_DIGITAL_CLOCK_SC
    GUI_MEDIUM_FONT_SIZE,
#else
    GUI_LARGE_FONT_SIZE,
#endif /* GUI_FONT_SIZE_DIGITAL_CLOCK_SC */
#ifdef __MMI_UI_DALMATIAN_IDLESCREEN__                          //GUI_FONT_SIZE_DURATION_AUDIO_PLAY
    GUI_MEDIUM_FONT_SIZE,
#else
    GUI_LARGE_FONT_SIZE,
#endif /* GUI_FONT_SIZE_DIGITAL_CLOCK_SC */
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DOW_SELECT
    GUI_LARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_NETWORK_NAME
    GUI_LARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_NETWORK_STATUS
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_DATE
    GUI_XXLARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_DIALER
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_INFOBOX
    GUI_XXLARGE_FONT_SIZE,                                      //GUI_FONT_SIZE_DIALER_LARGE
    GUI_LARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_DIALER_SMALL
#ifndef __MMI_FTE_SUPPORT__
    GUI_XLARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_TITLE
#else
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_TITLE
#endif
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_HORIZONTAL_SELECT
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_POPUP
    GUI_MEDIUM_FONT_SIZE,                                     //GUI_FONT_SIZE_CALENDAR_IDLE_L_CUR_DAY
    GUI_XXXLARGE_FONT_SIZE,                                     //GUI_FONT_SIZE_CALENDAR_IDLE_L_CUR_DATE
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_VERTICAL_SELECT
    GUI_MEDIUM_FONT_SIZE,                                        //GUI_FONT_SIZE_CALENDAR_CURRENT
#ifndef __MMI_FTE_SUPPORT__
    GUI_SMALL_FONT_SIZE,                                        //GUI_FONT_SIZE_ICONBAR_HINT
#else
    GUI_MEDIUM_FONT_SIZE,                                      //GUI_FONT_SIZE_ICONBAR_HINT
#endif
    GUI_XLARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_VK_LARGE_ICON
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_STATUS_BAR_TIME
    GUI_XLARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_POPUP_EMBEDDED_SOFTKEY
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_LIST_HIGHLIGHT

    GUI_XXXLARGE_FONT_SIZE,                                     //GUI_FONT_SIZE_STOPWATCH_DURATION,   
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_STOPWATCH_NWAY_TIME,  
    GUI_XLARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_STOPWATCH_NWAY_HILITE,

#ifndef __MMI_FTE_SUPPORT__
    GUI_MEDIUM_FONT_SIZE,                                      //GUI_FONT_SIZE_ICONBAR_ITEM_TEXT
#else
    GUI_MEDIUM_FONT_SIZE,                                      //GUI_FONT_SIZE_ICONBAR_ITEM_TEXT
#endif

#ifndef __MMI_VUI_HOMESCREEN__
    GUI_XSMALL_FONT_SIZE,                                      //GUI_FONT_SIZE_IDLE_CALENDAR_TITLE
#else
    GUI_XSMALL_FONT_SIZE,                                      //GUI_FONT_SIZE_IDLE_CALENDAR_TITLE
#endif

};
const static stFontAttribute g_gui_font_oem_data [] =
{
    {0,0,0,0x80|12,0,1	},
    {0,0,0,0x80|14,0,1	},
    {0,0,0,0x80|21,0,1	},
    {0,0,0,0x80|30,0,1	},    
    {0,0,0,0x80|36,0,1	},
    {0,0,0,0x80|40,0,1	},    
    {0,0,0,0x80|48,0,1	},
    {0,0,0,0x80|48,0,1	},
};

const static stFontAttribute g_gui_font_oem_data_B [] =
{
    {1,0,0,0x80|12,0,1	},
    {1,0,0,0x80|14,0,1	},
    {1,0,0,0x80|21,0,1	},
    {1,0,0,0x80|30,0,1	},
    {1,0,0,0x80|36,0,1	},
    {1,0,0,0x80|40,0,1	},
    {1,0,0,0x80|48,0,1	},
    {1,0,0,0x80|48,0,1	},
};

const static stFontAttribute g_gui_font_oem_data_I [] =
{
    {0,1,0,0x80|12,0,1	},
    {0,1,0,0x80|14,0,1	},
    {0,1,0,0x80|21,0,1	},
    {0,1,0,0x80|30,0,1	},
    {0,1,0,0x80|36,0,1	},
    {0,1,0,0x80|40,0,1	},
    {0,1,0,0x80|48,0,1	},
    {0,1,0,0x80|48,0,1	},
};

const static stFontAttribute g_gui_font_oem_data_BI [] =
{
    {1,1,0,0x80|12,0,1	},
    {1,1,0,0x80|14,0,1	},
    {1,1,0,0x80|21,0,1	},
    {1,1,0,0x80|30,0,1	},
    {1,1,0,0x80|36,0,1	},
    {1,1,0,0x80|40,0,1	},
    {1,1,0,0x80|48,0,1	},
    {0,1,0,0x80|48,0,1	},
};

const static U8 g_gui_font_oem_map[] = 
{
    0,0,0,0,0,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4,5,5,5,6,6,7,7,
};



#elif defined(__MMI_MAINLCD_320X480__)

const static U8 g_gui_font_type_data[GUI_FONT_SIZE_TOTAL] = 
{
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DEFAULT
    GUI_LARGE_FONT_SIZE,                                      //GUI_FONT_SIZE_BUTTON
    GUI_LARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_MULTITAP
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_INPUTBOX
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_LIST
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_MATRIX
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_MENUBAR_INDEX
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_MENUBAR_ITEM
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_SHORTCUT
    GUI_LARGE_FONT_SIZE,                                      //GUI_FONT_SIZE_TITLE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DROPDOWN
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_LIST_MAINMENU
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_MATRIX_MAINMENU
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_VIRTUAL_KEYBOARD
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DATE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_TIME
    GUI_SMALL_FONT_SIZE,                                        //GUI_FONT_SIZE_SUB_DATE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_SUB_TIME
    GUI_LARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_TAB_TITLE
    GUI_SMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_INFOBOX
    GUI_SMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_HORIZONTAL_STRING
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_CELL
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_CALENDAR_HORIZONTAL
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_CALENDAR_CELL
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DCD_IDLE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_IME_TEXT
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_IME_LABEL
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_DURATION
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DAY

#if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)                   //GUI_FONT_SIZE_DATE_IDLESCREEN1
    GUI_XXLARGE_FONT_SIZE,
#else
    GUI_MEDIUM_FONT_SIZE,
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */

#if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)                    //GUI_FONT_SIZE_TIME_IDLESCREEN1
    GUI_XXLARGE_FONT_SIZE,
#else
    GUI_MEDIUM_FONT_SIZE,
#endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */

#ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__                          //GUI_FONT_SIZE_DT_STATUS_BAR_AT_BOTTOM
    GUI_SMALL_FONT_SIZE,
#endif
    GUI_XSMALL_FONT_SIZE,                                        //GUI_FONT_SIZE_TIME_NETWORK_SEARCH
    GUI_XSMALL_FONT_SIZE,                                        //GUI_FONT_SIZE_DURATION_ACTIVE_CALL
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_DURATION_CONF_CALL
#ifdef __MMI_SUBLCD_DATE_LARGE_FONT__
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_SUB_LARGE_DATE
#endif
#ifdef __MMI_SUBLCD_TIME_LARGE_FONT__
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_SUB_LARGE_TIME
    GUI_XXSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_SUB_LARGE_TIME_IDLESCREEN3
#endif /* __MMI_SUBLCD_TIME_LARGE_FONT__ */
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_SUB_DATE_IDLESCREEN4
    GUI_XXSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_SUB_TIME_IDLESCREEN4
#ifdef __MMI_UI_DALMATIAN_IDLESCREEN__                          //GUI_FONT_SIZE_TIME_DIGITAL_CLOCK_SC
    GUI_MEDIUM_FONT_SIZE,
#else
    GUI_LARGE_FONT_SIZE,
#endif /* GUI_FONT_SIZE_DIGITAL_CLOCK_SC */
#ifdef __MMI_UI_DALMATIAN_IDLESCREEN__                          //GUI_FONT_SIZE_DURATION_AUDIO_PLAY
    GUI_MEDIUM_FONT_SIZE,
#else
    GUI_LARGE_FONT_SIZE,
#endif /* GUI_FONT_SIZE_DIGITAL_CLOCK_SC */
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DOW_SELECT
    GUI_LARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_NETWORK_NAME
    GUI_LARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_NETWORK_STATUS
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_DATE
    GUI_XXLARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_DIALER
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_INFOBOX
    GUI_XXLARGE_FONT_SIZE,                                      //GUI_FONT_SIZE_DIALER_LARGE
    GUI_LARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_DIALER_SMALL
#ifndef __MMI_FTE_SUPPORT__
    GUI_XLARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_TITLE
#else
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_TITLE
#endif
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_HORIZONTAL_SELECT
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_POPUP
    GUI_MEDIUM_FONT_SIZE,                                     //GUI_FONT_SIZE_CALENDAR_IDLE_L_CUR_DAY
    GUI_XXXLARGE_FONT_SIZE,                                     //GUI_FONT_SIZE_CALENDAR_IDLE_L_CUR_DATE
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_VERTICAL_SELECT
    GUI_MEDIUM_FONT_SIZE,                                        //GUI_FONT_SIZE_CALENDAR_CURRENT
#ifndef __MMI_FTE_SUPPORT__
    GUI_SMALL_FONT_SIZE,                                        //GUI_FONT_SIZE_ICONBAR_HINT
#else
    GUI_MEDIUM_FONT_SIZE,                                      //GUI_FONT_SIZE_ICONBAR_HINT
#endif
    GUI_XLARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_VK_LARGE_ICON
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_STATUS_BAR_TIME
    GUI_XLARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_POPUP_EMBEDDED_SOFTKEY
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_LIST_HIGHLIGHT

    GUI_XXXLARGE_FONT_SIZE,                                     //GUI_FONT_SIZE_STOPWATCH_DURATION,   
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_STOPWATCH_NWAY_TIME,  
    GUI_XLARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_STOPWATCH_NWAY_HILITE,

#ifndef __MMI_FTE_SUPPORT__
    GUI_MEDIUM_FONT_SIZE,                                      //GUI_FONT_SIZE_ICONBAR_ITEM_TEXT
#else
    GUI_MEDIUM_FONT_SIZE,                                      //GUI_FONT_SIZE_ICONBAR_ITEM_TEXT
#endif

#ifndef __MMI_VUI_HOMESCREEN__
    GUI_XSMALL_FONT_SIZE,                                      //GUI_FONT_SIZE_IDLE_CALENDAR_TITLE
#else
    GUI_XSMALL_FONT_SIZE,                                      //GUI_FONT_SIZE_IDLE_CALENDAR_TITLE
#endif

};
const static stFontAttribute g_gui_font_oem_data [] =
{
    {0,0,0,0x80|12,0,1	},
    {0,0,0,0x80|14,0,1	},
    {0,0,0,0x80|16,0,1	},
    {0,0,0,0x80|20,0,1	},
    {0,0,0,0x80|24,0,1	},
    {0,0,0,0x80|30,0,1	},    
    {0,0,0,0x80|48,0,1	},
    {0,0,0,0x80|48,0,1	},
};

const static stFontAttribute g_gui_font_oem_data_B [] =
{
    {1,0,0,0x80|12,0,1	},
    {1,0,0,0x80|14,0,1	},
    {1,0,0,0x80|16,0,1	},
    {1,0,0,0x80|20,0,1	},
    {1,0,0,0x80|24,0,1	},
    {1,0,0,0x80|30,0,1	},
    {1,0,0,0x80|48,0,1	},
    {1,0,0,0x80|48,0,1	},
};

const static stFontAttribute g_gui_font_oem_data_I [] =
{
    {0,1,0,0x80|12,0,1	},
    {0,1,0,0x80|14,0,1	},
    {0,1,0,0x80|16,0,1	},
    {0,1,0,0x80|20,0,1	},
    {0,1,0,0x80|24,0,1	},
    {0,1,0,0x80|30,0,1	},
    {0,1,0,0x80|48,0,1	},
    {0,1,0,0x80|48,0,1	},
};

const static stFontAttribute g_gui_font_oem_data_BI [] =
{
    {1,1,0,0x80|12,0,1	},
    {1,1,0,0x80|14,0,1	},
    {1,1,0,0x80|16,0,1	},
    {1,1,0,0x80|20,0,1	},
    {1,1,0,0x80|24,0,1	},
    {1,1,0,0x80|30,0,1	},
    {1,1,0,0x80|48,0,1	},
    {0,1,0,0x80|48,0,1	},
};

const static U8 g_gui_font_oem_map[] = 
{
    0,0,0,0,0,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4,5,5,5,6,6,7,7,
};


#elif defined(__MMI_MAINLCD_240X400__)
const static U8 g_gui_font_type_data[GUI_FONT_SIZE_TOTAL] = 
{
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DEFAULT
    GUI_LARGE_FONT_SIZE,                                      //GUI_FONT_SIZE_BUTTON
    GUI_XXLARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_MULTITAP
    GUI_LARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_INPUTBOX
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_LIST
    GUI_SMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_MATRIX
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_MENUBAR_INDEX
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_MENUBAR_ITEM
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_SHORTCUT
    GUI_XLARGE_FONT_SIZE,                                      //GUI_FONT_SIZE_TITLE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DROPDOWN
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_LIST_MAINMENU
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_MATRIX_MAINMENU
    GUI_SMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_VIRTUAL_KEYBOARD
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DATE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_TIME
    GUI_SMALL_FONT_SIZE,                                        //GUI_FONT_SIZE_SUB_DATE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_SUB_TIME
    GUI_XLARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_TAB_TITLE
    GUI_SMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_INFOBOX
    GUI_SMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_HORIZONTAL_STRING
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_CELL
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_CALENDAR_HORIZONTAL
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_CALENDAR_CELL
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DCD_IDLE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_IME_TEXT
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_IME_LABEL
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_DURATION
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DAY

#if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)                   //GUI_FONT_SIZE_DATE_IDLESCREEN1
    GUI_XXLARGE_FONT_SIZE,
#else
    GUI_MEDIUM_FONT_SIZE,
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */

#if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)                    //GUI_FONT_SIZE_TIME_IDLESCREEN1
    GUI_XXLARGE_FONT_SIZE,
#else
    GUI_MEDIUM_FONT_SIZE,
#endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */

#ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__                          //GUI_FONT_SIZE_DT_STATUS_BAR_AT_BOTTOM
    GUI_SMALL_FONT_SIZE,
#endif
    GUI_XSMALL_FONT_SIZE,                                        //GUI_FONT_SIZE_TIME_NETWORK_SEARCH
    GUI_XSMALL_FONT_SIZE,                                        //GUI_FONT_SIZE_DURATION_ACTIVE_CALL
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_DURATION_CONF_CALL
#ifdef __MMI_SUBLCD_DATE_LARGE_FONT__
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_SUB_LARGE_DATE
#endif
#ifdef __MMI_SUBLCD_TIME_LARGE_FONT__
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_SUB_LARGE_TIME
    GUI_XXSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_SUB_LARGE_TIME_IDLESCREEN3
#endif /* __MMI_SUBLCD_TIME_LARGE_FONT__ */
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_SUB_DATE_IDLESCREEN4
    GUI_XXSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_SUB_TIME_IDLESCREEN4
#ifdef __MMI_UI_DALMATIAN_IDLESCREEN__                          //GUI_FONT_SIZE_TIME_DIGITAL_CLOCK_SC
    GUI_MEDIUM_FONT_SIZE,
#else
    GUI_LARGE_FONT_SIZE,
#endif /* GUI_FONT_SIZE_DIGITAL_CLOCK_SC */
#ifdef __MMI_UI_DALMATIAN_IDLESCREEN__                          //GUI_FONT_SIZE_DURATION_AUDIO_PLAY
    GUI_MEDIUM_FONT_SIZE,
#else
    GUI_LARGE_FONT_SIZE,
#endif /* GUI_FONT_SIZE_DIGITAL_CLOCK_SC */
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DOW_SELECT
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_NETWORK_NAME
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_NETWORK_STATUS
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_DATE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DIALER
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_INFOBOX
    GUI_XXXLARGE_FONT_SIZE,                                      //GUI_FONT_SIZE_DIALER_LARGE
    GUI_LARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_DIALER_SMALL
#ifndef __MMI_FTE_SUPPORT__
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_TITLE
#else
    GUI_SMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_TITLE
#endif
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_HORIZONTAL_SELECT
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_POPUP
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_IDLE_L_CUR_DAY
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_IDLE_L_CUR_DATE
    GUI_SMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_VERTICAL_SELECT
#ifndef __MMI_FTE_SUPPORT__
    GUI_XSMALL_FONT_SIZE,                                        //GUI_FONT_SIZE_CALENDAR_CURRENT
#else
    GUI_MEDIUM_FONT_SIZE,                                        //GUI_FONT_SIZE_CALENDAR_CURRENT
#endif
#ifndef __MMI_FTE_SUPPORT__
    GUI_SMALL_FONT_SIZE,                                        //GUI_FONT_SIZE_ICONBAR_HINT
#else
    GUI_MEDIUM_FONT_SIZE,                                      //GUI_FONT_SIZE_ICONBAR_HINT
#endif
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_VK_LARGE_ICON
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_STATUS_BAR_TIME
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_POPUP_EMBEDDED_SOFTKEY
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_LIST_HIGHLIGHT
    
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_STOPWATCH_DURATION,   
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_STOPWATCH_NWAY_TIME,  
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_STOPWATCH_NWAY_HILITE,

#ifndef __MMI_FTE_SUPPORT__
    GUI_MEDIUM_FONT_SIZE,                                      //GUI_FONT_SIZE_ICONBAR_ITEM_TEXT
#else
    GUI_MEDIUM_FONT_SIZE,                                      //GUI_FONT_SIZE_ICONBAR_ITEM_TEXT
#endif

#ifndef __MMI_VUI_HOMESCREEN__
    GUI_XSMALL_FONT_SIZE,                                      //GUI_FONT_SIZE_IDLE_CALENDAR_TITLE
#else
    GUI_XSMALL_FONT_SIZE,                                      //GUI_FONT_SIZE_IDLE_CALENDAR_TITLE
#endif
};
const static stFontAttribute g_gui_font_oem_data [] =
{
    {0,0,0,0x80|8,0,1	},
    {0,0,0,0x80|12,0,1	},
    {0,0,0,0x80|14,0,1	},
    {0,0,0,0x80|18,0,1	},
    {0,0,0,0x80|20,0,1	},
    {0,0,0,0x80|22,0,1	},
    {0,0,0,0x80|24,0,1	},    
    {0,0,0,0x80|30,0,1	},
};

const static stFontAttribute g_gui_font_oem_data_B [] =
{
    {1,0,0,0x80|8,0,1	},
    {1,0,0,0x80|12,0,1	},
    {1,0,0,0x80|14,0,1	},
    {1,0,0,0x80|18,0,1	},
    {1,0,0,0x80|20,0,1	},
    {1,0,0,0x80|22,0,1	},
    {1,0,0,0x80|24,0,1	},
    {1,0,0,0x80|30,0,1	},
};

const static stFontAttribute g_gui_font_oem_data_I [] =
{
    {0,1,0,0x80|8,0,1	},
    {0,1,0,0x80|12,0,1	},
    {0,1,0,0x80|14,0,1	},
    {0,1,0,0x80|18,0,1	},
    {0,1,0,0x80|20,0,1	},
    {0,1,0,0x80|22,0,1	},
    {0,1,0,0x80|24,0,1	},
    {0,1,0,0x80|30,0,1	},
};

const static stFontAttribute g_gui_font_oem_data_BI [] =
{
    {1,1,0,0x80|8,0,1	},
    {1,1,0,0x80|12,0,1	},
    {1,1,0,0x80|14,0,1	},
    {1,1,0,0x80|18,0,1	},
    {1,1,0,0x80|20,0,1	},
    {1,1,0,0x80|22,0,1	},
    {1,1,0,0x80|24,0,1	},
    {1,1,0,0x80|30,0,1	},
};

const static U8 g_gui_font_oem_map[] = 
{
    0,0,0,0,0,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4,5,5,5,6,6,7,7,
};

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)

const static U8 g_gui_font_type_data[GUI_FONT_SIZE_TOTAL] = 
{
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DEFAULT
    GUI_MEDIUM_FONT_SIZE,                                      //GUI_FONT_SIZE_BUTTON
    GUI_XXLARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_MULTITAP
    GUI_LARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_INPUTBOX
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_LIST
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_MATRIX
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_MENUBAR_INDEX
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_MENUBAR_ITEM
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_SHORTCUT
    GUI_MEDIUM_FONT_SIZE,                                      //GUI_FONT_SIZE_TITLE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DROPDOWN
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_LIST_MAINMENU
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_MATRIX_MAINMENU
    GUI_SMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_VIRTUAL_KEYBOARD
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DATE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_TIME
    GUI_SMALL_FONT_SIZE,                                        //GUI_FONT_SIZE_SUB_DATE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_SUB_TIME
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_TAB_TITLE
    GUI_SMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_INFOBOX
    GUI_SMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_HORIZONTAL
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_CELL
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_CALENDAR_HORIZONTAL
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_CALENDAR_CELL
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DCD_IDLE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_IME_TEXT
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_IME_LABEL
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_DURATION
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DAY

#if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)                   //GUI_FONT_SIZE_DATE_IDLESCREEN1
    GUI_XXLARGE_FONT_SIZE,
#else
    GUI_MEDIUM_FONT_SIZE,
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */

#if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)                    //GUI_FONT_SIZE_TIME_IDLESCREEN1
    GUI_LARGE_FONT_SIZE,
#else
    GUI_SMALL_FONT_SIZE,
#endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */

#ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__                          //GUI_FONT_SIZE_DT_STATUS_BAR_AT_BOTTOM
    GUI_SMALL_FONT_SIZE,
#endif
    GUI_XSMALL_FONT_SIZE,                                        //GUI_FONT_SIZE_TIME_NETWORK_SEARCH
    GUI_XSMALL_FONT_SIZE,                                        //GUI_FONT_SIZE_DURATION_ACTIVE_CALL
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_DURATION_CONF_CALL
#ifdef __MMI_SUBLCD_DATE_LARGE_FONT__
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_SUB_LARGE_DATE
#endif
#ifdef __MMI_SUBLCD_TIME_LARGE_FONT__
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_SUB_LARGE_TIME
    GUI_XXSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_SUB_LARGE_TIME_IDLESCREEN3
#endif /* __MMI_SUBLCD_TIME_LARGE_FONT__ */
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_SUB_DATE_IDLESCREEN4
    GUI_XXSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_SUB_TIME_IDLESCREEN4
#ifdef __MMI_UI_DALMATIAN_IDLESCREEN__                          //GUI_FONT_SIZE_TIME_DIGITAL_CLOCK_SC
    GUI_MEDIUM_FONT_SIZE,
#else
    GUI_LARGE_FONT_SIZE,
#endif /* GUI_FONT_SIZE_DIGITAL_CLOCK_SC */
#ifdef __MMI_UI_DALMATIAN_IDLESCREEN__                          //GUI_FONT_SIZE_DURATION_AUDIO_PLAY
    GUI_MEDIUM_FONT_SIZE,
#else
    GUI_LARGE_FONT_SIZE,
#endif /* GUI_FONT_SIZE_DIGITAL_CLOCK_SC */
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DOW_SELECT
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_NETWORK_NAME
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_NETWORK_STATUS
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_DATE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DIALER
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_INFOBOX
    GUI_XXXLARGE_FONT_SIZE,                                      //GUI_FONT_SIZE_DIALER_LARGE
    GUI_LARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_DIALER_SMALL
#ifndef __MMI_FTE_SUPPORT__
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_TITLE
#else
    GUI_SMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_TITLE
#endif
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_HORIZONTAL_SELECT
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_POPUP
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_IDLE_L_CUR_DAY
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_IDLE_L_CUR_DATE
    GUI_XSMALL_FONT_SIZE,                                        //GUI_FONT_SIZE_CALENDAR_VERTICAL_SELECT
#ifndef __MMI_FTE_SUPPORT__
    GUI_XSMALL_FONT_SIZE,                                        //GUI_FONT_SIZE_CALENDAR_CURRENT
#else
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_CURRENT
#endif
#ifndef __MMI_FTE_SUPPORT__
    GUI_XSMALL_FONT_SIZE,                                      //GUI_FONT_SIZE_ICONBAR_HINT
#else
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_ICONBAR_HINT
#endif
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_VK_LARGE_ICON
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_STATUS_BAR_TIME
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_POPUP_EMBEDDED_SOFTKEY
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_LIST_HIGHLIGHT

    
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_STOPWATCH_DURATION,   
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_STOPWATCH_NWAY_TIME,  
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_STOPWATCH_NWAY_HILITE,

#ifndef __MMI_FTE_SUPPORT__
    GUI_MEDIUM_FONT_SIZE,                                      //GUI_FONT_SIZE_ICONBAR_ITEM_TEXT
#else
    GUI_MEDIUM_FONT_SIZE,                                      //GUI_FONT_SIZE_ICONBAR_ITEM_TEXT
#endif

#ifndef __MMI_VUI_HOMESCREEN__
    GUI_XSMALL_FONT_SIZE,                                      //GUI_FONT_SIZE_IDLE_CALENDAR_TITLE
#else
    GUI_XSMALL_FONT_SIZE,                                      //GUI_FONT_SIZE_IDLE_CALENDAR_TITLE
#endif
};
const static stFontAttribute g_gui_font_oem_data [] =
{
    {0,0,0,0x80|8,0,1	},
    {0,0,0,0x80|12,0,1	},
    {0,0,0,0x80|14,0,1	},
    {0,0,0,0x80|18,0,1	},
    {0,0,0,0x80|20,0,1	},
    {0,0,0,0x80|22,0,1	},
    {0,0,0,0x80|24,0,1	},    
    {0,0,0,0x80|36,0,1	},
};

const static stFontAttribute g_gui_font_oem_data_B [] =
{
    {1,0,0,0x80|8,0,1	},
    {1,0,0,0x80|12,0,1	},
    {1,0,0,0x80|14,0,1	},
    {1,0,0,0x80|18,0,1	},
    {1,0,0,0x80|20,0,1	},
    {1,0,0,0x80|22,0,1	},
    {1,0,0,0x80|24,0,1	},
    {1,0,0,0x80|36,0,1	},
};

const static stFontAttribute g_gui_font_oem_data_I [] =
{
    {0,1,0,0x80|8,0,1	},
    {0,1,0,0x80|12,0,1	},
    {0,1,0,0x80|14,0,1	},
    {0,1,0,0x80|18,0,1	},
    {0,1,0,0x80|20,0,1	},
    {0,1,0,0x80|22,0,1	},
    {0,1,0,0x80|24,0,1	},
    {0,1,0,0x80|36,0,1	},
};

const static stFontAttribute g_gui_font_oem_data_BI [] =
{
    {1,1,0,0x80|8,0,1	},
    {1,1,0,0x80|12,0,1	},
    {1,1,0,0x80|14,0,1	},
    {1,1,0,0x80|18,0,1	},
    {1,1,0,0x80|20,0,1	},
    {1,1,0,0x80|22,0,1	},
    {1,1,0,0x80|36,0,1	},
};

const static U8 g_gui_font_oem_map[] = 
{
    0,0,0,0,0,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4,5,5,5,6,6,7,7,
};


#else
const static U8 g_gui_font_type_data[GUI_FONT_SIZE_TOTAL] = 
{
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DEFAULT
    GUI_MEDIUM_FONT_SIZE,                                      //GUI_FONT_SIZE_BUTTON
    GUI_XXLARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_MULTITAP
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_INPUTBOX
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_LIST
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_MATRIX
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_MENUBAR_INDEX
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_MENUBAR_ITEM
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_SHORTCUT
    GUI_MEDIUM_FONT_SIZE,                                      //GUI_FONT_SIZE_TITLE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DROPDOWN
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_LIST_MAINMENU
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_MATRIX_MAINMENU
    GUI_SMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_VIRTUAL_KEYBOARD
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DATE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_TIME
    GUI_SMALL_FONT_SIZE,                                        //GUI_FONT_SIZE_SUB_DATE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_SUB_TIME
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_TAB_TITLE
    GUI_SMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_INFOBOX
    GUI_SMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_HORIZONTAL
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_CELL
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_CALENDAR_HORIZONTAL
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_CALENDAR_CELL
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DCD_IDLE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_IME_TEXT
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_IME_LABEL
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_DURATION
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DAY

#if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)                   //GUI_FONT_SIZE_DATE_IDLESCREEN1
    GUI_XXLARGE_FONT_SIZE,
#else
    GUI_MEDIUM_FONT_SIZE,
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */

#if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)                    //GUI_FONT_SIZE_TIME_IDLESCREEN1
    GUI_XXLARGE_FONT_SIZE,
#else
    GUI_MEDIUM_FONT_SIZE,
#endif /* __MMI_UI_DALMATIAN_IDLESCREEN__ */

#ifdef __MMI_UI_STATUS_BAR_AT_BOTTOM__                          //GUI_FONT_SIZE_DT_STATUS_BAR_AT_BOTTOM
    GUI_SMALL_FONT_SIZE,
#endif
    GUI_XSMALL_FONT_SIZE,                                        //GUI_FONT_SIZE_TIME_NETWORK_SEARCH
    GUI_XSMALL_FONT_SIZE,                                        //GUI_FONT_SIZE_DURATION_ACTIVE_CALL
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_DURATION_CONF_CALL
#ifdef __MMI_SUBLCD_DATE_LARGE_FONT__
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_SUB_LARGE_DATE
#endif
#ifdef __MMI_SUBLCD_TIME_LARGE_FONT__
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_SUB_LARGE_TIME
    GUI_XXSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_SUB_LARGE_TIME_IDLESCREEN3
#endif /* __MMI_SUBLCD_TIME_LARGE_FONT__ */
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_SUB_DATE_IDLESCREEN4
    GUI_XXSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_SUB_TIME_IDLESCREEN4
#ifdef __MMI_UI_DALMATIAN_IDLESCREEN__                          //GUI_FONT_SIZE_TIME_DIGITAL_CLOCK_SC
    GUI_MEDIUM_FONT_SIZE,
#else
    GUI_LARGE_FONT_SIZE,
#endif /* GUI_FONT_SIZE_DIGITAL_CLOCK_SC */
#ifdef __MMI_UI_DALMATIAN_IDLESCREEN__                          //GUI_FONT_SIZE_DURATION_AUDIO_PLAY
    GUI_MEDIUM_FONT_SIZE,
#else
    GUI_LARGE_FONT_SIZE,
#endif /* GUI_FONT_SIZE_DIGITAL_CLOCK_SC */
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DOW_SELECT
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_NETWORK_NAME
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_NETWORK_STATUS
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_IDLE_DATE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_DIALER
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_INFOBOX
    GUI_XXXLARGE_FONT_SIZE,                                      //GUI_FONT_SIZE_DIALER_LARGE
    GUI_LARGE_FONT_SIZE,                                       //GUI_FONT_SIZE_DIALER_SMALL
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_TITLE
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_HORIZONTAL_SELECT
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_POPUP
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_IDLE_L_CUR_DAY
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_IDLE_L_CUR_DATE
    GUI_XSMALL_FONT_SIZE,                                        //GUI_FONT_SIZE_CALENDAR_VERTICAL_SELECT
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_CALENDAR_CURRENT
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_ICONBAR_HINT
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_VK_LARGE_ICON
    GUI_XSMALL_FONT_SIZE,                                       //GUI_FONT_SIZE_STATUS_BAR_TIME
    GUI_MEDIUM_FONT_SIZE,                                       //GUI_FONT_SIZE_POPUP_EMBEDDED_SOFTKEY
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_LIST_HIGHLIGHT

    
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_STOPWATCH_DURATION,   
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_STOPWATCH_NWAY_TIME,  
    GUI_LARGE_FONT_SIZE,                                        //GUI_FONT_SIZE_STOPWATCH_NWAY_HILITE,

    GUI_MEDIUM_FONT_SIZE,                                      //GUI_FONT_SIZE_ICONBAR_ITEM_TEXT

#ifndef __MMI_VUI_HOMESCREEN__
    GUI_XSMALL_FONT_SIZE,                                      //GUI_FONT_SIZE_IDLE_CALENDAR_TITLE
#else
    GUI_XSMALL_FONT_SIZE,                                      //GUI_FONT_SIZE_IDLE_CALENDAR_TITLE
#endif
};
const static stFontAttribute g_gui_font_oem_data [] =
{
    {0,0,0,0x80|8,0,1	},
    {0,0,0,0x80|12,0,1	},
    {0,0,0,0x80|14,0,1	},
    {0,0,0,0x80|18,0,1	},
    {0,0,0,0x80|20,0,1	},
    {0,0,0,0x80|22,0,1	},
    {0,0,0,0x80|24,0,1	},    
    {0,0,0,0x80|36,0,1	},
};

const static stFontAttribute g_gui_font_oem_data_B [] =
{
    {1,0,0,0x80|8,0,1	},
    {1,0,0,0x80|12,0,1	},
    {1,0,0,0x80|14,0,1	},
    {1,0,0,0x80|18,0,1	},
    {1,0,0,0x80|20,0,1	},
    {1,0,0,0x80|22,0,1	},
    {1,0,0,0x80|24,0,1	},
    {1,0,0,0x80|36,0,1	},
};

const static stFontAttribute g_gui_font_oem_data_I [] =
{
    {0,1,0,0x80|8,0,1	},
    {0,1,0,0x80|12,0,1	},
    {0,1,0,0x80|14,0,1	},
    {0,1,0,0x80|18,0,1	},
    {0,1,0,0x80|20,0,1	},
    {0,1,0,0x80|22,0,1	},
    {0,1,0,0x80|24,0,1	},
    {0,1,0,0x80|36,0,1	},
};

const static stFontAttribute g_gui_font_oem_data_BI [] =
{
    {1,1,0,0x80|8,0,1	},
    {1,1,0,0x80|12,0,1	},
    {1,1,0,0x80|14,0,1	},
    {1,1,0,0x80|18,0,1	},
    {1,1,0,0x80|20,0,1	},
    {1,1,0,0x80|22,0,1	},
    {1,1,0,0x80|36,0,1	},
};

const static U8 g_gui_font_oem_map[] = 
{
    0,0,0,0,0,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4,5,5,5,6,6,7,7,
};


#endif

/*****************************************************************************
 * FUNCTION
 *  gui_font_oem_get_type
 * DESCRIPTION
 *  Get the font type
 * PARAMETERS
 *  index       [IN]        index
 * RETURNS
 *  UI_font_type 
 *****************************************************************************/
/*const*/ UI_font_type gui_font_oem_get_type(gui_font_size_enum index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 font_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >=GUI_FONT_SIZE_TOTAL)
        return NULL;
    font_data = g_gui_font_type_data[index] & 0x1F;
    font_data = g_gui_font_oem_map[font_data];
    if ((g_gui_font_type_data[index] & GUI_FONT_TYPE_BOLD) && (g_gui_font_type_data[index] & GUI_FONT_TYPE_ITALIC))
    {
        return (/*const*/ UI_font_type) &g_gui_font_oem_data_BI[font_data];
    }
    else if (g_gui_font_type_data[index] & GUI_FONT_TYPE_BOLD)
    {            
        return (/*const*/ UI_font_type) &g_gui_font_oem_data_B[font_data];
    }
    else if (g_gui_font_type_data[index] & GUI_FONT_TYPE_ITALIC)
    {
        
        return (/*const*/ UI_font_type) &g_gui_font_oem_data_I[font_data];
    }
    else
    {        
        return (/*const*/ UI_font_type) &g_gui_font_oem_data[font_data];
    }
}
#endif /* __MMI_VECTOR_FONT_SUPPORT__*/

