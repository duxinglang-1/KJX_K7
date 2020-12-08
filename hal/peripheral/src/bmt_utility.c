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
 *    bmtutil.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements the interface between BMT and ADC scheduler.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include	"drv_features.h"
#include    "drv_comm.h"
#include	"bmt_trc.h"
// For RHR ADD Usage
#include	"stack_config.h"
#include	"drvpdn.h"
#include	"kal_trace.h"
#include    "chr_parameter.h"
#include    "bmt_utility.h"
#include    "dcl.h"
#include    "kal_general_types.h"
#include    "kal_public_api.h"
#include    "multiboot_config.h"
#include    "adc_sw.h"
#include    "adcsche.h"
#include    "bmt_sw_chip_setting.h"
#include    "bmt_chr_setting.h"
#include    "bmt_timer_control.h"
#include    "drvsignals.h"
#include    "l1sm_public.h"
#if defined(PULSE_LI_CHARGING)  
#include 	"bmt_pulse_li.h"
#elif defined(LINEAR_LI_CHARGING)
#include 	"bmt_linear_li.h"
#endif

// ============================================================ //
//define
// ============================================================ //
#define BMT_CHARGE_CLEAR_WDT_PERIOD				200	// in (10ms) unit, 200 means 2 sec


// ============================================================ //
//global variable
// ============================================================ //
BMTStruct BMT;

DCL_HANDLE  bmt_adc_handle;


#ifdef MTK_SLEEP_ENABLE
kal_uint8 BMTLockARM_handle = 0;
#endif

#if(defined(MTK_SLEEP_ENABLE) && defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__DRV_BMT_WAKE_UP_TDMA_TIMER__) )
kal_uint8 BMTLockMD2G_handle = 0; 
#endif

eventid        		 bmt_event_scheduler_id[BMT_TIMER_INDEX_NUMBER];
event_scheduler     *bmt_event_scheduler_ptr;
event_scheduler     *bmt_adc_event_scheduler_ptr;

bmt_timer bmt_charging_timer_set;

// module interface
BMT_CHARGING_CONTROL_HANDLER bmt_charging_control_handler;

// for multichannel read
kal_int32 BMT_VOL_RESULT[BMT_ADC_MAX_CHANNEL_TOTAL];
kal_uint8 bmt_multi_channel[BMT_ADC_MAX_CHANNEL_TOTAL];
double BMT_ADC_RESULT[BMT_ADC_MAX_CHANNEL_TOTAL];


#if !defined(BMT_CHARGING_DISABLE)
CHRTStruct  BATTime;
bmt_adc bmt_adc_get_data;
kal_uint8 SaftyTimer_Flag = 0;
PMU_CHR_CURRENT_ENUM bmt_usb_chr_current=PMU_CHARGE_CURRENT_INIT;	//set max current as default value
kal_uint32 bmt_total_charge_time = 0;
kal_int32 ISense_Offset = 0;

// for charger CV OV trimming
ChrTrimmingData TrimmingData;

#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
kal_bool First_Time_Charge_Enable = KAL_TRUE;
kal_uint32 bmt_high_vchg_current = 0xfffffff;
kal_int32 Pre_VCharge_AVG = 0;
kal_int32 Cur_VCharge_MAX = 0;
#endif

#ifdef __DRV_BMT_SW_POLLING_CHARGER_OV__
kal_timerid   bmt_sw_polling_timerId;
#endif

#ifdef __DRV_BMT_HIGH_BATTERY_SUPPORT__
PMU_VOLTAGE_ENUM bmt_high_battery_cv = PMU_VOLT_04_200000_V;
PMU_VOLTAGE_ENUM bmt_high_battery_ov = PMU_VOLT_04_300000_V;
#endif

#if defined(__BMT_INTERNAL_CHARGER_PLUG_STATUS_USE__)
static kal_uint8 chr_read_flag;
static CHARGER_IN_OUT_STATUS bmt_chr_in_out_status;
#endif
#endif	//#if !defined(BMT_CHARGING_DISABLE)

const bmt_customized_struct bmt_charging_para =
{
#if !defined(BMT_CHARGING_DISABLE)		
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
(kal_int32)CHR_VCHARGER_HV_HIGH, /* kal_int32 VCHARGER_HIGH */
#else
	(kal_int32)CHR_VCHARGER_HW_HIGH, /* HW HV*/
#endif
	(kal_int32)CHR_VCHARGER_HIGH, /* SW HV */
    (kal_int32)CHR_VCHARGER_LOW, /* kal_int32 VCHARGER_LOW */
    (kal_int32)CHR_ICHARGE_ON_HIGH, /* kal_int32 ICHARGE_ON_HIGH */
    (kal_int32)CHR_ICHARGE_ON_LOW, /* kal_int32 ICHARGE_ON_LOW */
    (kal_int32)CHR_ICHARGE_OFF_HIGH, /* kal_int32 ICHARGE_OFF_HIGH */
  
    (kal_int32)CHR_V_PRE2FAST_THRES, /* kal_int32 V_PRE2FAST_THRES */ 
    (kal_int32)CHR_V_PRE2FULL_THRES, /*kal_int32 CHR_V_PRE2FULL_THRES */
    (kal_int32)CHR_FAST_ICHARGE_HIGHLEVEL, /* kal_int32 FAST_ICHARGE_HIGHLEVEL */
    (kal_int32)CHR_FAST_ICHARGE_LOWLEVEL, /* kal_int32 FAST_ICHARGE_LOWLEVEL */
    (kal_int32)CHR_I_TOPOFF2FAST_THRES, /* kal_int32 I_TOPOFF2FAST_THRES */
    (kal_int32)CHR_I_TOPOFF2FULL_THRES, /* kal_int32 I_TOPOFF2FULL_THRES */

#if defined(LINEAR_LI_CHARGING) || defined(PULSE_LI_CHARGING)  
    (kal_int32)CHR_V_FAST2TOPOFF_THRES_LI, /* kal_int32 V_FAST2TOPOFF_THRES */
    (kal_int32)CHR_V_FULL2FAST_THRES_LI, /* kal_int32 V_FULL2FAST_THRES */
    (kal_int32)CHR_MAX_VBAT_LI, /* kal_int32 MAX_VBAT_LI */
    (kal_int32)CHR_V_PROTECT_HIGH_LI, /* kal_int32 V_PROTECT_HIGH_LI */
    (kal_int32)CHR_V_PROTECT_LOW_LI, /* kal_int32 V_PROTECT_LOW_LI */
#endif
#if defined(LINEAR_NIMH_CHARGING) || defined(PULSE_NIMH_CHARGING)  
    (kal_int32)CHR_V_TEMP_FAST2FULL_THRES_NI, /* kal_int32 V_TEMP_FAST2FULL_THRES_NI */
    (kal_int32)CHR_V_FULL2FAST_THRES_NI, /* kal_int32 V_FULL2FAST_THRES_NI */
    (kal_int32)CHR_MAX_VBAT_NI, /* kal_int32 MAX_VBAT_NI */
#endif 

    /* PRE CHARGE ,search table */
    (kal_uint32)PRE_TON_TIME, /* kal_uint32 PRE_TON */ 
    (kal_uint32)PRE_TOFF_TIME, /*  kal_uint32 PRE_TOFF */

    /* FAST CHARGE, search table */
    (kal_uint32)TOPOFF_TON_TIME, /* kal_uint32 TOPOFF_TON */
    (kal_uint32)TOPOFF_TOFF_TIME, /* kal_uint32 TOPOFF_TOFF */
    
#if defined(PULSE_LI_CHARGING) || defined(PULSE_NIMH_CHARGING)   
    (kal_uint32)PULSE_POSTFULL_TWAIT_TIME, /* kal_uint32 BATPOSTFULL_TWAIT_LI */
    (kal_uint32)PULSE_POSTFULL_TON_TIME, /* kal_uint32 BATPOSTFULL_TON_LI */
    (kal_uint32)PULSE_POSTFULL_TOFF_TIME, /* kal_uint32 BATPOSTFULL_TOFF_LI */
#endif 
#if defined(LINEAR_LI_CHARGING) || defined(PULSE_LI_CHARGING)  
    (kal_uint32)BATFULL_TON_TIME_LI, /* kal_uint32 BATFULL_TON_LI */
    (kal_uint32)BATFULL_TOFF_TIME_LI, /* kal_uint32 BATFULL_TOFF_LI */
#else
    (kal_uint32)BATFULL_TON_TIME_NI;  /* unit : second */
    (kal_uint32)BATFULL_TOFF_TIME_NI;
#endif    
    (kal_uint32)CHR_STOP_TOFF_TIME, /* kal_uint32 BATFULL_TOFF */
    (kal_uint32)BATHOLD_TOFF_TIME, /* kal_uint32 BATHOLD_OFF */
  
    //  kal_int32 CurrOffset[3];
    //{
      CURRENT_OFFSET_IDLE_MODE, // 100ma
      CURRENT_OFFSET_TALK_MODE,
      CURRENT_OFFSET_SWOFF_MODE,
    //},   

    (kal_uint32)TOTAL_CHARGE_TIME,

    //  kal_uint8 TONOFFTABLE[6][2];   
    //{
        (kal_uint8)FAST_ICHARGE_HI_NORMAL_ON,     (kal_uint8)FAST_ICHARGE_HI_NORMAL_OFF,
        (kal_uint8)FAST_ICHARGE_MID_NORMAL_ON,    (kal_uint8)FAST_ICHARGE_MID_NORMAL_OFF,
        (kal_uint8)FAST_ICHARGE_LO_NORMAL_ON,     (kal_uint8)FAST_ICHARGE_LO_NORMAL_OFF,
        (kal_uint8)FAST_ICHARGE_HI_TALK_ON,       (kal_uint8)FAST_ICHARGE_HI_TALK_OFF,
        (kal_uint8)FAST_ICHARGE_MID_TALK_ON,      (kal_uint8)FAST_ICHARGE_MID_TALK_OFF,
        (kal_uint8)FAST_ICHARGE_LO_TALK_ON,       (kal_uint8)FAST_ICHARGE_LO_TALK_OFF,
    //},


#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
	//kal_int32 HIGH_VCHG_TABLE[VCHG_VOL_LEVEL][VCHG_PARAMTER_COUNT];
	//{
		HIGH_V_VCHG_THRESHHOLD_LEVEL_0, HIGH_V_CHARGING_CURRENT_LEVEL_0, HIGH_V_SAFETY_TIME_LEVEL_0,
		HIGH_V_VCHG_THRESHHOLD_LEVEL_1, HIGH_V_CHARGING_CURRENT_LEVEL_1, HIGH_V_SAFETY_TIME_LEVEL_1,
		HIGH_V_VCHG_THRESHHOLD_LEVEL_2, HIGH_V_CHARGING_CURRENT_LEVEL_2, HIGH_V_SAFETY_TIME_LEVEL_2,
		HIGH_V_VCHG_THRESHHOLD_LEVEL_3, HIGH_V_CHARGING_CURRENT_LEVEL_3, HIGH_V_SAFETY_TIME_LEVEL_3,
		HIGH_V_VCHG_THRESHHOLD_LEVEL_4, HIGH_V_CHARGING_CURRENT_LEVEL_4, HIGH_V_SAFETY_TIME_LEVEL_4,		  
		HIGH_V_VCHG_THRESHHOLD_LEVEL_5, HIGH_V_CHARGING_CURRENT_LEVEL_5, HIGH_V_SAFETY_TIME_LEVEL_5,
		HIGH_V_VCHG_THRESHHOLD_LEVEL_6, HIGH_V_CHARGING_CURRENT_LEVEL_6, HIGH_V_SAFETY_TIME_LEVEL_6,
	//},
#endif

	(kal_bool)CHR_BATTERY_TYPE,
    (kal_bool)CHR_CHECK_CHARGER_VOLTAGE,
    (kal_bool)CHR_CHECK_BATT_TEMP,

#endif //#if !defined(BMT_CHARGING_DISABLE)    
    (kal_bool)CHR_CHECK_BATTERY,
    (kal_uint32)CHR_BATT_EXIST_ADC_THRESHOLD /* kal_uint32 BATT_EXIST_ADC_THRESHOLD */
};

// ============================================================ //
// function prototype
// ============================================================ //
#if !defined(BMT_CHARGING_DISABLE)
static void bmt_get_charging_timer_interface(void);
static kal_uint32 bmt_get_max_total_charge_time(void);
static void bmt_stop_charge_timer_callback(void* msg_ptr);
static void bmt_charging_timeout_timer_callback(void* msg_ptr);
static void bmt_top_off_timer_callback(void* msg_ptr);
#endif



// ============================================================ //
//extern variable
// ============================================================ //


// ============================================================ //
//extern function
// ============================================================ //
extern void bmt_sendMes2BMT(module_type srcid, msg_type msgid);
extern void bmt_sendMes2UEM(BMT_CHR_STAT status);
extern void bmt_sendAuxID2UEM(void);

#if(defined(MTK_SLEEP_ENABLE) && defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__DRV_BMT_WAKE_UP_TDMA_TIMER__) )
extern void L1SM_Multi_SW_WakeUp(void); 
extern kal_uint8 L1SM_IntGetHandle( void );
extern void L1SM_IntSleepDisable( kal_uint8 handle );
extern void L1SM_IntSleepEnable( kal_uint8 handle );
#endif

// ============================================================ //
#if defined(__DRV_BATTERY_EXIST_DETECTION__)
// first_time_det: Means whether it is first time to perform battery detection
// If first time, then need to send the battery status to UEM
void bmt_batt_exist_detection(kal_bool first_time_det)
{
   kal_bool batt_exist_state;
   static kal_bool batt_exist_flag = KAL_TRUE;  // Assume batt is mounted at init state

   CHR_DET_TYPE_ENUM chr_type;

   chr_type = bmt_get_chr_type();
   
#ifdef __CS_FAC_DET__
   {
      cs_fac_boot_mode_enum fac_boot_mode;
      fac_boot_mode = cs_fac_det->factory_det_get_boot_mode();
      switch (fac_boot_mode)
      {
      case CS_FAC_BOOT_IDLE:
         ; // We boot into IDLE on purpose, skip battery check
         return;
         break;
      case CS_FAC_BOOT_CHARGING:
         ;
         break;
      case CS_FAC_BOOT_USB_CHARGING:
         ;
         break;
      default:
         break;
      }
   }
#endif // #ifdef __CS_FAC_DET__
   
   batt_exist_state = bmt_is_bat_on();
   drv_trace1(TRACE_GROUP_10, BMT_MSG_BATT_ON_DET, batt_exist_state);
   if ( (batt_exist_flag != batt_exist_state) || (first_time_det) )
   {
      if (batt_exist_state == KAL_FALSE)
      {
			// A temp workaround
			// It seems UEM expect to receive charger in message first in charger boot mode,
			// then be able to process other messages from BMT
			if (first_time_det)
			{
				if ((PW_AC_CHR == chr_type) || (PW_AC_NON_STD_CHR == chr_type))
				{
					// Send charger in to UEM
					bmt_sendMes2UEM(BMT_USB_NO_CHARGING_IN);
				}
			}
         // Batt removal
         bmt_sendMes2UEM(BMT_BATT_OUT);
      }
      else
      {
         // Batt attached
         bmt_sendMes2UEM(BMT_BATT_IN);
         
         // When program run to here, it means we are CHARGER or USB boot mode
         // Manually trigger cable plug-in HISR to perform charging procedure
         //pmic_adpt_sw_trigger_chr_usb_intr
         if ( (!first_time_det) && (batt_exist_flag != batt_exist_state) )
         {
         	bmt_sendMes2BMT(MOD_EINT_HISR/*MOD_BMT*/,MSG_ID_BMT_CHARGER_IND);
         }
         
      }
      batt_exist_flag = batt_exist_state;
   }
}


kal_uint32 bmt_get_batt_exist_det_period(void)
{
	return (KAL_TICKS_1_MIN * 30); // 30 mins	
}


void bmt_battery_det_timer_callback(void* msg_ptr)
{
	bmt_event_scheduler_id[BMT_BATTERY_DET_TIMER] = 0;
	bmt_batt_exist_detection(KAL_FALSE);
    bmt_set_timer(BMT_BATTERY_DET_TIMER, bmt_get_batt_exist_det_period());
}
#endif	//#if defined(__DRV_BATTERY_EXIST_DETECTION__)


void bmt_aux_timer_callback(void* msg_ptr)
{
	bmt_event_scheduler_id[BMT_AUX_TIMER] = 0;
	bmt_sendAuxID2UEM();
}


void (*bmt_timer_callback[BMT_TIMER_INDEX_NUMBER])(void* msg_ptr)=
{
	bmt_aux_timer_callback
	#if !defined(BMT_CHARGING_DISABLE)	
	,bmt_stop_charge_timer_callback	
	,bmt_charging_timeout_timer_callback
	,bmt_top_off_timer_callback
	#endif
	#if defined(__DRV_BATTERY_EXIST_DETECTION__)
	,bmt_battery_det_timer_callback
	#endif
	
};


void bmt_set_timer(bmt_timer_enum timer_id, kal_uint32 tick)
{
#if !defined(BMT_CHARGING_DISABLE)
	kal_uint32 max_total_charge_time;
	
	if(BMT_CHARGE_TIMEOUT_TIMER == timer_id)	
	{
		max_total_charge_time = bmt_get_max_total_charge_time();
		if(bmt_charging_para.bmt_total_charge_time > max_total_charge_time)	//if the custom total charge time large than the max value, set the max vlaue 
			tick = max_total_charge_time;
	}
#endif
	
	bmt_event_scheduler_id[timer_id] = evshed_set_event(bmt_event_scheduler_ptr,(kal_timer_func_ptr)bmt_timer_callback[timer_id], NULL, tick);
}


void bmt_stop_timer(bmt_timer_enum timer_id)
{
   evshed_cancel_event(bmt_event_scheduler_ptr, &bmt_event_scheduler_id[timer_id]);
   #if !defined(BMT_CHARGING_DISABLE)
   if(BMT_CHARGE_TIMEOUT_TIMER == timer_id)
   {
	   drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_STOP_TRC, bmt_total_charge_time);
   }
   #endif
}


void bmt_timer_init(void)
{
	bmt_event_scheduler_ptr = evshed_create("BMT Timer",MOD_BMT,0,255);
	evshed_set_index(bmt_event_scheduler_ptr,BMT_TIMER_INDEX);
}


DCL_UINT32 bmt_get_event_scheduler_timer_index(void *id)
{
	bmt_adc_event_scheduler_ptr = (event_scheduler *)id;
	return BMT_ADC_TIMER_INDEX;
}


CHARGER_IN_OUT_STATUS bmt_read_chr_status(void)
{
#if defined(__BMT_INTERNAL_CHARGER_PLUG_STATUS_USE__)
   chr_read_flag = 0;
   return bmt_chr_in_out_status;
#else
	DCL_HANDLE chr_usb_det_handle;
	CHR_DET_CTRL_GET_CHR_STATUS chr;
	
	chr_usb_det_handle = Dcl_Chr_Det_Open(DCL_CHR_USB_DET, FLAGS_NONE);
	Dcl_Chr_Det_Control(chr_usb_det_handle, CHR_DET_CMD_GET_CHR_STATUS,(DCL_CTRL_DATA_T *)&chr);
    Dcl_Chr_Det_Close(chr_usb_det_handle);    

    return chr.charger_plug_status;
#endif   
}
/*
* FUNCTION
*	   bmt_get_adc_channel_voltage
*
* DESCRIPTION                                                           
*   	This function is used to obtain the Battery voltage of specific channel
*
* CALLS  
*
* PARAMETERS
*	   ch: specific channel
*	   voltage: pointer for read the voltage
*	
* RETURNS
*	   KAL_FALSE: invalid channel
*	   KAL_TRUE:  finish the measurement
*
* GLOBALS AFFECTED
*     None
*/
kal_bool bmt_get_adc_channel_voltage(DCL_ADC_CHANNEL_TYPE_ENUM ch, kal_uint32 *voltage)
{
	DCL_HANDLE adc_handle;
   	ADC_CTRL_GET_PHYSICAL_CHANNEL_T adc_get_channel;
	ADC_CTRL_GET_DATA_T adc_data;
	ADC_CTRL_TRANSFORM_INTO_VOLT_T adcTransV;

	if(ch > DCL_VCHARGER_ADC_CHANNEL)
		return KAL_FALSE;  
   
   	adc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
   	if(adc_handle == DCL_HANDLE_INVALID)
   	{
    	ASSERT(0);   
   	}
	
   	adc_get_channel.u2AdcName = ch;
   	DclSADC_Control(adc_handle, ADC_CMD_GET_CHANNEL, (DCL_CTRL_DATA_T *)&adc_get_channel);     

	adc_data.u1Channel = adc_get_channel.u1AdcPhyCh;
	DclHADC_Control(adc_handle, ADC_CMD_GET_DATA,(DCL_CTRL_DATA_T *)&adc_data);

	adcTransV.u1AdcPhyCh = adc_get_channel.u1AdcPhyCh;
	adcTransV.d8AdcValue = adc_data.u4ADCData;
	DclSADC_Control(adc_handle, ADC_CMD_TRANSFORM_INTO_VOLT, (DCL_CTRL_DATA_T *)&adcTransV);
	
	*voltage = adcTransV.u4Volt;
	
    DclSADC_Close(adc_handle);
	return KAL_TRUE;
}


CHR_DET_TYPE_ENUM bmt_get_chr_type(void)
{
	DCL_HANDLE chr_usb_det_handle;
	CHR_DET_CTRL_QUERY_CHR_TYPE chr;
	
	chr_usb_det_handle = Dcl_Chr_Det_Open(DCL_CHR_USB_DET, FLAGS_NONE);
	Dcl_Chr_Det_Control(chr_usb_det_handle, CHR_DET_CMD_QUERY_CHR_TYPE,(DCL_CTRL_DATA_T *)&chr);
    Dcl_Chr_Det_Close(chr_usb_det_handle);    

	return chr.Chr_det_type;
}


void bmt_Modify_PowerOn_Type(kal_uint8 power_type)
{
        PW_CTRL_SET_POWERON_REASON CtrlVal;
        DCL_HANDLE pmu_handle;
        CtrlVal.powerOnReason = (PW_CTRL_POWER_ON_REASON)power_type; 
        pmu_handle=DclPW_Open(DCL_PW, FLAGS_NONE);
        DclPW_Control(pmu_handle, PW_CMD_SET_POWERON_REASON, (DCL_CTRL_DATA_T *)&CtrlVal);
        DclPW_Close(pmu_handle);
}


kal_uint8 bmt_Get_PowerOn_Type(void)
{
        PW_CTRL_GET_POWERON_REASON CtrlVal;
        DCL_HANDLE pmu_handle;
        pmu_handle = DclPW_Open(DCL_PW, FLAGS_NONE);
        DclPW_Control(pmu_handle, PW_CMD_GET_POWERON_REASON, (DCL_CTRL_DATA_T *)&CtrlVal);
        DclPW_Close(pmu_handle);
        return CtrlVal.powerOnReason;
}


kal_bool bmt_check_if_bat_on(void)
{
	DCL_BOOL bat_on;
	bmt_charging_control_handler(BMT_CHARGING_CMD_GET_BAT_ON_DET_STATUS, &bat_on);

	if(bat_on == DCL_FALSE)
		return KAL_TRUE;
	else
		return KAL_FALSE;
}


kal_bool bmt_is_bat_on_pw()
{
    kal_uint32 voltage=0;

    bmt_get_adc_channel_voltage(DCL_VBATTMP_ADC_CHANNEL, &voltage);
    if(voltage < bmt_charging_para.BATT_EXIST_ADC_THRESHOLD)
       return KAL_TRUE;
    else
       return KAL_FALSE;
}


kal_bool bmt_is_bat_on()
{
   if(bmt_charging_para.bmt_check_battery)
   {
      return bmt_is_bat_on_pw();
   }
   else
   {
      return bmt_check_if_bat_on();
   }
}


kal_int32 bmt_change_VBatTmp_To_BatTmp(kal_int32 VbatTmp)
{
	DCL_HANDLE dcl_adc_handle;
	ADC_CTRL_TRANSFORM_INTO_TEMP_T adc_get_vbattmp;
		
	adc_get_vbattmp.u4Volt = VbatTmp;
	dcl_adc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
	DclSADC_Control(dcl_adc_handle, ADC_CMD_TRANSFORM_INTO_TEMP, (DCL_CTRL_DATA_T *)&adc_get_vbattmp);	   
	DclSADC_Close(dcl_adc_handle);

	return (kal_int32)adc_get_vbattmp.u4Temp;
}


kal_int32 bmt_change_Voltage_To_ISense(DCL_UINT32 TransformVolt)
{
	DCL_HANDLE dcl_adc_handle;
	ADC_CTRL_TRANSFORM_INTO_CURR_T rTransformCurr;

	dcl_adc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
	rTransformCurr.u4Volt = TransformVolt;
	DclSADC_Control(dcl_adc_handle, ADC_CMD_TRANSFORM_INTO_CURR, (DCL_CTRL_DATA_T *)&rTransformCurr);
	DclSADC_Close(dcl_adc_handle);

	return 	(kal_int32)rTransformCurr.u4Curr;
}


static void bmt_get_charging_control_handler(void)
{
#ifdef __GENERAL_EXTERNAL_CHARGER__
	bmt_charging_control_handler = External_chr_control_handler;
#else
	bmt_charging_control_handler = Internal_chr_control_handler;
#endif
}


void bmt_initialize(void)
{
	BMT.call_state = idle_mode;
	BMT.pmictrl_state = PMIC_CHARGEOFF;
	BMT.VBAT_UEM = VBAT_UEM_CHR_OUT;

	bmt_get_charging_control_handler();

#if !defined(BMT_CHARGING_DISABLE)		
	
	bmt_get_charging_timer_interface();

#ifdef MTK_SLEEP_ENABLE
    BMTLockARM_handle = L1SM_GetHandle();
#endif

#if ( defined(MTK_SLEEP_ENABLE) && defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__DRV_BMT_WAKE_UP_TDMA_TIMER__) )
	BMTLockMD2G_handle = L1SM_IntGetHandle(); // just get once
#endif

#endif   
}


#if !defined(BMT_CHARGING_DISABLE)
#ifdef __DRV_BMT_SW_POLLING_CHARGER_OV__
static void bmt_sw_polling_charger_ov(void *timer_param)
{
	DCL_BOOL  charge_en = KAL_FALSE;
	DCL_BOOL  hv_status;

	bmt_charging_control_handler(BMT_CHARGING_CMD_GET_HV_STATUS, &hv_status);		
	
	if (DCL_TRUE == hv_status)
	{
		bmt_charging_control_handler(BMT_CHARGING_CMD_CHARGING_ENABLE, &charge_en);
		drv_trace0(TRACE_GROUP_10, BMT_SW_POLLING_CHARGER_OV_TRC);
	}
	else
	{	
		bmt_charging_control_handler(BMT_CHARGING_CMD_WDT_CLEAR,NULL);
	}	

	kal_set_timer(bmt_sw_polling_timerId, (kal_timer_func_ptr)bmt_sw_polling_charger_ov, NULL, KAL_TICKS_200_MSEC ,	0);
}
#endif


void bmt_enable_sleepmode(kal_bool enable)
{
	if (KAL_TRUE == enable)
	{
		#ifdef __DRV_BMT_SW_POLLING_CHARGER_OV__
		kal_cancel_timer(bmt_sw_polling_timerId);
		#endif

		
		#if(defined(MTK_SLEEP_ENABLE) && defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__DRV_BMT_WAKE_UP_TDMA_TIMER__))
		{
			L1SM_SleepEnable( BMTLockARM_handle ); // should un-lock ARM first
			L1SM_IntSleepEnable( BMTLockMD2G_handle );
		}
		#elif defined(MTK_SLEEP_ENABLE)
		L1SM_SleepEnable(BMTLockARM_handle);
		#endif

	}
	else
	{
		#if(defined(MTK_SLEEP_ENABLE) && defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__DRV_BMT_WAKE_UP_TDMA_TIMER__))
		{
			L1SM_IntSleepDisable( BMTLockMD2G_handle ); // should lock MD2G first
			L1SM_SleepDisable( BMTLockARM_handle );
			L1SM_Multi_SW_WakeUp(); 
		}
		#elif defined(MTK_SLEEP_ENABLE)
		L1SM_SleepDisable(BMTLockARM_handle);
		#endif

		#ifdef __DRV_BMT_SW_POLLING_CHARGER_OV__
		kal_set_timer(bmt_sw_polling_timerId, (kal_timer_func_ptr)bmt_sw_polling_charger_ov, NULL, KAL_TICKS_200_MSEC ,0);
		#endif 
	}
}


void bmt_set_chr_trimming_data(BMT_CTRL_SET_CHR_TRIMMING_DATA *rSetTrimmingData)
{
	TrimmingData.CV_Trim_Enable = rSetTrimmingData->CV_Trim_Enable;
	TrimmingData.OV_Trim_Enable = rSetTrimmingData->OV_Trim_Enable;
	TrimmingData.CV_Trim_Data = rSetTrimmingData->CV_Trim_Data;
	TrimmingData.OV_Trim_Data = rSetTrimmingData->OV_Trim_Data;
}


#if defined(__BMT_INTERNAL_CHARGER_PLUG_STATUS_USE__)
void bmt_set_chr_status(CHARGER_IN_OUT_STATUS status)
{
   bmt_chr_in_out_status = status;
   
   if (chr_read_flag == 0)
   {
      chr_read_flag = 1;
   }
}
#endif   


static kal_uint32 bmt_get_max_total_charge_time(void)
{
#if defined(__DRV_BMT_BATTERY_LARGER_1600MA__)
   	return (KAL_TICKS_1_MIN * 12 * 60); // 12 hours = 720 mins
#else   	
   	return (KAL_TICKS_1_MIN * 8 * 60);  // 8 hours = 480 mins
#endif   	
}


static void bmt_charging_timer_set_by_ADC_sche(DCL_UINT32 *timer_period, DCL_UINT8 *timer_count)
{
	  DCL_STATUS adc_status;
	  ADC_CTRL_MODIFY_PARAM_T adc_para; 
	
	  adc_para.u4Period =  *timer_period;
	  adc_para.u1EvaluateCount = *timer_count;	

	  adc_status = DclSADC_Control(bmt_adc_handle, ADC_CMD_MODIFY_PARAM, (DCL_CTRL_DATA_T *)&adc_para);
	  if(adc_status != STATUS_OK)
	  {
			ASSERT(0);
	  }   	
	 
	  adc_status = DclSADC_Control(bmt_adc_handle, ADC_CMD_START_MEASURE, NULL);
	  if(adc_status != STATUS_OK)
	  {
			ASSERT(0);  		
	  }	      

}


static void bmt_get_charging_timer_interface(void)
{
#ifdef __EXTERNAL_ADC__
	bmt_charging_timer_set = bmt_charging_timer_ext;
#else
	bmt_charging_timer_set = bmt_charging_timer_set_by_ADC_sche;
#endif
}


static void get_vbat(BATPHYStruct *BATPHYS)
{
	BATPHYS->VBAT = BMT_VOL_RESULT[BMT_ADC_VBAT];
	drv_trace1(TRACE_INFO, BMT_VBAT_TRC, BATPHYS->VBAT);
}


// The return unit is mA ==> 1000 means 1A
static void get_isense(BATPHYStruct *BATPHYS)
{
#ifndef __BMT_NO_ISENSE_RESISTOR__
	DCL_UINT32 TransformVolt;

	if(BMT.pmictrl_state == PMIC_CHARGEOFF)
	{	
		ISense_Offset = BMT_VOL_RESULT[BMT_ADC_VISENSE] - BMT_VOL_RESULT[BMT_ADC_VBAT];
	}

	BATPHYS->ISense_Offset = ISense_Offset;

	TransformVolt = BMT_VOL_RESULT[BMT_ADC_VISENSE] - BMT_VOL_RESULT[BMT_ADC_VBAT]-BATPHYS->ISense_Offset;
	BATPHYS->ICHARGE = bmt_change_Voltage_To_ISense(TransformVolt);	
	
	drv_trace1(TRACE_INFO, BMT_VSENSE_TRC,BMT_VOL_RESULT[BMT_ADC_VISENSE]);
	drv_trace1(TRACE_INFO, BMT_ICHARGE_TRC, BATPHYS->ICHARGE);
	drv_trace1(TRACE_INFO, BMT_VSENSE_VBAT_OFFSET_TRC, BATPHYS->ISense_Offset);
#endif	
}


// The return unit is uV ==> 1000000 means 1.0V
static void get_vcharger(BATPHYStruct *BATPHYS)
{
	BATPHYS->VCHARGER = BMT_VOL_RESULT[BMT_ADC_VCHARGER];
	drv_trace1(TRACE_INFO, BMT_VCHARGER_TRC, BATPHYS->VCHARGER);
}


// Return the calculated temp value of battery temperature ==> 23000 means 23C
static void get_bat_temp(BATPHYStruct *BATPHYS)
{
	if (bmt_charging_para.bmt_check_temp)
	{
		BATPHYS->BATTMP = bmt_change_VBatTmp_To_BatTmp(BMT_VOL_RESULT[BMT_ADC_VBATTMP]);
		drv_trace1(TRACE_INFO, BMT_BATTMP_TRC, BATPHYS->BATTMP);
	}
}


kal_int32 get_ISense_Offset()
{
	return ISense_Offset;
}


static void get_adc_data(BATPHYStruct *BATPHYS)
{
	get_vbat(BATPHYS);
	
	get_isense(BATPHYS);
	
	get_vcharger(BATPHYS);
	
	get_bat_temp(BATPHYS);
}


static void bmt_get_adc_interface(void)
{
#ifdef __EXT_ADC__
	bmt_adc_get_data = get_adc_data_ext;
#else
	bmt_adc_get_data = get_adc_data;
#endif
}



#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
static void bmt_high_vchg_first_time_set(void)
{
	BATPHYStruct BATPHYS;

	bmt_ObtainBMTPhystate(&BATPHYS);
	
    bmt_vchg_compare_and_set_current(BATPHYS.VCHARGER, KAL_TRUE);
    Pre_VCharge_AVG = BATPHYS.VCHARGER;
    drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_FIRST_TIME_VCHG_TRC, Pre_VCharge_AVG);

} 


void bmt_vchg_compare_and_set_current(kal_int32 Cur_VCHG, kal_bool Hysteresis_Enable)
{
    static kal_uint8 pre_level = 0xFF;

    kal_uint8 i, cur_level = 0;
	CHR_DET_TYPE_ENUM chr_type;
	
	chr_type = bmt_get_chr_type();
  
    drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_CURRENT_VCHG_TRC, Cur_VCHG);    
    // Cur_VCHG > S/W OVP
    if(Cur_VCHG >= bmt_charging_para.HIGH_VCHG_TABLE[VCHG_VOL_LEVEL - 1][0])
    {
        bmt_high_vchg_current = bmt_charging_para.HIGH_VCHG_TABLE[VCHG_VOL_LEVEL - 1][1]; // Use Last Charge Current
        drv_trace0(TRACE_GROUP_9, BMT_HIGH_VCHG_TOO_HIGH_TRC);
        if(Hysteresis_Enable == KAL_TRUE)
        {
            cur_level = VCHG_VOL_LEVEL;
        }
    }
    else if(Cur_VCHG < bmt_charging_para.HIGH_VCHG_TABLE[0][0])
    {
        drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_LOWEST_THRESHOLD_TRC, bmt_charging_para.HIGH_VCHG_TABLE[0][0]);
        bmt_high_vchg_current = bmt_charging_para.HIGH_VCHG_TABLE[0][1];
        if(Hysteresis_Enable == KAL_TRUE)
        {        
            cur_level = 0;
        }
    }
    else
    {
        for(i = (VCHG_VOL_LEVEL - 1); i > 0; i--)
        {
            drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_UPPER_THRESHOLD_TRC, bmt_charging_para.HIGH_VCHG_TABLE[i][0]);
            drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_LOWER_THRESHOLD_TRC, bmt_charging_para.HIGH_VCHG_TABLE[i-1][0]);
            if((Cur_VCHG < bmt_charging_para.HIGH_VCHG_TABLE[i][0]) && (Cur_VCHG >= bmt_charging_para.HIGH_VCHG_TABLE[i-1][0]))
            {
                bmt_high_vchg_current = bmt_charging_para.HIGH_VCHG_TABLE[i][1];  
                if(Hysteresis_Enable == KAL_TRUE)
                {
                    cur_level = i;
                }
                break;
            }
        }
    }
    
    if(Hysteresis_Enable == KAL_TRUE)
    {
        drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_PRE_CURRENT_LEVEL_TRC, pre_level);       
        drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_CUR_CURRENT_LEVEL_TRC, cur_level);        
        if(cur_level != pre_level && ((cur_level - pre_level) == 1 || (pre_level - cur_level) == 1 ) )
        {
            drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_HYSTERESIS_UPPER_BOUND_TRC, bmt_charging_para.HIGH_VCHG_TABLE[pre_level][0] + BMT_HIGH_VCHG_THRESHOLD);              
            drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_HYSTERESIS_LOWER_BOUND_TRC, bmt_charging_para.HIGH_VCHG_TABLE[cur_level][0] - BMT_HIGH_VCHG_THRESHOLD);                          
            
            // Hysteresis
            if((cur_level > pre_level) && (Cur_VCHG < bmt_charging_para.HIGH_VCHG_TABLE[pre_level][0] + BMT_HIGH_VCHG_THRESHOLD))
            {
                bmt_high_vchg_current = bmt_charging_para.HIGH_VCHG_TABLE[pre_level][1];
            }
            else if((cur_level < pre_level) && (Cur_VCHG > bmt_charging_para.HIGH_VCHG_TABLE[cur_level][0] - BMT_HIGH_VCHG_THRESHOLD))
            {
                bmt_high_vchg_current = bmt_charging_para.HIGH_VCHG_TABLE[pre_level][1];
            }
            else
            {
                pre_level = cur_level;
            }
                
        }
        else
        {
            pre_level = cur_level;
        }
    }
    drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_CHARGE_CURRENT_TRC, bmt_high_vchg_current);                              


	if(chr_type == PW_AC_NON_STD_CHR)
	{
	    if(bmt_high_vchg_current > CHR_NON_AC_CHARGE_CURRENT)
	    {
	        bmt_high_vchg_current = CHR_NON_AC_CHARGE_CURRENT;
	        drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_SET_USB_CHARGE_CURRENT_TRC, CHR_USB_CHARGE_CURRENT);	
	    }
	}
	
}


void bmt_high_vchg_adjust_safetytimer(kal_int32 Cur_VCHG)   
{
    kal_int32 i;
	CHR_DET_TYPE_ENUM chr_type;

	chr_type = bmt_get_chr_type();

    
    drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_CURRENT_VCHG_TRC, Cur_VCHG);
    // Cur_VCHG > S/W OVP
    if(Cur_VCHG > bmt_charging_para.HIGH_VCHG_TABLE[VCHG_VOL_LEVEL - 1][0])
    {
        bmt_total_charge_time = 0;
        drv_trace0(TRACE_GROUP_9, BMT_HIGH_VCHG_TOO_HIGH_TRC);
    }
    else if(Cur_VCHG < bmt_charging_para.HIGH_VCHG_TABLE[0][0])
    {
        drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_LOWEST_THRESHOLD_TRC, bmt_charging_para.HIGH_VCHG_TABLE[0][0]);
        bmt_total_charge_time = bmt_charging_para.HIGH_VCHG_TABLE[0][2];
    }
    else
    {
        for(i = (VCHG_VOL_LEVEL - 1); i > 0; i--)
        {

            drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_UPPER_THRESHOLD_TRC, bmt_charging_para.HIGH_VCHG_TABLE[i][0]);
            drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_LOWER_THRESHOLD_TRC, bmt_charging_para.HIGH_VCHG_TABLE[i-1][0]);
            if((Cur_VCHG < bmt_charging_para.HIGH_VCHG_TABLE[i][0]) && (Cur_VCHG >= bmt_charging_para.HIGH_VCHG_TABLE[i-1][0]))
            {
                bmt_total_charge_time = bmt_charging_para.HIGH_VCHG_TABLE[i][2];  
                drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_TABLE_INDEX_TRC, i);
                break;
            }
        }
    }
    drv_trace1(TRACE_GROUP_9, BMT_CURRENT_PMIC_STATE_TRC, BMT.pmictrl_state);
    if((chr_type != PW_USB_CHR) && (chr_type !=PW_USB_CHARGING_HOST_CHR))
    {
        drv_trace0(TRACE_GROUP_9, BMT_AC_IN_TRC);
    }
    else
    {
        drv_trace0(TRACE_GROUP_9, BMT_USB_IN_TRC);
		bmt_total_charge_time = bmt_charging_para.bmt_total_charge_time;
    }
   
    
}
#endif


static void bmt_internal_adc_init()
{
   ADC_CTRL_GET_PHYSICAL_CHANNEL_T adc_ch;
   ADC_CTRL_CREATE_OBJECT_T adc_create;   
   DCL_STATUS adc_status;
   ADC_CTRL_REGISTER_MEASURE_CB_T registerMeasCB;
   DCL_MULTI_CHANNEL_PARA_T adc_multi_channel_para;

   bmt_adc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
   if(bmt_adc_handle == DCL_HANDLE_INVALID)
   {
      ASSERT(0);   
   }

   adc_ch.u2AdcName = DCL_VBAT_ADC_CHANNEL;
   DclSADC_Control(bmt_adc_handle, ADC_CMD_GET_CHANNEL, (DCL_CTRL_DATA_T *)&adc_ch);       
   bmt_multi_channel[BMT_ADC_VBAT] = adc_ch.u1AdcPhyCh;


   adc_ch.u2AdcName = DCL_VISENSE_ADC_CHANNEL;
   DclSADC_Control(bmt_adc_handle, ADC_CMD_GET_CHANNEL, (DCL_CTRL_DATA_T *)&adc_ch);    
   bmt_multi_channel[BMT_ADC_VISENSE] = adc_ch.u1AdcPhyCh;	


   adc_ch.u2AdcName = DCL_VBATTMP_ADC_CHANNEL;
   DclSADC_Control(bmt_adc_handle, ADC_CMD_GET_CHANNEL, (DCL_CTRL_DATA_T *)&adc_ch);      
   bmt_multi_channel[BMT_ADC_VBATTMP] = adc_ch.u1AdcPhyCh;	   


   adc_ch.u2AdcName = DCL_VCHARGER_ADC_CHANNEL;
   DclSADC_Control(bmt_adc_handle, ADC_CMD_GET_CHANNEL, (DCL_CTRL_DATA_T *)&adc_ch);      
   bmt_multi_channel[BMT_ADC_VCHARGER] = adc_ch.u1AdcPhyCh;	

   adc_create.u4Period = 10; // Measurement period (Uint is in Tick)
   adc_create.u1OwnerId = MOD_BMT; // Indicate the module to for ADC driver to notify the result
   //adc_create.u1AdcChannel = ADC_VBAT_channel; // To be measured physical ADC channel
   adc_create.u1EvaluateCount = 10; // Measurement count
   adc_create.fgSendPrimitive = KAL_FALSE; // Whether to send message to owner module or NOT
   adc_status = DclSADC_Control(bmt_adc_handle, ADC_CMD_CREATE_OBJECT, (DCL_CTRL_DATA_T *)&adc_create);
   if(adc_status != STATUS_OK)
   {
		ASSERT(0);   
   }
 
   registerMeasCB.pfMeasure_cb = adc_sche_measure;	
   adc_status = DclSADC_Control(bmt_adc_handle, ADC_CMD_REGISTER_MEASURE_CB, (DCL_CTRL_DATA_T *)&registerMeasCB);	
   if(adc_status != STATUS_OK)
   {
	   ASSERT(0);
   }	   

   adc_multi_channel_para.bEnable = KAL_TRUE;
   adc_multi_channel_para.u4ADC_ch_number = bmt_multi_channel;
   adc_multi_channel_para.u4Adc_max_ch_number = BMT_ADC_MAX_CHANNEL_TOTAL;
   adc_multi_channel_para.complete_multi_cb = bmt_measure_complete;
   adc_status = DclSADC_Control(bmt_adc_handle, ADC_CMD_SET_MULTI_CHANNEL_READ, (DCL_CTRL_DATA_T *)&adc_multi_channel_para);
   if(adc_status != STATUS_OK)
   {
	  ASSERT(0);  		
   }
}


/*
* FUNCTION
*	   bmt_adc_init
*
* DESCRIPTION                                                           
*   	This function is the charge initial function
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
/*if add more measure parameters, just need modify bmt_adc_init*/
void bmt_adc_init(void)
{
   bmt_get_adc_interface();		

#ifdef __EXT_ADC__   
	bmt_external_adc_init();
#else
	bmt_internal_adc_init();
#endif   
}


/*
* FUNCTION
*		bmt_CtrlCharge
*
* DESCRIPTION																			  
*		This function is called to control the SW of charge
*
* CALLS  
*
* PARAMETERS
*		ON: 1, charge on	  0, charge off
*	  VBAT: the measured voltage of battery.
*	
* RETURNS
*		None
*
* GLOBALS AFFECTED
*	  None
*/
void bmt_CtrlCharge(kal_uint8 ON)
{
	kal_bool chr_enable;
	kal_bool ChrCtrl;

    drv_trace1(TRACE_GROUP_1, BMT_CTRL_CHARGE_TRC, ON);

	// If bat_state is HOLD, we do NOT enable chr_en
	if ( (BMT.bat_state == CHR_HOLD) || (BMT.bat_state == CHR_ERROR) )
	{
		BMT.pmictrl_state = PMIC_CHARGEOFF;

		chr_enable = KAL_FALSE;
		bmt_charging_control_handler(BMT_CHARGING_CMD_CHARGING_ENABLE, &chr_enable);

		return;
	}

	if ((kal_bool)ON == KAL_TRUE)
	{
		if (BMT.pmictrl_state == PMIC_CHARGEOFF)
		{      
			BMT.pmictrl_state = PMIC_CHARGEON;

			// Fast plug in/out may cause HW disable current level, but SW do not receive interrupt.
			// Under such scenario the current level will incorrect.
			// Enforce set correct current level every time charge ON.
     		bmt_set_chr_current();
     
			ChrCtrl = KAL_TRUE;
			bmt_charging_control_handler(BMT_CHARGING_CMD_CHARGING_ENABLE, &ChrCtrl);
		}
		else
		{
			bmt_charging_control_handler(BMT_CHARGING_CMD_WDT_CLEAR,NULL);
   	 		drv_trace0(TRACE_GROUP_6, BMT_CHARGING_ALREADY_ON_TRC);
      	}
	}
	else
	{
		BMT.pmictrl_state = PMIC_CHARGEOFF;
		ChrCtrl = KAL_FALSE;

		bmt_charging_control_handler(BMT_CHARGING_CMD_CHARGING_ENABLE, &ChrCtrl);
	}
}


/*
* FUNCTION
*		bmt_ChrStop
*
* DESCRIPTION																			  
*		This function is called if charge is complete and run after 30 min
*
* CALLS  
*
* PARAMETERS
*		None
*	
* RETURNS
*		None
*
*/
static void bmt_ChrStop(void)  /*30 min*/
{
	DCL_STATUS adc_status;
	drv_trace0(TRACE_STATE, BMT_MEASURE_STOP_TRC);
	bmt_CtrlCharge((kal_uint8)KAL_FALSE);	//Stop Charge!!
	BMT.highfull = 1;
	
	adc_status = DclSADC_Control(bmt_adc_handle, ADC_CMD_STOP_MEASURE, NULL);
	if(adc_status != STATUS_OK)
	{
		ASSERT(0);
	}
	
	bmt_timer_config(bmt_charging_para.BATFULL_TOFF*CHARGING_TIME_UNIT);

}


static void bmt_stop_charge_timer_callback(void* msg_ptr)
{
	 drv_trace0(TRACE_GROUP_10, BMT_STOP_TIMER_EXPIRE_TRC);

	 bmt_event_scheduler_id[BMT_STOP_CHARGE_TIMER] = 0;	
	 
     bmt_ChrStop();

	 bmt_enable_sleepmode(KAL_TRUE);
}


static void bmt_top_off_timer_callback(void* msg_ptr)
{
	 drv_trace0(TRACE_GROUP_10, BMT_TOP_OFF_TIMER_EXPIRE_TRC);

	 bmt_event_scheduler_id[BMT_TOP_OFF_TIMER] = 0;	
	 
	 bmt_CtrlCharge((kal_uint8)KAL_TRUE);
	 BMT.bat_state = CHR_BATFULL;
	 bmt_stop_timer(BMT_STOP_CHARGE_TIMER);
	 bmt_stop_timer(BMT_CHARGE_TIMEOUT_TIMER);

 	 bmt_set_timer(BMT_STOP_CHARGE_TIMER,STOPTIMER_TIMEOUT_TICK);
	 bmt_sendMes2UEM(BMT_CHARGE_COMPLETE);
	 drv_trace0(TRACE_GROUP_10, BMT_CHR_BATFULL_CHANGE_TRC);

	 bmt_timer_config(bmt_charging_para.TOPOFF_TON*CHARGING_TIME_UNIT);
}



static void bmt_charging_timeout_timer_callback(void* msg_ptr)
{
	  kal_bool charging_algo_enable;

	  drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_EXPIRE_TRC, bmt_total_charge_time);

	  bmt_event_scheduler_id[BMT_CHARGE_TIMEOUT_TIMER] = 0;	

      //When BMT has guard time, it won't need safty time
      bmt_sendMes2UEM(BMT_CHARGE_TIMEOUT);
      charging_algo_enable = KAL_FALSE;
	  chr_algorithm_control_handler(BMT_CHARGING_ALGO_CMD_ENABLE, &charging_algo_enable);

	  bmt_enable_sleepmode(KAL_TRUE);
}


kal_bool bmt_PhyCheck_VCharger(BATPHYStruct *BATPHYS)
{
	static kal_uint8 over_charger_count = 0;
	static kal_uint8 low_charger_count = 0;
    char tmp[200]={0};

    //sprintf(tmp,"##@bmt_PhyCheck_VCharger %d  (%d~%d)\r\n",BATPHYS->VCHARGER,bmt_charging_para.VCHARGER_LOW,bmt_charging_para.VCHARGER_HIGH);
    //    U_PutUARTBytes(uart_port1, (kal_uint8*)tmp, strlen(tmp));
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
	if ( (BATPHYS->VCHARGER > bmt_charging_para.HIGH_VCHG_TABLE[VCHG_VOL_LEVEL - 1][0]) )
#else
	if ( (BATPHYS->VCHARGER > bmt_charging_para.VCHARGER_HIGH) )
#endif // End of #if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)   
	{
		over_charger_count ++;
		drv_trace1(TRACE_ERROR, BMT_PHY_CHECK_OVER_CHARGER_COUNT_TRC, over_charger_count);	
	}
	else
	{
		over_charger_count = 0;
	}
	
	if ( (BATPHYS->VCHARGER < bmt_charging_para.VCHARGER_LOW) )
	{
		low_charger_count++;
	}
	else
	{			
		low_charger_count = 0;
	}
	
	if ( (low_charger_count > VCHARGER_LOW_CHECK_COUNT) || (over_charger_count > VCHARGER_OVER_CHECK_COUNT) )
	{
		low_charger_count = 0;
		return KAL_FALSE;
	}
	return KAL_TRUE;
}


#ifndef __BMT_NO_ISENSE_RESISTOR__
kal_bool bmt_PhyCheck_OverCurrent(BATPHYStruct *BATPHYS)
{
	static kal_uint8 over_current_count=0;
	
	if (BMT.pmictrl_state == PMIC_CHARGEOFF)
	{
		if(BATPHYS->ICHARGE > bmt_charging_para.ICHARGE_OFF_HIGH || BATPHYS->ISense_Offset > (bmt_charging_para.ICHARGE_OFF_HIGH / 5))	// x0.2 Ohm resistor
		{
			over_current_count++;
			drv_trace1(TRACE_ERROR, BMT_PHY_CHECK_OVER_CURRENT_COUNT_TRC, over_current_count);	
		}
		else
		{				
			over_current_count = 0;	
		}
	}
	else
	{
		if(BATPHYS->ICHARGE > bmt_charging_para.ICHARGE_ON_HIGH)
		{
			over_current_count++;
			drv_trace1(TRACE_ERROR, BMT_PHY_CHECK_OVER_CURRENT_COUNT_TRC, over_current_count);	
		}
		else
		{				
			over_current_count = 0;	  
		}	
	}
	if (over_current_count > OVER_CURRENT_CHECK_COUNT)
	{
		over_current_count = 0;
		return KAL_FALSE;
		
	}
	return KAL_TRUE;
}


kal_bool bmt_PhyCheck_LowCurrent(BATPHYStruct *BATPHYS)
{
	static kal_uint8 low_current_count=0;
	if (BMT.pmictrl_state != PMIC_CHARGEOFF)
	{
		if ( (BMT.bat_state == CHR_FAST)) 
		{
			if(BATPHYS->ICHARGE < bmt_charging_para.ICHARGE_ON_LOW)
			{
				low_current_count++;
				drv_trace1(TRACE_GROUP_6, BMT_PHY_CHECK_LOW_CURRENT_COUNT_TRC, low_current_count);	
			}
			else
			{				
				low_current_count = 0;
			}
			
			if (low_current_count > LOW_CURRENT_CHECK_COUNT)
			{
				low_current_count = 0;
				return KAL_FALSE;
			}
		}
		else
		{
			low_current_count = 0;
		}
	}
	return KAL_TRUE;
}
#endif // End of #ifndef __BMT_NO_ISENSE_RESISTOR__


kal_bool bmt_PhyCheck_VBat(BATPHYStruct *BATPHYS)
{
#if defined(LINEAR_LI_CHARGING) || defined(PULSE_LI_CHARGING) 
	if(BATPHYS->VBAT > bmt_charging_para.MAX_VBAT_LI) 
	{
		return KAL_FALSE;
	}
#endif 
   
#if defined(LINEAR_NIMH_CHARGING) || defined(PULSE_NIMH_CHARGING)  
	if(BATPHYS->VBAT > bmt_charging_para.MAX_VBAT_NI) 
	{
		return KAL_FALSE;
	}
#endif    
	return KAL_TRUE;
}


kal_bool bmt_PhyCheck_LowBatTemp(BATPHYStruct *BATPHYS)
{
	static kal_uint8 low_temper_count = 0;
	
	if (BATPHYS->BATTMP <CHR_BATTMP_LOW_TEMP && BATPHYS->BATTMP > CHR_BATTMP_BAD_CONTACT)  /*battery temperature < 0C*/
	{
		low_temper_count ++;
		drv_trace1(TRACE_ERROR, BMT_PHY_CHECK_LOW_TRMPER_COUNT_TRC, low_temper_count);	
	}
	else
	{
		low_temper_count = 0;
	}
	
	if (low_temper_count > LOW_BATTEMP_CHECK_COUNT)
	{
		return KAL_FALSE;
	}
	
	return KAL_TRUE;
}


kal_bool bmt_PhyCheck_HighBatTemp(BATPHYStruct *BATPHYS)
{
	static kal_uint8 over_temper_count = 0;
	/*y=69.65-47.4x*/
	if (BATPHYS->BATTMP > CHR_BATTMP_HIGH_TEMP)	/*battery temperature > 45C*/
	{
		over_temper_count++;
		drv_trace1(TRACE_ERROR, BMT_PHY_CHECK_OVER_TEMPER_COUNT_TRC, over_temper_count);	
	}
	else
	{
		over_temper_count = 0;
	}
	
	if (over_temper_count > OVER_BATTEMP_CHECK_COUNT)
	{
		over_temper_count = 0;
		return KAL_FALSE;
	}
	
	return KAL_TRUE;
}


kal_bool bmt_PhyCheck_BadBattContact(BATPHYStruct *BATPHYS)
{
	if (BATPHYS->BATTMP < CHR_BATTMP_BAD_CONTACT)
	{
		return KAL_FALSE;
	}
	
	return KAL_TRUE;
}


kal_bool bmt_PhyCheck_ReChargeTemp(BATPHYStruct *BATPHYS)
{
	static kal_uint8 recharge_temper_count = 0;
	/*y=69.65-47.4x*/
	if (BATPHYS->BATTMP > CHR_BATTMP_RECHARGE_TEMP)	/*battery temperature > 45C*/
	{
		recharge_temper_count++;
		drv_trace1(TRACE_ERROR, BMT_PHY_CHECK_RECHARGE_TEMPER_COUNT_TRC, recharge_temper_count);	
	}
	else
	{
		recharge_temper_count = 0;
	}
	
	if (recharge_temper_count > RECHARGE_BATTEMP_CHECK_COUNT)
	{
		recharge_temper_count = 0;
		return KAL_FALSE;
	}
	
	return KAL_TRUE;
}


kal_bool bmt_PhyCheck_EnterChargeHold(BATPHYStruct *BATPHYS)
{
	if ((BMT.call_state == talk_mode) && (BATPHYS->VBAT >= bmt_charging_para.V_PROTECT_HIGH_LI))
	{
		if (BMT.pmictrl_state == PMIC_CHARGEOFF ||
			(BMT.pmictrl_state == PMIC_CHARGEON) &&
			(BMT.bat_state == CHR_TOPOFF || BMT.bat_state == CHR_BATFULL || BMT.bat_state == CHR_POSTFULL))
		{
			return KAL_TRUE;
		}
	}
	
	return KAL_FALSE;
}


kal_bool bmt_PhyCheck_DisableSafetyTimer(void)
{
	//In talking mode, the power consumption may be large and cause long time to complete charging
	if (BMT.call_state == talk_mode)
	{
		return KAL_TRUE;
	}
	
	// When in hold state, the safety timer should be disabled
	// Because we do NOT perform charging
	if (BMT.bat_state == CHR_HOLD)
	{
		return KAL_TRUE;
	}
	
	return KAL_FALSE;
}


kal_bool bmt_CHR_Is_Charge_Full(BATPHYStruct *pBATPHYS)
{
#ifndef __BMT_NO_ISENSE_RESISTOR__
	if (pBATPHYS->ICHARGE < bmt_charging_para.I_TOPOFF2FULL_THRES)
	{
		return KAL_TRUE;
	}
	else
	{
		return KAL_FALSE;
	}
#else	
	ASSERT(0); // When this function is called, we should have some operations to check charge full
	return KAL_FALSE;
#endif // #ifndef __BMT_NO_ISENSE_RESISTOR__
}


/*
* FUNCTION
*		bmt_CallState
*
* DESCRIPTION																			  
*		This function is called by MMI to nodify talk/idle state to BMT task.
*
* CALLS  
*
* PARAMETERS
*		callState: 1, talk mode.
*					 0, idel mode.
*	
* RETURNS
*		None
*
* GLOBALS AFFECTED
*	  None
*/
void bmt_CallState(kal_uint8 callState)
{
	BMT.call_state = callState;	/*Talk time=1, otherwise = 0*/
	drv_trace1(TRACE_GROUP_10, BMT_CALL_STATE_TRC, callState);
}


void bmt_set_chr_current(void)
{ 
    kal_uint32 chr_current = PMU_CHARGE_CURRENT_0_00_MA;
	CHR_DET_TYPE_ENUM chr_type;
	
	chr_type = bmt_get_chr_type();
	
	switch (chr_type)
	{
	case PW_AC_CHR:
		chr_current = CHR_AC_CHARGE_CURRENT;
		drv_trace0(TRACE_GROUP_10, BMT_SET_AC_CHARGE_CURRENT_TRC);  
		break;

	case PW_USB_CHR:
		chr_current = CHR_USB_CHARGE_CURRENT;
		drv_trace0(TRACE_GROUP_10, BMT_SET_USB_CHARGE_CURRENT_TRC);               
		break;

	case PW_AC_NON_STD_CHR:
		chr_current = CHR_NON_AC_CHARGE_CURRENT;
		break;	

	case PW_USB_CHARGING_HOST_CHR:
		chr_current = CHR_USB_CHARGING_HOST_CHARGE_CURRENT;
		break;

	default:
		ASSERT(0);
		break;
	}

#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
	if((chr_type != PW_USB_CHR) && (chr_type != PW_USB_CHARGING_HOST_CHR))	
	{
		if(First_Time_Charge_Enable == KAL_TRUE)
		{
			drv_trace0(TRACE_GROUP_9, BMT_HIGH_VCHG_FIRST_TIME_CHARGER_ON_TRC); 
			bmt_high_vchg_first_time_set();
			First_Time_Charge_Enable = KAL_FALSE;
		}

		if(chr_type  == PW_AC_NON_STD_CHR)
		{
			if(bmt_high_vchg_current > CHR_NON_AC_CHARGE_CURRENT)
			  {
				bmt_high_vchg_current = CHR_NON_AC_CHARGE_CURRENT;
				drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_SET_USB_CHARGE_CURRENT_TRC, CHR_USB_CHARGE_CURRENT);	
			}
		}
		
		drv_trace1(TRACE_GROUP_9, BMT_HIGH_VCHG_CHARGE_CURRENT_TRC, bmt_high_vchg_current); 

		chr_current = bmt_high_vchg_current;
		
		Cur_VCharge_MAX = 0;
		drv_trace0(TRACE_GROUP_9, BMT_HIGH_VCHG_MAX_RESET_TO_ZERO_TRC); 
					  
	}
	else
	{
		drv_trace0(TRACE_GROUP_9, BMT_HIGH_VCHG_USB_IN_USE_CUSTOM_CHARGE_CURRENT_TRC);	
	}
#endif

    bmt_charging_control_handler(BMT_CHARGING_CMD_SET_CHARGING_CURRENT, &chr_current);
}


kal_bool bmt_get_chr_cv_det(void)
{
	kal_bool Get_CV_Detect_Status;

	bmt_charging_control_handler(BMT_CHARGING_CMD_GET_CV_STATUS, &Get_CV_Detect_Status);
	return (kal_bool)Get_CV_Detect_Status;
}


#ifdef __DRV_BMT_HIGH_BATTERY_SUPPORT__
void bmt_set_high_battery_cv(BMT_CTRL_SET_HIGH_BATTERY_DATA *rSetHighBatteryData)
{
	bmt_high_battery_cv = (PMU_VOLTAGE_ENUM)rSetHighBatteryData->HVBat_CV_Voltage;
	bmt_high_battery_ov = (PMU_VOLTAGE_ENUM)rSetHighBatteryData->HVBat_OV_Voltage;
}
#endif


DCL_STATUS bmt_get_customized_para(BMT_CTRL_GET_CUSTOMIZED_PARA_T *GetCustomizedPara)
{
    DCL_STATUS return_status = STATUS_INVALID_CMD;
    switch (GetCustomizedPara->eGetParaCmd)
    {
        case DCL_GET_BATTERY_TYPE:
            GetCustomizedPara->u4ChargingParameter = bmt_charging_para.bmt_battery_type;
            return_status = STATUS_OK;
            break;
        case DCL_GET_CHECK_BATTERY:
            GetCustomizedPara->u4ChargingParameter = bmt_charging_para.bmt_check_battery;
            return_status = STATUS_OK;
            break;            
        case DCL_GET_CHECK_CHARGER_VOLTAGE:
            GetCustomizedPara->u4ChargingParameter = bmt_charging_para.bmt_check_charger;
            return_status = STATUS_OK;
            break;
        case DCL_GET_CHECK_BATT_TEMP:
            GetCustomizedPara->u4ChargingParameter = bmt_charging_para.bmt_check_temp;
            return_status = STATUS_OK;            
            break;
        case DCL_GET_MAX_VBAT_LI:
            return_status = STATUS_UNSUPPORTED;  
            break;
        default:
            ASSERT(0); // Unsupported Get Command
            return_status = STATUS_INVALID_CMD;   
            break;                
    }

    return return_status;
}

#endif //#if !defined(BMT_CHARGING_DISABLE)

