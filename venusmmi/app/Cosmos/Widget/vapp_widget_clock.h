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
 *  vapp_widget_clock.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the hello world widget.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef VAPP_WIDGET_CLOCK_H
#define VAPP_WIDGET_CLOCK_H

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_widget_def.h"
#include "vapp_widget.h"


// BEGIN OF THE TEMP CODES
//
// TODO: Remove it later.
#define VAPP_WIDGET_STR_CLOCK_NAME    (60337)
#define VAPP_WIDGET_IMG_CLOCK_ICON    (60337)

// END OF THE TEMP CODES
class VappClockDataControl : public VfxBase
{
public:
	void getTime(VfxFloat src, VfxFloat des, VfxDateTime &dt, VfxU16 City_index);
};

/*****************************************************************************
 * Clock Widget
 *****************************************************************************/
#ifdef __MMI_MAINLCD_320X480__
#define VAPP_WIDGET_CLOCK2_MONTH_FONT_SIZE              VFX_FONT_DESC_VF_SIZE(14)
#define VAPP_WIDGET_CLOCK2_DAY_FONT_SIZE              VFX_FONT_DESC_VF_SIZE(16)
#define VAPP_WIDGET_CLOCK2_CITY_FONT_SIZE              VFX_FONT_DESC_VF_SIZE(14)
#elif defined(__MMI_MAINLCD_480X800__)
	#define VAPP_WIDGET_CLOCK2_MONTH_FONT_SIZE              VFX_FONT_DESC_VF_SIZE(18)
	#define VAPP_WIDGET_CLOCK2_DAY_FONT_SIZE              VFX_FONT_DESC_VF_SIZE(20)
	#define VAPP_WIDGET_CLOCK2_CITY_FONT_SIZE              VFX_FONT_DESC_VF_SIZE(18)
#else
	#define VAPP_WIDGET_CLOCK2_MONTH_FONT_SIZE              VFX_FONT_DESC_VF_SIZE(10)
	#define VAPP_WIDGET_CLOCK2_DAY_FONT_SIZE              VFX_FONT_DESC_VF_SIZE(10)
	#define VAPP_WIDGET_CLOCK2_CITY_FONT_SIZE              VFX_FONT_DESC_VF_SIZE(10)
#endif

class VappAnalogClock : public VfxControl
{
	VFX_DECLARE_CLASS(VappAnalogClock);
public:
	enum
	{
		CLOCK_STYLE1,  // show time
		CLOCK_STYLE2, // only clock
		CLOCK_STYLE3,
		CLOCK_STYLE4,
	};
    enum
    {
#ifdef __MMI_MAINLCD_320X480__
		VAPP_WIDGET_CLOCK1_CENTER_X = 115,
		VAPP_WIDGET_CLOCK1_CENTER_Y = 115,

		VAPP_WIDGET_CLOCK2_CENTER_X = 119,
		VAPP_WIDGET_CLOCK2_CENTER_Y = 119,

		VAPP_WIDGET_CLOCK3_CENTER_X = 120,
		VAPP_WIDGET_CLOCK3_CENTER_Y = 120,

		VAPP_WIDGET_CLOCK4_CENTER_X = 75,
		VAPP_WIDGET_CLOCK4_CENTER_Y = 75,
#elif defined(__MMI_MAINLCD_480X800__)
		VAPP_WIDGET_CLOCK1_CENTER_X = 163,
		VAPP_WIDGET_CLOCK1_CENTER_Y = 163,

		VAPP_WIDGET_CLOCK2_CENTER_X = 160,
		VAPP_WIDGET_CLOCK2_CENTER_Y = 160,

		VAPP_WIDGET_CLOCK3_CENTER_X = 161,
		VAPP_WIDGET_CLOCK3_CENTER_Y = 162,

		VAPP_WIDGET_CLOCK4_CENTER_X = 106,
		VAPP_WIDGET_CLOCK4_CENTER_Y = 106,
#else
		VAPP_WIDGET_CLOCK1_CENTER_X = 75,
		VAPP_WIDGET_CLOCK1_CENTER_Y = 75,

		VAPP_WIDGET_CLOCK2_CENTER_X = 75,
		VAPP_WIDGET_CLOCK2_CENTER_Y = 75,

		VAPP_WIDGET_CLOCK3_CENTER_X = 75,
		VAPP_WIDGET_CLOCK3_CENTER_Y = 75,

		VAPP_WIDGET_CLOCK4_CENTER_X = 50,
		VAPP_WIDGET_CLOCK4_CENTER_Y = 50,
#endif
    };
// Constructor / Destructor
public:
	VappAnalogClock();
    VappAnalogClock(VfxU8 style);
// Method
public:
	void setFrameCustom(VfxFrame *customFrame);
    void setTime(
        const VfxDateTime &startTime // [IN] Is the start relative time
    );
	void hideSecondHande();
	void unhideSecondHande();
	VfxBool getHiddenSecondHande();
// Override
protected:
    virtual void onInit();

    virtual void onDeinit();
// Variable
private:
	VcpAnalogClock *m_aclock;
	VfxU8 m_style;
};

#ifdef __MMI_VUI_WIDGET_CLOCK1__
class VappWidgetClock1 : public VappWidget
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetClock1);

public:
    enum
    {
#ifdef __MMI_MAINLCD_320X480__
        MAX_SIZE_WIDTH = 320,
        MAX_SIZE_HEIGHT = 252,

        WIDTH = 235,
        HEIGHT = 235,

		VAPP_WIDGET_CLOCK1_CENTER_X = 115,
		VAPP_WIDGET_CLOCK1_CENTER_Y = 115,
		VAPP_WIDGET_CLOCK1_TEXT_X = 79,
		VAPP_WIDGET_CLOCK1_TEXT_Y = 143,
		VAPP_WIDGET_CLOCK1_TEXT_W = 74,
		VAPP_WIDGET_CLOCK1_TEXT_H = 14,

		VAPP_WIDGET_CLOCK1_TEXT_SIZE = 13,

		BUTTON_X = 187,
		BUTTON_Y = 40,

#elif defined(__MMI_MAINLCD_480X800__)
        MAX_SIZE_WIDTH = 480,
        MAX_SIZE_HEIGHT = 360,

        WIDTH = 325,
        HEIGHT = 326,

		VAPP_WIDGET_CLOCK1_TEXT_X = 110,
		VAPP_WIDGET_CLOCK1_TEXT_Y = 198,
		VAPP_WIDGET_CLOCK1_TEXT_W = 105,
		VAPP_WIDGET_CLOCK1_TEXT_H = 20,

		VAPP_WIDGET_CLOCK1_TEXT_SIZE = 20,

		BUTTON_X = 278,
		BUTTON_Y = 62,
#else
        MAX_SIZE_WIDTH = 240,
        MAX_SIZE_HEIGHT = 213,

        WIDTH = 150,
        HEIGHT = 150,

		VAPP_WIDGET_CLOCK1_CENTER_X = 75,
		VAPP_WIDGET_CLOCK1_CENTER_Y = 75,
		VAPP_WIDGET_CLOCK1_TEXT_X = 52,
		VAPP_WIDGET_CLOCK1_TEXT_Y = 93,
		VAPP_WIDGET_CLOCK1_TEXT_W = 50,
		VAPP_WIDGET_CLOCK1_TEXT_H = 9,

		VAPP_WIDGET_CLOCK1_TEXT_SIZE = 8,

		BUTTON_X = 120,
		BUTTON_Y = 28,
#endif
    };

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetClock1();

// Override
public:
    virtual VappWidgetId getId() const;

    virtual VfxSize getMaxSize() const;

    virtual VfxS32 getName(VfxWChar *string, VfxS32 size) const;

    virtual VfxFrame *createIcon(VfxObject *parentObj);
protected:
	 virtual VfxPoint onGetEditButtonOffset();
     virtual void onEnterSlimView();

     virtual void onExitSlimView();

	 virtual void onSerializeView(VfxArchive *ar);
	 virtual void onRestoreView(VfxArchive *ar);

// Overide
public:
    virtual void onCreateView();

    virtual void onReleaseView();

// Variable
private:
	VappAnalogClock *m_analog;
	VcpDigitalTextClock *m_date;
};

#endif /*__MMI_VUI_WIDGET_CLOCK1__ */


#ifdef __MMI_VUI_WIDGET_CLOCK2__
class VappWidgetClock2 : public VappWidget
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetClock2);

public:
    enum
    {
#ifdef __MMI_MAINLCD_320X480__
        MAX_SIZE_WIDTH = 320,
        MAX_SIZE_HEIGHT = 252,

        WIDTH = 240,
        HEIGHT = 240,
		MONTH_TEXT_X = 86,
		MONTH_TEXT_Y = 64,
		MONTH_TEXT_W = 70,
		MONTH_TEXT_H = 20,

		DAY_TEXT_X = 103,
		DAY_TEXT_Y = 83,
		DAY_TEXT_W = 38,
		DAY_TEXT_H = 15,

		CITY_TEXT_X = 85,
		CITY_TEXT_Y = 155,
		CITY_TEXT_W = 70,
		CITY_TEXT_H = 20,

		BUTTON_X = 193,
		BUTTON_Y = 40,
#elif defined(__MMI_MAINLCD_480X800__)
        MAX_SIZE_WIDTH = 480,
        MAX_SIZE_HEIGHT = 360,

        WIDTH = 320,
        HEIGHT = 320,
		MONTH_TEXT_X = 123,
		MONTH_TEXT_Y = 84,
		MONTH_TEXT_W = 84,
		MONTH_TEXT_H = 23,

		DAY_TEXT_X = 145,
		DAY_TEXT_Y = 108,
		DAY_TEXT_W = 34,
		DAY_TEXT_H = 23,

		CITY_TEXT_X = 114,
		CITY_TEXT_Y = 213,
		CITY_TEXT_W = 96,
		CITY_TEXT_H = 23,

		BUTTON_X = 271,
		BUTTON_Y = 53,
#else
        MAX_SIZE_WIDTH = 240,
        MAX_SIZE_HEIGHT = 213,

        WIDTH = 150,
        HEIGHT = 150,
		MONTH_TEXT_X = 61,
		MONTH_TEXT_Y = 40,
		MONTH_TEXT_W = 33,
		MONTH_TEXT_H = 12,

		DAY_TEXT_X = 68,
		DAY_TEXT_Y = 55,
		DAY_TEXT_W = 12,
		DAY_TEXT_H = 10,

		CITY_TEXT_X = 54,
		CITY_TEXT_Y = 97,
		CITY_TEXT_W = 40,
		CITY_TEXT_H = 11,

		BUTTON_X = 120,
		BUTTON_Y = 28,
#endif
    };

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetClock2();

// Override
public:
    virtual VappWidgetId getId() const;

    virtual VfxSize getMaxSize() const;

    virtual VfxS32 getName(VfxWChar *string, VfxS32 size) const;

    virtual VfxFrame *createIcon(VfxObject *parentObj);
public:
	void launchWorldClock();
// Overide
public:
    virtual void onCreateView();

    virtual void onReleaseView();
// Override
protected:
	 virtual VfxPoint onGetEditButtonOffset();
     //virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual void onSerializeView(VfxArchive *ar);

    virtual void onRestoreView(VfxArchive *ar);
    virtual void onTap(
        const VfxPoint &pos
    );
    virtual VfxBool onContainPoint(
        const VfxPoint &point       // [IN] the point in the coordinate of the frame
    ) const;
     virtual void onEnterSlimView();

     virtual void onExitSlimView();
private:
    // Handle the time change event of PLUTO system time.
    void onSystemTimeChanged(
        VfxU32 flag // [IN] Is the flag to notify the type of time change
    );
	void updateClock(VfxU16 city_index, VfxBool isHidden);
// Variable
private:
	VappAnalogClock *m_analog;
	VfxFrame *m_custom;
	VfxTextFrame *m_month_text;
	VfxTextFrame *m_day_text;
	VfxTextFrame *m_city_text;
	VfxBool m_launch;
};

#endif /*__MMI_VUI_WIDGET_CLOCK2__*/

#if defined(__MMI_VUI_WIDGET_CLOCK2__) || defined(__MMI_VUI_WIDGET_DCLOCK__)
class VappWidgetClock : public VfxApp
{
    VFX_DECLARE_CLASS(VappWidgetClock);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual mmi_ret onProc(mmi_event_struct *evt);
protected:
	virtual VfxBool onScrBack(VfxAppScr *scr);
private:
	VfxU16 m_type;
};

class VappWidgetClocktScrn : public VfxMainScr
{
     VFX_DECLARE_CLASS(VappWidgetClocktScrn);
public:
    virtual void on1stReady(); 
protected:
	//virtual void processEnter(VfxBool isBackward, VfxScrRotateTypeEnum rotateType);
	 virtual void onEnter(VfxBool isBackward);
};
#endif /* defined(__MMI_VUI_WIDGET_CLOCK2__) || defined(__MMI_VUI_WIDGET_DCLOCK__)*/

#ifdef __MMI_VUI_WIDGET_CLOCK3__
class VappWidgetClock3 : public VappWidget
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetClock3);

public:
    enum
    {
#ifdef __MMI_MAINLCD_320X480__
        MAX_SIZE_WIDTH = 320,
        MAX_SIZE_HEIGHT = 252,

        WIDTH = 240,
        HEIGHT = 240,

		BUTTON_X = 193,
		BUTTON_Y = 40,
#elif defined(__MMI_MAINLCD_480X800__)
        MAX_SIZE_WIDTH = 480,
        MAX_SIZE_HEIGHT = 360,

        WIDTH = 322,
        HEIGHT = 324,

		BUTTON_X = 265,
		BUTTON_Y = 50,
#else
        MAX_SIZE_WIDTH = 240,
        MAX_SIZE_HEIGHT = 213,

		WIDTH = 150,
        HEIGHT = 150,

		BUTTON_X = 120,
		BUTTON_Y = 28,
#endif
    };

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetClock3();

// Override
public:
    virtual VappWidgetId getId() const;

    virtual VfxSize getMaxSize() const;

    virtual VfxS32 getName(VfxWChar *string, VfxS32 size) const;

    virtual VfxFrame *createIcon(VfxObject *parentObj);
protected:
	virtual VfxPoint onGetEditButtonOffset();
// Overide
public:
    virtual void onCreateView();

    virtual void onReleaseView();
    virtual void onEnterSlimView();

    virtual void onExitSlimView();
// Variable
private:
	VappAnalogClock *m_analog;
};
#endif /* __MMI_VUI_WIDGET_CLOCK3__ */

#ifdef __MMI_VUI_WIDGET_CLOCK4__
class VappWidgetClock4 : public VappWidget
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetClock4);

public:
    enum
    {
#ifdef __MMI_MAINLCD_320X480__
        MAX_SIZE_WIDTH = 160,
        MAX_SIZE_HEIGHT = 168,

        WIDTH = 150,
        HEIGHT = 150,

		BUTTON_X = 123,
		BUTTON_Y = 32,
#elif defined(__MMI_MAINLCD_480X800__)
        MAX_SIZE_WIDTH = 240,
        MAX_SIZE_HEIGHT = 240,

        WIDTH = 212,
        HEIGHT = 213,

		BUTTON_X = 185,
		BUTTON_Y = 39,
#else
        MAX_SIZE_WIDTH = 120,
        MAX_SIZE_HEIGHT = 142,

        WIDTH = 100,
        HEIGHT = 100,

		BUTTON_X = 90,
		BUTTON_Y = 20,
#endif
    };

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetClock4();

// Override
public:
    virtual VappWidgetId getId() const;

    virtual VfxSize getMaxSize() const;

    virtual VfxS32 getName(VfxWChar *string, VfxS32 size) const;

    virtual VfxFrame *createIcon(VfxObject *parentObj);
protected:
	virtual VfxPoint onGetEditButtonOffset();
// Overide
public:
    virtual void onCreateView();

    virtual void onReleaseView();
// Variable
private:
	VappAnalogClock *m_analog;
};

#endif /* __MMI_VUI_WIDGET_CLOCK4__ */
/*****************************************************************************
 * Digtial clock Widget
 *****************************************************************************/
#ifdef __MMI_VUI_WIDGET_DCLOCK__
#define VAPP_WIDGET_DCLOCK_DATE_COLOR VRT_COLOR_MAKE(255, 177, 177, 177)

class VappWidgetDigtialClock : public VappWidget
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetDigtialClock);

public:
    enum
    {
#ifdef __MMI_MAINLCD_320X480__
        MAX_SIZE_WIDTH = 320,
        MAX_SIZE_HEIGHT = 168,

        D_CLOCK_WIDTH = 230,
        D_CLOCK_HEIGHT = 133,

		D_CLOCK_12_CENTER_X = 108,
		D_CLOCK_24_CENTER_X = 115,
		D_CLOCK_CENTER_Y = 52,

		D_CLOCK_DATE_X = 20,
		D_CLOCK_DATE_Y = 100,
		D_CLOCK_DATE_W = 110,
		D_CLOCK_DATE_H = 20,

		D_CLOCK_CITY_X = 150,
		D_CLOCK_CITY_Y = 104,
		D_CLOCK_CITY_W = 60,
		D_CLOCK_CITY_H = 20,

		D_CLOCK_AM_PM_X = 193,
		D_CLOCK_AM_PM_Y = 67,
		D_CLOCK_AM_PM_W = 50,
		D_CLOCK_AM_PM_H = 20,

		DATE_FONT_SIZE = 14,
		CITY_FONT_SIZE = 14,
		APM_FONT_SIZE = 14,
		BUTTON_X = 213,
		BUTTON_Y = 16,
#elif defined(__MMI_MAINLCD_480X800__)
        MAX_SIZE_WIDTH = 480,
        MAX_SIZE_HEIGHT = 240,

        D_CLOCK_WIDTH = 328,
        D_CLOCK_HEIGHT = 195,

		D_CLOCK_12_CENTER_X = 145,
		D_CLOCK_24_CENTER_X = 165,
		D_CLOCK_CENTER_Y = 75,

		D_CLOCK_DATE_X = 14,
		D_CLOCK_DATE_Y = 154,
		D_CLOCK_DATE_W = 110,
		D_CLOCK_DATE_H = 20,

		D_CLOCK_CITY_X = 135,
		D_CLOCK_CITY_Y = 154,
		D_CLOCK_CITY_W = 170,
		D_CLOCK_CITY_H = 23,

		D_CLOCK_AM_PM_X = 268,
		D_CLOCK_AM_PM_Y = 92,
		D_CLOCK_AM_PM_W = 50,
		D_CLOCK_AM_PM_H = 25,

		DATE_FONT_SIZE = 20,
		CITY_FONT_SIZE = 20,
		APM_FONT_SIZE = 20,

		BUTTON_X = 303,
		BUTTON_Y = 21,
#else
        MAX_SIZE_WIDTH = 240,
        MAX_SIZE_HEIGHT = 142,

        D_CLOCK_WIDTH = 168,
        D_CLOCK_HEIGHT = 98,

		D_CLOCK_12_CENTER_X = 75,
		D_CLOCK_24_CENTER_X = 85,
		D_CLOCK_CENTER_Y = 38,

		D_CLOCK_DATE_X = 11,
		D_CLOCK_DATE_Y = 77,
		D_CLOCK_DATE_W = 55,
		D_CLOCK_DATE_H = 11,

		D_CLOCK_CITY_X = 95,
		D_CLOCK_CITY_Y = 76,
		D_CLOCK_CITY_W = 65,
		D_CLOCK_CITY_H = 15,

		D_CLOCK_AM_PM_X = 140,
		D_CLOCK_AM_PM_Y = 49,
		D_CLOCK_AM_PM_W = 30,
		D_CLOCK_AM_PM_H = 12,

		DATE_FONT_SIZE = 10,
		CITY_FONT_SIZE = 10,
		APM_FONT_SIZE = 10,

		BUTTON_X = 156,
		BUTTON_Y = 11,
#endif
    };

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetDigtialClock();

// Override
public:
    virtual VappWidgetId getId() const;

    virtual VfxSize getMaxSize() const;

    virtual VfxS32 getName(VfxWChar *string, VfxS32 size) const;

    virtual VfxFrame *createIcon(VfxObject *parentObj);

// Overide
public:
    virtual void onCreateView();

    virtual void onReleaseView();
    virtual void onRestoreView(VfxArchive *ar);
	virtual void onSerializeView(VfxArchive *ar);
protected:
    virtual void onTap(
        const VfxPoint &pos
    );
	virtual VfxPoint onGetEditButtonOffset();
//solt
private:
	void onSystemTimeChanged(
        VfxU32 flag // [IN] Is the flag to notify the type of date change
    );
private:
	void updateView(VfxU16 city_index);
	void launchWorldClock();
	void createDclock(VfxDateTime dt);
	void createDate(VfxDateTime dt);
// Variable
private: 
	VfxImageFrame *m_bg;
	VcpDigitalImageClock *m_dclock;
	VfxTextFrame *m_city;
	VcpDigitalTextClock *m_date;
	VfxTextFrame *m_am_pm;
	VfxDateTime m_dt;
	VfxBool m_launch;
};

#endif /*__MMI_VUI_WIDGET_DCLOCK__*/
#endif /* VAPP_WIDGET_HELLO_WORLD_H */

