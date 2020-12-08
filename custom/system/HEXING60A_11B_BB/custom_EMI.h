/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   custom_EMI.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the EMI (external memory interface) related setting.
 *
 * Author:
 * -------
 *  CM Huang(mtk00582)   EMI auto generator V8.267
 *
 *   Memory Device database last modified on 2017/9/6
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(MT6260)
    
#ifndef __CUSTOM_EMI__
#define __CUSTOM_EMI__

#include "kal_general_types.h"
#include "MemoryDevice_TypeDef.h"

/**
  *    for definition of COMBO_MEM_ENTRY_COUNT and __EMI_DEVICE_MODE_BURST__
  */
#include "custom_MemoryDevice.h"
#include "custom_EMI_release.h"

#define __EMI_COMBO_ENTRY_COUNT     1

#define __EMI_DCM_COMBO_INDEX_UND   0xffffffff


/*
 ****************************************************************************
 Specify the chip select configuration
 Possible choices, NOR_FLASH, RAM, LPSDRAM, UNUSED
 ****************************************************************************
*/


/*
 ****************************************************************************
 Specify NOR/PSRAM Command Num
 ****************************************************************************
*/

#define __EMI_PSRAM_CMD_NUM    8



/*
 ****************************************************************************
 Specify if ADMUX device is applied
 If it is supported, define ADMUX_MCP
 ****************************************************************************
*/
#define ADMUX_MCP


/*
 ****************************************************************************
 Define the driving and cache/prefetch setting (optional)
 ****************************************************************************
*/

/* start of MCP0 */

#if defined(__EMI_CLK_130MHZ__)
/* PSRAM async */
#define EMI_CONB_ASYNC_MCP0               0x39320D61

/* PSRAM burst */
#define EMI_CONB_BURST_MCP0               0xA0000000
#define EMI_CONF_BURST_MCP0               0xB2014411

/*EMI GENA value*/
#define EMI_GENERAL_A_VAL_MCP0           0x00000400

#define EMI_RDCT_VAL_MCP0                0x20004001

#define EMI_IDL_A_VAL_MCP0             0x0
#define EMI_IDL_B_VAL_MCP0             0x0
#define EMI_IDL_C_VAL_MCP0             0x0
#define EMI_IDL_D_VAL_MCP0             0x0
#define EMI_IDL_E_VAL_MCP0             0x0

#define EMI_ODL_A_VAL_MCP0             0x0
#define EMI_ODL_B_VAL_MCP0             0x0
#define EMI_ODL_C_VAL_MCP0             0x0
#define EMI_ODL_D_VAL_MCP0             0x0
#define EMI_ODL_E_VAL_MCP0             0x0
#define EMI_ODL_F_VAL_MCP0             0x0   

/* EMI_DRV value */
#define EMI_IO_A_VAL_MCP0                0x00010001
#define EMI_IO_B_VAL_MCP0                0x00010001

#define EMI_DSRAM_VAL_MCP0               0x00000011

/**
  * Setup PSRAM mode register to BRBW mode, wrap-64-bytes, LC=3(data T)
  */
  
#define EMI_PSRAM_BURST_OP_1_MCP0           MEM_CMD_OP_16BIT_RD
#define EMI_PSRAM_BURST_OP_2_MCP0           MEM_CMD_OP_16BIT_RD
#define EMI_PSRAM_BURST_OP_3_MCP0           MEM_CMD_OP_16BIT_WR
#define EMI_PSRAM_BURST_OP_4_MCP0           MEM_CMD_OP_16BIT_WR
#define EMI_PSRAM_BURST_OP_5_MCP0           MEM_CMD_OP_16BIT_RD
#define EMI_PSRAM_BURST_OP_6_MCP0           MEM_CMD_OP_16BIT_RD
#define EMI_PSRAM_BURST_OP_7_MCP0           MEM_CMD_OP_16BIT_WR
#define EMI_PSRAM_BURST_OP_8_MCP0           MEM_CMD_OP_16BIT_WR
#define EMI_PSRAM_BURST_ADDRESS_1_MCP0    0x0FFFFFFE
#define EMI_PSRAM_BURST_ADDRESS_2_MCP0    0x0FFFFFFE
#define EMI_PSRAM_BURST_ADDRESS_3_MCP0    0x0FFFFFFE
#define EMI_PSRAM_BURST_ADDRESS_4_MCP0    0x0FFFFFFE
#define EMI_PSRAM_BURST_ADDRESS_5_MCP0    0x0FFFFFFE
#define EMI_PSRAM_BURST_ADDRESS_6_MCP0    0x0FFFFFFE
#define EMI_PSRAM_BURST_ADDRESS_7_MCP0    0x0FFFFFFE
#define EMI_PSRAM_BURST_ADDRESS_8_MCP0    0x0FFFFFFE
#define EMI_PSRAM_BURST_DATA_1_MCP0      0x0
#define EMI_PSRAM_BURST_DATA_2_MCP0      0x0
#define EMI_PSRAM_BURST_DATA_3_MCP0      0x01
#define EMI_PSRAM_BURST_DATA_4_MCP0      0x2313
#define EMI_PSRAM_BURST_DATA_5_MCP0      0x0
#define EMI_PSRAM_BURST_DATA_6_MCP0      0x0
#define EMI_PSRAM_BURST_DATA_7_MCP0      0x00
#define EMI_PSRAM_BURST_DATA_8_MCP0      0x0010

#elif defined(__EMI_CLK_166MHZ__)
/* PSRAM async */
#define EMI_CONB_ASYNC_MCP0               0x39320D61

/* PSRAM burst */
#define EMI_CONB_BURST_MCP0               0xA0000000
#define EMI_CONF_BURST_MCP0               0xB2024419

/*EMI GENA value*/
#define EMI_GENERAL_A_VAL_MCP0           0x00000401

#define EMI_RDCT_VAL_MCP0                0x20004001

#define EMI_IDL_A_VAL_MCP0             0x0
#define EMI_IDL_B_VAL_MCP0             0x0
#define EMI_IDL_C_VAL_MCP0             0x0
#define EMI_IDL_D_VAL_MCP0             0x0
#define EMI_IDL_E_VAL_MCP0             0x0

#define EMI_ODL_A_VAL_MCP0             0x0
#define EMI_ODL_B_VAL_MCP0             0x0
#define EMI_ODL_C_VAL_MCP0             0x0
#define EMI_ODL_D_VAL_MCP0             0x0
#define EMI_ODL_E_VAL_MCP0             0x0
#define EMI_ODL_F_VAL_MCP0             0x0   

/* EMI_DRV value */
#define EMI_IO_A_VAL_MCP0                0x00010001
#define EMI_IO_B_VAL_MCP0                0x00010001

#define EMI_DSRAM_VAL_MCP0               0x00005111

/**
  * Setup PSRAM mode register to BRBW mode, wrap-64-bytes, LC=3(data T)
  */
  
#define EMI_PSRAM_BURST_OP_1_MCP0           MEM_CMD_OP_16BIT_RD
#define EMI_PSRAM_BURST_OP_2_MCP0           MEM_CMD_OP_16BIT_RD
#define EMI_PSRAM_BURST_OP_3_MCP0           MEM_CMD_OP_16BIT_WR
#define EMI_PSRAM_BURST_OP_4_MCP0           MEM_CMD_OP_16BIT_WR
#define EMI_PSRAM_BURST_OP_5_MCP0           MEM_CMD_OP_16BIT_RD
#define EMI_PSRAM_BURST_OP_6_MCP0           MEM_CMD_OP_16BIT_RD
#define EMI_PSRAM_BURST_OP_7_MCP0           MEM_CMD_OP_16BIT_WR
#define EMI_PSRAM_BURST_OP_8_MCP0           MEM_CMD_OP_16BIT_WR
#define EMI_PSRAM_BURST_ADDRESS_1_MCP0    0x0FFFFFFE
#define EMI_PSRAM_BURST_ADDRESS_2_MCP0    0x0FFFFFFE
#define EMI_PSRAM_BURST_ADDRESS_3_MCP0    0x0FFFFFFE
#define EMI_PSRAM_BURST_ADDRESS_4_MCP0    0x0FFFFFFE
#define EMI_PSRAM_BURST_ADDRESS_5_MCP0    0x0FFFFFFE
#define EMI_PSRAM_BURST_ADDRESS_6_MCP0    0x0FFFFFFE
#define EMI_PSRAM_BURST_ADDRESS_7_MCP0    0x0FFFFFFE
#define EMI_PSRAM_BURST_ADDRESS_8_MCP0    0x0FFFFFFE
#define EMI_PSRAM_BURST_DATA_1_MCP0      0x0
#define EMI_PSRAM_BURST_DATA_2_MCP0      0x0
#define EMI_PSRAM_BURST_DATA_3_MCP0      0x01
#define EMI_PSRAM_BURST_DATA_4_MCP0      0x2B13
#define EMI_PSRAM_BURST_DATA_5_MCP0      0x0
#define EMI_PSRAM_BURST_DATA_6_MCP0      0x0
#define EMI_PSRAM_BURST_DATA_7_MCP0      0x00
#define EMI_PSRAM_BURST_DATA_8_MCP0      0x0010

#else
Error!!
#endif




#if ( defined(MT6235) || defined(MT6235B) )

const kal_uint32   EMI_SettingOnCS[4] =
{
   1,
   1,
   0,
   0
};

#elif ( defined(MT6236) || defined(MT6236B) )

const kal_uint32   EMI_SettingOnCS[4] =
{
   1,
   1,
   0,
   0
};

#elif ( defined(MT6253) || defined(MT6252H) )

const kal_uint32   EMI_SettingOnCS[4] =
{
   1,
   1,
   0,
   0
};

#elif ( defined(MT6252) )

const kal_uint32   EMI_SettingOnCS[4] =
{
   0,
   1,
   0,
   0
};

#elif ( defined(MT6255) || defined(MT6922))

const kal_uint32   EMI_SettingOnCS[4] =
{
   EMI_CONA_ASYNC_VAL,
   EMI_CONB_ASYNC_VAL,
   0,
   0
};

#elif ( defined(MT6250) )

const kal_uint32   EMI_SettingOnCS[4] =
{
   0,
   1,
   0,
   0
};

#endif








/**
   * memory mode-switch command operation.
   */
typedef enum
{
   MEM_CMD_OP_16BIT_RD = 0x00000000,
   MEM_CMD_OP_16BIT_WR,
   MEM_CMD_OP_32BIT_RD,
   MEM_CMD_OP_32BIT_WR,
   MEM_CMD_OP_NOP
} MEM_CMD_OP;


/**
   * memory device mode switch information.
   */

/* 
      1. EMI_NOR_CMD_num_max, EMI_PSRAM_CMD_num_max will be the largest one of all valid MCP 
         for all OPs which are not used by certain MCP, the OP must be MEM_CMD_OP_NOP 
      2. Some fields are moved to MTK_Combo_List
 */
typedef struct 
{

   kal_char m_identifier[8];   

   /**
      * EMI control register value.
      */
 
   kal_uint32 EMI_CONB_ASYNC_value;

   kal_uint32 EMI_CONB_BURST_value;
   kal_uint32 EMI_CONF_BURST_value;
   
   kal_uint32 EMI_GENA_value;
   
   kal_uint32 EMI_RDCT_value;
   
   kal_uint32 EMI_IDL_A_value; 
   kal_uint32 EMI_IDL_B_value;
   kal_uint32 EMI_IDL_C_value;
   kal_uint32 EMI_IDL_D_value;
   kal_uint32 EMI_IDL_E_value;
   
   kal_uint32 EMI_ODL_A_value;
   kal_uint32 EMI_ODL_B_value;
   kal_uint32 EMI_ODL_C_value;
   kal_uint32 EMI_ODL_D_value;
   kal_uint32 EMI_ODL_E_value;
   kal_uint32 EMI_ODL_F_value;
   
   kal_uint32 EMI_IO_A_value;
   kal_uint32 EMI_IO_B_value;

   kal_uint32 EMI_DSRAM_value;
   
   /** 
     * Only Burst Mode
     */
     

   /**
      * PSRAM switch command sets.
      */
   kal_uint32 EMI_PSRAM_CMD_num;
   
   kal_uint32 EMI_PSRAM_CMD_OP[__EMI_PSRAM_CMD_NUM];
   kal_uint32 EMI_PSRAM_CMD_ADDR[__EMI_PSRAM_CMD_NUM];
   kal_uint32 EMI_PSRAM_CMD_DATA[__EMI_PSRAM_CMD_NUM];

} MTK_EMI_Info;

/**
   * List of All valid MCPs
   */ 
 
typedef struct 
{
   /**
      * header pattern information.
      */
   kal_char m_identifier[16];
   /**
      * chip version information.
      * m_ver = 1 for MT6253
      */
   kal_uint32 m_ver;
   /**
      * switch op version information.
      * m_ver = 1 for initial version.
      */
   kal_uint8 op_ver;

  
   kal_uint8 reserved_1;  
   kal_uint8 reserved_2;   

   /**
      * Numbers of MCPs
      */
   kal_uint8 mcps_num; 

   /** List of all MCP
     *
     */
   MTK_EMI_Info mem_info[__EMI_COMBO_ENTRY_COUNT];
   
} MTK_EMI_List;


/****************************************************
 * This part is for auto-gen validity CHECK *
 * Don't modify any content in this comment section *


 ****************************************************/

#endif /* __CUSTOM_EMI__ */

#endif //#if defined(MT6260)

