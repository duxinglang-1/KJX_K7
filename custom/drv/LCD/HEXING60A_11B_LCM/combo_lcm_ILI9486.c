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
 *   lcd.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   This Module defines the LCD driver.
 *
 * Author:
 	Hesong Li
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "reg_base.h"
#include "lcd_sw_inc.h"
#include "lcd_sw.h"
#include "lcd_hw.h"
/*Serial interface*/
#include "lcd_if_hw.h"
#include "lcd_if.h"
#include "eint.h"

#ifdef __GPS_TRACKER_MODULE_SUPPORT__
#include "GpstLog.h"
#else
#define bst2_log /\
/
#endif


#if (defined(MAIN_LCD_8BIT_MODE_ILI9486))
    #define MAIN_LCD_8BIT_MODE
#elif (defined(MAIN_LCD_9BIT_MODE_ILI9486))
    #define MAIN_LCD_9BIT_MODE
#elif (defined(MAIN_LCD_16BIT_MODE_ILI9486))
    #define MAIN_LCD_16BIT_MODE
#elif (defined(MAIN_LCD_18BIT_MODE_ILI9486))
    #define MAIN_LCD_18BIT_MODE
#endif

#ifdef LCD_CMD_DMA_MODE
	#if (defined(MAIN_LCD_8BIT_MODE))
		#define LCD_CtrlWrite_ILI9486(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_CMD,(_data ));\
			LCD_SEND_DMA_CMD(1);\
		}\

		#define LCD_DataWrite_ILI9486(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_DATA,(_data ));\
			LCD_SEND_DMA_CMD(1);\
		}\

	#elif (defined(MAIN_LCD_9BIT_MODE))
		#define LCD_CtrlWrite_ILI9486(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_CMD,(_data & 0xFF));\
			LCD_SEND_DMA_CMD(1);\
		}\

		#define LCD_DataWrite_ILI9486(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_DATA,(_data & 0xFF));\
			LCD_SEND_DMA_CMD(1);\
		}
		
	#elif (defined(MAIN_LCD_16BIT_MODE))
		#define LCD_CtrlWrite_ILI9486(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_CMD,(_data & 0xFF));\
			LCD_SEND_DMA_CMD(1);\
		}\
		
		#define LCD_DataWrite_ILI9486(_data) \
		{\
			SET_LCD_CMD_PARAMETER(0,LCD_DATA,(_data & 0xFF));\
			LCD_SEND_DMA_CMD(1);\
		}

	#endif
    
	//#define LCD_RAMWrite_HX8347D(_data)
#else
	#define LCD_delay_ILI9486()

	#if (defined(MAIN_LCD_8BIT_MODE))
		#define LCD_CtrlWrite_ILI9486(_data)  \
		{\
			*(volatile kal_uint8 *) MAIN_LCD_CMD_ADDR = (_data );\
			LCD_delay_ILI9486();\
		}\

		#define LCD_DataWrite_ILI9486(_data)  \
		{\
			*(volatile kal_uint8 *)MAIN_LCD_DATA_ADDR = (_data);\
			LCD_delay_ILI9486();\
		}
        
	#elif (defined(MAIN_LCD_9BIT_MODE))
		#define LCD_CtrlWrite_ILI9486(_data)  \
		{\
			*(volatile kal_uint16 *) MAIN_LCD_CMD_ADDR = (_data );\
			LCD_delay_ILI9486();\
		}\
		
		#define LCD_DataWrite_ILI9486(_data)  \
		{\
			*(volatile kal_uint16 *)MAIN_LCD_DATA_ADDR = (_data);\
			LCD_delay_ILI9486();\
		}
        
	#elif (defined(MAIN_LCD_16BIT_MODE))
		#define LCD_CtrlWrite_ILI9486(_data)  \
		{\
			*(volatile kal_uint8 *) MAIN_LCD_CMD_ADDR = (_data );\
			LCD_delay_ILI9486();\
		}\
		
		#define LCD_DataWrite_ILI9486(_data)  \
		{\
			*(volatile kal_uint8 *)MAIN_LCD_DATA_ADDR = (_data);\
			LCD_delay_ILI9486();\
		}

	#endif
#endif /* LCD_CMD_DMA_MODE */

#if (defined(MAIN_LCD_8BIT_MODE))
	#define LCD_DataRead_ILI9486	(*(volatile kal_uint8 *)MAIN_LCD_DATA_ADDR);
#elif (defined(MAIN_LCD_9BIT_MODE))
	#define LCD_DataRead_ILI9486	(*(volatile kal_uint16 *)MAIN_LCD_DATA_ADDR);
#elif (defined(MAIN_LCD_18BIT_MODE))
	#define LCD_DataRead_ILI9486	(*(volatile kal_uint16 *)MAIN_LCD_DATA_ADDR);
#endif

static void LCD_Delay(kal_uint32 delay_count)
{
	volatile kal_uint32 delay;
	for (delay =0;delay <(delay_count*4);delay++) {}
}

extern kal_uint32 drv_get_current_time(void);
extern kal_uint32 drv_get_duration_ms(kal_uint32 previous_time);
void LCDDelayms(kal_uint16 data)
{

    kal_uint32 time1;
    
    time1 = drv_get_current_time();
    while (drv_get_duration_ms(time1) <= data);
}

static void LCD_set_reg_ILI9486(kal_uint16 reg_index, kal_uint16 reg_data)
{

	LCD_CtrlWrite_ILI9486(reg_index);
	if (reg_data==0xFFFF){
  //no register setting
  	}
	else
	{
  		LCD_DataWrite_ILI9486(reg_data);
  	}
}

void spi_ini_ILI9486(void)
{
}

void init_lcd_interface_ILI9486(void)
{
	kal_uint32 backup_val;	

	//bst2_log("%s:",__func__);
	
#ifdef DUAL_LCD
	#if (defined(MT6218B)||defined(MT6217)||defined(MT6219))
		GPIO_ModeSetup(24, 1);
	#elif (defined(MT6226)||defined(MT6227)||defined(MT6228)||defined(MT6229)||defined(MT6268T)||defined(MT6268H)||defined(MT6230)||defined(MT6235)||defined(MT6235B)||defined(MT6238)||defined(MT6239)||defined(MT6268A)||defined(MT6239)||defined(MT6268))
		GPIO_ModeSetup(25, 1);
  		#ifdef SERIAL_SUBLCD

		GPIO_ModeSetup(14, 1); //LCD serial clock LSCK
		GPIO_ModeSetup(15, 1); //serial LCD Address Signal LSA0
		GPIO_ModeSetup(16, 1); //serial LCD Data Signal LSDA
		GPIO_ModeSetup(17, 1); //serial LCD chip select 0 LSCE0#
  		#endif
	#endif
#endif    
  /// Turn on LCD clock
#if defined(__OLD_PDN_DEFINE__)
	DRV_Reg(DRVPDN_CON1_CLR) = DRVPDN_CON1_LCD;
	//modifed for new clock gating
#elif defined(__CLKG_DEFINE__)
	DRV_Reg(MMCG_CLR0) = MMCG_CON0_LCD;
#endif

	REG_LCD_ROI_CTRL=0;
#if (defined(MT6218B))
	SET_LCD_PARALLEL_CE2WR_SETUP_TIME(3);
	SET_LCD_PARALLEL_CE2WR_HOLD_TIME(3);
	SET_LCD_PARALLEL_CE2RD_SETUP_TIME(0);
	SET_LCD_PARALLEL_WRITE_WAIT_STATE(5);
	SET_LCD_PARALLEL_READ_LATENCY_TIME(0);
	SET_LCD_ROI_CTRL_CMD_LATENCY(4);

	DISABLE_LCD_PARALLEL_SYNC;
#elif (defined(MT6219))
	SET_LCD_PARALLEL_CE2WR_SETUP_TIME((kal_uint32)0);
	SET_LCD_PARALLEL_CE2WR_HOLD_TIME(0);
	SET_LCD_PARALLEL_CE2RD_SETUP_TIME(0);
	SET_LCD_PARALLEL_WRITE_WAIT_STATE(4);
	SET_LCD_PARALLEL_READ_LATENCY_TIME(2);
	SET_LCD_ROI_CTRL_CMD_LATENCY(2);

	DISABLE_LCD_PARALLEL_SYNC;
#elif (defined(MT6223)||defined(MT6223P))
	CLEAR_LCD_CTRL_RESET_PIN;
	SET_LCD_PARALLEL_CE2WR_SETUP_TIME((kal_uint32)1);
	SET_LCD_PARALLEL_CE2WR_HOLD_TIME(1);
	SET_LCD_PARALLEL_CE2RD_SETUP_TIME(1);
	SET_LCD_PARALLEL_WRITE_WAIT_STATE(2);
	SET_LCD_PARALLEL_READ_LATENCY_TIME(2);
	SET_LCD_ROI_CTRL_CMD_LATENCY(2);

	#if (defined(MAIN_LCD_18BIT_MODE))
		SET_LCD_PARALLEL_18BIT_DATA_BUS;
		GPIO_ModeSetup(55, 1);
		*((volatile unsigned short *) 0x801201B0) |= 0x4000;
		*((volatile unsigned short *) 0x801201D0) |= 0x0001;
		SET_LCD_PARALLEL_18BIT_DATA_BUS;
	#elif (defined(MAIN_LCD_9BIT_MODE))
		SET_LCD_PARALLEL_9BIT_DATA_BUS; 
	#endif


#elif (defined(MT6226)||defined(MT6227)||defined(MT6228)||defined(MT6229)||defined(MT6268T)||defined(MT6268H)||defined(MT6230)||defined(MT6235)||defined(MT6235B)||defined(MT6238)||defined(MT6239)||defined(MT6268A)||defined(MT6239)||defined(MT6253T)||defined(MT6253)||defined(MT6253E)||defined(MT6253L)||defined(MT6252H)||defined(MT6252)||defined(MT6225)||defined(MT6268)||defined(MT6236)||defined(MT6236B)||defined(MT6255)||defined(MT6250)||defined(MT6260)||defined(MT6276)||defined(MT6270A))
	
	#if (defined(MAIN_LCD_8BIT_MODE))
		#if (defined(MT6250)||defined(MT6260))
		SET_LCD_PARALLEL_DATA_BUS(0,0);
		#else
		SET_LCD_PARALLEL_8BIT_DATA_BUS;
		#endif
	#elif (defined(MAIN_LCD_9BIT_MODE) || defined(MAIN_LCD_16BIT_MODE) || defined(MAIN_LCD_18BIT_MODE))
		#if (defined(MT6253T)||defined(MT6253)||defined(MT6253E)||defined(MT6253L)||defined(MT6252H)||defined(MT6252)||defined(MT6225))

	    	#if defined(MAIN_LCD_16BIT_MODE)
			  SET_LCD_PARALLEL_16BIT_DATA_BUS;
	    	#else
			  SET_LCD_PARALLEL_9BIT_DATA_BUS; 
	    	#endif

		#elif (defined(MT6250)||defined(MT6260))
			#if defined(MAIN_LCD_16BIT_MODE)
			  SET_LCD_PARALLEL_DATA_BUS(0,2);
	    	#else
			  SET_LCD_PARALLEL_DATA_BUS(0,1);
	    	#endif
		
		#endif
		#if (defined(MT6228)||defined(MT6229)||defined(MT6268T)||defined(MT6268H)||defined(MT6230))
			#ifndef MT6268H
			GPIO_ModeSetup(10, 1);
			GPIO_ModeSetup(11, 1);
			#endif
			GPIO_ModeSetup(54, 0);
			GPIO_ModeSetup(55, 0);
			GPIO_ModeSetup(56, 0);
			GPIO_ModeSetup(57, 0);
			GPIO_ModeSetup(58, 0);
			GPIO_ModeSetup(59, 0);
			GPIO_ModeSetup(60, 0);
			GPIO_ModeSetup(61, 0);
		#elif (defined(MT6226)||defined(MT6227))
			GPIO_ModeSetup(55, 1);
			*((volatile unsigned short *) 0x801201B0) |= 0x4000;
			*((volatile unsigned short *) 0x801201D0) |= 0x0001;
		#elif (defined(MT6235)||defined(MT6235B)||defined(MT6238)||defined(MT6239)||defined(MT6268A)||defined(MT6239)||defined(MT6253T)||defined(MT6268))
			GPIO_ModeSetup(20, 1);
			GPIO_ModeSetup(21, 1);
		#endif
	#endif

	#if (defined(MT6253T)||defined(MT6253)||defined(MT6225))
		  SET_LCD_PARALLEL_CE2WR_SETUP_TIME((kal_uint32)1);
		  SET_LCD_PARALLEL_CE2WR_HOLD_TIME(1);
		  SET_LCD_PARALLEL_CE2RD_SETUP_TIME(0);
		  SET_LCD_PARALLEL_WRITE_WAIT_STATE(3);
		  SET_LCD_PARALLEL_READ_LATENCY_TIME(10);
		  SET_LCD_ROI_CTRL_CMD_LATENCY(0);
	#elif (defined(MT6253E)||defined(MT6253L)||defined(MT6252H)||defined(MT6252)||defined(MT6250)||defined(MT6260))
		#if defined(_LCM_ON_EMI_)//Tristan
		  SET_EMI_BANK2_CE2WR_SETUP_TIME(2);//2);
		  SET_EMI_BANK2_CE2WR_HOLD_TIME(2);//1);
		  SET_EMI_BANK2_CE2RD_SETUP_TIME(2);
		  SET_EMI_BANK2_WRITE_WAIT_STATE_TIME(3);//5);
		  SET_EMI_BANK2_READ_LATENCY_TIME(10);
		  SET_LCD_ROI_CTRL_CMD_LATENCY(2);	 
	 	#else
  
			#if (defined(MT6250)||defined(MT6260))
		  		SET_LCD_PARALLEL_IF_TIMING(0, LCD_PARALLEL_CLOCK_104MHZ, 0, 1, 3, 2, 2, 16, 1);
			#else
				SET_LCD_PARALLEL_CE2WR_SETUP_TIME(2);
				SET_LCD_PARALLEL_CE2WR_HOLD_TIME(2);//1);
				SET_LCD_PARALLEL_CE2RD_SETUP_TIME(1);
				SET_LCD_PARALLEL_WRITE_WAIT_STATE(5);//5);
				SET_LCD_PARALLEL_READ_LATENCY_TIME(10);
				SET_LCD_ROI_CTRL_CMD_LATENCY(5)
		    #endif
	 	#endif
	#elif (defined(MT6268A)||defined(MT6268)||defined(MT6255)||defined(MT6276)) 
		  SET_LCD_PARALLEL_CE2WR_SETUP_TIME(0x1);//1
		  SET_LCD_PARALLEL_CE2WR_HOLD_TIME(0x1);//1
		  SET_LCD_PARALLEL_CE2RD_SETUP_TIME(0x3);//3
		  SET_LCD_PARALLEL_WRITE_WAIT_STATE(0x4);//2
		  SET_LCD_PARALLEL_READ_LATENCY_TIME(0x3);//4	 
		  SET_LCD_ROI_CTRL_CMD_LATENCY(0x0);//4    
	#elif (defined(MT6236)||defined(MT6236B)) 
		  SET_LCD_PARALLEL_CE2WR_SETUP_TIME(0x1);
		  SET_LCD_PARALLEL_CE2WR_HOLD_TIME(0x1);
		  SET_LCD_PARALLEL_CE2RD_SETUP_TIME(0x3);
		  SET_LCD_PARALLEL_WRITE_WAIT_STATE(0x4);
		  SET_LCD_PARALLEL_READ_LATENCY_TIME(0x3);	 
		  SET_LCD_ROI_CTRL_CMD_LATENCY(0x2);//Tianshu's comment for MT6236 ADMUX load		  
	#elif defined(MT6270A)      
		  SET_LCD_PARALLEL_CE2WR_SETUP_TIME((kal_uint32)2);
		  SET_LCD_PARALLEL_CE2WR_HOLD_TIME(1);
		  SET_LCD_PARALLEL_WRITE_WAIT_STATE(5);    
		  SET_LCD_PARALLEL_CE2RD_SETUP_TIME(2);
		  SET_LCD_PARALLEL_READ_LATENCY_TIME(20);
		  SET_LCD_ROI_CTRL_CMD_LATENCY(0);		
	#else
		
		#ifdef __WIFI_SUPPORT__
		  SET_LCD_PARALLEL_CE2WR_SETUP_TIME((kal_uint32)1);
		  SET_LCD_PARALLEL_CE2WR_HOLD_TIME(1);
		  SET_LCD_PARALLEL_CE2RD_SETUP_TIME(2);
		  SET_LCD_PARALLEL_WRITE_WAIT_STATE(3);
		  SET_LCD_PARALLEL_READ_LATENCY_TIME(10);
		  SET_LCD_ROI_CTRL_CMD_LATENCY(4);		
		#else
		  SET_LCD_PARALLEL_CE2WR_SETUP_TIME((kal_uint32)0);
		  SET_LCD_PARALLEL_CE2WR_HOLD_TIME(0);
		  SET_LCD_PARALLEL_CE2RD_SETUP_TIME(2);
		  SET_LCD_PARALLEL_WRITE_WAIT_STATE(2);
		  SET_LCD_PARALLEL_READ_LATENCY_TIME(10);
		  SET_LCD_ROI_CTRL_CMD_LATENCY(4);		
		#endif  

	#endif
	//SET_LCD_PARALLEL_CLOCK_52M;
	#if (defined(MT6236)||defined(MT6236B)) 
	  SET_LCD_PARALLEL0_CLOCK_104M;
	#else
		//SET_LCD_PARALLEL_CLOCK_52M;
	#endif ////(defined(MT6236))     
	  
	#if (defined(MT6236)||defined(MT6236B))
		CONFIG_LCD_CTRL_PIN_DRIVING_CURRNET(LCD_DRIVING_6MA);
		CONFIG_LCD_DATA_PIN_DRIVING_CURRNET(LCD_DRIVING_6MA);
	#elif (defined(MT6253E)||defined(MT6253L)||defined(MT6252H)||defined(MT6252)||defined(MT6250)||defined(MT6260))
		#if (defined(MT6250_EVB))
		set_lcd_driving_current(LCD_DRIVING_8MA);
		#else
		set_lcd_driving_current(LCD_DRIVING_8MA);
		#endif
	#endif
		  
	#if (defined(MT6226)||defined(MT6227)||defined(MT6229)||defined(MT6268T)||defined(MT6268H)||defined(MT6230)||defined(MT6235)||defined(MT6235B)||defined(MT6238)||defined(MT6239)||defined(MT6268A)||defined(MT6239)||defined(MT6253T)||defined(MT6253)||defined(MT6225)||defined(MT6268)||defined(MT6255)||defined(MT6276)||defined(MT6236)||defined(MT6236B)||defined(MT6270A))
	  //MT6253E, MT6253L, MT6255 and MT6276 have no layer gamma
	  SET_LCD_PARALLEL_GAMMA_R_TABLE(LCD_PARALLEL_GAMMA_DISABLE);
	  SET_LCD_PARALLEL_GAMMA_G_TABLE(LCD_PARALLEL_GAMMA_DISABLE);
	  SET_LCD_PARALLEL_GAMMA_B_TABLE(LCD_PARALLEL_GAMMA_DISABLE);
	#endif
	
	#ifdef DUAL_LCD
	  SET_LCD_PARALLEL1_CE2WR_SETUP_TIME((kal_uint32)0);
	  SET_LCD_PARALLEL1_CE2WR_HOLD_TIME(0);
	  SET_LCD_PARALLEL1_CE2RD_SETUP_TIME(2);
	  SET_LCD_PARALLEL1_WRITE_WAIT_STATE(1);
	  SET_LCD_PARALLEL1_READ_LATENCY_TIME(10);
	  SET_LCD_ROI_CTRL_CMD_LATENCY(0);
	  
		#if (defined(SUB_LCD_8BIT_MODE))
			SET_LCD_PARALLEL1_8BIT_DATA_BUS;	  
		#elif (defined(SUB_LCD_9BIT_MODE))
			SET_LCD_PARALLEL1_9BIT_DATA_BUS;
		#elif (defined(SUB_LCD_16BIT_MODE))
			SET_LCD_PARALLEL1_16BIT_DATA_BUS; 
		#elif (defined(SUB_LCD_18BIT_MODE))
			SET_LCD_PARALLEL1_18BIT_DATA_BUS;
		#ifndef MT6268H  
			GPIO_ModeSetup(10, 1);
			GPIO_ModeSetup(11, 1);
		#endif
		#endif
		
	  	SET_LCD_PARALLEL1_CLOCK_52M;
		
		#if (defined(MT6226)||defined(MT6227)||defined(MT6229)||defined(MT6268T)||defined(MT6268H)||defined(MT6230)||defined(MT6235)||defined(MT6235B)||defined(MT6238)||defined(MT6239)||defined(MT6268A)||defined(MT6239)||defined(MT6253T)||defined(MT6253)||defined(MT6225)||defined(MT6268)||defined(MT6255)||defined(MT6276)||defined(MT6236)||defined(MT6236B)||defined(MT6270A))
		  //MT6253E, MT6253L, MT6255 and MT6276 have no layer gamma
		  SET_LCD_PARALLEL1_GAMMA_TABLE(LCD_PARALLEL_GAMMA_DISABLE);
		#endif
	#endif
#elif (defined(MT6255)||defined(MT6276))
	  //************Interface Bus***************
  #if (defined(MAIN_LCD_8BIT_MODE))
	  SET_LCD_PARALLEL_DATA_BUS(0, LCD_PARALLEL_BUS_WIDTH_8BIT);//SET_LCD_PARALLEL_8BIT_DATA_BUS;
  #elif (defined(MAIN_LCD_9BIT_MODE))
	  SET_LCD_PARALLEL_DATA_BUS(0, LCD_PARALLEL_BUS_WIDTH_9BIT);//SET_LCD_PARALLEL_9BIT_DATA_BUS;
  #elif (defined(MAIN_LCD_16BIT_MODE))
	  SET_LCD_PARALLEL_DATA_BUS(0, LCD_PARALLEL_BUS_WIDTH_16BIT);//SET_LCD_PARALLEL_16BIT_DATA_BUS; 		   
  #elif (defined(MAIN_LCD_18BIT_MODE))
	  SET_LCD_PARALLEL_DATA_BUS(0, LCD_PARALLEL_BUS_WIDTH_18BIT);//SET_LCD_PARALLEL_18BIT_DATA_BUS;
  #endif
	  //************Interface Timing*************** 		 
	  SET_LCD_PARALLEL_IF_TIMING(0, 0, 1, 1, 4, 3, 3, 0);		  
	  DISABLE_LCD_PARALLEL0_GAMMA(backup_val);
#elif (defined(MT6217))
#endif


}
	


#ifdef LQT_SUPPORT/*Do not remove LQT code segment*/
/*************************************************************************
* FUNCTION
*   LCD_gamma_test() and LCD_flicker_test()
*
* DESCRIPTION
*   Generating test pattern by AT commands.
*
* PARAMETERS
*   level, color
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void LCD_gamma_test_ILI9486(kal_uint8 level, kal_uint8 color)
{
	kal_uint16 LCD_x;
	kal_uint16 LCD_y;
	kal_uint16 r_color,g_color,b_color,w_color;
    kal_uint32 lcd_layer0_buffer;	

  		  		
	lcd_layer0_buffer=REG_LCD_LAYER0_BUFF_ADDR;
	r_color=(level>>1)<<11;	/* transfer to RGB565 */
	g_color=level<<5;
	b_color=level>>1;
	w_color=(r_color|g_color|b_color);
	for(LCD_y=0;LCD_y<LCD_HEIGHT;LCD_y++)
	{
		for(LCD_x=0;LCD_x<LCD_WIDTH/2;LCD_x++)
		{
			switch(color)
			{
	      case 0:
					*((kal_uint32 *)lcd_layer0_buffer+LCD_y*(LCD_WIDTH/2)+LCD_x)= ((w_color<<16)|w_color);
					break;					
				case 1:
					*((kal_uint32 *)lcd_layer0_buffer+LCD_y*(LCD_WIDTH/2)+LCD_x)= ((r_color<<16)|r_color);
					break;
	      case 2:
					*((kal_uint32 *)lcd_layer0_buffer+LCD_y*(LCD_WIDTH/2)+LCD_x)= ((g_color<<16)|g_color);
					break;
	      case 3:
					*((kal_uint32 *)lcd_layer0_buffer+LCD_y*(LCD_WIDTH/2)+LCD_x)= ((b_color<<16)|b_color);
					break;

	      default:
	         ASSERT(0);
			}
		}
	}		
}

void LCD_flicker_test_ILI9486(kal_uint8 level)
{
		kal_uint16 LCD_x;
		kal_uint16 LCD_y;
		kal_uint16 r_color,g_color,b_color,w_color;
    kal_uint32 lcd_layer0_buffer;	
    	
	  lcd_layer0_buffer=REG_LCD_LAYER0_BUFF_ADDR;
	  r_color=(level>>1)<<11;	/* transfer to RGB565 */
	  g_color=level<<5;
	  b_color=level>>1;
	  w_color=(r_color|g_color|b_color);
		
		for(LCD_y=0;LCD_y<LCD_HEIGHT;LCD_y++)
		{
			if(LCD_y&0x1)
			{
				for(LCD_x=0;LCD_x<LCD_WIDTH/2;LCD_x++)
						*((kal_uint32 *)lcd_layer0_buffer+LCD_y*(LCD_WIDTH/2)+LCD_x)= ((w_color<<16)|w_color);
			}
			else
			{
				for(LCD_x=0;LCD_x<LCD_WIDTH/2;LCD_x++)
					*((kal_uint32 *)lcd_layer0_buffer+LCD_y*(LCD_WIDTH/2)+LCD_x)=0x0;
			}
		}	
}
#endif/*LQT_SUPPORT*/


/***********************ILI9486********************************/
/*ILI, 262K Color LCD, Parallel Interface, Firefly development board*/

#define WMLCDCOM	LCD_CtrlWrite_ILI9486
#define WMLCDDATA	LCD_DataWrite_ILI9486 



void LCD_Partial_On_ILI9486(kal_uint16 start_page,kal_uint16 end_page)
{

}

void LCD_Partial_Off_ILI9486(void)
{

}

kal_uint8 LCD_Partial_line_ILI9486(void)
{
	return 1;		/* partial display in 1 line alignment */
}

void LCD_Set_Y_Addr_ILI9486(kal_uint16 start_row, kal_uint16 end_row)
{

}

void LCD_Set_X_Addr_ILI9486(kal_uint16 start_column, kal_uint16 end_column)
{

}

void LCD_blockClear_ILI9486(kal_uint16 x1,kal_uint16 y1,kal_uint16 x2,kal_uint16 y2,kal_uint16 data)
{
	kal_uint16 LCD_x;
	kal_uint16 LCD_y;
	kal_uint8 r_color,g_color,b_color;
	kal_uint8 x1_high,x1_low,y1_high,y1_low,x2_high,x2_low,y2_high,y2_low;


	x1_high=(x1&0xFF00)>>8;
	x1_low=x1&0xFF;
	y1_high=(y1&0xFF00)>>8;
	y1_low=y1&0xFF;
	x2_high=(x2&0xFF00)>>8;
	x2_low=x2&0xFF;
	y2_high=((y2)&0xFF00)>>8;
	y2_low=(y2)&0xFF;

#ifdef MAIN_LCD_9BIT_MODE
	r_color=(data&0xF800)>>10;	/* transfer to RGB666 */
	g_color=(data>>5)&0x3F;
	b_color=((data)&0x1F)<<1;
#endif

    WMLCDCOM(0x2A);
	WMLCDDATA(((x1&0xFF00)>>8));
	WMLCDDATA((x1&0xFF));
	WMLCDDATA(((x2&0xFF00)>>8));
	WMLCDDATA((x2&0xFF));
    WMLCDCOM(0x2B);
	WMLCDDATA(((y1&0xFF00)>>8));
	WMLCDDATA((y1&0xFF));
	WMLCDDATA(((y2&0xFF00)>>8));
	WMLCDDATA((y2&0xFF));
	
	WMLCDCOM(0x2C);

	//data = 0xF800;
	for(LCD_y=y1;LCD_y<=y2;LCD_y++)
	{
		for(LCD_x=x1;LCD_x<=x2;LCD_x++)
		{
		#if (defined(MAIN_LCD_8BIT_MODE))
			*((volatile unsigned char *) MAIN_LCD_DATA_ADDR)=(kal_uint8)((data&0xFF00)>>8);
			*((volatile unsigned char *) MAIN_LCD_DATA_ADDR)=(kal_uint8)(data&0xFF);			
		#elif (defined(MAIN_LCD_9BIT_MODE))
			*((volatile unsigned short *) MAIN_LCD_DATA_ADDR)=((r_color<<6)|(g_color>>3)<<9);
			*((volatile unsigned short *) MAIN_LCD_DATA_ADDR)=((((g_color&0x07)<<6)|b_color)<<9);		
		#elif (defined(MAIN_LCD_16BIT_MODE) || defined(MAIN_LCD_18BIT_MODE))
			*((volatile unsigned int *) MAIN_LCD_DATA_ADDR)=(r_color<<12)|(g_color<<6)|b_color;
		#endif
		}
	}

}

void LCD_ClearAll_ILI9486(kal_uint16 data)
{
   LCD_blockClear_ILI9486(0,0,LCD_WIDTH-1,LCD_HEIGHT-1,data);
}


void LCD_Init_ILI9486(kal_uint32 bkground, void **buf_addr)
{
	// Enhance LCD I/F driving current.
#if defined(MT6238)
	*((volatile unsigned short *) 0x80010700) |= 0xE0E0;
#endif
	//bst2_log("%s:",__func__);


	LCDDelayms(10);
	SET_LCD_CTRL_RESET_PIN;
	LCDDelayms(20);
	CLEAR_LCD_CTRL_RESET_PIN;
	LCDDelayms(20); 
	SET_LCD_CTRL_RESET_PIN;
	LCDDelayms(140);


#if 1  //for ILI9486+ LGD 3.2' 
		   //VCC=IOVCC=2.8V  9Bit
	WMLCDCOM(0xF1);
	WMLCDDATA(0x36);
	WMLCDDATA(0x04);
	WMLCDDATA(0x00);
	WMLCDDATA(0x3C);
	WMLCDDATA(0x0F);
	WMLCDDATA(0x8F);
	LCDDelayms(1);
	
	WMLCDCOM(0xF2);//
	WMLCDDATA(0x18);
	WMLCDDATA(0xA3);
	WMLCDDATA(0x12);
	WMLCDDATA(0x02);
	WMLCDDATA(0xB2);
	WMLCDDATA(0x12);
	WMLCDDATA(0xFF);
	WMLCDDATA(0x10);
	WMLCDDATA(0x00);
	LCDDelayms(1);
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	
	WMLCDCOM(0xF8);//
	WMLCDDATA(0x21);
	WMLCDDATA(0x04);
	LCDDelayms(1);
	WMLCDCOM(0xF9);//
	WMLCDDATA(0x00);
	WMLCDDATA(0x08);
	LCDDelayms(1);
	
	WMLCDCOM(0x36);//
	WMLCDDATA(0x48);

	// LCM CS time = 320*480*2*(1+0+2+4+2)/104M = 26.58ms, 再预留15%的margin,即30.57ms。
	// 因此，frame rate< 1/(30.57/2) = 65.4Hz
	//timing无法优化。
	LCDDelayms(1);
	
	WMLCDCOM(0xB1);//FRAME RATE 

	WMLCDDATA(0xC0);/*set 74.6 Hz,*/
	WMLCDDATA(0x11);

//#if (defined(__MMI_MAINLCD_240X400__)||defined(__MMI_MAINLCD_240X320__))
//	WMLCDDATA(0xA0);/*set 55.6 Hz,*/
//	WMLCDDATA(0x12);
//#else
//	WMLCDDATA(0xC0);/*set 74.6 Hz,*/
//	WMLCDDATA(0x11);
//#endif

	//WMLCDDATA(0xB0);/*set 61.7 Hz */
	//WMLCDDATA(0x12);
	
	//WMLCDDATA(0xC0);/*set 70.4 Hz */
	//WMLCDDATA(0x12);
	
	LCDDelayms(1);
	
	WMLCDCOM(0xB4);//DOT inversion
	WMLCDDATA(0x02);// 0x03
	LCDDelayms(1);
	
	WMLCDCOM(0xB6);//
	WMLCDDATA(0x00);
	WMLCDDATA(0x02);//
	LCDDelayms(1);
	
	WMLCDCOM(0xC0);//Power Control 1	
	WMLCDDATA(0x0D);//Sets the VREG1OUT voltage for positive gamma 
	WMLCDDATA(0x0D);//Sets the VREG2OUT voltage for negative gamma 
	LCDDelayms(1);
	
	WMLCDCOM(0xC1);//DDVDH/DDVDL/VCL/VGH/VGL
	WMLCDDATA(0x44);
	LCDDelayms(1);
	
	WMLCDCOM(0xC5);//VCOM
	WMLCDDATA(0x00);
	WMLCDDATA(0x3A);//
	LCDDelayms(1);
	
	WMLCDCOM(0xE0);//
	WMLCDDATA(0x0F);
	WMLCDDATA(0x1F);
	WMLCDDATA(0x1C);
	WMLCDDATA(0x0C);
	WMLCDDATA(0x0F);
	WMLCDDATA(0x08);
	WMLCDDATA(0x48);
	WMLCDDATA(0x98);
	WMLCDDATA(0x37);
	WMLCDDATA(0x0A);
	WMLCDDATA(0x13);
	WMLCDDATA(0x04);
	WMLCDDATA(0x11);
	WMLCDDATA(0x0D);
	WMLCDDATA(0x00);
	LCDDelayms(1);
	
	WMLCDCOM(0xE1);//
	WMLCDDATA(0x0F);
	WMLCDDATA(0x32);
	WMLCDDATA(0x2E);
	WMLCDDATA(0x0B);
	WMLCDDATA(0x0D);
	WMLCDDATA(0x05);
	WMLCDDATA(0x47);
	WMLCDDATA(0x75);
	WMLCDDATA(0x37);
	WMLCDDATA(0x06);
	WMLCDDATA(0x10);
	WMLCDDATA(0x03);
	WMLCDDATA(0x24);
	WMLCDDATA(0x20);
	WMLCDDATA(0x00);
	LCDDelayms(1);
	
	WMLCDCOM(0x3A);//Set Pixel Format
	WMLCDDATA(0x66); // 18bpp
	//WMLCDDATA(0x55);

	WMLCDCOM(0x44);//Tear Scan Line -- 01
	WMLCDDATA(0x00);// N[15:8]
	WMLCDDATA(0x01);// N[7:0]
	
	WMLCDCOM(0x35);//TE ON
	WMLCDCOM(0x00);//TE ON Vsync
	//WMLCDCOM(0x34);//TE OFF
	LCDDelayms(1);
	WMLCDCOM(0x21);//
	LCDDelayms(20);
	WMLCDCOM(0x11);//
	LCDDelayms(150);//120ms
	WMLCDCOM(0x29);//


	LCDDelayms(150);
	
    LCD_ClearAll_ILI9486(0x00);
	
#endif

}



void LCD_EnterSleep_ILI9486(void)
{
#if defined(LQT_SUPPORT)/*Do not remove LQT code segment*/
 if(!(lcd_at_mode==LCD_AT_RELEASE_MODE))
 {
  return;
 }	
#endif /*defined(LQT_SUPPORT))*/	
	//bst2_log("%s:",__func__);

	WMLCDCOM(0x28);
	LCDDelayms(10);  
	WMLCDCOM(0x10);
	LCDDelayms(120); 
}

void LCD_ExitSleep_ILI9486(void)
{
#if defined(LQT_SUPPORT)/*Do not remove LQT code segment*/
 if(!(lcd_at_mode==LCD_AT_RELEASE_MODE))
 {
  return;
 }	
#endif /*defined(LQT_SUPPORT))*/
	//bst2_log("%s:",__func__);

	WMLCDCOM(0x11);
	LCDDelayms(120); 
	WMLCDCOM(0x29);
	LCDDelayms(150);

	//LCD_Init_HX8352B(0,NULL);
}


void LCD_PWRON_ILI9486(kal_bool on)
{
   if(on)
   {
      LCD_ExitSleep_ILI9486();
   }
   else
   {
      LCD_EnterSleep_ILI9486();
   }
}

void LCD_SetContrast_ILI9486(kal_uint8 level)
{
}

void LCD_ON_ILI9486(kal_bool on)
{
   if (on)
   {
      LCD_ExitSleep_ILI9486();
   }
   else
   {
      LCD_EnterSleep_ILI9486();
   }
}

void LCD_BlockWrite_ILI9486(kal_uint16 startx,kal_uint16 starty,kal_uint16 endx,kal_uint16 endy)
{

#ifdef LQT_SUPPORT/*Do not remove LQT code segment*/
    if(!lcd_update_permission&&!(lcd_at_mode==LCD_AT_RELEASE_MODE))
    {
    	lcd_assert_fail = KAL_FALSE;
    	return;//in LQT mode but not update permitted
    }
    if(lcd_update_permission&&!(lcd_at_mode==LCD_AT_RELEASE_MODE))
    {
    	startx = 0;
    	starty = 0;
    	endx = LCD_WIDTH -1;
    	endy = LCD_HEIGHT -1; //in LQT mode and update permitted
    }
#endif /*LQT_SUPPORT*/

#if defined(__RF_DESENSE_TEST__)&& defined(__FM_DESENSE_COPY_NO_LCM_UPDATE_)
   // under this test, LCD will do nothing ==> just return this function call
   return;
#endif

	ASSERT(lcd_assert_fail==KAL_FALSE);
	lcd_assert_fail = KAL_TRUE;

#if defined(LCD_CMD_DMA_MODE)

	SET_LCD_CMD_PARAMETER(0,LCD_CMD,0x2A);                            //column address set
	SET_LCD_CMD_PARAMETER(1,LCD_DATA,((startx&0xFF00)>>8));
	SET_LCD_CMD_PARAMETER(2,LCD_DATA,(startx&0xFF));
	SET_LCD_CMD_PARAMETER(3,LCD_DATA,((endx&0xFF00)>>8));
	SET_LCD_CMD_PARAMETER(4,LCD_DATA,(endx&0xFF));

	SET_LCD_CMD_PARAMETER(5,LCD_CMD,0x2B);                            //Row address set
	SET_LCD_CMD_PARAMETER(6,LCD_DATA,((starty&0xFF00)>>8));
	SET_LCD_CMD_PARAMETER(7,LCD_DATA,(starty&0xFF));
	SET_LCD_CMD_PARAMETER(8,LCD_DATA,((endy&0xFF00)>>8));
	SET_LCD_CMD_PARAMETER(9,LCD_DATA,(endy&0xFF));

	SET_LCD_CMD_PARAMETER(10,LCD_CMD,0x2C);							  //memory write

	SET_LCD_ROI_CTRL_NUMBER_OF_CMD(11);

	ENABLE_LCD_TRANSFER_COMPLETE_INT;
	ENABLE_LCD_ROI_CTRL_CMD_FIRST;
	START_LCD_TRANSFER;
#else
	WMLCDCOM(0x2A);
	WMLCDDATA(((startx&0xFF00)>>8));
	WMLCDDATA((startx&0xFF));
	WMLCDDATA(((endx&0xFF00)>>8));
	WMLCDDATA((endx&0xFF));
    WMLCDCOM(0x2B);
	WMLCDDATA(((starty&0xFF00)>>8));
	WMLCDDATA((starty&0xFF));
	WMLCDDATA(((endy&0xFF00)>>8));
	WMLCDDATA((endy&0xFF));
	
	WMLCDCOM(0x2C);

	ENABLE_LCD_TRANSFER_COMPLETE_INT;//Kate
	DISABLE_LCD_ROI_CTRL_CMD_FIRST;
	START_LCD_TRANSFER;
#endif

	 lcd_assert_fail = KAL_FALSE;
}


void LCD_Size_ILI9486(kal_uint16 *out_LCD_width,kal_uint16 *out_LCD_height)
{
   *out_LCD_width = LCD_WIDTH;
   *out_LCD_height = LCD_HEIGHT;
}

/*Engineering mode*/
kal_uint8 LCD_GetParm_ILI9486(lcd_func_type type)
{
   switch(type)
   {
      case lcd_Bais_func:
         return 1;
      case lcd_Contrast_func:
         return 1;
      case lcd_LineRate_func:
         return 1;
      case lcd_Temperature_Compensation_func:
         return 1;
      default:
         ASSERT(0);
      return 100;
   }
}

void LCD_SetBias_ILI9486(kal_uint8 *bias)
{
}

void LCD_Contrast_ILI9486(kal_uint8 *contrast)
{
}

void LCD_LineRate_ILI9486(kal_uint8 *linerate)
{
}

void LCD_Temp_Compensate_ILI9486(kal_uint8 *compensate)
{
}

void LCD_Set_Scan_Direction_ILI9486(kal_uint8 rotate_value)
{
	switch (rotate_value)
	{	
		#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
		break;
	}

}	/* LCD_Set_Scan_Direction_HX8352B() */
LCM_IOCTRL_STATUS_ENUM
LCD_IOCTRL_ILI9486(LCM_IOCTRL_ID_ENUM ID, void* Parameters)
{
  
  
   switch (ID)
   {
       case LCM_IOCTRL_QUERY__FRAME_RATE:
       {
             *(kal_uint32*) (Parameters) =  74.6;
             
            return LCM_IOCTRL_OK;
             
       }

       case LCM_IOCTRL_SET__FRAME_RATE:
       {
	   		 return LCM_IOCTRL_NOT_SUPPORT;
            
       }


       case LCM_IOCTRL_QUERY__FRAME_MARKER:
	   	 	return LCM_IOCTRL_NOT_SUPPORT;

       case LCM_IOCTRL_SET__FRAME_MARKER:
            return LCM_IOCTRL_NOT_SUPPORT;


       case LCM_IOCTRL_QUERY__SUPPORT_H_V_SIGNAL_FUNC:
       {
	   		 return LCM_IOCTRL_NOT_SUPPORT;
       }

       case LCM_IOCTRL_QUERY__SUPPORT_V_PULSE_WIDTH:
       {
			 return LCM_IOCTRL_NOT_SUPPORT;
			
       }

       case LCM_IOCTRL_QUERY__SUPPORT_H_PULSE_WIDTH:
                return LCM_IOCTRL_NOT_SUPPORT;


       case LCM_IOCTRL_QUERY__BACK_PORCH:
       {
            *(kal_uint32*) (Parameters) = 2; // for example
            return LCM_IOCTRL_OK;
       }

       case LCM_IOCTRL_QUERY__FRONT_PORCH:
       {
            *(kal_uint32*) (Parameters) = 6; // for example
            return LCM_IOCTRL_OK;
       }

       case LCM_IOCTRL_SET__BACK_PORCH:
       {
	   	 return LCM_IOCTRL_NOT_SUPPORT;
       }

       case LCM_IOCTRL_SET__FRONT_PORCH:
       {
	   	 return LCM_IOCTRL_NOT_SUPPORT;
       }

       case LCM_IOCTRL_QUERY__TE_EDGE_ATTRIB:
       {
	   		return LCM_IOCTRL_NOT_SUPPORT;
       }

       case LCM_IOCTRL_QUERY__SUPPORT_READBACK_FUNC:
            return LCM_IOCTRL_NOT_SUPPORT;

       case LCM_IOCTRL_QUERY__SCANLINE_REG:
            return LCM_IOCTRL_NOT_SUPPORT;

       case LCM_IOCTRL_QUERY__IF_CS_NUMBER:
       {
            *(kal_uint32*) (Parameters) =  LCD_IF_PARALLEL_0;
            return LCM_IOCTRL_OK;
       }

       case LCM_IOCTRL_QUERY__LCM_WIDTH:
       {
            *(kal_uint32*) (Parameters) =  320;
            return LCM_IOCTRL_OK;
       }

       case LCM_IOCTRL_QUERY__LCM_HEIGHT:
       {
            *(kal_uint32*) (Parameters) =  480;
            return LCM_IOCTRL_OK;
       }
       
     case LCM_IOCTRL_QUERY__SYNC_MODE:

          *(kal_uint32*) (Parameters) = LCM_TE_VSYNC_MODE;
          return LCM_IOCTRL_OK;

     case LCM_IOCTRL_QUERY__FLIP_MIRROR:
          return LCM_IOCTRL_NOT_SUPPORT;

     case LCM_IOCTRL_QUERY__ROTATION:
          return LCM_IOCTRL_OK;
          
     case LCM_IOCTRL_QUERY__LCD_PPI: 
     	  *((kal_uint32*)Parameters) = LCM_DPI;
      	  return LCM_IOCTRL_OK;  
     default:
          return LCM_IOCTRL_NOT_SUPPORT;
          
   }
}


#ifdef COMBO_LCM_ID_AUTO_DETECT
kal_bool LCM_ID_check_ILI9486()
{
    kal_uint8 dummy, ILI9486_1, ILI9486_2, ILI9486_3;

    LCD_CtrlWrite_ILI9486(0x04);  //LCM ID
    dummy = LCD_DataRead_ILI9486;
    ILI9486_1 = LCD_DataRead_ILI9486;
    ILI9486_2 = LCD_DataRead_ILI9486;
    ILI9486_3 = LCD_DataRead_ILI9486;

    if (84 == ILI9486_1 && 128 == ILI9486_2 &&
        102 == ILI9486_3)
      return KAL_TRUE;
    else
      return KAL_FALSE;
}
#endif


LCD_Funcs LCD_func_ILI9486 = {
   LCD_Init_ILI9486,
   LCD_PWRON_ILI9486,
   LCD_SetContrast_ILI9486,
   LCD_ON_ILI9486,
   LCD_BlockWrite_ILI9486,
   LCD_Size_ILI9486,
   LCD_EnterSleep_ILI9486,
   LCD_ExitSleep_ILI9486,
   LCD_Partial_On_ILI9486,
   LCD_Partial_Off_ILI9486,
   LCD_Partial_line_ILI9486,
   /*Engineering mode*/
   LCD_GetParm_ILI9486,
   LCD_SetBias_ILI9486,
   LCD_Contrast_ILI9486,
   LCD_LineRate_ILI9486,
   LCD_Temp_Compensate_ILI9486
#ifdef LCM_ROTATE_SUPPORT
   ,LCD_Set_Scan_Direction_ILI9486
#endif
#ifdef LQT_SUPPORT/*Do not remove LQT code segment*/
   ,LCD_gamma_test_ILI9486
   ,LCD_flicker_test_ILI9486
#endif
  , NULL
   ,LCD_IOCTRL_ILI9486
};

void LCD_FunConfig_ILI9486(void)
{

	MainLCD = &LCD_func_ILI9486;

	#ifdef DUAL_LCD
		//SubLCD = &LCD_func_HD66791;
	#endif
}
