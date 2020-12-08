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
 *  
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_FRM_GESTURES_H__
#define __MMI_FRM_GESTURES_H__

#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)  

#include "mmi_frm_gestures_cfg.h"

//RHR
#include "lcd_sw_inc.h"    	
#include "mmi_frm_gestures_gprot.h"    
#include "MMIDataType.h"    
#include "kal_general_types.h"	 
#include "mmi_frm_input_gprot.h"


/***************************************************************************** 
* Define
*****************************************************************************/

#define MMI_FRM_MAX_STROKES  4

/* The maximum of recordable points */
#define MMI_FRM_MAX_POINT                  256

/* The minimum of grid which is analyzable */
#define MMI_FRM_MIN_ANALYZABLE_GRID    3
/* The unit of minimum distance */
#define MMI_FRM_MIN_DISTANCE               (MIN(LCD_HEIGHT, LCD_WIDTH)/6)

/* The weight for used by analyzing broken line */
#define MMI_FRM_DIRECTIONS_PROPORTION_WEIGHT  0.5

/* The threshold for used by analyzing circle */
#define MMI_FRM_CIRCLE_DIAGONAL_THRESHOLD  0.2
#define MMI_FRM_CIRCLE_SQUARE_THRESHOLD    0.2
#define MMI_FRM_CIRCLE_START_END_PROXIMITY_THRESHOLD  MMI_FRM_MIN_DISTANCE
#define MMI_FRM_CIRCLE_START_END_PROXIMITY_DISTANCE   20
#define MMI_FRM_CIRCLE_DIRECTION_CHANGE_THRESHOLD     0.3

/* The threshold for used by analyzing semicircle */
#define MMI_FRM_SEMICIRCLE_HIGH_RECOGNIZABILITY
#ifdef MMI_FRM_SEMICIRCLE_HIGH_RECOGNIZABILITY
#define MMI_FRM_SEMICIRCLE_BELONG_TO_CIRCLE         0.7
#define MMI_FRM_SEMICIRCLE_POINT_COORDINATES_DIFF   30
#define MMI_FRM_SEMICIRCLE_DISTANCE_THRESHOLD       0.3
#else /* MMI_FRM_SEMICIRCLE_HIGH_RECOGNIZABILITY */
#define MMI_FRM_SEMICIRCLE_BELONG_TO_CIRCLE         0.9
#define MMI_FRM_SEMICIRCLE_POINT_COORDINATES_DIFF   20
#define MMI_FRM_SEMICIRCLE_DISTANCE_THRESHOLD       0.2
#endif /* MMI_FRM_SEMICIRCLE_HIGH_RECOGNIZABILITY */

/* The threshold for used by analyzing straight line */
#define MMI_FRM_DIRECTIONS_UPPER_THRESHOLD 0.8
#define MMI_FRM_DIRECTIONS_LOWER_THRESHOLD 0.5

/* The threshold for used by analyzing diagonal directions */
#define MMI_FRM_DIAGONAL_XY_RATIO_UPPER_THRESHOLD 2
#define MMI_FRM_DIAGONAL_XY_RATIO_LOWER_THRESHOLD 0.5

/* The size of needs screen base ASM  */
#define MMI_FRM_GESTURE_ENGINE_POOL_SIZE MMI_FRM_MAX_POINT*8 + MMI_FRM_GESTURE_MAX*4


/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef void (*mmi_frm_gesture_hdlr) (mmi_frm_gesture_event_enum);
typedef MMI_BOOL (*mmi_frm_gesture_custom_engine_hdlr) (mmi_pen_event_type_enum, mmi_pen_point_struct);

typedef struct{
    mmi_frm_gesture_event_enum event_enum; 
    mmi_frm_strokes_enum       strokes[MMI_FRM_MAX_STROKES + 1];
}mmi_frm_gesture_struct;



/***************************************************************************** 
* Extern Variable
*****************************************************************************/
extern const mmi_frm_gesture_struct mmi_frm_gesture_array[MMI_FRM_GESTURE_MAX];


/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

extern MMI_BOOL mmi_frm_gesture_listen_event(mmi_frm_gesture_event_enum gesture_event, mmi_frm_gesture_hdlr gesture_hdlr);
extern void     mmi_frm_gesture_stop_listen_event(void);
extern MMI_BOOL mmi_frm_gesture_is_listening(void);

extern MMI_BOOL mmi_frm_gesture_recognise(mmi_pen_event_type_enum event, mmi_pen_point_struct pos);

extern void mmi_frm_gesture_register_custom_engine(mmi_frm_gesture_custom_engine_hdlr engine_hdlr);
extern void mmi_frm_gesture_unregister_custom_engine(void);

extern void mmi_frm_gestures_draw_track(void);
extern void mmi_frm_gesture_enable_debug_mode(void);
extern void mmi_frm_gesture_disable_debug_mode(void);
extern void mmi_frm_gesture_enable(void);
extern void mmi_frm_gesture_disable(void);

#endif /* #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)  */

#endif /* #ifndef __MMI_FRM_GESTURE_H__ */

 

