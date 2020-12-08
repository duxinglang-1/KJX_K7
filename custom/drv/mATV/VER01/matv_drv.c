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
 *   matv_drv.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   implement atv power on seq/ channel talbe/ auido control/gpio setting
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


#if defined(__MTK_TARGET__) && defined(__ATV_SUPPORT__)
#if defined(MT6250)|| defined(MT6260)
#undef __SERIAL_SENSOR_V1_SUPPORT__
#endif

 #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#include "kal_trace.h"
#include "matvctrl.h"
#include "hostlib.h"
#include "dcl.h"

#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#include "dcmgr.h"
#endif

//#include "mtv_comm.h"
#if defined(MT6250)
#include "l1_fh_interface.h"
#endif
#if (!(defined(MT6223)||defined(MT6223P)||defined(__DIRECT_SENSOR_V2_SUPPORT__)))
#ifndef  _MATV_NOT_REF_MCLK_
  #define _MATV_NOT_REF_MCLK_
#endif
#endif
extern kal_uint8 atv_slp_handle; // added for Sleep mode, sleep mode controll will move from MED to porting layer[MAUI_02602171]
extern kal_bool bAtv_IsSleepHandleInit;
extern void L1SM_SleepDisable( kal_uint8 handle );
extern void L1SM_SleepEnable( kal_uint8 handle );
extern kal_uint8 L1SM_GetHandle ( void );

extern void matv_kal_take_sem(void);
extern void matv_kal_give_sem();
//typedef  void (*FullScanProgCB_t)(UINT8 precent,UINT32 freq,UINT32 freq_start,UINT32 freq_end);
//typedef  void (*matv_fullscan_progress_cb)(kal_uint8 precent,kal_uint32 freq,kal_uint32 freq_start,kal_uint32 freq_end);
/////////////////////////////////////////////////////////////////////////////
#ifndef MATV_UART_PORT_NULL
#define MATV_UART_PORT_NULL 0xFF
#endif

extern void matv_set_atv_chip_customization(void);
/////

#if 0//defined(MOTION_SENSOR_SUPPORT)
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
/////

//extern MATV_GET_SCCB_INFO_STRUCT MATVSccbData;
//callback
/////////////////////////////////////////////////////////////////////////////
kal_bool bMatv_powerOn = KAL_FALSE;
static void * matvdrv_cb_param;
static	matv_autoscan_progress_cb matvdrv_auto_cb;
static	matv_fullscan_progress_cb matvdrv_full_cb;
static	matv_scanfinish_cb matvdrv_finish_cb;
static	matv_audioformat_cb matvdrv_audfmt_cb;
kal_bool matvdrv_ps_status = KAL_FALSE;

kal_bool matvdrv_ps_init(kal_bool on);

#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_MATVDRIVER_ROCODE", rodata = "DYNAMIC_CODE_MATVDRIVER_ROCODE"
#endif
static void matvdrv_autoscan_progress_cb(kal_uint8 precent,kal_uint8 ch,kal_uint8 chnum)
{
	matvdrv_auto_cb(matvdrv_cb_param,precent,ch,chnum);
}
static void matvdrv_fullscan_progress_cb(kal_uint8 precent,kal_uint32 freq,kal_uint32 freq_start,kal_uint32 freq_end)
{
	matvdrv_full_cb(matvdrv_cb_param,precent,freq,freq_start,freq_end);
}

static void matvdrv_scanfinish_cb(kal_uint8 chnum)
{
	matvdrv_finish_cb(matvdrv_cb_param,chnum);
}
void ATV_SetSccbInfo(void)
{
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
#endif	 
} /* ATV_SetSccbInfo() */

static void matvdrv_audioformat_cb(kal_uint32 format)
{
	matvdrv_audfmt_cb(matvdrv_cb_param,format);
}
#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif
void matvdrv_register_callback(
	void* cb_param,
	matv_autoscan_progress_cb auto_cb,
	matv_fullscan_progress_cb full_cb,
	matv_scanfinish_cb finish_cb,
	matv_audioformat_cb audfmt_cb)
{
	matvdrv_cb_param=cb_param;
	matvdrv_auto_cb=auto_cb;
	matvdrv_full_cb=full_cb;
	matvdrv_finish_cb=finish_cb;
	matvdrv_audfmt_cb=audfmt_cb;
}
#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_MATVDRIVER_ROCODE", rodata = "DYNAMIC_CODE_MATVDRIVER_ROCODE"
#endif
#define CUSTOM_MATV_AVC_ATV  0// Auto volume control, 0 = off, 1 = on
// AVC default max gain = 12dB;if AVC is on,please set ClassAB too.
extern void ATV_i2c_init(void);
extern void matv_module_power_off(void);
extern void  matv_module_power_on(void);
 /*****************************************************************************
 * FUNCTION
 *	matvdrv_poweroff_seq
 * DESCRIPTION
 *	power off sequency
 * PARAMETERS
 *	 void
 * RETURNS
 *	
 *****************************************************************************/ 
 kal_bool matvdrv_poweroff_seq(void)
 {
     matv_module_power_off();
	#if defined(MT6250)
	 L1D_FH_ATV_TurnOn(KAL_FALSE);
	 #endif
	 bMatv_powerOn = KAL_FALSE;
	  return KAL_TRUE;
 }

  /*****************************************************************************
 * FUNCTION
 *	matvdrv_detect_id
 * DESCRIPTION
 *	detect atv id
 * PARAMETERS
 *	NONE
 * RETURNS
 *	KAL_TRUE: Detect id successful
 *    KAL_FALSE:  Detect id  fail
 *****************************************************************************/
 kal_bool matvdrv_detect_id(void)
{
    kal_uint32 id;
   id=ATVChipID();
#ifdef MATV_DRV_DEBUG
		  kal_wap_trace(MOD_MATV, TRACE_INFO, "matvdrv_init() chipid=%x \n",id);
#endif
	if((id!=0x90)&&(id!=0x91)&&(id!=0x92))
	{
#ifdef MATV_DRV_DEBUG	
		  matv_wap_trace(MOD_MATV, TRACE_INFO, "matvdrv_init() chipid=%x,init failed\n",id);
#endif
		  matvdrv_poweroff_seq();
		  return KAL_FALSE;
	  }
	  return  KAL_TRUE;
}
  /*****************************************************************************
 * FUNCTION
 *	matvdrv_poweron_seq
 * DESCRIPTION
 *	power on sequency
 * PARAMETERS
 *	tvmode: 1---TV mode;  0---FM
 * RETURNS
 *	KAL_TRUE: power on successful 
 *    KAL_FALSE:  Power on fail
 *****************************************************************************/
  kal_bool matvdrv_poweron_seq(int tvmode)
  {
     // kal_bool ret = KAL_TRUE;
	  matv_module_power_on();
	#if defined(MT6250)
	L1D_FH_ATV_TurnOn(KAL_TRUE);
	#endif
      if(KAL_TRUE != matvdrv_detect_id())
      {
#ifdef MATV_DRV_DEBUG
         matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matvdrv_detect_id FAIL");
#endif
         return KAL_FALSE;
	  }
#ifdef MATV_DRV_DEBUG
	  matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matvdrv_detect_id Successful");
#endif
	  return KAL_TRUE;
  }
  /*****************************************************************************
  * FUNCTION
  *  matvdrv_prepare
  * DESCRIPTION
  *  init CLI uart port if CLI enable, set event to make matv task go forword
  * PARAMETERS
  *  void
  * RETURNS
  *  void
  *****************************************************************************/
void matvdrv_prepare(void)
{ 
           extern kal_eventgrpid matv_event_id;
		   extern kal_bool mATV_CLI_enable;
	       extern kal_uint8 u1CliUseUartPort;
		   extern kal_uint8 cli_init(DCL_DEV port);
		   if(mATV_CLI_enable && (u1CliUseUartPort==uart_port_null)) //uart_port_null
		   {
			ATV_i2c_init();
			cli_init(uart_port1);			// uart_port1, DCL_UART1
		   }
	       bMatv_powerOn = KAL_TRUE;
	       kal_set_eg_events(matv_event_id,1,KAL_OR);
}


/////////////////////////////////////////////////////////////////////////////
//drv init/suspend/shutdown
/////////////////////////////////////////////////////////////////////////////
kal_bool matvdrv_init(void)
{
	int ret;
	extern kal_uint16 matv_get_LCM_WriteCycle(void);

#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_init In");
#endif

	matv_kal_take_sem();
	
	matvdrv_prepare();
	#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "matvdrv_init() begin\n");
	#endif
	ret=matvdrv_poweron_seq(1);
	if(ret)
	{

	RegisterChScanCB(matvdrv_autoscan_progress_cb,
			(FullScanProgCB_t)matvdrv_fullscan_progress_cb,
			matvdrv_scanfinish_cb);						
	RegisterAudNotifyCB((AudNotifyCB_t)matvdrv_audioformat_cb);
	
#if (defined(MT6223P)||defined(MT6223)||defined(__DIRECT_SENSOR_V2_SUPPORT__))
	bChipSuspend(1);
#endif
	
#if 0//defined(MOTION_SENSOR_SUPPORT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif   /* MOTION_SENSOR_SUPPORT */


	ret=bChipInit(1);
	
	#if 0//defined(MOTION_SENSOR_SUPPORT)
/* under construction !*/
/* under construction !*/
	#endif   /* MOTION_SENSOR_SUPPORT */

	if(ret)
	{
#if  (defined( _MATV_NOT_REF_MCLK_))
  DrvSetChipDep(MTK_TVD_CamIFRefMCLK,0);
#endif
#if (defined(MT6223P)||defined(MT6223)||defined(__DIRECT_SENSOR_V2_SUPPORT__)) //for direct
		DrvSetChipDep(MTK_TVD_CamIFMode,3);
#elif (defined(__SERIAL_SENSOR_V1_SUPPORT__))     //for serial
		DrvSetChipDep(MTK_TVD_CamIFMode,1);
#else
		DrvSetChipDep(MTK_TVD_CamIFMode,0);
#endif

		matv_set_atv_chip_customization();
        DrvSetChipDep(MTK_LCM_WRITECYCLE, matv_get_LCM_WriteCycle());

#if  CUSTOM_MATV_AVC_ATV
			DrvSetChipDep(MTK_AUD_AVC,0x30000);
#else
			DrvSetChipDep(MTK_AUD_AVC,0);
#endif

	}
	}
		#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "matvdrv_init() finished\n");
	#endif
	matv_kal_give_sem();

#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_init Out");
#endif		
	return 	(kal_bool)ret;
}

kal_bool matvdrv_suspend(kal_bool on)
{
	kal_bool ret;
	
#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_suspend In");
#endif		

	matv_kal_take_sem();

	ret = bChipSuspend(on);

	matv_kal_give_sem();

#ifdef MATV_DRV_DEBUG		
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_suspend Out");
#endif		
	
      return ret;
	//return 	bChipSuspend(on);
}

kal_bool matvdrv_shutdown(void)
{
	kal_bool ret;

#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_shutdown In");
#endif	
	
	matv_kal_take_sem();
	
#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "matvdrv_shutdown() begin\n");
#endif

	ret=bChipShutdown();
	matvdrv_poweroff_seq();
#if (defined(MT6223P)||defined(MT6223)||defined(__DIRECT_SENSOR_V2_SUPPORT__))
		matvdrv_ps_init(1);
#endif
#ifdef MATV_DRV_DEBUG	
		matv_wap_trace(MOD_MATV, TRACE_INFO, "matvdrv_shutdown() finished\n");
#endif
        matvdrv_cb_param=NULL;
	RegisterChScanCB(NULL,
			NULL,
			NULL);						
	RegisterAudNotifyCB(NULL);

	matv_kal_give_sem();

#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_shutdown Out");
#endif	
		
	return 	ret;
}

kal_bool matvdrv_ps_init(kal_bool on)
{
	//int ret;
	return KAL_TRUE;     //////don't need set  power saving mode in 5193
/*			#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "matvdrv_ps_init() begin\n");
			#endif
	if (bAtv_IsSleepHandleInit == 0)  
	{
		atv_slp_handle = L1SM_GetHandle ();
		bAtv_IsSleepHandleInit = KAL_TRUE;
	}
	L1SM_SleepDisable(atv_slp_handle); 
	kal_sleep_task(kal_milli_secs_to_ticks(20)); // need delay 20ms before MT5192 power-on  for clock stable
	#if (defined(MT6223P)||defined(MT6223)||defined(__DIRECT_SENSOR_V2_SUPPORT__))
	if(on)
	{
		if(matvdrv_poweron_seq(1))
		{
			bChipInit(2);
		}
	}
	#else
	if(on)
	{
		if(matvdrv_poweron_seq(1))
		{
			bChipInit(2);
		}
	}
	else
	{
		 matvdrv_poweroff_seq();
	}
	#endif
	if (bAtv_IsSleepHandleInit == 0)  
	{
		atv_slp_handle = L1SM_GetHandle ();
		bAtv_IsSleepHandleInit = KAL_TRUE;
	}	 
	L1SM_SleepEnable(atv_slp_handle);  
		#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "matvdrv_ps_init() finished\n");
	#endif
	return KAL_TRUE;*/
}
#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif
#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_MATVDRIVER_ROCODE", rodata = "DYNAMIC_CODE_MATVDRIVER_ROCODE"
#endif
/////////////////////////////////////////////////////////////////////////////
//TTS table
/////////////////////////////////////////////////////////////////////////////
typedef struct
{
	kal_uint32 SpurFreq;
	kal_uint16 CVBSNoiseEnter_EQOn;
	kal_uint16 CVBSNoiseBack_EQOn;
	kal_uint16 CVBSNoiseEnter_EQOff;
	kal_uint16 CVBSNoiseBack_EQOff;
} TTS_Script_T;

TTS_Script_T const TTS_Table[] =
{
//Common Table
{ 78000,	6000,	2000,	5000,	1000},
{182000,	6000,	2000,	5000,	1000},
{208000,	6000,	2000,	5000,	1000},
{520000,	6000,	2000,	5000,	1000},
{624000,	6000,	2000,	5000,	1000},
{676000,	6000,	2000,	5000,	1000},
{702000,	6000,	2000,	5000,	1000},
{728000,	6000,	2000,	5000,	1000},
{780000,	6000,	2000,	5000,	1000},
{832000,	6000,	2000,	5000,	1000},
{     0,	   0,	   0,      0,	   0}
};

/////////////////////////////////////////////////////////////////////////////
//ch scan/control
/////////////////////////////////////////////////////////////////////////////

enum {
	BG_LIKE=0,
	DK_LIKE,
	I_LIKE,
	L_LIKE,
	L1_LIKE,
	M_LIKE,
}; // assosiate  to abScanRoadMap

#define Freq2DR(freqkhz)		(kal_uint16)((freqkhz*2)/125) //(freqkhz*16)/1000

struct UniSystemChMap{
	kal_uint8  start_ch;
	kal_uint8  end_ch;
	kal_uint16  start_DR;
	kal_uint16  end_DR;
	kal_uint16  bandwidth_DR;
	kal_uint8 sndsys;
	kal_uint8 colsys;
};

#define UNICHMAP(start_ch,end_ch,start_freq,end_freq,bandwidth_freq) \
	{ start_ch, end_ch, Freq2DR(start_freq),Freq2DR(end_freq),Freq2DR(bandwidth_freq),0,0}

#define ADHOCCHMAP(start_ch,end_ch,start_freq,end_freq,bandwidth_freq,sndsys,colsys) \
	{ start_ch, end_ch, Freq2DR(start_freq),Freq2DR(end_freq),Freq2DR(bandwidth_freq),sndsys,colsys}
	
struct chscan_method {
	const char * description;
	kal_uint8 BSystem;
	kal_uint8 SndSystem;
	kal_uint8 ColorSystem;
	kal_uint8 UniSystem;
	const struct UniSystemChMap * UniChTab;	
};


const struct UniSystemChMap NA_AIR[]=
	{	//NA_AIR
		UNICHMAP(2,4,55250,67250,6000), //VHF
		UNICHMAP(5,6,77250,83250,6000), //VHF
		UNICHMAP(7,13,175250,211250,6000), //VHF
		UNICHMAP(14,69,471250,801250,6000), //UHF
		UNICHMAP(0,0,0,0,0) //end of table
	};
const struct UniSystemChMap JP_AIR[]=
	{	//JP_AIR
		UNICHMAP(1,3,91250,103250,6000), //VHF
		UNICHMAP(4,7,171250,189250,6000), //VHF
		UNICHMAP(8,12,193250,217250,6000), //VHF
		UNICHMAP(13,62,471250,765250,6000), //UHF
		UNICHMAP(0,0,0,0,0) //end of table
	};

/* Russia & Eastern Europe*/
const struct UniSystemChMap RU_AIR[]=
	{	//RU_AIR
		UNICHMAP(1,2,49750,59250,9500), //VHF
		UNICHMAP(3,5,77250,93250,8000), //VHF
		UNICHMAP(6,12,175250,223250,8000), //VHF
		UNICHMAP(21,69,471250,855250,8000), //UHF
		UNICHMAP(0,0,0,0,0) //end of table
	};
	
/* Western Europe */
const struct UniSystemChMap WE_AIR[]=
	{	//WE_AIR	
		UNICHMAP(2,4,48250,62250,7000), //VHF
		UNICHMAP(5,12,175250,224250,7000), //VHF
		UNICHMAP(21,69,471250,855250,8000), //UHF
		UNICHMAP(0,0,0,0,0) //end of table
	};

/* UK */
const struct UniSystemChMap UK_AIR[]=
	{	//UK_AIR
		UNICHMAP(2,4,46250,62250,8000), //VHF
		UNICHMAP(5,13,175250,239250,8000), //VHF
		UNICHMAP(21,69,471250,855250,8000), //UHF
		UNICHMAP(0,0,0,0,0) //end of table
	};
/* China */
const struct UniSystemChMap CN_AIR[]=
	{	//CN_AIR
		UNICHMAP(1,3,49750,65750,8000), //VHF
		UNICHMAP(4,5,77250,85250,8000), //VHF
		UNICHMAP(6,12,168250,216250,8000), //VHF
		UNICHMAP(13,24,471250,559250,8000), //UHF
		UNICHMAP(25,59,607250,879250,8000), //UHF
		UNICHMAP(0,0,0,0,0) //end of table
	};
/* Vietnam */
const struct UniSystemChMap VN_AIR[]=
	{	//VN_AIR
		UNICHMAP(2,3,49750,59750,10000), //VHF
		UNICHMAP(4,5,77250,85250,8000), //VHF
		UNICHMAP(6,12,175250,223250,8000), //VHF
		UNICHMAP(21,69,471250,855250,8000), //UHF
		UNICHMAP(0,0,0,0,0) //end of table
	};
/* Italy*/
const struct UniSystemChMap IT_AIR[]=
	{	//IT_AIR - 7MHz channel
		UNICHMAP(1,2,53750,62250,8500), //VHF -sparse
		UNICHMAP(3,4,82250,175250,93000), //VHF -sparse
		UNICHMAP(5,6,183750,192250,8500), //VHF -sparse
		UNICHMAP(7,8,201250,210250,9000), //VHF -sparse
		UNICHMAP(9,10,217250,224250,7000), //VHF -sparse
		UNICHMAP(21,62,471250,799250,8000), //UHF
		UNICHMAP(0,0,0,0,0) //end of table
	};
/*Australia*/
const struct UniSystemChMap AU_AIR[]=
	{	//AU_AIR - 7MHz channel
		UNICHMAP(0,1,46250,57250,11000), //VHF -sparse
		UNICHMAP(2,3,64250,86250,22000), //VHF -sparse
		UNICHMAP(4,5,95250,102250,7000), //VHF -sparse
		UNICHMAP(6,6,138250,138250,7000), //VHF
		UNICHMAP(7,10,175250,196250,7000), //VHF
		UNICHMAP(11,13,209250,223250,7000), //VHF
		UNICHMAP(28,69,527250,814250,7000), //UHF
		UNICHMAP(0,0,0,0,0) //end of table
	};
/* New Zealand */
const struct UniSystemChMap NZ_AIR[]=
	{	//NZ_AIR
		UNICHMAP(1,1,45250,45250,7000), //VHF
		UNICHMAP(2,3,55250,62250,7000), //VHF
		UNICHMAP(4,11,175250,224250,7000), //VHF
		UNICHMAP(28,69,527250,814250,7000), //UHF
		UNICHMAP(0,0,0,0,0) //end of table
	};
/* Morocco */
const struct UniSystemChMap MA_AIR[]=
	{	//MA_AIR
		UNICHMAP(4,10,163250,211250,8000), //VHF
		UNICHMAP(21,69,471250,855250,8000), //UHF
		UNICHMAP(0,0,0,0,0) //end of table
	};
/* South Africa */
const struct UniSystemChMap ZA_AIR[]=
	{	//ZA_AIR
		//UNICHMAP(1,1,43250,43250,8000), //VHF
		UNICHMAP(2,4,46250,62250,8000), //VHF
		UNICHMAP(5,13,175250,239250,8000), //VHF
		UNICHMAP(21,69,471250,855250,8000), //UHF
		//UNICHMAP(21,81,471250,951250,8000), //UHF
		UNICHMAP(0,0,0,0,0) //end of table
	};
/* France */
const struct UniSystemChMap FR_AIR[]=
	{	//FR_AIR
		UNICHMAP(2,3,55750,60500,4750), //VHF
		UNICHMAP(4,4,63750,63750,8000), //VHF
		UNICHMAP(5,10,176000,216000,8000), //VHF
		UNICHMAP(21,69,471250,855250,8000), //UHF
		UNICHMAP(0,0,0,0,0) //end of table
	};
/* French oversea,French African colonies */
const struct UniSystemChMap FR2_AIR[]=
	{	//FR2_AIR
		UNICHMAP(2,3,52250,60250,8000), //VHF
		UNICHMAP(4,9,175250,215250,8000), //VHF
		UNICHMAP(21,69,471250,855250,8000), //UHF
		UNICHMAP(0,0,0,0,0) //end of table
	};
/* USA Cabe IRC */
const struct UniSystemChMap NA_IRC[]=
	{	//NA_IRC
//		UNICHMAP(1,1,73250,73250,6000), //VHF
		UNICHMAP(2,4,55250,67250,6000), //VHF
		UNICHMAP(5,6,77250,83250,6000), //VHF
		UNICHMAP(7,13,175250,211250,6000), //VHF
		UNICHMAP(14,22,121250,169250,6000), //VHF
		UNICHMAP(23,94,217250,643250,6000), //VHF,UHF
//		UNICHMAP(95,99,91250,115250,6000), //VHF
		UNICHMAP(100,158,649250,997250,6000), //UHF
		UNICHMAP(0,0,0,0,0) //end of table
	};
/* USA Cabe HRC */
const struct UniSystemChMap NA_HRC[]=
	{	//NA_HRC
//		UNICHMAP(1,1,72000,72000,6000), //VHF
		UNICHMAP(2,4,54000,66000,6000), //VHF
		UNICHMAP(5,6,76000,82000,6000), //VHF
		UNICHMAP(7,13,174000,210000,6000), //VHF
		UNICHMAP(14,22,120000,168000,6000), //VHF
		UNICHMAP(23,94,216000,642000,6000), //VHF,UHF
//		UNICHMAP(95,99,90000,114000,6000), //VHF
		UNICHMAP(100,158,648000,996000,6000), //UHF
		UNICHMAP(0,0,0,0,0) //end of table
	};
/* Ireland */
const struct UniSystemChMap IE_AIR[]=
	{	//IE_AIR
		UNICHMAP(1,3,45750,61750,8000), //VHF
		UNICHMAP(4,13,175250,247250,8000), //VHF
		UNICHMAP(21,69,471250,855250,8000), //UHF
		UNICHMAP(0,0,0,0,0) //end of table
	};
/* Lab signal */
const struct UniSystemChMap LAB_AIR[]=
	{	//IE_AIR
		ADHOCCHMAP(1,1,77250,77250,8000,SV_PAL_DK,SV_CS_PAL), //VHF DK
		ADHOCCHMAP(2,2,120000,120000,8000,SV_SECAM_L,SV_CS_SECAM), //VHF		
		ADHOCCHMAP(4,13,175250,247250,8000,SV_PAL_BG,SV_CS_SECAM), //VHF BG
		UNICHMAP(14,14,256250,256250,8000), //VHF BG
		UNICHMAP(15,15,448250,448250,8000), //VHF BG
		ADHOCCHMAP(16,16,495250,495250,7000,SV_PAL_I,SV_CS_PAL), //UHF
		ADHOCCHMAP(17,17,543250,543250,7000,SV_PAL_I,SV_CS_PAL), //UHF
		ADHOCCHMAP(18,18,808250,808250,7000,SV_PAL_I,SV_CS_PAL), //UHF
		UNICHMAP(0,0,0,0,0) //end of table
	};
const struct chscan_method ChCountryTab[]=
{
	{"West EU(PAL-BG)",BG_LIKE,SV_A2_BG,SV_CS_PAL,1,WE_AIR},
	{"West EU(PAL-DK)",DK_LIKE,SV_A2_DK1,SV_CS_PAL,1,WE_AIR},
	{"East EU(PAL-DK)",DK_LIKE,SV_A2_DK1,SV_CS_PAL,1,RU_AIR},	
	{"Russia(SECAM-DK)",DK_LIKE,SV_PAL_DK,SV_CS_SECAM,1,RU_AIR},
	{"UK(PAL-I)",I_LIKE,SV_PAL_I,SV_CS_PAL,1,UK_AIR},
	{"Italy(PAL-BG)",BG_LIKE,SV_A2_BG,SV_CS_PAL,1,IT_AIR},
	{"France(SECAM-L)",L_LIKE,SV_SECAM_L,SV_CS_SECAM,1,FR_AIR},
	{"FrenchOversea(SECAM-DK)",DK_LIKE,SV_SECAM_DK,SV_CS_SECAM,1,FR2_AIR},
	{"US(NTSC-M)",M_LIKE,SV_MTS,SV_CS_NTSC358,1,NA_AIR},
	{"Korea(NTSC-M)",M_LIKE,SV_MTS,SV_CS_NTSC358,1,NA_AIR},
	{"Japan(NTSC-M)",M_LIKE,SV_MTS,SV_CS_NTSC358,1,JP_AIR},
	{"China(PAL-DK)",DK_LIKE,SV_PAL_DK_FMMONO,SV_CS_PAL,1,CN_AIR},
	{"Brazil(PAL-M)",M_LIKE,SV_MTS,SV_CS_PAL_M,1,NA_AIR},
	{"Uruguay(PAL-N)",M_LIKE,SV_MTS,SV_CS_PAL_N,1,NA_AIR},
	{"Argentina(PAL-Nc)",M_LIKE,SV_MTS,SV_CS_PAL_N,1,NA_AIR},
	{"SouthernAfrica(PAL-I)",I_LIKE,SV_PAL_I,SV_CS_PAL,1,ZA_AIR},
	{"Australia(PAL-BG)",BG_LIKE,SV_A2_BG,SV_CS_PAL,1,AU_AIR},
	{"NewZealand(PAL-BG)",BG_LIKE,SV_PAL_BG,SV_CS_PAL,1,NZ_AIR},
	{"IRC(NTSC-M)",M_LIKE,SV_MTS,SV_CS_NTSC358,1,NA_IRC},
	{"HRC(NTSC-M)",M_LIKE,SV_MTS,SV_CS_NTSC358,1,NA_HRC},
	{"Vietnam(PAL-DK)",DK_LIKE,SV_A2_DK1,SV_CS_PAL,1,VN_AIR},
	{"Iran(SECAM-BG)",BG_LIKE,SV_A2_BG,SV_CS_SECAM,1,WE_AIR},
	{"Ireland(PAL-I)",I_LIKE,SV_PAL_I,SV_CS_PAL,1,IE_AIR},
	{"Morocco(SECAM-BG)",BG_LIKE,SV_A2_BG,SV_CS_SECAM,1,MA_AIR},
	{"SZ,HK(PAL-I)",I_LIKE,SV_PAL_I_FMMONO,SV_CS_PAL,1,UK_AIR},
	{"West EU(PAL-BG)(NICAM)",BG_LIKE,SV_PAL_BG,SV_CS_PAL,1,WE_AIR},
	{"Lab signal(PAL-BG)",BG_LIKE,SV_PAL_BG,SV_CS_PAL,1,LAB_AIR}
};
#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif
#define CHSCAN_METHODTAB_SIZE (sizeof(ChCountryTab)/sizeof(struct chscan_method))
kal_uint16 ChCountryTab_Size=CHSCAN_METHODTAB_SIZE;
struct UniSystemChMap * ChScanUniChTab=(struct UniSystemChMap *)WE_AIR;//ChCountryTab[CHSCAN_COUNTRY_DEFAULT].UniChTab;

#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_MATVDRIVER_ROCODE", rodata = "DYNAMIC_CODE_MATVDRIVER_ROCODE"
#endif
static const kal_uint8 countrymap[TV_COUNTRY_MAX]=
{
	0,14,16,12,8,
	0,8,8,11,24,
	24,2,0,6,7,
	0,25,21,5,10,
	9,0,0,8,17,
	0,13,8,0,3,
	25,15,25,8,0,
	0,0,4,8,13,
	8,20,22,23
};
#if defined(MT6250)
typedef struct
{
	kal_uint32	CHFreq;
    kal_uint8  MpllHopping;

} MPLL_Script_T;


MPLL_Script_T const MpllHopping_Table[] =
{
{0,	 0 }
};
#endif
#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

kal_uint8 ScanCountry=0;

#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#pragma arm section code = "DYNAMIC_CODE_MATVDRIVER_ROCODE", rodata = "DYNAMIC_CODE_MATVDRIVER_ROCODE"
#endif
void matvdrv_set_country(kal_uint8 country)
{
#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_set_country In");
#endif

	matv_kal_take_sem();

	if(country<TV_COUNTRY_MAX)
	{
        ScanCountry=country;
	vChSetCountryID(countrymap[country]);
}
	matv_kal_give_sem();
#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_set_country Out");
#endif		
}

#define MIN_FREQ_DR			Freq2DR(45250)
#define MAX_FREQ_DR			Freq2DR(870250)
void matvdrv_chscan(kal_uint8 mode)
{
#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_chscan In");
#endif	
	matv_kal_take_sem();

	switch(mode)
	{
		case MATV_AUTOSCAN:
			vChSearchInit(MIN_FREQ_DR, CHINS_AUTO);
			break;
		case MATV_FULLSCAN:
			vChSearchInit(MIN_FREQ_DR, CHINS_FULLSCAN);
			break;
		case MATV_QUICKSCAN:
			vChQuickInstall();
			break;
	}	
	//matvdrv_suspend(KAL_TRUE);
	bChipSuspend(KAL_TRUE);

	matv_kal_give_sem();	
#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_chscan Out");
#endif	
}

void matvdrv_chscan_stop(void)
{
#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_chscan_stop In");
#endif	
	matv_kal_take_sem();
	vChSearchStop();
	matv_kal_give_sem();		
#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_chscan_stop Out");
#endif		
}

kal_bool matvdrv_get_chtable(kal_uint8 ch, matv_ch_entry *entry)
{
	struct ChRec  rec;	
	kal_bool ret;
#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_get_chtable In");
#endif	
	matv_kal_take_sem();
	
	if(entry&&bChTab_Get(ch,&rec))
	{
		entry->freq=DR2Freq_Fn(rec.freqDR);
		entry->sndsys=rec.sndsys;
		entry->colsys=rec.colsys;
		entry->flag=rec.flag;
		//return KAL_TRUE;
		ret = KAL_TRUE;
	}	
	else
		ret = KAL_FALSE;

	matv_kal_give_sem();	

#ifdef MATV_DRV_DEBUG		
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_get_chtable Out");
#endif		
	//return KAL_FALSE;
	return ret;	
}

kal_bool matvdrv_set_chtable(kal_uint8 ch, matv_ch_entry *entry)
{
	struct ChRec  rec;
	kal_bool ret;

#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_set_chtable In");
#endif
	
	matv_kal_take_sem();
	
	if(entry)
	{
		rec.freqDR=Freq2DR(entry->freq);
		rec.sndsys=entry->sndsys;
		rec.colsys=entry->colsys;
		rec.flag=entry->flag;
		
		//return bChTab_Set(ch,&rec);
	       ret = bChTab_Set(ch,&rec);
	}
	else ret = KAL_FALSE;

	matv_kal_give_sem();	

#ifdef MATV_DRV_DEBUG				
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_set_chtable Out");			
#endif
		
//	return KAL_FALSE;
	return ret;
}

kal_bool matvdrv_clear_chtable(void)
{
	kal_bool ret;

#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_clear_chtable In");
#endif
		
	matv_kal_take_sem();
	ret = bChTab_ClearAll();
	matv_kal_give_sem();	

#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_clear_chtable Out");
#endif	
	//return bChTab_ClearAll();
	return ret;
}

#if (defined(MT6252H) || defined(MT6252))
kal_uint8 prech=0xff;
kal_uint8 curch=0;
extern kal_uint8 CountDropPixel;
#endif
void matvdrv_change_channel(kal_uint8 ch)
{
#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_change_channel In");
#endif

	matv_kal_take_sem();

    #if (defined(MT6252H) || defined(MT6252))
    curch=ch;
	prech=curch;
	CountDropPixel=0;
	#endif
	vChChg(ch);
	matv_kal_give_sem();		
#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_change_channel Out");
#endif	
}



/////////////////////////////////////////////////////////////////////////////
//AUDIO
/////////////////////////////////////////////////////////////////////////////	
void matvdrv_audio_play(void)
{
#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_audio_play In");
#endif	
	matv_kal_take_sem();
	vApiAudioPlay(1);
	matv_kal_give_sem();
#ifdef MATV_DRV_DEBUG				
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_audio_play Out");
#endif	
}

void matvdrv_audio_stop(void)
{
#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_audio_stop In");
#endif
	matv_kal_take_sem();
	vApiAudioStop();
	matv_kal_give_sem();
#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_audio_stop out");
#endif	
}

kal_uint32 matvdrv_audio_get_format(void)
{
       kal_uint32 ret;
#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_audio_get_format In");
#endif	   
	matv_kal_take_sem();
	ret = dwApiAudioGetFormatSrc();
	matv_kal_give_sem();
#ifdef MATV_DRV_DEBUG		
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_audio_get_format Out");
#endif	
	return ret;
	//return dwApiAudioGetFormatSrc();
}

void matvdrv_audio_set_format(kal_uint32 val)
{
#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_audio_set_format In");
#endif
	matv_kal_take_sem();
	vApiAudioSetAtvOutputMode(val);
	matv_kal_give_sem();
#ifdef MATV_DRV_DEBUG
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_audio_set_format Out");
#endif	
}

kal_uint8 matvdrv_audio_get_sound_system(void)
{
       kal_uint8 ret;
#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_audio_get_sound_system In");
#endif	   
	matv_kal_take_sem();
	ret = bApiAudioGetSoundSystem(0);
	matv_kal_give_sem();
#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_audio_get_sound_system Out");
#endif	
	return ret;
//	return bApiAudioGetSoundSystem(0);
}

kal_uint8 matvdrv_audio_get_fm_detect_status(kal_uint32 *qulity)
{
       kal_uint8 ret;
#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_audio_get_fm_detect_status In");
#endif	   
	matv_kal_take_sem();
       ret = bApiAudioGetFmRdoDetectStatus((kal_uint32*)qulity);
	matv_kal_give_sem();
#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_audio_get_fm_detect_status Out");
#endif	
	return ret;
//	return bApiAudioGetFmRdoDetectStatus((kal_uint32*)qulity);
}

/////////////////////////////////////////////////////////////////////////////
//Common adjust for Video/Audio
/////////////////////////////////////////////////////////////////////////////

kal_bool matvdrv_adjust(kal_uint8 item,kal_int32 val)
{
#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_adjust In, item=%d, value=%d",item, val);
#endif
	matv_kal_take_sem();

	 /*UI contrast/brightness 8/128/248 */
	switch(item)
	{
		case MATV_AUD_VOLUME:
			/* mapping 0/128/255 to 0/64/127 */
			vApiAudioSetMasterVolume(val/2);
			break;
		case MATV_VDO_BRIGHTNESS:
			/* mapping 0/128/255 to -255/0/255 */
			val-=128;
			if(val>=0)
				vApiVideoPosBrightness(1,(val*255)/127);
			else
				vApiVideoPosBrightness(0,(-val*255)/128);			
			break;
		case MATV_VDO_CONTRAST:
			/* mapping 0/128/255 to 13(0xd)/38(0x26)/63(0x3f) +/-25 */
			vApiVideoContrast(38+(val-128)*25/127);			
			/* mapping 0/128/255 to 0/0x20/0x3f */
			//vApiVideoContrast(val/4);
			break;
		case MATV_VDO_SATURATION:
			vApiVideoSaturation(val/4);
			break;
	}
	matv_kal_give_sem();					

#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_adjust Out, return=%d",return_value);
#endif		
	return KAL_TRUE;
}

/////////////////////////////////////////////////////////////////////////////
//Chip/Vendor dependent
/////////////////////////////////////////////////////////////////////////////
kal_int32 matvdrv_get_chipdep(kal_uint8 item)
{
       kal_int32 ret;
#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_get_chipdep In, item=%d",item);
#endif	   
	matv_kal_take_sem();

	ret =DrvGetChipDep(item); //TODO
	
	matv_kal_give_sem();					
#ifdef MATV_DRV_DEBUG
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_get_chipdep Out, return=%d",return_value);
#endif
       return ret;
	//return DrvGetChipDep(item); //TODO
}

extern kal_uint8 cli_init(DCL_DEV port);

kal_bool matvdrv_set_chipdep(kal_uint8 item,kal_int32 val)
{
       kal_bool ret;

#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_set_chipdep In, item=%d, value=%d",item, val);
#endif	   
	matv_kal_take_sem();

	switch(item)
	{
		case MTK_CLI_PORT:
				cli_init((DCL_DEV)val);
		default:
			//return DrvSetChipDep(item,val);
			ret = DrvSetChipDep(item,val);
	}
	matv_kal_give_sem();					

#ifdef MATV_DRV_DEBUG	
	matv_wap_trace(MOD_MATV, TRACE_INFO, "[ATV] matv_set_chipdep Out, return=%d", return_value);
#endif	
	return ret;
}

kal_int32 matvdrv_get_framerate(void)
{
	kal_int32 temp;
	temp = matvdrv_get_chipdep(MTK_TVD_FrameRate);
//	temp /= 100;
	return (temp/100);
}

#if !defined(__ATV_RECORD_SUPPORT__) && defined(__MM_DCM_SUPPORT__)
#pragma arm section code, rodata
#endif

#endif /* __MTK_TARGET__ && __ATV_SUPPORT__ */   
