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
 *  vfx_input_event.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Define Venus input event
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_INPUT_EVENT_H__
#define __VFX_INPUT_EVENT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxBase
#include "vfx_cpp_base.h"
// For VfxObjList
#include "vfx_object_list.h"

#include "vfx_datatype.h"
#include "vfx_object.h"
#include "vfx_basic_type.h"

extern "C" 
{
#include "mmi_features.h"
#include "GlobalConstants.h"
}


/***************************************************************************** 
 * Define
 *****************************************************************************/

/*
 * The key special flag which define by Pluto.
 * In Venus, we remap the flag, and we also add our additional flag
 */

/* 
 * Special key means, the keys which can be used together with
 * other keys, such Ctrl + C, Alt + Enter.
 * In QWERTY project, the translate key handler will get the special key flag,
 * the flag indicate the special key is down or not at that time.
 * The following macro is the position of the specific special key in the special key flag
 * of the translate key handler.
 * If the applications want to know the special key is down or not in translate key hander,
 * he may use the following code:
 *  VFX_BOOL shift_down = 
 *            (special_key_flags & VFX_SPECIAL_KEY_FLAG_SHIFT == VFX_SPECIAL_KEY_FLAG_SHIFT)
 *  Notes: The special key flag has special meanings for Input Method Module.
 */
#define VFX_SPECIAL_KEY_FLAG_SHIFT      MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT
/* SEE ALSO: VFX_SPECIAL_KEY_FLAG_SHIFT */
#define VFX_SPECIAL_KEY_FLAG_ALT        MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_ALT
/* SEE ALSO: VFX_SPECIAL_KEY_FLAG_SHIFT */
#define VFX_SPECIAL_KEY_FLAG_CAPSLOCK   MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_CAPSLOCK
/* SEE ALSO: VFX_SPECIAL_KEY_FLAG_SHIFT */
#define VFX_SPECIAL_KEY_FLAG_CTRL       MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_CTRL      
/* SEE ALSO: VFX_SPECIAL_KEY_FLAG_SHIFT */
#define VFX_SPECIAL_KEY_FLAG_FN         MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN        
/* SEE ALSO: VFX_SPECIAL_KEY_FLAG_SHIFT */
#define VFX_SPECIAL_KEY_FLAG_NUMLOCK    MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_NUMLOCK   

/* 
 *  Venus Addition Flag, we define it from high bit to low bit.
 *  So we can avoid conflict with pluto.
 */
#define VFX_SPECIAL_KEY_FLAG_ACCESSKEY  0x800000

#if defined(__TOUCH_PANEL_CAPACITY__) || defined(__TOUCH_PANEL_MULTITOUCH__)
#define VFX_PEN_MULTI_TOUCH_MAX_FINGER 5
#else
#define VFX_PEN_MULTI_TOUCH_MAX_FINGER 1
#endif


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/*
 * Predefine classes
 */
class VfxFrame;

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
typedef struct _vm_pen_event_struct vm_pen_event_struct;
typedef struct _vm_key_event_struct vm_key_event_struct;
#endif


// VfxKeyCodeEnum defines all key codes for key events.
//
// SEE ALSO: mmi_keypads_enum, VfxKeyEvent, VfxControl::registerKeyHandler
enum VfxKeyCodeEnum
{
    VFX_KEY_CODE_UNKNOWN = -1,

    // We match Venus Key code as the same as pluto, so that we can speed up the dispatch
    VFX_KEY_CODE_BEGIN = 0,
    
    VFX_KEY_CODE_0 = KEY_0,
    VFX_KEY_CODE_1 = KEY_1,
    VFX_KEY_CODE_2 = KEY_2,
    VFX_KEY_CODE_3 = KEY_3,
    VFX_KEY_CODE_4 = KEY_4,
    VFX_KEY_CODE_5 = KEY_5,
    VFX_KEY_CODE_6 = KEY_6,
    VFX_KEY_CODE_7 = KEY_7,
    VFX_KEY_CODE_8 = KEY_8,
    VFX_KEY_CODE_9 = KEY_9,

    VFX_KEY_CODE_LSK = KEY_LSK,
    VFX_KEY_CODE_RSK = KEY_RSK,
    VFX_KEY_CODE_CSK = KEY_CSK,

    VFX_KEY_CODE_ENTER = KEY_ENTER,
    VFX_KEY_CODE_WAP = KEY_WAP,
    VFX_KEY_CODE_IP = KEY_IP,
    
    VFX_KEY_CODE_ARROW_UP = KEY_UP_ARROW,
    VFX_KEY_CODE_ARROW_DOWN = KEY_DOWN_ARROW,
    VFX_KEY_CODE_ARROW_LEFT = KEY_LEFT_ARROW,
    VFX_KEY_CODE_ARROW_RIGHT = KEY_RIGHT_ARROW,
    
    VFX_KEY_CODE_SEND = KEY_SEND,
    VFX_KEY_CODE_END = KEY_END,
    VFX_KEY_CODE_CLEAR = KEY_CLEAR,
    VFX_KEY_CODE_STAR = KEY_STAR,
    VFX_KEY_CODE_POUND = KEY_POUND,
    VFX_KEY_CODE_VOL_UP = KEY_VOL_UP,
    VFX_KEY_CODE_VOL_DOWN = KEY_VOL_DOWN,
    VFX_KEY_CODE_CAMERA = KEY_CAMERA,

    VFX_KEY_CODE_QUICK_ACS = KEY_QUICK_ACS,
    VFX_KEY_CODE_EXTRA_1 = KEY_EXTRA_1,
    VFX_KEY_CODE_EXTRA_2 = KEY_EXTRA_2,
    VFX_KEY_CODE_PLAY_STOP = KEY_PLAY_STOP,
    VFX_KEY_CODE_FWD = KEY_FWD,
    VFX_KEY_CODE_BACK = KEY_BACK,
    VFX_KEY_CODE_POWER = KEY_POWER,
    VFX_KEY_CODE_EXTRA_A = KEY_EXTRA_A,
    VFX_KEY_CODE_EXTRA_B = KEY_EXTRA_B,
    VFX_KEY_CODE_SEND1 = KEY_SEND1,
    VFX_KEY_CODE_SEND2 = KEY_SEND2,

    VFX_KEY_CODE_HOME = KEY_HOME,
    
    VFX_KEY_CODE_A = KEY_A,
    VFX_KEY_CODE_B = KEY_B,
    VFX_KEY_CODE_C = KEY_C,
    VFX_KEY_CODE_D = KEY_D,
    VFX_KEY_CODE_E = KEY_E,
    VFX_KEY_CODE_F = KEY_F,
    VFX_KEY_CODE_G = KEY_G,
    VFX_KEY_CODE_H = KEY_H,
    VFX_KEY_CODE_I = KEY_I,
    VFX_KEY_CODE_J = KEY_J,
    VFX_KEY_CODE_K = KEY_K,
    VFX_KEY_CODE_L = KEY_L,
    VFX_KEY_CODE_M = KEY_M,
    VFX_KEY_CODE_N = KEY_N,
    VFX_KEY_CODE_O = KEY_O,
    VFX_KEY_CODE_P = KEY_P,
    VFX_KEY_CODE_Q = KEY_Q,
    VFX_KEY_CODE_R = KEY_R,
    VFX_KEY_CODE_S = KEY_S,
    VFX_KEY_CODE_T = KEY_T,
    VFX_KEY_CODE_U = KEY_U,
    VFX_KEY_CODE_V = KEY_V,
    VFX_KEY_CODE_W = KEY_W,
    VFX_KEY_CODE_X = KEY_X,
    VFX_KEY_CODE_Y = KEY_Y,
    VFX_KEY_CODE_Z = KEY_Z,
    
    VFX_KEY_CODE_SPACE = KEY_SPACE,
    VFX_KEY_CODE_TAB = KEY_TAB,
    VFX_KEY_CODE_DEL = KEY_DEL,
    VFX_KEY_CODE_ALT = KEY_ALT,
    VFX_KEY_CODE_CTRL = KEY_CTRL,
    VFX_KEY_CODE_WIN = KEY_WIN,
    VFX_KEY_CODE_SHIFT = KEY_SHIFT,
    VFX_KEY_CODE_QUESTION = KEY_QUESTION,
    VFX_KEY_CODE_PERIOD = KEY_PERIOD,
    VFX_KEY_CODE_COMMA = KEY_COMMA,
    VFX_KEY_CODE_EXCLAMATION = KEY_EXCLAMATION,
    VFX_KEY_CODE_APOSTROPHE = KEY_APOSTROPHE,
    VFX_KEY_CODE_AT = KEY_AT,
    VFX_KEY_CODE_BACKSPACE = KEY_BACKSPACE,
    VFX_KEY_CODE_QWERTY_ENTER = KEY_QWERTY_ENTER,
    VFX_KEY_CODE_FN = KEY_FN,
    VFX_KEY_CODE_SYMBOL = KEY_SYMBOL,
    VFX_KEY_CODE_NUM_LOCK = KEY_NUM_LOCK,
    VFX_KEY_CODE_QWERTY_MENU = KEY_QWERTY_MENU,
    VFX_KEY_CODE_OK = KEY_OK,
    VFX_KEY_CODE_DOLLAR = KEY_DOLLAR,
    VFX_KEY_CODE_QWERTY = KEY_QWERTY,

    VFX_KEY_CODE_END_OF_NORMAL,

    /* Special key codes */
    VFX_KEY_CODE_START_OF_SPECIAL,
    VFX_KEY_CODE_SPECIAL_ALL,
    VFX_KEY_CODE_SPECIAL_ALL_SOFT_KEYS,
    VFX_KEY_CODE_SPECIAL_ALL_ARROW,
    VFX_KEY_CODE_SPECIAL_ALL_NUMBER,
    VFX_KEY_CODE_SPECIAL_ALL_IME_SYM_KEYS,
    
    VFX_KEY_CODE_END_OF_ENUM
};

/*
 * The key input event type.
 *
 * SEE ALSO: VfxKeypad
 */
enum VfxKeyEventTypeEnum
{
    VFX_KEY_EVENT_TYPE_UNKNOWN          = -1,
    VFX_KEY_EVENT_TYPE_FULL_PRESS_DOWN  = KEY_FULL_PRESS_DOWN,
    VFX_KEY_EVENT_TYPE_DOWN             = KEY_EVENT_DOWN,
    VFX_KEY_EVENT_TYPE_UP               = KEY_EVENT_UP,
    VFX_KEY_EVENT_TYPE_LONG_PRESS       = KEY_LONG_PRESS,
    VFX_KEY_EVENT_TYPE_REPEAT           = KEY_REPEAT,
    VFX_KEY_EVENT_TYPE_HALF_PRESS_DOWN  = KEY_HALF_PRESS_DOWN,
    VFX_KEY_EVENT_TYPE_HALF_PRESS_UP    = KEY_HALF_PRESS_UP,    
    VFX_KEY_EVENT_TYPE_END_OF_ENUM
};

/*
 * The pen input event type.
 *
 * SEE ALSO: VfxPenEvent
 */
enum VfxPenEventTypeEnum
{
    // Unknown pen event
    VFX_PEN_EVENT_TYPE_UNKNOWN = 0,
    // Pen down event
    VFX_PEN_EVENT_TYPE_DOWN,
    // Pen log tap event
    VFX_PEN_EVENT_TYPE_LONG_TAP,
    // Pen move event
    VFX_PEN_EVENT_TYPE_MOVE,
    // Pen up event
    VFX_PEN_EVENT_TYPE_UP,
    // Pen abort event
    VFX_PEN_EVENT_TYPE_ABORT,

    // Stroke down event
    VFX_PEN_EVENT_TYPE_STROKE_DOWN,
    // Stroke move event
    VFX_PEN_EVENT_TYPE_STROKE_MOVE,
    // Stroke up event
    VFX_PEN_EVENT_TYPE_STROKE_UP,

    VFX_PEN_EVENT_TYPE_END_OF_ENUM
};

/*
 * The key source type.
 *
 * SEE ALSO: VfxKeyEvent
 */
enum VfxKeySourceEnum
{
    VFX_KEY_SOURCE_UNKNOWN          = -1,
    VFX_KEY_SOURCE_ACCESSKEY,
    VFX_KEY_SOURCE_FOCUSKEY,
    VFX_KEY_SOURCE_END_OF_ENUM
};

enum VfxPenTouchModeEnum
{
    VFX_PEN_TOUCH_MODE_SINGLE_TOUCH,
    VFX_PEN_TOUCH_MODE_MULTI_TOUCH,
    VFX_PEN_TOUCH_MODE_END_OF_ENUM
};

/*
 * SEE ALSO: mmi_pen_point_struct
 */
struct VfxPenStrokePoint
{
    VfxS16 x, y;
};

/*
 * SEE ALSO: mmi_pen_handwriting_area_struct 
 */
struct VfxPenStrokeHandWritingRegion
{
    VfxS16 x1, y1, x2, y2;
};

// Pen abort reason enum
enum VfxPenAbortReasonEnum 
{
    VFX_PEN_ABORT_REASON_DEFAULT,
    VFX_PEN_ABORT_REASON_CAPTURE_SWIPE,
    VFX_PEN_ABORT_REASON_END_OF_ENUM
};


/***************************************************************************** 
 * Class VfxInputEventArgs
 *****************************************************************************/

/*
 * Internal used.
 */
class VfxInputEventArgs : public VfxBase
{
public:
    // Internal used.
    VfxObject *source;
    // Internal used.
    VfxObject *target;
};


/***************************************************************************** 
 * Class VfxKeyEvent
 *****************************************************************************/
 
/*
 * VfxKeyEvent is a structure provides a key event information.
 *
 * SEE ALSO: VfxKeypad, VfxControl, VfxFrame::onKeyInput, mmi_frm_set_app_translate_key_handler
 */
class VfxKeyEvent : public VfxInputEventArgs
{
// Variable
public:
    // Key input event type
    VfxKeyEventTypeEnum type;    
    // Key code
    VfxKeyCodeEnum      keyCode;
    // UCS2
    VfxWChar            ucs2;
    // Key special flag, see VFX_SPECIAL_KEY_FLAG_XXXX.
    VfxU32              specialKeyFlag;
    // Time stemp of the key input event
    VfxMsec             timeStamp;

    // A helper to return whether this key is routing by accesskey or focuskey.
    VfxBool isAccessKey()
    {
        return (specialKeyFlag & VFX_SPECIAL_KEY_FLAG_ACCESSKEY) != 0;
    }

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    // Internal Used
    VfxKeyEvent() {}
    VfxKeyEvent(vm_key_event_struct &event);

    operator vm_key_event_struct();
#endif
};


class VfxTouchPos : public VfxBase
{
public:
    VfxMsec             timeStamp;      // invoke time.
    VfxPoint            pos;            // pen position.
};


class VfxTouchEvent : public VfxBase
{
public:
    VfxS16 id;
    // Pen input event type.
    VfxPenEventTypeEnum type;
    // Previous pen input event type.
    VfxPenEventTypeEnum prevType;

    // Time stemp of the pen input event.
    VfxMsec timeStamp;
    // Time stemp of the previous pen input event.
    VfxMsec prevTimeStamp;
    // Time stemp of the nearest down pen input event.
    VfxMsec downTimeStamp;

    // The position of the pen event, on global coordinate.
    // SEE ALSO: prevPos, downPos, getRelPos
    VfxPoint pos;
    // The position of the previois pen event, on global coordinate.
    // SEE ALSO: pos, downPos, getRelPrevPos
    VfxPoint prevPos;
    // The position of the nearest down pen event, on global coordinate.
    // SEE ALSO: pos, prevPos, getRelDownPos
    VfxPoint downPos;

// Method
public:
    // Get the relative position of the pen input event.
    // RETURNS: The pen position relative to the given frame.
    // SEE ALSO: pos
    VfxPoint getRelPos(
        const VfxFrame *relTo
    ) const;
    
    // Get the relative position of the previois pen input event.
    // RETURNS: The previois pen position relative to the given frame.
    // SEE ALSO: prevPos
    VfxPoint getRelPrevPos(
        const VfxFrame *relTo
    ) const;
    
    // Get the relative position of the nearest down pen input event.
    // RETURNS: The nearest pen down position relative to the given frame.
    // SEE ALSO: downPos
    VfxPoint getRelDownPos(
        const VfxFrame *relTo
    ) const;
};


/***************************************************************************** 
 * Class VfxPenEvent
 *****************************************************************************/

/*
 * VfxPenEvent is a structure provides a pen event information.
 *
 * SEE ALSO: VfxPen, VfxControl, VfxFrame::onPenInput
 */
class VfxPenEvent : public VfxInputEventArgs
{
// Variable
public:
    // Pen input event type.
    VfxPenEventTypeEnum type;

    // Time stemp of the pen input event.
    VfxMsec timeStamp;
    // Time stemp of the previous pen input event.
    VfxMsec prevTimeStamp;
    // Time stemp of the nearest down pen input event.
    VfxMsec downTimeStamp;

    // The position of the pen event, on global coordinate.
    // SEE ALSO: prevPos, downPos, getRelPos
    VfxPoint pos;
    VfxPoint predictPos;
    // The position of the previois pen event, on global coordinate.
    // SEE ALSO: pos, downPos, getRelPrevPos
    VfxPoint prevPos;
    // The position of the nearest down pen event, on global coordinate.
    // SEE ALSO: pos, prevPos, getRelDownPos
    VfxPoint downPos;

    // Relative object list
    VfxObjList relObjList;


    // Number of multi touch events
    VfxU8 touchCount;
    // Multi touch events
    VfxTouchEvent touchEvents[VFX_PEN_MULTI_TOUCH_MAX_FINGER];
    // Internal used. Pressure value.
    VfxU32 pressure;

// Method
public:
    // Get the relative position of the pen input event.
    // RETURNS: The pen position relative to the given frame.
    // SEE ALSO: pos
    VfxPoint getRelPos(
        const VfxFrame *relTo
    ) const;
    
    // Get the relative position of the previois pen input event.
    // RETURNS: The previois pen position relative to the given frame.
    // SEE ALSO: prevPos
    VfxPoint getRelPrevPos(
        const VfxFrame *relTo
    ) const;
    
    // Get the relative position of the nearest down pen input event.
    // RETURNS: The nearest pen down position relative to the given frame.
    // SEE ALSO: downPos
    VfxPoint getRelDownPos(
        const VfxFrame *relTo
    ) const;

    // Get the relative position of the predicted pen input event.
    // RETURNS: The predicted pen position relative to the given frame.
    // SEE ALSO: pos
    VfxPoint getRelPredictPos(
        const VfxFrame *relTo
    ) const;

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
// Internal Used
public:
    VfxPenEvent() {}
    VfxPenEvent(vm_pen_event_struct &event);

    operator vm_pen_event_struct();
#endif
};


/***************************************************************************** 
 * Global function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vfxKeyCodeCheck
 * DESCRIPTION
 *  Check the test key code whatever own the given normal key code
 * PARAMETERS
 *  testKeyCode   [IN]    the key code to be checked
 *  normalKeyCode [IN]    the normal key code to check
 * RETURNS
 *
 *****************************************************************************/
extern VfxBool vfxKeyCodeCheck(VfxKeyCodeEnum testKeyCode, VfxKeyCodeEnum normalKeyCode);

#endif /* __VFX_INPUT_EVENT_H__ */

