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
 *    chr_parameter.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is defined for charging parameters.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __CHR_PARAMETER_H__
#define __CHR_PARAMETER_H__
#include "kal_non_specific_general_types.h"
#include "dcl.h"

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// Common Part /////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
// Configuration of Battery Type
#define LI_ION_BATTERY					0
#define NI_MH_BATTERY					1
#define CHR_BATTERY_TYPE    			LI_ION_BATTERY


// Configuration of Checking
#define CHR_CHECK_BATTERY               KAL_FALSE
#define CHR_CHECK_CHARGER_VOLTAGE		KAL_TRUE
#define CHR_CHECK_BATT_TEMP				KAL_FALSE

// Configuration of Li / Ni Battery Detect
#define CHR_TYPICAL_LI_BATTYPE          1100000
#define CHR_TYPICAL_NI_BATTYPE          1100000

// Configuration of AC/USB Charge Current
#ifdef __KJX_FUN__	//xb add 2017-07-28 修改USB充电电流
#define CHR_AC_CHARGE_CURRENT           PMU_CHARGE_CURRENT_600_00_MA
#define CHR_NON_AC_CHARGE_CURRENT       PMU_CHARGE_CURRENT_600_00_MA
#define CHR_USB_CHARGE_CURRENT          PMU_CHARGE_CURRENT_600_00_MA
#define CHR_USB_CHARGING_HOST_CHARGE_CURRENT PMU_CHARGE_CURRENT_600_00_MA
#else
#define CHR_AC_CHARGE_CURRENT           PMU_CHARGE_CURRENT_650_00_MA
#define CHR_NON_AC_CHARGE_CURRENT        PMU_CHARGE_CURRENT_450_00_MA
#define CHR_USB_CHARGE_CURRENT          PMU_CHARGE_CURRENT_450_00_MA
#define CHR_USB_CHARGING_HOST_CHARGE_CURRENT PMU_CHARGE_CURRENT_450_00_MA
#endif

////////////////////////////////////////////////////////////////////
// PHY Check Threshold 										      //
////////////////////////////////////////////////////////////////////

// For Battery check, turn on by CHR_CHECK_BATTERY = KAL_TRUE
#define CHR_BATT_EXIST_ADC_THRESHOLD    4600000

// For V Charge check, turn on by CHR_CHECK_CHARGER_VOLTAGE = KAL_TRUE
#define CHR_VCHARGER_HW_HIGH            PMU_VOLT_07_000000_V
#define CHR_VCHARGER_HIGH               6500000
#define CHR_VCHARGER_LOW                0

// For Battery Temperature check, turn on by CHR_CHECK_TEMP = KAL_TRUE
#define CHR_BATTMP_HIGH_TEMP            50000 
#define CHR_BATTMP_LOW_TEMP             -10000
#define CHR_BATTMP_BAD_CONTACT          -40000 
#define CHR_BATTMP_RECHARGE_TEMP               40000

// For I Charge check
#define CHR_ICHARGE_ON_HIGH             1000000
#define CHR_ICHARGE_ON_LOW              50000
#define CHR_ICHARGE_OFF_HIGH            1000000


/* charging error check count */
#define VCHARGER_LOW_CHECK_COUNT		    6   //3		// VCHARGER low check count
#define VCHARGER_OVER_CHECK_COUNT		    6   //3		// VCHARGER high check count
#define OVER_CURRENT_CHECK_COUNT		    3		// Over current check count
#define LOW_CURRENT_CHECK_COUNT			    5  //3		// Low current check count
#define OVER_BATTEMP_CHECK_COUNT		    5  //3		// Over battery temperature check count
#define LOW_BATTEMP_CHECK_COUNT			    5   //3		// Low battery temperature check count

/* ReCharge check count */
#define RECHARGE_BATTEMP_CHECK_COUNT        3

////////////////////////////////////////////////////////////////////
// Misc Configuration										      //
////////////////////////////////////////////////////////////////////

// For current offset of different mode
#define CURRENT_OFFSET_IDLE_MODE		100000	/* unit : mA */
#define CURRENT_OFFSET_TALK_MODE		100000	/* unit : mA */
#define CURRENT_OFFSET_SWOFF_MODE		100000	/* unit : mA */


////////////////////////////////////////////////////////////////////
// State Transition Configuration								  //
////////////////////////////////////////////////////////////////////

// For state transition threshold
#define CHR_V_PRE2FAST_THRES            3400000   //3600000  /*关机电压*/
#define CHR_V_PRE2FULL_THRES            4170000   //4170000 huzheng     

// For Fast Charge State, charge duty adjustment
#define CHR_FAST_ICHARGE_HIGHLEVEL      600000  /* 600ma,for table search */
#define CHR_FAST_ICHARGE_LOWLEVEL       400000  /* 400ma,for table search */

#define CHR_I_TOPOFF2FAST_THRES         250000  /* 250ma, TOPOFF->FAST */ // No use right now
#define CHR_I_TOPOFF2FULL_THRES         120000  /* TOPOFF->BATFULL */ 

//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// Individual Part ///////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

// Start of Li-Ion Battery Configuration
/* Li-Ion Battery Configuration */
#define CHR_V_FAST2TOPOFF_THRES_LI     4050000   //4050000  huzheng
#define CHR_V_FULL2FAST_THRES_LI       4110000   //4110000 /* BATFULL->FAST */
#define CHR_MAX_VBAT_LI                 6000000
#define CHR_V_PROTECT_HIGH_LI           4050000
#define CHR_V_PROTECT_LOW_LI            3800000
// End of Li-Ion Battery Configuration

// Start of Ni-MH Battery
/* Ni-MH Battery Configuration */
#define CHR_V_TEMP_FAST2FULL_THRES_NI   414557  /* 50oC, FAST->BATFULL */
#define CHR_V_FULL2FAST_THRES_NI        4050000
#define CHR_MAX_VBAT_NI                 5500000
// End of Ni-MH Battery

////////////////////////////////////////////////////////////////////
// Charge Duty Configuration									  //
////////////////////////////////////////////////////////////////////
/* PRE CHARGE, search table */
#define PRE_TON_TIME               	    3	//120	/* unit : second */
#define PRE_TOFF_TIME              	    2	//2	/* unit : second */

// Fast Charge ON/OFF duty configuration for different charge current of Normal Mode
#define FAST_ICHARGE_HI_NORMAL_ON		7		/* unit : sec */
#define FAST_ICHARGE_HI_NORMAL_OFF		1		/* unit : sec */
#define FAST_ICHARGE_MID_NORMAL_ON		8		/* unit : sec */
#define FAST_ICHARGE_MID_NORMAL_OFF		1		/* unit : sec */
#define FAST_ICHARGE_LO_NORMAL_ON		9		/* unit : sec */
#define FAST_ICHARGE_LO_NORMAL_OFF		1		/* unit : sec */

// Fast Charge ON/OFF duty configuration for different charge current of Talk Mode
#define FAST_ICHARGE_HI_TALK_ON			7		/* unit : sec */
#define FAST_ICHARGE_HI_TALK_OFF		1		/* unit : sec */
#define FAST_ICHARGE_MID_TALK_ON		8		/* unit : sec */
#define FAST_ICHARGE_MID_TALK_OFF		1		/* unit : sec */
#define FAST_ICHARGE_LO_TALK_ON			9		/* unit : sec */
#define FAST_ICHARGE_LO_TALK_OFF		1		/* unit : sec */

/* TOPOFF CHARGE, search table */
#define TOPOFF_TON_TIME            	    3
#define TOPOFF_TOFF_TIME                3

/* Only for Pulse Charge Start */
#define PULSE_POSTFULL_TWAIT_TIME      	90
#define PULSE_POSTFULL_TON_TIME        	3
#define PULSE_POSTFULL_TOFF_TIME       	1
/* Only for Pulse Charge End */

/* Only for Li-Ion Battery Start */
#define BATFULL_TON_TIME_LI        	    6       /* unit : second */
#define BATFULL_TOFF_TIME_LI       	    0		/* unit : second */
/* Only for Li-Ion Battery End */

/* Only for Ni-MH Battery Start */
#define BATFULL_TON_TIME_NI        	    1       /* unit : second */
#define BATFULL_TOFF_TIME_NI       	    9		/* unit : second */
/* Only for Ni-MH Battery End */

/* Recharge duty */
#define RECHARGE_TOFF_TIME               3


#define CHR_STOP_TOFF_TIME        	    6
#define BATHOLD_TOFF_TIME          	    10
#define MEASURE_DISCARD_TIME            24      /* unit : ticks */

#define TOTAL_CHARGE_TIME             (60 * 60) //(8 * 60)  8 hours = 480 mins huzheng


// ============================================================ //
// High V parameter
// ============================================================ //
#define CHR_VCHARGER_HV_HIGH            PMU_VOLT_10_500000_V

#define HIGH_V_VCHG_THRESHHOLD_LEVEL_0	5250000
#define HIGH_V_VCHG_THRESHHOLD_LEVEL_1	5500000
#define HIGH_V_VCHG_THRESHHOLD_LEVEL_2	6000000
#define HIGH_V_VCHG_THRESHHOLD_LEVEL_3	6500000
#define HIGH_V_VCHG_THRESHHOLD_LEVEL_4	7500000
#define HIGH_V_VCHG_THRESHHOLD_LEVEL_5	9000000
#define HIGH_V_VCHG_THRESHHOLD_LEVEL_6	9000000

#define HIGH_V_CHARGING_CURRENT_LEVEL_0	PMU_CHARGE_CURRENT_650_00_MA
#define HIGH_V_CHARGING_CURRENT_LEVEL_1	PMU_CHARGE_CURRENT_650_00_MA
#define HIGH_V_CHARGING_CURRENT_LEVEL_2	PMU_CHARGE_CURRENT_550_00_MA
#define HIGH_V_CHARGING_CURRENT_LEVEL_3	PMU_CHARGE_CURRENT_450_00_MA
#define HIGH_V_CHARGING_CURRENT_LEVEL_4	PMU_CHARGE_CURRENT_400_00_MA
#define HIGH_V_CHARGING_CURRENT_LEVEL_5	PMU_CHARGE_CURRENT_200_00_MA
#define HIGH_V_CHARGING_CURRENT_LEVEL_6	PMU_CHARGE_CURRENT_200_00_MA

#define HIGH_V_SAFETY_TIME_LEVEL_0	600
#define HIGH_V_SAFETY_TIME_LEVEL_1	600
#define HIGH_V_SAFETY_TIME_LEVEL_2	700
#define HIGH_V_SAFETY_TIME_LEVEL_3	860
#define HIGH_V_SAFETY_TIME_LEVEL_4	1920
#define HIGH_V_SAFETY_TIME_LEVEL_5	1920
#define HIGH_V_SAFETY_TIME_LEVEL_6	1920

#endif

