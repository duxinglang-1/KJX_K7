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
 *   lens_module.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   A Lens module device driver control interface
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "stdio.h"
#include "string.h"
#include "drv_comm.h"
#include "IntrCtrl.h"
#include "reg_base.h"
#include "gpio_sw.h"
#include "isp_if.h"
#include "image_sensor.h"
#include "camera_para.h"
#include "lens_module.h"
#include "sccb.h"

#if (defined(AF_SUPPORT))
#include "af.h"

#define ACME_900_0043_00_OV3640_AD5398_Lens_I2C_DELAY  (0x0F)

#define ACME_900_0043_00_OV3640_AD5398_AD5398_WRITE_ID (0x18)
#define ACME_900_0043_00_OV3640_AD5398_AD5398_READ_ID  (0x19)
    
#define AF_LENS_TEST

//kal_uint16 g_curr_pos, g_home_pos, g_macro_pos;

typedef struct {
	kal_uint32	pos;	
	kal_uint32	distance;
} af_step_struct;


typedef struct
{
   	kal_uint32		Step_no;
	af_step_struct		AF[32];	
}camera_lens_run_struct;

#if (!defined(DRV_ISP_6238_SERIES))
#define LENS_SCALING    (1024 / 130.0f)
float lens_step_scaling = LENS_SCALING;
camera_lens_run_struct camera_lens_step = {
    {17},
    {
        {(kal_uint32) (0 * LENS_SCALING), 250},    {(kal_uint32) (6 * LENS_SCALING), 0x00},   {(kal_uint32) (12 * LENS_SCALING), 0x00},  {(kal_uint32) (18 * LENS_SCALING), 0x00},
        {(kal_uint32) (26 * LENS_SCALING), 0x00},  {(kal_uint32) (34 * LENS_SCALING), 0x00},  {(kal_uint32) (42 * LENS_SCALING), 0x00},  {(kal_uint32) (50 * LENS_SCALING), 0x00},
        {(kal_uint32) (58 * LENS_SCALING), 0x00},  {(kal_uint32) (66 * LENS_SCALING), 0x00},  {(kal_uint32) (74 * LENS_SCALING), 0x00},  {(kal_uint32) (82 * LENS_SCALING), 0x00},
        {(kal_uint32) (90 * LENS_SCALING), 0x00},  {(kal_uint32) (98 * LENS_SCALING), 0x00},  {(kal_uint32) (106 * LENS_SCALING), 0x00}, {(kal_uint32) (114 * LENS_SCALING), 0x00},
        {(kal_uint32) (130 * LENS_SCALING), 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00},
        {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00},
        {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00},
        {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}
    }
};

camera_lens_timing_struct camera_lens_timing={
    {8}, {2},
    {
        {(kal_uint32) (66 * LENS_SCALING), 3277},  {(kal_uint32) (33 * LENS_SCALING), 1639},
        {(kal_uint32) (17 * LENS_SCALING), 820},   {(kal_uint32) (9 * LENS_SCALING), 410},
        {(kal_uint32) (5 * LENS_SCALING), 205},    {(kal_uint32) (4 * LENS_SCALING), 103}, 
        {(kal_uint32) (2 * LENS_SCALING), 52},     {(kal_uint32) (1 * LENS_SCALING), 26},
        {0x00, 0x00},   {0x00, 0x00},
        {0x00, 0x00},   {0x00, 0x00}
    }
};
#else
camera_lens_timing_struct ACME_900_0043_00_OV3640_AD5398_camera_lens_timing={
	{2}, {2},
	{
		{16, 1312}, {4, 656},
		{0x00, 0x00}, {0x00, 0x00}, 
		{0x00, 0x00}, {0x00, 0x00},
		{0x00, 0x00}, {0x00, 0x00}, 
		{0x00, 0x00}, {0x00, 0x00}, 
		{0x00, 0x00}, {0x00, 0x00}
	}
};
#endif

//extern kal_uint8 PWM2_flag;
#if(defined(DRV_ISP_6238_SERIES))
extern kal_uint8 PWM_no;
extern void PWM_Set_Duty(kal_uint8 owner, kal_uint32 pwm_num, kal_uint16 duty);
#endif

#define ACME_900_0043_00_OV3640_AD5398_Lens_I2C_START_TRANSMISSION \
{ \
    volatile kal_uint8 iI; \
    SET_SCCB_CLK_OUTPUT; \
    SET_SCCB_DATA_OUTPUT; \
    SET_SCCB_CLK_HIGH; \
    SET_SCCB_DATA_HIGH; \
    for(iI = 0; iI < ACME_900_0043_00_OV3640_AD5398_Lens_I2C_DELAY; iI++);\
    SET_SCCB_DATA_LOW; \
    for(iI = 0; iI < ACME_900_0043_00_OV3640_AD5398_Lens_I2C_DELAY; iI++);\
    SET_SCCB_CLK_LOW; \
}

#define ACME_900_0043_00_OV3640_AD5398_Lens_I2C_STOP_TRANSMISSION \
{ \
    volatile kal_uint8 iI; \
    SET_SCCB_CLK_OUTPUT; \
    SET_SCCB_DATA_OUTPUT; \
    SET_SCCB_CLK_LOW; \
    SET_SCCB_DATA_LOW; \
    for(iI = 0; iI < ACME_900_0043_00_OV3640_AD5398_Lens_I2C_DELAY; iI++);\
    SET_SCCB_CLK_HIGH; \
    for(iI = 0; iI < ACME_900_0043_00_OV3640_AD5398_Lens_I2C_DELAY; iI++);\
    SET_SCCB_DATA_HIGH; \
}

void ACME_900_0043_00_OV3640_AD5398_Lens_SCCB_send_byte(kal_uint8 iByte)
{
    signed char iI;
    volatile kal_uint8 iJ;

    SET_SCCB_DATA_OUTPUT;
    for (iI = 7; iI >= 0; iI--) {  /* data bit 7~0 */
        if (iByte & (1 << iI)) {
            SET_SCCB_DATA_HIGH;
        }else {
            SET_SCCB_DATA_LOW;
        }
        for (iJ = 0; iJ < ACME_900_0043_00_OV3640_AD5398_Lens_I2C_DELAY; iJ++);
        SET_SCCB_CLK_HIGH;
        for (iJ = 0; iJ < ACME_900_0043_00_OV3640_AD5398_Lens_I2C_DELAY; iJ++);
        SET_SCCB_CLK_LOW;
    }

    /*  9th bit, don't care  */
    SET_SCCB_DATA_LOW;
    SET_SCCB_DATA_INPUT;
    for (iJ = 0; iJ < ACME_900_0043_00_OV3640_AD5398_Lens_I2C_DELAY; iJ++);
    SET_SCCB_CLK_HIGH;
    for (iJ = 0; iJ < ACME_900_0043_00_OV3640_AD5398_Lens_I2C_DELAY; iJ++);
    SET_SCCB_CLK_LOW;
    for (iJ = 0; iJ < ACME_900_0043_00_OV3640_AD5398_Lens_I2C_DELAY; iJ++);
}   /*  Lens_SCCB_send_byte() */

kal_uint8 ACME_900_0043_00_OV3640_AD5398_Lens_SCCB_get_byte(void)
{
    volatile signed char iI;
    volatile kal_uint8 iJ;
    kal_uint8 iGet_byte = 0;

	SET_SCCB_DATA_INPUT;

	for (iI = 7; iI >= 0; iI--) {   /*  data bit 7~0 */
        SET_SCCB_CLK_HIGH;
        for (iJ = 0; iJ < ACME_900_0043_00_OV3640_AD5398_Lens_I2C_DELAY; iJ++);
        if (GET_SCCB_DATA_BIT) {
            iGet_byte |= (1 << iI);
        }
        SET_SCCB_CLK_LOW;
        for (iJ = 0; iJ < ACME_900_0043_00_OV3640_AD5398_Lens_I2C_DELAY; iJ++);
    }

    /*  9th bit, don't care  */
    SET_SCCB_DATA_LOW;
    SET_SCCB_DATA_INPUT;
    for (iJ = 0; iJ < ACME_900_0043_00_OV3640_AD5398_Lens_I2C_DELAY; iJ++);
    SET_SCCB_CLK_HIGH;
    for (iJ = 0; iJ < ACME_900_0043_00_OV3640_AD5398_Lens_I2C_DELAY; iJ++);
    SET_SCCB_CLK_LOW;
    for (iJ = 0; iJ < ACME_900_0043_00_OV3640_AD5398_Lens_I2C_DELAY; iJ++);

	return iGet_byte;
}	/*  Lens_SCCB_get_byte()    */

void ACME_900_0043_00_OV3640_AD5398_write_lens_reg(const kal_uint8 iMSB, const kal_uint8 iLSB)
{
    #ifdef HW_SCCB
    #else
        ACME_900_0043_00_OV3640_AD5398_Lens_I2C_START_TRANSMISSION;
        ACME_900_0043_00_OV3640_AD5398_Lens_SCCB_send_byte(ACME_900_0043_00_OV3640_AD5398_AD5398_WRITE_ID);
        ACME_900_0043_00_OV3640_AD5398_Lens_SCCB_send_byte(iMSB);
        ACME_900_0043_00_OV3640_AD5398_Lens_SCCB_send_byte(iLSB);
        ACME_900_0043_00_OV3640_AD5398_Lens_I2C_STOP_TRANSMISSION;
	#endif /* HW_SCCB */
}   /*  write_lens_reg() */

kal_uint32 ACME_900_0043_00_OV3640_AD5398_read_lens_reg(void)
{
    kal_uint8 iMSB, iLSB;
    kal_uint32 iValue = 0;

    #ifdef HW_SCCB
	#else
        ACME_900_0043_00_OV3640_AD5398_Lens_I2C_START_TRANSMISSION;
        ACME_900_0043_00_OV3640_AD5398_Lens_SCCB_send_byte(ACME_900_0043_00_OV3640_AD5398_AD5398_READ_ID);
        iMSB = ACME_900_0043_00_OV3640_AD5398_Lens_SCCB_get_byte();
        ACME_900_0043_00_OV3640_AD5398_Lens_SCCB_get_byte();   // don't care byte
        ACME_900_0043_00_OV3640_AD5398_Lens_I2C_STOP_TRANSMISSION;
        ACME_900_0043_00_OV3640_AD5398_Lens_I2C_START_TRANSMISSION;
        ACME_900_0043_00_OV3640_AD5398_Lens_SCCB_send_byte(ACME_900_0043_00_OV3640_AD5398_AD5398_READ_ID);
       	iLSB = ACME_900_0043_00_OV3640_AD5398_Lens_SCCB_get_byte();
        ACME_900_0043_00_OV3640_AD5398_Lens_SCCB_get_byte();    // don't care byte
        ACME_900_0043_00_OV3640_AD5398_Lens_I2C_STOP_TRANSMISSION;
    #endif

    iValue = (iMSB << 8) | iLSB;

    return iValue;
}   /*  read_lens_reg() */

/*************************************************************************
* FUNCTION
*************************************************************************/
void ACME_900_0043_00_OV3640_AD5398_Lens_AF_Set_Para(const kal_uint32 iValue)
{
    //---------------------------------------------------------------------------------
    //  Data Format
    //        Serial Data-Words          High Byte       |      Low Byte
    //                            PD X D9 D8 D7 D6 D5 D4 | D3 D2 D1 D0 X X X X
    // PD = 1, enable power down mode, otherwise wake up mode
    // D[9:0] = 10-bit ADC value
    //---------------------------------------------------------------------------------
    const kal_uint8 iMSB = (kal_uint8) (0x00 | (iValue >> 4));
    const kal_uint8 iLSB = (kal_uint8) ((iValue & 0x0F) << 4);

    ASSERT(iValue < 1024);

    ACME_900_0043_00_OV3640_AD5398_write_lens_reg(iMSB, iLSB);
}   /*  Lens_AF_Set_Para    */

void ACME_900_0043_00_OV3640_AD5398_set_step(kal_uint32 iDuty)
{
	kal_prompt_trace(MOD_ENG, "Set_step:%x, %d", iDuty, iDuty);
	
    if (iDuty < g_macro_pos) {
        ACME_900_0043_00_OV3640_AD5398_Lens_AF_Set_Para(iDuty);
    }else{
        ACME_900_0043_00_OV3640_AD5398_Lens_AF_Set_Para(g_macro_pos);
    }
}

/*************************************************************************
* FUNCTION
*	AF_Lens_Init
*
* DESCRIPTION
*	This function initialize the vcm comtrol IO
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
kal_int8 ACME_900_0043_00_OV3640_AD5398_AF_Lens_Init(void)
{	
#if (!defined(DRV_ISP_6238_SERIES))	
		extern const nvram_camera_3a_struct CAMERA_3A_DEFAULT_VALUE;

    /* init af status and pos */
    g_home_pos = CAMERA_3A_DEFAULT_VALUE.AF.table_info[0].table_range.af_me_home_pos;
    g_macro_pos= CAMERA_3A_DEFAULT_VALUE.AF.table_info[0].table_range.af_me_macro_pos;
    g_curr_pos = g_home_pos;   
	/* init af status and pos */
/*	
	g_home_pos = camera_lens.AF[camera_lens.INFO.af_home_idx].pos;
	g_home_pos= camera_lens.AF[camera_lens.INFO.af_macro_idx].pos;
	g_curr_pos = g_home_pos;	
*/	
#else
	/* init af status and pos */
	g_home_pos = camera_3a.AF.table_info[0].table_step[camera_3a.AF.table_info[0].table_range.af_home_idx].pos;
	g_home_pos= camera_3a.AF.table_info[0].table_step[camera_3a.AF.table_info[0].table_range.af_macro_idx].pos;	
	g_curr_pos = g_home_pos;		
#endif	
	/* Load module calibration data if existed */
	/* ... */
	return 1;
}	/* lens_init() */
/*************************************************************************
* FUNCTION
*	AF_Lens_PowerOn
*
* DESCRIPTION
*	This function is to turn on VCM AF lens power.
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
void ACME_900_0043_00_OV3640_AD5398_AF_Lens_PowerOn(void)
{
    lens_af_power_on(KAL_TRUE); // power on AF lens module

    {
        kal_uint8 iMSB, iLSB;

        #ifdef AF_LENS_TEST
        {
            kal_uint16 iI, iValue;

            for (iI = 0; iI < 1024; iI++) {
                iMSB = 0x00 | ( iI >> 4);
                iLSB = (iI << 4) & 0xF0;
                ACME_900_0043_00_OV3640_AD5398_write_lens_reg(iMSB, iLSB);
                iValue = ACME_900_0043_00_OV3640_AD5398_read_lens_reg();
                if (iValue != ((iMSB << 8) | iLSB)) {
                    return;
                }
            }
        }
        #endif

        iMSB = 0x00 | (g_curr_pos >> 4);
        iLSB = (g_curr_pos << 4) & 0xF0;
        ACME_900_0043_00_OV3640_AD5398_write_lens_reg(iMSB, iLSB);
    }

    ACME_900_0043_00_OV3640_AD5398_write_lens_reg(0, 0);
    ACME_900_0043_00_OV3640_AD5398_set_step(g_curr_pos);
}   /*  AF_Lens_PowerOn   */

/*************************************************************************
* FUNCTION
*	AF_Lens_PowerOff
*
* DESCRIPTION
*	This function is to turn off VCF AF lens power.
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
void ACME_900_0043_00_OV3640_AD5398_AF_Lens_PowerOff(void)
{
    kal_uint16 reg_value_H, reg_value_L;
    g_curr_pos = g_home_pos;
    ACME_900_0043_00_OV3640_AD5398_set_step(g_curr_pos);	

    reg_value_H = (0x80 | (g_curr_pos >> 4));
    reg_value_L = ((g_curr_pos << 4) & 0xF0);
    ACME_900_0043_00_OV3640_AD5398_write_lens_reg(reg_value_H, reg_value_L);
    lens_af_power_on(KAL_FALSE);
}   /*  AF_Lens_PowerOff  */

/*************************************************************************
* FUNCTION
*	AF_Lens_Standby
*
* DESCRIPTION
*	This function is to let VCM AF lens stand by.
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
void ACME_900_0043_00_OV3640_AD5398_AF_Lens_Standby(void)
{
}   /*  AF_Lens_Standby */

/*************************************************************************
* FUNCTION
*	AF_Get_Lens_ID
*
* DESCRIPTION
*	This function return the VCM ID
*
* PARAMETERS
*	*lens_id : address pointer of VCM ID
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void ACME_900_0043_00_OV3640_AD5398_AF_Get_Lens_ID(kal_uint8 *lens_id)
{
}	/* AF_Get_Lens_ID() */

/*************************************************************************
* FUNCTION
*	AF_Lens_Home_Check
*
* DESCRIPTION
*	This function is to check if lens stay at home position
*
* PARAMETERS
*	NONE
*
* RETURNS
*	KAL_TRUE/KAL_FALSE.
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint8 ACME_900_0043_00_OV3640_AD5398_AF_Lens_Home_Check(void)
{
    return  g_curr_pos == g_home_pos;
}   /*  AF_Lens_Home_Check  */

/*************************************************************************
* FUNCTION
*	AF_Get_Lens_Current_Position
*
* DESCRIPTION
*	This function is to get lens parameter
*
* PARAMETERS
*	NONE
*
* RETURNS
*	get current lens position
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 ACME_900_0043_00_OV3640_AD5398_AF_Get_Lens_Current_Position(void)
{
    return g_curr_pos;
}   /*  AF_Get_Lens_Current_Position    */

/*************************************************************************
* FUNCTION
*	AF_Lens_Step_CW
*
* DESCRIPTION
*	This function is to move lens cw number steps, go infinite
*
* PARAMETERS
*	set lens cw move steps
*
* RETURNS
*	NONE
*
* GLOBALS AFFECTED
*
*************************************************************************/
void ACME_900_0043_00_OV3640_AD5398_AF_Lens_Step_CW(kal_uint32 iNum)
{
    if ((g_curr_pos + iNum) < g_macro_pos) {
      g_curr_pos += iNum;
    }else {
        g_curr_pos = g_macro_pos;
    }

    ACME_900_0043_00_OV3640_AD5398_set_step(g_curr_pos);
}   /*  AF_Lens_Step_CW()   */

/*************************************************************************
* FUNCTION
*	AF_Lens_Step_CCW
*
* DESCRIPTION
*	This function is to move lens ccw number steps, go macro
*
* PARAMETERS
*	set lens ccw move steps
*
* RETURNS
*	NONE
*
* GLOBALS AFFECTED
*
*************************************************************************/
void ACME_900_0043_00_OV3640_AD5398_AF_Lens_Step_CCW(kal_uint32 iNum)
{
    if (g_curr_pos >= iNum) {
        g_curr_pos -= iNum;
	}else {
        g_curr_pos = g_home_pos;
    }

   ACME_900_0043_00_OV3640_AD5398_set_step(g_curr_pos);
}   /*  AF_Lens_Step_CCW    */

/*************************************************************************
* FUNCTION
*	AF_Lens_MoveTo
*
* DESCRIPTION
*	This function is to move lens to target pos
*
* PARAMETERS
*	set lens move to target pos
*
* RETURNS
*	NONE
*
* GLOBALS AFFECTED
*
*************************************************************************/
void ACME_900_0043_00_OV3640_AD5398_AF_Lens_MoveTo(kal_int32 iTarget_Pos)
{
    g_curr_pos = iTarget_Pos;

    if (iTarget_Pos > g_macro_pos) {
		g_curr_pos = g_macro_pos;
    }

    ACME_900_0043_00_OV3640_AD5398_set_step(g_curr_pos);
}   /*  AF_Lens_MoveTo  */

/*************************************************************************
* FUNCTION
*	AF_Get_Lens_Status
*
* DESCRIPTION
*	This function is to get current lens status
*
* PARAMETERS
*	NONE
*
* RETURNS
*	lens status
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint8 ACME_900_0043_00_OV3640_AD5398_AF_Get_Lens_Status(void)
{
    return AF_STATUS_READY;
}   /*  AF_Get_Lens_Status  */

/*************************************************************************
* FUNCTION
*	lens_func_map
*
* DESCRIPTION
*	vcm af module functions struct.
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
lens_func_struct ACME_900_0043_00_OV3640_AD5398_lens_func_map =
{
	ACME_900_0043_00_OV3640_AD5398_AF_Lens_Init,
	ACME_900_0043_00_OV3640_AD5398_AF_Lens_PowerOn,
	ACME_900_0043_00_OV3640_AD5398_AF_Lens_PowerOff,
	ACME_900_0043_00_OV3640_AD5398_AF_Lens_Standby,
	ACME_900_0043_00_OV3640_AD5398_AF_Get_Lens_ID,
	ACME_900_0043_00_OV3640_AD5398_AF_Lens_Home_Check,
	ACME_900_0043_00_OV3640_AD5398_AF_Get_Lens_Current_Position,
	ACME_900_0043_00_OV3640_AD5398_AF_Lens_Step_CW,
	ACME_900_0043_00_OV3640_AD5398_AF_Lens_Step_CCW,
	ACME_900_0043_00_OV3640_AD5398_AF_Lens_MoveTo,	
	ACME_900_0043_00_OV3640_AD5398_AF_Get_Lens_Status,
	0,									// lens_ms_open
	0,									// lens_ms_close
	0,									// get_lens_current_iris
	0									// lens_set_iris
};  /*  lens_func_pixelplus  */

kal_uint32 ACME_900_0043_00_OV3640_AD5398_get_lens_prefix_name(kal_char* buf){
	strcpy(buf, "FOXLINK_FM30AF_13_L1_MT9T012_MD115");
}

#endif

