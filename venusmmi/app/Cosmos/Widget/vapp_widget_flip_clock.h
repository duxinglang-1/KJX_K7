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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_widget_flip_clock.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines widget flip clock class.
 *
 * Author:
 * -------
 * 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef VAPP_WIDGET_FLIP_CLOCK_H
#define VAPP_WIDGET_FLIP_CLOCK_H

#include "MMI_features.h"

#ifdef __MMI_VUI_WIDGET_FLIP_CLOCK__

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_widget_def.h"
#include "vapp_widget.h"

/***************************************************************************** 
 * flip clock VcpFlipClockPage Class
 *****************************************************************************/

class VappFlipClockPage : public VfxFrame
{
// Constructor / Destructor
public:
    // Default constructor
    VappFlipClockPage();

// Method
public:
    // Set backgroud image resource id if need 
    void setBackGround(
        VfxResId bg_id                // [IN] Background image resource id
    );

    // Set tow number image resource id and position 
    void setNumber(
        VfxResId num1,               // [IN] Left number image resource id
        VfxPoint num1_pos,           // [IN] Left number image position
        VfxResId num2,               // [IN] Right number image resource id
        VfxPoint num2_pos            // [IN] Right number image position
    );
    
    // Get tow number image resource id
    void getNumber(
        VfxResId *num1,               // [OUT] Left number image resource id
        VfxResId *num2               // [OUT] Right number image resource id
    );

    // Set string information if need    
    void setString(
        const VfxWString &value,     // [IN] String value
        const VfxFontDesc &fontDesc, // [IN] String font style , include font effect
        VfxColor font_color,         // [IN] String font color
        VfxPoint pos,                // [IN] String position
        VfxBool left_align           // [IN] String align mode . TURE : align left of page . False : align right of page
    );

    // Get string value   
    VfxWString &getString();

    // Set page index
    void setIndex(
        VfxS32 index                // [IN] Index id of this page
    );

    // Get page index 
    VfxS32 getIndex();

// Overide
protected:
    virtual void onInit();
     
    virtual void onDeinit();
     
    virtual void onDraw(VfxDrawContext &dc);
 
// Variable
private: 
    VfxU8 * m_bg;
    VfxU8 * m_num1;
    VfxU8 * m_num2;
    VfxResId m_num1_res;
    VfxResId m_num2_res;
    VfxPoint m_num1_pos;
    VfxPoint m_num2_pos;
    VfxWString m_string;
    VfxPoint m_str_pos;
    VfxFontDesc m_font;
    VfxColor m_font_color;
    VfxBool is_left_align;
    VfxS32 m_index;
    VfxSize m_string_size;
 };


/***************************************************************************** 
 * flip clock VappWidgetFlipClock Class
 *****************************************************************************/

class VappWidgetFlipClock : public VappWidget
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetFlipClock);

public:
    enum
    {      
    #if defined(__MMI_MAINLCD_480X800__)
        MAX_SIZE_WIDTH = 480,
        MAX_SIZE_HEIGHT = 300,
    
        WIDTH=460,
        HEIGHT=213,
    
        BUTTON_X=439,
        BUTTON_Y=11,
    
        DATE_FONT_SIZE=18,
    
        PAGE_WIDTH=208,
        PAGE_HEIGHT=80,
        PAGE_Y=98,
    
        DATE_X=194,
        DATE_Y=8,
    
        AMPM_X=192,
        AMPM_Y=50,
        
        DATA_NAME_X=12,
        DATA_NAME_Y=8,
        
        NUM_X=44,
        NUM_TOP_HEIGHT=41,
        NUM_GAP=8,
        NUM_WIDTH=54,
    
        ANIMATION_TIME=250,
        ANIMATION_DELAY=500,
    #elif defined(__MMI_MAINLCD_320X480__)
        MAX_SIZE_WIDTH = 320,
        MAX_SIZE_HEIGHT = 149,

        WIDTH=312,
        HEIGHT=149,

        BUTTON_X=296,
        BUTTON_Y=5,

        DATE_FONT_SIZE=12,

        PAGE_WIDTH=139,
        PAGE_HEIGHT=53,
        PAGE_Y=66,

        DATE_X=131,
        DATE_Y=6,

        AMPM_X=131,
        AMPM_Y=33,

        DATA_NAME_X=8,
        DATA_NAME_Y=6,

        NUM_X=32,
        NUM_TOP_HEIGHT=24,
        NUM_GAP=4,
        NUM_WIDTH=36,

        ANIMATION_TIME=250,
        ANIMATION_DELAY=500,
    #else /* defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)*/
        MAX_SIZE_WIDTH = 240,
        MAX_SIZE_HEIGHT = 99,
    
        WIDTH=216,
        HEIGHT=99,
    
        BUTTON_X=210,
        BUTTON_Y=3,
    
        DATE_FONT_SIZE=10,
    
        PAGE_WIDTH=97,
        PAGE_HEIGHT=38,
        PAGE_Y=45,
    
        DATE_X=92,
        DATE_Y=4,
    
        AMPM_X=91,
        AMPM_Y=23,

        DATA_NAME_X=5,
        DATA_NAME_Y=4,
    
        NUM_X=21,
        NUM_TOP_HEIGHT=17,
        NUM_GAP=4,
        NUM_WIDTH=25,
    
        ANIMATION_TIME=250,
        ANIMATION_DELAY=500,
    #endif
    };

private:
    // Flip clock animation type
    enum VappFlipClockAnimTyepEnum
    {
        // None animation
        VAPP_FLIP_CLOCK_ANIM_TYPE_LEFT_NONE,

        VAPP_FLIP_CLOCK_ANIM_TYPE_RIGHT_NONE,

        // One page animation
        VAPP_FLIP_CLOCK_ANIM_TYPE_LEFT_NORMAL,

        VAPP_FLIP_CLOCK_ANIM_TYPE_RIGHT_NORMAL,

        // N-page animation
        VAPP_FLIP_CLOCK_ANIM_TYPE_LEFT_SWIPE,

        VAPP_FLIP_CLOCK_ANIM_TYPE_RIGHT_SWIPE,

        VAPP_FLIP_CLOCK_ANIM_TYPE_MAX
    };

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetFlipClock();

// Method
public:
    // Create flip clock four pages
    void CreateFlipClock(VfxDateTime dt);

    // Update time and do animation
    void UpdateTime(
        VfxDateTime dt_new,                // [IN] New time . Page need to change to it
        VfxDateTime dt_old,                // [IN] Old time . Page need to change from it
        VappFlipClockAnimTyepEnum type     //[IN] Animation type 
        );

    void TimelineBegin(
        VappFlipClockPage *target,        //[IN] The one need to do animation
        VfxS32 delay                      //[IN] Time of timeline need to delay
        );

// Override
public:
    virtual VappWidgetId getId() const;

    virtual VfxSize getMaxSize() const;

    virtual VfxS32 getName(VfxWChar *string, VfxS32 size) const;

    virtual VfxFrame *createIcon(VfxObject *parentObj);

    virtual void onCreateView();

    virtual void onReleaseView();

    virtual void onEnterSlimView();

    virtual void onExitSlimView();
    
    virtual VfxPoint onGetEditButtonOffset();

    virtual void onSerializeView(VfxArchive *ar);

    virtual void onRestoreView(VfxArchive *ar);

//solt
private:
    // System time changed callback funtion. Will update time by flag, and begin animation.
    void onSystemTimeChanged(
        VfxU32 flag                     // [IN] Is the flag to notify the type of date change
    );

    void TimelineOnGoing(VfxBaseTimeline *timeline, VfxBool isCompleted);

    void TimelineEnd(VfxBaseTimeline *timeline, VfxBool isCompleted);

    void onTimerTick(VfxTimer *source);

// Variable
private: 
    VfxImageFrame *m_bg;
    VfxFrame *m_bg_frame;
    VfxFrame *m_bg_timeline;
    static const VfxU32 G1_PAGE_COUNT = 2;
    static const VfxU32 MAX_PAGE_COUNT = G1_PAGE_COUNT;
    VappFlipClockPage *m_page_right_top;
    VappFlipClockPage *m_page_right_top_temp[MAX_PAGE_COUNT];
    VappFlipClockPage *m_page_right_bottom;
    VappFlipClockPage *m_page_right_bottom_temp[MAX_PAGE_COUNT];
    VappFlipClockPage *m_page_left_top;  
    VappFlipClockPage *m_page_left_top_temp[MAX_PAGE_COUNT];
    VappFlipClockPage *m_page_left_bottom;
    VappFlipClockPage *m_page_left_bottom_temp[MAX_PAGE_COUNT];
    VappFlipClockPage *m_left_shadow[MAX_PAGE_COUNT];
    VappFlipClockPage *m_right_shadow[MAX_PAGE_COUNT];
    VfxFontDesc m_font;
    VfxFontEffect *m_effect;
    VfxColor m_color;
    VfxDateTime m_dt;
    VfxBool need_animation;
    VfxBool disable_swipe;
    VfxBool is_swiping;
    VfxU32 m_formatFlags;
};

#endif /*__MMI_VUI_WIDGET_FLIP_CLOCK__*/

#endif /*VAPP_WIDGET_FLIP_CLOCK_H*/
