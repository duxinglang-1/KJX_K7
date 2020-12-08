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
	 *	 atv_api.h
	 *
	 * Project:
	 * --------
	 *	 Maui_sw
	 *
	 * Description:
	 * ------------
	 *	 implement adapter atv and mtv
	 *
	 * Author:
	 * -------
	 *	 shaowu.he (mtk70699)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __ATV_API_H__
#define __ATV_API_H__

#if defined(__ATV_SUPPORT__)

#define ATV_MAX_SIGNAL_STRENGTH    (100)

/* audio format */
/* MTS auto update use */
#define ATV_API_MTS_MONO        0x00000001
#define ATV_API_MTS_STEREO      0x00000002
#define ATV_API_MTS_SAP         0x00000004

/* Japan & Korea MPX */
#define ATV_API_MPX_MONO        0x00000008
#define ATV_API_MPX_STEREO      0x00000010
#define ATV_API_MPX_SUB         0x00000020
#define ATV_API_MPX_MAIN_SUB    0x00000040
#define ATV_API_MPX_MAIN        0x00000080

#define ATV_API_FM_MONO         0x00000100
#define ATV_API_A2_STEREO       0x00000200
#define ATV_API_A2_DUAL1        0x00000400
#define ATV_API_A2_DUAL2        0x00000800
#define ATV_API_NICAM_MONO      0x00001000
#define ATV_API_NICAM_STEREO    0x00002000
#define ATV_API_NICAM_DUAL1     0x00004000
#define ATV_API_NICAM_DUAL2     0x00008000

#define ATV_API_FMRDO_MONO      0x00010000
#define ATV_API_FMRDO_STEREO    0x00020000

#define ATV_API_FORMAT_DETECTING 0x00000000

#define ATV_API_AUDIO_MASK_MTS      (ATV_API_MTS_MONO | ATV_API_MTS_STEREO | ATV_API_MTS_SAP)
#define ATV_API_AUDIO_MASK_MPX      (ATV_API_MPX_MONO | ATV_API_MPX_STEREO | ATV_API_MPX_SUB | ATV_API_MPX_MAIN_SUB | ATV_API_MPX_MAIN)
#define ATV_API_AUDIO_MASK_FM       (ATV_API_FM_MONO)
#define ATV_API_AUDIO_MASK_A2       (ATV_API_A2_STEREO | ATV_API_A2_DUAL1 | ATV_API_A2_DUAL2)
#define ATV_API_AUDIO_MASK_NICAM    (ATV_API_NICAM_MONO | ATV_API_NICAM_STEREO | ATV_API_NICAM_DUAL1 | ATV_API_NICAM_DUAL2)
#define ATV_API_AUDIO_MASK_FMRDO    (ATV_API_FMRDO_MONO | ATV_API_FMRDO_STEREO)

/* country */
typedef enum
{
    ATV_API_AFGHANISTAN = 0, ATV_API_COUNTRY_START = ATV_API_AFGHANISTAN,
    ATV_API_ARGENTINA,
    ATV_API_AUSTRALIA,
    ATV_API_BRAZIL,
    ATV_API_BURMA,
    ATV_API_CAMBODIA,
    ATV_API_CANADA,
    ATV_API_CHILE,
    ATV_API_CHINA,
    ATV_API_CHINA_HONGKONG,
    ATV_API_CHINA_SHENZHEN,
    ATV_API_EUROPE_EASTERN,
    ATV_API_EUROPE_WESTERN,
    ATV_API_FRANCE,
    ATV_API_FRENCH_COLONIE,
    ATV_API_INDIA,
    ATV_API_INDONESIA,
    ATV_API_IRAN,
    ATV_API_ITALY,
    ATV_API_JAPAN,
    ATV_API_KOREA,
    ATV_API_LAOS,
    ATV_API_MALAYSIA,
    ATV_API_MEXICO,
    ATV_API_NEWZEALAND,
    ATV_API_PAKISTAN,
    ATV_API_PARAGUAY,
    ATV_API_PHILIPPINES,
    ATV_API_PORTUGAL,
    ATV_API_RUSSIA,
    ATV_API_SINGAPORE,  // 30
    ATV_API_SOUTHAFRICA,
    ATV_API_SPAIN,
    ATV_API_TAIWAN,     // 33
    ATV_API_THAILAND,
    ATV_API_TURKEY,
    ATV_API_UNITED_ARAB_EMIRATES,
    ATV_API_UNITED_KINGDOM,
    ATV_API_USA,
    ATV_API_URUGUAY,
    ATV_API_VENEZUELA,
    ATV_API_VIETNAM,
    ATV_API_IRELAND,
    ATV_API_MOROCCO,
    ATV_API_COUNTRY_MAX,
    ATV_API_COUNTRY_END = ATV_API_COUNTRY_MAX,

    //alias
    ATV_API_BANGLADESH = ATV_API_PAKISTAN
} atv_country_t;

typedef enum
{
    ATV_AUTOSCAN,
    ATV_FULLSCAN,
    ATV_QUICKSCAN
} atv_scan_mode;

typedef struct
{
    kal_uint32	freq; //khz
    kal_uint8   audio_system;
    kal_uint8   color_system;
    kal_uint8   flag;
    kal_bool    valid;
} atv_ch_info;

typedef enum
{
    ATV_VDO_BRIGHTNESS,
    ATV_VDO_CONTRAST,
    ATV_VDO_SATURATION

} atv_video_param_t;

typedef enum
{
    ATV_AUD_TYPE_I2S,
    ATV_AUD_TYPE_LINEIN,
    ATV_AUD_TYPE_NONE

} atv_audio_type_t;

typedef enum
{
    ATV_AUD_TYPE,
    ATV_AUD_SAMPLING_RATE,
    ATV_AUD_BITS_PER_SAMPLE,
    ATV_AUD_CHANNEL_NUM

} atv_audio_param_t;

typedef enum
{
	ATV_SV_CS_NTSC,
	ATV_SV_CS_PAL,
	ATV_SV_CS_MAX
}atv_video_color_system_t;
/* atv part */
extern kal_bool ATV_PowerOn(void);
extern kal_bool ATV_PowerOff(void);

extern void     ATV_Scan(kal_uint8 country, kal_uint8 mode);
extern void     ATV_StopScan(void);

extern kal_bool ATV_GetChannelTable(kal_uint32 ch_id, atv_ch_info* ch_info);
extern kal_bool ATV_SetChannelTable(kal_uint32 ch_id, atv_ch_info* ch_info);
extern kal_bool ATV_ClearChannelTable(void);
extern void     ATV_ChangeChannel(kal_uint32 ch_id);

extern kal_bool ATV_VideoOpen(void);
extern kal_bool ATV_VideoClose(void);
extern kal_bool ATV_SetVideoParam(atv_video_param_t param, kal_int32 value);
extern kal_uint8 ATV_GetVideoColorSystem(void);

extern kal_uint32 ATV_GetAudioFormat(void);
extern void       ATV_SetAudioFormat(kal_uint32 format);

extern kal_int32  ATV_GetSignalStrength(void);
extern kal_int32  ATV_GetSignalSNR(void);


/* callback */
typedef void (*atv_autoscan_progress_cb)(void* cb_param, kal_uint8 precent, kal_uint8 ch, kal_uint8 chnum);
typedef void (*atv_fullscan_progress_cb)(void* cb_param, kal_uint8 precent, kal_uint32 freq, kal_uint32 freq_start,kal_uint32 freq_end);
typedef void (*atv_scanfinish_cb)(void* cb_param, kal_uint8 chnum);
typedef void (*atv_audioformat_cb)(void* cb_param, kal_uint32 format);
extern void ATV_RegisterCallback(void* cb_param,
	                        atv_autoscan_progress_cb auto_cb,
                        	atv_fullscan_progress_cb full_cb,
                        	atv_scanfinish_cb finish_cb,
                        	atv_audioformat_cb audfmt_cb);

/* audio part */
extern void     ATV_AudioSetOutputDevice(kal_uint8 device);
extern void     ATV_AudioSetOutputVolume(kal_uint8 volume1, kal_int8 digital_gain_index);
extern void     ATV_AudioSetLevelVolume(kal_uint8 MaxAnalogGain, kal_uint8 step, kal_uint8 level);
extern void     ATV_AudioMute(kal_bool mute);
extern kal_bool ATV_AudioOpen(void);
extern kal_bool ATV_AudioClose(void);
extern void     ATV_GetAudioParam(atv_audio_param_t param, kal_int32* value);
extern void 	ATV_SetChannelScanMode(kal_bool enable);
extern kal_bool ATV_GetChannelScanMode(void);

#endif // #if defined(__ATV_SUPPORT__)
#endif
