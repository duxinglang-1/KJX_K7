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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * afe.c
 *
 * Project:
 * --------
 *   MT6219
 *
 * Description:
 * ------------
 *   Audio Front End
 *
 * Author:
 * -------
 * -------
 *
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *******************************************************************************/
#include "afe_def.h"
extern void GPO_WriteIO(char data,char port);
//#define  AFE_VAC_DCON1  (volatile unsigned short*)(0x8040000CL)  /* AFE Voice Analog Circuit Control Register 1   */
//#define  AFE_VAC_CON0   (volatile unsigned short*)(0x80500104L)  /* AFE Voice Analog-Circuit Control Register 0   */

/*****************************************************************************
* FUNCTION
*  AFE_Initialize
* DESCRIPTION
*   This function is to set the initial value of AFE HW.
*****************************************************************************/
void AFE_Initialize( void )
{
   /// AFE_VAC_CON0::VCALI is chip dependent, will be set in l1audio\afe2.c
   /// immediately after this function is called.
   *AFE_VAC_CON0  = 0x40;
   *AFE_VAC_DCON1 = 0x80;
}

#if defined(__KJX_FUN__)
#if 0//defined(CUSTOMER_NAME_OLDMAN)
extern void kjx_afe_switch(kal_bool on);
#endif   
#endif

//#define __AUDIO_CLASS_AB__
//extern const char gpio_afe_amplifier_pin;
//#include "dcl.h"
/*****************************************************************************
* FUNCTION
*  AFE_SwitchExtAmplifier
* DESCRIPTION
*   This function is to turn on/off external amplifier.
*****************************************************************************/
void AFE_SwitchExtAmplifier( char sw_on )
{
#if 0//defined(__SLC_FUN__)
#if defined(CUSTOMER_NAME_OLDMAN)

#if defined(__AUDIO_CLASS_K__)//K类功放
        volatile unsigned short iDelay;
    
        if (sw_on)
        {
            GPIO_WriteIO( 0, gpio_afe_amplifier_pin);
                 
            for (iDelay =0; iDelay <20; iDelay++){}    //30//pulse time define by device 脉冲时间间隔由硬件决定
             
            GPIO_WriteIO( 1, gpio_afe_amplifier_pin);
             
            for (iDelay =0; iDelay <20; iDelay++){}    //30
     
            GPIO_WriteIO( 0, gpio_afe_amplifier_pin);
         
            for (iDelay =0; iDelay <20; iDelay++){}    //30
         
            GPIO_WriteIO( 1, gpio_afe_amplifier_pin);
           
            for (iDelay =0; iDelay <20; iDelay++){}    //30
     
            GPIO_WriteIO( 0, gpio_afe_amplifier_pin);
         
            for (iDelay =0; iDelay <20; iDelay++){}    //30
         
            GPIO_WriteIO( 1, gpio_afe_amplifier_pin);
         
            for (iDelay =0; iDelay <20; iDelay++){}    //30
         
            GPIO_WriteIO( 0, gpio_afe_amplifier_pin);
    
            for (iDelay =0; iDelay <20; iDelay++){}    //30
    
            GPIO_WriteIO( 1, gpio_afe_amplifier_pin);
        }
        else
        {
            GPIO_WriteIO( 0, gpio_afe_amplifier_pin);
        }


 #elif defined(__AUDIO_CLASS_AB__)//AB类功放
        if (sw_on)
        {
         U_PutUARTBytes(0,"__AUDIO_CLASS_AB__ 001\r\n",strlen("__AUDIO_CLASS_AB__ 001\r\n"));
            GPIO_WriteIO( 1, gpio_afe_amplifier_pin);
		//pmu6260_spk_enable(KAL_TRUE);
        }
        else
        {
         U_PutUARTBytes(0,"__AUDIO_CLASS_AB__ 002\r\n",strlen("__AUDIO_CLASS_AB__ 002\r\n"));
            GPIO_WriteIO( 0, gpio_afe_amplifier_pin);
		//pmu6260_spk_enable(KAL_FALSE);
        }

#else    //__AUDIO_CLASS_K__


#if defined(MT6253T) || defined(MT6253) 
    //For MT6253T
    if( sw_on )
        pmu6253_spk_enable(KAL_TRUE);
    else
        pmu6253_spk_enable(KAL_FALSE);
#elif defined(MT6253E) || defined(MT6253L)
    
    if( sw_on )
        pmu_6253el_spk_enable(KAL_TRUE);
    else
        pmu_6253el_spk_enable(KAL_FALSE);
#elif defined(MT6252H) || defined(MT6252)
   DCL_HANDLE handle;
   PMU_CTRL_SPK_SET_EN val;
   
   handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);


   if( sw_on )
       //pmu_6252_spk_enable(KAL_TRUE);
       
   val.enable=DCL_TRUE;
   else
       //pmu_6252_spk_enable(KAL_FALSE);
       
   val.enable=DCL_FALSE;
   
   DclPMU_Control(handle, SPK_SET_EN, (DCL_CTRL_DATA_T *)&val);
   DclPMU_Close(handle);   
   
#else


    DCL_HANDLE handle;
    PMU_CTRL_SPK_SET_EN val;


    handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);


    if( sw_on )
    {
        val.enable=DCL_TRUE;
    }
    else
    {
        val.enable=DCL_FALSE;
    }
   
    DclPMU_Control(handle, SPK_SET_EN, (DCL_CTRL_DATA_T *)&val);
    DclPMU_Close(handle);   
#endif


#endif    //__AUDIO_CLASS_K__	

return;

#endif
#endif
 
#if 0//defined(__KJX_FUN__)
#if defined(CUSTOMER_NAME_TOUR)
#include "dcl.h"
	//kjx_afe_switch(sw_on);	
    DCL_HANDLE handle;
    PMU_CTRL_SPK_SET_EN val;

 
    handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);


    if( sw_on )
    {
        val.enable=DCL_TRUE;
    }
    else
    {
        val.enable=DCL_FALSE;
    }
   
    DclPMU_Control(handle, SPK_SET_EN, (DCL_CTRL_DATA_T *)&val);
    DclPMU_Close(handle);   

   return;
#endif   
#endif

    if( sw_on )
        GPO_WriteIO( 1, 1 );
    else
        GPO_WriteIO( 0, 1 );
}


