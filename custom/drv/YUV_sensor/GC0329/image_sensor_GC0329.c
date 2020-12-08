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
 *   image_sensor_GC0329.c
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

static struct
{
    kal_bool BypassAe;
    kal_bool BypassAwb;
    kal_bool CapState; /* KAL_TRUE: in capture state, else in preview state */
    kal_bool PvMode; /* KAL_TRUE: preview size output, else full size output */
	kal_bool VideoMode; /* KAL_TRUE: video mode, else preview mode */
	kal_bool NightMode;/*KAL_TRUE:work in night mode, else normal mode*/
    kal_uint8 BandingFreq; /* GC0329_50HZ or GC0329_60HZ for 50Hz/60Hz */
    kal_uint32 InternalClock; /* internal clock which using process pixel(for exposure) */
    kal_uint32 Pclk; /* output clock which output to baseband */
    kal_uint32 Gain; /* base on 0x40 */
    kal_uint32 Shutter; /* unit is (linelength / internal clock) s */
	kal_uint32 FrameLength; /* total line numbers in one frame(include dummy line) */
    kal_uint32 LineLength; /* total pixel numbers in one line(include dummy pixel) */
    IMAGE_SENSOR_INDEX_ENUM SensorIdx;
    sensor_data_struct *NvramData;
} GC0329Sensor;

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

#ifdef GC0329_LOAD_FROM_T_FLASH
/*************************************************************************
* FUNCTION
*  GC0329_Initialize_from_T_Flash
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
static kal_uint8 GC0329_Initialize_from_T_Flash()
{
#include <stdlib.h>
#include "med_utility.h"
#include "fs_type.h"

#define GC0329_REG_SKIP    0x06
#define GC0329_VAL_SKIP    0x06
  
    /* 0 - Initial value, 1 - Register, 2 - Delay, 3 - End of setting. */
    #define GC0329_OP_CODE_INI    0x00    /* Initial value. */
    #define GC0329_OP_CODE_REG    0x01    /* Register */
    #define GC0329_OP_CODE_DLY    0x02    /* Delay */
    #define GC0329_OP_CODE_END    0x03    /* End of initial setting. */

    typedef struct
    {
        kal_uint16 init_reg;
        kal_uint16 init_val;  /* Save the register value and delay tick */
        kal_uint8 op_code;    /* 0 - Initial value, 1 - Register, 2 - Delay, 3 - End of setting. */
    } GC0329_initial_set_struct;
  
    static GC0329_initial_set_struct GC0329_Init_Reg[1000];
    static WCHAR GC0329_set_file_name[256] = {0};
    FS_HANDLE fp = -1;        /* Default, no file opened. */
    kal_uint8 *data_buff = NULL;
    kal_uint8 *curr_ptr = NULL;
    kal_uint32 file_size = 0;
    kal_uint32 bytes_read = 0;
    kal_uint32 i = 0, j = 0;
    kal_uint8 func_ind[3] = {0};  /* REG or DLY */

    kal_mem_cpy(GC0329_set_file_name, L"C:\\GC0329_Initialize_Setting.Bin", sizeof(L"C:\\GC0329_Initialize_Setting.Bin"));
    
    /* Search the setting file in all of the user disk. */
    curr_ptr = (kal_uint8 *)GC0329_set_file_name;
    while (fp < 0)
    {
        if ((*curr_ptr >= 'c' && *curr_ptr <= 'z') || (*curr_ptr >= 'C' && *curr_ptr <= 'Z'))
        {
            fp = FS_Open(GC0329_set_file_name, FS_READ_ONLY);
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
        GC0329_TRACE("!!! Warning, Can't find the initial setting file!!!");
        return 0;
    }
    
    FS_GetFileSize(fp, &file_size);
    if (file_size < 20)
    {
        GC0329_TRACE("!!! Warning, Invalid setting file!!!");
        return 0;      /* Invalid setting file. */
    }
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
    //FS_Read(fp, data_buff, file_size, &bytes_read);
    FS_Read(fp, curr_ptr, file_size, &bytes_read);
    /* Start parse the setting witch read from t-flash. */
    //curr_ptr = data_buff;
	data_buff = curr_ptr;//leo add
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
            GC0329_Init_Reg[i].op_code = GC0329_OP_CODE_REG;
      
            GC0329_Init_Reg[i].init_reg = strtol((const char *)curr_ptr, NULL, 16);
            curr_ptr += GC0329_REG_SKIP;  /* Skip "0x0000, " */
      
            GC0329_Init_Reg[i].init_val = strtol((const char *)curr_ptr, NULL, 16);
            curr_ptr += GC0329_VAL_SKIP;  /* Skip "0x0000);" */
        }
        else                  /* DLY */
        {
            /* Need add delay for this setting. */
            GC0329_Init_Reg[i].op_code = GC0329_OP_CODE_DLY;
      
            GC0329_Init_Reg[i].init_reg = 0xFF;
            GC0329_Init_Reg[i].init_val = strtol((const char *)curr_ptr, NULL, 10);  /* Get the delay ticks, the delay should less then 50 */
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
    GC0329_Init_Reg[i].op_code = GC0329_OP_CODE_END;
    GC0329_Init_Reg[i].init_reg = 0xFF;
    GC0329_Init_Reg[i].init_val = 0xFF;
    i++;

    GC0329_TRACE("%d register read...", i - 1);
    //med_free_ext_mem((void **)&data_buff);
    FS_Close(fp);

    GC0329_TRACE("Start apply initialize setting.");
    /* Start apply the initial setting to sensor. */
    for (j=0; j<i; j++)
    {
        if (GC0329_Init_Reg[j].op_code == GC0329_OP_CODE_END)  /* End of the setting. */
        {
            break ;
        }
        else if (GC0329_Init_Reg[j].op_code == GC0329_OP_CODE_DLY)
        {
            kal_sleep_task(GC0329_Init_Reg[j].init_val);    /* Delay */
        }
        else if (GC0329_Init_Reg[j].op_code == GC0329_OP_CODE_REG)
        {
            CamWriteCmosSensor(GC0329_Init_Reg[j].init_reg, GC0329_Init_Reg[j].init_val);
        }
        else
        {
            ASSERT(0);
        }
    }
    GC0329_TRACE("%d register applied...", j);
    return 1;  
}
#endif

/*************************************************************************
* FUNCTION
*   GC0329SetMirror
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
static void GC0329SetMirror(kal_uint8 Mirror)
{
    // TODO: set mirror&flip here
	switch (Mirror)
    {
    case IMAGE_SENSOR_MIRROR_NORMAL:
		CamWriteCmosSensor(0x17, 0x14);
        break;
    case IMAGE_SENSOR_MIRROR_H:
		CamWriteCmosSensor(0x17, 0x15);
        break;
    case IMAGE_SENSOR_MIRROR_V:
		CamWriteCmosSensor(0x17, 0x16);
        break;
    case IMAGE_SENSOR_MIRROR_HV:
		CamWriteCmosSensor(0x17, 0x17);
        break;
    default:
        /* no need to do error handling */
        break;
    }
}

/*************************************************************************
* FUNCTION
*   GC0329SetClock
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
static void GC0329SetClock(kal_uint32 InternalClock)
{
    if (GC0329Sensor.InternalClock == InternalClock)
    {
        return;
    }
    GC0329Sensor.InternalClock = InternalClock;
    // TODO: set internal clock(use process pixel) and output clock(ouput to baseband) here
    {
    	kal_uint8 clk_div = 0x00;
        /* add PLL comment here */
        switch (InternalClock)
        {
			case GC0329_MCLK / 2:
				clk_div = 0x00;
			break;/*pclk = mclk*/
			
			case GC0329_MCLK / 4:
				clk_div = 0x11;
			break;/*pclk = mclk / 2*/
			
			case GC0329_MCLK / 8:
				clk_div = 0x32;
			break;/*pclk = mclk / 4*/
        }
		CamWriteCmosSensor(0xfa, clk_div);
    }
}

/*************************************************************************
* FUNCTION
*   GC0329WriteShutter
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
static void GC0329WriteShutter(kal_uint32 Shutter)
{
    // TODO: set integration time here
	if(Shutter < 1) Shutter = 1;
	CamWriteCmosSensor(0x03 , (Shutter>>8)&0xff);           
	CamWriteCmosSensor(0x04 , Shutter&0xff); 
}

/*************************************************************************
* FUNCTION
*   GC0329ReadShutter
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
static kal_uint32 GC0329ReadShutter(void)
{
    // TODO: read integration time here
	return (CamReadCmosSensor(0x03) << 8)|CamReadCmosSensor(0x04);
}

/*************************************************************************
* FUNCTION
*   GC0329WriteGain
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
static void GC0329WriteGain(kal_uint32 Gain)
{
    // TODO: set global gain here
    
}

/*************************************************************************
* FUNCTION
*   GC0329ReadGain
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
static kal_uint32 GC0329ReadGain(void)
{
    // TODO: read global gain here
    
    return 0x40;
}

/*************************************************************************
* FUNCTION
*   GC0329AeEnable
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
static void GC0329AeEnable(kal_bool Enable)
{
    if (GC0329Sensor.BypassAe)
    {
        Enable = KAL_FALSE;
    }
    // TODO: enable or disable AE here
    {
	    kal_uint8 temp = CamReadCmosSensor(0x4f);
        if (Enable)
        {
            CamWriteCmosSensor(0x4f, (temp | 0x01));
        }
        else
        {
            CamWriteCmosSensor(0x4f, (temp & (~0x01)));
        }		
#ifdef __GC0329_DEBUG_TRACE__
		GC0329_TRACE("GC0329AeEnable Enable = %d",Enable);
#endif
    }
}

/*************************************************************************
* FUNCTION
*   GC0329AwbEnable
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
static void GC0329AwbEnable(kal_bool Enable)
{
    if (GC0329Sensor.BypassAwb)
    {
        Enable = KAL_FALSE;
    }
    // TODO: enable or disable AWB here
    {
		kal_uint8 temp = CamReadCmosSensor(0x42);
		if (Enable)
		{
			CamWriteCmosSensor(0x42, (temp | 0x02));
		}
		else
		{
			CamWriteCmosSensor(0x42, (temp & (~0x02)));
		}
#ifdef __GC0329_DEBUG_TRACE__
		GC0329_TRACE("GC0329AwbEnable Enable = %d",Enable);
#endif
    }
}

/*************************************************************************
* FUNCTION
*    GC0329SetBandingStep
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
static void GC0329SetBandingStep(void)
{
    // TODO: set banding step here
}

/*************************************************************************
* FUNCTION
*   GC0329SetDummy
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
static void GC0329SetDummy(kal_uint32 DummyPixel, kal_uint32 DummyLine)
{
    kal_uint32 LineLength, FrameLength;

    if (GC0329Sensor.PvMode) /* preview size output mode */
    {
        LineLength = DummyPixel + GC0329_PV_PERIOD_PIXEL_NUMS;
        FrameLength = DummyLine + GC0329_PV_PERIOD_LINE_NUMS;
    }
    else
    {
        LineLength = DummyPixel + GC0329_FULL_PERIOD_PIXEL_NUMS;
        FrameLength = DummyLine + GC0329_FULL_PERIOD_LINE_NUMS;
    }

    // TODO: set linelength/framelength or dummy pixel/line and return right value here
    {
		kal_uint32 hb_ori, hb_total;
		kal_uint32 temp_reg;
			
		/*Set HB start*/
		
		/*The HB must < 0xFFF*/
		temp_reg = CamReadCmosSensor(0x05);
		hb_ori = ((temp_reg&0x0f)<<8 )|CamReadCmosSensor(0x06);
		hb_total = hb_ori + DummyPixel;
		
		if(hb_total > 0xfff)
		{
			CamWriteCmosSensor(0x05 , temp_reg|0x0f);
			CamWriteCmosSensor(0x06 , 0xff); 
			temp_reg = GC0329Sensor.Shutter * (694 + hb_ori ) / 4095;
		}
		else
		{
			CamWriteCmosSensor(0x05 , temp_reg|((hb_total>>8)&0x0f));
			CamWriteCmosSensor(0x06 , hb_total&0xff); 
			temp_reg = GC0329Sensor.Shutter * (694 + hb_ori ) / (694 + hb_ori + DummyPixel);
		}

		GC0329Sensor.Shutter = temp_reg;
    }

    /* config banding step or base shutter */
    if (GC0329Sensor.PvMode) /* preview size output mode */
    {
        GC0329SetBandingStep();
    }
}

/*************************************************************************
* FUNCTION
*   GC0329SetMinFps
*
* DESCRIPTION
*   This function calculate & set min frame rate
*
* PARAMETERS
*   Fps: min frame rate, base on GC0329_FPS(x)
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC0329SetMinFps(kal_uint16 Fps)
{
    // TODO: set max exposure time or max AE index here
	if(GC0329_FPS(5) == Fps)
	{
		CamWriteCmosSensor(0xfe, 0x01);
		CamWriteCmosSensor(0x33, 0x30);
		CamWriteCmosSensor(0xfe, 0x00);
	}
	else if(GC0329_FPS(10) == Fps)
	{
		CamWriteCmosSensor(0xfe, 0x01);
		CamWriteCmosSensor(0x33, 0x20);
		CamWriteCmosSensor(0xfe, 0x00);
	}
}

/*************************************************************************
* FUNCTION
*   GC0329SetMaxFps
*
* DESCRIPTION
*   This function calculate & set max frame rate
*
* PARAMETERS
*   Fps: max frame rate, base on GC0329_FPS(x)
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC0329SetMaxFps(kal_uint16 Fps)
{
    kal_uint32 LineLength, FrameLength;

    /* get max line length */
    LineLength = GC0329Sensor.InternalClock * GC0329_FPS(1) / (Fps * GC0329_PV_PERIOD_LINE_NUMS);
    if (LineLength > GC0329_MAX_PV_LINELENGTH) /* overflow check */
    {
        LineLength = GC0329_MAX_PV_LINELENGTH;
    }
    if (LineLength < GC0329_PV_PERIOD_PIXEL_NUMS)
    {
        LineLength = GC0329_PV_PERIOD_PIXEL_NUMS;
    }

    /* get frame height */
    FrameLength = GC0329Sensor.InternalClock * GC0329_FPS(1) / (Fps * LineLength);
    if (FrameLength > GC0329_MAX_PV_FRAMELENGTH) /* overflow check */
    {
        FrameLength = GC0329_MAX_PV_FRAMELENGTH;
    }
    if (FrameLength < GC0329_PV_PERIOD_LINE_NUMS)
    {
        FrameLength = GC0329_PV_PERIOD_LINE_NUMS;
    }

    /* limit max frame rate to Fps specified */
    GC0329SetDummy(LineLength - GC0329_PV_PERIOD_PIXEL_NUMS, FrameLength - GC0329_PV_PERIOD_LINE_NUMS);
}

/*************************************************************************
* FUNCTION
*   GC0329SetVideoFps
*
* DESCRIPTION
*   This function calculate & fix frame rate in video mode
*
* PARAMETERS
*   Fps: target frame rate to fixed, base on GC0329_FPS(x)
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void GC0329SetVideoFps(kal_uint16 Fps)
{
    /* limit max frame rate */
    GC0329SetMaxFps(Fps);

    // TODO: fix, set max exposure time or max AE index here
    {
    }
}

/*************************************************************************
* FUNCTION
*   GC0329SetFPS
*
* DESCRIPTION
*   This function calculate & fix frame rate in video mode
*
* PARAMETERS
*   Fps: target frame rate to fixed, base on GC0329_FPS(x)
*
* RETURNS
*   None
*
* LOCAL AFFECTED
*
*************************************************************************/
void GC0329SetFPS()
{
#ifdef __GC0329_DEBUG_TRACE__
	GC0329_TRACE("GC0329Banding BandingFreq = %d , NightMode = %d , VideoMode = %d",GC0329Sensor.BandingFreq,GC0329Sensor.NightMode,GC0329Sensor.VideoMode);
#endif

	if(GC0329Sensor.BandingFreq == GC0329_50HZ)
	{
		if((!GC0329Sensor.NightMode)&&(!GC0329Sensor.VideoMode))//Normal mode 10~30FPS
		{
			CamWriteCmosSensor(0x07, 0x00);
			CamWriteCmosSensor(0x08, 0x22);
				
			CamWriteCmosSensor(0xfe, 0x01);
			CamWriteCmosSensor(0x33, 0x20);
			CamWriteCmosSensor(0xfe, 0x00);
#ifdef __GC0329_DEBUG_TRACE__
			GC0329_TRACE("Normal mode 10~30FPS");
#endif
		}
		else if((GC0329Sensor.NightMode)&&(!GC0329Sensor.VideoMode))//Night mode 5~30FPS
		{
			CamWriteCmosSensor(0x07, 0x00);
			CamWriteCmosSensor(0x08, 0x22);
				
			CamWriteCmosSensor(0xfe, 0x01);
			CamWriteCmosSensor(0x33, 0x30);
			CamWriteCmosSensor(0xfe, 0x00);
#ifdef __GC0329_DEBUG_TRACE__
			GC0329_TRACE("Night mode 5~30FPS");
#endif
		}
		else if((!GC0329Sensor.NightMode)&&(GC0329Sensor.VideoMode))//Video normal mode 30FPS
		{
			CamWriteCmosSensor(0x07, 0x00);
			CamWriteCmosSensor(0x08, 0x22);
		
			CamWriteCmosSensor(0xfe, 0x01);
			CamWriteCmosSensor(0x33, 0x00);
			CamWriteCmosSensor(0xfe, 0x00);
#ifdef __GC0329_DEBUG_TRACE__
			GC0329_TRACE("Video normal mode 30FPS");
#endif
		}
		else if((GC0329Sensor.NightMode)&&(GC0329Sensor.VideoMode))//Video night mode 15FPS
		{
			CamWriteCmosSensor(0x07, 0x02);
			CamWriteCmosSensor(0x08, 0xda);
			
			CamWriteCmosSensor(0xfe, 0x01);
			CamWriteCmosSensor(0x33, 0x00);
			CamWriteCmosSensor(0xfe, 0x00);
			
#ifdef __GC0329_DEBUG_TRACE__
			GC0329_TRACE("Video night mode 15FPS");
#endif
		}
	}
	else if(GC0329Sensor.BandingFreq == GC0329_60HZ)
	{
		if((!GC0329Sensor.NightMode)&&(!GC0329Sensor.VideoMode))//Normal mode 10~30FPS
		{
			CamWriteCmosSensor(0x07, 0x00);
			CamWriteCmosSensor(0x08, 0x60);
		
			CamWriteCmosSensor(0xfe, 0x01);
			CamWriteCmosSensor(0x33, 0x20);
			CamWriteCmosSensor(0xfe, 0x00);
#ifdef __GC0329_DEBUG_TRACE__
			GC0329_TRACE("Normal mode 10~30FPS");
#endif
		}
		else if((GC0329Sensor.NightMode)&&(!GC0329Sensor.VideoMode))//Night mode 5~30FPS
		{
			CamWriteCmosSensor(0x07, 0x00);
			CamWriteCmosSensor(0x08, 0x60);
		
			CamWriteCmosSensor(0xfe, 0x01);
			CamWriteCmosSensor(0x33, 0x30);
			CamWriteCmosSensor(0xfe, 0x00);
#ifdef __GC0329_DEBUG_TRACE__
			GC0329_TRACE("Night mode 5~30FPS");
#endif
		}
		else if(!(GC0329Sensor.NightMode)&&(GC0329Sensor.VideoMode))//Video normal mode 30FPS
		{
			CamWriteCmosSensor(0x07, 0x00);
			CamWriteCmosSensor(0x08, 0x60);
		
			CamWriteCmosSensor(0xfe, 0x01);
			CamWriteCmosSensor(0x33, 0x00);
			CamWriteCmosSensor(0xfe, 0x00);
#ifdef __GC0329_DEBUG_TRACE__
			GC0329_TRACE("Video normal mode 30FPS");
#endif
		}
		else if((GC0329Sensor.NightMode)&&(GC0329Sensor.VideoMode))//Video night mode 15FPS
		{
			CamWriteCmosSensor(0x07, 0x02);
			CamWriteCmosSensor(0x08, 0xa8);
		
			CamWriteCmosSensor(0xfe, 0x01);
			CamWriteCmosSensor(0x33, 0x00);
			CamWriteCmosSensor(0xfe, 0x00);
#ifdef __GC0329_DEBUG_TRACE__
			GC0329_TRACE("Video night mode 15FPS");
#endif
		}
	}
}
/*************************************************************************
* FUNCTION
*	GC0329GammaSelect
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
void GC0329GammaSelect(GC0329_GAMMA_TAG GammaLvl)
{
	switch(GammaLvl)
	{
		case GC0329_RGB_Gamma_m1:						//smallest gamma curve
			CamWriteCmosSensor(0xfe, 0x00);
			CamWriteCmosSensor(0xbf, 0x06);
			CamWriteCmosSensor(0xc0, 0x12);
			CamWriteCmosSensor(0xc1, 0x22);
			CamWriteCmosSensor(0xc2, 0x35);
			CamWriteCmosSensor(0xc3, 0x4b);
			CamWriteCmosSensor(0xc4, 0x5f);
			CamWriteCmosSensor(0xc5, 0x72);
			CamWriteCmosSensor(0xc6, 0x8d);
			CamWriteCmosSensor(0xc7, 0xa4);
			CamWriteCmosSensor(0xc8, 0xb8);
			CamWriteCmosSensor(0xc9, 0xc8);
			CamWriteCmosSensor(0xca, 0xd4);
			CamWriteCmosSensor(0xcb, 0xde);
			CamWriteCmosSensor(0xcc, 0xe6);
			CamWriteCmosSensor(0xcd, 0xf1);
			CamWriteCmosSensor(0xce, 0xf8);
			CamWriteCmosSensor(0xcf, 0xfd);
			break;
		case GC0329_RGB_Gamma_m2:
			CamWriteCmosSensor(0xBF, 0x08);
			CamWriteCmosSensor(0xc0, 0x0F);
			CamWriteCmosSensor(0xc1, 0x21);
			CamWriteCmosSensor(0xc2, 0x32);
			CamWriteCmosSensor(0xc3, 0x43);
			CamWriteCmosSensor(0xc4, 0x50);
			CamWriteCmosSensor(0xc5, 0x5E);
			CamWriteCmosSensor(0xc6, 0x78);
			CamWriteCmosSensor(0xc7, 0x90);
			CamWriteCmosSensor(0xc8, 0xA6);
			CamWriteCmosSensor(0xc9, 0xB9);
			CamWriteCmosSensor(0xcA, 0xC9);
			CamWriteCmosSensor(0xcB, 0xD6);
			CamWriteCmosSensor(0xcC, 0xE0);
			CamWriteCmosSensor(0xcD, 0xEE);
			CamWriteCmosSensor(0xcE, 0xF8);
			CamWriteCmosSensor(0xcF, 0xFF);
			break;
			
		case GC0329_RGB_Gamma_m3:			
			CamWriteCmosSensor(0xBF, 0x0B);
			CamWriteCmosSensor(0xc0, 0x16);
			CamWriteCmosSensor(0xc1, 0x29);
			CamWriteCmosSensor(0xc2, 0x3C);
			CamWriteCmosSensor(0xc3, 0x4F);
			CamWriteCmosSensor(0xc4, 0x5F);
			CamWriteCmosSensor(0xc5, 0x6F);
			CamWriteCmosSensor(0xc6, 0x8A);
			CamWriteCmosSensor(0xc7, 0x9F);
			CamWriteCmosSensor(0xc8, 0xB4);
			CamWriteCmosSensor(0xc9, 0xC6);
			CamWriteCmosSensor(0xcA, 0xD3);
			CamWriteCmosSensor(0xcB, 0xDD);
			CamWriteCmosSensor(0xcC, 0xE5);
			CamWriteCmosSensor(0xcD, 0xF1);
			CamWriteCmosSensor(0xcE, 0xFA);
			CamWriteCmosSensor(0xcF, 0xFF);
			break;
			
		case GC0329_RGB_Gamma_m4:
			CamWriteCmosSensor(0xBF, 0x0E);
			CamWriteCmosSensor(0xc0, 0x1C);
			CamWriteCmosSensor(0xc1, 0x34);
			CamWriteCmosSensor(0xc2, 0x48);
			CamWriteCmosSensor(0xc3, 0x5A);
			CamWriteCmosSensor(0xc4, 0x6B);
			CamWriteCmosSensor(0xc5, 0x7B);
			CamWriteCmosSensor(0xc6, 0x95);
			CamWriteCmosSensor(0xc7, 0xAB);
			CamWriteCmosSensor(0xc8, 0xBF);
			CamWriteCmosSensor(0xc9, 0xCE);
			CamWriteCmosSensor(0xcA, 0xD9);
			CamWriteCmosSensor(0xcB, 0xE4);
			CamWriteCmosSensor(0xcC, 0xEC);
			CamWriteCmosSensor(0xcD, 0xF7);
			CamWriteCmosSensor(0xcE, 0xFD);
			CamWriteCmosSensor(0xcF, 0xFF);
			break;
			
		case GC0329_RGB_Gamma_m5:
			CamWriteCmosSensor(0xBF, 0x10);
			CamWriteCmosSensor(0xc0, 0x20);
			CamWriteCmosSensor(0xc1, 0x38);
			CamWriteCmosSensor(0xc2, 0x4E);
			CamWriteCmosSensor(0xc3, 0x63);
			CamWriteCmosSensor(0xc4, 0x76);
			CamWriteCmosSensor(0xc5, 0x87);
			CamWriteCmosSensor(0xc6, 0xA2);
			CamWriteCmosSensor(0xc7, 0xB8);
			CamWriteCmosSensor(0xc8, 0xCA);
			CamWriteCmosSensor(0xc9, 0xD8);
			CamWriteCmosSensor(0xcA, 0xE3);
			CamWriteCmosSensor(0xcB, 0xEB);
			CamWriteCmosSensor(0xcC, 0xF0);
			CamWriteCmosSensor(0xcD, 0xF8);
			CamWriteCmosSensor(0xcE, 0xFD);
			CamWriteCmosSensor(0xcF, 0xFF);
			break;
			
		case GC0329_RGB_Gamma_m6:										// largest gamma curve
			CamWriteCmosSensor(0xBF, 0x14);
			CamWriteCmosSensor(0xc0, 0x28);
			CamWriteCmosSensor(0xc1, 0x44);
			CamWriteCmosSensor(0xc2, 0x5D);
			CamWriteCmosSensor(0xc3, 0x72);
			CamWriteCmosSensor(0xc4, 0x86);
			CamWriteCmosSensor(0xc5, 0x95);
			CamWriteCmosSensor(0xc6, 0xB1);
			CamWriteCmosSensor(0xc7, 0xC6);
			CamWriteCmosSensor(0xc8, 0xD5);
			CamWriteCmosSensor(0xc9, 0xE1);
			CamWriteCmosSensor(0xcA, 0xEA);
			CamWriteCmosSensor(0xcB, 0xF1);
			CamWriteCmosSensor(0xcC, 0xF5);
			CamWriteCmosSensor(0xcD, 0xFB);
			CamWriteCmosSensor(0xcE, 0xFE);
			CamWriteCmosSensor(0xcF, 0xFF);
			break;
		case GC0329_RGB_Gamma_night:									//Gamma for night mode
			CamWriteCmosSensor(0xBF, 0x0B);
			CamWriteCmosSensor(0xc0, 0x16);
			CamWriteCmosSensor(0xc1, 0x29);
			CamWriteCmosSensor(0xc2, 0x3C);
			CamWriteCmosSensor(0xc3, 0x4F);
			CamWriteCmosSensor(0xc4, 0x5F);
			CamWriteCmosSensor(0xc5, 0x6F);
			CamWriteCmosSensor(0xc6, 0x8A);
			CamWriteCmosSensor(0xc7, 0x9F);
			CamWriteCmosSensor(0xc8, 0xB4);
			CamWriteCmosSensor(0xc9, 0xC6);
			CamWriteCmosSensor(0xcA, 0xD3);
			CamWriteCmosSensor(0xcB, 0xDD);
			CamWriteCmosSensor(0xcC, 0xE5);
			CamWriteCmosSensor(0xcD, 0xF1);
			CamWriteCmosSensor(0xcE, 0xFA);
			CamWriteCmosSensor(0xcF, 0xFF);
			break;
		default:
			//GC0329_RGB_Gamma_m1
			CamWriteCmosSensor(0xfe, 0x00);
			CamWriteCmosSensor(0xbf, 0x06);
			CamWriteCmosSensor(0xc0, 0x12);
			CamWriteCmosSensor(0xc1, 0x22);
			CamWriteCmosSensor(0xc2, 0x35);
			CamWriteCmosSensor(0xc3, 0x4b);
			CamWriteCmosSensor(0xc4, 0x5f);
			CamWriteCmosSensor(0xc5, 0x72);
			CamWriteCmosSensor(0xc6, 0x8d);
			CamWriteCmosSensor(0xc7, 0xa4);
			CamWriteCmosSensor(0xc8, 0xb8);
			CamWriteCmosSensor(0xc9, 0xc8);
			CamWriteCmosSensor(0xca, 0xd4);
			CamWriteCmosSensor(0xcb, 0xde);
			CamWriteCmosSensor(0xcc, 0xe6);
			CamWriteCmosSensor(0xcd, 0xf1);
			CamWriteCmosSensor(0xce, 0xf8);
			CamWriteCmosSensor(0xcf, 0xfd);
			break;
	}
}

/*************************************************************************
* FUNCTION
*   GC0329NightMode
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
static void GC0329NightMode(kal_bool Enable)
{
    // TODO: set night mode here
	GC0329Sensor.NightMode = Enable;
	if(Enable)
	{
		CamWriteCmosSensor(0xfe, 0x01);
		CamWriteCmosSensor(0x11, 0xa1);
		CamWriteCmosSensor(0x13, 0x68);
		CamWriteCmosSensor(0x21, 0xb0);
		CamWriteCmosSensor(0x22, 0x60);
		CamWriteCmosSensor(0xfe, 0x00);
		CamWriteCmosSensor(0x40, 0xef);
		CamWriteCmosSensor(0x41, 0x74);
		CamWriteCmosSensor(0x42, 0x7e);
		CamWriteCmosSensor(0xd1, 0x40);
		CamWriteCmosSensor(0xd2, 0x40);
		CamWriteCmosSensor(0xd3, 0x4b);
		CamWriteCmosSensor(0xd5, 0x2b);
		CamWriteCmosSensor(0xde, 0x30);
		GC0329GammaSelect(GC0329_RGB_Gamma_night);
	}
	else
	{
		CamWriteCmosSensor(0xfe, 0x01);
		CamWriteCmosSensor(0x11, 0xa1);
		CamWriteCmosSensor(0x13, 0x50);
		CamWriteCmosSensor(0x21, 0xb0);
		CamWriteCmosSensor(0x22, 0x48);
		CamWriteCmosSensor(0xfe, 0x00);
		CamWriteCmosSensor(0x40, 0xff);
		CamWriteCmosSensor(0x41, 0x04);
		CamWriteCmosSensor(0x42, 0x7e);
		CamWriteCmosSensor(0xd1, 0x30);
		CamWriteCmosSensor(0xd2, 0x30);
		CamWriteCmosSensor(0xd3, 0x40);
		CamWriteCmosSensor(0xd5, 0x00);
		CamWriteCmosSensor(0xde, 0x36);
		GC0329GammaSelect(GC0329_RGB_Gamma_m1);		
	}
#ifdef __GC0329_DEBUG_TRACE__
	GC0329_TRACE("GC0329NightMode Enable = %d",Enable);
#endif
	GC0329SetFPS();
}

/*************************************************************************
* FUNCTION
*   GC0329Ev
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
static MM_ERROR_CODE_ENUM GC0329Ev(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
		kal_uint8 value_luma, value_Y;
		/*switch night or normal mode*/
		value_luma = (GC0329Sensor.NightMode?0x2b:0x00);
		value_Y = (GC0329Sensor.NightMode?0x68:0x50);
		
		switch (In->FeatureSetValue)
        {
		case CAM_EV_NEG_4_3:	
			CamWriteCmosSensor(0xd5, value_luma - 0x48);
			CamWriteCmosSensor(0xfe, 0x01);
			CamWriteCmosSensor(0x13, value_Y - 0x28);
			CamWriteCmosSensor(0xfe, 0x00);
			break;		
		case CAM_EV_NEG_3_3:
			CamWriteCmosSensor(0xd5, value_luma - 0x30);
			CamWriteCmosSensor(0xfe, 0x01);
			CamWriteCmosSensor(0x13, value_Y - 0x18);
			CamWriteCmosSensor(0xfe, 0x00);
			break;		
		case CAM_EV_NEG_2_3:
			CamWriteCmosSensor(0xd5, value_luma - 0x20);
			CamWriteCmosSensor(0xfe, 0x01);
			CamWriteCmosSensor(0x13, value_Y - 0x10);
			CamWriteCmosSensor(0xfe, 0x00);
			break;				
		case CAM_EV_NEG_1_3:
			CamWriteCmosSensor(0xd5, value_luma - 0x10);
			CamWriteCmosSensor(0xfe, 0x01);
			CamWriteCmosSensor(0x13, value_Y - 0x08);
			CamWriteCmosSensor(0xfe, 0x00);
			break;				
		case CAM_EV_ZERO:
			CamWriteCmosSensor(0xd5, value_luma);
			CamWriteCmosSensor(0xfe, 0x01);
			CamWriteCmosSensor(0x13, value_Y);
			CamWriteCmosSensor(0xfe, 0x00);
			break;				
		case CAM_EV_POS_1_3:
			CamWriteCmosSensor(0xd5, value_luma + 0x10);
			CamWriteCmosSensor(0xfe, 0x01);
			CamWriteCmosSensor(0x13, value_Y + 0x10);
			CamWriteCmosSensor(0xfe, 0x00);
			break;				
		case CAM_EV_POS_2_3:
			CamWriteCmosSensor(0xd5, value_luma + 0x20);
			CamWriteCmosSensor(0xfe, 0x01);
			CamWriteCmosSensor(0x13, value_Y + 0x20);
			CamWriteCmosSensor(0xfe, 0x00);
			break;				
		case CAM_EV_POS_3_3:
			CamWriteCmosSensor(0xd5, value_luma + 0x30);
			CamWriteCmosSensor(0xfe, 0x01);
			CamWriteCmosSensor(0x13, value_Y + 0x30);
			CamWriteCmosSensor(0xfe, 0x00);
			break;				
		case CAM_EV_POS_4_3:	
			CamWriteCmosSensor(0xd5, value_luma + 0x48);
			CamWriteCmosSensor(0xfe, 0x01);
			CamWriteCmosSensor(0x13, value_Y + 0x48);
			CamWriteCmosSensor(0xfe, 0x00);
			break;
        default:
            return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        }
#ifdef __GC0329_DEBUG_TRACE__
		GC0329_TRACE("GC0329Ev Level = %d",In->FeatureSetValue - 4);
#endif
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC0329Contrast
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
static MM_ERROR_CODE_ENUM GC0329Contrast(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
        switch (In->FeatureSetValue)
        {
		case CAM_CONTRAST_HIGH:
			CamWriteCmosSensor(0xd3, 0x48);
			break;
		case CAM_CONTRAST_MEDIUM:
			CamWriteCmosSensor(0xd3, 0x40);
			break;
		case CAM_CONTRAST_LOW:
			CamWriteCmosSensor(0xd3, 0x38);
			break;
        default:
            return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        }
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC0329Saturation
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
static MM_ERROR_CODE_ENUM GC0329Saturation(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
*   GC0329Sharpness
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
static MM_ERROR_CODE_ENUM GC0329Sharpness(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
*   GC0329Wb
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
static MM_ERROR_CODE_ENUM GC0329Wb(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
			CamWriteCmosSensor(0x77, 0x57);
			CamWriteCmosSensor(0x78, 0x4d);
			CamWriteCmosSensor(0x79, 0x45);
			GC0329AwbEnable(KAL_TRUE);
			break;
		case CAM_WB_CLOUD:
			GC0329AwbEnable(KAL_FALSE);
			CamWriteCmosSensor(0x77, 0x8c);
			CamWriteCmosSensor(0x78, 0x50);
			CamWriteCmosSensor(0x79, 0x40);
			break;
		case CAM_WB_DAYLIGHT:
			GC0329AwbEnable(KAL_FALSE);
			CamWriteCmosSensor(0x77, 0x74); 
			CamWriteCmosSensor(0x78, 0x52);
			CamWriteCmosSensor(0x79, 0x40); 
			break;
		case CAM_WB_INCANDESCENCE:
			GC0329AwbEnable(KAL_FALSE);
			CamWriteCmosSensor(0x77, 0x48);
			CamWriteCmosSensor(0x78, 0x40);
			CamWriteCmosSensor(0x79, 0x5c);
			break;
		case CAM_WB_FLUORESCENT:
			GC0329AwbEnable(KAL_FALSE);
			CamWriteCmosSensor(0x77, 0x40);
			CamWriteCmosSensor(0x78, 0x42);
			CamWriteCmosSensor(0x79, 0x50);
			break;
		case CAM_WB_TUNGSTEN:
			GC0329AwbEnable(KAL_FALSE);
			CamWriteCmosSensor(0x77, 0x40);
			CamWriteCmosSensor(0x78, 0x54);
			CamWriteCmosSensor(0x79, 0x70);
			break;
        default:
            return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        }
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC0329Effect
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
static MM_ERROR_CODE_ENUM GC0329Effect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
			CamWriteCmosSensor(0x43 , 0x00);
			break;
		case CAM_EFFECT_ENC_SEPIA:
			CamWriteCmosSensor(0x43 , 0x02);
			CamWriteCmosSensor(0xda , 0xd0);
			CamWriteCmosSensor(0xdb , 0x28);
			break;
		case CAM_EFFECT_ENC_COLORINV:
			CamWriteCmosSensor(0x43 , 0x01);
			break;
		case CAM_EFFECT_ENC_SEPIAGREEN:
			CamWriteCmosSensor(0x43 , 0x02);
			CamWriteCmosSensor(0xda , 0xc0);
			CamWriteCmosSensor(0xdb , 0xc0);
			break;
		case CAM_EFFECT_ENC_SEPIABLUE:
			CamWriteCmosSensor(0x43 , 0x02);
			CamWriteCmosSensor(0xda , 0x50);
			CamWriteCmosSensor(0xdb , 0xe0);
			break;
		case CAM_EFFECT_ENC_GRAYSCALE: 
			CamWriteCmosSensor(0x43 , 0x02);
			CamWriteCmosSensor(0xda , 0x00);
			CamWriteCmosSensor(0xdb , 0x00);
			break;
        default:
            return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        }
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC0329StillCaptureSize
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
MM_ERROR_CODE_ENUM GC0329StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
        CapSize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC0329Banding
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
static MM_ERROR_CODE_ENUM GC0329Banding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
        GC0329Sensor.BandingFreq = (CAM_BANDING_50HZ == In->FeatureSetValue ? GC0329_50HZ : GC0329_60HZ);
        // TODO: set manual banding here
        {
            if (CAM_BANDING_50HZ == In->FeatureSetValue)
            {
				CamWriteCmosSensor(0x05, 0x00); 	
				CamWriteCmosSensor(0x06, 0x35);

				CamWriteCmosSensor(0xfe, 0x01);
				CamWriteCmosSensor(0x29, 0x00);   //anti-flicker step [11:8]
				CamWriteCmosSensor(0x2a, 0xae);   //anti-flicker step [7:0]
				
				CamWriteCmosSensor(0x2b, 0x02);   //exp level 0  30.00fps
				CamWriteCmosSensor(0x2c, 0x0a); 
				CamWriteCmosSensor(0x2d, 0x04);   //exp level 1  14.29fps
				CamWriteCmosSensor(0x2e, 0xc2); 
				CamWriteCmosSensor(0x2f, 0x06);   //exp level 2  10.00fps
				CamWriteCmosSensor(0x30, 0xcc); 
				CamWriteCmosSensor(0x31, 0x0c);   //exp level 3  5.26fps
				CamWriteCmosSensor(0x32, 0xea); 
				CamWriteCmosSensor(0xfe, 0x00);
            }
            else
            {
				CamWriteCmosSensor(0x05, 0x00);
				CamWriteCmosSensor(0x06, 0x3a);

				CamWriteCmosSensor(0xfe, 0x01);
				CamWriteCmosSensor(0x29, 0x00);   //anti-flicker step [11:8]
				CamWriteCmosSensor(0x2a, 0x85);   //anti-flicker step [7:0]
				
				CamWriteCmosSensor(0x2b, 0x02);   //exp level 0  30.00fps
				CamWriteCmosSensor(0x2c, 0x14); 
				CamWriteCmosSensor(0x2d, 0x04);   //exp level 0  15.00fps
				CamWriteCmosSensor(0x2e, 0x28); 
				CamWriteCmosSensor(0x2f, 0x06);   //exp level 0  10.00fps
				CamWriteCmosSensor(0x30, 0x3c); 
				CamWriteCmosSensor(0x31, 0x0c);   //exp level 0  5.00fps
				CamWriteCmosSensor(0x32, 0x78); 
				CamWriteCmosSensor(0xfe, 0x00);
            }
#ifdef __GC0329_DEBUG_TRACE__
			GC0329_TRACE("GC0329Banding BandingFreq = %d",In->FeatureSetValue);
#endif
        }		
		GC0329SetFPS();
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC0329SceneMode
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
static MM_ERROR_CODE_ENUM GC0329SceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
*   GC0329InitialSetting
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
static void GC0329InitialSetting(void)
{
	// TODO: add initial code here
	CamWriteCmosSensor(0xfe, 0x80);
	CamWriteCmosSensor(0xfc, 0x12); 
	CamWriteCmosSensor(0xfc, 0x12); 
	CamWriteCmosSensor(0xfe, 0x00);
	CamWriteCmosSensor(0xf0, 0x07); 
	CamWriteCmosSensor(0xf1, 0x01); 

	CamWriteCmosSensor(0x73, 0x90); 
	CamWriteCmosSensor(0x74, 0x80); 
	CamWriteCmosSensor(0x75, 0x80); 
	CamWriteCmosSensor(0x76, 0x94); 

	//CamWriteCmosSensor(0x42, 0x00);
	//CamWriteCmosSensor(0x77, 0x57);
	//CamWriteCmosSensor(0x78, 0x4d);
	//CamWriteCmosSensor(0x79, 0x45);
	//CamWriteCmosSensor(0x42, 0xfc);

	////////////////////analog////////////////////
	CamWriteCmosSensor(0xfc, 0x16); 

	//CamWriteCmosSensor(0x05, 0x00); 
	//CamWriteCmosSensor(0x06, 0x6a); 
	//CamWriteCmosSensor(0x07, 0x00); 
	//CamWriteCmosSensor(0x08, 0x70);
	
	CamWriteCmosSensor(0x09, 0x00); 
	CamWriteCmosSensor(0x0a, 0x02); 
	CamWriteCmosSensor(0x0b, 0x00); 
	CamWriteCmosSensor(0x0c, 0x02);
	
	CamWriteCmosSensor(0x17, 0x16); 
	CamWriteCmosSensor(0x19, 0x05); 
	CamWriteCmosSensor(0x1b, 0x24); 
	CamWriteCmosSensor(0x1c, 0x04); 
	CamWriteCmosSensor(0x1e, 0x08); 
	CamWriteCmosSensor(0x1f, 0xc0); 
	CamWriteCmosSensor(0x20, 0x00); 
	CamWriteCmosSensor(0x21, 0x48);
	CamWriteCmosSensor(0x22, 0xba);
	CamWriteCmosSensor(0x23, 0x22); 
	CamWriteCmosSensor(0x24, 0x16); 


	////////////////////blk////////////////////
	CamWriteCmosSensor(0x26, 0xf7);
	//CamWriteCmosSensor(0x29, 0x80);
	CamWriteCmosSensor(0x32, 0x04);
	CamWriteCmosSensor(0x33, 0x20);
	CamWriteCmosSensor(0x34, 0x20);
	CamWriteCmosSensor(0x35, 0x20);
	CamWriteCmosSensor(0x36, 0x20);

	////////////////////ISP BLOCK ENABLE////////////////////
	CamWriteCmosSensor(0x40, 0xff); 
	CamWriteCmosSensor(0x41, 0x04);
	CamWriteCmosSensor(0x42, 0x7e); 
	CamWriteCmosSensor(0x46, 0x02); 
	CamWriteCmosSensor(0x4b, 0xcb);
	CamWriteCmosSensor(0x4d, 0x01); 
	CamWriteCmosSensor(0x4f, 0x01);
	CamWriteCmosSensor(0x70, 0x40);

	//CamWriteCmosSensor(0xb0, 0x00);
	//CamWriteCmosSensor(0xbc, 0x00);
	//CamWriteCmosSensor(0xbd, 0x00);
	//CamWriteCmosSensor(0xbe, 0x00);

	////////////////////DNDD////////////////////
	CamWriteCmosSensor(0x80, 0xe7); 
	//CamWriteCmosSensor(0x81, 0x0e); 
	CamWriteCmosSensor(0x82, 0x55); 
	CamWriteCmosSensor(0x87, 0x4a); 

	////////////////////ASDE////////////////////
	CamWriteCmosSensor(0xfe, 0x01);
	CamWriteCmosSensor(0x18, 0x22); 
	CamWriteCmosSensor(0xfe, 0x00);
	CamWriteCmosSensor(0x9c, 0x0a); 
	CamWriteCmosSensor(0xa4, 0x50); 
	CamWriteCmosSensor(0xa5, 0x21); 
	CamWriteCmosSensor(0xa7, 0x35); 
	CamWriteCmosSensor(0xdd, 0x54); 
	CamWriteCmosSensor(0x95, 0x35); 

	////////////////////RGB gamma////////////////////
	CamWriteCmosSensor(0xfe, 0x00);
	CamWriteCmosSensor(0xbf, 0x06);
	CamWriteCmosSensor(0xc0, 0x12);
	CamWriteCmosSensor(0xc1, 0x22);
	CamWriteCmosSensor(0xc2, 0x35);
	CamWriteCmosSensor(0xc3, 0x4b);
	CamWriteCmosSensor(0xc4, 0x5f);
	CamWriteCmosSensor(0xc5, 0x72);
	CamWriteCmosSensor(0xc6, 0x8d);
	CamWriteCmosSensor(0xc7, 0xa4);
	CamWriteCmosSensor(0xc8, 0xb8);
	CamWriteCmosSensor(0xc9, 0xc8);
	CamWriteCmosSensor(0xca, 0xd4);
	CamWriteCmosSensor(0xcb, 0xde);
	CamWriteCmosSensor(0xcc, 0xe6);
	CamWriteCmosSensor(0xcd, 0xf1);
	CamWriteCmosSensor(0xce, 0xf8);
	CamWriteCmosSensor(0xcf, 0xfd);

	//////////////////CC///////////////////
	CamWriteCmosSensor(0xfe, 0x00);
	CamWriteCmosSensor(0xb3, 0x44);
	CamWriteCmosSensor(0xb4, 0xfd);
	CamWriteCmosSensor(0xb5, 0x02);
	CamWriteCmosSensor(0xb6, 0xfa);
	CamWriteCmosSensor(0xb7, 0x48);
	CamWriteCmosSensor(0xb8, 0xf0);

	//skin
	//CamWriteCmosSensor(0xb3, 0x3c);
	//CamWriteCmosSensor(0xb4, 0xFF);
	//CamWriteCmosSensor(0xb5, 0x03);
	//CamWriteCmosSensor(0xb6, 0x01);
	//CamWriteCmosSensor(0xb7, 0x3f);
	//CamWriteCmosSensor(0xb8, 0xF3);

	// crop 
	CamWriteCmosSensor(0x50, 0x01);
	CamWriteCmosSensor(0x19, 0x05);
	CamWriteCmosSensor(0x20, 0x01);
	CamWriteCmosSensor(0x22, 0xba);
	CamWriteCmosSensor(0x21, 0x48);

	////////////////////YCP////////////////////
	CamWriteCmosSensor(0xfe, 0x00);
	CamWriteCmosSensor(0xd1, 0x30); 
	CamWriteCmosSensor(0xd2, 0x30); 
	
	////////////////////AEC////////////////////
	CamWriteCmosSensor(0xfe, 0x01);
	CamWriteCmosSensor(0x10, 0x40);
	CamWriteCmosSensor(0x11, 0xa1);
	CamWriteCmosSensor(0x12, 0x03);//0x06
	CamWriteCmosSensor(0x13, 0x50); 
	CamWriteCmosSensor(0x17, 0x88);
	CamWriteCmosSensor(0x1a, 0x21);
	CamWriteCmosSensor(0x21, 0xb0);
	CamWriteCmosSensor(0x22, 0x48);
	CamWriteCmosSensor(0x3c, 0x30);//0x95
	CamWriteCmosSensor(0x3d, 0x70);//0x50
	CamWriteCmosSensor(0x3e, 0x30);//0x90

	////////////////////AWB////////////////////
	CamWriteCmosSensor(0xfe, 0x01);
	CamWriteCmosSensor(0x06, 0x16);
	CamWriteCmosSensor(0x07, 0x06);
	CamWriteCmosSensor(0x08, 0x98);
	CamWriteCmosSensor(0x09, 0xee);
	CamWriteCmosSensor(0x50, 0xfc);
	CamWriteCmosSensor(0x51, 0x28);
	CamWriteCmosSensor(0x52, 0x0b);
	CamWriteCmosSensor(0x53, 0x10);
	CamWriteCmosSensor(0x54, 0x10);
	CamWriteCmosSensor(0x55, 0x10);
	CamWriteCmosSensor(0x56, 0x20);
	//CamWriteCmosSensor(0x57, 0x40); 
	CamWriteCmosSensor(0x58, 0x60);
	CamWriteCmosSensor(0x59, 0x28);
	CamWriteCmosSensor(0x5a, 0x02);
	CamWriteCmosSensor(0x5b, 0x63);
	CamWriteCmosSensor(0x5c, 0x3d);
	CamWriteCmosSensor(0x5d, 0x73);
	CamWriteCmosSensor(0x5e, 0x11);
	CamWriteCmosSensor(0x5f, 0x40);
	CamWriteCmosSensor(0x60, 0x40);
	CamWriteCmosSensor(0x61, 0xc8);
	CamWriteCmosSensor(0x62, 0xa0);
	CamWriteCmosSensor(0x63, 0x40);
	CamWriteCmosSensor(0x64, 0x50);
	CamWriteCmosSensor(0x65, 0x98);
	CamWriteCmosSensor(0x66, 0xfa);
	CamWriteCmosSensor(0x67, 0x70);
	CamWriteCmosSensor(0x68, 0x58);
	CamWriteCmosSensor(0x69, 0x85);
	CamWriteCmosSensor(0x6a, 0x40);
	CamWriteCmosSensor(0x6b, 0x39);
	CamWriteCmosSensor(0x6c, 0x20);
	CamWriteCmosSensor(0x6d, 0x30);
	CamWriteCmosSensor(0x6e, 0x00);
	CamWriteCmosSensor(0x70, 0x02);
	CamWriteCmosSensor(0x71, 0x00);
	CamWriteCmosSensor(0x72, 0x10);
	CamWriteCmosSensor(0x73, 0x40);
	
	CamWriteCmosSensor(0x80, 0x58);
	CamWriteCmosSensor(0x81, 0x50);
	CamWriteCmosSensor(0x82, 0x44);
	CamWriteCmosSensor(0x83, 0x40);
	CamWriteCmosSensor(0x84, 0x40);
	CamWriteCmosSensor(0x85, 0x40);
	
	CamWriteCmosSensor(0x74, 0x40);
	CamWriteCmosSensor(0x75, 0x58);
	CamWriteCmosSensor(0x76, 0x24);
	CamWriteCmosSensor(0x77, 0x40);
	CamWriteCmosSensor(0x78, 0x20);
	CamWriteCmosSensor(0x79, 0x60);
	CamWriteCmosSensor(0x7a, 0x58);
	CamWriteCmosSensor(0x7b, 0x20);
	CamWriteCmosSensor(0x7c, 0x30);
	CamWriteCmosSensor(0x7d, 0x35);
	CamWriteCmosSensor(0x7e, 0x10);
	CamWriteCmosSensor(0x7f, 0x08);

	///////////////////ABS///////////////////////
	CamWriteCmosSensor(0x9c, 0x02);
	CamWriteCmosSensor(0x9d, 0x30);


	////////////////////CC-AWB////////////////////
	CamWriteCmosSensor(0xd0, 0x00);
	CamWriteCmosSensor(0xd2, 0x2c); 
	CamWriteCmosSensor(0xd3, 0x80);

	///////////////////LSC //////////////////////
	//// for xuye062d lens setting
	CamWriteCmosSensor(0xfe, 0x01);
	CamWriteCmosSensor(0xa0, 0x00);
	CamWriteCmosSensor(0xa1, 0x3c);
	CamWriteCmosSensor(0xa2, 0x50);
	CamWriteCmosSensor(0xa3, 0x00);
	CamWriteCmosSensor(0xa8, 0x0f);
	CamWriteCmosSensor(0xa9, 0x08);
	CamWriteCmosSensor(0xaa, 0x00);
	CamWriteCmosSensor(0xab, 0x04);
	CamWriteCmosSensor(0xac, 0x00);
	CamWriteCmosSensor(0xad, 0x07);
	CamWriteCmosSensor(0xae, 0x0e);
	CamWriteCmosSensor(0xaf, 0x00);
	CamWriteCmosSensor(0xb0, 0x00);
	CamWriteCmosSensor(0xb1, 0x09);
	CamWriteCmosSensor(0xb2, 0x00);
	CamWriteCmosSensor(0xb3, 0x00);
	CamWriteCmosSensor(0xb4, 0x35);
	CamWriteCmosSensor(0xb5, 0x28);
	CamWriteCmosSensor(0xb6, 0x24);
	CamWriteCmosSensor(0xba, 0x3c);
	CamWriteCmosSensor(0xbb, 0x2f);
	CamWriteCmosSensor(0xbc, 0x2c);
	CamWriteCmosSensor(0xc0, 0x1b);
	CamWriteCmosSensor(0xc1, 0x16);
	CamWriteCmosSensor(0xc2, 0x15);
	CamWriteCmosSensor(0xc6, 0x21);
	CamWriteCmosSensor(0xc7, 0x1c);
	CamWriteCmosSensor(0xc8, 0x1b);
	CamWriteCmosSensor(0xb7, 0x00);
	CamWriteCmosSensor(0xb8, 0x00);
	CamWriteCmosSensor(0xb9, 0x00);
	CamWriteCmosSensor(0xbd, 0x00);
	CamWriteCmosSensor(0xbe, 0x00);
	CamWriteCmosSensor(0xbf, 0x00);
	CamWriteCmosSensor(0xc3, 0x00);
	CamWriteCmosSensor(0xc4, 0x00);
	CamWriteCmosSensor(0xc5, 0x00);
	CamWriteCmosSensor(0xc9, 0x00);
	CamWriteCmosSensor(0xca, 0x00);
	CamWriteCmosSensor(0xcb, 0x00);
	CamWriteCmosSensor(0xa4, 0x00);
	CamWriteCmosSensor(0xa5, 0x00);
	CamWriteCmosSensor(0xa6, 0x00);
	CamWriteCmosSensor(0xa7, 0x00);

	CamWriteCmosSensor(0xfe, 0x00);
	////////////////////asde ///////////////////
	CamWriteCmosSensor(0xa0, 0xaf);
	CamWriteCmosSensor(0xa2, 0xff);

	CamWriteCmosSensor(0x44, 0xa2);

}

/*************************************************************************
* FUNCTION
*   GC0329PvSetting
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
static void GC0329PvSetting(void)
{
    // TODO: add preview setting here
    
}

/*************************************************************************
* FUNCTION
*   GC0329CapSetting
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
static void GC0329CapSetting(void)
{
    // TODO: add capture setting here
    
}

/*************************************************************************
* FUNCTION
*   GC0329GetSensorInfo
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
static void GC0329GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT Info)
{
    Info->SensorId = GC0329_SENSOR_ID;
    Info->SensorIf = IMAGE_SENSOR_IF_PARALLEL;

    /* data format */
    Info->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
    Info->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
    Info->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
    Info->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;
    Info->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_YUYV;

    Info->PreviewMclkFreq = GC0329_MCLK;
    Info->CaptureMclkFreq = GC0329_MCLK;
    Info->VideoMclkFreq = GC0329_MCLK;
    Info->PreviewWidth = GC0329_IMAGE_SENSOR_PV_WIDTH;
    Info->PreviewHeight = GC0329_IMAGE_SENSOR_PV_HEIGHT;
    Info->FullWidth = GC0329_IMAGE_SENSOR_FULL_WIDTH;
    Info->FullHeight = GC0329_IMAGE_SENSOR_FULL_HEIGHT;
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
*   GC0329PowerOn
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
static kal_uint32 GC0329PowerOn(void)
{
    static kal_uint8 GC0329I2cAddr[] = {GC0329_WRITE_ID_0,
#if (GC0329_WRITE_ID_1 != 0xFF)
    GC0329_WRITE_ID_1,
#endif
#if (GC0329_WRITE_ID_2 != 0xFF)
    GC0329_WRITE_ID_2,
#endif
#if (GC0329_WRITE_ID_3 != 0xFF)
    GC0329_WRITE_ID_3,
#endif
    };
    kal_uint32 SensorId;
    kal_uint8 i;

    CisModulePowerOn(GC0329Sensor.SensorIdx, KAL_TRUE);
    CameraSccbOpen(CAMERA_SCCB_SENSOR, GC0329_WRITE_ID_0,
    GC0329_I2C_ADDR_BITS, GC0329_I2C_DATA_BITS, GC0329_HW_I2C_SPEED);
    /* add under line if sensor I2C do not support repeat start */
    //CameraSccbDisWR(CAMERA_SCCB_SENSOR);

    // TODO: add hardware reset  by spec here
    {
    	//SET PDN LOW
		GC0329_SET_PDN_LOW;
		kal_sleep_task(1);
		//SET RST
		GC0329_SET_RST_HIGH;
		kal_sleep_task(1);
		GC0329_SET_RST_LOW;
		kal_sleep_task(1);
		GC0329_SET_RST_HIGH;
		kal_sleep_task(1);
    }

    for (i = 0; i < sizeof(GC0329I2cAddr) / sizeof(GC0329I2cAddr[0]); i++)
    {
        CameraSccbSetAddr(CAMERA_SCCB_SENSOR, GC0329I2cAddr[i]);

        // TODO: read sensor id here
        {
			CamWriteCmosSensor(0xfc, 0x16);
			kal_sleep_task(1);
			SensorId = CamReadCmosSensor(0x00);
        }
        if (GC0329_SENSOR_ID == SensorId)
        {
            kal_uint8 Temp;

            /* swap the correct i2c address to first one, it will speed up next time read sensor ID */
            Temp = GC0329I2cAddr[0];
            GC0329I2cAddr[0] = GC0329I2cAddr[i];
            GC0329I2cAddr[i] = Temp;
            break;
        }
    }
    GC0329_TRACE("SENSOR ID: %x", SensorId);
    return SensorId;
}

/*************************************************************************
* FUNCTION
*   GC0329PowerDown
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
static void GC0329PowerDown(void)
{
    // TODO: power down sensor by spec here
	GC0329_SET_RST_LOW;
	kal_sleep_task(1);
	GC0329_SET_PDN_HIGH;
}

/*************************************************************************
* FUNCTION
*   GC0329Preview
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
static void GC0329Preview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
    GC0329Sensor.BandingFreq = (CAM_BANDING_50HZ == In->BandingFreq ? GC0329_50HZ : GC0329_60HZ);

    /* change to preview size output */
    GC0329Sensor.PvMode = KAL_TRUE;
    GC0329PvSetting();
    GC0329SetClock(GC0329_PV_INTERNAL_CLK);

    /* set preview frame rate range */
    switch (Id)
    {
    case CAL_SCENARIO_VIDEO:
		GC0329Sensor.VideoMode = KAL_TRUE;
        //GC0329SetVideoFps(In->MaxVideoFrameRate);
        break;
    default:
		GC0329Sensor.VideoMode = KAL_FALSE;
        //GC0329SetMaxFps(GC0329_FPS(30));
        //GC0329SetMinFps(In->NightMode ? GC0329_FPS(5) : GC0329_FPS(10));

        /* roll back shutter&gain from capture state */
        if (GC0329Sensor.CapState)
        {
            GC0329WriteShutter(GC0329Sensor.Shutter);
            GC0329WriteGain(GC0329Sensor.Gain);
        }
		break;
    }
	
    /* misc setting */
    GC0329SetMirror(In->ImageMirror);
    GC0329NightMode(In->NightMode);
	
    /* change to preview state */
    GC0329Sensor.CapState = KAL_FALSE;

    /* enable ae/awb */
    GC0329AeEnable(KAL_TRUE);
    GC0329AwbEnable(KAL_TRUE);

    /* set grab window */
    Out->WaitStableFrameNum = 1;
    Out->GrabStartX = GC0329_PV_GRAB_START_X;
    Out->GrabStartY = GC0329_PV_GRAB_START_Y;
    Out->ExposureWindowWidth = GC0329_PV_GRAB_WIDTH;
    Out->ExposureWindowHeight = GC0329_PV_GRAB_HEIGHT;
}

/*************************************************************************
* FUNCTION
*   GC0329Capture
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
static void GC0329Capture(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
    kal_uint32 PvClk, PvLineLength, CapShutter, CapLineLength, DummyPixel = 0;

    /* back up preview clock/linelength/shutter */
    PvClk = GC0329Sensor.InternalClock;
    PvLineLength = GC0329Sensor.LineLength;
    GC0329Sensor.Shutter = GC0329ReadShutter();
    GC0329Sensor.Gain = GC0329ReadGain();

    /* change to capture state */
    GC0329Sensor.CapState = KAL_TRUE;
    if (1)
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
                /* GC0329SetClock(~); */
            }
            else if (In->ZoomFactor > 200) /* (2, 4]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC0329SetClock(~); */
            }
            else if (In->ZoomFactor > 100) /* (1, 2]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC0329SetClock(~); */
            }
#elif (defined(DRV_ISP_6238_SERIES))
            if (In->ZoomFactor > 400) /* (4, 8]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC0329SetClock(~); */
            }
            else if (In->ZoomFactor > 200) /* (2, 4]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC0329SetClock(~); */
            }
            else if (In->ZoomFactor > 100) /* (1, 2]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC0329SetClock(~); */
            }
#elif (defined(DRV_ISP_6235_SERIES)) /* MT6235 */
            if (In->ZoomFactor > 400) /* (4, 8]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC0329SetClock(~); */
            }
            else if (In->ZoomFactor > 200) /* (2, 4]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC0329SetClock(~); */
            }
            else if (In->ZoomFactor > 100) /* (1, 2]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC0329SetClock(~); */
            }
#else
#error not verify yet
#endif
        }

        if (DummyPixel)
        {
            /* disable ae/awb */
            GC0329AeEnable(KAL_FALSE);
            GC0329AwbEnable(KAL_FALSE);

            /* set dummy pixel */
            if (PvLineLength - GC0329_PV_PERIOD_PIXEL_NUMS > DummyPixel)
            {
                DummyPixel = PvLineLength - GC0329_PV_PERIOD_PIXEL_NUMS;
            }
            GC0329SetDummy(DummyPixel, 0);

            /* shutter translation, GC0329Sensor.InternalClock >> 14 & PvClk >> 14 to avoid data overflow */
            //CapShutter = (GC0329Sensor.Shutter * (GC0329Sensor.InternalClock >> 14) + (PvClk >> 15)) / (PvClk >> 14);
            //CapShutter = (CapShutter * PvLineLength + (GC0329Sensor.LineLength >> 1)) / GC0329Sensor.LineLength;
			CapShutter = GC0329Sensor.Shutter;
            /* write shutter */
            GC0329WriteShutter(CapShutter);

            Out->WaitStableFrameNum = GC0329_CAPTURE_DELAY_FRAME;
        }
        else
        {
            Out->WaitStableFrameNum = 0;
        }

        /* set grab window */
        Out->GrabStartX = GC0329_PV_GRAB_START_X;
        Out->GrabStartY = GC0329_PV_GRAB_START_Y;
        Out->ExposureWindowWidth = GC0329_PV_GRAB_WIDTH;
        Out->ExposureWindowHeight = GC0329_PV_GRAB_HEIGHT;
    }
    else
    {
        /* disable ae/awb */
        GC0329AeEnable(KAL_FALSE);
        GC0329AwbEnable(KAL_FALSE);

        /* change to full size output */
        GC0329Sensor.PvMode = KAL_FALSE;
        GC0329CapSetting();
        GC0329SetClock(6500000);

        // TODO: add dummy pixel or reduce pclk until capture success
        {
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT) || defined(DRV_ISP_6276_SERIES)) /* MT6253/76 */
            /* no need reduce frame rate */
#elif (defined(DRV_ISP_MT6236_HW_SUPPORT)) /* MT6236 */
            if (In->ZoomFactor > 400) /* (4, 8]x zoom */
            {
                DummyPixel = 652;
                /* please reduce pclk if dummy pixel overflow */
                /* GC0329SetClock(~); */
            }
            else if (In->ZoomFactor > 200) /* (2, 4]x zoom */
            {
                DummyPixel = 652;
                /* please reduce pclk if dummy pixel overflow */
                /* GC0329SetClock(~); */
            }
            else if (In->ZoomFactor > 100) /* (1, 2]x zoom */
            {
                DummyPixel = 652;
                /* please reduce pclk if dummy pixel overflow */
                /* GC0329SetClock(~); */
            }
#elif (defined(DRV_ISP_6238_SERIES))
            if (In->ZoomFactor > 400) /* (4, 8]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC0329SetClock(~); */
            }
            else if (In->ZoomFactor > 200) /* (2, 4]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC0329SetClock(~); */
            }
            else if (In->ZoomFactor > 100) /* (1, 2]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC0329SetClock(~); */
            }
#elif (defined(DRV_ISP_6235_SERIES)) /* MT6235 */
            if (In->ZoomFactor > 400) /* (4, 8]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC0329SetClock(~); */
            }
            else if (In->ZoomFactor > 200) /* (2, 4]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC0329SetClock(~); */
            }
            else if (In->ZoomFactor > 100) /* (1, 2]x zoom */
            {
                DummyPixel = 0;
                /* please reduce pclk if dummy pixel overflow */
                /* GC0329SetClock(~); */
            }
#else
#error not verify yet
#endif
        }

        /* set dummy pixel */
        CapLineLength = GC0329Sensor.InternalClock * GC0329_FPS(1) / (GC0329_FULL_PERIOD_LINE_NUMS * In->MaxVideoFrameRate);
        if (CapLineLength < GC0329_FULL_PERIOD_PIXEL_NUMS)
        {
            CapLineLength = GC0329_FULL_PERIOD_PIXEL_NUMS;
        }
        if (CapLineLength > GC0329_MAX_CAP_LINELENGTH) /* register limitation */
        {
            GC0329_TRACE("caplinelength: %d, capframerate: %d overflow!!!", CapLineLength, In->MaxVideoFrameRate);
            CapLineLength = GC0329_MAX_CAP_LINELENGTH;
        }
        if (CapLineLength - GC0329_FULL_PERIOD_PIXEL_NUMS > DummyPixel)
        {
            DummyPixel = CapLineLength - GC0329_FULL_PERIOD_PIXEL_NUMS;
        }
        GC0329SetDummy(DummyPixel, 0);

        /* shutter translation, GC0329Sensor.InternalClock >> 14 & PvClk >> 14 to avoid data overflow */
        //CapShutter = (GC0329Sensor.Shutter * (GC0329Sensor.InternalClock >> 14) + (PvClk >> 15)) / (PvClk >> 14);
        //CapShutter = (CapShutter * PvLineLength + (GC0329Sensor.LineLength >> 1)) / GC0329Sensor.LineLength;
		CapShutter = GC0329Sensor.Shutter / 2;
        /* write shutter */
        GC0329WriteShutter(CapShutter);

        /* set grab window */
        Out->WaitStableFrameNum = GC0329_CAPTURE_DELAY_FRAME;
        Out->GrabStartX = GC0329_FULL_GRAB_START_X;
        Out->GrabStartY = GC0329_FULL_GRAB_START_Y;
        Out->ExposureWindowWidth = GC0329_FULL_GRAB_WIDTH;
        Out->ExposureWindowHeight = GC0329_FULL_GRAB_HEIGHT;
    }
}

/*************************************************************************
* FUNCTION
*   GC0329DetectSensorId
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
static kal_uint32 GC0329DetectSensorId(void)
{
    MM_ERROR_CODE_ENUM GC0329SensorClose(void);
    kal_uint32 SensorId;
    IMAGE_SENSOR_INDEX_ENUM InvIdx;
    kal_int8 i, j;

    switch (GC0329Sensor.SensorIdx)
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
            SensorId = GC0329PowerOn();
            GC0329SensorClose();
            if (GC0329_SENSOR_ID == SensorId)
            {
                return GC0329_SENSOR_ID;
            }
        }
    }
    return MM_ERROR_SENSOR_READ_ID_FAIL;
}

/*************************************************************************
* FUNCTION
*   GC0329InitOperationPara
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
static void GC0329InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
    Para->CaptureDelayFrame = 0; /* use WaitStableFrameNum instead of this */
    Para->PreviewDelayFrame = GC0329_PREVIEW_DELAY_FRAME;
    Para->PreviewDisplayWaitFrame = GC0329_FIRST_PREVIEW_DELAY_FRAME;
}

/*************************************************************************
* FUNCTION
*   GC0329SensorOpen
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
static MM_ERROR_CODE_ENUM GC0329SensorOpen(void)
{
    if (GC0329PowerOn() != GC0329_SENSOR_ID)
    {
        return MM_ERROR_SENSOR_READ_ID_FAIL;
    }
#ifdef GC0329_LOAD_FROM_T_FLASH
    if (!GC0329_Initialize_from_T_Flash()) /* for debug use. */
#endif
    {
        GC0329InitialSetting(); /* apply the sensor initial setting */
    }

    /* default setting */
    GC0329Sensor.BypassAe = KAL_FALSE; /* for panorama view */
    GC0329Sensor.BypassAwb = KAL_FALSE; /* for panorama view */
    GC0329Sensor.CapState = KAL_FALSE; /* preview state */
    GC0329Sensor.PvMode = KAL_TRUE; /* preview size output mode */
	GC0329Sensor.VideoMode = KAL_FALSE; /* preview mode */
	GC0329Sensor.NightMode = KAL_FALSE; /*normal mode*/
    GC0329Sensor.BandingFreq = GC0329_50HZ;
    GC0329Sensor.InternalClock = 1; /* will be update by setclock function */
    GC0329Sensor.Shutter = 1; /* default shutter 1 avoid divide by 0 */
    GC0329Sensor.Gain = 0x40; /* default gain 1x */
    GC0329Sensor.FrameLength = GC0329_PV_PERIOD_LINE_NUMS; /* will be update by setdummy function */
    GC0329Sensor.LineLength = GC0329_PV_PERIOD_PIXEL_NUMS; /* will be update by setdummy function */

    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC0329SensorFeatureCtrl
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
static MM_ERROR_CODE_ENUM GC0329SensorFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
    MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;

    if (Id >= CAL_FEATURE_WEBCAM_BEGIN && Id <= CAL_FEATURE_WEBCAM_END)
    {
        return GC0329WebcamFeatureCtrl(Id, In, Out, OutLen, RealOutLen);
    }
    switch (Id)
    {
    /* query and set series */
    case CAL_FEATURE_CAMERA_BRIGHTNESS:
    case CAL_FEATURE_CAMERA_EV_VALUE:
        ErrCode = GC0329Ev(In, Out);
        break;
    case CAL_FEATURE_CAMERA_CONTRAST:
        ErrCode = GC0329Contrast(In, Out);
        break;
    case CAL_FEATURE_CAMERA_SATURATION:
        ErrCode = GC0329Saturation(In, Out);
        break;
    case CAL_FEATURE_CAMERA_SHARPNESS:
        ErrCode = GC0329Sharpness(In, Out);
        break;
    case CAL_FEATURE_CAMERA_WB:
        ErrCode = GC0329Wb(In, Out);
        break;
    case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
        ErrCode = GC0329Effect(In, Out);
        break;
    case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
        ErrCode = GC0329StillCaptureSize(In, Out);
        break;
    case CAL_FEATURE_CAMERA_BANDING_FREQ:
        ErrCode = GC0329Banding(In, Out);
        break;
    case CAL_FEATURE_CAMERA_SCENE_MODE:
        ErrCode = GC0329SceneMode(KAL_TRUE, In, Out);
        break;
    case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
        ErrCode = GC0329SceneMode(KAL_FALSE, In, Out);
        break;
    case CAL_FEATURE_CAMERA_FLASH_MODE:
    case CAL_FEATURE_CAMERA_HUE:
    case CAL_FEATURE_CAMERA_GAMMA:
        ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        break;

    /* get info series */
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
        GC0329GetSensorInfo(Out);
        break;
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
        ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = GC0329DetectSensorId();
        break;
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
        ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = \
        GC0329Sensor.InternalClock * GC0329_FPS(1) / (GC0329Sensor.LineLength * GC0329Sensor.FrameLength);
        break;
    case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
        GC0329InitOperationPara(Out);
        break;
    case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
        CamGetHWInfo(GC0329Sensor.SensorIdx, Out);
        break;

    /* set para series */
    case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
        GC0329PowerDown();
        break;
    case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
        GC0329Sensor.NvramData = &(((nvram_camera_para_struct *)In)->SENSOR);
        break;
    case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
        GC0329Sensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
        break;
    case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
        break;
    case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
        GC0329Sensor.BypassAe = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
        GC0329AeEnable(GC0329Sensor.BypassAe ? KAL_FALSE : KAL_TRUE);
        break;
    case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
        GC0329Sensor.BypassAwb = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
        GC0329AwbEnable(GC0329Sensor.BypassAwb ? KAL_FALSE : KAL_TRUE);
        break;
    default:
        ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        break;
    }
    return ErrCode;
}

/*************************************************************************
* FUNCTION
*   GC0329SensorCtrl
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
static MM_ERROR_CODE_ENUM GC0329SensorCtrl(CAL_SCENARIO_ENUM Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
    switch (Id)
    {
    case CAL_SCENARIO_CAMERA_PREVIEW:
    case CAL_SCENARIO_VIDEO:
    case CAL_SCENARIO_WEBCAM_PREVIEW:
    case CAL_SCENARIO_WEBCAM_CAPTURE:
        GC0329Preview(Id, In, Out);
        break;
    case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
        GC0329Capture(Id, In, Out);
        break;
    default:
        break;
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC0329SensorClose
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
static MM_ERROR_CODE_ENUM GC0329SensorClose(void)
{
    GC0329PowerDown();
    CisModulePowerOn(GC0329Sensor.SensorIdx, KAL_FALSE);
    CameraSccbClose(CAMERA_SCCB_SENSOR);
  
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   GC0329SensorFunc
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
MM_ERROR_CODE_ENUM GC0329SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
    static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncGC0329 =
    {
        GC0329SensorOpen,
        GC0329SensorFeatureCtrl,
        GC0329SensorCtrl,
        GC0329SensorClose,
    };

    *pfSensorFunc = &ImageSensorFuncGC0329;
  
    return MM_ERROR_NONE;
}

#ifdef __GC0329_DEBUG_TRACE__
static kal_bool GC0329AtGetValue(char *Str, kal_uint32 *Data)
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

    if (!GC0329AtGetValue(Str, Data))
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

            GC0329_TRACE("Current Frame Rate: %d.%d fps", IspCurrentFrameRate / 10, IspCurrentFrameRate % 10);
        }
        break;
    case 0x02:
        GC0329_TRACE("Read BB Reg[%x] = %x", Data[2], DRV_Reg32(Data[2]));
        break;
    case 0x03:
        DRV_Reg32(Data[2]) = Data[3];
        GC0329_TRACE("Write BB Reg[%x] = %x", Data[2], DRV_Reg32(Data[2]));
        break;
    case 0x04:
        GC0329_TRACE("Read Sensor Reg[%x] = %x", Data[2], CamReadCmosSensor(Data[2]));
        break;
    case 0x05:
        CamWriteCmosSensor(Data[2], Data[3]);
        GC0329_TRACE("Write Sensor Reg[%x] = %x", Data[2], CamReadCmosSensor(Data[2]));
        break;
    case 0x06:
        CamWriteCmosSensor(Data[2], Data[3]);
        GC0329_TRACE("Read Sensor Reg[%x:%x] = %x", Data[3], Data[4], CamReadCmosSensor(Data[4]));
        break;
    case 0x07:
        CamWriteCmosSensor(Data[2], Data[3]);
        CamWriteCmosSensor(Data[4], Data[5]);
        CamWriteCmosSensor(Data[2], Data[3]);
        GC0329_TRACE("Write Sensor Reg[%x:%x] = %x", Data[3], Data[4], CamReadCmosSensor(Data[4]));
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
                GC0329_TRACE("Read Sensor Reg[%x] = %x", Data[2] + i, CamReadCmosSensor(Data[2] + i));
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
                GC0329_TRACE("Read BB Reg[%x] = %x", Data[2] + i * 4, DRV_Reg32(Data[2] + i * 4));
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

