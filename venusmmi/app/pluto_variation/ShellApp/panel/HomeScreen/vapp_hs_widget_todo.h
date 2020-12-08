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
 *  vapp_hs_widget_todo.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: todo
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_HS_WIDGET_TODO_H__
#define __VAPP_HS_WIDGET_TODO_H__
     
#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_TODO__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vapp_hs_widget_base.h"
#include "vcp_button.h"
#include "mmi_rp_app_venus_hs_todo_def.h"

    #include "vfx_control.h"
    #include "vfx_date_time.h"
    #include "vfx_primitive_frame.h"
    #include "vfx_datatype.h"
    #include "vfx_timer.h"
    #include "vfx_cpp_base.h"
    #include "vapp_hs_widget_cfg.h"
    #include "vapp_hs_def.h"
    #include "vfx_sys_memory.h"
    #include "vfx_object.h"
    #include "mmi_rp_app_venus_hs_todo_def.h"
    #include "vfx_input_event.h"
    #include "vfx_basic_type.h"
    #include "vfx_string.h"
    #include "vfx_text_frame.h"
/***************************************************************************** 
 * helper class : VappHsWidgetTodoImage
 *****************************************************************************/
class VappHsWidgetTodoImage : public VfxControl
{
// Declaration
public:
    VappHsWidgetTodoImage();

    void setTime(
        const VfxDateTime &date //[IN] the date of this image
    );

    // clear all content
    void clearAll(void);
    
// Override
protected:
    virtual void onInit();
    
// Variable
private:
    VfxImageFrame *m_imgMonth;
    VfxImageFrame *m_imgDayL;   // the Left part of the day 
    VfxImageFrame *m_imgDayR;   // The Right part of the day
};


/***************************************************************************** 
 * helper class : VappHsTodoAnimateControl
 *****************************************************************************/
class VappHsTodoAnimateControl : public VfxControl
{
// Declaration
public:
    VappHsTodoAnimateControl();
    VappHsTodoAnimateControl(const VfxS32 &startResId, const VfxS32 &resCount);
    
    void startAnimate(void);
    void stopAnimate(void);

    // set animation resource
    void setRes(
        const VfxS32 &startResId, //[IN] start ret id
        const VfxS32 &resCount    //[IN] total resource number
        );

    // set animation interval time
    void setDuration(
        const VfxU16 &mesc        //[IN] Animation interval time
        );
    
//Override
protected:
    virtual void onInit(void);
    
private:
    void onTimerExpire(VfxTimer * source);
    
private:
    VfxImageFrame *m_frmImage;      // the anmiation image
    VfxTimer      *m_timerTick;
    VfxS32         m_sStartResId;
    VfxS32         m_nCount;
    VfxU16         m_nDuration;

};

/***************************************************************************** 
 * Home screen widget: Todo
 *****************************************************************************/
class VappHsWidgetTodo : public VappHsWidget
{
    VAPP_HS_WIDGET_CREATE(VappHsWidgetTodo);

// Declaration
public:

    // const enum
    enum 
    {
       DATE_WIDTH  = 43,
       DATE_HEIGHT = 48,
       MON_POS_X = 0,      // Month position in date frame
       MON_POS_y = 0,
       DAY_LEFT_POS_X = 0, // Day position in date frame
       DAY_LEFT_POS_Y = 18,
       DAY_RIGHT_POS_X = 14,
       DAY_RIGHT_POS_Y = DAY_LEFT_POS_Y,
       DATE_POS_X = 22,
       DATE_POS_Y = 13,
       STRING_WIDTH = 150,
       STRING_HEIGHT = 15,

       TIME_POS_Y = 8,
       SUB_POS_Y = 26,
       LOC_POS_Y = 49,
       ANIM_POX_X = 10,
       ANIM_POS_Y = 10,
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
       TXT_LOADING_POX_X = 91,
       TXT_LOADING_WIDTH = 138,
       TXT_LOADING_HEIGHT = 28,
       ANIM_LOADING_POX_X = 37,
       ANIM_LOADING_POX_Y = 18,
       TXT_POS_X = 76,
#else
       TXT_LOADING_POX_X = 134,
       TXT_LOADING_WIDTH = 158,
       TXT_LOADING_HEIGHT = 28,
       ANIM_LOADING_POX_X = 66,
       ANIM_LOADING_POX_Y = 13,
       TXT_POS_X = 91,
#endif
       CAL_AREA_WIDTH = 54,
       CAL_AREA_HEIGHT = 52,

       CAL_HOT_POS_LEFT_X = 15,
       CAL_HOT_POS_LEFT_Y = 13,
       CAL_HOT_POS_RIGHT_X = 58,
       CAL_HOT_POS_RIGHT_Y = 57,
       
       MAX_TEXT_LEN = 32
    };

    typedef enum
    {
        VIEW_CALENDAR,
        VIEW_DETAIL,
        VIEW_TOTAL
    }VIEW_TYPE;
    
// Constructor / Destructor
public:
    // Default constructor
    VappHsWidgetTodo();

// Override
public:
    // get the image ID of widget bar icon
    // RETURNS: image ID
    virtual VfxU16 getIcon() { return VAPP_HS_IMG_WG_ICON_TODO; }

    // Get string resource ID for the name of this widget
    // RETURNS: string ID
    virtual VfxU16 getName() { return VAPP_HS_STR_WG_TODO; }

    // create the whole widget content
    virtual void onCreateView();

    // release the whole widget content
    virtual void onReleaseView();

    virtual VfxBool onPenInput(VfxPenEvent & event);
    // support nail widget
    virtual void onDirectLaunch(void);
    
private:
    // entry calendar screen
    void showCalendar(void *data);

    // view event detail infomation
    void viewEvent(void *data);
    
    // to hit test whether the point is in calendar icon
    VfxBool isInCalendar(const VfxPoint &point) const;

    // to hit test whether the point is in detail area
    VfxBool isInDetail(const VfxPoint &point) const;

    // widget is in loading status, in which user can't entry calendar
    VfxBool isLoading(void) const;

    // timer change event
    void onTimeChanged(
        VfxU32 flag                     //[IN] time change flag
    );
    
    void onTimerExpire(VfxTimer * source);

    // for the time to string
    VfxWString formatTimeString(
        const VfxDateTime &startTime,   //[IN] start time
        const VfxDateTime &endTime      //[IN]  end time
        );

    // query recent event
    void query(void);

    // init all the widget content
    void initContent(void);
    
// Variable
private:

    VappHsWidgetTodoImage    *m_imgDate;  // event start date
    VappHsTodoAnimateControl *m_animLoad; // Todo is busy
    
    VfxTextFrame  *m_txtLocation;
    VfxTextFrame  *m_txtSubject;
    VfxTextFrame  *m_txtTime;           // event start time and end time
    VfxImageFrame *m_imgBg;             // background image 
    VfxImageFrame *m_imgCalBg;          // background image 
    VfxTextFrame  *m_txtLoading;
    VfxTimer 	  *m_timerCheck;
    
    VfxU16      m_uIndex;               // current event index
    VfxDateTime m_tmCurr;
    VIEW_TYPE   m_eViewMode;
};

#endif /* __MMI_VUI_HOMESCREEN_TODO__ */

#endif /* __VAPP_HS_WIDGET_TODO_H__ */

