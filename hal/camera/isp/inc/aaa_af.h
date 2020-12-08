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
 *   aaa_af.h
 *
 * Project:
 * --------
 *   MT6238
 *
 * Description:
 * ------------
 *   Auto Focus Algorithm
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
#ifndef _AAA_AF_H_
#define _AAA_AF_H_

#include "kal_release.h"
#include "drv_features.h"
//#if (defined(ISP_SUPPORT)&&defined(DRV_ISP_6238_SERIES))
#include "isp_hw_feature_def.h"
//#if	(defined(RAW_MAIN_CAMERA))
#include "aaa_process.h"
#include "aaa_nvram.h"  // SC NV

//#define	AF_MAX_DEF_PATH_NO		(3)	// AF PATH NO in NVRAM // SC NV
#define	AF_MAX_STEP_NO			(24)
//#define	AF_MAX_TABLE_NO			(24)    // SC NV
#define	AF_MAX_STEP_TIME_NO		(12)
#define	AF_MAX_LEVEL			(5)

#define	AF_WIN_DEFAULT_WIDTH	(96)	// 96X80 for 640x480
#define	AF_WIN_DEFAULT_HEIGHT	(80)	// 112X96 for 800X600
#define AF_WIN_MIN_WIDTH		(48)
#define AF_WIN_MIN_HEIGHT		(48)
#define AF_WIN_MAX_WIDTH		(320)
#define AF_WIN_MAX_HEIGHT		(240)

#define AF_WIN0_WIDTH(width)	((1+((width+63)>>7))<<4)	// width*16/128	=> 640*16/128 = 80, 1024*16/128=128
#define AF_WIN0_HEIGHT(height)	((1+((height+63)>>7))<<4)	// height*16/128=> 480*16/128 = 60, 768*16/128=96

#define AF_FILTER_DEFAULT_THRE0	(2)
#define AF_FILTER_DEFAULT_THRE1	(10)
#define AF_FILTER_DEFAULT_THRE2	(12)
#define AF_FILTER_DEFAULT_THRE3	(20)
#define AF_FILTER_DEFAULT_THRE4	(30)

/* for programmable cont. af window usage */
#define	AF_WIN_CFG_X0_SHIFT	 0
#define	AF_WIN_CFG_X1_SHIFT	 4
#define	AF_WIN_CFG_X2_SHIFT	 8
#define	AF_WIN_CFG_X3_SHIFT	12
#define	AF_WIN_CFG_Y0_SHIFT	16
#define	AF_WIN_CFG_Y1_SHIFT	20
#define	AF_WIN_CFG_Y2_SHIFT	24
#define	AF_WIN_CFG_Y3_SHIFT	28


typedef enum
{
	AF_IDLE_MODE=0,
	AF_SINGLE_MODE,
	AF_MULTI_ZONE_MODE,	
	AF_CONTINUOUS_MODE,
	AF_MANUAL_MODE,		
	AF_FULL_SEARCH_MODE,	
	AF_RELEASE_MODE	
} AF_OPERATION_MODE_ENUM;

typedef enum
{
	AF_IDLE_STATE=0,		/*0*/
	AF_STANDBY_STATE,		/*1*/
	AF_INIT_STATE,			/*2*/
	AF_COLLECT_STATE,		/*3*/
	AF_SEARCH_STATE,		/*4*/
	AF_FREEZE_STATE,		/*5*/
	AF_READY_STATE,			/*6*/
	// Continuous State
	AF_DIR_DECIDE_INIT_STATE,/*7*/	
	AF_DIR_DECIDE_STATE,	/*8*/
	AF_MONITOR_STATE,		/*9*/
	AF_STATE_MAX_NO	
} AF_OPERATION_STATE_ENUM;

typedef enum
{
	AF_AUTO_RANGE=0,
	AF_MACRO_RANGE,
	AF_INFINITE_RANGE
}AF_SEARCH_RANGE_ENUM;

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

typedef enum
{
	AF_SWITCH_TO_MACRO_ENABLE=0,
	AF_SWITCH_TO_MACRO_DISABLE,
	AF_SWITCH_TO_MACRO_NO
}AF_SWITCH_TO_MACRO_ENUM;


typedef enum 
{
	AF_FILTER_SMD=0,
	AF_FILTER_TEND
} AF_FILTER_TYPE_ENUM;

enum
{
	ID_FOCUS_VALUE = 0,
	ID_FOCUS_POS,
	ID_FOCUS_NUM
};

typedef enum 
{
	SEARCH_STATUS_IDLE=0,
	SEARCH_STATUS_BUSY	,
	SEARCH_STATUS_FOUND_FAIL,    
	SEARCH_STATUS_FOUND_SUCCESS,
	SEARCH_STATUS_FOUND_NOFOCUS,
	SEARCH_STATUS_SWITCH_MACRO	
} AF_SEARCH_STATUS_ENUM;

typedef enum 
{
	AF_SCENARIO_PREVIEW_SINGLE_NORMAL =0,
	AF_SCENARIO_PREVIEW_SINGLE_LOWLIGHT,
	AF_SCENARIO_PREVIEW_CONTINUOUS_NORMAL,	
	AF_SCENARIO_PREVIEW_CONTINUOUS_LOWLIGHT,		
	AF_SCENARIO_PREVIEW_MULTI_NORMAL,	
	AF_SCENARIO_PREVIEW_MULTI_LOWLIGHT,	
	AF_SCENARIO_VIDEO_SINGLE_NORMAL,	
	AF_SCENARIO_VIDEO_SINGLE_LOWLIGHT,		
	AF_SCENARIO_VIDEO_CONTINUOUS_NORMAL,	
	AF_SCENARIO_VIDEO_CONTINUOUS_LOWLIGHT,	
	AF_SCENARIO_VIDEO_MULTI_NORMAL,		// Reserve, Not Support Yet
	AF_SCENARIO_VIDEO_MULTI_LOWLIGHT,	// Reserve, Not Support Yet		
	AF_SCENARIO_MAX_NO
} AF_SCENARIO_ENUM;

typedef enum
{
	AF_ZONE_0,
	AF_ZONE_1,
	AF_ZONE_2,
	AF_ZONE_3,
	AF_ZONE_4,			
	AF_ZONE_MAX_NO	
} AF_ZONE_ENUM;

enum
{
	AF_NORMAL_FV_MODE=0,
	AF_BLUR_FV_MODE,
	AF_FV_MODE_NO	
};

typedef struct
{
	kal_uint32		af_zone_w;
	kal_uint32		af_zone_h;
	kal_uint32		af_zone_x;
	kal_uint32		af_zone_y;			
} AF_ZONE_STRUCT, *P_AF_ZONE_STRUCT;

typedef struct
{	/* AF Window Setting */
	kal_uint32			af_active_zone;	
	AF_ZONE_STRUCT		af_zone[AF_ZONE_MAX_NO];	// for LCD display 
	AF_ZONE_STRUCT		af_window[AF_ZONE_MAX_NO];	// for ISP cal ATF 
}AF_ZONE_PARA_STRUCT, *P_AF_ZONE_PARA_STRUCT;

#define AF_DIR_DECIDE_FV_WIAT_FRAME 1
typedef struct
{
	kal_uint16 x0;
	kal_uint16 y0;
	kal_uint16 x1;
	kal_uint16 y1;
}AF_WIN_STRUCT, *P_AF_WIN_STRUCT;

typedef struct
{
	/*kal_uint8 obj_src_wd;*/ /* source image size for face detection or object tracking */
	/*kal_uint8 obj_src_ht;*/
	kal_bool ObjEnable;
	kal_bool SdEnable;
	kal_uint8 CounterCur;
	kal_uint8 CounterPre; 
	kal_uint8 ObjNoCur;
	kal_uint8 ObjNoPre;	
	kal_uint8 ObjLumaCur;
	kal_uint8 ObjLumaPre;	
	AF_WIN_STRUCT ObjWinCur;
	AF_WIN_STRUCT ObjWinPre;	
}AF_OBJ_DATA_STRUCT, *P_AF_OBJ_DATA_STRUCT;

typedef struct
{
	kal_uint32 cur_off_hi;
	kal_uint32 cur_off_lo; 
	kal_uint32 count_hi;
}AF_OBJ_SIZE_SENSTIVITY_STRUCT, *P_AF_OBJ_SIZE_SENSTIVITY_STRUCT;


/*******************************************************
    AF Auxiant LED Support
*******************************************************/
#define AF_AUXI_LED_SUPPORT 1 
#define AF_AUXI_LED_STABLE_CNT 1 // frame count to wait AF LED stable for ae cal
extern kal_uint8 afGetAuxiLedSupport(void);
extern kal_uint8 afGetAuxiLedAeIdxThr(void);
extern kal_uint8 afGetAuxiLedStatus(void);
extern void afSetAuxiLedStatus(kal_uint8 flag);
extern kal_uint8 afGetAuxiLedStableFrameCnt(void);
extern void AfSetAuxiLedOffContMode(kal_bool flag);
extern kal_bool AfGetAuxiLedOffContMode(void);
extern void AfAuxiLedMain(void);
extern void AfAuxiLedReset(void);
kal_bool AfGetStableFlag(void);
kal_uint16 AfGetLensPosition(void);
/********************************************************/

typedef struct
{	/* Customize Parameter Setting */
	kal_uint16	af_peak_threshold;  		// 0~256
	kal_uint16	af_nofocus_threshold;  		// 0~256	
	kal_uint16	af_stop_threshold;  		// 0~256		
	kal_uint16	af_hysteresis_threshold;  	// 0~256    
	kal_uint16	af_hysteresis_dir;  		// dir = 0:big->smaller, 1:small->bigger
	kal_uint16	af_slow_move_max_step; 		// 1~max_step_no		
	kal_uint16	af_slow_back_max_step; 		// 1~max_step_no			
	kal_uint16	af_wait_stable_threshold2;	// 0~256    
	kal_uint16	af_wait_stable_threshold3;	// 0~256    
	kal_uint16	af_startup_pos;  			// lens start up pos
	kal_uint16	af_startup_wait_frame;		// lens start up wait frames	
	kal_uint16	af_search_option;			// AF_SEARCH_OPTION_ENUM
	kal_uint16	af_cont_dd_step_ratio;			// 0~256 		
	kal_uint16	af_cont_dd_range_thre;  		// 0~256 			
	kal_uint16	af_cont_fv_delta;  			// 0~256 	//0828NEW			
	kal_uint16	af_cont_fv_blur;  			// 0~256 	//0828NEW		
	kal_uint16	af_cont_fv_delta_high;  		// 0~256 	
	kal_uint16	af_cont_fv_delta_low;  			// 0~256 
	kal_uint16	af_cont_ae_delta_high; 			// 0~255 (index)	
	kal_uint16	af_cont_ae_delta_low;  			// 0~255 (index)
	kal_uint16	af_cont_wait_stable_frame_ae;	// 0~65535 frames
	kal_uint16	af_cont_wait_stable_frame_fv_high;	// 0~65535 frames	
	kal_uint16	af_cont_wait_stable_frame_fv_low;	// 0~65535 frames		
	kal_uint16	af_cont_wait_stable_frame_freeze;	// 0~65535 frames		
	kal_uint16	af_cont_jump_count_thre;			// 0~255 frames (refocus)
	kal_uint16	af_cont_wait_stable_frame_max;	// 0~65535 frames, 30 mins	
	kal_uint16	af_mz_inf_dof;	//mz inf dof
	kal_uint16	af_mz_macro_dof;	//mz macro dof
	kal_uint16	af_cont_pan_luma_delta;			// 0~1024, //0832new
	kal_uint16	af_cont_pan_hold_frame;			// 0~, //0832new
	kal_uint16	af_cont_pan_over_speedup;       // 0~255, //0832new
	kal_uint16  af_cont_window_config_x;// 0~65535, //0832new
	kal_uint16  af_cont_window_config_y;// 0~65535, //0832new
	kal_uint16  af_cont_stop_search_config;//0836new	
	kal_uint16  af_window_size_level_config;// 2~5, //0836new
}AF_OPERATION_PARA_STRUCT, *P_AF_OPERATION_PARA_STRUCT;

typedef struct {
	/* Search Result */
	kal_uint8	af_search_result;	// AF_SEARCH_STATUS_ENUM
	kal_uint32	af_search_num;		
	kal_uint32	af_search_best;
	kal_uint32	af_success_zone;
    kal_uint32	af_search_power;
} AF_RESULT_STRUCT, *P_AF_RESULT_STRUCT;

typedef struct
{	
	/* AF Window Setting */
	kal_uint16 wind_grab_width;
	kal_uint16 wind_grab_height;
	kal_uint16 wind_result_start_x;
	kal_uint16 wind_result_start_y;
	kal_uint16 wind_result_width;
	kal_uint16 wind_result_height;
	kal_uint16 wind_target_width;
	kal_uint16 wind_target_height;
	kal_uint16 wind_fd_start_x;
	kal_uint16 wind_fd_start_y;	
	kal_uint16 wind_fd_end_x;
	kal_uint16 wind_fd_end_y;
}AF_FD_ZONE_WIN_STRUCT, *P_AF_FD_ZONE_WIN_STRUCT;

extern kal_uint32	af_statistic[AF_ZONE_MAX_NO][AF_MAX_LEVEL];	/* af 5 window and 5 fv*/
extern kal_uint32 *afGetStatistic(kal_uint8 zone_id);
extern kal_uint32 afGetStatisticByThre(kal_uint8 zone_id, kal_uint8 thre_id);
extern void afRetrieveStatistic(void);
extern void AfMain(void);
extern kal_bool AfInit(void);
extern void AfInitPara(void);
extern void AfConfigWin( kal_uint16 srcW,kal_uint16 srcH, kal_uint16 resultStartX, kal_uint16 resultStartY, kal_uint16 resultW,kal_uint16 resultH, kal_uint16 targetW,kal_uint16 targetH );
extern kal_bool AfUpdateWin( kal_uint16 srcW,kal_uint16 srcH, kal_uint16 resultStartX, kal_uint16 resultStartY, kal_uint16 resultW,kal_uint16 resultH, kal_uint16 targetW,kal_uint16 targetH );
extern void AfExit(void);
extern void AfConfigCaptureSetting(void);
extern void AfCaptureStop(kal_uint8 snapshot_number);
extern void AfSetEnable(kal_bool flag);
extern kal_bool afIsEnable(void);
extern void afAeAwbPause(void);
extern void afRestoreAeAwb(void);
extern kal_bool afIsAeAwbPause(void);
extern void afSendResult(void);
void AfSetSwitchToMacroSupport(kal_uint8 flag);
kal_uint8 AfGetSwitchToMacroSupport(void);
/* Information Access*/
extern AF_RESULT_STRUCT *AfGetResult(void);
extern AF_OPERATION_PARA_STRUCT *AfGetOperationPara(void);
extern void AfUpdateZonePara(void);
extern AF_ZONE_PARA_STRUCT *AfGetZonePara(void);
extern AF_ZONE_PARA_STRUCT *AfGetSingleZonePara(void);
extern kal_uint32 afGetStepStableTick(kal_uint32 stepOffset);
extern kal_uint32 afGetStepStableMaxWaitFrameNo(void);
/* State machine and Mode Control Functions */
extern kal_uint8 AfGetMode(void);
extern void AfSetMode(kal_uint8 mode);
extern void AfActiveMode(void);
extern kal_uint8 AfGetState(void);
extern void AfSetState(kal_uint8 state);
extern kal_uint8 AfGetRange(void);
extern void AfSetRange(kal_uint8 range);
extern kal_uint8 AfGetFvMode(void);
extern void AfSetFvMode(kal_uint8 mode);
/* AF process function */ 
extern void afSingleProc(kal_bool releaseFlag);
extern void afMultizoneProc(kal_bool releaseFlag);
extern void afContinuousProc(kal_bool releaseFlag);
extern void afFullsearchProc(kal_bool releaseFlag);
extern void afManualProc(kal_bool releaseFlag);
extern void afCaptureEndRelease(void);
extern kal_uint16 afGetLensPosition(void);
/********************************/
/* AF debug info and log */
/********************************/
#define MAX_AF_TIME_LOG_COUNT	(20)
typedef enum 
{
	AF_TIME_LOG_START=0,
	AF_TIME_LOG_END	,
	AF_TIME_LOG_STATE,	
	AF_TIME_LOG_PROC_DUTY,	
	AF_TIME_LOG_NUM	
} AF_TIME_LOG_ENUM;
extern void afTimeLogStart(void);
extern void afTimeLogEnd(void);
extern kal_uint32 afTimeLogGetIdx(void);
extern void afSaveLog(char *buf_filename);

extern void AfExifUpdateMtkParaStruct(kal_uint32* pPara, kal_uint32 ParaSize);

/********************************/
/*		 Camera Parameter 		*/
/********************************/
typedef struct
{
	kal_bool	af_support;	
	kal_bool	single;
	kal_bool	multizone;
	kal_bool	continuous;
	kal_bool	range_auto;
	kal_bool	range_macro;
	kal_bool	range_landscape;		
}AF_PREVIEW_INFO_STRUCT, *P_AF_PREVIEW_INFO_STRUCT;

typedef struct
{
	kal_bool	af_support;		
	kal_bool	automode;
	kal_bool	multizone;
	kal_bool	continuous;
	kal_bool	range_auto;
	kal_bool	range_macro;
	kal_bool	range_landscape;		
}AF_VIDEO_INFO_STRUCT, *P_AF_VIDEO_INFO_STRUCT;

typedef struct
{
	AF_PREVIEW_INFO_STRUCT	preview_mode;
	AF_VIDEO_INFO_STRUCT	video_mode;
}AF_INFO_STRUCT, *P_AF_INFO_STRUCT;
#if 0 /* SC NV */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if 0 /* SC NV */
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
#if 0 /* SC NV */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if 0   /* SC NV */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
// AF step stable timing talbe
typedef struct {
	kal_uint32	step;	
	kal_uint32	tick;
}AF_TIMING_STRUCT, *P_AF_TIMING_STRUCT;

typedef struct
{
   	kal_uint32		step_no;
   	kal_uint32		max_frame_delay;
	AF_TIMING_STRUCT tick[AF_MAX_STEP_TIME_NO];	
}AF_LENS_TIMING_STRUCT, *P_AF_LENS_TIMING_STRUCT;
//extern AF_LENS_TIMING_STRUCT camera_lens_timing;

/* mz dof table */
//#define AF_MZ_DOF_MAX_NO 		(8) // SC NV
#define AF_MZ_DOF_LUT_STEP_IDX 	(0)
#define AF_MZ_DOF_LUT_MACRO_IDX (1)
#define AF_MZ_DOF_LUT_INF_IDX 	(2)
//#define AF_MZ_DOF_LUT_IDX_NO 	(3) // SC NV
#if 0 /* SC NV */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if 0 /* SC NV */
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
#endif
#if 0 /* SC NV */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
typedef struct
{
	AF_TABLE_RANGE_STRUCT	table_range;	
	AF_TABLE_STEP_STRUCT	table_step[AF_MAX_TABLE_NO];
}AF_LUT_STRUCT, *P_AF_LUT_STRUCT;

typedef struct
{
	kal_uint16		operationmode;
	kal_bool		videomode;
	kal_bool		lowlightmode;	
}AF_LUT_INFO_STRUCT, *P_AF_LUT_INFO_STRUCT;

extern AF_NVRAM_PARA_STRUCT *AfGetPara(void);
extern void AfSetPara(const AF_NVRAM_PARA_STRUCT *p_cam_af_para);
void AfInitOperationPara(AF_OPERATION_PARA_STRUCT *pPara);
extern AF_LUT_STRUCT *AfGetLut(void);
extern AF_LUT_STRUCT *AF_LUT; 

void AfSetRotate(kal_uint8 rot_flag);
kal_uint8 AfGetRotate(void);
extern kal_uint32 af_mz_lcd_width, af_mz_lcd_height;
kal_bool AfGetFocusStep(kal_uint32 *total_step,kal_uint32 *current_step);
void AfMainNull(void);


/* New for Facial AF */
extern void afCheckObjEvent(void);
extern kal_bool afGetObjFvRefocusEnable(void);
extern kal_uint16 afGetDirDecideWaitFrame(void);
extern kal_uint8 afGetObjSizeSentivityThr(void);
extern AF_OBJ_SIZE_SENSTIVITY_STRUCT *afGetObjSizeSentivityPara(void);
extern kal_uint16 afGetObjFvSentivityPara(void);
extern AF_OBJ_DATA_STRUCT *AfGetObjData(void);
extern AF_FD_ZONE_WIN_STRUCT *AfGetObjWinCfg(void);
extern kal_bool AfUpdateWinByObjDynamic(kal_uint16 srcW,kal_uint16 srcH, kal_uint16 resultStartX, kal_uint16 resultStartY, kal_uint16 resultW,kal_uint16 resultH, kal_uint16 targetW,kal_uint16 targetH ,AF_OBJ_DATA_STRUCT *af_obj);
extern kal_bool AfGetWinChangeByObjFlag(void);
extern void AfSetWinChangeByObjFlag(kal_bool flag);
extern void AfUpdateWinCentral(void);
extern void afContObjSetAllowMonitorChangeAfWin(kal_bool flag);
extern kal_bool afContObjGetAllowMonitorChangeAfWin(void);


/**********************************************************START*/
/*********************AF Engineer mode start ******************/  // // move to aaa_af.h
#define AF_EM_CONT_SHOT_NO      (50)  // 50
#define AF_EM_BEST_BRACKET_OFFSET   (4) //(1)
#define AF_EM_FULL_SCAN_OFFSET    (4) //(1)
#define AF_EM_MAX_FRAME_NO 			(3)
#define AF_EM_MAX_BUFF_NO 			(64*4)
typedef struct {
	kal_bool	save_flag;
	kal_uint16	start;
	kal_uint16	end;
	kal_uint16	offset;
	kal_uint16	curr_pos;
}af_full_search_struct;
typedef struct {
	void *ptr_fv_buf;
	void *ptr_step_buf;
}af_em_buf_ptr_struct;

extern kal_uint32 AfEmbedMtkInfo(kal_uint32 *addr);
extern kal_bool AfSetEm(AAA_EM_IN_PARA_STRUCT *pInPara, AAA_EM_OUT_PARA_STRUCT *pOutPara);
extern kal_uint8 afGetEngineerMode(void);
extern kal_uint32 afGetEngineerIndex(void);
void afGetEMInfo(kal_uint32 *cont_shot_no, kal_uint32 *best_bracket_offset, kal_uint32 *full_scan_offset);
af_em_buf_ptr_struct AfGetEmBufPtr(void);
/*********************AF Engineer mode end ******************/

/**********************************************************END*/

#if(defined(__FACE_DETECTION_SUPPORT__))
AF_ZONE_PARA_STRUCT *get_fd_af_zone_para(void);
extern void afConfigFdWin(AF_FD_ZONE_WIN_STRUCT *fd_zone_para);
extern void afConfigFdWinDefault(void);
#endif

//#endif	/* RAW_MAIN_CAMERA */
#endif	// _AAA_AF_V2_H_

