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
 *   uem_gpio.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file contains definition of custom component module configuration
 *   variables, and routines handle for equipment device.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __CUST_NEW__
#ifndef __L1_STANDALONE__

/*
**   Includes
*/
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "stack_types.h"
#include "syscomp_config.h"
//MSBB remove #include "custom_config.h"
#include "stack_buff_pool.h"
#include "ctrl_buff_pool.h"

#include "device.h"
#include "custom_equipment.h"
#include "custom_hw_default.h"
#include "custom_em.h"
#include "dcl.h"
#include "pwm_drv.h"
#if defined(__RF_DESENSE_TEST__)
#include "rf_desense_test.h"
#endif // __RF_DESENSE_TEST__

#ifdef LQT_SUPPORT /* Please don't remove LQT code segments */
#include "lcd_lqt.h"
extern kal_uint8 lcd_at_mode;
#endif /* LQT_SUPPORT */

/*
**   Typedefs
*/

/*
**   Defines
*/

/*
**   Extern Functions
*/
extern void GPIO_WriteIO(char data, char port);
extern void GPIO_WriteIO_FAST(char data, char port);
//extern void Alter_level(kal_uint8 level);
#if (defined(TOUCH_PAD_SUPPORT) && defined(__MTK_TARGET__))
extern void Touchpad_PowerOn(const kal_bool bOn);
#endif

/*
**   Extern Varibales
*/
extern const char gpio_led_mainbl_en_pin;
//extern const char gpio_led_keybl_en_pin;
//extern const char gpio_led_keybl2_en_pin;
//extern const char gpio_vibrator_en_pin;

/*
**   Globol Varibales
*/

/*
**   Local Functions
*/

/*
**   Local Variables
*/
/***********************************************************
  **
  **  GPIO SETTTING
  **
  ***********************************************************/

#if !defined(__FUE__)
/*
*   Function
*      custom_cfg_outward_gpio_port
*   DESCRIPTION
*      The function is used to handle the port number of the outward gpio device.
*     And it will be call by audio manager.
*   PARAMETERS
*     gpio_device_id      IN
*     port_num            IN/OUT
*   RETURNS
*      kal_bool
*   GLOBALS AFFECTED
*/
kal_uint8 custom_cfg_outward_gpio_port(kal_uint8  gpio_device_id /* gpio_device_enum */)
{
	if((gpio_device_id < GPIO_LABELID_MAX) && (gpio_map_tbl[gpio_device_id].vaild != GPIO_INVAILD))
		return gpio_map_tbl[gpio_device_id].port;
	else
		return 0;
}
#endif

#if defined(__KJX_FUN__)//&&(defined(CUSTOMER_NAME_OLDMAN))
#include "MMI_features.h"
#include "TimerEvents.h"
//extern void kjx_trace_mmi(const char *fmt, ...);
extern void srv_backlight_to_sleep_mode(void);
void kjx_main_lcd_set_level_0(void)
{
	StopTimer(KJX_TIMER_ID_SET_MAINLCD);
	//custom_cfg_gpio_set_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL0);
	srv_backlight_to_sleep_mode();
}

#endif


kal_bool custom_cfg_gpio_set_level(kal_uint8 gpio_dev_type, kal_uint8 gpio_dev_level )
{
    DCL_HANDLE pwm_handle;
    PWM_LEVEL_T level;
	PMU_CTRL_KPLED_SET_EN val_kpled;
#if defined(__RF_DESENSE_TEST__)
    if (RF_DESENSE_MODE_VBOOST_OFF == rf_desense_get_curr_mode()) {
        // Turn Off backlight
    	DCL_HANDLE handle;
		PMU_CTRL_BL_SET_EN val;
		val.enable=DCL_FALSE;
		handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
		DclPMU_Control(handle, BL_SET_EN, (DCL_CTRL_DATA_T *)&val);
		DclPMU_Close(handle);	
    }
    else {
        // Turn On backlight
    	DCL_HANDLE handle;
		PMU_CTRL_BL_SET_EN val;
		val.enable=DCL_TRUE;
		handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
		DclPMU_Control(handle, BL_SET_EN, (DCL_CTRL_DATA_T *)&val);
		DclPMU_Close(handle);	
	}
#endif // __RF_DESENSE_TEST__

	switch(gpio_dev_type)
	{           
		case GPIO_DEV_LED_MAINLCD:
			#ifdef LQT_SUPPORT /* Please don't remove LQT code segments */
			if(!(lcd_at_mode == LCD_AT_RELEASE_MODE))
			{
				gpio_dev_level = 5;
			}
			#endif /* LQT_SUPPORT */

			/*if( gpio_dev_level == LED_LIGHT_LEVEL0)
				GPIO_WriteIO(GPIO_OFF, gpio_led_mainbl_en_pin);
			else
				GPIO_WriteIO(GPIO_ON, gpio_led_mainbl_en_pin);
			*/           

			level.pwm_level = gpio_dev_level;
			pwm_handle= DclPWM_Open(DCL_MAIN_LCD_BL, MOD_UEM);
			DclPWM_Control(pwm_handle, PWM_CMD_SET_LEVEL,(DCL_CTRL_DATA_T*)&level);
			DclPWM_Close(pwm_handle);  

			if( gpio_dev_level == LED_LIGHT_LEVEL0)
			{
				DCL_HANDLE handle;
				PMU_CTRL_BL_SET_EN val;
				val.enable = DCL_FALSE;
				handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
				DclPMU_Control(handle, BL_SET_EN, (DCL_CTRL_DATA_T *)&val);
				DclPMU_Close(handle);		
			}
			else
			{
                    DCL_HANDLE handle;
                    
                    PMU_CTRL_BL_SET_EN val;

                    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);

                    val.enable = DCL_TRUE;
                    DclPMU_Control(handle, BL_SET_EN, (DCL_CTRL_DATA_T *)&val);
                     
                    DclPMU_Close(handle);
			}
        	break;

		case GPIO_DEV_LED_SUBLCD:
			break;

		case GPIO_DEV_LED_STATUS_1:
			break;

		case GPIO_DEV_LED_STATUS_2:
			break;

		case GPIO_DEV_LED_STATUS_3:
			break;

		case GPIO_DEV_LED_KEY:
		#if (!defined(__KJX_FUN__))
			level.pwm_level = gpio_dev_level;
			pwm_handle= DclPWM_Open(DCL_LED_KP, MOD_UEM);
			DclPWM_Control(pwm_handle, PWM_CMD_SET_LEVEL,(DCL_CTRL_DATA_T*)&level);
			DclPWM_Close(pwm_handle);  
						
			if(gpio_dev_level == LED_LIGHT_LEVEL0)
			{
				DCL_HANDLE handle;
				val_kpled.enable = DCL_FALSE;
				handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
				DclPMU_Control(handle, KPLED_SET_EN, (DCL_CTRL_DATA_T *)&val_kpled);
				DclPMU_Close(handle);
			}
			else
			{
				DCL_HANDLE handle;
				val_kpled.enable = DCL_TRUE;
				handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
				DclPMU_Control(handle, KPLED_SET_EN, (DCL_CTRL_DATA_T *)&val_kpled);
				DclPMU_Close(handle);
			}
		 #endif
			break;

		case GPIO_DEV_VIBRATOR:
			{
				DCL_HANDLE handle;
				PMU_CTRL_LDO_BUCK_SET_EN ldoSetEn;
				handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
				ldoSetEn.mod = VIBR;
				if(gpio_dev_level != LED_LIGHT_LEVEL0)
				{
					ldoSetEn.enable = DCL_TRUE;
				}
				else // VIBRATOR_OFF: Vibrator off
				{
					ldoSetEn.enable = DCL_FALSE;
				}
				DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&ldoSetEn);
				DclPMU_Close(handle);
			}
			break;

		default:
			/* error undefine */
			return KAL_FALSE;
	}

	return KAL_TRUE;
}

void custom_start_flashlight(kal_uint8 red_level, kal_uint8 green_level, kal_uint8 blue_level, kal_uint8 duty)
{
	/*
	custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_1, ((red_level>0) ? LED_LIGHT_LEVEL5 : LED_LIGHT_LEVEL0));
	custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_2, ((green_level>0) ? LED_LIGHT_LEVEL5 : LED_LIGHT_LEVEL0));
	custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_3, ((blue_level>0) ? LED_LIGHT_LEVEL5 : LED_LIGHT_LEVEL0));

	//PWM2_Configure(PWM2_Level_Info[0][0], duty);   
	//PWM2_Start();
	*/
}

void custom_stop_flashlight(void)
{ 
	/*
	custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL0);
	custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_2, LED_LIGHT_LEVEL0);
	custom_cfg_gpio_set_level(GPIO_DEV_LED_STATUS_3, LED_LIGHT_LEVEL0);

	//PWM2_Stop();
	*/
}

#endif /* !__L1_STANDALONE__ */

#endif /* __CUST_NEW__ */
