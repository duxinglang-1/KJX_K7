/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vfx_adp_device.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Hardware Device Adapatation Layer 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VFX_ADP_DEVICE_H__
#define __VFX_ADP_DEVICE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For basic types
#include "vfx_datatype.h"

#ifdef __cplusplus
extern "C"
{
#endif


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef enum
{
    VFX_ADP_SLEEP_MODE_STATE_UNKNOWN = 0,
    VFX_ADP_SLEEP_MODE_STATE_ENABLE,
    VFX_ADP_SLEEP_MODE_STATE_DISABLE,
    VFX_ADP_SLEEP_MODE_STATE_END_OF_ENUM
} vfx_adp_sleep_mode_state_enum;

typedef enum
{
    VFX_ADP_TOUCH_FB_TYPE_DOWN,
    VFX_ADP_TOUCH_FB_TYPE_DOWN_VIBRATE,
    VFX_ADP_TOUCH_FB_TYPE_DOWN_TONE,
    VFX_ADP_TOUCH_FB_TYPE_HOLD,
    VFX_ADP_TOUCH_FB_TYPE_SPECIAL,
    VFX_ADP_TOUCH_FB_TYPE_END_OF_ENUM
} vfx_adp_touch_fb_type_enum;


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*
 * LCD
 */

/*****************************************************************************
 * FUNCTION
 *  vfx_adp_sleep_mode_get_state
 * DESCRIPTION
 *  Adaptation Function to get the sleep mode state
 * PARAMETERS
 *  void
 * RETURNS
 *  sleep mode state
 *****************************************************************************/
extern vfx_adp_sleep_mode_state_enum vfx_adp_sleep_mode_get_state(void);


/*
 * Screen Rotation Sensor
 *  Ex. G-Sensor, Side Qwerty switch, etc.
 */

/*****************************************************************************
 * FUNCTION
 *  vfx_adp_srs_enable
 * DESCRIPTION
 *  Adaptation Function to enable screen rotate sensor.
 *  Venus UI Engine use this function to enable sensor.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vfx_adp_srs_enable(void);

/*****************************************************************************
 * FUNCTION
 *  vfx_adp_srs_enable
 * DESCRIPTION
 *  Adaptation Function to disable screen rotate sensor.
 *  Venus UI Engine use this function to disable sensor.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vfx_adp_srs_disable(void);

/*****************************************************************************
 * FUNCTION
 *  vfx_adp_srs_on_rotate
 * DESCRIPTION
 *  When screen rotation sensor detects the screen need to rotate,
 *  call this function to ask Venus UI Engine to handle it.
 * PARAMETERS
 *  rotate_type [IN] The new rotate type
 * RETURNS
 *  void
 *****************************************************************************/
extern void vfx_adp_srs_on_rotate(VfxScrRotateTypeEnum rotate_type);


/*****************************************************************************
 * FUNCTION
 *  vfx_adp_srs_get_value
 * DESCRIPTION
 *  query current value of screen rotate_sensor
 * PARAMETERS
 *  void
 * RETURNS
 *  current value of screen rotate_sensor
 *****************************************************************************/
extern VfxScrRotateTypeEnum vfx_adp_srs_get_value(void);


/*****************************************************************************
 * FUNCTION
 *  vfx_adp_srs_is_paused
 * DESCRIPTION
 *  query current paused count of screen rotate
 * PARAMETERS
 *  void
 * RETURNS
 *  current count of screen rotate pause
 *****************************************************************************/
extern VfxS32 vfx_adp_srs_is_paused(void);


/*****************************************************************************
 * FUNCTION
 *  vfx_adp_srs_pause
 * DESCRIPTION
 *  pause current screen rotate of AP
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vfx_adp_srs_pause(void);


/*****************************************************************************
 * FUNCTION
 *  vfx_adp_srs_resume
 * DESCRIPTION
 *  resume current screen rotate of AP
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vfx_adp_srs_resume(void);


/*
 * Touch Feedback
 *  Ex. Vibrate, tone, etc.
 */

/*****************************************************************************
 * FUNCTION
 *  vfx_adp_touch_fb_enable_tone
 * DESCRIPTION
 *  Adaptation Function to enable tone touch feedback.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vfx_adp_touch_fb_enable_tone(void);

/*****************************************************************************
 * FUNCTION
 *  vfx_adp_touch_fb_disable_tone
 * DESCRIPTION
 *  Adaptation Function to disable tone touch feedback.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vfx_adp_touch_fb_disable_tone(void);

/*****************************************************************************
 * FUNCTION
 *  vfx_adp_touch_fb_enable_vibrate
 * DESCRIPTION
 *  Adaptation Function to enable vibrate touch feedback.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vfx_adp_touch_fb_enable_vibrate(void);

/*****************************************************************************
 * FUNCTION
 *  vfx_adp_touch_fb_disable_vibrate
 * DESCRIPTION
 *  Adaptation Function to disable vibrate touch feedback.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vfx_adp_touch_fb_disable_vibrate(void);

/*****************************************************************************
 * FUNCTION
 *  vfx_adp_touch_fb_enable
 * DESCRIPTION
 *  Adaptation Function to enable touch feedback.
 *  Venus UI Engine use this function to enable device.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vfx_adp_touch_fb_enable(void);


/*****************************************************************************
 * FUNCTION
 *  vfx_adp_touch_fb_disable
 * DESCRIPTION
 *  Adaptation Function to disable touch feedback.
 *  Venus UI Engine use this function to disable device.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vfx_adp_touch_fb_disable(void);


/*****************************************************************************
 * FUNCTION
 *  vfx_adp_touch_fb_play
 * DESCRIPTION
 *  Adaptation Function to play touch feedback result with given type.
 *  Venus UI Engine use this function to play.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vfx_adp_touch_fb_play(vfx_adp_touch_fb_type_enum type);


#ifdef __cplusplus
} /* extern "C"*/
#endif 

#endif /* __VFX_ADP_DEVICE_H__ */

