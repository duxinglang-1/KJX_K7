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
 *   w32_dslp_layer.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Display functions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "stdafx.h "
#include "string.h"
#include "resource.h "
#include <stdio.h>
#include <assert.h>
#include "kal_non_specific_general_types.h"
#include "w32_dspl.h"
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "stacklib.h"
#include "stack_timer.h"
#include "syscomp_config.h"
#include "task_config.h"
#include "device.h"
#include "wfd_lcd_modis.h"
#include "lcd_sw_inc.h"
#include "lcd_sw_rnd.h"
#include "lcm_if.h"
#include "kbd_table.h"
#include "kal_debug.h"
#include "w32_util.h"


#if defined(EMPTY_MMI) || defined(EXTERNAL_MMI)

int mainlcd_backlight_level = 0;
volatile kal_uint8 current_update_lcd = MAIN_LCD;
volatile kal_eventgrpid lcd_event_id = NULL;

LCD_Funcs MainLCD_temp;
LCD_Funcs SubLCD_temp;
volatile LCD_Funcs *MainLCD = &MainLCD_temp;
volatile LCD_Funcs *SubLCD	= &SubLCD_temp;

void w32_light_black_draw_mmi(void){}
int g_nSleepMode=0;

#else

#include "mmi_features.h"
#ifdef PLUTO_MMI
#include "MMIDataType.h"
#else
#include "pixteldatatypes.h"
#endif
#include "gdi_include.h"

#if defined(__COSMOS_MMI_PACKAGE__) || defined( __PLUTO_MMI_PACKAGE__)
#include "GlobalConstants.h"
#endif


/***************************************************************************** 
* Global variable
*****************************************************************************/
int g_nSleepMode=0;

//Main lcd max backlight level can be got through a API calling
int	mainlcd_backlight_level = 4;
const int g_mainlcd_backlight_level_min = 4;
int g_mainlcd_backlight_level_max = -1;
int	g_lcd_id = 1;
static HANDLE g_LCDProtectionMutex = NULL;
static char LCD_CS_is_deleted = 0 ;


HDC	lcd_hdcMem;	
HBITMAP	lcd_hbmp;

HDC	sub_lcd_hdcMem;	
HBITMAP	sub_lcd_hbmp;

BITMAPINFO bitmap_info;
BITMAPINFO sub_bitmap_info;

unsigned char Update_Status;
unsigned char new_application_flag = 0;

COLORREF show_display[LCD_HEIGHT][LCD_WIDTH];

int SIMULATOR_SKIN_LCD_X;
int SIMULATOR_SKIN_LCD_Y;
int SIMULATOR_SKIN_SUB_LCD_X;
int SIMULATOR_SKIN_SUB_LCD_Y;
int	skin_lcd_width;
int	skin_lcd_height;
int	skin_sublcd_width;
int	skin_sublcd_height;

static int key_release;
static int mouse_last_button_down_position = -1;

/* Main LCD simulator shadow buffer */
unsigned short	simulator_shadow_buffer[LCD_WIDTH * LCD_HEIGHT];
/* Main LCD frame buffer for bitmap */
unsigned int	simulator_frame_buffer[LCD_WIDTH * LCD_HEIGHT];

/* Sub LCD simulator shadow buffer */
#ifdef DUAL_LCD
unsigned short	simulator_sub_shadow_buffer[SUBLCD_WIDTH*SUBLCD_HEIGHT];
/* Sub LCD frame buffer for bitmap */
unsigned int	simulator_sub_frame_buffer[SUBLCD_WIDTH * SUBLCD_HEIGHT];
#endif

/* layers */
lcd_layer_struct_modis	lcd_layer_data[GDI_LCD_SUM][SIMULATOR_LAYER_COUNT];

/* palette look up table */
unsigned short	layer_sim_LUT0[256];
unsigned short	layer_sim_LUT1[256];

int	keypad_offset_x;
int	keypad_offset_y;

int	lcd_offset_x;
int	lcd_offset_y;
int	sub_lcd_offset_x;
int	sub_lcd_offset_y;

BOOL lcd_updating;

int	ViBrate_Num = 0;
T_W32_SCREEN_DEVICE	device, device_original;
volatile kal_uint8	current_update_lcd = MAIN_LCD;
volatile kal_eventgrpid	lcd_event_id = NULL;

S32	active_layer;
MODIS_UI_layer_info_struct	MODIS_UI_layer[SIMULATOR_LAYER_COUNT];
MODIS_UI_layer_info_struct	**MODIS_UI_layer_ptr = NULL;
MODIS_UI_layer_info_struct	*uil_ptr;

unsigned short	gShadowBuffer[LCD_HEIGHT][LCD_WIDTH];

// create this table, so we can use for loop to prcess each layer
static DWORD layer_flag_table[] = {
		LCD_LAYER0_ENABLE,
		LCD_LAYER1_ENABLE,
		LCD_LAYER2_ENABLE,
		LCD_LAYER3_ENABLE};

LCD_Funcs MainLCD_temp;
LCD_Funcs SubLCD_temp;
volatile LCD_Funcs *MainLCD = &MainLCD_temp;
volatile LCD_Funcs *SubLCD	= &SubLCD_temp;
BYTE *pResizeData;
CRITICAL_SECTION LCD_CS; 
char LCD_CSIsInitialized = 0 ;
static char UI_IsVibrating = 0;
BOOL g_bLockPaint = FALSE;
BOOL g_bUpdateScreen = FALSE;
static BOOL g_bEndKeyDown = FALSE; 

//Slide
BOOL g_bSlider = TRUE;

//MoDIS ui resize and rotate
float g_fResizeRatio=1.0;
int g_nRotate=0;

/***************************************************************************** 
* Local variable
*****************************************************************************/
/* MoDIS keycode mapping table :
 * according "read key profile setting", "MoDIS.ini setting" and driver key code
*  It is actually defined in MoDIS.ini
 */
static key_mapping_struct key_mapping_table[] =
{
//-1 means no define
	{0 ,	DEVICE_KEY_0,		VK_NUMPAD0},
	{1, 	DEVICE_KEY_1,		VK_NUMPAD1},
	{2, 	DEVICE_KEY_2,		VK_NUMPAD2},
	{3, 	DEVICE_KEY_3,		VK_NUMPAD3},
	{4, 	DEVICE_KEY_4,		VK_NUMPAD4},
	{5, 	DEVICE_KEY_5,		VK_NUMPAD5},
	{6, 	DEVICE_KEY_6,		VK_NUMPAD6},
	{7, 	DEVICE_KEY_7,		VK_NUMPAD7},
	{8, 	DEVICE_KEY_8,		VK_NUMPAD8},
	{9, 	DEVICE_KEY_9,		VK_NUMPAD9},
	//We do this definition in MoDIS.ini
	{10,	DEVICE_KEY_STAR,	0x00},		
	{11,	DEVICE_KEY_HASH,	0x00},	
	{12,	DEVICE_KEY_VOL_UP,	0x00},		
	{13,	DEVICE_KEY_VOL_DOWN,0x00},		
	{14,	DEVICE_KEY_UP,	0x00},		
	{15,	DEVICE_KEY_DOWN,		0x00},		
	{16,	DEVICE_KEY_LEFT,		0x00},		
	{17,	DEVICE_KEY_RIGHT,	0x00},		
	{18,	DEVICE_KEY_MENU,	0x00},		
	{19,	DEVICE_KEY_FUNCTION,	0x00},	
	{20,	DEVICE_KEY_SK_LEFT, 0x00},		
	{21,	DEVICE_KEY_SK_RIGHT,0x00},	
	{22,	DEVICE_KEY_SEND,	0x00},		
	{23,	DEVICE_KEY_END,0x00},  
	{-1,	DEVICE_KEY_POWER,	0x00},		//Change to F12
	{25,	DEVICE_KEY_CLEAR,	0x00},		
	{-1,	DEVICE_KEY_EXT_FUNC1,	0x00},		
	{-1,	DEVICE_KEY_EXT_FUNC2,	0x00},		
	{28,	DEVICE_KEY_MP3_PLAY_STOP,	0x78},	
	{29,	DEVICE_KEY_MP3_FWD, 0x7a},		
	{30,	DEVICE_KEY_MP3_BACK,	0x63},	
	{-1,	DEVICE_KEY_EXT_A,	0x00},		
	{-1,	DEVICE_KEY_EXT_B,	0x00},
	{33,	DEVICE_KEY_A,	'A'},		
	{34,	DEVICE_KEY_B,	'B'},		
	{35,	DEVICE_KEY_C,	'C'},		
	{36,	DEVICE_KEY_D,	'D'},		
	{37,	DEVICE_KEY_E,	'E'},		
	{38,	DEVICE_KEY_F,	'F'},	
	{39,	DEVICE_KEY_G,	'G'},		
	{40,	DEVICE_KEY_H,	'H'},	
	{41,	DEVICE_KEY_I,	'I'},		
	{42,	DEVICE_KEY_J,	'J'},		
	{43,	DEVICE_KEY_K,	'K'},		
	{44,	DEVICE_KEY_L,	'L'},	
	{45,	DEVICE_KEY_M,	'M'},		
	{46,	DEVICE_KEY_N,	'N'},		
	{47,	DEVICE_KEY_O,	'O'},		
	{48,	DEVICE_KEY_P,	'P'},		
	{49,	DEVICE_KEY_Q,	'Q'},		
	{50,	DEVICE_KEY_R,	'R'},		
	{51,	DEVICE_KEY_S,	'S'},		
	{52,	DEVICE_KEY_T,	'T'},		
	{53,	DEVICE_KEY_U,	'U'},
	{54,	DEVICE_KEY_V,	'V'},
	{55,	DEVICE_KEY_W,	'W'},
	{56,	DEVICE_KEY_X,	'X'},
	{57,	DEVICE_KEY_Y,	'Y'},
	{58,	DEVICE_KEY_Z,	'Z'},
	{59,	DEVICE_KEY_ENTER,	VK_RETURN},
	{60,	DEVICE_KEY_SPACE,	VK_SPACE},
	{-1,	DEVICE_KEY_TAB, VK_TAB},
	{-1,	DEVICE_KEY_DEL, VK_BACK}, //Change DEL to Backspace
	{-1,	DEVICE_KEY_ALT, VK_MENU}, //Left ALT & Right ALT
	{-1,	DEVICE_KEY_CTRL, VK_CONTROL}, //Left CTRL & Right CTRL
	{-1,	DEVICE_KEY_WIN, VK_LWIN},  //Left WIN
	{66,	DEVICE_KEY_SHIFT,	VK_SHIFT},
	{67,	DEVICE_KEY_QUESTION, '?'},
	{68,	DEVICE_KEY_PERIOD,	'.'},
	{69,	DEVICE_KEY_COMMA,	','},
	{-1,	DEVICE_KEY_EXCLAMATION, '!'},	
	{-1,	DEVICE_KEY_APOSTROPHE,	'\''},	
	{-1,	DEVICE_KEY_AT,	'@'},	
	{73,	DEVICE_KEY_SEND2,	0x00},
	 
	{-1,	DEVICE_KEY_BACKQUOTE   ,	0x00},	
	{-1,	DEVICE_KEY_DASH 	   ,	0x00},	
	{-1,	DEVICE_KEY_EQUAL	   ,	0x00},	
	{77,	DEVICE_KEY_BACKSPACE   ,	0x00},	
	{-1,	DEVICE_KEY_OPEN_PARENS ,	0x00},	
	{-1,	DEVICE_KEY_CLOSE_PARENS,	0x00},	
	{-1,	DEVICE_KEY_OPEN_SQUARE ,	0x00},	
	{-1,	DEVICE_KEY_CLOSE_SQUARE,	0x00},	
	{-1,	DEVICE_KEY_OPEN_BRACE  ,	0x00},	
	{-1,	DEVICE_KEY_CLOSE_BRACE ,	0x00},	
	{-1,	DEVICE_KEY_BACKSLASH   ,	0x00},
	{-1,	DEVICE_KEY_SEMICOLON   ,	0x00},	
	{-1,	DEVICE_KEY_SLASH	   ,	0x00},	
	{87,	DEVICE_KEY_DOLLAR	   ,	0x00},	
	{-1,	DEVICE_KEY_PERCENT	   ,	0x00},	
	{-1,	DEVICE_KEY_CARET	   ,	0x00},	
	{-1,	DEVICE_KEY_AND		   ,	0x00},	
	{-1,	DEVICE_KEY_QUOTE	   ,	0x00},	
	{-1,	DEVICE_KEY_PLUS 	   ,	0x00},	
	{-1,	DEVICE_KEY_LESS_THAN   ,	0x00},	
	{-1,	DEVICE_KEY_GREAT_THAN  ,	0x00},		
	{-1,	DEVICE_KEY_UNDERSCORE  ,	0x00},	
	{-1,	DEVICE_KEY_PIPE 	   ,	0x00},	
	{-1,	DEVICE_KEY_TILDE	   ,	0x00},	
	{-1,	DEVICE_KEY_CAPS_LOCK   ,	0x00},
	 
	{99,	DEVICE_KEY_NUM_LOCK   , 0x00}, //99
	
	{100,	DEVICE_KEY_FN		,	0x00},	
	{101,	DEVICE_KEY_SYMBOL	,	0x00},	
	{-1,	DEVICE_KEY_EMAIL	,	0x00},	
	{103,	DEVICE_KEY_MESSAGE	,	0x00},	
	{104,	DEVICE_KEY_CAMERA	,	0x00},	
	{-1,	DEVICE_KEY_ESC		,	0x00},		
	{106,	DEVICE_KEY_QWERTY_MENU	 ,	0x00},	
	{-1,	DEVICE_KEY_OK	,	0x00},

	{108,	DEVICE_KEY_SLIDER	, 0x00},
	{-1,	DEVICE_KEY_NONE   , 0x00},
	{-1,	DEVICE_KEY_NONE   , 0x00},	

	{111,	DEVICE_KEY_F1	,	0x00},	
	{112,	DEVICE_KEY_F2	,	0x00},
	{113,	DEVICE_KEY_F3	,	0x00},	
	{114,	DEVICE_KEY_F4	,	0x00},	
	{115,	DEVICE_KEY_F5	,	0x00},	
	{116,	DEVICE_KEY_F6	,	0x00},	
	{117,	DEVICE_KEY_F7	,	0x00},	
	{118,	DEVICE_KEY_F8	,	0x00},	
	{119,	DEVICE_KEY_F9	,	0x00},	
	{120,	DEVICE_KEY_F10	,	0x00},	
	{121,	DEVICE_KEY_F11	,	0x00},	
	{122,	DEVICE_KEY_F12	,	0x00},	
	{123,	DEVICE_KEY_BACK ,	0x00},
	{124,	DEVICE_KEY_HOME ,	0x00},
	//total 120 keys
			
	{125,	MAX_DEVICE_KEYS,	125},		
	{0xFE,	DEVICE_KEY_NONE,	0x00},	
};

//Key Name for w32_ReadKeyMapping
static const char *KeyMappingName[MAX_KEY_SUPPORT] = 
{
		"DEVICE_KEY_0",  //0	  
		"DEVICE_KEY_1", 	  
		"DEVICE_KEY_2", 	  
		"DEVICE_KEY_3", 	  
		"DEVICE_KEY_4", 	  
		"DEVICE_KEY_5", 	  
		"DEVICE_KEY_6", 	  
		"DEVICE_KEY_7", 	  
		"DEVICE_KEY_8", 	  
		"DEVICE_KEY_9", 	  
		"DEVICE_KEY_STAR",
		"DEVICE_KEY_HASH",	  
		"DEVICE_KEY_VOL_UP",	  
		"DEVICE_KEY_VOL_DOWN",	 
		"DEVICE_KEY_UP",		  
		"DEVICE_KEY_DOWN",	  
		"DEVICE_KEY_LEFT",	  
		"DEVICE_KEY_RIGHT",   
		"DEVICE_KEY_MENU",	  
		"DEVICE_KEY_FUNCTION",	 
		"DEVICE_KEY_SK_LEFT",  
		"DEVICE_KEY_SK_RIGHT",	 
		"DEVICE_KEY_SEND",	  
		"DEVICE_KEY_END",		  
		"DEVICE_KEY_POWER",   
		"DEVICE_KEY_CLEAR",   
		"DEVICE_KEY_EXT_FUNC1",  
		"DEVICE_KEY_EXT_FUNC2",  
		"DEVICE_KEY_MP3_PLAY_STOP",
		"DEVICE_KEY_MP3_FWD",	  
		"DEVICE_KEY_MP3_BACK",	 
		"DEVICE_KEY_EXT_A",   
		"DEVICE_KEY_EXT_B",   
		"DEVICE_KEY_A", 	  
		"DEVICE_KEY_B", 	  
		"DEVICE_KEY_C", 	  
		"DEVICE_KEY_D", 	  
		"DEVICE_KEY_E", 	  
		"DEVICE_KEY_F", 	  
		"DEVICE_KEY_G", 	  
		"DEVICE_KEY_H", 	  
		"DEVICE_KEY_I", 	  
		"DEVICE_KEY_J", 	  
		"DEVICE_KEY_K", 	  
		"DEVICE_KEY_L", 	  
		"DEVICE_KEY_M", 	  
		"DEVICE_KEY_N", 	  
		"DEVICE_KEY_O", 	  
		"DEVICE_KEY_P", 	  
		"DEVICE_KEY_Q", 	  
		"DEVICE_KEY_R", 	  
		"DEVICE_KEY_S", 	  
		"DEVICE_KEY_T", 	  
		"DEVICE_KEY_U", 	  
		"DEVICE_KEY_V", 	  
		"DEVICE_KEY_W", 	  
		"DEVICE_KEY_X", 	  
		"DEVICE_KEY_Y", 	  
		"DEVICE_KEY_Z", 	  
		"DEVICE_KEY_ENTER",   
		"DEVICE_KEY_SPACE",   
		"DEVICE_KEY_TAB",		  
		"DEVICE_KEY_DEL",		  
		"DEVICE_KEY_ALT",		  
		"DEVICE_KEY_CTRL",	  
		"DEVICE_KEY_WIN",		  
		"DEVICE_KEY_SHIFT",   
		"DEVICE_KEY_QUESTION",	 
		"DEVICE_KEY_PERIOD",	  
		"DEVICE_KEY_COMMA",   
		"DEVICE_KEY_EXCLAMATION",
		"DEVICE_KEY_APOSTROPHE", 
		"DEVICE_KEY_AT",		  
		"DEVICE_KEY_SEND2", //73
		
		"DEVICE_KEY_BACKQUOTE", 	  /* ` */  //74
		"DEVICE_KEY_DASH",			  /* - */ 
		"DEVICE_KEY_EQUAL", 		  /* = */ 
		"DEVICE_KEY_BACKSPACE", 	  /* <-*/
		"DEVICE_KEY_OPEN_PARENS",	  /* ( */ 
		"DEVICE_KEY_CLOSE_PARENS",	  /* ) */ 
		"DEVICE_KEY_OPEN_SQUARE",	  /* [ */ 
		"DEVICE_KEY_CLOSE_SQUARE",	  /* ] */ 
		"DEVICE_KEY_OPEN_BRACE",	  /* { */ 
		"DEVICE_KEY_CLOSE_BRACE",	  /* } */ 
		"DEVICE_KEY_BACKSLASH", 	  /* \ */ 
		"DEVICE_KEY_SEMICOLON", 	  /* ; */ 
		"DEVICE_KEY_SLASH", 		  /* / */ 
		"DEVICE_KEY_DOLLAR",		  /* $ */ 
		"DEVICE_KEY_PERCENT",		  /* % */ 
		"DEVICE_KEY_CARET", 		  /* ^ */ 
		"DEVICE_KEY_AND",			  /* & */ 
		"DEVICE_KEY_QUOTE", 		  /* " */ 
		"DEVICE_KEY_PLUS",			  /* + */ 
		"DEVICE_KEY_LESS_THAN", 	  /* < */ 
		"DEVICE_KEY_GREAT_THAN",	  /* > */ 
		"DEVICE_KEY_UNDERSCORE",	  /* _ */ 
		"DEVICE_KEY_PIPE",			  /* | */ 
		"DEVICE_KEY_TILDE", 		  /* ~ */ 
		"DEVICE_KEY_CAPS_LOCK", 	//98
		"DEVICE_KEY_NUM_LOCK", //99
		
		"DEVICE_KEY_FN",  //100 	
		"DEVICE_KEY_SYMBOL",	  
		"DEVICE_KEY_EMAIL", 	  
		"DEVICE_KEY_MESSAGE",	  
		"DEVICE_KEY_CAMERA",	  
		"DEVICE_KEY_ESC",	//105 
		"DEVICE_KEY_QWERTY_MENU", //106
		"DEVICE_KEY_OK", //107
		"DEVICE_KEY_SLIDER", //108
		NULL, //109
		NULL, //110 	
		"DEVICE_KEY_F1",	//111	   
		"DEVICE_KEY_F2",		  
		"DEVICE_KEY_F3",		  
		"DEVICE_KEY_F4",		  
		"DEVICE_KEY_F5",		  
		"DEVICE_KEY_F6",		  
		"DEVICE_KEY_F7",		  
		"DEVICE_KEY_F8",		  
		"DEVICE_KEY_F9",		  
		"DEVICE_KEY_F10",		  
		"DEVICE_KEY_F11",		  
		"DEVICE_KEY_F12",  //122
		"DEVICE_KEY_BACK",
		"DEVICE_KEY_HOME",//124

		"MAX_DEVICE_KEYS", //125
		"DEVICE_KEY_NONE", //126 
};	 


/***************************************************************************** 
* Local Function
*****************************************************************************/
static void w32_lcd_update_internal(
		lcd_frame_update_struct_modis *lcd_para,
		lcd_layer_struct_modis lcd_layer_data[][SIMULATOR_LAYER_COUNT],
		U32 layer_flag_table[],
		U32 *gdi_w32_lcd_buffer)
{
	unsigned char layer_id;
	unsigned char lcd_id;

	/* MODIS UI not init yet */
	if (MODIS_UI_layer_ptr == NULL)
	{
		return; 
	}
	
	/* set up the necessary information for DLL_UI */
	lcd_id = lcd_para->lcd_id;

	if (lcd_id == MAIN_LCD)
	{
		for (layer_id = 0; layer_id < SIMULATOR_LAYER_COUNT; layer_id++)
		{
			uil_ptr = MODIS_UI_layer_ptr[layer_id];

			uil_ptr->layer_x_offset = lcd_layer_data[lcd_id - 1][layer_id].x_offset;
			uil_ptr->layer_y_offset = lcd_layer_data[lcd_id - 1][layer_id].y_offset;
			uil_ptr->layer_width	= lcd_layer_data[lcd_id - 1][layer_id].column_number;
			uil_ptr->layer_height	= lcd_layer_data[lcd_id - 1][layer_id].row_number;

			uil_ptr->roi_x_offset	= lcd_para->roi_offset_x;
			uil_ptr->roi_y_offset	= lcd_para->roi_offset_y;
			uil_ptr->roi_width		= lcd_para->lcm_end_x - lcd_para->lcm_start_x;
			uil_ptr->roi_height 	= lcd_para->lcm_end_y - lcd_para->lcm_start_y;

			uil_ptr->source_key_enable = lcd_layer_data[lcd_id - 1][layer_id].source_key_enable;
			uil_ptr->opacity_enable = lcd_layer_data[lcd_id - 1][layer_id].opacity_enable;
			uil_ptr->source_key 	= lcd_layer_data[lcd_id - 1][layer_id].source_key;
			uil_ptr->opacity_value	= lcd_layer_data[lcd_id - 1][layer_id].opacity_value;

			uil_ptr->layer_enable	= (lcd_para->update_layer & layer_flag_table[layer_id]);
			uil_ptr->frame_buffer_address = lcd_layer_data[lcd_id - 1][layer_id].frame_buffer_address;

			uil_ptr->active_layer	= active_layer;
		}
	}

	/* send the main-lcd information to MODIS_UI for displaying */
	if (lcd_id == MAIN_LCD)
	{
		//Info monitor update
		MoDisUISetLayerData(MODIS_UI_layer_ptr,
							LCD_WIDTH,
							LCD_HEIGHT,
							SIMULATOR_LAYER_COUNT,
							&new_application_flag,
							&g_nSleepMode);

	}

	if (lcd_id == MAIN_LCD)
	{
		if(90 == g_nRotate || 270 == g_nRotate)
			w32_put_screen(lcd_id,
					   lcd_offset_x,
					   lcd_offset_y,
					   skin_lcd_height,
					   skin_lcd_width,
					   (unsigned char*)gdi_w32_lcd_buffer);
		else		
			w32_put_screen(lcd_id,
					   lcd_offset_x,
					   lcd_offset_y,
					   skin_lcd_width,
					   skin_lcd_height,
					   (unsigned char*)gdi_w32_lcd_buffer);
	}
	else
	{
#ifdef DUAL_LCD
		w32_put_screen(lcd_id,
					   sub_lcd_offset_x,
					   sub_lcd_offset_y,
					   skin_sublcd_width,
					   skin_sublcd_height,
					   (unsigned char*)gdi_w32_lcd_buffer);
#endif
	}
}

/*****************************************************************************
* FUNCTION
*  w32_convert_key_code
* DESCRIPTION
*  convert PC key code to SW driver key code
*
* PARAMETERS
*	void
* RETURNS
*  the index of the key mapping table
* GLOBALS AFFECTED
*  void
*****************************************************************************/
static int w32_convert_key_code(unsigned int vk, unsigned int *drv_key)
{    
	int i=0;
     
	for (i=0; i<MAX_KEY_SUPPORT; i++)
	{  
		if (key_mapping_table[i].pc_key_code == vk)
		{
			  /* find the mapping key code */
			  //It is actually defined in MoDIS.ini
			  *drv_key = key_mapping_table[i].sw_drv_key_code ;
			  return key_mapping_table[i].key_bitmap_id; //for UI only
		}
	}  
	return -1;
}    
     
static int w32_convert_LButtonDown2Key(unsigned int bitmap_num)
{    
	int i ;
	for( i = 0 ; i < MAX_KEY_SUPPORT ; ++i )
	{  
		if (key_mapping_table[i].key_bitmap_id == (int)bitmap_num)
		{
			  /* find the mapping key code */
			  //It is actually defined in MoDIS.ini
			  return key_mapping_table[i].sw_drv_key_code; 
		}
	}  
	return -1 ;
}    

/***************************************************************************** 
* Global Function
*****************************************************************************/
void w32_lcd_protection_init()
{
    g_LCDProtectionMutex = CreateMutex(NULL, FALSE, "MutexToProtectLCD");
	if( !LCD_CSIsInitialized )
	{			
		InitializeCriticalSection(&LCD_CS);
		LCD_CSIsInitialized = 1 ;
	}

    if (g_LCDProtectionMutex == NULL)
    {
        kal_print("Failed to create mutex\n");
        assert(0);
    }
}

void w32_lcd_protection_deinit()
{
    if (!CloseHandle(g_LCDProtectionMutex))
    {
        kal_print("Failed to close mutex handle\n");
    }
	LCD_CS_is_deleted = 1 ;
	//DeleteCriticalSection(&LCD_CS) ; 

    g_LCDProtectionMutex = NULL;
}


void get_backlight_level_max(void)
{
	g_mainlcd_backlight_level_max = (int)custom_uem_get_bl_level_num();
	g_mainlcd_backlight_level_max += 4;
	mainlcd_backlight_level = g_mainlcd_backlight_level_max;
}

/*****************************************************************************
* FUNCTION
*  config_lcd_roi_window
* DESCRIPTION
*  config lcd roi window
*
* PARAMETERS
*  roi_x_offset	IN			lcd layer
*  roi_y_offset	IN			lcd data
*  roi_column		IN			roi column
*  roi_row			IN			roi row
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
kal_bool config_lcd_roi_window(kal_uint16 roi_offset_x, kal_uint16 roi_offset_y, kal_uint16 roi_column,
			   						 kal_uint16 roi_row)
{
	return KAL_TRUE;
} /* end of config_lcd_roi_window */


/*****************************************************************************
* FUNCTION
*  LCD_SetVoltLevel
* DESCRIPTION
*  set lvd volt level
*
* PARAMETERS
*  voltage				IN			voltage
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void LCD_SetVoltLevel(kal_uint8 voltage)
{
} /* end of LCD_SetVoltLevel */


/*****************************************************************************
* FUNCTION
*  w32_mapping
* DESCRIPTION
*  mapping values
*
* PARAMETERS
*  value			IN			value
* RETURNS
*  mapping value
* GLOBALS AFFECTED
*  void
*****************************************************************************/
unsigned char w32_mapping(unsigned char value)
{
	switch(value)
	{
	case 0x0f:
		return 0xff;
	case 0x00:
		return 0x00;
	default:
		return (value << 4);
	}
} /* end of w32_mapping */


/*****************************************************************************
* FUNCTION
*  w32_draw_point
* DESCRIPTION
*  draw a point
*
* PARAMETERS
*  x			IN			X position
*  y			IN			Y position
*  color		IN			color of the point
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_draw_point(int x, int y, unsigned short color)
{
	COLORREF temp;
	temp = DRV_HW_TO_RGB_R(color) << 16 | DRV_HW_TO_RGB_G(color) << 8 | DRV_HW_TO_RGB_B(color);
	show_display[LCD_HEIGHT - y - 1][x] = temp;
} /* end of w32_draw_point */


/*****************************************************************************
* FUNCTION
*  w32_get_device_info
* DESCRIPTION
*  get the information of the display device
*
* PARAMETERS
*	void
* RETURNS
*	the pointer of the information structure of the device
* GLOBALS AFFECTED
*	void
*****************************************************************************/
void* w32_get_device_info(void)
{
	return &device;
} /* end of w32_get_device_info */


/*****************************************************************************
* FUNCTION
*  w32_dspl_init
* DESCRIPTION
*  initialize the display
*
* PARAMETERS
*	void
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_dspl_init(void)
{
	int	i = 0;
	HDC	hdc = NULL;
	if (MODIS_UI_layer_ptr == NULL)
	{
		MODIS_UI_layer_ptr = (MODIS_UI_layer_info_struct **)malloc(SIMULATOR_LAYER_COUNT * sizeof(MODIS_UI_layer_info_struct *));

		/* initialize pointer allocation for MODIS_UI_layer */
		for (i = 0; i < SIMULATOR_LAYER_COUNT; i++)
		{
			MODIS_UI_layer_ptr[i] = &MODIS_UI_layer[i];
		}
	}

	/* ATTENTION!!!
	 *
	 * w32_ReadKeyProfile() MUST be called before this function be called!
	 *
	 */

	/* initialize the information about dimension */
	skin_lcd_height	= device.main_lcd_height;
	skin_lcd_width	= device.main_lcd_width;
	skin_sublcd_height = device.sub_lcd_height;
	skin_sublcd_width = device.sub_lcd_width;
	lcd_offset_x = device.skin_main_lcd_x;
	lcd_offset_y = device.skin_main_lcd_y;

	/* draw to simulator's main LCD region */
	hdc	= GetDC(device.hwnd);
	if(lcd_hdcMem) 	
		DeleteDC(lcd_hdcMem); //wayne 0823
	if(lcd_hbmp) 
		DeleteObject(lcd_hbmp); //wayne 0823
	lcd_hdcMem	= CreateCompatibleDC(hdc);
	lcd_hbmp = CreateCompatibleBitmap(hdc, skin_lcd_width, skin_lcd_height);
 	SelectObject(lcd_hdcMem, lcd_hbmp);

	/* set up the bitmap infomation */
	bitmap_info.bmiHeader.biSize = sizeof(bitmap_info.bmiHeader);
	bitmap_info.bmiHeader.biWidth = skin_lcd_width;
	bitmap_info.bmiHeader.biHeight= skin_lcd_height;
	bitmap_info.bmiHeader.biPlanes = 1;
	bitmap_info.bmiHeader.biBitCount = 32;
	bitmap_info.bmiHeader.biCompression = BI_RGB;
	bitmap_info.bmiHeader.biSizeImage = skin_lcd_width * skin_lcd_height * 4;
	bitmap_info.bmiHeader.biClrUsed = 0;
	bitmap_info.bmiHeader.biClrImportant = 0;

#ifdef DUAL_LCD
	sub_lcd_offset_x = device.skin_sub_lcd_x;
	sub_lcd_offset_y = device.skin_sub_lcd_y;
	sub_bitmap_info.bmiHeader.biSize = sizeof(bitmap_info.bmiHeader);
	sub_bitmap_info.bmiHeader.biWidth = skin_sublcd_width;
	sub_bitmap_info.bmiHeader.biHeight = skin_sublcd_height;
	sub_bitmap_info.bmiHeader.biPlanes = 1;
	sub_bitmap_info.bmiHeader.biBitCount = 32;
	sub_bitmap_info.bmiHeader.biCompression	= BI_RGB;
	sub_bitmap_info.bmiHeader.biSizeImage		= skin_sublcd_width*skin_sublcd_height*4;
	sub_bitmap_info.bmiHeader.biClrUsed			= 0;
	sub_bitmap_info.bmiHeader.biClrImportant	= 0;
	if(sub_lcd_hdcMem) 
		DeleteDC(sub_lcd_hdcMem); //wayne 0823
	if(sub_lcd_hbmp) 
		DeleteObject(sub_lcd_hbmp); //wayne 0823
	sub_lcd_hdcMem	= CreateCompatibleDC(hdc);
	sub_lcd_hbmp	= CreateCompatibleBitmap(hdc, skin_sublcd_width, skin_sublcd_height);
	SelectObject(sub_lcd_hdcMem, sub_lcd_hbmp);
#endif

	ReleaseDC(device.hwnd, hdc);
} /* end of w32_dspl_init */


void w32_light_black_draw(int x, int y, int w, int h, HDC hdc, HDC lcd)
{
    RECT rc;
    BLENDFUNCTION bf;
    HBRUSH	black_brush;
    HDC memoryDC;
    HBITMAP bitmap;

	if(mainlcd_backlight_level == g_mainlcd_backlight_level_max)
		return;

    rc.left   = 0;
    rc.top    = 0;
    rc.right  = 0 + w;
    rc.bottom = 0 + h;
    bf.BlendOp = AC_SRC_OVER;
    bf.BlendFlags = 0;
    bf.AlphaFormat = 0; // ignore source alpha channel
    bf.SourceConstantAlpha = mainlcd_backlight_level*255 / g_mainlcd_backlight_level_max;
    black_brush = CreateSolidBrush(RGB(0, 0, 0));

	/***** Double buffering *****/
	//1. AlphaBlend
    memoryDC = CreateCompatibleDC(hdc);
	bitmap   = CreateCompatibleBitmap(hdc, w, h);
    SelectObject(memoryDC, bitmap);
    FillRect(memoryDC, &rc, black_brush);
	if(mainlcd_backlight_level > g_mainlcd_backlight_level_min && mainlcd_backlight_level < g_mainlcd_backlight_level_max)
		AlphaBlend(memoryDC, 0, 0, w, h, lcd, 0, 0, w, h, bf);	//if backlight off, don't alphablend, or the lcd will mess on some special occasions
	//2. BitBlt
	BitBlt(hdc, x, y, w, h,memoryDC, 0, 0, SRCCOPY);

	DeleteObject(black_brush);
    DeleteObject(bitmap);
    DeleteDC(memoryDC);
}


/*****************************************************************************
* FUNCTION
*  w32_update_screen
* DESCRIPTION
*  update the screen
*
* PARAMETERS
*	void
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_update_screen(void)
{
	HDC hdc;
	if (!lcd_updating)
	{
		hdc = GetDC(device.hwnd);
		if(mainlcd_backlight_level == g_mainlcd_backlight_level_max)
		{
			if(ViBrate_Num==0) //No Vibrate
			{
				BitBlt(hdc, lcd_offset_x, lcd_offset_y, skin_lcd_width, skin_lcd_height, lcd_hdcMem, 0, 0, SRCCOPY);	
			}
		}
		else if( mainlcd_backlight_level >= g_mainlcd_backlight_level_min && mainlcd_backlight_level<=g_mainlcd_backlight_level_max-1)
		{
			if(ViBrate_Num==0) //No Vibrate
			{
				g_lcd_id = 1; 
				w32_light_black_draw(lcd_offset_x, lcd_offset_y, skin_lcd_width, skin_lcd_height, hdc, lcd_hdcMem) ;
			}
		}
		
#ifdef DUAL_LCD
		if(mainlcd_backlight_level==g_mainlcd_backlight_level_max)
		{
			if(ViBrate_Num==0) //No Vibrate
			{
				BitBlt (hdc, sub_lcd_offset_x,sub_lcd_offset_y,skin_sublcd_width, skin_sublcd_height,sub_lcd_hdcMem, 0, 0, SRCCOPY);
			}
		}
		else if( mainlcd_backlight_level >=g_mainlcd_backlight_level_min && mainlcd_backlight_level<=g_mainlcd_backlight_level_max-1)
		{
			if(ViBrate_Num==0) //No Vibrate
			{
				g_lcd_id = 2;
				w32_light_black_draw( sub_lcd_offset_x,sub_lcd_offset_y,skin_sublcd_width, skin_sublcd_height, hdc,sub_lcd_hdcMem) ;	
			}
		}
#endif
		ReleaseDC(device.hwnd,hdc);
	}
	
} /* end of w32_update_screen */


void w32_light_black_draw_mmi(void)
{
	HDC	hdc;
	hdc = GetDC(device.hwnd);
	g_lcd_id = 1;
	w32_light_black_draw(lcd_offset_x,lcd_offset_y,skin_lcd_width,skin_lcd_height, hdc,lcd_hdcMem);
	ReleaseDC(hdc, device.hwnd);
}

/*****************************************************************************
* FUNCTION
*  w32_put_screen
* DESCRIPTION
*  put a bitmap to the screen
*
* PARAMETERS
*	lcd_in	IN		LCD ID
*	x		IN		X position
*	y		IN		Y position
*	w		IN		width
*	h		IN		height
*	bmp	IN		pointer to the bitmap
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_put_screen(unsigned char lcd_id, int x, int y, int w, int h, unsigned char *bmp)
{
	HDC	hdc;
	int LCD_WIDTH_NEW, LCD_HEIGHT_NEW;

	if(g_bUpdateScreen)
		return;
	g_bUpdateScreen = TRUE;
	g_lcd_id = lcd_id;

	hdc = GetDC(device.hwnd);
	g_bLockPaint = TRUE;

	
	if(90 == g_nRotate || 270 == g_nRotate)
	{	
		LCD_WIDTH_NEW = LCD_HEIGHT;
		LCD_HEIGHT_NEW = LCD_WIDTH;
	}
	else
	{
		LCD_WIDTH_NEW = LCD_WIDTH;
		LCD_HEIGHT_NEW = LCD_HEIGHT;
	}
	
	if (lcd_id == MAIN_LCD)
	{
		if(w == LCD_WIDTH && h==LCD_HEIGHT)
		{
			if(0 != g_nRotate)
			{
				unsigned char* destbmp =(unsigned char*) malloc ((w+1)*(h+1)*4*sizeof(BYTE));
				RotateBmpBuf(w,h, bmp,destbmp,g_nRotate);
				if(180 == g_nRotate)
					SetDIBits(NULL, lcd_hbmp, 0, h, destbmp, &bitmap_info, DIB_RGB_COLORS);
				else
					SetDIBits(NULL, lcd_hbmp, 0, w, destbmp, &bitmap_info, DIB_RGB_COLORS);
				free(destbmp);
			}
			else
				SetDIBits(NULL, lcd_hbmp, 0, h, bmp, &bitmap_info, DIB_RGB_COLORS);
		}
		else
		{
			BYTE *pResizeData =  (BYTE *) malloc(w*h*sizeof(BYTE)*4);
			if(w >= LCD_WIDTH && h>=LCD_HEIGHT) //resize w,h both >=original W,H
				EnlargeDataInt(bmp,LCD_WIDTH, LCD_HEIGHT,pResizeData,w,h);
			else if (w < LCD_WIDTH && h< LCD_HEIGHT) //resize w,h both < original W,H
				ShrinkDataInt(bmp,LCD_WIDTH, LCD_HEIGHT,pResizeData,w,h);
			//The following resize is seldom use
			else if( w >= LCD_WIDTH && h < LCD_HEIGHT) //resize w,h w >= LCD_WIDTH && h < LCD_HEIGHT
			{
				BYTE *ptmpResizeData =  (BYTE *) malloc(w*LCD_HEIGHT*sizeof(BYTE)*4);
				EnlargeDataInt(bmp,LCD_WIDTH, LCD_HEIGHT,ptmpResizeData,w,LCD_HEIGHT);

				ShrinkDataInt(ptmpResizeData,w, LCD_HEIGHT,pResizeData,w,h);
				free(ptmpResizeData);
			}
			else if( w < LCD_WIDTH && h >= LCD_HEIGHT)//resize w,h; w < LCD_WIDTH && h >= LCD_HEIGHT
			{
				BYTE *ptmpResizeData =  (BYTE *) malloc(LCD_WIDTH*h*sizeof(BYTE)*4);
				EnlargeDataInt(bmp,LCD_WIDTH, LCD_HEIGHT,ptmpResizeData,LCD_WIDTH,h);

				ShrinkDataInt(ptmpResizeData,LCD_WIDTH, h,pResizeData,w,h);
				free(ptmpResizeData);
			}
			if(0 != g_nRotate)
			{
				unsigned char* destbmp =(unsigned char*) malloc ((w+1)*(h+1)*4*sizeof(BYTE));
				RotateBmpBuf(w,h, pResizeData,destbmp,g_nRotate);
				if(180 == g_nRotate)
					SetDIBits(NULL, lcd_hbmp, 0, h, destbmp, &bitmap_info, DIB_RGB_COLORS);
				else
					SetDIBits(NULL, lcd_hbmp, 0, w, destbmp, &bitmap_info, DIB_RGB_COLORS);
				free(destbmp);
			}
			else
				SetDIBits(NULL, lcd_hbmp, 0, h, pResizeData, &bitmap_info, DIB_RGB_COLORS);
			free(pResizeData);
		}
		
		if(mainlcd_backlight_level==g_mainlcd_backlight_level_max)
		{
			if(ViBrate_Num==0) //No Vibrate
			{
				if(90 == g_nRotate || 270 == g_nRotate)
					BitBlt(hdc,	x,y,h,w,lcd_hdcMem, 0, 0, SRCCOPY);
				else
					BitBlt(hdc,	x,y,w,h,lcd_hdcMem, 0, 0, SRCCOPY);
			}
		}
		else if( mainlcd_backlight_level >=g_mainlcd_backlight_level_min && mainlcd_backlight_level<=g_mainlcd_backlight_level_max-1)
		{
						
			if(ViBrate_Num==0) //No Vibrate
			{
				if(90 == g_nRotate || 270 == g_nRotate)
					w32_light_black_draw(x,y,h,w,hdc,lcd_hdcMem);		
				else
					w32_light_black_draw(x,y,w,h,hdc,lcd_hdcMem);			
			}
		}
	
		ReleaseDC(device.hwnd,hdc);
	}
	else
	{
	#ifdef DUAL_LCD
		//hdc		= GetDC(device.hwnd);
		//kal_print("DUAL_LCD");
		if(w == SUBLCD_WIDTH && h==SUBLCD_HEIGHT)
		{
			SetDIBits(NULL, sub_lcd_hbmp, 0, h, bmp, &sub_bitmap_info, DIB_RGB_COLORS);
		}
		else
		{
		BYTE *psubResizeData =  (BYTE *) malloc(w*h*sizeof(BYTE)*4);
		 if(w >= SUBLCD_WIDTH && h>=SUBLCD_HEIGHT) //resize w,h both >=original W,H
			EnlargeDataInt(bmp,SUBLCD_WIDTH, SUBLCD_HEIGHT,psubResizeData,w,h);
		 else if (w < SUBLCD_WIDTH && h< SUBLCD_HEIGHT) //resize w,h both < original W,H
			ShrinkDataInt(bmp,SUBLCD_WIDTH, SUBLCD_HEIGHT,psubResizeData,w,h);
		 else if( w >= SUBLCD_WIDTH && h < SUBLCD_HEIGHT) //resize w,h w >= LCD_WIDTH && h < LCD_HEIGHT
		 {
		    BYTE *psubtmpResizeData =  (BYTE *) malloc(w*SUBLCD_HEIGHT*sizeof(BYTE)*4);
			EnlargeDataInt(bmp,SUBLCD_WIDTH, SUBLCD_HEIGHT,psubtmpResizeData,w,SUBLCD_HEIGHT);

			ShrinkDataInt(psubtmpResizeData,w, SUBLCD_HEIGHT,psubResizeData,w,h);
			free(psubtmpResizeData);
		 }
		 else if( w < SUBLCD_WIDTH && h >= SUBLCD_HEIGHT)//resize w,h; w < LCD_WIDTH && h >= LCD_HEIGHT
		 {
			BYTE *psubtmpResizeData =  (BYTE *) malloc(SUBLCD_WIDTH*h*sizeof(BYTE)*4);
			EnlargeDataInt(bmp,SUBLCD_WIDTH, SUBLCD_HEIGHT,psubtmpResizeData,SUBLCD_WIDTH,h);

			ShrinkDataInt(psubtmpResizeData,SUBLCD_WIDTH, h,psubResizeData,w,h);
			free(psubtmpResizeData);
		 }
		SetDIBits(NULL, sub_lcd_hbmp, 0, h, psubResizeData, &sub_bitmap_info, DIB_RGB_COLORS);
			free(psubResizeData);
		}
		if(mainlcd_backlight_level==g_mainlcd_backlight_level_max)
		{
			if(ViBrate_Num==0) 
			{
				BitBlt(hdc,x,y,w,h,sub_lcd_hdcMem, 0, 0, SRCCOPY);
				//UpdateWindow( device.hwnd );
			}
		}
		else if( mainlcd_backlight_level >=g_mainlcd_backlight_level_min && mainlcd_backlight_level<=g_mainlcd_backlight_level_max-1)
		{
			if(ViBrate_Num==0) //No Vibrate
			{
				w32_light_black_draw(x,y,w,h,hdc,sub_lcd_hdcMem);			
			}		
		}
		
		ReleaseDC(device.hwnd, hdc);
	#endif
	}

	g_bLockPaint  =FALSE;
	g_bUpdateScreen = FALSE;

} /* end of w32_put_screen */





/*****************************************************************************
* FUNCTION
*  w32_lcd_update
* DESCRIPTION
*  update the lcd
*
* PARAMETERS
*	lcd_para			IN		the updating parameters for lcd
*	lcd_layer_data		IN		the related information for each layer
*	layer_flag_table	IN		the table of layer updating flag
*	gdi_w32_lcd_buffer	IN		the merged lcd image
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_lcd_update(
        lcd_frame_update_struct_modis *lcd_para,
        lcd_layer_struct_modis lcd_layer_data[][SIMULATOR_LAYER_COUNT],
        U32 layer_flag_table[],
        U32 *gdi_w32_lcd_buffer)
{

	//Get max backlight level only once
	static int nGot = 0;
	if(0 == nGot)
	{
		get_backlight_level_max();
		nGot = 1;
	}

	if( !LCD_CSIsInitialized )
		return ;					

	if( LCD_CS_is_deleted )
		return ;
	EnterCriticalSection(&LCD_CS); 
    w32_lcd_update_internal(lcd_para,
                            lcd_layer_data,
                            layer_flag_table,
                            gdi_w32_lcd_buffer);
	LeaveCriticalSection(&LCD_CS); 
	return ;

} /* end of w32_lcd_update */


/*****************************************************************************
* FUNCTION
*  w32_ResetKeyMemory
* DESCRIPTION
*  initialize the memory for images of keys
*
* PARAMETERS
*	void
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_ResetKeyMemory()
{
	device.main_bitmap = device.main_bitmap_down = NULL;
	device_original.main_bitmap = device_original.main_bitmap_down = NULL;
} /* end of w32_ResetKeyMemory */

/*****************************************************************************
* FUNCTION
*  w32_ReadKeyMapping
* DESCRIPTION
*  read the key mapping from the INI file
*
* PARAMETERS
*	in_path		IN		path for INI file
*	hwnd			IN		window handle
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_ReadKeyMapping(char in_path[], HWND hwnd)
{
	char	buffer[512], path[512];
	int i ;
	HANDLE	hFind;
	WIN32_FIND_DATA FindFileData;


	hFind = FindFirstFile("MoDIS.ini", &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		/* Can't find the file "MoDIS.ini" */
		return ;
	}
	FindClose(hFind);

	/* get the complete name for opening the INI file */
	strcpy(path, "./MoDIS.ini");
	
	//Willie
	//Load key setting
	//GetPrivateProfileString("Keyboard-Mapping","TOTAL_KEY_NUM", NULL, buffer, sizeof(buffer), path);
	//total_key_num = atoi(buffer);
	for( i = 0 ; i < MAX_KEY_SUPPORT ; ++i )
	{
		if( GetPrivateProfileString("Keyboard-Mapping", KeyMappingName[i] , NULL, buffer, sizeof(buffer), path) != 0 )
			key_mapping_table[i].pc_key_code = atohex(buffer);
	}	
}
char *w32_GerProfilePath()
{
	char profilePath[256];
	GetPrivateProfileString("LCD","MMI_SKIN_NAME", NULL, profilePath, 256, "../Skin/SkinStyleLog.ini");
    return profilePath;
}
char *w32_GetProfileName()
{
	char profileName[512];
	strcpy( profileName, "./Profile_Revise.ini") ;	
    return profileName;
}

void w32_ui_post_process(HWND hwnd)
{
	char buffer[8];
	HDC hdcTplt = GetDC(hwnd);
	
	/*Read resize and rotate seeting in .ini file*/
	GetPrivateProfileString(SEC_INTEGRATE, KEY_RESIZE, DEF_RESIZE, buffer, 8, PATH_MODIS_INI);
	_atoflt(&g_fResizeRatio, buffer);
	GetPrivateProfileString(SEC_INTEGRATE, KEY_ROTATE, DEF_ROTATE, buffer, 8, PATH_MODIS_INI);
	g_nRotate = atoi(buffer);

	/*Resize*/
	if(g_fResizeRatio > 1.02 || g_fResizeRatio < 0.98)
	{
		//main size
		device.window_width *= g_fResizeRatio;
		device.window_height *= g_fResizeRatio;
		device.skin_main_lcd_x *= g_fResizeRatio;
		device.skin_main_lcd_y *= g_fResizeRatio;
		device.main_lcd_width *= g_fResizeRatio;
		device.main_lcd_height *= g_fResizeRatio;
		device.skin_sub_lcd_x *= g_fResizeRatio;
		device.skin_sub_lcd_y *= g_fResizeRatio;
		device.sub_lcd_width *= g_fResizeRatio;
		device.sub_lcd_height *= g_fResizeRatio;
		device.main_bitmap_width *= g_fResizeRatio;
		device.main_bitmap_height *= g_fResizeRatio;
		
		//resize bg down image
		{
			HBITMAP hbmWnd = NULL;

			if (device.main_bitmap_down != NULL)
				DeleteDC(device.main_bitmap_down);
					
			device.main_bitmap_down = CreateCompatibleDC(hdcTplt);
			hbmWnd = CreateCompatibleBitmap(hdcTplt, device.main_bitmap_width, device.main_bitmap_height);	
			SelectObject(device.main_bitmap_down, hbmWnd); 
			SetStretchBltMode(device.main_bitmap_down, STRETCH_HALFTONE);
			StretchBlt(device.main_bitmap_down,0,0,device.main_bitmap_width, device.main_bitmap_height,
				device_original.main_bitmap_down,0,0,device_original.main_bitmap_width, device_original.main_bitmap_height,SRCCOPY);
		
			DeleteObject(hbmWnd);
		}

		
		//resize bg image
		{
			HBITMAP hbmWnd = NULL;

			if (device.main_bitmap != NULL)
				DeleteDC(device.main_bitmap);
					
			device.main_bitmap = CreateCompatibleDC(hdcTplt);
			hbmWnd = CreateCompatibleBitmap(hdcTplt, device.main_bitmap_width, device.main_bitmap_height);	
			SelectObject(device.main_bitmap, hbmWnd); 
			SetStretchBltMode(device.main_bitmap, STRETCH_HALFTONE);
			StretchBlt(device.main_bitmap,0,0,device.main_bitmap_width, device.main_bitmap_height,
				device_original.main_bitmap,0,0,device_original.main_bitmap_width, device_original.main_bitmap_height,SRCCOPY);
		
			DeleteObject(hbmWnd);
		}

		//resize key layout information
		{
			int i = 0;
			for(i = 0 ; i < MAX_KEY_SUPPORT ; ++i )
			{
				ResizeRECT(&device.key_location[i], g_fResizeRatio);
			}	
			
		}
		
	}

	
	/*Rotate*/
	
	{
		int i = 0;
		RECT rcLCD;

		if(g_nRotate > 0)
		{
			//Bg image HDC
			RotateHDC(device.main_bitmap, device.main_bitmap_width, device.main_bitmap_height, g_nRotate);
			RotateHDC(device.main_bitmap_down, device.main_bitmap_width, device.main_bitmap_height, g_nRotate);

			//LCD size: MainLCD & SubLCD
			rcLCD.left = device.skin_main_lcd_x;
			rcLCD.top = device.skin_main_lcd_y;
			rcLCD.right = rcLCD.left + device.main_lcd_width;
			rcLCD.bottom = rcLCD.top + device.main_lcd_height;
			RotateRECT(&rcLCD, g_nRotate, device.window_width, device.window_height);
			device.skin_main_lcd_x = rcLCD.left;
			device.skin_main_lcd_y = rcLCD.top;
			device.main_lcd_width = rcLCD.right - rcLCD.left;
			device.main_lcd_height = rcLCD.bottom - rcLCD.top;
			
			rcLCD.left = device.skin_sub_lcd_x;
			rcLCD.top = device.skin_sub_lcd_y;
			rcLCD.right = rcLCD.left + device.sub_lcd_width;
			rcLCD.bottom = rcLCD.top + device.sub_lcd_height;
			RotateRECT(&rcLCD, g_nRotate, device.window_width, device.window_height);
			device.skin_sub_lcd_x = rcLCD.left;
			device.skin_sub_lcd_y = rcLCD.top;
			device.sub_lcd_width = rcLCD.right - rcLCD.left;
			device.sub_lcd_height = rcLCD.bottom - rcLCD.top;

			//Keypad layout	
			for(i = 0 ; i < MAX_KEY_SUPPORT ; ++i )
			{
				RotateRECT(&device.key_location[i], g_nRotate, device.window_width, device.window_height);
			}		
		}
		
		//Others	
		switch(g_nRotate)
		{
		case 0:
			#if defined(__COSMOS_MMI_PACKAGE__) || defined( __PLUTO_MMI_PACKAGE__)
			mmi_auto_rotate_on_modis_handler(KEY_0);
			#endif				
			break;
		
		case 90:
			//LCD
			#if defined(__COSMOS_MMI_PACKAGE__) || defined( __PLUTO_MMI_PACKAGE__)
			mmi_auto_rotate_on_modis_handler(KEY_STAR);
			#endif
			Swap(&device.window_width, &device.window_height);
			Swap(&device.main_bitmap_width, &device.main_bitmap_height);
			break;
			
		case 270:
			#if defined(__COSMOS_MMI_PACKAGE__) || defined( __PLUTO_MMI_PACKAGE__)
			mmi_auto_rotate_on_modis_handler(KEY_POUND);
			#endif
			Swap(&device.window_width, &device.window_height);
			Swap(&device.main_bitmap_width, &device.main_bitmap_height);
			break;
		case 180:
			#if defined(__COSMOS_MMI_PACKAGE__) || defined( __PLUTO_MMI_PACKAGE__)
			mmi_auto_rotate_on_modis_handler(KEY_1);
			#endif
			break;
		default:
			break;
		}
	}

	/* reset window size */
	{
		RECT window_info, client_info;
		int menuheight;
		GetWindowRect(hwnd, &window_info);
		GetClientRect(hwnd, &client_info);
		SetWindowPos(hwnd, 0, 0, 0, device.window_width, device.window_height + (window_info.bottom - client_info.bottom - window_info.top), SWP_NOMOVE | SWP_NOZORDER);
		menuheight = window_info.bottom - window_info.top - client_info.bottom + client_info.top;

		GetWindowRect(hwnd, &window_info);
		GetClientRect(hwnd, &client_info);
		if (menuheight != (window_info.bottom - window_info.top - client_info.bottom + client_info.top))
			SetWindowPos(hwnd, 0, 0, 0, device.window_width, device.window_height + (window_info.bottom - client_info.bottom - window_info.top), SWP_NOMOVE | SWP_NOZORDER);
		SendMessage(hwnd, WM_MOVE, 0, (client_info.top << 2 * sizeof(short)) + client_info.left);
	}

	ReleaseDC(hwnd, hdcTplt);

	w32_dspl_init();

}

/*****************************************************************************
* FUNCTION
*  ReadOneImageInformation
* DESCRIPTION
*  Read one image information from the INI file
*
*****************************************************************************/
void ReadOneImageInformation(LPCSTR pcszImageName, 
							 LONG*plWidth, LONG*plHeight, HDC* pbmpImage, HDC hdcTplt, LPCSTR pcszIniSection, LPCSTR pcszIniPath)
{
	char	buffer[512];
	int buffer_size = 512;
	HBITMAP img = NULL;
	BITMAP	bmp = {0,0,0,0,0,0, NULL};
	SIZE sz;

	GetPrivateProfileString(pcszIniSection, pcszImageName, NULL, buffer, buffer_size, pcszIniPath);
	if (*pbmpImage != NULL)
		DeleteDC(*pbmpImage);

	//if(g_fResizeRatio < 1.02 && g_fResizeRatio > 0.98)
	{
		MTKLoadImage(pbmpImage, (LPCSTR)buffer, &sz);
		(*plWidth) = sz.cx;
		(*plHeight) = sz.cy;
	}

}

/*****************************************************************************
* FUNCTION
*  ReadOneKeyInformation
* DESCRIPTION
*  read one key information from the INI file
*
*****************************************************************************/
void ReadOneKeyInformation(LPCSTR pcszKeyname, RECT* prectKey, 
						   HDC hdcTplt, LPCSTR pcszIniSection, LPCSTR pcszIniPath)
{
	char szKeyLayout[128];
	char buffer[512];
	int buffer_size = 512;

	memset(szKeyLayout, 0, 128);
	memset(buffer, 0, 512);

	if(NULL == pcszKeyname)
		return;

	strcpy( szKeyLayout, pcszKeyname);
	strcat( szKeyLayout, "_LAYOUT");
	GetPrivateProfileString(pcszIniSection, szKeyLayout, NULL, buffer, buffer_size, pcszIniPath);
	if (strlen(buffer) <= 0)
		return;

	ParseLayoutString(buffer, strlen(buffer), prectKey);
}

/*****************************************************************************
* FUNCTION
*  w32_ReadKeyProfile
* DESCRIPTION
*  read the key information from the INI file
*
* PARAMETERS
*	in_path		IN		path for INI file
*	hwnd			IN		window handle
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/

void w32_ReadKeyProfile(char in_path[], HWND hwnd)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	char			buffer[512], old_path[512], path[512];
	int			buffer_size = 512;
	HBITMAP		img;
	BITMAP		bmp;
	HDC			hdc;
	RECT			window_info, client_info, menu_info, show_info;
	int i ;
	int			menuheight;
	char profile_section_name[256];

	SIZE main_window_size;
	RECT rcMainLcd, rcSubLcd;

	//Debug using
	char sengkeymode[64];
	char phonetype[64];

	memset(sengkeymode,0,64);
	memset(phonetype,0,64);
	GetPrivateProfileString(SEC_FEATURES,KEY_SENDKEY_MODE, NULL, sengkeymode, 64, PATH_MODIS_INI);
	GetPrivateProfileString(SEC_FEATURES,KEY_PHONE_TYPE, NULL, phonetype, 64, PATH_MODIS_INI);

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/* save the original working directory */
	GetCurrentDirectory(512, old_path);
	/* get the complete name for opening the INI file */
	SetCurrentDirectory(in_path);
	strcpy(path, w32_GetProfileName());

	/* Form section name*/
	memset(profile_section_name,0,256);
	strcpy(profile_section_name, sengkeymode);
	strcat(profile_section_name, "_");
	if(0 == strcmp("CLAMSHELL", phonetype))
		strcat(profile_section_name, "BAR");
	else
		strcat(profile_section_name, phonetype);
	if(0 == strcmp("SLIDE", phonetype))
	{
		if(g_bSlider)
			strcat(profile_section_name, "_ON");
		else
			strcat(profile_section_name, "_OFF");
	}

	OutputDebugStringA("Profile section name:\n");
	OutputDebugStringA(profile_section_name);
	OutputDebugStringA("\n");

	/* get layout related date */
	GetPrivateProfileString(profile_section_name, "MAIN_WINDOW_SIZE", NULL, buffer, buffer_size, path);
	if(strlen(buffer) <= 0)
	{
		MessageBox(hwnd, "Sorry, MoDIS UI skin not supported on this project", "MoDIS", MB_OK | MB_ICONWARNING);
		PostMessage(GetConsoleWindow(), WM_CLOSE, 0, 0);
		return;
	}
	ParseSizeString(buffer, strlen(buffer), &main_window_size);
	GetPrivateProfileString(profile_section_name, "MAIN_LCD_LAYOUT", NULL, buffer, buffer_size, path);
	ParseLayoutString(buffer, strlen(buffer), &rcMainLcd);
	GetPrivateProfileString(profile_section_name, "SUB_LCD_LAYOUT", NULL, buffer, buffer_size, path);
	ParseLayoutString(buffer, strlen(buffer), &rcSubLcd);

	device.window_width = main_window_size.cx;
	device.window_height = main_window_size.cy;
	device.skin_main_lcd_x = rcMainLcd.left;
	device.skin_main_lcd_y = rcMainLcd.top;
	device.main_lcd_width = (rcMainLcd.right - rcMainLcd.left);
	device.main_lcd_height = (rcMainLcd.bottom - rcMainLcd.top);
	device.skin_sub_lcd_x = rcSubLcd.left;
	device.skin_sub_lcd_y = rcSubLcd.top;
	device.sub_lcd_width = (rcSubLcd.right - rcSubLcd.left);
	device.sub_lcd_height = (rcSubLcd.bottom - rcSubLcd.top);

	hdc = GetDC(hwnd);

	/* background image and all keys */
	MTKDeleteDC(device.main_bitmap);
	MTKDeleteDC(device.main_bitmap_down);
	ReadOneImageInformation("BACKGROUND_UP", &device.main_bitmap_width, &device.main_bitmap_height, 
		&device.main_bitmap, hdc, profile_section_name, path);
	ReadOneImageInformation("BACKGROUND_DOWN", &device.main_bitmap_width, &device.main_bitmap_height, 
		&device.main_bitmap_down, hdc, profile_section_name, path);

	for( i = 0 ; i < MAX_KEY_SUPPORT ; ++i )
	{
		device.key_location[i].left = device.key_location[i].top = 
			device.key_location[i].right = device.key_location[i].bottom = -1 ;
		ReadOneKeyInformation(KeyMappingName[i], &device.key_location[i], hdc, profile_section_name, path);
	}	

	/* Copy original device value, it will be useful when resizing and rotating*/
	MTKDeleteDC(device_original.main_bitmap);
	MTKDeleteDC(device_original.main_bitmap_down);
	device_original = device;
	device_original.main_bitmap = device_original.main_bitmap_down = NULL;
	ReadOneImageInformation("BACKGROUND_UP", &device_original.main_bitmap_width, &device_original.main_bitmap_height, 
		&device_original.main_bitmap, hdc, profile_section_name, path);
	ReadOneImageInformation("BACKGROUND_DOWN", &device_original.main_bitmap_width, &device_original.main_bitmap_height, 
		&device_original.main_bitmap_down, hdc, profile_section_name, path);

	/* restore the original working directory */
	SetCurrentDirectory(old_path);

	w32_ui_post_process(hwnd);

	ReleaseDC(hwnd, hdc);
	w32_ReadKeyMapping(old_path, hwnd);	
} /* end of w32_ReadKeyProfile */


/*****************************************************************************
* FUNCTION
*  w32_screen_init
* DESCRIPTION
*  initialize the screen
*
* PARAMETERS
*	hWnd			IN		window handle
*	hInstance	IN		handle of instance
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_screen_init(HWND hWnd, HINSTANCE hInstance)
{
	device.hwnd = hWnd;
	w32_dspl_init();
} /* end of w32_screen_init */


/*****************************************************************************
* FUNCTION
*  w32_draw_main_bitmap
* DESCRIPTION
*  draw the main bitmap
*
* PARAMETERS
*	hdc			IN		dc handle
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
//Draw part of main bitmap specified by rcROI
void w32_draw_main_bitmap_roi(HDC hdc, RECT rcROI, BOOL bDownEffect)
{
	if (bDownEffect)
	{
		BitBlt(hdc, rcROI.left, rcROI.top, rcROI.right - rcROI.left, rcROI.bottom - rcROI.top, device.main_bitmap_down, 
			rcROI.left, rcROI.top, SRCCOPY);
	} 
	else
	{
		BitBlt(hdc, rcROI.left, rcROI.top, rcROI.right - rcROI.left, rcROI.bottom - rcROI.top, device.main_bitmap, 
			rcROI.left, rcROI.top, SRCCOPY);
	}

} /* end of w32_draw_main_bitmap_roi */

void w32_draw_main_bitmap(HDC hdc)
{
	RECT rcROI;
	rcROI.left = rcROI.top = 0;
	rcROI.right = device.main_bitmap_width;
	rcROI.bottom = device.main_bitmap_height;
	w32_draw_main_bitmap_roi(hdc, rcROI, FALSE);
} /* end of w32_draw_main_bitmap */


/*****************************************************************************
* FUNCTION
*  w32_vibrate_by_move
* DESCRIPTION
*  vibrate_by_move
*
* PARAMETERS
*	interval means millsecond
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_vibrate_by_move(kal_uint8 onoff) //interval mean milisecond
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	//char		buf[64];
	
	HDC hdc, hdcTemp; 
	HBITMAP hbmpTemp;
	RECT rectbk;
	COLORREF crrefresh;
	HBRUSH hbrrefresh;

	hdc = GetDC(device.hwnd);

	//Create a temp HDC to avoid flipping
	hdcTemp = CreateCompatibleDC(hdc);
	hbmpTemp = CreateCompatibleBitmap(hdc, device.main_bitmap_width, device.main_bitmap_height);
	SelectObject(hdcTemp, hbmpTemp);

	if(!onoff)
	{
		if(ViBrate_Num!=0)
			MoDISCallTimer(FALSE);

		//Draw all items on temp HDC
		BitBlt(hdcTemp, 0, 0, device.main_bitmap_width, device.main_bitmap_height, device.main_bitmap, 0, 0, SRCCOPY);
		if(mainlcd_backlight_level ==g_mainlcd_backlight_level_max)
		{
			BitBlt(hdcTemp, lcd_offset_x,lcd_offset_y,skin_lcd_width,skin_lcd_height,lcd_hdcMem, 0, 0, SRCCOPY);
		}
		else if (mainlcd_backlight_level >=g_mainlcd_backlight_level_min && mainlcd_backlight_level<=g_mainlcd_backlight_level_max-1)
		{
			g_lcd_id = 1;
			w32_light_black_draw(lcd_offset_x,lcd_offset_y,skin_lcd_width,skin_lcd_height, hdcTemp,lcd_hdcMem);
		}
#ifdef DUAL_LCD
		if(mainlcd_backlight_level ==g_mainlcd_backlight_level_max)
			BitBlt(hdcTemp,	sub_lcd_offset_x,sub_lcd_offset_y,skin_sublcd_width,skin_sublcd_height,sub_lcd_hdcMem, 0, 0, SRCCOPY);
		else if (mainlcd_backlight_level >=g_mainlcd_backlight_level_min && mainlcd_backlight_level<=g_mainlcd_backlight_level_max-1)
			w32_light_black_draw(sub_lcd_offset_x,sub_lcd_offset_y,skin_sublcd_width,skin_sublcd_height, hdcTemp,sub_lcd_hdcMem);
#endif

		//Draw temp HDC to real HDC
		BitBlt(hdc, 0, 0, device.main_bitmap_width, device.main_bitmap_height, hdcTemp, 0, 0, SRCCOPY);
		ViBrate_Num = 0;
		UI_IsVibrating = 0;
	}
	else
	{
		UI_IsVibrating = 1;	
		if(ViBrate_Num==0)
			MoDISCallTimer(TRUE);
		if(ViBrate_Num%2==0)
		{	
			//Draw all items on temp HDC
			g_lcd_id = 1;
			BitBlt(hdcTemp, 0, 0, device.main_bitmap_width, device.main_bitmap_height, device.main_bitmap, 0, 0, SRCCOPY);
			if(mainlcd_backlight_level ==g_mainlcd_backlight_level_max)
				BitBlt(hdcTemp,	lcd_offset_x,lcd_offset_y,skin_lcd_width,skin_lcd_height,lcd_hdcMem, 0, 0, SRCCOPY);
			else if (mainlcd_backlight_level >=g_mainlcd_backlight_level_min && mainlcd_backlight_level<=g_mainlcd_backlight_level_max-1)
				w32_light_black_draw(lcd_offset_x,lcd_offset_y,skin_lcd_width,skin_lcd_height, hdcTemp,lcd_hdcMem);
#ifdef DUAL_LCD
			if(mainlcd_backlight_level ==g_mainlcd_backlight_level_max)
				BitBlt(hdcTemp,	sub_lcd_offset_x,sub_lcd_offset_y,skin_sublcd_width,skin_sublcd_height,sub_lcd_hdcMem, 0, 0, SRCCOPY);
			else if (mainlcd_backlight_level >=g_mainlcd_backlight_level_min && mainlcd_backlight_level<=g_mainlcd_backlight_level_max-1)
				w32_light_black_draw(sub_lcd_offset_x,sub_lcd_offset_y,skin_sublcd_width,skin_sublcd_height, hdcTemp,sub_lcd_hdcMem);
#endif

			//Draw temp HDC to real HDC
			BitBlt(hdc, 0, 0, device.main_bitmap_width, device.main_bitmap_height, hdcTemp, 0, 0, SRCCOPY);
		}
		else
		{
			//Erase the background
			rectbk.top = 0;
			rectbk.left = 0;
			rectbk.right = device.main_bitmap_width;
			rectbk.bottom = device.main_bitmap_height;
			crrefresh = RGB(224,224,224); 
			hbrrefresh = CreateSolidBrush(crrefresh); 
			FillRect(hdcTemp, &rectbk, hbrrefresh);

			//Draw all items on temp HDC
			g_lcd_id = 1;
			BitBlt(hdcTemp, VIBRATE_PIXEL, VIBRATE_PIXEL, device.main_bitmap_width, device.main_bitmap_height, device.main_bitmap, 0, 0, SRCCOPY);
			if(mainlcd_backlight_level ==g_mainlcd_backlight_level_max)
				BitBlt(hdcTemp,	lcd_offset_x+VIBRATE_PIXEL,lcd_offset_y+VIBRATE_PIXEL,skin_lcd_width,skin_lcd_height,lcd_hdcMem, 0, 0, SRCCOPY);
			else if (mainlcd_backlight_level >=g_mainlcd_backlight_level_min && mainlcd_backlight_level<=g_mainlcd_backlight_level_max-1)
				w32_light_black_draw(lcd_offset_x+VIBRATE_PIXEL,lcd_offset_y+VIBRATE_PIXEL,skin_lcd_width,skin_lcd_height, hdcTemp,lcd_hdcMem);
#ifdef DUAL_LCD
			if(mainlcd_backlight_level ==g_mainlcd_backlight_level_max)
				BitBlt(hdcTemp,	sub_lcd_offset_x+VIBRATE_PIXEL,sub_lcd_offset_y+VIBRATE_PIXEL,skin_sublcd_width,skin_sublcd_height,sub_lcd_hdcMem, 0, 0, SRCCOPY);
			else if (mainlcd_backlight_level >=g_mainlcd_backlight_level_min && mainlcd_backlight_level<=g_mainlcd_backlight_level_max-1)
				w32_light_black_draw(sub_lcd_offset_x+VIBRATE_PIXEL,sub_lcd_offset_y+VIBRATE_PIXEL,skin_sublcd_width,skin_sublcd_height, hdcTemp,sub_lcd_hdcMem);
#endif

			//Draw temp HDC to real HDC
			BitBlt(hdc, VIBRATE_PIXEL, VIBRATE_PIXEL, device.main_bitmap_width, device.main_bitmap_height, hdcTemp, 0, 0, SRCCOPY);
		}
		ViBrate_Num++;
	}

	if(hbmpTemp)
		DeleteObject(hbmpTemp);
	if(hdcTemp)
		DeleteDC(hdcTemp);
	if(hdc)
		ReleaseDC(device.hwnd, hdc);
}/* end of w32_vibrate_by_move */


/*****************************************************************************
* FUNCTION
*  w32_keyup_by_mouse
* DESCRIPTION
*  function for mouse button up
*
* PARAMETERS
*	hWnd			IN		window handle
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_keyup_by_mouse(HWND hWnd,int wParam,int xNewPos,int yNewPos)
{
	HDC		hdc;
	int		i; 
	BOOL	status = FALSE;
	int		drvkey ;
	if( UI_IsVibrating )
		return ;
	if( mouse_last_button_down_position != -1 )  
	{
		//If mouse has pressed button on something
		i = mouse_last_button_down_position ;
		mouse_last_button_down_position = -1 ;
		hdc = GetDC(hWnd);
		w32_draw_main_bitmap_roi(hdc, device.key_location[i], FALSE);

		drvkey = w32_convert_LButtonDown2Key( (unsigned int)i ) ;
		if( drvkey != DEVICE_KEY_END )  //Avoid Poweroff
			w32_key_detect_ind((unsigned char)DRV_KEY_UP, (unsigned char)drvkey);

	    ReleaseDC(hWnd, hdc);    
	}   
} /* end of w32_keyup_by_mouse */


/*****************************************************************************
* FUNCTION
*  w32_keydown_by_mouse
* DESCRIPTION
*  function for mouse button down
*
* PARAMETERS
*	hWnd			IN		window handle
*	xPos			IN		X position
*	yPos			IN		Y position
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_keydown_by_mouse(HWND hWnd, int xPos, int yPos,int xNewPos,int yNewPos)
{
	int	i; 

	if( UI_IsVibrating )
		return ;   
	mouse_last_button_down_position = -1;

	xPos -= keypad_offset_x;
	yPos -= keypad_offset_y;

	for (i=0; i < PC_KEY_NUMBERS; i++)
	{
		if (xPos > device.key_location[i].left && xPos < device.key_location[i].right &&
			yPos > device.key_location[i].top && yPos < device.key_location[i].bottom)
		{	
			int drvkey;
			HDC hdc;

			//Draw keydown effect
			hdc = GetDC(hWnd);
			w32_draw_main_bitmap_roi(hdc, device.key_location[i], TRUE);

			if(strcmp("DEVICE_KEY_SLIDER", KeyMappingName[i]) == 0)
			{
				//If "Slide" key pressed, change background image
				g_bSlider = !g_bSlider;
				slider_switch_set_gpio(g_bSlider);
				w32_ReadKeyProfile(w32_GerProfilePath(), hWnd);
				w32_draw_main_bitmap(hdc);
				w32_update_screen();
			}
			else
			{
				//Send keydown message to mmi framework
				mouse_last_button_down_position = i;
				drvkey = w32_convert_LButtonDown2Key( (unsigned int)i ) ;
				w32_key_detect_ind((unsigned char)DRV_KEY_DOWN, (unsigned char)drvkey);
				if(drvkey == DEVICE_KEY_END )  //Avoid Poweroff
					w32_key_detect_ind( 1, DEVICE_KEY_END);
			}
			
			ReleaseDC(hWnd, hdc);
			return;	
        }
	}

} /* end of w32_keydown_by_mouse */


/*****************************************************************************
* FUNCTION
*  w32_mouse_move_enable
* DESCRIPTION
*  mouse move enable
*
* PARAMETERS
*	hWnd			IN		window handle
*	xPos			IN		X position
*	yPos			IN		Y position
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_mouse_move_enable(HWND hWnd, int xPos, int yPos,int xNewScrnSize,int yNewScrnSize)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	int		i; 
	int		mx, my;
	BOOL		status = FALSE;
	HDC		hdc;
	char		buf[128];
	RECT		rect;
	COLORREF	crBkgnd;
	HBRUSH	hbrBkgnd;


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	mx = xPos;
	my = yPos;
 
	xPos -= keypad_offset_x;
	yPos -= keypad_offset_y;
	
	for (i=0 ; i < PC_KEY_NUMBERS; i++)
	{
		if (xPos > device.key_location[i].left && xPos < device.key_location[i].right &&
			yPos > device.key_location[i].top && yPos < device.key_location[i].bottom)
		{	
         status = TRUE;
			break;	
      }
	}  
	if (status)
	{
		SetCursor(LoadCursor(0, MAKEINTRESOURCE(32649)));
	}

	// display position
	hdc			= GetDC(device.hwnd);
	rect.top	= keypad_offset_y;
	rect.left	= keypad_offset_x;
	rect.right	= keypad_offset_x + 60;
	rect.bottom	= keypad_offset_y + 17;

	crBkgnd = GetBkColor(hdc); 
	hbrBkgnd = CreateSolidBrush(crBkgnd); 
	FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1));

	sprintf(buf, "(%d,%d)", mx - lcd_offset_x, my - lcd_offset_y);
	DrawText(hdc, buf, strlen(buf), &rect, DT_CENTER);

	DeleteObject(hbrBkgnd); 
	ReleaseDC(device.hwnd, hdc);
} /* end of w32_mouse_move_enable */


/*****************************************************************************
* FUNCTION
*  w32_keydown_by_shortcut
* DESCRIPTION
*  keydown from shortcut
*
* PARAMETERS
*	hWnd			IN		window handle
*	vk				IN		key
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_keydown_by_shortcut( HWND hWnd, int vk )
{
	int	i = 0;
	unsigned int drv_key ;
	HDC	hdc;

	if( UI_IsVibrating )
		return ;
	
	if(g_bEndKeyDown)
		return;

	i = w32_convert_key_code(vk,&drv_key);
	
	if (i >= 0) //Not QWERTY keypad
	{
		if(DEVICE_KEY_END == drv_key)
			g_bEndKeyDown = TRUE;

		hdc = GetDC(hWnd);
		w32_draw_main_bitmap_roi(hdc, device.key_location[i], TRUE);
		
		w32_key_detect_ind( (unsigned char)DRV_KEY_DOWN, (unsigned char)drv_key);
		//UpdateWindow( device.hwnd );
		
		if( drv_key == DEVICE_KEY_END ) //disable power off(Send a End-Key up after End-Key Down immediately)
            w32_key_detect_ind((unsigned char)DRV_KEY_UP, (unsigned char)drv_key );
            
		ReleaseDC(hWnd, hdc);
	}
} /* end of w32_keydown_by_shortcut */


/*****************************************************************************
* FUNCTION
*  w32_keyup_by_shortcut
* DESCRIPTION
*  keydown from shortcut
*
* PARAMETERS
*	hWnd			IN		window handle
*	wParam		IN		wParam
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_keyup_by_shortcut(HWND hWnd, unsigned int wParam)
{
	HDC		hdc;
	unsigned int drv_key ;
	int i = w32_convert_key_code(wParam, &drv_key);

	if( UI_IsVibrating )
		return ;
	
	if ( i >= 0 )
	{
		if(DEVICE_KEY_END == drv_key)
			g_bEndKeyDown = FALSE;

		hdc = GetDC(hWnd);
		w32_draw_main_bitmap_roi(hdc, device.key_location[i], FALSE);
		
		if( drv_key != DEVICE_KEY_END )  //If End-Key, don't send key up
			w32_key_detect_ind((unsigned char)DRV_KEY_UP, (unsigned char)drv_key);
		ReleaseDC(hWnd, hdc);
	}	
} /* end of w32_keyup_by_shortcut */


/*****************************************************************************
* FUNCTION
*  DisplayToDebugwindow
* DESCRIPTION
*  display to debug window
*
* PARAMETERS
*	void
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void DisplayToDebugwindow(void)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/


} /* end of DisplayToDebugwindow */


/*****************************************************************************
* FUNCTION
*  LCD_Dummy
* DESCRIPTION
*  LCD dummy function
*
* PARAMETERS
*	void
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void LCD_Dummy(void)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/


} /* end of LCD_Dummy */


/*****************************************************************************
* FUNCTION
*  LCD_Dummy_Return
* DESCRIPTION
*  LCD dummy return
*
* PARAMETERS
*	void
* RETURNS
*  3
* GLOBALS AFFECTED
*  void
*****************************************************************************/
kal_uint8 LCD_Dummy_Return()
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   return 3;
} /* end of LCD_Dummy_Return */




/*****************************************************************************
* FUNCTION
*  LCD_Init_MODIS
* DESCRIPTION
*  LCD initialization for MODIS
*
* PARAMETERS
*	bkground		IN		background
*	buf_addr		IN		address for the buffer
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void LCD_Init_MODIS(kal_uint32 bkground, void **buf_addr)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	int	x;
	int	y;


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	for (x = 0; x < LCD_WIDTH; x++)
	{
		for (y = 0; y < LCD_HEIGHT; y++)
		{
			gShadowBuffer[y][x] = bkground;
		}
	}

	if (buf_addr)
	{
		*buf_addr = &gShadowBuffer[0][0];
	}
} /* end of LCD_Init_MODIS */



/*****************************************************************************
* FUNCTION
*  get_lcd_status
* DESCRIPTION
*  get lcd status
*
* PARAMETERS
*	void
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
kal_bool get_lcd_status(void)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	return 0;
} /* end of get_lcd_status */


/*****************************************************************************
* FUNCTION
*  modis_ui_set_new_application_flag
* DESCRIPTION
*  set the flag to indicate that a new application starts
*
* PARAMETERS
*	void
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void modis_ui_set_new_application_flag()
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	new_application_flag = 1;
} /* end of modis_ui_set_new_application_flag */


/*****************************************************************************
* FUNCTION
*  modis_ui_set_layer_data
* DESCRIPTION
*  set the flag to indicate that a new application starts
*
* PARAMETERS
*	layer_index			IN		index for the layer
*	lcd_id				IN		lcd id
*	text_clip_left		IN		text clipping region info
*	text_clip_top		IN		text clipping region info
*	text_clip_right	IN		text clipping region info
*	text_clip_bottom	IN		text clipping region info
*	gfx_clip_left		IN		clipping region info
*	gfx_clip_top		IN		clipping region info
*	gfx_clip_right		IN		clipping region info
*	gfx_clip_bottom	IN		clipping region info
*	current_handle		IN		current lcd handle
*	active_handle		IN		active lcd handle
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void modis_ui_set_layer_data(
	U8			layer_index,
	U8			lcd_id,
	S32		text_clip_left,
	S32		text_clip_top,
	S32		text_clip_right,
	S32		text_clip_bottom,

	S32		gfx_clip_left,
	S32		gfx_clip_top,
	S32		gfx_clip_right,
	S32		gfx_clip_bottom,

	S32		current_handle,
	S32		active_handle
)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	int	 i;


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	if (MODIS_UI_layer_ptr == NULL)
	{
		MODIS_UI_layer_ptr = (MODIS_UI_layer_info_struct **)malloc(SIMULATOR_LAYER_COUNT * sizeof(MODIS_UI_layer_info_struct *));

		/* initialize pointer allocation for MODIS_UI_layer */
		for (i = 0; i < SIMULATOR_LAYER_COUNT; i++)
		{
			MODIS_UI_layer_ptr[i] = &MODIS_UI_layer[i];
		}
	}

	if (lcd_id == MAIN_LCD)
	{
		/* UIL := UI Layer */
		uil_ptr = MODIS_UI_layer_ptr[layer_index];

		uil_ptr->text_clip_left = text_clip_left;
		uil_ptr->text_clip_top = text_clip_top;
		uil_ptr->text_clip_right = text_clip_right;
		uil_ptr->text_clip_bottom = text_clip_bottom;

		uil_ptr->gfx_clip_left = gfx_clip_left;
		uil_ptr->gfx_clip_top = gfx_clip_top;
		uil_ptr->gfx_clip_right = gfx_clip_right;
		uil_ptr->gfx_clip_bottom = gfx_clip_bottom;

		if (current_handle == active_handle)
		{
			active_layer = layer_index;
		}
	}
} /* end of modis_ui_set_layer_data */


/*****************************************************************************
* FUNCTION
*  resume_lcd_layer_rotate
* DESCRIPTION
*  resume lcd layer rotation
*
* PARAMETERS
*	void
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void resume_lcd_layer_rotate(void)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/


} /* end of resume_lcd_layer_rotate */


/*****************************************************************************
* FUNCTION
*  set_lcd_layer_roate
* DESCRIPTION
*  set lcd layer rotation
*
* PARAMETERS
*	rotate_layer	IN		the layer for rotating
*	rotate_value	IN		the rotation value
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void set_lcd_layer_roate(kal_uint32 rotate_layer, kal_uint8 rotate_value)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/


} /* end of set_lcd_layer_roate */

#ifdef __MMI_TOUCH_SCREEN__

static int w32_touch_screen_mouse_down;
static void w32_touch_screen_get_point_mapping(int *x, int *y,int xNewScrnSize,int yNewScrnSize)
{
	POINT point;

	if( xNewScrnSize == 0 || yNewScrnSize == 0 )
		return ;
	
	GetCursorPos(&point);

	ScreenToClient(device.hwnd, &point);

	if(0 == g_nRotate)
	{
		*x = (point.x - lcd_offset_x) / g_fResizeRatio;
		*y = (point.y - lcd_offset_y) / g_fResizeRatio;
	}
	else if(90 == g_nRotate)
	{
		*y = (xNewScrnSize - (point.x - lcd_offset_x)) / g_fResizeRatio;
		*x = ( point.y - lcd_offset_y) / g_fResizeRatio;
	}
	else if(180 == g_nRotate)
	{
		*x = (xNewScrnSize - point.x + lcd_offset_x) / g_fResizeRatio;
		*y = (yNewScrnSize - point.y + lcd_offset_y) / g_fResizeRatio;
	}
	else if(270 == g_nRotate)
	{
		*y = (point.x - lcd_offset_x) / g_fResizeRatio;
		*x = (yNewScrnSize - point.y + lcd_offset_y) / g_fResizeRatio;
	}

	kal_printf("X=%d, Y= %d\n", point.x,point.y);
	kal_printf("lcd_offsetX=%d, Y= %d\n", lcd_offset_x,lcd_offset_y);
	kal_printf("xNewScrnSize=%d, yNewScrnSize= %d\n", xNewScrnSize,yNewScrnSize);
	kal_printf("mapping X=%d, Y= %d\n", *x,*y);
}
static void w32_touch_screen_get_point(int *x, int *y)
{
	POINT point;
	GetCursorPos(&point);
	kal_printf("X=%d, Y= %d\n", point.x,point.y);
	ScreenToClient(device.hwnd, &point);

	*x = point.x - lcd_offset_x;
	*y = point.y - lcd_offset_y;
	kal_printf("minus lcd_offset X=%d, Y= %d\n", *x,*y);
}


BOOL w32_touch_screen_button_down(int xNewScrnSize, int yNewScrnSize)
{
	int x, y;
	int newx,newy;
	if( w32_touch_screen_mouse_down )
	{
		kal_printf("Warning... Next mouse left-button up will not work...");
		return 0 ;
	}
	
	if(90 == g_nRotate || 270 == g_nRotate)
		w32_touch_screen_get_point_mapping(&x, &y,LCD_HEIGHT*g_fResizeRatio,LCD_WIDTH*g_fResizeRatio);
	else
		w32_touch_screen_get_point_mapping(&x, &y,LCD_WIDTH*g_fResizeRatio,LCD_HEIGHT*g_fResizeRatio);

	if (x >= 0 && x < LCD_WIDTH && y >= 0 && y < LCD_HEIGHT)
	{		
		mmi_pen_MODIS_enqueue_down((S16)x, (S16)y);
		w32_touch_screen_mouse_down = 1;
		SetCapture(device.hwnd);
		return 1;
	}
	else
	{
		return 0;
	}
}

BOOL w32_touch_screen_button_move(int xNewScrnSize, int yNewScrnSize)
{
	int x, y;
	int newx,newy;

	if (w32_touch_screen_mouse_down)
	{
		if(90 == g_nRotate || 270 == g_nRotate)
			w32_touch_screen_get_point_mapping(&x, &y,LCD_HEIGHT*g_fResizeRatio,LCD_WIDTH*g_fResizeRatio);
		else
			w32_touch_screen_get_point_mapping(&x, &y,LCD_WIDTH*g_fResizeRatio,LCD_HEIGHT*g_fResizeRatio);
		
		if(x < 0)
			x = 0;
		if(y < 0)
			y = 0;
		if(x > LCD_WIDTH)
			x = LCD_WIDTH;
		if(y > LCD_HEIGHT)
			y = LCD_HEIGHT;
		mmi_pen_MODIS_enqueue_move((S16)x, (S16)y);
		return 1;
	}
	else
	{
		return 0;
	}
}

BOOL w32_touch_screen_button_up(int xNewScrnSize, int yNewScrnSize)
{
	int x, y;
	int newx,newy;
	if (w32_touch_screen_mouse_down)
	{
		if(90 == g_nRotate || 270 == g_nRotate)
			w32_touch_screen_get_point_mapping(&x, &y,LCD_HEIGHT*g_fResizeRatio,LCD_WIDTH*g_fResizeRatio);
		else
			w32_touch_screen_get_point_mapping(&x, &y,LCD_WIDTH*g_fResizeRatio,LCD_HEIGHT*g_fResizeRatio);
		
		if(x < 0)
			x = 0;
		if(y < 0)
			y = 0;
		if(x > LCD_WIDTH)
			x = LCD_WIDTH;
		if(y > LCD_HEIGHT)
			y = LCD_HEIGHT;
		mmi_pen_MODIS_enqueue_up((S16)x, (S16)y);
		w32_touch_screen_mouse_down = 0;
		ReleaseCapture();
		return 1;
	}
	else
	{
		return 0;
	}
}

#else /* __MMI_TOUCH_SCREEN__ */

BOOL w32_touch_screen_button_down(int dummy1, int dummy2)
{
	return FALSE;
}

BOOL w32_touch_screen_button_move(int dummy1, int dummy2)
{
	return FALSE;
}

BOOL w32_touch_screen_button_up(int dummy1, int dummy2)
{
	return FALSE;
}

#endif /* __MMI_TOUCH_SCREEN__ */

/*****************************************************************************
* FUNCTION
*  mouse_mouse
* DESCRIPTION
*  mouse move enable
*
* PARAMETERS
*	hWnd			IN		window handle
*	xPos			IN		X position
*	yPos			IN		Y position
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void mouse_move(HWND hWnd, int xPos, int yPos,int xNewScrnSize, int yNewScrnSize)
{
	if( UI_IsVibrating )
		return ;


	if(90 == g_nRotate || 270 == g_nRotate)
	{
		if (!w32_touch_screen_button_move(yNewScrnSize,xNewScrnSize))
			w32_mouse_move_enable(hWnd, xPos, yPos,xNewScrnSize,yNewScrnSize);
	}
	else
	{
		if (!w32_touch_screen_button_move(xNewScrnSize, yNewScrnSize))
			w32_mouse_move_enable(hWnd, xPos, yPos,xNewScrnSize, yNewScrnSize);
	}
} /* end of mouse_mouse */


/*****************************************************************************
* FUNCTION
*  mouse_lbutton_up
* DESCRIPTION
*  function for mouse button up
*
* PARAMETERS
*	hWnd			IN		window handle
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void mouse_lbutton_up(HWND hWnd,int wParam,int xNewScrnSize, int yNewScrnSize)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

	if( UI_IsVibrating )
		return ;

	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	//EnterCriticalSection(&LCD_CS);	
	if (!w32_touch_screen_button_up(xNewScrnSize, yNewScrnSize))
	{
		w32_keyup_by_mouse(hWnd,wParam,xNewScrnSize, yNewScrnSize);//0 mean nothing, just default
	}
	//LeaveCriticalSection(&LCD_CS);	
} /* end of mouse_lbutton_up */


/*****************************************************************************
* FUNCTION
*  mouse_lbutton_down
* DESCRIPTION
*  function for mouse button down
*
* PARAMETERS
*	hWnd			IN		window handle
*	xPos			IN		X position
*	yPos			IN		Y position
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void mouse_lbutton_down(HWND hWnd, int xPos, int yPos, int xNewScrnSize, int yNewScrnSize)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	if( UI_IsVibrating )
		return ;

	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	//EnterCriticalSection(&LCD_CS);	
	if (!w32_touch_screen_button_down(xNewScrnSize,yNewScrnSize))
	{
		w32_keydown_by_mouse(hWnd, xPos, yPos,xNewScrnSize,yNewScrnSize);
	}
	//LeaveCriticalSection(&LCD_CS);	
} /* end of mouse_lbutton_down */


/*****************************************************************************
 * FUNCTION
 *  get_mainlcd_hbitmap
 * DESCRIPTION
 *  Allocate a BITMAP object and save the main lcd content to it
 * PARAMETERS
 *  void
 * RETURNS
 *  HBITMAP
 *****************************************************************************/
HBITMAP get_mainlcd_hbitmap(void)
{
	return GetSrcBit(lcd_hdcMem, skin_lcd_width, skin_lcd_height);
}

#endif // defined(EMPTY_MMI) || defined(EXTERNAL_MMI)
