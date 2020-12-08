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
 *  SensorSrvGprot.h
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


#ifndef _SRV_SENSOR_H_
#define _SRV_SENSOR_H_

/*
#include "MMIDataType.h" 
#include "mmi_frm_events_gprot.h" 
#include "mdi_datatype.h" 
#include "kal_non_specific_general_types.h"*/

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mdi_datatype.h"
#include "mmi_frm_events_gprot.h"



/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

 #define SRV_SENSOR_MOTION_ANGLE_THRESHOLD_MIN               (0)
 #define SRV_SENSOR_MOTION_ANGLE_THRESHOLD_MAX               (30)
 #define SRV_SENSOR_MOTION_SUCCEED                           (0)
 #define SRV_SENSOR_MOTION_NO_SLOT                           (-1)
 #define SRV_SENSOR_MOTION_CB_NOT_FOUND                      (-2)
 #define SRV_SENSOR_MOTION_INVALID_PARAM                     (-3)
#define SRV_SENSOR_MOTION_NOT_SUPPORT_GESTURE               (-4)


/*Backlight close then sensor close,it cannot be used by application*/
#define SRV_SENSOR_MOTION_NORAML_MODE        0x0000   
#define SRV_SENSOR_MOTION_ALWAYS_ON_MODE     0x0001   /*Sensor always open*/

/*----------------------------------------------------------------------------*/
/* Typedef                                                                    */
/*----------------------------------------------------------------------------*/
typedef S32   SRV_SENSOR_HANDLE;
typedef S32   SRV_SENSOR_RESULT;


/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/
/* Sensor Event Type */
typedef enum
{
    EVT_ID_SENSOR_PXS_TURN_ON_NOTIFY  = SRV_SENSOR_BASE + 1,           /* event for notify PXS device is enable */
    EVT_ID_SENSOR_PXS_TURN_OFF_NOTIFY,          /* event for notify PXS device is disable */
    EVT_ID_SENSOR_PXS_DETECT_OBJ_CLOSE,         /* event for detect the object close */
    EVT_ID_SENSOR_PXS_DETECT_OBJ_AWAY,          /* event for detect the object away */

	EVT_ID_SENSOR_MOTION_CALI_FINISHED,
	EVT_ID_SENSOR_MOTION_CALI_TIMEOUT,
	EVT_ID_SENSOR_MOTION_CALI_WRITE_FAIL,

    EVT_ID_SRV_SENSOR_END_OF_ENUM
} srv_sensor_event_enum;

/* Sensor set parameter type */
typedef enum
{
	SRV_SENSOR_MOTION_SET_TAP,
	SRV_SENSOR_MOTION_SET_FLIP,
	SRV_SENSOR_MOTION_END_OF_ENUM
}srv_sensor_motion_set_type_enum;




/* Motion sensor gesture support type */
typedef enum
{
    SRV_SENSOR_MOTION_DIRECT,	
    SRV_SENSOR_MOTION_SHAKE,
    SRV_SENSOR_MOTION_TILT,


	/*Add for mCube porting*/
	SRV_SENSOR_MOTION_TAP,
	SRV_SENSOR_MOTION_DOUBLE_TAP,
	SRV_SENSOR_MOTION_DROP,


	SRV_SENSOR_MOTION_STEP,


	SRV_SENSOR_MOTION_ADVANCED_SHAKE,
	SRV_SENSOR_MOTION_TURNOVER,
			
    SRV_SENSOR_TOTAL, 
    SRV_SENSOR_DISABLE           /* motion sensor have been disabled */
} srv_sensor_type_enum;

typedef enum
{
    SRV_SENSOR_MOTION_ANGLE_GX0,
    SRV_SENSOR_MOTION_ANGLE_GY0,	
    SRV_SENSOR_MOTION_ANGLE_GZ0,
    SRV_SENSOR_MOTION_ANGLE_GX180,
    SRV_SENSOR_MOTION_ANGLE_GY180,
    SRV_SENSOR_MOTION_ANGLE_GZ180,
    SRV_SENSOR_MOTION_ANGLE_OTHER 
} srv_sensor_motion_direct_enum;

typedef enum
{
    SRV_SENSOR_MOTION_SHAKE_STRONG,
    SRV_SENSOR_MOTION_SHAKE_MEDIUM,
    SRV_SENSOR_MOTION_SHAKE_WEAK
} srv_sensor_motion_shake_sensitive_enum;

typedef enum
{
	SRV_SENSOR_MOTION_NORMAL_TILT,       /*Filter noise*/
	SRV_SENSOR_MOTION_RAW_TILT,          /*May have noise*/
}srv_sensor_motion_tilt_sensitive_enum;

typedef enum
{
    SRV_SENSOR_MOTION_STEP_HIGH,
    SRV_SENSOR_MOTION_STEP_MEDIUM,
    SRV_SENSOR_MOTION_STEP_LOW
}srv_sensor_motion_step_sensitive_enum;


typedef enum
{
    SRV_SENSOR_MOTION_ACTION_NULL,  
    SRV_SENSOR_MOTION_ACTION_ROLL_RIGHT,
    SRV_SENSOR_MOTION_ACTION_ROLL_LEFT,
    SRV_SENSOR_MOTION_ACTION_PITCH_BACKWARD,
    SRV_SENSOR_MOTION_ACTION_PITCH_FORWARD,
    SRV_SENSOR_MOTION_ACTION_YAW_RIGHT,
    SRV_SENSOR_MOTION_ACTION_YAW_LEFT,
    SRV_SENSOR_MOTION_ACTION_TOTAL
} srv_sensor_motion_action_enum;

typedef enum
{
    SRV_SENSOR_MOTION_SHAKING,
    SRV_SENSOR_MOTION_SHAKE_NULL
} srv_sensor_motion_shake_action_enum;

typedef enum
{
	SRV_SENSOR_PXS_PARAM_TYPE_DEBOUNCE,
	SRV_SENSOR_PXS_PARAM_TYPE_TOTAL
}srv_sensor_pxs_set_param_type_enum;


/* Add for mCube porting */

typedef enum   
{
	SRV_SENSOR_MOTION_TAP_DONE,    /* Detect tap action */
	SRV_SENSOR_MOTION_TAP_NULL
}srv_sensor_motion_tap_direct_enum;




typedef enum
{
	SRV_SENSOR_MOTION_ACTION_STEP,  /*Step事件发生*/
	SRV_SENSOR_MOTION_STEP_NULL	
}srv_sensor_motion_step_enum;



/*
typedef enum {
	SRV_SENSOR_MOTION_ADVANCED_SHAKE_DIRECTION_NONE      = 0,
	SRV_SENSOR_MOTION_ADVANCED_SHAKE_DIRECTION_UP	    = 0x01,
	SRV_SENSOR_MOTION_ADVANCED_SHAKE_DIRECTION_DOWN	    = 0x02,
	SRV_SENSOR_MOTION_ADVANCED_SHAKE_DIRECTION_LEFT	    = 0x04,
	SRV_SENSOR_MOTION_ADVANCED_SHAKE_DIRECTION_RIGHT	    = 0x08,
	SRV_SENSOR_MOTION_ADVANCED_SHAKE_DIRECTION_TOP	    = 0x10,
	SRV_SENSOR_MOTION_ADVANCED_SHAKE_DIRECTION_BOTTOM    = 0x20,
	SRV_SENSOR_MOTION_ADVANCED_SHAKE_INVALED_DIRECTION   = 0xffff
} srv_sensor_motion_advanced_shake_enum;
*/

typedef enum {  
	SRV_SENSOR_MOTION_TURNOVER_NONE	= 0,
	SRV_SENSOR_MOTION_TURNOVER_UP = 0x01,     /*back to front*/
	SRV_SENSOR_MOTION_TURNOVER_DOWN	= 0x02,   /*front to back*/
	
	SRV_SENSOR_MOTION_TURNOVER_LEFT	= 0x04,   /*below not support*/
	SRV_SENSOR_MOTION_TURNOVER_RIGHT = 0x08,
	SRV_SENSOR_MOTION_TURNOVER_TOTAL = 0xffff
} srv_sensor_motion_turnover_enum;

typedef enum
{
	SRV_SENSOR_MOTION_ACTION_DROP,  /*Drop事件发生*/
	SRV_SENSOR_MOTION_DROP_NULL	
}srv_sensor_motion_drop_enum;

/*
typedef enum
{
	SRV_SENSOR_MOTION_NORMAL_MODE,		//设置手机进入正常模式，背光关闭sensor关闭
	SRV_SENSOR_MOTION_ALWAYS_OPEN_MODE, //设置手机进入恒开模式
}srv_sensor_motion_mode_enum;
*/

/* Motion Sensor calibration result */
/*
typedef enum
{
	EVT_ID_SENSOR_MOTION_CALI_FINISHED,
	EVT_ID_SENSOR_MOTION_CALI_TIMEOUT,
	EVT_ID_SENSOR_MOTION_CALI_NVRAM_WRITE_FAIL,
} srv_sensor_motion_cali_event_enum;
*/


typedef enum
{
	  SRV_SENSOR_MOTION_CALI_FINISHED,
      SRV_SENSOR_MOTION_CALI_TIMEOUT,
}srv_sensor_motion_cali_status_enum;




/*----------------------------------------------------------------------------*/
/* Struct                                                                     */
/*----------------------------------------------------------------------------*/
/*cfg_option*/
/*sensor_type = SRV_SENSOR_MOTION_DIRECT*/
typedef struct
{
    U8	angle_threshold;
} srv_sensor_motion_direct_cfg_struct ;

/*sensor_type = SRV_SENSOR_MOTION_SHAKE*/
typedef struct
{
    srv_sensor_motion_shake_sensitive_enum sensitive;
}srv_sensor_motion_shake_cfg_struct;


/*sensor_type = SRV_SENSOR_MOTION_STEP*/
typedef struct
{
    srv_sensor_motion_step_sensitive_enum sensitive;
}srv_sensor_motion_step_cfg_struct;


/*sensor_type = SRV_SENSOR_MOTION_TILT*/
typedef struct
{
    srv_sensor_motion_tilt_sensitive_enum  sensitive;
}srv_sensor_motion_tilt_cfg_struct;


/*CALLBACK sensor data*/
/*sensor_type = SRV_SENSOR_MOTION_DIRECT*/
typedef struct
{
    srv_sensor_motion_direct_enum  direct; 
    srv_sensor_motion_action_enum  action;
} srv_sensor_motion_direct_struct ;

/*sensor_type = SRV_SENSOR_MOTION_SHAKE*/
typedef struct
{
    srv_sensor_motion_shake_action_enum action;
}srv_sensor_motion_shake_struct;


typedef struct
{
    S32 gx;
    S32 gy; 
    S32 gz;
}srv_sensor_motion_tilt_angle_struct;

typedef struct
{
    S16 x;
    S16 y; 
    S16 z;
}srv_sensor_motion_tilt_acc_struct;


/*sensor_type = SRV_SENSOR_MOTION_TILT*/
typedef struct
{
    srv_sensor_motion_tilt_angle_struct angle;
    srv_sensor_motion_tilt_acc_struct   acc;
}srv_sensor_motion_tilt_struct;


/*------ Add for mCube porting ------*/


/*sensor_type = SRV_SENSOR_MOTION_TAP*/
typedef struct
{
	srv_sensor_motion_tap_direct_enum tap_direct;
}srv_sensor_motion_tap_struct;

/*sensor_type = SRV_SENSOR_MOTION_DOUBLE_TAP*/
typedef struct
{
	srv_sensor_motion_tap_direct_enum double_tap_direct;
}srv_sensor_motion_double_tap_struct;


/*sensor_type = SRV_SENSOR_MOTION_DROP*/
typedef struct
{
	srv_sensor_motion_drop_enum action;
}srv_sensor_motion_drop_struct;



/*sensor_type = SRV_SENSOR_MOTION_STEP*/
typedef struct
{
	srv_sensor_motion_step_enum action;
}srv_sensor_motion_step_struct;



/*sensor_type = SRV_SENSOR_MOTION_ADVANCED_SHAKE*/

/*---------------------------------------------*/
/*	advanced shake direction is a U8 bitmask   */
/*	                                           */ 
/*	XX     XX   XX   XX                        */
/*	NULL   Z    y    x                         */
/*                                             */
/*	shake direction:                           */
/*	00: None                                   */
/*	01: NEG                                    */
/*	10: POS                                    */
/*---------------------------------------------*/

typedef struct {
	U8 direction;
}srv_sensor_motion_advanced_shake_struct;


/*sensor_type = SRV_SENSOR_MOTION_TURNOVER*/
typedef struct {
	srv_sensor_motion_turnover_enum	direction;
} srv_sensor_motion_turnover_struct;


/*This struct is for PXS sensor set debounce value*/
typedef struct
{
	U32 top_area_debounce;
	U32 larger_area_debounce;
}srv_sensor_pxs_set_debounce_struct;



/* These are for motion sensor set parameters */
/* Set Tap */
typedef struct
{
	U32  curr_val;
    U32  max_val;
    U32  min_val;
}srv_sensor_motion_tap_para_struct;

typedef struct
{
	U32 set_tap_plus;
	U32 set_tap_threshold;
}srv_sensor_motion_set_tap_struct;

typedef struct
{
	srv_sensor_motion_tap_para_struct get_tap_plus;
	srv_sensor_motion_tap_para_struct get_tap_threshold;
}srv_sensor_motion_get_tap_struct;

/* Set Flip */
typedef struct
{
	MMI_BOOL flipEnable;
	float flipFilter;
	float flipThreshold;
	float tFlipDebounce;
	float tFlipInterval;	
}srv_sensor_motion_flip_para_struct;





/*----------------------------------------------------------------------------*/
/* Extern Function                                                            */
/*----------------------------------------------------------------------------*/

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *  SRV_SENSOR_MOTION_TILT_HDLR 
 * DESCRIPTION
 *  sensor event callback handler
 *
 * PARAMETERS
 * sensor_type:    [IN] the type of the sensor
 * sensor_data:    [IN] pointer to detail information structure
 * user_data:      [IN] the data of application pass to sensor service when call start       
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*SRV_SENSOR_EVENT_HDLR)(srv_sensor_type_enum sensor_type, void *sensor_data, void *user_data); 

 
/*****************************************************************************
 * FUNCTION
 *  srv_sensor_init
 * DESCRIPTION
 *  To initiate Sensor layer, should called at system start, user don't call this function.
 *
 * PARAMETERS
 *  NONE     
 * RETURNS
 *  SRV_SENSOR_RESULT 
 * RETURN VALUES
 *    SRV_SENSOR_MOTION_SUCCEED:         init success                     
 *****************************************************************************/
extern mmi_ret srv_sensor_init(mmi_event_struct *evt);   


/*****************************************************************************
 * FUNCTION
 *  srv_sensor_message_dispatcher
 * DESCRIPTION
 *  The message dispatcher of sensor.
 *
 * PARAMETERS
 *  ilm_ptr:      [IN] the pointer of message structure.     
 * RETURNS
 *  MMI_BOOL 
 *****************************************************************************/
extern MMI_BOOL srv_sensor_message_dispatcher(void *ilm_ptr);


/*****************************************************************************
 * FUNCTION
 *  srv_sensor_start_listen
 * DESCRIPTION
 *  Start the listen
 *
 * PARAMETERS
 *   event_hdlr:     [IN]  application callback function
 *   user_data:             [IN]  the data of application pass to sensor service when call start 
 * RETURNS
 *  SRV_SENSOR_HANDLE  
 * RETURN VALUES
 *  SRV_SENSOR_MOTION_NO_SLOT :  open too much detection, so that no have enough handle .    
 *  Other: the handle of direct detection . 
 *****************************************************************************/
extern SRV_SENSOR_HANDLE srv_sensor_start_listen(srv_sensor_type_enum type, void *option, 
                                                 SRV_SENSOR_EVENT_HDLR event_hdlr, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_sensor_stop_listen
 * DESCRIPTION
 *  Stop listen a sensor application
 *
 * PARAMETERS
 *   handle:           [IN] the handle of application want to stop   
 * RETURNS
 *  SRV_SENSOR_RESULT
 * RETURN VALUES
 *  SRV_SENSOR_SUCCEED:         Stop success
 *  SRV_SENSOR_CB_NOT_FOUND:    Pass the wrong handle                     
 *****************************************************************************/
extern SRV_SENSOR_RESULT srv_sensor_stop_listen(SRV_SENSOR_HANDLE handle);


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
extern MMI_BOOL srv_sensor_is_available(srv_sensor_type_enum sensor_type);


/*****************************************************************************
 * FUNCTION
 *  srv_sensor_pxs_turn_on
 * DESCRIPTION
 *  This function is to turn on the proximity device
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/ 
extern MMI_BOOL srv_sensor_pxs_turn_on(void);


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
extern void srv_sensor_pxs_turn_off(void);


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
extern MMI_BOOL srv_sensor_pxs_get_status(MMI_BOOL *fgObjectDetected);


/*****************************************************************************
 * FUNCTION
 *  srv_sensor_pxs_set_value
 * DESCRIPTION
 *  This function is to set value
 * PARAMETERS
 *	type:      [IN]For example SRV_SENSOR_PXS_SET_DEBOUNCE
 *	val_1:     [IN]value 1
 *  val_2:     [IN]value 2
 * RETURNS
 *  void
 *****************************************************************************/ 
extern MMI_BOOL srv_sensor_pxs_set_value(srv_sensor_pxs_set_param_type_enum type,void *val);



/*****************************************************************************
 * FUNCTION
 *  srv_sensor_motion_set_switch
 * DESCRIPTION
 *  This function is to set switch
 * PARAMETERS
 *  is_enable:     [IN] 
 * RETURNS
 *  void
 *****************************************************************************/ 
extern void srv_sensor_motion_set_switch(MMI_BOOL is_enable);

/*****************************************************************************
 * FUNCTION
 *  srv_sensor_motion_get_switch
 * DESCRIPTION
 *  This function is to get switch status
 * PARAMETERS
 *  NULL:     [IN] 
 * RETURNS
 *  void
 *****************************************************************************/ 
extern MMI_BOOL srv_sensor_motion_get_switch(void);


/*****************************************************************************
 * FUNCTION
 *  srv_sensor_motion_enable_mode
 * DESCRIPTION
 *  This function is to enable mode
 * PARAMETERS
 *  handler:     [IN] The return value of start listen
 *  sensor_mode: [IN] A bitmask of sensor mode(SRV_SENSOR_MOTION_ALWAYS_ON_MODE)
 * RETURNS
 *  SRV_SENSOR_RESULT
 *****************************************************************************/ 
extern SRV_SENSOR_RESULT srv_sensor_motion_enable_mode(SRV_SENSOR_HANDLE handler , U16 sensor_mode);


/*****************************************************************************
 * FUNCTION
 *  srv_sensor_motion_disable_mode
 * DESCRIPTION
 *  This function is to disable mode
 * PARAMETERS
 *  handler:     [IN] The return value of start listen
 *  sensor_mode: [IN] A bitmask of sensor mode(SRV_SENSOR_MOTION_ALWAYS_ON_MODE)
 * RETURNS
 *  SRV_SENSOR_RESULT
 *****************************************************************************/ 
extern SRV_SENSOR_RESULT srv_sensor_motion_disable_mode(SRV_SENSOR_HANDLE handler , U16 sensor_mode);


/*****************************************************************************
 * FUNCTION
 *  srv_sensor_motion_start_cali
 * DESCRIPTION
 *  This function is to start calibration
 * PARAMETERS
 *  NULL
 * RETURNS
 *  void
 *****************************************************************************/ 
extern void srv_sensor_motion_start_cali(void);
extern void srv_sensor_motion_stop_cali(void);

/*****************************************************************************
 * FUNCTION
 *  srv_sensor_motion_get_parameters
 * DESCRIPTION
 *  This function is to get parameters, for example, tap parameter, flip parameter.
 * Which kind of parameter is justified by type.
 * PARAMETERS
 *  srv_sensor_motion_set_type_enum
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/ 
extern MMI_BOOL srv_sensor_motion_get_parameters(srv_sensor_motion_set_type_enum type,void * para);

/*****************************************************************************
 * FUNCTION
 *  srv_sensor_motion_set_parameters
 * DESCRIPTION
 *	This function is to set parameters, for example, tap parameter, flip parameter.
 * Which kind of parameter is justified by type.
 * PARAMETERS
 *  srv_sensor_motion_set_type_enum
 * RETURNS
 *  void
 *****************************************************************************/ 
extern MMI_BOOL srv_sensor_motion_set_parameters(srv_sensor_motion_set_type_enum type,void * para);






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

#endif /*_SRV_SENSOR_H_*/

  

