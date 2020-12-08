# Define source file folder to SRC_LIST
ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
   AUDFOLDER         =  hal\audio\src\v2
   AUD_SOLUTION      =  V2
else   
   ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
      AUDFOLDER         =  hal\audio\src\v1\sp
      AUD_SOLUTION      =  V1_SP
   else 
      AUDFOLDER         =  hal\audio\src\v1
      AUD_SOLUTION      =  V1
   endif
endif


# Start Define source file lists to SRC_LIST
# Common part in v1, v2 and v1SP
SRC_LIST = $(strip $(AUDFOLDER))\am.c \
           $(strip $(AUDFOLDER))\sp_drv.c \
           $(strip $(AUDFOLDER))\tone_drv.c \
           $(strip $(AUDFOLDER))\tone_debug.c \
           $(strip $(AUDFOLDER))\dtmf_drv.c \
           $(strip $(AUDFOLDER))\media.c \
           $(strip $(AUDFOLDER))\l1audio_trace.c \
           $(strip $(AUDFOLDER))\pcm4way.c \
           $(strip $(AUDFOLDER))\audio_service.c \
           $(strip $(AUDFOLDER))\wav_codec.c \
           $(strip $(AUDFOLDER))\wav.c \
           $(strip $(AUDFOLDER))\dpmgr.c \
           $(strip $(AUDFOLDER))\l1audio_sph_srv.c \
           interface\hal\audio\audio_create.c

ifneq ($(filter __MCU_DTMF_SUPPORT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST +=  $(strip $(AUDFOLDER))\PcmMixer.c
endif

ifneq ($(filter __AUDIO_RECORD_COMPONENT_SUPPORT__, $(strip $(MODULE_DEFS))),)
   ifneq ($(filter WAV_CODEC, $(strip $(MODULE_DEFS))),)
      SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\pcm_comp_rec.c
      SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\wav_comp_rec.c
   endif
   ifneq ($(filter AMR_CODEC, $(strip $(MODULE_DEFS))),)
      SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\amr_comp_rec.c
   endif
   ifneq ($(filter __VORBIS_ENCODE__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\vorbis_comp_rec.c
   endif
   ifneq ($(filter __VM_CODEC_SUPPORT__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\vm_comp_rec.c
   endif
endif

AFE_SPLIT_DRIVER_PLATFORM  = MT6251 MT6255 MT6256 MT6250 MT6922 MT6260
ifneq ($(filter $(strip $(MODULE_DEFS)), $(AFE_SPLIT_DRIVER_PLATFORM)),)
   SRC_LIST +=  $(strip $(AUDFOLDER))\afe_common.c
   ifeq ($(strip $(PLATFORM)),MT6260)
     SRC_LIST += $(strip $(AUDFOLDER))\afes\afe_6260.c
   endif
   ifeq ($(strip $(PLATFORM)),MT6250)
     SRC_LIST += $(strip $(AUDFOLDER))\afes\afe_6250.c
   endif
   ifeq ($(strip $(PLATFORM)),MT6255)
     SRC_LIST += $(strip $(AUDFOLDER))\afes\afe_6255.c
   endif
   ifeq ($(strip $(PLATFORM)),MT6922)
     SRC_LIST += $(strip $(AUDFOLDER))\afes\afe_6255.c
   endif
   ifeq ($(strip $(PLATFORM)),MT6256)
     SRC_LIST += $(strip $(AUDFOLDER))\afes\afe_6256.c
   endif
else
   SRC_LIST +=  $(strip $(AUDFOLDER))\afe2.c
endif
 


ifneq ($(filter __VM_CODEC_SUPPORT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST +=  $(strip $(AUDFOLDER))\vm.c
endif

ifneq ($(filter __CVSD_CODEC_SUPPORT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST +=  $(strip $(AUDFOLDER))\bt_sco_drv.c
   SRC_LIST +=  $(strip $(AUDFOLDER))\bt_sco_app.c
endif

# Common part in V1_SP
ifeq ($(strip $(AUD_SOLUTION)),V1_SP)
   SRC_LIST += $(strip $(AUDFOLDER))\vm_strm_drv.c \
               $(strip $(AUDFOLDER))\bgsnd_drv.c \
               $(strip $(AUDFOLDER))\sp_enhance.c \
               $(strip $(AUDFOLDER))\wav_thumb.c
else
# Common part in V1 and V2
   SRC_LIST += $(strip $(AUDFOLDER))\audioPP.c \
               $(strip $(AUDFOLDER))\tone_loopback_rec.c \
               $(strip $(AUDFOLDER))\audioCF.c

ifneq ($(filter __VM_CODEC_SUPPORT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST +=  $(strip $(AUDFOLDER))\vm_drv.c
endif

ifneq ($(filter __SPECTRUM_DISPLAY_SUPPORT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST +=  $(strip $(AUDFOLDER))\spt_analyzer.c
endif

ifneq ($(filter __VIBRATION_SPEAKER_SUPPORT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST +=  $(strip $(AUDFOLDER))\vibration_drv.c
   SRC_LIST +=  $(strip $(AUDFOLDER))\vibration_rom.c
endif

   ifeq ($(strip $(AUD_SOLUTION)),V1)
      SRC_LIST += $(strip $(AUDFOLDER))\audio_idma.c \
                  $(strip $(AUDFOLDER))\spe_custom_drv.c \
                  $(strip $(AUDFOLDER))\sp_enhance.c

      ifneq ($(filter __DRA_DECODE_SUPPORT__, $(strip $(MODULE_DEFS))),)
        ifeq ($(filter __AUDIO_COMPONENT_SUPPORT__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += $(strip $(AUDFOLDER))\dra_drv.c
        endif
      endif
      
      ifneq ($(filter __DUAL_TALK_MODEM_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += $(strip $(AUDFOLDER))\spc_drv.c
        SRC_LIST += $(strip $(AUDFOLDER))\pcm_rec.c
        SRC_LIST += $(strip $(AUDFOLDER))\audl_service.c
        SRC_LIST += $(strip $(AUDFOLDER))\sp_strm_drv.c
      endif      
      
   endif
   
   ifeq ($(strip $(AUD_SOLUTION)),V2)
      ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
         SRC_LIST += $(strip $(AUDFOLDER))\audl_service.c \
                     $(strip $(AUDFOLDER))\spc_drv.c
      endif
      SRC_LIST += $(strip $(AUDFOLDER))\ut_acoustic_loopback.c
      ifneq ($(filter DSP_WT_SYN, $(strip $(MODULE_DEFS))),)
         SRC_LIST += $(strip $(AUDFOLDER))\Wavetable_SW.c
      endif
      ifneq ($(filter __DATA_CARD_SPEECH__, $(strip $(MODULE_DEFS))),)
         SRC_LIST += $(strip $(AUDFOLDER))\audl_service.c \
                     $(strip $(AUDFOLDER))\sp_strm_drv.c
      endif
   endif
   ifneq ($(filter __AUDIO_COMPONENT_SUPPORT__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += $(strip $(AUDFOLDER))\Wavetable_SW.c
   endif
endif

ifneq ($(filter __UMTS_RAT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST += $(strip $(AUDFOLDER))\amr_table.c \
               $(strip $(AUDFOLDER))\sp_3g.c
else
  ifneq ($(filter __UMTS_TDD128_MODE__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += $(strip $(AUDFOLDER))\amr_table.c \
                $(strip $(AUDFOLDER))\sp_3g.c
  endif
endif

ifneq ($(filter BGSND_ENABLE, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\snd_effect.c
endif
ifneq ($(filter WAV_CODEC, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\wav_thumb.c
  SRC_LIST += $(strip $(AUDFOLDER))\pcm_strm_drv.c
  WAV_DRIVER_NOT_SUPPORT_PLATFORM = MT6516 MT6573
  ifeq ($(filter $(strip $(MODULE_DEFS)) ,$(WAV_DRIVER_NOT_SUPPORT_PLATFORM)),)
    ifeq ($(strip $(AUD_SOLUTION)),V2)
       SRC_LIST += $(strip $(AUDFOLDER))\wav_drv.c
    else
       ifneq ($(filter __AUDIO_COMPONENT_SUPPORT__, $(strip $(MODULE_DEFS))),)
          SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\wav_comp_drv.c
       else
          SRC_LIST += $(strip $(AUDFOLDER))\wav_drv.c
       endif
    endif     
  endif
  ifneq ($(strip $(AUD_SOLUTION)),V2)
    SRC_LIST += $(strip $(AUDFOLDER))\pcm.c
  endif
endif

ifneq ($(filter __CTM_SUPPORT__, $(strip $(MODULE_DEFS))),)
     SRC_LIST += $(strip $(AUDFOLDER))\ctm_drv.c
endif

ifneq ($(filter __ECALL_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))\eCall_drv.c
endif

ifeq ($(strip $(SMART_PHONE_CORE)),NONE)
   ifneq ($(filter AAC_DECODE, $(strip $(MODULE_DEFS))),)
     ifeq ($(strip $(AUD_SOLUTION)),V2)
       SRC_LIST += $(strip $(AUDFOLDER))\aac_drv.c
     else
       ifneq ($(filter __AUDIO_COMPONENT_SUPPORT__, $(strip $(MODULE_DEFS))),)
          SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\aac_comp_drv.c
       else
          SRC_LIST += $(strip $(AUDFOLDER))\aac_drv.c
       endif
     endif
   endif
   ifneq ($(filter AAC_PLUS_DECODE, $(strip $(MODULE_DEFS))),)
     ifeq ($(strip $(AUD_SOLUTION)),V1)
       SRC_LIST += $(strip $(AUDFOLDER))\aac_huffman_table.c
     endif
   endif
   ifneq ($(filter AMR_CODEC, $(strip $(MODULE_DEFS))),)
     SRC_LIST += $(strip $(AUDFOLDER))\amr.c \
                 $(strip $(AUDFOLDER))\amr_table.c
     ifeq ($(strip $(AUD_SOLUTION)),V2)
       SRC_LIST += $(strip $(AUDFOLDER))\amr_drv.c
     else
       ifneq ($(filter __AUDIO_COMPONENT_SUPPORT__, $(strip $(MODULE_DEFS))),)
          SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\amr_comp_drv.c
       else
          SRC_LIST += $(strip $(AUDFOLDER))\amr_drv.c
       endif
     endif
     ifneq ($(filter DEDI_AMR_REC, $(strip $(MODULE_DEFS))),)
       ifeq ($(strip $(AUD_SOLUTION)),V1)
           SRC_LIST += $(strip $(AUDFOLDER))\amr_dedi.c
       endif
     endif
   endif
   ifneq ($(filter AMRWB_ENCODE, $(strip $(MODULE_DEFS))),)
     AWB_SW_ENC_SUPPORT_PLATFORM = MT6255 MT6922
     ifneq ($(filter $(strip $(MODULE_DEFS)), $(AWB_SW_ENC_SUPPORT_PLATFORM)),)
       SRC_LIST += $(strip $(AUDFOLDER))\awb_enc.c
     endif
   endif
   ifneq ($(filter __APE_DECODE__, $(strip $(MODULE_DEFS))),)
     ifeq ($(strip $(AUD_SOLUTION)),V2)
       SRC_LIST += $(strip $(AUDFOLDER))\ape_drv.c
     else
       ifneq ($(filter __AUDIO_COMPONENT_SUPPORT__, $(strip $(MODULE_DEFS))),)
          SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\ape_comp_drv.c
       else
          SRC_LIST += $(strip $(AUDFOLDER))\ape_drv.c
       endif
     endif
   endif
   ifneq ($(filter __VORBIS_DECODE__, $(strip $(MODULE_DEFS))),)
     ifeq ($(strip $(AUD_SOLUTION)),V2)
       SRC_LIST += $(strip $(AUDFOLDER))\vorbis_drv.c
       SRC_LIST += $(strip $(AUDFOLDER))\vorbis_strm_drv.c
     else
       ifneq ($(filter __AUDIO_COMPONENT_SUPPORT__, $(strip $(MODULE_DEFS))),)
          SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\vorbis_comp_drv.c
          SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\vorbis_strm_comp_drv.c
       else
          SRC_LIST += $(strip $(AUDFOLDER))\vorbis_drv.c
          SRC_LIST += $(strip $(AUDFOLDER))\vorbis_strm_drv.c
       endif
     endif
   endif
   ifneq ($(filter __VORBIS_ENCODE__, $(strip $(MODULE_DEFS))),)
     SRC_LIST += $(strip $(AUDFOLDER))\vorbis_enc_drv.c
   endif
   ifneq ($(filter __AUDIO_DSP_LOWPOWER_V2__, $(strip $(MODULE_DEFS))),)
     SRC_LIST += $(strip $(AUDFOLDER))\audlp2_drv.c
   endif
   ifneq ($(filter __ENABLE_AUDIO_DVT__, $(strip $(MODULE_DEFS))),)
     SRC_LIST += $(strip $(AUDFOLDER))\audio_DVT.c
   endif
   ifneq ($(filter __BT_AUDIO_VIA_SCO__, $(strip $(MODULE_DEFS))),)
     ifeq ($(strip $(AUD_SOLUTION)),V1)
       SRC_LIST += $(strip $(AUDFOLDER))\avb_drv.c
     endif
   endif
   ifneq ($(filter __COOK_DECODE__, $(strip $(MODULE_DEFS))),)
     ifeq ($(filter __COOK_DECODE_DSP__, $(strip $(MODULE_DEFS))),)     
        ifeq ($(strip $(AUD_SOLUTION)),V2)
          SRC_LIST += $(strip $(AUDFOLDER))\cook_drv.c
        else
          ifneq ($(filter __AUDIO_COMPONENT_SUPPORT__, $(strip $(MODULE_DEFS))),)
             SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\cook_comp_drv.c
          else
             SRC_LIST += $(strip $(AUDFOLDER))\cook_drv.c
          endif
        endif
     endif
   endif
   ifneq ($(filter __COOK_DECODE__, $(strip $(MODULE_DEFS))),)
     ifneq ($(filter __COOK_DECODE_DSP__, $(strip $(MODULE_DEFS))),)
       SRC_LIST += $(strip $(AUDFOLDER))\ra_drv.c
     endif
   endif
   ifneq ($(filter DAF_DECODE, $(strip $(MODULE_DEFS))),)
     ifeq ($(strip $(AUD_SOLUTION)),V2)
       SRC_LIST += $(strip $(AUDFOLDER))\daf_drv.c
     else
       ifneq ($(filter __AUDIO_COMPONENT_SUPPORT__, $(strip $(MODULE_DEFS))),)
          SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\daf_comp_drv.c
       else
          SRC_LIST += $(strip $(AUDFOLDER))\daf_drv.c
       endif
     endif
   endif
   ifneq ($(filter __FLAC_DECODE__ , $(strip $(MODULE_DEFS))),)
       ifneq ($(filter __AUDIO_COMPONENT_SUPPORT__, $(strip $(MODULE_DEFS))),)
          SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\flac_comp_drv.c
       endif
   endif
   ifneq ($(filter __BES_EQ_SUPPORT__, $(strip $(MODULE_DEFS))),)
     ifeq ($(strip $(AUD_SOLUTION)),V1)
       SRC_LIST += $(strip $(AUDFOLDER))\eq_table.c
     endif
   endif
   ifneq ($(filter __I2S_INPUT_MODE_SUPPORT__, $(strip $(MODULE_DEFS))),)
     SRC_LIST += $(strip $(AUDFOLDER))\i2s_drv.c
   endif
   ifneq ($(filter CYBERON_DIC_TTS, $(strip $(MODULE_DEFS))),)
     SRC_LIST += $(strip $(AUDFOLDER))\tts_drv.c
   else
     ifneq ($(filter IFLY_TTS, $(strip $(MODULE_DEFS))),)
       SRC_LIST += $(strip $(AUDFOLDER))\tts_drv.c
       endif
   endif
   ifneq ($(filter SINOVOICE_TTS, $(strip $(MODULE_DEFS))),)
     SRC_LIST += $(strip $(AUDFOLDER))\tts_drv.c
   endif   
   ifneq ($(filter __BT_A2DP_PROFILE__, $(strip $(MODULE_DEFS))),)
     SRC_LIST += $(strip $(AUDFOLDER))\sbc_drv.c
     ifeq ($(filter __LOW_COST_SUPPORT_COMMON__, $(strip $(MODULE_DEFS))),)
       SRC_LIST += $(strip $(AUDFOLDER))\daf_rtpss.c
     endif
   endif
   ifneq ($(filter UT_2WAYWB_RECORD_SUPPORT, $(strip $(MODULE_DEFS))),)
     ifneq ($(filter __UTIL_CLI_SUPPORT__, $(strip $(MODULE_DEFS))),)
       SRC_LIST += $(strip $(AUDFOLDER))\ut_2waywb_record.c
     endif
   endif
   ifneq ($(filter __ACOUSTIC_LOOPBACK_SUPPORT__, $(strip $(MODULE_DEFS))),)
     SRC_LIST += $(strip $(AUDFOLDER))\ut_acoustic_loopback.c
   endif
   ifneq ($(filter __UTIL_CLI_SUPPORT__, $(strip $(MODULE_DEFS))),)
     SRC_LIST += $(strip $(AUDFOLDER))\util_cli_input.c \
                 $(strip $(AUDFOLDER))\util_cli_parser.c \
                 $(strip $(AUDFOLDER))\util_cli_task.c \
                 $(strip $(AUDFOLDER))\util_aud_cmd.c
   endif
   ifneq ($(filter __LG_VOICE_ENGINE__, $(strip $(MODULE_DEFS))),)
     SRC_LIST += $(strip $(AUDFOLDER))\voice_clarity.c
   endif
   ifneq ($(filter VRSI_CYBERON, $(strip $(MODULE_DEFS))),)
     SRC_LIST += $(strip $(AUDFOLDER))\vr_si.c
   endif
   ifneq ($(filter WMA_DECODE, $(strip $(MODULE_DEFS))),)
     ifeq ($(strip $(AUD_SOLUTION)),V2)
       SRC_LIST += $(strip $(AUDFOLDER))\wma_drv.c
     else
       ifneq ($(filter __AUDIO_COMPONENT_SUPPORT__, $(strip $(MODULE_DEFS))),)
          SRC_LIST += $(strip $(AUDFOLDER))\cmpdrv\wma_comp_drv.c
       else
          SRC_LIST += $(strip $(AUDFOLDER))\wma_drv.c
       endif
     endif
   endif
   ifneq ($(filter __DAF_ENCODE__, $(strip $(MODULE_DEFS))),)
     SRC_LIST +=  $(strip $(AUDFOLDER))\mp3_enc_drv.c
   endif
   ifneq ($(filter __BT_SUPPORT__, $(strip $(MODULE_DEFS))),)
     SRC_LIST += $(strip $(AUDFOLDER))\BT_PcmLoopback.c
     ifneq ($(filter BT_Loopback_Test, $(strip $(COMP_DEFS))),)
       SRC_LIST += $(strip $(AUDFOLDER))\BT_loopback.c
     endif   
   endif
   ifneq ($(filter DSP_WT_SYN, $(strip $(MODULE_DEFS))),)
     ifeq ($(strip $(AUD_SOLUTION)),V1)
        DSP_WT_SYN_V1_SUPPORT_PLATFORM = MT6219 MT6223 MT6225 MT6229 MT6253T MT6253 MT6268A MT6268T MT6268H MT6223P
        ifneq ($(filter $(strip $(MODULE_DEFS)) ,$(DSP_WT_SYN_V1_SUPPORT_PLATFORM)),)
           SRC_LIST += $(strip $(AUDFOLDER))\Wavetable_DSPv1.c
        else
           ifeq ($(filter __AUDIO_COMPONENT_SUPPORT__, $(strip $(MODULE_DEFS))),)
           SRC_LIST += $(strip $(AUDFOLDER))\Wavetable_DSPv2.c
           endif
        endif
     endif
   endif
   ifneq ($(filter STREAM_SUPPORT, $(strip $(MODULE_DEFS))),)
     SRC_LIST += $(strip $(AUDFOLDER))\poc_amr.c
   else
     ifneq ($(filter __VOIP__, $(strip $(MODULE_DEFS))),)
       SRC_LIST += $(strip $(AUDFOLDER))\poc_amr.c
       endif
   endif
   ifneq ($(filter __VOIP__, $(strip $(MODULE_DEFS))),)
     SRC_LIST += $(strip $(AUDFOLDER))\PCMRB.c
   endif
endif           

SRC_LIST += $(strip $(AUDFOLDER))\comp\daf_seek.c \
            $(strip $(AUDFOLDER))\comp\ast.c \
            $(strip $(AUDFOLDER))\comp\audioeq.c \
            $(strip $(AUDFOLDER))\comp\kt_Detect.c \
            $(strip $(AUDFOLDER))\comp\media_avsync.c \
            $(strip $(AUDFOLDER))\comp\tonedect.c \
            $(strip $(AUDFOLDER))\comp\tonesyn.c

ifneq ($(filter __AUDIO_RECORD_COMPONENT_SUPPORT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\PcmSource.c
   SRC_LIST += hal\audio\src\common\src\PcmPacker.c
   SRC_LIST += hal\audio\src\common\src\SRConv.c
   
   ifneq ($(filter WAV_CODEC, $(strip $(MODULE_DEFS))),)
      SRC_LIST += hal\audio\src\common\src\WavEncoder.c
   endif
   ifeq ($(strip $(AUD_SOLUTION)),V1)
      ifneq ($(filter AMR_CODEC, $(strip $(MODULE_DEFS))),)
         SRC_LIST += hal\audio\src\v1\comp\PBMG\AmrDspEncoder.c
      endif
      ifneq ($(filter __VM_CODEC_SUPPORT__, $(strip $(MODULE_DEFS))),)
         SRC_LIST += hal\audio\src\v1\comp\PBMG\VmDspEncoder.c
      endif
   endif
   ifneq ($(filter DEDI_AMR_REC, $(strip $(MODULE_DEFS))),)
      SRC_LIST += hal\audio\src\common\src\AmrEncoder.c
   endif
   ifneq ($(filter __VORBIS_ENCODE__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += hal\audio\src\common\src\VorbisEncoder.c
   endif
   ifneq ($(filter __SPEECH_ENHENCEMENT_SWIP_SUPPORT__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += hal\audio\src\common\src\SphEnhance.c
   endif
endif

ifeq ($(strip $(AUD_SOLUTION)),V2)
  SRC_LIST += $(strip $(AUDFOLDER))\comp\apm.c
else
  ifneq ($(filter __AUDIO_COMPONENT_SUPPORT__, $(strip $(MODULE_DEFS))),)
     SRC_LIST += hal\audio\src\common\src\apm_comp.c
  else
     SRC_LIST += $(strip $(AUDFOLDER))\comp\apm.c
  endif
endif

ifeq ($(strip $(AUD_SOLUTION)),V2)
   SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\AudComUtil.c
   ifneq ($(strip $(MED_PROFILE)),MED_MODEM)
      SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\AudioDrain.c
      SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\MedAdapt.c
      SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\PcmRouteSrc.c
      SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\PcmSink.c
      SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\SeekEngine.c
   endif
   ifneq ($(filter AMR_CODEC, $(strip $(MODULE_DEFS))),)
      SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\AmrDecoder.c
      SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\AmrParser.c
   endif
   ifneq ($(filter AAC_DECODE, $(strip $(MODULE_DEFS))),)
      SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\AacDecoder.c
      SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\AacParser.c
   endif
   SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\M4aParser.c
   ifneq ($(filter DAF_DECODE, $(strip $(MODULE_DEFS))),)
      SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\DafParser.c
      SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\DafDecoder.c
   endif
   ifneq ($(filter __DRA_DECODE_SUPPORT__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\DraDecoder.c
   endif
   ifneq ($(filter WAV_CODEC, $(strip $(MODULE_DEFS))),)
      SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\WavDecoder.c
      SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\WavParser.c
   endif
   ifneq ($(filter __COOK_DECODE__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\CookDecoder.c
      SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\CookParser.c
   endif
   ifneq ($(filter __APE_DECODE__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\ApeDecoder.c
      SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\ApeParser.c
   endif
   ifneq ($(filter __VORBIS_DECODE__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\VorbisStrmDecoder.c
      SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\VorbisDecoder.c
      SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\VorbisParser.c
   endif
   ifneq ($(filter __BES_TS_SUPPORT__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\BesSoundTemplate.c
      SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\BesTSEntry.c
   endif
   
   ifneq ($(filter DSP_WT_SYN, $(strip $(MODULE_DEFS))),)
     SRC_LIST += $(strip $(AUDFOLDER))\comp\melody_common.c
     SRC_LIST += $(strip $(AUDFOLDER))\comp\jimy.c
     SRC_LIST += $(strip $(AUDFOLDER))\comp\jsmf.c
     SRC_LIST += $(strip $(AUDFOLDER))\comp\jtone.c
     SRC_LIST += $(strip $(AUDFOLDER))\comp\jwav.c
     SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\MelodySynthesizer.c
     SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\MelodyParser.c
   endif
else
   SRC_LIST += $(strip $(AUDFOLDER))\comp\aac_sbr.c \
               $(strip $(AUDFOLDER))\comp\aac_seek.c \
               $(strip $(AUDFOLDER))\comp\amr_seek.c \
               $(strip $(AUDFOLDER))\comp\jamr.c
               
  ifneq ($(filter __AUDIO_COMPONENT_SUPPORT__, $(strip $(MODULE_DEFS))),)
     SRC_LIST += hal\audio\src\common\src\AudComUtil.c
     ifneq ($(strip $(MED_PROFILE)),MED_MODEM)
        SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\PcmSink.c
        SRC_LIST += hal\audio\src\common\src\AudioDrain.c
        SRC_LIST += hal\audio\src\common\src\MedAdapt.c
        SRC_LIST += hal\audio\src\common\src\PcmRouteSrc.c
        SRC_LIST += hal\audio\src\common\src\pcmRouteService.c
        SRC_LIST += hal\audio\src\common\src\SeekEngine.c
     endif
     ifneq ($(filter WMA_DECODE, $(strip $(MODULE_DEFS))),)
      SRC_LIST += hal\audio\src\common\src\WmaDecoder.c
      SRC_LIST += hal\audio\src\common\src\WmaParser.c
     endif
     ifneq ($(filter __VORBIS_DECODE__, $(strip $(MODULE_DEFS))),)
       SRC_LIST += hal\audio\src\common\src\VorbisStrmDecoder.c
       SRC_LIST += hal\audio\src\common\src\VorbisParser.c
       SRC_LIST += hal\audio\src\common\src\VorbisDecoder.c
     endif     
     ifneq ($(filter DAF_DECODE, $(strip $(MODULE_DEFS))),)
       SRC_LIST += hal\audio\src\common\src\DafParser.c
       SRC_LIST += hal\audio\src\common\src\DafDecoder.c
     endif
     ifneq ($(filter __FLAC_DECODE__, $(strip $(MODULE_DEFS))),)
       SRC_LIST += hal\audio\src\common\src\FlacParser.c
       SRC_LIST += hal\audio\src\common\src\FlacDecoder.c
     endif  
     ifneq ($(filter AAC_DECODE, $(strip $(MODULE_DEFS))),)
        SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\AacDspDecoder.c
        SRC_LIST += hal\audio\src\common\src\AacParser.c
     endif
     SRC_LIST += hal\audio\src\common\src\M4aParser.c
     ifneq ($(filter __DRA_DECODE_SUPPORT__, $(strip $(MODULE_DEFS))),)
       SRC_LIST += hal\audio\src\common\src\DraDecoder.c
     endif
     ifneq ($(filter WAV_CODEC, $(strip $(MODULE_DEFS))),)
       SRC_LIST += hal\audio\src\common\src\WavDecoder.c
       SRC_LIST += hal\audio\src\common\src\WavParser.c
     endif
     ifneq ($(filter AMR_CODEC, $(strip $(MODULE_DEFS))),)
       SRC_LIST += hal\audio\src\common\src\AmrParser.c
       SRC_LIST += $(strip $(AUDFOLDER))\comp\PBMG\AmrDspDecoder.c
     endif    
     ifneq ($(filter __COOK_DECODE__, $(strip $(MODULE_DEFS))),)
       SRC_LIST += hal\audio\src\common\src\CookDecoder.c
       SRC_LIST += hal\audio\src\common\src\CookParser.c
     endif
     ifneq ($(filter __APE_DECODE__, $(strip $(MODULE_DEFS))),)
       SRC_LIST += hal\audio\src\common\src\ApeDecoder.c
       SRC_LIST += hal\audio\src\common\src\ApeParser.c
     endif
     ifneq ($(filter __BES_TS_SUPPORT__, $(strip $(MODULE_DEFS))),)
       SRC_LIST += hal\audio\src\common\src\BesSoundTemplate.c
       SRC_LIST += hal\audio\src\common\src\BesTSEntry.c
     endif     
  endif
  
  
  ifneq ($(filter DSP_WT_SYN, $(strip $(MODULE_DEFS))),)    
     ifneq ($(filter __AUDIO_COMPONENT_SUPPORT__, $(strip $(MODULE_DEFS))),)
        SRC_LIST += hal\audio\src\common\src\melody\jimy_comp.c
        SRC_LIST += hal\audio\src\common\src\melody\jsmf_comp.c
        SRC_LIST += hal\audio\src\common\src\melody\jtone_comp.c
        SRC_LIST += hal\audio\src\common\src\melody\jwav_comp.c
        SRC_LIST += hal\audio\src\common\src\melody\melody_common.c
        SRC_LIST += hal\audio\src\common\src\melody\MelodySynthesizer.c
        SRC_LIST += hal\audio\src\common\src\melody\MelodyParser.c
     else
        SRC_LIST += $(strip $(AUDFOLDER))\comp\dspsyn.c
        SRC_LIST += $(strip $(AUDFOLDER))\comp\jimy.c
        SRC_LIST += $(strip $(AUDFOLDER))\comp\jsmf.c
        SRC_LIST += $(strip $(AUDFOLDER))\comp\jtone.c
        SRC_LIST += $(strip $(AUDFOLDER))\comp\jwav.c
     endif
  endif
endif

ifneq ($(filter __VOIP__, $(strip $(MODULE_DEFS))),)
     SRC_LIST += $(strip $(AUDFOLDER))\comp\VoRTP\VoRTP.c \
                 $(strip $(AUDFOLDER))\comp\RTPBuffer.c \
                 $(strip $(AUDFOLDER))\comp\RTPCodec.c \
                 $(strip $(AUDFOLDER))\comp\G711_main.c \
                 $(strip $(AUDFOLDER))\comp\G726_main.c \
                 $(strip $(AUDFOLDER))\comp\VoIPev_drv.c \
                 $(strip $(AUDFOLDER))\comp\vmi.c
endif

#  Define include path lists to INC_DIR
INC_DIR = $(strip $(AUDFOLDER)) \
          $(strip $(AUDFOLDER))\inc \
          $(strip $(AUDFOLDER))\comp \
          $(strip $(AUDFOLDER))\comp\VoRTP \
          hal\audio\lib\MTKINC \
          hal\audio\lib\VENDOR\tc01 \
          interface\hal\audio \
          interface\hal\video \
          interface\hal\system \
          hal\dsp_ram \
          hal\dp_engine\ctm \
          hal\dp_engine \
          $(strip $(PS_FOLDER))\l4\include \
          hal\audio\src32_inc \
          drv\include \
          hal\video\demuxer\mp4_parser\inc \
          hal\system\init\inc \
          l1_dm\l1d_ext \
          hal\system\DP\inc \
          hal\system\dcmgr\inc \
          custom\common\hal

ifneq ($(filter __GENERAL_TTS__, $(strip $(MODULE_DEFS))),)
     INC_DIR += hal\audio\lib\VENDOR\tts
endif
ifeq ($(strip $(AUD_SOLUTION)),V1)
  ifneq ($(filter __AUDIO_COMPONENT_SUPPORT__, $(strip $(MODULE_DEFS))),)
     INC_DIR += hal\audio\src\common\inc
  endif
endif

ifneq ($(filter __CENTRALIZED_SLEEP_MANAGER__, $(strip $(MODULE_DEFS))),)
  INC_DIR    += hal\sleep_drv\public\inc
endif

# Define the specified compile options to COMP_DEFS
COMP_DEFS = APCS_INTWORK
 
          
 

