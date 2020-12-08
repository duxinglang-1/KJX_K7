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
 *  Vapp_notes_list.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Header file for class declaration for Notes application
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/


#ifndef __VAPP_NOTES_LIST_H__
#define __VAPP_NOTES_LIST_H__
#ifdef __MMI_NOTE_APP__ 

#include "vfx_mc_include.h"
#include "vcp_include.h"
//#include "Vfx_control.h"
#include "vcp_page_panel.h"
#include "vcp_menu_popup.h"
#include "mmi_rp_vapp_notes_def.h"
extern "C"
{
	//#include "Mmi_rp_fw_test1_def.h"
	#include "vapp_notes_struct.h"
}

#if defined(__MMI_MAINLCD_320X480__)
/*for custom list*/
#define NOTES_APP_LIST_ITEM_CUST_FRAME_HEIGHT  50
#define NOTES_APP_LIST_ITEM_CUST_FRAME_WIDTH_MARK  280
#define NOTES_APP_LIST_ITEM_CUST_FRAME_WIDTH_NORMAL  312
#define NOTES_APP_LIST_ITEM_BG_FRAME_WIDTH_MARK  280
#define NOTES_APP_LIST_ITEM_BG_FRAME_WIDTH_NORMAL  312
#define NOTES_APP_LIST_ITEM_BG_FRAME_POS_X_MARK  5
#define NOTES_APP_LIST_ITEM_BG_FRAME_POS_X_NORMAL  0
#define NOTES_APP_LIST_ITEM_IMG_FRAME_WIDTH_MARK  268
#define NOTES_APP_LIST_ITEM_IMG_FRAME_WIDTH_NORMAL  312
#define NOTES_APP_LIST_ITEM_TEXT_FRAME_X  20
#define NOTES_APP_LIST_ITEM_TEXT_FRAME_Y  8
#define NOTES_APP_LIST_ITEM_TEXT_FRAME_WIDTH_MARK  230
#define NOTES_APP_LIST_ITEM_TEXT_FRAME_WIDTH_NORMAL  275
#define NOTES_APP_LIST_ITEM_MAIN_TEXT_FONT  16

#define NOTES_APP_LIST_ITEM_TIME_TEXT_POS_X  20
#define NOTES_APP_LIST_ITEM_TIME_TEXT_POS_Y  32
#define NOTES_APP_LIST_ITEM_SUB_TEXT_FONT  12
#define NOTES_APP_LIST_ITEM_EMPTY_TEXT_FONT  20

#define TOP_BAR_HEIGHT			7
#define NOTES_APP_LIST_START_GAP_X			5
#define NOTES_APP_LIST_END_GAP_X			3
#define NOTES_APP_LIST_ITEM_HEIGHT			57
#define NOTES_APP_VIEW_PAGE_TOP_BAR_HEIGHT  38
#define NOTES_APP_VIEW_PAGE_TOP_BAR_HEIGHT_TEMP  38
#define NOTES_APP_VIEW_PAGE_PREV_BUTTON_X    7
#define NOTES_APP_VIEW_PAGE_PREV_BUTTON_Y    4
#define NOTES_APP_VIEW_PAGE_PREV_BUTTON_WIDTH    30
#define NOTES_APP_VIEW_PAGE_PREV_BUTTON_HEIGHT   30
#define NOTES_APP_VIEW_PAGE_NEXT_BUTTON_WIDTH    25
#define NOTES_APP_VIEW_PAGE_NEXT_BUTTON_HEIGHT   25
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_START_GAP 2
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_END_GAP 2
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_DATE_X  10
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_DATE_Y  9
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_TIME_X  260
	/*LCD_WIDTH-NOTES_APP_VIEW_PAGE_VIEW_FRAME_START_GAP-NOTES_APP_VIEW_PAGE_VIEW_FRAME_END_GAP-NOTES_APP_VIEW_PAGE_VIEW_FRAME_DATE_X */
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_TIME_Y  9
#define NOTES_APP_VIEW_PAGE_VIEW_BG_FRAME_HEIGHT  28
#define NOTES_APP_VIEW_PAGE_VIEW_VIEW_FRAME_HEIGHT 345
#define NOTES_APP_VIEW_PAGE_VIEW_HINT_TITLE_FONT 20
#define NOTES_APP_VIEW_PAGE_VIEW_OFFSET 0

/*for big button*/

#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_X  97
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_Y  41
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_WIDTH   126
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_HEIGHT  154
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_SHADOW  20

#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_COUNT_TEXT_X  35
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_COUNT_TEXT_Y  30
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_COUNT_TEXT_FONT   48

#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_TAIL_X  40
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_TAIL_Y  30
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_TAIL_FONT   14

/*for white button*/
#define NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_X  8
#define NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_Y  196
#define NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_WIDTH   97
#define NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_HEIGHT  115

/*for blue button*/
#define NOTES_APP_CATEGORY_PAGE_BLUE_BUTTON_X  113
#define NOTES_APP_CATEGORY_PAGE_BLUE_BUTTON_Y  196
#define NOTES_APP_CATEGORY_PAGE_BLUE_BUTTON_WIDTH   96
#define NOTES_APP_CATEGORY_PAGE_BLUE_BUTTON_HEIGHT  115

/*for GREEN button*/
#define NOTES_APP_CATEGORY_PAGE_GREEN_BUTTON_X  218
#define NOTES_APP_CATEGORY_PAGE_GREEN_BUTTON_Y  196
#define NOTES_APP_CATEGORY_PAGE_GREEN_BUTTON_WIDTH   97
#define NOTES_APP_CATEGORY_PAGE_GREEN_BUTTON_HEIGHT  115

/*for yellow button*/
#define NOTES_APP_CATEGORY_PAGE_YELLOW_BUTTON_X  8
#define NOTES_APP_CATEGORY_PAGE_YELLOW_BUTTON_Y  317
#define NOTES_APP_CATEGORY_PAGE_YELLOW_BUTTON_WIDTH   97
#define NOTES_APP_CATEGORY_PAGE_YELLOW_BUTTON_HEIGHT  115


/*for oRANGE button*/
#define NOTES_APP_CATEGORY_PAGE_ORANGE_BUTTON_X  113
#define NOTES_APP_CATEGORY_PAGE_ORANGE_BUTTON_Y  317
#define NOTES_APP_CATEGORY_PAGE_ORANGE_BUTTON_WIDTH   96
#define NOTES_APP_CATEGORY_PAGE_ORANGE_BUTTON_HEIGHT  115

/*for red button*/
#define NOTES_APP_CATEGORY_PAGE_RED_BUTTON_X  218
#define NOTES_APP_CATEGORY_PAGE_RED_BUTTON_Y  317
#define NOTES_APP_CATEGORY_PAGE_RED_BUTTON_WIDTH   97
#define NOTES_APP_CATEGORY_PAGE_RED_BUTTON_HEIGHT  115
    /*general for all small one button*/

/*common*/

#define NOTES_APP_CATEGORY_PAGE_BUTTON_TAIL_X    30
#define NOTES_APP_CATEGORY_PAGE_BUTTON_TAIL_Y    20
#define NOTES_APP_CATEGORY_PAGE_BUTTON_TAIL_FONT    14
#define NOTES_APP_CATEGORY_PAGE_BUTTON_COUNT_TEXT_FONT   40
#define NOTES_APP_CATEGORY_PAGE_BUTTON_COUNT_TEXT_X  22
#define NOTES_APP_CATEGORY_PAGE_BUTTON_COUNT_TEXT_Y  25
#define NOTES_APP_CATEGORY_BIG_BUTTON_TEXT_TAIL_GAP 6
#define NOTES_APP_CATEGORY_SMALL_BUTTON_SHADOW      13
#define NOTES_APP_CATEGORY_TEXT_TAIL_GAP_ALIGNMENT  3
#define NOTES_APP_CATEGORY_TEXT_TAIL_GAP_ALIGNMENT_BIG         3
#endif



/*For 480*800 size*/
#if defined(__MMI_MAINLCD_480X800__)

#define NOTES_APP_LIST_ITEM_CUST_FRAME_HEIGHT  75
#define NOTES_APP_LIST_ITEM_CUST_FRAME_WIDTH_MARK  390
#define NOTES_APP_LIST_ITEM_CUST_FRAME_WIDTH_NORMAL  454
#define NOTES_APP_LIST_ITEM_BG_FRAME_WIDTH_MARK  375
#define NOTES_APP_LIST_ITEM_BG_FRAME_WIDTH_NORMAL  454
#define NOTES_APP_LIST_ITEM_BG_FRAME_POS_X_MARK  8
#define NOTES_APP_LIST_ITEM_BG_FRAME_POS_X_NORMAL  0
#define NOTES_APP_LIST_ITEM_IMG_FRAME_WIDTH_MARK  380
#define NOTES_APP_LIST_ITEM_IMG_FRAME_WIDTH_NORMAL  454
#define NOTES_APP_LIST_ITEM_TEXT_FRAME_X  30
#define NOTES_APP_LIST_ITEM_TEXT_FRAME_Y  14
#define NOTES_APP_LIST_ITEM_TEXT_FRAME_WIDTH_MARK  345
#define NOTES_APP_LIST_ITEM_TEXT_FRAME_WIDTH_NORMAL  413
#define NOTES_APP_LIST_ITEM_MAIN_TEXT_FONT  26

#define NOTES_APP_LIST_ITEM_TIME_TEXT_POS_X  30
#define NOTES_APP_LIST_ITEM_TIME_TEXT_POS_Y  53
#define NOTES_APP_LIST_ITEM_SUB_TEXT_FONT  18
#define NOTES_APP_LIST_ITEM_EMPTY_TEXT_FONT  30

#define TOP_BAR_HEIGHT			10
#define NOTES_APP_LIST_START_GAP_X			15
#define NOTES_APP_LIST_END_GAP_X			11
#define NOTES_APP_LIST_ITEM_HEIGHT			83

#define NOTES_APP_VIEW_PAGE_TOP_BAR_HEIGHT  70
#define NOTES_APP_VIEW_PAGE_TOP_BAR_HEIGHT_TEMP  75
#define NOTES_APP_VIEW_PAGE_PREV_BUTTON_X   10
#define NOTES_APP_VIEW_PAGE_PREV_BUTTON_Y    12
#define NOTES_APP_VIEW_PAGE_PREV_BUTTON_WIDTH    51
#define NOTES_APP_VIEW_PAGE_PREV_BUTTON_HEIGHT   51
#define NOTES_APP_VIEW_PAGE_NEXT_BUTTON_WIDTH    51
#define NOTES_APP_VIEW_PAGE_NEXT_BUTTON_HEIGHT   51
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_DATE_X  8
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_DATE_Y  12
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_TIME_X  380
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_TIME_Y  12
#define NOTES_APP_VIEW_PAGE_VIEW_BG_FRAME_HEIGHT 42
#define NOTES_APP_VIEW_PAGE_VIEW_VIEW_FRAME_HEIGHT 565
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_START_GAP 4
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_END_GAP 4
#define NOTES_APP_VIEW_PAGE_VIEW_HINT_TITLE_FONT 35
#define NOTES_APP_VIEW_PAGE_VIEW_OFFSET 0
/****************************************************************************************/



#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_X  141
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_Y  77
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_WIDTH   199
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_HEIGHT  244
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_SHADOW  38

#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_COUNT_TEXT_X  50
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_COUNT_TEXT_Y  52
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_COUNT_TEXT_FONT   76

#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_TAIL_X  60
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_TAIL_Y  45
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_TAIL_FONT   24

/*for white button*/
#define NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_X  20
#define NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_Y  351
#define NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_WIDTH   137
#define NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_HEIGHT  162

/*for blue button*/
#define NOTES_APP_CATEGORY_PAGE_BLUE_BUTTON_X  172
#define NOTES_APP_CATEGORY_PAGE_BLUE_BUTTON_Y  351
#define NOTES_APP_CATEGORY_PAGE_BLUE_BUTTON_WIDTH   136
#define NOTES_APP_CATEGORY_PAGE_BLUE_BUTTON_HEIGHT  163

/*for GREEN button*/
#define NOTES_APP_CATEGORY_PAGE_GREEN_BUTTON_X  323
#define NOTES_APP_CATEGORY_PAGE_GREEN_BUTTON_Y  351
#define NOTES_APP_CATEGORY_PAGE_GREEN_BUTTON_WIDTH   137
#define NOTES_APP_CATEGORY_PAGE_GREEN_BUTTON_HEIGHT  163

/*for yellow button*/
#define NOTES_APP_CATEGORY_PAGE_YELLOW_BUTTON_X  20
#define NOTES_APP_CATEGORY_PAGE_YELLOW_BUTTON_Y  546
#define NOTES_APP_CATEGORY_PAGE_YELLOW_BUTTON_WIDTH   137
#define NOTES_APP_CATEGORY_PAGE_YELLOW_BUTTON_HEIGHT  163


/*for oRANGE button*/
#define NOTES_APP_CATEGORY_PAGE_ORANGE_BUTTON_X  172
#define NOTES_APP_CATEGORY_PAGE_ORANGE_BUTTON_Y  546
#define NOTES_APP_CATEGORY_PAGE_ORANGE_BUTTON_WIDTH   136
#define NOTES_APP_CATEGORY_PAGE_ORANGE_BUTTON_HEIGHT  163

/*for red button*/
#define NOTES_APP_CATEGORY_PAGE_RED_BUTTON_X  323
#define NOTES_APP_CATEGORY_PAGE_RED_BUTTON_Y  546
#define NOTES_APP_CATEGORY_PAGE_RED_BUTTON_WIDTH   137
#define NOTES_APP_CATEGORY_PAGE_RED_BUTTON_HEIGHT  163
    /*general for all small one button*/

/*common*/

#define NOTES_APP_CATEGORY_PAGE_BUTTON_TAIL_X    45
#define NOTES_APP_CATEGORY_PAGE_BUTTON_TAIL_Y    25
#define NOTES_APP_CATEGORY_PAGE_BUTTON_TAIL_FONT    20
#define NOTES_APP_CATEGORY_PAGE_BUTTON_COUNT_TEXT_FONT   56
#define NOTES_APP_CATEGORY_PAGE_BUTTON_COUNT_TEXT_X  33
#define NOTES_APP_CATEGORY_PAGE_BUTTON_COUNT_TEXT_Y  28
#define NOTES_APP_CATEGORY_BIG_BUTTON_TEXT_TAIL_GAP 10
#define NOTES_APP_CATEGORY_SMALL_BUTTON_SHADOW      27
#define NOTES_APP_CATEGORY_TEXT_TAIL_GAP_ALIGNMENT  3
#define NOTES_APP_CATEGORY_TEXT_TAIL_GAP_ALIGNMENT_BIG         5
#endif

#if defined(__MMI_MAINLCD_240X400__)
/*for custom list*/
#define NOTES_APP_LIST_ITEM_CUST_FRAME_HEIGHT  42+2
#define NOTES_APP_LIST_ITEM_CUST_FRAME_WIDTH_MARK  210
#define NOTES_APP_LIST_ITEM_CUST_FRAME_WIDTH_NORMAL  234
#define NOTES_APP_LIST_ITEM_BG_FRAME_WIDTH_MARK  210
#define NOTES_APP_LIST_ITEM_BG_FRAME_WIDTH_NORMAL  234
#define NOTES_APP_LIST_ITEM_BG_FRAME_POS_X_MARK  4
#define NOTES_APP_LIST_ITEM_BG_FRAME_POS_X_NORMAL  0
#define NOTES_APP_LIST_ITEM_IMG_FRAME_WIDTH_MARK  201
#define NOTES_APP_LIST_ITEM_IMG_FRAME_WIDTH_NORMAL  234
#define NOTES_APP_LIST_ITEM_TEXT_FRAME_X  15
#define NOTES_APP_LIST_ITEM_TEXT_FRAME_Y  7
#define NOTES_APP_LIST_ITEM_TEXT_FRAME_WIDTH_MARK  173
#define NOTES_APP_LIST_ITEM_TEXT_FRAME_WIDTH_NORMAL  206
#define NOTES_APP_LIST_ITEM_MAIN_TEXT_FONT  16

#define NOTES_APP_LIST_ITEM_TIME_TEXT_POS_X  15
#define NOTES_APP_LIST_ITEM_TIME_TEXT_POS_Y  24 + 2
#define NOTES_APP_LIST_ITEM_SUB_TEXT_FONT  12
#define NOTES_APP_LIST_ITEM_EMPTY_TEXT_FONT  16

#define TOP_BAR_HEIGHT			6
#define NOTES_APP_LIST_START_GAP_X			5
#define NOTES_APP_LIST_END_GAP_X			3
#define NOTES_APP_LIST_ITEM_HEIGHT			47
#define NOTES_APP_VIEW_PAGE_TOP_BAR_HEIGHT  30
#define NOTES_APP_VIEW_PAGE_TOP_BAR_HEIGHT_TEMP  30
#define NOTES_APP_VIEW_PAGE_PREV_BUTTON_X    5
#define NOTES_APP_VIEW_PAGE_PREV_BUTTON_Y    2
#define NOTES_APP_VIEW_PAGE_PREV_BUTTON_WIDTH    26
#define NOTES_APP_VIEW_PAGE_PREV_BUTTON_HEIGHT   26
#define NOTES_APP_VIEW_PAGE_NEXT_BUTTON_WIDTH    26
#define NOTES_APP_VIEW_PAGE_NEXT_BUTTON_HEIGHT   26
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_START_GAP 2
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_END_GAP 2
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_DATE_X  4
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_DATE_Y  7
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_TIME_X  185
	/*LCD_WIDTH-NOTES_APP_VIEW_PAGE_VIEW_FRAME_START_GAP-NOTES_APP_VIEW_PAGE_VIEW_FRAME_END_GAP-NOTES_APP_VIEW_PAGE_VIEW_FRAME_DATE_X */
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_TIME_Y  7
#define NOTES_APP_VIEW_PAGE_VIEW_BG_FRAME_HEIGHT  25
#define NOTES_APP_VIEW_PAGE_VIEW_VIEW_FRAME_HEIGHT 280
#define NOTES_APP_VIEW_PAGE_VIEW_HINT_TITLE_FONT 16
#define NOTES_APP_VIEW_PAGE_VIEW_OFFSET 0
/*for big button*/

#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_X  71
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_Y  35
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_WIDTH   99
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_HEIGHT  123
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_SHADOW  20

#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_COUNT_TEXT_X  19
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_COUNT_TEXT_Y  20
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_COUNT_TEXT_FONT   38

#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_TAIL_X  22
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_TAIL_Y  17
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_TAIL_FONT   12

/*for white button*/
#define NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_X  10
#define NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_Y  172
#define NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_WIDTH   69
#define NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_HEIGHT  80

/*for blue button*/
#define NOTES_APP_CATEGORY_PAGE_BLUE_BUTTON_X  86
#define NOTES_APP_CATEGORY_PAGE_BLUE_BUTTON_Y  172
#define NOTES_APP_CATEGORY_PAGE_BLUE_BUTTON_WIDTH   68
#define NOTES_APP_CATEGORY_PAGE_BLUE_BUTTON_HEIGHT  80

/*for GREEN button*/
#define NOTES_APP_CATEGORY_PAGE_GREEN_BUTTON_X  161
#define NOTES_APP_CATEGORY_PAGE_GREEN_BUTTON_Y  172
#define NOTES_APP_CATEGORY_PAGE_GREEN_BUTTON_WIDTH   69
#define NOTES_APP_CATEGORY_PAGE_GREEN_BUTTON_HEIGHT  80

/*for yellow button*/
#define NOTES_APP_CATEGORY_PAGE_YELLOW_BUTTON_X  10
#define NOTES_APP_CATEGORY_PAGE_YELLOW_BUTTON_Y  270
#define NOTES_APP_CATEGORY_PAGE_YELLOW_BUTTON_WIDTH   69
#define NOTES_APP_CATEGORY_PAGE_YELLOW_BUTTON_HEIGHT  81


/*for oRANGE button*/
#define NOTES_APP_CATEGORY_PAGE_ORANGE_BUTTON_X  86
#define NOTES_APP_CATEGORY_PAGE_ORANGE_BUTTON_Y  270
#define NOTES_APP_CATEGORY_PAGE_ORANGE_BUTTON_WIDTH   68
#define NOTES_APP_CATEGORY_PAGE_ORANGE_BUTTON_HEIGHT  81

/*for red button*/
#define NOTES_APP_CATEGORY_PAGE_RED_BUTTON_X  161
#define NOTES_APP_CATEGORY_PAGE_RED_BUTTON_Y  270
#define NOTES_APP_CATEGORY_PAGE_RED_BUTTON_WIDTH   69
#define NOTES_APP_CATEGORY_PAGE_RED_BUTTON_HEIGHT  81
    /*general for all small one button*/

/*common*/

#define NOTES_APP_CATEGORY_PAGE_BUTTON_TAIL_X    22
#define NOTES_APP_CATEGORY_PAGE_BUTTON_TAIL_Y    12
#define NOTES_APP_CATEGORY_PAGE_BUTTON_TAIL_FONT    10
#define NOTES_APP_CATEGORY_PAGE_BUTTON_COUNT_TEXT_FONT   28
#define NOTES_APP_CATEGORY_PAGE_BUTTON_COUNT_TEXT_X  16
#define NOTES_APP_CATEGORY_PAGE_BUTTON_COUNT_TEXT_Y  14
#define NOTES_APP_CATEGORY_BIG_BUTTON_TEXT_TAIL_GAP 6
#define NOTES_APP_CATEGORY_SMALL_BUTTON_SHADOW      13
#define NOTES_APP_CATEGORY_TEXT_TAIL_GAP_ALIGNMENT  3
#define NOTES_APP_CATEGORY_TEXT_TAIL_GAP_ALIGNMENT_BIG         3
#endif

#if defined(__MMI_MAINLCD_240X320__)
/*for custom list*/
#define NOTES_APP_LIST_ITEM_CUST_FRAME_HEIGHT  34
#define NOTES_APP_LIST_ITEM_CUST_FRAME_WIDTH_MARK  210
#define NOTES_APP_LIST_ITEM_CUST_FRAME_WIDTH_NORMAL  234
#define NOTES_APP_LIST_ITEM_BG_FRAME_WIDTH_MARK  210
#define NOTES_APP_LIST_ITEM_BG_FRAME_WIDTH_NORMAL  234
#define NOTES_APP_LIST_ITEM_BG_FRAME_POS_X_MARK  4
#define NOTES_APP_LIST_ITEM_BG_FRAME_POS_X_NORMAL  0
#define NOTES_APP_LIST_ITEM_IMG_FRAME_WIDTH_MARK  201
#define NOTES_APP_LIST_ITEM_IMG_FRAME_WIDTH_NORMAL  234
#define NOTES_APP_LIST_ITEM_TEXT_FRAME_X  15
#define NOTES_APP_LIST_ITEM_TEXT_FRAME_Y  6
#define NOTES_APP_LIST_ITEM_TEXT_FRAME_WIDTH_MARK  173
#define NOTES_APP_LIST_ITEM_TEXT_FRAME_WIDTH_NORMAL  206
#define NOTES_APP_LIST_ITEM_MAIN_TEXT_FONT  13

#define NOTES_APP_LIST_ITEM_TIME_TEXT_POS_X  15
#define NOTES_APP_LIST_ITEM_TIME_TEXT_POS_Y  20
#define NOTES_APP_LIST_ITEM_SUB_TEXT_FONT  9
#define NOTES_APP_LIST_ITEM_EMPTY_TEXT_FONT  16

#define TOP_BAR_HEIGHT			6
#define NOTES_APP_LIST_START_GAP_X			5
#define NOTES_APP_LIST_END_GAP_X			3
#define NOTES_APP_LIST_ITEM_HEIGHT			38
#define NOTES_APP_VIEW_PAGE_TOP_BAR_HEIGHT  30
#define NOTES_APP_VIEW_PAGE_TOP_BAR_HEIGHT_TEMP  30
#define NOTES_APP_VIEW_PAGE_PREV_BUTTON_X    5
#define NOTES_APP_VIEW_PAGE_PREV_BUTTON_Y    2
#define NOTES_APP_VIEW_PAGE_PREV_BUTTON_WIDTH    26
#define NOTES_APP_VIEW_PAGE_PREV_BUTTON_HEIGHT   26
#define NOTES_APP_VIEW_PAGE_NEXT_BUTTON_WIDTH    26
#define NOTES_APP_VIEW_PAGE_NEXT_BUTTON_HEIGHT   26
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_START_GAP 2
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_END_GAP 2
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_DATE_X  4
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_DATE_Y  7
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_TIME_X  190
	/*LCD_WIDTH-NOTES_APP_VIEW_PAGE_VIEW_FRAME_START_GAP-NOTES_APP_VIEW_PAGE_VIEW_FRAME_END_GAP-NOTES_APP_VIEW_PAGE_VIEW_FRAME_DATE_X */
#define NOTES_APP_VIEW_PAGE_VIEW_FRAME_TIME_Y  7
#define NOTES_APP_VIEW_PAGE_VIEW_BG_FRAME_HEIGHT  25
#define NOTES_APP_VIEW_PAGE_VIEW_VIEW_FRAME_HEIGHT 200
#define NOTES_APP_VIEW_PAGE_VIEW_HINT_TITLE_FONT 16
#define NOTES_APP_VIEW_PAGE_VIEW_OFFSET 0
/*for big button*/

#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_X  72
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_Y  8
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_WIDTH   99
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_HEIGHT  123
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_SHADOW  20

#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_COUNT_TEXT_X  19
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_COUNT_TEXT_Y  20
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_COUNT_TEXT_FONT   38

#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_TAIL_X  22
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_TAIL_Y  17
#define NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_TAIL_FONT   12

/*for white button*/
#define NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_X  11
#define NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_Y  133
#define NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_WIDTH   69
#define NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_HEIGHT  80

/*for blue button*/
#define NOTES_APP_CATEGORY_PAGE_BLUE_BUTTON_X  87
#define NOTES_APP_CATEGORY_PAGE_BLUE_BUTTON_Y  133
#define NOTES_APP_CATEGORY_PAGE_BLUE_BUTTON_WIDTH   68
#define NOTES_APP_CATEGORY_PAGE_BLUE_BUTTON_HEIGHT  80

/*for GREEN button*/
#define NOTES_APP_CATEGORY_PAGE_GREEN_BUTTON_X  162
#define NOTES_APP_CATEGORY_PAGE_GREEN_BUTTON_Y  133
#define NOTES_APP_CATEGORY_PAGE_GREEN_BUTTON_WIDTH   69
#define NOTES_APP_CATEGORY_PAGE_GREEN_BUTTON_HEIGHT  80

/*for yellow button*/
#define NOTES_APP_CATEGORY_PAGE_YELLOW_BUTTON_X  11
#define NOTES_APP_CATEGORY_PAGE_YELLOW_BUTTON_Y  217
#define NOTES_APP_CATEGORY_PAGE_YELLOW_BUTTON_WIDTH   69
#define NOTES_APP_CATEGORY_PAGE_YELLOW_BUTTON_HEIGHT  81


/*for oRANGE button*/
#define NOTES_APP_CATEGORY_PAGE_ORANGE_BUTTON_X  87
#define NOTES_APP_CATEGORY_PAGE_ORANGE_BUTTON_Y  217
#define NOTES_APP_CATEGORY_PAGE_ORANGE_BUTTON_WIDTH   68
#define NOTES_APP_CATEGORY_PAGE_ORANGE_BUTTON_HEIGHT  81

/*for red button*/
#define NOTES_APP_CATEGORY_PAGE_RED_BUTTON_X  162
#define NOTES_APP_CATEGORY_PAGE_RED_BUTTON_Y  217
#define NOTES_APP_CATEGORY_PAGE_RED_BUTTON_WIDTH   69
#define NOTES_APP_CATEGORY_PAGE_RED_BUTTON_HEIGHT  81
    /*general for all small one button*/

/*common*/

#define NOTES_APP_CATEGORY_PAGE_BUTTON_TAIL_X    22
#define NOTES_APP_CATEGORY_PAGE_BUTTON_TAIL_Y    12
#define NOTES_APP_CATEGORY_PAGE_BUTTON_TAIL_FONT    10
#define NOTES_APP_CATEGORY_PAGE_BUTTON_COUNT_TEXT_FONT   28
#define NOTES_APP_CATEGORY_PAGE_BUTTON_COUNT_TEXT_X  16
#define NOTES_APP_CATEGORY_PAGE_BUTTON_COUNT_TEXT_Y  12
#define NOTES_APP_CATEGORY_BIG_BUTTON_TEXT_TAIL_GAP 6
#define NOTES_APP_CATEGORY_SMALL_BUTTON_SHADOW      13
#define NOTES_APP_CATEGORY_TEXT_TAIL_GAP_ALIGNMENT  3
#define NOTES_APP_CATEGORY_TEXT_TAIL_GAP_ALIGNMENT_BIG         5
#endif

enum{
	FRAME_1 = 1,
	FRAME_2
  	};


class VappNotesCustomContentFrame : public VcpListMenuCellClientBaseFrame
{

public:

    virtual void onCreateElements(){}

    virtual void onCloseElements(){}

	virtual void onLayoutElements(){}

    virtual void onUpdateElements(){}
};



class VappNotesPage : public VfxPage , public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappNotesPage);
//constructor
public:
	VappNotesPage(mmi_note_category_color_enum color = NOTES_CATAEGORY_COLOR_TOTAL):text_frame(NULL), m_color(color)
	{
		title_bar = NULL;
		tool_bar = NULL;
		del_tool_bar = NULL;
		text_frame = NULL;
		listMenu = NULL;
		search_bar = NULL;
		search_editor = NULL;
		frame_top = NULL;
		m_category_new = 0;
	}

// variables
private:
	VcpTitleBar *title_bar;
	VcpToolBar *tool_bar;
	VcpToolBar *del_tool_bar;
	VfxTextFrame *text_frame;
	VcpListMenu *listMenu;
	VcpListMenuSearchBar *search_bar;
	VcpTextEditor *search_editor;
	mmi_note_category_color_enum m_color;
	VfxFrame *frame_top;
	VfxU8 m_category_new;

	enum {
		ADD_BUTTON = 1,
		LIST_DELETE_BUTTON,                /*delete button for the notes list screen*/ 
		MARK_LIST_DELETE_BUTTON,		/*delete button for the amrk several screen*/ 		
		CATEGORY_BUTTON,
		SEARCH_BUTTON,
		SELECT_ALL_BUTTON,
		UNSELECT_ALL_BUTTON,
		CANCEL_BUTTON,
		CNTXT_EDIT_BUTTON,
		CNTXT_DELETE_BUTTON,
		TOTAL_BUTTON
  	};


//member functions



public:
	virtual void onInit();	
	virtual void onEnter(VfxBool isBackward);
	virtual void onUpdate();
	virtual void onEntered();
	virtual void onBack();
	virtual VfxU32 getCount() const;
    virtual void onExited();
	void updateToolBar();
#ifndef __LOW_COST_SUPPORT_COMMON__
	void vapp_notes_list_setColor(mmi_note_category_color_enum id)
	{
		m_color = id;
	}
	void vapp_notes_list_setNewCategory(VfxU8 state)
	{
		m_category_new = state;
	}
#endif

	/*Event handler for the buttons provided on the tool bar*/
	void vapp_notes_page_tool_bar_button_handler(VfxObject* obj, VfxId id);

	virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,        // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        ) ;	

	 virtual VcpListMenuItemStateEnum getItemState(
        	VfxU32 index   // [IN] index of the item
        	) const;
    virtual VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        ) 
	 {
		 switch(m_color)
					{
					
					#ifndef __LOW_COST_SUPPORT_COMMON__
						case NOTES_CATAEGORY_COLOR_WHITE:
								text.loadFromRes(STR_ID_VAPP_NOTES_NOTES_WHITE_NO);
								break;
						case NOTES_CATAEGORY_COLOR_BLUE:
								text.loadFromRes(STR_ID_VAPP_NOTES_NOTES_BLUE_NO);
								break;
						case NOTES_CATAEGORY_COLOR_GREEN:
								text.loadFromRes(STR_ID_VAPP_NOTES_NOTES_GREEN_NO);
								break;
						case NOTES_CATAEGORY_COLOR_YELLOW:
								text.loadFromRes(STR_ID_VAPP_NOTES_NOTES_YELLOW_NO);
								break;
						case NOTES_CATAEGORY_COLOR_ORANGE:
								text.loadFromRes(STR_ID_VAPP_NOTES_NOTES_ORANGE_NO);
								break;
						case NOTES_CATAEGORY_COLOR_RED:
								text.loadFromRes(STR_ID_VAPP_NOTES_NOTES_RED_NO);
								break;
					#endif    /*__LOW_COST_SUPPORT_COMMON__*/
						case NOTES_CATAEGORY_COLOR_TOTAL:
								text.loadFromRes(STR_ID_VAPP_NOTES_NOTES_NO_NOTES);
								break;
					
						default:
							break;
					}
        return VFX_TRUE;
	 };
	 
	void vapp_notes_page_onSelectionChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState); /*mark several screen handler*/
	void vapp_notes_page_onSelectionitemtapped(VcpListMenu *menu, VfxU32 index);
	void vapp_notes_page_onSelectionItemLongTapped(VcpListMenu *menu, VfxU32 index);
	void vapp_notes_page_OptionDeleteconfirm(VfxObject *obj, VfxId id);
	void vapp_notes_page_marked_notes_delete_confirmation(VfxObject * obj,VfxId id);
	void vapp_notes_page_OptionPopup_cntx(VcpMenuPopup * menu,  VcpMenuPopupEventEnum event, VcpMenuPopupItem * item);
	void vapp_notes_page_onSearchTextChanged(VcpTextEditor *editor);
	
private:
	void setTopbarTitle();
	
};

class VappNotesPageviewer : public VfxPage 
{
    VFX_DECLARE_CLASS(VappNotesPageviewer);
public:
	VappNotesPageviewer()
	{
		tool_bar = NULL;
		bg_frame1 = NULL;
		bg_frame2 = NULL;
		text_frame_date1 = NULL;
		text_frame_date2 = NULL;
		text_frame_time1 = NULL;
		text_frame_time2 = NULL;
		m_text1 = NULL;
		m_text2 = NULL;
		top_button_frame = NULL;
		button_previous = NULL;
		button_next = NULL;
		view_panel = NULL;
		current_view_frame = NULL;
		new_view_frame = NULL;
		m_hintText = NULL;
		bg_frame_upper1 = NULL;
		bg_frame_upper2 = NULL;

	}
public:
	VcpToolBar *tool_bar;
	VfxFrame *bg_frame1, *bg_frame2,*bg_frame_upper1,*bg_frame_upper2;
	VfxTextFrame *text_frame_date1, *text_frame_date2,*text_frame_time1,*text_frame_time2;	 
	VfxFontDesc     font_size1, font_size2;
	VcpTextView *m_text1, *m_text2;
	VfxFrame *top_button_frame;	
	VcpImageButton *button_previous, *button_next; 
	VcpPagePanel *view_panel;
	VfxFrame *current_view_frame;
	VfxFrame *new_view_frame;
	VfxTextFrame *m_hintText;
	VfxWString update;
public:
    virtual void onInit();	
	virtual void onEnter(VfxBool isbackward);
	virtual VfxBool onKeyInput(VfxKeyEvent &event);
	void vapp_notes_viewer_page_tool_bar_button_handler(VfxObject * obj,VfxId id);
	void vapp_notes_viewer_OptionDeleteconfirm(VfxObject *obj, VfxId id);
	void vapp_notes_viewer_prev_button_handler(VfxObject * obj,VfxId id);
	void vapp_notes_viewer_next_button_handler(VfxObject * obj,VfxId id);
	//void onEffectFinish(VfxFrame *target, VfxBool isCompleted);
	private:
	 enum {
			EDIT_BUTTON = 1,
			DELETE_BUTTON,
			PREVIOUS_NOTE_BUTTON,
			NEXT_NOTE_BUTTON,
			TOTAL_BUTTON
  		}; 

};

#ifndef __LOW_COST_SUPPORT_COMMON__
class VappNotesCategoryView : public VfxPage 
{
	VFX_DECLARE_CLASS(VappNotesCategoryView);

public:
	virtual void onInit();
	void vapp_notes_category_page_color_button_handler(VfxObject* obj, VfxId id);

public:
	VfxPage *m_notesCategory;
	enum {
		VAPP_NOTES_TOTAL_NOTES = 0,
		VAPP_NOTES_ONLY_WHITE_NOTES,
		VAPP_NOTES_ONLY_BLUE_NOTES,
		VAPP_NOTES_ONLY_GREEN_NOTES,
		VAPP_NOTES_ONLY_YELLOW_NOTES,
		VAPP_NOTES_ONLY_ORANGE_NOTES,
		VAPP_NOTES_ONLY_RED_NOTES,
		NOTES_COLOR_END
	};

};
#endif /*__LOW_COST_SUPPORT_COMMON__*/

#endif /*__MMI_NOTE_APP__ */
#endif /* __VAPP_NOTES_APP_H__ */
