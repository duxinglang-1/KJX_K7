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

/*******************************************************************************
 * Filename:
 * ---------
 *  vcp_info_balloon.h
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Info Balloons component header
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_INFO_BALLOON_H__
#define __VCP_INFO_BALLOON_H__

#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_cpp_base.h"
#include "vfx_input_event.h"
#include "vfx_animation.h"
#include "vfx_timer.h"
#include "vfx_object_list.h"
#include "vfx_screen.h"
#include "vfx_text_frame.h"
#include "vfx_base_popup.h"

#if defined(__MMI_VUI_COSMOS_CP__)

/***************************************************************************** 
 * Include
 *****************************************************************************/



/***************************************************************************** 
 * Define
 *****************************************************************************/

// Coordinates
#if defined(__MMI_MAINLCD_320X480__)
    #define VCP_INFO_BALLOON_BOTTOM_HEIGHT (44)

    #define VCP_INFO_BALLOON_BOTTOM_Y (-100)

    #define VCP_INFO_BALLOON_UPPER_HEIGHT (51)

    #define VCP_INFO_BALLOON_UPPER_ARROW_HEIGHT (0)
    #define VCP_INFO_BALLOON_UPPER_ARROW_WIDTH  (16)
    #define VCP_INFO_BALLOON_UPPER_MIN_X (20)
    #define VCP_INFO_BALLOON_UPPER_SUIT_X (23)
    
    #define VCP_INFO_BALLOON_BOTTOM_Y_DISTANCE (80)
    
    #define VCP_INFO_BALLOON_ICON_X (19)
    #define VCP_INFO_BALLOON_UPPER_ICON_Y  (25)
    #define VCP_INFO_BALLOON_BOTTOM_ICON_Y (19)
    
    #define VCP_INFO_BALLOON_ICON_WIDTH  (19)
    #define VCP_INFO_BALLOON_ICON_HEIGHT (19)
    
    //#define VCP_INFO_BALLOON_TEXT_X (39)
    
    #define VCP_INFO_BALLOON_TEXT_X (10)
    #define VCP_INFO_BALLOON_UPPER_TEXT_Y  (25)
    #define VCP_INFO_BALLOON_BOTTOM_TEXT_Y (19)
    #define VCP_INFO_BALLOON_TEXT_SIZE (15)
    
    #define VCP_INFO_BALLOON_TEXT_RIGHT_MARGIN (10)
    
    
    #define VCP_INFO_BALLOON_FLYING_TIME  (500)
    #define VCP_INFO_BALLOON_STAYING_TIME (1000)
    #define VCP_INFO_BALLOON_FADING_TIME  (500)

#elif defined(__MMI_MAINLCD_480X800__)
    #define VCP_INFO_BALLOON_BOTTOM_HEIGHT (81)

    #define VCP_INFO_BALLOON_BOTTOM_Y (-173)

    #define VCP_INFO_BALLOON_UPPER_HEIGHT (81)

    #define VCP_INFO_BALLOON_UPPER_ARROW_HEIGHT (0)
    #define VCP_INFO_BALLOON_UPPER_ARROW_WIDTH  (25)
    #define VCP_INFO_BALLOON_UPPER_MIN_X (37)
    #define VCP_INFO_BALLOON_UPPER_SUIT_X (39)
    
    #define VCP_INFO_BALLOON_BOTTOM_Y_DISTANCE (120)
    
    #define VCP_INFO_BALLOON_ICON_X (30)
    #define VCP_INFO_BALLOON_UPPER_ICON_Y  (39)
    #define VCP_INFO_BALLOON_BOTTOM_ICON_Y (39)
    
    #define VCP_INFO_BALLOON_ICON_WIDTH  (32)
    #define VCP_INFO_BALLOON_ICON_HEIGHT (32)
    
    //#define VCP_INFO_BALLOON_TEXT_X (64)
    
    #define VCP_INFO_BALLOON_TEXT_X (18)
    #define VCP_INFO_BALLOON_UPPER_TEXT_Y  (39)
    #define VCP_INFO_BALLOON_BOTTOM_TEXT_Y (39)
    #define VCP_INFO_BALLOON_TEXT_SIZE (23)
    
    #define VCP_INFO_BALLOON_TEXT_RIGHT_MARGIN (18)
    
    
    #define VCP_INFO_BALLOON_FLYING_TIME  (500)
    #define VCP_INFO_BALLOON_STAYING_TIME (1000)
    #define VCP_INFO_BALLOON_FADING_TIME  (500)

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    #define VCP_INFO_BALLOON_BOTTOM_HEIGHT (37)

    #define VCP_INFO_BALLOON_BOTTOM_Y (-84)

    #define VCP_INFO_BALLOON_UPPER_HEIGHT (43)

    #define VCP_INFO_BALLOON_UPPER_ARROW_HEIGHT (0)
    #define VCP_INFO_BALLOON_UPPER_ARROW_WIDTH  (14)
    #define VCP_INFO_BALLOON_UPPER_MIN_X (21)
    #define VCP_INFO_BALLOON_UPPER_SUIT_X (21)
    
    #define VCP_INFO_BALLOON_BOTTOM_Y_DISTANCE (60)
    
    #define VCP_INFO_BALLOON_ICON_X (17)
    #define VCP_INFO_BALLOON_UPPER_ICON_Y  (21)
    #define VCP_INFO_BALLOON_BOTTOM_ICON_Y (15)
    
    #define VCP_INFO_BALLOON_ICON_WIDTH  (19)
    #define VCP_INFO_BALLOON_ICON_HEIGHT (19)
    
    //#define VCP_INFO_BALLOON_TEXT_X (32)
    
    #define VCP_INFO_BALLOON_TEXT_X (8)
    #define VCP_INFO_BALLOON_UPPER_TEXT_Y  (21)
    #define VCP_INFO_BALLOON_BOTTOM_TEXT_Y (15)
    #define VCP_INFO_BALLOON_TEXT_SIZE (12)
    
    #define VCP_INFO_BALLOON_TEXT_RIGHT_MARGIN (8)
    
    
    #define VCP_INFO_BALLOON_FLYING_TIME  (500)
    #define VCP_INFO_BALLOON_STAYING_TIME (1000)
    #define VCP_INFO_BALLOON_FADING_TIME  (500)
#else
    #define VCP_INFO_BALLOON_BOTTOM_HEIGHT (44)

    #define VCP_INFO_BALLOON_BOTTOM_Y (-100)

    #define VCP_INFO_BALLOON_UPPER_HEIGHT (51)

    #define VCP_INFO_BALLOON_UPPER_ARROW_HEIGHT (0)
    #define VCP_INFO_BALLOON_UPPER_ARROW_WIDTH  (16)
    #define VCP_INFO_BALLOON_UPPER_MIN_X (20)
    #define VCP_INFO_BALLOON_UPPER_SUIT_X (23)
    
    #define VCP_INFO_BALLOON_BOTTOM_Y_DISTANCE (80)
    
    #define VCP_INFO_BALLOON_ICON_X (19)
    #define VCP_INFO_BALLOON_UPPER_ICON_Y  (25)
    #define VCP_INFO_BALLOON_BOTTOM_ICON_Y (19)
    
    #define VCP_INFO_BALLOON_ICON_WIDTH  (19)
    #define VCP_INFO_BALLOON_ICON_HEIGHT (19)
    
    //#define VCP_INFO_BALLOON_TEXT_X (39)
    
    #define VCP_INFO_BALLOON_TEXT_X (10)
    #define VCP_INFO_BALLOON_UPPER_TEXT_Y  (25)
    #define VCP_INFO_BALLOON_BOTTOM_TEXT_Y (19)
    #define VCP_INFO_BALLOON_TEXT_SIZE (15)
    
    #define VCP_INFO_BALLOON_TEXT_RIGHT_MARGIN (10)
    
    
    #define VCP_INFO_BALLOON_FLYING_TIME  (500)
    #define VCP_INFO_BALLOON_STAYING_TIME (1000)
    #define VCP_INFO_BALLOON_FADING_TIME  (500)
#endif

    #define VCP_INFO_BALLOON_Z_ORDER      (3000)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum 
{
    VCP_INFO_BALLOON_TYPE_FAILURE,
    VCP_INFO_BALLOON_TYPE_INFO,
    VCP_INFO_BALLOON_TYPE_WARNING,
    VCP_INFO_BALLOON_TYPE_SUCCESS,
    VCP_INFO_BALLOON_TYPE_PROGRESS,
    VCP_INFO_BALLOON_TYPE_TOTAL
}VcpInfoBalloonTypeEnum;

typedef enum 
{
    VCP_INFO_BALLOON_ANIMATION_STATE_NONE,
    VCP_INFO_BALLOON_ANIMATION_STATE_FLYING,
    VCP_INFO_BALLOON_ANIMATION_STATE_STAYING,
    VCP_INFO_BALLOON_ANIMATION_STATE_FADING,
    VCP_INFO_BALLOON_ANIMATION_STATE_TOTAL
}VcpInfoBalloonAnimationStateEnum;

typedef enum 
{
    VCP_INFO_BALLOON_STYLE_UP,
    VCP_INFO_BALLOON_STYLE_BOTTOM,
    VCP_INFO_BALLOON_STYLE_END_OF_ENUM
}VcpInfoBallooonStyleEnum;


#define VCP_INFO_BALLOON_MAX_NUMBER         (2)

/*****************************************************************************
 * Class VcpInfoBalloonUpperItem
 * VcpInfoBalloonUpperItem is an internal class for info_balloons, 
 * displayed on top of the screen.
 *****************************************************************************/
class VcpInfoBalloonBaseItem : public VfxControl
{	
  //  VFX_DECLARE_CLASS(VcpInfoBalloonUpperItem);
// Constructor / Destructor
public:
    // <group DOM_InfoBalloon_VcpInfoBalloonBaseItem_Constructor/Destructor>
    VcpInfoBalloonBaseItem();
	// <group DOM_InfoBalloon_VcpInfoBalloonBaseItem_Method>
    // leave balloon
    void leave();
    // <group DOM_InfoBalloon_VcpInfoBalloonBaseItem_Method>
    // exit and close balloon
    void exit();
    // <group DOM_InfoBalloon_VcpInfoBalloonBaseItem_Method>
    // set the text of balloon
    void setText(
        const VfxWString &text                  // [IN] text
        )
    {
        m_textFrame->setString(text);
    }
    // <group DOM_InfoBalloon_VcpInfoBalloonBaseItem_Method>
    // get the text of balloon
    const VfxWString& getText() const
    {
        return m_textFrame->getString();
    }
    // <group DOM_InfoBalloon_VcpInfoBalloonBaseItem_Method>
    // set the image of balloon
    void setImage(
        const VfxImageSrc &imgScr         // [IN] image
        )
    {
        m_iconFrame->setImgContent(imgScr);
    }
    // <group DOM_InfoBalloon_VcpInfoBalloonBaseItem_Method>
    // set the index of balloon
    void setIndex(VfxS32 index)
    {
        m_index = index;
    }
    // <group DOM_InfoBalloon_VcpInfoBalloonBaseItem_Method>
    // get the index of balloon
    VfxS32 getIndex()
    {
        return m_index;
    }
// Signal
public:
    // <group DOM_InfoBalloon_VcpInfoBalloonBaseItem_Signal>
    // notify VcpInfoBallon when balloon leave
    VfxSignal2 <
        VfxObject *,             // target frame
        VfxS32                   // index
        > m_signalLeaveFinished;
// Override    
protected:
    // <group DOM_InfoBalloon_VcpInfoBalloonBaseItem_Override>
    virtual void onInit();

	// Variable
protected:
    // <group DOM_InfoBalloon_VcpInfoBalloonBaseItem_Variable>
    VfxFrame  *m_iconFrame;
    // <group DOM_InfoBalloon_VcpInfoBalloonBaseItem_Variable>
    VfxTextFrame *m_textFrame;
	 // <group DOM_InfoBalloon_VcpInfoBalloonBaseItem_Variable>
    VfxFloatTimeline *m_opacityTimeline;
    // <group DOM_InfoBalloon_VcpInfoBalloonBaseItem_Variable>
    VfxTimer *m_durationTimer;
    // <group DOM_InfoBalloon_VcpInfoBalloonBaseItem_Variable>
    VfxS32 m_index;
    // <group DOM_InfoBalloon_VcpInfoBalloonBaseItem_Variable>
    VcpInfoBalloonAnimationStateEnum m_state;

// Implematation
protected:
    // <group DOM_InfoBalloon_VcpInfoBalloonUpperItem_Implematation>
    void timeOut(VfxTimer *timer);
    // <group DOM_InfoBalloon_VcpInfoBalloonUpperItem_Implematation>
    void finishState(VfxBaseTimeline *timeline, VfxBool stop);

};

class VcpInfoBalloonUpperItem : public VcpInfoBalloonBaseItem
{
  //  VFX_DECLARE_CLASS(VcpInfoBalloonUpperItem);
// Constructor / Destructor
public:
    // <group DOM_InfoBalloon_VcpInfoBalloonUpperItem_Constructor/Destructor>
    VcpInfoBalloonUpperItem();

// Method
public:
    // <group DOM_InfoBalloon_VcpInfoBalloonUpperItem_Method>
    // adjust postion according to arrow position
    void adjustPos(const VfxPoint &arrow);
    // <group DOM_InfoBalloon_VcpInfoBalloonUpperItem_Method>
    // show balloon
    void show(const VfxPoint &arrow);
    // <group DOM_InfoBalloon_VcpInfoBalloonUpperItem_Method>
    // notify balloon when screen rotate
    void onRotate(VfxScreenRotateParam param);

// Signal
public:
    // <group DOM_InfoBalloon_VcpInfoBalloonUpperItem_Signal>
    // notify VcpInfoBallon when balloon leave
    //VfxSignal2 <
    //    VfxObject *,             // target frame
    //    VfxS32                   // index
    //    > m_signalLeaveFinished;
// Override    
protected:
    // <group DOM_InfoBalloon_VcpInfoBalloonUpperItem_Override>
    virtual void onInit();

// Variable
private:
    // <group DOM_InfoBalloon_VcpInfoBalloonUpperItem_Variable>
    VfxFrame *m_backgroundLeft;
    // <group DOM_InfoBalloon_VcpInfoBalloonUpperItem_Variable>
    VfxFrame *m_backgroundCenter;
    // <group DOM_InfoBalloon_VcpInfoBalloonUpperItem_Variable>
    VfxFrame *m_backgroundRight;
    // <group DOM_InfoBalloon_VcpInfoBalloonUpperItem_Variable>
    VfxPoint m_arrowPos;
};


/*****************************************************************************
 * Class VcpInfoBalloonBottomItem
 * VcpInfoBalloonBottomItem is an internal class for info_balloons, 
 * displayed on bottom of the screen.
 *****************************************************************************/
class VcpInfoBalloonBottomItem : public VcpInfoBalloonBaseItem
{
    //VFX_DECLARE_CLASS(VcpInfoBalloonBottomItem);
// Constructor / Destructor
public:
    // <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Constructor/Destructor>
    VcpInfoBalloonBottomItem();

// Method
public:
    // <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Method>
    // show balloon
    void show();
    // <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Method>
    // leave balloon
    //void leave();
    //// <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Method>
    //// exit and close balloon
    //void exit();
    //// <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Method>
    //// set the text of balloon
    //void setText(
    //    const VfxWString &text                  // [IN] text
    //    )
    //{
    //    m_textFrame->setString(text);
    //}
    //// <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Method>
    //// get the text of balloon
    //const VfxWString& getText() const
    //{
    //    return m_textFrame->getString();
    //}
    //// <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Method>
    //// set the image of balloon
    //void setImage(
    //    const VfxImageSrc &imgScr         // [IN] image
    //    )
    //{
    //    m_iconFrame->setImgContent(imgScr);
    //}
    //// <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Method>
    //// set the index of balloon
    //void setIndex(VfxS32 index)
    //{
    //    m_index = index;
    //}
    //// <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Method>
    //// get the index of balloon
    //VfxS32 getIndex()
    //{
    //    return m_index;
    //}
    //// <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Method>
    //// notify balloon when screen rotate
    void onRotate(VfxScreenRotateParam param);
    // <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Method>
    // notify balloon when screen enter
    void onScreenEnter();
    // <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Method>
    // notify balloon when screen exit
    void onScreenExit();

// Event
public:
    // <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Event>
    // notify VcpInfoBallon when balloon leave
    //VfxSignal2 <
    //    VfxObject *,             // target frame
    //    VfxS32                   // index
    //    > m_signalLeaveFinished;

// Override
protected:
    // <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Override>
    virtual void onInit();

// Variable
private:
    // <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Variable>
  //  VfxFrame  *m_iconFrame;
    // <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Variable>
    //VfxTextFrame *m_textFrame;
    // <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Variable>
    VfxPointTimeline *m_posTimeline;
    // <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Variable>
    //VfxFloatTimeline *m_opacityTimeline;
    // <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Variable>
   // VfxTimer *m_durationTimer;
    // <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Variable>
    //VfxS32 m_index;
    // <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Variable>
   // VcpInfoBalloonAnimationStateEnum m_state;
    // <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Variable>
    VcpInfoBalloonAnimationStateEnum m_exitScreenState;

// Implematation
private:
    // <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Implematation>
 //   void timeOut(VfxTimer *timer);
    // <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Implematation>
    void startFly(VfxBaseTimeline *timeline);
    // <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Implematation>
    void finishFly(VfxBaseTimeline *timeline, VfxBool stop);
    // <group DOM_InfoBalloon_VcpInfoBalloonBottomItem_Implematation>
   // void finishState(VfxBaseTimeline *timeline, VfxBool stop);
	void  startPosTimeLine();
};


/*****************************************************************************
 * Class VcpInfoBalloon
 * VcpInfoBalloon is a class for info_balloons, displayed on top of the screen.
 *
 * EXAMPLE
 * <code>
 *  VcpInfoBalloon *nt;
 *  VFX_OBJ_CREATE(nt, VcpInfoBalloon, this);
 *  nt->addItem(VfxImageSrc(IMG_GLOBAL_L1), VFX_WSTR("Message arrived!")); 
 * </code>
 *****************************************************************************/
class VcpInfoBalloon : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VcpInfoBalloon);
// Constructor / Destructor
public:
    // <group DOM_InfoBalloon_VcpInfoBalloon_Constructor/Destructor>
    // Default constructor.
    VcpInfoBalloon();

// Method
public:
    // <group DOM_InfoBalloon_VcpInfoBalloon_Method>
    // Adds one info_balloon with text and icon and send it to the screen.
    void addItem(
        VfxResId icon,               // [IN]  Icon to be displayed 
        const VfxWString &text                // [IN]  Text to show     
        );
    // <group DOM_InfoBalloon_VcpInfoBalloon_Method>
    // Adds one info_balloon with text and icon and put according to arrow position.
    void addItem(
        VfxResId icon,               // [IN]  Icon to be displayed 
        const VfxWString &text,                // [IN]  Text to show
        const VfxPoint &arrowPos      // [IN]  Target distance from bottom        
        );

    // <group DOM_InfoBalloon_VcpInfoBalloon_Method>
    // Adds one info_balloon with text and icon and send it to the screen.
    void addItem(
        VcpInfoBalloonTypeEnum type,               // [IN]  Info Balloon type to yse predeifned icon 
        const VfxWString &text                           // [IN]  Text to show
        );

    // <group DOM_InfoBalloon_VcpInfoBalloon_Method>
    // Adds one info_balloon with text and icon and put according to arrow position.
    void addItem(
        VcpInfoBalloonTypeEnum type,               // [IN]  Info Balloon type to yse predeifned icon 
        const VfxWString &text,                           // [IN]  Text to show
        const VfxPoint &arrowPos                 // [IN]  Target distance from bottom    
        );
    // <group DOM_InfoBalloon_VcpInfoBalloon_Method>
    // move balloon according to arrow position.
    void moveCurrentUpperItem(const VfxPoint &arrowPos);
    // <group DOM_InfoBalloon_VcpInfoBalloon_Method>
    // cancel current upper item.
    void cancelCurrentUpperItem();
    // <group DOM_InfoBalloon_VcpInfoBalloon_Method>
    // cancel current bottom item.
    void cancelCurrentBottomItem();

	// <group DOM_InfoBalloon_VcpInfoBalloon_Event>
    // when the ballon is closed
	 VfxSignal1 <
        VfxObject*                    
    > m_signalBallonClosed;

	virtual vrt_allocator_handle getAllocator();

// Override
protected:
    // <group DOM_InfoBalloon_VcpInfoBalloon_Override>
    virtual void onInit();

// Variable 
private:
    // <group DOM_InfoBalloon_VcpInfoBalloon_Variable>
    VcpInfoBalloonUpperItem *m_upperBalloon[VCP_INFO_BALLOON_MAX_NUMBER];
    // <group DOM_InfoBalloon_VcpInfoBalloon_Variable>
    VcpInfoBalloonBottomItem *m_bottomBalloon[VCP_INFO_BALLOON_MAX_NUMBER];
    // <group DOM_InfoBalloon_VcpInfoBalloon_Variable>
    VfxS32 upperIndex;
    // <group DOM_InfoBalloon_VcpInfoBalloon_Variable>
    VfxS32 bottomIndex;

// Implematation
private:
    // <group DOM_InfoBalloon_VcpInfoBalloon_Implematation>
    void onActiveScreenEnter(VfxWeakPtr<VfxScreen> scr);
    // <group DOM_InfoBalloon_VcpInfoBalloon_Implematation>
    void onActiveScreenExit(VfxWeakPtr<VfxScreen> scr);
    // <group DOM_InfoBalloon_VcpInfoBalloon_Implematation>
    void killBalloonUpperItem(VfxObject *object, VfxS32 index);
    // <group DOM_InfoBalloon_VcpInfoBalloon_Implematation>
    void killBalloonBottomItem(VfxObject *object, VfxS32 index);
    // <group DOM_InfoBalloon_VcpInfoBalloon_Implematation>
    VfxResId selectIcon(VcpInfoBalloonTypeEnum type); 
    // <group DOM_InfoBalloon_VcpInfoBalloon_Implematation>
    void onPopupChanged(VfxWeakPtr<VfxBasePopup> popup);
    // <group DOM_InfoBalloon_VcpInfoBalloon_Implematation>
    void onRotate(VfxScreenRotateParam param);
};

#endif /* #if defined (__MMI_VUI_COSMOS_CP__)  */ 

#endif /* __VCP_INFO_BALLOON_H__ */

