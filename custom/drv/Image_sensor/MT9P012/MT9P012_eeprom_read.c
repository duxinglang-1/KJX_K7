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
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "IntrCtrl.h"
#include "reg_base.h"
#include "gpio_sw.h"
#include "isp_if.h"
//#include "camera_para.h"
#include "upll_ctrl.h"
//#include "med_api.h"
//#include "sensor_common.h"
//#include "camera_sccb.h"
#include "sccb_v2.h"
#include "med_utility.h"

#if (defined(SENSOR_COMMON_INTERFACE_SUPPORT))
 
#define __EEPROM_DEBUG_TRACE__


/*EEPROM DATA STRUCTURE*/
kal_uint32 eepromTag;
kal_uint32 eepromShadingTag;
kal_uint32 eepromShadingStart;

#define TAG_SINGLE_SLIM_SHADING            0x010200FF
#define TAG_DEFECT_SINGLE_SLIM_SHADING     0x010300FF
#define TAG_DYNAMIC_SLIM_SHADING           0x010400FF
#define TAG_DEFECT_DYNAMIC_SLIM_SHADING    0x010500FF
#define TAG_FIXED_SHADING                  0x010600FF
#define TAG_DEFECT_EIXED_SHADING           0x010700FF

#define SHADING_TAG_SINGLE_SLIM            0x010200FF
#define SHADING_TAG_DYNAMIC_SLIM           0x31520000
#define SHADING_TAG_FIXED                  0x39333236

#define TAG_ID_POS                         0x0000
#define TAG_ID_LENGTH                      0x0004
#define DEFECT_TABLE_LENGTH                0x0BF4
#define PREGAIN_LENGTH                     0x0004
#define PREGAIN_FACTORE_LENGTH             0x0004

#define SHADING_TAG_POS_OFFSET             0x0000
#define SHADING_PRV_TBL_SIZE_POS_OFFSET    0x0014
#define SHADING_CAP_TBL_SIZE_POS_OFFSET    0x0018
#define SHADING_PRV_REG_POS_OFFSET         0x001C
#define SHADING_CAP_REG_POS_OFFSET         0x0030
#define SHADING_TABLE_OFFSET               0x0044

#define SHADING_CAP_MAX_BLOCK_SIZE         72
#define SHADING_PRV_MAX_BLOCK_SIZE         30

/* SCCB Control*/ 
#define EEPROM_I2C_WRITE_ID                            0xAA
#define EEPROM_I2C_READ_ID                             0xAB
 
#ifdef MT9P012_HW_SCCB
    #define EEPROM_SCCB_FAST_MODE_SPEED_1            320 /* unit: Kb */
    #define EEPROM_SCCB_FAST_MODE_SPEED_2            380 /* unit: Kb */
#else
    #define EEPROM_SENSOR_I2C_DELAY                  40
    #define EEPROM_MAX_I2C_FAIL_TRY_NO               10
 
#define EEPROM_I2C_START_TRANSMISSION \
 { \
   volatile kal_uint32 j; \
   SET_SCCB_CLK_OUTPUT; \
   SET_SCCB_DATA_OUTPUT; \
   SET_SCCB_DATA_HIGH; \
   for (j = EEPROM_SENSOR_I2C_DELAY; j > 0; j--); \
       SET_SCCB_CLK_HIGH; \
   for (j = EEPROM_SENSOR_I2C_DELAY; j > 0; j--); \
       SET_SCCB_DATA_LOW; \
   for (j = EEPROM_SENSOR_I2C_DELAY; j > 0; j--); \
       SET_SCCB_CLK_LOW; \
   for (j = EEPROM_SENSOR_I2C_DELAY; j > 0; j--); \
 }
 
#define EEPROM_I2C_STOP_TRANSMISSION \
 { \
   volatile kal_uint32 j; \
   SET_SCCB_CLK_OUTPUT; \
   SET_SCCB_DATA_OUTPUT; \
   SET_SCCB_CLK_LOW; \
   SET_SCCB_DATA_LOW; \
   for (j = EEPROM_SENSOR_I2C_DELAY; j > 0; j--); \
       SET_SCCB_CLK_HIGH; \
   for (j = EEPROM_SENSOR_I2C_DELAY; j > 0; j--); \
       SET_SCCB_DATA_HIGH; \
 }
#endif
 
 extern kal_uint16 mmi_asc_to_ucs2(kal_char *pOutBuffer, kal_char *pInBuffer);
/**

#ifndef MT9P012_HW_SCCB
 static kal_uint8 eeprom_send_byte(kal_uint8 send_byte)
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
     for (j = EEPROM_SENSOR_I2C_DELAY; j > 0; j--);
     SET_SCCB_CLK_HIGH;
     for (j = EEPROM_SENSOR_I2C_DELAY; j > 0; j--);
     SET_SCCB_DATA_OUTPUT; /* just for delay /
     for (j = EEPROM_SENSOR_I2C_DELAY; j > 0; j--);
     SET_SCCB_CLK_LOW;
     for (j = EEPROM_SENSOR_I2C_DELAY; j > 0; j--);
   }
   SET_SCCB_DATA_INPUT;
   for (j = EEPROM_SENSOR_I2C_DELAY; j > 0; j--);
   SET_SCCB_CLK_HIGH;
   for (j = EEPROM_SENSOR_I2C_DELAY; j > 0; j--);
   ack = GET_SCCB_DATA_BIT;
   for (j = EEPROM_SENSOR_I2C_DELAY; j > 0; j--);
   SET_SCCB_CLK_LOW;
   for (j = EEPROM_SENSOR_I2C_DELAY; j > 0; j--);
   SET_SCCB_DATA_OUTPUT;
   
   return ack;
 }
 static kal_uint8 eeprom_get_byte(void)
 {
   volatile signed char i;
   volatile kal_uint32 j;
   kal_uint8 get_byte = 0;
 
   SET_SCCB_DATA_INPUT;
   for (i = 7; i >= 0; i--)
   {
     for (j = EEPROM_SENSOR_I2C_DELAY; j > 0; j--);
     SET_SCCB_CLK_HIGH;
     for (j = EEPROM_SENSOR_I2C_DELAY; j > 0; j--);
     if (GET_SCCB_DATA_BIT) get_byte |= (1 << i);
     for (j = EEPROM_SENSOR_I2C_DELAY; j > 0; j--);
     SET_SCCB_CLK_LOW;
     for (j = EEPROM_SENSOR_I2C_DELAY; j > 0; j--);
   }
   SET_SCCB_DATA_OUTPUT;
   SET_SCCB_DATA_LOW; //Ack
   for (j = EEPROM_SENSOR_I2C_DELAY; j > 0; j--);
   SET_SCCB_CLK_HIGH;
   for (j = EEPROM_SENSOR_I2C_DELAY; j > 0; j--);
   SET_SCCB_CLK_LOW;
   for (j = EEPROM_SENSOR_I2C_DELAY; j > 0; j--);
   
   return get_byte;
 }
#endif
 static void MT9P012_write_eeprom_byte(kal_uint16 addr, kal_uint8 para)
 {
#ifndef MT9P012_HW_SCCB
   kal_uint8 fail_try_no = EEPROM_MAX_I2C_FAIL_TRY_NO + 1;
   
   while (--fail_try_no > 0)
   {
     EEPROM_I2C_START_TRANSMISSION;
     if (eeprom_send_byte(EEPROM_I2C_WRITE_ID)) continue;
     if (eeprom_send_byte(addr >> 8)) continue;
     if (eeprom_send_byte(addr&0xFF)) continue;
     if (eeprom_send_byte(para)) continue;
     break;
   }
   EEPROM_I2C_STOP_TRANSMISSION;
#ifdef __EEPROM_DEBUG_TRACE__
   if (!fail_try_no) kal_print_string_trace(MOD_ENG, TRACE_WARNING, "I2C write %x, %x error", addr, para);
#endif
#else
   SCCB_TRANSACTION_RESULT rt;
   kal_uint8 out_buff[3];
   
   out_buff[0] = addr >> 8;
   out_buff[1] = addr;
   out_buff[2] = para;
   rt = i2c_write(SCCB_OWNER_CAMERA_EEPROM, out_buff, sizeof(out_buff));
#ifdef __EEPROM_DEBUG_TRACE__
   if (rt == SCCB_TRANSACTION_FAIL) kal_print_string_trace(MOD_ENG, TRACE_WARNING, "I2C write %x, %x error", addr, para);
#endif
#endif

 }
 static void MT9P012_write_eeprom_word(kal_uint16 addr, kal_uint16 para)
 {

#ifndef MT9P012_HW_SCCB
   kal_uint8 fail_try_no = EEPROM_MAX_I2C_FAIL_TRY_NO + 1;
   
   while (--fail_try_no > 0)
   {
     EEPROM_I2C_START_TRANSMISSION;
     if (eeprom_send_byte(EEPROM_I2C_WRITE_ID)) continue;
     if (eeprom_send_byte(addr >> 8)) continue;
     if (eeprom_send_byte(addr&0xFF)) continue;
     if (eeprom_send_byte(para&0xFF)) continue;
     if (eeprom_send_byte((para>>8)&0xFF)) continue;
     break;
   }
   EEPROM_I2C_STOP_TRANSMISSION;
#ifdef __EEPROM_DEBUG_TRACE__
   if (!fail_try_no) kal_print_string_trace(MOD_ENG, TRACE_WARNING, "I2C write %x, %x error", addr, para);
#endif
#else
   SCCB_TRANSACTION_RESULT rt;
   kal_uint8 out_buff[4];
   
   out_buff[0] = addr >> 8;
   out_buff[1] = addr;
   out_buff[2] = para;
   out_buff[3] = para>>8;  
   rt = i2c_write(SCCB_OWNER_CAMERA_EEPROM, out_buff, sizeof(out_buff));
#ifdef __EEPROM_DEBUG_TRACE__
   if (rt == SCCB_TRANSACTION_FAIL) kal_print_string_trace(MOD_ENG, TRACE_WARNING, "I2C write %x, %x error", addr, para);
#endif
#endif
 }
 static void MT9P012_write_eeprom_dword(kal_uint16 addr, kal_uint32 para)
 {
#ifndef MT9P012_HW_SCCB
   kal_uint8 fail_try_no = EEPROM_MAX_I2C_FAIL_TRY_NO + 1;
   
   while (--fail_try_no > 0)
   {
     EEPROM_I2C_START_TRANSMISSION;
     if (eeprom_send_byte(EEPROM_I2C_WRITE_ID)) continue;
     if (eeprom_send_byte(addr >> 8)) continue;
     if (eeprom_send_byte(addr&0xFF)) continue;
     if (eeprom_send_byte(para&0xFF)) continue;
     if (eeprom_send_byte((para>>8)&0xFF)) continue;
     if (eeprom_send_byte((para>>16)&0xFF)) continue;
     if (eeprom_send_byte((para>>24)&0xFF)) continue;
     break;
   }
   EEPROM_I2C_STOP_TRANSMISSION;
#ifdef __EEPROM_DEBUG_TRACE__
   if (!fail_try_no) kal_print_string_trace(MOD_ENG, TRACE_WARNING, "I2C write %x, %x error", addr, para);
#endif
#else
   SCCB_TRANSACTION_RESULT rt;
   kal_uint8 out_buff[6];
   
   out_buff[0] = addr >> 8;
   out_buff[1] = addr;
   out_buff[2] = para;
   out_buff[3] = para>>8;
   out_buff[4] = para>>16;
   out_buff[5] = para>>24;
   rt = i2c_write(SCCB_OWNER_CAMERA_EEPROM, out_buff, sizeof(out_buff));
#ifdef __EEPROM_DEBUG_TRACE__
   if (rt == SCCB_TRANSACTION_FAIL) kal_print_string_trace(MOD_ENG, TRACE_WARNING, "I2C write %x, %x error", addr, para);
#endif
#endif
 }
 
 static kal_uint8 MT9P012_read_eeprom_byte(kal_uint16 addr)
 {
   kal_uint8 in_buff[1] = {0xFF};
#ifndef MT9P012_HW_SCCB
   kal_uint8 get_byte = 0xFF;
   kal_uint8 fail_try_no = EEPROM_MAX_I2C_FAIL_TRY_NO + 1;
   
   while (--fail_try_no > 0)
   {
     EEPROM_I2C_START_TRANSMISSION;
     if (eeprom_send_byte(EEPROM_I2C_WRITE_ID)) continue;
     if (eeprom_send_byte(addr >> 8)) continue;
     if (eeprom_send_byte(addr&0xFF)) continue;
     EEPROM_I2C_START_TRANSMISSION;
     if (eeprom_send_byte(EEPROM_I2C_READ_ID)) continue;
     in_buff[0] = eeprom_get_byte();
     break;
   }
   EEPROM_I2C_STOP_TRANSMISSION;
#ifdef __EEPROM_DEBUG_TRACE__
   if (!fail_try_no) kal_print_string_trace(MOD_ENG, TRACE_WARNING, "I2C read %x error", addr);
#endif
#else
   SCCB_TRANSACTION_RESULT rt;
   kal_uint8 out_buff[2];
   
   out_buff[0] = addr >> 8;
   out_buff[1] = addr;
   rt = i2c_write_and_read(SCCB_OWNER_CAMERA_EEPROM, out_buff, sizeof(out_buff), in_buff, sizeof(in_buff));
#ifdef __EEPROM_DEBUG_TRACE__
   if (rt == SCCB_TRANSACTION_FAIL) kal_print_string_trace(MOD_ENG, TRACE_WARNING, "I2C read %x error", addr);
#endif
#endif
     return in_buff[0];
 }
 static kal_uint16 MT9P012_read_eeprom_word(kal_uint16 addr)
 {

     kal_uint16 get_word;
     kal_uint8 in_buff[2]={0xFF, 0xFF};
#ifndef MT9P012_HW_SCCB
   kal_uint8 fail_try_no = EEPROM_MAX_I2C_FAIL_TRY_NO + 1;
 
   while (--fail_try_no > 0)
   {
     EEPROM_I2C_START_TRANSMISSION;
     if (eeprom_send_byte(EEPROM_I2C_WRITE_ID)) continue;
     if (eeprom_send_byte(addr >> 8)) continue;
     if (eeprom_send_byte(addr&0xFF)) continue;
     EEPROM_I2C_START_TRANSMISSION;
     if (eeprom_send_byte(EEPROM_I2C_READ_ID)) continue;
     in_buff[0] = eeprom_get_byte();
     in_buff[1] = eeprom_get_byte(); 
     break;
   }
   EEPROM_I2C_STOP_TRANSMISSION;
#ifdef __EEPROM_DEBUG_TRACE__
   if (!fail_try_no) kal_print_string_trace(MOD_ENG, TRACE_WARNING, "I2C read %x error", addr);
#endif
#else
   SCCB_TRANSACTION_RESULT rt;
   kal_uint8 out_buff[2];
   
   out_buff[0] = addr >> 8;
   out_buff[1] = addr;
   rt = i2c_write_and_read(SCCB_OWNER_CAMERA_EEPROM, out_buff, sizeof(out_buff), in_buff, sizeof(in_buff));
#ifdef __EEPROM_DEBUG_TRACE__
   if (rt == SCCB_TRANSACTION_FAIL) kal_print_string_trace(MOD_ENG, TRACE_WARNING, "I2C read %x error", addr);
#endif
#endif
   get_word = in_buff[1];
   get_word = (get_word<<8) | in_buff[0];
   return get_word;
 }
 static kal_uint32 MT9P012_read_eeprom_dword(kal_uint16 addr)
 {
   kal_uint32 get_dword;
   kal_uint8 in_buff[4]={0xFF, 0xFF, 0xFF, 0xFF};
#ifndef MT9P012_HW_SCCB
   kal_uint8 fail_try_no = EEPROM_MAX_I2C_FAIL_TRY_NO + 1;
 
   while (--fail_try_no > 0)
   {
     EEPROM_I2C_START_TRANSMISSION;
     if (eeprom_send_byte(EEPROM_I2C_WRITE_ID)) continue;
     if (eeprom_send_byte(addr >> 8)) continue;
     if (eeprom_send_byte(addr&0xFF)) continue;
     EEPROM_I2C_START_TRANSMISSION;
     if (eeprom_send_byte(EEPROM_I2C_READ_ID)) continue;
     in_buff[0] = eeprom_get_byte();
     in_buff[1] = eeprom_get_byte();
     in_buff[2] = eeprom_get_byte();
     in_buff[3] = eeprom_get_byte();    
     break;
   }
   EEPROM_I2C_STOP_TRANSMISSION;
#ifdef __EEPROM_DEBUG_TRACE__
   if (!fail_try_no) kal_print_string_trace(MOD_ENG, TRACE_WARNING, "I2C read %x error", addr);
#endif
#else
   SCCB_TRANSACTION_RESULT rt;
   kal_uint8 out_buff[2];
   
   out_buff[0] = addr >> 8;
   out_buff[1] = addr;
   rt = i2c_write_and_read(SCCB_OWNER_CAMERA_EEPROM, out_buff, sizeof(out_buff), in_buff, sizeof(in_buff));
#ifdef __EEPROM_DEBUG_TRACE__
   if (rt == SCCB_TRANSACTION_FAIL) kal_print_string_trace(MOD_ENG, TRACE_WARNING, "I2C read %x error", addr);
#endif
#endif
   get_dword = in_buff[3];
   get_dword = (get_dword<<8) | in_buff[2];
   get_dword = (get_dword<<8) | in_buff[1];
   get_dword = (get_dword<<8) | in_buff[0];
   return get_dword;
 }
 
#ifdef MT9P012_HW_SCCB
static void vRegisterEepromSCCB(void)
{
    kal_uint32 speed = EEPROM_SCCB_FAST_MODE_SPEED_1;
 
    i2c_set_get_handle_wait(SCCB_OWNER_CAMERA_EEPROM, KAL_TRUE);
    i2c_set_transaction_speed(SCCB_OWNER_CAMERA_EEPROM, SCCB_TRANSACTION_FAST_MODE, &speed, NULL);
    i2c_set_slave_address(SCCB_OWNER_CAMERA_EEPROM, EEPROM_I2C_WRITE_ID);
     kal_sleep_task(1);
}
#endif

kal_bool check_eeprom_tag(void)
{
    eepromTag = MT9P012_read_eeprom_dword(TAG_ID_POS);
#ifdef __EEPROM_DEBUG_TRACE__
    kal_print_string_trace(MOD_ENG, TRACE_WARNING, "eeprom tag = %x", eepromTag);
#endif
    if ((eepromTag != TAG_SINGLE_SLIM_SHADING) && (eepromTag != TAG_DEFECT_SINGLE_SLIM_SHADING)
        && (eepromTag != TAG_DYNAMIC_SLIM_SHADING) && (eepromTag != TAG_DEFECT_DYNAMIC_SLIM_SHADING)
        && (eepromTag != TAG_FIXED_SHADING) && (eepromTag != TAG_DEFECT_EIXED_SHADING))
    {
#ifdef __EEPROM_DEBUG_TRACE__
        kal_print_string_trace(MOD_ENG, TRACE_WARNING, "check_eeprom_tag fail!!");
#endif
        return KAL_FALSE;
    }
    return KAL_TRUE;
}

void calculate_shading_pos(void)
{
    if ((eepromTag == TAG_DEFECT_SINGLE_SLIM_SHADING) || (eepromTag == TAG_DEFECT_DYNAMIC_SLIM_SHADING)
        || (eepromTag == TAG_DEFECT_EIXED_SHADING))
    {
        eepromShadingStart = TAG_ID_POS + TAG_ID_LENGTH + DEFECT_TABLE_LENGTH + PREGAIN_LENGTH + PREGAIN_FACTORE_LENGTH;
    }
    else
    {
        eepromShadingStart = TAG_ID_POS + TAG_ID_LENGTH + PREGAIN_LENGTH + PREGAIN_FACTORE_LENGTH;
    }
}

kal_bool check_shading_tag(void)
{
    eepromShadingTag = MT9P012_read_eeprom_dword(eepromShadingStart+SHADING_TAG_POS_OFFSET);
#ifdef __EEPROM_DEBUG_TRACE__
    kal_print_string_trace(MOD_ENG, TRACE_WARNING, "eeprom shading tag = %x", eepromShadingTag);
#endif
    if ((((eepromTag == TAG_SINGLE_SLIM_SHADING) || (eepromTag == TAG_DEFECT_SINGLE_SLIM_SHADING)) && (eepromShadingTag == SHADING_TAG_SINGLE_SLIM))
        || (((eepromTag == TAG_DYNAMIC_SLIM_SHADING) || (eepromTag == TAG_DEFECT_DYNAMIC_SLIM_SHADING)) && (eepromShadingTag == SHADING_TAG_DYNAMIC_SLIM))
        || (((eepromTag == TAG_FIXED_SHADING) || (eepromTag == TAG_DEFECT_EIXED_SHADING)) && (eepromShadingTag == SHADING_TAG_FIXED)))
    {
        return KAL_TRUE;
    }
#ifdef __EEPROM_DEBUG_TRACE__
    kal_print_string_trace(MOD_ENG, TRACE_WARNING, "shading tag unmatch!!");
#endif
    return KAL_FALSE;
}


kal_bool get_shading_table_from_EEPROM(PSENSOR_SHADING_TABLE_IN_STRUCT p_shading_in,
                                   PSENSOR_SHADING_TABLE_OUT_STRUCT p_shading_out,
                                   kal_uint16 out_buff_size)
{
#if (defined(DRV_ISP_MT6236_HW_SUPPORT))
    kal_uint32 tempValue;
    kal_uint32 i, shading_node_number;

#ifdef __EEPROM_DEBUG_TRACE__
    kal_print_string_trace(MOD_ENG, TRACE_WARNING, "get_shading_table_from_EEPROM start!!");
#endif

#ifdef MT9P012_HW_SCCB
    vRegisterEepromSCCB();
#endif
    if (!check_eeprom_tag())
    {
        return KAL_FALSE;
    }
    calculate_shading_pos();
    if (!check_shading_tag())
    {
        return KAL_FALSE;
    }
    p_shading_out->shading_table_support=KAL_TRUE;
    p_shading_out->shading_table_angle=SHADING_TALE_ROTATE_ANGLE_0;
    
    tempValue = MT9P012_read_eeprom_dword(eepromShadingStart+SHADING_PRV_REG_POS_OFFSET+1*4);
    p_shading_out->pre_shading_block_number_x=((tempValue&0xF0000000)>>28)+1;
    p_shading_out->pre_shading_block_number_y=((tempValue&0xF000)>>12)+1;
    p_shading_out->pre_shading_block_width=(tempValue&0x0FFF0000)>>16;
    p_shading_out->pre_shading_block_height=(tempValue&0x0FFF);

    tempValue = MT9P012_read_eeprom_dword(eepromShadingStart+SHADING_PRV_REG_POS_OFFSET+3*4);
    p_shading_out->pre_last_shading_block_width=(tempValue&0x0FFF0000)>>16;
    p_shading_out->pre_last_shading_block_height=(tempValue&0x0FFF);

    tempValue = MT9P012_read_eeprom_dword(eepromShadingStart+SHADING_CAP_REG_POS_OFFSET+1*4);
    p_shading_out->cap_shading_block_number_x=((tempValue&0xF0000000)>>28)+1;
    p_shading_out->cap_shading_block_number_y=((tempValue&0xF000)>>12)+1;
    p_shading_out->cap_shading_block_width=(tempValue&0x0FFF0000)>>16;
    p_shading_out->cap_shading_block_height=(tempValue&0x0FFF);

    tempValue = MT9P012_read_eeprom_dword(eepromShadingStart+SHADING_CAP_REG_POS_OFFSET+3*4);
    p_shading_out->cap_last_shading_block_width=(tempValue&0x0FFF0000)>>16;
    p_shading_out->cap_last_shading_block_height=(tempValue&0x0FFF);
    
    p_shading_out->single_slim_shading_para.shading_block_number_x=p_shading_out->cap_shading_block_number_x;
    p_shading_out->single_slim_shading_para.shading_block_number_y=p_shading_out->cap_shading_block_number_y;
    p_shading_out->single_slim_shading_para.shading_block_width=p_shading_out->cap_shading_block_width;
    p_shading_out->single_slim_shading_para.shading_block_height=p_shading_out->cap_shading_block_height;
    p_shading_out->single_slim_shading_para.last_shading_block_width=p_shading_out->cap_last_shading_block_width;
    p_shading_out->single_slim_shading_para.last_shading_block_height=p_shading_out->cap_last_shading_block_height;

    if (eepromShadingTag == SHADING_TAG_SINGLE_SLIM)
    {
        p_shading_out->shading_table_type=SHADING_TABLE_SINGLE_SLIM;
        // copy single slim shading table
        shading_node_number=(p_shading_out->cap_shading_block_number_x+1)*(p_shading_out->cap_shading_block_number_y+1);
        if (shading_node_number > SHADING_CAP_MAX_BLOCK_SIZE)
        {
            shading_node_number = SHADING_CAP_MAX_BLOCK_SIZE;
        }
        for (i=0;i<(shading_node_number*2); i++)
        {
            *(p_shading_in->p_pre_shading_table+i)=MT9P012_read_eeprom_dword(eepromShadingStart+SHADING_TABLE_OFFSET+i*4);
        }
    }
    else if (eepromShadingTag == SHADING_TAG_DYNAMIC_SLIM)
    {
        p_shading_out->shading_table_type=SHADING_TABLE_DYNAMIC;
        // copy dynamic slim shading table
        shading_node_number=(p_shading_out->pre_shading_block_number_x+1)*(p_shading_out->pre_shading_block_number_y+1);
        shading_node_number+=((p_shading_out->cap_shading_block_number_x+1)*(p_shading_out->cap_shading_block_number_y+1)*3);
        if (shading_node_number > (SHADING_PRV_MAX_BLOCK_SIZE + SHADING_CAP_MAX_BLOCK_SIZE*3))
        {
            shading_node_number = (SHADING_PRV_MAX_BLOCK_SIZE + SHADING_CAP_MAX_BLOCK_SIZE*3);
        }
        for (i=0;i<(shading_node_number*2); i++)
        {
            *(p_shading_in->p_cap_shading_table1+i)=MT9P012_read_eeprom_dword(eepromShadingStart+SHADING_TABLE_OFFSET+i*4);
        }
    }
    else
    {
        p_shading_out->shading_table_type=SHADING_TABLE_FIXED;
        // copy fixed shading table
        p_shading_out->fixed_shading_para.pre_shading_table_size=MT9P012_read_eeprom_dword(eepromShadingStart+SHADING_PRV_TBL_SIZE_POS_OFFSET);
        p_shading_out->fixed_shading_para.cap_shading_table_size=MT9P012_read_eeprom_dword(eepromShadingStart+SHADING_CAP_TBL_SIZE_POS_OFFSET);
        if (p_shading_out->fixed_shading_para.pre_shading_table_size > MAX_SHADING2_PRV_SIZE)
        {
            p_shading_out->fixed_shading_para.pre_shading_table_size = MAX_SHADING2_PRV_SIZE;
        }
        if (p_shading_out->fixed_shading_para.cap_shading_table_size > (MAX_SHADING1_CAP_SIZE+MAX_SHADING2_CAP_SIZE+MAX_DEFECT2_CAP_SIZE))
        {
            p_shading_out->fixed_shading_para.cap_shading_table_size = (MAX_SHADING1_CAP_SIZE+MAX_SHADING2_CAP_SIZE+MAX_DEFECT2_CAP_SIZE);
        }
        for (i=0;i<p_shading_out->fixed_shading_para.pre_shading_table_size;i++)
        {
            *(p_shading_in->p_pre_shading_table+i)=MT9P012_read_eeprom_dword(eepromShadingStart+SHADING_TABLE_OFFSET+i*4);
        }
        for (i=0;i<p_shading_out->fixed_shading_para.cap_shading_table_size;i++)
        {
            if (i < MAX_SHADING1_CAP_SIZE)
            {
                *(p_shading_in->p_cap_shading_table1+i)=MT9P012_read_eeprom_dword(eepromShadingStart+SHADING_TABLE_OFFSET+(MAX_SHADING2_PRV_SIZE+i)*4);
            }
            else if (i < (MAX_SHADING1_CAP_SIZE+MAX_SHADING2_CAP_SIZE))
            {
                *(p_shading_in->p_cap_shading_table2+i-MAX_SHADING1_CAP_SIZE)=MT9P012_read_eeprom_dword(eepromShadingStart+SHADING_TABLE_OFFSET+(MAX_SHADING2_PRV_SIZE+i)*4);
            }
            else
            {
                *(p_shading_in->p_cap_shading_table3+i-(MAX_SHADING1_CAP_SIZE+MAX_SHADING2_CAP_SIZE))=MT9P012_read_eeprom_dword(eepromShadingStart+SHADING_TABLE_OFFSET+(MAX_SHADING2_PRV_SIZE+i)*4);
            }
        }
   }
#ifdef __EEPROM_DEBUG_TRACE__
    kal_print_string_trace(MOD_ENG, TRACE_WARNING, "get_shading_table_from_EEPROM end!!");
#endif
   return KAL_TRUE;
#else
    return KAL_FALSE;
#endif
} */
#endif

