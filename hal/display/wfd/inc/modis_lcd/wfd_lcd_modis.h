/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010-2011
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
 *    wfd_lcd_6276.h
 *
 * Project:
 * --------
 *    MAUI/HAL/WFD
 *
 * Description:
 * ------------
 *    This file is the body of MT6276 LCD HW driver.
 *
 * Author:
 * -------
 * -------
 *    
 *============================================================================
 * HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * $Log$
 *
 * 04 17 2012 dong.guo
 * removed!
 * .
 *
 * 11 10 2011 dong.guo
 * removed!
 * cut modis off from lcd_if.h, define new structures in wfd_lcd_modis.h..
 *
 * 07 26 2011 zifeng.qiu
 * removed!
 *   DDv2 On Modis Check In.
 *
 * 05 18 2011 zifeng.qiu
 * removed!
 * Event Group Slim.
 *
 * 04 21 2011 bin.han
 * removed!
 * .
 *
 * 03 30 2011 sixian.wang
 * removed!
 * .
 *
 * 03 14 2011 ct.fang
 * removed!
 * .
 *
 * 03 11 2011 sophie.chen
 * removed!
 * .
 *
 * 03 08 2011 bin.han
 * removed!
 * .
 *
 * 03 07 2011 chelun.tsai
 * removed!
 * wfd header move to hal
 *
 * 03 07 2011 chelun.tsai
 * removed!
 * CALLBACK_MAX_COUNT = 2.
 *
 * 03 07 2011 chelun.tsai
 * removed!
 * remove LCD_FLATTEN_SUPPORT.
 *
 * 02 10 2011 chelun.tsai
 * removed!
 * modify drv_features.h include.
 *
 * 01 07 2011 sophie.chen
 * removed!
 * .
 *
 * 12 22 2010 sophie.chen
 * removed!
 * .
 *
 * 11 23 2010 sophie.chen
 * removed!
 * .
 *
 * 11 18 2010 sophie.chen
 * removed!
 * .
 *
 * 11 15 2010 sophie.chen
 * removed!
 * .
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __WFD_LCD_MODIS_H__
#define __WFD_LCD_MODIS_H__

#if !defined(__MTK_TARGET__)
/*****************************************************************************
 *  Local macro definitions
 ****************************************************************************/

/*****************************************************************************
 *  Include directives
 ****************************************************************************/
#include "kal_release.h"
#include "drv_comm.h"
#include "drv_features_display.h"
#include "drv_sw_features_display.h"
#include "wfd\inc\wfd.h"
#include "wfd\inc\wfd_hwdevice.h"

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 *  Local type definitions
 ****************************************************************************/
typedef enum
{
   WFD_LCD_HW_EVENT_DATA_TRANSFER_COMPLETE_MTK     =   0x00000001,
   WFD_LCD_HW_EVENT_REG_LATCH_COMPLETE_MTK         =   0x00000002,
   WFD_LCD_HW_EVENT_COMMAND_TRANSFER_COMPLETE_MTK  =   0x00000004,
   WFD_LCD_HW_EVENT_HW_TRIGGER_RECIEVE_MTK         =   0x00000008,
   WFD_LCD_HW_EVENT_VSYNC_MTK                      =   0x00000010,
   WFD_LCD_HW_EVENT_TE_SIGNAL_RECEIVED_MTK         =   0x00000020,
   WFD_LCD_HW_EVENT_UNKNOWN                        =   0x00004000,
   WFD_LCD_HW_EVENT_HW_ENGIN_ALL                   =   0x0000FFFF
}  WFD_LCD_HW_EVENT_ENUM;

typedef enum
{
  WFD_LCD_LAYER_FORMAT_8BPP_INDEX = 0,
  WFD_LCD_LAYER_FORMAT_RGB565,
  WFD_LCD_LAYER_FORMAT_UYVY422,
  WFD_LCD_LAYER_FORMAT_RGB888,
  WFD_LCD_LAYER_FORMAT_ARGB8888,
  WFD_LCD_LAYER_FORMAT_PARGB8888,
  WFD_LCD_LAYER_FORMAT_ARGB6666,
  WFD_LCD_LAYER_FORMAT_PARGB6666,
  WFD_LCD_LAYER_FORMAT_RSD
} WFD_LCD_LAYER_SOURCE_COLOR_FORMAT_ENUM;


typedef enum
{
  WFD_LCD_WMEM_COLOR_RGB565 = 0, /*!< Write to memory with RGB565 color format */  
  WFD_LCD_WMEM_COLOR_RGB888 = 1, /*!< Write to memory with RGB888 color format */
  WFD_LCD_WMEM_COLOR_ARGB8888_CONSTANT_ALPHA = 2, /*!< Write to memory with ARGB8888 color format with constant alpha value */
  WFD_LCD_WMEM_COLOR_ARGB8888_PIXEL_ALPHA = 3, /*!< Write to memory with ARGB8888 color format with per-pixel alpha value*/  
  WFD_LCD_WMEM_COLOR_ARGB6666_CONSTANT_ALPHA = 4, /*!< Write to memory with ARGB6666 color format with constant alpha value */
  WFD_LCD_WMEM_COLOR_ARGB6666_PIXEL_ALPHA = 5, /*!< Write to memory with ARGB6666 color format with per-pixel alpha value*/ 
  WFD_LCD_WMEM_COLOR_RSVD = 6  /*!<Reserved */
} WFD_LCD_WMEM_COLOR_FORMAT_ENUM;

typedef enum
{
   WFD_LCD_LAYER_ROTATE_NORMAL = 0,
   WFD_LCD_LAYER_ROTATE_90,
   WFD_LCD_LAYER_ROTATE_180,
   WFD_LCD_LAYER_ROTATE_270,
   WFD_LCD_LAYER_FLIP,
   WFD_LCD_LAYER_FLIP_ROTATE_90,
   WFD_LCD_LAYER_FLIP_ROTATE_180,
   WFD_LCD_LAYER_FLIP_ROTATE_270,
   WFD_LCD_LAYER_RSVD
}  WFD_LCD_LAYER_ROTATE_ENUM;

//Dong: move structure in lcd_if.h here
typedef struct
{
   kal_bool    layer_update_queue;     /* lcd layer parameter queue is full or not */
   kal_bool    source_key_enable;      /* enable/disable source key for specified layer */
   kal_bool    color_palette_enable;   /* enable/disable color palette for specified layer */
   kal_bool    opacity_enable;         /* enable/disable opacity for specified layer */

   //LCD_LAYER_SOURCE_COLOR_FORMAT_ENUM
   kal_uint8   source_color_format;    /* color format of the specified layer, for MT6228 and MT6229 only */

   kal_uint8   color_palette_select;   /* selection of color palette table */
   kal_uint8   opacity_value;          /* opacity value for specified layer */

   //LCD_LAYER_ROTATE_ENUM
   kal_uint8   rotate_value;           /* rotate select for specified layer */
   kal_uint16  x_offset;               /* x axis offset from main window for specified layer */
   kal_uint16  y_offset;               /* y axis offset from main widnow for specified layer */
   kal_uint16  row_number;             /* layer buffer height of specified layer */
   kal_uint16  column_number;          /* layer buffer width of specified layer */
   kal_uint32  source_key;             /* source key color in RGB565 format for specified layer */
   kal_uint32  frame_buffer_address;   /* frame buffer start address of specified layer */

   // For MT6236
   kal_bool    dst_key_enable;      /* enable/disable source key for specified layer */
   kal_bool    lgamma_enable;      /* enable/disable source key for specified layer */
   kal_bool    dither_enable;      /* enable/disable source key for specified layer */
   kal_uint16  mem_x_offset;               /* x axis offset from mem space window for specified layer */
   kal_uint16  mem_y_offset;               /* y axis offset from mem space window for specified layer */
   kal_uint16  mem_pitch;               /* pitch of mem space window for specified layer */
} lcd_layer_struct_modis;


typedef struct
{
   /// module ID that request frame buffer update
   /// LCD_UPDATE_MODULE_MMI, LCD_UPDATE_MODULE_MEDIA, LCD_UPDAET_MODULE_EXT_CAMERA, LCD_UPDATE_MODULE_JPEG_VIDEO
   kal_uint8 module_id;
   /// which lcd will be updated (MAIN_LCD or SUB_LCD)
   kal_uint8 lcd_id;
   /// block caller or not
   kal_bool block_mode_flag;
   /// callback when lcd update is done
   void (* lcd_block_mode_cb)(void);
   //// frame buffer update mode (SW_TRIGGER, HW_TRIGGER or DIRECT_COUPLE)
   kal_uint8 fb_update_mode;
   /// the starting x coordinate of LCM to be updated
   kal_uint16 lcm_start_x;
   /// the starting y coordinate of LCM to be updated
   kal_uint16 lcm_start_y;
   /// the ending x coordinate of LCM to be updated
   kal_uint16 lcm_end_x;
   /// the ending y coordinate of LCM to be updated
   kal_uint16 lcm_end_y;
   /// the ROI window offset x from main window
   kal_uint16 roi_offset_x;
   /// the ROI window offset y from main window
   kal_uint16 roi_offset_y;
   /// the layers to be updated
   kal_uint32 update_layer;
   /// which layer will be applied by hw trigger or direct couple
   kal_uint32 hw_update_layer;
   /// rotate select for hardware update layer
   kal_uint8 rotate_value;

#if defined(DRV_LCD_ROI_BACKGROUND_COLOR)
   /// background color of ROI
   kal_uint32  roi_background_color;
#endif

#if defined(DRV_LCD_MEMORY_OUTPUT)
   /// enable/disable otuput to memory and LCM simultaneously
   kal_bool    memory_output;
   /// block write out or not
   kal_uint8   block_mode;
   /// output data format to memory, LCD_WMEM_RGB565 or LCD_WMEM_RGB888 for 6228, 6229.
   /// always RGB565 for 6226,6227
   kal_uint8   memory_data_format;
   /// memory block when output to memory
   kal_uint16  memory_block_width;
   /// buffer address of memory output buffer
   kal_uint32  memory_output_buffer_address;
   /// buffer size of memory output buffer
   kal_uint32  memory_output_buffer_size;
   /// x offset of dest buffer
   kal_uint16  dest_offset_x;
   /// y offset of dest buffer
   kal_uint16  dest_offset_y;
   /// temp memory buffer
   kal_uint32  dest_temp_address;
#endif //DRV_LCD_MEMORY_OUTPUT
}  lcd_frame_update_struct_modis;

/*****************************************************************************
 *  Local Definitions
 ****************************************************************************/

/*!
 *  MT6236 LCD has 1 port for each LCM connected, and
 *  1 port for memory output.
 *  Each port has only one port mode in current implementation.
 *  MT6236 LCD has four pipelines since MT6236 LCD HW has only
 *  four layers.
 */
#ifdef DUAL_LCD
#define ATTACHED_LCM_CNT 2
#else
#define ATTACHED_LCM_CNT 1
#endif

/*!
 *  LCD_FLATTEN_SUPPORT: indicate if LCD driver support flatten or not.
 */ 
#define LCD_FLATTEN_SUPPORT
//DRV_LCD_MEMORY_OUTPUT
/*!
 *  WFD_ATTACHED_PORT_COUNT: indicate how many ports attached on LCD.
 */
#if defined(LCD_FLATTEN_SUPPORT)
#define WFD_ATTACHED_PORT_COUNT (ATTACHED_LCM_CNT + 1)
#else
#define WFD_ATTACHED_PORT_COUNT (ATTACHED_LCM_CNT)
#endif


/*!
 *  LCD ROI related definitions
 */
#define  WFD_LCD_ROI_MAX_WIDTH                   0x7FF
#define  WFD_LCD_ROI_MAX_HEIGHT                  0x7FF
#define  WFD_LCD_ROI_MAX_OFFSETX                 0x7FF
#define  WFD_LCD_ROI_MAX_OFFSETY                 0x7FF
#define  WFD_LCD_ROI_ORIGIN_X                    1024
#define  WFD_LCD_ROI_ORIGIN_Y                    1024

/*!
 *  LCD Layer related definitions
 */
#define  WFD_LCD_LAYER_MAX_WIDTH                 0x7FF
#define  WFD_LCD_LAYER_MAX_HEIGHT                0x7FF
#define  WFD_LCD_LAYER_MAX_OFFSETX               0x7FF
#define  WFD_LCD_LAYER_MAX_OFFSETY               0x7FF
#define  WFD_LCD_LAYER_MAX_ALPHA                 0xFF
#define  WFD_LCD_LAYER_MEM_MAX_OFFSETX           0x7FF
#define  WFD_LCD_LAYER_MEM_MAX_OFFSETY           0x7FF
#define  WFD_LCD_LAYER_MEM_MAX_PITCH             0x7FF

/*!
 *  LCD Flatten related definitions
 */
#define  WFD_LCD_MEM_OUT_MAX_MAIN_WINDOW_WIDTH   0x7FF
#define  WFD_LCD_MEM_OUT_MAX_MAIN_WINDOW_HEIGHT  0x7FF
#define  WFD_LCD_MEM_OUT_MAX_OFFSETX             0x7FF
#define  WFD_LCD_MEM_OUT_MAX_OFFSETY             0x7FF


//#define WFD_LCD_PARALLEL_INTERFACE_COUNT  3 //the definition shall be in drv_feature due to the reference by IFManager
//#define WFD_LCD_SERIAL_INTERFACE_COUNT  1
#define WFD_LCD_PALETTE_COUNT	0
#define WFD_LCD_CMD_QUEUE_COUNT 2
#define WFD_LCD_CMD_QUEUE_NUMBER 32

//#define WFD_LCD_BYTE_ALIGN_COUNT 4


/*!
 *  WFD LCD DRIVER RELATED DEFINITIONS
 */
#define CALLBACK_ENTRY_SIZE 4
#define CALLBACK_MAX_COUNT  2

//unit:10ms
#define WFD_LCD_TIMEOUT_INTERVAL 500
/*****************************************************************************
 *  Local variables
 ****************************************************************************/

/*****************************************************************************
 *  Local function definitions
 ****************************************************************************/ 
//Supported Event
#define IS_LCD_SUPPORTED_EVENT(event)(((event) == WFD_EVENT_VSYNC_MTK) || \
                                      ((event) == WFD_EVENT_TE_SIGNAL_RECEIVED_MTK) || \
                                      ((event) == WFD_EVENT_COMMAND_TRANSFER_COMPLETE_MTK) || \
                                      ((event) == WFD_EVENT_DATA_TRANSFER_COMPLETE_MTK))

#define CONVERT_TO_LCD_HW_BK_COLOR(A,R,G,B) ((((A)&0xFF)<<24)|(((R)&0xFF)<<16)|(((G)&0xFF)<<8)|(((B)&0xFF)))

#define ENABLE_LCD_SERIAL_IF_CS(csNum, enable)



/**
 *  \def WFD_LCD_DBG_SUPPORT
 *  \remark In order to enhance SW performance, disable WFD debug logging when 
 *          official release, which means it will be more difficult for driver 
 *          owner to debug based on memory dump.
 */
//#undef WFD_LCD_DBG_SUPPORT
//#define WFD_LCD_DBG_SUPPORT
//#define LCD_V1_ADP_DBG_SUPPORT

/*****************************************************************************
 *  API function definitions
 ****************************************************************************/
//extern WFDErrorCode wfd_lcd_6236_initialize(
//    WFDHWDevicePrimitivesMTK **pDevicePrimitives);



////////////////////


#ifdef __cplusplus
}
#endif

#endif  // #if !defined(__MTK_TARGET__)

#endif  // #ifndef __WFD_LCD_MODIS_H__

