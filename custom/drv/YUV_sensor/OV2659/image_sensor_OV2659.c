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
 *   image_sensor_OV2659.c
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
 *
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

#define OVT_AUTOUV
//#define OVT_SIM
//#define BINNING_EN
//#define OV2659_DEBUG

/* #define OV2659_DEBUG */
static struct
{
  kal_uint8   Banding;
  kal_bool    NightMode;
  kal_bool    VideoMode;
  kal_uint16  Fps;
  kal_uint32  Pclk;
  kal_uint16  Hblank; /* for calculating shutter step */
  kal_uint16  ShutterStep;
  kal_uint8   IsPVmode;
  kal_uint32  DummyPixels;
  kal_uint32  DummyLines;
  kal_uint32  PreviewPclk;
  kal_uint32  CapturePclk;
  kal_uint32  PreviewShutter;
  kal_uint32  SensorGain;
  IMAGE_SENSOR_INDEX_ENUM SensorIdx;
  sensor_data_struct *NvramData;
} OV2659Sensor0;

static struct
{
  kal_uint8   Banding;
  kal_bool    NightMode;
  kal_bool    VideoMode;
  kal_uint16  Fps;
  kal_uint32  Pclk;
  kal_uint16  Hblank; /* for calculating shutter step */
  kal_uint16  ShutterStep;
  kal_uint8   IsPVmode;
  kal_uint32  PreviewDummyPixels;
  kal_uint32  PreviewDummyLines;
  kal_uint32  CaptureDummyPixels;
  kal_uint32  CaptureDummyLines;
  kal_uint32  PreviewPclk;
  kal_uint32  CapturePclk;
  kal_uint32  PreviewShutter;
  kal_uint32  PreviewExtraShutter;
  kal_uint32  SensorGain;
  IMAGE_SENSOR_INDEX_ENUM SensorIdx;
  sensor_data_struct *NvramData;
} OV2659Sensor;

static kal_uint8 Night_mode_flag=0;
static IMAGE_SENSOR_MIRROR_ENUM ImageMirror;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

#ifdef OV2659_LOAD_FROM_T_FLASH
/*************************************************************************
* FUNCTION
*  OV2659_Initialize_from_T_Flash
*
* DESCRIPTION
*  Read the initialize setting from t-flash or user disk to speed up image quality tuning.
*
* PARAMETERS
*  None
*
* RETURNS
*  kal_uint8 - 0 : Load setting fail, 1 : Load setting successfully.
*
*************************************************************************/
static kal_uint8 OV2659_Initialize_from_T_Flash()
{
#include <stdlib.h>
#include "med_utility.h"
#include "fs_type.h"

#if OV2659_I2C_ADDR_BITS == CAMERA_SCCB_16BIT
    #define OV2659_REG_SKIP    0x08
#else
    #define OV2659_REG_SKIP    0x06
#endif
#if OV2659_I2C_DATA_BITS == CAMERA_SCCB_16BIT
    #define OV2659_VAL_SKIP    0x08
#else
    #define OV2659_VAL_SKIP    0x06
#endif
  
    /* 0 - Initial value, 1 - Register, 2 - Delay, 3 - End of setting. */
    #define OV2659_OP_CODE_INI    0x00    /* Initial value. */
    #define OV2659_OP_CODE_REG    0x01    /* Register */
    #define OV2659_OP_CODE_DLY    0x02    /* Delay */
    #define OV2659_OP_CODE_END    0x03    /* End of initial setting. */

    typedef struct
    {
        kal_uint16 init_reg;
        kal_uint16 init_val;  /* Save the register value and delay tick */
        kal_uint8 op_code;    /* 0 - Initial value, 1 - Register, 2 - Delay, 3 - End of setting. */
    } OV2659_initial_set_struct;
  
    static OV2659_initial_set_struct OV2659_Init_Reg[1000];
    static WCHAR OV2659_set_file_name[256] = {0};
    FS_HANDLE fp = -1;        /* Default, no file opened. */
    kal_uint8 *data_buff = NULL;
    kal_uint8 *curr_ptr = NULL;
    kal_uint32 file_size = 0;
    kal_uint32 bytes_read = 0;
    kal_uint32 i = 0, j = 0;
    kal_uint8 func_ind[3] = {0};  /* REG or DLY */
    
    kal_mem_cpy(OV2659_set_file_name, L"C:\\OV2659_Initialize_Setting.Bin", sizeof(L"C:\\OV2659_Initialize_Setting.Bin"));
    
    /* Search the setting file in all of the user disk. */
    curr_ptr = (kal_uint8 *)OV2659_set_file_name;
    while (fp < 0)
    {
        if ((*curr_ptr >= 'c' && *curr_ptr <= 'z') || (*curr_ptr >= 'C' && *curr_ptr <= 'Z'))
        {
            fp = FS_Open(OV2659_set_file_name, FS_READ_ONLY);
            if (fp >= 0)
            {
                break; /* Find the setting file. */
            }
            *curr_ptr = *curr_ptr + 1;
        }
        else
        {
            break ;
        }
    }
    if (fp < 0)    /* Error handle */
    {
        OV2659_TRACE("!!! Warning, Can't find the initial setting file!!!");
        return 0;
    }
    
    FS_GetFileSize(fp, &file_size);
    if (file_size < 20)
    {
        OV2659_TRACE("!!! Warning, Invalid setting file!!!");
        return 0;      /* Invalid setting file. */
    }
    
    data_buff = med_alloc_ext_mem(file_size);
    if (data_buff == NULL)
    {
        OV2659_TRACE("!!! Warning, Memory not enoughed...");
        return 0;        /* Memory not enough */
    }
    FS_Read(fp, data_buff, file_size, &bytes_read);
    
    /* Start parse the setting witch read from t-flash. */
    curr_ptr = data_buff;
    while (curr_ptr < (data_buff + file_size))
    {
        while ((*curr_ptr == ' ') || (*curr_ptr == '\t'))/* Skip the Space & TAB */
            curr_ptr++;
        if (((*curr_ptr) == '/') && ((*(curr_ptr + 1)) == '*'))
        {
            while (!(((*curr_ptr) == '*') && ((*(curr_ptr + 1)) == '/')))
            {
                curr_ptr++;    /* Skip block comment code. */
            }
            while (!((*curr_ptr == 0x0D) && (*(curr_ptr+1) == 0x0A)))
            {
                curr_ptr++;
            }
            curr_ptr += 2;            /* Skip the enter line */
            continue ;
        }
    
        if (((*curr_ptr) == '/') || ((*curr_ptr) == '{') || ((*curr_ptr) == '}'))    /* Comment line, skip it. */
        {
            while (!((*curr_ptr == 0x0D) && (*(curr_ptr+1) == 0x0A)))
            {
                curr_ptr++;
            }

            curr_ptr += 2;            /* Skip the enter line */

            continue ;
        }
        /* This just content one enter line. */
        if (((*curr_ptr) == 0x0D) && ((*(curr_ptr + 1)) == 0x0A))
        {
            curr_ptr += 2;
            continue ;
        }

        kal_mem_cpy(func_ind, curr_ptr, 3);
        curr_ptr += 4;          /* Skip "REG(" or "DLY(" */
        if (strcmp((const char *)func_ind, "REG") == 0)    /* REG */
        {
            OV2659_Init_Reg[i].op_code = OV2659_OP_CODE_REG;
      
            OV2659_Init_Reg[i].init_reg = strtol((const char *)curr_ptr, NULL, 16);
            curr_ptr += OV2659_REG_SKIP;  /* Skip "0x0000, " */
      
            OV2659_Init_Reg[i].init_val = strtol((const char *)curr_ptr, NULL, 16);
            curr_ptr += OV2659_VAL_SKIP;  /* Skip "0x0000);" */
        }
        else                  /* DLY */
        {
            /* Need add delay for this setting. */
            OV2659_Init_Reg[i].op_code = OV2659_OP_CODE_DLY;
      
            OV2659_Init_Reg[i].init_reg = 0xFF;
            OV2659_Init_Reg[i].init_val = strtol((const char *)curr_ptr, NULL, 10);  /* Get the delay ticks, the delay should less then 50 */
        }
        i++;
    
        /* Skip to next line directly. */
        while (!((*curr_ptr == 0x0D) && (*(curr_ptr+1) == 0x0A)))
        {
            curr_ptr++;
        }
        curr_ptr += 2;
    }

    /* (0xFFFF, 0xFFFF) means the end of initial setting. */
    OV2659_Init_Reg[i].op_code = OV2659_OP_CODE_END;
    OV2659_Init_Reg[i].init_reg = 0xFF;
    OV2659_Init_Reg[i].init_val = 0xFF;
    i++;

    OV2659_TRACE("%d register read...", i - 1);
    med_free_ext_mem((void **)&data_buff);
    FS_Close(fp);

    OV2659_TRACE("Start apply initialize setting.");
    /* Start apply the initial setting to sensor. */
    for (j=0; j<i; j++)
    {
        if (OV2659_Init_Reg[j].op_code == OV2659_OP_CODE_END)  /* End of the setting. */
        {
            break ;
        }
        else if (OV2659_Init_Reg[j].op_code == OV2659_OP_CODE_DLY)
        {
            kal_sleep_task(OV2659_Init_Reg[j].init_val);    /* Delay */
        }
        else if (OV2659_Init_Reg[j].op_code == OV2659_OP_CODE_REG)
        {
            CamWriteCmosSensor(OV2659_Init_Reg[j].init_reg, OV2659_Init_Reg[j].init_val);
        }
        else
        {
            ASSERT(0);
        }
    }
    OV2659_TRACE("%d register applied...", j);
    return 1;  
}
#endif

/*****************************************************************************
 * FUNCTION
 *  OV2659WriteReg
 * DESCRIPTION
 *  This function set the register of OV2659.
 * PARAMETERS
 *  Addr       [IN]        the register index of OV2659
 *  Para       [IN]        setting parameter of the specified register of OV2659
 * RETURNS
 *  void
 *****************************************************************************/
static void OV2659WriteReg(kal_uint32 Addr, kal_uint32 Para)
{
  	CamWriteCmosSensor(Addr,Para);
}

/*****************************************************************************
 * FUNCTION
 *  OV2659ReadReg
 * DESCRIPTION
 *  This function read parameter of specified register from OV2659.
 * PARAMETERS
 *  Addr       [IN]        the register index of OV2659
 * RETURNS
 *  the data that read from OV2659
 *****************************************************************************/
static kal_uint32 OV2659ReadReg(kal_uint32 Addr)
{
  return CamReadCmosSensor(Addr);
}

/*************************************************************************
* FUNCTION
*    OV2659InitialSetting
*
* DESCRIPTION
*    This function initialize the registers of CMOS sensor.
*
* PARAMETERS
*    None
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV2659InitialSetting(void)
{
		OV2659WriteReg(0x3000,0x0F);//io ctrl00 DVP[9:8]
		OV2659WriteReg(0x3001,0xFF);//io ctrl01 DVP[7:0]
		OV2659WriteReg(0x3002,0xFF);//io ctrl02 VSYNC HREF PCLK enable

		OV2659WriteReg(0x0100,0x01);//sw standby bit[0]:1:streaming;0:sw standby

		OV2659WriteReg(0x3633,0x3d); 	
		OV2659WriteReg(0x3620,0x02);	
		OV2659WriteReg(0x3631,0x11); 	
		OV2659WriteReg(0x3612,0x04);

		OV2659WriteReg(0x3630,0x20);
		OV2659WriteReg(0x4702,0x02);
		OV2659WriteReg(0x370c,0x34);

		//////////26*22/2/2/3=47.47///////
		OV2659WriteReg(0x3004,0x10);
		OV2659WriteReg(0x3005,0x16);
		OV2659WriteReg(0x3006,0x0d);
		///24MCLK 48PCLK
		//OV2659WriteReg(0x3004,0x10);
		//OV2659WriteReg(0x3005,0x18);
		//OV2659WriteReg(0x3006,0x0d);

		OV2659WriteReg(0x3800,0x00);
		OV2659WriteReg(0x3801,0x00);
		OV2659WriteReg(0x3802,0x00);
		OV2659WriteReg(0x3803,0x00);
		OV2659WriteReg(0x3804,0x06);
		OV2659WriteReg(0x3805,0x5f);
		OV2659WriteReg(0x3806,0x04);
		OV2659WriteReg(0x3807,0xb7);
		OV2659WriteReg(0x3808,0x03);
		OV2659WriteReg(0x3809,0x20);
		OV2659WriteReg(0x380a,0x02);
		OV2659WriteReg(0x380b,0x58);
		OV2659WriteReg(0x380c,0x05);
		OV2659WriteReg(0x380d,0x14);
		OV2659WriteReg(0x380e,0x02);
		OV2659WriteReg(0x380f,0x68);

		OV2659WriteReg(0x3811,0x08);
		OV2659WriteReg(0x3813,0x02);
		OV2659WriteReg(0x3814,0x31);
		OV2659WriteReg(0x3815,0x31);

		OV2659WriteReg(0x3800,0x38);//disable exposure less than 1 line//Tony_8_31
		//////////////////////////////////////////
		////////////////50HZ//////////////////
		OV2659WriteReg(0x3a00, 0x38); // disable exposure less than 1 line. enable banding, exposure less than banding
		OV2659WriteReg(0x3a02, 0x02);	// max exposure 60Hz
		OV2659WriteReg(0x3a03, 0x68);	// max exposure 60Hz
		OV2659WriteReg(0x3a08, 0x00);	// B50
		OV2659WriteReg(0x3a09, 0xb8);	// B50
		OV2659WriteReg(0x3a0a, 0x00);	// B60
		OV2659WriteReg(0x3a0b, 0x99);	// B60
		OV2659WriteReg(0x3a0d, 0x04);	// max band 60Hz
		OV2659WriteReg(0x3a0e, 0x03);	// max band 50Hz
		OV2659WriteReg(0x3a14, 0x02);	// max exposure 50Hz
		OV2659WriteReg(0x3a15, 0x28);	// max exposure 50Hz
		OV2659WriteReg(0x3a05, 0x30);	// select 50hz banding filter
		// night mode
		OV2659WriteReg(0x3a02, 0x07);	// max exposure 60Hz, 15~5fps   30~5fps 0xe
		OV2659WriteReg(0x3a03, 0x30);	// max exposure 60Hz	0x6c
		OV2659WriteReg(0x3a14, 0x07);	// max exposure 50Hz, 15~5fps 0x0e
		OV2659WriteReg(0x3a15, 0x30);	// max exposure 50Hz 0x6c
		/////////////////////////////////////////////
		OV2659WriteReg(0x3623,0x00);
		OV2659WriteReg(0x3634,0x76);
		OV2659WriteReg(0x3701,0x44);
		OV2659WriteReg(0x3702,0x18);
		OV2659WriteReg(0x3703,0x24);
		OV2659WriteReg(0x3704,0x24);
		OV2659WriteReg(0x3705,0x0c);

		// define group 1 for preview
		OV2659WriteReg(0x3208, 0x01);	// enable group 1
		OV2659WriteReg(0x3702, 0x18);
		OV2659WriteReg(0x3703, 0x24);
		OV2659WriteReg(0x3704, 0x24);
		OV2659WriteReg(0x3208, 0x11);	// end group 1
		// define group 2 for capture
		OV2659WriteReg(0x3208, 0x02);	// enable group 2
		OV2659WriteReg(0x3702, 0x30);
		OV2659WriteReg(0x3703, 0x48);
		OV2659WriteReg(0x3704, 0x48);
		OV2659WriteReg(0x3208, 0x12);	// end group 2

		OV2659WriteReg(0x3820,0x81);

		///1 shutterx2////////////////1122
		///0 shutterx1///////////////
		//bining
#ifdef BINNING_EN
			OV2659WriteReg(0x3821,0x01);
#else
			OV2659WriteReg(0x3821,0x00);
#endif

		OV2659WriteReg(0x370a,0x52);
		OV2659WriteReg(0x4608,0x00);
		OV2659WriteReg(0x4609,0x80);//a0
		OV2659WriteReg(0x4300,0x30);//YUYV
		OV2659WriteReg(0x5086,0x02);
		OV2659WriteReg(0x5000,0xff);
		OV2659WriteReg(0x5001,0x1f);
		OV2659WriteReg(0x5002,0x00);//10
		//AEC
		OV2659WriteReg(0x3a0f, 0x30);	// Stable in high
		OV2659WriteReg(0x3a10, 0x28);	// stable in low
		OV2659WriteReg(0x3a1b, 0x30);	// stable out high
		OV2659WriteReg(0x3a1e, 0x28);	// stable out low
		OV2659WriteReg(0x3a11, 0x61);	// fast range high
		OV2659WriteReg(0x3a1f, 0x10);	// fast range low
		OV2659WriteReg(0x5060, 0x55);	// window 0~3
		OV2659WriteReg(0x5061, 0x7d);	// Window 4~7
		OV2659WriteReg(0x5062, 0x7d);	// window 8~11
		OV2659WriteReg(0x5063, 0x55);	// window 12~15
		OV2659WriteReg(0x3a18, 0x00);	// gain ceiling
		OV2659WriteReg(0x3a19, 0xb0);	// gain ceiling 4x


		//normal gamma
		OV2659WriteReg(0x5025,0x0d);
		OV2659WriteReg(0x5026,0x1c);
		OV2659WriteReg(0x5027,0x32);
		OV2659WriteReg(0x5028,0x46);
		OV2659WriteReg(0x5029,0x57);
		OV2659WriteReg(0x502a,0x68);	
		OV2659WriteReg(0x502b,0x78);
		OV2659WriteReg(0x502c,0x84);
		OV2659WriteReg(0x502d,0x90);
		OV2659WriteReg(0x502e,0xa6);
		OV2659WriteReg(0x502f,0xb8);
		OV2659WriteReg(0x5030,0xc7);
		OV2659WriteReg(0x5031,0xdd);
		OV2659WriteReg(0x5032,0xee);
		OV2659WriteReg(0x5033,0xf6);
		OV2659WriteReg(0x5034,0x0d);
		/*
		OV2659WriteReg(0x5025,0x0e);
		OV2659WriteReg(0x5026,0x18);
		OV2659WriteReg(0x5027,0x34);
		OV2659WriteReg(0x5028,0x4c);
		OV2659WriteReg(0x5029,0x62);
		OV2659WriteReg(0x502a,0x74);	
		OV2659WriteReg(0x502b,0x85);
		OV2659WriteReg(0x502c,0x92);
		OV2659WriteReg(0x502d,0x9e);
		OV2659WriteReg(0x502e,0xb2);
		OV2659WriteReg(0x502f,0xc0);
		OV2659WriteReg(0x5030,0xcc);
		OV2659WriteReg(0x5031,0xe0);
		OV2659WriteReg(0x5032,0xee);
		OV2659WriteReg(0x5033,0xf6);
		OV2659WriteReg(0x5034,0x11);
		*/
		/////////////CMX//////////////////

		//	OV2659WriteReg(0x5070,0x20);
		//	OV2659WriteReg(0x5071,0x5b);
		//	OV2659WriteReg(0x5072,0x05);
		//	OV2659WriteReg(0x5073,0x2a);
		//	OV2659WriteReg(0x5074,0x78);
		//	OV2659WriteReg(0x5075,0xa2);
		//	OV2659WriteReg(0x5076,0xa2);
		//	OV2659WriteReg(0x5077,0xae);
		//	OV2659WriteReg(0x5078,0x0b);
		//	OV2659WriteReg(0x5079,0x98);
		//	OV2659WriteReg(0x507a,0x00);
		OV2659WriteReg(0x5070,0x05);
		OV2659WriteReg(0x5071,0x8d);
		OV2659WriteReg(0x5072,0x12);
		OV2659WriteReg(0x5073,0x13);
		OV2659WriteReg(0x5074,0x87);
		OV2659WriteReg(0x5075,0x9a);
		OV2659WriteReg(0x5076,0xa5);
		OV2659WriteReg(0x5077,0xc5);
		OV2659WriteReg(0x5078,0x20);
		OV2659WriteReg(0x5079,0x9c);
		OV2659WriteReg(0x507a,0x00);


		///////////////awb////////////////
		//OV2659WriteReg(0x5035,0x6A);
		//OV2659WriteReg(0x5036,0x11);
		//OV2659WriteReg(0x5037,0x92);
		//OV2659WriteReg(0x5038,0x21);
		//OV2659WriteReg(0x5039,0xe1);
		//OV2659WriteReg(0x503a,0x01);
		//OV2659WriteReg(0x503c,0x05);
		//OV2659WriteReg(0x503d,0x08);
		//OV2659WriteReg(0x503e,0x08);
		//OV2659WriteReg(0x503f,0x64);
		//OV2659WriteReg(0x5040,0x58);
		//OV2659WriteReg(0x5041,0x2A);
		//OV2659WriteReg(0x5042,0xC5);
		//OV2659WriteReg(0x5043,0x2E);
		//OV2659WriteReg(0x5044,0x3A);
		//OV2659WriteReg(0x5045,0x3C);
		//OV2659WriteReg(0x5046,0x44);
		//OV2659WriteReg(0x5047,0xf8);
		//OV2659WriteReg(0x5048,0x08);
		//OV2659WriteReg(0x5049,0x70);
		//OV2659WriteReg(0x504a,0xf0);
		//OV2659WriteReg(0x504b,0xf0);
		OV2659WriteReg(0x5035,0x6a);
		OV2659WriteReg(0x5036,0x01);
		OV2659WriteReg(0x5037,0x92);
		OV2659WriteReg(0x5038,0x21);
		OV2659WriteReg(0x5039,0xe1);
		OV2659WriteReg(0x503a,0x01);
		OV2659WriteReg(0x503c,0x0a);//0X12
		OV2659WriteReg(0x503d,0x0c);
		OV2659WriteReg(0x503e,0x0f);
		OV2659WriteReg(0x503f,0x62);//0x62
		OV2659WriteReg(0x5040,0x59);
		OV2659WriteReg(0x5041,0x98);
		OV2659WriteReg(0x5042,0xd9);
		OV2659WriteReg(0x5043,0x3e);
		OV2659WriteReg(0x5044,0x3c);
		OV2659WriteReg(0x5045,0x51);
		OV2659WriteReg(0x5046,0x47);
		OV2659WriteReg(0x5047,0xf8);
		OV2659WriteReg(0x5048,0x08);
		OV2659WriteReg(0x5049,0x70);
		OV2659WriteReg(0x504a,0xf0);
		OV2659WriteReg(0x504b,0xf0);

		OV2659WriteReg(0x3406,0x00);  //	; Light mode auto Tony_8_31
		///////////////lenc/////////////////
		OV2659WriteReg(0x500c,0x03);
		OV2659WriteReg(0x500d,0x0c);
		OV2659WriteReg(0x500e,0x02);
		OV2659WriteReg(0x500f,0x5c);

		OV2659WriteReg(0x5010,0x4d);
		OV2659WriteReg(0x5011,0x00);
		OV2659WriteReg(0x5012,0x66);
		OV2659WriteReg(0x5013,0x03);
		OV2659WriteReg(0x5014,0x0c);
		OV2659WriteReg(0x5015,0x02);
		OV2659WriteReg(0x5016,0x5c);
		OV2659WriteReg(0x5017,0x40);
		OV2659WriteReg(0x5018,0x00);
		OV2659WriteReg(0x5019,0x66);
		OV2659WriteReg(0x501a,0x03);
		OV2659WriteReg(0x501b,0x0c);
		OV2659WriteReg(0x501c,0x02);
		OV2659WriteReg(0x501d,0x66);
		OV2659WriteReg(0x501e,0x3a);
		OV2659WriteReg(0x501f,0x00);
		OV2659WriteReg(0x5020,0x66);

		///////CIP/DNS/SHARPEN CTRL///////
		OV2659WriteReg(0x506e,0x44);

		OV2659WriteReg(0x5064,0x08);	
		OV2659WriteReg(0x5065,0x10);
		OV2659WriteReg(0x5066,0x16);//0x12

		OV2659WriteReg(0x5067,0x06);//0x02
		OV2659WriteReg(0x506c,0x08);//0x08
		OV2659WriteReg(0x506d,0x10);

		OV2659WriteReg(0x506e,0x44);/////////////////		
		OV2659WriteReg(0x506f,0xa6);

		///denoise
		OV2659WriteReg(0x5068,0x08);
		OV2659WriteReg(0x5069,0x10);

		OV2659WriteReg(0x506a,0x0c);//0x04
		OV2659WriteReg(0x506b,0x20);//0x12
		////////////////SDE/////////////////	
		OV2659WriteReg(0x507e,0x40);//0x3a
		OV2659WriteReg(0x507f,0x1c);//0x1a
		OV2659WriteReg(0x507b,0x02);

		OV2659WriteReg(0x507a,0x00);//0x01
#ifdef OVT_AUTOUV
		OV2659WriteReg(0x5084,0x10);//0x0c//th1 1.5x
		OV2659WriteReg(0x5085,0x30);//0x1f//1f//th2 4x
#else
		OV2659WriteReg(0x5084,0x0c);
		OV2659WriteReg(0x5085,0x3e);
#endif
		////////////////?//////////////////
		OV2659WriteReg(0x5005,0x80);
		///////////////AEC/AGC////////////
		//OV2659WriteReg(0x3a0f,0x30);
		//OV2659WriteReg(0x3a10,0x28);
		//OV2659WriteReg(0x3a11,0x61);
		//OV2659WriteReg(0x3a1b,0x32);
		//OV2659WriteReg(0x3a1e,0x26);
		//OV2659WriteReg(0x3a1f,0x14);
		//////////AVERAGE WEIGHT/////////
		//OV2659WriteReg(0x5060,0x69);
		//OV2659WriteReg(0x5061,0x7d);
		//OV2659WriteReg(0x5062,0x7d);
		//OV2659WriteReg(0x5063,0x69);
		//////
		OV2659WriteReg(0x5051, 0x40);	// LCD adjustment red gain
		OV2659WriteReg(0x5052, 0x40);	// LCD adjustment red gain
		OV2659WriteReg(0x5053, 0x40);	// LCD adjustment red gain


		OV2659Sensor.IsPVmode= 1;
		OV2659Sensor.PreviewDummyPixels= 0;
		OV2659Sensor.PreviewDummyLines= 0;
		OV2659Sensor.PreviewPclk= 480;
		OV2659Sensor.CapturePclk= 480;
		OV2659Sensor.PreviewShutter=0x0265;
		OV2659Sensor.SensorGain=0x10;
		
}                                  

/*************************************************************************
* FUNCTION
*    OV2659PreviewSetting
*
* DESCRIPTION
*    This function config Preview setting related registers of CMOS sensor.
*
* PARAMETERS
*    None
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV2659PreviewSetting(void)
{
	#ifdef OVT_SIM
		OV2659WriteReg(0x3004,0x20);
	#else
		OV2659WriteReg(0x3004,0x10);
	#endif
	OV2659WriteReg(0x3005,0x16);
	OV2659WriteReg(0x3006,0x0d);
	#ifdef BINNING_EN
    	OV2659Sensor.PreviewShutter/=2;
	#endif

	OV2659WriteReg(0x3500,((OV2659Sensor.PreviewShutter*16)>>16) & 0XFF);
	OV2659WriteReg(0x3501,((OV2659Sensor.PreviewShutter*16)>>8) & 0XFF);
	OV2659WriteReg(0x3502,(OV2659Sensor.PreviewShutter*16) & 0XFF);
	OV2659WriteReg(0x350B, OV2659Sensor.SensorGain);	
	
	//OV2659WriteReg(0x3807, 0xb7);

	//data outputsize(DVP)
	//800x600
	//OV2659WriteReg(0x3808, 0x03);
	//OV2659WriteReg(0x3809, 0x20);
	//OV2659WriteReg(0x380a, 0x02);
	//OV2659WriteReg(0x380b, 0x58);
	
	//TIMING HTS and VTS/////?
	//HTS 1300 
	//OV2659WriteReg(0x380c, 0x05);
	//OV2659WriteReg(0x380d, 0x14);
	//VTS 616
	//OV2659WriteReg(0x380e, 0x02);
	//OV2659WriteReg(0x380f, 0x68);

	//Prescaling size
	//H OFFSET 8
	//OV2659WriteReg(0x3811, 0x08);
	//V OFFSET 2
	//OV2659WriteReg(0x3813, 0x02);

	//bit[7:4] h/v odd increase number
	//bit[3:0] h/v even increase number
	//TIMING XINC : h odd inc 3;h even inc 1
	//OV2659WriteReg(0x3814, 0x31);
	//TIMING YINC : v odd inc 3;v even inc 1
	//OV2659WriteReg(0x3815, 0x31);
						// Timing
	OV2659WriteReg(0x3800, 0x00);	// HS
	OV2659WriteReg(0x3801, 0x00);	// HS
	OV2659WriteReg(0x3802, 0x00);	// VS
	OV2659WriteReg(0x3803, 0x00);	// VS
	OV2659WriteReg(0x3804, 0x06);	// HW = 1631
	OV2659WriteReg(0x3805, 0x5f);	// HW
	OV2659WriteReg(0x3806, 0x04);	// VH = 1207
	OV2659WriteReg(0x3807, 0xb7);	// VH
	OV2659WriteReg(0x3808, 0x03);	// DVPHO = 800
	OV2659WriteReg(0x3809, 0x20);	// DVPHO
	OV2659WriteReg(0x380a, 0x02);	// DVPVO = 600
	OV2659WriteReg(0x380b, 0x58);	// DVPVO
	OV2659WriteReg(0x380c, 0x05);	// HTS = 1300
	OV2659WriteReg(0x380d, 0x14);	// HTS
	OV2659WriteReg(0x380e, 0x02);	// VTS = 616
	OV2659WriteReg(0x380f, 0x68);	// VTS
	OV2659WriteReg(0x3811, 0x08);	// H offset
	OV2659WriteReg(0x3813, 0x02);	// V offset
	OV2659WriteReg(0x3814, 0x31);	// X inc
	OV2659WriteReg(0x3815, 0x31);	// Y inc

	OV2659WriteReg(0x3623, 0x00);
	OV2659WriteReg(0x3634, 0x76);
	OV2659WriteReg(0x3701, 0x44);
	OV2659WriteReg(0x3208, 0xa1);	// launch group 1
	OV2659WriteReg(0x3705, 0x0c);
	OV2659WriteReg(0x3820, 0x81);
	#ifdef BINNING_EN
		OV2659WriteReg(0x3821, 0x01);
	#else
		OV2659WriteReg(0x3821, 0x00);
	#endif

	OV2659WriteReg(0x3A00, OV2659ReadReg(0x3A00)| 0x04);///sofia 20110113
	
	////////////////50HZ//////////////////
	//OV2659WriteReg(0x3a14,0x02);
	//OV2659WriteReg(0x3a15,0x28);
	
	OV2659WriteReg(0x3a08,0x00);
	OV2659WriteReg(0x3a09,0xb8);
	
	OV2659WriteReg(0x3a0e,0x03);
	////////////////60HZ//////////////////
	//OV2659WriteReg(0x3a02,0x02);
	//OV2659WriteReg(0x3a03,0x68);//616

	OV2659WriteReg(0x3a0a,0x00);
	OV2659WriteReg(0x3a0b,0x9A);//99

	OV2659WriteReg(0x3a0d,0x04);
	/////////////////////////////////////////////
	
	///////////////////////////
	//OV2659WriteReg(0x3634, 0x76);
	//OV2659WriteReg(0x3701, 0x44);
	//OV2659WriteReg(0x3208, 0xa1);	// launch group 1
	//OV2659WriteReg(0x3702, 0x18);
	//OV2659WriteReg(0x3703, 0x24);
	//OV2659WriteReg(0x3704, 0x24);
	//OV2659WriteReg(0x3705, 0x0c);
	///////////////////////////
	OV2659WriteReg(0x370a, 0x52);
	OV2659WriteReg(0x4608, 0x00);	// VFIFO start
	OV2659WriteReg(0x4609, 0x80);	// VFIFO start
	OV2659WriteReg(0x5002, 0x10);	// Scale enable
	//	OV2659WriteReg(0x3005, 0x18);	// PLL
	//	OV2659WriteReg(0x3004, 0x10);	// Divider //0x20
	OV2659WriteReg(0x3503, 0x00);	// AEC auto, AGC auto
	#ifdef OVT_AUTOUV 
	if(!(OV2659ReadReg(0x507b)&0xF0))
	{
		OV2659WriteReg(0x5084,0x10);//0x0c//th1 1.5x
		OV2659WriteReg(0x5085,0x30);//0x1f//1f//th2 4x
		OV2659WriteReg(0x507e,0x40);//0x3a//offset 1
		OV2659WriteReg(0x507f,0x1c);//0x1a//0x18//offset 2
		OV2659WriteReg(0x507a, OV2659ReadReg(0x507a)&~0x10);//Auto UV
	}
	#endif

	OV2659Sensor.IsPVmode = KAL_TRUE;
	OV2659Sensor.PreviewPclk= 480;
	
}

/*************************************************************************
* FUNCTION
*     OV2659FullSizeCaptureSetting
*
* DESCRIPTION
*    This function config full size capture setting related registers of CMOS sensor.
*
* PARAMETERS
*    None
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV2659FullSizeCaptureSetting(void)
{
	OV2659WriteReg(0x3005,0x21);
	OV2659WriteReg(0x3006,0x0d);
	//(0,0)
	OV2659WriteReg(0x3800, 0x00);
	OV2659WriteReg(0x3801, 0x00);
	OV2659WriteReg(0x3802, 0x00);
	OV2659WriteReg(0x3803, 0x00);
	//(1631,1211)
	OV2659WriteReg(0x3804, 0x06);
	OV2659WriteReg(0x3805, 0x5f);
	OV2659WriteReg(0x3806, 0x04);
	OV2659WriteReg(0x3807, 0xbb);
		
	//1600x1200
	OV2659WriteReg(0x3808, 0x06);
	OV2659WriteReg(0x3809, 0x40);
	OV2659WriteReg(0x380a, 0x04);
	OV2659WriteReg(0x380b, 0xb0);
	
	//HTS 1951 
	OV2659WriteReg(0x380c, 0x07);
	OV2659WriteReg(0x380d, 0x9f);
	//VTS 1232
	OV2659WriteReg(0x380e, 0x04);
	OV2659WriteReg(0x380f, 0xd0);
	
	//(16,6)
	//h offset 16
	OV2659WriteReg(0x3811, 0x10);
	//v offset 6
	OV2659WriteReg(0x3813, 0x06);
	
	////////////////???????////////////////////
	//bit[7:4] h/v odd increase number
	//bit[3:0] h/v even increase number
	//TIMING XINC : h odd inc 1;h even inc 1
	OV2659WriteReg(0x3814, 0x11);
	//TIMING YINC : V odd inc 1;h even inc 1
	OV2659WriteReg(0x3815, 0x11);
	
	//maximum exposure for 60hz: 1232
	//OV2659WriteReg(0x3a02, 0x04);
	//OV2659WriteReg(0x3a03, 0xd0);
		
	//band step for 50/60 HZ light
	//CAM_BANDING_50HZ light:184
	//OV2659WriteReg(0x3a08, 0x00);
	//OV2659WriteReg(0x3a09, 0xb8);
	//CAM_BANDING_60HZ light:154
	//OV2659WriteReg(0x3a0a, 0x00);
	//OV2659WriteReg(0x3a0b, 0x9a);
	
	//maximum band number in one frame for 60 Hz light source:8
	//OV2659WriteReg(0x3a0d, 0x08);
	//maximum band number in one frame for 50 Hz light source:6
	//OV2659WriteReg(0x3a0e, 0x06);
	
	//maximum exposure number for 50Hz :1104
	//OV2659WriteReg(0x3a14, 0x04);
	//OV2659WriteReg(0x3a15, 0x50);
		
	OV2659WriteReg(0x3623, 0x00);
	OV2659WriteReg(0x3634, 0x44);
	OV2659WriteReg(0x3701, 0x44);
	OV2659WriteReg(0x3208, 0xa2);// launch group 2
	//OV2659WriteReg(0x3702, 0x30);
	//OV2659WriteReg(0x3703, 0x48);
	//OV2659WriteReg(0x3704, 0x48);
	OV2659WriteReg(0x3705, 0x18);
	OV2659WriteReg(0x3820, 0x80);
	OV2659WriteReg(0x3821, 0x00);
	OV2659WriteReg(0x370a, 0x12);
	
	//VFIFO Read Strat:128
	OV2659WriteReg(0x4608, 0x00);
	OV2659WriteReg(0x4609, 0x80);
	
	//ISP CTRL Bit[4]:Scale Enable(1:en;0,dis)
	OV2659WriteReg(0x5002, 0x00);
	
	///////////FULL Size CAPTURE CORLOR DIFFER
	OV2659WriteReg(0x4003, 0x88);

	OV2659WriteReg(0x3503, 0x03);	// AEC manual, AGC manual//Tony_8_31

	OV2659Sensor.IsPVmode = KAL_FALSE;
	OV2659Sensor.CapturePclk= 480;
	
}


/*************************************************************************
* FUNCTION
*	OV2659_set_dummy
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
static void OV2659SetDummy(kal_uint32 dummy_pixels, kal_uint32 dummy_lines)
{
	kal_uint32 temp_reg1, temp_reg2;
	kal_uint32 temp_reg, base_shutter = 0x9B;
	
	if (dummy_pixels > 0)
	{
		temp_reg1 = OV2659ReadReg(0x380D);    // HTS[b7~b0]
		temp_reg2 = OV2659ReadReg(0x380C);    // HTS[b15~b8]
		temp_reg = (temp_reg1 & 0xFF) | (temp_reg2 << 8);
	
		temp_reg += dummy_pixels;
	
		OV2659WriteReg(0x380D,(temp_reg&0xFF));         //HTS[7:0]
		OV2659WriteReg(0x380C,((temp_reg&0xFF00)>>8));  //HTS[15:8]
	}

	if (dummy_lines > 0)
	{
		temp_reg1 = OV2659ReadReg(0x380F);    // VTS[b7~b0]
		temp_reg2 = OV2659ReadReg(0x380E);    // VTS[b15~b8]
		temp_reg = (temp_reg1 & 0xFF) | (temp_reg2 << 8);
	
		temp_reg += dummy_lines;
	
		OV2659WriteReg(0x380F,(temp_reg&0xFF));         //VTS[7:0]
		OV2659WriteReg(0x380E,((temp_reg&0xFF00)>>8));  //VTS[15:8]
	}
	temp_reg1 = OV2659ReadReg(0x380D);    // HTS[b7~b0]
	temp_reg2 = OV2659ReadReg(0x380C);    // HTS[b15~b8]
	temp_reg = (temp_reg1 & 0xFF) | (temp_reg2 << 8);

	temp_reg1 = OV2659ReadReg(0x380F);    // VTS[b7~b0]
	temp_reg2 = OV2659ReadReg(0x380E);    // VTS[b15~b8]
	temp_reg = (temp_reg1 & 0xFF) | (temp_reg2 << 8);
	
}    /* OV2659_set_dummy */
/*************************************************************************
* FUNCTION
*	OV2659WriteShutter
*
* DESCRIPTION
*	This function used to write the shutter.
*
* PARAMETERS
*	1. kal_uint32 : The shutter want to apply to sensor.
*
* RETURNS
*	None
*
*************************************************************************/
static void OV2659WriteShutter(kal_uint32 shutter)
{
	kal_uint32 extra_exposure_lines = 0;
	if (shutter < 1)
	{
		shutter = 1;
	}
	
	if (OV2659Sensor.IsPVmode) 
	{
		if (shutter <= OV2659_PV_EXPOSURE_LIMITATION) 
		{
			extra_exposure_lines = 0;
		}
		else 
		{
			extra_exposure_lines=shutter - OV2659_PV_EXPOSURE_LIMITATION;
		}
		
	}
	else 
	{
		if (shutter <= OV2659_FULL_EXPOSURE_LIMITATION) 
		{
			extra_exposure_lines = 0;
		}
		else 
		{
			extra_exposure_lines = shutter - OV2659_FULL_EXPOSURE_LIMITATION;
		}
		
	}
	
	//AEC PK EXPOSURE
	shutter*=16;
	OV2659WriteReg(0x3502, (shutter & 0x00FF));           //AEC[7:0]
	OV2659WriteReg(0x3501, ((shutter & 0x0FF00) >>8));  //AEC[15:8]
	OV2659WriteReg(0x3500, ((shutter & 0xFF0000) >> 16));	
	
	if(extra_exposure_lines>0)
	{
		// set extra exposure line [aec add vts]
		OV2659WriteReg(0x3507, extra_exposure_lines & 0xFF);          // EXVTS[b7~b0]
		OV2659WriteReg(0x3506, (extra_exposure_lines & 0xFF00) >> 8); // EXVTS[b15~b8]
	}
	else
	{
		// set extra exposure line [aec add vts]
		OV2659WriteReg(0x3507, 0x00);          // EXVTS[b7~b0]
		OV2659WriteReg(0x3506, 0x00); // EXVTS[b15~b8]
	}
	
}    /* OV2659_write_shutter */
/*************************************************************************
* FUNCTION
*	OV2659ReadShutter
*
* DESCRIPTION
*	This function read current shutter for calculate the exposure.
*
* PARAMETERS
*	None
*
* RETURNS
*	kal_uint16 : The current shutter value.
*
*************************************************************************/
static kal_uint32 OV2659ReadShutter(void)
{
	kal_uint16 temp_reg1, temp_reg2 ,temp_reg3;
	temp_reg1 = OV2659ReadReg(0x3500);    // AEC[b19~b16]
	temp_reg2 = OV2659ReadReg(0x3501);    // AEC[b15~b8]
	temp_reg3 = OV2659ReadReg(0x3502);    // AEC[b7~b0]
	//read out register value and divide 16;
	OV2659Sensor.PreviewShutter  = (temp_reg1 <<12)| (temp_reg2<<4)|(temp_reg3>>4);
	
	temp_reg1 = OV2659ReadReg(0x3506);    // EXVTS[b15~b8]
	temp_reg2 = OV2659ReadReg(0x3507);    // EXVTS[b7~b0]
	/* Backup the preview mode last shutter & sensor gain. */
	OV2659Sensor.PreviewExtraShutter = (temp_reg2 & 0xFF) | (temp_reg1 << 8);
	
	return OV2659Sensor.PreviewShutter;
}    /* OV2659_read_shutter */

/*************************************************************************
* FUNCTION
*	OV2659WriteWensorGain
*
* DESCRIPTION
*	This function used to write the sensor gain.
*
* PARAMETERS
*	1. kal_uint32 : The sensor gain want to apply to sensor.
*
* RETURNS
*	None
*
*************************************************************************/
static void OV2659WriteSensorGain(kal_uint32 gain)
{
	kal_uint16 temp_reg = 0;
		
	if(gain > 1024)  ASSERT(0);
	temp_reg = 0;
	
	temp_reg=gain&0x0FF;	
	OV2659WriteReg(0x350B,temp_reg);
}  /* OV2659_write_sensor_gain */

/*************************************************************************
* FUNCTION
*	OV2659ReadSensorGain
*
* DESCRIPTION
*	This function read current sensor gain for calculate the exposure.
*
* PARAMETERS
*	None
*
* RETURNS
*	kal_uint16 : The current sensor gain value.
*
*************************************************************************/
static kal_uint32 OV2659ReadSensorGain(void)
{
	kal_uint16 temp_reg = 0;
	kal_uint32 sensor_gain = 0;
	sensor_gain=(OV2659ReadReg(0x350B)&0xFF);//+((OV2659ReadReg(0x350A)&0xFF<<8)&0xFF00);  
		
	return sensor_gain;

}  /* OV2659ReadSensorGain */

/*************************************************************************
* FUNCTION
*    OV2659SetHVMirror
*
* DESCRIPTION
*    This function set sensor Mirror
*
* PARAMETERS
*    Mirror
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV2659SetHVMirror(kal_uint8 Mirror)
{
  kal_uint8 mirror= 0, flip=0;
#ifdef OV2659_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO,"Mirror:%d",Mirror);
#endif 
    
  	flip = OV2659ReadReg(0x3820);
	mirror=OV2659ReadReg(0x3821);

	switch (Mirror)
	{
	case IMAGE_SENSOR_MIRROR_NORMAL:
		OV2659WriteReg(0x3820, flip&0xf9);     
		OV2659WriteReg(0x3821, mirror&0xf9);
		break;
	case IMAGE_SENSOR_MIRROR_H:
		OV2659WriteReg(0x3820, flip&0xf9);     
		OV2659WriteReg(0x3821, mirror|0x06);
		break;
	case IMAGE_SENSOR_MIRROR_V: 
		OV2659WriteReg(0x3820, flip|0x06);     
		OV2659WriteReg(0x3821, mirror&0xf9);
		break;
		
	case IMAGE_SENSOR_MIRROR_HV:
		OV2659WriteReg(0x3820, flip|0x06);     
		OV2659WriteReg(0x3821, mirror|0x06);
		break;
		
	default:
		ASSERT(0);
	}
}

/*************************************************************************
* FUNCTION
*    OV2659AeEnable
*
* DESCRIPTION
*    disable/enable AE
*
* PARAMETERS
*    Enable
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV2659AeEnable(kal_bool Enable)
{
  kal_uint8 AeTemp;
  
  AeTemp = OV2659ReadReg(0x3503);
  if (Enable)
  {
     OV2659WriteReg(0x3503, (AeTemp&(~0x07)));
  }
  else
  {
    OV2659WriteReg(0x3503, (AeTemp| 0x07));
  }
#ifdef OV2659_DEBUG
  kal_prompt_trace(MOD_ENG,"AEenable:%d",Enable);
#endif

  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV2659AwbEnable
*
* DESCRIPTION
*    disable/enable awb
*
* PARAMETERS
*    Enable
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV2659AwbEnable(kal_bool Enable)
{
  kal_uint8 AwbTemp;
  AwbTemp = OV2659ReadReg(0x3406);
  if (Enable)
  {
    OV2659WriteReg(0x3406 , AwbTemp&0xFE );
  }
  else
  {
    OV2659WriteReg(0x3406 , AwbTemp|0x01 );
  }
#ifdef OV2659_DEBUG
  kal_prompt_trace(MOD_ENG,"AWBenable:%d",Enable);
#endif

  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV2659Ev
*
* DESCRIPTION
*    OV2659 EV setting.
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV2659Ev(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT EvPara = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
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
    kal_uint8 EvTemp0 = 0x00, EvTemp1 = 0x00, temp_reg= 0x00;
	
	temp_reg=OV2659ReadReg(0x5083);//[3] sign
	OV2659WriteReg(0x507b,OV2659ReadReg(0x507b)|0x04);

#ifdef OV2659_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "EV:%d", In->FeatureSetValue);
#endif

    switch (In->FeatureSetValue)
    {
    case CAM_EV_POS_4_3:
		EvTemp0= 0x55;
		EvTemp1= temp_reg&0xf7;
		break;
		
	case CAM_EV_POS_3_3:
		EvTemp0= 0x3c;
		EvTemp1= temp_reg&0xf7;
		break;
				
	case CAM_EV_POS_2_3:
		EvTemp0= 0x28;
		EvTemp1= temp_reg&0xf7;
		break;
		
	case CAM_EV_POS_1_3:
		EvTemp0= 0x14;
		EvTemp1= temp_reg&0xf7;
		break;
		
	case CAM_EV_ZERO:
		EvTemp0= 0x00;
		EvTemp1= temp_reg&0xf7;
		break;
		
	case CAM_EV_NEG_1_3:
		EvTemp0= 0x14;
		EvTemp1= temp_reg|0x08;		
		break;
		
	case CAM_EV_NEG_2_3:
		EvTemp0= 0x28;
		EvTemp1= temp_reg|0x08;	
		break;
		
	case CAM_EV_NEG_3_3:
		EvTemp0= 0x42;
		EvTemp1= temp_reg|0x08;	
		break;
		
	case CAM_EV_NEG_4_3:
		EvTemp0= 0x60;
		EvTemp1= temp_reg|0x08;	
		break;
		
	default:
		//return KAL_FALSE;
		return MM_ERROR_NONE;//Tony_8_31
    }
    OV2659WriteReg(0x5082, EvTemp0);
	OV2659WriteReg(0x5083, EvTemp1);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV2659Contrast
*
* DESCRIPTION
*    OV2659 Contrast setting.
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV2659Contrast(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT EvPara = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    EvPara->IsSupport = KAL_TRUE;
    EvPara->ItemCount = 3;
    EvPara->SupportItem[0] = CAM_CONTRAST_HIGH;
    EvPara->SupportItem[1] = CAM_CONTRAST_MEDIUM;
    EvPara->SupportItem[2] = CAM_CONTRAST_LOW;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
#ifdef OV2659_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "EV:%d", In->FeatureSetValue);
#endif
	OV2659WriteReg(0x5001, 0x1f);
	//OV2659WriteReg(0x507b, 0x04);
    switch (In->FeatureSetValue)
    {
    case CAM_CONTRAST_HIGH:   
		OV2659WriteReg(0x5080, 0x2c);
		OV2659WriteReg(0x5081, 0x2c); 
		OV2659WriteReg(0x5083, 0x01); 
		break;
    case CAM_CONTRAST_MEDIUM: 
		OV2659WriteReg(0x5080, 0x20);
		OV2659WriteReg(0x5081, 0x20); 
		OV2659WriteReg(0x5083, 0x01);
		break;
    case CAM_CONTRAST_LOW:    
		OV2659WriteReg(0x5080, 0x14);
		OV2659WriteReg(0x5081, 0x14); 
		OV2659WriteReg(0x5083, 0x01);
		break;
    default: break;
    }

  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV2659Wb
*
* DESCRIPTION
*    OV2659 WB setting.
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
static MM_ERROR_CODE_ENUM OV2659Wb(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
	kal_uint16 temp_reg = 0;
		
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
#ifdef OV2659_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"WB:%d",In->FeatureSetValue);
#endif
	temp_reg = OV2659ReadReg(0x3406);
    switch (In->FeatureSetValue)
    {
	case CAM_WB_AUTO:
		OV2659AwbEnable(KAL_TRUE);
		break;
    case CAM_WB_CLOUD: 
		//OV2659AwbEnable(KAL_FALSE); 
		OV2659WriteReg(0x3406 ,temp_reg|0x1 );
		OV2659WriteReg(0x3400 ,0x6 );
		OV2659WriteReg(0x3401 ,0x30 );
		OV2659WriteReg(0x3402 ,0x4 );
		OV2659WriteReg(0x3403 ,0x0 );
		OV2659WriteReg(0x3404 ,0x4 );
		OV2659WriteReg(0x3405 ,0x30 );
		break;
		
	case CAM_WB_DAYLIGHT: 
		//OV2659AwbEnable(KAL_FALSE); 
		OV2659WriteReg(0x3406 ,temp_reg|0x1 );
		OV2659WriteReg(0x3400 ,0x6 );
		OV2659WriteReg(0x3401 ,0x10 );
		OV2659WriteReg(0x3402 ,0x4 );
		OV2659WriteReg(0x3403 ,0x0 );
		OV2659WriteReg(0x3404 ,0x4 );
		OV2659WriteReg(0x3405 ,0x48 );
		break;
		
	case CAM_WB_INCANDESCENCE: 
		//OV2659AwbEnable(KAL_FALSE);
		OV2659WriteReg(0x3406 ,temp_reg|0x1 );
		OV2659WriteReg(0x3400 ,0x4 );
		OV2659WriteReg(0x3401 ,0xe0 );
		OV2659WriteReg(0x3402 ,0x4 );
		OV2659WriteReg(0x3403 ,0x0 );
		OV2659WriteReg(0x3404 ,0x5 );
		OV2659WriteReg(0x3405 ,0xa0 );
		break;
		
	case CAM_WB_FLUORESCENT:
		//OV2659AwbEnable;
		OV2659WriteReg(0x3406 ,temp_reg|0x1 );
		OV2659WriteReg(0x3400 ,0x5 );
		OV2659WriteReg(0x3401 ,0x48 );
		OV2659WriteReg(0x3402 ,0x4 );
		OV2659WriteReg(0x3403 ,0x0 );
		OV2659WriteReg(0x3404 ,0x5 );
		OV2659WriteReg(0x3405 ,0xe0 );
		break;
		
	case CAM_WB_TUNGSTEN: 
		//OV2659AwbEnable;
		OV2659WriteReg(0x3406 ,temp_reg|0x1 );
		OV2659WriteReg(0x3400 ,0x4 );
		OV2659WriteReg(0x3401 ,0x0 );
		OV2659WriteReg(0x3402 ,0x4 );
		OV2659WriteReg(0x3403 ,0x0 );
		OV2659WriteReg(0x3404 ,0x6 );
		OV2659WriteReg(0x3405 ,0x50 );
		break;
	
	default:
		break;
    }
  }
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    OV2659Effect
*
* DESCRIPTION
*    OV2659 Effect setting.
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
static MM_ERROR_CODE_ENUM OV2659Effect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  kal_uint8 temp_reg;
  
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    P_CAL_FEATURE_TYPE_ENUM_STRUCT EffectPara = &Out->FeatureInfo.FeatureEnum;
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION | CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    EffectPara->IsSupport = KAL_TRUE;
    EffectPara->ItemCount = 9;
    EffectPara->SupportItem[0] = CAM_EFFECT_ENC_NORMAL;
    EffectPara->SupportItem[1] = CAM_EFFECT_ENC_GRAYSCALE;
    EffectPara->SupportItem[2] = CAM_EFFECT_ENC_SEPIA;
    EffectPara->SupportItem[3] = CAM_EFFECT_ENC_SEPIAGREEN;
    EffectPara->SupportItem[4] = CAM_EFFECT_ENC_SEPIABLUE;
    EffectPara->SupportItem[5] = CAM_EFFECT_ENC_COLORINV;

  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
#ifdef OV2659_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"Effect:%d",In->FeatureSetValue);
#endif
	temp_reg=OV2659ReadReg(0x507B);
	temp_reg&=0x07;
	  
    switch (In->FeatureSetValue)
    {
    case CAM_EFFECT_ENC_NORMAL:
		OV2659WriteReg(0x507B, temp_reg);
		#ifdef OVT_AUTOUV
			OV2659WriteReg(0x507e,0x40);//offset 1  , it must be same with PV setting[Ken]
        	OV2659WriteReg(0x507f,0x1c);
        #endif
		break;
		
	case CAM_EFFECT_ENC_SEPIA:
		OV2659WriteReg(0x507B, (temp_reg|0x18));
		OV2659WriteReg(0x507E, (0x40));
		OV2659WriteReg(0x507F, (0xA0));
		break;
		
	case CAM_EFFECT_ENC_COLORINV://NEGATIVE
		OV2659WriteReg(0x507B, (temp_reg|0x40));
		break;
		
	case CAM_EFFECT_ENC_SEPIAGREEN:
		OV2659WriteReg(0x507B, (temp_reg|0x18));
		OV2659WriteReg(0x507E, (0x60));
		OV2659WriteReg(0x507F, (0x60));
		break;
		
	case CAM_EFFECT_ENC_SEPIABLUE:
		OV2659WriteReg(0x507B, (temp_reg|0x18));
		OV2659WriteReg(0x507E, (0xA0));
		OV2659WriteReg(0x507F, (0x40));
		break;
		
	case CAM_EFFECT_ENC_GRAYSCALE: //B&W
		OV2659WriteReg(0x507B, (temp_reg|0x20));
		//OV2659WriteReg(0x507B, (0x4 | 0x60));

		break;
		
	case CAM_EFFECT_ENC_GRAYINV:
	case CAM_EFFECT_ENC_COPPERCARVING:
	case CAM_EFFECT_ENC_BLUECARVING:
	case CAM_EFFECT_ENC_CONTRAST:
		
		
	case CAM_EFFECT_ENC_EMBOSSMENT:
	case CAM_EFFECT_ENC_SKETCH:
	case CAM_EFFECT_ENC_BLACKBOARD:
	case CAM_EFFECT_ENC_WHITEBOARD:
	case CAM_EFFECT_ENC_JEAN:
	case CAM_EFFECT_ENC_OIL:
		break;
	default:
		break;
    }
  }   
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV2659StillCaptureSize
*
* DESCRIPTION
*    This function get capture size
*
* PARAMETERS
*    In, Out, OutLen, RealOutLen
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV2659StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  const P_CAL_FEATURE_TYPE_ENUM_STRUCT CapSize = &Out->FeatureInfo.FeatureEnum;
  
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_GET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
    CapSize->IsSupport = KAL_TRUE;
    CapSize->ItemCount = 4;
    CapSize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
    CapSize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
	CapSize->SupportItem[2] = CAM_IMAGE_SIZE_1M;//CAM_SIZE_1M;//Tony_8_31
	CapSize->SupportItem[3] = CAM_IMAGE_SIZE_2M;//CAM_SIZE_2M;//Tony_8_31
	#if (defined(__YUVCAM_INTERPOLATION_SW__)||defined(__YUVCAM_INTERPOLATION_HW__))
		CapSize->SupportItem[CapSize->ItemCount] = CAM_SIZE_3M; 
		CapSize->ItemCount++;
	#endif
  }
  return MM_ERROR_NONE;
  
}

/*************************************************************************
* FUNCTION
*    OV2659Banding
*
* DESCRIPTION
*    This function get banding setting
*
* PARAMETERS
*    In, Out, OutLen, RealOutLen
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV2659Banding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
	
  const P_CAL_FEATURE_TYPE_ENUM_STRUCT Banding = &Out->FeatureInfo.FeatureEnum;
  kal_uint16 temp_reg = 0;
  kal_uint32 base_shutter = 0, max_shutter_step = 0, exposure_limitation = 0;
  kal_uint32 line_length = 0, sensor_pixel_clock = 0;
  
  #ifdef OV2659_DEBUG
  	kal_wap_trace(MOD_ENG,TRACE_INFO,"Banding:%d",In->FeatureSetValue);
  #endif
  
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    Banding->IsSupport = KAL_TRUE;
    Banding->ItemCount = 2;
    Banding->SupportItem[0] = CAM_BANDING_50HZ;
    Banding->SupportItem[1] = CAM_BANDING_60HZ;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    OV2659Sensor.Banding = In->FeatureSetValue;

	if (OV2659Sensor.IsPVmode == KAL_TRUE)
	{
		line_length = OV2659_PV_PERIOD_PIXEL_NUMS + OV2659Sensor.PreviewDummyPixels;
		exposure_limitation = OV2659_PV_PERIOD_LINE_NUMS + OV2659Sensor.PreviewDummyLines;
		sensor_pixel_clock = OV2659Sensor.PreviewPclk * 100 * 1000;
	}
	else
	{
		line_length = OV2659_FULL_PERIOD_PIXEL_NUMS + OV2659Sensor.CaptureDummyPixels;
		exposure_limitation = OV2659_FULL_PERIOD_LINE_NUMS + OV2659Sensor.CaptureDummyLines;
		sensor_pixel_clock = OV2659Sensor.CapturePclk * 100 * 1000;
	}

	line_length = line_length * 2;		/* Multiple 2 is because one YUV422 pixels need two clock. */
	
	temp_reg = OV2659ReadReg(0x3a05);
	
	switch (OV2659Sensor.Banding)
	{
	case CAM_BANDING_50HZ:

		/* + (line_length/2) is used fot base_shutter + 0.5 */
		//base_shutter=framerate*max exposure line/100=(plck/2/(line_len*frame_len))*max exposure line/100
		base_shutter = ((sensor_pixel_clock/100) + (line_length/2)) / line_length;
		max_shutter_step = (exposure_limitation / base_shutter);// - 1;

		OV2659WriteReg(0x3a0e, max_shutter_step); 
		OV2659WriteReg(0x3a09, base_shutter); 

		OV2659WriteReg(0x3a05, temp_reg&~0x80);
		break;
		
	case CAM_BANDING_60HZ:

		/* + (line_length/2) is used fot base_shutter + 0.5 */
		base_shutter = ((sensor_pixel_clock/120) + (line_length/2)) / line_length;
		max_shutter_step = (exposure_limitation / base_shutter);// - 1;

		OV2659WriteReg(0x3a0d, max_shutter_step); 
		OV2659WriteReg(0x3a0b, base_shutter); 

		OV2659WriteReg(0x3a05, temp_reg|0x80);

		break;
		
	default:
		/* Enable Auto Anti-Flicker if the sensor support it. */
		//return KAL_FALSE;
		return MM_ERROR_NONE;//Tony_8_31
	}
	
  }  
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV2659GetZoomInfo
*
* DESCRIPTION
*    This function get sensor zoom info
*
* PARAMETERS
*    Query, Info
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
#if 0//Tony_8_31
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
#endif

/*************************************************************************
* FUNCTION
*    OV2659GetSensorInfo
*
* DESCRIPTION
*    This function get sensor infomation
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
static void OV2659GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT Info)
{
  Info->SensorId = OV2659_SENSOR_ID;
  Info->SensorIf = IMAGE_SENSOR_IF_PARALLEL;
  
  Info->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;  
  Info->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
  Info->PixelClkInv = KAL_FALSE;
  Info->PixelClkPolarity = POLARITY_LOW;
  Info->HsyncPolarity = POLARITY_LOW;
  Info->VsyncPolarity = POLARITY_LOW;
  
  Info->PreviewMclkFreq = 26000000;
  Info->CaptureMclkFreq = 26000000;
  Info->VideoMclkFreq = 26000000;

  Info->PreviewWidth = OV2659_IMAGE_SENSOR_SVGA_WIDTH;
  Info->PreviewHeight = OV2659_IMAGE_SENSOR_SVGA_HEIGHT;
  Info->FullWidth = OV2659_IMAGE_SENSOR_UVGA_WITDH;
  Info->FullHeight = OV2659_IMAGE_SENSOR_UVGA_HEIGHT;
  
  Info->SensorAfSupport = KAL_FALSE;
  Info->SensorFlashSupport = KAL_FALSE;
}


/*************************************************************************
* FUNCTION
*    OV2659InitOperationPara
*
* DESCRIPTION
*    This function set sensor operation Para
*
* PARAMETERS
*    Para
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV2659InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
  Para->CaptureDelayFrame = 3; /* wait stable frame when sensor change mode (pre to cap) */
  Para->PreviewDelayFrame = 3; /* wait stable frame when sensor change mode (cap to pre) */
  Para->PreviewDisplayWaitFrame = 3; /* wait stable frame when sensor change mode (cap to pre) */
}

/*************************************************************************
* FUNCTION
*	OV2659SetVideoFrameRate
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
static void OV2659SetVideoFrameRate(kal_uint32 frame_rate)
{
	/*The real frame rate need /10*/
	kal_uint32 temp=0,temp1=0;
	kal_uint32 line_length = OV2659_PV_PERIOD_PIXEL_NUMS;
	kal_uint16 night = OV2659ReadReg(0x3a00); //bit[3], 0: disable, 1:enable
	OV2659WriteReg(0x3A00,  night| 0x04);
	//HTS 1300 
	
	OV2659WriteReg(0x380c, 0x05);
	OV2659WriteReg(0x380d, 0x14);
	//VTS 616
	OV2659WriteReg(0x380e, 0x02);
	OV2659WriteReg(0x380f, 0x68);
	
	line_length = OV2659Sensor.PreviewPclk*1000000/frame_rate/(OV2659_PV_PERIOD_LINE_NUMS + OV2659Sensor.PreviewDummyLines)/2;

	if (line_length >= 0x3000)
	{
		OV2659WriteReg(0x3004,0x20);////////4X
		OV2659WriteReg(0x3005,0x08);////PLUS 8
		OV2659WriteReg(0x3006,0x0d);/////01 101  2X 3X
		OV2659Sensor.PreviewPclk = 120;
		line_length = OV2659Sensor.PreviewPclk*1000000/frame_rate/(OV2659_PV_PERIOD_LINE_NUMS + OV2659Sensor.PreviewDummyLines)/2;
	}
	else if (line_length >= 0x2000)
	{
		OV2659WriteReg(0x3004,0x20);////////4X
		OV2659WriteReg(0x3005,0x0F);////PLUS 15
		OV2659WriteReg(0x3006,0x0d);/////01 101  2X 3X
		OV2659Sensor.PreviewPclk = 160;
		line_length = OV2659Sensor.PreviewPclk*1000000/frame_rate/(OV2659_PV_PERIOD_LINE_NUMS + OV2659Sensor.PreviewDummyLines)/2;
	}
	else if (line_length >= 0x1000)
	{
		/////26X22/4/2/3=24M
		OV2659WriteReg(0x3004,0x20);////////4X
		OV2659WriteReg(0x3005,0x16);////PLUS 22
		OV2659WriteReg(0x3006,0x0d);/////01 101  2X 3X
		OV2659Sensor.PreviewPclk = 240;
		line_length = OV2659Sensor.PreviewPclk*1000000/frame_rate/(OV2659_PV_PERIOD_LINE_NUMS + OV2659Sensor.PreviewDummyLines)/2;
	}
	if( line_length < OV2659_PV_PERIOD_PIXEL_NUMS )
	{
		OV2659WriteReg(0x3004,0x10);////////4X
		OV2659WriteReg(0x3005,0x16);////PLUS 22
		OV2659WriteReg(0x3006,0x0d);/////01 101  2X 3X
		OV2659Sensor.PreviewPclk = 480;
		line_length = OV2659Sensor.PreviewPclk*1000000/frame_rate/(OV2659_PV_PERIOD_LINE_NUMS + OV2659Sensor.PreviewDummyLines)/2;
	}
	
	OV2659Sensor.PreviewDummyPixels = line_length - OV2659_PV_PERIOD_PIXEL_NUMS;
	
	OV2659SetDummy(OV2659Sensor.PreviewDummyPixels, OV2659Sensor.PreviewDummyLines);
	
	/*Enable fix frame rate==TURN OFF NIGHT MODE*/
	OV2659WriteReg(0x3A00, night & ~0x4); //0x78  0xfb
	// clear extra exposure line
	OV2659WriteReg(0x3506, 0x00);
	OV2659WriteReg(0x3507, 0x00);
	
}

/*************************************************************************
* FUNCTION
*    OV2659NightMode
*
* DESCRIPTION
*    This function switch on/off night mode
*
* PARAMETERS
*    enable
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV2659NightMode(kal_bool Enable)
{
	kal_uint16 night = OV2659ReadReg(0x3A00); //bit[2], 0: disable, 1:enable
#ifdef OV2659_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "OV2659 NightMode %d",Enable);
#endif
  if (OV2659Sensor.VideoMode == KAL_FALSE)// camera mode
  {
    if (KAL_TRUE == Enable)
    { /* camera night mode */
		Night_mode_flag=1;
		#ifdef OV2659_DEBUG
        	kal_wap_trace(MOD_ENG,TRACE_INFO, "camera night mode");
		#endif
	//	OV2659WriteReg(0x3a19, 0x90); //7c/* Max gain 8X for video night mode */
		OV2659WriteReg(0x3A00, night | 0x04); /*Disable fix frame rate*///0x7c
	
		OV2659WriteReg(0x3a02 ,0x0e);// 60Hz, maximum exposures, , reduce 1/6 , ->5 frames
		OV2659WriteReg(0x3a03 ,0x58);
				
		OV2659WriteReg(0x3a14 ,0x0e); //50hz 30-->5fps
		OV2659WriteReg(0x3a15 ,0x60);
	
		//gamma to improve nightmode noise
		//night gamma
		OV2659WriteReg(0x5025,0x02);
		OV2659WriteReg(0x5026,0xf);
		OV2659WriteReg(0x5027,0x27);
		OV2659WriteReg(0x5028,0x3f);
		OV2659WriteReg(0x5029,0x54);
		OV2659WriteReg(0x502a,0x67);	
		OV2659WriteReg(0x502b,0x77);
		OV2659WriteReg(0x502c,0x84);
		OV2659WriteReg(0x502d,0x8c);
		OV2659WriteReg(0x502e,0xa6);
		OV2659WriteReg(0x502f,0xb8);
		OV2659WriteReg(0x5030,0xc7);
		OV2659WriteReg(0x5031,0xdd);
		OV2659WriteReg(0x5032,0xee);
		OV2659WriteReg(0x5033,0xf6);
		OV2659WriteReg(0x5034,0x0d);
      
    }
    else
    {   /* camera normal mode */
		Night_mode_flag=0;
		#ifdef OV2659_DEBUG
  			kal_wap_trace(MOD_ENG,TRACE_INFO, "camera normal mode");
		#endif
	//	OV2659WriteReg(0x3a19, 0x90);//gain ceiling 4.5x
   		OV2659WriteReg(0x3A00, night | 0x04); /*Disable fix frame rate*/

   		OV2659WriteReg(0x3a02 ,0x07);// 60 maximum exposure . reduce 1/3, 10fps
   		OV2659WriteReg(0x3a03 ,0x2c);
			
   		OV2659WriteReg(0x3a14 ,0x07);
   		OV2659WriteReg(0x3a15 ,0x30);	//50hz 30fps--10fps

		//normal gamma
		OV2659WriteReg(0x5025,0x0d);
		OV2659WriteReg(0x5026,0x1c);
		OV2659WriteReg(0x5027,0x32);
		OV2659WriteReg(0x5028,0x46);
		OV2659WriteReg(0x5029,0x57);
		OV2659WriteReg(0x502a,0x68);	
		OV2659WriteReg(0x502b,0x78);
		OV2659WriteReg(0x502c,0x84);
		OV2659WriteReg(0x502d,0x90);
		OV2659WriteReg(0x502e,0xa6);
		OV2659WriteReg(0x502f,0xb8);
		OV2659WriteReg(0x5030,0xc7);
		OV2659WriteReg(0x5031,0xdd);
		OV2659WriteReg(0x5032,0xee);
		OV2659WriteReg(0x5033,0xf6);
		OV2659WriteReg(0x5034,0x0d);
    }
  }
  else //video mode
  {	
	Night_mode_flag=0;
    if (KAL_TRUE == Enable)
    {   /* video night mode */
#ifdef OV2659_DEBUG
      kal_wap_trace(MOD_ENG,TRACE_INFO, "video night mode");
#endif
      OV2659WriteReg(0x3a19, 0x60);
    }
    else
    {   /* video normal mode */
#ifdef OV2659_DEBUG
      kal_wap_trace(MOD_ENG,TRACE_INFO, "video normal mode");
#endif
      OV2659WriteReg(0x3a19, 0x3e);
    }	  	
  	OV2659SetVideoFrameRate(OV2659Sensor.Fps);

	
  }
}

/*************************************************************************
* FUNCTION
*    OV3640SceneMode
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
static MM_ERROR_CODE_ENUM OV2659SceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    OV2659NightMode(Enable);
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV2659PowerOn
*
* DESCRIPTION
*    This function reset sensor and read Id
*
* PARAMETERS
*    None
*
* RETURNS
*    sensor Id
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint16 OV2659PowerOn(void)
{
  kal_uint32 SensorId;
  /* PowerOn the sensor */

  CisModulePowerOn(OV2659Sensor.SensorIdx, KAL_TRUE);

  CameraSccbOpen(CAMERA_SCCB_SENSOR, OV2659_SLAVE_ADDR, CAMERA_SCCB_16BIT, CAMERA_SCCB_8BIT, 150);

  kal_sleep_task(2);  /* delay for power stable */
  
  /* set sensors chip enable pin to low to activate OV2659 */
  CamPdnPinCtrl(OV2659Sensor.SensorIdx, 0);

  kal_sleep_task(1);
  
  /* Reset the sensor */
  CamRstPinCtrl(OV2659Sensor.SensorIdx, 1);
  kal_sleep_task(2);
  CamRstPinCtrl(OV2659Sensor.SensorIdx, 0);
  kal_sleep_task(4);
  CamRstPinCtrl(OV2659Sensor.SensorIdx, 1);
  /* delay for stable sensor */  
  kal_sleep_task(2);


  /*software reset sensor and wait (to sensor)*/ 
  OV2659WriteReg(0x0103,0x01);
  kal_sleep_task(4);
   
  /* Read Sensor ID  */
  SensorId = (OV2659ReadReg(OV2659_ID_REG) << 8)| OV2659ReadReg(OV2659_INFO_REG);

  dbg_print("SensorId = %x \r\n",SensorId);
#ifdef OV2659_DEBUG
  kal_wap_trace(MOD_ENG, TRACE_INFO, "OV2659 Sensor ID: %x ",SensorId);
#endif
  return SensorId;
}

/*************************************************************************
* FUNCTION
*    OV2659Preview
*
* DESCRIPTION
*    This function set to preview mode
*
* PARAMETERS
*    Id, In, Out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV2659Preview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint8 StartX = 1, StartY = 1;

#ifdef OV2659_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "OV2659 Preview");
#endif

  OV2659PreviewSetting();
  kal_sleep_task(15);

   OV2659AeEnable(KAL_TRUE);
   OV2659AwbEnable(KAL_TRUE);

  OV2659Sensor.Banding = In->BandingFreq;
  OV2659Sensor.NightMode = In->NightMode;
  switch (Id)
  {
  case CAL_SCENARIO_VIDEO:
    OV2659Sensor.VideoMode = KAL_TRUE;
    OV2659Sensor.Fps = In->MaxVideoFrameRate * OV2659_FRAME_RATE_UNIT / 10;
	OV2659Sensor.PreviewDummyLines=0;
	OV2659Sensor.PreviewDummyPixels=0;
    break;
  case CAL_SCENARIO_CAMERA_PREVIEW:
    OV2659Sensor.VideoMode = KAL_FALSE;
    OV2659Sensor.Fps = OV2659_FRAME_RATE_UNIT * (OV2659Sensor.NightMode ? 75 : 150);
	OV2659Sensor.PreviewDummyLines=0;
	OV2659Sensor.PreviewDummyPixels=0;
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    OV2659Sensor.VideoMode = KAL_FALSE;
    OV2659Sensor.Fps = OV2659_FRAME_RATE_UNIT * (OV2659Sensor.NightMode ? 75 : 150);
	OV2659Sensor.PreviewDummyLines=0;
	OV2659Sensor.PreviewDummyPixels=0;
    break;
  default:
    break;
  }

  ImageMirror = In->ImageMirror;
  OV2659SetHVMirror(In->ImageMirror);//Tony_8_31_hungup
  OV2659NightMode(OV2659Sensor.NightMode);

  Out->GrabStartX = StartX;
  Out->GrabStartY = StartY;
  Out->ExposureWindowWidth = OV2659_IMAGE_SENSOR_SVGA_WIDTH - 2 * StartX; 
  Out->ExposureWindowHeight = OV2659_IMAGE_SENSOR_SVGA_HEIGHT - 2 * StartY;
}


kal_uint32 OV2659TransferAECAGC(kal_uint32 preview_clk_in_M, kal_uint32 capture_clk_in_M)
{

    kal_uint32 PV_Line_Width;
    kal_uint32 Capture_Line_Width;
    kal_uint32 Capture_Maximum_Shutter;
    kal_uint32 Capture_Exposure;
    kal_uint32 Capture_Gain16;
    kal_uint32 Capture_Banding_Filter;
    kal_uint32 Gain_Exposure=0;
	kal_uint32 OV2659_Capture_Max_Gain16=0x40;
	

	#ifdef BINNING_EN
    	OV2659Sensor.PreviewShutter*=2; 	
	#endif
    PV_Line_Width = OV2659_PV_PERIOD_PIXEL_NUMS+OV2659Sensor.PreviewDummyPixels;

    Capture_Line_Width = OV2659_FULL_PERIOD_PIXEL_NUMS+OV2659Sensor.CaptureDummyPixels;
    Capture_Maximum_Shutter = OV2659_FULL_EXPOSURE_LIMITATION + OV2659Sensor.CaptureDummyPixels;

    //Capture_Banding_Filter = capture_clk_in_M*100000/10/(2*Capture_Line_Width); 
    if(OV2659Sensor.Banding==CAM_BANDING_50HZ)
    	Capture_Banding_Filter = capture_clk_in_M*100000/100/(2*Capture_Line_Width); 
	else
		Capture_Banding_Filter = capture_clk_in_M*100000/120/(2*Capture_Line_Width); 

    Gain_Exposure = OV2659Sensor.SensorGain;
    ///////////////////////
    Gain_Exposure *=OV2659Sensor.PreviewShutter;
    Gain_Exposure *=PV_Line_Width;  
    Gain_Exposure /=Capture_Line_Width;

    //Gain_Exposure = Gain_Exposure*g_Capture_PCLK_Frequency/g_Preview_PCLK_Frequency;//OK
    
    Gain_Exposure = Gain_Exposure*capture_clk_in_M/preview_clk_in_M;  

    //redistribute gain and exposure
    if (Gain_Exposure < Capture_Banding_Filter * 16)     // Exposure < 1/100/120
    {
	     //Capture_Exposure = Gain_Exposure /16;
            //Capture_Gain16 = (Gain_Exposure*2 + 1)/Capture_Exposure/2;
            Capture_Gain16=16;//for 59, 16 mean 1x gain
            Capture_Exposure = (Gain_Exposure*2 + 1)/Capture_Gain16/2;   
    }
    else 
    {
        if (Gain_Exposure > Capture_Maximum_Shutter * 16) // Exposure > Capture_Maximum_Shutter
        {
           
            Capture_Exposure = Capture_Maximum_Shutter/Capture_Banding_Filter*Capture_Banding_Filter;
            Capture_Gain16 = (Gain_Exposure*2 + 1)/Capture_Exposure/2;
            if (Capture_Gain16 > OV2659_Capture_Max_Gain16 )
            {
                // gain reach maximum, insert extra line
                Capture_Exposure = Gain_Exposure*1.1/OV2659_Capture_Max_Gain16;
                
                // Exposure = n/100/120
                Capture_Exposure = Capture_Exposure/Capture_Banding_Filter;
                Capture_Exposure =Capture_Exposure * Capture_Banding_Filter;
                Capture_Gain16 = ((Gain_Exposure *4)/ Capture_Exposure+3)/4;
            }
        }
        else  // 1/100 < Exposure < Capture_Maximum_Shutter, Exposure = n/100/120
        {
            Capture_Exposure = (Gain_Exposure*1.1)/16/Capture_Banding_Filter;
            Capture_Exposure = Capture_Exposure * Capture_Banding_Filter;
            Capture_Gain16 = (Gain_Exposure*2 +1) / Capture_Exposure/2;
        }
    }
    OV2659Sensor.SensorGain = Capture_Gain16;
    return Capture_Exposure;
 }
///////////////////////////////////Tony_8_31 add_start//////////////////////////////////

 int OV2659_get_shutter()
 {
	 // read shutter, in number of line period
	 int shutter;

	 shutter = (OV2659ReadReg( 0x03500) & 0x0f);
	 shutter = (shutter<<8) + OV2659ReadReg( 0x3501);
	 shutter = (shutter<<4) + (OV2659ReadReg( 0x3502)>>4);

	 return shutter;
 }

 int OV2659_set_shutter(int shutter)
 {
	 // write shutter, in number of line period
	 int temp;
	 
	 shutter = shutter & 0xffff;

	 temp = shutter & 0x0f;
	 temp = temp<<4;
	 OV2659WriteReg( 0x3502, temp);

	 temp = shutter & 0xfff;
	 temp = temp>>4;
	 OV2659WriteReg( 0x3501, temp);

	 temp = shutter>>12;
	 OV2659WriteReg( 0x3500, temp);

	 return 0;
 }

 int OV2659_get_gain16()
 {
	 // read gain, 16 = 1x
	 int gain16;

	 gain16 = OV2659ReadReg( 0x350a) & 0x03;
	 gain16 = (gain16<<8) + OV2659ReadReg( 0x350b);

	 return gain16;
 }

 int OV2659_set_gain16(int gain16)
 {
	 // write gain, 16 = 1x
	 int temp;
	 gain16 = gain16 & 0x3ff;

	 temp = gain16 & 0xff;
	 OV2659WriteReg( 0x350b, temp);

	 temp = gain16>>8;
	 OV2659WriteReg( 0x350a, temp);

	 return 0;
 }

 int OV2659_get_PCLK()
 {
	 // calculate PCLK
	 int PCLK, temp1, temp2;
	 int Pre_div2x, PLLDiv, FreqDiv2x, Bit8Div, SysDiv, ScaleDiv, VCO;
	 int XVCLK = 2600;	// real clock/10000

	 int Pre_div2x_map[] = {
		 2, 3, 4, 6, 4, 6, 8, 12};

	 int FreqDiv2x_map[] = {
		 2, 3, 4, 6};

	 int Bit8Div_map[] = {
		 1, 1, 4, 5};

	 int SysDiv_map[] = {
		 1, 2, 8, 16};

	 int ScaleDiv_map[] = {
		 1, 2, 4, 6, 8, 10, 12, 14};

	 temp1 = OV2659ReadReg( 0x3003);
	 temp2 = temp1>>6;
	 FreqDiv2x = FreqDiv2x_map[temp2];

	 temp2 = temp1 & 0x03;
	 Bit8Div = Bit8Div_map[temp2];

	 temp1 = OV2659ReadReg( 0x3004);
	 temp2 = temp1 >>4;
	 ScaleDiv = ScaleDiv_map[temp2];

	 temp1 = OV2659ReadReg( 0x3005);
	 PLLDiv = temp1 & 0x3f;

	 temp1 = OV2659ReadReg( 0x3006);
	 temp2 = temp1 & 0x07;
	 Pre_div2x = Pre_div2x_map[temp2];

	 temp2 = temp1 & 0x18;
	 temp2 = temp2>>3;
	 SysDiv = SysDiv_map[temp2];

	 VCO = XVCLK * PLLDiv * FreqDiv2x * Bit8Div / Pre_div2x;

	 PCLK = VCO / SysDiv / ScaleDiv / 2;

	 return PCLK;
 }

 int OV2659_get_HTS()
 {
	 // read HTS from register settings
	 int HTS;

	 HTS = OV2659ReadReg( 0x380c);
	 HTS = (HTS<<8) + OV2659ReadReg( 0x380d);

	 return HTS;
 }

 int OV2659_get_VTS()
 {
	 // read VTS from register settings
	 int VTS;

	 VTS = OV2659ReadReg( 0x380e);
	 VTS = (VTS<<8) + OV2659ReadReg( 0x380f);

	 return VTS;
 }

  int OV2659_set_VTS(int VTS)
 {
	 // write VTS to registers
	 int temp;

	 temp = VTS & 0xff;
	 OV2659WriteReg( 0x380f, temp);

	 temp = VTS>>8;
	 OV2659WriteReg( 0x380e, temp);

	 return 0;
 }

 int OV2659_get_binning_factor()
 {
	 // read VTS from register settings
	 int temp, binning;

	 temp = OV2659ReadReg( 0x3821);
	 if (temp & 0x01) {
		 binning = 2;
	 }
	 else {
		 binning = 1;
	 }

	 return binning;
 }

 int OV2659_get_light_frequency()
 {
	 // get light frequency
	 int temp, light_frequency;

	 temp = OV2659ReadReg( 0x3a05);

	 if (temp & 0x80) {
		 // 60Hz
		 light_frequency = 60;
	 }
	 else {
		 // 50Hz
		 light_frequency = 50;
	 }
	 return light_frequency;
 }

void ChangeNightMode(int NightMode)

{

 int temp;

 switch (NightMode)
 {

 case 0://Off
	 temp = OV2659ReadReg(  0x3a00);
	 temp = temp & 0xfb;			// night mode off, bit[2] = 0
	 OV2659WriteReg(  0x3a00, temp);

	 break;

 case 1:// on
	 temp = OV2659ReadReg(  0x3a00);
	 temp = temp | 0x04;			// night mode on, bit[2] = 1
	 OV2659WriteReg(  0x3a00, temp);
	 break;

 default:
	 break;

 }
}

//////////////////////////////////////////add_end/////////////////////////////////////////

/*************************************************************************
* FUNCTION
*    OV2659Capture
*
* DESCRIPTION
*    This function set to capture mode
*
* PARAMETERS
*    Id, In, Out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV2659Capture(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
  kal_uint8 StartX = 1, StartY = 1;
  kal_uint32 shutter = 0, temp_reg = 0;
  kal_uint32 prev_line_len = 0;
  kal_uint32 cap_line_len = 0;

#ifdef OV2659_DEBUG
  kal_wap_trace(MOD_ENG,TRACE_INFO, "OV2659 Capture");
#endif
 
  OV2659Sensor.IsPVmode = KAL_FALSE;
  
  shutter=OV2659ReadShutter();
  OV2659Sensor.SensorGain=OV2659ReadSensorGain();

  #ifdef OVT_AUTOUV
	if(!(OV2659ReadReg(0x507b)&0xF8))
	{
		//calculater auto uv
		temp_reg = OV2659ReadReg(0x5238);
		OV2659WriteReg(0x507a, OV2659ReadReg(0x507a)|0x10);	
    	// Sat
		OV2659WriteReg(0x507e,temp_reg);
		OV2659WriteReg(0x507f,temp_reg);
	}
 #endif
  
  if (In->ImageTargetWidth <= OV2659_IMAGE_SENSOR_SVGA_WIDTH && In->ImageTargetHeight <= OV2659_IMAGE_SENSOR_SVGA_HEIGHT)
  {
  	OV2659Sensor.CapturePclk = OV2659Sensor.PreviewPclk;   //Don't need change the clk for pv capture
  	
  	OV2659Sensor.CaptureDummyPixels = 0;
  	OV2659Sensor.CaptureDummyLines = 0;
  	OV2659SetDummy(OV2659Sensor.CaptureDummyPixels, OV2659Sensor.CaptureDummyLines);

  	prev_line_len = OV2659_PV_PERIOD_PIXEL_NUMS + OV2659Sensor.PreviewDummyPixels;
  	cap_line_len = OV2659_PV_PERIOD_PIXEL_NUMS + OV2659Sensor.CaptureDummyPixels;
  	shutter = (shutter * OV2659Sensor.CapturePclk) / OV2659Sensor.PreviewPclk;
  	shutter = (shutter * prev_line_len) / cap_line_len;
  	OV2659WriteShutter(shutter);

  	OV2659WriteSensorGain(OV2659Sensor.SensorGain);

  	Out->GrabStartX = StartX;
  	Out->GrabStartY = StartY;
  	Out->ExposureWindowWidth = OV2659_PV_GRAB_WIDTH;- 2 * StartX;
  	Out->ExposureWindowHeight = OV2659_PV_GRAB_HEIGHT - 2 * StartY;
  }
  else if (In->ImageTargetWidth <= OV2659_IMAGE_SENSOR_UVGA_WITDH && In->ImageTargetHeight <= OV2659_IMAGE_SENSOR_UVGA_HEIGHT)
  {
///////////////////////////////////Add_AEC_AGC_transfer1 by tony_8_31 start////////////////////////////
	 int preview_shutter, preview_gain16, preview_PCLK, preview_HTS, preview_binning;
	 int capture_shutter, capture_gain16, capture_PCLK, capture_HTS, capture_VTS;
	 int light_frequency, capture_bandingfilter, capture_max_band;
	 long capture_gain16_shutter;
	


	 // read preview shutter
	 preview_shutter = OV2659_get_shutter();

	 // read preview gain
	 preview_gain16 = OV2659_get_gain16();

	 // read preview PCLK
	 preview_PCLK = OV2659_get_PCLK();

	 // read preview HTS
	 preview_HTS = OV2659_get_HTS();

	 // get preview binning factor
	 preview_binning = OV2659_get_binning_factor();

	 // turn off night mode for capture
	 ChangeNightMode(0);
///////////////////////////////////////add_end/////////////////////

  	kal_sleep_task(10);

  	OV2659FullSizeCaptureSetting();
	
  	OV2659Sensor.CapturePclk = 480;  

	OV2659Sensor.CaptureDummyPixels = 0;
  	OV2659Sensor.CaptureDummyLines = 0;
	OV2659SetDummy(OV2659Sensor.CaptureDummyPixels, OV2659Sensor.CaptureDummyLines);
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#ifdef BINNING_EN/* By sensor design */
/* under construction !*/
 	#endif
/* under construction !*/
	#else
		OV2659TransferAECAGC(OV2659Sensor.PreviewPclk,OV2659Sensor.CapturePclk);
	#endif
  	OV2659WriteShutter(shutter);

///////////////////////////////////Add_AEC_AGC_transfer2 by tony_8_31 start////////////////////////////

	 // Write preview table
	 /*for (int i=0; i<sizeof(regCapture)/sizeof(int); i+=3)
	 {
		WriteSCCB(regCapture[i], regCapture[i+1], regCapture[i+2]);
	 }*/

	 // read capture PCLK
	 capture_PCLK = OV2659_get_PCLK();

	 // read capture HTS
	 capture_HTS = OV2659_get_HTS();

	 // read capture VTS
	 capture_VTS = OV2659_get_VTS();

	 // calculate capture banding filter
	 light_frequency = OV2659_get_light_frequency();
	 if (light_frequency == 60) {
		 // 60Hz
		 capture_bandingfilter = capture_PCLK * 100/capture_HTS * 100/120; 
	 }
	 else {
		 // 50Hz
		 capture_bandingfilter = capture_PCLK * 100/capture_HTS; 
	 }

	 if(Night_mode_flag==1)
	 {
	 	capture_max_band = 5*capture_VTS/capture_bandingfilter;
	 }
	 else
	 {
	 	capture_max_band = capture_VTS/capture_bandingfilter;
	 }
	 // calculate capture shutter
	 capture_shutter = preview_shutter  *  preview_binning * capture_PCLK/preview_PCLK * preview_HTS/capture_HTS;
	if(capture_shutter == 0){
	 capture_shutter =1;
	}
	 // gain to shutter
	 capture_gain16 = preview_gain16;
	 if (capture_gain16 < 16) {
		 capture_gain16 = 16;
	 }
	 
	 capture_gain16_shutter = capture_gain16 * capture_shutter;

	 if(capture_gain16_shutter < (capture_bandingfilter * 16)) {
		 // shutter < 1/100
		 capture_shutter = capture_gain16_shutter/16;
		 capture_gain16 = capture_gain16_shutter/capture_shutter;
	 }
	 else {
		 if(capture_gain16_shutter > (capture_bandingfilter*capture_max_band*16)) {
			 // exposure reach max
			 capture_shutter = capture_bandingfilter*capture_max_band;
			 capture_gain16 = capture_gain16_shutter / capture_shutter;
		 }
		 else {
			 // 1/100 < capture_shutter < max, capture_shutter = n/100
			 capture_shutter = ( (capture_gain16_shutter/16)/capture_bandingfilter) * capture_bandingfilter;
			 capture_gain16 = capture_gain16_shutter / capture_shutter;
		 }
	 }


	 // write capture gain
	 OV2659_set_gain16(capture_gain16);

	 // write capture shutter
	 if (capture_shutter > (capture_VTS - 4)) {
		 capture_VTS = capture_shutter + 4;
		 OV2659_set_VTS(capture_VTS);
	 }
	 OV2659_set_shutter(capture_shutter);
/////////////////////////////////////Add_AEC_AGC_transfer end//////////////////////////////////

	Out->WaitStableFrameNum = 3;
			
	Out->GrabStartX = StartX;
  	Out->GrabStartY = StartY;
  	Out->ExposureWindowWidth = OV2659_FULL_GRAB_WIDTH;- 2 * StartX;
  	Out->ExposureWindowHeight = OV2659_FULL_GRAB_HEIGHT - 2 * StartY;

  }

  OV2659SetHVMirror(ImageMirror);
}


/*************************************************************************
* FUNCTION
*    OV2659SensorOpen
*
* DESCRIPTION
*    This function read sensor Id and init sensor
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
static MM_ERROR_CODE_ENUM OV2659SensorOpen(void)
{
  if (OV2659_SENSOR_ID != OV2659PowerOn())
  {
    return MM_ERROR_SENSOR_READ_ID_FAIL;
  }
#ifdef OV2659_LOAD_FROM_T_FLASH
    if (!OV2659_Initialize_from_T_Flash()) /* for debug use. */
#endif
{
  OV2659InitialSetting();
}
  OV2659Sensor.VideoMode = KAL_FALSE;
  OV2659Sensor.NightMode = KAL_FALSE;
  OV2659Sensor.Banding = CAM_BANDING_50HZ;
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
  OV2659Sensor.Pclk = 26000000;
#else
  OV2659Sensor.Pclk = 24000000;
#endif

  OV2659Sensor.Fps = 10 * OV2659_FRAME_RATE_UNIT;
  OV2659Sensor.ShutterStep= 0xb8;////band step for 50hz
  
  return MM_ERROR_NONE;
}



/*************************************************************************
* FUNCTION
*    OV2659SensorCtrl
*
* DESCRIPTION
*    This function set sensor scenario mode
*
* PARAMETERS
*    Id: scenario Id
*    In/Out: parameter
*    OutLen: Out parameter length
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV2659SensorCtrl(CAL_SCENARIO_ENUM Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
  switch (Id)
  {
  case CAL_SCENARIO_CAMERA_PREVIEW:
  case CAL_SCENARIO_VIDEO:
  case CAL_SCENARIO_WEBCAM_PREVIEW:
  case CAL_SCENARIO_WEBCAM_CAPTURE:
    //OV2659Preview(Id, In, Out);//Tony_8_31
	 OV2659Preview(Id, (P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT)In, (P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT)Out);
    break;
  case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
    //OV2659Capture(Id, In, Out);//Tony_8_31
	  OV2659Capture(Id, (P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT)In, (P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT)Out);
    break;
  default:
    break;
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV2659SensorClose
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
static MM_ERROR_CODE_ENUM OV2659SensorClose(void)
{
  /* power down sensor */
  CamPdnPinCtrl(OV2659Sensor.SensorIdx, 1);
  CamRstPinCtrl(OV2659Sensor.SensorIdx, 0);
  CisModulePowerOn(OV2659Sensor.SensorIdx, KAL_FALSE);
  CameraSccbClose(CAMERA_SCCB_SENSOR);
  
  return MM_ERROR_NONE;
}
/*************************************************************************
* FUNCTION
*    OV2659DetectSensorId
*
* DESCRIPTION
*    This function detect sensor Id
*
* PARAMETERS
*    None
*
* RETURNS
*    sensor Id
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint32 OV2659DetectSensorId(void)
{
  //MM_ERROR_CODE_ENUM OV2659SensorClose(void);//Tony_8_31
  //kal_uint16 OV2659PowerOn();//Tony_8_31
  kal_uint16 SensorId;
  IMAGE_SENSOR_INDEX_ENUM AnotherSensorIdx;
  kal_int8 i, j;
  
  if (IMAGE_SENSOR_MAIN == OV2659Sensor.SensorIdx)
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
      SensorId = OV2659PowerOn();
      OV2659SensorClose();
#ifdef OV2659_DEBUG
      kal_wap_trace(MOD_ENG,TRACE_INFO,"OV2659DetectSensorId:%x",SensorId);
#endif
      if (OV2659_SENSOR_ID == SensorId)
      {
        return OV2659_SENSOR_ID;
      }
    }
  }
  return MM_ERROR_SENSOR_READ_ID_FAIL;
}

/*************************************************************************
* FUNCTION
*    S5K4EAGXSensorFeatureCtrl
*
* DESCRIPTION
*    This function set sensor feature mode
*
* PARAMETERS
*    id: scenario id
*    In: input parameter
*    Out: output parameter
*    OutLen: output parameter length
*    RealOutLen: real output parameter length
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV2659SensorFeatureCtrl(IMAGE_SENSOR_FEATURE_ENUM id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)//Tony_8_31
{
  MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
  kal_uint32 tmpFrameRate;
  
  if (id >= CAL_FEATURE_WEBCAM_BEGIN && id <= CAL_FEATURE_WEBCAM_END)
  {
    return OV2659WebcamFeatureCtrl(id, In, Out, OutLen, RealOutLen);
  }
  switch (id)
  {
  /* CAL query and set series */
  case CAL_FEATURE_CAMERA_BRIGHTNESS:
  case CAL_FEATURE_CAMERA_EV_VALUE:
    ErrCode = OV2659Ev((P_CAL_FEATURE_CTRL_STRUCT)In, (P_CAL_FEATURE_CTRL_STRUCT)Out);
    break;
  case CAL_FEATURE_CAMERA_CONTRAST:
    ErrCode = OV2659Contrast((P_CAL_FEATURE_CTRL_STRUCT)In, (P_CAL_FEATURE_CTRL_STRUCT)Out);
    break;
  case CAL_FEATURE_CAMERA_HUE:
  case CAL_FEATURE_CAMERA_SATURATION:
  case CAL_FEATURE_CAMERA_SHARPNESS:
  case CAL_FEATURE_CAMERA_GAMMA:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  case CAL_FEATURE_CAMERA_WB:
    ErrCode = OV2659Wb((P_CAL_FEATURE_CTRL_STRUCT)In, (P_CAL_FEATURE_CTRL_STRUCT)Out);
    break;
  case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
    ErrCode = OV2659Effect((P_CAL_FEATURE_CTRL_STRUCT)In,(P_CAL_FEATURE_CTRL_STRUCT)Out);
    break;
  case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
    ErrCode = OV2659StillCaptureSize((P_CAL_FEATURE_CTRL_STRUCT)In, (P_CAL_FEATURE_CTRL_STRUCT)Out);
    break;
  case CAL_FEATURE_CAMERA_BANDING_FREQ: /* move to preview */
    ErrCode = OV2659Banding((P_CAL_FEATURE_CTRL_STRUCT)In, (P_CAL_FEATURE_CTRL_STRUCT)Out);
    break;
  case CAL_FEATURE_CAMERA_SCENE_MODE:
    ErrCode = OV2659SceneMode(KAL_TRUE, (P_CAL_FEATURE_CTRL_STRUCT)In, (P_CAL_FEATURE_CTRL_STRUCT)Out);
    break;
  case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
    ErrCode = OV2659SceneMode(KAL_FALSE, (P_CAL_FEATURE_CTRL_STRUCT)In, (P_CAL_FEATURE_CTRL_STRUCT)Out);
    break;
  case CAL_FEATURE_CAMERA_FLASH_MODE:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  case CAL_FEATURE_CAMERA_DIGITAL_ZOOM:
    //ErrCode = OV2659GetZoomInfo(In, Out);//Tony_8_31
    break;
  
  /* get info series */
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
    OV2659GetSensorInfo((P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT)Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = OV2659DetectSensorId();
    break;
  case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
    ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = OV2659Sensor.Fps * 10 / OV2659_FRAME_RATE_UNIT;
    break;
  case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
    OV2659InitOperationPara((P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT)Out);
    break;
  case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
    //CamGetHWInfo(Out);
    break;
  
  /* set para series */
  case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
    CamPdnPinCtrl(OV2659Sensor.SensorIdx, 1);
    CamRstPinCtrl(OV2659Sensor.SensorIdx, 0);
    break;
  case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
    OV2659Sensor.NvramData = &(((nvram_camera_para_struct *)In)->SENSOR);
    break;
  case IMAGE_SENSOR_FEATURE_VSYNC_HISR_INFORM_FRAME_TIME:
    tmpFrameRate = ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
    break;
  case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
    OV2659Sensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
    break;
  case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
    break;
  default:
    ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  }
  return ErrCode;
}
/*************************************************************************
* FUNCTION
*    OV2659SensorFunc
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
MM_ERROR_CODE_ENUM OV2659SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncOV2659 =
  {
    OV2659SensorOpen,
    OV2659SensorFeatureCtrl,
    OV2659SensorCtrl,
    OV2659SensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncOV2659;
  
  return MM_ERROR_NONE;
}

#ifdef OV2659_DEBUG

void OV2659_at_test_func(kal_uint32 *d)
 {
 	kal_int32 i,base,read_value;
 	switch (d[1])
    {
	case 0:
		 kal_prompt_trace(MOD_ENG,"IspCurrentFrameRate=%d",IspCurrentFrameRate);
		 break;
	 default:
		 break;
 	}
	 
 }
#endif
