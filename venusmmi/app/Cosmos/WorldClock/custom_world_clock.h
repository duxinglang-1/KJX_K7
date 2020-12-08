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
 * Custom_world_clock.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is worldclock lay out define.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef __CUSTOM_WORLD_CLOCK_H__
#define __CUSTOM_WORLD_CLOCK_H__

#define WC_SCREEN_WIDTH             LCD_WIDTH
#define WC_SCREEN_HEIGHT            LCD_HEIGHT
#define WC_SYM_COMMA    (VfxWChar)','
#define WC_SYM_POSITIVE (VfxWChar)'+'
#define WC_SYM_NEGATIVE (VfxWChar)'-'
#define WC_SYM_SPACE    (VfxWChar)' '
#define WC_FLOAT_CITY_NUM           20
#define WC_SHADOW_MIN_WIDTH         26     //9slice image width, if < this width,vrt will assert
#define WC_HOME_NORMAL_COLOR VfxColor(255, 255, 255, 255)
#define WC_HOME_LOWLIGHT_COLOR VfxColor(255, 191, 191, 191)
#define WC_FRN_NORMAL_COLOR VfxColor(255, 0, 0, 0)
#define WC_FRN_LOWLIGHT_COLOR VfxColor(255, 80, 80, 80)




#ifndef __LOW_COST_SUPPORT_COMMON__
#if defined(__MMI_MAINLCD_240X320__)

#define WC_MAP_WIDTH                582
#define WC_MAP_HEIGHT               296
#define WC_MAP_TOP_GAP              24
#define HALO_WIDTH                  56
#define HALO_HEIGHT                 56
#define WC_CLOCK_CENTER_X           41
#define WC_CLOCK_CENTER_Y           41
#define WC_SEARCH_BY_X_DISTANCE     35
#define WC_SEARCH_BY_POS_DISTANCE   20
#define WC_STATUS_BAR_HEIGHT        24
#define WC_PANEL_MID                getSize().width>>1
#define WC_HOME_PANEL_WIDTH         LCD_WIDTH
#define WC_HOME_PANEL_HEIGHT        94
#define WC_HOME_PANEL_X             0
#define WC_HOME_PANEL_Y             0
#define WC_HOME_CITY_X              77
#define WC_HOME_CITY_Y              18
#define WC_HOME_CITY_FONT_SIZE      VFX_FONT_DESC_VF_SIZE(14)
#define WC_HOME_DCLOCK_X            77
#define WC_HOME_DCLOCK_Y            46
#define WC_HOME_DCLOCK_WIDTH        100
#define WC_HOME_DCLOCK_HEIGHT       40
#define WC_HOME_DCLOCK_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(40)
#define WC_HOME_ACLOCK_X            154
#define WC_HOME_ACLOCK_Y            3
#define WC_HOME_DATE_X              95
#define WC_HOME_DATE_Y              67
#define WC_HOME_DATE_WIDTH          73
#define WC_HOME_DATE_HEIGHT         15
#define WC_HOME_DATE_FONT_SIZE      VFX_FONT_DESC_VF_SIZE(14)
#define WC_HOME_TZ_X                102
#define WC_HOME_TZ_Y                69
#define WC_HOME_TZ_FONT_SIZE        VFX_FONT_DESC_VF_SIZE(12)
#define WC_HOME_CITY_ICON_X         20
#define WC_HOME_CITY_ICON_Y         80
#define WC_HOME_AMPM_POS_X          127
#define WC_HOME_AMPM_POS_Y          47
#define WC_HOME_AMPM_FONT_SIZE      VFX_FONT_DESC_VF_SIZE(14)
#define WC_FOREIGN_PANEL_WIDTH      115
#define WC_FOREIGN_PANEL_HEIGHT     77
#define WC_FOREIGN_PANEL_1_X        3
#define WC_FOREIGN_PANEL_1_Y        216
#define WC_FOREIGN_PANEL_2_X        122
#define WC_FOREIGN_PANEL_2_Y        216
#define WC_FOREIGN_CITY_Y           8
#define WC_FOREIGN_CITY_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(13)
#define WC_FOREIGN_DCLOCK_Y         18
#define WC_FOREIGN_DCLOCK_WIDTH     63
#define WC_FOREIGN_DCLOCK_HEIGHT    32
#define WC_FOREIGN_DCLOCK_FONT_SIZE VFX_FONT_DESC_VF_SIZE(25)
#define WC_FOREIGN_DATE_Y           47
#define WC_FOREIGN_DATE_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(12)
#define WC_FOREIGN_TZ_Y             62
#define WC_FOREIGN_TZ_FONT_SIZE     VFX_FONT_DESC_VF_SIZE(12)
#define WC_FOREIGN_ADD_Y            57
#define WC_FOREIGN_ADD_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(14)
#define WC_FOREIGN_PLUS_Y           41
#define WC_FOREIGN_PLUS_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(48)
#define WC_FOREIGN_AMPM_POS_X       90
#define WC_FOREIGN_AMPM_POS_Y       34
#define WC_FOREIGN_AMPM_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(11)
#define WC_BUBBLE_WIDTH             286
#define WC_BUBBLE_HEIGHT            190
#define WC_BUBBLE_ACLOCK_POS_X      10
#define WC_BUBBLE_ACLOCK_POS_Y      20
#define WC_BUBBLE_DCLOCK_POS_X      119
#define WC_BUBBLE_DCLOCK_POS_Y      48
#define WC_BUBBLE_DCLOCK_WIDTH      133
#define WC_BUBBLE_DCLOCK_HEIGHT     55
#define WC_BUBBLE_DCLOCK_FONT_SIZE  VFX_FONT_DESC_VF_SIZE(52)
#define WC_BUBBLE_CITY_POS_X        127
#define WC_BUBBLE_CITY_POS_Y        26
#define WC_BUBBLE_CITY_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(18)
#define WC_BUBBLE_TZ_POS_X          127
#define WC_BUBBLE_TZ_POS_Y          102
#define WC_BUBBLE_TZ_FONT_SIZE      VFX_FONT_DESC_VF_SIZE(18)
#define WC_BUBBLE_BUTTON_POS_Y      WC_BUBBLE_HEIGHT -10
#define WC_BUBBLE_BUTTON_WIDTH      WC_BUBBLE_WIDTH - 2*10
#define WC_BUBBLE_BUTTON_HEIGHT     45
#define WC_BUBBLE_AMPM_POS_X        250
#define WC_BUBBLE_AMPM_POS_Y        77
#define WC_BUBBLE_AMPM_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(20)
#define WC_BACK_BUTTON_X            199
#define WC_BACK_BUTTON_Y            255
#define WC_LIST_BUTTON_X            206
#define WC_LIST_BUTTON_Y            179
#define WC_FLOAT_CITY_FONT_SIZE     VFX_FONT_DESC_VF_SIZE(9)
#define WC_FLOAT_CITY_FONT_SIZE2    VFX_FONT_DESC_VF_SIZE(9)
#define WC_FLOAT_CITY_WIDTH         45
#define WC_FLOAT_CITY_HEIGHT        15
#define WC_FLOAT_CITY_GAP           3
#define WC_FLOAT_CITY_STRING_LEN    64
#define WC_TZ_PANEL_WIDTH           105
#define WC_TZ_PANEL_HEIGHT          70
#define WC_TZ_PANEL_TZ_POS_Y        15
#define WC_TZ_PANEL_CLOCK_WIDTH     82
#define WC_TZ_PANEL_CLOCK_HEIGHT    27
#define WC_TZ_PANEL_CLOCK_FONT_SIZE VFX_FONT_DESC_VF_SIZE(30)
#define WC_TZ_PANEL_DATE_FONT_SIZE  VFX_FONT_DESC_VF_SIZE(13)
#define WC_TZ_PANEL_DATE_POS_Y      50
#define WC_TZ_PANEL_TZ_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(13)
#define WC_TZ_PANEL_AMPM_POS_X      85
#define WC_TZ_PANEL_AMPM_POS_Y      39
#define WC_TZ_PANEL_AMPM_FONT_SIZE  VFX_FONT_DESC_VF_SIZE(10)

#elif defined(__MMI_MAINLCD_240X400__)

#define WC_MAP_WIDTH                582
#define WC_MAP_HEIGHT               376
#define WC_MAP_TOP_GAP              24
#define HALO_WIDTH                  56
#define HALO_HEIGHT                 56
#define WC_CLOCK_CENTER_X           41
#define WC_CLOCK_CENTER_Y           41
#define WC_SEARCH_BY_X_DISTANCE     35
#define WC_SEARCH_BY_POS_DISTANCE   20
#define WC_STATUS_BAR_HEIGHT        24
#define WC_PANEL_MID                getSize().width>>1
#define WC_HOME_PANEL_WIDTH         LCD_WIDTH
#define WC_HOME_PANEL_HEIGHT        94
#define WC_HOME_PANEL_X             0
#define WC_HOME_PANEL_Y             0
#define WC_HOME_CITY_X              77
#define WC_HOME_CITY_Y              18
#define WC_HOME_CITY_FONT_SIZE      VFX_FONT_DESC_VF_SIZE(14)
#define WC_HOME_DCLOCK_X            77
#define WC_HOME_DCLOCK_Y            46
#define WC_HOME_DCLOCK_WIDTH        100
#define WC_HOME_DCLOCK_HEIGHT       40
#define WC_HOME_DCLOCK_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(40)
#define WC_HOME_ACLOCK_X            154
#define WC_HOME_ACLOCK_Y            3
#define WC_HOME_DATE_X              95
#define WC_HOME_DATE_Y              67
#define WC_HOME_DATE_WIDTH          73
#define WC_HOME_DATE_HEIGHT         15
#define WC_HOME_DATE_FONT_SIZE      VFX_FONT_DESC_VF_SIZE(14)
#define WC_HOME_TZ_X                102
#define WC_HOME_TZ_Y                69
#define WC_HOME_TZ_FONT_SIZE        VFX_FONT_DESC_VF_SIZE(12)
#define WC_HOME_CITY_ICON_X         20
#define WC_HOME_CITY_ICON_Y         80
#define WC_HOME_AMPM_POS_X          127
#define WC_HOME_AMPM_POS_Y          47
#define WC_HOME_AMPM_FONT_SIZE      VFX_FONT_DESC_VF_SIZE(14)
#define WC_FOREIGN_PANEL_WIDTH      115
#define WC_FOREIGN_PANEL_HEIGHT     77
#define WC_FOREIGN_PANEL_1_X        3
#define WC_FOREIGN_PANEL_1_Y        296
#define WC_FOREIGN_PANEL_2_X        122
#define WC_FOREIGN_PANEL_2_Y        296
#define WC_FOREIGN_CITY_Y           8
#define WC_FOREIGN_CITY_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(13)
#define WC_FOREIGN_DCLOCK_Y         18
#define WC_FOREIGN_DCLOCK_WIDTH     63
#define WC_FOREIGN_DCLOCK_HEIGHT    32
#define WC_FOREIGN_DCLOCK_FONT_SIZE VFX_FONT_DESC_VF_SIZE(25)
#define WC_FOREIGN_DATE_Y           47
#define WC_FOREIGN_DATE_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(12)
#define WC_FOREIGN_TZ_Y             62
#define WC_FOREIGN_TZ_FONT_SIZE     VFX_FONT_DESC_VF_SIZE(12)
#define WC_FOREIGN_ADD_Y            57
#define WC_FOREIGN_ADD_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(14)
#define WC_FOREIGN_PLUS_Y           41
#define WC_FOREIGN_PLUS_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(48)
#define WC_FOREIGN_AMPM_POS_X       90
#define WC_FOREIGN_AMPM_POS_Y       34
#define WC_FOREIGN_AMPM_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(11)
#define WC_BUBBLE_WIDTH             286
#define WC_BUBBLE_HEIGHT            190
#define WC_BUBBLE_ACLOCK_POS_X      10
#define WC_BUBBLE_ACLOCK_POS_Y      20
#define WC_BUBBLE_DCLOCK_POS_X      119
#define WC_BUBBLE_DCLOCK_POS_Y      48
#define WC_BUBBLE_DCLOCK_WIDTH      133
#define WC_BUBBLE_DCLOCK_HEIGHT     55
#define WC_BUBBLE_DCLOCK_FONT_SIZE  VFX_FONT_DESC_VF_SIZE(52)
#define WC_BUBBLE_CITY_POS_X        127
#define WC_BUBBLE_CITY_POS_Y        26
#define WC_BUBBLE_CITY_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(18)
#define WC_BUBBLE_TZ_POS_X          127
#define WC_BUBBLE_TZ_POS_Y          102
#define WC_BUBBLE_TZ_FONT_SIZE      VFX_FONT_DESC_VF_SIZE(18)
#define WC_BUBBLE_BUTTON_POS_Y      WC_BUBBLE_HEIGHT -10
#define WC_BUBBLE_BUTTON_WIDTH      WC_BUBBLE_WIDTH - 2*10
#define WC_BUBBLE_BUTTON_HEIGHT     45
#define WC_BUBBLE_AMPM_POS_X        250
#define WC_BUBBLE_AMPM_POS_Y        77
#define WC_BUBBLE_AMPM_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(20)
#define WC_BACK_BUTTON_X            199
#define WC_BACK_BUTTON_Y            335
#define WC_LIST_BUTTON_X            206
#define WC_LIST_BUTTON_Y            259
#define WC_FLOAT_CITY_FONT_SIZE     VFX_FONT_DESC_VF_SIZE(9)
#define WC_FLOAT_CITY_FONT_SIZE2    VFX_FONT_DESC_VF_SIZE(9)
#define WC_FLOAT_CITY_WIDTH         45
#define WC_FLOAT_CITY_HEIGHT        15
#define WC_FLOAT_CITY_GAP           3
#define WC_FLOAT_CITY_STRING_LEN    64
#define WC_TZ_PANEL_WIDTH           105
#define WC_TZ_PANEL_HEIGHT          70
#define WC_TZ_PANEL_TZ_POS_Y        15
#define WC_TZ_PANEL_CLOCK_WIDTH     82
#define WC_TZ_PANEL_CLOCK_HEIGHT    27
#define WC_TZ_PANEL_CLOCK_FONT_SIZE VFX_FONT_DESC_VF_SIZE(30)
#define WC_TZ_PANEL_DATE_FONT_SIZE  VFX_FONT_DESC_VF_SIZE(13)
#define WC_TZ_PANEL_DATE_POS_Y      50
#define WC_TZ_PANEL_TZ_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(13)
#define WC_TZ_PANEL_AMPM_POS_X      85
#define WC_TZ_PANEL_AMPM_POS_Y      39
#define WC_TZ_PANEL_AMPM_FONT_SIZE  VFX_FONT_DESC_VF_SIZE(10)

#elif defined(__MMI_MAINLCD_320X480__)

#define WC_MAP_WIDTH                710
#define WC_MAP_HEIGHT               456
#define WC_MAP_TOP_GAP              24
#define HALO_WIDTH                  56
#define HALO_HEIGHT                 56
#define WC_CLOCK_CENTER_X           52
#define WC_CLOCK_CENTER_Y           52
#define WC_SEARCH_BY_X_DISTANCE     35
#define WC_SEARCH_BY_POS_DISTANCE   20
#define WC_STATUS_BAR_HEIGHT        24
#define WC_PANEL_MID                getSize().width>>1
#define WC_HOME_PANEL_WIDTH         LCD_WIDTH
#define WC_HOME_PANEL_HEIGHT        122
#define WC_HOME_PANEL_X             0
#define WC_HOME_PANEL_Y             0
#define WC_HOME_CITY_X              109
#define WC_HOME_CITY_Y              26
#define WC_HOME_CITY_FONT_SIZE      VFX_FONT_DESC_VF_SIZE(16)
#define WC_HOME_DCLOCK_X            106
#define WC_HOME_DCLOCK_Y            60
#define WC_HOME_DCLOCK_WIDTH        120
#define WC_HOME_DCLOCK_HEIGHT       36
#define WC_HOME_DCLOCK_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(48)
#define WC_HOME_ACLOCK_X            211
#define WC_HOME_ACLOCK_Y            5
#define WC_HOME_DATE_X              120
#define WC_HOME_DATE_Y              86
#define WC_HOME_DATE_WIDTH          82
#define WC_HOME_DATE_HEIGHT         15
#define WC_HOME_DATE_FONT_SIZE      VFX_FONT_DESC_VF_SIZE(16)
#define WC_HOME_TZ_X                129
#define WC_HOME_TZ_Y                86
#define WC_HOME_TZ_FONT_SIZE        VFX_FONT_DESC_VF_SIZE(16)
#define WC_HOME_CITY_ICON_X         35
#define WC_HOME_CITY_ICON_Y         100
#define WC_HOME_AMPM_POS_X          168
#define WC_HOME_AMPM_POS_Y          57
#define WC_HOME_AMPM_FONT_SIZE      VFX_FONT_DESC_VF_SIZE(20)
#define WC_FOREIGN_PANEL_WIDTH      158
#define WC_FOREIGN_PANEL_HEIGHT     108
#define WC_FOREIGN_PANEL_1_X        3
#define WC_FOREIGN_PANEL_1_Y        353
#define WC_FOREIGN_PANEL_2_X        160
#define WC_FOREIGN_PANEL_2_Y        353
#define WC_FOREIGN_CITY_Y           8
#define WC_FOREIGN_CITY_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(14)
#define WC_FOREIGN_DCLOCK_Y         25
#define WC_FOREIGN_DCLOCK_WIDTH     85
#define WC_FOREIGN_DCLOCK_HEIGHT    32
#define WC_FOREIGN_DCLOCK_FONT_SIZE VFX_FONT_DESC_VF_SIZE(34)
#define WC_FOREIGN_DATE_Y           57
#define WC_FOREIGN_DATE_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(14)
#define WC_FOREIGN_TZ_Y             74
#define WC_FOREIGN_TZ_FONT_SIZE     VFX_FONT_DESC_VF_SIZE(14)
#define WC_FOREIGN_ADD_Y            65
#define WC_FOREIGN_ADD_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(16)
#define WC_FOREIGN_PLUS_Y           45
#define WC_FOREIGN_PLUS_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(75)
#define WC_FOREIGN_AMPM_POS_X       124
#define WC_FOREIGN_AMPM_POS_Y       38
#define WC_FOREIGN_AMPM_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(14)
#define WC_BUBBLE_WIDTH             286
#define WC_BUBBLE_HEIGHT            190
#define WC_BUBBLE_ACLOCK_POS_X      10
#define WC_BUBBLE_ACLOCK_POS_Y      20
#define WC_BUBBLE_DCLOCK_POS_X      119
#define WC_BUBBLE_DCLOCK_POS_Y      48
#define WC_BUBBLE_DCLOCK_WIDTH      133
#define WC_BUBBLE_DCLOCK_HEIGHT      55
#define WC_BUBBLE_DCLOCK_FONT_SIZE  VFX_FONT_DESC_VF_SIZE(52)
#define WC_BUBBLE_CITY_POS_X        127
#define WC_BUBBLE_CITY_POS_Y        26
#define WC_BUBBLE_CITY_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(18)
#define WC_BUBBLE_TZ_POS_X          127
#define WC_BUBBLE_TZ_POS_Y          102
#define WC_BUBBLE_TZ_FONT_SIZE      VFX_FONT_DESC_VF_SIZE(18)
#define WC_BUBBLE_BUTTON_POS_Y      WC_BUBBLE_HEIGHT -10
#define WC_BUBBLE_BUTTON_WIDTH      WC_BUBBLE_WIDTH - 2*10
#define WC_BUBBLE_BUTTON_HEIGHT     45
#define WC_BUBBLE_AMPM_POS_X        250
#define WC_BUBBLE_AMPM_POS_Y        77
#define WC_BUBBLE_AMPM_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(20)
#define WC_BACK_BUTTON_X            271
#define WC_BACK_BUTTON_Y            407
#define WC_LIST_BUTTON_X            274
#define WC_LIST_BUTTON_Y            310
#define WC_FLOAT_CITY_FONT_SIZE     VFX_FONT_DESC_VF_SIZE(12)
#define WC_FLOAT_CITY_FONT_SIZE2    VFX_FONT_DESC_VF_SIZE(12)
#define WC_FLOAT_CITY_WIDTH         60
#define WC_FLOAT_CITY_HEIGHT        20
#define WC_FLOAT_CITY_GAP           3
#define WC_FLOAT_CITY_STRING_LEN    85
#define WC_TZ_PANEL_WIDTH           145
#define WC_TZ_PANEL_HEIGHT          100
#define WC_TZ_PANEL_TZ_POS_Y        20
#define WC_TZ_PANEL_CLOCK_WIDTH     110
#define WC_TZ_PANEL_CLOCK_HEIGHT    40
#define WC_TZ_PANEL_CLOCK_FONT_SIZE VFX_FONT_DESC_VF_SIZE(45)
#define WC_TZ_PANEL_DATE_FONT_SIZE  VFX_FONT_DESC_VF_SIZE(18)
#define WC_TZ_PANEL_DATE_POS_Y      70
#define WC_TZ_PANEL_TZ_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(18)
#define WC_TZ_PANEL_AMPM_POS_X      120
#define WC_TZ_PANEL_AMPM_POS_Y      50
#define WC_TZ_PANEL_AMPM_FONT_SIZE  VFX_FONT_DESC_VF_SIZE(14)

#elif defined(__MMI_MAINLCD_480X800__)

#define WC_MAP_WIDTH                1180
#define WC_MAP_HEIGHT               762
#define WC_MAP_TOP_GAP              24
#define HALO_WIDTH                  97
#define HALO_HEIGHT                 97
#define WC_PANEL_MID                getSize().width>>1
#define WC_CLOCK_CENTER_X           81
#define WC_CLOCK_CENTER_Y           81
#define WC_SEARCH_BY_X_DISTANCE     60
#define WC_SEARCH_BY_POS_DISTANCE   30
#define WC_STATUS_BAR_HEIGHT        38
#define WC_HOME_PANEL_WIDTH         LCD_WIDTH
#define WC_HOME_PANEL_HEIGHT        185
#define WC_HOME_PANEL_X             0
#define WC_HOME_PANEL_Y             0 
#define WC_HOME_CITY_X              142
#define WC_HOME_CITY_Y              37
#define WC_HOME_CITY_FONT_SIZE      VFX_FONT_DESC_VF_SIZE(24)
#define WC_HOME_DCLOCK_X            150
#define WC_HOME_DCLOCK_Y            88
#define WC_HOME_DCLOCK_WIDTH        180
#define WC_HOME_DCLOCK_HEIGHT       80
#define WC_HOME_DCLOCK_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(72)
#define WC_HOME_ACLOCK_X            312
#define WC_HOME_ACLOCK_Y            5
#define WC_HOME_DATE_X              167
#define WC_HOME_DATE_Y              131
#define WC_HOME_DATE_WIDTH          120
#define WC_HOME_DATE_HEIGHT         20
#define WC_HOME_DATE_FONT_SIZE      VFX_FONT_DESC_VF_SIZE(24)
#define WC_HOME_TZ_X                180
#define WC_HOME_TZ_Y                128
#define WC_HOME_TZ_FONT_SIZE        VFX_FONT_DESC_VF_SIZE(24)
#define WC_HOME_CITY_ICON_X         44
#define WC_HOME_CITY_ICON_Y         150
#define WC_HOME_AMPM_POS_X          249
#define WC_HOME_AMPM_POS_Y          91
#define WC_HOME_AMPM_FONT_SIZE      VFX_FONT_DESC_VF_SIZE(24)
#define WC_FOREIGN_PANEL_WIDTH      234
#define WC_FOREIGN_PANEL_HEIGHT     157
#define WC_FOREIGN_PANEL_1_X        5
#define WC_FOREIGN_PANEL_1_Y        599
#define WC_FOREIGN_PANEL_2_X        241
#define WC_FOREIGN_PANEL_2_Y        599
#define WC_FOREIGN_CITY_Y           11
#define WC_FOREIGN_CITY_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(24)
#define WC_FOREIGN_DCLOCK_Y         36
#define WC_FOREIGN_DCLOCK_WIDTH     130
#define WC_FOREIGN_DCLOCK_HEIGHT    52
#define WC_FOREIGN_DCLOCK_FONT_SIZE VFX_FONT_DESC_VF_SIZE(50)
#define WC_FOREIGN_DATE_Y           90
#define WC_FOREIGN_DATE_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(23)
#define WC_FOREIGN_DATE_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(23)
#define WC_FOREIGN_TZ_Y             116
#define WC_FOREIGN_TZ_FONT_SIZE     VFX_FONT_DESC_VF_SIZE(23)
#define WC_FOREIGN_ADD_Y            88
#define WC_FOREIGN_ADD_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(25)
#define WC_FOREIGN_PLUS_Y           50
#define WC_FOREIGN_PLUS_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(127)
#define WC_FOREIGN_AMPM_POS_X       178
#define WC_FOREIGN_AMPM_POS_Y       63
#define WC_FOREIGN_AMPM_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(20)
#define WC_BUBBLE_WIDTH             446
#define WC_BUBBLE_HEIGHT            308
#define WC_BUBBLE_ACLOCK_POS_X      30
#define WC_BUBBLE_ACLOCK_POS_Y      43
#define WC_BUBBLE_DCLOCK_POS_X      212
#define WC_BUBBLE_DCLOCK_POS_Y      80
#define WC_BUBBLE_DCLOCK_FONT_SIZE  VFX_FONT_DESC_VF_SIZE(75)
#define WC_BUBBLE_DCLOCK_WIDTH      185
#define WC_BUBBLE_DCLOCK_HEIGHT      75
#define WC_BUBBLE_CITY_POS_X        222
#define WC_BUBBLE_CITY_POS_Y        45
#define WC_BUBBLE_CITY_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(24)
#define WC_BUBBLE_TZ_POS_X          222
#define WC_BUBBLE_TZ_POS_Y          154
#define WC_BUBBLE_TZ_FONT_SIZE      VFX_FONT_DESC_VF_SIZE(24)
#define WC_BUBBLE_BUTTON_POS_Y      WC_BUBBLE_HEIGHT -31
#define WC_BUBBLE_BUTTON_WIDTH      WC_BUBBLE_WIDTH - 2*21
#define WC_BUBBLE_BUTTON_HEIGHT     59
#define WC_BUBBLE_AMPM_POS_X        393
#define WC_BUBBLE_AMPM_POS_Y        120
#define WC_BUBBLE_AMPM_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(24)
#define WC_BACK_BUTTON_X            422
#define WC_BACK_BUTTON_Y            688
#define WC_LIST_BUTTON_X            413
#define WC_LIST_BUTTON_Y            532
#define WC_FLOAT_CITY_FONT_SIZE     VFX_FONT_DESC_VF_SIZE(12)
#define WC_FLOAT_CITY_FONT_SIZE2    VFX_FONT_DESC_VF_SIZE(12)
#define WC_FLOAT_CITY_WIDTH         60
#define WC_FLOAT_CITY_HEIGHT        20
#define WC_FLOAT_CITY_GAP           3
#define WC_FLOAT_CITY_STRING_LEN    85
#define WC_TZ_PANEL_WIDTH           195
#define WC_TZ_PANEL_HEIGHT          120
#define WC_TZ_PANEL_TZ_POS_Y        15
#define WC_TZ_PANEL_CLOCK_WIDTH     160
#define WC_TZ_PANEL_CLOCK_HEIGHT    72
#define WC_TZ_PANEL_CLOCK_FONT_SIZE VFX_FONT_DESC_VF_SIZE(65)
#define WC_TZ_PANEL_DATE_FONT_SIZE  VFX_FONT_DESC_VF_SIZE(26)
#define WC_TZ_PANEL_DATE_POS_Y      95
#define WC_TZ_PANEL_TZ_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(26)
#define WC_TZ_PANEL_AMPM_POS_X      165
#define WC_TZ_PANEL_AMPM_POS_Y      65
#define WC_TZ_PANEL_AMPM_FONT_SIZE  VFX_FONT_DESC_VF_SIZE(20)

#else

#define WC_MAP_WIDTH                1180
#define WC_MAP_HEIGHT               758
#define WC_MAP_TOP_GAP              24
#define HALO_WIDTH                  56
#define HALO_HEIGHT                 56
#define WC_CLOCK_CENTER_X           52
#define WC_CLOCK_CENTER_Y           52
#define WC_SEARCH_BY_X_DISTANCE     35
#define WC_SEARCH_BY_POS_DISTANCE   20
#define WC_STATUS_BAR_HEIGHT        24
#define WC_PANEL_MID                getSize().width>>1
#define WC_HOME_PANEL_WIDTH         LCD_WIDTH
#define WC_HOME_PANEL_HEIGHT        122
#define WC_HOME_PANEL_X             0
#define WC_HOME_PANEL_Y             0
#define WC_HOME_CITY_X              109
#define WC_HOME_CITY_Y              26
#define WC_HOME_CITY_FONT_SIZE      VFX_FONT_DESC_VF_SIZE(16)
#define WC_HOME_DCLOCK_X            106
#define WC_HOME_DCLOCK_Y            60
#define WC_HOME_DCLOCK_WIDTH        120
#define WC_HOME_DCLOCK_HEIGHT       36
#define WC_HOME_DCLOCK_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(48)
#define WC_HOME_ACLOCK_X            211
#define WC_HOME_ACLOCK_Y            5
#define WC_HOME_DATE_X              120
#define WC_HOME_DATE_Y              86
#define WC_HOME_DATE_FONT_SIZE      VFX_FONT_DESC_VF_SIZE(16)
#define WC_HOME_TZ_X                129
#define WC_HOME_TZ_Y                84
#define WC_HOME_TZ_FONT_SIZE        VFX_FONT_DESC_VF_SIZE(16)
#define WC_HOME_CITY_ICON_X         35
#define WC_HOME_CITY_ICON_Y         100
#define WC_HOME_AMPM_POS_X          168
#define WC_HOME_AMPM_POS_Y          57
#define WC_HOME_AMPM_FONT_SIZE      VFX_FONT_DESC_VF_SIZE(20)
#define WC_FOREIGN_PANEL_WIDTH      158
#define WC_FOREIGN_PANEL_HEIGHT     108
#define WC_FOREIGN_PANEL_1_X        3
#define WC_FOREIGN_PANEL_1_Y        353
#define WC_FOREIGN_PANEL_2_X        160
#define WC_FOREIGN_PANEL_2_Y        353
#define WC_FOREIGN_CITY_Y           8
#define WC_FOREIGN_CITY_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(14)
#define WC_FOREIGN_DCLOCK_Y         25
#define WC_FOREIGN_DCLOCK_WIDTH     85
#define WC_FOREIGN_DCLOCK_HEIGHT    32
#define WC_FOREIGN_DCLOCK_FONT_SIZE VFX_FONT_DESC_VF_SIZE(34)
#define WC_FOREIGN_DATE_Y           57
#define WC_HOME_DATE_WIDTH               40
#define WC_HOME_DATE_HEIGHT              15
#define WC_FOREIGN_DATE_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(14)
#define WC_FOREIGN_TZ_Y             74
#define WC_FOREIGN_TZ_FONT_SIZE     VFX_FONT_DESC_VF_SIZE(14)
#define WC_FOREIGN_ADD_Y            65
#define WC_FOREIGN_ADD_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(16)
#define WC_FOREIGN_PLUS_Y           45
#define WC_FOREIGN_PLUS_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(75)
#define WC_FOREIGN_AMPM_POS_X       124
#define WC_FOREIGN_AMPM_POS_Y       38
#define WC_FOREIGN_AMPM_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(14)
#define WC_BUBBLE_WIDTH             286
#define WC_BUBBLE_HEIGHT            190
#define WC_BUBBLE_ACLOCK_POS_X      10
#define WC_BUBBLE_ACLOCK_POS_Y      20
#define WC_BUBBLE_DCLOCK_POS_X      119
#define WC_BUBBLE_DCLOCK_POS_Y      48
#define WC_BUBBLE_DCLOCK_WIDTH      133
#define WC_BUBBLE_DCLOCK_HEIGHT      55
#define WC_BUBBLE_DCLOCK_FONT_SIZE  VFX_FONT_DESC_VF_SIZE(52)
#define WC_BUBBLE_CITY_POS_X        127
#define WC_BUBBLE_CITY_POS_Y        26
#define WC_BUBBLE_CITY_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(18)
#define WC_BUBBLE_TZ_POS_X          127
#define WC_BUBBLE_TZ_POS_Y          102
#define WC_BUBBLE_TZ_FONT_SIZE      VFX_FONT_DESC_VF_SIZE(18)
#define WC_BUBBLE_BUTTON_POS_Y      WC_BUBBLE_HEIGHT -10
#define WC_BUBBLE_BUTTON_WIDTH      WC_BUBBLE_WIDTH - 2*10
#define WC_BUBBLE_BUTTON_HEIGHT     45
#define WC_BUBBLE_AMPM_POS_X        250
#define WC_BUBBLE_AMPM_POS_Y        77
#define WC_BUBBLE_AMPM_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(20)
#define WC_BACK_BUTTON_X            271
#define WC_BACK_BUTTON_Y            407
#define WC_LIST_BUTTON_X            274
#define WC_LIST_BUTTON_Y            310
#define WC_FLOAT_CITY_FONT_SIZE     VFX_FONT_DESC_VF_SIZE(12)
#define WC_FLOAT_CITY_FONT_SIZE2    VFX_FONT_DESC_VF_SIZE(12)
#define WC_FLOAT_CITY_WIDTH         60
#define WC_FLOAT_CITY_HEIGHT        20
#define WC_FLOAT_CITY_GAP           3
#define WC_FLOAT_CITY_STRING_LEN    85
#define WC_TZ_PANEL_WIDTH           140
#define WC_TZ_PANEL_HEIGHT          100
#define WC_TZ_PANEL_TZ_POS_Y        20
#define WC_TZ_PANEL_CLOCK_WIDTH     110
#define WC_TZ_PANEL_CLOCK_HEIGHT    40
#define WC_TZ_PANEL_CLOCK_FONT_SIZE VFX_FONT_DESC_VF_SIZE(45)
#define WC_TZ_PANEL_DATE_FONT_SIZE  VFX_FONT_DESC_VF_SIZE(18)
#define WC_TZ_PANEL_DATE_POS_Y      70
#define WC_TZ_PANEL_TZ_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(18)
#define WC_TZ_PANEL_AMPM_POS_X      120
#define WC_TZ_PANEL_AMPM_POS_Y      50
#define WC_TZ_PANEL_AMPM_FONT_SIZE  VFX_FONT_DESC_VF_SIZE(14)

#endif /*__MMI_MAINLCD_320X480__*/

#else //__LOW_COST_SUPPORT_COMMON__
#if defined(__MMI_MAINLCD_240X320__)
#define WC_ITEM_HEIGHT 78
#define WC_CITYNAME_FONT VFX_FONT_DESC_VF_SIZE(15)
#define WC_CITYNAME_WIDTH 75
#define WC_CITYNAME_HEIGHT 12
#define WC_CITYNAME_POS_X 10
#define WC_CITYNAME_POS_Y 30
#define WC_DCLOCK_FONT VFX_FONT_DESC_VF_SIZE(22)
#define WC_DCLOCK_POS_X 93
#define WC_DCLOCK_POS_Y 17
#define WC_DCLOCK_WIDTH 54
#define WC_DCLOCK_HEIGHT 24
#define WC_DATE_POS_X 122
#define WC_DATE_POS_Y 45
#define WC_DATE_FONT VFX_FONT_DESC_VF_SIZE(13)
#define WC_DATE_WIDTH 70
#define WC_DATE_HEIGHT 11
#define WC_AMPM_POS_X 150
#define WC_AMPM_POS_Y 39
#define WC_AMPM_FONT VFX_FONT_DESC_VF_SIZE(13)
#define WC_ACLOCK_POS_X WC_SCREEN_WIDTH - 10
#define WC_ACLOCK_POS_Y 17
#define WC_ACLOCK_CENTER 21
#define WC_SEARCH_BY_POS_DISTANCE   20
#define WC_SEARCH_BY_X_DISTANCE     35
#define WC_HOME_ICON_POS_X 9
#define WC_HOME_ICON_POS_Y 10



#elif defined(__MMI_MAINLCD_240X400__)
#define WC_ITEM_HEIGHT 78
#define WC_CITYNAME_FONT VFX_FONT_DESC_VF_SIZE(15)
#define WC_CITYNAME_WIDTH 75
#define WC_CITYNAME_HEIGHT 12
#define WC_CITYNAME_POS_X 10
#define WC_CITYNAME_POS_Y 30
#define WC_DCLOCK_FONT VFX_FONT_DESC_VF_SIZE(22)
#define WC_DCLOCK_POS_X 93
#define WC_DCLOCK_POS_Y 17
#define WC_DCLOCK_WIDTH 54
#define WC_DCLOCK_HEIGHT 24
#define WC_DATE_POS_X 122
#define WC_DATE_POS_Y 45
#define WC_DATE_FONT VFX_FONT_DESC_VF_SIZE(13)
#define WC_DATE_WIDTH 70
#define WC_DATE_HEIGHT 11
#define WC_AMPM_POS_X 150
#define WC_AMPM_POS_Y 39
#define WC_AMPM_FONT VFX_FONT_DESC_VF_SIZE(13)
#define WC_ACLOCK_POS_X WC_SCREEN_WIDTH - 10
#define WC_ACLOCK_POS_Y 17
#define WC_ACLOCK_CENTER 21
#define WC_SEARCH_BY_POS_DISTANCE   20
#define WC_SEARCH_BY_X_DISTANCE     35
#define WC_HOME_ICON_POS_X 9
#define WC_HOME_ICON_POS_Y 10



#else
#define WC_ITEM_HEIGHT 96
#define WC_CITYNAME_FONT VFX_FONT_DESC_VF_SIZE(17)
#define WC_CITYNAME_WIDTH 95
#define WC_CITYNAME_HEIGHT 18
#define WC_CITYNAME_POS_X 14
#define WC_CITYNAME_POS_Y 38
#define WC_DCLOCK_FONT VFX_FONT_DESC_VF_SIZE(30)
#define WC_DCLOCK_POS_X 122
#define WC_DCLOCK_POS_Y 20
#define WC_DCLOCK_WIDTH 75
#define WC_DCLOCK_HEIGHT 34
#define WC_DATE_POS_X 160
#define WC_DATE_POS_Y 60
#define WC_DATE_FONT VFX_FONT_DESC_VF_SIZE(15)
#define WC_DATE_WIDTH 80
#define WC_DATE_HEIGHT 13
#define WC_AMPM_POS_X 200
#define WC_AMPM_POS_Y 50
#define WC_AMPM_FONT VFX_FONT_DESC_VF_SIZE(15)
#define WC_ACLOCK_POS_X WC_SCREEN_WIDTH - 14
#define WC_ACLOCK_POS_Y 17
#define WC_ACLOCK_CENTER 31
#define WC_SEARCH_BY_POS_DISTANCE   20
#define WC_SEARCH_BY_X_DISTANCE     35
#define WC_HOME_ICON_POS_X 12
#define WC_HOME_ICON_POS_Y 13

#endif/*__MMI_MAINLCD_320X480__*/





#endif//__LOW_COST_SUPPORT_COMMON__

#endif/*__CUSTOM_WORLD_CLOCK_H__*/
