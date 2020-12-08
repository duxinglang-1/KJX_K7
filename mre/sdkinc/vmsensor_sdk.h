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

#ifndef __VM_SENSOR_SDK
#define __VM_SENSOR_SDK

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    VM_SRV_SENSOR_MOTION_ANGLE_GX0,
    VM_SRV_SENSOR_MOTION_ANGLE_GY0,	
    VM_SRV_SENSOR_MOTION_ANGLE_GZ0,
    VM_SRV_SENSOR_MOTION_ANGLE_GX180,
    VM_SRV_SENSOR_MOTION_ANGLE_GY180,
    VM_SRV_SENSOR_MOTION_ANGLE_GZ180,
    VM_SRV_SENSOR_MOTION_ANGLE_OTHER 
} vm_srv_sensor_motion_direct_enum;

typedef enum
{
    VM_SRV_SENSOR_MOTION_ACTION_NULL,  
    VM_SRV_SENSOR_MOTION_ACTION_ROLL_RIGHT,
    VM_SRV_SENSOR_MOTION_ACTION_ROLL_LEFT,
    VM_SRV_SENSOR_MOTION_ACTION_PITCH_BACKWARD,
    VM_SRV_SENSOR_MOTION_ACTION_PITCH_FORWARD,
    VM_SRV_SENSOR_MOTION_ACTION_YAW_RIGHT,
    VM_SRV_SENSOR_MOTION_ACTION_YAW_LEFT,
    VM_SRV_SENSOR_MOTION_ACTION_TOTAL
} vm_srv_sensor_motion_action_enum;

typedef enum
{
    VM_SRV_SENSOR_MOTION_DIRECT,	
    VM_SRV_SENSOR_MOTION_SHAKE,
    VM_SRV_SENSOR_MOTION_TILT,
	VM_SRV_SENSOR_MOTION_TAP,
	VM_SRV_SENSOR_MOTION_DOUBLE_TAP,
	VM_SRV_SENSOR_MOTION_DROP,
	
	VM_SRV_SENSOR_MOTION_STEP,
	
	VM_SRV_SENSOR_MOTION_ADVANCED_SHAKE,
	VM_SRV_SENSOR_MOTION_TURNOVER,
			
	VM_SRV_SENSOR_TOTAL, 
	VM_SRV_SENSOR_DISABLE			 /* motion sensor have been disabled */
} vm_srv_sensor_type_enum;

typedef struct
{
    VMUINT8	angle_threshold;
} vm_srv_sensor_motion_direct_cfg_struct ;

typedef struct
{
    VMINT gx;
    VMINT gy; 
    VMINT gz;
}vm_srv_sensor_motion_tilt_angle_struct;

typedef struct
{
    VMINT16 x;
    VMINT16 y; 
    VMINT16 z;
}vm_srv_sensor_motion_tilt_acc_struct;

/*sensor_type = VM_SRV_SENSOR_MOTION_TILT*/
typedef struct
{
    vm_srv_sensor_motion_tilt_angle_struct angle;
    vm_srv_sensor_motion_tilt_acc_struct   acc;
}vm_srv_sensor_motion_tilt_struct;

typedef VMINT   VM_SRV_SENSOR_HANDLE;
typedef VMINT   VM_SRV_SENSOR_RESULT;

typedef enum   
{
	VM_SRV_SENSOR_MOTION_TAP_DONE
}vm_srv_sensor_motion_tap_direct_enum;

typedef enum
{
	VM_SRV_SENSOR_MOTION_ACTION_STEP,  /*Step事件发生*/
	VM_SRV_SENSOR_MOTION_STEP_NULL	
}vm_srv_sensor_motion_step_enum;

typedef enum
{
	VM_SRV_SENSOR_MOTION_ACTION_DROP,  /*Drop事件发生*/
	VM_SRV_SENSOR_MOTION_DROP_NULL	
}vm_srv_sensor_motion_drop_enum;

typedef enum {  
	VM_SRV_SENSOR_MOTION_TURNOVER_NONE	= 0,
	VM_SRV_SENSOR_MOTION_TURNOVER_UP = 0x01,     /*back to front*/
	VM_SRV_SENSOR_MOTION_TURNOVER_DOWN	= 0x02,   /*front to back*/
	
	VM_SRV_SENSOR_MOTION_TURNOVER_LEFT	= 0x04,   /*below not support*/
	VM_SRV_SENSOR_MOTION_TURNOVER_RIGHT = 0x08,
	VM_SRV_SENSOR_MOTION_TURNOVER_TOTAL = 0xffff
} vm_srv_sensor_motion_turnover_enum;

/* sensor_type = VM_SRV_SENSOR_MOTION_STEP  */
typedef enum
{
    VM_SRV_SENSOR_MOTION_STEP_HIGH,
    VM_SRV_SENSOR_MOTION_STEP_MEDIUM,
    VM_SRV_SENSOR_MOTION_STEP_LOW
}vm_srv_sensor_motion_step_sensitive_enum;

typedef struct
{
    vm_srv_sensor_motion_step_sensitive_enum sensitive;
}vm_srv_sensor_motion_step_cfg_struct;


/* sensor_type = VM_SRV_SENSOR_MOTION_TILT  */
typedef enum
{
    VM_SRV_SENSOR_MOTION_NORMAL_TILT,
    VM_SRV_SENSOR_MOTION_RAW_TILT
}vm_srv_sensor_motion_tilt_sensitive_enum;

typedef struct
{
    vm_srv_sensor_motion_tilt_sensitive_enum sensitive;
}vm_srv_sensor_motion_tilt_cfg_struct;

/*sensor_type = SRV_SENSOR_MOTION_TAP*/
typedef struct
{
	vm_srv_sensor_motion_tap_direct_enum tap_direct;
}vm_srv_sensor_motion_tap_struct;

/*sensor_type = SRV_SENSOR_MOTION_DOUBLE_TAP*/
typedef struct
{
	vm_srv_sensor_motion_tap_direct_enum double_tap_direct;
}vm_srv_sensor_motion_double_tap_struct;


/*sensor_type = SRV_SENSOR_MOTION_DROP*/
typedef struct
{
	vm_srv_sensor_motion_drop_enum action;
}vm_srv_sensor_motion_drop_struct;

/*sensor_type = SRV_SENSOR_MOTION_STEP*/
typedef struct
{
	vm_srv_sensor_motion_step_enum action;
}vm_srv_sensor_motion_step_struct;

typedef struct {
	VMUINT8 direction;
}vm_srv_sensor_motion_advanced_shake_struct;

/*sensor_type = SRV_SENSOR_MOTION_TURNOVER*/
typedef struct {
	vm_srv_sensor_motion_turnover_enum	direction;
} vm_srv_sensor_motion_turnover_struct;


typedef struct
{
    vm_srv_sensor_motion_direct_enum  direct; 
    vm_srv_sensor_motion_action_enum  action;
} vm_srv_sensor_motion_direct_struct ;

#define VM_SRV_SENSOR_MOTION_ALWAYS_ON_MODE     0x0001   /*Sensor always open*/


/*----------------------------------------------------------------------------*/
/* Extern Function                                                            */
/*----------------------------------------------------------------------------*/

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *  SRV_SENSOR_MOTION_TILT_HDLR 
 * DESCRIPTION
 *  sensor event callback handler
 *  please invole this function to release it.
 * PARAMETERS
 *  sensor_handle : [IN] sensor's handle which is created by vm_create_sensor_instance.
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*VM_SRV_SENSOR_EVENT_HDLR)(vm_srv_sensor_type_enum sensor_type, void *sensor_data, void *user_data); 

/*****************************************************************************
 * FUNCTION
 *  vm_srv_sensor_start_listen
 * DESCRIPTION
 *  Start the listen
 * PARAMETERS
 *  type : [IN] sensor type, please refer vm_srv_sensor_type_enum
 *  option : [IN] some type's option, if it have
 *  event_hdlr : [IN] callback function
 *  user_data : [IN] user data
 * RETURNS
 *  VM_SRV_SENSOR_HANDLE  
 * RETURN VALUES
 *  VM_SRV_SENSOR_MOTION_NO_SLOT :  open too much detection, so that no have enough handle .    
 *  Other: the handle of direct detection . 
 *****************************************************************************/
extern VM_SRV_SENSOR_HANDLE vm_srv_sensor_start_listen(vm_srv_sensor_type_enum type, void *option, 
                                                 VM_SRV_SENSOR_EVENT_HDLR event_hdlr, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  vm_srv_sensor_stop_listen
 * DESCRIPTION
 *  Stop listen a sensor application
 * PARAMETERS
 *  sensor_handle : [IN] sensor's handle. 
 *  control_name : [IN] sensor's control name.
 *  value : [IN] set value.
 * RETURNS
 *  VM_SRV_SENSOR_RESULT
 * RETURN VALUES
 *  VM_SRV_SENSOR_SUCCEED:         Stop success
 *  VM_SRV_SENSOR_CB_NOT_FOUND:    Pass the wrong handle                     
 *****************************************************************************/
extern VM_SRV_SENSOR_RESULT vm_srv_sensor_stop_listen(VM_SRV_SENSOR_HANDLE handle);


/*****************************************************************************
 * FUNCTION
 *  vm_srv_sensor_enable_mode
 * DESCRIPTION
 *  This function is to enable mode
 * PARAMETERS
 *  sensor_handle : [IN] The return value of start listen
 *  sensor_mode : [IN] A bitmask of sensor mode(VM_SRV_SENSOR_MOTION_ALWAYS_ON_MODE)
 * RETURNS
 *  VM_SRV_SENSOR_RESULT
 * RETURN VALUES
 *  VM_SRV_SENSOR_SUCCEED:         enable success
 *  VM_SRV_SENSOR_MOTION_NO_SLOT:          
 *****************************************************************************/
extern VM_SRV_SENSOR_RESULT vm_srv_sensor_enable_mode(VM_SRV_SENSOR_HANDLE handle , VMUINT16 sensor_mode);


/*****************************************************************************
 * FUNCTION
 *  vm_srv_sensor_disable_mode
 * DESCRIPTION
 *   This function is to disable mode
 * PARAMETERS
 *  sensor_handle : [IN] The return value of start listen
 *  sensor_mode : [IN] A bitmask of sensor mode(VM_SRV_SENSOR_MOTION_ALWAYS_ON_MODE)
 * RETURNS
 *  VM_SRV_SENSOR_RESULT
 * RETURN VALUES
 *  VM_SRV_SENSOR_SUCCEED:         disable success
 *  VM_SRV_SENSOR_MOTION_NO_SLOT:                 
 *****************************************************************************/
extern VM_SRV_SENSOR_RESULT vm_srv_sensor_disable_mode(VM_SRV_SENSOR_HANDLE handle, VMUINT16 sensor_mode);


/*****************************************************************************
 * FUNCTION
 *   vm_srv_sensor_is_available
 * DESCRIPTION
 *   Check whether the sensor(motion ,or future other sensors...) is enable
 *  stop sensor.
 * PARAMETERS
 *  sensor_handle : [OUT] sensor's handle. 
 * RETURNS
 *  stop sensor success or not.
 * RETURN VALUES
 *****************************************************************************/
extern VMINT vm_srv_sensor_is_available(vm_srv_sensor_type_enum sensor_type);

#ifdef __cplusplus
}
#endif

#endif /* __VM_SENSOR_SDK */
