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
 *   dcm.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides APIs to get device information 
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
 * removed!
 * removed!
 * removed!
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

#ifdef __MTK_TARGET__

#include "reg_base.h"
#include "config_hw.h"
#include "init.h"
#include "cp15.h"
#include "us_timer.h"
#include "drv_comm.h"
#include "emi_hw.h"
#include "emi_sw.h"
#include "dma_hw.h"
#include "drvpdn.h"
#include "dcm.h"
#include "pll.h"
#include "us_timer.h"

#include "l1_interface.h"
#if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
#include "ostd_public.h"
#endif

#include "stack_config.h"
#include "kal_trace.h"

#include "kal_public_defs.h"

#include "kal_general_types.h"
#include "kal_internal_api.h"
#include "kal_public_api.h"

#include "sst_sla.h"
#include "system_trc.h"

/*
 * NoteXXX: SaveAndSetIRQMask()/RestoreIRQMask() are APIs for appilcations to disable/restore
 *          IRQ. They will restrict the disable duration. But idle task disables IRQ for a 
 *          time due to DCM. Thus LockIRQ()/RestoreIRQ() are used here. Only the idle task
 *          can use them!! Other applications are not allowed to use LockIRQ()/RestoreIRQ().
 */
kal_uint32 LockIRQ(void);
void RestoreIRQ(kal_uint32);

extern void dormant_mode_activate(void);
extern kal_bool OSTD_Allow_Dormant_Mode(void);
#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"

#if defined(MT6238) || defined(MT6239) || defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6268A) || defined(MT6236) || defined(MT6236B) || defined(MT6276) || defined(MT6256) || defined(MT6573)  || defined(MT6575) || defined(MT6255)
volatile static kal_uint32 WFI_Handle_Count =0;
#endif

#if defined (MT6255)
/** 
 * sw_secversion =SW_SEC_0, sw_dcm with workaround of WHQA_00009504.
 * sw_secversion =SW_SEC_1, sw_dcm pure.
 * sw_secversion =SW_SEC_2, hw_dcm.
 **/
SW_SECVERSION sw_secversion = SW_SEC_0;
#if defined (__DCM_AUTO_MODE__)
#define MT6255_HWDCM_MODE(_version) (SW_SEC_2 <= _version)
#define MT6255_PATCH_WHQA_9504(_version) (SW_SEC_0 == _version)
#else //#if !defined (__DCM_AUTO_MODE__)
#define MT6255_HWDCM_MODE(_version) (KAL_TRUE)
#define MT6255_PATCH_WHQA_9504(_version) (SW_SEC_0 == _version)
#endif //#if !defined (__DCM_AUTO_MODE__)
#endif //#if defined (MT6255)


#if defined(MT6260_S00)
/**
 * 1. E1 has a defect where protect ready can go through a buffer that lack of power connection 
 * 2. EMI DCM has a too-long recovery time due to requirement of 2 EMI SLOW clock to synch up ARM-to-EMI idle signal.
 **/
#define MT6260_CONDE_GOLDEN_CONF (0x2b1 & ~MT6260_CONDE_EMI_DCM_MASK)
#else //#if defined(MT6260_S00)
#define MT6260_CONDE_GOLDEN_CONF (0x2b5 & ~MT6260_CONDE_EMI_DCM_MASK)
#endif //#if defined(MT6260_S00) 


volatile static kal_bool OST_ReadyToSlept = KAL_FALSE;
volatile static kal_bool OST_AllowedToPowerDown = KAL_FALSE;
#if defined(__MCU_DORMANT_MODE__)
__align(8) volatile kal_uint32 dormant_mode_storage[256];
#endif /* __MCU_DORMANT_MODE__ */

volatile static kal_bool pll_save_mode_enabled = KAL_FALSE;
#if !defined(MT6276_S00) && defined(MT6276) /* for MT6276E2 MP3 jitter issue workaround */
volatile static kal_bool dcm_enter_sleep_mode = KAL_FALSE;
volatile static kal_uint32 dcm_top_sm_peri_mask = 0;
volatile static kal_uint32 sleep_top_sm_peri_mask = 0;
volatile static kal_uint32 dcm_enter_sleep_frc = 0;
volatile static kal_uint32 dcm_leave_sleep_frc = 0;

volatile static kal_uint32 dcm_enter_32k_cnt = 0;
volatile static kal_uint32 dcm_check_32k_cnt = 0;
volatile static kal_uint32 dcm_dbg_dummy_read_peri_mask = 0;
volatile static kal_uint32 dcm_check_NIRQ_peri_mask = 0;
volatile static kal_uint32 dcm_check_sleep_peri_mask = 0;
volatile static kal_uint32 dcm_enable_check_peri_mask = 0;

volatile static kal_bool   dcm_mp3_workaround = KAL_FALSE;
volatile static kal_uint32 dcm_SYSCLK_Force_On_count = 0;

#endif /* MT6276_S00 */

#pragma arm section rwdata , rodata , zidata

#if defined(__MCU_DORMANT_MODE__)
/*
 * Following variables are expected to locate on EMI space.
 */
#pragma arm section rwdata = "NONCACHEDRW", zidata = "NONCACHEDZI"
/* variable to keep information of dormant mode entry and exit procedure */
volatile kal_uint32 dormant_restore_begin;
volatile kal_uint32 dormant_tcm_restore_begin;
volatile kal_uint32 dormant_tcm_storage[16];
volatile kal_uint32 dormant_dma0_status;
volatile kal_uint32 dormant_dma1_status;
volatile kal_uint32 dormant_ctrl_backup;
volatile kal_uint32 dormant_coproc_acc_ctrl;
#pragma arm section rwdata, zidata

volatile kal_uint32 dormant_dummy_wb_variable;

/* variable to keep chip dependent register definition. */
#if defined(MT6575)
const kal_uint32 dormant_status_reg = (kal_uint32)DCM_RM_PWR_STA;
const kal_uint32 dormant_power_ack_mask = DCM_RM_PWR_STA_ARM_PWR_ACK;
#endif /* MT6575 */

#endif /* __MCU_DORMANT_MODE__ */

#if defined( DCM_ENABLE )

kal_uint32 SaveAndSetIRQMask(void);
void RestoreIRQMask(kal_uint32);

//#pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"
#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#if defined (MT6252)
volatile static kal_bool dcm_cached_slept_flag = KAL_FALSE; // 
volatile static kal_bool dcm_cached_rf_sleep = KAL_FALSE; // 
kal_bool sm_rf_sleep(void);
#endif //#if defined (MT6252)
volatile static kal_uint32 dcm_state = 0;
volatile static kal_bool dcm_excuted = KAL_FALSE;

#if defined(DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT)
volatile static kal_bool dcm_lpaudio_mode = KAL_FALSE;        /* Added for LP AUDIO */
volatile static kal_uint32 dcm_lpaudio_cnt = 0;
#endif /* DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT */

#if defined(__MTK_INTERNAL__)
/* under construction !*/
#if defined(__USE_HW_DCM_CYCLE_COUNTER__)
/* under construction !*/
#endif
#endif //__MTK_INTERNAL__

 /* dcm_state = 0, 104/52 MHz.
                1, 104/52->13/26 MHz transition.
                2, 13/26 Mhz.
                3, 13/26->104/52 MHz transition. */
static struct 
{
   kal_uint32   dcmForceDisalbe;
   kal_uint8   	dcmHandleCount;
   kal_uint32   dcmDisable;					/* Default not disable DCM */
   
   /* mtk01940: for MT6227, use this flag to distinguish dedi or idle mode */   
   #if defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6226D) || defined(MT6227D) || defined(MT6226DS) || defined(MT6227DS)  || defined(MT6228) 
   kal_bool     isIdleMode;         
   kal_bool     force26MHz;       
   #endif //MT6226 || MT6227 || MT6226M || MT6226D || MT6226DS || MT6227DS || MT6228
   
   #if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
   kal_bool OST_ReadyToSlept;
   Sleep_Time allow_sleep_dur;
   #endif
} dcm = { 0, 0, 0 }; 
 
extern int custom_DynamicClockSwitch(mcu_clock_enum clock);
extern int custom_SFIDynamicClockSwitch_Init(void);
extern int custom_EMIDynamicClockSwitch_Init(void);

extern ECO_VERSION INT_ecoVersion(void);

#pragma arm section rwdata , rodata , zidata

#if defined(MT6238) || defined(MT6239) || defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6268A) || defined(MT6236) || defined(MT6236B) || defined(MT6276) || defined(MT6256) || defined(MT6573) || defined(MT6255)
void WFI_Disable( void )
{
   kal_uint32 _savedMask;
   _savedMask = SaveAndSetIRQMask();
   WFI_Handle_Count++;
   RestoreIRQMask(_savedMask);
}

void WFI_Enable( void )
{
   kal_uint32 _savedMask;
   _savedMask = SaveAndSetIRQMask();
   if( WFI_Handle_Count > 0 )
       WFI_Handle_Count--;
   RestoreIRQMask(_savedMask);
}

#else

void WFI_Disable( void )
{
    /* do nothing */
}

void WFI_Enable( void )
{
    /* do nothing */
}

#endif

#if !defined(MT6276_S00) && defined(MT6276)

void TOP_SM_Focre_SYSCLK_ON( kal_bool sysclk_on )
{
    kal_uint32 _irqMask;

    if(sysclk_on)
    {
        _irqMask = SaveAndSetIRQMask();
        dcm_SYSCLK_Force_On_count++;
        RestoreIRQMask(_irqMask);
    }
    else
    {
        _irqMask = SaveAndSetIRQMask();
        if(dcm_SYSCLK_Force_On_count > 0)
        {
            dcm_SYSCLK_Force_On_count--;
        }
        RestoreIRQMask(_irqMask);
    }
}

#else /* !MT6276_S00 && MT6276 */

void TOP_SM_Focre_SYSCLK_ON( kal_bool sysclk_on )
{
}

#endif /* !MT6276_S00 && MT6276 */

kal_bool DCM_Query_Status(void)
{
   kal_bool status = dcm_excuted;
   dcm_excuted = KAL_FALSE;/* Restored to default state */
   return status;
} 
kal_uint8 DCM_GetHandle( void )
{	
   ASSERT(dcm.dcmHandleCount<32);
   return dcm.dcmHandleCount++;   /* Using handle number from 0, not 1 */
}
void DCM_Enable( kal_uint8 handle )
{   
   kal_uint32 _savedMask;
   
   _savedMask = SaveAndSetIRQMask();
   dcm.dcmDisable &= ~(1 << handle);   
   #if defined(__HW_DCM__)
   if(0 == dcm.dcmDisable)
   {
       #if defined(MT6256) || defined(MT6255)
       *DCM_MCUSYS_PDN_CLR1 = 0x8000;
       #elif defined(MT6575)
       *DCM_RG_CK_DCM_EN |= 0xF; // MDMCU, bus, DCM enable
       #elif defined(MT6250)
       *PLL_CLK_CONDE = (*PLL_CLK_CONDE & (1<<10)) | 0x02B5;
       #elif defined (MT6260)
       *PLL_CLK_CONDE = (*PLL_CLK_CONDE & ((3<<14) | (1<<10))) | MT6260_CONDE_GOLDEN_CONF;  //reserve bit 14, 15, 10, that is not DCM switch.
       #endif
   }
   #else 
   #if defined (MT6255)
   if (MT6255_HWDCM_MODE(sw_secversion)) {
       if(0 == dcm.dcmDisable) {
           *DCM_MCUSYS_PDN_CLR1 = 0x8000;
       }
   }
   #endif //#if defined (MT6255)
   #endif //#if defined(__HW_DCM__) 
   RestoreIRQMask(_savedMask);
}
void DCM_Disable( kal_uint8 handle )
{
   kal_uint32 _savedMask;
   
   _savedMask = SaveAndSetIRQMask();
   dcm.dcmDisable |= (1 << handle);
   #if defined(__HW_DCM__)
   #if defined(MT6256) || defined(MT6255)
   *DCM_MCUSYS_PDN_SET1 = 0x8000;
   APB_CONFIG_DUMMY_READ();
   #elif defined(MT6575)
   *DCM_RG_CK_DCM_EN &= ~(0xF); // MDMCU, bus, DCM disable
   #elif defined(MT6250)
   /**
    * 1. originally to disable bus DCM(0x70) only and bit[2,7,9] for SWLA.
    * 2. however finally, decide to set all DCM off.
    * 3. reserver bit10 for SFI owner.
    **/
   *PLL_CLK_CONDE = (*PLL_CLK_CONDE & (1<<10));  
   #elif defined (MT6260)
   *PLL_CLK_CONDE = (*PLL_CLK_CONDE & ((3<<14) | (1<<10)));  
   #endif

   #else //#if defined(__HW_DCM__)
   #if defined (MT6255)
   if (MT6255_HWDCM_MODE(sw_secversion)) {
       *DCM_MCUSYS_PDN_SET1 = 0x8000;
       APB_CONFIG_DUMMY_READ();
   }
   #endif //#if defined (MT6255)
   #endif //#if defined (__HW_DCM__)
   RestoreIRQMask(_savedMask);
}

/* mtk01940: for MT6227, to distinguish from dedi or idle */
#if defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6226D) || defined(MT6227D) || defined(MT6226DS) || defined(MT6227DS)  || defined(MT6228) 
void DCM_IsIdleMode(kal_bool isCurMode)
{
	dcm.isIdleMode = isCurMode;
}

/* mtk01940: For MT6226,27,28, DCM change to 13MHz when idle but 26MHz when dedicated. */
/*           However, when polling response case, MS may possibly tx in idle mode and cause fail */
/*           TC42.4.6.1 is the case decribed here */
void DCM_ForceDCM26MHz(kal_bool isDCM26MHz)
{
	dcm.force26MHz = isDCM26MHz;
}
#endif //MT6226 || MT6227 || MT6226M || MT6226D || MT6226DS || MT6227DS || MT6228
 
#if defined(__MTK_INTERNAL__)
/* under construction !*/
#if defined(__HW_DCM__)
#if defined(__USE_HW_DCM_CYCLE_COUNTER__)
/* under construction !*/
#if defined (MT6250)
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
#elif defined(MT6256) || defined(MT6255)
#if !defined(MT6256_S00)
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
#else /* MT6256_S00 */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // #if !defined(MT6256_S00)
/* under construction !*/
#else // #if defined(MT6250)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //#if defined (MT6250)
#endif /* __USE_HW_DCM_CYCLE_COUNTER__ */
/* under construction !*/
#else // #if defined (__HW_DCM__)
#endif //#if defined(__HW_DCM__)
/* under construction !*/
/* under construction !*/
#if defined (MT6250)
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
#elif defined (MT6255) && !defined (__HW_DCM__)
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
#else //#if defined (MT6250)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if defined(__HW_DCM__)
    #if defined(__USE_HW_DCM_CYCLE_COUNTER__)
/* under construction !*/
    #endif /* __USE_HW_DCM_CYCLE_COUNTER__ */
/* under construction !*/
    #endif /* __HW_DCM__ */
/* under construction !*/
    #if defined(__HW_DCM__)
    #if defined(__USE_HW_DCM_CYCLE_COUNTER__)
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
    #endif /* __USE_HW_DCM_CYCLE_COUNTER__ */
/* under construction !*/
    #else  // #if defined (__HW_DCM__)
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
    #endif /* __HW_DCM__ */
/* under construction !*/
/* under construction !*/
    #if defined(DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT)
/* under construction !*/
    #endif
/* under construction !*/
#endif //#if defined (MT6250)
/* under construction !*/
#endif //__MTK_INTERNAL__          		  


//#pragma arm section code = "INTERNCODE"
#pragma arm section code = "INTSRAM_ROCODE"
 
void DCM_Recovery(void)
{  
#if !defined(__HW_DCM__)
   /* UnGateDG */
   #if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238) || defined(MT6239)
   extern kal_uint32 GateDG(void);
   extern void UngateDG(kal_uint32);
   /* MT6235 doesn't use L2 cache, only use MT6238_SER */
   /* Gate GMC DMA */
   volatile kal_uint16 i=0;  
   kal_uint32 tmp;
   #endif //MT6228 || MT6229 || MT6230 || MT6238 || MT6239
      
   if( dcm_state == 2 ) 
   {
      /* mtk01940 
           ======================================
	                        Idle      Dedi
	         MT6217         13MHz     x
	         MT6227         13MHZ     26MHz
	         MT6223         13MHz     13MHz
	         MT6225         13MHz     13MHz
	         MT6228         13MHz     x
	         MT6229         26MHz     26MHz
	         MT6235         13MHz     13MHz
	         MT6238         13MHz     13MHz
	         MT6516         13MHz     13MHz
           ======================================
      */      
      #if defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6226D) || defined(MT6227D) || defined(MT6226DS) || defined(MT6227DS)  || defined(MT6228) 
        #if defined(MT6227D)
          ASSERT( *MCUCLK_CON == 0x0000 ); //13MHz
        #else
          if(dcm.isIdleMode && !(dcm.force26MHz))
          {
             ASSERT( *MCUCLK_CON == 0x0000 ); //13MHz
          }
          else
          {
             #if defined(MT6228)
             ASSERT( *MCUCLK_CON ); //26MHz for MT6228
             #else
             ASSERT( *MCUCLK_CON ); //26MHz for MT6227
             #endif
          }        
        #endif
      #elif defined(MT6229) || defined(MT6230)
          ASSERT( *MCUCLK_CON == 0x0101 ); //26MHz
	  #elif defined(MT6235) || defined(MT6235B) ||defined(MT6238) || defined(MT6239)
 
        /* Because E1 and E2 are co-existed on MT6235 and MT6238, we need to split them */
	    #if defined(MT6238) || defined(MT6239)
           if(INT_ecoVersion()== ENG_E1)
           {
           	 ASSERT( *MCUCLK_CON == 0x7000 ); // EMI 104MHz
           }
           else	
           {
              ASSERT( *MCUCLK_CON == 0x0000 ); // EMI 13MHz, MCU 13MHz
           }
        #elif defined(MT6235) || defined(MT6235B)
           if(INT_ecoVersion()== ECO_E1)
           {
                ASSERT( *MCUCLK_CON == 0x7000 ); // EMI 104MHz, MCU 13MHz
           }
           else
           {
           	    ASSERT( *MCUCLK_CON == 0x0000 ); // EMI 13MHz, MCU 13MHz
           	    /* mtk01940: note that this part shall be removed when E1 code is phased out */
           }
        #else
           ASSERT( *MCUCLK_CON == 0x0000 ); // EMI 13MHz, MCU 13MHz
        #endif
                   
      #elif defined(MT6516)
          ASSERT((((*MCUCLK_CON) & 0xFFEF) == 0x0000) ); // EMI 13MHz, MCU 13MHz                     
      #elif defined(MT6253) || defined(MT6253T) || defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
	      ASSERT( (*MCUCLK_CON & 0x0F7F) == 0x0000 ); // EMI 13MHz, MCU 13MHz                                          
      #elif defined(MT6268)
          ASSERT( *MCUCLK_CON == 0x0421 ); //15.36MHz
      #elif defined(MT6268A)
          ASSERT( *MCUCLK_CON == 0x0C63 ); //30.72MHz
      #elif defined(MT6256)
        #if defined(MT6256_S00)
          ASSERT( (*DCM_PLL_CON6 & 0x3000) == 0x3000 );
        #else /* !MT6256_S00 */
          ASSERT( (*DCM_PLL_CON6 & 0x0C00) == 0x0C00 );
        #endif /* MT6256_S00 */
      #elif defined(MT6255)
          /*do nothing*/
      #elif defined(MT6251)
	      ASSERT( (*DCM_PLL_CON6 & 0x3000) == 0x3000 );
      #else
          ASSERT( *MCUCLK_CON == 0x0000 ); //13MHz
      #endif //defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6226D) || defined(MT6227D) || defined(MT6226DS) || defined(MT6227DS)  || defined(MT6228) 
      /* mtk01940 */

      dcm_state = 3; /* DCM @ 13/26->104/52MHz */
      
      #if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238) || defined(MT6239)
        /* MT6235/MT6268 doesn't use L2 cache, only use MT6238_SER */
       	/* Gate GMC DMA */
        tmp = GateDG();
         for (i = 0; i < 20; i++)
             ;
      #endif
                            
      /* I_Bit is disabled and Wait until EMI access is complete.
         Otherwise, some external(Burst/Async/Sync RAM), some will get problems. */
      #if !(defined(MT6516) || defined(TK6516))
      EMI_Dummy_Read();
      #endif
      /*A26=1 means will not get data via data cache, it will access EMI directly.*/
   
      /* Change WS and clock rate. */
      #if defined(MT6253) || defined(MT6253T)
	     if(*HW_CODE == 0x6251)
	        custom_DynamicClockSwitch( MCU_52MHZ );
	     else if(*HW_CODE == 0x6253)
	        custom_DynamicClockSwitch( MCU_104MHZ);
	     else
	        ASSERT( 0 );
      #elif defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
	     custom_DynamicClockSwitch( MCU_104MHZ );
      #elif defined(MT6228)|| defined(MT6229) || defined(MT6230) || defined(MT6225) || defined(TK6516) || defined(MT6516)
         custom_DynamicClockSwitch( MCU_104MHZ );
      #elif defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6226D) || defined(MT6227D) || defined(MT6226DS) || defined(MT6227DS)|| defined(MT6223) || defined(MT6223P)
         custom_DynamicClockSwitch( MCU_52MHZ );
      #elif defined(MT6238) || defined(MT6239)||defined(MT6235) || defined(MT6235B)
         custom_DynamicClockSwitch( MCU_208MHZ );
      #elif defined(MT6268) || defined(MT6268A)
         custom_DynamicClockSwitch( MCU_245_76MHZ );
      #elif defined(MT6236) || defined(MT6236B)
         custom_DynamicClockSwitch( MCU_312MHZ );
      #elif defined(MT6256)
         custom_DynamicClockSwitch(MCU_520MHZ);
      #elif defined(MT6251)
         custom_DynamicClockSwitch( MCU_78MHZ );
      #elif defined(MT6255)
         if (!MT6255_HWDCM_MODE(sw_secversion)) {
			custom_DynamicClockSwitch( MCU_416MHZ );
         }
         else {
             if (MT6255_PATCH_WHQA_9504(sw_secversion))
             {
                 register unsigned short sleep_con_save;
                 sleep_con_save = *SLEEP_CON;
                 sleep_con_save &= ~0x26;   //~(PDN_AHBEMI_CONFIG | PDN_AHB_CONFIG | PDN_AHB_FORCE)
                 *SLEEP_CON = sleep_con_save;
                 sleep_con_save = *SLEEP_CON;
                 if (sleep_con_save & 0x26)   
                     ASSERT(0);
             }
         }
      #endif
      
      #if defined(DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT)
        /* If we use SWDCM for Low Power Audio mode, we need to enable H/W DCM back */
      if(dcm_lpaudio_mode)
      {
          dcm_lpaudio_mode = KAL_FALSE;
      }
      #endif /* DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT */
      
      #if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238) || defined(MT6239)
         /* MT6235/MT6268 doesn't use L2 cache, only use MT6238_SER */  
         /* Recover GMC DMA gating */
         UngateDG(tmp);
      #endif
      
      dcm_state = 0; /* DCM @ 104/52MHz */
      dcm_excuted = KAL_TRUE;/* Record the execution of DCM and print in L1SM_FrameTick */
   }
#else

   if(dcm_state == 2)
   {
       dcm_state = 3;

       #if defined (MT6255) 
       //WHQA_00009504: disable SLEEP_CON[1,2,5] 
       if (MT6255_PATCH_WHQA_9504(sw_secversion))
       {
           register unsigned short sleep_con_save;
           sleep_con_save = *SLEEP_CON;
           sleep_con_save &= ~0x26;   //(PDN_AHBEMI_CONFIG | PDN_AHB_CONFIG | PDN_AHB_FORCE)
           *SLEEP_CON = sleep_con_save;
           sleep_con_save = *SLEEP_CON;
           if (sleep_con_save & 0x26)   
               ASSERT(0);
       }
       #endif /* defined (MT6255) */

       #if defined(MT6256)
       #if !defined(MT6256_S00)
       #if defined(__ENABLE_EMI_DCM_AT_IDLE__)
       *SLEEP_CON &= ~(0x20);         //Disable AHB to EMI idle detect
       #endif /* __ENABLE_EMI_DCM_AT_IDLE__ */
       #endif /* MT6256_S00 */
       #endif /* MT6256 */

       #if defined(DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT)
         /* If we use SWDCM for Low Power Audio mode, we need to enable H/W DCM back */
       if(dcm_lpaudio_mode)
       {
            /*
             * Clear the Low Power Audio flag as we're going back to normal mode
             */
            #if defined(MT6256)
            #if !defined(MT6256_S00)
            custom_DynamicClockSwitch(MCU_520MHZ);
            #endif /* MT6256_S00 */
            #endif /* MT6256 */
            
            dcm_lpaudio_mode = KAL_FALSE;
            
            /*
             * Enable HWDCM
             */
            #if defined(MT6256)
            #if !defined(MT6256_S00)
            *DCM_PLL_CON1 |= 0x4000; 
            #endif /* MT6256_S00 */
            #endif /* MT6256 */
       }

       #else /* !DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT */

       /* Work around for MT6276E1, DCM_IRQ_CLR_EN can not be set */
       #if defined(MT6276)

       #if defined(MT6276_S00)
       *DCM_RG_CK_DCM_EN1 = 0x0;
       #else /* MT6276_S01 or latter */
       *DCM_RG_CK_DCM_EN1 &= ~(0x000B);/* clear bus, EMI and MCU DCM enable bits */
       #endif /* MT6276_S00 */

       #elif defined(MT6573)

       #ifndef __SMART_PHONE_MODEM__
       *DCM_RG_CK_DCM_EN &= ~(0x3);
       #endif /* __SMART_PHONE_MODEM__ */

       *DCM_MDARM_DCM_EN &= ~(0x3);
       *DCM_MDARM_CCTL |= ~(0xFFFFFEFF);

       #endif /* MT6276*/

       #endif  /* DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT */

       dcm_state = 0;
       dcm_excuted = KAL_TRUE;/* Record the execution of DCM and print in L1SM_FrameTick */
   }
#endif //!_HW_DCM__   
}

#if defined(__MEUT__)

void Enter_DCM_mode(void)
{
    kal_uint32 _savedMask;

    #if defined(MT6256) && !defined(MT6256_S01)
    *DCM_PLL_CON1 |= 0x4000;    //Enable HWDCM
    APB_PLL_DUMMY_READ();
    #elif defined(MT6255) 
    if (MT6255_HWDCM_MODE(sw_secversion)) {
        *DCM_PLL_CON1 |= 0x4000;    //Enable HWDCM
        APB_PLL_DUMMY_READ();
    }
    else {
        kal_uint32 _savedMask;
        _savedMask = LockIRQ();
	    custom_DynamicClockSwitch( MCU_416MHZ );
        RestoreIRQ(_savedMask);
    }

    #elif defined(MT6250)
    #if defined (__HW_DCM__)
    //start DCM 
    _savedMask = LockIRQ();
    *PLL_CLK_CONDE = (*PLL_CLK_CONDE & (1<<10)) | 0x02B5;
    RestoreIRQ(_savedMask);
    #endif //#if defined (__HW_DCM__)

    #elif defined (MT6260)
    #if defined (__HW_DCM__)
    //start DCM 
    _savedMask = LockIRQ();
    *PLL_CLK_CONDE = (*PLL_CLK_CONDE & ((3<<14) | (1<<10))) | MT6260_CONDE_GOLDEN_CONF;  //reserve bit 14, 15, 10, that is not DCM switch.
    RestoreIRQ(_savedMask);
    #endif //#if defined (__HW_DCM__)

    #elif defined(MT6575)
    *DCM_RG_CK_DCM_EN = 0xF; // MDMCU, bus, DCM enable
    *DCM_RG_CK_DCM_DSP_EN = 0xF; //DSP, bus, DCM enable
    #endif
}

void Leave_DCM_mode(void)
{
    kal_uint32 _savedMask;

    #if defined(MT6256) && !defined(MT6256_S01)
    *DCM_PLL_CON1 &= ~(0x4000);    //Disable HWDCM
    APB_PLL_DUMMY_READ();
    #elif defined(MT6255)
    if (MT6255_HWDCM_MODE(sw_secversion)) {
        *DCM_PLL_CON1 &= ~(0x4000);    //Disable HWDCM    
        APB_PLL_DUMMY_READ();
    }
    else {
        _savedMask = LockIRQ();
	    custom_DynamicClockSwitch( MCU_26MHZ );
        RestoreIRQ(_savedMask);
    }

    #elif defined (MT6250) || defined (MT6260)
    _savedMask = LockIRQ();
    *PLL_CLK_CONDE = (*PLL_CLK_CONDE & ((3<<14) | (1<<10)));
    RestoreIRQ(_savedMask);

    #elif defined(MT6575)
    *DCM_RG_CK_DCM_EN = 0x0; // MDMCU, bus, DCM disable
    *DCM_RG_CK_DCM_DSP_EN = 0x0; //DSP, bus, DCM disable
    #endif
}
#endif /* __MEUT__ */

#pragma arm section code

#else /* DCM_ENABLE */

kal_bool DCM_Query_Status(void) 
{
	return KAL_FALSE;
}
kal_uint8 DCM_GetHandle( void ) 
{
	return 0;
}
void DCM_Enable( kal_uint8 handle ) {}
void DCM_Disable( kal_uint8 handle ) {}

#if defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6226D) || defined(MT6227D) || defined(MT6226DS) || defined(MT6227DS)  || defined(MT6228) 
void DCM_IsIdleMode(kal_bool isCurMode) {}
void DCM_ForceDCM26MHz(kal_bool isDCM26MHz) {}
#endif //MT6226 || MT6227 || MT6226M || MT6226D || MT6226DS || MT6227DS || MT6228

#endif /* DCM_ENABLE */


void DCM_Init( void )
{
    kal_uint32 _savedMask;

    #if defined( DCM_ENABLE )

    #if defined(__COMBO_MEMORY_SUPPORT__)
    custom_EMIDynamicClockSwitch_Init();
    #endif /* __COMBO_MEMORY_SUPPORT__ */
    #if defined(__SERIAL_FLASH_EN__)
    custom_SFIDynamicClockSwitch_Init();
    #endif /* __SERIAL_FLASH_EN__ */

    #if defined(MT6276)

    #if !defined(MT6276_S00) /* MT6276_S01 or latter */
    /* enable HW power saving mode */
    *DCM_HW_MISC0 = 0x387;
    /* MP3 jitter issue workaround */
    *DCM_RM_PERI_CON &= ~(DCM_2G_PERI_MASK|DCM_3G_PERI_MASK); /* clear 2G and 3G mask bit */
    #endif

    *DCM_RG_CK_ALW_ON = 0x0000;
    *DCM_BUS_GATED_EN = 0x01FF;

    /* idle frequency setting */
    *EMI_IDLE_FSEL = EMI_DCM_FREQ;
    *FBUS_IDLE_FSEL = 0x1;
    *SBUS_IDLE_FSEL = 0x1;

    #elif defined(MT6255)
    sw_secversion = INT_SW_SecVersion();
    *DCM_PLL_CON2 &= (0xf);      // normal mode clock rate is set to the highest speed (and excluding of SFC control setting).
    *DCM_PLL_CON4 = 0x0;      // normal mode clock rate is set to the highest speed

    if (!MT6255_HWDCM_MODE(sw_secversion)) { // DCM clock CKS is not toggled to normal mode to avoid HW bug, that DCM CKS transiction check logic is fail randomly.
	    *DCM_PLL_CON5 = 0x0;   
	    *DCM_PLL_CON3 = 0x0;   //EMI2x (325/16)MHz, in DCM mode, MCU clock is gated.	
    }
    else {
        /** Slow idle mode clock dcm, BUS_CK=26M  MCU_CK=104M, 
         * SFCPLLCLK/5 (only apply to SFCPLLCLK. If SFC with bus_clk, this DCM divider is bypassed.)
         **/
        *DCM_PLL_CON5 = 0x0553;   
        *DCM_PLL_CON3 = 0x7000;   //EMI2x (325/16)MHz, in DCM mode, MCU clock is gated.    
        *DCM_PLL_CON7 = 0x8F0F;  //   clkswprd enable, 15T deglitch
        *DCM_PLL_CON6 |= 0x0D00;  //   EMI and BUS idle_det_en, SFC_IDLE_DET_EN
        *DCM_PLL_CON6 &= ~0x0020; //

        ///AST, SLEEP_CON[1,2,5] can not activate until WFI to avoid WHQA_00009504
        if (!MT6255_PATCH_WHQA_9504(sw_secversion)) {
            /* /// enable SLEEP_CON */
            *SLEEP_CON |= 0x24;     //Enable AHB clock gated force  //Enable AHB to EMI idle detect
        }
    }

    *DCM_MCUCLK_CON &= ~0x01;  //not arm_clock_always_on
    *DCM_PLL_CON9 = (0x03<<4); //only DSP SWDCM detection on, others HWDCM detection

    /*
     * Clear SW flag so DCM won't be blocked
     */
    *DCM_MCUSYS_PDN_CLR1 = 0x8000;

    *DCM_MCUSYS_DCM_EN0 = 0x4602;
    *DCM_MCUSYS_DCM_EN1 = 0x0210;
    *DCM_MCUSYS_DCM_EN2 = 0x0B00;
    *DCM_MD2G_DCM_EN = 0x0;
    *DCM_MM_DCM_EN = 0xFFFFFFFF;

    #if !defined(__MEUT__) 
    if (MT6255_HWDCM_MODE(sw_secversion))
        *DCM_PLL_CON1 |= 0x4000;    //Enable HWDCM
    #endif //__MEUT__
    APB_PLL_DUMMY_READ();

    #elif defined(MT6256) 

    #if defined(MT6256_S00)

    *DCM_PLL_CON1 &= ~0xC000; //SWDCM mode: clear HWDIV_MODE & HWDCM_MODE
    *DCM_PLL_CON3 = 0x4004;   //EMI2x (325/16)MHz, AHB 13MHz, APB bus 13MHz (UART limitation) in DCM mode, MCU clock is gated.    
	  *DCM_PLL_CON5 = 0x0300; 
    *DCM_PLL_CON6 |= 0xC000;  //set SW_DIV mode 
    *DCM_MCUCLK_CON &= ~0x01;

    APB_CONFIG_DUMMY_READ();
    #else /* !MT6256_S00 */

    /*
     * Enable ARM system clock gating as it's required for HWDCM
     */
    *DCM_ARMSYS_SYNC_CON |= 0x0E00;

    *DCM_PLL_CON2 = 0x0;      // normal mode clock rate is set to the highest speed
    *DCM_PLL_CON3 = 0x4000;   //EMI2x (325/16)MHz, in DCM mode, MCU clock is gated.    
    *DCM_PLL_CON4 = 0x0;      // normal mode clock rate is set to the highest speed
    *DCM_PLL_CON5 = 0x0204;   //Slow idle mode clock dcm, BUS_CK=26M  MCU_CK=104M
    *DCM_PLL_CON7 |= 0x8F0F;  //   clkswprd enable, 15T deglitch
    *DCM_PLL_CON6 |= 0x0C00;  //   EMI and BUS idle_det_en
    *DCM_PLL_CON9 |= 0x33;    //Force DSP and G3D to enter DCM mode
    *DCM_MCUCLK_CON &= ~0x01;
    
    /*
     * Setup the DCM check condition
     */
    *DCM_MCUSYS_DCM_EN0 = 0x4602;
    *DCM_MCUSYS_DCM_EN1 = 0x0210;
    *DCM_MCUSYS_DCM_EN2 = 0x0F00;
    *DCM_MD2G_DCM_EN = 0x0;
    *DCM_MM_DCM_EN = 0xFFFFFFFF;
    
    /*
     * Enable AHB clock gated and AHB to EMI idle detect
     */
    *SLEEP_CON |= 0x04;     //Enable AHB clock gated
    #if defined(__ENABLE_EMI_DCM_AT_IDLE__)
    *SLEEP_CON &= ~(0x20);  //Disable AHB to EMI idle detect
    #else
    *SLEEP_CON |= 0x20;     //Enable AHB to EMI idle detect
    #endif /* __ENABLE_EMI_DCM_AT_IDLE__ */
    
    /*
     * Clear SW flag so DCM won't be blocked
     */
    *DCM_MCUSYS_PDN_CLR1 = 0x8000;
    
    #if !defined(__MEUT__)
    /*
     * Enable HWDCM
     */
    *DCM_PLL_CON1 |= 0x4000;    //Enable HWDCM
    #endif /* __MEUT__ */

    APB_PLL_DUMMY_READ();

    #endif /* MT6256_S00 */

    #elif defined(MT6251)

    *DCM_PLL_CON3 &= 0x00F0; //DIV = 0;
    *DCM_PLL_CON5 = 0x0070;  //DCM to 13MHz except for DSP;
    *DCM_PLL_CON6 = 0xC000;  //SW DCM mode 
	
    #elif defined(MT6573)
    
    #ifndef __SMART_PHONE_MODEM__
    *DCM_RG_CK_ALW_ON &= 0x00;
    *DCM_BUS_GATED_EN |= 0x00FF;
    *DCM_RG_CK_DCM_EN &= ~(0x80);
    /* idle frequency setting */
    *EMI_IDLE_FSEL = 0x1F;
    *FBUS_IDLE_FSEL = 0x1;
    *SBUS_IDLE_FSEL = 0x1;
    #endif /* __SMART_PHONE_MODEM__ */

    #elif defined(MT6575)

    // When clock switch setting is stable, gated global_con register
    *DCM_RG_GLOBALCON_CON = *DCM_RG_GLOBALCON_CON | (1<<1); 
    *DCM_PERI_BUS_CON0 = *DCM_PERI_BUS_CON0 | (1<<31); // for LOC_ACC entering DCM

    *DCM_HW_MISC0 |= 0x606;
    // bit[1] 	= 1: MD2GSYS bus clock is gated when MD2GSYS MTCMOS
    // bit[2] 	= 1: MCU clock switch is switched to 26MHz when MCU clock is gated
    // bit[3] 	= 1: MD2GSYS subsys clock is gated when MD2GSYS MTCMOS
    // bit[4] 	= 1: HSPASYS subsys clock is gated when HSPASYS MTCMOS
    // bit[9] 	= 1: DSP clock switch is switched to 26MHz when DSP clock is gated
    // bit[10] 	= 1: MCU clock is gated when MCU MTCMOS
    *DCM_HW_MISC0 = *DCM_HW_MISC0 & 0xf7ff;   // Enable HW_DCM auto detection (bit[11] : MD2GSYS)
    *DCM_HW_MISC0 = *DCM_HW_MISC0 & 0xefff;   // Enable HW_DCM auto detection (bit[12] : P_DMA)


    // Low power setting
    *DCM_RG_CK_ALW_ON = 0x0; // all CG controlled by HW
    *DCM_BUS_GATED_EN = 0xffff; // bus gated enable
    // Lowest frequency setting
    *DCM_FBUS_IDLE_FSEL = 0x1;  // 15.36MHz for AFC
    *DCM_SBUS_IDLE_FSEL = 0x1; // 15.36MHz for AFC
    // HW control bus protection when enterning ARM MTCMOS mode
    *DCM_ARM_BUS_ACCESS_CON &= ~(0x00010000); 

    #if !defined(__MEUT__)
    *DCM_RG_CK_DCM_EN = 0x100F; // MDMCU, bus, DCM enable
    #else
    *DCM_DSP_IDLE_FSEL  = 0x1f; // 8.125MHz
    #endif

    #ifndef __SMART_PHONE_MODEM__
    // AP side DCM and lowest frequency setting
    *DCM_INFRA_TOPCKGEN_DCMCTL |= 0x7;
    *DCM_INFRA_TOPCKGEN_DCMFSEL = 0x07000000;
    *((volatile UINT32P)0xC00041DC) |= (0x3 << 24);/* enable EMI DCM */
    *DCM_INFRA_GLOBALCON_DCMCTL |= ((0x1 << 8) | 0x1);
    *DCM_INFRA_GLOBALCON_DCMFSEL = 0x0;
    *DCM_PERI_GLOBALCON_DCMCTL |= 0x1;
    *DCM_PERI_GLOBALCON_DCMFSEL = 0x0;
    *DCM_MMSYS2_GLOBALCON_DCMCTL = (0x1<<9) | (0x1<<8) | (0x1);
    #endif /* __SMART_PHONE_MODEM__ */

    #elif defined(MT6250) || defined (MT6260)

    *PLL_CLK_CONDB &= (~0x08000); /** 0xA001_0104, clear bit 15, the HW 26Mhz to PLL switching assistance enable bit
                                   * because to switch to ARM 87Mhz needs it be disabled
                                   **/
    *PLL_CLK_CONDB; //read back for assureence of write down

    #if !defined(__MEUT__) && defined (__HW_DCM__)
    //start DCM 
    _savedMask = LockIRQ();
#if defined (MT6250)
    *PLL_CLK_CONDE = (*PLL_CLK_CONDE & (1<<10)) | 0x02B5;
#else //#if defined (MT6250)
    *PLL_CLK_CONDE = (*PLL_CLK_CONDE & ((3<<14) | (1<<10))) | MT6260_CONDE_GOLDEN_CONF;  //reserve bit 14, 15, 10, that is not DCM switch.
#endif //#if defined (MT6250)
    RestoreIRQ(_savedMask);

    #endif //#if defined (__HW_DCM__)

    #endif //MT6276

    #if defined(__MTK_INTERNAL__)
/* under construction !*/
    #if defined (MT6250) && defined (__HW_DCM__)
/* under construction !*/
    #endif //#if defined (MT6250) && defined (__HW_DCM__)
/* under construction !*/
#if !defined(MT6260) /// disable temperarly for MT6260
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //#if !defined(MT6260)
/* under construction !*/
    #endif //__MTK_INTERNAL__
	
    #endif // DCM_ENABLE	
    
    #if defined(MT6276)
    /* get current chip SW version */
    if(SW_SEC_0 == INT_SW_SecVersion())
    {
        dcm_mp3_workaround = KAL_TRUE;
    }
    else
    {
        dcm_mp3_workaround = KAL_FALSE;
    }
    #endif /* MT6276 */
}

#if defined(DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT)

#if defined(L1D_TEST)
extern kal_int8 L1DTest_L1SM_Is_Slept(void);
#else
extern kal_bool L1SM_Is_Slept(void);
#endif  /* L1D_TEST */

extern kal_bool AUDLP_Check_LowPower_Status(void);

#endif  /* DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT */

//#pragma arm section code = "INTERNCODE"
#pragma arm section code = "INTSRAM_ROCODE"

void DCM_Handler( void )
{

   /* Partial sleep mode for MCU and AVB block.
      To force MCU and AVB bus CLK stopped when system is in idle task.
      System will run again and CLK resume automatically only when IRQ comes.
   */
   	
   #if defined( DCM_ENABLE )
      kal_uint32 _savedMask;
      register kal_uint32 start, end, duration;

      #if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
        kal_get_sleep_time(&dcm.allow_sleep_dur);
      #endif /* __CENTRALIZED_SLEEP_MANAGER__ */
      
   #if defined(__MCU_DORMANT_MODE__)
      OST_AllowedToPowerDown = OSTD_Allow_Dormant_Mode();
   #endif /* __MCU_DORMANT_MODE__ */
	  
      _savedMask = LockIRQ();
#if defined (MT6252)
      dcm_cached_rf_sleep = sm_rf_sleep();
#endif //#if defined (MT6252)

      #if !defined(MT6276_S00) && defined(MT6276)
      dcm_enter_32k_cnt = *DCM_F32K_CNT;
      #endif /* !MT6276_S00 && MT6276 */
      start = ust_get_current_time();

      #if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
         /* Enable nIRQ wake-up event after I-Bit OFF. */
         #if !defined(MT6276_S00) && defined(MT6276)
         dcm_check_NIRQ_peri_mask = *DCM_RM_PERI_CON;
         #endif /* !MT6276_S00 && MT6276 */
         OSTD_EnableNIRQ();
        /* Get confirm. (return for next while loop if it is invalid sleep time) */
        if( kal_is_valid_sleep_time( &(dcm.allow_sleep_dur) ) == 0 )
        {
            /* Disable nIRQ wake-up event before I-Bit ON. */
            OSTD_DisableNIRQ();
           RestoreIRQ(_savedMask);
           return;
        }
        /* Check & Trigger OST Pause Mode:
           MUST be called inside of I-Bit protection:
           If return value is KAL_FALSE, not going to sleep and maybe then execute DCM. 
           If return value is KAL_TRUE, going to sleep and bypass DCM. */
        #if !defined(MT6276_S00) && defined(MT6276)
        dcm_check_sleep_peri_mask = *DCM_RM_PERI_CON;
        #endif /* !MT6276_S00 && MT6276 */
        OST_ReadyToSlept = OSTD_CheckSleep();
	    dcm.OST_ReadyToSlept = OST_ReadyToSlept;
      #endif /* __CENTRALIZED_SLEEP_MANAGER__ */

      /* Check if DMA, GMC and LCD_DMA is in Power Down Mode. */
      #if !defined(MT6276_S00) && defined(MT6276)
      dcm_enable_check_peri_mask = *DCM_RM_PERI_CON;
      #endif /* !MT6276_S00 && MT6276 */
      #if defined(MT6573)
      if ( DCM_ENABLE_CHECK &&
           dcm.dcmDisable == 0 &&
           dcm.dcmForceDisalbe == 0 )
      #elif defined(MT6255) 
      if ( (MT6255_HWDCM_MODE(sw_secversion) || DCM_ENABLE_CHECK) &&
           OST_ReadyToSlept == KAL_FALSE && 
           dcm.dcmDisable == 0 &&
           dcm.dcmForceDisalbe == 0 )
      #else
      if ( DCM_ENABLE_CHECK &&
           OST_ReadyToSlept == KAL_FALSE && 
           dcm.dcmDisable == 0 &&
           dcm.dcmForceDisalbe == 0 )
      #endif
      {
         #if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238) || defined(MT6239)
            /* MT6235/MT6268 doesn't use L2 cache, only use MT6238_SER */
          	/* Gate GMC DMA */
            extern kal_uint32 GateDG(void);
            extern void UngateDG(kal_uint32);
            kal_uint32 tmp;
            tmp = GateDG();
            {   
                volatile register kal_uint32 i=0;  
                for (i = 0; i < 20; i++);
            }
         #endif

         /*To access an address not in existance will ensure that EMI access is complete.*/
         #if !(defined(MT6516) || defined(TK6516) || defined(MT6251))
         #if !defined(MT6276_S00) && defined(MT6276)
         dcm_dbg_dummy_read_peri_mask = *DCM_RM_PERI_CON;
         #endif /* !MT6276_S00 && MT6276 */
             EMI_Dummy_Read();
         #endif
         /*A26=1 means will not get data via data cache, it will access EMI directly.*/
         
         dcm_state = 1; /* DCM @ 104/52->13/26Mhz */ 

         /* Change WS and clock rate. */ 
         /* mtk01940 
           ======================================
	                        Idle      Dedi
	         MT6217         13MHz     x
	         MT6227         13MHZ     26MHz
	         MT6223         13MHz     13MHz
	         MT6225         13MHz     13MHz
	         MT6228         13MHz     x
	         MT6229         26MHz     26MHz
	         MT6235         13MHz     13MHz
	         MT6238         13MHz     13MHz
	         MT6516         13MHz     13MHz
           ======================================
         */
         #if defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6226D) || defined(MT6227D) || defined(MT6226DS) || defined(MT6227DS)  || defined(MT6228) 
           #if defined(MT6227D)
             custom_DynamicClockSwitch( MCU_13MHZ );
           #else
             if(dcm.isIdleMode && !(dcm.force26MHz))
             {         
                custom_DynamicClockSwitch( MCU_13MHZ );
             }
             else
             {
                custom_DynamicClockSwitch( MCU_26MHZ );
             }
           #endif
         #elif defined(MT6268)
             custom_DynamicClockSwitch( MCU_15_36MHZ );
         #elif defined(MT6268A)
             custom_DynamicClockSwitch( MCU_30_72MHZ );
         #elif defined(MT6229) || defined(MT6230)
             custom_DynamicClockSwitch( MCU_26MHZ );
		 #elif defined(MT6255) 
             if (!MT6255_HWDCM_MODE(sw_secversion))
			     custom_DynamicClockSwitch( MCU_26MHZ );
	     #elif !defined(__HW_DCM__)
             custom_DynamicClockSwitch( MCU_13MHZ );  
         #endif         
         
         #if defined(DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT)
             /* Check if we should switch to SWDCM in Low Power Audio mode, it's decided by
                the API provided by audio and also L1 sleep mode */
           #if defined(L1D_TEST)
             if (AUDLP_Check_LowPower_Status() && L1DTest_L1SM_Is_Slept())
           #else
             if (AUDLP_Check_LowPower_Status() && L1SM_Is_Slept())
           #endif
             {
                /*
                 * Set the flag for Low Power Audio mode
                 */
                dcm_lpaudio_mode = KAL_TRUE;
                dcm_lpaudio_cnt++;
                
                /*
                 * Dummy Read to force EMI to leave DCM mode, assume PPCT will keep it from
                 * going back to DCM again
                 */
                #if !(defined(MT6516) || defined(TK6516) || defined(MT6251))
                EMI_Dummy_Read();
                #endif
                
                #if defined(MT6256)
                #if !defined(MT6256_S00)
                /*
                 * Disable HWDCM
                 */
                *DCM_PLL_CON1 &= ~0x4000; 
                
                /*
                 * Switch EMI to 26MHz
                 */
                custom_DynamicClockSwitch( MCU_26MHZ );  
                #endif /* MT6256_S00 */
                #endif /* MT6256 */
             }
         #endif /* DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT */
         
         dcm_state = 2; /* DCM @ 13/26MHz */
         
         #if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6238) || defined(MT6239)
            /* MT6235/MT6268 doesn't use L2 cache, only use MT6238_SER */
            /* Recover GMC DMA gating */
            UngateDG(tmp);
         #endif
      
         /* check if IRQ is disabled for more than 60 qbits */
         end = ust_get_current_time();
         duration = ust_get_duration(start, end);
         #if !defined(MT6276_S00) && defined(MT6276)
         dcm_check_32k_cnt = *DCM_F32K_CNT;
         #endif /* !MT6276_S00 && MT6276 */
		 
         if (duration > 60) {
            if( !L1_CHECK_ASSERT_BYPASS() )
               EXT_ASSERT(0, duration, start, end);
         }
		 
          #if defined(MT6516) || defined(TK6516)
          {
              volatile register kal_uint32 i=0;  
              *SLEEP_CON |= 0x0003;
              for (i = 0; i < 20; i++);
          }
          #elif defined(MT6253T)
             /* do nothing */
          #elif defined(MT6236) || defined(MT6251) || defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
             *SLEEP_CON |= 0x0003;
          #elif defined(MT6255) 
             // do nothing
          #elif defined(MT6256)
          #if defined(MT6256_S00)
	        *SLEEP_CON |= 0x0001;
          #else /* !MT6256_S00 */
            /* check whether we need to enable EMI DCM here */
            #if defined(__ENABLE_EMI_DCM_AT_IDLE__)
             *SLEEP_CON |= 0x20;         //Enable AHB to EMI idle detect
            #endif /* __ENABLE_EMI_DCM_AT_IDLE__ */
          #endif /* MT6256_S00 */
          #elif defined(MT6253)
             /* MT6253 Chip bug: AHB clock gate doesn't refer to EMI idle, disable this function */
             *SLEEP_CON = 0x0001;
          #elif defined(MT6276)
             #if defined(MT6276_S00)
             *DCM_RG_CK_DCM_EN1 = 0x0003;
             #else /* MT6276_S01 or latter */
             //*DCM_RG_CK_DCM_EN1 = 0x008B; /* enable DCM IRQ clear */
             //*DCM_RG_CK_DCM_EN1 = 0x000B; /* enable bus, EMI, and MCU DCM */
             *DCM_RG_CK_DCM_EN1 = 0x100B; /* enable bus, EMI, and MCU DCM, bypass hspa_bus_idle_x1  */
             #endif
          #elif defined(MT6573)
             #ifndef __SMART_PHONE_MODEM__
             *DCM_RG_CK_DCM_EN |= 0x3;
             #endif /* __SMART_PHONE_MODEM__ */
             *DCM_MDARM_DCM_EN |= 0x3;
             *DCM_MDARM_CCTL &= 0xFFFFFEFF;
#elif defined(MT6250) || defined (MT6260)
#if defined (MT6260)
             //enable EMI HW DCM, 
             /** 1. arm-to-emi idle has too-long recovery time, thus only enable EMI DCM while ARM entering idle.
              *  2. MMSYS idle signal has poor timing constrain, thus only enable EMI DCM while all MMSYSs entering idle.
              */
             if ((*DCM_PDN_COND0 & (0x3f)) == 0x3f) {                 
                 MT6260_EMI_DCM_ENABLE();
             }
#endif //#if defined (MT6260)

             arm_enter_standby_mode(0);

          #elif defined(MT6575)
          /* TODO - add HW DCM code */          
          #else 
             *SLEEP_CON = 0x0003;
          #endif
      
#if defined(MT6238) || defined(MT6239) || defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6268A) || defined(MT6236) || defined(MT6236B) || defined(MT6256) || defined(MT6276) || defined(MT6573) || defined(MT6575) || defined(MT6255)
          /* When DTCM is used by other subsys, ARM can not gate clock. */
          if(WFI_Handle_Count == 0 )
          {
              #if !defined(MT6276_S00) && defined(MT6276)
              dcm_top_sm_peri_mask = *DCM_RM_PERI_CON;

              /* de-assert RM_SYSCLK_ON | FORCE_SYSCLK_ON | FORCE_PLLCLK_ON | FORCE_TOP_CLK_ON */
              if(dcm_SYSCLK_Force_On_count > 0)
              {
                  *DCM_CCF_CLK_CON &= ~(0x0C); /* keep 26Mhz clock on */
              }
              else
              {
                  *DCM_CCF_CLK_CON &= ~(0x0F);
              }

              #endif /* !MT6276_S00 && MT6276 */
#if defined(MT6255) 
              {
                  //WHQA_00009504: close SLEEP_CON[1,2,5] to avoid F2S post write failure, that suffer if has continuous 2 APB write. 
                  register unsigned short sleep_con_save;
                  if (MT6255_HWDCM_MODE(sw_secversion) && MT6255_PATCH_WHQA_9504(sw_secversion)) {
                      sleep_con_save = *SLEEP_CON;
                      sleep_con_save = (sleep_con_save & ~0x26) | 0x22; //PDN_AHBEMI_CONFIG | PDN_AHB_CONFIG
                      *SLEEP_CON = sleep_con_save;   
                  }

                  //WHQA_00010183: WFI gating mcu_clk to F2S, that thus fail to deal with outstanding APB write.
                  sleep_con_save = *SLEEP_CON;
              }
#endif
              cp15_enter_low_pwr_state();

              #if !defined(MT6276_S00) && defined(MT6276)

              /* Assert RM_SYSCLK_ON | FORCE_SYSCLK_ON | FORCE_PLLCLK_ON | FORCE_TOP_CLK_ON 
                 to avoid MCU clock disappear unexpectedly issue.
              */
              *DCM_CCF_CLK_CON |= 0x0F;

              dcm_top_sm_peri_mask = *DCM_RM_PERI_CON;
              #endif /* !MT6276_S00 && MT6276 */
          }
          #endif /* MT623538 */            

          #if defined(__MTK_INTERNAL__)
/* under construction !*/
          #endif //__MTK_INTERNAL__
      } 
      else
      {
          #if defined(DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT)
          /* Check if we should switch to SWDCM in Low Power Audio mode, it's decided by
             the API provided by audio and also L1 sleep mode */
          #if defined(L1D_TEST)
          if (AUDLP_Check_LowPower_Status() && L1DTest_L1SM_Is_Slept())
          #else
          if (AUDLP_Check_LowPower_Status() && L1SM_Is_Slept())
          #endif
          {
              dcm_state = 1; /* DCM @ 104/52->13/26Mhz */ 

              /*
               * Set the flag for Low Power Audio mode
               */
              dcm_lpaudio_mode = KAL_TRUE;
              dcm_lpaudio_cnt++;

              /*
               * Dummy Read to force EMI to leave DCM mode, assume PPCT will keep it from
               * going back to DCM again
               */
              #if !(defined(MT6516) || defined(TK6516) || defined(MT6251))
              EMI_Dummy_Read();
              #endif

              #if defined(MT6256)
              #if !defined(MT6256_S00)
              /*
               * Disable HWDCM
               */
              *DCM_PLL_CON1 &= ~0x4000; 

              /*
               * Switch EMI to 26MHz
               */
              custom_DynamicClockSwitch( MCU_26MHZ );  
              #endif /* MT6256_S00 */
              #endif /* MT6256 */
              dcm_state = 2; /* DCM @ 13/26MHz */
          }
          #endif /* DCM_AUDIO_DSP_LOWPOWER_V2_SUPPORT */

          #if defined(MT6516) || defined(TK6516)
          {
              volatile register kal_uint32 i=0;  
              *SLEEP_CON |= 0x0001;
              for (i = 0; i < 20; i++);
          }
          #elif defined(MT6253T) || defined(MT6276) || defined(MT6573) || (defined(MT6256) && !defined(MT6256_S00)) || defined(MT6575) || defined (MT6255)
             /* do nothing */
          #elif defined(MT6236) || defined(MT6256_S00)
             *SLEEP_CON |= 0x0001;  		  
	  #elif defined(MT6251)
          if( dcm.dcmForceDisalbe == 0 )
          {
              *SLEEP_CON |= 0x0001;
          }
          #elif defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
          if( dcm.dcmForceDisalbe == 0 )
          {
#if defined(MT6252)
              /* workaround, to elimite current leakage of PSRAM and relevent side effect. */
              /** PLEASE NOTE: DO NOT change this code pattern, otherwise do more stree test for network camping. **/
              {
                  extern kal_bool L1SM_Is_Slept(void);

                  dcm_cached_slept_flag = L1SM_Is_Slept();

                  if (dcm_cached_slept_flag == KAL_TRUE) {
                      EMI_Mask_PullDownED();
                  }  
                  if (dcm_cached_slept_flag == KAL_FALSE) {
                      if (dcm_cached_rf_sleep == KAL_FALSE) {
                          goto question_ungated;
                      }
                  } 
                  *SLEEP_CON |= 0x0001;  
                  __nop(); //1
                  __nop();
                  __nop();
                  __nop();
                  __nop(); //5
                  __nop();
                  __nop();
                  __nop();
                  __nop();
                  __nop(); //10
                  __nop();
                  __nop();
                  __nop();
                  __nop();
                  __nop(); //15
                  __nop();
                  __nop();

              }
          question_ungated:
              {
                  if (dcm_cached_slept_flag == KAL_TRUE) {
                      EMI_Unmask_NonPullED();
                  }

              }
#else //#if defined(MT6252)
              *SLEEP_CON |= 0x0001;  
#endif //#if defined(MT6252)
          }
          #elif defined(MT6250)
              arm_enter_standby_mode(0);
          #elif defined (MT6260)
              arm_enter_standby_mode(OST_ReadyToSlept);
          #else
             *SLEEP_CON = 0x0001;
          #endif
      
          #if defined(MT6238) || defined(MT6239) || defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6268A) || defined(MT6236) || defined(MT6236B) || defined(MT6256) || defined(MT6276) || defined(MT6573) || defined(MT6575) || defined(MT6255)
          /* When DTCM is used by other subsys, ARM can not gate clock. */          
          if(WFI_Handle_Count == 0 )
          {
              #if !defined(MT6276_S00) && defined(MT6276)
              if(OST_ReadyToSlept && dcm_mp3_workaround) /* mp3 jitter issue workaround is only for MT6276E2 */
              {
                  register kal_uint32 idx = 0;

                  SLA_CustomLogging("SLP", SA_label);
                  dcm_enter_sleep_mode = KAL_TRUE;
                  /* SW workaround for the issue that audio clock is switched back before MPLL settles down */
                  *DCM_ARM_SLEEP_BACKUP |= DCM_ARM_PERI_MASK; /* set 2G, 3G, and ARM mask bit*/
                  *DCM_RM_PERI_CON |= DCM_ARM_PERI_MASK;
                  for(idx = 0 ; idx < 3 ; idx++)
                  {
                      if( (*DCM_RM_PERI_CON & DCM_DSP_PERI_MASK) == (*DCM_DSP_SLEEP_BACKUP & DCM_DSP_PERI_MASK) )
                      {
                          break;
                      }
                  }
                  if(3 == idx)
                  {
                      /* race condition is detected, set RM_PERI_CON to DSP required value */
                      if(*DCM_DSP_SLEEP_BACKUP & DCM_DSP_PERI_MASK)
                      {
                          *DCM_RM_PERI_CON |= DCM_DSP_PERI_MASK;
                      }
                      else
                      {
                          *DCM_RM_PERI_CON &= ~DCM_DSP_PERI_MASK;
                      }
                  }
                  if(*DCM_RM_PERI_CON & DCM_DSP_PERI_MASK)
                  {
                      /* ARM is the last one to sleep, ensure that all RM_PERI_CON mask bits are set to '1' at the same time. */
                      *DCM_RM_PERI_CON |= (DCM_2G_PERI_MASK|DCM_3G_PERI_MASK);
                  }
                  dcm_top_sm_peri_mask = *DCM_RM_PERI_CON;
                  dcm_enter_sleep_frc = ust_get_current_time();
              }
              #endif /* MT6276_S01 or latter */

              if( (KAL_TRUE == OST_ReadyToSlept) && (KAL_TRUE == OST_AllowedToPowerDown) )
              {
                  #if defined(__MCU_DORMANT_MODE__)
                  dormant_mode_activate();
                  #else /* __MCU_DORMANT_MODE__ */

                  #if !defined(MT6276_S00) && defined(MT6276)
                  /* de-assert RM_SYSCLK_ON | FORCE_SYSCLK_ON | FORCE_PLLCLK_ON | FORCE_TOP_CLK_ON */
                  if(dcm_SYSCLK_Force_On_count > 0)
                  {
                      *DCM_CCF_CLK_CON &= ~(0x0C); /* keep 26Mhz clock on */
                  }
                  else
                  {
                      *DCM_CCF_CLK_CON &= ~(0x0F);
                  }
                  #endif /* !MT6276_S00 && MT6276 */

                  #if defined(MT6255)
                  //WHQA_00010183: WFI gating mcu_clk to F2S, that thus fail to deal with outstanding APB write.
                  {
                      register unsigned short sleep_con_save;
                      sleep_con_save = *SLEEP_CON;
                  }
                  #endif // defined(MT6255)

                  cp15_enter_low_pwr_state();

                  #if !defined(MT6276_S00) && defined(MT6276)
                  /* assert RM_SYSCLK_ON | FORCE_SYSCLK_ON | FORCE_PLLCLK_ON | FORCE_TOP_CLK_ON 
                     to avoid MCU clock disappear unexpectedly issue 
                  */
                  *DCM_CCF_CLK_CON |= 0x0F;
                  #endif /* !MT6276_S00 && MT6276 */

                  #endif /* __MCU_DORMANT_MODE__ */
              }
              else
              {
                  #if defined(MT6255)
                  //WHQA_00010183: WFI gating mcu_clk to F2S, that thus fail to deal with outstanding APB write.
                  {
                      register unsigned short sleep_con_save;
                      sleep_con_save = *SLEEP_CON;
                  }
                  #endif //defined(MT6255)
                  #if !defined(MT6276_S00) && defined(MT6276)
                  /* de-assert RM_SYSCLK_ON | FORCE_SYSCLK_ON | FORCE_PLLCLK_ON | FORCE_TOP_CLK_ON */
                  if(dcm_SYSCLK_Force_On_count > 0)
                  {
                      *DCM_CCF_CLK_CON &= ~(0x0C); /* keep 26Mhz clock on */
                  }
                  else
                  {
                      *DCM_CCF_CLK_CON &= ~(0x0F);
                  }
                  #endif /* !MT6276_S00 && MT6276 */

                  cp15_enter_low_pwr_state();

                  #if !defined(MT6276_S00) && defined(MT6276)
                  /* assert RM_SYSCLK_ON | FORCE_SYSCLK_ON | FORCE_PLLCLK_ON | FORCE_TOP_CLK_ON 
                     to avoid MCU clock disappear unexpectedly issue 
                  */
                  *DCM_CCF_CLK_CON |= 0x0F;
                  #endif /* !MT6276_S00 && MT6276 */
              }

              #if !defined(MT6276_S00) && defined(MT6276)
              if(OST_ReadyToSlept && dcm_mp3_workaround) /* mp3 jitter issue workaround is only for MT6276E2 */
              {
                  register kal_uint32 idx = 0;

                  dcm_leave_sleep_frc = ust_get_current_time();
                  /* SW workaround for the issue that audio clock is switched back before MPLL settles down */
                  /* check RM_PERI_CON state */
                  if(*DCM_RM_PERI_CON & DCM_DSP_PERI_MASK)
                  {
                      if(*DCM_RM_PERI_CON & (DCM_2G_PERI_MASK|DCM_3G_PERI_MASK))
                      {
                          /* proceed ARM wake up operations */
                      }
                      else
                      {
                          register kal_uint32 i=0;  

                          /* DSP is the last one to sleep, ensure that all RM_PERI_CON mask bits are set to '1' at the same time. */
                          while(!(*DCM_RM_PERI_CON & (DCM_2G_PERI_MASK|DCM_3G_PERI_MASK)))
                          {
                              if(i++ > DCM_WAIT_FOR_DSP_COMPLETE)
                              {
                                  /* unexpected state, DSP does not think it is the last one to sleep just before ARM tries to wake up .*/
                                  /* a loop to bypass contention case */
                                  break;
                              }
                          };
                      }
                  }
                  *DCM_ARM_SLEEP_BACKUP &= ~DCM_ARM_PERI_MASK;
                  *DCM_RM_PERI_CON &= ~(DCM_2G_PERI_MASK|DCM_3G_PERI_MASK|DCM_ARM_PERI_MASK); /* clear ARM, 2G, and 3G mask bit*/
                  for(idx = 0 ; idx < 3 ; idx++)
                  {
                      if( (*DCM_RM_PERI_CON & DCM_DSP_PERI_MASK) == (*DCM_DSP_SLEEP_BACKUP & DCM_DSP_PERI_MASK) )
                      {
                          break;
                      }
                  }
                  if(3 == idx)
                  {
                      /* race condition is detected, set RM_PERI_CON to DSP required value */
                      if(*DCM_DSP_SLEEP_BACKUP & DCM_DSP_PERI_MASK)
                      {
                          *DCM_RM_PERI_CON |= DCM_DSP_PERI_MASK;
                      }
                      else
                      {
                          *DCM_RM_PERI_CON &= ~DCM_DSP_PERI_MASK;
                      }
                  }
                  dcm_top_sm_peri_mask = *DCM_RM_PERI_CON;
                  /* ensure that ARM side mask is cleared */
                  while(*DCM_RM_PERI_CON&DCM_ARM_PERI_MASK);
                  dcm_enter_sleep_mode = KAL_FALSE;
                  EMI_Dummy_Read();
                  SLA_CustomLogging("WAK", SA_label);
              }
              #endif /* MT6276_S01 or latter */
          }
          #endif /* MT623538 */            
      }           
      
      #if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
      /* Disable nIRQ wake-up event before I-Bit ON. */
      OSTD_DisableNIRQ();
      #endif /* __CENTRALIZED_SLEEP_MANAGER__ */
      RestoreIRQ(_savedMask);

   #else //DCM_ENABLE

      register kal_uint32 idx = 0;
      register kal_uint32 i=0;  
      kal_uint32 _savedMask;
      #if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
      Sleep_Time allow_sleep_dur;

      kal_get_sleep_time(&allow_sleep_dur);
      #endif /* __CENTRALIZED_SLEEP_MANAGER__ */

      #if defined(__MCU_DORMANT_MODE__)
      OST_AllowedToPowerDown = OSTD_Allow_Dormant_Mode();
      #endif /* __MCU_DORMANT_MODE__ */
	  
      _savedMask = LockIRQ();

      #if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
      /* Enable nIRQ wake-up event after I-Bit OFF. */
      OSTD_EnableNIRQ();
      /* Get confirm */
      if( kal_is_valid_sleep_time( &allow_sleep_dur ) == 0 )
      {
         /* Disable nIRQ wake-up event before I-Bit ON. */
         OSTD_DisableNIRQ();
         RestoreIRQ(_savedMask);
         return;
      }
      /* Check & Trigger OST Pause Mode:
           MUST be called inside of I-Bit protection:
           No need to check return value while DCM disabled. */
      OST_ReadyToSlept = OSTD_CheckSleep();
      #endif /* __CENTRALIZED_SLEEP_MANAGER__ */
	  
      /*To temporarily avoid the problem on AHB.*/

      #if !defined(MT6268T) && !defined(MT6268H) && !defined(MT6270A) //Raymond 20071113 with CS5/Zhuohao
        #if defined(MT6516) || defined(TK6516)
          *SLEEP_CON |= 0x0001; 
        #elif defined(MT6253T) || defined(MT6253E) || defined(MT6253L) || defined(MT6251) || defined(MT6252) || defined(MT6252H)
        /* do nothing */
        #elif defined(MT6276) || defined(MT6573)  || (defined(MT6256) && !defined(MT6256_S00)) || defined(MT6575) || defined(MT6255) 
          if(WFI_Handle_Count == 0 )
          {
              #if !defined(MT6276_S00) && defined(MT6276)
              if(OST_ReadyToSlept && dcm_mp3_workaround) /* mp3 jitter issue workaround is only for MT6276E2 */
              {
                  SLA_CustomLogging("SLP", SA_label);
                  dcm_enter_sleep_mode = KAL_TRUE;
                  /* SW workaround for the issue that audio clock is switched back before MPLL settles down */
                  *DCM_ARM_SLEEP_BACKUP |= DCM_ARM_PERI_MASK; /* set 2G, 3G, and ARM mask bit*/
                  *DCM_RM_PERI_CON |= DCM_ARM_PERI_MASK;
                  for(idx = 0 ; idx < 3 ; idx++)
                  {
                      if( (*DCM_RM_PERI_CON & DCM_DSP_PERI_MASK) == (*DCM_DSP_SLEEP_BACKUP & DCM_DSP_PERI_MASK) )
                      {
                          break;
                      }
                  }
                  if(3 == idx)
                  {
                      /* race condition is detected, set RM_PERI_CON to DSP required value */
                      if(*DCM_DSP_SLEEP_BACKUP & DCM_DSP_PERI_MASK)
                      {
                          *DCM_RM_PERI_CON |= DCM_DSP_PERI_MASK;
                      }
                      else
                      {
                          *DCM_RM_PERI_CON &= ~DCM_DSP_PERI_MASK;
                      }
                  }
                  if(*DCM_RM_PERI_CON & DCM_DSP_PERI_MASK)
                  {
                      /* ARM is the last one to sleep, ensure that all RM_PERI_CON mask bits are set to '1' at the same time. */
                      *DCM_RM_PERI_CON |= (DCM_2G_PERI_MASK|DCM_3G_PERI_MASK);
                  }
                  dcm_top_sm_peri_mask = *DCM_RM_PERI_CON;
                  dcm_enter_sleep_frc = ust_get_current_time();
              }
              #endif /* MT6276_S01 or latter */

              if( (KAL_TRUE == OST_ReadyToSlept) && (KAL_TRUE == OST_AllowedToPowerDown) )
              {
                  #if defined(__MCU_DORMANT_MODE__)
                  dormant_mode_activate();
                  #else /* __MCU_DORMANT_MODE__ */

                  #if !defined(MT6276_S00) && defined(MT6276)
                  /* de-assert RM_SYSCLK_ON | FORCE_SYSCLK_ON | FORCE_PLLCLK_ON | FORCE_TOP_CLK_ON */
                  if(dcm_SYSCLK_Force_On_count > 0)
                  {
                      *DCM_CCF_CLK_CON &= ~(0x0C); /* keep 26Mhz clock on */
                  }
                  else
                  {
                      *DCM_CCF_CLK_CON &= ~(0x0F);
                  }
                  #endif /* !MT6276_S00 && MT6276 */

                  #if defined(MT6255) 
                  //WHQA_00010183: WFI gating mcu_clk to F2S, that thus fail to deal with outstanding APB write.
                  {
                      register unsigned short sleep_con_save;
                      sleep_con_save = *SLEEP_CON;
                  }
                  #endif //defined (MT6255)

                  cp15_enter_low_pwr_state();

                  #if !defined(MT6276_S00) && defined(MT6276)
                  /* assert RM_SYSCLK_ON | FORCE_SYSCLK_ON | FORCE_PLLCLK_ON | FORCE_TOP_CLK_ON 
                     to avoid MCU clock disappear unexpectedly issue 
                  */
                  *DCM_CCF_CLK_CON |= 0x0F;
                  #endif /* !MT6276_S00 && MT6276 */

                  #endif /* __MCU_DORMANT_MODE__ */

              }
              else
              {
                  #if !defined(MT6276_S00) && defined(MT6276)
                  /* de-assert RM_SYSCLK_ON | FORCE_SYSCLK_ON | FORCE_PLLCLK_ON | FORCE_TOP_CLK_ON */
                  if(dcm_SYSCLK_Force_On_count > 0)
                  {
                      *DCM_CCF_CLK_CON &= ~(0x0C); /* keep 26Mhz clock on */
                  }
                  else
                  {
                      *DCM_CCF_CLK_CON &= ~(0x0F);
                  }
                  #endif /* !MT6276_S00 && MT6276 */

                  #if defined(MT6255) 
                  //WHQA_00010183: WFI gating mcu_clk to F2S, that thus fail to deal with outstanding APB write.
                  {
                      register unsigned short sleep_con_save;
                      sleep_con_save = *SLEEP_CON;
                  }
                  #endif //defined (MT6255)

                  cp15_enter_low_pwr_state();

                  #if !defined(MT6276_S00) && defined(MT6276)
                  /* assert RM_SYSCLK_ON | FORCE_SYSCLK_ON | FORCE_PLLCLK_ON | FORCE_TOP_CLK_ON 
                     to avoid MCU clock disappear unexpectedly issue 
                  */
                  *DCM_CCF_CLK_CON |= 0x0F;
                  #endif /* !MT6276_S00 && MT6276 */
              }

              #if !defined(MT6276_S00) && defined(MT6276)
              if(OST_ReadyToSlept && dcm_mp3_workaround) /* mp3 jitter issue workaround is only for MT6276E2 */
              {
                  dcm_leave_sleep_frc = ust_get_current_time();
                  /* SW workaround for the issue that audio clock is switched back before MPLL settles down */
                  /* check RM_PERI_CON state */
                  if(*DCM_RM_PERI_CON & DCM_DSP_PERI_MASK)
                  {
                      if(*DCM_RM_PERI_CON & (DCM_2G_PERI_MASK|DCM_3G_PERI_MASK))
                      {
                          /* proceed ARM wake up operations */
                      }
                      else
                      {
                          /* DSP is the last one to sleep, ensure that all RM_PERI_CON mask bits are set to '1' at the same time. */
                          while(!(*DCM_RM_PERI_CON & (DCM_2G_PERI_MASK|DCM_3G_PERI_MASK)))
                          {
                              if(i++ > DCM_WAIT_FOR_DSP_COMPLETE)
                              {
                                  /* unexpected state, DSP does not think it is the last one to sleep just before ARM tries to wake up .*/
                                  /* a loop to bypass contention case */
                                  break;
                              }
                          };
                      }
                  }
                  *DCM_ARM_SLEEP_BACKUP &= ~DCM_ARM_PERI_MASK;
                  *DCM_RM_PERI_CON &= ~(DCM_2G_PERI_MASK|DCM_3G_PERI_MASK|DCM_ARM_PERI_MASK); /* clear ARM, 2G, and 3G mask bit*/
                  for(idx = 0 ; idx < 3 ; idx++)
                  {
                      if( (*DCM_RM_PERI_CON & DCM_DSP_PERI_MASK) == (*DCM_DSP_SLEEP_BACKUP & DCM_DSP_PERI_MASK) )
                      {
                          break;
                      }
                  }
                  if(3 == idx)
                  {
                      /* race condition is detected, set RM_PERI_CON to DSP required value */
                      if(*DCM_DSP_SLEEP_BACKUP & DCM_DSP_PERI_MASK)
                      {
                          *DCM_RM_PERI_CON |= DCM_DSP_PERI_MASK;
                      }
                      else
                      {
                          *DCM_RM_PERI_CON &= ~DCM_DSP_PERI_MASK;
                      }
                  }
                  dcm_top_sm_peri_mask = *DCM_RM_PERI_CON;
                  /* ensure that ARM side mask is cleared */
                  while(*DCM_RM_PERI_CON&DCM_ARM_PERI_MASK);
                  dcm_enter_sleep_mode = KAL_FALSE;
                  EMI_Dummy_Read();
                  SLA_CustomLogging("WAK", SA_label);
              }
              #endif /* MT6276_S01 or latter */
          }
        #elif defined(MT6236) || defined(MT6256_S00)
          *SLEEP_CON |= 0x0001;		
        #elif defined(MT6250) 
          arm_enter_standby_mode(0);
        #elif defined (MT6260)
          arm_enter_standby_mode(OST_ReadyToSlept);
        #else      
          *SLEEP_CON = 0x0001; 
        #endif 
      #endif

      #if defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__EVENT_BASED_TIMER__) && defined(MTK_SLEEP_ENABLE)
      /* Disable nIRQ wake-up event before I-Bit ON. */
      OSTD_DisableNIRQ();
      #endif /* __CENTRALIZED_SLEEP_MANAGER__ */
      RestoreIRQ(_savedMask);

   #endif /* defined(DCM_ENABLE)*/       
}

#pragma arm section code

#if defined(__MCU_DORMANT_MODE__)
/*
 * Dormant mode support routines
 */
extern void enter_dormant_mode(void);
extern void leave_dormant_mode(void);
extern void arm_dormant_reset_handler(void);

#pragma arm section code = "INTSRAM_ROCODE"

/**********************************************************
Description : trigger dormant mode procedure
Input       : Non
Output      : Non
***********************************************************/
void dormant_mode_activate(void)
{
    kal_uint32 orig_reset = 0;

    SLA_CustomLogging("DOR", SA_start);

#if defined(MT6575)
    orig_reset = *DCM_BOOT_JUMP_ADDR;
    *DCM_BOOT_JUMP_ADDR = (unsigned int)arm_dormant_reset_handler;

    enter_dormant_mode();
    cp15_enter_low_pwr_state();

    *DCM_BOOT_JUMP_ADDR = orig_reset;

#else /* !MT6575 */

    cp15_enter_low_pwr_state();

#endif /* MT6575 */

    SLA_CustomLogging("DOR", SA_stop);

    return ;
}

/**********************************************************
Description : mark a flag to indicate that entry to dormant mode is abort
Input       : Non
Output      : Non
***********************************************************/
void dormant_mode_abort_entry(void)
{
    SLA_CustomLogging("dab", SA_label);
}

/**********************************************************
Description : mark a flag to indicate that dormant mode reset is abort
Input       : Non
Output      : Non
***********************************************************/
void dormant_mode_abort_reset(void)
{
    SLA_CustomLogging("dra", SA_label);
}


#pragma arm section code

#endif /* __MCU_DORMANT_MODE__ */

/* 
 * PLL save mode - implementation 
 */

#if defined(MT6276) && defined(__PLL_SAVE_MODE_ENABLE__)

extern void reduce_PLL_usage(kal_bool enable);

#if defined(__PLL_SAVE_MODE_LATENCY__)
volatile kal_uint32 enter_pll_save_duration = 0;
volatile kal_uint32 leave_pll_save_duration = 0;
#endif /* __PLL_SAVE_MODE_LATENCY__ */

void enter_PLL_save_mode(pll_use_scenario_t pll_scenario)
{
    #if defined(__PLL_SAVE_MODE_LATENCY__)
    enter_pll_save_duration = ust_get_current_time();
    #endif /* __PLL_SAVE_MODE_LATENCY__ */

    switch(pll_scenario)
    {
        case PLL_2G_TALKING:
        case PLL_3G_TALKING:
            reduce_PLL_usage(KAL_TRUE);
            break;
        default:
            ASSERT(0);
            break; 
    }

    #if defined(__PLL_SAVE_MODE_LATENCY__)
    enter_pll_save_duration = ust_get_current_time() - enter_pll_save_duration;
    kal_print_string_trace(MOD_IDLE, TRACE_INFO,"enter:%d us\n", enter_pll_save_duration);
    #endif /* __PLL_SAVE_MODE_LATENCY__ */

    return;
}

void leave_PLL_save_mode(pll_use_scenario_t pll_scenario)
{
    #if defined(__PLL_SAVE_MODE_LATENCY__)
    leave_pll_save_duration = ust_get_current_time();
    #endif /* __PLL_SAVE_MODE_LATENCY__ */

    switch(pll_scenario)
    {
        case PLL_2G_TALKING:
        case PLL_3G_TALKING:
            reduce_PLL_usage(KAL_FALSE);
            break;
        default:
            ASSERT(0);
            break; 
    }

    #if defined(__PLL_SAVE_MODE_LATENCY__)
    leave_pll_save_duration = ust_get_current_time() - leave_pll_save_duration;
    kal_print_string_trace(MOD_IDLE, TRACE_INFO,"exit:%d us\n", leave_pll_save_duration);
    #endif /* __PLL_SAVE_MODE_LATENCY__ */

    return;
}

#else /* !MT6276 || !__PLL_SAVE_MODE_ENABLE__ */

void enter_PLL_save_mode(pll_use_scenario_t pll_scenario) {}
void leave_PLL_save_mode(pll_use_scenario_t pll_scenario) {}

#endif /* MT6276 && __PLL_SAVE_MODE_ENABLE__ */

#pragma arm section code = "INTSRAM_ROCODE"

#if defined(MT6276)

#if defined(MT6276_S00)
void dynamic_switch_EMI(pll_source_t pll_type)
{
    kal_uint16 reg_val = 0;
    kal_uint32 saved = 0;
    kal_uint32 delay = 0;

    /* disable IRQ */
    saved = SaveAndSetIRQMask();
    switch(pll_type)
    {
        case MCU_PLL:
            /* set MCU PLL divider for EMI */
            reg_val = DRV_Reg16(DCM_CLKSW_PLLDIV_CON0);
            reg_val &= ~(0x01C0);
            reg_val |= 0x0100;
            DRV_Reg16(DCM_CLKSW_PLLDIV_CON0) = reg_val;
            break;
        case EMI_PLL:
            /* do nothing */
            break;
        default:
            ASSERT(0);
            break;
    }
    /* restore IRQ */
    //RestoreIRQMask(saved);

    //cp15_disable_mmu();
    /* block EMI request */
    /*Step 1: Disable Dummy Read*/
    *EMI_DRCT &=    ~0x1;       
    /*Step 2: Block all emi transaction*/
    *EMI_CONM =     0x003F;    
    /*Step 3: */
    *EMI_DQSE &= ~(1<<28);//Clear
    /*Step 4: Enter SDRAM self refresh mode and polling status*/
    *EMI_CONN |=    (1<<5);     
    while( ( *EMI_CONN & (1<<7) ) == 0 );
    /*Step 4: Wait for EMI idle bit assert*/
    while( ( *EMI_CONN & (1<<10) ) == 0 );

    /* disable IRQ */
    //saved = SaveAndSetIRQMask();
    switch(pll_type)
    {
        case MCU_PLL:
            /* switch to MCU PLL */
            reg_val = DRV_Reg16(DCM_PLL_CON4);
            reg_val &= ~(0x00F0);
            reg_val |= 0x0040;
            DRV_Reg16(DCM_PLL_CON4) = reg_val;
            break;
        case EMI_PLL:
            /* switch to EMI PLL */
            reg_val = DRV_Reg16(DCM_PLL_CON4);
            reg_val &= ~(0x00F0);
            reg_val |= 0x0010;
            DRV_Reg16(DCM_PLL_CON4) = reg_val;
            break;
        default:
            ASSERT(0);
            break;
    }
    /* restore IRQ */
    //RestoreIRQMask(saved);

    /* un-block EMI request */
    /*Step 9: Unmask EMI access for all master*/
    *EMI_CONM = 0x0000;

    /*Step 10: Exit SDRAM self refresh mode and polling status*/
    *EMI_CONN &=    ~(1<<5);
    while( ( *EMI_CONN & (1<<7) ) == 1 );

    /*Step 11: Enable dummy Read*/
    *EMI_DRCT |=    0x1; 

    //cp15_enable_mmu();
    /* restore IRQ */
    RestoreIRQMask(saved);
    for( delay = 0; delay <= 0xFFFF; delay++ );

}

void dynamic_switch_DSP(pll_source_t pll_type)
{
    kal_uint16 reg_val = 0;
    kal_uint32 saved = 0;

    /* disable IRQ */
    saved = SaveAndSetIRQMask();
    switch(pll_type)
    {
        case MCU_PLL:
            /* set MCU PLL divider for DSP */
            reg_val = DRV_Reg16(DCM_CLKSW_PLLDIV_CON0);
            reg_val &= ~(0x0E00);
            reg_val |= 0x0800;
            DRV_Reg16(DCM_CLKSW_PLLDIV_CON0) = reg_val;
            /* switch to MCU PLL */
            reg_val = DRV_Reg16(DCM_PLL_CON4);
            reg_val &= ~(0x0F00);
            reg_val |= 0x0400;
            DRV_Reg16(DCM_PLL_CON4) = reg_val;
            break;
        case DSP_PLL:
            /* switch to DSP PLL */
            reg_val = DRV_Reg16(DCM_PLL_CON4);
            reg_val &= ~(0x0F00);
            reg_val |= 0x0100;
            DRV_Reg16(DCM_PLL_CON4) = reg_val;
            break;
        default:
            ASSERT(0);
            break;
    }
   /* restore IRQ */
   RestoreIRQMask(saved);
}

void dynamic_switch_MCU(pll_source_t speed_type)
{
    kal_uint16 reg_val = 0;
    kal_uint32 saved = 0;

    /* disable IRQ */
    saved = SaveAndSetIRQMask();
    switch(speed_type)
    {
        case BASE_26MHZ:
            reg_val = DRV_Reg16(DCM_PLL_CON4);
            reg_val &= ~(0xF000);
            reg_val |= 0x0000;
            DRV_Reg16(DCM_PLL_CON4) = reg_val;
            break;
        case MCU_PLL:
            reg_val = DRV_Reg16(DCM_PLL_CON4);
            reg_val &= ~(0xF000);
            reg_val |= 0x1000;
            DRV_Reg16(DCM_PLL_CON4) = reg_val;
            break;
        default:
            ASSERT(0);
            break;
    }
   /* restore IRQ */
   RestoreIRQMask(saved);
}

void reduce_PLL_usage(kal_bool enable)
{
    kal_uint16 reg_val = 0;
    kal_uint32 saved = 0;

    if(enable)
    {
        /* reduce PLL usage */
        dynamic_switch_MCU(BASE_26MHZ);
        /* disable IRQ */
        saved = SaveAndSetIRQMask();
        /* set MPLL to 624Mhz */
        reg_val = DRV_Reg16(DCM_MPLL_CON0);
        reg_val &= ~(0x7F00);
        reg_val |= 0x7100;
        DRV_Reg16(DCM_MPLL_CON0) = reg_val;
        reg_val = DRV_Reg16(DCM_MPLL_CON0);
        reg_val |= 0x0001;
        DRV_Reg16(DCM_MPLL_CON0) = reg_val;
        /* restore IRQ */
        RestoreIRQMask(saved);
        /* wait for 30us */
        ust_busy_wait(30);
        /* enable MPLL clock divider */
        reg_val = DRV_Reg16(DCM_CLKSW_PLLCNTEN_CON);
        reg_val |= 0x80;
        DRV_Reg16(DCM_CLKSW_PLLCNTEN_CON) = reg_val;

        dynamic_switch_MCU(MCU_PLL);
        dynamic_switch_DSP(MCU_PLL);
        dynamic_switch_EMI(MCU_PLL);

        /* disable EMI and DSP PLL */
        /* disable IRQ */
        saved = SaveAndSetIRQMask();
        reg_val = DRV_Reg16(DCM_DPLL_CON0);
        reg_val &= ~(0x0001);
        DRV_Reg16(DCM_DPLL_CON0) = reg_val;
        reg_val = DRV_Reg16(DCM_EPLL_CON0);
        reg_val &= ~(0x0001);
        DRV_Reg16(DCM_EPLL_CON0) = reg_val;
        /* restore IRQ */
        RestoreIRQMask(saved);
    }
    else
    {
        /* use all PLLs */

        /* enable EMI and DSP PLL */
        /* disable IRQ */
        saved = SaveAndSetIRQMask();
        reg_val = DRV_Reg16(DCM_DPLL_CON0);
        reg_val |= 0x0001;
        DRV_Reg16(DCM_DPLL_CON0) = reg_val;
        reg_val = DRV_Reg16(DCM_EPLL_CON0);
        reg_val |= 0x0001;
        DRV_Reg16(DCM_EPLL_CON0) = reg_val;
        /* restore IRQ */
        RestoreIRQMask(saved);

        dynamic_switch_MCU(BASE_26MHZ);
        saved = SaveAndSetIRQMask();
        /* set MPLL to 598Mhz */
        reg_val = DRV_Reg16(DCM_MPLL_CON0);
        reg_val &= ~(0x7F00);
        reg_val |= 0x6F00;
        DRV_Reg16(DCM_MPLL_CON0) = reg_val;
        reg_val = DRV_Reg16(DCM_MPLL_CON0);
        reg_val |= 0x0001;
        DRV_Reg16(DCM_MPLL_CON0) = reg_val;
        /* restore IRQ */
        RestoreIRQMask(saved);
        /* wait for 30us */
        ust_busy_wait(30);
        /* switch to original PLL */
        dynamic_switch_MCU(MCU_PLL);
        dynamic_switch_DSP(DSP_PLL);
        dynamic_switch_EMI(EMI_PLL);
        /* disable MPLL clock divider */
        reg_val = DRV_Reg16(DCM_CLKSW_PLLCNTEN_CON);
        reg_val &= ~(0x80);
        DRV_Reg16(DCM_CLKSW_PLLCNTEN_CON) = reg_val;
    }
    return;
}
#else /* MT6276_S01 or latter */

void dynamic_switch_BUS(pll_source_t pll_type, kal_bool fhop)
{
    kal_uint16 reg_val = 0;
    kal_uint32 saved = 0;

    /* disable IRQ */
    saved = SaveAndSetIRQMask();
    switch(pll_type)
    {
        case MCU_PLL:
            if(fhop)
            {
                /* set bus to 26Mhz */
                reg_val = DRV_Reg16(DCM_FHCTL_CLKSEL_CON1);
                reg_val &= 0xFF00;
                DRV_Reg16(DCM_FHCTL_CLKSEL_CON1) = reg_val;

                /* set MCU PLL divider 1 as /6 */
                reg_val = *DCM_CLKSW_PLLDIV_CON0;
                reg_val &= 0x0FFF;
                reg_val |= 0x7000;
                *DCM_CLKSW_PLLDIV_CON0 = reg_val;

                /* switch to MCU PLL */
                reg_val = DRV_Reg16(DCM_FHCTL_CLKSEL_CON1);
                reg_val |= 0x0011;
                DRV_Reg16(DCM_FHCTL_CLKSEL_CON1) = reg_val;
            }
            else
            {
                /* set MCU PLL divider for bus */
                reg_val = DRV_Reg16(DCM_CLKSW_PLLDIV_CON0);
                reg_val &= ~(0x0E00);
                reg_val |= 0x0800;
                DRV_Reg16(DCM_CLKSW_PLLDIV_CON0) = reg_val;
                /* switch to MCU PLL */
                reg_val = DRV_Reg16(DCM_PLL_CON4);
                reg_val &= ~(0x0F00);
                reg_val |= 0x0400;
                DRV_Reg16(DCM_PLL_CON4) = reg_val;
            }
            break;
        default:
            ASSERT(0);
            break;
    }
   /* restore IRQ */
   RestoreIRQMask(saved);
}

void dynamic_switch_EMI(pll_source_t pll_type, kal_bool fhop)
{
    kal_uint16 reg_val = 0;
    kal_uint32 saved = 0;

    /* disable IRQ */
    saved = SaveAndSetIRQMask();
    switch(pll_type)
    {
        case MCU_PLL:
            /* set MCU PLL divider for EMI */
            reg_val = DRV_Reg16(DCM_CLKSW_PLLDIV_CON0);
            reg_val &= ~(0x38);
            reg_val |= 0x20;
            DRV_Reg16(DCM_CLKSW_PLLDIV_CON0) = reg_val;
            break;
        case EMI_PLL:
            /* do nothing */
            break;
        default:
            ASSERT(0);
            break;
    }
    /* restore IRQ */
    //RestoreIRQMask(saved);

    /* block EMI request */
    /*Step 1: Disable Dummy Read*/
    *EMI_DRCT &=    ~0x1;       
    /*Step 2: Block all emi transaction*/
    *EMI_CONM =     0x003F;    
    /*Step 3: */
    *EMI_DQSE &= ~(1<<28);//Clear
    /*Step 4: Enter SDRAM self refresh mode and polling status*/
    *EMI_CONN |=    (1<<5);     
    while( ( *EMI_CONN & (1<<7) ) == 0 );
    /*Step 4: Wait for EMI idle bit assert*/
    while( ( *EMI_CONN & (1<<10) ) == 0 );

    switch(pll_type)
    {
        case MCU_PLL:
            /* switch to MCU PLL */
            if(fhop)
            {
                reg_val = DRV_Reg16(DCM_FHCTL_CLKSEL_CON1);
                reg_val &= 0x00FF;
                reg_val |= 0x2200;
                DRV_Reg16(DCM_FHCTL_CLKSEL_CON1) = reg_val;
            }
            else
            {
                reg_val = DRV_Reg16(DCM_PLL_CON4);
                reg_val &= ~(0x00F0);
                reg_val |= 0x0020;
                DRV_Reg16(DCM_PLL_CON4) = reg_val;
            }
            break;
        case EMI_PLL:
            /* switch to EMI PLL */
            if(fhop)
            {
                reg_val = DRV_Reg16(DCM_FHCTL_CLKSEL_CON1);
                reg_val &= 0x00FF;
                reg_val |= 0x1100;
                DRV_Reg16(DCM_FHCTL_CLKSEL_CON1) = reg_val;
            }
            else
            {
                reg_val = DRV_Reg16(DCM_PLL_CON4);
                reg_val &= ~(0x00F0);
                reg_val |= 0x0010;
                DRV_Reg16(DCM_PLL_CON4) = reg_val;
            }
            break;
        default:
            ASSERT(0);
            break;
    }
    /* restore IRQ */
    //RestoreIRQMask(saved);

    /* un-block EMI request */
    /*Step 9: Unmask EMI access for all master*/
    *EMI_CONM = 0x0000;

    /*Step 10: Exit SDRAM self refresh mode and polling status*/
    *EMI_CONN &=    ~(1<<5);
    while( ( *EMI_CONN & (1<<7) ) == 1 );

    /*Step 11: Enable dummy Read*/
    *EMI_DRCT |=    0x1; 

    /* restore IRQ */
    RestoreIRQMask(saved);

    /* wait for 20us */
    ust_busy_wait(20);

}

void reduce_PLL_usage(kal_bool enable)
{
    register kal_uint32 reg_val = 0;
    register kal_uint32 mpll_con0_val = 0;
    register kal_uint32 pll_con5_val = 0;
    register kal_uint32 pll_con4_val = 0;
    register kal_uint32 clksel_con1_val =0;
    register kal_uint32 saved = 0;

    if(enable)
    {
        if(!pll_save_mode_enabled)
        {
            /* disable IRQ */
            saved = SaveAndSetIRQMask();
#if defined(__SWTICH_OFF_EPLL__)
            *DCM_CLKSW_PLLDIV_CON0 = 0x0827; /* skip DIV3, DIV4=/2, DIV2=/2*/
#else
            *DCM_CLKSW_PLLDIV_CON0 = 0x083F; /* skip DIV3, DIV4=/6, DIV2=/2*/
#endif
            *DCM_CLKSW_PLLDIV_CON1 = 0x7000; /* DIV6=/6 */
            *DCM_CLKSW_PLLCNTEN_CON = 0x0008;
             RestoreIRQMask(saved);

            saved = SaveAndSetIRQMask();
            L1D_INFORM_DSP_WAKEUP(); /* tell Fcore to wake up and lock DSP sleep mode */
            RestoreIRQMask(saved);

            saved = SaveAndSetIRQMask();

            /* read register contetn into local variable */
            clksel_con1_val = DRV_Reg32(DCM_FHCTL_CLKSEL_CON1);
            mpll_con0_val = *DCM_MPLL_CON0;
            pll_con4_val = *DCM_PLL_CON4;
            pll_con5_val = *DCM_PLL_CON5;

            /* change DPLL to 26Mhz */
            reg_val = *DCM_DPLL_CON0;
            reg_val &= 0x00FF;
            reg_val |= 0x0200;
            *DCM_DPLL_CON0 = reg_val;

            /* change FPLL to 26Mhz */
            reg_val = *DCM_FPLL_CON0;
            reg_val &= 0x00FF;
            reg_val |= 0x0200;
            *DCM_FPLL_CON0 = reg_val;

            /* change MPLL to 26Mhz */
            mpll_con0_val &= 0x00FF;
            mpll_con0_val |= 0x0200;
            *DCM_MPLL_CON0 = mpll_con0_val;

            /* switch DSP to MPLL_DIV2 and MCU to MPLL_DIV3 */
            pll_con4_val &= 0x00FF;
            pll_con4_val |= 0x2200;
            *DCM_PLL_CON4 = pll_con4_val;
            /* frequency hopping part */
            DRV_Reg32(DCM_FHCTL_CLKSEL_CON0) = 0x2222;

            /* set bus to 26Mhz */
            pll_con5_val &= 0x0FFF;
            *DCM_PLL_CON5 = pll_con5_val;
            /* frequency hopping part */
            clksel_con1_val &= 0xFF00;
            DRV_Reg32(DCM_FHCTL_CLKSEL_CON1) = clksel_con1_val;

            /* choose MPLL divider1 as 5 */
            reg_val = *DCM_CLKSW_PLLDIV_CON0;
            reg_val &= 0x0FFF;
            reg_val |= 0x6000;
            *DCM_CLKSW_PLLDIV_CON0 = reg_val;

            /* switch bus to MPLL_DIV1 */
            pll_con5_val |= 0x1000;
            *DCM_PLL_CON5 = pll_con5_val;
            /* frequency hopping part */
            clksel_con1_val |= 0x0011;
            DRV_Reg32(DCM_FHCTL_CLKSEL_CON1) = clksel_con1_val;

            /* switch MPLL to 611Mhz */
            mpll_con0_val &= 0x00FF;
            mpll_con0_val |= 0x7000;
            *DCM_MPLL_CON0 = mpll_con0_val;

            RestoreIRQMask(saved);

            saved = SaveAndSetIRQMask();
            L1D_INFORM_DSP_REENTER_SLEEP(); /* unlock DSP sleep mode */
            RestoreIRQMask(saved);

#if defined(__SWTICH_OFF_EPLL__)
            saved = SaveAndSetIRQMask();
            cp15_disable_mmu();

            /* block EMI request */
            /*Step 1: Disable Dummy Read*/
            *EMI_DRCT &= ~0x1;
            /*Step 2: Block all emi transaction*/
            *EMI_CONM =  0x003F;
            /*Step 3: */
            *EMI_DQSE &= ~(1<<28);//Clear
            /*Step 4: Enter SDRAM self refresh mode and polling status*/
            *EMI_CONN |= (1<<5);
            while( ( *EMI_CONN & (1<<7) ) == 0 );
            /*Step 4: Wait for EMI idle bit assert*/
            while( ( *EMI_CONN & (1<<10) ) == 0 );

            /* switch EMI to MPLL_DIV4 */
            reg_val = *DCM_PLL_CON4;
            reg_val &= 0xFF0F;
            reg_val |= 0x0020;
            *DCM_PLL_CON4 = reg_val;
            /* frequency hopping part */
            reg_val = DRV_Reg16(DCM_FHCTL_CLKSEL_CON1);
            reg_val &= 0x00FF;
            reg_val |= 0x2200;
            DRV_Reg16(DCM_FHCTL_CLKSEL_CON1) = reg_val;

            /* un-block EMI request */
            /*Step 9: Unmask EMI access for all master*/
            *EMI_CONM = 0x0000;

            /*Step 10: Exit SDRAM self refresh mode and polling status*/
            *EMI_CONN &=    ~(1<<5);
            while( ( *EMI_CONN & (1<<7) ) == 1 );

            /*Step 11: Enable dummy Read*/
            *EMI_DRCT |= 0x1; 
            cp15_enable_mmu();

            RestoreIRQMask(saved);
#endif

            /* disable DPLL, EPLL, and FPLL */
            saved = SaveAndSetIRQMask();
            *DCM_DPLL_CON1 |= 0x0100;
#if defined(__SWTICH_OFF_EPLL__)
            *DCM_EPLL_CON1 |= 0x0100;
#endif
            *DCM_FPLL_CON1 |= 0x0100;

            *DCM_DPLL_CON0 &= ~(0x1);
#if defined(__SWTICH_OFF_EPLL__)
            *DCM_EPLL_CON0 &= ~(0x1);
#endif
            *DCM_FPLL_CON0 &= ~(0x1);

            pll_save_mode_enabled = KAL_TRUE;
            RestoreIRQMask(saved);
        }
    }
    else
    {
        if(pll_save_mode_enabled)
        {
            saved = SaveAndSetIRQMask();
#if defined(__SWTICH_OFF_EPLL__)
            /* enable EPLL */
            *DCM_EPLL_CON0 |= 0x1;
#endif

            /* enable DPLL to 312Mhz */
            *DCM_DPLL_CON0 &= 0x00FF;
            *DCM_DPLL_CON0 |= 0x01;

            /* enable FPLL to 611Mhz */ 
            *DCM_FPLL_CON0 &= 0x00FF;
            *DCM_FPLL_CON0 |= 0x7000;
            *DCM_FPLL_CON0 |= 0x01;

            /* restore IRQ */
            RestoreIRQMask(saved);

            /* wait for 20us */
            ust_busy_wait(20);

#if defined(__SWTICH_OFF_EPLL__)
            saved = SaveAndSetIRQMask();
            cp15_disable_mmu();
            /* block EMI request */
            /*Step 1: Disable Dummy Read*/
            *EMI_DRCT &=    ~0x1;
            /*Step 2: Block all emi transaction*/
            *EMI_CONM =     0x003F;
            /*Step 3: */
            *EMI_DQSE &= ~(1<<28);//Clear
            /*Step 4: Enter SDRAM self refresh mode and polling status*/
            *EMI_CONN |=    (1<<5);     
            while( ( *EMI_CONN & (1<<7) ) == 0 );
            /*Step 4: Wait for EMI idle bit assert*/
            while( ( *EMI_CONN & (1<<10) ) == 0 );

            /* switch EMI to EPLL */
            reg_val = *DCM_PLL_CON4;
            reg_val &= 0xFF0F;
            reg_val |= 0x0010;
            *DCM_PLL_CON4 = reg_val;
            /* frequency hopping part */
            reg_val = DRV_Reg16(DCM_FHCTL_CLKSEL_CON1);
            reg_val &= 0x00FF;
            reg_val |= 0x1100;
            DRV_Reg16(DCM_FHCTL_CLKSEL_CON1) = reg_val;

            /* un-block EMI request */
            /*Step 9: Unmask EMI access for all master*/
            *EMI_CONM = 0x0000;

            /*Step 10: Exit SDRAM self refresh mode and polling status*/
            *EMI_CONN &=    ~(1<<5);
            while( ( *EMI_CONN & (1<<7) ) == 1 );

            /*Step 11: Enable dummy Read*/
            *EMI_DRCT |= 0x1; 

            cp15_enable_mmu();
            /* restore IRQ */
            RestoreIRQMask(saved);
#endif

            saved = SaveAndSetIRQMask();
            L1D_INFORM_DSP_WAKEUP(); /* tell Fcore to wake up and lock DSP sleep mode */
            RestoreIRQMask(saved);

            saved = SaveAndSetIRQMask();
            /* read register contetn into local variable */
            clksel_con1_val = DRV_Reg32(DCM_FHCTL_CLKSEL_CON1);
            pll_con4_val = *DCM_PLL_CON4;
            pll_con5_val = *DCM_PLL_CON5;

            /* enable MPLL to 26Mhz */
            mpll_con0_val = *DCM_MPLL_CON0;
            mpll_con0_val &= 0x00FF;
            mpll_con0_val |= 0x0200;
            *DCM_MPLL_CON0 = mpll_con0_val;

            /* switch DSP to DPLL and MCU to FPLL */
            pll_con4_val &= 0x00FF;
            pll_con4_val |= 0x1100;
            *DCM_PLL_CON4 = pll_con4_val;
            /* frequency hopping part */
            DRV_Reg32(DCM_FHCTL_CLKSEL_CON0) = 0x1111;

            /* switch bus to 26Mhz */
            pll_con5_val &= 0x0FFF;
            *DCM_PLL_CON5 = pll_con5_val;
            /* frequency hopping part */
            clksel_con1_val &= 0xFF00;
            DRV_Reg32(DCM_FHCTL_CLKSEL_CON1) = clksel_con1_val;

            /* skip all divider */
            *DCM_CLKSW_PLLDIV_CON0 = 0;
            *DCM_CLKSW_PLLCNTEN_CON = 0;

            /* change MPLL to 122.2Mh */
            mpll_con0_val &= 0x00FF;
            mpll_con0_val |= 0x2D00;
            *DCM_MPLL_CON0 = mpll_con0_val;

            /* wait for 20us */
            ust_busy_wait(20);

            /* switch bus to MPLL divider1 */
            pll_con5_val |= 0x1000;
            *DCM_PLL_CON5 = pll_con5_val;
            /* frequency hopping part */
            clksel_con1_val |= 0x0011;
            DRV_Reg32(DCM_FHCTL_CLKSEL_CON1) = clksel_con1_val;
            RestoreIRQMask(saved);

            saved = SaveAndSetIRQMask();
            /* change PLL back to top SM controlled mode */
            *DCM_DPLL_CON1 &= ~(0x0100);
#if defined(__SWTICH_OFF_EPLL__)
            *DCM_EPLL_CON1 &= ~(0x0100);
#endif
            *DCM_FPLL_CON1 &= ~(0x0100);

            pll_save_mode_enabled = KAL_FALSE;
            RestoreIRQMask(saved);

            saved = SaveAndSetIRQMask();
            L1D_INFORM_DSP_REENTER_SLEEP(); /* unlock DSP sleep mode */
            RestoreIRQMask(saved);
        }
    }
    return;
}

#endif /* MT6276_S00 */

#endif /* MT6276 */


#pragma arm section code

#if defined (MT6252)
#include "l1sm_public.h"
kal_bool sm_rf_sleep(void)
{
    return __6252_workaround_sm_query_rf_status__();
}
#endif //#if defined (MT6252)


#else  /* __MTK_TARGET__ */
   
#endif

