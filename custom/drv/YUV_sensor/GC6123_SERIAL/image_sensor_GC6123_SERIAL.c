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
 *   image_sensor_GC6123_SERIAL.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Image sensor driver function_11A&11B
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
 *
 * removed!
 *
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
 *
 *
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
    kal_bool BypassAe;
    kal_bool BypassAwb;
    kal_bool CapState; /* KAL_TRUE: in capture state, else in preview state */
    kal_bool PvMode; /* KAL_TRUE: preview size output, else full size output */
    kal_bool sccb_opened;
	kal_bool VideoMode; /* KAL_TRUE: video mode, else preview mode */
	kal_bool NightMode;/*KAL_TRUE:work in night mode, else normal mode*/
    kal_uint8 BandingFreq; /* GC6123_SERIAL_50HZ or GC6123_SERIAL_60HZ for 50Hz/60Hz */
    kal_uint32 InternalClock; /* internal clock which using process pixel(for exposure) */
    kal_uint32 Pclk; /* output clock which output to baseband */
    kal_uint32 Gain; /* base on 0x40 */
    kal_uint32 Shutter; /* unit is (linelength / internal clock) s */
    kal_uint32 FrameLength; /* total line numbers in one frame(include dummy line) */
    kal_uint32 LineLength; /* total pixel numbers in one line(include dummy pixel) */
    IMAGE_SENSOR_INDEX_ENUM SensorIdx;
    sensor_data_struct *NvramData;
} GC6123_SERIALSensor;

#define GC6123_SERIAL_SET_PAGE0 CamWriteCmosSensor(0xfe , 0x00)
#define GC6123_SERIAL_SET_PAGE1 CamWriteCmosSensor(0xfe , 0x01)
#define GC6123_SERIAL_SET_PAGE2 CamWriteCmosSensor(0xfe , 0x02)
kal_bool GC6123_SERIAL_CAM_BANDING_50HZ = KAL_FALSE;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

#ifdef GC6123_SERIAL_LOAD_FROM_T_FLASH
/*************************************************************************
* FUNCTION
*  GC6123_SERIAL_Initialize_from_T_Flash
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
static kal_uint8 GC6123_SERIAL_Initialize_from_T_Flash()
{
#include <stdlib.h>
#include "med_utility.h"
#include "fs_type.h"

#if GC6123_SERIAL_I2C_ADDR_BITS == CAMERA_SCCB_16BIT
    #define GC6123_SERIAL_REG_SKIP    0x08
#else
    #define GC6123_SERIAL_REG_SKIP    0x06
#endif
#if GC6123_SERIAL_I2C_DATA_BITS == CAMERA_SCCB_16BIT
    #define GC6123_SERIAL_VAL_SKIP    0x08
#else
    #define GC6123_SERIAL_VAL_SKIP    0x06
#endif
  
    /* 0 - Initial value, 1 - Register, 2 - Delay, 3 - End of setting. */
    #define GC6123_SERIAL_OP_CODE_INI    0x00    /* Initial value. */
    #define GC6123_SERIAL_OP_CODE_REG    0x01    /* Register */
    #define GC6123_SERIAL_OP_CODE_DLY    0x02    /* Delay */
    #define GC6123_SERIAL_OP_CODE_END    0x03    /* End of initial setting. */

    typedef struct
    {
        kal_uint16 init_reg;
        kal_uint16 init_val;  /* Save the register value and delay tick */
        kal_uint8 op_code;    /* 0 - Initial value, 1 - Register, 2 - Delay, 3 - End of setting. */
    } GC6123_SERIAL_initial_set_struct;
  
    static GC6123_SERIAL_initial_set_struct GC6123_SERIAL_Init_Reg[1000];
    static WCHAR GC6123_SERIAL_set_file_name[256] = {0};
    FS_HANDLE fp = -1;        /* Default, no file opened. */
    kal_uint8 *data_buff = NULL;
    kal_uint8 *curr_ptr = NULL;
    kal_uint32 file_size = 0;
    kal_uint32 bytes_read = 0;
    kal_uint32 i = 0, j = 0;
    kal_uint8 func_ind[3] = {0};  /* REG or DLY */
    
    kal_mem_cpy(GC6123_SERIAL_set_file_name, L"C:\\GC6123_SERIAL_Initialize_Setting.Bin", sizeof(L"C:\\GC6123_SERIAL_Initialize_Setting.Bin"));
    
    /* Search the setting file in all of the user disk. */
    curr_ptr = (kal_uint8 *)GC6123_SERIAL_set_file_name;
    while (fp < 0)
    {
        if ((*curr_ptr >= 'c' && *curr_ptr <= 'z') || (*curr_ptr >= 'C' && *curr_ptr <= 'Z'))
        {
            fp = FS_Open(GC6123_SERIAL_set_file_name, FS_READ_ONLY);
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
        GC6123_SERIAL_TRACE("!!! Warning, Can't find the initial setting file!!!");
        return 0;
    }
    
    FS_GetFileSize(fp, &file_size);
    if (file_size < 20)
    {
        GC6123_SERIAL_TRACE("!!! Warning, Invalid setting file!!!");
        return 0;      /* Invalid setting file. */
    }
    
    data_buff = med_alloc_ext_mem(file_size);
    if (data_buff == NULL)
    {
        GC6123_SERIAL_TRACE("!!! Warning, Memory not enoughed...");
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
            GC6123_SERIAL_Init_Reg[i].op_code = GC6123_SERIAL_OP_CODE_REG;
      
            GC6123_SERIAL_Init_Reg[i].init_reg = strtol((const char *)curr_ptr, NULL, 16);
            curr_ptr += GC6123_SERIAL_REG_SKIP;  /* Skip "0x0000, " */
      
            GC6123_SERIAL_Init_Reg[i].init_val = strtol((const char *)curr_ptr, NULL, 16);
            curr_ptr += GC6123_SERIAL_VAL_SKIP;  /* Skip "0x0000);" */
        }
        else                  /* DLY */
        {
            /* Need add delay for this setting. */
            GC6123_SERIAL_Init_Reg[i].op_code = GC6123_SERIAL_OP_CODE_DLY;
      
            GC6123_SERIAL_Init_Reg[i].init_reg = 0xFF;
            GC6123_SERIAL_Init_Reg[i].init_val = strtol((const char *)curr_ptr, NULL, 10);  /* Get the delay ticks, the delay should less then 50 */
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
    GC6123_SERIAL_Init_Reg[i].op_code = GC6123_SERIAL_OP_CODE_END;
    GC6123_SERIAL_Init_Reg[i].init_reg = 0xFF;
    GC6123_SERIAL_Init_Reg[i].init_val = 0xFF;
    i++;

    GC6123_SERIAL_TRACE("%d register read...", i - 1);
    med_free_ext_mem((void **)&data_buff);
    FS_Close(fp);

    GC6123_SERIAL_TRACE("Start apply initialize setting.");
    /* Start apply the initial setting to sensor. */
    for (j=0; j<i; j++)
    {
        if (GC6123_SERIAL_Init_Reg[j].op_code == GC6123_SERIAL_OP_CODE_END)  /* End of the setting. */
        {
            break ;
        }
        else if (GC6123_SERIAL_Init_Reg[j].op_code == GC6123_SERIAL_OP_CODE_DLY)
        {
            kal_sleep_task(GC6123_SERIAL_Init_Reg[j].init_val);    /* Delay */
        }
        else if (GC6123_SERIAL_Init_Reg[j].op_code == GC6123_SERIAL_OP_CODE_REG)
        {
            CamWriteCmosSensor(GC6123_SERIAL_Init_Reg[j].init_reg, GC6123_SERIAL_Init_Reg[j].init_val);
        }
        else
        {
            ASSERT(0);
        }
    }
    GC6123_SERIAL_TRACE("%d register applied...", j);
    return 1;  
}
#endif

/*************************************************************************
* FUNCTION
*   GC6123_SERIALSetMirror
*
* DESCRIPTION
*   This function set the mirror to the CMOS sensor
*   IMPORTANT NOTICE:
*     the color should be normal when mirror or flip
*
* PARAMETERS
*   Mirror
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC6123_SERIALSetMirror(kal_uint8 Mirror)
{
	// TODO: set mirror&flip here
	CamWriteCmosSensor(0xfe, 0x00);
	switch (Mirror)
	{
		case IMAGE_SENSOR_MIRROR_H:
			CamWriteCmosSensor(0x14, 0x11);
			break;
		case IMAGE_SENSOR_MIRROR_V:
			CamWriteCmosSensor(0x14, 0x12);
			break;
		case IMAGE_SENSOR_MIRROR_HV:
			CamWriteCmosSensor(0x14, 0x13);
			break;
		default:
			CamWriteCmosSensor(0x14, 0x10);
			break;
	}
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALSetClock
*
* DESCRIPTION
*   This function set sensor internal clock and output clock
*
* PARAMETERS
*   Clk: internal clock
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC6123_SERIALSetClock(kal_uint32 InternalClock)
{
    if (GC6123_SERIALSensor.InternalClock == InternalClock)
    {
        return;
    }
    GC6123_SERIALSensor.InternalClock = InternalClock;
    // TODO: set internal clock(use process pixel) and output clock(ouput to baseband) here
    {
    	 kal_uint8 ClkDiv;
        /* add PLL comment here */
        switch (InternalClock)
        {
		case GC6123_SERIAL_MCLK / 2:
			ClkDiv = 0x00; 
			break; /* pclk = mclk */
		case GC6123_SERIAL_MCLK / 4: 
			ClkDiv = 0x11; 
			break; /* pclk = mclk / 2 */
		case GC6123_SERIAL_MCLK / 8: 
			ClkDiv = 0x32; 
			break; /* pclk = mclk / 4 */
		default: ASSERT(0);
        }
	 CamWriteCmosSensor(0xfa, ClkDiv);
    }
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALWriteShutter
*
* DESCRIPTION
*   This function apply shutter to sensor
*
* PARAMETERS
*   Shutter: integration time, unit: (linelength / internal clock) s
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC6123_SERIALWriteShutter(kal_uint32 Shutter)
{
    // TODO: set integration time here
	CamWriteCmosSensor(0x03, Shutter >> 8);
	CamWriteCmosSensor(0x04, Shutter);    
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALReadShutter
*
* DESCRIPTION
*   This function get shutter from sensor
*
* PARAMETERS
*   None
*
* RETURNS
*   Shutter: integration time, unit: (linelength / internal clock) s
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint32 GC6123_SERIALReadShutter(void)
{
    // TODO: read integration time here
	return (CamReadCmosSensor(0x03) << 8)|CamReadCmosSensor(0x04);
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALWriteGain
*
* DESCRIPTION
*   This function apply global gain to sensor
*
* PARAMETERS
*   Gain: base on 0x40
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC6123_SERIALWriteGain(kal_uint32 Gain)
{
    // TODO: set global gain here
    
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALReadGain
*
* DESCRIPTION
*   This function get global gain from sensor
*
* PARAMETERS
*   None
*
* RETURNS
*   Gain: base on 0x40
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint32 GC6123_SERIALReadGain(void)
{
    // TODO: read global gain here
    
    return 0x40;
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALAeEnable
*
* DESCRIPTION
*   disable/enable AE
*
* PARAMETERS
*   Enable
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC6123_SERIALAeEnable(kal_bool Enable)
{
	kal_uint16 temp_ae_reg;
	if (GC6123_SERIALSensor.BypassAe)
	{
		Enable = KAL_FALSE;
	}
	
	// TODO: enable or disable AE here
	{
		CamWriteCmosSensor(0xfe, 0x00);
		temp_ae_reg = CamReadCmosSensor(0xa4);
		if (Enable)
		{
	    		CamWriteCmosSensor(0xa4, (temp_ae_reg | 0x01));
		}
		else
		{
	    		CamWriteCmosSensor(0xa4, (temp_ae_reg & (~0x01))); /* Turn OFF AEC/AGC*/
		}
	}
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALAwbEnable
*
* DESCRIPTION
*   disable/enable awb
*
* PARAMETERS
*   Enable
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC6123_SERIALAwbEnable(kal_bool Enable)
{
	kal_uint16 temp_awb_reg;
	if (GC6123_SERIALSensor.BypassAwb)
	{
		Enable = KAL_FALSE;
	}
	
	// TODO: enable or disable AWB here
	{
		CamWriteCmosSensor(0xfe, 0x00);
		temp_awb_reg = CamReadCmosSensor(0x22);
		if (Enable)
		{
	    		CamWriteCmosSensor(0x22, (temp_awb_reg | 0x02));
		}
		else
		{
	    		CamWriteCmosSensor(0x22, (temp_awb_reg & (~0x02))); /* Turn OFF AWB*/
		}
	}
}

/*************************************************************************
* FUNCTION
*    GC6123_SERIALSetBandingStep
*
* DESCRIPTION
*    This function set base shutter or banding step to the CMOS sensor
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
static void GC6123_SERIALSetBandingStep(void)
{
    // TODO: set banding step here
    
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALSetDummy
*
* DESCRIPTION
*   This function set the dummy pixels(Horizontal Blanking) & dummy lines(Vertical Blanking), it can be
*   used to adjust the frame rate or gain more time for back-end process.
*
* PARAMETERS
*   DummyPixel
*   DummyLine
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC6123_SERIALSetDummy(kal_uint32 DummyPixel, kal_uint32 DummyLine)
{
    kal_uint32 LineLength, FrameLength;

    if (GC6123_SERIALSensor.PvMode) /* preview size output mode */
    {
        LineLength = DummyPixel + GC6123_SERIAL_PV_PERIOD_PIXEL_NUMS;
        FrameLength = DummyLine + GC6123_SERIAL_PV_PERIOD_LINE_NUMS;
    }
    else
    {
        LineLength = DummyPixel + GC6123_SERIAL_FULL_PERIOD_PIXEL_NUMS;
        FrameLength = DummyLine + GC6123_SERIAL_FULL_PERIOD_LINE_NUMS;
    }

    // TODO: set linelength/framelength or dummy pixel/line and return right value here
    {
        
    }

    /* config banding step or base shutter */
    if (GC6123_SERIALSensor.PvMode) /* preview size output mode */
    {
        GC6123_SERIALSetBandingStep();
    }
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALSetMinFps
*
* DESCRIPTION
*   This function calculate & set min frame rate
*
* PARAMETERS
*   Fps: min frame rate, base on GC6123_SERIAL_FPS(x)
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC6123_SERIALSetMinFps(kal_uint16 Fps)
{
    // TODO: set max exposure time or max AE index here
    
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALSetMaxFps
*
* DESCRIPTION
*   This function calculate & set max frame rate
*
* PARAMETERS
*   Fps: max frame rate, base on GC6123_SERIAL_FPS(x)
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC6123_SERIALSetMaxFps(kal_uint16 Fps)
{
    kal_uint32 LineLength, FrameLength;

    /* get max line length */
    LineLength = GC6123_SERIALSensor.InternalClock * GC6123_SERIAL_FPS(1) / (Fps * GC6123_SERIAL_PV_PERIOD_LINE_NUMS);
    if (LineLength > GC6123_SERIAL_MAX_PV_LINELENGTH) /* overflow check */
    {
        LineLength = GC6123_SERIAL_MAX_PV_LINELENGTH;
    }
    if (LineLength < GC6123_SERIAL_PV_PERIOD_PIXEL_NUMS)
    {
        LineLength = GC6123_SERIAL_PV_PERIOD_PIXEL_NUMS;
    }

    /* get frame height */
    FrameLength = GC6123_SERIALSensor.InternalClock * GC6123_SERIAL_FPS(1) / (Fps * LineLength);
    if (FrameLength > GC6123_SERIAL_MAX_PV_FRAMELENGTH) /* overflow check */
    {
        FrameLength = GC6123_SERIAL_MAX_PV_FRAMELENGTH;
    }
    if (FrameLength < GC6123_SERIAL_PV_PERIOD_LINE_NUMS)
    {
        FrameLength = GC6123_SERIAL_PV_PERIOD_LINE_NUMS;
    }

    /* limit max frame rate to Fps specified */
    GC6123_SERIALSetDummy(LineLength - GC6123_SERIAL_PV_PERIOD_PIXEL_NUMS, FrameLength - GC6123_SERIAL_PV_PERIOD_LINE_NUMS);
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALSetVideoFps
*
* DESCRIPTION
*   This function calculate & fix frame rate in video mode
*
* PARAMETERS
*   Fps: target frame rate to fixed, base on GC6123_SERIAL_FPS(x)
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC6123_SERIALSetVideoFps(kal_uint16 Fps)
{
    /* limit max frame rate */
    GC6123_SERIALSetMaxFps(Fps);

    // TODO: fix, set max exposure time or max AE index here
    {
        
    }
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALNightMode
*
* DESCRIPTION
*   This function set night mode to sensor.
*
* PARAMETERS
*   Enable
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC6123_SERIALNightMode(kal_bool Enable)
{
    // TODO: set night mode here
    
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALEv
*
* DESCRIPTION
*   Exposure setting.
*
* PARAMETERS
*   In, Out
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM GC6123_SERIALEv(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        const P_CAL_FEATURE_TYPE_ENUM_STRUCT Exposure = &Out->FeatureInfo.FeatureEnum;

        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
        // TODO: add supported EV enum here
        Exposure->IsSupport = KAL_TRUE;
        Exposure->ItemCount = 9;
        Exposure->SupportItem[0] = CAM_EV_NEG_4_3;
        Exposure->SupportItem[1] = CAM_EV_NEG_3_3;
        Exposure->SupportItem[2] = CAM_EV_NEG_2_3;
        Exposure->SupportItem[3] = CAM_EV_NEG_1_3;
        Exposure->SupportItem[4] = CAM_EV_ZERO;
        Exposure->SupportItem[5] = CAM_EV_POS_1_3;
        Exposure->SupportItem[6] = CAM_EV_POS_2_3;
        Exposure->SupportItem[7] = CAM_EV_POS_3_3;
        Exposure->SupportItem[8] = CAM_EV_POS_4_3;
    }
    else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
    {
    	 // TODO: adjust brightness here

		 CamWriteCmosSensor(0xfe, 0x00);
        switch (In->FeatureSetValue)
        {
		case CAM_EV_NEG_4_3:							/* EV -2 */
			CamWriteCmosSensor(0x92, 0x60);
			CamWriteCmosSensor(0x85, 0xc0);
			break;
		case CAM_EV_NEG_3_3:							/* EV -1.5 */
			CamWriteCmosSensor(0x92, 0x68);
			CamWriteCmosSensor(0x85, 0xd0);
			break;
		case CAM_EV_NEG_2_3:							/* EV -1 */
			CamWriteCmosSensor(0x92, 0x70);
			CamWriteCmosSensor(0x85, 0xe0);
			break;
		case CAM_EV_NEG_1_3:							/* EV -0.5 */
			CamWriteCmosSensor(0x92, 0x78);
			CamWriteCmosSensor(0x85, 0xf0);
			break;
		case CAM_EV_ZERO:								/* EV 0 */
			CamWriteCmosSensor(0x92, 0x80);
			CamWriteCmosSensor(0x85, 0x00);
			break;
		case CAM_EV_POS_1_3:							/* EV +0.5 */
			CamWriteCmosSensor(0x92, 0x88);
			CamWriteCmosSensor(0x85, 0x10);
			break;
		case CAM_EV_POS_2_3:							/* EV +1 */
			CamWriteCmosSensor(0x92, 0x90);
			CamWriteCmosSensor(0x85, 0x20);
			break;
		case CAM_EV_POS_3_3:							/* EV +1.5 */
			CamWriteCmosSensor(0x92, 0x98);
			CamWriteCmosSensor(0x85, 0x30);
			break;
		case CAM_EV_POS_4_3:							/* EV +2 */
			CamWriteCmosSensor(0x92, 0xa0);
			CamWriteCmosSensor(0x85, 0x40);
			break;
		default:
	      return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        }
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALContrast
*
* DESCRIPTION
*   Contrast setting.
*
* PARAMETERS
*   In, Out
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM GC6123_SERIALContrast(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        const P_CAL_FEATURE_TYPE_ENUM_STRUCT Contrast = &Out->FeatureInfo.FeatureEnum;

        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
        // TODO: add supported contrast enum here
        Contrast->IsSupport = KAL_TRUE;
        Contrast->ItemCount = 3;
        Contrast->SupportItem[0] = CAM_CONTRAST_HIGH;
        Contrast->SupportItem[1] = CAM_CONTRAST_MEDIUM;
        Contrast->SupportItem[2] = CAM_CONTRAST_LOW;
    }
    else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
    {
        // TODO: adjust contrast here
        CamWriteCmosSensor(0xfe, 0x00);
        switch (In->FeatureSetValue)
        {
        case CAM_CONTRAST_HIGH:
            CamWriteCmosSensor(0x83, 0x48);
            break;
        case CAM_CONTRAST_MEDIUM:
            CamWriteCmosSensor(0x83, 0x40);
            break;
        case CAM_CONTRAST_LOW:
            CamWriteCmosSensor(0x83, 0x38);
            break;
        default:
            return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        }
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALSaturation
*
* DESCRIPTION
*   Saturation setting.
*
* PARAMETERS
*   In, Out
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM GC6123_SERIALSaturation(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        const P_CAL_FEATURE_TYPE_ENUM_STRUCT Saturation = &Out->FeatureInfo.FeatureEnum;

        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
        // TODO: add supported saturation enum here
        Saturation->IsSupport = KAL_FALSE;
        //Saturation->ItemCount = 3;
        //Saturation->SupportItem[0] = CAM_SATURATION_HIGH;
        //Saturation->SupportItem[1] = CAM_SATURATION_MEDIUM;
        //Saturation->SupportItem[2] = CAM_SATURATION_LOW;
    }
    else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
    {
        // TODO: adjust saturation here
        //switch (In->FeatureSetValue)
        //{
        //case CAM_SATURATION_HIGH:
            /* add setting here */
        //    break;
        //case CAM_SATURATION_MEDIUM:
            /* add setting here */
        //    break;
        //case CAM_SATURATION_LOW:
            /* add setting here */
        //    break;
        //default:
        //    return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        //}
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALSharpness
*
* DESCRIPTION
*   Sharpness setting.
*
* PARAMETERS
*   In, Out
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM GC6123_SERIALSharpness(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        const P_CAL_FEATURE_TYPE_ENUM_STRUCT Sharpness = &Out->FeatureInfo.FeatureEnum;

        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
        // TODO: add supported sharpness enum here
        Sharpness->IsSupport = KAL_FALSE;
        //Sharpness->ItemCount = 3;
        //Sharpness->SupportItem[0] = CAM_SHARPNESS_HIGH;
        //Sharpness->SupportItem[1] = CAM_SHARPNESS_MEDIUM;
        //Sharpness->SupportItem[2] = CAM_SHARPNESS_LOW;
    }
    else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
    {
        // TODO: adjust sharpness here
        //switch (In->FeatureSetValue)
        //{
        //case CAM_SHARPNESS_HIGH:
            /* add setting here */
        //    break;
        //case CAM_SHARPNESS_MEDIUM:
            /* add setting here */
        //    break;
        //case CAM_SHARPNESS_LOW:
            /* add setting here */
        //    break;
        //default:
        //    return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        //}
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALWb
*
* DESCRIPTION
*   Wb setting.
*
* PARAMETERS
*   In, Out
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM GC6123_SERIALWb(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        const P_CAL_FEATURE_TYPE_ENUM_STRUCT Wb = &Out->FeatureInfo.FeatureEnum;

        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
        // TODO: add supported manual WB enum here
        Wb->IsSupport = KAL_TRUE;
        Wb->ItemCount = 6;
        Wb->SupportItem[0] = CAM_WB_AUTO;
        Wb->SupportItem[1] = CAM_WB_CLOUD;
        Wb->SupportItem[2] = CAM_WB_DAYLIGHT;
        Wb->SupportItem[3] = CAM_WB_INCANDESCENCE;
        Wb->SupportItem[4] = CAM_WB_FLUORESCENT;
        Wb->SupportItem[5] = CAM_WB_TUNGSTEN;
    }
    else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
    {
        // TODO: adjust manual WB here
        switch (In->FeatureSetValue)
	{
		case CAM_WB_AUTO:
			GC6123_SERIALAwbEnable(KAL_TRUE);
			break;
		case CAM_WB_CLOUD:
			GC6123_SERIALAwbEnable(KAL_FALSE);
			CamWriteCmosSensor(0xc0,0x8c); 
			CamWriteCmosSensor(0xc1,0x50);
			CamWriteCmosSensor(0xc2,0x40);
			break;
		case CAM_WB_DAYLIGHT:
			GC6123_SERIALAwbEnable(KAL_FALSE);
			CamWriteCmosSensor(0xc0,0x74); 
			CamWriteCmosSensor(0xc1,0x52);
			CamWriteCmosSensor(0xc2,0x40);	
			break;
		case CAM_WB_INCANDESCENCE:
			GC6123_SERIALAwbEnable(KAL_FALSE);
			CamWriteCmosSensor(0xc0,0x48);
			CamWriteCmosSensor(0xc1,0x40);
			CamWriteCmosSensor(0xc2,0x5c);
			break;
		case CAM_WB_FLUORESCENT:
			GC6123_SERIALAwbEnable(KAL_FALSE);
			CamWriteCmosSensor(0xc0,0x40);
			CamWriteCmosSensor(0xc1,0x42);
			CamWriteCmosSensor(0xc2,0x50);
			break;
		case CAM_WB_TUNGSTEN:
			GC6123_SERIALAwbEnable(KAL_FALSE);
			CamWriteCmosSensor(0xc0,0x40);
			CamWriteCmosSensor(0xc1,0x54);
			CamWriteCmosSensor(0xc2,0x70);
			break;
	default:
		return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
	}
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALEffect
*
* DESCRIPTION
*   Effect setting.
*
* PARAMETERS
*   In, Out
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM GC6123_SERIALEffect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        const P_CAL_FEATURE_TYPE_ENUM_STRUCT Effect = &Out->FeatureInfo.FeatureEnum;

        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
        // TODO: add supported effect enum here
        Effect->IsSupport = KAL_TRUE;
        Effect->ItemCount = 6;
        Effect->SupportItem[0] = CAM_EFFECT_ENC_NORMAL;
        Effect->SupportItem[1] = CAM_EFFECT_ENC_GRAYSCALE;
        Effect->SupportItem[2] = CAM_EFFECT_ENC_SEPIA;
        Effect->SupportItem[3] = CAM_EFFECT_ENC_SEPIAGREEN;
        Effect->SupportItem[4] = CAM_EFFECT_ENC_SEPIABLUE;
        Effect->SupportItem[5] = CAM_EFFECT_ENC_COLORINV;
    }
    else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
    {
        // TODO: adjust effect here
        switch (In->FeatureSetValue)
	{
		case CAM_EFFECT_ENC_NORMAL:
			CamWriteCmosSensor(0x23, 0x00); 
			CamWriteCmosSensor(0x8a, 0x00); 
			CamWriteCmosSensor(0x8b, 0x00); 
			break;
		case CAM_EFFECT_ENC_GRAYSCALE:
			CamWriteCmosSensor(0x23, 0x02); 
			CamWriteCmosSensor(0x8a, 0x00); 
			CamWriteCmosSensor(0x8b, 0x00); 
			break;
		case CAM_EFFECT_ENC_SEPIA:
			CamWriteCmosSensor(0x23, 0x02); 
			CamWriteCmosSensor(0x8a, 0xd0); 
			CamWriteCmosSensor(0x8b, 0x28); 
			break;
		case CAM_EFFECT_ENC_SEPIAGREEN:
			CamWriteCmosSensor(0x23, 0x02); 
			CamWriteCmosSensor(0x8a, 0xc0); 
			CamWriteCmosSensor(0x8b, 0xc0); 
			break;
		case CAM_EFFECT_ENC_SEPIABLUE:
			CamWriteCmosSensor(0x23, 0x02); 
			CamWriteCmosSensor(0x8a, 0x50); 
			CamWriteCmosSensor(0x8b, 0xe0); 
			break;
		case CAM_EFFECT_ENC_COLORINV:
			CamWriteCmosSensor(0x23, 0x01); 
			CamWriteCmosSensor(0x8a, 0x00); 
			CamWriteCmosSensor(0x8b, 0x00); 
			break;
		default:
			return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
	}
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALStillCaptureSize
*
* DESCRIPTION
*   This function get capture size
*
* PARAMETERS
*   In, Out
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM GC6123_SERIALStillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT CapSize = &Out->FeatureInfo.FeatureEnum;

    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
        CapSize->IsSupport = KAL_TRUE;
        // TODO: add supported capture size enum here
        CapSize->ItemCount = 2;
        CapSize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
        CapSize->SupportItem[1] = CAM_IMAGE_SIZE_QVGA;
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALBanding
*
* DESCRIPTION
*   This function get banding setting
*
* PARAMETERS
*   In, Out
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM GC6123_SERIALBanding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Banding = &Out->FeatureInfo.FeatureEnum;

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
        GC6123_SERIALSensor.BandingFreq = (CAM_BANDING_50HZ == In->FeatureSetValue ? GC6123_SERIAL_50HZ : GC6123_SERIAL_60HZ);
        // TODO: set manual banding here  
        GC6123_SERIAL_SET_PAGE0;
        if(GC6123_SERIALSensor.NightMode)  //Night Mode
        {
            if (CAM_BANDING_50HZ == In->FeatureSetValue)
            {		
			// based on 24M MCLK 		
				CamWriteCmosSensor(0x01, 0xb2);  //hb[7:0]
				CamWriteCmosSensor(0x02, 0x60);  //vb[7:0]
				CamWriteCmosSensor(0x0f, 0x07);  //vb[11:8] , hb[11:8] 

				CamWriteCmosSensor(0x9c, 0x00);   //step[11:8]
				CamWriteCmosSensor(0x9d, 0x35);   //step[7:0]
				if(GC6123_SERIALSensor.VideoMode)
				{
					CamWriteCmosSensor(0x9e, 0x03);   //  6.25fps
					CamWriteCmosSensor(0x9f, 0x50);
				}
				else{
					CamWriteCmosSensor(0x9e, 0x04);   //   5.00fps
					CamWriteCmosSensor(0x9f, 0x24);
				}
					
				/*CamWriteCmosSensor(0x9e, 0x01);   // level_0  12.5fps
				CamWriteCmosSensor(0x9f, 0xa8); 		
				CamWriteCmosSensor(0x9e, 0x02);   //  8.33fps
				CamWriteCmosSensor(0x9f, 0x7c);
				CamWriteCmosSensor(0x9e, 0x03);   //  6.25fps
				CamWriteCmosSensor(0x9f, 0x50);
				CamWriteCmosSensor(0x9e, 0x04);   //   5.00fps
				CamWriteCmosSensor(0x9f, 0x24);*/
			
			
			GC6123_SERIAL_CAM_BANDING_50HZ = KAL_TRUE;
            }
            else
            {			
			// based on 24M MCLK 
				CamWriteCmosSensor(0x01, 0xbb);  //hb[7:0]
				CamWriteCmosSensor(0x02, 0x70);  //vb[7:0]
				CamWriteCmosSensor(0x0f, 0x07);  //vb[11:8] , hb[11:8] 

				CamWriteCmosSensor(0x9c, 0x00);   //step[11:8]
				CamWriteCmosSensor(0x9d, 0x2c);   //step[7:0]
				
				if(GC6123_SERIALSensor.VideoMode)
				{
				CamWriteCmosSensor(0x9e, 0x03);   // level_2  6.31fps
				CamWriteCmosSensor(0x9f, 0x44);
				}
				else{
					CamWriteCmosSensor(0x9e, 0x04);   // level_3  4.99fps
					CamWriteCmosSensor(0x9f, 0x20);
				}


				/*CamWriteCmosSensor(0x9e, 0x01);   // level_0  11.99fps
				CamWriteCmosSensor(0x9f, 0xb8);  
				CamWriteCmosSensor(0x9e, 0x02);	 // level_1  7.99fps
				CamWriteCmosSensor(0x9f, 0x94);
				CamWriteCmosSensor(0x9e, 0x03);   // level_2  6.31fps
				CamWriteCmosSensor(0x9f, 0x44);
				CamWriteCmosSensor(0x9e, 0x04);   // level_3  4.99fps
				CamWriteCmosSensor(0x9f, 0x20);*/
		
				GC6123_SERIAL_CAM_BANDING_50HZ = KAL_FALSE;
            }
        	}
			else
			{
				 if (CAM_BANDING_50HZ == In->FeatureSetValue)
	            {		
				// based on 24M MCLK 
					CamWriteCmosSensor(0x01, 0xb2);  //hb[7:0]
					CamWriteCmosSensor(0x02, 0x60);  //vb[7:0]
					CamWriteCmosSensor(0x0f, 0x07);  //vb[11:8] , hb[11:8] 

					CamWriteCmosSensor(0x9c, 0x00);   //step[11:8]
					CamWriteCmosSensor(0x9d, 0x35);   //step[7:0]

					if(GC6123_SERIALSensor.VideoMode)
					{
						CamWriteCmosSensor(0x9e, 0x01);   // level_0  12.5fps
						CamWriteCmosSensor(0x9f, 0xa8); 
					}
					else{
						CamWriteCmosSensor(0x9e, 0x02);   //  8.33fps
						CamWriteCmosSensor(0x9f, 0x7c);
					}
					/*CamWriteCmosSensor(0x9e, 0x01);   // level_0  12.5fps
					CamWriteCmosSensor(0x9f, 0xa8); 
					CamWriteCmosSensor(0x9e, 0x02);   //  8.33fps
					CamWriteCmosSensor(0x9f, 0x7c);
					CamWriteCmosSensor(0x9e, 0x03);   //  6.25fps
					CamWriteCmosSensor(0x9f, 0x50);
					CamWriteCmosSensor(0x9e, 0x04);   //   5.00fps
					CamWriteCmosSensor(0x9f, 0x24);*/
				
				
					GC6123_SERIAL_CAM_BANDING_50HZ = KAL_TRUE;
	            }
		        else
	            {			
				// based on 24M MCLK 
					CamWriteCmosSensor(0x01, 0xbb);  //hb[7:0]
					CamWriteCmosSensor(0x02, 0x70);  //vb[7:0]
					CamWriteCmosSensor(0x0f, 0x07);  //vb[11:8] , hb[11:8] 

					CamWriteCmosSensor(0x9c, 0x00);   //step[11:8]
					CamWriteCmosSensor(0x9d, 0x2c);   //step[7:0]

					if(GC6123_SERIALSensor.VideoMode)
					{
						CamWriteCmosSensor(0x9e, 0x01);   // level_0  11.99fps
						CamWriteCmosSensor(0x9f, 0xb8);  
					}
					else{
						CamWriteCmosSensor(0x9e, 0x02);	 // level_1  7.99fps
						CamWriteCmosSensor(0x9f, 0x94);
					}
					/*CamWriteCmosSensor(0x9e, 0x01);   // level_0  11.99fps
					CamWriteCmosSensor(0x9f, 0xb8);  
					CamWriteCmosSensor(0x9e, 0x02);	 // level_1  7.99fps
					CamWriteCmosSensor(0x9f, 0x94);
					CamWriteCmosSensor(0x9e, 0x03);   // level_2  6.31fps
					CamWriteCmosSensor(0x9f, 0x44);
					CamWriteCmosSensor(0x9e, 0x04);   // level_3  4.99fps
					CamWriteCmosSensor(0x9f, 0x20);*/				
					GC6123_SERIAL_CAM_BANDING_50HZ = KAL_FALSE;
	            }
				
			}
        }
   
    return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*   GC6123_SERIALSceneMode
*
* DESCRIPTION
*   This function get/set scene mode of sensor.
*
* PARAMETERS
*   IsCam: camera scene mode or not
*   In, Out
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM GC6123_SERIALSceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*	GC6123_SERIALGammaSelect
*
* DESCRIPTION
*	This function is served for FAE to select the appropriate GAMMA curve.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void GC6123_SERIALGammaSelect(kal_uint32 GammaLvl)
{

}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALInitialSetting
*
* DESCRIPTION
*   This function initialize the registers of CMOS sensor
*   IMPORTANT NOTICE:
*     the output format should be YUV422, order: YUYV
*     data output should be at pclk falling edge
*     VSYNC should be low active
*     HSYNC should be hight active
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC6123_SERIALInitialSetting(void)
{
	/////////////////////////////////////////////////////
	//////////////////////	 SYS   //////////////////////
	/////////////////////////////////////////////////////
	CamWriteCmosSensor(0xfe, 0xa0);
	CamWriteCmosSensor(0xfe, 0xa0);
	CamWriteCmosSensor(0xfe, 0xa0);
	CamWriteCmosSensor(0xf1, 0x07); //output enable
	CamWriteCmosSensor(0xf4, 0x00);
	CamWriteCmosSensor(0xfc, 0x16); //clock enable
	GC6123_SERIAL_SET_PAGE0; //Page select

	/////////////////////////////////////////////////////
	////////////////   ANALOG & CISCTL	 ////////////////
	/////////////////////////////////////////////////////
	CamWriteCmosSensor(0x08, 0x02); //col start
	CamWriteCmosSensor(0x09, 0x01); //window height
	CamWriteCmosSensor(0x0a, 0x48);
	CamWriteCmosSensor(0x0b, 0x00); //window width
	CamWriteCmosSensor(0x0c, 0xf4);
	CamWriteCmosSensor(0x10, 0x48); //sh_width
	CamWriteCmosSensor(0x11, 0x1d); //tx_width
	CamWriteCmosSensor(0x14, 0x14); //dark CFA
	CamWriteCmosSensor(0x15, 0x0a); //sdark
	CamWriteCmosSensor(0x16, 0x04); //AD pipe number
	CamWriteCmosSensor(0x18, 0xc2); //rowsg_gap
	CamWriteCmosSensor(0x1a, 0x17); //clk_delay_en
	CamWriteCmosSensor(0x1b, 0x1a); //20121107 comv_r solve FPN-W/18 //70/adclk mode
	CamWriteCmosSensor(0x1c, 0x49); //txhigh_en
	CamWriteCmosSensor(0x1d, 0xb0); //vref
	CamWriteCmosSensor(0x1e, 0x52); //20121107 solve OBI/51 //ADC_r

	/////////////////////////////////////////////////////
	//////////////////////	 ISP   //////////////////////
	/////////////////////////////////////////////////////
	CamWriteCmosSensor(0x20,0x5e); 
	CamWriteCmosSensor(0x21,0x38); //autogray
	CamWriteCmosSensor(0x22,0x92); //20121107 auto_DD_en/82 //02
	CamWriteCmosSensor(0x24,0xa3); //output_format
	CamWriteCmosSensor(0x26,0x03);
	CamWriteCmosSensor(0x27,0x90); //clock gating
	CamWriteCmosSensor(0x28,0x8c);
	CamWriteCmosSensor(0x38,0x80); //crop
	CamWriteCmosSensor(0x3b,0x01);
	CamWriteCmosSensor(0x3c,0x40);
	CamWriteCmosSensor(0x3d,0x00);
	CamWriteCmosSensor(0x3e,0xf0);

	/////////////////////////////////////////////////////
	//////////////////////	 BLK   //////////////////////
	/////////////////////////////////////////////////////
	CamWriteCmosSensor(0x2a, 0x65); //2f/BLK row select
	CamWriteCmosSensor(0x2c, 0x40); //global offset

	/////////////////////////////////////////////////////
	//////////////////////	 GAIN	/////////////////////
	/////////////////////////////////////////////////////
	CamWriteCmosSensor(0x3f, 0x12); //20/global gain

	/////////////////////////////////////////////////////
	//////////////////////	 DNDD	/////////////////////
	/////////////////////////////////////////////////////
	CamWriteCmosSensor(0x50, 0x45);
	CamWriteCmosSensor(0x52, 0x4f); //6c/DN b
	CamWriteCmosSensor(0x53, 0x81); //a5/DN C
	CamWriteCmosSensor(0x58, 0x6f); //20121107 dark_th 64 
	CamWriteCmosSensor(0xc3, 0x96); //00

	/////////////////////////////////////////////////////
	//////////////////////	 ASDE	/////////////////////
	/////////////////////////////////////////////////////
	CamWriteCmosSensor(0xac, 0xb5);
	CamWriteCmosSensor(0x5c, 0x80); //60/OT_th

	/////////////////////////////////////////////////////
	/////////////////////	INTPEE	 ////////////////////
	/////////////////////////////////////////////////////
	CamWriteCmosSensor(0x63, 0x03); //04/edge effect
	CamWriteCmosSensor(0x65, 0x23); //43/42/edge max/min

	/////////////////////////////////////////////////////
	/////////////////////	GAMMA	/////////////////////
	/////////////////////////////////////////////////////

	/////////////////////////////////////////////////////
	//////////////////////	 CC   ///////////////////////
	/////////////////////////////////////////////////////
	CamWriteCmosSensor(0x66, 0x13);
	CamWriteCmosSensor(0x67, 0x26);
	CamWriteCmosSensor(0x68, 0x07);
	CamWriteCmosSensor(0x69, 0xf5);
	CamWriteCmosSensor(0x6a, 0xea);
	CamWriteCmosSensor(0x6b, 0x21);
	CamWriteCmosSensor(0x6c, 0x21);
	CamWriteCmosSensor(0x6d, 0xe4);
	CamWriteCmosSensor(0x6e, 0xfb);

	/////////////////////////////////////////////////////
	//////////////////////	 YCP   //////////////////////
	/////////////////////////////////////////////////////
	CamWriteCmosSensor(0x81, 0x48); //38//cb
	CamWriteCmosSensor(0x82, 0x48); //38//cr
	CamWriteCmosSensor(0x83, 0x4b); //40/luma contrast
	CamWriteCmosSensor(0x84, 0x80); //90/contrast center
	CamWriteCmosSensor(0x85, 0x00); //06/luma offset
	CamWriteCmosSensor(0x86, 0xfb); //skin cb
	CamWriteCmosSensor(0x87, 0x1d); //skin cr
	CamWriteCmosSensor(0x88, 0x18); //skin radius
	CamWriteCmosSensor(0x8d, 0x78); //38/edge dec sa
	CamWriteCmosSensor(0x8e, 0x25); //autogray

	/////////////////////////////////////////////////////
	//////////////////////	 AEC   //////////////////////
	/////////////////////////////////////////////////////
	CamWriteCmosSensor(0xa4, 0x01); 
	CamWriteCmosSensor(0x9e, 0x02);
	CamWriteCmosSensor(0x9f, 0x1c);
	CamWriteCmosSensor(0xa0, 0x10);
	CamWriteCmosSensor(0x90, 0x48); //0a
	CamWriteCmosSensor(0x92, 0x80); //40/target Y
	CamWriteCmosSensor(0xa2, 0x40); //max_post_gain
	CamWriteCmosSensor(0xa3, 0x80); //max_pre_gain

	/////////////////////////////////////////////////////
	//////////////////////	 AWB   //////////////////////
	/////////////////////////////////////////////////////
	CamWriteCmosSensor(0xb0, 0xf8); //f5/RGB high low
	CamWriteCmosSensor(0xb1, 0x24); //18/Y to C
	CamWriteCmosSensor(0xb3, 0x20); //0d/C max
	CamWriteCmosSensor(0xb4, 0x2d); //22/C inter
	CamWriteCmosSensor(0xb5, 0x1b); //22/C inter
	CamWriteCmosSensor(0xb6, 0x2e); //C inter2
	CamWriteCmosSensor(0xb7, 0x18); //40/C inter3
	CamWriteCmosSensor(0xb8, 0x13); //20/number limit
	CamWriteCmosSensor(0xb9, 0x33);
	CamWriteCmosSensor(0xba, 0x21);
	CamWriteCmosSensor(0xbb, 0x61); //42/speed & margin
	CamWriteCmosSensor(0xbf, 0x68); //78/b limit
	CamWriteCmosSensor(0x4c, 0x08);
	CamWriteCmosSensor(0x4d, 0x06);
	CamWriteCmosSensor(0x4e, 0x7b);
	CamWriteCmosSensor(0x4f, 0xa0);

	/////////////////////////////////////////////////////
	//////////////////////	 SPI   //////////////////////
	/////////////////////////////////////////////////////
/*	GC6123_SERIAL_SET_PAGE2;
	CamWriteCmosSensor(0x01, 0x03); //SPI MASTER enable
	CamWriteCmosSensor(0x0a, 0x00); //yuv
	CamWriteCmosSensor(0x0b, 0xf0);//image width  240
	CamWriteCmosSensor(0x0c, 0x00);
	CamWriteCmosSensor(0x0d, 0x40);//image height	320
	CamWriteCmosSensor(0x0e, 0x01);
	CamWriteCmosSensor(0x13, 0xd0); //50/fifo_prog_full_level
	CamWriteCmosSensor(0x20, 0x01); //00 //SYNC code
	CamWriteCmosSensor(0x21, 0x02); //01
	CamWriteCmosSensor(0x22, 0x40); //a5
	CamWriteCmosSensor(0x23, 0x00); //5a*/

	//1-wire
	GC6123_SERIAL_SET_PAGE2;
	CamWriteCmosSensor(0x01, 0x03);
	CamWriteCmosSensor(0x02, 0x02);   //LSB & Falling edge sample
	//CamWriteCmosSensor(0x03, 0x20);	//1-wire
	CamWriteCmosSensor(0x04, 0x20);   //[4] master_outformat
	CamWriteCmosSensor(0x05, 0x00);
	CamWriteCmosSensor(0x09, 0x00);   //Reverse the high<->low byte.
	CamWriteCmosSensor(0x0a, 0x00);   //Data ID, 0x00-YUV422, 0x01-RGB565
	CamWriteCmosSensor(0x13, 0xf0);


	/////////////////////////////////////////////////////
	/////////////////////	2-wire	 ////////////////////
	/////////////////////////////////////////////////////
	/*CamWriteCmosSensor(0x03, 0x25); //20
	CamWriteCmosSensor(0xfd, 0x04); 
	CamWriteCmosSensor(0xf1, 0x07); //00*/


	/////////////////////////////////////////////////////
	/////////////////////	1-wire	 ////////////////////
	/////////////////////////////////////////////////////
	CamWriteCmosSensor(0x03, 0x20); //20
	CamWriteCmosSensor(0xfd, 0x00); //00
	CamWriteCmosSensor(0xf1, 0x05); 
	
	GC6123_SERIAL_SET_PAGE0;


}


/*************************************************************************
* FUNCTION
*	GC6123_SERIAL_Write_More_Registers
*
* DESCRIPTION
*	This function is served for FAE to modify the necessary Init Regs. Do not modify the regs
*     in init_GC6123_SERIAL() directly.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void GC6123_SERIALMoreSetting(void)
{

}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALPvSetting
*
* DESCRIPTION
*   This function apply the preview mode setting, normal the preview size is 1/4 of full size.
*   Ex. 2M (1600 x 1200)
*   Preview: 800 x 600 (use sub-sample or binning to acheive it)
*   Full Size: 1600 x 1200 (output every effective pixels.)
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC6123_SERIALPvSetting(void)
{
    // TODO: add preview setting here
    
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALCapSetting
*
* DESCRIPTION
*   This function config capture settting to sensor
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC6123_SERIALCapSetting(void)
{
    // TODO: add capture setting here
    
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALGetSensorInfo
*
* DESCRIPTION
*   This function set sensor infomation
*
* PARAMETERS
*   Info
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC6123_SERIALGetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT Info)
{
    Info->SensorId = GC6123_SERIAL_SENSOR_ID;
    Info->SensorIf = IMAGE_SENSOR_IF_SERIAL;

    /* data format */
    Info->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
    Info->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
    Info->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
    Info->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
    Info->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;

    Info->PreviewMclkFreq = 24000000;
    Info->CaptureMclkFreq = 24000000;
    Info->VideoMclkFreq = 24000000;
	
    Info->PreviewWidth = GC6123_SERIAL_IMAGE_SENSOR_PV_WIDTH;
    Info->PreviewHeight = GC6123_SERIAL_IMAGE_SENSOR_PV_HEIGHT;
    Info->FullWidth = GC6123_SERIAL_IMAGE_SENSOR_FULL_WIDTH;
    Info->FullHeight = GC6123_SERIAL_IMAGE_SENSOR_FULL_HEIGHT;
    Info->SensorAfSupport = KAL_FALSE;
    Info->SensorFlashSupport = KAL_FALSE;
    Info->PixelClkPolarity = POLARITY_LOW;

    /* HSYNC/VSYNC polarity */
    Info->HsyncPolarity = POLARITY_LOW; /* actually high active when set POLARITY_LOW */
    Info->VsyncPolarity = POLARITY_LOW;

    // TODO: set isp pclk invert here if needed
    /* isp pclk invert switch */
    Info->PixelClkInv = KAL_FALSE;
}


/*************************************************************************
* FUNCTION
*    GC6123SerialSensorFeatureCtrl
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
MM_ERROR_CODE_ENUM GC6123_SERIALGetSerialSensorInfo(P_SERIAL_SENSOR_INFO_IN_STRUCT In,P_SERIAL_SENSOR_INFO_OUT_STRUCT Out)
{
	if (In->ScenarioId == CAL_SCENARIO_CAMERA_STILL_CAPTURE)
	{
		Out->para_1 = KAL_TRUE; 								/* SCK clock inverse */
		Out->para_2 = 4;										/* Cycle */
		Out->para_3 = GC6123_SERIAL_IMAGE_SENSOR_PV_WIDTH; 	/* Sensor capture data valid width */
		Out->para_4 = GC6123_SERIAL_IMAGE_SENSOR_PV_HEIGHT;	/* Sensor capture data valid height */
	}
	else
	{
		Out->para_1 = KAL_TRUE; 								/* SCK clock inverse */
		Out->para_2 = 4;										/* Cycle */
		Out->para_3 = GC6123_SERIAL_IMAGE_SENSOR_FULL_WIDTH; 	/* Sensor preview data valid width */
		Out->para_4 = GC6123_SERIAL_IMAGE_SENSOR_FULL_HEIGHT; 	/* Sensor preview data valid height */
	}

	return MM_ERROR_NONE; 
}


/*************************************************************************
* FUNCTION
*   GC6123_SERIALPowerOn
*
* DESCRIPTION
*   This function apply the power on sequence and read the sensor ID to check if the I2C
*  communication can work or not.
*
* PARAMETERS
*   None
*
* RETURNS
*   Sensor id
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint32 GC6123_SERIALPowerOn(void)
{
    static kal_uint8 GC6123_SERIALI2cAddr[] = {GC6123_SERIAL_WRITE_ID_0,
#if (GC6123_SERIAL_WRITE_ID_1 != 0xFF)
    GC6123_SERIAL_WRITE_ID_1,
#endif
#if (GC6123_SERIAL_WRITE_ID_2 != 0xFF)
    GC6123_SERIAL_WRITE_ID_2,
#endif
#if (GC6123_SERIAL_WRITE_ID_3 != 0xFF)
    GC6123_SERIAL_WRITE_ID_3,
#endif
    };
    kal_uint32 SensorId;
    kal_uint8 i;
	
 
    CisModulePowerOn(GC6123_SERIALSensor.SensorIdx, KAL_TRUE);
    GC6123_SERIALSensor.sccb_opened = KAL_TRUE;              // lanking 20120423
    CameraSccbOpen(CAMERA_SCCB_SENSOR, GC6123_SERIAL_WRITE_ID_0,
    GC6123_SERIAL_I2C_ADDR_BITS, GC6123_SERIAL_I2C_DATA_BITS, GC6123_SERIAL_HW_I2C_SPEED);
    /* add under line if sensor I2C do not support repeat start */
    //CameraSccbDisWR(CAMERA_SCCB_SENSOR);
    kal_sleep_task(2);
    // TODO: add hardware reset  by spec here
    {
	    GC6123_SERIAL_SET_PDN_LOW;
	  	kal_sleep_task(1);

		GC6123_SERIAL_SET_RST_HIGH;
		kal_sleep_task(1);
		GC6123_SERIAL_SET_RST_LOW;
		kal_sleep_task(1);
		GC6123_SERIAL_SET_RST_HIGH;
		kal_sleep_task(1);
    }

     //for SPI
    #if defined(MT6250)
    GPIO_ModeSetup(52, 2);
    GPIO_ModeSetup(64, 2);
    #else   //    mt6252
    GPIO_ModeSetup(47, 2);
    GPIO_ModeSetup(59, 2);
    #endif
	
    for (i = 0; i < sizeof(GC6123_SERIALI2cAddr) / sizeof(GC6123_SERIALI2cAddr[0]); i++)
    {
        CameraSccbSetAddr(CAMERA_SCCB_SENSOR, GC6123_SERIALI2cAddr[i]);

        // TODO: read sensor id here
        {
          
	     kal_sleep_task(1);
            SensorId = CamReadCmosSensor(0xf0);
        }
        if (GC6123_SERIAL_SENSOR_ID == SensorId)
        {
            kal_uint8 Temp;

            /* swap the correct i2c address to first one, it will speed up next time read sensor ID */
            Temp = GC6123_SERIALI2cAddr[0];
            GC6123_SERIALI2cAddr[0] = GC6123_SERIALI2cAddr[i];
            GC6123_SERIALI2cAddr[i] = Temp;
            break;
        }
    }
    GC6123_SERIAL_TRACE("SENSOR ID: %x", SensorId);

	/*
	If dual camera , get current ID here, 
		if back camera, continue;
		if front camera, reture 0;
	*/
	
    return SensorId;
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALPowerDown
*
* DESCRIPTION
*   This function power down the cmos sensor
*   IMPORTANT NOTICE:
*     data[7:0]/HSYNC/VSYNC/PCLK pin should be in High-Z state after executed this function
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC6123_SERIALPowerDown(void)
{
    // TODO: power down sensor by spec here
    if(GC6123_SERIALSensor.sccb_opened == KAL_TRUE)
    {

	CamWriteCmosSensor(0xfc, 0x01);
	CamWriteCmosSensor(0xf1, 0x00);
    }
	GC6123_SERIAL_SET_RST_LOW;
	kal_sleep_task(1);
	GC6123_SERIAL_SET_PDN_HIGH;
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALPreview
*
* DESCRIPTION
*   This function is the most important functions of (Init, Preview & Capture). 
*   1. Apply preview setting, make sensor output preview resolution, e.g. 800x600 for 2M sensor.
*   2. Record video resolution, and set mode based on the isp operation mode.
*   3. Configure the grab window.
*
* PARAMETERS
*   Id, In, Out
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC6123_SERIALPreview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
    GC6123_SERIALSensor.BandingFreq = (CAM_BANDING_50HZ == In->BandingFreq ? GC6123_SERIAL_50HZ : GC6123_SERIAL_60HZ);

	GC6123_SERIALSensor.NightMode = In->NightMode;
    /* change to preview size output */
    GC6123_SERIALSensor.PvMode = KAL_TRUE;
    GC6123_SERIALPvSetting();
    //GC6123_SERIALSetClock(GC6123_SERIAL_PV_INTERNAL_CLK);

    /* set preview frame rate range */
    switch (Id)
    {
    case CAL_SCENARIO_VIDEO:
		GC6123_SERIALSensor.VideoMode = KAL_TRUE;
        //GC6123_SERIALSetVideoFps(In->MaxVideoFrameRate);
          
        break;
    default:
		GC6123_SERIALSensor.VideoMode = KAL_FALSE;
        //GC6123_SERIALSetMaxFps(GC6123_SERIAL_FPS(30));
        //GC6123_SERIALSetMinFps(In->NightMode ? GC6123_SERIAL_FPS(5) : GC6123_SERIAL_FPS(10));
/*	if(In->NightMode)
	{
		
	}
	else
	{
	
	}*/
        /* roll back shutter&gain from capture state */
        if (GC6123_SERIALSensor.CapState)
        {
            GC6123_SERIALWriteShutter(GC6123_SERIALSensor.Shutter);
            GC6123_SERIALWriteGain(GC6123_SERIALSensor.Gain);
        }
    }

    /* misc setting */
    GC6123_SERIALSetMirror(In->ImageMirror);
  
    /* change to preview state */
    GC6123_SERIALSensor.CapState = KAL_FALSE;

    /* enable ae/awb */
    GC6123_SERIALAeEnable(KAL_TRUE);
    GC6123_SERIALAwbEnable(KAL_TRUE);

    /* set grab window */
    Out->WaitStableFrameNum = 0;
    Out->GrabStartX = GC6123_SERIAL_PV_GRAB_START_X;
    Out->GrabStartY = GC6123_SERIAL_PV_GRAB_START_Y;
    Out->ExposureWindowWidth = GC6123_SERIAL_PV_GRAB_WIDTH;
    Out->ExposureWindowHeight = GC6123_SERIAL_PV_GRAB_HEIGHT;
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALCapture
*
* DESCRIPTION
*   This function is the most important functions of (Init, Preview & Capture). 
*   1. Apply capture setting when capture size greatter then preview size, make sensor output 
*     full size, e.g. 1600x1200 for 2M sensor.
*   2. Increase the dummy pixels or derease pixel clock based on the digital zoom factor and
*    interpolation times.
*   3. Re-Calculate the shutter and sensor gain, to make the exposure value is same with preview
*   4. Configure the grab window based on sensor output.
*
* PARAMETERS
*   Id, In, Out
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC6123_SERIALCapture(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
    kal_uint32 PvClk, PvLineLength, CapShutter, CapLineLength, DummyPixel = 0;

    /* back up preview clock/linelength/shutter */
    PvClk = GC6123_SERIALSensor.InternalClock;
    PvLineLength = GC6123_SERIALSensor.LineLength;
    GC6123_SERIALSensor.Shutter = GC6123_SERIALReadShutter();
    //GC6123_SERIALSensor.Gain = GC6123_SERIALReadGain();

    /* change to capture state */
    GC6123_SERIALSensor.CapState = KAL_TRUE;
    if (In->ImageTargetWidth <= GC6123_SERIAL_IMAGE_SENSOR_PV_WIDTH && In->ImageTargetHeight <= GC6123_SERIAL_IMAGE_SENSOR_PV_HEIGHT)
    {
        // TODO: add dummy pixel or reduce pclk until capture success
        {
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT) || defined(DRV_ISP_6276_SERIES)) /* MT6253/76 */
            /* no need reduce frame rate */
#elif (defined(DRV_ISP_MT6236_HW_SUPPORT)) /* MT6236 */
            if (In->ZoomFactor > 400) /* (4, 8]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC6123_SERIALSetClock(~); */
            }
            else if (In->ZoomFactor > 200) /* (2, 4]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC6123_SERIALSetClock(~); */
            }
            else if (In->ZoomFactor > 100) /* (1, 2]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC6123_SERIALSetClock(~); */
            }
#elif (defined(DRV_ISP_6238_SERIES))
            if (In->ZoomFactor > 400) /* (4, 8]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC6123_SERIALSetClock(~); */
            }
            else if (In->ZoomFactor > 200) /* (2, 4]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC6123_SERIALSetClock(~); */
            }
            else if (In->ZoomFactor > 100) /* (1, 2]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC6123_SERIALSetClock(~); */
            }
#elif (defined(DRV_ISP_6235_SERIES)) /* MT6235 */
            if (In->ZoomFactor > 400) /* (4, 8]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC6123_SERIALSetClock(~); */
            }
            else if (In->ZoomFactor > 200) /* (2, 4]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC6123_SERIALSetClock(~); */
            }
            else if (In->ZoomFactor > 100) /* (1, 2]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC6123_SERIALSetClock(~); */
            }
#else
#error not verify yet
#endif
        }

        if (DummyPixel)
        {
            /* disable ae/awb */
            GC6123_SERIALAeEnable(KAL_FALSE);
            GC6123_SERIALAwbEnable(KAL_FALSE);

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
            #endif

            Out->WaitStableFrameNum = GC6123_SERIAL_CAPTURE_DELAY_FRAME;
        }
        else
        {
            Out->WaitStableFrameNum = 0;
        }

        /* set grab window */
        Out->GrabStartX = GC6123_SERIAL_PV_GRAB_START_X;
        Out->GrabStartY = GC6123_SERIAL_PV_GRAB_START_Y;
        Out->ExposureWindowWidth = GC6123_SERIAL_PV_GRAB_WIDTH;
        Out->ExposureWindowHeight = GC6123_SERIAL_PV_GRAB_HEIGHT;
    }
    else
    {
        /* disable ae/awb */
        GC6123_SERIALAeEnable(KAL_FALSE);
        GC6123_SERIALAwbEnable(KAL_FALSE);

        /* change to full size output */
        GC6123_SERIALSensor.PvMode = KAL_FALSE;
        //GC6123_SERIALCapSetting();
        //GC6123_SERIALSetClock(GC6123_SERIAL_CAP_INTERNAL_CLK);

        // TODO: add dummy pixel or reduce pclk until capture success
        {
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT) || defined(DRV_ISP_6276_SERIES)) /* MT6253/76 */
            /* no need reduce frame rate */
#elif (defined(DRV_ISP_MT6236_HW_SUPPORT)) /* MT6236 */
            if (In->ZoomFactor > 400) /* (4, 8]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC6123_SERIALSetClock(~); */
            }
            else if (In->ZoomFactor > 200) /* (2, 4]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC6123_SERIALSetClock(~); */
            }
            else if (In->ZoomFactor > 100) /* (1, 2]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC6123_SERIALSetClock(~); */
            }
#elif (defined(DRV_ISP_6238_SERIES))
            if (In->ZoomFactor > 400) /* (4, 8]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC6123_SERIALSetClock(~); */
            }
            else if (In->ZoomFactor > 200) /* (2, 4]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC6123_SERIALSetClock(~); */
            }
            else if (In->ZoomFactor > 100) /* (1, 2]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC6123_SERIALSetClock(~); */
            }
#elif (defined(DRV_ISP_6235_SERIES)) /* MT6235 */
            if (In->ZoomFactor > 400) /* (4, 8]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC6123_SERIALSetClock(~); */
            }
            else if (In->ZoomFactor > 200) /* (2, 4]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC6123_SERIALSetClock(~); */
            }
            else if (In->ZoomFactor > 100) /* (1, 2]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC6123_SERIALSetClock(~); */
            }
#else
#error not verify yet
#endif
        }

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
	 #endif
	 
	 /* set grab window */
        Out->WaitStableFrameNum = GC6123_SERIAL_CAPTURE_DELAY_FRAME;
        Out->GrabStartX = GC6123_SERIAL_FULL_GRAB_START_X;
        Out->GrabStartY = GC6123_SERIAL_FULL_GRAB_START_Y;
        Out->ExposureWindowWidth = GC6123_SERIAL_FULL_GRAB_WIDTH;
        Out->ExposureWindowHeight = GC6123_SERIAL_FULL_GRAB_HEIGHT;
    }
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALDetectSensorId
*
* DESCRIPTION
*   This function detect sensor id
*
* PARAMETERS
*   None
*
* RETURNS
*   Sensor id
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint32 GC6123_SERIALDetectSensorId(void)
{
    MM_ERROR_CODE_ENUM GC6123_SERIALSensorClose(void);
    kal_uint32 SensorId;
    IMAGE_SENSOR_INDEX_ENUM InvIdx;
    kal_int8 i, j;

    switch (GC6123_SERIALSensor.SensorIdx)
    {
    case IMAGE_SENSOR_MAIN:
    case IMAGE_SENSOR_BAK1:
        InvIdx = IMAGE_SENSOR_SUB;
        break;
    default:
        InvIdx = IMAGE_SENSOR_MAIN;
        break;
    }
    for (i = 1; i >= 0; i--)
    {
        for (j = 1; j >= 0; j--)
        {
            CamRstPinCtrl(InvIdx, i);
            CamPdnPinCtrl(InvIdx, j);
            SensorId = GC6123_SERIALPowerOn();
            GC6123_SERIALSensorClose();
            if (GC6123_SERIAL_SENSOR_ID == SensorId)
            {
                return GC6123_SERIAL_SENSOR_ID;
            }
        }
    }
    return MM_ERROR_SENSOR_READ_ID_FAIL;
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALInitOperationPara
*
* DESCRIPTION
*   This function set sensor operation para
*
* PARAMETERS
*   Para
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC6123_SERIALInitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
    Para->CaptureDelayFrame = 0; /* use WaitStableFrameNum instead of this */
    Para->PreviewDelayFrame = GC6123_SERIAL_PREVIEW_DELAY_FRAME;
    Para->PreviewDisplayWaitFrame = GC6123_SERIAL_FIRST_PREVIEW_DELAY_FRAME;
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALSensorOpen
*
* DESCRIPTION
*   This function read sensor id and init sensor
*
* PARAMETERS
*   None
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM GC6123_SERIALSensorOpen(void)
{
    if (GC6123_SERIALPowerOn() != GC6123_SERIAL_SENSOR_ID)
    {
        return MM_ERROR_SENSOR_READ_ID_FAIL;
    }
#ifdef GC6123_SERIAL_LOAD_FROM_T_FLASH
    if (!GC6123_SERIAL_Initialize_from_T_Flash()) /* for debug use. */
#endif
    {
        GC6123_SERIALInitialSetting(); /* apply the sensor initial setting */
	 GC6123_SERIALMoreSetting();
    }

    /* default setting */
    GC6123_SERIALSensor.BypassAe = KAL_FALSE; /* for panorama view */
    GC6123_SERIALSensor.BypassAwb = KAL_FALSE; /* for panorama view */
    GC6123_SERIALSensor.CapState = KAL_FALSE; /* preview state */
    GC6123_SERIALSensor.PvMode = KAL_TRUE; /* preview size output mode */
	GC6123_SERIALSensor.VideoMode = KAL_FALSE; /* KAL_TRUE: video mode, else preview mode */
	GC6123_SERIALSensor.NightMode = KAL_FALSE;/*KAL_TRUE:work in night mode, else normal mode*/
    GC6123_SERIALSensor.BandingFreq = GC6123_SERIAL_50HZ;
    GC6123_SERIALSensor.InternalClock = 1; /* will be update by setclock function */
    GC6123_SERIALSensor.Shutter = 1; /* default shutter 1 avoid divide by 0 */
    GC6123_SERIALSensor.Gain = 0x40; /* default gain 1x */
    //GC6123_SERIALSensor.FrameLength = GC6123_SERIAL_PV_PERIOD_LINE_NUMS; /* will be update by setdummy function */
    //GC6123_SERIALSensor.LineLength = GC6123_SERIAL_PV_PERIOD_PIXEL_NUMS; /* will be update by setdummy function */

    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALSensorFeatureCtrl
*
* DESCRIPTION
*   This function set sensor feature mode
*
* PARAMETERS
*   Id: scenario id
*   In: input parameter
*   Out: output parameter
*   OutLen: output parameter length
*   RealOutLen: real output parameter length
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM GC6123_SERIALSensorFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
    MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;

    if (Id >= CAL_FEATURE_WEBCAM_BEGIN && Id <= CAL_FEATURE_WEBCAM_END)
    {
        return GC6123_SERIALWebcamFeatureCtrl(Id, In, Out, OutLen, RealOutLen);
    }
    switch (Id)
    {
    /* query and set series */
    case CAL_FEATURE_CAMERA_BRIGHTNESS:
    case CAL_FEATURE_CAMERA_EV_VALUE:
        ErrCode = GC6123_SERIALEv(In, Out);
        break;
    case CAL_FEATURE_CAMERA_CONTRAST:
        ErrCode = GC6123_SERIALContrast(In, Out);
        break;
    case CAL_FEATURE_CAMERA_SATURATION:
        ErrCode = GC6123_SERIALSaturation(In, Out);
        break;
    case CAL_FEATURE_CAMERA_SHARPNESS:
        ErrCode = GC6123_SERIALSharpness(In, Out);
        break;
    case CAL_FEATURE_CAMERA_WB:
        ErrCode = GC6123_SERIALWb(In, Out);
        break;
    case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
        ErrCode = GC6123_SERIALEffect(In, Out);
        break;
    case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
        ErrCode = GC6123_SERIALStillCaptureSize(In, Out);
        break;
    case CAL_FEATURE_CAMERA_BANDING_FREQ:
        ErrCode = GC6123_SERIALBanding(In, Out);
        break;
    case CAL_FEATURE_CAMERA_SCENE_MODE:
        ErrCode = GC6123_SERIALSceneMode(KAL_TRUE, In, Out);
        break;
    case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
        ErrCode = GC6123_SERIALSceneMode(KAL_FALSE, In, Out);
        break;
    case CAL_FEATURE_CAMERA_FLASH_MODE:
    case CAL_FEATURE_CAMERA_HUE:
    case CAL_FEATURE_CAMERA_GAMMA:
        ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        break;

    /* get info series */
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
        GC6123_SERIALGetSensorInfo(Out);
        break;
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
        ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = GC6123_SERIALDetectSensorId();
        break;
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
        ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = \
        GC6123_SERIALSensor.InternalClock * GC6123_SERIAL_FPS(1) / (GC6123_SERIALSensor.LineLength * GC6123_SERIALSensor.FrameLength);
        break;
    case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
        GC6123_SERIALInitOperationPara(Out);
        break;
    case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
        CamGetHWInfo(GC6123_SERIALSensor.SensorIdx, Out);
        break;

    /* set para series */
    case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
        GC6123_SERIALPowerDown();
        break;
    case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
        GC6123_SERIALSensor.NvramData = &(((nvram_camera_para_struct *)In)->SENSOR);
        break;
    case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
        GC6123_SERIALSensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
        break;
    case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
		
        break;
    case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
        GC6123_SERIALSensor.BypassAe = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
        GC6123_SERIALAeEnable(GC6123_SERIALSensor.BypassAe ? KAL_FALSE : KAL_TRUE);
        break;
    case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
        GC6123_SERIALSensor.BypassAwb = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
        GC6123_SERIALAwbEnable(GC6123_SERIALSensor.BypassAwb ? KAL_FALSE : KAL_TRUE);
        break;
    case IMAGE_SENSOR_FEATURE_GET_SERIAL_SENSOR_INFO:
	 GC6123_SERIALGetSerialSensorInfo(In, Out);
    break;
    default:
        ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        break;
    }
    return ErrCode;
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALSensorCtrl
*
* DESCRIPTION
*   This function set sensor scenario mode
*
* PARAMETERS
*   Id: scenario id
*   In/Out: parameter
*   OutLen: out parameter length
*   RealOutLen: real out parameter length
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM GC6123_SERIALSensorCtrl(CAL_SCENARIO_ENUM Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
    switch (Id)
    {
    case CAL_SCENARIO_CAMERA_PREVIEW:
    case CAL_SCENARIO_VIDEO:
    case CAL_SCENARIO_WEBCAM_PREVIEW:
    case CAL_SCENARIO_WEBCAM_CAPTURE:
        GC6123_SERIALPreview(Id, In, Out);
        break;
    case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
        GC6123_SERIALCapture(Id, In, Out);
        break;
    default:
        break;
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALSensorClose
*
* DESCRIPTION
*   This function is to turn off sensor module power.
*
* PARAMETERS
*   None
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM GC6123_SERIALSensorClose(void)
{
    GC6123_SERIALPowerDown();
    GC6123_SERIALSensor.sccb_opened = KAL_FALSE; // lanking 20120423
    CisModulePowerOn(GC6123_SERIALSensor.SensorIdx, KAL_FALSE);
    CameraSccbClose(CAMERA_SCCB_SENSOR);

    //Resume
    #if defined(MT6250)
    GPIO_ModeSetup(52, 1);
    GPIO_ModeSetup(64, 1);
    #else    // MT6252
    GPIO_ModeSetup(47, 1);
    GPIO_ModeSetup(59, 1);
    #endif
 

    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC6123_SERIALSensorFunc
*
* DESCRIPTION
*   This function get sensor function pointer
*
* PARAMETERS
*   Sensor function pointer
*
* RETURNS
*   Error code
*
* GLOBALS AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM GC6123_SERIALSensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
    static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncGC6123_SERIAL =
    {
        GC6123_SERIALSensorOpen,
        GC6123_SERIALSensorFeatureCtrl,
        GC6123_SERIALSensorCtrl,
        GC6123_SERIALSensorClose,
    };

    *pfSensorFunc = &ImageSensorFuncGC6123_SERIAL;
  
    return MM_ERROR_NONE;
}

#ifdef __GC6123_SERIAL_DEBUG_TRACE__
static kal_bool GC6123_SERIALAtGetValue(char *Str, kal_uint32 *Data)
{
    extern int isdigit(int c);
    extern int isxdigit(int c);
    extern int tolower(int c);
    char CmdName[15];
    kal_uint8 TmpIdx = 0, Index = 3;
    kal_uint32 Value;

    while (Str[Index] != '=' && Str[Index] != 13)
    {
        CmdName[TmpIdx++] = Str[Index++];
    }
    CmdName[TmpIdx] = '\0';

    if (strcmp(CmdName, "DO"))
    {
        return KAL_FALSE;
    }
    Value = Data[0] = 0;
    while (1)
    {
        TmpIdx = Str[++Index];
        switch (TmpIdx)
        {
        case 13:
        case ',':
            Data[++Data[0]] = Value;
            if (Data[0] == 9 || TmpIdx == 13)
            {
                return KAL_TRUE;
            }
            Value = 0;
            break;
        default:
            if (isdigit(TmpIdx))
            {
                Value = Value * 16 + TmpIdx - '0';
            }
            else if (isxdigit(TmpIdx))
            {
                Value = Value * 16 + tolower(TmpIdx) - 'a' + 10;
            }
            else
            {
                return KAL_TRUE;
            }
            break;
        }
    }
}

kal_bool AtFuncTest(kal_char *Str)
{
    kal_uint32 Data[10];

    if (!GC6123_SERIALAtGetValue(Str, Data))
    {
        return KAL_FALSE;
    }
    if (!Data[0])
    {
        return KAL_TRUE;
    }
    switch (Data[1])
    {
    case 0x00:
        {
            extern kal_uint32 IspCurrentFrameRate;

            GC6123_SERIAL_TRACE("Current Frame Rate: %d.%d fps", IspCurrentFrameRate / 10, IspCurrentFrameRate % 10);
        }
        break;
    case 0x02:
        GC6123_SERIAL_TRACE("Read BB Reg[%x] = %x", Data[2], DRV_Reg32(Data[2]));
        break;
    case 0x03:
        DRV_Reg32(Data[2]) = Data[3];
        GC6123_SERIAL_TRACE("Write BB Reg[%x] = %x", Data[2], DRV_Reg32(Data[2]));
        break;
    case 0x04:
        GC6123_SERIAL_TRACE("Read Sensor Reg[%x] = %x", Data[2], CamReadCmosSensor(Data[2]));
        break;
    case 0x05:
        CamWriteCmosSensor(Data[2], Data[3]);
        GC6123_SERIAL_TRACE("Write Sensor Reg[%x] = %x", Data[2], CamReadCmosSensor(Data[2]));
        break;
    case 0x06:
        CamWriteCmosSensor(Data[2], Data[3]);
        GC6123_SERIAL_TRACE("Read Sensor Reg[%x:%x] = %x", Data[3], Data[4], CamReadCmosSensor(Data[4]));
        break;
    case 0x07:
        CamWriteCmosSensor(Data[2], Data[3]);
        CamWriteCmosSensor(Data[4], Data[5]);
        CamWriteCmosSensor(Data[2], Data[3]);
        GC6123_SERIAL_TRACE("Write Sensor Reg[%x:%x] = %x", Data[3], Data[4], CamReadCmosSensor(Data[4]));
        break;
    case 0x09:
        //Data[4] = t[Data[2]];
        //t[Data[2]] = Data[3];
        //kal_print_string_trace(MOD_ENG, TRACE_INFO, "t[%d]: %d -> %d", Data[2], Data[4], t[Data[2]]);
        break;
    case 0x0A:
        {
            kal_uint32 i;

            for (i = 0; i < Data[3]; i++)
            {
                GC6123_SERIAL_TRACE("Read Sensor Reg[%x] = %x", Data[2] + i, CamReadCmosSensor(Data[2] + i));
                if (!(i % 200))
                {
                    kal_sleep_task(30);
                }
            }
        }
        break;
    case 0x0B:
        {
            kal_uint32 i;

            for (i = 0; i < Data[3]; i++)
            {
                GC6123_SERIAL_TRACE("Read BB Reg[%x] = %x", Data[2] + i * 4, DRV_Reg32(Data[2] + i * 4));
                if (!(i % 200))
                {
                    kal_sleep_task(30);
                }
            }
        }
        break;
    default:
        break;
    }
    return KAL_TRUE;
}
#endif

