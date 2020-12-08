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
 *	 resource_camera_skins.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Camera customization file.
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
#ifndef _CAMERA_SKIN_H_
#define _CAMERA_SKIN_H_

#include "MMIDataType.h"
#include "gdi_lcd_config.h"
#include "MMI_features.h"
#include "MMI_features_camera.h"
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)


/***************************************************************************** 
* Define
*****************************************************************************/
    /***************************************************************************** 
    * Customizable OSD Skin        
    * [128x128]
    * [128x160]
    * [176x220]
    * [240x320]    
    * [320x240]
    *****************************************************************************/
    
    
#if ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128) || (LCD_WIDTH == 64) && (LCD_HEIGHT == 48))
    /***************************************************************************** 
    * 
    * [128x128]
    * 
    *****************************************************************************/
        /****** background ******/
    #define BG_COLOR_R      0
    #define BG_COLOR_G      0
    #define BG_COLOR_B      0
        /****** title ******/
    #define IS_DRAW_MMI_TITLE_BAR           FALSE
    #define IS_DRAW_MMI_TITLE_CAPTION       FALSE
        /****** softkey layer ******/
    #ifdef __MMI_CAMERA_SIMPLE_UI__
        #define IS_DRAW_MMI_SOFTKEY         TRUE
        #define SK_TXT_R                    255
        #define SK_TXT_G                    255
        #define SK_TXT_B                    255
        #define SK_TXT_STYLE_R              0
        #define SK_TXT_STYLE_G              0
        #define SK_TXT_STYLE_B              0
        #define SK_TXT_STYLE                CAMERA_TEXT_STYLE_BORDER    
        
        #define LSK_IS_SHOW                 FALSE
        #define LSK_X                       2
        #define LSK_Y                       105
            
        #define RSK_IS_SHOW                 FALSE
        #define RSK_X                       103
        #define RSK_Y                       105
        
    #else   /*__MMI_CAMERA_SLIM__*/
        #define IS_DRAW_MMI_SOFTKEY         FALSE
        #define SK_TXT_R                    255
        #define SK_TXT_G                    255
        #define SK_TXT_B                    255
        #define SK_TXT_STYLE_R              0
        #define SK_TXT_STYLE_G              0
        #define SK_TXT_STYLE_B              0
        #define SK_TXT_STYLE                CAMERA_TEXT_STYLE_BORDER    
            
        #define LSK_IS_SHOW                 TRUE
        #define LSK_X                       2
        #define LSK_Y                       105
            
        #define RSK_IS_SHOW                 TRUE
        #define RSK_X                       103
        #define RSK_Y                       105
        
    #endif /*__MMI_CAMERA_SLIM__*/
        
        /****** status icons ******/
    #ifdef __MMI_CAMERA_SLIM__
        #define WB_IS_SHOW                  FALSE
        #define WB_X                        0
        #define WB_Y                        0
        
        #define FLASH_IS_SHOW               FALSE
        #define FLASH_X                     0
        #define FLASH_Y                     0
        
        #define LED_HIGHLIGHT_IS_SHOW       FALSE
        #define LED_HIGHLIGHT_X             0
        #define LED_HIGHLIGHT_Y             0
        
        #define EV_IS_SHOW                  FALSE
        #define EV_X                        0
        #define EV_Y                        0
        
        #define EV_INC_IS_SHOW              FALSE
        #define EV_INC_X                    36
        #define EV_INC_Y                    2
        
        #define EV_DEC_IS_SHOW              FALSE
        #define EV_DEC_X                    47
        #define EV_DEC_Y                    2
        
        #define NIGHT_IS_SHOW               FALSE
        #define NIGHT_X                     110
        #define NIGHT_Y                     2
        
        #define CLOSEUP_IS_SHOW             FALSE
        #define CLOSEUP_X                   0
        #define CLOSEUP_Y                   0
        
        #define IMAGE_SIZE_IS_SHOW          TRUE
        #define IMAGE_SIZE_X                5
        #define IMAGE_SIZE_Y                5
        
        #define IMAGE_QTY_IS_SHOW           FALSE
        #define IMAGE_QTY_X                 23
        #define IMAGE_QTY_Y                 3
        
        #define CONT_SHOT_IS_SHOW           FALSE
        #define CONT_SHOT_X                 53
        #define CONT_SHOT_Y                 2
        
        #define DELAY_TIMER_IS_SHOW         FALSE
        #define DELAY_TIMER_X               63
        #define DELAY_TIMER_Y               3
        
        #define STORAGE_IS_SHOW             FALSE
        #define STORAGE_X                   0
        #define STORAGE_Y                   0
        
        #define EFFECT_IS_SHOW              FALSE
        #define EFFECT_X                    0
        #define EFFECT_Y                    0
        
        #define AE_METER_IS_SHOW            FALSE
        #define AE_METER_X                  0
        #define AE_METER_Y                  0
        
        #define ISO_IS_SHOW                 FALSE
        #define ISO_X                       0
        #define ISO_Y                       0
        
        #define SCENE_MODE_IS_SHOW          FALSE
        #define SCENE_MODE_X                72
        #define SCENE_MODE_Y                2
        
        #define AF_MODE_IS_SHOW             FALSE
        #define AF_MODE_X                   0
        #define AF_MODE_Y                   0
        
        #define AF_METER_IS_SHOW            FALSE
        #define AF_METER_X                  0
        #define AF_METER_Y                  0
        
        #define ZOOM_MF_TOGGLE_IS_SHOW      FALSE
        #define ZOOM_MF_TOGGLE_X            0
        #define ZOOM_MF_TOGGLE_Y            0
        
        #define CAPTURE_IS_SHOW             TRUE
        #define CAPTURE_X                   54
        #define CAPTURE_Y                   105
        
        #define ZOOM_IS_SHOW                FALSE
        #define ZOOM_X                      60
        #define ZOOM_Y                      2
        
        #define ZOOM_INC_IS_SHOW            FALSE
        #define ZOOM_INC_X                  100
        #define ZOOM_INC_Y                  2
        
        #define ZOOM_DEC_IS_SHOW            FALSE
        #define ZOOM_DEC_X                  111
        #define ZOOM_DEC_Y                  2
        
        #define MMS_ICON_X                  54
        #define MMS_ICON_Y                  135
        
        #define LEFT_ARROW_IS_SHOW          FALSE
        #define LEFT_ARROW_X                2
        #define LEFT_ARROW_Y                126
        
        #define RIGHT_ARROW_IS_SHOW         FALSE
        #define RIGHT_ARROW_X               110
        #define RIGHT_ARROW_Y               126
        
        #define FLASH_CHARGE_IS_SHOW        FALSE
        #define FLASH_CHARGE_X              0
        #define FLASH_CHARGE_Y              0
        
    #else   /*__MMI_CAMERA_SLIM__*/
        #define WB_IS_SHOW                  FALSE
        #define WB_X                        0
        #define WB_Y                        0
        
        #define FLASH_IS_SHOW               TRUE
        #define FLASH_X                     43
        #define FLASH_Y                     3
        
        #define LED_HIGHLIGHT_IS_SHOW       TRUE
        #define LED_HIGHLIGHT_X             43
        #define LED_HIGHLIGHT_Y             3
        
        #define EV_IS_SHOW                  FALSE
        #define EV_X                        2
        #define EV_Y                        2
        
        #define EV_INC_IS_SHOW              FALSE
        #define EV_INC_X                    36
        #define EV_INC_Y                    2
        
        #define EV_DEC_IS_SHOW              FALSE
        #define EV_DEC_X                    47
        #define EV_DEC_Y                    2
        
        #define NIGHT_IS_SHOW               FALSE
        #define NIGHT_X                     110
        #define NIGHT_Y                     2
        
        #define CLOSEUP_IS_SHOW             FALSE
        #define CLOSEUP_X                   0
        #define CLOSEUP_Y                   0
        
        #define IMAGE_SIZE_IS_SHOW          TRUE
        #define IMAGE_SIZE_X                3
        #define IMAGE_SIZE_Y                3
        
        #define IMAGE_QTY_IS_SHOW           TRUE
        #define IMAGE_QTY_X                 23
        #define IMAGE_QTY_Y                 3
        
        #define CONT_SHOT_IS_SHOW           FALSE
        #define CONT_SHOT_X                 53
        #define CONT_SHOT_Y                 2
        
        #define DELAY_TIMER_IS_SHOW         TRUE
        #define DELAY_TIMER_X               63
        #define DELAY_TIMER_Y               3
        
        #define STORAGE_IS_SHOW             FALSE
        #define STORAGE_X                   0
        #define STORAGE_Y                   0
        
        #define EFFECT_IS_SHOW              FALSE
        #define EFFECT_X                    0
        #define EFFECT_Y                    0
        
        #define AE_METER_IS_SHOW            FALSE
        #define AE_METER_X                  0
        #define AE_METER_Y                  0
        
        #define ISO_IS_SHOW                 FALSE
        #define ISO_X                       0
        #define ISO_Y                       0
        
        #define SCENE_MODE_IS_SHOW          FALSE
        #define SCENE_MODE_X                72
        #define SCENE_MODE_Y                2
        
        #define AF_MODE_IS_SHOW             FALSE
        #define AF_MODE_X                   0
        #define AF_MODE_Y                   0
        
        #define AF_METER_IS_SHOW            FALSE
        #define AF_METER_X                  0
        #define AF_METER_Y                  0
        
        #define ZOOM_MF_TOGGLE_IS_SHOW      FALSE
        #define ZOOM_MF_TOGGLE_X            0
        #define ZOOM_MF_TOGGLE_Y            0
        
        #define CAPTURE_IS_SHOW             TRUE
        #define CAPTURE_X                   54
        #define CAPTURE_Y                   105
        
        #define ZOOM_IS_SHOW                FALSE
        #define ZOOM_X                      60
        #define ZOOM_Y                      2
        
        #define ZOOM_INC_IS_SHOW            FALSE
        #define ZOOM_INC_X                  100
        #define ZOOM_INC_Y                  2
        
        #define ZOOM_DEC_IS_SHOW            FALSE
        #define ZOOM_DEC_X                  111
        #define ZOOM_DEC_Y                  2
        
        #define MMS_ICON_X                  54
        #define MMS_ICON_Y                  135
        
        #define LEFT_ARROW_IS_SHOW          FALSE
        #define LEFT_ARROW_X                2
        #define LEFT_ARROW_Y                126
        
        #define RIGHT_ARROW_IS_SHOW         FALSE
        #define RIGHT_ARROW_X               110
        #define RIGHT_ARROW_Y               126
        
        #define FLASH_CHARGE_IS_SHOW        FALSE
        #define FLASH_CHARGE_X              0
        #define FLASH_CHARGE_Y              0
        
    #endif  /*__MMI_CAMERA_SLIM__*/
        
        /****** hint box ******/
    #define HINT_IS_SHOW                    FALSE
    #define HINT_X                          0
    #define HINT_Y                          33
    #define HINT_W                          128
    #define HINT_H                          50
        
    #define HINT_TXT_R                      255
    #define HINT_TXT_G                      255
    #define HINT_TXT_B                      255
    #define HINT_TXT_STYLE_R                0
    #define HINT_TXT_STYLE_G                0
    #define HINT_TXT_STYLE_B                0
    #define HINT_TXT_STYLE                  CAMERA_TEXT_STYLE_BORDER
    
#elif ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))
    /***************************************************************************** 
    * 
    * [128x160]
    * 
    *****************************************************************************/
        /****** background ******/
    #define BG_COLOR_R      0
    #define BG_COLOR_G      0
    #define BG_COLOR_B      0
        /****** title ******/
    #define IS_DRAW_MMI_TITLE_BAR           FALSE
    #define IS_DRAW_MMI_TITLE_CAPTION       FALSE
        /****** softkey layer ******/
    #ifdef __MMI_CAMERA_SIMPLE_UI__
        #define IS_DRAW_MMI_SOFTKEY         TRUE
        #define SK_TXT_R                    255
        #define SK_TXT_G                    255
        #define SK_TXT_B                    255
        #define SK_TXT_STYLE_R              0
        #define SK_TXT_STYLE_G              0
        #define SK_TXT_STYLE_B              0
        #define SK_TXT_STYLE                CAMERA_TEXT_STYLE_BORDER    
        
        #define LSK_IS_SHOW                 FALSE
        #define LSK_X                       2
        #define LSK_Y                       137
            
        #define RSK_IS_SHOW                 FALSE
        #define RSK_X                       103
        #define RSK_Y                       137
        
    #else   /*__MMI_CAMERA_SLIM__*/
        #define IS_DRAW_MMI_SOFTKEY         FALSE
        #define SK_TXT_R                    255
        #define SK_TXT_G                    255
        #define SK_TXT_B                    255
        #define SK_TXT_STYLE_R              0
        #define SK_TXT_STYLE_G              0
        #define SK_TXT_STYLE_B              0
        #define SK_TXT_STYLE                CAMERA_TEXT_STYLE_BORDER    
            
        #define LSK_IS_SHOW                 TRUE
        #define LSK_X                       2
        #define LSK_Y                       105
            
        #define RSK_IS_SHOW                 TRUE
        #define RSK_X                       103
        #define RSK_Y                       105
        
    #endif /*__MMI_CAMERA_SLIM__*/
        
        /****** status icons ******/
    #ifdef __MMI_CAMERA_SLIM__
        #define WB_IS_SHOW                  FALSE
        #define WB_X                        0
        #define WB_Y                        0
        
        #define FLASH_IS_SHOW               FALSE
        #define FLASH_X                     43
        #define FLASH_Y                     3
        
        #define LED_HIGHLIGHT_IS_SHOW       FALSE
        #define LED_HIGHLIGHT_X             43
        #define LED_HIGHLIGHT_Y             3
        
        #define EV_IS_SHOW                  FALSE
        #define EV_X                        2
        #define EV_Y                        2
        
        #define EV_INC_IS_SHOW              FALSE
        #define EV_INC_X                    36
        #define EV_INC_Y                    2
        
        #define EV_DEC_IS_SHOW              FALSE
        #define EV_DEC_X                    47
        #define EV_DEC_Y                    2
        
        #define NIGHT_IS_SHOW               FALSE
        #define NIGHT_X                     110
        #define NIGHT_Y                     2
        
        #define CLOSEUP_IS_SHOW             FALSE
        #define CLOSEUP_X                   0
        #define CLOSEUP_Y                   0
        
        #define IMAGE_SIZE_IS_SHOW          TRUE
        #define IMAGE_SIZE_X                3
        #define IMAGE_SIZE_Y                3
        
        #define IMAGE_QTY_IS_SHOW           FALSE
        #define IMAGE_QTY_X                 23
        #define IMAGE_QTY_Y                 3
        
        #define CONT_SHOT_IS_SHOW           FALSE
        #define CONT_SHOT_X                 53
        #define CONT_SHOT_Y                 2
        
        #define DELAY_TIMER_IS_SHOW         FALSE
        #define DELAY_TIMER_X               63
        #define DELAY_TIMER_Y               3
        
        #define STORAGE_IS_SHOW             FALSE
        #define STORAGE_X                   0
        #define STORAGE_Y                   0
        
        #define EFFECT_IS_SHOW              FALSE
        #define EFFECT_X                    0
        #define EFFECT_Y                    0
        
        #define AE_METER_IS_SHOW            FALSE
        #define AE_METER_X                  0
        #define AE_METER_Y                  0
        
        #define ISO_IS_SHOW                 FALSE
        #define ISO_X                       0
        #define ISO_Y                       0
        
        #define SCENE_MODE_IS_SHOW          FALSE
        #define SCENE_MODE_X                72
        #define SCENE_MODE_Y                2
        
        #define AF_MODE_IS_SHOW             FALSE
        #define AF_MODE_X                   0
        #define AF_MODE_Y                   0
        
        #define AF_METER_IS_SHOW            FALSE
        #define AF_METER_X                  0
        #define AF_METER_Y                  0
        
        #define ZOOM_MF_TOGGLE_IS_SHOW      FALSE
        #define ZOOM_MF_TOGGLE_X            0
        #define ZOOM_MF_TOGGLE_Y            0
        
        #define CAPTURE_IS_SHOW             TRUE
        #define CAPTURE_X                   56
        #define CAPTURE_Y                   138
        
        #define ZOOM_IS_SHOW                TRUE
        #define ZOOM_X                      72
        #define ZOOM_Y                      2
        
        #define ZOOM_INC_IS_SHOW            TRUE
        #define ZOOM_INC_X                  90
        #define ZOOM_INC_Y                  4
        
        #define ZOOM_DEC_IS_SHOW            TRUE
        #define ZOOM_DEC_X                  108
        #define ZOOM_DEC_Y                  4
        
        #define MMS_ICON_X                  54
        #define MMS_ICON_Y                  135
        
        #define LEFT_ARROW_IS_SHOW          FALSE
        #define LEFT_ARROW_X                2
        #define LEFT_ARROW_Y                126
        
        #define RIGHT_ARROW_IS_SHOW         FALSE
        #define RIGHT_ARROW_X               110
        #define RIGHT_ARROW_Y               126
        
        #define FLASH_CHARGE_IS_SHOW        FALSE
        #define FLASH_CHARGE_X              0
        #define FLASH_CHARGE_Y              0
        
    #else   /*__MMI_CAMERA_SLIM__*/
        #define WB_IS_SHOW                  FALSE
        #define WB_X                        0
        #define WB_Y                        0
        
        #define FLASH_IS_SHOW               TRUE
        #define FLASH_X                     43
        #define FLASH_Y                     3
        
        #define LED_HIGHLIGHT_IS_SHOW       TRUE
        #define LED_HIGHLIGHT_X             43
        #define LED_HIGHLIGHT_Y             3
        
        #define EV_IS_SHOW                  FALSE
        #define EV_X                        2
        #define EV_Y                        2
        
        #define EV_INC_IS_SHOW              FALSE
        #define EV_INC_X                    36
        #define EV_INC_Y                    2
        
        #define EV_DEC_IS_SHOW              FALSE
        #define EV_DEC_X                    47
        #define EV_DEC_Y                    2
        
        #define NIGHT_IS_SHOW               FALSE
        #define NIGHT_X                     110
        #define NIGHT_Y                     2
        
        #define CLOSEUP_IS_SHOW             FALSE
        #define CLOSEUP_X                   0
        #define CLOSEUP_Y                   0
        
        #define IMAGE_SIZE_IS_SHOW          TRUE
        #define IMAGE_SIZE_X                3
        #define IMAGE_SIZE_Y                3
        
        #define IMAGE_QTY_IS_SHOW           TRUE
        #define IMAGE_QTY_X                 23
        #define IMAGE_QTY_Y                 3
        
        #define CONT_SHOT_IS_SHOW           FALSE
        #define CONT_SHOT_X                 53
        #define CONT_SHOT_Y                 2
        
        #define DELAY_TIMER_IS_SHOW         TRUE
        #define DELAY_TIMER_X               63
        #define DELAY_TIMER_Y               3
        
        #define STORAGE_IS_SHOW             FALSE
        #define STORAGE_X                   0
        #define STORAGE_Y                   0
        
        #define EFFECT_IS_SHOW              FALSE
        #define EFFECT_X                    0
        #define EFFECT_Y                    0
        
        #define AE_METER_IS_SHOW            FALSE
        #define AE_METER_X                  0
        #define AE_METER_Y                  0
        
        #define ISO_IS_SHOW                 FALSE
        #define ISO_X                       0
        #define ISO_Y                       0
        
        #define SCENE_MODE_IS_SHOW          FALSE
        #define SCENE_MODE_X                72
        #define SCENE_MODE_Y                2
        
        #define AF_MODE_IS_SHOW             FALSE
        #define AF_MODE_X                   0
        #define AF_MODE_Y                   0
        
        #define AF_METER_IS_SHOW            FALSE
        #define AF_METER_X                  0
        #define AF_METER_Y                  0
        
        #define ZOOM_MF_TOGGLE_IS_SHOW      FALSE
        #define ZOOM_MF_TOGGLE_X            0
        #define ZOOM_MF_TOGGLE_Y            0
        
        #define CAPTURE_IS_SHOW             TRUE
        #define CAPTURE_X                   55
        #define CAPTURE_Y                   140
        
        #define ZOOM_IS_SHOW                FALSE
        #define ZOOM_X                      60
        #define ZOOM_Y                      2
        
        #define ZOOM_INC_IS_SHOW            FALSE
        #define ZOOM_INC_X                  100
        #define ZOOM_INC_Y                  2
        
        #define ZOOM_DEC_IS_SHOW            FALSE
        #define ZOOM_DEC_X                  111
        #define ZOOM_DEC_Y                  2
        
        #define MMS_ICON_X                  54
        #define MMS_ICON_Y                  139
        
        #define LEFT_ARROW_IS_SHOW          FALSE
        #define LEFT_ARROW_X                2
        #define LEFT_ARROW_Y                126
        
        #define RIGHT_ARROW_IS_SHOW         FALSE
        #define RIGHT_ARROW_X               110
        #define RIGHT_ARROW_Y               126
        
        #define FLASH_CHARGE_IS_SHOW        FALSE
        #define FLASH_CHARGE_X              0
        #define FLASH_CHARGE_Y              0
        
    #endif  /*__MMI_CAMERA_SLIM__*/
	#ifdef __MMI_CAMERA_4_OSD_LAYER__
	    #define OSD_REGION0_X               72
		#define OSD_REGION0_Y               2
		#define OSD_REGION0_WIDTH           64
		#define OSD_REGION0_HEIGHT          20
		#define OSD_REGION1_X               0
		#define OSD_REGION1_Y               138
		#define OSD_REGION1_WIDTH           128
		#define OSD_REGION1_HEIGHT          25
		#define OSD_REGION2_X               107
		#define OSD_REGION2_Y               20
		#define OSD_REGION2_WIDTH           20
		#define OSD_REGION2_HEIGHT          80
		#define OSD_REGION3_X               19
		#define OSD_REGION3_Y               55
		#define OSD_REGION3_WIDTH           90
		#define OSD_REGION3_HEIGHT          50
	#endif     
        /****** hint box ******/
	#ifdef __MMI_CAMERA_4_OSD_LAYER__
    #define HINT_IS_SHOW                    TRUE
    #define HINT_X                          19
    #define HINT_Y                          55
    #define HINT_W                          90
    #define HINT_H                          50
    #else
	#define HINT_IS_SHOW                    TRUE
    #define HINT_X                          0
    #define HINT_Y                          55
    #define HINT_W                          128
    #define HINT_H                          50
	#endif
    #define HINT_TXT_R                      255
    #define HINT_TXT_G                      255
    #define HINT_TXT_B                      255
    #define HINT_TXT_STYLE_R                0
    #define HINT_TXT_STYLE_G                0
    #define HINT_TXT_STYLE_B                0
    #define HINT_TXT_STYLE                  CAMERA_TEXT_STYLE_BORDER
#ifdef __CAMERA_OSD_HORIZONTAL__
        /****** softkey layer ******/
    #ifdef __MMI_CAMERA_SIMPLE_UI__
        #define LSK_X_270                       130
        #define LSK_Y_270                       100
            
        #define RSK_X_270                       130
        #define RSK_Y_270                       3
        
    #else   /*__MMI_CAMERA_SIMPLE_UI__*/
        #define LSK_X_270                       130
        #define LSK_Y_270                       100
            
        #define RSK_X_270                       194
        #define RSK_Y_270                       3
        
    #endif /*__MMI_CAMERA_SIMPLE_UI__*/
        
        /****** status icons ******/
    
        #define WB_X_270                        13
        #define WB_Y_270                        100
        
        #define FLASH_X_270                     33
        #define FLASH_Y_270                     100
        
        #define LED_HIGHLIGHT_X_270             33
        #define LED_HIGHLIGHT_Y_270             100
        
        #define EV_X_270                        3
        #define EV_Y_270                        3
        
        #define EV_INC_X_270                    67
        #define EV_INC_Y_270                    3
        
        #define EV_DEC_X_270                    47
        #define EV_DEC_Y_270                    3
        
        #define NIGHT_X_270                     43
        #define NIGHT_Y_270                     100
        
        #define CLOSEUP_X_270                   0
        #define CLOSEUP_Y_270                   0
        
        #define IMAGE_SIZE_X_270                3
        #define IMAGE_SIZE_Y_270                100
        
        #define IMAGE_QTY_X_270                 23
        #define IMAGE_QTY_Y_270                 100
        
        #define CONT_SHOT_X_270                 73
        #define CONT_SHOT_Y_270                 100
        
        #define DELAY_TIMER_X_270               53
        #define DELAY_TIMER_Y_270               100
        
        #define STORAGE_X_270                   155
        #define STORAGE_Y_270                   0
        
        #define EFFECT_X_270                    5
        #define EFFECT_Y_270                    3
        
        #define AE_METER_X_270                  0
        #define AE_METER_Y_270                  0
        
        #define ISO_X_270                       5
        #define ISO_Y_270                       0
        
        #define SCENE_MODE_X_270                5
        #define SCENE_MODE_Y_270                0
        
        #define AF_MODE_X_270                   0
        #define AF_MODE_Y_270                   0
        
        #define AF_METER_X_270                  0
        #define AF_METER_Y_270                  0
        
        #define ZOOM_MF_TOGGLE_X_270            0
        #define ZOOM_MF_TOGGLE_Y_270            0
        
        #define CAPTURE_X_270                   130
        #define CAPTURE_Y_270                   50
        
        #define ZOOM_X_270                      40
        #define ZOOM_Y_270                      4
    
#ifdef __MMI_CAMERA_SIMPLE_UI__
        #define ZOOM_INC_X_270                  60
        #define ZOOM_INC_Y_270                  6
        
        #define ZOOM_DEC_X_270                  76
        #define ZOOM_DEC_Y_270                  6
#else
        #define ZOOM_INC_X_270                  60
        #define ZOOM_INC_Y_270                  6
        
        #define ZOOM_DEC_X_270                  76
        #define ZOOM_DEC_Y_270                  6
    
#endif
    
        #define MMS_ICON_X_270                  130
        #define MMS_ICON_Y_270                  28
        
        #define LEFT_ARROW_X_270                5
        #define LEFT_ARROW_Y_270                106
        
        #define RIGHT_ARROW_X_270               90
        #define RIGHT_ARROW_Y_270               106
        
        #define FLASH_CHARGE_X_270              0
        #define FLASH_CHARGE_Y_270              0
    #ifdef __MMI_CAMERA_4_OSD_LAYER__
        #define OSD_REGION0_X_270               40
		#define OSD_REGION0_Y_270               3
		#define OSD_REGION0_WIDTH_270          	65
		#define OSD_REGION0_HEIGHT_270          20
		#define OSD_REGION1_X_270               110
		#define OSD_REGION1_Y_270               0
		#define OSD_REGION1_WIDTH_270           46
		#define OSD_REGION1_HEIGHT_270          128
		#define OSD_REGION2_X_270               0
		#define OSD_REGION2_Y_270               107
		#define OSD_REGION2_WIDTH_270           80
		#define OSD_REGION2_HEIGHT_270          20
		#define OSD_REGION3_X_270               20
		#define OSD_REGION3_Y_270               34
		#define OSD_REGION3_WIDTH_270           90
		#define OSD_REGION3_HEIGHT_270          50
	#endif    
        /****** hint box ******/
	#define HINT_X_270							20
	#define HINT_Y_270							34
    #define HINT_W_270                          90
    #define HINT_H_270                          50
        
#endif  /*__CAMERA_OSD_HORIZONTAL__*/      
#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
    /***************************************************************************** 
    * 
    * [176x220]
    * 
    *****************************************************************************/
        /****** background ******/
    #define BG_COLOR_R      0
    #define BG_COLOR_G      0
    #define BG_COLOR_B      0
        /****** title ******/
    #define IS_DRAW_MMI_TITLE_BAR           FALSE
    #define IS_DRAW_MMI_TITLE_CAPTION       FALSE
        /****** softkey layer ******/
    #ifdef __MMI_CAMERA_SIMPLE_UI__
        #define IS_DRAW_MMI_SOFTKEY         TRUE
        #define SK_TXT_R                    255
        #define SK_TXT_G                    255
        #define SK_TXT_B                    255
        #define SK_TXT_STYLE_R              0
        #define SK_TXT_STYLE_G              0
        #define SK_TXT_STYLE_B              0
        #define SK_TXT_STYLE                CAMERA_TEXT_STYLE_BORDER    
        
        #define LSK_IS_SHOW                 FALSE
        #define LSK_X                       3
        #define LSK_Y                       197
            
        #define RSK_IS_SHOW                 FALSE
        #define RSK_X                       150
        #define RSK_Y                       197
        
    #else   /*__MMI_CAMERA_SIMPLE_UI__*/
        #define IS_DRAW_MMI_SOFTKEY         FALSE
        #define SK_TXT_R                    255
        #define SK_TXT_G                    255
        #define SK_TXT_B                    255
        #define SK_TXT_STYLE_R              0
        #define SK_TXT_STYLE_G              0
        #define SK_TXT_STYLE_B              0
        #define SK_TXT_STYLE                CAMERA_TEXT_STYLE_BORDER    
            
        #define LSK_IS_SHOW                 TRUE
        #define LSK_X                       3
        #define LSK_Y                       197
            
        #define RSK_IS_SHOW                 TRUE
        #define RSK_X                       150
        #define RSK_Y                       197
        
    #endif /*__MMI_CAMERA_SIMPLE_UI__*/
        
        /****** status icons ******/
    #ifdef __MMI_CAMERA_SLIM__
        #define WB_IS_SHOW                  TRUE
        #define WB_X                        150
        #define WB_Y                        63
        
        #define FLASH_IS_SHOW               FALSE
        #define FLASH_X                     150
        #define FLASH_Y                     103
        
        #define LED_HIGHLIGHT_IS_SHOW       FALSE
        #define LED_HIGHLIGHT_X             150
        #define LED_HIGHLIGHT_Y             103
        
        #define EV_IS_SHOW                  FALSE
        #define EV_X                        3
        #define EV_Y                        3
        
        #define EV_INC_IS_SHOW              FALSE
        #define EV_INC_X                    67
        #define EV_INC_Y                    3
        
        #define EV_DEC_IS_SHOW              FALSE
        #define EV_DEC_X                    47
        #define EV_DEC_Y                    3
        
        #define NIGHT_IS_SHOW               FALSE
        #define NIGHT_X                     150
        #define NIGHT_Y                     63
        
        #define CLOSEUP_IS_SHOW             FALSE
        #define CLOSEUP_X                   0
        #define CLOSEUP_Y                   0
        
        #define IMAGE_SIZE_IS_SHOW          TRUE
        #define IMAGE_SIZE_X                150
        #define IMAGE_SIZE_Y                23
        
        #define IMAGE_QTY_IS_SHOW           TRUE
        #define IMAGE_QTY_X                 150
        #define IMAGE_QTY_Y                 43
        
        #define CONT_SHOT_IS_SHOW           FALSE
        #define CONT_SHOT_X                 150
        #define CONT_SHOT_Y                 143
        
        #define DELAY_TIMER_IS_SHOW         TRUE
        #define DELAY_TIMER_X               150
        #define DELAY_TIMER_Y               83
        
        #define STORAGE_IS_SHOW             FALSE
        #define STORAGE_X                   0
        #define STORAGE_Y                   0
        
        #define EFFECT_IS_SHOW              FALSE
        #define EFFECT_X                    150
        #define EFFECT_Y                    23
        
        #define AE_METER_IS_SHOW            FALSE
        #define AE_METER_X                  0
        #define AE_METER_Y                  0
        
        #define ISO_IS_SHOW                 FALSE
        #define ISO_X                       150
        #define ISO_Y                       83
        
        #define SCENE_MODE_IS_SHOW          FALSE
        #define SCENE_MODE_X                150
        #define SCENE_MODE_Y                123
        
        #define AF_MODE_IS_SHOW             FALSE
        #define AF_MODE_X                   0
        #define AF_MODE_Y                   0
        
        #define AF_METER_IS_SHOW            FALSE
        #define AF_METER_X                  0
        #define AF_METER_Y                  0
        
        #define ZOOM_MF_TOGGLE_IS_SHOW      FALSE
        #define ZOOM_MF_TOGGLE_X            0
        #define ZOOM_MF_TOGGLE_Y            0
        
        #define CAPTURE_IS_SHOW             TRUE
        #define CAPTURE_X                   77
        #define CAPTURE_Y                   196
        
        #define ZOOM_IS_SHOW                TRUE
        #define ZOOM_X                      115
        #define ZOOM_Y                      4
    
#ifdef __MMI_CAMERA_SIMPLE_UI__
        #define ZOOM_INC_IS_SHOW            TRUE
        #define ZOOM_INC_X                  133
        #define ZOOM_INC_Y                  6
        
        #define ZOOM_DEC_IS_SHOW            TRUE
        #define ZOOM_DEC_X                  151
        #define ZOOM_DEC_Y                  6
#else
        #define ZOOM_INC_IS_SHOW            TRUE
        #define ZOOM_INC_X                  133
        #define ZOOM_INC_Y                  6
        
        #define ZOOM_DEC_IS_SHOW            TRUE
        #define ZOOM_DEC_X                  151
        #define ZOOM_DEC_Y                  6
    
#endif
    
        #define MMS_ICON_X                  79
        #define MMS_ICON_Y                  203
        
        #define LEFT_ARROW_IS_SHOW          FALSE
        #define LEFT_ARROW_X                5
        #define LEFT_ARROW_Y                180
        
        #define RIGHT_ARROW_IS_SHOW         FALSE
        #define RIGHT_ARROW_X               151
        #define RIGHT_ARROW_Y               180
        
        #define FLASH_CHARGE_IS_SHOW        FALSE
        #define FLASH_CHARGE_X              0
        #define FLASH_CHARGE_Y              0
        
    #else   /*__MMI_CAMERA_SLIM__*/
        #define WB_IS_SHOW                  TRUE
        #define WB_X                        150
        #define WB_Y                        83
        
        #define FLASH_IS_SHOW               TRUE
        #define FLASH_X                     150
        #define FLASH_Y                     103
        
        #define LED_HIGHLIGHT_IS_SHOW       TRUE
        #define LED_HIGHLIGHT_X             150
        #define LED_HIGHLIGHT_Y             103
        
        #define EV_IS_SHOW                  TRUE
        #define EV_X                        3
        #define EV_Y                        3
        
        #define EV_INC_IS_SHOW              TRUE
        #define EV_INC_X                    67
        #define EV_INC_Y                    3
        
        #define EV_DEC_IS_SHOW              TRUE
        #define EV_DEC_X                    47
        #define EV_DEC_Y                    3
        
        #define NIGHT_IS_SHOW               TRUE
        #define NIGHT_X                     150
        #define NIGHT_Y                     63
        
        #define CLOSEUP_IS_SHOW             FALSE
        #define CLOSEUP_X                   0
        #define CLOSEUP_Y                   0
        
        #define IMAGE_SIZE_IS_SHOW          TRUE
        #define IMAGE_SIZE_X                150
        #define IMAGE_SIZE_Y                23
        
        #define IMAGE_QTY_IS_SHOW           TRUE
        #define IMAGE_QTY_X                 150
        #define IMAGE_QTY_Y                 43
        
        #define CONT_SHOT_IS_SHOW           TRUE
        #define CONT_SHOT_X                 150
        #define CONT_SHOT_Y                 143
        
        #define DELAY_TIMER_IS_SHOW         TRUE
        #define DELAY_TIMER_X               150
        #define DELAY_TIMER_Y               123
        
        #define STORAGE_IS_SHOW             FALSE
        #define STORAGE_X                   0
        #define STORAGE_Y                   0
        
        #define EFFECT_IS_SHOW              FALSE
        #define EFFECT_X                    150
        #define EFFECT_Y                    23
        
        #define AE_METER_IS_SHOW            FALSE
        #define AE_METER_X                  0
        #define AE_METER_Y                  0
        
        #define ISO_IS_SHOW                 FALSE
        #define ISO_X                       150
        #define ISO_Y                       83
        
        #define SCENE_MODE_IS_SHOW          FALSE
        #define SCENE_MODE_X                150
        #define SCENE_MODE_Y                123
        
        #define AF_MODE_IS_SHOW             FALSE
        #define AF_MODE_X                   0
        #define AF_MODE_Y                   0
        
        #define AF_METER_IS_SHOW            FALSE
        #define AF_METER_X                  0
        #define AF_METER_Y                  0
        
        #define ZOOM_MF_TOGGLE_IS_SHOW      FALSE
        #define ZOOM_MF_TOGGLE_X            0
        #define ZOOM_MF_TOGGLE_Y            0
        
        #define CAPTURE_IS_SHOW             TRUE
        #define CAPTURE_X                   77
        #define CAPTURE_Y                   197
        
        #define ZOOM_IS_SHOW                TRUE
        #define ZOOM_X                      115
        #define ZOOM_Y                      4
    
#ifdef __MMI_CAMERA_SIMPLE_UI__
        #define ZOOM_INC_IS_SHOW            TRUE
        #define ZOOM_INC_X                  138
        #define ZOOM_INC_Y                  7
        
        #define ZOOM_DEC_IS_SHOW            TRUE
        #define ZOOM_DEC_X                  161
        #define ZOOM_DEC_Y                  7
#else
        #define ZOOM_INC_IS_SHOW            TRUE
        #define ZOOM_INC_X                  138
        #define ZOOM_INC_Y                  7
        
        #define ZOOM_DEC_IS_SHOW            TRUE
        #define ZOOM_DEC_X                  161
        #define ZOOM_DEC_Y                  7
#endif
        
        #define MMS_ICON_X                  79
        #define MMS_ICON_Y                  203
        
        #define LEFT_ARROW_IS_SHOW          FALSE
        #define LEFT_ARROW_X                5
        #define LEFT_ARROW_Y                180
        
        #define RIGHT_ARROW_IS_SHOW         FALSE
        #define RIGHT_ARROW_X               151
        #define RIGHT_ARROW_Y               180
        
        #define FLASH_CHARGE_IS_SHOW        FALSE
        #define FLASH_CHARGE_X              0
        #define FLASH_CHARGE_Y              0
        
    #endif  /*__MMI_CAMERA_SLIM__*/
    #ifdef __MMI_CAMERA_4_OSD_LAYER__
        #define OSD_REGION0_X               110
		#define OSD_REGION0_Y               2
		#define OSD_REGION0_WIDTH           88
		#define OSD_REGION0_HEIGHT          20
		#define OSD_REGION1_X               0
		#define OSD_REGION1_Y               189
		#define OSD_REGION1_WIDTH           176
		#define OSD_REGION1_HEIGHT          30
		#define OSD_REGION2_X               150
		#define OSD_REGION2_Y               20
		#define OSD_REGION2_WIDTH           25
		#define OSD_REGION2_HEIGHT          180
		#define OSD_REGION3_X               30
		#define OSD_REGION3_Y               80
		#define OSD_REGION3_WIDTH           116
		#define OSD_REGION3_HEIGHT          60
	#endif   
        /****** hint box ******/
    #define HINT_IS_SHOW                    TRUE
    #define HINT_X                          30
    #define HINT_Y                          80
    #define HINT_W                          116
    #define HINT_H                          60
        
    #define HINT_TXT_R                      255
    #define HINT_TXT_G                      255
    #define HINT_TXT_B                      255
    #define HINT_TXT_STYLE_R                0
    #define HINT_TXT_STYLE_G                0
    #define HINT_TXT_STYLE_B                0
    #define HINT_TXT_STYLE                  CAMERA_TEXT_STYLE_BORDER
    
#ifdef __CAMERA_OSD_HORIZONTAL__
        /****** softkey layer ******/
    #ifdef __MMI_CAMERA_SIMPLE_UI__
        #define LSK_X_270                       194
        #define LSK_Y_270                       155
            
        #define RSK_X_270                       194
        #define RSK_Y_270                       3
        
    #else   /*__MMI_CAMERA_SIMPLE_UI__*/
        #define LSK_X_270                       194
        #define LSK_Y_270                       155
            
        #define RSK_X_270                       194
        #define RSK_Y_270                       3
        
    #endif /*__MMI_CAMERA_SIMPLE_UI__*/
        
        /****** status icons ******/
    
        #define WB_X_270                        63
        #define WB_Y_270                        153
        
        #define FLASH_X_270                     83
        #define FLASH_Y_270                     153
        
        #define LED_HIGHLIGHT_X_270             83
        #define LED_HIGHLIGHT_Y_270             153
        
        #define EV_X_270                        3
        #define EV_Y_270                        3
        
        #define EV_INC_X_270                    67
        #define EV_INC_Y_270                    3
        
        #define EV_DEC_X_270                    47
        #define EV_DEC_Y_270                    3
        
        #define NIGHT_X_270                     43
        #define NIGHT_Y_270                     153
        
        #define CLOSEUP_X_270                   0
        #define CLOSEUP_Y_270                   0
        
        #define IMAGE_SIZE_X_270                3
        #define IMAGE_SIZE_Y_270                153
        
        #define IMAGE_QTY_X_270                 23
        #define IMAGE_QTY_Y_270                 153
        
        #define CONT_SHOT_X_270                 123
        #define CONT_SHOT_Y_270                 153
        
        #define DELAY_TIMER_X_270               103
        #define DELAY_TIMER_Y_270               153
        
        #define STORAGE_X_270                   205
        #define STORAGE_Y_270                   0
        
        #define EFFECT_X_270                    5
        #define EFFECT_Y_270                    3
        
        #define AE_METER_X_270                  0
        #define AE_METER_Y_270                  0
        
        #define ISO_X_270                       5
        #define ISO_Y_270                       0
        
        #define SCENE_MODE_X_270                5
        #define SCENE_MODE_Y_270                0
        
        #define AF_MODE_X_270                   0
        #define AF_MODE_Y_270                   0
        
        #define AF_METER_X_270                  0
        #define AF_METER_Y_270                  0
        
        #define ZOOM_MF_TOGGLE_X_270            0
        #define ZOOM_MF_TOGGLE_Y_270            0
        
        #define CAPTURE_X_270                   194
        #define CAPTURE_Y_270                   78
        
        #define ZOOM_X_270                      100
        #define ZOOM_Y_270                      4
    
#ifdef __MMI_CAMERA_SIMPLE_UI__
        #define ZOOM_INC_X_270                  118
        #define ZOOM_INC_Y_270                  6
        
        #define ZOOM_DEC_X_270                  136
        #define ZOOM_DEC_Y_270                  6
#else
        #define ZOOM_INC_X_270                  117
        #define ZOOM_INC_Y_270                  6
        
        #define ZOOM_DEC_X_270                  134
        #define ZOOM_DEC_Y_270                  6
    
#endif
    
        #define MMS_ICON_X_270                  194
        #define MMS_ICON_Y_270                  78
        
        #define LEFT_ARROW_X_270                5
        #define LEFT_ARROW_Y_270                156
        
        #define RIGHT_ARROW_X_270               150
        #define RIGHT_ARROW_Y_270               156
        
        #define FLASH_CHARGE_X_270              0
        #define FLASH_CHARGE_Y_270              0
    #ifdef __MMI_CAMERA_4_OSD_LAYER__
        #define OSD_REGION0_X_270               100
		#define OSD_REGION0_Y_270               2
		#define OSD_REGION0_WIDTH_270          110
		#define OSD_REGION0_HEIGHT_270          20
		#define OSD_REGION1_X_270               169
		#define OSD_REGION1_Y_270               0
		#define OSD_REGION1_WIDTH_270           50
		#define OSD_REGION1_HEIGHT_270          176
		#define OSD_REGION2_X_270               0
		#define OSD_REGION2_Y_270               150
		#define OSD_REGION2_WIDTH_270           220
		#define OSD_REGION2_HEIGHT_270          25
		#define OSD_REGION3_X_270               45
		#define OSD_REGION3_Y_270               63
		#define OSD_REGION3_WIDTH_270           130
		#define OSD_REGION3_HEIGHT_270          50
	#endif    
        /****** hint box ******/
	#ifndef __MMI_CAMERA_4_OSD_LAYER__
    #define HINT_X_270                          30
    #define HINT_Y_270                          58
    #define HINT_W_270                          160
    #define HINT_H_270                          60
    #else
	#define HINT_X_270                          45
    #define HINT_Y_270                          63
    #define HINT_W_270                          130
    #define HINT_H_270                          50
	#endif
        
#endif  /*__CAMERA_OSD_HORIZONTAL__*/
    
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) ) || ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 240) )
    /***************************************************************************** 
    * 
    * [240x320]
    * 
    *****************************************************************************/
        /****** background ******/
    #define BG_COLOR_R      0
    #define BG_COLOR_G      0
    #define BG_COLOR_B      0
        /****** title ******/
    #define IS_DRAW_MMI_TITLE_BAR           FALSE
    #define IS_DRAW_MMI_TITLE_CAPTION       FALSE
        /****** softkey layer ******/
    #ifdef __MMI_CAMERA_SIMPLE_UI__
        #define IS_DRAW_MMI_SOFTKEY         TRUE
        #define SK_TXT_R                    255
        #define SK_TXT_G                    255
        #define SK_TXT_B                    255
        #define SK_TXT_STYLE_R              0
        #define SK_TXT_STYLE_G              0
        #define SK_TXT_STYLE_B              0
        #define SK_TXT_STYLE                CAMERA_TEXT_STYLE_BORDER    
        
        #define LSK_IS_SHOW                 FALSE
        #define LSK_X                       3
        #define LSK_Y                       287
            
        #define RSK_IS_SHOW                 FALSE
        #define RSK_X                       199
        #define RSK_Y                       287
        
    #else   /*__MMI_CAMERA_SIMPLE_UI__*/
        #define IS_DRAW_MMI_SOFTKEY         FALSE
        #define SK_TXT_R                    255
        #define SK_TXT_G                    255
        #define SK_TXT_B                    255
        #define SK_TXT_STYLE_R              0
        #define SK_TXT_STYLE_G              0
        #define SK_TXT_STYLE_B              0
        #define SK_TXT_STYLE                CAMERA_TEXT_STYLE_BORDER    
            
        #define LSK_IS_SHOW                 TRUE
        #define LSK_X                       3
        #define LSK_Y                       287
            
        #define RSK_IS_SHOW                 TRUE
        #define RSK_X                       199
        #define RSK_Y                       287
        
    #endif /*__MMI_CAMERA_SIMPLE_UI__*/
        
        /****** status icons ******/
        #define WB_IS_SHOW                  TRUE
        #define WB_X                        210
        #define WB_Y                        120
        
        #define FLASH_IS_SHOW               TRUE
        #define FLASH_X                     210
        #define FLASH_Y                     150
        
        #define LED_HIGHLIGHT_IS_SHOW       TRUE
        #define LED_HIGHLIGHT_X             210
        #define LED_HIGHLIGHT_Y             150
        
        #define EV_IS_SHOW                  TRUE
        #define EV_X                        3
        #define EV_Y                        3
        
        #define EV_INC_IS_SHOW              TRUE
        #define EV_INC_X                    68
        #define EV_INC_Y                    3
        
        #define EV_DEC_IS_SHOW              TRUE
        #define EV_DEC_X                    47
        #define EV_DEC_Y                    3
        
        #define NIGHT_IS_SHOW               TRUE
        #define NIGHT_X                     210
        #define NIGHT_Y                     90
        
        #define CLOSEUP_IS_SHOW             FALSE
        #define CLOSEUP_X                   0
        #define CLOSEUP_Y                   0
        
        #define IMAGE_SIZE_IS_SHOW          TRUE
        #define IMAGE_SIZE_X                210
        #define IMAGE_SIZE_Y                30
        
        #define IMAGE_QTY_IS_SHOW           TRUE
        #define IMAGE_QTY_X                 210
        #define IMAGE_QTY_Y                 60
        
        #define CONT_SHOT_IS_SHOW           TRUE
        #define CONT_SHOT_X                 210
        #define CONT_SHOT_Y                 210
        
        #define DELAY_TIMER_IS_SHOW         TRUE
        #define DELAY_TIMER_X               210
        #define DELAY_TIMER_Y               180
        
        #define STORAGE_IS_SHOW             FALSE
        #define STORAGE_X                   205
        #define STORAGE_Y                   79
        
        #define EFFECT_IS_SHOW              FALSE
        #define EFFECT_X                    150
        #define EFFECT_Y                    23
        
        #define AE_METER_IS_SHOW            FALSE
        #define AE_METER_X                  0
        #define AE_METER_Y                  0
        
        #define ISO_IS_SHOW                 FALSE
        #define ISO_X                       208
        #define ISO_Y                       110
        
        #define SCENE_MODE_IS_SHOW          FALSE
        #define SCENE_MODE_X                208
        #define SCENE_MODE_Y                165
        
        #define AF_MODE_IS_SHOW             FALSE
        #define AF_MODE_X                   0
        #define AF_MODE_Y                   0
        
        #define AF_METER_IS_SHOW            FALSE
        #define AF_METER_X                  208
        #define AF_METER_Y                  106
        
        #define ZOOM_MF_TOGGLE_IS_SHOW      FALSE
        #define ZOOM_MF_TOGGLE_X            5
        #define ZOOM_MF_TOGGLE_Y            188
        
        #define CAPTURE_IS_SHOW             TRUE
        #define CAPTURE_X                   105
        #define CAPTURE_Y                   290
        
        #define ZOOM_IS_SHOW                TRUE
        #define ZOOM_X                      147
        #define ZOOM_Y                      3
    
#ifdef __MMI_CAMERA_SIMPLE_UI__
        #define ZOOM_INC_IS_SHOW            TRUE
        #define ZOOM_INC_X                  170
        #define ZOOM_INC_Y                  6
				
        #define ZOOM_DEC_IS_SHOW            TRUE
        #define ZOOM_DEC_X                  195
        #define ZOOM_DEC_Y                  6
#else
        #define ZOOM_INC_IS_SHOW            TRUE
        #define ZOOM_INC_X                  192
        #define ZOOM_INC_Y                  3
        
        #define ZOOM_DEC_IS_SHOW            TRUE
        #define ZOOM_DEC_X                  213
        #define ZOOM_DEC_Y                  3
#endif
        
        #define MMS_ICON_X                  112
        #define MMS_ICON_Y                  290
        
        #define LEFT_ARROW_IS_SHOW          FALSE
        #define LEFT_ARROW_X                5
        #define LEFT_ARROW_Y                239
        
        #define RIGHT_ARROW_IS_SHOW         FALSE
        #define RIGHT_ARROW_X               214
        #define RIGHT_ARROW_Y               239
        
        #define FLASH_CHARGE_IS_SHOW        FALSE
        #define FLASH_CHARGE_X              142
        #define FLASH_CHARGE_Y              290
        
     #ifdef __MMI_CAMERA_4_OSD_LAYER__
        #define OSD_REGION0_X               100
		#define OSD_REGION0_Y               0
		#define OSD_REGION0_WIDTH           120
		#define OSD_REGION0_HEIGHT          20
		#define OSD_REGION1_X               0
		#define OSD_REGION1_Y               279
		#define OSD_REGION1_WIDTH           240
		#define OSD_REGION1_HEIGHT          36
		#define OSD_REGION2_X               209
		#define OSD_REGION2_Y               40
		#define OSD_REGION2_WIDTH           30
		#define OSD_REGION2_HEIGHT          240
		#define OSD_REGION3_X               40
		#define OSD_REGION3_Y               110
		#define OSD_REGION3_WIDTH           160
		#define OSD_REGION3_HEIGHT          70
	#endif   
        /****** hint box ******/
	#ifndef __MMI_CAMERA_4_OSD_LAYER__
    #define HINT_IS_SHOW                    TRUE
    #define HINT_X                          0
    #define HINT_Y                          110
    #define HINT_W                          240
    #define HINT_H                          70
	#else
	#define HINT_IS_SHOW                    TRUE
    #define HINT_X                          40
    #define HINT_Y                          110
    #define HINT_W                          160
    #define HINT_H                          70
	#endif
        
    #define HINT_TXT_R                      255
    #define HINT_TXT_G                      255
    #define HINT_TXT_B                      255
    #define HINT_TXT_STYLE_R                0
    #define HINT_TXT_STYLE_G                0
    #define HINT_TXT_STYLE_B                0
    #define HINT_TXT_STYLE                  CAMERA_TEXT_STYLE_BORDER
    
#ifdef __CAMERA_OSD_HORIZONTAL__
        /****** softkey layer ******/
    #ifdef __MMI_CAMERA_SIMPLE_UI__
        #define LSK_X_270                       279
        #define LSK_Y_270                       207
            
        #define RSK_X_270                       279
        #define RSK_Y_270                       3
        
    #else   /*__MMI_CAMERA_SIMPLE_UI__*/
        #define LSK_X_270                       279
        #define LSK_Y_270                       207
            
        #define RSK_X_270                       279
        #define RSK_Y_270                       3
        
    #endif /*__MMI_CAMERA_SIMPLE_UI__*/
        
        /****** status icons ******/
    
        #define WB_X_270                        93
        #define WB_Y_270                        210
        
        #define FLASH_X_270                     123
        #define FLASH_Y_270                     210
        
        #define LED_HIGHLIGHT_X_270             123
        #define LED_HIGHLIGHT_Y_270             210
        
        #define EV_X_270                        3
        #define EV_Y_270                        3
        
        #define EV_INC_X_270                    68
        #define EV_INC_Y_270                    3
        
        #define EV_DEC_X_270                    47
        #define EV_DEC_Y_270                    3
        
        #define NIGHT_X_270                     63
        #define NIGHT_Y_270                     153
        
        #define CLOSEUP_X_270                   0
        #define CLOSEUP_Y_270                   0
        
        #define IMAGE_SIZE_X_270                3
        #define IMAGE_SIZE_Y_270                210
        
        #define IMAGE_QTY_X_270                 33
        #define IMAGE_QTY_Y_270                 210
        
        #define CONT_SHOT_X_270                 183
        #define CONT_SHOT_Y_270                 210
        
        #define DELAY_TIMER_X_270               153
        #define DELAY_TIMER_Y_270               210
        
        #define STORAGE_X_270                   205
        #define STORAGE_Y_270                   79
        
        #define EFFECT_X_270                    5
        #define EFFECT_Y_270                    3
        
        #define AE_METER_X_270                  0
        #define AE_METER_Y_270                  0
        
        #define ISO_X_270                       5
        #define ISO_Y_270                       93
        
        #define SCENE_MODE_X_270                5
        #define SCENE_MODE_Y_270                153
        
        #define AF_MODE_X_270                   0
        #define AF_MODE_Y_270                   0
        
        #define AF_METER_X_270                  5
        #define AF_METER_Y_270                  93
        
        #define ZOOM_MF_TOGGLE_X_270            290
        #define ZOOM_MF_TOGGLE_Y_270            183
        
        #define CAPTURE_X_270                   283
        #define CAPTURE_Y_270                   106
        
        #define ZOOM_X_270                      120
        #define ZOOM_Y_270                      5
			
#ifdef __MMI_CAMERA_SIMPLE_UI__
        #define ZOOM_INC_X_270                  143
        #define ZOOM_INC_Y_270                  8
				
        #define ZOOM_DEC_X_270                  168
        #define ZOOM_DEC_Y_270                  8
#else
        #define ZOOM_INC_X_270                  143
        #define ZOOM_INC_Y_270                  8
				
        #define ZOOM_DEC_X_270                  168
        #define ZOOM_DEC_Y_270                  8
			
#endif
    
        #define MMS_ICON_X_270                  287
        #define MMS_ICON_Y_270                  112
        
        #define LEFT_ARROW_X_270                5
        #define LEFT_ARROW_Y_270                215
        
        #define RIGHT_ARROW_X_270               250
        #define RIGHT_ARROW_Y_270               215
        
        #define FLASH_CHARGE_X_270              290
        #define FLASH_CHARGE_Y_270              183
        
    #ifdef __MMI_CAMERA_4_OSD_LAYER__
        #define OSD_REGION0_X_270               100
		#define OSD_REGION0_Y_270               5
		#define OSD_REGION0_WIDTH_270          120
		#define OSD_REGION0_HEIGHT_270          25
		#define OSD_REGION1_X_270               239
		#define OSD_REGION1_Y_270               0
		#define OSD_REGION1_WIDTH_270           80
		#define OSD_REGION1_HEIGHT_270          240
		#define OSD_REGION2_X_270               40
		#define OSD_REGION2_Y_270               200
		#define OSD_REGION2_WIDTH_270           240
		#define OSD_REGION2_HEIGHT_270          30
		#define OSD_REGION3_X_270               80
		#define OSD_REGION3_Y_270               85
		#define OSD_REGION3_WIDTH_270           160
		#define OSD_REGION3_HEIGHT_270          70
	#endif    
        /****** hint box ******/
	#ifndef __MMI_CAMERA_4_OSD_LAYER__
	    #define HINT_X_270                          75
	    #define HINT_Y_270                          50
	    #define HINT_W_270                          170
	    #define HINT_H_270                          140
	#else
		#define HINT_X_270                          80
	    #define HINT_Y_270                          85
	    #define HINT_W_270                          160
	    #define HINT_H_270                          70
	#endif
#endif /*__CAMERA_OSD_HORIZONTAL__*/
    
#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
    /***************************************************************************** 
    * 
    * [320x240]
    * 
    *****************************************************************************/
        /****** background ******/
    #define BG_COLOR_R      0
    #define BG_COLOR_G      0
    #define BG_COLOR_B      0
        /****** title ******/
    #define IS_DRAW_MMI_TITLE_BAR           FALSE
    #define IS_DRAW_MMI_TITLE_CAPTION       FALSE
        /****** softkey layer ******/
    #ifdef __MMI_CAMERA_SIMPLE_UI__
        #define IS_DRAW_MMI_SOFTKEY         TRUE
        #define SK_TXT_R                    255
        #define SK_TXT_G                    255
        #define SK_TXT_B                    255
        #define SK_TXT_STYLE_R              0
        #define SK_TXT_STYLE_G              0
        #define SK_TXT_STYLE_B              0
        #define SK_TXT_STYLE                CAMERA_TEXT_STYLE_BORDER    
        
        #define LSK_IS_SHOW                 FALSE
        #define LSK_X                       3
        #define LSK_Y                       207
            
        #define RSK_IS_SHOW                 FALSE
        #define RSK_X                       279
        #define RSK_Y                       207
        
    #else   /*__MMI_CAMERA_SIMPLE_UI__*/
        #define IS_DRAW_MMI_SOFTKEY         FALSE
        #define SK_TXT_R                    255
        #define SK_TXT_G                    255
        #define SK_TXT_B                    255
        #define SK_TXT_STYLE_R              0
        #define SK_TXT_STYLE_G              0
        #define SK_TXT_STYLE_B              0
        #define SK_TXT_STYLE                CAMERA_TEXT_STYLE_BORDER    
            
        #define LSK_IS_SHOW                 TRUE
        #define LSK_X                       3
        #define LSK_Y                       207
            
        #define RSK_IS_SHOW                 TRUE
        #define RSK_X                       279
        #define RSK_Y                       207
        
    #endif /*__MMI_CAMERA_SIMPLE_UI__*/
        
        /****** status icons ******/
        #define WB_IS_SHOW                  TRUE
        #define WB_X                        288
        #define WB_Y                        93
        
        #define FLASH_IS_SHOW               TRUE
        #define FLASH_X                     288
        #define FLASH_Y                     123
        
        #define LED_HIGHLIGHT_IS_SHOW       TRUE
        #define LED_HIGHLIGHT_X             288
        #define LED_HIGHLIGHT_Y             123
        
        #define EV_IS_SHOW                  TRUE
        #define EV_X                        3
        #define EV_Y                        3
        
        #define EV_INC_IS_SHOW              TRUE
        #define EV_INC_X                    68
        #define EV_INC_Y                    3
        
        #define EV_DEC_IS_SHOW              TRUE
        #define EV_DEC_X                    47
        #define EV_DEC_Y                    3
        
        #define NIGHT_IS_SHOW               TRUE
        #define NIGHT_X                     288
        #define NIGHT_Y                     63
        
        #define CLOSEUP_IS_SHOW             FALSE
        #define CLOSEUP_X                   0
        #define CLOSEUP_Y                   0
        
        #define IMAGE_SIZE_IS_SHOW          TRUE
        #define IMAGE_SIZE_X                288
        #define IMAGE_SIZE_Y                3
        
        #define IMAGE_QTY_IS_SHOW           TRUE
        #define IMAGE_QTY_X                 288
        #define IMAGE_QTY_Y                 33
        
        #define CONT_SHOT_IS_SHOW           TRUE
        #define CONT_SHOT_X                 288
        #define CONT_SHOT_Y                 181
        
        #define DELAY_TIMER_IS_SHOW         TRUE
        #define DELAY_TIMER_X               288
        #define DELAY_TIMER_Y               153
        
        #define STORAGE_IS_SHOW             FALSE
        #define STORAGE_X                   0
        #define STORAGE_Y                   0
        
        #define EFFECT_IS_SHOW              FALSE
        #define EFFECT_X                    288
        #define EFFECT_Y                    13
        
        #define AE_METER_IS_SHOW            FALSE
        #define AE_METER_X                  0
        #define AE_METER_Y                  0
        
        #define ISO_IS_SHOW                 FALSE
        #define ISO_X                       0
        #define ISO_Y                       0
        
        #define SCENE_MODE_IS_SHOW          FALSE
        #define SCENE_MODE_X                288
        #define SCENE_MODE_Y                147
        
        #define AF_MODE_IS_SHOW             FALSE
        #define AF_MODE_X                   0
        #define AF_MODE_Y                   0
        
        #define AF_METER_IS_SHOW            FALSE
        #define AF_METER_X                  0
        #define AF_METER_Y                  0
        
        #define ZOOM_MF_TOGGLE_IS_SHOW      FALSE
        #define ZOOM_MF_TOGGLE_X            0
        #define ZOOM_MF_TOGGLE_Y            0
        
        #define CAPTURE_IS_SHOW             TRUE
        #define CAPTURE_X                   145
        #define CAPTURE_Y                   214
        
        #define ZOOM_IS_SHOW                TRUE
        #define ZOOM_X                      100
        #define ZOOM_Y                      3
    
#ifdef __MMI_CAMERA_SIMPLE_UI__
        #define ZOOM_INC_IS_SHOW            TRUE
        #define ZOOM_INC_X                  130
        #define ZOOM_INC_Y                  3
        
        #define ZOOM_DEC_IS_SHOW            TRUE
        #define ZOOM_DEC_X                  155
        #define ZOOM_DEC_Y                  3
#else
        #define ZOOM_INC_IS_SHOW            TRUE
        #define ZOOM_INC_X                  140
        #define ZOOM_INC_Y                  3
        
        #define ZOOM_DEC_IS_SHOW            TRUE
        #define ZOOM_DEC_X                  161
        #define ZOOM_DEC_Y                  3
#endif
        
        #define MMS_ICON_X                  145
        #define MMS_ICON_Y                  214
        
        #define LEFT_ARROW_IS_SHOW          FALSE
        #define LEFT_ARROW_X                5
        #define LEFT_ARROW_Y                5
        
        #define RIGHT_ARROW_IS_SHOW         FALSE
        #define RIGHT_ARROW_X               250
        #define RIGHT_ARROW_Y               5
        
        #define FLASH_CHARGE_IS_SHOW        FALSE
        #define FLASH_CHARGE_X              290
        #define FLASH_CHARGE_Y              183
        
   #ifdef __MMI_CAMERA_4_OSD_LAYER__
        #define OSD_REGION0_X               100
		#define OSD_REGION0_Y               2
		#define OSD_REGION0_WIDTH           160
		#define OSD_REGION0_HEIGHT          20
		#define OSD_REGION1_X               0
		#define OSD_REGION1_Y               200
		#define OSD_REGION1_WIDTH           320
		#define OSD_REGION1_HEIGHT          36
		#define OSD_REGION2_X               289
		#define OSD_REGION2_Y               0
		#define OSD_REGION2_WIDTH           30
		#define OSD_REGION2_HEIGHT          240
		#define OSD_REGION3_X               80
		#define OSD_REGION3_Y               85
		#define OSD_REGION3_WIDTH           160
		#define OSD_REGION3_HEIGHT          70
	#endif   
        /****** hint box ******/
	#ifndef __MMI_CAMERA_4_OSD_LAYER__
	#define HINT_IS_SHOW					TRUE
	#define HINT_X							75
	#define HINT_Y							50
	#define HINT_W							170
	#define HINT_H							140
	#else
	#define HINT_IS_SHOW                    TRUE
    #define HINT_X                          80
    #define HINT_Y                          85
    #define HINT_W                          160
    #define HINT_H                          70
	#endif
        
    #define HINT_TXT_R                      255
    #define HINT_TXT_G                      255
    #define HINT_TXT_B                      255
    #define HINT_TXT_STYLE_R                0
    #define HINT_TXT_STYLE_G                0
    #define HINT_TXT_STYLE_B                0
    #define HINT_TXT_STYLE                  CAMERA_TEXT_STYLE_BORDER
    
    
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 400))
    /***************************************************************************** 
    * 
    * [240x400]
    * 
    *****************************************************************************/
        /****** background ******/
    #define BG_COLOR_R      0
    #define BG_COLOR_G      0
    #define BG_COLOR_B      0
        /****** title ******/
    #define IS_DRAW_MMI_TITLE_BAR           FALSE
    #define IS_DRAW_MMI_TITLE_CAPTION       FALSE
        /****** softkey layer ******/
    #ifdef __MMI_CAMERA_SIMPLE_UI__
        #define IS_DRAW_MMI_SOFTKEY         TRUE
        #define SK_TXT_R                    255
        #define SK_TXT_G                    255
        #define SK_TXT_B                    255
        #define SK_TXT_STYLE_R              0
        #define SK_TXT_STYLE_G              0
        #define SK_TXT_STYLE_B              0
        #define SK_TXT_STYLE                CAMERA_TEXT_STYLE_BORDER    
        
        #define LSK_IS_SHOW                 FALSE
        #define LSK_X                       3
        #define LSK_Y                       367
            
        #define RSK_IS_SHOW                 FALSE
        #define RSK_X                       200
        #define RSK_Y                       367
        
    #else   /*__MMI_CAMERA_SIMPLE_UI__*/
        #define IS_DRAW_MMI_SOFTKEY         FALSE
        #define SK_TXT_R                    255
        #define SK_TXT_G                    255
        #define SK_TXT_B                    255
        #define SK_TXT_STYLE_R              0
        #define SK_TXT_STYLE_G              0
        #define SK_TXT_STYLE_B              0
        #define SK_TXT_STYLE                CAMERA_TEXT_STYLE_BORDER    
            
        #define LSK_IS_SHOW                 TRUE
        #define LSK_X                       3
        #define LSK_Y                       367
            
        #define RSK_IS_SHOW                 TRUE
        #define RSK_X                       200
        #define RSK_Y                       367
        
    #endif /*__MMI_CAMERA_SIMPLE_UI__*/
        
        /****** status icons ******/
        #define WB_IS_SHOW                  TRUE
        #define WB_X                        212
        #define WB_Y                        120
        
        #define FLASH_IS_SHOW               TRUE
        #define FLASH_X                     212
        #define FLASH_Y                     150
        
        #define LED_HIGHLIGHT_IS_SHOW       TRUE
        #define LED_HIGHLIGHT_X             212
        #define LED_HIGHLIGHT_Y             150
        
        #define EV_IS_SHOW                  TRUE
        #define EV_X                        3
        #define EV_Y                        3
        
        #define EV_INC_IS_SHOW              TRUE
        #define EV_INC_X                    68
        #define EV_INC_Y                    3
        
        #define EV_DEC_IS_SHOW              TRUE
        #define EV_DEC_X                    47
        #define EV_DEC_Y                    3
        
        #define NIGHT_IS_SHOW               TRUE
        #define NIGHT_X                     212
        #define NIGHT_Y                     90
        
        #define CLOSEUP_IS_SHOW             FALSE
        #define CLOSEUP_X                   0
        #define CLOSEUP_Y                   0
        
        #define IMAGE_SIZE_IS_SHOW          TRUE
        #define IMAGE_SIZE_X                212
        #define IMAGE_SIZE_Y                30
        
        #define IMAGE_QTY_IS_SHOW           TRUE
        #define IMAGE_QTY_X                 212
        #define IMAGE_QTY_Y                 60
        
        #define CONT_SHOT_IS_SHOW           TRUE
        #define CONT_SHOT_X                 212
        #define CONT_SHOT_Y                 210
        
        #define DELAY_TIMER_IS_SHOW         TRUE
        #define DELAY_TIMER_X               212
        #define DELAY_TIMER_Y               180
        
        #define STORAGE_IS_SHOW             FALSE
        #define STORAGE_X                   212
        #define STORAGE_Y                   0
        
        #define EFFECT_IS_SHOW              FALSE
        #define EFFECT_X                    212
        #define EFFECT_Y                    0
        
        #define AE_METER_IS_SHOW            FALSE
        #define AE_METER_X                  212
        #define AE_METER_Y                  0
        
        #define ISO_IS_SHOW                 FALSE
        #define ISO_X                       212
        #define ISO_Y                       0
        
        #define SCENE_MODE_IS_SHOW          FALSE
        #define SCENE_MODE_X                212
        #define SCENE_MODE_Y                0
        
        #define AF_MODE_IS_SHOW             FALSE
        #define AF_MODE_X                   212
        #define AF_MODE_Y                   0
        
        #define AF_METER_IS_SHOW            FALSE
        #define AF_METER_X                  212
        #define AF_METER_Y                  0
        
        #define ZOOM_MF_TOGGLE_IS_SHOW      FALSE
        #define ZOOM_MF_TOGGLE_X            212
        #define ZOOM_MF_TOGGLE_Y            0
        
        #define CAPTURE_IS_SHOW             TRUE
        #define CAPTURE_X                   105
        #define CAPTURE_Y                   369
        
        #define ZOOM_IS_SHOW                TRUE
        #define ZOOM_X                      152
        #define ZOOM_Y                      3
    
        #define ZOOM_INC_IS_SHOW            TRUE
        #define ZOOM_INC_X                  192
        #define ZOOM_INC_Y                  3
        
        #define ZOOM_DEC_IS_SHOW            TRUE
        #define ZOOM_DEC_X                  213
        #define ZOOM_DEC_Y                  3
        
        #define MMS_ICON_X                  105
        #define MMS_ICON_Y                  372
        
        #define LEFT_ARROW_IS_SHOW          FALSE
        #define LEFT_ARROW_X                0
        #define LEFT_ARROW_Y                0
        
        #define RIGHT_ARROW_IS_SHOW         FALSE
        #define RIGHT_ARROW_X               0
        #define RIGHT_ARROW_Y               0
        
        #define FLASH_CHARGE_IS_SHOW        FALSE
        #define FLASH_CHARGE_X              0
        #define FLASH_CHARGE_Y              0
        
    #ifdef __MMI_CAMERA_4_OSD_LAYER__
        #define OSD_REGION0_X               152
		#define OSD_REGION0_Y               2
		#define OSD_REGION0_WIDTH           120
		#define OSD_REGION0_HEIGHT          20
		#define OSD_REGION1_X               0
		#define OSD_REGION1_Y               360
		#define OSD_REGION1_WIDTH           240
		#define OSD_REGION1_HEIGHT          36
		#define OSD_REGION2_X               209
		#define OSD_REGION2_Y               0
		#define OSD_REGION2_WIDTH           30
		#define OSD_REGION2_HEIGHT          400
		#define OSD_REGION3_X               80
		#define OSD_REGION3_Y               165
		#define OSD_REGION3_WIDTH           160
		#define OSD_REGION3_HEIGHT          70
	#endif   
        /****** hint box ******/
	#ifndef __MMI_CAMERA_4_OSD_LAYER__
	#define HINT_IS_SHOW					TRUE
	#define HINT_X							0
	#define HINT_Y							110
	#define HINT_W							240
	#define HINT_H							70
	#else
	#define HINT_IS_SHOW                    TRUE
    #define HINT_X                          80
    #define HINT_Y                          165
    #define HINT_W                          160
    #define HINT_H                          70
	#endif 
    #define HINT_TXT_R                      255
    #define HINT_TXT_G                      255
    #define HINT_TXT_B                      255
    #define HINT_TXT_STYLE_R                0
    #define HINT_TXT_STYLE_G                0
    #define HINT_TXT_STYLE_B                0
    #define HINT_TXT_STYLE                  CAMERA_TEXT_STYLE_BORDER
    
#ifdef __CAMERA_OSD_HORIZONTAL__
        /****** softkey layer ******/
    #ifdef __MMI_CAMERA_SIMPLE_UI__
        #define LSK_X_270                       359
        #define LSK_Y_270                       207
            
        #define RSK_X_270                       359
        #define RSK_Y_270                       3
        
    #else   /*__MMI_CAMERA_SIMPLE_UI__*/
        #define LSK_X_270                       359
        #define LSK_Y_270                       207
            
        #define RSK_X_270                       359
        #define RSK_Y_270                       3
        
    #endif /*__MMI_CAMERA_SIMPLE_UI__*/
        
        /****** status icons ******/
    
        #define WB_X_270                        93
        #define WB_Y_270                        210
        
        #define FLASH_X_270                     123
        #define FLASH_Y_270                     210
        
        #define LED_HIGHLIGHT_X_270             123
        #define LED_HIGHLIGHT_Y_270             210
        
        #define EV_X_270                        3
        #define EV_Y_270                        3
        
        #define EV_INC_X_270                    68
        #define EV_INC_Y_270                    3
        
        #define EV_DEC_X_270                    47
        #define EV_DEC_Y_270                    3
        
        #define NIGHT_X_270                     63
        #define NIGHT_Y_270                     90
        
        #define CLOSEUP_X_270                   0
        #define CLOSEUP_Y_270                   0
        
        #define IMAGE_SIZE_X_270                3
        #define IMAGE_SIZE_Y_270                210
        
        #define IMAGE_QTY_X_270                 33
        #define IMAGE_QTY_Y_270                 210
        
        #define CONT_SHOT_X_270                 183
        #define CONT_SHOT_Y_270                 210
        
        #define DELAY_TIMER_X_270               153
        #define DELAY_TIMER_Y_270               210
        
        #define STORAGE_X_270                   0
        #define STORAGE_Y_270                   0
        
        #define EFFECT_X_270                    0
        #define EFFECT_Y_270                    0
        
        #define AE_METER_X_270                  0
        #define AE_METER_Y_270                  0
        
        #define ISO_X_270                       0
        #define ISO_Y_270                       0
        
        #define SCENE_MODE_X_270                0
        #define SCENE_MODE_Y_270                0
        
        #define AF_MODE_X_270                   0
        #define AF_MODE_Y_270                   0
        
        #define AF_METER_X_270                  0
        #define AF_METER_Y_270                  0
        
        #define ZOOM_MF_TOGGLE_X_270            0
        #define ZOOM_MF_TOGGLE_Y_270            0
        
        #define CAPTURE_X_270                   365
        #define CAPTURE_Y_270                   107
        
        #define ZOOM_X_270                      215
        #define ZOOM_Y_270                      3
    
        #define ZOOM_INC_X_270                  255
        #define ZOOM_INC_Y_270                  3
        
        #define ZOOM_DEC_X_270                  276
        #define ZOOM_DEC_Y_270                  3
    
        #define MMS_ICON_X_270                  365
        #define MMS_ICON_Y_270                  110
        
        #define LEFT_ARROW_X_270                0
        #define LEFT_ARROW_Y_270                0
        
        #define RIGHT_ARROW_X_270               0
        #define RIGHT_ARROW_Y_270               0
        
        #define FLASH_CHARGE_X_270              0
        #define FLASH_CHARGE_Y_270              0
    #ifdef __MMI_CAMERA_4_OSD_LAYER__
        #define OSD_REGION0_X_270               215
		#define OSD_REGION0_Y_270               2
		#define OSD_REGION0_WIDTH_270          160
		#define OSD_REGION0_HEIGHT_270          20
		#define OSD_REGION1_X_270               319
		#define OSD_REGION1_Y_270               0
		#define OSD_REGION1_WIDTH_270           80
		#define OSD_REGION1_HEIGHT_270          240
		#define OSD_REGION2_X_270               40
		#define OSD_REGION2_Y_270               200
		#define OSD_REGION2_WIDTH_270           320
		#define OSD_REGION2_HEIGHT_270          30
		#define OSD_REGION3_X_270               120
		#define OSD_REGION3_Y_270               85
		#define OSD_REGION3_WIDTH_270           160
		#define OSD_REGION3_HEIGHT_270          70
	#endif    
        /****** hint box ******/
	#ifndef __MMI_CAMERA_4_OSD_LAYER__
		#define HINT_X_270							75
		#define HINT_Y_270							70
		#define HINT_W_270							180
		#define HINT_H_270							70
	#else
		#define HINT_X_270                          120
	    #define HINT_Y_270                          85
	    #define HINT_W_270                          160
	    #define HINT_H_270                          70
	#endif
#endif /*__CAMERA_OSD_HORIZONTAL__*/
    
#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 480))
    /***************************************************************************** 
    * 
    * [320X480]
    * 
    *****************************************************************************/
        /****** background ******/
    #define BG_COLOR_R      0
    #define BG_COLOR_G      0
    #define BG_COLOR_B      0
        /****** title ******/
    #define IS_DRAW_MMI_TITLE_BAR           FALSE
    #define IS_DRAW_MMI_TITLE_CAPTION       FALSE
        /****** softkey layer ******/
    #ifdef __MMI_CAMERA_SIMPLE_UI__
        #define IS_DRAW_MMI_SOFTKEY         TRUE
        #define SK_TXT_R                    255
        #define SK_TXT_G                    255
        #define SK_TXT_B                    255
        #define SK_TXT_STYLE_R              0
        #define SK_TXT_STYLE_G              0
        #define SK_TXT_STYLE_B              0
        #define SK_TXT_STYLE                CAMERA_TEXT_STYLE_BORDER    
        
        #define LSK_IS_SHOW                 FALSE
        #define LSK_X                       0
        #define LSK_Y                       0
            
        #define RSK_IS_SHOW                 FALSE
        #define RSK_X                       0
        #define RSK_Y                       0
        
    #else   /*__MMI_CAMERA_SIMPLE_UI__*/
        #define IS_DRAW_MMI_SOFTKEY         FALSE
        #define SK_TXT_R                    255
        #define SK_TXT_G                    255
        #define SK_TXT_B                    255
        #define SK_TXT_STYLE_R              0
        #define SK_TXT_STYLE_G              0
        #define SK_TXT_STYLE_B              0
        #define SK_TXT_STYLE                CAMERA_TEXT_STYLE_BORDER    
            
        #define LSK_IS_SHOW                 TRUE
        #define LSK_X                       5
        #define LSK_Y                       453
            
        #define RSK_IS_SHOW                 TRUE
        #define RSK_X                       269
        #define RSK_Y                       453
        
    #endif /*__MMI_CAMERA_SIMPLE_UI__*/
        
        /****** status icons ******/
        #define WB_IS_SHOW                  TRUE
        #define WB_X                        284
        #define WB_Y                        224
    
    #if defined(__CAMERA_FEATURE_LED_HIGHLIGHT__)
        #define FLASH_IS_SHOW               FALSE
        #define FLASH_X                     284
        #define FLASH_Y                     167
        
        #define LED_HIGHLIGHT_IS_SHOW       TRUE
        #define LED_HIGHLIGHT_X             284
        #define LED_HIGHLIGHT_Y             281
    #elif defined(__CAMERA_FEATURE_FLASH__)
        #define FLASH_IS_SHOW               TRUE
        #define FLASH_X                     284
        #define FLASH_Y                     167
        
        #define LED_HIGHLIGHT_IS_SHOW       FALSE
        #define LED_HIGHLIGHT_X             284
        #define LED_HIGHLIGHT_Y             281
    #else
        #define FLASH_IS_SHOW               FALSE
        #define FLASH_X                     284
        #define FLASH_Y                     167
        
        #define LED_HIGHLIGHT_IS_SHOW       FALSE
        #define LED_HIGHLIGHT_X             284
        #define LED_HIGHLIGHT_Y             281
    #endif

	#if defined(__CAMERA_FEATURE_FTE_SUPPORT__)
		#define EV_IS_SHOW                  false
		#define EV_X                        0
        #define EV_Y                        0
	#else
        #define EV_IS_SHOW                  true
        #define EV_X                        5
        #define EV_Y                        5
	#endif        

	#if defined(__CAMERA_FEATURE_FTE_SUPPORT__)
		#define EV_INC_IS_SHOW              false
		#define EV_INC_X                    0
        #define EV_INC_Y                    0
	#else
        #define EV_INC_IS_SHOW              true
        #define EV_INC_X                    70
        #define EV_INC_Y                    5
	#endif        

	#if defined(__CAMERA_FEATURE_FTE_SUPPORT__)
		#define EV_DEC_IS_SHOW              false
		#define EV_DEC_X                    0
        #define EV_DEC_Y                    0
	#else
        #define EV_DEC_IS_SHOW              true
        #define EV_DEC_X                    55
        #define EV_DEC_Y                    5
	#endif        
        
        #define NIGHT_IS_SHOW               FALSE
        #define NIGHT_X                     0
        #define NIGHT_Y                     0
        
        #define CLOSEUP_IS_SHOW             FALSE
        #define CLOSEUP_X                   0
        #define CLOSEUP_Y                   0
        
        #define IMAGE_SIZE_IS_SHOW          TRUE
        #define IMAGE_SIZE_X                284
        #define IMAGE_SIZE_Y                51
        
        #define IMAGE_QTY_IS_SHOW           TRUE
        #define IMAGE_QTY_X                 284
        #define IMAGE_QTY_Y                 108
        
        #define CONT_SHOT_IS_SHOW           TRUE
        #define CONT_SHOT_X                 284
        #define CONT_SHOT_Y                 395
        
    #ifdef __CAMERA_FEATURE_ISO_SUPPORT__
        #define DELAY_TIMER_IS_SHOW         FALSE
        #define DELAY_TIMER_X               0
        #define DELAY_TIMER_Y               0
    #else
        #define DELAY_TIMER_IS_SHOW         TRUE
        #define DELAY_TIMER_X               284
        #define DELAY_TIMER_Y               338
    #endif
        
        #define STORAGE_IS_SHOW             FALSE
        #define STORAGE_X                   0
        #define STORAGE_Y                   0
        
        #define EFFECT_IS_SHOW              FALSE
        #define EFFECT_X                    0
        #define EFFECT_Y                    0
        
        #define AE_METER_IS_SHOW            FALSE
        #define AE_METER_X                  0
        #define AE_METER_Y                  0
        
        #define ISO_IS_SHOW                 FALSE
        #define ISO_X                       0
        #define ISO_Y                       0
        
        #define SCENE_MODE_IS_SHOW          FALSE
        #define SCENE_MODE_X                0
        #define SCENE_MODE_Y                0
        
        #define AF_MODE_IS_SHOW             FALSE
        #define AF_MODE_X                   0
        #define AF_MODE_Y                   0
        
        #define AF_METER_IS_SHOW            FALSE
        #define AF_METER_X                  0
        #define AF_METER_Y                  0
        
        #define ZOOM_MF_TOGGLE_IS_SHOW      FALSE
        #define ZOOM_MF_TOGGLE_X            0
        #define ZOOM_MF_TOGGLE_Y            0
        
        #define CAPTURE_IS_SHOW             TRUE
        #define CAPTURE_X                   144
        #define CAPTURE_Y                   443

	#if defined(__CAMERA_FEATURE_FTE_SUPPORT__)
        #define ZOOM_IS_SHOW                TRUE
        #define ZOOM_X                      184
        #define ZOOM_Y 						5
    #else
        #define ZOOM_IS_SHOW                TRUE
        #define ZOOM_X                      235
        #define ZOOM_Y 						5
    #endif
	
	#if defined(__CAMERA_FEATURE_FTE_SUPPORT__)
		#define ZOOM_INC_IS_SHOW            TRUE
        #define ZOOM_INC_X                  184
        #define ZOOM_INC_Y                  5
	#else
        #define ZOOM_INC_IS_SHOW            TRUE
        #define ZOOM_INC_X                  300
        #define ZOOM_INC_Y                  5
    #endif
        
    #if defined(__CAMERA_FEATURE_FTE_SUPPORT__)
        #define ZOOM_DEC_IS_SHOW            TRUE
        #define ZOOM_DEC_X                  246
        #define ZOOM_DEC_Y                  5
    #else
    	#define ZOOM_DEC_IS_SHOW            TRUE
        #define ZOOM_DEC_X                  285
        #define ZOOM_DEC_Y                  5
    #endif
        
        #define MMS_ICON_X                  112
        #define MMS_ICON_Y                  370
        
        #define LEFT_ARROW_IS_SHOW          FALSE
        #define LEFT_ARROW_X                0
        #define LEFT_ARROW_Y                0
        
        #define RIGHT_ARROW_IS_SHOW         FALSE
        #define RIGHT_ARROW_X               0
        #define RIGHT_ARROW_Y               0
        
        #define FLASH_CHARGE_IS_SHOW        FALSE
        #define FLASH_CHARGE_X              0
        #define FLASH_CHARGE_Y              0
        
   #ifdef __MMI_CAMERA_4_OSD_LAYER__
   #if defined(__CAMERA_FEATURE_FTE_SUPPORT__)
        #define OSD_REGION0_X               184
		#define OSD_REGION0_Y               4
   #else
        #define OSD_REGION0_X               235
		#define OSD_REGION0_Y               4
   #endif
		#define OSD_REGION0_WIDTH           160
		#define OSD_REGION0_HEIGHT          30
		#define OSD_REGION1_X               0
		#define OSD_REGION1_Y               429
		#define OSD_REGION1_WIDTH           320
		#define OSD_REGION1_HEIGHT          50
		#define OSD_REGION2_X               279
		#define OSD_REGION2_Y               50
		#define OSD_REGION2_WIDTH           40
		#define OSD_REGION2_HEIGHT          380
		#define OSD_REGION3_X               70
		#define OSD_REGION3_Y               190
		#define OSD_REGION3_WIDTH           180
		#define OSD_REGION3_HEIGHT          100
	#endif   
        /****** hint box ******/
	#ifndef __MMI_CAMERA_4_OSD_LAYER__
	#define HINT_IS_SHOW					TRUE
	#define HINT_X							0
	#define HINT_Y							200
	#define HINT_W							320
	#define HINT_H							70
	#else
	#define HINT_IS_SHOW                    TRUE
    #define HINT_X                          70
    #define HINT_Y                          190
    #define HINT_W                          180
    #define HINT_H                          100
	#endif      
        
    #define HINT_TXT_R                      255
    #define HINT_TXT_G                      255
    #define HINT_TXT_B                      255
    #define HINT_TXT_STYLE_R                0
    #define HINT_TXT_STYLE_G                0
    #define HINT_TXT_STYLE_B                0
    #define HINT_TXT_STYLE                  CAMERA_TEXT_STYLE_BORDER
    
#ifdef __CAMERA_OSD_HORIZONTAL__
        /****** softkey layer ******/
    #ifdef __MMI_CAMERA_SIMPLE_UI__
        #define LSK_X_270                       398
        #define LSK_Y_270                       292
            
        #define RSK_X_270                       429
        #define RSK_Y_270                       9
        
    #else   /*__MMI_CAMERA_SIMPLE_UI__*/
        #define LSK_X_270                       398
        #define LSK_Y_270                       292
            
        #define RSK_X_270                       429
        #define RSK_Y_270                       9
        
    #endif /*__MMI_CAMERA_SIMPLE_UI__*/
        
        /****** status icons ******/
    
        #define WB_X_270                        137
        #define WB_Y_270                        280
    
        #define FLASH_X_270                     94
        #define FLASH_Y_270                     280
        
        #define LED_HIGHLIGHT_X_270             180
        #define LED_HIGHLIGHT_Y_270             280
        
        #define EV_X_270                        0
        #define EV_Y_270                        0
        
        #define EV_INC_X_270                    0
        #define EV_INC_Y_270                    0
        
        #define EV_DEC_X_270                    0
        #define EV_DEC_Y_270                    0
        
        #define NIGHT_X_270                     0
        #define NIGHT_Y_270                     0
        
        #define CLOSEUP_X_270                   0
        #define CLOSEUP_Y_270                   0
        
        #define IMAGE_SIZE_X_270                8
        #define IMAGE_SIZE_Y_270                280
        
        #define IMAGE_QTY_X_270                 51
        #define IMAGE_QTY_Y_270                 280
        
        #define CONT_SHOT_X_270                 266
        #define CONT_SHOT_Y_270                 280
        
        #define DELAY_TIMER_X_270               223
        #define DELAY_TIMER_Y_270               280
        
        #define STORAGE_X_270                   0
        #define STORAGE_Y_270                   0
        
        #define EFFECT_X_270                    0
        #define EFFECT_Y_270                    0
        
        #define AE_METER_X_270                  0
        #define AE_METER_Y_270                  0
        
        #define ISO_X_270                       0
        #define ISO_Y_270                       0
        
        #define SCENE_MODE_X_270                0
        #define SCENE_MODE_Y_270                0
        
        #define AF_MODE_X_270                   0
        #define AF_MODE_Y_270                   0
        
        #define AF_METER_X_270                  0
        #define AF_METER_Y_270                  0
        
        #define ZOOM_MF_TOGGLE_X_270            0
        #define ZOOM_MF_TOGGLE_Y_270            0
        
        #define CAPTURE_X_270                   440
        #define CAPTURE_Y_270                   148
        
        #define ZOOM_X_270                      8
        #define ZOOM_Y_270                      7
    
        #define ZOOM_INC_X_270                  8
        #define ZOOM_INC_Y_270                  7
        
        #define ZOOM_DEC_X_270                  70
        #define ZOOM_DEC_Y_270                  7
    
        #define MMS_ICON_X_270                  440
        #define MMS_ICON_Y_270                  148
        
        #define LEFT_ARROW_X_270                0
        #define LEFT_ARROW_Y_270                0
        
        #define RIGHT_ARROW_X_270               0
        #define RIGHT_ARROW_Y_270               0
        
        #define FLASH_CHARGE_X_270              0
        #define FLASH_CHARGE_Y_270              0
    #ifdef __MMI_CAMERA_4_OSD_LAYER__
        #define OSD_REGION0_X_270               8
		#define OSD_REGION0_Y_270               6
		#define OSD_REGION0_WIDTH_270          240
		#define OSD_REGION0_HEIGHT_270          30
		#define OSD_REGION1_X_270               389
		#define OSD_REGION1_Y_270               0
		#define OSD_REGION1_WIDTH_270           90
		#define OSD_REGION1_HEIGHT_270          320
		#define OSD_REGION2_X_270               40
		#define OSD_REGION2_Y_270               279
		#define OSD_REGION2_WIDTH_270           400
		#define OSD_REGION2_HEIGHT_270          40
		#define OSD_REGION3_X_270               150
		#define OSD_REGION3_Y_270               100
		#define OSD_REGION3_WIDTH_270           180
		#define OSD_REGION3_HEIGHT_270          120
	#endif    
        /****** hint box ******/
	#ifndef __MMI_CAMERA_4_OSD_LAYER__
		#define HINT_X_270							150
		#define HINT_Y_270							100
		#define HINT_W_270							180
		#define HINT_H_270							120
	#else
		#define HINT_X_270                          150
	    #define HINT_Y_270                          100
	    #define HINT_W_270                          180
	    #define HINT_H_270                          120
	#endif    
#endif /*__CAMERA_OSD_HORIZONTAL__*/
    
#else /* Other non support size */
#error "Camera does not support this LCD size, please customize first !"
#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */
    



#if defined(__MMI_CAMERA_HIGH_END__)
	/* for MT6228 / MT6229, use wav, which have better qty */
	#define CAMERA_SOUND_SHUTTER_1_LEN	(4798)
	#define CAMERA_SOUND_SHUTTER_2_LEN	(3532)
	#define CAMERA_SOUND_SHUTTER_3_LEN	(6960)
	#define CAMERA_SOUND_DUMMY_BG_LEN	(94)
	#define CAMERA_SOUND_AF_SUCCEED_LEN (3695)
#else
	#define CAMERA_SOUND_SHUTTER_1_LEN	(1199)
	#define CAMERA_SOUND_SHUTTER_2_LEN	(883)
	#define CAMERA_SOUND_SHUTTER_3_LEN	(1740)
	#define CAMERA_SOUND_DUMMY_BG_LEN	(94)	
#endif 

#if defined(ISP_SUPPORT) 
#define CAMREA_SOUND_COUNTDOWN_LEN	(1374)
#else
#define CAMREA_SOUND_COUNTDOWN_LEN	(164)
#endif

typedef enum {
	CAMERA_TEXT_STYLE_NORMAL,
	CAMERA_TEXT_STYLE_BORDER,
	CAMERA_TEXT_STYLE_SHADOW	
} mmi_camera_text_style;


/***************************************************************************** 
* Struct
*****************************************************************************/
typedef struct
{
	S32	offset_x;
	S32	offset_y;
} camera_skin_icon_struct;

typedef struct
{
	U8 r;
	U8 g;
	U8 b;
} camera_color_struct;

typedef struct {
	U8		r;
	U8		g;	
	U8		b;		
	U8		style_r;
	U8		style_g;	
	U8		style_b;
	U16	style;	
} camera_style_text_struct;

typedef struct
{
	BOOL	is_draw_mmi_softkey;
	camera_style_text_struct	lsk;
	camera_style_text_struct	rsk;
} camera_skin_softkey_struct;

typedef struct
{
	BOOL	is_show;
	S32 	offset_x;
	S32	offset_y;
	S32	width;
	S32 	height;
	camera_style_text_struct style_text;
} camera_skin_hint_box_struct;


typedef struct 
{	
	BOOL 	is_show;
	BOOL	is_right_align;	
	S32 	offset_x;
	S32	    offset_y;
	camera_style_text_struct style_text;
   	U8		group_id;
} camera_skin_storage_struct;

typedef struct 
{	
	BOOL 	is_draw_bg_image;
	BOOL	is_draw_bg_color;
	U8		r;
	U8		g;	
	U8		b;	
} camera_skin_bg_struct;

typedef struct 
{	
	BOOL 	is_draw_mmi_title_bar;
	BOOL	is_draw_mmi_caption;
} camera_skin_title_struct;

#if defined(__MMI_CAMERA_4_OSD_LAYER__)
typedef struct
{
	S32 offset_x;
	S32 offset_y;
	S32 width;
	S32 height;
}camera_osd_region_struct;
#endif

typedef struct {

	/* background */
	camera_skin_bg_struct				bg;

	/* title */
	camera_skin_title_struct			title;

	/* softkey (buttom bar) */
	camera_skin_softkey_struct		softkey;
#if (LSK_IS_SHOW == TRUE)
    camera_skin_icon_struct          lsk;
#endif

#if (RSK_IS_SHOW == TRUE)
    camera_skin_icon_struct          rsk;
#endif
	
	/* camera setting */
#if defined(__CAMERA_FEATURE_WB__) && (WB_IS_SHOW == TRUE)
    camera_skin_icon_struct 			wb;
#endif

#if defined(__CAMERA_FEATURE_FLASH__) && (FLASH_IS_SHOW == TRUE)
	camera_skin_icon_struct 			flash;
#endif
    
#if defined(__CAMERA_FEATURE_LED_HIGHLIGHT__) && (LED_HIGHLIGHT_IS_SHOW == TRUE)
	camera_skin_icon_struct 			led_highlight;	
#endif

#if defined(__CAMERA_FEATURE_EV__) && (EV_IS_SHOW == TRUE)
	camera_skin_icon_struct 			ev;		
	camera_skin_icon_struct 			ev_inc;		/* for touch screen */
	camera_skin_icon_struct 			ev_dec;		/* for touch screen */
#endif

#if defined(__CAMERA_FEATURE_NIGHT__) && (NIGHT_IS_SHOW == TRUE)    
	camera_skin_icon_struct			night;
#endif

    /* image setting  */ 
#if (IMAGE_SIZE_IS_SHOW == TRUE)    
	camera_skin_icon_struct			image_size;
#endif

#if (IMAGE_QTY_IS_SHOW == TRUE)
	camera_skin_icon_struct			image_qty;
#endif

	/* others */
#if defined(__CAMERA_FEATURE_CONT_SHOT__) && (CONT_SHOT_IS_SHOW == TRUE)    
	camera_skin_icon_struct			cont_shot;
#endif

#if defined(__CAMERA_FEATURE_DELAY_TIMER__) && (DELAY_TIMER_IS_SHOW == TRUE)    
	camera_skin_icon_struct			delay_timer;
#endif

#if defined(__CAMERA_FEATURE_STORAGE__) && (STORAGE_IS_SHOW == TRUE) 
	camera_skin_icon_struct			storage;
#endif

#if defined(__CAMERA_FEATURE_EFFECT__) && (EFFECT_IS_SHOW == TRUE) 
	camera_skin_icon_struct			effect;
#endif

#if defined(__CAMERA_FEATURE_AE_METER__) && (AE_METER_IS_SHOW == TRUE)     
	camera_skin_icon_struct			ae_meter;	
#endif
    
#if defined(__CAMERA_FEATURE_ISO_SUPPORT__) && (ISO_IS_SHOW == TRUE)     
	camera_skin_icon_struct			iso;	
#endif

#if defined(__CAMERA_DSC_MODE__) && (SCENE_MODE_IS_SHOW == TRUE)     
	camera_skin_icon_struct			dsc_mode ;
#endif

#if defined(__CAMERA_AUTOFOCUS_MODE__) && (AF_MODE_IS_SHOW == TRUE)     
	camera_skin_icon_struct			af_mode;
#endif
    
#if defined(__CAMERA_AUTOFOCUS_METERING__) && (AF_METER_IS_SHOW == TRUE)     
	camera_skin_icon_struct			af_meter;
#endif
        
#if (CAPTURE_IS_SHOW == TRUE)     
	camera_skin_icon_struct			capture;	
#endif

#if defined(__CAMERA_FEATURE_ZOOM__) && (ZOOM_IS_SHOW == TRUE)     
	camera_skin_icon_struct			zoom;	
	camera_skin_icon_struct 			zoom_inc;		/* for touch screen */
	camera_skin_icon_struct 			zoom_dec;		/* for touch screen */
#endif

#if defined(__MMI_CAMERA_FORWARD_SUPPORT__)     
	camera_skin_icon_struct			mms_icon;
#endif

#if (LEFT_ARROW_IS_SHOW == TRUE)
	camera_skin_icon_struct			left_arrow;
#endif

#if (RIGHT_ARROW_IS_SHOW == TRUE)
	camera_skin_icon_struct			right_arrow;
#endif

#if (FLASH_CHARGE_IS_SHOW == TRUE)
	camera_skin_icon_struct			flash_charge_status;
#endif
#if defined(__MMI_CAMERA_4_OSD_LAYER__)
	camera_osd_region_struct osd_region0;
	camera_osd_region_struct osd_region1;
	camera_osd_region_struct osd_region2;
	camera_osd_region_struct osd_region3;
#endif
	camera_skin_hint_box_struct		hint_box;
	camera_skin_storage_struct		remain_storage;

} camera_skin_layeout_struct;


/***************************************************************************** 
* Local Variable
*****************************************************************************/
/* camera osd display cntx */
extern const camera_skin_layeout_struct g_camera_skin_cntx;

#ifdef __CAMERA_OSD_HORIZONTAL__	
extern const camera_skin_layeout_struct g_camera_skin_cntx_270;
#endif


/* camera sound */
#ifndef WIN32
	extern __align(2) const U8 camera_sound_countdown[CAMREA_SOUND_COUNTDOWN_LEN];
	extern __align(2) const U8 camera_sound_shutter_1[CAMERA_SOUND_SHUTTER_1_LEN];
	extern __align(2) const U8 camera_sound_shutter_2[CAMERA_SOUND_SHUTTER_2_LEN];
	extern __align(2) const U8 camera_sound_shutter_3[CAMERA_SOUND_SHUTTER_3_LEN];
	extern __align(2) const U8 camera_sound_dummy_bg[CAMERA_SOUND_DUMMY_BG_LEN];
#if defined(__MMI_CAMERA_HIGH_END__)
	extern __align(2) const U8 camera_af_succeed[CAMERA_SOUND_AF_SUCCEED_LEN];
#endif
#else
	extern const U8 camera_sound_countdown[CAMREA_SOUND_COUNTDOWN_LEN];
	extern const U8 camera_sound_shutter_1[CAMERA_SOUND_SHUTTER_1_LEN];
	extern const U8 camera_sound_shutter_2[CAMERA_SOUND_SHUTTER_2_LEN];
	extern const U8 camera_sound_shutter_3[CAMERA_SOUND_SHUTTER_3_LEN];
	extern const U8 camera_sound_dummy_bg[CAMERA_SOUND_DUMMY_BG_LEN];	
#if defined(__MMI_CAMERA_HIGH_END__)
	extern const U8 camera_af_succeed[CAMERA_SOUND_AF_SUCCEED_LEN];
#endif
#endif 







#endif /* defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) */
#endif /* _CAMERA_SKIN_H_ */


