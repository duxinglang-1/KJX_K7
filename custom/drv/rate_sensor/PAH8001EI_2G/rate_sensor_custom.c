
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
 *    motion_sensor_custom.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module is for motion sensor driver.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(__HEART_RATE_SUPPORT__)
#ifndef WIN32
#include "pxialg.h"
#include "MMI_features.h"
#include "TimerEvents.h"
#include "uem_utility.h"
#include "mmi_rp_app_mainmenu_def.h"

kal_uint32 MS_DELAY_TIME	= 350; 
kal_uint8 pah8001_TEMP; 
kal_uint8 pah8001_TEMP00[10]; 
kal_uint8 pah8001_TEMP01[10]; 
kal_bool test1 = KAL_FALSE;
kal_bool test2 = KAL_FALSE;

char MS_sensor_buffer[10];

#define MS_DBG

#define LED_INC_DEC_STEP										2
#define LED_CTRL_EXPO_TIME_HI_BOUND 						496
#define LED_CTRL_EXPO_TIME_LOW_BOUND						32
#define LED_CTRL_EXPO_TIME_HI								420
#define LED_CTRL_EXPO_TIME_LOW								64
#define LED_CURRENT_HI				 						31
#define LED_CURRENT_LOW				 						1
#define STATE_COUNT_TH				 						3

#define DEFAULT_LED_STEP				 						10

kal_uint8 _led_step	= DEFAULT_LED_STEP; 
kal_uint8 _state	= 0 , state_count = 0; 
kal_uint8 _led_current_change_flag	= 0; 
kal_uint8 _sleep_flag	= 1; 

float myHR=0; 
extern void show_HeartRate(void);

kal_bool pah8001_I2C_write_byte(kal_uint8 ucBufferIndex, kal_uint8 pucData)
{
	return pah8001_i2c_send(MS_SLAVE_ADDR,ucBufferIndex,&pucData,1);
}

#define MS_I2C_read(a,b,c) pah8001_i2c_receive(MS_SLAVE_ADDR,a,b,c)
kal_bool pah8001_I2C_read_byte(kal_uint8 ucBufferIndex, kal_uint8 * pucData ,kal_uint32 unDataLength )
{
	return pah8001_i2c_receive(MS_SLAVE_ADDR,ucBufferIndex,pucData, unDataLength);
}


/*It is for mCube time stamp*/
kal_uint32 pah8001_get_milli_time(void)
{
   kal_uint32 time;
   kal_get_time(&time);
   return kal_ticks_to_milli_secs(time);
}

	
extern void ST_8001_Heart_Rate_handler(void);
void pah8001_sensor_init(void)
{

	pah8001_i2c_configure(MS_SLAVE_ADDR, MS_DELAY_TIME); 


	//ST_8001_Heart_Rate_handler();

	pah8001_I2C_read_byte(0x00,pah8001_TEMP00,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x00  %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP00[0] , pah8001_TEMP00[1],pah8001_TEMP00[2],pah8001_TEMP00[3] , pah8001_TEMP00[4],pah8001_TEMP00[5],pah8001_TEMP00[6] , pah8001_TEMP00[7] , pah8001_TEMP00[8] , pah8001_TEMP00[9] );
#endif
	pah8001_I2C_read_byte(0x01,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x01  %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif

	pah8001_I2C_read_byte(0x00,pah8001_TEMP00,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x00  %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP00[0] , pah8001_TEMP00[1],pah8001_TEMP00[2],pah8001_TEMP00[3] , pah8001_TEMP00[4],pah8001_TEMP00[5],pah8001_TEMP00[6] , pah8001_TEMP00[7] , pah8001_TEMP00[8] , pah8001_TEMP00[9] );
#endif
	pah8001_I2C_read_byte(0x01,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x01  %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif


	pah8001_I2C_write_byte(0x06,0x82);
	pah8001_i2c_udelay(10);

	pah8001_I2C_read_byte(0x06,pah8001_TEMP01,1);
#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x06	%x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif


	pah8001_I2C_write_byte(0x09,0x5A);

	pah8001_I2C_read_byte(0x09,pah8001_TEMP01,1);
#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x09	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif


	pah8001_I2C_write_byte(0x05,0x99);

	pah8001_I2C_read_byte(0x05,pah8001_TEMP01,1);
#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x05	  %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif

	pah8001_I2C_read_byte(0x17,&pah8001_TEMP,1);
#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x17   pah8001_TEMP = %x, \r\n" , pah8001_TEMP );
#endif

	pah8001_I2C_write_byte(0x17,pah8001_TEMP|0x80);

	pah8001_I2C_read_byte(0x17,pah8001_TEMP01,1);
#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x17	   %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif


	pah8001_I2C_write_byte(0x27,0xFF);
	pah8001_I2C_read_byte(0x27,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x27		%x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif


	pah8001_I2C_write_byte(0x28,0xFA);

	pah8001_I2C_read_byte(0x28,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x28 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif


	pah8001_I2C_write_byte(0x29,0x0A);

	pah8001_I2C_read_byte(0x29,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x29 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif


	pah8001_I2C_write_byte(0x2A,0xC8);

	pah8001_I2C_read_byte(0x2A,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x2A 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif


	pah8001_I2C_write_byte(0x2B,0xA0);

	pah8001_I2C_read_byte(0x2B,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x2B 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif


	pah8001_I2C_write_byte(0x2C,0x8C);

	pah8001_I2C_read_byte(0x2C,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x2C 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif


	pah8001_I2C_write_byte(0x2D,0x64);
	pah8001_I2C_read_byte(0x2D,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x2D 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif

	pah8001_I2C_write_byte(0x42,0x20);
	pah8001_I2C_read_byte(0x42,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x42 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif

	pah8001_I2C_write_byte(0x48,0x00);
	pah8001_I2C_read_byte(0x48,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x48 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif


	pah8001_I2C_write_byte(0x4D,0x1A);
	pah8001_I2C_read_byte(0x4D,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x4D 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif

	pah8001_I2C_write_byte(0x7A,0xB5);
	pah8001_I2C_read_byte(0x7A,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x7A 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif

	pah8001_I2C_write_byte(0x7F,0x01);
	pah8001_I2C_read_byte(0x7F,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x7F 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif

	pah8001_I2C_write_byte(0x07,0x48);
	pah8001_I2C_read_byte(0x07,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x07 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif


	pah8001_I2C_write_byte(0x23,0x3C);
	pah8001_I2C_read_byte(0x23,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x23 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif

	pah8001_I2C_write_byte(0x26,0x0F);
	pah8001_I2C_read_byte(0x26,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x26 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif

	pah8001_I2C_write_byte(0x2E,0x48);
	pah8001_I2C_read_byte(0x2E,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x2E 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif

	pah8001_I2C_write_byte(0x38,0xEA);
	pah8001_I2C_read_byte(0x38,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x38 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif

	pah8001_I2C_write_byte(0x42,0xA4);
	pah8001_I2C_read_byte(0x42,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x42 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif

	pah8001_I2C_write_byte(0x43,0x41);
	pah8001_I2C_read_byte(0x43,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x43 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif

	pah8001_I2C_write_byte(0x44,0x41);
	pah8001_I2C_read_byte(0x44,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x44 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif


	pah8001_I2C_write_byte(0x45,0x24);
	pah8001_I2C_read_byte(0x45,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x45 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif

	pah8001_I2C_write_byte(0x46,0xC0);
	pah8001_I2C_read_byte(0x46,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x46 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif

	pah8001_I2C_write_byte(0x52,0x32);
	pah8001_I2C_read_byte(0x52,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x52 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif


	pah8001_I2C_write_byte(0x53,0x28);
	pah8001_I2C_read_byte(0x53,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x53 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif

	pah8001_I2C_write_byte(0x56,0x60);
	pah8001_I2C_read_byte(0x56,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x56 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif


	pah8001_I2C_write_byte(0x57,0x28);
	pah8001_I2C_read_byte(0x57,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x57 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif

	pah8001_I2C_write_byte(0x6D,0x02);
	pah8001_I2C_read_byte(0x6D,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x6D 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif

	pah8001_I2C_write_byte(0x0F,0xC8);
	pah8001_I2C_read_byte(0x0F,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x0F 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif

	pah8001_I2C_write_byte(0x7F,0x00);
	pah8001_I2C_read_byte(0x7F,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x7F 	 %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif

	pah8001_I2C_write_byte(0x5D,0x81);
	pah8001_I2C_read_byte(0x5D,pah8001_TEMP01,1);

#ifndef WIN32	 
	kal_prompt_trace(MOD_DRVKBD, "\r\n 0x5D		%x, %x, %x, %x, %x, %x, %x, %x, %x, %x, \r\n" , 
	pah8001_TEMP01[0] , pah8001_TEMP01[1],pah8001_TEMP01[2],pah8001_TEMP01[3] , pah8001_TEMP01[4],pah8001_TEMP01[5],pah8001_TEMP01[6] , pah8001_TEMP01[7] , pah8001_TEMP01[8] , pah8001_TEMP01[9] );
#endif

}


typedef struct
{
   kal_uint8 HRD_Data[13]; 
   float MEMS_Data[3];

}ppg_mems_data_t;

#define FIFO_SIZE 	8
#define FIFO_SIZE_M1 	(FIFO_SIZE-1)
static ppg_mems_data_t _ppg_mems_data[FIFO_SIZE] ; 
static int _read_index = 0 ; 
static int _write_index = 0 ; 
kal_uint8 Frame_Count=0; 

unsigned char PPG_Data[][13] = 
{
		{1,0x10,0x7f,0x3,0x1,0xa,0xc,0x44,0x14,0x0,0x0,0x80,0x4c},
		{1,0xdd,0xae,0x4c,0x1,0x5,0x7a,0x77,0x15,0x0,0x0,0x80,0x7a},
		{1,0x8b,0x30,0x20,0x6,0x4,0x9c,0x98,0x16,0x0,0x0,0x80,0x9c},
		{1,0xc6,0xaa,0xa0,0x8,0x4,0x95,0x91,0x17,0x0,0x0,0x80,0x95},

		
		{1,0xa2,0x59,0x77,0x8,0x4,0x95,0x91,0x18,0x0,0x0,0x80,0x95},
		{1,0xa4,0xcd,0x76,0x8,0x4,0x9a,0x96,0x19,0x0,0x0,0x80,0x9a},
		{1,0xf,0xbf,0xa8,0x8,0x4,0x9c,0x98,0x1a,0x0,0x0,0x80,0x9c},
		{1,0x7c,0x70,0xdd,0x8,0x3,0xa1,0x9e,0x1b,0x0,0x0,0x80,0xa1},
};

kal_bool isFIFOEmpty(void) 
{ 
 return (_write_index == _read_index) ; 
} 

kal_bool Push(ppg_mems_data_t *data) //Push return data must be KAL_TRUE. If return KAL_FALSE, please increase FIFO size.   
{ 
 int tmp = _write_index ; 
tmp++; 
if(tmp >= FIFO_SIZE) 
  tmp = 0 ; 
 if(tmp == _read_index) 
return KAL_FALSE; 
 _ppg_mems_data[tmp] = *data ;  
 _write_index = tmp ; 
return KAL_TRUE; 
} 

kal_bool Pop(ppg_mems_data_t *data) 
{ 
 int tmp ; 
if(isFIFOEmpty()) 
return KAL_FALSE; 
 *data = _ppg_mems_data[_read_index] ; 
 tmp = _read_index + 1; 
if(tmp >= FIFO_SIZE) 
  tmp = 0 ;
 _read_index = tmp ; 
return KAL_TRUE; 
} 



void led_ctrl(kal_uint8 touch)
{
	if(touch == 0x80)
	{
	kal_uint8 data;
	kal_uint16 frame_average,EP_L,EP_H,Exposure_Line;
	
	pah8001_I2C_write_byte(0x7f,0x00);
	pah8001_I2C_write_byte(0x05,0x98);

	data = pah8001_I2C_read_byte(0x33,&pah8001_TEMP,1);
	EP_H =pah8001_TEMP&0x03;
	data = pah8001_I2C_read_byte(0x32,&pah8001_TEMP,1);
	EP_L =pah8001_TEMP;
	Exposure_Line = (EP_H<<8)+EP_L;

	pah8001_I2C_write_byte(0x7f,0x01);

	if(_sleep_flag == 1)
	{
		pah8001_I2C_write_byte(0x38,(0xE0 | DEFAULT_LED_STEP ));
		_sleep_flag = 0;
	}

	if(state_count <= STATE_COUNT_TH)
	{
		state_count++;
		_led_current_change_flag = 0;
	}
	else
	{
		state_count = 0;
		if(_state == 0) 
		{ 
			if((Exposure_Line>=LED_CTRL_EXPO_TIME_HI_BOUND)|| (Exposure_Line<=LED_CTRL_EXPO_TIME_LOW_BOUND )) 
			{ 
					data = MS_I2C_read(0x38,&pah8001_TEMP,1);
					_led_step=pah8001_TEMP&0x1f; 

 					if( (Exposure_Line>=LED_CTRL_EXPO_TIME_HI_BOUND)&&(_led_step < LED_CURRENT_HI))
					{ 
						_state = 1 ; 

						_led_step =_led_step +LED_INC_DEC_STEP; 

						if(_led_step>LED_CURRENT_HI) 

						_led_step	=LED_CURRENT_HI; 

						pah8001_I2C_write_byte(0x38, (_led_step|0xE0)); 

						_led_current_change_flag = 1; 

					} 
					else if((Exposure_Line<=LED_CTRL_EXPO_TIME_LOW_BOUND) && (_led_step > LED_CURRENT_LOW)) 
					{ 
						_state = 2 ; 
						if(_led_step<=(LED_CURRENT_LOW+LED_INC_DEC_STEP)) 
							_led_step	=LED_CURRENT_LOW; 
						else 
							_led_step	=_led_step-LED_INC_DEC_STEP; 

							pah8001_I2C_write_byte(0x38, (_led_step|0xE0)); 
 
							_led_current_change_flag = 1; 


 					}else 
					{ 
						_state = 0 ; 

						_led_current_change_flag = 0; 
 
					} 
				} 
				else 
				{ 
					_led_current_change_flag = 0; 
				} 

			} 

		else if(_state == 1) 
		{ 
 
			if(Exposure_Line > LED_CTRL_EXPO_TIME_HI) 
			{ 
				_state = 1 ; 

				_led_step=_led_step+LED_INC_DEC_STEP; 
 
				if(_led_step>=LED_CURRENT_HI) 
				{ 
					_state = 0 ; 
					_led_step=LED_CURRENT_HI; 
 
				} 

				pah8001_I2C_write_byte(0x38, (_led_step|0xE0)); 

				_led_current_change_flag = 1; 
 
		} 
		else  
		{ 
			_state = 0 ; 
 
			_led_current_change_flag = 0; 

		} 

	} 
	else 
	{ 

				if(Exposure_Line < LED_CTRL_EXPO_TIME_LOW) 
				{ 
						_state = 2 ; 
						if(_led_step<=(LED_CURRENT_LOW+LED_INC_DEC_STEP))
						{ 
							_state = 0 ; 
							_led_step=LED_CURRENT_LOW; 
						} 
						else 
							_led_step=_led_step - LED_INC_DEC_STEP; 
					
						pah8001_I2C_write_byte(0x38, (_led_step|0xE0)); 
						_led_current_change_flag = 1; 
				} 
				else 
				{ 
					_state = 0; 
					_led_current_change_flag = 0; 
				}
			}
		}
	 
	} 
	else 
	{ 
	 
		pah8001_I2C_write_byte(0x7f,0x00); 

		pah8001_I2C_write_byte(0x05, 0xB8); 

		pah8001_I2C_write_byte(0x7F, 0x01); 

		_led_step = DEFAULT_LED_STEP; 
	
		//writeRegister(0x38, (0xE0 | |DEFAULT_LED_STEP)); 
		//for Asian person only 
		pah8001_I2C_write_byte(0x38, 0xFF);
		_sleep_flag = 1; 
	 
		_led_current_change_flag = 0; 

	} 
	
	
} 

kal_bool Pixart_HRD(void)  
{ 
		kal_uint8 buffer[4]={0}; 		
		kal_uint8 tmp=0; 
		kal_uint32 HWCounter = 0 ; 
		ppg_mems_data_t ppg_mems_data; 
		kal_uint8 PxiAlg_Flag;

		pah8001_I2C_write_byte(0x7F,0x00); //bank0 
		pah8001_I2C_read_byte(0x59 , &tmp,1); 
		//kal_prompt_trace(MOD_DRVKBD, "tmp =%d \r\n",tmp);
		tmp = tmp&0x80;
		//kal_prompt_trace(MOD_DRVKBD, "tmp =%d \r\n",tmp);
		led_ctrl(tmp);
		pah8001_I2C_read_byte(0x68,&ppg_mems_data.HRD_Data[0],1);
		ppg_mems_data.HRD_Data[0] = ppg_mems_data.HRD_Data[0]&0x0f; 
		if(ppg_mems_data.HRD_Data[0] ==0) 
		{ 
			pah8001_I2C_write_byte(0x7F,0x00); //bank0 
			return KAL_FALSE; 
		} 
		else 
		{ 

			pah8001_I2C_read_byte(0x64,&ppg_mems_data.HRD_Data[1],4);
			//pah8001_I2C_read_byte(0x65,&ppg_mems_data.HRD_Data[2],1);
			//pah8001_I2C_read_byte(0x66,&ppg_mems_data.HRD_Data[3],1);
			//pah8001_I2C_read_byte(0x67,&ppg_mems_data.HRD_Data[4],1);

			pah8001_I2C_read_byte(0x1A,&ppg_mems_data.HRD_Data[5],3);
			//pah8001_I2C_read_byte(0x1B,&ppg_mems_data.HRD_Data[6],1);
			//pah8001_I2C_read_byte(0x1C,&ppg_mems_data.HRD_Data[7],1);

			
			ppg_mems_data.HRD_Data[1]=ppg_mems_data.HRD_Data[1]&0xff; 
			ppg_mems_data.HRD_Data[2]=ppg_mems_data.HRD_Data[2]&0xff; 
			ppg_mems_data.HRD_Data[3]=ppg_mems_data.HRD_Data[3]&0xff; 
			ppg_mems_data.HRD_Data[4]=ppg_mems_data.HRD_Data[4]&0xff; 

			ppg_mems_data.HRD_Data[5]=ppg_mems_data.HRD_Data[5]&0xff; 
			ppg_mems_data.HRD_Data[6]=ppg_mems_data.HRD_Data[6]&0xff; 
			ppg_mems_data.HRD_Data[7]=ppg_mems_data.HRD_Data[7]&0xff; 

		
			ppg_mems_data.HRD_Data[8]=Frame_Count++; 

			ppg_mems_data.HRD_Data[9]=0 ; 

			ppg_mems_data.HRD_Data[10]=_led_current_change_flag; 
			pah8001_I2C_write_byte(0x7F,0x00); //bank0 

			pah8001_I2C_read_byte(0x59 , &ppg_mems_data.HRD_Data[11],1);
			ppg_mems_data.HRD_Data[11]=ppg_mems_data.HRD_Data[11]&0x80;
			ppg_mems_data.HRD_Data[12]= ppg_mems_data.HRD_Data[6]; 

			ppg_mems_data.MEMS_Data[0] = 0; 
			ppg_mems_data.MEMS_Data[1] = 0; 
			ppg_mems_data.MEMS_Data[2] = 0; 

			
			/*kal_prompt_trace(MOD_DRVKBD, "{PPG_GSENSOR_RAW_DATA,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%f,%f,%f},\r\n",
				ppg_mems_data.HRD_Data[0],ppg_mems_data.HRD_Data[1],ppg_mems_data.HRD_Data[2],ppg_mems_data.HRD_Data[3],
				ppg_mems_data.HRD_Data[4],ppg_mems_data.HRD_Data[5],ppg_mems_data.HRD_Data[6],ppg_mems_data.HRD_Data[7],
				ppg_mems_data.HRD_Data[8],ppg_mems_data.HRD_Data[9],ppg_mems_data.HRD_Data[10] ,ppg_mems_data.HRD_Data[11],ppg_mems_data.HRD_Data[12],
				ppg_mems_data.MEMS_Data[0],ppg_mems_data.MEMS_Data[1],ppg_mems_data.MEMS_Data[2]);
			
			PxiAlg_Process(ppg_mems_data.HRD_Data, ppg_mems_data.MEMS_Data);
			
			PxiAlg_HrGet(&myHR);

			kal_prompt_trace(MOD_DRVKBD, "myHR =  %d ",myHR); 	*/	

			Push(&ppg_mems_data); 


			/*if(!isFIFOEmpty())
			{
				if(Pop(&ppg_mems_data))
				{
					kal_prompt_trace(MOD_DRVKBD, "{PPG_GSENSOR_RAW_DATA,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d},\r\n",ppg_mems_data.HRD_Data[0],ppg_mems_data.HRD_Data[1],ppg_mems_data.HRD_Data[2],ppg_mems_data.HRD_Data[3],ppg_mems_data.HRD_Data[4]
					   ,ppg_mems_data.HRD_Data[5],ppg_mems_data.HRD_Data[6],ppg_mems_data.HRD_Data[7],ppg_mems_data.HRD_Data[8],ppg_mems_data.HRD_Data[9],ppg_mems_data.HRD_Data[10]
					   ,ppg_mems_data.HRD_Data[11],ppg_mems_data.HRD_Data[12],ppg_mems_data.MEMS_Data[0],ppg_mems_data.MEMS_Data[1],ppg_mems_data.MEMS_Data[2]);
					
					PxiAlg_Flag = PxiAlg_Process(ppg_mems_data.HRD_Data, ppg_mems_data.MEMS_Data);
			
					kal_prompt_trace(MOD_DRVKBD, "PxiAlg_Flag == %d! " , PxiAlg_Flag);		
			
					if(PxiAlg_Flag == FLAG_DATA_READY)
					{
						PxiAlg_HrGet(&myHR);
					}
					else
					{
						 PxiAlg_HrGet(&myHR);
						 if(PxiAlg_Flag== FLAG_DATA_LOSS)
							 kal_prompt_trace(MOD_DRVKBD, "40ms is not good! ");		 
						 if(PxiAlg_Flag== FLAG_FIFO_ERROR)
							 kal_prompt_trace(MOD_DRVKBD, "FIFO_SIZE is not enough! "); 	 
					}
					kal_prompt_trace(MOD_DRVKBD, "myHR =  %d ",myHR); 		
					
				}
			}
			else
			{
				kal_prompt_trace(MOD_DRVKBD, "isFIFOEmpty " ); 		
			}*/
			return KAL_TRUE; 
	} 
} 

void TimeISR()
{
	//kal_uint32 curr_frc , ticks_ptrgxx;
	//char str[5];
	
	//float test1 = 82.8;
	
	//curr_frc = ust_get_current_time();//unit: micro second (us)
	//kal_prompt_trace(MOD_DRVKBD, "curr_frc =%d ",curr_frc);

	/*int i = 0;
	float MEMS_Data[3] = {0,0,0};

	for( i = 0 ; i < sizeof(PPG_Data)/sizeof(PPG_Data[0]) ; i++ )
	{
		
		PxiAlg_Process((unsigned char*)PPG_Data[i], MEMS_Data);
		
	}
	PxiAlg_HrGet(&myHR);*/

	//sprintf(str,"%f",myHR);

	//kal_prompt_trace(MOD_DRVKBD, "myHR =  %d ",myHR);		
	//kal_prompt_trace(MOD_DRVKBD, "myHR =  %s ",str);		

	Pixart_HRD();
	//StopTimer(MMI_OLDMAN_HEARTRATE_TIMER);
	//StartTimer(MMI_OLDMAN_HEARTRATE_TIMER , 40 ,TimeISR);
	
	 //kal_get_time(&ticks_ptrgxx);
	 //kal_prompt_trace(MOD_DRVKBD, "gxxticks=%d ",ticks_ptrgxx);

	uem_stop_timer(HRD_EVENT_TIMER);
	uem_start_timer(HRD_EVENT_TIMER,TimeISR,38);
}

void pah8001_sensor_show_data()
{
	ppg_mems_data_t ppg_mems_data;
	unsigned char ready_flag = 0;
	unsigned char motion_flag = 0;
	int cnt_to_update_ppg_chart = 0;
	kal_uint8 PxiAlg_Flag;
	float test1 = 82.8;
	char str[4];

	if(!isFIFOEmpty())
	{
		if(Pop(&ppg_mems_data))
		{
			kal_prompt_trace(MOD_DRVKBD, "{PPG_GSENSOR_RAW_DATA,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d},\r\n",
				ppg_mems_data.HRD_Data[0],ppg_mems_data.HRD_Data[1],ppg_mems_data.HRD_Data[2],ppg_mems_data.HRD_Data[3],
				ppg_mems_data.HRD_Data[4],ppg_mems_data.HRD_Data[5],ppg_mems_data.HRD_Data[6],ppg_mems_data.HRD_Data[7],
				ppg_mems_data.HRD_Data[8],ppg_mems_data.HRD_Data[9],ppg_mems_data.HRD_Data[10] ,ppg_mems_data.HRD_Data[11],ppg_mems_data.HRD_Data[12]);
			
			PxiAlg_Flag = PxiAlg_Process(ppg_mems_data.HRD_Data, ppg_mems_data.MEMS_Data);

			kal_prompt_trace(MOD_DRVKBD, "PxiAlg_Flag == %d! " , PxiAlg_Flag); 		

			if(PxiAlg_Flag == FLAG_DATA_READY)
			{
				PxiAlg_HrGet(&myHR);
			}
			else
			{
			     if(PxiAlg_Flag== FLAG_DATA_LOSS)
					 kal_prompt_trace(MOD_DRVKBD, "40ms is not good! ");		 
			     if(PxiAlg_Flag== FLAG_FIFO_ERROR)
					 kal_prompt_trace(MOD_DRVKBD, "FIFO_SIZE is not enough! ");		 
			}
			sprintf(str,"%f",myHR);
			kal_prompt_trace(MOD_DRVKBD, "myHR =  %s ",str);		
			
			if(GetActiveScreenId() == SCR_ID_PHONE_0)
			{
				show_HeartRate();
			}
		}
	}
	StopTimer(MMI_OLDMAN_HEARTRATE_DATA_TIMER);
	StartTimer(MMI_OLDMAN_HEARTRATE_DATA_TIMER , 10 ,pah8001_sensor_show_data);
	//uem_start_timer(2,pah8001_sensor_show_data,10);
}

void pah8001_sensor_main(void)
{
	
	pah8001_sensor_init();

	PxiAlg_SetMemsScale(0);
	PxiAlg_EnableFastOutput(0);
	//auto mode
	PxiAlg_EnableAutoMode(1);
	PxiAlg_EnableMotionMode(0);

	//motion mode
	//PxiAlg_EnableAutoMode(0);
	//PxiAlg_EnableMotionMode(1);

	TimeISR();

	//Set PPG display buffer
	pah8001_sensor_show_data();
	
}

#endif
#endif
