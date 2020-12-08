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
 *   image_sensor.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Image sensor driver function
 *
 * Author:
 * -------
 *   
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "isp_comm_if.h"
#include "camera_sccb.h"
#include "image_sensor.h"
#include "cal_comm_def.h"
#include "isp_if.h"


static struct
{
  kal_uint8   Banding;
  kal_bool    NightMode;
  kal_bool    VideoMode;
  kal_bool    PreviewMode;
  kal_bool	  BypassAe;
  kal_bool    BypassAwb;
  kal_uint16  Fps;
  kal_uint32  PrePclk;
  kal_uint32  CapPclk;
  kal_uint16  PreDummyPixel; /* for user customization */
  kal_uint16  PreDummyLine;
  kal_uint16  CapDummyPixel; /* for user customization */
  kal_uint16  CapDummyLine;
  kal_uint16  Hblank; /* for calculating shutter step */
  kal_uint16  ShutterStep;
  IMAGE_SENSOR_INDEX_ENUM SensorIdx;
  sensor_data_struct *NvramData;
} MT9D115Sensor; 
// for HAL
//IMAGE_SENSOR_INDEX_ENUM MT9D115Sensor.SensorIdx;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

/*************************************************************************
* FUNCTION
*    MT9D115SetCmd
*
* DESCRIPTION
*    This function set command to the sequencer to change the state.
*    when set cmd fail, the function retry again until try times reach 200.
*
* PARAMETERS
*    cmd    : command, MUST BE 1, 2, 5, 6 !!!
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void MT9D115SetCmd(kal_uint16 cmd)
{
  kal_uint8 status;
  kal_uint8 delay, i;

  delay = 2;

  CamWriteCmosSensor(0x098C, 0xA103);
  CamWriteCmosSensor(0x0990, cmd);

  for (i = 100; i > 0; i--) /* wait for ready */
  {

	 kal_sleep_task(delay);
   
	CamWriteCmosSensor(0x098C, 0xA103);
	status = CamReadCmosSensor(0x0990);
      if(0 == status)
      	{
      	   break;
      	}
   
  
  }
#ifdef __MT9D115_DEBUG_TRACE__
  if (!i) kal_print_string_trace(MOD_ENG, TRACE_WARNING, "set cmd: %d time out", cmd);
#endif
kal_sleep_task(5);
}


/*************************************************************************
* FUNCTION
*   MT9D115SetNightMode
*
* DESCRIPTION
*   This function switch on/off night mode of MT9D115.
*
*************************************************************************/

MM_ERROR_CODE_ENUM MT9D115SetNightMode(kal_bool night_enable)
{
	//MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
	
#ifdef    __MT9D115_DEBUG_INFO__
    kal_wap_trace(MOD_ENG,TRACE_INFO, "NightMode %d", night_enable);
#endif

	if (night_enable == KAL_TRUE)
	{
		//switch (ScenarioId)
		//{
		//case CAL_SCENARIO_VIDEO:
			
		//	break;
		//case CAL_SCENARIO_CAMERA_PREVIEW:
		//case CAL_SCENARIO_WEBCAM_PREVIEW:
		//case CAL_SCENARIO_WEBCAM_CAPTURE:
			CamWriteCmosSensor(0x098C, 0xA20B); 	// MCU_ADDRESS [AE_MIN_INDEX]
            CamWriteCmosSensor(0x0990, 0x0008); 	// MCU_DATA_0
            CamWriteCmosSensor(0x098C, 0xA20C); 	// MCU_ADDRESS [AE_Max_INDEX]
            CamWriteCmosSensor(0x0990, 0x0014);
            MT9D115SetCmd(5);
		//	break;
		//default:
		//	ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		//	break;
		//}
	}
	else
	{
	//	switch (ScenarioId)
	//	{
	//	case CAL_SCENARIO_VIDEO:

	//		break;
	//	case CAL_SCENARIO_CAMERA_PREVIEW:
	//	case CAL_SCENARIO_WEBCAM_PREVIEW:
	//	case CAL_SCENARIO_WEBCAM_CAPTURE:
			CamWriteCmosSensor(0x098C, 0xA20B); 	// MCU_ADDRESS [AE_MIN_INDEX]
         	CamWriteCmosSensor(0x0990, 0x0000); 	// MCU_DATA_0
         	CamWriteCmosSensor(0x098C, 0xA20C); 	// MCU_ADDRESS [AE_Max_INDEX]
         	CamWriteCmosSensor(0x0990, 0x000E); // MCU_DATA_0
            MT9D115SetCmd(5);
	//		break;
	//	default:
	//		ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
	//		break;
	//	}
	}
    MT9D115Sensor.NightMode = night_enable;
	//return ErrCode;
}   /* MT9D115SetNightMode */



/*************************************************************************
* FUNCTION
*   MT9D115InitialSetting
*
* DESCRIPTION
*   This function initialize the registers of CMOS sensor.
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void MT9D115InitialSetting(void)
{
  kal_uint16 delay,i;
  kal_uint16 status;

 
  #ifdef __MT9D115_DEBUG_TRACE__
  kal_print_string_trace(MOD_ENG, TRACE_WARNING, "MT9D115_YUV_sensor_initial_setting");
  #endif
  
  

  ///PLL
  CamWriteCmosSensor(0x0014, 0x21F9);	//PLL Control: BYPASS PLL = 9541
  CamWriteCmosSensor(0x0010, 0x0110);	//PLL Dividers = 272
  CamWriteCmosSensor(0x0012, 0x1FF7);	//PLL P Dividers = 8183
  CamWriteCmosSensor(0x0014, 0x2545);	//PLL Control: TEST_BYPASS on = 9541
  CamWriteCmosSensor(0x0014, 0x2547);	//PLL Control: PLL_ENABLE on = 9543
  CamWriteCmosSensor(0x0014, 0x2447);	//PLL Control: SEL_LOCK_DET on
  //DELAY = 1               //Delay 1ms to allow PLL to lock
  kal_sleep_task(1);
  CamWriteCmosSensor(0x0014, 0x2047);	//PLL Control: PLL_BYPASS off
  CamWriteCmosSensor(0x0014, 0x2046);	//PLL Control: TEST_BYPASS off
  //CamWriteCmosSensor(0x001E, 0x0707); 	// PAD_SLEW
  //CamWriteCmosSensor(0x001E, 0x0300); 	// PAD_SLEW
  CamWriteCmosSensor(0x001E, 0x0700); 	// PAD_SLEW
  //CamWriteCmosSensor(0x001A, 0x0050); 	// RESET_AND_MISC_CONTROL
  CamWriteCmosSensor(0x0018, 0x402D); 	// STANDBY_CONTROL  MCU powerup stop enable
  
  CamWriteCmosSensor(0x0018, 0x402C); 	// STANDBY_CONTROL  GO
  //DELAY=10
  kal_sleep_task(3);


  
  ///TIMMING
  CamWriteCmosSensor(0x321C, 0x0003);	  //By Pass TxFIFO = 3
  CamWriteCmosSensor(0x98C, 0x2703); //Output Width (A)
  CamWriteCmosSensor(0x990, 0x0320); //	  = 800
  CamWriteCmosSensor(0x98C, 0x2705); //Output Height (A)
  CamWriteCmosSensor(0x990, 0x0258); //	  = 600
  CamWriteCmosSensor(0x98C, 0x2707); //Output Width (B)
  CamWriteCmosSensor(0x990, 0x0640); //	  = 1600
  CamWriteCmosSensor(0x98C, 0x2709); //Output Height (B)
  CamWriteCmosSensor(0x990, 0x04B0); //	  = 1200
  CamWriteCmosSensor(0x98C, 0x270D); //Row Start (A)
  CamWriteCmosSensor(0x990, 0x000);  //	  = 0
  CamWriteCmosSensor(0x98C, 0x270F); //Column Start (A)
  CamWriteCmosSensor(0x990, 0x000);  //	  = 0
  CamWriteCmosSensor(0x98C, 0x2711); //Row End (A)
  CamWriteCmosSensor(0x990, 0x4BD);  //	  = 1213
  CamWriteCmosSensor(0x98C, 0x2713); //Column End (A)
  CamWriteCmosSensor(0x990, 0x64D);  //	  = 1613
  CamWriteCmosSensor(0x98C, 0x2715); //Row Speed (A)
  CamWriteCmosSensor(0x990, 0x0111); //	  = 273
  CamWriteCmosSensor(0x98C, 0x2717); //Read Mode (A)
  CamWriteCmosSensor(0x990, 0x046C); //	  = 1132
  CamWriteCmosSensor(0x98C, 0x2719); //sensor_fine_correction (A)
  CamWriteCmosSensor(0x990, 0x005A); //	  = 90
  CamWriteCmosSensor(0x98C, 0x271B); //sensor_fine_IT_min (A)
  CamWriteCmosSensor(0x990, 0x01BE); //	  = 446
  CamWriteCmosSensor(0x98C, 0x271D); //sensor_fine_IT_max_margin (A)
  CamWriteCmosSensor(0x990, 0x0131); //	  = 305
  CamWriteCmosSensor(0x98C, 0x271F); //Frame Lines (A)
  CamWriteCmosSensor(0x990, 0x02B3); //	  = 691
  CamWriteCmosSensor(0x98C, 0x2721); //Line Length (A)
  //CamWriteCmosSensor(0x990, 0x0558); //	  = 1368
  CamWriteCmosSensor(0x990, 0x0546); //	  = 1350
  CamWriteCmosSensor(0x98C, 0x2723); //Row Start (B)
  CamWriteCmosSensor(0x990, 0x004 ); //	  = 4
  CamWriteCmosSensor(0x98C, 0x2725); //Column Start (B)
  CamWriteCmosSensor(0x990, 0x004 ); //	  = 4
  CamWriteCmosSensor(0x98C, 0x2727); //Row End (B)
  CamWriteCmosSensor(0x990, 0x4BB ); //	  = 1211
  CamWriteCmosSensor(0x98C, 0x2729); //Column End (B)
  CamWriteCmosSensor(0x990, 0x64B ); //	  = 1611
  CamWriteCmosSensor(0x98C, 0x272B); //Row Speed (B)
  CamWriteCmosSensor(0x990, 0x0111); //	  = 273
  CamWriteCmosSensor(0x98C, 0x272D); //Read Mode (B)
  CamWriteCmosSensor(0x990, 0x0024); //	  = 36
  CamWriteCmosSensor(0x98C, 0x272F); //sensor_fine_correction (B)
  CamWriteCmosSensor(0x990, 0x003A); //	  = 58
  CamWriteCmosSensor(0x98C, 0x2731); //sensor_fine_IT_min (B)
  CamWriteCmosSensor(0x990, 0x00F6); //	  = 246
  CamWriteCmosSensor(0x98C, 0x2733); //sensor_fine_IT_max_margin (B)
  CamWriteCmosSensor(0x990, 0x008B); //	  = 139
  CamWriteCmosSensor(0x98C, 0x2735); //Frame Lines (B)
  CamWriteCmosSensor(0x990, 0x050D); //	  = 1293
  CamWriteCmosSensor(0x98C, 0x2737); //Line Length (B)
  CamWriteCmosSensor(0x990, 0x0844); //	  = 2116
  CamWriteCmosSensor(0x98C, 0x2739); //Crop_X0 (A)
  CamWriteCmosSensor(0x990, 0x0000); //	  = 0
  CamWriteCmosSensor(0x98C, 0x273B); //Crop_X1 (A)
  CamWriteCmosSensor(0x990, 0x031F); //	  = 799
  CamWriteCmosSensor(0x98C, 0x273D); //Crop_Y0 (A)
  CamWriteCmosSensor(0x990, 0x0000); //	  = 0
  CamWriteCmosSensor(0x98C, 0x273F); //Crop_Y1 (A)
  CamWriteCmosSensor(0x990, 0x0257); //	  = 599
  CamWriteCmosSensor(0x98C, 0x2747); //Crop_X0 (B)
  CamWriteCmosSensor(0x990, 0x0000); //	  = 0
  CamWriteCmosSensor(0x98C, 0x2749); //Crop_X1 (B)
  CamWriteCmosSensor(0x990, 0x063F); //	  = 1599
  CamWriteCmosSensor(0x98C, 0x274B); //Crop_Y0 (B)
  CamWriteCmosSensor(0x990, 0x0000); //	  = 0
  CamWriteCmosSensor(0x98C, 0x274D); //Crop_Y1 (B)
  CamWriteCmosSensor(0x990, 0x04AF); //	  = 1199
  CamWriteCmosSensor(0x98C, 0x222D); //R9 Step
  CamWriteCmosSensor(0x990, 0x009E); //	  = 158
  CamWriteCmosSensor(0x98C, 0xA408); //search_f1_50
  CamWriteCmosSensor(0x990, 0x26  ); //	  = 38
  CamWriteCmosSensor(0x98C, 0xA409); //search_f2_50
  CamWriteCmosSensor(0x990, 0x28  ); //	  = 40
  CamWriteCmosSensor(0x98C, 0xA40A); //search_f1_60
  CamWriteCmosSensor(0x990, 0x2E  ); //	  = 46
  CamWriteCmosSensor(0x98C, 0xA40B); //search_f2_60
  CamWriteCmosSensor(0x990, 0x30  );//	  = 48
  CamWriteCmosSensor(0x98C, 0x2411); //R9_Step_60 (A)
  //CamWriteCmosSensor(0x990, 0x009E); //	  = 148
  CamWriteCmosSensor(0x990, 0x0094); //	  = 158
  CamWriteCmosSensor(0x98C, 0x2413); //R9_Step_50 (A)
  //CamWriteCmosSensor(0x990, 0x00BE); //	  = 190
  CamWriteCmosSensor(0x990, 0x00B2); //	  = 178
  CamWriteCmosSensor(0x98C, 0x2415); //R9_Step_60 (B)
  CamWriteCmosSensor(0x990, 0x0066); //	  = 102
  CamWriteCmosSensor(0x98C, 0x2417); //R9_Step_50 (B)
  CamWriteCmosSensor(0x990, 0x007B); //	  = 123
  CamWriteCmosSensor(0x98C, 0xA404); //FD Mode
  CamWriteCmosSensor(0x990, 0x10  ); //	  = 16
  CamWriteCmosSensor(0x98C, 0xA40D); //Stat_min
  CamWriteCmosSensor(0x990, 0x02  ); //	  = 2
  CamWriteCmosSensor(0x98C, 0xA40E);//Stat_max
  CamWriteCmosSensor(0x990, 0x03  ); //	  = 3
  CamWriteCmosSensor(0x98C, 0xA410); //Min_amplitude
  CamWriteCmosSensor(0x990, 0x0A  ); //	  = 10
  
  ///AE settings
  CamWriteCmosSensor(0x098C, 0xA117);	  // MCU_ADDRESS [SEQ_PREVIEW_0_AE]
  CamWriteCmosSensor(0x0990, 0x0002);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xA11D);	  // MCU_ADDRESS [SEQ_PREVIEW_1_AE]
  CamWriteCmosSensor(0x0990, 0x0002);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xA129);	  // MCU_ADDRESS [SEQ_PREVIEW_3_AE]
  CamWriteCmosSensor(0x0990, 0x0002);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xA24F);	  // MCU_ADDRESS [AE_BASETARGET]
  CamWriteCmosSensor(0x0990, 0x0040);	  // MCU_DATA_0 0x32
  //11-23
  //CamWriteCmosSensor(0x098C, 0xA20C);	  // MCU_ADDRESS [AE_MAX_INDEX]
  //CamWriteCmosSensor(0x0990, 0x0002);	  // MCU_DATA_0
  //CamWriteCmosSensor(0x0990, 0x0014);	  // MCU_DATA_0
  //CamWriteCmosSensor(0x0990, 0x0003);	  // MCU_DATA_0

  //12-2
  CamWriteCmosSensor(0x098C, 0xA20C);  // MCU_ADDRESS [AE_MAX_INDEX]
  CamWriteCmosSensor(0x0990, 0x0014);	  // MCU_DATA_0
  
  CamWriteCmosSensor(0x098C, 0xA216);	  // MCU_ADDRESS
  //12-2
  //CamWriteCmosSensor(0x0990, 0x0051);	  // MCU_DATA_0
  CamWriteCmosSensor(0x0990, 0x0091);	  // MCU_DATA_0
  
  CamWriteCmosSensor(0x098C, 0xA20E);	  // MCU_ADDRESS [AE_MAX_VIRTGAIN]
  //12-2
  //CamWriteCmosSensor(0x0990, 0x0090);	  // MCU_DATA_0
  CamWriteCmosSensor(0x0990, 0x0091);	  // MCU_DATA_0
  
  CamWriteCmosSensor(0x098C, 0x2212);	  // MCU_ADDRESS [AE_MAX_DGAIN_AE1]
  //12-2
  //CamWriteCmosSensor(0x0990, 0x0064);	  // MCU_DATA_0
  //12-23
  CamWriteCmosSensor(0x0990, 0x007F);	  // MCU_DATA_0\
  //CamWriteCmosSensor(0x0990, 0x0080);	  // MCU_DATA_0
  
  ///LSC 11-23
  CamWriteCmosSensor(0x364E, 0x06F0);     
  CamWriteCmosSensor(0x3650, 0x8F8C);     
  CamWriteCmosSensor(0x3652, 0x5971);     
  CamWriteCmosSensor(0x3654, 0x4628);     
  CamWriteCmosSensor(0x3656, 0xFA32);     
  CamWriteCmosSensor(0x3658, 0x00D0);     
  CamWriteCmosSensor(0x365A, 0xBD0C);     
  CamWriteCmosSensor(0x365C, 0x1212);     
  CamWriteCmosSensor(0x365E, 0x4A2D);     
  CamWriteCmosSensor(0x3660, 0x90F3);     
  CamWriteCmosSensor(0x3662, 0x0110);     
  CamWriteCmosSensor(0x3664, 0x928C);     
  CamWriteCmosSensor(0x3666, 0x52D1);     
  CamWriteCmosSensor(0x3668, 0x6ACD);     
  CamWriteCmosSensor(0x366A, 0x9053);     
  CamWriteCmosSensor(0x366C, 0x0150);     
  CamWriteCmosSensor(0x366E, 0x8D2C);     
  CamWriteCmosSensor(0x3670, 0x50B1);     
  CamWriteCmosSensor(0x3672, 0x830A);     
  CamWriteCmosSensor(0x3674, 0xE492);     
  CamWriteCmosSensor(0x3676, 0x2FEB);     
  CamWriteCmosSensor(0x3678, 0xA5D0);     
  CamWriteCmosSensor(0x367A, 0x6F8E);     
  CamWriteCmosSensor(0x367C, 0x50D2);     
  CamWriteCmosSensor(0x367E, 0x8470);     
  CamWriteCmosSensor(0x3680, 0x234D);     
  CamWriteCmosSensor(0x3682, 0x0130);     
  CamWriteCmosSensor(0x3684, 0xE12A);     
  CamWriteCmosSensor(0x3686, 0xA712);     
  CamWriteCmosSensor(0x3688, 0x328F);    
  CamWriteCmosSensor(0x368A, 0x00AB);   
  CamWriteCmosSensor(0x368C, 0xE72F);     
  CamWriteCmosSensor(0x368E, 0xA40F);     
  CamWriteCmosSensor(0x3690, 0x1B92);     
  CamWriteCmosSensor(0x3692, 0x31F0);     
  CamWriteCmosSensor(0x3694, 0xCC29);     
  CamWriteCmosSensor(0x3696, 0x704F);     
  CamWriteCmosSensor(0x3698, 0x5AAE);     
  CamWriteCmosSensor(0x369A, 0xDFB1);     
  CamWriteCmosSensor(0x369C, 0x9AB1);     
  CamWriteCmosSensor(0x369E, 0x6452);     
  CamWriteCmosSensor(0x36A0, 0x434F);     
  CamWriteCmosSensor(0x36A2, 0xA494);     
  CamWriteCmosSensor(0x36A4, 0xCA90);     
  CamWriteCmosSensor(0x36A6, 0xAB15);     
  CamWriteCmosSensor(0x36A8, 0x0633);     
  CamWriteCmosSensor(0x36AA, 0xB70D);     
  CamWriteCmosSensor(0x36AC, 0xCFD4);     
  CamWriteCmosSensor(0x36AE, 0x4271);     
  CamWriteCmosSensor(0x36B0, 0xAEB5);     
  CamWriteCmosSensor(0x36B2, 0x5332);     
  CamWriteCmosSensor(0x36B4, 0xBC70);    
  CamWriteCmosSensor(0x36B6, 0xB754);     
  CamWriteCmosSensor(0x36B8, 0x2ED3);     
  CamWriteCmosSensor(0x36BA, 0x9195);     
  CamWriteCmosSensor(0x36BC, 0x67F2);     
  CamWriteCmosSensor(0x36BE, 0x118F);     
  CamWriteCmosSensor(0x36C0, 0x8354);     
  CamWriteCmosSensor(0x36C2, 0xE78F);     
  CamWriteCmosSensor(0x36C4, 0x9716);     
  CamWriteCmosSensor(0x36C6, 0xEF4A);     
  CamWriteCmosSensor(0x36C8, 0x5A32);     
  CamWriteCmosSensor(0x36CA, 0x8EB1);     
  CamWriteCmosSensor(0x36CC, 0xBD74);     
  CamWriteCmosSensor(0x36CE, 0x53D0);     
  CamWriteCmosSensor(0x36D0, 0x920E);     
  CamWriteCmosSensor(0x36D2, 0x8472);     
  CamWriteCmosSensor(0x36D4, 0x7C51);     
  CamWriteCmosSensor(0x36D6, 0x71B3);     
  CamWriteCmosSensor(0x36D8, 0xD7F4);     
  CamWriteCmosSensor(0x36DA, 0xB4AF);     
  CamWriteCmosSensor(0x36DC, 0x0231);     
  CamWriteCmosSensor(0x36DE, 0x04B3);     
  CamWriteCmosSensor(0x36E0, 0x5392);     
  CamWriteCmosSensor(0x36E2, 0xFAB3);     
  CamWriteCmosSensor(0x36E4, 0x2CCD);     
  CamWriteCmosSensor(0x36E6, 0x9971);     
  CamWriteCmosSensor(0x36E8, 0xC252);     
  CamWriteCmosSensor(0x36EA, 0xEF32);     
  CamWriteCmosSensor(0x36EC, 0x5934);     
  CamWriteCmosSensor(0x36EE, 0xACF4);     
  CamWriteCmosSensor(0x36F0, 0xC4F2);     
  CamWriteCmosSensor(0x36F2, 0xDF17);     
  CamWriteCmosSensor(0x36F4, 0x20B3);     
  CamWriteCmosSensor(0x36F6, 0x767A);     
  CamWriteCmosSensor(0x36F8, 0xC3B4);     
  CamWriteCmosSensor(0x36FA, 0x65B2);     
  CamWriteCmosSensor(0x36FC, 0xA237);     
  CamWriteCmosSensor(0x36FE, 0xBFD5);     
  CamWriteCmosSensor(0x3700, 0x33BA);     
  CamWriteCmosSensor(0x3702, 0xB8B4);     
  CamWriteCmosSensor(0x3704, 0x0E94);     
  CamWriteCmosSensor(0x3706, 0xB657);    
  CamWriteCmosSensor(0x3708, 0xDFB6);     
  CamWriteCmosSensor(0x370A, 0x6C5A);     
  CamWriteCmosSensor(0x370C, 0xB014);     
  CamWriteCmosSensor(0x370E, 0x9351);     
  CamWriteCmosSensor(0x3710, 0x8778);     
  CamWriteCmosSensor(0x3712, 0xB054);     
  CamWriteCmosSensor(0x3714, 0x0C7B);     
  CamWriteCmosSensor(0x3644, 0x0320); 
  CamWriteCmosSensor(0x3642, 0x0258); 
  
  CamWriteCmosSensor(0x3210, 0x01B8); 	// COLOR_PIPELINE_CONTROL

  
  ////kernel settings 
  CamWriteCmosSensor(0x098C, 0xAB36);	  // MCU_ADDRESS [HG_CLUSTERDC_TH]
  CamWriteCmosSensor(0x0990, 0x0014);  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2B66);	  // MCU_ADDRESS [HG_CLUSTER_DC_BM]
  CamWriteCmosSensor(0x0990, 0x2AF8);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB20);	  // MCU_ADDRESS [HG_LL_SAT1]
  CamWriteCmosSensor(0x0990, 0x0080);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB24);	  // MCU_ADDRESS [HG_LL_SAT2]
  CamWriteCmosSensor(0x0990, 0x0000);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB21);	  // MCU_ADDRESS [HG_LL_INTERPTHRESH1]
  CamWriteCmosSensor(0x0990, 0x000A);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB25);	  // MCU_ADDRESS [HG_LL_INTERPTHRESH2]
  CamWriteCmosSensor(0x0990, 0x002A);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB22);	  // MCU_ADDRESS [HG_LL_APCORR1]
  CamWriteCmosSensor(0x0990, 0x0005);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB26);	  // MCU_ADDRESS [HG_LL_APCORR2]
  CamWriteCmosSensor(0x0990, 0x0001);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB23);	  // MCU_ADDRESS [HG_LL_APTHRESH1]
  CamWriteCmosSensor(0x0990, 0x0004);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB27);	  // MCU_ADDRESS [HG_LL_APTHRESH2]
  CamWriteCmosSensor(0x0990, 0x0009);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2B28);	  // MCU_ADDRESS [HG_LL_BRIGHTNESSSTART]
  CamWriteCmosSensor(0x0990, 0x0BB8);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2B2A);	  // MCU_ADDRESS [HG_LL_BRIGHTNESSSTOP]
  CamWriteCmosSensor(0x0990, 0x2968);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB2C);	  // MCU_ADDRESS [HG_NR_START_R]
  CamWriteCmosSensor(0x0990, 0x00FF);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB30);	  // MCU_ADDRESS [HG_NR_STOP_R]
  CamWriteCmosSensor(0x0990, 0x00FF);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB2D);	  // MCU_ADDRESS [HG_NR_START_G]
  CamWriteCmosSensor(0x0990, 0x00FF);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB31);	  // MCU_ADDRESS [HG_NR_STOP_G]
  CamWriteCmosSensor(0x0990, 0x00FF);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB2E);	  // MCU_ADDRESS [HG_NR_START_B]
  CamWriteCmosSensor(0x0990, 0x00FF);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB32);	  // MCU_ADDRESS [HG_NR_STOP_B]
  CamWriteCmosSensor(0x0990, 0x00FF);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB2F);	  // MCU_ADDRESS [HG_NR_START_OL]
  CamWriteCmosSensor(0x0990, 0x000A);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB33);	  // MCU_ADDRESS [HG_NR_STOP_OL]
  CamWriteCmosSensor(0x0990, 0x0006);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB34);	  // MCU_ADDRESS [HG_NR_GAINSTART]
  CamWriteCmosSensor(0x0990, 0x0020);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB35);	  // MCU_ADDRESS [HG_NR_GAINSTOP]
  CamWriteCmosSensor(0x0990, 0x0091);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xA765);	  // MCU_ADDRESS [MODE_COMMONMODESETTINGS_FILTER_MODE]
  CamWriteCmosSensor(0x0990, 0x0006);	  // MCU_DATA_0
  
  
  
  
  
  CamWriteCmosSensor(0x098C, 0xAB37);	  // MCU_ADDRESS [HG_GAMMA_MORPH_CTRL]
  CamWriteCmosSensor(0x0990, 0x0003);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2B38);	  // MCU_ADDRESS [HG_GAMMASTARTMORPH]
  CamWriteCmosSensor(0x0990, 0x2968);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2B3A);	  // MCU_ADDRESS [HG_GAMMASTOPMORPH]
  CamWriteCmosSensor(0x0990, 0x2D50);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2B62);	  // MCU_ADDRESS [HG_FTB_START_BM]
  CamWriteCmosSensor(0x0990, 0xFFFE);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2B64);	  // MCU_ADDRESS [HG_FTB_STOP_BM]
  CamWriteCmosSensor(0x0990, 0xFFFF);	  // MCU_DATA_0
  
  ////GAMMA
  CamWriteCmosSensor(0x098C, 0xAB3C);	  // MCU_ADDRESS [HG_GAMMA_TABLE_A_0]
  CamWriteCmosSensor(0x0990, 0x0000);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB3D);	  // MCU_ADDRESS [HG_GAMMA_TABLE_A_1]
  CamWriteCmosSensor(0x0990, 0x0003);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB3E);	  // MCU_ADDRESS [HG_GAMMA_TABLE_A_2]
  CamWriteCmosSensor(0x0990, 0x000B);  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB3F);	  // MCU_ADDRESS [HG_GAMMA_TABLE_A_3]
  CamWriteCmosSensor(0x0990, 0x0022);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB40);	  // MCU_ADDRESS [HG_GAMMA_TABLE_A_4]
  CamWriteCmosSensor(0x0990, 0x004C);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB41);	  // MCU_ADDRESS [HG_GAMMA_TABLE_A_5]
  CamWriteCmosSensor(0x0990, 0x0068);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB42);	  // MCU_ADDRESS [HG_GAMMA_TABLE_A_6]
  CamWriteCmosSensor(0x0990, 0x007F);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB43);	  // MCU_ADDRESS [HG_GAMMA_TABLE_A_7]
  CamWriteCmosSensor(0x0990, 0x0093);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB44);	  // MCU_ADDRESS [HG_GAMMA_TABLE_A_8]
  CamWriteCmosSensor(0x0990, 0x00A3);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB45);	  // MCU_ADDRESS [HG_GAMMA_TABLE_A_9]
  CamWriteCmosSensor(0x0990, 0x00B1);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB46);	  // MCU_ADDRESS [HG_GAMMA_TABLE_A_10]
  CamWriteCmosSensor(0x0990, 0x00BE);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB47);	  // MCU_ADDRESS [HG_GAMMA_TABLE_A_11]
  CamWriteCmosSensor(0x0990, 0x00C9);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB48);	  // MCU_ADDRESS [HG_GAMMA_TABLE_A_12]
  CamWriteCmosSensor(0x0990, 0x00D2);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB49);	  // MCU_ADDRESS [HG_GAMMA_TABLE_A_13]
  CamWriteCmosSensor(0x0990, 0x00DB);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB4A);	  // MCU_ADDRESS [HG_GAMMA_TABLE_A_14]
  CamWriteCmosSensor(0x0990, 0x00E4);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB4B);	  // MCU_ADDRESS [HG_GAMMA_TABLE_A_15]
  CamWriteCmosSensor(0x0990, 0x00EB);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB4C);	  // MCU_ADDRESS [HG_GAMMA_TABLE_A_16]
  CamWriteCmosSensor(0x0990, 0x00F2);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB4D);	  // MCU_ADDRESS [HG_GAMMA_TABLE_A_17]
  CamWriteCmosSensor(0x0990, 0x00F9);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB4E);	  // MCU_ADDRESS [HG_GAMMA_TABLE_A_18]
  CamWriteCmosSensor(0x0990, 0x00FF);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB4F);	  // MCU_ADDRESS [HG_GAMMA_TABLE_B_0]
  CamWriteCmosSensor(0x0990, 0x0000);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB50);	  // MCU_ADDRESS [HG_GAMMA_TABLE_B_1]
  CamWriteCmosSensor(0x0990, 0x0013);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB51);	  // MCU_ADDRESS [HG_GAMMA_TABLE_B_2]
  CamWriteCmosSensor(0x0990, 0x0027);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB52);	  // MCU_ADDRESS [HG_GAMMA_TABLE_B_3]
  CamWriteCmosSensor(0x0990, 0x0043);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB53);	  // MCU_ADDRESS [HG_GAMMA_TABLE_B_4]
  CamWriteCmosSensor(0x0990, 0x0068);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB54);	  // MCU_ADDRESS [HG_GAMMA_TABLE_B_5]
  CamWriteCmosSensor(0x0990, 0x0081);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB55);	  // MCU_ADDRESS [HG_GAMMA_TABLE_B_6]
  CamWriteCmosSensor(0x0990, 0x0093);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB56);	  // MCU_ADDRESS [HG_GAMMA_TABLE_B_7]
  CamWriteCmosSensor(0x0990, 0x00A3);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB57);	  // MCU_ADDRESS [HG_GAMMA_TABLE_B_8]
  CamWriteCmosSensor(0x0990, 0x00B0);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB58);	  // MCU_ADDRESS [HG_GAMMA_TABLE_B_9]
  CamWriteCmosSensor(0x0990, 0x00BC);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB59);	  // MCU_ADDRESS [HG_GAMMA_TABLE_B_10]
  CamWriteCmosSensor(0x0990, 0x00C7);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB5A);	  // MCU_ADDRESS [HG_GAMMA_TABLE_B_11]
  CamWriteCmosSensor(0x0990, 0x00D1);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB5B);	  // MCU_ADDRESS [HG_GAMMA_TABLE_B_12]
  CamWriteCmosSensor(0x0990, 0x00DA);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB5C);	  // MCU_ADDRESS [HG_GAMMA_TABLE_B_13]
  CamWriteCmosSensor(0x0990, 0x00E2);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB5D);	  // MCU_ADDRESS [HG_GAMMA_TABLE_B_14]
  CamWriteCmosSensor(0x0990, 0x00E9);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB5E);	  // MCU_ADDRESS [HG_GAMMA_TABLE_B_15]
  CamWriteCmosSensor(0x0990, 0x00EF);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB5F);	  // MCU_ADDRESS [HG_GAMMA_TABLE_B_16]
  CamWriteCmosSensor(0x0990, 0x00F4);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB60);	  // MCU_ADDRESS [HG_GAMMA_TABLE_B_17]
  CamWriteCmosSensor(0x0990, 0x00FA);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xAB61);	  // MCU_ADDRESS [HG_GAMMA_TABLE_B_18]
  CamWriteCmosSensor(0x0990, 0x00FF);	  // MCU_DATA_0
  
  ///CCM&AWB
  CamWriteCmosSensor(0x098C, 0x2306);	  // MCU_ADDRESS [AWB_CCM_L_0]
  CamWriteCmosSensor(0x0990, 0x01D6);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2308);	  // MCU_ADDRESS [AWB_CCM_L_1]
  CamWriteCmosSensor(0x0990, 0xFF89);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x230A);	  // MCU_ADDRESS [AWB_CCM_L_2]
  CamWriteCmosSensor(0x0990, 0xFFA1);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x230C);	  // MCU_ADDRESS [AWB_CCM_L_3]
  CamWriteCmosSensor(0x0990, 0xFF73);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x230E);	  // MCU_ADDRESS [AWB_CCM_L_4]
  CamWriteCmosSensor(0x0990, 0x019C);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2310);	  // MCU_ADDRESS [AWB_CCM_L_5]
  CamWriteCmosSensor(0x0990, 0xFFF1);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2312);	  // MCU_ADDRESS [AWB_CCM_L_6]
  CamWriteCmosSensor(0x0990, 0xFFB0);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2314);	  // MCU_ADDRESS [AWB_CCM_L_7]
  CamWriteCmosSensor(0x0990, 0xFF2D);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2316);	  // MCU_ADDRESS [AWB_CCM_L_8]
  CamWriteCmosSensor(0x0990, 0x0223);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2318);	  // MCU_ADDRESS [AWB_CCM_L_9]
  CamWriteCmosSensor(0x0990, 0x001C);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x231A);	  // MCU_ADDRESS [AWB_CCM_L_10]
  CamWriteCmosSensor(0x0990, 0x0048);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2318);	  // MCU_ADDRESS [AWB_CCM_L_9]
  CamWriteCmosSensor(0x0990, 0x001C);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x231A);	  // MCU_ADDRESS [AWB_CCM_L_10]
  CamWriteCmosSensor(0x0990, 0x0038);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2318);	  // MCU_ADDRESS [AWB_CCM_L_9]
  CamWriteCmosSensor(0x0990, 0x001E);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x231A);	  // MCU_ADDRESS [AWB_CCM_L_10]
  CamWriteCmosSensor(0x0990, 0x0038);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2318);	  // MCU_ADDRESS [AWB_CCM_L_9]
  CamWriteCmosSensor(0x0990, 0x0022);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x231A);	  // MCU_ADDRESS [AWB_CCM_L_10]
  CamWriteCmosSensor(0x0990, 0x0038);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2318);	  // MCU_ADDRESS [AWB_CCM_L_9]
  CamWriteCmosSensor(0x0990, 0x002C);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x231A);	  // MCU_ADDRESS [AWB_CCM_L_10]
  CamWriteCmosSensor(0x0990, 0x0038);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2318);	  // MCU_ADDRESS [AWB_CCM_L_9]
  CamWriteCmosSensor(0x0990, 0x0024);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x231A);	  // MCU_ADDRESS [AWB_CCM_L_10]
  CamWriteCmosSensor(0x0990, 0x0038);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x231C);	  // MCU_ADDRESS [AWB_CCM_RL_0]
  CamWriteCmosSensor(0x0990, 0xFFCD);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x231E);	  // MCU_ADDRESS [AWB_CCM_RL_1]
  CamWriteCmosSensor(0x0990, 0x0023);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2320);	  // MCU_ADDRESS [AWB_CCM_RL_2]
  CamWriteCmosSensor(0x0990, 0x0010);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2322);	  // MCU_ADDRESS [AWB_CCM_RL_3]
  CamWriteCmosSensor(0x0990, 0x0026);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2324);	  // MCU_ADDRESS [AWB_CCM_RL_4]
  CamWriteCmosSensor(0x0990, 0xFFE9);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2326);	  // MCU_ADDRESS [AWB_CCM_RL_5]
  CamWriteCmosSensor(0x0990, 0xFFF1);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2328);	  // MCU_ADDRESS [AWB_CCM_RL_6]
  CamWriteCmosSensor(0x0990, 0x003A);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x232A);	  // MCU_ADDRESS [AWB_CCM_RL_7]
  CamWriteCmosSensor(0x0990, 0x005D);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x232C);	  // MCU_ADDRESS [AWB_CCM_RL_8]
  CamWriteCmosSensor(0x0990, 0xFF69);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x232E);	  // MCU_ADDRESS [AWB_CCM_RL_9]
  CamWriteCmosSensor(0x0990, 0x000C);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2330);	  // MCU_ADDRESS [AWB_CCM_RL_10]
  CamWriteCmosSensor(0x0990, 0xFFE4);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x232E);	  // MCU_ADDRESS [AWB_CCM_RL_9]
  CamWriteCmosSensor(0x0990, 0x000C);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2330);	  // MCU_ADDRESS [AWB_CCM_RL_10]
  CamWriteCmosSensor(0x0990, 0xFFF4);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x232E);	  // MCU_ADDRESS [AWB_CCM_RL_9]
  CamWriteCmosSensor(0x0990, 0x000A);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2330);	  // MCU_ADDRESS [AWB_CCM_RL_10]
  CamWriteCmosSensor(0x0990, 0xFFF4);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x232E);	  // MCU_ADDRESS [AWB_CCM_RL_9]
  CamWriteCmosSensor(0x0990, 0x0006);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2330);	  // MCU_ADDRESS [AWB_CCM_RL_10]
  CamWriteCmosSensor(0x0990, 0xFFF4);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x232E);	  // MCU_ADDRESS [AWB_CCM_RL_9]
  CamWriteCmosSensor(0x0990, 0xFFFC);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2330);	  // MCU_ADDRESS [AWB_CCM_RL_10]
  CamWriteCmosSensor(0x0990, 0xFFF4);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x232E);	  // MCU_ADDRESS [AWB_CCM_RL_9]
  CamWriteCmosSensor(0x0990, 0x0004);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0x2330);	  // MCU_ADDRESS [AWB_CCM_RL_10]
  CamWriteCmosSensor(0x0990, 0xFFF4);	  // MCU_DATA_0
  
  
  ///SOC2031_patch
  CamWriteCmosSensor(0x098C, 0x0415);	  // MCU_ADDRESS
  CamWriteCmosSensor(0x0990, 0xF601);
  CamWriteCmosSensor(0x0992, 0x42C1);
  CamWriteCmosSensor(0x0994, 0x0326);
  CamWriteCmosSensor(0x0996, 0x11F6);
  CamWriteCmosSensor(0x0998, 0x0143);
  CamWriteCmosSensor(0x099A, 0xC104);
  CamWriteCmosSensor(0x099C, 0x260A);
  CamWriteCmosSensor(0x099E, 0xCC04);
  CamWriteCmosSensor(0x098C, 0x0425);	  // MCU_ADDRESS
  CamWriteCmosSensor(0x0990, 0x33BD);
  CamWriteCmosSensor(0x0992, 0xA362);
  CamWriteCmosSensor(0x0994, 0xBD04);
  CamWriteCmosSensor(0x0996, 0x3339);
  CamWriteCmosSensor(0x0998, 0xC6FF);
  CamWriteCmosSensor(0x099A, 0xF701);
  CamWriteCmosSensor(0x099C, 0x6439);
  CamWriteCmosSensor(0x099E, 0xFE01);
  CamWriteCmosSensor(0x098C, 0x0435);	  // MCU_ADDRESS
  CamWriteCmosSensor(0x0990, 0x6918);
  CamWriteCmosSensor(0x0992, 0xCE03);
  CamWriteCmosSensor(0x0994, 0x25CC);
  CamWriteCmosSensor(0x0996, 0x0013);
  CamWriteCmosSensor(0x0998, 0xBDC2);
  CamWriteCmosSensor(0x099A, 0xB8CC);
  CamWriteCmosSensor(0x099C, 0x0489);
  CamWriteCmosSensor(0x099E, 0xFD03);
  CamWriteCmosSensor(0x098C, 0x0445);	  // MCU_ADDRESS
  CamWriteCmosSensor(0x0990, 0x27CC);
  CamWriteCmosSensor(0x0992, 0x0325);
  CamWriteCmosSensor(0x0994, 0xFD01);
  CamWriteCmosSensor(0x0996, 0x69FE);
  CamWriteCmosSensor(0x0998, 0x02BD);
  CamWriteCmosSensor(0x099A, 0x18CE);
  CamWriteCmosSensor(0x099C, 0x0339);
  CamWriteCmosSensor(0x099E, 0xCC00);
  CamWriteCmosSensor(0x098C, 0x0455);	  // MCU_ADDRESS
  CamWriteCmosSensor(0x0990, 0x11BD);
  CamWriteCmosSensor(0x0992, 0xC2B8);
  CamWriteCmosSensor(0x0994, 0xCC04);
  CamWriteCmosSensor(0x0996, 0xC8FD);
  CamWriteCmosSensor(0x0998, 0x0347);
  CamWriteCmosSensor(0x099A, 0xCC03);
  CamWriteCmosSensor(0x099C, 0x39FD);
  CamWriteCmosSensor(0x099E, 0x02BD);
  CamWriteCmosSensor(0x098C, 0x0465);	  // MCU_ADDRESS
  CamWriteCmosSensor(0x0990, 0xDE00);
  CamWriteCmosSensor(0x0992, 0x18CE);
  CamWriteCmosSensor(0x0994, 0x00C2);
  CamWriteCmosSensor(0x0996, 0xCC00);
  CamWriteCmosSensor(0x0998, 0x37BD);
  CamWriteCmosSensor(0x099A, 0xC2B8);
  CamWriteCmosSensor(0x099C, 0xCC04);
  CamWriteCmosSensor(0x099E, 0xEFDD);
  CamWriteCmosSensor(0x098C, 0x0475);	  // MCU_ADDRESS
  CamWriteCmosSensor(0x0990, 0xE6CC);
  CamWriteCmosSensor(0x0992, 0x00C2);
  CamWriteCmosSensor(0x0994, 0xDD00);
  CamWriteCmosSensor(0x0996, 0xC601);
  CamWriteCmosSensor(0x0998, 0xF701);
  CamWriteCmosSensor(0x099A, 0x64C6);
  CamWriteCmosSensor(0x099C, 0x03F7);
  CamWriteCmosSensor(0x099E, 0x0165);
  CamWriteCmosSensor(0x098C, 0x0485);	  // MCU_ADDRESS
  CamWriteCmosSensor(0x0990, 0x7F01);
  CamWriteCmosSensor(0x0992, 0x6639);
  CamWriteCmosSensor(0x0994, 0x3C3C);
  CamWriteCmosSensor(0x0996, 0x3C34);
  CamWriteCmosSensor(0x0998, 0xCC32);
  CamWriteCmosSensor(0x099A, 0x3EBD);
  CamWriteCmosSensor(0x099C, 0xA558);
  CamWriteCmosSensor(0x099E, 0x30ED);
  CamWriteCmosSensor(0x098C, 0x0495);	  // MCU_ADDRESS
  CamWriteCmosSensor(0x0990, 0x04BD);
  CamWriteCmosSensor(0x0992, 0xB2D7);
  CamWriteCmosSensor(0x0994, 0x30E7);
  CamWriteCmosSensor(0x0996, 0x06CC);
  CamWriteCmosSensor(0x0998, 0x323E);
  CamWriteCmosSensor(0x099A, 0xED00);
  CamWriteCmosSensor(0x099C, 0xEC04);
  CamWriteCmosSensor(0x099E, 0xBDA5);
  CamWriteCmosSensor(0x098C, 0x04A5);	  // MCU_ADDRESS
  CamWriteCmosSensor(0x0990, 0x44CC);
  CamWriteCmosSensor(0x0992, 0x3244);
  CamWriteCmosSensor(0x0994, 0xBDA5);
  CamWriteCmosSensor(0x0996, 0x585F);
  CamWriteCmosSensor(0x0998, 0x30ED);
  CamWriteCmosSensor(0x099A, 0x02CC);
  CamWriteCmosSensor(0x099C, 0x3244);
  CamWriteCmosSensor(0x099E, 0xED00);
  CamWriteCmosSensor(0x098C, 0x04B5);	  // MCU_ADDRESS
  CamWriteCmosSensor(0x0990, 0xF601);
  CamWriteCmosSensor(0x0992, 0xD54F);
  CamWriteCmosSensor(0x0994, 0xEA03);
  CamWriteCmosSensor(0x0996, 0xAA02);
  CamWriteCmosSensor(0x0998, 0xBDA5);
  CamWriteCmosSensor(0x099A, 0x4430);
  CamWriteCmosSensor(0x099C, 0xE606);
  CamWriteCmosSensor(0x099E, 0x3838);
  CamWriteCmosSensor(0x098C, 0x04C5);	  // MCU_ADDRESS
  CamWriteCmosSensor(0x0990, 0x3831);
  CamWriteCmosSensor(0x0992, 0x39BD);
  CamWriteCmosSensor(0x0994, 0xD661);
  CamWriteCmosSensor(0x0996, 0xF602);
  CamWriteCmosSensor(0x0998, 0xF4C1);
  CamWriteCmosSensor(0x099A, 0x0126);
  CamWriteCmosSensor(0x099C, 0x0BFE);
  CamWriteCmosSensor(0x099E, 0x02BD);
  CamWriteCmosSensor(0x098C, 0x04D5);	  // MCU_ADDRESS
  CamWriteCmosSensor(0x0990, 0xEE10);
  CamWriteCmosSensor(0x0992, 0xFC02);
  CamWriteCmosSensor(0x0994, 0xF5AD);
  CamWriteCmosSensor(0x0996, 0x0039);
  CamWriteCmosSensor(0x0998, 0xF602);
  CamWriteCmosSensor(0x099A, 0xF4C1);
  CamWriteCmosSensor(0x099C, 0x0226);
  CamWriteCmosSensor(0x099E, 0x0AFE);
  CamWriteCmosSensor(0x098C, 0x04E5);	  // MCU_ADDRESS
  CamWriteCmosSensor(0x0990, 0x02BD);
  CamWriteCmosSensor(0x0992, 0xEE10);
  CamWriteCmosSensor(0x0994, 0xFC02);
  CamWriteCmosSensor(0x0996, 0xF7AD);
  CamWriteCmosSensor(0x0998, 0x0039);
  CamWriteCmosSensor(0x099A, 0x3CBD);
  CamWriteCmosSensor(0x099C, 0xB059);
  CamWriteCmosSensor(0x099E, 0xCC00);
  CamWriteCmosSensor(0x098C, 0x04F5);	  // MCU_ADDRESS
  CamWriteCmosSensor(0x0990, 0x28BD);
  CamWriteCmosSensor(0x0992, 0xA558);
  CamWriteCmosSensor(0x0994, 0x8300);
  CamWriteCmosSensor(0x0996, 0x0027);
  CamWriteCmosSensor(0x0998, 0x0BCC);
  CamWriteCmosSensor(0x099A, 0x0026);
  CamWriteCmosSensor(0x099C, 0x30ED);
  CamWriteCmosSensor(0x099E, 0x00C6);
  CamWriteCmosSensor(0x098C, 0x0505);	  // MCU_ADDRESS
  CamWriteCmosSensor(0x0990, 0x03BD);
  CamWriteCmosSensor(0x0992, 0xA544);
  CamWriteCmosSensor(0x0994, 0x3839);
  //DELAY = 1
  kal_sleep_task(1);
  CamWriteCmosSensor(0x098C, 0x2006);	  // MCU_ADDRESS [MON_ARG1]
  CamWriteCmosSensor(0x0990, 0x0415);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xA005);	  // MCU_ADDRESS [MON_CMD]
  CamWriteCmosSensor(0x0990, 0x0001);	  // MCU_DATA_0


  
  for(i = 100; i>0 ;i--)
  	{
  	   kal_sleep_task(2);
	   //11-25
 	   CamWriteCmosSensor(0x098C, 0xA204);
       status = CamReadCmosSensor(0x0990);
	   if(status !=0)
	   	{
	   	   break;
	   	}
  	}

  #ifdef __MT9D115_DEBUG_TRACE__
  if (!i) kal_print_string_trace(MOD_ENG, TRACE_WARNING, "set cmd time out");
  #endif
  //DELAY = 10
  //kal_sleep_task(3);
  
  
  
  ////optimize
  
  CamWriteCmosSensor(0x098C, 0xAB20);	  // MCU_ADDRESS [HG_LL_SAT1]
  //CamWriteCmosSensor(0x0990, 0x0059);	  // MCU_DATA_0
  //12-3
  CamWriteCmosSensor(0x0990, 0x0079);	  // MCU_DATA_0
  
  CamWriteCmosSensor(0x098C, 0xA20D);	  // MCU_ADDRESS [AE_MIN_VIRTGAIN]
  CamWriteCmosSensor(0x0990, 0x0020);	  // MCU_DATA_0 1X gain
  
  CamWriteCmosSensor(0x098C, 0xA206);	  // MCU_ADDRESS [AE_TARGET]
  CamWriteCmosSensor(0x0990, 0x0048);	  // MCU_DATA_0 AE_TARGET
  
  CamWriteCmosSensor(0x098C, 0xA11E);	  // MCU_ADDRESS [SEQ_PREVIEW_1_FD]
  CamWriteCmosSensor(0x0990, 0x0002);	  // MCU_DATA_0
  
  CamWriteCmosSensor(0x098C, 0xA404);	  // MCU_ADDRESS [FD_MODE]--50Hz
  CamWriteCmosSensor(0x0990, 0x00f1);	  // MCU_DATA_0


  //12-3
  
  //Speed up AE&AWB
  CamWriteCmosSensor(0x098C, 0xA108);	  // MCU_ADDRESS [SEQ_AE_CONTSTEP]
  CamWriteCmosSensor(0x0990, 0x0001);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xA10A);	  // MCU_ADDRESS [SEQ_AE_FASTSTEP]
  CamWriteCmosSensor(0x0990, 0x0001);	  // MCU_DATA_0
  CamWriteCmosSensor(0x098C, 0xA10C);	  // MCU_ADDRESS [SEQ_AWB_CONTSTEP]
  CamWriteCmosSensor(0x0990, 0x0001);	  // MCU_DATA_0
  //
  
  //  POLL	MON_PATCH_ID_0 =>  0x00, 0x01
  CamWriteCmosSensor(0x0018, 0x0028);	  // STANDBY_CONTROL
  //  POLL	SEQ_STATE =>  0x03
  //DELAY = 10
  kal_sleep_task(3);
  //CamWriteCmosSensor(0x098C, 0xA103);	  // MCU_ADDRESS [SEQ_CMD]
  //CamWriteCmosSensor(0x0990, 0x0006);	  // MCU_DATA_0
  //DELAY = 100
  //kal_sleep_task(25);
  MT9D115SetCmd(6);
  //11-25
  //kal_sleep_task(5);
  //CamWriteCmosSensor(0x098C, 0xA103);	  // MCU_ADDRESS [SEQ_CMD]
  //CamWriteCmosSensor(0x0990, 0x0005);	  // MCU_DATA_0
  //DELAY = 100
  //kal_sleep_task(25);
  //11-24
  //MT9D115SetCmd(5);

  //12-2
  MT9D115SetCmd(5);
  
  //MT9D115_sensor.preview_pclk = 520;


}

/*************************************************************************
* FUNCTION
*   MT9D115SetMirrorFlip
*
* DESCRIPTION
*   This function config the HVmirror of image sensor.
*
*************************************************************************/
 static void MT9D115SetMirrorFlip(IMAGE_SENSOR_MIRROR_ENUM ImageMirrorFlip)
 {   
     kal_uint16 iTemp = 0;
     
	 switch (ImageMirrorFlip)
	 {
	 case IMAGE_SENSOR_MIRROR_NORMAL:
		 iTemp = 0x00;
		 break;
	 case IMAGE_SENSOR_MIRROR_H:
		 iTemp = 0x01;
		 break;
	 case IMAGE_SENSOR_MIRROR_V:
		 iTemp = 0x02;
		 break;
	 case IMAGE_SENSOR_MIRROR_HV:
		 iTemp = 0x03;
		 break;
	 default:
		 ASSERT(0);
	 }

	 CamWriteCmosSensor(0x098C, 0x2717); 
     CamWriteCmosSensor(0x0990, 0x046C|iTemp);
  
  
     CamWriteCmosSensor(0x098C, 0x272D); 
     CamWriteCmosSensor(0x0990, 0x0024|iTemp);  
     MT9D115SetCmd(6); /* refresh mode */
 }   /* MT9D115SetMirrorFlip */





/*************************************************************************
* FUNCTION
*    MT9D115EV
*
* DESCRIPTION
*    MT9D115 EV setting.
*
* PARAMETERS
*    Para
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
	

static MM_ERROR_CODE_ENUM MT9D115EV(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    P_CAL_FEATURE_TYPE_ENUM_STRUCT EvPara = &Out->FeatureInfo.FeatureEnum;
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION | CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    EvPara->IsSupport = KAL_TRUE;
    EvPara->ItemCount = 9;
    EvPara->SupportItem[0] = CAM_EV_NEG_4_3;
    EvPara->SupportItem[1] = CAM_EV_NEG_3_3;
    EvPara->SupportItem[2] = CAM_EV_NEG_2_3;
    EvPara->SupportItem[3] = CAM_EV_NEG_1_3;
    EvPara->SupportItem[4] = CAM_EV_ZERO;
    EvPara->SupportItem[5] = CAM_EV_POS_1_3;
    EvPara->SupportItem[6] = CAM_EV_POS_2_3;
    EvPara->SupportItem[7] = CAM_EV_POS_3_3;
    EvPara->SupportItem[8] = CAM_EV_POS_4_3;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
#ifdef MT9D115_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"EV:%d",iEvTemp);
#endif

  
    switch (In->FeatureSetValue)
    {
        case CAM_EV_NEG_4_3:    // -2.0 EV
            CamWriteCmosSensor(0x098C, 0xA24F); 	// MCU_ADDRESS [AE_BASETARGET]
            CamWriteCmosSensor(0x0990, 0x0028); 	// MCU_DATA_0
            break;
        case CAM_EV_NEG_3_3:    // -1.5 EV
            CamWriteCmosSensor(0x098C, 0xA24F); 	// MCU_ADDRESS [AE_BASETARGET]
            CamWriteCmosSensor(0x0990, 0x0030); 	// MCU_DATA_0
            break;
        case CAM_EV_NEG_2_3:    // -1.0 EV
            CamWriteCmosSensor(0x098C, 0xA24F); 	// MCU_ADDRESS [AE_BASETARGET]
            CamWriteCmosSensor(0x0990, 0x0038); 	// MCU_DATA_0
            break;
        case CAM_EV_NEG_1_3:    // -0.5 EV
            CamWriteCmosSensor(0x098C, 0xA24F); 	// MCU_ADDRESS [AE_BASETARGET]
            CamWriteCmosSensor(0x0990, 0x0040); 	// MCU_DATA_0
            break;
        case CAM_EV_ZERO:   	// +0 EV
            CamWriteCmosSensor(0x098C, 0xA24F); 	// MCU_ADDRESS [AE_BASETARGET]
            CamWriteCmosSensor(0x0990, 0x0048); 	// MCU_DATA_0
            break;
        case CAM_EV_POS_1_3:    // +0.5 EV
            CamWriteCmosSensor(0x098C, 0xA24F); 	// MCU_ADDRESS [AE_BASETARGET]
            CamWriteCmosSensor(0x0990, 0x0050); 	// MCU_DATA_0
            break;
        case CAM_EV_POS_2_3:    // +1.0 EV
            CamWriteCmosSensor(0x098C, 0xA24F); 	// MCU_ADDRESS [AE_BASETARGET]
            CamWriteCmosSensor(0x0990, 0x0058); 	// MCU_DATA_0
            break;
        case CAM_EV_POS_3_3:    // +1.5 EV
            CamWriteCmosSensor(0x098C, 0xA24F); 	// MCU_ADDRESS [AE_BASETARGET]
            CamWriteCmosSensor(0x0990, 0x0060); 	// MCU_DATA_0
            break;
        case CAM_EV_POS_4_3:    // +2.0 EV
            CamWriteCmosSensor(0x098C, 0xA24F); 	// MCU_ADDRESS [AE_BASETARGET]
            CamWriteCmosSensor(0x0990, 0x0068); 	// MCU_DATA_0
            break;
        default:
			return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
            break;
    }
  
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    MT9D115WB
*
* DESCRIPTION
*    MT9D115 WB setting.
*
* PARAMETERS
*    Para
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM MT9D115WB(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    P_CAL_FEATURE_TYPE_ENUM_STRUCT WBPara = &Out->FeatureInfo.FeatureEnum;
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION | CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    WBPara->IsSupport = KAL_TRUE;
    WBPara->ItemCount = 6;
    WBPara->SupportItem[0] = CAM_WB_AUTO;
    WBPara->SupportItem[1] = CAM_WB_CLOUD;
    WBPara->SupportItem[2] = CAM_WB_DAYLIGHT;
    WBPara->SupportItem[3] = CAM_WB_INCANDESCENCE;
    WBPara->SupportItem[4] = CAM_WB_FLUORESCENT;
    WBPara->SupportItem[5] = CAM_WB_TUNGSTEN;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
#ifdef MT9D115_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"WB:%d",WBTemp);
#endif

   
    switch (In->FeatureSetValue)
    {
        case CAM_WB_AUTO:   // enable AWB
            // CAM_WB_AUTO mode should not update R/G/B gains
            CamWriteCmosSensor(0x098c,0xA34A);
            CamWriteCmosSensor(0x0990,0x59);
            CamWriteCmosSensor(0x098c,0xA34B);
            CamWriteCmosSensor(0x0990,0xB6);
            CamWriteCmosSensor(0x098c,0xA34C);
            CamWriteCmosSensor(0x0990,0x59);
            CamWriteCmosSensor(0x098c,0xA34D);
            CamWriteCmosSensor(0x0990,0xA6);
            CamWriteCmosSensor(0x098c,0xA351);
            CamWriteCmosSensor(0x0990,0x00);
            CamWriteCmosSensor(0x098c,0xA352);
            CamWriteCmosSensor(0x0990,0x7F);
            break;
        case CAM_WB_CLOUD:
            CamWriteCmosSensor(0x098c,0xA34A);
        	CamWriteCmosSensor(0x0990,0x8B);
        	CamWriteCmosSensor(0x098c,0xA34B);
        	CamWriteCmosSensor(0x0990,0x8B);
        	CamWriteCmosSensor(0x098c,0xA34C);
        	CamWriteCmosSensor(0x0990,0x97);
        	CamWriteCmosSensor(0x098c,0xA34D);
        	CamWriteCmosSensor(0x0990,0x97);
        	CamWriteCmosSensor(0x098c,0xA351);
        	CamWriteCmosSensor(0x0990,0x6F);
        	CamWriteCmosSensor(0x098c,0xA352);
        	CamWriteCmosSensor(0x0990,0x6F);
        	
        	CamWriteCmosSensor(0x098c,0xA353);
        	CamWriteCmosSensor(0x0990,0x6F);
            break;
        case CAM_WB_DAYLIGHT:
            CamWriteCmosSensor(0x098c,0xA34A);
            CamWriteCmosSensor(0x0990,0x8D);
            CamWriteCmosSensor(0x098c,0xA34B);
            CamWriteCmosSensor(0x0990,0x8D);
            CamWriteCmosSensor(0x098c,0xA34C);
            CamWriteCmosSensor(0x0990,0x7A);
            CamWriteCmosSensor(0x098c,0xA34D);
            CamWriteCmosSensor(0x0990,0x7A);
            CamWriteCmosSensor(0x098c,0xA351);
            CamWriteCmosSensor(0x0990,0x7F);
            CamWriteCmosSensor(0x098c,0xA352);
            CamWriteCmosSensor(0x0990,0x7F);
            
            CamWriteCmosSensor(0x098c,0xA353);
            CamWriteCmosSensor(0x0990,0x7F);
            break;
        case CAM_WB_INCANDESCENCE:
            CamWriteCmosSensor(0x098c,0xA34A);
            CamWriteCmosSensor(0x0990,0x74);
            CamWriteCmosSensor(0x098c,0xA34B);
            CamWriteCmosSensor(0x0990,0x74);
            CamWriteCmosSensor(0x098c,0xA34C);
            CamWriteCmosSensor(0x0990,0xA3);
            CamWriteCmosSensor(0x098c,0xA34D);
            CamWriteCmosSensor(0x0990,0xA3);
            CamWriteCmosSensor(0x098c,0xA351);
            CamWriteCmosSensor(0x0990,0x10);
            CamWriteCmosSensor(0x098c,0xA352);
            CamWriteCmosSensor(0x0990,0x10);
            
            CamWriteCmosSensor(0x098c,0xA353);
            CamWriteCmosSensor(0x0990,0x10);
            break;
        case CAM_WB_FLUORESCENT:
			CamWriteCmosSensor(0x098c,0xA34A);
			CamWriteCmosSensor(0x0990,0x8D);
			CamWriteCmosSensor(0x098c,0xA34B);
			CamWriteCmosSensor(0x0990,0x8D);
			CamWriteCmosSensor(0x098c,0xA34C);
			CamWriteCmosSensor(0x0990,0x8C);
			CamWriteCmosSensor(0x098c,0xA34D);
			CamWriteCmosSensor(0x0990,0x8C);
			CamWriteCmosSensor(0x098c,0xA351);
			CamWriteCmosSensor(0x0990,0x79);
			CamWriteCmosSensor(0x098c,0xA352);
			CamWriteCmosSensor(0x0990,0x79);
			
			CamWriteCmosSensor(0x098c,0xA353);
			CamWriteCmosSensor(0x0990,0x79);

            break;
        case CAM_WB_TUNGSTEN:
			CamWriteCmosSensor(0x098c,0xA34A);
			CamWriteCmosSensor(0x0990,0x68);
			CamWriteCmosSensor(0x098c,0xA34B);
			CamWriteCmosSensor(0x0990,0x68);
			CamWriteCmosSensor(0x098c,0xA34C);
			CamWriteCmosSensor(0x0990,0xB1);
			CamWriteCmosSensor(0x098c,0xA34D);
			CamWriteCmosSensor(0x0990,0xB1);
			CamWriteCmosSensor(0x098c,0xA351);
			CamWriteCmosSensor(0x0990,0x00);
			CamWriteCmosSensor(0x098c,0xA352);
			CamWriteCmosSensor(0x0990,0x00);
			
			CamWriteCmosSensor(0x098c,0xA353);
			CamWriteCmosSensor(0x0990,0x00);

            break;
        case CAM_WB_MANUAL:
        default:
			return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
            break;
    }
  }
  
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    MT9D115Effect
*
* DESCRIPTION
*    MT9D115 Effect setting.
*
* PARAMETERS
*    Para
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM MT9D115Effect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    P_CAL_FEATURE_TYPE_ENUM_STRUCT EffectPara = &Out->FeatureInfo.FeatureEnum;
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION | CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    EffectPara->IsSupport = KAL_TRUE;
    EffectPara->ItemCount = 8;
    EffectPara->SupportItem[0] = CAM_EFFECT_ENC_NORMAL;
    EffectPara->SupportItem[1] = CAM_EFFECT_ENC_GRAYSCALE;
    EffectPara->SupportItem[2] = CAM_EFFECT_ENC_SEPIA;
    EffectPara->SupportItem[3] = CAM_EFFECT_ENC_SEPIAGREEN;
    EffectPara->SupportItem[4] = CAM_EFFECT_ENC_SEPIABLUE;
    EffectPara->SupportItem[5] = CAM_EFFECT_ENC_COLORINV;
    EffectPara->SupportItem[6] = CAM_EFFECT_ENC_GRAYINV;
    EffectPara->SupportItem[7] = CAM_EFFECT_ENC_EMBOSSMENT;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
  kal_uint8 EffectTemp = In->FeatureSetValue;
#ifdef MT9D115_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO,"Effect:%d",EffectTemp);
#endif
 
    switch (In->FeatureSetValue)
    {
        case CAM_EFFECT_ENC_NORMAL:
            CamWriteCmosSensor(0x098C, 0x2759); 	// MCU_ADDRESS [MODE_SPEC_EFFECTS_A]
            CamWriteCmosSensor(0x0990, 0x6440); 	// MCU_DATA_0
            CamWriteCmosSensor(0x098C, 0x275B); 	// MCU_ADDRESS [MODE_SPEC_EFFECTS_B]
            CamWriteCmosSensor(0x0990, 0x6440); 	// MCU_DATA_0
            MT9D115SetCmd(5);
            break;
        case CAM_EFFECT_ENC_GRAYSCALE:
			CamWriteCmosSensor(0x098C, 0x2759);	// MCU_ADDRESS [MODE_SPEC_EFFECTS_A]
			CamWriteCmosSensor(0x0990, 0x6441);	// MCU_DATA_0
			CamWriteCmosSensor(0x098C, 0x275B);	// MCU_ADDRESS [MODE_SPEC_EFFECTS_B]
			CamWriteCmosSensor(0x0990, 0x6441);	// MCU_DATA_0
			MT9D115SetCmd(5);

            break;
        case CAM_EFFECT_ENC_SEPIA:
			CamWriteCmosSensor(0x098C, 0x2759);	// MCU_ADDRESS [MODE_SPEC_EFFECTS_A]
			CamWriteCmosSensor(0x0990, 0x6442);	// MCU_DATA_0
			CamWriteCmosSensor(0x098C, 0x275B);	// MCU_ADDRESS [MODE_SPEC_EFFECTS_B]
			CamWriteCmosSensor(0x0990, 0x6442);	// MCU_DATA_0
			CamWriteCmosSensor(0x098C, 0x2763);	// MCU_ADDRESS [MODE_COMMONMODESETTINGS_FX_SEPIA_SETTINGS]
			CamWriteCmosSensor(0x0990, 0x015E);	// MCU_DATA_0
			MT9D115SetCmd(5);

            break;
        case CAM_EFFECT_ENC_SEPIAGREEN:
			CamWriteCmosSensor(0x098C, 0x2759);	// MCU_ADDRESS [MODE_SPEC_EFFECTS_A]
			CamWriteCmosSensor(0x0990, 0x6442);	// MCU_DATA_0
			CamWriteCmosSensor(0x098C, 0x275B);	// MCU_ADDRESS [MODE_SPEC_EFFECTS_B]
			CamWriteCmosSensor(0x0990, 0x6442);	// MCU_DATA_0
			CamWriteCmosSensor(0x098C, 0x2763);	// MCU_ADDRESS [MODE_COMMONMODESETTINGS_FX_SEPIA_SETTINGS]
			CamWriteCmosSensor(0x0990, 0x8181);	// MCU_DATA_0
			MT9D115SetCmd(5);
            break;
        case CAM_EFFECT_ENC_SEPIABLUE:
			CamWriteCmosSensor(0x098C, 0x2759);	// MCU_ADDRESS [MODE_SPEC_EFFECTS_A]
			CamWriteCmosSensor(0x0990, 0x6442);	// MCU_DATA_0
			CamWriteCmosSensor(0x098C, 0x275B);	// MCU_ADDRESS [MODE_SPEC_EFFECTS_B]
			CamWriteCmosSensor(0x0990, 0x6442);	// MCU_DATA_0
			CamWriteCmosSensor(0x098C, 0x2763);	// MCU_ADDRESS [MODE_COMMONMODESETTINGS_FX_SEPIA_SETTINGS]
			CamWriteCmosSensor(0x0990, 0x48EE);	// MCU_DATA_0
			MT9D115SetCmd(5);
            break;
        case CAM_EFFECT_ENC_COLORINV:
			CamWriteCmosSensor(0x098C, 0x2759);	// MCU_ADDRESS [MODE_SPEC_EFFECTS_A]
			CamWriteCmosSensor(0x0990, 0x6443);	// MCU_DATA_0
			CamWriteCmosSensor(0x098C, 0x275B);	// MCU_ADDRESS [MODE_SPEC_EFFECTS_B]
			CamWriteCmosSensor(0x0990, 0x6443);	// MCU_DATA_0
			MT9D115SetCmd(5);

            break;
        case CAM_EFFECT_ENC_GRAYINV:
           // CamWriteCmosSensor(0xB6, 0x20);
            break;
        case CAM_EFFECT_ENC_EMBOSSMENT:
           // CamWriteCmosSensor(0xB6, 0x08);
            break;
        default:
            return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
			break;
    }
  }   
  
  return MM_ERROR_NONE;
}


static void MT9D115AeEnable(kal_bool Enable)
{
   kal_uint16 reg_temp = 0;
   
   if(MT9D115Sensor.BypassAe)
   	{
   	   Enable = KAL_FALSE;
   	}

   if(Enable)
   	{
   	   CamWriteCmosSensor(0x098C, 0xA102);
       reg_temp = CamReadCmosSensor(0x0990);// get the current reg value.

	   reg_temp = (reg_temp | 0x01); //enable the ae

	   CamWriteCmosSensor(0x098C, 0xA102);
	   CamWriteCmosSensor(0x0990, reg_temp);
	   
   	}
   else
   	{
   	   CamWriteCmosSensor(0x098C, 0xA102);
       reg_temp = CamReadCmosSensor(0x0990);// get the current reg value.
       
       reg_temp = (reg_temp & (~0x01)); //disable the ae

	   CamWriteCmosSensor(0x098C, 0xA102);
	   CamWriteCmosSensor(0x0990, reg_temp);
   	}
}


static void MT9D115AwbEnable(kal_bool Enable)
{
   kal_uint16 reg_temp = 0;
   
   if(MT9D115Sensor.BypassAwb)
   	{
   	   Enable = KAL_FALSE;
   	}
   if(Enable)
   	{
   	   CamWriteCmosSensor(0x098C, 0xA102);
       reg_temp = CamReadCmosSensor(0x0990);// get the current reg value.

	   reg_temp = (reg_temp | 0x02); //enable the ae

	   CamWriteCmosSensor(0x098C, 0xA102);
	   CamWriteCmosSensor(0x0990, reg_temp);
   	}
   else
   	{
   	   CamWriteCmosSensor(0x098C, 0xA102);
       reg_temp = CamReadCmosSensor(0x0990);// get the current reg value.
       
       reg_temp = (reg_temp & (~0x02)); //disable the ae

	   CamWriteCmosSensor(0x098C, 0xA102);
	   CamWriteCmosSensor(0x0990, reg_temp);
   	}
}



/*************************************************************************
* FUNCTION
*   MT9D115SetAeBaseShutter
*
* DESCRIPTION
*   This function is to set frame count register .
*
*************************************************************************/
static void MT9D115SetAeBaseShutter(CAL_CAMERA_BANDING_FREQ_ENUM BandingFreq)
{
   // kal_uint16 Frame_Count,min_fps = 100;
	//kal_uint32 banding = MT9D115_NUM_50HZ;

	// TODO: Right   ???

	if (BandingFreq == CAM_BANDING_50HZ)
	{
	//	banding = MT9D115_NUM_50HZ;

		CamWriteCmosSensor(0x098C, 0xA404); 	// MCU_ADDRESS [FD_MODE]
        CamWriteCmosSensor(0x0990, 0x00f1); 	// MCU_DATA_0
        MT9D115SetCmd(6);
	}
	else
	{
	//	banding = MT9D115_NUM_60HZ;

		CamWriteCmosSensor(0x098C, 0xA404); 	// MCU_ADDRESS [FD_MODE]
        CamWriteCmosSensor(0x0990, 0x0091); 	// MCU_DATA_0
        MT9D115SetCmd(6);
	}

   // Frame_Count = banding * MT9D115_FRAME_RATE_UNIT / MinFrameRate;
	
#ifdef __MT9D115_DEBUG_INFO__
   // kal_wap_trace(MOD_ENG,TRACE_INFO, "min_fps:%d,Frame_Count:%x",MinFrameRate/MT9D115_FRAME_RATE_UNIT,Frame_Count);
#endif

    /*Block 01: 0x11  Max shutter step,for Min frame rate */
   // MT9D115_set_page(1);
   // CamWriteCmosSensor(0x11,Frame_Count&0xFF);
}/* MT9D115SetAeBaseShutter */



/*************************************************************************
* FUNCTION
*    MT9D115Banding
*
* DESCRIPTION
*    This function get capture size
*
* PARAMETERS
*    In, Out, out_len, r_out_len
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM MT9D115Banding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  P_CAL_FEATURE_TYPE_ENUM_STRUCT Banding = (P_CAL_FEATURE_TYPE_ENUM_STRUCT)&(Out->FeatureInfo.FeatureEnum);

  switch (In->FeatureCtrlCode)
  {
    case CAL_FEATURE_QUERY_OPERATION:
      Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
      Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|
                               CAL_FEATURE_GET_OPERATION|
                               CAL_FEATURE_QUERY_OPERATION;
      Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
      Banding->IsSupport = KAL_TRUE;
      Banding->ItemCount = 2;
      Banding->SupportItem[0] = CAM_BANDING_50HZ;
      Banding->SupportItem[1] = CAM_BANDING_60HZ;
      break;
	case CAL_FEATURE_SET_OPERATION:
	//	if(MT9D115_g_iBanding == In->FeatureSetValue)
        return KAL_TRUE;

 //   MT9D115_g_iBanding = In->FeatureSetValue;
    //MT9D115SetShutterStep();
    MT9D115SetAeBaseShutter(In->FeatureSetValue);
	
		break;
		
  }
  return MM_ERROR_NONE;
}

void MT9D115GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT SensorInfo)
{
	SensorInfo->SensorId			=	MT9D115_SENSOR_ID;

	/* Not used now */
	//SensorInfo->ResetActiveHigh	=	KAL_FALSE;
	//SensorInfo->PowerOnActiveHigh	=	KAL_FALSE;

	SensorInfo->SensorIf			=	IMAGE_SENSOR_IF_PARALLEL;
	SensorInfo->PreviewNormalDataFormat	=	IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
	SensorInfo->PreviewHMirrorDataFormat 	= 	IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
	SensorInfo->PreviewVMirrorDataFormat 	= 	IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
	SensorInfo->PreviewHVMirrorDataFormat 	= 	IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;  

	SensorInfo->CaptureDataFormat	=	IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
	// TODO: ENABLE_CAMERA_INDATA_FORMAT ???

	SensorInfo->PixelClkPolarity	=	POLARITY_LOW;
	SensorInfo->HsyncPolarity		=	POLARITY_LOW;	/* Active High, it's inversed. */
	SensorInfo->VsyncPolarity		=	POLARITY_HIGH;

//	SensorInfo->DrivingCurrent		=	ISP_DRIVING_8MA;

#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
	SensorInfo->PreviewMclkFreq 	= 	26000000;
	SensorInfo->CaptureMclkFreq 	= 	26000000;
	SensorInfo->VideoMclkFreq 		= 	26000000;
#else
	SensorInfo->PreviewMclkFreq	=	24000000;
	SensorInfo->CaptureMclkFreq	=	24000000;
	SensorInfo->VideoMclkFreq		=	24000000;
#endif

	SensorInfo->PreviewWidth		=	MT9D115_IMAGE_SENSOR_PV_WIDTH;
	SensorInfo->PreviewHeight		=	MT9D115_IMAGE_SENSOR_PV_HEIGHT;
	SensorInfo->FullWidth			=	MT9D115_IMAGE_SENSOR_FULL_WIDTH;
	SensorInfo->FullHeight			=	MT9D115_IMAGE_SENSOR_FULL_HEIGHT;

	SensorInfo->SensorAfSupport	=	KAL_FALSE;
	SensorInfo->SensorFlashSupport	=	KAL_FALSE;
} /* MT9D115GetSensorInfo() */

MM_ERROR_CODE_ENUM MT9D115StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
	P_CAL_FEATURE_TYPE_ENUM_STRUCT Capsize = (P_CAL_FEATURE_TYPE_ENUM_STRUCT)&(Out->FeatureInfo.FeatureEnum);

	switch (In->FeatureCtrlCode)
	{
	case CAL_FEATURE_QUERY_OPERATION:
		Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
		Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION 
									| CAL_FEATURE_GET_OPERATION 
									| CAL_FEATURE_QUERY_OPERATION;
		
		Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
		
		Capsize->IsSupport = KAL_TRUE;
		Capsize->ItemCount = 4;
		Capsize->SupportItem[0] = CAM_SIZE_WALLPAPER;
		Capsize->SupportItem[1] = CAM_SIZE_VGA;
		Capsize->SupportItem[2] = CAM_SIZE_1M;
		Capsize->SupportItem[3] = CAM_SIZE_2M;
		break;
	default:
		ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;
	}

	return MM_ERROR_NONE;
}   /* MT9D115StillCaptureSize() */


/*************************************************************************
* FUNCTION
*    MT9D115SceneMode
*
* DESCRIPTION
*    This function get/set scene mode of sensor.
*
* PARAMETERS
*    IsCam: camera scene mode or not
*    In, Out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM MT9D115SceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT SceneMode = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
    SceneMode->IsSupport = KAL_TRUE;
    SceneMode->ItemCount = 2;
    if (IsCam)
    {
      SceneMode->SupportItem[0] = CAM_AUTO_DSC;
      SceneMode->SupportItem[1] = CAM_NIGHTSCENE;
    }
    else
    {
      SceneMode->SupportItem[0] = CAM_VIDEO_AUTO;
      SceneMode->SupportItem[1] = CAM_VIDEO_NIGHT;
    }
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    kal_bool Enable;
    
    if (CAM_NIGHTSCENE == In->FeatureSetValue || CAM_VIDEO_NIGHT == In->FeatureSetValue)
    {
      Enable = KAL_TRUE;
    }
    else
    {
      Enable = KAL_FALSE;
    }
    MT9D115SetNightMode(Enable);
  }
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    MC501CBDetectSensorId
*
* DESCRIPTION
*    This function detect sensor id
*
* PARAMETERS
*    None
*
* RETURNS
*    sensor id
*
* LOCAL AFFECTED
*
*************************************************************************/
kal_uint32 MT9D115DetectSensorId(void)
{
    kal_uint32 SensorId=0;
	kal_uint16 AnotherSensorIdx = (IMAGE_SENSOR_MAIN == MT9D115Sensor.SensorIdx ? IMAGE_SENSOR_SUB : IMAGE_SENSOR_MAIN);
	kal_int8 i = 0, j = 0;

	for (i = 1; i >= 0; i++)
	{
		for (j = 1; j >= 0; j++)
		{
			/* Make the other camera into power down state. */
			CamRstPinCtrl(AnotherSensorIdx, i);
			CamRstPinCtrl(AnotherSensorIdx, j);
			
			SensorId = MT9D115PowerOn();
			
			MT9D115SensorClose();
			
			if (MT9D115_SENSOR_ID == SensorId)
			{
				return MT9D115_SENSOR_ID;
			}
		}
	}

    //return SensorId;
    return MM_ERROR_SENSOR_READ_ID_FAIL;
}   /* MT9D115DetectSensorId() */

void MT9D115InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT pInitOperPara)
{
	pInitOperPara->CaptureDelayFrame = 2;			/* wait stable frame when sensor change mode (pre to cap) */
	pInitOperPara->PreviewDelayFrame = 3;			/* wait stable frame when sensor change mode (cap to pre) */
	pInitOperPara->PreviewDisplayWaitFrame = 2;		/* wait stable frame when sensor change mode (cap to pre) */

} /* MT9D115InitOperationPara() */

kal_uint32 MT9D115PowerOn(void)
{
    kal_uint32 SensorId = 0;

     //4 <1> disable PND && RES(to BB)
     CamPdnPinCtrl(MT9D115Sensor.SensorIdx, 0);
     CamRstPinCtrl(MT9D115Sensor.SensorIdx, 1);
	 //4 <2> power on (to sensor)
     CisModulePowerOn(MT9D115Sensor.SensorIdx, KAL_TRUE);
	 CameraSccbOpen(CAMERA_SCCB_SENSOR, MT9D115_WRITE_ID, CAMERA_SCCB_16BIT, CAMERA_SCCB_16BIT, 250);
	 kal_sleep_task(1);  /* delay for power stable */
	 //4 <3>hard reset sensor
    CamRstPinCtrl(MT9D115Sensor.SensorIdx, 0);	/* Set Reset Pin Low */
    kal_sleep_task(1);
	CamRstPinCtrl(MT9D115Sensor.SensorIdx, 1);	/* Set Reset Pin High */
    kal_sleep_task(1);  /* delay for stable sensor */
    //4 <4>check sensor ID (to sensor)
	

	//CamPdnPinCtrl(MT9D115Sensor.SensorIdx, 1);	/* Set Power Down High */
	//kal_sleep_task(1);

    /* Reset the sensor */
	

    /* Read Sensor ID  */
    //MT9D115_set_page(0);
    SensorId = CamReadCmosSensor(0x0000);
#ifdef __MT9D115_DEBUG_INFO__
	kal_wap_trace(MOD_ENG, TRACE_INFO, "Sensor_id = %x", SensorId);
#endif
	
    return SensorId;
} /* MT9D115PowerOn() */


/*************************************************************************
* FUNCTION
*	MT9D115_Set_Video_Frame_Rate
*
* DESCRIPTION
*	This function set the sensor output frmae to target frame and fix the frame rate for 
*	video encode.
*
* PARAMETERS
*	1. kal_uint32 : Target frame rate to fixed.
*
* RETURNS
*	None
*
*************************************************************************/
static void MT9D115SetVideoFrameRate(kal_uint32 frame_rate)
{
	/*The real frame rate need /10*/
	kal_uint16 line_length = MT9D115_PV_PERIOD_LINE_NUMS;
	kal_uint16 aemax_temp = 1000/frame_rate;

	line_length = MT9D115Sensor.PrePclk*1000000/frame_rate\
		                   /(MT9D115_PV_PERIOD_PIXEL_NUMS+MT9D115Sensor.PreDummyLine)/2;

	CamWriteCmosSensor(0x098C, 0xA20B);	
    CamWriteCmosSensor(0x0990, 0x0000);

	CamWriteCmosSensor(0x098C, 0xA20C);	
    CamWriteCmosSensor(0x0990, aemax_temp);

	CamWriteCmosSensor(0x300A, line_length);

	CamWriteCmosSensor(0x098C, 0x271F);	
    CamWriteCmosSensor(0x0990, line_length);

	MT9D115SetCmd(5);
	

	
#ifdef __MT9D115_DEBUG_TRACE__
  kal_print_string_trace(MOD_ENG, TRACE_WARNING, "MT9D115_Set_Video_Frame_Rate:");
  kal_print_string_trace(MOD_ENG, TRACE_WARNING, "frame_rate=%d,aemax_temp=%d,line_length=%d",frame_rate,aemax_temp,line_length);
#endif
	
	//MT9D115_sensor.video_frame_rate = frame_rate;
}

/*************************************************************************
* FUNCTION
*	MT9D115_set_dummy
*
* DESCRIPTION
*	This function set the dummy pixels(Horizontal Blanking) & dummy lines(Vertical Blanking), it can be
*	used to adjust the frame rate or gain more time for back-end process.
*	
*	IMPORTANT NOTICE: the base shutter need re-calculate for some sensor, or else flicker may occur.
*
* PARAMETERS
*	1. kal_uint32 : Dummy Pixels (Horizontal Blanking)
*	2. kal_uint32 : Dummy Lines (Vertical Blanking)
*
* RETURNS
*	None
*
*************************************************************************/
	static void MT9D115SetDummy(kal_uint16 dummy_pixels, kal_uint16 dummy_lines)
	{
   #ifdef __MT9D115_DEBUG_TRACE__
	kal_wap_trace(MOD_ENG, TRACE_INFO, "MT9D115_op_state.is_PV_mode=%d, dummy_pixels=%d,dummy_lines=%d",MT9D115_op_state.is_PV_mode,dummy_pixels,dummy_lines);
   #endif
	   
		if(KAL_TRUE == MT9D115Sensor.PreviewMode)
			{
			   //for preview
			   const kal_uint16 frame_height = MT9D115_PV_PERIOD_LINE_NUMS + dummy_lines;
			   const kal_uint16 line_length = MT9D115_PV_PERIOD_PIXEL_NUMS + dummy_pixels;
			   //const kal_uint16 half_adjust_50 = (MT9D115_preview_pclk*1000000/20*2+line_length*50*2)/(line_length*50*2*2);
			   //const kal_uint16 half_adjust_60 = (MT9D115_preview_pclk*1000000/20*2+line_length*60*2)/(line_length*60*2*2);

			   const kal_uint16 half_adjust_50 = (MT9D115Sensor.PrePclk*1000000/20*2+line_length*50*2)/(line_length*50*2*2);
			   const kal_uint16 half_adjust_60 = (MT9D115Sensor.PrePclk*1000000/20*2+line_length*60*2)/(line_length*60*2*2);
	  
	
			   CamWriteCmosSensor(0x098C, 0x271F);/* preview frame length */
			   CamWriteCmosSensor(0x0990, frame_height);
			   
				
			   CamWriteCmosSensor(0x098C, 0x2721);/* preview line length */
			   CamWriteCmosSensor(0x0990, line_length);
			   
			   
			   CamWriteCmosSensor(0x098C, 0x2411);/* preview fd_r9_step_f60 */
			   CamWriteCmosSensor(0x0990, half_adjust_60);
			   
			   
			   CamWriteCmosSensor(0x098C, 0x2413);/* preview fd_r9_step_f50 */
			   CamWriteCmosSensor(0x0990, half_adjust_50);
			   MT9D115SetCmd(6); /* refresh mode */
	
   #ifdef __MT9D115_DEBUG_TRACE__
			 kal_wap_trace(MOD_ENG, TRACE_INFO, "MT9D115 set dummy--preview");
   #endif
			}
		else
			{
			   //for capture
			  const kal_uint16 frame_height = MT9D115_FULL_PERIOD_LINE_NUMS + dummy_lines;
			  const kal_uint16 line_length = MT9D115_FULL_PERIOD_PIXEL_NUMS + dummy_pixels;
			  //const kal_uint16 half_adjust_50 = (MT9D115_capture_pclk*1000000/20*2+line_length*50*2)/(line_length*50*2*2);
			  //const kal_uint16 half_adjust_60 = (MT9D115_capture_pclk*1000000/20*2+line_length*60*2)/(line_length*60*2*2);

			  const kal_uint16 half_adjust_50 = (MT9D115Sensor.CapPclk*1000000/20*2+line_length*50*2)/(line_length*50*2*2);
			  const kal_uint16 half_adjust_60 = (MT9D115Sensor.CapPclk*1000000/20*2+line_length*60*2)/(line_length*60*2*2);
	  
			 
			  CamWriteCmosSensor(0x098C, 0x2735);/* snapshot/video frame length */
			  CamWriteCmosSensor(0x0990, frame_height);
			   
	   
			  CamWriteCmosSensor(0x098C, 0x2737);
			  CamWriteCmosSensor(0x0990, line_length);/* snapshot/video line length */
			  
			  CamWriteCmosSensor(0x098C, 0x2415);/* snapshot/video fd_r9_step_f60 */
			  CamWriteCmosSensor(0x0990, half_adjust_60);
			  
			  CamWriteCmosSensor(0x098C, 0x2417);/* snapshot/video fd_r9_step_f50 */
			  CamWriteCmosSensor(0x0990, half_adjust_50);
			  MT9D115SetCmd(6); /* refresh mode */ 
   #ifdef __MT9D115_DEBUG_TRACE__
			 kal_wap_trace(MOD_ENG, TRACE_INFO, "MT9D115 set dummy--capture");
   #endif
			}
	}


void MT9D115PVSetting(void)
{
   //when the capture zoom larger than 2X, we need set the pclk ==>39Mhz. so need reset the pll when return to preview.
   ///PLL
  CamWriteCmosSensor(0x0014, 0x21F9);	//PLL Control: BYPASS PLL = 9541
  CamWriteCmosSensor(0x0010, 0x0110);	//PLL Dividers = 272
  CamWriteCmosSensor(0x0012, 0x1FF7);	//PLL P Dividers = 8183
  CamWriteCmosSensor(0x0014, 0x2545);	//PLL Control: TEST_BYPASS on = 9541
  CamWriteCmosSensor(0x0014, 0x2547);	//PLL Control: PLL_ENABLE on = 9543
  CamWriteCmosSensor(0x0014, 0x2447);	//PLL Control: SEL_LOCK_DET on
  //DELAY = 1               //Delay 1ms to allow PLL to lock
  kal_sleep_task(1);
  CamWriteCmosSensor(0x0014, 0x2047);	//PLL Control: PLL_BYPASS off
  CamWriteCmosSensor(0x0014, 0x2046);	//PLL Control: TEST_BYPASS off

  //when return to preview, reset the capture dummy line and pixel.
  CamWriteCmosSensor(0x98C, 0x2735); //Frame Lines (B)
  CamWriteCmosSensor(0x990, 0x050D); //	  = 1293
  CamWriteCmosSensor(0x98C, 0x2737); //Line Length (B)
  CamWriteCmosSensor(0x990, 0x0844); //	  = 2116

  MT9D115Sensor.PrePclk = 520;
  //MT9D115_op_state.is_PV_mode = KAL_TRUE;
   
}




MM_ERROR_CODE_ENUM MT9D115Preview(CAL_SCENARIO_ENUM ScenarioId,
								  P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In,
								  P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;

	kal_uint16 status;
	kal_uint16 i;

	//MT9D115CurrScenario = ScenarioId;

	MT9D115Sensor.Banding = In->BandingFreq;
	MT9D115Sensor.NightMode = In->NightMode;


	MT9D115PVSetting();

	switch (ScenarioId)
	{
	case CAL_SCENARIO_VIDEO:
		//MT9D115MaxFrameRate = In->MaxVideoFrameRate;
		//MT9D115MinFrameRate = In->MaxVideoFrameRate;
		
		//MT9D115SetFixFrameRate(KAL_TRUE);

		MT9D115Sensor.VideoMode = KAL_TRUE;
        MT9D115Sensor.Fps = In->MaxVideoFrameRate * MT9D115_FRAME_RATE_UNIT / 10;
         MT9D115SetVideoFrameRate(MT9D115Sensor.Fps);
		//Out->WaitStableFrameNum = 3;
		break;
	case CAL_SCENARIO_CAMERA_PREVIEW:
	case CAL_SCENARIO_WEBCAM_PREVIEW:
	case CAL_SCENARIO_WEBCAM_CAPTURE:
		//MT9D115MaxFrameRate = MT9D115_MAX_CAMERA_FPS;
		//MT9D115MinFrameRate = 10 *  MT9D115_FRAME_RATE_UNIT;
		//if (In->NightMode)
		//{
			//MT9D115MinFrameRate = MT9D115MinFrameRate >> 1;
		//}
		//
		//MT9D115SetFixFrameRate(KAL_FALSE);

		MT9D115Sensor.VideoMode = KAL_FALSE;
        MT9D115Sensor.Fps = MT9D115_FRAME_RATE_UNIT * (MT9D115Sensor.NightMode ? 5 : 10);

		//Out->WaitStableFrameNum = 3;
		break;
	default:
		ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;
	}

	MT9D115SetMirrorFlip(In->ImageMirror);
	MT9D115SetDummy(MT9D115Sensor.PreDummyPixel, MT9D115Sensor.PreDummyLine);

	CamWriteCmosSensor(0x098C, 0xA115);
  CamWriteCmosSensor(0x0990, 0x0000);
  
  MT9D115SetCmd(1); /* seq_cmd: goto preview mode */

  for (i = 100; i > 0; i--) /* wait for ready */
         {

	        kal_sleep_task(2);
   
	        CamWriteCmosSensor(0x098C, 0xA104);
	        status = CamReadCmosSensor(0x0990);
            if(3 == status)
      	     {
      	        break;
      	     }
   
  
         }
	
	//MT9D115CalculateFrameRate(MT9D115MinFrameRate, MT9D115MaxFrameRate);

	//MT9D115SetNightMode(MT9D115CurrScenario, In->NightMode);

	//MT9D115SetAeBaseShutter(In->BandingFreq, MT9D115MinFrameRate);

	Out->GrabStartX = MT9D115_PV_GRAB_START_X;
	Out->GrabStartY = MT9D115_PV_GRAB_START_Y;
	Out->ExposureWindowWidth = MT9D115_PV_GRAB_WIDTH;
	Out->ExposureWindowHeight = MT9D115_PV_GRAB_HEIGHT;

	return ErrCode;
} /* MT9D115Preview */


static void MT9D115CAPSetting(void)
{
    MT9D115Sensor.CapPclk= 520;
	//MT9D115_op_state.is_PV_mode = KAL_FALSE;
}



MM_ERROR_CODE_ENUM MT9D115Capture(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{

    kal_uint16 status;
	kal_uint16 i;
    kal_uint16 cap_fps;
      kal_uint16 prev_line_len = 0;
  kal_uint16 cap_line_len = 0;
	
   if((In->ImageTargetWidth <= MT9D115_IMAGE_SENSOR_PV_WIDTH)
   	   &&(In->ImageTargetHeight <= MT9D115_IMAGE_SENSOR_PV_HEIGHT))
   	{
   	     
		 	   if (In->ZoomFactor>= 300) // DZ >= 3x
		 	   	{
		 	   	  MT9D115Sensor.CapDummyPixel= 0;
				  MT9D115Sensor.CapDummyLine= 0; 
		 	   	}
			   else if (In->ZoomFactor>= 200) // DZ >= 2x
			   	{
			   	   MT9D115Sensor.CapDummyPixel= 0;
				  MT9D115Sensor.CapDummyLine= 0;
			   	}
			   else
			   	{
			   	   MT9D115Sensor.CapDummyPixel= 0;
				  MT9D115Sensor.CapDummyLine= 0; 
			   	}
			   
			MT9D115Sensor.CapPclk= MT9D115Sensor.PrePclk;   //Don't need change the clk for pv capture
			MT9D115SetDummy( MT9D115Sensor.CapDummyPixel, MT9D115Sensor.CapDummyLine);

		//#if (defined(__DYNAMIC_SENSOR_DELAY__))
		//	image_window->wait_stable_frame = 0;	// For preview size capture, no need wait stable frame.
		//#endif
			
			Out->GrabStartX = MT9D115_PV_GRAB_START_X;
			Out->GrabStartY= MT9D115_PV_GRAB_START_Y;
			Out->ExposureWindowWidth = MT9D115_PV_GRAB_WIDTH;
			Out->ExposureWindowHeight = MT9D115_PV_GRAB_HEIGHT;
			   

   }
   else
   	{   /* FULL Size Capture Mode */
   	 //#if (defined(__DYNAMIC_SENSOR_DELAY__))
	//	camera_wait_sensor_vd_done();	// Apply the switch size setting from VD. it's more safe.
	// #endif
	 
     MT9D115CAPSetting();
	 
	 /* Capture Size <= 2M */
		if ((In->ImageTargetWidth <= MT9D115_IMAGE_SENSOR_FULL_WIDTH)
			&& (In->ImageTargetHeight <= MT9D115_IMAGE_SENSOR_FULL_HEIGHT))
		{
		#if ((defined(DRV_ISP_6238_SERIES) || defined(DRV_ISP_6276_SERIES)))
			if (In->ZoomFactor >= 400)
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
			#endif
               //set pclk 26MHz 
               MT9D115Sensor.CapPclk= 260;
			   cap_fps = 50;
			   CamWriteCmosSensor(0x0014, 0x2047);	//PLL Control: PLL_BYPASS off
			  
			}
			else if (In->ZoomFactor >= 200)
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
			 #endif

			    //set pclk 26MHz
			    MT9D115Sensor.CapPclk= 260;
			    cap_fps = 50;
				CamWriteCmosSensor(0x0014, 0x2047);	//PLL Control: PLL_BYPASS off
			    
			}
			else
			{
				
				//cap_fps = 150;
			}
		#elif (defined(DRV_ISP_6235_SERIES))
			if (In->ZoomFactor >= 300)  // DZ >= 3X
			{  
				
				//cap_fps = 60;
			}
			else if (In->ZoomFactor >= 200)  // DZ >= 2X
			{
				
				//cap_fps = 130;
			}
			else 
			{
				

			    //cap_fps = 130;
			}

		#endif
		}
		else    /* When Capture Size Interpolate to 3M */
		{
		#if ((defined(DRV_ISP_6238_SERIES) || defined(DRV_ISP_6276_SERIES)))
			if (In->ZoomFactor >= 400)
			{
				//cap_fps = 50;
			}
			else if (In->ZoomFactor >= 200)
			{
				//cap_fps = 50;
			}
			else
			{
				//cap_fps = 100;
			}
		#elif (defined(DRV_ISP_6235_SERIES))
			/* If Capture fail or system hang when capture, you can add dummy pixels for each step.  */
			if (In->ZoomFactor >= 300) // DZ >= 3X
			{
				//cap_fps = 60;
			}
			else if (In->ZoomFactor >= 200) // DZ >= 2x
			{  
				//cap_fps = 130;
			}
			else if (In->ZoomFactor > 100) // DZ > 1x
			{
				//cap_fps = 130;
			}
			else 
			{
				//cap_fps = 130;
			}

		#endif
		}

		

		
      if(cap_fps)
      	{
			MT9D115Sensor.CapDummyPixel= MT9D115Sensor.CapPclk* 1000000 / (2 * MT9D115_FULL_PERIOD_LINE_NUMS * cap_fps);
			MT9D115Sensor.CapDummyPixel= MT9D115Sensor.CapDummyPixel< MT9D115_FULL_PERIOD_PIXEL_NUMS ? 0 : MT9D115Sensor.CapDummyPixel- MT9D115_FULL_PERIOD_PIXEL_NUMS;


//	prev_line_len = MT9D115_PV_PERIOD_PIXEL_NUMS + (MT9D115_PV_dummy_pixels);
//	cap_line_len = MT9D115_FULL_PERIOD_PIXEL_NUMS + (MT9D115_Cap_dummy_pixels);

			prev_line_len = MT9D115_PV_PERIOD_PIXEL_NUMS + MT9D115Sensor.PreDummyPixel;
			cap_line_len = MT9D115_FULL_PERIOD_PIXEL_NUMS + MT9D115Sensor.CapDummyPixel;
		
			//MT9D115_gPVmode = KAL_FALSE;
//	MT9D115_set_dummy(MT9D115_Cap_dummy_pixels,0);

            MT9D115SetDummy(MT9D115Sensor.CapDummyPixel,0);
      	}
			//11-23
		CamWriteCmosSensor(0x098C, 0xA115);
		CamWriteCmosSensor(0x0990, 0x0002);
		
		MT9D115SetCmd(2);/* seq_cmd: goto capture mode */

		for (i = 100; i > 0; i--) /* wait for ready */
         {

	        kal_sleep_task(2);
   
	        CamWriteCmosSensor(0x098C, 0xA104);
	        status = CamReadCmosSensor(0x0990);
            if(7 == status)
      	     {
      	        break;
      	     }
   
  
         }
     #ifdef __MT9D115_DEBUG_TRACE__
      if (!i) kal_print_string_trace(MOD_ENG, TRACE_WARNING, "set cmd: %d time out,status:%d", 0xA104,status);
     #endif


	 	
    #ifdef __MT9D115_DEBUG_TRACE__
      kal_print_string_trace(MOD_ENG, TRACE_WARNING, "capture cap_fps:%d",cap_fps);
	  kal_print_string_trace(MOD_ENG, TRACE_WARNING, "capture dummy_pixel:%d",MT9D115_sensor.cap_dummy_pixels);
	  kal_print_string_trace(MOD_ENG, TRACE_WARNING, "capture shutter:%d--++--%d",shutter,CamReadCmosSensor(0x3012));
	  //kal_print_string_trace(MOD_ENG, TRACE_WARNING, "capture mul:%d",mul);
    #endif
		
		

    Out->GrabStartX = MT9D115_FULL_GRAB_START_X;
	Out->GrabStartY = MT9D115_FULL_GRAB_START_Y;
	Out->ExposureWindowWidth = MT9D115_FULL_GRAB_WIDTH;
	Out->ExposureWindowHeight = MT9D115_FULL_GRAB_HEIGHT;
	

	}
		 				 

   
	
	
	return MM_ERROR_NONE;
} /* MT9D115Capture() */

/*************************************************************************
* FUNCTION
*    MT9D115SensorOpen
*
* DESCRIPTION
*    This function read sensor id and init sensor
*
* PARAMETERS
*    None
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM MT9D115SensorOpen(void)
{
    if (MT9D115PowerOn() != MT9D115_SENSOR_ID)
    {
        return MM_ERROR_SENSOR_READ_ID_FAIL;
    }

    //MT9D115_g_iBanding = CAM_BANDING_50HZ;
    //MT9D115_Control = 0x00;
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
    //MT9D115_Dummy_Pixel = 0x1d;
#else
    //MT9D115_Dummy_Pixel = 0x01;
#endif

	MT9D115InitialSetting();
	
    //MT9D115CalculateFrameRate(MT9D115MinFrameRate, MT9D115MaxFrameRate);

    return MM_ERROR_NONE;
} /* MT9D115SensorOpen() */


/*************************************************************************
* FUNCTION
*    MT9D115SensorFeatureCtrl
*
* DESCRIPTION
*    This function set sensor feature mode
*
* PARAMETERS
*    id: scenario id
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM MT9D115SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_ENUM id, void *In, void *Out, kal_uint32 out_len, kal_uint32 *r_out_len)
{
	MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
	kal_uint32 TmpFrameRate;
	
    P_CAL_FEATURE_CTRL_STRUCT pCameraFeatureIn=(P_CAL_FEATURE_CTRL_STRUCT) In;
    P_CAL_FEATURE_CTRL_STRUCT pCameraFeatureOut=(P_CAL_FEATURE_CTRL_STRUCT) Out;
    // for camera HAL UT only
    P_CAL_FEATURE_TYPE_ENUM_STRUCT pCamFeatureEnum=(P_CAL_FEATURE_TYPE_ENUM_STRUCT) &(pCameraFeatureOut->FeatureInfo.FeatureEnum);
    P_CAL_CAMERA_DIGITAL_ZOOM_OUT_STRUCT pCameraDzOut=pCameraFeatureOut->FeatureInfo.FeatureStructured.pCamDzOutPara;
	
	
	if (id >= CAL_FEATURE_WEBCAM_BEGIN && id <= CAL_FEATURE_WEBCAM_END)
	{
		return MT9D115WebcamFeatureCtrl(id, In, Out, out_len, r_out_len);
	}
	
	if(Out!=NULL && CAL_FEATURE_QUERY_OPERATION==pCameraFeatureIn->FeatureCtrlCode){
        pCamFeatureEnum->IsSupport = KAL_FALSE;
	}
	
	switch (id)
	{
		/* CAL Query and set series */
    case CAL_FEATURE_CAMERA_BRIGHTNESS:
    case CAL_FEATURE_CAMERA_EV_VALUE:
		ErrCode = MT9D115EV(In, Out);
		break;
    case CAL_FEATURE_CAMERA_CONTRAST:
    case CAL_FEATURE_CAMERA_HUE:
    case CAL_FEATURE_CAMERA_SATURATION:
    case CAL_FEATURE_CAMERA_SHARPNESS:
    case CAL_FEATURE_CAMERA_GAMMA:
		ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;
    case CAL_FEATURE_CAMERA_WB:
		ErrCode = MT9D115WB(In, Out);
		break;
    case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
		ErrCode = MT9D115Effect(In, Out);
		break;
    case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
		ErrCode = MT9D115StillCaptureSize(In, Out);
		break;
    case CAL_FEATURE_CAMERA_BANDING_FREQ: /* move to preview */
		ErrCode = MT9D115Banding(In, Out);
		break;
	case CAL_FEATURE_CAMERA_SCENE_MODE:
        ErrCode = MT9D115SceneMode(KAL_TRUE, In, Out);
        break;
    case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
        ErrCode = MT9D115SceneMode(KAL_FALSE, In, Out);
        break;
    case CAL_FEATURE_CAMERA_FLASH_MODE:
		ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;
		
		/* Get Info series */
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
		MT9D115GetSensorInfo((P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT)Out);
		break;
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
		((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = MT9D115DetectSensorId();
		break;
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
		((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = MT9D115Sensor.Fps * 10 / MT9D115_FRAME_RATE_UNIT;
		break;
    case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
		MT9D115InitOperationPara((P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT)Out);
		break;
    case IMAGE_SENSOR_FEATURE_GET_DSC_SUPPORT_INFO:
		//MT9D115DscSupportInfo((P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT)Out);
		break;
		
		/* Set Para series */
    case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
		ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;      
    case IMAGE_SENSOR_FEATURE_VSYNC_HISR_INFORM_FRAME_TIME:
		TmpFrameRate = ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
		break;      
    case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
		MT9D115Sensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
		break;
    case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
		break;     
    //case IMAGE_SENSOR_FEATURE_YUV_3A_CTRL:
		//rCode = MT9D115AEEnable((kal_bool)(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue));
		//rCode |= MT9D115AWBEnable((kal_bool)(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue));
	//	break;
	case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
		MT9D115Sensor.BypassAe = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
		MT9D115AeEnable(MT9D115Sensor.BypassAe ? KAL_FALSE : KAL_TRUE);	
		break;
	case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
		MT9D115Sensor.BypassAwb = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
		MT9D115AwbEnable(MT9D115Sensor.BypassAwb ? KAL_FALSE : KAL_TRUE);	
		break;
	case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
	    CamGetHWInfo(MT9D115Sensor.SensorIdx,Out);
	    break;
    default:
		ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
		break;
	}
	
	return ErrCode;
}


/*************************************************************************
* FUNCTION
*    MT9D115SensorCtrl
*
* DESCRIPTION
*    This function set sensor scenario mode
*
* PARAMETERS
*    id: scenario id
*    In/Out: parameter
*    out_len: Out parameter length
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM MT9D115SensorCtrl(CAL_SCENARIO_ENUM id, void *In, void *Out, kal_uint16 out_len)
{
  switch (id)
  {
    case CAL_SCENARIO_CAMERA_PREVIEW:
    case CAL_SCENARIO_VIDEO:
    case CAL_SCENARIO_WEBCAM_PREVIEW:
    case CAL_SCENARIO_WEBCAM_CAPTURE: MT9D115Preview(id, In, Out); break;
    case CAL_SCENARIO_CAMERA_STILL_CAPTURE: MT9D115Capture(id, In, Out); break;
    default: break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    MT9D115SensorClose
*
* DESCRIPTION
*    This function is to turn off sensor module power.
*
* PARAMETERS
*    None
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM MT9D115SensorClose(void)
{

    /* power down sensor */
  CamPdnPinCtrl(MT9D115Sensor.SensorIdx, 0);
  CamRstPinCtrl(MT9D115Sensor.SensorIdx, 1);
  
	CameraSccbClose(CAMERA_SCCB_SENSOR);
	
	CisModulePowerOn(MT9D115Sensor.SensorIdx, KAL_FALSE);

    return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    MT9D115SensorFunc
*
* DESCRIPTION
*    This function get sensor function pointer
*
* PARAMETERS
*    sensor function pointer
*
* RETURNS
*    error code
*
* GLOBALS AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM MT9D115SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncMT9D115=
  {
    MT9D115SensorOpen,
    MT9D115SensorFeatureCtrl,
    MT9D115SensorCtrl,
    MT9D115SensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncMT9D115;
}


