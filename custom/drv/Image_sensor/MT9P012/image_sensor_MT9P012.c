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
*#80FF80
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

 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "cal_comm_def.h"
#include "isp_if.h"
#include "isp_comm_if.h"
#include "isp_flashlight_if.h"
#include "aaa_ae.h"
	 
#include "camera_sccb.h"
#include "image_sensor.h"
	 
/* Global Valuable */
IMAGE_SENSOR_INDEX_ENUM MT9P012SensorIdx;
sensor_data_struct *pMT9P012NvramSensorData;
SensorInfo MT9P012_CCT_MainSensor=MT9P012_CURRENT_MAIN_SENSOR;
kal_uint16 MT9P012SensorGainArray[4][4]={{0x0208, 0x0206, 0x020C, 0x020A},{0, 0, 0, 0},{0x0209, 0x0207, 0x020D, 0x020B},{0x18, 0x10, 0x10, 0x18}};

/* Parameter For Engineer mode function */
kal_uint32 MT9P012_FAC_SENSOR_REG; 

static struct MT9P012_SENSOR_STRUCT MT9P012SensorStatus;

#ifdef MT9P012_REV8_SUPPORT
kal_uint16 MT9P012_curr_rev = 7;	// 7 - Rev7, 8 - Rev8
#endif

extern camcorder_info_struct	MT9P012_dsc_support_info;
extern void SetIspDrivingCurrent(kal_uint8 Current);
extern void SetIspDrivingCurrent(kal_uint8 Current);
extern void CamRstPinCtrl(IMAGE_SENSOR_INDEX_ENUM Idx, kal_int8 Data);
extern void CamPdnPinCtrl(IMAGE_SENSOR_INDEX_ENUM Idx, kal_int8 Data);

/*************************************************************************
* FUNCTION
*	init_cmos_sensor
*
* DESCRIPTION
*	This function configure CMOS sensor window size
*
* PARAMETERS
*	startX, endX, startY,	endY, X_size, Y_size, scaler(1,3,7)
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/

void MT9P012ConfigWindow(kal_uint16 startX,kal_uint16 endX,kal_uint16 startY,kal_uint16 endY,kal_uint16 X_size,kal_uint16 Y_size,kal_uint16 scaler)
{
	kal_uint16 Frame_Length_lines, Line_Length_pck;
//CamWriteCmosSensor(0x0104, 0x01);	
	if (scaler != 1)
	{
		Frame_Length_lines = MT9P012_PV_PERIOD_LINE_NUMS;
		Line_Length_pck = MT9P012_PV_PERIOD_PIXEL_NUMS*2;//the period pixel number is double in scope
		CamWriteCmosSensor(0x0382, scaler>>8);			//X_Odd_INC
		CamWriteCmosSensor(0x0383, scaler&0xFF);			
		CamWriteCmosSensor(0x0386, scaler>>8);			//Y_Odd_INC
		CamWriteCmosSensor(0x0387, scaler&0xFF);
	}
	else
	{
		Frame_Length_lines = MT9P012_FULL_PERIOD_LINE_NUMS;//(endY-startY)+IMAGE_SENSOR_FULL_VBLANKING;
		Line_Length_pck = MT9P012_FULL_PERIOD_PIXEL_NUMS*2;//(endX-startX)+IMAGE_SENSOR_FULL_HBLANKING;
		CamWriteCmosSensor(0x0382, scaler>>8);			//X_Odd_INC
		CamWriteCmosSensor(0x0383, scaler&0xFF);			
		CamWriteCmosSensor(0x0386, scaler>>8);			//Y_Odd_INC
		CamWriteCmosSensor(0x0387, scaler&0xFF);
	}
		
	CamWriteCmosSensor(0x0340, Frame_Length_lines>>8);   //frame_Length_lines
	CamWriteCmosSensor(0x0341, Frame_Length_lines&0xFF);
	CamWriteCmosSensor(0x0342, Line_Length_pck>>8);      //line_Length_pck
	CamWriteCmosSensor(0x0343, Line_Length_pck&0xFF);
	
	CamWriteCmosSensor(0x0344, startX>>8);               //X_start
	CamWriteCmosSensor(0x0345, startX&0xFF); 
	CamWriteCmosSensor(0x0346, startY>>8);	            //Y_start
	CamWriteCmosSensor(0x0347, startY&0xFF);	
	    	
	CamWriteCmosSensor(0x0348, endX>>8);                 //X_end	
	CamWriteCmosSensor(0x0349, endX&0xFF);	
	CamWriteCmosSensor(0x034A, endY>>8);                 //Y_end	
	CamWriteCmosSensor(0x034B, endY&0xFF);	
                                                                   
    CamWriteCmosSensor(0x034C, X_size>>8);          //X_size  
    CamWriteCmosSensor(0x034D, X_size&0xFF);                  
    CamWriteCmosSensor(0x034E, Y_size>>8);          //Y_size  
    CamWriteCmosSensor(0x034F, Y_size&0xFF);                  
//CamWriteCmosSensor(0x0104, 0x00);
	
}	/*  MT9P012ConfigWindow */



void MT9P012WriteGain(kal_uint16 gain)
{
	volatile signed char i;
    kal_uint16 TempReg=0, TempGain=0;
	kal_uint16 temp_Min_gain = gain;
	
    CamWriteCmosSensor(0x0104, 0x01);		//parameter_hold
   for(i=0;i<4;i++)
   {
      TempGain=(MT9P012SensorGainArray[3][i]*gain)/BASEGAIN;
       /* prevent init value error of temp_Min_gain > 2 */
	  if (i==0)
	  {
	        temp_Min_gain = TempGain;
	  }
	
        if(TempGain>=1*BASEGAIN && TempGain<15*BASEGAIN)
        {
            TempReg=(8*TempGain)/BASEGAIN;
            if(TempGain<=temp_Min_gain)
            {
                MT9P012SensorStatus.GlobalGain=TempGain&(~0x1);
         	    temp_Min_gain = TempGain;
            }
	    }
        else
        {
            TempReg = 0x7F;
            if(TempGain<=temp_Min_gain)
            {
                MT9P012SensorStatus.GlobalGain=15.875*BASEGAIN;
         	    temp_Min_gain = TempGain;
            }                           
        }
					
            CamWriteCmosSensor(MT9P012SensorGainArray[2][i],TempReg);
            
    }
   CamWriteCmosSensor(0x0104, 0x00);		//parameter_hold
}   /* MT9P012WriteGain */

kal_uint16 MT9P012ReadGain()
{
   volatile signed char i;
   kal_uint16 TempReg=0, sensor_gain=0,TempReg_base=0;
			
   for(i=0;i<4;i++)
   {
      TempReg_base=pMT9P012NvramSensorData->cct[MT9P012_SENSOR_BASEGAIN].para;
      TempReg=pMT9P012NvramSensorData->cct[MT9P012_PRE_GAIN_R_INDEX+i].para;

      if(TempReg>=0x08 && TempReg<=0xFF)
         MT9P012SensorGainArray[3][i]=((((TempReg*BASEGAIN)/8)*TempReg_base)/8);
      else if(TempReg>0xFF && TempReg<=0x1FF)
         MT9P012SensorGainArray[3][i]=((((TempReg*BASEGAIN)/8)*TempReg_base)/8);
      else
         ASSERT(0);      
   }

   sensor_gain=(TempReg_base*BASEGAIN)/8;

   return sensor_gain;
}  /* MT9P012ReadGain */

void MT9P012SetMirrorFlip(kal_uint8 image_mirror)
{
	switch (image_mirror)
	{
		case IMAGE_SENSOR_MIRROR_NORMAL:
			CamWriteCmosSensor(0x301D,0x00);
			//SET_FIRST_GRAB_COLOR(MT9P012_FIRST_GRAB_COLOR);
		break;
		case IMAGE_SENSOR_MIRROR_H:
			CamWriteCmosSensor(0x301D,0x01);
			//SET_FIRST_GRAB_COLOR((MT9P012_FIRST_GRAB_COLOR + 1) % 4);
		break;
		case IMAGE_SENSOR_MIRROR_V:
			CamWriteCmosSensor(0x301D,0x02);
			//SET_FIRST_GRAB_COLOR((MT9P012_FIRST_GRAB_COLOR + 2) % 4);
		break;
		case IMAGE_SENSOR_MIRROR_HV:
			CamWriteCmosSensor(0x301D,0x03);
			//SET_FIRST_GRAB_COLOR((MT9P012_FIRST_GRAB_COLOR + 3) % 4);
		break;
	}
}

// 2592 * 1944
void MT9P012SetQSXGAMode()
{
	CamWriteCmosSensor(0x0104, 0x01);		//parameter_hold
	
	MT9P012ConfigWindow(MT9P012_FULL_X_START,MT9P012_FULL_X_END,MT9P012_FULL_Y_START,MT9P012_FULL_Y_END,2592,1944,MT9P012_FULL_SCALER_FACTOR);
	
	CamWriteCmosSensor(0x0400, 0x00);		//scaling mode
	CamWriteCmosSensor(0x0401, 0x00);
	CamWriteCmosSensor(0x0404, 0x00);		//scale_M
	CamWriteCmosSensor(0x0405, 0x10);
	CamWriteCmosSensor(0x0104, 0x00);		//parameter_hold
	CamWriteCmosSensor(0x0100, 0x01);		//mode_select (Open streaMing)
}


// 1280 * 960
void MT0P012SetSXGAMode()
{

	CamWriteCmosSensor(0x0104, 0x01);		//parameter_hold

	MT9P012ConfigWindow(MT9P012_PV_X_START,MT9P012_PV_X_END,MT9P012_PV_Y_START,MT9P012_PV_Y_END,1296,972,MT9P012_PV_SCALER_FACTOR);

	CamWriteCmosSensor(0x0400, 0x00);		//scaling mode
	CamWriteCmosSensor(0x0401, 0x00);
	CamWriteCmosSensor(0x0404, 0x00);		//scale_M
	CamWriteCmosSensor(0x0405, 0x10);

	CamWriteCmosSensor(0x0104, 0x00);		//parameter_hold check 20080408
	CamWriteCmosSensor(0x0100, 0x01);		//mode_select (Open streaMing)
}

void MT9P012SetQSXGAMode_HS()
{	
	// PLL Settings
	CamWriteCmosSensor(0x0100, 0x00);	//Mode Select=0x0
    kal_sleep_task(1);	
	CamWriteCmosSensor(0x0300, 0x00);
	CamWriteCmosSensor(0x0301, 0x05);	//vt_pix_clk_div=0x5
	CamWriteCmosSensor(0x0302, 0x00);
	CamWriteCmosSensor(0x0303, 0x01);	//vt_sys_clk_div=0x1
	CamWriteCmosSensor(0x0304, 0x00);
	CamWriteCmosSensor(0x0305, 0x0D);	//pre_pll_clk_div=0xD
	CamWriteCmosSensor(0x0306, 0x00);
	CamWriteCmosSensor(0x0307, 0xa0);//167;	//pll_multiplier=0xAA  170
	CamWriteCmosSensor(0x0308, 0x00);
	CamWriteCmosSensor(0x0309, 0x08);	//op_pix_clk_div=0x8
	CamWriteCmosSensor(0x030A, 0x00);
	CamWriteCmosSensor(0x030b, 0x01);	//op_sys_clk_div=0x1
	kal_sleep_task(1);// Allow PLL to lock
	CamWriteCmosSensor(0x0100, 0x01);	//Mode Select=0x1
	
	
	CamWriteCmosSensor(0x301A, 0x10);
	CamWriteCmosSensor(0x301b, 0xCC);	// RESET_REGISTER
	
	// Capture mode as default
	CamWriteCmosSensor(0x0104, 0x01);	//Grouped Parameter Hold=0x1
	CamWriteCmosSensor(0x0344, 0x00);
	CamWriteCmosSensor(0x0345, 0x08);	//x_addr_start_=0x8
	CamWriteCmosSensor(0x0348, 0x0A);
	CamWriteCmosSensor(0x0349, 0x27);	//x_addr_end_=0xA27
	CamWriteCmosSensor(0x0346, 0x00);
	CamWriteCmosSensor(0x0347, 0x08);	//x_addr_start_=0x8
	CamWriteCmosSensor(0x034A, 0x07);
	CamWriteCmosSensor(0x034b, 0x9F);	//y_addr_end_=0x79F
	CamWriteCmosSensor(0x3040, 0x00);
	CamWriteCmosSensor(0x3041, 0x41);	//read_mode=0x41
	CamWriteCmosSensor(0x034C, 0x0A);
	CamWriteCmosSensor(0x034d, 0x20);	//x_output_size=0xA20
	CamWriteCmosSensor(0x034E, 0x07);
	CamWriteCmosSensor(0x034f, 0x98);	//y_output_size=0x798
	CamWriteCmosSensor(0x0342, 0x11);
	CamWriteCmosSensor(0x0343, 0x60);	//line_length_pck_=0x1160 4448
	CamWriteCmosSensor(0x0340, 0x07);
	CamWriteCmosSensor(0x0341, 0xED);	//frame_length_lines_=0x7ED 2029
	CamWriteCmosSensor(0x0202, 0x00);
	CamWriteCmosSensor(0x0203, 0x10);	//coarse_integration_time_=0x10
	CamWriteCmosSensor(0x3014, 0x03);
	CamWriteCmosSensor(0x3015, 0x72);	//fine_integration_time_=0x372
	CamWriteCmosSensor(0x3010, 0x00);
	CamWriteCmosSensor(0x3011, 0x9C);	//fine_correction=0x9C
	CamWriteCmosSensor(0x0104, 0x00); //Grouped Parameter Hold=0x0
	
	CamWriteCmosSensor(0x0100, 0x01);	// MODE_SELECT
	
	// Slew rate 
	CamWriteCmosSensor(0x306E, 0x34);
	CamWriteCmosSensor(0x306f, 0x80);	// DATAPATH_SELECT
	// New analog chain tiMing, to reduce cluster defects, this require Minimum VAA of 2.6V
	CamWriteCmosSensor(0x309C, 0x19); 
        CamWriteCmosSensor(0x309D, 0x00);
        CamWriteCmosSensor(0x309E, 0x5D); 
        CamWriteCmosSensor(0x309F, 0x00);

}

void MT9P012Input52MHzMclkOuptu48MHzPclk(void)
{
	CamWriteCmosSensor(0x0100, 0x00);	  //MODE select (Stop streaMing)
	 kal_sleep_task(1); 
				  
	//Sensor PLL settng: 52MHz input--> 48MHz output
	CamWriteCmosSensor(0x0300, 0x00);	
	CamWriteCmosSensor(0x0301, 0x04);	  //Vt_pix_clk_div, (Internal used to control the tiMing of the pixel array)
	CamWriteCmosSensor(0x0302, 0x00);	
	CamWriteCmosSensor(0x0303, 0x02);	  //Vt_sys_div (For SIMA)
	CamWriteCmosSensor(0x0304, 0x00);	
	CamWriteCmosSensor(0x0305, 0x0D);	  //Pre_pll_div
	CamWriteCmosSensor(0x0306, 0x00);	
	CamWriteCmosSensor(0x0307, 0xC0);	  //PLL_Multipler
	CamWriteCmosSensor(0x0308, 0x00);	
	CamWriteCmosSensor(0x0309, 0x08);	  //op_pix_clk_div (Pixel clock)  
	CamWriteCmosSensor(0x030A, 0x00);	
	CamWriteCmosSensor(0x030B, 0x02);	  //op_sys_clk_div
							
	kal_sleep_task(1);

}
	

void MT9P012InitialSetting()
{
	CamWriteCmosSensor(0x301A, 0x10);		//RESET_REGISTER, enable parallel interface and disable serialiser
	CamWriteCmosSensor(0x301B, 0xCC);

#ifdef MT9P012_REV8_SUPPORT
	MT9P012_curr_rev = (CamReadCmosSensor(0x31FF) & 0x0F);
    kal_print_string_trace(MOD_ENG, TRACE_INFO,"Rev %d", MT9P012_curr_rev);
#endif

	//camera_para_to_sensor();

	MT9P012Input52MHzMclkOuptu48MHzPclk();
		  
	CamWriteCmosSensor(0x0100, 0x01);		//MODE select (Stop streaMing)
	kal_sleep_task(10);   

	// power saving
	CamWriteCmosSensor(0x0104, 0x01);	//parameter_hold

	CamWriteCmosSensor(0x30B0, 0x00); 
	CamWriteCmosSensor(0x30B1, 0x01);

#ifdef MT9P012_REV8_SUPPORT
	if (MT9P012_curr_rev == MT9P012_REV8)
	{
		CamWriteCmosSensor(0x308E, 0xD6);		//VRef = 0.8V to improved sensor sensitivity.
		CamWriteCmosSensor(0x308F, 0x6A);
		CamWriteCmosSensor(0x3090, 0x56); 
		CamWriteCmosSensor(0x3091, 0x6A);
	}
	else
#endif
	{
		CamWriteCmosSensor(0x308E, 0xE0);		//VRef = 1.0V
		CamWriteCmosSensor(0x308F, 0x60);
	}

	CamWriteCmosSensor(0x3084, 0x24); 
	CamWriteCmosSensor(0x3085, 0x24);

	CamWriteCmosSensor(0x3088, 0x6E); 
	CamWriteCmosSensor(0x3089, 0x61);
	CamWriteCmosSensor(0x3092, 0x0A); 
	CamWriteCmosSensor(0x3093, 0x52);
	CamWriteCmosSensor(0x3094, 0x46); 
	CamWriteCmosSensor(0x3095, 0x56);
	CamWriteCmosSensor(0x3096, 0x56); 
	CamWriteCmosSensor(0x3097, 0x52);
	CamWriteCmosSensor(0x30CA, 0x80); 
	CamWriteCmosSensor(0x30CB, 0x06);
	CamWriteCmosSensor(0x312A, 0xDD); 
	CamWriteCmosSensor(0x312B, 0x02);
	CamWriteCmosSensor(0x312C, 0x00); 
	CamWriteCmosSensor(0x312D, 0xE4);
	CamWriteCmosSensor(0x3170, 0x29); 
	CamWriteCmosSensor(0x3171, 0x9A);

#ifdef MT9P012_REV8_SUPPORT
	if (MT9P012_curr_rev == MT9P012_REV8)
	{
        CamWriteCmosSensor(0x308E, 0xD6);
        CamWriteCmosSensor(0x308f, 0x6A);	
        CamWriteCmosSensor(0x3090, 0x56);
        CamWriteCmosSensor(0x3091, 0x6A);	
        CamWriteCmosSensor(0x3088, 0x6E);
        CamWriteCmosSensor(0x3089, 0x61);	
        CamWriteCmosSensor(0x3092, 0x0A);
        CamWriteCmosSensor(0x3093, 0x52);	
        CamWriteCmosSensor(0x3094, 0x46);
        CamWriteCmosSensor(0x3095, 0x56);	
        CamWriteCmosSensor(0x3096, 0x56);
        CamWriteCmosSensor(0x3097, 0x52);	
        CamWriteCmosSensor(0x30CA, 0x80);
        CamWriteCmosSensor(0x30cb, 0x06);	
        CamWriteCmosSensor(0x312A, 0xDD);
        CamWriteCmosSensor(0x312b, 0x02);	
        CamWriteCmosSensor(0x312C, 0x00);
        CamWriteCmosSensor(0x312d, 0xE4);	
        CamWriteCmosSensor(0x3170, 0x29);
        CamWriteCmosSensor(0x3171, 0x9A);	
		// New analog chain tiMing, to reduce cluster defects, this require Minimum VAA of 2.6V
        CamWriteCmosSensor(0x309C, 0x19); 
        CamWriteCmosSensor(0x309D, 0x00);
        CamWriteCmosSensor(0x309E, 0x5D); 
        CamWriteCmosSensor(0x309F, 0x00);
	}
#endif

	CamWriteCmosSensor(0x0104, 0x00);	//parameter_hold
	//Soso remove the code from preview function to init function
	//Please refer to the MAUI_02279334
	CamWriteCmosSensor(0x301A, 0x10);		//Enable SMIA clock
	CamWriteCmosSensor(0x301B, 0xCC);

	//CamWriteCmosSensor(0x3064, 0x08);//smia test:[0:3]smia_test_pfd,[4]smia_test_dp_bypass,[5]smia_test_scaler_pattern_test,[6]smia_test_scaler_bist
	//CamWriteCmosSensor(0x3065, 0x05);//[7]smia_test_fifo_sam_bist,[8]smia_test_embedded_data,[9]smia_test_pll_bypass,[10:11]smia_test_pll_lock_mode
	CamWriteCmosSensor(0x3088, 0x6F);//dac_ld_8_9:[0:3]ana_sreg_vdac_vtx_lo,[4:7]ana_sreg_vdac_vtx_hi
	CamWriteCmosSensor(0x3089, 0xF6);//[8:11]ana_sreg_vdac_vrst_lo,[12:15]ana_sreg_vdac_vrst_hi
	CamWriteCmosSensor(0x3154, 0x02);//global boost:[0:7]global_boost_lower_edge,[8:15]global_boost_upper_edge
	CamWriteCmosSensor(0x3155, 0x82);
	CamWriteCmosSensor(0x3156, 0x03);//global done:[0:7]global_done_lower_edge,[8:15]global_done_upper_edge
	CamWriteCmosSensor(0x3157, 0x81);
	CamWriteCmosSensor(0x3162, 0x04);//global rst end
	CamWriteCmosSensor(0x3163, 0xCE);
}

/*************************************************************************
* FUNCTION
*	MT9P012GetID
*
* DESCRIPTION
*	This function return the sensor read/write id of SCCB interface.
*
* PARAMETERS
*	*sensor_write_id : address pointer of sensor write id
*  *sensor_read_id  : address pointer of sensor read id
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void MT9P012GetID(kal_uint8 *sensor_write_id, kal_uint8 *sensor_read_id)
{
	*sensor_write_id = MT9P012_SLV3_WRITE_ID;
	*sensor_read_id = MT9P012_SLV3_READ_ID;
}	/* MT9P012GetID */

/*************************************************************************
* FUNCTION
*	MT9P012_get_size
*
* DESCRIPTION
*	This function return the image width and height of image sensor.
*
* PARAMETERS
*	*sensor_width : address pointer of horizontal effect pixels of image sensor
*  *sensor_height : address pointer of vertical effect pixels of image sensor
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void MT9P012_get_size(kal_uint16 *sensor_width, kal_uint16 *sensor_height)
{
	*sensor_width=MT9P012_IMAGE_SENSOR_FULL_WIDTH;			/* pixel numbers actually used in one frame */
	*sensor_height=MT9P012_IMAGE_SENSOR_FULL_HEIGHT;		/* line numbers actually used in one frame */
}	/* MT9P012_get_size */

/*************************************************************************
* FUNCTION
*	MT9P012_get_period
*
* DESCRIPTION
*	This function return the image width and height of image sensor.
*
* PARAMETERS
*	*pixel_number : address pointer of pixel numbers in one period of HSYNC
*  *line_number : address pointer of line numbers in one period of VSYNC
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void MT9P012_get_period(kal_uint16 *pixel_number, kal_uint16 *line_number)
{
	*pixel_number=MT9P012_PV_PERIOD_PIXEL_NUMS+MT9P012SensorStatus.PvDummyPixels;		/* pixel numbers in one period of HSYNC */
	*line_number=MT9P012_PV_PERIOD_LINE_NUMS+MT9P012SensorStatus.PvDummyLines;			/* line numbers in one period of VSYNC */
}	/* MT9P012_get_period */

/*************************************************************************
* FUNCTION
*	MT9P012_set_dummy
*
* DESCRIPTION
*	This function set dummys of MT9P012 to change line times and frame times.
*
* PARAMETERS
*	Line_Length : pixels in a line
*     Frame_Length: lines ina frame      
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void MT9P012SetDummy(kal_uint16 Line_Length,kal_uint16 Frame_Length)
{
    ASSERT(Line_Length<0xffff);
    ASSERT(Frame_Length<0xffff);
	
    CamWriteCmosSensor(0x0104, 0x01);	//Grouped parameter hold
    CamWriteCmosSensor(0x0342, Line_Length>>8);	    //LINE_LENGTH_PCK
    CamWriteCmosSensor(0x0343, Line_Length&0xFF); 			
    CamWriteCmosSensor(0x0340, Frame_Length>>8);	//FRAME_LENGTH_LINES
    CamWriteCmosSensor(0x0341, Frame_Length&0xFF); 			
    CamWriteCmosSensor(0x0104, 0x00);    //Grouped parameter hold
}

/*************************************************************************
* FUNCTION
*	MT9P012WriteShutter
*
* DESCRIPTION
*	This function set e-shutter of MT9P012 to change exposure time.
*
* PARAMETERS
*	shutter : exposured lines
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void MT9P012WriteShutter(kal_uint16 shutter)
{
    CamWriteCmosSensor(0x0104, 0x01);//Grouped parameter hold	
    CamWriteCmosSensor(0x0202,shutter>>8);
    CamWriteCmosSensor(0x0203,shutter&0xFF);
    CamWriteCmosSensor(0x0104, 0x00);		//parameter_hold
}	/* MT9P012WriteShutter */

/*************************************************************************
* FUNCTION
*	MT9P012_set_shutter
*
* DESCRIPTION
*	This function set e-shutter of MT9P012 to change exposure time.
*
* PARAMETERS
*	shutter : exposured lines
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void MT9P012SetShutter(kal_uint16 shutter)
{
 MT9P012SensorStatus.ExposureLines=shutter;
 MT9P012WriteShutter(shutter);
}

/*************************************************************************
* FUNCTION
*	MT9P012SetGain
*
* DESCRIPTION
*	This function is to set global gain to sensor.
*
* PARAMETERS
*	gain : sensor global gain(base: 0x40)
*
* RETURNS
*	the actually gain set to sensor.
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint16 MT9P012SetGain(kal_uint16 gain)
{
	kal_uint32 reg_gain;
	
   	MT9P012WriteGain(gain);
  	reg_gain=(MT9P012SensorStatus.GlobalGain*BASEGAIN)/MT9P012SensorStatus.SensorGainBase;
  	
  	return reg_gain;
}
/*************************************************************************
* FUNCTION
*	MT9P012FixVideoFrameRate
*
* DESCRIPTION
*	This function is to set dummy line to sensor for video fixed frame rate.
*
* PARAMETERS
*	framerate : Video Fix frame rate 
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/

static void MT9P012FixVideoFrameRate(kal_uint16 framerate)
{
	kal_uint32 dummy;

if (framerate>=300)
	MT9P012SensorStatus.VideoCurrentFrameRate=300;
else if(framerate>=240)
	MT9P012SensorStatus.VideoCurrentFrameRate=240;
else if(framerate>=200)
	MT9P012SensorStatus.VideoCurrentFrameRate=200;
else if(framerate>=150)
	MT9P012SensorStatus.VideoCurrentFrameRate=150;
else if(framerate>=120)
	MT9P012SensorStatus.VideoCurrentFrameRate=120;
else if(framerate>=100)
	MT9P012SensorStatus.VideoCurrentFrameRate=100;
else if(framerate>=75)
	MT9P012SensorStatus.VideoCurrentFrameRate=75;
else if(framerate>=50)
	MT9P012SensorStatus.VideoCurrentFrameRate=50;
else
	ASSERT(0);

    MT9P012SensorStatus.VideoMaxLineLength = (kal_uint16)((MT9P012SensorStatus.PrvPclk*1000000*10/MT9P012SensorStatus.VideoCurrentFrameRate)
                                              /(MT9P012_PV_PERIOD_LINE_NUMS+MT9P012SensorStatus.PvDummyLines));
   /*Auto mode 15fps-2901 ,12fps-3626,  night mode 7.5fps-5802,5fps-8703*/

if (MT9P012SensorStatus.VideoMaxLineLength < (MT9P012_PV_PERIOD_PIXEL_NUMS+MT9P012SensorStatus.PvDummyPixels))			
	MT9P012SensorStatus.VideoMaxLineLength = (MT9P012_PV_PERIOD_PIXEL_NUMS+MT9P012SensorStatus.PvDummyPixels);	

    MT9P012SetDummy((MT9P012SensorStatus.VideoMaxLineLength*2),(MT9P012_PV_PERIOD_LINE_NUMS+MT9P012SensorStatus.PvDummyLines));

}


/*************************************************************************
* FUNCTION
*	MT9P012NightMode
*
* DESCRIPTION
*	This function night mode of MT9P012.
*
* PARAMETERS
*	none
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void MT9P012NightMode(kal_bool enable)
{

}	/* MT9P012NightMode */

static void MT9P012SetFlashlight (kal_bool enable)
{
	//flashlight_power_on(enable);
	FlashlightPowerOn(MT9P012SensorIdx, enable);
}  

void MT9P012GetSensorAeInfo(IMAGE_SENSOR_AE_INFO_STRUCT *pInfo)
{
    pInfo->DefaultPrevLinePixels = MT9P012_PV_PERIOD_PIXEL_NUMS;
    pInfo->CurrentPrevLinePixels =MT9P012_PV_PERIOD_PIXEL_NUMS+MT9P012SensorStatus.PvDummyPixels;
	pInfo->CurrentPclk=MT9P012SensorStatus.PrvPclk*1000000;

}

kal_uint32 MT9P012GetImageSensorFullWidth(void){
	return MT9P012_IMAGE_SENSOR_FULL_WIDTH;
}

// write camera_para to sensor register
void MT9P012CameraParaToSensor(nvram_camera_para_struct *pCameraPara)
{
	kal_uint32	i;
	for(i=0; 0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr; i++)
	{
		CamWriteCmosSensor(pCameraPara->SENSOR.reg[i].addr, pCameraPara->SENSOR.reg[i].para);
	}
	for(i=ENGINEER_START_ADDR; 0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr; i++)
	{
		CamWriteCmosSensor(pCameraPara->SENSOR.reg[i].addr,pCameraPara->SENSOR.reg[i].para);
	}
	for(i=FACTORY_START_ADDR+1; i<5; i++)
	{
		CamWriteCmosSensor(pCameraPara->SENSOR.cct[i].addr,pCameraPara->SENSOR.cct[i].para);
	}
}

// update camera_para from sensor register 
void MT9P012SensorToCameraPara(nvram_camera_para_struct *pCameraPara)
{
	kal_uint32	i;
	for(i=0; 0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr; i++)
	{
		pCameraPara->SENSOR.reg[i].para = CamReadCmosSensor(pCameraPara->SENSOR.reg[i].addr);
	}

	for(i=ENGINEER_START_ADDR; 0xFFFFFFFF!=pMT9P012NvramSensorData->reg[i].addr; i++)
	{
		pCameraPara->SENSOR.reg[i].para = CamReadCmosSensor(pCameraPara->SENSOR.reg[i].addr);
	}

}

//------------------------Engineer mode---------------------------------

void  MT9P012GetSensorGroupCount(kal_int32* sensor_count_ptr)
{
   *sensor_count_ptr=GROUP_TOTAL_NUMS;
   
	return;
}
    
extern int sprintf(char *buffer, const char *format, ... ); 
  
void MT9P012GetSensorGroupInfo(kal_uint16 group_idx, kal_int8* group_name_ptr, kal_int32* item_count_ptr)
{
   switch (group_idx)
   {
		case PRE_GAIN:
			kal_sprintf((kal_char *)group_name_ptr, "CCT");
			*item_count_ptr = 5;
		break;
		case CMMCLK_CURRENT:
			kal_sprintf((kal_char *)group_name_ptr, "CMMCLK Current");
			*item_count_ptr = 1;
		break;		
		case FRAME_RATE_LIMITATION:
			kal_sprintf((kal_char *)group_name_ptr, "Frame Rate Limitation");
			*item_count_ptr = 2;
		break;
		case REGISTER_EDITOR:
			kal_sprintf((kal_char *)group_name_ptr, "Register Editor");
			*item_count_ptr = 2;
		break;		
		default:
		   ASSERT(0);
	}
}

void MT9P012GetSensorItemInfo(kal_uint16 group_idx,kal_uint16 item_idx, CAL_CCT_SENSOR_ITEM_INFO_STRUCT* info_ptr)
{
	kal_int16 TempReg=0;
	kal_uint16 TempGain=0, TempAddr=0, TempPara=0;
	
	switch (group_idx)
	{
		case PRE_GAIN:
			switch (item_idx)
			{
				case 0:
				  kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"Pregain-R");
					TempAddr = PRE_GAIN_R_INDEX;
				break; 
				case 1:
				  kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"Pregain-Gr");
					TempAddr = PRE_GAIN_Gr_INDEX;
				break;
				case 2:
				  kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"Pregain-Gb");
					TempAddr = PRE_GAIN_Gb_INDEX;
				break;
				case 3:
				  kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"Pregain-B");
					TempAddr = PRE_GAIN_B_INDEX;
				break;
				case 4:
				   kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"SENSOR_BASEGAIN");
				   TempAddr = SENSOR_BASEGAIN;
				break;
				default:
				   ASSERT(0);		
			}
			
			TempPara=pMT9P012NvramSensorData->cct[TempAddr].para;
			
			if(TempPara>=0x08 && TempPara<=0xFF)
				TempGain=(TempPara*BASEGAIN)/8;
			else if(TempPara>0xFF && TempPara<=0x1FF)
				TempGain=(TempPara*BASEGAIN)/8;
			else
				ASSERT(0);
			
			TempGain=(TempGain*1000)/BASEGAIN;
			
			info_ptr->ItemValue=TempGain;
				  info_ptr->IsTrueFalse=KAL_FALSE;
				  info_ptr->IsReadOnly=KAL_FALSE;
				  info_ptr->IsNeedRestart=KAL_FALSE;
				  info_ptr->Min=1000;
				  info_ptr->Max=15875;
				break;
		case CMMCLK_CURRENT:
			switch (item_idx)
			{
				case 0:
				  kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"Drv Cur[2,4,6,8]mA");
				  
				  TempReg=pMT9P012NvramSensorData->reg[CMMCLK_CURRENT_INDEX].para;
				  if(TempReg==ISP_DRIVING_2MA)
				  {
				      info_ptr->ItemValue=2;
				  }
				  else if(TempReg==ISP_DRIVING_4MA)
				  {
				      info_ptr->ItemValue=4;
				  }
				  else if(TempReg==ISP_DRIVING_6MA)
				  {
				      info_ptr->ItemValue=6;
				  }
				  else if(TempReg==ISP_DRIVING_8MA)
				  {
				      info_ptr->ItemValue=8;
				  }
				  
				  info_ptr->IsTrueFalse=KAL_FALSE;
				  info_ptr->IsReadOnly=KAL_FALSE;
				  info_ptr->IsNeedRestart=KAL_TRUE;
				  info_ptr->Min=2;
				  info_ptr->Max=8;
				break;
				default:
				   ASSERT(0);
			}
		break;
		case FRAME_RATE_LIMITATION:
			switch (item_idx)
			{
				case 0:
				  kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"Max Exposure Lines");
				  info_ptr->ItemValue=MT9P012_LIMIT_EXPOSURE_LINES;
				  info_ptr->IsTrueFalse=KAL_FALSE;
				  info_ptr->IsReadOnly=KAL_TRUE;
				  info_ptr->IsNeedRestart=KAL_FALSE;
				  info_ptr->Min=0;
				  info_ptr->Max=0;
				break;
				case 1:
				  kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"Min Frame Rate");
				  info_ptr->ItemValue=MT9P012_MIN_FRAME_RATE;
				  info_ptr->IsTrueFalse=KAL_FALSE;
				  info_ptr->IsReadOnly=KAL_TRUE;
				  info_ptr->IsNeedRestart=KAL_FALSE;
				  info_ptr->Min=0;
				  info_ptr->Max=0;
				break;
				default:
				   ASSERT(0);
			}
		break;
		case REGISTER_EDITOR:
			switch (item_idx)
			{
				case 0:
				  kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"REG Addr.");
				  info_ptr->ItemValue=0;
				  info_ptr->IsTrueFalse=KAL_FALSE;
				  info_ptr->IsReadOnly=KAL_FALSE;
				  info_ptr->IsNeedRestart=KAL_FALSE;
				  info_ptr->Min=0;
				  info_ptr->Max=0xFFFF;
				break;
				case 1:
				  kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"REG Value");
				  info_ptr->ItemValue=0;
				  info_ptr->IsTrueFalse=KAL_FALSE;
				  info_ptr->IsReadOnly=KAL_FALSE;
				  info_ptr->IsNeedRestart=KAL_FALSE;
				  info_ptr->Min=0;
				  info_ptr->Max=0xFFFF;
				break;
				default:
				   ASSERT(0);		
			}
		break;
		default:
			ASSERT(0); 
	}
}

kal_bool MT9P012SetSensoItemInfo(kal_uint16 group_idx, kal_uint16 item_idx, kal_int32 ItemValue)
{
//   kal_int16 TempReg;
   kal_uint16 TempGain=0, TempAddr=0, TempPara=0;
   
   switch (group_idx)
	{
		case PRE_GAIN:
			switch (item_idx)
			{
				case 0:
				  TempAddr = PRE_GAIN_R_INDEX;
				break;
				case 1:
				  TempAddr = PRE_GAIN_Gr_INDEX;
				break;
				case 2:
				  TempAddr = PRE_GAIN_Gb_INDEX;
				break;
				case 3:
				  TempAddr = PRE_GAIN_B_INDEX;
				break;
				case 4:
				  TempAddr = SENSOR_BASEGAIN;
				break;
				default:
				   ASSERT(0);		
			}
			
			TempGain=((ItemValue*BASEGAIN+500)/1000);			//+500:get closed integer value
			
			if(TempGain>=1*BASEGAIN && TempGain<=15*BASEGAIN)
			{
			   TempPara=(TempGain*8+BASEGAIN/2)/BASEGAIN;					
			}
			else if(TempGain>=16*BASEGAIN)
			{
			   TempPara=(15.875*BASEGAIN*8+BASEGAIN/2)/BASEGAIN;
			}
			else
				return KAL_FALSE;
			
			pMT9P012NvramSensorData->cct[TempAddr].para = TempPara;
			if(TempAddr != SENSOR_BASEGAIN)
			{
			CamWriteCmosSensor(pMT9P012NvramSensorData->cct[TempAddr].addr,TempPara);
			}
      
			MT9P012SensorStatus.SensorGainBase=MT9P012ReadGain();      
			if(TempAddr == SENSOR_BASEGAIN)
			{
			    MT9P012WriteGain(BASEGAIN);
			}			
		break;
		case CMMCLK_CURRENT:
			switch (item_idx)
			{
				case 0:
				  if(ItemValue==2)
				  {
				      pMT9P012NvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_2MA;
				      SetIspDrivingCurrent(ISP_DRIVING_2MA);
				  }
				  else if(ItemValue==3 || ItemValue==4)
				  {
				      pMT9P012NvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_4MA;
				      SetIspDrivingCurrent(ISP_DRIVING_4MA);
				  }
				  else if(ItemValue==5 || ItemValue==6)
				  {
				      pMT9P012NvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_6MA;
				      SetIspDrivingCurrent(ISP_DRIVING_6MA);
				  }
				  else
				  {
				      pMT9P012NvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_8MA;
				      SetIspDrivingCurrent(ISP_DRIVING_8MA);
				  }
				break;
				default:
				   ASSERT(0);
			}
		break;
		case FRAME_RATE_LIMITATION:
			switch (item_idx)
			{
				   ASSERT(0);	
			}
		break;
		case REGISTER_EDITOR:
			switch (item_idx)
			{
				case 0:
				  MT9P012_FAC_SENSOR_REG=ItemValue;
				break;
				case 1:
				  CamWriteCmosSensor(MT9P012_FAC_SENSOR_REG,ItemValue);
				break;
				default:
				   ASSERT(0);		
			}
		break;
		default:
		   ASSERT(0);
	}
	
	return KAL_TRUE;
}

void MT9P012GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT pSensorInfo)
{
    pSensorInfo->SensorId=MT9P012_SENSOR_ID;
    pSensorInfo->SensorIf=IMAGE_SENSOR_IF_PARALLEL;
    pSensorInfo->PreviewNormalDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_B_FIRST;
    pSensorInfo->PreviewHMirrorDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gb_FIRST;
    pSensorInfo->PreviewVMirrorDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gr_FIRST;
    pSensorInfo->PreviewHVMirrorDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_R_FIRST;    
    pSensorInfo->CaptureDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_B_FIRST;
    pSensorInfo->PixelClkInv=KAL_FALSE;
    pSensorInfo->PixelClkPolarity=POLARITY_LOW;
    pSensorInfo->HsyncPolarity=POLARITY_LOW;
    pSensorInfo->VsyncPolarity=POLARITY_HIGH;
    pSensorInfo->PreviewMclkFreq = 52000000;
    pSensorInfo->CaptureMclkFreq = 52000000;
    pSensorInfo->VideoMclkFreq = 52000000;
    pSensorInfo->PreviewWidth=MT9P012_IMAGE_SENSOR_PV_WIDTH;
    pSensorInfo->PreviewHeight=MT9P012_IMAGE_SENSOR_PV_HEIGHT;
    pSensorInfo->FullWidth=MT9P012_IMAGE_SENSOR_FULL_WIDTH;
    pSensorInfo->FullHeight=MT9P012_IMAGE_SENSOR_FULL_HEIGHT;
    pSensorInfo->SensorAfSupport=KAL_FALSE;
    pSensorInfo->SensorFlashSupport=KAL_FALSE;
} /* MT9P012GetSensorInfo() */

static kal_uint16 MT9P012PowerOn(void)
{
    const kal_uint8 i2c_addr[4] = {MT9P012_SLV1_WRITE_ID, MT9P012_SLV2_WRITE_ID, MT9P012_SLV3_WRITE_ID, MT9P012_SLV4_WRITE_ID};

    kal_uint16 SensorId=NULL_SENSOR_ID;
    kal_uint8 i=0;

    /* PowerOn the sensor */
    CisModulePowerOn(MT9P012SensorIdx, KAL_TRUE);
    CameraSccbOpen(CAMERA_SCCB_SENSOR, MT9P012_SLV3_WRITE_ID, CAMERA_SCCB_16BIT, CAMERA_SCCB_8BIT, 320);
	kal_sleep_task(1);	/* delay for power stable */
	
    /* set sensors chip enable pin to low to activate SIV100B */
    //CamPdnPinCtrl(MT9P012SensorIdx, 0);
	
    /* Reset the sensor */
	CamRstPinCtrl(MT9P012SensorIdx, 1);
    /* delay for stable sensor */  
	kal_sleep_task(3);
	
    CamWriteCmosSensor(0x0103, 0x01);	// SOFTWARE_RESET (clears itself)

	for (i = 0; i < sizeof(i2c_addr) / sizeof(i2c_addr[0]); i++)
	  {
	   /* SensorSccbData.HWSccbSlaveAddress=i2c_addr[i];
		SensorSccbData.SWSccbWriteID = i2c_addr[i];
		SensorSccbData.SWSccbReadID = i2c_addr[i]|1;*/
		
		SensorId = (CamReadCmosSensor(0x0000) << 8)|CamReadCmosSensor(0x0001);
		if (SensorId == MT9P012_SENSOR_ID)
		{
#ifdef __MT9P012_DEBUG_TRACE__
		  kal_print_string_trace(MOD_ENG, TRACE_WARNING, "I2C address: %x", MT9P012SensorStatus.WriteSWSccbAddress);
#endif
		  break;
		}
	  }

    return SensorId;
} /* MT9P012PowerOn() */

kal_uint32 MT9P012DetectSensorId(void)
{
  MM_ERROR_CODE_ENUM MT9P012SensorClose(void);
  kal_uint16 MT9P012PowerOn();
  kal_uint16 sensorId, AnotherSensorIdx;
  kal_int8 i, j;
  
  if (IMAGE_SENSOR_MAIN == MT9P012SensorIdx)
  {
    AnotherSensorIdx = IMAGE_SENSOR_SUB;
  }
  else
  {
    AnotherSensorIdx = IMAGE_SENSOR_MAIN;
  }
  for (i = 1; i >= 0; i--)
  {
    for (j = 1; j >= 0; j--)
    {
      CamRstPinCtrl(AnotherSensorIdx, i);
      CamPdnPinCtrl(AnotherSensorIdx, j);
      sensorId = MT9P012PowerOn();
      MT9P012SensorClose();
#ifdef MT9P012_DBG
      kal_wap_trace(MOD_ENG,TRACE_INFO,"MT9P012 DetectSensorId:%x",sensorId);
#endif
      if (MT9P012_SENSOR_ID == sensorId)
      {
        return MT9P012_SENSOR_ID;
      }
    }
  }
  return MM_ERROR_SENSOR_READ_ID_FAIL;
}   /* MT9P012DetectSensorId() */

MM_ERROR_CODE_ENUM MT9P012SensorOpen(void)
{
    IspSetInterruptTriggerDelayLines(1);	// 0: VD INT, others: TG INT & start line

    if (MT9P012PowerOn()!= MT9P012_SENSOR_ID)
        return MM_ERROR_SENSOR_READ_ID_FAIL;

	MT9P012InitialSetting();
	MT9P012SensorStatus.SensorGainBase = MT9P012ReadGain();
	MT9P012SensorStatus.GlobalGain=BASEGAIN;
	
	MT9P012SensorStatus.SensorExpoWidth=1;
	MT9P012SensorStatus.CurrentSensorExpoWidth=1;

    return MM_ERROR_NONE;
} /* MT9P012SensorOpen() */

static void MT9P012Preview(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{

	kal_uint32 backup_MT9P012_PvDummyLines;
	 
	MT9P012SensorStatus.CurrentSensorExpoWidth=MT9P012SensorStatus.SensorExpoWidth;
	 
	MT9P012SensorStatus.PvMode=1;
	
	MT9P012SensorStatus.PvDummyPixels = 0;//220;					
	MT9P012SensorStatus.PvDummyLines = 0;	
	
	MT9P012SensorStatus.SensorExpoWidth=MT9P012_PV_PERIOD_PIXEL_NUMS+MT9P012SensorStatus.PvDummyPixels;
	MT9P012SensorStatus.CurrentSensorExpoWidth=MT9P012SensorStatus.SensorExpoWidth;
   
    #if defined(DRV_ISP_MT6236_HW_SUPPORT)
		 MT9P012Input52MHzMclkOuptu48MHzPclk();
    #endif
	
	MT9P012SensorStatus.PrvPclk = 48;//MHz
    MT9P012SetMirrorFlip(pParaIn->ImageMirror);

    MT0P012SetSXGAMode();


	backup_MT9P012_PvDummyLines = MT9P012SensorStatus.PvDummyLines;
	 if ( MT9P012SensorStatus.ExposureLines > (MT9P012_PV_PERIOD_LINE_NUMS+MT9P012SensorStatus.PvDummyLines)) 
		 {
		 MT9P012SensorStatus.PvDummyLines = MT9P012SensorStatus.ExposureLines - MT9P012_PV_PERIOD_LINE_NUMS;
		 }
	
	MT9P012SetDummy(((MT9P012_PV_PERIOD_PIXEL_NUMS+MT9P012SensorStatus.PvDummyPixels)*2),(MT9P012_PV_PERIOD_LINE_NUMS+MT9P012SensorStatus.PvDummyLines));
	 
	MT9P012SensorStatus.PvDummyLines = backup_MT9P012_PvDummyLines;

    pParaOut->GrabStartX = MT9P012_IMAGE_SENSOR_PV_INSERTED_PIXELS;
    pParaOut->GrabStartY = MT9P012_IMAGE_SENSOR_PV_INSERTED_LINES;
    pParaOut->ExposureWindowWidth = MT9P012_IMAGE_SENSOR_PV_WIDTH;
    pParaOut->ExposureWindowHeight = MT9P012_IMAGE_SENSOR_PV_HEIGHT;

    MT9P012WriteShutter(MT9P012SensorStatus.ExposureLines);

}/* MT9P012Preview */


void MT9P012GetPreviewFlashlightInfo(P_FLASHLIGHT_PREVIEW_PARA_STURCT pPreviewInfo)
{
    pPreviewInfo->pixels = MT9P012_PV_PERIOD_PIXEL_NUMS+MT9P012SensorStatus.PvDummyPixels;
    pPreviewInfo->lines = MT9P012_IMAGE_SENSOR_PV_HEIGHT;
    pPreviewInfo->frame_lines = MT9P012_PV_PERIOD_LINE_NUMS+MT9P012SensorStatus.PvDummyLines;
    //flashlight_sensor_preview_config(&flashlight_preview_para, pParaIn);
}

static void MT9P012Capture(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{
	volatile kal_int32 Shutter=MT9P012SensorStatus.ExposureLines;
	float ShutterTemp=MT9P012SensorStatus.ExposureLines;
	  
	MT9P012SensorStatus.CapPclk=48;


    if(KAL_TRUE==pParaIn->EnableShutterTransfer)
    {
        Shutter=pParaIn->CaptureShutter;
        ShutterTemp=(float)pParaIn->CaptureShutter;
    } 

    if ((pParaIn->ImageTargetWidth<=MT9P012_IMAGE_SENSOR_PV_WIDTH)&&
        (pParaIn->ImageTargetHeight<=MT9P012_IMAGE_SENSOR_PV_HEIGHT))
    {
    
	MT9P012SensorStatus.PvMode=1;
	  
    //#ifdef CAM_OTF_CAPTURE
	if (CAL_RAW_CAPTURE_MODE_OTF==pParaIn->CaptureScenario)
      {
	  MT9P012SensorStatus.CapDummyLines = 0;
	
	  if (100==pParaIn->ZoomFactor) /* 1x capture */
	
		  MT9P012SensorStatus.CapDummyPixels = 0;
	  
	  else if(pParaIn->ZoomFactor<200)/* 1x~2x capture */
	
		  MT9P012SensorStatus.CapDummyPixels = 500;
	
	  else if(pParaIn->ZoomFactor<=400)/* 2x~4x capture */
	
		  MT9P012SensorStatus.CapDummyPixels = 1800;
	
	  else /* 4x~8x capture */
			  
		  MT9P012SensorStatus.CapDummyPixels = 2200;
	}
	else
    //#else
		{
	  MT9P012SensorStatus.CapDummyPixels = 0;			  
	  MT9P012SensorStatus.CapDummyLines = 0;
		}
    //#endif
	  
	  ShutterTemp = (ShutterTemp * (MT9P012_PV_PERIOD_PIXEL_NUMS+MT9P012SensorStatus.PvDummyPixels)) / ((MT9P012_PV_PERIOD_PIXEL_NUMS+MT9P012SensorStatus.CapDummyPixels));
	  MT9P012SetDummy(((MT9P012_PV_PERIOD_PIXEL_NUMS+MT9P012SensorStatus.CapDummyPixels)*2),(MT9P012_PV_PERIOD_LINE_NUMS+MT9P012SensorStatus.CapDummyLines));
            pParaOut->GrabStartX = MT9P012_IMAGE_SENSOR_PV_INSERTED_PIXELS;
            pParaOut->GrabStartY = MT9P012_IMAGE_SENSOR_PV_INSERTED_LINES;
            pParaOut->ExposureWindowWidth = MT9P012_IMAGE_SENSOR_PV_WIDTH;
            pParaOut->ExposureWindowHeight = MT9P012_IMAGE_SENSOR_PV_HEIGHT;
        }
    
    else  //>1.3M
    {
		MT9P012SensorStatus.PvMode=1;
		  
     //#ifdef CAM_OTF_CAPTURE
	 if (CAL_RAW_CAPTURE_MODE_OTF==pParaIn->CaptureScenario)
        {
	    MT9P012SensorStatus.HighSpeedCapture=KAL_FALSE;
		
        /* Check Zoom Factor */
        if (100==pParaIn->ZoomFactor)  //1x capture
            #if defined(DRV_ISP_MT6236_HW_SUPPORT)	  
				 MT9P012SensorStatus.CapDummyPixels=200;
            #else
				 MT9P012SensorStatus.CapDummyPixels=0;
            #endif

        else if(pParaIn->ZoomFactor<200)//1x~2x capture
			MT9P012SensorStatus.CapDummyPixels=MT9P012SensorStatus.CapPclk*1000000/MT9P012_FULL_PERIOD_LINE_NUMS/MT9P012_2X_ZOOM_IN_CAPTURE_FRAME-MT9P012_FULL_PERIOD_PIXEL_NUMS;
        else if(pParaIn->ZoomFactor<=400)//2x~4x capture
			MT9P012SensorStatus.CapDummyPixels=MT9P012SensorStatus.CapPclk*1000000/MT9P012_FULL_PERIOD_LINE_NUMS/MT9P012_4X_ZOOM_IN_CAPTURE_FRAME-MT9P012_FULL_PERIOD_PIXEL_NUMS;
        else //4x~8x capture
			MT9P012SensorStatus.CapDummyPixels=MT9P012SensorStatus.CapPclk*1000000/MT9P012_FULL_PERIOD_LINE_NUMS/MT9P012_8X_ZOOM_IN_CAPTURE_FRAME-MT9P012_FULL_PERIOD_PIXEL_NUMS;
	 	}
    //#elif CAM_OFFLINE_CAPTURE
	else if (CAL_RAW_CAPTURE_MODE_OFFLINE==pParaIn->CaptureScenario)
		{
	    #if defined(DRV_ISP_MT6236_HW_SUPPORT)					
                MT9P012SensorStatus.HighSpeedCapture=KAL_TRUE;					
                MT9P012SensorStatus.CapDummyPixels = 0;
	    #else /*MT6239 & MT6268*/			
                MT9P012SensorStatus.HighSpeedCapture=KAL_FALSE;                
                MT9P012SensorStatus.CapDummyPixels = 0;	 						
	    #endif
		}
	else
	//#else ////CAM_STANDARD_CAPTURE
		{
        #if defined(DRV_ISP_MT6236_HW_SUPPORT)
        if (pParaIn->ZoomFactor>100)
        {
			MT9P012SensorStatus.HighSpeedCapture=KAL_TRUE;
			MT9P012SensorStatus.CapDummyPixels = 0;
        }
        else
        {
			MT9P012SensorStatus.HighSpeedCapture=KAL_FALSE; 			 
			MT9P012SensorStatus.CapDummyPixels = 300; //8fps
        }
		#else
		    MT9P012SensorStatus.HighSpeedCapture=KAL_FALSE;
            MT9P012SensorStatus.CapDummyPixels = 0;	
        #endif
		}
	//#endif	

	if(MT9P012SensorStatus.HighSpeedCapture==KAL_TRUE)
		 {
		 MT9P012SetQSXGAMode_HS();
		 MT9P012SetMirrorFlip(pParaIn->ImageMirror);
		 MT9P012SensorStatus.CapPclk=64;//68;//MHz
	   
		 ShutterTemp = (ShutterTemp * (MT9P012_PV_PERIOD_PIXEL_NUMS+MT9P012SensorStatus.PvDummyPixels)*2*MT9P012SensorStatus.CapPclk) / ((MT9P012_FULL_HS_PERIOD_PIXEL_NUMS+MT9P012SensorStatus.CapDummyPixels)*MT9P012SensorStatus.PrvPclk);	   
		 MT9P012SetDummy((MT9P012_FULL_HS_PERIOD_PIXEL_NUMS+MT9P012SensorStatus.CapDummyPixels),MT9P012_FULL_HS_PERIOD_LINE_NUMS+(MT9P012SensorStatus.CapDummyLines));
		 }
	 else
		 {
		 MT9P012SetQSXGAMode();
		 MT9P012SensorStatus.CapPclk=48;//MHz
	   
		 ShutterTemp=(ShutterTemp*(MT9P012_PV_PERIOD_PIXEL_NUMS+MT9P012SensorStatus.PvDummyPixels)+(MT9P012_FULL_PERIOD_PIXEL_NUMS+MT9P012SensorStatus.CapDummyPixels)*0.5)/((MT9P012_FULL_PERIOD_PIXEL_NUMS+MT9P012SensorStatus.CapDummyPixels));
		 MT9P012SetDummy(((MT9P012_FULL_PERIOD_PIXEL_NUMS+MT9P012SensorStatus.CapDummyPixels)*2),(MT9P012_FULL_PERIOD_LINE_NUMS+MT9P012SensorStatus.CapDummyLines));
		 }

        pParaOut->GrabStartX = MT9P012_IMAGE_SENSOR_FULL_INSERTED_PIXELS;
        pParaOut->GrabStartY = MT9P012_IMAGE_SENSOR_FULL_INSERTED_LINES;
        pParaOut->ExposureWindowWidth = MT9P012_IMAGE_SENSOR_FULL_WIDTH;
        pParaOut->ExposureWindowHeight = MT9P012_IMAGE_SENSOR_FULL_HEIGHT;
    }

    Shutter=ShutterTemp+0.5;

	if(Shutter<1)
        Shutter=1;

	 MT9P012SensorStatus.CapShutter=Shutter;
	
    MT9P012WriteShutter(Shutter);

} /* MT9P012Capture() */


void MT9P012GetCaptureFlashlightInfo(P_FLASHLIGHT_CAPTURE_SENSOR_PARA_IN_STRUCT pParaIn, P_FLASHLIGHT_CAPTURE_PARA_STRUCT pCaptureInfo)
{
    if(KAL_TRUE==MT9P012SensorStatus.PvMode)
    {
       pCaptureInfo->default_pclk = 48000000;
    }
    else
    {
        if (KAL_TRUE==MT9P012SensorStatus.HighSpeedCapture)
        {
            pCaptureInfo->default_pclk=80000000;
        }
        else
        {
            pCaptureInfo->default_pclk=48000000;
        }
    }
    pCaptureInfo->pixels = MT9P012_FULL_PERIOD_PIXEL_NUMS+MT9P012SensorStatus.CapDummyPixels;
    pCaptureInfo->frame_lines = MT9P012_FULL_PERIOD_LINE_NUMS+MT9P012SensorStatus.CapDummyLines;
    pCaptureInfo->lines = MT9P012_IMAGE_SENSOR_FULL_HEIGHT;
    pCaptureInfo->shutter = MT9P012SensorStatus.CapShutter;
    //Shutter = flashlight_sensor_capture_config(&flashlight_capture_para, pParaIn);    
    
}

static void MT9P012Video(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{
	kal_uint32 backup_MT9P012_PvDummyLines;
	 
	MT9P012SensorStatus.CurrentSensorExpoWidth=MT9P012SensorStatus.SensorExpoWidth;
	 
	MT9P012SensorStatus.PvMode=1;

    #if defined(DRV_ISP_MT6236_HW_SUPPORT)
        MT9P012Input52MHzMclkOuptu48MHzPclk();
    #endif

    MT9P012SensorStatus.PrvPclk = 48;//MHz

    MT9P012SetMirrorFlip(pParaIn->ImageMirror);

    MT0P012SetSXGAMode();

	MT9P012FixVideoFrameRate(pParaIn->MaxVideoFrameRate);

    pParaOut->GrabStartX = MT9P012_IMAGE_SENSOR_PV_INSERTED_PIXELS;
    pParaOut->GrabStartY = MT9P012_IMAGE_SENSOR_PV_INSERTED_LINES;
    pParaOut->ExposureWindowWidth = MT9P012_IMAGE_SENSOR_PV_WIDTH;
    pParaOut->ExposureWindowHeight = MT9P012_IMAGE_SENSOR_PV_HEIGHT;
}/* MT9P012Video */



MM_ERROR_CODE_ENUM MT9P012BinningInfo(P_CAL_FEATURE_CTRL_STRUCT pFeatureParaIn,
                                        P_CAL_FEATURE_CTRL_STRUCT pFeatureParaOut,
                                        kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
    P_CAL_FEATURE_CAMERA_BINNING_INFO_STRUCT pBinningInfo=pFeatureParaOut->FeatureInfo.FeatureStructured.pBinningInfo;
    kal_uint8 i;

    switch (pFeatureParaIn->FeatureCtrlCode)
    {
        case CAL_FEATURE_QUERY_OPERATION:
            for (i=CAM_ISO_AUTO;i<=CAM_ISO_400;i++)
            {
                pBinningInfo->IsoBinningInfo[i].MaxResolution=CAM_IMAGE_SIZE_5M;
                pBinningInfo->IsoBinningInfo[i].IsoSupported=KAL_TRUE;
                pBinningInfo->IsoBinningInfo[i].BinningEnable=KAL_FALSE;
            }
            for (;i<=CAM_ISO_1600;i++)
            {
                pBinningInfo->IsoBinningInfo[i].MaxResolution=CAM_IMAGE_SIZE_1M;
                pBinningInfo->IsoBinningInfo[i].IsoSupported=KAL_TRUE;
                pBinningInfo->IsoBinningInfo[i].BinningEnable=KAL_TRUE;
            }
        break;
    }
}   /* MT9P012BinningInfo() */

MM_ERROR_CODE_ENUM MT9P012StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT pFeatureParaIn,
                                               P_CAL_FEATURE_CTRL_STRUCT pFeatureParaOut,
                                               kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
    P_CAL_FEATURE_TYPE_ENUM_STRUCT pStillCaptureSize=(P_CAL_FEATURE_TYPE_ENUM_STRUCT) &(pFeatureParaOut->FeatureInfo.FeatureEnum);

    switch (pFeatureParaIn->FeatureCtrlCode)
    {
        case CAL_FEATURE_QUERY_OPERATION:
            pFeatureParaOut->FeatureType=CAL_FEATURE_TYPE_ENUMERATE;
            pFeatureParaOut->FeatureOperationSupport=CAL_FEATURE_SET_OPERATION|
                                                     CAL_FEATURE_GET_OPERATION|
                                                     CAL_FEATURE_QUERY_OPERATION;
            pFeatureParaOut->FeatureModeSupport=CAL_FEATURE_CAMERA_SUPPORT;
            pStillCaptureSize->IsSupport=KAL_TRUE;
            pStillCaptureSize->ItemCount = 7;
            pStillCaptureSize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
            pStillCaptureSize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
            pStillCaptureSize->SupportItem[2] = CAM_IMAGE_SIZE_1M;
            pStillCaptureSize->SupportItem[3] = CAM_IMAGE_SIZE_2M;
            pStillCaptureSize->SupportItem[4] = CAM_IMAGE_SIZE_3M;
            pStillCaptureSize->SupportItem[5] = CAM_IMAGE_SIZE_4M;
            pStillCaptureSize->SupportItem[6] = CAM_IMAGE_SIZE_5M;
        break;
    }

    return MM_ERROR_NONE;
}   /* MT9P012StillCaptureSize() */

void MT9P012InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT pInitOperPara)
{
	pInitOperPara->CaptureDelayFrame = 2;			/* wait stable frame when sensor change mode (pre to cap) */
	pInitOperPara->PreviewDelayFrame = 2;			/* wait stable frame when sensor change mode (cap to pre) */
	pInitOperPara->PreviewDisplayWaitFrame = 2;	/* wait stable frame when sensor change mode (cap to pre) */
	pInitOperPara->AeCalDelayFrame = 0;			/* The frame of calculation default 0 */
	pInitOperPara->AeShutDelayFrame = 0;			/* The frame of setting shutter default 0 for TG int */
	pInitOperPara->AeSensorGainDelayFrame = 1;	/* The frame of setting sensor gain */
	pInitOperPara->AeIspGainDelayFrame = 2;		/* The frame of setting gain */
	pInitOperPara->AeCalPeriod = 3;				/* AE AWB calculation period */
	#if(defined(LED_FLASHLIGHT_SUPPORT))
       	pInitOperPara->FlashlightMode = FLASHLIGHT_LED_CONSTANT;
	#elif(defined(LED_ONOFF_SUPPORT))
       	pInitOperPara->FlashlightMode = FLASHLIGHT_LED_ONOFF;
	#else
       	pInitOperPara->FlashlightMode = FLASHLIGHT_NONE;
	#endif
  pInitOperPara->FlashlightDeltaMainLum = 65;    // 1.015*64(1.015X)
} /* MT9P012InitOperationPara() */

void MT9P012DscSupportInfo(P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT pDscSupportInfo)
{
    kal_mem_cpy(pDscSupportInfo, &MT9P012_dsc_support_info, sizeof(camcorder_info_struct));
} /* MT9P012MipiDscSupportInfo() */


MM_ERROR_CODE_ENUM MT9P012SensorFeatureCtrl(kal_uint32 FeatureId,
                                                void* pFeatureParaIn, void* pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
	kal_uint32 i=0;
    if ((FeatureId>=CAL_FEATURE_WEBCAM_BEGIN)&&
        (FeatureId<=CAL_FEATURE_WEBCAM_END))
    {
        ErrorCode=MT9P012WebcamFeatureCtrl(FeatureId, pFeatureParaIn, pFeatureParaOut,
                                               FeatureParaOutLen, pRealFeatureParaOutLen);
        return ErrorCode;
    }
    // for the features that not support in the sensor, then it is not necessary to implement it.
    switch (FeatureId)
    {
        /*get*/
        case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
            MT9P012GetSensorInfo((P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT) pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_MIPI_INFO:
            ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;            
        break;        
        case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
            ((P_IMAGE_SENSOR_COMM_DATA_STRUCT) pFeatureParaOut)->FeatureValue=MT9P012DetectSensorId();
        break;
        case IMAGE_SENSOR_FEATURE_GET_PREVIEW_FLASHLIGHT_INFO:
            MT9P012GetPreviewFlashlightInfo((P_FLASHLIGHT_PREVIEW_PARA_STURCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_CAPTURE_FLASHLIGHT_INFO:
            MT9P012GetCaptureFlashlightInfo((P_FLASHLIGHT_CAPTURE_SENSOR_PARA_IN_STRUCT)pFeatureParaIn, (P_FLASHLIGHT_CAPTURE_PARA_STRUCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_AE_INFO:
            MT9P012GetSensorAeInfo((P_IMAGE_SENSOR_AE_INFO_STRUCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_AE_LUT:
            MT9P012GetAeLut((P_AE_LUT_INFO_STRUCT) pFeatureParaIn, (P_IMAGE_SENSOR_AE_LUT_STRUCT)pFeatureParaOut,
                                FeatureParaOutLen, pRealFeatureParaOutLen);
        break;
        case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
            ((P_IMAGE_SENSOR_COMM_DATA_STRUCT) pFeatureParaOut)->FeatureValue=MT9P012SensorStatus.VideoCurrentFrameRate;
        break;
        case IMAGE_SENSOR_FEATURE_GET_SHADING_TABLE:
            ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        break;
        case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
            MT9P012InitOperationPara((P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_DSC_SUPPORT_INFO:
            MT9P012DscSupportInfo((P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_GAIN:
            ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaOut)->FeatureValue=MT9P012ReadGain();
        break;
        case IMAGE_SENSOR_FEATURE_GET_ENG_INFO:
            ((P_SENSOR_INFO_STRUCT)pFeatureParaOut)->id = 128;
            ((P_SENSOR_INFO_STRUCT)pFeatureParaOut)->type = CMOS_SENSOR;
        break;
        case IMAGE_SENSOR_FEATURE_GET_CCT_GROUP_COUNT:
            MT9P012GetSensorGroupCount((kal_int32*)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_CCT_GROUP_INFO:
            MT9P012GetSensorGroupInfo(((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaIn)->GroupNamePtr, &((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaOut)->ItemCount);
        break;  
        case IMAGE_SENSOR_FEATURE_GET_CCT_ITEM_INFO:
            MT9P012GetSensorItemInfo(((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemIdx, (P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaOut);
        break;	
		case IMAGE_SENSOR_FEATURE_SET_REGISTER:
		  for (i=0;i<((P_IMAGE_SENSOR_REG_IN_STRUCT)pFeatureParaIn)->RegNum;i++)
		  {
			 CamWriteCmosSensor(((P_IMAGE_SENSOR_REG_IN_STRUCT)pFeatureParaIn)->pRegAddr[i],((P_IMAGE_SENSOR_REG_IN_STRUCT)pFeatureParaIn)->pRegData[i]);
		  }
			 break;
		case IMAGE_SENSOR_FEATURE_GET_REGISTER:
		  ((P_IMAGE_SENSOR_REG_IN_STRUCT)pFeatureParaOut)->RegNum = ((P_IMAGE_SENSOR_REG_IN_STRUCT)pFeatureParaIn)->RegNum;
		   for (i=0;i<((P_IMAGE_SENSOR_REG_IN_STRUCT)pFeatureParaIn)->RegNum;i++)
		   {
			  ((P_IMAGE_SENSOR_REG_IN_STRUCT) pFeatureParaOut)->pRegAddr[i]=((P_IMAGE_SENSOR_REG_IN_STRUCT)pFeatureParaIn)->pRegAddr[i];
			  ((P_IMAGE_SENSOR_REG_IN_STRUCT) pFeatureParaOut)->pRegData[i]=CamReadCmosSensor(((P_IMAGE_SENSOR_REG_IN_STRUCT)pFeatureParaIn)->pRegAddr[i]);
		   }
		   break;
		case IMAGE_SENSOR_FEATURE_GET_DATA_INFO:
		   ((P_SENSOR_REG_WIDTH_STRUCT)pFeatureParaOut)->AddrWidth=16;
		   ((P_SENSOR_REG_WIDTH_STRUCT)pFeatureParaOut)->ParaWidth=8;
			break;

		
		/*set*/
        case IMAGE_SENSOR_FEATURE_SET_ESHUTTER:
            MT9P012SetShutter(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
        break;
        case IMAGE_SENSOR_FEATURE_SET_GAIN:
            MT9P012SetGain(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
        break;
        case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
            MT9P012SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT) pFeatureParaIn)->ImageSensorIdx;
        break;
	case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
            CamPdnPinCtrl(MT9P012SensorIdx, 0);
            CamRstPinCtrl(MT9P012SensorIdx, 0);
	break;	
        case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
            pMT9P012NvramSensorData = &(((nvram_camera_para_struct *) pFeatureParaIn)->SENSOR);
        break;
        case IMAGE_SENSOR_FEATURE_SET_CCT_ITEM_INFO:
            MT9P012SetSensoItemInfo(((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemIdx, ((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemValue);
        break;

		
        case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE:
            MT9P012NightMode(((P_IMAGE_SENSOR_COMM_CTRL_STRUCT)pFeatureParaIn)->FeatureEnable);
        break;
        case IMAGE_SENSOR_FEATURE_CTRL_FLASHLIGHT:
            MT9P012SetFlashlight(((P_IMAGE_SENSOR_COMM_CTRL_STRUCT)pFeatureParaIn)->FeatureEnable);
        break;
        case CAL_FEATURE_CAMERA_BINNING_INFO:
            ErrorCode=MT9P012BinningInfo((P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaIn,
                                             (P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaOut, FeatureParaOutLen, pRealFeatureParaOutLen);
        break;
        // customized by customer
        case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
            ErrorCode=MT9P012StillCaptureSize((P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaIn,
                                         (P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaOut, FeatureParaOutLen, pRealFeatureParaOutLen);
        break;
        // for YUV sensor sample code
        // the following are for YUV sensor only
        case CAL_FEATURE_CAMERA_SHARPNESS:
        case CAL_FEATURE_CAMERA_EV_VALUE:
        case CAL_FEATURE_CAMERA_BANDING_FREQ:
        case CAL_FEATURE_CAMERA_WB:
        case CAL_FEATURE_CAMERA_HUE:
        case CAL_FEATURE_CAMERA_BRIGHTNESS:
        case CAL_FEATURE_CAMERA_CONTRAST:
        case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
        case CAL_FEATURE_CAMERA_SATURATION:
        break;
        case IMAGE_SENSOR_FEATURE_YUV_3A_CTRL:
        case CAL_FEATURE_CAMERA_FLASH_MODE:
            // These features are supported in YUV sensor only.
            // Put here just for notifying DD colleagues. Should be removed later for MT9P012. PC Huang 20100903
            ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        break;
        // the above are for YUV sensor only
        case CAL_FEATURE_CCT_OP_CAMERA_PARA_TO_SENSOR:
            MT9P012CameraParaToSensor(pFeatureParaIn);
        break;
        case CAL_FEATURE_CCT_OP_SENSOR_TO_CAMERA_PARA:
            MT9P012SensorToCameraPara(pFeatureParaOut);
        break;
        
        default:
            ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        break;
    }
    return ErrorCode;
} /* MT9P012SensorFeatureCtrl() */

MM_ERROR_CODE_ENUM MT9P012SensorCtrl(CAL_SCENARIO_ENUM ScenarioId, void *pParaIn,
                                         void *pParaOut, kal_uint16 ParaOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

    switch (ScenarioId)
    {
        case CAL_SCENARIO_CAMERA_PREVIEW:
        case CAL_SCENARIO_WEBCAM_PREVIEW:
        case CAL_SCENARIO_WEBCAM_CAPTURE:
            MT9P012Preview(ScenarioId, pParaIn, pParaOut);
        break;
        case CAL_SCENARIO_VIDEO:
			MT9P012Video(ScenarioId, pParaIn, pParaOut);
        break;
        case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
            MT9P012Capture(ScenarioId, pParaIn, pParaOut);
        break;
        default:
        break;
    }
    return ErrorCode;
}

MM_ERROR_CODE_ENUM MT9P012SensorClose(void)
{
    //CamPdnPinCtrl(MT9P012SensorIdx, 1);
    CamRstPinCtrl(MT9P012SensorIdx, 0);
    CisModulePowerOn(MT9P012SensorIdx, KAL_FALSE);
    CameraSccbClose(CAMERA_SCCB_SENSOR);

    return MM_ERROR_NONE;
}

IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncMT9P012=
{
    MT9P012SensorOpen,
    MT9P012SensorFeatureCtrl,
    MT9P012SensorCtrl,
    MT9P012SensorClose,
};

MM_ERROR_CODE_ENUM MT9P012SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
	*pfSensorFunc=&ImageSensorFuncMT9P012;
}	/* cam_module_func_config() */

