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
 *    wfd_lcd_6236.c
 *
 * Project:
 * --------
 *    MAUI/HAL/WFD
 *
 * Description:
 * ------------
 *    This file is the body of MT6236 LCD HW driver.
 *    This file is only for target.
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
 * 12 27 2012 joey.pan
 * removed!
 * Fix sub_lcd cannot sleep in issue.
 *
 * 05 31 2012 dong.guo
 * removed!
 * .
 *
 * 04 17 2012 dong.guo
 * removed!
 * .
 *
 * 02 10 2012 haitao.shang
 * removed!
 * .
 *
 * 11 10 2011 dong.guo
 * removed!
 * cut modis off from lcd_if.h, define new structures in wfd_lcd_modis.h..
 *
 * 09 23 2011 dong.guo
 * removed!
 * Exclude Lcd_profiling.h and its reference .
 *
 * 07 26 2011 zifeng.qiu
 * removed!
 *   DDv2 On Modis Check In.
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if !defined(__MTK_TARGET__)

/*****************************************************************************
 *  Local macro definitions
 ****************************************************************************/

/*****************************************************************************
 *  Include directives
 ****************************************************************************/
#include <memory.h>
#include "common\display_io.h"
#include "kal_public_api.h"

#include "drv_comm.h"
#include "drv_hisr.h"
#include "wfd\inc\wfd_hwdevice.h"
#include "wfd\inc\wfd.h"
#include "wfd\inc\wfdplatform.h"
#include "mm_power_ctrl.h"
#include "kal_release.h"
#include "lcd_if_hw.h"
//#include "lcd_if.h"
#include "lcd_sw.h"
#include "lcd_sw_inc.h"
#include "common/owftypes.h"
#include "common/owfimage.h"
#include "wfd\inc\wfd_lcd_internal.h"
#include "lcd_tear_manager\inc\lcd_tear_manager.h"
#include "wfd\inc\wfd_common.h"
#include "lcd_power_mgr.h"
#include "lcd_if_manager.h"
#include "l1_interface.h"

#include "drv_features_display.h"
#include "drv_sw_features_display.h"
#include "lcm_if.h"

#include "wfd\inc\modis_lcd\wfd_lcd_modis.h"
#include "lcd_c_model\inc\lcd_c_model.h"

#include "lcd_exception_api.h"

#ifdef __cplusplus
extern "C" {
#endif

kal_bool lcd_physical_interface_is_busy = KAL_FALSE;

/*****************************************************************************
 *  Local variables
 ****************************************************************************/
WFD_PORT _wfd_lcd_port[WFD_ATTACHED_PORT_COUNT] = {0};
WFD_PIPELINE _wfd_lcd_pipeline[DRV_LAYER_TOTAL_COUNT] = {0};
extern WFD_DEVICE _wfd_lcd_device;

static WFD_PORT* _wfd_current_processing_port = NULL;
//static DCL_HANDLE _wfd_lcd_timer = NULL;

WFDuint wfd_lcd_power_ctrl_handle = 0xFFFFFFFF;

static WFDLCDInterfacePara _wfd_lcd_if_para[WFD_ATTACHED_PORT_COUNT];

#if defined(DRV_DISPLAY_DRIVER_V2)

//Simulator Modis HW Registers
static lcd_layer_config_t modis_layer_config[DRV_LAYER_TOTAL_COUNT] = {0};
static lcd_roi_config_t modis_roi_config = {0};
static kal_uint32 modis_main_lcm_gram[LCD_WIDTH * LCD_HEIGHT] = {0};
#ifdef DUAL_LCD
static kal_uint32 modis_sub_lcm_gram[SUBLCD_WIDTH * SUBLCD_HEIGHT] = {0};
#endif
#ifdef DUAL_LCD
static kal_uint32 *modis_lcm_gram[ATTACHED_LCM_CNT] = {modis_main_lcm_gram, modis_sub_lcm_gram};
#else
static kal_uint32 *modis_lcm_gram[ATTACHED_LCM_CNT] = {modis_main_lcm_gram};
#endif
//For w32_lcd_update
lcd_layer_struct_modis modis_lcd_layer_data[ATTACHED_LCM_CNT][DRV_LAYER_TOTAL_COUNT];
lcd_layer_struct_modis *modis_current_lcd_layer_data = NULL;
kal_uint8 modis_lcd_update_w2m_tempbuffer[LCD_WIDTH * LCD_HEIGHT * 4] = {0};

kal_bool modis_lcd_debug = KAL_FALSE;
char g_lcd_debug_path[256];
char g_lcd_debug_file[256];
void dump(void* pBuffer, kal_uint32 width, kal_uint32 height, kal_uint32 bpp, kal_uint8* file);

//Dong: for convert to rgb565, for info monitor
unsigned char _rgb565_buffer_mainlcd[DRV_LAYER_TOTAL_COUNT][WFD_LCD_LAYER_MAX_WIDTH*WFD_LCD_LAYER_MAX_HEIGHT*2]={0};
unsigned char _rgb565_buffer_sublcd[DRV_LAYER_TOTAL_COUNT][WFD_LCD_LAYER_MAX_WIDTH*WFD_LCD_LAYER_MAX_HEIGHT*2]={0};


/*****************************************************************************
 *  Internal used macros
 ****************************************************************************/
#define CHECK_DEVICE(d, errorcode, retval)
#define CHECK_DEVICE_NR(d, errorcode)


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
#else
#define CHECK_HANDLE(d, h, errorcode, retval)
#define CHECK_HANDLE_NR(d, h, errorcode)
#define CHECK_CONDITION(d, c, errorcode, retval) 
#define CHECK_CONDITION_NR(d, c, errorcode)
#endif

#define DPRINT(x) 


/*****************************************************************************
 *  Local function definitions
 ****************************************************************************/
// TODO: [m] check why this option WFD_LCD_DBG_SUPPORT is not defined/undefined in MT6235 driver header: wfd_lcd_6235.h 
#if defined(WFD_LCD_DBG_SUPPORT)
/**
 *  \def WFD_LCD_DBG_ENTRY_CNT
 *  This number must be 2^N
 */
//#define WFD_LCD_DBG_ENTRY_CNT (64)
#define WFD_LCD_DBG_ENTRY_CNT (16)  ///Bin:reduce to 16

// Chelun : move to wfd_lcd_internal.h
//typedef enum
//{
//  WFDLCD__...
//  
//}WFDLCDDbgIdEnum;

typedef struct
{
  WFDLCDDbgIdEnum id;
  WFDErrorCode    error;
  WFDuint         intStatus;

#if defined(DRV_LCD_MT6268_SERIES)
  WFDuint         dcReg;
#endif  // #if defined(DRV_LCD_MT6268_SERIES)

#if defined(LCD_DEBUG_POWER_CONTROL_AND_WHITE_SCREEN)
  WFDuint         ifReg;
  WFDuint         teReg;
  WFDuint         roiCtrl;
  WFDuint         roiSz;
  WFDuint         HWref;
#endif  // #if defined(LCD_DEBUG_POWER_CONTROL_AND_WHITE_SCREEN)

  WFDuint         time;
} WFDLCDDbgCtrlBlk;


static WFDuint _wfdLcdDbgCnt = 0;
static WFDLCDDbgCtrlBlk _wfdLcdDbgDat[WFD_LCD_DBG_ENTRY_CNT] = {0};
void __wfd_lcd_trace(WFDLCDDbgIdEnum id)
{
  kal_uint32 index;

  if (KAL_TRUE == INT_QueryExceptionStatus())
  {
    index = _wfdLcdDbgCnt;
    _wfdLcdDbgCnt++;
    _wfdLcdDbgCnt &= (WFD_LCD_DBG_ENTRY_CNT-1);
  }
  else
  {
    kal_uint32 mask = SaveAndSetIRQMask();
    index = _wfdLcdDbgCnt;
    _wfdLcdDbgCnt++;
    _wfdLcdDbgCnt &= (WFD_LCD_DBG_ENTRY_CNT-1);
    RestoreIRQMask(mask);
  }

  _wfdLcdDbgDat[index].id = id;
  _wfdLcdDbgDat[index].error = _wfd_lcd_device.lastUnreadError;
  _wfdLcdDbgDat[index].time = drv_get_current_time();
	
}
#else   // #if defined(WFD_LCD_DBG_SUPPORT)
#define __wfd_lcd_trace(i)
#endif  // #if defined(WFD_LCD_DBG_SUPPORT)

/**
 *  \def WFD_CATCHLOG_TEAR_DBGMSG_SUPPORT
 *  If this is defined, WFD uses MOD_MED to log traces for tearing information.
 */
//#define WFD_CATCHLOG_TEAR_DBGMSG_SUPPORT
//extern kal_uint32 DEBUG__HSYNC_COUNT;
//extern kal_uint32 DEBUG__LCM_STARTY;

#if defined(WFD_CATCHLOG_TEAR_DBGMSG_SUPPORT)
//Profiling
static WFDuint _wfd_port_start_busy_timestamp = 0;
static WFDuint _wfd_port_update_duration = 0;
#define pf_entry (32)
typedef struct
{
  kal_uint32 en_layer;
  kal_uint32 w;
  kal_uint32 h;
  kal_uint32 t;
  kal_uint32 layer_ctrl[4];
  kal_uint32 nli_arb_cs;
  kal_uint32 ultra_ctrl;
  kal_uint32 hsync;
  kal_uint32 lcmSY; //startY
} performance;
static performance pf[pf_entry];
static kal_uint32 pf_idx = 0;

// TODO: [o] modify this to use function instead if needed 
// TODO: [m] Use drv trace but use MOD_MED
#define WFD_CATCHLOG(msg) kal_prompt_trace(MOD_MED, msg)
#define WFD_CATCHLOG_PROFILE_START()\
{\
  kal_uint32 index;\
  if (KAL_TRUE == INT_QueryExceptionStatus())\
  {\
    index = pf_idx;\
  }\
  else\
  {\
  kal_uint32 mask = SaveAndSetIRQMask();\
  index = pf_idx;\
  RestoreIRQMask(mask);\
  }\
  pf[index].w = (REG_LCD_ROI_SIZE) & 0xFFFF;\
  pf[index].h = ((REG_LCD_ROI_SIZE) >> 16) & 0xFFFF;\
  pf[index].en_layer = (((REG_LCD_ROI_CTRL) >> 28) & 0xF);\
  pf[index].layer_ctrl[0] = REG_LCD_LAYER0_CTRL;\
  pf[index].layer_ctrl[1] = REG_LCD_LAYER1_CTRL;\
  _wfd_port_start_busy_timestamp = drv_get_current_time();\
}
//  pf[index].layer_ctrl[2] = REG_LCD_LAYER2_CTRL;\
//  pf[index].layer_ctrl[3] = REG_LCD_LAYER3_CTRL;\
//  pf[index].nli_arb_cs = REG_NLI_ARB_CS;\
//  pf[index].ultra_ctrl = REG_LCD_ULTRA_CON;\
//  pf[index].hsync = DEBUG__HSYNC_COUNT;\
//  pf[index].lcmSY = DEBUG__LCM_STARTY;\
//  kal_prompt_trace(MOD_MED, "[LCD] Start update.\n");\

#define WFD_CATCHLOG_PROFILE_END() \
{\
  kal_uint32 index;\
  if (KAL_TRUE == INT_QueryExceptionStatus())\
  {\
    index = pf_idx;\
    pf_idx = (++pf_idx) & (pf_entry-1);\
  }\
  else\
  {\
  kal_uint32 mask = SaveAndSetIRQMask();\
  index = pf_idx;\
  pf_idx = (++pf_idx) & (pf_entry-1);\
  RestoreIRQMask(mask);\
  }\
  _wfd_port_update_duration = drv_get_duration_ms(_wfd_port_start_busy_timestamp);\
  pf[index].t = _wfd_port_update_duration;\
}
//  kal_prompt_trace(MOD_MED, "[LCD] End update. Busy Interval: %d\n", _wfd_port_update_duration);\

#else   // #if defined(WFD_CATCHLOG_TEAR_DBGMSG_SUPPORT)
#define WFD_CATCHLOG(msg)
#define WFD_CATCHLOG_PROFILE_START()
#define WFD_CATCHLOG_PROFILE_END()
#endif  // #if defined(WFD_CATCHLOG_TEAR_DBGMSG_SUPPORT)


//Dong: for modis info monitor, we will convert 6666 to 565, so win32 display can show layer data normally
kal_uint32 __wfd_lcd_SrcBufCnvtToRgb565_Ex(OWF_IMAGE* image_source, kal_uint32 screen_id, kal_uint32 layer_index)	
			{  
			  
			  unsigned char* pByte;
			  unsigned char* pBuffer;
			  unsigned char a,r,g,b;
			  unsigned int i,j;
			  kal_uint32 src_height = image_source->height;
			  kal_uint32 src_width = image_source->width;
			  kal_uint32 src_colorformat = image_source->format.pixelFormat;
				  
			  switch(src_colorformat)
		  	{
			  		case OWF_IMAGE_ARGB6666:
		  			{
							  unsigned char* src6666;
							  unsigned char src6666_value;		  
							  src6666 = (unsigned char*) image_source->data;
							  if(0 == screen_id)			  
							    pBuffer = _rgb565_buffer_mainlcd[layer_index];
							  else if(1 == screen_id)
							  	pBuffer = _rgb565_buffer_sublcd[layer_index];
							  else
							  	return (kal_uint32)image_source->data;
							  pByte = pBuffer;
							  	
								  //buffer data convert
								  for (i=0; i< src_height*src_width; i++)
								  {
								  	  j = i*3;
									  src6666_value = src6666[j];
									  b = (src6666_value)&0x3f;
									  g = ((src6666_value)>>6)&0x3;
									  src6666_value = src6666[j+1];
									  g |= (src6666_value&0xf)<<2;
									  r = ((src6666_value)>>4)&0xf;
									  src6666_value = src6666[j+2];
									  r |= (src6666_value&0x3)<<4;
									  a = (src6666_value>>2)&0x3f;					  
								  
									  *(pByte) = (b>>1)&0x1F;	 
									  *(pByte++) |= (g<<5);
									  *(pByte) = (g>>3)&0x7;
									  *(pByte++) |= ((r<<2)&0xF8);
								  }
								  
								 break;		   
					   }
					case OWF_IMAGE_ARGB8888:
		  			{
							  unsigned int* src8888;
							  unsigned int src8888_value;		  
							  src8888 = (unsigned int*) image_source->data;
							  if(0 == screen_id)			  
							    pBuffer = _rgb565_buffer_mainlcd[layer_index];
							  else if(1 == screen_id)
							  	pBuffer = _rgb565_buffer_sublcd[layer_index];
							  else
							  	return (kal_uint32)image_source->data;
							  pByte = pBuffer;
							  	
								  //buffer data convert
								  for (i=0; i< src_height*src_width; i++)
								  {
								  	  src8888_value = src8888[i];
									  b = (src8888_value)&0xFF;
									  g = ((src8888_value)>>8)&0xFF;
									  r = ((src8888_value)>>16)&0xFF;
									  a = ((src8888_value)>>24)&0xFF;
									 					  
								  
                                      *(pByte) = 0;
									  *(pByte) = (b>>3)&0x1F;	 
									  *(pByte++) |= ((g>>2)<<5);
									  *(pByte) = 0;
									  *(pByte) = (g>>5)&0x7;
									  *(pByte++) |= (r&0xF8);
								  }
								  
								 break;		   
					   }
					case OWF_IMAGE_RGB888:
		  			{
							  unsigned char* src888;
							  unsigned char src888_value;		  
							  src888 = (unsigned char*) image_source->data;
							  if(0 == screen_id)			  
							    pBuffer = _rgb565_buffer_mainlcd[layer_index];
							  else if(1 == screen_id)
							  	pBuffer = _rgb565_buffer_sublcd[layer_index];
							  else
							  	return (kal_uint32)image_source->data;
							  pByte = pBuffer;
							  	
								  //buffer data convert
								  for (i=0; i< src_height*src_width; i++)
								  {
								  	  j = i*3;
									  b = src888[j];
									  g = src888[j+1];
									  r = src888[j+2];									  					  

									  *(pByte) = 0;
									  *(pByte) = (b>>3)&0x1F;	 
									  *(pByte++) |= ((g>>2)<<5);
									  *(pByte) = 0;
									  *(pByte) = (g>>5)&0x7;
									  *(pByte++) |= (r&0xF8);
								  }
								  
								 break;		   
					   }
						  
				}		
			   return (kal_uint32)pBuffer;
			 }




WFDboolean __wfd_lcd_IsWaitHwVsync_modis(void)
{
// TODO: [m] Check if SUB LCD uses different compile option. This will make SUB LCD fail!
#if defined(__SYNC_LCM_HW_SUPPORT__)
    return ((REG_LCD_TECON & LCD_TE_ENABLE_BIT) && (LCD_WAIT_TE));
#else
    return WFD_FALSE;
#endif
}


/*!
 *  Convert WFD format definition to LCD HW register definition.
 *
 *  \param format           OWF image color format
 *                          Handle to newly created stream, or OWF_INVALID_HANDLE if no
 *                          stream could be created.\n
 *  \notice                 This function may not achieve all chips' LCD requirement.
 *                          If need, please overwrite this function _wfd_lcd_utilities 
 *                          in your wfd_lcd_hook_internal_utility(~).\n
 */
WFDuint
__wfd_lcd_CnvtImgFormatToHwDef_modis(OWF_IMAGE_FORMAT *format)
{
    switch (format->pixelFormat)
    {
        case OWF_IMAGE_L8:      { return WFD_LCD_LAYER_FORMAT_8BPP_INDEX; }

        case OWF_IMAGE_RGB565:  { return WFD_LCD_LAYER_FORMAT_RGB565; }

        case OWF_IMAGE_UYVY:    { return WFD_LCD_LAYER_FORMAT_UYVY422; }

        case OWF_IMAGE_RGB888:  { return WFD_LCD_LAYER_FORMAT_RGB888; }

        case OWF_IMAGE_ARGB8888:
        {
            if (format->premultiplied) { return WFD_LCD_LAYER_FORMAT_PARGB8888; }
            return WFD_LCD_LAYER_FORMAT_ARGB8888;
        }

	case OWF_IMAGE_ARGB6666:
	{
	    if (format->premultiplied) { return WFD_LCD_LAYER_FORMAT_PARGB6666; }
	    return WFD_LCD_LAYER_FORMAT_ARGB6666;
	}

        default:
        { 
            ASSERT(0);
            return WFD_LCD_LAYER_FORMAT_RSD; 
        }
    }

    return WFD_LCD_LAYER_FORMAT_RSD;
}



/*!
 *  Convert Clockwise 0/90/180/270 degree to HW rotation/flip definition value.
 *
 *                          0xFFFFFFFF: means the passed paramrters are wrong\n
 *
 *  \notice                 This function may not achieve all chips' LCD requirement.
 *                          If need, please overwrite this function _wfd_lcd_utilities 
 *                          in your wfd_lcd_hook_internal_utility(~).\n
 */
WFDuint
__wfd_lcd_CnvtAngleToHwDef_modis(WFD_DEVICE* device, WFDint angle, WFDboolean flip)
{
    switch (angle)
    {
        case 0:
        {
            return ((WFD_FALSE == flip) ? WFD_LCD_LAYER_ROTATE_NORMAL: WFD_LCD_LAYER_FLIP);
        }

        case 90:
        {
            return ((WFD_FALSE == flip) ? WFD_LCD_LAYER_ROTATE_270: WFD_LCD_LAYER_FLIP_ROTATE_270);
        }

        case 180:
        {
            return ((WFD_FALSE == flip) ? WFD_LCD_LAYER_ROTATE_180: WFD_LCD_LAYER_FLIP_ROTATE_180);
        }

        case 270:
        {
            return ((WFD_FALSE == flip) ? WFD_LCD_LAYER_ROTATE_90: WFD_LCD_LAYER_FLIP_ROTATE_90);
        }

        default:
        {
            WFD_ASSERT_CHECK(device, 0, WFD_ERROR_ILLEGAL_ARGUMENT, 0xffffff);
            return 0xffffff;
        }
    }

    return WFD_LCD_LAYER_ROTATE_NORMAL;
}



/*!
 *  Convert WFD format definition to LCD HW register definition.
 *
 *                          WFD_LCD_HW_EVENT_UNKNOWN means the input event_type is wrong.
 *
 *  \notice                 This function may not achieve all chips' LCD requirement.
 *                          If need, please overwrite this function _wfd_lcd_utilities 
 *                          in your wfd_lcd_hook_internal_utility(~).\n
 */
WFDuint 
__wfd_lcd_CnvtEventToHWDef_modis(WFDEventType event_type)
{
    switch (event_type)
    {
        case WFD_EVENT_VSYNC_MTK:
        { 
            return WFD_LCD_HW_EVENT_VSYNC_MTK; 
        }

        case WFD_EVENT_TE_SIGNAL_RECEIVED_MTK:
        {
            return WFD_LCD_HW_EVENT_TE_SIGNAL_RECEIVED_MTK;
        }

        case WFD_EVENT_COMMAND_TRANSFER_COMPLETE_MTK:
        {
            return WFD_LCD_HW_EVENT_COMMAND_TRANSFER_COMPLETE_MTK;
        }

        case WFD_EVENT_DATA_TRANSFER_COMPLETE_MTK:
        {
            return WFD_LCD_HW_EVENT_DATA_TRANSFER_COMPLETE_MTK;
        }

        default:
        { 
            //WFD_ASSERT_CHECK(&_wfd_lcd_primitives, 0, WFD_ERROR_ILLEGAL_ARGUMENT, LCD_LAYER_MONO);
            //ASSERT(0);
            return WFD_LCD_HW_EVENT_DATA_TRANSFER_COMPLETE_MTK;
    }
}

    return WFD_LCD_HW_EVENT_UNKNOWN;
}



/*!
 *  Convert WFD Color Format to W2MWM Format HW definition.\n
 *
 *                          WFD_LCD_WMEM_COLOR_RSVD means the input format is wrong.
 *
 *  \notice                 This function may not achieve all chips' LCD requirement.
 *                          If need, please overwrite this function _wfd_lcd_utilities 
 *                          in your wfd_lcd_hook_internal_utility(~).\n
 */
WFDuint
__wfd_lcd_CnvtW2memFormatToHwDef_modis(OWF_IMAGE_FORMAT *format)
{
    switch (format->pixelFormat)
    {
        case OWF_IMAGE_RGB565:  
            return WFD_LCD_WMEM_COLOR_RGB565; 

        case OWF_IMAGE_RGB888:  
            return WFD_LCD_WMEM_COLOR_RGB888; 

        case OWF_IMAGE_ARGB8888:
            if (format->premultiplied) 
                return WFD_LCD_WMEM_COLOR_ARGB8888_PIXEL_ALPHA; 
            else
                return WFD_LCD_WMEM_COLOR_ARGB8888_CONSTANT_ALPHA;
	      case OWF_IMAGE_ARGB6666:
            if (format->premultiplied) 
                return WFD_LCD_WMEM_COLOR_ARGB6666_PIXEL_ALPHA; 
            else
                return WFD_LCD_WMEM_COLOR_ARGB6666_CONSTANT_ALPHA;

        default:
            ASSERT(0);	  	
            return WFD_LCD_WMEM_COLOR_RSVD; 
    }
}


/*!
 *  Get Interface Period value. [LCD Only]
 *
 *  \param Port              Port struct
 *  \return                  Period value\n
 *
 *  \notice                  
 */
WFDuint
__wfd_lcd_GetDevicePeriodVal_modis(WFD_PORT* port)
{
    return 0;
}



/*!
 *  Rollback Port's Interface setting after power on LCD.
 *
 *                           and then powered on, we will continue to turn on LCD clock. At this
 *                           situation, we need to reconfigure all LCD interface related HW registers.
 *                           This function will call LCD Interface Manager to perform the port'interface
 *                           setting. Caller shall make sure to call this function before ask LCD to 
 *                           do any transfer.
 */
WFDboolean
__wfd_lcd_RollbackPortIFSetting_modis(WFDint portId)
{
	
    return WFD_TRUE;
}



/*!
 *  Backup Port's Interface setting after power on LCD.
 *
 *
 *  \notice                  See the notice of function: __wfd_lcd_RollbackPortIFSetting(~) first.
 *                           Due to the need of rollbacking register settings, sometimes we might 
 *                           want to keep curren HW register settings. At such situation, call this
 *                           function to backup the port's interface setting.
 */
static WFDboolean
__wfd_lcd_BackupPortIFSetting_modis(WFDint portId)
{

    return WFD_TRUE;
}


static void
__wfd_device_PowerCtrl_modis(WFD_DEVICE* device, WFDuint handle, WFDboolean enable)
{
   if (enable)
   {
      WFDuint i;
      for (i = 0; i < ATTACHED_LCM_CNT; i++)
      {
        __wfd_lcd_RollbackPortIFSetting_modis(i);
      }
   }
   else
   {
   }
}

/*!
 *  Execute all active event callbacks.
 *
 *  \param pPort             Port structure.\n
 *  \param interruptStatus   The interrupt status\n
 *  \return                  NA\n
 *
 *  \notice                  This fucntion is called in HISR and Blt function now to 
 *                           execute WFC's all registered callback functions.
 */
void
__wfd_lcd_ExecActiveEventsCb_modis(WFD_PORT* pPort, WFDuint interruptStatus)
{
    WFD_PORT_CONFIG* pPortCfg;
    WFD_DEVICE* pDevice = &_wfd_lcd_device;

    pPortCfg = &(pPort->config);
    __wfd_lcd_trace(WFDLCD_____CB__EXEC_ACTIVE_CB);

    if (interruptStatus & WFD_LCD_HW_EVENT_DATA_TRANSFER_COMPLETE_MTK)
    {
        void (*cb_func)(WFDEventType, void*) = (void (*)(WFDEventType, void*)) (pPortCfg->updateDoneCallback[CB_FUNC_PTR]);

        if(cb_func != NULL)
            cb_func(WFD_EVENT_DATA_TRANSFER_COMPLETE_MTK, (void*)pPortCfg->updateDoneCallback[CB_PARA]);

       __wfd_lcd_trace(WFDLCD_____CB_________CMP_EVT);
    }

}


/** DESCRIPTION :
 *    Call this function to wait specific event.\n
 *  @param[in] NA
 *  @return NA
 *  @remark 
 */
WFDboolean
__wfd_lcd_WaitEvent_modis(WFDEventType event_type)
{
    WFDboolean c;
    WFD_DEVICE* pDevice = &_wfd_lcd_device;

    c = IS_LCD_SUPPORTED_EVENT(event_type);
    if (!c)	 ASSERT(0);

    {
        WFD_PORT_CONFIG* pPortCfg;

        pPortCfg = &(_wfd_current_processing_port->config);    

        //Turn off power before reset busyFlag to avoid race condition.
        pDevice->utilityTable._wfd_PowerCtrl(pDevice, wfd_lcd_power_ctrl_handle, WFD_FALSE);
        //Clear BusyFlag before exec callback.
        _wfd_lcd_device.busyFlag = WFD_FALSE;

        __wfd_lcd_ExecActiveEventsCb_modis(_wfd_current_processing_port, WFD_LCD_HW_EVENT_DATA_TRANSFER_COMPLETE_MTK);	
		  
    }

    return WFD_TRUE;
}



/*!
 *  Get desired interrupt mask setting based on active event callbacks.
 *
 *  \param pCfgCached        Port's cached config structure.\n
 *  \return                  NA\n
 *
 *  \notice                  
 *                           
 */
WFDuint
__wfd_lcd_SetInterruptMask_modis(WFD_DEVICE* device, WFD_PORT_CONFIG* pPortCfg)
{
	
    return 0;
}



/** DESCRIPTION :
 *    Initialize LCD's Port Config Structure.\n
 *  @param[in] pPortCfg
 *  @param[in] portID
 *  @param[in] pPortFunc: Can be NULL for GOVL. This field is not uesd for GOVL.
 *  @return NA
 *  @remark 
 */
static void 
__wfd_lcd_InitPortConfig_modis(
   WFD_PORT_CONFIG *pPortCfg, WFDint portID, WFDLCDInterfacePara *ifPara)
{
    WFDuint i;
    //Flatten PortConfig

    //specify each port mode's specific feature here
    pPortCfg->id = portID;

    for (i = 0; i < 4; i++)    { pPortCfg->partialRefreshRectangle[i] = 0; }

    pPortCfg->powerMode = WFD_POWER_MODE_ON;
    pPortCfg->powerModeBackup = WFD_POWER_MODE_ON;
    pPortCfg->syncEnable = WFD_FALSE;
    pPortCfg->syncMode= WFD_SYNC_MODE_NONE_MTK;
    pPortCfg->refreshRate = 30;

    pPortCfg->updateDoneCallback[CB_FUNC_PTR] = NULL;
    if (WFD_FALSE == ifPara->_ifOnScreen)
    {
        pPortCfg->portWidth = WFD_LCD_ROI_MAX_WIDTH;
        pPortCfg->portHeight = WFD_LCD_ROI_MAX_HEIGHT;
        pPortCfg->type = WFD_PORT_TYPE_MEMORY_OUTPUT_MTK;
        pPortCfg->nativeResolution[0] = WFD_LCD_ROI_MAX_WIDTH;
        pPortCfg->nativeResolution[1] = WFD_LCD_ROI_MAX_HEIGHT;
        pPortCfg->ppi = 0;
        return;
    }

    //Blt PortConfig
    {
        WFDuint temp[2] = {0};

		// default value
		pPortCfg->portTearFreeRefreshRate = 30;

        //specify each port mode's specific feature here
        pPortCfg->type = WFD_PORT_TYPE_INTERNAL;
        
        if(portID == WFD_SCREEN_LCD_0)
        {
            #if defined(__LCM_SCANLINE_ROTATION_SUPPORT__) && (defined(__MAIN_LCM_SCANLINE_ROTATION_90__) || defined(__MAIN_LCM_SCANLINE_ROTATION_270__))
                temp[0] = LCD_HEIGHT;
                temp[1] = LCD_WIDTH;
            #else
                temp[0] = LCD_WIDTH;
                temp[1] = LCD_HEIGHT;
            #endif 
        }
#if (2 == ATTACHED_LCM_CNT)
        else  if(portID == WFD_SCREEN_LCD_1) //sub LCD
        {
            #if defined(__LCM_SCANLINE_ROTATION_SUPPORT__) && (defined(__SUB_LCM_SCANLINE_ROTATION_90__) || defined(__SUB_LCM_SCANLINE_ROTATION_270__))
                temp[0] = SUBLCD_HEIGHT;
                temp[1] = SUBLCD_WIDTH;
            #else
                temp[0] = SUBLCD_WIDTH;
                temp[1] = SUBLCD_HEIGHT;
            #endif 
        }
#endif
        
        pPortCfg->nativeResolution[0] = temp[0];
        pPortCfg->nativeResolution[1] = temp[1];

      
        // Query LCM refresh rate
        
        {
            temp[0] = 75;
        }
        pPortCfg->refreshRate = temp[0];

        // Query LCM ppi
        
        {
            temp[0] = 0;
        }
        pPortCfg->ppi = temp[0];

        if(portID == WFD_SCREEN_LCD_0)
        {
            #if defined(__LCM_SCANLINE_ROTATION_SUPPORT__) && (defined(__MAIN_LCM_SCANLINE_ROTATION_90__) || defined(__MAIN_LCM_SCANLINE_ROTATION_270__))
            pPortCfg->portWidth = LCD_HEIGHT;
            pPortCfg->portHeight = LCD_WIDTH;
            #else
            pPortCfg->portWidth = LCD_WIDTH;
            pPortCfg->portHeight = LCD_HEIGHT;
            #endif 
        }
#if (2 == ATTACHED_LCM_CNT)
        else  if(portID == WFD_SCREEN_LCD_1) //sub LCD
        {
            #if defined(__LCM_SCANLINE_ROTATION_SUPPORT__) && (defined(__SUB_LCM_SCANLINE_ROTATION_90__) || defined(__SUB_LCM_SCANLINE_ROTATION_270__))
            pPortCfg->portWidth = SUBLCD_HEIGHT;
            pPortCfg->portHeight = SUBLCD_WIDTH;
            #else
            pPortCfg->portWidth = SUBLCD_WIDTH;
            pPortCfg->portHeight = SUBLCD_HEIGHT;
            #endif 
        }
#endif
    }
}

/** DESCRIPTION :
 *  Initialize Port Structure.\n
 *  @param[in] pPort
 *  @param[in] portID
 *  @param[in] pPortFunc: Can be NULL for GOVL. This field is not uesd for GOVL.
 *  @return NA
 *  @remark 
*/
static void 
__wfd_lcd_InitPort_modis(
    WFD_PORT *pPort, 
    WFDint portID, 
    WFDLCDInterfacePara *ifPara)
{
    pPort->device = &_wfd_lcd_device;
    pPort->screenNumber = portID;
    
    pPort->portOutputFormat = ifPara->_ifOutFormat;
    pPort->portFuncTable = ifPara->_ifFuncTable;
    pPort->portCmdAddr = ifPara->_ifCmdPort;
    pPort->portDataAddr = ifPara->_ifDataPort;	
    pPort->cmdQueueIdx = ifPara->_ifCmdQueueIdx;
}



WFDboolean
__wfd_lcd_PortPowerCtrl_modis(WFD_DEVICE* device, WFD_PORT* port)
{
    if ((NULL == device) || (NULL == port))  { return WFD_FALSE; }

    if (WFD_PORT_TYPE_MEMORY_OUTPUT_MTK == port->config.type)
    {
        return WFD_TRUE;
    }

    if(port->config.powerModeBackup != port->config.powerMode)
    {
        //Handle Power Off LCM
        device->utilityTable._wfd_PowerCtrl(device, wfd_lcd_power_ctrl_handle, WFD_TRUE);

        if (WFD_POWER_MODE_OFF == port->config.powerMode)
        {
            __wfd_lcd_trace(WFDLCD__________LCM_SLEEP__IN);
            
        }
        else
        {
            //Handle Power On LCM
            __wfd_lcd_trace(WFDLCD__________LCM_SLEEP_OUT);
            
        }
        port->config.powerModeBackup = port->config.powerMode;

    }
    return WFD_TRUE;

}


/*!
 *   [LCD Only]
 *
 *  \param 
 *  \return
 *
 *  \notice
 *         
 */
static WFDboolean
__wfd_lcd_ConfigMemOut_modis(WFD_DEVICE* device, WFD_PORT* port)
{
    WFD_PORT_CONFIG* pPortCfg;
    WFD_LCD_WMEM_COLOR_FORMAT_ENUM w2mem_fmt;

    pPortCfg = &(port->config);

    if (WFD_PORT_TYPE_MEMORY_OUTPUT_MTK == pPortCfg->type)
    {
    	
    }
    else
    {
        /// we do not support BLT+FLATTEN here
        ASSERT(0);
    }

    w2mem_fmt = device->utilityTable._wfd_CnvtW2memFormatToHwDef(&pPortCfg->targetImage->format);

    //set W2MEM Ctrl Reg
    {
    	
        modis_roi_config.w2m = KAL_TRUE;
        modis_roi_config.w2lcm = KAL_FALSE;


        modis_roi_config.w2m_fmt = w2mem_fmt;
        
        modis_roi_config.alpha = (pPortCfg->targetImage->alpha);

        modis_roi_config.pitch = ((pPortCfg->targetImage->stride) / (pPortCfg->targetImage->pixelSize));
    }


    modis_roi_config.w2m_ofs.x = pPortCfg->partialRefreshRectangle[RECT_OFFSETX];
    modis_roi_config.w2m_ofs.y = pPortCfg->partialRefreshRectangle[RECT_OFFSETY];

    modis_roi_config.w2m_add = ((kal_uint8 *)pPortCfg->targetImage->data);
    
    return WFD_TRUE;
}


static void
__wfd_lcd_ConfigPerformancePara_modis(WFD_PORT* port, LCD_IOCTRL_DEVICE_IF_T* if_mgr_setting)
{

}


/*!
 *   Handle Blt to LCM/Memory/both. [LCD Only]
 *
 *  \param 
 *  \return
 *
 *  \notice
 *         
 */
 
static WFDboolean
__wfd_lcd_Blt_modis(WFD_DEVICE* device, WFD_PORT* port, WFDEventType event)
{
    WFD_PORT_CONFIG* pPortCfg;
    WFDint port_index = port->config.id;
    WFDboolean status = WFD_TRUE;
    WFDboolean result = WFD_TRUE;
    WFDuint i;

    kal_uint32 *modis_current_lcm_gram = NULL;

    if ((NULL == device) || (NULL == port))
    {
        result = WFD_FALSE;
        goto exit;
    }

    pPortCfg = &(port->config);

    //Config HW registers for blt.
    {
        WFDuint period = 0;
        WFDuint roi_background = 0;

        // Configure HW registers... 
        device->utilityTable._wfd_PowerCtrl(device, wfd_lcd_power_ctrl_handle, WFD_TRUE);

        period = __wfd_lcd_GetDevicePeriodVal_modis(port);


        modis_roi_config.out_fmt = (port->portOutputFormat);
        
        if (WFD_PORT_TYPE_MEMORY_OUTPUT_MTK == pPortCfg->type)
        {
            modis_roi_config.w2m = KAL_TRUE;
            modis_roi_config.w2lcm = KAL_FALSE;
        }
        else if (WFD_PORT_TYPE_INTERNAL == pPortCfg->type)
        {
        	modis_current_lcm_gram = modis_lcm_gram[pPortCfg->id];
            modis_roi_config.w2m = KAL_TRUE;
            modis_roi_config.w2lcm = KAL_FALSE;
            modis_roi_config.w2m_fmt = W2M_PARGB8888_CONST_A;
            modis_roi_config.w2m_add = modis_lcd_update_w2m_tempbuffer;
            modis_roi_config.pitch = (pPortCfg->portWidth);
            modis_roi_config.w2m_ofs.x = pPortCfg->partialRefreshRectangle[RECT_OFFSETX];
            modis_roi_config.w2m_ofs.y = pPortCfg->partialRefreshRectangle[RECT_OFFSETY];
        }
		
		modis_roi_config.layer_en = 0;
        for (i = 0; i < DRV_LAYER_TOTAL_COUNT; i++)
        {
            if (pPortCfg->bindedPipelines[i])
            {
            	
                modis_roi_config.layer_en |= ((1 << (DRV_LAYER_TOTAL_COUNT - 1)) >> i);
            }
        }

        roi_background = CONVERT_TO_LCD_HW_BK_COLOR(pPortCfg->backgroundColor[0], //A
                                                    pPortCfg->backgroundColor[1], //R 
                                                    pPortCfg->backgroundColor[2], //G
                                                    pPortCfg->backgroundColor[3]);//B



        modis_roi_config.ofs.x = (pPortCfg->roiDestRectangle[RECT_OFFSETX] + WFD_LCD_ROI_ORIGIN_X);
        modis_roi_config.ofs.y = (pPortCfg->roiDestRectangle[RECT_OFFSETY] + WFD_LCD_ROI_ORIGIN_Y);
        
        modis_roi_config.size.x = (pPortCfg->roiDestRectangle[RECT_WIDTH]);
        modis_roi_config.size.y = (pPortCfg->roiDestRectangle[RECT_HEIGHT]);
        
        modis_roi_config.bgclr = roi_background;
        
        modis_roi_config.command_addr = port->portCmdAddr;
        
        modis_roi_config.data_addr = port->portDataAddr;
    }


    //Config MemOut
    {      
        if (WFD_PORT_TYPE_MEMORY_OUTPUT_MTK == pPortCfg->type)
        {
            //Call this function after seeting ROI register
            device->utilityTable._wfd_ConfigMemOut(device, port);
        }
    }

    //Handle INT Mask Here.....	
    {
        // Zifeng: Modis does not need
    }

    //performance config registers information
    {
       // Zifeng: Modis does not need
    }

    //Handle BlockWrite
    {

        ENABLE_LCD_SERIAL_IF_CS(1,0);
        WFD_CATCHLOG_PROFILE_START();
        if (WFD_PORT_TYPE_INTERNAL == pPortCfg->type)
        {
        	lcd_frame_update_struct_modis lcd_para = {0};        	
            kal_uint32 layer_flag_table[] = 
            {
                LCD_LAYER0_ENABLE,
                LCD_LAYER1_ENABLE,
                LCD_LAYER2_ENABLE,
                LCD_LAYER3_ENABLE,
                LCD_LAYER4_ENABLE,
                LCD_LAYER5_ENABLE
            };
            __wfd_lcd_trace(WFDLCD______________BEING_BLT);
            _modis_lcd_update(modis_layer_config, &modis_roi_config);
            // Copy ROI region to GRAM
            for (i = modis_roi_config.w2m_ofs.y; i < modis_roi_config.w2m_ofs.y + modis_roi_config.size.y; i++)
            {
            	kal_uint32 *modis_lcm_gram_addr = modis_current_lcm_gram + (pPortCfg->portHeight - 1 - i) * pPortCfg->portWidth + pPortCfg->partialRefreshRectangle[RECT_OFFSETX];
                kal_uint32 *modis_lcd_w2m_buffer = (kal_uint32 *)modis_lcd_update_w2m_tempbuffer;
                modis_lcd_w2m_buffer += i * pPortCfg->portWidth + modis_roi_config.w2m_ofs.x;
                memcpy (modis_lcm_gram_addr, modis_lcd_w2m_buffer, modis_roi_config.size.x*4);
            }
            
            if (modis_lcd_debug)  // For debug
            {
                if (pPortCfg->bindedPipelines[0])
                    dump(modis_layer_config[0].layer_add, modis_layer_config[0].size.x, modis_layer_config[0].size.y, modis_layer_config[0].bpp, "blt_layer0.ibf");
                if (pPortCfg->bindedPipelines[1])
                    dump(modis_layer_config[1].layer_add, modis_layer_config[1].size.x, modis_layer_config[1].size.y, modis_layer_config[1].bpp, "blt_layer1.ibf");
                if (pPortCfg->bindedPipelines[2])
                    dump(modis_layer_config[2].layer_add, modis_layer_config[2].size.x, modis_layer_config[2].size.y, modis_layer_config[2].bpp, "blt_layer2.ibf");
                if (pPortCfg->bindedPipelines[3])
                    dump(modis_layer_config[3].layer_add, modis_layer_config[3].size.x, modis_layer_config[3].size.y, modis_layer_config[3].bpp, "blt_layer3.ibf");
#if (DRV_LAYER_TOTAL_COUNT > 4)
                if (pPortCfg->bindedPipelines[4])
                    dump(modis_layer_config[4].layer_add, modis_layer_config[4].size.x, modis_layer_config[4].size.y, modis_layer_config[4].bpp, "blt_layer4.ibf");
                if (pPortCfg->bindedPipelines[5])
                    dump(modis_layer_config[5].layer_add, modis_layer_config[5].size.x, modis_layer_config[5].size.y, modis_layer_config[5].bpp, "blt_layer5.ibf");
#endif
                dump(modis_current_lcm_gram, pPortCfg->portWidth, pPortCfg->portHeight, 4, "blt.ibf");
            }

            lcd_para.module_id = LCD_UPDATE_MODULE_MMI;
            lcd_para.lcd_id = pPortCfg->id + 1; //Main_lcd = 1, Sub_lcd =2
            lcd_para.block_mode_flag = pPortCfg->blockModeReq;
            lcd_para.lcd_block_mode_cb = NULL;
            lcd_para.fb_update_mode = LCD_SW_TRIGGER_MODE;
            lcd_para.lcm_start_x = pPortCfg->partialRefreshRectangle[RECT_OFFSETX];
            lcd_para.lcm_start_y = pPortCfg->partialRefreshRectangle[RECT_OFFSETY];
            lcd_para.lcm_end_x = pPortCfg->partialRefreshRectangle[RECT_OFFSETX] + pPortCfg->partialRefreshRectangle[RECT_WIDTH] - 1;
            lcd_para.lcm_end_y = pPortCfg->partialRefreshRectangle[RECT_OFFSETY] + pPortCfg->partialRefreshRectangle[RECT_HEIGHT] - 1;
            lcd_para.roi_offset_x = modis_roi_config.ofs.x;
            lcd_para.roi_offset_y = modis_roi_config.ofs.y;
            for (i = 0; i < DRV_LAYER_TOTAL_COUNT; i++)
            {
                if (pPortCfg->bindedPipelines[i])
                {
            	
                    lcd_para.update_layer |= layer_flag_table[i];
                }
            }
            lcd_para.roi_background_color = modis_roi_config.bgclr;
            w32_lcd_update(&lcd_para, modis_lcd_layer_data, layer_flag_table, modis_current_lcm_gram);

        }
        else
        {
            __wfd_lcd_trace(WFDLCD______________BEING_FLT);
            _modis_lcd_update(modis_layer_config, &modis_roi_config);
            
            if (modis_lcd_debug)  // For debug
            {
                if (pPortCfg->bindedPipelines[0])
                    dump(modis_layer_config[0].layer_add, modis_layer_config[0].size.x, modis_layer_config[0].size.y, modis_layer_config[0].bpp, "flatten_layer0.ibf");
                if (pPortCfg->bindedPipelines[1])
                    dump(modis_layer_config[1].layer_add, modis_layer_config[1].size.x, modis_layer_config[1].size.y, modis_layer_config[1].bpp, "flatten_layer1.ibf");
                if (pPortCfg->bindedPipelines[2])
                    dump(modis_layer_config[2].layer_add, modis_layer_config[2].size.x, modis_layer_config[2].size.y, modis_layer_config[2].bpp, "flatten_layer2.ibf");
                if (pPortCfg->bindedPipelines[3])
                    dump(modis_layer_config[3].layer_add, modis_layer_config[3].size.x, modis_layer_config[3].size.y, modis_layer_config[3].bpp, "flatten_layer3.ibf");
#if (DRV_LAYER_TOTAL_COUNT > 4)
                if (pPortCfg->bindedPipelines[4])
                    dump(modis_layer_config[4].layer_add, modis_layer_config[4].size.x, modis_layer_config[4].size.y, modis_layer_config[4].bpp, "flatten_layer4.ibf");
                if (pPortCfg->bindedPipelines[5])
                    dump(modis_layer_config[5].layer_add, modis_layer_config[5].size.x, modis_layer_config[5].size.y, modis_layer_config[5].bpp, "flatten_layer5.ibf");
#endif
                dump(modis_roi_config.w2m_add, modis_roi_config.pitch, modis_roi_config.ofs.y + modis_roi_config.size.y, pPortCfg->targetImage->pixelSize, "flatten.ibf");
            }
            
        }

        pPortCfg->doBlt = WFD_FALSE;
    }

    if (WFD_TRUE == pPortCfg->blockModeReq)
    {
        __wfd_lcd_WaitEvent_modis(event);      
    }

exit:
    return result;
}



static WFDboolean
__wfd_lcd_ConfigDitherCtrl_modis(void)
{
    kal_uint32 dither_bit_r, dither_bit_g, dither_bit_b;
    kal_uint32 lcd_to_lcm_fmt;

    lcd_to_lcm_fmt = 3; //In modis, set to be RGB666

    // Currently ROI color format in HW LCD register are at the same location.
    switch (lcd_to_lcm_fmt)
    {

        case 2: // RGB888 -> RGB565
            dither_bit_r = 2;
            dither_bit_g = 1;
            dither_bit_b = 2;
            break;
        case 3: // RGB888 -> RGB666
        default:
            dither_bit_r = 1;
            dither_bit_g = 1;
            dither_bit_b = 1;
            break;
    }


    modis_roi_config.db_r = dither_bit_r;
    modis_roi_config.db_g = dither_bit_g;
    modis_roi_config.db_b = dither_bit_b;
    
    modis_roi_config.lfsr_r_seed = 1;
    modis_roi_config.lfsr_g_seed = 1;
    modis_roi_config.lfsr_b_seed = 1;
    

    return WFD_TRUE;
}



static WFDboolean
__wfd_lcd_PipelineCommit_modis(WFD_DEVICE* device, WFD_PIPELINE* pipeline)
{
    WFD_PIPELINE *cap_pPipeline;
    WFDint id = pipeline->config.id;

    if ((NULL == device) || (NULL == pipeline))  { return WFD_FALSE; }

    id = pipeline->config.id;
    cap_pPipeline = &_wfd_lcd_pipeline[id];

    //configure pipeline setting to HW
    {
        WFD_PIPELINE_CONFIG*  config = &(cap_pPipeline->config);
        WFDuint angle;

        // Move to the front since MMSYS must be enabled before setting LCD registers.
        device->utilityTable._wfd_PowerCtrl(device, wfd_lcd_power_ctrl_handle, WFD_TRUE);

        memset(&modis_layer_config[id], 0, sizeof(modis_layer_config[id]));
        memset(&modis_current_lcd_layer_data[id], 0, sizeof(lcd_layer_struct_modis));
        if (config->transparencyEnable & WFD_TRANSPARENCY_SOURCE_COLOR)
        {
        	
            modis_layer_config[id].skey_en = KAL_TRUE;
            modis_current_lcd_layer_data[id].source_key_enable = KAL_TRUE;
        }

        if (config->transparencyEnable & WFD_TRANSPARENCY_GLOBAL_ALPHA)
        {
        	
            modis_layer_config[id].opaen = KAL_TRUE;
            modis_current_lcd_layer_data[id].opacity_enable = KAL_TRUE;
        }

        if (config->transparencyEnable & WFD_TRANSPARENCY_SOURCE_ALPHA)
        {
        	
            modis_layer_config[id].opaen = KAL_TRUE;
            modis_current_lcd_layer_data[id].opacity_enable = KAL_TRUE;
            if ((OWF_IMAGE_ARGB8888 != config->image_source->format.pixelFormat) && (OWF_IMAGE_ARGB6666 != config->image_source->format.pixelFormat))
            {
                ASSERT(0);
            }
        }

        if (config->transparencyEnable & WFD_TRANSPARENCY_GLOBAL_ALPHA)
        {
        	
            modis_layer_config[id].opacity = config->globalAlpha;
            modis_current_lcd_layer_data[id].opacity_value = config->globalAlpha;
        }
        else if (config->transparencyEnable & WFD_TRANSPARENCY_SOURCE_ALPHA)
        {
        	
            modis_layer_config[id].opacity = 0xFF;
            modis_current_lcd_layer_data[id].opacity_value = 0xFF;
        }        

        //Rotation Angle
        {
            angle = device->utilityTable._wfd_CnvtAngleToHwDef(device, config->rotation, config->flip);
            
            modis_layer_config[id].rotate = angle;
            modis_current_lcd_layer_data[id].rotate_value = angle;
        }

        // Byte Swap Enable?
        if (config->swapEnable)
        {
        	
            modis_layer_config[id].swap = KAL_TRUE;
        }

        //Dither Enable?
        if (config->ditherEnable)
        {
        	
            modis_layer_config[id].dither_en = KAL_TRUE;
            __wfd_lcd_ConfigDitherCtrl_modis();
            modis_current_lcd_layer_data[id].dither_enable = KAL_TRUE;
        }

        //Color Format
        {
            WFD_LCD_LAYER_SOURCE_COLOR_FORMAT_ENUM color_format;
            color_format = device->utilityTable._wfd_CnvtImgFormatToHwDef(&config->image_source->format);

            if (WFD_LCD_LAYER_FORMAT_RSD == color_format)	
            {
                return WFD_FALSE;
            }
            else if (WFD_LCD_LAYER_FORMAT_8BPP_INDEX == color_format)
            {
            	WFDuint loop_count;
            	kal_uint16 *palette_addr = (kal_uint16 *)(_wfd_current_processing_port->config.paletteTable);
            	
                modis_roi_config.pal_add = (kal_uint8 *)(_wfd_current_processing_port->config.paletteTable);
                for(loop_count = 0; loop_count < PALETTE_NUM; loop_count++)
                    modis_roi_config.palette[loop_count] = (kal_uint32)(*(palette_addr + loop_count));
                    
                modis_current_lcd_layer_data[id].color_palette_enable = KAL_TRUE;
            }
            
            
            modis_layer_config[id].clrdpt = color_format;
            modis_current_lcd_layer_data[id].source_color_format = color_format;
        }



        modis_layer_config[id].skey = config->transparencyColor;
        modis_current_lcd_layer_data[id].source_key = config->transparencyColor;
        
        modis_layer_config[id].layer_add = (WFDuint8 *)(config->image_source->data);
        modis_current_lcd_layer_data[id].frame_buffer_address = (kal_uint32)(config->image_source->data);


        modis_layer_config[id].ofs.x = config->destinationRectangle[RECT_OFFSETX] + WFD_LCD_ROI_ORIGIN_X;
        modis_layer_config[id].ofs.y = config->destinationRectangle[RECT_OFFSETY] + WFD_LCD_ROI_ORIGIN_Y;
        modis_current_lcd_layer_data[id].x_offset = modis_layer_config[id].ofs.x;
        modis_current_lcd_layer_data[id].y_offset = modis_layer_config[id].ofs.y;


        modis_layer_config[id].size.x = config->sourceRectangle[RECT_WIDTH];
        modis_layer_config[id].size.y = config->sourceRectangle[RECT_HEIGHT];
        modis_current_lcd_layer_data[id].row_number = modis_layer_config[id].size.y;
        modis_current_lcd_layer_data[id].column_number = modis_layer_config[id].size.x;
        
        
        modis_layer_config[id].mem_ofs.x = config->sourceRectangle[RECT_OFFSETX];
        modis_layer_config[id].mem_ofs.y = config->sourceRectangle[RECT_OFFSETY];
        modis_current_lcd_layer_data[id].mem_x_offset = modis_layer_config[id].mem_ofs.x;
        modis_current_lcd_layer_data[id].mem_y_offset = modis_layer_config[id].mem_ofs.y;


        modis_layer_config[id].pitch = ((config->image_source->stride)/(config->image_source->pixelSize));
        modis_current_lcd_layer_data[id].mem_pitch = modis_layer_config[id].pitch;
        
        modis_layer_config[id].bpp = ((config->image_source->pixelSize));
        
        //Dong: for argb6666 info moniter can't display abnormally so convert argb6666 to rgb565
        {
	        	WFD_PORT_CONFIG portConfig = ((WFD_PORT*) (pipeline->config.portId))->config;
		        if((modis_layer_config[id].clrdpt == WFD_LCD_LAYER_FORMAT_ARGB8888 
					|| modis_layer_config[id].clrdpt == WFD_LCD_LAYER_FORMAT_PARGB8888
					|| modis_layer_config[id].clrdpt == WFD_LCD_LAYER_FORMAT_RGB888
					|| modis_layer_config[id].clrdpt == WFD_LCD_LAYER_FORMAT_ARGB6666
					|| modis_layer_config[id].clrdpt == WFD_LCD_LAYER_FORMAT_PARGB6666)
		        	&& portConfig.type == WFD_PORT_TYPE_INTERNAL)
		        {
			        	kal_uint32 screen_id;        	
			        	screen_id = ((WFD_PORT*)(pipeline->config.portId))->screenNumber;        	
			        	modis_current_lcd_layer_data[id].frame_buffer_address = __wfd_lcd_SrcBufCnvtToRgb565_Ex(config->image_source, screen_id, id);
			          modis_current_lcd_layer_data[id].source_color_format = WFD_LCD_LAYER_FORMAT_RGB565;
						    modis_current_lcd_layer_data[id].opacity_enable = KAL_FALSE;
		        }     
        }     
        
    }
    
    return WFD_TRUE;
}


static WFDboolean
__wfd_lcd_FastRotatorMemEnable_modis(WFDboolean enable)
{
    return WFD_TRUE;
}



static void
_wfd_lcd_init_internal_modis(void)
{
    // Init port for each LCM and memory out.
    {
        WFDuint i;

        for (i = 0; i < WFD_ATTACHED_PORT_COUNT; i++)
        {		 
            //  Init port
            __wfd_lcd_InitPort_modis(&_wfd_lcd_port[WFD_SCREEN_LCD_0+i],
                               WFD_SCREEN_LCD_0+i, &_wfd_lcd_if_para[i]);
        
            // Init port config
            __wfd_lcd_InitPortConfig_modis(&_wfd_lcd_port[WFD_SCREEN_LCD_0+i].config,
                                     WFD_SCREEN_LCD_0+i, &_wfd_lcd_if_para[i]);
        }
    }

    // Init pipelines.
    {
        kal_uint32 i;

        _wfd_lcd_pipeline[0].config.maxSourceSize[0] = WFD_LCD_LAYER_MAX_WIDTH;
        _wfd_lcd_pipeline[0].config.maxSourceSize[1] = WFD_LCD_LAYER_MAX_HEIGHT;

        for (i = 1; i < DRV_LAYER_TOTAL_COUNT; i++)
        {
            kal_mem_cpy((void*) &_wfd_lcd_pipeline[i].config,
                        (void*) &_wfd_lcd_pipeline[0].config,
                        sizeof(WFD_PIPELINE_CONFIG));

            _wfd_lcd_pipeline[i].config.id = i;
        }

        for (i = 0; i < DRV_LAYER_TOTAL_COUNT; i++)
        {
            _wfd_lcd_pipeline[i].device = &_wfd_lcd_device;
        }
    }

}



static WFDDevice
_wfd_lcd_CreateDevice_modis(WFDint deviceId, const WFDint *attribList)
{
    // TODO: parameter checking...
    _wfd_lcd_device.inUse = &_wfd_lcd_device;
    _wfd_lcd_device.id = deviceId;
    return (WFDDevice) &_wfd_lcd_device;
}



static WFDErrorCode
_wfd_lcd_DestroyDevice_modis(WFDDevice device)
{
    CHECK_DEVICE(device, WFD_ERROR_BAD_DEVICE, WFD_ERROR_BAD_DEVICE);

    // TODO: check if LCD is still busy...
    while (_wfd_lcd_device.busyFlag == WFD_TRUE)
    {
       kal_sleep_task(1);
    }

    _wfd_lcd_device.inUse = WFD_INVALID_HANDLE;

    return WFD_ERROR_NONE;
}


static void
_wfd_lcd_DeviceCommit_modis(WFDDevice device, WFDCommitType type, WFDHandle handle)
{
    WFD_DEVICE* pDevice;
    WFD_PORT* pPort;

    CHECK_DEVICE_NR(device, WFD_ERROR_BAD_DEVICE);
    CHECK_HANDLE_NR(device, handle, WFD_ERROR_BAD_HANDLE);

    pDevice = &_wfd_lcd_device;
    ASSERT(pDevice->busyFlag == WFD_FALSE);
    pDevice->busyFlag = WFD_TRUE; 
    
    switch (type)
    {
        case WFD_COMMIT_ENTIRE_DEVICE:
        {
  
            pDevice->busyFlag = WFD_FALSE;
                        
            break;
        }
		  
        case WFD_COMMIT_ENTIRE_PORT:
        {
            WFDint i;			
            WFD_PORT_CONFIG* pPortCfg;

            pPort = (WFD_PORT*) handle;
            pPortCfg = &(pPort->config);

            _wfd_current_processing_port = pPort;

            {
               pPortCfg->blockModeReq = WFD_TRUE;
               pPortCfg->syncEnable = WFD_FALSE;
            }
				
            if (pPortCfg->doBlt)
            {
                for (i = 0; i < DRV_LAYER_TOTAL_COUNT; i++)
                {
                    if (pPortCfg->bindedPipelines[i]) //if this pipeline is enabled?
                    {
                       modis_current_lcd_layer_data = modis_lcd_layer_data[pPortCfg->id];
                       pDevice->utilityTable._wfd_PipelineCommit(pDevice, &_wfd_lcd_pipeline[i]);
                    }
                }
					 		
                {
                   pDevice->utilityTable._wfd_Blt(pDevice, pPort, WFD_EVENT_DATA_TRANSFER_COMPLETE_MTK);
                }                
            }
            break;
        }
   }
}


WFD_DEVICE _wfd_lcd_device =
{
    //  Member:  WFDHWDevicePrimitivesMTK      primitivesTable;
    {   ///Must be payed attention to the following order is correct
        NULL,                               ///NULL is a flag to init LCD !!!!!!!!!!!!
        _wfd_lcd_DestroyDevice_modis,
        _wfd_lcd_DeviceCommit_modis,
    },
    //Member: WFDHWDeviceInternalUtilityMTK utilityTable;
    {    ///Must be payed attention to the following order is correct          
        __wfd_device_PowerCtrl_modis,
        __wfd_lcd_CnvtImgFormatToHwDef_modis,
        __wfd_lcd_CnvtEventToHWDef_modis,
        __wfd_lcd_CnvtW2memFormatToHwDef_modis,
        __wfd_lcd_CnvtAngleToHwDef_modis,
        WFD_INVALID_HANDLE,                ///   _wfd_GetIFPara is not used
        __wfd_lcd_Blt_modis,
        __wfd_lcd_PipelineCommit_modis,
        __wfd_lcd_ConfigMemOut_modis,
        WFD_INVALID_HANDLE,
        WFD_INVALID_HANDLE,
    },
    WFD_ERROR_NONE,                         //Member: WFDErrorCode          lastUnreadError;
    WFD_FALSE,                              //Member: WFDboolean            busyFlag;
    NULL,                              //Member: WFD_DEVICE*           inUse;
    0,                                      //Member: WFDint                id;
    {                                       //Member: Config
        WFD_FALSE,
    },
    _wfd_lcd_port,
    WFD_ATTACHED_PORT_COUNT,
    _wfd_lcd_pipeline,
    DRV_LAYER_TOTAL_COUNT
};

WFDLCDInterfacePara _wfd_lcd_if_para[WFD_ATTACHED_PORT_COUNT] = 
{   
    {
        WFD_TRUE,
        LCD_IF_USER_MAIN_LCD,
        LCD_IF_TYPE_DBI_PARALLEL,
        0,
        0x90004000,
        0x90004100,
        0xD8, ///LCM_18BIT_18_BPP_RGB666_1
        NULL,   ///
        0,
    },    
    #if (2 == ATTACHED_LCM_CNT)
    {
        WFD_TRUE,
        LCD_IF_USER_SUB_LCD,
        LCD_IF_TYPE_DBI_PARALLEL,
        1,
        0x90005000,
        0x90005100,
        0xD8, ///LCM_18BIT_18_BPP_RGB666_1
        NULL,
        0,
    },
    #endif
    #if defined(LCD_FLATTEN_SUPPORT)
    {
        WFD_FALSE,
        LCD_IF_USER_MAIN_LCD,
        LCD_IF_TYPE_DBI_PARALLEL,
        0,
        0x90004000,
        0x90004100,
        WFD_LCD_WMEM_COLOR_RGB565,
        NULL,
        0,
    },
    #endif	 	
};
/*****************************************************************************
 *  API function definitions
 ****************************************************************************/
WFDErrorCode 
wfd_lcd_initialize(WFDHWDevicePrimitivesMTK **pDevicePrimitives)
{
    WFD_DEVICE *device = &_wfd_lcd_device;
    if (NULL == pDevicePrimitives) { return WFD_ERROR_ILLEGAL_ARGUMENT; }

    // check if ever init'ed
    if (NULL != device->primitivesTable.wfdCreateDevice)
    {
        *pDevicePrimitives = &(device->primitivesTable);
        return WFD_ERROR_NONE;
    }

    /*
     * data structure init...
     */
    if (NULL == device->primitivesTable.wfdCreateDevice)
    {
        device->primitivesTable.wfdCreateDevice = _wfd_lcd_CreateDevice_modis;
    }

    *pDevicePrimitives = &(device->primitivesTable);

    /*
     * Init internal used utilities functions...
     */
    // Zifeng: Modis does not need

    /*
     * Do what is done in DDv1::lcd_system_init()
     */
    // 1. Get L1 SM handle.

    // 2. Initialize LCM driver(s)
    _wfd_lcd_if_para[0]._ifFuncTable = NULL;
    #if (2 == ATTACHED_LCM_CNT)
    _wfd_lcd_if_para[1]._ifFuncTable = NULL;
    #endif

    //get power control handle
    // Zifeng: Modis does not need
    // In order to sync with Target, will set wfd_lcd_power_ctrl_handle
    wfd_lcd_power_ctrl_handle = 0x5F44434C; // "LCD_"

    // 3. call _wfd_lcd_init_internal after LCD_FunConfig
    // because we need to call LCM function to get information
    _wfd_lcd_init_internal_modis();
	 
    // 4. Reset LCD HW registers
    // Zifeng: Modis does not need

    // 5. Initialize LCD interface settings, such as setup GPIO, LCM timing, reset LCM
    // TODO: Declare this function in a common header file as a std. API of a LCM driver.
    // Zifeng: Modis does not need

    // 6. Initialize LCM HW module
    // Zifeng: Modis does not need

    // 7. Register LCD I/F manager... after LCM init.
    // Zifeng: Modis does not need


    // 8. Calculate hopping to avoid RF-desense
    // Zifeng: Modis does not need

    // 7. register interrupt LISR/HISR
    // Zifeng: Modis does not need
	 
    // 8. create timer if required
    // Zifeng: Modis does not need

#if defined(DRV_DISPLAY_DRIVER_V2_TEARING_CONTROL_SUPPORT)
    // 10. Init Tear_Manager...
    // Zifeng: Modis does not need
    
#endif //DRV_DISPLAY_DRIVER_V2_TEARING_CONTROL_SUPPORT

	 
    return WFD_ERROR_NONE;
}


DisplayResultEnum DisplayIOControl(DisplayDeviceEnum device, DisplayCtrlCode code, void* pData)
{
    DisplayResultEnum result = DISPLAY_RESULT_OK;
    switch (code)
    {
    case DISPLAY_IOCTL_CABC_QUERY_SUPPORT:
        {
            DisplayCABC_T* pCABCStruct = (DisplayCABC_T*) pData;
            if (pCABCStruct)
            {
                pCABCStruct->bSupport = KAL_FALSE;
            }
            else
                result = DISPLAY_RESULT_INVALID_DATA;
        }
        break;
    case DISPLAY_IOCTL_CABC_SET_MODE:
        result = DISPLAY_RESULT_CONTROL_FAIL;
        break;
    case DISPLAY_IOCTL_CABC_GET_MODE:
        result = DISPLAY_RESULT_CONTROL_FAIL;
        break;
    default:
        result = DISPLAY_RESULT_INVALID_CODE;
        break;
    }

    return result;
}


// For GDI Exception link
kal_uint32 lcd_exception_screen_update(kal_uint8* pFramebuffer, kal_uint32 width, kal_uint32 height)
{
	return 0;
}

kal_uint32 lcd_exception_flatten(kal_uint32 layers, lcd_exception_layer_struct* pLayerInfo, kal_uint8* pFramebuffer, kal_uint32 bg_color, kal_uint32 width, kal_uint32 height)
{
	return 0;
}

void dump(void* pBuffer, kal_uint32 width, kal_uint32 height, kal_uint32 bpp, kal_uint8* file)
{
    FILE* fp = NULL;
    kal_uint32 size = width * height * bpp;
    kal_uint32 data = 0;
    if (pBuffer == NULL)
        return;
    if (width == 0 || height == 0)
        return;
    if (file == NULL)
    {
        strcpy(g_lcd_debug_file, g_lcd_debug_path);
        strcat(g_lcd_debug_file, "\\temp.ibf");
    }
    else
    {
        strcpy(g_lcd_debug_file, g_lcd_debug_path);
        strcat(g_lcd_debug_file, "\\");
        strcat(g_lcd_debug_file, file);
    }
    fp = fopen(g_lcd_debug_file, "wb");
    if (fp)
    {
        data = 1;
        fwrite(&data, 4, 1, fp);
        fwrite(&size, 4, 1, fp);
        fwrite(&width, 4, 1, fp);
        fwrite(&height, 4, 1, fp);
        if (bpp == 2)
            data = 1;
        else if (bpp == 3)
            data = 2;
        else if (bpp == 4)
            data = 3;
        else
            data = -1;
        fwrite(&data, 4, 1, fp);
        fwrite(pBuffer, size, 1, fp);
        fclose(fp);
    }
}

#endif //#if defined(DRV_DISPLAY_DRIVER_V2)

#ifdef __cplusplus
}
#endif


#endif  // #if defined(__MTK_TARGET__)

