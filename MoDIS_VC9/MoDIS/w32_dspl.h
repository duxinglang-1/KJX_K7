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
 *   w32_dslp.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of display functions
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __PC_DISPLAY_H
#define __PC_DISPLAY_H

#include "kal_release.h"

/********************************************************
	Typedef structures
*********************************************************/

/*Used information when parsing INI files*/
#define PATH_UI_INI "./MoDIS_UI.ini"
#define PATH_MODIS_INI "./MoDIS.ini"


#define SEC_SKIN "Skin"
#define SEC_PATH "Path"
#define SEC_FEATURES "FeatureOptions"
#define SEC_BOARD_VER "BoardVersion"
#define SEC_INTEGRATE "INTEGRATE"

#define KEY_RESIZE "Resize"
#define KEY_ROTATE "Rotate"

#define KEY_PHONE_TYPE "PHONE_TYPE"
#define KEY_KEYPAD_TYPE "KEYPAD_TYPE"
#define KEY_SENDKEY_MODE "SENDKEY_MODE"

#define KEY_MMI_SCREEN_ROTATE_SUPPORT "MMI_SCREEN_ROTATE_SUPPORT"


#define DEF_RESIZE "1"
#define DEF_ROTATE "0"

#define VAL_MMI_SCREEN_ROTATE_TRUE "TRUE"
#define VAL_MMI_SCREEN_ROTATE_FALSE "FALSE"

/*Screen device*/
#define PC_KEY_NUMBERS 300
typedef struct {
	HWND			hwnd;
	RECT			lcd_location;
   	RECT			key_location[PC_KEY_NUMBERS];
	HDC				main_bitmap, main_bitmap_down;
	
	unsigned int	main_bitmap_width;
	unsigned int	main_bitmap_height;

	/* the data below are read from the INI file */
	unsigned int	main_lcd_height;
	unsigned int	main_lcd_width;
	unsigned int	skin_main_lcd_x;
	unsigned int	skin_main_lcd_y;
	unsigned int	sub_lcd_height;
	unsigned int	sub_lcd_width;
	unsigned int	skin_sub_lcd_x;
	unsigned int	skin_sub_lcd_y;
	unsigned int	window_height;
	unsigned int	window_width;
	/* the data above are read from the INI file */

} T_W32_SCREEN_DEVICE;

typedef struct 
{	
	unsigned char r;
	unsigned char g;
	unsigned char b;
} color;


/* it must be identical to what was defined in MODIS_UI.h */
typedef struct {
	unsigned int	layer_enable;
	unsigned int	frame_buffer_address;

	int				text_clip_left;
	int				text_clip_top;
	int				text_clip_right;
	int				text_clip_bottom;

	int				gfx_clip_left;
	int				gfx_clip_top;
	int				gfx_clip_right;
	int				gfx_clip_bottom;

	int				active_layer;

	unsigned short	layer_x_offset;
	unsigned short	layer_y_offset;
	unsigned short	layer_width;
	unsigned short	layer_height;

	unsigned short	roi_x_offset;
	unsigned short	roi_y_offset;
	unsigned short	roi_width;
	unsigned short	roi_height;

	unsigned char	source_key_enable;
	unsigned char	opacity_enable;
	unsigned short	source_key;
	unsigned char	opacity_value;
} MODIS_UI_layer_info_struct;

typedef struct
{
	int	key_bitmap_id;
	int sw_drv_key_code;
	unsigned int	pc_key_code;
} key_mapping_struct;

#ifndef DEVICE_KEY_SLIDER
#define DEVICE_KEY_SLIDER 108
#endif

#define MAX_KEY_SUPPORT 127
#define DRV_KEY_DOWN 0
#define DRV_KEY_UP   1

#define SIMULATOR_LAYER_COUNT (4)

#define VIBRATE_PIXEL (7)

/********************************************************
	Extern functions
*********************************************************/

extern void w32_key_detect_ind(unsigned char key_status, unsigned char key_code);
extern void w32_update_screen(void);
extern void w32_lcd_update_sub(void);

/*Slide phone related*/
extern void slider_switch_set_gpio(BOOL bOn);

/*Modis UI dll export functions*/
extern __declspec(dllimport)
void	MoDisUISetLayerData(
	MODIS_UI_layer_info_struct	**layer,
	int								lcd_width,
	int								lcd_height,
	int								layer_count,
	unsigned char					*new_app_flag,
	int	*						pSleep
);
extern __declspec(dllimport)
void MoDISCallTimer(BOOL flag);
extern __declspec(dllimport)
void CloseCalledbyCore(void);
extern __declspec(dllimport)
void EnlargeDataInt(BYTE *pInBuff,int wWidth,int wHeight,BYTE *pOutBuff,int wNewWidth,int wNewHeight);
extern __declspec(dllimport)
void ShrinkDataInt(BYTE *pInBuff,int wWidth,int wHeight,BYTE *pOutBuff,int wNewWidth,int wNewHeight);			
extern __declspec(dllimport)
int MTKLoadImage(HDC* hdcImage, LPCSTR pszImage, SIZE* sz);	

/*Back light level*/
extern kal_uint32 custom_uem_get_bl_level_num(void);

/*MMI touch screen*/
#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_pen_MODIS_enqueue_down(kal_int16 x, kal_int16 y);
extern void mmi_pen_MODIS_enqueue_move(kal_int16 x, kal_int16 y);
extern void mmi_pen_MODIS_enqueue_up(kal_int16 x, kal_int16 y);
#endif


/*Internal funtions*/
void LCD_Init_MODIS(kal_uint32 bkground, void **buf_addr);
void LCDrBlockWrite(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2);
void w32_put_screen(unsigned char lcd_id, int x, int y, int w, int h, unsigned char *bmp);


#endif
