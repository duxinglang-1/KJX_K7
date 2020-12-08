
#include "lcd_sw_inc.h"
#include "lcd_sw.h"
#include "lcd_hw.h"


/*****************************************************************************
 * COMBO LCM ID and string name *
 *============================================================================*/
 
#pragma arm section code = "PRIMARY_ROCODE", rwdata = "PRIMARY_RW", rodata = "PRIMARY_RODATA"

typedef struct
{
    kal_uint32 pattern_head;
    kal_uint32 main_lcd_id;
    kal_uint32 pattern_tail;
}main_lcd_block;

char* (main_lcm_list[]) =
{
	"ST7789S",
 	"GC9305",
	"EXAMPLE_LCM" //please add main lcd names above this item, the order must corresponding to main_lcm_enum.	
	              //notice, the name should be less than 50 characters.
}; 

kal_uint32 main_lcm_number = MAIN_LCM_MAX_NUM;
	

#if defined(__MTK_TARGET__)
__align(4) main_lcd_block MainLCDBlock = 
#else
main_lcd_block MainLCDBlock = 
#endif
{
    0x44434C4D,
    0,   //modify this value to adapt the current attached LCM
    0x4C494154
};

#ifdef DUAL_LCD

typedef struct
{
	kal_uint32 pattern_head;
	kal_uint32 sub_lcd_id;
	kal_uint32 pattern_tail;
}sub_lcd_block;


char* (sub_lcm_list[]) =
{
	"SUB_EXAMPLE_LCM_A",
	"SUB_EXAMPLE_LCM_B",
	"SUB_EXAMPLE_LCM_C",
	"EXAMPLE_LCM" //please add sub lcd names above this item, the order must corresponding to sub_lcm_enum.	
	              //notice, the name should be less than 50 characters.
}; 
kal_uint32 sub_lcm_number = SUB_LCM_MAX_NUM;

#if defined(__MTK_TARGET__)
__align(4) sub_lcd_block SubLCDBlock = 
#else
sub_lcd_block SubLCDBlock = 
#endif
{
	0x44434C53,
	0,   //modify this value to adapt the current attached LCM
	0x4C494154
};

#endif

extern kal_uint32 drv_get_current_time(void);
extern kal_uint32 drv_get_duration_ms(kal_uint32 previous_time);
void LCDDelayms(kal_uint16 data)
{

    kal_uint32 time1;
    
    time1 = drv_get_current_time();
    while (drv_get_duration_ms(time1) <= data);
}
	

void spi_ini_main(void)
{
}


void init_lcd_interface_main(void)
{
	kal_uint32 backup_val;	
  /// Turn on LCD clock
#if defined(__OLD_PDN_DEFINE__)
	DRV_Reg(DRVPDN_CON1_CLR) = DRVPDN_CON1_LCD;
	//modifed for new clock gating
#elif defined(__CLKG_DEFINE__)
	DRV_Reg(MMCG_CLR0) = MMCG_CON0_LCD;
#endif

	REG_LCD_ROI_CTRL=0;

#if (defined(MT6250)||defined(MT6260))
	
	#if (defined(MAIN_LCD_8BIT_MODE))
		#if (defined(MT6250)||defined(MT6260))
		SET_LCD_PARALLEL_DATA_BUS(0,0);
		#endif
	#elif (defined(MAIN_LCD_9BIT_MODE) || defined(MAIN_LCD_16BIT_MODE) || defined(MAIN_LCD_18BIT_MODE))

		#if (defined(MT6250)||defined(MT6260))
			#if defined(MAIN_LCD_16BIT_MODE)
			  SET_LCD_PARALLEL_DATA_BUS(0,2);
	    		#else
			  SET_LCD_PARALLEL_DATA_BUS(0,1);
	    		#endif
		
		#endif
	#endif

	#if (defined(MT6250)||defined(MT6260))
  
  		SET_LCD_PARALLEL_IF_TIMING(0, LCD_PARALLEL_CLOCK_104MHZ, 3, 4, 6, 5, 5, 18, 2);//rm68090 0,1,3,2,2,16,1s
		//SET_LCD_PARALLEL_IF_TIMING(0, LCD_PARALLEL_CLOCK_104MHZ, 1, 2, 4, 3, 3, 16, 1);

	#endif
	  
	#if (defined(MT6250)||defined(MT6260))
		set_lcd_driving_current(LCD_DRIVING_8MA);
	#endif
		  
	
#endif


}

/*****************************************************************************
 *wrap function for combo lcm interface *
 *============================================================================*/

void spi_ini(void)
{
	spi_ini_main();
}
void init_lcd_interface(void)
{
	init_lcd_interface_main();
}

void LCD_FunConfig(void)
{
	switch (MainLCDBlock.main_lcd_id)
	{
			
		case ST7789S:
			LCD_FunConfig_ST7789S();
			break;	
	    case GC9305:
	         LCD_FunConfig_GC9305();
	         break;  
		default:
			ASSERT(0);			
	}
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
void LCD_gamma_test_main(kal_uint8 level, kal_uint8 color)
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

void LCD_flicker_test_main(kal_uint8 level)
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


#ifdef COMBO_LCM_ID_AUTO_DETECT
kal_bool LCM_ID_Validation(void)
{
	switch (MainLCDBlock.main_lcd_id)
	{
	case ST7789S:
		return LCM_ID_check_ST7789S();
	case GC9305:
		return LCM_ID_check_GC9305();
	default:
		ASSERT(0);          
	}
}

kal_uint32 LCM_ID_Get(void)
{
  return MainLCDBlock.main_lcd_id;
}

void LCM_ID_Alter(void)
{
  MainLCDBlock.main_lcd_id++;
}
#endif

/*****************************************************************************
 *global varible*
 *============================================================================*/
 
kal_bool  lcd_assert_fail=KAL_FALSE;
kal_uint16 lcd_driver_rotation=LCD_LAYER_ROTATE_NORMAL;
kal_uint32 back_potch = 1;
