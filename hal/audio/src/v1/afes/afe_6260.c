/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012 
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
 * afe_6260.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   AFE Driver for 6260
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
 *
 *******************************************************************************/


#if defined(MT6260)

#include "afe.h"
#include "dcl.h"
#include "Drvsignals.h"
#include "init.h"

static void UpdateSPKGain();
static void _AFE_Wait_ZCD_Stable(kal_bool audio);
extern kal_bool L1Audio_IsInitiated(void);

#if defined(__KJX_FUN__)
#if 0//defined(CUSTOMER_NAME_OLDMAN)
extern void kjx_afe_switch(kal_bool on);
#endif   
#endif

static void _AFE_Switch_IntAmp(kal_bool on)  // 1: turn on, 0: turn off
{

   if(on){
   	  kal_uint16 retore = *ABBA_VOICE_CON0;
   	  *AFE_AMCU_CON5 |= 0x0002;  
      *ABBA_VOICE_CON3 |= RG_VBUF_PWDB;
      *ABBA_VOICE_CON4 |= RG_V2SPK;
      *ABBA_VOICE_CON0 &= (~RG_VBIRX_ZCD_EN);  
      *ABBA_VOICE_CON0 &= (~0x00F0);
      {                                           
         //avoid compesation fail, set compensate registers several times
         kal_uint16 compensate_temp = 0, count =0;
         *AFE_AMCU_CON2 |= 0x8000;          
         while(count < COMPENSATE_NO)
         {
         	  *AFE_AMCU_CON7 = compensate_temp;
         	  compensate_temp+=50;
         	  count++;
         	  AFE_DELAY(50);
         }
         *AFE_AMCU_CON7 = afe.spk_dc_compensate_value;       
      }
      *SPK_CON0 |= 0x0001;
      *SPK_CON3 |= 0x4000;
      *SPK_CON7 |= 0x04A0; 
      *ABBA_VOICE_CON0 = retore;
      *ABBA_VOICE_CON0 |= (RG_VBIRX_ZCD_EN);
      _AFE_Wait_ZCD_Stable(KAL_FALSE);
#if defined(__KJX_FUN__)
#if 0//defined(CUSTOMER_NAME_OLDMAN)
	slc_afe_switch(on);	
#endif   
#endif
	  
   }
   else{
   	  //un-mute first to make compensation work. 
   	  *ABBA_AUDIO_CON2 &= (~(RG_AMUTER|RG_AMUTEL));
      if(!afe.voice_dl_ena)  //if voice dl enable: close when dl turned off
         *ABBA_VOICE_CON3 &= (~RG_VBUF_PWDB);
      *ABBA_VOICE_CON4 &= (~RG_V2SPK);      
      *SPK_CON0 &= (~0x0001);
      *SPK_CON3 &= (~0x4000);
      *SPK_CON7 &= (~0x04A0); 
      *ABBA_AUDIO_CON2 |= (RG_AMUTER|RG_AMUTEL);
      *AFE_AMCU_CON2 &= ~0x8000;
      *AFE_AMCU_CON7 = 0;
#if defined(__KJX_FUN__)
#if 0//defined(CUSTOMER_NAME_OLDMAN)
	slc_afe_switch(!on);	
#endif   
#endif
   }
   #if __AFE_CLASSK_SUPPORT_INTERNAL__
   if(L1Audio_IsInitiated())
      audio_send_vbat_detect_rate(on);
   #endif
}

static void _AFE_Switch_TurnOff_Amp(kal_int16 v_lowest, kal_int16 a_lowest)
{
   if( !afe.gpio_lock ) 
   {
      if( ( (a_lowest >= 0) && (afe.aud[a_lowest].out_dev & L1SP_BUFFER_EXT) ) ||
          ( (v_lowest >= 0) && (afe.aud[v_lowest].out_dev & L1SP_BUFFER_EXT) ) || 
          ( (v_lowest >= 0) && (afe.aud[v_lowest].out_dev & L1SP_BUFFER_0) && (Spk2In1) ) )
      {
      } 
      else 
      {
         /// Turn off the external amplifier
         if (Ext_op_off_delay == 0) 
         {
            AVolumeRampDown();
            _AFE_Switch_IntAmp(KAL_FALSE);
            AFE_SwitchExtAmplifier( false );
            #if __AFE_CLASSK_SUPPORT_INTERNAL__
            _AFE_Switch_ChargePump(KAL_FALSE, CP_STATE_OFF);
            #endif
            afe.ext_op_on = KAL_FALSE;
            /// Reset the ext_op_delay timer to indicate the completion of current operation
            afe.ext_op_delay = 0;
            AFE_SetRefresh();
         }
         else 
         {
            /// The latest command will replace the un-executed command
            afe.ext_op_delay = -(int16)Ext_op_off_delay;
         }
      }
   }
}

static void _AFE_Switch_TurnOn_Amp(kal_int16 v_lowest, kal_int16 a_lowest)
{

   if( !afe.gpio_lock ) {
      if( ( (a_lowest >= 0) && (afe.aud[a_lowest].out_dev & L1SP_BUFFER_EXT) ) ||
          ( (v_lowest >= 0) && (afe.aud[v_lowest].out_dev & L1SP_BUFFER_EXT) ) ||
          ( (v_lowest >= 0) && (afe.aud[v_lowest].out_dev & L1SP_BUFFER_0) && (Spk2In1) ) )
      {
         /// Turn on the external amplifier                        
         if (Ext_op_on_delay == 0) {
            #if __AFE_CLASSK_SUPPORT_INTERNAL__
            if(Check_CP_available())
               _AFE_Switch_ChargePump(KAL_TRUE, CP_STATE_ON_BOOST);
            else
            	 _AFE_Switch_ChargePump(KAL_TRUE, CP_STATE_ON_BYPASS);   
            #endif
            _AFE_Switch_IntAmp(KAL_TRUE);
            AFE_SwitchExtAmplifier( true );
            afe.ext_op_on = KAL_TRUE;
            /// Reset the ext_op_delay timer to indicate the completion of current operation
            afe.ext_op_delay = 0;
         } else {
            /// The latest command will replace the un-executed command
            afe.ext_op_delay = (int16)Ext_op_on_delay;
         }
      }
   }
}

void _AfeRegisterBackupByChip(void)
{
}

void _AfeRegisterStoreByChip(void)
{
}

//=============================================================================================
//                  Die To Die Control Sequence
//=============================================================================================
void _AFE_MDIE_CtrlSeq(kal_bool turnon, kal_bool audio, AFE_DIE2DIE_T downlink)
{
   kal_uint32 savedMask;
   kal_uint16 dummy;
   savedMask = SaveAndSetIRQMask();
   
   if( turnon )
   {
      *D2D_D_AUD_CON1   |= f26m_aud_en;       //D die D2D 26MHz clock enable           
      *D2D_D_AUD_CON0   = 0x0022;             //D die D2D initial configuration        
      *D2D_D_AUD_CON1   &= (~d_audio_ies);    //D die IES register disable             
      *D2D_A_AUD_CON0   &= (~a_audio_ies);    //A die IES register disable             

      if(downlink == AFE_DIE2DIE_DOWNLINK)
      {                              
         *D2D_A_AUD_CON0   |= a_aud_mode;     //A die D2D a_audio_mode selection : audio  
         dummy             = *D2D_A_AUD_CON0; 
         *D2D_D_AUD_CON0   |= d_aud_mode;     //D die D2D d_audio_mode selection : audio
         *D2D_D_AUD_CON1   |= d_audio_ies;    //D die IES register enable
         *D2D_A_AUD_CON0   |= a_audio_ies;    //A die IES register enable
      }
      else 
      {   
         *D2D_D_AUD_CON0   &= (~d_aud_mode);  //D die D2D d_audio_mode selection : voice 
         dummy             = *D2D_D_AUD_CON0;    
         *D2D_A_AUD_CON0   &= (~a_aud_mode);  //A die D2D a_audio_mode selection : voice
         *D2D_A_AUD_CON0   |= a_audio_ies;    //A die IES register enable
         *D2D_D_AUD_CON1   |= d_audio_ies;    //D die IES register enable         
      }
      
      *D2D_A_AUD_CON0   |= a_aud_en;          //A die D2D a_audio_enable setting
      dummy             = *D2D_A_AUD_CON0;    
      *D2D_D_AUD_CON0   |= d_aud_en;          //D die D2D d_audio_enable setting
      *D2D_D_AUD_CON0   |= audio_fifo_en;     //D die D2D enable AFIFO on      
      *MD2GSYS_CG_CLR2  =  PDN_CON2_VAFE;     //equal PDN_CON2_AAFE  
      if(audio)
         *AFE_AMCU_CON0 |= 0x0001;
      else
         *AFE_VMCU_CON0 |= 0x0001;
 
      if(downlink == AFE_DIE2DIE_DOWNLINK)
      	 afe.die2die_status = AFE_DIE2DIE_DOWNLINK;
      else
      	 afe.die2die_status = AFE_DIE2DIE_UPLINK;     
   }
   else
   {
      *D2D_D_AUD_CON0  &= (~audio_fifo_en);   //D die D2D disable AFIFO on/off( aud_fifo_en)
      while(1) //polling state 1
      {
      	if((*D2D_D_AUD_CON0 & audio_fifo_rst_st)) 
      		break;
      }      
      if(audio)
         *AFE_AMCU_CON0  = 0x0000;
      else
         *AFE_VMCU_CON0  = 0x0000;

      *MD2GSYS_CG_SET2   = PDN_CON2_VAFE;     //equal PDN_CON2_AAFE     
      *D2D_D_AUD_CON0    &= (~d_aud_en);      //D die D2D d_audio_enable disable   
      *D2D_A_AUD_CON0    &= (~a_aud_en);      //A die D2D a_audio_enable disable
      AFE_DELAY(1);                           //wait for 4T(26M)
      *D2D_D_AUD_CON1    &= (~f26m_aud_en);   //D die D2D 26MHz clock enable         
      afe.die2die_status = AFE_DIE2DIE_NONE;
   }
   RestoreIRQMask(savedMask);
}

void AFE_SetSamplingRate( uint32 freq )
{
   kal_uint16 SampleRate;
#if defined(AUDIO_COMPENSATION_ENABLE) 
   *AFE_AMCU_CON1 &= (~0x0C00);
   *AFE_AMCU_CON1 |= 0x0800;  // turn on HW EQ
#else
   *AFE_AMCU_CON1 |= 0x0C00;  // turn off HW FIR
#endif

#if defined(EXT_DAC_SUPPORT) 
   switch (freq) {
      case 0x00: 
      case 0x20:
      case 0x40:     
         afe.ext_dac_freq = 32000;     
         break;
      case 0x11:
      case 0x21:  
      case 0x41:
         afe.ext_dac_freq = 44100;
         break;
      case 0x12: 
      case 0x22:  
      case 0x42: 
         afe.ext_dac_freq = 48000;
         break;
   }
#endif
   switch (freq) {
      case ASP_FS_8K:  SampleRate = 0;  break;
      case ASP_FS_11K: SampleRate = 1;  break;
      case ASP_FS_12K: SampleRate = 2;  break;
      case ASP_FS_16K: SampleRate = 4;  break;
      case ASP_FS_22K: SampleRate = 5;  break;
      case ASP_FS_24K: SampleRate = 6;  break;
      case ASP_FS_32K: SampleRate = 8;  break;
      case ASP_FS_44K: SampleRate = 9;  break;
      case ASP_FS_48K: SampleRate = 10; break;
      default        : SampleRate = 0;  break;
   }
   *AFE_AMCU_CON1 = ((*AFE_AMCU_CON1) & (~0x03C0)) | (SampleRate<<6);
   afe.audio_fs = freq;
}

/// Caller: Task
void AFE_TurnOnLoopback( void )
{
   *AFE_VLB_CON |= 0x0022;     // for digital loopback
   *AFE_VLB_CON |= 0x0008;
   *AFE_VAGC_CON0 &= (~0x1);

   afe.loopback = KAL_TRUE;
   AFE_SetRefresh();
   kal_brief_trace(TRACE_STATE, AFE_SWITCH_LOOPBACK, '+');
}

void AFE_TurnOffLoopback( void )
{
   *AFE_VLB_CON &= (~0x62);    // for digital loopback
   *AFE_VLB_CON &= (~0x0008);
   afe.loopback = KAL_FALSE;

   AFE_SetRefresh();
   kal_brief_trace(TRACE_STATE, AFE_SWITCH_LOOPBACK, '-');
}

//=============================================================================================
//                  Sidetone Gain
//=============================================================================================
static const kal_uint16 SideToneTable[] = {
   32767, 26027, 20674, 16422, 13044, 10361, 8230, 6537,       /* 2 dB per step */
    5193,  4125,  3276,  2602,  2066,  1641, 1304, 1035,
     822,   653,   519,   412,   327,   260,  206,  164
};

void UpdateSidetone( kal_int8 vol )
{
   kal_int8 J;
   kal_uint32 R;
   kal_uint16 sidetone_vol;

   if(afe.sidetone_disable || afe.sidetone_volume == 0) {
      *DP_SIDETONE_VOL = 0;
      return;
   }
   sidetone_vol = afe.sidetone_volume;
   
   {
      kal_int16 i;
      kal_uint8  agc_ul_gain, pga_ul_gain = 0;
   
      pga_ul_gain = MIN_PGA_GAIN;
      i = afe.mic_volume - SW_AGC_GAIN_DEFAULT;
      i = i - pga_ul_gain;
      if(i>3)
      {
         for(; i > 3; i-=6)
         {
            pga_ul_gain += 6;
         }
      }
      if(pga_ul_gain > MAX_PGA_GAIN) 
         pga_ul_gain = MAX_PGA_GAIN;
      if(afe.mic_volume < pga_ul_gain)
         agc_ul_gain = 0;
      else
         agc_ul_gain = afe.mic_volume - pga_ul_gain;
      
      i = agc_ul_gain;
      i = i << 3;
      sidetone_vol += i;

      if(sidetone_vol > 255 )
         sidetone_vol = 255;
   }
   
   R = (kal_uint32)(sidetone_vol & 0xF);
   vol = vol + 8 - (kal_int8)(sidetone_vol >> 4);

   if( vol < 0 )
      vol = 0;
   
   if(vol > 23) vol = 23;
   J = ( vol == 0 )? 0: vol-1;
   *DP_SIDETONE_VOL = (kal_uint16)(((kal_uint32)SideToneTable[vol]*(16-R) + (kal_uint32)SideToneTable[J]*R) >> 4);
}


//=============================================================================================
//                  Audio/8K Clock Related
//=============================================================================================

void AFE_TurnOnAudioClock( kal_uint8 clock )
{
   kal_uint16 SampleRate;
   kal_uint32 u4SavedMask = 0;

   if(!kal_if_lisr())
      u4SavedMask = SaveAndSetIRQMask();
   
   if( (afe.audio_clk_ena) && (afe.aClk_off_request) )
      afe.aClk_off_request = KAL_FALSE;
   if(!afe.audio_clk_ena )
   {
      afe.aClk_off_request = KAL_FALSE;
      switch (clock) {
         case ASP_FS_8K:  SampleRate = 0;  break;
         case ASP_FS_11K: SampleRate = 1;  break;
         case ASP_FS_12K: SampleRate = 2;  break;
         case ASP_FS_16K: SampleRate = 4;  break;
         case ASP_FS_22K: SampleRate = 5;  break;
         case ASP_FS_24K: SampleRate = 6;  break;
         case ASP_FS_32K: SampleRate = 8;  break;
         case ASP_FS_44K: SampleRate = 9;  break;
         case ASP_FS_48K: SampleRate = 10; break;
         default        : SampleRate = 0;  break;
      }
      //SampleRate = (clock&3) + 8; //8: 32kHz, 9: 44kHz, 10: 48kHz
      *AFE_AMCU_CON1 = ((*AFE_AMCU_CON1) & (~0x03C0)) | (SampleRate<<6);
      afe.audio_fs = (kal_uint32)clock;
      if(AFE_IsKaraok()){
         *AFE_VMCU_CON3 |= 0x0020;
         *ABBA_WR_PATH4   |= 0x8000;
         _AFE_MDIE_CtrlSeq(KAL_TRUE, KAL_TRUE, AFE_DIE2DIE_UPLINK);
      }else{
         _AFE_MDIE_CtrlSeq(KAL_TRUE, KAL_TRUE, AFE_DIE2DIE_DOWNLINK);
      }
      afe.audio_clk_ena = KAL_TRUE;
   }
   if(!kal_if_lisr())
      RestoreIRQMask(u4SavedMask);
}

void AFE_TurnOffAudioClock( void )
{
   kal_uint32 u4SavedMask = 0;
   if (!kal_if_lisr())
      u4SavedMask = SaveAndSetIRQMask();
   afe.aClk_off_request = KAL_TRUE;
   if (!kal_if_lisr())
      RestoreIRQMask(u4SavedMask);
   AFE_SetRefresh();
}

// The coefficient can be written into register only when the power is on
void AFE_TurnOnAudioPower( void )
{
   *MD2GSYS_CG_CLR2 = PDN_CON2_AAFE;
}

void AFE_TurnOffAudioPower( void )
{
   if(!afe.voice_clk_ena)
      *MD2GSYS_CG_SET2 = PDN_CON2_AAFE;
}

void AFE_TurnOn8K( void )
{
   kal_uint32 u4SavedMask = 0;
#ifdef L1D_TEST
   extern  int  PollLoopbackMode(void);
   if( PollLoopbackMode() !=1 )
#endif
   {
      if (!kal_if_lisr())
         u4SavedMask = SaveAndSetIRQMask();
      if( (afe.voice_clk_ena) && (afe.v8k_off_request) )
         afe.v8k_off_request = KAL_FALSE;
      if(!afe.voice_clk_ena )
      {
         afe.v8k_off_request = KAL_FALSE;
         if( ((*AFE_AMCU_CON0&0x0001)==0) || AFE_IsKaraok() )
         {
            *AFE_VMCU_CON3 |= 0x0020;
            *ABBA_WR_PATH4   |= 0x8000;
         }
         *AFE_VMCU_CON6 |= 0x0001;
         if(afe.die2die_status == AFE_DIE2DIE_NONE)
         {
            _AFE_MDIE_CtrlSeq(KAL_TRUE, KAL_FALSE, AFE_DIE2DIE_UPLINK);
         }
         else
         {
            *MD2GSYS_CG_CLR2 =  PDN_CON2_VAFE;
            *AFE_VMCU_CON0   = 0x0001;
         }
         afe.voice_clk_ena = KAL_TRUE;
      }

      *DP_8K_LIMITER_CTRL &= (~0x1);  //Long ago, when HQA, limiter must be closed,But now no this limitation; After MT6256_S01, this setting means initial bit which causes DSP'init, and DSP turn it into 1
   }
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   //turn on filter
   *DP_8K_LIMITER_CTRL |= 0x200; 
   *DP_8K_LIMITER_CTRL &= ~0x800; 
#endif //__VIBRATION_SPEAKER_SUPPORT__
   if (!kal_if_lisr())
      RestoreIRQMask(u4SavedMask);
}

void AFE_TurnOff8K( void )
{
   kal_uint32 u4SavedMask = 0;
   if (!kal_if_lisr())
      u4SavedMask = SaveAndSetIRQMask();
   afe.v8k_off_request = KAL_TRUE;
   if (!kal_if_lisr())
      RestoreIRQMask(u4SavedMask);
   AFE_SetRefresh();
}

void AFE_TurnOff8K_Direct( void )
{
   kal_uint32 u4SavedMask = 0;
   if (!kal_if_lisr())
      u4SavedMask = SaveAndSetIRQMask();
   if(afe.voice_clk_ena)
   {
      if(afe.audio_clk_ena)
      {
         *AFE_VMCU_CON3  &= (~0x0020);
         *AFE_VMCU_CON6  &= (~0x0001);
         *AFE_VMCU_CON0  &= (~0x0001);
      }
      else
      {
         _AFE_MDIE_CtrlSeq(KAL_FALSE, KAL_FALSE,afe.die2die_status);
      }
      afe.voice_clk_ena = KAL_FALSE;
   }
   if (!kal_if_lisr())
      RestoreIRQMask(u4SavedMask);
   AFE_SetRefresh();
}

//=============================================================================================
//                  VAPDN Related
//=============================================================================================
static void UpdateVAPDN(kal_uint8 device)
{
   if( afe.mic_mute||afe.mic_flag==0 ||afe.mute ) {
      if(afe.accessory_flag)
      {
         *ABBA_VOICE_CON3 &= (~(RG_VPWDB_PGA | RG_VPWDB_ADC));
         *ABBA_VOICE_CON1 |= (RG_VCFG_1); //avoid cross-talk
         *ABBA_VOICE_CON3 |= (RG_VPWDB_MBIAS|RG_VREF24_EN|RG_VCM14_EN);
      }
      else 
      {
         *ABBA_VOICE_CON3 &= (~(RG_VPWDB_MBIAS | RG_VPWDB_PGA | RG_VPWDB_ADC));
         *ABBA_VOICE_CON1 |= (RG_VCFG_1);
         if( !(afe.audio_dl_ena || afe.voice_dl_ena) )
            *ABBA_VOICE_CON3 &= (~(RG_VREF24_EN|RG_VCM14_EN));
      }
      afe.voice_ul_ena = KAL_FALSE;
      return;
   }
   *ABBA_VOICE_CON3 |= (RG_VPWDB_MBIAS | RG_VPWDB_PGA | RG_VPWDB_ADC | RG_VREF24_EN | RG_VCM14_EN);
   *ABBA_VOICE_CON1 &= ~(RG_VCFG_1);
   afe.voice_ul_ena = KAL_TRUE;
}



static void _apply_mic_setting(kal_int16 a_lowest, kal_int16 v_lowest)
{

   if( afe.mic_src==L1SP_LNA_1 ) {/* Headset Mode */
      *ABBA_VOICE_CON1 = (*ABBA_VOICE_CON1 & MIC_SETTING_MASK) | MIC_SETTING_HEADSET; /* Switch input source to headset microphone */
   }
   else {                         /* Normal Mode */
      *ABBA_VOICE_CON1 = (*ABBA_VOICE_CON1 & MIC_SETTING_MASK) | MIC_SETTING_NORMAL;  /* Switch input source to normal microphone */
   }
}


//=============================================================================================
//                 Update VGain / AGain
//=============================================================================================
static void _AFE_Wait_ZCD_Stable(kal_bool audio) // 1: audio, 0: voice
{
   kal_uint8 counter = 0;
   while(1){
      kal_uint16 reg_temp = 0;
      if(audio && afe.audio_dl_ena)
         reg_temp = (*ABBA_AUDIO_CON6&0xC000);
      else if(!audio && afe.voice_dl_ena)
         reg_temp = (*ABBA_VOICE_CON5&0x8000);
      if((!reg_temp) || (counter == 1) )
         break;
      counter++;
      AFE_DELAY(1000);
   }
}
static void UpdateAGCGain(kal_uint16 vol)
{
   {
      kal_uint8  agc_ul_gain, pga_ul_gain = 0;
      kal_int16   i;
      //UL PGA and AGC digital gain update
      if( afe.mic_src == L1SP_LNA_DIGITAL ){
         if( afe.mic_volume > TRANSPARENT_AGC_GAIN_OFFSET)
            agc_ul_gain = afe.mic_volume - TRANSPARENT_AGC_GAIN_OFFSET;
         else
            agc_ul_gain = 0;
      } else{
         pga_ul_gain = MIN_PGA_GAIN;
         i = afe.mic_volume - SW_AGC_GAIN_DEFAULT;
         i = i - pga_ul_gain;
         if(i>3){
            for(; i > 3; i-=6){
               pga_ul_gain += 6;
            }
         }
         if(pga_ul_gain > MAX_PGA_GAIN) 
            pga_ul_gain = MAX_PGA_GAIN;
         
         if(afe.mic_volume < pga_ul_gain)
            agc_ul_gain = 0;
         else
            agc_ul_gain = afe.mic_volume - pga_ul_gain;
      }
      *DSP_AGC_GAIN = agc_ul_gain;

      vol = pga_ul_gain;
      afe_prompt_trace(MOD_L1SP, "UpdateAGCGain (PGA=%d, AGC=%d) \r\n", agc_ul_gain, pga_ul_gain);
   }
   
   //6260: *ABBA_VOICE_CON0[10:8]: -6db~+24db, 6db per step 
   vol = (vol-8)/6; //0: -6db, 1: 0db, ...
   if(vol>=5)
      vol = 5;
   *ABBA_VOICE_CON0 = ((*ABBA_VOICE_CON0&(~0x0700)) | (vol<<8));
   *AFE_VAGC_CON0 = 0x0000;
   afe.agc_reset_flag = KAL_FALSE;
}

static void UpdateSPKGain()
{
   kal_int16 I, v_lowest;
   kal_uint16 val, gainflag;
   
   v_lowest = -1;

   for( I = L1SP_MAX_AUDIO; I >= 0; I-- ) {
      if( afe.sp_flag & (1<<I) ) {
         val = (kal_uint16)afe.aud[I].out_dev;
         if( val & (L1SP_BUFFER_0|L1SP_BUFFER_1) )
            v_lowest = I;
      }
   }
   gainflag = 0;
   if( v_lowest >= 0)
   {
      if( (afe.aud[v_lowest].out_dev & L1SP_BUFFER_0) && (Spk2In1) ) //RCV=SPK 
         gainflag = 1;
   }
   if (gainflag)
      *SPK_CON0 = ( (*SPK_CON0&0xFFCF)|(0x0<<4) );         // -6dB
   else
      *SPK_CON0 = ( (*SPK_CON0&0xFFCF)|(SpkAmpGain<<4) );  // 12dB
}

static void UpdatePGAGain( kal_uint8 aud_func )
{
   kal_uint16 volume    = afe.aud[aud_func].volume;
   kal_bool HS_gain     = KAL_FALSE;  // FALSE: HP Gain, TRUE: HS Gain
   kal_bool HP_gain_adj = KAL_FALSE;
   kal_uint16 amp_gain;
   
   UpdateVAPDN(0);

   if((afe.aud[aud_func].out_dev & L1SP_BUFFER_EXT) )
   {
      if((afe.aud[aud_func].out_dev & L1SP_BUFFER_ST) )
         HP_gain_adj = KAL_TRUE;	

   #if !HP_EN_UNDERSPK
      if((afe.aud[aud_func].out_dev & L1SP_STEREO2MONO) )
         HP_gain_adj = KAL_FALSE;
   #endif
   }
   
   if( (afe.aud[aud_func].out_dev & L1SP_BUFFER_EXT) || (afe.voice_dl_ena) )
      HS_gain = KAL_TRUE;

   if(HS_gain)
   {
      kal_uint16 again_lowerbound;
      if(volume > VGAIN_UPBOUND_SETTING) // 240 upper bound
         volume = VGAIN_UPBOUND_SETTING;

      if(HP_gain_adj)
         again_lowerbound = VGAIN_DUALSPEAKER_LOWBOUND_SETTING;
      else
         again_lowerbound = VGAIN_LOWBOUND_SETTING;
      if(volume < again_lowerbound) // 128 or 0 lower bound
         volume = again_lowerbound;
      amp_gain = (volume >> 4);
   #ifdef __VIBRATION_SPEAKER_SUPPORT__
      if( (afe.aud[aud_func].out_dev & L1SP_BUFFER_EXT) && (aud_func == L1SP_AUDIO) && afe.vibrate ){
         amp_gain = afe.vib_ampgain;
         VIBR_Vibration_UpdateGain(amp_gain, afe.class_d_gain);
      }
   #endif
      
      *ABBA_VOICE_CON0 = (*ABBA_VOICE_CON0 & 0xFF0F) | (kal_uint16)(amp_gain<<4);
      *ABBA_VOICE_CON0 |= (RG_VBIRX_ZCD_EN);
      _AFE_Wait_ZCD_Stable(KAL_FALSE); 
      if(HP_gain_adj)
      {
         amp_gain = (((amp_gain*2-19)+3)>>1);
         *ABBA_AUDIO_CON2 = (*ABBA_AUDIO_CON2&0xFF88) | (kal_uint16)(amp_gain) | (kal_uint16)(amp_gain<<4);
         *ABBA_AUDIO_CON6 |= (RG_ABIRX_ZCD_EN);
         _AFE_Wait_ZCD_Stable(KAL_TRUE);
         
      }
   }
   else
   {
      amp_gain = AFE_AGainRangeConvert(volume >> 4);
      if(volume > AGAIN_UPBOUND_SETTING) // 160 upper bound
         volume = AGAIN_UPBOUND_SETTING;
      if(volume < AGAIN_LOWBOUND_SETTING) // 104 lower bound
         volume = AGAIN_LOWBOUND_SETTING;
      amp_gain = (volume-AGAIN_LOWBOUND_SETTING) >> 3;
      *ABBA_AUDIO_CON2 = (*ABBA_AUDIO_CON2&0xFF88) | (kal_uint16)(amp_gain) | (kal_uint16)(amp_gain<<4);
      *ABBA_AUDIO_CON6 |= (RG_ABIRX_ZCD_EN);
      _AFE_Wait_ZCD_Stable(KAL_TRUE);
   }
#if __AFE_CLASSK_SUPPORT_INTERNAL__
   afe.spk_vol = volume;
#endif   
   UpdateSPKGain();

   if( afe.mic_flag && !afe.mic_mute && !afe.mute) {
      /* Normal recording */
      UpdateAGCGain((kal_uint16)afe.mic_volume);
   } 

   if( (aud_func == L1SP_SPEECH) )
      UpdateSidetone( (kal_int8)(volume >> 4) );
   else
      *DP_SIDETONE_VOL = 0;
}

//=============================================================================================
//                  Output Volume Releated Functions
//=============================================================================================
static void AFE_CalculateVolume(kal_uint8 aud_func)
{
   if( (afe.aud[aud_func].out_dev & (L1SP_BUFFER_0|L1SP_BUFFER_1|L1SP_BUFFER_ST|L1SP_BUFFER_EXT) ) )
   {
      kal_int16 again_lowerbound = VGAIN_LOWBOUND_SETTING;
      kal_int8 digital_gain_index = afe.aud[aud_func].digital_gain_index;
      kal_uint16 volume           = afe.aud[aud_func].volume;
      
      
      if((afe.aud[aud_func].out_dev & (L1SP_BUFFER_EXT) ))
      {
         if((afe.aud[aud_func].out_dev & (L1SP_BUFFER_ST) ))
            again_lowerbound = VGAIN_DUALSPEAKER_LOWBOUND_SETTING;
      #if !HP_EN_UNDERSPK
         if((afe.aud[aud_func].out_dev & L1SP_STEREO2MONO) )
            again_lowerbound = VGAIN_LOWBOUND_SETTING;
      #endif
      }
      else
      {
         if((afe.aud[aud_func].out_dev & (L1SP_BUFFER_0|L1SP_BUFFER_1) ))
            again_lowerbound = VGAIN_LOWBOUND_SETTING;
         else
            again_lowerbound = AGAIN_LOWBOUND_SETTING;
      }

      if(volume<again_lowerbound) //lower bound is 104
      { 
         kal_int16 tmp_gain_index;
         tmp_gain_index = (kal_int16)digital_gain_index;
         tmp_gain_index -= (((again_lowerbound-volume)>>2)<<1);
   
         if(tmp_gain_index>-128)
            digital_gain_index = (kal_int8)tmp_gain_index;
         else
            digital_gain_index = -128;
   
         afe.aud[aud_func].volume = volume;
         afe.aud[aud_func].digital_gain_index = digital_gain_index;
         afe.aud[aud_func].digital_gain = _converted_digital_gain(digital_gain_index);
       }
   }
}
void AFE_SetOutputVolume( kal_uint8 aud_func, kal_uint8 volume1, kal_int8 digital_gain_index )
{  
   kal_uint8 digital_gain_index1 = digital_gain_index;
   kal_uint8 volume = volume1;

   if (AFE_GetNVRAMDigitalGainSupport())
   {
      digital_gain_index1 = volume1 & 0x0F;
      afe.aud[aud_func].volume = volume;
      afe.aud[aud_func].digital_gain_index = digital_gain_index1;
      afe.aud[aud_func].digital_gain = digital_gain_table[digital_gain_index1];
      afe_prompt_trace(MOD_L1SP, "vol, digital_index, digital_gain = (0x%x, 0x%x, 0x%x) \r\n", volume, digital_gain_index1, afe.aud[aud_func].digital_gain);
   }
   else
   {
      afe.aud[aud_func].volume = volume;
      afe.aud[aud_func].digital_gain_index = digital_gain_index1;
      afe.aud[aud_func].digital_gain = _converted_digital_gain(digital_gain_index1);
   }
   
   AFE_CalculateVolume(aud_func);
   
#if defined(EXT_DAC_SUPPORT) 
   // Note : extrenal DAC is used as earphone or TV-out only 
   // case 1 : play amr with melody volume (7-level case)  
   if(aud_func == L1SP_VOICE && (afe.aud[L1SP_VOICE].out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1)))
   {
      kal_uint32 i, type;
      if(!(afe.aud[L1SP_VOICE].out_dev & L1SP_BUFFER_EXT) && (volume1 != 0)) // for play both case : apply AFE gain is OK 
      {
      #if defined(TV_OUT_SUPPORT)   
         if(audio_tv_cable_in)
            type = AUD_VOLUME_TVO;
         else 
      #endif    
            type = AUD_VOLUME_MEDIA;    
         for(i = 0 ; i < AUD_MAX_VOLUME_LEVEL ; i ++)
         {
            // find the closest level
            if(aud_get_volume_gain(VOL_HEADSET, type, i) > volume1) 
               break;
         }
         if(i > 0) i--;
         afe.aud[aud_func].volume = aud_get_volume_gain(VOL_HEADSET, AUD_VOLUME_SPH, i); // apply speech volume       
      }    
   }
   
   // case 2 : play Audio both on earphone and LoudSpk 
   if(aud_func == L1SP_AUDIO && (afe.aud[L1SP_AUDIO].out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1)))
   {
      if((afe.aud[L1SP_AUDIO].out_dev & L1SP_BUFFER_EXT) && (volume1 != 0)) // play both 
      {
         kal_uint32 i, type;
         for(i = 0 ; i < AUD_MAX_VOLUME_LEVEL ; i ++)
         {              
            //  find the closest level 
            if(aud_get_volume_gain(VOL_NORMAL, AUD_VOLUME_MEDIA, i) > volume1)
               break;            
         }          
         if(i > 0) i--;
      #if defined(TV_OUT_SUPPORT)
         if(audio_tv_cable_in)
            type = AUD_VOLUME_TVO;
         else 
      #endif    
            type = AUD_VOLUME_MEDIA;    
         afe.ext_dac_aud_vol = aud_get_volume_gain(VOL_HEADSET, type, i);
      }
      else 
         afe.ext_dac_aud_vol = volume1;  
   }
   
   if(afe.ext_dac_i2s_on)
   { 
      if(((SND_SRC_MAP>>aud_func*2)&3) == SRC_AUDIO_DAC) 
      {            
         EXT_DAC_SetVolume(afe.aud[aud_func].out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1), afe.ext_dac_aud_vol);  
      }
   }
#endif
   
   AFE_SetRefresh();
   if(kal_if_hisr())
      kal_dev_trace(TRACE_STATE, AFE_SET_OUTPUT_VOLUME, aud_func, volume1, digital_gain_index);
   else
      kal_brief_trace(TRACE_STATE, AFE_SET_OUTPUT_VOLUME, aud_func, volume1, digital_gain_index);
}

/*****************************************************************************
* FUNCTION
*  AFE_SetLevelVolume
* DESCRIPTION
*   This function is to set the proper analog gain and digital gain 
*   based on a MaxAnalogGain and the desired (step * 0.5* level)dB attenuation. 
* 
* PARAMETERS
*  aud_func - the audio function
*  MaxAnalogGain - the maximum volume without any attenuation 
*  step - attenuation step quantity , 0.5dB unit   
*  level - the multiplier of attenuation step; 
*          so the total attenuation is (step * 0.5* level)dB  
*
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void AFE_SetLevelVolume(kal_uint8 aud_func, kal_uint8 MaxAnalogGain, kal_uint8 step, kal_uint8 level)
{
   kal_uint8 vol_step, vol_step_unit;
   kal_uint8 a_gain, a_atten, d_atten;
   kal_trace(TRACE_STATE, AFE_SET_LEVEL_VOLUME, aud_func, MaxAnalogGain, step, level);
#if defined(EXT_DAC_SUPPORT)
   {
      kal_uint8 out_dev;
      // Note : extrenal DAC is used as earphone or TV-out only 
      // case 1 : play amr with melody volume (7-level case)  
      if(aud_func == L1SP_VOICE && (out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1)))
      {
         if(!(out_dev & L1SP_BUFFER_EXT)) // for play both case : apply AFE gain is OK 
         {
            // use AFE gain 
            aud_get_melody_volume_setting(VOL_NORMAL, &MaxAnalogGain, &step);
         }
      }
   
      // case 2 : play Audio both on earphone and LoudSpk 
      if(aud_func == L1SP_AUDIO && (out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1)))
      {
         uint8 ext_dac_max_vol, ext_dac_step;
         if(afe.aud[L1SP_AUDIO].out_dev & L1SP_BUFFER_EXT) // play both 
         {
         #if defined(TV_OUT_SUPPORT)
            if(audio_tv_cable_in)
               aud_get_melody_volume_setting(VOL_TV_OUT, &ext_dac_max_vol, &ext_dac_step);
            else 
         #endif    
               aud_get_melody_volume_setting(VOL_HEADSET,&ext_dac_max_vol, &ext_dac_step);
         }
         else 
         {
            ext_dac_max_vol = MaxAnalogGain;  
            ext_dac_step = step;
         }
         a_gain = ext_dac_max_vol / L1SP_EXT_DAC_STEP;

         a_atten = (ext_dac_step * level) / L1SP_EXT_DAC_STEP_UNIT; 
         d_atten = (ext_dac_step * level) % L1SP_EXT_DAC_STEP_UNIT; 
         ASSERT(d_atten == 0); // For current EXT_DAC interface, this must be 0.
      
         if(a_gain >= a_atten)  
            a_gain -= a_atten;
         else 
         {
            a_atten -= a_gain;
            a_gain = 0;
            d_atten += a_atten * L1SP_EXT_DAC_STEP_UNIT;
            if(d_atten > 128)
               d_atten = 128;
         }
         afe.ext_dac_aud_vol = a_gain * L1SP_EXT_DAC_STEP;  

         if(afe.ext_dac_i2s_on)                        
            EXT_DAC_SetVolume(out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1), afe.ext_dac_aud_vol);
      }
   }
#endif 
   vol_step = 4;   
   vol_step_unit = 2; // 1dB = 2 * 0.5dB

   a_gain = MaxAnalogGain / vol_step;

   a_atten = (step * level) / vol_step_unit; 
   d_atten = (step * level) % vol_step_unit; 

   if(a_gain >= a_atten)  
      a_gain -= a_atten;
   else 
   {
      a_atten -= a_gain;
      a_gain = 0;
      d_atten += a_atten * vol_step_unit;
      if(d_atten > 128)
         d_atten = 128;
   }

   if(a_gain == 0)
      afe.aud[aud_func].volume = a_gain * vol_step + 1;   // plus 1 to avoid volume == 0 (this will turn off speaker)
   else
      afe.aud[aud_func].volume = a_gain * vol_step;
   afe.aud[aud_func].digital_gain_index = 0 - d_atten; 
   afe.aud[aud_func].digital_gain = _converted_digital_gain( 0-d_atten);       
   
   AFE_CalculateVolume(aud_func);
   AFE_SetRefresh();
}

void _AfeHardwareMuteCtrl(void)
{
   kal_bool fgMute;

#if __AFE_MD2G_PWDN_LOCK__
   _AFE_SetAudioFlag();
   _AFE_MD2GLockNum_Update(KAL_TRUE);
#endif

   fgMute = (kal_bool)(afe.afe_hw_mute || afe.afe_event_handler_hw_mute || afe.afe_audio_clk_hw_mute);
   
   if(fgMute) 
   {   
      *AFE_AMCU_CON1 |= 0x3C;
   }
   else
   {
      *AFE_AMCU_CON1 &= ~0x0C;
   }
   
#if __AFE_MD2G_PWDN_LOCK__
   _AFE_ClearAudioFlag();
   _AFE_MD2GLockNum_Update(KAL_FALSE);
#endif
}

void AFE_SetHardwareMute(bool mute)
{
#if HW_MUTE_SUPPORT_PLATFORM
   if(mute) 
   {
   	  if(afe.afe_hw_mute)
   	  {
   	  	//avoid re-mute again
   	  	return;
   	  }
   #if defined(EXT_DAC_SUPPORT)
      afe.ext_dac_mute = true;
      AFE_SetRefresh();
   #endif
      afe.afe_hw_mute = mute; 
      _AfeHardwareMuteCtrl();
      
      if (afe.hw_mute_sleep)
      {
         kal_uint8 mute_sleepcnt;
         switch(afe.audio_fs)
         {
            case ASP_FS_8K:  mute_sleepcnt = 15;  break;
            case ASP_FS_11K: mute_sleepcnt = 12;  break;
            case ASP_FS_12K: mute_sleepcnt = 11;  break;
            case ASP_FS_16K: mute_sleepcnt =  8;  break;
            case ASP_FS_22K: mute_sleepcnt =  7;  break;
            case ASP_FS_24K: mute_sleepcnt =  6;  break;
            case ASP_FS_32K: mute_sleepcnt =  5;  break;
            case ASP_FS_44K: mute_sleepcnt =  4;  break;
            case ASP_FS_48K: mute_sleepcnt =  4;  break;
            default        : mute_sleepcnt =  4;  break;
         }
         kal_sleep_task(mute_sleepcnt);
      #if __AFE_MD2G_PWDN_LOCK__
        _AFE_SetAudioFlag();
        _AFE_MD2GLockNum_Update(KAL_TRUE);
      #endif
      #if __AFE_MD2G_PWDN_LOCK__
         _AFE_ClearAudioFlag();
         _AFE_MD2GLockNum_Update(KAL_FALSE);
      #endif
      }
   }
   else
   { 
   #if defined(EXT_DAC_SUPPORT)      
      afe.ext_dac_mute = false;
      AFE_SetRefresh(); 
   #endif

      afe.afe_hw_mute = mute; 
      _AfeHardwareMuteCtrl();
   }
#endif //HW_MUTE_SUPPORT_PLATFORM
}

kal_bool AFE_SPKAMP_OCDetect(void) 
{
#if __AFE_OC_DETECTION__
   kal_bool oc_flag = KAL_FALSE;
   uint8 oc_enabled = 0;
   uint8 oc_autoffed =0;
   kal_uint16 aud_temp_id;

//#if __AFE_MD2G_PWDN_LOCK__
//   _AFE_SetAudioFlag();
//   _AFE_MD2GLockNum_Update(KAL_TRUE);
//#endif   
//MT6260 has one HW bug when using CPD, should lock MCU sleep mode to force EPLL on, then DSP has clock
   aud_temp_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( aud_temp_id );

    kal_sleep_task(10);
   //enable OC detection
   if( (*SPK_CON0 & SPK_OC_AUTOFF) == 0x0000 )
      *SPK_CON0 |= SPK_OC_AUTOFF;
   else
      oc_autoffed = 1;
   if( (*SPK_CON7 & SPK_CLASSAB_OC_EN) == 0x0000 )
      *SPK_CON7 |= SPK_CLASSAB_OC_EN;
   else
      oc_enabled = 1;
   kal_sleep_task(20);
   //Check OC flag
   if( (*SPK_CON0&SPK_OC_FLAG) )
      oc_flag = KAL_TRUE;
   if(!oc_enabled)
      *SPK_CON7 &= (~SPK_CLASSAB_OC_EN);
   if(!oc_autoffed)
      *SPK_CON0 &= (~SPK_OC_AUTOFF);


//#if __AFE_MD2G_PWDN_LOCK__
//   _AFE_ClearAudioFlag();
//   _AFE_MD2GLockNum_Update(KAL_FALSE);
//#endif

//MT6260 has one HW bug when using CPD, should lock MCU sleep mode to force EPLL on, then DSP has clock
   L1Audio_ClearFlag( aud_temp_id );
   L1Audio_FreeAudioID( aud_temp_id );

   return oc_flag;
#else
   return KAL_FALSE;
#endif //__AFE_OC_DETECTION__
}

static void AVolumeRampDown() 
{ 
   kal_int16 I;
   kal_int16 i2Gain;
   kal_uint16 OrgValue;

   i2Gain = (kal_int16)(*ABBA_AUDIO_CON2 & (~0xFFF8));         //R gain = L gain ; extract one
   OrgValue = *ABBA_AUDIO_CON2&0xFF88;                         //get original ADUIO_CON2 setting
    
    for (I=i2Gain; I>=0x00; I--)
    {
      _AFE_Wait_ZCD_Stable(KAL_TRUE);
      *ABBA_AUDIO_CON2 = (I) | (I<<4) | (OrgValue & 0xFF88);   //R mod_gain | L mod_gain | original
    }
    *ABBA_AUDIO_CON2 |= (RG_AMUTER|RG_AMUTEL);                 // mute R and L
    
    i2Gain = (kal_int16)((*ABBA_VOICE_CON0 & (~0xFF0F))>>4);
    OrgValue = *ABBA_VOICE_CON0&0xFF0F;

   if(!afe.loopback)
   {
      for (I=i2Gain; I>=0; I--)
      {
         *ABBA_VOICE_CON0 = (I<<4) | (OrgValue & 0xFF0F);
         _AFE_Wait_ZCD_Stable(KAL_FALSE); 
      }
   }
}


//=============================================================================================
//                  Chip Specific AFE Init
//=============================================================================================
void AFE_Chip_Init( void )
{
   int I;
   //Digital part Initialization
   *AFE_AMCU_CON1   = 0x0E00;
   *AFE_AMCU_CON5   = 0x0002;
   *AFE_VMCU_CON3   = 0x0002;
   *AFE_VMCU_CON2   = 0x082C;
   *AFE_AMCU_CON2   = 0x002C;
   *AFE_VAGC_CON0   = 0x0000;
   *AFE_VLB_CON     = 0x0008;
   *ABBA_AUDIO_CON0 = 0x1001;  
   
   //Uplink PGA Gain : 6dB
   *ABBA_VOICE_CON0 = ((*ABBA_VOICE_CON0&0xF80F) | (0x2<<8) );
   
   //Analog part Initialization
   *ABBA_AUDIO_CON3 = 0x0014;
   
   //power-on control sequence
   *ABBA_AUDIO_CON6 = (RG_CHARGEOPTION_DEPOP)|(RG_DEPOP_VCMSEL)|(RG_ABIRX_ZCD_HYS_ENB)|(CUSTOM_RG_DEPOP_CURSEL<<8)|(RG_DEPOP_VCM_EN);
   *ABBA_AUDIO_CON5 = 0x0106;
   *ABBA_AUDIO_CON4 = 0x1400;

   //Speaker Amp setting
   *SPK_CON0 = ( (*SPK_CON0&0xFFCF)|(SpkAmpGain<<4) );
#if !defined(__CLASSK_CP_SUPPORT__)
   //Class AB mode
   *CP_CON2 |= 0x3000;
#endif   
   afe.class_d_gain  = SpkAmpGain;
   *DP_VOL_IN_PCM    = DG_Microphone;
   *DP_VOL_OUT_PCM   = DG_DL_Speech;
   PcmSink_SetGain(DG_DAF);
   PcmSink_InitDigitalGain();
   // For AWB Record
   *DP_AUDIO_16K_TX_VOL = DG_Microphone;
   *DP_AUDIO_16K_RX_VOL = DG_DL_Speech;   // 16K WB DownLink path digital gain
   
   for( I = 1; I < 45; I++ )
      *(AFE_EQCOEF+2*I) = 0; // Set AFE_VAC_CON0::VDSEND (external circuit dependent) and AFE_VMCU_CON1
   
   AFE_Initialize();
   afe.dc_calibrate_writeback = KAL_FALSE;
   afe.bReceiverOut = KAL_FALSE;
   afe.dc_cali_new_callback = KAL_FALSE;
   afe.retrieved_dc_data = 0;
#if __AFE_CURRENT_SENSOR_ENABLE__    
   afe.cali_cf_data = 0;
   afe.vib_cali_done = KAL_FALSE;
#endif    
#if __AFE_HP_DC_CALIBRATION__
   afe.hp_dc_compensate_value_r = 0;
   afe.hp_dc_compensate_value_l = 0;
#endif
   afe.bPowerDown = KAL_TRUE;
   afe.KaraokMode = KAL_FALSE;
   afe.powerOffWait = -1;
}

//=============================================================================================
//                  Wavetable Data Transfer Unit DMA
//=============================================================================================
void AFE_TurnOnWTDMA( void ){}

void AFE_TurnOffWTDMA( void ){}




//=============================================================================================
//                  SWIP Common Functions Related
//=============================================================================================
#if defined(__IPS_SUPPORT__)
void _AfeForceTurnOnAudioClock(void)
{
   _AFE_MDIE_CtrlSeq(KAL_TRUE, KAL_TRUE, AFE_DIE2DIE_DOWNLINK);
}

void _AfeForceTurnOffAudioClock(void)
{
   _AFE_MDIE_CtrlSeq(KAL_FALSE, KAL_TRUE, AFE_DIE2DIE_DOWNLINK);
}
#endif


static void AFE_Switch_VoiceDAC_AudAMP(kal_int16 v_lowest, kal_int16 a_lowest)
{
   if(!afe.audio_dl_ena)
   {      
      *ABBA_AUDIO_CON5 = 0x0106;
#if __AFE_HP_DC_CALIBRATION__
      if(afe.hp_dc_compensate_value_r || afe.hp_dc_compensate_value_l)
      {
        *AFE_AMCU_CON5 |= 0x0002;
        {                                                    
           kal_uint16 compensate_temp=0, count = 0;
           *AFE_AMCU_CON2 |= 0x8000;          
           while(count < COMPENSATE_NO)
           {
           	  *AFE_AMCU_CON7 = compensate_temp;
           	  *AFE_AMCU_CON6 = compensate_temp;
           	  compensate_temp+=37;
           	  AFE_DELAY(50);
           	  count++;
           }
           *AFE_AMCU_CON6 = afe.hp_dc_compensate_value_r;
           *AFE_AMCU_CON7 = afe.hp_dc_compensate_value_l;      
        }
      }
#endif      
      *ABBA_AUDIO_CON6 |= ((RG_AVCM_GEN_EN) | (RG_DEPOP_VCM_EN) );          
      *ABBA_AUDIO_CON2 = 0x8000;
      *ABBA_VOICE_CON3 &= (~RG_VBUF_PWDB);
      *ABBA_VOICE_CON3 |= ( RG_VREF24_EN|RG_VCM14_EN );
      *ABBA_AUDIO_CON4 = 0x1410;
      *ABBA_AUDIO_CON4 = 0x141C;
      
      AFE_DELAY(1000);
      if(afe.dc_calibrate_finish){
      #if HP_EN_UNDERSPK
         *ABBA_AUDIO_CON4 = 0x141F;
         *ABBA_AUDIO_CON4 = 0x101F;
      #else
         if( ( (a_lowest >= 0) && (afe.aud[a_lowest].out_dev & L1SP_BUFFER_EXT) ) ||
             ( (v_lowest >= 0) && (afe.aud[v_lowest].out_dev & L1SP_BUFFER_EXT) ) ||
             ( (v_lowest >= 0) && (afe.aud[v_lowest].out_dev & L1SP_BUFFER_0) && (Spk2In1) ) )
         {
            *ABBA_AUDIO_CON4 = 0x141C;
            *ABBA_AUDIO_CON4 = 0x101C;
         }else{
            *ABBA_AUDIO_CON4 = 0x141F;
            *ABBA_AUDIO_CON4 = 0x101F;
         }
      #endif
      }
      *ABBA_AUDIO_CON6 &= (~RG_DEPOP_VCM_EN);
      *ABBA_AUDIO_CON2 = 0x8011;
      afe.audio_dl_ena = KAL_TRUE;
      afe.voice_dl_ena = KAL_FALSE;
   }
#if !HP_EN_UNDERSPK
   if(( (a_lowest >= 0) && (afe.aud[a_lowest].out_dev & L1SP_BUFFER_EXT) ) ||
      ( (v_lowest >= 0) && (afe.aud[v_lowest].out_dev & L1SP_BUFFER_EXT) ) ||
      ( (v_lowest >= 0) && (afe.aud[v_lowest].out_dev & L1SP_BUFFER_0) && (Spk2In1) ) )
      {
         *ABBA_AUDIO_CON4 = 0x141C;
         *ABBA_AUDIO_CON4 = 0x101C;
      }else{
         *ABBA_AUDIO_CON4 = 0x141F;
         *ABBA_AUDIO_CON4 = 0x101F;
      }
#endif
}

static void AFE_Switch_AudDAC_AudAMP(kal_int16 v_lowest, kal_int16 a_lowest)
{
   if( (afe.aud[a_lowest].out_dev&L1SP_STEREO2MONO) ) 
      *AFE_AMCU_CON1 |= 0x4000;
   else
      *AFE_AMCU_CON1 &= (~0x4000);

   AFE_Switch_VoiceDAC_AudAMP(v_lowest, a_lowest);
}

static void AFE_Switch_VoiceDAC_VoiceAMP(kal_int16 v_lowest, kal_int16 a_lowest)
{
   if(!afe.voice_dl_ena)
   {                        
      *ABBA_AUDIO_CON6 |= RG_AVCM_GEN_EN;
      *ABBA_AUDIO_CON6 &= (~RG_DEPOP_VCM_EN);
      *ABBA_VOICE_CON0 = 0x0108;
      *ABBA_AUDIO_CON2 = 0x8300;
      *ABBA_AUDIO_CON4 = 0x0410;
      *ABBA_AUDIO_CON5 = 0x0906;
      *ABBA_VOICE_CON3 |= ( RG_VCM14_EN | RG_VREF24_EN );
      *ABBA_VOICE_CON2 = 0x4000;
      *ABBA_VOICE_CON3 |= RG_VBUF_PWDB;
      AFE_DELAY(1000);
      
      *ABBA_AUDIO_CON4 = 0x0414;
      AFE_DELAY(1000);
      
      *ABBA_AUDIO_CON4 = 0x1414;
      *ABBA_AUDIO_CON2 = 0x8011;
      *ABBA_VOICE_CON0 = 0x01B8 ;
      afe.voice_dl_ena = KAL_TRUE;
      afe.audio_dl_ena = KAL_FALSE;
   }
}

static void AFE_Switch_AudDAC_VoiceAMP(kal_int16 v_lowest, kal_int16 a_lowest)
{
   AFE_Switch_VoiceDAC_VoiceAMP(v_lowest, a_lowest);
}

static void AFE_Switch_VoiceAmp(kal_int16 v_lowest, kal_int16 a_lowest)
{
   if(L1SP_TONE == v_lowest || L1SP_KEYTONE == v_lowest){         
      afe.Pre_InSrc = (DTMF_MCU_IsPlaying()) ? SRC_AUDIO_DAC : SRC_VOICE_DAC;
   }else{
      afe.Pre_InSrc = (SND_SRC_MAP>>v_lowest*2)&3;
   } 
   
   switch(afe.Pre_InSrc) {
      /// determine the source for the aud function v_lowest
      case SRC_VOICE_DAC:
         afe_prompt_trace( MOD_L1SP, "v(%x) a(%x) , SRC_VOICE_DAC ", v_lowest, a_lowest);
         if( afe.fir_flag & (1<<v_lowest) ){
            *COMPEN_BLOCK_FLT_PAR_PTR |= 3;
         }else if (!afe.toneLoopbackRec){
            *COMPEN_BLOCK_FLT_PAR_PTR &= (~3);
         }
         AFE_Switch_VoiceDAC_VoiceAMP(v_lowest, a_lowest);
         break;
      case SRC_AUDIO_DAC:
         afe_prompt_trace( MOD_L1SP, "v(%x) a(%x) , SRC_AUDIO_DAC ", v_lowest, a_lowest);
         AFE_Switch_AudDAC_VoiceAMP(v_lowest, a_lowest);
         break;
      case SRC_EXT_INPUT:
         afe_prompt_trace( MOD_L1SP, "v(%x) a(%x) , SRC_EXT_INPUT ", v_lowest, a_lowest);
         break;
   }
   
   UpdatePGAGain( v_lowest );

   kal_trace(TRACE_STATE, AFE_GAIN, *ABBA_AUDIO_CON1, *ABBA_AUDIO_CON2, *DP_SIDETONE_VOL);
}

static void AFE_Switch_AudAmp(kal_int16 v_lowest, kal_int16 a_lowest)
{
   if(L1SP_TONE == a_lowest || L1SP_KEYTONE == a_lowest){
      afe.Pre_InSrc = (DTMF_MCU_IsPlaying()) ? SRC_AUDIO_DAC : SRC_VOICE_DAC;
   }else{
      afe.Pre_InSrc = (SND_SRC_MAP>>a_lowest*2)&3;
   } 
   
   switch(afe.Pre_InSrc) {
      case SRC_VOICE_DAC:
         afe_prompt_trace( MOD_L1SP, "v(%x) a(%x) , SRC_VOICE_DAC ", v_lowest, a_lowest);
         if( afe.fir_flag & (1<<a_lowest) ){
            *COMPEN_BLOCK_FLT_PAR_PTR |= 3;
         }else if (!afe.toneLoopbackRec){
            *COMPEN_BLOCK_FLT_PAR_PTR &= (~3);
         }
         //// turn on only BIAS & DAC
         AFE_Switch_VoiceDAC_AudAMP(v_lowest, a_lowest);
         break;
      case SRC_AUDIO_DAC:
         afe_prompt_trace( MOD_L1SP, "v(%x) a(%x), SRC_AUDIO_DAC ", v_lowest, a_lowest);
         AFE_Switch_AudDAC_AudAMP(v_lowest, a_lowest);
         break;
      case SRC_EXT_INPUT:
         afe_prompt_trace( MOD_L1SP, "v(%x) a(%x) , SRC_EXT_INPUT ", v_lowest, a_lowest);
         break;
   }
   
   UpdatePGAGain( a_lowest );

   kal_trace(TRACE_STATE, AFE_GAIN, *ABBA_AUDIO_CON1, *ABBA_AUDIO_CON2, *DP_SIDETONE_VOL);
}

static void AFE_Switch_No_VoiceAudAmp()
{
   // If there is no aud function which wants to output through
   // Voice Amp-0 or Voice Amp-1 or Audio Amp.
   // Update MIC volume here for the scenario that microphone is turned on with no speaker on 
   if( afe.mic_flag && !afe.mic_mute && !afe.mute) 
   {
      UpdateAGCGain((kal_uint16)afe.mic_volume);
   }
   else  // Voice buffer & Audio buffer & mic all off, then enter low power mode
   {
   }

   UpdateVAPDN( 0 );

#if __AFE_AUDIO_DELAY_OFF__
   if( (afe.Audio_close_delay<0) && (afe.Audio_close_delay_expired==KAL_FALSE) )
      afe.Audio_close_delay = afe.AUDIOCLOSEDELAY; 
                 
   if(AUDIO_CLOSE_DELAY==0 || afe.Audio_close_delay==0)
      afe.Audio_close_delay_expired = KAL_TRUE;
      
 #ifdef BGSND_ENABLE
   if( (!afe.Pre_OutDev) || (AFE_IsKaraok()) || (afe.sp_flag) || (AM_IsBgsndOn()) ) //voice out
 #else
   if( (!afe.Pre_OutDev) || (AFE_IsKaraok()) || (afe.sp_flag) ) //voice out
 #endif 
   {
      if( (afe.sp_flag == (1 << L1SP_AUDIO)) && ( afe.aud[L1SP_AUDIO].volume == 0 || afe.aud[L1SP_AUDIO].mute == KAL_TRUE) )
      {
      }
      else{
         afe.Audio_close_delay = 0;
         afe.Audio_close_delay_expired = KAL_TRUE;
      }
   }
   else //audio out
   {
      if(afe.Pre_InSrc==SRC_EXT_INPUT) //SRC_AUDIO_DAC, SRC_VOICE_DAC
      {
         afe.Audio_close_delay = 0;
         afe.Audio_close_delay_expired = KAL_TRUE;
      }
   }
       
   if( (afe.Audio_gpt_on==KAL_FALSE) && (afe.Audio_close_delay>0) )
   {
      SGPT_CTRL_START_T start;
      start.u2Tick = afe.Audio_close_delay;
      start.pfCallback = Audio_DelayCloseHandler;
      start.vPara = 0;
      DclSGPT_Control(afe.Audio_gpt,  SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);
      afe.Audio_gpt_on = KAL_TRUE;
   
      _AfeSetHardwareMute(true);
      afe.afe_state = AFE_STATE_IDLE_OFF;
   }
#else
   afe.Audio_close_delay_expired = KAL_TRUE;
#endif
   afe_prompt_trace(MOD_L1SP,"AFE noAVamp:delayoff_%x; pre_%x; karaok_%x; sp_%x",afe.Audio_close_delay_expired,afe.Pre_OutDev,AFE_IsKaraok(),afe.sp_flag);
   
#if __AFE_PA_DELAY_OFF__
   if(afe.pa_delay == -1 && (afe.afe_state != AFE_STATE_OFF))
   {
      if(!L1SP_IsBluetoothOn())
      {
         afe.pa_delay = AFE_PA_DELAY_NUM;
         AFE_SetRefresh();
      }
   }
#endif

#if __AFE_PA_DELAY_OFF__
   if(afe.Audio_close_delay_expired && afe.pa_delay==0)
#else
   if(afe.Audio_close_delay_expired)
#endif
   {
      AVolumeRampDown();
      if(afe.powerOffWait > 0 ){
         return;
      }
      else if(afe.powerOffWait == 0){
         *ABBA_AUDIO_CON6 = ( (0x90) | (CUSTOM_RG_DEPOP_CURSEL<<8) );
      }

      if(afe.audio_dl_ena)
      {
         if( (afe.system_poweroff) && (afe.Pre_InSrc == SRC_AUDIO_DAC) && (afe.powerOffWait == -1) && (afe.audio_fs == ASP_FS_32K) )
         {
            *ABBA_AUDIO_CON5 = 0x0106;
            *ABBA_AUDIO_CON4 = 0x1400;
            *ABBA_AUDIO_CON6 = ( (0x91) | (CUSTOM_RG_DEPOP_CURSEL<<8) );
            afe.powerOffWait = 250;
            return;
         }
         *ABBA_AUDIO_CON2 = 0x8000;
         *ABBA_AUDIO_CON6 |= (RG_DEPOP_VCM_EN);
         *ABBA_AUDIO_CON4 = 0x141F;
         *ABBA_AUDIO_CON4 = 0x0400;
         *ABBA_AUDIO_CON6 &= (~(RG_AVCM_GEN_EN | RG_ABIRX_ZCD_EN ) );
         *ABBA_VOICE_CON0 &= (~RG_VBIRX_ZCD_EN);
         if(!(afe.voice_ul_ena || afe.accessory_flag))
            *ABBA_VOICE_CON3 &= (~(RG_VREF24_EN|RG_VCM14_EN));
         *ABBA_AUDIO_CON2 = 0x8011;
         afe.audio_dl_ena = KAL_FALSE;
         afe.powerOffWait = -1;
      }
      if(afe.voice_dl_ena)
      {
         *ABBA_VOICE_CON0 = 0x0108;
         *ABBA_VOICE_CON3 &= (~(RG_VBUF_PWDB));
         *ABBA_AUDIO_CON2 = 0x8300;
         *ABBA_AUDIO_CON4 = 0x0400;
         *ABBA_AUDIO_CON6 &= (~(RG_AVCM_GEN_EN | RG_ABIRX_ZCD_EN ) );
         if(!(afe.voice_ul_ena || afe.accessory_flag))
            *ABBA_VOICE_CON3 &= (~(RG_VREF24_EN|RG_VCM14_EN));
         *ABBA_AUDIO_CON5 = 0x0106;
         afe.voice_dl_ena = KAL_FALSE;
      }
#if __AFE_HP_DC_CALIBRATION__
      if(afe.hp_dc_compensate_value_r || afe.hp_dc_compensate_value_l)
      {
      	 *AFE_AMCU_CON2 &= ~0x8000;
         *AFE_AMCU_CON7 = 0;
      }
#endif      
      #if __AFE_PA_DELAY_OFF__
         afe.pa_delay = -1;
      #endif
      afe.afe_state = AFE_STATE_OFF;
   }
   else if( AFE_IsInDelayOff() )
   {
      if(afe.audio_dl_ena || afe.voice_dl_ena)
         AVolumeRampDown();
   }
}

/* ========================================================================= */
/*   AFE Event Handler                                                       */
/*   This function runs under the context of L1Audio Task                    */
/* ========================================================================= */
void AFE_Chip_Event_Handler( void *data )
{
   {
      kal_int16 v_lowest = -1, a_lowest = -1;
      afe_prompt_trace(MOD_L1SP,"AFE EventHdlr:spflag:%x",afe.sp_flag);
      if( afe.sp_flag ) {
         /// v_lowest: the highest priority aud function which outputs through
         ///           Voice Amp-0 or Voice Amp-1
         /// a_lowest: the highest priority aud function which outputs through
         ///           Audio Amp
         SearchSpkFlag( &v_lowest, &a_lowest );
         afe_prompt_trace(MOD_L1SP,"AFE EventHdlrSPEnable:a_%x, v_%x",a_lowest,v_lowest);
         if(v_lowest >=0 || a_lowest >=0 ){
            *ABBA_AUDIO_CON2 &= (~(RG_AMUTER|RG_AMUTEL));
         }
      #if defined(__BT_SUPPORT__)
         if (((a_lowest < 0) && (v_lowest < 0) && AM_IsBluetoothOn()) || ((a_lowest < 0) && (v_lowest < 0) && afe.bt_flag))
         {
             if(afe.afe_state==AFE_STATE_IDLE_OFF)
             {
               #if __AFE_AUDIO_DELAY_OFF__
                  if(afe.Audio_close_delay>0)
                  {
                     if(afe.Audio_gpt_on)
                     { 
                        DclSGPT_Control( afe.Audio_gpt, SGPT_CMD_STOP, 0);
                        afe.Audio_gpt_on = KAL_FALSE;
                     }       
                     afe.Audio_close_delay = 0;
                     afe.Audio_close_delay_expired = KAL_TRUE;
                     AFE_SetRefresh();
                  }
               #endif
             }
         }
      #endif
      }
      L1Audio_Msg_AFE_SpkSelect( v_lowest, a_lowest, afe.fir_flag, afe.mic_flag, afe.mic_volume );
   #if defined(EXT_DAC_SUPPORT)
      if(a_lowest != -1 && !afe.ext_dac_mute && (afe.aud[a_lowest].out_dev & (L1SP_EXT_DAC_BUF0 | L1SP_EXT_DAC_BUF1)))
      {
         if(afe.ext_dac_aud_func != a_lowest)
         {
            kal_uint8 out_spk;  
            
            afe.ext_dac_aud_func = a_lowest;                   
            out_spk = afe.aud[a_lowest].out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1);       
            
            switch((SND_SRC_MAP>>a_lowest*2)&3) 
            {            
               case SRC_AUDIO_DAC:
                  EXT_DAC_SetPlaybackFreq(afe.ext_dac_freq);
                  EXT_DAC_TurnOnSpeaker(EXT_DAC_I2S , out_spk );    
                  AFE_TurnOnEDI(0, 1, L1SP_EXT_DAC_I2S_BCLK_SCALE >> 1); 
                  EXT_DAC_SetVolume(out_spk , afe.ext_dac_aud_vol);
                  afe.ext_dac_i2s_on = KAL_TRUE;
                  if(afe.ext_dac_add_st)
                     a_lowest = -1;  // Turn Off Audio Stereo Buffer When using EXT_DAC only    
                  break;
               case SRC_VOICE_DAC:   
               case SRC_EXT_INPUT:
                  EXT_DAC_TurnOnSpeaker(EXT_DAC_LINEIN , out_spk); 
                  EXT_DAC_FixedLineInGain(out_spk);
                  break;
            }
         }
         else 
         {
            if(((SND_SRC_MAP>>a_lowest*2)&3) == SRC_AUDIO_DAC && afe.ext_dac_add_st)
               a_lowest = -1;
         }
         if(afe.ext_dac_aud_func == L1SP_AUDIO)
            PcmSink_SetGain(((kal_uint32) DG_DAF * afe.ext_dac_level_gain) >> 15);
      }  
      else 
      {
         if(afe.ext_dac_aud_func != -1)
         {
            kal_uint8 out_spk;  
            out_spk = afe.aud[afe.ext_dac_aud_func].out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1);
            afe.ext_dac_aud_func = -1; 
            if(afe.ext_dac_i2s_on)
            {           
               AFE_TurnOffEDI(); 
               afe.ext_dac_i2s_on = KAL_FALSE;             
            }                        
            EXT_DAC_TurnOffSpeaker(out_spk);
         }   
      }
   #endif
      
      if(v_lowest >=0 && a_lowest >=0 ){// only allow a path output
         if(v_lowest <= a_lowest)
            a_lowest = -1;
         else
            v_lowest = -1;
      }
      
      if( v_lowest >= 0 || a_lowest >=0 || (afe.mic_flag && !afe.mic_mute && !afe.mute))
      {
         afe.bPowerDown = KAL_FALSE;
      #if defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
         if(!afe.aux_Audio_on)
         {
            AUX_CTRL_SET_AUDIO_STATUS_T sta;
            sta.eAudioStatus = DCL_AUX_AUDIO_STATUS_OPEN;
            DclAUX_Control( afe.dcl_aux_handle, AUX_CMD_SET_AUDIO_STATUS, (DCL_CTRL_DATA_T *)&sta );
            afe.aux_Audio_on = KAL_TRUE;
         }
      #endif
      }

      if(a_lowest >=0 || v_lowest >=0)
      {
      #if __AFE_PA_DELAY_OFF__
         afe.pa_delay = -1;
      #endif
      #if __AFE_AUDIO_DELAY_OFF__
         if(afe.Audio_gpt_on)
         {
            DclSGPT_Control( afe.Audio_gpt, SGPT_CMD_STOP, 0);
            afe.Audio_gpt_on = KAL_FALSE;
         }
   
         afe.Audio_close_delay = -1;
         afe.Audio_close_delay_expired = KAL_FALSE;
      #endif

         if(v_lowest>=0)
         {
            afe.Pre_OutDev = 0;
         }
         else
         {
            afe.Pre_OutDev = 1;
            afe.Pre_aFunc = a_lowest;
         }
         _AfeSetHardwareMute(false);
         afe.afe_state = AFE_STATE_ON;
      }
      /// Switch amplifier
      if(afe.ext_op_on)
         _AFE_Switch_TurnOff_Amp(v_lowest, a_lowest);
   //==================================================================================================
      if( v_lowest >= 0 ) {
         AFE_Switch_VoiceAmp(v_lowest, a_lowest);
      }
      //==================================================================================================
      else if( a_lowest >= 0 ) {
         AFE_Switch_AudAmp(v_lowest, a_lowest);
      }
      //==================================================================================================
      else {
         AFE_Switch_No_VoiceAudAmp();
      }
      kal_brief_trace(TRACE_STATE, AFE_STATE_INFO, afe.afe_state, v_lowest, v_lowest, a_lowest, a_lowest); 
      afe.bPowerDown = KAL_TRUE;

      if( v_lowest >= 0 || a_lowest >=0 )
      {
         kal_brief_trace(TRACE_STATE, AFE_GAIN, *ABBA_AUDIO_CON1, *ABBA_AUDIO_CON2, *DP_SIDETONE_VOL);
      }
      /// Switch amplifier
      if(!afe.ext_op_on)
         _AFE_Switch_TurnOn_Amp(v_lowest, a_lowest);
   #ifdef EXTERNAL_AMPLIFIER_ROUTE_CONFIGURATION
      //external audio amplifer route path config.
      if ((v_lowest < L1SP_MAX_AUDIO) && (a_lowest < L1SP_MAX_AUDIO)) 
      { 
         AFE_SetOutputDeviceExtAmp(v_lowest, (v_lowest >= 0) ? afe.aud[v_lowest].out_dev : 0, 
                                   a_lowest, (a_lowest >= 0) ? afe.aud[a_lowest].out_dev : 0);
      }
   #endif
#if __AFE_CLASSK_SUPPORT_INTERNAL__   
      if(afe.ext_op_on)
      {
      	 if(afe.cp_disable && AFE_IsCPEnable())
      	 {
      	 	  _AFE_Switch_ChargePump(KAL_TRUE, CP_STATE_ON_BYPASS); 
      	 }
      	 else if(!afe.cp_disable)               
      	 {
      	 	 if(Check_CP_available())
      	 	 {
      	 	    _AFE_Switch_ChargePump(KAL_TRUE, CP_STATE_ON_BOOST);
      	 	 }
      	 	 else
      	 	 {
      	 	   _AFE_Switch_ChargePump(KAL_TRUE, CP_STATE_ON_BYPASS); 
      	 	 }   
      	 }
      }
#endif
      _apply_mic_setting(a_lowest, v_lowest);
   }
   
}

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        AFE Manager 
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
/* ========================================================================= */
/*   AFE Manager                                                             */
/*   This function runs under the context of L1 ISR                          */
/* ========================================================================= */
void AFE_Manager( void )
{
   DelayCmd dc;
   if( afe.ext_op_delay != 0 ) {
      if( afe.ext_op_delay > 0 ) {
         if( --afe.ext_op_delay == 0 ) {
            #if __AFE_CLASSK_SUPPORT_INTERNAL__
            if(Check_CP_available())
               _AFE_Switch_ChargePump(KAL_TRUE, CP_STATE_ON_BOOST);
            else
            	 _AFE_Switch_ChargePump(KAL_TRUE, CP_STATE_ON_BYPASS);   
            #endif
            _AFE_Switch_IntAmp(KAL_TRUE);
            AFE_SwitchExtAmplifier( true );
            afe.ext_op_on = KAL_TRUE;
         }
      }
      else { /* afe.ext_op_delay < 0 */
         if( ++afe.ext_op_delay == 0 ) {
            *ABBA_AUDIO_CON2 |= (RG_AMUTER|RG_AMUTEL);
            _AFE_Switch_IntAmp(KAL_FALSE);
            AFE_SwitchExtAmplifier( false );
            #if __AFE_CLASSK_SUPPORT_INTERNAL__
            _AFE_Switch_ChargePump(KAL_FALSE, CP_STATE_OFF);
            #endif
            afe.ext_op_on = KAL_FALSE;
            AFE_SetRefresh();
         }
      }
   }
   
#if __AFE_PA_DELAY_OFF__
   if(afe.pa_delay > 0){
      afe.pa_delay--;
      if(afe.pa_delay == 0)
         AFE_SetRefresh();
   }
#endif
   
   if(afe.powerOffWait > 0)
      afe.powerOffWait--;
   if(afe.powerOffWait == 0)
      AFE_SetRefresh();
   
   if(afe.md2glock_checking){
      kal_set_timer(afe.timer, AFE_Timer_Handler, 0, 1, 0);   //to avoid race condition
      return;
   }
   
   if( !RB_EMPTY( afe.regq ) ) {
      RB_GET( afe.regq, dc );
      *dc.addr = dc.val;
   }
   
   if(afe.v8k_off_request)
   {
      if( (!afe.voice_dl_ena) && (afe.bPowerDown))
      {
         if( !((afe.audio_clk_ena == KAL_FALSE) && (afe.audio_dl_ena == KAL_TRUE) ) )
         {
            if(afe.audio_clk_ena){
               *AFE_VMCU_CON0 = 0;
            }else{
               _AFE_MDIE_CtrlSeq(KAL_FALSE, KAL_FALSE, afe.die2die_status);
               *ABBA_WR_PATH4 &= (~0x8000);
               *AFE_VMCU_CON3 &= (~0x0020);
            }
            *AFE_VMCU_CON6 &= (~0x0001);
            afe.voice_clk_ena = KAL_FALSE;
            afe.v8k_off_request = KAL_FALSE;
         }
      }
   }
   
   if(afe.aClk_off_request)
   {
      if( (!afe.audio_dl_ena) && (afe.bPowerDown) )
      {
         if(afe.voice_clk_ena){
            *AFE_AMCU_CON0 = 0;
         }else{
            _AFE_MDIE_CtrlSeq(KAL_FALSE, KAL_TRUE, afe.die2die_status);
            *ABBA_WR_PATH4 &= (~0x8000);
            *AFE_VMCU_CON3 &= (~0x0020);
         }
         afe.audio_clk_ena = KAL_FALSE;
         afe.aClk_off_request = KAL_FALSE;
      }
   }
   
#if __AFE_MD2G_PWDN_LOCK__
   if(afe.voice_clk_ena || afe.audio_clk_ena || afe.sp_flag)
   {
      if(!afe.fgIdleOffTimerSet)
      {
         afe.fgIdleOffTimerSet = KAL_TRUE;
         AFE_SetRefresh();
      }
   }
   else
   {
      if(afe.fgIdleOffTimerSet)
      {
         afe.fgIdleOffTimerSet = KAL_FALSE;
         AFE_SetRefresh();
      }
   }
#endif

#if __CTIRQ_SLEEP_PLATFORM__
   if( (afe.ext_op_delay != 0) || !RB_EMPTY( afe.regq ) || (afe.powerOffWait >= 0) )
      kal_set_timer(afe.timer, AFE_Timer_Handler, 0, 1, 0);
 #if __AFE_PA_DELAY_OFF__
   else if(afe.pa_delay > 0)
      kal_set_timer(afe.timer, AFE_Timer_Handler, 0, 1, 0);
 #endif
#endif
}
//=============================================================================================
//                  DC Calibration/Compensation
//=============================================================================================
static kal_uint16 _AFE_Calculate_DC_Value(kal_int32 dc_offset_value)
{
   kal_int32 dc_compensation_tmp = 0;
   kal_uint16 dc_compensation_value = 0; 
   // For speaker amp +6dB case, 
   // x : DC compensation value (mV)
   // y : DSP compensation value
   // y = -176.16 * x + 2.9752
   if ((*SPK_CON0 & 0x0030) == 0x30)
   {   // 12dB
       dc_compensation_tmp = (dc_offset_value >> 1) * (176) + 3;
   }
   else
   {   // 6dB
       dc_compensation_tmp = dc_offset_value * (176) + 3;
   }
 
   if(dc_compensation_tmp>=0) //compensation value > 0
   {
      dc_compensation_value = (uint16)dc_compensation_tmp;
   }
   else //compensation value < 0
   {
      dc_compensation_value = (uint16)(0 - dc_compensation_tmp);
      dc_compensation_value = (~dc_compensation_value) + 1;
   }  
   
   return dc_compensation_value;

}

void AFE_DC_Calibration_WriteBack(void)
{
#if 1
   if( !afe.dc_calibrate_writeback && afe.dc_calibrate_finish )
   {
      afe.dc_calibrate_writeback = KAL_TRUE;   
      if(afe.Pre_DC_OFFSET != afe.DC_OFFSET)
         afe.pDC_Calibration_CallBack(&afe.Callback_DCOffset); 
   }
#endif
}
static void Earphone_DC_Calibration(void)
{
#if __AFE_HP_DC_CALIBRATION__	
   #define E_BUF_LEN    120
   #define u2Channel_R  8
   #define u2Channel_L  7
   #define hp_u2Samples    (100+20)
      
   kal_uint16 au2Buf[E_BUF_LEN];
      
   #define hp_u4NLen 100
   #define hp_u4MLen 20
   #define hp_AVGCountDef 4 // don't modify it
      
   kal_uint16 u2CalResult_L[hp_AVGCountDef][2];
   kal_uint16 u2CalResult_R[hp_AVGCountDef][2];
   kal_uint16 u2Result[hp_u4MLen];

   kal_int16 I,J,K,L,M;
   kal_uint32 u4Sum = 0;
   kal_uint32 u4Sum2 = 0;
   
   kal_uint8 AVGCount = hp_AVGCountDef;
   kal_int16 DCOffSet_L[hp_AVGCountDef];
   kal_int16 DCOffSet_R[hp_AVGCountDef];
   kal_int16 AvgDCOffSet; 
   kal_int16 offset_sum= hp_AVGCountDef; 
   kal_int16 DCOffsetSum_L = 0;
   kal_int16 DCOffsetSum_R = 0;
   kal_int32 AvgDCOffSetVol; 

   DCL_HANDLE dcl_hadc_handle;
   ADC_CTRL_GET_IMM_DATA_ON_BOOTING_T GetImmDataOnBooting;

	_AFE_MDIE_CtrlSeq(KAL_TRUE, KAL_TRUE, AFE_DIE2DIE_DOWNLINK); // turn on die2die interface and clk

	//gen silence 
	*AFE_AMCU_CON1 |= 0x003c; //mute
	*AFE_DAC_TEST |= 0x6000;  //audio sine tone gen

	*AFE_AMCU_CON1 &= ~0x4000; //disable mono mode

   dcl_hadc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
   {
      for(K=0; K<2; K++)
      {
      	 if (K == 0)
         {
             *ABBA_AUDIO_CON2 = 0x8000; //-3dB
             AFE_Switch_VoiceDAC_AudAMP(0,0);   // turn on audio dac & buffer                 			     
         }
         else
         {
         	    //disable HP dc compensation                        
              *AFE_AMCU_CON2 &= ~0x8000;
              *AFE_AMCU_CON7 = 0;      

         	    *ABBA_AUDIO_CON6 |= RG_DEPOP_VCM_EN; 
         	    //turn off audio dac & buffer
              *ABBA_AUDIO_CON2 = 0x8000;
              *ABBA_AUDIO_CON4 = 0x141C;
              *ABBA_AUDIO_CON4 = 0x0400;
              *ABBA_VOICE_CON3 &= (~(RG_VREF24_EN|RG_VCM14_EN));
              *ABBA_AUDIO_CON2 = 0x8011;
              afe.audio_dl_ena = KAL_FALSE;
              AFE_DELAY(24000);      	             	     
         }
      	
         for(L=0; L<AVGCount; L++)
         {
             for(M=0; M<2; M++)
             {
               u4Sum = 0; 
               if(M==0)
               {        
                  GetImmDataOnBooting.u4Channel = (DCL_UINT32)u2Channel_L;
               }
               else
               {           
                  GetImmDataOnBooting.u4Channel = (DCL_UINT32)u2Channel_R;   
               }
               GetImmDataOnBooting.u4MeaCount= (DCL_UINT32)hp_u2Samples;
               GetImmDataOnBooting.u2ADCData = (DCL_UINT16 *)au2Buf;
               DclSADC_Control(dcl_hadc_handle, ADC_CMD_GET_IMM_DATA_ON_BOOTING, (DCL_CTRL_DATA_T *)&GetImmDataOnBooting);
               
               for (J=0 ; J<hp_u4MLen; J++)
               {
                  for (I=0; I<hp_u4NLen; I++)
                  {
                     u4Sum = u4Sum + au2Buf[I+J];
                  }
               
                  u2Result[J] = u4Sum/hp_u4NLen;
                  u4Sum = 0;
               }
               
               u4Sum2 = 0;
               for (J=0 ; J<hp_u4MLen; J++)
               {
                  u4Sum2 = u4Sum2 + u2Result[J];
               }
               
               if (M == 0)
               {
               	  u2CalResult_L[L][K] = u4Sum2/hp_u4MLen;
               }
               else
               {
               	  u2CalResult_R[L][K] = u4Sum2/hp_u4MLen;
               }
             }
         }      
         AFE_DELAY(1000);
      }
      
      for(L=0; L<AVGCount; L++) 
      {
      	 DCOffSet_L[L] = (kal_int16)((kal_int16)u2CalResult_L[L][0] - (kal_int16)u2CalResult_L[L][1]);
         DCOffSet_R[L] = (kal_int16)((kal_int16)u2CalResult_R[L][0] - (kal_int16)u2CalResult_R[L][1]);
         DCOffsetSum_L += (kal_int16)((kal_int16)u2CalResult_L[L][0] - (kal_int16)u2CalResult_L[L][1]);
         DCOffsetSum_R += (kal_int16)((kal_int16)u2CalResult_R[L][0] - (kal_int16)u2CalResult_R[L][1]);
      }
      
      DclSADC_Close(dcl_hadc_handle);
   }  
   
   // turn off DAC tone
   *AFE_DAC_TEST &= (~0x6000);
   *AFE_AMCU_CON1 &= (~0x000c);

   _AFE_MDIE_CtrlSeq(KAL_FALSE, KAL_TRUE, AFE_DIE2DIE_DOWNLINK);

    if (DCOffsetSum_L>offset_sum || (DCOffsetSum_L<-offset_sum))
    {
        afe.hp_dc_compensate_value_l=(kal_uint16)(((kal_int32)DCOffsetSum_L*175*(37) >>8)-131);
    }
    
    if (DCOffsetSum_R>offset_sum || (DCOffsetSum_R<-offset_sum))
    {
        afe.hp_dc_compensate_value_r=(kal_uint16)(((kal_int32)DCOffsetSum_R*175*(37) >>8)-88);
    }

#endif   
}

void DC_Calibration(void)
{
#if 1
   #define BUF_LEN  120
   #define u2Channel  9
   #define u2Samples (100+20)
      
   kal_uint16 au2Buf[BUF_LEN];
      
   #define u4NLen 100
   #define u4MLen 20
      
   kal_uint16 u2CalResult[2];
   kal_uint16 u2Result[u4MLen];

   kal_int16 I,J,K,L;
   kal_uint32 u4Sum = 0;
   kal_uint32 u4Sum2 = 0;

   #define AVGCountDef 3
   kal_uint8 AVGCount = AVGCountDef;
   kal_int16 DCOffSet[AVGCountDef];
   kal_int16 AvgDCOffSet; 
   kal_int16 DCOffsetSum = 0;
   kal_int32 AvgDCOffSetVol; 

   DCL_HANDLE dcl_hadc_handle;
   ADC_CTRL_GET_IMM_DATA_ON_BOOTING_T GetImmDataOnBooting;
      
   _AFE_MDIE_CtrlSeq(KAL_TRUE, KAL_TRUE, AFE_DIE2DIE_DOWNLINK); // turn on die2die interface and clk
   
   *AFE_AMCU_CON1 &= ~0x4000; //disable mono mode

   //gen silence 
   *AFE_AMCU_CON1 |= 0x003c; //mute
   *AFE_DAC_TEST |= 0x6000; //audio sine tone gen
   
   AFE_Switch_VoiceDAC_AudAMP(0,0);   // turn on audio dac & buffer
   
   _AFE_Switch_IntAmp(KAL_TRUE);
   *SPK_CON0 = ( (*SPK_CON0&0xFFCF)|(SpkAmpGain<<4) );
   AFE_DELAY(1000);

   //enable dc compensation   
   *AFE_AMCU_CON2 |= 0x8000;  
   *AFE_AMCU_CON7 = _AFE_Calculate_DC_Value((kal_int32)afe.Pre_DC_OFFSET);     

   DCOffsetSum = 0;
   dcl_hadc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
   {
      for(L=0; L<AVGCount; L++)
      {
         for(K=0; K<2; K++)
         {
            u4Sum = 0;
            if(K==0)
            {
                *SPK_CON8 |= 0x0200;
            }
            else
            {
                *SPK_CON8 &= (~0x0200);
            }
            {
               //enable calibration
               *SPK_CON8 |= 0x0040;
            }
            GetImmDataOnBooting.u4Channel = (DCL_UINT32)u2Channel;
            GetImmDataOnBooting.u4MeaCount= (DCL_UINT32)u2Samples;
            GetImmDataOnBooting.u2ADCData= (DCL_UINT16 *)au2Buf;
            DclSADC_Control(dcl_hadc_handle, ADC_CMD_GET_IMM_DATA_ON_BOOTING, (DCL_CTRL_DATA_T *)&GetImmDataOnBooting);
         
            for (J=0 ; J<u4MLen; J++)
            {
               for (I=0; I<u4NLen; I++)
               {
                  u4Sum = u4Sum + au2Buf[I+J];
               }
         
               u2Result[J] = u4Sum/u4NLen;
               u4Sum = 0;
            }
         
            u4Sum2 = 0;
            for (J=0 ; J<u4MLen; J++)
            {
               u4Sum2 = u4Sum2 + u2Result[J];
            }
         
            u2CalResult[K] = u4Sum2/u4MLen;
            afe_prompt_trace(MOD_L1SP, "Calibration Result %d = %d", K, u2CalResult[K]);
            
            {
                //disable calibration
               *SPK_CON8 &= (~0x0040);
            }
         }
      
         DCOffSet[L] = (kal_int16)((kal_int16)u2CalResult[0] - (kal_int16)u2CalResult[1]);
         DCOffsetSum += (kal_int16)((kal_int16)u2CalResult[0] - (kal_int16)u2CalResult[1]);
      
         //kal_sleep_task(1);
         AFE_DELAY(1000);
      }
      
      DclSADC_Close(dcl_hadc_handle);
      
      if( (DCOffsetSum%AVGCount) > (AVGCount/2) )
         AvgDCOffSet = (DCOffsetSum+(AVGCount-1))/AVGCount;
      else
         AvgDCOffSet = DCOffsetSum/AVGCount;
      
      if( ((AvgDCOffSet*175)%64) > 32 )
         AvgDCOffSetVol = (AvgDCOffSet*175+63)/64; //AvgDCOffSet*2800/1024; //mV
      else
         AvgDCOffSetVol = AvgDCOffSet*175/64; //AvgDCOffSet*2800/1024; //mV
      
      afe.DC_OFFSET += (kal_int16)AvgDCOffSetVol;
      //wdc_offset = (kal_int16)AvgDCOffSetVol;
   }
   //DOUg
   _AFE_Switch_IntAmp(KAL_FALSE);
   AFE_SwitchExtAmplifier( false );

#if !__AFE_HP_DC_CALIBRATION__	
   //disable dc compensation   
   *AFE_AMCU_CON2 &= ~0x8000; 
   *AFE_AMCU_CON7 = 0; 
   
   //turn off audio dac & buffer
   *ABBA_AUDIO_CON2 = 0x8000;
   *ABBA_AUDIO_CON4 = 0x141C;
   *ABBA_AUDIO_CON4 = 0x0400;
   *ABBA_VOICE_CON3 &= (~(RG_VREF24_EN|RG_VCM14_EN));
   *ABBA_AUDIO_CON2 = 0x8011;
   afe.audio_dl_ena = KAL_FALSE;

   *AFE_DAC_TEST &= (~0x6000);
   *AFE_AMCU_CON1 &= (~0x000c);

   _AFE_MDIE_CtrlSeq(KAL_FALSE, KAL_TRUE, AFE_DIE2DIE_DOWNLINK);
#endif
   
   if( (afe.DC_OFFSET>100) || (afe.DC_OFFSET<-100) )
      afe.DC_OFFSET = 0; //to protect

   afe.Callback_DCOffset = (kal_uint16)afe.DC_OFFSET; //(kal_uint16)wdc_offset; 
     
   afe.dc_calibrate_finish = KAL_TRUE;
   afe.spk_dc_compensate_value = _AFE_Calculate_DC_Value((kal_int32)afe.DC_OFFSET);
       
   Earphone_DC_Calibration(); 
   
#endif
}

kal_int16 AFE_GetDCOffSet(void)
{
   return afe.DC_OFFSET; //mv
}

//=============================================================================================
//                  Section: [Gain] __GAIN_TABLE_SUPPORT__ Specific Functions
//=============================================================================================
#if defined(__GAIN_TABLE_SUPPORT__)
void _AfeGetExtAmpPathUsage(kal_uint8 *ext_dac, kal_uint16 *ctrl_point)
{
   *ctrl_point = 2;
   *ext_dac = L1SP_BUFFER_EXT;
}

void _AfeGetExtPgaInfo(kal_uint8 ext_dac, kal_uint16 ctrl_point, kal_uint8* total_level, kal_uint8* bit_number)
{
   if (ctrl_point == 0){ //Class AB
      *total_level = 4;
      *bit_number = 3;
   } else {
      *total_level = 0;
      *bit_number = 0;
   }
}

void _AfeGetExtPgaGainMap(kal_uint8 ext_dac, kal_uint16 ctrl_point, kal_uint8 total_level, kal_int8* gain_map)
{
   kal_uint16 i;
   if (ctrl_point == 0) 
   {//Class AB
      ASSERT(total_level >= 4);
      gain_map[0] = -6;
      gain_map[1] = -3;
      gain_map[2] = 6;
      gain_map[3] = 12;
   } else {
      ASSERT(0);
   }
   

}
#endif

#if defined(__CLASSK_CP_SUPPORT__)
void _AFE_Switch_ChargePump(kal_bool on, AFE_VCP_T mode)
{
#if __AFE_CLASSK_SUPPORT_INTERNAL__
   //for test usage
   
   if(!L1Audio_IsInitiated())
   {
   	 return;
   }
#if __AFE_CURRENT_SENSOR_ENABLE__
  if(VIBR_Is_In_Calibration())
  {
  	 return;
  }
#endif   	     
   {
      kal_uint16 testflag;
      testflag = L1Audio_GetDebugInfo(AUDIO_DEBUG_MISC);
      if (testflag == AUDIO_DBG_VCP_FDISABLE)
      {
         afe.cp_state = CP_STATE_OFF;
         return;
      }
      else if (testflag == AUDIO_DBG_VCP_FENABLE)
      {
      	 kal_uint32  vbat_val  = audio_query_vbat_value() ;
      	 if( vbat_val < 4000000 && on)
      	 {
      	 	  mode = CP_STATE_ON_BOOST;
      	 }	
      }
   }

	 if(afe.cp_state == mode)
	 {
	 	 return;
	 }
	 if(on)
	 {
       // off -> CP/bypass
       if(afe.cp_state == CP_STATE_OFF)
       {
          *CP_CON3 |= 0x0001;
          *CP_CON0  = 0x0881;  //bypass mode                    
       }
       if((afe.cp_state == CP_STATE_ON_BOOST) && (mode== CP_STATE_ON_BYPASS))
       {
       	   *SPK_CON7= 0x04A0;
      	 	 *CP_CON0 = 0x0881; //change to bypass
      	 	 AFE_DELAY(2000);
      	 	 *SPK_CON7  = 0x0420; 
       }       
       else if(mode==CP_STATE_ON_BOOST)
	 	 	 {
	 	 	 	  *SPK_CON7  = 0x04A0; //vcm sel = 1   
	 	 	 	  *CP_CON0   = 0x2881; //change to boost
	 	 	 	  AFE_DELAY(2000);     //wait 2ms
	 	 	 	  *SPK_CON7  = 0x0420; //vcm sel = 0    
	 	 	 }      
	 }
	 else
	 {
      if(afe.cp_state == CP_STATE_ON_BOOST)
      {
      	  //change to bypass mode
      	  *CP_CON0 = 0x0881;
      	  AFE_DELAY(500);  //wait 500us     	 	 
      }
      *CP_CON0 &= (~0x1); //disable VCP
      *CP_CON3 &= (~0x1);
	 }
	 afe.cp_state = mode;
#endif	 
}

#ifdef __ATV_SUPPORT__
extern kal_bool mATV_Class_K_Implementation(void); //hostlib.h
#endif
#if defined(MT6260FM) 
extern kal_bool FMDrv_ClassK_Permit(void); 
#endif
kal_bool Check_CP_available(void)
{
#if __AFE_CLASSK_SUPPORT_INTERNAL__	
#if defined(MT6260FM) 
	kal_bool    fm_result = FMDrv_ClassK_Permit();
#else	
  kal_bool    fm_result = KAL_TRUE;
#endif	
#ifdef __ATV_SUPPORT__
	kal_bool    atv_result= mATV_Class_K_Implementation();
#else
  kal_bool    atv_result= KAL_TRUE;	
#endif	
	kal_bool    bt_result = KAL_TRUE;
	kal_bool    l1_result = KAL_TRUE;
	kal_uint32  vbat_val  = audio_query_vbat_value();
	kal_uint16  spk_gain  = afe.spk_vol;
	if(fm_result&&atv_result&&bt_result&&l1_result)
	{
		 //vbat < 4v and spk gain > 6 dB
		 if( (vbat_val < 4000000) && (spk_gain > 128) )
		 {
		 	 return KAL_TRUE;
		 }	
	}
#endif		
	return KAL_FALSE;
}

#endif //__CLASSK_CP_SUPPORT__
#if __AFE_CURRENT_SENSOR_ENABLE__
extern void VIBR_SetInitCoef(kal_uint16 vs_cf, kal_uint16 vs_df, kal_uint16 vs_mf, kal_bool restore);

void AFE_Retrieve_VIB_CF_Data(kal_int32 data)
{  
   afe.retrieved_cf_data = (kal_uint16)data;
   afe.vib_cali_wait = KAL_FALSE;
}

void AFE_Adc_MsgSend(kal_uint32 msg_name, void *data)
{  
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret_val = KAL_TRUE;
    ilm_struct *ilm_ptr = NULL;
    va_list varpars;

    /* First allocate a memory for an interlayer message structure */
    ilm_ptr = allocate_ilm(MOD_L1SP);

    ilm_ptr->msg_id = (msg_type) msg_name;  /* Set the message id */
    /* there are no peer message to be sent to UEM. Hence this field is null. */
    ilm_ptr->peer_buff_ptr = NULL; 
	 switch (msg_name)
    {
        case MSG_ID_BMT_ADC_ADD_ITEM_REQ:
        {
            bmt_adc_add_item_req_struct *parm_stream;
            parm_stream =
                (bmt_adc_add_item_req_struct*) construct_local_para(sizeof(bmt_adc_add_item_req_struct), TD_CTRL);
            parm_stream->adc_handle = (DCL_HANDLE)data;
            ilm_ptr->local_para_ptr = (local_para_struct*) parm_stream;
            break;
        }
        case MSG_ID_BMT_ADC_REMOVE_ITEM_REQ:
        {
            bmt_adc_remove_item_req_struct *parm_stream;
            parm_stream = (bmt_adc_remove_item_req_struct*) construct_local_para(sizeof(bmt_adc_remove_item_req_struct), TD_CTRL);
            parm_stream->adc_handle = (DCL_HANDLE)data;
            ilm_ptr->local_para_ptr = (local_para_struct*) parm_stream;
            break;
        }
        default:
            ASSERT(0);
    }
    SEND_ILM(MOD_L1SP, MOD_BMT, DRIVER_PS_SAP, ilm_ptr);
}

kal_bool AFE_Is_VIBR_Calibration()
{
	 afe.vib_cali_done = VIBR_NVRAM_DATA.VIBR_NVRAM_CALI_DONE;
	 return afe.vib_cali_done;
}

extern void Set_Vibr_Center_Freq(kal_uint16 vibr_center_freq);

kal_uint16 AFE_Vibrate_Calibration()
{
   #define vib_Channel  10
   
	 kal_uint16 CF     = AFE_VS_START_FREQ; 
	 kal_uint16 end_CF = AFE_VS_END_FREQ;
	 kal_uint16 vib_step   = AFE_VS_CALI_STEP;
	 kal_uint16 v_temp  = 0xFFFF;
	 kal_uint16 cf_temp = 0;
	  
	 DCL_HANDLE dcl_cursensor_handle;
   ADC_CTRL_CREATE_OBJECT_T  adc_measure_cf;
      
	 dcl_cursensor_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);	 
	 
	 Media_SetCalibrationType(MEDIA_CALI_VIB);
	 	          
   adc_measure_cf.u1OwnerId = MOD_MED;
   adc_measure_cf.u1AdcChannel = (DCL_UINT32)vib_Channel;
   adc_measure_cf.u4Period= 1;
   adc_measure_cf.u1EvaluateCount = 1;
   adc_measure_cf.fgSendPrimitive= KAL_TRUE;
   adc_measure_cf.u4Sapid= NULL;
   DclSADC_Control(dcl_cursensor_handle, ADC_CMD_CREATE_OBJECT, (DCL_CTRL_DATA_T *)&adc_measure_cf);  	 
	 
	 //Enable and init current sensor
	 *SPK_CON9 |= 0x9300;
	 *SPK_CON6 &= (~0x0800);	
	 
    VIBR_SetInitCoef(CF,0,0,KAL_FALSE);
    Media_SpkVibration_Enable_Cal(KAL_TRUE);
	 
	 for( ;CF<(end_CF+1); CF+=vib_step)
	 {
	 	  kal_int16 I = 0;
	 	  kal_uint16 I1=0;
	 	  afe.vib_cali_wait = KAL_TRUE;
	 	  
	 	  Set_Vibr_Center_Freq(CF);
	 	  
      kal_sleep_task(1);
      *SPK_CON6 |=0x800;
      kal_sleep_task(1); //wait at least 4.3ms
      *SPK_CON6 &= (~0x0800);       
      // auxadc read data.
      AFE_Adc_MsgSend(MSG_ID_BMT_ADC_ADD_ITEM_REQ, (void *)dcl_cursensor_handle);
      
      while(afe.vib_cali_wait == KAL_TRUE)
      {
		      kal_sleep_task(1);
		      I++;
		  }
		  //compare retrieve cf value: replace with min one
		  if (v_temp > afe.retrieved_cf_data)
		  {
		  	 v_temp  = afe.retrieved_cf_data;
		  	 cf_temp = CF;
		  }	
		   	
      AFE_Adc_MsgSend(MSG_ID_BMT_ADC_REMOVE_ITEM_REQ, (void *)dcl_cursensor_handle);     
	 }	 
	 //disable current sensor
	 *SPK_CON9 &= (~0x9300);
	 //center frequency of vib.
	 afe.cali_cf_data = cf_temp;
	 afe.vib_cali_done = KAL_TRUE;
	 VIBR_SetInitCoef(0,0,0,KAL_TRUE);
	 Media_SpkVibration_Enable_Cal(KAL_FALSE);
	 Media_SetCalibrationType(MEDIA_CALI_NONE);
	 return afe.cali_cf_data;
}


#endif //__AFE_CURRENT_SENSOR_ENABLE__

#endif //MT6260
