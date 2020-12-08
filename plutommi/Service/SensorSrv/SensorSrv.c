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
*  SensorSrv.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  This file is intends for sensor service
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

#include "MMI_features.h"

#include "MMIDataType.h"
#include "custom_events_notify.h"
#include "mmi_frm_gprot.h"
#include "gui.h"        				/*	 UI timer */
#include "math.h"      			  /* atan */

#include "mdi_datatype.h"       /* mdi datatype */
#include "mdi_resdef.h"
#include "SensorSrvGport.h"

#include "common_nvram_editor_data_item.h"
#include "nvram_common_defs.h"

#include "stack_config.h"    
#include "kal_general_types.h"   
#include "kal_public_defs.h"    
#include "app_ltlcom.h"   
#include "kal_public_api.h"    
#include "DebugInitDef_Int.h"   
#include "MMI_media_app_trc.h"   
#include "mmi_media_app_trc.h"   
#include "kal_trace.h"   
#include "stack_msgs.h"   
#include "mmi_frm_events_gprot.h"   
#include "string.h"   
#include "stdlib.h"   
#include "mmi_frm_queue_gprot.h"   
#include "mmi_rp_srv_mdi_def.h"

#include "mmi_cb_mgr_gprot.h"
#include "GpioSrvGprot.h"



#ifdef __PXS_ENABLE__
#include "Drv_comm.h"
#include "mmi_rp_srv_sensor_def.h"
#include "dcl.h" /* for proximity */
#endif /* __PXS_ENABLE__ */

#ifdef MOTION_SENSOR_SUPPORT

#include "mmi_rp_srv_sensor_def.h"
#include "mcube_library_if.h"
#include "mcube_storage.h"

#ifdef __MTK_TARGET__
/* 
* - For PC Simulator and MoDis, do not call media's webcam functions 
* - For Target, call media's cam functions.
*/
#define MDI_MOTION_DRIVER_AVAIALBE
#endif /* __MTK_TARGET__ */ 

#endif /* MOTION_SENSOR_SUPPORT */

/***************************************************************************** 
* Include
*****************************************************************************/


#ifdef MOTION_SENSOR_SUPPORT

#ifdef MDI_MOTION_DRIVER_AVAIALBE
#include "motion_sensor.h"      /* motion sensor driver */
#endif 

#endif /* MOTION_SENSOR_SUPPORT */

/***************************************************************************** 
* Define
*****************************************************************************/
#ifdef MOTION_SENSOR_SUPPORT

#define MOTION_SUPPORT_APP_NUM                  (5)   /*the number of app can open motion*/
#define MOTION_SAMPLE_PERIOD                    (5)        /* value*10 ms, if 5 means 50 ms */
#define MOTION_THRESHOLD_FOR_DRV                0//(50)
#define MOTION_SHAKE_DET_MUTE_DURATION          (800)
#define MOTION_SHAKE_HISTORY_DEPTH              (5)

#define MOTION_DIRECT_DEBOUNCE                  (400)    /*It can be tune by customer*/

/* when sensitive is higher, threshold value smaller, 
* whihc means smaller action will trigger event  */
#define MOTION_SHAKE_THRESHOLD_HIGH             (500)
#define MOTION_SHAKE_THRESHOLD_NORMAL           (1000)
#define MOTION_SHAKE_THRESHOLD_LOW              (1500)

#define MOTION_TILE_THRESHOLD_HIGH              (10)
#define MOTION_TILE_THRESHOLD_NORMAL            (50)
#define MOTION_TILE_THRESHOLD_LOW               (100)
#define MOTION_ANGLE_SENS_HIGH_THRESHOLD        (45)
#define MOTION_ANGLE_SENS_NORMAL_THRESHOLD      (30)
#define MOTION_ANGLE_SENS_LOW_THRESHOLD         (20)

#define MOTION_ACC_G                            (980.0)
#define MOTION_ACC_G_THRESHOLD                  (100)
#define MOTION_ACC_G_THRESHOLD_AXIS             (300)
#define MOTION_SQUARE_G                         (MOTION_ACC_G * MOTION_ACC_G)
#define MOTION_SQUARE_G_THRESHOLD               (100 * 100)

#define MOTION_ERR_CALC_ANGLE_FAILED            (-1)
#define MOTION_ANGLE_180                        (180)
#define MOTION_ANGLE_90                         (90)
#define H_PI    (3.1415926/2)
#define PI      (3.1415926)

#define MOTION_ACC_G_CALI_THRESHOLD             (100)
#define MOTION_ACC_G_CALI_MIN                   (MOTION_ACC_G - MOTION_ACC_G_CALI_THRESHOLD)
#define MOTION_ACC_G_CALI_MAX                   (MOTION_ACC_G + MOTION_ACC_G_CALI_THRESHOLD)
#define MOTION_ACC_G_OFFSET_MAX                 (1 * 100)
#define MOTION_ACC_G_SCALE_MAX                  (1.20 * 10000.0)
#define MOTION_ACC_G_SCALE_MIN                  (0.8 * 10000.0)

#define MOTION_ENTER_PROTECT                    kal_take_mutex(g_srv_sensor_motion_cntx.mutex)
#define MOTION_EXIT_PROTECT                     kal_give_mutex(g_srv_sensor_motion_cntx.mutex)
#define MOTION_RUN_MOD                          MOD_MMI



#define MOTION_SUPPORT_MAX_MODE                 (10)


#endif /* MOTION_SENSOR_SUPPORT */

#ifdef __PXS_ENABLE__
#define SENSOR_PXS_FIRST_POLLING_TIME           (500)   /* ms */
#define SENSOR_PXS_REPEAT_POLLING_TIME          (200)   /* ms */
#endif

/***************************************************************************** 
* Typedef 
*****************************************************************************/
#ifdef MOTION_SENSOR_SUPPORT

/* This struct is for motion sensor mode(always on or others)*/
typedef struct
{
	U8 flag ;
	U8 mode ;
	SRV_SENSOR_HANDLE hdlr;

}srv_sensor_motion_mode_struct;


typedef enum
{
	MOTION_DATA_EPMTY,
	MOTION_DATA_FULL,
	MOTION_DATA_EXIST
} srv_sensor_motion_data_state_enum;

typedef struct
{
	S32 acc_x; /*real value * 100*/
	S32 acc_y;
} srv_sensor_motion_acc_history_struct;


typedef struct
{
	srv_sensor_motion_tilt_struct          tilt;                /*tilt data*/       
	void                            	   *tilt_user_data;

	srv_sensor_motion_shake_struct          shake;
	void                            	   *shake_user_data;

	srv_sensor_motion_direct_struct        direct;             	/*direct data*/
	void                                   *direct_user_data;

	SRV_SENSOR_EVENT_HDLR                  tilt_callback;
	SRV_SENSOR_EVENT_HDLR                  shake_callback;
	SRV_SENSOR_EVENT_HDLR                  direct_callback;

	srv_sensor_type_enum                   type;

	srv_sensor_motion_direct_cfg_struct    direct_sen;
	srv_sensor_motion_shake_cfg_struct     shake_sen;
	srv_sensor_motion_tilt_cfg_struct      tilt_sen;

	module_type                     	    mod_id;
	MMI_BOOL    is_msg_send;

	MMI_BOOL    is_shake;
	MMI_BOOL    is_tilt;
	MMI_BOOL    is_direct;

	srv_sensor_motion_direct_enum          prev_direct;


	srv_sensor_motion_tap_struct           		tap;    		 	/* Tap data */
	void                            	   		*tap_user_data;
	srv_sensor_motion_double_tap_struct    		double_tap;			/* double tap data */
	void                                   		*double_tap_user_data;
	srv_sensor_motion_advanced_shake_struct  	advanced_shake;     /* advanced shake */
	void                                     	*advanced_shake_user_data;
	srv_sensor_motion_turnover_struct           turnover;			/* turn over */
	void                                        *turnover_user_data;
	srv_sensor_motion_drop_struct               drop;				/* drop */
	void                                        *drop_user_data;


	SRV_SENSOR_EVENT_HDLR				   		tap_callback;  
	SRV_SENSOR_EVENT_HDLR				   		double_tap_callback; 
	SRV_SENSOR_EVENT_HDLR						advanced_shake_callback;
	SRV_SENSOR_EVENT_HDLR						turnover_callback;
	SRV_SENSOR_EVENT_HDLR						drop_callback;

	//#ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
	srv_sensor_motion_step_struct               step;				/* step */
	void                                        *step_user_data;
	SRV_SENSOR_EVENT_HDLR                       step_callback;
	MMI_BOOL	is_step;
	//#endif /*__MOTION_SENSOR_ADVANCED_GESTURE__*/

	MMI_BOOL    is_tap;
	MMI_BOOL    is_double_tap;
	MMI_BOOL    is_advanced_shake;
	MMI_BOOL    is_turnover;

	MMI_BOOL    is_drop;

} srv_sensor_motion_app_struct;

typedef struct
{
	LOCAL_PARA_HDR U16 data_state;
} srv_sensor_motion_msg_struct;


typedef struct
{
	LOCAL_PARA_HDR 
		srv_sensor_motion_cali_status_enum cali_status;
}srv_sensor_motion_cali_msg_struct;


/* This struct is for mcube sensor data */
typedef struct
{
	uint8_t status; 
	float mcube_acc_x;
	float mcube_acc_y;
	float mcube_acc_z;

	kal_uint64 timeStampMs; /*Time stamp*/

}sensor_srv_motion_mcube_sensor_data;


/*There will store the history action and direction*/
typedef struct
{
	srv_sensor_motion_action_enum   prev_action;   /*previous action*/
	srv_sensor_motion_direct_enum    prev_direct;   /*previous direction*/
	// mdi_motion_action_enum   prev2_action;  /*the previous action of previous*/
	// mdi_motion_angle_enum    prev2_direct;  /*the previous direction of previous*/
	// MMI_BOOL is_prev_action;                /*is has previous data*/
	// MMI_BOOL is_prev2_action;               /*is has previous data of previous*/
} srv_sensor_motion_direct_pre_action_struct;

/*Detail infomation of tilt detection*/
typedef struct 
{
	S32 angle_gx;   /*X angle related to acceleration of gravity, 0-180 and less then 0 means not support*/
	S32 angle_gy;   /*Y angle related to acceleration of gravity, 0-180 and less then 0 means not support*/
	S32 angle_gz;   /*Z angle 0-90(for hardware not support) and less then 0 means can't detect this time*/

	S16 acc_x; /*acc*10 at x axis*/
	S16 acc_y; /*acc*10 at y axis*/
	S16 acc_z; /*acc*10 at z axis*/
	MMI_BOOL is_support_acc_x;/*is sensor support acc at x axis*/
	MMI_BOOL is_support_acc_y;/*is sensor support acc at y axis*/
	MMI_BOOL is_support_acc_z;/*is sensor support acc at z axis*/

	sensor_srv_motion_mcube_sensor_data sensor_data;
} srv_sensor_motion_detail_struct;

typedef struct
{
	srv_sensor_motion_app_struct           app[MOTION_SUPPORT_APP_NUM];
	srv_sensor_motion_acc_history_struct   history[MOTION_SHAKE_HISTORY_DEPTH];
	srv_sensor_motion_detail_struct        detail_info;    
	kal_mutexid mutex;
	MMI_BOOL    is_shake_mute;
	MMI_BOOL    is_msg_send;
	MMI_BOOL    is_mute;	
} srv_sensor_motion_cntx_struct;


typedef struct
{
	SRV_SENSOR_HANDLE internal_handle;
	srv_sensor_type_enum app_type;
	SRV_SENSOR_HANDLE external_handle;			/*Interface handle for app*/ 

}srv_sensor_motion_handle_map;

#endif /* MOTION_SENSOR_SUPPORT */


#ifdef __PXS_ENABLE__

typedef void (* srv_sensor_pxs_set_val_func)(void *);


typedef struct
{
	srv_sensor_pxs_set_param_type_enum          pxs_set_type;
	srv_sensor_pxs_set_val_func      internal_set_handler;
}srv_sensor_pxs_set_map_tbl;

#endif /*__PXS_ENABLE__*/

/***************************************************************************** 
* const
*****************************************************************************/
#ifdef MOTION_SENSOR_SUPPORT

#define HANDLE_TAB_SIZE   sizeof(handle_tab)/sizeof(srv_sensor_motion_handle_map)


static const srv_sensor_motion_handle_map handle_tab[45] = 
{
	{0,SRV_SENSOR_MOTION_DIRECT,1},
	{0,SRV_SENSOR_MOTION_SHAKE,2},
	{0,SRV_SENSOR_MOTION_TILT,3},
	{0,SRV_SENSOR_MOTION_TAP,4},
	{0,SRV_SENSOR_MOTION_DOUBLE_TAP,5},
	{0,SRV_SENSOR_MOTION_DROP,6},
	{0,SRV_SENSOR_MOTION_STEP,7},
	{0,SRV_SENSOR_MOTION_ADVANCED_SHAKE,8},
	{0,SRV_SENSOR_MOTION_TURNOVER,9},

	{1,SRV_SENSOR_MOTION_DIRECT,10},
	{1,SRV_SENSOR_MOTION_SHAKE,11},
	{1,SRV_SENSOR_MOTION_TILT,12},
	{1,SRV_SENSOR_MOTION_TAP,13},
	{1,SRV_SENSOR_MOTION_DOUBLE_TAP,14},
	{1,SRV_SENSOR_MOTION_DROP,15},
	{1,SRV_SENSOR_MOTION_STEP,16},
	{1,SRV_SENSOR_MOTION_ADVANCED_SHAKE,17},
	{1,SRV_SENSOR_MOTION_TURNOVER,18},

	{2,SRV_SENSOR_MOTION_DIRECT,19},
	{2,SRV_SENSOR_MOTION_SHAKE,20},
	{2,SRV_SENSOR_MOTION_TILT,21},
	{2,SRV_SENSOR_MOTION_TAP,22},
	{2,SRV_SENSOR_MOTION_DOUBLE_TAP,23},
	{2,SRV_SENSOR_MOTION_DROP,24},
	{2,SRV_SENSOR_MOTION_STEP,25},
	{2,SRV_SENSOR_MOTION_ADVANCED_SHAKE,26},
	{2,SRV_SENSOR_MOTION_TURNOVER,27},

	{3,SRV_SENSOR_MOTION_DIRECT,28},
	{3,SRV_SENSOR_MOTION_SHAKE,29},
	{3,SRV_SENSOR_MOTION_TILT,30},
	{3,SRV_SENSOR_MOTION_TAP,31},
	{3,SRV_SENSOR_MOTION_DOUBLE_TAP,32},
	{3,SRV_SENSOR_MOTION_DROP,33},
	{3,SRV_SENSOR_MOTION_STEP,34},
	{3,SRV_SENSOR_MOTION_ADVANCED_SHAKE,35},
	{3,SRV_SENSOR_MOTION_TURNOVER,36},


	{4,SRV_SENSOR_MOTION_DIRECT,37},
	{4,SRV_SENSOR_MOTION_SHAKE,38},
	{4,SRV_SENSOR_MOTION_TILT,39}, 
	{4,SRV_SENSOR_MOTION_TAP,40},
	{4,SRV_SENSOR_MOTION_DOUBLE_TAP,41},
	{4,SRV_SENSOR_MOTION_DROP,42},
	{4,SRV_SENSOR_MOTION_STEP,43},
	{4,SRV_SENSOR_MOTION_ADVANCED_SHAKE,44},
	{4,SRV_SENSOR_MOTION_TURNOVER,45}
};

#endif /* MOTION_SENSOR_SUPPORT */

#ifdef __PXS_ENABLE__

static void srv_sensor_pxs_set_debounce(void *);  /*internal function, for set pxs debounce*/


srv_sensor_pxs_set_map_tbl g_sensor_srv_pxs_set_val_tab[SRV_SENSOR_PXS_PARAM_TYPE_TOTAL] = 
{
	{SRV_SENSOR_PXS_PARAM_TYPE_DEBOUNCE,    srv_sensor_pxs_set_debounce}
};

#endif /*__PXS_ENABLE__*/


/***************************************************************************** 
* Global Function
*****************************************************************************/
#ifdef MOTION_SENSOR_SUPPORT
srv_sensor_motion_cntx_struct g_srv_sensor_motion_cntx;
MMI_BOOL    g_motion_sensor_able;  /*If sensor is on enable mode,default is enable*/


MMI_BOOL g_is_reg_mcube = MMI_FALSE;    /* If MMI_TRUE, some APP have registered mCube */

MMI_BOOL g_is_power_on = MMI_FALSE;    

MMI_BOOL g_sub_init = MMI_TRUE;

srv_sensor_motion_mode_struct g_motion_sensor_tab[10] = {0};

srv_sensor_motion_flip_para_struct g_mcube_init ={MMI_TRUE,0.7,-0.3,0.4,1.2};

/* mcube init value 
g_mcube_init.flipEnable = MMI_TRUE;
g_mcube_init.flipFilter = 0.7;
g_mcube_init.flipThreshold = -0.3;
g_mcube_init.tFlipDebounce = 0.4;
g_mcube_init.tFlipInterval = 1.2;*/


S16 old_x,old_y,old_z;
S16 new_x = -10000, new_y = -10000, new_z = -10000;

/* Shake vs Direct */
srv_sensor_motion_direct_enum  g_direction = SRV_SENSOR_MOTION_ANGLE_OTHER;
srv_sensor_motion_direct_enum  g_old_direction = SRV_SENSOR_MOTION_ANGLE_OTHER;
srv_sensor_motion_direct_enum  g_real_direction = SRV_SENSOR_MOTION_ANGLE_OTHER;


#endif /* MOTION_SENSOR_SUPPORT */

/***************************************************************************** 
* Local Variable
*****************************************************************************/
#ifdef __PXS_ENABLE__

extern DCL_HANDLE g_pxs_handle = DCL_HANDLE_NONE;   /* for PXS */
/* If MSG_ID_SRV_SENSOR_PXS_DETECT_OBJECT_IND is already en-queued in MMI external queue, we don't need to send the primitive again */
static MMI_BOOL g_pxs_is_indication_in_queue = MMI_FALSE;

static U8 g_pxs_user_count = 0;
MMI_BOOL g_pxs_res_status = MMI_FALSE;


#endif /* __PXS_ENABLE__ */

/***************************************************************************** 
* Local Function
*****************************************************************************/
#ifdef MOTION_SENSOR_SUPPORT

#ifdef MDI_MOTION_DRIVER_AVAIALBE
static void srv_sensor_motion_data_hdlr(void *msg_ptr);
static void srv_sensor_motion_driver_data_state_hdlr(void *parameter, Motion_Sensor_BuffState_enum state);

#endif /* MDI_MOTION_DRIVER_AVAIALBE */ 

static SRV_SENSOR_RESULT srv_sensor_motion_add_to_slot(srv_sensor_type_enum type,
													   U8 sensitive,void(* callback)(),void * param,void * user_data);
static SRV_SENSOR_RESULT srv_sensor_motion_remove_from_slot(srv_sensor_type_enum type,SRV_SENSOR_HANDLE index);
static void srv_sensor_motion_reset_direct_data(srv_sensor_motion_direct_struct *tilt);
static void srv_sensor_motion_data_hdlr(void *msg_ptr);
static void srv_sensor_motion_update_hldr(void);
static void srv_sensor_motion_shake_add_to_history(srv_sensor_motion_acc_history_struct *history);
static void srv_sensor_motion_calc_angle_gxyz_by_xy(
	S32 int_x, S32 int_y, S32 int_z, 
	S32 *out_angle_gx, S32 *out_angle_gy, S32 *out_angle_gz);
static srv_sensor_motion_direct_enum
srv_sensor_motion_calc_axis_direct(U8 sensitive, S32 angle_gx, S32 angle_gy, S32 angle_gz, S32 acc_x, S32 acc_y);
static srv_sensor_motion_action_enum
srv_sensor_motion_calc_action(srv_sensor_motion_direct_enum old_direct, srv_sensor_motion_direct_enum new_direct);
static srv_sensor_motion_shake_action_enum srv_sensor_motion_calc_shake(srv_sensor_motion_acc_history_struct *history, 
																		srv_sensor_motion_shake_sensitive_enum sensitive);
static void srv_sensor_motion_push_direct2history(
	srv_sensor_motion_direct_enum motion_direct,
	srv_sensor_motion_app_struct *app_tilt);

//static MMI_BOOL srv_sensor_motion_is_around(S32 x, S32 point, S32 threshold);

static SRV_SENSOR_HANDLE srv_sensor_motion_get_external_handle(srv_sensor_type_enum type,SRV_SENSOR_HANDLE handle);

static void srv_sensor_motion_get_internal_handle(SRV_SENSOR_HANDLE handle, SRV_SENSOR_HANDLE *internal_handle, srv_sensor_type_enum *type);

//static MMI_BOOL srv_sensor_motion_is_normal_mode();

static void srv_sensor_motion_remove_mode(SRV_SENSOR_HANDLE handler);

static U16 srv_sensor_motion_check_mode();

static MMI_BOOL srv_sensor_no_have_mcube_reg();




#endif /* MOTION_SENSOR_SUPPORT */


/***************************************************************************** 
* External functions
*****************************************************************************/
#ifdef MOTION_SENSOR_SUPPORT

/*****************************************************************************
* FUNCTION
*  sensor_srv_motion_write_switch
* DESCRIPTION
*  Write switch of motion sensor to NVRAM
* PARAMETERS
*  is_enable
* RETURNS
*  MDI_RESULT
*****************************************************************************/
static sensor_srv_motion_write_switch(MMI_BOOL is_enable)
{
	nvram_ef_motion_sensor_switch_struct sensor_switch;
	S16 ErrorCode;

	sensor_switch.motion_sensor_switch = is_enable;

	WriteRecord(NVRAM_EF_MOTION_SENSOR_SWITCH_LID, 1, &sensor_switch, 
		NVRAM_EF_MOTION_SENSOR_SWITCH_SIZE, &ErrorCode);

}

/*****************************************************************************
* FUNCTION
*  sensor_srv_motion_read_switch
* DESCRIPTION
*  Read motion sensor switch from NVRAM
* PARAMETERS
*  void
* RETURNS
*  MMI_BOOL
*****************************************************************************/
static MMI_BOOL sensor_srv_motion_read_switch()
{
	nvram_ef_motion_sensor_switch_struct sensor_switch;
	S16 ErrorCode;

	ReadRecord(NVRAM_EF_MOTION_SENSOR_SWITCH_LID,1,&sensor_switch,NVRAM_EF_MOTION_SENSOR_SWITCH_SIZE,&ErrorCode);

	g_motion_sensor_able = sensor_switch.motion_sensor_switch;

//	kal_prompt_trace(MOD_MMI,"[mcube] %d",g_motion_sensor_able);

}


/*****************************************************************************
* FUNCTION
*  srv_sensor_motion_init
* DESCRIPTION
*  init MDI Camera
* PARAMETERS
*  void
* RETURNS
*  MDI_RESULT
*****************************************************************************/
mmi_ret srv_sensor_motion_init(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U32 i;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	for (i = 0; i < MOTION_SUPPORT_APP_NUM; i++)
	{
		g_srv_sensor_motion_cntx.app[i].mod_id = MOD_NIL;
		g_srv_sensor_motion_cntx.app[i].is_msg_send = MMI_FALSE;
		g_srv_sensor_motion_cntx.app[i].is_direct = MMI_FALSE;
		g_srv_sensor_motion_cntx.app[i].is_shake = MMI_FALSE;
		g_srv_sensor_motion_cntx.app[i].is_tilt = MMI_FALSE;
		g_srv_sensor_motion_cntx.app[i].prev_direct = SRV_SENSOR_MOTION_ANGLE_GY180;
	}
	g_srv_sensor_motion_cntx.is_shake_mute = MMI_FALSE;
	g_srv_sensor_motion_cntx.is_msg_send = MMI_FALSE;
	g_srv_sensor_motion_cntx.mutex = kal_create_mutex((CHAR*)"srv_sensor_motion");

	sensor_srv_motion_read_switch();

#ifdef MDI_MOTION_DRIVER_AVAIALBE

	motion_sensor_read_cali_from_nvram(); /* Notify drv to read calibration information */

#endif /*MDI_MOTION_DRIVER_AVAIALBE*/


	return MMI_RET_OK;
}

mmi_ret srv_sensor_motion_sub_init()
{

	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U32 i;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	for (i = 0; i < MOTION_SUPPORT_APP_NUM; i++)
	{
		g_srv_sensor_motion_cntx.app[i].mod_id = MOD_NIL;
		g_srv_sensor_motion_cntx.app[i].is_msg_send = MMI_FALSE;
		g_srv_sensor_motion_cntx.app[i].is_direct = MMI_FALSE;
		g_srv_sensor_motion_cntx.app[i].is_shake = MMI_FALSE;
		g_srv_sensor_motion_cntx.app[i].is_tilt = MMI_FALSE;
		g_srv_sensor_motion_cntx.app[i].prev_direct = SRV_SENSOR_MOTION_ANGLE_GY180;
	}
	g_srv_sensor_motion_cntx.is_shake_mute = MMI_FALSE;
	g_srv_sensor_motion_cntx.is_msg_send = MMI_FALSE;
	g_srv_sensor_motion_cntx.mutex = kal_create_mutex((CHAR*)"srv_sensor_motion");

	sensor_srv_motion_read_switch();

	return MMI_RET_OK;
}



static SRV_SENSOR_RESULT power_off_sensor()
{

	if (srv_sensor_motion_check_mode() != SRV_SENSOR_MOTION_ALWAYS_ON_MODE )
	{
#ifdef MDI_MOTION_DRIVER_AVAIALBE
		motion_sensor_power(MMI_FALSE);
		g_is_power_on = MMI_FALSE;

		motion_sensor_sample(MMI_FALSE); /*Add by XiaoHua*/

		if (srv_sensor_no_have_mcube_reg() != MMI_TRUE)
		{
			mCube_LibClose();
		}

#endif /* MDI_MOTION_DRIVER_AVAIALBE */ 


		return MDI_RES_MOTION_SUCCEED;
	}

}


static SRV_SENSOR_RESULT power_on_sensor()
{
	mCubeLibInit_t initData;

	initData.accelInit.accelOrientation = CHIP_TOP_RIGHT_DOWN;
	initData.accelInit.accelPolaBafrInit.enableUpdate = MMI_TRUE;
	initData.accelInit.accelPolaBafrInit.polaUpdRateHz = 10;

	initData.accelInit.accelPolaBafrInit.flipCntrl.flipEnable = g_mcube_init.flipEnable ;
	initData.accelInit.accelPolaBafrInit.flipCntrl.flipFilter = g_mcube_init.flipFilter;
	initData.accelInit.accelPolaBafrInit.flipCntrl.flipThreshold = g_mcube_init.flipThreshold;
	initData.accelInit.accelPolaBafrInit.flipCntrl.tFlipDebounce = g_mcube_init.tFlipDebounce ;
	initData.accelInit.accelPolaBafrInit.flipCntrl.tFlipInterval = g_mcube_init.tFlipInterval;


	if (srv_sensor_motion_check_mode() != SRV_SENSOR_MOTION_ALWAYS_ON_MODE )
	{

#ifdef MDI_MOTION_DRIVER_AVAIALBE

		motion_sensor_power(MMI_TRUE);
		g_is_power_on = MMI_TRUE;
		// motion_sensor_conf_sample_period(MOTION_SAMPLE_PERIOD);
		motion_sensor_flush_buff();
		motion_sensor_cb_registration(srv_sensor_motion_driver_data_state_hdlr, NULL);

		motion_sensor_conf_filter(MOTION_THRESHOLD_FOR_DRV);
		/* star sampling */
		motion_sensor_sample(MMI_TRUE);

		if (srv_sensor_no_have_mcube_reg() != MMI_TRUE)
		{
			mCube_LibOpen( &initData );
		}
#endif /* MDI_MOTION_DRIVER_AVAIALBE */ 
		return SRV_SENSOR_MOTION_SUCCEED;    
	}
}


/*****************************************************************************
* FUNCTION
*  srv_sensor_motion_power_on
* DESCRIPTION
*  power on
* PARAMETERS
*  void
* RETURNS
*  MDI_RESULT
*****************************************************************************/
static SRV_SENSOR_RESULT srv_sensor_motion_power_on(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifdef MDI_MOTION_DRIVER_AVAIALBE
	motion_sensor_power(MMI_TRUE);
	g_is_power_on = MMI_TRUE;
	motion_sensor_conf_sample_period(MOTION_SAMPLE_PERIOD);
	motion_sensor_flush_buff();


	mmi_frm_cb_reg_event (EVT_ID_GPIO_LCD_SLEEP_IN, 
		power_off_sensor, NULL);

	mmi_frm_cb_reg_event (EVT_ID_GPIO_LCD_SLEEP_OUT, 
		power_on_sensor, NULL);

#endif /* MDI_MOTION_DRIVER_AVAIALBE */ 
	return SRV_SENSOR_MOTION_SUCCEED;
}

/*****************************************************************************
* FUNCTION
*  srv_sensor_motion_shake_det_mute_timeout
* DESCRIPTION
*  shake timeout function
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_sensor_motion_shake_det_mute_timeout(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	g_srv_sensor_motion_cntx.is_shake_mute = MMI_FALSE;
}



/* Transfer MTK drv data to mCube data */
void srv_sensor_motion_get_acc(S16 acc_x, S16 acc_y, S16 acc_z,
							   float *x, float *y, float *z)
{
	*x = -1.0 * (float)acc_x * 9.807 / 1000.0 ;             //milli-g to m/s2
	*y = -1.0 * (float)acc_y * 9.807 / 1000.0  ;            //milli-g to m/s2
	*z = -1.0 * (float)acc_z * 9.807 / 1000.0 ;             //milli-g to m/s2
}


/*****************************************************************************
* FUNCTION
*  srv_sensor_motion_power_off
* DESCRIPTION
*  power off
* PARAMETERS
*  void
* RETURNS
*  MDI_RESULT
*****************************************************************************/
static SRV_SENSOR_RESULT srv_sensor_motion_power_off(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifdef MDI_MOTION_DRIVER_AVAIALBE
	motion_sensor_power(MMI_FALSE);
	g_is_power_on = MMI_FALSE;

	mmi_frm_cb_dereg_event(EVT_ID_GPIO_LCD_SLEEP_IN,
		power_off_sensor,
		NULL);

	mmi_frm_cb_dereg_event(EVT_ID_GPIO_LCD_SLEEP_OUT,
		power_on_sensor,
		NULL);

#endif /* MDI_MOTION_DRIVER_AVAIALBE */ 
	return MDI_RES_MOTION_SUCCEED;
}



/*****************************************************************************
* FUNCTION
*  srv_sensor_motion_start_listen_shake
* DESCRIPTION
*  listen to shake event
* PARAMETERS
*  sensitive                   [IN]        sensitive
*  shake_event_callback        [IN]        Event callback
* RETURNS
*  MDI_RESULT
*****************************************************************************/
SRV_SENSOR_HANDLE srv_sensor_start_listen(srv_sensor_type_enum type, void *option, 
										  SRV_SENSOR_EVENT_HDLR event_hdlr, void *user_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	SRV_SENSOR_HANDLE  return_value = SRV_SENSOR_MOTION_INVALID_PARAM;
	U8 sen;
  #ifdef __MTK_TARGET__
	mCubeLibResult_t mcube_open_result;
  #endif
	mCubeLibInit_t initData;

	U16 ms_gest_type;

	srv_sensor_motion_tilt_sensitive_enum tilt_mode = SRV_SENSOR_MOTION_RAW_TILT;

	srv_sensor_motion_step_sensitive_enum step_mode = SRV_SENSOR_MOTION_STEP_MEDIUM;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/       
	if (g_sub_init == MMI_TRUE)
	{
		srv_sensor_motion_sub_init();
		g_sub_init = MMI_FALSE;
	}

	initData.accelInit.accelOrientation = CHIP_TOP_RIGHT_DOWN;
	initData.accelInit.accelPolaBafrInit.enableUpdate = MMI_TRUE;
	initData.accelInit.accelPolaBafrInit.polaUpdRateHz = 10;

	initData.accelInit.accelPolaBafrInit.flipCntrl.flipEnable = g_mcube_init.flipEnable ;
	initData.accelInit.accelPolaBafrInit.flipCntrl.flipFilter = g_mcube_init.flipFilter;
	initData.accelInit.accelPolaBafrInit.flipCntrl.flipThreshold = g_mcube_init.flipThreshold;
	initData.accelInit.accelPolaBafrInit.flipCntrl.tFlipDebounce = g_mcube_init.tFlipDebounce ;
	initData.accelInit.accelPolaBafrInit.flipCntrl.tFlipInterval = g_mcube_init.tFlipInterval;

    initData.stepInit.stepSensitivity = STEP_SENS_LOW;  /* Default step sens is low */
	
	//mcube_open_result = mCube_LibOpen(&initData);
	//mcube_open_result = mCube_LibOpen();

#ifdef MDI_MOTION_DRIVER_AVAIALBE

	if (type == SRV_SENSOR_MOTION_TAP || type == SRV_SENSOR_MOTION_DOUBLE_TAP 
		|| type == SRV_SENSOR_MOTION_STEP || type == SRV_SENSOR_MOTION_DROP)
	{

		if (type == SRV_SENSOR_MOTION_TAP || type == SRV_SENSOR_MOTION_DOUBLE_TAP)
		{
			ms_gest_type = MS_TAP;
		}

		//#ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
		else if (type == SRV_SENSOR_MOTION_STEP)
		{
			ms_gest_type = MS_STEP;
		}
		//#endif

		else if (type == SRV_SENSOR_MOTION_DROP)
		{
			ms_gest_type = MS_DROP;
		}


		if (motion_sensor_query_gesture(ms_gest_type) == MMI_FALSE)
		{
			return SRV_SENSOR_MOTION_NOT_SUPPORT_GESTURE;
		}
	}

#endif /*MDI_MOTION_DRIVER_AVAIALBE*/

	switch (type)
	{
	case SRV_SENSOR_MOTION_SHAKE:
		{

			MMI_ASSERT(event_hdlr != NULL);
			sen = ((srv_sensor_motion_shake_cfg_struct *)option)->sensitive;
			return_value = srv_sensor_motion_add_to_slot(SRV_SENSOR_MOTION_SHAKE, 
				sen , event_hdlr, NULL,user_data);
			break;

		}
	case SRV_SENSOR_MOTION_DIRECT:
		{
			MMI_ASSERT(event_hdlr != NULL);
			sen = ((srv_sensor_motion_direct_cfg_struct *)option)->angle_threshold;
			return_value = srv_sensor_motion_add_to_slot(SRV_SENSOR_MOTION_DIRECT,
				sen, event_hdlr, NULL, user_data);
			break;
		}
	case SRV_SENSOR_MOTION_TILT:
		{
			MMI_ASSERT(event_hdlr != NULL);
			if (option != NULL)
			    tilt_mode = ((srv_sensor_motion_tilt_cfg_struct *)option)->sensitive;
			return_value = srv_sensor_motion_add_to_slot(SRV_SENSOR_MOTION_TILT,
				tilt_mode, event_hdlr, NULL, user_data);
			break;
		}


		/* For mCube library */


	case SRV_SENSOR_MOTION_TAP:

		MMI_ASSERT(event_hdlr != NULL);

#ifdef __MTK_TARGET__

		mcube_open_result = mCube_LibOpen(&initData);

#endif

		return_value = srv_sensor_motion_add_to_slot(SRV_SENSOR_MOTION_TAP,
			0,event_hdlr, NULL, user_data);

		break;
	case SRV_SENSOR_MOTION_DOUBLE_TAP:
		MMI_ASSERT(event_hdlr != NULL);

#ifdef __MTK_TARGET__
		mcube_open_result = mCube_LibOpen(&initData);
#endif

		return_value = srv_sensor_motion_add_to_slot(SRV_SENSOR_MOTION_DOUBLE_TAP,
			0,event_hdlr, NULL, user_data);
		break;

	case SRV_SENSOR_MOTION_DROP:
		MMI_ASSERT(event_hdlr != NULL);

#ifdef __MTK_TARGET__
		mcube_open_result = mCube_LibOpen(&initData);
#endif

		//kal_prompt_trace(MOD_MMI,"[mcube]Open %d",mcube_open_result);

		return_value = srv_sensor_motion_add_to_slot(SRV_SENSOR_MOTION_DROP,
			0,event_hdlr, NULL, user_data);
		break;

	case SRV_SENSOR_MOTION_ADVANCED_SHAKE:
		MMI_ASSERT(event_hdlr != NULL);

#ifdef __MTK_TARGET__
		mcube_open_result = mCube_LibOpen(&initData);
#endif
		//mcube_open_result = mCube_LibOpen();

		//kal_prompt_trace(MOD_MMI,"[mcube]Open %d",mcube_open_result);

		return_value = srv_sensor_motion_add_to_slot(SRV_SENSOR_MOTION_ADVANCED_SHAKE,
			0,event_hdlr, NULL, user_data);
		break;

	case SRV_SENSOR_MOTION_TURNOVER:
		MMI_ASSERT(event_hdlr != NULL);

#ifdef __MTK_TARGET__
		mcube_open_result = mCube_LibOpen(&initData);
#endif

		return_value = srv_sensor_motion_add_to_slot(SRV_SENSOR_MOTION_TURNOVER,
			0,event_hdlr, NULL, user_data);

#ifdef __MTK_TARGET__
		mcube_open_result = mCube_LibOpen(&initData);

#endif
		//mcube_open_result = mCube_LibOpen();
		//kal_prompt_trace(MOD_MMI,"[mcube]Open %d",mcube_open_result);

		break;

		//#ifdef __MOTION_SENSOR_ADVANCED_GESTURE__	
	case SRV_SENSOR_MOTION_STEP:
		MMI_ASSERT(event_hdlr != NULL);

#ifdef __MTK_TARGET__
		mcube_open_result = mCube_LibOpen(&initData);

#endif

		//kal_prompt_trace(MOD_MMI,"[mcube]Open %d",mcube_open_result);

        if (option != NULL)
        {
            step_mode = ((srv_sensor_motion_step_cfg_struct *)option)->sensitive;
        }
        
		return_value = srv_sensor_motion_add_to_slot(SRV_SENSOR_MOTION_STEP,
			step_mode,event_hdlr, NULL, user_data);

		kal_prompt_trace(MOD_MMI,"[mcube step]step_mode=%d",step_mode);
		
		break;
		//#endif

	default :
		break;
	}

	return return_value;
}


/*****************************************************************************
* FUNCTION
*  srv_sensor_motion_stop_listen_shake
* DESCRIPTION
*  stop listen shake operation
* PARAMETERS
*  *callback       [IN]    the callback of application
* RETURNS
*  MDI_RESULT
*****************************************************************************/
SRV_SENSOR_RESULT srv_sensor_stop_listen(SRV_SENSOR_HANDLE handle)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	SRV_SENSOR_RESULT  return_value = SRV_SENSOR_MOTION_INVALID_PARAM;
	SRV_SENSOR_HANDLE   internal_handle = 0;
	srv_sensor_type_enum  type;
	// U8 i;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (handle>45 || handle<1)
		return SRV_SENSOR_MOTION_INVALID_PARAM;

//	kal_prompt_trace(MOD_MMI,"[mcube]srv_sensor_stop_listen");

	srv_sensor_motion_get_internal_handle(handle, &internal_handle, &type);

	//if(handle < MOTION_SUPPORT_APP_NUM)

	kal_prompt_trace(MOD_MMI,"[mcube]type %d,internal handle %d",
		type, internal_handle);

	srv_sensor_motion_remove_mode(handle);


	return_value = srv_sensor_motion_remove_from_slot(type, internal_handle);
	return return_value;
}


/*****************************************************************************
* FUNCTION
*  srv_sensor_motion_get_external_handle
* DESCRIPTION
*  
* PARAMETERS
*
* RETURNS
*  MDI_RESULT
*****************************************************************************/
static SRV_SENSOR_HANDLE srv_sensor_motion_get_external_handle(srv_sensor_type_enum type,SRV_SENSOR_HANDLE handle)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	U8 i;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	for(i=0; i<HANDLE_TAB_SIZE; i++)
	{
		if (type == handle_tab[i].app_type && handle == handle_tab[i].internal_handle)
			return handle_tab[i].external_handle;
	}

	return SRV_SENSOR_MOTION_NO_SLOT;
}

/*****************************************************************************
* FUNCTION
*  srv_sensor_motion_get_external_handle
* DESCRIPTION
*  
* PARAMETERS
*
* RETURNS
*  MDI_RESULT
*****************************************************************************/
static void srv_sensor_motion_get_internal_handle(SRV_SENSOR_HANDLE handle, SRV_SENSOR_HANDLE *internal_handle, srv_sensor_type_enum *type)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8 i;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	for(i=0; i<HANDLE_TAB_SIZE; i++)
	{
		if (handle == handle_tab[i].external_handle)
		{
			*type =  handle_tab[i].app_type;
			*internal_handle = handle_tab[i].internal_handle;
			break;
		}
	}

}


static MMI_BOOL srv_sensor_no_have_mcube_reg()
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U32 i = 0;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	for (i = 0; i < MOTION_SUPPORT_APP_NUM; i++)
	{
		if (g_srv_sensor_motion_cntx.app[i].double_tap_callback != NULL ||
			g_srv_sensor_motion_cntx.app[i].advanced_shake_callback != NULL ||
			g_srv_sensor_motion_cntx.app[i].tap_callback != NULL ||
			g_srv_sensor_motion_cntx.app[i].turnover_callback != NULL ||
			g_srv_sensor_motion_cntx.app[i].drop_callback != NULL ||
			g_srv_sensor_motion_cntx.app[i].step_callback != NULL)
		{
			return MMI_FALSE;
		}
	}
	return MMI_TRUE;
}

static srv_sensor_motion_set_step_sens(U8 sens)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	mCubeLibInit_t initData;
	initData.stepInit.stepSensitivity = STEP_SENS_MED;
    /* other */
	initData.accelInit.accelOrientation = CHIP_TOP_RIGHT_DOWN;
	initData.accelInit.accelPolaBafrInit.enableUpdate = MMI_TRUE;
	initData.accelInit.accelPolaBafrInit.polaUpdRateHz = 10;

	initData.accelInit.accelPolaBafrInit.flipCntrl.flipEnable = g_mcube_init.flipEnable ;
	initData.accelInit.accelPolaBafrInit.flipCntrl.flipFilter = g_mcube_init.flipFilter;
	initData.accelInit.accelPolaBafrInit.flipCntrl.flipThreshold = g_mcube_init.flipThreshold;
	initData.accelInit.accelPolaBafrInit.flipCntrl.tFlipDebounce = g_mcube_init.tFlipDebounce ;
	initData.accelInit.accelPolaBafrInit.flipCntrl.tFlipInterval = g_mcube_init.tFlipInterval;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

    switch ((srv_sensor_motion_step_sensitive_enum)sens)
    {
       case SRV_SENSOR_MOTION_STEP_HIGH:
	   	initData.stepInit.stepSensitivity = STEP_SENS_HIGH;
	   	break;
       case SRV_SENSOR_MOTION_STEP_MEDIUM:
	   	initData.stepInit.stepSensitivity = STEP_SENS_MED;
	   	break;
       case SRV_SENSOR_MOTION_STEP_LOW:
	   	initData.stepInit.stepSensitivity = STEP_SENS_LOW;
	   	break;
    }

	
	kal_prompt_trace(MOD_MMI,"[mcube step]initData.stepInit.stepSensitivity = %d",initData.stepInit.stepSensitivity);

	
   #ifdef __MTK_TARGET__
		mCube_LibClose();
		mCube_LibOpen(&initData);
   #endif
}

/*****************************************************************************
* FUNCTION
*  srv_sensor_motion_add_to_slot
* DESCRIPTION
*  add request to the slot
* PARAMETERS
*  type                    [IN]        request type
*  sensitive               [IN]        sensitive
*  *callback               [IN]        callback pointer to the app function
*  *param                  [IN]        param to the slot add function
* RETURNS
*  MDI_RESULT
*****************************************************************************/
static SRV_SENSOR_RESULT srv_sensor_motion_add_to_slot(srv_sensor_type_enum type,
													   U8 sensitive,void(* callback)(),void * param,void * user_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	module_type module_id;
	//srv_sensor_motion_tilt_event_enum   *tilt_indcation = param;
	SRV_SENSOR_HANDLE  return_value = SRV_SENSOR_MOTION_NO_SLOT;
	SRV_SENSOR_HANDLE  res_handle;
	U32 i = 0;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_ASSERT(callback != NULL);

	module_id = stack_get_active_module_id();
	MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_ADD_TO_SLOT, module_id, type, callback);

	kal_prompt_trace(MOD_MMI,"Motion sensor: Type = %d",type);
	MOTION_ENTER_PROTECT;    
	/*check if this is the first request*/
	for (i = 0; i < MOTION_SUPPORT_APP_NUM; i++)
	{
		if (MOD_NIL != g_srv_sensor_motion_cntx.app[i].mod_id)
		{
			break;
		}
	}
	if (i == MOTION_SUPPORT_APP_NUM  && g_motion_sensor_able == KAL_TRUE)		/* Is the first request and setting enable sensor mode */
	{
		MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_POWER_ON);
		srv_sensor_motion_power_on();
		g_srv_sensor_motion_cntx.is_shake_mute = MMI_TRUE;
		gui_start_timer(MOTION_SHAKE_DET_MUTE_DURATION, srv_sensor_motion_shake_det_mute_timeout);
		g_srv_sensor_motion_cntx.is_msg_send = MMI_FALSE;
#ifdef MDI_MOTION_DRIVER_AVAIALBE
		/* register callback to retrive data */
		motion_sensor_cb_registration(srv_sensor_motion_driver_data_state_hdlr, NULL);
		SetProtocolEventHandler(srv_sensor_motion_data_hdlr, MSG_ID_MDI_MOTION_DATA_STATE_RSP);
		motion_sensor_conf_filter(MOTION_THRESHOLD_FOR_DRV);
		/* star sampling */
		motion_sensor_sample(MMI_TRUE);

#endif /* MDI_MOTION_DRIVER_AVAIALBE */ 
	}

	/*check if another mode have open at same module*/
	for (i = 0; i < MOTION_SUPPORT_APP_NUM; i++)
	{
		if (type == SRV_SENSOR_MOTION_SHAKE &&
			module_id == g_srv_sensor_motion_cntx.app[i].mod_id &&
			NULL == g_srv_sensor_motion_cntx.app[i].shake_callback)
		{
			g_srv_sensor_motion_cntx.app[i].shake_sen.sensitive  = (srv_sensor_motion_shake_sensitive_enum)sensitive;
			g_srv_sensor_motion_cntx.app[i].shake_callback = (SRV_SENSOR_EVENT_HDLR)callback;
			g_srv_sensor_motion_cntx.app[i].shake_user_data= user_data;
			g_srv_sensor_motion_cntx.app[i].mod_id = module_id;
			g_srv_sensor_motion_cntx.app[i].is_shake = MMI_TRUE;
			MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_SHAKE_FIND_TILT_ADD_OK, i, module_id);
			return_value = i;
			break;
		}
		else if(type == SRV_SENSOR_MOTION_DIRECT && 
			module_id == g_srv_sensor_motion_cntx.app[i].mod_id &&
			NULL == g_srv_sensor_motion_cntx.app[i].direct_callback)
		{
			MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_TILT_FIND_SHAKE_ADD_OK, i, module_id);
			g_srv_sensor_motion_cntx.app[i].direct_sen.angle_threshold = sensitive;
			g_srv_sensor_motion_cntx.app[i].direct_callback = (SRV_SENSOR_EVENT_HDLR)callback;
			g_srv_sensor_motion_cntx.app[i].direct_user_data= user_data;
			g_srv_sensor_motion_cntx.app[i].mod_id = module_id;
			g_srv_sensor_motion_cntx.app[i].is_direct = MMI_TRUE;
			srv_sensor_motion_reset_direct_data(&g_srv_sensor_motion_cntx.app[i].direct);
			return_value = i;
			break;
		}
		else if(type == SRV_SENSOR_MOTION_TILT && 
			module_id == g_srv_sensor_motion_cntx.app[i].mod_id &&
			NULL == g_srv_sensor_motion_cntx.app[i].tilt_callback)
		{

			MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_TILT_FIND_SHAKE_ADD_OK, i, module_id);
			g_srv_sensor_motion_cntx.app[i].tilt_sen.sensitive = (srv_sensor_motion_tilt_sensitive_enum)sensitive;
			g_srv_sensor_motion_cntx.app[i].tilt_callback = (SRV_SENSOR_EVENT_HDLR)callback;
			g_srv_sensor_motion_cntx.app[i].tilt_user_data = user_data;
			g_srv_sensor_motion_cntx.app[i].mod_id = module_id;
			g_srv_sensor_motion_cntx.app[i].is_tilt = MMI_TRUE;
			return_value = i;
			break;
		}       

		/* For porting mCude library */



		/* Tap */

		else if (type == SRV_SENSOR_MOTION_TAP && 
			module_id == g_srv_sensor_motion_cntx.app[i].mod_id &&
			NULL == g_srv_sensor_motion_cntx.app[i].tap_callback)
		{			
			kal_prompt_trace(MOD_MMI,"[mcube] Register tap(another mode)");
			g_srv_sensor_motion_cntx.app[i].tap_callback = (SRV_SENSOR_EVENT_HDLR)callback;
			g_srv_sensor_motion_cntx.app[i].tap_user_data = user_data;
			g_srv_sensor_motion_cntx.app[i].mod_id = module_id;
			g_srv_sensor_motion_cntx.app[i].is_tap = MMI_TRUE;
			return_value = i;
			g_is_reg_mcube = MMI_TRUE;
			break;
		}


		/*Double Tap*/
		else if (type == SRV_SENSOR_MOTION_DOUBLE_TAP && 
			module_id == g_srv_sensor_motion_cntx.app[i].mod_id &&
			NULL == g_srv_sensor_motion_cntx.app[i].double_tap_callback)
		{			
			kal_prompt_trace(MOD_MMI,"[mcube] Register double tap(another mode)");
			g_srv_sensor_motion_cntx.app[i].double_tap_callback = (SRV_SENSOR_EVENT_HDLR)callback;
			g_srv_sensor_motion_cntx.app[i].double_tap_user_data = user_data;
			g_srv_sensor_motion_cntx.app[i].mod_id = module_id;
			g_srv_sensor_motion_cntx.app[i].is_double_tap = MMI_TRUE;
			return_value = i;
			g_is_reg_mcube = MMI_TRUE;
			break;
		}

		/* Advanced shake */

		else if (type == SRV_SENSOR_MOTION_ADVANCED_SHAKE &&
			module_id == g_srv_sensor_motion_cntx.app[i].mod_id &&
			NULL == g_srv_sensor_motion_cntx.app[i].advanced_shake_callback)

		{			
			kal_prompt_trace(MOD_MMI,"[mcube] Register advanced shake(another mode)");
			g_srv_sensor_motion_cntx.app[i].advanced_shake_callback = (SRV_SENSOR_EVENT_HDLR)callback;
			g_srv_sensor_motion_cntx.app[i].advanced_shake_user_data = user_data;
			g_srv_sensor_motion_cntx.app[i].mod_id = module_id;
			g_srv_sensor_motion_cntx.app[i].is_advanced_shake = MMI_TRUE;
			return_value = i;
			g_is_reg_mcube = MMI_TRUE;
			break;
		}

		/*Turn over*/
		else if (type == SRV_SENSOR_MOTION_TURNOVER &&
			module_id == g_srv_sensor_motion_cntx.app[i].mod_id &&
			NULL == g_srv_sensor_motion_cntx.app[i].turnover_callback)
		{
			kal_prompt_trace(MOD_MMI,"[mcube] Register turn over(another mode)");
			g_srv_sensor_motion_cntx.app[i].turnover_callback = (SRV_SENSOR_EVENT_HDLR)callback;
			g_srv_sensor_motion_cntx.app[i].turnover_user_data = user_data;
			g_srv_sensor_motion_cntx.app[i].mod_id = module_id;
			g_srv_sensor_motion_cntx.app[i].is_turnover = MMI_TRUE;
			return_value = i;
			g_is_reg_mcube = MMI_TRUE;
			break;
		}

		//#ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
		/* Step */
		else if (type == SRV_SENSOR_MOTION_STEP &&
			module_id == g_srv_sensor_motion_cntx.app[i].mod_id &&
			NULL == g_srv_sensor_motion_cntx.app[i].step_callback)
		{
			MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_TILT_FIND_SHAKE_ADD_OK, i, module_id);
			g_srv_sensor_motion_cntx.app[i].step_callback = (SRV_SENSOR_EVENT_HDLR)callback;
			g_srv_sensor_motion_cntx.app[i].step_user_data = user_data;
			g_srv_sensor_motion_cntx.app[i].mod_id = module_id;
			g_srv_sensor_motion_cntx.app[i].is_step = MMI_TRUE;
			return_value = i;
			g_is_reg_mcube = MMI_TRUE;
			srv_sensor_motion_set_step_sens(sensitive);
			break;
		}
		//#endif /*__MOTION_SENSOR_ADVANCED_GESTURE__*/

		/* Drop */
		else if (type == SRV_SENSOR_MOTION_DROP &&
			module_id == g_srv_sensor_motion_cntx.app[i].mod_id &&
			NULL == g_srv_sensor_motion_cntx.app[i].drop_callback)
		{
			MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_TILT_FIND_SHAKE_ADD_OK, i, module_id);
			g_srv_sensor_motion_cntx.app[i].drop_callback = (SRV_SENSOR_EVENT_HDLR)callback;
			g_srv_sensor_motion_cntx.app[i].drop_user_data = user_data;
			g_srv_sensor_motion_cntx.app[i].mod_id = module_id;
			g_srv_sensor_motion_cntx.app[i].is_drop = MMI_TRUE;
			return_value = i;
			g_is_reg_mcube = MMI_TRUE;
			break;
		}


	}
	/*find empty slot*/
	if (i == MOTION_SUPPORT_APP_NUM)
	{
		for (i = 0; i < MOTION_SUPPORT_APP_NUM; i++)
		{
			if (type == SRV_SENSOR_MOTION_SHAKE &&
				MOD_NIL == g_srv_sensor_motion_cntx.app[i].mod_id &&
				NULL == g_srv_sensor_motion_cntx.app[i].shake_callback)
			{
				MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_SHAKE_FIND_EMPTY_SLOT, i, module_id);
				g_srv_sensor_motion_cntx.app[i].shake_callback = (SRV_SENSOR_EVENT_HDLR)callback;
				g_srv_sensor_motion_cntx.app[i].mod_id = module_id;
				g_srv_sensor_motion_cntx.app[i].shake_sen.sensitive = (srv_sensor_motion_shake_sensitive_enum)sensitive;
				g_srv_sensor_motion_cntx.app[i].shake_user_data= user_data;
				g_srv_sensor_motion_cntx.app[i].is_shake = MMI_TRUE;
				return_value = i;
				break;
			}
			else if(type == SRV_SENSOR_MOTION_DIRECT && 
				MOD_NIL == g_srv_sensor_motion_cntx.app[i].mod_id &&
				NULL == g_srv_sensor_motion_cntx.app[i].direct_callback)
			{
				MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_TILT_FIND_EMPTY_SLOT, i, module_id);
				g_srv_sensor_motion_cntx.app[i].direct_callback = (SRV_SENSOR_EVENT_HDLR)callback;
				g_srv_sensor_motion_cntx.app[i].mod_id = module_id;
				g_srv_sensor_motion_cntx.app[i].direct_sen.angle_threshold = sensitive;
				g_srv_sensor_motion_cntx.app[i].direct_user_data= user_data;
				g_srv_sensor_motion_cntx.app[i].is_direct = MMI_TRUE;
				srv_sensor_motion_reset_direct_data(&g_srv_sensor_motion_cntx.app[i].direct);
				return_value = i;
				break;
			}
			else if(type == SRV_SENSOR_MOTION_TILT && 
				MOD_NIL == g_srv_sensor_motion_cntx.app[i].mod_id &&
				NULL == g_srv_sensor_motion_cntx.app[i].tilt_callback)
			{
				MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_TILT_FIND_SHAKE_ADD_OK, i, module_id);
				g_srv_sensor_motion_cntx.app[i].tilt_sen.sensitive = (srv_sensor_motion_tilt_sensitive_enum)sensitive;
				g_srv_sensor_motion_cntx.app[i].tilt_callback = (SRV_SENSOR_EVENT_HDLR)callback;
				g_srv_sensor_motion_cntx.app[i].tilt_user_data= user_data;
				g_srv_sensor_motion_cntx.app[i].mod_id = module_id;
				g_srv_sensor_motion_cntx.app[i].is_tilt = MMI_TRUE;
				return_value = i;
				break;
			}


			/* For porting mCude library */



			/* Tap */

			else if (type == SRV_SENSOR_MOTION_TAP && 
				MOD_NIL == g_srv_sensor_motion_cntx.app[i].mod_id &&
				NULL == g_srv_sensor_motion_cntx.app[i].tap_callback)
			{			
				kal_prompt_trace(MOD_MMI,"[mcube] Register tap and add to slot");
				g_srv_sensor_motion_cntx.app[i].tap_callback = (SRV_SENSOR_EVENT_HDLR)callback;
				g_srv_sensor_motion_cntx.app[i].tap_user_data = user_data;
				g_srv_sensor_motion_cntx.app[i].mod_id = module_id;
				g_srv_sensor_motion_cntx.app[i].is_tap = MMI_TRUE;
				return_value = i;
				g_is_reg_mcube = MMI_TRUE;
				break;
			}

			/* Advanced shake */

			else if (type == SRV_SENSOR_MOTION_ADVANCED_SHAKE &&
				MOD_NIL == g_srv_sensor_motion_cntx.app[i].mod_id &&
				NULL == g_srv_sensor_motion_cntx.app[i].advanced_shake_callback)
			{			
				kal_prompt_trace(MOD_MMI,"[mcube] Register advanced shake and add to slot");
				g_srv_sensor_motion_cntx.app[i].advanced_shake_callback = (SRV_SENSOR_EVENT_HDLR)callback;
				g_srv_sensor_motion_cntx.app[i].advanced_shake_user_data = user_data;
				g_srv_sensor_motion_cntx.app[i].mod_id = module_id;
				g_srv_sensor_motion_cntx.app[i].is_advanced_shake = MMI_TRUE;
				return_value = i;
				g_is_reg_mcube = MMI_TRUE;
				break;
			}

			/* Double tap */

			else if (type == SRV_SENSOR_MOTION_DOUBLE_TAP && 
				MOD_NIL == g_srv_sensor_motion_cntx.app[i].mod_id &&
				NULL == g_srv_sensor_motion_cntx.app[i].double_tap_callback)
			{			
				kal_prompt_trace(MOD_MMI,"[mcube] Register double tap and add to slot");
				g_srv_sensor_motion_cntx.app[i].double_tap_callback = (SRV_SENSOR_EVENT_HDLR)callback;
				g_srv_sensor_motion_cntx.app[i].double_tap_user_data = user_data;
				g_srv_sensor_motion_cntx.app[i].mod_id = module_id;
				g_srv_sensor_motion_cntx.app[i].is_double_tap = MMI_TRUE;
				return_value = i;
				g_is_reg_mcube = MMI_TRUE;
				break;
			}

			/*Turn over*/

			else if (type == SRV_SENSOR_MOTION_TURNOVER &&
				MOD_NIL == g_srv_sensor_motion_cntx.app[i].mod_id &&
				NULL == g_srv_sensor_motion_cntx.app[i].turnover_callback)
			{
				kal_prompt_trace(MOD_MMI,"[mcube] Register turnover and add to slot");
				g_srv_sensor_motion_cntx.app[i].turnover_callback = (SRV_SENSOR_EVENT_HDLR)callback;
				g_srv_sensor_motion_cntx.app[i].turnover_user_data = user_data;
				g_srv_sensor_motion_cntx.app[i].mod_id = module_id;
				g_srv_sensor_motion_cntx.app[i].is_turnover = MMI_TRUE;
				return_value = i;
				g_is_reg_mcube = MMI_TRUE;
				break;
			}
			//#ifdef __MOTION_SENSOR_ADVANCED_GESTURE__

			/* Step */
			else if (type == SRV_SENSOR_MOTION_STEP &&
				MOD_NIL == g_srv_sensor_motion_cntx.app[i].mod_id &&
				NULL == g_srv_sensor_motion_cntx.app[i].step_callback)
			{
				kal_prompt_trace(MOD_MMI,"[mcube] Register step and add to slot");
				g_srv_sensor_motion_cntx.app[i].step_callback = (SRV_SENSOR_EVENT_HDLR)callback;
				g_srv_sensor_motion_cntx.app[i].step_user_data = user_data;
				g_srv_sensor_motion_cntx.app[i].mod_id = module_id;
				g_srv_sensor_motion_cntx.app[i].is_step = MMI_TRUE;
				return_value = i;
				g_is_reg_mcube = MMI_TRUE;
				srv_sensor_motion_set_step_sens(sensitive);
				break;
			}

			//#endif /*__MOTION_SENSOR_ADVANCED_GESTURE__*/

			/* Drop */
			else if (type == SRV_SENSOR_MOTION_DROP &&
				MOD_NIL == g_srv_sensor_motion_cntx.app[i].mod_id &&
				NULL == g_srv_sensor_motion_cntx.app[i].drop_callback)
			{
			//	kal_prompt_trace(MOD_MMI,"[mcube] Register drop and add to slot");
				g_srv_sensor_motion_cntx.app[i].drop_callback = (SRV_SENSOR_EVENT_HDLR)callback;
				g_srv_sensor_motion_cntx.app[i].drop_user_data = user_data;
				g_srv_sensor_motion_cntx.app[i].mod_id = module_id;
				g_srv_sensor_motion_cntx.app[i].is_drop = MMI_TRUE;
				return_value = i;
				g_is_reg_mcube = MMI_TRUE;
				break;
			}




		}
	}

	MMI_ASSERT(i>=0);
	res_handle = srv_sensor_motion_get_external_handle(type,return_value);
	if (i == MOTION_SUPPORT_APP_NUM)
	{
		res_handle = SRV_SENSOR_MOTION_NO_SLOT;
	}

	kal_prompt_trace(MOD_MMI,"[mcube]add external index %d",return_value);

	MOTION_EXIT_PROTECT;
	return res_handle;

}



static U8 srv_sensor_callback_handler_count(U8 index)
{
	U8 count = 0;


	if (g_srv_sensor_motion_cntx.app[index].advanced_shake_callback != NULL)
		count++;
	if (g_srv_sensor_motion_cntx.app[index].tap_callback != NULL)
		count++;
	if (g_srv_sensor_motion_cntx.app[index].double_tap_callback != NULL)
		count++;
	//#ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
	if (g_srv_sensor_motion_cntx.app[index].step_callback!= NULL)
		count++;
	//#endif /*__MOTION_SENSOR_ADVANCED_GESTURE__*/
	if (g_srv_sensor_motion_cntx.app[index].drop_callback!= NULL)
		count++;
	if (g_srv_sensor_motion_cntx.app[index].turnover_callback != NULL)
		count++;


	if (g_srv_sensor_motion_cntx.app[index].tilt_callback != NULL)
		count++;
	if (g_srv_sensor_motion_cntx.app[index].direct_callback != NULL)
		count++;
	if (g_srv_sensor_motion_cntx.app[index].shake_callback != NULL)
		count++;

	return count;
}






/*****************************************************************************
* FUNCTION
*  srv_sensor_motion_remove_from_slot
* DESCRIPTION
*  remove  a request from the slot
* PARAMETERS
*  type                [IN]        the type want to remove
*  *callback           [IN]        the callback function pointer
* RETURNS
*  MDI_RESULT
*****************************************************************************/
static SRV_SENSOR_RESULT srv_sensor_motion_remove_from_slot(srv_sensor_type_enum type,SRV_SENSOR_HANDLE index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	module_type module_id;
	SRV_SENSOR_RESULT  return_value = SRV_SENSOR_MOTION_CB_NOT_FOUND;
	U32 i = 0;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	module_id = stack_get_active_module_id();
	MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_REMOVE_FROM_SLOT, module_id, type, index);
	MMI_ASSERT(index >= 0);
	MMI_ASSERT(index < MOTION_SUPPORT_APP_NUM);

	kal_prompt_trace(MOD_MMI,"[mcube]remove internal index %d",index);

	MMI_ASSERT(g_srv_sensor_motion_cntx.app[index].mod_id == module_id);
	MOTION_ENTER_PROTECT;    
	if (type == SRV_SENSOR_MOTION_SHAKE)
	{
		g_srv_sensor_motion_cntx.app[index].shake_callback = NULL;
		g_srv_sensor_motion_cntx.app[index].shake_user_data= NULL;
		/*
		if (NULL == g_srv_sensor_motion_cntx.app[index].tilt_callback &&
		NULL == g_srv_sensor_motion_cntx.app[index].direct_callback)
		*/    
		if (srv_sensor_callback_handler_count(index) == 0)
		{
			g_srv_sensor_motion_cntx.app[index].mod_id = MOD_NIL;
		}
		MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_SHAKE_REMOVE_OK, i);
		return_value = SRV_SENSOR_MOTION_SUCCEED;
	}
	else if(type == SRV_SENSOR_MOTION_TILT)
	{
		g_srv_sensor_motion_cntx.app[index].tilt_callback = NULL;
		g_srv_sensor_motion_cntx.app[index].tilt_user_data= NULL;
		/*
		if (NULL == g_srv_sensor_motion_cntx.app[index].shake_callback &&
		NULL == g_srv_sensor_motion_cntx.app[index].direct_callback)
		*/
		if (srv_sensor_callback_handler_count(index) == 0)
		{
			g_srv_sensor_motion_cntx.app[index].mod_id = MOD_NIL;
		}
		MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_TILT_REMOVE_OK, i);
		return_value = SRV_SENSOR_MOTION_SUCCEED;
	}
	else if(type == SRV_SENSOR_MOTION_DIRECT)
	{
		g_srv_sensor_motion_cntx.app[index].direct_callback = NULL;
		g_srv_sensor_motion_cntx.app[index].direct_user_data= NULL;

		/*
		if (NULL == g_srv_sensor_motion_cntx.app[index].shake_callback &&
		NULL == g_srv_sensor_motion_cntx.app[index].tilt_callback)
		*/
		if (srv_sensor_callback_handler_count(index) == 0)
		{
			g_srv_sensor_motion_cntx.app[index].mod_id = MOD_NIL;
		}
		MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_TILT_REMOVE_OK, i);
		return_value = SRV_SENSOR_MOTION_SUCCEED;
	}


	else if(type == SRV_SENSOR_MOTION_TAP)
	{
		g_srv_sensor_motion_cntx.app[index].tap_callback = NULL;
		g_srv_sensor_motion_cntx.app[index].tap_user_data = NULL;

		/*
		if (NULL == g_srv_sensor_motion_cntx.app[index].shake_callback &&
		NULL == g_srv_sensor_motion_cntx.app[index].tilt_callback)
		*/
		if (srv_sensor_callback_handler_count(index) == 0)
		{
			g_srv_sensor_motion_cntx.app[index].mod_id = MOD_NIL;
		}
		MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_TILT_REMOVE_OK, i);
	//	kal_prompt_trace(MOD_MMI,"[mcube]close tap!!");
		return_value = SRV_SENSOR_MOTION_SUCCEED;
	}
	else if(type == SRV_SENSOR_MOTION_DOUBLE_TAP)
	{
		g_srv_sensor_motion_cntx.app[index].double_tap_callback = NULL;
		g_srv_sensor_motion_cntx.app[index].double_tap_user_data= NULL;

		/*
		if (NULL == g_srv_sensor_motion_cntx.app[index].shake_callback &&
		NULL == g_srv_sensor_motion_cntx.app[index].tilt_callback)
		*/
		if (srv_sensor_callback_handler_count(index) == 0)
		{
			g_srv_sensor_motion_cntx.app[index].mod_id = MOD_NIL;
		}
		MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_TILT_REMOVE_OK, i);
	//	kal_prompt_trace(MOD_MMI,"[mcube]close double tap!!");
		return_value = SRV_SENSOR_MOTION_SUCCEED;
	}
	else if(type == SRV_SENSOR_MOTION_TURNOVER)
	{
		g_srv_sensor_motion_cntx.app[index].turnover_callback = NULL;
		g_srv_sensor_motion_cntx.app[index].turnover_user_data= NULL;

		/*
		if (NULL == g_srv_sensor_motion_cntx.app[index].shake_callback &&
		NULL == g_srv_sensor_motion_cntx.app[index].tilt_callback)
		*/
		if (srv_sensor_callback_handler_count(index) == 0)
		{
			g_srv_sensor_motion_cntx.app[index].mod_id = MOD_NIL;
		}
		MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_TILT_REMOVE_OK, i);
	//	kal_prompt_trace(MOD_MMI,"[mcube]close turnover!!");
		return_value = SRV_SENSOR_MOTION_SUCCEED;
	}
	else if(type == SRV_SENSOR_MOTION_ADVANCED_SHAKE)
	{
		g_srv_sensor_motion_cntx.app[index].advanced_shake_callback = NULL;
		g_srv_sensor_motion_cntx.app[index].advanced_shake_user_data= NULL;

		/*
		if (NULL == g_srv_sensor_motion_cntx.app[index].shake_callback &&
		NULL == g_srv_sensor_motion_cntx.app[index].tilt_callback)
		*/
		if (srv_sensor_callback_handler_count(index) == 0)
		{
			g_srv_sensor_motion_cntx.app[index].mod_id = MOD_NIL;
		}
		MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_TILT_REMOVE_OK, i);
	//	kal_prompt_trace(MOD_MMI,"[mcube]close advanced shake!!");
		return_value = SRV_SENSOR_MOTION_SUCCEED;
	}
	//#ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
	else if(type == SRV_SENSOR_MOTION_STEP)
	{
		g_srv_sensor_motion_cntx.app[index].step_callback = NULL;
		g_srv_sensor_motion_cntx.app[index].step_user_data= NULL;

		/*
		if (NULL == g_srv_sensor_motion_cntx.app[index].shake_callback &&
		NULL == g_srv_sensor_motion_cntx.app[index].tilt_callback)
		*/
		if (srv_sensor_callback_handler_count(index) == 0)
		{
			g_srv_sensor_motion_cntx.app[index].mod_id = MOD_NIL;
		}
		MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_TILT_REMOVE_OK, i);
	//	kal_prompt_trace(MOD_MMI,"[mcube]close step!!");
		return_value = SRV_SENSOR_MOTION_SUCCEED;
	}
	//#endif
	else if(type == SRV_SENSOR_MOTION_DROP)
	{
		g_srv_sensor_motion_cntx.app[index].drop_callback = NULL;
		g_srv_sensor_motion_cntx.app[index].drop_user_data= NULL;

		/*
		if (NULL == g_srv_sensor_motion_cntx.app[index].shake_callback &&
		NULL == g_srv_sensor_motion_cntx.app[index].tilt_callback)
		*/
		if (srv_sensor_callback_handler_count(index) == 0)
		{
			g_srv_sensor_motion_cntx.app[index].mod_id = MOD_NIL;
		}
		MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_TILT_REMOVE_OK, i);
	//	kal_prompt_trace(MOD_MMI,"[mcube]close drop!!");
		return_value = SRV_SENSOR_MOTION_SUCCEED;
	}




	if (srv_sensor_no_have_mcube_reg())
	{
#ifdef __MTK_TARGET__
		mCube_LibClose();
#endif

		g_is_reg_mcube = MMI_FALSE;
	//	kal_prompt_trace(MOD_MMI,"[mcube]close mcube lib");
	}



	for (i = 0; i < MOTION_SUPPORT_APP_NUM; i++)
	{
		if (MOD_NIL != g_srv_sensor_motion_cntx.app[i].mod_id)
		{
			MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_FIND_OPEN_NOT_POWER_OFF, i, 
				g_srv_sensor_motion_cntx.app[i].mod_id,
				g_srv_sensor_motion_cntx.app[i].tilt_callback,
				g_srv_sensor_motion_cntx.app[i].shake_callback);
			break;
		}
	}
	if (i == MOTION_SUPPORT_APP_NUM)
	{
		MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_POWER_OFF_MOTION);
		SetProtocolEventHandler(NULL, MSG_ID_MDI_MOTION_DATA_STATE_RSP);
		srv_sensor_motion_power_off();  //if all request are closed , power off motion
	}
	MOTION_EXIT_PROTECT;
	MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_REMOVE_FROM_SLOT_RETURN,return_value);
	return return_value;  
}

/*****************************************************************************
* FUNCTION
*  srv_sensor_motion_reset_tilt_data
* DESCRIPTION
*  reset tilt detect context
* PARAMETERS
*  *tilt   [IN]    the pointer to the tilt context
* RETURNS
*  void
*****************************************************************************/
static void srv_sensor_motion_reset_direct_data(srv_sensor_motion_direct_struct *tilt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	tilt->action = SRV_SENSOR_MOTION_ACTION_NULL;
	tilt->direct = SRV_SENSOR_MOTION_ANGLE_OTHER;  
}
#ifdef MDI_MOTION_DRIVER_AVAIALBE
#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"
/*****************************************************************************
* FUNCTION
*  srv_sensor_motion_driver_data_state_hdlr
* DESCRIPTION
*  callback function to handler driver's data state change.
*  this function will be under driver's HISR. so only send message to MMI
* PARAMETERS
*  parameter       [IN]        Para
*  state           [IN]        Data state
* RETURNS
*  void
*****************************************************************************/
static void srv_sensor_motion_driver_data_state_hdlr(void *parameter, Motion_Sensor_BuffState_enum state)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	MYQUEUE message;
	srv_sensor_motion_msg_struct *msg_data_ptr;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (g_srv_sensor_motion_cntx.is_msg_send == MMI_TRUE)
	{
		return;
	}
	if (state == BUFF_EMPTY)
	{
		return;
	}
	msg_data_ptr = OslConstructDataPtr(sizeof(srv_sensor_motion_msg_struct));

	switch (state)
	{
	case BUFF_DATA_EXIST:
		msg_data_ptr->data_state = MOTION_DATA_EXIST;
		break;

	case BUFF_FULL:
		msg_data_ptr->data_state = MOTION_DATA_FULL;
		break;
	}
	message.oslMsgId = MSG_ID_MDI_MOTION_DATA_STATE_RSP;
	message.oslDataPtr = (oslParaType*) msg_data_ptr;
	message.oslPeerBuffPtr = NULL;
	// message.oslSrcId = MOD_DRV_HISR;
	message.oslSrcId = stack_get_active_module_id();
	message.oslDestId = MOTION_RUN_MOD;
	OslMsgSendExtQueue(&message);
	g_srv_sensor_motion_cntx.is_msg_send = MMI_TRUE;
}
#pragma arm section code, rodata


/*****************************************************************************
* FUNCTION
*  srv_sensor_motion_data_hdlr
* DESCRIPTION
*  tilt event data handler
* PARAMETERS
*  msg_ptr     [IN]        Msg data pointer
* RETURNS
*  void
*****************************************************************************/
static void srv_sensor_motion_data_hdlr(void *msg_ptr)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	MotionSensorDataStruct            		   ms_data[2];
	srv_sensor_motion_msg_struct               *msg_data_ptr;
	srv_sensor_motion_acc_history_struct        history;
	MYQUEUE message;
	srv_sensor_motion_action_enum         motion_action;
	srv_sensor_motion_direct_enum  		  motion_direct;
	srv_sensor_motion_shake_action_enum       	  shake;
	//module_type                         	  module_id;

	char x[20]=0;
	char y[20]=0;
	char z[20]=0;

	//kal_uint32 time_ms;
#ifdef __MTK_TARGET__
	mCubeLibResult_t mcube_result;
#endif

	//static U8 universal_filter_level = 0;
	U8 need_push_data_to_mcube = 0;       



	U8  ms_index = 0, i;
	MMI_BOOL    need_mute = MMI_FALSE, is_has_data = MMI_TRUE;

#ifdef MDI_MOTION_DRIVER_AVAIALBE

    MotionSensorQueryStruct unit;

#endif /*MDI_MOTION_DRIVER_AVAIALBE*/

	U32 threshold = 0;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	msg_data_ptr = (srv_sensor_motion_msg_struct*) msg_ptr;
	if (msg_data_ptr->data_state == MOTION_DATA_EPMTY)
	{
		MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_DATA_EMPTY);
		return;
	}
	//module_id = stack_get_active_module_id();
	/* if has buffer, get data and text if pass threshold or not */
	if ((msg_data_ptr->data_state == MOTION_DATA_EXIST) || (msg_data_ptr->data_state == MOTION_DATA_FULL))
	{
		is_has_data = motion_sensor_get_data(&ms_data[1 - ms_index]);
		MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_TILT_GET_DATA);
		if (is_has_data == MMI_TRUE)
		{
			/*read out all the data and callback app with last one*/
			for (i = 0;i < 50; i++)
			{
				is_has_data = motion_sensor_get_data(&ms_data[ms_index]);
				MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_TILT_GET_DATA);
				ms_index = 1 - ms_index;
				if (is_has_data != MMI_TRUE)
				{
					break;
				}
			}
			motion_sensor_flush_buff();
			/*fill acceleration data to xyz*/
			MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_PRT_DATA_FROM_DRV,
				ms_data[ms_index].x_acc,
				ms_data[ms_index].y_acc,
				ms_data[ms_index].z_acc);
			{
				MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_CALI_NOT_USE);
				/*driver's x y z axis is not same to MDI's*/
				g_srv_sensor_motion_cntx.detail_info.acc_x = ms_data[ms_index].x_acc;
				g_srv_sensor_motion_cntx.detail_info.acc_y = (-1) * ms_data[ms_index].y_acc;
				g_srv_sensor_motion_cntx.detail_info.acc_z = ms_data[ms_index].z_acc;
				g_srv_sensor_motion_cntx.detail_info.sensor_data.status = ms_data[ms_index].motion_info;
				g_srv_sensor_motion_cntx.detail_info.sensor_data.timeStampMs = (kal_uint64)ms_data[ms_index].timeStampMs;
			}

		//	kal_prompt_trace(MOD_MMI,"[mcube]acc_x:%d,acc_y:%d,acc_z:%d",g_srv_sensor_motion_cntx.detail_info.acc_x,
		//		g_srv_sensor_motion_cntx.detail_info.acc_y,g_srv_sensor_motion_cntx.detail_info.acc_z);

			/*push data to history for shake check*/
			history.acc_x = g_srv_sensor_motion_cntx.detail_info.acc_x;
			history.acc_y = g_srv_sensor_motion_cntx.detail_info.acc_y;
			srv_sensor_motion_shake_add_to_history(&history);       /* For shake */

			/*calc all infomation at MMI task*/
			/*calc tilt for all task here*/
			for (i = 0; i < MOTION_SUPPORT_APP_NUM; i++)
			{
				if (g_srv_sensor_motion_cntx.app[i].mod_id == MOD_NIL)
				{
					MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_FIND_NIL_MOD_BREAK, i);
					break;
				}
				MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_MOD_ID,g_srv_sensor_motion_cntx.app[i].mod_id);
				if (g_srv_sensor_motion_cntx.app[i].direct_callback != NULL ||
					g_srv_sensor_motion_cntx.app[i].tilt_callback != NULL)
				{
					MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_TILT_CALC_ACTION,i);
					/*calc angle of gx gy gz*/
					MOTION_ENTER_PROTECT;
					srv_sensor_motion_calc_angle_gxyz_by_xy(
						g_srv_sensor_motion_cntx.detail_info.acc_x,
						g_srv_sensor_motion_cntx.detail_info.acc_y,
						g_srv_sensor_motion_cntx.detail_info.acc_z,
						&g_srv_sensor_motion_cntx.detail_info.angle_gx,
						&g_srv_sensor_motion_cntx.detail_info.angle_gy,
						&g_srv_sensor_motion_cntx.detail_info.angle_gz);

					/*calc direction of the motion*/
					motion_direct = srv_sensor_motion_calc_axis_direct(
						g_srv_sensor_motion_cntx.app[i].direct_sen.angle_threshold,
						g_srv_sensor_motion_cntx.detail_info.angle_gx,
						g_srv_sensor_motion_cntx.detail_info.angle_gy,
						g_srv_sensor_motion_cntx.detail_info.angle_gz,
						g_srv_sensor_motion_cntx.detail_info.acc_x,
						g_srv_sensor_motion_cntx.detail_info.acc_y);


					kal_prompt_trace(MOD_MMI,"Sensor service gx=%d,gy=%d,gz=%d",
						g_srv_sensor_motion_cntx.detail_info.angle_gx,
						g_srv_sensor_motion_cntx.detail_info.angle_gy,
						g_srv_sensor_motion_cntx.detail_info.angle_gz);

					/*calc action of the motion*/
					motion_action = srv_sensor_motion_calc_action(g_srv_sensor_motion_cntx.app[i].prev_direct,
						motion_direct);
					/* get direct tilt data for each app */
					g_srv_sensor_motion_cntx.app[i].direct.direct = motion_direct;
					g_srv_sensor_motion_cntx.app[i].direct.action = motion_action;
					g_srv_sensor_motion_cntx.app[i].tilt.angle.gx = g_srv_sensor_motion_cntx.detail_info.angle_gx;
					g_srv_sensor_motion_cntx.app[i].tilt.angle.gy = g_srv_sensor_motion_cntx.detail_info.angle_gy;
					g_srv_sensor_motion_cntx.app[i].tilt.angle.gz = g_srv_sensor_motion_cntx.detail_info.angle_gz;
					g_srv_sensor_motion_cntx.app[i].tilt.acc.x = g_srv_sensor_motion_cntx.detail_info.acc_x;
					g_srv_sensor_motion_cntx.app[i].tilt.acc.y = g_srv_sensor_motion_cntx.detail_info.acc_y;
					g_srv_sensor_motion_cntx.app[i].tilt.acc.z = g_srv_sensor_motion_cntx.detail_info.acc_z;

		

					/* If user set normal tilt (or default), it will filter noise
					this part will calculate filter noise acc_xyz*/

					if (g_srv_sensor_motion_cntx.app[i].tilt_sen.sensitive == SRV_SENSOR_MOTION_NORMAL_TILT)
					{
						#ifdef MDI_MOTION_DRIVER_AVAIALBE

						motion_sensor_get_sensor_params(MS_ACC_DATA_RESOLUTION,&unit);	/* call driver api*/
					    threshold = unit.curr_val * 3;

						#endif /*MDI_MOTION_DRIVER_AVAIALBE*/

						kal_prompt_trace(MOD_MMI,"Filter nosie: threshold = %d",threshold);

						new_x = g_srv_sensor_motion_cntx.detail_info.acc_x;
					    new_y = g_srv_sensor_motion_cntx.detail_info.acc_y;
					    new_z = g_srv_sensor_motion_cntx.detail_info.acc_z;
					
					    if (abs(old_x - new_x) <= threshold)
						    g_srv_sensor_motion_cntx.app[i].tilt.acc.x = old_x;
					    else
					    {
						    g_srv_sensor_motion_cntx.app[i].tilt.acc.x = new_x;
						    old_x = new_x;
					    }
					    if (abs(old_y - new_y) <= threshold)
						    g_srv_sensor_motion_cntx.app[i].tilt.acc.y = old_y;
					    else
					    {
						    g_srv_sensor_motion_cntx.app[i].tilt.acc.y = new_y;
					        old_y = new_y;
					    }
					    if (abs(old_z - new_z) <= threshold)
						    g_srv_sensor_motion_cntx.app[i].tilt.acc.z = old_z;
					    else
					    {
						    g_srv_sensor_motion_cntx.app[i].tilt.acc.z = new_z;
						    old_z = new_z;
					    }


					    /* Caculate angle through filter noise acc*/
					    srv_sensor_motion_calc_angle_gxyz_by_xy(
						    g_srv_sensor_motion_cntx.app[i].tilt.acc.x,
						    g_srv_sensor_motion_cntx.app[i].tilt.acc.y,
						    g_srv_sensor_motion_cntx.app[i].tilt.acc.z,
						    &g_srv_sensor_motion_cntx.app[i].tilt.angle.gx,
						    &g_srv_sensor_motion_cntx.app[i].tilt.angle.gy,
						    &g_srv_sensor_motion_cntx.app[i].tilt.angle.gz);				
					 }

					MOTION_EXIT_PROTECT;
				}
				//  MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MOTION_SHAKE_STATE,
				//       g_srv_sensor_motion_cntx.app[i].shake_callback, i, g_srv_sensor_motion_cntx.is_shake_mute);

				if (g_srv_sensor_motion_cntx.app[i].shake_callback != NULL &&
					g_srv_sensor_motion_cntx.is_shake_mute == MMI_FALSE)
				{
					/*check shake here*/
					shake = srv_sensor_motion_calc_shake(g_srv_sensor_motion_cntx.history, g_srv_sensor_motion_cntx.app[i].shake_sen.sensitive);
					g_srv_sensor_motion_cntx.app[i].shake.action = shake;

				//	kal_prompt_trace(MOD_MMI,"Motion sensor: Shake action = %d",shake);

					if (shake != SRV_SENSOR_MOTION_SHAKE_NULL)
					{
						need_mute = MMI_TRUE;
					}
				}

				/* For porting mCube library */


				if (g_srv_sensor_motion_cntx.app[i].tap_callback != NULL ||
					g_srv_sensor_motion_cntx.app[i].double_tap_callback != NULL
					|| g_srv_sensor_motion_cntx.app[i].advanced_shake_callback != NULL
					|| g_srv_sensor_motion_cntx.app[i].step_callback != NULL
					|| g_srv_sensor_motion_cntx.app[i].drop_callback != NULL
					|| g_srv_sensor_motion_cntx.app[i].turnover_callback != NULL)
				{
					/*There is APP register mCube,need push data*/
					need_push_data_to_mcube = 1;

				}
				else
					need_push_data_to_mcube = 0;

			} /*end for*/

			if (need_push_data_to_mcube == 1)
			{
				/* translate acc_xyz to mcube acc_xyz (milli-g to m/s2))*/
				srv_sensor_motion_get_acc(g_srv_sensor_motion_cntx.detail_info.acc_x,
					g_srv_sensor_motion_cntx.detail_info.acc_y,
					g_srv_sensor_motion_cntx.detail_info.acc_z,
					&g_srv_sensor_motion_cntx.detail_info.sensor_data.mcube_acc_x,
					&g_srv_sensor_motion_cntx.detail_info.sensor_data.mcube_acc_y,
					&g_srv_sensor_motion_cntx.detail_info.sensor_data.mcube_acc_z
					);

#ifdef __MTK_TARGET__
				/* mCube library process data */
				mcube_result = mCube_LibProcessData(MCUBE_LIB_ACCEL, 
					(void *)&g_srv_sensor_motion_cntx.detail_info.sensor_data, 1);
#endif

				/* Trace */

			//	kal_prompt_trace(MOD_MMI,"[mcube]mCube_LibProcessData : %d", mcube_result);

				sprintf((char *)x,"%6.5f",(float)g_srv_sensor_motion_cntx.detail_info.sensor_data.mcube_acc_x);
				sprintf((char *)y,"%6.5f",(float)g_srv_sensor_motion_cntx.detail_info.sensor_data.mcube_acc_y);
				sprintf((char *)z,"%6.5f",(float)g_srv_sensor_motion_cntx.detail_info.sensor_data.mcube_acc_z);

				kal_prompt_trace(MOD_MMI,"[mcube] x:%s, y:%s, z:%s, status: %x, time:%d", 
					x,
					y,
					z,
					g_srv_sensor_motion_cntx.detail_info.sensor_data.status,
					g_srv_sensor_motion_cntx.detail_info.sensor_data.timeStampMs);
			}
			/*if need mute shake detect for a while*/
			if (need_mute)
			{
				g_srv_sensor_motion_cntx.is_shake_mute = MMI_TRUE;
				gui_start_timer(MOTION_SHAKE_DET_MUTE_DURATION, srv_sensor_motion_shake_det_mute_timeout);
			}
			/*callback app with data or send message to right task*/
			srv_sensor_motion_update_hldr();
			for (i = 0; i < MOTION_SUPPORT_APP_NUM; i++)
			{
				if (g_srv_sensor_motion_cntx.app[i].mod_id == MOD_NIL)
				{
					MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_SEND_MSG_MOD_EQ_NIL,i);
					break;
				}
				if (g_srv_sensor_motion_cntx.app[i].mod_id != MOTION_RUN_MOD &&
					g_srv_sensor_motion_cntx.app[i].is_msg_send == MMI_FALSE)
				{
					message.oslMsgId = MSG_ID_MDI_MOTION_UPDATE_RSP;
					message.oslDataPtr = NULL;
					message.oslPeerBuffPtr = NULL;
					message.oslSrcId = MOTION_RUN_MOD;
					message.oslDestId = g_srv_sensor_motion_cntx.app[i].mod_id;
					OslMsgSendExtQueue(&message);
					g_srv_sensor_motion_cntx.app[i].is_msg_send = MMI_TRUE;
				}
			}
		}
	}
	/* set this flag false, allows next messge */
	g_srv_sensor_motion_cntx.is_msg_send = MMI_FALSE;
}



/* Through callback data get detail info for advanced shake */

static void srv_sensor_motion_cal_advanced_shake(void *data, U32 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8 shakeData = 0;
	/*
	uint8_t shake_x;
	uint8_t shake_y;
	uint8_t shake_z;
	*/

	/*----------------------------------------------------------------*/
	/* Code body                                                      */
	/*----------------------------------------------------------------*/
	shakeData = (*(int*)data & 0xFF);

	g_srv_sensor_motion_cntx.app[index].advanced_shake.direction = shakeData;

}

/* Through callback data get detail info for tap */

static srv_sensor_motion_cal_tap(void *data, U32 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												 */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code body 													 */
	/*----------------------------------------------------------------*/
	g_srv_sensor_motion_cntx.app[index].tap.tap_direct = SRV_SENSOR_MOTION_TAP_DONE;

}

/* Through callback data get detail info for double tap */

static srv_sensor_motion_cal_doubletap(void *data, U32 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												 */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code body													 */
	/*----------------------------------------------------------------*/
	g_srv_sensor_motion_cntx.app[index].double_tap.double_tap_direct = SRV_SENSOR_MOTION_TAP_DONE;

}


/* Through callback data get detail info for turnover (flip) */

static void srv_sensor_motion_cal_turnover(void *data, U32 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												 */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code body 													 */
	/*----------------------------------------------------------------*/

	mCubeFlipEvent_t *flip = (mCubeFlipEvent_t*)data;

	switch (*flip)
	{
	case FLIP_FRONT_TO_BACK:
		g_srv_sensor_motion_cntx.app[index].turnover.direction= SRV_SENSOR_MOTION_TURNOVER_DOWN;
		break;
	case FLIP_BACK_TO_FRONT:
		g_srv_sensor_motion_cntx.app[index].turnover.direction= SRV_SENSOR_MOTION_TURNOVER_UP;
		break;
	default:
		g_srv_sensor_motion_cntx.app[index].turnover.direction= SRV_SENSOR_MOTION_TURNOVER_NONE;
		break;
	}
}


#ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
static void srv_sensor_motion_cal_step(void *data, U32 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												 */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code body													 */
	/*----------------------------------------------------------------*/
	g_srv_sensor_motion_cntx.app[index].step.action = SRV_SENSOR_MOTION_ACTION_STEP;	
}
#endif /*__MOTION_SENSOR_ADVANCED_GESTURE__*/

static void srv_sensor_motion_cal_drop(void *data, U32 index)
{	
	/*----------------------------------------------------------------*/
	/* Local Variables												 */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code body													 */
	/*----------------------------------------------------------------*/
	g_srv_sensor_motion_cntx.app[index].drop.action = SRV_SENSOR_MOTION_ACTION_DROP;	
}






#ifdef __MTK_TARGET__

/** mCube_LibHandler
*
* This function is invoked by the mCube Sensor Library to provide event
* notifications, and when interaction with the sensor driver is required.
*/
mCubeLibResult_t mCube_LibHandler(mCubeLibSens_t sensor,
								  mCubeLibEvent_t event,
								  void *data)
{

	module_type 	   module_id;	

	mCubeLibResult_t retVal = MCUBE_LIB_SUCCESS;
	U8 i = 0;
	module_id = stack_get_active_module_id();


//	kal_prompt_trace(MOD_MMI,"[mcube]Call mCube_LibHandler %d ", event);

	if (MCUBE_LIB_ACCEL == sensor) {		

		for (i = 0; i<MOTION_SUPPORT_APP_NUM; i++)
		{
			if (g_srv_sensor_motion_cntx.app[i].mod_id == module_id)
			{
				/* Advanced shake callback */

				if(g_srv_sensor_motion_cntx.app[i].advanced_shake_callback!= NULL &&
					MCUBE_LIB_SHAKE == event)
				{
					/* call back direct function*/
					/* Get shake data */
					srv_sensor_motion_cal_advanced_shake(data,i);

					/* Call back */
					g_srv_sensor_motion_cntx.app[i].advanced_shake_callback(SRV_SENSOR_MOTION_ADVANCED_SHAKE, 
						&(g_srv_sensor_motion_cntx.app[i].advanced_shake),
						g_srv_sensor_motion_cntx.app[i].advanced_shake_user_data);

					/* Trace */
					kal_prompt_trace(MOD_MMI,"[mcube]advanced_shake_callback! %d",
						g_srv_sensor_motion_cntx.app[i].advanced_shake.direction);

				}

				/* Tap callback */
				if(g_srv_sensor_motion_cntx.app[i].tap_callback != NULL &&
					MCUBE_LIB_TAP == event)
				{

					srv_sensor_motion_cal_tap(data,i);
					g_srv_sensor_motion_cntx.app[i].tap_callback(SRV_SENSOR_MOTION_TAP,
						&(g_srv_sensor_motion_cntx.app[i].tap),
						g_srv_sensor_motion_cntx.app[i].tap_user_data);

					/* Trace */
					kal_prompt_trace(MOD_MMI,"Motion sensor: tap callback!!!");

				}

				/* Double Tap callback */
				if(g_srv_sensor_motion_cntx.app[i].double_tap_callback != NULL &&
					MCUBE_LIB_DOUBLE_TAP == event)
				{
					srv_sensor_motion_cal_doubletap(data,i);
					g_srv_sensor_motion_cntx.app[i].double_tap_callback(SRV_SENSOR_MOTION_DOUBLE_TAP,
						&(g_srv_sensor_motion_cntx.app[i].double_tap),
						g_srv_sensor_motion_cntx.app[i].double_tap_user_data);
					/* Trace */
					kal_prompt_trace(MOD_MMI,"Motion sensor: double tap callback!!!");
				}	

				/* Turnover callback */
				if(g_srv_sensor_motion_cntx.app[i].turnover_callback != NULL &&
					MCUBE_LIB_FLIP == event)
				{

					srv_sensor_motion_cal_turnover(data,i);

					g_srv_sensor_motion_cntx.app[i].turnover_callback(SRV_SENSOR_MOTION_TURNOVER,
						&(g_srv_sensor_motion_cntx.app[i].turnover),
						g_srv_sensor_motion_cntx.app[i].turnover_user_data);

					kal_prompt_trace(MOD_MMI,"Motion sensor: flip callback!!!");
				}


#ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
				/* Step callback */
				if(g_srv_sensor_motion_cntx.app[i].step_callback != NULL &&
					MCUBE_LIB_STEP == event)
				{
					kal_prompt_trace(MOD_MMI,"Motion sensor: step callback!!!");

					srv_sensor_motion_cal_step(data,i);

					g_srv_sensor_motion_cntx.app[i].step_callback(SRV_SENSOR_MOTION_STEP,
						&(g_srv_sensor_motion_cntx.app[i].step),
						g_srv_sensor_motion_cntx.app[i].step_user_data);
				}
#endif /*__MOTION_SENSOR_ADVANCED_GESTURE__*/

				/* Drop callback */
				if(g_srv_sensor_motion_cntx.app[i].drop_callback != NULL &&
					MCUBE_LIB_DROP == event)
				{
					kal_prompt_trace(MOD_MMI,"Motion sensor: drop callback!!!");

					srv_sensor_motion_cal_drop(data,i);

					g_srv_sensor_motion_cntx.app[i].drop_callback(SRV_SENSOR_MOTION_DROP,
						&(g_srv_sensor_motion_cntx.app[i].drop),
						g_srv_sensor_motion_cntx.app[i].drop_user_data);
				}

				g_srv_sensor_motion_cntx.app[i].is_msg_send = MMI_FALSE;
			}
		}				 

	}
	return retVal;
}

#endif /* __MTK_TARGET__*/




/*****************************************************************************
* FUNCTION
*  srv_sensor_motion_update_hldr
* DESCRIPTION
*  the function run at caller task to callback the application
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_sensor_motion_update_hldr(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	module_type        module_id;   
	U32 i;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	module_id = stack_get_active_module_id();

	/*This is for an abnormal case. If there is no sensor chip or sensor chip is
	abnormal, acc_x,acc_y,acc_z will be all zero, but it is wrong, so sensor service
	will not callback application */

	if (g_srv_sensor_motion_cntx.detail_info.acc_x == 0 &&
		g_srv_sensor_motion_cntx.detail_info.acc_y == 0 &&
		g_srv_sensor_motion_cntx.detail_info.acc_z == 0 )
	{
		kal_prompt_trace(MOD_MMI,"Motion sensor: It is an abnormal case,acc_x=0,acc_y=0,acc_z=0");
		return;
	}
	

	for (i = 0; i<MOTION_SUPPORT_APP_NUM; i++)
	{
		if (g_srv_sensor_motion_cntx.app[i].mod_id == module_id)
		{
			/*call app with last right data*/

			if(g_srv_sensor_motion_cntx.app[i].direct_callback != NULL &&
				g_srv_sensor_motion_cntx.app[i].direct.direct != g_srv_sensor_motion_cntx.app[i].prev_direct)
			{
				/* call back direct function*/
				//srv_sensor_type_enum sensor_type, void *sensor_data, void *user_data
				g_srv_sensor_motion_cntx.app[i].direct_callback(SRV_SENSOR_MOTION_DIRECT, 
					&(g_srv_sensor_motion_cntx.app[i].direct),
					g_srv_sensor_motion_cntx.app[i].direct_user_data);

			}
			if(g_srv_sensor_motion_cntx.app[i].shake_callback != NULL &&
				g_srv_sensor_motion_cntx.app[i].shake.action != SRV_SENSOR_MOTION_SHAKE_NULL)
			{

				kal_prompt_trace(MOD_MMI,"Motion sensor: Shake callback!!!");


				g_srv_sensor_motion_cntx.app[i].shake_callback(SRV_SENSOR_MOTION_SHAKE,
					&(g_srv_sensor_motion_cntx.app[i].shake),
					g_srv_sensor_motion_cntx.app[i].shake_user_data);
				g_srv_sensor_motion_cntx.app[i].shake.action = SRV_SENSOR_MOTION_SHAKE_NULL;
			}
			if(g_srv_sensor_motion_cntx.app[i].tilt_callback != NULL)
			{
				g_srv_sensor_motion_cntx.app[i].tilt_callback(SRV_SENSOR_MOTION_TILT,
					&(g_srv_sensor_motion_cntx.app[i].tilt),
					g_srv_sensor_motion_cntx.app[i].tilt_user_data);

				kal_prompt_trace(MOD_MMI,"Filter noise x=%d,y=%d,z=%d",
					g_srv_sensor_motion_cntx.app[i].tilt.acc.x,
					g_srv_sensor_motion_cntx.app[i].tilt.acc.y,
					g_srv_sensor_motion_cntx.app[i].tilt.acc.z);

				kal_prompt_trace(MOD_MMI,"Filter noise (raw) x=%d,y=%d,z=%d",
					g_srv_sensor_motion_cntx.app[i].tilt.acc.x,
					g_srv_sensor_motion_cntx.app[i].tilt.acc.y,
					g_srv_sensor_motion_cntx.app[i].tilt.acc.z);

				
			}            
			srv_sensor_motion_push_direct2history(
				g_srv_sensor_motion_cntx.app[i].direct.direct, 
				&g_srv_sensor_motion_cntx.app[i]);
			g_srv_sensor_motion_cntx.app[i].is_msg_send = MMI_FALSE;
		}
	}
}


/*****************************************************************************
* FUNCTION
*  mdi_motion_shake_add_to_history
* DESCRIPTION
*  add a data to history
* PARAMETERS
*  *history           [IN]        pointer to the history structure
* RETURNS
*  void
*****************************************************************************/
static void srv_sensor_motion_shake_add_to_history(srv_sensor_motion_acc_history_struct *history)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	memcpy(&g_srv_sensor_motion_cntx.history[1],
		&g_srv_sensor_motion_cntx.history[0],
		sizeof(srv_sensor_motion_acc_history_struct) * (MOTION_SHAKE_HISTORY_DEPTH - 1));
	memcpy(&g_srv_sensor_motion_cntx.history[0], history, sizeof(srv_sensor_motion_acc_history_struct));
}





/*****************************************************************************
* FUNCTION
*  mdi_motion_tilt_calc_angle_gxyz_by_xy
* DESCRIPTION
*  calc gx gy gz angle by acc of x y only
* PARAMETERS
*  int_x           [IN]        acc at x axis with direction
*  int_y           [IN]        acc at y axis with direction
*  int_z           [IN]        dummy input now
*  *out_angle_gx   [IN]        the pointer to the gx angle output
*  *out_angle_gy   [IN]        the pointer to the gy angle output
*  *out_angle_gz   [IN]        the pointer to the gz angle output
* RETURNS
*  void
*****************************************************************************/
static void srv_sensor_motion_calc_angle_gxyz_by_xy(
	S32 int_x, S32 int_y, S32 int_z, 
	S32 *out_angle_gx, S32 *out_angle_gy, S32 *out_angle_gz)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U32 square_g;
	float actual_g;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	square_g = int_x * int_x + int_y * int_y + int_z * int_z;

	actual_g = sqrt(square_g);

	if (int_x >= 0)
	{
		*out_angle_gx = (S32)(acos(abs(int_x)/actual_g)/PI * 180.0);
	}
	else
	{
		*out_angle_gx = 180.0 - (S32)(acos(abs(int_x)/actual_g)/PI * 180.0);
	}
	if (int_y >=0)
	{
		*out_angle_gy = (S32)(acos(abs(int_y)/actual_g)/PI * 180.0);
	}
	else
	{
		*out_angle_gy = 180.0 - (S32)(acos(abs(int_y)/actual_g)/PI * 180.0);
	}
	if (int_z >= 0)
	{
		*out_angle_gz = (S32)(acos(abs(int_z)/actual_g)/PI * 180.0);
	}
	else
	{
		*out_angle_gz = 180.0 - (S32)(acos(abs(int_z)/actual_g)/PI * 180.0);
	}

}

/*****************************************************************************
* FUNCTION
*  srv_sensor_motion_direct_debounce
* DESCRIPTION
*  Direct debounce
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/

static void srv_sensor_motion_direct_debounce(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (g_direction == g_old_direction)
	{
	    //kal_prompt_trace(MOD_MMI,"Sensor service g_real_direction = g_old_direction");
		g_real_direction = g_old_direction;
	}
	else
	{
		g_real_direction = SRV_SENSOR_MOTION_ANGLE_OTHER;
		//kal_prompt_trace(MOD_MMI,"Sensor service SRV_SENSOR_MOTION_ANGLE_OTHER");
	}
}

/*****************************************************************************
* FUNCTION
*  mdi_motion_tilt_calc_axis_direct
* DESCRIPTION
*  calc if near the axis of x y or z
* PARAMETERS
*  sensitive       [IN]        sensitive
*  angle_gx        [IN]        angle of g and x axis
*  angle_gy        [IN]        angle of g and y axis
*  angle_gz        [IN]        angle of g and z axis
*  acc_x           [IN]        acc of x axis
*  acc_y           [IN]        acc of y axis
* RETURNS
*  mdi_motion_angle_enum the direction of axis    
*****************************************************************************/
static srv_sensor_motion_direct_enum
srv_sensor_motion_calc_axis_direct(U8 sensitive, S32 angle_gx, S32 angle_gy, S32 angle_gz, S32 acc_x, S32 acc_y)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8 threshold = MOTION_ANGLE_SENS_NORMAL_THRESHOLD;
	//U32 boundary_down, boundary_up;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	if(sensitive > 40)
	{
		sensitive = 40;
	}
	if(sensitive < 0)
	{
		sensitive = 0;
	}

	threshold = sensitive;

	if (angle_gx <= threshold)
	{
		g_direction = SRV_SENSOR_MOTION_ANGLE_GX0;
	}
	else if (angle_gx >= MOTION_ANGLE_180 - threshold)
	{
		g_direction = SRV_SENSOR_MOTION_ANGLE_GX180;
	}
	else if (angle_gy <= threshold)
	{
		g_direction = SRV_SENSOR_MOTION_ANGLE_GY0;
	}
	else if (angle_gy >= MOTION_ANGLE_180 - threshold)
	{
		g_direction = SRV_SENSOR_MOTION_ANGLE_GY180;
	}
	else if (angle_gz <= threshold)
	{
		g_direction = SRV_SENSOR_MOTION_ANGLE_GZ0;
	}
	else if (angle_gz > MOTION_ANGLE_180 - threshold)
	{
		g_direction = SRV_SENSOR_MOTION_ANGLE_GZ180;
	}
	
	else 
		g_direction = SRV_SENSOR_MOTION_ANGLE_OTHER;



	if (g_direction != g_old_direction)
	{
		g_old_direction = g_direction;
		StopTimer(SRV_MOTION_DIRECT_TIMER_ID);
		StartTimer(SRV_MOTION_DIRECT_TIMER_ID, MOTION_DIRECT_DEBOUNCE, srv_sensor_motion_direct_debounce);
	}

    //kal_prompt_trace(MOD_MMI,"Sensor service direction is %d",g_real_direction);
	return g_real_direction;
}


/*****************************************************************************
* FUNCTION
*  mdi_motion_tilt_calc_action
* DESCRIPTION
*  calc the rotate action
* PARAMETERS
*  old_direct      [IN]        old direction of axis direction
*  new_direct      [IN]        new direction of axis direction
* RETURNS
*  mdi_motion_tilt_calc_action the aciton of rotate
*****************************************************************************/
static srv_sensor_motion_action_enum
srv_sensor_motion_calc_action(srv_sensor_motion_direct_enum old_direct, srv_sensor_motion_direct_enum new_direct)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_sensor_motion_action_enum action = SRV_SENSOR_MOTION_ACTION_NULL;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	switch (new_direct)
	{
		/*Y equ 0*/
	case SRV_SENSOR_MOTION_ANGLE_GY0:
		switch (old_direct)
		{
		case SRV_SENSOR_MOTION_ANGLE_GX0:
			action = SRV_SENSOR_MOTION_ACTION_ROLL_RIGHT;
			break;
		case SRV_SENSOR_MOTION_ANGLE_GX180:
			action = SRV_SENSOR_MOTION_ACTION_ROLL_LEFT;
			break;
		case SRV_SENSOR_MOTION_ANGLE_GZ0:
			action = SRV_SENSOR_MOTION_ACTION_PITCH_BACKWARD;
			break;
		case SRV_SENSOR_MOTION_ANGLE_GZ180:
			action = SRV_SENSOR_MOTION_ACTION_PITCH_FORWARD;
			break;
		default:
			break;
		}
		break;
		/*Y equ 180*/
	case SRV_SENSOR_MOTION_ANGLE_GY180:
		switch (old_direct)
		{
		case SRV_SENSOR_MOTION_ANGLE_GX0:
			action = SRV_SENSOR_MOTION_ACTION_ROLL_LEFT;
			break;
		case SRV_SENSOR_MOTION_ANGLE_GX180:
			action = SRV_SENSOR_MOTION_ACTION_ROLL_RIGHT;
			break;
		case SRV_SENSOR_MOTION_ANGLE_GZ0:
			action = SRV_SENSOR_MOTION_ACTION_PITCH_BACKWARD;
			break;
		case SRV_SENSOR_MOTION_ANGLE_GZ180:
			action = SRV_SENSOR_MOTION_ACTION_PITCH_FORWARD;
			break;
		default:
			break;
		}
		break;
		/*X equ 0*/
	case SRV_SENSOR_MOTION_ANGLE_GX0:
		switch (old_direct)
		{
		case SRV_SENSOR_MOTION_ANGLE_GY0:
			action = SRV_SENSOR_MOTION_ACTION_ROLL_LEFT;
			break;
		case SRV_SENSOR_MOTION_ANGLE_GY180:
			action = SRV_SENSOR_MOTION_ACTION_ROLL_RIGHT;
			break;
		case SRV_SENSOR_MOTION_ANGLE_GZ0:
			action = SRV_SENSOR_MOTION_ACTION_YAW_RIGHT;
			break;
		case SRV_SENSOR_MOTION_ANGLE_GZ180:
			action = SRV_SENSOR_MOTION_ACTION_YAW_LEFT;
			break;
		default:
			break;
		}
		break;
		/*X equ 180*/
	case SRV_SENSOR_MOTION_ANGLE_GX180:
		switch (old_direct)
		{
		case SRV_SENSOR_MOTION_ANGLE_GY0:
			action = SRV_SENSOR_MOTION_ACTION_ROLL_RIGHT;
			break;
		case SRV_SENSOR_MOTION_ANGLE_GY180:
			action = SRV_SENSOR_MOTION_ACTION_ROLL_LEFT;
			break;
		case SRV_SENSOR_MOTION_ANGLE_GZ0:
			action = SRV_SENSOR_MOTION_ACTION_YAW_LEFT;
			break;
		case SRV_SENSOR_MOTION_ANGLE_GZ180:
			action = SRV_SENSOR_MOTION_ACTION_YAW_RIGHT;
			break;
		default:
			break;
		}
		break;
		/*Z equ 0*/
	case SRV_SENSOR_MOTION_ANGLE_GZ0:
		switch (old_direct)
		{
		case SRV_SENSOR_MOTION_ANGLE_GX0:
			action = SRV_SENSOR_MOTION_ACTION_YAW_LEFT;
			break;
		case SRV_SENSOR_MOTION_ANGLE_GX180:
			action = SRV_SENSOR_MOTION_ACTION_YAW_RIGHT;
			break;
		case SRV_SENSOR_MOTION_ANGLE_GY0:
			action = SRV_SENSOR_MOTION_ACTION_PITCH_BACKWARD;
			break;
		case SRV_SENSOR_MOTION_ANGLE_GY180:
			action = SRV_SENSOR_MOTION_ACTION_PITCH_FORWARD;
			break;
		default:
			break;
		}
		break;
		/*Z equ 180*/
	case SRV_SENSOR_MOTION_ANGLE_GZ180:
		switch (old_direct)
		{
		case SRV_SENSOR_MOTION_ANGLE_GX0:
			action = SRV_SENSOR_MOTION_ACTION_YAW_RIGHT;
			break;
		case SRV_SENSOR_MOTION_ANGLE_GX180:
			action = SRV_SENSOR_MOTION_ACTION_YAW_LEFT;
			break;
		case SRV_SENSOR_MOTION_ANGLE_GY0:
			action = SRV_SENSOR_MOTION_ACTION_PITCH_FORWARD;
			break;
		case SRV_SENSOR_MOTION_ANGLE_GY180:
			action = SRV_SENSOR_MOTION_ACTION_PITCH_BACKWARD;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return action;
}

/*****************************************************************************
* FUNCTION
*  mdi_motion_shake_calc_direct
* DESCRIPTION
*  calc direction of shake action
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static srv_sensor_motion_shake_action_enum srv_sensor_motion_calc_shake(srv_sensor_motion_acc_history_struct *history, 
																		srv_sensor_motion_shake_sensitive_enum sensitive)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U32 i, shake_index = 0, threshold = MOTION_SHAKE_THRESHOLD_NORMAL;
	srv_sensor_motion_shake_action_enum    shake_action = SRV_SENSOR_MOTION_SHAKE_NULL;


	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (g_srv_sensor_motion_cntx.is_shake_mute == MMI_TRUE)
	{
		return shake_action;
	}
	switch (sensitive)
	{
	case SRV_SENSOR_MOTION_SHAKE_WEAK:
		threshold = MOTION_SHAKE_THRESHOLD_LOW;
		break;
	case SRV_SENSOR_MOTION_SHAKE_MEDIUM:
		threshold = MOTION_SHAKE_THRESHOLD_NORMAL;
		break;
	case SRV_SENSOR_MOTION_SHAKE_STRONG:
		threshold = MOTION_SHAKE_THRESHOLD_HIGH;
		break;
	default:
		ASSERT(0);
	}
	MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_SHAKE_HISTORY,
		history[0].acc_x,
		history[1].acc_x,
		history[2].acc_x,
		history[3].acc_x,
		history[4].acc_x,
		threshold);
	for (i = 0; i < MOTION_SHAKE_HISTORY_DEPTH - 1 && i < 3; i++)
	{
		if (abs(history[i].acc_x - history[i+1].acc_x) > threshold)
		{
			shake_index = i;
			break;
		}
	}
	for (i = shake_index + 1; i < MOTION_SHAKE_HISTORY_DEPTH - 1; i++)
	{
		if (abs(history[i].acc_x - history[i+1].acc_x) > threshold)
		{
			if (history[shake_index].acc_x - history[shake_index + 1].acc_x > 0 &&
				history[i].acc_x - history[i+1].acc_x < 0)
			{
				shake_action = SRV_SENSOR_MOTION_SHAKING;
				MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_SHAKE_DETECT_DATA,
					shake_action,
					shake_index,
					i,
					i+1,
					history[shake_index].acc_x,
					history[i].acc_x,
					history[i+1].acc_x);
				break;
			}
			else if (history[shake_index].acc_x - history[shake_index + 1].acc_x < 0 &&
				history[i].acc_x - history[i+1].acc_x > 0)
			{
				shake_action = SRV_SENSOR_MOTION_SHAKING;
				MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_SHAKE_DETECT_DATA,
					shake_action,
					shake_index,
					i,
					i+1,
					history[shake_index].acc_x,
					history[i].acc_x,
					history[i+1].acc_x);
				break;
			}
		}
	}
#if 0  /*this part can check up down shake but not work well*/
/* under construction !*/
#endif
	return shake_action;
}


/*****************************************************************************
* FUNCTION
*  mdi_motion_push_action2history
* DESCRIPTION
*  push the action to the history
* PARAMETERS
*  motion_direct   [IN]    direction
*  motion_action   [IN]    action
*  *app_tilt       [IN]    the structure to push the behaver to
* RETURNS
*  void
*****************************************************************************/
static void srv_sensor_motion_push_direct2history(
	srv_sensor_motion_direct_enum motion_direct,
	srv_sensor_motion_app_struct *app_tilt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MOTION_ENTER_PROTECT;
	if (motion_direct != SRV_SENSOR_MOTION_ANGLE_OTHER)
	{
		app_tilt->prev_direct = motion_direct;
	}
	MOTION_EXIT_PROTECT;
}


#endif  /*MDI_MOTION_DRIVER_AVAIALBE*/


/*****************************************************************************
* FUNCTION
*  mdi_motion_message_dispatcher
* DESCRIPTION
*  dispatcher of the mdi motion, this will get message for task needed
* PARAMETERS
*  ilm_ptr        [IN]        ilm_struct data
* RETURNS           
*  MMI_TRUE    message is consumed by this function
*  MMI_FALSE   message is not consumed by this function
*****************************************************************************/
MMI_BOOL srv_sensor_message_dispatcher(void *ilm_ptr)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
#ifdef MDI_MOTION_DRIVER_AVAIALBE
	ilm_struct *ilm_p = ilm_ptr;
	MMI_BOOL handle_msg = MMI_TRUE;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/    
	switch(ilm_p->msg_id)
	{
	case MSG_ID_MDI_MOTION_DATA_STATE_RSP:
		srv_sensor_motion_data_hdlr(ilm_p->local_para_ptr);
		break;
	case MSG_ID_MDI_MOTION_UPDATE_RSP:
		srv_sensor_motion_update_hldr();
		break;
	default:
		handle_msg = MMI_FALSE;
		break;
	}
	return handle_msg;
#else
	return MMI_FALSE;
#endif
}


/*****************************************************************************
* FUNCTION
*  mdi_motion_is_around
* DESCRIPTION
*  check x is around point with threshold
* PARAMETERS
*  x           [IN]    the number want to check
*  point       [IN]    the point want to check if been around
*  threshold   [IN]    the r
* RETURNS
*  MMI_TRUE    x is around point
*  MMI_TRUE    x is not around point
*****************************************************************************/
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
#endif





#endif /* MOTION_SENSOR_SUPPORT */ 



#ifdef MOTION_SENSOR_SUPPORT

/*****************************************************************************
* FUNCTION
*   srv_sensor_is_available
* DESCRIPTION
*   Check whether the sensor(motion ,or future other sensors...) is enable
*
* PARAMETERS
*   handle:           [IN] the sensor type which need to be check 
* RETURNS
*  MMI_BOOL
*****************************************************************************/
extern MMI_BOOL srv_sensor_is_available(srv_sensor_type_enum sensor_type)
{
	switch(sensor_type)
	{
	case SRV_SENSOR_MOTION_DIRECT:	
	case SRV_SENSOR_MOTION_SHAKE:
	case SRV_SENSOR_MOTION_TILT:
		{
#ifdef MOTION_SENSOR_SUPPORT
			return MMI_TRUE;
#endif
			break;
		}
	default:
		break;
	}

	return MMI_FALSE;
}


/* When motion sensor switch is off, service will notify each application */
static srv_sensor_motion_notify_each_app()
{
	U32 i = 0;

	for (i = 0; i<MOTION_SUPPORT_APP_NUM; i++)
	{
		if (g_srv_sensor_motion_cntx.app[i].advanced_shake_callback != NULL)
		{
			g_srv_sensor_motion_cntx.app[i].advanced_shake_callback
				(SRV_SENSOR_DISABLE, 
				NULL,
				g_srv_sensor_motion_cntx.app[i].advanced_shake_user_data);
		}
		if (g_srv_sensor_motion_cntx.app[i].double_tap_callback != NULL)
		{
			g_srv_sensor_motion_cntx.app[i].double_tap_callback
				(SRV_SENSOR_DISABLE, 
				NULL,
				g_srv_sensor_motion_cntx.app[i].double_tap_user_data);
		}
		if (g_srv_sensor_motion_cntx.app[i].tap_callback != NULL)
		{
			g_srv_sensor_motion_cntx.app[i].tap_callback
				(SRV_SENSOR_DISABLE, 
				NULL,
				g_srv_sensor_motion_cntx.app[i].tap_user_data);
		}
		if (g_srv_sensor_motion_cntx.app[i].turnover_callback != NULL)
		{
			g_srv_sensor_motion_cntx.app[i].turnover_callback
				(SRV_SENSOR_DISABLE, 
				NULL,
				g_srv_sensor_motion_cntx.app[i].turnover_user_data);
		}
		if (g_srv_sensor_motion_cntx.app[i].drop_callback != NULL)
		{
			g_srv_sensor_motion_cntx.app[i].drop_callback
				(SRV_SENSOR_DISABLE, 
				NULL,
				g_srv_sensor_motion_cntx.app[i].drop_user_data);
		}
		if (g_srv_sensor_motion_cntx.app[i].step_callback != NULL)
		{
			g_srv_sensor_motion_cntx.app[i].step_callback
				(SRV_SENSOR_DISABLE, 
				NULL,
				g_srv_sensor_motion_cntx.app[i].step_user_data);
		}

		if (g_srv_sensor_motion_cntx.app[i].tilt_callback!= NULL)
		{
			g_srv_sensor_motion_cntx.app[i].tilt_callback
				(SRV_SENSOR_DISABLE, 
				NULL,
				g_srv_sensor_motion_cntx.app[i].tilt_user_data);
		}

		if (g_srv_sensor_motion_cntx.app[i].direct_callback!= NULL)
		{
			g_srv_sensor_motion_cntx.app[i].direct_callback
				(SRV_SENSOR_DISABLE, 
				NULL,
				g_srv_sensor_motion_cntx.app[i].direct_user_data);
		}

		if (g_srv_sensor_motion_cntx.app[i].shake_callback!= NULL)
		{
			g_srv_sensor_motion_cntx.app[i].shake_callback
				(SRV_SENSOR_DISABLE, 
				NULL,
				g_srv_sensor_motion_cntx.app[i].shake_user_data);
		}
	}
}



/* Enable motion sensor, if ture enable , false disable */
void srv_sensor_motion_set_switch(MMI_BOOL is_enable)
{
	if (is_enable == MMI_TRUE)
	{
		if (g_motion_sensor_able == MMI_FALSE)
		{
			MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MMI_TRC_MOTION_POWER_ON);
			srv_sensor_motion_power_on();
			g_srv_sensor_motion_cntx.is_shake_mute = MMI_TRUE;
			gui_start_timer(MOTION_SHAKE_DET_MUTE_DURATION, srv_sensor_motion_shake_det_mute_timeout);
			g_srv_sensor_motion_cntx.is_msg_send = MMI_FALSE;
#ifdef MDI_MOTION_DRIVER_AVAIALBE
			/* register callback to retrive data */
			motion_sensor_cb_registration(srv_sensor_motion_driver_data_state_hdlr, NULL);
			SetProtocolEventHandler(srv_sensor_motion_data_hdlr, MSG_ID_MDI_MOTION_DATA_STATE_RSP);
			motion_sensor_conf_filter(MOTION_THRESHOLD_FOR_DRV);
			/* star sampling */
			motion_sensor_sample(MMI_TRUE);

#endif /* MDI_MOTION_DRIVER_AVAIALBE */ 
		}

		g_motion_sensor_able = MMI_TRUE;
	}
	else
	{
		SetProtocolEventHandler(NULL, MSG_ID_MDI_MOTION_DATA_STATE_RSP);
		srv_sensor_motion_power_off();  //if all request are closed , power off motion
		srv_sensor_motion_notify_each_app();
		g_motion_sensor_able = MMI_FALSE;

	}
	sensor_srv_motion_write_switch(g_motion_sensor_able);
}

MMI_BOOL srv_sensor_motion_get_switch()
{
	return g_motion_sensor_able;
}




extern SRV_SENSOR_RESULT srv_sensor_motion_enable_mode(SRV_SENSOR_HANDLE handler , U16 sensor_mode)
{
	U32 i;

	for (i = 0; i<MOTION_SUPPORT_MAX_MODE; i++)
	{
		if (g_motion_sensor_tab[i].flag == 1 && g_motion_sensor_tab[i].hdlr == handler)
		{
			g_motion_sensor_tab[i].mode = g_motion_sensor_tab[i].mode | sensor_mode;
			return SRV_SENSOR_MOTION_SUCCEED;
		}
	}

	/* No same handler */
	if (i == MOTION_SUPPORT_MAX_MODE)
	{
		for (i = 0; i<MOTION_SUPPORT_MAX_MODE; i++)
		{
			if (g_motion_sensor_tab[i].flag == NULL) //empty slot
			{
				g_motion_sensor_tab[i].hdlr = handler;  //external handler
				g_motion_sensor_tab[i].mode =  sensor_mode;
				g_motion_sensor_tab[i].flag = 1;
				return SRV_SENSOR_MOTION_SUCCEED;
			}
		}
	}

	return SRV_SENSOR_MOTION_NO_SLOT;

}

extern SRV_SENSOR_RESULT srv_sensor_motion_disable_mode(SRV_SENSOR_HANDLE handler, U16 sensor_mode)
{	
	U32 i = 0;
	for (i = 0; i<MOTION_SUPPORT_MAX_MODE; i++)
	{
		if (g_motion_sensor_tab[i].hdlr == handler) 
		{
			kal_prompt_trace(MOD_MMI,"[mcube]disable mode");

			g_motion_sensor_tab[i].mode = g_motion_sensor_tab[i].mode & ~(sensor_mode);
			if (g_motion_sensor_tab[i].mode == SRV_SENSOR_MOTION_NORAML_MODE)
			{
				g_motion_sensor_tab[i].hdlr = NULL;
				g_motion_sensor_tab[i].flag = NULL;
			}
			break;
		}
	}

	if (i == MOTION_SUPPORT_MAX_MODE)
		return SRV_SENSOR_MOTION_INVALID_PARAM;
	else
		return SRV_SENSOR_MOTION_SUCCEED;
}

static void srv_sensor_motion_remove_mode(SRV_SENSOR_HANDLE handler)
{
	U32 i = 0;
	for (i = 0; i<MOTION_SUPPORT_MAX_MODE; i++)
	{
		if (g_motion_sensor_tab[i].hdlr == handler) //empty slot
		{
			kal_prompt_trace(MOD_MMI,"[mcube]Remove mode");
			g_motion_sensor_tab[i].hdlr = NULL;
			g_motion_sensor_tab[i].flag = NULL;
			g_motion_sensor_tab[i].mode = NULL;
			break;
		}

	}
}

static U16 srv_sensor_motion_check_mode()
{
	U32 i = 0;
	U16 sensor_mode = SRV_SENSOR_MOTION_NORAML_MODE;

	for (i = 0; i<MOTION_SUPPORT_MAX_MODE; i++)
	{
		if (g_motion_sensor_tab[i].flag == 1)
		{
			sensor_mode = sensor_mode | g_motion_sensor_tab[i].mode;
		}
	}

	return sensor_mode;	
}


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
#endif



#ifdef MDI_MOTION_DRIVER_AVAIALBE
#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"


static void srv_sensor_motion_cali_hdlr(void *msg_ptr)
{
	srv_sensor_motion_cali_msg_struct *msg_data_ptr;
	mmi_event_struct evt;

	msg_data_ptr = (srv_sensor_motion_cali_msg_struct *)msg_ptr;



	//kal_prompt_trace(MOD_MMI,"[Cali] srv_sensor_motion_cali_hdlr !!");

	switch (msg_data_ptr->cali_status)
	{
	case SRV_SENSOR_MOTION_CALI_FINISHED:

#ifdef MDI_MOTION_DRIVER_AVAIALBE
		motion_sensor_write_cali_to_nvram();
#endif /*MDI_MOTION_DRIVER_AVAIALBE*/

		MMI_FRM_INIT_EVENT(&evt, EVT_ID_SENSOR_MOTION_CALI_FINISHED);

		mmi_frm_cb_emit_post_event(&evt);
		break;
	case SRV_SENSOR_MOTION_CALI_TIMEOUT:
		MMI_FRM_INIT_EVENT(&evt, EVT_ID_SENSOR_MOTION_CALI_TIMEOUT);
		mmi_frm_cb_emit_post_event(&evt);
		break;

		/*
		case SRV_SENSOR_MOTION_CALI_NVRAM_WRITE_FAIL:
		MMI_FRM_INIT_EVENT(&evt, EVT_ID_SENSOR_MOTION_CALI_WRITE_FAIL);
		mmi_frm_cb_emit_post_event(&evt);
		break;
		*/
	}

}

srv_sensor_motion_cali_callback(void *parameter, Motion_Sensor_Cali_Status_enum state)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												*/
	/*----------------------------------------------------------------*/
	MYQUEUE message;
	srv_sensor_motion_cali_msg_struct *msg_data_ptr;

	/*----------------------------------------------------------------*/
	/* Code Body														*/
	/*----------------------------------------------------------------*/
	/*
	if (g_srv_sensor_motion_cntx.is_msg_send == MMI_TRUE)
	{
	return;
	}
	*/

//	kal_prompt_trace(MOD_MMI,"[Cali] srv_sensor_motion_cali_callback !!");

	msg_data_ptr = OslConstructDataPtr(sizeof(srv_sensor_motion_cali_msg_struct));


	switch (state)
	{
	case MS_CALI_FINISHED:
		msg_data_ptr->cali_status = SRV_SENSOR_MOTION_CALI_FINISHED;
		break;

	case MS_CALI_TIMEOUT:
		msg_data_ptr->cali_status = SRV_SENSOR_MOTION_CALI_TIMEOUT;
		break;
	}
	message.oslMsgId = MSG_ID_SRV_SENSOR_MOTION_CALI_RSP;
	message.oslDataPtr = (oslParaType*) msg_data_ptr;
	message.oslPeerBuffPtr = NULL;
	// message.oslSrcId = MOD_DRV_HISR;
	message.oslSrcId = stack_get_active_module_id();
	message.oslDestId = MOTION_RUN_MOD;
	OslMsgSendExtQueue(&message);

}

#pragma arm section code, rodata


#endif /*MDI_MOTION_DRIVER_AVAIALBE*/


extern void srv_sensor_motion_start_cali()
{

#ifdef MDI_MOTION_DRIVER_AVAIALBE

	U32 i = 0;
	MMI_BOOL flag = MMI_TRUE;


	for (i=0; i<MOTION_SUPPORT_APP_NUM; i++)
	{
		if (srv_sensor_callback_handler_count(i) != 0)
		{
			flag = MMI_FALSE;
		//	kal_prompt_trace(MOD_MMI, "have app reg not power on");
			break;
		}
	}
	if (flag)
	{
		kal_prompt_trace(MOD_MMI, " need power on");
		motion_sensor_power(MMI_TRUE);
		//motion_sensor_conf_sample_period(MOTION_SAMPLE_PERIOD);
		motion_sensor_flush_buff();	

		motion_sensor_conf_filter(MOTION_THRESHOLD_FOR_DRV);
		/* star sampling */
		motion_sensor_sample(MMI_TRUE);
	}

	motion_sensor_cali_cb_registration(srv_sensor_motion_cali_callback);





	SetProtocolEventHandler(srv_sensor_motion_cali_hdlr, MSG_ID_SRV_SENSOR_MOTION_CALI_RSP);
	motion_sensor_start_cali();

	//kal_prompt_trace(MOD_MMI,"[Cali] srv_sensor_motion_start_cali !!");

	kal_prompt_trace(MOD_MMI,"Cali hdlr(srv) %x ",srv_sensor_motion_cali_callback);

#endif /*MDI_MOTION_DRIVER_AVAIALBE*/
}

extern void srv_sensor_motion_stop_cali()
{
	U32 i = 0;
	MMI_BOOL flag = MMI_TRUE;

	SetProtocolEventHandler(NULL, MSG_ID_SRV_SENSOR_MOTION_CALI_RSP);


	for (i=0; i<MOTION_SUPPORT_APP_NUM; i++)
	{
		if (srv_sensor_callback_handler_count(i) != 0)
		{
			flag = MMI_FALSE;
			break;
		}
	}

	if (flag)
	{
		srv_sensor_motion_power_off(); 
	}	
}


static MMI_BOOL srv_sensor_motion_set_flip_paremeters(srv_sensor_motion_flip_para_struct * para)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mCubeLibInit_t initData;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/ 
	initData.accelInit.accelOrientation = CHIP_TOP_RIGHT_DOWN;
	initData.accelInit.accelPolaBafrInit.enableUpdate = MMI_TRUE;
	initData.accelInit.accelPolaBafrInit.polaUpdRateHz = 10;

	g_mcube_init.flipEnable = 
		initData.accelInit.accelPolaBafrInit.flipCntrl.flipEnable = para->flipEnable;
	g_mcube_init.flipFilter = 
		initData.accelInit.accelPolaBafrInit.flipCntrl.flipFilter = para->flipFilter;
	g_mcube_init.flipThreshold = 
		initData.accelInit.accelPolaBafrInit.flipCntrl.flipThreshold = para->flipThreshold;
	g_mcube_init.tFlipDebounce = 
		initData.accelInit.accelPolaBafrInit.flipCntrl.tFlipDebounce = para->tFlipDebounce;
	g_mcube_init.tFlipInterval =
		initData.accelInit.accelPolaBafrInit.flipCntrl.tFlipInterval = para->tFlipInterval;

#ifdef __MTK_TARGET__

	if (g_is_reg_mcube == MMI_TRUE) //mcube is open,some app register mcube
	{
		mCube_LibClose();
		mCube_LibOpen(&initData);
	}

#endif

	return MMI_TRUE;

}

static MMI_BOOL srv_sensor_motion_get_flip_paremeters(srv_sensor_motion_flip_para_struct * para)
{
	para->flipEnable = g_mcube_init.flipEnable;
	para->flipFilter = g_mcube_init.flipFilter;
	para->flipThreshold = g_mcube_init.flipThreshold;
	para->tFlipDebounce = g_mcube_init.tFlipDebounce;
	para->tFlipInterval = g_mcube_init.tFlipInterval;
	return MMI_TRUE;
}



static MMI_BOOL srv_sensor_motion_get_tap_paremeters(srv_sensor_motion_get_tap_struct * ms_params)
{

#ifdef MDI_MOTION_DRIVER_AVAIALBE

	//srv_sensor_motion_get_tap_struct tap_plus;
	//srv_sensor_motion_get_tap_struct tap_threshold;

	MotionSensorQueryStruct tap_plus;
	MotionSensorQueryStruct tap_threshold;
	MMI_BOOL res1,res2;


	res1 = motion_sensor_get_sensor_params(MS_TAP_PULSE, &tap_plus);
	res2 = motion_sensor_get_sensor_params(MS_TAP_THRESHOLD, &tap_threshold);

	if (res1 && res2)
	{
		ms_params->get_tap_plus.curr_val = tap_plus.curr_val;
		ms_params->get_tap_plus.max_val = tap_plus.max_val;
		ms_params->get_tap_plus.min_val = tap_plus.min_val;

		ms_params->get_tap_threshold.curr_val = tap_threshold.curr_val;
		ms_params->get_tap_threshold.max_val = tap_threshold.max_val;
		ms_params->get_tap_threshold.min_val = tap_threshold.min_val;

		return MMI_TRUE;
	}
	else

#endif /*MDI_MOTION_DRIVER_AVAIALBE*/
		return MMI_FALSE;

}

static MMI_BOOL srv_sensor_motion_set_tap_parameters(srv_sensor_motion_set_tap_struct * ms_params)
{
	MMI_BOOL res = MMI_TRUE;

#ifdef MDI_MOTION_DRIVER_AVAIALBE

	res = motion_sensor_set_sensor_params(MS_TAP_PULSE, ms_params->set_tap_plus);
	if (res)
		res = motion_sensor_set_sensor_params(MS_TAP_THRESHOLD , ms_params->set_tap_threshold);
#endif /*MDI_MOTION_DRIVER_AVAIALBE*/

	return res;
}


extern MMI_BOOL srv_sensor_motion_set_parameters(srv_sensor_motion_set_type_enum type,void * para)
{
	switch (type)
	{
	case SRV_SENSOR_MOTION_SET_TAP:
		srv_sensor_motion_set_tap_parameters(para);
		return MMI_TRUE;
	case SRV_SENSOR_MOTION_SET_FLIP:
		srv_sensor_motion_set_flip_paremeters(para);
		return MMI_TRUE;
	default:
		break;
	}

	return MMI_FALSE;
}


extern MMI_BOOL srv_sensor_motion_get_parameters(srv_sensor_motion_set_type_enum type,void * para)
{
	switch (type)
	{
	case SRV_SENSOR_MOTION_SET_TAP:
		srv_sensor_motion_get_tap_paremeters(para);
		return MMI_TRUE;
	case  SRV_SENSOR_MOTION_SET_FLIP:
		srv_sensor_motion_get_flip_paremeters(para);
		return MMI_TRUE;
	default:
		break;
	}

	return MMI_FALSE;
}

#endif /*MOTION_SENSOR_SUPPORT*/







#ifdef __PXS_ENABLE__
/*****************************************************************************
* FUNCTION
*  srv_sensor_pxs_poll_hdlr
* DESCRIPTION
*  This function is the timer expiry to poll if detect object away
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/ 
static void srv_sensor_pxs_poll_hdlr(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	MMI_BOOL is_detected = MMI_FALSE;
	mmi_event_struct evt;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	srv_sensor_pxs_get_status(&is_detected);

	if (is_detected == MMI_TRUE)
	{
		/* start the timer to poll the proximity again */
		StartTimer(SRV_PXS_TIMER_ID, SENSOR_PXS_REPEAT_POLLING_TIME, srv_sensor_pxs_poll_hdlr);
	}
	else
	{
		/* the proximity detect the object away, do the notification via callback manager */
		MMI_FRM_INIT_EVENT(&evt, EVT_ID_SENSOR_PXS_DETECT_OBJ_AWAY);
		mmi_frm_cb_emit_post_event(&evt);
	}
}


/*****************************************************************************
* FUNCTION
*  srv_sensor_pxs_detect_obj_hdlr
* DESCRIPTION
*  This function is the protocol event handler of MSG_ID_SRV_SENSOR_PXS_DETECT_OBJECT_IND
* PARAMETERS
*  msg :      [IN] the local param of ilm
* RETURNS
*  void
*****************************************************************************/ 
static void srv_sensor_pxs_detect_obj_hdlr(void *msg)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	mmi_event_struct evt;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	g_pxs_is_indication_in_queue = MMI_FALSE;

	MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, TRC_SRV_SENSOR_PXS_DET_OBJ_CLOSE);
	MMI_FRM_INIT_EVENT(&evt, EVT_ID_SENSOR_PXS_DETECT_OBJ_CLOSE);
	mmi_frm_cb_emit_post_event(&evt);

	/* We will start the timer to polling the proximity detect the object away. */
	StartTimer(SRV_PXS_TIMER_ID, SENSOR_PXS_FIRST_POLLING_TIME, srv_sensor_pxs_poll_hdlr);
}
#endif /*  __PXS_ENABLE__ */


/*****************************************************************************
* FUNCTION
*  srv_sensor_motion_init
* DESCRIPTION
*  init MDI Camera
* PARAMETERS
*  void
* RETURNS
*  MDI_RESULT
*****************************************************************************/
#if defined (MOTION_SENSOR_SUPPORT)||(__PXS_ENABLE__)
mmi_ret srv_sensor_init(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

#ifdef MOTION_SENSOR_SUPPORT
	srv_sensor_motion_init(evt);
#endif

#ifdef __PXS_ENABLE__

	SetProtocolEventHandler(srv_sensor_pxs_detect_obj_hdlr, MSG_ID_SRV_SENSOR_PXS_DETECT_OBJECT_IND);

#endif /* __PXS_ENABLE__ */

	return MMI_RET_OK;
}
#endif /* (MOTION_SENSOR_SUPPORT)||( __PXS_ENABLE__) */


#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"
/*****************************************************************************
* FUNCTION
*  srv_sensor_pxs_cb
* DESCRIPTION
*  This function is the notify callback of PXS
* PARAMETERS
*  fgObjectDetected :      [IN] detect the object close or away
* RETURNS
*  void
*****************************************************************************/ 
#ifdef __PXS_ENABLE__
static void srv_sensor_pxs_cb(DCL_BOOL fgObjectDetected)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	//ilm_struct *pxs_ilm;
	ilm_struct pxs_ilm;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	if (DCL_TRUE == fgObjectDetected && MMI_FALSE == g_pxs_is_indication_in_queue)
	{
		/*
		* When the priximity detect the object close and MMI queue doesn't have
		* MSG_ID_SRV_SENSOR_PXS_DETECT_OBJECT_IND, we will send the primitive.
		*/
		g_pxs_is_indication_in_queue = MMI_TRUE;
		//DRV_BuildPrimitive(pxs_ilm, MOD_DRV_HISR, MOD_MMI, MSG_ID_SRV_SENSOR_PXS_DETECT_OBJECT_IND, NULL);
		// msg_send_ext_queue(pxs_ilm);

		pxs_ilm.oslMsgId = MSG_ID_SRV_SENSOR_PXS_DETECT_OBJECT_IND;
		pxs_ilm.oslDataPtr = NULL;
		pxs_ilm.oslPeerBuffPtr = NULL;
		pxs_ilm.oslSrcId = MOD_DRV_HISR;
		pxs_ilm.oslDestId = MOD_MMI;
		pxs_ilm.sap_id = DRIVER_PS_SAP;

		OslMsgSendExtQueue(&pxs_ilm);
	}
}
#endif /*  __PXS_ENABLE__ */
#pragma arm section code, rodata

#ifdef __PXS_ENABLE__

static void srv_sensor_pxs_set_debounce(void * val)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/	
	DCL_HANDLE	 pxs_handle;
	PXS_CTRL_SET_DEBOUNCE_T pxs_debounce;
	srv_sensor_pxs_set_debounce_struct *srv_sensor = (srv_sensor_pxs_set_debounce_struct *)val;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	pxs_handle = DclPXS_Open(DCL_PXS, NULL);

	pxs_debounce.u4TopAreaDebounce = (DCL_UINT32)(srv_sensor->top_area_debounce);          //5000ms
	pxs_debounce.u4LargerAreaDebounce = (DCL_UINT32)(srv_sensor->larger_area_debounce);    //0ms

	DclPXS_Control(pxs_handle, PXS_CMD_SET_DEBOUNCE, (DCL_CTRL_DATA_T *)&pxs_debounce);
	DclPXS_Close(pxs_handle);

}

/*****************************************************************************
* FUNCTION
*  srv_sensor_pxs_set_value
* DESCRIPTION
*  This function is to set value
* PARAMETERS
*	type:      [IN]For example SRV_SENSOR_PXS_SET_DEBOUNCE
*  val:       pointer of parameter
* RETURNS
*  MMI_BOOL
*****************************************************************************/ 
extern MMI_BOOL srv_sensor_pxs_set_value(srv_sensor_pxs_set_param_type_enum type,void *val)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U32 i = 0;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	for (i=0; i<SRV_SENSOR_PXS_PARAM_TYPE_TOTAL; i++)
	{
		if (g_sensor_srv_pxs_set_val_tab[i].pxs_set_type == type)
		{
			g_sensor_srv_pxs_set_val_tab[i].internal_set_handler(val);
			break;
		}
	}
	if (SRV_SENSOR_PXS_PARAM_TYPE_TOTAL == i)
	{
		return MMI_FALSE;
	}
	return MMI_TRUE;
}

#endif /*  __PXS_ENABLE__ */




/*****************************************************************************
* FUNCTION
*  srv_sensor_pxs_turn_on
* DESCRIPTION
*  This function is to turn on the proximity device
* PARAMETERS
*  void
* RETURNS
*  MMI_TRUE - turn on the proximity device successfully
*  MMI_FALSE - turn on the proximity device fail
*****************************************************************************/ 
MMI_BOOL srv_sensor_pxs_turn_on(void)
{
#ifdef __PXS_ENABLE__
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	DCL_STATUS          pxs_status = STATUS_FAIL;
	PXS_CTRL_ENABLE_T   dcl_ctrl_pxs_enable;
	PXS_CTRL_CONFIG_T   dcl_ctrol_pxs_config;
	mmi_event_struct    evt;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(g_pxs_user_count == 0)
	{
		/* proximity sensor init */
		if (g_pxs_handle > DCL_HANDLE_NONE)
		{
			DclPXS_Close(g_pxs_handle);
		}
		/* get the proximity instance */
		g_pxs_handle = DclPXS_Open(DCL_PXS, 0);
		/* Could get the proximity device */
		MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, TRC_SRV_SENSOR_PXS_OPEN_DEVICE, g_pxs_handle);

		if (g_pxs_handle > DCL_HANDLE_NONE)
		{
			dcl_ctrl_pxs_enable.fgEnable = DCL_TRUE;
			pxs_status = DclPXS_Control(g_pxs_handle, PXS_CMD_ENABLE, (DCL_CTRL_DATA_T  *) &dcl_ctrl_pxs_enable);
			dcl_ctrol_pxs_config.fgNotify = DCL_TRUE;
			dcl_ctrol_pxs_config.NotifyCallback = srv_sensor_pxs_cb;
			pxs_status = DclPXS_Control(g_pxs_handle, PXS_CMD_MODIFY_CONFIG, (DCL_CTRL_DATA_T  *) &dcl_ctrol_pxs_config);
		}

		MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, TRC_SRV_SENSOR_PXS_TURN_ON, g_pxs_handle, pxs_status);
		if (pxs_status < 0)
		{
			g_pxs_res_status = MMI_FALSE;
		}
		else
		{
			MMI_FRM_INIT_EVENT(&evt, EVT_ID_SENSOR_PXS_TURN_ON_NOTIFY);
			mmi_frm_cb_emit_post_event(&evt);
			g_pxs_res_status =  MMI_TRUE;
		}
		// kal_prompt_trace(MOD_MMI, "[SRV_SENSOR_PXS] TURN ON! %d",g_pxs_res_status);
	}
	g_pxs_user_count++;

	// kal_prompt_trace(MOD_MMI, "[SRV_SENSOR_PXS] g_pxs_user_count %d",g_pxs_user_count);
	return g_pxs_res_status;
#else
	return MMI_FALSE;
#endif /*  __PXS_ENABLE__ */
}


/*****************************************************************************
* FUNCTION
*  srv_sensor_pxs_turn_off
* DESCRIPTION
*  This function is to turn off the proximity device
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/ 
void srv_sensor_pxs_turn_off(void)
{
#ifdef __PXS_ENABLE__
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	DCL_STATUS          pxs_status;
	PXS_CTRL_ENABLE_T   dcl_ctrl_pxs_enable;
	mmi_event_struct    evt;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	g_pxs_user_count--;
	//kal_prompt_trace(MOD_MMI, "[SRV_SENSOR_PXS] g_pxs_user_count %d",g_pxs_user_count);
	if (g_pxs_user_count == 0)
	{
		MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, TRC_SRV_SENSOR_PXS_TURN_OFF, g_pxs_handle);
		StopTimer(SRV_PXS_TIMER_ID);
		if (g_pxs_handle > DCL_HANDLE_NONE)
		{
			dcl_ctrl_pxs_enable.fgEnable = DCL_FALSE;
			pxs_status = DclPXS_Control(g_pxs_handle, PXS_CMD_ENABLE, (DCL_CTRL_DATA_T  *) &dcl_ctrl_pxs_enable);
		}

		/* reset PXS handle */
		DclPXS_Close(g_pxs_handle);
		g_pxs_handle = DCL_HANDLE_NONE;
		MMI_FRM_INIT_EVENT(&evt, EVT_ID_SENSOR_PXS_TURN_OFF_NOTIFY);
		mmi_frm_cb_emit_post_event(&evt);

		g_pxs_res_status = MMI_FALSE;
		// kal_prompt_trace(MOD_MMI, "[SRV_SENSOR_PXS] TURN OFF! %d",g_pxs_res_status);
	}

#endif /*  __PXS_ENABLE__ */
}


/*****************************************************************************
* FUNCTION
*  srv_sensor_pxs_get_status
* DESCRIPTION
*  This function is to get the object status from the proximity device
* PARAMETERS
*  fgObjectDetected :  [OUT] get the if detect the object close
* RETURNS
*  MMI_TRUE - get the status of the proximity device successfully
*  MMI_FALSE - get the status of the proximity device fail
*****************************************************************************/ 
MMI_BOOL srv_sensor_pxs_get_status(MMI_BOOL *obj_detected)
{
#ifdef __PXS_ENABLE__
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	DCL_STATUS pxs_status = STATUS_FAIL;
	PXS_CTRL_GET_DETECT_STATUS_T dcl_ctrl_pxs_get_detect_status;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	/* the default value is not non-detected object */
	*obj_detected = MMI_FALSE;


	if (g_pxs_handle > DCL_HANDLE_NONE)
	{
		pxs_status = DclPXS_Control(g_pxs_handle, PXS_CMD_GET_DETECT_STATUS, (DCL_CTRL_DATA_T  *) &dcl_ctrl_pxs_get_detect_status);
		*obj_detected = (MMI_BOOL)dcl_ctrl_pxs_get_detect_status.fgDetected;
	}

	MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, TRC_SRV_SENSOR_PXS_GET_STATUS, g_pxs_handle, *obj_detected, pxs_status);
	return (pxs_status < 0)? MMI_FALSE : MMI_TRUE;
#else
	return MMI_FALSE;
#endif /*  __PXS_ENABLE__ */
}


/*****************************************************************************
* FUNCTION
*  srv_sensor_pxs_get_raw_data
* DESCRIPTION
*  This function is to get PXS raw data
* PARAMETERS
*  em_param :  [OUT] raw data
* RETURNS
*  MMI_TRUE - get PXS raw data successfully
*  MMI_FALSE - get PXS raw data fail
*****************************************************************************/ 
extern MMI_BOOL srv_sensor_pxs_get_raw_data(U16 *em_param)
{
#ifdef __PXS_ENABLE__
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	DCL_STATUS pxs_status = STATUS_FAIL;
	PXS_CTRL_RAW_DATA_T raw_data = {0};

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (g_pxs_handle > DCL_HANDLE_NONE)
	{
		pxs_status = DclPXS_Control(g_pxs_handle, PXS_CMD_GET_RAW_DATA, (DCL_CTRL_DATA_T  *) &raw_data);
		*em_param = raw_data.u2Data;
	}

	MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, TRC_SRV_SENSOR_PXS_GET_RAW_DATA, *em_param, pxs_status);
	return (pxs_status < 0)? MMI_FALSE : MMI_TRUE;
#else
	return MMI_FALSE;
#endif /*  __PXS_ENABLE__ */
}




#if 0
/* under construction !*/
/* under construction !*/
#ifndef __SRV_SENSOR_PXS_UT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
#endif /* if 0 */


#ifdef MOTION_SENSOR_SUPPORT

/*Temp API to avoid link error*/

void UTL_AssertFailed(
					  char const * const fileName,
					  uint32_t           lineNumber)
{

	(void)fileName;
	(void)lineNumber;

#if defined(ANDROID)
	__assert(fileName, lineNumber, "");

#elif ((TOOLCHAIN == TOOLCHAIN_gcc) || (TOOLCHAIN == TOOLCHAIN_ads))
	/* TODO */

#else
	_assert(0, fileName, lineNumber);

#endif

	return;

}  /* UTL_AssertFailed() */

/* Close NVM file */
mCubeLibResult_t mCube_StorageClose(mCubeStorageId_t nvmId)
{
	mCubeLibResult_t retVal = MCUBE_LIB_SUCCESS;

	// mcube_motion_pal_dbg_print("%s: called\r\n", __func__);

	return retVal;
}


/* Initialize the storage module by closing any previously opened
* NVM files prior to invalidating the descriptors.
*/
mCubeLibResult_t mCube_StorageInit(void)
{
	mCubeLibResult_t retVal = MCUBE_LIB_SUCCESS;

	//mcube_motion_pal_dbg_print("%s: called\r\n", __func__);

	return retVal;
}


/* Open specified storage device */
mCubeLibResult_t mCube_StorageOpen(mCubeStorageId_t nvmId)
{
	mCubeLibResult_t retVal = MCUBE_LIB_SUCCESS;

	// mcube_motion_pal_dbg_print("%s: called\r\n", __func__);

	return retVal;
}

mCubeLibResult_t mCube_StorageRead(uint16_t nvmId,
								   uint32_t offset,
								   uint8_t *data,
								   uint32_t len)
{
	//mCubeLibResult_t retVal = MCUBE_LIB_SUCCESS;
	mCubeLibResult_t retVal = MCUBE_LIB_FAILURE;

	// mcube_motion_pal_dbg_print("%s: called\r\n", __func__);

	return retVal;
}

mCubeLibResult_t mCube_StorageWrite(uint16_t nvmId,
									uint32_t offset,
									uint8_t *data,
									uint32_t len)
{
	//mCubeLibResult_t retVal = MCUBE_LIB_SUCCESS;
   	mCubeLibResult_t retVal = MCUBE_LIB_FAILURE;

	//mcube_motion_pal_dbg_print("%s: called\r\n", __func__);

	return retVal;
}

/* Calculates the CRC32 value for the given input data utilizing
* a pre-generated ROM table (crc32Table).  In order to utilize
* a different polynomial, the CRC table must be re-generated.
*/
uint32_t UTL_CalcCrc32(uint8_t *dataPtr, int length)
{
	/*
	uint8_t tabOffset;
	int i;
	uint32_t crcResult = CRC32_INIT_VALUE;

	for(i = 0; i < length; i++)
	{
	tabOffset = dataPtr[i] ^ (crcResult >> 24);
	crcResult = (crcResult << 8) ^ crc32Table[tabOffset];
	}
	*/
	return 1;
}



#endif /*MOTION_SENSOR_SUPPORT*/


