/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    lcd_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for LCD driver.
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#include "lcd_if_hw.h"
#include "lcm_if.h"
#include "lcd_if.h"


#ifndef _LCD_SW_H
#define _LCD_SW_H
//#if (defined(MT6226)||defined(MT6227)||defined(MT6228)||defined(MT6229)||defined(MT6230)||defined(MT6235)||defined(MT6238)||defined(MT6268)||defined(MT6236) || defined(MT6236B))

#ifdef LQT_SUPPORT/*Do not remove LQT code segment*/ 
#include "lcd_lqt.h"
extern kal_uint8 lcd_at_mode;
extern kal_bool lcd_update_permission;
#endif/*LQT_SUPPORT*/

extern kal_bool  lcd_assert_fail;
extern kal_uint16 lcd_driver_rotation;
extern kal_uint32 back_potch ;

#ifdef DUAL_LCD
kal_uint16 lcd_power_ctrl_shadow1;
#endif

#if (defined(MT6260)||defined(MT6250))
#define COMBO_LCM_ID_AUTO_DETECT
#endif

#define LCD_CMD_DMA_MODE

#if (defined(MT6256)||defined(MT6255)||defined(MT6250)||defined(MT6260))
#undef LCD_CMD_DMA_MODE
#endif

#define LCD_DUMMYADDR   				0x90000000

#ifdef COMBO_LCM_ID_AUTO_DETECT
  #define   MAIN_LCD_8BIT_MODE
#endif

#define MAIN_LCD_CMD_ADDR               LCD_PARALLEL0_A0_LOW_ADDR
#define MAIN_LCD_DATA_ADDR              LCD_PARALLEL0_A0_HIGH_ADDR

#ifdef COMBO_LCM_ID_AUTO_DETECT
  
      #if (defined(MAIN_LCD_8BIT_MODE))
          #define MAIN_LCD_OUTPUT_FORMAT  LCM_8BIT_18_BPP_RGB666_1//LCM_8BIT_18_BPP_RGB666_1        
      #endif
#endif

    // define main supported combo lcm ID
    typedef enum
    {
       ST7789S  = 0,
	   GC9305 =1,
       MAIN_LCM_MAX_NUM  //please add main lcd ID above this item, this "MAIN_LCM_MAX_NUM" will be used as the number of LCMs.
    }  main_lcm_enum;

#ifdef DUAL_LCD
    // define sub supported combo lcm ID
    typedef enum
    {
       SUB_EXAMPLE_LCM_A  = 0,
       SUB_EXAMPLE_LCM_B  = 1,
       SUB_EXAMPLE_LCM_C  = 2,
       SUB_LCM_MAX_NUM  //please add sub lcd ID above this item, this "SUB_LCM_MAX_NUM" will be used as the number of LCMs.
    }  sub_lcm_enum;    //notice, the enum value should not be conflict with main lcd enum.
#endif

#ifdef COMBO_LCM_ID_AUTO_DETECT
    //kal_uint32 LCM_ID_Get(void);

    // MAIN_LCD_OUTPUT_FORMAT will be chosen as current used LCM's output color format
    //#define MAIN_LCD_OUTPUT_FORMAT  MAIN_LCD_OUTPUT_FORMAT//((LCM_ID_Get() == 0)? MAIN_LCD_OUTPUT_FORMAT_ILI9486 : MAIN_LCD_OUTPUT_FORMAT_R61529)
    #define DEFAULT_MAIN_LCD_OUTPUT_FORMAT MAIN_LCD_OUTPUT_FORMAT//MAIN_LCD_OUTPUT_FORMAT_ILI9486
#endif


	#define LCD_delay_main()

	#if (defined(MAIN_LCD_8BIT_MODE))
		#define LCD_CtrlWrite_main(_data)  \
		{\
			*(volatile kal_uint8 *) MAIN_LCD_CMD_ADDR = (_data );\
			LCD_delay_main();\
		}\

		#define LCD_DataWrite_main(_data)  \
		{\
			*(volatile kal_uint8 *)MAIN_LCD_DATA_ADDR = (_data);\
			LCD_delay_main();\
		}
		
        	#define LCD_CtrlWrite_main_16bit(_data)  \
		{\
			*(volatile kal_uint8 *) MAIN_LCD_CMD_ADDR = ((_data&0xFF00)>>8);\
			*(volatile kal_uint8 *) MAIN_LCD_CMD_ADDR = (_data&0xFF);\
			LCD_delay_main();\
		}\

		#define LCD_DataWrite_main_16bit(_data)  \
		{\
			*(volatile kal_uint8 *)MAIN_LCD_DATA_ADDR = ((_data&0xFF00)>>8);\
			*(volatile kal_uint8 *)MAIN_LCD_DATA_ADDR = (_data&0xFF);\
			LCD_delay_main();\
		}


	#endif

#if (defined(MAIN_LCD_8BIT_MODE))
	#define LCD_DataRead_main	(*(volatile kal_uint8 *)MAIN_LCD_DATA_ADDR);
#elif (defined(MAIN_LCD_9BIT_MODE))
	#define LCD_DataRead_main	(*(volatile kal_uint16 *)MAIN_LCD_DATA_ADDR);
#elif (defined(MAIN_LCD_18BIT_MODE))
	#define LCD_DataRead_main	(*(volatile kal_uint16 *)MAIN_LCD_DATA_ADDR);
#endif

//#endif
#endif  /*_LCD_SW_H*/
