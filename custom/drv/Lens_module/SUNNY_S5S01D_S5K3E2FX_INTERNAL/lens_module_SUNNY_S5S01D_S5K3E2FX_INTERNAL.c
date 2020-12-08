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
#include "stdio.h"
#include "string.h"
#include "drv_comm.h"
#include "IntrCtrl.h"
#include "reg_base.h"
#include "gpio_sw.h"
#include "isp_if.h"
//#include "image_sensor.h"
#include "camera_para.h"
#include "lens_module.h"
#include "lens_module_SUNNY_S5S01D_S5K3E2FX_INTERNAL.h"
#include "Af.h"
#include "sccb.h"

#if (defined(AF_SUPPORT))


extern kal_uint16 g_curr_pos,g_home_pos,g_macro_pos;


#if !(defined(DRV_ISP_6238_SERIES)|| defined(DRV_ISP_6235_SERIES))
#define lens_scaling 2//1024/130//1.0
float    lens_step_scaling=lens_scaling;
camera_lens_run_struct     camera_lens_step={
    {17},
    {
        {0*lens_scaling,  250},  {12*lens_scaling, 0x00}, {16*lens_scaling, 0x00}, { 20*lens_scaling, 0x00}, 
        {24*lens_scaling, 0x00}, {28*lens_scaling, 0x00}, {32*lens_scaling, 0x00}, { 38*lens_scaling, 0x00},
        {46*lens_scaling, 0x00}, {54*lens_scaling, 0x00}, {62*lens_scaling, 0x00}, { 70*lens_scaling, 0x00},
        {78*lens_scaling, 0x00}, {86*lens_scaling, 0x00}, {94*lens_scaling, 0x00}, {102*lens_scaling, 0x00},
        {116*lens_scaling, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00},
        {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00},
        {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00},
        {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00},
    }
};

camera_lens_timing_struct camera_lens_timing={
    {8}, {2},
    {
        {66*lens_scaling, 3277}, {33*lens_scaling, 1639},
        {17*lens_scaling, 820}, {9*lens_scaling, 410},
        {5*lens_scaling, 205}, {4*lens_scaling, 103}, 
        {2*lens_scaling, 52}, {1*lens_scaling, 26},
        {0x00, 0x00}, {0x00, 0x00}, 
        {0x00, 0x00}, {0x00, 0x00}
    }
};
/* AF */
nvram_camera_lens_struct    camera_lens;
const nvram_camera_lens_struct CAMERA_LENS_DEFAULT_VALUE={
    { /*af_table_num, af_home_idx, af_macro_idx, af_infinity_idx, ae_hyper_pos, af_me_home_pos, af_me_macro_pos, af_calibration_offset */
       6, 0, 5, 1, 0, 0, 256, 0 
   },
    {    {   0,  250}, {   16, 0x00}, {  58, 0x00}, {  120, 0x00}, 
        {  174, 0x00}, {  256, 0x00}, {  0x00, 0x00}, {  0x00, 0x00},
        {  0x00, 0x00}, { 0x00, 0x00}, { 0x00, 0x00}, {0x00, 0x00}, 
        {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00},
        {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, 
        {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00},
        {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, 
        {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}
    }
};     
#else // DRV_ISP_6238_SERIES
camera_lens_timing_struct SUNNY_S5S01D_S5K3E2FX_INTERNAL_camera_lens_timing={
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
#else
extern void S5K3E2FX_write_cmos_sensor(kal_uint32 addr, kal_uint32 para);
extern kal_uint32 S5K3E2FX_read_cmos_sensor(kal_uint32 addr);
static void S5K3E2_INTERNAL_LENS_write_reg(kal_uint16 addr, kal_uint8 para)
{
    S5K3E2FX_write_cmos_sensor(addr, para);
}
kal_uint8 S5K3E2_INTERNAL_LENS_read_reg(kal_uint16 addr)
{
    return (kal_uint8)(S5K3E2FX_read_cmos_sensor(addr));
}
#endif


/*************************************************************************
* FUNCTION
*************************************************************************/
void lens_af_set_para(kal_uint32 thres)
{
    //kal_uint16 reg_value_H, reg_value_L;
    //reg_value_H = (0x00|(thres>>2));
    //reg_value_L =  ((thres<<6) & 0xC0);
    ASSERT(thres < 0x10000);
    S5K3E2_INTERNAL_LENS_write_reg(S5K3E2_LENS_POSITION_REG_M, (thres>>8)&0xFF);
    S5K3E2_INTERNAL_LENS_write_reg(S5K3E2_LENS_POSITION_REG_L, thres&0xFF);
}


void set_step(kal_uint32 duty)
{
    if(duty<g_macro_pos){
    lens_af_set_para(duty);    
    }else{
    lens_af_set_para(g_macro_pos);    
    }
}

/*************************************************************************
* FUNCTION
*    SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_init
*
* DESCRIPTION
*    This function initialize the vcm comtrol IO
*
* PARAMETERS
*    None
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_int8 SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_init(void)
{    
    //kal_uint16 lens_reg, reg_value_H, reg_value_L;
    
#if (!defined(DRV_ISP_6238_SERIES))    
    /* init af status and pos */
    g_home_pos = camera_lens.AF[camera_lens.INFO.af_home_idx].pos;
    g_macro_pos= camera_lens.AF[camera_lens.INFO.af_macro_idx].pos;
    g_curr_pos = g_home_pos;    
#else
    /* init af status and pos */
    g_home_pos = camera_3a.AF.table_info[0].table_step[camera_3a.AF.table_info[0].table_range.af_home_idx].pos;
    g_macro_pos= camera_3a.AF.table_info[0].table_step[camera_3a.AF.table_info[0].table_range.af_macro_idx].pos;    
    g_curr_pos = g_home_pos;        
#endif    
        /* Load module calibration data if existed */

    #if 0   //Now the I2C is not avalible
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    /* ... */
    return 1;
}    /* SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_init() */

/*************************************************************************
* FUNCTION
*    SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_power_on
*
* DESCRIPTION
*    This function is to turn on vcm af lens power.
*
* PARAMETERS
*    None
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_power_on(void)
{    
    lens_af_power_on(KAL_TRUE);   
    S5K3E2_INTERNAL_LENS_write_reg(S5K3E2_LENS_START_REG, 0x03);
    set_step(g_curr_pos);  
}

/*************************************************************************
* FUNCTION
*    SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_power_off
*
* DESCRIPTION
*    This function is to turn off vcm af lens power.
*
* PARAMETERS
*    None
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_power_off(void)
{    
    //kal_uint16 reg_value_H, reg_value_L;
    g_curr_pos = g_home_pos;
    set_step(g_curr_pos);    
    S5K3E2_INTERNAL_LENS_write_reg(S5K3E2_LENS_POSITION_REG_M, (g_curr_pos>>8)&0xFF);
    S5K3E2_INTERNAL_LENS_write_reg(S5K3E2_LENS_POSITION_REG_L, (g_curr_pos)&0xFF);
    S5K3E2_INTERNAL_LENS_write_reg(S5K3E2_LENS_START_REG, 0x00);
    lens_af_power_on(KAL_FALSE);       
}

/*************************************************************************
* FUNCTION
*    SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_standby
*
* DESCRIPTION
*    This function is to let vcm af lens stand by.
*
* PARAMETERS
*    None
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_standby(void)
{
}
    
/*************************************************************************
* FUNCTION
*    SUNNY_S5S01D_S5K3E2FX_INTERNAL_get_lens_id
*
* DESCRIPTION
*    This function return the vcm id
*
* PARAMETERS
*    *lens_id : address pointer of vcm id
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void SUNNY_S5S01D_S5K3E2FX_INTERNAL_get_lens_id(kal_uint8 *lens_id)
{
    /* LENS_VCM_LEBRO_ID    */
}    /* SUNNY_S5S01D_S5K3E2FX_INTERNAL_get_lens_id() */

/*************************************************************************
* FUNCTION
*    SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_af_home_check
*
* DESCRIPTION
*    This function is to check if lens stay at home position
*
* PARAMETERS
*    NONE
*
* RETURNS
*    KAL_TRUE/KAL_FALSE.
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint8 SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_af_home_check(void)
{
    if(g_curr_pos==g_home_pos)
        return KAL_TRUE;
    else        
        return KAL_FALSE;    
}

/*************************************************************************
* FUNCTION
*    SUNNY_S5S01D_S5K3E2FX_INTERNAL_get_lens_af_current_pos
*
* DESCRIPTION
*    This function is to get lens parameter
*
* PARAMETERS
*    NONE
*
* RETURNS
*    get current lens position
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 SUNNY_S5S01D_S5K3E2FX_INTERNAL_get_lens_af_current_pos(void)   
{

  return g_curr_pos;
}

/*************************************************************************
* FUNCTION
*    SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_af_step_cw
*
* DESCRIPTION
*    This function is to move lens cw number steps, go infinite
*
* PARAMETERS
*    set lens cw move steps
*
* RETURNS
*    NONE
*
* GLOBALS AFFECTED
*
*************************************************************************/
void SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_af_step_cw(kal_uint32 number)
{
   if((g_curr_pos+number)<g_macro_pos)
      g_curr_pos+=number;
    else
        g_curr_pos = g_macro_pos;              
   set_step(g_curr_pos);      
}    /* lens_step_motor_step_cw() */

/*************************************************************************
* FUNCTION
*    SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_af_step_ccw
*
* DESCRIPTION
*    This function is to move lens ccw number steps, go macro
*
* PARAMETERS
*    set lens ccw move steps
*
* RETURNS
*    NONE
*
* GLOBALS AFFECTED
*
*************************************************************************/
void SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_af_step_ccw(kal_uint32 number)
{
   if(g_curr_pos>=number)
      g_curr_pos-=number;   
    else    
        g_curr_pos = g_home_pos;
   set_step(g_curr_pos);            
}    /* lens_step_motor_step_ccw() */

/*************************************************************************
* FUNCTION
*    SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_af_move_to
*
* DESCRIPTION
*    This function is to move lens to target pos
*
* PARAMETERS
*    set lens move to target pos
*
* RETURNS
*    NONE
*
* GLOBALS AFFECTED
*
*************************************************************************/
void SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_af_move_to( kal_int32 target_pos )
{
    g_curr_pos = target_pos;            
    if( target_pos > g_macro_pos )
        g_curr_pos = g_macro_pos;
    set_step(g_curr_pos);            
}

/*************************************************************************
* FUNCTION
*    SUNNY_S5S01D_S5K3E2FX_INTERNAL_get_af_lens_status
*
* DESCRIPTION
*    This function is to get current lens status
*
* PARAMETERS
*    NONE
*
* RETURNS
*    lens status
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint8 SUNNY_S5S01D_S5K3E2FX_INTERNAL_get_af_lens_status( void )
{
    return AF_STATUS_READY;
}

/*************************************************************************
* FUNCTION
*    lens_func_map
*
* DESCRIPTION
*    vcm af module functions struct.
*
* PARAMETERS
*    none
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*
*************************************************************************/
lens_func_struct SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_func_map=
{
    SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_init,
    SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_power_on,
    SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_power_off,
    SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_standby,    
    SUNNY_S5S01D_S5K3E2FX_INTERNAL_get_lens_id,
    SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_af_home_check,
    SUNNY_S5S01D_S5K3E2FX_INTERNAL_get_lens_af_current_pos,
    SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_af_step_cw,
    SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_af_step_ccw,
    SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_af_move_to,    
    SUNNY_S5S01D_S5K3E2FX_INTERNAL_get_af_lens_status,
    0,                                    // lens_ms_open
    0,                                    // lens_ms_close
    0,                                    // get_lens_current_iris
    0                                    // lens_set_iris    
};    /* lens_func_pixelplus */

kal_uint32 SUNNY_S5S01D_S5K3E2FX_INTERNAL_get_lens_prefix_name(kal_char* buf){
    strcpy(buf, "SUNNY_S5S01D_S5K3E2FX_INTERNAL");
    return 0;
}
   
#endif

