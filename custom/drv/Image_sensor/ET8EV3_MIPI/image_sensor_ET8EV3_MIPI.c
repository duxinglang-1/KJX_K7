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
 *   image_sensor_ET8EV3_MIPI.c
 *
 * Project:
 * --------
 *   MT6236
 *
 * Description:
 * ------------
 *   ET8EV3 MIPI sensor driver
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

#define __ET8EV3_MIPI_DBG__


IMAGE_SENSOR_INDEX_ENUM ET8EV3MipiSensorIdx;
sensor_data_struct *pET8EV3MipiNvramSensorData;
SensorInfo ET8EV3_MIPI_g_CCT_MainSensor = ET8EV3_MIPI_CURRENT_MAIN_SENSOR;
static struct ET8EV3_MIPI_SENSOR_STRUCT ET8EV3MipiSensorStatus;
extern camcorder_info_struct	ET8EV3_MIPI_dsc_support_info;
extern void SetIspDrivingCurrent(kal_uint8 Current);
extern void CamRstPinCtrl(IMAGE_SENSOR_INDEX_ENUM Idx, kal_int8 Data);
extern void CamPdnPinCtrl(IMAGE_SENSOR_INDEX_ENUM Idx, kal_int8 Data);

static void ET8EV3MipiSetDummy(const kal_uint16 iPixels, const kal_uint16 iLines)
{
    kal_uint16 ttldot;
	kal_uint16 ttline;
    
	if (ET8EV3MipiSensorStatus.PvMode == KAL_TRUE)
	{
		ttldot=ET8EV3MipiSensorStatus.PvLineLength;
		ttline=ET8EV3MipiSensorStatus.PvFrameLength;

	} else {
		ttldot=ET8EV3MipiSensorStatus.CapLineLength;
		ttline=ET8EV3MipiSensorStatus.CapFrameLength;
	}

	ttldot+=iPixels;
	ttline+=iLines;

#ifdef __ET8EV3_MIPI_DBG__	
    kal_print_string_trace (MOD_ENG,TRACE_INFO, "ET8EV3MipiSetDummy(): Ipixels=%x, iLines=%x,", iPixels, iLines);
    kal_print_string_trace (MOD_ENG,TRACE_INFO, "ET8EV3MipiSetDummy(): ttldot=%x, ttline=%x,", ttldot, ttline);
#endif

    CamWriteCmosSensor(0x0307,ttldot>>8);//TTLDOT[15:8]                                   
	CamWriteCmosSensor(0x0308,ttldot&0x00FF);//TTLDOT[7:0];                                             
	CamWriteCmosSensor(0x0305,ttline>>8);//TTLINE[15:8]                                    
	CamWriteCmosSensor(0x0306,ttline&0x00FF);//TTLINE[7:0];    

}   /*  ET8EV3_MIPI_Set_Dummy    */


//void ET8EV3MipiWriteShutter(const kal_uint16 iShutter)
void ET8EV3MipiWriteShutter(kal_uint16 iShutter)
{

    if (ET8EV3MipiSensorStatus.PvMode == KAL_TRUE)
    	{
    	   // Preview Mode or Small Size Capture
    		if(iShutter > (ET8EV3_MIPI_PV_PERIOD_LINE_NUMS -8))
    			{
    			    // If shutter larger than one frame
					ET8EV3MipiSensorStatus.PvDummyLines= iShutter- ET8EV3MipiSensorStatus.PvFrameLength;
    			}
			else
				{
				   // If shutter within one frame
					ET8EV3MipiSensorStatus.PvDummyLines= 0;				   
				}

			ET8EV3MipiSetDummy(ET8EV3MipiSensorStatus.PvDummyPixels, ET8EV3MipiSensorStatus.PvDummyLines);
			
		#ifdef __ET8EV3_MIPI_DBG__	
			kal_wap_trace(MOD_ENG,TRACE_INFO,"ET8EV3MipiWriteShutter(): PvDummyPixels=%x , PvDummyLines=%x",ET8EV3MipiSensorStatus.PvDummyPixels,ET8EV3MipiSensorStatus.PvDummyLines);
		#endif
    	}
	else
		{
		   // Capture Mode

    		if(iShutter > (ET8EV3_MIPI_FULL_PERIOD_LINE_NUMS -8))
    			{
    			  // If shutter larger than one frame
					ET8EV3MipiSensorStatus.CapDummyLines= iShutter - ET8EV3MipiSensorStatus.CapFrameLength;
    			}
			else
				{
				// If shutter within one frame
					ET8EV3MipiSensorStatus.CapDummyLines=0;

				}
			ET8EV3MipiSetDummy(ET8EV3MipiSensorStatus.CapDummyPixels,ET8EV3MipiSensorStatus.CapDummyLines);
		#ifdef __ET8EV3_MIPI_DBG__	
			kal_wap_trace(MOD_ENG,TRACE_INFO,"ET8EV3MipiWriteShutter(): CapDummyPixels=%x , CapDummyLines=%x",ET8EV3MipiSensorStatus.CapDummyPixels,ET8EV3MipiSensorStatus.CapDummyLines);			
		#endif
		}

	// Write the value into sensor
	CamWriteCmosSensor(0x0200,iShutter>>8);//INTGTIM[15:8];                                       
	CamWriteCmosSensor(0x0201,iShutter&0x00FF);//INTGTIM[7:0];                                                  

}

void ET8EV3MipiReadShutter()
{
	CamReadCmosSensor(0x0200);
	CamReadCmosSensor(0x0201);
}


/*************************************************************************
* FUNCTION
*	ET8EV3_MIPI_SetShutter
*
* DESCRIPTION
*	This function set e-shutter of ET8EV3_MIPI to change exposure time.
*
* PARAMETERS
*   iShutter : exposured lines
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/

void ET8EV3MipiSetShutter(const kal_uint16 iShutter)
{
#ifdef __ET8EV3_MIPI_DBG__
	kal_print_string_trace(MOD_ENG, TRACE_INFO, "** iShutter:%d",iShutter);

#endif

    ET8EV3MipiSensorStatus.ExposureLines=iShutter;

    ET8EV3MipiWriteShutter(iShutter);

 }  /*  ET8EV3_MIPI_Write_Shutter    */



void ET8EV3MiPiInitialSetting()
{

#ifdef __ET8EV3_MIPI_DBG__	
	kal_wap_trace(MOD_ENG,TRACE_INFO,"danbo Test Enter  ET8EV3MiPiInitialSetting \n:");
#endif
	/* Silicon Recommendation*/
	CamWriteCmosSensor(0x0000,0x10);//VERNUM[15:8];
	CamWriteCmosSensor(0x0001,0x00);//,VERNUM[7:0];
	CamWriteCmosSensor(0x0002,0x00);//,-/-/-/-/-/ANA_GA_MIN[11:8];
	CamWriteCmosSensor(0x0003,0x2C);//,ANA_GA_MIN[7:0];
	CamWriteCmosSensor(0x0004,0x01);//,-/-/-/-/-/ANA_GA_MAX[11:8];
	CamWriteCmosSensor(0x0005,0x60);//,ANA_GA_MAX[7:0];
	CamWriteCmosSensor(0x0010,0x60);//,PISO[15:8];
	CamWriteCmosSensor(0x0011,0x60);//,PISO[7:0];	
	CamWriteCmosSensor(0x0100,0x81);//,MODE_SEL/VREVON/HREVON/SWRST/GRHOLD/-/-/OUT_FORMAT;
	//CamWriteCmosSensor(0x0200,0x0F);//,INTGTIM[15:8];
	//CamWriteCmosSensor(0x0201,0xE4);//,INTGTIM[7:0];
	//CamWriteCmosSensor(0x0202,0x00);//,-/-/-/-/ANAGAIN[11:8];
	//CamWriteCmosSensor(0x0203,0xFD);//,ANAGAIN[7:0];
	//CamWriteCmosSensor(0x0204,0x01);//,-/-/-/-/-/-/MWBGAINGR[9:8];
	//CamWriteCmosSensor(0x0205,0x00);//,MWBGAINGR[7:0];
	//CamWriteCmosSensor(0x0206,0x01);//,-/-/-/-/-/-/MWBGAINR[9:8];
	//CamWriteCmosSensor(0x0207,0x00);//,MWBGAINR[7:0];
	//CamWriteCmosSensor(0x0208,0x01);//,-/-/-/-/-/-/MWBGAINB[9:8];
	//CamWriteCmosSensor(0x0209,0x00);//,MWBGAINB[7:0];
	//CamWriteCmosSensor(0x020A,0x01);//,-/-/-/-/-/-/MWBGAINGB[9:8];
	//CamWriteCmosSensor(0x020B,0x00);//,MWBGAINGB[7:0];
	CamWriteCmosSensor(0x0300,0x21);//,-/PIXCKDIV[2:0]/-/SYSCKDIV[2:0];
	CamWriteCmosSensor(0x0301,0x01);//,-/-/-/-/-/-/PRECKDIV[1:0];
	CamWriteCmosSensor(0x0302,0x01);//,-/-/-/-/-/OPSYSDIV[2:0];
	CamWriteCmosSensor(0x0303,0x00);//,-/-/-/-/-/-/-/PLLMULT[8];
	CamWriteCmosSensor(0x0304,0x42);//,PLLMULT[7:0];
	CamWriteCmosSensor(0x0305,0x03);//,TTLINE[15:8];
	CamWriteCmosSensor(0x0306,0xFC);//,TTLINE[7:0];
	CamWriteCmosSensor(0x0307,0x08);//,TTLDOT[15:8];
	CamWriteCmosSensor(0x0308,0x78);//,TTLDOT[7:0];
	CamWriteCmosSensor(0x030D,0x00);//,-/-/-/-/HOUT_STADR[11:8];
	CamWriteCmosSensor(0x030E,0x0C);//,HOUT_STADR[7:0];
	CamWriteCmosSensor(0x030F,0x00);//,-/-/-/-/VOUT_STADR[11:8];
	CamWriteCmosSensor(0x0310,0x82);//,VOUT_STADR[7:0];
	CamWriteCmosSensor(0x0311,0x05);//,-/-/-/-/HOUTSIZ[11:8];
	CamWriteCmosSensor(0x0312,0x00);//,HOUTSIZ[7:0];
	CamWriteCmosSensor(0x0313,0x02);//,-/-/-/-/VOUTSIZ[11:8];
	CamWriteCmosSensor(0x0314,0xD0);//,VOUTSIZ[7:0];
	CamWriteCmosSensor(0x0315,0x81);//,HANABIN/-/-/-/-/-/VMON[1:0];
	CamWriteCmosSensor(0x0400,0x00);//,/-/-/-/-/-/-/-/HSCALE;
	CamWriteCmosSensor(0x0600,0x02);//,TPAT_SEL[2:0]/(4)/(3)/(2)/ TPAT_R[9:8];
	CamWriteCmosSensor(0x0601,0xC0);//,TPAT_R[7:0];
	CamWriteCmosSensor(0x0602,0x02);//,(7)/(6)/(5)/(4)/(3)/(2)/ TPAT_GR[9:8];
	CamWriteCmosSensor(0x0603,0xC0);//,TPAT_GR[7:0];
	CamWriteCmosSensor(0x0604,0x02);//,(7)/(6)/(5)/(4)/(3)/(2)/ TPAT_B[9:8];
	CamWriteCmosSensor(0x0605,0xC0);//,TPAT_B[7:0];
	CamWriteCmosSensor(0x0606,0x02);//,(7)/(6)/(5)/(4)/(3)/(2)/ TPAT_GB[9:8];
	CamWriteCmosSensor(0x0607,0xC0);//,TPAT_GB[7:0];
	CamWriteCmosSensor(0x0608,0x00);//,(7)/(6)/(5)/(4)/ CURHW[11:8];
	CamWriteCmosSensor(0x0609,0x00);//,CURHW[7:0];
	CamWriteCmosSensor(0x060A,0x00);//,(7)/(6)/(5)/(4)/ CURHST[11:8];
	CamWriteCmosSensor(0x060B,0x00);//,CURHST[7:0];
	CamWriteCmosSensor(0x060C,0x00);//,(7)/(6)/(5)/(4)/(3)/ CORVW[10:8];
	CamWriteCmosSensor(0x060D,0x00);//,CORVW[7:0];
	CamWriteCmosSensor(0x060E,0x00);//,(7)/(6)/(5)/(4)/(3)/ CURVST[10:8];
	CamWriteCmosSensor(0x060F,0x00);//,CURVST[7:0];
	CamWriteCmosSensor(0x0000,0x00);//,*********WAIT**********
	CamWriteCmosSensor(0x3240,0xCA);//,POSLFIX/ NEGLFIX/ NEGLEAKCUT/ POSBSTSEL/ NEGBSTCNT[3:0];
	CamWriteCmosSensor(0x3241,0x63);//,(7)/ POSBSTCNT[2:0]/ (3)/ POSBSTHG[2:0];
	CamWriteCmosSensor(0x3242,0x35);//,GDMOSBGREN/ (6)/ VSIGDRSEL[1:0]/ (3)/ POSBSTGA[2:0];
	CamWriteCmosSensor(0x3243,0x26);//,GDMOSCNT[3:0]/ KBIASCNT[3:0];
	CamWriteCmosSensor(0x3244,0x22);//,SPARE[1:0]/ DRADRV[1:0]/ DRADRV_PU/ DRADRVL[2:0];
	CamWriteCmosSensor(0x3245,0x3E);//,S1CNT[3:0]/ CBIASIA[1:0]/ CBIASIB/ IDLOFFEN;
	CamWriteCmosSensor(0x3246,0x20);//,VREFDLYCNT/ VREFSWG[1:0]/ (3)/ SENSEMODE[2:0];
	CamWriteCmosSensor(0x3247,0x0C);//,LNOB_ON/ LNOBMODE/ EDGETESTEN[1:0]/ VOUT_SEL[3:0];
	CamWriteCmosSensor(0x3248,0x03);//,VLAT_OFF/ (6)/(5)/(4)/ (3)/ (2)/ (1)/ VCO_CONV;
	CamWriteCmosSensor(0x3250,0x04);//,BSC_OFF/ (6)/(5)/(4)/ SADR_1W[3:0];
	CamWriteCmosSensor(0x3251,0x84);//,ESRST_D[3:0]/ SAME_WD/ ES_MODE/ RODATA_U/ ALLZEROSET;
	CamWriteCmosSensor(0x3252,0x3C);//,(7)/ ESREAD_1W[6:0] ;
	CamWriteCmosSensor(0x3253,0x14);//,(7)/ ESREAD_2U[6:0];
	CamWriteCmosSensor(0x3254,0x3C);//,(7)/ ESREAD_2W[6:0];
	CamWriteCmosSensor(0x3255,0xC2);//,(7)/ ZSET_U[3:0]/ ZSET_W[3:0];
	CamWriteCmosSensor(0x3256,0x87);//,ZSET_W[4]/ RORST_W[6:0];
	CamWriteCmosSensor(0x3257,0x48);//,RORST_U[3:0]/ RSTDRAIN3_U[3:0];
	CamWriteCmosSensor(0x3258,0x00);//,STG_SPARE[7:0];
	CamWriteCmosSensor(0x3259,0x3C);//,(7)/ ROREAD_W[6:0];
	CamWriteCmosSensor(0x325A,0x66);//,RSTDRAIN2_U[3:0]/ RSTDRAIN3_D[3:0];
	CamWriteCmosSensor(0x325B,0x1B);//,(7)/(6)/ VSIGPU_W[5:0];
	CamWriteCmosSensor(0x325C,0x80);//,VSIGPU_U[3:0]/ VSIGDR_U[1:0]/ VSIGDR_D[1:0];
	CamWriteCmosSensor(0x325D,0x11);//,(7)/ DRCUT_U[2:0]/ VSIGPU_EN/ (2)/ VSIGDR1EN/ SIGDR2EN;
	CamWriteCmosSensor(0x325E,0x47);//,S1_1D[3:0]/ S1_2U[3:0];
	CamWriteCmosSensor(0x325F,0x68);//,S1_2W[3:0]/ S1_2P/ S1_DMPOFF/ (1)/ CDS_STPBST;
	CamWriteCmosSensor(0x3260,0x78);//,S3_W[3:0]/ S4_D[3:0];
	CamWriteCmosSensor(0x3261,0x05);//,AD9BIT/ (6)/(5)/(4)/ IDLOFF_U[1:0]/ IDLOFF_MG[1:0];
	CamWriteCmosSensor(0x3262,0x40);//,HPL2_SEL/ DRKCLIP_D[2:0]/ (3)/ INTEN_SU[2:0];
	CamWriteCmosSensor(0x3263,0xC2);//,FBC_ON/ FBC_MODE[1:0]/ CPFBC_MODE[1:0]/ FBC_SUSP[1:0]/ FBC_START;
	CamWriteCmosSensor(0x3264,0x82);//,CLAMPSFT_SEL[2:0]/ BLADJ_MODE[1:0]/ BLADJ_COEF[10:8];
	CamWriteCmosSensor(0x3265,0xAA);//,BLADJ_COEF[7:0];
	CamWriteCmosSensor(0x3266,0x00);//,EXT_CLP_ON/ FFBC/ (5)/(4)/ (3)/ S4IO/ OADJ_MODE[1:0];
	CamWriteCmosSensor(0x3267,0x00);//,(7)/ (6)/(5)/(4)/ OADJON_START[3:0];
	CamWriteCmosSensor(0x3268,0x20);//,OADJON_DLY[3:0]/ OADJON_WIDTH[3:0];
	CamWriteCmosSensor(0x3269,0x08);//,ES_MARGIN[7:0];
	CamWriteCmosSensor(0x326A,0x30);//,(7)/ BLEVEL[6:0];
	CamWriteCmosSensor(0x326B,0x34);//,(7)/ (6)/(5)/ FBC_ENREST[1:0]/ FBC_RESTLV[3:0] ;
	CamWriteCmosSensor(0x326C,0x20);//,(7)/ HOB_WIDTH[6:0];
	CamWriteCmosSensor(0x0000,0x00);//,************WAIT************
	CamWriteCmosSensor(0x3270,0x30);//,(7)/ LNNARROW/ HLNRSW/ PIXDANSA/ HOBPSTN[3:0];
	CamWriteCmosSensor(0x3271,0x00);//,HOBNRON/ VOBNRON/ SEKI_DISP/ HOBLKLVL[4:0];
	CamWriteCmosSensor(0x3272,0x00);//,VLNRSW,DANSASW[1:0]/ VOBNRON,VOBFIL/ (2)/ VOB_DISP,HOB_DISP;
	CamWriteCmosSensor(0x3273,0xC0);//,WBPCMODE,BBPCMODE/ (5)/(4)/ GAMMAOFF/ DRCDRE[1:0]/ ABCTH;
	CamWriteCmosSensor(0x3274,0x00);//,BBPCLV[7:0];
	CamWriteCmosSensor(0x3275,0x18);//,WBPCLV[7:0];
	CamWriteCmosSensor(0x3276,0x00);//,HCBCGA0[3:0]/ HCBCGA1[3:0];
	
#ifdef _SENSOR_CLOSE_AWB_   //Close Sensor  AWB
	CamWriteCmosSensor(0x3277,0x00);//,PWBGAINR[7:0];
	CamWriteCmosSensor(0x3278,0x00);//,PWBGAINGR[7:0];
	CamWriteCmosSensor(0x3279,0x00);//,PWBGAINGB[7:0];
	CamWriteCmosSensor(0x327A,0x00);//,PWBGAINB[7:0];
#else
	CamWriteCmosSensor(0x3277,0x38);//,PWBGAINR[7:0];
	CamWriteCmosSensor(0x3278,0x02);//,PWBGAINGR[7:0];
	CamWriteCmosSensor(0x3279,0x02);//,PWBGAINGB[7:0];
	CamWriteCmosSensor(0x327A,0x1D);//,PWBGAINB[7:0];
#endif
	CamWriteCmosSensor(0x327B,0x00);//,HDCBLACK[7:0];
	CamWriteCmosSensor(0x327C,0x5F);//,PWBBLNOFF/ HDCBLNOFF (5)/ HDCPOINT[4:0];
	
	//CamWriteCmosSensor(0x327D,0x8F);//,LSSCON /LSASIGN /LSQSIGN / (4) / HDSCLOPE[3:0];
	CamWriteCmosSensor(0x327D,0x0F);//,LSSCON /LSASIGN /LSQSIGN / (4) / HDSCLOPE[3:0];

	CamWriteCmosSensor(0x327E,0xFF);//,LSHGA[3:0] / LSVGA[3:0];
	CamWriteCmosSensor(0x327F,0x25);//,LSHOFS[7:0];
	CamWriteCmosSensor(0x3280,0x0C);//,LSVOFS[7:0];
	CamWriteCmosSensor(0x3281,0x1E);//,LSALGR[7:0];
	CamWriteCmosSensor(0x3282,0x1E);//,LSALGB[7:0];
	CamWriteCmosSensor(0x3283,0x1E);//,LSALR[7:0];
	CamWriteCmosSensor(0x3284,0x14);//,LSALB[7:0];
	CamWriteCmosSensor(0x3285,0x14);//,LSARGR[7:0];
	CamWriteCmosSensor(0x3286,0x14);//,LSARGB[7:0];
	CamWriteCmosSensor(0x3287,0x1E);//,LSARR[7:0];
	CamWriteCmosSensor(0x3288,0x1E);//,LSARB[7:0];
	CamWriteCmosSensor(0x3289,0x14);//,LSAUGR[7:0];
	CamWriteCmosSensor(0x328A,0x14);//,LSAUGB[7:0];
	CamWriteCmosSensor(0x328B,0x1E);//,LSAUR[7:0];
	CamWriteCmosSensor(0x328C,0x1E);//,LSAUB[7:0];
	CamWriteCmosSensor(0x328D,0x1E);//,LSADGR[7:0];
	CamWriteCmosSensor(0x328E,0x1E);//,LSADGB[7:0];
	CamWriteCmosSensor(0x328F,0x28);//,LSADR[7:0];
	CamWriteCmosSensor(0x3290,0x25);//,LSADB[7:0];
	CamWriteCmosSensor(0x3291,0x46);//,LSBLGR[7:0];
	CamWriteCmosSensor(0x3292,0x46);//,LSBLGB[7:0];
	CamWriteCmosSensor(0x3293,0x6E);//,LSBLR[7:0];
	CamWriteCmosSensor(0x3294,0x3C);//,LSBLB[7:0];
	CamWriteCmosSensor(0x3295,0x46);//,LSBRGR[7:0];
	CamWriteCmosSensor(0x3296,0x46);//,LSBRGB[7:0];
	CamWriteCmosSensor(0x3297,0x5A);//,LSBRR[7:0];
	CamWriteCmosSensor(0x3298,0x32);//,LSBRB[7:0];
	CamWriteCmosSensor(0x3299,0x28);//,LSCUGR[7:0];
	CamWriteCmosSensor(0x329A,0x28);//,LSCUGB[7:0];
	CamWriteCmosSensor(0x329B,0x46);//,LSCUR[7:0];
	CamWriteCmosSensor(0x329C,0x28);//,LSCUB[7:0];
	CamWriteCmosSensor(0x329D,0x28);//,LSCDGR[7:0];
	CamWriteCmosSensor(0x329E,0x28);//,LSCDGB[7:0];
	CamWriteCmosSensor(0x329F,0x32);//,LSCDR[7:0];
	CamWriteCmosSensor(0x32A0,0x14);//,LSCDB[7:0];
	CamWriteCmosSensor(0x32A1,0x00);//,LSDLGR[7:0];
	CamWriteCmosSensor(0x32A2,0x00);//,LSDLGB[7:0];
	CamWriteCmosSensor(0x32A3,0x00);//,LSDLR[7:0];
	CamWriteCmosSensor(0x32A4,0x00);//,LSDLB[7:0];
	CamWriteCmosSensor(0x32A5,0x00);//,LSDRGR[7:0];
	CamWriteCmosSensor(0x32A6,0x00);//,LSDRGB[7:0];
	CamWriteCmosSensor(0x32A7,0x00);//,LSDRR[7:0];
	CamWriteCmosSensor(0x32A8,0x00);//,LSDRB[7:0];
	CamWriteCmosSensor(0x32A9,0x00);//,LSEUGR[7:0];
	CamWriteCmosSensor(0x32AA,0x00);//,LSEUGB[7:0];
	CamWriteCmosSensor(0x32AB,0x00);//,LSEUR[7:0];
	CamWriteCmosSensor(0x32AC,0x00);//,LSEUB[7:0];
	CamWriteCmosSensor(0x32AD,0x00);//,LSEDGR[7:0];
	CamWriteCmosSensor(0x32AE,0x00);//,LSEDGB[7:0];
	CamWriteCmosSensor(0x32AF,0x00);//,LSEDR[7:0];
	CamWriteCmosSensor(0x32B0,0x31);//,LSEDB[7:0];
	CamWriteCmosSensor(0x32B1,0x00);//,HNCAMP[2:0]/ HNCDET /(3)/ (2)/ (1)/ (0);
	CamWriteCmosSensor(0x32B2,0x00);//,HNCLIM0[3:0]/ HNCLIM1[3:0];
	CamWriteCmosSensor(0x32B3,0x00);//,PPRO_SPARE[7:0];
	CamWriteCmosSensor(0x32B4,0x55);//,NOISEMP0[3:0]/ NOISEMP1[3:0];
	CamWriteCmosSensor(0x32B5,0x55);//,EDMP0[3:0]/ EDMP1[3:0];
	CamWriteCmosSensor(0x32B6,0xDD);//,FLNZMP[3:0]/ GAINMP[3:0];
	CamWriteCmosSensor(0x32B7,0xFF);//,ANAGMAX[7:0];
	CamWriteCmosSensor(0x32B8,0x00);//,ANAGMIN[7:0];
	CamWriteCmosSensor(0xFFFF,0xFF);//,**********WAIT***********
	CamWriteCmosSensor(0x32C0,0x80);//,PHYPWRON/(6)/TXOUT_MODE[1:0]/(3)/CLK_DELAY[2:0];
	CamWriteCmosSensor(0x32C1,0x66);//,(7) / DA1_DELAY[2:0] / (3) / DA2_DELAY[2:0];
	CamWriteCmosSensor(0x32C2,0x84);//,REGVD_SEL[1:0]/ (5)/ (4)/ DLREN_SEL/ MIPI1L / AUTO_R_SEL/ LPFR_SEL;
	CamWriteCmosSensor(0x32C3,0x44);//,HS_SR_CNT/ LP_SR_CNT/ LB_LANE_SEL/ DEBUG_ON/ (3)/ PHASE_ADJUST[2:0;
	CamWriteCmosSensor(0x32C4,0x03);//,(7)/(6)/(5)/(4)/(3)/(2)/ PARALLEL_OUT_SW[1:0];
	CamWriteCmosSensor(0x32C5,0x78);//,ESCDATA[7:0];
	CamWriteCmosSensor(0x32C6,0x25);//,TLPXPRD[3:0]/ CLKPREPRD[3:0];
	CamWriteCmosSensor(0x32C7,0x55);//,CLKTRIPRD[3:0]/ HSPREPRD[3:0];
	CamWriteCmosSensor(0x32C8,0x56);//,HS0PRD[3:0]/ HSTRLPRD[3:0];
	CamWriteCmosSensor(0x32C9,0xA7);//,NUMWAKE[7:0];
	CamWriteCmosSensor(0x32CA,0x00);//,HFCORROFF/ CLKUPLS / ESCREQ / FNUMRST / CLKMODE/ PARALLEL_MODE / F;
	CamWriteCmosSensor(0x32CB,0x00);//,FIFODLY[7:0];
	CamWriteCmosSensor(0x32CC,0x11);//,FS_CODE[7:0];
	CamWriteCmosSensor(0x32CD,0x44);//,FE_CODE[7:0];
	CamWriteCmosSensor(0x32CE,0x22);//,LS_CODE[7:0];
	CamWriteCmosSensor(0x32CF,0x33);//,LE_CODE[7:0];
	CamWriteCmosSensor(0xFFFF,0xFF);//,**********WAIT***********
	CamWriteCmosSensor(0x32D0,0x30);//,ESYNC_SW/ ESYNC_SET/ VSYNC_PH/ HSYNC_PH/ (3)/ (2)/ HCTR_STOP/VCTR_;
	CamWriteCmosSensor(0x32D1,0x00);//,VPSET[15:8];
	CamWriteCmosSensor(0x32D2,0x01);//,VPSET[7:0];
	CamWriteCmosSensor(0x32D3,0x00);//,(7)/ (6)/ HPSET[13:8];
	CamWriteCmosSensor(0x32D4,0x00);//,HPSET[7:0];
	CamWriteCmosSensor(0x32D5,0x00);//,LATCH_TEST[1:0],,DAC_TEST,GAIN_TEST,AG_TEST/ (2)/ (1)/ (0);
	CamWriteCmosSensor(0x32D6,0x00);//,DACT_INT[7:0];
	CamWriteCmosSensor(0x32D7,0x10);//,DACT_STEP[3:0]/ (3)/ (2)/ DACT_SWD[1:0];
	CamWriteCmosSensor(0x32D8,0xFF);//,DACS_MAX[7:0];
	CamWriteCmosSensor(0x32D9,0x00);//,DACS_INT[7:0];
	CamWriteCmosSensor(0x32DA,0x10);//,DACS_STEP[3:0](3)/ (2)/ DACS_SWD[1:0];
	CamWriteCmosSensor(0x32DB,0xFF);//,DACS_MAX[7:0];
	CamWriteCmosSensor(0x32DC,0x81);//,OADJON_SW/ OADJ_ON/ OADJ_SET/ EXT_OFS_ON/ EXT_DACPARA[11:8];
	CamWriteCmosSensor(0x32DD,0x00);//,EXT_DACPARA[7:0];
	CamWriteCmosSensor(0x32DE,0x00);//,SIGIN_ON/ ROREAD_OFF/ RSTDRAIN_HI/ DRCUT_HI/ DRCUT_OFF/ IDLOFF_OFF;
	CamWriteCmosSensor(0x32DF,0x00);//,ESREAD_1OFF/ ESREAD_2OFF/ ESRST_1OFF/ ESRST_2OFF/ RORST_1OFF/ RORS;
	CamWriteCmosSensor(0x32E0,0x01);//,DRESET_OFF/ FTLSNS_1OFF/ (5)/ SADR_1OFF/ (3)/ RST_1OFF/ (1)/ BOOST;
	CamWriteCmosSensor(0x32E1,0x00);//,S1_1OFF/ S1_2OFF/ S3_OFF/ S4_OFF/ INTEN_1OFF/ INTRS_1OFF/ INTEN_2O;
	CamWriteCmosSensor(0x32E2,0x00);//,FBC_PARAM[1:0]/ (5)/ (4)/ (3)/ (2)/ (1)/ (0);
	CamWriteCmosSensor(0x32E3,0x00);//,(7)/ OBAVE[6:0];
	CamWriteCmosSensor(0x32E4,0x00);//,(7)/ (6)/ (5)/ (4)/ OFFSET_ST[11:8],;
	CamWriteCmosSensor(0x32E5,0x00);//,OFFSET_ST[7:0];
	CamWriteCmosSensor(0x32E6,0x00);//,(7)/ (6)/ PSCLAMP_ST[13:8];
	CamWriteCmosSensor(0x32E7,0x00);//,PSCLAMP_ST[7:0];
	CamWriteCmosSensor(0x32E8,0x00);//,(7)/ (6)/ CLAMP_ST[13:8];
	CamWriteCmosSensor(0x32E9,0x00);//,CLAMP_ST[7:0];
	CamWriteCmosSensor(0x32F0,0x90);//,BIAS_SEL/ BSTREADEV/ RSTVDSEL/ READVDSEL/ SYSCLKOFF/ PLLCNTL[2:0];
	CamWriteCmosSensor(0x32F1,0x00);//,ANAMON1_SEL[3:0]/ TEST_PHY1/ TEST_PHY2/ ANAMON0_SEL[1:0];
	CamWriteCmosSensor(0x32F2,0x55);//,PCMODE/ ICP_PCH/ ICP_NCH/ VCO_STP_X/ TXEV_SEL/ RST_DIV_X/ (1)/ TCO;
	CamWriteCmosSensor(0x32F3,0x00);//,VALUE1[7:0;
	CamWriteCmosSensor(0x32F4,0x00);//,VALUE2[7:0];
	CamWriteCmosSensor(0x32F5,0x00);//,HOB_DUMMY/ V_FULL_MODE/ VREG_TEST[1:0]/ TEST_LVDS[3:0];
	CamWriteCmosSensor(0x32F6,0x80);//,I2C_DRVDN/ (6)/ (5)/ T_OUTSEL[4:0];
	CamWriteCmosSensor(0x32F7,0x80);//,T_TMOSEL[3:0]/ DCLK_POL/ (2)/ (1)/ VCO_ON;
	CamWriteCmosSensor(0x0000,0x00);//,***************WAIT********************
	CamWriteCmosSensor(0x3400,0x00);//,(7)/(6)/(5)/(4)/(3)/GLBRST_POL/MSHUTTER_POL/STROBE_POL;
	CamWriteCmosSensor(0x3401,0x00);//,(7)/(6)/(5)/(4)/(3)/GLBRST_SW/GLBRST_H_REG/GLBRST_SEL;
	CamWriteCmosSensor(0x3402,0x00);//,GLBRST_WIDTH_A[7:0];
	CamWriteCmosSensor(0x3403,0x02);//,(7)/(6)/(5)/(4)/GLBRST_WIDTH_B[3:0];
	CamWriteCmosSensor(0x3404,0x10);//,GLBRST_WIDTH_C[7:0];
	CamWriteCmosSensor(0x3405,0x02);//,GLBRST_WIDTH_D[7:0];
	CamWriteCmosSensor(0x3406,0x00);//,(7)/(6)/(5)/(4)/GLBRST_WIDTH_F[11:8];
	CamWriteCmosSensor(0x3407,0x10);//,GLBRST_WIDTH_F[7:0];
	CamWriteCmosSensor(0x3408,0x05);//,GLBRST_WIDTH_H[7:0];
	CamWriteCmosSensor(0x3409,0x04);//,GLBRST_WIDTH_J[7:0];
	CamWriteCmosSensor(0x340A,0x00);//,(7)/(6)/(5)/(4)/(3)/(2)/(1)/MSHUTTER_DLY[8];
	CamWriteCmosSensor(0x340B,0x00);//,MSHUTTER_DLY[7:0];
	CamWriteCmosSensor(0x340C,0x04);//,STROBE_RDLY[7:0];
	CamWriteCmosSensor(0x340D,0x04);//,STROBE_FDLY[7:0];
	CamWriteCmosSensor(0x3410,0x2D);//,(7)/GLBREAD_1W[6:0];
	CamWriteCmosSensor(0x3411,0x33);//,(7)/GLBREAD_1D[6:0];
	CamWriteCmosSensor(0x3412,0x20);//,(7)/GLBREAD_2W[6:0];
	CamWriteCmosSensor(0x3413,0x78);//,(7)/GLBREAD_2D[6:0];
	CamWriteCmosSensor(0x3414,0x4E);//,(7)/GLBTGRESET_W[6:0];
	CamWriteCmosSensor(0x3415,0x00);//,(7)/(6)/(5)/(4)/(3)/(2)/GLBMDCHG_0SET/GLBHREGCK_OFF;
	CamWriteCmosSensor(0x3420,0x70);//,B_TPH_OFFSET[7:0];
	CamWriteCmosSensor(0x3421,0x00);//,(7)/(6)/(5)/(4)/(3)/(2)/(1)/TPAT_NOISE_EN;
	CamWriteCmosSensor(0x3422,0x00);//,(7)/(6)/(5)/(4)/(3)/(2)/DIN_SW[1:0];
	CamWriteCmosSensor(0x3423,0x00);//,B_DIN_ADD[7:0];
	CamWriteCmosSensor(0x3424,0x07);//,(7)/(6)/(5)/(4)/(3)/DH_OUT_SW/DL_OUT_SW/D_NOISE_SW;
	CamWriteCmosSensor(0x3425,0x00);//,(7)/(6)/TPG_VLN2_SW/TPG_VLN_SW/TPBP_SW/TPG_RN_SW/D_DANSA_SW/TPG_HL;
	CamWriteCmosSensor(0x3426,0x00);//,(7)/TPBP_PIX[2:0]/(3)/(2)/VLN_MP[1:0];
	CamWriteCmosSensor(0x3427,0x30);//,B_RN_MP[7:0];
	CamWriteCmosSensor(0x3428,0x30);//,B_HLN_MP[7:0];
	CamWriteCmosSensor(0x3429,0x30);//,B_RDIN[7:0];
	CamWriteCmosSensor(0x342A,0x80);//,B_B_DANSA[7:0];
	CamWriteCmosSensor(0x342B,0x80);//,B_GB_DANSA[7:0];
	CamWriteCmosSensor(0x342C,0x80);//,B_GR_DANSA[7:0];
	CamWriteCmosSensor(0x342D,0x80);//,B_R_DANSA[7:0];

	CamWriteCmosSensor(0x0000,0x00);//*************************WAIT**************************               
	CamWriteCmosSensor(0xA700,0x00);//(7)/(6)/(5)/(4)/(3)/(2)/DAC_CODE[9:8];                                
	CamWriteCmosSensor(0xA701,0x00);//DAC_CODE[7:0];                                                        
	CamWriteCmosSensor(0xA702,0x26);//(7)/(6)/MODE[1:0]/(3)/STEP[2:0];                                      
	CamWriteCmosSensor(0xA703,0x00);//SRST/(6)/(5)/(4)/(3)/(2)/(1)/(0);                                     
	CamWriteCmosSensor(0xA704,0x00);//T_DAC_FAST/(6)/T_AMP_FAST/(4)/BGR_TST/(2)/DC_TST/(1);                 
	CamWriteCmosSensor(0xA705,0x00);//(7)/(6)/(5)/(4)/(3)/(2)/(1)/DACOUT_P_TST;                             
	CamWriteCmosSensor(0xA706,0x00);//--;                                                                   
	CamWriteCmosSensor(0xA707,0x03);//(7)/(6)/(5)/(4)/(3)/(2)/VCMCK_DIV[1:0];                               
	CamWriteCmosSensor(0xA708,0x00);//--;                                                                   
	CamWriteCmosSensor(0xA709,0x00);//(7)/(6)/(5)/(4)/(3)/(2)/(1)/PD_X;                                     
	CamWriteCmosSensor(0xA70A,0x00);//(7)/(6)/TEST_RSW/ADCCNT[4:0];                                         
	CamWriteCmosSensor(0xA70B,0x00);//(7)/(6)/(5)/(4)/(3)/(2)/ADCOUT[9:8];

#ifdef __ET8EV3_MIPI_DBG__	
	kal_wap_trace(MOD_ENG,TRACE_INFO,"danbo Test Exit  ET8EV3MiPiInitialSetting \n:");
#endif
}

/*****************************************************************************
//danbo Note:
//Note Size: 1270* 950
//FAE Setting :Frame Rate  29.9fps (RAW8) , PCLK 66MHZ
//use FAE Setting  Preview and WebCamera has Shading Block,So add 100 Dummy Piex. Now  Frame Rate  27.9fps (RAW8)
*****************************************************************************/

void ET8EV3MipiSetSXGA_Preview(kal_uint8 RAW_Data_bits)
{
	ET8EV3MipiSensorStatus.PvMode = KAL_TRUE;
	ET8EV3MipiSensorStatus.PvFrameLength = ET8EV3_MIPI_PV_PERIOD_LINE_NUMS;
	ET8EV3MipiSensorStatus.PvLineLength = ET8EV3_MIPI_PV_PERIOD_PIXEL_NUMS;
	ET8EV3MipiSensorStatus.PrvPclk=66; // SPCK on sensor (MHz)


	if(RAW_Data_bits==ET8EV3_MIPI_8BIT_RAW)
	{
		CamWriteCmosSensor(0x0100,0x81);//-/-/-/-/-/ANA_GA_MIN[11:8]; 
	}
	else
	{		
		CamWriteCmosSensor(0x0100,0x80);//-/-/-/-/-/ANA_GA_MIN[11:8]; 
	}
	
	CamWriteCmosSensor(0x0002,0x00);//-/-/-/-/-/ANA_GA_MIN[11:8]; 
	CamWriteCmosSensor(0x0003,0x2C);//ANA_GA_MIN[7:0];								 
	CamWriteCmosSensor(0x0004,0x01);//-/-/-/-/-/ANA_GA_MAX[11:8]; 					 
	CamWriteCmosSensor(0x0005,0x60);//ANA_GA_MAX[7:0];								 
	//CamWriteCmosSensor(0x0200,0x0F);//INTGTIM[15:8];									 
	//CamWriteCmosSensor(0x0201,0xE4);//INTGTIM[7:0];									 
	//CamWriteCmosSensor(0x0202,0x00);//-/-/-/-/ANAGAIN[11:8];							 
	//CamWriteCmosSensor(0x0203,0xFD);//ANAGAIN[7:0];	
	
	CamWriteCmosSensor(0x0300,0x21);//-/PIXCKDIV[2:0]/-/SYSCKDIV[2:0];				 
	CamWriteCmosSensor(0x0301,0x01);//-/-/-/-/-/-/PRECKDIV[1:0];						 
	CamWriteCmosSensor(0x0302,0x01);//-/-/-/-/-/OPSYSDIV[2:0];						 
	CamWriteCmosSensor(0x0303,0x00);//-/-/-/-/-/-/-/PLLMULT[8];						 
	CamWriteCmosSensor(0x0304,0x42);//PLLMULT[7:0];	
	
	CamWriteCmosSensor(0x0305,0x03);//TTLINE[15:8];									 
	CamWriteCmosSensor(0x0306,0xFC);//TTLINE[7:0];
	CamWriteCmosSensor(0x0307,0x08);//TTLDOT[15:8];									 
	CamWriteCmosSensor(0x0308,0xA2);//TTLDOT[7:0];	
	
	CamWriteCmosSensor(0x030D,0x00);//-/-/-/-/HOUT_STADR[11:8];						 
	CamWriteCmosSensor(0x030E,0x0C);//HOUT_STADR[7:0];	
	CamWriteCmosSensor(0x030F,0x00);//-/-/-/-/VOUT_STADR[11:8];						 
	CamWriteCmosSensor(0x0310,0x0A);//VOUT_STADR[7:0];
	
	CamWriteCmosSensor(0x0311,0x05);//-/-/-/-/HOUTSIZ[11:8];							 
	CamWriteCmosSensor(0x0312,0x00);//HOUTSIZ[7:0];									 
	CamWriteCmosSensor(0x0313,0x03);//-/-/-/-/VOUTSIZ[11:8];							 
	CamWriteCmosSensor(0x0314,0xC0);//VOUTSIZ[7:0];	
	
	CamWriteCmosSensor(0x0315,0x81);//HANABIN/-/-/-/-/-/VMON[1:0];					 
	CamWriteCmosSensor(0x0400,0x00);///-/-/-/-/-/-/-/HSCALE;	
	CamWriteCmosSensor(0x0600,0x02);//TPAT_SEL[2:0]/(4)/(3)/(2)/ TPAT_R[9:8]; 
	
	CamWriteCmosSensor(0x32C6,0x26);//TLPXPRD[3:0]/ CLKPREPRD[3:0];					 
	CamWriteCmosSensor(0x32C7,0x65);//CLKTRIPRD[3:0]/ HSPREPRD[3:0];					 
	CamWriteCmosSensor(0x32C8,0x56);//HS0PRD[3:0]/ HSTRLPRD[3:0];
}

/*****************************************************************************
//danbo Note:
//Note Size: 1270* 710
//FAE Setting :Frame Rate  29.9fps (RAW8) , PCLK 66MHZ
//use FAE Setting  Preview and WebCamera has Shading Block,So add 100 Dummy Piex. Now  Frame Rate  27.9fps (RAW8)
*****************************************************************************/

void ET8EV3MipiSetXGA_720P(kal_uint8 RAW_Data_bits)
{
	ET8EV3MipiSensorStatus.PvMode = KAL_TRUE;
	ET8EV3MipiSensorStatus.PvFrameLength = ET8EV3_MIPI_PV_PERIOD_LINE_NUMS;
	ET8EV3MipiSensorStatus.PvLineLength = ET8EV3_MIPI_PV_PERIOD_PIXEL_NUMS;
	ET8EV3MipiSensorStatus.PrvPclk=66; // SPCK on sensor (MHz)


	if(RAW_Data_bits==ET8EV3_MIPI_8BIT_RAW)
	{
		CamWriteCmosSensor(0x0100,0x81);//-/-/-/-/-/ANA_GA_MIN[11:8]; 
	}
	else
	{		
		CamWriteCmosSensor(0x0100,0x80);//-/-/-/-/-/ANA_GA_MIN[11:8]; 
	}
	
	CamWriteCmosSensor(0x0002,0x00);//-/-/-/-/-/ANA_GA_MIN[11:8]; 
	CamWriteCmosSensor(0x0003,0x2C);//ANA_GA_MIN[7:0];								 
	CamWriteCmosSensor(0x0004,0x01);//-/-/-/-/-/ANA_GA_MAX[11:8]; 					 
	CamWriteCmosSensor(0x0005,0x60);//ANA_GA_MAX[7:0];								 
	//CamWriteCmosSensor(0x0200,0x0F);//INTGTIM[15:8];									 
	//CamWriteCmosSensor(0x0201,0xE4);//INTGTIM[7:0];									 
	//CamWriteCmosSensor(0x0202,0x00);//-/-/-/-/ANAGAIN[11:8];							 
	//CamWriteCmosSensor(0x0203,0xFD);//ANAGAIN[7:0];	
	
	CamWriteCmosSensor(0x0300,0x21);//-/PIXCKDIV[2:0]/-/SYSCKDIV[2:0];				 
	CamWriteCmosSensor(0x0301,0x01);//-/-/-/-/-/-/PRECKDIV[1:0];						 
	CamWriteCmosSensor(0x0302,0x01);//-/-/-/-/-/OPSYSDIV[2:0];						 
	CamWriteCmosSensor(0x0303,0x00);//-/-/-/-/-/-/-/PLLMULT[8];						 
	CamWriteCmosSensor(0x0304,0x42);//PLLMULT[7:0];	
	
	CamWriteCmosSensor(0x0305,0x03);//TTLINE[15:8];									 
	CamWriteCmosSensor(0x0306,0xFC);//TTLINE[7:0];
	CamWriteCmosSensor(0x0307,0x08);//TTLDOT[15:8];									 
	CamWriteCmosSensor(0x0308,0x98);//TTLDOT[7:0];	
	
	CamWriteCmosSensor(0x030D,0x00);//-/-/-/-/HOUT_STADR[11:8];						 
	CamWriteCmosSensor(0x030E,0x04);//HOUT_STADR[7:0];	
	CamWriteCmosSensor(0x030F,0x00);//-/-/-/-/VOUT_STADR[11:8];						 
	CamWriteCmosSensor(0x0310,0x82);//VOUT_STADR[7:0];
	
	CamWriteCmosSensor(0x0311,0x05);//-/-/-/-/HOUTSIZ[11:8];							 
	CamWriteCmosSensor(0x0312,0x00);//HOUTSIZ[7:0];									 
	CamWriteCmosSensor(0x0313,0x02);//-/-/-/-/VOUTSIZ[11:8];							 
	CamWriteCmosSensor(0x0314,0xD0);//VOUTSIZ[7:0];	
	
	CamWriteCmosSensor(0x0315,0x81);//HANABIN/-/-/-/-/-/VMON[1:0];					 
	CamWriteCmosSensor(0x0400,0x00);///-/-/-/-/-/-/-/HSCALE;	
	CamWriteCmosSensor(0x0600,0x02);//TPAT_SEL[2:0]/(4)/(3)/(2)/ TPAT_R[9:8]; 
	
	CamWriteCmosSensor(0x32C6,0x26);//TLPXPRD[3:0]/ CLKPREPRD[3:0];					 
	CamWriteCmosSensor(0x32C7,0x65);//CLKTRIPRD[3:0]/ HSPREPRD[3:0];					 
	CamWriteCmosSensor(0x32C8,0x56);//HS0PRD[3:0]/ HSTRLPRD[3:0];
}


/*****************************************************************************
//danbo Note:
//Note Size: 632* 474
//FAE Setting :Frame Rate  29.9fps (RAW8) , PCLK 66MHZ
//use FAE Setting  Preview and WebCamera has Shading Block,So add 100 Dummy Piex. Now  Frame Rate  27.9fps (RAW8)
*****************************************************************************/
void ET8EV3MipiSetXGA_VGA(kal_uint8 RAW_Data_bits)
{
	ET8EV3MipiSensorStatus.PvMode = KAL_TRUE;
	ET8EV3MipiSensorStatus.PvFrameLength = ET8EV3_MIPI_PV_PERIOD_LINE_NUMS;
	ET8EV3MipiSensorStatus.PvLineLength = ET8EV3_MIPI_PV_PERIOD_PIXEL_NUMS;
	ET8EV3MipiSensorStatus.PrvPclk=66; // SPCK on sensor (MHz)


	if(RAW_Data_bits==ET8EV3_MIPI_8BIT_RAW)
	{
		CamWriteCmosSensor(0x0100,0x81);//-/-/-/-/-/ANA_GA_MIN[11:8]; 
	}
	else
	{		
		CamWriteCmosSensor(0x0100,0x80);//-/-/-/-/-/ANA_GA_MIN[11:8]; 
	}
	CamWriteCmosSensor(0x0002,0x00);//-/-/-/-/-/ANA_GA_MIN[11:8]; 					 
	CamWriteCmosSensor(0x0003,0x2C);//ANA_GA_MIN[7:0];								 
	CamWriteCmosSensor(0x0004,0x01);//-/-/-/-/-/ANA_GA_MAX[11:8]; 					 
	CamWriteCmosSensor(0x0005,0x60);//ANA_GA_MAX[7:0];								 
	//CamWriteCmosSensor(0x0200,0x03);//INTGTIM[15:8];									 
	//CamWriteCmosSensor(0x0201,0xE4);//INTGTIM[7:0];									 
	//CamWriteCmosSensor(0x0202,0x00);//-/-/-/-/ANAGAIN[11:8];							 
	//CamWriteCmosSensor(0x0203,0x1D);//ANAGAIN[7:0];	
	
	CamWriteCmosSensor(0x0300,0x02);//-/PIXCKDIV[2:0]/-/SYSCKDIV[2:0];				 
	CamWriteCmosSensor(0x0301,0x01);//-/-/-/-/-/-/PRECKDIV[1:0];						 
	CamWriteCmosSensor(0x0302,0x01);//-/-/-/-/-/OPSYSDIV[2:0];						 
	CamWriteCmosSensor(0x0303,0x00);//-/-/-/-/-/-/-/PLLMULT[8];						 
	CamWriteCmosSensor(0x0304,0x42);//PLLMULT[7:0];		
	
	CamWriteCmosSensor(0x0305,0x02);//TTLINE[15:8];									 
	CamWriteCmosSensor(0x0306,0x04);//TTLINE[7:0];
	CamWriteCmosSensor(0x0307,0x0C);//TTLDOT[15:8];									 
	CamWriteCmosSensor(0x0308,0xEE);//TTLDOT[7:0];	
	
	CamWriteCmosSensor(0x030D,0x00);//-/-/-/-/HOUT_STADR[11:8];						 
	CamWriteCmosSensor(0x030E,0x06);//HOUT_STADR[7:0];	
	CamWriteCmosSensor(0x030F,0x00);//-/-/-/-/VOUT_STADR[11:8];						 
	CamWriteCmosSensor(0x0310,0x04);//VOUT_STADR[7:0];		
	
	CamWriteCmosSensor(0x0311,0x02);//-/-/-/-/HOUTSIZ[11:8];							 
	CamWriteCmosSensor(0x0312,0x80);//HOUTSIZ[7:0];									 
	CamWriteCmosSensor(0x0313,0x01);//-/-/-/-/VOUTSIZ[11:8];							 
	CamWriteCmosSensor(0x0314,0xE0);//VOUTSIZ[7:0];		
	
	CamWriteCmosSensor(0x0315,0x83);//HANABIN/-/-/-/-/-/VMON[1:0];					 
	CamWriteCmosSensor(0x0400,0x01);///-/-/-/-/-/-/-/HSCALE;	
	CamWriteCmosSensor(0x0600,0x02);//TPAT_SEL[2:0]/(4)/(3)/(2)/ TPAT_R[9:8]; 
	
	CamWriteCmosSensor(0x32C6,0x25);//TLPXPRD[3:0]/ CLKPREPRD[3:0];					 
	CamWriteCmosSensor(0x32C7,0x55);//CLKTRIPRD[3:0]/ HSPREPRD[3:0];					 
	CamWriteCmosSensor(0x32C8,0x56);//HS0PRD[3:0]/ HSTRLPRD[3:0];
}

/*****************************************************************************
//danbo Note:
//Note Size: 2560* 1920
//FAE Setting :Frame Rate  14.3fps (RAW10) , PCLK 96MHZ
//use FAE Setting  Capture has Shading Block,So add 200 Dummy Piex. Now  Frame Rate  13.5fps (RAW10)
*****************************************************************************/
static void ET8EV3MipiSetQSXGA_14_FPS(kal_uint8 RAW_Data_bits)
{
	ET8EV3MipiSensorStatus.PvMode = KAL_FALSE;
    ET8EV3MipiSensorStatus.CapFrameLength= ET8EV3_MIPI_FULL_PERIOD_LINE_NUMS_12_FPS;
	ET8EV3MipiSensorStatus.CapLineLength= ET8EV3_MIPI_FULL_PERIOD_PIXEL_NUMS_12_FPS;

	ET8EV3MipiSensorStatus.CapPclk=96; // SPCK on sensor (MHz)

	if(RAW_Data_bits==ET8EV3_MIPI_8BIT_RAW)
	{
		CamWriteCmosSensor(0x0100,0x81);//-/-/-/-/-/ANA_GA_MIN[11:8]; 
	}
	else
	{		
		CamWriteCmosSensor(0x0100,0x80);//-/-/-/-/-/ANA_GA_MIN[11:8]; 
	}
	CamWriteCmosSensor(0x0100,0x80);//MODE_SEL/VREVON/HREVON/SWRST/GRHOLD/-/-/OUT_FORMAT;
	CamWriteCmosSensor(0x0002,0x00);//-/-/-/-/-/ANA_GA_MIN[11:8]; 					 
	CamWriteCmosSensor(0x0003,0x1D);//ANA_GA_MIN[7:0];								 
	CamWriteCmosSensor(0x0004,0x01);//-/-/-/-/-/ANA_GA_MAX[11:8]; 					 
	CamWriteCmosSensor(0x0005,0x60);//ANA_GA_MAX[7:0];								 
	//CamWriteCmosSensor(0x0200,0x05);//INTGTIM[15:8];									 
	//CamWriteCmosSensor(0x0201,0x00);//INTGTIM[7:0];									 
	//CamWriteCmosSensor(0x0202,0x00);//-/-/-/-/ANAGAIN[11:8];							 
	//CamWriteCmosSensor(0x0203,0x1D);//ANAGAIN[7:0];	
	
	CamWriteCmosSensor(0x0300,0x01);//-/PIXCKDIV[2:0]/-/SYSCKDIV[2:0];				 
	CamWriteCmosSensor(0x0301,0x01);//-/-/-/-/-/-/PRECKDIV[1:0];						 
	CamWriteCmosSensor(0x0302,0x00);//-/-/-/-/-/OPSYSDIV[2:0];						 
	CamWriteCmosSensor(0x0303,0x00);//-/-/-/-/-/-/-/PLLMULT[8];						 

	CamWriteCmosSensor(0x0304,0x40);//PLLMULT[7:0];									 
	CamWriteCmosSensor(0x0305,0x07);//TTLINE[15:8];									 
	CamWriteCmosSensor(0x0306,0xDC);//TTLINE[7:0];									 
	CamWriteCmosSensor(0x0307,0x0D);//TTLDOT[15:8];									 
	CamWriteCmosSensor(0x0308,0x48);//TTLDOT[7:0];	

	CamWriteCmosSensor(0x030D,0x00);//-/-/-/-/HOUT_STADR[11:8];						 
	CamWriteCmosSensor(0x030E,0x00);//HOUT_STADR[7:0];								 
	CamWriteCmosSensor(0x030F,0x00);//-/-/-/-/VOUT_STADR[11:8];						 
	CamWriteCmosSensor(0x0310,0x00);//VOUT_STADR[7:0];								 
	CamWriteCmosSensor(0x0311,0x0A);//-/-/-/-/HOUTSIZ[11:8];							 
	CamWriteCmosSensor(0x0312,0x30);//HOUTSIZ[7:0];									 
	CamWriteCmosSensor(0x0313,0x07);//-/-/-/-/VOUTSIZ[11:8];							 
	CamWriteCmosSensor(0x0314,0xA8);//VOUTSIZ[7:0];									 
	CamWriteCmosSensor(0x0315,0x00);//HANABIN/-/-/-/-/-/VMON[1:0];					 
	CamWriteCmosSensor(0x0400,0x00);///-/-/-/-/-/-/-/HSCALE;							 
	CamWriteCmosSensor(0x0600,0x02);//TPAT_SEL[2:0]/(4)/(3)/(2)/ TPAT_R[9:8]; 		 
	CamWriteCmosSensor(0x32C6,0x48);//TLPXPRD[3:0]/ CLKPREPRD[3:0];					 
	CamWriteCmosSensor(0x32C7,0x86);//CLKTRIPRD[3:0]/ HSPREPRD[3:0];					 
	CamWriteCmosSensor(0x32C8,0x88);//HS0PRD[3:0]/ HSTRLPRD[3:0]; 		
	
}


/*****************************************************************************
//danbo Note:
//Note Size: 2560* 1920
//FAE Setting :Frame Rate  12fps (RAW10) , PCLK 80MHZ
//use FAE Setting  Capture has Shading Block,So add 200 Dummy Piex. Now  Frame Rate  10.9fps (RAW10)
*****************************************************************************/
static void ET8EV3MipiSetQSXGA_12_FPS(kal_uint8 RAW_Data_bits)
{
	ET8EV3MipiSensorStatus.PvMode = KAL_FALSE;
    ET8EV3MipiSensorStatus.CapFrameLength= ET8EV3_MIPI_FULL_PERIOD_LINE_NUMS_12_FPS;
	ET8EV3MipiSensorStatus.CapLineLength= ET8EV3_MIPI_FULL_PERIOD_PIXEL_NUMS_12_FPS;

	ET8EV3MipiSensorStatus.CapPclk=80; // SPCK on sensor (MHz)

	if(RAW_Data_bits==ET8EV3_MIPI_8BIT_RAW)
	{
		CamWriteCmosSensor(0x0100,0x81);//-/-/-/-/-/ANA_GA_MIN[11:8]; 
	}
	else
	{		
		CamWriteCmosSensor(0x0100,0x80);//-/-/-/-/-/ANA_GA_MIN[11:8]; 
	}
	CamWriteCmosSensor(0x0100,0x80);//MODE_SEL/VREVON/HREVON/SWRST/GRHOLD/-/-/OUT_FORMAT;
	CamWriteCmosSensor(0x0002,0x00);//-/-/-/-/-/ANA_GA_MIN[11:8]; 					 
	CamWriteCmosSensor(0x0003,0x1D);//ANA_GA_MIN[7:0];								 
	CamWriteCmosSensor(0x0004,0x01);//-/-/-/-/-/ANA_GA_MAX[11:8]; 					 
	CamWriteCmosSensor(0x0005,0x60);//ANA_GA_MAX[7:0];								 
	//CamWriteCmosSensor(0x0200,0x05);//INTGTIM[15:8];									 
	//CamWriteCmosSensor(0x0201,0x00);//INTGTIM[7:0];									 
	//CamWriteCmosSensor(0x0202,0x00);//-/-/-/-/ANAGAIN[11:8];							 
	//CamWriteCmosSensor(0x0203,0x1D);//ANAGAIN[7:0];	
	
	CamWriteCmosSensor(0x0300,0x01);//-/PIXCKDIV[2:0]/-/SYSCKDIV[2:0];				 
	CamWriteCmosSensor(0x0301,0x01);//-/-/-/-/-/-/PRECKDIV[1:0];						 
	CamWriteCmosSensor(0x0302,0x00);//-/-/-/-/-/OPSYSDIV[2:0];						 
	CamWriteCmosSensor(0x0303,0x00);//-/-/-/-/-/-/-/PLLMULT[8];						 

	CamWriteCmosSensor(0x0304,0x35);//PLLMULT[7:0];									 
	CamWriteCmosSensor(0x0305,0x07);//TTLINE[15:8];									 
	CamWriteCmosSensor(0x0306,0xDC);//TTLINE[7:0];									 
	CamWriteCmosSensor(0x0307,0x0D);//TTLDOT[15:8];									 
	CamWriteCmosSensor(0x0308,0x48);//TTLDOT[7:0];	

	CamWriteCmosSensor(0x030D,0x00);//-/-/-/-/HOUT_STADR[11:8];						 
	CamWriteCmosSensor(0x030E,0x00);//HOUT_STADR[7:0];								 
	CamWriteCmosSensor(0x030F,0x00);//-/-/-/-/VOUT_STADR[11:8];						 
	CamWriteCmosSensor(0x0310,0x00);//VOUT_STADR[7:0];								 
	CamWriteCmosSensor(0x0311,0x0A);//-/-/-/-/HOUTSIZ[11:8];							 
	CamWriteCmosSensor(0x0312,0x30);//HOUTSIZ[7:0];									 
	CamWriteCmosSensor(0x0313,0x07);//-/-/-/-/VOUTSIZ[11:8];							 
	CamWriteCmosSensor(0x0314,0xA8);//VOUTSIZ[7:0];									 
	CamWriteCmosSensor(0x0315,0x00);//HANABIN/-/-/-/-/-/VMON[1:0];					 
	CamWriteCmosSensor(0x0400,0x00);///-/-/-/-/-/-/-/HSCALE;							 
	CamWriteCmosSensor(0x0600,0x02);//TPAT_SEL[2:0]/(4)/(3)/(2)/ TPAT_R[9:8]; 		 
	CamWriteCmosSensor(0x32C6,0x45);//TLPXPRD[3:0]/ CLKPREPRD[3:0];					 
	CamWriteCmosSensor(0x32C7,0x66);//CLKTRIPRD[3:0]/ HSPREPRD[3:0];					 
	CamWriteCmosSensor(0x32C8,0x75);//HS0PRD[3:0]/ HSTRLPRD[3:0]; 		


	
}

/*****************************************************************************
//danbo Note:
//Note Size: 2560* 1920
//FAE Setting :Frame Rate  10.8ps (RAW10) , PCLK 78MHZ
//use FAE Setting  Capture has Shading Block,So add 200 Dummy Piex. Now  Frame Rate  fps (RAW10)
*****************************************************************************/
static void ET8EV3MipiSetQSXGA_10_8_FPS(kal_uint8 RAW_Data_bits)
{
	ET8EV3MipiSensorStatus.PvMode = KAL_FALSE;
    ET8EV3MipiSensorStatus.CapFrameLength= ET8EV3_MIPI_FULL_PERIOD_LINE_NUMS_10_8_FPS;
	ET8EV3MipiSensorStatus.CapLineLength= ET8EV3_MIPI_FULL_PERIOD_PIXEL_NUMS_10_8_FPS;

	ET8EV3MipiSensorStatus.CapPclk=78; // SPCK on sensor (MHz)

	if(RAW_Data_bits==ET8EV3_MIPI_8BIT_RAW)
	{
		CamWriteCmosSensor(0x0100,0x81);//-/-/-/-/-/ANA_GA_MIN[11:8]; 
	}
	else
	{		
		CamWriteCmosSensor(0x0100,0x80);//-/-/-/-/-/ANA_GA_MIN[11:8]; 
	}
	CamWriteCmosSensor(0x0100,0x80);//MODE_SEL/VREVON/HREVON/SWRST/GRHOLD/-/-/OUT_FORMAT;
	CamWriteCmosSensor(0x0002,0x00);//-/-/-/-/-/ANA_GA_MIN[11:8]; 					 
	CamWriteCmosSensor(0x0003,0x1D);//ANA_GA_MIN[7:0];								 
	CamWriteCmosSensor(0x0004,0x01);//-/-/-/-/-/ANA_GA_MAX[11:8]; 					 
	CamWriteCmosSensor(0x0005,0x60);//ANA_GA_MAX[7:0];								 
	//CamWriteCmosSensor(0x0200,0x05);//INTGTIM[15:8];									 
	//CamWriteCmosSensor(0x0201,0x00);//INTGTIM[7:0];									 
	//CamWriteCmosSensor(0x0202,0x00);//-/-/-/-/ANAGAIN[11:8];							 
	//CamWriteCmosSensor(0x0203,0x1D);//ANAGAIN[7:0];	
	
	CamWriteCmosSensor(0x0300,0x01);//-/PIXCKDIV[2:0]/-/SYSCKDIV[2:0];				 
	CamWriteCmosSensor(0x0301,0x01);//-/-/-/-/-/-/PRECKDIV[1:0];						 
	CamWriteCmosSensor(0x0302,0x00);//-/-/-/-/-/OPSYSDIV[2:0];						 
	CamWriteCmosSensor(0x0303,0x00);//-/-/-/-/-/-/-/PLLMULT[8];						 

	CamWriteCmosSensor(0x0304,0x34);//PLLMULT[7:0]; 								 
	CamWriteCmosSensor(0x0305,0x07);//TTLINE[15:8]; 								 
	CamWriteCmosSensor(0x0306,0xDC);//TTLINE[7:0];									 
	CamWriteCmosSensor(0x0307,0x0D);//TTLDOT[15:8]; 								 
	CamWriteCmosSensor(0x0308,0x48);//TTLDOT[7:0];

	CamWriteCmosSensor(0x030D,0x00);//-/-/-/-/HOUT_STADR[11:8];						 
	CamWriteCmosSensor(0x030E,0x00);//HOUT_STADR[7:0];								 
	CamWriteCmosSensor(0x030F,0x00);//-/-/-/-/VOUT_STADR[11:8];						 
	CamWriteCmosSensor(0x0310,0x00);//VOUT_STADR[7:0];								 
	CamWriteCmosSensor(0x0311,0x0A);//-/-/-/-/HOUTSIZ[11:8];							 
	CamWriteCmosSensor(0x0312,0x30);//HOUTSIZ[7:0];									 
	CamWriteCmosSensor(0x0313,0x07);//-/-/-/-/VOUTSIZ[11:8];							 
	CamWriteCmosSensor(0x0314,0xA8);//VOUTSIZ[7:0];									 
	CamWriteCmosSensor(0x0315,0x00);//HANABIN/-/-/-/-/-/VMON[1:0];					 
	CamWriteCmosSensor(0x0400,0x00);///-/-/-/-/-/-/-/HSCALE;							 
	CamWriteCmosSensor(0x0600,0x02);//TPAT_SEL[2:0]/(4)/(3)/(2)/ TPAT_R[9:8]; 		 
	CamWriteCmosSensor(0x32C6,0x45);//TLPXPRD[3:0]/ CLKPREPRD[3:0];					 
	CamWriteCmosSensor(0x32C7,0x66);//CLKTRIPRD[3:0]/ HSPREPRD[3:0];					 
	CamWriteCmosSensor(0x32C8,0x75);//HS0PRD[3:0]/ HSTRLPRD[3:0]; 		


	
}

/*****************************************************************************
//danbo Note:
//Note Size: 2560* 1920
//FAE Setting :Frame Rate  8fps (RAW10) , PCLK 75MHZ
//use FAE Setting  Capture has Shading Block,So add 200 Dummy Piex. Now  Frame Rate  fps (RAW10)
*****************************************************************************/
static void ET8EV3MipiSetQSXGA_8_FPS(kal_uint8 RAW_Data_bits)
{
	ET8EV3MipiSensorStatus.PvMode = KAL_FALSE;
    ET8EV3MipiSensorStatus.CapFrameLength= ET8EV3_MIPI_FULL_PERIOD_LINE_NUMS_8_FPS;
	ET8EV3MipiSensorStatus.CapLineLength= ET8EV3_MIPI_FULL_PERIOD_PIXEL_NUMS_8_FPS;

	ET8EV3MipiSensorStatus.CapPclk=75; // SPCK on sensor (MHz)

	if(RAW_Data_bits==ET8EV3_MIPI_8BIT_RAW)
	{
		CamWriteCmosSensor(0x0100,0x81);//-/-/-/-/-/ANA_GA_MIN[11:8]; 
	}
	else
	{		
		CamWriteCmosSensor(0x0100,0x80);//-/-/-/-/-/ANA_GA_MIN[11:8]; 
	}
	CamWriteCmosSensor(0x0100,0x80);//MODE_SEL/VREVON/HREVON/SWRST/GRHOLD/-/-/OUT_FORMAT;
	CamWriteCmosSensor(0x0002,0x00);//-/-/-/-/-/ANA_GA_MIN[11:8]; 					 
	CamWriteCmosSensor(0x0003,0x1D);//ANA_GA_MIN[7:0];								 
	CamWriteCmosSensor(0x0004,0x01);//-/-/-/-/-/ANA_GA_MAX[11:8]; 					 
	CamWriteCmosSensor(0x0005,0x60);//ANA_GA_MAX[7:0];								 
	//CamWriteCmosSensor(0x0200,0x05);//INTGTIM[15:8];									 
	//CamWriteCmosSensor(0x0201,0x00);//INTGTIM[7:0];									 
	//CamWriteCmosSensor(0x0202,0x00);//-/-/-/-/ANAGAIN[11:8];							 
	//CamWriteCmosSensor(0x0203,0x1D);//ANAGAIN[7:0];	
	
	CamWriteCmosSensor(0x0300,0x01);//-/PIXCKDIV[2:0]/-/SYSCKDIV[2:0];				 
	CamWriteCmosSensor(0x0301,0x01);//-/-/-/-/-/-/PRECKDIV[1:0];						 
	CamWriteCmosSensor(0x0302,0x00);//-/-/-/-/-/OPSYSDIV[2:0];						 
	CamWriteCmosSensor(0x0303,0x00);//-/-/-/-/-/-/-/PLLMULT[8];						 

	CamWriteCmosSensor(0x0304,0x32);//PLLMULT[7:0]; 								 
	CamWriteCmosSensor(0x0305,0x07);//TTLINE[15:8]; 								 
	CamWriteCmosSensor(0x0306,0xDC);//TTLINE[7:0];									 
	CamWriteCmosSensor(0x0307,0x0D);//TTLDOT[15:8]; 								 
	CamWriteCmosSensor(0x0308,0x48);//TTLDOT[7:0];

	CamWriteCmosSensor(0x030D,0x00);//-/-/-/-/HOUT_STADR[11:8];						 
	CamWriteCmosSensor(0x030E,0x00);//HOUT_STADR[7:0];								 
	CamWriteCmosSensor(0x030F,0x00);//-/-/-/-/VOUT_STADR[11:8];						 
	CamWriteCmosSensor(0x0310,0x00);//VOUT_STADR[7:0];								 
	CamWriteCmosSensor(0x0311,0x0A);//-/-/-/-/HOUTSIZ[11:8];							 
	CamWriteCmosSensor(0x0312,0x30);//HOUTSIZ[7:0];									 
	CamWriteCmosSensor(0x0313,0x07);//-/-/-/-/VOUTSIZ[11:8];							 
	CamWriteCmosSensor(0x0314,0xA8);//VOUTSIZ[7:0];									 
	CamWriteCmosSensor(0x0315,0x00);//HANABIN/-/-/-/-/-/VMON[1:0];					 
	CamWriteCmosSensor(0x0400,0x00);///-/-/-/-/-/-/-/HSCALE;							 
	CamWriteCmosSensor(0x0600,0x02);//TPAT_SEL[2:0]/(4)/(3)/(2)/ TPAT_R[9:8]; 		 
	CamWriteCmosSensor(0x32C6,0x45);//TLPXPRD[3:0]/ CLKPREPRD[3:0];					 
	CamWriteCmosSensor(0x32C7,0x66);//CLKTRIPRD[3:0]/ HSPREPRD[3:0];					 
	CamWriteCmosSensor(0x32C8,0x75);//HS0PRD[3:0]/ HSTRLPRD[3:0]; 		
	
}


static void ET8EV3MipiSetQSXGA_7_5_FPS(kal_uint8 RAW_Data_bits)
{
	ET8EV3MipiSensorStatus.PvMode = KAL_FALSE;
    ET8EV3MipiSensorStatus.CapFrameLength= ET8EV3_MIPI_FULL_PERIOD_PIXEL_NUMS_8_FPS;
	ET8EV3MipiSensorStatus.CapLineLength= ET8EV3_MIPI_FULL_PERIOD_PIXEL_NUMS_8_FPS;
	
	ET8EV3MipiSensorStatus.CapPclk=66; // SPCK on sensor (MHz)

	if(RAW_Data_bits==ET8EV3_MIPI_8BIT_RAW)
	{
		CamWriteCmosSensor(0x0100,0x81);//-/-/-/-/-/ANA_GA_MIN[11:8]; 
	}
	else
	{		
		CamWriteCmosSensor(0x0100,0x80);//-/-/-/-/-/ANA_GA_MIN[11:8]; 
	}
	CamWriteCmosSensor(0x0100,0x80);//MODE_SEL/VREVON/HREVON/SWRST/GRHOLD/-/-/OUT_FORMAT;
	CamWriteCmosSensor(0x0002,0x00);//-/-/-/-/-/ANA_GA_MIN[11:8]; 					 
	CamWriteCmosSensor(0x0003,0x1D);//ANA_GA_MIN[7:0];								 
	CamWriteCmosSensor(0x0004,0x01);//-/-/-/-/-/ANA_GA_MAX[11:8]; 					 
	CamWriteCmosSensor(0x0005,0x60);//ANA_GA_MAX[7:0];								 
	//CamWriteCmosSensor(0x0200,0x05);//INTGTIM[15:8];									 
	//CamWriteCmosSensor(0x0201,0x00);//INTGTIM[7:0];									 
	//CamWriteCmosSensor(0x0202,0x00);//-/-/-/-/ANAGAIN[11:8];							 
	//CamWriteCmosSensor(0x0203,0x1D);//ANAGAIN[7:0];	
	
	CamWriteCmosSensor(0x0300,0x21);//-/PIXCKDIV[2:0]/-/SYSCKDIV[2:0];				 
	CamWriteCmosSensor(0x0301,0x01);//-/-/-/-/-/-/PRECKDIV[1:0];						 
	CamWriteCmosSensor(0x0302,0x01);//-/-/-/-/-/OPSYSDIV[2:0];						 
	CamWriteCmosSensor(0x0303,0x00);//-/-/-/-/-/-/-/PLLMULT[8];						 
	CamWriteCmosSensor(0x0304,0x42);//PLLMULT[7:0];									 
	CamWriteCmosSensor(0x0305,0x07);//TTLINE[15:8];									 
	CamWriteCmosSensor(0x0306,0xDC);//TTLINE[7:0];									 
	CamWriteCmosSensor(0x0307,0x11);//TTLDOT[15:8];									 
	CamWriteCmosSensor(0x0308,0x3A);//TTLDOT[7:0];									 
	CamWriteCmosSensor(0x030D,0x00);//-/-/-/-/HOUT_STADR[11:8];						 
	CamWriteCmosSensor(0x030E,0x00);//HOUT_STADR[7:0];								 
	CamWriteCmosSensor(0x030F,0x00);//-/-/-/-/VOUT_STADR[11:8];						 
	CamWriteCmosSensor(0x0310,0x00);//VOUT_STADR[7:0];								 
	CamWriteCmosSensor(0x0311,0x0A);//-/-/-/-/HOUTSIZ[11:8];							 
	CamWriteCmosSensor(0x0312,0x30);//HOUTSIZ[7:0];									 
	CamWriteCmosSensor(0x0313,0x07);//-/-/-/-/VOUTSIZ[11:8];							 
	CamWriteCmosSensor(0x0314,0xA8);//VOUTSIZ[7:0];									 
	CamWriteCmosSensor(0x0315,0x00);//HANABIN/-/-/-/-/-/VMON[1:0];					 
	CamWriteCmosSensor(0x0400,0x00);///-/-/-/-/-/-/-/HSCALE;							 
	CamWriteCmosSensor(0x0600,0x02);//TPAT_SEL[2:0]/(4)/(3)/(2)/ TPAT_R[9:8]; 		 
	CamWriteCmosSensor(0x32C6,0x25);//TLPXPRD[3:0]/ CLKPREPRD[3:0];					 
	CamWriteCmosSensor(0x32C7,0x55);//CLKTRIPRD[3:0]/ HSPREPRD[3:0];					 
	CamWriteCmosSensor(0x32C8,0x56);//HS0PRD[3:0]/ HSTRLPRD[3:0]; 		


	
}

/*****************************************************************************
//danbo Note:
//Note Size: 2560* 1920
//FAE Setting :Frame Rate  3.5fps (RAW10) , PCLK 26MHZ
*****************************************************************************/

static void ET8EV3MipiSetQSXGA_3_5_FPS(kal_uint8 RAW_Data_bits)
{
	ET8EV3MipiSensorStatus.PvMode = KAL_FALSE;
    ET8EV3MipiSensorStatus.CapFrameLength= ET8EV3_MIPI_FULL_PERIOD_LINE_NUMS_3_5_FPS;
	ET8EV3MipiSensorStatus.CapLineLength= ET8EV3_MIPI_FULL_PERIOD_PIXEL_NUMS_3_5_FPS;

	ET8EV3MipiSensorStatus.CapPclk=26; // SPCK on sensor (MHz)

	if(RAW_Data_bits==ET8EV3_MIPI_8BIT_RAW)
	{
		CamWriteCmosSensor(0x0100,0x81);//-/-/-/-/-/ANA_GA_MIN[11:8]; 
	}
	else
	{		
		CamWriteCmosSensor(0x0100,0x80);//-/-/-/-/-/ANA_GA_MIN[11:8]; 
	}
	CamWriteCmosSensor(0x0100,0x80);//MODE_SEL/VREVON/HREVON/SWRST/GRHOLD/-/-/OUT_FORMAT;
	CamWriteCmosSensor(0x0002,0x00);//-/-/-/-/-/ANA_GA_MIN[11:8]; 					 
	CamWriteCmosSensor(0x0003,0x1D);//ANA_GA_MIN[7:0];								 
	CamWriteCmosSensor(0x0004,0x01);//-/-/-/-/-/ANA_GA_MAX[11:8]; 					 
	CamWriteCmosSensor(0x0005,0x60);//ANA_GA_MAX[7:0];								 
	//CamWriteCmosSensor(0x0200,0x05);//INTGTIM[15:8];									 
	//CamWriteCmosSensor(0x0201,0x00);//INTGTIM[7:0];									 
	//CamWriteCmosSensor(0x0202,0x00);//-/-/-/-/ANAGAIN[11:8];							 
	//CamWriteCmosSensor(0x0203,0x1D);//ANAGAIN[7:0];	
	
	CamWriteCmosSensor(0x0300,0x22);//-/PIXCKDIV[2:0]/-/SYSCKDIV[2:0];				 
	CamWriteCmosSensor(0x0301,0x01);//-/-/-/-/-/-/PRECKDIV[1:0];						 
	CamWriteCmosSensor(0x0302,0x01);//-/-/-/-/-/OPSYSDIV[2:0];						 
	CamWriteCmosSensor(0x0303,0x00);//-/-/-/-/-/-/-/PLLMULT[8];						 

    CamWriteCmosSensor(0x0304,0x34);//PLLMULT[7:0]; 								 
	CamWriteCmosSensor(0x0305,0x07);//TTLINE[15:8]; 								 
	CamWriteCmosSensor(0x0306,0xDC);//TTLINE[7:0];									 
	CamWriteCmosSensor(0x0307,0x0D);//TTLDOT[15:8]; 								 
	CamWriteCmosSensor(0x0308,0x48);//TTLDOT[7:0];

	CamWriteCmosSensor(0x030D,0x00);//-/-/-/-/HOUT_STADR[11:8];						 
	CamWriteCmosSensor(0x030E,0x00);//HOUT_STADR[7:0];								 
	CamWriteCmosSensor(0x030F,0x00);//-/-/-/-/VOUT_STADR[11:8];						 
	CamWriteCmosSensor(0x0310,0x00);//VOUT_STADR[7:0];								 
	CamWriteCmosSensor(0x0311,0x0A);//-/-/-/-/HOUTSIZ[11:8];							 
	CamWriteCmosSensor(0x0312,0x30);//HOUTSIZ[7:0];									 
	CamWriteCmosSensor(0x0313,0x07);//-/-/-/-/VOUTSIZ[11:8];							 
	CamWriteCmosSensor(0x0314,0xA8);//VOUTSIZ[7:0];									 
	CamWriteCmosSensor(0x0315,0x00);//HANABIN/-/-/-/-/-/VMON[1:0];					 
	CamWriteCmosSensor(0x0400,0x00);///-/-/-/-/-/-/-/HSCALE;							 
	CamWriteCmosSensor(0x0600,0x02);//TPAT_SEL[2:0]/(4)/(3)/(2)/ TPAT_R[9:8]; 		 
	CamWriteCmosSensor(0x32C6,0x28);//TLPXPRD[3:0]/ CLKPREPRD[3:0];					 
	CamWriteCmosSensor(0x32C7,0x86);//CLKTRIPRD[3:0]/ HSPREPRD[3:0];					 
	CamWriteCmosSensor(0x32C8,0x88);//HS0PRD[3:0]/ HSTRLPRD[3:0]; 	
	
}

/*****************************************************************************
//danbo Note:
//Note Size: 2560* 1920
//FAE Setting :Frame Rate  2 fps (RAW10) , PCLK 26MHZ
*****************************************************************************/
static void ET8EV3MipiSetQSXGA_2_FPS(kal_uint8 RAW_Data_bits)
{
	ET8EV3MipiSensorStatus.PvMode = KAL_FALSE;
    ET8EV3MipiSensorStatus.CapFrameLength= ET8EV3_MIPI_FULL_PERIOD_LINE_NUMS_3_5_FPS;
	ET8EV3MipiSensorStatus.CapLineLength= ET8EV3_MIPI_FULL_PERIOD_PIXEL_NUMS_3_5_FPS;

	ET8EV3MipiSensorStatus.CapPclk=26; // SPCK on sensor (MHz)

	if(RAW_Data_bits==ET8EV3_MIPI_8BIT_RAW)
	{
		CamWriteCmosSensor(0x0100,0x81);//-/-/-/-/-/ANA_GA_MIN[11:8]; 
	}
	else
	{		
		CamWriteCmosSensor(0x0100,0x80);//-/-/-/-/-/ANA_GA_MIN[11:8]; 
	}
	CamWriteCmosSensor(0x0100,0x80);//MODE_SEL/VREVON/HREVON/SWRST/GRHOLD/-/-/OUT_FORMAT;
	CamWriteCmosSensor(0x0002,0x00);//-/-/-/-/-/ANA_GA_MIN[11:8]; 					 
	CamWriteCmosSensor(0x0003,0x1D);//ANA_GA_MIN[7:0];								 
	CamWriteCmosSensor(0x0004,0x01);//-/-/-/-/-/ANA_GA_MAX[11:8]; 					 
	CamWriteCmosSensor(0x0005,0x60);//ANA_GA_MAX[7:0];								 
	//CamWriteCmosSensor(0x0200,0x05);//INTGTIM[15:8];									 
	//CamWriteCmosSensor(0x0201,0x00);//INTGTIM[7:0];									 
	//CamWriteCmosSensor(0x0202,0x00);//-/-/-/-/ANAGAIN[11:8];							 
	//CamWriteCmosSensor(0x0203,0x1D);//ANAGAIN[7:0];	
	
	CamWriteCmosSensor(0x0300,0x42);//-/PIXCKDIV[2:0]/-/SYSCKDIV[2:0];				 
	CamWriteCmosSensor(0x0301,0x01);//-/-/-/-/-/-/PRECKDIV[1:0];						 
	CamWriteCmosSensor(0x0302,0x01);//-/-/-/-/-/OPSYSDIV[2:0];						 
	CamWriteCmosSensor(0x0303,0x00);//-/-/-/-/-/-/-/PLLMULT[8];						 

    CamWriteCmosSensor(0x0304,0x34);//PLLMULT[7:0]; 								 
	CamWriteCmosSensor(0x0305,0x07);//TTLINE[15:8]; 								 
	CamWriteCmosSensor(0x0306,0xDC);//TTLINE[7:0];									 
	CamWriteCmosSensor(0x0307,0x0D);//TTLDOT[15:8]; 								 
	CamWriteCmosSensor(0x0308,0x48);//TTLDOT[7:0];

	CamWriteCmosSensor(0x030D,0x00);//-/-/-/-/HOUT_STADR[11:8];						 
	CamWriteCmosSensor(0x030E,0x00);//HOUT_STADR[7:0];								 
	CamWriteCmosSensor(0x030F,0x00);//-/-/-/-/VOUT_STADR[11:8];						 
	CamWriteCmosSensor(0x0310,0x00);//VOUT_STADR[7:0];								 
	CamWriteCmosSensor(0x0311,0x0A);//-/-/-/-/HOUTSIZ[11:8];							 
	CamWriteCmosSensor(0x0312,0x30);//HOUTSIZ[7:0];									 
	CamWriteCmosSensor(0x0313,0x07);//-/-/-/-/VOUTSIZ[11:8];							 
	CamWriteCmosSensor(0x0314,0xA8);//VOUTSIZ[7:0];									 
	CamWriteCmosSensor(0x0315,0x00);//HANABIN/-/-/-/-/-/VMON[1:0];					 
	CamWriteCmosSensor(0x0400,0x00);///-/-/-/-/-/-/-/HSCALE;							 
	CamWriteCmosSensor(0x0600,0x02);//TPAT_SEL[2:0]/(4)/(3)/(2)/ TPAT_R[9:8]; 		 
	CamWriteCmosSensor(0x32C6,0x28);//TLPXPRD[3:0]/ CLKPREPRD[3:0];					 
	CamWriteCmosSensor(0x32C7,0x86);//CLKTRIPRD[3:0]/ HSPREPRD[3:0];					 
	CamWriteCmosSensor(0x32C8,0x88);//HS0PRD[3:0]/ HSTRLPRD[3:0]; 		


	
}

void ET8EV3MipiSetMirrorFlip(kal_uint8 image_mirror)
{
	switch (image_mirror)
	{
		case IMAGE_SENSOR_MIRROR_NORMAL:
			CamWriteCmosSensor(0x0100,0x80);
		break;
		case IMAGE_SENSOR_MIRROR_H:
			CamWriteCmosSensor(0x0100,0xA0);
		break;
		case IMAGE_SENSOR_MIRROR_V:
			CamWriteCmosSensor(0x0100,0xC0);
		break;
		case IMAGE_SENSOR_MIRROR_HV:
			CamWriteCmosSensor(0x0100,0xE0);
		break;
	}
}


static kal_uint16 ET8EV3MipiReg2Gain(const kal_uint16 iReg)
{
    /*************************************************************************
    * AG is common gain for R, G and B channel and is used for AE operation.
    * 0x0202(D11-D8), 0x0203(D7-D0) 
    * 02Ch:    1x  
    * 058h:    2x
    * 0B0h:    4x
    * 160h:    8x
    * 2C0h:   16x  (Max)
    **************************************************************************/     
    const kal_uint16 iGain = iReg * BASEGAIN / ET8EV3_BASE_GAIN;

    return iGain;
}

//static kal_uint8 ET8EV3MipiGain2Reg(const kal_uint16 iGain)
static kal_uint16 ET8EV3MipiGain2Reg(const kal_uint16 iGain)
{
    /*************************************************************************
    * AG is common gain for R, G and B channel and is used for AE operation.
    * 0x0202(D11-D8), 0x0203(D7-D0) 
    * 02Ch:    1x  
    * 058h:    2x
    * 0B0h:    4x
    * 160h:    8x
    * 2C0h:   16x  (Max)
    **************************************************************************/    
   kal_uint16 iReg = ET8EV3_BASE_GAIN * iGain / BASEGAIN;

    return iReg;
}

static kal_uint16 ET8EV3MipiGain2Sensor(const kal_uint16 iGain)
{
    /*************************************************************************
    * AG is common gain for R, G and B channel and is used for AE operation.
    * 0x0202(D11-D8), 0x0203(D7-D0) 
    * 02Ch:    1x  
    * 058h:    2x
    * 0B0h:    4x
    * 160h:    8x
    * 2C0h:   16x  (Max)
    **************************************************************************/    
   kal_uint16 iReg = ET8EV3_BASE_GAIN_APPLY_SENSOR * iGain / BASEGAIN;

    return iReg;
}

/*************************************************************************
* FUNCTION
*	ET8EV3_MIPI_SetGain
*
* DESCRIPTION
*	This function is to set global gain to sensor.
*
* PARAMETERS
*   iGain : sensor global gain(base: 0x40)
*
* RETURNS
*	the actually gain set to sensor.
*
* GLOBALS AFFECTED
*
*************************************************************************/

kal_uint16 ET8EV3_Sensor_gain=1;

kal_uint16 ET8EV3MipiSetGain(kal_uint16 iGain)
{
	
	float iBaseGain = (float)pET8EV3MipiNvramSensorData->cct[ET8EV3_MIPI_INDEX_BASE_GAIN].para / (float)ET8EV3_BASE_GAIN;
    const kal_uint16 iReg = ET8EV3MipiGain2Sensor( iGain * iBaseGain );

	ET8EV3_Sensor_gain = iReg;	

	CamWriteCmosSensor(0x0202,iReg>>8);//-/-/-/-/ANAGAIN[11:8];                                         
	CamWriteCmosSensor(0x0203,iReg&0xFF);//ANAGAIN[7:0];                                                  

#ifdef __ET8EV3_MIPI_DBG__
    kal_print_string_trace (MOD_ENG,TRACE_INFO, "[GAIN]Shut: %d, Gain: %d, YAvg: %d", ET8EV3MipiSensorStatus.ExposureLines, iGain, iReg);
#endif

	CamReadCmosSensor(0x0202);
	CamReadCmosSensor(0x0203);

	//return (ET8EV3MipiReg2Gain(iReg)/iBaseGain);
	return iGain;
}

kal_uint16 ET8EV3MipiReadSensorGain()
{
	CamReadCmosSensor(0x0202);
	CamReadCmosSensor(0x0203);
}

static kal_uint16 ET8EV3MipiReadGain(void)
{
    volatile signed char i;
    kal_uint16 sensor_gain=0,temp_reg_base=0;

    sensor_gain=(temp_reg_base*BASEGAIN)/8;
    return sensor_gain;
}  /* MT9P012MipiReadGain */

static void ET8EV3MipiFixVideoFrameRate(kal_uint16 framerate)
{

	if (framerate>=150)
		ET8EV3MipiSensorStatus.VideoCurrentFrameRate=150;
	else if(framerate>=120)
		ET8EV3MipiSensorStatus.VideoCurrentFrameRate=120;
	else if(framerate>=75)
		ET8EV3MipiSensorStatus.VideoCurrentFrameRate=75;
	else if(framerate>=50)
	    ET8EV3MipiSensorStatus.VideoCurrentFrameRate=50;
	else
		ASSERT(0);
	
    ET8EV3MipiSensorStatus.VideoMaxLineLength = (kal_uint16)((ET8EV3MipiSensorStatus.PvLineLength * 300)/ET8EV3MipiSensorStatus.VideoCurrentFrameRate);
    /*Auto15fps-4620, 12fps-5775; night 7.5fps-9240, 5fps-13860*/

    if (ET8EV3MipiSensorStatus.VideoMaxLineLength < ET8EV3MipiSensorStatus.PvLineLength)			
        ET8EV3MipiSensorStatus.VideoMaxLineLength = ET8EV3MipiSensorStatus.PvLineLength;

    ET8EV3MipiSetDummy(ET8EV3MipiSensorStatus.VideoMaxLineLength-ET8EV3MipiSensorStatus.PvLineLength,0);
    ET8EV3MipiSensorStatus.PvLineLength=ET8EV3MipiSensorStatus.VideoMaxLineLength;
}

/*************************************************************************
* FUNCTION
*	ET8EV3_MIPI_night_mode
*
* DESCRIPTION
*	This function night mode of ET8EV3_MIPI.
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
static void ET8EV3MipiNightMode(kal_bool enable)
{
}/* ET8EV3_MIPI_night_mode */

/*************************************************************************
* FUNCTION
*   ET8EV3_MIPI_SetFlashlight
*
* DESCRIPTION
*   ET8EV3_MIPI flash control function
*
* PARAMETERS
*   bEnable: KAL_TRUE -> enable flash light, otherwise disable flash light
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void ET8EV3MipiSetFlashlight(kal_bool bEnable)
{
    FlashlightPowerOn(ET8EV3MipiSensorIdx, bEnable);
}   /*  ET8EV3_MIPI_SetFlashlight    */

void ET8EV3MipiGetSensorAeInfo(IMAGE_SENSOR_AE_INFO_STRUCT *info_ptr) {
	info_ptr->DefaultPrevLinePixels = ET8EV3_MIPI_PV_PERIOD_PIXEL_NUMS;
    info_ptr->CurrentPrevLinePixels =ET8EV3_MIPI_PV_PERIOD_PIXEL_NUMS +ET8EV3MipiSensorStatus.PvDummyPixels;
	info_ptr->CurrentPclk=ET8EV3MipiSensorStatus.PrvPclk*1000000;
}

// for camera HAL integration
// write camera_para to sensor register
void ET8EV3MipiCameraParaToSensor(nvram_camera_para_struct *pCameraPara)
{
	kal_uint32	i;
	for(i=0; 0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr; i++)
	{
		CamWriteCmosSensor(pCameraPara->SENSOR.reg[i].addr, pCameraPara->SENSOR.reg[i].para);
    }

	for(i=ENGINEER_START_ADDR; 0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr; i++)
	{
		CamWriteCmosSensor(pCameraPara->SENSOR.reg[i].addr, pCameraPara->SENSOR.reg[i].para);
    }
	for(i=FACTORY_START_ADDR+1; i<5; i++)
	{
		CamWriteCmosSensor(pCameraPara->SENSOR.cct[i].addr, (pCameraPara->SENSOR.cct[i].para>>8));
		CamWriteCmosSensor(pCameraPara->SENSOR.cct[i].addr+1, (pCameraPara->SENSOR.cct[i].para&0xFF));
    }

} /* ET8EV3MipiCameraParaToSensor() */

// update camera_para from sensor register
void ET8EV3MipiSensorToCameraPara(nvram_camera_para_struct *pCameraPara)
{
	kal_uint32	i;
	for(i=0; 0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr; i++)
	{
		pCameraPara->SENSOR.reg[i].para = CamReadCmosSensor(pCameraPara->SENSOR.reg[i].addr);
    }

	for(i=ENGINEER_START_ADDR; 0xFFFFFFFF!=pCameraPara->SENSOR.reg[i].addr; i++)
	{
		pCameraPara->SENSOR.reg[i].para = CamReadCmosSensor(pCameraPara->SENSOR.reg[i].addr);
	}

} /* ET8EV3MipiSensorToCameraPara() */


void  ET8EV3MipiGetSensorGroupCount(kal_int32* sensor_count_ptr)
{

    *sensor_count_ptr=GROUP_TOTAL_NUMS;

    return;
}


void ET8EV3MipiGetSensorGrouinfo(kal_uint16 group_idx, kal_int8* group_name_ptr, kal_int32* item_count_ptr)
{
   switch (group_idx)
   {
    case PRE_GAIN:
        kal_sprintf((kal_char *)group_name_ptr, "CCT");
        *item_count_ptr = CCT_END_ADDR;
        break;
    case CMMCLK_CURRENT:
        kal_sprintf((kal_char *)group_name_ptr, "CMMCLK Current");
        *item_count_ptr = 1;
        break;
    case FRAME_RATE_LIMITATION:
        break;
    case REGISTER_EDITOR:
        kal_sprintf((kal_char *)group_name_ptr, "Register Editor");
        *item_count_ptr = 2;
        break;
    default:
        ASSERT(0);
    }
}

void ET8EV3MipiGetSensorItemInfo(kal_uint16 group_idx,kal_uint16 item_idx, CAL_CCT_SENSOR_ITEM_INFO_STRUCT* info_ptr)
{
	kal_uint16 temp_addr=0;
	
    switch (group_idx) {

	case PRE_GAIN:
		switch (item_idx) {
		case SENSOR_BASEGAIN:
			sprintf((char *) (info_ptr->ItemNamePtr), "SENSOR_BASEGAIN");
			info_ptr->ItemValue = 1000* ET8EV3MipiReg2Gain(pET8EV3MipiNvramSensorData->cct[SENSOR_BASEGAIN].para)/ BASEGAIN;
			info_ptr->IsTrueFalse = KAL_FALSE;
			info_ptr->IsReadOnly = KAL_FALSE;
			info_ptr->IsNeedRestart = KAL_FALSE;
			info_ptr->Min = 1 * 1000;	// MIN. global gain = 1x gain
			info_ptr->Max = 32 * 1000; // MAX. global gain = 32x gain
			break;
	
		case PRE_GAIN_R_INDEX:
		case PRE_GAIN_Gr_INDEX:
		case PRE_GAIN_B_INDEX:
		case PRE_GAIN_Gb_INDEX:
			switch (item_idx)
			{
				case PRE_GAIN_R_INDEX:
				  temp_addr = 1;
				break;
				case PRE_GAIN_Gr_INDEX:
				  temp_addr = 2;
				break;
				case PRE_GAIN_B_INDEX:
				  temp_addr = 3;
				break;
				case PRE_GAIN_Gb_INDEX:
				temp_addr = 4;
				break;
				default:
				   ASSERT(0);		
			}
			
			if (item_idx == PRE_GAIN_R_INDEX) {
				sprintf((char *) (info_ptr->ItemNamePtr), "Pregain-R");
			}else if (item_idx == PRE_GAIN_Gr_INDEX) {
				sprintf((char *) (info_ptr->ItemNamePtr), "Pregain-Gr");
			}else if (item_idx == PRE_GAIN_B_INDEX) {
				sprintf((char *) (info_ptr->ItemNamePtr), "Pregain-B");
			}else if (item_idx == PRE_GAIN_Gb_INDEX) {
				sprintf((char *) (info_ptr->ItemNamePtr), "Pregain-Gb");
			}else {
				ASSERT(0);
			}
	
			// R, G, B gain = reg / 0x400
			info_ptr->ItemValue = pET8EV3MipiNvramSensorData->cct[temp_addr].para * 1000/ 0x100 ;
			info_ptr->IsTrueFalse = KAL_FALSE;
			info_ptr->IsReadOnly = KAL_FALSE;
			info_ptr->IsNeedRestart = KAL_FALSE;
			info_ptr->Min = 1 * 1000;	// MIN. pre-gain
			info_ptr->Max = 0xfff * 1000 / 0x400; // MAX. pre-gain
			break;
		}
		break;
	
	case CMMCLK_CURRENT:
		switch (item_idx) {
		case 0:
			sprintf((char *) info_ptr->ItemNamePtr, "Drv Current[2,4,6,8]mA");
			switch (pET8EV3MipiNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para) {
			case ISP_DRIVING_2MA:
				info_ptr->ItemValue = 2;
				break;
	
			case ISP_DRIVING_4MA:
				info_ptr->ItemValue = 4;
				break;
	
			case ISP_DRIVING_6MA:
				info_ptr->ItemValue = 6;
				break;
	
			case ISP_DRIVING_8MA:
				info_ptr->ItemValue = 8;
				break;
	
			default:
				ASSERT(0);
			}	// switch (pET8EV3MipiNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para)
	
			info_ptr->IsTrueFalse = KAL_FALSE;
			info_ptr->IsReadOnly = KAL_FALSE;
			info_ptr->IsNeedRestart = KAL_TRUE;
			info_ptr->Min = 2;
			info_ptr->Max = 8;
			break;
	
		default:
			ASSERT(0);
		}	// switch (item_idx)
		break;
	
	case REGISTER_EDITOR:
		switch (item_idx) {
		case 0:
			sprintf((char *) info_ptr->ItemNamePtr, "REG Addr.");
			info_ptr->ItemValue = 0;
			info_ptr->IsTrueFalse = KAL_FALSE;
			info_ptr->IsReadOnly = KAL_FALSE;
			info_ptr->IsNeedRestart = KAL_FALSE;
			info_ptr->Min = 0x00;
			info_ptr->Max = 0xFF;
			break;
	
		case 1:
			sprintf((char *) info_ptr->ItemNamePtr, "REG Value");
			info_ptr->ItemValue = 0;
			info_ptr->IsTrueFalse = KAL_FALSE;
			info_ptr->IsReadOnly = KAL_FALSE;
			info_ptr->IsNeedRestart = KAL_FALSE;
			info_ptr->Min = 0x00;
			info_ptr->Max = 0xFF;
			break;
	
		default:
			ASSERT(0);
		}
		break;
	
	default:
		ASSERT(0);
    }
}

kal_bool ET8EV3MipiSetSensorItemInfo(kal_uint16 group_idx, kal_uint16 item_idx, kal_int32 ItemValue)
{
	kal_uint16 iTemp = 0x00;
	 static kal_uint32 iFAC_SENSOR_REG = 0x00;
	 kal_uint16 temp_addr=0;

    switch (group_idx)
    {
		case PRE_GAIN:
			switch (item_idx) {
			case SENSOR_BASEGAIN:
				if (ItemValue < 1 * 1000 || ItemValue >= 32 * 1000) {
					return KAL_FALSE;
				}

				iTemp = ET8EV3MipiGain2Reg(ItemValue * BASEGAIN / 1000);
				pET8EV3MipiNvramSensorData->cct[SENSOR_BASEGAIN].para = iTemp;
				//CamWriteCmosSensor(pET8EV3MipiNvramSensorData->cct[SENSOR_BASEGAIN].addr, iTemp&0xFF);
				break;
		
			case PRE_GAIN_R_INDEX:
			case PRE_GAIN_Gr_INDEX:
			case PRE_GAIN_B_INDEX:
			case PRE_GAIN_Gb_INDEX:
				switch (item_idx)
				{
					case PRE_GAIN_R_INDEX:
					  temp_addr = 1;
					break;
					case PRE_GAIN_Gr_INDEX:
					  temp_addr = 2;
					break;
					case PRE_GAIN_B_INDEX:
					  temp_addr = 3;
					  break;
					 case PRE_GAIN_Gb_INDEX:
					  temp_addr = 4;
					break;
					default:
					   ASSERT(0);		
				}
				if (ItemValue < (1* 1000)  || ItemValue > (3* 1000) ) {
					return KAL_FALSE;
				}
				
				iTemp = ItemValue * 0x100 / 1000;  // R, G, B gain = reg. / 0x40
				pET8EV3MipiNvramSensorData->cct[temp_addr].para = iTemp;
				CamWriteCmosSensor(pET8EV3MipiNvramSensorData->cct[item_idx].addr, (iTemp>>8)&0xff);
				CamWriteCmosSensor(pET8EV3MipiNvramSensorData->cct[item_idx].addr+1, iTemp&0xff);
				
				break;
		
			default:
				ASSERT(0);	
			}
			break;
		
			case CMMCLK_CURRENT:
				switch (item_idx) {
				case 0:
					if (ItemValue == 2) {
						pET8EV3MipiNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_2MA;
						SetIspDrivingCurrent(ISP_DRIVING_2MA);
					}else if (ItemValue == 3 || ItemValue == 4) {
						pET8EV3MipiNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_4MA;
						SetIspDrivingCurrent(ISP_DRIVING_4MA);
					}else if (ItemValue == 5 || ItemValue == 6) {
						pET8EV3MipiNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_6MA;
						SetIspDrivingCurrent(ISP_DRIVING_6MA);
					}else if (ItemValue == 7 || ItemValue == 8) {
						pET8EV3MipiNvramSensorData->reg[CMMCLK_CURRENT_INDEX].para = ISP_DRIVING_8MA;
						SetIspDrivingCurrent(ISP_DRIVING_8MA);
					}else {
						return KAL_FALSE;
					}
					break;
		
				default:
					ASSERT(0);
				}	// switch (CMMCLK_CURRENT)
			break;
		
		case REGISTER_EDITOR:
			switch (item_idx)	{
			case 0:
				if (ItemValue < 0 || ItemValue > 0xFFFF) {
					return KAL_FALSE;
				}
				iFAC_SENSOR_REG = ItemValue;
				break;
		
			case 1:
				if (ItemValue < 0 || ItemValue > 0xFFFF) {
					return KAL_FALSE;
				}
				CamWriteCmosSensor(iFAC_SENSOR_REG, ItemValue);
				break;
		
			default:
				ASSERT(0);
			}	// switch (iItemIndex)
			break;
		
			default:
			   ASSERT(0);

    }

    return KAL_TRUE;
}


void ET8EV3MipiGetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT pSensorInfo)
{
    pSensorInfo->SensorId=ET8EV3_MIPI_SENSOR_ID;
    pSensorInfo->SensorIf=IMAGE_SENSOR_IF_MIPI;

    pSensorInfo->PreviewNormalDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_B_FIRST;
    pSensorInfo->PreviewHMirrorDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gb_FIRST;
    pSensorInfo->PreviewVMirrorDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_Gr_FIRST;
    pSensorInfo->PreviewHVMirrorDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_R_FIRST;    
    pSensorInfo->CaptureDataFormat=IMAGE_SENSOR_DATA_OUT_FORMAT_RAW_B_FIRST;

    pSensorInfo->PixelClkInv=KAL_FALSE;
    pSensorInfo->PixelClkPolarity=POLARITY_LOW;
    pSensorInfo->HsyncPolarity=POLARITY_LOW;
    pSensorInfo->VsyncPolarity=POLARITY_LOW;
    pSensorInfo->PreviewMclkFreq = 24000000;
    pSensorInfo->CaptureMclkFreq = 24000000;
    pSensorInfo->VideoMclkFreq = 24000000;
    pSensorInfo->PreviewWidth=ET8EV3_MIPI_IMAGE_SENSOR_PV_WIDTH;
    pSensorInfo->PreviewHeight=ET8EV3_MIPI_IMAGE_SENSOR_PV_HEIGHT;
    pSensorInfo->FullWidth=ET8EV3_MIPI_IMAGE_SENSOR_FULL_WIDTH;
    pSensorInfo->FullHeight=ET8EV3_MIPI_IMAGE_SENSOR_FULL_HEIGHT;
    pSensorInfo->SensorAfSupport=KAL_FALSE;
    pSensorInfo->SensorFlashSupport=KAL_FALSE;
} /* ET8EV3MipiGetSensorInfo() */


void ET8EV3MipiGetMipiInfo(P_IMAGE_SENSOR_MIPI_PARA_IN_STRUCT pParaIn, P_IMAGE_SENSOR_MIPI_PARA_OUT_STRUCT pParaOut)
{


    if((CAL_SCENARIO_CAMERA_PREVIEW == pParaIn->ScenarioMode)
        ||(CAL_SCENARIO_WEBCAM_PREVIEW == pParaIn->ScenarioMode)
        ||(CAL_SCENARIO_CCT_CAMERA_PREVIEW == pParaIn->ScenarioMode))
    {
        pParaOut->MipiLaneNum = 1;
        pParaOut->LowPwr2HighSpeedDelayCount = 20;//20;//25;
    }
    else if ((CAL_SCENARIO_CAMERA_STILL_CAPTURE ==pParaIn->ScenarioMode) 
        ||(CAL_SCENARIO_CCT_CAMERA_CAPTURE_JPEG ==pParaIn->ScenarioMode) 
        ||(CAL_SCENARIO_CCT_CAMERA_CAPTURE_RAW ==pParaIn->ScenarioMode))
    {

    if ((pParaIn->TargetWidth<=ET8EV3_MIPI_IMAGE_SENSOR_PV_WIDTH)
        &&(pParaIn->TargetHeight<=ET8EV3_MIPI_IMAGE_SENSOR_PV_HEIGHT))
        {
        #ifdef CAM_OFFLINE_CAPTURE
            pParaOut->MipiLaneNum = 1;
            pParaOut->LowPwr2HighSpeedDelayCount = 20;//10;//10;
        #else
            pParaOut->MipiLaneNum = 1;
            pParaOut->LowPwr2HighSpeedDelayCount = 20;//25;
        #endif	
        }
    else
        {
        #ifdef CAM_OFFLINE_CAPTURE

            pParaOut->MipiLaneNum = 1;
            pParaOut->LowPwr2HighSpeedDelayCount = 9;//15;//Delaycount;//10;

        #elif CAM_OTF_CAPTURE

            if (100==pParaIn->DigitalZoomFactor) /* 1x capture */
                {
                pParaOut->MipiLaneNum = 1;
                pParaOut->LowPwr2HighSpeedDelayCount =9;//15;//25;
                }
            else if(pParaIn->DigitalZoomFactor<200)/* 1x~2x capture */
                {
                pParaOut->MipiLaneNum = 1;
                pParaOut->LowPwr2HighSpeedDelayCount =9;//15;//25;
                }
            else if(pParaIn->DigitalZoomFactor<=400)/* 2x~4x capture */
                {
                pParaOut->MipiLaneNum = 1;
                pParaOut->LowPwr2HighSpeedDelayCount = 9;//15;//40;
                }
            else /* 4x~8x capture */
                {
                pParaOut->MipiLaneNum = 1;
                pParaOut->LowPwr2HighSpeedDelayCount = 9;//15;//70;
                }

        #else //CAM_STANDARD_CAPTURE

                if (pParaIn->DigitalZoomFactor>100)
                    {
                    pParaOut->MipiLaneNum = 1;
                    pParaOut->LowPwr2HighSpeedDelayCount =9;//15;//15;//10;
                    }
                else
                    {
                    pParaOut->MipiLaneNum = 1;
                    pParaOut->LowPwr2HighSpeedDelayCount =9;//15;//15;//25;
                    }

            #endif
        }
    }
    else if((CAL_SCENARIO_VIDEO ==pParaIn->ScenarioMode))
    {
        switch (ET8EV3MipiSensorStatus.VideoCurrentFrameRate)
        {
            case ET8EV3_MIPI_VIDEO_FRAME_RATE_5fps:
                pParaOut->MipiLaneNum = 1;
                pParaOut->LowPwr2HighSpeedDelayCount = 20;//70;
                break;	
            case ET8EV3_MIPI_VIDEO_FRAME_RATE_7_5fps:	
                pParaOut->MipiLaneNum = 1;
                pParaOut->LowPwr2HighSpeedDelayCount = 20;//40;
                break;
            case ET8EV3_MIPI_VIDEO_FRAME_RATE_12fps:
            case ET8EV3_MIPI_VIDEO_FRAME_RATE_15fps:
                pParaOut->MipiLaneNum = 1;
                pParaOut->LowPwr2HighSpeedDelayCount = 20;//25;
            break;
            default:
		ASSERT(0);
            break; 
        }
    }
    
}


static kal_uint16 ET8EV3MipiPowerOn(void)
{
	volatile kal_uint32 iI;
	kal_uint32 sensor_id=0;

#ifdef __ET8EV3_MIPI_DBG__
	kal_wap_trace(MOD_ENG,TRACE_INFO,"ET8EV3MipiPowerOn(): Function IN**************");
#endif

	CisModulePowerOn(ET8EV3MipiSensorIdx, KAL_TRUE);

	CamPdnPinCtrl(ET8EV3MipiSensorIdx, 1);
	CamRstPinCtrl(ET8EV3MipiSensorIdx, 0);
	kal_sleep_task(1);
	CamPdnPinCtrl(ET8EV3MipiSensorIdx, 0);
	CamRstPinCtrl(ET8EV3MipiSensorIdx, 1);
	kal_sleep_task(1);

	CameraSccbOpen(CAMERA_SCCB_SENSOR, ET8EV3_MIPI_HW_SCCB_SLAVE_ADDR, CAMERA_SCCB_16BIT, CAMERA_SCCB_8BIT, 320);
	kal_sleep_task(4);	/* delay for power stable */
								
    /* Check ID */
    for (iI=0;iI<3;iI++)
    {
        sensor_id=((CamReadCmosSensor(0x0000)<<8)|CamReadCmosSensor(0x0001));

#ifdef __ET8EV3_MIPI_DBG__
		kal_wap_trace(MOD_ENG,TRACE_INFO,"ET8EV3_MIPI PowerOn SensorId:%x",sensor_id);
#endif
        if (sensor_id==ET8EV3_MIPI_SENSOR_ID)
            break;
    }
    return sensor_id;
} /* ET8EV3MipiPowerOn() */

kal_uint32 ET8EV3MipiDetectSensorId(void)
{
  MM_ERROR_CODE_ENUM ET8EV3MipiSensorClose(void);
  kal_uint16 ET8EV3MipiPowerOn();
  kal_uint16 sensorId, AnotherSensorIdx;
  kal_int8 i, j;

  if (IMAGE_SENSOR_MAIN == ET8EV3MipiSensorIdx)
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
      //CamRstPinCtrl(AnotherSensorIdx, i);
//      CamPdnPinCtrl(AnotherSensorIdx, j);
      sensorId = ET8EV3MipiPowerOn();
      ET8EV3MipiSensorClose();
#ifdef __ET8EV3_MIPI_DBG__
      kal_wap_trace(MOD_ENG,TRACE_INFO,"ET8EV3_MIPI DetectSensorId:%x",sensorId);
#endif
      if (ET8EV3_MIPI_SENSOR_ID == sensorId)
      {
        return ET8EV3_MIPI_SENSOR_ID;
      }
    }
  }
  return MM_ERROR_SENSOR_READ_ID_FAIL;
}   /* ET8EV3MipiDetectSensorId() */

MM_ERROR_CODE_ENUM ET8EV3MipiSensorOpen(void)
{
    IspSetInterruptTriggerDelayLines(4);	// 0: VD INT, others: TG INT & start line

    if (ET8EV3MipiPowerOn()!= ET8EV3_MIPI_SENSOR_ID)
        return MM_ERROR_SENSOR_READ_ID_FAIL;

 	ET8EV3MipiSensorStatus.ExposureLines=400;
	
	ET8EV3MiPiInitialSetting();
    return MM_ERROR_NONE;
} /* ET8EV3MipiSensorOpen() */


// Base shutter calculation
//		60Hz: (1/120) * Clk / PREVIEW_MODE_WITHOUT_DUMMY_PIXELS = 66000000/(2310*120)=238
//		50Hz: (1/100) * Clk / PREVIEW_MODE_WITHOUT_DUMMY_PIXELS = 66000000/(2310*100)=285.7

static void ET8EV3MipiPreview(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{
	kal_uint32 sensor_id=0,sensor_id1=0,sensor_id2=0;
	
#ifdef __ET8EV3_MIPI_DBG__
	kal_wap_trace(MOD_ENG,TRACE_INFO,"danbo Test Enter  ET8EV3MipiPreview \n:");
#endif

    ET8EV3MipiSensorStatus.PvDummyPixels=0;
    ET8EV3MipiSensorStatus.PvDummyLines=0;

#ifdef __PREVIEW_1_4_FULL_SIZE
	ET8EV3MipiSetSXGA_Preview(ET8EV3_MIPI_8BIT_RAW);
#else
	#ifdef __PREVIEW_720P__
		ET8EV3MipiSetXGA_720P(ET8EV3_MIPI_8BIT_RAW);
	#else
		ET8EV3MipiSetXGA_VGA(ET8EV3_MIPI_8BIT_RAW);
	#endif
#endif

    ET8EV3MipiSetMirrorFlip(pParaIn->ImageMirror);

    pParaOut->GrabStartX = 1;//0;
    pParaOut->GrabStartY = 2;//1;
    pParaOut->ExposureWindowWidth = ET8EV3_MIPI_IMAGE_SENSOR_PV_WIDTH;
    pParaOut->ExposureWindowHeight = ET8EV3_MIPI_IMAGE_SENSOR_PV_HEIGHT;
   
    ET8EV3MipiWriteShutter(ET8EV3MipiSensorStatus.ExposureLines);

#ifdef __ET8EV3_MIPI_DBG__	
	kal_wap_trace(MOD_ENG,TRACE_INFO,"danbo Test Exit  ET8EV3MipiPreview \n:");
#endif

}/* ET8EV3MipiPreview */

void ET8EV3MipiGetPreviewFlashlightInfo(P_FLASHLIGHT_PREVIEW_PARA_STURCT pPreviewInfo)
{
    pPreviewInfo->pixels = ET8EV3_MIPI_PV_PERIOD_PIXEL_NUMS;
    pPreviewInfo->lines = ET8EV3_MIPI_IMAGE_SENSOR_PV_HEIGHT;
    pPreviewInfo->frame_lines = ET8EV3_MIPI_PV_PERIOD_LINE_NUMS;
     
}

static void ET8EV3MipiCapture(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{
    volatile kal_uint16 shutter=ET8EV3MipiSensorStatus.ExposureLines;
    kal_uint32 ShutterTemp=ET8EV3MipiSensorStatus.ExposureLines;
    ET8EV3MipiSensorStatus.BackupExposureLines = ET8EV3MipiSensorStatus.ExposureLines;	
    
    if(KAL_TRUE==pParaIn->EnableShutterTransfer)
    {
        shutter=pParaIn->CaptureShutter;
        ShutterTemp=(float)pParaIn->CaptureShutter;
    }

    /////////////////////////////////////////////////////
    // Determind the size to run the Small size or Large size capture
    if ((pParaIn->ImageTargetWidth<=ET8EV3_MIPI_IMAGE_SENSOR_PV_WIDTH)&&
        (pParaIn->ImageTargetHeight<=ET8EV3_MIPI_IMAGE_SENSOR_PV_HEIGHT))
    {

		// Run the Small size capture  - Wallpaper(), HVGA, VGA size 
        //Write the preview setting
		#ifdef __PREVIEW_1_4_FULL_SIZE
			ET8EV3MipiSetSXGA_Preview(ET8EV3_MIPI_10BIT_RAW);
		#else
			#ifdef __PREVIEW_720P__
				ET8EV3MipiSetXGA_720P(ET8EV3_MIPI_10BIT_RAW);
			#else
				ET8EV3MipiSetXGA_VGA(ET8EV3_MIPI_10BIT_RAW);
			#endif
		#endif
		      
		#ifdef CAM_OFFLINE_CAPTURE
            ET8EV3MipiSensorStatus.CapDummyPixels=0;
            ET8EV3MipiSensorStatus.CapDummyLines=0;
        #elif CAM_OTF_CAPTURE
            ET8EV3MipiSensorStatus.CapDummyLines = 0;		
            if (100==pParaIn->ZoomFactor) /* 1x capture */
                ET8EV3MipiSensorStatus.CapDummyPixels = 0;
            else if(pParaIn->ZoomFactor<200)/* 1x~2x capture */
                ET8EV3MipiSensorStatus.CapDummyPixels = 0;//200;
            else if(pParaIn->ZoomFactor<400)/* 2x~4x capture */
                ET8EV3MipiSensorStatus.CapDummyPixels = 0;//1500;
            else /* 4x~8x capture */
                ET8EV3MipiSensorStatus.CapDummyPixels = 0;//2000;
        #else  //CAM_STANDARD_CAPTURE
            ET8EV3MipiSensorStatus.CapDummyPixels=0;
            ET8EV3MipiSensorStatus.CapDummyLines=0;
        #endif
		
            pParaOut->GrabStartX = 1;//2;//1;
            pParaOut->GrabStartY = 2;//1;//2;
            pParaOut->ExposureWindowWidth = ET8EV3_MIPI_IMAGE_SENSOR_PV_WIDTH;
            pParaOut->ExposureWindowHeight = ET8EV3_MIPI_IMAGE_SENSOR_PV_HEIGHT;
        }
    
    else  
        {
        // Run the Large size capture  - Larger Preview size to Max , 1M~5M for this sensor
        
        #ifdef CAM_OFFLINE_CAPTURE
			ET8EV3MipiSensorStatus.CapDummyPixels=0;			
            ET8EV3MipiSensorStatus.CapDummyLines=0;
			
			ET8EV3MipiSetQSXGA_12_FPS(ET8EV3_MIPI_10BIT_RAW);
			//ET8EV3MipiSetQSXGA_14_FPS(ET8EV3_MIPI_10BIT_RAW);

        #elif CAM_OTF_CAPTURE		
			ET8EV3MipiSensorStatus.CapDummyLines=0;
        /* Check Zoom Factor */
            if (100==pParaIn->ZoomFactor)  //1x capture
            	{   		
					ET8EV3MipiSensorStatus.CapDummyPixels=200;	
					
					if ((pParaIn->ImageTargetWidth==ET8EV3_MIPI_4M_WIDTH)&&
					(pParaIn->ImageTargetHeight==ET8EV3_MIPI_4M_HEIGHT))
					 {
						ET8EV3MipiSetQSXGA_7_5_FPS(ET8EV3_MIPI_10BIT_RAW);
					 }
					else
					 {
						ET8EV3MipiSetQSXGA_8_FPS(ET8EV3_MIPI_10BIT_RAW);
					 }
					
            	}
            else if(pParaIn->ZoomFactor<=200)//1x~2x capture
            	{				
					ET8EV3MipiSensorStatus.CapDummyPixels=1000;//200;
					
					if (((pParaIn->ImageTargetWidth==ET8EV3_MIPI_3M_WIDTH)&&
					(pParaIn->ImageTargetHeight==ET8EV3_MIPI_3M_HEIGHT))||
					((pParaIn->ImageTargetWidth==ET8EV3_MIPI_4M_WIDTH)&&
					(pParaIn->ImageTargetHeight==ET8EV3_MIPI_4M_HEIGHT)))
						{
							ET8EV3MipiSetQSXGA_7_5_FPS(ET8EV3_MIPI_10BIT_RAW);
						}
					else
						{
							ET8EV3MipiSetQSXGA_8_FPS(ET8EV3_MIPI_10BIT_RAW);
						}
            	}
            else if(pParaIn->ZoomFactor<=400)//2x~4x capture
            	{
					ET8EV3MipiSensorStatus.CapDummyPixels=6000;//1000;//200;
					
	            	if ((pParaIn->ImageTargetWidth==ET8EV3_MIPI_5M_WIDTH)&&
					(pParaIn->ImageTargetHeight==ET8EV3_MIPI_5M_HEIGHT))
	            		{
							ET8EV3MipiSetQSXGA_2_FPS(ET8EV3_MIPI_10BIT_RAW);
	            		}
					else
						{
							ET8EV3MipiSetQSXGA_3_5_FPS(ET8EV3_MIPI_10BIT_RAW);
						}
                } 
            else //4x~8x capture
            	{
	            	if ((pParaIn->ImageTargetWidth==ET8EV3_MIPI_5M_WIDTH)&&
					(pParaIn->ImageTargetHeight==ET8EV3_MIPI_5M_HEIGHT))
	            		{
							ET8EV3MipiSensorStatus.CapDummyPixels=10000;//5000;//200;
							ET8EV3MipiSetQSXGA_2_FPS(ET8EV3_MIPI_10BIT_RAW);
	            		}
					else
						{
							ET8EV3MipiSensorStatus.CapDummyPixels=6000;//5000;//200;
							ET8EV3MipiSetQSXGA_2_FPS(ET8EV3_MIPI_10BIT_RAW);
						}
                }   

     	#else ////CAM_STANDARD_CAPTURE
			if (100==pParaIn->ZoomFactor)  //1x capture  // the same as OTF
				{
					ET8EV3MipiSensorStatus.CapDummyLines=0;
					ET8EV3MipiSensorStatus.CapDummyPixels = 200;
					
					if ((pParaIn->ImageTargetWidth==ET8EV3_MIPI_4M_WIDTH)&&
						(pParaIn->ImageTargetHeight==ET8EV3_MIPI_4M_HEIGHT))
						 {
							ET8EV3MipiSetQSXGA_7_5_FPS(ET8EV3_MIPI_10BIT_RAW);
						 }
						else
						 {
							ET8EV3MipiSetQSXGA_8_FPS(ET8EV3_MIPI_10BIT_RAW);
						 }
				}
			else  // Big  1X Capture  the same as Offlie
				{	
					ET8EV3MipiSensorStatus.CapDummyPixels=0;			
					ET8EV3MipiSensorStatus.CapDummyLines=0;
					
					ET8EV3MipiSetQSXGA_12_FPS(ET8EV3_MIPI_10BIT_RAW);
					//ET8EV3MipiSetQSXGA_14_FPS(ET8EV3_MIPI_10BIT_RAW);
				}

     	#endif

#if 0	
		#ifdef CAM_OFFLINE_CAPTURE
/* under construction !*/
		#else
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
		#endif
#endif
        pParaOut->GrabStartX = 1;//2;//1;
        pParaOut->GrabStartY = 2;//1;//2;
        pParaOut->ExposureWindowWidth = ET8EV3_MIPI_IMAGE_SENSOR_FULL_WIDTH;
        pParaOut->ExposureWindowHeight = ET8EV3_MIPI_IMAGE_SENSOR_FULL_HEIGHT;

    }

	ET8EV3MipiSetMirrorFlip(pParaIn->ImageMirror);
	

    if (ET8EV3MipiSensorStatus.PvMode==KAL_TRUE)
    	{
    	  //Small Size Shutter Conversion 
          // No need to Change since it is already preview shutter  
          ShutterTemp=ShutterTemp;
    	}
    else 
        {
 
 		// Large Size Shutter Conversion  		
        ShutterTemp=(ShutterTemp*ET8EV3MipiSensorStatus.CapPclk/ET8EV3MipiSensorStatus.PrvPclk);    // Changed with Preview Clk and Capture Clock
	#ifdef __ET8EV3_MIPI_DBG__
		kal_wap_trace(MOD_ENG,TRACE_INFO,"ET8EV3MipiCapture(): Calculating1: ShutterTemp =%d,",(int)(ShutterTemp));
	#endif
	
		ShutterTemp=(ShutterTemp*(ET8EV3MipiSensorStatus.PvLineLength+ET8EV3MipiSensorStatus.PvDummyPixels)/(ET8EV3MipiSensorStatus.CapLineLength+ET8EV3MipiSensorStatus.CapDummyPixels)); // Changed with Preview Line length and Capture Line length
	#ifdef __ET8EV3_MIPI_DBG__
		kal_wap_trace(MOD_ENG,TRACE_INFO,"ET8EV3MipiCapture(): Calculating2: ShutterTemp =%d,",(int)(ShutterTemp));
	#endif
       }

    if(ShutterTemp<1)
        ShutterTemp=1;
	
   ET8EV3MipiWriteShutter(ShutterTemp&0x0000FFFF);

} /* ET8EV3MipiCapture() */

void ET8EV3MipiGetCaptureFlashlightInfo(P_FLASHLIGHT_CAPTURE_SENSOR_PARA_IN_STRUCT pParaIn, P_FLASHLIGHT_CAPTURE_PARA_STRUCT pCaptureInfo)
{
    if(KAL_TRUE==ET8EV3MipiSensorStatus.PvMode)
    {
        #ifdef CAM_OFFLINE_CAPTURE
            pCaptureInfo->default_pclk = 66000000;
        #else
            pCaptureInfo->default_pclk = 66000000;
        #endif
    }
    else
    {
        #ifdef CAM_OFFLINE_CAPTURE
            pCaptureInfo->default_pclk = 80000000;
		#elif CAM_OTF_CAPTURE
            if(pParaIn->DigitalZoomFactor<200)
                pCaptureInfo->default_pclk = 75000000;
            else if(pParaIn->DigitalZoomFactor<=400)
                pCaptureInfo->default_pclk = 75000000;
            else
                pCaptureInfo->default_pclk = 26000000;
       #else//CAM_STANDARD_CAPTURE
            if(pParaIn->DigitalZoomFactor>100)
                pCaptureInfo->default_pclk = 75000000;
            else	
                pCaptureInfo->default_pclk = 26000000;
       #endif
				
    }
    pCaptureInfo->pixels = ET8EV3MipiSensorStatus.CapLineLength;
    pCaptureInfo->frame_lines = ET8EV3MipiSensorStatus.CapFrameLength;
    pCaptureInfo->lines = ET8EV3_MIPI_IMAGE_SENSOR_FULL_HEIGHT;
    pCaptureInfo->shutter = ET8EV3MipiSensorStatus.CapShutter;
    //Shutter = flashlight_sensor_capture_config(&flashlight_capture_para, pParaIn);    
    
}

static void ET8EV3MipiVideo(CAL_SCENARIO_ENUM ScenarioId,
                               P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT pParaIn,
                               P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT pParaOut)
{	

    ET8EV3MipiSensorStatus.PvDummyPixels=0;
    ET8EV3MipiSensorStatus.PvDummyLines=0;
    
#ifdef __PREVIEW_1_4_FULL_SIZE
		ET8EV3MipiSetSXGA_Preview(ET8EV3_MIPI_8BIT_RAW);
#else
	#ifdef __PREVIEW_720P__
		ET8EV3MipiSetXGA_720P(ET8EV3_MIPI_8BIT_RAW);
	#else
		ET8EV3MipiSetXGA_VGA(ET8EV3_MIPI_8BIT_RAW);
	#endif
#endif

	ET8EV3MipiFixVideoFrameRate(pParaIn->MaxVideoFrameRate);

	ET8EV3MipiSetMirrorFlip(pParaIn->ImageMirror);

    pParaOut->GrabStartX = 1;
    pParaOut->GrabStartY = 2;
    pParaOut->ExposureWindowWidth = ET8EV3_MIPI_IMAGE_SENSOR_PV_WIDTH;
    pParaOut->ExposureWindowHeight = ET8EV3_MIPI_IMAGE_SENSOR_PV_HEIGHT;
   
    ET8EV3MipiWriteShutter(ET8EV3MipiSensorStatus.ExposureLines);

}/* ET8EV3MipiPreview */

MM_ERROR_CODE_ENUM ET8EV3MipiBinningInfo(P_CAL_FEATURE_CTRL_STRUCT pFeatureParaIn,
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
}   /* ET8EV3MipiBinningInfo() */

MM_ERROR_CODE_ENUM ET8EV3MipiStillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT pFeatureParaIn,
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
}   /* ET8EV3MipiStillCaptureSize() */

void ET8EV3MipiInitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT pInitOperPara)
{
	pInitOperPara->CaptureDelayFrame = 3;			/* wait stable frame when sensor change mode (pre to cap) */
	pInitOperPara->PreviewDelayFrame = 2;			/* wait stable frame when sensor change mode (cap to pre) */
	pInitOperPara->PreviewDisplayWaitFrame = 2;	/* wait stable frame when sensor change mode (cap to pre) */
	pInitOperPara->AeCalDelayFrame = 0;			/* The frame of calculation default 0 */
	pInitOperPara->AeShutDelayFrame = 1;			/* The frame of setting shutter default 0 for TG int */
	pInitOperPara->AeSensorGainDelayFrame = 2;	/* The frame of setting sensor gain */
	pInitOperPara->AeIspGainDelayFrame = 3;		/* The frame of setting gain */
	pInitOperPara->AeCalPeriod = 4;				/* AE AWB calculation period */
	#if(defined(XENON_FLASHLIGHT_ANTI_RED_EYE))
       	pInitOperPara->FlashlightMode = FLASHLIGHT_XENON_IGBT;
	#elif(defined(XENON_FLASHLIGHT))
       	pInitOperPara->FlashlightMode = FLASHLIGHT_XENON_SCR;
	#elif(defined(LED_FLASHLIGHT_SUPPORT))
       	pInitOperPara->FlashlightMode = FLASHLIGHT_LED_CONSTANT;
	#elif(defined(LED_ONOFF_SUPPORT))
       	pInitOperPara->FlashlightMode = FLASHLIGHT_LED_ONOFF;
	#else
       	pInitOperPara->FlashlightMode = FLASHLIGHT_NONE;
	#endif
  pInitOperPara->FlashlightDeltaMainLum = 65;    // 1.015*64(1.015X)
} /* ET8EV3MipiInitOperationPara() */

void ET8EV3MipiDscSupportInfo(P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT pDscSupportInfo)
{
    kal_mem_cpy(pDscSupportInfo, &ET8EV3_MIPI_dsc_support_info, sizeof(camcorder_info_struct));
} /* ET8EV3MipiDscSupportInfo() */


MM_ERROR_CODE_ENUM ET8EV3MipiSensorFeatureCtrl(kal_uint32 FeatureId,
                                                void* pFeatureParaIn, void* pFeatureParaOut,
                                                kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

    if ((FeatureId>=CAL_FEATURE_WEBCAM_BEGIN)&&
        (FeatureId<=CAL_FEATURE_WEBCAM_END))
    {
        ErrorCode=ET8EV3MipiWebcamFeatureCtrl(FeatureId, pFeatureParaIn, pFeatureParaOut,
                                               FeatureParaOutLen, pRealFeatureParaOutLen);
        return ErrorCode;
    }
    // for the features that not support in the sensor, then it is not necessary to implement it.
    switch (FeatureId)
    {
        /*get*/
        case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
            ET8EV3MipiGetSensorInfo((P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT) pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_MIPI_INFO:
            ET8EV3MipiGetMipiInfo((P_IMAGE_SENSOR_MIPI_PARA_IN_STRUCT)pFeatureParaIn,(P_IMAGE_SENSOR_MIPI_PARA_OUT_STRUCT) pFeatureParaOut);
            FeatureParaOutLen = sizeof(P_IMAGE_SENSOR_MIPI_PARA_OUT_STRUCT);
            *pRealFeatureParaOutLen = sizeof(P_IMAGE_SENSOR_MIPI_PARA_OUT_STRUCT);            
        break;        
        case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
            ((P_IMAGE_SENSOR_COMM_DATA_STRUCT) pFeatureParaOut)->FeatureValue=ET8EV3MipiDetectSensorId();
        break;
        case IMAGE_SENSOR_FEATURE_GET_PREVIEW_FLASHLIGHT_INFO:
            ET8EV3MipiGetPreviewFlashlightInfo((P_FLASHLIGHT_PREVIEW_PARA_STURCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_CAPTURE_FLASHLIGHT_INFO:
            ET8EV3MipiGetCaptureFlashlightInfo((P_FLASHLIGHT_CAPTURE_SENSOR_PARA_IN_STRUCT)pFeatureParaIn, (P_FLASHLIGHT_CAPTURE_PARA_STRUCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_AE_INFO:
            ET8EV3MipiGetSensorAeInfo((P_IMAGE_SENSOR_AE_INFO_STRUCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_AE_LUT:
            ET8EV3MipiGetAeLut((P_AE_LUT_INFO_STRUCT) pFeatureParaIn, (P_IMAGE_SENSOR_AE_LUT_STRUCT)pFeatureParaOut,
                                FeatureParaOutLen, pRealFeatureParaOutLen);
        break;
        case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
            ((P_IMAGE_SENSOR_COMM_DATA_STRUCT) pFeatureParaOut)->FeatureValue=ET8EV3MipiSensorStatus.VideoCurrentFrameRate;
        break;
        case IMAGE_SENSOR_FEATURE_GET_SHADING_TABLE:
            ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        break;
        case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
            ET8EV3MipiInitOperationPara((P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_DSC_SUPPORT_INFO:
            ET8EV3MipiDscSupportInfo((P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
            pET8EV3MipiNvramSensorData = &(((nvram_camera_para_struct *) pFeatureParaIn)->SENSOR);
        break;
        case IMAGE_SENSOR_FEATURE_GET_GAIN:
            ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaOut)->FeatureValue=ET8EV3MipiReadGain();
        break;
        case IMAGE_SENSOR_FEATURE_GET_ENG_INFO:
            ((P_SENSOR_INFO_STRUCT)pFeatureParaOut)->id = ET8EV3_MIPI_g_CCT_MainSensor.id;
            ((P_SENSOR_INFO_STRUCT)pFeatureParaOut)->type = ET8EV3_MIPI_g_CCT_MainSensor.type;
        break;
        case IMAGE_SENSOR_FEATURE_GET_CCT_GROUP_COUNT:
            ET8EV3MipiGetSensorGroupCount((kal_int32*)pFeatureParaOut);
        break;
        case IMAGE_SENSOR_FEATURE_GET_CCT_GROUP_INFO:
            ET8EV3MipiGetSensorGrouinfo(((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaIn)->GroupNamePtr, &((P_CAL_CCT_SENSOR_GROUP_INFO_STRUCT)pFeatureParaOut)->ItemCount);
        break;  
        case IMAGE_SENSOR_FEATURE_GET_CCT_ITEM_INFO:
            ET8EV3MipiGetSensorItemInfo(((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemIdx, (P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaOut);
        break;
		
		/*set*/
        case IMAGE_SENSOR_FEATURE_SET_ESHUTTER:
            ET8EV3MipiSetShutter(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
        break;
        case IMAGE_SENSOR_FEATURE_SET_GAIN:
            ET8EV3MipiSetGain(((P_IMAGE_SENSOR_COMM_DATA_STRUCT)pFeatureParaIn)->FeatureValue);
        break;
        case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
            ET8EV3MipiSensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT) pFeatureParaIn)->ImageSensorIdx;
        break;
	    case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
            CamPdnPinCtrl(ET8EV3MipiSensorIdx, 1);
	        CamRstPinCtrl(ET8EV3MipiSensorIdx, 0);
        break;
        case IMAGE_SENSOR_FEATURE_SET_CCT_ITEM_INFO:
            ET8EV3MipiSetSensorItemInfo(((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->GroupIdx,((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemIdx, ((P_CAL_CCT_SENSOR_ITEM_INFO_STRUCT)pFeatureParaIn)->ItemValue);
        break;		
		
        case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE:
            ET8EV3MipiNightMode(((P_IMAGE_SENSOR_COMM_CTRL_STRUCT)pFeatureParaIn)->FeatureEnable);
        break;
        case IMAGE_SENSOR_FEATURE_CTRL_FLASHLIGHT:
            ET8EV3MipiSetFlashlight(((P_IMAGE_SENSOR_COMM_CTRL_STRUCT)pFeatureParaIn)->FeatureEnable);
        break;

        case CAL_FEATURE_CAMERA_BINNING_INFO:
            ErrorCode=ET8EV3MipiBinningInfo((P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaIn,
                                             (P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaOut, FeatureParaOutLen, pRealFeatureParaOutLen);
        break;
        // customized by customer
        case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
            ErrorCode=ET8EV3MipiStillCaptureSize((P_CAL_FEATURE_CTRL_STRUCT)pFeatureParaIn,
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
            // Put here just for notifying DD colleagues. Should be removed later for ET8EV3. PC Huang 20100903
            ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        break;
        // the above are for YUV sensor only
        case CAL_FEATURE_CCT_OP_CAMERA_PARA_TO_SENSOR:
            ET8EV3MipiCameraParaToSensor(pFeatureParaIn);
        break;
        case CAL_FEATURE_CCT_OP_SENSOR_TO_CAMERA_PARA:
            ET8EV3MipiSensorToCameraPara(pFeatureParaOut);
        break;
        
        default:
            ErrorCode=MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        break;
    }
    return ErrorCode;
} /* ET8EV3MipiSensorFeatureCtrl() */

MM_ERROR_CODE_ENUM ET8EV3MipiSensorCtrl(CAL_SCENARIO_ENUM ScenarioId, void *pParaIn,
                                         void *pParaOut, kal_uint16 ParaOutLen)
{
    MM_ERROR_CODE_ENUM ErrorCode=MM_ERROR_NONE;

    switch (ScenarioId)
    {
        case CAL_SCENARIO_CAMERA_PREVIEW:
        case CAL_SCENARIO_WEBCAM_PREVIEW:
        case CAL_SCENARIO_WEBCAM_CAPTURE:
            ET8EV3MipiPreview(ScenarioId, pParaIn, pParaOut);
        break;
        case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
            ET8EV3MipiCapture(ScenarioId, pParaIn, pParaOut);
        break;
		case CAL_SCENARIO_VIDEO:
			ET8EV3MipiVideo(ScenarioId, pParaIn, pParaOut);		
        default:
        break;
    }
    return ErrorCode;
}

MM_ERROR_CODE_ENUM ET8EV3MipiSensorClose(void)
{
	  /* power down sensor */
	  CamWriteCmosSensor(0x0100,0x0000);//MODE_SEL/VREVON/HREVON/SWRST/GRHOLD/-/-/OUT_FORMAT;					  
	  CamPdnPinCtrl(ET8EV3MipiSensorIdx, 1);
	  CamRstPinCtrl(ET8EV3MipiSensorIdx, 0);
      CisModulePowerOn(ET8EV3MipiSensorIdx, KAL_FALSE);
	  CameraSccbClose(CAMERA_SCCB_SENSOR);

    return MM_ERROR_NONE;
}


IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncET8EV3Mipi=
{
    ET8EV3MipiSensorOpen,
    ET8EV3MipiSensorFeatureCtrl,
    ET8EV3MipiSensorCtrl,
    ET8EV3MipiSensorClose,
};

MM_ERROR_CODE_ENUM ET8EV3MipiSensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
	*pfSensorFunc=&ImageSensorFuncET8EV3Mipi;
}	/* cam_module_func_config() */


void at_test_func(kal_uint32 *d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (d[1])
    {
	case 0:
		
		break;
	case 1:
		//cb_config(SCCB_SW_8BIT, d[2], d[3], NULL);
		kal_prompt_trace(MOD_ENG, "SCCB Config %x %x", d[2], d[3]);
		break;
	case 2:
		/* Michael add to set and read BB register. 2008-06-30 */
		kal_wap_trace(MOD_ENG,TRACE_INFO, "Read BB Reg %x = %x", d[2], DRV_Reg32((d[2])));
		kal_wap_trace(MOD_ENG,TRACE_INFO, "Read BB Reg %x = %x", 0x840b0024, DRV_Reg32(0x840b0024));
		break;
	case 3:
		/* Michael add to set and read BB register. 2008-06-30 */
		DRV_Reg32((d[2])) = d[3];
		kal_wap_trace(MOD_ENG,TRACE_INFO, "Write BB Reg %x = %x", d[2], DRV_Reg32((d[2])));
		break;
	case 4:
		kal_wap_trace(MOD_ENG,TRACE_INFO, "Read Sensor %x = %x", d[2], CamReadCmosSensor(d[2]));
		break;
	case 5:
		CamWriteCmosSensor(d[2], d[3]);
		kal_wap_trace(MOD_ENG,TRACE_INFO, "Write Sensor %x = %x", d[2], CamReadCmosSensor(d[2]));
		break;
	case 6:
		ET8EV3MipiWriteShutter(ET8EV3MipiSensorStatus.ExposureLines);
		break;
	case 7:
		ET8EV3MipiReadShutter();
		break;
	case 8:
		ET8EV3MipiSetGain(d[2]);
		break;
	case 9:
		ET8EV3MipiReadSensorGain();
		break;
	case 10:
	//	write_S5K4E2FX_gain(d[2]);
		
		kal_wap_trace(MOD_ENG,TRACE_INFO, "write_ET8EV3_Gain",d[2]);
		break;
	case 11:
		{
			kal_uint32 get_current_frame_rate(void);
			
			//l_prompt_trace(MOD_ENG, "Current FPS = %d", get_current_frame_rate());
		}
		break;
	case 12:
		{
			//extern kal_bool dynamic_setting_flag;
		//	dynamic_setting_flag = d[2];
		}
	case 13:
		for (i = d[2]; i < d[3]; i++)
		{
			//l_prompt_trace(MOD_ENG, "Reg[%x] = %x", i, S5K4E2FX_read_cmos_sensor(i));
		}
		break;
	case 15:
		{
			static kal_uint8 flg = 0;
			/* Michael add to test the gpio pin. 2008-06-28 */
			GPIO_ModeSetup(d[2],0);
			GPIO_InitIO(1,d[2]);
			GPIO_WriteIO(flg, d[2]);
			flg = (flg == 1) ? 0 : 1;
		}
		break;
    }
}



