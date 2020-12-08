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
 *   camera_tuning_para.c
 *
 * Project:
 * --------
 *   MT6238
 *
 * Description:
 * ------------
 *   Camera Parameter for Micron 3M Sensor (MT9T012)
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------

 ****************************************************************************/
#include "drv_features.h"

#if (defined(DRV_ISP_6238_SERIES))

#if !defined(ISP_SUPPORT)
	// DO NOT delete this section!!! 
	// When ISP_SUPPORT is not defined, NVRAM still need the dummy structure 
	// and default value to initialize NVRAM_EF_CAMERA_PARA_LID.             
	#include "camera_para.h"
	const nvram_camera_para_struct SIV120B_DIRECT_CAMERA_PARA_DEFAULT_VALUE={0};
#else
#include "camera_para.h"
#include "camera_sensor_para_SIV120B_DIRECT.h"
#include "camera_af_para.h"

#define SIV120B_DIRECT_CAMERA_SENSOR_CCT_DEFAULT_VALUE {{ 0xFFFFFFFF, 0x08 } ,{ 0x0209, 0x0008 } ,{ 0x0207, 0x0008 } ,{ 0x020D, 0x0008 } ,{ 0x020B, 0x0008 }}


const nvram_camera_para_struct SIV120B_DIRECT_CAMERA_PARA_DEFAULT_VALUE=
{
	/* STRUCT: ISP */
	{
		/* ARRAY: ISP.reg[144+8] */
		{
      0xA4021842, 0x1FFF0FFF, 0x000203FD, 0x000202FF,         // CAM+000h~00Ch ,0
			0x00300091, 0xA8A8A8A8, 0x00000040, 0x00000081,         // CAM+010h~01Ch ,4
			0x00000000, 0x06000030, 0x40010000, 0x40030000,         // CAM+020h~02Ch ,8 
			0x80FF0100, 0x00800080, 0x00800080, 0x00000000,         // CAM+030h~03Ch ,12
			0x00000000, 0x03C9A800, 0x0880081F, 0x0000043F,         // CAM+040h~04Ch ,16
			0x00000000, 0x00000008, 0x00408010, 0xFF0190B7,         // CAM+050h~05Ch ,20
			0x00000000, 0x10107000, 0x40404040, 0x00800080,         // CAM+060h~06Ch ,24
			0x00800080, 0x000000F1, 0x000001A0, 0x00000000,         // CAM+070h~07Ch ,28
			0x00000000, 0x00000000, 0x00000000, 0x00000000,         // CAM+080h~08Ch ,32
			0x00000000, 0x00000000, 0x00000000, 0x00000000,         // CAM+090h~09Ch ,36
			0x00000000, 0x00000000, 0x00000000, 0x00000000,         // CAM+0A0h~0ACh ,40
			0x00000000, 0x00000000, 0x00000000, 0x00000000,         // CAM+0B0h~0BCh ,44
			0x00000000, 0x00000000, 0x00000000, 0x00000000,         // CAM+0C0h~0CCh ,48
			0x00000000, 0x00000000, 0x00000000, 0x00000000,         // CAM+0D0h~0DCh ,52
			0x00000000, 0x00000000, 0x00000000, 0x00000000,         // CAM+0E0h~0ECh ,56
			0x00000000, 0x00000000, 0x00000000, 0x00000000        // CAM+0F0h~0FCh ,60
			
		}
	},
   //ISPTUNING
    {
                //idx
                {
						0x0,0x3,0x3,0x3,0x1,0x1,0x1,0x0
                },
          
                //shadingReg
                {
                        {
                            0x30000000, 0x4066207F, 0x40000000, 0x0064007E,0x19191919	//Preview
                        },
                        {
                            0x30000000, 0x60924098, 0x40000000, 0x008C0094,0x19191919	//Capture
                        },                        
                        {
                            0x30000000, 0x6048404B, 0x40000000, 0x004A004C,0x19191919	//Binning
                         }
                },

                //nr1Reg
                {
                        {
                          0x000000F5, 0x000650A0, 0x00000678, 0x02040608,
                          0x08080808, 0x02040608, 0x08080808, 0x02040608,
                          0x08080808, 0x02040608, 0x08080808
                        },
                       {
                          0x000000F5, 0x000750A0, 0x00000678, 0x04060808,
                          0x08080808, 0x04060808, 0x08080808, 0x04060808,
                          0x08080808, 0x04060808, 0x08080808
                        },
                       {
                          0x000000F5, 0x000750A0, 0x00000678, 0x06080A0A,
                          0x08080808, 0x06080A0A, 0x08080808, 0x06080A0A,
                          0x08080808, 0x06080A0A, 0x08080808
                        },
                       {
                          0x000000F5, 0x000750A0, 0x00000678, 0x06080A0A,
                          0x08080808, 0x06080A0A, 0x08080808, 0x06080A0A,
                          0x08080808, 0x06080A0A, 0x08080808
                        },
                       {
                          0x000000F5, 0x000850A0, 0x00000678, 0x06080A0A,
                          0x08080808, 0x06080A0A, 0x08080808, 0x06080A0A,
                          0x08080808, 0x06080A0A, 0x08080808
                        },
                       {
                          0x000000F5, 0x000850A0, 0x00000678, 0x06080A0A,
                          0x08080808, 0x06080A0A, 0x08080808, 0x06080A0A,
                          0x08080808, 0x06080A0A, 0x08080808
                        },
                       {
                          0x000000F5, 0x000890A0, 0x00000678, 0x0F0F0F0F,
                          0x0F0F0F0F, 0x0F0F0F0F, 0x0F0F0F0F, 0x0F0F0F0F,
                          0x0F0F0F0F, 0x0F0F0F0F, 0x0F0F0F0F
                        }

                },


                //nr2Reg
                {
                       {
                          0x00000003, 0x00000000, 0x00942266, 0x02040606, 0x02040606
                        },
                       {
                          0x00000003, 0x00000000, 0x00942266, 0x03050707, 0x03050707
                        },
                       {
                          0x00000003, 0x00000000, 0x00942277, 0x04060808, 0x04060808
                        },
                       {
                          0x00000003, 0x00000000, 0x009C3388, 0x06080A0A, 0x06080A0A
                        },
                       {
                          0x00000003, 0x00000000, 0x00A44488, 0x06080A0A, 0x06080A0A
                        },
                       {
                          0x00000003, 0x00000000, 0x00A44488, 0x080A0C0C, 0x080A0C0C
                        },
                       {
                          0x00000003, 0x00000000, 0x00A44488, 0x0A0C0E0E, 0x0A0C0E0E
                        }
                },
                        
                //edgeReg
                {
                       {
                          0x4002086C, 0x00200804, 0x06060404
                        },
                       {
                          0x20020821, 0x000C0806, 0x04030201
                        },
                       {
                          0x30020821, 0x00080402, 0x0A080604
                        },
                       {
                          0x30020821, 0x00080402, 0x0C0A0806
                        },
                       {
                          0x40020821, 0x00080402, 0x1814100C
                        },
                       {
                          0x60020821, 0x00080402, 0x1A16120E
                        },
                       {
                           0x60020821, 0x00080402, 0x1A16120E
                        }
                 },

                //autodefect
                {
                        {
                            0x000000F5, 0x50285050, 0x006003A0, 0x00300050,0x00000895
                        },
                        {
                            0x000000F5, 0x50285050, 0x006003A0, 0x00300050,0x00000895
                        },

                        {
                            0x000000F5, 0x50285050, 0x006003A0, 0x00300050,0x00000895
                         }
                },
                            
                //saturation
                {
                        {
                            0x00000001, 0x1020E0F0, 0x081E1E1E, 0x080A0000
                        },
                        {
                            0x00000001, 0x1020E0F0, 0x20464846, 0x200A0000
                        },
                        {
                            0x00000001, 0x1020E0F0, 0x244A4C4A, 0x240A0000
                        },
                        {
                            0x00000001, 0x1020E0F0, 0x284C4E4C, 0x240A0000
                        },

                        {
                            0x00000001, 0x1020E0F0, 0x284C4E4C, 0x240A0000
                        },
                        {
                            0x00000001, 0x1020E0F0, 0x284C4E4C, 0x240A0000
                        },

                        {
                            0x00000001, 0x1020E0F0, 0x284C4E4C, 0x240A0000
                         }
                },

                //contrast
                {
                       {
                          0x00000009, 0x400F0000, 0xFF00003D
                        },
                       {
                          0x00000009, 0x40000000, 0xFF000040
                        },
                       {
                          0x00000009, 0x40E20000, 0xFF000049
                        }
                }

   	   
     },

     //MShutter
     {  
        0x000001F4, 0x00000000        
     },

	{SIV120B_DIRECT_CAMERA_SENSOR_REG_DEFAULT_VALUE,
	 SIV120B_DIRECT_CAMERA_SENSOR_CCT_DEFAULT_VALUE,
	}

};




#endif //#if !defined(ISP_SUPPORT)

#endif //#if (defined(DRV_ISP_6238_SERIES))


#if(defined(DRV_ISP_6235_SERIES))
#if !defined(ISP_SUPPORT)
	// DO NOT delete this section!!! 
	// When ISP_SUPPORT is not defined, NVRAM still need the dummy structure 
	// and default value to initialize NVRAM_EF_CAMERA_PARA_LID.             
	#include "camera_para.h"
	const nvram_camera_para_struct SIV120B_DIRECT_CAMERA_PARA_DEFAULT_VALUE={0};
#else

//#else
#include "isp_if.h"
#include "image_sensor.h"
#include "camera_para.h"
#if defined(__CAMERA_NVRAM_REDUCTION__)
const nvram_camera_para_struct SIV120B_DIRECT_CAMERA_PARA_DEFAULT_VALUE=
{CAMERA_NVRAM_REDUCTION_DEFAULT_VALUE};
#else


const nvram_camera_para_struct SIV120B_DIRECT_CAMERA_PARA_DEFAULT_VALUE=
{
	/* STRUCT: ISP */
	{
		/* ARRAY: ISP.reg[144] */
		{
			0xA3020074, 0x0FFF0FFF, 0x006302E6, 0x00310212, 
			0x00000001, 0x80808080, 0x00000040, 0x0000000F, 
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 
			0x88002104, 0x00C60080, 0x00900080, 0x03070BF8, 
			0xFF000000, 0x00610940, 0x000D000A, 0x0D1A000A, 
			0x1A27000A, 0x000D0A14, 0x0D1A0A14, 0x1A270A14, 
			0x000D141E, 0x0D1A141E, 0x1A27141E, 0x05230519, 
			0x00000001, 0x0A0A1910, 0x00000514, 0x061FC810, /*COREH=6,COREH2=1F,CORE_CON=10*/
			0x81080802, 0x08080002, 0x24108F0F, 0x101F8224, /*HA=1,HB=8,VB=8,VA=2,VC=2,HC=2,ETH3=24,E_TH1_V=10*/		
			0x003F2F3C, 0x84131204, 0x1E1B0303, 0x003D9785, 
			0x008A378E, 0x00859137, 0x00202020, 0x00000048, 
			0x00888888, 0x008A8A8A, 0x00428030, 0x20200000, 			
			0x00FF91B8, 0x00018080, 0x284E6778, 0x91A8C0D7,			
			0xE1EBF500, 0x00000000, 0x00000000, 0x00000000,			
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 
			0x00000000, 0x00000000, 0x00000000, 0x00008000, 
			0x245C5C24, 0x245C5C24, 0x12000200, 0x12800280, 
			0x00325065, 0x7694AEC5, 0xDAE4EDF7, 0x32506576, 
			0x94AEC5DA, 0xE4EDF700, 0x32506576, 0x94AEC5DA, 
			0xE4EDF700, 0x00040000, 0x40045100, 0x00000000, 
			0x32506576, 0x94AEC5DA, 0xE4EDF700, 0x00800080, 
			0x00800080, 0x00000096, 0x000000C8, 0x00000000, 
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 
			0x00000000, 0x00000000, 0x00000000, 0xF8000000, 
			0xA0A00000, 0x00000000, 0x00000000, 0x00000000, 
			0x60708090, 0xA0B0C0D0, 0xE0F00000, 0x00000000, 
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 
			0x00000000, 0x00000000, 0x00000000, 0x00000000, 
			0x00000000, 0x1246731D, 0x6E645AFF, 0x02204163, 
			0xAAAAD0E2, 0xFFFFFFFF, 0x204163AA, 0xAAD0E2FF, 
			0xFFFFFF00, 0x204163AA, 0xAAD0E2FF, 0xFFFFFF00, 
			0x00000000, 0x00000000, 0x00000000, 0x161B1015, 
			0x00000000, 0x00000000, 0x00000000, 0x00000000  
		}
	},

	/* STRUCT: PREDGAMMA */
	{
		/* PREDGAMMA.gamma_select */ 0x00, 		/* ARRAY: PREDGAMMA.gamma[9][11] */
		{
			/* ARRAY: PREDGAMMA.gamma[0][11] */
			{
				0x28, 0x4E, 0x67, 0x78, 0x91, 0xA8, 0xC0, 0xD7, 
				0xE1, 0xEB, 0xF5
			},

			/* ARRAY: PREDGAMMA.gamma[1][11] */
			{
				0x20, 0x3C, 0x55, 0x69, 0x8D, 0xA8, 0xC0, 0xD7, 
				0xE1, 0xEB, 0xF5
			},

			/* ARRAY: PREDGAMMA.gamma[2][11] */
			{
				0x14, 0x28, 0x46, 0x64, 0x91, 0xB4, 0xCE, 0xE0, 
				0xE8, 0xF0, 0xF8
			},

			/* ARRAY: PREDGAMMA.gamma[3][11] */
			{
				0x49, 0x64, 0x78, 0x88, 0xA4, 0xBA, 0xCE, 0xE0, 
				0xE8, 0xF0, 0xF8
			},

			/* ARRAY: PREDGAMMA.gamma[4][11] */
			{
				0x29, 0x59, 0x75, 0x88, 0xA4, 0xBA, 0xCE, 0xE0, 
				0xE8, 0xF0, 0xF8
			},

			/* ARRAY: PREDGAMMA.gamma[5][11] */
			{
				0x14, 0x30, 0x50, 0x69, 0x87, 0xA5, 0xBE, 0xD7, 
				0xE1, 0xEB, 0xF5
			},

			/* ARRAY: PREDGAMMA.gamma[6][11] */
			{
				0x17, 0x30, 0x53, 0x74, 0x99, 0xAB, 0xBE, 0xD7, 
				0xE1, 0xEB, 0xF5
			},

			/* ARRAY: PREDGAMMA.gamma[7][11] */
			{
				0x30, 0x49, 0x5D, 0x6F, 0x8D, 0xA8, 0xC0, 0xD7, 
				0xE1, 0xEB, 0xF5
			},

			/* ARRAY: PREDGAMMA.gamma[8][11] */
			{
				0x10, 0x20, 0x30, 0x40, 0x60, 0x80, 0xA0, 0xC0, 
				0xD0, 0xE0, 0xF0
			}
		}
	},

	/* STRUCT: Comp */
	{
		/* STRUCT: shading_cap */
		{
				0x14846638, 0x6E645AFF, 0x02204163, 0x868DAABB,
				0xDAEEFFFF, 0x20416386, 0x8DAABBDA, 0xEEFFFF00,
				0x20416386, 0x8DAABBDA, 0xEEFFFF00             
		},
		/* ARRAY: COMP.autodefect_pre_low[2] */
		{
			0xF8000000, 0x14142020
		},

		/* ARRAY: COMP.autodefect_cap_nor[2] */
		{
			0xF8000000, 0x64640000
		},

		/* ARRAY: COMP.autodefect_cap_low[2] */
		{
			0xF8000000, 0x14140000
		},
		/* STRUCT: shading_spare_1 */
		{
				0x00000000, 0x00000000, 0x00204060, 0x8090A0B0,
				0xC0D0E0F0, 0x20406080, 0x90A0B0C0, 0xD0E0F000,
				0x20406080, 0x90A0B0C0, 0xD0E0F000             
		},
		/* STRUCT: shading_spare_2 */
		{
				0x00000000, 0x00000000, 0x00204060, 0x8090A0B0,
				0xC0D0E0F0, 0x20406080, 0x90A0B0C0, 0xD0E0F000,
				0x20406080, 0x90A0B0C0, 0xD0E0F000
		}		
	},

	/* STRUCT: AE */
	{
		/* AE.iniShutter */ 0x0118, /* AE.TargetLum */ 0x5A, /* AE.StepperEV */ 0x02, 40
	},

	/* STRUCT: AWB */
	{
		/* ARRAY: AWB.LightSource[5][4] */
		{
			/* ARRAY: AWB.LightSource[0][4] */
			{
				0x1D4C, 0x00BC, 0x0080, 0x0080, 0x0080
			},

			/* ARRAY: AWB.LightSource[1][4] */
			{
				0x1964, 0x00BC, 0x0080, 0x0089, 0x0080
			},

			/* ARRAY: AWB.LightSource[2][4] */
			{
				0x0FA0, 0x009C, 0x0080, 0x00C0, 0x0080
			},

			/* ARRAY: AWB.LightSource[3][4] */
			{
				0x0ED8, 0x008C, 0x0080, 0x00BD, 0x0080 
			},

			/* ARRAY: AWB.LightSource[4][4] */
			{
				0x0AF0, 0x0080, 0x0080, 0x00CC, 0x0080
			}
		},
		/* ARRAY: MAX AWB */
		0x009D, 0x00B2, 0x0120
	},
	/* STRUCT: SENSOR */
	{
		/* ARRAY: SENSOR.reg[34] */
		{
			 { 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }
			,{ 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x00 }, { 0xFFFFFFFF, 0x00 } 
			,{ 0xFFFFFFFF, ISP_DRIVING_8MA }
			//------------------------Engineer mode---------------------------------
		},
		//------------------------CCT mode---------------------------------
		{
		   { 0xFFFFFFFF, 0x00 } ,{ 0xFFFFFFFF, 0x0 } ,{ 0xFFFFFFFF, 0x0 },{ 0xFFFFFFFF, 0x0 },{ 0xFFFFFFFF, 0x0 }
		}
		//------------------------CCT mode---------------------------------	
	},
	{
   	    {64, 64, 64},/* ISO gain */
	    {100, 100, 100}/* ISO value */
	}
};
#endif

#endif

#endif//#if(defined(DRV_ISP_6235_SERIES))

