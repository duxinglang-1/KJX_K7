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
 *  vcp_matrix.h
 *
 * Project:
 * --------
 *  Venus UI Component
 *
 * Description:
 * ------------
 *  Basic class to handle matrix
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef __VCP_MATRIX_H__
#define __VCP_MATRIX_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vcp_matrix_item.h"
#include "vcp_squeeze_filter.h"
#include "vcp_jelly_filter.h"
#include "vcp_softkey.h"

#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_signal.h"
#include "vfx_cpp_base.h"
#include "vfx_input_event.h"
#include "vfx_timer.h"
#include "vfx_animation.h"
#include "vfx_basic_type.h"
#include "vfx_frame.h"
#include "vfx_image_src.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef __MMI_FTE_SUPPORT__
#if defined(__MMI_MAINLCD_240X320__) && !defined (__MMI_VECTOR_FONT_SUPPORT__)
#undef VCP_SIMPLE_MATRIX_TEXT_UNDER_ICON
#define VCP_SIMPLE_MATRIX_WITH_TITLE
#define VCP_SIMPLE_MATRIX_JUMP_EFFECT_FACTOR    (0.2f)  /* Jump effect parameter */
#else
#define VCP_SIMPLE_MATRIX_TEXT_UNDER_ICON   /* Vector font is preferred for smaller text */
#undef VCP_SIMPLE_MATRIX_WITH_TITLE
#define VCP_SIMPLE_MATRIX_JUMP_EFFECT_FACTOR    (0.1f)  /* Jump effect parameter */
#endif
#elif defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) 
#define VCP_SIMPLE_MATRIX_TEXT_UNDER_ICON   /* Vector font is preferred for smaller text */
#undef VCP_SIMPLE_MATRIX_WITH_TITLE
#define VCP_SIMPLE_MATRIX_JUMP_EFFECT_FACTOR    (0.1f)  /* Jump effect parameter */
#else
#undef VCP_SIMPLE_MATRIX_TEXT_UNDER_ICON
#define VCP_SIMPLE_MATRIX_WITH_TITLE
#define VCP_SIMPLE_MATRIX_JUMP_EFFECT_FACTOR    (0.2f)  /* Jump effect parameter */
#endif


#if defined(__CPU_ARM9EJ_S__)
// Add rotation effect in drag and move mode. 
#define VCP_SIMPLE_MATRIX_ROTATE_IN_DRAG_MODE   
#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
enum VcpMatrixEffectState
{
    // Squeeze effect of highlight switch.
    VCP_MATRIX_EFFECT_SQUEEZE = 0,
    // Jump effect of highlight switch.
    VCP_MATRIX_EFFECT_JUMP,
    // Jelly effect of highlight switch.
    VCP_MATRIX_EFFECT_JELLY,
    // Bubble effect of highlight switch.
    VCP_MATRIX_EFFECT_BUBBLE,
    // Rotate effect of highlight switch.
    VCP_MATRIX_EFFECT_ROTATE,
    // None effect of highlight switch.
    VCP_MATRIX_EFFECT_NONE,
    // End of highlight effect.
    VCP_MATRIX_EFFECT_TOTAL
};


enum VcpMatrixSoftkeyState
{
    // The state of softkey in matrix is enabled.
    VCP_MATRIX_SOFTKEY_ENABLED = 0,
    // The state of softkey in matrix is disabled.
    VCP_MATRIX_SOFTKEY_DISABLED,
    // The state of softkey in matrix is resetted.
    VCP_MATRIX_SOFTKEY_RESET,
    // End of softkey state.
    VCP_MATRIX_SOFTKEY_TOTAL
};

/*
 * Simple Matrix is a simple component that can support 
 * 1. Drag-n-move 
 * 2. A few highlight switching effects
 */
class VcpSimpleMatrix : public VfxControl
{
// Declaration
public:
    enum PenStateEnum
    {
        // Pen down state.
        PEN_STATE_DOWN = 0,
        // Pen move state.
        PEN_STATE_MOVE,
        // Pen up state.
        PEN_STATE_UP,
        // Long tab state.
        PEN_STATE_LONG_TAP,
        // End of pen state.
        PEN_STATE_TOTAL
    };

    enum DirectionEnum
    {
        // Left ward.
        DIRECTION_LEFTWARD = 0,
        // Right ward.
        DIRECTION_RIGHTWARD,
        // Up ward.
        DIRECTION_UPWARD,
        // Down ward.
        DIRECTION_DOWNWARD,
        // End of direction.
        DIRECTION_TOTAL
    };
    
    enum
    {
        // The number of total items in simple matrix.
        TOTAL_ITEMS = 12,
    #if defined(__MMI_MAINLCD_320X240__)
        // The default value of rows in simple matrix.
        DEFAULT_ROWS = 3,
        // The default value of columns in simple matrix.
        DEFAULT_COLUMNS = 4,
    #else
        // The default value of rows in simple matrix.
        DEFAULT_ROWS = 4,
        // The default value of columns in simple matrix.
        DEFAULT_COLUMNS = 3,
    #endif
        
    #if defined(__MMI_VUI_LITE_DISPLAY__)
        // The interval of bubble effect.
        BUBBLE_INTERVAL = 100,
        // The interval of rotate effect.
        ROTATE_INTERVAL = 200,
        // The interval of squeeze effect.
        SQUEEZED_INTERVAL = 400,
        // The interval of jelly effect.
        JELLY_INTERVAL = 400,
        // The interval of none effect.
        NONE_EFFECT_INTERVAL = 100,
    #else /* __MMI_VUI_LITE_DISPLAY__ */
        // The interval of bubble effect.
        BUBBLE_INTERVAL = 60,
        // The interval of rotate effect.
        ROTATE_INTERVAL = 200,
        // The interval of squeeze effect.
        SQUEEZED_INTERVAL = 400,
        // The interval of jelly effect.
        JELLY_INTERVAL = 400,
        // The interval of none effect.
        NONE_EFFECT_INTERVAL = 100,
    #endif /* __MMI_VUI_LITE_DISPLAY__ */

        // Initial wait time after pen down before entering drag-n-move mode (no visible changes on screen yet)
        LONG_TAP_INTERVAL = 800,
        // Duration of the shaking effect.
        DRAG_MOVE_DURATION = 200,
        // Initial entry time for drag-n-move mode (resizing the highlight).
        DRAG_MOVE_START = 300,
        // The size of buffer the nextcoming move operations when pressing key rapidly.
        FAST_MOVE_QUEUE_SIZE = 10,

    #if defined(__MMI_MAINLCD_240X400__)
        // Width of normal icon.
        NORMAL_ICON_WIDTH = 78,
        // Height of normal icon.
        NORMAL_ICON_HEIGHT = 80,
        // Width of highlight icon (larger than actual image size due to effect).
        HIGHLIGHT_ICON_WIDTH = 180,  
        // Height of highlight icon (larger than actual image size due to effect).        
        HIGHLIGHT_ICON_HEIGHT = 180, 
        
    #ifdef __MMI_VECTOR_FONT_SUPPORT__
        // The gap between drag frame and normal icon.
        HIGHLIGHT_DRAG_GAP = 8,
        // The y offset of highlight image.
        HIGHLIGHT_IMAGE_OFFSET_Y = 7,
    #else /* __MMI_VECTOR_FONT_SUPPORT__ */
        // The gap between drag frame and normal icon.
        HIGHLIGHT_DRAG_GAP = 12,
        // The y offset of highlight image.
        HIGHLIGHT_IMAGE_OFFSET_Y = 7,
    #endif /* __MMI_VECTOR_FONT_SUPPORT__ */
        
        // Width of highlight image(Only used for effect filter).
        HIGHLIGHT_IMAGE_WIDTH = 180,
        // Height of highlight image(Only used for effect filter).
        HIGHLIGHT_IMAGE_HEIGHT = 180,
        // The y offset of highlight image.
        HIGHLIGHT_IMAGE_OFFSET_X = 11,
        // The x offset for effect(Only used for effect filter).
        HIGHLIGHT_IMAGE_OFFSET_X_GAP = 68,
        // The y offset for effect(Only used for effect filter).
        HIGHLIGHT_IMAGE_OFFSET_Y_GAP = 68,
        // The x position of highlight icon.
        HIGHLIGHT_ICON_X = 90,
        // The y position of highlight icon.
        HIGHLIGHT_ICON_Y = 90,
        // The gap between image and frame
        NORMAL_IMAGE_Y = 0,
    #elif defined (__MMI_MAINLCD_240X320__)
        // Width of normal icon.
        NORMAL_ICON_WIDTH = 66,
#ifdef __MMI_VECTOR_FONT_SUPPORT__
        // Height of normal icon.
        NORMAL_ICON_HEIGHT = 66,
#else /* __MMI_VECTOR_FONT_SUPPORT__ */
        // Height of normal icon.
        NORMAL_ICON_HEIGHT = 59,
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */
        // Width of highlight icon (larger than actual image size due to effect).
        HIGHLIGHT_ICON_WIDTH = 120,
        // Height of highlight icon (larger than actual image size due to effect).        
        HIGHLIGHT_ICON_HEIGHT = 120,
        // The gap between drag frame and normal icon.
        HIGHLIGHT_DRAG_GAP = 0,
        // Width of highlight image(Only used for effect filter).
        HIGHLIGHT_IMAGE_WIDTH  = 120,
        // Height of highlight image(Only used for effect filter).
        HIGHLIGHT_IMAGE_HEIGHT = 120,
        // The x offset of highlight image.
        HIGHLIGHT_IMAGE_OFFSET_X = 10,
        // The y offset of highlight image.
        HIGHLIGHT_IMAGE_OFFSET_Y = 10,
        // The x offset for effect(Only used for effect filter).
        HIGHLIGHT_IMAGE_OFFSET_X_GAP = 45,
        // The y offset for effect(Only used for effect filter).
        HIGHLIGHT_IMAGE_OFFSET_Y_GAP = 45,
        // The x position of highlight icon.
        HIGHLIGHT_ICON_X = 60,
        // The y position of highlight icon.
        HIGHLIGHT_ICON_Y = 60,
        // The gap between image and frame
        NORMAL_IMAGE_Y = 0,
    #elif defined (__MMI_MAINLCD_320X480__)
        // Width of normal icon.
        NORMAL_ICON_WIDTH = 100,
        // Height of normal icon.
        NORMAL_ICON_HEIGHT = 122,
        // Width of highlight icon (larger than actual image size due to effect).
        HIGHLIGHT_ICON_WIDTH = 250,  
        // Height of highlight icon (larger than actual image size due to effect).        
        HIGHLIGHT_ICON_HEIGHT = 250, 
        
	#ifdef __MMI_VECTOR_FONT_SUPPORT__
        // The gap between drag frame and normal icon.
        HIGHLIGHT_DRAG_GAP = 8,
	#else /* __MMI_VECTOR_FONT_SUPPORT__ */
        // The gap between drag frame and normal icon.
        HIGHLIGHT_DRAG_GAP = 12,
	#endif /* __MMI_VECTOR_FONT_SUPPORT__ */
		
        // The y offset of highlight image.
        HIGHLIGHT_IMAGE_OFFSET_Y = 25,
        
        // Width of highlight image(Only used for effect filter).
        HIGHLIGHT_IMAGE_WIDTH = 203,
        // Height of highlight image(Only used for effect filter).
        HIGHLIGHT_IMAGE_HEIGHT = 203,
        // The y offset of highlight image.
        HIGHLIGHT_IMAGE_OFFSET_X = 16,
        // The x offset for effect(Only used for effect filter).
        HIGHLIGHT_IMAGE_OFFSET_X_GAP = 120,
        // The y offset for effect(Only used for effect filter).
        HIGHLIGHT_IMAGE_OFFSET_Y_GAP = 120,
        // The x position of highlight icon.
        HIGHLIGHT_ICON_X = 100,
        // The y position of highlight icon.
        HIGHLIGHT_ICON_Y = 95,
        // The gap between image and frame
        NORMAL_IMAGE_Y = 8,
    #else
        // Width of normal icon.
        NORMAL_ICON_WIDTH = 64,
        // Height of normal icon.
        NORMAL_ICON_HEIGHT = 52,
        // Width of highlight icon (larger than actual image size due to effect).
        HIGHLIGHT_ICON_WIDTH = 124,
        // Height of highlight icon (larger than actual image size due to effect).        
        HIGHLIGHT_ICON_HEIGHT = 100,
        // The gap between drag frame and normal icon.
        HIGHLIGHT_DRAG_GAP = 0,
        // Width of highlight image(Only used for effect filter).
        HIGHLIGHT_IMAGE_WIDTH  = 124,
        // Height of highlight image(Only used for effect filter).
        HIGHLIGHT_IMAGE_HEIGHT = 100,
        // The x offset of highlight image.
        HIGHLIGHT_IMAGE_OFFSET_X = 10,
        // The y offset of highlight image.
        HIGHLIGHT_IMAGE_OFFSET_Y = 10,
        // The x offset for effect(Only used for effect filter).
        HIGHLIGHT_IMAGE_OFFSET_X_GAP = 45,
        // The y offset for effect(Only used for effect filter).
        HIGHLIGHT_IMAGE_OFFSET_Y_GAP = 45,
        // The x position of highlight icon.
        HIGHLIGHT_ICON_X = 62,
        // The y position of highlight icon.
        HIGHLIGHT_ICON_Y = 50,
        // The gap between image and frame
        NORMAL_IMAGE_Y = 0,
    #endif

        // Random delay time for drag-n-move effects (in milliseconds)
        DRAG_EFFECT_RANDOM_DELAY = 100,
        // Interval of entry animation (fly-in effect of all menu items)
    #if defined(__MMI_VUI_LITE_DISPLAY__)        
        ENTRY_ANIMATION_INTERVAL = 300,
    #else
        ENTRY_ANIMATION_INTERVAL = 220,
    #endif
        // Interval of entry animation (delay of highlight display)
        ENTRY_ANIMATION_INTERVAL2 = 50       
    };

// Constructor / Destructor
public:
    // Constructor.
    VcpSimpleMatrix();    

// Method
public:
    // Set the row and column number.
    void setRowsColumns(
        VfxS32 numRows,     //[IN] The number of rows
        VfxS32 numColumns   //[IN] The number of columns
        );
    // Set the image for item.
    void setItemImage(
        VfxS32 rows,        //[IN] The index of row
        VfxS32 columns,     //[IN] The index of column
	    VfxImageSrc &image
        );
    // Set to stringfor item.
    void setItemString(
        VfxS32 rows,            //[IN] The index of row
        VfxS32 columns,         //[IN] The index of column
        const VfxWString &text  //[IN] The image
        );
    
    // Reset main menu to normal mode.
    void resetNormal();

    // Reset main menu to normal mode and restore the menu order.
    void resetNormalAndRestore();
    
    // Start entry animation(Only used from homescreen to mainmenu).
    void startEntryAnimation();
    // Initialized the state of entry animation.
    void initEntryAnimation();

    // Change current highlight index.
    void changeCurrentHighlightIndex(
        VfxS32 highlightIndex //[IN] The new highlight index
        );
    // Get current highlight index.
    VfxS32 getCurrentHighlightIndex();

	void blockEventInput(void)
	{
		m_isBlockInput = VFX_TRUE;
	}

// Slot
public:
    // To handler the key input.
    void          onEventinput(
        VfxS32 num                  //[IN] The number to input
        );
    // To return normal mode
    void          onStopDrag();

// Signal
public:    
    // The signal to trigger the handler of LSK.
    VfxSignal1 <VcpSoftkeyEventEnum>    m_signalLSK;
    // The signal to trigger the handler of the state of softkey changed.
    VfxSignal1 <VcpMatrixSoftkeyState>  m_signalSoftkeyStateChanged;
    // The signal to trigger the handler of title changed.
    VfxSignal1 <const VfxWString &>     m_signalTitleChanged;
    // The signal to trigger the handler of title changed without redraw.
    VfxSignal1 <const VfxWString &>     m_signalTitleChangedNoRedraw;

// Variable
public:
    // The ordering of each menu item.
    VfxS32                  m_menuOrder[TOTAL_ITEMS];
    // The previous ordering of each menu item.
    VfxS32                  m_menuPreOrder[TOTAL_ITEMS];
    // Current highlight effect style.
    VfxU32                  m_highlightEffect;

// Override
protected:
    // Init function.
    virtual void onInit();
    // Deinit function.
    virtual void onDeinit();
    // Key input function.
    virtual VfxBool onKeyInput(
        VfxKeyEvent &event  //[IN] Key event
        );
    // Pen input function
    virtual VfxBool onPenInput(
        VfxPenEvent &event  //[IN] Pen event
        );

// Slot
private:     
    // The back light has been switched.
    void onPropertyBacklightSwitch(
        VfxBool isOn            //[IN] The back light is on or not
        );
    
    // The timer callback function of pen timer.
    void onPenTimer(
        VfxTimer *source        //[IN] Timer source
        );
    // The timer callback function of bubble effect timer.
    void onBubbleTimer(
        VfxTimer *source        //[IN] Timer source
        );
    // The timer callback function of filter timer.
    void onFilterTimer(
        VfxTimer *source        //[IN] Timer source
        );

    // The timer callback function of entry animation.
    void onEntryAnimTimer(
        VfxTimer *source        //[IN] Timer source
        );    
    
    // The finished callback function to cleanup timeline.
    void onTimelineCleanup(
        VfxBaseTimeline *timeline,      //[IN] Time line
        VfxBool isCompleted             //[IN] Timeline is completed of not
        );

    // The finished callback function of step1 in rotate effect.
    void onRotateStep1Stop(
        VfxBaseTimeline *timeline,      //[IN] Time line
        VfxBool isCompleted             //[IN] Timeline is completed of not
        );
    // The finished callback function of step2 in rotate effect.
    void onRotateStep2Stop(
        VfxBaseTimeline *timeline,      //[IN] Time line
        VfxBool isCompleted             //[IN] Timeline is completed of not
        );
    // The finished callback function of filter effect.
    void onFilterStop(
        VfxBaseTimeline *timeline,      //[IN] Time line
        VfxBool isCompleted             //[IN] Timeline is completed of not
        );  
    // The finished callback function of none effect.
    void onNoneEffectStop(
        VfxBaseTimeline *timeline,      //[IN] Time line
        VfxBool isCompleted             //[IN] Timeline is completed of not
        );
    
    // The finished callback function of fast move timeline.
    void onFastMoveStop(
        VfxBaseTimeline *timeline,      //[IN] Time line
        VfxBool isCompleted             //[IN] Timeline is completed of not
        );
    
    // The finished callback function of drag transition.
    void onDragTransitionStop(
        VfxBaseTimeline *timeline,      //[IN] Time line
        VfxBool isCompleted             //[IN] Timeline is completed of not
        );

// Variable
private:
    // The number of rows in matrix.
    VfxS32                  m_numRows;
    // The number of columns in matrix.
    VfxS32                  m_numColumns;

    // The pen state.
    PenStateEnum            m_penState;
    // The position of pen down.
    VfxPoint                m_penDownPos;
    // The position of last pen event.
    VfxPoint                m_penLastPos;
    // Whether highlight is changed during the pen move.
    VfxBool                 m_penHighlightChanged;

    // Whether the current highlight switch is triggered by pen or key.
    VfxBool                 m_highlightTriggeredByPen;

    // The current index to drag & move.
    VfxS32                  m_dragIndex;

    // Check if the current highlight switch effect is finished.
    VfxBool                 m_highlightEffectFinished;

    // Queued move steps.
    VfxS32                  m_fastMoveQueue[FAST_MOVE_QUEUE_SIZE];
    // The count of key event in queue.
    VfxS32                  m_fastMoveCount;

    // Frame index of bubble animation.
    VfxS32                  m_bubbleAnimIndex;

    // Stop drag and move mode by key input.
    VfxBool                 m_stopByKey;
public:
    // The current highlight index.
    VfxS32                  m_highlightIndex;

// Child Objects
private:
    // Normal items.
    VcpSimpleMatrixIcon     *m_normalItems[TOTAL_ITEMS];
    // Background of highlight.
    VfxFrame                *m_highlightFrame;
    // m_highlightItem is always put on m_highlightFrame.
    VcpSimpleMatrixIcon     *m_highlightItem;
    // The background of highlight in drag & move mode.
    VfxFrame                *m_highlightDrag;
    
    // The first timeline of rotate effect.
    VfxFloatTimeline        *m_rotateTimeline1;
    // The second timeline of rotate effect.
    VfxFloatTimeline        *m_rotateTimeline2;
    
    // The timer to changed to drag & move mode.
    VfxTimer                *m_penTimer;
    // The timer to update highlight icon.
    VfxTimer                *m_highlightTimer;

    /* Entry Animation */
    
    // Block key and pen input in entry animation and shortcut handler.
    VfxBool                 m_isBlockInput;
    
    /* Non-Linear Filter */
    // The filter of squeeze effect.
    VcpSqueezeFilter        *m_squfilter;
    // The filter of jelly effect.
    VcpJellyFilter          *m_jelfilter;
    // The timeline of non-liner filter.
    VfxFloatTimeline        *m_filterTimeline;
    
    // The timeline to change the position of item in drag & move mode.
    VfxFPointTimeline       *m_dragPosTimeline[TOTAL_ITEMS];

    // The timeline to rotate the item in drag & move mode.
    VfxFloatTimeline       *m_dragTransformTimeline[TOTAL_ITEMS];
    
    // The timeline to change the opacity for entry animation.
    VfxFloatTimeline        *m_opacityTimeline;
    
    // The timeline to change the position for fast move.
    VfxPointTimeline        *m_fastMoveTimelines[FAST_MOVE_QUEUE_SIZE];

    // The first timeline to change the position of highlight.
    VfxPointTimeline        *m_effectPosTimeline1;
    // The second timeline to change the position of highlight.
    VfxPointTimeline        *m_effectPosTimeline2;

// Method
private:
    // Layout all the items.
    void layoutItems();
    // Update the current highlighted item (image, text, etc).
    void updateHighlightItem();
    
    // Change to drag & move mode.
    void startDragMove();
    // Back to normal mode.
    VfxBool stopDragMove();
    
    // Restore the order.
    void restoreOrder();
    
    // Get the direction of effect.
    DirectionEnum getEffectDirection(VfxS32 OldIndex, VfxS32 index);

private:
    // Setup the timeline of squeeze effect
    void setupSqueezeEffect(
        VfxS32 OldIndex,        //[IN] old index
        VfxS32 index            //[IN] new index
        );
    // Setup the timeline of jump effect
    void setupJumpEffect(
        VfxS32 OldIndex,        //[IN] old index
        VfxS32 index            //[IN] new index
        );
    // Setup the timeline of jelly effect
    void setupJellyEffect(
        VfxS32 OldIndex,        //[IN] old index
        VfxS32 index            //[IN] new index
        );
    // Setup the timeline of bubble effect
    void setupBubbleEffect(
        VfxS32 OldIndex,        //[IN] old index
        VfxS32 index,           //[IN] new index
        VfxS32 x,               //[IN] new x position
        VfxS32 y                //[IN] new y position
        );
    // Setup the timeline of rotate effect
    void setupRotateEffect
        (VfxS32 OldIndex,       //[IN] old index
        VfxS32 x,               //[IN] new x position    
        VfxS32 y                //[IN] new Y position
        );
    
    // Setup the timeline of fastmove effect
    void setupFastMoveTimelines(
        VfxS32 OldIndex,        //[IN] old index
        VfxS32 index            //[IN] new index
        );
    
    // Setup the timeline to chagne the position during all the effects
    void setupPosTimeline(
        VfxS32 row,             //[IN] new row
        VfxS32 oldRow,          //[IN] old row
        VfxS32 column,          //[IN] new column
        VfxS32 oldColumn,       //[IN] old column    
        VfxS32 x1,              //[IN] new x position
        VfxS32 y1,              //[IN] new y position 
        VfxS32 x2,              //[IN] old x position 
        VfxS32 y2               //[IN] old y position
        );
};


#endif /* __VCP_MATRIX_H__ */
