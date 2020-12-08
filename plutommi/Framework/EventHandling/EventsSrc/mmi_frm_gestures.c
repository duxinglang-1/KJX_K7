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
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "mmi_features.h"

#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) 

#include "mmi_frm_gestures.h"
#include "math.h"
#include "mmi_frm_gestures_cfg.h"
#include "mmi_frm_input_gprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_gestures_gprot.h"
#include "string.h"
#include "lcd_sw_inc.h"
#include "app_mem.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_fw_trc.h"
#include "kal_trace.h"
#include "gui.h"
#include "gui_typedef.h"
#include "gdi_include.h"
/*****************************************************************************
* Define
*****************************************************************************/

/* Shortcut macro for gets the larger of two specified numbers. */
#ifndef MAX
    #define MAX(a, b)   ((a) > (b) ? (a) : (b))
#endif
/* Shortcut macro for gets the smaller of two specified numbers. */
#ifndef MIN
    #define MIN(a, b)   ((a) < (b) ? (a) : (b))
#endif
/* Shortcut macro for gets the absolute value of a specified number. */
#ifndef ABS
    #define ABS(x)          ((x)>=0 ? (x) : -(x))
#endif
/* Shortcut macro for gets the number of elements in a specified array. */
#define COUNT_ARRAY(a)  sizeof(a)/sizeof(a[0])

/* Shortcut macro for accesses previous recorded point */
#define MMI_FRM_GESTURE_PRE_POS     (g_gesture_framework_p->gesture_info.points_sequence[g_gesture_framework_p->gesture_info.points_sequence_count - 1])
/* Shortcut macro for accesses current recorded point */
#define MMI_FRM_GESTURE_CUR_POS     (g_gesture_framework_p->gesture_info.points_sequence[g_gesture_framework_p->gesture_info.points_sequence_count])

/* Shortcut macro for gets the total number of analyzable directions */
#define MMI_FRM_DIRECTIONS_NUM               (MMI_FRM_STROKES_UP_LEFT - MMI_FRM_STROKES_UP + 1) 
/* Shortcut macro for means the specified two directions is neighbouring */
#define MMI_FRM_DIRECTIONS_NEIGHBOUR         (MMI_FRM_STROKES_UP_RIGHT - MMI_FRM_STROKES_UP)
#define MMI_FRM_DIRECTIONS_CYCLE_NEIGHBOUR   (MMI_FRM_STROKES_UP - MMI_FRM_STROKES_UP_LEFT) 

#define MMI_FRM_GESTRUE_BELONG_TO_CIRCLE_DIRECTION(direction)   \
        ((direction == MMI_FRM_DIRECTIONS_NEIGHBOUR) || (direction == 2 * MMI_FRM_DIRECTIONS_NEIGHBOUR) ||  \
         (direction == MMI_FRM_DIRECTIONS_CYCLE_NEIGHBOUR) || (direction == MMI_FRM_DIRECTIONS_CYCLE_NEIGHBOUR + 1) ||  \
         (direction == MMI_FRM_DIRECTIONS_CYCLE_NEIGHBOUR + 2) || (direction == 3 * MMI_FRM_DIRECTIONS_NEIGHBOUR))

/*****************************************************************************
* Data Type
*****************************************************************************/
typedef enum{
    UNKNOWN_CIRCLE,
    CLOCKWISE_CIRCLE = MMI_FRM_STROKES_CLOCKWISE,
    ANTICLOCKWISE_CIRCLE = MMI_FRM_STROKES_ANTICLOCKWISE,
    NON_CIRCLE
}mmi_frm_gesture_circle_enum; 

typedef enum{
    TRACK_START,
    TRACK_MIDDLE,
    TRACK_END
}mmi_frm_gesture_track_status_enum; 


typedef struct{
    double direction[MMI_FRM_DIRECTIONS_NUM];
    double total;
}mmi_frm_gesture_distances_struct;

typedef struct{
    double direction[MMI_FRM_DIRECTIONS_NUM];   /* Percentage of the gesture that consists of the pen moving to 8 directions. */ 
    double square;      /* Percentage of the gesture that is straight (that is, the sum of Right, Left, Up, and Down). */
    double diagonal;    /* Percentage of the gesture that is made of diagonal lines (that is, the sum of RightUp, RightDown, LeftUp, and LeftDown).. */
    double inflexion;   /* Essentially, the number of corners in the shape, counting the start point and end point as corners. */
    double start_end_proximity;  /* Distance between the start point of the gesture and the end point of the 
                                    gesture. Used to determine if the gesture is a closed shape, like a circle, 
                                    or an open shape, like a check mark.  */
    double clockwise;
    double anticlockwise;
    double direction_change;
    mmi_frm_gesture_circle_enum circle;
}mmi_frm_gesture_statistics_struct;

typedef struct{
    mmi_frm_strokes_enum  vectors_sequence[MMI_FRM_MAX_POINT - 1];
    mmi_pen_point_struct  points_sequence[MMI_FRM_MAX_POINT]; 
    U16 points_sequence_count;
    MMI_BOOL is_overflow;   
    mmi_frm_gesture_distances_struct distances;    
    mmi_frm_gesture_statistics_struct gesture_statistics;
}mmi_frm_gesture_info_struct;

typedef struct{
    mmi_frm_gesture_hdlr       gesture_hdlr;
    mmi_frm_gesture_event_enum gesture_event;   
}mmi_frm_gesture_hdlr_info_struct;

typedef struct{
    mmi_frm_gesture_info_struct gesture_info;
    mmi_frm_gesture_hdlr_info_struct gesture_hdlr_array[MMI_FRM_GESTURE_MAX];
    mmi_frm_gesture_rect_struct rect;
    U16 gesture_hdlr_count; 
    MMI_BOOL is_gesture_enable;
}mmi_frm_gesture_framework_struct;

/*****************************************************************************  
*   Local Variables 
*****************************************************************************/

mmi_frm_gesture_framework_struct   *g_gesture_framework_p = NULL;

mmi_frm_gesture_custom_engine_hdlr g_custom_engine_hdlr = NULL;

static MMI_BOOL g_debug_mode = MMI_FALSE;


/***************************************************************************** 
*   Local Functions 
*****************************************************************************/

static void mmi_frm_gesture_reset(void);

static void mmi_frm_gesture_record_track(mmi_pen_point_struct pos, mmi_frm_gesture_track_status_enum track_status);

static void mmi_frm_gesture_get_statistics(void);
static void mmi_frm_gesture_calculate_inflexion(S32 index);
static void mmi_frm_gesture_calculate_clockwise(S32 index);
static double mmi_frm_gesture_calculate_distance(mmi_pen_point_struct point_1, mmi_pen_point_struct point_2);
static mmi_frm_strokes_enum mmi_frm_gesture_calculate_direction(mmi_pen_point_struct cur_pos, mmi_pen_point_struct pre_pos);

static void mmi_frm_gesture_parser(void);
static MMI_BOOL mmi_frm_gesture_is_match(const mmi_frm_strokes_enum *pattern);
static MMI_BOOL mmi_frm_gesture_is_match_circle(mmi_frm_strokes_enum pattern);
static MMI_BOOL mmi_frm_gesture_is_match_semicircle(mmi_frm_strokes_enum pattern);
static MMI_BOOL mmi_frm_gesture_is_match_straight(mmi_frm_strokes_enum pattern);
static MMI_BOOL mmi_frm_gesture_is_match_broken_line(const mmi_frm_strokes_enum *pattern);

static void mmi_frm_gesture_print_info(S32 index);


/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_register_custom_engine
* DESCRIPTION
*  Registers an custom engine for recognise gestures.
* PARAMETERS
*  engine_hdlr [IN]  The handler of custom recognizing engine.
* RETURNS 
*  void
*****************************************************************************/
void mmi_frm_gesture_register_custom_engine(mmi_frm_gesture_custom_engine_hdlr engine_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_custom_engine_hdlr = engine_hdlr;
}


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
void mmi_frm_gesture_unregister_custom_engine(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_custom_engine_hdlr = NULL;
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_init
* DESCRIPTION
*  Resets the state of gesture recogniser.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_gesture_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != g_gesture_framework_p)
    {
        memset(&(g_gesture_framework_p->gesture_info), 0, sizeof(mmi_frm_gesture_info_struct));
    }
}

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
*  gesture_event [IN]
*  gesture_hdlr  [IN]
* RETURNS
*  MMI_TRUE if register the gesture event listener was successful; otherwise MMI_FALSE.
*****************************************************************************/
MMI_BOOL mmi_frm_gesture_listen_event(mmi_frm_gesture_event_enum gesture_event, mmi_frm_gesture_hdlr gesture_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_gesture_rect_struct gesture_rect;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gesture_rect.x1 = 0;
    gesture_rect.y1 = 0;
    gesture_rect.x2 = UI_DEVICE_WIDTH;
    gesture_rect.y2 = UI_DEVICE_HEIGHT;
    return mmi_frm_gesture_listen_event_ex(gesture_event, gesture_hdlr, &gesture_rect);
}

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
*  gesture_event  :[IN]
*  gesture_hdlr   :[IN]
*  gesture_rect_p :[IN]
* RETURNS
*  MMI_TRUE if register the gesture event listener was successful; otherwise MMI_FALSE.
*****************************************************************************/
MMI_BOOL mmi_frm_gesture_listen_event_ex(mmi_frm_gesture_event_enum gesture_event, 
                                      mmi_frm_gesture_hdlr gesture_hdlr, mmi_frm_gesture_rect_struct *gesture_rect_p)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_gesture_framework_p)
    {
        g_gesture_framework_p = applib_mem_screen_alloc(sizeof(mmi_frm_gesture_framework_struct));

        MMI_ASSERT(g_gesture_framework_p);
        
        memset(g_gesture_framework_p, 0, sizeof(mmi_frm_gesture_framework_struct));
        g_gesture_framework_p->is_gesture_enable = MMI_TRUE;
        mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_2, MMI_PEN_SAMPLING_PERIOD_2);
    }

    memcpy(&g_gesture_framework_p->rect, gesture_rect_p, sizeof(g_gesture_framework_p->rect));

    if ((gesture_event < MMI_FRM_GESTURE_MAX) && (gesture_hdlr != NULL))
    {
        /* found the description of gesture */
        for (i = 0; i < COUNT_ARRAY(mmi_frm_gesture_array); i++)
        {
            if (gesture_event == mmi_frm_gesture_array[i].event_enum)
            {
                break;
            }
        }
        
        /* if the gesture hasn't description, return false */
        if (i == COUNT_ARRAY(mmi_frm_gesture_array))
        {
            return MMI_FALSE;
        }
        

        /* Check the gesture if registered */
        for (j = 0; j < g_gesture_framework_p->gesture_hdlr_count; j++)
        {
            if (g_gesture_framework_p->gesture_hdlr_array[j].gesture_event == gesture_event)
            {
                /* Overwrite the pre-register*/
                g_gesture_framework_p->gesture_hdlr_array[j].gesture_hdlr  = gesture_hdlr;
                return MMI_TRUE;
            }                
        }          

        /* Add new register*/
        g_gesture_framework_p->gesture_hdlr_array[g_gesture_framework_p->gesture_hdlr_count].gesture_event = gesture_event;
        g_gesture_framework_p->gesture_hdlr_array[g_gesture_framework_p->gesture_hdlr_count].gesture_hdlr  = gesture_hdlr;
        g_gesture_framework_p->gesture_hdlr_count++;

        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_listen_event
* DESCRIPTION
*  
* PARAMETERS
*  
*  
* RETURNS
*  void
*****************************************************************************/
void mmi_frm_gesture_stop_listen_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != g_gesture_framework_p)
    {
        applib_mem_screen_free(g_gesture_framework_p);
        g_gesture_framework_p = NULL;
        mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_1, MMI_PEN_SAMPLING_PERIOD_2);
    }
}

/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  
*  
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL mmi_frm_gesture_is_listening(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != g_gesture_framework_p)
    {
        return MMI_TRUE;        
    }
    else
    {
        return MMI_FALSE;      	 
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_record_track
* DESCRIPTION
*  Records the user inputed gesture track.
* PARAMETERS
*  pos           [IN]  The position of pen;
*  track_status  [IN]  The status of track line;
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_gesture_record_track(mmi_pen_point_struct pos, mmi_frm_gesture_track_status_enum track_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x_dif, y_dif;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_gesture_framework_p->gesture_info.is_overflow)
    {
        return;
    }

    if (track_status == TRACK_START)
    {
        MMI_FRM_GESTURE_CUR_POS.x =  pos.x;
        MMI_FRM_GESTURE_CUR_POS.y =  pos.y;
        g_gesture_framework_p->gesture_info.points_sequence_count++;

        return;
    }
    
    x_dif = ABS(MMI_FRM_GESTURE_PRE_POS.x - pos.x);
    y_dif = ABS(MMI_FRM_GESTURE_PRE_POS.y - pos.y);
   

    if (MAX(x_dif, y_dif) > MMI_FRM_MIN_ANALYZABLE_GRID)
    {
        if (g_gesture_framework_p->gesture_info.points_sequence_count < MMI_FRM_MAX_POINT)
        {
            MMI_FRM_GESTURE_CUR_POS.x =  pos.x;
            MMI_FRM_GESTURE_CUR_POS.y =  pos.y;
            g_gesture_framework_p->gesture_info.points_sequence_count++;            
        }
        else
        {
            g_gesture_framework_p->gesture_info.is_overflow = MMI_TRUE;
        }
     }
}


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
void mmi_frm_gesture_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != g_gesture_framework_p)
    {
        g_gesture_framework_p->is_gesture_enable = MMI_TRUE;
    }
}


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
void mmi_frm_gesture_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != g_gesture_framework_p)
    {
        g_gesture_framework_p->is_gesture_enable = MMI_FALSE;
        mmi_frm_gesture_reset();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_recognise
* DESCRIPTION
*  Recognise the gesture 
* PARAMETERS
*  event    [IN]   the pen event;
*  pos      [IN]   the position of pen; 
* RETURNS
*  MMI_TRUE if recognise the gesture was successful; otherwise MMI_FALSE.
*****************************************************************************/
MMI_BOOL mmi_frm_gesture_recognise(mmi_pen_event_type_enum event, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static MMI_BOOL in_rect = MMI_TRUE;
    static MMI_BOOL out_rect = MMI_FALSE;
    MMI_BOOL temp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_gesture_framework_p == NULL) || (g_gesture_framework_p->is_gesture_enable == MMI_FALSE))
    {
        return MMI_FALSE;
    }

    if (NULL != g_custom_engine_hdlr)
    {
        if(g_custom_engine_hdlr(event, pos))
        {
            return MMI_TRUE;
        }
    }
    temp = (MMI_BOOL)((pos.x >= g_gesture_framework_p->rect.x1) &&
            					(pos.x <= g_gesture_framework_p->rect.x2) &&
            					(pos.y >= g_gesture_framework_p->rect.y1) &&
            					(pos.y <= g_gesture_framework_p->rect.y2));
    if (event == MMI_PEN_EVENT_DOWN)
    {
        in_rect = temp;
        out_rect = MMI_FALSE;
    }
    else
    {
        if (out_rect == MMI_FALSE)
        {
            out_rect = (MMI_BOOL)(!temp);
        }
    }
    if (in_rect == MMI_FALSE)
    {
        return MMI_FALSE;
    }
    if (out_rect == MMI_TRUE)
    {
        return MMI_FALSE;
    }

    
    switch (event)
    {
        case MMI_PEN_EVENT_DOWN: 
            
            mmi_frm_gesture_reset();
            mmi_frm_gesture_record_track(pos, TRACK_START);
            break;
    
        case MMI_PEN_EVENT_MOVE:
            mmi_frm_gesture_record_track(pos, TRACK_MIDDLE);
            break;
    
        case MMI_PEN_EVENT_UP:            
            mmi_frm_gesture_record_track(pos, TRACK_END);
            if(!g_gesture_framework_p->gesture_info.is_overflow)
            {                           
                mmi_frm_gesture_get_statistics();
                mmi_frm_gesture_parser();
            }
            break;

        case MMI_PEN_EVENT_ABORT:
            mmi_frm_gesture_reset();
            break;

        default:
            return MMI_FALSE;            
    }
       
    if (g_debug_mode)
    {
        mmi_frm_gestures_draw_track();
    }   
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_enable_debug_mode
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_frm_gesture_enable_debug_mode(void)
{
    g_debug_mode = MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_disable_debug_mode
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_frm_gesture_disable_debug_mode(void)
{
    g_debug_mode = MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_get_statistics
* DESCRIPTION
*  Statistics the info of gesture.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_gesture_get_statistics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_gesture_framework_p->gesture_info.points_sequence_count - 1; i++)
    {
        g_gesture_framework_p->gesture_info.vectors_sequence[i] =
            mmi_frm_gesture_calculate_direction(g_gesture_framework_p->gesture_info.points_sequence[i + 1],
                                        g_gesture_framework_p->gesture_info.points_sequence[i]);
        mmi_frm_gesture_print_info(i);

        if (i >= 2)
        {
            /* Calculate change time of direction */
            if (g_gesture_framework_p->gesture_info.vectors_sequence[i] != 
                g_gesture_framework_p->gesture_info.vectors_sequence[i - 1])
            {
                g_gesture_framework_p->gesture_info.gesture_statistics.direction_change += 1;
            }
            mmi_frm_gesture_calculate_clockwise(i);
        }

        if (i >= 3)
        {
            mmi_frm_gesture_calculate_inflexion(i);
        }
    }

    for (i = 0; i < MMI_FRM_DIRECTIONS_NUM; i++)
    {
        g_gesture_framework_p->gesture_info.gesture_statistics.direction[i] = 
            g_gesture_framework_p->gesture_info.distances.direction[i] / g_gesture_framework_p->gesture_info.distances.total;

        if ((i%2) == 0)
        {
            g_gesture_framework_p->gesture_info.gesture_statistics.square
                += g_gesture_framework_p->gesture_info.gesture_statistics.direction[i];
        }
        else
        {
            g_gesture_framework_p->gesture_info.gesture_statistics.diagonal
                += g_gesture_framework_p->gesture_info.gesture_statistics.direction[i];
        }
    }

    g_gesture_framework_p->gesture_info.gesture_statistics.direction_change = 
        g_gesture_framework_p->gesture_info.gesture_statistics.direction_change / 
        (g_gesture_framework_p->gesture_info.points_sequence_count - 1);

    g_gesture_framework_p->gesture_info.gesture_statistics.start_end_proximity
        = mmi_frm_gesture_calculate_distance(g_gesture_framework_p->gesture_info.points_sequence[0], MMI_FRM_GESTURE_PRE_POS);

}


/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_calculate_distance
* DESCRIPTION
*  Calculates the distance between two points.
* PARAMETERS
*  point_1   [IN] the position of point 1;
*  point_2   [IN] the position of point 2;
* RETURNS
*  the distance between two points.
*****************************************************************************/
static double mmi_frm_gesture_calculate_distance(mmi_pen_point_struct point_1, mmi_pen_point_struct point_2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sqrt((point_1.x - point_2.x)*(point_1.x - point_2.x) 
                + (point_1.y - point_2.y)*(point_1.y - point_2.y));
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_calculate_clockwise
* DESCRIPTION
*  Calculates the number of inflexion
* PARAMETERS
*  index     [IN] the index of point sequence. 
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_gesture_calculate_clockwise(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    S32 d = g_gesture_framework_p->gesture_info.vectors_sequence[index] - g_gesture_framework_p->gesture_info.vectors_sequence[index - 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_gesture_framework_p->gesture_info.gesture_statistics.circle != NON_CIRCLE) && (d))
    {
        /* clockwise */
        if (MMI_FRM_GESTRUE_BELONG_TO_CIRCLE_DIRECTION(d))
        {
            g_gesture_framework_p->gesture_info.gesture_statistics.clockwise += 1;
        }
        /* anticlockwise */
        else if (MMI_FRM_GESTRUE_BELONG_TO_CIRCLE_DIRECTION((-1) * d))
        {
             g_gesture_framework_p->gesture_info.gesture_statistics.anticlockwise += 1;
        }
        else
        {
             g_gesture_framework_p->gesture_info.gesture_statistics.circle = NON_CIRCLE;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_calculate_inflexion
* DESCRIPTION
*  Calculates the number of inflexion
* PARAMETERS
*  index     [IN] the index of point sequence. 
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_gesture_calculate_inflexion(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((ABS(g_gesture_framework_p->gesture_info.vectors_sequence[index - 2] - g_gesture_framework_p->gesture_info.vectors_sequence[index]) 
         > ABS(MMI_FRM_DIRECTIONS_NEIGHBOUR)) &&
        (ABS(g_gesture_framework_p->gesture_info.vectors_sequence[index - 2] - g_gesture_framework_p->gesture_info.vectors_sequence[index]) 
         < ABS(MMI_FRM_DIRECTIONS_CYCLE_NEIGHBOUR)))
    {
        g_gesture_framework_p->gesture_info.gesture_statistics.inflexion++;        
    }       
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_calculate_direction
* DESCRIPTION
*  Returns the direction based on the gradient's angle.
* PARAMETERS
*  cur_pos    [IN] the point to the current position.
*  pre_pos    [IN] the point to the previous position.
* RETURNS 
*  return the direction.
*****************************************************************************/
static mmi_frm_strokes_enum mmi_frm_gesture_calculate_direction(mmi_pen_point_struct cur_pos,  mmi_pen_point_struct pre_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x_dif, y_dif;
    double xy_ratio, d;
    mmi_frm_strokes_enum result = MMI_FRM_STROKES_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x_dif = cur_pos.x - pre_pos.x;
    y_dif = cur_pos.y - pre_pos.y;

    if ( y_dif != 0 )
    {
        xy_ratio = ABS((double)x_dif/y_dif);
    }
    else 
    {
        xy_ratio = 1.0e300;
    }   

    d = sqrt((double)(x_dif*x_dif + y_dif*y_dif));
    
    if (xy_ratio >= MMI_FRM_DIAGONAL_XY_RATIO_LOWER_THRESHOLD && 
        xy_ratio <= MMI_FRM_DIAGONAL_XY_RATIO_UPPER_THRESHOLD)
    {
        if (x_dif >= 0 && y_dif >= 0)
        {           
            result = MMI_FRM_STROKES_DOWN_RIGHT;
        }
        else if (x_dif >= 0 && y_dif < 0)
        {            
            result = MMI_FRM_STROKES_UP_RIGHT;
        }
        else if (x_dif < 0 && y_dif >= 0)
        {
            result = MMI_FRM_STROKES_DOWN_LEFT;
        }
        else if (x_dif < 0 && y_dif < 0)
        {            
            result = MMI_FRM_STROKES_UP_LEFT;
        }
    }
    else
    {
            
        if(ABS(x_dif) >= ABS(y_dif))
        {
            if (x_dif > 0)
            {                
                result = MMI_FRM_STROKES_RIGHT;
            }
            else
            {                
                result = MMI_FRM_STROKES_LEFT;
            }
        }
        else
        {
            if(y_dif > 0) 
            {                
                result = MMI_FRM_STROKES_DOWN;
            }
            else
            {                
                result = MMI_FRM_STROKES_UP;
            }                
        }         
    }


    g_gesture_framework_p->gesture_info.distances.direction[result] += d;

    g_gesture_framework_p->gesture_info.distances.total += d;

    return result;
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_parser
* DESCRIPTION
*  Parses a gesture containing a description.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_gesture_parser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i <g_gesture_framework_p->gesture_hdlr_count; i++)
    {
        if (mmi_frm_gesture_is_match((mmi_frm_strokes_enum *) mmi_frm_gesture_array[g_gesture_framework_p->gesture_hdlr_array[i].gesture_event].strokes))
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_TRC_GESTURE_ACCEPT, g_gesture_framework_p->gesture_hdlr_array[i].gesture_event);
            g_gesture_framework_p->gesture_hdlr_array[i].gesture_hdlr(g_gesture_framework_p->gesture_hdlr_array[i].gesture_event);
            return;
        }
    }
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_TRC_GESTURE_REJECT);
    
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_is_match
* DESCRIPTION
*  Tests if user inputed gesture matches the gesture pattern.
* PARAMETERS
*  pattern  [IN]  the gesture pattern.
* RETURNS
*  Returns MMI_TRUE if there is a match. Otherwise MMI_FALSE.  
*****************************************************************************/
static MMI_BOOL mmi_frm_gesture_is_match(const mmi_frm_strokes_enum *pattern)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_FRM_STROKES_CLOCKWISE == pattern[0])
        || (MMI_FRM_STROKES_ANTICLOCKWISE == pattern[0]))
    {
        return mmi_frm_gesture_is_match_circle(pattern[0]);
    }
    else if (MMI_FRM_STROKES_SEMICIRCLE_UP <= pattern[0] &&
		pattern[0] <= MMI_FRM_STROKES_SEMICIRCLE_RIGHT)
    {/* Semicircle pattern */
        return mmi_frm_gesture_is_match_semicircle(pattern[0]);
    }
    
    if (MMI_FRM_STROKES_END == pattern[1])
    {
        return mmi_frm_gesture_is_match_straight(pattern[0]);
    }
    return mmi_frm_gesture_is_match_broken_line(pattern);
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_is_match_semicircle
* DESCRIPTION
*  Tests if user inputed gesture matches the semicircle pattern.
* PARAMETERS
*  pattern  [IN]  the gesture pattern.
* RETURNS
*  Returns MMI_TRUE if there is a match. Otherwise MMI_FALSE. 
*****************************************************************************/
static MMI_BOOL mmi_frm_gesture_is_match_semicircle(mmi_frm_strokes_enum pattern)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DOUBLE circle_total, radius, diameter, start_end_distance;
    mmi_pen_point_struct start_point, mid_point, end_point;
    mmi_frm_strokes_enum semicircle_type = MMI_FRM_STROKES_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    circle_total = g_gesture_framework_p->gesture_info.gesture_statistics.anticlockwise + g_gesture_framework_p->gesture_info.gesture_statistics.clockwise;
    g_gesture_framework_p->gesture_info.gesture_statistics.anticlockwise = g_gesture_framework_p->gesture_info.gesture_statistics.anticlockwise / circle_total;
    g_gesture_framework_p->gesture_info.gesture_statistics.clockwise = g_gesture_framework_p->gesture_info.gesture_statistics.clockwise / circle_total;

    start_end_distance = g_gesture_framework_p->gesture_info.gesture_statistics.start_end_proximity;

    #ifdef DEBUG_GESTURE
        kal_print("Condition Level-1, anticlockwise:%f, clockwise:%f\n",
            g_gesture_framework_p->gesture_info.gesture_statistics.anticlockwise,
            g_gesture_framework_p->gesture_info.gesture_statistics.clockwise);
    #endif /* DEBUG_GESTURE */

    if ((g_gesture_framework_p->gesture_info.gesture_statistics.anticlockwise > MMI_FRM_SEMICIRCLE_BELONG_TO_CIRCLE ||
        g_gesture_framework_p->gesture_info.gesture_statistics.clockwise > MMI_FRM_SEMICIRCLE_BELONG_TO_CIRCLE) &&
        start_end_distance > MMI_FRM_CIRCLE_START_END_PROXIMITY_THRESHOLD)
    {/* Belong to a circle shape but not a closed circle */
        radius = g_gesture_framework_p->gesture_info.distances.total / (double)3.14159;
        diameter = 2 * radius;

    #ifdef DEBUG_GESTURE
        kal_print("Condition Level-2, start_end_distance:%f, radius:%f, diameter:%f, proportion:%f\n",
            start_end_distance, radius, diameter,
            ((DOUBLE)ABS(start_end_distance - diameter) / diameter));
    #endif /* DEBUG_GESTURE */
        /* start_end_proximity should be close to diameter */
        if (start_end_distance > radius &&
            (((DOUBLE)ABS(start_end_distance - diameter) / diameter) < MMI_FRM_SEMICIRCLE_DISTANCE_THRESHOLD))
        {/* Belong to a semicircle shape */
            start_point = g_gesture_framework_p->gesture_info.points_sequence[0];
            end_point = MMI_FRM_GESTURE_PRE_POS;
            mid_point = g_gesture_framework_p->gesture_info.points_sequence[g_gesture_framework_p->gesture_info.points_sequence_count / 2];

    #ifdef DEBUG_GESTURE
        {
            double x_distance, proportion_start_mid, proportion_end_mid;
            x_distance = ABS(start_point.x - end_point.x);
            proportion_start_mid = (DOUBLE)(ABS(ABS(start_point.x - mid_point.x) - radius)) / radius;
            proportion_end_mid = (DOUBLE)(fabs(fabs(end_point.x - mid_point.x) - radius)) / radius;
            kal_print("Condition Level-3-1, x_distance:%f, proportion_start_mid:%f, proportion_end_mid:%f\n",
                x_distance, proportion_start_mid, proportion_end_mid);
        }
    #endif /* DEBUG_GESTURE */
            /* Check arc direction left and right */
            if ((ABS(start_point.x - end_point.x) <= MMI_FRM_SEMICIRCLE_POINT_COORDINATES_DIFF) &&
                ((DOUBLE)ABS(ABS(start_point.x - mid_point.x) - radius) / radius < MMI_FRM_SEMICIRCLE_DISTANCE_THRESHOLD) &&
                ((DOUBLE)ABS(ABS(end_point.x - mid_point.x) - radius) / radius < MMI_FRM_SEMICIRCLE_DISTANCE_THRESHOLD))
            {/* Coordinates condition of three points - start, end, middle */
                if (mid_point.x < start_point.x && mid_point.x < end_point.x)
                {
                    semicircle_type = MMI_FRM_STROKES_SEMICIRCLE_LEFT;
                }
                else if (mid_point.x > start_point.x && mid_point.x > end_point.x)
                {
                    semicircle_type = MMI_FRM_STROKES_SEMICIRCLE_RIGHT;
                }
                else
                {/* Drop other cases */
                }
            }
    #ifdef DEBUG_GESTURE
        {
            double y_distance, proportion_start_mid, proportion_end_mid;
            y_distance = ABS(start_point.y - end_point.y);
            proportion_start_mid = (DOUBLE)ABS(ABS(start_point.y - mid_point.y) - radius) / radius;
            proportion_end_mid = (DOUBLE)ABS(ABS(end_point.y - mid_point.y) - radius) / radius;
            kal_print("Condition Level-3-2, y_distance:%f, proportion_start_mid:%f, proportion_end_mid:%f\n",
                y_distance, proportion_start_mid, proportion_end_mid);
        }
    #endif /* DEBUG_GESTURE */
            /* Check arc direction up and down */
            if ((ABS(start_point.y - end_point.y) <= MMI_FRM_SEMICIRCLE_POINT_COORDINATES_DIFF) &&
                    ((DOUBLE)ABS(ABS(start_point.y - mid_point.y) - radius) / radius < MMI_FRM_SEMICIRCLE_DISTANCE_THRESHOLD) &&
                    ((DOUBLE)ABS(ABS(end_point.y - mid_point.y) - radius) / radius < MMI_FRM_SEMICIRCLE_DISTANCE_THRESHOLD))
            {
                if (mid_point.y < start_point.y && mid_point.y < end_point.y)
                {
                    semicircle_type = MMI_FRM_STROKES_SEMICIRCLE_UP;
                }
                else if (mid_point.y > start_point.y && mid_point.y > end_point.y)
                {
                    semicircle_type = MMI_FRM_STROKES_SEMICIRCLE_DOWN;
                }
                else
                {/* Drop other cases */
                }
            }
        }
    }

    if ((pattern ==  semicircle_type) &&
        (g_gesture_framework_p->gesture_info.gesture_statistics.diagonal > MMI_FRM_CIRCLE_DIAGONAL_THRESHOLD) &&
        (g_gesture_framework_p->gesture_info.gesture_statistics.square > MMI_FRM_CIRCLE_SQUARE_THRESHOLD) &&
        (g_gesture_framework_p->gesture_info.gesture_statistics.direction_change > MMI_FRM_CIRCLE_DIRECTION_CHANGE_THRESHOLD))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_is_match_circle
* DESCRIPTION
*  Tests if user inputed gesture matches the circle pattern.
* PARAMETERS
*  pattern  [IN]  the gesture pattern.
* RETURNS
*  Returns MMI_TRUE if there is a match. Otherwise MMI_FALSE. 
*****************************************************************************/
static MMI_BOOL mmi_frm_gesture_is_match_circle(mmi_frm_strokes_enum pattern)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    double t;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_gesture_framework_p->gesture_info.gesture_statistics.circle == UNKNOWN_CIRCLE)
    {
        t = g_gesture_framework_p->gesture_info.gesture_statistics.anticlockwise + g_gesture_framework_p->gesture_info.gesture_statistics.clockwise;
        g_gesture_framework_p->gesture_info.gesture_statistics.anticlockwise = g_gesture_framework_p->gesture_info.gesture_statistics.anticlockwise/t;
        g_gesture_framework_p->gesture_info.gesture_statistics.clockwise = g_gesture_framework_p->gesture_info.gesture_statistics.clockwise/t;

        if (g_gesture_framework_p->gesture_info.gesture_statistics.anticlockwise > 0.9)
        {
            g_gesture_framework_p->gesture_info.gesture_statistics.circle = ANTICLOCKWISE_CIRCLE;
        }
        else if (g_gesture_framework_p->gesture_info.gesture_statistics.clockwise > 0.9)
        {
            g_gesture_framework_p->gesture_info.gesture_statistics.circle = CLOCKWISE_CIRCLE;
        }
    }
    
    if ((pattern ==  g_gesture_framework_p->gesture_info.gesture_statistics.circle) &&
        (g_gesture_framework_p->gesture_info.gesture_statistics.diagonal > MMI_FRM_CIRCLE_DIAGONAL_THRESHOLD) &&
        (g_gesture_framework_p->gesture_info.gesture_statistics.square > MMI_FRM_CIRCLE_SQUARE_THRESHOLD) &&
        (g_gesture_framework_p->gesture_info.gesture_statistics.start_end_proximity < MMI_FRM_CIRCLE_START_END_PROXIMITY_DISTANCE) &&
        g_gesture_framework_p->gesture_info.gesture_statistics.direction_change > MMI_FRM_CIRCLE_DIRECTION_CHANGE_THRESHOLD)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}
  

/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_is_match_straight
* DESCRIPTION
*  Tests if user inputed gesture matches the straight line pattern.
* PARAMETERS
*  pattern  [IN]  the gesture pattern.
* RETURNS
*  Returns MMI_TRUE if there is a match. Otherwise MMI_FALSE. 
*****************************************************************************/
static MMI_BOOL mmi_frm_gesture_is_match_straight(mmi_frm_strokes_enum pattern)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((g_gesture_framework_p->gesture_info.gesture_statistics.direction[pattern] > MMI_FRM_DIRECTIONS_UPPER_THRESHOLD) ||
        ((g_gesture_framework_p->gesture_info.gesture_statistics.direction[pattern] > MMI_FRM_DIRECTIONS_LOWER_THRESHOLD) 
          && (0 == g_gesture_framework_p->gesture_info.gesture_statistics.inflexion)))
		  && (g_gesture_framework_p->gesture_info.distances.total >= MMI_FRM_MIN_DISTANCE))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_gesture_is_match_straight
* DESCRIPTION
*  Tests if user inputed gesture matches the broken line pattern.
* PARAMETERS
*  pattern  [IN]  the gesture pattern.
* RETURNS
*  Returns MMI_TRUE if there is a match. Otherwise MMI_FALSE. 
*****************************************************************************/
static MMI_BOOL mmi_frm_gesture_is_match_broken_line(const mmi_frm_strokes_enum *pattern)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, m = 0;
    double pattern_statistics[MMI_FRM_DIRECTIONS_NUM] = {0}; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_gesture_framework_p->gesture_info.points_sequence_count - 1; i++)
    {
        if (ABS(pattern[m] - g_gesture_framework_p->gesture_info.vectors_sequence[i]) <= 1 || ABS(pattern[m] - g_gesture_framework_p->gesture_info.vectors_sequence[i]) == 7 )
        {
            if ((ABS(pattern[m+1] - g_gesture_framework_p->gesture_info.vectors_sequence[i+1]) <= ABS(MMI_FRM_DIRECTIONS_NEIGHBOUR) 
                 || ABS(pattern[m+1] - g_gesture_framework_p->gesture_info.vectors_sequence[i+1]) == ABS(MMI_FRM_DIRECTIONS_CYCLE_NEIGHBOUR)))
            {               
                m++;                                                
            }            
        }
        else
        {
            return MMI_FALSE;
        }
    }

    if (pattern[m+1] != MMI_FRM_STROKES_END)
    {
        return MMI_FALSE;
    }

    m = 0;
        
    while (pattern[m] != MMI_FRM_STROKES_END)
    {          
        pattern_statistics[pattern[m]]++; 
        m++;
    }

    for (i = 0; i < MMI_FRM_DIRECTIONS_NUM; i++)
    {
        if (pattern_statistics[i] != 0)
        {
            pattern_statistics[i] = pattern_statistics[i]/m;

            if (g_gesture_framework_p->gesture_info.gesture_statistics.direction[i] 
                < (pattern_statistics[i]* MMI_FRM_DIRECTIONS_PROPORTION_WEIGHT) )
            {
                return MMI_FALSE;
            }
        }
    }  

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_gestures_draw_track
* DESCRIPTION
*  Draws the user inputed gesture track.
* PARAMETERS
*  coordinate  [IN] the coordinates of the drawing area.
*  line_color  [IN] the color of track line.
* RETURNS
*  void
*****************************************************************************/
void mmi_frm_gestures_draw_track(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_gesture_framework_p)
    {
        return;
    }

    gui_lock_double_buffer();
    RedrawCategoryFunction();

    gui_push_clip();

    gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);
   
    for(i = 1; i < g_gesture_framework_p->gesture_info.points_sequence_count; i++)
    {
        gdi_draw_line(g_gesture_framework_p->gesture_info.points_sequence[i - 1].x,
                      g_gesture_framework_p->gesture_info.points_sequence[i - 1].y, 
                      g_gesture_framework_p->gesture_info.points_sequence[i].x,
                      g_gesture_framework_p->gesture_info.points_sequence[i].y, GDI_COLOR_WHITE);
     }

    gui_pop_clip();
    
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
    
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_gestures_draw_track
* DESCRIPTION
*  Prints the basic info of user inputed gesture.
* PARAMETERS
*  index     [IN] the index of point sequence.  
* RETURNS
*  void
*****************************************************************************/
static void mmi_frm_gesture_print_info(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_TRC_GESTURE_INFO, index,                  
              g_gesture_framework_p->gesture_info.vectors_sequence[index],
              g_gesture_framework_p->gesture_info.points_sequence[index].x,
              g_gesture_framework_p->gesture_info.points_sequence[index].y,
              g_gesture_framework_p->gesture_info.points_sequence[index+1].x,
              g_gesture_framework_p->gesture_info.points_sequence[index+1].y);
}
//#define __MMI_FRM_GESTURE_UT__

#if defined(__MMI_FRM_GESTURE_UT__)

#define AS(a) sizeof(a)/sizeof(a[0])
/* unit test function */
typedef mmi_ret (*unit_test_func)(void *para);

/* unit test struct */
typedef struct
{
    U8 index;
    unit_test_func test;
} mmi_unit_test_struct;

#define GES_UT (sizeof(g_ts_ut)/sizeof(g_ts_ut[0]))

typedef struct
{
    mmi_frm_gesture_rect_struct rect;
    const mmi_pen_point_struct *point_seq;// end with (-1, -1)
    mmi_frm_gesture_event_enum expected_gesture;
} gesture_test_data;

const mmi_pen_point_struct gesture_right1[] = {1, 100, 10, 100, 20, 100, 30, 100, 50, 100, 90, 100, 150, 100, 201, 100, -1, -1};
const mmi_pen_point_struct gesture_right2[] = {1, 100, 10, 100, 20, 100, 30, 100, 50, 100, 90, 100, 150, 100, 201, 100, -1, -1};
const mmi_pen_point_struct gesture_right3[] = {1, 100, 10, 100, 20, 100, 30, 100, 50, 100, 90, 100, 150, 100, 190, 100, -1, -1};
const mmi_pen_point_struct gesture_left1[] =  {201, 100, 150, 100, 90, 100, 50, 100, 30, 100, 20, 100, 10, 100, 1, 100, -1, -1};
const mmi_pen_point_struct gesture_left2[] =  {190, 100, 150, 100, 90, 100, 50, 100, 30, 100, 20, 100, 10, 100, 1, 100, -1, -1};
const mmi_pen_point_struct gesture_up1[] = {100, 370, 100, 330, 100, 280, 100, 250, 100, 200, 100, 150, 100, 100, 100, 50, -1, -1};
const mmi_pen_point_struct gesture_up2[] = {100, 370, 100, 330, 9, 280, 100, 250, 100, 200, 100, 150, 100, 100, 100, 50, -1, -1};
const mmi_pen_point_struct gesture_up3[] = {100, 370, 100, 330, 100, 280, 96, 250, 100, 200, 105, 150, 100, 100, 99, 50, -1, -1};
static gesture_test_data _gesture_test_data[] =
{
    {
        {0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT},
        gesture_right1,
        MMI_FRM_GESTURE_RIGHT
    },
    {
        {0, 0, 200, UI_DEVICE_HEIGHT},
        gesture_right2,
        MMI_FRM_GESTURE_MAX    
    },
    {
        {0, 0, 200, UI_DEVICE_HEIGHT},
            gesture_right3,
        MMI_FRM_GESTURE_RIGHT  
    },
    {
        {0, 0, 200, UI_DEVICE_HEIGHT},
            gesture_left1,
        MMI_FRM_GESTURE_MAX  
    },
    {
        {0, 0, 200, UI_DEVICE_HEIGHT},
            gesture_left2,
            MMI_FRM_GESTURE_LEFT  
    },
    {
        {10, 10, 200, 380},
            gesture_up1,
            MMI_FRM_GESTURE_UP            
    },
    {
        {10, 10, 200, 380},
            gesture_up2,
            MMI_FRM_GESTURE_MAX            
    },
    {
        {10, 10, 200, 380},
            gesture_up3,
        MMI_FRM_GESTURE_UP     
    }
};

static mmi_frm_gesture_event_enum g_curr_gesture = MMI_FRM_GESTURE_MAX;
void gesture_common_handler(mmi_frm_gesture_event_enum ges)
{
    g_curr_gesture = ges;
}

mmi_ret gesture_within_rect_test(void *para)
{
    S32 i;
    S32 j;
    mmi_pen_event_type_enum event;

    
    for (i = 0; i < AS(_gesture_test_data); i++)
    {
        mmi_frm_gesture_listen_event_ex(
           _gesture_test_data[i].expected_gesture, gesture_common_handler, &_gesture_test_data[i].rect);
        g_curr_gesture = MMI_FRM_GESTURE_MAX;
        j = 0;
        while (_gesture_test_data[i].point_seq &&
            (_gesture_test_data[i].point_seq[j].x != -1) &&
            (_gesture_test_data[i].point_seq[j].y != -1))
        {
            if (j == 0)
            {
                event = MMI_PEN_EVENT_DOWN;
            }
            else
            {
                if ((_gesture_test_data[i].point_seq[j + 1].x == -1) &&
                    (_gesture_test_data[i].point_seq[j + 1].y == -1))
                {
                    event = MMI_PEN_EVENT_UP;
                }
                else
                {
                    event = MMI_PEN_EVENT_MOVE;
                }
            }
            mmi_frm_gesture_recognise(event, _gesture_test_data[i].point_seq[j]);       
            j++;
        }
        MMI_ASSERT(g_curr_gesture == _gesture_test_data[i].expected_gesture);
        
    }
    mmi_frm_gesture_stop_listen_event();
    kal_prompt_trace(MOD_MMI, "[UT_GESTURE] gesture within a rect test PASS!!!");
    return MMI_RET_OK;
}

const static mmi_unit_test_struct g_ts_ut[] =
{
    {1, gesture_within_rect_test}     
};
void mmi_frm_gesture_ut(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (index == 0)
    {
        for (i = 0; i < GES_UT; i++)
        {
            g_ts_ut[i].test(NULL);
        }
    }
    else
    {
        for (i = 0; i < GES_UT; i++)
        {
            if (g_ts_ut[i].index == index)
            {
                g_ts_ut[i].test(NULL);
            }
        }
    }
}

#endif

#endif /*#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)*/  


