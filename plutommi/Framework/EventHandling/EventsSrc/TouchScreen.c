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
 *   TouchScreen.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Low-level Touch Screen API - interface between driver or PC simulator
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#ifdef __MMI_TOUCH_SCREEN__

/***************************************************************************** 
* Include
*****************************************************************************/
#ifdef __MMI_TOUCH_PANEL_SHORTCUT__
#include "touch_panel_shortcut_custom.h"
#endif /* __MMI_TOUCH_PANEL_SHORTCUT__ */

#include "mmi_frm_prot.h"
#include "gui.h"
#include "BootupSrvGprot.h"
#include "mmi_frm_gestures.h"
#if defined(__MMI_AVRCP_SUPPORT__)
#include "BTMMIAVRCPGprot.h"
#include "AvrcpSrvGprot.h"
#endif /* defined(__MMI_AVRCP_SUPPORT__) */

#include "gui_data_types.h"
#include "gui.h"
#include "Touch_Panel.h"
#include "Drv_Comm.h"   /*  mmi_pen_touch_panel_sendilm() */
#include "gdi_include.h"
#include "ProfilingEngine.h"
#include "ScreenRotationGprot.h"

#include "MMIDataType.h"
#include "mmi_frm_input_gprot.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "string.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_fw_trc.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "mmi_frm_input.h"
#include "stack_msgs.h"
#include "mmi_frm_gestures_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "kal_internal_api.h"
#include "NotificationGprot.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "stack_common.h"
#include "stack_ltlcom.h"
#include "bt_a2dp_base_struct.h"
#include "mmi_fw_trc.h"
#include "dcl.h"
#include "GlobalResDef.h"
#include "lcd_sw_inc.h"
#if defined(__MMI_VUI_ENGINE__)
#include "vadp_p2v_uc.h"
#endif
#include "GpioSrvGprot.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#define MMI_PEN_LOOKAHEAD_BUFFER_SIZE     (25)
#define MAX_FINGER_EVENT_IN_QUEUE 20
#define MERGE_MAX_POINTS 5

typedef struct
{
    U16 x_adc;
    U16 y_adc;
    U16 z;
    DCL_TP_Event_enum event;
    U32   time_stamp;		
} mmi_pen_event_struct;

#if defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)
/* mode + (x, y, z, event) * finger number + time stamp */
#define QUEUE_SIZE  ((2+4+(2+2+2+2) * MMI_FRM_MULTI_TOUCH_MAX_FINGER) * MAX_FINGER_EVENT_IN_QUEUE)
#else
/* mmi_pen_event_struct: x, y, event, time*/
#define QUEUE_SIZE  (sizeof(mmi_pen_event_struct) * MMI_PEN_LOOKAHEAD_BUFFER_SIZE) 
#endif

/* Pen polling handler period, unit: ms */
#define MMI_PEN_POLLING_PERIOD            (3 * 10)


/* 
 * Delayed polling period time. (We allow only 5 Pen Down event per sec) 
 * We restrict the frequency of incoming Pen Down events in MMI framework instead of 
 * driver debounce time because driver debounce time needs to be smaller than sampling period. 
 */
#define MMI_PEN_DEBOUNCE_POLLING_DELAY    (1000 / 5 - MMI_PEN_POLLING_PERIOD)

#define MMI_PENDING_MSG_THRESHOLD         (3)
#define MMI_PEN_MAX_HANDWRITING_REGION    (3)
#define MMI_PENDING_MSG_THRESHOLD         (3)
#define MMI_PEN_STROKE_MAX_OFFSET   (0x7FFF)

#ifndef __MTK_TARGET__
#define MMI_PEN_MODIS_QUEUE_SIZE 1024
#endif


/* Common finger touch range (0.137 inch) */
#if (defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)) && defined(__MTK_TARGET__)

#define MMI_FRM_FINGER_MAX_WIDTH     (UI_DEVICE_WIDTH / 16)
#define MMI_FRM_TOUCH_FINGER_WIDTH    ((137 * LCM_DPI / 1000) > MMI_FRM_FINGER_MAX_WIDTH ? MMI_FRM_FINGER_MAX_WIDTH : (137 * LCM_DPI / 1000))
#else
#define MMI_FRM_FINGER_MAX_WIDTH     (0)
#define MMI_FRM_TOUCH_FINGER_WIDTH   (0)
#endif
/***************************************************************************** 
* Typedef
*****************************************************************************/
/* AT Command CTSA ation type */
typedef enum
{
    MMI_PEN_AT_UP,
    MMI_PEN_AT_DOWN,
    MMI_PEN_AT_SINGLETAP,
    MMI_PEN_AT_DOUBLETAP
} mmi_pen_at_ctsa_action;

/* AT Command CTSA response type */
typedef enum
{
    MMI_PEN_CTSA_OK = 0,
    MMI_PEN_CTSA_NOT_MOVE = -1,
    MMI_PEN_CTSA_INVALID = -2,
    MMI_PEN_CTSA_LOOKAHEAD_FULL = -3,
    MMI_PEN_CTSA_NOT_ENTRY_AT_MODE = -4
} mmi_pen_at_ctsa_rsp_type;

/* AT command send touch event report */
typedef enum
{
    MMI_PEN_REPORT_NONE = 0,
    MMI_PEN_REPORT_TARGET,
    MMI_PEN_REPORT_ALL,
    MMI_PEN_REPORT_TARGET_VERBOSE
} mmi_pen_at_send_touch_report;


typedef struct
{
    U32 read;
    U32 write;
    U16* queue;
} touch_queue_struct;


/* 
 * multi-Touch proc 
 * [proc function + user data]
 */
typedef struct
{
    mmi_proc_func touch_proc;     /*  proc function */
    void *user_data;            /* user data */
} mmi_touch_proc_struct;

/* AT command and Modis simulate driver context */
typedef struct
{
    /* If has pen down event before */
    U32 is_pen_down:1;

    /* If it's in stroke event now */
    U32 is_stroke_created:1;

    /* wait for 1: pen long-tap 0: pen repeat (event-based) */
    U32 is_waiting_long_tap_event:1;

    /* if it's AT command mode */
    U32 is_AT_command: 1;

    /* If pen abort happen, we should filter modis mouse event */
    U32 is_abort_happen: 1;
    /* stroke down index */
    U32 stroke_down_block_index;    

    /* The position where pen is tapped down */
    mmi_pen_point_struct pen_pre_down_pos;

    /* If enable extend area. */
    MMI_BOOL ext_enable;   
} mmi_pen_simulate_driver_context_struct;


typedef struct
{
    /* mmi_pen_block() & mmi_pen_unblock() */
    U8 is_blocked;

    /* mmi_pen_enable() & mmi_pen_disable() */
    U8 is_enabled;

    /* After DCL_PEN_DOWN, mmi_pen_reset() set 'is_pen_down' to 0 */
    U8 is_pen_down;

    /* To know if it's in the pen handler procedure */
    U8 is_in_pen_handler;

    /* Debug only. After DCL_STROKE_DOWN, mmi_pen_reset() set 'is_stroke_down' to 0 */
    U8 is_stroke_down;

    /* Pen down in hand-writing area, but we still do not know if it is a stroke */
    U8 is_pending_stroke_event;

    /* this value is true when needs to send event to new screen */
    U8 is_send_event_to_new_screen;

	U8 is_sw_pen_down;
    /* 
     * Set by mmi_pen_change_handwriting_area() and mmi_pen_stop_capture_strokes().
     * Close stroke and reset touch screen when pen is up. 
     */
    U8 reset_stroke_on_pen_up;

    /* to judge the driver event state */    
    U8 is_driver_down;
    	
    U8 has_pen_move;

    /* touch screen mode */
    mmi_frm_touch_mode touch_mode;

    /* To know what pen event is handling */
    DCL_TP_Event_enum pen_event;

    /* The time stamp of previous pen down event */
    U32 previous_pen_down_time;

    /* Pen down position */
    mmi_touch_pos_struct pen_down_pos;

    /* The current pen position */
    mmi_pen_point_struct pen_current_pos;

    MMI_TOUCH_ID new_id;

    /* Block index of handwriting area */
    S32 stroke_down_block_index;

    /* For stroke */
    S32 num_points_queued;

} mmi_pen_context_struct;


/* keep the information of each finger, send this information to application */
typedef struct
{
    mmi_pen_event_type_enum pre_event;
    mmi_touch_pos_struct pre_touch_pos;
    mmi_touch_pos_struct touch_down_info;
    MMI_TOUCH_ID id;
} mmi_frm_finger_info_struct;
	

/***************************************************************************** 
* Local Variable
*****************************************************************************/
#ifndef __MTK_TARGET__
static volatile int g_mmi_pen_MODIS_qread;   /* modified by MMI thread */
static volatile int g_mmi_pen_MODIS_qwrite;  /* modified by windows message loop thread */
static mmi_pen_event_struct g_mmi_pen_MODIS_ring_buffer[MMI_PEN_MODIS_QUEUE_SIZE];
static MMI_BOOL g_mmi_pen_MODIS_start_timer = MMI_FALSE;
#endif

typedef void (*pen_enqueue_callback)(mmi_pen_event_struct *event);
//add compile option
static mmi_multi_touch_event_struct g_multi_touch_event;

#if defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)
static mmi_touch_pos_struct g_multi_touch_merge_array[MMI_FRM_MULTI_TOUCH_MAX_FINGER][MERGE_MAX_POINTS + 1];
static U16 g_merge_pressure[MMI_FRM_MULTI_TOUCH_MAX_FINGER][MERGE_MAX_POINTS + 1];
#endif

static mmi_touch_proc_struct g_mmi_frm_touch_proc;

static U16 multi_touch_queue[QUEUE_SIZE]; //20 points, delete lookahead buffer

static touch_queue_struct g_frm_touch_queue;


static mmi_frm_finger_info_struct g_frm_finger_info[MMI_FRM_MULTI_TOUCH_MAX_FINGER];


#if defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)
static mmi_pen_event_struct g_pre_event[MMI_FRM_MULTI_TOUCH_MAX_FINGER];
#endif

/* HAL Pen device handler */
static DCL_HANDLE g_pen_drv_handle;

/* Global pen context that is reset in mmi_pen_reset() and mmi_pen_disable() */
static mmi_pen_context_struct g_pen_cntx;

/* Only normal power on initialize touch screen. Otherwise, touch screen is not initialized */
static MMI_BOOL g_pen_initialized;

/* Whether MSG_ID_TP_EVENT_IND is already en-queued in MMI external queue */
/* It is not put inside g_pen_cntx for similar reason like g_pen_polling_timer_started */
U32 g_pen_is_driver_indication_in_queue;

static mmi_pen_hdlr g_pen_event_table[MMI_PEN_EVENT_TYPE_MAX];
static mmi_pen_hdlr g_pen_stroke_table[MMI_PEN_STROKE_TYPE_MAX];
static S32 g_pen_stroke_max_points;
static mmi_pen_point_struct *g_pen_stroke_points;
/* For AT command, MOD_L4C or MOD_L4C_2 */
static module_type g_scr_mod = MOD_L4C;

/* Used for the new multi-block feature.
   Note: the data can be put into driver, but we do not want to change driver interface 
   because customers may port their driver */
static mmi_pen_handwriting_area_struct g_pen_stroke_areas[HAND_WRITING_AREA_NUM];
static S32 g_pen_num_stroke_area;
static mmi_pen_handwriting_area_struct g_pen_ext_stroke_area;
/* Minimum square distance (diff_x^2 + diff_y^2)  */
static S16 g_pen_stroke_min_offset_square;
//static mmi_pen_event_struct g_pen_lookahead_buffer[MMI_PEN_LOOKAHEAD_BUFFER_SIZE];
static MMI_BOOL g_pen_drvq_full_abort;
static mmi_pen_abort_type_enum g_pen_abort_type;
static kal_uint8 g_pen_at_mode_orient = 0;
static kal_uint8 g_pen_at_report_mode = 0;
static mmi_pen_simulate_driver_context_struct g_pen_simulate_driver_cntx;
/* pre callback function: registered by the application */
/* post callback function: registered by the application */
#ifndef __MTK_TARGET__
static MMI_BOOL mmi_pen_modis_read_from_ring_buffer(mmi_pen_event_struct *touch_data);
static void mmi_pen_modis_simulate_driver(void);
static U32 g_mmi_pre_pen_move_time = 0;
#endif
static void generate_pen_abort_event(void);
static void mmi_pen_simulator_pen_repeat_hdlr(void);

static S32 mmi_pen_simulator_in_stroke_area(S16 x, S16 y);
static void mmi_pen_poll_hdlr(void);
static void mmi_pen_simulator_fix_point_bound(S16 *x, S16 *y);

static void  mmi_pen_drv_enable(MMI_BOOL enable);
static void mmi_pen_drv_reset(MMI_BOOL reset);
static void reset_pre_touch_event_status(void);
static mmi_pen_event_type_enum switch_touch_event(DCL_TP_Event_enum event);
static void mmi_pen_touch_panel_sendilm(DCL_EVENT touch_event);

extern MMI_BOOL g_pen_flag;
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_touch_set_mode
 * DESCRIPTION
 *  set touch screen mode
 * PARAMETERS
 *  mode : [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_touch_set_mode(mmi_frm_touch_mode mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if ((!defined(__TOUCH_PANEL_CAPACITY__) && !defined(__TOUCH_PANEL_MULTITOUCH__)) || (!defined(__MTK_TARGET__)))
     mode = MMI_FRM_SINGLE_TOUCH;
    #endif
    MMI_ASSERT(mode < MMI_FRM_MULTI_TOUCH_TOTAL);
    mmi_pen_reset();
    g_pen_cntx.touch_mode = mode;

    if(MMI_FRM_MULTI_TOUCH == mode)
    {
        g_pen_simulate_driver_cntx.is_AT_command = 0;
    }
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_SET_TOUCH_MODE, mode);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_touch_get_mode
 * DESCRIPTION
 *  get current screen touch mode
 * PARAMETERS
 *  mode : [IN] 
 * RETURNS
 *  mmi_frm_touch_mode
 *****************************************************************************/
mmi_frm_touch_mode mmi_frm_touch_get_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_pen_cntx.touch_mode;
}











/*****************************************************************************
 * FUNCTION
 *  mmi_pen_simulator_pen_longtap_hdlr
 * DESCRIPTION
 *  Simulate driver behavior for Modis and AT command, start a gui timer to call
 *  pen longtap event callback, and start pen repeat timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_simulator_pen_longtap_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_event_struct touchevent;
    kal_uint32 time;
    mmi_pen_event_struct* lookahead_buffer = (mmi_pen_event_struct*)g_frm_touch_queue.queue;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_simulate_driver_cntx.is_waiting_long_tap_event)
    {
        if (g_frm_touch_queue.write < MMI_PEN_LOOKAHEAD_BUFFER_SIZE)
        {
            touchevent.event = DCL_PEN_LONGTAP;
            touchevent.x_adc = g_pen_simulate_driver_cntx.pen_pre_down_pos.x;
            touchevent.y_adc = g_pen_simulate_driver_cntx.pen_pre_down_pos.y;
            kal_get_time(&time);
            touchevent.time_stamp = time;
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_SIMULATE_PEN_LONGTAP, touchevent.x_adc, touchevent.y_adc);
            lookahead_buffer[g_frm_touch_queue.write] = touchevent;
            g_frm_touch_queue.write++;
        }
        gui_start_timer(MMI_PEN_REPEAT_TIME * 10, mmi_pen_simulator_pen_repeat_hdlr);
        g_pen_simulate_driver_cntx.is_waiting_long_tap_event = 0;
    }
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_simulator_pen_repeat_hdlr
 * DESCRIPTION
 *  pen repeat timer callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_simulator_pen_repeat_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_event_struct touchevent;
    U32 time;
    mmi_pen_event_struct* lookahead_buffer = (mmi_pen_event_struct*)g_frm_touch_queue.queue;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_frm_touch_queue.write < MMI_PEN_LOOKAHEAD_BUFFER_SIZE) && (g_pen_simulate_driver_cntx.is_pen_down == 1))
    {
        touchevent.event = DCL_PEN_REPEAT;
        touchevent.x_adc = g_pen_simulate_driver_cntx.pen_pre_down_pos.x;
        touchevent.y_adc = g_pen_simulate_driver_cntx.pen_pre_down_pos.y;
        kal_get_time(&time);
        touchevent.time_stamp = time;
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_SIMULATE_PEN_REPEAT, touchevent.x_adc, touchevent.y_adc);
        lookahead_buffer[g_frm_touch_queue.write] = touchevent;
        g_frm_touch_queue.write++;
        gui_start_timer(MMI_PEN_REPEAT_TIME * 10, mmi_pen_simulator_pen_repeat_hdlr);
        mmi_pen_touch_panel_sendilm(DCL_TP_UNKNOWN_EVENT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_simulate_is_exceed_pen_move_threshold
 * DESCRIPTION
 *  Compare the current coordinate to the prevous down position, if it's larger than
 *  the threshold, it will generate pen move, otherwise, ignore this event.
 * PARAMETERS
 *  x, y    :[IN]  the current coordinate.
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_pen_simulate_is_exceed_pen_move_threshold(S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x_diff, y_diff;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x_diff = x - g_pen_simulate_driver_cntx.pen_pre_down_pos.x;
    y_diff = y - g_pen_simulate_driver_cntx.pen_pre_down_pos.y;
    x_diff = (x_diff >= 0) ? x_diff: -x_diff;
    y_diff = (y_diff >= 0) ? y_diff: -y_diff;
    
    if (!g_pen_simulate_driver_cntx.is_waiting_long_tap_event) // normal case, not in longtap timer
    {
        if((x_diff >= MMI_PEN_SKIP_MOVE_OFFSET || y_diff >= MMI_PEN_SKIP_MOVE_OFFSET))
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    else // in longtap timer
    {
        if((x_diff >= MMI_PEN_SKIP_LONGTAP_OFFSET || y_diff >= MMI_PEN_SKIP_LONGTAP_OFFSET))
        {
            return MMI_TRUE;          
        }
       else
       {
           return MMI_FALSE;   
       }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_simulate_is_exceed_stroke_move_threshold
 * DESCRIPTION
 *  Compare the current coordinate to the prevous down position, if it's larger than
 *  the threshold, it will generate stroke move, otherwise, ignore this event.
 * PARAMETERS
 *  x, y    :[IN]  the current coordinate.
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_pen_simulate_is_exceed_stroke_move_threshold(S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x_diff, y_diff;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x_diff = x - g_pen_simulate_driver_cntx.pen_pre_down_pos.x;
    y_diff = y - g_pen_simulate_driver_cntx.pen_pre_down_pos.y;
    x_diff = (x_diff >= 0) ? x_diff: -x_diff;
    y_diff = (y_diff >= 0) ? y_diff: -y_diff;
    if((x_diff >= MMI_PEN_SKIP_STROKE_MOVE_OFFSET || y_diff >= MMI_PEN_SKIP_STROKE_MOVE_OFFSET))
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
 *  mmi_pen_at_ctsa_rsp
 * DESCRIPTION
 *  Send AT command(CTSA) response to L4
 * PARAMETERS
 *  result    :[IN]  AT Command CTSA result code.
 *                   0, success
 *                   -1, can not generate pen move
 *                   -2, invalid action
 *                   -3, pen buffer full
 *                   -4, can not entry AT commond mode
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_at_ctsa_rsp(kal_int8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_screen_touch_rsp_struct *local;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_simulate_driver_cntx.is_AT_command)
    {
        local = (mmi_frm_screen_touch_rsp_struct *)mmi_construct_msg_local_para(sizeof(mmi_frm_screen_touch_rsp_struct));
        local->result = result;
        mmi_frm_send_ilm(g_scr_mod, MSG_ID_MMI_EQ_SCREEN_TOUCH_RES_REQ, (oslParaType*) local, NULL);
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_SEND_CTSA_RSP, result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_simulate_driver_enqueue_lookahead_buffer
 * DESCRIPTION
 * Put at command or Modis simulate driver events in lookahead buffer.
 * PARAMETERS
 *  touchevent    :[IN]  touchevent.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_simulate_driver_enqueue_lookahead_buffer(mmi_pen_event_struct *touchevent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_event_struct* lookahead_buffer = (mmi_pen_event_struct*)g_frm_touch_queue.queue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lookahead_buffer[g_frm_touch_queue.write] = *touchevent;
    g_frm_touch_queue.write++;
}





/*****************************************************************************
 * FUNCTION
 *  mmi_pen_simulate_driver_pen_down
 * DESCRIPTION
 *  simulate driver pen down/pen move handler for at command and modis. If it's first pen down, we should 
 *  judge if it is in the stroke area. And if we already have pen down before, we should judge if it will
 *  generate pen move or stroke move events.
 * PARAMETERS
 *  touchevent       : [IN]  touch event.
 *  enqueuecallback  : [IN]  put touch event to buffer callback
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_simulate_driver_pen_down(mmi_pen_event_struct *touchevent, pen_enqueue_callback enqueuecallback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 handwriting_index = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* The first pen down */
    if (!g_pen_simulate_driver_cntx.is_pen_down)
    {
        MMI_ASSERT(!g_pen_simulate_driver_cntx.is_stroke_created);
        /* Check if in handwriting area */
        if (g_pen_simulate_driver_cntx.ext_enable == MMI_FALSE)
        {
            handwriting_index = mmi_pen_simulator_in_stroke_area(touchevent->x_adc, touchevent->y_adc);

            if (handwriting_index >= 0) //stroke events
            {
                g_pen_simulate_driver_cntx.is_stroke_created = 1;
                
                if((g_pen_ext_stroke_area.x1 != g_pen_ext_stroke_area.x2) &&
                   (g_pen_ext_stroke_area.y1 != g_pen_ext_stroke_area.y2))
                {
                   g_pen_simulate_driver_cntx.ext_enable = MMI_TRUE;/*use extended handwriting area*/
                }   
            } 
        }
        else
        {
            if ((touchevent->x_adc >= g_pen_ext_stroke_area.x1) && (touchevent->y_adc >= g_pen_ext_stroke_area.y1) &&
                (touchevent->x_adc <= g_pen_ext_stroke_area.x2) && (touchevent->y_adc <= g_pen_ext_stroke_area.y2))
                g_pen_simulate_driver_cntx.is_stroke_created = 1; 
        }
        
        /* in handwriting area */
        if (g_pen_simulate_driver_cntx.is_stroke_created == 1)
        {
            touchevent->event = DCL_STROKE_DOWN;
            enqueuecallback(touchevent);
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_SIMULATE_STROKE_DOWN, touchevent->x_adc, touchevent->y_adc);
        }
        
        /* not in handwriting area, just pen down */
        else
        {
            touchevent->event = DCL_PEN_DOWN;
            enqueuecallback(touchevent);
            /* start timer to wait for longtap */
            gui_start_timer(MMI_PEN_LONGTAP_TIME * 10, mmi_pen_simulator_pen_longtap_hdlr);
            g_pen_simulate_driver_cntx.is_waiting_long_tap_event = 1;
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_SIMULATE_PEN_DOWN, touchevent->x_adc, touchevent->y_adc);
        }
        g_pen_simulate_driver_cntx.is_pen_down = 1;
        /* send response for AT commond */
        mmi_pen_at_ctsa_rsp(MMI_PEN_CTSA_OK);
        g_pen_simulate_driver_cntx.pen_pre_down_pos.x = touchevent->x_adc;
        g_pen_simulate_driver_cntx.pen_pre_down_pos.y = touchevent->y_adc;
        /* Simulate driver: send msg when pen down */
				mmi_pen_touch_panel_sendilm(DCL_TP_UNKNOWN_EVENT);
    }

    /* we already have pen down event before */
    else
    {
        if (!g_pen_simulate_driver_cntx.is_stroke_created) // pen event before
        {

            //if(mmi_pen_simulate_is_exceed_pen_move_threshold(touchevent->x_adc, touchevent->y_adc))
            //{
                touchevent->event = DCL_PEN_MOVE;
                enqueuecallback(touchevent);
                g_pen_simulate_driver_cntx.is_waiting_long_tap_event = 0;
                gui_cancel_timer(mmi_pen_simulator_pen_repeat_hdlr);
                gui_start_timer(MMI_PEN_REPEAT_TIME * 10, mmi_pen_simulator_pen_repeat_hdlr);
                mmi_pen_at_ctsa_rsp(MMI_PEN_CTSA_OK);
                g_pen_simulate_driver_cntx.pen_pre_down_pos.x = touchevent->x_adc;
                g_pen_simulate_driver_cntx.pen_pre_down_pos.y = touchevent->y_adc;
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_SIMULATE_PEN_MOVE, touchevent->x_adc, touchevent->y_adc);
								mmi_pen_touch_panel_sendilm(DCL_TP_UNKNOWN_EVENT);
            //}
            /*else
            {
                mmi_pen_at_ctsa_rsp(MMI_PEN_CTSA_OK);
            }*/

        }
        
        else // stroke event before
        {
            
            if (mmi_pen_simulate_is_exceed_stroke_move_threshold(touchevent->x_adc, touchevent->y_adc))
            {
                touchevent->event = DCL_STROKE_MOVE;
                enqueuecallback(touchevent);
                mmi_pen_at_ctsa_rsp(MMI_PEN_CTSA_OK);
                g_pen_simulate_driver_cntx.pen_pre_down_pos.x = touchevent->x_adc;
                g_pen_simulate_driver_cntx.pen_pre_down_pos.y = touchevent->y_adc;
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_SIMULATE_STROKE_MOVE, touchevent->x_adc, touchevent->y_adc);
            }
            else
            {
                mmi_pen_at_ctsa_rsp(MMI_PEN_CTSA_NOT_MOVE);
            }

        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_simulate_driver_pen_up
 * DESCRIPTION
 *  simulate driver pen up/pen move handler for at command and modis.
 * PARAMETERS
 *  touchevent    :[IN]  touch event.
 *  enqueuecallback  : [IN]  put touch event to buffer callback
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_simulate_driver_pen_up(mmi_pen_event_struct *touchevent, pen_enqueue_callback enqueuecallback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_simulate_driver_cntx.is_pen_down)          
    {
        if (g_pen_simulate_driver_cntx.is_stroke_created)
        {
            // add stoke move/stroke up or stroke up
           if (mmi_pen_simulate_is_exceed_stroke_move_threshold(touchevent->x_adc, touchevent->y_adc))
            {
                touchevent->event = DCL_STROKE_MOVE;
                g_pen_simulate_driver_cntx.pen_pre_down_pos.x = touchevent->x_adc;
                g_pen_simulate_driver_cntx.pen_pre_down_pos.y = touchevent->y_adc;
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_SIMULATE_STROKE_MOVE, touchevent->x_adc, touchevent->y_adc);
                enqueuecallback(touchevent);
                touchevent->event = DCL_STROKE_UP;
                enqueuecallback(touchevent);
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_SIMULATE_STROKE_UP, touchevent->x_adc, touchevent->y_adc);
            }
            else
            {
                touchevent->event = DCL_STROKE_UP;
                touchevent->x_adc = g_pen_simulate_driver_cntx.pen_pre_down_pos.x;
                touchevent->y_adc = g_pen_simulate_driver_cntx.pen_pre_down_pos.y;
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_SIMULATE_STROKE_UP, touchevent->x_adc, touchevent->y_adc);
                enqueuecallback(touchevent);
            }
            g_pen_simulate_driver_cntx.is_stroke_created = 0;
            g_pen_simulate_driver_cntx.is_pen_down = 0;
            g_pen_simulate_driver_cntx.is_waiting_long_tap_event = 0;
            gui_cancel_timer(mmi_pen_simulator_pen_repeat_hdlr);
						mmi_pen_touch_panel_sendilm(DCL_TP_UNKNOWN_EVENT);
        }
        else
        {
            // add pen move/pen up or pen up cancel longtap and repeat timer
            if(mmi_pen_simulate_is_exceed_pen_move_threshold(touchevent->x_adc, touchevent->y_adc))
            {
                touchevent->event = DCL_PEN_MOVE;
                enqueuecallback(touchevent);
                g_pen_simulate_driver_cntx.pen_pre_down_pos.x = touchevent->x_adc;
                g_pen_simulate_driver_cntx.pen_pre_down_pos.y = touchevent->y_adc;
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_SIMULATE_PEN_MOVE, touchevent->x_adc, touchevent->y_adc);
                touchevent->event = DCL_PEN_UP;
                enqueuecallback(touchevent);
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_SIMULATE_PEN_UP, touchevent->x_adc, touchevent->y_adc);
            }
            else
            {
                touchevent->event = DCL_PEN_UP;
                touchevent->x_adc = g_pen_simulate_driver_cntx.pen_pre_down_pos.x;
                touchevent->y_adc = g_pen_simulate_driver_cntx.pen_pre_down_pos.y;
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_SIMULATE_PEN_UP, touchevent->x_adc, touchevent->y_adc);
                enqueuecallback(touchevent);
            }
            g_pen_simulate_driver_cntx.is_waiting_long_tap_event = 0;
            gui_cancel_timer(mmi_pen_simulator_pen_repeat_hdlr);
			 			mmi_pen_touch_panel_sendilm(DCL_TP_UNKNOWN_EVENT);
        }
        mmi_pen_at_ctsa_rsp(MMI_PEN_CTSA_OK);
        g_pen_simulate_driver_cntx.is_pen_down = 0;
        
    }
    else
    {
        mmi_pen_at_ctsa_rsp(MMI_PEN_CTSA_INVALID);//report error invalid release event
    #ifdef __MTK_TARGET__
        mmi_pen_drv_enable(MMI_TRUE);
        mmi_pen_drv_reset(MMI_TRUE);
    #endif/*__MTK_TARGET__*/
        memset(&g_pen_simulate_driver_cntx, 0x00, sizeof(g_pen_simulate_driver_cntx));
        //g_pen_at_mode_orient = 0;
        return;
    }
}


static void  mmi_pen_drv_enable(MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    STS_CTRL_EN_T data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	data.fgEnable = enable;
	DclSTS_Control(g_pen_drv_handle, STS_CMD_ENABLE, (DCL_CTRL_DATA_T*)&data);
}


static void  mmi_pen_drv_power_on(MMI_BOOL poweron)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    STS_CTRL_POWER_ON_T data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	data.fgPowerOn = poweron;
	DclSTS_Control(g_pen_drv_handle, STS_CMD_POWER_ON, (DCL_CTRL_DATA_T*)&data);


}


static void mmi_pen_drv_reset(MMI_BOOL reset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    STS_CTRL_RESET_T data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	data.fgSkipUnreleaseEnable = reset;
	DclSTS_Control(g_pen_drv_handle,STS_CMD_RESET, (DCL_CTRL_DATA_T*)&data);
}


static MMI_BOOL mmi_pen_drv_get_event(STS_CTRL_GET_T *touch_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
		if(DclSTS_Control(g_pen_drv_handle,STS_CMD_GET_EVENT, (DCL_CTRL_DATA_T*)touch_data))
    		return MMI_TRUE;
		else
			return MMI_FALSE;
}



static void mmi_pen_drv_reset_handwriting(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//MMI_BOOL value;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DclSTS_Control(g_pen_drv_handle,STS_CMD_RESET_HANDWRITING,0);
}



static void mmi_pen_drv_callback_registry(PFN_DCL_CALLBACK function, void *parameter)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DclSTS_RegisterCallback(g_pen_drv_handle, DCL_EVENT_STS_PUSH_BUFF, function);
}



static void mmi_pen_drv_config_handwriting(TouchPanelHandAreaStruct *area, U16 n, 
                              TouchPanelHandAreaStruct  *ext_area)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	STS_CTRL_CHW_T data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	data.rArea=(TS_HandArea_T*)area;
	data.rExtArea=(TS_HandArea_T*)ext_area;
	data.u2n=n;
	DclSTS_Control(g_pen_drv_handle,STS_CMD_CONF_HANDWRITING,(DCL_CTRL_DATA_T*)&data);
    
}



static void mmi_pen_drv_flush(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DclSTS_Control(g_pen_drv_handle,STS_CMD_FLUSH,0);
}





static void mmi_pen_drv_set_calibration(TouchPanelCaliStruct cali)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	STS_CTRL_RC_T prCtrlRC;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	prCtrlRC.rCali.x_offset=cali.x_offset;
	prCtrlRC.rCali.x_slope=cali.x_slope;
	prCtrlRC.rCali.y_offset=cali.y_offset;
	prCtrlRC.rCali.y_slope=cali.y_slope;
	DclSTS_Control(g_pen_drv_handle, STS_CMD_SET_CALI, (DCL_CTRL_DATA_T*)&prCtrlRC);

	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_is_in_at_mode
 * DESCRIPTION
 *  For setting/calibraction, if in the AT command mode, just do as modis behavior.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_pen_is_in_at_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_simulate_driver_cntx.is_AT_command == 1)
        return MMI_TRUE;
    else
        return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_ctsa_req
 * DESCRIPTION
 *  This is the protocal event handler of MSG_ID_MMI_CSTA_REQ
 *
 * PARAMETERS
 *  para    :[IN]  local parameter of the message MSG_ID_MMI_CSTA_REQ
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_pen_ctsa_req(void *para, module_type src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_screen_touch_req_struct *p = (mmi_frm_screen_touch_req_struct *)para;
    mmi_pen_event_struct touchevent;
    STS_CTRL_GET_T drv_evt;    
    MMI_BOOL if_can_change_to_at = MMI_FALSE;
    U32 time;
    mmi_frm_screen_touch_rsp_struct *local;
    mmi_pen_event_struct* lookahead_buffer = (mmi_pen_event_struct*)g_frm_touch_queue.queue;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* The first time entry AT commond mode */
    g_scr_mod = src_mod;
    if (g_pen_simulate_driver_cntx.is_AT_command == 0)
    {
        /* Disable touch panel, enter AT Command Mode */
    #ifdef __MTK_TARGET__ /* Target */ 
        if ((g_frm_touch_queue.write == 0) && (mmi_pen_drv_get_event(&drv_evt) == MMI_FALSE) &&
            (g_pen_cntx.is_pen_down == 0) && (g_pen_cntx.touch_mode == MMI_FRM_SINGLE_TOUCH) && (!g_pen_cntx.is_blocked))
        {
            if_can_change_to_at = MMI_TRUE;
        }
    #else /* Modis */
        if ((g_frm_touch_queue.write == 0) && (g_mmi_pen_MODIS_qread == g_mmi_pen_MODIS_qwrite) &&
            (g_pen_cntx.is_pen_down == 0))
        {
            if_can_change_to_at = MMI_TRUE;
        }
    #endif /* __MTK_TARGET__ */
        
        if (if_can_change_to_at)
        {
            g_pen_simulate_driver_cntx.is_AT_command = 1;
        #ifndef __MTK_TARGET__
            g_mmi_pen_MODIS_qread = g_mmi_pen_MODIS_qwrite = 0;
            gui_cancel_timer(mmi_pen_modis_simulate_driver);
            g_mmi_pen_MODIS_start_timer = MMI_FALSE;
        #endif           
            /* clear the driver ring buffer */
            mmi_pen_drv_reset(MMI_TRUE);
            mmi_pen_drv_enable(MMI_FALSE);
             //memset(g_pen_lookahead_buffer, 0x00, sizeof(g_pen_lookahead_buffer));
            g_frm_touch_queue.read = g_frm_touch_queue.write = 0;
            //clear driver context
            memset(&g_pen_simulate_driver_cntx, 0x00, sizeof(g_pen_simulate_driver_cntx));
            memset(&g_pen_cntx, 0, sizeof(g_pen_cntx));
            g_pen_cntx.is_enabled = 1;
            g_pen_simulate_driver_cntx.is_AT_command = 1;
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_ENTRY_AT_MODE, g_pen_at_mode_orient);
        }
        else // cannot change to AT command
        {
            local = (mmi_frm_screen_touch_rsp_struct *)mmi_construct_msg_local_para(sizeof(mmi_frm_screen_touch_rsp_struct));
            local->result = MMI_PEN_CTSA_NOT_ENTRY_AT_MODE;
            mmi_frm_send_ilm(g_scr_mod, MSG_ID_MMI_EQ_SCREEN_TOUCH_RES_REQ, (oslParaType*) local, NULL);
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_CAN_NOT_ENTRY_AT_MODE);
            return MMI_TRUE;
        }
    }
    if (p == NULL || (g_frm_touch_queue.write >= (MMI_PEN_LOOKAHEAD_BUFFER_SIZE - 3)))
    {
        mmi_pen_at_ctsa_rsp(MMI_PEN_CTSA_LOOKAHEAD_FULL);
        return MMI_TRUE;
    }
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_PEN_CSTA_REQ, p->action, p->x, p->y);
    kal_get_time(&time);
    touchevent.time_stamp = time;
    if (g_pen_at_mode_orient == 1)
    {
        S16 x, y;
        x = (S16)p->x;
        y = (S16)p->y;
        mmi_pen_simulator_fix_point_bound(&x, &y);
        touchevent.x_adc = (GDI_LCD_HEIGHT - 1) - y;
        touchevent.y_adc =  x;
    }
    else
    {
        touchevent.x_adc = p->x;
        touchevent.y_adc = p->y;
        mmi_pen_simulator_fix_point_bound((S16*)&touchevent.x_adc, (S16*)&touchevent.y_adc);
    }
    switch(p->action)
    {   
        //down or move
        case MMI_PEN_AT_DOWN:
        {
            mmi_pen_simulate_driver_pen_down(&touchevent, mmi_pen_simulate_driver_enqueue_lookahead_buffer);
            break;
        }
        //up or move, may be need to add pen up
        case MMI_PEN_AT_UP: 
        {
            mmi_pen_simulate_driver_pen_up(&touchevent, mmi_pen_simulate_driver_enqueue_lookahead_buffer);          
            break;
        }
        //single tap, need to judge if valid
        case MMI_PEN_AT_SINGLETAP:
        {
            if (!g_pen_simulate_driver_cntx.is_pen_down)
            {
                touchevent.event = DCL_PEN_DOWN;
                lookahead_buffer[g_frm_touch_queue.write] = touchevent;
                g_frm_touch_queue.write++;
                g_pen_simulate_driver_cntx.pen_pre_down_pos.x = touchevent.x_adc;
                g_pen_simulate_driver_cntx.pen_pre_down_pos.y = touchevent.y_adc;
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_SIMULATE_PEN_DOWN, touchevent.x_adc, touchevent.y_adc);
                touchevent.event = DCL_PEN_UP;
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_SIMULATE_PEN_UP, touchevent.x_adc, touchevent.y_adc);
                lookahead_buffer[g_frm_touch_queue.write] = touchevent;
                g_frm_touch_queue.write++;
				mmi_pen_touch_panel_sendilm(DCL_TP_UNKNOWN_EVENT);
                mmi_pen_at_ctsa_rsp(MMI_PEN_CTSA_OK);
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_AT_MODE_SINGLETAP);
            }
            else
            {
                //report error
                mmi_pen_at_ctsa_rsp(MMI_PEN_CTSA_INVALID);
            }
            break;
        }
        //double tap, simulate double click => pen down, pen up, pen down, pen up
        case MMI_PEN_AT_DOUBLETAP:
        {
            if (!g_pen_simulate_driver_cntx.is_pen_down)
            {
                // add pen down pen up pen down pen up
                touchevent.event = DCL_PEN_DOWN;
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_SIMULATE_PEN_DOWN, touchevent.x_adc, touchevent.y_adc);
                lookahead_buffer[g_frm_touch_queue.write] = touchevent;
                g_frm_touch_queue.write++;
                touchevent.event = DCL_PEN_UP;
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_SIMULATE_PEN_UP, touchevent.x_adc, touchevent.y_adc);
                lookahead_buffer[g_frm_touch_queue.write] = touchevent;
                g_frm_touch_queue.write++;
                touchevent.event = DCL_PEN_DOWN;
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_SIMULATE_PEN_DOWN, touchevent.x_adc, touchevent.y_adc);
                lookahead_buffer[g_frm_touch_queue.write] = touchevent;
                g_frm_touch_queue.write++;
                g_pen_simulate_driver_cntx.pen_pre_down_pos.x = touchevent.x_adc;
                g_pen_simulate_driver_cntx.pen_pre_down_pos.y = touchevent.y_adc;
                touchevent.event = DCL_PEN_UP;
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_SIMULATE_PEN_UP, touchevent.x_adc, touchevent.y_adc);
                lookahead_buffer[g_frm_touch_queue.write] = touchevent;
                g_frm_touch_queue.write++;
				mmi_pen_touch_panel_sendilm(DCL_TP_UNKNOWN_EVENT);
                mmi_pen_at_ctsa_rsp(MMI_PEN_CTSA_OK); //right case
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_AT_MODE_DOUBLETAP);
            }
            else
            {
                //report error
                mmi_pen_at_ctsa_rsp(MMI_PEN_CTSA_INVALID);
            }
            break;
        }
        default:
            mmi_pen_at_ctsa_rsp(MMI_PEN_CTSA_INVALID);
            return MMI_TRUE;
    }
    return MMI_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_pen_cso_req
 * DESCRIPTION
 *  Protocol event handler of CSO.
 * PARAMETERS
 *  para    :[IN]  local parameter of the message
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_pen_cso_req(void *para, module_type src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_screen_touch_orient_req_struct *orient = (mmi_frm_screen_touch_orient_req_struct *)para;
    mmi_frm_screen_touch_orient_rsp_struct * localdata;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(orient)
    {
        g_scr_mod = src_mod;
        localdata = (mmi_frm_screen_touch_orient_rsp_struct *)mmi_construct_msg_local_para(sizeof(mmi_frm_screen_touch_orient_rsp_struct));
        localdata->mode = orient->mode;
        if (orient->mode == 0) // 0 is query
        {
            localdata->result = g_pen_at_mode_orient;
        }
        else if (orient->mode == 1) // 1 is set
        {
            g_pen_at_mode_orient = orient->orient;
            
        }
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_PEN_CSO_REQ, orient->mode, g_pen_at_mode_orient);
        mmi_frm_send_ilm(g_scr_mod, MSG_ID_MMI_EQ_SCRNORIENT_RES_REQ, (oslParaType*) localdata, NULL);
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_cmer_req
 * DESCRIPTION
 *  Protocol event handler of CMER, report touch event.
 * PARAMETERS
 *  para    :[IN]  local parameter of the message
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_pen_cmer_req(void *para, module_type src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (para)
    {
        g_scr_mod = src_mod;
        g_pen_at_report_mode = ((mmi_frm_screen_touch_report_req_struct *)para)->mode;
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_PEN_CMER_REQ, g_pen_at_report_mode);
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_cmer_req
 * DESCRIPTION
 *  This is the parameter of MSG_ID_MMI_CSS_REQ
 *
 * PARAMETERS
 *  para    :[IN]  local parameter of the message
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_at_commod_send_report(kal_uint8 action, kal_uint16 x, kal_uint16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_screen_touch_report_rsp_struct *localdata;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(((g_pen_at_report_mode == MMI_PEN_REPORT_TARGET) && (g_pen_simulate_driver_cntx.is_AT_command == 0)) ||
       (g_pen_at_report_mode == MMI_PEN_REPORT_ALL) || 
       ((g_pen_at_report_mode == MMI_PEN_REPORT_TARGET_VERBOSE) && (g_pen_simulate_driver_cntx.is_AT_command == 0)))
    {    
        localdata = (mmi_frm_screen_touch_report_rsp_struct *)mmi_construct_msg_local_para(sizeof(mmi_frm_screen_touch_report_rsp_struct));
        localdata->action= action;
        if (g_pen_at_mode_orient == 1)
        {
            localdata->x = y;
            localdata->y = UI_device_width - 1 - x;
        }
        else
        {
            localdata->x = x;
            localdata->y = y;
        }
        mmi_frm_send_ilm(g_scr_mod, MSG_ID_MMI_EQ_SCRNTCH_EVENT_OUTPUT_REQ, (oslParaType*) localdata, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_simulator_fix_point_bound
 * DESCRIPTION
 *  The function is used to correct the coordinates of the point if the point lies
 *  in out of the handwriting area.
 *  For Single Block handwriting: make sure the points inside the LCD area.
 *  For Multi-Block handlwriting: make sure the points inside the handwriting area.
 * PARAMETERS
 *  x       :[IN/OUT]   x coordinate of the touch point       
 *  y       :[IN/OUT]   y coordinate of the touch point  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_simulator_fix_point_bound(S16 *x, S16 *y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*x < 0)
    {
        *x = 0;
    }
    else if (*x >= GDI_LCD_WIDTH)
    {
        *x = GDI_LCD_WIDTH - 1;
    }
    if (*y < 0)
    {
        *y = 0;
    }
    else if (*y >= GDI_LCD_HEIGHT)
    {
        *y = GDI_LCD_HEIGHT - 1;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_simulator_in_stroke_area
 * DESCRIPTION
 *  This function is used to judge if the point is inside the handwriting area
 * PARAMETERS
 *  x       :[IN]  x coordinate of the touch point        
 *  y       :[IN]  y coordinate of the touch point      
 * RETURNS
 *  The index of handwriting block. 0 for block-0 or extended area, -1 if not found.
 *****************************************************************************/
static S32 mmi_pen_simulator_in_stroke_area(S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
	S32 x1;
	S32 y1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SCREEN_ROTATE__
	if (mmi_frm_get_screen_rotate() != MMI_FRM_SCREEN_ROTATE_0)
	{		  
		x1 = x;
		y1 = y;
		gdi_rotate_map_absolute_hw_to_lcd(&x1, &y1);
		x = (S16)x1;
		y = (S16)y1;	
			
	}
#endif /* __MMI_SCREEN_ROTATE__ */

    for (i = 0; i < g_pen_num_stroke_area; i++)
    {
        if (x >= g_pen_stroke_areas[i].x1 && x <= g_pen_stroke_areas[i].x2 &&
            y >= g_pen_stroke_areas[i].y1 && y <= g_pen_stroke_areas[i].y2)
        {
            return i;
        }
    }
    return -1;
}


#ifndef __MTK_TARGET__
/* By Windows main thread */

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_modis_simulate_driver_sample
 * DESCRIPTION
 *  Modis protocol event handler
 * PARAMETERS
 *  void   
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_modis_simulate_driver_sample(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_start_timer(MMI_PEN_SAMPLING_PERIOD_1 * 10, mmi_pen_modis_simulate_driver);
    g_mmi_pen_MODIS_start_timer = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_MODIS_enqueue_point
 * DESCRIPTION
 *   En-queue the stroke events into g_mmi_pen_MODIS_ring_buffer array.
 * PARAMETERS
 *  type        [IN]   stroke event type.     
 *  x           [IN]   x coordinate.     
 *  y           [IN]   y coordinate.      
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_enqueue_modis_ring_buffer(mmi_pen_event_struct *touchevent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 tail = g_mmi_pen_MODIS_qwrite;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //kal_prompt_trace(MOD_MMI_FW, "[PEN] Enqueu modis ring buffer, event=%d, x=%d, y=%d", touchevent->event, touchevent->x_adc, touchevent->y_adc);
    //kal_prompt_trace(MOD_MMI_FW, "[PEN] Modis Ring buffer(En), read = %d, writer = %d",g_mmi_pen_MODIS_qread, g_mmi_pen_MODIS_qwrite);
    g_mmi_pen_MODIS_ring_buffer[tail] = *touchevent; 
    
    if (++tail == MMI_PEN_MODIS_QUEUE_SIZE)
    {
        tail = 0;
    }
    g_mmi_pen_MODIS_qwrite = tail;
    MMI_ASSERT(tail != g_mmi_pen_MODIS_qread);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_MODIS_enqueue_down
 * DESCRIPTION
 *  En-queue the mouse down events into g_mmi_pen_MODIS_ring_buffer array.
 *  Remark: Executed from non-MMI task
 * PARAMETERS
 *  x       [IN]  x coordinate      
 *  y       [IN]  y coordinate      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_MODIS_enqueue_down(S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_event_struct touchevent;
    MYQUEUE message;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     kal_get_time(&g_mmi_pre_pen_move_time);
    if (!g_pen_simulate_driver_cntx.is_AT_command && g_pen_cntx.is_enabled && !g_pen_cntx.is_blocked)
    {
        touchevent.x_adc = x;
        touchevent.y_adc = y;
        touchevent.event = DCL_PEN_DOWN;
       // kal_prompt_trace(MOD_MMI_FW, "[PEN] Mouser Down, x=%d, y=%d", x, y);
        mmi_pen_enqueue_modis_ring_buffer(&touchevent);
        if (!g_mmi_pen_MODIS_start_timer)
        {
             message.oslMsgId = MSG_ID_MODIS_TP_EVENT_IND;
             message.oslDataPtr = NULL;
             message.oslPeerBuffPtr = NULL;
             message.oslSrcId = MOD_L4C;
             message.oslDestId = MOD_MMI;
             OslMsgSendExtQueue(&message);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_MODIS_enqueue_move
 * DESCRIPTION
 *  En-queue the mouse move events into g_mmi_pen_MODIS_ring_buffer array.
 * PARAMETERS
 *  x       [IN]   x coordinate     
 *  y       [IN]   y coordinate     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_MODIS_enqueue_move(S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_event_struct touchevent;
    kal_uint32 time, threshold, time_diff;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_pen_simulate_driver_cntx.is_AT_command && g_pen_cntx.is_enabled && !g_pen_cntx.is_blocked)
    {
        kal_get_time(&time);
        if(g_pen_num_stroke_area)
        {
            threshold = MMI_PEN_SAMPLING_PERIOD_2*10;
        }
        else
        {
            /* Adjust threshold on MODIS since pen event is faster on pc, this is a tuned count! */
            threshold = 40;
        }
        time_diff = (time > g_mmi_pre_pen_move_time) ? (time - g_mmi_pre_pen_move_time) : (g_mmi_pre_pen_move_time - time);
        if (kal_ticks_to_milli_secs(time_diff) >= threshold)
        {
            touchevent.x_adc = x;
            touchevent.y_adc = y;
            touchevent.event = DCL_PEN_DOWN;
	       g_mmi_pre_pen_move_time = time;
	        //kal_prompt_trace(MOD_MMI_FW, "[PEN] Mouser Move, x=%d, y=%d", x, y);
            mmi_pen_enqueue_modis_ring_buffer(&touchevent);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_MODIS_enqueue_up
 * DESCRIPTION
 *  En-queue the stroke up events into g_mmi_pen_MODIS_ring_buffer array.
 * PARAMETERS
 *  x       [IN]  x coordinate      
 *  y       [IN]  y coordinate      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_MODIS_enqueue_up(S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_event_struct touchevent;
    MYQUEUE message;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_pen_simulate_driver_cntx.is_AT_command && g_pen_cntx.is_enabled && !g_pen_cntx.is_blocked)
    {
        touchevent.x_adc = x;
        touchevent.y_adc = y;
        touchevent.event = DCL_PEN_UP;
        //kal_prompt_trace(MOD_MMI_FW, "[PEN] Mouser Up, x=%d, y=%d", x, y);
        mmi_pen_enqueue_modis_ring_buffer(&touchevent);
        if (!g_mmi_pen_MODIS_start_timer)
        {
             message.oslMsgId = MSG_ID_MODIS_TP_EVENT_IND;
             message.oslDataPtr = NULL;
             message.oslPeerBuffPtr = NULL;
             message.oslSrcId = MOD_L4C;
             message.oslDestId = MOD_MMI;
             OslMsgSendExtQueue(&message);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_modis_simulate_driver
 * DESCRIPTION
 *  Change MODIS mouse events to driver pen events.
 * PARAMETERS
 *  void  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_modis_simulate_driver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_event_struct touchevent;
    kal_uint32 time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(g_mmi_pen_MODIS_qwrite != g_mmi_pen_MODIS_qread)
    {
        if(g_frm_touch_queue.write >= (MMI_PEN_LOOKAHEAD_BUFFER_SIZE - 1))
		{
			mmi_pen_touch_panel_sendilm(DCL_TP_UNKNOWN_EVENT);
		    gui_start_timer(MMI_PEN_SAMPLING_PERIOD_1 * 10, mmi_pen_modis_simulate_driver);
			return;
		}
        if (mmi_pen_modis_read_from_ring_buffer(&touchevent))     
        {
			kal_get_time(&time);
			touchevent.time_stamp = time;
		  //mmi_pen_simulator_fix_point_bound(&touchevent.x_adc, &touchevent.y_adc);
			switch(touchevent.event)
			{
				case DCL_PEN_DOWN:
				    if (!g_pen_simulate_driver_cntx.is_abort_happen)
				    {
					    mmi_pen_simulate_driver_pen_down(&touchevent, mmi_pen_simulate_driver_enqueue_lookahead_buffer);
				    }
					break;
				 case DCL_PEN_UP:
				    if(!g_pen_simulate_driver_cntx.is_abort_happen)
				    {
					    mmi_pen_simulate_driver_pen_up(&touchevent, mmi_pen_simulate_driver_enqueue_lookahead_buffer);
					}
					else
					{
					    g_pen_simulate_driver_cntx.is_abort_happen = 0;
					}
					break;
				 default:
					MMI_ASSERT(0);
					break;
			}
		}
    }
    g_pen_flag = MMI_TRUE;
    gui_start_timer(MMI_PEN_SAMPLING_PERIOD_1 * 10, mmi_pen_modis_simulate_driver);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_modis_read_from_ring_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_pen_modis_read_from_ring_buffer(mmi_pen_event_struct *touch_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //kal_prompt_trace(MOD_MMI_FW, "[PEN] Modis Ring buffer(De), read = %d, writer = %d",g_mmi_pen_MODIS_qread, g_mmi_pen_MODIS_qwrite);
    if (g_mmi_pen_MODIS_qwrite == g_mmi_pen_MODIS_qread)
    {
        return MMI_FALSE;
    }
    else
    {
        memcpy(touch_data, &g_mmi_pen_MODIS_ring_buffer[g_mmi_pen_MODIS_qread], sizeof(mmi_pen_event_struct));
        //kal_prompt_trace(MOD_MMI_FW, "READ from ring buffer event =%d, X = %d, Y = %d\n", touch_data->event, touch_data->x_adc, touch_data->y_adc);
        if (g_mmi_pen_MODIS_qread == MMI_PEN_MODIS_QUEUE_SIZE - 1)
            g_mmi_pen_MODIS_qread = 0;
        else
            g_mmi_pen_MODIS_qread++;
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_MODIS_flush_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_MODIS_flush_queue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_pen_MODIS_qwrite = 0;
    g_mmi_pen_MODIS_qread = 0;
    //g_mmi_pen_MODIS_timer_flag = MMI_FALSE;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_get_distance_square
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos1        [IN]        
 *  pos2        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S16 mmi_pen_get_distance_square(mmi_pen_point_struct pos1, mmi_pen_point_struct pos2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 diff_x = pos1.x - pos2.x;
    S16 diff_y = pos1.y - pos2.y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (diff_x < 0)
    {
        diff_x = -diff_x;
    }
    if (diff_y < 0)
    {
        diff_y = -diff_y;
    }
    return (diff_x * diff_x) + (diff_y * diff_y);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_push_stroke_point
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_push_stroke_point(S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_cntx.num_points_queued >= g_pen_stroke_max_points - 2)
    {
        /* Leave the last two slots for (-1, 0) and (-1, -1) */
        return;
    }
    g_pen_stroke_points[g_pen_cntx.num_points_queued].x = x;
    g_pen_stroke_points[g_pen_cntx.num_points_queued].y = y;
    g_pen_cntx.num_points_queued++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_push_stroke_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_push_stroke_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_cntx.num_points_queued >= g_pen_stroke_max_points - 1)
    {
        return;
    }
#if defined(__MMI_HANWANG__)
    g_pen_stroke_points[g_pen_cntx.num_points_queued].x = -1;
    g_pen_stroke_points[g_pen_cntx.num_points_queued].y = 0;
    g_pen_cntx.num_points_queued++;
#elif defined(__MMI_PENPOWER__)
    if (g_pen_cntx.num_points_queued && 
        !(g_pen_stroke_points[g_pen_cntx.num_points_queued].x == -1 && g_pen_stroke_points[g_pen_cntx.num_points_queued].y == -1))
    {
        g_pen_stroke_points[g_pen_cntx.num_points_queued].x = -1;
        g_pen_stroke_points[g_pen_cntx.num_points_queued].y = -1;
        g_pen_cntx.num_points_queued++;
    }
#else 
    g_pen_stroke_points[g_pen_cntx.num_points_queued].x = -1;
    g_pen_stroke_points[g_pen_cntx.num_points_queued].y = 0;
    g_pen_cntx.num_points_queued++;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_push_char_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_push_char_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_cntx.num_points_queued >= g_pen_stroke_max_points)
    {
        /* queue full */
        return;
    }
#if defined(__MMI_HANWANG__)
    g_pen_stroke_points[g_pen_cntx.num_points_queued].x = -1;
    g_pen_stroke_points[g_pen_cntx.num_points_queued].y = -1;
    g_pen_cntx.num_points_queued++;
#elif defined(__MMI_PENPOWER__)
    if (g_pen_cntx.num_points_queued)
    {
        if (g_pen_stroke_points[g_pen_cntx.num_points_queued - 1].x == -1 && g_pen_stroke_points[g_pen_cntx.num_points_queued - 1].y == -1)
        {
            g_pen_cntx.num_points_queued--;
            g_pen_stroke_points[g_pen_cntx.num_points_queued].x = -1;
            g_pen_stroke_points[g_pen_cntx.num_points_queued].y = 0;
            g_pen_cntx.num_points_queued++;
        }
        else
        {
            g_pen_stroke_points[g_pen_cntx.num_points_queued].x = -1;
            g_pen_stroke_points[g_pen_cntx.num_points_queued].y = 0;
            g_pen_cntx.num_points_queued++;

        }
    }
    else
    {
        g_pen_stroke_points[g_pen_cntx.num_points_queued].x = -1;
        g_pen_stroke_points[g_pen_cntx.num_points_queued].y = 0;
        g_pen_cntx.num_points_queued++;
    }
#else 
    g_pen_stroke_points[g_pen_cntx.num_points_queued].x = -1;
    g_pen_stroke_points[g_pen_cntx.num_points_queued].y = -1;
    g_pen_cntx.num_points_queued++;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_lookup_handwriting_block
 * DESCRIPTION
 *  Search which handwriting block contains a point (multi-block mode)
 * PARAMETERS
 *  x       [IN]
 *  y       [IN]
 * RETURNS
 *  The index of handwriting block. 0 for block-0 or extended area, -1 if not found.
 *****************************************************************************/
static S32 mmi_pen_lookup_handwriting_block(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_pen_num_stroke_area; i++)
    {
        if (x >= g_pen_stroke_areas[i].x1 && x <= g_pen_stroke_areas[i].x2 &&
            y >= g_pen_stroke_areas[i].y1 && y <= g_pen_stroke_areas[i].y2)
        {
            return i;
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_fix_multi_block_pen_position
 * DESCRIPTION
 *  Restrict stroke position to the current handwriting block
 * PARAMETERS
 *  pos       [IN/OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_fix_multi_block_pen_position(mmi_pen_point_struct *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_handwriting_area_struct *block;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_pen_cntx.stroke_down_block_index >= 0 &&
               g_pen_cntx.stroke_down_block_index < g_pen_num_stroke_area);

    block = &g_pen_stroke_areas[g_pen_cntx.stroke_down_block_index];
    
    if (pos->x < block->x1)
    {
        pos->x = block->x1;
    }
    else if (pos->x > block->x2)
    {
        pos->x = block->x2;
    }
    
    if (pos->y < block->y1)
    {
        pos->y = block->y1;
    }
    else if (pos->y > block->y2)
    {
        pos->y = block->y2;
    }    
}


/*
 * Look-ahead buffer of pen events (used in mmi_pen_poll_hdlr())
 *
 * If our MMI is blocked and fails to process incoming pen events fast enough, 
 * it may have unexpected results (e.g. extq full) unless we drop certain pending events.
 */

/* 
 * Fill the data in lookahead buffer. 
 *
 * The sampling rate of pen events (MMI_PEN_SAMPLING_PERIOD_1) is very high,
 * If we find paired Pen Down/Up, it means that MMI is blocked.
 *
 * 1. If there are consecutive Pen Move events, keep the last one.
 * 2. If there are paired "Pen Down ~ Pen Up", drop it.
 *
 * We do not drop stroke events because it is used by handwriting engine.
 */
 /*****************************************************************************
 * FUNCTION
 *  mmi_pen_lookahead_buffer_filter_data
 * DESCRIPTION
 *  filter the lookahead buffer data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_lookahead_buffer_filter_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 first_down_index, last_up_index, windex, rindex;
    mmi_pen_event_struct*  lookahead_buffer = (mmi_pen_event_struct*)g_frm_touch_queue.queue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    first_down_index = -1;
    last_up_index = -1;
    if (g_frm_touch_queue.write == MMI_PEN_LOOKAHEAD_BUFFER_SIZE)
    {
        for (rindex = 1 /* not including the first event */ ; rindex < g_frm_touch_queue.write; rindex++)
        {
            switch (lookahead_buffer[rindex].event)
            {
                case DCL_PEN_DOWN:
                    if (first_down_index < 0)
                    {
                        first_down_index = rindex;
                    }
                    break;
    
                case DCL_PEN_UP:
                    if(rindex < (g_frm_touch_queue.write-1))
                    {
                    last_up_index = rindex;
                    }
                    break;
    
                case DCL_PEN_MOVE:
                case DCL_PEN_LONGTAP:
                case DCL_PEN_REPEAT:
                case DCL_PEN_LONGTAP_HOLD:
                case DCL_PEN_REPEAT_HOLD:
                    break;
    
                default:
                    /* Some events can not be dropped */
                    first_down_index = -1;
            }
        }
    
        if (first_down_index > 0 && last_up_index > first_down_index)
        {
            if (last_up_index < g_frm_touch_queue.write - 1)
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_PEN_TRC_DROP_LOOKAHEAD_BUF, first_down_index, last_up_index);
                memmove(
                    &lookahead_buffer[first_down_index],
                    &lookahead_buffer[last_up_index + 1],
                    sizeof(mmi_pen_event_struct) * (g_frm_touch_queue.write - 1 - last_up_index));
               g_frm_touch_queue.write -= (last_up_index - first_down_index + 1);
    
            }
    
        }
    }

    /* 
     * If there are multiple Pen Move events queued, it means that pen handler can not 
     * process the events fast enough. We should drop Pen Move events before the last one in queue.
     */
    #if defined(__MMI_GESTURES_FRAMEWORK__)
    		if(!mmi_frm_gesture_is_listening())
    #endif
    		{
    				for (windex = 0, rindex = 0; rindex < g_frm_touch_queue.write; rindex++)
        		{
            		if (lookahead_buffer[rindex].event == DCL_PEN_MOVE &&
                		rindex < g_frm_touch_queue.write - 1 && lookahead_buffer[rindex + 1].event == DCL_PEN_MOVE)
            		{
                		/* Drop this Pen Move event. */
                		continue;
            		}

            		if (windex != rindex)
            		{
                		lookahead_buffer[windex] = lookahead_buffer[rindex];
            		}
            		windex++;
        		}
        		g_frm_touch_queue.write = windex; 
    		}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_touch_enqueue
 * DESCRIPTION
 *  put the multi-touch event in the framework touch queue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
static void mmi_touch_enqueue(TouchPanelMultipleEventStruct* drv_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*single touch mode only get the first touch event, we will save event as mmi_pen_event_struct
      x, y, event, timestamp
     */

    if(g_pen_cntx.touch_mode == MMI_FRM_SINGLE_TOUCH)
    {
        mmi_pen_event_struct* lookahead_buffer = (mmi_pen_event_struct*)g_frm_touch_queue.queue;
        MMI_ASSERT(g_frm_touch_queue.write < MMI_PEN_LOOKAHEAD_BUFFER_SIZE);
        lookahead_buffer[g_frm_touch_queue.write].event = (DCL_TP_Event_enum)drv_evt->points[0].event;
        lookahead_buffer[g_frm_touch_queue.write].x_adc = drv_evt->points[0].x;
        lookahead_buffer[g_frm_touch_queue.write].y_adc = drv_evt->points[0].y;
        lookahead_buffer[g_frm_touch_queue.write].z = drv_evt->points[0].z;
        lookahead_buffer[g_frm_touch_queue.write].time_stamp = drv_evt->time_stamp;
    #if defined(__TOUCH_PANEL_MULTITOUCH__) && !defined(__TOUCH_PANEL_CAPACITY__)
		if (drv_evt->model == 2)
		{
		    if (drv_evt->points[0].event == DCL_PEN_UP && drv_evt->points[1].event != DCL_PEN_UP ||
				drv_evt->points[0].event == DCL_STROKE_UP && drv_evt->points[1].event != DCL_STROKE_UP)
		    {
		        //kal_prompt_trace(MOD_MMI_FW, "[Pen] first finger up, use second finger ");
       			lookahead_buffer[g_frm_touch_queue.write].event = drv_evt->points[1].event;
        		lookahead_buffer[g_frm_touch_queue.write].x_adc = drv_evt->points[1].x;
        		lookahead_buffer[g_frm_touch_queue.write].y_adc = drv_evt->points[1].y;
        		lookahead_buffer[g_frm_touch_queue.write].z = drv_evt->points[1].z;		        
		    }
			else if (drv_evt->points[0].event != DCL_PEN_UP && drv_evt->points[1].event == DCL_PEN_UP ||
				drv_evt->points[0].event != DCL_STROKE_UP && drv_evt->points[1].event == DCL_STROKE_UP)
			{
			    //use the 1 finger
			    //kal_prompt_trace(MOD_MMI_FW, "[Pen] second finger up, use first finger ");
			}
			else
			{
			    //kal_prompt_trace(MOD_MMI_FW, "[Pen] no finger up, use middle point (%d, %d)", 
					//lookahead_buffer[g_frm_touch_queue.write].x_adc,
					//lookahead_buffer[g_frm_touch_queue.write].y_adc);
		    	lookahead_buffer[g_frm_touch_queue.write].x_adc = (drv_evt->points[0].x + drv_evt->points[1].x) / 2;
				lookahead_buffer[g_frm_touch_queue.write].y_adc = (drv_evt->points[0].y + drv_evt->points[1].y) / 2;
			}
		}
	#endif

        g_frm_touch_queue.write++;
    }
    else
    {
    #if defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)
		U16 high, low;
		U32 i;
        /* mode +  (x, y, event) * finger number +  time stamp  */
        MMI_ASSERT(g_frm_touch_queue.write < QUEUE_SIZE);
        //kal_prompt_trace(MOD_MMI_FW, "[pen] mmi_touch_enqueue, write = %d", g_frm_touch_queue.write);
        g_frm_touch_queue.queue[g_frm_touch_queue.write] = drv_evt->model;
        g_frm_touch_queue.write++;

        for(i=0; i<drv_evt->model; i++)
        {

            #ifdef __MMI_SCREEN_ROTATE__
            if (mmi_frm_get_screen_rotate() != MMI_FRM_SCREEN_ROTATE_0)
            { 
                S32 x, y;        
                x = drv_evt->points[i].x;
                y = drv_evt->points[i].y;
                gdi_rotate_map_absolute_hw_to_lcd(&x, &y);			
                drv_evt->points[i].x = x;
                drv_evt->points[i].y = y;
             }
            #endif /* __MMI_SCREEN_ROTATE__ */
            g_frm_touch_queue.queue[g_frm_touch_queue.write] = drv_evt->points[i].x;
            g_frm_touch_queue.write++;
            g_frm_touch_queue.queue[g_frm_touch_queue.write] = drv_evt->points[i].y;
            g_frm_touch_queue.write++;
            g_frm_touch_queue.queue[g_frm_touch_queue.write] = drv_evt->points[i].z;
            g_frm_touch_queue.write++;
            g_frm_touch_queue.queue[g_frm_touch_queue.write] = drv_evt->points[i].event;
            g_frm_touch_queue.write++;
        }
        /* time stamp  high 16 bits put in array[1], low 16 bits put in array[0] */
        //*((U32*)(&(g_frm_touch_queue.queue[g_frm_touch_queue.write]))) = drv_evt->time_stamp;
        high = (drv_evt->time_stamp & 0xFFFF0000) >> 16;
        low = drv_evt->time_stamp & 0x0000FFFFF;
        g_frm_touch_queue.queue[g_frm_touch_queue.write] = low;//low 16 bits
        g_frm_touch_queue.write++;
        g_frm_touch_queue.queue[g_frm_touch_queue.write] = high;//high 16 bits
        g_frm_touch_queue.write ++;
    #endif
    }

}

#if defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)
/*****************************************************************************
 * FUNCTION
 *  mmi_touch_enqueue
 * DESCRIPTION
 *  put the multi-touch event in the framework touch queue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
static MMI_BOOL mmi_touch_ignore_drv_evt(U16 drv_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_pen_cntx.touch_mode == MMI_FRM_SINGLE_TOUCH)
    {
        if((g_pen_cntx.is_driver_down == 0) &&(drv_evt == DCL_PEN_DOWN) || (drv_evt == DCL_STROKE_DOWN))
        {
            g_pen_cntx.is_driver_down = 1;
        }
        else if((g_pen_cntx.is_driver_down == 1) && (drv_evt== DCL_PEN_UP) || (drv_evt == DCL_STROKE_UP))
        {
            g_pen_cntx.is_driver_down = 0;
        }
        else if((g_pen_cntx.is_driver_down == 0) && (drv_evt != DCL_PEN_DOWN) && (drv_evt != DCL_STROKE_DOWN) && (drv_evt != DCL_PEN_ABORT))
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_touch_reorder_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_touch_reorder_event(TouchPanelMultipleEventStruct* drv_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, pre_index = 0;
    S32 j = 0;
    U8 array[MMI_FRM_MULTI_TOUCH_MAX_FINGER] = {0, 1, 2, 3, 4};
    U32 distance, min_distance;
    U8 pen_up_index[MMI_FRM_MULTI_TOUCH_MAX_FINGER] = {0xff, 0xff, 0xff, 0xff, 0xff};
    U32 up_num = 0;
    mmi_pen_event_struct temp[MMI_FRM_MULTI_TOUCH_MAX_FINGER];
	U32 first_empty = 0;
	MMI_BOOL all_hold_event = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i=0; i< drv_evt->model; i++)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_GET_CTP_EVENT_FROM_DRIVER, 
                         i, drv_evt->points[i].event, drv_evt->points[i].x, drv_evt->points[i].y, drv_evt->model);
        // if all the event is STROKE_STATICAL, STROKE_HOLD, PEN_LONGTAP_HOLD, PEN_REPEAT_HOLD, we will skip this event.
        if ((drv_evt->points[i].event != DCL_STROKE_STATICAL) && (drv_evt->points[i].event != DCL_STROKE_HOLD) && 
            (drv_evt->points[i].event != DCL_PEN_LONGTAP_HOLD) && (drv_evt->points[i].event != DCL_PEN_REPEAT_HOLD))
        {
            all_hold_event = MMI_FALSE;
    
        }
        if ((drv_evt->points[i].event == DCL_PEN_UP) || (drv_evt->points[i].event == DCL_STROKE_UP))
        {

            pen_up_index[up_num] = i;
            up_num++;
        }
        
    }
    if (all_hold_event)
    {
        return MMI_FALSE; // skip this event
    }

    if (1 == drv_evt->model) // do not do the reorder for the just one point.
    {

        if(up_num == 1)
        {
            g_pre_event[pre_index].event = MMI_PEN_INVALID_EVENT;
        }
        else
        {
            g_pre_event[pre_index].event = drv_evt->points[i].event;
            g_pre_event[i].x_adc = drv_evt->points[i].x;
			g_pre_event[i].y_adc = drv_evt->points[i].y;
        }
        if(MMI_FALSE == mmi_touch_ignore_drv_evt(drv_evt->points[0].event))
        {
            return MMI_FALSE;
        }
        return MMI_TRUE;
    }


    /*because pen up event from driver do not send by sequence, it always put at the end, 
      we should put the pen up in the right position. The criterion is distance. But any
      criterion maybe wrong, since finger can move so randomly. When our criterion fail, 
      we just use the driver event sequence.
    */
    if (up_num  > 0)
    {
         for(i=0; i< drv_evt->model; i++)
         {
            if ((drv_evt->points[i].event != DCL_PEN_DOWN) && (drv_evt->points[i].event != DCL_STROKE_DOWN) &&
                (drv_evt->points[i].event != DCL_PEN_UP) && (drv_evt->points[i].event != DCL_STROKE_UP))
        {
            min_distance = 0xffffffff;                      
            for(pre_index=0; pre_index<MMI_FRM_MULTI_TOUCH_MAX_FINGER; pre_index++)
            {   
                if(g_pre_event[pre_index].event == MMI_PEN_INVALID_EVENT)
                {
					first_empty = pre_index;
                    break;
                }
                else
                {
                    U16 x = g_pre_event[pre_index].x_adc;
                    U16 y = g_pre_event[pre_index].y_adc;
                    distance = (drv_evt->points[i].x - x) * (drv_evt->points[i].x -x) + 
                               (drv_evt->points[i].y - y) * (drv_evt->points[i].y - y);      

                    if (distance < min_distance)
                    {
                        min_distance = distance;
                        array[i] = pre_index;
                    }
                }
            }
        }
		else if((drv_evt->points[i].event == DCL_PEN_DOWN) || (drv_evt->points[i].event == DCL_STROKE_DOWN))// pen down or stroke down, put the event in the buffer
		{
			g_pre_event[first_empty].x_adc = drv_evt->points[i].x;
			g_pre_event[first_empty].y_adc = drv_evt->points[i].y;
			g_pre_event[first_empty].event = drv_evt->points[i].event;
			array[i] = first_empty;
			first_empty++;
			//MMI_ASSERT(first_empty<MMI_FRM_MULTI_TOUCH_MAX_FINGER);
		}
       }
    }
    //handle pen up case, put the pen up in the right position
    while (up_num > 0)
    {
        for(pre_index=0; pre_index<MMI_FRM_MULTI_TOUCH_MAX_FINGER; pre_index++)
        {
            if (g_pre_event[pre_index].event == MMI_PEN_INVALID_EVENT)
            {
                break;
            }
            else
            {
                for(i=0; i< drv_evt->model; i++)
                {
                    if(array[i] == pre_index)
                    {
                        break;
                    }
                
    }
                //not find the pre buffer index in the array, we will add pen up to it.
                if (i == drv_evt->model)
                {
                    //MMI_ASSERT(pen_up_index[up_num - 1] != 0Xff);
                    array[pen_up_index[up_num - 1]] = pre_index;
                    
}

            }
                
        }
		up_num--;
    }

    //our reorder mechanism fail, we just use driver event sequence
    for(i=0; i<drv_evt->model; i++)
    {
        MMI_BOOL to_break = MMI_FALSE;
        for(j = i+1;j<drv_evt->model; j++)
        {
            if(array[i] == array[j])
            {
                array[0] = 0;
                array[1] = 1;
                array[2] = 2;
                array[3] = 3;
                array[4] = 4;
                break;
                to_break = MMI_TRUE;
            }
        }
        if(to_break)
        {
            break;
        }   
    }
     // move the event buffer to the right sequence
    for(i=0; i< drv_evt->model; i++)
    {
        U8 index = array[i];
        temp[index].x_adc = drv_evt->points[i].x;
        temp[index].y_adc = drv_evt->points[i].y;
        temp[index].event = drv_evt->points[i].event;
    }
    for(i=0; i< drv_evt->model; i++)
    {
        drv_evt->points[i].event = temp[i].event;
        g_pre_event[i].event = temp[i].event;
		if ((g_pre_event[i].event != DCL_PEN_UP) && (g_pre_event[i].event != DCL_STROKE_UP))
		{
			drv_evt->points[i].x = temp[i].x_adc;
			drv_evt->points[i].y = temp[i].y_adc;
			g_pre_event[i].x_adc = temp[i].x_adc;
			g_pre_event[i].y_adc = temp[i].y_adc;
		}
		else
		{
			drv_evt->points[i].x = g_pre_event[i].x_adc;
			drv_evt->points[i].y = g_pre_event[i].y_adc;
		}
    }

	for (i=0; i<drv_evt->model; i++)
    {
        if((g_pre_event[i].event == DCL_PEN_UP) ||(g_pre_event[i].event == DCL_STROKE_UP))
        {
            memmove(&g_pre_event[i], &g_pre_event[i+1],  sizeof(mmi_pen_event_struct)*(MMI_FRM_MULTI_TOUCH_MAX_FINGER-1-i) );
            g_pre_event[MMI_FRM_MULTI_TOUCH_MAX_FINGER-1].event = MMI_PEN_INVALID_EVENT;
			i--;
        }
    }

    if(MMI_FALSE == mmi_touch_ignore_drv_evt(drv_evt->points[0].event))
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_lookahead_buffer_fill_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_lookahead_buffer_fill_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* AT command mode */
    if (g_pen_simulate_driver_cntx.is_AT_command)
    {
        if ((g_frm_touch_queue.write == 0) && (g_pen_simulate_driver_cntx.is_pen_down == 0))
        {
            //g_pen_simulate_driver_cntx.is_AT_command = 0;
            #ifdef __MTK_TARGET__
            mmi_pen_drv_enable(MMI_TRUE);
            mmi_pen_drv_reset(MMI_TRUE);
            #endif/*__MTK_TARGET__*/
            memset(&g_pen_simulate_driver_cntx, 0x00, sizeof(g_pen_simulate_driver_cntx));
            return; /* Exit point */
        }
    }
    /* Modis or Target */
    else
    {
        #if defined(__MTK_TARGET__)
        STS_CTRL_GET_T drv_evt;
        /* Get from target ring buffer */
        while (((g_pen_cntx.touch_mode == MMI_FRM_SINGLE_TOUCH) && (g_frm_touch_queue.write < MMI_PEN_LOOKAHEAD_BUFFER_SIZE))
                ||(g_pen_cntx.touch_mode == MMI_FRM_MULTI_TOUCH) && (g_frm_touch_queue.write < (QUEUE_SIZE-46)))
        {
            if (mmi_pen_drv_get_event(&drv_evt))
        	{
            	#if defined(__TOUCH_PANEL_CAPACITY__)
              	if(mmi_touch_reorder_event((TouchPanelMultipleEventStruct*)&drv_evt))
              	{
              	#endif
                  	mmi_touch_enqueue((TouchPanelMultipleEventStruct*)&drv_evt);
              	#if defined(__TOUCH_PANEL_CAPACITY__)
              	}
              	#endif
            }
            else
            {
                break;    
            
            }
        }
          
        if (g_frm_touch_queue.write == 0)
        {
            return; /* Exit point */
        }
        #else /* __MTK_TARGET__ */

        if (g_frm_touch_queue.write == 0)
        {
            return; /* Exit point */
        }
        #endif /* __MTK_TARGET__ */
    }

    if(g_pen_cntx.touch_mode == MMI_FRM_SINGLE_TOUCH)
    {
        mmi_pen_lookahead_buffer_filter_data();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_lookahead_buffer_peek_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  touch_data      [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool mmi_pen_lookahead_buffer_peek_event(mmi_pen_event_struct *touch_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_event_struct* lookahead_buffer = (mmi_pen_event_struct*)g_frm_touch_queue.queue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_lookahead_buffer_fill_data();
    
    if (g_frm_touch_queue.write > 0)
    {
        *touch_data = lookahead_buffer[0];
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  if_has_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  touch_data      [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL if_has_pen_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //fill the touch event in the queue, if it is single touch mode, do the filter.
    mmi_pen_lookahead_buffer_fill_data();

    if (g_frm_touch_queue.write > 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}





static void singel_touch_get_event(mmi_pen_event_struct* touch_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 x, y;
    mmi_pen_event_struct*  lookahead_buffer = (mmi_pen_event_struct*)g_frm_touch_queue.queue;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x = lookahead_buffer[0].x_adc;
    y = lookahead_buffer[0].y_adc;
    #ifdef __MMI_SCREEN_ROTATE__
    if (mmi_frm_get_screen_rotate() != MMI_FRM_SCREEN_ROTATE_0)
    {   
        gdi_rotate_map_absolute_hw_to_lcd(&x, &y);
	    lookahead_buffer[0].x_adc = (S16)x;
	    lookahead_buffer[0].y_adc = (S16)y;	
    			
    }
    #endif /* __MMI_SCREEN_ROTATE__ */

    /* For capacity touch panel, do the touch shift, user posision in mind and the actual position
       is usually not the same, they have a shift distance */
    #if defined(__TOUCH_PANEL_CAPACITY__) && defined(__MTK_TARGET__)
    if ((lookahead_buffer[0].event != DCL_STROKE_DOWN) && (lookahead_buffer[0].event != DCL_STROKE_MOVE) && 
        (lookahead_buffer[0].event != DCL_STROKE_UP) && (lookahead_buffer[0].event != DCL_STROKE_LONGTAP))
    {
        if (y < UI_device_height- MMI_FRM_TOUCH_FINGER_WIDTH)
        {
            y -= MMI_FRM_TOUCH_FINGER_WIDTH >> 1;
        }
        else
        {
            y -= (UI_device_height - y) >> 1;
        }

        if (y < 0)
        {
           y = 0;
        }
        lookahead_buffer[0].y_adc = y;
    }
    #endif
    
    *touch_data = lookahead_buffer[0];
    g_frm_touch_queue.write--;
    for (i = 0; i < g_frm_touch_queue.write; i++)
    {
        lookahead_buffer[i] = lookahead_buffer[i + 1];
    }
}


static void update_pre_touch_data(void)
{
    U32 i;
    U32 merge_num = g_multi_touch_event.touch_data[0].merge_num;
    for(i=0; i<g_multi_touch_event.touch_num; i++)
    {
        g_frm_finger_info[i].pre_event = g_multi_touch_event.touch_data[i].event;
        if (merge_num> 0)
        {
            g_frm_finger_info[i].pre_touch_pos.pos = g_multi_touch_event.touch_data[i].merge_points[merge_num -1].pos;
            g_frm_finger_info[i].pre_touch_pos.timestamp = g_multi_touch_event.touch_data[i].merge_points[merge_num -1].timestamp;
        }
        else
        {
             g_frm_finger_info[i].pre_touch_pos.pos  = g_multi_touch_event.touch_data[i].currpos.pos;
             g_frm_finger_info[i].pre_touch_pos.timestamp = g_multi_touch_event.touch_data[i].currpos.timestamp;
        }
        
    }

    for (i=0; i<g_multi_touch_event.touch_num; i++)
    {
        if((g_frm_finger_info[i].pre_event == MMI_PEN_EVENT_UP) ||(g_frm_finger_info[i].pre_event == MMI_STROKE_UP))
        {
            memmove(&g_frm_finger_info[i], &g_frm_finger_info[i+1],  sizeof(mmi_frm_finger_info_struct)*(MMI_FRM_MULTI_TOUCH_MAX_FINGER-1-i) );
            g_frm_finger_info[g_multi_touch_event.touch_num-1].pre_event = MMI_PEN_INVALID_EVENT;
			i--;
        }
    }
}

#if defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)

static MMI_BOOL multi_touch_get_event(void)
{
       /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j, k;
    MMI_BOOL no_merge = MMI_FALSE;
    U32 count  =0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_frm_touch_queue.write == 0)
    {
        return MMI_FALSE;
    }
    //multi-touch mode, if needs to merge event
    for (i= 0; i< g_frm_touch_queue.write;)
    {
        
        for(j=0; j< g_frm_touch_queue.queue[i]; j++)
        {   
            if(g_frm_touch_queue.queue[i+4+4*j] != DCL_PEN_MOVE)
            {
                
                no_merge = MMI_TRUE;
                break;
            }
        }
        if(no_merge)
        {
            break;
        }
        else
        {
            count++;
        }
        //finger number
        i=i+3+4*g_frm_touch_queue.queue[i];
    }
    
    // need to send several events together to app proc
    if(count == 0)
        count++;

    // mmi_multi_touch_event_struct g_multi_touch_event;
    //mmi_touch_pos_struct g_multi_touch_merge_array[MMI_FRM_MULTI_TOUCH_MAX_FINGER][MERGE_MAX_POINTS + 1];
    g_multi_touch_event.touch_num = g_frm_touch_queue.queue[0];
    for(k=0; k<g_multi_touch_event.touch_num; k++)
    {
        
        g_multi_touch_event.touch_data[k].merge_num = count - 1;
        g_multi_touch_event.touch_data[k].merge_num = (g_multi_touch_event.touch_data[k].merge_num > MERGE_MAX_POINTS) ? MERGE_MAX_POINTS : g_multi_touch_event.touch_data[k].merge_num;
        g_multi_touch_event.touch_data[k].event = switch_touch_event(g_frm_touch_queue.queue[1+4*k+3]);
        g_multi_touch_event.touch_data[k].area =  g_frm_touch_queue.queue[1+4*k+2];
        g_multi_touch_event.touch_data[k].currpos.pos.x = g_frm_touch_queue.queue[1+4*k];
        g_multi_touch_event.touch_data[k].currpos.pos.y = g_frm_touch_queue.queue[1+4*k+1];
		//g_multi_touch_event.touch_data[k].currpos.timestamp = *((U32 *)(&(g_frm_touch_queue.queue[1+4*g_multi_touch_event.touch_num])));
        g_multi_touch_event.touch_data[k].currpos.timestamp = (g_frm_touch_queue.queue[1+4*g_multi_touch_event.touch_num+1]<< 16) & 0xFFFF0000;
        g_multi_touch_event.touch_data[k].currpos.timestamp |= g_frm_touch_queue.queue[1+4*g_multi_touch_event.touch_num]; 
        if ((g_multi_touch_event.touch_data[k].event == MMI_PEN_EVENT_DOWN) || (g_multi_touch_event.touch_data[k].event == MMI_STROKE_DOWN))
        {
            g_multi_touch_event.touch_data[k].pre_event = MMI_PEN_INVALID_EVENT;
            g_multi_touch_event.touch_data[k].pre_pos.pos.x = 0;
            g_multi_touch_event.touch_data[k].pre_pos.pos.y = 0;
            g_multi_touch_event.touch_data[k].pre_pos.timestamp = 0;
            g_multi_touch_event.touch_data[k].down_pos = g_frm_finger_info[k].touch_down_info = g_multi_touch_event.touch_data[k].currpos;
            g_multi_touch_event.touch_data[k].id  = g_frm_finger_info[k].id =  g_pen_cntx.new_id++;
        }
        else
        {
            g_multi_touch_event.touch_data[k].id = g_frm_finger_info[k].id;
            g_multi_touch_event.touch_data[k].pre_event = g_frm_finger_info[k].pre_event;
            g_multi_touch_event.touch_data[k].pre_pos = g_frm_finger_info[k].pre_touch_pos;

            g_multi_touch_event.touch_data[k].down_pos = g_frm_finger_info[k].touch_down_info;
            if(g_multi_touch_event.touch_data[k].merge_num > 0)
            {
				g_multi_touch_event.touch_data[k].merge_points = g_multi_touch_merge_array[k];
				g_multi_touch_event.touch_data[k].merge_area = g_merge_pressure[k];
                for (j=1; j<=g_multi_touch_event.touch_data[k].merge_num; j++)
                {
                    U32 index = (4*g_multi_touch_event.touch_num+3)*j+1;
					//MMI_ASSERT( ); // the finger number should be the same
                    //g_multi_touch_merge_array[k][j-1].timestamp = *((U32 *)(&(g_frm_touch_queue.queue[index+4*g_multi_touch_event.touch_num])));
                    g_multi_touch_merge_array[k][j-1].timestamp = (g_frm_touch_queue.queue[index+4*g_multi_touch_event.touch_num+1]<< 16) & 0xFFFF0000;
                    g_multi_touch_merge_array[k][j-1].timestamp  |= g_frm_touch_queue.queue[index+4*g_multi_touch_event.touch_num];
                    g_multi_touch_merge_array[k][j-1].pos.x = g_frm_touch_queue.queue[index+4*k];
                    g_multi_touch_merge_array[k][j-1].pos.y = g_frm_touch_queue.queue[index+4*k+1];
                    g_merge_pressure[k][j-1] = g_frm_touch_queue.queue[index+4*k+2];
                }
                
            }
            else
            {
                g_multi_touch_event.touch_data[k].merge_points = 0;
            }
            
            
        }        
    }
	memmove(g_frm_touch_queue.queue, &g_frm_touch_queue.queue[count*(3+g_multi_touch_event.touch_num*4)], sizeof(multi_touch_queue) - sizeof(U16)*count*(2+g_multi_touch_event.touch_num*3));
    g_frm_touch_queue.write -= count*(3+g_multi_touch_event.touch_num*4) ;	
    return MMI_TRUE;
}

static void multi_touch_get_abort_event(void)
{
    U32 i = 0;
    for (i=0; i < g_multi_touch_event.touch_num; i++)
    {
        g_multi_touch_event.touch_data[i].merge_num = 0;
        g_multi_touch_event.touch_data[i].event = MMI_PEN_EVENT_ABORT;
        g_multi_touch_event.touch_data[i].currpos = g_frm_finger_info[i].pre_touch_pos;
        g_multi_touch_event.touch_data[i].id = g_frm_finger_info[i].id;
        g_multi_touch_event.touch_data[i].merge_points = NULL;
        g_multi_touch_event.touch_data[i].pre_event = g_frm_finger_info[i].pre_event;
        g_multi_touch_event.touch_data[i].pre_pos = g_frm_finger_info[i].pre_touch_pos;
        g_multi_touch_event.touch_data[i].down_pos = g_frm_finger_info[i].touch_down_info;
    }
}
#endif

#ifdef __MMI_TOUCH_PANEL_SHORTCUT__
/*****************************************************************************
 * FUNCTION
 *  mmi_pen_check_tp_shortcut
 * DESCRIPTION
 *  This function used for check whether is the pen event's location in touch
 *  panel shortcut's region. If the location is in the region, it will call
 *  the related shortcut handler.
 *  If the type of pen event is DCL_STROKE_MOVE or DCL_STROKE_UP, it will fix the 
 *  location to the nearest LCD boundary.
 * PARAMETERS
 *  pos         [IN/OUT]        The pen event's location.
 *  event       [IN]            The type of pen event.
 * RETURNS
 *  Returns MMI_TURE if the shortcut handler processed the pen event,
 *  otherwise returns MMI_FALSE. 
 *****************************************************************************/
static MMI_BOOL mmi_pen_check_tp_shortcut(mmi_pen_point_struct *pos, DCL_TP_Event_enum event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 0; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_PEN_TRC_CHECK_TP_SHORTCUT, pos->x, pos->y, event);
    if (mmi_pen_check_inside_polygon((mmi_pen_polygon_area_struct*)(&g_tp_shortcut_total_polygon), *pos))
    {
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_PEN_TRC_CHECK_TP_SHORTCUT_AREA, TP_SHORTCUT_NUMBER);
        if ((DCL_STROKE_MOVE == event)||(DCL_STROKE_UP == event))
        {
            pos->y = LCD_HEIGHT - 1;
        }
        else if (mmi_idle_is_active())
        {
            while (count < TP_SHORTCUT_NUMBER)
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_PEN_TRC_CHECK_TP_SHORTCUT_AREA, count);
                if (mmi_pen_check_inside_polygon
                    ((mmi_pen_polygon_area_struct*) (&(g_tp_shortcut_area_tbl[count].polygon)), *pos))
                {
                    switch (event)
                    {
                        case DCL_PEN_DOWN:
                            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_PEN_TRC_CHECK_TP_SHORTCUT_DOWN, count);
                            return g_tp_shortcut_area_tbl[count].hdlr(*pos, MMI_PEN_EVENT_DOWN);
                            
                        case DCL_PEN_UP:
                            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_PEN_TRC_CHECK_TP_SHORTCUT_UP, count);
                            return g_tp_shortcut_area_tbl[count].hdlr(*pos, MMI_PEN_EVENT_UP);

                        case DCL_PEN_MOVE:
                            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_PEN_TRC_CHECK_TP_SHORTCUT_MOVE, count);
                            return g_tp_shortcut_area_tbl[count].hdlr(*pos, MMI_PEN_EVENT_MOVE);
                            
                        case DCL_PEN_LONGTAP:
                            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_PEN_TRC_CHECK_TP_SHORTCUT_LONGTAP, count);
                            return g_tp_shortcut_area_tbl[count].hdlr(*pos, MMI_PEN_EVENT_LONG_TAP);
                            
                        case DCL_PEN_REPEAT:
                            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_PEN_TRC_CHECK_TP_SHORTCUT_REPEAT, count);
                            return g_tp_shortcut_area_tbl[count].hdlr(*pos, MMI_PEN_EVENT_REPEAT);

                        case DCL_PEN_ABORT:
                            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_PEN_TRC_CHECK_TP_SHORTCUT_ABORT, count);
                            return g_tp_shortcut_area_tbl[count].hdlr(*pos, MMI_PEN_EVENT_ABORT);

                        default:
                            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_PEN_TRC_CHECK_TP_SHORTCUT_DEFAULT, count);
                            return MMI_FALSE;                        
                    }
                }
                count++;
            }
        }
    }
    return MMI_FALSE;    
}
#endif /* __MMI_TOUCH_PANEL_SHORTCUT__ */ 

void mmi_frm_touch_register_proc(mmi_proc_func proc, void *user_data)
{
    g_mmi_frm_touch_proc.touch_proc = proc;
    g_mmi_frm_touch_proc.user_data = user_data;
}


void mmi_frm_touch_screen_switch_action(void)
{

    mmi_frm_touch_set_mode(MMI_FRM_SINGLE_TOUCH);
    mmi_frm_touch_register_proc(NULL, NULL);
}


static mmi_pen_event_type_enum switch_touch_event(DCL_TP_Event_enum event)
{
	mmi_pen_event_type_enum event_id = MMI_PEN_INVALID_EVENT;
    switch(event)
    {
        case DCL_PEN_DOWN:
            event_id = MMI_PEN_EVENT_DOWN;
            break;
            
        case DCL_PEN_MOVE:
            event_id = MMI_PEN_EVENT_MOVE;
            break;
        case DCL_PEN_UP:
        
            event_id = MMI_PEN_EVENT_UP;
            break;
        case DCL_PEN_LONGTAP:
            event_id =MMI_PEN_EVENT_LONG_TAP;
            break;
        case DCL_PEN_REPEAT:
            event_id =MMI_PEN_EVENT_REPEAT;
            break; 
        case DCL_PEN_ABORT:
            event_id =MMI_PEN_EVENT_ABORT;
            break;
        case DCL_STROKE_DOWN:
            event_id = MMI_STROKE_DOWN;
            break;
        case DCL_STROKE_MOVE:
            event_id = MMI_STROKE_MOVE;
            break;
        case DCL_STROKE_UP:
            event_id = MMI_STROKE_UP;
            break;
        case DCL_STROKE_LONGTAP:
            event_id = MMI_STROKE_LONGTAP;
            break;
        case DCL_STROKE_STATICAL:
            event_id = MMI_STROKE_STATICAL;
            break;
        case DCL_STROKE_HOLD:
            event_id = MMI_STROKE_HOLD;
            break;
        case DCL_PEN_LONGTAP_HOLD:
            event_id = MMI_PEN_LONGTAP_HOLD;
            break;
        case DCL_PEN_REPEAT_HOLD:
            event_id = MMI_PEN_REPEAT_HOLD;
            break;
        case DCL_TP_UNKNOWN_EVENT:
			event_id = MMI_PEN_INVALID_EVENT;
            MMI_ASSERT(0);
            break;
    }
    return event_id;

}


static void calculate_main_point(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/*
	 * Set the maint point as the first point
	 */
	g_multi_touch_event.main_point = g_multi_touch_event.touch_data[0];
#if defined(__TOUCH_PANEL_MULTITOUCH__) && !defined(__TOUCH_PANEL_CAPACITY__)

    /*
     * If RTP, Multi-Touch Screen, two finger down, correct the pos as the middle point
     */
    if (g_multi_touch_event.touch_num == 2)
    {
    	/*
    	 * Single and Multi-Touch Mode will correct the main point position
    	 */
        g_multi_touch_event.main_point.currpos.pos.x = 
		    (g_multi_touch_event.touch_data[0].currpos.pos.x + g_multi_touch_event.touch_data[1].currpos.pos.x) / 2;
		g_multi_touch_event.main_point.currpos.pos.y =
			(g_multi_touch_event.touch_data[0].currpos.pos.y + g_multi_touch_event.touch_data[1].currpos.pos.y) / 2;
    }
#endif

}


static void excecute_pen_event(mmi_pen_event_struct* pen_event, U16 evt_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;
    mmi_pen_point_struct pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&g_multi_touch_event, EVT_ID_PRE_TOUCH_EVT_ROUTING);
    g_multi_touch_event.touch_num = 1;
    g_multi_touch_event.touch_data[0].id = 0;
    if(evt_type == MMI_PEN_EVENT_DOUBLE_CLICK)
    {
        g_multi_touch_event.touch_data[0].event = MMI_PEN_EVENT_DOUBLE_CLICK;
    }
    else
    {
        g_multi_touch_event.touch_data[0].event = switch_touch_event(pen_event->event);
    }
    g_multi_touch_event.touch_data[0].currpos.pos.x = pen_event->x_adc;
    g_multi_touch_event.touch_data[0].currpos.pos.y = pen_event->y_adc;

    g_multi_touch_event.touch_data[0].currpos.timestamp = pen_event->time_stamp;
    g_multi_touch_event.touch_data[0].area = pen_event->z;
    g_multi_touch_event.touch_data[0].down_pos =  g_frm_finger_info[0].touch_down_info;
    g_multi_touch_event.touch_data[0].pre_event = g_frm_finger_info[0].pre_event; 
    g_multi_touch_event.touch_data[0].pre_pos = g_frm_finger_info[0].pre_touch_pos;
    g_multi_touch_event.touch_data[0].merge_num = 0;
    g_multi_touch_event.touch_data[0].merge_points = NULL;
    g_multi_touch_event.touch_data[0].merge_area = NULL;
	calculate_main_point();
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_EXECUTE_PEN_HANDLER, g_multi_touch_event.touch_data[0].event, g_multi_touch_event.touch_data[0].currpos.pos.x, 
              g_multi_touch_event.touch_data[0].currpos.pos.y);
    ret = MMI_FRM_CB_EMIT_EVENT(&g_multi_touch_event);
    pos = g_multi_touch_event.touch_data[0].currpos.pos;


    if (ret != MMI_RET_STOP_TOUCH_HANDLE)
    {
        g_multi_touch_event.evt_id = EVT_ID_ON_TOUCH;  
        if((pen_event->event == DCL_STROKE_DOWN) ||(pen_event->event == DCL_STROKE_UP) || (pen_event->event == DCL_STROKE_MOVE) ||
           (pen_event->event == DCL_STROKE_LONGTAP))
        {   
              

            if (g_mmi_frm_touch_proc.touch_proc != NULL)
            {
                MMI_FRM_SEND_EVENT(&g_multi_touch_event, g_mmi_frm_touch_proc.touch_proc, g_mmi_frm_touch_proc.user_data);   
            }
            else if(g_pen_stroke_table[evt_type])
            {
                (g_pen_stroke_table[evt_type]) (pos);
            }

            
        }
        else
        {

            if (g_mmi_frm_touch_proc.touch_proc != NULL)
            {
                MMI_FRM_SEND_EVENT(&g_multi_touch_event, g_mmi_frm_touch_proc.touch_proc, g_mmi_frm_touch_proc.user_data);   
            }
            else if (g_pen_event_table[evt_type])
            {

                (g_pen_event_table[evt_type]) (pos);
            }
        }
    }
    g_multi_touch_event.evt_id = EVT_ID_POST_TOUCH_EVT_ROUTING;
    MMI_FRM_CB_EMIT_EVENT(&g_multi_touch_event);
    update_pre_touch_data();
}

#if defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)
void handle_multi_touch_event(void)
{
    mmi_ret ret = MMI_RET_OK;
    // multi touch routing mechanism
    while(multi_touch_get_event())
    {
    
        if(g_multi_touch_event.touch_data[0].event == MMI_PEN_EVENT_ABORT)
        {
            g_pen_drvq_full_abort = MMI_TRUE;
            mmi_pen_reset();
            break;
        }
        update_pre_touch_data(); 
    
        if (g_frm_finger_info[0].pre_event == MMI_PEN_EVENT_DOWN) 
        {
            mmi_frm_nmgr_control_end();
            //MMI_ASSERT(g_pen_cntx.new_id == 1);
            g_pen_cntx.is_pen_down  = 1;
            g_pen_cntx.is_in_pen_handler = 1;
            g_pen_cntx.pen_down_pos= g_frm_finger_info[0].pre_touch_pos;
        }
        //if all up
        else if (g_frm_finger_info[0].pre_event == MMI_PEN_INVALID_EVENT)
        {
            g_pen_cntx.new_id  = 0;
            g_pen_cntx.is_pen_down = 0; 
            g_pen_cntx.is_in_pen_handler = 0;
         }
        g_multi_touch_event.evt_id = EVT_ID_PRE_TOUCH_EVT_ROUTING;
        calculate_main_point();
        ret = MMI_FRM_CB_EMIT_EVENT(&g_multi_touch_event);
        if (ret != MMI_RET_STOP_TOUCH_HANDLE)
        {
    
            if(g_mmi_frm_touch_proc.touch_proc != NULL)
            {   
                g_multi_touch_event.evt_id = EVT_ID_ON_TOUCH;
                //send event to proc
                MMI_FRM_SEND_EVENT(&g_multi_touch_event, g_mmi_frm_touch_proc.touch_proc, g_mmi_frm_touch_proc.user_data);  
            }
    
    
        }            
        g_multi_touch_event.evt_id = EVT_ID_POST_TOUCH_EVT_ROUTING;
        MMI_FRM_CB_EMIT_EVENT(&g_multi_touch_event);
        mmi_frm_invoke_post_event();
    
    }

}
#endif

void handle_single_touch_event(void)
{
    mmi_pen_event_struct data;
    U16      interval = 0;
    mmi_pen_point_struct pos;
    singel_touch_get_event(&data);
#ifdef __VENUS_UI_ENGINE__
    if (data.event == DCL_PEN_MOVE && vadp_p2v_uc_is_in_venus() && g_pen_cntx.has_pen_move == 1)
    {
        mmi_pen_event_struct temp;
        if (mmi_pen_lookahead_buffer_peek_event(&temp) == KAL_TRUE)
        {
            if (temp.event == DCL_PEN_UP)
            {
                singel_touch_get_event(&data);
            }
        }
    }
#endif
    pos.x = (S16) data.x_adc;
    pos.y = (S16) data.y_adc;
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_PEN_DRV_EVENT, data.event, pos.x, pos.y, data.time_stamp);

#ifdef __MMI_TOUCH_PANEL_SHORTCUT__
    if(!mmi_pen_check_tp_shortcut(&pos, data.event))
#endif /* __MMI_TOUCH_PANEL_SHORTCUT__ */
    {

        g_pen_cntx.pen_current_pos = pos;
        g_pen_cntx.pen_event = data.event;

        switch (data.event)
        {
                /* Call pen handler after setting context variables because pen handler might invoke mmi_pen_reset() */
            case DCL_PEN_DOWN:
                g_pen_cntx.is_pen_down = 1;
                /* leave pen handler procedure */
                g_pen_cntx.is_in_pen_handler = 1;
                
                g_pen_cntx.has_pen_move = 0;

				if (g_pen_cntx.is_send_event_to_new_screen)
				{
					g_pen_cntx.is_sw_pen_down = 1;
				}

                /* calculate the interval between twice pen down */
                if (g_pen_cntx.previous_pen_down_time > data.time_stamp)
                {
                    interval = 0XFFFF - g_pen_cntx.previous_pen_down_time + data.time_stamp;
                }
                else
                {
                    interval = data.time_stamp - g_pen_cntx.previous_pen_down_time;
                }

                /* check whether it is double click */
                if ((interval <= MMI_PEN_DOUBLE_CLICK_THRESHOLD) && 
                    (mmi_pen_get_distance_square(g_pen_cntx.pen_down_pos.pos, pos) < MMI_PEN_SKIP_DOUBLE_CLICK_OFFSET_SQUARE))
                {                        
                    excecute_pen_event(&data, MMI_PEN_EVENT_DOUBLE_CLICK);
                    g_pen_cntx.previous_pen_down_time = 0;
                }
                else
                {
                    g_pen_cntx.previous_pen_down_time = data.time_stamp;
                }

                g_frm_finger_info[0].touch_down_info.pos = g_pen_cntx.pen_down_pos.pos = pos;
                g_frm_finger_info[0].touch_down_info.timestamp = g_pen_cntx.pen_down_pos.timestamp = data.time_stamp;
                
            #ifdef __MMI_INTERACTIVE_PROFILNG__
                    mmi_frm_profiling_interactive_start3();
            #endif /* __MMI_INTERACTIVE_PROFILNG__ */ 
                
                excecute_pen_event(&data, MMI_PEN_EVENT_DOWN);
            #ifdef __MMI_INTERACTIVE_PROFILNG__
                    mmi_frm_profiling_interactive_end3();
            #endif /* __MMI_INTERACTIVE_PROFILNG__ */ 

            #if defined(__MMI_GESTURES_FRAMEWORK__)
                    mmi_frm_gesture_recognise(MMI_PEN_EVENT_DOWN, pos); 
            #endif /* #if defined(__MMI_GESTURES_FRAMEWORK__) */
                 mmi_pen_at_commod_send_report(1, pos.x, pos.y);
                mmi_frm_nmgr_control_end();
                break;
                
            case DCL_PEN_UP:
                if (g_pen_cntx.is_pen_down)
                {
                    g_pen_cntx.is_pen_down = 0;

                #ifdef __MMI_INTERACTIVE_PROFILNG__
                        mmi_frm_profiling_interactive_start2();
                #endif /* __MMI_INTERACTIVE_PROFILNG__ */       
                    excecute_pen_event(&data, MMI_PEN_EVENT_UP);

                #ifdef __MMI_INTERACTIVE_PROFILNG__
                        mmi_frm_profiling_interactive_end2();
                        mmi_frm_profiling_interactive_show((U8*) L"P", MMI_FRM_PROFILING_MASK_2 | MMI_FRM_PROFILING_MASK_3);
                #endif /* __MMI_INTERACTIVE_PROFILNG__ */ 
    
                #if defined(__MMI_GESTURES_FRAMEWORK__)
                        mmi_frm_gesture_recognise(MMI_PEN_EVENT_UP, pos);
                #endif /* #if defined(__MMI_GESTURES_FRAMEWORK__) */
    
                    if (g_pen_cntx.reset_stroke_on_pen_up)
                    {
                        if (g_pen_stroke_max_points > 0)
                        {
                            mmi_pen_end_strokes_of_character();
                            mmi_pen_reset();
                            mmi_pen_begin_strokes_of_character();
                        }
                        else
                        {
                            mmi_pen_reset();
                        }
                    }
    
                    /* Delay processing futher events */
                    g_pen_cntx.is_send_event_to_new_screen = MMI_FALSE;
					g_pen_cntx.is_sw_pen_down = 0;
                    /* leave pen handler procedure */
                    g_pen_cntx.is_in_pen_handler = 0;
                    g_pen_cntx.pen_event = DCL_TP_UNKNOWN_EVENT;
                    mmi_pen_at_commod_send_report(0, pos.x, pos.y);
                }
                break;
                
            case DCL_PEN_MOVE:
                if(g_pen_cntx.is_pen_down)
                {
                	  g_pen_cntx.has_pen_move = 1;
                    excecute_pen_event(&data, MMI_PEN_EVENT_MOVE);

                #if defined(__MMI_GESTURES_FRAMEWORK__)
                        mmi_frm_gesture_recognise(MMI_PEN_EVENT_MOVE, pos);
                #endif /* #if defined(__MMI_GESTURES_FRAMEWORK__) */
                    mmi_pen_at_commod_send_report(1, pos.x, pos.y);
                }
                break;
                
            case DCL_PEN_LONGTAP:
                if(g_pen_cntx.is_pen_down)
                {
                    excecute_pen_event(&data, MMI_PEN_EVENT_LONG_TAP);

                #if defined(__MMI_GESTURES_FRAMEWORK__)
                      mmi_frm_gesture_recognise(MMI_PEN_EVENT_LONG_TAP, pos);
                #endif /* #if defined(__MMI_GESTURES_FRAMEWORK__) */
                    //mmi_pen_at_commod_send_report(1, pos.x, pos.y);
                }
                break;
                
            case DCL_PEN_REPEAT:
                if(g_pen_cntx.is_pen_down)
                {
                    excecute_pen_event(&data, MMI_PEN_EVENT_REPEAT);
                
                #if defined(__MMI_GESTURES_FRAMEWORK__)
                        mmi_frm_gesture_recognise(MMI_PEN_EVENT_REPEAT, pos);
                #endif /* #if defined(__MMI_GESTURES_FRAMEWORK__) */
                    //mmi_pen_at_commod_send_report(1, pos.x, pos.y);
                }
                break;
                
            case DCL_PEN_ABORT:
                /* Driver queue full */
		        g_pen_drvq_full_abort = MMI_TRUE;
                mmi_pen_reset();
                break;
                
            case DCL_TP_UNKNOWN_EVENT:
                MMI_ASSERT(0);
                break;
                
            case DCL_STROKE_MOVE:
                /* mmi_pen_reset() should be used after mmi_pen_stop_capture_strokes() such that enqueued stroke events are flushed. */
                if(!g_pen_cntx.is_pen_down)
                {
                    break;
                }
                if (g_pen_cntx.is_pending_stroke_event)
                {
                    if (mmi_pen_get_distance_square(g_pen_cntx.pen_down_pos.pos, pos) > g_pen_stroke_min_offset_square)
                    {
                        g_pen_cntx.is_pending_stroke_event = 0;
                        
                        /* Pen Down -> Pen Move -> Pen Abort -> Stroke Down -> Stroke Move -> Stroke Up 
                           There is no stroke points queued before the first stroke is created
                           If we set 'reset_stroke_on_pen_up' in previous Pen Down handler and invoke mmi_pen_reset() in Stroke Up, 
                           all stroke points in between are discarded */
                        g_pen_cntx.reset_stroke_on_pen_up = 0;
                        data.event = g_pen_cntx.pen_event = DCL_PEN_ABORT;
                        data.x_adc = g_pen_cntx.pen_down_pos.pos.x;
                        data.y_adc = g_pen_cntx.pen_down_pos.pos.y;
                        data.time_stamp = g_pen_cntx.pen_down_pos.timestamp;
                        excecute_pen_event(&data, MMI_PEN_EVENT_ABORT);
                        g_pen_cntx.pen_event = DCL_STROKE_MOVE;

                        /* Handle Stroke Down */
                    #ifdef __MMI_INTERACTIVE_PROFILNG__
                            mmi_frm_profiling_interactive_start3();
                    #endif /* __MMI_INTERACTIVE_PROFILNG__ */
                        g_pen_stroke_min_offset_square = 0; /* The next stroke does not have minimum offset */
                        data.event = DCL_STROKE_DOWN;
                        mmi_pen_push_stroke_point(g_pen_cntx.pen_down_pos.pos.x, g_pen_cntx.pen_down_pos.pos.y);
                        excecute_pen_event(&data, MMI_PEN_STROKE_DOWN);
                    #ifdef __MMI_INTERACTIVE_PROFILNG__
                            mmi_frm_profiling_interactive_end3();
                    #endif /* __MMI_INTERACTIVE_PROFILNG__ */ 

                        g_pen_cntx.pen_event = DCL_STROKE_MOVE;

                        if (g_pen_num_stroke_area > 1)
                        {
                            mmi_pen_fix_multi_block_pen_position(&pos);

                        }

                        /* Stroke Move */
                        data.event = DCL_STROKE_MOVE;
                        data.x_adc = pos.x;
                        data.y_adc = pos.y;
                        mmi_pen_push_stroke_point(pos.x, pos.y);
                        excecute_pen_event(&data, MMI_PEN_STROKE_MOVE);
                    }
                    else
                    {
                        mmi_pen_info_struct pen_info;
                        if ((g_pen_stroke_min_offset_square == MMI_PEN_STROKE_MAX_OFFSET)
                            &&
                            mmi_pen_get_distance_square(pen_info.point, pos) > (MMI_PEN_SKIP_MOVE_OFFSET * MMI_PEN_SKIP_MOVE_OFFSET))
                        {                            
                            data.event = DCL_PEN_MOVE;                 
                            excecute_pen_event(&data, MMI_PEN_EVENT_MOVE);

                         }
                      }
                }
                else
                {
                    if (g_pen_num_stroke_area > 1)
                    {
                        mmi_pen_fix_multi_block_pen_position(&pos);
                        data.x_adc = pos.x;
                        data.y_adc = pos.y;
                    }
                    

                    mmi_pen_push_stroke_point(pos.x, pos.y);
                    
                    excecute_pen_event(&data, MMI_PEN_STROKE_MOVE);
                }
                mmi_pen_at_commod_send_report(1, pos.x, pos.y);
                break;
                
            case DCL_STROKE_DOWN:
                /* mmi_pen_reset() should be used after mmi_pen_stop_capture_strokes() such that enqueued stroke events are flushed. */
                /* leave pen handler procedure */
                g_pen_cntx.is_stroke_down = 1;
                g_pen_cntx.is_pen_down = 1;
                g_frm_finger_info[0].touch_down_info.pos = g_pen_cntx.pen_down_pos.pos = pos;
                g_frm_finger_info[0].touch_down_info.timestamp = g_pen_cntx.pen_down_pos.timestamp = data.time_stamp;

                g_pen_cntx.stroke_down_block_index = mmi_pen_lookup_handwriting_block(pos.x, pos.y);
                if (g_pen_num_stroke_area > 1 && g_pen_cntx.stroke_down_block_index < 0)
                {
                    /* MMI framework and driver have intergration problem.
                       Maybe the current driver does not support multi-block, 
                       or driver does not disable extended handwriting area properly in
                       multi-block mode. */
                    MMI_ASSERT(0);
                }

            #ifdef __MMI_INTERACTIVE_PROFILNG__
                    mmi_frm_profiling_interactive_start3();
            #endif /* __MMI_INTERACTIVE_PROFILNG__ */ 
                if (g_pen_stroke_min_offset_square > 0)
                {
                    g_pen_cntx.is_pending_stroke_event = 1;
                    data.event = g_pen_cntx.pen_event = DCL_PEN_DOWN;
                    excecute_pen_event(&data, MMI_PEN_EVENT_DOWN);
                }
                else
                {
                    g_pen_cntx.is_pending_stroke_event = 0;
                    g_pen_cntx.pen_event = DCL_STROKE_DOWN;
                    excecute_pen_event(&data, MMI_PEN_STROKE_DOWN);
                    
                    /* Put stroke point after stroke down handler because multi-block handwriting may invoke
                     * mmi_pen_begin_strokes_of_character() and mmi_pen_end_strokes_of_character() in 
                     * Stroke Down handler.
                     */
                    if (g_pen_cntx.is_enabled && g_pen_cntx.is_pen_down && g_pen_stroke_max_points > 0)
                    {
                        mmi_pen_push_stroke_point(pos.x, pos.y);
                    }                    
                }
            #ifdef __MMI_INTERACTIVE_PROFILNG__
                    mmi_frm_profiling_interactive_end3();
            #endif /* __MMI_INTERACTIVE_PROFILNG__ */
                mmi_pen_at_commod_send_report(1, pos.x, pos.y);
                mmi_frm_nmgr_control_end();
                break;
                
            case DCL_STROKE_UP:
                /* mmi_pen_reset() should be used after mmi_pen_stop_capture_strokes() such that enqueued stroke events are flushed. */
                if(!g_pen_cntx.is_pen_down)
                {
                    break;
                }
                g_pen_cntx.is_stroke_down = 0;
                g_pen_cntx.is_pen_down = 0;

            #ifdef __MMI_INTERACTIVE_PROFILNG__
                        mmi_frm_profiling_interactive_start2();
            #endif /* __MMI_INTERACTIVE_PROFILNG__ */ 

                if (g_pen_cntx.is_pending_stroke_event)
                {
                    g_pen_cntx.is_pending_stroke_event = 0;

                    /*
                     * Flush driver queue and lookahead buffer:
                     * Otherwise, it might restore handwriting area (touch_panel_reset_handwriting)
                     * while stroke-based mode is already entered.
                     */
                    g_pen_cntx.reset_stroke_on_pen_up = 1;
                    data.event = g_pen_cntx.pen_event = DCL_PEN_UP;
                    excecute_pen_event(&data, MMI_PEN_EVENT_UP);
                    /* Delay processing further events */
                }
                else
                {
                    /* 
                     * Because touch panel can not detect pen position in Stroke Up event,
                     * we do not put the point into stroke queue
                     */
                    g_pen_cntx.pen_event = DCL_STROKE_UP;
                    if (g_pen_num_stroke_area > 1)
                    {
                        mmi_pen_fix_multi_block_pen_position(&pos);
                        data.x_adc = pos.x;
                        data.y_adc = pos.y;
                    }
                    
                    mmi_pen_push_stroke_end();
                    excecute_pen_event(&data, MMI_PEN_STROKE_UP);
                }

                /* Clear strokes and reset handwriting area */
                if (g_pen_cntx.reset_stroke_on_pen_up)
                {
                    if (g_pen_stroke_max_points > 0)
                    {
                        mmi_pen_end_strokes_of_character();
                        mmi_pen_reset();
                        mmi_pen_begin_strokes_of_character();
                    }
                    else
                    {
                        mmi_pen_reset();
                    }
                }
            #ifdef __MMI_INTERACTIVE_PROFILNG__
                    mmi_frm_profiling_interactive_end2();
                    mmi_frm_profiling_interactive_show((U8*) L"S", MMI_FRM_PROFILING_MASK_2 | MMI_FRM_PROFILING_MASK_3);
            #endif /* __MMI_INTERACTIVE_PROFILNG__ */ 

                /* leave pen handler procedure */
                g_pen_cntx.is_send_event_to_new_screen = MMI_FALSE;
				g_pen_cntx.is_sw_pen_down = 0;
                g_pen_cntx.is_in_pen_handler = 0;
                g_pen_cntx.pen_event = DCL_TP_UNKNOWN_EVENT;
                mmi_pen_at_commod_send_report(0, pos.x, pos.y);

                break;

            case DCL_STROKE_LONGTAP:
            case DCL_STROKE_STATICAL:
            case DCL_STROKE_HOLD:
            case DCL_PEN_REPEAT_HOLD:
            case DCL_PEN_LONGTAP_HOLD:

                break;

            default:
                break;
        }

    } /* if(!mmi_pen_check_tp_shortcut(&pos, data.event)) */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_poll_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_poll_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ResetBit(g_input_msg_in_queue, MMI_DEVICE_PEN);
    if (g_pen_cntx.is_blocked || !g_pen_cntx.is_enabled || ((srv_bootup_is_completed() == MMI_FALSE) && (IsInNVRAMProcedure())))
    {
        return;
    }
    
    while (1)
    {
        if (if_has_pen_event())
        {       
            if (!g_pen_cntx.is_enabled && g_pen_cntx.is_blocked)
            {
                /* Previous pen handlers might call mmi_pen_disable(), but
                   we should already flush driver pen queue on mmi_pen_disable() */
                break;
            }

        #if defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)
            if (g_pen_cntx.touch_mode == MMI_FRM_MULTI_TOUCH)
            {
                
                handle_multi_touch_event();            
            }
            else
        #endif
            {   
                handle_single_touch_event();
            }
            /* Invoke post event */
            mmi_frm_invoke_post_event();
            
            mmi_frm_fetch_msg_from_extQ_to_circularQ();
            if (OslNumOfCircularQMsgs() > 0)
            {
                if (!g_pen_cntx.is_blocked)
                {
                    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_PEN_POLL_HDLR_BREAK_SINCE_MSG);
                    g_pen_flag = MMI_TRUE;
                    SetBit(g_input_msg_in_queue, MMI_DEVICE_PEN);
                    break;
                } 
            }
        }
        else
        {
            g_pen_flag = MMI_FALSE;
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_pen_flush_queue
 * DESCRIPTION
 *  Flush pen event queue and reset context structure.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_TRUE if success to flush queue, return MMI_FALSE if failed.
 *****************************************************************************/
static MMI_BOOL mmi_frm_pen_flush_queue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 tmp_enable;
	mmi_frm_touch_mode mode;
	U16 send_to_new_screen;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_pen_initialized || g_pen_cntx.is_blocked || !g_pen_cntx.is_enabled)
    {/* The condition is as same as mmi_pen_reset, can't process pen events if pen is blocked or disable. */
        return MMI_FALSE;
    }
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_PEN_TRC_FLUSH_QUEUE);

    /* If we drop a pen down here, the following pen up will be dropped too by driver! */
    if (g_pen_simulate_driver_cntx.is_AT_command)
    {
        //memset(g_pen_lookahead_buffer, 0x00, sizeof(g_pen_lookahead_buffer));// clear lookahead buffer
        g_frm_touch_queue.read = g_frm_touch_queue.write = 0;
    }
    else
    {
        if (!g_pen_cntx.is_send_event_to_new_screen)
        {
            kal_prompt_trace(MOD_MMI_FW, "[pen]send to new screen, value = %d", g_pen_cntx.is_send_event_to_new_screen);
        	#ifdef __MTK_TARGET__
      
        	mmi_pen_drv_reset(MMI_TRUE);
            
        	#else
        	mmi_pen_MODIS_flush_queue();
        	gui_cancel_timer(mmi_pen_modis_simulate_driver);
        	g_mmi_pen_MODIS_start_timer = MMI_FALSE;
        	#endif
            g_frm_touch_queue.read = g_frm_touch_queue.write = 0;
        }
    }
    //memset(&g_pen_simulate_driver_cntx, 0x00, sizeof(g_pen_simulate_driver_cntx));
    reset_pre_touch_event_status();
    g_pen_simulate_driver_cntx.ext_enable = MMI_FALSE;
    g_pen_simulate_driver_cntx.is_pen_down = 0;
    g_pen_simulate_driver_cntx.is_stroke_created = 0;
    send_to_new_screen = g_pen_cntx.is_send_event_to_new_screen;
    tmp_enable = g_pen_cntx.is_enabled;
    mode = g_pen_cntx.touch_mode;
    memset(&g_pen_cntx, 0, sizeof(g_pen_cntx));
    g_pen_cntx.touch_mode = mode;
    g_pen_cntx.is_send_event_to_new_screen = send_to_new_screen;
    /* Can't set as 1 which will fail to enalbe pen since its condition - MAUI_01752274 */
    g_pen_cntx.is_enabled = tmp_enable;
    //g_multi_touch_hanler = NULL;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_touch_panel_sendilm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [IN]         unused
 *  state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_touch_panel_sendilm(DCL_EVENT touch_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *tp_ilm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Dummy function */
    if (!g_pen_is_driver_indication_in_queue)
    /* MSG_ID_TP_EVENT_IND only exist once in external queue */
    {
        g_pen_is_driver_indication_in_queue = 1;
		msg_send4(MOD_TP_TASK, MOD_MMI, DRIVER_PS_SAP, MSG_ID_TP_EVENT_IND);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_touch_panel_event_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [IN]     unused
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pen_touch_panel_event_ind(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pen_is_driver_indication_in_queue = 0;
    mmi_pen_poll_hdlr();
}

void mmi_frm_pen_handle(void)
{
    mmi_pen_poll_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_dummy_hdlr
 * DESCRIPTION
 *  This function is the dummy pen handler. It will do nothing.
 *  Some applications will use this function as the dump pen handler 
 *  
 * PARAMETERS
 *  pos     :[IN] The position of the touched point.        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_dummy_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(pos);
}


/*****************************************************************************
 * FUNCTION
 *  reset_pre_touch_event_status
 * DESCRIPTION
 *  reset pre touch event of all the finger to MMI_PEN_INVALID_EVENT, it's our ju
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void reset_pre_touch_event_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i=0; i< MMI_FRM_MULTI_TOUCH_MAX_FINGER; i++)
    {
        g_frm_finger_info[i].pre_event = MMI_PEN_INVALID_EVENT;
#if defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)
        g_pre_event[i].event = MMI_PEN_INVALID_EVENT;
#endif
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pen_init
 * DESCRIPTION
 *  Initialize pen system
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_INIT_BEGIN);
    g_pen_initialized = MMI_TRUE;
    g_pen_drvq_full_abort = MMI_FALSE;
    g_pen_abort_type = MMI_PEN_ABORT_TYPE_NONE;
	g_frm_touch_queue.queue = multi_touch_queue;
	g_frm_touch_queue.read = g_frm_touch_queue.write = 0;
	reset_pre_touch_event_status();
	if (g_pen_drv_handle == NULL)
	{
        g_pen_drv_handle = DclSTS_Open(DCL_TS,0);
    }
	

    mmi_pen_stop_capture_strokes();
    mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_1, MMI_PEN_SAMPLING_PERIOD_2);
    mmi_pen_config_timeout_period(MMI_PEN_LONGTAP_TIME, MMI_PEN_REPEAT_TIME, MMI_PEN_STROKE_LONGTAP_TIME);
    mmi_pen_config_move_offset(
        MMI_PEN_SKIP_MOVE_OFFSET,
        MMI_PEN_SKIP_STROKE_MOVE_OFFSET,
        MMI_PEN_SKIP_LONGTAP_OFFSET,
        MMI_PEN_SKIP_STROKE_LONGTAP_OFFSET);
    mmi_pen_drv_callback_registry(mmi_pen_touch_panel_sendilm, NULL);
    SetProtocolEventHandler(mmi_pen_touch_panel_event_ind, MSG_ID_TP_EVENT_IND);
    /* AT command protocal event handler */
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EQ_SCREEN_TOUCH_REQ_IND, (PsIntFuncPtr)mmi_pen_ctsa_req, MMI_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EQ_SCRNORIENT_REQ_IND, (PsIntFuncPtr)mmi_pen_cso_req, MMI_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EQ_SCRNTCH_EVENT_ACT_IND, (PsIntFuncPtr)mmi_pen_cmer_req, MMI_FALSE);
#ifndef __MTK_TARGET__
    SetProtocolEventHandler(mmi_pen_modis_simulate_driver_sample, MSG_ID_MODIS_TP_EVENT_IND);
    g_mmi_pen_MODIS_start_timer = MMI_FALSE;
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_block
 * DESCRIPTION
 *  Block pen system
 *  
 *  Note: typically used for keypad lock in idle screen
 *  mmi_pen_enable()/mmi_pen_disable() are ignored when pen is blocked.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_block(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_touch_mode mode;
    U32 enable;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_BLOCK);
    if (!g_pen_initialized)
    {
        return;
    }

    #ifdef __MTK_TARGET__
    mmi_pen_drv_power_on(MMI_FALSE);
    mmi_pen_drv_flush();
    #else
    mmi_pen_MODIS_flush_queue();
    g_frm_touch_queue.write = g_frm_touch_queue.read = 0;
    gui_cancel_timer(mmi_pen_modis_simulate_driver);
    g_mmi_pen_MODIS_start_timer = MMI_FALSE;
    #endif

    g_frm_touch_queue.write = g_frm_touch_queue.read = 0;
    
    if (g_pen_cntx.is_pen_down)
    {
        generate_pen_abort_event();
    }
    reset_pre_touch_event_status();
    memset(&g_pen_simulate_driver_cntx, 0, sizeof(g_pen_simulate_driver_cntx));
    mode = g_pen_cntx.touch_mode;
    enable = g_pen_cntx.is_enabled;
    memset(&g_pen_cntx, 0, sizeof(g_pen_cntx));
    g_pen_cntx.touch_mode = mode;
    g_pen_cntx.is_enabled = enable;
    g_pen_cntx.is_blocked = 1;
    g_pen_flag = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_unblock
 * DESCRIPTION
 *  Unblock pen system
 *  
 *  Note: typically used for keypad lock in idle screen
 *  mmi_pen_enable()/mmi_pen_disable() are ignored when pen is blocked.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_unblock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_touch_mode mode = g_pen_cntx.touch_mode;
    U32 enable = g_pen_cntx.is_enabled;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_UNBLOCK);
    //mmi_pen_enable();

    if (!g_pen_initialized)
    {
        return;
    }
    memset(&g_pen_cntx, 0, sizeof(g_pen_cntx));
    g_pen_cntx.touch_mode = mode;
    g_pen_cntx.is_enabled = enable;
    mmi_pen_drv_power_on(MMI_TRUE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_config_sampling_period
 * DESCRIPTION
 *  Config sampling period of Event-based and Stroke-Based
 * PARAMETERS
 *  low         :[IN]        (Pen Event)Sampling period in non-handwriting area (multiple of 10ms)
 *  high        :[IN]        (Stroke Event)Sampling period in handwriting area (multiple of 10ms)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_config_sampling_period(kal_uint32 low, kal_uint32 high)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    STS_CTRL_CSP_T data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	data.u4Low = low;
	data.u4High = high;
	DclSTS_Control(g_pen_drv_handle, STS_CMD_CONF_SAMPLE_PERIOD, (DCL_CTRL_DATA_T*)&data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_config_timeout_period
 * DESCRIPTION
 *  Config timeout period for LongTap and Repeat
 * PARAMETERS
 *  longtap             :[IN]        Timeout period for Pen LongTap event (multiple of 10ms).
 *  repeat              :[IN]        Timeout period for Pen Repeat event (multiple of 10ms).
 *  stroke_longtap      :[IN]        Timeout period for Stroke LongTap event (multiple of 10ms).
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_config_timeout_period(kal_uint32 longtap, kal_uint32 repeat, kal_uint32 stroke_longtap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    STS_CTRL_CTP_T data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	data.u4Longtap = longtap;
	data.u4Repeat = repeat;
	data.u4Handwriting_longtap = stroke_longtap;
	DclSTS_Control(g_pen_drv_handle, STS_CMD_CONF_TIMEOUT_PERIOD, (DCL_CTRL_DATA_T*)&data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_config_move_offset
 * DESCRIPTION
 *  Config
 * PARAMETERS
 *  event_based         :[IN]        Minimum move offset for Pen Move event
 *  stroke_based        :[IN]        Minimum move offset for Stroke Move event
 *  long_tap            :[IN]        Maximum move offset for Pen LongTap event
 *  stroke_long_tap     :[IN]        Maximum move offset for Stroke LongTap event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_config_move_offset(
        kal_uint32 event_based,
        kal_uint32 stroke_based,
        kal_uint32 long_tap,
        kal_uint32 stroke_long_tap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	STS_CTRL_CMO_T data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	data.u2Pen_offset = event_based;
	data.u2Stroke_offset = stroke_based;
	data.u2Longtap_pen_offset = long_tap;
	data.u2Longtap_stroke_offset = stroke_long_tap;
	DclSTS_Control(g_pen_drv_handle,STS_CMD_CONF_MOVE_OFFSET, (DCL_CTRL_DATA_T*)&data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_enable
 * DESCRIPTION
 *  Enable pen system
 *  
 *  Note: typically on Keypad Up
 *  If g_pen_initialized is not true, we do not enable touch screen because
 *  TP task might not be running
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_touch_mode mode = g_pen_cntx.touch_mode;
    U32 block;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!g_pen_initialized)
    {
        return;
    }

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_PEN_TRC_ENABLE);
    block = g_pen_cntx.is_blocked;
    memset(&g_pen_cntx, 0, sizeof(g_pen_cntx));
    g_pen_cntx.is_blocked = block;
    g_pen_cntx.touch_mode = mode;
    g_pen_cntx.is_enabled = 1;
    if (!g_pen_simulate_driver_cntx.is_AT_command)
    {
        mmi_pen_drv_enable(MMI_TRUE);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_disable
 * DESCRIPTION
 *  Disable pen system
 *  
 *  Note: typically on Keypad Down because we don't want to use keypad and touch screen
 *  at the same time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_touch_mode mode;
    U32 block;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_pen_initialized)
    {
        return;
    }
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_PEN_TRC_DISABLE);
    if (!g_pen_simulate_driver_cntx.is_AT_command)
    {
        #ifdef __MTK_TARGET__
        mmi_pen_drv_enable(MMI_FALSE);
        mmi_pen_drv_flush();
        #else
        mmi_pen_MODIS_flush_queue();
        //memset(g_pen_lookahead_buffer, 0x00, sizeof(g_pen_lookahead_buffer));
        g_frm_touch_queue.write = g_frm_touch_queue.read = 0;
        gui_cancel_timer(mmi_pen_modis_simulate_driver);
        g_mmi_pen_MODIS_start_timer = MMI_FALSE;
        #endif
    }

    g_frm_touch_queue.write = g_frm_touch_queue.read = 0;
    
    if (g_pen_cntx.is_pen_down)
    {
        generate_pen_abort_event();
    }
    reset_pre_touch_event_status();
    //memset(&g_pen_simulate_driver_cntx, 0, sizeof(g_pen_simulate_driver_cntx));
    g_pen_simulate_driver_cntx.ext_enable = MMI_FALSE;
    g_pen_simulate_driver_cntx.is_pen_down = 0;
    g_pen_simulate_driver_cntx.is_stroke_created = 0;
    g_pen_simulate_driver_cntx.is_waiting_long_tap_event = 0;
    mode = g_pen_cntx.touch_mode;
    block = g_pen_cntx.is_blocked;
    memset(&g_pen_cntx, 0, sizeof(g_pen_cntx));
    g_pen_cntx.touch_mode = mode;
    g_pen_cntx.is_blocked = block;
    g_pen_flag = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_get_pen_abort_type
 * DESCRIPTION
 *  Get pen abort type, since mmi_pen_reset will be invoked when driver queue full
 *  or screen is switched, so pen abort will happen in these cases, application need
 *  to differentiate these scenario.
 * PARAMETERS
 *  void
 * RETURNS
 *  pen abort type
 *****************************************************************************/
mmi_pen_abort_type_enum mmi_pen_get_pen_abort_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_pen_abort_type;
}


void mmi_pen_send_event_to_new_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_SEND_EVENT_TO_NEW_SCREEN);
    g_pen_cntx.is_send_event_to_new_screen = MMI_TRUE;
}

MMI_BOOL mmi_pen_is_sw_pen_down(void)
{
	return (g_pen_cntx.is_sw_pen_down) ? MMI_TRUE : MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  generate_pen_abort_event
 * DESCRIPTION
 *  Generate pen abort event to let user reset status since pen up event may be
 *  dropped by the action of flushing queue.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void generate_pen_abort_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_event_struct data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_PEN_TRC_POLL_HDLR_PEN_ABORT, (int)g_pen_cntx.pen_current_pos.x, (int)g_pen_cntx.pen_current_pos.y);
    /* For both stroke-based and event-based */

    if (g_pen_drvq_full_abort)
    {
        g_pen_drvq_full_abort = MMI_FALSE;
        g_pen_abort_type = MMI_PEN_ABORT_TYPE_DRVQ_FULL;
    }
    else if (mmi_frm_event_get_switch_screen_flag())
    {
        g_pen_abort_type = MMI_PEN_ABORT_TYPE_SWITCH_SCRN;
    }
    if(g_pen_cntx.touch_mode == MMI_FRM_MULTI_TOUCH)
    {
    #if defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)
		mmi_ret ret;
        multi_touch_get_abort_event();
        g_multi_touch_event.evt_id = EVT_ID_PRE_TOUCH_EVT_ROUTING;
        ret = MMI_FRM_CB_EMIT_EVENT(&g_multi_touch_event);
		calculate_main_point();
        if (ret != MMI_RET_STOP_TOUCH_HANDLE)
        {

            if(g_mmi_frm_touch_proc.touch_proc != NULL)
            {   
				g_multi_touch_event.evt_id = EVT_ID_ON_TOUCH;
        		//send event to proc
        		MMI_FRM_SEND_EVENT(&g_multi_touch_event, g_mmi_frm_touch_proc.touch_proc, g_mmi_frm_touch_proc.user_data);   
            }


        }            
		g_multi_touch_event.evt_id = EVT_ID_POST_TOUCH_EVT_ROUTING;
        MMI_FRM_CB_EMIT_EVENT(&g_multi_touch_event); 
    #endif
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_PEN_POLL_HDLR_GEN_PEN_ABORT);

        data.event = DCL_PEN_ABORT;
        data.x_adc = g_pen_cntx.pen_current_pos.x;
        data.y_adc = g_pen_cntx.pen_current_pos.y;
        excecute_pen_event(&data, MMI_PEN_EVENT_ABORT);
       
    g_pen_simulate_driver_cntx.is_abort_happen = 1;
#if defined(__MMI_GESTURES_FRAMEWORK__)
        mmi_frm_gesture_recognise(MMI_PEN_EVENT_ABORT, g_pen_cntx.pen_current_pos);
#endif /* #if defined(__MMI_GESTURES_FRAMEWORK__) */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_reset
 * DESCRIPTION
 *  Reset the status of touch screen
 *  - Flush event queue
 *  - If the pen is currently tapped down, ignore all subsequent pen events until the pen is up.
 *  
 *  Note: typically on MMI screen switching
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     MMI_BOOL tmp_enable;
     mmi_pen_event_struct* pen_lookahead_buffer = (mmi_pen_event_struct*)g_frm_touch_queue.queue;
     mmi_frm_touch_mode mode;
     U16 send_to_new_screen;
     S32 x, y;
     U32 driver_state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!g_pen_initialized || g_pen_cntx.is_blocked || !g_pen_cntx.is_enabled)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_PEN_TRC_RESET_ERR, g_pen_initialized, g_pen_cntx.is_blocked, g_pen_cntx.is_enabled);
        return;
    }
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_PEN_TRC_RESET);

    if (g_pen_cntx.is_pen_down && (!g_pen_cntx.is_send_event_to_new_screen))
    {
        generate_pen_abort_event();
    }
    if (g_pen_cntx.is_pen_down && g_pen_cntx.is_send_event_to_new_screen && (g_frm_touch_queue.write < (MMI_PEN_LOOKAHEAD_BUFFER_SIZE - 2)))
    {
        mmi_pen_event_struct pen_down_event;
        /* we need to put pen down event in lookahead buffer, but if the screen is rotated, we need to 
           change the pen down position to the position before screen rotation
        */
        MMI_ASSERT(g_pen_cntx.touch_mode == MMI_FRM_SINGLE_TOUCH);

		if (g_pen_cntx.is_sw_pen_down == 1)
		{
			return;
		}
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_ADD_PEN_DOWN_EVENT);
        pen_down_event.event = DCL_PEN_DOWN;
        x = g_pen_cntx.pen_down_pos.pos.x;
        y = g_pen_cntx.pen_down_pos.pos.y;
        #ifdef __MMI_SCREEN_ROTATE__
        if (mmi_frm_get_screen_rotate() != MMI_FRM_SCREEN_ROTATE_0)
        {  
            gdi_rotate_map_lcd_to_absolute_hw(&x, &y);
        }
        #endif /* __MMI_SCREEN_ROTATE__ */
   
        pen_down_event.x_adc = x;
        pen_down_event.y_adc = y;
		pen_down_event.time_stamp = g_pen_cntx.pen_down_pos.timestamp;
        
        memmove(pen_lookahead_buffer, &(pen_lookahead_buffer[1]), 
                sizeof(U16) * (g_frm_touch_queue.write));
        memcpy(pen_lookahead_buffer, &pen_down_event, sizeof(mmi_pen_event_struct));
        g_frm_touch_queue.write++;
        driver_state = g_pen_cntx.is_driver_down;
        tmp_enable = (MMI_BOOL)g_pen_cntx.is_enabled;
        memset(&g_pen_cntx, 0, sizeof(g_pen_cntx));
        g_pen_cntx.is_driver_down = driver_state;
        g_pen_cntx.is_enabled = tmp_enable;
        g_pen_simulate_driver_cntx.ext_enable = MMI_FALSE;
        g_pen_simulate_driver_cntx.is_stroke_created = 0;
		g_pen_cntx.is_send_event_to_new_screen = MMI_TRUE;
        return;
     }
    /* If drop a pen down here, the following pen up will be dropped too by driver! */
    if (g_pen_simulate_driver_cntx.is_AT_command)
    {
        //memset(g_frm_touch_queue.queue, 0x0000, sizeof(U16) * QUEUE_SIZE);// clear lookahead buffer
        g_frm_touch_queue.read = g_frm_touch_queue.write = 0;
    }
    else
    {
        if (!g_pen_cntx.is_send_event_to_new_screen)
	    {
            
        	#ifdef __MTK_TARGET__
        	mmi_pen_drv_reset(MMI_TRUE);
        	#else
        	mmi_pen_MODIS_flush_queue();
        	gui_cancel_timer(mmi_pen_modis_simulate_driver);
        	g_mmi_pen_MODIS_start_timer = MMI_FALSE;
			g_pen_simulate_driver_cntx.is_pen_down = 0;
        	#endif
    		g_frm_touch_queue.read = g_frm_touch_queue.write = 0;
			g_pen_cntx.is_driver_down = 0;
         }
    }

    send_to_new_screen = g_pen_cntx.is_send_event_to_new_screen;
    reset_pre_touch_event_status();
    g_pen_simulate_driver_cntx.ext_enable = MMI_FALSE;
    g_pen_simulate_driver_cntx.is_stroke_created = 0;
    g_pen_simulate_driver_cntx.is_waiting_long_tap_event = 0;
    mode = g_pen_cntx.touch_mode;
    driver_state = g_pen_cntx.is_driver_down;
    memset(&g_pen_cntx, 0, sizeof(g_pen_cntx));
    g_pen_cntx.is_driver_down = driver_state;
    g_pen_cntx.touch_mode = mode;
    g_pen_cntx.is_send_event_to_new_screen = send_to_new_screen;
    g_pen_cntx.is_enabled = 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_get_state
 * DESCRIPTION
 *  Get the current state of touch screen
 *  It returns the current state *inside MMI task*, real pen state might be changed, but
 *  the driver indication might not be processed yet.
 *
 * PARAMETERS
 *  is_enabled      :[OUT] Is pen enabled or not        
 *  is_pen_down     :[OUT] Is pen down or not
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_get_state(kal_bool *is_enabled, kal_bool *is_pen_down)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_cntx.is_enabled)
    {
        *is_enabled = KAL_TRUE;
        if (g_pen_cntx.is_pen_down)
        {
            *is_pen_down = KAL_TRUE;
        }
        else
        {
            *is_pen_down = KAL_FALSE;
        }
    }
    else
    {
        *is_enabled = KAL_FALSE;
        *is_pen_down = KAL_FALSE;
    }
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_GET_STATE, *is_enabled, *is_pen_down);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_get_info
 * DESCRIPTION
 *  Get the current information of pen event.
 * PARAMETERS
 *  pen_type        :[OUT]  If the current event is pen event, pen event will be got      
 *  stroke_type     :[OUT]  If the current event is stroke event, stroke event will be got      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_get_info(mmi_pen_event_type_enum *pen_type, mmi_pen_stroke_type_enum *stroke_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *pen_type = MMI_PEN_EVENT_NONE;
    *stroke_type = MMI_PEN_STROKE_NONE;
    
    switch (g_pen_cntx.pen_event)
    {
        case DCL_PEN_DOWN:
            *pen_type = MMI_PEN_EVENT_DOWN;
            break;
        case DCL_PEN_UP:
            *pen_type = MMI_PEN_EVENT_UP;
            break;
        case DCL_PEN_MOVE:
            *pen_type = MMI_PEN_EVENT_MOVE;
            break;
        case DCL_PEN_LONGTAP:
            *pen_type = MMI_PEN_EVENT_LONG_TAP;
            break;
        case DCL_PEN_REPEAT:
            *pen_type = MMI_PEN_EVENT_REPEAT;
            break;
        case DCL_PEN_ABORT:
            *pen_type = MMI_PEN_EVENT_ABORT;
            break;
        case DCL_STROKE_MOVE:
            *stroke_type = MMI_PEN_STROKE_MOVE;
            break;
        case DCL_STROKE_DOWN:
            *stroke_type = MMI_PEN_STROKE_DOWN;
            break;
        case DCL_STROKE_LONGTAP:
            *stroke_type = MMI_PEN_STROKE_LONGTAP;
            break;
        case DCL_STROKE_UP:
            *stroke_type = MMI_PEN_STROKE_UP;
            break;
        default:    /* DCL_TP_UNKNOWN_EVENT */
            break;
    }
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_PEN_GET_INFO, *pen_type, *stroke_type);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_start_calibration
 * DESCRIPTION
 *  Start pen calibration
 *  After mmi_pen_reset(), the calibration process is terminated.
 * PARAMETERS
 *  num         :[IN]        Number of calibration points
 *  points      :[IN]        Calibration points buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_start_calibration(U16 num, const mmi_pen_point_struct *points)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    STS_CTRL_SC_T       data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_PEN_TRC_CALIBRATION);
    MMI_ASSERT(g_pen_initialized);
	data.rpPoint = (TS_COORD_T*)points;
	data.u2Num = num;
	DclSTS_Control(g_pen_drv_handle,STS_CMD_START_CALI, (DCL_CTRL_DATA_T*)&data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_set_calibration_data
 * DESCRIPTION
 *  Assign driver calibration data
 * PARAMETERS
 *  data        :[IN]   calibration data     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_set_calibration_data(const mmi_pen_calibration_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TouchPanelCaliStruct cali;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_PEN_SET_CALIBRATION_DATA);
    MMI_DBG_ASSERT(sizeof(mmi_pen_calibration_struct) == sizeof(TouchPanelCaliStruct));
    memcpy(&cali, data, sizeof(TouchPanelCaliStruct));
    mmi_pen_drv_set_calibration(cali);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_read_calibration_data
 * DESCRIPTION
 *  Read the current value of driver calibration data
 * PARAMETERS
 *  data        :[OUT] calibration data from driver       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_read_calibration_data(mmi_pen_calibration_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TouchPanelCaliStruct cali;
	STS_CTRL_RC_T  prCtrlRC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_PEN_READ_CALIBRATION_DATA);
    MMI_DBG_ASSERT(sizeof(mmi_pen_calibration_struct) == sizeof(TouchPanelCaliStruct));

    DclSTS_Control(g_pen_drv_handle, STS_CMD_READ_CALI, (DCL_CTRL_DATA_T*)&prCtrlRC);

    //  touch_panel_read_cali(&cali);
	cali.x_offset = prCtrlRC.rCali.x_offset;
	cali.x_slope =  prCtrlRC.rCali.x_slope;
	cali.y_offset = prCtrlRC.rCali.y_offset;
	cali.y_slope = prCtrlRC.rCali.y_slope;
    memcpy(data, &cali, sizeof(TouchPanelCaliStruct));

}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_down_handler
 * DESCRIPTION
 *  Register the Pen Down handler
 * PARAMETERS
 *  pen_fp      :[IN]  Callback function for Pen Down event.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_down_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_PEN_TRC_REG_PEN_EVENT_DOWN_HDLR, pen_fp);
    g_pen_event_table[MMI_PEN_EVENT_DOWN] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_long_tap_handler
 * DESCRIPTION
 *  Register the Pen LongTap handler
 *  
 *  Note:
 *  1. LongTap handler is invoked when  the pen is tapped for a period of time
 *  and stays at the same place where it is tapped down.
 *  
 *  2. If pen move happen after pen down, there will be no pen longtap event.
 *  3. Pen long tap can only happen one time at most.
 * 
 * PARAMETERS
 *  pen_fp      :[IN]   Callback function for Pen LongTap event.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_long_tap_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_PEN_TRC_REG_PEN_EVENT_LONG_TAP_HDLR, pen_fp);
    g_pen_event_table[MMI_PEN_EVENT_LONG_TAP] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_repeat_handler
 * DESCRIPTION
 *  Register the Pen Repeat handler.
 *  
 *  Note:
 *  1. Repeat can happen after LongTap or move or another repeat.
 *  2. Repeat event's coordinate will follow the previous events
 *  
 * PARAMETERS
 *  pen_fp      :[IN]  Callback function for Pen Repeat event.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_repeat_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_PEN_TRC_REG_PEN_EVENT_REPEAT_HDLR, pen_fp);
    g_pen_event_table[MMI_PEN_EVENT_REPEAT] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_double_click_handler
 * DESCRIPTION
 *  Register the Pen double click handler.
 * PARAMETERS
 *  pen_fp      :[IN]  Callback function for Pen Repeat event.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_double_click_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_PEN_TRC_REG_PEN_EVENT_DOUBLE_CLICK_HDLR, pen_fp);
    g_pen_event_table[MMI_PEN_EVENT_DOUBLE_CLICK] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_move_handler
 * DESCRIPTION
 *  Register the Pen Move handler.
 *  The invocation frequency of Pen Move handler is typically less than driver sampling rate.
 * PARAMETERS
 *  pen_fp      :[IN]   Callback function for Pen Move event.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_move_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_PEN_TRC_REG_PEN_EVENT_MOVE_HDLR, pen_fp);
    g_pen_event_table[MMI_PEN_EVENT_MOVE] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_up_handler
 * DESCRIPTION
 *  Register the Pen Up handler.
 * PARAMETERS
 *  pen_fp      :[IN]  Callback function for Pen Up event.      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_up_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_PEN_TRC_REG_PEN_EVENT_UP_HDLR, pen_fp);
    g_pen_event_table[MMI_PEN_EVENT_UP] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_abort_handler
 * DESCRIPTION
 *  Register the Pen Abort handler.
 * PARAMETERS
 *  pen_fp      :[IN]  Callback function for Pen Abort event.      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_abort_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_PEN_TRC_REG_PEN_EVENT_ABORT_HDLR, pen_fp);
    g_pen_event_table[MMI_PEN_EVENT_ABORT] = pen_fp;
}


/*****************************************************************************
* FUNCTION
*  mmi_pen_get_handler
* DESCRIPTION
*  This function is used for gets the pen event handler for current screen.
* PARAMETERS
*  pen_event     :[IN]  Which pen event's handler is wanted to query.       
* RETURNS
*  The handler of pen event.
*****************************************************************************/
mmi_pen_hdlr mmi_pen_get_pen_handler(mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return g_pen_event_table[pen_event];
}




static void mmi_pen_rotate_region(S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	S32 x3 = *x1;
	S32 y3 = *y1;
	S32 x4 = *x2;
	S32 y4 = *y2;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
    gdi_rotate_map_lcd_to_absolute_hw(&x3, &y3);
    gdi_rotate_map_lcd_to_absolute_hw(&x4, &y4);

	if (x3 > x4)
	{
		*x1 = x4;
		*x2 = x3;
	}
	else
	{
		*x1 = x3;
		*x2 = x4;
	}
	if (y3 > y4)
	{
	    *y1 = y4;
		*y2 = y3;
	}
	else
	{
	    *y1 = y3;
		*y2 = y4;
	}
}


static void mmi_pen_handwriting_in_rotation(TouchPanelHandAreaStruct *area)
{
	S32 x1;
	S32 y1;
	S32 x2;
	S32 y2;
	if (area != NULL)
	{
		x1 = area->min.x;
		y1 = area->min.y;
		x2 = area->max.x;
		y2 = area->max.y;
		mmi_pen_rotate_region(&x1, &y1, &x2, &y2);
		area->min.x = x1;
		area->min.y = y1;
		area->max.x = x2;
		area->max.y = y2;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_start_capture_strokes
 * DESCRIPTION
 *  Start to capture stroke inside the handwriting area.
 *
 *  This API is typically used in entry function of editor screen.
 *
 *  The points are en-queued in 'point_array' in the following format:
 * 
 *  Each point contains two 16-bit integers for x, y coordinates. Two strokes are separated with
 *  marker (0xffff, 0), and all strokes of one character are ended with (0xffff, 0xffff) by
 *  mmi_pen_end_strokes_of_character(). The parameter 'max_points' should also include the memory 
 *  used by markers.
 *  (x0, y0) (x1, y1) ¡K (0xffff, 0), ¡K(0xffff, 0), ¡K(0xffff, 0xffff)
 *  
 *  We has the following types of stroke-based handler
 *  - Stroke Down
 *  - Stroke Move
 *  - Stroke Up
 *  However, it does not have Stroke Repeat handler.
 *  
 *  In single-block mode ('num_regions' > 1), it enters stroke-based mode when pen is down in 
 *  handwriting area and then moves across MMI_PEN_STROKE_MIN_OFFSET pixels.
 *
 *  In multi-block mode ('num_regions' > 1), it enters stroke-based mode immediately after pen 
 *  is down in handwriting area.
 * 
 *  Note: the parameter 'ext_region' can only be used in single-block mode.
 * 
 * PARAMETERS
 *  max_points          :[IN]        Maximum number of points can be en-queued.
 *  point_array         :[IN]        Array for storing sampled points in strokes.
 *  num_regions         :[IN]        Number of handwriting regions
 *  region_array        :[IN]        Handwriting regions
 *  ext_region          :[IN]        Handwriting region after the first stroke is generated. (NULL to ignore it)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_start_capture_strokes(
        kal_uint32 max_points,
        mmi_pen_point_struct *point_array,
        kal_uint32 num_regions,
        const mmi_pen_handwriting_area_struct *region_array,
        const mmi_pen_handwriting_area_struct *ext_region)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;
    TouchPanelHandAreaStruct area[HAND_WRITING_AREA_NUM];
    TouchPanelHandAreaStruct ext_area;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_PEN_TRC_START_CAPTURE_STROKES);

    /* Multi-block mode does not have extended region. Otherwise, it cannot switch to another 
       block and multi-block feature is broken. */
    MMI_ASSERT(ext_region == NULL || num_regions == 1);
    if (num_regions > HAND_WRITING_AREA_NUM)
    {
        num_regions = HAND_WRITING_AREA_NUM;
    }

    for (i = 0; i < num_regions; i++)
    {
        area[i].min.x = (kal_int16) region_array[i].x1;
        area[i].min.y = (kal_int16) region_array[i].y1;
        area[i].max.x = (kal_int16) region_array[i].x2;
        area[i].max.y = (kal_int16) region_array[i].y2;
	#ifdef __MMI_SCREEN_ROTATE__
		if (mmi_frm_get_screen_rotate() != MMI_FRM_SCREEN_ROTATE_0)
		{
			mmi_pen_handwriting_in_rotation(&area[i]);
		}
	#endif
    }

    if (ext_region == NULL) /* No extended area */
    {
    #ifdef __MMI_TOUCH_SCREEN__
        ext_area.min.x = -1;
        ext_area.min.y = -1;
        ext_area.max.x = -1;
        ext_area.max.y = -1;
    #else /* __MMI_TOUCH_SCREEN__ */ 
        /* change to full region for handwriting automatically */
        // TODO: should we change this?
        ext_area.min.x = TOUCH_PANEL_COORD_X_START;
        ext_area.min.y = TOUCH_PANEL_COORD_Y_START;
        ext_area.max.x = (kal_int16) TOUCH_PANEL_COORD_X_END - 1;
        ext_area.max.y = (kal_int16) TOUCH_PANEL_COORD_Y_END - 1;
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    }
    else
    {
        ext_area.min.x = (kal_int16) ext_region->x1;
        ext_area.min.y = (kal_int16) ext_region->y1;
        ext_area.max.x = (kal_int16) ext_region->x2;
        ext_area.max.y = (kal_int16) ext_region->y2;

    }
    memcpy(&g_pen_ext_stroke_area, &ext_area, sizeof(mmi_pen_handwriting_area_struct));
    #ifdef __MMI_SCREEN_ROTATE__
	if (mmi_frm_get_screen_rotate() != MMI_FRM_SCREEN_ROTATE_0)
	{
		mmi_pen_handwriting_in_rotation(&ext_area);
    }
    #endif

    mmi_pen_drv_config_handwriting(area, (kal_uint16)num_regions, &ext_area);

    g_pen_stroke_max_points = max_points;
    g_pen_stroke_points = point_array;
    
    g_pen_num_stroke_area = num_regions;
    memcpy(g_pen_stroke_areas, region_array, sizeof(mmi_pen_handwriting_area_struct) * num_regions);
    
    /* Stroke minimum offset is used by single-block mode only */
    if (num_regions == 1)
    {
        g_pen_stroke_min_offset_square = MMI_PEN_STROKE_MIN_OFFSET * MMI_PEN_STROKE_MIN_OFFSET;
    }
    else
    {
        g_pen_stroke_min_offset_square = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_change_handwriting_area
 * DESCRIPTION
 *  Change hand-written area.
 *  It is typically used when changing input language.
 *  
 *  It will
 *  1. reset handwriting and g_pen_stroke_min_offset_square
 *  2. mmi_pen_reset() to flush queue.
 * PARAMETERS
 *  num_regions         :[IN]        Number of handwriting regions
 *  region_array        :[IN]        Handwriting regions
 *  ext_region          :[IN]        Handwriting region after the first stroke is generated. (NULL to ignore it)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_change_handwriting_area(
        kal_uint32 num_regions,
        const mmi_pen_handwriting_area_struct *region_array,
        const mmi_pen_handwriting_area_struct *ext_region)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;
    TouchPanelHandAreaStruct area[HAND_WRITING_AREA_NUM];
    TouchPanelHandAreaStruct ext_area;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_PEN_TRC_CHANGE_HANDWRITING_AREA);

    if (g_pen_stroke_max_points == 0)
    {
        return;
    }

    /* Multi-block mode does not have extended region */
    MMI_ASSERT(ext_region == NULL || num_regions == 1);

    /* Change handwriting area */
    if (num_regions > HAND_WRITING_AREA_NUM)
    {
        num_regions = HAND_WRITING_AREA_NUM;
    }

    for (i = 0; i < num_regions; i++)
    {
        area[i].min.x = (kal_int16) region_array[i].x1;
        area[i].min.y = (kal_int16) region_array[i].y1;
        area[i].max.x = (kal_int16) region_array[i].x2;
        area[i].max.y = (kal_int16) region_array[i].y2;
	#ifdef __MMI_SCREEN_ROTATE__
		if (mmi_frm_get_screen_rotate() != MMI_FRM_SCREEN_ROTATE_0)
		{
			mmi_pen_handwriting_in_rotation(&area[i]);
		}
	#endif
    }

    if (ext_region == NULL)
    {
        ext_area.min.x = -1;
        ext_area.min.y = -1;
        ext_area.max.x = -1;
        ext_area.max.y = -1;
    }
    else
    {
        // TODO: should we change this?    
        ext_area.min.x = (kal_int16) ext_region->x1;
        ext_area.min.y = (kal_int16) ext_region->y1;
        ext_area.max.x = (kal_int16) ext_region->x2;
        ext_area.max.y = (kal_int16) ext_region->y2;
    }
    memcpy(&g_pen_ext_stroke_area, &ext_area, sizeof(mmi_pen_handwriting_area_struct));
	#ifdef __MMI_SCREEN_ROTATE__
	    if (mmi_frm_get_screen_rotate() != MMI_FRM_SCREEN_ROTATE_0)
	    {    
			mmi_pen_handwriting_in_rotation(&ext_area);
	    }
	#endif	
    mmi_pen_drv_config_handwriting(area, (kal_uint16)num_regions, &ext_area);

    g_pen_num_stroke_area = num_regions;
    memcpy(g_pen_stroke_areas, region_array, sizeof(mmi_pen_handwriting_area_struct) * num_regions);

    /* Stroke minimum offset is used by single-block mode only */
    if (num_regions == 1)
    {
        g_pen_stroke_min_offset_square = MMI_PEN_STROKE_MIN_OFFSET * MMI_PEN_STROKE_MIN_OFFSET;
    }
    else
    {
        g_pen_stroke_min_offset_square = 0;
    }

    /* 
     * We will call mmi_pen_reset() *later* on Pen Up or Stroke Up event.
     *
     * There might be many pending events in driver queue if MMI task is blocked by 
     * other time-consuming jobs. If there are pending stroke events in driver queue, 
     * it is better to flush driver queue.
     *
     */
    if (!g_pen_cntx.is_pen_down)
    {
        /* Clear strokes */
        mmi_pen_end_strokes_of_character();
        mmi_pen_reset();
        mmi_pen_begin_strokes_of_character();
    }
}
   
/*****************************************************************************
 * FUNCTION
 *  mmi_pen_change_handwriting_area_ex
 * DESCRIPTION
 *  Change hand-written area.
 *  It is typically used when changing input language.
 *  
 *  It will
 *  1. reset handwriting and g_pen_stroke_min_offset_square
 *  2. mmi_pen_reset() to flush queue.
 * PARAMETERS
 *  num_regions         :[IN]        Number of handwriting regions
 *  region_array        :[IN]        Handwriting regions
 *  ext_region          :[IN]        Handwriting region after the first stroke is generated. (NULL to ignore it)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_change_handwriting_area_ex(
        kal_uint32 num_regions,
        const mmi_pen_handwriting_area_struct *region_array,
        const mmi_pen_handwriting_area_struct *ext_region)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;
    TouchPanelHandAreaStruct area[HAND_WRITING_AREA_NUM];
    TouchPanelHandAreaStruct ext_area;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_PEN_TRC_CHANGE_HANDWRITING_AREA);

    if (g_pen_stroke_max_points == 0)
    {
        return;
    }

    /* Multi-block mode does not have extended region */
    MMI_ASSERT(ext_region == NULL || num_regions == 1);

    /* Change handwriting area */
    if (num_regions > HAND_WRITING_AREA_NUM)
    {
        num_regions = HAND_WRITING_AREA_NUM;
    }

    for (i = 0; i < num_regions; i++)
    {
        area[i].min.x = (kal_int16) region_array[i].x1;
        area[i].min.y = (kal_int16) region_array[i].y1;
        area[i].max.x = (kal_int16) region_array[i].x2;
        area[i].max.y = (kal_int16) region_array[i].y2;
#ifdef __MMI_SCREEN_ROTATE__
		if (mmi_frm_get_screen_rotate() != MMI_FRM_SCREEN_ROTATE_0)
		{	 
			mmi_pen_handwriting_in_rotation(&area[i]);
		}
#endif
    }

    if (ext_region == NULL)
    {
        ext_area.min.x = -1;
        ext_area.min.y = -1;
        ext_area.max.x = -1;
        ext_area.max.y = -1;
    }
    else
    {
        // TODO: should we change this?    
        ext_area.min.x = (kal_int16) ext_region->x1;
        ext_area.min.y = (kal_int16) ext_region->y1;
        ext_area.max.x = (kal_int16) ext_region->x2;
        ext_area.max.y = (kal_int16) ext_region->y2;
    }
	memcpy(&g_pen_ext_stroke_area, &ext_area, sizeof(mmi_pen_handwriting_area_struct));
	#ifdef __MMI_SCREEN_ROTATE__
		if (mmi_frm_get_screen_rotate() != MMI_FRM_SCREEN_ROTATE_0)
		{	 
			mmi_pen_handwriting_in_rotation(&ext_area);
		}
	#endif

    mmi_pen_drv_config_handwriting(area, (U16)num_regions, &ext_area);

    g_pen_num_stroke_area = num_regions;
    memcpy(g_pen_stroke_areas, region_array, sizeof(mmi_pen_handwriting_area_struct) * num_regions);
    /* Stroke minimum offset is used by single-block mode only */
    if (num_regions == 1)
    {
        g_pen_stroke_min_offset_square = MMI_PEN_STROKE_MIN_OFFSET * MMI_PEN_STROKE_MIN_OFFSET;
    }
    else
    {
        g_pen_stroke_min_offset_square = 0;
    }
    
    if (!g_pen_cntx.is_pen_down)
    {
        /* Clear strokes */
        mmi_pen_end_strokes_of_character();        
        mmi_pen_begin_strokes_of_character();
    }
    else
    {
        /* 
         * NOTE: we *cannot* call mmi_pen_reset().
         *
         * For example, assume mmi_pen_change_handwriting_area() is invoked on Button Down.
         * If we invoke mmi_pen_reset() here, it will send MMI_PEN_EVENT_ABORT and reset the button.
         */
        g_pen_cntx.reset_stroke_on_pen_up = 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_stop_capture_strokes
 * DESCRIPTION
 *  Stop capturing stroke
 *  
 *  Note: mmi_pen_reset() should be used to flush driver pen queue
 *  after this function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_stop_capture_strokes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TouchPanelHandAreaStruct area;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_PEN_TRC_STOP_CAPTURE_STROKES);

    area.max.x = -1;
    area.max.y = -1;
    area.min.x = -1;
    area.min.y = -1;
    mmi_pen_drv_config_handwriting(&area, 1, &area);
    g_pen_stroke_max_points = 0;
    g_pen_stroke_points = NULL;
    memset(&g_pen_ext_stroke_area, 0, sizeof(mmi_pen_handwriting_area_struct));
    memset(g_pen_stroke_areas, 0, sizeof(g_pen_stroke_areas));
    g_pen_num_stroke_area = 0;
    /*
     * unfinished stroke is illegal. Applications need to check mmi_pen_peek_stroke_state()
     * * before using mmi_pen_stop_capture_strokes().
     */

    /* 
     * We will call mmi_pen_reset() *later* on Pen Up or Stroke Up event.
     *
     * There might be many pending events in driver queue if MMI task is blocked by 
     * other time-consuming jobs. If there are pending stroke events in driver queue, 
     * it is better to flush driver queue.
     *
     */
	if (!g_pen_cntx.is_send_event_to_new_screen)
	{
		if ((!g_pen_cntx.is_pen_down))
    {
        mmi_pen_reset();
    }
    else
    {
        /* 
         * NOTE: we *cannot* call mmi_pen_reset().
         *
         * For example, assume mmi_pen_stop_capture_strokes() is invoked when scrollbar of inline editor 
         * is scrolled on Pen Move event and the highlighed single-line editor is un-highlighted. 
         * If we invoke mmi_pen_reset() here, it will send MMI_PEN_EVENT_ABORT and reset the scrolling of scrollbar.
         */
        g_pen_cntx.reset_stroke_on_pen_up = 1;
    }
}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_enable_stroke_event
 * DESCRIPTION
 *  This function is used to enable stroke event in single block handwriting mode
 *  To design this API is to enable stroke event. If IME disable stroke event in
 *  single box handwriting mode, IME must invoke this API to enable stroke event
 *  when it finish its work. Please refer mmi_pen_disable_stroke_event for more 
 *  detail information.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 *   //In pen down handler to disable stroke events
 *   void pen_down_hdlr(mmi_pen_point_struct p)
 *   {
 *       if (handwriting_mode == SINGLE_BLOCK)
 *       {
 *           mmi_pen_disable_stroke_event();
 *       }
 *   }
 *
 *   //In pen up handler to enable stroke events
 *   void pen_up_handler(mmi_pen_point_struct p)
 *   {
 *       if (handwriting_mode == SINGLE_BLOCK)
 *       {
 *           mmi_pen_enable_stroke_event();
 *       }
 *   }
 *   //In pen abort handler to enable stroke events
 *   {
 *        if (handwriting_mode == SINGLE_BLOCK)
 *        {
 *            mmi_pen_enable_stroke_event();
 *        }
 *   }
 * </code>
 *****************************************************************************/
void mmi_pen_enable_stroke_event()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM,
        TRC_MMI_FRM_PEN_ENABLE_STROKE_EVENT,
        g_pen_stroke_min_offset_square,
        MMI_PEN_STROKE_MIN_OFFSET * MMI_PEN_STROKE_MIN_OFFSET);
    g_pen_stroke_min_offset_square = MMI_PEN_STROKE_MIN_OFFSET * MMI_PEN_STROKE_MIN_OFFSET;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_disable_stroke_event
 * DESCRIPTION
 *  This function is used to disable stroke events in single-block Handwriting
 *  mode. Please don't use this interface in multi-block handwriting mode.
 *  To design this API is to disable stroke events when pen is down in an area,
 *  where IME will hope to receive pen events instead of stroke events.
 *  The mechanism is based on the original single block pen event mechanism.
 *  That is.
 *    stroke down => pen down
 *    stroke move => pen move if stroke move offset > MMI_PEN_SKIP_MOVE_OFFSET
 *    if square(stroke move offset) > g_pen_stroke_min_offset_square = square(MMI_PEN_STROKE_MIN_OFFSET)
 *    stroke move => pen abort stroke down stroke move
 *
 *  So this API sets the g_pen_stroke_min_offset as 0x7FFF to make sure
 *  stroke move offset will always < g_pen_stroke_min_offset to implement
 *  disable stroke events in the whole touch panel.
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 *   //In pen down handler to disable stroke events
 *   void pen_down_hdlr(mmi_pen_point_struct p)
 *   {
 *       if (handwriting_mode == SINGLE_BLOCK)
 *       {
 *           mmi_pen_disable_stroke_event();
 *       }
 *   }
 *
 *   //In pen up handler to enable stroke events
 *   void pen_up_handler(mmi_pen_point_struct p)
 *   {
 *       if (handwriting_mode == SINGLE_BLOCK)
 *       {
 *           mmi_pen_enable_stroke_event();
 *       }
 *   }
 *   //In pen abort handler to enable stroke events
 *   {
 *        if (handwriting_mode == SINGLE_BLOCK)
 *        {
 *            mmi_pen_enable_stroke_event();
 *        }
 *   }
 * </code>
 *****************************************************************************/
void mmi_pen_disable_stroke_event()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM,
        TRC_MMI_FRM_PEN_DISABLE_STROKE_EVENT,
        g_pen_stroke_min_offset_square,
        MMI_PEN_STROKE_MAX_OFFSET);   
    g_pen_stroke_min_offset_square = MMI_PEN_STROKE_MAX_OFFSET;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_stroke_down_handler
 * DESCRIPTION
 *  Register the Stroke Down handler
 * PARAMETERS
 *  pen_fp      :[IN]   Callback function for Stroke Down event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_stroke_down_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_PEN_TRC_REG_PEN_STROKE_DOWN_HDLR, pen_fp);
    g_pen_stroke_table[MMI_PEN_STROKE_DOWN] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_stroke_move_handler
 * DESCRIPTION
 *  Register the Stroke Move handler
 *  Note: pre and post multiple stroke move handler is not used any more.
 *        So we will remove it gradually.
 * PARAMETERS
 *  begin_fp        :[IN]        Callback function before multiple Stroke Move events
 *  end_fp          :[IN]        Callback function after multiple Stroke Move events
 *  pen_fp          :[IN]        Callback function for Stroke Move event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_stroke_move_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_PEN_TRC_REG_PEN_STROKE_MOVE_HDLR, pen_fp);
    g_pen_stroke_table[MMI_PEN_STROKE_MOVE] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_stroke_up_handler
 * DESCRIPTION
 *  Register the Stroke Up handler
 * PARAMETERS
 *  pen_fp      :[IN]       Callback function for Stroke Up event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_stroke_up_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_PEN_TRC_REG_PEN_STROKE_UP_HDLR, pen_fp);
    g_pen_stroke_table[MMI_PEN_STROKE_UP] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_register_stroke_longtap_handler
 * DESCRIPTION
 *  Register the Stroke Longtap handler
 * PARAMETERS
 *  pen_fp      [IN]        Callback function for Stroke Longtap event.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_register_stroke_longtap_handler(mmi_pen_hdlr pen_fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_PEN_TRC_REG_PEN_STROKE_LONGTAP_HDLR, pen_fp);
    g_pen_stroke_table[MMI_PEN_STROKE_LONGTAP] = pen_fp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_get_stroke_handler
 * DESCRIPTION
 *  This function is used for gets the stroke event handler for current screen.
 * PARAMETERS
 *  stroke_event     :[IN]  Which stroke event's handler is wanted to query.       
 * RETURNS
 *  The handler of stroke event.
 *****************************************************************************/
mmi_pen_hdlr mmi_pen_get_stroke_handler(mmi_pen_stroke_type_enum stroke_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return g_pen_stroke_table[stroke_event];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_peek_stroke_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  has_unfinished_stroke       :[OUT]   Whether there are more strokes to come
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_peek_stroke_state(MMI_BOOL *has_unfinished_stroke)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pen_cntx.is_pen_down)
    {
        *has_unfinished_stroke = MMI_TRUE;
    }
    else
    {
        mmi_pen_event_struct data;

        if (!mmi_pen_lookahead_buffer_peek_event(&data))
        {
            *has_unfinished_stroke = MMI_FALSE;
        }
        else
        {
            /* Even if it is a DCL_PEN_ABORT, we still need to handle it */
            *has_unfinished_stroke = MMI_TRUE;
        }
    }

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_PEN_TRC_PEEK_STROKE_STATE, (int)*has_unfinished_stroke);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_begin_strokes_of_character
 * DESCRIPTION
 *  Start to write a new character
 *  
 *  It is typically coupled with mmi_pen_end_strokes_of_character(), which stops en-queueing
 *  strokes inside 'point_array'.
 *  In mmi_pen_begin_strokes_of_character(), MMI continue to en-queue strokes from the head of 'point_array'.
 *  
 *  (However, simulator does not implement all of these)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_begin_strokes_of_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_PEN_TRC_BEGIN_STROKES_OF_CHAR);

    g_pen_cntx.num_points_queued = 0;

    /* Note: touch_panel_reset_handwriting() is invoked both in mmi_pen_begin_strokes_of_character()
       and mmi_pen_end_strokes_of_character() due to some driver implementation reason */
    mmi_pen_drv_reset_handwriting();
    g_pen_simulate_driver_cntx.ext_enable = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pen_end_strokes_of_character
 * DESCRIPTION
 *  End a written character.
 *  
 *  The following procedures are executed
 *  o Reset handwriting area to original size
 *  o Stop en-queueing new strokes inside 'point_array'. (But incoming strokes are still en-queued in driver ring buffer)
 *  o Append end marker (0xffff, 0xffff) in 'point_array'
 *  This API should be used only if there is no unfinished stroke (checked by mmi_pen_peek_stroke_state()).
 *  After it returns, we may pass 'point_array' to handwriting recognition engine.
 *  
 *  (However, simulator does not implement all of these)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pen_end_strokes_of_character(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_PEN_TRC_END_STROKES_OF_CHAR);
 
    mmi_pen_push_char_end();

    mmi_pen_drv_reset_handwriting();
    g_pen_simulate_driver_cntx.ext_enable = MMI_FALSE;
    /* Stroke minimum offset is used by single-block mode only */
    if (g_pen_num_stroke_area == 1)
    {
        g_pen_stroke_min_offset_square = MMI_PEN_STROKE_MIN_OFFSET * MMI_PEN_STROKE_MIN_OFFSET;
    }
    else
    {
        g_pen_stroke_min_offset_square = 0;
    }

}


/*****************************************************************************
* 
*  Utility functions
* 
*****************************************************************************/



/*****************************************************************************
 * FUNCTION
 *  mmi_pen_check_inside_polygon
 * DESCRIPTION
 *  Check if a point is inside a polygon.
 *  
 * PARAMETERS
 *  polygon     :[IN] The top points of the polygon        
 *  pos         :[IN] point that need to be judged.       
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_pen_check_inside_polygon(mmi_pen_polygon_area_struct *polygon, mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL c = MMI_FALSE;
    S16 i, j;
    S16 nPoints = polygon->num;
    mmi_pen_point_struct *outline = polygon->points;
    S16 x = pos.x;
    S16 y = pos.y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0, j = nPoints - 1; i < nPoints; j = i++)
    {
        mmi_pen_point_struct *a = &outline[i];
        mmi_pen_point_struct *b = &outline[j];

        if (((a->y <= y && y < b->y) || (b->y <= y && y < a->y)) &&
            (x < (b->x - a->x) * (y - a->y) / (b->y - a->y) + a->x))
        {
        		if(c == MMI_TRUE)
					c = MMI_FALSE;
				else
					c = MMI_TRUE;
        }
    }
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, MMI_PEN_TRC_CHECK_INSIDE_POLYGON, pos.x, pos.y, 
        outline[0].x, outline[0].y, outline[1].x, outline[1].y, outline[2].x, outline[2].y, outline[3].x, outline[3].y, c);

    return c;
}


#ifdef __MMI_CLAMSHELL__
mmi_ret mmi_touch_clam_hdlr(mmi_event_struct* evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_GPIO_CLAM_OPEN:
            mmi_pen_unblock();
            break;
        case EVT_ID_GPIO_CLAM_CLOSE:
            mmi_pen_block();
            break;
        default:
            break;        
    
    }
    return MMI_RET_OK;

}

#endif


//#define __MMI_TOUCH_SCREEN_UT__
#if defined(__MMI_TOUCH_SCREEN_UT__)
typedef mmi_ret (*unit_test_func)(void);

typedef struct
{
    U8 index;
    unit_test_func test;
} mmi_unit_test_struct;



#define TS_UT sizeof(g_ts_ut) / sizeof(g_ts_ut[0])




static void mmi_frm_touch_modis_pen_down(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_printf("UT Start: PEN DOWN, x = %d, y = %d \n", pos.x, pos.y);
}


static void mmi_frm_touch_modis_pen_move(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_printf("PEN MOVE, x = %d, y = %d \n", pos.x, pos.y);
}


static void mmi_frm_touch_modis_pen_up(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_printf("PEN UP, x = %d, y = %d \n", pos.x, pos.y);
}


static void mmi_frm_touch_modis_pen_longtap(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_printf("PEN LONGTAP, x = %d, y = %d \n", pos.x, pos.y);
}


static void mmi_frm_touch_modis_pen_repeat(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_printf("PEN REPEAT, x = %d, y = %d \n", pos.x, pos.y);
}


static void mmi_frm_touch_modis_pen_abort(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_printf("PEN ABORT, x = %d, y = %d \n", pos.x, pos.y);
}


static void mmi_frm_touch_modis_stroke_down(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_printf("Stroke Down, x = %d, y = %d \n", pos.x, pos.y);
}

static void mmi_frm_touch_modis_stroke_up(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_printf("Stroke Up, x = %d, y = %d \n", pos.x, pos.y);
}


static void mmi_frm_touch_modis_stroke_move(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_printf("Stroke Move, x = %d, y = %d \n", pos.x, pos.y);
}


static void mmi_frm_touch_move_check_repeat_timer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_pen_MODIS_enqueue_up(11, 11);
}


static void mmi_frm_touch_down_check_longtap_timer_callback(void)
{

    StartTimer(KEY_TIMER_ID_NONE + 2, 1000, mmi_frm_touch_move_check_repeat_timer_callback);
    
}


static void mmi_frm_touch_simulate_at_command(kal_uint8 mode, kal_uint16 x, kal_uint16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    mmi_csta_req_struct *para = (mmi_csta_req_struct *)mmi_construct_msg_local_para(sizeof(mmi_csta_req_struct));
    para->type = mode;
    para->x = x;
    para->y = y;
    message.oslMsgId = MSG_ID_MMI_EQ_SCREEN_TOUCH_REQ_IND;
    message.oslDataPtr = para;
    message.oslPeerBuffPtr = NULL;
    message.oslSrcId = MOD_L4C;
    message.oslDestId = MOD_MMI;
    OslMsgSendExtQueue(&message);
    
}



void mmi_frm_touch_modis_check_simulate_driver_ut(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_register_down_handler(mmi_frm_touch_modis_pen_down);
    mmi_pen_register_long_tap_handler(mmi_frm_touch_modis_pen_longtap);
    mmi_pen_register_up_handler(mmi_frm_touch_modis_pen_up);
    mmi_pen_register_abort_handler(mmi_frm_touch_modis_pen_abort);
    mmi_pen_register_move_handler(mmi_frm_touch_modis_pen_move);
    mmi_pen_register_repeat_handler(mmi_frm_touch_modis_pen_repeat);
    mmi_pen_MODIS_enqueue_down(1, 1);
    mmi_pen_MODIS_enqueue_move(12, 12);
    mmi_pen_MODIS_enqueue_up(9, 9);
    mmi_pen_MODIS_enqueue_down(2, 2);
    StartTimer(KEY_TIMER_ID_NONE + 1, 1000, mmi_frm_touch_down_check_longtap_timer_callback);
      
}

static mmi_pen_point_struct point_array[100];
void mmi_frm_modis_handwriting_ut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*******60 60 180 340************handwriting***/
    /*******40 40 200 360 ***********ext*area**/
    mmi_pen_handwriting_area_struct handwriting = {60, 60, (UI_device_width - 60), (UI_device_height - 60)};
    mmi_pen_handwriting_area_struct ext_area = {40, 40, (UI_device_width - 40), (UI_device_height - 40)};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_stop_capture_strokes();
    mmi_pen_register_stroke_down_handler(mmi_frm_touch_modis_stroke_down);
    mmi_pen_register_stroke_move_handler(mmi_frm_touch_modis_stroke_move);
    mmi_pen_register_stroke_up_handler(mmi_frm_touch_modis_stroke_up);
    mmi_pen_register_down_handler(mmi_frm_touch_modis_pen_down);
    mmi_pen_register_long_tap_handler(mmi_frm_touch_modis_pen_longtap);
    mmi_pen_register_up_handler(mmi_frm_touch_modis_pen_up);
    mmi_pen_register_abort_handler(mmi_frm_touch_modis_pen_abort);
    mmi_pen_register_move_handler(mmi_frm_touch_modis_pen_move);
    mmi_pen_register_repeat_handler(mmi_frm_touch_modis_pen_repeat);
    mmi_pen_start_capture_strokes(100, &point_array, 1, &handwriting, &ext_area);
    mmi_pen_MODIS_enqueue_down(65, 65);
    mmi_pen_MODIS_enqueue_move(30, 30);
    mmi_pen_MODIS_enqueue_up(20, 20);
    mmi_pen_MODIS_enqueue_down(20, 20);
    mmi_pen_MODIS_enqueue_up(70, 70);
    mmi_pen_MODIS_enqueue_down(65, 65);
    mmi_pen_MODIS_enqueue_move(30, 30);
    mmi_pen_MODIS_enqueue_up(20, 20);
    mmi_pen_MODIS_enqueue_down(65, 65);
    mmi_pen_MODIS_enqueue_move(30, 30);
    mmi_pen_MODIS_enqueue_up(20, 20);
    mmi_pen_MODIS_enqueue_down(20, 20);
    mmi_pen_MODIS_enqueue_up(70, 70);
    mmi_pen_MODIS_enqueue_down(65, 65);
    mmi_pen_MODIS_enqueue_move(30, 30);
    mmi_pen_MODIS_enqueue_up(20, 20);
}


static void mmi_frm_touch_modis_at_interactive_timer_callback(void)
{
    mmi_pen_MODIS_enqueue_down(65, 65);
    mmi_pen_MODIS_enqueue_move(30, 30);
    mmi_pen_MODIS_enqueue_up(20, 20);    
}
void mmi_frm_modis_at_interactive()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_stop_capture_strokes();
    mmi_pen_register_stroke_down_handler(mmi_frm_touch_modis_stroke_down);
    mmi_pen_register_stroke_move_handler(mmi_frm_touch_modis_stroke_move);
    mmi_pen_register_stroke_up_handler(mmi_frm_touch_modis_stroke_up);
    mmi_pen_register_down_handler(mmi_frm_touch_modis_pen_down);
    mmi_pen_register_long_tap_handler(mmi_frm_touch_modis_pen_longtap);
    mmi_pen_register_up_handler(mmi_frm_touch_modis_pen_up);
    mmi_pen_register_abort_handler(mmi_frm_touch_modis_pen_abort);
    mmi_pen_register_move_handler(mmi_frm_touch_modis_pen_move);
    mmi_pen_register_repeat_handler(mmi_frm_touch_modis_pen_repeat);
    mmi_frm_touch_simulate_at_command(1, 1, 1);
    mmi_frm_touch_simulate_at_command(1, 12, 12);
    mmi_frm_touch_simulate_at_command(0, 9, 9);
    StartTimer(KEY_TIMER_ID_NONE + 1, 10, mmi_frm_touch_modis_at_interactive_timer_callback);
}


void mmi_frm_at_modis_interactive()
{
    mmi_pen_stop_capture_strokes();
    mmi_pen_register_stroke_down_handler(mmi_frm_touch_modis_stroke_down);
    mmi_pen_register_stroke_move_handler(mmi_frm_touch_modis_stroke_move);
    mmi_pen_register_stroke_up_handler(mmi_frm_touch_modis_stroke_up);
    mmi_pen_register_down_handler(mmi_frm_touch_modis_pen_down);
    mmi_pen_register_long_tap_handler(mmi_frm_touch_modis_pen_longtap);
    mmi_pen_register_up_handler(mmi_frm_touch_modis_pen_up);
    mmi_pen_register_abort_handler(mmi_frm_touch_modis_pen_abort);
    mmi_pen_register_move_handler(mmi_frm_touch_modis_pen_move);
    mmi_pen_register_repeat_handler(mmi_frm_touch_modis_pen_repeat);
    mmi_pen_MODIS_enqueue_down(1, 1);
    mmi_pen_MODIS_enqueue_move(12, 12);
    mmi_pen_MODIS_enqueue_up(9, 9);
    mmi_pen_MODIS_enqueue_down(3, 3);
    mmi_pen_MODIS_enqueue_move(13, 13);
    mmi_pen_MODIS_enqueue_up(10, 10);        
    mmi_frm_touch_simulate_at_command(1, 65, 65);
    mmi_frm_touch_simulate_at_command(1, 30, 30);
    mmi_frm_touch_simulate_at_command(0, 20, 20);    
}


void mmi_frm_block_disable_ut(void)
{

    mmi_pen_enable();
    MMI_ASSERT(g_pen_cntx.is_enabled);
    MMI_ASSERT(g_pen_cntx.disable_ref_cnt == 0);
    // first disable and then block
    mmi_pen_disable();
    mmi_pen_block();
    MMI_ASSERT(g_pen_cntx.disable_ref_cnt == 2);
    mmi_pen_enable();
    MMI_ASSERT(g_pen_cntx.disable_ref_cnt == 1);
    MMI_ASSERT(g_pen_cntx.is_enabled == 0);
    MMI_ASSERT(g_pen_cntx.is_blocked == 1);
    mmi_pen_disable();
    mmi_pen_unblock();
    mmi_pen_enable();
    MMI_ASSERT(g_pen_cntx.disable_ref_cnt == 0);
    MMI_ASSERT(g_pen_cntx.is_enabled == 1);
    MMI_ASSERT(g_pen_cntx.is_blocked == 0);
    // first block and then disable
    mmi_pen_block();
    mmi_pen_disable();
    mmi_pen_unblock();
    MMI_ASSERT(g_pen_cntx.disable_ref_cnt == 1);
    MMI_ASSERT(g_pen_cntx.is_enabled == 0);
    mmi_pen_enable();
    MMI_ASSERT(g_pen_cntx.disable_ref_cnt == 0);
    MMI_ASSERT(g_pen_cntx.is_enabled == 1);
    mmi_pen_disable();
    mmi_pen_disable();
    MMI_ASSERT(g_pen_cntx.disable_ref_cnt == 2);
    MMI_ASSERT(g_pen_cntx.is_enabled == 0);
    mmi_pen_enable();
    mmi_pen_enable();
}

static TouchPanelMultipleEventStruct driver[10] = 
{
	{2,0, 0xffff1111, {{PEN_DOWN, 233, 364, 10}, {PEN_DOWN, 161, 117, 10}}},
	{2,0, 0xffff1112, {{PEN_REPEAT_HOLD, 161, 117, 20},{PEN_REPEAT_HOLD, 233, 364, 20}}},//need to revert
	{2,0, 0xffff1113, {{PEN_REPEAT_HOLD, 233, 364, 30},{PEN_REPEAT_HOLD, 161, 117, 30}}},
	{3,0, 0xffff1114, {{PEN_REPEAT_HOLD, 233, 364, 40},{PEN_REPEAT_HOLD, 161, 117, 40}, {PEN_DOWN, 216, 223, 40}}},
	{3,0, 0xffff1115, {{PEN_MOVE, 200, 388, 50},{PEN_MOVE, 119, 161, 50}, {PEN_MOVE, 175, 248, 50}}},
	{3,0, 0xffff1116, {{PEN_MOVE, 197, 390, 60},{PEN_MOVE, 116, 163, 60}, {PEN_MOVE, 171, 252, 60}}},
	{3,0, 0xffff1117, {{PEN_MOVE, 193, 392, 70},{PEN_MOVE, 113, 165, 70}, {PEN_MOVE, 168, 254, 70}}},
	{4,0, 0xffff1118, {{PEN_MOVE, 196, 393, 80},{PEN_MOVE, 119, 256, 80}, {PEN_DOWN, 10, 10, 80}, {PEN_UP, 119, 256, 80}}},
	{3,0, 0xffff1119, {{PEN_MOVE, 20, 20, 90}, {PEN_UP, 119, 256, 90},{PEN_UP, 119, 256, 90}}},
	{1,0, 0xffff1120, {{PEN_UP, 119, 256, 100}}},
	//{1,0, 1111, {{PEN_DOWN, 233, 364, 0}}},
	{1,0, 1112, {{PEN_UP, 119, 256, 0}}},
	//{2,0, 0xffff1111, {{PEN_MOVE, 329, 426, 10}, {PEN_MOVE, 175, 426, 10}}},
};

void mmi_frm_multi_touch_ut(void)
{
	U32 i;
	TouchPanelMultipleEventStruct drv_evt;
	g_frm_touch_queue.queue = multi_touch_queue;
	g_frm_touch_queue.read = g_frm_touch_queue.write = 0;
	g_pen_cntx.touch_mode = MMI_FRM_MULTI_TOUCH;
	reset_pre_touch_event_status();
	for(i=0; i<10; i++)
	{   
		drv_evt = driver[i];
        if(mmi_touch_reorder_event(&drv_evt))
        {
			mmi_touch_enqueue(&drv_evt);
		}
	}
	while(g_frm_touch_queue.write > 0)
	{
		multi_touch_get_event();
		update_pre_touch_data();
	}
}




const static mmi_unit_test_struct g_ts_ut[] = 
{

    {1, mmi_frm_touch_modis_check_simulate_driver_ut},
    {2, mmi_frm_modis_handwriting_ut},
    {3, mmi_frm_modis_at_interactive},
    {4, mmi_frm_at_modis_interactive},
    {5, mmi_frm_block_disable_ut},
    {6, mmi_frm_multi_touch_ut},
    
};

void mmi_frm_touch_screen_ut(U8 index)
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
        for (i = 0; i < TS_UT; i++)
        {
            g_ts_ut[i].test();
        }
    }
    else
    {
        for (i = 0; i < TS_UT; i++)
        {
            if (g_ts_ut[i].index == index)
            {
                g_ts_ut[i].test();
            }
        }
    }
}

#endif /* __MMI_TOUCH_SCREEN_UT__ */
#endif /* __MMI_TOUCH_SCREEN__ */




