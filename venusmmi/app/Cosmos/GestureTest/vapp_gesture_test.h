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
 *  vapp_gesture_test.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Gesture test header file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_GESTURE_TEST_H__
#define __VAPP_GESTURE_TEST_H__

#include "MMI_features.h"
#ifdef __MMI_EM_MISC_TOUCH_SCREEN__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_navi_title_bar.h"
#include "vcp_confirm_popup.h"
#include "vcp_pluto_control.h"
#include "vcp_list_menu.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_GESTURE_TEST_FRAMES                 9
#define VAPP_GESTURE_TEST_FRAMES_ROW             3
#define VAPP_GESTURE_TEST_FRAMES_COL             3
#define VAPP_GESTURE_TEST_DRAG_ROUTES            8
#define VAPP_GESTURE_TEST_MAX_POINTS             500
#define VAPP_GESTURE_TEST_MAX_SETTINGS           10

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum {
    VAPP_GESTURE_TEST_UP,
    VAPP_GESTURE_TEST_UPRIGHT,
    VAPP_GESTURE_TEST_RIGHT,
    VAPP_GESTURE_TEST_DOWNRIGHT,
    VAPP_GESTURE_TEST_DOWN,
    VAPP_GESTURE_TEST_DOWNLEFT,
    VAPP_GESTURE_TEST_LEFT,
    VAPP_GESTURE_TEST_UPLEFT,
    VAPP_GESTURE_TEST_ENUM_MAX
} vapp_gesture_test_nudge_enum;

typedef enum {
    VAPP_GESTURE_SLIDE_DOWN,
    VAPP_GESTURE_SLIDE_UP,
    VAPP_GESTURE_SLIDE_RIGHT,
    VAPP_GESTURE_SLIDE_LEFT,
    VAPP_GESTURE_SLIDE_ENUM_MAX
} vapp_gesture_test_slide_enum;

typedef enum {
    VAPP_GESTURE_TEST_TAP_INTERVAL,
    VAPP_GESTURE_TEST_DOUBLETAP_INTERVAL,
    VAPP_GESTURE_TEST_DOUBLETAP_DISTANCE,
    VAPP_GESTURE_TEST_HOLD_INTERVAL,
    VAPP_GESTURE_TEST_HOLD_DISTANCE,
    VAPP_GESTURE_TEST_DRAG_INTERVAL,
    VAPP_GESTURE_TEST_DRAG_DISTANCE,
    VAPP_GESTURE_TEST_SLIDE_INTERVAL,
    VAPP_GESTURE_TEST_SLIDE_DISTANCE,
    VAPP_GESTURE_TEST_NUDGE_DISTANCE,
    VAPP_GESTURE_TEST_DIMETER
} vapp_gesture_test_settings_enum;

/*****************************************************************************
 * gesture test menu class
 *****************************************************************************/
class VappGestureTestMenu : public VfxPage, public IVcpListMenuContentProvider
{
//    VFX_DECLARE_CLASS(VappGestureTestMenu);

// Override
protected:
    virtual void onInit();
    virtual VfxU32 getCount() const;
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color);

public:
    void onTapItem(VcpListMenu *menu, VfxU32 index);

private:
    VcpListMenu* m_menu;
};

class VappGestureTestCaliMenu : public VfxPage, public IVcpListMenuContentProvider
{
//    VFX_DECLARE_CLASS(VappGestureTestCaliMenu);

// Override
protected:
    virtual void onInit();
    virtual VfxU32 getCount() const {return 2;}
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color);

public:
    void onTapItem(VcpListMenu *menu, VfxU32 index);

private:
    VcpListMenu* m_menu;
};

class VappGestureTestGestureMenu : public VfxPage, public IVcpListMenuContentProvider
{
//    VFX_DECLARE_CLASS(VappGestureTestGestureMenu);

// Override
protected:
    virtual void onInit();
    virtual VfxU32 getCount() const {return 8;}
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color);

public:
    void onTapItem(VcpListMenu *menu, VfxU32 index);

private:
    VcpListMenu* m_menu;
};

class VappGestureTestCaliSetting : public VfxPage, public IVcpListMenuContentProvider
{
//    VFX_DECLARE_CLASS(VappGestureTestCaliSetting);

// Override
protected:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward) {m_menu->updateAllItems();}
    virtual VfxU32 getCount() const {return 1;}
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color);

public:
    void onTapItem(VcpListMenu *menu, VfxU32 index);

private:
    VcpListMenu* m_menu;
};

class VappGestureTestGestureSetting : public VfxPage, public IVcpListMenuContentProvider
{
//    VFX_DECLARE_CLASS(VappGestureTestGestureSetting);

// Override
protected:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward) {m_menu->updateAllItems();}
    virtual VfxU32 getCount() const {return 10;}
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color);

public:
    void onTapItem(VcpListMenu *menu, VfxU32 index);

private:
    VcpListMenu* m_menu;
};

class VappGestureTestSetting : public VfxPage, public IVcpListMenuContentProvider
{
//    VFX_DECLARE_CLASS(VappGestureTestSetting);

// Constructor
public:
    VappGestureTestSetting() {}
    VappGestureTestSetting(VfxU8 index) : m_index(index) {};

// Override
protected:
    virtual void onInit();
    virtual VfxU32 getCount() const {return VAPP_GESTURE_TEST_MAX_SETTINGS;}
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color);
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

public:
    void onTapItem(VcpListMenu *menu, VfxU32 index);

private:
    VcpListMenu*    m_menu;
    VfxU8           m_index;
};

/*****************************************************************************
 * gesture test app class
 *****************************************************************************/
class VappGestureTestScr : public VfxMainScr
{
//    VFX_DECLARE_CLASS(VappGestureTestScr);

// Override
protected:
    virtual void on1stReady();
};

class VappGestureTestApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappGestureTestApp);

// Override
protected:
    virtual void onRun(void * args,VfxU32 argSize);

public:
    static const VfxU32 m_settings_list[][VAPP_GESTURE_TEST_MAX_SETTINGS];
    static VfxU32 m_settings[];
};

/*****************************************************************************
 * pen track class
 *****************************************************************************/
class VappGestureTestPenTrack : public VfxFrame
{
    typedef struct {
        VfxPenEventTypeEnum type;
        VfxPoint            pos;
    } VappGestureTestPenTrackPoint;

//Constructor / Destructor
public: 
    VappGestureTestPenTrack() : m_count(0)
    {
    }

// Method
public:
    void addPoint(VfxPenEvent &event);
    void clearPenTrack();

// Override
protected:
    virtual void onDraw(VfxDrawContext &dc);

protected:
    VappGestureTestPenTrackPoint    m_point[VAPP_GESTURE_TEST_MAX_POINTS];
    VfxS32                          m_count;
};


/*****************************************************************************
 * pen track test screen
 *****************************************************************************/
class VappGestureTestPenTrackScr : public VfxPage
{
//Constructor / Destructor
public: 
    VappGestureTestPenTrackScr() :
        m_parameters(NULL), m_pentrack(NULL)
    {
    }

// Override
protected:
    virtual void onInit();
    virtual VfxBool onPenInput(VfxPenEvent &event);

protected:
    VfxTextFrame            *m_parameters;
    VappGestureTestPenTrack *m_pentrack;
};


/*****************************************************************************
 * calibration test image
 *****************************************************************************/
class VappGestureTestCalibrationImage : public VcpPlutoControl
{
//Constructor / Destructor
public: 
    VappGestureTestCalibrationImage() : dimeter(0)
    {
    }

public:
    VfxS32 dimeter;

// Override
protected:
    virtual void onPlutoCreate() {}
    virtual void onPlutoClose() {}
    virtual void onPlutoDraw() { gdi_draw_circle(getSize().width / 2, getSize().height / 2, dimeter / 2, GDI_COLOR_BLACK); }
};


/*****************************************************************************
 * calibration test screen
 *****************************************************************************/
class VappGestureTestCalibrationScr : public VappGestureTestPenTrackScr
{
//    VFX_DECLARE_CLASS(VappGestureTestCalibrationScr);
//Constructor / Destructor
public: 
    VappGestureTestCalibrationScr() {}
    VappGestureTestCalibrationScr(VfxS32 dimeter) : m_dimeter(dimeter)
    {
    }

// Override
protected:
    virtual void onInit();
    virtual VfxBool onPenInput(VfxPenEvent &event);

private:
    void handleResult();

protected:
    VfxU8                           m_caliState;
    VfxPoint                        m_caliPoint[3];
    VfxPoint                        m_inputPoint[3];
    VappGestureTestCalibrationImage *m_caliImage;
    VfxS32                          m_dimeter;
    VfxTextFrame                    *m_settings;
};


/*****************************************************************************
 * gesture test screen base class
 *****************************************************************************/
class VappGestureTestBaseScr : public VappGestureTestPenTrackScr
{
//Constructor / Destructor
public: 
    VappGestureTestBaseScr() {}
    VappGestureTestBaseScr(VfxMsec interval, VfxS16 distance);

// Override
protected:
    virtual void onInit();

// Helper functions
protected:
    // check if test finished
    VfxBool isTestFinished();
    // show a success popup
    void testSuccess();
    // show a failed popup
    void testFailed(VfxWString &str);
    // draw an arrow from start to end
    void drawArrow(VfxDrawContext &dc, VfxPoint &start, VfxPoint &end);

protected:
    VfxFrame        *m_testArea;
    VfxFrame        *m_testFrames[VAPP_GESTURE_TEST_FRAMES];
    VfxTextFrame    *m_settings;
    VfxMsec         m_interval;
    VfxS16          m_distance;
};


/*****************************************************************************
 * tap test screen
 *****************************************************************************/
class VappGestureTestTapScr : public VappGestureTestBaseScr
{
//Constructor / Destructor
public: 
    VappGestureTestTapScr(VfxMsec interval) :
        VappGestureTestBaseScr(interval, 0)
    {
    }

// Override
protected:
    virtual void onInit();
    virtual VfxBool onPenInput(VfxPenEvent &event);
};


/*****************************************************************************
 * double tap test screen
 *****************************************************************************/
class VappGestureTestDoubleTapScr : public VappGestureTestBaseScr
{
//Constructor / Destructor
public: 
    VappGestureTestDoubleTapScr(VfxMsec interval, VfxS16 distance);

// Override
protected:
    virtual void onInit();
    virtual VfxBool onPenInput(VfxPenEvent &event);

private:
    VfxFrame        *m_firstDownFrame;
    VfxPoint        m_firstDownPos;
    VfxMsec         m_firstDownTime;
    VfxBool         m_waitSecondTap;
};


/*****************************************************************************
 * hold test screen
 *****************************************************************************/
class VappGestureTestHoldScr : public VappGestureTestBaseScr
{
//Constructor / Destructor
public: 
    VappGestureTestHoldScr(VfxMsec interval, VfxS16 distance) :
        VappGestureTestBaseScr(interval, distance)
    {
    }

// Override
protected:
    virtual void onInit();
    virtual VfxBool onPenInput(VfxPenEvent &event);
};


/*****************************************************************************
 * drag test screen
 *****************************************************************************/
class VappGestureTestDragScr : public VappGestureTestBaseScr
{
    struct VappGestureTestDragRoute
    {
        VfxFrame *src;
        VfxFrame *dst;
    };

//Constructor / Destructor
public: 
    VappGestureTestDragScr(VfxMsec interval, VfxS16 distance);

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onDraw(VfxDrawContext & dc);
    virtual VfxBool onPenInput(VfxPenEvent &event);

private:
    VappGestureTestDragRoute    m_testRoute[VAPP_GESTURE_TEST_DRAG_ROUTES];
    VappGestureTestDragRoute    *m_currRoute;
    VfxFrame                    *m_tempFrame;
};


/*****************************************************************************
 * slide test screen
 *****************************************************************************/
class VappGestureTestSlideScr : public VappGestureTestBaseScr
{
//Constructor / Destructor
public: 
    VappGestureTestSlideScr(VfxMsec interval, VfxS16 distance) :
        VappGestureTestBaseScr(interval, distance), m_direction(0)
    {
    }

// Override
protected:
    virtual void onInit();
    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual void onDraw(VfxDrawContext &dc);

private:
    VfxU8           m_direction;
};


/*****************************************************************************
 * ssp test screen
 *****************************************************************************/
class VappGestureTestSSPScr : public VfxPage, public IVcpListMenuContentProvider
{
//Constructor / Destructor
public: 
    VappGestureTestSSPScr() {}

// Override
protected:
    virtual void onInit();
    virtual VfxU32 getCount() const {return 20;}
    virtual VfxBool getItemText(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color
        ) { text.format("Menu item: %d", index); color = VCP_LIST_MENU_TEXT_COLOR_NORMAL; return VFX_TRUE;}
    void notifyScrollEnd(VcpScrollable* sender);
    virtual VfxBool onPreviewPenInput(VfxPenEvent &event);

private:
    VcpListMenu *m_testMenu;
};


/*****************************************************************************
 * nudge test screen
 *****************************************************************************/
class VappGestureTestNudgeScr : public VappGestureTestBaseScr
{
    struct VappGestureTestNudgeRoute
    {
        VfxFrame *src;
        VfxU8    dir;
    };

//Constructor / Destructor
public: 
    VappGestureTestNudgeScr(VfxS16 distance) :
        VappGestureTestBaseScr(0, distance)
    {
    }

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual void onDraw(VfxDrawContext &dc);

private:
    // check if a frame has been nudged by correct direction
    VfxBool checkDirection(VfxPoint &downPos, VfxPoint &poss, VfxFrame *frame);

protected:
    VappGestureTestNudgeRoute m_testRoute[VAPP_GESTURE_TEST_FRAMES];
};

#endif /* __MMI_EM_MISC_TOUCH_SCREEN__ */

#endif /* __VAPP_GESTURE_TEST_H__ */

