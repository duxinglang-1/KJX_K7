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
 *   custom_hw_default.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file contains definition of custom component module configuration
 *   variables, and routines handle for equipment device.
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
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/*
**   Includes
*/


#include "kal_release.h"
#include "custom_hw_default.h"
#include "pwm_sw.h"
#ifndef __L1_STANDALONE__

#include "stack_types.h"
#include "syscomp_config.h"
#include "custom_config.h"
#include "stack_buff_pool.h"
#include "ctrl_buff_pool.h"

#include "custom_nvram_editor_data_item.h"

#endif /* __L1_STANDALONE__ */

#ifdef MMI_ON_HARDWARE_P
#include "Pmic6318_sw.h"
#endif

/* 
**   Globol Varibales 
*/

#if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__) && defined(LED_MAINLCD_USE_PWM_1)

kal_uint32 PWM1_Level_Info[PWM_MAX_BACKLIGHT_LEVEL][2] = 
{
   /*Freq, duty*/
   {200,5},     /*Level 1*/
   {200,10},    /*Level 2*/
   {200,15},    /*Level 3*/
   {200,20},    /*Level 4*/
   {200,25},    /*Level 5*/
   {200,30},    /*Level 6*/
   {200,35},    /*Level 7*/
   {200,40},    /*Level 8*/
   {200,45},    /*Level 9*/
   {200,50},    /*Level 10*/
   {200,55},    /*Level 11*/
   {200,60},    /*Level 12*/
   {200,65},    /*Level 13*/
   {200,70},    /*Level 14*/
   {200,75},    /*Level 15*/
   {200,80},    /*Level 16*/
   {200,85},    /*Level 17*/
   {200,90},    /*Level 18*/
   {200,95},    /*Level 19*/
   {200,100}    /*Level 20*/   
};

#else

kal_uint32 PWM1_Level_Info[PWM_MAX_LEVEL][2] = 
{
   /*Freq,duty*/
   {200,20},    /*Level 1*/
   {200,40},    /*Level 2*/
   {200,60},    /*Level 3*/
   {200,80},    /*Level 4*/
   {200,100}    /*Level 5*/
};
#endif // End of #if defined(MULTI_LEVEL_BACKLIGHT_SUPPORT) && defined(LED_MAINLCD_USE_PWM_1)

#if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__) && defined(LED_MAINLCD_USE_PWM_2)

kal_uint32 PWM2_Level_Info[PWM_MAX_BACKLIGHT_LEVEL][2] = 
{
   /*Freq, duty*/
    {200,5},     /*Level 1*/
   {200,10},    /*Level 2*/
   {200,15},    /*Level 3*/
   {200,20},    /*Level 4*/
   {200,25},    /*Level 5*/
   {200,30},    /*Level 6*/
   {200,35},    /*Level 7*/
   {200,40},    /*Level 8*/
   {200,45},    /*Level 9*/
   {200,50},    /*Level 10*/
   {200,55},    /*Level 11*/
   {200,60},    /*Level 12*/
   {200,65},    /*Level 13*/
   {200,70},    /*Level 14*/
   {200,75},    /*Level 15*/
   {200,80},    /*Level 16*/
   {200,85},    /*Level 17*/
   {200,90},    /*Level 18*/
   {200,95},    /*Level 19*/
   {200,100}    /*Level 20*/     
};

#else

kal_uint32 PWM2_Level_Info[PWM_MAX_LEVEL][2] =    
{
   /*Freq,duty,for KPAD LED 3 duty: 0,50,100*/
   {200,50},    /*Level 1*/
   {200,100},    /*Level 2*/
   {200,100},    /*Level 3*/
   {200,100},    /*Level 4*/
   {200,100}    /*Level 5*/
};
#endif // End of #if defined(MULTI_LEVEL_BACKLIGHT_SUPPORT) && defined(LED_MAINLCD_USE_PWM_2)

#if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__) && defined(LED_MAINLCD_USE_PWM_3)

kal_uint32 PWM3_Level_Info[PWM_MAX_BACKLIGHT_LEVEL][2] = 
{
   /*Freq, duty*/
   {20000,9},     /*Level 1*/
   {20000,12},    /*Level 2*/
   {20000,17},    /*Level 3*/
   {20000,22},    /*Level 4*/
   {20000,27},    /*Level 5*/
   {20000,32},    /*Level 6*/
   {20000,37},    /*Level 7*/
   {20000,42},    /*Level 8*/
   {20000,47},    /*Level 9*/
   {20000,52},    /*Level 10*/
   {20000,56},    /*Level 11*/
   {20000,62},    /*Level 12*/
   {20000,66},    /*Level 13*/
   {20000,72},    /*Level 14*/
   {20000,76},    /*Level 15*/
   {20000,81},    /*Level 16*/
   {20000,86},    /*Level 17*/
   {20000,91},    /*Level 18*/
   {20000,96},    /*Level 19*/
   {20000,100}    /*Level 20*/    
};

#else

kal_uint32 PWM3_Level_Info[PWM_MAX_LEVEL][2] = 
{
   /*Freq,duty*/
   {20000,15},     /*Level 1*/
   {20000,35},    /*Level 2*/
   {20000,55},    /*Level 3*/
   {20000,75},    /*Level 4*/
   {20000,100},    /*Level 5*/
};

#endif // End of #if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__) && defined(LED_MAINLCD_USE_PWM_3)

kal_uint32 Alter_Level_Info[PWM_MAX_LEVEL][2] = 
{
   /*Freq,duty*/
   {200,20},    /*Level 1*/
   {200,40},    /*Level 2*/
   {200,60},    /*Level 3*/
   {200,80},    /*Level 4*/
   {200,100}    /*Level 5*/
};

#if defined(MT6318)
kal_uint32 PMIC6318_PWM_Level_Info[PWM_MAX_LEVEL][2] = 
{
   /*Freq,duty*/
   {200,20},    /*Level 1*/
   {200,40},    /*Level 2*/
   {200,60},    /*Level 3*/
   {200,80},    /*Level 4*/
   {200,100}    /*Level 5*/
};

kal_uint16 pmic_custom_get_bl_pmw_type(void)
{
   // Choose BL_LED or KP_LED. If no use, just return 0.
   return BL_LED;
}
#endif
   
const kal_uint8 DEFAULT_HARDWARE_YEAR = 13; //2013
const kal_uint8 DEFAULT_HARDWARE_MON = 1;
const kal_uint8 DEFAULT_HARDWARE_DAY = 1;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

//50ms * 10 = 0.5 sec
const kal_uint32 ADC_BOOTUP_EVAL_PERIOD  =  KAL_TICKS_50_MSEC;  
const kal_uint32 ADC_BOOTUP_EVAL_COUNT   =  10;

//10sec * 6 = 1min
const kal_uint32 ADC_IDLE_EVAL_PERIOD  =  (2*KAL_TICKS_5_SEC);
const kal_uint32 ADC_IDLE_EVAL_COUNT   =   6;

//5sec * 6 = 30sec
const kal_uint32 ADC_TALKING_EVAL_PERIOD  = (KAL_TICKS_5_SEC);
const kal_uint32 ADC_TALKING_EVAL_COUNT   =  6;

//150 * 10 ms = 1.5 sec  (unit : 10ms )
const kal_uint32 KPD_LONGPRESS_PERIOD  = 60;

//50 * 10ms = 0.5 sec  (unit : 10ms )
const kal_uint32 KPD_REPEAT_PERIOD     = 50;

#ifndef __L1_STANDALONE__

kal_uint8   MainLCD_Contrast_Level_Info[LCD_CONTRAST_MAX_LEVEL];
kal_uint8   MainLCD_Bias_Level_Info[LCD_PARAM_MAX_LEVEL];
kal_uint8   MainLCD_Linerate_Level_Info[LCD_PARAM_MAX_LEVEL];
kal_uint8   MainLCD_Temp_Level_Info[LCD_PARAM_MAX_LEVEL];
   
#ifdef DUAL_LCD
kal_uint8   SubLCD_Contrast_Level_Info[LCD_CONTRAST_MAX_LEVEL];
kal_uint8   SubLCD_Bias_Level_Info[LCD_PARAM_MAX_LEVEL];
kal_uint8   SubLCD_Linerate_Level_Info[LCD_PARAM_MAX_LEVEL];
kal_uint8   SubLCD_Temp_Level_Info[LCD_PARAM_MAX_LEVEL];
#endif

kal_uint32   Battery_Level_Info[BATTERY_MAX_LEVEL];


void  custom_init_hardware_level(void *hw_level_struct)
{
    kal_uint8 i, j;

   custom_hw_level_struct *hw_level = (custom_hw_level_struct *)hw_level_struct;

    for( i=0; i< LCD_CONTRAST_MAX_LEVEL; i++ )
    {
        MainLCD_Contrast_Level_Info[i]= hw_level->MainLCD_Contrast[i];
#ifdef DUAL_LCD        
        SubLCD_Contrast_Level_Info[i]= hw_level->SubLCD_Contrast[i];
#endif        
    }

    for( i=0; i< LCD_PARAM_MAX_LEVEL; i++ )
    {
        MainLCD_Bias_Level_Info[i]= hw_level->MainLCD_Bias[i];
        MainLCD_Linerate_Level_Info[i]= hw_level->MainLCD_Linerate[i];
        MainLCD_Temp_Level_Info[i] =  hw_level->MainLCD_Temp[i];
#ifdef DUAL_LCD
        SubLCD_Bias_Level_Info[i]= hw_level->SubLCD_Bias[i];
        SubLCD_Linerate_Level_Info[i]= hw_level->SubLCD_Linerate[i];
        SubLCD_Temp_Level_Info[i] =  hw_level->SubLCD_Temp[i];
#endif        
    }

    for( i=0; i< BATTERY_MAX_LEVEL; i++ )
      Battery_Level_Info[i] = hw_level->BatteryLevel[i];

#if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__)

#if !defined(LED_MAINLCD_USE_PWM_NONE)      
    for( i = 0; i< PWM_MAX_BACKLIGHT_LEVEL; i++ )
        for( j = 0; j < 2; j++ )
        {
#if defined(LED_MAINLCD_USE_PWM_1)            
            PWM1_Level_Info[i][j] = hw_level->BacklightLevel[i][j];
#elif defined(LED_MAINLCD_USE_PWM_2)            
            PWM2_Level_Info[i][j] = hw_level->BacklightLevel[i][j];
#elif defined(LED_MAINLCD_USE_PWM_3)            
            PWM3_Level_Info[i][j] = hw_level->BacklightLevel[i][j];
#endif // End of #if defined(LED_MAINLCD_USE_PWM_1)    
         }
#endif // End of #if !defined(LED_MAINLCD_USE_PWM_NONE)       

   for( i=0; i<PWM_MAX_LEVEL; i++ )
      for( j=0; j<2; j++ )
         {
#if !defined(LED_MAINLCD_USE_PWM_1)             
               PWM1_Level_Info[i][j] = hw_level->PWM1[i][j];
#endif

#if !defined(LED_MAINLCD_USE_PWM_2)             
               PWM2_Level_Info[i][j] = hw_level->PWM2[i][j];
#endif

               Alter_Level_Info[i][j] = hw_level->PWM3[i][j];
         }

#else
   for( i=0; i<PWM_MAX_LEVEL; i++ )
      for( j=0; j<2; j++ )
         {
               PWM1_Level_Info[i][j] = hw_level->PWM1[i][j];
               PWM2_Level_Info[i][j] = hw_level->PWM2[i][j];
               Alter_Level_Info[i][j] = hw_level->PWM3[i][j];
         }
#endif // End of #if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__)  
      
#if defined(MT6318)   
   for( i=0; i<PWM_MAX_LEVEL; i++ )
      for( j=0; j<2; j++ )
         {
             PMIC6318_PWM_Level_Info[i][j] = hw_level->PMIC6318BLPWM[i][j];
         }
#endif      

#if defined(DRV_PWM_AFFECT_RF) && defined(__MTK_TARGET__) && !defined(__UBL__)

//added for 6250 E1 RF desense issue
	Set_Level_of_backlight(PWM3_Level_Info);
#endif

}

#endif /* __L1_STANDALONE__ */


