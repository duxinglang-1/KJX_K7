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
#ifndef _LENS_MODULE_SUNNY_S5S01D_S5K3E2FX_INTERNAL_H
#define _LENS_MODULE_SUNNY_S5S01D_S5K3E2FX_INTERNAL_H

#include "image_sensor_s5k3e2fx.h"

    extern lens_func_struct SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_func_map;
#if(defined(DRV_ISP_6238_SERIES))
    extern camera_lens_timing_struct SUNNY_S5S01D_S5K3E2FX_INTERNAL_camera_lens_timing;
#endif
    
    kal_uint32 SUNNY_S5S01D_S5K3E2FX_INTERNAL_get_lens_prefix_name(kal_char* buf);
    
#if (defined(AF_SUPPORT))
    // config lens module callback function 
    void SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_func_config(void);

    // Lens Module Power ON/OFF
    void SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_af_power_on(kal_bool on);
    // AF Module Parameter setting
    void SUNNY_S5S01D_S5K3E2FX_INTERNAL_lens_af_set_para(kal_uint32 para);
#endif

    #define S5K3E2_INTERNAL_LENS_WRITE_ID         S5K3E2FX_WRITE_ID
    #define S5K3E2_INTERNAL_LENS_READ_ID          S5K3E2FX_READ_ID
    #define S5K3E2_INTERNAL_LENS_ID               0x3E

    #define S5K3E2_LENS_START_REG               0x3130
    #define S5K3E2_LENS_POSITION_REG_M          0x3131
    #define S5K3E2_LENS_POSITION_REG_L          0x3132
    #define S5K3E2_LENS_CURRENT_REG             0x3146

    #define S5K3E2_INTERNAL_LENS_I2C_DELAY          S5K3E2FX_SENSOR_I2C_DELAY


    #define S5K3E2_INTERNAL_LENS_START_BIT \
    { \
        volatile kal_uint32 j; \
        SET_SCCB_CLK_OUTPUT; \
        SET_SCCB_DATA_OUTPUT; \
        SET_SCCB_CLK_HIGH; \
        SET_SCCB_DATA_HIGH; \
        for(j=0;j<S5K3E2_INTERNAL_LENS_I2C_DELAY;j++);\
        SET_SCCB_DATA_LOW; \
        for(j=0;j<S5K3E2_INTERNAL_LENS_I2C_DELAY;j++);\
        SET_SCCB_CLK_LOW; \
    }

    #define S5K3E2_INTERNAL_LENS_STOP_BIT \
    { \
        volatile kal_uint32 j; \
        SET_SCCB_CLK_OUTPUT; \
        SET_SCCB_DATA_OUTPUT; \
        SET_SCCB_CLK_LOW; \
        SET_SCCB_DATA_LOW; \
        for(j=0;j<S5K3E2_INTERNAL_LENS_I2C_DELAY;j++);\
        SET_SCCB_CLK_HIGH; \
        for(j=0;j<S5K3E2_INTERNAL_LENS_I2C_DELAY;j++);\
        SET_SCCB_DATA_HIGH; \
    }


#endif /* _LENS_MODULE_H */
