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
 *  mmi_frm_gesture_gprot.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_FRM_GESTURES_GPROT_H
#define MMI_FRM_GESTURES_GPROT_H

#include "mmi_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_input_gprot.h"

#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)  

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/* gesture event */
typedef enum
{
    /* gesture event is down */
    MMI_FRM_GESTURE_DOWN,
    /* gesture event is up */
    MMI_FRM_GESTURE_UP,
    /* gesture event is left down */
    MMI_FRM_GESTURE_DOWN_LEFT,
    /* gesture event is right down */
    MMI_FRM_GESTURE_DOWN_RIGHT,
    /* gesture event is right up */
    MMI_FRM_GESTURE_UP_RIGHT,
    /* gesture event is left up */
    MMI_FRM_GESTURE_UP_LEFT,
    /* gesture event is right */
    MMI_FRM_GESTURE_RIGHT,
    /* gesture event is left */
    MMI_FRM_GESTURE_LEFT,
    /* gesture event is clockwise */
    MMI_FRM_GESTURE_CLOCKWISE,
    /* gesture event is anticlockwise */
    MMI_FRM_GESTURE_ANTICLOCKWISE,
    /* gesture event is semicircle up */
    MMI_FRM_GESTURE_SEMICIRCLE_UP,
    /* gesture event is semicircle down */
    MMI_FRM_GESTURE_SEMICIRCLE_DOWN,
    /* gesture event is semicircle left */
    MMI_FRM_GESTURE_SEMICIRCLE_LEFT,
    /* gesture event is semicircle right */
    MMI_FRM_GESTURE_SEMICIRCLE_RIGHT,
    /* gesture event is backward */
    MMI_FRM_GESTURE_BACKWARD,
    /* gesture event is forward */
    MMI_FRM_GESTURE_FORWARD,
    /* gesture event is bracket right */
    MMI_FRM_GESTURE_RIGHT_BRACKET,
    /* gesture event is bracket left */
    MMI_FRM_GESTURE_LEFT_BRACKET,
    /* Please add before this */
    MMI_FRM_GESTURE_MAX
}mmi_frm_gesture_event_enum;

/* gesture event call back */
typedef void (*mmi_frm_gesture_hdlr) (mmi_frm_gesture_event_enum);

/* custome gesture engine */
typedef MMI_BOOL (*mmi_frm_gesture_custom_engine_hdlr) (mmi_pen_event_type_enum, mmi_pen_point_struct);

/* gesture valid area */
typedef struct
{   
    /* x coordinate of left-top point */
    S16 x1;
    /* y coordinate of left-top point */
    S16 y1;
    /* x coordinate of right-bottom point */
    S16 x2;
    /* y coordinate of right-bottom point */
    S16 y2;
} mmi_frm_gesture_rect_struct;

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_listen_event
* DESCRIPTION
*  This function is used for register the gesture event which want to listen. 
*  Note:
*       The effective region of gesture is full screen. 
*       The application can receive the pen events when listens the gesture events. 
*       The gesture is invalid on Hand Writing mode.
* PARAMETERS
*  gesture_event  : [IN] gesture event
*  gesture_hdlr   : [IN] gesture call back
* RETURNS
*  MMI_TRUE if register the gesture event listener was successful; otherwise MMI_FALSE.
*****************************************************************************/
extern MMI_BOOL mmi_frm_gesture_listen_event(mmi_frm_gesture_event_enum gesture_event, mmi_frm_gesture_hdlr gesture_hdlr);

/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_listen_event_ex
* DESCRIPTION
*  This function is used for register the gesture event which want to listen. 
*  Note:
*       The effective region of gesture is within an rect 
*       The application can receive the pen events when listens the gesture events. 
*       The gesture is invalid on Hand Writing mode.
* PARAMETERS
*  gesture_event  : [IN] gesture event
*  gesture_hdlr   : [IN] gesture callback
*  gesture_rect_p : [IN] gesture valid area
* RETURNS
*  MMI_TRUE if register the gesture event listener was successful; otherwise MMI_FALSE.
*****************************************************************************/
extern MMI_BOOL mmi_frm_gesture_listen_event_ex(
                    mmi_frm_gesture_event_enum gesture_event, 
                    mmi_frm_gesture_hdlr gesture_hdlr,
                    mmi_frm_gesture_rect_struct *gesture_rect_p);

/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_stop_listen_event
* DESCRIPTION
*  This function is used to stop listen gesture event.
*  Please make sure to call this api when leave your screen if the gesture framework
*  is running.
* PARAMETERS
*  void  
* RETURNS
*  void
*****************************************************************************/
extern void mmi_frm_gesture_stop_listen_event(void);

/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_is_listening
* DESCRIPTION
*  This function is used to check if the gesture framework work or not
*  
* PARAMETERS
*  void  
* RETURNS
*  MMI_TRUE if gesture framework is running or MMI_FALSE
*****************************************************************************/
extern MMI_BOOL mmi_frm_gesture_is_listening(void);

/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_register_custom_engine
* DESCRIPTION
*  Registers an custom engine for recognise gestures.
* PARAMETERS
*  engine_hdlr : [IN]  The handler of custom recognizing engine.
* RETURNS 
*  void
*****************************************************************************/
extern void mmi_frm_gesture_register_custom_engine(mmi_frm_gesture_custom_engine_hdlr engine_hdlr);

/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_unregister_custom_engine
* DESCRIPTION
*  Unregisters the custom recognizing engine that was previously registered by a call
*  to mmi_frm_gesture_register_custom_engine().
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
extern void mmi_frm_gesture_unregister_custom_engine(void);

/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_enable
* DESCRIPTION
*  Enable the gesture 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
extern void mmi_frm_gesture_enable(void);

/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_disable
* DESCRIPTION
*  Disable the gesture 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
extern void mmi_frm_gesture_disable(void);

#endif /* #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)  */

#endif /* MMI_FRM_GESTURES_GPROT_H */

 

