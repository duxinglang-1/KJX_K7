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
 *  vapp_hs_widget_fmradio.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: FM Radio
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_HS_WIDGET_FMR_H__
#define __VAPP_HS_WIDGET_FMR_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_VUI_HOMESCREEN_FM_RADIO__
#include "vapp_hs_widget_base.h"
#include "vapp_hs_def.h"
#include "vcp_marquee.h"
#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_signal.h"
#include "vfx_input_event.h"
#include "vfx_cpp_base.h"
#include "vfx_primitive_frame.h"
#include "vapp_hs_widget_cfg.h"
#include "vfx_sys_memory.h"
#include "vfx_string.h"
#include "vfx_weak_ptr.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_HS_FMR_BUTTON_CLASS_NAME             "FMRBUTTON"

/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/***************************************************************************** 
 * Class VappHsWidgetFmrButton
 *****************************************************************************/

/*
 * VappHsWidgetFmrButton is a class that support the button of FM radio widget.
 *
 * EXAMPLE
 * <code>
 *  VappHsWidgetFmrButton *button;
 *  VFX_OBJ_CREATE(button, VappHsWidgetFmrButton, this);
 *  button->setPos(VfxPoint(13, 34));
 * </code>
 */ 
class VappHsWidgetFmrButton : public VfxControl
{
    VFX_DECLARE_CLASS(VappHsWidgetFmrButton);

// Constructor / Destructor      
public:
    // Default constructor
    VappHsWidgetFmrButton();

    // Destructor
    virtual ~VappHsWidgetFmrButton();

// Signal
public:
    // Pen down signal
    VfxSignal1 <VfxPenEvent &> m_eventPenDown;

    // Pen up signal
    VfxSignal1 <VfxPenEvent &> m_eventPenUp;

// Method
public:
    // Set image resource ID
    void setImage(
        VfxS32 upImage,     // [IN] up image ID
        VfxS32 downImage    // [IN] down image ID
    );

    // Set display flag
    void setDisplay(
        VfxBool isDisplay   // [IN] display flag
    );

// Override    
private:
    // On init
    virtual void onInit();

    // On Deinit
    virtual void onDeinit();

    // On pen input
    // RETURNS: VfxBool    
    virtual VfxBool onPenInput(
        VfxPenEvent &event
    );

// Variable
private:
    // Image frame
    VfxImageFrame *m_image;

    // Up image resource ID
    VfxS32 m_imageUpId;

    // Down image resource ID
    VfxS32 m_imageDownId;

    // Current pen type
    VfxS32 m_curr_pentype;
};


/***************************************************************************** 
 * Class VappHsWidgetFmr
 *****************************************************************************/

/*
 * VappHsWidgetFmr is a class that creates an FM radio widget.
 *
 * EXAMPLE
 * <code>
 *  VappHsWidgetFmr *fmradio;
 *  VFX_OBJ_CREATE(fmradio, VappHsWidgetFmr, this);
 * </code>
 */
class VappHsWidgetFmr : public VappHsWidget
{
    VAPP_HS_WIDGET_CREATE(VappHsWidgetFmr);
    
// Declaration
private:
    // The state of FM radio widget
    typedef enum
    {
        STATE_INIT          = VAPP_WIDGET_FMR_STATE_INIT,           // Init
        STATE_READY         = VAPP_WIDGET_FMR_STATE_READY,          // Ready
        STATE_PLAY          = VAPP_WIDGET_FMR_STATE_PLAY,           // Playing
        STATE_PLAY_NO_LIST  = VAPP_WIDGET_FMR_STATE_PLAY_NO_LIST,   // Playing without channel list
        STATE_SEARCHING     = VAPP_WIDGET_FMR_STATE_SEARCHING       // Searching
    }VappWidgetFmrStateEnum;

    // The title position
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        TITLE_START_OFFSET_X     = 10,       // The start offset x
        TITLE_START_OFFSET_Y     = 11,       // The start offset y
    #else
        TITLE_START_OFFSET_X     = 9,       // The start offset x
        TITLE_START_OFFSET_Y     = 9,       // The start offset y
    #endif     

    #if defined(__MMI_MAINLCD_320X480__)
        TITLE_END_OFFSET_X       = 183,     // The end offset x
        TITLE_END_OFFSET_Y       = 33,      // The end offset y
    #else
        TITLE_END_OFFSET_X       = 133,     // The end offset x
        TITLE_END_OFFSET_Y       = 29,      // The end offset y
    #endif

    #if defined(__MMI_MAINLCD_320X480__)
        BUTTON_PREV_OFFSET_X     = 6,
        BUTTON_PREV_OFFSET_Y     = 39,
    #else
        BUTTON_PREV_OFFSET_X     = 6,
        BUTTON_PREV_OFFSET_Y     = 33,
    #endif    

    #if defined(__MMI_MAINLCD_320X480__)
        BUTTON_PLAY_OFFSET_X     = 68,
        BUTTON_PLAY_OFFSET_Y     = 39,
    #else
        BUTTON_PLAY_OFFSET_X     = 50,
        BUTTON_PLAY_OFFSET_Y     = 33,
    #endif

    #if defined(__MMI_MAINLCD_320X480__)
        BUTTON_STOP_OFFSET_X     = 68,
        BUTTON_STOP_OFFSET_Y     = 39,
    #else
        BUTTON_STOP_OFFSET_X     = 50,
        BUTTON_STOP_OFFSET_Y     = 33,
    #endif

    #if defined(__MMI_MAINLCD_320X480__)
        BUTTON_NEXT_OFFSET_X     = 130,
        BUTTON_NEXT_OFFSET_Y     = 39,
    #else
        BUTTON_NEXT_OFFSET_X     = 90,
        BUTTON_NEXT_OFFSET_Y     = 33,
    #endif
    };

// Constructor / Destructor    
public:
    // Default constructor
    VappHsWidgetFmr();

// Override
public:
    // Get icon
    virtual VfxU16 getIcon();

    // Get name
    virtual VfxU16 getName();

    // Create the whole widget content
    virtual void onCreateView();

    // Release the whole widget content
    virtual void onReleaseView();
    
private:
    // On init
    virtual void onInit();

    // On deinit
    virtual void onDeinit();    

    // On DirectLunch
    virtual void onDirectLaunch();
    
// Variable    
private:
    // Background image frame
    VfxImageFrame *m_imageBg;

    // Text frame
    VcpMarquee *m_marqueeText;

    // Current string content
    VfxWString m_curr_show_title;

    // Ready flag
    VfxBool m_isReady;

    // Channel number
    VfxS16 m_channelNum;

    // Title string
    VfxChar m_title[256];

    // State
    VfxU32 m_state;

    // Previous button
    VappHsWidgetFmrButton *m_butPrev;

    // Next button
    VappHsWidgetFmrButton *m_butNext;

    // Play button
    VappHsWidgetFmrButton *m_butPlay;

    // Stop button
    VappHsWidgetFmrButton *m_butStop;

// Implementation
public:
    static void fmrCallback(
        void* userdata,     // [IN] userdata
        VfxU32 result       // [IN] information
    );
    
    void launchApp();

private:
    // Button up handle function
    void onButtonUp(
        VfxObjWeakPtr this_ptr
    );
    
    // Prev button down handle function
    // RETURNS: void
    void onPrevDown(
        VfxPenEvent &event  // [IN] pen event
    );

    // Prev button up handle function
    // RETURNS: void    
    void onPrevUp(
        VfxPenEvent &event  // [IN] pen event
    );

    // Next button down handle function
    // RETURNS: void    
    void onNextDown(
        VfxPenEvent &event  // [IN] pen event
    );

    // Next button up handle function
    // RETURNS: void    
    void onNextUp(
        VfxPenEvent &event  // [IN] pen event
    );

    // Play button down handle function
    // RETURNS: void    
    void onPlayDown(
        VfxPenEvent &event  // [IN] pen event
    );

    // Play button up handle function
    // RETURNS: void    
    void onPlayUp(
        VfxPenEvent &event  // [IN] pen event
    );

    // Stop button down handle function
    // RETURNS: void    
    void onStopDown(
        VfxPenEvent &event  // [IN] pen event
    );

    // Stop button up handle function
    // RETURNS: void    
    void onStopUp(
        VfxPenEvent &event  // [IN] pen event
    );

    // Status change notification handler
    void onStatusChanged(
        VfxU32 result       // [IN] information
    );

    // Update widget UI    
    void update(void);

    // Get the string of current media file
    // RETURNS: string
    VfxChar* getTitle(void);

    // Get the state of application
    void getState(void);

    // Get the channel number
    VfxS16 getChannelNum(void);
    
};
#endif /* __MMI_VUI_HOMESCREEN_FM_RADIO__ */
#endif /* __VAPP_HS_WIDGET_FMR_H__ */
