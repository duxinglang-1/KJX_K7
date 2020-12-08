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
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "IntrCtrl.h"
#include "reg_base.h"
#include "gpio_sw.h"
#include "isp_if.h"
#include "isp_yuv_if.h"
#include "image_sensor.h"
#include "camera_para.h"
#include "upll_ctrl.h"
#include "med_api.h"
#include "sensor_common.h"
#ifndef SIV120B_DIRECT_HW_SCCB
#include "sccb.h"
#else
#include "sccb_v2.h"
#endif

#if defined(__CAMERA_NVRAM_REDUCTION__)
#ifndef SIV120B_DIRECT_CMMCLK_CURRENT_INDEX
#define SIV120B_DIRECT_CMMCLK_CURRENT_INDEX CMMCLK_CURRENT_INDEX
#endif
#ifndef SIV120B_DIRECT_ENGINEER_START_ADDR
#define SIV120B_DIRECT_ENGINEER_START_ADDR ENGINEER_START_ADDR
#endif
#ifndef SIV120B_DIRECT_ENGINEER_END_ADDR
#define SIV120B_DIRECT_ENGINEER_END_ADDR ENGINEER_END_ADDR
#endif
#ifndef SIV120B_DIRECT_FACTORY_START_ADDR
#define SIV120B_DIRECT_FACTORY_START_ADDR FACTORY_START_ADDR
#endif
#ifndef SIV120B_DIRECT_FACTORY_END_ADDR
#define SIV120B_DIRECT_FACTORY_END_ADDR FACTORY_END_ADDR
#endif
#ifndef SIV120B_DIRECT_CCT_END_ADDR
#define SIV120B_DIRECT_CCT_END_ADDR CCT_END_ADDR
#endif
#endif
#define SIV120B_DIRECT_DEBUG
#define SIV120B_DIRECT_PREVIEW_MODE 0
#define SIV120B_DIRECT_CAPTURE_MODE 1

/* Global Valuable */
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
#define SIV120B_DIRECT_SOURCE_CLK      52000000
#else
#define SIV120B_DIRECT_SOURCE_CLK      48000000
#endif
#define SIV120B_DIRECT_PCLK        (SIV120B_DIRECT_SOURCE_CLK / SIV120B_DIRECT_mclk_div)

static kal_uint8 cntr_a_driving = 0x50;
static kal_bool SIV120B_DIRECT_g_bNightMode = KAL_FALSE;
static kal_uint8 SIV120B_DIRECT_g_iBanding = CAM_BANDING_50HZ;
static kal_uint8 SIV120B_DIRECT_g_iAE_Meter = CAM_AE_METER_AUTO;
static kal_uint8 SIV120B_DIRECT_Control = 0x00;
static kal_uint16 SIV120B_DIRECT_Dummy_Pixel = 0x1c; // for user customization
static kal_uint16 SIV120B_DIRECT_Hblank = 0x1c;       //for calculating shutter step
static kal_bool SIV120B_DIRECT_Video_Mode = KAL_FALSE;
static kal_uint8 SIV120B_DIRECT_mclk_div = 8;//2 hunk
static kal_bool SIV120B_DIRECT_Mode_change = KAL_FALSE;
static kal_uint16 SIV120B_DIRECT_Min_Fps_Normal;
static kal_uint16 SIV120B_DIRECT_Min_Fps_Night;

/* direct sensor v2 */
SEC_SENSOR_SET_PARA_STRUCT sensor_para_set;


#if (defined(DRV_ISP_6238_SERIES)||defined(DRV_ISP_6235_SERIES))
static kal_uint8 SIV120B_DIRECT_pshutter_step = 0x64;
static kal_uint8 SIV120B_DIRECT_cshutter_step = 0x3e;
#endif


/* MAX/MIN Explosure Lines Used By AE Algorithm */
kal_uint16 SIV120B_DIRECT_MAX_EXPOSURE_LINES = 1000;   // must be defined but not referenced by YUV driver
kal_uint8  SIV120B_DIRECT_MIN_EXPOSURE_LINES = 1;  // must be defined but not referenced by YUV driver

static void SIV120B_DIRECT_OutputFormat(SIV120B_DIRECT_OUTPUT_SIZE para);

extern void yuv_wait_one_vd_done(void);
#ifdef SIV120B_DIRECT_HW_SCCB
extern void i2c_set_get_handle_wait(SCCB_OWNER owner,kal_bool enable);
extern void i2c_set_slave_address(SCCB_OWNER owner,kal_uint8 slave_address);
extern kal_uint32 i2c_set_transaction_mode(SCCB_OWNER owner,SCCB_TRANSACTION_MODE mode,SCCB_SPEED_ENUM speed);
#endif

#ifndef SIV120B_DIRECT_HW_SCCB
/*************************************************************************
* FUNCTION
*    SIV120B_DIRECT_SCCB_send_byte
*
* DESCRIPTION
*    This function send data to I2C
*
* PARAMETERS
*    send_byte    : 8bit data send to I2C
*
* RETURNS
*    1    : send fail
*    0    : send success
*
* GLOBALS AFFECTED
*
*************************************************************************/
static kal_uint8 SIV120B_DIRECT_SCCB_send_byte(kal_uint8 send_byte)
{
  volatile signed char i;
  volatile kal_uint32 j;
  kal_uint8 ack;

  for (i = 7; i >= 0; i--)
  {
    if (send_byte&(1 << i))
    {
      SET_SCCB_DATA_HIGH;
    }
    else
    {
      SET_SCCB_DATA_LOW;
    }
    for (j = 0; j < SIV120B_DIRECT_SENSOR_I2C_DELAY; j++);
    SET_SCCB_CLK_HIGH;
    for (j = 0; j < SIV120B_DIRECT_SENSOR_I2C_DELAY; j++);
    SET_SCCB_DATA_OUTPUT; /* only for delay */
    for (j = 0; j < SIV120B_DIRECT_SENSOR_I2C_DELAY; j++);
    SET_SCCB_CLK_LOW;
    for (j = 0; j < SIV120B_DIRECT_SENSOR_I2C_DELAY; j++);
  }
  SET_SCCB_DATA_INPUT;
  for (j = 0; j < SIV120B_DIRECT_SENSOR_I2C_DELAY; j++);
  SET_SCCB_CLK_HIGH;
  for (j = 0; j < SIV120B_DIRECT_SENSOR_I2C_DELAY; j++);
  ack = GET_SCCB_DATA_BIT;
  for (j = 0; j < SIV120B_DIRECT_SENSOR_I2C_DELAY; j++);
  SET_SCCB_CLK_LOW;
  for (j = 0; j < SIV120B_DIRECT_SENSOR_I2C_DELAY; j++);
  SET_SCCB_DATA_OUTPUT;

  return ack;
}

/*************************************************************************
* FUNCTION
*    SIV120B_DIRECT_SCCB_get_byte
*
* DESCRIPTION
*    This function read 8bit data from I2C
*
* PARAMETERS
*    None
*
* RETURNS
*    8bit data read from I2C
*
* GLOBALS AFFECTED
*
*************************************************************************/
static kal_uint8 SIV120B_DIRECT_SCCB_get_byte(void)
{
  volatile signed char i;
  volatile kal_uint32 j;
  kal_uint8 get_byte = 0;

  for (i = 7; i >= 0; i--)
  {
    SET_SCCB_DATA_INPUT;
    for (j = 0; j < SIV120B_DIRECT_SENSOR_I2C_DELAY; j++);
    SET_SCCB_CLK_HIGH;
    for (j = 0; j < SIV120B_DIRECT_SENSOR_I2C_DELAY; j++);
    if (GET_SCCB_DATA_BIT) get_byte |= (1 << i);
    for (j = 0; j < SIV120B_DIRECT_SENSOR_I2C_DELAY; j++);
    SET_SCCB_CLK_LOW;
    for (j = 0; j < SIV120B_DIRECT_SENSOR_I2C_DELAY; j++);
  }
  SET_SCCB_DATA_HIGH;
  SET_SCCB_DATA_OUTPUT;
  for (j = 0;j < SIV120B_DIRECT_SENSOR_I2C_DELAY; j++);
  SET_SCCB_CLK_HIGH;
  for (j = 0;j < SIV120B_DIRECT_SENSOR_I2C_DELAY; j++);
  SET_SCCB_DATA_OUTPUT; /* only for delay */
  for (j = 0;j < SIV120B_DIRECT_SENSOR_I2C_DELAY; j++);
  SET_SCCB_CLK_LOW;
  for (j = 0;j < SIV120B_DIRECT_SENSOR_I2C_DELAY; j++);

  return get_byte;
}
#endif

/*************************************************************************
* FUNCTION
*    SIV120B_DIRECT_write_cmos_sensor
*
* DESCRIPTION
*    This function wirte data to CMOS sensor through I2C
*    SIV120B_DIRECT_MAX_I2C_FAIL_TRY_NO is the max try number. when write fail, the function retry again until
*    try times reach SIV120B_DIRECT_MAX_I2C_FAIL_TRY_NO.
*
* PARAMETERS
*    addr    : the 8bit address of register
*    para    : the 8bit value of register
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void SIV120B_DIRECT_write_cmos_sensor(kal_uint8 addr, kal_uint8 para)
{
#ifndef SIV120B_DIRECT_HW_SCCB
  kal_uint8 fail_try_no = SIV120B_DIRECT_MAX_I2C_FAIL_TRY_NO + 1;

  while (--fail_try_no > 0)
  {
    SIV120B_DIRECT_I2C_START_TRANSMISSION;
    if (SIV120B_DIRECT_SCCB_send_byte(SIV120B_DIRECT_I2C_WRITE_ID)) continue;
    if (SIV120B_DIRECT_SCCB_send_byte(addr)) continue;
    if (SIV120B_DIRECT_SCCB_send_byte(para)) continue;
    break;
  }
  SIV120B_DIRECT_I2C_STOP_TRANSMISSION;
#ifdef SIV120B_DIRECT_DEBUG
  if (!fail_try_no) kal_wap_trace(MOD_ENG,TRACE_INFO, "I2C write %x, %x error", addr, para);
#endif
#else
  SCCB_TRANSACTION_RESULT rt;
  kal_uint8 out_buff[2];

  out_buff[0] = addr;
  out_buff[1] = para;
  rt = i2c_write(SCCB_OWNER_CAMERA, out_buff, sizeof(out_buff));
#ifdef SIV120B_DIRECT_DEBUG
  if (rt == SCCB_TRANSACTION_FAIL) kal_wap_trace(MOD_ENG,TRACE_INFO, "I2C write %x, %x error", addr, para);
#endif
#endif
}
/*************************************************************************
* FUNCTION
*    SIV120B_DIRECT_read_cmos_sensor
*
* DESCRIPTION
*    This function read data from CMOS sensor through I2C.
*    SIV120B_DIRECT_MAX_I2C_FAIL_TRY_NO is the max try number. when read fail, the function retry again until
*    try times reach SIV120B_DIRECT_MAX_I2C_FAIL_TRY_NO.
*
* PARAMETERS
*    addr    : the 8bit address of register
*
* RETURNS
*    8bit data read through I2C
*
* GLOBALS AFFECTED
*
*************************************************************************/
static kal_uint8 SIV120B_DIRECT_read_cmos_sensor(kal_uint8 addr)
{
#ifndef SIV120B_DIRECT_HW_SCCB
  kal_uint8 get_byte = 0xFF;
  kal_uint8 fail_try_no = SIV120B_DIRECT_MAX_I2C_FAIL_TRY_NO + 1;

  while (--fail_try_no > 0)
  {
    SIV120B_DIRECT_I2C_START_TRANSMISSION;
    if (SIV120B_DIRECT_SCCB_send_byte(SIV120B_DIRECT_I2C_WRITE_ID)) continue;
    if (SIV120B_DIRECT_SCCB_send_byte(addr)) continue;
    SIV120B_DIRECT_I2C_START_TRANSMISSION;
    if (SIV120B_DIRECT_SCCB_send_byte(SIV120B_DIRECT_I2C_READ_ID)) continue;
    get_byte = SIV120B_DIRECT_SCCB_get_byte();
    break;
  }
  SIV120B_DIRECT_I2C_STOP_TRANSMISSION;
#ifdef SIV120B_DIRECT_DEBUG
  if (!fail_try_no) kal_wap_trace(MOD_ENG,TRACE_INFO, "I2C read %x error", addr);
#endif
  return get_byte;
#else
  SCCB_TRANSACTION_RESULT rt;
  kal_uint8 in_buff[1] = {0xFF};
  kal_uint8 out_buff[1];

  out_buff[0] = addr;
  rt = i2c_write_and_read(SCCB_OWNER_CAMERA, out_buff, sizeof(out_buff), in_buff, sizeof(in_buff));
#ifdef SIV120B_DIRECT_DEBUG
  if (rt == SCCB_TRANSACTION_FAIL) kal_wap_trace(MOD_ENG,TRACE_INFO, "I2C read %x error", addr);
#endif
  return in_buff[0];
#endif
}


static void SIV120B_DIRECT_bank_write_cmos_sensor(kal_uint32 addr, kal_uint32 para)
{
	kal_uint16 reg_page,reg_addr;

	reg_page = addr>>8;
	reg_addr = (addr&0x000000ff);

	SIV120B_DIRECT_write_cmos_sensor(BANK_SETTING_REG,reg_page);
	SIV120B_DIRECT_write_cmos_sensor(reg_addr,para);


}

static kal_uint8 SIV120B_DIRECT_bank_read_cmos_sensor(kal_uint32 addr)
{
	kal_uint16 reg_page,reg_addr;

	reg_page = addr>>8;
	reg_addr = (addr&0x000000ff);

	SIV120B_DIRECT_write_cmos_sensor(BANK_SETTING_REG,reg_page);
	return SIV120B_DIRECT_read_cmos_sensor(reg_addr);

}

static void SIV120B_DIRECT_set_page(kal_uint8 iPage)
{
    SIV120B_DIRECT_write_cmos_sensor(0x00,iPage);
}

/*************************************************************************
* FUNCTION
*   SIV120B_DIRECT_Initial_Setting
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
static void SIV120B_DIRECT_Initial_Setting(void)
{
	switch (SENSOR_LEVEL3)  //hunk add for adjust driving current
	{
	case SENSOR_LEVEL0:
	 cntr_a_driving = 0x00;
	 break;
	case SENSOR_LEVEL1:
	 cntr_a_driving = 0x50;
	 break;
	case SENSOR_LEVEL2:
	 cntr_a_driving = 0xa0;
	 break;
	case SENSOR_LEVEL3:
	 cntr_a_driving = 0xf0;
	 break;
	}
    // SNR block [Vendor recommended value ##Don't change##]
    SIV120B_DIRECT_set_page(0);
    SIV120B_DIRECT_write_cmos_sensor(0x04,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0x05,0x07); //VGA Output
    SIV120B_DIRECT_write_cmos_sensor(0x10,0x13);
    SIV120B_DIRECT_write_cmos_sensor(0x11,0x25);
    SIV120B_DIRECT_write_cmos_sensor(0x12,0x21);
    SIV120B_DIRECT_write_cmos_sensor(0x13,0x17); // ABS
    SIV120B_DIRECT_write_cmos_sensor(0x16,0xCF);
    SIV120B_DIRECT_write_cmos_sensor(0x17,0xaa); //Internal LDO On: 0xaa
                                          //Internal LDO off: 0x00

    // SIV120B_DIRECT 50Hz - 24MHz
    SIV120B_DIRECT_write_cmos_sensor(0x20,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0x21,0x6E);
    SIV120B_DIRECT_write_cmos_sensor(0x23,0x1D);
    SIV120B_DIRECT_set_page(1);
    SIV120B_DIRECT_write_cmos_sensor(0x34,0x84);

    // Vendor recommended value ##Don't change##
    SIV120B_DIRECT_set_page(0);
    SIV120B_DIRECT_write_cmos_sensor(0x40,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0x41,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0x42,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0x43,0x00);

    // AE
    SIV120B_DIRECT_set_page(1);
    SIV120B_DIRECT_write_cmos_sensor(0x11,0x0A);
    SIV120B_DIRECT_write_cmos_sensor(0x12,0x80); // D65 target 0x84
    SIV120B_DIRECT_write_cmos_sensor(0x13,0x80); // D30 target
    SIV120B_DIRECT_write_cmos_sensor(0x14,0x80); // D20 target

    // Init shutter & gain
    SIV120B_DIRECT_write_cmos_sensor(0x1D,0x02); //Initial shutter time
    SIV120B_DIRECT_write_cmos_sensor(0x1E,0x28); //Initial analog gain

    SIV120B_DIRECT_write_cmos_sensor(0x40,0x70); // Max gain 0x7F  //68
    SIV120B_DIRECT_write_cmos_sensor(0x41,0x28);
    SIV120B_DIRECT_write_cmos_sensor(0x42,0x28);
    SIV120B_DIRECT_write_cmos_sensor(0x43,0x08);
    SIV120B_DIRECT_write_cmos_sensor(0x44,0x08);
    SIV120B_DIRECT_write_cmos_sensor(0x45,0x09);
    SIV120B_DIRECT_write_cmos_sensor(0x46,0x17);
    SIV120B_DIRECT_write_cmos_sensor(0x47,0x1D);
    SIV120B_DIRECT_write_cmos_sensor(0x48,0x21);
    SIV120B_DIRECT_write_cmos_sensor(0x49,0x23);
    SIV120B_DIRECT_write_cmos_sensor(0x4A,0x24);
    SIV120B_DIRECT_write_cmos_sensor(0x4B,0x26);
    SIV120B_DIRECT_write_cmos_sensor(0x4C,0x27);
    SIV120B_DIRECT_write_cmos_sensor(0x4D,0x27);
    SIV120B_DIRECT_write_cmos_sensor(0x4E,0x1A);
    SIV120B_DIRECT_write_cmos_sensor(0x4F,0x14);
    SIV120B_DIRECT_write_cmos_sensor(0x50,0x11);
    SIV120B_DIRECT_write_cmos_sensor(0x51,0x0F);
    SIV120B_DIRECT_write_cmos_sensor(0x52,0x0D);
    SIV120B_DIRECT_write_cmos_sensor(0x53,0x0C);
    SIV120B_DIRECT_write_cmos_sensor(0x54,0x0A);
    SIV120B_DIRECT_write_cmos_sensor(0x55,0x09);

    // AE Window
    SIV120B_DIRECT_write_cmos_sensor(0x60,0xFF);
    SIV120B_DIRECT_write_cmos_sensor(0x61,0xFF);
    SIV120B_DIRECT_write_cmos_sensor(0x62,0xFF);
    SIV120B_DIRECT_write_cmos_sensor(0x63,0xFF);
    SIV120B_DIRECT_write_cmos_sensor(0x64,0xFF);
    SIV120B_DIRECT_write_cmos_sensor(0x65,0xFF);
    SIV120B_DIRECT_write_cmos_sensor(0x66,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0x67,0x50);
    SIV120B_DIRECT_write_cmos_sensor(0x68,0x50);
    SIV120B_DIRECT_write_cmos_sensor(0x69,0x50);
    SIV120B_DIRECT_write_cmos_sensor(0x6A,0x50);
    SIV120B_DIRECT_write_cmos_sensor(0x6B,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0x6C,0x06);

    //Anti Saturation
    SIV120B_DIRECT_write_cmos_sensor(0x70,0xD4); //Anti Saturation On
    SIV120B_DIRECT_write_cmos_sensor(0x77,0xB0);
    SIV120B_DIRECT_write_cmos_sensor(0x78,0xB8);
    SIV120B_DIRECT_write_cmos_sensor(0x79,0x6E); //Y Level 0x70 for gamma test

    SIV120B_DIRECT_write_cmos_sensor(0x90,0xC8);

    // AWB
    SIV120B_DIRECT_set_page(2);
    SIV120B_DIRECT_write_cmos_sensor(0x10,0xD3);
    SIV120B_DIRECT_write_cmos_sensor(0x11,0xC0);
    SIV120B_DIRECT_write_cmos_sensor(0x12,0x80);
    SIV120B_DIRECT_write_cmos_sensor(0x13,0x80);
    SIV120B_DIRECT_write_cmos_sensor(0x14,0x7F);
    SIV120B_DIRECT_write_cmos_sensor(0x15,0xFE);
    SIV120B_DIRECT_write_cmos_sensor(0x16,0x80);
    SIV120B_DIRECT_write_cmos_sensor(0x17,0xEA);
    SIV120B_DIRECT_write_cmos_sensor(0x18,0x80);

    SIV120B_DIRECT_write_cmos_sensor(0x19,0xB0);//0xA0
    SIV120B_DIRECT_write_cmos_sensor(0x1A,0x50);//0x60
    SIV120B_DIRECT_write_cmos_sensor(0x1B,0xB0);//0xA0
    SIV120B_DIRECT_write_cmos_sensor(0x1C,0x50);//0x60
    SIV120B_DIRECT_write_cmos_sensor(0x1D,0xA0);
    SIV120B_DIRECT_write_cmos_sensor(0x1E,0x70);

    SIV120B_DIRECT_write_cmos_sensor(0x20,0xE8);
    SIV120B_DIRECT_write_cmos_sensor(0x21,0x20);
    SIV120B_DIRECT_write_cmos_sensor(0x22,0xA4);
    SIV120B_DIRECT_write_cmos_sensor(0x23,0x20);
    SIV120B_DIRECT_write_cmos_sensor(0x24,0xFF);
    SIV120B_DIRECT_write_cmos_sensor(0x25,0x20);
    SIV120B_DIRECT_write_cmos_sensor(0x26,0x0F);
    SIV120B_DIRECT_write_cmos_sensor(0x27,0x10);
    SIV120B_DIRECT_write_cmos_sensor(0x28,0x1A);
    SIV120B_DIRECT_write_cmos_sensor(0x29,0xB8);
    SIV120B_DIRECT_write_cmos_sensor(0x2A,0x90);

    SIV120B_DIRECT_write_cmos_sensor(0x30,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0x31,0x10);
    SIV120B_DIRECT_write_cmos_sensor(0x32,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0x33,0x10);
    SIV120B_DIRECT_write_cmos_sensor(0x34,0x02);
    SIV120B_DIRECT_write_cmos_sensor(0x35,0x76);
    SIV120B_DIRECT_write_cmos_sensor(0x36,0x01);
    SIV120B_DIRECT_write_cmos_sensor(0x37,0xD6);
    SIV120B_DIRECT_write_cmos_sensor(0x40,0x01);
    SIV120B_DIRECT_write_cmos_sensor(0x41,0x04);
    SIV120B_DIRECT_write_cmos_sensor(0x42,0x08);
    SIV120B_DIRECT_write_cmos_sensor(0x43,0x10);
    SIV120B_DIRECT_write_cmos_sensor(0x44,0x12);
    SIV120B_DIRECT_write_cmos_sensor(0x45,0x35);
    SIV120B_DIRECT_write_cmos_sensor(0x46,0x64);
    SIV120B_DIRECT_write_cmos_sensor(0x50,0x33);
    SIV120B_DIRECT_write_cmos_sensor(0x51,0x20);
    SIV120B_DIRECT_write_cmos_sensor(0x52,0xE5);
    SIV120B_DIRECT_write_cmos_sensor(0x53,0xFB);
    SIV120B_DIRECT_write_cmos_sensor(0x54,0x13);
    SIV120B_DIRECT_write_cmos_sensor(0x55,0x26);
    SIV120B_DIRECT_write_cmos_sensor(0x56,0x07);
    SIV120B_DIRECT_write_cmos_sensor(0x57,0xF5);
    SIV120B_DIRECT_write_cmos_sensor(0x58,0xEA);
    SIV120B_DIRECT_write_cmos_sensor(0x59,0x21);

    //CMA change  -D65~A
    SIV120B_DIRECT_write_cmos_sensor(0x63,0x9D); //D30 to D20 for R
    SIV120B_DIRECT_write_cmos_sensor(0x64,0xBE); //D30 to D20 for B
    SIV120B_DIRECT_write_cmos_sensor(0x65,0x9D); //D20 to D30 for R
    SIV120B_DIRECT_write_cmos_sensor(0x66,0xBE); //D20 to D30 for B
    SIV120B_DIRECT_write_cmos_sensor(0x67,0xC2); //D65 to D30 for R
    SIV120B_DIRECT_write_cmos_sensor(0x68,0x9C); //D65 to D30 for B
    SIV120B_DIRECT_write_cmos_sensor(0x69,0xC2); //D30 to D65 for R
    SIV120B_DIRECT_write_cmos_sensor(0x6A,0x9C); //D30 to D65 for B

    // IDP
    SIV120B_DIRECT_set_page(3);
    SIV120B_DIRECT_write_cmos_sensor(0x10,0xFF); // IDP function enable
    SIV120B_DIRECT_write_cmos_sensor(0x11,0x0D); // PCLK polarity
    SIV120B_DIRECT_write_cmos_sensor(0x12,0x0B); /* direct RGB565 */
    //SIV120B_DIRECT_write_cmos_sensor(0x12,0xDD); // Y,Cb,Cr order sequence
    SIV120B_DIRECT_write_cmos_sensor(0x8C,0x18); // Color matrix select at dark condition

    // DPCNR
    SIV120B_DIRECT_write_cmos_sensor(0x17,0xB8);
    SIV120B_DIRECT_write_cmos_sensor(0x18,0x18);
    SIV120B_DIRECT_write_cmos_sensor(0x19,0x48);
    SIV120B_DIRECT_write_cmos_sensor(0x1A,0x48);
    SIV120B_DIRECT_write_cmos_sensor(0x1B,0x3F);
    SIV120B_DIRECT_write_cmos_sensor(0x1C,0x10);
    SIV120B_DIRECT_write_cmos_sensor(0x1D,0x60);
    SIV120B_DIRECT_write_cmos_sensor(0x1E,0x60);
    SIV120B_DIRECT_write_cmos_sensor(0x1F,0x4F);
    SIV120B_DIRECT_write_cmos_sensor(0x20,0x03); // Normal illumiinfo start
    SIV120B_DIRECT_write_cmos_sensor(0x21,0x0F); // Dark illumiinfo start

    // Gamma
    SIV120B_DIRECT_write_cmos_sensor(0x30,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0x31,0x08);
    SIV120B_DIRECT_write_cmos_sensor(0x32,0x0F);
    SIV120B_DIRECT_write_cmos_sensor(0x33,0x20);
    SIV120B_DIRECT_write_cmos_sensor(0x34,0x3B);
    SIV120B_DIRECT_write_cmos_sensor(0x35,0x52);
    SIV120B_DIRECT_write_cmos_sensor(0x36,0x66);
    SIV120B_DIRECT_write_cmos_sensor(0x37,0x78);
    SIV120B_DIRECT_write_cmos_sensor(0x38,0x89);
    SIV120B_DIRECT_write_cmos_sensor(0x39,0x98);
    SIV120B_DIRECT_write_cmos_sensor(0x3A,0xA4);
    SIV120B_DIRECT_write_cmos_sensor(0x3B,0xBA);
    SIV120B_DIRECT_write_cmos_sensor(0x3C,0xD4);
    SIV120B_DIRECT_write_cmos_sensor(0x3D,0xEC);
    SIV120B_DIRECT_write_cmos_sensor(0x3E,0xF6);
    SIV120B_DIRECT_write_cmos_sensor(0x3F,0xFF);

    // Shading back up
    /*
    SIV120B_DIRECT_write_cmos_sensor(0x40,0x0A);
    SIV120B_DIRECT_write_cmos_sensor(0x41,0xDC);
    SIV120B_DIRECT_write_cmos_sensor(0x42,0xBA);
    SIV120B_DIRECT_write_cmos_sensor(0x43,0x98);
    SIV120B_DIRECT_write_cmos_sensor(0x44,0x75);
    SIV120B_DIRECT_write_cmos_sensor(0x45,0x31);
    SIV120B_DIRECT_write_cmos_sensor(0x46,0x46);//0x57
    SIV120B_DIRECT_write_cmos_sensor(0x47,0x74);//0x86
    SIV120B_DIRECT_write_cmos_sensor(0x48,0x46);//0x46
    SIV120B_DIRECT_write_cmos_sensor(0x49,0x74);//0x74
    SIV120B_DIRECT_write_cmos_sensor(0x4A,0x24);//0x24
    SIV120B_DIRECT_write_cmos_sensor(0x4B,0x42);//0x42
    SIV120B_DIRECT_write_cmos_sensor(0x4C,0x13);//0x14
    SIV120B_DIRECT_write_cmos_sensor(0x4D,0x52);//0x52
    SIV120B_DIRECT_write_cmos_sensor(0x4E,0x04);
    SIV120B_DIRECT_write_cmos_sensor(0x4F,0x44);//0x44
    SIV120B_DIRECT_write_cmos_sensor(0x50,0xF6);//0xF6
    SIV120B_DIRECT_write_cmos_sensor(0x51,0x80);
    SIV120B_DIRECT_write_cmos_sensor(0x52,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0x53,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0x54,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0x55,0x00);
    */

    // Shading
    SIV120B_DIRECT_write_cmos_sensor(0x40,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0x41,0xDC);
    SIV120B_DIRECT_write_cmos_sensor(0x42,0xCB);
    SIV120B_DIRECT_write_cmos_sensor(0x43,0xA8);
    SIV120B_DIRECT_write_cmos_sensor(0x44,0x75);
    SIV120B_DIRECT_write_cmos_sensor(0x45,0x31);
    SIV120B_DIRECT_write_cmos_sensor(0x46,0x63);//0x44
    SIV120B_DIRECT_write_cmos_sensor(0x47,0x45);//0x63
    SIV120B_DIRECT_write_cmos_sensor(0x48,0x63);//0x44
    SIV120B_DIRECT_write_cmos_sensor(0x49,0x43);//0x62
    SIV120B_DIRECT_write_cmos_sensor(0x4A,0x63);//0x34
    SIV120B_DIRECT_write_cmos_sensor(0x4B,0x42);//0x41
    SIV120B_DIRECT_write_cmos_sensor(0x4C,0x52);//0x23
    SIV120B_DIRECT_write_cmos_sensor(0x4D,0x31);//0x40
    SIV120B_DIRECT_write_cmos_sensor(0x4E,0x04);
    SIV120B_DIRECT_write_cmos_sensor(0x4F,0x44);//0x44
    SIV120B_DIRECT_write_cmos_sensor(0x50,0xFE);//0xF6
    SIV120B_DIRECT_write_cmos_sensor(0x51,0x80);
    SIV120B_DIRECT_write_cmos_sensor(0x52,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0x53,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0x54,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0x55,0x00);


    // Lowlux Shading
    SIV120B_DIRECT_write_cmos_sensor(0x56,0x10);
    SIV120B_DIRECT_write_cmos_sensor(0x57,0xDA);
    SIV120B_DIRECT_write_cmos_sensor(0x58,0xFF);

    //Filter
    SIV120B_DIRECT_write_cmos_sensor(0x60,0x2F);
    SIV120B_DIRECT_write_cmos_sensor(0x61,0xB7);
    SIV120B_DIRECT_write_cmos_sensor(0x62,0xB7);
    SIV120B_DIRECT_write_cmos_sensor(0x63,0xB7);
    SIV120B_DIRECT_write_cmos_sensor(0x64,0x0C);
    SIV120B_DIRECT_write_cmos_sensor(0x65,0xFF);
    SIV120B_DIRECT_write_cmos_sensor(0x66,0x08);
    SIV120B_DIRECT_write_cmos_sensor(0x67,0xFF);
    SIV120B_DIRECT_write_cmos_sensor(0x68,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0x69,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0x6A,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0x6B,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0x6C,0xA0);
    SIV120B_DIRECT_write_cmos_sensor(0x6D,0x10);
    SIV120B_DIRECT_write_cmos_sensor(0x6E,0x08);
    SIV120B_DIRECT_write_cmos_sensor(0x6F,0x18);

    // Color Matrix (D65) - Daylight
    /*
    SIV120B_DIRECT_write_cmos_sensor(0x71,0x3B);
    SIV120B_DIRECT_write_cmos_sensor(0x72,0xC1);
    SIV120B_DIRECT_write_cmos_sensor(0x73,0x04);
    SIV120B_DIRECT_write_cmos_sensor(0x74,0x0F);
    SIV120B_DIRECT_write_cmos_sensor(0x75,0x1E);
    SIV120B_DIRECT_write_cmos_sensor(0x76,0x12);
    SIV120B_DIRECT_write_cmos_sensor(0x77,0xF3);
    SIV120B_DIRECT_write_cmos_sensor(0x78,0xCF);
    SIV120B_DIRECT_write_cmos_sensor(0x79,0x3E);
    */
    SIV120B_DIRECT_write_cmos_sensor(0x71,0x3E);
    SIV120B_DIRECT_write_cmos_sensor(0x72,0xBD);
    SIV120B_DIRECT_write_cmos_sensor(0x73,0x05);
    SIV120B_DIRECT_write_cmos_sensor(0x74,0x0F);
    SIV120B_DIRECT_write_cmos_sensor(0x75,0x1E);
    SIV120B_DIRECT_write_cmos_sensor(0x76,0x13);
    SIV120B_DIRECT_write_cmos_sensor(0x77,0xF3);
    SIV120B_DIRECT_write_cmos_sensor(0x78,0xCC);
    SIV120B_DIRECT_write_cmos_sensor(0x79,0x41);

    // Color Matrix (D30) - CWF
    SIV120B_DIRECT_write_cmos_sensor(0x7A,0x3D);
    SIV120B_DIRECT_write_cmos_sensor(0x7B,0xC4);
    SIV120B_DIRECT_write_cmos_sensor(0x7C,0xFF);
    SIV120B_DIRECT_write_cmos_sensor(0x7D,0x10);
    SIV120B_DIRECT_write_cmos_sensor(0x7E,0x1D);
    SIV120B_DIRECT_write_cmos_sensor(0x7F,0x13);
    SIV120B_DIRECT_write_cmos_sensor(0x80,0xF2);
    SIV120B_DIRECT_write_cmos_sensor(0x81,0xC4);
    SIV120B_DIRECT_write_cmos_sensor(0x82,0x4A);

    // Color Matrix (D20) - A
    SIV120B_DIRECT_write_cmos_sensor(0x83,0x3C);
    SIV120B_DIRECT_write_cmos_sensor(0x84,0xC2);
    SIV120B_DIRECT_write_cmos_sensor(0x85,0x01);
    SIV120B_DIRECT_write_cmos_sensor(0x86,0x10);
    SIV120B_DIRECT_write_cmos_sensor(0x87,0x1F);
    SIV120B_DIRECT_write_cmos_sensor(0x88,0x0F);
    SIV120B_DIRECT_write_cmos_sensor(0x89,0xF6);
    SIV120B_DIRECT_write_cmos_sensor(0x8A,0xD2);
    SIV120B_DIRECT_write_cmos_sensor(0x8B,0x39);

    // Edge - Green
    SIV120B_DIRECT_write_cmos_sensor(0x90,0x10); //Up Gain
    SIV120B_DIRECT_write_cmos_sensor(0x91,0x10); //Down Gain
    SIV120B_DIRECT_write_cmos_sensor(0x92,0x04);
    SIV120B_DIRECT_write_cmos_sensor(0x93,0x12);
    SIV120B_DIRECT_write_cmos_sensor(0x94,0xFF);
    SIV120B_DIRECT_write_cmos_sensor(0x95,0x20);
    SIV120B_DIRECT_write_cmos_sensor(0x96,0x04);
    SIV120B_DIRECT_write_cmos_sensor(0x97,0x12);
    SIV120B_DIRECT_write_cmos_sensor(0x98,0xFF);
    SIV120B_DIRECT_write_cmos_sensor(0x99,0x20);
    SIV120B_DIRECT_write_cmos_sensor(0x9A,0x20);
    SIV120B_DIRECT_write_cmos_sensor(0x9B,0x20);
    SIV120B_DIRECT_write_cmos_sensor(0x9C,0x1A);
    SIV120B_DIRECT_write_cmos_sensor(0x9D,0x40);
    SIV120B_DIRECT_write_cmos_sensor(0x9E,0x00);

    // Edge - Luminance
    SIV120B_DIRECT_write_cmos_sensor(0x9F,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0xA0,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0xA1,0x02);
    SIV120B_DIRECT_write_cmos_sensor(0xA2,0x02);
    SIV120B_DIRECT_write_cmos_sensor(0xA3,0x04);
    SIV120B_DIRECT_write_cmos_sensor(0xA4,0x20);
    SIV120B_DIRECT_write_cmos_sensor(0xA5,0x1A);
    SIV120B_DIRECT_write_cmos_sensor(0xA6,0x40);
    SIV120B_DIRECT_write_cmos_sensor(0xA7,0x00);

    // YCbCr Gain, Brightness, Contrast
    SIV120B_DIRECT_write_cmos_sensor(0xA8,0x10);
    SIV120B_DIRECT_write_cmos_sensor(0xA9,0x15); //a9 aa  0813
    SIV120B_DIRECT_write_cmos_sensor(0xAA,0x15);
    SIV120B_DIRECT_write_cmos_sensor(0xAB,0x04);
    SIV120B_DIRECT_write_cmos_sensor(0xAC,0x10);

    SIV120B_DIRECT_write_cmos_sensor(0xB0,0xFF); //Y Top
    SIV120B_DIRECT_write_cmos_sensor(0xB1,0x00); //Y Bottom
    SIV120B_DIRECT_write_cmos_sensor(0xB2,0xFF);
    SIV120B_DIRECT_write_cmos_sensor(0xB3,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0xB4,0xFF);
    SIV120B_DIRECT_write_cmos_sensor(0xB5,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0xB6,0x00);

    // Color suppress
    SIV120B_DIRECT_write_cmos_sensor(0xB9,0x1A); //Ilimininfo Start0 x1A
    SIV120B_DIRECT_write_cmos_sensor(0xBA,0x30); //Slope

    // Window
    SIV120B_DIRECT_write_cmos_sensor(0xC0,0x24);
    SIV120B_DIRECT_write_cmos_sensor(0xC1,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0xC2,0x80);
    SIV120B_DIRECT_write_cmos_sensor(0xC3,0x00);
    SIV120B_DIRECT_write_cmos_sensor(0xC4,0xE0);

    SIV120B_DIRECT_write_cmos_sensor(0xDD,0x4F); // ENHCTRL
    SIV120B_DIRECT_write_cmos_sensor(0xDE,0xBA); // NOIZCTRL
    SIV120B_DIRECT_write_cmos_sensor(0xDF,0x28);
    SIV120B_DIRECT_write_cmos_sensor(0xE0,0x70);
    SIV120B_DIRECT_write_cmos_sensor(0xE1,0x90);
    SIV120B_DIRECT_write_cmos_sensor(0xE2,0x08);
    SIV120B_DIRECT_write_cmos_sensor(0xE3,0x10);
    SIV120B_DIRECT_write_cmos_sensor(0xE4,0x40);

    // Memory speed control
    SIV120B_DIRECT_write_cmos_sensor(0xE5,0x15);
    SIV120B_DIRECT_write_cmos_sensor(0xE6,0x28);
    SIV120B_DIRECT_write_cmos_sensor(0xE7,0x04);

    // AE on
    SIV120B_DIRECT_set_page(1);
    SIV120B_DIRECT_write_cmos_sensor(0x10,0x80);

    // Sensor on
    SIV120B_DIRECT_set_page(0);
    SIV120B_DIRECT_write_cmos_sensor(0x03,0x25); //0x55

    //board 1  0x25
    //board 2
    //board 3  0x05

}   /* SIV120B_DIRECT_Initial_Setting */

/*************************************************************************
* FUNCTION
*    SIV120B_DIRECT_half_adjust
*
* DESCRIPTION
*    This function dividend / divisor and use round-up.
*
* PARAMETERS
*    dividend
*    divisor
*
* RETURNS
*    [dividend / divisor]
*
* LOCAL AFFECTED
*
*************************************************************************/
__inline static kal_uint32 SIV120B_DIRECT_half_adjust(kal_uint32 dividend, kal_uint32 divisor)
{
  return (dividend * 2 + divisor) / (divisor * 2); /* that is [dividend / divisor + 0.5]*/
}

/*************************************************************************
* FUNCTION
*   SIV120B_DIRECT_Set_pShutter_Step
*
* DESCRIPTION
*   This function is to calculate & set shutter step register .
*
*************************************************************************/
static void SIV120B_DIRECT_Set_pShutter_Step(void)
{
    const kal_uint8 banding = SIV120B_DIRECT_g_iBanding == CAM_BANDING_50HZ ? SIV120B_DIRECT_NUM_50HZ : SIV120B_DIRECT_NUM_60HZ;
    const kal_uint16 shutter_step = SIV120B_DIRECT_half_adjust(SIV120B_DIRECT_PCLK / 2, (SIV120B_DIRECT_Hblank + SIV120B_DIRECT_PERIOD_PIXEL_NUMS) * banding);
	kal_uint16 temp=0;
    ASSERT(shutter_step <= 0xFF);
    /* Block 1:0x34  shutter step*/
	SIV120B_DIRECT_set_page(0x01);
	while(temp == 0)
		{
			SIV120B_DIRECT_bank_write_cmos_sensor(0x0134,shutter_step);//
			temp = SIV120B_DIRECT_read_cmos_sensor(0x34);
		}
#if (defined(DRV_ISP_6238_SERIES)||defined(DRV_ISP_6235_SERIES))
    SIV120B_DIRECT_pshutter_step = shutter_step;
#endif
#ifdef SIV120B_DIRECT_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "Set Shutter Step:%x",shutter_step);
#endif
}/* SIV120B_DIRECT_Set_pShutter_Step */
static void SIV120B_DIRECT_Set_cShutter_Step(void)
{
    const kal_uint8 banding = SIV120B_DIRECT_g_iBanding == CAM_BANDING_50HZ ? SIV120B_DIRECT_NUM_50HZ : SIV120B_DIRECT_NUM_60HZ;
    //const kal_uint16 shutter_step = SIV120B_DIRECT_half_adjust(SIV120B_DIRECT_PCLK / 2, (SIV120B_DIRECT_Hblank + SIV120B_DIRECT_PERIOD_PIXEL_NUMS) * banding);
	const kal_uint16 shutter_step = SIV120B_DIRECT_half_adjust(12000000 / 2, (SIV120B_DIRECT_Hblank + SIV120B_DIRECT_PERIOD_PIXEL_NUMS) * banding);
	kal_uint16 temp=0;
    ASSERT(shutter_step <= 0xFF);
    /* Block 1:0x34  shutter step*/
	SIV120B_DIRECT_set_page(0x01);
	while(temp == 0)
		{
			SIV120B_DIRECT_bank_write_cmos_sensor(0x0135,shutter_step);//
			temp = SIV120B_DIRECT_read_cmos_sensor(0x35);
		}
#if (defined(DRV_ISP_6238_SERIES)||defined(DRV_ISP_6235_SERIES))
    SIV120B_DIRECT_cshutter_step = shutter_step;
#endif
#ifdef SIV120B_DIRECT_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "Set Shutter Step:%x",shutter_step);
#endif
}/* SIV120B_DIRECT_Set_pShutter_Step */

/*************************************************************************
* FUNCTION
*   SIV120B_DIRECT_Set_Frame_Count
*
* DESCRIPTION
*   This function is to set frame count register .
*
*************************************************************************/
static void SIV120B_DIRECT_Set_Frame_Count(void)
{
    kal_uint16 Frame_Count,min_fps = 100;
    kal_uint8 banding = SIV120B_DIRECT_g_iBanding == CAM_BANDING_50HZ ? SIV120B_DIRECT_NUM_50HZ : SIV120B_DIRECT_NUM_60HZ;

	min_fps = SIV120B_DIRECT_g_bNightMode ? SIV120B_DIRECT_Min_Fps_Night : SIV120B_DIRECT_Min_Fps_Normal;
    Frame_Count = banding * SIV120B_DIRECT_FRAME_RATE_UNIT / min_fps;
#ifdef SIV120B_DIRECT_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "min_fps:%d,Frame_Count:%x",min_fps/SIV120B_DIRECT_FRAME_RATE_UNIT,Frame_Count);
#endif
    /*Block 01: 0x11  Max shutter step,for Min frame rate */
    SIV120B_DIRECT_set_page(1);
    SIV120B_DIRECT_write_cmos_sensor(0x11,Frame_Count&0xFF);
}/* SIV120B_DIRECT_Set_Frame_Count */

/*************************************************************************
* FUNCTION
*   SIV120B_DIRECT_ConfigBlank
*
* DESCRIPTION
*   This function is to set Blank size for Preview mode .
*
* PARAMETERS
*   iBlank: target HBlank size
*      iHz: banding frequency
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void SIV120B_DIRECT_ConfigBlank(kal_uint16 hblank,kal_uint16 vblank)
{
#ifdef SIV120B_DIRECT_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"hblank:%x,vblank:%x",hblank,vblank);
#endif
   /********************************************
    *   Register :0x20 - 0x22
    *  Block 00
    *  0x20  [7:4]:HBANK[9:8]; 0x20  [3:0]:VBANK[9:8]
    *  0x21 HBANK[7:0]
    *  0x23 VBANK[7:0]
    ********************************************/
    ASSERT(hblank <= SIV120B_DIRECT_BLANK_REGISTER_LIMITATION && vblank <= SIV120B_DIRECT_BLANK_REGISTER_LIMITATION);
    SIV120B_DIRECT_set_page(0);
    SIV120B_DIRECT_write_cmos_sensor(0x20,((hblank>>4)&0xF0)|((vblank>>8)&0x0F));
    SIV120B_DIRECT_write_cmos_sensor(0x21,hblank & 0xFF);
    SIV120B_DIRECT_write_cmos_sensor(0x23,vblank & 0xFF);
    SIV120B_DIRECT_Set_pShutter_Step();
}   /* SIV120B_DIRECT_ConfigBlank */

/*************************************************************************
* FUNCTION
*    SIV120B_DIRECT_cal_fps
*
* DESCRIPTION
*    This function calculate & set frame rate and fix frame rate when video mode
*    MUST BE INVOKED AFTER SIM120C_preview() !!!
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
static void SIV120B_DIRECT_cal_fps(void)
{
    kal_int16 Line_length,Dummy_Line;
    kal_uint16 max_fps = 300;

    Line_length = SIV120B_DIRECT_Dummy_Pixel + SIV120B_DIRECT_PERIOD_PIXEL_NUMS;//0x01+(652 + 144 + 3) = 800

	if (SIV120B_DIRECT_Video_Mode == KAL_TRUE)
	{
		max_fps = SIV120B_DIRECT_g_bNightMode ? SIV120B_DIRECT_Min_Fps_Night: SIV120B_DIRECT_Min_Fps_Normal;
	}
	else
	{
		max_fps = SIV120B_DIRECT_MAX_CAMERA_FPS;
	}

    Dummy_Line = SIV120B_DIRECT_PCLK * SIV120B_DIRECT_FRAME_RATE_UNIT / (2 * Line_length * max_fps) - SIV120B_DIRECT_PERIOD_LINE_NUMS;
    if(Dummy_Line > SIV120B_DIRECT_BLANK_REGISTER_LIMITATION)
    {
        Dummy_Line = SIV120B_DIRECT_BLANK_REGISTER_LIMITATION;
        Line_length = SIV120B_DIRECT_PCLK * SIV120B_DIRECT_FRAME_RATE_UNIT / (2 * (Dummy_Line + SIV120B_DIRECT_PERIOD_LINE_NUMS) * max_fps);
    }
    SIV120B_DIRECT_Hblank = Line_length -  SIV120B_DIRECT_PERIOD_PIXEL_NUMS;
#ifdef SIV120B_DIRECT_DEBUG
   kal_wap_trace(MOD_ENG,TRACE_INFO, "max_fps:%d",max_fps/SIV120B_DIRECT_FRAME_RATE_UNIT);
   kal_wap_trace(MOD_ENG,TRACE_INFO, "Dummy Pixel:%x,Hblank:%x,Vblank:%x",SIV120B_DIRECT_Dummy_Pixel,SIV120B_DIRECT_Hblank,Dummy_Line);
#endif
	kal_prompt_trace(MOD_ENG,"SIV120B_DIRECT_Hblank = %x,Dummy_Line = %x",SIV120B_DIRECT_Hblank,Dummy_Line);
    SIV120B_DIRECT_ConfigBlank((SIV120B_DIRECT_Hblank > 0) ? SIV120B_DIRECT_Hblank : 0, (Dummy_Line > 0) ? Dummy_Line : 0);

}

/*****************************************************************************
 * FUNCTION
 *  SIV120B_DIRECT_PowerOn
 * DESCRIPTION
 *  This function Power On the CMOS sensor .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void Set_CMPDN_High(void);
extern void Set_CMPDN_Low(void);

static kal_int16 SIV120B_DIRECT_PowerOn(void)
{
    kal_uint16 sensor_id = 0;

    /* PowerOn the sensor */
    cis_module_power_on(KAL_TRUE);
    Set_CMPDN_High();
    kal_sleep_task(2);  /* delay for power stable */

    /* set sensors chip enable pin to high to activate SIV120B_DIRECT */
    SIV120B_DIRECT_PWRDN_PIN_HIGH;
    set_isp_driving_current(ISP_DRIVING_6MA);

    /* SIV120B_DIRECT needs 24M MCLK */
    /* Use UPLL to produce 48M clock, then divided by 2 */
#if (defined(DRV_ISP_6238_SERIES))
    setCameraCPLLOutputFreq(48000000);
    ENABLE_CAMERA_TG_CLK_48M;
#else
    DISABLE_CAMERA_TG_CLK_48M;//52mhz
    ENABLE_CAMERA_TG_CLK_48M;//48mhz
    UPLL_Enable(UPLL_OWNER_ISP);
#endif
    //SET_TG_OUTPUT_CLK_DIVIDER(1);
    SET_TG_OUTPUT_CLK_DIVIDER(3);//Mclk = 48/4 //hunk
    SET_CMOS_RISING_EDGE(0);//SET_CMOS_RISING_EDGE(0); //hunk
    SET_CMOS_FALLING_EDGE(2);//SET_CMOS_FALLING_EDGE(1);//hunk

    /* Sensor Signal Polarity */
    /* Note: Set HSync Polarity to Low means High active */
    ENABLE_CAMERA_PIXEL_CLKIN_ENABLE;
    ENABLE_CAMERA_PIXEL_CLK_INV;
    SET_CMOS_CLOCK_POLARITY_LOW;
    SET_VSYNC_POLARITY_LOW;
    SET_HSYNC_POLARITY_LOW;

    /* YUV Sensor Input Format */
    ENABLE_CAMERA_INDATA_FORMAT;            /* Enable yuv data input */
    SET_CAMERA_INPUT_TYPE(INPUT_RGB);    /* direct RGB565 */
    //SET_CAMERA_INPUT_TYPE(INPUT_YUV422);    /* SIV120B_DIRECT support YUV422 */
    //SET_CAMERA_INPUT_ORDER(INPUT_ORDER_CbYCrY1);

    /* Reset the sensor */
    SIV120B_DIRECT_RESET_PIN_LOW;
    kal_sleep_task(1);
    SIV120B_DIRECT_RESET_PIN_HIGH;
    kal_sleep_task(1);  /* delay for stable sensor */

#ifdef SIV120B_DIRECT_HW_SCCB
    i2c_set_get_handle_wait(SCCB_OWNER_CAMERA, KAL_TRUE);
    i2c_set_slave_address(SCCB_OWNER_CAMERA, SIV120B_DIRECT_I2C_WRITE_ID);
    i2c_set_transaction_mode(SCCB_OWNER_CAMERA, SCCB_TRANSACTION_FAST_MODE, SCCB_300KB);
#endif

    /* Read Sensor ID  */
    SIV120B_DIRECT_set_page(0);
    //sensor_id = SIV120B_DIRECT_read_cmos_sensor(0x01)<<8 | SIV120B_DIRECT_read_cmos_sensor(0x02);
    sensor_id = SIV120B_DIRECT_read_cmos_sensor(0x01) ;
	kal_prompt_trace(MOD_ENG,"sensor_id = %x", sensor_id);	
    return sensor_id;
}

/*****************************************************************************
 * FUNCTION
 *  SIV120B_DIRECT_PowerOff
 * DESCRIPTION
 *  This function is to turn off sensor module power.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void SIV120B_DIRECT_PowerOff(void)
{
#ifdef SIV120B_DIRECT_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"PowerOff");
#endif
    SIV120B_DIRECT_set_page(0);
    SIV120B_DIRECT_write_cmos_sensor(0x03, 0x02);  //sensor sleep mode
    cis_module_power_on(KAL_FALSE);         // power off sensor
    Set_CMPDN_Low();

#ifndef SIV120B_DIRECT_HW_SCCB
    SET_SCCB_CLK_LOW;
    SET_SCCB_DATA_LOW;
#endif
#if (defined(DRV_ISP_6238_SERIES))
    setCameraCPLLPowerDown();
#else
#if !(defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
    UPLL_Disable(UPLL_OWNER_ISP);
#endif
#endif
}   /* SIV120B_DIRECT_PowerOff */


/*************************************************************************
* FUNCTION
*   SIV120B_DIRECT_Init
*
* DESCRIPTION
*   This function initialize the registers of CMOS sensor and ISP control register.
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
static kal_int8 SIV120B_DIRECT_Init(void)
{
    kal_uint16 sensor_id = 0;

#ifdef SIV120B_DIRECT_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "SIV120B_DIRECT Init");
#endif

    sensor_id = SIV120B_DIRECT_PowerOn();

#ifdef SIV120B_DIRECT_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"SIV120B_DIRECT Sensor ID %x",sensor_id);
#endif

    if (SIV120B_SENSOR_ID != sensor_id)
        return -1;  /* The sensor is not SIV120B_DIRECT */

    SIV120B_DIRECT_Initial_Setting();

    SIV120B_DIRECT_Video_Mode = KAL_FALSE;
    SIV120B_DIRECT_Mode_change = KAL_FALSE;
    SIV120B_DIRECT_g_bNightMode = KAL_FALSE;
    SIV120B_DIRECT_g_iBanding = CAM_BANDING_50HZ;
    SIV120B_DIRECT_g_iAE_Meter = CAM_AE_METER_AUTO;
    SIV120B_DIRECT_Control = 0x00;

    SIV120B_DIRECT_Dummy_Pixel = 0x01;

    SIV120B_DIRECT_Min_Fps_Normal = 15 * SIV120B_DIRECT_FRAME_RATE_UNIT;//hunk
    SIV120B_DIRECT_Min_Fps_Night = SIV120B_DIRECT_Min_Fps_Normal >> 1;

    return 1;

}   /* SIV120B_DIRECT_Init() */

kal_uint32 SIV120B_DIRECT_detect_sensor_id(void)
{
    kal_uint16 SIV120B_DIRECT_sensor_id = 0;

    SIV120B_DIRECT_sensor_id = SIV120B_DIRECT_PowerOn();
    SIV120B_DIRECT_PowerOff();
#ifdef SIV120B_DIRECT_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"Detect SIV120B_DIRECT Sensor ID %x",SIV120B_DIRECT_sensor_id);
#endif
    return SIV120B_DIRECT_sensor_id;

}

/*************************************************************************
* FUNCTION
*   SIV120B_DIRECT_Get_I2C_ID
*
* DESCRIPTION
*   This function return the sensor read/write IDs of I2C I/F.
*
* PARAMETERS
*   *pI2C_WriteID : address pointer of sensor's I2C write id
*   *pI2C_ReadID  : address pointer of sensor's I2C read id
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void SIV120B_DIRECT_Get_I2C_ID(kal_uint8 *pI2C_WriteID, kal_uint8 *pI2C_ReadID)
{
    /* No need for YUV sensor driver */
}   /* SIV120B_DIRECT_Get_I2C_ID */

/*************************************************************************
* FUNCTION
*   SIV120B_DIRECT_GetSize
*
* DESCRIPTION
*   This function return the image width and height of image sensor.
*
* PARAMETERS
*   *pWidth : address pointer of horizontal effective pixels of image sensor
*  *pHeight : address pointer of vertical effective lines of image sensor
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void SIV120B_DIRECT_GetSize(kal_uint16 *pWidth, kal_uint16 *pHeight)
{
#ifdef SIV120B_DIRECT_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO,"GetSize");
#endif
    /* No need for YUV sensor driver */
}   /* SIV120B_DIRECT_GetSize */

/*************************************************************************
* FUNCTION
*   SIV120B_DIRECT_GetPeriod
*
* DESCRIPTION
*   This function return the image width and height of image sensor.
*
* PARAMETERS
*   *pPixelNumber : address pointer of pixel numbers in one period of HSYNC
*   *pLineNumber : address pointer of line numbers in one period of VSYNC
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void SIV120B_DIRECT_GetPeriod(kal_uint16 *pPixelNumber, kal_uint16 *pLineNumber)
{
    /* No need for YUV sensor driver */
}   /* SIV120B_DIRECT_GetPeriod */

/*************************************************************************
* FUNCTION
*   SIV120B_DIRECT_FixFrameRate
*
* DESCRIPTION
*   This function fix the frame rate of image sensor.
*
*************************************************************************/
static void SIV120B_DIRECT_StillMode(kal_bool bEnable)
{
	SIV120B_DIRECT_Control = SIV120B_DIRECT_bank_read_cmos_sensor(0x0004);
	if(bEnable == KAL_TRUE)//enable still mode
		{
			SIV120B_DIRECT_Control |= 0x10;
			SIV120B_DIRECT_set_page(0);
        	SIV120B_DIRECT_write_cmos_sensor(0x04,SIV120B_DIRECT_Control);
		}
	else
		{
	        SIV120B_DIRECT_Control &= 0xef;
	        SIV120B_DIRECT_set_page(0);
	        SIV120B_DIRECT_write_cmos_sensor(0x04,SIV120B_DIRECT_Control);
		}
}
static void SIV120B_DIRECT_FixFrameRate(kal_bool bEnable)
{
	SIV120B_DIRECT_Control = SIV120B_DIRECT_bank_read_cmos_sensor(0x0004);
	if(bEnable == KAL_TRUE)
    {   //fix frame rate
        SIV120B_DIRECT_Control |= 0xC0;
        SIV120B_DIRECT_set_page(0);
        SIV120B_DIRECT_write_cmos_sensor(0x04,SIV120B_DIRECT_Control);
    }
    else
    {
        SIV120B_DIRECT_Control &= 0x3F;
        SIV120B_DIRECT_set_page(0);
        SIV120B_DIRECT_write_cmos_sensor(0x04,SIV120B_DIRECT_Control);

    }
}   /* SIV120B_DIRECT_FixFrameRate */

/*************************************************************************
* FUNCTION
*   SIV120B_DIRECT_HVmirror
*
* DESCRIPTION
*   This function config the HVmirror of image sensor.
*
*************************************************************************/
static void SIV120B_DIRECT_HVmirror(kal_uint8 HVmirrorType)
{
    SIV120B_DIRECT_Control = SIV120B_DIRECT_Control & 0xFC;
    switch (HVmirrorType)
    {
        case IMAGE_NORMAL:
            SIV120B_DIRECT_Control |= 0x00;
            break;

        case IMAGE_H_MIRROR:
            SIV120B_DIRECT_Control |= 0x01;
            break;

        case IMAGE_V_MIRROR:
            SIV120B_DIRECT_Control |= 0x02;
            break;

        case IMAGE_HV_MIRROR:
            SIV120B_DIRECT_Control |= 0x03;
            break;

        default:
            ASSERT(0);
    }
    SIV120B_DIRECT_set_page(0);
    SIV120B_DIRECT_write_cmos_sensor(0x04,SIV120B_DIRECT_Control);
}   /* SIV120B_DIRECT_HVmirror */


/*************************************************************************
* FUNCTION
*   SIV120B_DIRECT_Preview
*
* DESCRIPTION
*   This function configure the sensor to preview mode.
*
* PARAMETERS
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
/**************************************************************************/
static void SIV120B_DIRECT_OutputFormat(SIV120B_DIRECT_OUTPUT_SIZE para)
{
	SIV120B_DIRECT_set_page(0);
	switch (para)
		{
			case SIV120B_DIRECT_QCIF_FORMAT:
				SIV120B_DIRECT_write_cmos_sensor(0x05,0x01);
				SIV120B_DIRECT_PERIOD_PIXEL_NUMS = SIV120B_DIRECT_PERIOD_PIXEL_NUMS_QCIF;
				SIV120B_DIRECT_PERIOD_LINE_NUMS   = SIV120B_DIRECT_PERIOD_LINE_NUMS_QCIF;
				break;
			case SIV120B_DIRECT_QVGA_FORMAT:
				SIV120B_DIRECT_write_cmos_sensor(0x05,0x05);
				SIV120B_DIRECT_PERIOD_PIXEL_NUMS = SIV120B_DIRECT_PERIOD_PIXEL_NUMS_QVGA;
				SIV120B_DIRECT_PERIOD_LINE_NUMS   = SIV120B_DIRECT_PERIOD_LINE_NUMS_QVGA;
				break;
			case SIV120B_DIRECT_CIF_FORMAT:
				SIV120B_DIRECT_write_cmos_sensor(0x05,0x03);
				SIV120B_DIRECT_PERIOD_PIXEL_NUMS = SIV120B_DIRECT_PERIOD_PIXEL_NUMS_CIF;
				SIV120B_DIRECT_PERIOD_LINE_NUMS   = SIV120B_DIRECT_PERIOD_LINE_NUMS_CIF;
				break;
			case SIV120B_DIRECT_VGA_FORMAT:
				SIV120B_DIRECT_write_cmos_sensor(0x05,0x07);
				SIV120B_DIRECT_PERIOD_PIXEL_NUMS = SIV120B_DIRECT_PERIOD_PIXEL_NUMS_VGA;
				SIV120B_DIRECT_PERIOD_LINE_NUMS   = SIV120B_DIRECT_PERIOD_LINE_NUMS_VGA;
				break;
			default:
				ASSERT(0);
		}
}
/* MT6253EL */
/* please update parameters by SIV120B_DIRECT_set_sensor_info() */
MM_ERROR_CODE_ENUM SIV120B_DIRECT_sensor_resume(void);

static void SIV120B_DIRECT_Preview(image_sensor_exposure_window_struct *pImage_Window, image_sensor_config_struct *pSensor_Config_Data)
{
    kal_uint8 iStartX = 0, iStartY = 1;
    kal_bool  SIV120B_DIRECT_Mode_temp = KAL_FALSE;
	//MM_ERROR_CODE_ENUM test;

	kal_prompt_trace(MOD_ENG,"entry preview");
	SIV120B_DIRECT_StillMode(KAL_FALSE);//disable mode
	SIV120B_DIRECT_OutputFormat(SIV120B_DIRECT_QVGA_FORMAT);//hunk
    /* direct RGB565 */
    SET_CAMERA_INPUT_TYPE(INPUT_RGB);
    SIV120B_DIRECT_set_page(3);
    SIV120B_DIRECT_write_cmos_sensor(0x12,0x0B);

#ifdef    SIV120B_DIRECT_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "Preview");
#endif
	switch (pSensor_Config_Data->isp_op_mode)
	{
		case ISP_MJPEG_PREVIEW_MODE:
		case ISP_MJPEG_ENCODE_MODE:
#ifdef     SIV120B_DIRECT_DEBUG
			kal_wap_trace(MOD_ENG,TRACE_INFO, "MJPEG");
#endif
			 SIV120B_DIRECT_Mode_temp = KAL_TRUE;
#if (defined(DRV_ISP_YUV_BURST_MODE_SUPPORT))
			 SIV120B_DIRECT_Min_Fps_Normal = 15 *  SIV120B_DIRECT_FRAME_RATE_UNIT; //normal 15fps night 7.5 fps
#else
			 SIV120B_DIRECT_Min_Fps_Normal = 15 *  SIV120B_DIRECT_FRAME_RATE_UNIT; //normal 10fps night 5 fps
#endif
			 SIV120B_DIRECT_Min_Fps_Night =  SIV120B_DIRECT_Min_Fps_Normal >> 1;
			 SIV120B_DIRECT_FixFrameRate(KAL_TRUE);
			 //SIV120B_DIRECT_cal_fps();

                         pImage_Window->exposure_window_width = SIV120B_DIRECT_IMAGE_SENSOR_QVGA_WIDTH - 2 * iStartX;
                         pImage_Window->exposure_window_height = SIV120B_DIRECT_IMAGE_SENSOR_QVGA_HEIGHT - 2 * iStartY;
                         sensor_para_set.sensor_valid_width 	= SIV120B_DIRECT_IMAGE_SENSOR_QVGA_WIDTH;
                         sensor_para_set.sensor_valid_height 	= SIV120B_DIRECT_IMAGE_SENSOR_QVGA_HEIGHT;
			break;

		case ISP_MPEG4_PREVIEW_MODE:
		case ISP_MPEG4_ENCODE_MODE:
			SIV120B_DIRECT_Mode_temp = KAL_TRUE;
			if (pImage_Window->image_target_width == 240 && pImage_Window->image_target_height ==180)//QVGA branch
			{
				   SIV120B_DIRECT_Min_Fps_Normal = 10 * SIV120B_DIRECT_FRAME_RATE_UNIT;
				   SIV120B_DIRECT_Min_Fps_Night = SIV120B_DIRECT_Min_Fps_Normal >> 1;
                                   SIV120B_DIRECT_FixFrameRate(KAL_TRUE);
					 SIV120B_DIRECT_Dummy_Pixel = 375; // Tuned for video 10fps

				   pImage_Window->exposure_window_width = SIV120B_DIRECT_IMAGE_SENSOR_QVGA_WIDTH - 2 * iStartX;
                                   pImage_Window->exposure_window_height = SIV120B_DIRECT_IMAGE_SENSOR_QVGA_HEIGHT - 2 * iStartY;
                                   sensor_para_set.sensor_valid_width 	= SIV120B_DIRECT_IMAGE_SENSOR_QVGA_WIDTH;
                                   sensor_para_set.sensor_valid_height 	= SIV120B_DIRECT_IMAGE_SENSOR_QVGA_HEIGHT;
			}
			else//Qcif branch
			{
				   //SIV120B_DIRECT_OutputFormat(SIV120B_DIRECT_QCIF_FORMAT);//hunk
				   SIV120B_DIRECT_Min_Fps_Normal = 15 * SIV120B_DIRECT_FRAME_RATE_UNIT;
			           SIV120B_DIRECT_Min_Fps_Night = SIV120B_DIRECT_Min_Fps_Normal >> 1;
			           SIV120B_DIRECT_FixFrameRate(KAL_TRUE);
			           //SIV120B_DIRECT_cal_fps();

        			   pImage_Window->exposure_window_width = SIV120B_DIRECT_IMAGE_SENSOR_QVGA_WIDTH - 2 * iStartX;
                                   pImage_Window->exposure_window_height = SIV120B_DIRECT_IMAGE_SENSOR_QVGA_HEIGHT - 2 * iStartY;
                                   sensor_para_set.sensor_valid_width 	= SIV120B_DIRECT_IMAGE_SENSOR_QVGA_WIDTH;
                                   sensor_para_set.sensor_valid_height 	= SIV120B_DIRECT_IMAGE_SENSOR_QVGA_HEIGHT;
			}			
			break;

#ifdef __MEDIA_VT__
/* under construction !*/
#ifdef     SIV120B_DIRECT_DEBUG
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

		default: /* ISP_PREVIEW_MODE */
			/* config TG for camera preview mode */
			 SIV120B_DIRECT_Mode_temp = KAL_FALSE;

                         SIV120B_DIRECT_FixFrameRate(KAL_FALSE);
			 SIV120B_DIRECT_Dummy_Pixel = 0x01;
			 SIV120B_DIRECT_Min_Fps_Normal = 10 *  SIV120B_DIRECT_FRAME_RATE_UNIT;//normal 10fps night 5 fps  hunk
			 SIV120B_DIRECT_Min_Fps_Night =  SIV120B_DIRECT_Min_Fps_Normal >> 1;			 
//			 SIV120B_DIRECT_cal_fps();

                      pImage_Window->exposure_window_width = SIV120B_DIRECT_IMAGE_SENSOR_QVGA_WIDTH - 2 * iStartX;
                      pImage_Window->exposure_window_height = SIV120B_DIRECT_IMAGE_SENSOR_QVGA_HEIGHT - 2 * iStartY;
                      sensor_para_set.sensor_valid_width 	= SIV120B_DIRECT_IMAGE_SENSOR_QVGA_WIDTH;
                      sensor_para_set.sensor_valid_height 	= SIV120B_DIRECT_IMAGE_SENSOR_QVGA_HEIGHT;
#ifdef     SIV120B_DIRECT_DEBUG
			kal_wap_trace(MOD_ENG,TRACE_INFO, "Camera");
#endif
	}
	if ( SIV120B_DIRECT_Mode_temp !=  SIV120B_DIRECT_Video_Mode)
	{
		 SIV120B_DIRECT_Video_Mode =  SIV120B_DIRECT_Mode_temp;
		 SIV120B_DIRECT_Mode_change = KAL_TRUE;
	}
	SIV120B_DIRECT_cal_fps();
    //SIV120B_DIRECT_Dummy_Pixel = 0x1c;
    SIV120B_DIRECT_HVmirror(pSensor_Config_Data->image_mirror);
#if (defined(__DYNAMIC_SENSOR_DELAY__ ))
    pImage_Window->wait_stable_frame = 3 ;
#endif
    pImage_Window->grab_start_x = iStartX;
    pImage_Window->grab_start_y = iStartY;
//    pImage_Window->exposure_window_width = SIV120B_DIRECT_IMAGE_SENSOR_QVGA_WIDTH - 2 * iStartX;
//    pImage_Window->exposure_window_height = SIV120B_DIRECT_IMAGE_SENSOR_QVGA_HEIGHT - 2 * iStartY;

    /* direct sensor v2 */
    sensor_para_set.sensor_pclk 		= SIV120B_DIRECT_PCLK;//6000000;
    sensor_para_set.sensor_valid_start_x = pImage_Window->grab_start_x;
    sensor_para_set.sensor_valid_start_y = pImage_Window->grab_start_y;
    sensor_para_set.target_width		= pImage_Window->image_target_width;
    sensor_para_set.target_height		= pImage_Window->image_target_height;
    SIV120B_DIRECT_set_interface_info(  (kal_uint8 *)(&sensor_para_set) ); 
	//test = SIV120B_DIRECT_sensor_resume();//hunk add for test
	kal_prompt_trace(MOD_ENG,"exit preview");
}   /* SIV120B_DIRECT_Preview */


/*************************************************************************
* FUNCTION
*   SID201A_Capture
*
* DESCRIPTION
*   This function configures the sensor to capture mode.
*
* PARAMETERS
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
/* MT6253EL */
/* capture will keep YUV mode */
void SIV120B_DIRECT_P2CFactor_Setting(kal_uint8 pShutstep,kal_uint8 cShutstep)
{
	kal_uint32 P2CFactor;
	P2CFactor = cShutstep * 64 / pShutstep;
	//kal_prompt_trace(MOD_ENG,"P2CFactor = %d",P2CFactor);
	SIV120B_DIRECT_bank_write_cmos_sensor(0x0136,P2CFactor & 0xff);
}

static void SIV120B_DIRECT_Capture(image_sensor_exposure_window_struct *pImage_Window, image_sensor_config_struct *pSensor_Config_Data)
{
    kal_uint8 iStartX = 0, iStartY = 1;
    kal_uint8 SIV120B_DIRECT_cShutter_step;
    /* SIV120B_DIRECT support YUV422 capture */
    SET_CAMERA_INPUT_TYPE(INPUT_YUV422);
    SIV120B_DIRECT_set_page(3);
    SIV120B_DIRECT_write_cmos_sensor(0x12,0xDD); // Y,Cb,Cr order sequence //1D/9D/0D/3D
    //SIV120B_DIRECT_write_cmos_sensor(0x12,0x8D);
    SET_CAMERA_INPUT_ORDER(INPUT_ORDER_CbYCrY1);
    SIV120B_DIRECT_OutputFormat(SIV120B_DIRECT_VGA_FORMAT);

#ifdef    SIV120B_DIRECT_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "Capture");
#endif
    if (pSensor_Config_Data->frame_rate == 0xF0)
    {
    	SIV120B_DIRECT_OutputFormat(SIV120B_DIRECT_VGA_FORMAT);  
#ifdef    SIV120B_DIRECT_DEBUG
        kal_wap_trace(MOD_ENG,TRACE_INFO, "WebCam");
#endif
#if (defined(__DYNAMIC_SENSOR_DELAY__ ))
        pImage_Window->wait_stable_frame = 3 ;
#endif
       // pImage_Window->wait_ae_frame = 0;
    }
    else
    {   /* Normal camera capture mode  */
        if (pImage_Window->image_target_width <= SIV120B_DIRECT_IMAGE_SENSOR_VGA_WIDTH &&
            pImage_Window->image_target_height <= SIV120B_DIRECT_IMAGE_SENSOR_VGA_HEIGHT)
        {
            SIV120B_DIRECT_OutputFormat(SIV120B_DIRECT_VGA_FORMAT);   
            SIV120B_DIRECT_set_page(1);
	    //SIV120B_DIRECT_Set_cShutter_Step();
            //SIV120B_DIRECT_write_cmos_sensor(0x35, 0x3e); // 1/2 divide
            SIV120B_DIRECT_cshutter_step = SIV120B_DIRECT_pshutter_step;
	    SIV120B_DIRECT_write_cmos_sensor(0x35, SIV120B_DIRECT_cshutter_step); 
            SIV120B_DIRECT_P2CFactor_Setting(SIV120B_DIRECT_pshutter_step,SIV120B_DIRECT_cshutter_step);
            //SIV120B_DIRECT_write_cmos_sensor(0x36, 0x20); // 1/2 = x/64, x=32
            SIV120B_DIRECT_Control = SIV120B_DIRECT_Control & 0xE3 | 0x10;  // set CLK divider = 1/1 & Still mode change
        }

        SIV120B_DIRECT_set_page(0);
        SIV120B_DIRECT_write_cmos_sensor(0x04, SIV120B_DIRECT_Control);
    }

    pImage_Window->grab_start_x = iStartX;
    pImage_Window->grab_start_y = iStartY;
    pImage_Window->exposure_window_width = SIV120B_DIRECT_IMAGE_SENSOR_VGA_WIDTH - 2 * iStartX;
    pImage_Window->exposure_window_height = SIV120B_DIRECT_IMAGE_SENSOR_VGA_HEIGHT - 2 *  iStartY;

}   /* SIV120B_DIRECT_Capture() */

/*************************************************************************
* FUNCTION
*   SIV120B_DIRECT_WriteReg
*
* DESCRIPTION
*   This function set the register of SIV120B_DIRECT.
*
* PARAMETERS
*   iAddr : the register index of SIV120B_DIRECT
*   iPara : setting parameter of the specified register of SIV120B_DIRECT
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void SIV120B_DIRECT_WriteReg(kal_uint32 iAddr, kal_uint32 iPara)
{
    SIV120B_DIRECT_write_cmos_sensor(iAddr, iPara);
}/* SIV120B_DIRECT_WriteReg() */

/*************************************************************************
* FUNCTION
*   read_cmos_sensor
*
* DESCRIPTION
*   This function read parameter of specified register from SIV120B_DIRECT.
*
* PARAMETERS
*   iAddr: the register index of SIV120B_DIRECT
*
* RETURNS
*   the data that read from SIV120B_DIRECT
*
* GLOBALS AFFECTED
*
*************************************************************************/
static kal_uint32 SIV120B_DIRECT_ReadReg(kal_uint32 iAddr)
{
    return SIV120B_DIRECT_read_cmos_sensor(iAddr);
}   /* SIV120B_DIRECT_ReadReg() */

/*************************************************************************
* FUNCTION
*   SIV120B_DIRECT_SetShutter
*
* DESCRIPTION
*   This function set e-shutter of SIV120B_DIRECT to change exposure time.
*
* PARAMETERS
*   shutter : exposured lines
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void SIV120B_DIRECT_SetShutter(kal_uint16 shutter)
{
    /* No use for YUV sensor */
	SIV120B_DIRECT_bank_write_cmos_sensor(0x0134,shutter);
}   /* SIV120B_DIRECT_SetShutter */


/*************************************************************************
* FUNCTION
*   SIV120B_DIRECT_SetGain
*
* DESCRIPTION
*   This function is to set global gain to sensor.
*
* PARAMETERS
*   iGain : sensor global gain(base: 0x40)
*
* RETURNS
*   the actually gain set to sensor.
*
* GLOBALS AFFECTED
*
*************************************************************************/
static kal_uint16 SIV120B_DIRECT_SetGain(kal_uint16 iGain)
{
    /* No use for YUV sensor */
    return iGain;
}   /* SIV120B_DIRECT_SetGain */

/*************************************************************************
* FUNCTION
*   SIV120B_DIRECT_NightMode
*
* DESCRIPTION
*   This function switch on/off night mode of SIV120B_DIRECT.
*
*************************************************************************/
static void SIV120B_DIRECT_NightMode(kal_bool bEnable)
{
#ifdef    SIV120B_DIRECT_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "NightMode %d",bEnable);
#endif
	kal_prompt_trace(MOD_ENG,"entry nightmode");
    if((SIV120B_DIRECT_g_bNightMode == bEnable) && (SIV120B_DIRECT_Mode_change == KAL_FALSE))
        return;

    SIV120B_DIRECT_g_bNightMode = bEnable;
    SIV120B_DIRECT_Mode_change = KAL_FALSE;

    if ( SIV120B_DIRECT_Video_Mode == KAL_FALSE)// camera mode
    {
        if (SIV120B_DIRECT_g_bNightMode == KAL_TRUE)
        {   /* camera night mode */
#ifdef SIV120B_DIRECT_DEBUG
            kal_wap_trace(MOD_ENG,TRACE_INFO, "camera night mode");
#endif
            SIV120B_DIRECT_set_page(1);
            SIV120B_DIRECT_write_cmos_sensor(0x40,0x6c); //Max Analog Gain Value @ Shutter step = Max Shutter step  0x7D
            SIV120B_DIRECT_set_page(3);
            SIV120B_DIRECT_write_cmos_sensor(0xAB,0x0d); //Brightness Control 0x11
            SIV120B_DIRECT_write_cmos_sensor(0xB9,0x14); //Color Suppression Change Start State  0x17
            SIV120B_DIRECT_write_cmos_sensor(0xBA,0x40); //Slope
        }
        else
        {   /* camera normal mode */
#ifdef SIV120B_DIRECT_DEBUG
            kal_wap_trace(MOD_ENG,TRACE_INFO, "camera normal mode");
#endif
            SIV120B_DIRECT_set_page(1);
            SIV120B_DIRECT_write_cmos_sensor(0x40,0x66);// 0x7F
            SIV120B_DIRECT_set_page(3);
            SIV120B_DIRECT_write_cmos_sensor(0xAB,0x02); //0x04
            SIV120B_DIRECT_write_cmos_sensor(0xB9,0x18);
            SIV120B_DIRECT_write_cmos_sensor(0xBA,0x30); //Slope
        }
    }
    else //video mode
    {
        SIV120B_DIRECT_cal_fps();
        if (SIV120B_DIRECT_g_bNightMode == KAL_TRUE)
        {   /* video night mode */
#ifdef SIV120B_DIRECT_DEBUG
            kal_wap_trace(MOD_ENG,TRACE_INFO, "video night mode");
#endif
        }
        else
        {   /* video normal mode */
#ifdef SIV120B_DIRECT_DEBUG
            kal_wap_trace(MOD_ENG,TRACE_INFO, "video normal mode");
#endif
        }
    }
    SIV120B_DIRECT_Set_Frame_Count();
	kal_prompt_trace(MOD_ENG,"exit nightmode");
}   /* SIV120B_DIRECT_NightMode */


/*************************************************************************
* FUNCTION
 *  SIV120B_DIRECT_SetFlash
*
* DESCRIPTION
*   turn on/off SIV120B_DIRECT flashlight .
*
* PARAMETERS
*   bEnable:
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void SIV120B_DIRECT_SetFlash(kal_bool bEnable)
{
    /*SIV120B_DIRECT can't support the function */
}   /* SIV120B_DIRECT_SetFlash */

/*************************************************************************
* FUNCTION
*   SIV120B_DIRECT_Set_Para_WB
*
* DESCRIPTION
*   SIV120B_DIRECT WB setting.
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
static kal_uint32 SIV120B_DIRECT_Set_Para_WB(kal_uint32 iPara)
{
#ifdef    SIV120B_DIRECT_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "WB %d",iPara);
#endif

    SIV120B_DIRECT_set_page(2);    //bank 2
    switch (iPara)
    {
        case CAM_WB_AUTO:   // enable AWB
            // CAM_WB_AUTO mode should not update R/G/B gains
            SIV120B_DIRECT_write_cmos_sensor(0x10, 0xD3);
            return KAL_TRUE;

        case CAM_WB_CLOUD:
            SIV120B_DIRECT_write_cmos_sensor(0x10, 0x00);  // disable AWB
            SIV120B_DIRECT_write_cmos_sensor(0x60, 0xD0);
            SIV120B_DIRECT_write_cmos_sensor(0x61, 0x88);
            break;

        case CAM_WB_DAYLIGHT:
            SIV120B_DIRECT_write_cmos_sensor(0x10, 0x00);  // disable AWB
            SIV120B_DIRECT_write_cmos_sensor(0x60, 0xC2);
            SIV120B_DIRECT_write_cmos_sensor(0x61, 0x9E);
            break;

        case CAM_WB_INCANDESCENCE:
            SIV120B_DIRECT_write_cmos_sensor(0x10, 0x00);  // disable AWB
            SIV120B_DIRECT_write_cmos_sensor(0x60, 0x98);
            SIV120B_DIRECT_write_cmos_sensor(0x61, 0xC8);
            break;

        case CAM_WB_FLUORESCENT:
            SIV120B_DIRECT_write_cmos_sensor(0x10, 0x00);  // disable AWB
            SIV120B_DIRECT_write_cmos_sensor(0x60, 0xAA);
            SIV120B_DIRECT_write_cmos_sensor(0x61, 0xBE);
            break;

        case CAM_WB_TUNGSTEN:
            SIV120B_DIRECT_write_cmos_sensor(0x10, 0x00);  // disable AWB
            SIV120B_DIRECT_write_cmos_sensor(0x60, 0x90);
            SIV120B_DIRECT_write_cmos_sensor(0x61, 0xC0);
            break;

        case CAM_WB_MANUAL:
        default:
            return KAL_FALSE;
    }
    return KAL_TRUE;
}   /* SIV120B_DIRECT_Set_Para_WB */

/*************************************************************************
* FUNCTION
*   SIV120B_DIRECT_Set_Para_EV
*
* DESCRIPTION
*   SIV120B_DIRECT exposure setting.
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
static kal_uint32 SIV120B_DIRECT_Set_Para_EV(kal_uint32 iPara)
{
    SIV120B_DIRECT_set_page(1); //bank 1
#ifdef    SIV120B_DIRECT_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "EV %d",iPara);
#endif

    switch (iPara)
    {
        case CAM_EV_NEG_4_3:    // -4 EV
            SIV120B_DIRECT_write_cmos_sensor(0x12,0x44);
            SIV120B_DIRECT_write_cmos_sensor(0x13,0x44);
            SIV120B_DIRECT_write_cmos_sensor(0x14,0x44);
            break;

        case CAM_EV_NEG_3_3:    // -3 EV
            SIV120B_DIRECT_write_cmos_sensor(0x12,0x54);
            SIV120B_DIRECT_write_cmos_sensor(0x13,0x54);
            SIV120B_DIRECT_write_cmos_sensor(0x14,0x54);
            break;

        case CAM_EV_NEG_2_3:    // -2 EV
            SIV120B_DIRECT_write_cmos_sensor(0x12,0x64);
            SIV120B_DIRECT_write_cmos_sensor(0x13,0x64);
            SIV120B_DIRECT_write_cmos_sensor(0x14,0x64);
            break;

        case CAM_EV_NEG_1_3:    // -1 EV
            SIV120B_DIRECT_write_cmos_sensor(0x12,0x74);
            SIV120B_DIRECT_write_cmos_sensor(0x13,0x74);
            SIV120B_DIRECT_write_cmos_sensor(0x14,0x74);
            break;

        case CAM_EV_ZERO:   // +0 EV
            SIV120B_DIRECT_write_cmos_sensor(0x12,0x80); //0x84
            SIV120B_DIRECT_write_cmos_sensor(0x13,0x80);
            SIV120B_DIRECT_write_cmos_sensor(0x14,0x80);
            break;

        case CAM_EV_POS_1_3:    // +1 EV
            SIV120B_DIRECT_write_cmos_sensor(0x12,0x94);
            SIV120B_DIRECT_write_cmos_sensor(0x13,0x94);
            SIV120B_DIRECT_write_cmos_sensor(0x14,0x94);
            break;

        case CAM_EV_POS_2_3:    // +2 EV
            SIV120B_DIRECT_write_cmos_sensor(0x12,0xA4);
            SIV120B_DIRECT_write_cmos_sensor(0x13,0xA4);
            SIV120B_DIRECT_write_cmos_sensor(0x14,0xA4);
            break;

        case CAM_EV_POS_3_3:    // +3 EV
            SIV120B_DIRECT_write_cmos_sensor(0x12,0xB4);
            SIV120B_DIRECT_write_cmos_sensor(0x13,0xB4);
            SIV120B_DIRECT_write_cmos_sensor(0x14,0xB4);
            break;

        case CAM_EV_POS_4_3:    // +4 EV
            SIV120B_DIRECT_write_cmos_sensor(0x12,0xC4);
            SIV120B_DIRECT_write_cmos_sensor(0x13,0xC4);
            SIV120B_DIRECT_write_cmos_sensor(0x14,0xC4);
            break;

        default:
            return KAL_FALSE;
    }
    return KAL_TRUE;
}   /* SIV120B_DIRECT_Set_Para_EV */

/*************************************************************************
* FUNCTION
*   SIV120B_DIRECT_Set_Para_Banding
*
* DESCRIPTION
*   SIV120B_DIRECT banding setting.
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
static kal_uint32 SIV120B_DIRECT_Set_Para_Banding(kal_uint32 iPara)
{
#ifdef    SIV120B_DIRECT_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "Banding %d",iPara);
#endif
	kal_prompt_trace(MOD_ENG,"entry banding");

    if(SIV120B_DIRECT_g_iBanding == iPara)
        return KAL_TRUE;

    SIV120B_DIRECT_g_iBanding = iPara;
    SIV120B_DIRECT_Set_pShutter_Step();
    SIV120B_DIRECT_Set_Frame_Count();
	kal_prompt_trace(MOD_ENG,"exit banding");

    return KAL_TRUE;
}   /* SIV120B_DIRECT_Set_Para_Banding */

/*************************************************************************
* FUNCTION
*   SIV120B_DIRECT_Set_Para_NightMode
*
* DESCRIPTION
*   SIV120B_DIRECT night mode setting.
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
static kal_uint32 SIV120B_DIRECT_Set_Para_NightMode(kal_uint32 iPara)
{
    SIV120B_DIRECT_NightMode((kal_bool) iPara);
    return KAL_TRUE;
}   /* SIV120B_DIRECT_Set_Para_NightMode */

/*************************************************************************
* FUNCTION
*   SIV120B_DIRECT_Set_Para_AE_Meter
*
* DESCRIPTION
*   SIV120B_DIRECT AE metering mode
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
static kal_uint32 SIV120B_DIRECT_Set_Para_AE_Meter(kal_uint32 iPara)
{
    SIV120B_DIRECT_set_page(1); //bank 1
#ifdef    SIV120B_DIRECT_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "AE_Meter %d",iPara);
#endif
    switch (iPara)
    {
        case CAM_AE_METER_AUTO: // NORMAL mode AE metering : window setting change
            SIV120B_DIRECT_write_cmos_sensor(0x60, 0xFF);
            SIV120B_DIRECT_write_cmos_sensor(0x61, 0xFF);
            SIV120B_DIRECT_write_cmos_sensor(0x62, 0xFF);
            SIV120B_DIRECT_write_cmos_sensor(0x63, 0xFF);
            SIV120B_DIRECT_write_cmos_sensor(0x64, 0xFF);
            SIV120B_DIRECT_write_cmos_sensor(0x65, 0xFF);

            SIV120B_DIRECT_write_cmos_sensor(0x66, 0x00);
            SIV120B_DIRECT_write_cmos_sensor(0x67, 0x50);
            SIV120B_DIRECT_write_cmos_sensor(0x68, 0x50);
            SIV120B_DIRECT_write_cmos_sensor(0x69, 0x50);
            SIV120B_DIRECT_write_cmos_sensor(0x6A, 0x50);
            SIV120B_DIRECT_write_cmos_sensor(0x6B, 0x00);

            SIV120B_DIRECT_g_iAE_Meter = CAM_AE_METER_AUTO;
            break;

        case CAM_AE_METER_SPOT: // SPOT mode AE metering : window setting change
            SIV120B_DIRECT_write_cmos_sensor(0x60, 0x18);
            SIV120B_DIRECT_write_cmos_sensor(0x61, 0x7E);
            SIV120B_DIRECT_write_cmos_sensor(0x62, 0xFF);
            SIV120B_DIRECT_write_cmos_sensor(0x63, 0xFF);
            SIV120B_DIRECT_write_cmos_sensor(0x64, 0x7E);
            SIV120B_DIRECT_write_cmos_sensor(0x65, 0x18);

            SIV120B_DIRECT_write_cmos_sensor(0x66, 0x00);
            SIV120B_DIRECT_write_cmos_sensor(0x67, 0xA0);
            SIV120B_DIRECT_write_cmos_sensor(0x68, 0xA0);
            SIV120B_DIRECT_write_cmos_sensor(0x69, 0xA0);
            SIV120B_DIRECT_write_cmos_sensor(0x6A, 0xA0);
            SIV120B_DIRECT_write_cmos_sensor(0x6B, 0x00);

            SIV120B_DIRECT_g_iAE_Meter = CAM_AE_METER_SPOT;
            break;

        default:
            return KAL_FALSE;
    }
    return KAL_TRUE;
}   /* SIV120B_DIRECT_Set_Para_AE_Meter */

/*************************************************************************
* FUNCTION
*   SIV120B_DIRECT_Set_Para_Effect
*
* DESCRIPTION
*   SIV120B_DIRECT
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
static kal_uint32 SIV120B_DIRECT_Set_Para_Effect(kal_uint32 iPara)
{
#ifdef    SIV120B_DIRECT_DEBUG
    kal_wap_trace(MOD_ENG,TRACE_INFO, "Effect %d",iPara);
#endif
    SIV120B_DIRECT_set_page(3);  //bank 3
    switch (iPara)
    {
        case CAM_EFFECT_ENC_NORMAL:
            SIV120B_DIRECT_write_cmos_sensor(0xB6, 0x00);
            break;

        case CAM_EFFECT_ENC_GRAYSCALE:
            SIV120B_DIRECT_write_cmos_sensor(0xB6, 0x40);
            break;

        case CAM_EFFECT_ENC_SEPIA:
            SIV120B_DIRECT_write_cmos_sensor(0xB6, 0x80);
            SIV120B_DIRECT_write_cmos_sensor(0xB7, 0x60);
            SIV120B_DIRECT_write_cmos_sensor(0xB8, 0xA0);
            break;

        case CAM_EFFECT_ENC_SEPIAGREEN:
            SIV120B_DIRECT_write_cmos_sensor(0xB6, 0x80);
            SIV120B_DIRECT_write_cmos_sensor(0xB7, 0x50);
            SIV120B_DIRECT_write_cmos_sensor(0xB8, 0x50);
            break;

        case CAM_EFFECT_ENC_SEPIABLUE:
            SIV120B_DIRECT_write_cmos_sensor(0xB6, 0x80);
            SIV120B_DIRECT_write_cmos_sensor(0xB7, 0xC0);
            SIV120B_DIRECT_write_cmos_sensor(0xB8, 0x60);
            break;

        case CAM_EFFECT_ENC_COLORINV:
            SIV120B_DIRECT_write_cmos_sensor(0xB6, 0x10);
            break;

        case CAM_EFFECT_ENC_GRAYINV:
            SIV120B_DIRECT_write_cmos_sensor(0xB6, 0x20);
            break;

        case CAM_EFFECT_ENC_EMBOSSMENT:
            SIV120B_DIRECT_write_cmos_sensor(0xB6, 0x08);
            break;

        default:
            return KAL_FALSE;
    }
    return KAL_TRUE;
}   /* SIV120B_DIRECT_Set_Para_Effect */

#ifdef __PANORAMA_VIEW_SUPPORT__
/*************************************************************************
* FUNCTION
*    SIV120B_DIRECT_set_param_3a_enable
*
* DESCRIPTION
*    disable/enable 3a
*
* PARAMETERS
*    para
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint32 SIV120B_DIRECT_set_param_3a_enable(kal_uint32 para)
{
  kal_uint8 seq_preview_ae,seq_preview_awb;

  if (para)
  {
	  seq_preview_ae = 0x80;
	  seq_preview_awb = 0xD3;
  }
  else
  {
	  seq_preview_ae = 0x00;
	  seq_preview_awb = 0x00;
  }
#ifdef SIV120B_DIRECT_DEBUG
	  kal_prompt_trace(MOD_ENG,"3a_enable:%d",para);
#endif

  SIV120B_DIRECT_set_page(1);
  SIV120B_DIRECT_write_cmos_sensor(0x10, seq_preview_ae);
  SIV120B_DIRECT_set_page(2);
  SIV120B_DIRECT_write_cmos_sensor(0x10, seq_preview_awb);

  return KAL_TRUE;
}
#endif

#if (defined(SENSOR_COMMON_INTERFACE_SUPPORT))
/*************************************************************************
* FUNCTION
*    SIV120B_video_frame_rate
*
* DESCRIPTION
*    This function get video frame rate to upper layer
*
* PARAMETERS
*    out
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM SIV120B_DIRECT_video_frame_rate(PSENSOR_FLEXIBLE_VIDEO_FRAMERATE_STRUCT out)
{

  out->current_video_frame_rate = SIV120B_DIRECT_g_bNightMode ? SIV120B_DIRECT_Min_Fps_Night : SIV120B_DIRECT_Min_Fps_Normal;

  return ERROR_NONE;
}

MM_ERROR_CODE_ENUM SIV120B_DIRECT_get_common_info(PSENSOR_COMMON_INFO_STRUCT out)
{
	out->sensor_if_type = SENSOR_IF_DIRECT;
	out->preview_data_format = SENSOR_DATA_FORMAT_RGB565;
	out->capture_data_format = SENSOR_DATA_FORMAT_YUV422_VYUY;
	out->video_data_format = SENSOR_DATA_FORMAT_RGB565;
	out->sensor_preview_height = 480;
	out->sensor_preview_width = 640;
	out->sensor_full_height = 480;
	out->sensor_full_width = 640;
	out->sensor_video_height = 480;
	out->sensor_video_width = 640;
	return ERROR_NONE;
}

MM_ERROR_CODE_ENUM SIV120B_DIRECT_sensor_pause(void)
{
	#ifdef SIV120B_DIRECT_DEBUG
		kal_prompt_trace(MOD_ENG, "SIV120B_Pause(): in");
	#endif
		SIV120B_DIRECT_bank_write_cmos_sensor(0x0003, 0x01|cntr_a_driving);//bank_write_cmos_sensor(0x0003, 0x01|cntr_a_driving);// bank_write_cmos_sensor(0x0103, cntr_a_driving|0x01);//SETi suggest (2)SW standby-->Normal, register reserved
	#ifdef SIV120B_DIRECT_DEBUG
		kal_prompt_trace(MOD_ENG, "SIV120B_Pause(): out");
	#endif
	return ERROR_NONE;
}

MM_ERROR_CODE_ENUM SIV120B_DIRECT_sensor_resume(void)
{

	SIV120B_DIRECT_bank_write_cmos_sensor(0x0003, 0x05|cntr_a_driving);//bank_write_cmos_sensor(0x0003, 0x05|cntr_a_driving);
	kal_prompt_trace(MOD_ENG, "SIV120B_resume(): out");
	return ERROR_NONE;
}

MM_ERROR_CODE_ENUM SIV120B_DIRECT_set_sensor_mode(PSENSOR_SET_MODE_STRUCT in)
{
	switch(in->sensor_mode)
	{
		case SENSOR_MODE_PAUSE:
			return SIV120B_DIRECT_sensor_pause();
		break;
		case SENSOR_MODE_RESUME:
			return SIV120B_DIRECT_sensor_resume();
		break;
	}
	return ERROR_SENSOR_FEATURE_NOT_SUPPORT;
}

/*************************************************************************
* FUNCTION
*    SIV120B_feature_control
*
* DESCRIPTION
*    This function provide lots of features for upper layer
*
* PARAMETERS
*    feature_id
*    p_feature_para_input: input msg
*    p_feature_para_output: output msg
*    feature_para_output_length: output length
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM SIV120B_DIRECT_feature_control(IMAGE_SENSOR_FEATURE_ENUM feature_id, void *in, void *out, kal_uint16 out_len)
{
  switch (feature_id)
  {
  case SENSOR_FEATURE_VIDEO_FRAME_RATE:
    return SIV120B_DIRECT_video_frame_rate(((PSENSOR_FEATURE_CONTRL_STRUCT)out)->p_sensor_flexible_video_framerate);
    break;
 case SENSOR_FEATURE_GET_COMMON_INFO:
    return SIV120B_DIRECT_get_common_info(((PSENSOR_FEATURE_CONTRL_STRUCT)out)->pSensorCommonInfoPara);
    break;
 case SENSOR_FEATURE_GET_INTERFACE_INFO:
	/* direct sensor v2 */
 	return SIV120B_DIRECT_get_interface_info( (kal_uint8 *)((PSENSOR_FEATURE_CONTRL_STRUCT)out)->pSensorIfInforPara );
//        return SIV120B_DIRECT_get_interface_info(  (kal_uint8 *)((PSENSOR_FEATURE_CONTRL_STRUCT)in)->pSecSensorSetPara,
//                                                                                  (kal_uint8 *)((PSENSOR_FEATURE_CONTRL_STRUCT)out)->pSensorIfInforPara  );
    break;
 case SENSOR_FEATURE_SET_SENSOR_MODE:
    return SIV120B_DIRECT_set_sensor_mode(((PSENSOR_FEATURE_CONTRL_STRUCT)in)->pSensorSetModePara);
  default:
    return ERROR_SENSOR_FEATURE_NOT_SUPPORT;
    break;
  }
}

#endif

/*************************************************************************
* FUNCTION
*   SIV120B_DIRECT_YUV_SensorSetting
*
* DESCRIPTION
*   This function sends command and parameter to YUV-mode SIV120B_DIRECT to configure it
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
static kal_uint32 SIV120B_DIRECT_YUV_SensorSetting(kal_uint32 iCmd, kal_uint32 iPara)
{
    kal_uint32 iRet = KAL_FALSE;

    switch (iCmd)
    {
        case CAM_PARAM_WB:
            iRet = SIV120B_DIRECT_Set_Para_WB(iPara);
            break;

        case CAM_PARAM_EXPOSURE:
        case CAM_PARAM_EV_VALUE:
            iRet = SIV120B_DIRECT_Set_Para_EV(iPara);
            break;

        case CAM_PARAM_EFFECT:
            iRet = SIV120B_DIRECT_Set_Para_Effect(iPara);
            break;

        case CAM_PARAM_BANDING:
            iRet = SIV120B_DIRECT_Set_Para_Banding(iPara);
            break;

        case CAM_PARAM_NIGHT_MODE:
            iRet = SIV120B_DIRECT_Set_Para_NightMode(iPara);
            break;

        case CAM_PARAM_AE_METERING:
            iRet = SIV120B_DIRECT_Set_Para_AE_Meter(iPara);
            break;
#ifdef __PANORAMA_VIEW_SUPPORT__
		case CAM_PARAM_3A_ENABLE:
			iRet = SIV120B_DIRECT_set_param_3a_enable(iPara);
			break;
#endif
        default:
            return KAL_FALSE;
    }
    return iRet;
}   /* SIV120B_DIRECT_YUV_SensorSetting */

/*************************************************************************
* FUNCTION
*   image_sensor_func_OV76X0
*
* DESCRIPTION
*   OV76X0 Image Sensor functions struct.
*
* PARAMETERS
*   none
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static image_sensor_func_struct image_sensor_func_SIV120B_DIRECT =
{
    SIV120B_DIRECT_Init,
    SIV120B_DIRECT_Get_I2C_ID,
    SIV120B_DIRECT_GetSize,
    SIV120B_DIRECT_GetPeriod,
    SIV120B_DIRECT_Preview,
    SIV120B_DIRECT_Capture,
    SIV120B_DIRECT_WriteReg,
    SIV120B_DIRECT_ReadReg,
    SIV120B_DIRECT_SetShutter,
    SIV120B_DIRECT_NightMode,
    SIV120B_DIRECT_PowerOff,
    SIV120B_DIRECT_SetGain,
    SIV120B_DIRECT_SetFlash,
#if (defined(DRV_ISP_6238_SERIES))
    NULL,
    NULL,
#if (defined(MSHUTTER_SUPPORT))
    NULL,
    NULL,
#endif
#endif
#if (defined(SENSOR_COMMON_INTERFACE_SUPPORT))
    SIV120B_DIRECT_feature_control,
#endif
    SIV120B_DIRECT_YUV_SensorSetting
};  /* image_sensor_func_SIV120B_DIRECT */

/*************************************************************************
* FUNCTION
*   image_sensor_func_config
*
* DESCRIPTION
*   This function maps the external camera module function API structure.
*
* PARAMETERS
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void SIV120B_DIRECT_image_sensor_func_config(void)
{
    image_sensor_func = &image_sensor_func_SIV120B_DIRECT;
}   /* image_sensor_func_config() */


/*****************************************************************************
 * FUNCTION
 *  camera_para_to_sensor
 * DESCRIPTION
 *  This function write initial setting sequence into sensor's registers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SIV120B_DIRECT_camera_para_to_sensor(void)
{
    /* No use for YUV sensor */
}   /* camera_para_to_sensor */


/*****************************************************************************
 * FUNCTION
 *  sensor_to_camera_para
 * DESCRIPTION
 *  This function read back sensor's register values to camera_para structure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SIV120B_DIRECT_sensor_to_camera_para(void)
{
    /* No use for YUV sensor */
}   /* sensor_to_camera_para */

/* ------------------------Engineer mode--------------------------------- */
/********************************************************
*   Engineer mode is unnecessary for YUV sensor driver  *
********************************************************/


/*****************************************************************************
 * FUNCTION
 *  get_sensor_group_count
 * DESCRIPTION
 *
 * PARAMETERS
 *  pGroupCount     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void SIV120B_DIRECT_get_sensor_group_count(kal_int32 *pGroupCount)
{
    /* No use for YUV sensor */
}


/*****************************************************************************
 * FUNCTION
 *  get_sensor_group_info
 * DESCRIPTION
 *
 * PARAMETERS
 *  group_idx           [IN]
 *  group_name_ptr      [?]
 *  item_count_ptr      [?]
 * RETURNS
 *  void
 *****************************************************************************/
void SIV120B_DIRECT_get_sensor_group_info(kal_uint16 group_idx, kal_int8 *group_name_ptr, kal_int32 *item_count_ptr)
{
    /* No use for YUV sensor */
}


/*****************************************************************************
 * FUNCTION
 *  get_sensor_item_info
 * DESCRIPTION
 *
 * PARAMETERS
 *  group_idx       [IN]
 *  item_idx        [IN]
 *  info_ptr        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void SIV120B_DIRECT_get_sensor_item_info(kal_uint16 group_idx, kal_uint16 item_idx, ENG_sensor_info *info_ptr)
{
    /* No use for YUV sensor */
}


/*****************************************************************************
 * FUNCTION
 *  set_sensor_item_info
 * DESCRIPTION
 *
 * PARAMETERS
 *  group_idx       [IN]
 *  item_idx        [IN]
 *  item_value      [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_bool SIV120B_DIRECT_set_sensor_item_info(kal_uint16 group_idx, kal_uint16 item_idx, kal_int32 item_value)
{
    /* No use for YUV sensor */
    return KAL_TRUE;
}

void SIV120B_DIRECT_get_sensor_prefix_name(kal_char* buf){
    strcpy(buf, "SIV120B_DIRECT");
}

#if (defined(DRV_ISP_6238_SERIES))
void  SIV120B_DIRECT_dispatch_camera_info(void) {
       kal_mem_cpy(&dsc_support_info, &SIV120B_DIRECT_dsc_support_info, sizeof(camcorder_info_struct));
}
#endif

kal_uint32 SIV120B_DIRECT_get_valid_camera_type(void) {
#if(defined(SIV120B_DIRECT_YUV_MAIN))
    return  IMAGE_SENSOR_MAIN;
#elif(defined(SIV120B_DIRECT_YUV_SUB))
    return  IMAGE_SENSOR_SUB;
#elif(defined(SIV120B_DIRECT_YUV_BAK1))
    return  IMAGE_SENSOR_BAK1;
#elif(defined(SIV120B_DIRECT_YUV_SUB_BAK1))
    return  IMAGE_SENSOR_SUB_BAK1;
#endif

}

#ifdef SIV120B_DIRECT_DEBUG
 void at_test_func(kal_uint32 *d)
{
    switch (d[1])
    {
        case 0:
            kal_wap_trace(MOD_ENG,TRACE_INFO, "Read BB Reg %x = %x", d[2], DRV_Reg32((d[2])));
            break;

        case 1:
            DRV_Reg32((d[2])) = d[3];
            kal_wap_trace(MOD_ENG,TRACE_INFO, "Write BB Reg %x = %x", d[2], DRV_Reg32((d[2])));
            break;

        case 2:
            kal_wap_trace(MOD_ENG,TRACE_INFO, "Read Sensor %x = %x", d[2], SIV120B_DIRECT_bank_read_cmos_sensor(d[2]));
            break;

        case 3:
            SIV120B_DIRECT_bank_write_cmos_sensor(d[2], d[3]);
            kal_wap_trace(MOD_ENG,TRACE_INFO, "Write Sensor %x = %x", d[2], SIV120B_DIRECT_bank_read_cmos_sensor(d[2]));
            break;
        default:
            break;
    }
}
#endif



