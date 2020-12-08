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
 *   wgui_virtual_keyboard.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Virtual keyboard - WGUI integration
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
 * removed!
 * removed!
 * removed!
 * removed!
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

/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
*/


#ifndef __WGUI_VIRTUAL_KEYBOARD_H__
#define __WGUI_VIRTUAL_KEYBOARD_H__
#include "MMI_features.h"

    #include "MMIDataType.h"
   /*  #include "kal_non_specific_general_types.h" */ 
    #include "gui_data_types.h"
    #include "mmi_frm_input_gprot.h"
    #include "gui.h"
#if defined(__MMI_VIRTUAL_KEYBOARD__)

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
/*****************************************************************************
 * Following code is for VK V1
 ****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */
#include "gui_virtual_keyboard.h"
#include "wgui.h"

#if defined(__MMI_TOUCH_SCREEN__)

#if defined(__MMI_MAINLCD_320X480__)
#define  MMI_VKBD_MATRIX_KEY_WIDTH              28
#define  MMI_VKBD_MATRIX_KEY_HEIGHT             34
#define  MMI_VKBD_MATRIX_KEY_H_GAP              3
#define  MMI_VKBD_MATRIX_KEY_V_GAP              4

#define  MATRIX_WIDTH(col)       ((col)*(MMI_VKBD_MATRIX_KEY_WIDTH+MMI_VKBD_MATRIX_KEY_H_GAP) - MMI_VKBD_MATRIX_KEY_H_GAP)
#define  MATRIX_HEIGHT(row)      ((row)*(MMI_VKBD_MATRIX_KEY_HEIGHT+MMI_VKBD_MATRIX_KEY_V_GAP) - MMI_VKBD_MATRIX_KEY_V_GAP)

#define  MATRIX_WIDTH_EXT(col, key_width, h_gap)   ( (col) * ((key_width) + (h_gap)) - (h_gap) )
#define  MATRIX_HEIGHT_EXT(row, key_height, v_gap) ( (row) * ((key_height) + (v_gap)) - (v_gap) )


#define  MMI_VKBD_STANDARD_WIDTH                320
#define  MMI_VKBD_STANDARD_HEIGHT               154
/* matrix layout at the left side */
#define  MMI_VKBD_STANDARD_MATRIX_COLUMN        7
#define  MMI_VKBD_STANDARD_MATRIX_ROW           3
#define  MMI_VKBD_STANDARD_MATRIX_X             37
#define  MMI_VKBD_STANDARD_MATRIX_Y             3
#define  MMI_VKBD_STANDARD_MATRIX_WIDTH         MATRIX_WIDTH(7)
#define  MMI_VKBD_STANDARD_MATRIX_HEIGHT        MATRIX_HEIGHT(3)

#define  MMI_VKBD_EXTENDED_WIDTH                320
#define  MMI_VKBD_EXTENDED_HEIGHT               192
/* matrix layout at the left side */
#define  MMI_VKBD_EXTENDED_MATRIX_COLUMN        8
#define  MMI_VKBD_EXTENDED_MATRIX_ROW           4
#define  MMI_VKBD_EXTENDED_MATRIX_X             6
#define  MMI_VKBD_EXTENDED_MATRIX_Y             3
#define  MMI_VKBD_EXTENDED_MATRIX_WIDTH         MATRIX_WIDTH(8)
#define  MMI_VKBD_EXTENDED_MATRIX_HEIGHT        MATRIX_HEIGHT(4)

#define  MMI_VKBD_CYRILLIC_WIDTH                320
#define  MMI_VKBD_CYRILLIC_HEIGHT               154
#define  MMI_VKBD_CYRILLIC_MATRIX_COLUMN        10
#define  MMI_VKBD_CYRILLIC_MATRIX_ROW           3
#define  MMI_VKBD_CYRILLIC_MATRIX_X             30
#define  MMI_VKBD_CYRILLIC_MATRIX_Y             3
#define  MMI_VKBD_CYRILLIC_MATRIX_WIDTH         259
#define  MMI_VKBD_CYRILLIC_MATRIX_HEIGHT        109
#define  MMI_VKBD_CYRILLIC_MATRIX_KEY_WIDTH    25
#define  MMI_VKBD_CYRILLIC_MATRIX_KEY_HEIGHT   33
#define  MMI_VKBD_CYRILLIC_MATRIX_KEY_H_GAP   1
#define  MMI_VKBD_CYRILLIC_MATRIX_KEY_V_GAP   5  


/* two line tray vk (For tray and empty tray) */
#define  MMI_VKBD_TRAY_WIDTH                    320
#define  MMI_VKBD_TRAY_HEIGHT                   78
#define  MMI_VKBD_TRAY_MATRIX_COLUMN            5
#define  MMI_VKBD_TRAY_MATRIX_ROW               1
#define  MMI_VKBD_TRAY_MATRIX_X                 6
#define  MMI_VKBD_TRAY_MATRIX_Y                 3
#define  MMI_VKBD_TRAY_MATRIX_WIDTH             MATRIX_WIDTH(5)
#define  MMI_VKBD_TRAY_MATRIX_HEIGHT            MATRIX_HEIGHT(1)

/* for number and float number */
#define  MMI_VKBD_NUM_TRAY_WIDTH                    320
#define  MMI_VKBD_NUM_TRAY_HEIGHT                   40
#define  MMI_VKBD_NUM_TRAY_MATRIX_COLUMN            10
#define  MMI_VKBD_NUM_TRAY_MATRIX_ROW               1
#define  MMI_VKBD_NUM_TRAY_MATRIX_X                 4
#define  MMI_VKBD_NUM_TRAY_MATRIX_Y                 3
#define  MMI_VKBD_NUM_TRAY_MATRIX_WIDTH             259
#define  MMI_VKBD_NUM_TRAY_MATRIX_HEIGHT            33
#define  MMI_VKBD_MATRIX_NUM_TRAY_KEY_WIDTH 25
#define  MMI_VKBD_MATRIX_NUM_TRAY_KEY_HEIGHT 33
#define  MMI_VKBD_MATRIX_NUM_TRAY_KEY_H_GAP              1


#define  MMI_VKBD_NUMBER_WIDTH                  320
#define  MMI_VKBD_NUMBER_HEIGHT                 116
/* matrix layout at the left side */
#define  MMI_VKBD_NUMBER_MATRIX_COLUMN          8
#define  MMI_VKBD_NUMBER_MATRIX_ROW             2
#define  MMI_VKBD_NUMBER_MATRIX_X               6
#define  MMI_VKBD_NUMBER_MATRIX_Y               2
#define  MMI_VKBD_NUMBER_MATRIX_WIDTH           MATRIX_WIDTH(8)
#define  MMI_VKBD_NUMBER_MATRIX_HEIGHT          MATRIX_HEIGHT(2)

#define  MMI_VKBD_PINYIN_WIDTH                  320
#define  MMI_VKBD_PINYIN_HEIGHT                 192
/* matrix layout at the left-bottom */
#define  MMI_VKBD_PINYIN_MATRIX_COLUMN          9
#define  MMI_VKBD_PINYIN_MATRIX_ROW             3
#define  MMI_VKBD_PINYIN_MATRIX_X               6
#define  MMI_VKBD_PINYIN_MATRIX_Y               41
#define  MMI_VKBD_PINYIN_MATRIX_WIDTH           MATRIX_WIDTH(9)
#define  MMI_VKBD_PINYIN_MATRIX_HEIGHT          MATRIX_HEIGHT(3)

#define  MMI_VKBD_BOPOMO_WIDTH                  320
#define  MMI_VKBD_BOPOMO_HEIGHT                 192
/* matrix layout at the left-bottom */
#define  MMI_VKBD_BOPOMO_MATRIX_COLUMN          10
#define  MMI_VKBD_BOPOMO_MATRIX_ROW             3
#define  MMI_VKBD_BOPOMO_MATRIX_X               4
#define  MMI_VKBD_BOPOMO_MATRIX_Y               41
#define  MMI_VKBD_BOPOMO_MATRIX_KEY_H_GAP 1
#define  MMI_VKBD_BOPOMO_MATRIX_KEY_V_GAP 5
#define  MMI_VKBD_BOPOMO_MATRIX_WIDTH           259//MATRIX_WIDTH(10)
#define  MMI_VKBD_BOPOMO_MATRIX_HEIGHT          109//MATRIX_HEIGHT(3)
#define  MMI_VKBD_BOPOMO_MATRIX_KEY_WIDTH              25
#define  MMI_VKBD_BOPOMO_MATRIX_KEY_HEIGHT             33

#define  MMI_VKBD_CH_SYMBOL_WIDTH                320
#define  MMI_VKBD_CH_SYMBOL_HEIGHT               154
#define  MMI_VKBD_CH_SYMBOL_MATRIX_COLUMN        8
#define  MMI_VKBD_CH_SYMBOL_MATRIX_ROW           3
#define  MMI_VKBD_CH_SYMBOL_MATRIX_X             6
#define  MMI_VKBD_CH_SYMBOL_MATRIX_Y             3
#define  MMI_VKBD_CH_SYMBOL_MATRIX_WIDTH         MATRIX_WIDTH(8)
#define  MMI_VKBD_CH_SYMBOL_MATRIX_HEIGHT        MATRIX_HEIGHT(3)

#define  MMI_VKBD_EUROPEAN_WIDTH                  320
#define  MMI_VKBD_EUROPEAN_HEIGHT                 192
#define  MMI_VKBD_EUROPEAN_MATRIX_KEY_WIDTH       28
#define  MMI_VKBD_EUROPEAN_MATRIX_KEY_HEIGHT      34
#define  MMI_VKBD_EUROPEAN_MATRIX_KEY_H_GAP       3
#define  MMI_VKBD_EUROPEAN_MATRIX_KEY_V_GAP       4
#define  MMI_VKBD_EUROPEAN_MATRIX_COLUMN          7
#define  MMI_VKBD_EUROPEAN_MATRIX_ROW             4
#define  MMI_VKBD_EUROPEAN_MATRIX_X               37
#define  MMI_VKBD_EUROPEAN_MATRIX_Y               3
#define  MMI_VKBD_EUROPEAN_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_EUROPEAN_MATRIX_COLUMN, MMI_VKBD_EUROPEAN_MATRIX_KEY_WIDTH, MMI_VKBD_EUROPEAN_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_EUROPEAN_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_EUROPEAN_MATRIX_ROW, MMI_VKBD_EUROPEAN_MATRIX_KEY_HEIGHT, MMI_VKBD_EUROPEAN_MATRIX_KEY_V_GAP)


#define  MMI_VKBD_CZECH_WIDTH                  320
#define  MMI_VKBD_CZECH_HEIGHT                 83
/* matrix layout at the left-bottom */
#define  MMI_VKBD_CZECH_MATRIX_KEY_WIDTH       25
#define  MMI_VKBD_CZECH_MATRIX_KEY_HEIGHT      19
#define  MMI_VKBD_CZECH_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_CZECH_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_CZECH_MATRIX_COLUMN          7
#define  MMI_VKBD_CZECH_MATRIX_ROW             4
#define  MMI_VKBD_CZECH_MATRIX_X               1
#define  MMI_VKBD_CZECH_MATRIX_Y               2
#define  MMI_VKBD_CZECH_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_CZECH_MATRIX_COLUMN, MMI_VKBD_CZECH_MATRIX_KEY_WIDTH, MMI_VKBD_CZECH_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_CZECH_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_CZECH_MATRIX_ROW, MMI_VKBD_CZECH_MATRIX_KEY_HEIGHT, MMI_VKBD_CZECH_MATRIX_KEY_V_GAP)


#define  MMI_VKBD_HEBREW_WIDTH                  176        
#define  MMI_VKBD_HEBREW_HEIGHT                 46
/* matrix layout at the left-bottom */
#define  MMI_VKBD_HEBREW_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_HEBREW_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_HEBREW_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_HEBREW_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_HEBREW_MATRIX_COLUMN          8
#define  MMI_VKBD_HEBREW_MATRIX_ROW             3
#define  MMI_VKBD_HEBREW_MATRIX_X               1
#define  MMI_VKBD_HEBREW_MATRIX_Y               1
#define  MMI_VKBD_HEBREW_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_HEBREW_MATRIX_COLUMN, MMI_VKBD_HEBREW_MATRIX_KEY_WIDTH, MMI_VKBD_HEBREW_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_HEBREW_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_HEBREW_MATRIX_ROW, MMI_VKBD_HEBREW_MATRIX_KEY_HEIGHT, MMI_VKBD_HEBREW_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_FARSI_WIDTH                  320        
#define  MMI_VKBD_FARSI_HEIGHT                 82
/* matrix layout at the left-bottom */
#define  MMI_VKBD_FARSI_MATRIX_KEY_WIDTH       25
#define  MMI_VKBD_FARSI_MATRIX_KEY_HEIGHT      34
#define  MMI_VKBD_FARSI_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_FARSI_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_FARSI_MATRIX_COLUMN          9
#define  MMI_VKBD_FARSI_MATRIX_ROW             4
#define  MMI_VKBD_FARSI_MATRIX_X               1
#define  MMI_VKBD_FARSI_MATRIX_Y               2
#define  MMI_VKBD_FARSI_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_FARSI_MATRIX_COLUMN, MMI_VKBD_FARSI_MATRIX_KEY_WIDTH, MMI_VKBD_FARSI_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_FARSI_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_FARSI_MATRIX_ROW, MMI_VKBD_FARSI_MATRIX_KEY_HEIGHT, MMI_VKBD_FARSI_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_FARSI_SYMBOL_WIDTH                  176        
#define  MMI_VKBD_FARSI_SYMBOL_HEIGHT                 76
/* matrix layout at the left-bottom */
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_COLUMN          9
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_ROW             5
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_X               4
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_Y               1
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_FARSI_SYMBOL_MATRIX_COLUMN, MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_WIDTH, MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_FARSI_SYMBOL_MATRIX_ROW, MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_HEIGHT, MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_GREEK_WIDTH                  176        
#define  MMI_VKBD_GREEK_HEIGHT                 46
/* matrix layout at the left-bottom */
#define  MMI_VKBD_GREEK_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_GREEK_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_GREEK_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_GREEK_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_GREEK_MATRIX_COLUMN          7
#define  MMI_VKBD_GREEK_MATRIX_ROW             3
#define  MMI_VKBD_GREEK_MATRIX_X               1
#define  MMI_VKBD_GREEK_MATRIX_Y               1
#define  MMI_VKBD_GREEK_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_GREEK_MATRIX_COLUMN, MMI_VKBD_GREEK_MATRIX_KEY_WIDTH, MMI_VKBD_GREEK_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_GREEK_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_GREEK_MATRIX_ROW, MMI_VKBD_GREEK_MATRIX_KEY_HEIGHT, MMI_VKBD_GREEK_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_BULGARIAN_WIDTH                  320       
#define  MMI_VKBD_BULGARIAN_HEIGHT                 83
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_BULGARIAN_MATRIX_KEY_WIDTH       25
#define  MMI_VKBD_BULGARIAN_MATRIX_KEY_HEIGHT      19
#define  MMI_VKBD_BULGARIAN_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_BULGARIAN_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_BULGARIAN_MATRIX_COLUMN          7
#define  MMI_VKBD_BULGARIAN_MATRIX_ROW             4
#define  MMI_VKBD_BULGARIAN_MATRIX_X               1
#define  MMI_VKBD_BULGARIAN_MATRIX_Y               2
#define  MMI_VKBD_BULGARIAN_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_BULGARIAN_MATRIX_COLUMN, MMI_VKBD_BULGARIAN_MATRIX_KEY_WIDTH, MMI_VKBD_BULGARIAN_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_BULGARIAN_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_BULGARIAN_MATRIX_ROW, MMI_VKBD_BULGARIAN_MATRIX_KEY_HEIGHT, MMI_VKBD_BULGARIAN_MATRIX_KEY_V_GAP)


#define  MMI_VKBD_DANISH_WIDTH                  176        
#define  MMI_VKBD_DANISH_HEIGHT                 46
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_DANISH_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_DANISH_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_DANISH_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_DANISH_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_DANISH_MATRIX_COLUMN          7
#define  MMI_VKBD_DANISH_MATRIX_ROW             3
#define  MMI_VKBD_DANISH_MATRIX_X               1
#define  MMI_VKBD_DANISH_MATRIX_Y               1
#define  MMI_VKBD_DANISH_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_DANISH_MATRIX_COLUMN, MMI_VKBD_DANISH_MATRIX_KEY_WIDTH, MMI_VKBD_DANISH_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_DANISH_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_DANISH_MATRIX_ROW, MMI_VKBD_DANISH_MATRIX_KEY_HEIGHT, MMI_VKBD_DANISH_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_HUNGARIAN_WIDTH                  320        
#define  MMI_VKBD_HUNGARIAN_HEIGHT                 192
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_HUNGARIAN_MATRIX_KEY_WIDTH       25
#define  MMI_VKBD_HUNGARIAN_MATRIX_KEY_HEIGHT      34
#define  MMI_VKBD_HUNGARIAN_MATRIX_KEY_H_GAP       3
#define  MMI_VKBD_HUNGARIAN_MATRIX_KEY_V_GAP       4
#define  MMI_VKBD_HUNGARIAN_MATRIX_COLUMN          7
#define  MMI_VKBD_HUNGARIAN_MATRIX_ROW             4
#define  MMI_VKBD_HUNGARIAN_MATRIX_X               35
#define  MMI_VKBD_HUNGARIAN_MATRIX_Y               3
#define  MMI_VKBD_HUNGARIAN_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_HUNGARIAN_MATRIX_COLUMN, MMI_VKBD_HUNGARIAN_MATRIX_KEY_WIDTH, MMI_VKBD_HUNGARIAN_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_HUNGARIAN_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_HUNGARIAN_MATRIX_ROW, MMI_VKBD_HUNGARIAN_MATRIX_KEY_HEIGHT, MMI_VKBD_HUNGARIAN_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_FINNISH_WIDTH                  176        
#define  MMI_VKBD_FINNISH_HEIGHT                 46
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_FINNISH_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_FINNISH_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_FINNISH_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_FINNISH_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_FINNISH_MATRIX_COLUMN          8
#define  MMI_VKBD_FINNISH_MATRIX_ROW             3
#define  MMI_VKBD_FINNISH_MATRIX_X               1
#define  MMI_VKBD_FINNISH_MATRIX_Y               1
#define  MMI_VKBD_FINNISH_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_FINNISH_MATRIX_COLUMN, MMI_VKBD_FINNISH_MATRIX_KEY_WIDTH, MMI_VKBD_FINNISH_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_FINNISH_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_FINNISH_MATRIX_ROW, MMI_VKBD_FINNISH_MATRIX_KEY_HEIGHT, MMI_VKBD_FINNISH_MATRIX_KEY_V_GAP)


#define  MMI_VKBD_POLISH_WIDTH                  176        
#define  MMI_VKBD_POLISH_HEIGHT                 61
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_POLISH_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_POLISH_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_POLISH_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_POLISH_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_POLISH_MATRIX_COLUMN          7
#define  MMI_VKBD_POLISH_MATRIX_ROW             4
#define  MMI_VKBD_POLISH_MATRIX_X               1
#define  MMI_VKBD_POLISH_MATRIX_Y               1
#define  MMI_VKBD_POLISH_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_POLISH_MATRIX_COLUMN, MMI_VKBD_POLISH_MATRIX_KEY_WIDTH, MMI_VKBD_POLISH_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_POLISH_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_POLISH_MATRIX_ROW, MMI_VKBD_POLISH_MATRIX_KEY_HEIGHT, MMI_VKBD_POLISH_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_VIETNAMESE_WIDTH                  176        
#define  MMI_VKBD_VIETNAMESE_HEIGHT                 61
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_VIETNAMESE_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_VIETNAMESE_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_VIETNAMESE_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_VIETNAMESE_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_VIETNAMESE_MATRIX_COLUMN          5   
#define  MMI_VKBD_VIETNAMESE_MATRIX_ROW             4
#define  MMI_VKBD_VIETNAMESE_MATRIX_X               0
#define  MMI_VKBD_VIETNAMESE_MATRIX_Y               1
#define  MMI_VKBD_VIETNAMESE_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_VIETNAMESE_MATRIX_COLUMN, MMI_VKBD_VIETNAMESE_MATRIX_KEY_WIDTH, MMI_VKBD_VIETNAMESE_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_VIETNAMESE_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_VIETNAMESE_MATRIX_ROW, MMI_VKBD_VIETNAMESE_MATRIX_KEY_HEIGHT, MMI_VKBD_VIETNAMESE_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_ARABIC_WIDTH                  320        
#define  MMI_VKBD_ARABIC_HEIGHT                 154
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_ARABIC_MATRIX_KEY_WIDTH       25
#define  MMI_VKBD_ARABIC_MATRIX_KEY_HEIGHT      33
#define  MMI_VKBD_ARABIC_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_ARABIC_MATRIX_KEY_V_GAP       5
#define  MMI_VKBD_ARABIC_MATRIX_COLUMN          10   
#define  MMI_VKBD_ARABIC_MATRIX_ROW             3
#define  MMI_VKBD_ARABIC_MATRIX_X               30
#define  MMI_VKBD_ARABIC_MATRIX_Y               3
#define  MMI_VKBD_ARABIC_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_ARABIC_MATRIX_COLUMN, MMI_VKBD_ARABIC_MATRIX_KEY_WIDTH, MMI_VKBD_ARABIC_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_ARABIC_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_ARABIC_MATRIX_ROW, MMI_VKBD_ARABIC_MATRIX_KEY_HEIGHT, MMI_VKBD_ARABIC_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_THAI_WIDTH                  320        
#define  MMI_VKBD_THAI_HEIGHT                 192
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_THAI_MATRIX_KEY_WIDTH       25
#define  MMI_VKBD_THAI_MATRIX_KEY_HEIGHT      33
#define  MMI_VKBD_THAI_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_THAI_MATRIX_KEY_V_GAP       5
#define  MMI_VKBD_THAI_MATRIX_COLUMN          10   
#define  MMI_VKBD_THAI_MATRIX_ROW             4
#define  MMI_VKBD_THAI_MATRIX_X               30
#define  MMI_VKBD_THAI_MATRIX_Y               3
#define  MMI_VKBD_THAI_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_THAI_MATRIX_COLUMN, MMI_VKBD_THAI_MATRIX_KEY_WIDTH, MMI_VKBD_THAI_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_THAI_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_THAI_MATRIX_ROW, MMI_VKBD_THAI_MATRIX_KEY_HEIGHT, MMI_VKBD_THAI_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_ARABIC_SYMBOL_WIDTH                  320        
#define  MMI_VKBD_ARABIC_SYMBOL_HEIGHT                 192
/* matrix layout at the left-bottom */
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_WIDTH       25
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_HEIGHT      33
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_V_GAP       5
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_COLUMN          11
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_ROW             4
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_X               4
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_Y               3
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_ARABIC_SYMBOL_MATRIX_COLUMN, MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_WIDTH, MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_ARABIC_SYMBOL_MATRIX_ROW, MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_HEIGHT, MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_UKRAINIAN_WIDTH                  176        
#define  MMI_VKBD_UKRAINIAN_HEIGHT                 61
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_UKRAINIAN_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_UKRAINIAN_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_UKRAINIAN_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_UKRAINIAN_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_UKRAINIAN_MATRIX_COLUMN          5   
#define  MMI_VKBD_UKRAINIAN_MATRIX_ROW             4
#define  MMI_VKBD_UKRAINIAN_MATRIX_X               4
#define  MMI_VKBD_UKRAINIAN_MATRIX_Y               1
#define  MMI_VKBD_UKRAINIAN_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_UKRAINIAN_MATRIX_COLUMN, MMI_VKBD_UKRAINIAN_MATRIX_KEY_WIDTH, MMI_VKBD_UKRAINIAN_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_UKRAINIAN_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_UKRAINIAN_MATRIX_ROW, MMI_VKBD_UKRAINIAN_MATRIX_KEY_HEIGHT, MMI_VKBD_UKRAINIAN_MATRIX_KEY_V_GAP)

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)

#define  MMI_VKBD_MATRIX_KEY_WIDTH              19
#define  MMI_VKBD_MATRIX_KEY_HEIGHT             19
#define  MMI_VKBD_MATRIX_KEY_H_GAP              1
#define  MMI_VKBD_MATRIX_KEY_V_GAP              1

#define  MATRIX_WIDTH(col)       ((col)*(MMI_VKBD_MATRIX_KEY_WIDTH+MMI_VKBD_MATRIX_KEY_H_GAP) - MMI_VKBD_MATRIX_KEY_H_GAP)
#define  MATRIX_HEIGHT(row)      ((row)*(MMI_VKBD_MATRIX_KEY_HEIGHT+MMI_VKBD_MATRIX_KEY_V_GAP) - MMI_VKBD_MATRIX_KEY_V_GAP)

#define  MATRIX_WIDTH_EXT(col, key_width, h_gap)   ( (col) * ((key_width) + (h_gap)) - (h_gap) )
#define  MATRIX_HEIGHT_EXT(row, key_height, v_gap) ( (row) * ((key_height) + (v_gap)) - (v_gap) )

#define  MMI_VKBD_STANDARD_WIDTH                240
#define  MMI_VKBD_STANDARD_HEIGHT               63
/* matrix layout at the left side */
#define  MMI_VKBD_STANDARD_MATRIX_COLUMN        7
#define  MMI_VKBD_STANDARD_MATRIX_ROW           3
#define  MMI_VKBD_STANDARD_MATRIX_X             1
#define  MMI_VKBD_STANDARD_MATRIX_Y             2
#define  MMI_VKBD_STANDARD_MATRIX_WIDTH         MATRIX_WIDTH(7)
#define  MMI_VKBD_STANDARD_MATRIX_HEIGHT        MATRIX_HEIGHT(3)

#define  MMI_VKBD_EXTENDED_WIDTH                240
#define  MMI_VKBD_EXTENDED_HEIGHT               83
/* matrix layout at the left side */
#define  MMI_VKBD_EXTENDED_MATRIX_COLUMN        8
#define  MMI_VKBD_EXTENDED_MATRIX_ROW           4
#define  MMI_VKBD_EXTENDED_MATRIX_X             1
#define  MMI_VKBD_EXTENDED_MATRIX_Y             2
#define  MMI_VKBD_EXTENDED_MATRIX_WIDTH         MATRIX_WIDTH(8)
#define  MMI_VKBD_EXTENDED_MATRIX_HEIGHT        MATRIX_HEIGHT(4)

#define  MMI_VKBD_TRAY_WIDTH                    240
#define  MMI_VKBD_TRAY_HEIGHT                   23
/* matrix layout at the left side */
#define  MMI_VKBD_TRAY_MATRIX_COLUMN            5
#define  MMI_VKBD_TRAY_MATRIX_ROW               1
#define  MMI_VKBD_TRAY_MATRIX_X                 1
#define  MMI_VKBD_TRAY_MATRIX_Y                 2
#define  MMI_VKBD_TRAY_MATRIX_WIDTH             MATRIX_WIDTH(5)
#define  MMI_VKBD_TRAY_MATRIX_HEIGHT            MATRIX_HEIGHT(1)

#define  MMI_VKBD_NUMBER_WIDTH                  240
#define  MMI_VKBD_NUMBER_HEIGHT                 43
/* matrix layout at the left side */
#define  MMI_VKBD_NUMBER_MATRIX_COLUMN          8
#define  MMI_VKBD_NUMBER_MATRIX_ROW             2
#define  MMI_VKBD_NUMBER_MATRIX_X               1
#define  MMI_VKBD_NUMBER_MATRIX_Y               2
#define  MMI_VKBD_NUMBER_MATRIX_WIDTH           MATRIX_WIDTH(8)
#define  MMI_VKBD_NUMBER_MATRIX_HEIGHT          MATRIX_HEIGHT(2)

#define  MMI_VKBD_PINYIN_WIDTH                  240
#define  MMI_VKBD_PINYIN_HEIGHT                 83
/* matrix layout at the left-bottom */
#define  MMI_VKBD_PINYIN_MATRIX_COLUMN          9
#define  MMI_VKBD_PINYIN_MATRIX_ROW             3
#define  MMI_VKBD_PINYIN_MATRIX_X               1
#define  MMI_VKBD_PINYIN_MATRIX_Y               22
#define  MMI_VKBD_PINYIN_MATRIX_WIDTH           MATRIX_WIDTH(9)
#define  MMI_VKBD_PINYIN_MATRIX_HEIGHT          MATRIX_HEIGHT(3)

#define  MMI_VKBD_BOPOMO_WIDTH                  240
#define  MMI_VKBD_BOPOMO_HEIGHT                 83
/* matrix layout at the left-bottom */
#define  MMI_VKBD_BOPOMO_MATRIX_COLUMN          10
#define  MMI_VKBD_BOPOMO_MATRIX_ROW             3
#define  MMI_VKBD_BOPOMO_MATRIX_X               1
#define  MMI_VKBD_BOPOMO_MATRIX_Y               22
#define  MMI_VKBD_BOPOMO_MATRIX_WIDTH           MATRIX_WIDTH(10)
#define  MMI_VKBD_BOPOMO_MATRIX_HEIGHT          MATRIX_HEIGHT(3)


#define  MMI_VKBD_CZECH_WIDTH                  240        
#define  MMI_VKBD_CZECH_HEIGHT                 83
/* matrix layout at the left-bottom */
#define  MMI_VKBD_CZECH_MATRIX_KEY_WIDTH       19
#define  MMI_VKBD_CZECH_MATRIX_KEY_HEIGHT      19
#define  MMI_VKBD_CZECH_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_CZECH_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_CZECH_MATRIX_COLUMN          7
#define  MMI_VKBD_CZECH_MATRIX_ROW             4
#define  MMI_VKBD_CZECH_MATRIX_X               1
#define  MMI_VKBD_CZECH_MATRIX_Y               2
#define  MMI_VKBD_CZECH_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_CZECH_MATRIX_COLUMN, MMI_VKBD_CZECH_MATRIX_KEY_WIDTH, MMI_VKBD_CZECH_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_CZECH_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_CZECH_MATRIX_ROW, MMI_VKBD_CZECH_MATRIX_KEY_HEIGHT, MMI_VKBD_CZECH_MATRIX_KEY_V_GAP)


#define  MMI_VKBD_HEBREW_WIDTH                  240        
#define  MMI_VKBD_HEBREW_HEIGHT                 63
/* matrix layout at the left-bottom */
#define  MMI_VKBD_HEBREW_MATRIX_KEY_WIDTH       19
#define  MMI_VKBD_HEBREW_MATRIX_KEY_HEIGHT      19
#define  MMI_VKBD_HEBREW_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_HEBREW_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_HEBREW_MATRIX_COLUMN          8
#define  MMI_VKBD_HEBREW_MATRIX_ROW             3
#define  MMI_VKBD_HEBREW_MATRIX_X               1
#define  MMI_VKBD_HEBREW_MATRIX_Y               2
#define  MMI_VKBD_HEBREW_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_HEBREW_MATRIX_COLUMN, MMI_VKBD_HEBREW_MATRIX_KEY_WIDTH, MMI_VKBD_HEBREW_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_HEBREW_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_HEBREW_MATRIX_ROW, MMI_VKBD_HEBREW_MATRIX_KEY_HEIGHT, MMI_VKBD_HEBREW_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_FARSI_WIDTH                  240        
#define  MMI_VKBD_FARSI_HEIGHT                 83
/* matrix layout at the left-bottom */
#define  MMI_VKBD_FARSI_MATRIX_KEY_WIDTH       19
#define  MMI_VKBD_FARSI_MATRIX_KEY_HEIGHT      19
#define  MMI_VKBD_FARSI_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_FARSI_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_FARSI_MATRIX_COLUMN          9
#define  MMI_VKBD_FARSI_MATRIX_ROW             4
#define  MMI_VKBD_FARSI_MATRIX_X               1
#define  MMI_VKBD_FARSI_MATRIX_Y               2
#define  MMI_VKBD_FARSI_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_FARSI_MATRIX_COLUMN, MMI_VKBD_FARSI_MATRIX_KEY_WIDTH, MMI_VKBD_FARSI_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_FARSI_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_FARSI_MATRIX_ROW, MMI_VKBD_FARSI_MATRIX_KEY_HEIGHT, MMI_VKBD_FARSI_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_FARSI_SYMBOL_WIDTH                  240        
#define  MMI_VKBD_FARSI_SYMBOL_HEIGHT                 103
/* matrix layout at the left-bottom */
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_WIDTH       19
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_HEIGHT      19
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_COLUMN          9
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_ROW             5
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_X               1
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_Y               2
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_FARSI_SYMBOL_MATRIX_COLUMN, MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_WIDTH, MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_FARSI_SYMBOL_MATRIX_ROW, MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_HEIGHT, MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_GREEK_WIDTH                  240        
#define  MMI_VKBD_GREEK_HEIGHT                 63
/* matrix layout at the left-bottom */
#define  MMI_VKBD_GREEK_MATRIX_KEY_WIDTH       19
#define  MMI_VKBD_GREEK_MATRIX_KEY_HEIGHT      19
#define  MMI_VKBD_GREEK_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_GREEK_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_GREEK_MATRIX_COLUMN          7
#define  MMI_VKBD_GREEK_MATRIX_ROW             3
#define  MMI_VKBD_GREEK_MATRIX_X               1
#define  MMI_VKBD_GREEK_MATRIX_Y               2
#define  MMI_VKBD_GREEK_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_GREEK_MATRIX_COLUMN, MMI_VKBD_GREEK_MATRIX_KEY_WIDTH, MMI_VKBD_GREEK_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_GREEK_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_GREEK_MATRIX_ROW, MMI_VKBD_GREEK_MATRIX_KEY_HEIGHT, MMI_VKBD_GREEK_MATRIX_KEY_V_GAP)


#define  MMI_VKBD_BULGARIAN_WIDTH                  240        
#define  MMI_VKBD_BULGARIAN_HEIGHT                 83
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_BULGARIAN_MATRIX_KEY_WIDTH       19
#define  MMI_VKBD_BULGARIAN_MATRIX_KEY_HEIGHT      19
#define  MMI_VKBD_BULGARIAN_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_BULGARIAN_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_BULGARIAN_MATRIX_COLUMN          7
#define  MMI_VKBD_BULGARIAN_MATRIX_ROW             4
#define  MMI_VKBD_BULGARIAN_MATRIX_X               1
#define  MMI_VKBD_BULGARIAN_MATRIX_Y               2
#define  MMI_VKBD_BULGARIAN_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_BULGARIAN_MATRIX_COLUMN, MMI_VKBD_BULGARIAN_MATRIX_KEY_WIDTH, MMI_VKBD_BULGARIAN_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_BULGARIAN_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_BULGARIAN_MATRIX_ROW, MMI_VKBD_BULGARIAN_MATRIX_KEY_HEIGHT, MMI_VKBD_BULGARIAN_MATRIX_KEY_V_GAP)


#define  MMI_VKBD_DANISH_WIDTH                  240        
#define  MMI_VKBD_DANISH_HEIGHT                 63
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_DANISH_MATRIX_KEY_WIDTH       19
#define  MMI_VKBD_DANISH_MATRIX_KEY_HEIGHT      19
#define  MMI_VKBD_DANISH_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_DANISH_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_DANISH_MATRIX_COLUMN          7
#define  MMI_VKBD_DANISH_MATRIX_ROW             3
#define  MMI_VKBD_DANISH_MATRIX_X               1
#define  MMI_VKBD_DANISH_MATRIX_Y               2
#define  MMI_VKBD_DANISH_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_DANISH_MATRIX_COLUMN, MMI_VKBD_DANISH_MATRIX_KEY_WIDTH, MMI_VKBD_DANISH_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_DANISH_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_DANISH_MATRIX_ROW, MMI_VKBD_DANISH_MATRIX_KEY_HEIGHT, MMI_VKBD_DANISH_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_HUNGARIAN_WIDTH                  240        
#define  MMI_VKBD_HUNGARIAN_HEIGHT                 83
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_HUNGARIAN_MATRIX_KEY_WIDTH       19
#define  MMI_VKBD_HUNGARIAN_MATRIX_KEY_HEIGHT      19
#define  MMI_VKBD_HUNGARIAN_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_HUNGARIAN_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_HUNGARIAN_MATRIX_COLUMN          7
#define  MMI_VKBD_HUNGARIAN_MATRIX_ROW             4
#define  MMI_VKBD_HUNGARIAN_MATRIX_X               1
#define  MMI_VKBD_HUNGARIAN_MATRIX_Y               2
#define  MMI_VKBD_HUNGARIAN_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_HUNGARIAN_MATRIX_COLUMN, MMI_VKBD_HUNGARIAN_MATRIX_KEY_WIDTH, MMI_VKBD_HUNGARIAN_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_HUNGARIAN_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_HUNGARIAN_MATRIX_ROW, MMI_VKBD_HUNGARIAN_MATRIX_KEY_HEIGHT, MMI_VKBD_HUNGARIAN_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_FINNISH_WIDTH                  240        
#define  MMI_VKBD_FINNISH_HEIGHT                 63
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_FINNISH_MATRIX_KEY_WIDTH       19
#define  MMI_VKBD_FINNISH_MATRIX_KEY_HEIGHT      19
#define  MMI_VKBD_FINNISH_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_FINNISH_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_FINNISH_MATRIX_COLUMN          8
#define  MMI_VKBD_FINNISH_MATRIX_ROW             3
#define  MMI_VKBD_FINNISH_MATRIX_X               1
#define  MMI_VKBD_FINNISH_MATRIX_Y               2
#define  MMI_VKBD_FINNISH_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_FINNISH_MATRIX_COLUMN, MMI_VKBD_FINNISH_MATRIX_KEY_WIDTH, MMI_VKBD_FINNISH_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_FINNISH_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_FINNISH_MATRIX_ROW, MMI_VKBD_FINNISH_MATRIX_KEY_HEIGHT, MMI_VKBD_FINNISH_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_POLISH_WIDTH                  240        
#define  MMI_VKBD_POLISH_HEIGHT                 83
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_POLISH_MATRIX_KEY_WIDTH       19
#define  MMI_VKBD_POLISH_MATRIX_KEY_HEIGHT      19
#define  MMI_VKBD_POLISH_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_POLISH_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_POLISH_MATRIX_COLUMN          7
#define  MMI_VKBD_POLISH_MATRIX_ROW             4
#define  MMI_VKBD_POLISH_MATRIX_X               1
#define  MMI_VKBD_POLISH_MATRIX_Y               2
#define  MMI_VKBD_POLISH_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_POLISH_MATRIX_COLUMN, MMI_VKBD_POLISH_MATRIX_KEY_WIDTH, MMI_VKBD_POLISH_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_POLISH_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_POLISH_MATRIX_ROW, MMI_VKBD_POLISH_MATRIX_KEY_HEIGHT, MMI_VKBD_POLISH_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_VIETNAMESE_WIDTH                  240        
#define  MMI_VKBD_VIETNAMESE_HEIGHT                 83
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_VIETNAMESE_MATRIX_KEY_WIDTH       19
#define  MMI_VKBD_VIETNAMESE_MATRIX_KEY_HEIGHT      19
#define  MMI_VKBD_VIETNAMESE_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_VIETNAMESE_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_VIETNAMESE_MATRIX_COLUMN          5   
#define  MMI_VKBD_VIETNAMESE_MATRIX_ROW             4
#define  MMI_VKBD_VIETNAMESE_MATRIX_X               1
#define  MMI_VKBD_VIETNAMESE_MATRIX_Y               2
#define  MMI_VKBD_VIETNAMESE_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_VIETNAMESE_MATRIX_COLUMN, MMI_VKBD_VIETNAMESE_MATRIX_KEY_WIDTH, MMI_VKBD_VIETNAMESE_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_VIETNAMESE_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_VIETNAMESE_MATRIX_ROW, MMI_VKBD_VIETNAMESE_MATRIX_KEY_HEIGHT, MMI_VKBD_VIETNAMESE_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_ARABIC_WIDTH                  240        
#define  MMI_VKBD_ARABIC_HEIGHT                 63
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_ARABIC_MATRIX_KEY_WIDTH       19
#define  MMI_VKBD_ARABIC_MATRIX_KEY_HEIGHT      19
#define  MMI_VKBD_ARABIC_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_ARABIC_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_ARABIC_MATRIX_COLUMN          5   
#define  MMI_VKBD_ARABIC_MATRIX_ROW             3
#define  MMI_VKBD_ARABIC_MATRIX_X               1
#define  MMI_VKBD_ARABIC_MATRIX_Y               2
#define  MMI_VKBD_ARABIC_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_ARABIC_MATRIX_COLUMN, MMI_VKBD_ARABIC_MATRIX_KEY_WIDTH, MMI_VKBD_ARABIC_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_ARABIC_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_ARABIC_MATRIX_ROW, MMI_VKBD_ARABIC_MATRIX_KEY_HEIGHT, MMI_VKBD_ARABIC_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_THAI_WIDTH                  240        
#define  MMI_VKBD_THAI_HEIGHT                 83
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_THAI_MATRIX_KEY_WIDTH       19
#define  MMI_VKBD_THAI_MATRIX_KEY_HEIGHT      19
#define  MMI_VKBD_THAI_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_THAI_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_THAI_MATRIX_COLUMN          10   
#define  MMI_VKBD_THAI_MATRIX_ROW             4
#define  MMI_VKBD_THAI_MATRIX_X               1
#define  MMI_VKBD_THAI_MATRIX_Y               2
#define  MMI_VKBD_THAI_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_THAI_MATRIX_COLUMN, MMI_VKBD_THAI_MATRIX_KEY_WIDTH, MMI_VKBD_THAI_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_THAI_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_THAI_MATRIX_ROW, MMI_VKBD_THAI_MATRIX_KEY_HEIGHT, MMI_VKBD_THAI_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_ARABIC_SYMBOL_WIDTH                  240        
#define  MMI_VKBD_ARABIC_SYMBOL_HEIGHT                 83
/* matrix layout at the left-bottom */
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_WIDTH       19
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_HEIGHT      19
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_COLUMN          5
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_ROW             4
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_X               1
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_Y               2
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_ARABIC_SYMBOL_MATRIX_COLUMN, MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_WIDTH, MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_ARABIC_SYMBOL_MATRIX_ROW, MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_HEIGHT, MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_UKRAINIAN_WIDTH                  240        
#define  MMI_VKBD_UKRAINIAN_HEIGHT                 83
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_UKRAINIAN_MATRIX_KEY_WIDTH       19
#define  MMI_VKBD_UKRAINIAN_MATRIX_KEY_HEIGHT      19
#define  MMI_VKBD_UKRAINIAN_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_UKRAINIAN_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_UKRAINIAN_MATRIX_COLUMN          5   
#define  MMI_VKBD_UKRAINIAN_MATRIX_ROW             4
#define  MMI_VKBD_UKRAINIAN_MATRIX_X               1
#define  MMI_VKBD_UKRAINIAN_MATRIX_Y               2
#define  MMI_VKBD_UKRAINIAN_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_UKRAINIAN_MATRIX_COLUMN, MMI_VKBD_UKRAINIAN_MATRIX_KEY_WIDTH, MMI_VKBD_UKRAINIAN_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_UKRAINIAN_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_UKRAINIAN_MATRIX_ROW, MMI_VKBD_UKRAINIAN_MATRIX_KEY_HEIGHT, MMI_VKBD_UKRAINIAN_MATRIX_KEY_V_GAP)

#elif defined(__MMI_MAINLCD_176X220__)

#define  MMI_VKBD_MATRIX_KEY_WIDTH              14
#define  MMI_VKBD_MATRIX_KEY_HEIGHT             14
#define  MMI_VKBD_MATRIX_KEY_H_GAP              1
#define  MMI_VKBD_MATRIX_KEY_V_GAP              1

#define  MATRIX_WIDTH(col)       ((col)*(MMI_VKBD_MATRIX_KEY_WIDTH+MMI_VKBD_MATRIX_KEY_H_GAP) - MMI_VKBD_MATRIX_KEY_H_GAP)
#define  MATRIX_HEIGHT(row)      ((row)*(MMI_VKBD_MATRIX_KEY_HEIGHT+MMI_VKBD_MATRIX_KEY_V_GAP) - MMI_VKBD_MATRIX_KEY_V_GAP)

#define  MATRIX_WIDTH_EXT(col, key_width, h_gap)   ( (col) * ((key_width) + (h_gap)) - (h_gap) )
#define  MATRIX_HEIGHT_EXT(row, key_height, v_gap) ( (row) * ((key_height) + (v_gap)) - (v_gap) )

#define  MMI_VKBD_STANDARD_WIDTH                176
#define  MMI_VKBD_STANDARD_HEIGHT               46
/* matrix layout at the left side */
#define  MMI_VKBD_STANDARD_MATRIX_COLUMN        7
#define  MMI_VKBD_STANDARD_MATRIX_ROW           3
#define  MMI_VKBD_STANDARD_MATRIX_X             1
#define  MMI_VKBD_STANDARD_MATRIX_Y             1
#define  MMI_VKBD_STANDARD_MATRIX_WIDTH         MATRIX_WIDTH(7)
#define  MMI_VKBD_STANDARD_MATRIX_HEIGHT        MATRIX_HEIGHT(3)

#define  MMI_VKBD_EXTENDED_WIDTH                176
#define  MMI_VKBD_EXTENDED_HEIGHT               61
/* matrix layout at the left side */
#define  MMI_VKBD_EXTENDED_MATRIX_COLUMN        8
#define  MMI_VKBD_EXTENDED_MATRIX_ROW           4
#define  MMI_VKBD_EXTENDED_MATRIX_X             1
#define  MMI_VKBD_EXTENDED_MATRIX_Y             1
#define  MMI_VKBD_EXTENDED_MATRIX_WIDTH         MATRIX_WIDTH(8)
#define  MMI_VKBD_EXTENDED_MATRIX_HEIGHT        MATRIX_HEIGHT(4)

#define  MMI_VKBD_TRAY_WIDTH                    176
#define  MMI_VKBD_TRAY_HEIGHT                   16
/* matrix layout at the left side */
#define  MMI_VKBD_TRAY_MATRIX_COLUMN            5
#define  MMI_VKBD_TRAY_MATRIX_ROW               1
#define  MMI_VKBD_TRAY_MATRIX_X                 1
#define  MMI_VKBD_TRAY_MATRIX_Y                 1
#define  MMI_VKBD_TRAY_MATRIX_WIDTH             MATRIX_WIDTH(5)
#define  MMI_VKBD_TRAY_MATRIX_HEIGHT            MATRIX_HEIGHT(1)

#define  MMI_VKBD_NUMBER_WIDTH                  176
#define  MMI_VKBD_NUMBER_HEIGHT                 31
/* matrix layout at the left side */
#define  MMI_VKBD_NUMBER_MATRIX_COLUMN          8
#define  MMI_VKBD_NUMBER_MATRIX_ROW             2
#define  MMI_VKBD_NUMBER_MATRIX_X               1
#define  MMI_VKBD_NUMBER_MATRIX_Y               1
#define  MMI_VKBD_NUMBER_MATRIX_WIDTH           MATRIX_WIDTH(8)
#define  MMI_VKBD_NUMBER_MATRIX_HEIGHT          MATRIX_HEIGHT(2)

#define  MMI_VKBD_PINYIN_WIDTH                  176
#define  MMI_VKBD_PINYIN_HEIGHT                 61
/* matrix layout at the left-bottom */
#define  MMI_VKBD_PINYIN_MATRIX_COLUMN          9
#define  MMI_VKBD_PINYIN_MATRIX_ROW             3
#define  MMI_VKBD_PINYIN_MATRIX_X               1
#define  MMI_VKBD_PINYIN_MATRIX_Y               16
#define  MMI_VKBD_PINYIN_MATRIX_WIDTH           MATRIX_WIDTH(9)
#define  MMI_VKBD_PINYIN_MATRIX_HEIGHT          MATRIX_HEIGHT(3)

#define  MMI_VKBD_BOPOMO_WIDTH                  176
#define  MMI_VKBD_BOPOMO_HEIGHT                 61
/* matrix layout at the left-bottom */
#define  MMI_VKBD_BOPOMO_MATRIX_COLUMN          10
#define  MMI_VKBD_BOPOMO_MATRIX_ROW             3
#define  MMI_VKBD_BOPOMO_MATRIX_X               1
#define  MMI_VKBD_BOPOMO_MATRIX_Y               16
#define  MMI_VKBD_BOPOMO_MATRIX_WIDTH           MATRIX_WIDTH(10)
#define  MMI_VKBD_BOPOMO_MATRIX_HEIGHT          MATRIX_HEIGHT(3)

#define  MMI_VKBD_CZECH_WIDTH                  176
#define  MMI_VKBD_CZECH_HEIGHT                 61
/* matrix layout at the left-bottom */
#define  MMI_VKBD_CZECH_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_CZECH_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_CZECH_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_CZECH_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_CZECH_MATRIX_COLUMN          7
#define  MMI_VKBD_CZECH_MATRIX_ROW             4
#define  MMI_VKBD_CZECH_MATRIX_X               4
#define  MMI_VKBD_CZECH_MATRIX_Y               1
#define  MMI_VKBD_CZECH_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_CZECH_MATRIX_COLUMN, MMI_VKBD_CZECH_MATRIX_KEY_WIDTH, MMI_VKBD_CZECH_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_CZECH_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_CZECH_MATRIX_ROW, MMI_VKBD_CZECH_MATRIX_KEY_HEIGHT, MMI_VKBD_CZECH_MATRIX_KEY_V_GAP)


#define  MMI_VKBD_HEBREW_WIDTH                  176        
#define  MMI_VKBD_HEBREW_HEIGHT                 46
/* matrix layout at the left-bottom */
#define  MMI_VKBD_HEBREW_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_HEBREW_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_HEBREW_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_HEBREW_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_HEBREW_MATRIX_COLUMN          8
#define  MMI_VKBD_HEBREW_MATRIX_ROW             3
#define  MMI_VKBD_HEBREW_MATRIX_X               1
#define  MMI_VKBD_HEBREW_MATRIX_Y               1
#define  MMI_VKBD_HEBREW_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_HEBREW_MATRIX_COLUMN, MMI_VKBD_HEBREW_MATRIX_KEY_WIDTH, MMI_VKBD_HEBREW_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_HEBREW_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_HEBREW_MATRIX_ROW, MMI_VKBD_HEBREW_MATRIX_KEY_HEIGHT, MMI_VKBD_HEBREW_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_FARSI_WIDTH                  176        
#define  MMI_VKBD_FARSI_HEIGHT                 61
/* matrix layout at the left-bottom */
#define  MMI_VKBD_FARSI_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_FARSI_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_FARSI_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_FARSI_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_FARSI_MATRIX_COLUMN          9
#define  MMI_VKBD_FARSI_MATRIX_ROW             4
#define  MMI_VKBD_FARSI_MATRIX_X               4
#define  MMI_VKBD_FARSI_MATRIX_Y               1
#define  MMI_VKBD_FARSI_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_FARSI_MATRIX_COLUMN, MMI_VKBD_FARSI_MATRIX_KEY_WIDTH, MMI_VKBD_FARSI_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_FARSI_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_FARSI_MATRIX_ROW, MMI_VKBD_FARSI_MATRIX_KEY_HEIGHT, MMI_VKBD_FARSI_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_FARSI_SYMBOL_WIDTH                  176        
#define  MMI_VKBD_FARSI_SYMBOL_HEIGHT                 76
/* matrix layout at the left-bottom */
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_COLUMN          9
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_ROW             5
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_X               4
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_Y               1
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_FARSI_SYMBOL_MATRIX_COLUMN, MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_WIDTH, MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_FARSI_SYMBOL_MATRIX_ROW, MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_HEIGHT, MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_GREEK_WIDTH                  176        
#define  MMI_VKBD_GREEK_HEIGHT                 46
/* matrix layout at the left-bottom */
#define  MMI_VKBD_GREEK_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_GREEK_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_GREEK_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_GREEK_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_GREEK_MATRIX_COLUMN          7
#define  MMI_VKBD_GREEK_MATRIX_ROW             3
#define  MMI_VKBD_GREEK_MATRIX_X               1
#define  MMI_VKBD_GREEK_MATRIX_Y               1
#define  MMI_VKBD_GREEK_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_GREEK_MATRIX_COLUMN, MMI_VKBD_GREEK_MATRIX_KEY_WIDTH, MMI_VKBD_GREEK_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_GREEK_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_GREEK_MATRIX_ROW, MMI_VKBD_GREEK_MATRIX_KEY_HEIGHT, MMI_VKBD_GREEK_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_BULGARIAN_WIDTH                  176       
#define  MMI_VKBD_BULGARIAN_HEIGHT                 61
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_BULGARIAN_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_BULGARIAN_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_BULGARIAN_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_BULGARIAN_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_BULGARIAN_MATRIX_COLUMN          7
#define  MMI_VKBD_BULGARIAN_MATRIX_ROW             4
#define  MMI_VKBD_BULGARIAN_MATRIX_X               0
#define  MMI_VKBD_BULGARIAN_MATRIX_Y               1
#define  MMI_VKBD_BULGARIAN_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_BULGARIAN_MATRIX_COLUMN, MMI_VKBD_BULGARIAN_MATRIX_KEY_WIDTH, MMI_VKBD_BULGARIAN_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_BULGARIAN_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_BULGARIAN_MATRIX_ROW, MMI_VKBD_BULGARIAN_MATRIX_KEY_HEIGHT, MMI_VKBD_BULGARIAN_MATRIX_KEY_V_GAP)


#define  MMI_VKBD_DANISH_WIDTH                  176        
#define  MMI_VKBD_DANISH_HEIGHT                 46
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_DANISH_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_DANISH_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_DANISH_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_DANISH_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_DANISH_MATRIX_COLUMN          7
#define  MMI_VKBD_DANISH_MATRIX_ROW             3
#define  MMI_VKBD_DANISH_MATRIX_X               1
#define  MMI_VKBD_DANISH_MATRIX_Y               1
#define  MMI_VKBD_DANISH_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_DANISH_MATRIX_COLUMN, MMI_VKBD_DANISH_MATRIX_KEY_WIDTH, MMI_VKBD_DANISH_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_DANISH_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_DANISH_MATRIX_ROW, MMI_VKBD_DANISH_MATRIX_KEY_HEIGHT, MMI_VKBD_DANISH_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_HUNGARIAN_WIDTH                  176        
#define  MMI_VKBD_HUNGARIAN_HEIGHT                 61
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_HUNGARIAN_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_HUNGARIAN_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_HUNGARIAN_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_HUNGARIAN_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_HUNGARIAN_MATRIX_COLUMN          7
#define  MMI_VKBD_HUNGARIAN_MATRIX_ROW             4
#define  MMI_VKBD_HUNGARIAN_MATRIX_X               4
#define  MMI_VKBD_HUNGARIAN_MATRIX_Y               1
#define  MMI_VKBD_HUNGARIAN_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_HUNGARIAN_MATRIX_COLUMN, MMI_VKBD_HUNGARIAN_MATRIX_KEY_WIDTH, MMI_VKBD_HUNGARIAN_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_HUNGARIAN_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_HUNGARIAN_MATRIX_ROW, MMI_VKBD_HUNGARIAN_MATRIX_KEY_HEIGHT, MMI_VKBD_HUNGARIAN_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_FINNISH_WIDTH                  176        
#define  MMI_VKBD_FINNISH_HEIGHT                 46
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_FINNISH_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_FINNISH_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_FINNISH_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_FINNISH_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_FINNISH_MATRIX_COLUMN          8
#define  MMI_VKBD_FINNISH_MATRIX_ROW             3
#define  MMI_VKBD_FINNISH_MATRIX_X               1
#define  MMI_VKBD_FINNISH_MATRIX_Y               1
#define  MMI_VKBD_FINNISH_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_FINNISH_MATRIX_COLUMN, MMI_VKBD_FINNISH_MATRIX_KEY_WIDTH, MMI_VKBD_FINNISH_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_FINNISH_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_FINNISH_MATRIX_ROW, MMI_VKBD_FINNISH_MATRIX_KEY_HEIGHT, MMI_VKBD_FINNISH_MATRIX_KEY_V_GAP)


#define  MMI_VKBD_POLISH_WIDTH                  176        
#define  MMI_VKBD_POLISH_HEIGHT                 61
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_POLISH_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_POLISH_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_POLISH_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_POLISH_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_POLISH_MATRIX_COLUMN          7
#define  MMI_VKBD_POLISH_MATRIX_ROW             4
#define  MMI_VKBD_POLISH_MATRIX_X               1
#define  MMI_VKBD_POLISH_MATRIX_Y               1
#define  MMI_VKBD_POLISH_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_POLISH_MATRIX_COLUMN, MMI_VKBD_POLISH_MATRIX_KEY_WIDTH, MMI_VKBD_POLISH_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_POLISH_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_POLISH_MATRIX_ROW, MMI_VKBD_POLISH_MATRIX_KEY_HEIGHT, MMI_VKBD_POLISH_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_VIETNAMESE_WIDTH                  176        
#define  MMI_VKBD_VIETNAMESE_HEIGHT                 61
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_VIETNAMESE_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_VIETNAMESE_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_VIETNAMESE_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_VIETNAMESE_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_VIETNAMESE_MATRIX_COLUMN          5   
#define  MMI_VKBD_VIETNAMESE_MATRIX_ROW             4
#define  MMI_VKBD_VIETNAMESE_MATRIX_X               0
#define  MMI_VKBD_VIETNAMESE_MATRIX_Y               1
#define  MMI_VKBD_VIETNAMESE_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_VIETNAMESE_MATRIX_COLUMN, MMI_VKBD_VIETNAMESE_MATRIX_KEY_WIDTH, MMI_VKBD_VIETNAMESE_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_VIETNAMESE_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_VIETNAMESE_MATRIX_ROW, MMI_VKBD_VIETNAMESE_MATRIX_KEY_HEIGHT, MMI_VKBD_VIETNAMESE_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_ARABIC_WIDTH                  176        
#define  MMI_VKBD_ARABIC_HEIGHT                 46
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_ARABIC_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_ARABIC_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_ARABIC_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_ARABIC_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_ARABIC_MATRIX_COLUMN          5   
#define  MMI_VKBD_ARABIC_MATRIX_ROW             3
#define  MMI_VKBD_ARABIC_MATRIX_X               1
#define  MMI_VKBD_ARABIC_MATRIX_Y               1
#define  MMI_VKBD_ARABIC_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_ARABIC_MATRIX_COLUMN, MMI_VKBD_ARABIC_MATRIX_KEY_WIDTH, MMI_VKBD_ARABIC_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_ARABIC_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_ARABIC_MATRIX_ROW, MMI_VKBD_ARABIC_MATRIX_KEY_HEIGHT, MMI_VKBD_ARABIC_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_THAI_WIDTH                  176        
#define  MMI_VKBD_THAI_HEIGHT                 61
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_THAI_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_THAI_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_THAI_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_THAI_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_THAI_MATRIX_COLUMN          10   
#define  MMI_VKBD_THAI_MATRIX_ROW             4
#define  MMI_VKBD_THAI_MATRIX_X               0
#define  MMI_VKBD_THAI_MATRIX_Y               1
#define  MMI_VKBD_THAI_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_THAI_MATRIX_COLUMN, MMI_VKBD_THAI_MATRIX_KEY_WIDTH, MMI_VKBD_THAI_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_THAI_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_THAI_MATRIX_ROW, MMI_VKBD_THAI_MATRIX_KEY_HEIGHT, MMI_VKBD_THAI_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_ARABIC_SYMBOL_WIDTH                  176        
#define  MMI_VKBD_ARABIC_SYMBOL_HEIGHT                 61
/* matrix layout at the left-bottom */
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_COLUMN          5
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_ROW             4
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_X               4
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_Y               1
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_ARABIC_SYMBOL_MATRIX_COLUMN, MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_WIDTH, MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_ARABIC_SYMBOL_MATRIX_ROW, MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_HEIGHT, MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_UKRAINIAN_WIDTH                  176        
#define  MMI_VKBD_UKRAINIAN_HEIGHT                 61
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_UKRAINIAN_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_UKRAINIAN_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_UKRAINIAN_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_UKRAINIAN_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_UKRAINIAN_MATRIX_COLUMN          5   
#define  MMI_VKBD_UKRAINIAN_MATRIX_ROW             4
#define  MMI_VKBD_UKRAINIAN_MATRIX_X               4
#define  MMI_VKBD_UKRAINIAN_MATRIX_Y               1
#define  MMI_VKBD_UKRAINIAN_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_UKRAINIAN_MATRIX_COLUMN, MMI_VKBD_UKRAINIAN_MATRIX_KEY_WIDTH, MMI_VKBD_UKRAINIAN_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_UKRAINIAN_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_UKRAINIAN_MATRIX_ROW, MMI_VKBD_UKRAINIAN_MATRIX_KEY_HEIGHT, MMI_VKBD_UKRAINIAN_MATRIX_KEY_V_GAP)

#elif defined (__MMI_MAINLCD_320X240__)  

#define  MMI_VKBD_MATRIX_KEY_WIDTH              25
#define  MMI_VKBD_MATRIX_KEY_HEIGHT             19
#define  MMI_VKBD_MATRIX_KEY_H_GAP              1
#define  MMI_VKBD_MATRIX_KEY_V_GAP              1

#define  MATRIX_WIDTH(col)       ((col)*(MMI_VKBD_MATRIX_KEY_WIDTH+MMI_VKBD_MATRIX_KEY_H_GAP) - MMI_VKBD_MATRIX_KEY_H_GAP)
#define  MATRIX_HEIGHT(row)      ((row)*(MMI_VKBD_MATRIX_KEY_HEIGHT+MMI_VKBD_MATRIX_KEY_V_GAP) - MMI_VKBD_MATRIX_KEY_V_GAP)

#define  MATRIX_WIDTH_EXT(col, key_width, h_gap)   ( (col) * ((key_width) + (h_gap)) - (h_gap) )
#define  MATRIX_HEIGHT_EXT(row, key_height, v_gap) ( (row) * ((key_height) + (v_gap)) - (v_gap) )


#define  MMI_VKBD_STANDARD_WIDTH                320
#define  MMI_VKBD_STANDARD_HEIGHT               63
/* matrix layout at the left side */
#define  MMI_VKBD_STANDARD_MATRIX_COLUMN        7
#define  MMI_VKBD_STANDARD_MATRIX_ROW           3
#define  MMI_VKBD_STANDARD_MATRIX_X             1
#define  MMI_VKBD_STANDARD_MATRIX_Y             2
#define  MMI_VKBD_STANDARD_MATRIX_WIDTH         MATRIX_WIDTH(7)
#define  MMI_VKBD_STANDARD_MATRIX_HEIGHT        MATRIX_HEIGHT(3)

#define  MMI_VKBD_EXTENDED_WIDTH                320
#define  MMI_VKBD_EXTENDED_HEIGHT               83
/* matrix layout at the left side */
#define  MMI_VKBD_EXTENDED_MATRIX_COLUMN        8
#define  MMI_VKBD_EXTENDED_MATRIX_ROW           4
#define  MMI_VKBD_EXTENDED_MATRIX_X             1
#define  MMI_VKBD_EXTENDED_MATRIX_Y             2
#define  MMI_VKBD_EXTENDED_MATRIX_WIDTH         MATRIX_WIDTH(8)
#define  MMI_VKBD_EXTENDED_MATRIX_HEIGHT        MATRIX_HEIGHT(4)

#define  MMI_VKBD_TRAY_WIDTH                    320
#define  MMI_VKBD_TRAY_HEIGHT                   23
/* matrix layout at the left side */
#define  MMI_VKBD_TRAY_MATRIX_COLUMN            5
#define  MMI_VKBD_TRAY_MATRIX_ROW               1
#define  MMI_VKBD_TRAY_MATRIX_X                 1
#define  MMI_VKBD_TRAY_MATRIX_Y                 2
#define  MMI_VKBD_TRAY_MATRIX_WIDTH             MATRIX_WIDTH(5)
#define  MMI_VKBD_TRAY_MATRIX_HEIGHT            MATRIX_HEIGHT(1)

#define  MMI_VKBD_NUMBER_WIDTH                  320
#define  MMI_VKBD_NUMBER_HEIGHT                 43
/* matrix layout at the left side */
#define  MMI_VKBD_NUMBER_MATRIX_COLUMN          8
#define  MMI_VKBD_NUMBER_MATRIX_ROW             2
#define  MMI_VKBD_NUMBER_MATRIX_X               1
#define  MMI_VKBD_NUMBER_MATRIX_Y               2
#define  MMI_VKBD_NUMBER_MATRIX_WIDTH           MATRIX_WIDTH(8)
#define  MMI_VKBD_NUMBER_MATRIX_HEIGHT          MATRIX_HEIGHT(2)

#define  MMI_VKBD_PINYIN_WIDTH                  320
#define  MMI_VKBD_PINYIN_HEIGHT                 83
/* matrix layout at the left-bottom */
#define  MMI_VKBD_PINYIN_MATRIX_COLUMN          9
#define  MMI_VKBD_PINYIN_MATRIX_ROW             3
#define  MMI_VKBD_PINYIN_MATRIX_X               1
#define  MMI_VKBD_PINYIN_MATRIX_Y               22
#define  MMI_VKBD_PINYIN_MATRIX_WIDTH           MATRIX_WIDTH(9)
#define  MMI_VKBD_PINYIN_MATRIX_HEIGHT          MATRIX_HEIGHT(3)

#define  MMI_VKBD_BOPOMO_WIDTH                  320
#define  MMI_VKBD_BOPOMO_HEIGHT                 83
/* matrix layout at the left-bottom */
#define  MMI_VKBD_BOPOMO_MATRIX_COLUMN          10
#define  MMI_VKBD_BOPOMO_MATRIX_ROW             3
#define  MMI_VKBD_BOPOMO_MATRIX_X               1
#define  MMI_VKBD_BOPOMO_MATRIX_Y               22
#define  MMI_VKBD_BOPOMO_MATRIX_WIDTH           MATRIX_WIDTH(10)
#define  MMI_VKBD_BOPOMO_MATRIX_HEIGHT          MATRIX_HEIGHT(3)

#define  MMI_VKBD_CZECH_WIDTH                  320
#define  MMI_VKBD_CZECH_HEIGHT                 83
/* matrix layout at the left-bottom */
#define  MMI_VKBD_CZECH_MATRIX_KEY_WIDTH       25
#define  MMI_VKBD_CZECH_MATRIX_KEY_HEIGHT      19
#define  MMI_VKBD_CZECH_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_CZECH_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_CZECH_MATRIX_COLUMN          7
#define  MMI_VKBD_CZECH_MATRIX_ROW             4
#define  MMI_VKBD_CZECH_MATRIX_X               1
#define  MMI_VKBD_CZECH_MATRIX_Y               2
#define  MMI_VKBD_CZECH_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_CZECH_MATRIX_COLUMN, MMI_VKBD_CZECH_MATRIX_KEY_WIDTH, MMI_VKBD_CZECH_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_CZECH_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_CZECH_MATRIX_ROW, MMI_VKBD_CZECH_MATRIX_KEY_HEIGHT, MMI_VKBD_CZECH_MATRIX_KEY_V_GAP)


#define  MMI_VKBD_HEBREW_WIDTH                  176        
#define  MMI_VKBD_HEBREW_HEIGHT                 46
/* matrix layout at the left-bottom */
#define  MMI_VKBD_HEBREW_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_HEBREW_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_HEBREW_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_HEBREW_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_HEBREW_MATRIX_COLUMN          8
#define  MMI_VKBD_HEBREW_MATRIX_ROW             3
#define  MMI_VKBD_HEBREW_MATRIX_X               1
#define  MMI_VKBD_HEBREW_MATRIX_Y               1
#define  MMI_VKBD_HEBREW_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_HEBREW_MATRIX_COLUMN, MMI_VKBD_HEBREW_MATRIX_KEY_WIDTH, MMI_VKBD_HEBREW_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_HEBREW_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_HEBREW_MATRIX_ROW, MMI_VKBD_HEBREW_MATRIX_KEY_HEIGHT, MMI_VKBD_HEBREW_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_FARSI_WIDTH                  320        
#define  MMI_VKBD_FARSI_HEIGHT                 82
/* matrix layout at the left-bottom */
#define  MMI_VKBD_FARSI_MATRIX_KEY_WIDTH       25
#define  MMI_VKBD_FARSI_MATRIX_KEY_HEIGHT      19
#define  MMI_VKBD_FARSI_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_FARSI_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_FARSI_MATRIX_COLUMN          9
#define  MMI_VKBD_FARSI_MATRIX_ROW             4
#define  MMI_VKBD_FARSI_MATRIX_X               1
#define  MMI_VKBD_FARSI_MATRIX_Y               2
#define  MMI_VKBD_FARSI_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_FARSI_MATRIX_COLUMN, MMI_VKBD_FARSI_MATRIX_KEY_WIDTH, MMI_VKBD_FARSI_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_FARSI_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_FARSI_MATRIX_ROW, MMI_VKBD_FARSI_MATRIX_KEY_HEIGHT, MMI_VKBD_FARSI_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_FARSI_SYMBOL_WIDTH                  176        
#define  MMI_VKBD_FARSI_SYMBOL_HEIGHT                 76
/* matrix layout at the left-bottom */
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_COLUMN          9
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_ROW             5
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_X               4
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_Y               1
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_FARSI_SYMBOL_MATRIX_COLUMN, MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_WIDTH, MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_FARSI_SYMBOL_MATRIX_ROW, MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_HEIGHT, MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_GREEK_WIDTH                  176        
#define  MMI_VKBD_GREEK_HEIGHT                 46
/* matrix layout at the left-bottom */
#define  MMI_VKBD_GREEK_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_GREEK_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_GREEK_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_GREEK_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_GREEK_MATRIX_COLUMN          7
#define  MMI_VKBD_GREEK_MATRIX_ROW             3
#define  MMI_VKBD_GREEK_MATRIX_X               1
#define  MMI_VKBD_GREEK_MATRIX_Y               1
#define  MMI_VKBD_GREEK_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_GREEK_MATRIX_COLUMN, MMI_VKBD_GREEK_MATRIX_KEY_WIDTH, MMI_VKBD_GREEK_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_GREEK_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_GREEK_MATRIX_ROW, MMI_VKBD_GREEK_MATRIX_KEY_HEIGHT, MMI_VKBD_GREEK_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_BULGARIAN_WIDTH                  320       
#define  MMI_VKBD_BULGARIAN_HEIGHT                 83
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_BULGARIAN_MATRIX_KEY_WIDTH       25
#define  MMI_VKBD_BULGARIAN_MATRIX_KEY_HEIGHT      19
#define  MMI_VKBD_BULGARIAN_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_BULGARIAN_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_BULGARIAN_MATRIX_COLUMN          7
#define  MMI_VKBD_BULGARIAN_MATRIX_ROW             4
#define  MMI_VKBD_BULGARIAN_MATRIX_X               1
#define  MMI_VKBD_BULGARIAN_MATRIX_Y               2
#define  MMI_VKBD_BULGARIAN_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_BULGARIAN_MATRIX_COLUMN, MMI_VKBD_BULGARIAN_MATRIX_KEY_WIDTH, MMI_VKBD_BULGARIAN_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_BULGARIAN_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_BULGARIAN_MATRIX_ROW, MMI_VKBD_BULGARIAN_MATRIX_KEY_HEIGHT, MMI_VKBD_BULGARIAN_MATRIX_KEY_V_GAP)


#define  MMI_VKBD_DANISH_WIDTH                  176        
#define  MMI_VKBD_DANISH_HEIGHT                 46
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_DANISH_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_DANISH_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_DANISH_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_DANISH_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_DANISH_MATRIX_COLUMN          7
#define  MMI_VKBD_DANISH_MATRIX_ROW             3
#define  MMI_VKBD_DANISH_MATRIX_X               1
#define  MMI_VKBD_DANISH_MATRIX_Y               1
#define  MMI_VKBD_DANISH_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_DANISH_MATRIX_COLUMN, MMI_VKBD_DANISH_MATRIX_KEY_WIDTH, MMI_VKBD_DANISH_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_DANISH_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_DANISH_MATRIX_ROW, MMI_VKBD_DANISH_MATRIX_KEY_HEIGHT, MMI_VKBD_DANISH_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_HUNGARIAN_WIDTH                  320        
#define  MMI_VKBD_HUNGARIAN_HEIGHT                 82
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_HUNGARIAN_MATRIX_KEY_WIDTH       25
#define  MMI_VKBD_HUNGARIAN_MATRIX_KEY_HEIGHT      19
#define  MMI_VKBD_HUNGARIAN_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_HUNGARIAN_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_HUNGARIAN_MATRIX_COLUMN          7
#define  MMI_VKBD_HUNGARIAN_MATRIX_ROW             4
#define  MMI_VKBD_HUNGARIAN_MATRIX_X               1
#define  MMI_VKBD_HUNGARIAN_MATRIX_Y               2
#define  MMI_VKBD_HUNGARIAN_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_HUNGARIAN_MATRIX_COLUMN, MMI_VKBD_HUNGARIAN_MATRIX_KEY_WIDTH, MMI_VKBD_HUNGARIAN_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_HUNGARIAN_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_HUNGARIAN_MATRIX_ROW, MMI_VKBD_HUNGARIAN_MATRIX_KEY_HEIGHT, MMI_VKBD_HUNGARIAN_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_FINNISH_WIDTH                  176        
#define  MMI_VKBD_FINNISH_HEIGHT                 46
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_FINNISH_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_FINNISH_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_FINNISH_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_FINNISH_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_FINNISH_MATRIX_COLUMN          8
#define  MMI_VKBD_FINNISH_MATRIX_ROW             3
#define  MMI_VKBD_FINNISH_MATRIX_X               1
#define  MMI_VKBD_FINNISH_MATRIX_Y               1
#define  MMI_VKBD_FINNISH_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_FINNISH_MATRIX_COLUMN, MMI_VKBD_FINNISH_MATRIX_KEY_WIDTH, MMI_VKBD_FINNISH_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_FINNISH_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_FINNISH_MATRIX_ROW, MMI_VKBD_FINNISH_MATRIX_KEY_HEIGHT, MMI_VKBD_FINNISH_MATRIX_KEY_V_GAP)


#define  MMI_VKBD_POLISH_WIDTH                  176        
#define  MMI_VKBD_POLISH_HEIGHT                 61
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_POLISH_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_POLISH_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_POLISH_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_POLISH_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_POLISH_MATRIX_COLUMN          7
#define  MMI_VKBD_POLISH_MATRIX_ROW             4
#define  MMI_VKBD_POLISH_MATRIX_X               1
#define  MMI_VKBD_POLISH_MATRIX_Y               1
#define  MMI_VKBD_POLISH_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_POLISH_MATRIX_COLUMN, MMI_VKBD_POLISH_MATRIX_KEY_WIDTH, MMI_VKBD_POLISH_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_POLISH_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_POLISH_MATRIX_ROW, MMI_VKBD_POLISH_MATRIX_KEY_HEIGHT, MMI_VKBD_POLISH_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_VIETNAMESE_WIDTH                  176        
#define  MMI_VKBD_VIETNAMESE_HEIGHT                 61
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_VIETNAMESE_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_VIETNAMESE_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_VIETNAMESE_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_VIETNAMESE_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_VIETNAMESE_MATRIX_COLUMN          5   
#define  MMI_VKBD_VIETNAMESE_MATRIX_ROW             4
#define  MMI_VKBD_VIETNAMESE_MATRIX_X               0
#define  MMI_VKBD_VIETNAMESE_MATRIX_Y               1
#define  MMI_VKBD_VIETNAMESE_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_VIETNAMESE_MATRIX_COLUMN, MMI_VKBD_VIETNAMESE_MATRIX_KEY_WIDTH, MMI_VKBD_VIETNAMESE_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_VIETNAMESE_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_VIETNAMESE_MATRIX_ROW, MMI_VKBD_VIETNAMESE_MATRIX_KEY_HEIGHT, MMI_VKBD_VIETNAMESE_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_ARABIC_WIDTH                  320        
#define  MMI_VKBD_ARABIC_HEIGHT                 63
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_ARABIC_MATRIX_KEY_WIDTH       25
#define  MMI_VKBD_ARABIC_MATRIX_KEY_HEIGHT      19
#define  MMI_VKBD_ARABIC_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_ARABIC_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_ARABIC_MATRIX_COLUMN          5   
#define  MMI_VKBD_ARABIC_MATRIX_ROW             3
#define  MMI_VKBD_ARABIC_MATRIX_X               1
#define  MMI_VKBD_ARABIC_MATRIX_Y               2
#define  MMI_VKBD_ARABIC_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_ARABIC_MATRIX_COLUMN, MMI_VKBD_ARABIC_MATRIX_KEY_WIDTH, MMI_VKBD_ARABIC_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_ARABIC_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_ARABIC_MATRIX_ROW, MMI_VKBD_ARABIC_MATRIX_KEY_HEIGHT, MMI_VKBD_ARABIC_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_THAI_WIDTH                  176        
#define  MMI_VKBD_THAI_HEIGHT                 61
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_THAI_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_THAI_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_THAI_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_THAI_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_THAI_MATRIX_COLUMN          10   
#define  MMI_VKBD_THAI_MATRIX_ROW             4
#define  MMI_VKBD_THAI_MATRIX_X               0
#define  MMI_VKBD_THAI_MATRIX_Y               1
#define  MMI_VKBD_THAI_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_THAI_MATRIX_COLUMN, MMI_VKBD_THAI_MATRIX_KEY_WIDTH, MMI_VKBD_THAI_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_THAI_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_THAI_MATRIX_ROW, MMI_VKBD_THAI_MATRIX_KEY_HEIGHT, MMI_VKBD_THAI_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_ARABIC_SYMBOL_WIDTH                  320        
#define  MMI_VKBD_ARABIC_SYMBOL_HEIGHT                 82
/* matrix layout at the left-bottom */
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_WIDTH       25
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_HEIGHT      19
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_COLUMN          5
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_ROW             4
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_X               1
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_Y               2
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_ARABIC_SYMBOL_MATRIX_COLUMN, MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_WIDTH, MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_ARABIC_SYMBOL_MATRIX_ROW, MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_HEIGHT, MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_UKRAINIAN_WIDTH                  176        
#define  MMI_VKBD_UKRAINIAN_HEIGHT                 61
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_UKRAINIAN_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_UKRAINIAN_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_UKRAINIAN_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_UKRAINIAN_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_UKRAINIAN_MATRIX_COLUMN          5   
#define  MMI_VKBD_UKRAINIAN_MATRIX_ROW             4
#define  MMI_VKBD_UKRAINIAN_MATRIX_X               4
#define  MMI_VKBD_UKRAINIAN_MATRIX_Y               1
#define  MMI_VKBD_UKRAINIAN_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_UKRAINIAN_MATRIX_COLUMN, MMI_VKBD_UKRAINIAN_MATRIX_KEY_WIDTH, MMI_VKBD_UKRAINIAN_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_UKRAINIAN_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_UKRAINIAN_MATRIX_ROW, MMI_VKBD_UKRAINIAN_MATRIX_KEY_HEIGHT, MMI_VKBD_UKRAINIAN_MATRIX_KEY_V_GAP)

#else /* (__MMI_MAINLCD_128X160__) */

#define  MMI_VKBD_MATRIX_KEY_WIDTH              10
#define  MMI_VKBD_MATRIX_KEY_HEIGHT             10
#define  MMI_VKBD_MATRIX_KEY_H_GAP              1
#define  MMI_VKBD_MATRIX_KEY_V_GAP              1

#define  MATRIX_WIDTH(col)       ((col)*(MMI_VKBD_MATRIX_KEY_WIDTH+MMI_VKBD_MATRIX_KEY_H_GAP) - MMI_VKBD_MATRIX_KEY_H_GAP)
#define  MATRIX_HEIGHT(row)      ((row)*(MMI_VKBD_MATRIX_KEY_HEIGHT+MMI_VKBD_MATRIX_KEY_V_GAP) - MMI_VKBD_MATRIX_KEY_V_GAP)

#define  MATRIX_WIDTH_EXT(col, key_width, h_gap)   ( (col) * ((key_width) + (h_gap)) - (h_gap) )
#define  MATRIX_HEIGHT_EXT(row, key_height, v_gap) ( (row) * ((key_height) + (v_gap)) - (v_gap) )

#define  MMI_VKBD_STANDARD_WIDTH                128
#define  MMI_VKBD_STANDARD_HEIGHT               34
/* matrix layout at the left side */
#define  MMI_VKBD_STANDARD_MATRIX_COLUMN        7
#define  MMI_VKBD_STANDARD_MATRIX_ROW           3
#define  MMI_VKBD_STANDARD_MATRIX_X             1
#define  MMI_VKBD_STANDARD_MATRIX_Y             1
#define  MMI_VKBD_STANDARD_MATRIX_WIDTH         MATRIX_WIDTH(7)
#define  MMI_VKBD_STANDARD_MATRIX_HEIGHT        MATRIX_HEIGHT(3)

#define  MMI_VKBD_EXTENDED_WIDTH                128
#define  MMI_VKBD_EXTENDED_HEIGHT               45
/* matrix layout at the left side */
#define  MMI_VKBD_EXTENDED_MATRIX_COLUMN        8
#define  MMI_VKBD_EXTENDED_MATRIX_ROW           4
#define  MMI_VKBD_EXTENDED_MATRIX_X             1
#define  MMI_VKBD_EXTENDED_MATRIX_Y             1
#define  MMI_VKBD_EXTENDED_MATRIX_WIDTH         MATRIX_WIDTH(8)
#define  MMI_VKBD_EXTENDED_MATRIX_HEIGHT        MATRIX_HEIGHT(4)

#define  MMI_VKBD_TRAY_WIDTH                    128
#define  MMI_VKBD_TRAY_HEIGHT                   12
/* matrix layout at the left side */
#define  MMI_VKBD_TRAY_MATRIX_COLUMN            5
#define  MMI_VKBD_TRAY_MATRIX_ROW               1
#define  MMI_VKBD_TRAY_MATRIX_X                 1
#define  MMI_VKBD_TRAY_MATRIX_Y                 1
#define  MMI_VKBD_TRAY_MATRIX_WIDTH             MATRIX_WIDTH(5)
#define  MMI_VKBD_TRAY_MATRIX_HEIGHT            MATRIX_HEIGHT(1)

#define  MMI_VKBD_NUMBER_WIDTH                  128
#define  MMI_VKBD_NUMBER_HEIGHT                 23
/* matrix layout at the left side */
#define  MMI_VKBD_NUMBER_MATRIX_COLUMN          8
#define  MMI_VKBD_NUMBER_MATRIX_ROW             2
#define  MMI_VKBD_NUMBER_MATRIX_X               1
#define  MMI_VKBD_NUMBER_MATRIX_Y               1
#define  MMI_VKBD_NUMBER_MATRIX_WIDTH           MATRIX_WIDTH(8)
#define  MMI_VKBD_NUMBER_MATRIX_HEIGHT          MATRIX_HEIGHT(2)

#define  MMI_VKBD_PINYIN_WIDTH                  128
#define  MMI_VKBD_PINYIN_HEIGHT                 45
/* matrix layout at the left-bottom */
#define  MMI_VKBD_PINYIN_MATRIX_COLUMN          9
#define  MMI_VKBD_PINYIN_MATRIX_ROW             3
#define  MMI_VKBD_PINYIN_MATRIX_X               1
#define  MMI_VKBD_PINYIN_MATRIX_Y               12
#define  MMI_VKBD_PINYIN_MATRIX_WIDTH           MATRIX_WIDTH(9)
#define  MMI_VKBD_PINYIN_MATRIX_HEIGHT          MATRIX_HEIGHT(3)

#define  MMI_VKBD_BOPOMO_WIDTH                  128
#define  MMI_VKBD_BOPOMO_HEIGHT                 45
/* matrix layout at the left-bottom */
#define  MMI_VKBD_BOPOMO_MATRIX_COLUMN          10
#define  MMI_VKBD_BOPOMO_MATRIX_ROW             3
#define  MMI_VKBD_BOPOMO_MATRIX_X               1
#define  MMI_VKBD_BOPOMO_MATRIX_Y               12
#define  MMI_VKBD_BOPOMO_MATRIX_WIDTH           MATRIX_WIDTH(10)
#define  MMI_VKBD_BOPOMO_MATRIX_HEIGHT          MATRIX_HEIGHT(3)

#define  MMI_VKBD_CZECH_WIDTH                  128
#define  MMI_VKBD_CZECH_HEIGHT                 45
/* matrix layout at the left-bottom */
#define  MMI_VKBD_CZECH_MATRIX_KEY_WIDTH       9
#define  MMI_VKBD_CZECH_MATRIX_KEY_HEIGHT      10
#define  MMI_VKBD_CZECH_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_CZECH_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_CZECH_MATRIX_COLUMN          7
#define  MMI_VKBD_CZECH_MATRIX_ROW             4
#define  MMI_VKBD_CZECH_MATRIX_X               1
#define  MMI_VKBD_CZECH_MATRIX_Y               1
#define  MMI_VKBD_CZECH_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_CZECH_MATRIX_COLUMN, MMI_VKBD_CZECH_MATRIX_KEY_WIDTH, MMI_VKBD_CZECH_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_CZECH_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_CZECH_MATRIX_ROW, MMI_VKBD_CZECH_MATRIX_KEY_HEIGHT, MMI_VKBD_CZECH_MATRIX_KEY_V_GAP)


#define  MMI_VKBD_HEBREW_WIDTH                  128        
#define  MMI_VKBD_HEBREW_HEIGHT                 34
/* matrix layout at the left-bottom */
#define  MMI_VKBD_HEBREW_MATRIX_KEY_WIDTH       9
#define  MMI_VKBD_HEBREW_MATRIX_KEY_HEIGHT      10
#define  MMI_VKBD_HEBREW_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_HEBREW_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_HEBREW_MATRIX_COLUMN          8
#define  MMI_VKBD_HEBREW_MATRIX_ROW             3
#define  MMI_VKBD_HEBREW_MATRIX_X               1
#define  MMI_VKBD_HEBREW_MATRIX_Y               1
#define  MMI_VKBD_HEBREW_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_HEBREW_MATRIX_COLUMN, MMI_VKBD_HEBREW_MATRIX_KEY_WIDTH, MMI_VKBD_HEBREW_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_HEBREW_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_HEBREW_MATRIX_ROW, MMI_VKBD_HEBREW_MATRIX_KEY_HEIGHT, MMI_VKBD_HEBREW_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_GREEK_WIDTH                  128        
#define  MMI_VKBD_GREEK_HEIGHT                 34
/* matrix layout at the left-bottom */
#define  MMI_VKBD_GREEK_MATRIX_KEY_WIDTH       9
#define  MMI_VKBD_GREEK_MATRIX_KEY_HEIGHT      10
#define  MMI_VKBD_GREEK_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_GREEK_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_GREEK_MATRIX_COLUMN          7
#define  MMI_VKBD_GREEK_MATRIX_ROW             3
#define  MMI_VKBD_GREEK_MATRIX_X               1
#define  MMI_VKBD_GREEK_MATRIX_Y               1
#define  MMI_VKBD_GREEK_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_GREEK_MATRIX_COLUMN, MMI_VKBD_GREEK_MATRIX_KEY_WIDTH, MMI_VKBD_GREEK_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_GREEK_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_GREEK_MATRIX_ROW, MMI_VKBD_GREEK_MATRIX_KEY_HEIGHT, MMI_VKBD_GREEK_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_BULGARIAN_WIDTH                  128       
#define  MMI_VKBD_BULGARIAN_HEIGHT                 45
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_BULGARIAN_MATRIX_KEY_WIDTH       9
#define  MMI_VKBD_BULGARIAN_MATRIX_KEY_HEIGHT      10
#define  MMI_VKBD_BULGARIAN_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_BULGARIAN_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_BULGARIAN_MATRIX_COLUMN          7
#define  MMI_VKBD_BULGARIAN_MATRIX_ROW             4
#define  MMI_VKBD_BULGARIAN_MATRIX_X               1
#define  MMI_VKBD_BULGARIAN_MATRIX_Y               1
#define  MMI_VKBD_BULGARIAN_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_BULGARIAN_MATRIX_COLUMN, MMI_VKBD_BULGARIAN_MATRIX_KEY_WIDTH, MMI_VKBD_BULGARIAN_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_BULGARIAN_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_BULGARIAN_MATRIX_ROW, MMI_VKBD_BULGARIAN_MATRIX_KEY_HEIGHT, MMI_VKBD_BULGARIAN_MATRIX_KEY_V_GAP)


#define  MMI_VKBD_DANISH_WIDTH                  128        
#define  MMI_VKBD_DANISH_HEIGHT                 34
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_DANISH_MATRIX_KEY_WIDTH       9
#define  MMI_VKBD_DANISH_MATRIX_KEY_HEIGHT      10
#define  MMI_VKBD_DANISH_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_DANISH_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_DANISH_MATRIX_COLUMN          7
#define  MMI_VKBD_DANISH_MATRIX_ROW             3
#define  MMI_VKBD_DANISH_MATRIX_X               1
#define  MMI_VKBD_DANISH_MATRIX_Y               1
#define  MMI_VKBD_DANISH_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_DANISH_MATRIX_COLUMN, MMI_VKBD_DANISH_MATRIX_KEY_WIDTH, MMI_VKBD_DANISH_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_DANISH_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_DANISH_MATRIX_ROW, MMI_VKBD_DANISH_MATRIX_KEY_HEIGHT, MMI_VKBD_DANISH_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_HUNGARIAN_WIDTH                  128        
#define  MMI_VKBD_HUNGARIAN_HEIGHT                 45
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_HUNGARIAN_MATRIX_KEY_WIDTH       9
#define  MMI_VKBD_HUNGARIAN_MATRIX_KEY_HEIGHT      10
#define  MMI_VKBD_HUNGARIAN_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_HUNGARIAN_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_HUNGARIAN_MATRIX_COLUMN          7
#define  MMI_VKBD_HUNGARIAN_MATRIX_ROW             4
#define  MMI_VKBD_HUNGARIAN_MATRIX_X               1
#define  MMI_VKBD_HUNGARIAN_MATRIX_Y               1
#define  MMI_VKBD_HUNGARIAN_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_HUNGARIAN_MATRIX_COLUMN, MMI_VKBD_HUNGARIAN_MATRIX_KEY_WIDTH, MMI_VKBD_HUNGARIAN_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_HUNGARIAN_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_HUNGARIAN_MATRIX_ROW, MMI_VKBD_HUNGARIAN_MATRIX_KEY_HEIGHT, MMI_VKBD_HUNGARIAN_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_FINNISH_WIDTH                  128        
#define  MMI_VKBD_FINNISH_HEIGHT                 34
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_FINNISH_MATRIX_KEY_WIDTH       9
#define  MMI_VKBD_FINNISH_MATRIX_KEY_HEIGHT      10
#define  MMI_VKBD_FINNISH_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_FINNISH_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_FINNISH_MATRIX_COLUMN          8
#define  MMI_VKBD_FINNISH_MATRIX_ROW             3
#define  MMI_VKBD_FINNISH_MATRIX_X               1
#define  MMI_VKBD_FINNISH_MATRIX_Y               1
#define  MMI_VKBD_FINNISH_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_FINNISH_MATRIX_COLUMN, MMI_VKBD_FINNISH_MATRIX_KEY_WIDTH, MMI_VKBD_FINNISH_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_FINNISH_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_FINNISH_MATRIX_ROW, MMI_VKBD_FINNISH_MATRIX_KEY_HEIGHT, MMI_VKBD_FINNISH_MATRIX_KEY_V_GAP)


#define  MMI_VKBD_POLISH_WIDTH                  128        
#define  MMI_VKBD_POLISH_HEIGHT                 45
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_POLISH_MATRIX_KEY_WIDTH       10
#define  MMI_VKBD_POLISH_MATRIX_KEY_HEIGHT      10
#define  MMI_VKBD_POLISH_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_POLISH_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_POLISH_MATRIX_COLUMN          7
#define  MMI_VKBD_POLISH_MATRIX_ROW             4
#define  MMI_VKBD_POLISH_MATRIX_X               1
#define  MMI_VKBD_POLISH_MATRIX_Y               1
#define  MMI_VKBD_POLISH_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_POLISH_MATRIX_COLUMN, MMI_VKBD_POLISH_MATRIX_KEY_WIDTH, MMI_VKBD_POLISH_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_POLISH_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_POLISH_MATRIX_ROW, MMI_VKBD_POLISH_MATRIX_KEY_HEIGHT, MMI_VKBD_POLISH_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_FARSI_WIDTH                  128        
#define  MMI_VKBD_FARSI_HEIGHT                 45
/* matrix layout at the left-bottom */
#define  MMI_VKBD_FARSI_MATRIX_KEY_WIDTH       9
#define  MMI_VKBD_FARSI_MATRIX_KEY_HEIGHT      10
#define  MMI_VKBD_FARSI_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_FARSI_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_FARSI_MATRIX_COLUMN          9
#define  MMI_VKBD_FARSI_MATRIX_ROW             4
#define  MMI_VKBD_FARSI_MATRIX_X               1
#define  MMI_VKBD_FARSI_MATRIX_Y               1
#define  MMI_VKBD_FARSI_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_FARSI_MATRIX_COLUMN, MMI_VKBD_FARSI_MATRIX_KEY_WIDTH, MMI_VKBD_FARSI_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_FARSI_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_FARSI_MATRIX_ROW, MMI_VKBD_FARSI_MATRIX_KEY_HEIGHT, MMI_VKBD_FARSI_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_FARSI_SYMBOL_WIDTH                  128        
#define  MMI_VKBD_FARSI_SYMBOL_HEIGHT                 76
/* matrix layout at the left-bottom */
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_WIDTH       14
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_HEIGHT      14
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_H_GAP       0
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_COLUMN          9
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_ROW             5
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_X               4
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_Y               1
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_FARSI_SYMBOL_MATRIX_COLUMN, MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_WIDTH, MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_FARSI_SYMBOL_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_FARSI_SYMBOL_MATRIX_ROW, MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_HEIGHT, MMI_VKBD_FARSI_SYMBOL_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_VIETNAMESE_WIDTH                  128        
#define  MMI_VKBD_VIETNAMESE_HEIGHT                 45
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_VIETNAMESE_MATRIX_KEY_WIDTH       10
#define  MMI_VKBD_VIETNAMESE_MATRIX_KEY_HEIGHT      10
#define  MMI_VKBD_VIETNAMESE_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_VIETNAMESE_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_VIETNAMESE_MATRIX_COLUMN          5   
#define  MMI_VKBD_VIETNAMESE_MATRIX_ROW             4
#define  MMI_VKBD_VIETNAMESE_MATRIX_X               1
#define  MMI_VKBD_VIETNAMESE_MATRIX_Y               1
#define  MMI_VKBD_VIETNAMESE_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_VIETNAMESE_MATRIX_COLUMN, MMI_VKBD_VIETNAMESE_MATRIX_KEY_WIDTH, MMI_VKBD_VIETNAMESE_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_VIETNAMESE_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_VIETNAMESE_MATRIX_ROW, MMI_VKBD_VIETNAMESE_MATRIX_KEY_HEIGHT, MMI_VKBD_VIETNAMESE_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_ARABIC_WIDTH                  128        
#define  MMI_VKBD_ARABIC_HEIGHT                 34
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_ARABIC_MATRIX_KEY_WIDTH       10
#define  MMI_VKBD_ARABIC_MATRIX_KEY_HEIGHT      10
#define  MMI_VKBD_ARABIC_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_ARABIC_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_ARABIC_MATRIX_COLUMN          5   
#define  MMI_VKBD_ARABIC_MATRIX_ROW             3
#define  MMI_VKBD_ARABIC_MATRIX_X               1
#define  MMI_VKBD_ARABIC_MATRIX_Y               1
#define  MMI_VKBD_ARABIC_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_ARABIC_MATRIX_COLUMN, MMI_VKBD_ARABIC_MATRIX_KEY_WIDTH, MMI_VKBD_ARABIC_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_ARABIC_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_ARABIC_MATRIX_ROW, MMI_VKBD_ARABIC_MATRIX_KEY_HEIGHT, MMI_VKBD_ARABIC_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_THAI_WIDTH                  128        
#define  MMI_VKBD_THAI_HEIGHT                 45
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_THAI_MATRIX_KEY_WIDTH       9
#define  MMI_VKBD_THAI_MATRIX_KEY_HEIGHT      10
#define  MMI_VKBD_THAI_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_THAI_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_THAI_MATRIX_COLUMN          10   
#define  MMI_VKBD_THAI_MATRIX_ROW             4
#define  MMI_VKBD_THAI_MATRIX_X               1
#define  MMI_VKBD_THAI_MATRIX_Y               1
#define  MMI_VKBD_THAI_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_THAI_MATRIX_COLUMN, MMI_VKBD_THAI_MATRIX_KEY_WIDTH, MMI_VKBD_THAI_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_THAI_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_THAI_MATRIX_ROW, MMI_VKBD_THAI_MATRIX_KEY_HEIGHT, MMI_VKBD_THAI_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_ARABIC_SYMBOL_WIDTH                  128        
#define  MMI_VKBD_ARABIC_SYMBOL_HEIGHT                 45
/* matrix layout at the left-bottom */
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_WIDTH       9
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_HEIGHT      10
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_COLUMN          5
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_ROW             4
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_X               1
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_Y               1
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_ARABIC_SYMBOL_MATRIX_COLUMN, MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_WIDTH, MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_ARABIC_SYMBOL_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_ARABIC_SYMBOL_MATRIX_ROW, MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_HEIGHT, MMI_VKBD_ARABIC_SYMBOL_MATRIX_KEY_V_GAP)

#define  MMI_VKBD_UKRAINIAN_WIDTH                  128        
#define  MMI_VKBD_UKRAINIAN_HEIGHT                 45
    /* matrix layout at the left-bottom */
#define  MMI_VKBD_UKRAINIAN_MATRIX_KEY_WIDTH       10
#define  MMI_VKBD_UKRAINIAN_MATRIX_KEY_HEIGHT      10
#define  MMI_VKBD_UKRAINIAN_MATRIX_KEY_H_GAP       1
#define  MMI_VKBD_UKRAINIAN_MATRIX_KEY_V_GAP       1
#define  MMI_VKBD_UKRAINIAN_MATRIX_COLUMN          5   
#define  MMI_VKBD_UKRAINIAN_MATRIX_ROW             4
#define  MMI_VKBD_UKRAINIAN_MATRIX_X               1
#define  MMI_VKBD_UKRAINIAN_MATRIX_Y               1
#define  MMI_VKBD_UKRAINIAN_MATRIX_WIDTH           MATRIX_WIDTH_EXT(MMI_VKBD_UKRAINIAN_MATRIX_COLUMN, MMI_VKBD_UKRAINIAN_MATRIX_KEY_WIDTH, MMI_VKBD_UKRAINIAN_MATRIX_KEY_H_GAP)
#define  MMI_VKBD_UKRAINIAN_MATRIX_HEIGHT          MATRIX_HEIGHT_EXT(MMI_VKBD_UKRAINIAN_MATRIX_ROW, MMI_VKBD_UKRAINIAN_MATRIX_KEY_HEIGHT, MMI_VKBD_UKRAINIAN_MATRIX_KEY_V_GAP)

#endif /* __MMI_MAINLCD_240X320__ */ 

/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */
extern virtual_keyboard MMI_virtual_keyboard;
extern const gui_keyboard_lang_map_struct MMI_virtual_keyboard_language_map[];
extern const gui_dead_key_map_struct gui_dead_key_symbol_table[];

extern S32 MMI_virtual_keyboard_bitmap_cache_size;
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  create_virtual_keyboard
 * DESCRIPTION
 *  Create virtual keyboard object.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void create_virtual_keyboard(void);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  wgui_virtual_keyboard_set_global_multi_block_mode
 * DESCRIPTION
 *  Set the flag of whether enable multi-block handwriting mode or not.
 * PARAMETERS
 *  enabled        : [IN] IS the flag of whether enable multi block mode or not
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_virtual_keyboard_set_global_multi_block_mode(MMI_BOOL enabled);

/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  wgui_setup_virtual_keyboard
 * DESCRIPTION
 *  Setup the language to be display to virtual keyboard object.
 * PARAMETERS
 *  lang_type       [IN]Is the new language
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know gui_virtual_keyboard_language_enum as well.
 *****************************************************************************/
extern void wgui_setup_virtual_keyboard(gui_virtual_keyboard_language_enum lang_type);

/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  wgui_close_virtual_keyboard
 * DESCRIPTION
 *  Close virtual keyboard and release the resource used by virtual keyboard object.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * REMARKS
 *  This API is generally used in exit function of category.
 *****************************************************************************/
extern void wgui_close_virtual_keyboard(void);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  wgui_set_virtual_keyboard_display_area
 * DESCRIPTION
 *  Update text content of display area for special input method.
 * PARAMETERS
 *  string        [IN] Is the new content to be displayed in display area
 *  redraw        [IN] Whether to redraw the keyboard
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_set_virtual_keyboard_display_area(const U8 *string, BOOL redraw);

/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  wgui_get_virtual_keyboard_size
 * DESCRIPTION
 *  Get the dimension of virtual keyboard object.
 * PARAMETERS
 *  width       [IN/OUT] is the pointer of parameter to get width of virtual keyboard
 *  height      [IN/OUT] is the pointer of parameter to get height of virtual keyboard
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_get_virtual_keyboard_size(S32 *width, S32 *height);

/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  wgui_set_virtual_keyboard_allowed_characters
 * DESCRIPTION
 *  Set the allowd characters that can be inputed in virtual keyboard.
 * REMAKRS
 *  This function and wgui_set_virtual_keyboard_disabled_list() are mutually-exclusive.
 *  
 *  Control keys such as GUI_VKBD_PEN_HIDE, GUI_VKBD_PEN_SHOW... are enabled because
 *  they are not related to character insertion.
 *  
 *  `allowed_characters' may contain '-' for consecutive characters
 *  (Ex. 'a-z' for characters from a to z.)
 *  If we want to accept "-", please write it as '\-'.
 *  For example, '\-0-9.' represents "-0123456789."
 *  
 * PARAMETERS
 *  allowed_chars       : [IN] Is the allowed characters
 * RETURNS
 *  void
 * EXAMPLE
 *  <code>
 *  wgui_set_virtual_keyboard_allowed_characters((const UI_character_type *) L"+_\\-.@A-Za-z0-9");
 *  </code>
 *****************************************************************************/
extern void wgui_set_virtual_keyboard_allowed_characters(const UI_character_type *allowed_chars);

/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  wgui_set_virtual_keyboard_disabled_list
 * DESCRIPTION
 *  Set disabled characters in virtual keyboard.
 * PARAMETERS
 *  disabled_chars      : [IN] Is the disabled characters, ended by '\0'
 *  disabled_symbols    : [IN] Is the disabled symbols which is one value of gui_virtual_keyboard_pen_enum and ended by GUI_VKBD_PEN_NONE
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know gui_virtual_keyboard_pen_enum as well.
 *****************************************************************************/
extern void wgui_set_virtual_keyboard_disabled_list(
                const UI_character_type *disabled_chars,
                const gui_virtual_keyboard_pen_enum *disabled_symbols);

/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  wgui_greyscale_virtual_keyboard
 * DESCRIPTION
 *  Make the 'displayed' virtual keyboard as greyed (disabled)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * REMARKS
 *  
 *****************************************************************************/
extern void wgui_greyscale_virtual_keyboard(void);

/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */

extern gui_keyboard_lang_map_struct_p wgui_get_virtual_keyboard(gui_virtual_keyboard_language_enum vk);
extern gui_dead_key_map_struct_p wgui_get_virtual_keyboard_dead_key_setting(gui_virtual_keyboard_language_enum vk);

/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  wgui_virtual_keyboard_register_hide_cursor_callback
 * DESCRIPTION
 *  Register hide cursor callback function to virtual keyboard object.
 * REMARK
 *  This API is provided for IME to inform edit to stop cursor's blink when
 *  virtual keyboard's popup hint display.
 * PARAMETERS
 *  f        [IN] is handler of hide cursor callback
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_virtual_keyboard_register_hide_cursor_callback(
             MMI_BOOL (*f) (S32 x1, S32 y1, S32 x2, S32 y2));


/*****************************************************************************
 * FUNCTION
 *  wgui_virtual_keyboard_register_blink_cursor_callback
 * DESCRIPTION
 *  Register blink cursor callback function to virtual keyboard object.
 * REMAKR
 *  This API is provided for IME to inform edit recover cursor's blink
 *  when virtual keyboard's popup hint disappear.
 * PARAMETERS
 *  f       [IN] is handler of blink cursor callback
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_virtual_keyboard_register_blink_cursor_callback(
             void (*f) (void));

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  wgui_virtual_keyboard_recover_cached_image
 * DESCRIPTION
 *  Recover the previous screen's content that popup hint covered.
 * REMARKS
 *  This API is provided for IME and editor to recover the area that 
 *  popup hint of virtual keyboard covered.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_virtual_keyboard_recover_covered_area(void);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  wgui_virtual_keyboard_register_display_callback
 * DESCRIPTION
 *  Register the display callback function to virtual keyboard object.
 * PARAMETERS
 *  f         [IN] is the handler of display callback
 * RETURNS
 *  void
 * SEE ALSO
 *  You should also know gui_vkbd_display_callback_type_enum as well.
 *****************************************************************************/
extern void wgui_virtual_keyboard_register_display_callback(
             void (*f) (gui_vkbd_display_callback_type_enum *flag, PU8 *content));

/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  wgui_virtual_keyboard_register_hide_callback
 * DESCRIPTION
 *  Register hide callback function to virtual keyboard object.
 * PARAMETERS
 *  f         : [IN] Is the handler of hide callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_virtual_keyboard_register_hide_callback(
             void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));


extern MMI_BOOL wgui_virtual_keyboard_translate_pen_event(
            S16 x,
            S16 y,
            mmi_pen_event_type_enum pen_event,
            gui_virtual_keyboard_pen_enum *vkbd_event,
            gui_pen_event_param_struct *vkbd_param);

extern virtual_keyboard* wgui_virtual_keyboard_get_handle(void);

extern void wgui_show_virtual_keyboard(void);

extern void wgui_virtual_keyboard_draw_from_cache(void);
extern void wgui_virtual_keyboard_recache(void);

/* DOM-NOT_FOR_SDK-END */

#endif /* defined(__MMI_TOUCH_SCREEN__) */

#endif /* __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__ */

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
/*****************************************************************************
 * Following code is for VK V2
 ****************************************************************************/

#include "gui_virtual_keyboard_language_type.h"
#include "gui_virtual_keyboard.h"

#if defined(__MMI_TOUCH_SCREEN__)
/***************************************************************************** 
* Define
*****************************************************************************/
#if defined(__MMI_MAINLCD_480X800__)
    #define  MMI_VKBD_TRAY_HEIGHT                   342
#elif defined(__MMI_MAINLCD_320X480__)
    #define  MMI_VKBD_TRAY_HEIGHT                   205
#elif defined (__MMI_MAINLCD_240X320__) 
    #define  MMI_VKBD_TRAY_HEIGHT                   159
#elif defined (__MMI_MAINLCD_240X400__)
    #define  MMI_VKBD_TRAY_HEIGHT                   162
#else /* (__MMI_MAINLCD_240X400__) */
    #error "FTE is not supported under the resolution."
#endif

/* max language count in one project */
#define WGUI_VIRTUAL_KEYBOARD_MAX_LANG_COUNT            20

#define WGUI_VIRTUAL_KEYBOARD_DEFAULT_LANGUAGE          GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY
/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef struct
{
    /* Resolution */
    S32 resolution_width, resolution_height;
    /* dimension of VK */
    S32 width, height;
    /* key count */
    U16 count;
    /* image id of VK background */
    U16 bg_id;
    /* language enum */
    gui_virtual_keyboard_language_enum lang;
    gui_virtual_keyboard_text_align_enum text_align;
    /* is rotate layout */
    U32 vk_attr;
    /* is round rect if we use code to draw buttons */
    MMI_BOOL is_round_rect;
    /* is rotate support */
    MMI_BOOL is_rotate_support;
    gui_virtual_keyboard_key_struct_p  key_list;
} wgui_virtual_keyboard_layout_struct, *wgui_virtual_keyboard_layout_struct_p;



/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
extern gui_virtual_keyboard_language_enum g_wgui_virtual_keyboard_lang_type;
extern gui_virtual_keyboard_struct g_wgui_virtual_keyboard;
/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void wgui_virtual_keyboard_discard_cache_and_recache(void);
extern void wgui_virtual_keyboard_draw_from_cache(void);
extern void wgui_virtual_keyboard_recache(void);
extern gui_virtual_keyboard_struct* wgui_get_virtual_keyboard_by_cb(void);
extern void wgui_virtual_keyboard_init_layout(void);
extern void wgui_setup_virtual_keyboard(
             gui_virtual_keyboard_language_enum lang,
             U32 vk_attr,
             gui_virtual_keyboard_event_callback_func_ptr event_callback,
             gui_virtual_keyboard_display_callback_func_ptr display_callback);
extern void wgui_virtual_keyboard_set_global_multi_block_mode(MMI_BOOL enabled);
extern void wgui_virtual_keyboard_close(void);
extern void wgui_virtual_keyboard_get_dimension(S32 *width, S32 *height);
extern void wgui_virtual_keyboard_get_positon(S32 *x, S32 *y);
extern void wgui_virtual_keyboard_move(S32 x, S32 y);
extern void wgui_virtual_keyboard_show(void);

extern void wgui_virtual_keyboard_set_dead_keys(const UI_character_type *dead_chars);
extern void wgui_virtual_keyboard_set_allowed_characters(
             const UI_character_type *allowed_chars);
extern void wgui_virtual_keyboard_set_disable_list(
             const UI_character_type *disabled_chars,
             const gui_virtual_keyboard_pen_enum *disabled_symbols);
extern void wgui_virtual_keyboard_set_display_area(const U8 *string, MMI_BOOL redraw);

extern void wgui_virtual_keyboard_register_hide_callback(
             void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));
extern void wgui_virtual_keyboard_register_display_callback(
             gui_virtual_keyboard_display_callback_func_ptr f);
extern void wgui_virtual_keyboard_register_hide_cursor_callback(
             MMI_BOOL (*f) (S32 x1, S32 y1, S32 x2, S32 y2));
extern void wgui_virtual_keyboard_register_blink_cursor_callback(
             void (*f) (void));
extern void wgui_virtual_keyboard_recover_covered_area(void);
extern MMI_BOOL wgui_virtual_keyboard_translate_pen_event(
                            S16 x,
                            S16 y,
                            mmi_pen_event_type_enum pen_event,
                            gui_virtual_keyboard_pen_enum *vkbd_event,
                            gui_pen_event_param_struct *vkbd_param);
extern void wgui_virtual_keyboard_get_key_info(gui_virtual_keyboard_key_pos_info_struct_p info);

extern MMI_BOOL wgui_virtual_keyboard_Check_alphanumeric_vk_0_to_9_key(
          S16 x,
		  S16 y);
#endif /* __MMI_TOUCH_SCREEN__ */

extern void wgui_virtual_keyboard_clear_cache_on_imc_disconnect(void);
extern void wgui_virtual_keyboard_clear_state_on_imc_disconnect(void);

extern void wgui_virtual_keyboard_set_vk_changed(MMI_BOOL state);
#endif /* __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__ */

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)

#include "gui_virtual_keyboard_language_type.h"
#include "gui_virtual_keyboard.h"

#if defined(__MMI_MAINLCD_480X800__)
    #define  MMI_VKBD_TRAY_HEIGHT                   342
#elif defined(__MMI_MAINLCD_320X480__)
    #define  MMI_VKBD_TRAY_HEIGHT                   205
#elif defined (__MMI_MAINLCD_240X320__) 
    #define  MMI_VKBD_TRAY_HEIGHT                   159
#elif defined (__MMI_MAINLCD_240X400__)
    #define  MMI_VKBD_TRAY_HEIGHT                   162
#elif defined (__MMI_MAINLCD_320X240__)
    #define  MMI_VKBD_TRAY_HEIGHT                   119
#endif

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
extern gui_virtual_keyboard_language_enum g_wgui_virtual_keyboard_lang_type;
extern gui_virtual_keyboard_struct g_wgui_virtual_keyboard;

#define WGUI_VIRTUAL_KEYBOARD_DEFAULT_LANGUAGE          GUI_VIRTUAL_KEYBOARD_EMPTY_TRAY

typedef struct wgui_virtual_keyboard_layout_struct
{
    U16 height; //keyboard's height
    U16 width;  //keyboard's width
    U16 bg;

    U8 margin_x;
    U8 margin_y;

    U8 row_num;    //number of  rows
    const struct gui_virtual_keyboard_row_struct* row_list;
    gui_virtual_keyboard_language_enum keyboard_type;
    
    S8 vk_attribute;   //indicate VK's style, for example ,qwerty,  phonetic and handwriting.
    MMI_BOOL is_rotate; //indicate whether VK is land mode.
    MMI_BOOL is_shift_spport;//need to support shift key function
    MMI_BOOL is_cache;  //reserved

    const struct gui_virtual_keyboard_keytype_struct* keytype_list;
}wgui_virtual_keyboard_layout_struct,* wgui_virtual_keyboard_layout_struct_p;

#ifdef __IMEHW_DCM_SUPPORT__
extern const wgui_virtual_keyboard_layout_struct* wgui_virtual_keyboard_layout_list;
extern const wgui_virtual_keyboard_layout_struct  keyBoardTable[];
#endif
extern void wgui_virtual_keyboard_discard_cache_and_recache(void);
extern void wgui_virtual_keyboard_draw_from_cache(void);
extern void wgui_virtual_keyboard_recache(void);
extern gui_virtual_keyboard_struct* wgui_get_virtual_keyboard_by_cb(void);
extern void wgui_virtual_keyboard_init_layout(void);
extern void wgui_setup_virtual_keyboard(
             gui_virtual_keyboard_language_enum lang,
             U32 vk_attr);
extern void wgui_setup_virtual_keyboard_by_layout(
            const wgui_virtual_keyboard_layout_struct* layout);
extern void wgui_virtual_keyboard_set_global_multi_block_mode(MMI_BOOL enabled);
extern void wgui_virtual_keyboard_close(void);
extern void wgui_virtual_keyboard_get_dimension(S32 *width, S32 *height);
extern void wgui_virtual_keyboard_get_positon(S32 *x, S32 *y);
extern void wgui_virtual_keyboard_move(S32 x, S32 y);
extern void wgui_virtual_keyboard_show(void);

extern void wgui_virtual_keyboard_set_dead_keys(const UI_character_type *dead_chars);
extern void wgui_virtual_keyboard_set_allowed_characters(
             const UI_character_type *allowed_chars);
extern void wgui_virtual_keyboard_set_disable_list(
             const UI_character_type *disabled_chars,
             const gui_virtual_keyboard_pen_enum *disabled_symbols);
extern void wgui_virtual_keyboard_set_display_area(const U8 *string, MMI_BOOL redraw);

extern void wgui_virtual_keyboard_register_hide_callback(
             void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));
extern void wgui_virtual_keyboard_register_display_callback(
             gui_virtual_keyboard_display_callback_func_ptr f);
extern void wgui_virtual_keyboard_register_hide_cursor_callback(
             MMI_BOOL (*f) (S32 x1, S32 y1, S32 x2, S32 y2));
extern void wgui_virtual_keyboard_register_blink_cursor_callback(
             void (*f) (void));
extern void wgui_virtual_keyboard_recover_covered_area(void);
extern MMI_BOOL wgui_virtual_keyboard_translate_pen_event(
                            S16 x,
                            S16 y,
                            mmi_pen_event_type_enum pen_event,
                            gui_virtual_keyboard_pen_enum *vkbd_event,
                            gui_pen_event_param_struct *vkbd_param);
extern void wgui_virtual_keyboard_get_key_info(gui_virtual_keyboard_key_pos_info_struct_p info);

extern MMI_BOOL wgui_virtual_keyboard_Check_alphanumeric_vk_0_to_9_key(
            S16 x,
            S16 y);


extern void wgui_virtual_keyboard_clear_cache_on_imc_disconnect(void);
extern void wgui_virtual_keyboard_clear_state_on_imc_disconnect(void);

extern MMI_BOOL wgui_virtual_keyboard_add_toggle_state_key(
                toggle_state_key_index_enum toggle_key_index,
                U8 state_id);

extern MMI_BOOL wgui_virtual_keyboard_remove_toggle_state_key(
                toggle_state_key_index_enum toggle_key_index);

extern void wgui_virtual_keyboard_set_active_row(U32 row_id);

extern void wgui_virtual_keyboard_set_get_string_func(get_multitap_string f);

/*those function may be removed to other file*/

extern U32 wgui_virtual_keyboard_get_button_count(void);

extern void wgui_virtual_keyboard_set_current_layout(
        gui_virtual_keyboard_language_enum lang, 
        U32 vk_attribute);

extern U16 wgui_virtual_keyboard_get_button_bg_image(  
            U32 index, 
            gui_virtual_keyboard_key_state_enum flag);

extern U16 wgui_virtual_keyboard_get_margin_x(
        U32 index);

extern U16 wgui_virtual_keyboard_get_margin_y(
        U32 index);

extern MMI_BOOL wgui_virtual_keyboard_is_popup_exist(U32 index);
  
extern void  wgui_virtual_keyboard_get_button_icon( 
            U32 index, 
            gui_virtual_keyboard_key_state_enum flag,
            U16 * img_resid,
            U32*  loc_x,
            U32 *loc_y);
extern void wgui_virtual_keyboard_get_button_icon_aux( 
            U32 index, 
            gui_virtual_keyboard_key_state_enum flag,
            U16 * img_resid,
            U32*  loc_x,
            U32 *loc_y);

extern void wgui_virtual_keyboard_get_button_icon_rect(
            U32 index, 
            gui_virtual_keyboard_key_state_enum flag,
            S32*  loc_x,
            S32 *loc_y,
            S32 * width , 
            S32* height);

extern void wgui_virtual_keyboard_get_button_icon_aux_rect(
            U32 index, 
            gui_virtual_keyboard_key_state_enum flag,
            S32*  loc_x,
            S32 *loc_y,
            S32 * width , 
            S32* height);

extern void wgui_virtual_keyboard_get_button_label( 
            U32 index, 
            UI_string_type* label,
            U32* loc_x,
            U32*loc_y,
            U32*color , 
            U32*size ,
            gui_virtual_keyboard_key_state_enum flag);

extern void  wgui_virtual_keyboard_get_button_label_aux( 
            U32 index, 
            UI_string_type* label,
            U32 *loc_x,
            U32 *loc_y,
            U32 *color , 
            U32 *size,
            gui_virtual_keyboard_key_state_enum flag );

extern void wgui_virtual_keyboard_get_button_label_rect( 
        U32 index, 
        gui_virtual_keyboard_key_state_enum flag,
        S32* loc_x,
        S32*loc_y,
        S32 * width , 
        S32* height,
        S32* baseline);
extern void wgui_virtual_keyboard_get_vk_rect(gui_virtual_keyboard_rect_struct_p rect,MMI_BOOL is_large);
extern U32 wgui_virtual_keyboard_get_vk_width(void);

extern U32 wgui_virtual_keyboard_get_vk_height(void);

extern void wgui_virtual_keyboard_get_button_label_aux_rect( 
        U32 index, 
        gui_virtual_keyboard_key_state_enum flag,
        S32* loc_x,
        S32*loc_y,
        S32 * width , 
        S32* height,
        S32* baseline);

extern void wgui_virtual_keyboard_get_button_rect( 
            U32 index , 
            S32 * x , 
            S32 * y , 
            S32 * width , 
            S32* height );
extern void wgui_virtual_keyboard_get_hl_button_rect( 
        U32 index , 
        U32 * x , 
        U32 * y , 
        U32 * width , 
        U32* height );

extern U32 wgui_virtual_keyboard_return_floating_composition_box_width(void);

extern void wgui_virtual_keyboard_get_popup_hint_rect(
        U32 index,
        S32 * x,
        S32 * y,
        S32 * width,
        S32 * height);

extern U16 wgui_virtual_keyboard_get_vk_bg_img(void);

extern U32 wgui_virtual_keyboard_get_vk_attr(void);

extern MMI_BOOL wgui_virtual_keyboard_is_key_has_mini_keyboard(
        U32 index);

extern const wgui_virtual_keyboard_layout_struct* wgui_virtual_keyboard_get_mini_keyboard_layout(
        U32 index);

extern MMI_BOOL wgui_virtual_keyboard_is_rotate_vk(void);

extern MMI_BOOL wgui_virtual_keyboard_is_shift_support(void);

extern MMI_BOOL wgui_virtual_keyboard_is_shift_state(void);

extern MMI_BOOL wgui_virtual_keyboard_is_cache(void);

extern S32 wgui_virtual_keyboard_get_longtap_vk(
            U32 index);

extern void wgui_virtual_keyboard_set_shift_state(toggle_state_id_mapping_enum flag);


extern const wgui_virtual_keyboard_layout_struct* wgui_virtual_keyboard_get_vk_layout(
   gui_virtual_keyboard_language_enum lang,
   S32 attr);

extern MMI_BOOL wgui_virtual_keyboard_is_symbol_vk(gui_virtual_keyboard_language_enum vk_type);

/* logical property */
extern U32 wgui_virtual_keyboard_get_button_code(  
        U32 index, mmi_pen_event_type_enum pen_event);
extern S32 wgui_virtual_keyboard_get_button_code_longpress(  
        U32 index);

extern void wgui_virtual_keyboard_get_qwerty_keymapping(UI_character_type* key_mapping, U32 len);
/*those function may be removed to other file*/

extern U32 wgui_virtual_keyboard_get_button_code_type(  
        U32 index , mmi_pen_event_type_enum pen_event);

extern U32 wgui_virtual_keyboard_get_button_code_type_longpress(  
        U32 index );

extern U32 wgui_virtual_keyboard_get_button_code_pointer(  
        U32 index, mmi_pen_event_type_enum pen_event);

extern void wgui_virtual_keyboard_set_large_screen_mode(
    MMI_BOOL flag);

extern void wgui_virtual_keyboard_get_mini_keyboard_pos(
            S32     index,
            S32*    x,
            S32*    y);
#endif/*__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__*/


#else
#define MMI_VKBD_TRAY_HEIGHT 0
void wgui_virtual_keyboard_register_blink_cursor_callback(
      void (*f) (void));
void wgui_virtual_keyboard_register_hide_cursor_callback(
      MMI_BOOL (*f) (S32 x1, S32 y1, S32 x2, S32 y2));
#endif /* #if defined(__MMI_VIRTUAL_KEYBOARD__) */
#endif /* __WGUI_VIRTUAL_KEYBOARD_H__ */ 


