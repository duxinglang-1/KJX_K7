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
 * vapp_dla_config.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 * Vikas Lal Srivastava (MTK33036)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef _VAPP_DLAGENT_COMP_SIZE_H_
#define _VAPP_DLAGENT_COMP_SIZE_H_


#if defined(__MMI_MAINLCD_320X480__)

/* Defining to overwrite default value */
#ifndef __VENUS_DOWNLOAD_AGENT_PLATFORM_DEFINE_VALUES__
#define __VENUS_DOWNLOAD_AGENT_PLATFORM_DEFINE_VALUES__
#endif /* __VENUS_DOWNLOAD_AGENT_PLATFORM_DEFINE_VALUES__ */


/*******************************************  Defiining Landscape mode macros  ***************************************************/
#define VAPP_DLA_LIST_ITEM_COMMON_DISTANCE                           5

#define VAPP_DLA_LIST_ITEM_FILENAME_EDIT_LENGTH                      180
#define VAPP_DLA_LIST_ITEM_FILENAME_EDIT_WIDTH                       20

#define VAPP_DLA_LIST_ITEM_STATUS_EDIT_LENGTH                        120
#define VAPP_DLA_LIST_ITEM_STATUS_EDIT_WIDTH                         15

#define VAPP_DLA_LIST_ITEM_SIZE_EDIT_LENGTH                          120
#define VAPP_DLA_LIST_ITEM_SIZE_EDIT_WIDTH                           15

#define VAPP_DLA_LIST_ITEM_TIME_EDIT_LENGTH                          (LCD_WIDTH - VAPP_DLA_LIST_ITEM_RIGHT_MARGIN - VAPP_DLA_LIST_ITEM_LEFT_MARGIN) 
#define VAPP_DLA_LIST_ITEM_TIME_EDIT_WIDTH                           15

#define VAPP_DLA_LIST_ITEM_TOP_MARGIN                                2
#define VAPP_DLA_LIST_ITEM_LEFT_MARGIN                               5
#define VAPP_DLA_LIST_ITEM_RIGHT_MARGIN                              5
#define VAPP_DLA_LIST_ITEM_BOTTOM_MARGIN                             2

#define VAPP_DLA_LIST_ITEM_BUTTOM_WIDTH                              40
#define VAPP_DLA_LIST_ITEM_BUTTOM_LENGTH                             150
#define VAPP_DLA_LIST_ITEM_DISTANCE_BTW_BUTTONS                      (LCD_WIDTH - (2*VAPP_DLA_LIST_ITEM_BUTTOM_LENGTH) - VAPP_DLA_LIST_ITEM_LEFT_MARGIN - VAPP_DLA_LIST_ITEM_RIGHT_MARGIN)

#define VAPP_DLA_LIST_ITEM_PROGRESS_BAR_WIDTH                        10
#define VAPP_DLA_LIST_ITEM_PROGRESS_BAR_LENGTH                       (LCD_WIDTH - VAPP_DLA_LIST_ITEM_RIGHT_MARGIN - VAPP_DLA_LIST_ITEM_LEFT_MARGIN)



/*******************************************  Defiining Landscape mode macros  ***************************************************/
#define VAPP_DLA_LIST_ITEM_COMMON_DISTANCE_LANDSCAPE                 5

#define VAPP_DLA_LIST_ITEM_FILENAME_EDIT_LENGTH_LANDSCAPE            280
#define VAPP_DLA_LIST_ITEM_FILENAME_EDIT_WIDTH_LANDSCAPE             20

#define VAPP_DLA_LIST_ITEM_STATUS_EDIT_LENGTH_LANDSCAPE              140
#define VAPP_DLA_LIST_ITEM_STATUS_EDIT_WIDTH_LANDSCAPE               15

#define VAPP_DLA_LIST_ITEM_SIZE_EDIT_LENGTH_LANDSCAPE                140
#define VAPP_DLA_LIST_ITEM_SIZE_EDIT_WIDTH_LANDSCAPE                 15

#define VAPP_DLA_LIST_ITEM_TIME_EDIT_LENGTH_LANDSCAPE                (LCD_HEIGHT - VAPP_DLA_LIST_ITEM_RIGHT_MARGIN - VAPP_DLA_LIST_ITEM_LEFT_MARGIN)
#define VAPP_DLA_LIST_ITEM_TIME_EDIT_WIDTH_LANDSCAPE                 15

#define VAPP_DLA_LIST_ITEM_TOP_MARGIN_LANDSCAPE                      2
#define VAPP_DLA_LIST_ITEM_LEFT_MARGIN_LANDSCAPE                     5
#define VAPP_DLA_LIST_ITEM_RIGHT_MARGIN_LANDSCAPE                    5
#define VAPP_DLA_LIST_ITEM_BOTTOM_MARGIN_LANDSCAPE                   2

#define VAPP_DLA_LIST_ITEM_BUTTOM_WIDTH_LANDSCAPE                    40
#define VAPP_DLA_LIST_ITEM_BUTTOM_LENGTH_LANDSCAPE                   225
#define VAPP_DLA_LIST_ITEM_DISTANCE_BTW_BUTTONS_LANDSCAPE            (LCD_HEIGHT - (2*VAPP_DLA_LIST_ITEM_BUTTOM_LENGTH_LANDSCAPE) - VAPP_DLA_LIST_ITEM_LEFT_MARGIN_LANDSCAPE - VAPP_DLA_LIST_ITEM_RIGHT_MARGIN_LANDSCAPE)

#define VAPP_DLA_LIST_ITEM_PROGRESS_BAR_WIDTH_LANDSCAPE              10
#define VAPP_DLA_LIST_ITEM_PROGRESS_BAR_LENGTH_LANDSCAPE             (LCD_HEIGHT - VAPP_DLA_LIST_ITEM_RIGHT_MARGIN_LANDSCAPE - VAPP_DLA_LIST_ITEM_LEFT_MARGIN_LANDSCAPE)

#endif /* __MMI_MAINLCD_320X480__ */




/* For WVGA */

#if defined(__MMI_MAINLCD_480X800__)

/* Defining to overwrite default value */
#ifndef __VENUS_DOWNLOAD_AGENT_PLATFORM_DEFINE_VALUES__
#define __VENUS_DOWNLOAD_AGENT_PLATFORM_DEFINE_VALUES__
#endif /* __VENUS_DOWNLOAD_AGENT_PLATFORM_DEFINE_VALUES__ */


/*******************************************  Defiining Landscape mode macros  ***************************************************/
#define VAPP_DLA_LIST_ITEM_COMMON_DISTANCE                           10

#define VAPP_DLA_LIST_ITEM_FILENAME_EDIT_LENGTH                      250
#define VAPP_DLA_LIST_ITEM_FILENAME_EDIT_WIDTH                       35

#define VAPP_DLA_LIST_ITEM_STATUS_EDIT_LENGTH                        200
#define VAPP_DLA_LIST_ITEM_STATUS_EDIT_WIDTH                         25

#define VAPP_DLA_LIST_ITEM_SIZE_EDIT_LENGTH                          200
#define VAPP_DLA_LIST_ITEM_SIZE_EDIT_WIDTH                           25

#define VAPP_DLA_LIST_ITEM_TOP_MARGIN                                14
#define VAPP_DLA_LIST_ITEM_LEFT_MARGIN                               5
#define VAPP_DLA_LIST_ITEM_RIGHT_MARGIN                              5
#define VAPP_DLA_LIST_ITEM_BOTTOM_MARGIN                             14

#define VAPP_DLA_LIST_ITEM_BUTTOM_WIDTH                              80
#define VAPP_DLA_LIST_ITEM_BUTTOM_LENGTH                             220
#define VAPP_DLA_LIST_ITEM_DISTANCE_BTW_BUTTONS                      (LCD_WIDTH - (2*VAPP_DLA_LIST_ITEM_BUTTOM_LENGTH) - VAPP_DLA_LIST_ITEM_LEFT_MARGIN - VAPP_DLA_LIST_ITEM_RIGHT_MARGIN)

#define VAPP_DLA_LIST_ITEM_PROGRESS_BAR_WIDTH                        10
#define VAPP_DLA_LIST_ITEM_PROGRESS_BAR_LENGTH                       (LCD_WIDTH - VAPP_DLA_LIST_ITEM_RIGHT_MARGIN - VAPP_DLA_LIST_ITEM_LEFT_MARGIN)


#define VAPP_DLA_LIST_ITEM_TIME_EDIT_LENGTH                          (LCD_WIDTH - VAPP_DLA_LIST_ITEM_RIGHT_MARGIN - VAPP_DLA_LIST_ITEM_LEFT_MARGIN) 
#define VAPP_DLA_LIST_ITEM_TIME_EDIT_WIDTH                           25



/*******************************************  Defiining Landscape mode macros  ***************************************************/
#define VAPP_DLA_LIST_ITEM_COMMON_DISTANCE_LANDSCAPE                 10

#define VAPP_DLA_LIST_ITEM_FILENAME_EDIT_LENGTH_LANDSCAPE            400
#define VAPP_DLA_LIST_ITEM_FILENAME_EDIT_WIDTH_LANDSCAPE             60

#define VAPP_DLA_LIST_ITEM_STATUS_EDIT_LENGTH_LANDSCAPE              300
#define VAPP_DLA_LIST_ITEM_STATUS_EDIT_WIDTH_LANDSCAPE               42

#define VAPP_DLA_LIST_ITEM_SIZE_EDIT_LENGTH_LANDSCAPE                300
#define VAPP_DLA_LIST_ITEM_SIZE_EDIT_WIDTH_LANDSCAPE                 42

#define VAPP_DLA_LIST_ITEM_TIME_EDIT_LENGTH_LANDSCAPE                (LCD_HEIGHT - VAPP_DLA_LIST_ITEM_RIGHT_MARGIN - VAPP_DLA_LIST_ITEM_LEFT_MARGIN)
#define VAPP_DLA_LIST_ITEM_TIME_EDIT_WIDTH_LANDSCAPE                 42

#define VAPP_DLA_LIST_ITEM_TOP_MARGIN_LANDSCAPE                      10
#define VAPP_DLA_LIST_ITEM_LEFT_MARGIN_LANDSCAPE                     5
#define VAPP_DLA_LIST_ITEM_RIGHT_MARGIN_LANDSCAPE                    5
#define VAPP_DLA_LIST_ITEM_BOTTOM_MARGIN_LANDSCAPE                   10

#define VAPP_DLA_LIST_ITEM_BUTTOM_WIDTH_LANDSCAPE                    80
#define VAPP_DLA_LIST_ITEM_BUTTOM_LENGTH_LANDSCAPE                   375
#define VAPP_DLA_LIST_ITEM_DISTANCE_BTW_BUTTONS_LANDSCAPE            (LCD_HEIGHT - (2*VAPP_DLA_LIST_ITEM_BUTTOM_LENGTH_LANDSCAPE) - VAPP_DLA_LIST_ITEM_LEFT_MARGIN_LANDSCAPE - VAPP_DLA_LIST_ITEM_RIGHT_MARGIN_LANDSCAPE)

#define VAPP_DLA_LIST_ITEM_PROGRESS_BAR_WIDTH_LANDSCAPE              10
#define VAPP_DLA_LIST_ITEM_PROGRESS_BAR_LENGTH_LANDSCAPE             (LCD_HEIGHT - VAPP_DLA_LIST_ITEM_RIGHT_MARGIN_LANDSCAPE - VAPP_DLA_LIST_ITEM_LEFT_MARGIN_LANDSCAPE)

#endif /* __MMI_MAINLCD_480X800__ */

#endif /* _VAPP_DLAGENT_COMP_SIZE_H_ */







#if (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__))

/* Defining to overwrite default value */
#ifndef __VENUS_DOWNLOAD_AGENT_PLATFORM_DEFINE_VALUES__
#define __VENUS_DOWNLOAD_AGENT_PLATFORM_DEFINE_VALUES__
#endif /* __VENUS_DOWNLOAD_AGENT_PLATFORM_DEFINE_VALUES__ */


/*******************************************  Defiining Landscape mode macros  ***************************************************/
#define VAPP_DLA_LIST_ITEM_COMMON_DISTANCE                           3

#define VAPP_DLA_LIST_ITEM_FILENAME_EDIT_LENGTH                      130
#define VAPP_DLA_LIST_ITEM_FILENAME_EDIT_WIDTH                       18

#define VAPP_DLA_LIST_ITEM_STATUS_EDIT_LENGTH                        100
#define VAPP_DLA_LIST_ITEM_STATUS_EDIT_WIDTH                         13

#define VAPP_DLA_LIST_ITEM_SIZE_EDIT_LENGTH                          100
#define VAPP_DLA_LIST_ITEM_SIZE_EDIT_WIDTH                           13

#define VAPP_DLA_LIST_ITEM_TOP_MARGIN                                5
#define VAPP_DLA_LIST_ITEM_LEFT_MARGIN                               8
#define VAPP_DLA_LIST_ITEM_RIGHT_MARGIN                              8
#define VAPP_DLA_LIST_ITEM_BOTTOM_MARGIN                             4

#define VAPP_DLA_LIST_ITEM_TIME_EDIT_LENGTH                          (LCD_WIDTH - VAPP_DLA_LIST_ITEM_RIGHT_MARGIN - VAPP_DLA_LIST_ITEM_LEFT_MARGIN) 
#define VAPP_DLA_LIST_ITEM_TIME_EDIT_WIDTH                           13

#define VAPP_DLA_LIST_ITEM_BUTTOM_WIDTH                              35
#define VAPP_DLA_LIST_ITEM_BUTTOM_LENGTH                             110
#define VAPP_DLA_LIST_ITEM_DISTANCE_BTW_BUTTONS                      (LCD_WIDTH - (2*VAPP_DLA_LIST_ITEM_BUTTOM_LENGTH) - VAPP_DLA_LIST_ITEM_LEFT_MARGIN - VAPP_DLA_LIST_ITEM_RIGHT_MARGIN)

#define VAPP_DLA_LIST_ITEM_PROGRESS_BAR_WIDTH                        10
#define VAPP_DLA_LIST_ITEM_PROGRESS_BAR_LENGTH                       (LCD_WIDTH - VAPP_DLA_LIST_ITEM_RIGHT_MARGIN - VAPP_DLA_LIST_ITEM_LEFT_MARGIN)



/*******************************************  Defiining Landscape mode macros  ***************************************************/
#define VAPP_DLA_LIST_ITEM_COMMON_DISTANCE_LANDSCAPE                 3

#define VAPP_DLA_LIST_ITEM_FILENAME_EDIT_LENGTH_LANDSCAPE            180
#define VAPP_DLA_LIST_ITEM_FILENAME_EDIT_WIDTH_LANDSCAPE             18

#define VAPP_DLA_LIST_ITEM_STATUS_EDIT_LENGTH_LANDSCAPE              120
#define VAPP_DLA_LIST_ITEM_STATUS_EDIT_WIDTH_LANDSCAPE               13

#define VAPP_DLA_LIST_ITEM_SIZE_EDIT_LENGTH_LANDSCAPE                120
#define VAPP_DLA_LIST_ITEM_SIZE_EDIT_WIDTH_LANDSCAPE                 13

#define VAPP_DLA_LIST_ITEM_TIME_EDIT_LENGTH_LANDSCAPE                (LCD_HEIGHT - VAPP_DLA_LIST_ITEM_RIGHT_MARGIN - VAPP_DLA_LIST_ITEM_LEFT_MARGIN)
#define VAPP_DLA_LIST_ITEM_TIME_EDIT_WIDTH_LANDSCAPE                 13

#define VAPP_DLA_LIST_ITEM_TOP_MARGIN_LANDSCAPE                      5
#define VAPP_DLA_LIST_ITEM_LEFT_MARGIN_LANDSCAPE                     8
#define VAPP_DLA_LIST_ITEM_RIGHT_MARGIN_LANDSCAPE                    8
#define VAPP_DLA_LIST_ITEM_BOTTOM_MARGIN_LANDSCAPE                   4

#define VAPP_DLA_LIST_ITEM_BUTTOM_WIDTH_LANDSCAPE                    35
#ifdef __MMI_MAINLCD_240X320__
#define VAPP_DLA_LIST_ITEM_BUTTOM_LENGTH_LANDSCAPE                   145
#else
#define VAPP_DLA_LIST_ITEM_BUTTOM_LENGTH_LANDSCAPE                   160
#endif /* __MMI_MAINLCD_240X320__ */
#define VAPP_DLA_LIST_ITEM_DISTANCE_BTW_BUTTONS_LANDSCAPE            (LCD_HEIGHT - (2*VAPP_DLA_LIST_ITEM_BUTTOM_LENGTH_LANDSCAPE) - VAPP_DLA_LIST_ITEM_LEFT_MARGIN_LANDSCAPE - VAPP_DLA_LIST_ITEM_RIGHT_MARGIN_LANDSCAPE)

#define VAPP_DLA_LIST_ITEM_PROGRESS_BAR_WIDTH_LANDSCAPE              10
#define VAPP_DLA_LIST_ITEM_PROGRESS_BAR_LENGTH_LANDSCAPE             (LCD_HEIGHT - VAPP_DLA_LIST_ITEM_RIGHT_MARGIN_LANDSCAPE - VAPP_DLA_LIST_ITEM_LEFT_MARGIN_LANDSCAPE)

#endif /* __MMI_MAINLCD_320X480__ */

