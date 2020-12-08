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
 *   i2s_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   I2S input mode interface
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "string.h"
#include "kal_trace.h"
#include "reg_base.h"

#include "l1audio.h"
#include "audio_def.h"
#include "speech_def.h"
#include "am.h"
#include "afe.h"
#include "media.h"
#include "ddload.h"
#include "l1sp_trc.h"
#include "blisrc_exp.h"

#if defined( __I2S_INPUT_MODE_SUPPORT__ )

extern void mp3_I2S_Record(kal_int32 Sample_Rate, void *hdl);
extern void amr_I2S_Record(mediaControl *ctrl, kal_uint32 *param, void *hdl);
extern void wav_I2S_Record(mediaControl *ctrl, kal_uint32 *param, void *hdl, kal_uint32 sample_rate);
extern const unsigned int Audio_Compensation_hsf_Coeffs_for_I2S[9][4];

#define I2S_ENC_BUFFER_LEN 8192  //in word //in mp3 should double
#define MaxTempBufSize     2048  //in word //equals to apm buffer size

#define PCMRUT_MASK       0x0080
#define PCMRUT_ON         0x0081

#define I2S_RECORD_STATE_CLOSED    0
#define I2S_RECORD_STATE_INIT      1
#define I2S_RECORD_STATE_READY     2 
#define I2S_RECORD_STATE_RECORDING 3

#if defined(__AUDIO_COMPONENT_SUPPORT__)
kal_uint16 i2s_sample_rate;
#endif

static struct{
   MHPB_Internal           *ihdl;
   mediaControl            *ctrl;
   void                    *pEncMem;
   void                    *pEnchdl;
   Audio_Encode_Interface  AEI;
   kal_uint16              state;
   kal_uint16              aud_id;
   kal_uint16              sample_rate;

   kal_uint16              encInBufSize;
   kal_uint16              encInBuf_w;
   kal_uint16              encInBuf_r;
   kal_int16               *encInBuf;

   kal_int16               *i2sInBuf;
   kal_uint32              i2sInBufDataLen;

   kal_uint8               odd_data;
   kal_uint8               add_on_data;
   kal_bool                odd_data_valid;
   kal_bool                is_resample;
   kal_bool                is_stereo2mono;
   kal_bool                flush_encoder;
   kal_bool                is_FM;
   kal_bool                is_ON;
   void*                   blisrc_handle;
   char*                   bli_workBufPtr;
   kal_uint64              uEncodeSamples;
   kal_uint16              uEncodeSampleRate;
#if defined(MT6250)
   kal_bool                fCheckEnable;
   kal_bool                fCheckReady;
   kal_bool                fCheckValid;
#endif
}i2s;

void I2SIN_TurnOnSpeaker()
{
   kal_trace( TRACE_FUNC, L1AUDIO_I2S_TURNON_SPK);
   AFE_TurnOnSpeaker(L1SP_AUDIO);
}

void I2SIN_TurnOffSpeaker()
{
   kal_trace( TRACE_FUNC, L1AUDIO_I2S_TURNOF_SPK);
   AFE_TurnOffSpeaker(L1SP_AUDIO);
}

void I2SIN_MuteSpeaker( kal_bool mute )
{
   kal_trace( TRACE_FUNC, L1AUDIO_I2S_MUTE_SPK, mute);
   Media_MuteSpeaker( mute );
}

void I2SIN_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index )
{
   kal_trace( TRACE_FUNC, L1AUDIO_I2S_SET_VOLUME, volume1, digital_gain_index);
   Media_SetOutputVolume( volume1, digital_gain_index );
}

void I2SIN_SetOutputDevice( kal_uint8 device )
{
   kal_trace( TRACE_FUNC, L1AUDIO_I2S_SET_DEVICE, device);
   Media_SetOutputDevice( device );
}

#if defined(MT6250)

#define I2S_ENABLE_CHECK 0x1
#define I2S_FINISH_CHECK 0x2
#define I2S_FAIL_MAGINNO 0x4444
#define I2S_CHECK_EXPIRED_TICK 100

kal_bool I2SIN_CheckDataValid()
{
   kal_uint32 uWaitTick=0;
   i2s.fCheckReady = KAL_FALSE;
   i2s.fCheckValid = KAL_FALSE;
   i2s.fCheckEnable = KAL_TRUE;
   if(i2s.is_FM && i2s.is_ON)
   {
      *I2S_PLAYERROR_INFO = 0;
      *I2S_PLAYERROR_CONTROL = I2S_ENABLE_CHECK;
      while(i2s.fCheckReady == KAL_FALSE)
      {
         kal_sleep_task(1);
         if(uWaitTick++ > I2S_CHECK_EXPIRED_TICK)
         {
            i2s.fCheckValid = KAL_TRUE;
         }
      }
   }
   i2s.fCheckEnable = KAL_FALSE;
   kal_trace( TRACE_FUNC, L1AUDIO_I2S_CHECK_VALID, i2s.is_FM, i2s.is_ON, i2s.fCheckValid, uWaitTick);
   return i2s.fCheckValid;
}

void I2SIN_MuteDSP( kal_bool fMute )
{
   kal_brief_trace( TRACE_FUNC, L1AUDIO_I2S_MUTE_DSP, fMute);
   PcmRut_MuteDSP(fMute);
}   

static void I2S_DspIntHISR( void *data )
{
   kal_bool fValid = KAL_FALSE;
   kal_uint16 uEnableCheck, uFinishCheck, uControl, uMagicNo;
   uMagicNo = *I2S_PLAYERROR_INFO;
   uControl = *I2S_PLAYERROR_CONTROL;
   uEnableCheck = uControl & I2S_ENABLE_CHECK;
   uFinishCheck = uControl & I2S_FINISH_CHECK;
   kal_dev_trace( TRACE_FUNC, L1AUDIO_I2S_INTERRUPT, uControl, uEnableCheck, uFinishCheck, uMagicNo);
   if(uFinishCheck && uEnableCheck)
   {
      if(uMagicNo == I2S_FAIL_MAGINNO)
      {
         fValid = KAL_FALSE;
      }
      else
      {
         fValid = KAL_TRUE;
      }
      i2s.fCheckReady = KAL_TRUE;
      i2s.fCheckValid = fValid;
   }
   if(i2s.fCheckEnable == KAL_FALSE || uFinishCheck )
   {
      *I2S_PLAYERROR_CONTROL &= ~(I2S_ENABLE_CHECK | I2S_FINISH_CHECK);
      *I2S_PLAYERROR_INFO = 0;
   }
}

#else

kal_bool I2SIN_CheckDataValid()
{
   return KAL_TRUE;
}

void I2SIN_MuteDSP( kal_bool fMute )
{

}

#endif

void I2S_init()
{
   i2s.state = I2S_RECORD_STATE_CLOSED;
#if defined(__BES_LOUDNESS_ON_I2S__)
   Media_SetBesLoudnessCustomCoeff_I2S( &Audio_Compensation_hsf_Coeffs_for_I2S[0][0] );
#endif
}

kal_bool I2S_is_I2S_open()
{
   if(I2S_RECORD_STATE_CLOSED==i2s.state)
      return KAL_FALSE;
   else 
      return KAL_TRUE;
}


kal_bool I2S_is_FM()
{
   return i2s.is_FM;
}

kal_bool I2S_is_On()
{
   return i2s.is_ON;
}

#ifdef __I2S_UNIT_TEST__
kal_uint16 Media_I2S_INPUT_MODE_SR_UT = 32000;
#endif

Media_Status I2S_Open( void ){
#ifdef __I2S_UNIT_TEST__
   kal_uint16 sr = Media_I2S_INPUT_MODE_SR_UT;
#else
   kal_uint16 sr = Media_I2S_INPUT_MODE_SR;
#endif

#if defined(MT6256) || defined(MT6255) || defined(MT6250) || defined(MT6260)
#if defined(__INTERAL_FM_VIA_I2S__)
   kal_uint8 isspkmute = 0;
#endif
#endif

#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   VIBR_Vibration_Deactivate();
#endif
   PcmSink_TerminateSound();

#if defined(__AUDIO_COMPONENT_SUPPORT__)
   Media_SetIsDSPDec(KAL_TRUE); // to bypass sink component
#endif
   kal_trace( TRACE_FUNC, L1AUDIO_I2S_ENABLE, ASP_TYPE_I2SBypass, sr );
   ASSERT( sr == 32000 || sr == 44100 || sr == 48000 );
   ASSERT( I2S_RECORD_STATE_CLOSED == i2s.state);
   i2s.is_ON = KAL_TRUE;
   i2s.state = I2S_RECORD_STATE_INIT;
   i2s.sample_rate = sr;
   i2s.aud_id  = L1Audio_GetAudioID();

#if defined(__BES_LOUDNESS_ON_I2S__)
   AudioPP_Loudness_Registry();
#endif
   
#if defined(__AUDIO_DSP_LOWPOWER_V2__)
   #if defined(MT6256) || defined(MT6255)
      if (!APM_IsLoudnessOn())
   #endif
   
   #if !(defined(MT6260) && defined(INTERNAL_ANTENNAL_SUPPORT))
      AUDLP_Mode(KAL_TRUE, 1);
   #endif
   
   if(AUDLP_Check_LowPower_Status())
   {
      L1Audio_SetFlag_MD2G( i2s.aud_id );
   #if defined(MT6250) || defined(MT6260)
      AUDLP_Set_ClkSwitchMode(KAL_TRUE);
      AUDLP_SW_Trigger_Event_Setting(KAL_TRUE);
      AUDLP_SetClkSwitch_26M(KAL_TRUE);
   #endif
   }
   else
      L1Audio_SetFlag( i2s.aud_id );
#else
   L1Audio_SetFlag( i2s.aud_id );
#endif
   ktLock();
   
   KT_StopAndWait();
   TONE_StopAndWait();
   AM_Force_VBI_END_IN_TASK();

   Media_SetSampleRate(sr);  
   Media_SetAudioFormat(MEDIA_FORMAT_UNKNOWN); 

   *DSP_AUDIO_CTRL2 |= DP_PCM_R_DIS;
   *DSP_AUDIO_FLEXI_CTRL |= (FLEXI_VBI_ENABLE | FLEXI_SD_ENABLE);
#if defined(MT6250) || defined(MT6260)   
   *I2S_PLAYERROR_INFO = 0;
   *I2S_PLAYERROR_CONTROL = 0;
#endif   
#if !defined(__CACHED_BASE_DSP__)
   DSP_DynamicDownload ( DDID_I2S );
#endif
   
   //should add a parameter to indicate input or output
   AFE_TurnOnEDI( 1, 1, L1SP_I2S_INPUT_SCALE >> 1 );
   
#if defined(__AUDIO_COMPONENT_SUPPORT__)
   i2s_sample_rate = i2s.sample_rate;
   ASSERT(i2s.ihdl==NULL);
   AudioRoute2Drain_Init(&i2s.ihdl, 0);
   AudioRoute2Drain_Start(i2s.ihdl);
#endif 
   
   //should not turn on output mode and input mode at the same time
   if( sr == 32000 )
      sr = ASP_FS_32K;
   else if ( sr == 44100 )
      sr = ASP_FS_44K;
   else
      sr = ASP_FS_48K;
      
#if defined(MT6260)
#if defined(__INTERAL_FM_VIA_I2S__)
   if(I2S_is_FM())
#endif
    *HW_MISC_REG |=0x0001;
#endif        
      
#if defined(__INTERAL_FM_VIA_I2S__)
   if(!I2S_is_FM())
#endif
      I2S_Input_GPIO_TurnOn();

#if defined(MT6256) || defined(MT6255) || defined(MT6250) || defined(MT6260)
#if defined(__INTERAL_FM_VIA_I2S__)
   if(!I2S_is_FM())
   {
      if(!AFE_IsSpeakerMuted())
      {
         AFE_MuteSpeaker(L1SP_AUDIO, KAL_TRUE);
         isspkmute = 1;
      }
   }
#endif
#endif

#if defined(MT6250)
   L1Audio_HookHisrHandler(DP_D2C_I2S_REC_INT, I2S_DspIntHISR, 0);
#endif

#if defined(__AUDIO_COMPONENT_SUPPORT__) && !defined(MED_MODEM)
   PcmSink_DepopMute(400); //depop
#endif
   AM_AudioPlaybackOn( ASP_TYPE_I2SBypass, sr );

#if defined(MT6256) || defined(MT6255) || defined(MT6250) || defined(MT6260)
#if defined(__INTERAL_FM_VIA_I2S__)
   if(!I2S_is_FM())
   {
      kal_sleep_task(45);
      if(isspkmute)
         AFE_MuteSpeaker(L1SP_AUDIO, KAL_FALSE);
   }
#endif
#endif

   return MEDIA_SUCCESS;
}

Media_Status I2S_Close( void ){
   kal_trace( TRACE_FUNC, L1AUDIO_I2S_DISABLE);
#if !defined(__AUDIO_RECORD_COMPONENT_SUPPORT__)
   ASSERT(I2S_RECORD_STATE_INIT == i2s.state);
#endif
   i2s.state = I2S_RECORD_STATE_CLOSED;
   AM_AudioPlaybackOff( true );
   
   AFE_TurnOffEDI();
#if defined(__INTERAL_FM_VIA_I2S__)
   if(!I2S_is_FM())
#endif
      I2S_Input_GPIO_TurnOff();
      
#if defined(MT6260)
#if defined(__INTERAL_FM_VIA_I2S__)
   if(I2S_is_FM())
#endif
   *HW_MISC_REG &= ~0x0001;
#endif     
  
   *DSP_AUDIO_FLEXI_CTRL &= ~(FLEXI_VBI_ENABLE | FLEXI_SD_ENABLE);
   *DSP_AUDIO_CTRL2 &= ~DP_PCM_R_DIS;
   /*  GPIO setting */

#if defined(__AUDIO_COMPONENT_SUPPORT__)
   ASSERT(i2s.ihdl);
   Media_SetIsDSPDec(KAL_FALSE); // to bypass sink component
   AudioRoute2Drain_Stop(i2s.ihdl);
   AudioRoute2Drain_Free(i2s.ihdl);
   i2s.ihdl = NULL;
#endif   

#if defined(__BES_LOUDNESS_ON_I2S__)
   AudioPP_Loudness_Registry();
#endif

#if defined(MT6250)
   L1Audio_UnhookHisrHandler( DP_D2C_I2S_REC_INT );
#endif

#if defined(__AUDIO_DSP_LOWPOWER_V2__)
   if(AUDLP_Check_LowPower_Status())
   {
   #if defined(MT6250) || defined(MT6260)
      AUDLP_SetClkSwitch_26M(KAL_FALSE);
      AUDLP_SW_Trigger_Event_Setting(KAL_FALSE);
      AUDLP_Set_ClkSwitchMode(KAL_FALSE);
   #endif
      AUDLP_Mode(KAL_FALSE, 1);
      L1Audio_ClearFlag_MD2G( i2s.aud_id );
   }
   else
      L1Audio_ClearFlag( i2s.aud_id );
#else
   L1Audio_ClearFlag( i2s.aud_id );
#endif

   L1Audio_FreeAudioID( i2s.aud_id );
   i2s.is_ON = KAL_FALSE;
   ktUnlock();
   return MEDIA_SUCCESS;
}

Media_Status FM_I2S_Open(void)
{
   i2s.is_FM = KAL_TRUE;
   I2S_Open();
#if I2S_FILTER_SUPPORT
   *I2S_HPF_CTRL = 0x8000;
#endif   
   return MEDIA_SUCCESS;
}

Media_Status FM_I2S_Close(void)
{
#if I2S_FILTER_SUPPORT
   *I2S_HPF_CTRL = 0;
#endif  
   I2S_Close();
   i2s.is_FM = KAL_FALSE;
   return MEDIA_SUCCESS;
}

static void I2S_RecordOn()
{
   kal_uint32 I=0;
   i2s.state = I2S_RECORD_STATE_RECORDING;
   i2s.flush_encoder = false;
   kal_trace( TRACE_FUNC, L1AUDIO_I2S_REC_ON );
#if !defined(__AUDIO_RECORD_COMPONENT_SUPPORT__)
   HOST_APM_Register(APM_TASKID_I2S_RECORD);
   while(i2s.pEnchdl == NULL)
   {
      kal_sleep_task(1);
      I++;
      ASSERT(I<80); 
   }
#endif
}


static void I2S_RecordOff()
{
   kal_uint32 I=0;
   i2s.state = I2S_RECORD_STATE_READY;
   kal_sleep_task(9);  //flush the last frame //(1152*1000)/(32000*4.615)=
   kal_trace( TRACE_FUNC, L1AUDIO_I2S_REC_OFF );
#if !defined(__AUDIO_RECORD_COMPONENT_SUPPORT__)
   HOST_APM_UnRegister(APM_TASKID_I2S_RECORD);
   while(i2s.pEnchdl != NULL)
   {
      kal_sleep_task(1);
      I++;
      ASSERT(I<80);	
   }   
#endif
}

static kal_uint32 I2S_PCM_Stereo2mono(kal_int16 *inBuf, kal_uint32 inBufWordLen, kal_int16 *outBuf, kal_uint32 outBufWordLen){
   kal_uint32 cnt;
   kal_int32 i;
   if((inBufWordLen>>1) > outBufWordLen ){
      cnt = outBufWordLen;
   }
   else{
      cnt = inBufWordLen>>1;
   }
   for( i = cnt-1 ; i >= 0 ; i--){
      kal_int16 temp_data = *inBuf++;
      *outBuf++ = (temp_data + *inBuf++)>>1;
   }
   
   return cnt; //return the output length
}

static kal_uint32 I2S_BLISRC_Init(){
   kal_uint32 workBufSize;
   ASSERT(i2s.blisrc_handle == NULL);
   BLI_GetMemSize(i2s.sample_rate, 2, 8000, 1, &workBufSize);
   i2s.bli_workBufPtr = (char *)audio_alloc_mem_cacheable( workBufSize * sizeof(kal_int8) );
   ASSERT(i2s.bli_workBufPtr != NULL);
   i2s.blisrc_handle = BLI_Open(i2s.sample_rate, 2, 8000, 1, i2s.bli_workBufPtr, audio_alloc_ext_mem_cacheable_simplified);
   return ((workBufSize+ 3) & ~0x3);
}


static void I2S_BLISRC_Free(){
   ASSERT(i2s.blisrc_handle);
   BLI_Close(i2s.blisrc_handle, audio_free_ext_mem_simplified);
   i2s.blisrc_handle = NULL;
   audio_free_mem( (void **) &i2s.bli_workBufPtr );
   i2s.bli_workBufPtr = NULL;
}

void I2S_Record_Init(APM_TCM *tcm)
{
}

void I2S_Record_Activate(APM_Info *info)
{
   kal_uint32 encMemSize = 0;
   kal_uint32 bliMemSize = 0;
   kal_uint32 enc_buffer_len = I2S_ENC_BUFFER_LEN;


   encMemSize = i2s.AEI.GetMemSize();

   i2s.pEncMem = (void*)audio_alloc_mem_cacheable( encMemSize * sizeof(kal_int8) );
   if(encMemSize)
   {
     ASSERT(i2s.pEncMem != NULL);
   }
   kal_trace( TRACE_FUNC, L1AUDIO_I2S_REC_ACTIVATE, 0, encMemSize );

   i2s.pEnchdl = i2s.AEI.Init( i2s.pEncMem );
   if(!i2s.encInBuf) 
   {
      i2s.encInBuf = (kal_int16*)audio_alloc_mem( enc_buffer_len * sizeof(kal_int16) );
      ASSERT(i2s.encInBuf != NULL);
      i2s.encInBufSize = enc_buffer_len;
      i2s.encInBuf_r = 0;
      i2s.encInBuf_w = 0;
   }
}

void I2S_Record_Deactivate(void){

   i2s.AEI.Free( &i2s.pEnchdl );

   audio_free_mem( (void **) &i2s.pEncMem );

   i2s.pEncMem = NULL;
   i2s.pEnchdl = NULL;

   if(i2s.encInBuf){
      audio_free_mem( (void **) &i2s.encInBuf );
      i2s.encInBuf = 0;
      i2s.encInBuf_r = 0;
      i2s.encInBuf_w = 0;
   }
   kal_trace( TRACE_FUNC, L1AUDIO_I2S_REC_DEACTIVATE );
   
}

kal_bool I2S_Record_Process(APM_Buffer *buf, APM_Info *info)
{ //This function works in L1Audio Task  
   kal_uint32 encInBufFreeSpace;  //in word
   kal_uint32 apmInBufDataCnt;    //in word
   kal_uint32 encOutBufFreeSpace; //in word
   kal_uint32 encOutBufDataBytes; //in byte
   kal_uint32 segment;            //in byte
   kal_uint8  *encOutBufPtr;
   kal_uint8  *RingBufPtr;

   encInBufFreeSpace = i2s.encInBufSize - i2s.encInBuf_w;
   apmInBufDataCnt = buf->inBufLen;

   apmInBufDataCnt &= 0xFFFFFFE;   
   kal_trace( TRACE_FUNC, L1AUDIO_I2S_REC_PROCESS, apmInBufDataCnt, encInBufFreeSpace);
   if(i2s.is_stereo2mono)   //stereo2mono convert
   {
      buf->inBufLen   = I2S_PCM_Stereo2mono(buf->inBuf, apmInBufDataCnt, i2s.encInBuf + i2s.encInBuf_w, encInBufFreeSpace)<<1;
      i2s.encInBuf_w += buf->inBufLen>>1 ; 
   }    
   else if(i2s.is_resample) //resample contains stereo2mono conversion
   {  
      ASSERT(i2s.blisrc_handle);
      encInBufFreeSpace = encInBufFreeSpace << 1; //convert to byte
      apmInBufDataCnt   = apmInBufDataCnt << 1; //convert to byte
      buf->inBufLen = BLI_Convert(i2s.blisrc_handle, buf->inBuf, &apmInBufDataCnt, i2s.encInBuf + i2s.encInBuf_w, &encInBufFreeSpace) >> 1;
      i2s.encInBuf_w += encInBufFreeSpace >> 1;
   }
   else
   {
      kal_uint32 cnt; 
      if(encInBufFreeSpace > apmInBufDataCnt)
         cnt = apmInBufDataCnt;
      else
         cnt = encInBufFreeSpace;
      memcpy(i2s.encInBuf + i2s.encInBuf_w, buf->inBuf, cnt*sizeof(int16));
      buf->inBufLen   = cnt;
      i2s.encInBuf_w += cnt;   
   }
   //Media_IncRecordedTime( buf->inBufLen*500/i2s.sample_rate);
   //output buffer size
   encOutBufFreeSpace = mediaGetFreeSpace()-1;
   if(encOutBufFreeSpace > MaxTempBufSize )
      encOutBufFreeSpace = MaxTempBufSize;

   //encoding
   encOutBufDataBytes = encOutBufFreeSpace<<1;
   //kal_prompt_trace(MOD_L1SP,"[i2s]enc_in, enc_data_in_16: %d, in_space_8: %d, flush: %d", i2s.encInBuf_w, encOutBufDataBytes, i2s.flush_encoder);
   i2s.encInBuf_r = i2s.AEI.Process( i2s.pEnchdl, i2s.encInBuf, i2s.encInBuf_w, (kal_uint8 *)buf->outBuf, &encOutBufDataBytes, i2s.flush_encoder); 
   if(i2s.is_stereo2mono || i2s.is_resample)
   {
      i2s.uEncodeSamples += i2s.encInBuf_r;
   }
   else
   {
      i2s.uEncodeSamples += i2s.encInBuf_r >> 1;
   }
   kal_trace( TRACE_FUNC, L1AUDIO_I2S_REC_ENCODED, i2s.encInBuf_r, encOutBufDataBytes, i2s.flush_encoder);
   Media_SetRecordedTime( i2s.uEncodeSamples*1000/i2s.uEncodeSampleRate );
   //move to residual input data to linear buffer head
   ASSERT(i2s.encInBuf_w >= i2s.encInBuf_r);
   if(i2s.encInBuf_w - i2s.encInBuf_r)
      memcpy(i2s.encInBuf, i2s.encInBuf + i2s.encInBuf_r, (i2s.encInBuf_w - i2s.encInBuf_r)*sizeof(int16));
   i2s.encInBuf_w = i2s.encInBuf_w - i2s.encInBuf_r;
   i2s.encInBuf_r = 0;

   //no output data. 
   if(!encOutBufDataBytes)
      return true;

   //media buffer should always enough
   if( mediaGetFreeSpace()-1 < encOutBufDataBytes>>1)
   {
      kal_trace( TRACE_WARNING, L1AUDIO_I2S_REC_REC_OF, mediaGetFreeSpace()-1, encOutBufDataBytes>>1 );
      return true;
   }

   encOutBufPtr = (kal_uint8 *)buf->outBuf;
   if(i2s.odd_data_valid)
   {
      Media_GetWriteBuffer((kal_uint16**)&RingBufPtr, &segment);
      *RingBufPtr++ = i2s.odd_data;
      *RingBufPtr++ = *encOutBufPtr++;
      encOutBufDataBytes--;
      Media_WriteDataDone_NoWaiting(1);
      i2s.odd_data_valid = false;
   }

   Media_GetWriteBuffer((kal_uint16**)&RingBufPtr, &segment);
   if(encOutBufDataBytes>>1 < segment)
      segment = encOutBufDataBytes>>1;
   memcpy((kal_uint8*)RingBufPtr, encOutBufPtr, segment * sizeof(kal_int16));
   Media_WriteDataDone_NoWaiting(segment);
   encOutBufPtr += segment<<1;
   encOutBufDataBytes -= segment<<1;
   if(encOutBufDataBytes>>1)
   {
      Media_GetWriteBuffer((kal_uint16**)&RingBufPtr, &segment);     
      segment = encOutBufDataBytes>>1;
      memcpy((kal_uint8*)RingBufPtr, encOutBufPtr, segment * sizeof(kal_int16));
      Media_WriteDataDone_NoWaiting(segment);
      encOutBufPtr += segment<<1;
      encOutBufDataBytes -= segment<<1;
   }
   
   //if the output bitstream is not word align, keep the last byte odd_data  
   if(encOutBufDataBytes==1)
   {
      i2s.odd_data_valid = true;
      i2s.odd_data = *encOutBufPtr;
      i2s.ctrl->write += (encOutBufDataBytes>>1);
   }
   else
   {
      ASSERT(0==encOutBufDataBytes);
   }
   mediaDataNotification();
   return true;
}

kal_uint32 I2S_GetInputSamplingRate()
{
   ASSERT(I2S_RECORD_STATE_CLOSED!=i2s.state);
   return i2s.sample_rate;
}


void I2S_Record_Resume(mediaControl *ctrl)
{
   (void) ctrl;
   ASSERT(I2S_RECORD_STATE_READY==i2s.state);
   I2S_RecordOn();
}


void I2S_Record_Pause(mediaControl *ctrl)
{   
   (void) ctrl;
   if(I2S_RECORD_STATE_READY==i2s.state)
   {
      return;
   }
   ASSERT(I2S_RECORD_STATE_RECORDING==i2s.state);
   I2S_RecordOff();
   if(i2s.odd_data_valid)  //flush the last odd byte if exist
   {
      *(i2s.ctrl->rb_base + i2s.ctrl->write) = (i2s.add_on_data << 8) || i2s.odd_data;
      i2s.odd_data_valid = false;
      mediaDataNotification();
   }
}

void I2S_Record_Stop(mediaControl *ctrl)
{
   mediaSetWaitingFlag(KAL_FALSE);
   i2s.flush_encoder = true;
   I2S_Record_Pause(ctrl);
   i2s.state = I2S_RECORD_STATE_INIT;
   i2s.AEI.Free       = NULL;
   i2s.AEI.GetMemSize = NULL;
   i2s.AEI.Init       = NULL;
   i2s.AEI.Process    = NULL;

   if(i2s.AEI.Close)
   {
      i2s.AEI.Close(i2s.pEnchdl);
   }
   
   mediaSetWaitingFlag(KAL_FALSE);
   ctrl->is_I2S_input = false;
   if(i2s.is_resample)
      I2S_BLISRC_Free();
}


Media_Status I2S_Record_Start( mediaControl *ctrl, void *param )
{
   i2s.add_on_data = 0;
   i2s.ctrl = ctrl;
   i2s.flush_encoder = false;
   ASSERT(I2S_RECORD_STATE_INIT==i2s.state);
   i2s.state = I2S_RECORD_STATE_READY;
   i2s.is_resample = false;
   i2s.is_stereo2mono = false;
   i2s.uEncodeSamples = 0;
   i2s.uEncodeSampleRate = i2s.sample_rate;
   
   i2s.AEI.Close = NULL;
   i2s.AEI.Free = NULL;
   i2s.AEI.GetMemSize = NULL;
   i2s.AEI.Process = NULL;
   i2s.AEI.Init = NULL;

   switch(ctrl->format) 
   {
#if defined(__I2S_DAF_RECORD__)
      case MEDIA_FORMAT_DAF:
         mp3_I2S_Record((kal_int32)i2s.sample_rate, &i2s.AEI);
         break;
#endif
#if defined(__I2S_WAV_RECORD__)
      case MEDIA_FORMAT_WAV_DVI_ADPCM:
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
      case MEDIA_FORMAT_WAV:
#if !defined(__I2S_UNIT_TEST__)
         i2s.is_stereo2mono = true;
#endif
         wav_I2S_Record( ctrl, param, &i2s.AEI, i2s.sample_rate);
         break;
      case MEDIA_FORMAT_PCM_8K:
         i2s.is_resample = true;      
         I2S_BLISRC_Init();		 
         i2s.uEncodeSampleRate = 8000;
         wav_I2S_Record( ctrl, param, &i2s.AEI, i2s.sample_rate);
         break;
#endif
#if defined(__I2S_AMR_RECORD__)
      case MEDIA_FORMAT_AMR:
         i2s.is_resample = true;
         I2S_BLISRC_Init();
         i2s.add_on_data = 0x7C;
         i2s.uEncodeSampleRate = 8000;
         amr_I2S_Record( ctrl, param, &i2s.AEI);
         break;
#endif
#if defined(__I2S_VORBIS_RECORD__)
      case MEDIA_FORMAT_VORBIS:
         i2s.is_resample = KAL_FALSE;
         vorbis_I2S_Record( ctrl, param, &i2s.AEI, i2s.sample_rate, i2s.is_stereo2mono);
         break;
#endif
      default:
         return MEDIA_UNSUPPORTED_TYPE;
   }
   I2S_RecordOn();
   return MEDIA_SUCCESS;
}

#endif //__I2S_INPUT_MODE_SUPPORT__

