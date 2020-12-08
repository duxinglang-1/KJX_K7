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
 *   image_sensor_OV2655.c
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
//#define OV2655_DEBUG_TRACE

#ifdef OV2655_LOAD_FROM_T_FLASH
#include "med_utility.h"
#include "fs_type.h"
#endif

extern kal_uint16 OV2655_read_shutter(void);
extern kal_uint16 OV2655_read_OV2655_gain(void);

#ifdef OV2655_LOAD_FROM_T_FLASH

    typedef struct
    {
        kal_uint16 init_reg;
        kal_uint8  init_val;    /* Save the register value and delay tick */
        kal_uint8   op_code;        /* 0 - Initial value, 1 - Register, 2 - Delay, 3 - End of setting. */
    } OV2655_initial_set_struct;

    #define OV2655_REG_SKIP     0x08
    #define OV2655_VAL_SKIP     0x06
    /* 0 - Initial value, 1 - Register, 2 - Delay, 3 - End of setting. */
    #define OV2655_OP_CODE_INI      0x00        /* Initial value. */
    #define OV2655_OP_CODE_REG      0x01        /* Register */
    #define OV2655_OP_CODE_DLY      0x02        /* Delay */
    #define OV2655_OP_CODE_END      0x03        /* End of initial setting. */

    OV2655_initial_set_struct OV2655_Init_Reg[4000];
    kal_uint8 temp_data_buff[40000];
    WCHAR OV2655_set_file_name[256] = {0};

#endif


static struct
{
    kal_uint8 Wb;
    kal_uint8 Ev;
    kal_uint8 Effect;
    kal_uint8 Mirror;
    kal_uint8 Banding;
    kal_bool NightMode;
    kal_bool VideoMode;
    kal_bool BypassAe;
    kal_bool BypassAwb;
    kal_uint16 Fps;
    kal_uint32 Pclk;
    kal_uint16 DummyPixel; /* for user customization */
    kal_uint16 Hblank; /* for calculating shutter step */
    //kal_uint16 ShutterStep;
    kal_bool OutTestPattern;      /* It can used to verify the HW. */

    IMAGE_SENSOR_INDEX_ENUM SensorIdx;
    sensor_data_struct *NvramData;
} OV2655Sensor;

#define OV2655_LIMIT_EXPOSURE_LINES             (1253)
/* Global Valuable */
CAL_SCENARIO_ENUM OV2655CurrScenario = CAL_SCENARIO_CAMERA_PREVIEW;
IMAGE_SENSOR_INDEX_ENUM SensorIdxOV2655;

//static kal_uint32 zoom_factor = 0;
static kal_uint8 OV2655_exposure_line_h = 0, OV2655_exposure_line_l = 0, OV2655_extra_exposure_line_h = 0, OV2655_extra_exposure_line_l = 0;

static kal_bool OV2655_gPVmode = KAL_TRUE; //PV size or Full size
//static kal_bool OV2655_VEDIO_encode_mode = KAL_FALSE; //Picture(Jpeg) or Video(Mpeg4)
static kal_bool OV2655_sensor_cap_state = KAL_FALSE; //Preview or Capture

static kal_uint16 OV2655_dummy_pixels=0, OV2655_dummy_lines=0;

static kal_uint16 OV2655_exposure_lines=0, OV2655_extra_exposure_lines = 0;


//static kal_int8 OV2655_DELAY_AFTER_PREVIEW = -1;
/****** OVT 6-18******/
static kal_uint16 OV2655_Capture_Max_Gain16= 6*16;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

static kal_uint16  OV2655_PV_Dummy_Pixels =0, OV2655_Capture_Dummy_Pixels =0, OV2655_Capture_Dummy_Lines =0;
static kal_uint16  OV2655_PV_Gain16 = 0;
static kal_uint16  OV2655_PV_Shutter = 0;
static kal_uint16  OV2655_PV_Extra_Lines = 0;

kal_uint16 OV2655_sensor_gain_base=0,OV2655_FAC_SENSOR_REG=0,OV2655_iOV2655_Mode=0,OV2655_max_exposure_lines=0;
kal_uint32 OV2655_capture_pclk_in_M=360,OV2655_preview_pclk_in_M=360,OV2655_PV_dummy_pixels=0,OV2655_PV_Dummy_Lines=0,OV2655_isp_master_clock=0;


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
static const unsigned char CATSTestPattern[] = { 
    0x80, 0xfc, 0x80, 0xfc, 0x17, 0xea, 0x8b, 0xe0, 0x94, 0xc3, 0x14, 0xb8, 0x10, 0x99, 0x00, 0x92,
    0xf0, 0x7c, 0xf0, 0x7a, 0x58, 0x54, 0xfa, 0x51, 0xf4, 0x2c, 0x71, 0x25, 0x80, 0x06, 0x80, 0x06,
    0x80, 0xfc, 0x80, 0xfc, 0x17, 0xea, 0x8b, 0xe0, 0x94, 0xc3, 0x14, 0xb8, 0x10, 0x99, 0x00, 0x92,
    0xf0, 0x7c, 0xf0, 0x7a, 0x58, 0x54, 0xfa, 0x51, 0xf4, 0x2c, 0x71, 0x25, 0x80, 0x06, 0x80, 0x06,
    0x80, 0xfc, 0x80, 0xfc, 0x17, 0xea, 0x8b, 0xe0, 0x94, 0xc3, 0x14, 0xb8, 0x10, 0x99, 0x00, 0x92,
    0xf0, 0x7c, 0xf0, 0x7a, 0x58, 0x54, 0xfa, 0x51, 0xf4, 0x2c, 0x71, 0x25, 0x80, 0x06, 0x80, 0x06,
    0x80, 0xfc, 0x80, 0xfc, 0x17, 0xea, 0x8b, 0xe0, 0x94, 0xc3, 0x14, 0xb8, 0x10, 0x99, 0x00, 0x92,
    0xf0, 0x7c, 0xf0, 0x7a, 0x58, 0x54, 0xfa, 0x51, 0xf4, 0x2c, 0x71, 0x25, 0x80, 0x06, 0x80, 0x06,
    0x80, 0xfc, 0x80, 0xfc, 0x17, 0xea, 0x8b, 0xe0, 0x94, 0xc3, 0x14, 0xb8, 0x10, 0x99, 0x00, 0x92,
    0xf0, 0x7c, 0xf0, 0x7a, 0x58, 0x54, 0xfa, 0x51, 0xf4, 0x2c, 0x71, 0x25, 0x80, 0x06, 0x80, 0x06,
    0x80, 0xfc, 0x80, 0xfc, 0x17, 0xea, 0x8b, 0xe0, 0x94, 0xc3, 0x14, 0xb8, 0x10, 0x99, 0x00, 0x92,
    0xf0, 0x7c, 0xf0, 0x7a, 0x58, 0x54, 0xfa, 0x51, 0xf4, 0x2c, 0x71, 0x25, 0x80, 0x06, 0x80, 0x06,
    0x80, 0xfc, 0x80, 0xfc, 0x17, 0xea, 0x8b, 0xe0, 0x94, 0xc3, 0x14, 0xb8, 0x10, 0x99, 0x00, 0x92,
    0xf0, 0x7c, 0xf0, 0x7a, 0x58, 0x54, 0xfa, 0x51, 0xf4, 0x2c, 0x71, 0x25, 0x80, 0x06, 0x80, 0x06,
    0x80, 0xfc, 0x80, 0xfc, 0x17, 0xea, 0x8b, 0xe0, 0x94, 0xc3, 0x14, 0xb8, 0x10, 0x99, 0x00, 0x92,
    0xf0, 0x7c, 0xf0, 0x7a, 0x58, 0x54, 0xfa, 0x51, 0xf4, 0x2c, 0x71, 0x25, 0x80, 0x06, 0x80, 0x06,
    0x80, 0xfc, 0x80, 0xfc, 0x17, 0xea, 0x8b, 0xe0, 0x94, 0xc3, 0x14, 0xb8, 0x10, 0x99, 0x00, 0x92,
    0xf0, 0x7c, 0xf0, 0x7a, 0x58, 0x54, 0xfa, 0x51, 0xf4, 0x2c, 0x71, 0x25, 0x80, 0x06, 0x80, 0x06,
    0x80, 0xfc, 0x80, 0xfc, 0x17, 0xea, 0x8b, 0xe0, 0x94, 0xc3, 0x14, 0xb8, 0x10, 0x99, 0x00, 0x92,
    0xf0, 0x7c, 0xf0, 0x7a, 0x58, 0x54, 0xfa, 0x51, 0xf4, 0x2c, 0x71, 0x25, 0x80, 0x06, 0x80, 0x06,
    0x80, 0xfc, 0x80, 0xfc, 0x17, 0xea, 0x8b, 0xe0, 0x94, 0xc3, 0x14, 0xb8, 0x10, 0x99, 0x00, 0x92,
    0xf0, 0x7c, 0xf0, 0x7a, 0x58, 0x54, 0xfa, 0x51, 0xf4, 0x2c, 0x71, 0x25, 0x80, 0x06, 0x80, 0x06,
    0x80, 0xfc, 0x80, 0xfc, 0x17, 0xea, 0x8b, 0xe0, 0x94, 0xc3, 0x14, 0xb8, 0x10, 0x99, 0x00, 0x92,
    0xf0, 0x7c, 0xf0, 0x7a, 0x58, 0x54, 0xfa, 0x51, 0xf4, 0x2c, 0x71, 0x25, 0x80, 0x06, 0x80, 0x06
};
#endif

#ifdef OV2655_LOAD_FROM_T_FLASH

static kal_uint8 OV2655LensSettingFromTFlash()
{
    FS_HANDLE fp = -1;              /* Default, no file opened. */
    kal_uint8 *data_buff = NULL;
    kal_uint8 *curr_ptr = NULL;
    kal_uint32 file_size = 0;
    kal_uint32 bytes_read = 0;
    kal_uint32 i = 0, j = 0;
    kal_uint8 func_ind[3] = {0};    /* REG or DLY */
    kal_uint32 writepara;

    kal_mem_cpy(OV2655_set_file_name, L"C:\\OV2655_Preview_Setting.Bin", sizeof(L"C:\\OV2655_Preview_Setting.Bin"));

    /* Search the setting file in all of the user disk. */
    curr_ptr = (kal_uint8 *)OV2655_set_file_name;
    while (fp < 0)
    {
        if ((*curr_ptr >= 'c' && *curr_ptr <= 'z') || (*curr_ptr >= 'C' && *curr_ptr <= 'Z'))
        {
            fp = FS_Open(OV2655_set_file_name, FS_READ_ONLY);
            if (fp >= 0)
            {
                break;          /* Find the setting file. */
            }

            *curr_ptr = *curr_ptr + 1;
        }
        else
        {
            break ;
        }
    }


    if (fp < 0)     /* Error handle */
    {
#ifdef __OV2655_DEBUG_TRACE__
        kal_wap_trace(MOD_ENG, TRACE_INFO, "!!! Warning, Can't find the initial setting file!!!");
#endif

        return 0;
    }

    FS_GetFileSize(fp, &file_size);
    if (file_size < 20)
    {
#ifdef __OV2655_DEBUG_TRACE__
        kal_wap_trace(MOD_ENG, TRACE_INFO, "!!! Warning, Invalid setting file!!!");
#endif

        return 0;           /* Invalid setting file. */
    }

    //data_buff =(kal_uint8*) med_alloc_ext_mem(file_size);
    data_buff =temp_data_buff;
    if (data_buff == NULL)
    {
#ifdef __OV2655_DEBUG_TRACE__
        kal_wap_trace(MOD_ENG, TRACE_INFO, "!!! Warning, Memory not enoughed...");
#endif

        return 0;               /* Memory not enough */
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
                curr_ptr++;     /* Skip block comment code. */
            }

            while (!((*curr_ptr == 0x0D) && (*(curr_ptr+1) == 0x0A)))
            {
                curr_ptr++;
            }

            curr_ptr += 2;                      /* Skip the enter line */

            continue ;
        }

        if (((*curr_ptr) == '/') || ((*curr_ptr) == '{') || ((*curr_ptr) == '}'))       /* Comment line, skip it. */
        {
            while (!((*curr_ptr == 0x0D) && (*(curr_ptr+1) == 0x0A)))
            {
                curr_ptr++;
            }

            curr_ptr += 2;                      /* Skip the enter line */

            continue ;
        }
        /* This just content one enter line. */
        if (((*curr_ptr) == 0x0D) && ((*(curr_ptr + 1)) == 0x0A))
        {
            curr_ptr += 2;
            continue ;
        }

        kal_mem_cpy(func_ind, curr_ptr, 3);
        curr_ptr += 4;                  /* Skip "REG(" or "DLY(" */
        if (strcmp((const char *)func_ind, "REG") == 0)     /* REG */
        {
            OV2655_Init_Reg[i].op_code = OV2655_OP_CODE_REG;

            OV2655_Init_Reg[i].init_reg = strtol((const char *)curr_ptr, NULL, 16);
            curr_ptr += OV2655_REG_SKIP;    /* Skip "0x0000, " */

            OV2655_Init_Reg[i].init_val = strtol((const char *)curr_ptr, NULL, 16);
            curr_ptr += OV2655_VAL_SKIP;    /* Skip "0x0000);" */
        }
        else                                    /* DLY */
        {
            /* Need add delay for this setting. */
            OV2655_Init_Reg[i].op_code = OV2655_OP_CODE_DLY;

            OV2655_Init_Reg[i].init_reg = 0xFF;
            OV2655_Init_Reg[i].init_val = strtol((const char *)curr_ptr, NULL, 10); /* Get the delay ticks, the delay should less then 50 */
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
    OV2655_Init_Reg[i].op_code = OV2655_OP_CODE_END;
    OV2655_Init_Reg[i].init_reg = 0xFF;
    OV2655_Init_Reg[i].init_val = 0xFF;
    i++;

#ifdef __OV2655_DEBUG_TRACE__
    kal_wap_trace(MOD_ENG, TRACE_INFO, "%d register read...", i-1);
#endif

    //med_free_ext_mem((void **)&data_buff);
    FS_Close(fp);

#ifdef __OV2655_DEBUG_TRACE__
    kal_wap_trace(MOD_ENG, TRACE_INFO, "Start apply initialize setting.");
#endif
    /* Start apply the initial setting to sensor. */
    for (j=0; j<i; j++)
    {
        if (OV2655_Init_Reg[j].op_code == OV2655_OP_CODE_END) /* End of the setting. */
        {
            break ;
        }
        else if (OV2655_Init_Reg[j].op_code == OV2655_OP_CODE_DLY)
        {
            kal_sleep_task(OV2655_Init_Reg[j].init_val);        /* Delay */
        }
        else if (OV2655_Init_Reg[j].op_code == OV2655_OP_CODE_REG)
        {
            CamWriteCmosSensor8(OV2655_Init_Reg[j].init_reg, OV2655_Init_Reg[j].init_val);
            kal_wap_trace(MOD_ENG, TRACE_INFO, "%d :%d",OV2655_Init_Reg[j].init_reg,OV2655_Init_Reg[j].init_val );
        }
        else
        {
            ASSERT(0);
        }
    }

#ifdef __OV2655_DEBUG_TRACE__
    kal_wap_trace(MOD_ENG, TRACE_INFO, "%d register applied...", j);
#endif

    return 1;
}

#endif


/*************************************************************************
* FUNCTION
*    OV2655InitialSetting
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
static void OV2655InitialSetting(void)
{
    //CamWriteCmosSensor(0x3012, 0x80);
     //IO & Clock & Analog Setup
    CamWriteCmosSensor(0x308c,0x80); //TMC12: DIS_MIPI_RW
    CamWriteCmosSensor(0x308d,0x0e); //TMC13: MIPI disable
    CamWriteCmosSensor(0x360b,0x00);
    CamWriteCmosSensor(0x30b0,0xff); //IO_CTRL0: Cy[7:0]
    CamWriteCmosSensor(0x30b1,0xff); //IO_CTRL1: C_VSYNC,C_STROBE,C_PCLK,C_HREF,Cy[9:8]
    CamWriteCmosSensor(0x30b2, 0x24);

    CamWriteCmosSensor(0x3085,0x20); // Add

    CamWriteCmosSensor(0x300e,0x34);
    CamWriteCmosSensor(0x300f,0xa6);
    CamWriteCmosSensor(0x3010,0x81);
    CamWriteCmosSensor(0x3082,0x01);
    CamWriteCmosSensor(0x30f4,0x01);
    CamWriteCmosSensor(0x3091,0xc0);
    CamWriteCmosSensor(0x30ac,0x42);

    CamWriteCmosSensor(0x30d1,0x08);
    CamWriteCmosSensor(0x30a8, 0x56);
    CamWriteCmosSensor(0x3093,0x00);
    CamWriteCmosSensor(0x307e,0xe5); //TMC8: AGC[7:6]=b'11
    CamWriteCmosSensor(0x3079,0x00);
    CamWriteCmosSensor(0x30aa,0x42); // Add
    CamWriteCmosSensor(0x3017,0x40); //AUTO_5: disable data drop, manual banding counter=0
    CamWriteCmosSensor(0x30f3,0x82);
    CamWriteCmosSensor(0x306a,0x0c); //0x0c->0x0f Joe 0814 : BLC
    CamWriteCmosSensor(0x306d,0x00);
    CamWriteCmosSensor(0x336a,0x3c);
    CamWriteCmosSensor(0x3076,0x6a); //TMC0: VSYNC drop option: drop
    CamWriteCmosSensor(0x30d9,0x95);
    CamWriteCmosSensor(0x3016,0x82); //Add
    CamWriteCmosSensor(0x3601, 0x30);
    CamWriteCmosSensor(0x304e,0x88);
    CamWriteCmosSensor(0x30f1,0x82);
    CamWriteCmosSensor(0x306f,0x14);
    CamWriteCmosSensor(0x3012,0x10);
    CamWriteCmosSensor(0x3011,0x00); // Add
    CamWriteCmosSensor(0x302A, 0x02);
    CamWriteCmosSensor(0x302B, 0x6a);
    CamWriteCmosSensor(0x3028,0x07); // Add
    CamWriteCmosSensor(0x3029,0x93); // Add

    CamWriteCmosSensor(0x3391,0x06); // Add
    CamWriteCmosSensor(0x3394,0x48); // Add
    CamWriteCmosSensor(0x3395,0x48); // Add

    //AEC/AGC
    CamWriteCmosSensor(0x3013,0xf7);
    CamWriteCmosSensor(0x3018, 0x80);// 80
    CamWriteCmosSensor(0x3019, 0x70);// 70
    //CamWriteCmosSensor(0x301a, 0xd4); // AE Step, high/low threshold
    CamWriteCmosSensor(0x301a, 0xc4);// b4

    //D5060
    CamWriteCmosSensor(0x30af,0x00); //0x10 // Modify
    CamWriteCmosSensor(0x3048,0x1f); // Add
    CamWriteCmosSensor(0x3049,0x4e); // Add
    CamWriteCmosSensor(0x304a,0x20); // Add
    CamWriteCmosSensor(0x304f,0x20); // Add
    CamWriteCmosSensor(0x304b,0x02); // Add
    CamWriteCmosSensor(0x304c,0x00); // Add
    CamWriteCmosSensor(0x304d,0x02); // Add
    CamWriteCmosSensor(0x304f,0x20); // Add
    CamWriteCmosSensor(0x30a3,0x10); // Add
    CamWriteCmosSensor(0x3013,0xf7); // Add
    CamWriteCmosSensor(0x3071,0x00); // Add
    CamWriteCmosSensor(0x3070, 0xb9);
    CamWriteCmosSensor(0x3073,0x00);
    CamWriteCmosSensor(0x3072, 0x9a);
    CamWriteCmosSensor(0x301c,0x03); // Add
    CamWriteCmosSensor(0x301d,0x04); // Add
    CamWriteCmosSensor(0x304d,0x42);
    CamWriteCmosSensor(0x304a,0x40); // Add
    CamWriteCmosSensor(0x304f,0x40); // Add
    CamWriteCmosSensor(0x3095,0x07);
    CamWriteCmosSensor(0x3096,0x16);
    CamWriteCmosSensor(0x3097,0x1d);

    //Window Setup
    CamWriteCmosSensor(0x3020,0x01);
    CamWriteCmosSensor(0x3021,0x1a); // 0x18
    CamWriteCmosSensor(0x3022,0x00);
    CamWriteCmosSensor(0x3023,0x06);
    CamWriteCmosSensor(0x3024,0x06);
    CamWriteCmosSensor(0x3025,0x58);
    CamWriteCmosSensor(0x3026,0x02);
    CamWriteCmosSensor(0x3027,0x5e);
    CamWriteCmosSensor(0x3088,0x03);
    CamWriteCmosSensor(0x3089,0x20);
    CamWriteCmosSensor(0x308a,0x02);
    CamWriteCmosSensor(0x308b,0x58);
    CamWriteCmosSensor(0x3316,0x64);
    CamWriteCmosSensor(0x3317,0x25);
    CamWriteCmosSensor(0x3318,0x80);
    CamWriteCmosSensor(0x3319,0x08);
    CamWriteCmosSensor(0x331a,0x64);
    CamWriteCmosSensor(0x331b,0x4b);
    CamWriteCmosSensor(0x331c,0x00);
    CamWriteCmosSensor(0x331d,0x38);
    CamWriteCmosSensor(0x3100,0x00);

    //AWB
    CamWriteCmosSensor(0x3320,0xfa);   //Jerry 0x9a
    CamWriteCmosSensor(0x3321,0x11);
    CamWriteCmosSensor(0x3322,0x92);
    CamWriteCmosSensor(0x3323,0x01);
    CamWriteCmosSensor(0x3324,0x97);   //Jerry 0x92
    CamWriteCmosSensor(0x3325,0x02);
    CamWriteCmosSensor(0x3326,0xff);
    CamWriteCmosSensor(0x3327,0x10);   //0x0c
    CamWriteCmosSensor(0x3328, 0x18);
    CamWriteCmosSensor(0x3329, 0x1f);
    CamWriteCmosSensor(0x332a, 0x56);
    CamWriteCmosSensor(0x332b, 0x54);
    CamWriteCmosSensor(0x332c,0xbe);   //a5 -> 89    //Jerry 0x89
    CamWriteCmosSensor(0x332d, 0xce);
    CamWriteCmosSensor(0x332e, 0x2e);
    CamWriteCmosSensor(0x332f, 0x28);
    CamWriteCmosSensor(0x3330, 0x4d);
    CamWriteCmosSensor(0x3331,0x44);   //Jerry 0x3d
    CamWriteCmosSensor(0x3332,0xf0);
    CamWriteCmosSensor(0x3333, 0x0a);
    CamWriteCmosSensor(0x3334,0xf0);
    CamWriteCmosSensor(0x3335,0xf0);
    CamWriteCmosSensor(0x3336,0xf0);
    CamWriteCmosSensor(0x3337,0x40);
    CamWriteCmosSensor(0x3338,0x40);
    CamWriteCmosSensor(0x3339,0x40);
    CamWriteCmosSensor(0x333a,0x00);
    CamWriteCmosSensor(0x333b,0x00);

    //Color Matrix
    CamWriteCmosSensor(0x3380, 0x28);
    CamWriteCmosSensor(0x3381, 0x48);
    CamWriteCmosSensor(0x3382, 0x14);
    CamWriteCmosSensor(0x3383, 0x17);
    CamWriteCmosSensor(0x3384, 0x90);
    CamWriteCmosSensor(0x3385, 0xa7);
    CamWriteCmosSensor(0x3386,0xbf);
    CamWriteCmosSensor(0x3387, 0xb7);
    CamWriteCmosSensor(0x3388, 0x08);
    CamWriteCmosSensor(0x3389,0x98);
    CamWriteCmosSensor(0x338a,0x01);

    //Gamma
    CamWriteCmosSensor(0x3340, 0x06);
    CamWriteCmosSensor(0x3341, 0x0c);
    CamWriteCmosSensor(0x3342, 0x19);
    CamWriteCmosSensor(0x3343, 0x34);
    CamWriteCmosSensor(0x3344, 0x4e);
    CamWriteCmosSensor(0x3345, 0x5f);
    CamWriteCmosSensor(0x3346, 0x6d);
    CamWriteCmosSensor(0x3347, 0x78);
    CamWriteCmosSensor(0x3348, 0x84);
    CamWriteCmosSensor(0x3349, 0x95);
    CamWriteCmosSensor(0x334a, 0xa5);
    CamWriteCmosSensor(0x334b, 0xb4);
    CamWriteCmosSensor(0x334c, 0xcc);
    CamWriteCmosSensor(0x334d, 0xe2);
    CamWriteCmosSensor(0x334e, 0xf6);
    CamWriteCmosSensor(0x334f, 0x11);


    //CWF
    CamWriteCmosSensor(0x307c, 0x10);//no flip&mirror
    CamWriteCmosSensor(0x3090, 0x33);

    #ifdef OV2655_LOAD_FROM_T_FLASH
    if (OV2655LensSettingFromTFlash())      /* For debug use. */
    {
        /* If load from t-flash success, then do nothing. */
    }
    else    /* Failed, load from the image load. */
    #endif
    {
    //R
    CamWriteCmosSensor(0x3350, 0x33);
    CamWriteCmosSensor(0x3351, 0x27);
    CamWriteCmosSensor(0x3352, 0x00);
    CamWriteCmosSensor(0x3353, 0x39);//0x3c
    CamWriteCmosSensor(0x3354,0x00);
    CamWriteCmosSensor(0x3355,0x85);
    //G
    CamWriteCmosSensor(0x3356,0x34);
    CamWriteCmosSensor(0x3357, 0x27);
    CamWriteCmosSensor(0x3358, 0x00);
    CamWriteCmosSensor(0x3359, 0x36);
    CamWriteCmosSensor(0x335a,0x00);
    CamWriteCmosSensor(0x335b,0x85);
    //B
    CamWriteCmosSensor(0x335c, 0x34);
    CamWriteCmosSensor(0x335d, 0x27);
    CamWriteCmosSensor(0x335e, 0x00);
    CamWriteCmosSensor(0x335f, 0x31);
    CamWriteCmosSensor(0x3360,0x00);
    CamWriteCmosSensor(0x3361,0x85);

    CamWriteCmosSensor(0x3363, 0x70);
    CamWriteCmosSensor(0x3364, 0x7f);
    CamWriteCmosSensor(0x3365, 0x00);
    CamWriteCmosSensor(0x3366,0x00);
    }
    /*CamWriteCmosSensor(0x307c, 0x13);// flip&mirror
       CamWriteCmosSensor(0x3090, 0x3b);
    CamWriteCmosSensor(0x3350, 0x33);
    CamWriteCmosSensor(0x3351, 0x27);
    CamWriteCmosSensor(0x3352, 0x00);
    CamWriteCmosSensor(0x3353, 0x3c);
    CamWriteCmosSensor(0x3354, 0x00);
    CamWriteCmosSensor(0x3355, 0x85);
    CamWriteCmosSensor(0x3356, 0x32);
    CamWriteCmosSensor(0x3357, 0x27);
    CamWriteCmosSensor(0x3358, 0x00);
    CamWriteCmosSensor(0x3359, 0x34);
    CamWriteCmosSensor(0x335a, 0x00);
    CamWriteCmosSensor(0x335b, 0x85);
    CamWriteCmosSensor(0x335c, 0x33);
    CamWriteCmosSensor(0x335d, 0x29);
    CamWriteCmosSensor(0x335e, 0x00);
    CamWriteCmosSensor(0x335f, 0x31);
    CamWriteCmosSensor(0x3360, 0x00);
    CamWriteCmosSensor(0x3361, 0x85);
    CamWriteCmosSensor(0x3363, 0x70);
    CamWriteCmosSensor(0x3364, 0x7f);
    CamWriteCmosSensor(0x3365, 0x00);
    CamWriteCmosSensor(0x3366, 0x00);*/

    CamWriteCmosSensor(0x3362,0x90); // Add
    CamWriteCmosSensor(0x3301,0xff); // Add

    //UVadjust
    CamWriteCmosSensor(0x338B, 0x13);
    CamWriteCmosSensor(0x338c,0x10);
    CamWriteCmosSensor(0x338d, 0x40);

    //Sharpness/De-noise
    CamWriteCmosSensor(0x3370,0xd0);
    CamWriteCmosSensor(0x3371,0x00);
    CamWriteCmosSensor(0x3372,0x00);
    CamWriteCmosSensor(0x3373, 0x50);
    CamWriteCmosSensor(0x3374,0x10);
    CamWriteCmosSensor(0x3375,0x10);
    CamWriteCmosSensor(0x3376, 0x08);
    CamWriteCmosSensor(0x3377,0x00);
    CamWriteCmosSensor(0x3378,0x04);
    CamWriteCmosSensor(0x3379, 0x80);

    //BLC
    CamWriteCmosSensor(0x3069, 0x86);
    CamWriteCmosSensor(0x3087,0x02);

    //Other functions
    CamWriteCmosSensor(0x3300,0xfc);
    CamWriteCmosSensor(0x3302,0x11);
    CamWriteCmosSensor(0x3400,0x00);
    CamWriteCmosSensor(0x3600,0x00); // Add
    CamWriteCmosSensor(0x3606,0x20);
    CamWriteCmosSensor(0x3601,0x32); /*[Hesong 0303] ,[bit1] 1:output DVP_DATA[7:0], 0:output DVP_DATA[9:2]  */
    CamWriteCmosSensor(0x30f3,0x83);
    CamWriteCmosSensor(0x304e,0x88);


    CamWriteCmosSensor(0x30a8, 0x54); //0x56   Wonder for Sun black
    CamWriteCmosSensor(0x30aa, 0x82);
    CamWriteCmosSensor(0x30a3, 0x91);
    CamWriteCmosSensor(0x30a1, 0x41);
    CamWriteCmosSensor(0x3014, 0x8c);
    CamWriteCmosSensor(0x3015, 0x32);
    CamWriteCmosSensor(0x302d, 0x00);
    CamWriteCmosSensor(0x302e, 0x00);

    CamWriteCmosSensor(0x3086, 0x0f);
    CamWriteCmosSensor(0x3086, 0x00);
    //Wonder add for close Mipi Interface
    CamWriteCmosSensor(0x363B,0x01);
    CamWriteCmosSensor(0x363C,0xF2);


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
#endif

static void OV2655WriteShutter(kal_uint16 shutter)
{
    if (OV2655_gPVmode)
    {
        if (shutter <= OV2655_PV_EXPOSURE_LIMITATION)
        {
            OV2655_extra_exposure_lines = 0;
        }
        else
        {
            OV2655_extra_exposure_lines=shutter - OV2655_PV_EXPOSURE_LIMITATION;
        }

        if (shutter > OV2655_PV_EXPOSURE_LIMITATION)
        {
            shutter = OV2655_PV_EXPOSURE_LIMITATION;
        }
    }
    else
    {
        if (shutter <= OV2655_FULL_EXPOSURE_LIMITATION)
        {
            OV2655_extra_exposure_lines = 0;
        }
        else
        {
            OV2655_extra_exposure_lines = shutter - OV2655_FULL_EXPOSURE_LIMITATION;
        }

        if (shutter > OV2655_FULL_EXPOSURE_LIMITATION) 
        {
            shutter = OV2655_FULL_EXPOSURE_LIMITATION;
        }
    }

    // set extra exposure line
    CamWriteCmosSensor(0x302E, OV2655_extra_exposure_lines & 0xFF);          // EXVTS[b7~b0]
    CamWriteCmosSensor(0x302D, (OV2655_extra_exposure_lines & 0xFF00) >> 8); // EXVTS[b15~b8]

    /* Max exporsure time is 1 frmae period event if Tex is set longer than 1 frame period */
    CamWriteCmosSensor(0x3003, shutter & 0xFF);           //AEC[7:0]
    CamWriteCmosSensor(0x3002, (shutter & 0xFF00) >> 8);  //AEC[8:15]

}    /* OV2655_write_shutter */
static void OV2655SetDummy(kal_uint16 pixels, kal_uint16 lines)
{
    kal_uint8 temp_reg1, temp_reg2;
    kal_uint16 temp_reg;

    /*Very Important: The line_length must < 0x1000, it is to say 0x3028 must < 0x10, or else the sensor will crash*/
    /*The dummy_pixel must < 2156*/
    if (pixels >= 2156)
        pixels = 2155;
    if (pixels < 0x100)
    {
        CamWriteCmosSensor(0x302c,(pixels&0xFF)); //EXHTS[7:0]
        temp_reg = OV2655_FULL_PERIOD_PIXEL_NUMS;
        CamWriteCmosSensor(0x3029,(temp_reg&0xFF));         //H_length[7:0]
        CamWriteCmosSensor(0x3028,((temp_reg&0xFF00)>>8));  //H_length[15:8]
    }
    else
    {
        CamWriteCmosSensor(0x302c,0);
        temp_reg = pixels + OV2655_FULL_PERIOD_PIXEL_NUMS;
        CamWriteCmosSensor(0x3029,(temp_reg&0xFF));         //H_length[7:0]
        CamWriteCmosSensor(0x3028,((temp_reg&0xFF00)>>8));  //H_length[15:8]
    }


    // read out and + line
    temp_reg1 = CamReadCmosSensor(0x302B);    // VTS[b7~b0]
    temp_reg2 = CamReadCmosSensor(0x302A);    // VTS[b15~b8]
    temp_reg = (temp_reg1 & 0xFF) | (temp_reg2 << 8);

    temp_reg += lines;

    CamWriteCmosSensor(0x302B,(temp_reg&0xFF));         //VTS[7:0]
    CamWriteCmosSensor(0x302A,((temp_reg&0xFF00)>>8));  //VTS[15:8]
}    /* OV2655_set_dummy */
static void OV2655SetVideoFrameRate(kal_uint16 FrameRate)
{
    /*The real frame rate need /10*/
    kal_uint16 frame_rate=OV2655Sensor.Fps;
    kal_uint16 line_length = OV2655_PV_PERIOD_PIXEL_NUMS;

    if (360 == OV2655_preview_pclk_in_M)
    {
    }
    else
    {
        CamWriteCmosSensor(0x3011, 0x00);
        OV2655_preview_pclk_in_M = 360;
    }


    if ((frame_rate > 300)||(frame_rate < 50))
    {
        //Frame Rate range check.
        #ifdef OV2655_DEBUG_TRACE
        kal_wap_trace(MOD_ENG,TRACE_INFO,"frame_rate:%d",frame_rate);
        #endif
    }
    else
    {
        line_length = OV2655_preview_pclk_in_M*100000*10/frame_rate/(OV2655_PV_PERIOD_LINE_NUMS + OV2655_PV_Dummy_Lines);

        // [Hesong]
        // Line_lenth must less than 0x1000, otherwise the sensor will crash.
        // video: min framerate=>10Fps, VGA size preview, dummy line = 0, line length = 5825 = 0x16C1

    if (line_length >= 0x3000) /*Because Line_lenth must less than 0x1000*/
    {
        CamWriteCmosSensor(0x3011, 0x03);
            OV2655_preview_pclk_in_M = 90;
        line_length = OV2655_preview_pclk_in_M*100000*10/frame_rate/(OV2655_PV_PERIOD_LINE_NUMS + OV2655_PV_Dummy_Lines);
    }
    else if (line_length >= 0x2000)
    {
        CamWriteCmosSensor(0x3011, 0x02);
            OV2655_preview_pclk_in_M = 120;
        line_length = OV2655_preview_pclk_in_M*100000*10/frame_rate/(OV2655_PV_PERIOD_LINE_NUMS + OV2655_PV_Dummy_Lines);
    }
    else if (line_length >= 0x1000)
    {
        CamWriteCmosSensor(0x3011, 0x01);
        OV2655_preview_pclk_in_M = 180;
        line_length = OV2655_preview_pclk_in_M*100000*10/frame_rate/(OV2655_PV_PERIOD_LINE_NUMS + OV2655_PV_Dummy_Lines);
    }
    }
    OV2655_PV_Dummy_Pixels = line_length - OV2655_FULL_PERIOD_PIXEL_NUMS;
    OV2655SetDummy(OV2655_PV_Dummy_Pixels, OV2655_PV_Dummy_Lines);
}
void OV2655_write_OV2655_gain(kal_uint16 gain)
{
    kal_uint16 temp_reg;

    if(gain > 248)  ASSERT(0);

    temp_reg = 0;
    if (gain > 31)
    {
        temp_reg |= 0x10;
        gain = gain >> 1;
    }
    if (gain > 31)
    {
        temp_reg |= 0x20;
        gain = gain >> 1;
    }

    if (gain > 31)
    {
        temp_reg |= 0x40;
        gain = gain >> 1;
    }
    if (gain > 31)
    {
        temp_reg |= 0x80;
        gain = gain >> 1;
    }

    if (gain > 16)
    {
        temp_reg |= ((gain -16) & 0x0f);
    }

    CamWriteCmosSensor(0x3000,temp_reg);
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

static void OV2655RollBackShutterGain(void)
{
    if (OV2655Sensor.BypassAe)
        return;

    CamWriteCmosSensor(0x3002, OV2655_exposure_line_h * 1); //090623
    CamWriteCmosSensor(0x3003, OV2655_exposure_line_l * 1);  //090623
    CamWriteCmosSensor(0x302D, OV2655_extra_exposure_line_h * 1); //090623
    CamWriteCmosSensor(0x302E, OV2655_extra_exposure_line_l * 1);  //090623

    OV2655_write_OV2655_gain(OV2655_PV_Gain16);

}

static void OV2655PVMode(void)
{

    OV2655RollBackShutterGain();
    OV2655_preview_pclk_in_M=360;

    CamWriteCmosSensor(0x3011, 0x00);

    //0x3011 = 0;
    //0x300e=0x34
    //YUV    //SVGA (800x600)
    // setup sensor output ROI
    #ifdef BANDING50_30HZ
       CamWriteCmosSensor(0x300e, 0x34);
    #else
    if (OV2655Sensor.Banding == CAM_BANDING_50HZ)
       CamWriteCmosSensor(0x300e, 0x36);
    else
       CamWriteCmosSensor(0x300e, 0x34);
    #endif
    CamWriteCmosSensor(0x300f, 0xa6);
    CamWriteCmosSensor(0x3012, 0x10);
    CamWriteCmosSensor(0x302a, 0x02);
    CamWriteCmosSensor(0x302b, 0x6a);
    CamWriteCmosSensor(0x306f, 0x14);
    CamWriteCmosSensor(0x3362, 0x90);

    CamWriteCmosSensor(0x3020, 0x01);
    CamWriteCmosSensor(0x3021, 0x1a);
    CamWriteCmosSensor(0x3022, 0x00);
    CamWriteCmosSensor(0x3023, 0x06);
    CamWriteCmosSensor(0x3024, 0x06);
    CamWriteCmosSensor(0x3025, 0x58);
    CamWriteCmosSensor(0x3026, 0x02);
    CamWriteCmosSensor(0x3027, 0x5e);
    CamWriteCmosSensor(0x3088, 0x03);
    CamWriteCmosSensor(0x3089, 0x20);
    CamWriteCmosSensor(0x308a, 0x02);
    CamWriteCmosSensor(0x308b, 0x58);

    CamWriteCmosSensor(0x3316, 0x64);
    CamWriteCmosSensor(0x3317, 0x25);
    CamWriteCmosSensor(0x3318, 0x80);
    CamWriteCmosSensor(0x3319, 0x08);
    CamWriteCmosSensor(0x331a, 0x64);
    CamWriteCmosSensor(0x331b, 0x4b);
    CamWriteCmosSensor(0x331c, 0x00);
    CamWriteCmosSensor(0x331d, 0x38);

    CamWriteCmosSensor(0x3302, 0x11);

    //0629, help with saturation, from OV
    //CamWriteCmosSensor(0x3391,0x02);
    //CamWriteCmosSensor(0x3394,0x44);
    //CamWriteCmosSensor(0x3395,0x44);


    //===preview setting end===
}
/*************************************************************************
* FUNCTION
*    OV2655SetShutterStep
*
* DESCRIPTION
*    This function is to calculate & set shutter step register .
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
static void OV2655SetBanding()
{
    kal_uint8 banding, base_shutter, banding_step;

    banding = CamReadCmosSensor(0x3014);

    switch (OV2655Sensor.Banding)
    {
        case CAM_BANDING_50HZ:
          #ifdef BANDING50_30HZ
            //Max frame rate = 30Fps

            if(OV2655Sensor.VideoMode == KAL_FALSE)
            {
                OV2655_preview_pclk_in_M = 360;
                CamWriteCmosSensor(0x3011, 0x00);
            }
            CamWriteCmosSensor(0x3014, banding|0x80);    /* enable banding and 50 Hz */
            CamWriteCmosSensor(0x301c, 0x02);
            CamWriteCmosSensor(0x3070, 0xB9);  //24M clk
          #else
            //Max frame rate = 25Fps except video record

            //if (OV2655_VEDIO_encode_mode)
            //{

            //    CamWriteCmosSensor( 0x3014, banding|0x81 );    /* enable banding and 50 Hz */
            //   CamWriteCmosSensor(0x301c, 0x02);
            //   CamWriteCmosSensor(0x3070, 0xB9); //30fps
                // Need tuning

            //}
            //else

            if(OV2655Sensor.VideoMode == KAL_FALSE)
            {
                OV2655_preview_pclk_in_M = 300;
                CamWriteCmosSensor(0x300e, 0x36);
                CamWriteCmosSensor(0x3011, 0x00);
            }
            CamWriteCmosSensor(0x3014, banding|0x80);    /* enable banding and 50 Hz */
            CamWriteCmosSensor(0x301c, 0x03);
            CamWriteCmosSensor(0x3070, 0x9b);
          #endif

            base_shutter = (OV2655_preview_pclk_in_M*100000/100+(OV2655_FULL_PERIOD_PIXEL_NUMS + OV2655_PV_Dummy_Pixels)*0.5)/(OV2655_FULL_PERIOD_PIXEL_NUMS + OV2655_PV_Dummy_Pixels);
            CamWriteCmosSensor(0x3070, base_shutter);

            if(OV2655Sensor.VideoMode == KAL_TRUE)
            {
                banding_step = 100/(OV2655Sensor.Fps/10) -1;
                CamWriteCmosSensor(0x301c, banding_step);
            }

            //CamWriteCmosSensor(0x3070, 0xB9);

            break;

        case CAM_BANDING_60HZ:
            //OV2655_Banding_setting = AE_FLICKER_MODE_60HZ;

            // 60Hz fixed 30fps

            //#ifndef BANDING50_30HZ
            if(OV2655Sensor.VideoMode == KAL_FALSE)
            {
                OV2655_preview_pclk_in_M = 360;
                CamWriteCmosSensor(0x3011, 0x00);
                CamWriteCmosSensor(0x300e, 0x34);
            }

            CamWriteCmosSensor(0x3014, (banding & ~0x80)|0x01);  /* enable banding and 60 Hz */
            CamWriteCmosSensor(0x301d, 0x03);
            CamWriteCmosSensor(0x3072, 0x9B);

            //#else
            //#endif
            //break;
            base_shutter = (OV2655_preview_pclk_in_M*100000/120+(OV2655_FULL_PERIOD_PIXEL_NUMS + OV2655_PV_Dummy_Pixels)*0.5)/(OV2655_FULL_PERIOD_PIXEL_NUMS + OV2655_PV_Dummy_Pixels);
            CamWriteCmosSensor(0x3072, base_shutter);
            //CamWriteCmosSensor(0x3072, 0x9b);
            if (OV2655Sensor.VideoMode == KAL_TRUE)
            {
                banding_step = 120/(OV2655Sensor.Fps/10) -1;
                CamWriteCmosSensor(0x301d, banding_step);
            }
            break;

          default:
            break;
    }
}


/*************************************************************************
* FUNCTION
*    OV2655SetHVMirror
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
static void OV2655SetHVMirror(kal_uint8 Mirror)
{
    kal_uint8 iCtr1=0x33;
    kal_uint8 iCtr2=0x10;
    #ifdef OV2655_DEBUG_TRACE
    kal_wap_trace(MOD_ENG,TRACE_INFO,"Mirror:%d",Mirror);
    #endif
    if (OV2655Sensor.Mirror == Mirror) return;
    OV2655Sensor.Mirror = Mirror;
    // set mirror and flip
    switch (Mirror) 
    {
        case IMAGE_SENSOR_MIRROR_H:
            iCtr2=0x13;
            break;
        case IMAGE_SENSOR_MIRROR_V:
            iCtr1=0x3b;
            break;
        case IMAGE_SENSOR_MIRROR_HV:
            iCtr1=0x3b;
            iCtr2=0x13;
            break;
        default: break;
    }

    if(Mirror != IMAGE_SENSOR_MIRROR_NORMAL)
    {
        CamWriteCmosSensor(0x307c, 0x13);// flip&mirror
        CamWriteCmosSensor(0x3090, 0x3b);
        CamWriteCmosSensor(0x3350, 0x33);
        CamWriteCmosSensor(0x3351, 0x27);
        CamWriteCmosSensor(0x3352, 0x00);
        CamWriteCmosSensor(0x3353, 0x3c);
        CamWriteCmosSensor(0x3354, 0x00);
        CamWriteCmosSensor(0x3355, 0x85);
        CamWriteCmosSensor(0x3356, 0x32);
        CamWriteCmosSensor(0x3357, 0x27);
        CamWriteCmosSensor(0x3358, 0x00);
        CamWriteCmosSensor(0x3359, 0x34);
        CamWriteCmosSensor(0x335a, 0x00);
        CamWriteCmosSensor(0x335b, 0x85);
        CamWriteCmosSensor(0x335c, 0x33);
        CamWriteCmosSensor(0x335d, 0x29);
        CamWriteCmosSensor(0x335e, 0x00);
        CamWriteCmosSensor(0x335f, 0x31);
        CamWriteCmosSensor(0x3360, 0x00);
        CamWriteCmosSensor(0x3361, 0x85);
        CamWriteCmosSensor(0x3363, 0x70);
        CamWriteCmosSensor(0x3364, 0x7f);
        CamWriteCmosSensor(0x3365, 0x00);
        CamWriteCmosSensor(0x3366, 0x00);
    }
    CamWriteCmosSensor(0x3090,iCtr1);
    CamWriteCmosSensor(0x307c,iCtr2);
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
*    OV2655EV
*
* DESCRIPTION
*    OV2655 EV setting.
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
static MM_ERROR_CODE_ENUM OV2655EV(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
        kal_uint8 iEvTemp = In->FeatureSetValue;
        kal_uint8 temp_reg=0;
        kal_uint8 iCtr1=0x41;
        kal_uint8 iCtr2=0x00;
      #ifdef OV2655_DEBUG_TRACE
        kal_wap_trace(MOD_ENG,TRACE_INFO,"EV:%d",iEvTemp);
      #endif
        if (OV2655Sensor.Ev == iEvTemp)
            return MM_ERROR_NONE;
        OV2655Sensor.Ev=iEvTemp;
        temp_reg=CamReadCmosSensor(0x3391);
        CamWriteCmosSensor(0x3391, temp_reg|0x4);

        switch (iEvTemp)
        {
            case CAM_EV_NEG_4_3:
                iCtr1=0x49;
                iCtr2=0x40;
                break;

            case CAM_EV_NEG_3_3:
                iCtr1=0x49;
                iCtr2=0x30; //34   /* for difference */
                break;

            case CAM_EV_NEG_2_3:
                iCtr1=0x49;
                iCtr2=0x20;
                break;

            case CAM_EV_NEG_1_3:
                iCtr1=0x49;
                iCtr2=0x10;
                break;

            case CAM_EV_ZERO:
                break;

            case CAM_EV_POS_1_3:
                iCtr2=0x10;
                break;

            case CAM_EV_POS_2_3:
                iCtr2=0x20;
                break;

            case CAM_EV_POS_3_3:
                iCtr2=0x30;   /* for difference */
                break;

            case CAM_EV_POS_4_3:
                iCtr2=0x42;
                break;

            default:
                break;
        }

        CamWriteCmosSensor(0x3390, iCtr1);
        CamWriteCmosSensor(0x339a, iCtr2);
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV2655WB
*
* DESCRIPTION
*    OV2655 WB setting.
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
static MM_ERROR_CODE_ENUM OV2655WB(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
        kal_uint8 WBTemp = In->FeatureSetValue;
        kal_uint8  temp_reg;
      #ifdef OV2655_DEBUG_TRACE
        kal_wap_trace(MOD_ENG,TRACE_INFO,"WB:%d",WBTemp);
      #endif
        if (OV2655Sensor.Wb == WBTemp)
            return MM_ERROR_NONE;

        OV2655Sensor.Wb = WBTemp;
        temp_reg=CamReadCmosSensor(0x3306);

        switch (WBTemp)
        {
            case CAM_WB_AUTO:
                CamWriteCmosSensor(0x3306, temp_reg&~0x2);   // select Auto WB
                break;

            case CAM_WB_CLOUD: //cloudy
                CamWriteCmosSensor(0x3306, temp_reg|0x2);  // select manual WB
                CamWriteCmosSensor(0x3337, 0x64);
                CamWriteCmosSensor(0x3338, 0x40);
                CamWriteCmosSensor(0x3339, 0x42);
                break;

            case CAM_WB_DAYLIGHT: //sunny
                CamWriteCmosSensor(0x3306, temp_reg|0x2);  // Disable AWB
                CamWriteCmosSensor(0x3337, 0x62);
                CamWriteCmosSensor(0x3338, 0x40);
                CamWriteCmosSensor(0x3339, 0x41);
                break;

            case CAM_WB_INCANDESCENCE: //office
                CamWriteCmosSensor(0x3306, temp_reg|0x2);  // Disable AWB
                CamWriteCmosSensor(0x3337, 0x49);
                CamWriteCmosSensor(0x3338, 0x40);
                CamWriteCmosSensor(0x3339, 0x60); //60
                break;


            case CAM_WB_FLUORESCENT:
                CamWriteCmosSensor(0x3306, temp_reg|0x2); // Disable AWB
                CamWriteCmosSensor(0x3337, 0x52);
                CamWriteCmosSensor(0x3338, 0x40);
                CamWriteCmosSensor(0x3339, 0x5a);
                break;
            case CAM_WB_TUNGSTEN:
                CamWriteCmosSensor(0x3306, temp_reg|0x2);  // Disable AWB
                CamWriteCmosSensor(0x3337, 0x43);
                CamWriteCmosSensor(0x3338, 0x40);
                CamWriteCmosSensor(0x3339, 0x66); //66
                break;
            default:
                break;
        }

    }
    return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    OV2655Effect
*
* DESCRIPTION
*    OV2655 Effect setting.
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
static MM_ERROR_CODE_ENUM OV2655Effect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        P_CAL_FEATURE_TYPE_ENUM_STRUCT EffectPara = &Out->FeatureInfo.FeatureEnum;
        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION | CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
        EffectPara->IsSupport = KAL_TRUE;
        EffectPara->ItemCount = 6;
        EffectPara->SupportItem[0] = CAM_EFFECT_ENC_NORMAL;
        EffectPara->SupportItem[1] = CAM_EFFECT_ENC_SEPIA;
        EffectPara->SupportItem[2] = CAM_EFFECT_ENC_COLORINV;
        EffectPara->SupportItem[3] = CAM_EFFECT_ENC_SEPIAGREEN;
        EffectPara->SupportItem[4] = CAM_EFFECT_ENC_SEPIABLUE;
        EffectPara->SupportItem[5] = CAM_EFFECT_ENC_GRAYSCALE;

    }
    else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
    {
        kal_uint8 EffectTemp = In->FeatureSetValue;
      #ifdef OV2655_DEBUG_TRACE
        kal_wap_trace(MOD_ENG,TRACE_INFO,"Effect:%d",EffectTemp);
      #endif
        if (OV2655Sensor.Effect == EffectTemp)
            return MM_ERROR_NONE;

        OV2655Sensor.Effect = EffectTemp;
        switch (EffectTemp)
        {
            case CAM_EFFECT_ENC_NORMAL:
                CamWriteCmosSensor(0x3391, (0x6 | 0x00));//add bit1
                break;

            case CAM_EFFECT_ENC_SEPIA:
                CamWriteCmosSensor(0x3391, (0x6 | 0x18));
                CamWriteCmosSensor(0x3396, 0x40);
                CamWriteCmosSensor(0x3397, 0xa6);
                break;

            case CAM_EFFECT_ENC_COLORINV:
                CamWriteCmosSensor(0x3391, (0x6 | 0x40));
                break;

            case CAM_EFFECT_ENC_SEPIAGREEN:
                CamWriteCmosSensor(0x3391, (0x6 | 0x18));
                CamWriteCmosSensor(0x3396, 0x60);
                CamWriteCmosSensor(0x3397, 0x60);
                break;

            case CAM_EFFECT_ENC_SEPIABLUE:
                CamWriteCmosSensor(0x3391, (0x6 | 0x18));
                CamWriteCmosSensor(0x3396, 0xf0);
                CamWriteCmosSensor(0x3397, 0x60);
                break;

            case CAM_EFFECT_ENC_GRAYSCALE: //B&W
                CamWriteCmosSensor(0x3391, (0x6 | 0x20));
                break;
            default:
                break;
        }
    }
    return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    OV2655Contrast
*
* DESCRIPTION
*    Contrast setting.
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM OV2655Contrast(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        const P_CAL_FEATURE_TYPE_ENUM_STRUCT Contrast = &Out->FeatureInfo.FeatureEnum;

        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
        Contrast->IsSupport = KAL_TRUE;
        Contrast->ItemCount = 3;
        Contrast->SupportItem[0] = CAM_CONTRAST_HIGH;
        Contrast->SupportItem[1] = CAM_CONTRAST_MEDIUM;
        Contrast->SupportItem[2] = CAM_CONTRAST_LOW;
    }
    else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
    {
        switch (In->FeatureSetValue)
        {
            case CAM_CONTRAST_HIGH:
                CamWriteCmosSensor(0x3398,0x2c);
                CamWriteCmosSensor(0x3399,0x2c);
                break;
            case CAM_CONTRAST_MEDIUM:
                CamWriteCmosSensor(0x3398,0x20);
                CamWriteCmosSensor(0x3399,0x20);
                break;
            case CAM_CONTRAST_LOW:
                CamWriteCmosSensor(0x3398,0x18);
                CamWriteCmosSensor(0x3399,0x18);
                break;
            default:
                return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        }
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   OV2655Saturation
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
static MM_ERROR_CODE_ENUM OV2655Saturation(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        const P_CAL_FEATURE_TYPE_ENUM_STRUCT Saturation = &Out->FeatureInfo.FeatureEnum;

        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
        Saturation->IsSupport = KAL_TRUE;
        Saturation->ItemCount = 3;
        Saturation->SupportItem[0] = CAM_SATURATION_HIGH;
        Saturation->SupportItem[1] = CAM_SATURATION_MEDIUM;
        Saturation->SupportItem[2] = CAM_SATURATION_LOW;
    }
    else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
    {

        switch (In->FeatureSetValue)
        {
            case CAM_SATURATION_HIGH:
                CamWriteCmosSensor(0x3394,0x58);
                CamWriteCmosSensor(0x3395,0x58);
                break;
            case CAM_SATURATION_MEDIUM:
                CamWriteCmosSensor(0x3394,0x48);
                CamWriteCmosSensor(0x3395,0x48);
                break;
            case CAM_SATURATION_LOW:
                CamWriteCmosSensor(0x3394,0x38);
                CamWriteCmosSensor(0x3395,0x38);
                break;
            default:
                return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        }
    }
    return MM_ERROR_NONE;
}
/*************************************************************************
* FUNCTION
*   OV2655Sharpness
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
static MM_ERROR_CODE_ENUM OV2655Sharpness(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        const P_CAL_FEATURE_TYPE_ENUM_STRUCT Sharpness = &Out->FeatureInfo.FeatureEnum;

        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
        Sharpness->IsSupport = KAL_TRUE;
        Sharpness->ItemCount = 3;
        Sharpness->SupportItem[0] = CAM_SHARPNESS_HIGH;
        Sharpness->SupportItem[1] = CAM_SHARPNESS_MEDIUM;
        Sharpness->SupportItem[2] = CAM_SHARPNESS_LOW;
    }
    else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
    {


        switch (In->FeatureSetValue)
        {
            case CAM_SHARPNESS_HIGH:
                CamWriteCmosSensor(0x3376, 0x0e);
            break;

            case CAM_SHARPNESS_MEDIUM:
                CamWriteCmosSensor(0x3376, 0x08);
                break;

            case CAM_SHARPNESS_LOW:
                CamWriteCmosSensor(0x3376, 0x02);
                break;

            default:
                return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        }
    }
    return MM_ERROR_NONE;
}



/*************************************************************************
* FUNCTION
*    OV2655StillCaptureSize
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
MM_ERROR_CODE_ENUM OV2655StillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    P_CAL_FEATURE_TYPE_ENUM_STRUCT Capsize = (P_CAL_FEATURE_TYPE_ENUM_STRUCT)&(Out->FeatureInfo.FeatureEnum);

    switch (In->FeatureCtrlCode)
    {
        case CAL_FEATURE_QUERY_OPERATION:
            Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
            Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|
                                   CAL_FEATURE_GET_OPERATION|
                                   CAL_FEATURE_QUERY_OPERATION;
            Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
            Capsize->IsSupport = KAL_TRUE;
        #if defined(MT6250) || defined(MT6260)
          #if defined(__IMAGE_SENSOR_PRETEND_VGA__)
            Capsize->ItemCount = 2;
            Capsize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
            Capsize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
            //Capsize->SupportItem[2] = CAM_IMAGE_SIZE_1M; //FOR MT6250 12864 project, Modify the output size. 11B1132SP Branch Only.
            //Capsize->SupportItem[3] = CAM_IMAGE_SIZE_2M; //FOR MT6250 12864 project, Modify the output size. 11B1132SP Branch Only.
            //Capsize->SupportItem[4] = CAM_IMAGE_SIZE_3M;//interplation
          #elif defined(__IMAGE_SENSOR_PRETEND_CIF__)
            Capsize->ItemCount = 1;
            Capsize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
          #else
            Capsize->ItemCount = 4;
            Capsize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
            Capsize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
            Capsize->SupportItem[2] = CAM_IMAGE_SIZE_1M; //FOR MT6250 12864 project, Modify the output size. 11B1132SP Branch Only.
            Capsize->SupportItem[3] = CAM_IMAGE_SIZE_2M; //FOR MT6250 12864 project, Modify the output size. 11B1132SP Branch Only.
            //Capsize->SupportItem[4] = CAM_IMAGE_SIZE_3M;//interplation
          #endif
        #else
            Capsize->ItemCount = 4;
            Capsize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
            Capsize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
            Capsize->SupportItem[2] = CAM_IMAGE_SIZE_1M;
            Capsize->SupportItem[3] = CAM_IMAGE_SIZE_2M;
        #endif
            break;
    }
    return MM_ERROR_NONE;
}
#ifdef __ZERO_SHUTTER_DELAY_SUPPORT__
/*************************************************************************
* FUNCTION
*    OV2655ZSDCaptureSize
*
* DESCRIPTION
*    This function get capture size
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM OV2655ZSDCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Capsize = &Out->FeatureInfo.FeatureEnum;
    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
        Capsize->IsSupport = KAL_TRUE;

        #if defined(__IMAGE_SENSOR_PRETEND_VGA__)
        Capsize->ItemCount = 2;
        Capsize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
        Capsize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
        #elif defined(__IMAGE_SENSOR_PRETEND_CIF__)
        Capsize->ItemCount = 1;
        Capsize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
        #else
        Capsize->ItemCount = 4;
        Capsize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
        Capsize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
        Capsize->SupportItem[2] = CAM_IMAGE_SIZE_1M;
        Capsize->SupportItem[3] = CAM_IMAGE_SIZE_2M;
        #endif
    }
    return MM_ERROR_NONE;
}
#endif

/*************************************************************************
* FUNCTION
*    OV2655Banding
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
MM_ERROR_CODE_ENUM OV2655Banding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    kal_uint8 banding, base_shutter, banding_step;
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
        banding = CamReadCmosSensor(0x3014);
      #ifdef OV2655_DEBUG_TRACE
        kal_wap_trace(MOD_ENG,TRACE_INFO,"Banding:%d",In->FeatureSetValue);
      #endif
        OV2655Sensor.Banding = In->FeatureSetValue;

        switch (OV2655Sensor.Banding)
        {
            case CAM_BANDING_50HZ:
              #ifdef BANDING50_30HZ
                if(OV2655Sensor.VideoMode == KAL_FALSE)
                {
                    OV2655_preview_pclk_in_M = 360;
                    CamWriteCmosSensor(0x3011, 0x00);
                }
                CamWriteCmosSensor( 0x3014, banding|0x80 );    /* enable banding and 50 Hz */
                CamWriteCmosSensor(0x301c, 0x02);
                CamWriteCmosSensor(0x3070, 0xB9);  //24M clk
             #else

                //Max frame rate = 25Fps except video record
                //if (OV2655_VEDIO_encode_mode)
                //{

                //    CamWriteCmosSensor( 0x3014, banding|0x81 );    /* enable banding and 50 Hz */
                //   CamWriteCmosSensor(0x301c, 0x02);
                //   CamWriteCmosSensor(0x3070, 0xB9); //30fps
                    // Need tuning

                //}
                //else
                if(OV2655Sensor.VideoMode == KAL_FALSE)
                {
                    OV2655_preview_pclk_in_M = 300;
                    CamWriteCmosSensor(0x300e, 0x36);
                    CamWriteCmosSensor(0x3011, 0x00);
                }
                CamWriteCmosSensor(0x3014, banding|0x80 );    /* enable banding and 50 Hz */
                CamWriteCmosSensor(0x301c, 0x03);
                CamWriteCmosSensor(0x3070, 0x9b);

              #endif

                base_shutter = (OV2655_preview_pclk_in_M*100000/100+(OV2655_FULL_PERIOD_PIXEL_NUMS + OV2655_PV_Dummy_Pixels)*0.5)/(OV2655_FULL_PERIOD_PIXEL_NUMS + OV2655_PV_Dummy_Pixels);
                CamWriteCmosSensor(0x3070, base_shutter);

                if(OV2655Sensor.VideoMode == KAL_TRUE)
                {
                    banding_step = 100/(OV2655Sensor.Fps/10) -1;
                    CamWriteCmosSensor(0x301c, banding_step);
                }

                //CamWriteCmosSensor(0x3070, 0xB9);

                break;

            case CAM_BANDING_60HZ:

                //OV2655_Banding_setting = AE_FLICKER_MODE_60HZ;

                // 60Hz fixed 30fps
                //#ifndef BANDING50_30HZ
                if(OV2655Sensor.VideoMode == KAL_FALSE)
                {
                    OV2655_preview_pclk_in_M = 360;
                    CamWriteCmosSensor(0x3011, 0x00);
                    CamWriteCmosSensor(0x300e, 0x34);
                }
                CamWriteCmosSensor(0x3014, (banding & ~0x80)|0x01 );     /* enable banding and 60 Hz */
                CamWriteCmosSensor(0x301d, 0x03);
                CamWriteCmosSensor(0x3072, 0x9B);
                //#else
                //#endif
                //break;
                base_shutter = (OV2655_preview_pclk_in_M*100000/120+(OV2655_FULL_PERIOD_PIXEL_NUMS + OV2655_PV_Dummy_Pixels)*0.5)/(OV2655_FULL_PERIOD_PIXEL_NUMS + OV2655_PV_Dummy_Pixels);
                CamWriteCmosSensor(0x3072, base_shutter);
                //CamWriteCmosSensor(0x3072, 0x9b);
                if(OV2655Sensor.VideoMode == KAL_TRUE)
                {
                    banding_step = 120/(OV2655Sensor.Fps/10) -1;
                    CamWriteCmosSensor(0x301d, banding_step);
                }
                break;

            default:
                break;
        }
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV2655GetSensorInfo
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
static void OV2655GetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT Info)
{
    Info->SensorId = OV2655_SENSOR_ID;
    Info->SensorIf = IMAGE_SENSOR_IF_PARALLEL;
    Info->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
    Info->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
    Info->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
    Info->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
    Info->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
    Info->PixelClkInv = KAL_FALSE;
    Info->PixelClkPolarity = POLARITY_LOW;
    Info->HsyncPolarity = POLARITY_LOW;//POLARITY_HIGH;
    Info->VsyncPolarity = POLARITY_LOW;
    Info->PreviewMclkFreq = 24000000;
    Info->CaptureMclkFreq = 24000000;
    Info->VideoMclkFreq = 24000000;
    Info->PreviewWidth = OV2655_IMAGE_SENSOR_PV_WIDTH;
    Info->PreviewHeight = OV2655_IMAGE_SENSOR_PV_HEIGHT;
    Info->FullWidth = OV2655_IMAGE_SENSOR_FULL_WIDTH;
    Info->FullHeight = OV2655_IMAGE_SENSOR_FULL_HEIGHT;
    Info->SensorAfSupport = KAL_FALSE;
    Info->SensorFlashSupport = KAL_FALSE;

}
#if defined (__AUTO_SCENE_DETECT_SUPPORT__)
/*************************************************************************
* FUNCTION
*    OV2655GetEvAwbRef
*
* DESCRIPTION
*    This function get sensor Ev/Awb (EV05/EV13) for auto scene detect
*
* PARAMETERS
*    Ref
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV2655GetEvAwbRef(P_SENSOR_AE_AWB_REF_STRUCT Ref)
{
    Ref->SensorAERef.AeRefLV05Shutter = 1791; //0x6FF
    Ref->SensorAERef.AeRefLV05Gain = 400; /* 3.125x, 128 base */
    Ref->SensorAERef.AeRefLV13Shutter = 21;   //0x15
    Ref->SensorAERef.AeRefLV13Gain = 128; /* 1x, 128 base */
    Ref->SensorAwbGainRef.AwbRefD65Rgain = 190; //95*2; //0x5f/* 1.4843x, 128 base */
    Ref->SensorAwbGainRef.AwbRefD65Bgain = 132; //66*2; //0x42/* 1.03125x, 128 base */
    Ref->SensorAwbGainRef.AwbRefCWFRgain = 164; //82*2; //0x52/* 1.28125x, 128 base */
    Ref->SensorAwbGainRef.AwbRefCWFBgain = 182; //91*2; //0x5b/* 1.421875x, 128 base */
}
/*************************************************************************
* FUNCTION
*    OV2655GetCurAeAwbInfo
*
* DESCRIPTION
*    This function get sensor cur Ae/Awb for auto scene detect
*
* PARAMETERS
*    Info
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV2655GetCurAeAwbInfo(P_SENSOR_AE_AWB_CUR_STRUCT Info)
{
    Info->SensorAECur.AeCurShutter = OV2655_read_shutter();
    Info->SensorAECur.AeCurGain = OV2655_read_OV2655_gain()*8; /* (REG*16)*8*/

    // Modify 0x330C to Read R/G/B gain. 02:R gain, 03:G gain, 04: B gain
    CamWriteCmosSensor(0x330C, 0x02);
    Info->SensorAwbGainCur.AwbCurRgain = CamReadCmosSensor(0x330F)*2; /*   (sensorGain* 64)*2 */
    CamWriteCmosSensor(0x330C, 0x04);
    Info->SensorAwbGainCur.AwbCurBgain = CamReadCmosSensor(0x330F)*2; /* (sensorGain* 64)*2 */
}

#endif

/*************************************************************************
* FUNCTION
*    OV2655DetectSensorId
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
static kal_int32 OV2655DetectSensorId(void)
{
    MM_ERROR_CODE_ENUM OV2655SensorClose(void);
    kal_uint32 OV2655PowerOn();
    kal_uint32 sensorId, AnotherSensorIdx;
    kal_int8 i, j;

    if (IMAGE_SENSOR_MAIN == OV2655Sensor.SensorIdx)
    {
        AnotherSensorIdx = IMAGE_SENSOR_SUB;
    }
    else
    {
        AnotherSensorIdx = IMAGE_SENSOR_MAIN;
    }
    for (i = 1; i >= 0; i--)
    {
        CamRstPinCtrl((IMAGE_SENSOR_INDEX_ENUM) AnotherSensorIdx, i);
        for (j = 1; j >= 0; j--)
        {
            CamPdnPinCtrl((IMAGE_SENSOR_INDEX_ENUM) AnotherSensorIdx, j);
            sensorId = OV2655PowerOn();
            OV2655SensorClose();
          #ifdef OV2655_DEBUG
            kal_wap_trace(MOD_ENG,TRACE_INFO,"OV2655DetectSensorId:%x",sensorId);
          #endif
            if (OV2655_SENSOR_ID == sensorId)
            {
                return OV2655_SENSOR_ID;
            }
        }
    }
    return -1;
}

/*************************************************************************
* FUNCTION
*    OV2655InitOperationPara
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
static void OV2655InitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
    Para->CaptureDelayFrame = 0; /* wait stable frame when sensor change mode (pre to cap) */
    Para->PreviewDelayFrame = 3; /* wait stable frame when sensor change mode (cap to pre) */
    Para->PreviewDisplayWaitFrame = 2; /* wait stable frame when sensor change mode (cap to pre) */
}

/*************************************************************************
* FUNCTION
*    OV2655DscSupportInfo
*
* DESCRIPTION
*    This function get dsc support Info
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
static void OV2655DscSupportInfo(P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT Info)
{
#if defined(DRV_ISP_6238_SERIES)
    //kal_mem_cpy(Info, &OV2655_dsc_support_info, sizeof(camcorder_info_struct));
#endif
}

/*************************************************************************
* FUNCTION
*    OV2655AEEnable
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
static MM_ERROR_CODE_ENUM OV2655AEEnable(kal_bool Enable)
{
    kal_uint8 AETemp = CamReadCmosSensor(0x3013);
#ifdef OV2655_DEBUG_TRACE
    kal_prompt_trace(MOD_ENG,"AWBenable_OV2655Sensor.BypassAe:%d",OV2655Sensor.BypassAe);
#endif
    //if (OV2655Sensor.BypassAe && OV2655_gPVmode)
    if (OV2655Sensor.BypassAe)// && OV2655_gPVmode)
    {
        Enable = KAL_FALSE;
    }


    if (Enable)
        CamWriteCmosSensor(0x3013, (AETemp| 0x05)); /* Turn ON AEC/AGC*/
    else
        CamWriteCmosSensor(0x3013, (AETemp&(~0x05))); /* Turn OFF AEC/AGC*/

    #ifdef OV2655_DEBUG_TRACE
    kal_prompt_trace(MOD_ENG,"AEenable:%d",Enable);
    #endif
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV2655AWBEnable
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
static MM_ERROR_CODE_ENUM OV2655AWBEnable(kal_bool Enable)
{
    kal_uint8 AWBTemp=CamReadCmosSensor(0x3324);
#ifdef OV2655_DEBUG_TRACE
    kal_prompt_trace(MOD_ENG,"AWBenable_OV2655Sensor.BypassAwb:%d",OV2655Sensor.BypassAwb);
#endif
    //if (OV2655Sensor.BypassAwb && OV2655_gPVmode)
    if (OV2655Sensor.BypassAwb)// && OV2655_gPVmode)
    {
        Enable = KAL_FALSE;
    }

    if (Enable)
    {
        CamWriteCmosSensor(0x3324, AWBTemp& ~0x40);
    }
    else
    {
        CamWriteCmosSensor(0x3324, AWBTemp|0x40);
    }
#ifdef OV2655_DEBUG_TRACE
    kal_prompt_trace(MOD_ENG,"AWBenable_enable:%d",Enable);
#endif

    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV2655NightMode
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
static void OV2655NightMode(kal_bool Enable)
{
    kal_uint8 night = CamReadCmosSensor(0x3014); //bit[3], 0: disable, 1:enable

#ifdef OV2655_DEBUG_TRACE
    kal_wap_trace(MOD_ENG,TRACE_INFO, "OV2655 NightMode %d",Enable);
#endif
    if (OV2655_sensor_cap_state == KAL_FALSE)
    {
        if (OV2655Sensor.VideoMode == KAL_FALSE)// camera mode
        {
            if (KAL_TRUE == Enable)
            { /* camera night mode */
                #ifdef OV2655_DEBUG_TRACE
                kal_wap_trace(MOD_ENG,TRACE_INFO, "camera night mode");
                #endif
                CamWriteCmosSensor(0x3014, night & 0xf7); /*Enable fix frame rate*/
                CamWriteCmosSensor(0x302d, 0x00); //jerry
                CamWriteCmosSensor(0x302e, 0x00);

                // set Max gain to 16X
                CamWriteCmosSensor(0x3015, 0x52);  //jerry 0624 for night mode
                CamWriteCmosSensor(0x3014, night | 0x08); /*Disable fix frame rate*/
                //CamWriteCmosSensor(0x3011, 0x00);
            }
            else
            {   /* camera normal mode */
                #ifdef OV2655_DEBUG_TRACE
                kal_wap_trace(MOD_ENG,TRACE_INFO, "camera normal mode");
                #endif

                CamWriteCmosSensor(0x3014, night & 0xf7); /*Enable fix frame rate*/
                CamWriteCmosSensor(0x302d, 0x00); //jerry
                CamWriteCmosSensor(0x302e, 0x00);

                // set Max gain to 4X
                CamWriteCmosSensor(0x3015, 0x32);
                //CamWriteCmosSensor(0x3011, 0x00);     //Preview 30fps
                CamWriteCmosSensor(0x3014, night | 0x08);
            }
        }
        else //video mode
        {
            CamWriteCmosSensor(0x3015, 0x02); //jerry
            #ifdef BANDING50_30HZ
            CamWriteCmosSensor(0x300e, 0x34);
            #else
            if (OV2655Sensor.Banding == CAM_BANDING_50HZ)
                CamWriteCmosSensor(0x300e, 0x36);
            else
                CamWriteCmosSensor(0x300e, 0x34);
            #endif

            if (KAL_TRUE == Enable)
            {   /* video night mode */
                #ifdef OV2655_DEBUG_TRACE
                kal_wap_trace(MOD_ENG,TRACE_INFO, "video night mode");
                #endif
            }
            else
            {   /* video normal mode */
                #ifdef OV2655_DEBUG_TRACE
                kal_wap_trace(MOD_ENG,TRACE_INFO, "video normal mode");
                #endif
            }
            kal_wap_trace(MOD_ENG,TRACE_INFO, "OV2655 videoframerate is %d",OV2655Sensor.Fps);
            OV2655SetVideoFrameRate(OV2655Sensor.Fps);
            CamWriteCmosSensor(0x3014, night & 0xf7); /*Enable fix frame rate*/
            // clear extra exposure line
            CamWriteCmosSensor(0x302d, 0x00);
            CamWriteCmosSensor(0x302e, 0x00);
        }
    }
}


static MM_ERROR_CODE_ENUM OV2655SceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
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
        OV2655NightMode(Enable);
    }
    return MM_ERROR_NONE;
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

/*************************************************************************
* FUNCTION
*    OV2655PowerOn
*
* DESCRIPTION
*    This function reset sensor and read id
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
static kal_uint32 OV2655PowerOn(void)
{
    kal_uint32 sensor_id = 0;
    /* PowerOn the sensor */
    CisModulePowerOn(OV2655Sensor.SensorIdx, KAL_TRUE);
    kal_sleep_task(2);  /* delay for power stable */
    CameraSccbOpen(CAMERA_SCCB_SENSOR, OV2655_WRITE_ID, CAMERA_SCCB_16BIT, CAMERA_SCCB_8BIT, 400);

    /* set sensors chip enable pin to low to activate OV2655 */
    CamPdnPinCtrl(OV2655Sensor.SensorIdx, 0);

    /* Reset the sensor */
    CamRstPinCtrl(OV2655Sensor.SensorIdx, 1);
    kal_sleep_task(1);
    CamRstPinCtrl(OV2655Sensor.SensorIdx, 0);
    kal_sleep_task(1);
    CamRstPinCtrl(OV2655Sensor.SensorIdx, 1);
    /* delay for stable sensor */
    kal_sleep_task(4);

    /* software reset sensor and wait (to sensor) */
    CamWriteCmosSensor(0x3012,0x80);
    kal_sleep_task(2);

    /* Read Sensor ID  */
#ifdef OV2655_DEBUG_TRACE
    kal_wap_trace(MOD_ENG,TRACE_INFO, "OV2655 Sensor ID: %x ",(CamReadCmosSensor(0x300A) << 8)|CamReadCmosSensor(0x300B));
#endif
    sensor_id = (CamReadCmosSensor(0x300A) << 8) | CamReadCmosSensor(0x300B);
    return sensor_id;
}

/**********************  OVT ***********************/

kal_uint16 OV2655_read_shutter(void)
{
    kal_uint8 temp_reg1, temp_reg2;
    kal_uint16 temp_reg, extra_exp_lines;

    temp_reg1 = CamReadCmosSensor(0x3003);    // AEC[b7~b0]
    temp_reg2 = CamReadCmosSensor(0x3002);    // AEC[b15~b8]
    temp_reg = (temp_reg1 & 0xFF) | (temp_reg2 << 8);

    temp_reg1 = CamReadCmosSensor(0x302E);    // EXVTS[b7~b0]
    temp_reg2 = CamReadCmosSensor(0x302D);    // EXVTS[b15~b8]
    extra_exp_lines = (temp_reg1 & 0xFF) | (temp_reg2 << 8);

    OV2655_PV_Shutter = temp_reg ;
    OV2655_PV_Extra_Lines = extra_exp_lines;
    return temp_reg + extra_exp_lines;
}    /* OV2655_read_shutter */

kal_uint16 OV2655_read_OV2655_gain(void)
{
    kal_uint8  temp_reg;
    kal_uint16 sensor_gain;

    temp_reg=CamReadCmosSensor(0x3000);


    sensor_gain=(16+(temp_reg&0x0F));
    if(temp_reg&0x10)
        sensor_gain<<=1;
    if(temp_reg&0x20)
        sensor_gain<<=1;

    if(temp_reg&0x40)
        sensor_gain<<=1;

    if(temp_reg&0x80)
        sensor_gain<<=1;

    return sensor_gain;
}  /* OV2655_read_OV2655_gain */

//From OV Jerry
void OV2655_Computer_AECAGC(kal_uint8 preview_clk_in_M, kal_uint8 capture_clk_in_M)
{
    kal_uint16 PV_Line_Width;
    kal_uint16 Capture_Line_Width;
    kal_uint16 Capture_Maximum_Shutter;
    kal_uint16 Capture_Exposure;
    kal_uint16 Capture_Gain16;
    kal_uint32 Capture_Banding_Filter;
    kal_uint32 Gain_Exposure=0;

    PV_Line_Width = OV2655_PV_PERIOD_PIXEL_NUMS + OV2655_PV_Dummy_Pixels;

    Capture_Line_Width = OV2655_FULL_PERIOD_PIXEL_NUMS + OV2655_Capture_Dummy_Pixels;
    Capture_Maximum_Shutter = OV2655_FULL_EXPOSURE_LIMITATION + OV2655_Capture_Dummy_Lines;

    kal_wap_trace(MOD_ENG,TRACE_INFO,"ov2655 pv linelength: %x",PV_Line_Width);
    kal_wap_trace(MOD_ENG,TRACE_INFO,"ov2655 cap linelength: %x",Capture_Line_Width);
    if (OV2655Sensor.Banding == CAM_BANDING_50HZ)

        Capture_Banding_Filter = (kal_uint32)(capture_clk_in_M*100000/100/(2*Capture_Line_Width));

    else

        Capture_Banding_Filter = (kal_uint32)(capture_clk_in_M*100000/120/(2*Capture_Line_Width) );


    /*   Gain_Exposure = OV2655_PV_Gain16*(OV2655_PV_Shutter+OV2655_PV_Extra_Lines)*PV_Line_Width/g_Preview_PCLK_Frequency/Capture_Line_Width*g_Capture_PCLK_Frequency
    ;*/
    OV2655_PV_Gain16 = OV2655_read_OV2655_gain();

    kal_wap_trace(MOD_ENG,TRACE_INFO,"ov2655 capture before: gain %x",OV2655_PV_Gain16);
    Gain_Exposure = 1 * OV2655_PV_Gain16;  //For OV2655
    ///////////////////////
    Gain_Exposure *=(OV2655_PV_Shutter+OV2655_PV_Extra_Lines);
    Gain_Exposure *=PV_Line_Width;  //970
    //   Gain_Exposure /=g_Preview_PCLK_Frequency;
    Gain_Exposure /=Capture_Line_Width;//1940
    Gain_Exposure = Gain_Exposure*capture_clk_in_M/preview_clk_in_M;// for clock

    //redistribute gain and exposure
    if (Gain_Exposure < (kal_uint32)(Capture_Banding_Filter * 16))     // Exposure < 1/100/120
    {
       if(Gain_Exposure<16){//exposure line smaller than 2 lines and gain smaller than 0x08
            Gain_Exposure = Gain_Exposure*4;
            Capture_Exposure = 1;
            Capture_Gain16 = (Gain_Exposure*2 + 1)/Capture_Exposure/2/4;
        }
        else
        {
            Capture_Exposure = Gain_Exposure /16;
            Capture_Gain16 = (Gain_Exposure*2 + 1)/Capture_Exposure/2;
        }
    }
    else
    {
        if (Gain_Exposure >(kal_uint32)( Capture_Maximum_Shutter * 16)) // Exposure > Capture_Maximum_Shutter
        {

            Capture_Exposure = Capture_Maximum_Shutter/Capture_Banding_Filter*Capture_Banding_Filter;
            Capture_Gain16 = (Gain_Exposure*2 + 1)/Capture_Exposure/2;
            if (Capture_Gain16 > OV2655_Capture_Max_Gain16)
            {
                // gain reach maximum, insert extra line
                Capture_Exposure = (kal_uint16)(Gain_Exposure*11 /10 /OV2655_Capture_Max_Gain16);

                // Exposure = n/100/120
                Capture_Exposure = Capture_Exposure/Capture_Banding_Filter * Capture_Banding_Filter;
                Capture_Gain16 = ((Gain_Exposure *4)/ Capture_Exposure+3)/4;
            }
        }
        else  // 1/100 < Exposure < Capture_Maximum_Shutter, Exposure = n/100/120
        {
            Capture_Exposure = Gain_Exposure/16/Capture_Banding_Filter;
            Capture_Exposure = Capture_Exposure * Capture_Banding_Filter;
            Capture_Gain16 = (Gain_Exposure*2 +1) / Capture_Exposure/2;
        }
    }

    //OV2655_Capture_Gain16 = Capture_Gain16;
    //OV2655_Capture_Extra_Lines = (Capture_Exposure > Capture_Maximum_Shutter)?
    //      (Capture_Exposure - Capture_Maximum_Shutter/Capture_Banding_Filter*Capture_Banding_Filter):0;

    //OV2655_Capture_Shutter = Capture_Exposure - OV2655_Capture_Extra_Lines;
}



/*************************************************************************
* FUNCTION
*    OV2655Preview
*
* DESCRIPTION
*    This function set to preview mode
*
* PARAMETERS
*    id, In, Out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV2655Preview(CAL_SCENARIO_ENUM ScenarioId, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
    kal_uint8 StartX = 1, StartY = 1;
    kal_uint16 iDummyPixels = 0, iDummyLines = 0;

    OV2655_sensor_cap_state = KAL_FALSE;

#ifdef OV2655_DEBUG_TRACE
    kal_wap_trace(MOD_ENG,TRACE_INFO, "OV2655 Preview");
#endif
    OV2655CurrScenario = ScenarioId;
    OV2655Sensor.Banding = In->BandingFreq;
    OV2655Sensor.NightMode = In->NightMode;
    OV2655PVMode();
    OV2655_preview_pclk_in_M = 360;
    switch (ScenarioId)
    {
        case CAL_SCENARIO_VIDEO:
            OV2655Sensor.VideoMode = KAL_TRUE;
            OV2655Sensor.Fps = In->MaxVideoFrameRate; //300 means 30fps
            Out->WaitStableFrameNum = 3;

            OV2655_exposure_line_h = 0;
            OV2655_exposure_line_l = 0;
            OV2655_extra_exposure_line_h = 0;
            OV2655_extra_exposure_line_l = 0;
            //CamWriteCmosSensor(0x300e, 0x34);
            //CamWriteCmosSensor(0x3011, 0x00);
            break;
        case CAL_SCENARIO_CAMERA_PREVIEW:
        case CAL_SCENARIO_WEBCAM_PREVIEW:
        case CAL_SCENARIO_WEBCAM_CAPTURE:
            OV2655Sensor.VideoMode = KAL_FALSE;
            OV2655Sensor.Fps = (OV2655Sensor.NightMode ? 50 : 100);
            Out->WaitStableFrameNum = 3;
            break;
        default:
            break;
    }
    OV2655_gPVmode=KAL_TRUE;
    OV2655AEEnable(KAL_TRUE);
    OV2655AWBEnable(KAL_TRUE);
    OV2655SetHVMirror(In->ImageMirror);
    OV2655_PV_Dummy_Pixels = iDummyPixels;
    OV2655_PV_Dummy_Lines = iDummyLines;
    OV2655SetDummy(iDummyPixels, iDummyLines);
    OV2655SetBanding();
    OV2655NightMode(OV2655Sensor.NightMode);
    OV2655RollBackShutterGain();

    //if(In->ImageMirror != IMAGE_SENSOR_MIRROR_NORMAL)
    StartX=StartY=1;
    //if(ScenarioId==CAL_SCENARIO_WEBCAM_PREVIEW || ScenarioId==CAL_SCENARIO_WEBCAM_CAPTURE)
    //{StartX += 40; StartY += 30;}

    if (KAL_TRUE == OV2655Sensor.OutTestPattern)
    {
        CamWriteCmosSensor(0x3308, 0x01);/* Color Bar */
    }
    else
    {
        CamWriteCmosSensor(0x3308, 0x00);/* Color Bar */
    }

    Out->GrabStartX = StartX;
    Out->GrabStartY = StartY;
    if (CAL_SCENARIO_VIDEO == OV2655CurrScenario)
    {
        Out->ExposureWindowWidth = OV2655_IMAGE_SENSOR_PV_WIDTH - 40;
        Out->ExposureWindowHeight = OV2655_IMAGE_SENSOR_PV_HEIGHT - 30;
    }
    else
    {
        Out->ExposureWindowWidth = OV2655_IMAGE_SENSOR_PV_WIDTH - 4;
        Out->ExposureWindowHeight = OV2655_IMAGE_SENSOR_PV_HEIGHT - 3;
    }
}

#ifdef __ZERO_SHUTTER_DELAY_SUPPORT__
/*************************************************************************
* FUNCTION
*    OV2655FullPreview
*
* DESCRIPTION
*    This function set to full size preview mode ,but 5M jpeg sensor can only support to 1.3M size
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
static void OV2655FullPreview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{

#ifdef __OV2655_DEBUG_TRACE__
    kal_print_string_trace(MOD_ENG, TRACE_WARNING, "OV2655FullPreview");
#endif
    OV2655Sensor.Banding=In->BandingFreq;
    OV2655_sensor_cap_state = KAL_FALSE;
    OV2655_gPVmode = KAL_FALSE;
    OV2655Sensor.VideoMode = KAL_FALSE;

    {
        CamWriteCmosSensor(0x300f, 0xa6);
        CamWriteCmosSensor(0x3012, 0x00);
        CamWriteCmosSensor(0x302a, 0x04);
        CamWriteCmosSensor(0x302b, 0xd4);
        CamWriteCmosSensor(0x306f, 0x54);
        CamWriteCmosSensor(0x3362, 0x80);

        CamWriteCmosSensor(0x3020, 0x01);
        CamWriteCmosSensor(0x3021, 0x12);// 18
        CamWriteCmosSensor(0x3022, 0x00);
        CamWriteCmosSensor(0x3023, 0x06);
        CamWriteCmosSensor(0x3024, 0x06);
        CamWriteCmosSensor(0x3025, 0x58);
        CamWriteCmosSensor(0x3026, 0x04);
        CamWriteCmosSensor(0x3027, 0xbc);
        CamWriteCmosSensor(0x3088, 0x06);
        CamWriteCmosSensor(0x3089, 0x40);
        CamWriteCmosSensor(0x308a, 0x04);
        CamWriteCmosSensor(0x308b, 0xb0);
        CamWriteCmosSensor(0x3316, 0x64);
        CamWriteCmosSensor(0x3317, 0x4b);
        CamWriteCmosSensor(0x3318, 0x00);
        CamWriteCmosSensor(0x3319, 0x6c);
        CamWriteCmosSensor(0x331a, 0x64);
        CamWriteCmosSensor(0x331b, 0x4b);
        CamWriteCmosSensor(0x331c, 0x00);
        CamWriteCmosSensor(0x331d, 0x6c);
        CamWriteCmosSensor(0x3302, 0x01);
    }
    OV2655SetHVMirror(In->ImageMirror);

    OV2655NightMode(In->NightMode);

    Out->WaitStableFrameNum = 2;
    Out->GrabStartX = 1;
    Out->GrabStartY = 1;

    Out->ExposureWindowWidth = OV2655_IMAGE_SENSOR_FULL_WIDTH-8;
    Out->ExposureWindowHeight = OV2655_IMAGE_SENSOR_FULL_HEIGHT-6;
}
#endif

/*************************************************************************
* FUNCTION
*    OV2655Capture
*
* DESCRIPTION
*    This function set to capture mode
*
* PARAMETERS
*    id, In, Out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void OV2655Capture(CAL_SCENARIO_ENUM id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
    volatile kal_uint32 shutter = OV2655_exposure_lines, temp_reg;
    //kal_uint8 temp_AE_reg, temp;
    //kal_uint16 AE_setting_delay = 0;
    //kal_uint16 PV_Line_Width;
    //kal_uint16 Capture_Line_Width;

    OV2655_sensor_cap_state = KAL_TRUE;

    temp_reg = CamReadCmosSensor(0x3014);
    CamWriteCmosSensor(0x3014, temp_reg & 0xf7); //Disable night mode

    #if 1
    // turn off AEC/AGC
    OV2655AEEnable(KAL_FALSE);
    //temp_AE_reg = CamReadCmosSensor(0x3013);
    //CamWriteCmosSensor(0x3013, (temp_AE_reg&(~0x05)) );
    OV2655AWBEnable(KAL_FALSE);
    #endif

    OV2655_exposure_line_h = CamReadCmosSensor(0x3002);
    OV2655_exposure_line_l = CamReadCmosSensor(0x3003);
    OV2655_extra_exposure_line_h = CamReadCmosSensor(0x302D);
    OV2655_extra_exposure_line_l = CamReadCmosSensor(0x302E);

    shutter = OV2655_read_shutter();
    OV2655_PV_Gain16 = OV2655_read_OV2655_gain();

    if (In->ImageTargetWidth <= OV2655_IMAGE_SENSOR_PV_WIDTH &&
          In->ImageTargetHeight<= OV2655_IMAGE_SENSOR_PV_HEIGHT)
    {    /* Less than PV Mode */

        OV2655_gPVmode=KAL_TRUE;

        OV2655_dummy_pixels = 0;
        OV2655_dummy_lines = 0;


        OV2655_capture_pclk_in_M = OV2655_preview_pclk_in_M;   //Don't change the clk

        shutter = (shutter*OV2655_capture_pclk_in_M)/OV2655_preview_pclk_in_M;
        shutter = (shutter*OV2655_PV_PERIOD_PIXEL_NUMS)/(OV2655_PV_PERIOD_PIXEL_NUMS+OV2655_dummy_pixels/2);
        // set dummy
        if((0 == OV2655_dummy_pixels)&&(0 == OV2655_dummy_lines))
        {
        // Do not change Line Length and Frame Lentgh
        }
        else
            OV2655SetDummy(OV2655_dummy_pixels, OV2655_dummy_lines);

        if (shutter < 1)
        {
            shutter = 1;
        }
        // set shutter OVT
        OV2655WriteShutter(shutter);

        Out->GrabStartX = 1;
        Out->GrabStartY = 1;

        Out->ExposureWindowWidth = OV2655_IMAGE_SENSOR_PV_WIDTH - 4;
        Out->ExposureWindowHeight = OV2655_IMAGE_SENSOR_PV_HEIGHT - 3;

        Out->WaitStableFrameNum= 0; // For preview size capture, no need wait stable frame.
    }
    else
    {    /* 2M FULL Mode */
        Out->WaitStableFrameNum = 2;

        CamWriteCmosSensor(0x300f, 0xa6);
        CamWriteCmosSensor(0x3012, 0x00);
        CamWriteCmosSensor(0x302a, 0x04);
        CamWriteCmosSensor(0x302b, 0xd4);
        CamWriteCmosSensor(0x306f, 0x54);
        CamWriteCmosSensor(0x3362, 0x80);

        CamWriteCmosSensor(0x3020, 0x01);
        CamWriteCmosSensor(0x3021, 0x12);// 18
        CamWriteCmosSensor(0x3022, 0x00);
        CamWriteCmosSensor(0x3023, 0x06);
        CamWriteCmosSensor(0x3024, 0x06);
        CamWriteCmosSensor(0x3025, 0x58);
        CamWriteCmosSensor(0x3026, 0x04);
        CamWriteCmosSensor(0x3027, 0xbc);
        CamWriteCmosSensor(0x3088, 0x06);
        CamWriteCmosSensor(0x3089, 0x40);
        CamWriteCmosSensor(0x308a, 0x04);
        CamWriteCmosSensor(0x308b, 0xb0);
        CamWriteCmosSensor(0x3316, 0x64);
        CamWriteCmosSensor(0x3317, 0x4b);
        CamWriteCmosSensor(0x3318, 0x00);
        CamWriteCmosSensor(0x3319, 0x6c);
        CamWriteCmosSensor(0x331a, 0x64);
        CamWriteCmosSensor(0x331b, 0x4b);
        CamWriteCmosSensor(0x331c, 0x00);
        CamWriteCmosSensor(0x331d, 0x6c);
        CamWriteCmosSensor(0x3302, 0x01);

        // 如果拍照拍不下来，建议不要修改clk，可以直接增加dummy pixel。eg: 970, 1940...

        OV2655_gPVmode = KAL_FALSE;

        OV2655_capture_pclk_in_M = 360;

        if ((In->ImageTargetWidth<=OV2655_IMAGE_SENSOR_FULL_WIDTH)&&
            (In->ImageTargetHeight<=OV2655_IMAGE_SENSOR_FULL_HEIGHT))
        {
            if (In->ZoomFactor <= 200)
            {
                //Do Not change Clk
                 OV2655_dummy_pixels=0;  /*If Capture fail, you can add this dummy*/
            }
            else if (In->ZoomFactor > 200)
            {
                OV2655_dummy_pixels = 1940; /*If Capture fail, you can add this dummy*/
                shutter = shutter/2;
            }

            OV2655_dummy_lines=0;


            OV2655_Capture_Dummy_Pixels = OV2655_dummy_pixels ;
            OV2655_Capture_Dummy_Lines = OV2655_dummy_lines;

            // set dummy
            OV2655SetDummy(OV2655_dummy_pixels, OV2655_dummy_lines);

            if (shutter < 1)
            {
                shutter = 1;
            }
            // set shutter OVT
            OV2655WriteShutter(shutter);

            kal_sleep_task(15);  //delay 1frame

            Out->GrabStartX=1;
            Out->GrabStartY=1;
            Out->ExposureWindowWidth=OV2655_IMAGE_SENSOR_FULL_WIDTH - 8;
            Out->ExposureWindowHeight=OV2655_IMAGE_SENSOR_FULL_HEIGHT - 6;
        }
    }
}





/*************************************************************************
* FUNCTION
*    OV2655SensorOpen
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
static MM_ERROR_CODE_ENUM OV2655SensorOpen(void)
{
    if (OV2655_SENSOR_ID != OV2655PowerOn()) return MM_ERROR_SENSOR_READ_ID_FAIL;

    //OV2655_sensor.pv_shutter = 0x0265;
    //OV2655_sensor.pv_extra_shutter = 0;

    OV2655InitialSetting();

    OV2655Sensor.Wb = CAM_WB_AUTO;
    OV2655Sensor.Ev = CAM_EV_ZERO;
    OV2655Sensor.Effect = CAM_EFFECT_ENC_NORMAL;
    OV2655Sensor.Mirror = IMAGE_SENSOR_MIRROR_NORMAL;
    OV2655Sensor.VideoMode = KAL_FALSE;
    OV2655Sensor.NightMode = KAL_FALSE;
    OV2655Sensor.Banding = CAM_BANDING_50HZ;

    OV2655Sensor.Fps = 100;
    //OV2655Sensor.ShutterStep= 0x96;
    OV2655Sensor.BypassAe = KAL_FALSE;
    OV2655Sensor.BypassAwb = KAL_FALSE;

    OV2655Sensor.OutTestPattern = KAL_FALSE;    /* Default not output test pattern */
  
    return MM_ERROR_NONE;
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
#endif

/*************************************************************************
* FUNCTION
*    OV2655SensorFeatureCtrl
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
extern MM_ERROR_CODE_ENUM OV2655WebcamFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen);
static MM_ERROR_CODE_ENUM OV2655SensorFeatureCtrl(kal_uint32 id, void *In, void *Out, kal_uint32 out_len, kal_uint32 *r_out_len)
{
    MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
    //kal_uint32 TmpFrameRate;

    P_CAL_FEATURE_CTRL_STRUCT pCameraFeatureIn=(P_CAL_FEATURE_CTRL_STRUCT) In;
    P_CAL_FEATURE_CTRL_STRUCT pCameraFeatureOut=(P_CAL_FEATURE_CTRL_STRUCT) Out;
    // for camera HAL UT only
    P_CAL_FEATURE_TYPE_ENUM_STRUCT pCamFeatureEnum=(P_CAL_FEATURE_TYPE_ENUM_STRUCT) &(pCameraFeatureOut->FeatureInfo.FeatureEnum);
    //P_CAL_CAMERA_DIGITAL_ZOOM_OUT_STRUCT pCameraDzOut=pCameraFeatureOut->FeatureInfo.FeatureStructured.pCamDzOutPara;


    if (id >= CAL_FEATURE_WEBCAM_BEGIN && id <= CAL_FEATURE_WEBCAM_END)
    {
        return OV2655WebcamFeatureCtrl(id, In, Out, out_len, r_out_len);
    }

    if(Out!=NULL && CAL_FEATURE_QUERY_OPERATION==pCameraFeatureIn->FeatureCtrlCode){
        pCamFeatureEnum->IsSupport = KAL_FALSE;
    }

    switch (id)
    {
         /* CAL Query and set series */
        case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
            CamPdnPinCtrl(OV2655Sensor.SensorIdx, 1);
            ErrCode = MM_ERROR_NONE;
            break;
        case CAL_FEATURE_CAMERA_BRIGHTNESS:
            ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
            break;
        case CAL_FEATURE_CAMERA_EV_VALUE:
            ErrCode = OV2655EV(In, Out);
            break;
        case CAL_FEATURE_CAMERA_HUE:
        case CAL_FEATURE_CAMERA_GAMMA:
            ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
            break;
        case CAL_FEATURE_CAMERA_WB:
            ErrCode = OV2655WB(In, Out);
            break;
        case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
            ErrCode = OV2655Effect(In, Out);
            break;
        case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
            ErrCode = OV2655StillCaptureSize(In, Out);
            break;
        #ifdef __ZERO_SHUTTER_DELAY_SUPPORT__
        case CAL_FEATURE_CAMERA_ZSD_CAPTURE_SIZE:
            ErrCode = OV2655ZSDCaptureSize(In, Out);
            break;
        #endif
        case CAL_FEATURE_CAMERA_SCENE_MODE:
            ErrCode = OV2655SceneMode(KAL_TRUE, In, Out);
            break;
        case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
            ErrCode = OV2655SceneMode(KAL_FALSE, In, Out);
            break;
        case CAL_FEATURE_CAMERA_BANDING_FREQ: /* move to preview */
            ErrCode = OV2655Banding(In, Out);
            break;
        case CAL_FEATURE_CAMERA_FLASH_MODE:
            ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
            break;
        case CAL_FEATURE_CAMERA_CONTRAST:
            ErrCode = OV2655Contrast(In, Out);
            break;
        case CAL_FEATURE_CAMERA_SATURATION:
            ErrCode = OV2655Saturation(In, Out);
            break;
        case CAL_FEATURE_CAMERA_SHARPNESS:
            ErrCode = OV2655Sharpness(In, Out);
            break;
        #if defined (__AUTO_SCENE_DETECT_SUPPORT__)
        case IMAGE_SENSOR_FEATURE_GET_EV_AWB_REF:
            OV2655GetEvAwbRef(Out);
            break;
        case IMAGE_SENSOR_FEATURE_GET_SHUTTER_GAIN_AWB_GAIN:
            OV2655GetCurAeAwbInfo(Out);
            break;
        case IMAGE_SENSOR_FEATURE_SET_SCENE_ENHANCE:
            {
                CAL_FEATURE_CTRL_STRUCT Para;

                Para.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
                Para.FeatureSetValue = ((P_SENSOR_SCENE_ENHANCE_STRUCT)In)->SceneContrast;
                OV2655Contrast(&Para,NULL);
                Para.FeatureSetValue = ((P_SENSOR_SCENE_ENHANCE_STRUCT)In)->SceneSaturation;
                OV2655Saturation(&Para,NULL);
                Para.FeatureSetValue = ((P_SENSOR_SCENE_ENHANCE_STRUCT)In)->SceneSharpness;
                OV2655Sharpness(&Para,NULL);
            }
            break;
        #endif


        /* Get Info series */
        case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
            OV2655GetSensorInfo((P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT)Out);
            break;
        case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
            ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = OV2655DetectSensorId();
            break;
        case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
            ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = OV2655Sensor.Fps;
            break;
        case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
            OV2655InitOperationPara((P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT)Out);
            break;
        case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
            CamGetHWInfo(OV2655Sensor.SensorIdx, Out);
            break;
        case IMAGE_SENSOR_FEATURE_GET_DSC_SUPPORT_INFO:
            OV2655DscSupportInfo((P_IMAGE_SENSOR_GET_DSC_SUPPORT_INFO_STRUCT)Out);
            break;

        /* Set Para series */
        case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
            OV2655Sensor.NvramData = &(((nvram_camera_para_struct *)In)->SENSOR);
            break;
        case IMAGE_SENSOR_FEATURE_VSYNC_HISR_INFORM_FRAME_TIME:
            //TmpFrameRate = ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
            break;
        case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
            OV2655Sensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
            break;
        case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
            break;
        case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
            OV2655Sensor.BypassAe = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
            OV2655AEEnable(OV2655Sensor.BypassAe ? KAL_FALSE : KAL_TRUE);
            break;
        case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
            OV2655Sensor.BypassAwb = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
            OV2655AWBEnable(OV2655Sensor.BypassAwb ? KAL_FALSE : KAL_TRUE);
            break;
        #if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
        case CAL_FEATURE_CAMERA_SENOSR_OUTPUT_TEST_PATTERN:
            OV2655Sensor.OutTestPattern = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
            break;
        case CAL_FEATURE_CAMERA_GET_TEST_PATTERN:
            ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = (kal_uint32) CATSTestPattern;
            break;
        #endif
        default:
            ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
            break;
    }
    return ErrCode;
}

/*************************************************************************
* FUNCTION
*    OV2655SensorCtrl
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
static MM_ERROR_CODE_ENUM OV2655SensorCtrl(CAL_SCENARIO_ENUM id, void *In, void *Out, kal_uint32 out_len, kal_uint32 *pRealParaOutLen)
{
    switch (id)
    {
        case CAL_SCENARIO_CAMERA_PREVIEW:
        case CAL_SCENARIO_VIDEO:
        case CAL_SCENARIO_WEBCAM_PREVIEW:
        case CAL_SCENARIO_WEBCAM_CAPTURE: OV2655Preview(id, In, Out); break;
        case CAL_SCENARIO_CAMERA_STILL_CAPTURE: OV2655Capture(id, In, Out); break;
      #ifdef __ZERO_SHUTTER_DELAY_SUPPORT__
        case CAL_SCENARIO_CAMERA_ZSD_PREVIEW:
            OV2655FullPreview(id,In,Out);
            break;
      #endif
        default: break;
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV2655SensorClose
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
static MM_ERROR_CODE_ENUM OV2655SensorClose(void)
{
    CisModulePowerOn(OV2655Sensor.SensorIdx, KAL_FALSE);
    CameraSccbClose(CAMERA_SCCB_SENSOR);
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    OV2655SensorFunc
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
MM_ERROR_CODE_ENUM OV2655SensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
    static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncOV2655=
    {
        OV2655SensorOpen,
        OV2655SensorFeatureCtrl,
        OV2655SensorCtrl,
        OV2655SensorClose,
    };

    *pfSensorFunc = &ImageSensorFuncOV2655;

    return MM_ERROR_NONE;
}



#ifdef __OV2655_DEBUG_TRACE__

#include "kbd_table.h"
#include "keypad_sw.h"
#include "stack_ltlcom.h"
#include "dcl.h"
#include "cam_main.h"

#include "med_utility.h"

extern kal_bool             kbd_push_assert;
extern kbd_buffer_struct    kbd_buffer;

kal_uint8 CATS_curr_state = 0;      // 0 - Idle
DCL_HANDLE AT_Camera_hdl=NULL;


static void CATS_kbd_push_onekey(kbd_event event,kal_uint8 key)
{
    ASSERT(kbd_push_assert == KAL_FALSE);
    kbd_push_assert = KAL_TRUE;
    kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_windex].Keyevent = event;
    kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_windex].Keydata[0] = key;
    //kbd_push_time_stamp();
    kbd_buffer.kbd_data_buffer_windex++;
    kbd_buffer.kbd_data_buffer_windex &= (kbd_buffer_size-1);
    kbd_push_assert = KAL_FALSE;
}


void CATS_press_one_key(kal_uint32 key_code)
{
    ilm_struct  *Kp_ilm = NULL;

    CATS_kbd_push_onekey(kbd_onekey_press, key_code);
    DRV_BuildPrimitive(Kp_ilm,
                       MOD_DRVKBD,
                       MOD_UEM,
                       MSG_ID_DRVUEM_KEYPAD_IND,
                       NULL);
    msg_send_ext_queue(Kp_ilm);

    CATS_kbd_push_onekey(kbd_onekey_release, key_code);
    DRV_BuildPrimitive(Kp_ilm,
                       MOD_DRVKBD,
                       MOD_UEM,
                       MSG_ID_DRVUEM_KEYPAD_IND,
                       NULL);
    msg_send_ext_queue(Kp_ilm);
}

void CATS_Callback(void *args)
{
    static kal_uint8 idx = 3;
    SGPT_CTRL_START_T start;

    switch (CATS_curr_state)
    {
        case 0:     // Idle screen state.
            CATS_press_one_key(DEVICE_KEY_SK_LEFT);
            CATS_press_one_key(DEVICE_KEY_RIGHT);
            CATS_press_one_key(DEVICE_KEY_SK_LEFT);
            CATS_press_one_key(DEVICE_KEY_DOWN);
            CATS_press_one_key(DEVICE_KEY_SK_LEFT);
            idx = 3;
            CATS_curr_state = 1;
            break;
        case 1:     // Preview state
            CATS_press_one_key(DEVICE_KEY_MENU);
            idx = 3;
            CATS_curr_state = 2;
            break;
        case 2:     // Capture state
            CATS_press_one_key(DEVICE_KEY_END);
            idx = 3;
            CATS_curr_state = 0;
            break;
        case 3:     // Error state
            CATS_press_one_key(DEVICE_KEY_END);
            idx = 5;
            CATS_curr_state = 0;
            break;

    }

    start.u2Tick=(idx*100);
    start.pfCallback=CATS_Callback;
    start.vPara=NULL;
    DclSGPT_Control(AT_Camera_hdl,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
}

static kal_bool OV2655AtGetValue(char *Str, kal_uint32 *Data)
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
    kal_uint32 Data[60];

    if (!OV2655AtGetValue(Str, Data))
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

                OV2655_TRACE("Current Frame Rate: %d.%d fps", IspCurrentFrameRate / 10, IspCurrentFrameRate % 10);
            }
            break;
        case 0x02:
            OV2655_TRACE("Read BB Reg[%x] = %x", Data[2], DRV_Reg32(Data[2]));
            break;
        case 0x03:
            DRV_Reg32(Data[2]) = Data[3];
            OV2655_TRACE("Write BB Reg[%x] = %x", Data[2], DRV_Reg32(Data[2]));
            break;
        case 0x04:
            OV2655_TRACE("Read Sensor Reg[%x] = %x", Data[2], CamReadCmosSensor(Data[2]));
            break;
        case 0x05:
            CamWriteCmosSensor(Data[2], Data[3]);
            OV2655_TRACE("Write Sensor Reg[%x] = %x", Data[2], CamReadCmosSensor(Data[2]));
            break;
        case 0x06:
            CamWriteCmosSensor(Data[2], Data[3]);
            OV2655_TRACE("Read Sensor Reg[%x:%x] = %x", Data[3], Data[4], CamReadCmosSensor(Data[4]));
            break;
        case 0x07:
            CamWriteCmosSensor(Data[2], Data[3]);
            CamWriteCmosSensor(Data[4], Data[5]);
            CamWriteCmosSensor(Data[2], Data[3]);
            OV2655_TRACE("Write Sensor Reg[%x:%x] = %x", Data[3], Data[4], CamReadCmosSensor(Data[4]));
            break;
        case 0x08:
        {
            SGPT_CTRL_START_T start;
            AT_Camera_hdl = DclSGPT_Open(DCL_GPT_CB,0);

            OV2655_TRACE("CATS start...");

            start.u2Tick=300;
            start.pfCallback=CATS_Callback;
            start.vPara=NULL;
            DclSGPT_Control(AT_Camera_hdl,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
            break;
        }
        case 0x09:
        {
            DclSGPT_Control(AT_Camera_hdl,SGPT_CMD_STOP,0);

            DclSGPT_Close(&AT_Camera_hdl);
            AT_Camera_hdl = NULL;

            OV2655_TRACE("CATS stop!!!");
        }
        break;
        case 0x0A:
            {
                kal_uint32 i;

                for (i = 0; i < Data[3]; i++)
                {
                    OV2655_TRACE("Read Sensor Reg[%x] = %x", Data[2] + i, CamReadCmosSensor(Data[2] + i));
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
                    OV2655_TRACE("Read BB Reg[%x] = %x", Data[2] + i * 4, DRV_Reg32(Data[2] + i * 4));
                    if (!(i % 200))
                    {
                        kal_sleep_task(30);
                    }
                }
            }
            break;
    #if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
        case 0x0C:                                  /* Get Sensor Id */
            {
                MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;
                kal_uint32 sensor_id;
                ret = CATSInit(0);
                if (MM_ERROR_NONE != ret)
                {
                    return KAL_FALSE;
                }
                ret = CATSFeatureCtrl(CATS_FEATURE_GET_SENSOR_ID, NULL, &sensor_id);
                CATSDeinit();
            }
            break;
        case 0x0D:                                  /* Get Test Pattern */
            {
                MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;
                cats_frame_buff_st test_pattern = {0};
                cats_compare_result_st comp_result = {0};
                ret = CATSInit(0);
                if (MM_ERROR_NONE != ret)
                {
                    return KAL_FALSE;
                }

                ret = CATSFeatureCtrl(CATS_FEATURE_GET_PATTERN_FORMAT, NULL, &(test_pattern.color_format));
                test_pattern.frame_width = 40;
                test_pattern.frame_height = 30;

                test_pattern.frame_buffer_size = test_pattern.frame_width * test_pattern.frame_height * 2;
                test_pattern.frame_buffer = (kal_uint32) med_alloc_asm_mem(0, test_pattern.frame_buffer_size);
                if (NULL == test_pattern.frame_buffer)
                {
                    CATSDeinit();

                    return KAL_FALSE;
                }

                ret = CATSFeatureCtrl(CATS_FEATURE_GET_TEST_PATTERN, &test_pattern, NULL);

                if (MM_ERROR_NONE == ret)
                {
                    //if (need_target_compare)
                    {
                        /* Error Ratio is represent with percent, and 10 means 10%, range is 0% to 100% */
                        test_pattern.err_ratio_threshold = 1;
                        ret = CATSFeatureCtrl(CATS_FEATURE_COMPARE_TEST_PATTERN, &test_pattern, &comp_result);
                        OV2655_TRACE("[Compare] ret = %d, err_ratio = %d, err_pattern_cnt=%d, pattern_size=%d", \
                                ret, comp_result.err_ratio, comp_result.err_pattern_cnt, comp_result.pattern_size);
                        if (MM_ERROR_NONE == ret)
                        {
                            /* Successeed, the pattern from sensor is same with stored pattern. */
                        }
                        else
                        {
                            /* Compare the test pattern failed. */
                        }
                    }
                }
                else
                {
                    /* Get the test pattern failed, Do the error handler */
                }

                CATSDeinit();

                med_free_asm_mem(0, (void **)&test_pattern.frame_buffer);

                return KAL_TRUE;
            }
            break;
    #endif  /* #if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__)) */
        default:
            break;
    }
    return KAL_TRUE;
}

#endif  /* #ifdef __OV2655_DEBUG_TRACE__ */



