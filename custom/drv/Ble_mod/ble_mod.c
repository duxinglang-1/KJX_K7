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
 *    ble_mod.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module is for ble module driver.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(__BLE_MODULE_SUPPORT__)  /*SPI */
#include "string.h"
#include "dcl_gpio.h"
#include "kal_general_types.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#include "dcl.h"
#include "ble_mod.h"
#include "Kjx_prin.h"

 //2，按要求设定各SPI口的高低电平函数
#define BLE_MOD_SET_SPI_CLK_OUTPUT		GPIO_InitIO(1,BLE_MOD_SPI_CLK); {int j; for(j=0;j<spi_delay1;j++);}
#define BLE_MOD_SET_SPI_CLK_HIGH		GPIO_WriteIO(1,BLE_MOD_SPI_CLK); {int j; for(j=0;j<spi_delay1;j++);}
#define BLE_MOD_SET_SPI_CLK_LOW			GPIO_WriteIO(0,BLE_MOD_SPI_CLK); {int j; for(j=0;j<spi_delay1;j++);}

#define BLE_MOD_SET_SPI_DI_INPUT		GPIO_InitIO(0,BLE_MOD_SPI_DI); {int j; for(j=0;j<spi_delay1;j++);}
#define BLE_MOD_SET_SPI_DI_HIGH			GPIO_WriteIO(1,BLE_MOD_SPI_DI); {int j; for(j=0;j<spi_delay1;j++);}
#define BLE_MOD_SET_SPI_DI_LOW			GPIO_WriteIO(0,BLE_MOD_SPI_DI); {int j; for(j=0;j<spi_delay1;j++);}
#define BLE_MOD_GET_SPI_DI_DATA_BIT		GPIO_ReadIO(BLE_MOD_SPI_DI)

#define BLE_MOD_SET_SPI_DO_OUTPUT		GPIO_InitIO(1,BLE_MOD_SPI_DO); {int j; for(j=0;j<spi_delay1;j++);}
#define BLE_MOD_SET_SPI_DO_HIGH			GPIO_WriteIO(1,BLE_MOD_SPI_DO); {int j; for(j=0;j<spi_delay1;j++);}
#define BLE_MOD_SET_SPI_DO_LOW			GPIO_WriteIO(0,BLE_MOD_SPI_DO); {int j; for(j=0;j<spi_delay1;j++);}

#define BLE_MOD_SET_SPI_CS_OUTPUT		GPIO_InitIO(1,BLE_MOD_SPI_CS); {int j; for(j=0;j<spi_delay1;j++);}
#define BLE_MOD_SET_SPI_CS_HIGH			GPIO_WriteIO(1,BLE_MOD_SPI_CS); {int j; for(j=0;j<spi_delay1;j++);}
#define BLE_MOD_SET_SPI_CS_LOW			GPIO_WriteIO(0,BLE_MOD_SPI_CS); {int j; for(j=0;j<spi_delay1;j++);}


void ble_mod_delay(kal_uint32 delay_count)
{
	volatile kal_uint32 delay;
	for(delay =0;delay <(delay_count);delay++) {}
}

//  3，SPI读写函数
kal_uint8 ble_mod_spi_readwrite_data(void)
{  
    kal_uint8 i,temp = 0,read_bit; 
    kal_uint16 delay = DELAY_TIME; //CLK延时，依具体而定    //132  100us
  
    for(i = 0;i < 8;i++)  
    {  
        BLE_MOD_SET_SPI_CLK_HIGH;                	//时钟上升沿写入数据  
        
		read_bit = BLE_MOD_GET_SPI_DI_DATA_BIT;		//读输入数据
		if(0!=read_bit)
		{
			temp |= (1<<i);  //依次存高位
		}   
		 
	    ble_mod_delay(delay);  
        BLE_MOD_SET_SPI_CLK_LOW;                	//时钟下降沿读取数据  
        ble_mod_delay(delay);  
    }  
    
    return temp;  
}

void ble_mod_spi_read_bytes(kal_uint8 *pBuff)
{
	kal_uint8 i;  
	GPIO_ModeSetup(BLE_MOD_SPI_CS,0);
	GPIO_PullenSetup(BLE_MOD_SPI_CS,KAL_FALSE);
	GPIO_InitIO(0,BLE_MOD_SPI_CS); 

    for(i = 0;i < BLE_MOD_SPI_RECEIVE_LEN;i ++)  
	{ 
		if(GPIO_ReadIO(BLE_MOD_SPI_CS))  break;

        pBuff[i] = ble_mod_spi_readwrite_data();  
	}  

	ble_mod_delay(5);
	GPIO_ModeSetup(BLE_MOD_SPI_CS,3);
	GPIO_PullenSetup(BLE_MOD_SPI_CS, KAL_TRUE);
}

/*****************************************************************************
 *  Globall Functions		全局函数
 *****************************************************************************/
extern CamDclPMU_Enable(PMU_LDO_BUCK_LIST_ENUM VCamera, PMU_VOLTAGE_ENUM Voltage);
extern void CamDclPMU_Disable(PMU_LDO_BUCK_LIST_ENUM VCamera);
void ble_mod_power_on(void)
{
#ifdef BLE_MOD_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	CamDclPMU_Enable(VCAMA, PMU_VOLT_02_800000_V);	/* PMU Enable VCAM_A, 2.8V */

	GPIO_ModeSetup(BLE_MOD_SPI_POWER,0);
	GPIO_InitIO(1, BLE_MOD_SPI_POWER);
	GPIO_WriteIO(1, BLE_MOD_SPI_POWER);		

	GPIO_ModeSetup(BLE_MOD_SPI_CLK,0);
	BLE_MOD_SET_SPI_CLK_OUTPUT;

	GPIO_ModeSetup(BLE_MOD_SPI_DI,0);
	BLE_MOD_SET_SPI_DI_INPUT;

	GPIO_ModeSetup(BLE_MOD_SPI_DO ,0);
	BLE_MOD_SET_SPI_DO_OUTPUT;

	GPIO_ModeSetup(BLE_MOD_SPI_CS,3);
	GPIO_PullenSetup(BLE_MOD_SPI_CS, KAL_TRUE);

	BLE_MOD_SET_SPI_CLK_LOW;	

#if defined(__BLE_MODULE_SUPPORT__)
	ble_mod_init_msg_protocol(KAL_TRUE);
#endif

}

void ble_mod_power_off(void)
{	
#ifdef BLE_MOD_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	GPIO_ModeSetup(BLE_MOD_SPI_POWER,0);
	GPIO_InitIO(1, BLE_MOD_SPI_POWER);
	GPIO_WriteIO(0, BLE_MOD_SPI_POWER);		
	CamDclPMU_Disable(VCAMA);		/* PMU Disable VCAM_A, 2.8V */

#if defined(__BLE_MODULE_SUPPORT__)
	ble_mod_init_msg_protocol(KAL_FALSE);
#endif
}

#endif
