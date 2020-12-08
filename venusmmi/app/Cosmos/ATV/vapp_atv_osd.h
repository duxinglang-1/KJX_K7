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
 *  vapp_atv_osd.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  vapp_atv_osd
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files
*****************************************************************************/
#ifndef __VAPP_ATV_OSD_H__
#define __VAPP_ATV_OSD_H__

#include "mmi_features.h"
#include "MMIDataType.h"
#include "lcd_sw_inc.h"
#ifdef __MMI_ATV_SUPPORT__

/*******************************************
 * Enum
 *******************************************/

typedef enum
{
    VAPP_ATV_ICON_STATUS_DISABLE,
    VAPP_ATV_ICON_STATUS_ENABLE,
    VAPP_ATV_ICON_STATUS_CLICKED
} vappAtvOsdIconStatusEnum;


/*******************************************
 * Structure
 *******************************************/



#if ((LCD_WIDTH == 240) && (LCD_HEIGHT == 320))

#define VAPP_ATV_ADJUST_BAR_Y   (116)
#define VAPP_ATV_ADJUST_BORDER_WIDTH  (20)
#define VAPP_ATV_ADJUST_TEXT_FONT_SIZE  (13)
#define VAPP_ATV_ADJUST_SLIDER_OFFSET   (16)

#ifndef __MMI_ATV_SLIM__
#define VAPP_ATV_WHEEL_CENT_TEXT_FONT_SIZE  (25)
#define VAPP_ATV_WHEEL_TEXT_FONT_SIZE  (18)
#define VAPP_ATV_WHEEL_RADIUS  (155)
#define VAPP_ATV_WHEEL_DEGREE  (16)
#define VAPP_ATV_WHEEL_ORIGIN_X  (400)
#define VAPP_ATV_WHEEL_BTN_X (297)
#define VAPP_ATV_WHEEL_BTN_UP_Y (71)
#define VAPP_ATV_WHEEL_BTN_DOWN_Y (150)
#define VAPP_ATV_WHEEL_BTN_WIDTH (30)
#define VAPP_ATV_WHEEL_BTN_HEIGHT (70)

#define VAPP_ATV_TBAR_BG_Y      (10)
#define VAPP_ATV_TBAR_BG_H      (220)
#define VAPP_ATV_TBAR_HANDLE_X  (33)
#define VAPP_ATV_TBAR_HANDLE_Y  (95)
#define VAPP_ATV_TBAR_LINE_X    (2)

#else
//QVGA
// target frame font size
#define VAPP_ATV_WHEEL_SLIM_CENT_TEXT_FONT_SIZE  (24)
#define VAPP_ATV_WHEEL_SLIM_TEXT_FONT_SIZE  (18)

// BG frame 
#define VAPP_ATV_WHEEL_SLIM_BG_FRAME_WIDTH (50)
#define VAPP_ATV_WHEEL_SLIM_BG_FRAME_HEIGHT (184)
#define VAPP_ATV_WHEEL_SLIM_BG_Y  (26)
#define VAPP_ATV_WHEEL_SLIM_OFFSET_Y        (4)  //THE FRAME NEED START from -offset
#define VAPP_ATV_WHEEL_SLIM_OFFSET_DOUBLE_Y (8)  //the height of frame need add double offset

// BG line step
#define VAPP_ATV_WHEEL_SLIM_STEP_BIG    (38)
#define VAPP_ATV_WHEEL_SLIM_STEP_SMALL  (36)

// BG line pos.x
#define VAPP_ATV_WHEEL_SLIM_LINE_X    (5)
//center triangle
#define VAPP_ATV_WHEEL_SLIM_TARGET_FRAME_X (30)
#define VAPP_ATV_WHEEL_SLIM_CENTER_TRIANGGLE_X  (10)
#define VAPP_ATV_WHEEL_SLIM_CENTER_TRIANGGLE_Y  (92)

#define VAPP_ATV_TBAR_BG_GAP    (5)

#define VAPP_ATV_TBAR_BG_Y      (10)
#define VAPP_ATV_TBAR_BG_H      (220)
#define VAPP_ATV_TBAR_HANDLE_X  (33)
#define VAPP_ATV_TBAR_HANDLE_Y  (95)
#define VAPP_ATV_TBAR_LINE_X    (2)

#define VAPP_ATV_TOOLBAR_SLIM_WIDTH  (38)

#endif



#define VAPP_ATV_SIGNAL_X (37)
#define VAPP_ATV_SIGNAL_Y (6)
#define VAPP_ATV_REC_STATUS_X (243)
#define VAPP_ATV_REC_STATUS_Y (9)
#define VAPP_ATV_REC_TIME_X (264)
#define VAPP_ATV_REC_TIME_Y (10)
#define VAPP_ATV_REC_TIME_FONT_SIZE (13)

#define VAPP_ATV_REC_LEFT_BTN_X (97)
#define VAPP_ATV_REC_LEFT_BTN_W (63)
#define VAPP_ATV_REC_RIGHT_BTN_X (160)
#define VAPP_ATV_REC_RIGHT_BTN_W (68)
#define VAPP_ATV_REC_BTN_Y (192)

#define VAPP_ATV_THUMBNAIL_X (290)
#define VAPP_ATV_THUMBNAIL_Y (210)


#elif ((LCD_WIDTH == 240) && (LCD_HEIGHT == 400))

#define VAPP_ATV_ADJUST_BAR_Y   (116)
#define VAPP_ATV_ADJUST_BORDER_WIDTH  (20)
#define VAPP_ATV_ADJUST_TEXT_FONT_SIZE  (13)
#define VAPP_ATV_ADJUST_SLIDER_OFFSET   (16)

#ifndef __MMI_ATV_SLIM__
#define VAPP_ATV_WHEEL_CENT_TEXT_FONT_SIZE  (25)
#define VAPP_ATV_WHEEL_TEXT_FONT_SIZE  (18)
#define VAPP_ATV_WHEEL_RADIUS  (155)
#define VAPP_ATV_WHEEL_DEGREE  (16)
#define VAPP_ATV_WHEEL_ORIGIN_X  (480)
#define VAPP_ATV_WHEEL_BTN_X (377)
#define VAPP_ATV_WHEEL_BTN_UP_Y (71)
#define VAPP_ATV_WHEEL_BTN_DOWN_Y (150)
#define VAPP_ATV_WHEEL_BTN_WIDTH (30)
#define VAPP_ATV_WHEEL_BTN_HEIGHT (70)

#define VAPP_ATV_TBAR_BG_Y      (10)
#define VAPP_ATV_TBAR_BG_H      (220)
#define VAPP_ATV_TBAR_HANDLE_X  (33)
#define VAPP_ATV_TBAR_HANDLE_Y  (95)
#define VAPP_ATV_TBAR_LINE_X    (2)

#else
//WQVGA same as QVGA
// target frame font size
#define VAPP_ATV_WHEEL_SLIM_CENT_TEXT_FONT_SIZE  (24)
#define VAPP_ATV_WHEEL_SLIM_TEXT_FONT_SIZE  (18)

// BG frame 
#define VAPP_ATV_WHEEL_SLIM_BG_FRAME_WIDTH (50)
#define VAPP_ATV_WHEEL_SLIM_BG_FRAME_HEIGHT (184)
#define VAPP_ATV_WHEEL_SLIM_BG_Y  (26)
#define VAPP_ATV_WHEEL_SLIM_OFFSET_Y        (4)  //THE FRAME NEED START from -offset
#define VAPP_ATV_WHEEL_SLIM_OFFSET_DOUBLE_Y (8)  //the height of frame need add double offset

// BG line step
#define VAPP_ATV_WHEEL_SLIM_STEP_BIG    (38)
#define VAPP_ATV_WHEEL_SLIM_STEP_SMALL  (36)

// BG line pos.x
#define VAPP_ATV_WHEEL_SLIM_LINE_X    (5)
//center triangle
#define VAPP_ATV_WHEEL_SLIM_TARGET_FRAME_X (30)
#define VAPP_ATV_WHEEL_SLIM_CENTER_TRIANGGLE_X  (10)
#define VAPP_ATV_WHEEL_SLIM_CENTER_TRIANGGLE_Y  (92)

#define VAPP_ATV_TBAR_BG_GAP    (5)

#define VAPP_ATV_TBAR_BG_Y      (10)
#define VAPP_ATV_TBAR_BG_H      (220)
#define VAPP_ATV_TBAR_HANDLE_X  (33)
#define VAPP_ATV_TBAR_HANDLE_Y  (95)
#define VAPP_ATV_TBAR_LINE_X    (2)

#define VAPP_ATV_TOOLBAR_SLIM_WIDTH  (38)


#endif

#define VAPP_ATV_SIGNAL_X (37)
#define VAPP_ATV_SIGNAL_Y (6)
#define VAPP_ATV_REC_STATUS_X (323)
#define VAPP_ATV_REC_STATUS_Y (9)
#define VAPP_ATV_REC_TIME_X (344)
#define VAPP_ATV_REC_TIME_Y (10)
#define VAPP_ATV_REC_TIME_FONT_SIZE (13)

#define VAPP_ATV_REC_LEFT_BTN_X (137)
#define VAPP_ATV_REC_LEFT_BTN_W (63)
#define VAPP_ATV_REC_RIGHT_BTN_X (200)
#define VAPP_ATV_REC_RIGHT_BTN_W (68)
#define VAPP_ATV_REC_BTN_Y (192)

#define VAPP_ATV_THUMBNAIL_X (370)
#define VAPP_ATV_THUMBNAIL_Y (210)


#elif ((LCD_WIDTH == 320) && (LCD_HEIGHT == 480))

#define VAPP_ATV_ADJUST_BAR_Y   (156)
#define VAPP_ATV_ADJUST_BORDER_WIDTH  (20)
#define VAPP_ATV_ADJUST_TEXT_FONT_SIZE  (16)
#define VAPP_ATV_ADJUST_SLIDER_OFFSET   (10)

#ifndef __MMI_ATV_SLIM__
#define VAPP_ATV_WHEEL_CENT_TEXT_FONT_SIZE  (34)
#define VAPP_ATV_WHEEL_TEXT_FONT_SIZE  (24)
#define VAPP_ATV_WHEEL_RADIUS  (200)
#define VAPP_ATV_WHEEL_DEGREE  (17)
#define VAPP_ATV_WHEEL_ORIGIN_X  (582)
#define VAPP_ATV_WHEEL_BTN_X (450)
#define VAPP_ATV_WHEEL_BTN_UP_Y (95)
#define VAPP_ATV_WHEEL_BTN_DOWN_Y (200)
#define VAPP_ATV_WHEEL_BTN_WIDTH (38)
#define VAPP_ATV_WHEEL_BTN_HEIGHT (96)

#define VAPP_ATV_TBAR_BG_Y      (10)
#define VAPP_ATV_TBAR_BG_H      (300)
#define VAPP_ATV_TBAR_HANDLE_X  (45)
#define VAPP_ATV_TBAR_HANDLE_Y  (128)
#define VAPP_ATV_TBAR_LINE_X    (2)

#else
//HVGA
// target frame font size
#define VAPP_ATV_WHEEL_SLIM_CENT_TEXT_FONT_SIZE  (34)
#define VAPP_ATV_WHEEL_SLIM_TEXT_FONT_SIZE  (24)

// BG frame 
#define VAPP_ATV_WHEEL_SLIM_BG_FRAME_WIDTH (76)
#define VAPP_ATV_WHEEL_SLIM_BG_FRAME_HEIGHT (264)
#define VAPP_ATV_WHEEL_SLIM_BG_Y  (26)
#define VAPP_ATV_WHEEL_SLIM_OFFSET_Y        (4)  //THE FRAME NEED START from -offset
#define VAPP_ATV_WHEEL_SLIM_OFFSET_DOUBLE_Y (8)  //the height of frame need add double offset

// BG line step
#define VAPP_ATV_WHEEL_SLIM_STEP_BIG    (54)
#define VAPP_ATV_WHEEL_SLIM_STEP_SMALL  (52)

// BG line pos.x
#define VAPP_ATV_WHEEL_SLIM_LINE_X    (5)
//center triangle
#define VAPP_ATV_WHEEL_SLIM_TARGET_FRAME_X (38)
#define VAPP_ATV_WHEEL_SLIM_CENTER_TRIANGGLE_X  (10)
#define VAPP_ATV_WHEEL_SLIM_CENTER_TRIANGGLE_Y  (132)

#define VAPP_ATV_TBAR_BG_GAP    (14)

#define VAPP_ATV_TBAR_BG_Y      (10)
#define VAPP_ATV_TBAR_BG_H      (300)
#define VAPP_ATV_TBAR_HANDLE_X  (45)
#define VAPP_ATV_TBAR_HANDLE_Y  (128)
#define VAPP_ATV_TBAR_LINE_X    (2)
// toolbar width
#define VAPP_ATV_TOOLBAR_SLIM_WIDTH  (58)

#endif

#define VAPP_ATV_SIGNAL_X (47)
#define VAPP_ATV_SIGNAL_Y (6)
#define VAPP_ATV_REC_STATUS_X (392)
#define VAPP_ATV_REC_STATUS_Y (11)
#define VAPP_ATV_REC_TIME_X (413)
#define VAPP_ATV_REC_TIME_Y (12)
#define VAPP_ATV_REC_TIME_FONT_SIZE (14)

#define VAPP_ATV_REC_LEFT_BTN_X (163)
#define VAPP_ATV_REC_LEFT_BTN_W (85)
#define VAPP_ATV_REC_RIGHT_BTN_X (248)
#define VAPP_ATV_REC_RIGHT_BTN_W (90)
#define VAPP_ATV_REC_BTN_Y (255)

#define VAPP_ATV_THUMBNAIL_X (435)
#define VAPP_ATV_THUMBNAIL_Y (275)

#elif ((LCD_WIDTH == 480) && (LCD_HEIGHT == 800))

#define VAPP_ATV_ADJUST_BAR_Y   (228)
#define VAPP_ATV_ADJUST_BORDER_WIDTH  (40)
#define VAPP_ATV_ADJUST_TEXT_FONT_SIZE  (24)
#define VAPP_ATV_ADJUST_SLIDER_OFFSET   (35)

#ifndef __MMI_ATV_SLIM__
#define VAPP_ATV_WHEEL_CENT_TEXT_FONT_SIZE  (50)
#define VAPP_ATV_WHEEL_TEXT_FONT_SIZE  (36)
#define VAPP_ATV_WHEEL_RADIUS  (305)
#define VAPP_ATV_WHEEL_DEGREE  (16)
#define VAPP_ATV_WHEEL_ORIGIN_X  (954)
#define VAPP_ATV_WHEEL_BTN_X (755)
#define VAPP_ATV_WHEEL_BTN_UP_Y (142)
#define VAPP_ATV_WHEEL_BTN_DOWN_Y (300)
#define VAPP_ATV_WHEEL_BTN_WIDTH (62)
#define VAPP_ATV_WHEEL_BTN_HEIGHT (132)

#define VAPP_ATV_TBAR_BG_Y      (20)
#define VAPP_ATV_TBAR_BG_H      (440)
#define VAPP_ATV_TBAR_HANDLE_X  (65)
#define VAPP_ATV_TBAR_HANDLE_Y  (191)
#define VAPP_ATV_TBAR_LINE_X    (2)

#else
// WVGA same as HVGA
// target frame font size
#define VAPP_ATV_WHEEL_SLIM_CENT_TEXT_FONT_SIZE  (34)
#define VAPP_ATV_WHEEL_SLIM_TEXT_FONT_SIZE  (24)

// BG frame 
#define VAPP_ATV_WHEEL_SLIM_BG_FRAME_WIDTH (76)
#define VAPP_ATV_WHEEL_SLIM_BG_FRAME_HEIGHT (264)
#define VAPP_ATV_WHEEL_SLIM_BG_Y  (26)
#define VAPP_ATV_WHEEL_SLIM_OFFSET_Y        (4)  //THE FRAME NEED START from -offset
#define VAPP_ATV_WHEEL_SLIM_OFFSET_DOUBLE_Y (8)  //the height of frame need add double offset

// BG line step
#define VAPP_ATV_WHEEL_SLIM_STEP_BIG    (54)
#define VAPP_ATV_WHEEL_SLIM_STEP_SMALL  (52)

// BG line pos.x
#define VAPP_ATV_WHEEL_SLIM_LINE_X    (5)
//center triangle
#define VAPP_ATV_WHEEL_SLIM_TARGET_FRAME_X (38)
#define VAPP_ATV_WHEEL_SLIM_CENTER_TRIANGGLE_X  (10)
#define VAPP_ATV_WHEEL_SLIM_CENTER_TRIANGGLE_Y  (132)

#define VAPP_ATV_TBAR_BG_GAP    (14)

#define VAPP_ATV_TBAR_BG_Y      (10)
#define VAPP_ATV_TBAR_BG_H      (300)
#define VAPP_ATV_TBAR_HANDLE_X  (45)
#define VAPP_ATV_TBAR_HANDLE_Y  (128)
#define VAPP_ATV_TBAR_LINE_X    (2)
// toolbar width
#define VAPP_ATV_TOOLBAR_SLIM_WIDTH  (58)


#endif

#define VAPP_ATV_SIGNAL_X (90)
#define VAPP_ATV_SIGNAL_Y (6)
#define VAPP_ATV_REC_STATUS_X (667)
#define VAPP_ATV_REC_STATUS_Y (22)
#define VAPP_ATV_REC_TIME_X (703)
#define VAPP_ATV_REC_TIME_Y (20)
#define VAPP_ATV_REC_TIME_FONT_SIZE (21)

#define VAPP_ATV_REC_LEFT_BTN_X (286)
#define VAPP_ATV_REC_LEFT_BTN_W (126)
#define VAPP_ATV_REC_RIGHT_BTN_X (412)
#define VAPP_ATV_REC_RIGHT_BTN_W (135)
#define VAPP_ATV_REC_BTN_Y (384)

#define VAPP_ATV_THUMBNAIL_X (740)
#define VAPP_ATV_THUMBNAIL_Y (420)

#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */

#endif // __MMI_ATV_SUPPORT__
#endif /* __VAPP_ATV_OSD_H__ */
