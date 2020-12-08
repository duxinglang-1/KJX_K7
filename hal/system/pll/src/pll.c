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
 *   init.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the HW initialization.
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

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#include "kal_general_types.h"
#include "reg_base.h"
#include "config_hw.h"
#include "drv_comm.h"
#include "pll.h"
#include "init.h"
#include "intrCtrl.h"
#include "drvpdn.h"
#include "custom_emi_release.h"
#include "flash_sfi_release.h"

#ifdef __MTK_TARGET__ /* should NOT be compiled on MODIS */

extern ECO_VERSION eco_version; /* only used in PLL setup */

extern int custom_DynamicClockSwitch(mcu_clock_enum clock);
extern kal_uint32 SaveAndSetIRQMask(void);
extern void RestoreIRQMask(kal_uint32);
extern kal_uint32 LockIRQ(void);
extern void RestoreIRQ(kal_uint32);

#if defined(MT6238) || defined(MT6239)
extern ECO_VERSION mt6238_version; 	/* 	ENG_E1 or ENG_E2. */
#endif	// MT6238

#if defined(MT6235) || defined(MT6235B)
extern ECO_VERSION 	mt6235_version;
#endif /* MT6235 MT6235B */

/*
 * NoteXXX:
 *    Please DO NOT place your code in the execution region EMIINITCODE.
 *    Code in this region is used for EMI/PLL initialization, and will be
 *    OVERWRITTEN after INT_InitRegions.
 */
#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE"
#endif /* __MTK_TARGET__ */

/*************************************************************************
* FUNCTION
*  INT_SetPLL
*
* DESCRIPTION
*  This function dedicates for PLL setting.
*
* CALLS
*  Non
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void INT_SetPLL(pll_init_mode mode)
{

#if defined(MT6229)
{
	kal_uint16 i;

#ifdef EXT_26M
   // 1. Power on DSP_DIV2, MCU_DIV2, and CLKSQ
   *PDN_CLR0 = 0x9800;
   // 2. Enable MCU clock divider
   *CLK_CON = 0x0008;
#elif defined (EXT_13M)
   // Power on CLKSQ
   *PDN_CLR0 = 0x0800;
#endif

   // 3. Boost MCU and DSP PLL (MDPLL) to 104MHz (MUST)
   *MPLL = 0x0087;
   *MPLL = 0x0007;
   
   // 4. Power ou MPLL
   *PDN_CLR0 = 0x4000;
   
   // 5. delay until PLL is stable, at least 50us
	for (i=0;i<0x100;i++);
   
   // 6. Define ARM(CPU, Data cache, TCM) and MCU PLL
#ifdef MCU_104M   
   // MCU and BUS clock 2:1
   *MCUCLK_CON = 0x0703;
#elif defined MCU_52M
   // MCU and BUS clock 1:1
   *MCUCLK_CON = 0x0303;
#elif defined MCU_26M
   // MCU and BUS clock 1:1
   *MCUCLK_CON = 0x0101;
#elif defined MCU_13M
   // MCU and BUS clock 1:1
   *MCUCLK_CON = 0x0000;   
#endif      

   // 7. Enable MPLL output
   *CLK_CON |= 0x0002;   
}
#endif /* MT6229 */

#if defined(MT6223)	|| defined(MT6223P)
{
	kal_uint16 i;

#ifdef EXT_26M
   // 1. Power on DSP_DIV2, MCU_DIV2, PLL and CLKSQ
   *PDN_CLR0 = 0xb800;
   // 2. Enable MCU clock divider
   *CLK_CON = 0x0002;
   
#elif defined (EXT_13M) 
   // Power on PLL and CLKSQ
   *PDN_CLR0 = 0x2800;
#endif

   // 3. Select PLL input from CLKSQ, set div_ctrl to 6 such that PLL gives 104MHz clock
   *PLL = 0xc008;
   
   // 4. Reset PLL
   *PLL = 0xc088;
   
   // 5. Select CLKSQ_DIV2_MCU to provide 13MHz
   *CLK_CON = 0x2;
   
   // 6. Define ARM(CPU, Data cache, TCM) and MCU PLL
#ifdef  MCU_52M
   // MCU and BUS clock 1:1
   *MCUCLK_CON = 0x0303;
#elif defined MCU_26M
   // MCU and BUS clock 1:1
   *MCUCLK_CON = 0x0101;
#elif defined MCU_13M
   // MCU and BUS clock 1:1
   *MCUCLK_CON = 0x0000;   
#endif      
   
   // 7. MPLL/2 nad DPLL/2 enable
   *CLK_CON = 0x3; 
   
   // 8. delay until PLL is stable, at least 50us
	for (i=0;i<0x200;i++);

   // 9. DPLLSEL = 1'b1, MPLLSEL=2'b10
   *PLL = 0xc030; // 
}
#endif   /* MT6223 	|| defined(MT6223P)*/

#if defined(MT6225)
{
	kal_uint16 i;

#ifdef EXT_26M
   // 1. Power on DSP_DIV2, MCU_DIV2, and CLKSQ
   *PDN_CLR0 = 0x9800;
   // 2. Enable MCU clock divider
   *CLK_CON = 0x0002;
#elif defined (EXT_13M)
   // Power on CLKSQ
   *PDN_CLR0 = 0x0800;
#endif

   // 3. Boost MCU and DSP PLL (MDPLL) to 104MHz (MUST)
   *PLL = 0x0080;
   *PLL = 0x0000;
   
   // 4. Power ou MPLL
   *PDN_CLR0 = 0x2000;
   
   // 5. delay until PLL is stable, at least 50us
   for (i=0;i<0x100;i++);
   
   // 6. Define ARM(CPU, Data cache, TCM) and MCU PLL
#ifdef MCU_104M   
   // MCU and BUS clock 2:1
   *MCUCLK_CON = 0x0703;
#elif defined MCU_52M
   // MCU and BUS clock 1:1
   *MCUCLK_CON = 0x0303;
#elif defined MCU_26M
   // MCU and BUS clock 1:1
   *MCUCLK_CON = 0x0101;
#elif defined MCU_13M
   // MCU and BUS clock 1:1
   *MCUCLK_CON = 0x0000;   
#endif      

   // 7. Enable MPLL output
   *PLL |= 0x0010;   
}
#endif  /* MT6225 */

#if defined(MT6253T) || defined(MT6253)
{
   unsigned int i;

#if defined(MT6253T) || defined(MT6253)
   if (ECO_E3 == eco_version) {
      /* SW workaround because PLL cannot be reset by WDT */
      /* de-select MPLL, DPLL, UPLL output in case WATCHDOG RESET */
      *PLL &= ~(0x003a);
   }
#endif /* MT6253T || MT6253 */

#if defined(EXT_26M)
   *CLK_CON = 0x00A0; // CLK_CON: power-off single-end CLKSQ 
#elif defined (EXT_13M)
   *CLK_CON = 0x0020;
#endif 
  
   // FZ, Althrough FPGA doesn't have PLL, the PLL still have to be enabled to make DCM works 
   *MPLL_CON1 |= 0x0002;// MPLL_CON1: Power on MPLL
   *MPLL_CON1 |= 0x0001;// MPLL_CON1:reset MPLL
   *MPLL_CON1 &= 0xfffe; // MPLL_CON1:reset release
	
   *UPLL_CON1 |= 0x0002;	// 0x8300_020C: Power-up UPLL
   *UPLL_CON1 |= 0x0001;	// 0x8300_020C: Reset UPLL
   *UPLL_CON1 &= 0xfffe;	// 0x8300_020C: Reset release

   for (i=0;i<1200;i++); // delay until MPLL stable
	
   *MCUCLK_CON &= 0xF0F0;	// Clear ARM_FSEL, Clear MCU_FSEL  
   *DSPCLK_CON &= 0xFF00;	// Clear DSP1_FSEL, DSP2_FSEL

   /*MT6251 clock setting*/
   //*MCUCLK_CON |= 0x3383; // MCUCLK_CON: dcm setting (ARM:52MHz, MCU:52MHz)
   //*DSPCLK_CON = *DSPCLK_CON | 0x0033; // DSPCLK_CON: DSP_CLK = 52MHz	

#if defined(MCU_104M)

   *MCUCLK_CON |= 0x3783; // MCUCLK_CON: dcm setting (ARM:104MHz, MCU:52MHz)
   *DSPCLK_CON = *DSPCLK_CON | 0x0077; // DSPCLK_CON: DSP_CLK = 104MHz

#elif defined(MCU_52M)

   *MCUCLK_CON |= 0x3383; // MCUCLK_CON: dcm setting (ARM:52MHz, MCU:52MHz)
   *DSPCLK_CON = *DSPCLK_CON | 0x0033; // DSPCLK_CON: DSP_CLK = 52MHz

#elif defined(MCU_13M)

   *MCUCLK_CON |= 0x3080; // MCUCLK_CON: dcm setting (ARM:13MHz, MCU:13MHz)
   *DSPCLK_CON = *DSPCLK_CON | 0x0000; // DSPCLK_CON: DSP_CLK = 13MHz

#endif
			
   *PLL |= 0x003a;// Select MPLL, DPLL, UPLL output

   for (i=0;i<200;i++);
	
}
#endif /* MT6253T || MT6253 */

#if defined(MT6253E) || defined(MT6253L) || defined(MT6252H)
{
    kal_uint32 i;
   /**
    * MT6253E/L PLL init sequence(not including 104MHz EMI switch sequence)
    */
    *PLL_CON1 &= ~(0x003F); // 0x8300_0204: De-select MPLL, DPLL, UPLL output in case WATCHDOG RESET
    *CLKSQ_CON0 = 0x00A0;   // 0x8300_0100: CLK_CON: power-off single-end CLKSQ 
    *CLKSQ_CON1 = 0x0008;   // 0x8300_0104: GSM_DCXO_PWR_CTRL_ENABLE=1
    *MPLL_CON1 |= 0x0002;   // 0x8300_0214: MPLL_CON1: Power on MPLL
    *MPLL_CON1 |= 0x0001;   // 0x8300_0214: MPLL_CON1:reset MPLL
    *MPLL_CON1 &= 0xFFFE;   // 0x8300_0214: MPLL_CON1:reset release
    *MPLL_CON1 &= ~(0xFF04); // 0x8300_0214: Clear RG_MPLL_FBDIV, PLL_TDMA
    *MPLL_CON1 |= 0xCE00;   // 0x8300_0214: Set MPLL frequency = 104MHz, for intel sibley PSRAM
    *UPLL_CON1 |= 0x0002;   // 0x8300_020C: Power-up UPLL
    *UPLL_CON1 |= 0x0001;   // 0x8300_020C: Reset UPLL
    *UPLL_CON1 &= 0xFFFE;   // 0x8300_020C: Reset release

    for (i = 0; i < 2000; i++);  // delay until MPLL stable 200us

    *MCUCLK_CON &= 0xF0F0;  // 0x8001_0118: CClear ARM_FSEL, Clear MCU_FSEL  
    *DSPCLK_CON &= 0xFF00;  // 0x8001_011C: Clear DSP1_FSEL, DSP2_FSEL
    *MCUCLK_CON |= 0x3783;  // 0x8001_0118: MCUCLK_CON: dcm setting (ARM:104MHz, MCU:52MHz)
    *DSPCLK_CON = *DSPCLK_CON |0x0077;  // 0x8001_011C: DSPCLK_CON: DSP_CLK = 104MHz
    *PLL_CON1 |= 0x003A;    // 0x8300_0204: Select MPLL, DPLL, UPLL output
 
}
#endif


#if defined(MT6252)

    kal_uint32 i;
   /**
    * MT6253E/L PLL init sequence(not including 104MHz EMI switch sequence)
    */
    *CLKSQ_CON0 = 0x00E0;   // 0x8300_0100: CLK_CON: power-off single-end CLKSQ 
    *CLKSQ_CON1 = 0x0008;   // 0x8300_0104: GSM_DCXO_PWR_CTRL_ENABLE=1
    
    *PLL_CON0 = 0x0000;
    *PLL_CON1 = 0x0000;

    *UPLL_CON1 |= 0x0003;
    *MPLL_CON1 |= 0x0003;
    *SPLL_CON1 |= 0x0003;

    *UPLL_CON1 &= (~0x0001);
    *MPLL_CON1 &= (~0x0001);
    *SPLL_CON1 &= (~0x0001);
	
    for (i = 0; i < 2000; i++);  // delay until MPLL stable 200us

    *PLL_CON0 = 0x0002;
    *PLL_CON1 = 0x003A;
	
#endif 


#if defined(MT6235) || defined(MT6235B)
{
		kal_uint16 i;

    *RAMSCR_11_CON = *RAMSCR_11_CON & ~(0x1<<12); //[12]
    *RAMSCR_16_CON = *RAMSCR_16_CON & ~(0x1<<14); //[14]
    *RAMSCR_17_CON = *RAMSCR_16_CON & ~(0x4444);			         //[2 6 10 14]
	   for (i=0;i<0x100;i++);   


	   // 1. Power on DSP_DIV2, MPLL, DPLL, MCU_DIV2, and CLKSQ
	   *PDN_CON = 0x0000;
	   
	   // 2. Enable MCU/DSP clock divider
#ifdef EXT_26M
		*CLK_CON = 0x0083;
#elif defined (EXT_13M)
	   	*CLK_CON = 0x0003;
#endif

	   // 3. Reset PLL.
	   *PLL = 0x0080;
	   
	   // 4. Release the reset, wait for PLL output stable.
	   *PLL = 0x0000;

	   // 5. delay until PLL is stable, at least 50us
	   for (i=0;i<0x100;i++);    
	   
	   // 6. Select PLL output for M/U/D-PLL.
	   *PLL = 0x0070;

	   // 7. Define ARM(CPU, Data cache, TCM) and MCU Clock.
	   if(ECO_E1 == eco_version)
	   {
#ifdef MCU_208M   
		*MCUCLK_CON = 0x7F37;		
#elif defined MCU_104M   
		*MCUCLK_CON = 0x7737;
#elif defined MCU_52M
		*MCUCLK_CON = 0x7333;
#elif defined MCU_26M
		*MCUCLK_CON = 0x7111;
#elif defined MCU_13M
		*MCUCLK_CON = 0x7000;   
#endif  	   
	   }
	   else if(ECO_E2 <= eco_version)
	   {
#ifdef MCU_208M   
			*MCUCLK_CON = 0x7F37;		
#elif defined MCU_104M   
			*MCUCLK_CON = 0x7737;
#elif defined MCU_52M
			*MCUCLK_CON = 0x3333;
#elif defined MCU_26M
			*MCUCLK_CON = 0x1111;
#elif defined MCU_13M
			*MCUCLK_CON = 0x0000;   
#endif  	   
	   }
}

#endif  /* MT6235 || MT6235B */


#if defined(MT6238) || defined(MT6239)
{
		kal_uint16 i;

    *RAMSCR_11_CON = *RAMSCR_11_CON & 0x03FF; //[15:10]
    *RAMSCR_17_CON = 0x0;			         //[15:00]
    *RAMSCR_16_CON = *RAMSCR_16_CON & 0x3FFF; //[15:14]
	   for (i=0;i<0x100;i++);   
    
	   // 1. Power on DSP_DIV2, MPLL, DPLL, MCU_DIV2, and CLKSQ
	   *PDN_CON = 0x0000;
	   
	   // 2. Enable MCU/DSP clock divider
#ifdef EXT_26M
		*CLK_CON = 0x0083;
#elif defined (EXT_13M)
	   	*CLK_CON = 0x0003;
#endif

	   // 3. Reset PLL.
	   *PLL = 0x0080;
	   
	   // 4. Release the reset, wait for PLL output stable.
	   *PLL = 0x0000;

	   // 5. delay until PLL is stable, at least 50us
	   for (i=0;i<0x100;i++);    
	   
	   // 6. Select PLL output for M/U/D-PLL.
	   *PLL = 0x0070;

	   // 7. Define ARM(CPU, Data cache, TCM) and MCU Clock.

	   if(ENG_E1 == eco_version)
	   {
#ifdef MCU_208M   
		*MCUCLK_CON = 0x7F37;		
#elif defined MCU_104M   
		*MCUCLK_CON = 0x7737;
#elif defined MCU_52M
		*MCUCLK_CON = 0x7333;
#elif defined MCU_26M
		*MCUCLK_CON = 0x7111;
#elif defined MCU_13M
		*MCUCLK_CON = 0x7000;   
#endif  	   
	   }
	   else if(ENG_E2 <= eco_version)
	   {
#ifdef MCU_208M   
			*MCUCLK_CON = 0x7F37;		
#elif defined MCU_104M   
			*MCUCLK_CON = 0x7737;
#elif defined MCU_52M
			*MCUCLK_CON = 0x3333;
#elif defined MCU_26M
			*MCUCLK_CON = 0x1111;
#elif defined MCU_13M
			*MCUCLK_CON = 0x0000;   
#endif  	   
	   }
}

#endif  /* MT6238 || MT6239  */

#if defined(TK6516)
{          
        /* DSP working clock choosing, also need change define in l1/l1d/l1d_def.h */
        //#define DPLL_26MHZ
        #define DPLL_104MHZ
        //#define DPLL_130MHZ
        
        //#define APLL_26MHZ
        //#define APLL_104MHZ
        #define APLL_208MHZ
        
        //#define CEVAPLL_156MHZ
        //#define CEVAPLL_208MHZ

#if !defined(EXT_26M)
        #error TK6516/MT6516 supports 26MHz oscillator only!
#endif

#if defined(MCU_104M)
        #if defined(APLL_26MHZ)
            #error APLL must greater or equal to MPLL!
        #endif
        #if defined(DPLL_26MHZ)
            #error DPLL_26MHZ only works under MCU_13M!
        #endif
#elif defined(MCU_52M)
        #error TK6516/MT6516 does not support MCU_52M!
#elif defined(MCU_26M)
        #error TK6516/MT6516 does not support MCU_26M!
#elif defined(MCU_13M)
        #if defined(DPLL_104MHZ) || defined(DPLL_130MHZ)
            #error DPLL_104MHZ or DPLL_130MHZ only works under MCU_104M!
        #endif
#endif

        #define MD_CONFIG_APB_CON  ((volatile UINT16P)0x811A0000)
        #define PLL_CLKSQ_base     0xF0060000L
        #define PLL                ((volatile UINT16P)(PLL_CLKSQ_base+0x000))
        #define PLL2               ((volatile UINT16P)(PLL_CLKSQ_base+0x004))
        #define PLL3               ((volatile UINT16P)(PLL_CLKSQ_base+0x060))
        #define APLL               ((volatile UINT16P)(PLL_CLKSQ_base+0x018))
        #define APLL2              ((volatile UINT16P)(PLL_CLKSQ_base+0x01C))
        #define CLK_CON            ((volatile UINT16P)(PLL_CLKSQ_base+0x028))
        #define PDN_CON            ((volatile UINT16P)(PLL_CLKSQ_base+0x02C))
        #define CEVAPLL            ((volatile UINT16P)(PLL_CLKSQ_base+0x030))
        #define CEVAPLL2           ((volatile UINT16P)(PLL_CLKSQ_base+0x034))
      
        #if defined(__SMART_PHONE_MODEM__)
      
            return;
         
        #else
      
        kal_uint32 i;
        volatile kal_uint16 tmp16;
    
        // Open channel to AP 0x80000000
        *MD_CONFIG_APB_CON = 0x0008;
    
        /********************* Power on PLLs *********************/

        // 1. Power on DSP_DIV2, MCU_DIV2, AP_DIV2 and CLKSQ
        *PDN_CON        &= (~0xD800);

#if defined(MCU_104M)
        // Power on MPLL 
        *PDN_CON        &= (~0x2000);
#endif

#if defined(APLL_104MHZ) || defined(APLL_208MHZ)
        // Power on APLL 
        *APLL2          &= (~0x0001);
        // Enable directly program APLL_DIVCTRL and APLL_DIGDIV 
        *APLL2          |= 0x2000;
#endif

#if defined(CEVAPLL_156MHZ) || defined(CEVAPLL_208MHZ)
        // Power on CEVAPLL 
        *CEVAPLL2       &= (~0x0001);
#endif

	    /********************* PLL Set DIVCTRL *********************/

#if defined(MCU_104M)
	    // Set DPLL_DIVCTRL (MPLL_DIVCTRL is always set to 0xE000 to generate 624MHZ clock) 
        tmp16 = (*PLL2&(~0x0F00));
#if defined(DPLL_104MHZ)
	    *PLL2           = (tmp16|0x0200);
#elif defined(DPLL_130MHZ)
	    *PLL2           = (tmp16|0x0300);
#endif
#endif
    
        // AP clock vs volt table 
        // 96   126  162  198  234  269  303  (MHz)
        // 0.9  1.0  1.1  1.2  1.3  1.4  1.5  (Volt) 

	    // Set APLL (ARM9) DIVCTRL 
        tmp16 = (*APLL&(~0x07E0));
#if defined(APLL_104MHZ)
	    *APLL           = (tmp16|0x00C0);
#elif defined(APLL_208MHZ)
	    *APLL           = (tmp16|0x01C0);
#endif
    
	    // Set CEVAPLL DIVCTRL 
	    tmp16 = (*CEVAPLL&(~0x07E0));
#if defined(CEVAPLL_156MHZ)
	    *CEVAPLL        = (tmp16|0x0140);
#elif defined(CEVAPLL_208MHZ)
	    *CEVAPLL        = (tmp16|0x01C0);
#endif

	    /********************* PLL Reset *********************/

#if defined(MCU_104M)
	    // Reset MPLL (ARM7 and bus) 
	    *PLL            |= 0x0080;
	    // Reset DPLL (DSP) 
	    *PLL2           |= 0x0080;
	    // Reset UPLL (USB)
	    *PLL3           |= 0x0080;
#endif
    
#if defined(APLL_104MHZ) || defined(APLL_208MHZ)
	    // Reset APLL (ARM9) 
	    *APLL           |= 0x0800;
#endif
    
#if defined(CEVAPLL_156MHZ) || defined(CEVAPLL_208MHZ)
	    // Reset CEVAPLL 
	    *CEVAPLL        |= 0x0800;
#endif

        /********************* PLL Reset Release *********************/
 
#if defined(MCU_104M)
        // MPLL Reset Release 
        *PLL            &= (kal_uint16)(~0x0080);
        // DPLL Reset Release 
        *PLL2           &= (kal_uint16)(~0x0080);
        // UPLL Reset Release 
        *PLL3           &= (kal_uint16)(~0x0080);
#endif

#if defined(APLL_104MHZ) || defined(APLL_208MHZ)
        // APLL Reset Release 
        *APLL           &= (kal_uint16)(~0x0800);
#endif

#if defined(CEVAPLL_156MHZ) || defined(CEVAPLL_208MHZ)
        // CEVAPLL Reset Release 
        *CEVAPLL        &= (kal_uint16)(~0x0800);
#endif

        // Delay until PLL is stable, at least 50us
        for (i=0;i<1316;i++);	// 26MHz->1cycle=0.038us  50/0.038=1316 cycles

        /********************* PLL Path Select *********************/

#if defined(MCU_104M)
        // Select UPLL, MPLL, DPLL clock source 
        tmp16 = (kal_uint16)(*PLL&(~0x0078));
        *PLL            |= 0x0070;
#endif

#if defined(APLL_104MHZ) || defined(APLL_208MHZ)
        // Select APLL clock source
        tmp16 = (kal_uint16)(*APLL2&(~0xC000));
        *APLL2          |= 0x8000;
#endif
      
      #endif //__MD_STANDALONE__
}
#endif /* TK6516 */

#ifdef __UBL__

#if defined(MT6516)
{
    kal_uint16 i;

#if defined(__APPLICATION_PROCESSOR__)
/*
D.S SD:0x80060010 %LE %WORD 0x001e  ; power-on MPLL(DPLL), UPLL
D.S SD:0x80060064 %LE %WORD 0x001f  ; power-on CEVAPLL 
D.S SD:0x80060014 %LE %WORD 0x0083  ; switch to 13MHz for PLL input frequency
; After power-on PLL.....
D.S SD:0x80060030 %LE %WORD 0x0080  ; reset UPLL
D.S SD:0x80060020 %LE %WORD 0x0080  ; reset MPLL
D.S SD:0x80060060 %LE %WORD 0x0800  ; reset CEVAPLL
D.S SD:0x80060030 %LE %WORD 0x0000  ; release UPLL reset
D.S SD:0x80060020 %LE %WORD 0x0000  ; release MPLL reset
D.S SD:0x80060060 %LE %WORD 0x0000  ; release CEVAPLL reset
wait 1.ms
; enable FMCU_2X_DIV_EN & FMCU_DIV_EN 
D.S SD:0x80001204 %LE %WORD 0x03E0
wait 1.ms
; select PLL outputs
D.S SD:0x80060014 %LE %WORD 0x00f3
wait 1.ms
*/
    DRV_WriteReg16(0x80060010, 0x001E);
    DRV_WriteReg16(0x80060064, 0x001F);
    DRV_WriteReg16(0x80060014, 0x0083);
    // After power-on PLL.....
    DRV_WriteReg16(0x80060030, 0x0080);
    DRV_WriteReg16(0x80060020, 0x0080);
    DRV_WriteReg16(0x80060060, 0x0800);
    DRV_WriteReg16(0x80060030, 0x0000);
    DRV_WriteReg16(0x80060020, 0x0000);
    DRV_WriteReg16(0x80060060, 0x0000);
    // Delay 1ms until PLL is stable while 26MHz
    // assume 1 loop cost 13T
    #define MINI_SECOND_LOOP_COUNTER_UNDER_26MHZ   (1999)
    for(i=MINI_SECOND_LOOP_COUNTER_UNDER_26MHZ;i>0;i--);

    // enable FMCU_2X_DIV_EN & FMCU_DIV_EN 
    cp15_enable_icache();
    DRV_Reg16(0x80001204) |= 0x0300;
    while( (DRV_Reg16(0x80001204) & 0x0300) != 0x0300);
    cp15_disable_icache();

    // Delay 1ms until PLL is stable while 26MHz
    for(i=MINI_SECOND_LOOP_COUNTER_UNDER_26MHZ;i>0;i--);
    // select PLL outputs
    DRV_WriteReg16(0x80060014, 0x00F3);
    // Delay 1ms until PLL is stable while 26MHz
    for(i=MINI_SECOND_LOOP_COUNTER_UNDER_26MHZ;i>0;i--);

#endif /*__APPLICATION_PROCESSOR__*/
}
#endif /* MT6516 */

#else

#if defined(MT6516) && defined(__APPLICATION_PROCESSOR__)
{
    #define AP2MD_BACKDOOR      ((volatile UINT16P)0x8003A000)
    #define AP_SLEEP_CON        ((volatile UINT16P)0x80001204)
    #define MD_MCUCLK_CON       ((volatile UINT16P)0xF0010208)
    #define PLL_CLKSQ_base      0x80060000

	 
    #define PDN_CON             ((volatile UINT16P)(PLL_CLKSQ_base+0x0010))
    #define CLK_CON             ((volatile UINT16P)(PLL_CLKSQ_base+0x0014))
    #define MPLL                ((volatile UINT16P)(PLL_CLKSQ_base+0x0020))
    #define MPLL2               ((volatile UINT16P)(PLL_CLKSQ_base+0x0024))
    #define UPLL                ((volatile UINT16P)(PLL_CLKSQ_base+0x0030))
    #define UPLL2               ((volatile UINT16P)(PLL_CLKSQ_base+0x0034))
    #define CPLL                ((volatile UINT16P)(PLL_CLKSQ_base+0x0038))
    #define CPLL2               ((volatile UINT16P)(PLL_CLKSQ_base+0x003C))
    #define TPLL                ((volatile UINT16P)(PLL_CLKSQ_base+0x0040))
    #define TPLL2               ((volatile UINT16P)(PLL_CLKSQ_base+0x0044))
    #define CPLL3               ((volatile UINT16P)(PLL_CLKSQ_base+0x0048))
    #define PLL_RES_CON0        ((volatile UINT16P)(PLL_CLKSQ_base+0x004C))
    #define PLL_BIAS            ((volatile UINT16P)(PLL_CLKSQ_base+0x0050))
    #define MCPLL               ((volatile UINT16P)(PLL_CLKSQ_base+0x0058))
    #define MCPLL2              ((volatile UINT16P)(PLL_CLKSQ_base+0x005C))
    #define CEVAPLL             ((volatile UINT16P)(PLL_CLKSQ_base+0x0060))
    #define CEVAPLL2            ((volatile UINT16P)(PLL_CLKSQ_base+0x0064))
    #define PLL_IDN             ((volatile UINT16P)(PLL_CLKSQ_base+0x0070))
    #define XOSC32_AC_CON       ((volatile UINT16P)(PLL_CLKSQ_base+0x007C))

    kal_uint32 i;
    DCL_HANDLE handle;

    init_burnin_gpio();

    //GPIO_WriteIO(KAL_TRUE, 137);
    handle = DclGPIO_Open(DCL_GPIO, 137);
    DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, 0);
    DclGPIO_Close(handle);
    
    //GPIO_WriteIO(KAL_TRUE, 138);
    handle = DclGPIO_Open(DCL_GPIO, 138);
    DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, 0);
    DclGPIO_Close(handle);
    
    //GPIO_WriteIO(KAL_TRUE, 139);
    handle = DclGPIO_Open(DCL_GPIO, 139);
    DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, 0);
    DclGPIO_Close(handle);
    
    //GPIO_WriteIO(KAL_TRUE, 140);
    handle = DclGPIO_Open(DCL_GPIO, 140);
    DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, 0);
    DclGPIO_Close(handle);
    
    //GPIO_WriteIO(KAL_TRUE, 141);  
    handle = DclGPIO_Open(DCL_GPIO, 141);
    DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, 0);
    DclGPIO_Close(handle);
    
    //GPIO_WriteIO(KAL_TRUE, 142);
    handle = DclGPIO_Open(DCL_GPIO, 142);
    DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, 0);
    DclGPIO_Close(handle);
    

    // set backdoor     
    *AP2MD_BACKDOOR = 0x8;


    // make sure PLL is not turn on 
    if( 0x00f3 != *CLK_CON )
    {

    // disable all the interrupts 
    *IRQ_MASKL = 0xFFFFFFFF;
    *IRQ_MASKH = 0xFFFFFFFF;
    *IRQ_SENSL = 0xFFFFFFFF;
    *IRQ_SENSH = 0xFFFFFFFF;

    *AP_SLEEP_CON &=  ~(0x1 << 5); // give CEVA pll
    *PDN_CON   = 0x1e;	  // power-on MPLL(DPLL), UPLL
    *CEVAPLL2	= 0x1f;	   // power-on CEVAPLL
    *CLK_CON   = 0x83;	  // switch to 13MHz for PLL input frequency
    *MD_MCUCLK_CON |= 0x0010;  // set ARM7 MCU to 104MHz
    // After power-on PLL.....
    *UPLL = 0x0080; // reset UPLL
    *MPLL = 0x0080; // reset MPLL
    *CEVAPLL = 0x0800; // reset CEVAPLL
    *UPLL = 0x0000; // release UPLL reset
    *MPLL = 0x0000; // release MPLL reset
    *CEVAPLL = 0x0000; // release CEVAPLL reset


    // enable instruction cache to avoid ARM9 MCU access bus 
    cp15_enable_icache();


    // enable FMCU_2X_DIV_EN & FMCU_DIV_EN 
    // NOTICE!! this setting can only apply while bus is idle at least 1T! 
    // therefore, enable icache to avoid ARM9 MCU access bus during the polling loop 
    *AP_SLEEP_CON |= 0x0300;
    while(( ((*AP_SLEEP_CON) & 0x0300) != 0x0300));

    // restore previous condition 
    cp15_disable_icache();

    for (i=0;i<200;i++);
    *CLK_CON = 0x00f3; // select PLL outputs
    
    for (i=0;i<200;i++);

    //GPIO_WriteIO(KAL_FALSE, 137);
    handle = DclGPIO_Open(DCL_GPIO, 137);
    DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
    DclGPIO_Close(handle);
    
    //GPIO_WriteIO(KAL_FALSE, 138);
    handle = DclGPIO_Open(DCL_GPIO, 138);
    DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
    DclGPIO_Close(handle);
    
    //GPIO_WriteIO(KAL_FALSE, 139);
    handle = DclGPIO_Open(DCL_GPIO, 139);
    DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
    DclGPIO_Close(handle);
    
    //GPIO_WriteIO(KAL_FALSE, 140);
    handle = DclGPIO_Open(DCL_GPIO, 140);
    DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
    DclGPIO_Close(handle);
    
    //GPIO_WriteIO(KAL_FALSE, 141);  
    handle = DclGPIO_Open(DCL_GPIO, 141);
    DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
    DclGPIO_Close(handle);
    
    //GPIO_WriteIO(KAL_FALSE, 142);
    handle = DclGPIO_Open(DCL_GPIO, 142);
    DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
    DclGPIO_Close(handle);
    
    }
}
#endif

#if defined(MT6516) && !defined(__APPLICATION_PROCESSOR__)
{          
        /* DSP working clock choosing, also need change define in l1/l1d/l1d_def.h */
        //#define DPLL_26MHZ
        #define DPLL_104MHZ
        //#define DPLL_130MHZ
        
        //#define APLL_26MHZ
        //#define APLL_104MHZ
        //#define APLL_208MHZ
	 #define APLL_416MHZ
        
        //#define CEVAPLL_156MHZ
        //#define CEVAPLL_208MHZ

#if !defined(EXT_26M)
        #error TK6516/MT6516 supports 26MHz oscillator only!
#endif

#if defined(MCU_104M)
        #if defined(APLL_26MHZ)
            #error APLL must greater or equal to MPLL!
        #endif
        #if defined(DPLL_26MHZ)
            #error DPLL_26MHZ only works under MCU_13M!
        #endif
#elif defined(MCU_52M)
        #error TK6516/MT6516 does not support MCU_52M!
#elif defined(MCU_26M)
        #error TK6516/MT6516 does not support MCU_26M!
#elif defined(MCU_13M)
        #if defined(DPLL_104MHZ) || defined(DPLL_130MHZ)
            #error DPLL_104MHZ or DPLL_130MHZ only works under MCU_104M!
        #endif
#endif

        #define MD_CONFIG_APB_CON  ((volatile UINT16P)0x811A0000)
	 #define AP_SLEEP_CON  ((volatile UINT16P)0xF0001204)
        #define PLL_CLKSQ_base     0xF0060000L
	 
        #define PDN_CON                ((volatile UINT16P)(PLL_CLKSQ_base+0x0010))
	 #define CLK_CON                ((volatile UINT16P)(PLL_CLKSQ_base+0x0014))
	 #define MPLL                ((volatile UINT16P)(PLL_CLKSQ_base+0x0020))
	 #define MPLL2                ((volatile UINT16P)(PLL_CLKSQ_base+0x0024))
	 #define UPLL                ((volatile UINT16P)(PLL_CLKSQ_base+0x0030))
	 #define UPLL2                ((volatile UINT16P)(PLL_CLKSQ_base+0x0034))
	 #define CPLL                ((volatile UINT16P)(PLL_CLKSQ_base+0x0038))
	 #define CPLL2                ((volatile UINT16P)(PLL_CLKSQ_base+0x003C))
	 #define TPLL                ((volatile UINT16P)(PLL_CLKSQ_base+0x0040))
	 #define TPLL2                ((volatile UINT16P)(PLL_CLKSQ_base+0x0044))
	 #define CPLL3                ((volatile UINT16P)(PLL_CLKSQ_base+0x0048))
	 #define PLL_RES_CON0                ((volatile UINT16P)(PLL_CLKSQ_base+0x004C))
	 #define PLL_BIAS                ((volatile UINT16P)(PLL_CLKSQ_base+0x0050))
	 #define MCPLL                ((volatile UINT16P)(PLL_CLKSQ_base+0x0058))
	 #define MCPLL2                ((volatile UINT16P)(PLL_CLKSQ_base+0x005C))
	 #define CEVAPLL                ((volatile UINT16P)(PLL_CLKSQ_base+0x0060))
	 #define CEVAPLL2                ((volatile UINT16P)(PLL_CLKSQ_base+0x0064))
	 #define PLL_IDN                ((volatile UINT16P)(PLL_CLKSQ_base+0x0070))
	 #define XOSC32_AC_CON                ((volatile UINT16P)(PLL_CLKSQ_base+0x007C))

			 
	 
        #if defined(__SMART_PHONE_MODEM__)

      kal_uint32 i;
 
      // ungate DSP clock since the default is gated
      *(volatile unsigned long *)(0x80010204) &=~0x000C;

      // reset MD2G/DSP no matter whole chip reset or reset by AP
      *(volatile unsigned long *)(0x80030028)  = 0xBB80; // RST MD2G(reset)
      *(volatile unsigned long *)(0x80030014)  = 0x8048; // RST DSP (reset)
      for(i=0; i<0xF; i++);
      *(volatile unsigned long *)(0x80030028)  = 0xBB00; // RST MD2G(release)
      *(volatile unsigned long *)(0x80030014)  = 0x0048; // RST DSP (release)

      // Set MCU clock to 104MHz
      *(volatile unsigned long *)(0x80010208) |= 0x00000010;
      for(i=0; i<0xF; i++);
 
      return;

        #else

		kal_uint32 i;
 
      *MD_CONFIG_APB_CON = 0x0008;

      // ungate DSP clock since the default is gated
      *(volatile unsigned long *)(0x80010204) &=~0x004C;
      *(volatile unsigned long *)(0x80010208) |= 0x0010;

		*PDN_CON   = 0x1e;	  // power-on MPLL(DPLL), UPLL
		*CEVAPLL2	= 0x1f;	   // power-on CEVAPLL
		*CLK_CON   = 0x83;	  // switch to 13MHz for PLL input frequency
		// After power-on PLL.....
		*UPLL = 0x0080; // reset UPLL
		*MPLL = 0x0080; // reset MPLL
		*CEVAPLL = 0x0800; // reset CEVAPLL
		*UPLL = 0x0000; // release UPLL reset
		*MPLL = 0x0000; // release MPLL reset
		*CEVAPLL = 0x0000; // release CEVAPLL reset

		*AP_SLEEP_CON |= 0x0300;
		while(( ((*AP_SLEEP_CON) & 0x0300) != 0x0300));
		
		for (i=0;i<200;i++);
		*CLK_CON = 0x00f3; // select PLL outputs


	for (i=0;i<200;i++);

     *(volatile unsigned long *)(0x80010204) |= 0x40;



	#endif


}
#endif

#endif

#if defined(MT6268T)
{
   kal_uint32 i, timeout;


   /* EMI_GENA should be configured before PLL is initialized */
   *(volatile kal_uint32 *)0x80010000 = 0x2249490a;

   /*
    *   ARM clock = 122.88Mhz, AHB clock (Peripheral Clock) = 30.72Mhz
    *   DSP clock = 130 Mhz
    *   USB clock = 48  Mhz 
    *   GSM clock = 52  Mhz
    */

   /* Set PAD Driving */
   *(volatile kal_uint16 *)0x80000720 = 0xCCCC;
   *(volatile kal_uint16 *)0x80000724 = 0x2ACC;
   *(volatile kal_uint16 *)0x80000728 = 0x3bb3;
   *(volatile kal_uint16 *)0x8000072C = 0x0003;


   //1. Power up PLLs and enable clock squre 
   *(volatile kal_uint32 *)0x80000320 = 0x8000;  // power up dsp_div2

   for (i = 0; i < 1000; i++);

   *(volatile kal_uint32 *)0x80000320 = 0x1000;  // power up mcu_div2

   for (i = 0; i < 1000; i++);

   *(volatile kal_uint32 *)0x80000320 = 0x2000;  // power up pll4

   for (i = 0; i < 1000; i++);

   *(volatile kal_uint32 *)0x80000320 = 0x4000;  // power up pll3

   for (i = 0; i < 1000; i++);

   *(volatile kal_uint32 *)0x80000320 = 0x0400;  // power up pll2

   for (i = 0; i < 1000; i++);

   *(volatile kal_uint32 *)0x80000320 = 0x0200;  // power up pll1

   for (i = 0; i < 1000; i++);

   *(volatile kal_uint32 *)0x80000320 = 0x0100;  // power up clksq

   for (i = 0; i < 1000; i++);

   //2. Setting PLLs 
   *(volatile kal_uint32 *)0x80000108 = 0x0001;      // Set PLL3 output clock is 122.88Mhz (used for ARM)
   *(volatile kal_uint32 *)0x8000010C = 0x0001;      // Set PLL3 output clock is 130Mhz (used for DSP)

   //3. Setting Clock divider of each clock doamin
   *(volatile kal_uint32 *)0x8000012C = 0x0003;  // AHB clock : ARM clock  = 1:4
                        // To fixed AHB bus clock = 30.72Mhz

   *(volatile kal_uint32 *)0x8000011C = 0x0099; // DSP1 clock = src clock, DSP2 clock = src clock o
                         // 0x0099 => DSP1 & DSP2 = 130Mhz
   *(volatile kal_uint32 *)0x80000110= 0x08;       // Setting Analog PLL input as reference clock divided 2 

   // 4. Wait PLL stable
   for (i = 0; i < 1000; i++); // Follow PLL stable time in datasheet

   // 5. Switch clock doamin clock source from external clock to pll output
   *(volatile kal_uint32 *)0x80000110 = 0x2f ;      //all clock domain use PLL output

   for (i = 0; i < 1000; i++);

   *(volatile kal_uint16 *)0x80000130 = 0x8000;
   *(volatile kal_uint16 *)0x80000140 = 0x8000;
   *(volatile kal_uint16 *)0x80000150 = 0x8000;
   *(volatile kal_uint16 *)0x80000160 = 0x8000;

   for (i = 0; i < 3000000; i++);

   WacthDogRestart();

   *(volatile unsigned int *)0xC0020400 = 0x10000;
   *(volatile unsigned int *)0xC0020418 = 0x10000;

   *(volatile unsigned int *)0xB00D0028 = 0x1;

   /* delay a while */
   for (i = 0; i < 9000000; i++);

   WacthDogRestart();

   timeout = 10000;
   do {
      i = *(volatile unsigned int *)0xB00D0028;
      if (i & 0x80000000) {
         break;
      }
      timeout--;
      if (timeout == 0) {
         break;
      }
   } while (1);

   WacthDogRestart();

   timeout = 10000;
   do {
      i = *(volatile unsigned int *)0xC0020400;
      if (i & 0x80000000) {
         break;
      }
      timeout--;
      if (timeout == 0) {
         break;
      }
   } while (1);

   WacthDogRestart();

   *(volatile unsigned short *)0x80000134 = 0x113C;
}
#endif  /* MT6268T */

#if defined(MT6268H)
{
   kal_uint32 i, timeout;


   /* EMI_GENA should be configured before PLL is initialized */
   *(volatile kal_uint32 *)0x80010000 = 0x2249490a;

   /*
    *   ARM clock = 122.88Mhz, AHB clock (Peripheral Clock) = 30.72Mhz
    *   DSP clock = 130 Mhz
    *   USB clock = 48  Mhz 
    *   GSM clock = 52  Mhz
    */

   /* Set PAD Driving */
   *(volatile kal_uint16 *)0x80000720 = 0xffff;
   *(volatile kal_uint16 *)0x80000724 = 0xffff;
   *(volatile kal_uint16 *)0x80000728 = 0xffff;
   *(volatile kal_uint16 *)0x8000072C = 0xffff;

   //1. Power up PLLs and enable clock squre 
   *(volatile kal_uint32 *)0x80000320 = 0x8000;  // power up dsp_div2

   for (i = 0; i < 1000; i++);

   *(volatile kal_uint32 *)0x80000320 = 0x1000;  // power up mcu_div2

   for (i = 0; i < 1000; i++);

   *(volatile kal_uint32 *)0x80000320 = 0x2000;  // power up pll4

   for (i = 0; i < 1000; i++);

   *(volatile kal_uint32 *)0x80000320 = 0x4000;  // power up pll3

   for (i = 0; i < 1000; i++);

   *(volatile kal_uint32 *)0x80000320 = 0x0400;  // power up pll2

   for (i = 0; i < 1000; i++);

   *(volatile kal_uint32 *)0x80000320 = 0x0200;  // power up pll1

   for (i = 0; i < 1000; i++);

   *(volatile kal_uint32 *)0x80000320 = 0x0100;  // power up clksq

   for (i = 0; i < 1000; i++);

   //2. Setting PLLs 
   *(volatile kal_uint32 *)0x80000108 = 0x0001;      // Set PLL3 output clock is 122.88Mhz (used for ARM)
   *(volatile kal_uint32 *)0x8000010C = 0x0001;      // Set PLL3 output clock is 130Mhz (used for DSP)

   //3. Setting Clock divider of each clock doamin
   *(volatile kal_uint32 *)0x8000012C = 0x0003;  // AHB clock : ARM clock  = 1:4
                        // To fixed AHB bus clock = 30.72Mhz

   *(volatile kal_uint32 *)0x8000011C = 0x0099; // DSP1 clock = src clock, DSP2 clock = src clock o
                         // 0x0099 => DSP1 & DSP2 = 130Mhz
   *(volatile kal_uint32 *)0x80000110= 0x08;       // Setting Analog PLL input as reference clock divided 2 

   // 4. Wait PLL stable
   for (i = 0; i < 1000; i++); // Follow PLL stable time in datasheet

   // 5. Switch clock doamin clock source from external clock to pll output
   *(volatile kal_uint32 *)0x80000110 = 0x2f ;      //all clock domain use PLL output

   for (i = 0; i < 1000; i++);

   *(volatile kal_uint16 *)0x80000130 = 0x8000;
   *(volatile kal_uint16 *)0x80000140 = 0x8000;
   *(volatile kal_uint16 *)0x80000150 = 0x8000;
   *(volatile kal_uint16 *)0x80000160 = 0x8000;

   for (i = 0; i < 3000000; i++);
   
   /* DCM Reset for MT6268H */
   {  kal_uint16 data;
      kal_uint32 i;
      
      /* Set as GPIO mode */
      *(volatile kal_uint16 *)0x801201A0 = 0x0;
      *(volatile kal_uint16 *)0x801201B0 = 0x0;
      
      /* Set GPIO_DAT */
      data  = *(volatile kal_uint16 *)0x801200F0;
      data &= ~0x0780;   //Set GPIO 7~10 as 0
      data |=  0xF800;   //Set GPIO11~15 as 1
      *(volatile kal_uint16 *)0x801200F0 = data;
      
      /* Set DIR as output */
      data  = *(volatile kal_uint16 *)0x80120000;
      data |= 0xFF80;  
      *(volatile kal_uint16 *)0x80120000 = data;

      /* Wait 10ms */
      for (i=0; i<250000; i++ ) ;      //Reseting DCM

      /* Set GPIO_DOUT */
      data  = *(volatile kal_uint16 *)0x801200F0;
      data |= 0x0780;   //Set GPIO7~10 as HIGH to de-assert DCM reset
      *(volatile kal_uint16 *)0x801200F0 = data;
      
      /*************************************************************************/
      /* Wait 10ms */
      for (i=0; i<250000; i++ ) ;      //Wait for DCM lock (Clock good)
      
      /* Set GPIO_DOUT */
      data  = *(volatile kal_uint16 *)0x801200F0;
      data &= ~0x7800; 
      *(volatile kal_uint16 *)0x801200F0 = data;
      
      /* Wait 10ms */
      for (i=0; i<20000; i++ ) ;      //Reseting FPGA4 & FPAG3
      
      /* Set GPIO_DOUT */
      data  = *(volatile kal_uint16 *)0x801200F0;
      data |= 0xFF80;
      *(volatile kal_uint16 *)0x801200F0 = data;
   }      

   WacthDogRestart();

   *(volatile unsigned int *)0xC0020400 = 0x10000;
   *(volatile unsigned int *)0xC0020418 = 0x10000;

   *(volatile unsigned int *)0xB00D0028 = 0x1;

   /* delay a while */
   for (i = 0; i < 9000000; i++);

   *(volatile unsigned short *)0x80000134 = 0x113C;
}
#endif   /* MT6268H */

#if defined(MT6268A)
{
    kal_uint16 i;
    
    /*1. Power on MPLL, DPLL, UPLL, CLKSQ and CLKSQ_DIV2*/
    DRV_WriteReg(PDN_CON, 0x001e);
    
    /*2. Switch to 13MHz for PLL input frequency*/
#ifdef EXT_26M
    DRV_WriteReg(CLK_CON, 0x0083);
#elif defined (EXT_13M)
    DRV_WriteReg(CLK_CON, 0x0083);
#endif

    /*3. Reset UPLL, MPLL, DPLL*/
    DRV_WriteReg(UPLL, 0x0080);
    DRV_WriteReg(MPLL, 0x0080);
    DRV_WriteReg(DPLL, 0x0080);
    DRV_WriteReg(DPLL, 0x0000);
    
    for(i=0;i<200;i++);
    
    /*4. Release UPLL, MPLL, DPLL reset*/
    DRV_WriteReg(UPLL, 0x0000);
    DRV_WriteReg(MPLL, 0x0000);
    DRV_WriteReg(DPLL, 0x0000);
    
    /*5. Delay until PLL is stable,*/
    for(i=0;i<200;i++);

    /*6. Select PLL outputs*/
    DRV_WriteReg(CLK_CON, 0x00f3);
    
    /*7. Setting ARM, Fast Bus and Slow Bus Clock.*/
#if defined(MCU_245_76M)
    DRV_WriteReg(MCUCLK_CON, 0x7DE7);
#elif defined(MCU_122_88M)
    DRV_WriteReg(MCUCLK_CON, 0x3DE7);
#elif defined(MCU_61_44M)
    DRV_WriteReg(MCUCLK_CON, 0x1CE7);
#elif defined(MCU_30_72M)
    DRV_WriteReg(MCUCLK_CON, 0x0C63);
#elif defined(MCU_15_36M)
    DRV_WriteReg(MCUCLK_CON, 0x0421);
#endif  	   
}
#endif /* MT6268A */

#if defined(MT6268)
{
    kal_uint16 i;
    
    /*1. Power on MPLL, DPLL, UPLL, CLKSQ and CLKSQ_DIV2*/
    DRV_WriteReg(PDN_CON, 0x001e);
    
    /*2. Switch to 13MHz for PLL input frequency*/
#ifdef EXT_26M
    DRV_WriteReg(CLK_CON, 0x0083);
#elif defined (EXT_13M)
    DRV_WriteReg(CLK_CON, 0x0083);
#endif

    /*3. Reset and release UPLL, MPLL, DPLL*/
    DRV_WriteReg(UPLL, 0x0080);
    DRV_WriteReg(UPLL, 0x0000);
    DRV_WriteReg(DPLL, 0x0080);
    DRV_WriteReg(DPLL, 0x0000);

    /*4. wait >100us after UPLL been reset for UPLL settling. */
    for(i=0;i<100;i++);
    
    /*5. Reset and Release MPLL reset*/
    DRV_WriteReg(MPLL, 0x0080);
    DRV_WriteReg(MPLL, 0x0000);

    
    /*6. Delay until PLL is stable,*/
    for(i=0;i<600;i++);
    
    /*7. Select PLL outputs*/
    DRV_WriteReg(CLK_CON, 0x00f3);
    
    /*8. Setting ARM, Fast Bus and Slow Bus Clock.*/
#ifdef MCU_245_76M   
    DRV_WriteReg(MCUCLK_CON, 0x7DE7);
#elif MCU_122_88M   
    DRV_WriteReg(MCUCLK_CON, 0x3DE7);
#elif defined MCU_61_44M
    DRV_WriteReg(MCUCLK_CON, 0x1CE7);
#elif defined MCU_30_72M
    DRV_WriteReg(MCUCLK_CON, 0x0C63);
#elif defined MCU_15_36M
    DRV_WriteReg(MCUCLK_CON, 0x0421);
#endif  	  

#if defined(_NAND_FLASH_BOOTING_)
    //power up NFI
    //DRV_WriteReg16((volatile unsigned short*)(0x84010324),0x1000);
    DRV_WriteReg((volatile unsigned short*)CG_CLR1,CG_CON1_NFI);
#endif
}
#endif /* MT6268 */

#if defined(MT6236) || defined(MT6236B)
{
    kal_uint32 i;

#ifdef MCU_312M
    *MCUCLK_CON = 0x2000;
#elif defined MCU_152M
    *MCUCLK_CON = 0x1000
#elif defined MCU_78M
    *MCUCLK_CON = 0x0100;
#elif defined MCU_13M
    *MCUCLK_CON = 0x0000;
#endif

    // 0x801A_0304 Power on & Reset UPLL: [1]UPLL_PWDB=1, [0]UPLL_RST=1
    *UPLL_CON1 = *UPLL_CON1 | 0x0003;
    // 0x801A_0404: Power on & Reset MPLL: [1]MPLL_PWDB=1, [0]MPLL_RST=1
    *MPLL_CON1 = *MPLL_CON1 | 0x0003;

    // 0x801A_0304 Release reset UPLL: [1]UPLL_PWDB=1, [0]UPLL_RST=0
    *UPLL_CON1 = *UPLL_CON1 & 0xfffe;
    // 0x801A_0404: Release reset MPLL: [1]MPLL_PWDB=1, [0]MPLL_RST=0
    *MPLL_CON1 = *MPLL_CON1 & 0xfffe;
 
    // wait for UPLL & MPLL stable (about 100uS)
    for (i=0;i<100;i++);
    // 0x801A_0204: UPLL & MPLL output select:[7:6]GPLLSEL=10,[5:4]UPLLSEL=10, [3:2]DPLLSEL=10,[1:0]MPLLSEL=10
    *PLL_CON1 = 0x00AA;
}
#endif  /* MT6236 || MT6236B */

#if defined(MT6270A)
{
    kal_uint16 i;
    // 0x7100_0118: setup MD ARM/AHB/APB bus clock
    *MCUCLK_CON  = 0x7DE7;
    // 0x7100_0140: setup AP ARM clock
    *APMCUCLK_CON  = 0x001F;
    // 0x7100_0150: setup DSP clock
    *BFCLK_CON = 0x001F;

    // 0x7114_0400: Change MPLL_VCOBAND[2:0] to 0x3 and Turn MPLL_VCOCAL_EN off..
    *MPLL_CON0 = *MPLL_CON0 & 0xf3ff;

    // 0x7114_0010 Power on UPLL & MPLL: [4]UPLL_PWDB=1, [2]MPLL_PWDB=1
    *PDN_CON = *PDN_CON | 0x0014;

    // 0x7114_0304: Reset UPLL first: [0]UPLL_RST=1
    *UPLL_CON1 = *UPLL_CON1 | 0x0001;
    // 0x7114_0304: Relase UPLL Reset [0]UPLL_RST=0
    *UPLL_CON1 = *UPLL_CON1 & 0xfffe;
    // wait for UPLL stable (about 20uS)
    for (i=0;i<20;i++);

    // 0x7114_0404: Reset MPLL first: [0]MPLL_RST=1
    *MPLL_CON1 = *MPLL_CON1 | 0x0001;
    // 0x7114_0404: Relase MPLL Reset [0]MPLL_RST=0
    *MPLL_CON1 = *MPLL_CON1 & 0xfffe;
    // wait for MPLL stable (about 20uS)
    for (i=0;i<20;i++);

    // 0x7114_0014: UPLL & MPLL output select: [5:4]GSM_PLLSEL=10, [3:2]MCU_PLLSEL=10,[1:0]ARM_PLLSEL=10
    *CLK_CON = *CLK_CON | 0x002A;


    //Reset FPGA
    //Adjust 26M clock driving
    //*(volatile kal_uint16*)0x71000708 = 0x6000;
    //*(volatile kal_uint16*)0x71000708 = 0x2000;
    *(volatile kal_uint16*)0x71000708 = 0xE000;

    //Adjust HCLK clock driving
    //*(volatile kal_uint32*)0x7100070C = 0x00000003;
	 //*(volatile kal_uint16*)0x7100070C = 0x0001;  //10mA
	 //*(volatile kal_uint16*)0x7100070C = 0x0003;  //10mA
	 *(volatile kal_uint16*)0x7100070C = 0x0007;    //14mA
	 
	 //FPGA_MAS interface driving 
    *(volatile kal_uint16*)0x71000710 = 0x036C;    
   
    //FPGA_SLV interface driving
    //*(volatile kal_uint16*)0x71000714 = 0xFFFF;
	 //*(volatile kal_uint16*)0x71000718 = 0xFFFF;
	 *(volatile kal_uint16*)0x71000718 = 0xB600;
	 
	 //IO driver of external interface
	 *(volatile kal_uint16*)0x7100071C = 0x1B6F;

    //Adjust FPGA clock phase
    //*(volatile kal_uint32*)0x71001000 = 0x00008000;
    //*(volatile kal_uint32*)0x71001008 = 0x00008000;
    *(volatile kal_uint16*)0x71001000 = 0x9000;
    *(volatile kal_uint16*)0x71001010 = 0x9000;
    //*(volatile kal_uint32*)0x71001018 = 0x00008000;

    //FPGA_SLV interface driving
    //*(volatile kal_uint16*)0x71000714 = 0xFFFF;
	 //*(volatile kal_uint16*)0x71000718 = 0xFFFF;
	 
	 //To bus master port as output mode
	 //*(volatile kal_uint16*)0x71003000 = (*(volatile kal_uint16*)0x71003000) & (~0x00000100);  

    // EINT mode setting (Set GPIO 0 and 10 as GPIO mode, others are IRQ mode)
    *(volatile kal_uint16*)0x71061000 = 0x0004;  //GPIO_MODE1 (Set GPIO_0  as GPIO mode for 3G DCM reset)
    *(volatile kal_uint16*)0x71061100 = 0x5540;  //GPIO_MODE2 (Set GPIO_10 as GPIO mode for 2G DCM reset)
    *(volatile kal_uint16*)0x71061200 = 0x5555;  //GPIO_MODE3
    *(volatile kal_uint16*)0x71061300 = 0x0015;  //GPIO_MODE4

    //reset FPGA to lock DCM
    *(volatile kal_uint16*)0x71060000 = 0x0401;  //GPIO_DIR1
    *(volatile kal_uint16*)0x71060800 = 0x0401;  //GPIO_DOUT1   
  //*(volatile kal_uint16*)0x71060040 = 0x0401;  //GPIO_DIR2

    //wait 1.ms
    for (i=0;i<26000;i++);
    *(volatile kal_uint16*)0x71060800 = 0x0000;  //GPIO_DOUT1   
  //*(volatile kal_uint16*)0x71060840 = 0x0000;  //GPIO_DOUT2

    //wait 1.ms
    for (i=0;i<26000;i++);
    *(volatile kal_uint16*)0x71060800 = 0x0401;  //GPIO_DOUT1   
  //*(volatile kal_uint16*)0x71060840 = 0x0401;  //GPIO_DOUT2

    //wait 1.ms
    for (i=0;i<26000;i++);    

    //power up NFI and DMA
    //DRV_WriteReg16((volatile unsigned short*)(0x84010324),0x1000);
    DRV_WriteReg16((volatile unsigned short*)CG_CLR1,CG_CON1_NFI);
    DRV_WriteReg16((volatile unsigned short*)CG_CLR0,CG_CON0_DMA);
    *(volatile kal_uint32 *)(0xB80A0080) = 0x62760001;

    *(volatile kal_uint32*)0xC0110000 = 0x80000004;   //F4 output through bridge, not direct output
    *(volatile kal_uint32*)0xC0110010 = 0xFD7F0000;   //Turn off F4 2 IRQ for F1 UPA L2 Copro IRQ and HW PPP Framer
  //*(volatile kal_uint32*)0xD0110010 = 0x00800000;   //Turn on F1 UPA L2 Copro IRQ (HW default on)
}
#endif /* MT6270A */

#if defined(MT6276)
{
#ifdef MT6276_S00

    kal_uint32 i;

   // setup vcore to 1.30V
   //*(volatile unsigned int*)0x61150900 |= 0x40;
   *(volatile unsigned int*)0x61150940 = 0xA861;

    // Reset PLL
    DRV_WriteReg(PLL_CON5, *PLL_CON5&0xF000);
    DRV_WriteReg(PLL_CON4, *PLL_CON4&0x00FF);
    DRV_WriteReg(WPLL_CON0, 0x0300);
    DRV_WriteReg(MPLL_CON1, 0x0100);
    DRV_WriteReg(GPLL_CON0, 0x0300);
    DRV_WriteReg(DPLL_CON1, 0x0100);

    DRV_WriteReg(MPLL_CON0, 0x0000);
    DRV_WriteReg(DPLL_CON0, 0x0000);

    // Initialize PLL
    DRV_WriteReg(WPLL_CON0, *WPLL_CON0|0x004C);
    DRV_WriteReg(WPLL_CON0, *WPLL_CON0|0x0001);

    /**
      * Lower ARM's frequency to 598MHz based on designer/Clavin's suggestion.
      */
#if defined(__MT6276_CONCURRENCY_TEST__)      
    DRV_WriteReg(MPLL_CON0, *MPLL_CON0|0x004C);
    DRV_WriteReg(MPLL_CON0, *MPLL_CON0|0x0001);
#else /* __MT6276_CONCURRENCY_TEST__ */    
    DRV_WriteReg(MPLL_CON0, *MPLL_CON0|0x6F4C);
    DRV_WriteReg(MPLL_CON0, *MPLL_CON0|0x6F01);
#endif /* __MT6276_CONCURRENCY_TEST__ */    

    DRV_WriteReg(GPLL_CON0, *GPLL_CON0|0x004C);
    DRV_WriteReg(GPLL_CON0, *GPLL_CON0|0x0001);

    /**
      * Lower DSP's frequency to 260MHz based on designer/Clavin's suggestion.
      */
#if defined(__MT6276_CONCURRENCY_TEST__)            
    DRV_WriteReg(DPLL_CON0, *DPLL_CON0|0x004C);
    DRV_WriteReg(DPLL_CON0, *DPLL_CON0|0x0001);
#else /* __MT6276_CONCURRENCY_TEST__ */        
    DRV_WriteReg(DPLL_CON0, *DPLL_CON0|0x314C);
    DRV_WriteReg(DPLL_CON0, *DPLL_CON0|0x3101);
#endif /* __MT6276_CONCURRENCY_TEST__ */    

    // wait > 20us for PLL lock
    for(i=0; i<0x1000; i++);

    // Switch PLL control to HW control
    DRV_WriteReg(WPLL_CON0, *WPLL_CON0&0xFCFF);
    DRV_WriteReg(MPLL_CON1, *MPLL_CON1&0xFEFF);
    DRV_WriteReg(GPLL_CON0, *GPLL_CON0&0xFCFF);
    DRV_WriteReg(DPLL_CON1, *DPLL_CON1&0xFEFF);
    
    // Switch clock from 26M to PLL outputs
    *PLL_CON5 = 0x0111;
    *PLL_CON4 = 0x1100;

    //Disable clksw unused divider
    DRV_WriteReg(PLLCNTEN_CON, 0x0);

#else /* MT6276_S01 */

#define __MPLL_USE_DDS__

    kal_uint32 i;

   if(mode == PLL_MODE_MAUI)
   {

   //Use Co-sim PLL flow for bring-up
   /**
     * For BUS_GATED_EN,
     * 1. Enable Infrasys bus clock, peripheral sys master bus clock, peripheral sys slave bus clock, ARM sys bus clock, Fcore sys bus clock, MD2G sys bus lock, HSPA sys bus clock, MM sys bus clock, and audio sys bus's gating.
     * For ARMSYS_CON,
     * 1. Set SYSROM's clock is 1/4 to ARM clock.
     * 2. Enable SYSROM clock gate function.
     * 3. Set L2TCM data cycle to 2 ARM cycles.
     * 4. Set L2TCM inst cycle to 2 ARM cycles.
     */  
   *(volatile kal_uint32 *)0x810D0558 = 0xffffffff;
   *(volatile kal_uint32 *)0x810D0500 = 0x3012;

   /**
      * For GPLL_CON0,
     * 1. Assert to adjust loop filter.
     * 2. Set lock detect control to 11us (shortest).
      * 3. Enable 2G PLL.
     */
   *(volatile kal_uint16 *)0x81140280 |= 0x004C;  
   *(volatile kal_uint16 *)0x81140280 |= 0x0081;

   /**
     * For WPLL_CON0, 
     * 1. Assert to adjust loop filter.
     * 2. Set lock detect control to 11us (shortest).
     * 3. Enable 3G PLL.
     */
   *(volatile kal_uint16 *)0x81140240 |= 0x004C;
   *(volatile kal_uint16 *)0x81140240 |= 0x0081;

    // wait > 20us for PLL lock
    for(i=0; i<0x1000; i++); /* in 26Mhz scale */

#if defined(__MPLL_USE_DDS__)
   /**
     * For MPLL_CON3, 
     * 1. Set MDDS divider integer to 6.
     */
   *(volatile kal_uint16 *)0x8114014C |= 0x0004;   

   /**
     * For MPLL_CON2, 
     * 1. Set MDDS divider fraction to 0.
     * 2. Enable MDDS
     */
   *(volatile kal_uint16 *)0x81140148 &= ~(0x03FF);
   *(volatile kal_uint16 *)0x81140148 |= 0x1000;

   /**
     * For MPLL_CON1, 
     * 1. Set MPLL reference clock from MDDS.
     */
   *(volatile kal_uint16 *)0x81140144 |= 0x0001;
#else

   /**
     * For MPLL_CON1, 
     * 1. Set MPLL reference clock from 26Mhz.
     */
   *(volatile kal_uint16 *)0x81140144 &= 0xFF00;

#endif

    /**
      * For MPLL_CON0,
      * 1. Assert to adjust loop filter.
      * 2. Enable MCU PLL.
      * 3. Set MPLL_DIV1 = /5(Bus), MPLL_DIV2 = /2(DSP), MPLL_DIV4 = /2(EMI)
      * 4. Set MPLL_DIV6 = /6 to save power
      * 5. Enable MPLL divider
      */   
   *(volatile kal_uint16 *)0x81140140 = 0x0;
   *(volatile kal_uint16 *)0x81140140 |= 0x704C;
   *(volatile kal_uint16 *)0x81140140 |= 0x0001;

   *(volatile kal_uint16 *)0x8114011C = 0x6820;
   *(volatile kal_uint16 *)0x81140120 = 0x7000;
   *(volatile kal_uint16 *)0x8114012C = 0x0008;

    /**
     * For FPLL_CON0, 
      * 1. Assert to adjust loop filter.
      * 2. Set lock detect control to 11us (shortest).
     * 3. Enable FOH PLL.
     */
   /**
     * Force ARM running at 650MHz => 611Mhz to mitigate ARM unstable issue when Vaproc < 1.35V.
     */
   *(volatile kal_uint16 *)0x811402C0 &= 0x00FF;   
   #if defined(__MODEM_CARD__)
   /**
     * Force ARM running at 520MHz for data card applications.
     */
   *(volatile kal_uint16 *)0x811402C0 |= 0x6100;//0x6900;change to 416Mhz
   #else
   /**
     * Force ARM running at 650MHz => 611Mhz to mitigate ARM unstable issue when Vaproc < 1.35V.
     */
   *(volatile kal_uint16 *)0x811402C0 |= 0x7000;   
   #endif

   *(volatile kal_uint16 *)0x811402C0 |= 0x004C;
   *(volatile kal_uint16 *)0x811402C0 |= 0x0001;

#if defined(__DSP_USE_DPLL__)
    /**
      * For DPLL_CON3,
      * 1. set DDDS dievider integer to 6.
      */      
   *(volatile kal_uint16 *)0x8114018C &= ~(0x001F);
   *(volatile kal_uint16 *)0x8114018C |= 0x0004;

    /**
      * For DPLL_CON2,
      * 1. set DDDS dievider fraction to 0.
      * 2. enable DDDS
      */      
   *(volatile kal_uint16 *)0x81140188 &= ~(0x03FF);
   *(volatile kal_uint16 *)0x81140188 |= 0x1000;

    /**
      * For DPLL_CON1,
      * 1. set DPLL reference clock from DDDS.
      */   
   *(volatile kal_uint16 *)0x81140184 |= 0x0001;

    /**
      * For DPLL_CON0,
      * 1. Assert to adjust loop filter.
      * 2. Set lock detect control to 11us (shortest).
      * 3. Enable DSP PLL.
      */      
   *(volatile kal_uint16 *)0x81140180 |= 0x004C;
   *(volatile kal_uint16 *)0x81140180 |= 0x0001;
#endif

    /**
      * For EPLL_CON3,
      * 1. set EDDS dievider integer to 6.
      */      
   *(volatile kal_uint16 *)0x811401CC &= ~(0x001F);
   *(volatile kal_uint16 *)0x811401CC |= 0x0004;

    /**
      * For EPLL_CON2,
      * 1. set EDDS dievider fraction to 0.
      * 2. enable DDDS
      */      
   *(volatile kal_uint16 *)0x811401C8 &= ~(0x03FF);
   *(volatile kal_uint16 *)0x811401C8 |= 0x1000;

    /**
      * For EPLL_CON1,
      * 1. set EPLL reference clock from EDDS.
      */      
   *(volatile kal_uint16 *)0x811401C4 |= 0x0001;

    /**
      * For EPLL_CON0,
      * 1. Assert to adjust loop filter.
      * 2. Switch EMI clock to 195MHz (DDR = 390MJz).
      * 3. Enable EMI PLL.
      */      
   *(volatile kal_uint16 *)0x811401C0 |= 0x6F4C;  
   *(volatile kal_uint16 *)0x811401C0 |= 0x0001;

#if !defined(__MODEM_CARD__) /* MT6276M does not need this clock source */
    /**
      * For CPLL_CON0,
      * 1. Assert to adjust loop filter.
      * 2. Enable CAMERA PLL.
      */         
   *(volatile kal_uint16 *)0x81140200 |= 0x004C;
   *(volatile kal_uint16 *)0x81140200 |= 0x0001;
#endif

    // wait > 30us for PLL lock
    for(i=0; i<0x1800; i++);

   /**
     * For WPLL_CON0, GPLL_CON0,
     * 1. Clear 2G & 3G clock lock.
     * For MPLL_CON1, EPLL_CON1, DPLL_CON1,
     * 1. Switch PLL enable signal from CCI register (SW-control) to top-state machine (HW-control).
     */
   *(volatile kal_uint16 *)0x811402C4 &= 0xFEFF; /* FPLL */
   *(volatile kal_uint16 *)0x81140240 &= 0xFCFF; /* WPLL */
   *(volatile kal_uint16 *)0x81140144 &= 0xFEFF; /* MPLL */
   *(volatile kal_uint16 *)0x81140280 &= 0xFCFF; /* GPLL */
   *(volatile kal_uint16 *)0x811401C4 &= 0xFEFF; /* EPLL */
#if defined(__DSP_USE_DPLL__)
   *(volatile kal_uint16 *)0x81140184 &= 0xFEFF;
#endif
    /**
       * Enable clock divider (*CLKSW_PLLDIV_CON3) for E2 to set WPLL_DIV_AFT_MUX to be output = clock divided by 5
       */
   /* Removed because of urgent clock design change. 
   *(volatile kal_uint16 *)0x81140128 = 0x6; */   

   /**
     * For PLL_CON4, PLL_CON5
     * 1. Select MPLL, DPLL, EPLL, CPLL, 3GPLL, 2GPLL, WPLL's output from correspoinding PLL divider output.
     * DSP clock is from MPLL_DIV2
     */
#if defined(__DSP_USE_DPLL__)
   *(volatile kal_uint16 *)0x81140110 = 0x1100;
#else
   *(volatile kal_uint16 *)0x81140110 = 0x1200;
   *(volatile kal_uint16 *)0x81140130 = 0x1222;
#endif

#if defined(MT6276_E2_BRINGUP_DBG_CODE)
   /**
     * Temp codes for bring-up.
     */
   *(volatile kal_uint16 *)0x8114012C = 0x0001;
   *(volatile kal_uint16 *)0x81140124 = 0x0007;      
   *(volatile kal_uint16 *)0x81140114 = 0x1200;   
   
   /**
     * Adjust ARM's timing.
     */
   *(volatile kal_uint32 *)0x610D050C = 0x00165695;      
   *(volatile kal_uint16 *)0x811402C0 = 0x604d;        

   /**
     * Adjust EMI's timing.
     */   
   *(volatile kal_uint16 *)0x811401C0 = 0x524d;  
       
#else /*  MT6276_E2_BRINGUP_DBG_CODE */

    /**
      * Software-workaround for force enable the mux of 3G PLL.
      */
   *(volatile kal_uint16 *)0x81140A94 = 0xC400;   
   /*
     MSDC use MPLL
   */
   *(volatile kal_uint16 *)0x81140114 = 0x1112;
   
#endif /*  MT6276_E2_BRINGUP_DBG_CODE */

   for(i=0; i<0x1800; i++);

#endif /* MT6276_S00 */
    }
    else /* USB meta mode */
    {
        /* enable DPLL since bootROM would not do it */
        *(volatile kal_uint16 *)0x81140180 |= 0x004C;
        *(volatile kal_uint16 *)0x81140180 |= 0x0001;
        // wait > 30us for PLL lock
        for(i=0; i<0x1800; i++);
        /* switch DSP to DPLL */
        *(volatile kal_uint16 *)0x81140110 |= 0x0100;
    }
}

#endif /* MT6276 */

#if defined(MT6256)
{
    kal_uint32 i;
    kal_bool   eco_flow = KAL_FALSE;
    
    if(INT_SW_SecVersion() > SW_SEC_0)
    {
        eco_flow = KAL_TRUE;
    }
    else
    {
        eco_flow = KAL_FALSE;
    }
 
    /** PLL Standard Init Sequence */
    if(eco_flow) /* MT6256 E5 of latter */
    {
        /** PLL Calibtration Sequence */
        /* disable all PLLs except currently used ones */
        if(mode == PLL_MODE_USB_META)
        {
            *PLL_CON1 &= 0x8004; /* keep UPLL_SEL */
            *PLL_CON1 |= 0x8000;
        }
        else
        {
            *PLL_CON1 = 0x8000;
        }

        if(mode != PLL_MODE_USB_META)
        {
            *FPLL_CON3 &= ~(0x0002);
        }
        *MPLL_CON3 &= ~(0x0002);
        *NPLL_CON3 &= ~(0x0002);
        *EPLL_CON3 &= ~(0x0002);
        *UPLL_CON3 &= ~(0x0002);

        /* re-enable VCO auto band calibration */
        *UPLL_CON2 |= 0x1000;
        if(mode != PLL_MODE_USB_META)
        {
            *FPLL_CON2 |= 0x1000;
        }
        *MPLL_CON2 |= 0x1000;
        *NPLL_CON2 |= 0x1000;
        *EPLL_CON2 |= 0x1000;

    /* All calibration should be complete within 700us        
        VCOCAL_FAIL=1 - failed IC
        VCOCAL_CPLT=1 - calibration complete
        [IvanTseng] SW workaround -- set vcoband with auto-K, and disable auto-K within 19us */
        
    /* Configure EMI PLL clock here but enable after LPDDR initialization */
    #if defined(__EMI_CLK_200MHZ__)

        *EPLL_CON2 = (*EPLL_CON2 & 0xff80) | 0x1D; // EPLL clock = 13Mhz x (29+1) = 390MHz
        
    #elif defined(__EMI_CLK_166MHZ__)

        *EPLL_CON2 = (*EPLL_CON2 & 0xff80) | 0x18; // EPLL clock = 13Mhz x (24+1) = 325MHz

    #else
        //For ADMUX MCP, use MPLL as EMI clock source
    #endif

        //1. Turn on all PLLs            
        //2. Wait auto band calibration
        //3. Set VCO band according to calibration result    
        //4. Disable auto band calibration    
        *UPLL_CON3 |= 0x0003; //0x701a_020c, power on and reset upll
        *UPLL_CON3 &= 0xfffe; //0x701a_020c, release reset
        while (!(*UPLL_CON4 & 0x0200)) {}
        *UPLL_CON1 = (*UPLL_CON1 & 0xffe0) | (*UPLL_CON4 & 0x001f);
        *UPLL_CON2 &= 0xefff;
        if(mode != PLL_MODE_USB_META)
        {

            *FPLL_CON3 |= 0x0003; //0x701a_060c, power on and reset upll
            *FPLL_CON3 &= 0xfffe; //0x701a_060c, release reset
            while (!(*FPLL_CON5 & 0x0200)) {}
            *FPLL_CON1 = (*FPLL_CON1 & 0xffe0) | (*FPLL_CON5 & 0x001f);
            *FPLL_CON2 &= 0xefff;

        }
    
            *MPLL_CON3 |= 0x0003; //0x701a_030c, power on and reset upll
            *MPLL_CON3 &= 0xfffe; //0x701a_030c, release reset    
            while (!(*MPLL_CON5 & 0x0200)) {}
            *MPLL_CON1 = (*MPLL_CON1 & 0xffe0) | (*MPLL_CON5 & 0x001f);
            *MPLL_CON2 &= 0xefff;
    
        *NPLL_CON3 |= 0x0003; //0x701a_040c, power on and reset upll
        *NPLL_CON3 &= 0xfffe; //0x701a_040c, release reset
        while (!(*NPLL_CON5 & 0x0200)) {}
        *NPLL_CON1 = (*NPLL_CON1 & 0xffe0) | (*NPLL_CON5 & 0x001f);
        *NPLL_CON2 &= 0xefff;
    
        *EPLL_CON3 |= 0x0003; //0x701a_050c, power on and reset upll
        *EPLL_CON3 &= 0xfffe; //0x701a_050c, release reset
        while (!(*EPLL_CON5 & 0x0200)) {}
        *EPLL_CON1 = (*EPLL_CON1 & 0xffe0) | (*EPLL_CON5 & 0x001f);
        *EPLL_CON2 &= 0xefff;
    
        //5. Disable unused PLLs since VCO calibration is done
        if(mode != PLL_MODE_USB_META)
        {
            *FPLL_CON3 &= 0xfffd;
        }
            *MPLL_CON3 &= 0xfffd;
        *NPLL_CON3 &= 0xfffd;
        *EPLL_CON3 &= 0xfffd;
        *UPLL_CON3 &= 0xfffd;

        //6. eanble PLLs with suitable VCO setting
        *UPLL_CON2 = (*UPLL_CON2 & 0xff80) | 0x0024; // Disable auto-K and configure UPLL clock = 26MHz x (36+1) /2 = 481MHz
        *UPLL_CON3 = *UPLL_CON3 | 0x0003;
        *UPLL_CON3 = *UPLL_CON3 & 0xfffe;
        //Wait 100us
        for(i=0; i < 2650; i++);
        if(mode != PLL_MODE_USB_META)
        {

            // For 624MHz clock source, turn-on FPLL
            *FPLL_CON2 = (*FPLL_CON2 & 0xff80) | 0x0017; // Disable auto-K and configure FPLL clock = 26MHz x (24+1) = 624MHz
            // 0x801A_060C Power on & Reset FPLL: [1]FPLL_PWDB=1, [0]FPLL_RST=1
            *FPLL_CON3 = *FPLL_CON3 | 0x0003;
            // 0x801A_060C Release reset UPLL: [1]FPLL_PWDB=1, [0]FPLL_RST=0
            *FPLL_CON3 = *FPLL_CON3 & 0xfffe;
            // 0x801A_060C Enable 48MHz clock generated from FPLL if you need: [2]FPLL_48M_EN=1
            *FPLL_CON3 = *FPLL_CON3 | 0x0004;

        }
        *MPLL_CON2 = (*MPLL_CON2 & 0xff80) | 0x13; //configure MPLL clock = 26MHz x (19+1) = 520MHz
        *MPLL_CON3 = *MPLL_CON3 | 0x0003;
        *MPLL_CON3 = *MPLL_CON3 & 0xfffe;
        //Wait 100us
        for(i=0; i < 2650; i++);

    #if defined(__MT6256_USE_NPLL__)
        // turn-on NPLL
        *NPLL_CON2 = (*NPLL_CON2 & 0xff80) | 0x0013; // Disable auto-K and configure NPLL clock = 26MHz x (19+1) = 520MHz
        // 0x801A_040C Power on & Reset NPLL: [1]NPLL_PWDB=1, [0]NPLL_RST=1
        *NPLL_CON3 = *NPLL_CON3 | 0x0003;
        // 0x801A_040C Release reset NPLL: [1]NPLL_PWDB=1, [0]NPLL_RST=0
        *NPLL_CON3 = *NPLL_CON3 & 0xfffe;
    #endif /* __MT6256_USE_NPLL__ */

        // Frequency hopping setting
        if(mode != PLL_MODE_USB_META)
        {
            *TDMA_FHCON4 |= 0x000B; /* enable BT, GSM scheme and free-run DDS */
        }

    #if defined(__MT6256_USE_NPLL__)
        // Turn-on NPLL free-run DDS
        // 0x801A_0A30: [5]NPLL_WILL_SWITCHED_TO_FRCTL=1
        *PLL_MISC_CON = *PLL_MISC_CON | 0x0020;
        // 0x801A_0A30: [6]NPLL_ SWITCHED_TO_FRCTL=1, [0]NPLL_FRDDS_EN=1
        *PLL_MISC_CON = *PLL_MISC_CON | 0x0041;
    #endif /* __MT6256_USE_NPLL__ */

        // EPLL is enabled in EMI driver
        *TDMA_FHCON6 |= 0x000B; /* enable BT, GSM scheme and free-run DDS */
        //Wait 100us
        for(i=0; i < 2650 ; i++);

    #if (defined(__EMI_CLK_200MHZ__) || defined(__EMI_CLK_166MHZ__))

        if(mode == PLL_MODE_USB_META)
        {
            *PLL_CON1 |= 0x0501; //EMIPLLSEL Bypass PLL, will be enabled in LPDDR init sequence
        }
        else
        {
            *PLL_CON1 = 0x0505; //EMIPLLSEL Bypass PLL, will be enabled in LPDDR init sequence
        }
    
    #elif defined(__EMI_CLK_133MHZ__)

        if(mode == PLL_MODE_USB_META)
        {
            *PLL_CON1 |= 0x0601; //EMIPLLSEL Bypass PLL, will be enabled in LPDDR init sequence
        }
        else
        {
            *PLL_CON1 = 0x0605; //EMIPLLSEL Bypass PLL, will be enabled in LPDDR init sequence
        }

    #else

        if(mode == PLL_MODE_USB_META)
        {
            *PLL_CON1 |= 0x0703; //It's no problem to enable all PLL for NOR+PSRAM    
        }
        else
        {
            *PLL_CON1 = 0x0707; //It's no problem to enable all PLL for NOR+PSRAM    
        }

    #endif

    }
    else /* before MT6256E5 */
    {
        /** PLL Calibtration Sequence */
        /* disable all PLLs */
        if(mode == PLL_MODE_USB_META)
        {
            *PLL_CON1 &= 0x8005; /* keep UPLL and MPLL */
            *PLL_CON1 |= 0x8000;
        }
        else
        {
            *PLL_CON1 = 0x8000;
        }

        if(mode != PLL_MODE_USB_META)
        {
            *UPLL_CON3 &= ~(0x0002);
            *MPLL_CON3 &= ~(0x0002);
        }
        *NPLL_CON3 &= ~(0x0002);
        *EPLL_CON3 &= ~(0x0002);
        *FPLL_CON3 &= ~(0x0002);

        /* re-enable VCO auto band calibration */
        if(mode != PLL_MODE_USB_META)
        {
            *UPLL_CON2 |= 0x1000; //re-enable VCO auto band calibration since it is cleared by BootROM
            *MPLL_CON2 |= 0x1000; //re-enable VCO auto band calibration since it is cleared by BootROM
        }
        *NPLL_CON2 |= 0x1000;
        *EPLL_CON2 |= 0x1000;
        *FPLL_CON2 |= 0x1000;

        /* All calibration should be complete within 700us        
            VCOCAL_FAIL=1 - failed IC
            VCOCAL_CPLT=1 - calibration complete
            [IvanTseng] SW workaround -- set vcoband with auto-K, and disable auto-K within 19us */
        
        /* Configure EMI PLL clock here but enable after LPDDR initialization */
        #if defined(__EMI_CLK_200MHZ__)

            *EPLL_CON2 = (*EPLL_CON2 & 0xff80) | 0x1D; // EPLL clock = 13Mhz x (29+1) = 390MHz
        
        #elif defined(__EMI_CLK_166MHZ__)

            *EPLL_CON2 = (*EPLL_CON2 & 0xff80) | 0x18; // EPLL clock = 13Mhz x (24+1) = 325MHz

        #else
            //For ADMUX MCP, use MPLL as EMI clock source
        #endif

        //1. Turn on all PLLs            
        //2. Wait auto band calibration
        //3. Set VCO band according to calibration result    
        //4. Disable auto band calibration    
        if(mode != PLL_MODE_USB_META)
        {
            *UPLL_CON3 |= 0x0003; //0x701a_020c, power on and reset upll
            *UPLL_CON3 &= 0xfffe; //0x701a_020c, release reset
            while (!(*UPLL_CON4 & 0x0200)) {}
            *UPLL_CON1 = (*UPLL_CON1 & 0xffe0) | (*UPLL_CON4 & 0x001f);
            *UPLL_CON2 &= 0xefff;

            *MPLL_CON3 |= 0x0003; //0x701a_030c, power on and reset upll
            *MPLL_CON3 &= 0xfffe; //0x701a_030c, release reset    
            while (!(*MPLL_CON5 & 0x0200)) {}
            *MPLL_CON1 = (*MPLL_CON1 & 0xffe0) | (*MPLL_CON5 & 0x001f);
            *MPLL_CON2 &= 0xefff;
        }
    
        *NPLL_CON3 |= 0x0003; //0x701a_040c, power on and reset upll
        *NPLL_CON3 &= 0xfffe; //0x701a_040c, release reset
        while (!(*NPLL_CON5 & 0x0200)) {}
        *NPLL_CON1 = (*NPLL_CON1 & 0xffe0) | (*NPLL_CON5 & 0x001f);
        *NPLL_CON2 &= 0xefff;
    
        *EPLL_CON3 |= 0x0003; //0x701a_050c, power on and reset upll
        *EPLL_CON3 &= 0xfffe; //0x701a_050c, release reset
        while (!(*EPLL_CON5 & 0x0200)) {}
        *EPLL_CON1 = (*EPLL_CON1 & 0xffe0) | (*EPLL_CON5 & 0x001f);
        *EPLL_CON2 &= 0xefff;
    
        *FPLL_CON3 |= 0x0003; //0x701a_060c, power on and reset upll
        *FPLL_CON3 &= 0xfffe; //0x701a_060c, release reset
        while (!(*FPLL_CON5 & 0x0200)) {}
        *FPLL_CON1 = (*FPLL_CON1 & 0xffe0) | (*FPLL_CON5 & 0x001f);
        *FPLL_CON2 &= 0xefff;
    
        //5. Disable unused PLLs
        if(mode != PLL_MODE_USB_META)
        {
            *UPLL_CON3 &= 0xfffd;
            *MPLL_CON3 &= 0xfffd;
        }
        *NPLL_CON3 &= 0xfffd;
        *EPLL_CON3 &= 0xfffd;
        *FPLL_CON3 &= 0xfffd;

        if(mode != PLL_MODE_USB_META)
        {
            *UPLL_CON2 = (*UPLL_CON2 & 0xff80) | 0x0017; // Disable auto-K and configure UPLL clock = 26MHz x (23+1) = 624MHz, then the UART clock will be 52MHz
            *UPLL_CON3 = *UPLL_CON3 | 0x0003;
            *UPLL_CON3 = *UPLL_CON3 & 0xfffe;
            //Wait 100us
            for(i=0; i < 2650; i++);

            *MPLL_CON2 = (*MPLL_CON2 & 0xff80) | 0x13; //configure MPLL clock = 26MHz x (19+1) = 520MHz
            *MPLL_CON3 = *MPLL_CON3 | 0x0003;
            *MPLL_CON3 = *MPLL_CON3 & 0xfffe;
            //Wait 100us
            for(i=0; i < 2650; i++);
        }

        // Frequency hopping setting
        if(mode != PLL_MODE_USB_META)
        {
            *TDMA_FHCON4 |= 0x000B;  /* enable BT, GSM scheme and free-run DDS */
        }
        *TDMA_FHCON6 |= 0x000B; /* enable BT, GSM scheme and free-run DDS */
        //Wait 100us
        for(i=0; i < 2650 ; i++);

    #if (defined(__EMI_CLK_200MHZ__) || defined(__EMI_CLK_166MHZ__))

        if(mode == PLL_MODE_USB_META)
        {
            *PLL_CON1 |= 0x0500; //EMIPLLSEL Bypass PLL, will be enabled in LPDDR init sequence
        }
        else
        {
            *PLL_CON1 = 0x0505; //EMIPLLSEL Bypass PLL, will be enabled in LPDDR init sequence
        }
    
    #elif defined(__EMI_CLK_133MHZ__)

        if(mode == PLL_MODE_USB_META)
        {
            *PLL_CON1 |= 0x0600; //EMIPLLSEL Bypass PLL, will be enabled in LPDDR init sequence
        }
        else
        {
            *PLL_CON1 = 0x0605; //EMIPLLSEL Bypass PLL, will be enabled in LPDDR init sequence
        }

    #else

        if(mode == PLL_MODE_USB_META)
        {
            *PLL_CON1 |= 0x0702; //It's no problem to enable all PLL for NOR+PSRAM    
        }
        else
        {
            *PLL_CON1 = 0x0707; //It's no problem to enable all PLL for NOR+PSRAM    
        }

    #endif

        switch(mode)
        {
            case PLL_MODE_MAUI:
            //0x701A_0108 & 0x701A_010C: clock division settings
            *PLL_CON2 = 0x0000;
            *PLL_CON3 = 0x0000;

            //0x701A_0110 & 0x701A_0114: clock division settings
    #if defined(MT6256)
            //ARM 520MHz
            *PLL_CON4 = 0x0000;
            *PLL_CON5 = 0x0000;
    #else
            //ARM 312MHZ
            *PLL_CON4 = 0x0002;
            *PLL_CON5 = 0x0002;
    #endif
            break;
            case PLL_MODE_USB_META:
            *PLL_CON2 &= 0x000F;
            *PLL_CON3 &= 0x000F;
            *PLL_CON4 &= 0x000F;
            *PLL_CON5 &= 0x000F;
            break;
        }
 
    } /* MT6256 E5 or latter  */
}
#endif  /* MT6256 */

#if defined(MT6251)
{
   unsigned int i;
   *UPLL_CON2 = 0x17;      // disable auto calibration and set UPLL to (23+1)*26=624Mhz 
   *UPLL_CON3 |= 0x0002;	// 0x8300_020C: Power-up UPLL
   *UPLL_CON3 |= 0x0001;	// 0x8300_020C: Reset UPLL
   *UPLL_CON3 &= 0xfffe;	// 0x8300_020C: Reset release
   
   for (i=0;i<2000;i++);   // delay until MPLL stable

   *MPLL_CON2 = 0x17;      // disable auto calibration and set MPLL to (23+1)*26=624Mhz (MCU/BUS is set to 78Mhz)    
   *MPLL_CON3 |= 0x0002;  // MPLL_CON1: Power on MPLL
   *MPLL_CON3 |= 0x0001;  // MPLL_CON1:reset MPLL
   *MPLL_CON3 &= 0xfffe;  // MPLL_CON1:reset release
   
   for (i=0;i<2000;i++);   // delay until MPLL stable

   *PLL_CON6 = 0xC000;
   *PLL_CON1 = 0x0415;    // DSP: MPLL 104Mhz, SF: MPLL 78Mhz, GSM: from UPLL, DCM: from MPLL 
   *PLL_CON2 = 0x0;
   *PLL_CON3 = 0x0;	
   *PLL_CON5 = 0x0;
	 *PLL_CON4 = 0x5575;    // Select MPLL, DPLL, UPLL output
}
#endif /* MT6251 */

#if defined(MT6575)

   /**
     * For BUS_GATED_EN,
     * 1. Enable Infrasys bus clock, peripheral sys master bus clock, peripheral sys slave bus clock, ARM sys bus clock, Fcore sys bus clock, MD2G sys bus lock, HSPA sys bus clock, MM sys bus clock, and audio sys bus's gating.
     * For ARMSYS_CON,
     */  
   //*(volatile kal_uint32 *)0x810D0558 = 0xffffffff;
   *PLL_BUS_GATED_EN = 0xffffffff;

   /*
    * modem clock switch setting
    */
   *PLL_CLKSW_CON0 = 0x1457; // set freq. divider for mcu/dsp/gsm clock
   //*(volatile kal_uint16 *)0x810D0910 = 0x1457; // set freq. divider for mcu/dsp/gsm clock
   *PLL_CLKSW_CON2 = 0x0555; // set clock mux to divider out
   //*(volatile kal_uint16 *)0x810D0918 = 0x0555; // set clock mux to divider out

#endif

#if defined(MT6255)
{
    kal_uint32 i;
    /* Setting target PLL frequency. */
    #if defined(__EMI_CLK_200MHZ__) /* DDR2_400 */
    {
        // 0x801A_0508: [6:0]EPLL_FBDIV = 29 ==> EPLL clock = 13*(29+1) = 390
        *PLL_EPLL_CON2 = (*PLL_EPLL_CON2 & 0xffc0) | 29;
    } 
    #elif defined(__EMI_CLK_166MHZ__) /* DDR_333 */
    {
        // 0x801A_0508: [6:0]EPLL_FBDIV = 24 ==> EPLL clock = 13*(24+1) = 325
        *PLL_EPLL_CON2 = (*PLL_EPLL_CON2 & 0xffc0) | 24;
    } 
    #elif defined(__EMI_CLK_133MHZ__) /* DDR_266 */
    {
        // 0x801A_0508: [6:0]EPLL_FBDIV = 24 ==> EPLL clock = 13*(19+1) = 260
        *PLL_EPLL_CON2 = (*EPLL_CON2 & 0xffc0) | 19;
    }
    #else /*( PSRAM_104)*/
    {
	      // use MPLL as EMI clock source
    }
    #endif

    /* According to DE's comment, when PLL APB write is complete, PLL analog part would get such setting immediately.
     * Therefore, one APB dummy read can eusure that write operation reach destination.
     */
    PLL_APB_DUMMY_READ;

    if(mode != PLL_MODE_USB_META)
    {
        /* standard PLL power-on sequence with frequency hopping */

        // 0x801A_020C Power on & Reset UPLL: [1]UPLL_PWDB=1, [0]UPLL_RST=1
        *PLL_UPLL_CON3 = *PLL_UPLL_CON3 | 0x0003;
        /* According to DE's comment, when PLL APB write is complete, PLL analog part would get such setting immediately.
         * Therefore, one APB dummy read can eusure that write operation reach destination.
         */
        PLL_APB_DUMMY_READ;
        for(i = 0 ; i < 6 ; i++); /* Wait 200ns */
    
        // 0x801A_020C Release reset UPLL: [1]UPLL_PWDB=1, [0]UPLL_RST=0
        *PLL_UPLL_CON3 = *PLL_UPLL_CON3 & 0xfffe;
        /* According to DE's comment, when PLL APB write is complete, PLL analog part would get such setting immediately.
         * Therefore, one APB dummy read can eusure that write operation reach destination.
         */
        PLL_APB_DUMMY_READ;
        for(i = 0 ; i < 2601 ; i++); /* Wait 100us */

        // 0x801A_030C: Power on & Reset MPLL: : [2]MDDS_EN=1, [1]MPLL_PWDB=1, [0]MPLL_RST=1
        *PLL_MPLL_CON3 = *PLL_MPLL_CON3 | 0x0007;
        /* According to DE's comment, when PLL APB write is complete, PLL analog part would get such setting immediately.
         * Therefore, one APB dummy read can eusure that write operation reach destination.
         */
        PLL_APB_DUMMY_READ;
        for(i = 0 ; i < 6 ; i++); /* Wait 200ns */
        // 0x801A_030C: Release reset MPLL: [1]MPLL_PWDB=1, [0]MPLL_RST=0
        *PLL_MPLL_CON3 = *PLL_MPLL_CON3 & 0xfffe;
        /* According to DE's comment, when PLL APB write is complete, PLL analog part would get such setting immediately.
         * Therefore, one APB dummy read can eusure that write operation reach destination.
         */
        PLL_APB_DUMMY_READ;
    
        /* 
           Setting FHCTL_SRAM (TDMA_FHCON2 & TDMA_FHCON3)
           Setting BTFH_SRAM (BTFH_CON0~5)
           Setting FHCTL_FSM, include SFSTR or Free-run DDS mode (TDMA_FHCON4, 5, 6 & 7)
        */
        // FHCTL_MNPLL_BTEN(TDMA_CON4[1]) or FHCTL_MNPLL_GSMEN(TDMA_CON4[0]) will switch the MPLLs control interface to FHCTL_FSM
        // FHCTL_MNPLL_BTEN(TDMA_CON4[3]) will enable the free-run DDS for MPLLs
        *PLL_TDMA_FHCON4 = *PLL_TDMA_FHCON4 | 0x000B;
        /* According to DE's comment, when PLL APB write is complete, PLL analog part would get such setting immediately.
         * Therefore, one APB dummy read can eusure that write operation reach destination.
         */
        PLL_APB_DUMMY_READ;
    }

    #if defined(__EMI_CLK_200MHZ__) || defined(__EMI_CLK_166MHZ__) || defined(__EMI_CLK_133MHZ__) /*(DDR2_400 | DDR_333 | DDR_266)*/

    // 0x801A_050C: Power on & Reset EPLL: [2]EDDS_EN=1, [1]EPLL_PWDB=1, [0]EPLL_RST=1
    *PLL_EPLL_CON3 = *PLL_EPLL_CON3 | 0x0007;
    /* According to DE's comment, when PLL APB write is complete, PLL analog part would get such setting immediately.
     * Therefore, one APB dummy read can eusure that write operation reach destination.
     */
    PLL_APB_DUMMY_READ;
    for(i = 0 ; i < 6 ; i++); /* Wait 200ns */
    // 0x801A_050C: Release reset EPLL: [1]EPLL_PWDB=1, [0]EPLL_RST=0
    *PLL_EPLL_CON3 = *PLL_EPLL_CON3 & 0xfffe;
    /* According to DE's comment, when PLL APB write is complete, PLL analog part would get such setting immediately.
     * Therefore, one APB dummy read can eusure that write operation reach destination.
     */
    PLL_APB_DUMMY_READ;
    
    if(mode != PLL_MODE_USB_META)
    {
        // FHCTL_EFPLL_BTEN(TDMA_CON6[1]) or FHCTL_EFPLL_GSMEN(TDMA_CON6[0]) will switch the EPLLs control interface to FHCTL_FSM
        // FHCTL_EFPLL_BTEN(TDMA_CON6[3]) will enable the free-run DDS for EPLLs.
        // 0x801A_0818: [1]FHCTL_EFPLL_BTEN=1,[0]FHCTL_EFPLL_GSMEN=1,[3]EFPLL_FRDDS_EN=1
        *PLL_TDMA_FHCON6 = *PLL_TDMA_FHCON6 | 0x000B;
        /* According to DE's comment, when PLL APB write is complete, PLL analog part would get such setting immediately.
         * Therefore, one APB dummy read can eusure that write operation reach destination.
         */
        PLL_APB_DUMMY_READ;
    }

    #else /* (PSRAM_104) */
    // use MPLL as EMI clock source

	  #endif

    for(i = 0 ; i < 2601 ; i++); /* Wait 100us */

    if(mode != PLL_MODE_USB_META)
    {
        #if defined(__EMI_CLK_200MHZ__) || defined(__EMI_CLK_166MHZ__) || defined(__EMI_CLK_133MHZ__) /*(DDR2_400 | DDR_333 | DDR_266)*/

        // 0x801A_0104: [11:10]DSPPLLSEL=01, [9:8]EMIPLLSEL=01,[2]UPLLSEL=1, [1]EPLLSEL=1,[0]MPLLSEL=1
        *PLL_PLL_CON1 = 0x0507;

        #else  /*(PSRAM_104)*/

        // 0x801A_0104: [11:10]DSPPLLSEL=01,[9:8]EMIPLLSEL=11, [2]UPLLSEL=1, [1]EPLLSEL=1,[0]MPLLSEL=1
        *PLL_PLL_CON1 = 0x0707;

        #endif
        /* According to DE's comment, when PLL APB write is complete, PLL analog part would get such setting immediately.
         * Therefore, one APB dummy read can eusure that write operation reach destination.
         */
        PLL_APB_DUMMY_READ;

        // select MCU clock frequency
        #if defined(MCU_416M)
        *CONF_HW_MISC &= ~(0x80000000);
        #elif defined(MCU_312M)
        *CONF_HW_MISC |= 0x80000000;
        #endif
        *CONF_HW_MISC;
    }
    else // PLL_MODE_USB_META
    {
        // switch EMI and DSP to EPLL and MPLL repsctively
        #if defined(__EMI_CLK_200MHZ__) || defined(__EMI_CLK_166MHZ__) || defined(__EMI_CLK_133MHZ__) /*(DDR2_400 | DDR_333 | DDR_266)*/

        // 0x801A_0104: [11:10]DSPPLLSEL=01, [9:8]EMIPLLSEL=01, [1]EPLLSEL=1
        *PLL_PLL_CON1 |= 0x0502;

        #else  /*(PSRAM_104)*/

        // 0x801A_0104: [11:10]DSPPLLSEL=01, [9:8]EMIPLLSEL=11, [1]EPLLSEL=1
        *PLL_PLL_CON1 |= 0x0702;

        #endif
        /* According to DE's comment, when PLL APB write is complete, PLL analog part would get such setting immediately.
         * Therefore, one APB dummy read can eusure that write operation reach destination.
         */
        PLL_APB_DUMMY_READ;
    }

    // 0x801A_0108 & 0x801A_010C: clock DIV setting
    *PLL_PLL_CON2 = 0x0000;
    *PLL_PLL_CON3 = 0x0000;
    // 0x801A_0110 & 0x801A_0114: clock DCM setting
    *PLL_PLL_CON4 = 0x0000;
    *PLL_PLL_CON5 = 0x0000;
    /* According to DE's comment, when PLL APB write is complete, PLL analog part would get such setting immediately.
     * Therefore, one APB dummy read can eusure that write operation reach destination.
     */
    PLL_APB_DUMMY_READ;

}
#endif /* MT6255 */

#if defined(MT6250)

    kal_uint32 i, reg_val;

    if(mode == PLL_MODE_MAUI)
    {
        // Sequence to enable PLL
        //wait  3us  for CLKSQ settle (in 26Mhz)
        for(i  = 0 ; i < 39 ; i++);

        // enable TOPSM control 
        *PLL_PLL_CON2 = 0x0000; // 0xA0170048, bit 12 and bit 10 set to 0 to enable TOPSM control
        *PLL_PLL_CON3 = 0x0000; // 0xA017004C, bit 12 and bit 8 set to 0 to enable TOPSM control

        // enable delay control 
        *PLL_PLLTD_CON0= 0x0000; //0x A0170700, bit 0 set to 0 to enable delay control

        //wait for 3us for TOPSM and delay (HW) control signal stable (in 26Mhz)
        for(i  = 0 ; i < 39 ; i++);

        // enable UPLL
        *PLL_UPLL_CON0  = 0x0B01 ; //0xA0170140, bit 0 set to 1 to enable UPLL and generate reset of UPLL

        // enable MDDS
        *PLL_MDDS_CON0 = 0x0001; //0x A0170640, bit 0 set to 1 to enable MDDS

        //Enable MPLL
        *PLL_MPLL_CON0  = 0x0E01; // 0xA0170100, bit 0 set to 1 to enable MPLL and generate reset of MPLL
 
        //wait  50~70us  for MPLL settle (in 26Mhz)
        for(i  = 0 ; i < 910 ; i++);

        *PLL_CLK_CONDA = 0x8610;  // 0xA001_0100, bit 10 set to 1 to select ARM PLL clock source 2 to 87Mhz
        // Sequence for switching to PLL clocks as below:
        *PLL_CLK_CONDC = 0x8049;  // 0xA001_0108, bit 15 set to 1 to enable digital frequency divider

        #if defined(__EMI_CLK_104MHZ__)
        *PLL_CLK_CONDH |= 0x8;       // 0xA001_011C, rg_bus4x_mux_sel = 1'b1 for EMI 2X clock @ 208Mhz
        reg_val = 0xBEA0; 
        #elif defined(__EMI_CLK_130MHZ__)
        *PLL_CLK_CONDH &= ~(0x8);    // 0xA001_011C, rg_bus4x_mux_sel = 1'b0 for EMI 2X clock @ 260Mhz
        reg_val = 0xBF20; 
        #endif

        #if defined(__SERIAL_FLASH_STT_EN__) || defined(__SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__)
        /* keep SFI to 26Mhz */
        reg_val |= (0x0001);  // 0xA001_0108, rg_sfc_gfmux_sel = 3・b001,
        #else /* !__SERIAL_FLASH_STT_EN__ */
        /* switch SFI to PLL */
        *PLL_CLK_CONDH &= ~(0x7); 
        #if defined(__SFI_CLK_130MHZ__)
        *PLL_CLK_CONDH |= 0x1;    // 0xA001_011C, rg_sfc_mux_sel = 3・b001, 
        reg_val |= (0x0004);  // 0xA001_0108, rg_sfc_gfmux_sel = 3・b100,
        #elif defined(__SFI_CLK_104MHZ__)
        *PLL_CLK_CONDH |= 0x3;    // 0xA001_011C, rg_sfc_mux_sel = 3・b011, 
        reg_val |= (0x0002);  // 0xA001_0108, rg_sfc_gfmux_sel = 3・b010,
        #else /* default __SFI_CLK_78MHZ__ */
        *PLL_CLK_CONDH |= 0x4;    // 0xA001_011C, rg_sfc_mux_sel = 3・b100, 
        reg_val |= (0x0004);  // 0xA001_0108, rg_sfc_gfmux_sel = 3・b100,
        #endif
        #endif /* __SERIAL_FLASH_STT_EN__ */

        *PLL_CLK_CONDC = reg_val; // 0xA001_0108, sfc_gfmux_sel = 3・b010, 
                                  // arm_gfmux_sel =2・b100,
                                  // bus4x_gfmux_sel=2・b010
                                  // dsp_gfmux_sel = 1・b1, x4g_gfmux_sel=1・b1, slcd_gfmux_sel=1・b1
                                  // rg_pllck_sel = 1・b1
         //*PLL_FH_CON4 |= 0x0008; // enable free-run DDS => moved to L1 FH control code
    }
    else
    {
        /* During META mode, no frequency hopping is required. 
         * However, since SFC and EMI uses MPLL as clock source under 104Mhz case in Maui mode, 
         * and the actual clock rate divided from MPLL is 97.5Mhz, META mode also changes to MPLL
         * under 104Mhz case to avoid SFC or EMI device timing setting variance.
         */
        *PLL_CLK_CONDA = 0x8610;  // 0xA001_0100, bit 10 set to 1 to select ARM PLL clock source 2 to 87Mhz

        /* switch bus clock to 26Mhz before changing EMI clock setting */
        reg_val = *PLL_CLK_CONDC; // 0xA001_0108
        reg_val &= ~(0x01C0);  
        reg_val |= 0x0040;
        *PLL_CLK_CONDC = reg_val; // 0xA001_0108, rg_bus_gfmux_sel  = 3'b001
        reg_val = *PLL_CLK_CONDC; // 0xA001_0108
        reg_val &= ~(0x01C0);  
        #if defined(__EMI_CLK_104MHZ__)
        *PLL_CLK_CONDH |= 0x8;       // 0xA001_011C, rg_bus4x_mux_sel = 1'b1 for EMI 2X clock @ 208Mhz
        reg_val |= 0x0080; // 0xA001_0108, rg_bus_gfmux_sel  = 3'b010
        #elif defined(__EMI_CLK_130MHZ__)
        *PLL_CLK_CONDH &= ~(0x8);    // 0xA001_011C, rg_bus4x_mux_sel = 1'b0 for EMI 2X clock @ 260Mhz
        reg_val |= 0x0100; // 0xA001_0108, rg_bus_gfmux_sel  = 3'b100
        #endif
        *PLL_CLK_CONDC = reg_val;

        #if defined(__SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__)
        /* keep SFI to 26Mhz */
        reg_val |= (0x0001);  // 0xA001_0108, rg_sfc_gfmux_sel = 3・b001,
        #else
        /* switch SFI to PLL */
        reg_val = *PLL_CLK_CONDC;
        reg_val &= ~(0x0007); 
        *PLL_CLK_CONDH &= ~(0x7); 
        #if defined(__SFI_CLK_130MHZ__)
        *PLL_CLK_CONDH |= 0x1;    // 0xA001_011C, rg_sfc_mux_sel = 3・b001, 
        reg_val |= (0x0004);  // 0xA001_0108, rg_sfc_gfmux_sel = 3・b100,
        #elif defined(__SFI_CLK_104MHZ__)
        *PLL_CLK_CONDH |= 0x3;    // 0xA001_011C, rg_sfc_mux_sel = 3・b011, 
        reg_val |= (0x0002);  // 0xA001_0108, rg_sfc_gfmux_sel = 3・b010,
        #else /* default __SFI_CLK_78MHZ__ */
        *PLL_CLK_CONDH |= 0x4;    // 0xA001_011C, rg_sfc_mux_sel = 3・b100, 
        reg_val |= (0x0004);  // 0xA001_0108, rg_sfc_gfmux_sel = 3・b100,
        #endif
        #endif /* !__SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__ */
        *PLL_CLK_CONDC = reg_val; 

        /* switch GSM, DSP to PLL */
        *PLL_CLK_CONDC |= 0x2E00;  // 0xA001_0108, rg_dsp_gfmux_sel = 1'b1, rg_dsp_gsmux_sel = 1・b1, slcd_gfmux_sel=1・b1
    }

#endif /* MT6250 */

#if defined(MT6260)

    volatile kal_uint32 i, reg_val, loop_1us;
    
    loop_1us = 13;

    if(mode == PLL_MODE_MAUI)
    {
        // MCU @ 26Mhz
    }
    else if( mode == PLL_MODE_USB_META) /* Need to keep USB connection */
    {
        // change MCU and bus back to @ 26Mhz
        *PLL_CLK_CONDC = 0x8048; // 0xA001_0108, switch to 26Mhz
        // wait for switch takes effect
        while(*PLL_CLK_CONDC & 0x2);
        *PLL_CLK_CONDC = 0x0048; // 0xA001_0108, bit 15 set to 0 to disable digital frequency divider
    }

    {
        // enable HW mode TOPSM control and clock CG of PLL control 

        *PLL_PLL_CON2 = 0x0000; // 0xA0170048, bit 12, 10 and 8 set to 0 to enable TOPSM control 
                                // bit 4, 2 and 0 set to 0 to enable clock CG of PLL control
        *PLL_PLL_CON3 = 0x0000; // 0xA017004C, bit 12 set to 0 to enable TOPSM control

        // enable delay control 
        *PLL_PLLTD_CON0= 0x0000; //0x A0170700, bit 0 set to 0 to enable delay control

        //wait for 3us for TOPSM and delay (HW) control signal stable
        for(i = 0 ; i < loop_1us*3 ; i++);

        //enable and reset UPLL
        reg_val = *PLL_UPLL_CON0;
        reg_val |= 0x0001;
        *PLL_UPLL_CON0  = reg_val; // 0xA0170140, bit 0 set to 1 to enable UPLL and generate reset of UPLL
     
        //select EPLL frequency
        #if defined(__EMI_CLK_104MHZ__)
        *PLL_EPLL_CON0  = 0x0B00; // 0xA0170180, set EPLL = 624M
        #elif defined(__EMI_CLK_166MHZ__)
        *PLL_EPLL_CON0  = 0x1840; // 0xA0170180, set EPLL = 650M
        *PLL_EPLL_CON1 |= 0x0100; // 0xA0170184, bit [10:8] = 3・b001 to increase EPLL stability
        #elif defined(__EMI_CLK_133MHZ__)
        *PLL_EPLL_CON0  = 0x0E00; // 0xA0170180, set EPLL = 780M
        #endif

        //enable MDDS
        *PLL_MDDS_CON0 = 0x0001; //0x A0170640, bit 0 set to 1 to enable MDDS

        //enable and reset MPLL
        reg_val = *PLL_MPLL_CON0;
        reg_val  |= 0x0001;
        *PLL_MPLL_CON0  = reg_val; //0xA0170100, bit 0 set to 1 to enable MPLL and generate reset of MPLL

        // wait for 1us to reduce UPLL glitch due to LDO drop
        for(i = 0 ; i < loop_1us ; i++);

        //enable EDDS
        *PLL_EDDS_CON0 = 0x0001; //0x A0170680, bit 0 set to 1 to enable EDDS

        //enable and reset EPLL
        reg_val = *PLL_EPLL_CON0;
        reg_val  |= 0x0001;
        *PLL_EPLL_CON0  = reg_val; //0xA0170180, bit 0 set to 1 to enable EPLL and generate reset of EPLL

        //wait 70us for PLL and DDS settle
        for(i = 0 ; i < loop_1us*70 ; i++);

        // Sequence to switch to PLL clocks as below: 
        #if defined(__EMI_CLK_166MHZ__)
        *PLL_CLK_CONDB |= 0x4000; //0xA001_0104, bit 14 set to 1 for MCU BUS clock = EMI1X/3
        // wait for 1us for bus divider setting from div2 to div3
        for(i = 0 ; i < loop_1us ; i++);
        #endif

        *PLL_CLK_CONDC = 0x8048;   // 0xA001_0108, bit 15 set to 1 to enable digital frequency divider

        #if defined(__EMI_CLK_104MHZ__)
          #if defined(__SFI_CLK_104MHZ__)
        *PLL_CLK_CONDH = 0xD012 ; // 0xA001_011C, rg_bus4x_mux_sel = 3'b001 for EMI 2X clock @ 208Mhz
                                  //              rg_sfc_mux_Sel=4・b0010 for SFC clock @ 104Mhz
          #elif defined(__SFI_CLK_130MHZ__)
        *PLL_CLK_CONDH = 0xD011; // 0xA001_011C, rg_bus4x_mux_sel = 3'b001 for EMI 2X clock @ 208Mhz
                                 //              rg_sfc_mux_Sel=4・b0001 for SFC clock @ 121Mhz
          #elif defined(__SFI_CLK_166MHZ__)
        *PLL_CLK_CONDH = 0xD01B; // 0xA001_011C, rg_bus4x_mux_sel = 3'b001 for EMI 2X clock @ 208Mhz
                                 //              rg_sfc_mux_Sel=4・b1011 for SFC clock @ 156Mhz
          #elif defined(__SFI_CLK_78MHZ__)
        *PLL_CLK_CONDH = 0xD014; // 0xA001_011C, rg_bus4x_mux_sel = 3'b001 for EMI 2X clock @ 208Mhz
                                 //              rg_sfc_mux_Sel=4・b0100 for SFC clock @ 72Mhz
          #endif

        #elif defined(__EMI_CLK_166MHZ__)
          #if defined(__SFI_CLK_104MHZ__)
        *PLL_CLK_CONDH = 0xD002; // 0xA001_011C, rg_bus4x_mux_sel = 3'b000 for EMI 2X clock @ 325Mhz
                                 //              rg_sfc_mux_Sel=4・b0010 for SFC clock @ 104Mhz
          #elif defined(__SFI_CLK_130MHZ__)
        *PLL_CLK_CONDH = 0xD001; // 0xA001_011C, rg_bus4x_mux_sel = 3'b000 for EMI 2X clock @ 325Mhz
                                 //              rg_sfc_mux_Sel=4・b1100 for SFC clock @ 121Mhz
          #elif defined(__SFI_CLK_166MHZ__)
        *PLL_CLK_CONDH = 0xD00B; // 0xA001_011C, rg_bus4x_mux_sel = 3'b000 for EMI 2X clock @ 325Mhz
                                 //              rg_sfc_mux_Sel=4・b1101 for SFC clock @ 162Mhz
          #elif defined(__SFI_CLK_78MHZ__)
        *PLL_CLK_CONDH = 0xD004; // 0xA001_011C, rg_bus4x_mux_sel = 3'b000 for EMI 2X clock @ 325Mhz
                                 //              rg_sfc_mux_Sel=4・b0100 for SFC clock @ 72Mhz
          #endif

        #elif defined(__EMI_CLK_133MHZ__)
          #if defined(__SFI_CLK_104MHZ__)
        *PLL_CLK_CONDH = 0xD012; // 0xA001_011C, rg_bus4x_mux_sel = 3'b001 for EMI 2X clock @ 260Mhz
                                 //              rg_sfc_mux_Sel=4・b0010 for SFC clock @ 104Mhz
          #elif defined(__SFI_CLK_130MHZ__)
        *PLL_CLK_CONDH = 0xD011; // 0xA001_011C, rg_bus4x_mux_sel = 3'b001 for EMI 2X clock @ 260Mhz
                                 //              rg_sfc_mux_Sel=4・b1101 for SFC clock @ 121Mhz
          #elif defined(__SFI_CLK_166MHZ__)
        *PLL_CLK_CONDH = 0xD01C; // 0xA001_011C, rg_bus4x_mux_sel = 3'b001 for EMI 2X clock @ 260Mhz
                                 //              rg_sfc_mux_Sel=4・b1100 for SFC clock @ 156Mhz
          #elif defined(__SFI_CLK_78MHZ__)
        *PLL_CLK_CONDH = 0xD014; // 0xA001_011C, rg_bus4x_mux_sel = 3'b001 for EMI 2X clock @ 260Mhz
                                 //              rg_sfc_mux_Sel=4・b0100 for SFC clock @ 78Mhz
          #endif
        #endif

        #if defined(__SERIAL_FLASH_STT_EN__) || defined(__SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__) || defined(__SPI_NAND_SUPPORT__)
        
        *PLL_CLK_CONDC = 0xB6A0;  // 0xA001_0108, sfc_gfmux_sel = 1・b0, keep SFC @ 26Mhz
                                  //             arm_gfmux_sel =3・b100,
                                  //             bus4x_gfmux_sel=3・b010,
                                  //             dsp_gfmux_sel = 1・b1,
                                  //             x4g_gfmux_sel=1・b1,                            
                                  //             rg_pllck_sel = 1・b1
        #else

        *PLL_CLK_CONDC = 0xB6A1;  // 0xA001_0108, sfc_gfmux_sel = 1・b1, 
                                  //             arm_gfmux_sel =3・b100,
                                  //             bus4x_gfmux_sel=3・b010,
                                  //             dsp_gfmux_sel = 1・b1,
                                  //             x4g_gfmux_sel=1・b1,                            
                                  //             rg_pllck_sel = 1・b1
        #endif
    }
#endif /* MT6260 */

}


#ifdef __MTK_TARGET__
#pragma arm section code
#endif /* __MTK_TARGET__ */

#ifndef __FUE__

/*************************************************************************
* FUNCTION
*  INT_SwitchMCUClock
*
* DESCRIPTION
*   This function intended for switching MCU clock.
* Be very careful that, before this function is called, user must ensure
* that there is very save EMI setting.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool INT_SwitchMCUClock(mcu_clock_enum inputclk)
{
   kal_uint32 savedMask;
   kal_bool   status=KAL_TRUE;
   
   savedMask = SaveAndSetIRQMask();
   
#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6225)

   switch (inputclk) {

   case MCU_13MHZ:

      *MCUCLK_CON = 0x0000;

      break;

   case MCU_26MHZ:

      *MCUCLK_CON = 0x0101;

      break;

   case MCU_52MHZ:

      *MCUCLK_CON = 0x0303;

      break;

   case MCU_104MHZ:

      *MCUCLK_CON = 0x0703;

      break;

   default:

      status = KAL_FALSE;

      break;
   }
   
#elif defined(MT6223)	|| defined(MT6223P)

   switch ( inputclk )
   {
      case MCU_13MHZ: *MCUCLK_CON &= 0x00f0 ;
                      break;
      case MCU_26MHZ: *MCUCLK_CON &= 0x00f0 ;
                      *MCUCLK_CON |= 0x01f1 ;
                      break;
      case MCU_39MHZ: *MCUCLK_CON &= 0x00f0 ;
                      *MCUCLK_CON |= 0x02f2 ;
                      break;
      case MCU_52MHZ: *MCUCLK_CON &= 0x00f0 ;
                      *MCUCLK_CON |= 0x03f3 ;
                      break;
      default : status = KAL_FALSE;
   }   
   

#elif defined(MT6217) || defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6227D) || defined(MT6226D)

   switch ( inputclk )
   {
      case MCU_13MHZ: *(volatile kal_uint16 *)0x80000114 = 0x0000 ;
                      break;
      case MCU_26MHZ: *(volatile kal_uint16 *)0x80000114 = 0x0001 ;
                      break;
      case MCU_39MHZ: *(volatile kal_uint16 *)0x80000114 = 0x0002 ;
                      break;
      case MCU_52MHZ: *(volatile kal_uint16 *)0x80000114 = 0x0003 ;
                      break;
      default : status = KAL_FALSE;
   }
   
#elif defined(MT6218B) || defined(MT6219)

   #ifdef EXT_26M   
   
      switch ( inputclk )
      {
         case MCU_13MHZ: /* Bypass MPLL, but retain MCU_DIV2 */
                         *(volatile kal_uint16 *)0x80000108 |= 0x0008;
                         *(volatile kal_uint16 *)0x80000108 &= ~(0x0002);                         
                         break;
         case MCU_26MHZ: /* Bypass MPLL and MCU_DIV2*/
                         *(volatile kal_uint16 *)0x80000108 &= ~(0x000a);
                         break;
         case MCU_52MHZ: /* Do not bypass both MPLL and MCU_DIV2*/
                         *(volatile kal_uint16 *)0x80000108 |= 0x000a;
                         break;
      default : status = KAL_FALSE;
         
      }
      
   #elif defined EXT_13M
   
      switch ( inputclk )
      {
         case MCU_13MHZ: /* Bypass MPLL and MCU_DIV2*/
                         *(volatile kal_uint16 *)0x80000108 &= ~(0x000a);
                         break;
         case MCU_26MHZ: /* Bypass MPLL and MCU_DIV2*/
                         *(volatile kal_uint16 *)0x80000108 &= ~(0x000a);
                         *(volatile kal_uint16 *)0x80000100 = 0x01;
                         {
                            kal_uint8  i;
                            // delay until PLL is stable
		                      for (i=0;i<200;i++);
                         }
                         *(volatile kal_uint16 *)0x80000108 |= 0x0002;
                         break;
         case MCU_52MHZ: /* Bypass MPLL and MCU_DIV2*/
                         *(volatile kal_uint16 *)0x80000108 &= ~(0x000a);
                         *(volatile kal_uint16 *)0x80000100 = 0x03;
                         {
                            kal_uint8  i;
                            // delay until PLL is stable
		                      for (i=0;i<200;i++);
                         }
                         *(volatile kal_uint16 *)0x80000108 |= 0x0002;
                         break;
         default : status = KAL_FALSE;
      }
       
   #endif /* EXT_26M */ 
   
#elif defined(MT6235) || defined(MT6235B)
      switch ( inputclk )
      {

   case MCU_13MHZ:

      *MCUCLK_CON = 0x7000;

      break;

   case MCU_26MHZ:

      *MCUCLK_CON = 0x7111;

      break;

   case MCU_52MHZ:

      *MCUCLK_CON = 0x7333;

      break;

   case MCU_104MHZ:

      *MCUCLK_CON = 0x7737;

      break;

   case MCU_208MHZ:

      *MCUCLK_CON = 0x7F37;

      break;

   default:

      status = KAL_FALSE;

      break;
    }

#elif defined(MT6238) || defined(MT6239)

	if(ENG_E1 == mt6238_version)
	{
	      switch ( inputclk )
	      {

	   case MCU_13MHZ:

	      *MCUCLK_CON = 0x7000;

	      break;

	   case MCU_26MHZ:

	      *MCUCLK_CON = 0x7111;

	      break;

	   case MCU_52MHZ:

	      *MCUCLK_CON = 0x7333;

	      break;

	   case MCU_104MHZ:

	      *MCUCLK_CON = 0x7737;

	      break;

	   case MCU_208MHZ:

	      *MCUCLK_CON = 0x7F37;

	      break;

	   default:

	      status = KAL_FALSE;

	      break;
	    }
	}
	else if(ENG_E2 == mt6238_version)
	{
	      switch ( inputclk )
	      {

	   case MCU_13MHZ:

	      *MCUCLK_CON = 0x0000;

	      break;

	   case MCU_26MHZ:

	      *MCUCLK_CON = 0x1111;

	      break;

	   case MCU_52MHZ:

	      *MCUCLK_CON = 0x3333;

	      break;

	   case MCU_104MHZ:

	      *MCUCLK_CON = 0x7737;

	      break;

	   case MCU_208MHZ:

	      *MCUCLK_CON = 0x7F37;

	      break;

	   default:

	      status = KAL_FALSE;

	      break;
	    }
	}

#elif defined(MT6268A)  || defined(MT6268)

   switch (inputclk)
   {
   case MCU_15_36MHZ:
      *MCUCLK_CON = 0x0421;
      break;

   case MCU_30_72MHZ:
      *MCUCLK_CON = 0x0C63;
      break;

   case MCU_61_44MHZ:
      *MCUCLK_CON = 0x1CE7;
      break;

   case MCU_122_88MHZ:
      *MCUCLK_CON = 0x3DE7;
      break;

   case MCU_245_76MHZ:
      *MCUCLK_CON = 0x7DE7;
      break;

   default:
      status = KAL_FALSE;
      break;
    }


#elif defined(MT6253T) || defined(MT6253)

switch (inputclk) {

   case MCU_13MHZ:

      *MCUCLK_CON = 0x3080;

      break;

   case MCU_52MHZ:

      *MCUCLK_CON = 0x3383;

      break;

   case MCU_104MHZ:

      *MCUCLK_CON = 0x3783;

      break;

   default:

      status = KAL_FALSE;

      break;
   }

#elif defined(MT6516) && defined(__APPLICATION_PROCESSOR__)
// Do Nothing

#elif defined(MT6516) && !defined(__APPLICATION_PROCESSOR__)

switch (inputclk) {

   case MCU_52MHZ:

      *MCUCLK_CON = 0x07;

      break;

   case MCU_104MHZ:

      *MCUCLK_CON = 0x17;

      break;

   default:

      status = KAL_FALSE;

      break;
   }

#elif defined(MT6236) || defined(MT6236B)

   switch (inputclk) {
   case MCU_312MHZ:
      *MCUCLK_CON = 0x2000;
      break;
   case MCU_152MHZ:
      *MCUCLK_CON = 0x1000;
      break;
   case MCU_78MHZ:
      *MCUCLK_CON = 0x0100;
      break;
   case MCU_13MHZ:
      *MCUCLK_CON = 0x0000;
      break;
   default:
      status = KAL_FALSE;
      break;
   }

#elif defined(MT6256)


#endif

   RestoreIRQMask(savedMask);
   
   return status;
}

#if defined(MT6250)
/*************************************************************************
* FUNCTION
*  mt6250_fm_force_upll_on
*
* DESCRIPTION
*   This function intended for MT6250 FM issue ONLY.
* According to the conclusion of issue discussion, this function is only 
* used by FM driver in MT6250.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void mt6250_fm_force_upll_on(kal_bool force_on)
{
    if(force_on)
    {
        /* keep 26Mhz and UPLL forced on */
        *PLL_DPM_CON0 |= 0x22;
    }
    else
    {
        /* remove 26Mhz and UPLL forced on */
        *PLL_DPM_CON0 &= ~(0x22);
    }
    *PLL_DPM_CON0;
}
#endif /* MT6250 */

#endif

#if (!defined(__UBL__) && !defined(__FUE__)) && defined(__MTK_TARGET__)

#ifdef __MTK_TARGET__
#pragma arm section code = "INTSRAM_ROCODE", rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#endif /* __MTK_TARGET__ */

extern kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...);

#if defined(MT6256_S01)
__align(8) kal_uint32 PLL_Stack_Pool_Init[PLL_SWITCH_STACK_SIZE>>2];
volatile kal_bool  pll_dds_off = KAL_FALSE;
volatile kal_uint32  pll_dds_switch_cycles;
#endif /* MT6256_S01 */

/*************************************************************************
* FUNCTION
*  INT_SwitchMCUClock
*
* DESCRIPTION
*   This function intended for switching MCU clock.
* Be very careful that, before this function is called, user must ensure
* that there is very save EMI setting.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if defined(MT6256_S01)

static kal_bool INT_DynamicSwitchDDS_internal(sys_pll_enum inputpll, kal_bool ddson)
{
    register kal_uint32 idx;
    register kal_uint32 reg_val;
    register kal_uint32 imask;

    if(inputpll == SYS_UPLL)
    {
        imask = SaveAndSetIRQMask();
        if( (ddson && !pll_dds_off) || (!ddson && pll_dds_off) )
        {
            /* do nothing */
            RestoreIRQMask(imask);
            return KAL_FALSE;
        }
        RestoreIRQMask(imask);

        imask = LockIRQ();
        /* switch DSP to UPLL/2 */
        *PLL_CON1 |= 0x2000; // enable sw_lpaud mode (force DSP to 26MHz)
        for(idx = 0 ; idx < 5 ; idx++);

        reg_val = *PLL_CON1; // select UPLL/4 as DSP clock
        reg_val &= ~(0x0C00);
        reg_val |= 0x0800;
        *PLL_CON1 = reg_val;
        for(idx = 0 ; idx < 5 ; idx++);

        *PLL_CON1 &= ~(0x2000); // disable sw_lpaud mode (force DSP back to PLL)
        *PLL_MISC_CON &= ~(0x2000); // prepare UPLL/2(312Mhz) to EPLL
        RestoreIRQ(imask);

        imask = LockIRQ();
        // switch EMI to UPLL/2
        custom_DynamicClockSwitch(SSC_EMI_NON_EPLL);

        // switch MCU to UPLL/2
        *PLL_MISC_CON |= 0x0400;
        RestoreIRQ(imask);

        imask = LockIRQ();
        //imask = SaveAndSetIRQMask();
        if(ddson && pll_dds_off) // DDS switch on flow
        {
            //enable DDS
            *TDMA_FHCON4 |= 0x0003;
            *TDMA_FHCON6 |= 0x0003;
            pll_dds_off = KAL_FALSE;
        }
        else if(!ddson && !pll_dds_off) // DDS switch off flow
        {
            //disable DDS
            *TDMA_FHCON4 &= ~(0x0003);
            *TDMA_FHCON6 &= ~(0x0003);
            pll_dds_off = KAL_TRUE;
        }
        else
        {
            /* do nothing */
        }
        //RestoreIRQMask(imask);

        // wait for 100 us
        for(idx = 0 ; idx < 31250 ; idx++); // in 312Mhz
        RestoreIRQ(imask);

        imask = LockIRQ();
        // switch MCU to MPLL
        *PLL_MISC_CON &= ~(0x0400);
        // switch EMI to EPLL
        custom_DynamicClockSwitch(SSC_EMI_EPLL);
        RestoreIRQ(imask);

        imask = LockIRQ();
        /* switch DSP to MPLL */
        *PLL_CON1 |= 0x2000; // enable sw_lpaud mode (force DSP to 26MHz)
        for(idx = 0 ; idx < 5 ; idx++);

        reg_val = *PLL_CON1; // select MPLL as DSP clock
        reg_val &= ~(0x0C00);
        reg_val |= 0x0400;
        *PLL_CON1 = reg_val;
        for(idx = 0 ; idx < 5 ; idx++);

        *PLL_CON1 &= ~(0x2000); // disable sw_lpaud mode (force DSP back to PLL)
         RestoreIRQ(imask);

         pll_dds_switch_cycles++;

         return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

kal_bool INT_DynamicSwitchDDS(sys_pll_enum inputpll, kal_bool ddson)
{
    if(INT_SW_SecVersion() < SW_SEC_1)
    {
        return INT_SwitchStackToRun(PLL_Stack_Pool_Init, PLL_SWITCH_STACK_SIZE, INT_DynamicSwitchDDS_internal, 2, inputpll, ddson);
    }
    else
    {
        return KAL_TRUE;
    }
}

#else /* !MT6256_S01 */
kal_bool INT_DynamicSwitchDDS(sys_pll_enum inputpll, kal_bool ddson)
{
    return KAL_TRUE;
}

#endif /* MT6256_S01 */

#ifdef __MTK_TARGET__
#pragma arm section code, rwdata, rodata, zidata
#endif /* __MTK_TARGET__ */

#else
kal_bool INT_DynamicSwitchDDS(sys_pll_enum inputpll, kal_bool ddson)
{
    return KAL_TRUE;
}

#endif /* !__UBL__ && !__FUE__ */

#endif /* should NOT be compiled on MODIS */
