/*****************************************************************************
 *
 * Filename:
 * ---------
 *   matv_dcl.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   implement adapter of atv and dcl, for dcl remove SW I2C
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================

 ******************************************************************************
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(__MTK_TARGET__) && defined(__ATV_SUPPORT__)
#if defined(MT6250)|| defined(MT6260)
#undef __SERIAL_SENSOR_V1_SUPPORT__
#endif

#include "kal_release.h"
//#include "gpio_sw.h"
#include "dcl.h"
#include "camera_sccb.h"
#include "matv_hostdrv.h"
#include "matvctrl.h"
#include "hostlib.h"

#define _ATV_NOT_SUPPORT_LCM_TE_ 
#if defined(_ATV_NOT_SUPPORT_LCM_TE_)
kal_bool bATV_TE_Enable = KAL_FALSE;
extern kal_bool gdi_lcd_get_te_ctrl(void);
extern kal_bool gdi_lcd_set_te_ctrl(kal_bool te_ctrl);
#endif

/////////////////////////////////////////////////////////////////////////////
//power on/off/suspend
/////////////////////////////////////////////////////////////////////////////

#if defined(__CUST_NEW__)
extern const char gpio_matv_power_en_pin;
extern const char gpio_matv_reset_pin;
#if defined(__ATV_I2S_SUPPORT__)
extern const char gpio_i2s_data_pin;
#endif
#define MT519X_PAD_PU			gpio_matv_power_en_pin //(15|0x80)//gpio_matv_power_en_pin
#define MT519X_PAD_RSTN		gpio_matv_reset_pin //(16|0x80)//gpio_matv_reset_pin
#else
#define MT519X_PAD_PU			46
#define MT519X_PAD_RSTN		3
#endif

#if defined(MT6256)|| defined(MT6250)|| defined(MT6260)
extern void bSystemInit(void);
extern void bSystemShutdown(void);
#endif
extern void ATV_i2c_init(void);
extern void ATV_i2c_deinit(void);
extern kal_bool mtv_atv_get_channel_scan_mode(void);
extern void AFE_SetClassDGain(kal_uint16 u2Gain);

#if defined(__WIFI_SUPPORT__)
extern kal_int32 wifi_driver_customer_setting[];
#endif

kal_bool g_matv_FactoryMode = KAL_FALSE;
#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_MATVDRIVER_ROCODE", rodata = "DYNAMIC_CODE_MATVDRIVER_ROCODE"
#endif
/*************************************************************************
* FUNCTION
*    Matv_Write_GPIO
*
* DESCRIPTION
*    this function contrl matv reset/pdn/VSYNC/HSYNC/I2S_Data pin high or low
*
* PARAMETERS
*    Pin: gpio pin, -1: just return
*    Data: 0: low, 1: high, -1: just return
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
void Matv_Write_GPIO(DCL_UINT32 Pin, DCL_UINT32 Data)
{
    const DCL_HANDLE Handle = DclGPIO_Open(DCL_GPIO, Pin);
    
    DclGPIO_Control(Handle, GPIO_CMD_SET_MODE_0, 0);
    DclGPIO_Control(Handle, GPIO_CMD_SET_DIR_OUT, 0);
    DclGPIO_Control(Handle, Data ? GPIO_CMD_WRITE_HIGH : GPIO_CMD_WRITE_LOW, 0);
    DclGPIO_Close(Handle);
}

/*************************************************************************
* FUNCTION
*    Matv_Set_VH_Mode
*
* DESCRIPTION
*    this function use to set VSYNC/HSYNC to be dedicated mode and input direction
*
* PARAMETERS
*    Pin: gpio pin,
*    Mode: VSYNC/HSYNC dedicated mode
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
 void Matv_Set_VH_Mode(DCL_UINT32 Pin, DCL_UINT32 Mode)
{
    const DCL_HANDLE Handle = DclGPIO_Open(DCL_GPIO, Pin);
    DclGPIO_Control(Handle, Mode, 0);
	DclGPIO_Control(Handle, GPIO_CMD_SET_DIR_IN, 0);
    DclGPIO_Close(Handle);
}

/*************************************************************************
* FUNCTION
*    CamPMU_Enable
*
* DESCRIPTION
*    this function enable camera power of PMU
*
* PARAMETERS
*    VCamera: VCAMA/VCAMD of PMU power
*    Voltage: the voltage of power
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
void MatvPMU_Enable(PMU_LDO_BUCK_LIST_ENUM VMatv, PMU_VOLTAGE_ENUM Voltage)
{
  const DCL_HANDLE Handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
  PMU_CTRL_LDO_BUCK_SET_EN PmuEn;
  PMU_CTRL_LDO_BUCK_SET_VOLTAGE PmuVol;
  
  PmuVol.voltage = Voltage;
  PmuVol.mod = VMatv;
  DclPMU_Control(Handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&PmuVol);
  
  PmuEn.enable = DCL_TRUE;
  PmuEn.mod = VMatv;
  DclPMU_Control(Handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&PmuEn);
  
  DclPMU_Close(Handle);
}


/*************************************************************************
* FUNCTION
*    CamPMU_Disable
*
* DESCRIPTION
*    this function disable camera power of PMU
*
* PARAMETERS
*    VCamera: VCAMA/VCAMD of PMU power
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
 void MatvPMU_Disable(PMU_LDO_BUCK_LIST_ENUM VMatv)
{
  const DCL_HANDLE Handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
  PMU_CTRL_LDO_BUCK_SET_EN PmuEn;
  
  PmuEn.enable = DCL_FALSE;
  PmuEn.mod = VMatv;
  DclPMU_Control(Handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&PmuEn);
  
  DclPMU_Close(Handle);
}

void ATV_sccb_write(kal_uint32 addr, kal_uint32 para)
{
	MatvWriteCmosSensor(addr,para);
}

kal_uint16 ATV_sccb_read(kal_uint16 addr)
{
    
	return MatvReadCmosSensor(addr);
}	/* MATVReadCmosMATV() */


void ATVSccbInit ()
{

    MatvSccbInit(CAMERA_HW_SCCB, 1, 1, 0x01);
    //MatvSccbInit(CAMERA_SW_SCCB, 1, 1, 0x1);
		

}

void MatvGetHWInfo(P_IMAGE_SENSOR_HW_DEPENDENT_STRUCT Info)
{
  Info->DataPinConnection = DATA_PIN_CONNECT_BIT9_2;
  Info->IspDrivingCurrent = ISP_DRIVING_2MA;
}



/*****************************************************************************
 * FUNCTION
 *	matv_module_power_off
 * DESCRIPTION
 *	power off sequency
 * PARAMETERS
 *	 void
 * RETURNS
 *	
 *****************************************************************************/ 
void  matv_module_power_off(void)
{

	 Matv_Write_GPIO(MT519X_PAD_PU, 0);
	 Matv_Write_GPIO(MT519X_PAD_RSTN, 0);
	 ATV_i2c_deinit();
	 MatvPMU_Disable(VCAMA);
	 MatvPMU_Disable(VCAMD);
#if defined(_ATV_NOT_SUPPORT_LCM_TE_)
    gdi_lcd_set_te_ctrl(bATV_TE_Enable);
#endif
#if defined(MT6256)|| defined(MT6250)
	bSystemShutdown();
#endif
#if defined(MT6260)
#if defined(__WIFI_SUPPORT__)
	if(wifi_driver_customer_setting[12] == 0)
	bSystemShutdown();
#else
	bSystemShutdown();
#endif
#endif

}

 /*****************************************************************************
 * FUNCTION
 *matv_module_power_on
 * DESCRIPTION
 *	config power on seq
 * PARAMETERS
 * RETURNS
 * NONE
 *****************************************************************************/
 void  matv_module_power_on(void)
 {

	DCL_UINT32  vsync_gpio_pin = 0;
	DCL_UINT32  hsync_gpio_pin = 0;
	DCL_UINT32 vsync_mode = 0;
	DCL_UINT32 hsync_mode = 0;
#if defined(__ATV_I2S_SUPPORT__)
//	DCL_UINT32  i2s_data_pin = (17|0x80);
//   DCL_UINT32  i2s_data_mode = GPIO_CMD_SET_MODE_2;
#endif

#if defined(MT6256)|| defined(MT6250)
	bSystemInit();
#endif

#if defined(MT6260)
#if defined(__WIFI_SUPPORT__)
	if(wifi_driver_customer_setting[12] == 0)
	bSystemInit();
#else
	bSystemInit();
#endif
#endif


#if (defined (MT6256)||defined(MT6255))
	*(volatile kal_uint32*)0x801a0004 |= 0x20;
#endif


#if defined(_ATV_NOT_SUPPORT_LCM_TE_)
    bATV_TE_Enable = gdi_lcd_get_te_ctrl();
//    gdi_lcd_set_te_ctrl(KAL_FALSE);
#endif
	MatvPMU_Enable(VCAMA, PMU_VOLT_02_800000_V);
	MatvPMU_Enable(VCAMD, PMU_VOLT_02_800000_V);

    ATV_i2c_init();
	Matv_Write_GPIO(MT519X_PAD_PU, 0);
    Matv_Write_GPIO(MT519X_PAD_RSTN, 0);
	Matv_Write_GPIO(MT519X_PAD_PU, 1);
	kal_sleep_task(kal_milli_secs_to_ticks(25));
	vsync_gpio_pin = 56;//61;
	hsync_gpio_pin = 55;//60;
	vsync_mode = GPIO_CMD_SET_MODE_1;
	hsync_mode = GPIO_CMD_SET_MODE_1;

    Matv_Write_GPIO(vsync_gpio_pin, 0);
    Matv_Write_GPIO(hsync_gpio_pin, 0);
#if defined(__ATV_I2S_SUPPORT__)
//		Matv_Write_GPIO(i2s_data_pin, 0);
#endif
    Matv_Write_GPIO(MT519X_PAD_RSTN, 1);
	kal_sleep_task(kal_milli_secs_to_ticks(15));

   Matv_Set_VH_Mode(vsync_gpio_pin, vsync_mode);
   Matv_Set_VH_Mode(hsync_gpio_pin, hsync_mode);
   
#if defined(__ATV_I2S_SUPPORT__)
//	Matv_Write_GPIO(i2s_data_pin, i2s_data_mode);
#endif
 }


/*****************************************************************************
 * FUNCTION
 *	matv_set_atv_chip_customization
 * DESCRIPTION
 *	mostly, you needn't to do customization
 * PARAMETERS
 *	NONE
 * RETURNS
 *	NONE
 *****************************************************************************/
void matv_set_atv_chip_customization(void)
{

	kal_uint8 driving_current = 0xa0;  // default adjust PCLK Driving current

	if(g_matv_FactoryMode==KAL_FALSE)
	{
		driving_current =  0xa4;
	}
	else
	{
		driving_current = 0xa4;
	}

 	DrvSetChipDep(MTK_PAD_DRIVING,driving_current);

#if (defined(__SERIAL_SENSOR_V1_SUPPORT__))     //for serial
	DrvSetChipDep(MTK_PAD_DRIVING,0x09);
	DrvSetChipDep(MTK_PAD_DRIVING,0xA9);
#endif
}


/*****************************************************************************
 * FUNCTION
 *	matv_get_custom_frame_rate
 * DESCRIPTION
 *	matv frame rate customization, mostly, this function don't need to modify.
 * PARAMETERS
 *	NONE
 * RETURNS
 *	frame rate, it can return one of 
 *    ATV_20FPS   
 *     ATV_15FPS  
 *    ATV_30FPS  
 *****************************************************************************/

kal_uint8 matv_get_customization_frame_rate(void)
{
  return 0;  // if return 0, use default value for matv frame rate.
}

/*******************
   
	  Class-D Class-AB		 
  000 6 dB			 0 dB	 
  001 9 dB			 3 dB	 
  010 12 dB   6 dB		 
  011 15 dB   9 dB		 
  100 18 dB   12 dB 	 
  101 21 dB   15 dB 	 
  110 24 dB   18 dB 	 
  111 27 dB   21 dB    */
  
#define CUATOM_MATV_GAIN      6    // ClassAB  18dB
#if defined(PMIC_6253_REG_API)
  kal_uint8 ori_gain;
#endif // #if defined(PMIC_6253_REG_API)

/*****************************************************************************
 * FUNCTION
 *	matvdrv_audio_control
 * DESCRIPTION
 *	audio D-Class Gain customization
 * PARAMETERS
 *	 on 	 [IN]		 KAL_TRUE: use audio D-Class Gain control; 
 * RETURNS
 *	void
 *****************************************************************************/

#if defined(PMIC_6253_REG_API)

void matv_pmu6253_spk_vol(kal_uint8 vol)
{
	DCL_HANDLE handle;
	PMU_CTRL_SPK_SET_VOL_VALUE val;
	val.volValue=vol;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, SPK_SET_VOL_VALUE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

kal_uint8 matv_pmu6253_spk_get_vol(void)
{
	DCL_HANDLE handle;
	PMU_CTRL_SPK_GET_VOL_VALUE val;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, SPK_GET_VOL_VALUE, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);

	return (kal_uint8)val.volValue;
}

#endif
void matvdrv_audio_control(kal_bool on)
{
#if defined(MT6253T)||defined(MT6253)||defined(MT6253D)||defined(PMIC_6253_REG_API)
	  kal_uint8 temp_gain = 0;
#endif
#if defined(PMIC_6253_REG_API)
	  if(on)
	  {
		  temp_gain = CUATOM_MATV_GAIN;
				 /* Store default Class-AB gain (e.g. 0dB) */
		  ori_gain = matv_pmu6253_spk_get_vol();
  
		  /* Set Class-AB gain for ATV */
		  /* soft start */
		  if (ori_gain < CUATOM_MATV_GAIN)
		  {
		   kal_uint32 i;
			 for (i= ori_gain+1;i<=CUATOM_MATV_GAIN;i++)
			 {
				  matv_pmu6253_spk_vol(i);  // Set PMU ClassD/ClassAB gain
				  kal_sleep_task(1);   // 注意，使用 kal_sleep 必?在 task裡面
			  }
		  }
		  else if(ori_gain > CUATOM_MATV_GAIN)
		  {
		   kal_uint32 i;
			 for (i=ori_gain-1;i>=CUATOM_MATV_GAIN;i--)
			 {
				  matv_pmu6253_spk_vol(i);  // Set PMU ClassD/ClassAB gain
				  kal_sleep_task(1);   // 注意，使用 kal_sleep 必?在 task裡面
			  }
		  }
  
	  }//if (on)
	  else
	  {
		  matv_pmu6253_spk_vol(temp_gain);
	  }
#endif // #if defined(PMIC_6253_REG_API)
  /* Update Class-AB gain to AFE */
#if defined(MT6253T)||defined(MT6253)||defined(MT6253D)
	  AFE_SetClassDGain(temp_gain);
#endif
}

#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif
#endif




