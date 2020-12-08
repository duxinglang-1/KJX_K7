/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vrt_canvas.h
 *
 * Project:
 * --------
 *  Venus Rendering Task
 *
 * Description:
 * ------------
 *  Canvas UI / Animation Engine API
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VRT_CANVAS_H__
#define __VRT_CANVAS_H__

#ifdef __cplusplus
extern "C"
{
#endif

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vrt_datatype.h"
#include "vrt_system.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/* Default timeline duration time */
#define VRT_TIMELINE_DEFAULT_DUR_TIME   250
/* Infinite timeline repeat count */
#define VRT_TIMELINE_REPEAT_INFINITE    0xFFFFFFFF


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/* Canvas states */
typedef enum
{
    /* Unknown state. Canvas API is not initialized */
    VRT_CANVAS_STATE_UNKNOWN = 0,
    /* Shutdown state. VRT is inactive */
    VRT_CANVAS_STATE_SHUTDOWN,
    /* Operate state. VRT is active and rendering */
    VRT_CANVAS_STATE_OPERATE,
    /* Susped state. VRT is active, but is not rendering */
    VRT_CANVAS_STATE_SUSPEND,
    /* End of enumerate */
    VRT_CANVAS_STATE_END_OF_ENUM
} vrt_canvas_staue_enum;


/* Predefined timing function ID */
typedef enum
{
    /* Linear timing function. Default value */
    VRT_TIMING_FUNC_ID_LINEAR = 0,
    /* Ease timing function. */
    VRT_TIMING_FUNC_ID_EASE,
    /* Ease-in timing function. */
    VRT_TIMING_FUNC_ID_EASE_IN,
    /* Ease-out timing function. */
    VRT_TIMING_FUNC_ID_EASE_OUT,
    /* Ease-in ease-out timing function. */
    VRT_TIMING_FUNC_ID_EASE_IN_EASE_OUT,
    /* Damping out timing function. */
    VRT_TIMING_FUNC_ID_DAMPING_OUT,
    /* End of enumerate */
    VRT_TIMING_FUNC_ID_END_OF_ENUM
} vrt_timing_func_id_enum;

/* Predefined interpolate function ID */
typedef enum
{
    /* Step interpolate function. Default value */
    VRT_INTERPOLATE_FUNC_ID_STEP = 0,
    /* Step interpolate function. */
    VRT_INTERPOLATE_FUNC_ID_LINEAR,
    /* Linear interpolate function. */
    VRT_INTERPOLATE_FUNC_ID_SLERP,
    /* Slerp interpolate function. */
    VRT_INTERPOLATE_FUNC_ID_SPLINE,
    /* Spline interpolate function. */
    VRT_INTERPOLATE_FUNC_ID_SQUAD,
    /* Squad of enumerate */
    VRT_INTERPOLATE_FUNC_ID_END_OF_ENUM
} vrt_interpolate_func_id_enum;


/* The action after vrt_frame_commit_end() */
typedef enum
{
    VRT_FRAME_COMMIT_ACTION_KEEP = 0,
    VRT_FRAME_COMMIT_ACTION_FORCE_SUSPEND,
    VRT_FRAME_COMMIT_ACTION_FORCE_RESUME,
    VRT_FRAME_COMMIT_ACTION_END_OF_ENUM
} vrt_frame_commit_action_enum;

/* The blocking type after vrt_frame_commit_end() */
typedef enum
{
    VRT_FRAME_COMMIT_BLOCK_TYPE_NONE = 0,
    VRT_FRAME_COMMIT_BLOCK_TYPE_RENDER_START,    
    VRT_FRAME_COMMIT_BLOCK_TYPE_RENDER_END,
    VRT_FRAME_COMMIT_BLOCK_TYPE_END_OF_ENUM
}  vrt_frame_commit_block_type_enum;


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*
 * Canvas engine functions
 */

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_init
 * DESCRIPTION
 *  Initial Canvas API at start up.
 *  Canvas API state will become VRT_CANVAS_STATE_SHUTDOWN.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_init(vrt_mem_provider_handle provider);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_get_state
 * DESCRIPTION
 *  Return the state of Canvas API
 * PARAMETERS
 *  void
 * RETURNS
 *  The state of Canvas API
 * SEE ALSO
 *  vrt_canvas_staue_enum
 *****************************************************************************/
extern vrt_canvas_staue_enum vrt_canvas_get_state(void);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_wait_rendering_complete
 * DESCRIPTION
 *  Wait for rendering complete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * SEE ALSO
 *  vrt_canvas_staue_enum
 *****************************************************************************/
extern void vrt_canvas_wait_rendering_complete(void);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_suspend
 * DESCRIPTION
 *  Suspend Canvas API. Canvas API state will become VRT_CANVAS_STATE_SUSPEND.
 *  It has no effect if Canvas API is shutdown.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * SEE ALSO
 *  vrt_canvas_staue_enum
 *****************************************************************************/
extern void vrt_canvas_suspend(void);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_resume
 * DESCRIPTION
 *  Resume Canvas API. Canvas API state will become VRT_CANVAS_STATE_OPERATE.
 *  It has no effect if Canvas API is shutdown.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * SEE ALSO
 *  vrt_canvas_staue_enum
 *****************************************************************************/
extern void vrt_canvas_resume(void);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_entry
 * DESCRIPTION
 *  Start Canvas API to entry a VRT screen.
 *  Canvas API state will become VRT_CANVAS_STATE_SUSPEND.
 * PARAMETERS
 *  param : [IN] Pointer to vrt_canvas_entry_param_struct
 * RETURNS
 *  void
 * SEE ALSO
 *  vrt_canvas_staue_enum
 *****************************************************************************/
extern void vrt_canvas_entry(const vrt_canvas_entry_param_struct *param);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_entered
 * DESCRIPTION
 *  Canvas API is ready to go.
 *  Must be called between vrt_canvas_entry() and vrt_canvas_leave().
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * SEE ALSO
 *  vrt_canvas_entry(), vrt_canvas_leave()
 *****************************************************************************/
extern void vrt_canvas_entered(void);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_leave
 * DESCRIPTION
 *  Stop Canvas API to leave a VRT screen.
 *  Canvas API state will become VRT_CANVAS_STATE_SHUTDOWN.
 * PARAMETERS
 *  param : [IN] Pointer to vrt_canvas_entry_param_struct
 * RETURNS
 *  void
 * SEE ALSO
 *  vrt_canvas_staue_enum
 *****************************************************************************/
extern void vrt_canvas_leave(const vrt_canvas_leave_param_struct *param);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_power_off
 * DESCRIPTION
 *  Ask Canvas API to enter power off mode, ex. backlight off
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_power_off(void);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_power_on
 * DESCRIPTION
 *  Ask Canvas API to enter power on mode, ex. backlight off
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_power_on(void);

#ifdef __MMI_REDUCED_UI_BUFFER__
/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_switch_render_buffer_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_switch_render_buffer_mode(void);
#endif /* __MMI_REDUCED_UI_BUFFER__ */
/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_deinit_render_buffers
 * DESCRIPTION
 *  Ask Canvas API to deinitialize blt layers and release memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_deinit_render_buffers(void);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_init_render_buffers
 * DESCRIPTION
 *  Ask Canvas API to initialize blt layers 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_init_render_buffers(void);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_pause_img_anim
 * DESCRIPTION
 *  Pause all animation images in the screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_pause_img_anim(void);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_resume_img_anim
 * DESCRIPTION
 *  Resume all animation images in the screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_resume_img_anim(void);


/*
 * Frame create functions
 */

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_create
 * DESCRIPTION
 *  Create a new VRT frame handle
 * PARAMETERS
 *  user_data       : [IN] The user data to attache on the VRT frame handle (for debug)
 * RETURNS
 *  The handle of new VRT frame
 *****************************************************************************/
extern vrt_frame_handle vrt_frame_create(void *user_data);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_release
 * DESCRIPTION
 *  Release a VRT frame handle
 * PARAMETERS
 *  frame_handle    : [IN] The frame handle to release
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_frame_release(vrt_frame_handle frame_handle);


/*
 * Frame animatable property functions
 */

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_get_property_type
 * DESCRIPTION
 *  Return the type ID of the given frame property ID
 * PARAMETERS
 *  property_id     : [IN] The frame property ID to get
 * RETURNS
 *  The type ID of the given frame property ID
 *****************************************************************************/
extern vrt_type_id_enum vrt_frame_get_property_type(
    vrt_object_property_id_enum property_id);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_init_property
 * DESCRIPTION
 *  Return the visual property structure of the given VRT frame handle
 *  Modify the structure to initial a new VRT frame.
 * PARAMETERS
 *  frame_handle    : [IN] The VRT frame handle to initialize
 * RETURNS
 *  The visual property structure 
 *****************************************************************************/
extern vrt_frame_visual_property_struct *vrt_frame_init_property(
    vrt_frame_handle frame_handle);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_set_3d_dirty
 * DESCRIPTION
 *  Mark there is any 3d property dirty which should case frame content dirty.
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_frame_set_3d_dirty(void);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_set_need_commit
 * DESCRIPTION
 *  Set canvas engine need to process commit later.
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_frame_set_need_commit(void);
/*****************************************************************************
 * FUNCTION
 *  vrt_object_add_property_timeline
 * DESCRIPTION
 *  description
 * PARAMETERS
 *  object_handle       : [IN] The VRT object handle to add timeline
 *  property_id         : [IN] The property ID to add
 *  to_value            : [IN] Pointer to to-value, the type should be same as the type of property_id
 *  value_size          : [IN] the to-value size, the size should be same as the size of property_id
 *  dur_time            : [IN] Duration time to add
 *  timing_callback     : [IN] The timing function callback to add, can be NULL for default
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_object_add_property_timeline(
    vrt_object_handle object_handle,
    vrt_object_property_id_enum property_id,
    const void *from_value, 
    const void *to_value, 
    vrt_u32 value_size,
    vrt_msec_type dur_time,
    const vrt_timeline_timing_callback_struct *timing_callback);

/*****************************************************************************
 * FUNCTION
 *  vrt_object_remove_property_timeline
 * DESCRIPTION
 *  remove preperty timeline of the object
 * PARAMETERS
 *  object_handle       : [IN] The VRT object handle to remove timeline
 *  property_id         : [IN] The property ID to remove
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_object_remove_property_timeline(
    vrt_object_handle object_handle,
    vrt_object_property_id_enum property_id);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_set_filter
 * DESCRIPTION
 *  Set the filter function callback on a VRT frame.
 * PARAMETERS
 *  frame_handle        : [IN] The VRT frame handle to add
 *  filter              : [IN] The filter function callback to add, can be NULL
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_frame_set_filter(
    vrt_frame_handle frame_handle, 
    const void *filter);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_set_owner_draw
 * DESCRIPTION
 *  Sets the frame owner draw property.
 * PARAMETERS
 *  frame_handle    [IN]     frame handle to set
 *  owner draw      [IN]     owner draw struct
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_frame_set_owner_draw(
    vrt_frame_handle frame_handle, 
    const void *owner_draw);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_set_material
 * DESCRIPTION
 *  Sets the frame material.
 * PARAMETERS
 *  frame_handle    [IN]     frame handle to set
 *  material        [IN]     material handle
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_frame_set_material(
    vrt_frame_handle frame_handle, 
    vrt_object_handle material);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_set_world
 * DESCRIPTION
 *  Sets world to the frame.
 * PARAMETERS
 *  frame_handle    [IN]     frame handle to set
 *  world           [IN]     world handle
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_frame_set_world(
    vrt_frame_handle frame_handle, 
    vrt_object_handle world);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_set_property_effect_callback
 * DESCRIPTION
 *  Set the frame property effect function callback on a VRT frame.
 * PARAMETERS
 *  frame_handle        : [IN] The VRT frame handle to add
 *  watch_frame_handle  : [IN] The watch VRT frame handle
 *  callback            : [IN] The frame property effect function callback to add, can be NULL
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_frame_set_property_effect_callback(
    vrt_frame_handle frame_handle, 
    vrt_frame_handle watch_frame_handle,
    const vrt_frame_property_effect_callback_struct *callback);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_set_property_monitor_callback
 * DESCRIPTION
 *  Set the frame property monitor function callback on a VRT frame.
 * PARAMETERS
 *  frame_handle        : [IN] The VRT frame handle to add
 *  callback            : [IN] The frame property monitor function callback to add, can be NULL
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_frame_set_property_monitor_callback(
    vrt_frame_handle frame_handle, 
    const vrt_frame_property_monitor_callback_struct *callback);

/*****************************************************************************
 * FUNCTION
 *  vrt_object_force_set_property_value
 * DESCRIPTION
 *  Force set a property value of a VRT animatable.
 *  It may suspend and resume VRT if it is rendering.
 * PARAMETERS
 *  vrt_animatable_handle       : [IN] The VRT animatable handle to set
 *  vrt_object_property_id_enum : [IN] The property ID to set
 *  value_buf                   : [IN] pointer to the value buffer
 *  value_buf_size              : [IN] The buffer size, must be same as the size of given frame property ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_object_force_set_property_value(
    vrt_animatable_handle object_handle, 
    vrt_object_property_id_enum property_id,
    const void *value_buf, 
    vrt_u32 value_buf_size);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_force_get_property_value
 * DESCRIPTION
 *  Force get a property value of a VRT frame.
 *  It may suspend and resume VRT if it is rendering.
 * PARAMETERS
 *  frame_handle        : [IN] The VRT frame handle to get
 *  property_id         : [IN] The frame property ID to get
 *  value_buf           : [OUT] pointer to the value buffer
 *  value_buf_size      : [IN] The buffer size, must be same as the size of given frame property ID
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_frame_force_get_property_value(
    vrt_frame_handle frame_handle, 
    vrt_object_property_id_enum property_id, 
    void *value_buf, 
    vrt_u32 value_buf_size);


/*****************************************************************************
 * FUNCTION
 *  vrt_frame_get_cache_buffer
 * DESCRIPTION
 *  Return the cache frame buffer of the given VRT frame handle.
 *  Only can be used in VRT callback functions.
 * PARAMETERS
 *  frame_handle        : [IN] The VRT frame handle to get
 * RETURNS
 *  Pointer to the cache frame buffer of the given VRT frame handle
 *****************************************************************************/
extern vrt_u8 *vrt_frame_get_cache_buffer(vrt_frame_handle frame_handle);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_lock_cache_buffer
 * DESCRIPTION
 *  Lock and return the cache frame buffer of the given VRT frame handle.
 *  Only can be used in VRT callback functions.
 * PARAMETERS
 *  frame_handle        : [IN] The VRT frame handle to lock
 *  lock_mode           : [IN] The mode to lock cache
 * RETURNS
 *  Pointer to the cache frame buffer of the given VRT frame handle.
 *  Return NULL if the frame is not cached or the memory for buffer is insufficient.
 *****************************************************************************/
extern vrt_u8 *vrt_frame_lock_cache_buffer(vrt_frame_handle frame_handle, vrt_cache_lock_mode_enum lock_mode);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_unlock_cache_buffer
 * DESCRIPTION
 *  Unlock the cache frame buffer of the given VRT frame handle.
 *  Only can be used in VRT callback functions.
 * PARAMETERS
 *  frame_handle        : [IN] The VRT frame handle to unlock
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_frame_unlock_cache_buffer(vrt_frame_handle frame_handle);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_get_has_animation
 * DESCRIPTION
 *  get a VRT frame whether has play a animation.
 *  It may suspend and resume VRT if it is rendering.
 * PARAMETERS
 *  frame_handle    : [IN] The VRT frame handle to initialize
 * RETURNS
 *  vrt_bool, return ture if has play a animation, otherwise return false
 *****************************************************************************/
extern vrt_bool vrt_frame_get_has_animation(vrt_frame_handle frame_handle);

/*
 * Frame non-animatable (setting) property functions
 */

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_set_opaque_mode
 * DESCRIPTION
 *  Set the opaque mode to the given VRT frame handle.
 *  It will take effect after next commit.
 * PARAMETERS
 *  frame_handle        : [IN] The VRT frame handle to set
 *  opaque_mode         : [IN] The opaque mode to set
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_frame_set_opaque_mode(vrt_frame_handle frame_handle, vrt_frame_opaque_mode_enum opaque_mode);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_set_quality
 * DESCRIPTION
 *  Set the quality type to the given VRT frame handle.
 *  It will take effect after next commit.
 * PARAMETERS
 *  frame_handle        : [IN] The VRT frame handle to set
 *  quality             : [IN] The quality type to set
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_frame_set_quality(vrt_frame_handle frame_handle, vrt_render_quality_enum quality);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_set_is_cached
 * DESCRIPTION
 *  Set the cache switch to the given VRT frame handle.
 *  It will take effect after next commit.
 * PARAMETERS
 *  frame_handle        : [IN] The VRT frame handle to set
 *  cached              : [IN] The cache switch to set
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_frame_set_is_cached(vrt_frame_handle frame_handle, vrt_bool cached);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_set_cache_mode
 * DESCRIPTION
 *  Set the cache mode to the given VRT frame handle.
 *  It will take effect after next commit.
 * PARAMETERS
 *  frame_handle        : [IN] The VRT frame handle to set
 *  mode                : [IN] The cache mode to set
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_frame_set_cache_mode(vrt_frame_handle frame_handle, vrt_cache_mode_enum mode);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_set_hints
 * DESCRIPTION
 *  Set the frame hints to the given VRT frame handle.
 *  It will take effect after next commit.
 * PARAMETERS
 *  frame_handle        : [IN] The VRT frame handle to set
 *  hints               : [IN] The frame hints to set
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_frame_set_hints(vrt_frame_handle frame_handle, vrt_frame_hints_enum hints);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_set_culling_type
 * DESCRIPTION
 *  Set the culling type to the given VRT frame handle.
 *  It will take effect after next commit.
 * PARAMETERS
 *  frame_handle        : [IN] The VRT frame handle to set
 *  culling_type        : [IN] The culling type to set
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_frame_set_culling_type(vrt_frame_handle frame_handle, vrt_frame_culling_type_enum culling_type);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_set_is_z_sort_child
 * DESCRIPTION
 *  Set the z-sort switch to the given VRT frame handle.
 *  It will take effect after next commit.
 * PARAMETERS
 *  frame_handle        : [IN] The VRT frame handle to set
 *  is_z_sort_child     : [IN] The z-sort switch to set
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_frame_set_is_z_sort_child(vrt_frame_handle frame_handle, vrt_bool is_z_sort_child);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_set_content_dirty
 * DESCRIPTION
 *  Set the VRT frame content is invalidate and need to redraw.
 *  It will take effect after next commit.
 * PARAMETERS
 *  frame_handle        : [IN] The VRT frame handle to set 
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_frame_set_content_dirty(vrt_frame_handle frame_handle);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_play_img_content
 * DESCRIPTION
 *  set the parameter of play animation image if frame_handle has animation image content
 *  It will take effect after next commit.
 * PARAMETERS
 *  frame_handle        : [IN] The VRT frame handle to set
 *  play_img_content   : [IN] The parameter of play animation image
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_frame_play_img_content(vrt_frame_handle frame_handle, vrt_frame_play_img_content_struct *play_img_content);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_force_swap_img_buf
 * DESCRIPTION
 *
 * PARAMETERS
 *  frame_handle        : [IN] The VRT frame handle to set
 
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_frame_force_swap_img_buf(
    vrt_frame_handle frame_handle, 
    vrt_u32 cmd_index, 
    const vrt_image_buffer_struct *img_buf);


/*****************************************************************************
 * FUNCTION
 *  vrt_frame_set_layer_frame
 * DESCRIPTION
 *  Sets the layer handle.
 * PARAMETERS
 *  frame_handle        : [IN] The VRT frame handle to set
 *  layer_handle        : [IN] layer handle
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_frame_set_layer_frame(vrt_frame_handle frame_handle, vrt_u32 layer_handle);


/*
 * Timeline functions
 */

/*****************************************************************************
 * FUNCTION
 *  vrt_timeline_get_predefined_timing_func
 * DESCRIPTION
 *  Return the predefined timing function with given ID
 * PARAMETERS
 *  timing_func_id      : [IN] The timing function ID to get
 * RETURNS
 *  Pointer to the predefined timing function with given ID
 *****************************************************************************/
extern const vrt_timeline_timing_callback_struct *vrt_timeline_get_predefined_timing_func(vrt_timing_func_id_enum timing_func_id);

/*****************************************************************************
 * FUNCTION
 *  vrt_timeline_get_predefined_interpolate_func
 * DESCRIPTION
 *  Return the predefined interpolation function with given ID
 * PARAMETERS
 *  interpolation_func_id      : [IN] The interpolation function ID to get
 * RETURNS
 *  Pointer to the predefined interpolation function with given ID
 *****************************************************************************/
extern vrt_timeline_interpolation_funcptr_type vrt_timeline_get_predefined_interpolate_func(vrt_interpolate_func_id_enum interpolation_func_id);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_add_timeline
 * DESCRIPTION
 *  Add a new VRT timeline a on the given VRT frame handle
 * PARAMETERS
 *  frame_handle        : [IN] The VRT frame to add
 *  property_id         : [IN] The frame property ID to add
 *  user_data           : [IN] The user data to attache on the new VRT timeline (for debug)
 * RETURNS
 *  The handle of the new VRT timeline
 *****************************************************************************/
extern vrt_timeline_handle vrt_frame_add_timeline(
    vrt_frame_handle frame_handle, 
    vrt_object_property_id_enum property_id,
    vrt_bool has_from_to_value,
    void *user_data);

/*****************************************************************************
 * FUNCTION
 *  vrt_object_get_property_type
 * DESCRIPTION
 *  Return the type ID of the given object property ID
 * PARAMETERS
 *  property_id     : [IN] The object property ID to get
 * RETURNS
 *  The type ID of the given object property ID
 *****************************************************************************/
extern vrt_type_id_enum vrt_object_get_property_type(
    vrt_object_property_id_enum property_id);

/*****************************************************************************
 * FUNCTION
 *  vrt_object_add_timeline
 * DESCRIPTION
 *  Add a new VRT timeline a on the given VRT object handle
 * PARAMETERS
 *  object_handle        : [IN] The VRT object to add
 *  property_id         : [IN] The object property ID to add
 *  user_data           : [IN] The user data to attache on the new VRT timeline (for debug)
 * RETURNS
 *  The handle of the new VRT timeline
 *****************************************************************************/
extern vrt_timeline_handle vrt_object_add_timeline(
    vrt_object_handle object_handle, 
    vrt_object_property_id_enum property_id,
    vrt_bool has_from_to_value,
    void *user_data);

/*****************************************************************************
 * FUNCTION
 *  vrt_object_remove_timeline
 * DESCRIPTION
 *  Remove the given VRT timleine from its VRT object.
 * PARAMETERS
 *  timeline_handle     : [IN] The VRT timeline handle to remove
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_object_remove_timeline(vrt_timeline_handle timeline_handle);

/*****************************************************************************
 * FUNCTION
 *  vrt_timeline_set_value
 * DESCRIPTION
 *  Set from-value and to-value to the given timeline.
 *  Can only called before the timeline committed.
 * PARAMETERS
 *  timeline_handle     : [IN] The VRT timeline handle to set
 *  from_value          : [IN] Pointer to the from-value to set, can be NULL
 *  to_value            : [IN] Pointer to the to-value to set
 *  by_value            : [IN] Pointer to the by-value to set
 *  value_size          : [IN] The size of values
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_timeline_set_value(vrt_timeline_handle timeline_handle, const void *from_value, const void *to_value, const void *by_value, vrt_u32 value_size);

/*****************************************************************************
 * FUNCTION
 *  vrt_timeline_set_time
 * DESCRIPTION
 *  Set start-time and duration-time to the given timeline.
 *  Can only called before the timeline committed.
 * PARAMETERS
 *  timeline_handle     : [IN] The VRT timeline handle to set
 *  start_time          : [IN] Start-time to set
 *  dur_time            : [IN] Duration-time to set
 *  update_dur          : [IN] Update-duration-time to set
 *  is_rel_start_time   : [IN] Whatever the given start-time is relative time or not
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_timeline_set_time(vrt_timeline_handle timeline_handle, vrt_msec_type start_time, vrt_msec_type dur_time, vrt_msec_type update_duration, vrt_bool is_rel_start_time);

/*****************************************************************************
 * FUNCTION
 *  vrt_timeline_set_time
 * DESCRIPTION
 *  Set repeat duration time and repeat count to the given timeline.
 *  Can only called before the timeline committed.
 * PARAMETERS
 *  timeline_handle     : [IN] The VRT timeline handle to set
 *  repeat_duration     : [IN] Repeat duration time to set
 *  repeat_count        : [IN] Duration count to set
 *  auto_reversed       : [IN] Whatever auto reversed
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_timeline_set_repeat(vrt_timeline_handle timeline_handle, vrt_msec_type repeat_duration, vrt_u32 repeat_count, vrt_bool auto_reversed);

/*****************************************************************************
 * FUNCTION
 *  vrt_timeline_set_timing_func
 * DESCRIPTION
 *  Set timing function to the given timeline with ID
 *  Can only called before the timeline committed.
 * PARAMETERS
 *  timeline_handle     : [IN] The VRT timeline handle to set
 *  timing_func_id      : [IN] Timing function ID to set
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_timeline_set_timing_func(vrt_timeline_handle timeline_handle, vrt_timing_func_id_enum timing_func_id);

/*****************************************************************************
 * FUNCTION
 *  vrt_timeline_set_besizer_timing_func
 * DESCRIPTION
 *  Set timing function to the given timeline with besizer parameters
 *  Can only called before the timeline committed.
 * PARAMETERS
 *  timeline_handle     : [IN] The VRT timeline handle to set
 *  p1_x                : [IN] x coordinate of the point 1
 *  p1_y                : [IN] y coordinate of the point 1
 *  p2_x                : [IN] x coordinate of the point 2
 *  p2_y                : [IN] y coordinate of the point 2
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_timeline_set_besizer_timing_func(vrt_timeline_handle timeline_handle, vrt_float p1_x, vrt_float p1_y, vrt_float p2_x, vrt_float p2_y);

/*****************************************************************************
 * FUNCTION
 *  vrt_timeline_set_custom_timing_func
 * DESCRIPTION
 *  Set timing function to the given timeline with custom timing function callback
 *  Can only called before the timeline committed.
 * PARAMETERS
 *  timeline_handle     : [IN] The VRT timeline handle to set
 *  callback            : [IN] The custom timing function callback to set
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_timeline_set_custom_timing_func(vrt_timeline_handle timeline_handle, const vrt_timeline_timing_callback_struct *callback);

/*****************************************************************************
 * FUNCTION
 *  vrt_timeline_set_custom_interpolation_func
 * DESCRIPTION
 *  Set custom interpolation function callback to the given timeline
 *  Can only called before the timeline committed.
 * PARAMETERS
 *  timeline_handle     : [IN] The VRT timeline handle to set
 *  callback            : [IN] The custom interpolation function callback to set
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_timeline_set_custom_interpolation_func(vrt_timeline_handle timeline_handle, const vrt_timeline_interplation_callback_struct *callback);

/*
 * Commit functions
 */

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_commit_beign
 * DESCRIPTION
 *  Begin to suspend and commit all scene graph
 * PARAMETERS
 *  current_time        : [IN] The time of this commit
 *  update_canvas       : [IN] Whatever need to update scene graph
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_frame_commit_beign(vrt_msec_type current_time, vrt_bool update_canvas, vrt_frame_commit_action_enum action, vrt_frame_commit_block_type_enum block_type);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_commit_end
 * DESCRIPTION
 *  End to suspend and commit all scene graph
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern vrt_bool vrt_frame_commit_end(void);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_copy_draw_cmds
 * DESCRIPTION
 *  copy the draw commands of a particulat frame
 * PARAMETERS
 *  frame handle
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_copy_draw_cmds(vrt_frame_handle handle);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_copy_subtree
 * DESCRIPTION
 *  copy draw commands of a subtree
 * PARAMETERS
 *  frame handle
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_copy_subtree(vrt_frame_handle handle);

/*****************************************************************************
 * FUNCTION
 *  vrt_frame_get_commit_counter
 * DESCRIPTION
 *  Return the commit counter. 
 *  The value can check if any commit between two this function calls.
 * PARAMETERS
 *  void
 * RETURNS
 *  The counter
 *****************************************************************************/
extern vrt_u32 vrt_frame_get_commit_counter(void);


/*
 * Canvas draw context functions
 */
 
/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_begin
 * DESCRIPTION
 *  Prepare a new draw context to draw.
 *  All draw command function should be called between vrt_canvas_begin and vrt_canvas_end.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_begin(void);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_begin
 * DESCRIPTION
 *  End to prepare a new draw context to draw.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_end(void);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_comment
 * DESCRIPTION
 *  Add a comment to draw context
 * PARAMETERS
 *  string          : [IN] The comment to add
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_comment(const vrt_char *string);
 
/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_push_and_set_active_frame
 * DESCRIPTION
 *  Push the current VRT frame and set a new active VRT frame to draw
 * PARAMETERS
 *  frame_handle    : [IN] The VRT frame handle to set active
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_push_and_set_active_frame(vrt_frame_handle frame_handle);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_pop_and_restore_frame
 * DESCRIPTION
 *  Pop the VRT frame handle in stack and restore to be active 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_pop_and_restore_frame(void);
 
/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_set_font
 * DESCRIPTION
 *  Set font to draw context
 * PARAMETERS
 *  font            : [IN] The font to set
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_set_font(const vrt_font_struct *font);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_set_ellipsis
 * DESCRIPTION
 *  Set the ellipsis string to draw a truncated text
 * PARAMETERS
 *  ellipsis        : [IN] The ellipsis string to set
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_set_ellipsis(const vrt_wchar *ellipsis, vrt_bool is_dynamic_string);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_set_clip
 * DESCRIPTION
 *  Set the clip rectangle to draw context
 * PARAMETERS
 *  clip_rect       : [IN] The clip rectangle to set
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_set_clip(const vrt_rect_struct *clip_rect);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_set_fill_color
 * DESCRIPTION
 *  Set the fill color to draw context
 * PARAMETERS
 *  color           : [IN] The fill color to set
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_set_fill_color(vrt_color_type color);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_set_stroke_color
 * DESCRIPTION
 *  Set the stroke color to draw context
 * PARAMETERS
 *  color           : [IN] The stroke color to set
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_set_stroke_color(vrt_color_type color);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_set_background_color
 * DESCRIPTION
 *  Set the background color
 *  Background color is the color of region that is not covered by any frame.
 * PARAMETERS
 *  color           : [IN] The background color to set
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_set_background_color(vrt_color_type color);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_set_layer_frame_clear_color
 * DESCRIPTION
 *  Set the layer frame clear color
 * PARAMETERS
 *  color           : [IN] clear color
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_set_layer_frame_clear_color(vrt_color_type color);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_set_fallback_image
 * DESCRIPTION
 *  Set the frame fallback image
 * PARAMETERS
 *  resId           : [IN] resource id of fallback image
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_set_fallback_image(vrt_s32 resId);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_disable_freeze
 * DESCRIPTION
 *  Set if disable VRT freezing display
 * PARAMETERS
 *  is_disabled     : [IN] If disable VRT freezing display
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_disable_freeze(vrt_bool is_disabled);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_fill_rect
 * DESCRIPTION
 *  Fill a rectangle with fill color
 * PARAMETERS
 *  x               : [IN] The x position of the rectangle
 *  y               : [IN] The y position of the rectangle
 *  width           : [IN] The width size of the rectangle
 *  height          : [IN] The height size of the rectangle
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_fill_rect(vrt_s32 x, vrt_s32 y, vrt_s32 width, vrt_s32 height);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_pixel
 * DESCRIPTION
 *  Draw a pixel with stroke color
 * PARAMETERS
 *  x               : [IN] The x position of the pixel
 *  y               : [IN] The y position of the pixel
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_pixel(vrt_s32 x, vrt_s32 y);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_line
 * DESCRIPTION
 *  Draw a line with stroke color
 * PARAMETERS
 *  x1              : [IN] The x position of point 1
 *  y1              : [IN] The y position of point 1
 *  x2              : [IN] The x position of point 2
 *  y2              : [IN] The y position of point 2
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_line(vrt_s32 x1, vrt_s32 y1, vrt_s32 x2, vrt_s32 y2);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_rect
 * DESCRIPTION
 *  Draw a rectangle with stroke color
 * PARAMETERS
 *  rect            : [IN] The rectangle position and size
 *  width           : [IN] The width size of the rectangle
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_rect(const vrt_rect_struct *rect, vrt_s32 width);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_aa_line
 * DESCRIPTION
 *  Draw a anti-aliasing line with stroke color
 * PARAMETERS
 *  x1              : [IN] The x position of point 1
 *  y1              : [IN] The y position of point 1
 *  x2              : [IN] The x position of point 2
 *  y2              : [IN] The y position of point 2
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_aa_line(vrt_s32 x1, vrt_s32 y1, vrt_s32 x2, vrt_s32 y2);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_image_from_mem
 * DESCRIPTION
 *  Draw an image from mem, with image resource 8-bytes header
 * PARAMETERS
 *  x               : [IN] The x position to draw
 *  y               : [IN] The y position to draw
 *  image_ptr       : [IN] Pointer to the image
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_image_from_mem(vrt_s32 x, vrt_s32 y, const void *image_ptr);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_image_from_res_id
 * DESCRIPTION
 *  Draw an image from res id
 * PARAMETERS
 *  x               : [IN] The x position to draw
 *  y               : [IN] The y position to draw
 *  res_id        : [IN] Resource id
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_image_from_res_id(vrt_s32 x, vrt_s32 y, vrt_res_id res_id);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_image_from_file
 * DESCRIPTION
 *  Draw an image from file
 * PARAMETERS
 *  x               : [IN] The x position to draw
 *  y               : [IN] The y position to draw
 *  filename        : [IN] The file name of the image
 *  info           : [IN] The info of the image
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_image_from_file(vrt_s32 x, vrt_s32 y, const vrt_wchar *filename, const vrt_sys_image_info_struct *info);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_resized_image_from_mem
 * DESCRIPTION
 *  Draw a resized image from mem, with image resource 8-bytes header
 * PARAMETERS
 *  rect            : [IN] The position and size to draw
 *  image_ptr       : [IN] Pointer to the image
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_resized_image_from_mem(const vrt_rect_struct *rect, const void *image_ptr);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_resized_image_from_res_id
 * DESCRIPTION
 *  Draw a resized image from res id
 * PARAMETERS
 *  rect            : [IN] The position and size to draw
 *  res_id         : [IN] res_id
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_resized_image_from_res_id(const vrt_rect_struct *rect, vrt_res_id res_id);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_resized_image_from_file
 * DESCRIPTION
 *  Draw a resized image from file
 * PARAMETERS
 *  rect            : [IN] The position and size to draw
 *  filename        : [IN] The file name of the image
 *  info            : [IN] The info of the image
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_resized_image_from_file(const vrt_rect_struct *rect, const vrt_wchar *filename, const vrt_sys_image_info_struct *info);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_image_content_from_mem
 * DESCRIPTION
 *  Draw an image from memory, placement in the current frame bounds,
 *  with image resource 8-bytes header
 * PARAMETERS
 *  image_ptr       : [IN] Pointer to the image
 *  place_type      : [IN] The placement type to draw
 *  image_size      : [IN] the size of given image (must same as given image)
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_image_content_from_mem(const void *image_ptr, vrt_frame_content_placement_type_enum place_type, const vrt_size_struct *image_size);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_image_content_from_res_id
 * DESCRIPTION
 *  Draw an image from res id, placement in the current frame bounds
 * PARAMETERS
 *  res_id             : [IN] Resource id
 *  place_type      : [IN] The placement type to draw
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_image_content_from_res_id(vrt_res_id res_id, vrt_frame_content_placement_type_enum place_type);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_image_content_from_file
 * DESCRIPTION
 *  Draw an image from file, placement in the current frame bounds,
 * PARAMETERS
 *  filename        : [IN] The file name of the image
 *  place_type      : [IN] The placement type to draw
 *  info                 : [IN] The info of the image
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_image_content_from_file(const vrt_wchar *filename, vrt_frame_content_placement_type_enum place_type, const vrt_sys_image_info_struct *info);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_image_content_from_layer
 * DESCRIPTION
 *  Draw an image from a layer, placement in the current frame bounds,
 * PARAMETERS
 *  gdi_handle      : [IN] The GDI layer to draw
 *  place_type      : [IN] The placement type to draw
 *  image_size      : [IN] the size of given image (must same as given image)
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_image_content_from_layer(void *gdi_handle, vrt_frame_content_placement_type_enum place_type, const vrt_size_struct *image_size);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_text
 * DESCRIPTION
 *  Draw a text
 * PARAMETERS
 *  x               : [IN] The x position to draw
 *  y               : [IN] The y position to draw
 *  string          : [IN] The text to draw
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_text(vrt_s32 x, vrt_s32 y, const vrt_wchar *string, vrt_bool is_dynamic_string);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_text_truncated
 * DESCRIPTION
 *  Draw a truncated text
 * PARAMETERS
 *  x               : [IN] The x position to draw
 *  y               : [IN] The y position to draw
 *  string          : [IN] The text to draw
 *  width           : [IN] The width to truncated
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_text_truncated(vrt_s32 x, vrt_s32 y, const vrt_wchar *string, vrt_s32 width, vrt_bool is_dynamic_string);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_text_truncated
 * DESCRIPTION
 *  Draw a truncated text
 * PARAMETERS
 *  rect            : [IN] The rectangle to draw
 *  baseline        : [IN] The baseline to draw
 *  string          : [IN] The text to draw
 *  width           : [IN] The width to truncated
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_text_truncated_baseline(const vrt_rect_struct *rect, vrt_s32 baseline, const vrt_wchar *string, vrt_s32 width, vrt_bool is_dynamic_string);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_text_n
 * DESCRIPTION
 *  Draw a text with length
 * PARAMETERS
 *  pos             : [IN] The position to draw
 *  string          : [IN] The text to draw
 *  len             : [IN] The character number of text
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_text_n(const vrt_point_struct *pos, const vrt_wchar *string, vrt_u32 len, vrt_bool is_dynamic_string);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_text_n
 * DESCRIPTION
 *  Draw a text with baseline
 * PARAMETERS
 *  rect            : [IN] The rectangle to draw
 *  baseline        : [IN] The baseline to draw
 *  string          : [IN] The text to draw
 *  len             : [IN] The character number of text
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_text_n_baseline(const vrt_rect_struct *rect, vrt_s32 baseline, const vrt_wchar *string, vrt_u32 len, vrt_bool is_dynamic_string);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_layer
 * DESCRIPTION
 *  Draw a GDI layer
 * PARAMETERS
 *  x               : [IN] The x position to draw
 *  y               : [IN] The y position to draw
 *  gdi_handle      : [IN] The GDI handle to draw
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_layer(vrt_s32 x, vrt_s32 y, void *gdi_handle);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_resized_layer
 * DESCRIPTION
 *  Draw a resized GDI layer
 * PARAMETERS
 *  rect            : [IN] The position and size to draw
 *  gdi_handle      : [IN] The GDI handle to draw
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_resized_layer(const vrt_rect_struct *rect, void *gdi_handle);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_img_buf
 * DESCRIPTION
 *  Draw an image buffer
 * PARAMETERS
 *  x               : [IN] The x position to draw
 *  y               : [IN] The y position to draw
 *  img_buf         : [IN] The image buffer to draw
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_img_buf(vrt_s32 x, vrt_s32 y, const vrt_image_buffer_struct *img_buf);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_img_raw_data
 * DESCRIPTION
 *  Draw an image raw data with no 8 byte header
 * PARAMETERS
 *  x               : [IN] The x position to draw
 *  y               : [IN] The y position to draw
 *  img_buf         : [IN] The image buffer with non 8 byte header to draw
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_img_raw_data(vrt_s32 x, vrt_s32 y, const vrt_file_raw_data_buffer_struct *img_buf);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_resized_raw_data
 * DESCRIPTION
 *  Draw a resized image buffer with not image 8 byte header
 * PARAMETERS
 *  rect            : [IN] The position and size to draw
 *  img_buf         : [IN] The image buffer with non 8 byte header to draw
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_resized_raw_data(const vrt_rect_struct *rect, const vrt_file_raw_data_buffer_struct *img_buf);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_image_content_from_raw_data
 * DESCRIPTION
 *  Draw an image buffer, placement in the current frame bounds,
 *  with not image 8-bytes header
 * PARAMETERS
 *  img_buf         : [IN] The image buffer with non 8 byte header to draw
 *  place_type      : [IN] The placement type to draw
 *  image_size      : [IN] the size of given image (must same as given image)
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_image_content_from_raw_data(const vrt_file_raw_data_buffer_struct *img_buf, vrt_frame_content_placement_type_enum place_type, const vrt_size_struct *image_size);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_resized_img_buf
 * DESCRIPTION
 *  Draw a resized image buffer
 * PARAMETERS
 *  rect            : [IN] The position and size to draw
 *  img_buf         : [IN] The image buffer to draw
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_resized_img_buf(const vrt_rect_struct *rect, const vrt_image_buffer_struct *img_buf);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_image_content_from_img_buf
 * DESCRIPTION
 *  Draw an image buffer, placement in the current frame bounds,
 *  with image resource 8-bytes header
 * PARAMETERS
 *  img_buf         : [IN] The image buffer to draw
 *  place_type      : [IN] The placement type to draw
 *  image_size      : [IN] the size of given image (must same as given image)
 * RETURNS
 *  The command index
 *****************************************************************************/
extern vrt_u32 vrt_canvas_draw_image_content_from_img_buf(const vrt_image_buffer_struct *img_buf, vrt_frame_content_placement_type_enum place_type, const vrt_size_struct *image_size);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_draw_world
 * DESCRIPTION
 *  Draw 3d world,
 * PARAMETERS
 *  handle          : [IN] The handle to world
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_draw_world(vrt_object_handle handle);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_set_resource
 * DESCRIPTION
 *  Set image resource
 * PARAMETERS
 *  image_ptr          [IN]     pointer to image
 * RETURNS
 *  void
 *****************************************************************************/
/* For detail description, please refer to vrt_canvas.h */
extern void vrt_canvas_set_resource(const vrt_image_source_struct *image_src);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_get_resouce
 * DESCRIPTION
 *  Get image buffer from image source
 * PARAMETERS
 *  img_src            [IN]     pointer to image source
 *  img_buf            [IN]     pointer to image buffer structure
 * RETURNS
 *  void
 *****************************************************************************/
extern vrt_bool vrt_canvas_get_resource(vrt_image_source_struct *img_src, vrt_image_buffer_struct *img_buf);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_before_using_resource
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_before_using_resource(void);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_after_using_resource
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_after_using_resource(void);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_get_frame_visual_property
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern vrt_frame_visual_property_struct *vrt_canvas_get_frame_visual_property(vrt_frame_property_handle frame_property_handle);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_get_frame_property_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern vrt_frame_property_handle vrt_canvas_get_frame_property_handle(vrt_frame_handle frame_handle);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_convert_point_to_root_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_convert_point_to_root_frame(vrt_frame_property_handle frame_property_handle, vrt_point_struct *point);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_intersect_rect_to_root_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern void vrt_canvas_intersect_rect_to_root_frame(vrt_frame_property_handle frame_property_handle, vrt_rect_struct *rect);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_get_animation_image_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern vrt_animation_image_status_struct *vrt_canvas_get_animation_image_status(vrt_frame_property_handle frame_property_handle);

/*****************************************************************************
 * FUNCTION
 *  vrt_canvas_snapshot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern vrt_bool vrt_canvas_snapshot(const vrt_image_buffer_struct *snapshotBuffer);

/*
 * ***Experimental Internal functions
 */

extern vrt_color_type_enum vrt_get_default_alpha_color_format(void);
extern vrt_u32 vrt_set_busy_sleep_tick(vrt_u32 tick);

extern void *vrt_canvas_get_instance(void);

extern vrt_float vrt_timing_func_timeline_time(vrt_float t, void *data, vrt_u32 data_size);

#ifdef __cplusplus
} /* extern "C"*/
#endif 

#endif /* __VRT_CANVAS_H__ */

