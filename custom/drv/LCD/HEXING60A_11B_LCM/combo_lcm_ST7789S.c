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
kal_bool LCM_ID_check_ST7789S();
#endif
#endif


#define LCD_CtrlWrite_ST7789S LCD_CtrlWrite_main
#define LCD_DataWrite_ST7789S LCD_DataWrite_main


static void LCD_Delay(kal_uint32 delay_count)
{
	volatile kal_uint32 delay;
	for (delay =0;delay <(delay_count*4);delay++) {}
}

extern void LCDDelayms(kal_uint16 data);




/***********************ST7789S********************************/
/*ILI, 262K Color LCD, Parallel Interface, Firefly development board*/

//#define WMLCDCOM	LCD_CtrlWrite_ST7789S
//#define WMLCDDATA	LCD_DataWrite_ST7789S 

static void WMLCDCOM(kal_uint16 DATA)
{
//	LCD_CtrlWrite_ST7789S((DATA&0xff00)>>8 );
	LCD_CtrlWrite_ST7789S(DATA&0x00ff );
}
static void WMLCDDATA(kal_uint16 DATA)
{
//	LCD_DataWrite_ST7789S((DATA&0xff00)>>8 );
	LCD_DataWrite_ST7789S(DATA&0x00ff );
}

void LCD_Partial_On_ST7789S(kal_uint16 start_page,kal_uint16 end_page)
{

}

void LCD_Partial_Off_ST7789S(void)
{

}

kal_uint8 LCD_Partial_line_ST7789S(void)
{
	return 1;		/* partial display in 1 line alignment */
}

void LCD_Set_Y_Addr_ST7789S(kal_uint16 start_row, kal_uint16 end_row)
{

}

void LCD_Set_X_Addr_ST7789S(kal_uint16 start_column, kal_uint16 end_column)
{

}

void LCD_blockClear_ST7789S(kal_uint16 x1,kal_uint16 y1,kal_uint16 x2,kal_uint16 y2,kal_uint16 data)
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

void LCD_ClearAll_ST7789S(kal_uint16 data)
{
   LCD_blockClear_ST7789S(0,0,LCD_WIDTH-1,LCD_HEIGHT-1,data);
}

#if 0//ruili



void LCD_Init_ST7789S(kal_uint32 bkground, void **buf_addr)
{
	// Enhance LCD I/F driving current.
#if defined(MT6238)
	*((volatile unsigned short *) 0x80010700) |= 0xE0E0;
#endif


	LCDDelayms(10);
	SET_LCD_CTRL_RESET_PIN;
	LCDDelayms(20);
	CLEAR_LCD_CTRL_RESET_PIN;
	LCDDelayms(20); 
	SET_LCD_CTRL_RESET_PIN;
	LCDDelayms(140);
	WMLCDCOM(0x11);
	LCDDelayms(120); //Delay 120ms


	 //Delay 120ms
	//--------------------------------------Display Setting------------------------------------------//
	WMLCDCOM(0x36);
	WMLCDDATA( 0x00);

	//WMLCDCOM(0x21);
	WMLCDCOM(0x2a);
	WMLCDDATA( 0x00);
	WMLCDDATA( 0x00);
	WMLCDDATA( 0x00);
	WMLCDDATA( 0xef);
	WMLCDCOM(0x2b);
	WMLCDDATA( 0x00);
	WMLCDDATA( 0x00);
	WMLCDDATA( 0x00);
	WMLCDDATA( 0xef);
	//--------------------------------ST7789V Frame rate setting----------------------------------//
	WMLCDCOM(0xb2);
	WMLCDDATA( 0x0c);
	WMLCDDATA( 0x0c);
	WMLCDDATA( 0x00);
	WMLCDDATA( 0x33);
	WMLCDDATA( 0x33);
	WMLCDCOM(0xb7);
	WMLCDDATA( 0x35);
	//---------------------------------ST7789V Power setting--------------------------------------//
	WMLCDCOM(0xbb);
	WMLCDDATA( 0x1f);
	WMLCDCOM(0xc0);
	WMLCDDATA( 0x2c);
	WMLCDCOM(0xc2);
	WMLCDDATA( 0x01);
	WMLCDCOM(0xc3);
	WMLCDDATA( 0x12);
	WMLCDCOM(0xc4);
	WMLCDDATA( 0x20);
	WMLCDCOM(0xc6);
	WMLCDDATA( 0x0f);
	WMLCDCOM(0xd0);
	WMLCDDATA( 0xa4);
	WMLCDDATA( 0xa1);
	//--------------------------------ST7789V gamma setting--------------------------------------//
	WMLCDCOM(0xe0);
	WMLCDDATA( 0xd0);
	WMLCDDATA( 0x08);
	WMLCDDATA( 0x11);
	WMLCDDATA( 0x08);
	WMLCDDATA( 0x0c);
	WMLCDDATA( 0x15);
	WMLCDDATA( 0x39);
	WMLCDDATA( 0x33);
	WMLCDDATA( 0x50);
	WMLCDDATA( 0x36);
	WMLCDDATA( 0x13);
	WMLCDDATA( 0x14);
	WMLCDDATA( 0x29);
	WMLCDDATA( 0x2d);
	WMLCDCOM(0xe1);
	WMLCDDATA( 0xd0);
	WMLCDDATA( 0x08);
	WMLCDDATA( 0x10);
	WMLCDDATA( 0x08);
	WMLCDDATA( 0x06);
	WMLCDDATA( 0x06);
	WMLCDDATA( 0x39);
	WMLCDDATA( 0x44);
	WMLCDDATA( 0x51);
	WMLCDDATA( 0x0b);
	WMLCDDATA( 0x16);
	WMLCDDATA( 0x14);
	WMLCDDATA( 0x2f);
	WMLCDDATA( 0x31);
	


	WMLCDCOM(0x3A);  
	WMLCDDATA(0x66);


	WMLCDCOM(0x21);  
	
	#if 0
	//==显示屏的FPC，IC朝上===========================             
	WMLCDCOM(0x36);    // Memory Access Control 
	WMLCDDATA(0xd0);
	#else
	//==显示屏的FPC，IC朝下，即所谓的显示旋转180度=====
	WMLCDCOM(0x36);    // Memory Access Control 
	WMLCDDATA(0x00);
	#endif
		
	WMLCDCOM(0x29);

}


#else


void LCD_Init_ST7789S(kal_uint32 bkground, void **buf_addr)
{
	// Enhance LCD I/F driving current.
#if defined(MT6238)
	*((volatile unsigned short *) 0x80010700) |= 0xE0E0;
#endif


	LCDDelayms(10);
	SET_LCD_CTRL_RESET_PIN;
	LCDDelayms(20);
	CLEAR_LCD_CTRL_RESET_PIN;
	LCDDelayms(20); 
	SET_LCD_CTRL_RESET_PIN;
	LCDDelayms(140);
	WMLCDCOM(0x11);
	LCDDelayms(120); //Delay 120ms


	 //Delay 120ms
	//--------------------------------------Display Setting------------------------------------------//
	WMLCDCOM(0x36);
	WMLCDDATA( 0x00);

	WMLCDCOM(0x3A);
	WMLCDDATA( 0x06);
	
	//--------------------------------ST7789V Frame rate setting----------------------------------//
	WMLCDCOM(0xB2);
	WMLCDDATA( 0x0c);
	WMLCDDATA( 0x0c);
	WMLCDDATA( 0x00);
	WMLCDDATA( 0x33);
	WMLCDDATA( 0x33);
	WMLCDCOM(0xb7);
	WMLCDDATA( 0x75);
	//---------------------------------ST7789V Power setting--------------------------------------//
	WMLCDCOM(0xbb);
	WMLCDDATA( 0x19);
	WMLCDCOM(0xc0);
	WMLCDDATA( 0x2c);
	WMLCDCOM(0xc2);
	WMLCDDATA( 0x01);
	WMLCDCOM(0xc3);
	WMLCDDATA( 0x1D);
	WMLCDCOM(0xc4);
	WMLCDDATA( 0x20);
	WMLCDCOM(0xc6);
	WMLCDDATA( 0x0f);
	WMLCDCOM(0xd0);
	WMLCDDATA( 0xa4);
	WMLCDDATA( 0xa1);
	//--------------------------------ST7789V gamma setting--------------------------------------//
    WMLCDCOM(0xE0);     
    WMLCDDATA( 0xD0);   
    WMLCDDATA( 0x03);   
    WMLCDDATA( 0x0B);   
    WMLCDDATA( 0x14);   
    WMLCDDATA( 0x17);   
    WMLCDDATA( 0x1D);   
    WMLCDDATA( 0x3F);   
    WMLCDDATA( 0x44);   
    WMLCDDATA( 0x4E);   
    WMLCDDATA( 0x0A);   
    WMLCDDATA( 0x13);   
    WMLCDDATA( 0x13);   
    WMLCDDATA( 0x1E);   
    WMLCDDATA( 0x20);   

    WMLCDCOM(0xE1);     
    WMLCDDATA( 0xD0);   
    WMLCDDATA( 0x03);   
    WMLCDDATA( 0x0B);   
    WMLCDDATA( 0x12);   
    WMLCDDATA( 0x14);   
    WMLCDDATA( 0x1C);   
    WMLCDDATA( 0x3F);   
    WMLCDDATA( 0x44);   
    WMLCDDATA( 0x4E);   
    WMLCDDATA( 0x0B);   
    WMLCDDATA( 0x17);   
    WMLCDDATA( 0x15);   
    WMLCDDATA( 0x1E);   
    WMLCDDATA( 0x21);   

	

//	WMLCDCOM(0x21);  
	
	#if 0
	//==显示屏的FPC，IC朝上===========================             
	WMLCDCOM(0x36);    // Memory Access Control 
	WMLCDDATA(0xd0);
	#else
	//==显示屏的FPC，IC朝下，即所谓的显示旋转180度=====
	WMLCDCOM(0x36);    // Memory Access Control 
	WMLCDDATA(0x00);
	#endif
		
	WMLCDCOM(0x29);

}

#endif

void LCD_EnterSleep_ST7789S(void)
{
#if defined(LQT_SUPPORT)/*Do not remove LQT code segment*/
 if(!(lcd_at_mode==LCD_AT_RELEASE_MODE))
 {
  return;
 }	
#endif /*defined(LQT_SUPPORT))*/	

	WMLCDCOM(0x28);
	LCDDelayms(10);  
	WMLCDCOM(0x10);
	LCDDelayms(120); 

}

void LCD_ExitSleep_ST7789S(void)
{
#if defined(LQT_SUPPORT)/*Do not remove LQT code segment*/
 if(!(lcd_at_mode==LCD_AT_RELEASE_MODE))
 {
  return;
 }	
#endif /*defined(LQT_SUPPORT))*/

	WMLCDCOM(0x11);
	LCDDelayms(120); 
	WMLCDCOM(0x29);
	LCDDelayms(20);
  
	//LCD_Init_HX8352B(0,NULL);
}


void LCD_PWRON_ST7789S(kal_bool on)
{
   if(on)
   {
      LCD_ExitSleep_ST7789S();
   }
   else
   {
      LCD_EnterSleep_ST7789S();
   }
}

void LCD_SetContrast_ST7789S(kal_uint8 level)
{
}

void LCD_ON_ST7789S(kal_bool on)
{
   if (on)
   {
      LCD_ExitSleep_ST7789S();
   }
   else
   {
      LCD_EnterSleep_ST7789S();
   }
}

kal_bool LCM_ID_check_ST7789S();
void LCD_BlockWrite_ST7789S(kal_uint16 startx,kal_uint16 starty,kal_uint16 endx,kal_uint16 endy)
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
	LCM_ID_check_ST7789S();
      kal_prompt_trace(MOD_MED, "-------LCM_ID_check_ST7789S   startx=%x,endx=%x,starty=%x,endy=%x------\n",startx,endx,starty,endy);
#endif
#endif

	ASSERT(lcd_assert_fail==KAL_FALSE);
	lcd_assert_fail = KAL_TRUE;




	WMLCDCOM(0x2a);   
	WMLCDDATA((startx&0xff00)>>8);
	WMLCDDATA(startx&0x00ff);
	WMLCDDATA((endx&0xff00)>>8);
	WMLCDDATA(endx&0x00ff);

	WMLCDCOM(0x2b);   
	WMLCDDATA((starty&0xff00)>>8);
	WMLCDDATA(starty&0x00ff);
	WMLCDDATA((endy&0xff00)>>8);
	WMLCDDATA(endy&0x00ff);

	WMLCDCOM(0x2c);

	ENABLE_LCD_TRANSFER_COMPLETE_INT;//Kate
	DISABLE_LCD_ROI_CTRL_CMD_FIRST;
	START_LCD_TRANSFER;

	 lcd_assert_fail = KAL_FALSE;
}


void LCD_Size_ST7789S(kal_uint16 *out_LCD_width,kal_uint16 *out_LCD_height)
{
   *out_LCD_width = LCD_WIDTH;
   *out_LCD_height = LCD_HEIGHT;
}

/*Engineering mode*/
kal_uint8 LCD_GetParm_ST7789S(lcd_func_type type)
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

void LCD_SetBias_ST7789S(kal_uint8 *bias)
{
}

void LCD_Contrast_ST7789S(kal_uint8 *contrast)
{
}

void LCD_LineRate_ST7789S(kal_uint8 *linerate)
{
}

void LCD_Temp_Compensate_ST7789S(kal_uint8 *compensate)
{
}

void LCD_Set_Scan_Direction_ST7789S(kal_uint8 rotate_value)
{
	switch (rotate_value)
	{	
		break;
	}

}	/* LCD_Set_Scan_Direction_HX8352B() */
LCM_IOCTRL_STATUS_ENUM
LCD_IOCTRL_ST7789S(LCM_IOCTRL_ID_ENUM ID, void* Parameters)
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
kal_bool LCM_ID_check_ST7789S()
{
    kal_uint8 dummy, ST7789S_1, ST7789S_2, ST7789S_3;

    LCD_CtrlWrite_ST7789S(0x04);  //LCM ID
    dummy = LCD_DataRead_main;
    ST7789S_1 = LCD_DataRead_main;
    ST7789S_2 = LCD_DataRead_main;
    ST7789S_3 = LCD_DataRead_main;
	
#ifdef DEBUG_LCD_ID
     if(flag_only_once)
     {
     	flag_only_once = KAL_FALSE;
	read_fisrt_id_1 = ST7789S_1;
	read_fisrt_id_2 = ST7789S_2;
	read_fisrt_id_3 = ST7789S_3;

	 }
     kal_prompt_trace(MOD_MED, "-------LCM_FIRSTREAD_ID_check_ST7789S   read_fisrt_id_1=%x,read_fisrt_id_2=%x,read_fisrt_id_3=%x------\n",read_fisrt_id_1,read_fisrt_id_2,read_fisrt_id_3);
     kal_prompt_trace(MOD_MED, "-------LCM_ID_check_ST7789S   ST7789S_1=%x,ST7789S_2=%x,ST7789S_3=%x------\n",ST7789S_1,ST7789S_2,ST7789S_3);
#endif

    if (0x85 == ST7789S_2 && 0x52 == ST7789S_3)
      return KAL_TRUE;
    else
      return KAL_FALSE;
}
#endif



LCD_Funcs LCD_func_ST7789S = {
   LCD_Init_ST7789S,
   LCD_PWRON_ST7789S,
   LCD_SetContrast_ST7789S,
   LCD_ON_ST7789S,
   LCD_BlockWrite_ST7789S,
   LCD_Size_ST7789S,
   LCD_EnterSleep_ST7789S,
   LCD_ExitSleep_ST7789S,
   LCD_Partial_On_ST7789S,
   LCD_Partial_Off_ST7789S,
   LCD_Partial_line_ST7789S,
   /*Engineering mode*/
   LCD_GetParm_ST7789S,
   LCD_SetBias_ST7789S,
   LCD_Contrast_ST7789S,
   LCD_LineRate_ST7789S,
   LCD_Temp_Compensate_ST7789S
#ifdef LCM_ROTATE_SUPPORT
   ,LCD_Set_Scan_Direction_ST7789S
#endif
#ifdef LQT_SUPPORT/*Do not remove LQT code segment*/
   ,LCD_gamma_test_main
   ,LCD_flicker_test_main
#endif
  , NULL
   ,LCD_IOCTRL_ST7789S
};

void LCD_FunConfig_ST7789S(void)
{

	MainLCD = &LCD_func_ST7789S;

	#ifdef DUAL_LCD
		//SubLCD = &LCD_func_HD66791;
	#endif
}
