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

#ifdef LQT_SUPPORT/*Do not remove LQT code segment*/
extern void LCD_gamma_test_main(kal_uint8 level, kal_uint8 color);
extern void LCD_flicker_test_main(kal_uint8 level);
#endif

//#define DEBUG_LCD_ID
#ifdef COMBO_LCM_ID_AUTO_DETECT
#ifdef DEBUG_LCD_ID
kal_bool LCM_ID_check_GC9305();
#endif
#endif


#define LCD_CtrlWrite_GC9305 LCD_CtrlWrite_main
#define LCD_DataWrite_GC9305 LCD_DataWrite_main


static void LCD_Delay(kal_uint32 delay_count)
{
	volatile kal_uint32 delay;
	for (delay =0;delay <(delay_count*4);delay++) {}
}

extern void LCDDelayms(kal_uint16 data);




/***********************GC9305********************************/
/*ILI, 262K Color LCD, Parallel Interface, Firefly development board*/

//#define WMLCDCOM	LCD_CtrlWrite_GC9305
//#define WMLCDDATA	LCD_DataWrite_GC9305 

static void LCD_GC9305_CMD(kal_uint16 DATA)
{
//	LCD_CtrlWrite_GC9305((DATA&0xff00)>>8 );
	LCD_CtrlWrite_GC9305(DATA&0x00ff );
}
static void LCD_GC9305_DATA(kal_uint16 DATA)
{
//	LCD_DataWrite_GC9305((DATA&0xff00)>>8 );
	LCD_DataWrite_GC9305(DATA&0x00ff );
}

void LCD_Partial_On_GC9305(kal_uint16 start_page,kal_uint16 end_page)
{

}

void LCD_Partial_Off_GC9305(void)
{

}

kal_uint8 LCD_Partial_line_GC9305(void)
{
	return 1;		/* partial display in 1 line alignment */
}

void LCD_Set_Y_Addr_GC9305(kal_uint16 start_row, kal_uint16 end_row)
{

}

void LCD_Set_X_Addr_GC9305(kal_uint16 start_column, kal_uint16 end_column)
{

}

void LCD_blockClear_GC9305(kal_uint16 x1,kal_uint16 y1,kal_uint16 x2,kal_uint16 y2,kal_uint16 data)
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

    LCD_GC9305_CMD(0x2A);
	LCD_GC9305_DATA(((x1&0xFF00)>>8));
	LCD_GC9305_DATA((x1&0xFF));
	LCD_GC9305_DATA(((x2&0xFF00)>>8));
	LCD_GC9305_DATA((x2&0xFF));
    LCD_GC9305_CMD(0x2B);
	LCD_GC9305_DATA(((y1&0xFF00)>>8));
	LCD_GC9305_DATA((y1&0xFF));
	LCD_GC9305_DATA(((y2&0xFF00)>>8));
	LCD_GC9305_DATA((y2&0xFF));
	
	LCD_GC9305_CMD(0x2C);

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

void LCD_ClearAll_GC9305(kal_uint16 data)
{
   LCD_blockClear_GC9305(0,0,LCD_WIDTH-1,LCD_HEIGHT-1,data);
}

void LCD_Init_GC9305(kal_uint32 bkground, void **buf_addr)
{
	// Enhance LCD I/F driving current.
#if defined(MT6238)
	*((volatile unsigned short *) 0x80010700) |= 0xE0E0;
#endif

	LCDDelayms(10);
	SET_LCD_CTRL_RESET_PIN;
	LCDDelayms(120);
	CLEAR_LCD_CTRL_RESET_PIN;
	LCDDelayms(120); 
	SET_LCD_CTRL_RESET_PIN;
	LCDDelayms(140);

	//Delay 120ms
	//--------------------------------------Display Setting------------------------------------------//
	/*LCD_GC9305_CMD(0xfe);
	LCD_GC9305_CMD(0xef);
	LCD_GC9305_CMD(0x36);//
	LCD_GC9305_DATA(0x48);
	LCD_GC9305_CMD(0x3a);//
	LCD_GC9305_DATA(0x06);//数据传输方式


	LCD_GC9305_CMD(0xa4);//
	LCD_GC9305_DATA(0x44);
	LCD_GC9305_DATA(0x44);
	LCD_GC9305_CMD(0xa5);//
	LCD_GC9305_DATA(0x42);
	LCD_GC9305_DATA(0x42);
	LCD_GC9305_CMD(0xaa);//
	LCD_GC9305_DATA(0x88);
	LCD_GC9305_DATA(0x88);

	LCD_GC9305_CMD(0xe8);//Frame rate=71.8hz
	LCD_GC9305_DATA(0x11);
	LCD_GC9305_DATA(0x0b);

	LCD_GC9305_CMD(0xe3);//source ps=01
	LCD_GC9305_DATA(0x01);
	LCD_GC9305_DATA(0x10);

	LCD_GC9305_CMD(0xff);//
	LCD_GC9305_DATA(0x61);

	LCD_GC9305_CMD(0xed);
	LCD_GC9305_DATA(0x19);
	LCD_GC9305_DATA(0x09);

	LCD_GC9305_CMD(0xAC);//ldo enable
	LCD_GC9305_DATA(0x00);
	//LCD_GC9305_CMD(0xAd);//ldo enable
	//LCD_GC9305_DATA(0x33);

	LCD_GC9305_CMD(0xae);
	LCD_GC9305_DATA(0x2b);

	LCD_GC9305_CMD(0xAf);//DIG_VREFAD_VRDD[2]
	LCD_GC9305_DATA(0x67);

	LCD_GC9305_CMD(0xa6);
	LCD_GC9305_DATA(0x2a);
	LCD_GC9305_DATA(0x2a);//29
	LCD_GC9305_CMD(0xa7);
	LCD_GC9305_DATA(0x2b);
	LCD_GC9305_DATA(0x2b);
	LCD_GC9305_CMD(0xa8);
	LCD_GC9305_DATA(0x18);
	LCD_GC9305_DATA(0x18);//17
	LCD_GC9305_CMD(0xa9);
	LCD_GC9305_DATA(0x2a);
	LCD_GC9305_DATA(0x2a);*/
LCD_GC9305_CMD(0xfe);
LCD_GC9305_CMD(0xef);
LCD_GC9305_CMD(0x36);
LCD_GC9305_DATA(0x48);
LCD_GC9305_CMD(0x3a);
LCD_GC9305_DATA(0x06);
//------end display control setting----//
//------Power Control Registers Initial----//
LCD_GC9305_CMD(0xa4);
LCD_GC9305_DATA(0x44);
LCD_GC9305_DATA(0x44);
LCD_GC9305_CMD(0xa5);
LCD_GC9305_DATA(0x42);
LCD_GC9305_DATA(0x42);
LCD_GC9305_CMD(0xaa);
LCD_GC9305_DATA(0x88);
LCD_GC9305_DATA(0x88);
LCD_GC9305_CMD(0xe8);
LCD_GC9305_DATA(0x11);
LCD_GC9305_DATA(0x0b);
LCD_GC9305_CMD(0xe3);
LCD_GC9305_DATA(0x01);
LCD_GC9305_DATA(0x10);
LCD_GC9305_CMD(0xff);
LCD_GC9305_DATA(0x61);
LCD_GC9305_CMD(0xAC);
LCD_GC9305_DATA(0x00);

LCD_GC9305_CMD(0xae);
LCD_GC9305_DATA(0x2b);

LCD_GC9305_CMD(0xad); 
LCD_GC9305_DATA(0x33);

LCD_GC9305_CMD(0xaf); 
LCD_GC9305_DATA(0x55);

LCD_GC9305_CMD(0xa6);
LCD_GC9305_DATA(0x2a);
LCD_GC9305_DATA(0x2a);
LCD_GC9305_CMD(0xa7);
LCD_GC9305_DATA(0x2b);
LCD_GC9305_DATA(0x2b);
LCD_GC9305_CMD(0xa8);
LCD_GC9305_DATA(0x18);
LCD_GC9305_DATA(0x18);
LCD_GC9305_CMD(0xa9);
LCD_GC9305_DATA(0x2a);
LCD_GC9305_DATA(0x2a);
	//======================gamma===========================
	//-----display window 240X320---------//
	LCD_GC9305_CMD(0x2a);
	LCD_GC9305_DATA(0x00);
	LCD_GC9305_DATA(0x00);
	LCD_GC9305_DATA(0x00);
	LCD_GC9305_DATA(0xef);
	LCD_GC9305_CMD(0x2b);
	LCD_GC9305_DATA(0x00);
	LCD_GC9305_DATA(0x00);
	LCD_GC9305_DATA(0x01);
	LCD_GC9305_DATA(0x3f);
	LCD_GC9305_CMD(0x2c);
	//--------end display window --------------//
	//色彩及对比对寄存器设置(F0~F5)
	LCD_GC9305_CMD(0xF0);
	LCD_GC9305_DATA(0x02);
	LCD_GC9305_DATA(0x02);
	LCD_GC9305_DATA(0x00);
	LCD_GC9305_DATA(0x00);
	LCD_GC9305_DATA(0x02);
	LCD_GC9305_DATA(0x07);
	
	LCD_GC9305_CMD(0xF1);
	LCD_GC9305_DATA(0x01);
	LCD_GC9305_DATA(0x00);
	LCD_GC9305_DATA(0x00);
	LCD_GC9305_DATA(0x01);
	LCD_GC9305_DATA(0x07);
	LCD_GC9305_DATA(0x0F);
	
	LCD_GC9305_CMD(0xF2);
	LCD_GC9305_DATA(0x08);
	LCD_GC9305_DATA(0x06);
	LCD_GC9305_DATA(0x30);
	LCD_GC9305_DATA(0x04);
	LCD_GC9305_DATA(0x04);
	LCD_GC9305_DATA(0x44);
	
	LCD_GC9305_CMD(0xF3);
	LCD_GC9305_DATA(0x12);
	LCD_GC9305_DATA(0x0D);
	LCD_GC9305_DATA(0x3E);
	LCD_GC9305_DATA(0x05);
	LCD_GC9305_DATA(0x04);
	LCD_GC9305_DATA(0x4F);
	
	LCD_GC9305_CMD(0xF4);
	LCD_GC9305_DATA(0x0D);
	LCD_GC9305_DATA(0x18);
	LCD_GC9305_DATA(0x16);
	LCD_GC9305_DATA(0x1C);
	LCD_GC9305_DATA(0x1E);
	LCD_GC9305_DATA(0x0F);
	
	LCD_GC9305_CMD(0xF5);
	LCD_GC9305_DATA(0x05);
	LCD_GC9305_DATA(0x14);
	LCD_GC9305_DATA(0x14);
	LCD_GC9305_DATA(0x1A);
	LCD_GC9305_DATA(0x1B);
	LCD_GC9305_DATA(0x0F);

	
	
	//====================end gamma=========================	
	LCD_GC9305_CMD(0x11);
	LCDDelayms(120);	
	LCD_GC9305_CMD(0x29);	
	LCD_GC9305_CMD(0x2c);
}


void LCD_EnterSleep_GC9305(void)
{
#if defined(LQT_SUPPORT)/*Do not remove LQT code segment*/
 if(!(lcd_at_mode==LCD_AT_RELEASE_MODE))
 {
  return;
 }	
#endif /*defined(LQT_SUPPORT))*/	
    LCD_GC9305_CMD(0xfe);
    LCD_GC9305_CMD(0xef);
	LCD_GC9305_CMD(0x28);
	LCDDelayms(120);  
	LCD_GC9305_CMD(0x10);
	LCDDelayms(150); 

}

void LCD_ExitSleep_GC9305(void)
{
#if defined(LQT_SUPPORT)/*Do not remove LQT code segment*/
 if(!(lcd_at_mode==LCD_AT_RELEASE_MODE))
 {
  return;
 }	
#endif /*defined(LQT_SUPPORT))*/
    LCD_GC9305_CMD(0xfe);
    LCD_GC9305_CMD(0xef);
	LCD_GC9305_CMD(0x11);
	LCDDelayms(120); 
	LCD_GC9305_CMD(0x29);
	LCDDelayms(20);
    LCD_Init_GC9305(0,NULL);
	//LCD_Init_HX8352B(0,NULL);
}


void LCD_PWRON_GC9305(kal_bool on)
{
   if(on)
   {
      LCD_ExitSleep_GC9305();
   }
   else
   {
      LCD_EnterSleep_GC9305();
   }
}

void LCD_SetContrast_GC9305(kal_uint8 level)
{
}

void LCD_ON_GC9305(kal_bool on)
{
   if (on)
   {
      LCD_ExitSleep_GC9305();
   }
   else
   {
      LCD_EnterSleep_GC9305();
   }
}

kal_bool LCM_ID_check_GC9305();
void LCD_BlockWrite_GC9305(kal_uint16 startx,kal_uint16 starty,kal_uint16 endx,kal_uint16 endy)
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

#ifdef COMBO_LCM_ID_AUTO_DETECT
#ifdef DEBUG_LCD_ID
	LCM_ID_check_GC9305();
	kal_prompt_trace(MOD_MED, "-------LCM_ID_check_GC9305   startx=%x,endx=%x,starty=%x,endy=%x------\n",startx,endx,starty,endy);
#endif
#endif

	ASSERT(lcd_assert_fail==KAL_FALSE);
	lcd_assert_fail = KAL_TRUE;

	LCD_GC9305_CMD(0x2a);   
	LCD_GC9305_DATA((startx&0xff00)>>8);
	LCD_GC9305_DATA(startx&0x00ff);
	LCD_GC9305_DATA((endx&0xff00)>>8);
	LCD_GC9305_DATA(endx&0x00ff);

	LCD_GC9305_CMD(0x2b);   
	LCD_GC9305_DATA((starty&0xff00)>>8);
	LCD_GC9305_DATA(starty&0x00ff);
	LCD_GC9305_DATA((endy&0xff00)>>8);
	LCD_GC9305_DATA(endy&0x00ff);

	LCD_GC9305_CMD(0x2c);

	ENABLE_LCD_TRANSFER_COMPLETE_INT;//Kate
	DISABLE_LCD_ROI_CTRL_CMD_FIRST;
	START_LCD_TRANSFER;

	lcd_assert_fail = KAL_FALSE;
}


void LCD_Size_GC9305(kal_uint16 *out_LCD_width,kal_uint16 *out_LCD_height)
{
   *out_LCD_width = LCD_WIDTH;
   *out_LCD_height = LCD_HEIGHT;
}

/*Engineering mode*/
kal_uint8 LCD_GetParm_GC9305(lcd_func_type type)
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

void LCD_SetBias_GC9305(kal_uint8 *bias)
{
}

void LCD_Contrast_GC9305(kal_uint8 *contrast)
{
}

void LCD_LineRate_GC9305(kal_uint8 *linerate)
{
}

void LCD_Temp_Compensate_GC9305(kal_uint8 *compensate)
{
}

void LCD_Set_Scan_Direction_GC9305(kal_uint8 rotate_value)
{
	switch (rotate_value)
	{	
		break;
	}

}	/* LCD_Set_Scan_Direction_HX8352B() */
LCM_IOCTRL_STATUS_ENUM
LCD_IOCTRL_GC9305(LCM_IOCTRL_ID_ENUM ID, void* Parameters)
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
#ifdef DEBUG_LCD_ID
kal_uint8 read_fisrt_id_1 = 0;
kal_uint8 read_fisrt_id_2 = 0;
kal_uint8 read_fisrt_id_3 = 0;
kal_bool flag_only_once = KAL_TRUE;
#endif
kal_bool LCM_ID_check_GC9305()
{
    kal_uint8 dummy, GC9305_1, GC9305_2, GC9305_3;

    LCD_CtrlWrite_GC9305(0x04);  //LCM ID
    dummy = LCD_DataRead_main;
    GC9305_1 = LCD_DataRead_main;
    GC9305_2 = LCD_DataRead_main;
    GC9305_3 = LCD_DataRead_main;
	
#ifdef DEBUG_LCD_ID
     if(flag_only_once)
     {
     	flag_only_once = KAL_FALSE;
	read_fisrt_id_1 = GC9305_1;
	read_fisrt_id_2 = GC9305_2;
	read_fisrt_id_3 = GC9305_3;

	 }
     kal_prompt_trace(MOD_MED, "-------LCM_FIRSTREAD_ID_check_GC9305   read_fisrt_id_1=%x,read_fisrt_id_2=%x,read_fisrt_id_3=%x------\n",read_fisrt_id_1,read_fisrt_id_2,read_fisrt_id_3);
     kal_prompt_trace(MOD_MED, "-------LCM_ID_check_GC9305   GC9305_1=%x,GC9305_2=%x,GC9305_3=%x------\n",GC9305_1,GC9305_2,GC9305_3);
#endif
     kal_prompt_trace(MOD_MED, "-------LCM_ID_check_GC9305   GC9305_1=%x,GC9305_2=%x,GC9305_3=%x------\n",GC9305_1,GC9305_2,GC9305_3);

    if (0x93 == GC9305_2 && 0x05 == GC9305_3)
      return KAL_TRUE;
    else
      return KAL_FALSE;
}
#endif



LCD_Funcs LCD_func_GC9305 = {
   LCD_Init_GC9305,
   LCD_PWRON_GC9305,
   LCD_SetContrast_GC9305,
   LCD_ON_GC9305,
   LCD_BlockWrite_GC9305,
   LCD_Size_GC9305,
   LCD_EnterSleep_GC9305,
   LCD_ExitSleep_GC9305,
   LCD_Partial_On_GC9305,
   LCD_Partial_Off_GC9305,
   LCD_Partial_line_GC9305,
   /*Engineering mode*/
   LCD_GetParm_GC9305,
   LCD_SetBias_GC9305,
   LCD_Contrast_GC9305,
   LCD_LineRate_GC9305,
   LCD_Temp_Compensate_GC9305
#ifdef LCM_ROTATE_SUPPORT
   ,LCD_Set_Scan_Direction_GC9305
#endif
#ifdef LQT_SUPPORT/*Do not remove LQT code segment*/
   ,LCD_gamma_test_main
   ,LCD_flicker_test_main
#endif
  , NULL
   ,LCD_IOCTRL_GC9305
};

void LCD_FunConfig_GC9305(void)
{

	MainLCD = &LCD_func_GC9305;

	#ifdef DUAL_LCD
		//SubLCD = &LCD_func_HD66791;
	#endif
}
