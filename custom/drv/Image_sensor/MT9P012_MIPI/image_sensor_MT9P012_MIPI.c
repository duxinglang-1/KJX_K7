/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *   image_sensor_MT9P012_MIPI.c
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
 *
 *
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


#define MT9P012_MIPI_DBG

/* Global Valuable */
IMAGE_SENSOR_INDEX_ENUM MT9P012MipiSensorIdx;
sensor_data_struct *pMT9P012MipiNvramSensorData;
static struct MT9P012_MIPI_SENSOR_STRUCT MT9P012MipiSensorStatus;
SensorInfo MT9P012MipiCCTMainSensor=MT9P012_MIPI_CURRENT_MAIN_SENSOR;
kal_uint16 MT9P012MipiSensorGainArray[4][4]={{0x302c, 0x302a, 0x3030, 0x302e},{0, 0, 0, 0},{0x302d, 0x302b, 0x3031, 0x302f},{0x18, 0x10, 0x10, 0x18}};
kal_uint32 MT9P012MipiFacSensorReg;

extern camcorder_info_struct	MT9P012_MIPI_dsc_support_info;
extern void SetIspDrivingCurrent(kal_uint8 Current);
extern void CamRstPinCtrl(IMAGE_SENSOR_INDEX_ENUM Idx, kal_int8 Data);
extern void CamPdnPinCtrl(IMAGE_SENSOR_INDEX_ENUM Idx, kal_int8 Data);

void MT9P012MipiGetAeLut(P_AE_LUT_INFO_STRUCT pFeatureParaIn,
                         P_IMAGE_SENSOR_AE_LUT_STRUCT pFeatureParaOut,
                         kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen);
void MT9P012MipiWebcamSizeInfo(P_IMAGE_SENSOR_GET_WEBCAM_SIZE_INFO_STRUCT pWebcamSizeInfo);

static void MT9P012MipiWriteGain(kal_uint16 gain)
{
	 volatile signed char i;
	 kal_uint16 temp_reg=0, temp_gain=0;
	 kal_uint16 temp_min_gain = gain;

	 CamWriteCmosSensor(0x0104, 0x01);		 //parameter_hold
for(i=0;i<4;i++)
{
   temp_gain=(MT9P012MipiSensorGainArray[3][i]*gain)/BASEGAIN;
	/* prevent init value error of temp_min_gain > 2 */
   if (i==0)
   {
		 temp_min_gain = temp_gain;
   }

		if(temp_gain>=1*BASEGAIN && temp_gain<15*BASEGAIN)
		 {
			 temp_reg=(8*temp_gain)/BASEGAIN;
			 if(temp_gain<=temp_min_gain)
			 {
				 MT9P012MipiSensorStatus.GlobalGain=temp_gain&(~0x1);
				 temp_min_gain = temp_gain;
			 }
		 }
		 else
		 {
			 temp_reg = 0x7F;
			 if(temp_gain<=temp_min_gain)
			 {
				 MT9P012MipiSensorStatus.GlobalGain=15.875*BASEGAIN;
				 temp_min_gain = temp_gain;
			 }
		 }

		 CamWriteCmosSensor(MT9P012MipiSensorGainArray[2][i],temp_reg);

 }
	CamWriteCmosSensor(0x0104, 0x00);	 //parameter_hold

}   /* MT9P012MipiWriteGain */

static kal_uint16 MT9P012MipiReadGain(void)
{
    volatile signed char i;
    kal_uint16 temp_reg=0, sensor_gain=0,temp_reg_base=0;

    for(i=0;i<4;i++)
    {
	    temp_reg_base=pMT9P012MipiNvramSensorData->cct[MT9P012_MIPI_SENSOR_BASEGAIN].para;
        temp_reg=pMT9P012MipiNvramSensorData->cct[MT9P012_MIPI_PRE_GAIN_R_INDEX+i].para;

        if(temp_reg>=0x08 && temp_reg<=0xFF)
            MT9P012MipiSensorGainArray[3][i]=((((temp_reg*BASEGAIN)/8)*temp_reg_base)/8);
        else if(temp_reg>0xFF && temp_reg<=0x1FF)
            MT9P012MipiSensorGainArray[3][i]=((((temp_reg*BASEGAIN)/8)*temp_reg_base)/8);
        else
            ASSERT(0);
	}
    sensor_gain=(temp_reg_base*BASEGAIN)/8;
    return sensor_gain;
}  /* MT9P012MipiReadGain */

static void MT9P012MipiInitSetting(void)
{
	/* Silicon Recommendation*/
	CamWriteCmosSensor(0x0104, 0x01); //group parameter hold
	CamWriteCmosSensor(0x30B0, 0x00);
	CamWriteCmosSensor(0x30B1, 0x01);
	CamWriteCmosSensor(0x308E, 0xd6);//0xE0);
	CamWriteCmosSensor(0x308f, 0x6a);//0x60);
	CamWriteCmosSensor(0x3090, 0x56);
	CamWriteCmosSensor(0x3091, 0x6a);
	CamWriteCmosSensor(0x3088, 0x6e);
	CamWriteCmosSensor(0x3089, 0x61);
	CamWriteCmosSensor(0x3092, 0x0a);
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
	CamWriteCmosSensor(0x309E, 0x5D);//add
	CamWriteCmosSensor(0x309f, 0x00);//add
	CamWriteCmosSensor(0x0104, 0x00); //group parameter hold
}

static void MT9P012MipiInitSingleLaneRaw8bit(void)
{
	CamWriteCmosSensor(0x0100, 0x00);	// MODE_SELECT, go to standby

	CamWriteCmosSensor(0x301A, 0x00);	// RESET_REGISTER
	CamWriteCmosSensor(0x301B, 0x18);

	CamWriteCmosSensor(0x3064, 0x08);	//disable embedded_data_enable
	CamWriteCmosSensor(0x3065, 0x05);

	CamWriteCmosSensor(0x31AE, 0x02);
	CamWriteCmosSensor(0x31AF, 0x01);	// SERIAL_FORMAT
	CamWriteCmosSensor(0x0112, 0x08);	// CCP_DATA_FORMAT, 8-bit pixel data
	CamWriteCmosSensor(0x0113, 0x08);

	CamWriteCmosSensor(0x0100, 0x01); // MODE_SELECT
}

static void MT9P012MipiInitSingleLaneRaw10bit(void)
{
	CamWriteCmosSensor(0x0100, 0x00);	// MODE_SELECT, go to standby

	CamWriteCmosSensor(0x301A, 0x00);	// RESET_REGISTER
	CamWriteCmosSensor(0x301B, 0x18);

	CamWriteCmosSensor(0x3064, 0x08); //disable embedded_data_enable
	CamWriteCmosSensor(0x3065, 0x05);

	CamWriteCmosSensor(0x31AE, 0x02);
	CamWriteCmosSensor(0x31AF, 0x01);	// SERIAL_FORMAT
	CamWriteCmosSensor(0x0112, 0x0A);		// CCP_DATA_FORMAT, 10-bit pixel data
	CamWriteCmosSensor(0x0113, 0x0A);

	CamWriteCmosSensor(0x0100, 0x01);	// MODE_SELECT
}

static void MT0P012MipiSet10bitQSXGA()
{
    // [MI5130 MIPI 600Mbps 2592x1944 RAW10 EXTCLK=24MHz OP_PIX_CLK=60MHz]

    CamWriteCmosSensor(0x0100, 0x00);	// MODE_SELECT, go to standby

    //MIPI PLL setup
    //MCLK=24MHz,
    //VT CLK=MCLK/(0x0304&0x0305)*(0x0306&0x0307)/(0x0300&0x0301)/(0x0302&0x0303)
    //OP CLK=MCLK/(0x0304&0x0305)*(0x0306&0x0307)/(0x0308&0x0309)/(0x030a&0x030b)
    CamWriteCmosSensor(0x0304, 0x00);// PRE_PLL_CLK_DIV
    CamWriteCmosSensor(0x0305, 0x03);
    CamWriteCmosSensor(0x0306, 0x00);// PLL_MULTIPLIER
    CamWriteCmosSensor(0x0307, 0x3c);//60;

    CamWriteCmosSensor(0x0302, 0x00);	// VT_SYS_CLK_DIV
    CamWriteCmosSensor(0x0303, 0x01);
    CamWriteCmosSensor(0x0300, 0x00);	// VT_PIX_CLK_DIV
    CamWriteCmosSensor(0x0301, 0x05);

    CamWriteCmosSensor(0x030A, 0x00);	// OP_SYS_CLK_DIV
    CamWriteCmosSensor(0x030B, 0x01);
    CamWriteCmosSensor(0x0308, 0x00);	// OP_PIX_CLK_DIV
    CamWriteCmosSensor(0x0309, 0x0A);

    kal_sleep_task(1); 			//DELAY=1 (ms)			// PLL locking time
    CamWriteCmosSensor(0x0104, 0x01);	// GROUPED_PARAMETER_HOLD

    //output size
    CamWriteCmosSensor(0x3004, 0x00);
    CamWriteCmosSensor(0x3005, 0x08);	// X_ADDR_START
    CamWriteCmosSensor(0x3002, 0x00);
    CamWriteCmosSensor(0x3003, 0x08);	// Y_ADDR_START
    CamWriteCmosSensor(0x3008, 0x0A);
    CamWriteCmosSensor(0x3009, 0x27);	// X_ADDR_END 2599
    CamWriteCmosSensor(0x3006, 0x07);
    CamWriteCmosSensor(0x3007, 0x9F);	// Y_ADDR_END  1951

    CamWriteCmosSensor(0x3040, 0x00);
    CamWriteCmosSensor(0x3041, 0x41);	   // Read Mode (x_odd_inc=1, y_odd_inc=1,xy_bin=1)

    CamWriteCmosSensor(0x034C, 0x0A);
    CamWriteCmosSensor(0x034D, 0x20);	// X_OUTPUT_SIZE  2592
    CamWriteCmosSensor(0x034E, 0x07);
    CamWriteCmosSensor(0x034F, 0x98);	// Y_OUTPUT_SIZE  1944

    CamWriteCmosSensor(0x300c, 0x16);
    CamWriteCmosSensor(0x300d, 0xf8);	// LINE_LENGTH_PCK  5880
    CamWriteCmosSensor(0x300a, 0x07);
    CamWriteCmosSensor(0x300b, 0xf8);	// FRAME_LENGTH_LINES  2040

    //frame rate and integration time setup
    CamWriteCmosSensor(0x3012, 0x07);
    CamWriteCmosSensor(0x3013, 0xe4);	// COARSE_INTEGRATION_TIME
    CamWriteCmosSensor(0x3010, 0x00);
    CamWriteCmosSensor(0x3011, 0x9c);	// FINE_CORRECTION
    CamWriteCmosSensor(0x3014, 0x03);
    CamWriteCmosSensor(0x3015, 0x72);	// FINE_INTEGRATION_TIME_

    CamWriteCmosSensor(0x0104, 0x00);	// GROUPED_PARAMETER_HOLD
    CamWriteCmosSensor(0x0100, 0x01);	// MODE_SELECT

    // Slew rate
    CamWriteCmosSensor(0x306E, 0x34);
    CamWriteCmosSensor(0x306f, 0x80);	// DATAPATH_SELECT
}

static void MT0P012MipiSet10bitQSXGAHS()
{
    //[MI-5131 MIPI single lane interface 24MHz_EXTCLK 76.8MHz_PCLK 14.04FPS 2592x1944 resolution]
    // Single Lane MIPI
    CamWriteCmosSensor(0x0100, 0x00);	// MODE_SELECT, go to standby

    //MIPI PLL setup
    //MCLK=24MHz,
    //VT CLK=MCLK/(0x0304&0x0305)*(0x0306&0x0307)/(0x0300&0x0301)/(0x0302&0x0303)
    //OP CLK=MCLK/(0x0304&0x0305)*(0x0306&0x0307)/(0x0308&0x0309)/(0x030a&0x030b)
    CamWriteCmosSensor(0x0304, 0x00);// PRE_PLL_CLK_DIV
    CamWriteCmosSensor(0x0305, 0x02);
    CamWriteCmosSensor(0x0306, 0x00);// PLL_MULTIPLIER
    CamWriteCmosSensor(0x0307, 0x40);//64;

    CamWriteCmosSensor(0x0302, 0x00);	// VT_SYS_CLK_DIV
    CamWriteCmosSensor(0x0303, 0x01);
    CamWriteCmosSensor(0x0300, 0x00);	// VT_PIX_CLK_DIV
    CamWriteCmosSensor(0x0301, 0x06);

    CamWriteCmosSensor(0x030A, 0x00);	// OP_SYS_CLK_DIV
    CamWriteCmosSensor(0x030B, 0x01);
    CamWriteCmosSensor(0x0308, 0x00);	// OP_PIX_CLK_DIV
    CamWriteCmosSensor(0x0309, 0x0A);

    kal_sleep_task(1); 			//DELAY=1 (ms)			// PLL locking time
    CamWriteCmosSensor(0x0104, 0x01);	// GROUPED_PARAMETER_HOLD

    //output size
    CamWriteCmosSensor(0x3004, 0x00);
    CamWriteCmosSensor(0x3005, 0x08);	// X_ADDR_START
    CamWriteCmosSensor(0x3002, 0x00);
    CamWriteCmosSensor(0x3003, 0x08);	// Y_ADDR_START
    CamWriteCmosSensor(0x3008, 0x0A);
    CamWriteCmosSensor(0x3009, 0x27);	// X_ADDR_END  2599
    CamWriteCmosSensor(0x3006, 0x07);
    CamWriteCmosSensor(0x3007, 0x9F);	// Y_ADDR_END   1951

    CamWriteCmosSensor(0x3040, 0x00);
    CamWriteCmosSensor(0x3041, 0x41);	   // Read Mode (x_odd_inc=1, y_odd_inc=1,xy_bin=1)

    CamWriteCmosSensor(0x034C, 0x0A);
    CamWriteCmosSensor(0x034D, 0x20);	// X_OUTPUT_SIZE  2952
    CamWriteCmosSensor(0x034E, 0x07);
    CamWriteCmosSensor(0x034F, 0x98);	// Y_OUTPUT_SIZE  1944

    CamWriteCmosSensor(0x300c, 0x11);
    CamWriteCmosSensor(0x300d, 0xD4);	// LINE_LENGTH_PCK	4564
    CamWriteCmosSensor(0x300a, 0x07);
    CamWriteCmosSensor(0x300b, 0xed);	// FRAME_LENGTH_LINES 2029

    //frame rate and integration time setup
    CamWriteCmosSensor(0x3012, 0x07);
    CamWriteCmosSensor(0x3013, 0xd0);	// COARSE_INTEGRATION_TIME
    CamWriteCmosSensor(0x3010, 0x00);
    CamWriteCmosSensor(0x3011, 0x9c);	// FINE_CORRECTION
    CamWriteCmosSensor(0x3014, 0x03);
    CamWriteCmosSensor(0x3015, 0x72);	// FINE_INTEGRATION_TIME_

    CamWriteCmosSensor(0x0104, 0x00);	// GROUPED_PARAMETER_HOLD
    CamWriteCmosSensor(0x0100, 0x01);	// MODE_SELECT

    // Slew rate
    CamWriteCmosSensor(0x306E, 0x34);
    CamWriteCmosSensor(0x306f, 0x80);	// DATAPATH_SELECT
}

static void MT0P012MipiSet10bitQSXGA11fps()
{
    //[MI-5131 MIPI single lane interface 24MHz_EXTCLK 76.8MHz_PCLK 14.04FPS 2592x1944 resolution]
    // Single Lane MIPI
    CamWriteCmosSensor(0x0100, 0x00);	// MODE_SELECT, go to standby

    //MIPI PLL setup
    //MCLK=24MHz,
    //VT CLK=MCLK/(0x0304&0x0305)*(0x0306&0x0307)/(0x0300&0x0301)/(0x0302&0x0303)
    //OP CLK=MCLK/(0x0304&0x0305)*(0x0306&0x0307)/(0x0308&0x0309)/(0x030a&0x030b)
    CamWriteCmosSensor(0x0304, 0x00);// PRE_PLL_CLK_DIV
    CamWriteCmosSensor(0x0305, 0x03);
    CamWriteCmosSensor(0x0306, 0x00);// PLL_MULTIPLIER
    CamWriteCmosSensor(0x0307, 0x4b);//75;

    CamWriteCmosSensor(0x0302, 0x00);	// VT_SYS_CLK_DIV
    CamWriteCmosSensor(0x0303, 0x01);
    CamWriteCmosSensor(0x0300, 0x00);	// VT_PIX_CLK_DIV
    CamWriteCmosSensor(0x0301, 0x05);

    CamWriteCmosSensor(0x030A, 0x00);	// OP_SYS_CLK_DIV
    CamWriteCmosSensor(0x030B, 0x01);
    CamWriteCmosSensor(0x0308, 0x00);	// OP_PIX_CLK_DIV
    CamWriteCmosSensor(0x0309, 0x0A);

    kal_sleep_task(1); 			//DELAY=1 (ms)			// PLL locking time
    CamWriteCmosSensor(0x0104, 0x01);	// GROUPED_PARAMETER_HOLD

    //output size
    CamWriteCmosSensor(0x3004, 0x00);
    CamWriteCmosSensor(0x3005, 0x08);	// X_ADDR_START
    CamWriteCmosSensor(0x3002, 0x00);
    CamWriteCmosSensor(0x3003, 0x08);	// Y_ADDR_START
    CamWriteCmosSensor(0x3008, 0x0A);
    CamWriteCmosSensor(0x3009, 0x27);	// X_ADDR_END  2599
    CamWriteCmosSensor(0x3006, 0x07);
    CamWriteCmosSensor(0x3007, 0x9F);	// Y_ADDR_END   1951

    CamWriteCmosSensor(0x3040, 0x00);
    CamWriteCmosSensor(0x3041, 0x41);	   // Read Mode (x_odd_inc=1, y_odd_inc=1,xy_bin=1)

    CamWriteCmosSensor(0x034C, 0x0A);
    CamWriteCmosSensor(0x034D, 0x20);	// X_OUTPUT_SIZE  2952
    CamWriteCmosSensor(0x034E, 0x07);
    CamWriteCmosSensor(0x034F, 0x98);	// Y_OUTPUT_SIZE  1944

    CamWriteCmosSensor(0x300c, 0x15);
    CamWriteCmosSensor(0x300d, 0x6c);	// LINE_LENGTH_PCK	5484//5390
    CamWriteCmosSensor(0x300a, 0x07);
    CamWriteCmosSensor(0x300b, 0xed);	// FRAME_LENGTH_LINES 2029

    //frame rate and integration time setup
    CamWriteCmosSensor(0x3012, 0x07);
    CamWriteCmosSensor(0x3013, 0xd0);	// COARSE_INTEGRATION_TIME
    CamWriteCmosSensor(0x3010, 0x00);
    CamWriteCmosSensor(0x3011, 0x9c);	// FINE_CORRECTION
    CamWriteCmosSensor(0x3014, 0x03);
    CamWriteCmosSensor(0x3015, 0x72);	// FINE_INTEGRATION_TIME_

    CamWriteCmosSensor(0x0104, 0x00);	// GROUPED_PARAMETER_HOLD
    CamWriteCmosSensor(0x0100, 0x01);	// MODE_SELECT

    // Slew rate
    CamWriteCmosSensor(0x306E, 0x34);
    CamWriteCmosSensor(0x306f, 0x80);	// DATAPATH_SELECT
}

static void MT0P012MipiSet8bitSXGA()
{
		//[MI-5131 MIPI single lane interface 52MHz_EXTCLK 48.75MHz_PCLK 1297x973 resolution]
    CamWriteCmosSensor(0x0100, 0x00);	// MODE_SELECT, go to standby

    //MIPI PLL setup
    //MCLK=24MHz,
    //VT CLK=MCLK/(0x0304&0x0305)*(0x0306&0x0307)/(0x0300&0x0301)/(0x0302&0x0303)
    //OP CLK=MCLK/(0x0304&0x0305)*(0x0306&0x0307)/(0x0308&0x0309)/(0x030a&0x030b)
    CamWriteCmosSensor(0x0300, 0x00);	// VT_PIX_CLK_DIV
    CamWriteCmosSensor(0x0301, 0x04);
    CamWriteCmosSensor(0x0302, 0x00);	// VT_SYS_CLK_DIV
    CamWriteCmosSensor(0x0303, 0x01);

    CamWriteCmosSensor(0x0304, 0x00);// PRE_PLL_CLK_DIV
    CamWriteCmosSensor(0x0305, 0x03);
    CamWriteCmosSensor(0x0306, 0x00);// PLL_MULTIPLIER
    CamWriteCmosSensor(0x0307, 0x32);

    CamWriteCmosSensor(0x0308, 0x00);	// OP_PIX_CLK_DIV
    CamWriteCmosSensor(0x0309, 0x08);
    CamWriteCmosSensor(0x030A, 0x00);	// OP_SYS_CLK_DIV
    CamWriteCmosSensor(0x030B, 0x01);

    kal_sleep_task(1); 			//DELAY=1 (ms)			// PLL locking time

    //CamWriteCmosSensor(0x0100, 0x01); // MODE_SELECT
    CamWriteCmosSensor(0x0104, 0x01);	// GROUPED_PARAMETER_HOLD
    //output size
    CamWriteCmosSensor(0x3004, 0x00);	// X_ADDR_START
    CamWriteCmosSensor(0x3005, 0x08);
    CamWriteCmosSensor(0x3008, 0x0A);	// X_ADDR_END
    CamWriteCmosSensor(0x3009, 0x25);
    CamWriteCmosSensor(0x3002, 0x00);	// Y_ADDR_START
    CamWriteCmosSensor(0x3003, 0x08);
    CamWriteCmosSensor(0x3006, 0x07);	// Y_ADDR_END
    CamWriteCmosSensor(0x3007, 0x9d);

    CamWriteCmosSensor(0x3040, 0x14);
    CamWriteCmosSensor(0x3041, 0xC3);	  // Read Mode (x_odd_inc=3, y_odd_inc=3,xy_bin=1)

    CamWriteCmosSensor(0x034C, 0x05);
    CamWriteCmosSensor(0x034D, 0x10);	// X_OUTPUT_SIZE  1296
    CamWriteCmosSensor(0x034E, 0x03);
    CamWriteCmosSensor(0x034F, 0xCC);	// Y_OUTPUT_SIZE   972

    CamWriteCmosSensor(0x300c, 0x0d);
    CamWriteCmosSensor(0x300d, 0x48);	// LINE_LENGTH_PCK	3400
    CamWriteCmosSensor(0x300a, 0x04);
    CamWriteCmosSensor(0x300b, 0x1F);	// FRAME_LENGTH_LINES  1055

    CamWriteCmosSensor(0x3012, 0x04);
    CamWriteCmosSensor(0x3013, 0x4C);	// COARSE_INTEGRATION_TIME
    CamWriteCmosSensor(0x3014, 0x07);
    CamWriteCmosSensor(0x3015, 0x02);	// FINE_INTEGRATION_TIME_
    CamWriteCmosSensor(0x3010, 0x01);
    CamWriteCmosSensor(0x3011, 0x5c);	// FINE_CORRECTION

    CamWriteCmosSensor(0x0104, 0x00);	// GROUPED_PARAMETER_HOLD
    CamWriteCmosSensor(0x0100, 0x01);	// MODE_SELECT

    // Slew rate
    CamWriteCmosSensor(0x306E, 0x34);
    CamWriteCmosSensor(0x306f, 0x80);	// DATAPATH_SELECT
}

static void MT0P012MipiSet10bitSXGA(CAL_RAW_CAPTURE_MODE_ENUM CaptureScenario)
{
    //[MI-5131 MIPI single lane interface 24MHz_EXTCLK 76.8MHz_PCLK 30FPS 1297x973 resolution]
    CamWriteCmosSensor(0x0100, 0x00);	// MODE_SELECT, go to standby

    //MIPI PLL setup
    //MCLK=24MHz,
    //VT CLK=MCLK/(0x0304&0x0305)*(0x0306&0x0307)/(0x0300&0x0301)/(0x0302&0x0303)
    //OP CLK=MCLK/(0x0304&0x0305)*(0x0306&0x0307)/(0x0308&0x0309)/(0x030a&0x030b)
    CamWriteCmosSensor(0x0300, 0x00);	// VT_PIX_CLK_DIV
    CamWriteCmosSensor(0x0301, 0x05);
    CamWriteCmosSensor(0x0302, 0x00);	// VT_SYS_CLK_DIV
    CamWriteCmosSensor(0x0303, 0x01);

    CamWriteCmosSensor(0x0304, 0x00);// PRE_PLL_CLK_DIV
    CamWriteCmosSensor(0x0305, 0x03);

    //#ifdef CAM_OTF_CAPTURE
    if (CAL_RAW_CAPTURE_MODE_OTF==CaptureScenario)
    {
    CamWriteCmosSensor(0x0306, 0x00);// PLL_MULTIPLIER
    CamWriteCmosSensor(0x0307, 0x3c);//60
    }
    //#else
    else
    {
    CamWriteCmosSensor(0x0306, 0x00);// PLL_MULTIPLIER
    CamWriteCmosSensor(0x0307, 0x4b);//75
    }
    //#endif

    CamWriteCmosSensor(0x0308, 0x00);	// OP_PIX_CLK_DIV
    CamWriteCmosSensor(0x0309, 0x0a);
    CamWriteCmosSensor(0x030A, 0x00);	// OP_SYS_CLK_DIV
    CamWriteCmosSensor(0x030B, 0x01);

    kal_sleep_task(1);	//DELAY=1 (ms)			// PLL locking time

    //CamWriteCmosSensor(0x0100, 0x01); // MODE_SELECT
    CamWriteCmosSensor(0x0104, 0x01);	// GROUPED_PARAMETER_HOLD
    //output size
    CamWriteCmosSensor(0x3004, 0x00);	// X_ADDR_START
    CamWriteCmosSensor(0x3005, 0x08);
    CamWriteCmosSensor(0x3008, 0x0A);	// X_ADDR_END
    CamWriteCmosSensor(0x3009, 0x25);
    CamWriteCmosSensor(0x3002, 0x00);	// Y_ADDR_START
    CamWriteCmosSensor(0x3003, 0x08);
    CamWriteCmosSensor(0x3006, 0x07);	// Y_ADDR_END
    CamWriteCmosSensor(0x3007, 0x9d);

    CamWriteCmosSensor(0x3040, 0x14);
    CamWriteCmosSensor(0x3041, 0xC3);	  // Read Mode (x_odd_inc=3, y_odd_inc=3,xy_bin=1)

    CamWriteCmosSensor(0x034C, 0x05);
    CamWriteCmosSensor(0x034D, 0x10);	// X_OUTPUT_SIZE  1296
    CamWriteCmosSensor(0x034E, 0x03);
    CamWriteCmosSensor(0x034F, 0xCC);	// Y_OUTPUT_SIZE   972

    CamWriteCmosSensor(0x300c, 0x0E);
    CamWriteCmosSensor(0x300d, 0x2E);	// LINE_LENGTH_PCK  3630
    CamWriteCmosSensor(0x300a, 0x04);
    CamWriteCmosSensor(0x300b, 0x4C);	// FRAME_LENGTH_LINES  1100

    CamWriteCmosSensor(0x3012, 0x04);
    CamWriteCmosSensor(0x3013, 0x4C);	// COARSE_INTEGRATION_TIME
    CamWriteCmosSensor(0x3014, 0x07);
    CamWriteCmosSensor(0x3015, 0x02);	// FINE_INTEGRATION_TIME_
    CamWriteCmosSensor(0x3010, 0x01);
    CamWriteCmosSensor(0x3011, 0x5c);	// FINE_CORRECTION


    CamWriteCmosSensor(0x0104, 0x00);	// GROUPED_PARAMETER_HOLD
    CamWriteCmosSensor(0x0100, 0x01);	// MODE_SELECT

    // Slew rate
    CamWriteCmosSensor(0x306E, 0x34);
    CamWriteCmosSensor(0x306f, 0x80);	// DATAPATH_SELECT
}


/*************************************************************************
* FUNCTION
*	MT9P012MipiSetDummy
*
* DESCRIPTION
*	This function set dummys of MT9P012 MIPI to change line times and frame times.
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
static void MT9P012MipiSetDummy(kal_uint16 Line_Length,kal_uint16 Frame_Length)
{
    ASSERT(Line_Length<0xffff);
    ASSERT(Frame_Length<0xffff);

    CamWriteCmosSensor(0x0104, 0x01);											//Grouped parameter hold
    CamWriteCmosSensor(0x300c, Line_Length>>8);    //LINE_LENGTH_PCK
    CamWriteCmosSensor(0x300d, Line_Length&0xFF);
    CamWriteCmosSensor(0x300a, Frame_Length>>8);  //FRAME_LENGTH_LINES
    CamWriteCmosSensor(0x300b, Frame_Length&0xFF);
    CamWriteCmosSensor(0x0104, 0x00);              //Grouped parameter hold
}

/*************************************************************************
* FUNCTION
*	MT9P012MipiWriteShutter
*
* DESCRIPTION
*	This function set e-shutter of MT9P012_MIPI to change exposure time.
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
static void MT9P012MipiWriteShutter(kal_uint16 shutter)
{
    CamWriteCmosSensor(0x0104, 0x01);		//parameter_hold

	CamWriteCmosSensor(0x3012,shutter>>8);
	CamWriteCmosSensor(0x3013,shutter&0xFF);

    CamWriteCmosSensor(0x0104, 0x00);		//parameter_hold
}	/* MT9P012MipiSetShutter */


/*************************************************************************
* FUNCTION
*	MT9P012MipiSetShutter
*
* DESCRIPTION
*	This function set e-shutter of MT9P012_MIPI to change exposure time.
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
static void MT9P012MipiSetShutter(kal_uint16 shutter)
{
    MT9P012MipiSensorStatus.ExposureLines=shutter;
    MT9P012MipiWriteShutter(shutter);
}	/* MT9P012MipiSetShutter */

/*************************************************************************
* FUNCTION
*	MT9P012MipiSetMirrorFlip
*
* DESCRIPTION
*	This function set mirror or flip.
*
* PARAMETERS
*	image_mirror :
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void MT9P012MipiSetMirrorFlip(kal_uint8 image_mirror)
{
	switch (image_mirror)
	{
		case IMAGE_SENSOR_MIRROR_NORMAL:
			CamWriteCmosSensor(0x301D,0x00);
			//SET_FIRST_GRAB_COLOR(BAYER_Gb);
		break;
		case IMAGE_SENSOR_MIRROR_H:
			CamWriteCmosSensor(0x301D,0x01);
			//SET_FIRST_GRAB_COLOR(BAYER_B);
		break;
		case IMAGE_SENSOR_MIRROR_V:
			CamWriteCmosSensor(0x301D,0x02);
			//SET_FIRST_GRAB_COLOR(BAYER_R);
		break;
		case IMAGE_SENSOR_MIRROR_HV:
			CamWriteCmosSensor(0x301D,0x03);
			//SET_FIRST_GRAB_COLOR(BAYER_Gr);
		break;
	}
}

/*************************************************************************
* FUNCTION
*	MT9P012MipiWriteReg
*
* DESCRIPTION
*	This function set the register of MT9P012_MIPI.
*
* PARAMETERS
*	addr : the register index of MT9P012_MIPI
*  para : setting parameter of the specified register of MT9P012_MIPI
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void MT9P012MipiWriteReg(kal_uint32 addr, kal_uint32 para)
{
	CamWriteCmosSensor(addr,para);
}	/* MT9P012MipiWriteReg() */

/*************************************************************************
* FUNCTION
*	MT9P012MipiCamReadCmosSensor
*
* DESCRIPTION
*	This function read parameter of specified register from MT9P012_MIPI.
*
* PARAMETERS
*	addr : the register index of MT9P012_MIPI
*
* RETURNS
*	the data that read from MT9P012_MIPI
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 MT9P012MipiReadReg(kal_uint32 addr)
{
	return (CamReadCmosSensor(addr));
}	/* MT9P012MipiReadReg() */


/*************************************************************************
* FUNCTION
*	MT9P012MipiSetGain
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
static kal_uint16 MT9P012MipiSetGain(kal_uint16 gain)
{
	kal_uint32 reg_gain;

   	MT9P012MipiWriteGain(gain);
  	reg_gain=(MT9P012MipiSensorStatus.GlobalGain*BASEGAIN)/MT9P012MipiSensorStatus.SensorGainBase;

  	return reg_gain;
}

/*************************************************************************
* FUNCTION
*	MT9P012_Fix_Video_Frame_Rate
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
*
*
*************************************************************************/
static void MT9P012MipiFixVideoFrameRate(kal_uint16 framerate)
{
    if (framerate>=300)
        MT9P012MipiSensorStatus.VideoCurrentFrameRate=278;
    else if (framerate>=240)
        MT9P012MipiSensorStatus.VideoCurrentFrameRate=240;
    else if (framerate>=200)
        MT9P012MipiSensorStatus.VideoCurrentFrameRate=200;
    else if (framerate>=150)
		MT9P012MipiSensorStatus.VideoCurrentFrameRate=150;
	else if(framerate>=120)
		MT9P012MipiSensorStatus.VideoCurrentFrameRate=120;
	else if(framerate>=75)
		MT9P012MipiSensorStatus.VideoCurrentFrameRate=75;
	else if(framerate>=50)
		MT9P012MipiSensorStatus.VideoCurrentFrameRate=50;
	else
		ASSERT(0);

    MT9P012MipiSensorStatus.VideoMaxLineLength = (kal_uint16)((MT9P012MipiSensorStatus.PvPclk*1000000*10/MT9P012MipiSensorStatus.VideoCurrentFrameRate)/(MT9P012MipiSensorStatus.PvFrameLength));
    /*Auto15fps-3159, 12fps-3949; night 7.5fps-6319, 5fps-9478*/

    if (MT9P012MipiSensorStatus.VideoMaxLineLength < MT9P012MipiSensorStatus.PvLineLength)
        MT9P012MipiSensorStatus.VideoMaxLineLength = MT9P012MipiSensorStatus.PvLineLength;

    MT9P012MipiSetDummy(MT9P012MipiSensorStatus.VideoMaxLineLength,MT9P012MipiSensorStatus.PvFrameLength);

    MT9P012MipiSensorStatus.PvLineLength=MT9P012MipiSensorStatus.VideoMaxLineLength;
}

/*************************************************************************
* FUNCTION
*	MT9P012MipiNightMode
*
* DESCRIPTION
*	This function night mode of MT9P012_MIPI.
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
static void MT9P012MipiNightMode(kal_bool enable)
{

}	/* MT9P012MipiNightMode */

static void MT9P012MipiSetFlashlight (kal_bool enable)
{
	//flashlight_power_on(enable);
	FlashlightPowerOn(MT9P012MipiSensorIdx, enable);
}

//void MT9P012MipiGetSensorAeInfo(sensor_ae_info *pInfo)
void MT9P012MipiGetSensorAeInfo(IMAGE_SENSOR_AE_INFO_STRUCT *pInfo)
{
    pInfo->DefaultPrevLinePixels = MT9P012_MIPI_PV_PERIOD_PIXEL_NUMS;
    pInfo->CurrentPrevLinePixels =MT9P012_MIPI_PV_PERIOD_PIXEL_NUMS + MT9P012MipiSensorStatus.PvDummyPixels;
	pInfo->CurrentPclk=MT9P012MipiSensorStatus.PvPclk*1000000;
}


//------------------------Engineer mode---------------------------------
void  MT9P012MipiGetSensorGroupCount(kal_int32* sensor_count_ptr)
{
    #if(! defined(DRV_ISP_6238_SERIES))
    *sensor_count_ptr=MT9P012_MIPI_GROUP_TOTAL_NUMS;
    #else
    *sensor_count_ptr=GROUP_TOTAL_NUMS;
    #endif

    return;
}

extern int sprintf(char *buffer, const char *format, ... );

void MT9P012MipiGetSensorGroupInfo(kal_uint16 group_idx, kal_int8* group_name_ptr, kal_int32* item_count_ptr)
{
   switch (group_idx)
   {
   	#if(! defined(DRV_ISP_6238_SERIES))
		case MT9P012_MIPI_PRE_GAIN:
			kal_sprintf((kal_char *)group_name_ptr, "CCT");
			*item_count_ptr = 5;
		break;
		case MT9P012_MIPI_CMMCLK_CURRENT:
			kal_sprintf((kal_char *)group_name_ptr, "CMMCLK Current");
			*item_count_ptr = 1;
		break;
		case MT9P012_MIPI_FRAME_RATE_LIMITATION:
			kal_sprintf((kal_char *)group_name_ptr, "Frame Rate Limitation");
			*item_count_ptr = 2;
		break;
		case MT9P012_MIPI_REGISTER_EDITOR:
			kal_sprintf((kal_char *)group_name_ptr, "Register Editor");
			*item_count_ptr = 2;
		break;
		default:
		   ASSERT(0);
	#else
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
	#endif
	}
}

void MT9P012MipiGetSensorItemInfo(kal_uint16 group_idx,kal_uint16 item_idx, CAL_CCT_SENSOR_ITEM_INFO_STRUCT* info_ptr)
{
    kal_int16 temp_reg=0;
    kal_uint16 temp_gain=0, temp_addr=0, temp_para=0;

    switch (group_idx)
    {
        #if(! defined(DRV_ISP_6238_SERIES))
        case MT9P012_MIPI_PRE_GAIN:
            switch (item_idx)
            {
                case 0:
                    kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"Pregain-R");
                    temp_addr = MT9P012_MIPI_PRE_GAIN_R_INDEX;
                break;
                case 1:
                    kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"Pregain-Gr");
                    temp_addr = MT9P012_MIPI_PRE_GAIN_Gr_INDEX;
                break;
                case 2:
                    kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"Pregain-Gb");
                    temp_addr = MT9P012_MIPI_PRE_GAIN_Gb_INDEX;
                break;
                case 3:
                    kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"Pregain-B");
                    temp_addr = MT9P012_MIPI_PRE_GAIN_B_INDEX;
                break;
                case 4:
                    kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"SENSOR_BASEGAIN");
                    temp_addr = MT9P012_MIPI_SENSOR_BASEGAIN;
                break;
                default:
                ASSERT(0);
            }

            temp_para=pMT9P012MipiNvramSensorData->cct[temp_addr].para;

            if(temp_para>=0x08 && temp_para<=0xFF)
                temp_gain=(temp_para*BASEGAIN)/8;
            else if(temp_para>0xFF && temp_para<=0x1FF)
                temp_gain=(temp_para*BASEGAIN)/8;
            else
                ASSERT(0);

            temp_gain=(temp_gain*1000)/BASEGAIN;

            info_ptr->ItemValue=temp_gain;
            info_ptr->IsTrueFalse=KAL_FALSE;
            info_ptr->IsReadOnly=KAL_FALSE;
            info_ptr->IsNeedRestart=KAL_FALSE;
            info_ptr->Min=1000;
            info_ptr->Max=15875;

        break;
        
        case MT9P012_MIPI_CMMCLK_CURRENT:
            switch (item_idx)
            {			
	            case 0:
                    kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"Drv Cur[2,4,6,8]mA");
                    temp_reg=pMT9P012MipiNvramSensorData->reg[MT9P012_MIPI_CMMCLK_CURRENT_INDEX].para;
                    if(temp_reg==ISP_DRIVING_2MA)
                    {
                        info_ptr->ItemValue=2;
                    }
                    else if(temp_reg==ISP_DRIVING_4MA)
                    {
                       info_ptr->ItemValue=4;
                    }
                    else if(temp_reg==ISP_DRIVING_6MA)
                    {
                        info_ptr->ItemValue=6;
                    }
                    else if(temp_reg==ISP_DRIVING_8MA)
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

        case MT9P012_MIPI_FRAME_RATE_LIMITATION:
            switch (item_idx)
            {
                case 0:
                    kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"Max Exposure Lines");
                    info_ptr->ItemValue=MT9P012_MIPI_LIMIT_EXPOSURE_LINES;
                    info_ptr->IsTrueFalse=KAL_FALSE;
                    info_ptr->IsReadOnly=KAL_TRUE;
                    info_ptr->IsNeedRestart=KAL_FALSE;
                    info_ptr->Min=0;
                    info_ptr->Max=0;
                break;
			
                case 1:
                    kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"Min Frame Rate");
                    info_ptr->ItemValue=MT9P012_MIPI_MIN_FRAME_RATE;
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

        case MT9P012_MIPI_REGISTER_EDITOR:
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

        #else
        case PRE_GAIN:
        switch (item_idx)
        {
            case 0:
                kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"Pregain-R");
                temp_addr = PRE_GAIN_R_INDEX;
            break;
			case 1:
                kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"Pregain-Gr");
                temp_addr = PRE_GAIN_Gr_INDEX;
            break;		
            case 2:
                kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"Pregain-Gb");
                temp_addr = PRE_GAIN_Gb_INDEX;
            break;
            case 3:
                kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"Pregain-B");
                temp_addr = PRE_GAIN_B_INDEX;
            break;
            case 4:
                kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"SENSOR_BASEGAIN");
                temp_addr = SENSOR_BASEGAIN;
            break;			
            default:
                ASSERT(0);
        }

        temp_para=pMT9P012MipiNvramSensorData->cct[temp_addr].para;

        if(temp_para>=0x08 && temp_para<=0xFF)
            temp_gain=(temp_para*BASEGAIN)/8;
        else if(temp_para>0xFF && temp_para<=0x1FF)
            temp_gain=(temp_para*BASEGAIN)/8;

        else
            ASSERT(0);

        temp_gain=(temp_gain*1000)/BASEGAIN;

        info_ptr->ItemValue=temp_gain;
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

                    temp_reg=pMT9P012MipiNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para;
                    if(temp_reg==ISP_DRIVING_2MA)
                    {
                        info_ptr->ItemValue=2;
                    }
                    else if(temp_reg==ISP_DRIVING_4MA)
                    {
                        info_ptr->ItemValue=4;
                    }
                    else if(temp_reg==ISP_DRIVING_6MA)
                    {
                        info_ptr->ItemValue=6;
                    }
                    else if(temp_reg==ISP_DRIVING_8MA)
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
		    info_ptr->ItemValue=MT9P012_MIPI_LIMIT_EXPOSURE_LINES;
                    info_ptr->IsTrueFalse=KAL_FALSE;
                    info_ptr->IsReadOnly=KAL_TRUE;
                    info_ptr->IsNeedRestart=KAL_FALSE;
                    info_ptr->Min=0;
                    info_ptr->Max=0;
                break;
			
        	    case 1:
                    kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"Min Frame Rate");
                    info_ptr->ItemValue=MT9P012_MIPI_MIN_FRAME_RATE;
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
                    kal_sprintf((kal_char *)(info_ptr->ItemNamePtr),"REGAddr.");
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
    #endif
    }
}

kal_bool MT9P012MipiSetSensorItemInfo(kal_uint16 group_idx, kal_uint16 item_idx, kal_int32 item_value)
{
//   kal_int16 temp_reg;
    kal_uint16 temp_gain=0, temp_addr=0, temp_para=0;

    switch (group_idx)
    {
    #if(! defined(DRV_ISP_6238_SERIES))
        case MT9P012_MIPI_PRE_GAIN:
        switch (item_idx)
        {
            case 0:
                temp_addr = MT9P012_MIPI_PRE_GAIN_R_INDEX;
            break;
            case 1:
                temp_addr = MT9P012_MIPI_PRE_GAIN_Gr_INDEX;
            break;
            case 2:
                temp_addr = MT9P012_MIPI_PRE_GAIN_Gb_INDEX;
            break;
            case 3:
                temp_addr = MT9P012_MIPI_PRE_GAIN_B_INDEX;
            break;		
            case 4:
                temp_addr = MT9P012_MIPI_SENSOR_BASEGAIN;
            break;	
            default:
                ASSERT(0);
        }

        temp_gain=((item_value*BASEGAIN+500)/1000);			//+500:get closed integer value

        if(temp_gain>=1*BASEGAIN && temp_gain<=15*BASEGAIN)
        {
            temp_para=(temp_gain*8+BASEGAIN/2)/BASEGAIN;
        }
        else if(temp_gain>=16*BASEGAIN)
        {
            temp_para=(15.875*BASEGAIN*8+BASEGAIN/2)/BASEGAIN;
        }

        else
            return KAL_FALSE;

        pMT9P012MipiNvramSensorData->cct[temp_addr].para = temp_para;
        if(temp_addr != MT9P012_MIPI_SENSOR_BASEGAIN)
        {
            MT9P012MipiWriteReg(pMT9P012MipiNvramSensorData->cct[temp_addr].addr,temp_para);
        }

			MT9P012MipiSensorStatus.SensorGainBase=MT9P012MipiReadGain();
        if(temp_addr == MT9P012_MIPI_SENSOR_BASEGAIN)
        {
            MT9P012MipiWriteGain(BASEGAIN);
        }
        break;

        case MT9P012_MIPI_CMMCLK_CURRENT:
            switch (item_idx)
            {
                case 0:
                if(item_value==2)
                {
                    pMT9P012MipiNvramSensorData->reg[MT9P012_MIPI_CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_2MA;
                    SetIspDrivingCurrent(ISP_DRIVING_2MA);
                }
                else if(item_value==3 || item_value==4)
                {
                    pMT9P012MipiNvramSensorData->reg[MT9P012_MIPI_CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_4MA;
                    SetIspDrivingCurrent(ISP_DRIVING_4MA);
                }
                else if(item_value==5 || item_value==6)
                {
                    pMT9P012MipiNvramSensorData->reg[MT9P012_MIPI_CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_6MA;
                    SetIspDrivingCurrent(ISP_DRIVING_6MA);
                }
                else
                {
                    pMT9P012MipiNvramSensorData->reg[MT9P012_MIPI_CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_8MA;
			    	SetIspDrivingCurrent(ISP_DRIVING_8MA);
                }
                break;	
                default:
                    ASSERT(0);
		    }
	    break;

        case MT9P012_MIPI_FRAME_RATE_LIMITATION:
            switch (item_idx)
            {
                ASSERT(0);
            }
            break;
            case MT9P012_MIPI_REGISTER_EDITOR:
            switch (item_idx)
            {
                case 0:
				  MT9P012MipiFacSensorReg=item_value;
                break;
		
                case 1:
				  MT9P012MipiWriteReg(MT9P012MipiFacSensorReg,item_value);
                break;
			
                default:
                    ASSERT(0);
            }
            break;
        default:
            ASSERT(0);

    #else
        case PRE_GAIN:
            switch (item_idx)
            {			
                case 0:
                    temp_addr = PRE_GAIN_R_INDEX;
                break;
                case 1:
                    temp_addr = PRE_GAIN_Gr_INDEX;
                break;
                case 2:
                    temp_addr = PRE_GAIN_Gb_INDEX;
                break;
                case 3:
                    temp_addr = PRE_GAIN_B_INDEX;
                break;		
                case 4:
                    temp_addr = SENSOR_BASEGAIN;
                break;				
                default:
                ASSERT(0);
            }

            temp_gain=((item_value*BASEGAIN+500)/1000);			//+500:get closed integer value

            if(temp_gain>=1*BASEGAIN && temp_gain<=15*BASEGAIN)
            {
                temp_para=(temp_gain*8+BASEGAIN/2)/BASEGAIN;
            }
            else if(temp_gain>=16*BASEGAIN)
            {
                temp_para=(15.875*BASEGAIN*8+BASEGAIN/2)/BASEGAIN;
            }
            else
                return KAL_FALSE;
            pMT9P012MipiNvramSensorData->cct[temp_addr].para = temp_para;
            if(temp_addr != SENSOR_BASEGAIN)
            {
                MT9P012MipiWriteReg(pMT9P012MipiNvramSensorData->cct[temp_addr].addr,temp_para);
            }

		MT9P012MipiSensorStatus.SensorGainBase=MT9P012MipiReadGain();
            if(temp_addr == SENSOR_BASEGAIN)
            {
                MT9P012MipiWriteGain(BASEGAIN);
            }
        break;

        case CMMCLK_CURRENT:
            switch (item_idx)
            {
                case 0:
                    if(item_value==2)
                    {
                        pMT9P012MipiNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_2MA;
			            SetIspDrivingCurrent(ISP_DRIVING_2MA);
				    }
                    else if(item_value==3 || item_value==4)
                    {
                        pMT9P012MipiNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_4MA;
                        SetIspDrivingCurrent(ISP_DRIVING_4MA);   
                    }
                    else if(item_value==5 || item_value==6)
				    {
                        pMT9P012MipiNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_6MA;
                        SetIspDrivingCurrent(ISP_DRIVING_6MA);
                    }
                    else
                    {
                        pMT9P012MipiNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_8MA;
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
				  MT9P012MipiFacSensorReg=item_value;
                break;
                case 1:
				  MT9P012MipiWriteReg(MT9P012MipiFacSensorReg,item_value);
                break;
                default:
                    ASSERT(0);
            }
        break;
        default:
	        ASSERT(0);
    #endif
    }

    return KAL_TRUE;
}

// for camera HAL integration
// write camera_para to sensor register
void MT9P012MipiCameraParaToSensor(nvram_camera_para_struct *pCameraPara)
{
	kal_uint32	i;
	for(i=0; 0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr; i++)
	{
		MT9P012MipiWriteReg(pCameraPara->SENSOR.reg[i].addr, pCameraPara->SENSOR.reg[i].para);
}

#if(! defined(DRV_ISP_6238_SERIES))
	for(i=MT9P012_MIPI_ENGINEER_START_ADDR; 0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr; i++)
	{
		MT9P012MipiWriteReg(pCameraPara->SENSOR.reg[i].addr, pCameraPara->SENSOR.reg[i].para);
}
	for(i=MT9P012_MIPI_FACTORY_START_ADDR+1; i<5; i++)
	{
		MT9P012MipiWriteReg(pCameraPara->SENSOR.cct[i].addr, pCameraPara->SENSOR.cct[i].para);
}
#else
	for(i=ENGINEER_START_ADDR; 0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr; i++)
	{
		MT9P012MipiWriteReg(pCameraPara->SENSOR.reg[i].addr, pCameraPara->SENSOR.reg[i].para);
}
	for(i=FACTORY_START_ADDR+1; i<5; i++)
	{
		MT9P012MipiWriteReg(pCameraPara->SENSOR.cct[i].addr, pCameraPara->SENSOR.cct[i].para);
}
#endif
} /* MT9P012MipiCameraParaToSensor() */

// update camera_para from sensor register
void MT9P012MipiSensorToCameraPara(nvram_camera_para_struct *pCameraPara)
{
	kal_uint32	i;
	for(i=0; 0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr; i++)
	{
		pCameraPara->SENSOR.reg[i].para = MT9P012MipiReadReg(pCameraPara->SENSOR.reg[i].addr);
}
#if(! defined(DRV_ISP_6238_SERIES))
	for(i=MT9P012_MIPI_ENGINEER_START_ADDR; 0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr; i++)
	{
		pCameraPara->SENSOR.reg[i].para = MT9P012MipiReadReg(pCameraPara->SENSOR.reg[i].addr);
	}
#else
	for(i=ENGINEER_START_ADDR; 0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr; i++)
	{
		pCameraPara->SENSOR.reg[i].para = MT9P012MipiReadReg(pCameraPara->SENSOR.reg[i].addr);
	}
#endif
} /* MT9P012MipiSensorToCameraPara() */

void MT9P012MipiGetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT pSensorInfo)
{
    pSensorInfo->SensorId=MT9P012_MIPI_SENSOR_ID;
    pSensorInfo->SensorIf=IMAGE_SENSOR_IF_MIPI;
    pSensorInfo->PreviewNormalDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gb_FIRST;
    pSensorInfo->PreviewHMirrorDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_B_FIRST;
    pSensorInfo->PreviewVMirrorDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_R_FIRST;
    pSensorInfo->PreviewHVMirrorDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gr_FIRST;    
    pSensorInfo->CaptureDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gb_FIRST;
    pSensorInfo->PixelClkInv=KAL_FALSE;
    pSensorInfo->PixelClkPolarity=POLARITY_LOW;
    pSensorInfo->HsyncPolarity=POLARITY_LOW;
    pSensorInfo->VsyncPolarity=POLARITY_LOW;
    pSensorInfo->PreviewMclkFreq = 24000000;
    pSensorInfo->CaptureMclkFreq = 24000000;
    pSensorInfo->VideoMclkFreq = 24000000;
    pSensorInfo->PreviewWidth=MT9P012_MIPI_IMAGE_SENSOR_PV_WIDTH;
    pSensorInfo->PreviewHeight=MT9P012_MIPI_IMAGE_SENSOR_PV_HEIGHT;
    pSensorInfo->FullWidth=MT9P012_MIPI_IMAGE_SENSOR_FULL_WIDTH;
    pSensorInfo->FullHeight=MT9P012_MIPI_IMAGE_SENSOR_FULL_HEIGHT;	
    pSensorInfo->SensorAfSupport=KAL_FALSE;
    pSensorInfo->SensorFlashSupport=KAL_FALSE;
} /* MT9P012MipiGetSensorInfo() */


void MT9P012MipiGetMipiInfo(P_IMAGE_SENSOR_MIPI_PARA_IN_STRUCT pParaIn, P_IMAGE_SENSOR_MIPI_PARA_OUT_STRUCT pParaOut)
{
    if((CAL_SCENARIO_CAMERA_PREVIEW == pParaIn->ScenarioMode)
        ||(CAL_SCENARIO_WEBCAM_PREVIEW == pParaIn->ScenarioMode)
        ||(CAL_SCENARIO_CCT_CAMERA_PREVIEW == pParaIn->ScenarioMode))
    {
        pParaOut->MipiLaneNum = 1;
        pParaOut->LowPwr2HighSpeedDelayCount = 20;
    }
    else if ((CAL_SCENARIO_CAMERA_STILL_CAPTURE ==pParaIn->ScenarioMode) 
        ||(CAL_SCENARIO_CCT_CAMERA_CAPTURE_JPEG ==pParaIn->ScenarioMode) 
        ||(CAL_SCENARIO_CCT_CAMERA_CAPTURE_RAW ==pParaIn->ScenarioMode))
    {

	if ((pParaIn->TargetWidth<=MT9P012_MIPI_IMAGE_SENSOR_PV_WIDTH)
	    &&(pParaIn->TargetHeight<=MT9P012_MIPI_IMAGE_SENSOR_PV_HEIGHT))
	{
			//#ifdef CAM_OFFLINE_CAPTURE
			if (CAL_RAW_CAPTURE_MODE_OFFLINE==pParaIn->CaptureScenario)
			{
			pParaOut->MipiLaneNum = 1;
			pParaOut->LowPwr2HighSpeedDelayCount = 6;
			}
			//#elif CAM_OTF_CAPTURE
			else if (CAL_RAW_CAPTURE_MODE_OTF==pParaIn->CaptureScenario)
			{
			pParaOut->MipiLaneNum = 1;
			pParaOut->LowPwr2HighSpeedDelayCount = 20;
			}
			//#else //CAM_STANDARD_CAPTURE
			else
			{
			if (pParaIn->DigitalZoomFactor>100)
			{
				pParaOut->MipiLaneNum = 1;
				pParaOut->LowPwr2HighSpeedDelayCount = 6;
			}
			else
			{
				pParaOut->MipiLaneNum = 1;
				pParaOut->LowPwr2HighSpeedDelayCount = 20;
			}
			}
			//#endif

        }
        else
        {
            //#ifdef CAM_OFFLINE_CAPTURE
            if (CAL_RAW_CAPTURE_MODE_OFFLINE==pParaIn->CaptureScenario)
            {
            pParaOut->MipiLaneNum = 1;
            pParaOut->LowPwr2HighSpeedDelayCount = 10;
            }
            //#elif CAM_OTF_CAPTURE
            else if (CAL_RAW_CAPTURE_MODE_OTF==pParaIn->CaptureScenario)
            {
            pParaOut->MipiLaneNum = 1;
            pParaOut->LowPwr2HighSpeedDelayCount = 20;
            }
            //#else //CAM_STANDARD_CAPTURE
            else
            {
            if (pParaIn->DigitalZoomFactor>100)
            {
                pParaOut->MipiLaneNum = 1;
                pParaOut->LowPwr2HighSpeedDelayCount = 10;
            }
            else
            {
                pParaOut->MipiLaneNum = 1;
                pParaOut->LowPwr2HighSpeedDelayCount = 20;
            }
            }
            //#endif
        }
    }
    else if((CAL_SCENARIO_VIDEO ==pParaIn->ScenarioMode))
    {
        pParaOut->MipiLaneNum = 1;
        pParaOut->LowPwr2HighSpeedDelayCount = 20;
    }
    
}


static kal_uint16 MT9P012MipiPowerOn(void)
{
    kal_uint16 SensorId;
    kal_uint8 i=0;

    CisModulePowerOn(MT9P012MipiSensorIdx, KAL_TRUE);
	CameraSccbOpen(CAMERA_SCCB_SENSOR, MT9P012_MIPI_HW_SCCB_SLAVE_ADDR, CAMERA_SCCB_16BIT, CAMERA_SCCB_8BIT, 320);
    kal_sleep_task(3);					// To wait for Stable Power

    CamRstPinCtrl(MT9P012MipiSensorIdx, 1);
    kal_sleep_task(3);

    CamWriteCmosSensor(0x0103, 0x01);	// SOFTWARE_RESET (clears itself)

    kal_sleep_task(3);

    /* Check ID */
    for (i=0;i<3;i++)
    {
        SensorId=(CamReadCmosSensor(0x0000)<<8)|CamReadCmosSensor(0x0001);

        if (SensorId==MT9P012_MIPI_SENSOR_ID)
            break;
    }
    return SensorId;
} /* MT9P012MipiPowerOn() */

kal_uint32 MT9P012MipiDetectSensorId(void)
{
  MM_ERROR_CODE_ENUM MT9P012MipiSensorClose(void);
  kal_uint16 MT9P012MipiPowerOn();
  kal_uint16 sensorId, AnotherSensorIdx;
  kal_int8 i, j;
  
  if (IMAGE_SENSOR_MAIN == MT9P012MipiSensorIdx)
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
      sensorId = MT9P012MipiPowerOn();
      MT9P012MipiSensorClose();
#ifdef MT9P012_MIPI_DBG
      kal_wap_trace(MOD_ENG,TRACE_INFO,"MT9P012_MIPI DetectSensorId:%x",sensorId);
#endif
      if (MT9P012_MIPI_SENSOR_ID == sensorId)
      {
        return MT9P012_MIPI_SENSOR_ID;
      }
    }
  }
  return MM_ERROR_SENSOR_READ_ID_FAIL;
} /* MT9P012MipiDetectSensorId() */


MM_ERROR_CODE_ENUM MT9P012MipiSensorOpen(void)
{
    IspSetInterruptTriggerDelayLines(1);	// 0: VD INT, others: TG INT & start line

    if (MT9P012MipiPowerOn()!= MT9P012_MIPI_SENSOR_ID)
        return MM_ERROR_SENSOR_READ_ID_FAIL;

    MT9P012MipiInitSetting();
    MT9P012MipiSensorStatus.SensorGainBase = MT9P012MipiReadGain();
    MT9P012MipiSensorStatus.GlobalGain=BASEGAIN;

    return MM_ERROR_NONE;
} /* MT9P012MipiSensorOpen() */

static void MT9P012MipiPreview(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{

    MT9P012MipiSensorStatus.PvMode=KAL_TRUE;
    
    MT9P012MipiInitSingleLaneRaw8bit();
    MT0P012MipiSet8bitSXGA();

	MT9P012MipiSensorStatus.PvDummyPixels=0;
    MT9P012MipiSensorStatus.PvDummyLines=0;

    MT9P012MipiSensorStatus.PvPclk=100;//000000Hz VT CLK
    MT9P012MipiSensorStatus.PvLineLength=MT9P012_MIPI_PV_PERIOD_PIXEL_NUMS+MT9P012MipiSensorStatus.PvDummyPixels;//Reg 0x300c, 0x300d
    MT9P012MipiSensorStatus.PvFrameLength=MT9P012_MIPI_PV_PERIOD_LINE_NUMS+MT9P012MipiSensorStatus.PvDummyLines;

    MT9P012MipiSetMirrorFlip(pParaIn->ImageMirror);

    MT9P012MipiSetDummy(MT9P012MipiSensorStatus.PvLineLength,MT9P012MipiSensorStatus.PvFrameLength);

    pParaOut->GrabStartX = 1;
    pParaOut->GrabStartY = 2;
    pParaOut->ExposureWindowWidth = MT9P012_MIPI_IMAGE_SENSOR_PV_WIDTH;
    pParaOut->ExposureWindowHeight = MT9P012_MIPI_IMAGE_SENSOR_PV_HEIGHT;

    MT9P012MipiWriteShutter(MT9P012MipiSensorStatus.ExposureLines);

}/* MT9P012MipiPreview */


void MT9P012MipiGetPreviewFlashlightInfo(P_FLASHLIGHT_PREVIEW_PARA_STURCT pPreviewInfo)
{
    pPreviewInfo->pixels = MT9P012_MIPI_PV_PERIOD_PIXEL_NUMS;
    pPreviewInfo->lines = MT9P012_MIPI_IMAGE_SENSOR_PV_HEIGHT;
    pPreviewInfo->frame_lines = MT9P012_MIPI_PV_PERIOD_LINE_NUMS;
    //flashlight_sensor_preview_config(&flashlight_preview_para, pParaIn);
    
}

static void MT9P012MipiCapture(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{
    float ShutterTemp=MT9P012MipiSensorStatus.ExposureLines;
    volatile kal_uint16 Shutter=MT9P012MipiSensorStatus.ExposureLines;


    if(KAL_TRUE==pParaIn->EnableShutterTransfer)
    {
        Shutter=pParaIn->CaptureShutter;
        ShutterTemp=(float)pParaIn->CaptureShutter;
    }

    if ((pParaIn->ImageTargetWidth<=MT9P012_MIPI_IMAGE_SENSOR_PV_WIDTH)&&
        (pParaIn->ImageTargetHeight<=MT9P012_MIPI_IMAGE_SENSOR_PV_HEIGHT))
    {
    
        MT9P012MipiInitSingleLaneRaw10bit();
        MT0P012MipiSet10bitSXGA(pParaIn->CaptureScenario);

        //#ifdef CAM_OTF_CAPTURE
        if (CAL_RAW_CAPTURE_MODE_OTF==pParaIn->CaptureScenario)
        {
            MT9P012MipiSensorStatus.CapPclk=96;//000000Hz
            MT9P012MipiSensorStatus.CapDummyLines = 0;

            if (100==pParaIn->ZoomFactor) /* 1x capture */
                MT9P012MipiSensorStatus.CapDummyPixels = 0;
            else if(pParaIn->ZoomFactor<200)/* 1x~2x capture */
                MT9P012MipiSensorStatus.CapDummyPixels = 500;
            else if(pParaIn->ZoomFactor<=400)/* 2x~4x capture */
                MT9P012MipiSensorStatus.CapDummyPixels = 2800;
            else /* 4x~8x capture */
                MT9P012MipiSensorStatus.CapDummyPixels = 3500;
        }
        //#else
        else
        {
            MT9P012MipiSensorStatus.CapPclk=120;//000000Hz
            MT9P012MipiSensorStatus.CapDummyPixels=0;
            MT9P012MipiSensorStatus.CapDummyLines=0;
        }
        //#endif

            MT9P012MipiSensorStatus.CapLineLength=MT9P012_MIPI_VGA_CAP_PERIOD_PIXEL_NUMS+MT9P012MipiSensorStatus.CapDummyPixels;
            MT9P012MipiSensorStatus.CapFrameLength=MT9P012_MIPI_VGA_CAP_PERIOD_LINE_NUMS+MT9P012MipiSensorStatus.CapDummyLines;

            pParaOut->GrabStartX = 0;
            pParaOut->GrabStartY = 2;
            pParaOut->ExposureWindowWidth = MT9P012_MIPI_IMAGE_SENSOR_PV_WIDTH;
            pParaOut->ExposureWindowHeight = MT9P012_MIPI_IMAGE_SENSOR_PV_HEIGHT;
        }
    
    else  //>1.3M
    {
        MT9P012MipiSensorStatus.PvMode=KAL_FALSE;
        MT9P012MipiInitSingleLaneRaw10bit();

        //#ifdef CAM_OFFLINE_CAPTURE
        if (CAL_RAW_CAPTURE_MODE_OFFLINE==pParaIn->CaptureScenario)
        {
            MT9P012MipiSensorStatus.HighSpeedCapture=KAL_TRUE;
            MT9P012MipiSensorStatus.CapDummyPixels=0;
            MT9P012MipiSensorStatus.CapDummyLines=0;
        }
        //#elif CAM_OTF_CAPTURE
        else if (CAL_RAW_CAPTURE_MODE_OTF==pParaIn->CaptureScenario)
        {
            MT9P012MipiSensorStatus.CapPclk=96;
            MT9P012MipiSensorStatus.HighSpeedCapture=KAL_FALSE;
            MT9P012MipiSensorStatus.CapDummyLines=0;
            MT9P012MipiSensorStatus.CapFrameLength=MT9P012_MIPI_FULL_OTF_PERIOD_LINE_NUMS+MT9P012MipiSensorStatus.CapDummyLines;

        /* Check Zoom Factor */
        if (100==pParaIn->ZoomFactor)  //1x capture
            MT9P012MipiSensorStatus.CapLineLength=MT9P012_MIPI_FULL_OTF_PERIOD_PIXEL_NUMS;
        else if(pParaIn->ZoomFactor<200)//1x~2x capture
            MT9P012MipiSensorStatus.CapLineLength=MT9P012MipiSensorStatus.CapPclk*1000000/MT9P012_MIPI_FULL_OTF_PERIOD_LINE_NUMS/MT9P012_MIPI_2X_ZOOM_IN_CAPTURE_FRAME;
        else if(pParaIn->ZoomFactor<=400)//2x~4x capture
            MT9P012MipiSensorStatus.CapLineLength=MT9P012MipiSensorStatus.CapPclk*1000000/MT9P012_MIPI_FULL_OTF_PERIOD_LINE_NUMS/MT9P012_MIPI_4X_ZOOM_IN_CAPTURE_FRAME;
        else //4x~8x capture
            MT9P012MipiSensorStatus.CapLineLength=MT9P012MipiSensorStatus.CapPclk*1000000/MT9P012_MIPI_FULL_OTF_PERIOD_LINE_NUMS/MT9P012_MIPI_8X_ZOOM_IN_CAPTURE_FRAME;
        }
        //#else ////CAM_STANDARD_CAPTURE
        else
        {
        if (pParaIn->ZoomFactor>100)
        {
            MT9P012MipiSensorStatus.HighSpeedCapture=KAL_TRUE;
            MT9P012MipiSensorStatus.CapDummyPixels = 0;
            MT9P012MipiSensorStatus.CapDummyLines=0;
        }
        else
        {
            MT9P012MipiSensorStatus.HighSpeedCapture=KAL_FALSE;
            MT9P012MipiSensorStatus.CapDummyPixels=0;
            MT9P012MipiSensorStatus.CapDummyLines=0;
            MT9P012MipiSensorStatus.CapLineLength=MT9P012_MIPI_FULL_OTF_PERIOD_PIXEL_NUMS+MT9P012MipiSensorStatus.CapDummyPixels;
            MT9P012MipiSensorStatus.CapFrameLength=MT9P012_MIPI_FULL_OTF_PERIOD_LINE_NUMS+MT9P012MipiSensorStatus.CapDummyLines;
        }
        }
        //#endif

        if (KAL_TRUE==MT9P012MipiSensorStatus.HighSpeedCapture)
        {
            MT0P012MipiSet10bitQSXGA11fps();
            MT9P012MipiSensorStatus.CapPclk=120; //MHz
            MT9P012MipiSensorStatus.CapLineLength=MT9P012_MIPI_FULL_11FPS_PERIOD_PIXEL_NUMS+MT9P012MipiSensorStatus.CapDummyPixels;
            MT9P012MipiSensorStatus.CapFrameLength=MT9P012_MIPI_FULL_11FPS_PERIOD_LINE_NUMS+MT9P012MipiSensorStatus.CapDummyLines;
        }
        else
        {
            MT0P012MipiSet10bitQSXGA();
            MT9P012MipiSensorStatus.CapPclk=96; //MHz
        }

        pParaOut->GrabStartX = 0;
        pParaOut->GrabStartY = 2;
        pParaOut->ExposureWindowWidth = MT9P012_MIPI_IMAGE_SENSOR_FULL_WIDTH;
        pParaOut->ExposureWindowHeight = MT9P012_MIPI_IMAGE_SENSOR_FULL_HEIGHT;
    }

    MT9P012MipiSetMirrorFlip(pParaIn->ImageMirror);

    MT9P012MipiSetDummy(MT9P012MipiSensorStatus.CapLineLength,MT9P012MipiSensorStatus.CapFrameLength);

    ShutterTemp=((ShutterTemp*MT9P012MipiSensorStatus.PvLineLength/MT9P012MipiSensorStatus.CapLineLength)*MT9P012MipiSensorStatus.CapPclk)/MT9P012MipiSensorStatus.PvPclk;

    if(KAL_FALSE==MT9P012MipiSensorStatus.PvMode)
    {
        ShutterTemp=ShutterTemp*2;	//preview binning mode
    }

    Shutter=ShutterTemp+0.5;

    MT9P012MipiSensorStatus.CapShutter = Shutter;

    if(Shutter<1)
        Shutter=1;

    MT9P012MipiWriteShutter(Shutter);

} /* MT9P012MipiCapture() */


void MT9P012MipiGetCaptureFlashlightInfo(P_FLASHLIGHT_CAPTURE_SENSOR_PARA_IN_STRUCT pParaIn, P_FLASHLIGHT_CAPTURE_PARA_STRUCT pCaptureInfo)
{
    if(KAL_TRUE==MT9P012MipiSensorStatus.PvMode)
    {
        //#ifdef CAM_OTF_CAPTURE
        if (CAL_RAW_CAPTURE_MODE_OTF==pParaIn->CaptureScenario)
            pCaptureInfo->default_pclk = 48000000;
        //#else
        else
            pCaptureInfo->default_pclk = 60000000;// op clk
        //#endif
    }
    else
    {
        if (KAL_TRUE==MT9P012MipiSensorStatus.HighSpeedCapture)
        {
            pCaptureInfo->default_pclk=60000000;
        }
        else
        {
            pCaptureInfo->default_pclk=48000000;
        }
    }
    pCaptureInfo->pixels = MT9P012MipiSensorStatus.CapLineLength;
    pCaptureInfo->frame_lines = MT9P012MipiSensorStatus.CapFrameLength;
    pCaptureInfo->lines = MT9P012_MIPI_IMAGE_SENSOR_FULL_HEIGHT;
    pCaptureInfo->shutter = MT9P012MipiSensorStatus.CapShutter;
    //Shutter = flashlight_sensor_capture_config(&flashlight_capture_para, pParaIn);    
    
}

static void MT9P012MipiVideo(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{
    MT9P012MipiSensorStatus.PvMode=KAL_TRUE;

    MT9P012MipiInitSingleLaneRaw8bit();
    MT0P012MipiSet8bitSXGA();

	MT9P012MipiSensorStatus.PvPclk=100;//000000Hz VT CLK

    MT9P012MipiSensorStatus.PvLineLength=MT9P012_MIPI_PV_PERIOD_PIXEL_NUMS;//Reg 0x300c, 0x300d
    MT9P012MipiSensorStatus.PvFrameLength=MT9P012_MIPI_PV_PERIOD_LINE_NUMS;

    MT9P012MipiFixVideoFrameRate(pParaIn->MaxVideoFrameRate);

    MT9P012MipiSetMirrorFlip(pParaIn->ImageMirror);

    pParaOut->GrabStartX = 1;
    pParaOut->GrabStartY = 2;
    pParaOut->ExposureWindowWidth = MT9P012_MIPI_IMAGE_SENSOR_PV_WIDTH;
    pParaOut->ExposureWindowHeight = MT9P012_MIPI_IMAGE_SENSOR_PV_HEIGHT;
}/* MT9P012MipiVideo */



MM_ERROR_CODE_ENUM MT9P012MipiBinningInfo(P_CAL_FEATURE_CTRL_STRUCT pFeatureParaIn,
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
}   /* MT9P012MipiBinningInfo() */

MM_ERROR_CODE_ENUM MT9P012MipiStillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT pFeatureParaIn,
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
}   /* MT9P012MipiStillCaptureSize() */

void MT9P012MipiInitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT pInitOperPara)
{
	pInitOperPara->CaptureDelayFrame = 2;			/* wait stable frame when sensor change mode (pre to cap) */
	pInitOperPara->PreviewDelayFrame = 3;			/* wait stable frame when sensor change mode (cap to pre) */
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
} /* MT9P012MipiInitOperationPara() */

void MT9P012MipiDscSupportInfo(P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT pDscSupportInfo)
{
    kal_mem_cpy(pDscSupportInfo, &MT9P012_MIPI_dsc_support_info, sizeof(camcorder_info_struct));
} /* MT9P012MipiDscSupportInfo() */


MM_ERROR_CODE_ENUM MT9P012MipiSensorFeatureCtrl(kal_uint32 FeatureId,
                                                void* pFeatureParaIn, void* pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;
	kal_uint32 i=0;
    if ((FeatureId>=CAL_FEATURE_WEBCAM_BEGIN)&&
        (FeatureId<=CAL_FEATURE_WEBCAM_END))
    {
        ErrorCode=MT9P012MipiWebcamFeatureCtrl(FeatureId, pFeatureParaIn, pFeatureParaOut,
                                               FeatureParaOutLen, pRealFeatureParaOutLen);
        return ErrorCode;
    }
    // for the features that not support in the sensor, then it is not necessary to implement it.
    switch (FeatureId)
    {
        /*get*/
        case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
            MT9P012MipiGetSensorInfo((P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT) pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_MIPI_INFO:
            MT9P012MipiGetMipiInfo((P_IMAGE_SENSOR_MIPI_PARA_IN_STRUCT)pFeatureParaIn,(P_IMAGE_SENSOR_MIPI_PARA_OUT_STRUCT) pFeatureParaOut);
            FeatureParaOutLen = sizeof(P_IMAGE_SENSOR_MIPI_PARA_OUT_STRUCT);
            *pRealFeatureParaOutLen = sizeof(P_IMAGE_SENSOR_MIPI_PARA_OUT_STRUCT);            
        break;        
        case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
            ((P_IMAGE_SENSOR_COMM_DATA_STRUCT) pFeatureParaOut)->FeatureValue=MT9P012MipiDetectSensorId();
        break;
        case IMAGE_SENSOR_FEATURE_GET_PREVIEW_FLASHLIGHT_INFO:
            MT9P012MipiGetPreviewFlashlightInfo((P_FLASHLIGHT_PREVIEW_PARA_STURCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_CAPTURE_FLASHLIGHT_INFO:
            MT9P012MipiGetCaptureFlashlightInfo((P_FLASHLIGHT_CAPTURE_SENSOR_PARA_IN_STRUCT)pFeatureParaIn, (P_FLASHLIGHT_CAPTURE_PARA_STRUCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_AE_INFO:
            MT9P012MipiGetSensorAeInfo((P_IMAGE_SENSOR_AE_INFO_STRUCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_AE_LUT:
            MT9P012MipiGetAeLut((P_AE_LUT_INFO_STRUCT) pFeatureParaIn, (P_IMAGE_SENSOR_AE_LUT_STRUCT)pFeatureParaOut,
                                FeatureParaOutLen, pRealFeatureParaOutLen);
        break;
        case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
            ((P_IMAGE_SENSOR_COMM_DATA_STRUCT) pFeatureParaOut)->FeatureValue=MT9P012MipiSensorStatus.VideoCurrentFrameRate;
        break;
        case IMAGE_SENSOR_FEATURE_GET_SHADING_TABLE:
            ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        break;
        case IMAGE_SENSOR_FEATURE_GET_CCT_REGISTER:
            ((P_CAL_CCT_REG_RW_STRUCT)pFeatureParaOut)->RegData = MT9P012MipiReadReg(((P_CAL_CCT_REG_RW_STRUCT)pFeatureParaOut)->RegAddr);
        break;		
        case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
            MT9P012MipiInitOperationPara((P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_DSC_SUPPORT_INFO:
            MT9P012MipiDscSupportInfo((P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_GAIN:
            ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaOut)->FeatureValue=MT9P012MipiReadGain();
        break;
        case IMAGE_SENSOR_FEATURE_GET_ENG_INFO:
            ((P_SENSOR_INFO_STRUCT)pFeatureParaOut)->id = 128;
            ((P_SENSOR_INFO_STRUCT)pFeatureParaOut)->type = CMOS_SENSOR;
        break;
        case IMAGE_SENSOR_FEATURE_GET_CCT_GROUP_COUNT:
            MT9P012MipiGetSensorGroupCount((kal_int32*)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_CCT_GROUP_INFO:
            MT9P012MipiGetSensorGroupInfo(((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaIn)->GroupNamePtr, &((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaOut)->ItemCount);
        break;  
        case IMAGE_SENSOR_FEATURE_GET_CCT_ITEM_INFO:
            MT9P012MipiGetSensorItemInfo(((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemIdx, (P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaOut);
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
            MT9P012MipiSetShutter(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
        break;
        case IMAGE_SENSOR_FEATURE_SET_GAIN:
            MT9P012MipiSetGain(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
        break;
        case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
            MT9P012MipiSensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT) pFeatureParaIn)->ImageSensorIdx;
        break;
		case IMAGE_SENSOR_FEATURE_SET_CCT_REGISTER:
			 MT9P012MipiWriteReg(((P_CAL_CCT_REG_RW_STRUCT)pFeatureParaIn)->RegAddr,((P_CAL_CCT_REG_RW_STRUCT)pFeatureParaIn)->RegData);
		break;
		case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
			 pMT9P012MipiNvramSensorData = &(((nvram_camera_para_struct *) pFeatureParaIn)->SENSOR);
		break;
		case IMAGE_SENSOR_FEATURE_SET_CCT_ITEM_INFO:
			 MT9P012MipiSetSensorItemInfo(((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemIdx, ((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemValue);
		break;
	    case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
            CamRstPinCtrl(MT9P012MipiSensorIdx, 0);
	        CamPdnPinCtrl(MT9P012MipiSensorIdx, 0);
        break;		 
		 
		
        case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE:
            MT9P012MipiNightMode(((P_IMAGE_SENSOR_COMM_CTRL_STRUCT)pFeatureParaIn)->FeatureEnable);
        break;
        case IMAGE_SENSOR_FEATURE_CTRL_FLASHLIGHT:
            MT9P012MipiSetFlashlight(((P_IMAGE_SENSOR_COMM_CTRL_STRUCT)pFeatureParaIn)->FeatureEnable);
        break;
        case CAL_FEATURE_CAMERA_BINNING_INFO:
            ErrorCode=MT9P012MipiBinningInfo((P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaIn,
                                             (P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaOut, FeatureParaOutLen, pRealFeatureParaOutLen);
        break;
        // customized by customer
        case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
            ErrorCode=MT9P012MipiStillCaptureSize((P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaIn,
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
        
        default:
            ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        break;
    }
    return ErrorCode;
} /* MT9P012MipiSensorFeatureCtrl() */

MM_ERROR_CODE_ENUM MT9P012MipiSensorCtrl(CAL_SCENARIO_ENUM ScenarioId, void *pParaIn,
                                         void *pParaOut, kal_uint16 ParaOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

    switch (ScenarioId)
    {
        case CAL_SCENARIO_CAMERA_PREVIEW:
        case CAL_SCENARIO_WEBCAM_PREVIEW:
        case CAL_SCENARIO_WEBCAM_CAPTURE:
            MT9P012MipiPreview(ScenarioId, pParaIn, pParaOut);
        break;
        case CAL_SCENARIO_VIDEO:
			MT9P012MipiVideo(ScenarioId, pParaIn, pParaOut);
        break;
        case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
            MT9P012MipiCapture(ScenarioId, pParaIn, pParaOut);
        break;
        default:
        break;
    }
    return ErrorCode;
}

MM_ERROR_CODE_ENUM MT9P012MipiSensorClose(void)
{
  /*CamPdnPinCtrl(MT9P012MipiSensorIdx, 1);
  CamRstPinCtrl(MT9P012MipiSensorIdx, 1);*/
  CisModulePowerOn(MT9P012MipiSensorIdx, KAL_FALSE);
  CameraSccbClose(CAMERA_SCCB_SENSOR);

    return MM_ERROR_NONE;
}

IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncMT9P012Mipi=
{
    MT9P012MipiSensorOpen,
    MT9P012MipiSensorFeatureCtrl,
    MT9P012MipiSensorCtrl,
    MT9P012MipiSensorClose,
};

MM_ERROR_CODE_ENUM MT9P012MipiSensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
	*pfSensorFunc=&ImageSensorFuncMT9P012Mipi;
}	/* cam_module_func_config() */
