/*----------------------------------------------------------------------------*
 * No Warranty                                                                   *
 * Except as may be otherwise agreed to in writing, no warranties of any      *
 * kind, whether express or implied, are given by MTK with respect to any MTK *
 * Deliverables or any use thereof, and MTK Deliverables are provided on an   *
 * "AS IS" basis.  MTK hereby expressly disclaims all such warranties,        *
 * including any implied warranties of merchantability, non-infringement and  *
 * fitness for a particular purpose and any warranties arising out of course  *
 * of performance, course of dealing or usage of trade.  Parties further      *
 * acknowledge that Company may, either presently and/or in the future,       *
 * instruct MTK to assist it in the development and the implementation, in    *
 * accordance with Company's designs, of certain softwares relating to        *
 * Company's product(s) (the "Services").  Except as may be otherwise agreed  *
 * to in writing, no warranties of any kind, whether express or implied, are  *
 * given by MTK with respect to the Services provided, and the Services are   *
 * provided on an "AS IS" basis.  Company further acknowledges that the       *
 * Services may contain errors, that testing is important and Company is      *
 * solely responsible for fully testing the Services and/or derivatives       *
 * thereof before they are used, sublicensed or distributed.  Should there be *
 * any third party action brought against MTK, arising out of or relating to  *
 * the Services, Company agree to fully indemnify and hold MTK harmless.      *
 * If the parties mutually agree to enter into or continue a business         *
 * relationship or other arrangement, the terms and conditions set forth      *
 * hereunder shall remain effective and, unless explicitly stated otherwise,  *
 * shall prevail in the event of a conflict in the terms in any agreements    *
 * entered into between the parties.                                          *
 *---------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
 * Copyright(c) 2009, MediaTek, Inc.
 * All rights reserved.
*
 * Unauthorized use, practice, perform, copy, distribution, reproduction,
 * or disclosure of this information in whole or in part is prohibited.
 *-----------------------------------------------------------------------------
 * $File: //DTV/MAIN_BR/mATV/tool/mATVctrl_VC6/mATVctrl/mATVdrv_chtable.h $
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
  *             HISTORY
 * removed!
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
 *---------------------------------------------------------------------------*/
/**
 *   @file hostlib.h
 *		
 *   @author lh.hsiao 
 */
#ifndef __HOSTLIB_H__
#define __HOSTLIB_H__

#if defined(__MTK_TARGET__)

#include "kal_release.h"

 #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if 0
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
#endif

/////////////////////////////////////////////////////////////////////////////
//power on/off/suspend
/////////////////////////////////////////////////////////////////////////////
kal_uint32 ATVChipID(void);
kal_bool bChipInit(kal_uint8 tvmode);
kal_bool bChipSuspend(kal_bool on);
kal_bool bChipShutdown(void);
void vMainloop(kal_uint32 delay_in_10ms); //chip main loop service running by task

/////////////////////////////////////////////////////////////////////////////
//ch scan/control
/////////////////////////////////////////////////////////////////////////////
#define Freq2DR(freqkhz)	(kal_uint16)((freqkhz*2)/125) //(freqkhz*16)/1000
#define DR2Freq(freqDR)		(((kal_uint32)freqDR*125)/2)
extern kal_uint16 Freq2DR_Fn(kal_uint32 freqkhz);
extern kal_uint32 DR2Freq_Fn(kal_uint16 freqDR);

enum 
{
	CHINS_AUTO=0,
	CHINS_FULLSCAN=1,
	CHINS_1CH=2
};

extern void vChSearchInit(kal_uint16 freqDR, kal_uint8 scantype);
extern void vChSearchStop(void);
extern void vChQuickInstall(void);
extern void vChChg(kal_uint8 ch);
extern void vChNext(kal_uint8 inc);
extern void vChSetCountryID(kal_uint8 id);

struct ChRec 
{
	kal_uint16	freqDR;
	kal_uint8	sndsys;	/* reference sv_const.h, TV_AUD_SYS_T ...*/
	kal_uint8	colsys;	/* reference sv_const.h, SV_CS_PAL_N, SV_CS_PAL,SV_CS_NTSC358...*/
	kal_uint8	flag;
};

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

extern kal_bool bChTab_Get(kal_uint8 n,struct ChRec * rec);//return 1:success 0:fail
extern kal_bool bChTab_Set(kal_uint8 n,struct ChRec * rec);//return 1:success 0:fail
extern kal_bool bChTab_Clear(kal_uint8 n);//return 1:success 0:fail
extern kal_bool bChTab_ClearAll(void);//return 1:success 0:fail

typedef  void (*AutoScanProgCB_t)(kal_uint8 precent,kal_uint8 ch,kal_uint8 chnum);
typedef  void (*FullScanProgCB_t)(kal_uint8 precent,kal_uint32 freq,kal_uint32 freq_start,kal_uint32 freq_end);
typedef  void (*ScanFinishCB_t)(kal_uint8 chnum);
void RegisterChScanCB(AutoScanProgCB_t auto_cb,FullScanProgCB_t full_cb,ScanFinishCB_t finish_cb);

/////////////////////////////////////////////////////////////////////////////
//AUDIO
/////////////////////////////////////////////////////////////////////////////

	void vApiAudioPlay(kal_uint8 fgWaitPlay);
	void vApiAudioStop(void);	
	void vApiAudioSetMasterVolume(kal_uint8 bValue);
	kal_uint32 dwApiAudioGetFormatSrc(void);
	void vApiAudioSetAtvOutputMode(kal_uint32 eSoundMode);
//meta	
	kal_uint8 bApiAudioGetFmRdoDetectStatus (kal_uint32 *info);	
	kal_uint8 bApiAudioGetSoundSystem(kal_uint32 *info);

typedef  void (*AudNotifyCB_t)(kal_uint32 format);
void RegisterAudNotifyCB(AudNotifyCB_t aud_notify_cb);

/////////////////////////////////////////////////////////////////////////////
//TVD
/////////////////////////////////////////////////////////////////////////////
enum TVD_BLOCK{
    TVD_BLOCK_IS443=0,
    TVD_BLOCK_IS358,
    TVD_BLOCK_UNKNOW
};

extern kal_uint8 bTvd3dGetColorSystem(void);
extern void vDrvTvd3dSetColorSystem(kal_uint8 bColSys);
extern void vTvd3dReset(void);
extern kal_uint8 fgDrvTvdCheckTVDLock(void);
extern kal_uint8 bDrvTvdCheckBurstFreq(void);
extern kal_uint8 bTvd3dGetNRLevel(void);

extern void vApiVideoPosBrightness(kal_uint8 polarity, kal_uint8 bValue);
extern void vApiVideoPreBrightness(kal_uint8 polarity, kal_uint8 bValue);
extern void vApiVideoContrast(kal_uint8 bValue);
extern void vApiVideoSaturation(kal_uint8 bValue);

#ifdef __CLASSK_CP_SUPPORT__
extern kal_bool mATV_Class_K_Implementation(void);
#endif

/////////////////////////////////////////////////////////////////////////////
//Chip/Vendor dependent
/////////////////////////////////////////////////////////////////////////////

typedef enum
{
	eOFF=0,
	eON=1
} eOnOff;

typedef enum
{
	FPS15=15,	/*if PAL mode 12.5 fps*/
	FPS20=20,	/*if PAL mode 16.67 fps*/
	FPS30=30	/*if PAL mode 25 fps*/
} eTVDMaxFramerate;

typedef enum
{
	CAMIF_Normal_Mode = 0,
	CAMIF_Direct_Mode = 3,	/*240*320=4.33Mhz 15fps, 176x220 PCLK=6.5MHz 30fps*/
	CAMIF_Direct_L_Mode = 4 /*240*320=4.33Mhz 15fps, 176x220 PCLK=3.25MHz 15fps*/
} eTVDCamIFMode;

typedef enum
{
	NR_Normal_Mode = 0,
	Force_On_Mode,
	Force_Off_Mode
} eTVDNR;

typedef enum
{
	I2S_Master_PWM = 0,
	I2S_Master,
	I2S_Slave,
	PWM,
	I2S_Slave_PWM	
} eAUDOutputMode;


enum
{
	//export to standard enum (mandatory)
	EXPORT_SIG_RSSI=0,
	EXPORT_SIG_SNR,
	EXPORT_SIG_STRENGTH,
	EXPORT_TVD_MaxFrameRate, /* ref. eTVDMaxFramerate */
	EXPORT_AUD_OutputMode,
	EXPORT_AUD_SWMute,
	
	/* item >= 100, variant info, not fixed
	 * example
	 * MTK_GAIN0=100,
	 * MTK_GAIN1=101 
	 */
	MTK_TVD_MaxFrameRate=180,	/* ref. eTVDMaxFramerate */
	MTK_TVD_CamIFRefMCLK,		/* ref. eOnOff */
	MTK_TVD_CamIFMode,		/* ref. eTVDCamIFMode */
	MTK_TVD_CamIFCaptureMode,	/* ref. eOnOff */
	MTK_TVD_CamIFResolution,	/* (width<<16)|height */
	MTK_TVD_SMOOTHER,			/* ref. (eTVDSMOOTHER<<4)|Thr */
	MTK_TVD_PCLK_INV,			/* ref. eOnOff */
	MTK_TVD_FrameRate,
	MTK_TVD_FRDIV2_WA,			/* 1~5, 0xff*/
	MTK_TVD_ScanLockPara,			/*VOFST_TH Recheck_TH CHECKTVD_ROUND,  */
	MTK_AUD_OutputMode=190,		/* ref. eAUDOutputMode */
	MTK_AUD_SWMute,	
	MTK_CLI_PORT=200,

	MTK_DRV_VERSION_ID=202,
	MTK_DRV_VERSION_SUB_ID,
	MTK_LCM_WRITECYCLE=210,
	MTK_PAD_DRIVING,	/* (pin<<4)|driving ; pin:0~7, H, V, PCLK*/
	MTK_ATD_EQ,
	MTK_TVD_AdapC,
	MTK_AUD_AVC,
	MTK_AUD_SmartToggling,
	MTK_TVD_DropFrameRate,
	MTK_TVD_EnableSharpness,
	MTK_TVD_Enable1DNR,
	MTK_TVD_MN_DropFrameRate,
	MTK_TVD_RealTimeMode,
	MTK_TVD_MN_RealTimeMode,
	MTK_TVD_RecoverDropFrameRate,
	MTK_TVD_DelayMode,
	MTK_TVD_AdjustNR,
	MTK_TVD_Bypass,
	MTK_TVD_Color
};
kal_uint32 DrvGetChipDep(kal_uint8 item);
kal_bool DrvSetChipDep(kal_uint8 item,kal_uint32 val);

#endif /* __MTK_TARGET__ */
#endif /* __HOSTLIB_H__ */
