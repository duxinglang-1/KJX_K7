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
 *  vapp_screen_lock_painting.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the simple screen lock class
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_SCREEN_LOCK_FACTORY__) && defined(__MMI_VUI_SCREEN_LOCK_PAINTING__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_screen_lock_def.h"
#include "vapp_screen_lock_painting.h"
#include "vapp_screen_lock_native_factory.h"
#include "mmi_rp_vapp_screen_lock_painting_def.h"

#include "vdat_systime.h"
#include "vfx_date_time.h"
#include "Vfx_page.h"


/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "GpioSrvGProt.h"
#include "Gdi_primitive.h"

#ifdef __cplusplus
}
#endif

#if defined (__MMI_MAINLCD_240X320__)
static const VfxS32 SCREEN_LOCK_PAINTING_MARGIN_X = -8;
static const VfxS32 SCREEN_LOCK_PAINTING_FISH_POS_Y = 210;
static const VfxS32 SCREEN_LOCK_PAINTING_DRAGON_FIY_POS_X = 114;
static const VfxS32 SCREEN_LOCK_PAINTING_DRAGON_FIY_POS_Y = 83;
static const VfxS32 SCREEN_LOCK_PAINTING_TIME_AREA_HEIGHT = 96;
static const VfxS32 SCREEN_LOCK_PAINTING_DOT_TOP_MARGIN_Y = 24;
static const VfxS32 SCREEN_LOCK_PAINTING_INDICATOR_TOP_MARGIN = 65;
static const VfxS32 SCREEN_LOCK_PAINTING_DRAG_THRESHOLD = 35;
#elif defined (__MMI_MAINLCD_240X400__)
static const VfxS32 SCREEN_LOCK_PAINTING_MARGIN_X = -8;
static const VfxS32 SCREEN_LOCK_PAINTING_FISH_POS_Y = 290;
static const VfxS32 SCREEN_LOCK_PAINTING_DRAGON_FIY_POS_X = 114;
static const VfxS32 SCREEN_LOCK_PAINTING_DRAGON_FIY_POS_Y = 163;
static const VfxS32 SCREEN_LOCK_PAINTING_TIME_AREA_HEIGHT = 96;
static const VfxS32 SCREEN_LOCK_PAINTING_DOT_TOP_MARGIN_Y = 24;
static const VfxS32 SCREEN_LOCK_PAINTING_INDICATOR_TOP_MARGIN = 65;
static const VfxS32 SCREEN_LOCK_PAINTING_DRAG_THRESHOLD = 38;
#elif defined (__MMI_MAINLCD_320X480__)
static const VfxS32 SCREEN_LOCK_PAINTING_MARGIN_X = -10;
static const VfxS32 SCREEN_LOCK_PAINTING_FISH_POS_Y = 326;
static const VfxS32 SCREEN_LOCK_PAINTING_DRAGON_FIY_POS_X = 155;
static const VfxS32 SCREEN_LOCK_PAINTING_DRAGON_FIY_POS_Y = 159;
static const VfxS32 SCREEN_LOCK_PAINTING_TIME_AREA_HEIGHT = 128;
static const VfxS32 SCREEN_LOCK_PAINTING_DOT_TOP_MARGIN_Y = 29;
static const VfxS32 SCREEN_LOCK_PAINTING_INDICATOR_TOP_MARGIN = 87;
static const VfxS32 SCREEN_LOCK_PAINTING_DRAG_THRESHOLD = 40;
#else //defined (__MMI_MAINLCD_480X800__)
static const VfxS32 SCREEN_LOCK_PAINTING_MARGIN_X = -14;
static const VfxS32 SCREEN_LOCK_PAINTING_FISH_POS_Y = 520;
static const VfxS32 SCREEN_LOCK_PAINTING_DRAGON_FIY_POS_X = 231;
static const VfxS32 SCREEN_LOCK_PAINTING_DRAGON_FIY_POS_Y = 276;
static const VfxS32 SCREEN_LOCK_PAINTING_TIME_AREA_HEIGHT = 193;
static const VfxS32 SCREEN_LOCK_PAINTING_DOT_TOP_MARGIN_Y = 48;
static const VfxS32 SCREEN_LOCK_PAINTING_INDICATOR_TOP_MARGIN = 129;
static const VfxS32 SCREEN_LOCK_PAINTING_DRAG_THRESHOLD = 60;
#endif

/*****************************************************************************
 * Screen Lock Painting Class
 *****************************************************************************/

VAPP_SCREEN_LOCK_SYS_PUBLISH_NATIVE(
    VappScreenLockPainting,
    VAPP_SCREEN_LOCK_TYPE_PAINTING,
    VappScreenLockPaintingPublisher);

VAPP_SCREEN_LOCK_IMPLEMENT_CLASS(VappScreenLockPainting, VappScreenLock);


VappScreenLockPainting::VappScreenLockPainting():
	m_bg(NULL),
	m_fish(NULL),
	m_dragonFly(NULL),
	m_timeArea(NULL),
	m_isFlapOn(VFX_FALSE),
	m_timerFish(NULL)
{
    // Do nothing.
}

/*
void VappScreenLockPainting::onInit()
{
    VappScreenLock::onInit();  //private function, cannot access here.
}


void VappScreenLockPainting::onDeinit()
{
    VappScreenLock::onDeinit();
}
*/

VappScreenLockId VappScreenLockPainting::getId() const
{
    return VappScreenLockId(VAPP_SCREEN_LOCK_SRC_NATIVE, 
                            VAPP_SCREEN_LOCK_TYPE_PAINTING);
}


VfxS32 VappScreenLockPainting::getName(
    VfxWChar *string,
    VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(STR_ID_VAPP_SCREEN_LOCK_PAINTING_NAME);

    VFX_ASSERT(string && size > 0);

    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);

}

VfxFrame *VappScreenLockPainting::createIcon(
    VfxObject *parentObj)
{
	VfxImageFrame *img;
	VFX_OBJ_CREATE(img, VfxImageFrame, parentObj);
	img->setResId(IMG_ID_VAPP_SCREEN_LOCK_PAINTING_BG);

    return img;
}


VfxS32 VappScreenLockPainting::getScreenshotNum() const
{
	return 1;
}


VfxFrame** VappScreenLockPainting::createScreenshot(
        VfxObject *parent           // [IN] Parent of the screenshots
    ) const
{
	VfxImageFrame **screenshot = NULL;
	VfxS32 num = getScreenshotNum();
	VFX_ALLOC_MEM(screenshot, sizeof(VfxImageFrame*) * num, parent);
	
	for(VfxS32 i = 0; i < num; i++)
	{
		VFX_OBJ_CREATE(screenshot[i], VfxImageFrame, parent);
	}
	screenshot[0]->setResId(IMG_ID_VAPP_SCREEN_LOCK_PAINTING_SCREENSHOT);
	return (VfxFrame**)screenshot;
}


void VappScreenLockPainting::onCreateView()
{
	//bg
	VFX_OBJ_CREATE(m_bg, VfxImageFrame, this);
	m_bg->setPos(0, 0);
	m_bg->setIsOpaque(VFX_TRUE);
	m_bg->setImgContent(VfxImageSrc(IMG_ID_VAPP_SCREEN_LOCK_PAINTING_BG));

    //timer for fish animation
    VFX_OBJ_CREATE(m_timerFish, VfxTimer, this);
    m_timerFish->setStartDelay(3000);
    m_timerFish->m_signalTick.connect(this, &VappScreenLockPainting::onTimerTickFish);
    
	//fish
	VFX_OBJ_CREATE(m_fish, VfxAnimImageFrame, this);
	m_fish->setPos(0, SCREEN_LOCK_PAINTING_FISH_POS_Y);
	m_fish->setResId(IMG_ID_VAPP_SCREEN_LOCK_PAINTING_FISH);
    //m_fish->playImgContent(1, VfxCallback0(this, &VappScreenLockPainting::onFishAnimationEndCallback));
    m_fish->setRepeatCount(1);
    m_fish->m_signalEnd.connect(this, &VappScreenLockPainting::onFishAnimationEndCallback);
    m_fish->play();
	
	//fly
	VFX_OBJ_CREATE(m_dragonFly, VfxImageFrame, this);
	m_dragonFly->setPos(SCREEN_LOCK_PAINTING_DRAGON_FIY_POS_X, SCREEN_LOCK_PAINTING_DRAGON_FIY_POS_Y);
	m_dragonFly->setAnchor(0.0f, 0.0f);
    m_dragonFly->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_TRANSLUCENT);
	
	VfxImageSrc img(IMG_ID_VAPP_SCREEN_LOCK_PAINTING_FLY01);
    m_dragonFly->setSize(img.getSize().width, img.getSize().height);

    VFX_OBJ_CREATE(m_dragonFlyFilter, VappDragonFlyFilter, this);
    m_dragonFly->setFilter(m_dragonFlyFilter);
    
    VFX_OBJ_CREATE(m_dragonFlyTimeline, VfxFloatTimeline, this);
    m_dragonFlyTimeline->setTarget(m_dragonFly);
    m_dragonFlyTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
    m_dragonFlyTimeline->setFromValue(0.0f);
    m_dragonFlyTimeline->setToValue(1.0f);
    m_dragonFlyTimeline->setDuration(1000);
    m_dragonFlyTimeline->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);

	//timeArea
	VFX_OBJ_CREATE(m_timeArea, VappScreenLockPaintingTimeArea, this);
	m_timeArea->setAnchor(0.0f, 1.0f);
	m_timeArea->setPos(0, getSize().height);
	m_timeArea->m_signalUnlock.connect(this, &VappScreenLockPainting::onUnlockHandler);
	m_timeArea->setAutoAnimate(VFX_TRUE);

}


void VappScreenLockPainting::onReleaseView()
{
	VFX_OBJ_CLOSE(m_bg);
	VFX_OBJ_CLOSE(m_fish);
	VFX_OBJ_CLOSE(m_dragonFly);
	VFX_OBJ_CLOSE(m_timeArea);
    VFX_OBJ_CLOSE(m_timerFish);
    VFX_OBJ_CLOSE(m_dragonFlyFilter);
    VFX_OBJ_CLOSE(m_dragonFlyTimeline);
}


void VappScreenLockPainting::onPageEnter()
{
    // use gpio service app timer, set 8s to dimming
    srv_backlight_set_timer(SRV_BACKLIGHT_SET_TIMER_BY_APP, 
                    VAPP_SCREEN_LOCK_PAINTING_BACKLIGHT_OFF_TIME*0.7,
                    VAPP_SCREEN_LOCK_PAINTING_BACKLIGHT_OFF_TIME);

	if(!m_dragonFlyTimeline->getIsEnabled())
	{
        m_dragonFlyTimeline->start();
	}
}


void VappScreenLockPainting::onPageExit()
{
    // restore app timer when lock is not active
    srv_backlight_set_timer(SRV_BACKLIGHT_RESTORE_TIMER_BY_APP, 0, 0);
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

	if(m_dragonFlyTimeline->getIsEnabled())
	{
        m_dragonFlyTimeline->stop();
	}
}


VfxResId VappScreenLockPainting::onGetStatusBarBg()
{
	return IMG_ID_VAPP_SCREEN_LOCK_PAINTING_STATUSBAR_BG;
}


VfxBool VappScreenLockPainting::onGetStatusBarTranslucent()
{
	return VFX_TRUE;
}


VfxBool VappScreenLockPainting::onPenInput(VfxPenEvent &event)
{
	if(event.type == VFX_PEN_EVENT_TYPE_DOWN)
	{
		return VFX_TRUE;
	}
	else if(event.type == VFX_PEN_EVENT_TYPE_MOVE && m_timeArea->containPoint(event.getRelPos(m_timeArea)))
	{
		VfxPoint pt = event.getRelPos(m_timeArea);
		VfxFloat anchor_y = (VfxFloat)pt.y / m_timeArea->getSize().height;
		VfxAutoAnimate::begin();
		VfxAutoAnimate::setDisable(VFX_TRUE);
		m_timeArea->setAnchor(0.0f, anchor_y);
		m_timeArea->setPos(0, event.pos.y);
		VfxAutoAnimate::commit();
		m_timeArea->setOpacity(0.7f);

		m_timeArea->capture();
		return VFX_TRUE;
	}

	return VfxControl::onPenInput(event);
}



void VappScreenLockPainting::onUnlockHandler(VfxObject* sender)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_PAGE_ON_UNLOCK_HANDLER, 200);
    m_signalUnlock.postEmit(this);
}

void VappScreenLockPainting::onFishAnimationEndCallback(VfxObject *frame)
{
    m_fish->setHidden(VFX_TRUE);
    m_timerFish->start();
}
    
void VappScreenLockPainting::onTimerTickFish(VfxTimer *timer)
{
    m_fish->setHidden(VFX_FALSE);
    m_fish->setRepeatCount(1);
    m_fish->m_signalEnd.connect(this, &VappScreenLockPainting::onFishAnimationEndCallback);
    m_fish->play();
}


/*****************************************************************************
 * Screen Lock Time Area Class
 *****************************************************************************/

VappScreenLockPaintingTimeArea::VappScreenLockPaintingTimeArea()
{
	for(VfxS32 i = 0; i < 2; i++)
	{
		m_timeHour[i] = NULL;
		m_timeMin[i] = NULL;
	}
	m_state = STATE_NORMAL;
}


void VappScreenLockPaintingTimeArea::onInit()
{
	VfxControl::onInit();
	
	setBgColor(VFX_COLOR_TRANSPARENT);
	setSize(LCD_WIDTH, SCREEN_LOCK_PAINTING_TIME_AREA_HEIGHT);

	//time bg
	VFX_OBJ_CREATE(m_timeBg, VfxImageFrame, this);
	m_timeBg->setPos(0, 0);
	m_timeBg->setResId(IMG_ID_VAPP_SCREEN_LOCK_PAINTING_TIME_BG);

	//time 
	for(VfxS32 i = 0; i < 2; i++)
	{
		VFX_OBJ_CREATE(m_timeHour[i], VfxImageFrame, this);
		VFX_OBJ_CREATE(m_timeMin[i], VfxImageFrame, this);
	}
	VFX_OBJ_CREATE(m_timeDot, VfxImageFrame, this);

	layoutTimeArea();
	
	//time indicator
	VFX_OBJ_CREATE(m_timeIndicator, VfxImageFrame, this);
	m_timeIndicator->setAnchor(0.5f, 0.0f);
	m_timeIndicator->setPos(getSize().width/2, SCREEN_LOCK_PAINTING_INDICATOR_TOP_MARGIN);
	m_timeIndicator->setResId(IMG_ID_VAPP_SCREEN_LOCK_PAINTING_INDICATOR);

	VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappScreenLockPaintingTimeArea::timeUpdate);

	timeUpdate(VDAT_SYSTIME_CHANGED_MIN);
}


VfxBool VappScreenLockPaintingTimeArea::onPenInput(VfxPenEvent &event)
{
	VfxPoint pt = event.getRelPos(this);
	if(event.type == VFX_PEN_EVENT_TYPE_DOWN)
	{
		m_state = STATE_PRESSED;
		
		VfxFloat anchor_y = (VfxFloat)pt.y / getSize().height;
		VfxAutoAnimate::begin();
		VfxAutoAnimate::setDisable(VFX_TRUE);
		setAnchor(0.0f, anchor_y);
		setPos(0, event.pos.y);
		VfxAutoAnimate::commit();
		setOpacity(0.7f);
		
		return VFX_TRUE;
	}
	else if(event.type == VFX_PEN_EVENT_TYPE_MOVE)
	{
		if(m_state == STATE_PRESSED)
		{
			pt = event.getRelPos(this);

			VfxAutoAnimate::begin();
			VfxAutoAnimate::setDisable(VFX_TRUE);
			forcePos(VfxPoint(0, event.pos.y > event.downPos.y ? event.pos.y : event.downPos.y));
			VfxAutoAnimate::commit();
		}
		return VFX_TRUE;
	}
	else if(event.type == VFX_PEN_EVENT_TYPE_UP)
	{
		if(m_state == STATE_PRESSED)
		{
			m_state = STATE_NORMAL;
			if(getPos().y > event.downPos.y + SCREEN_LOCK_PAINTING_DRAG_THRESHOLD)
			{
				flyOut();
			}
			else if(getPos().y <= event.downPos.y)
			{
				reset(VFX_TRUE);
			}
			else
			{
				reset(VFX_FALSE);
			}
		}
		return VFX_TRUE;
	}
	else if(event.type == VFX_PEN_EVENT_TYPE_ABORT)
	{
		reset(VFX_FALSE);
		return VFX_TRUE;
	}

	return VfxControl::onPenInput(event);
}


void VappScreenLockPaintingTimeArea::layoutTimeArea()
{
	VfxS32 offsetY = SCREEN_LOCK_PAINTING_DOT_TOP_MARGIN_Y;
	VfxImageSrc dotImage(IMG_ID_VAPP_SCREEN_LOCK_PAINTING_TIME_DOT);
	VfxS32 imgWidth = dotImage.getSize().width;
	
	m_timeDot->setAnchor(0.5f, 0.0f);
	m_timeDot->setPos(getSize().width/2 , offsetY);
	m_timeDot->setResId(IMG_ID_VAPP_SCREEN_LOCK_PAINTING_TIME_DOT);

	m_timeHour[0]->setAnchor(0.5f, 0.0f);
	m_timeHour[0]->setPos(getSize().width/2 - 2 * (SCREEN_LOCK_PAINTING_MARGIN_X + imgWidth), offsetY);

	m_timeHour[1]->setAnchor(0.5f, 0.0f);
	m_timeHour[1]->setPos(getSize().width/2 - SCREEN_LOCK_PAINTING_MARGIN_X - imgWidth, offsetY);

	m_timeMin[0]->setAnchor(0.5f, 0.0f);
	m_timeMin[0]->setPos(getSize().width/2 + SCREEN_LOCK_PAINTING_MARGIN_X + imgWidth, offsetY);

	m_timeMin[1]->setAnchor(0.5f, 0.0f);
	m_timeMin[1]->setPos(getSize().width/2 + 2 * (SCREEN_LOCK_PAINTING_MARGIN_X + imgWidth), offsetY);
}

void VappScreenLockPaintingTimeArea::timeUpdate(VfxU32 flag)
{
	if(flag & VDAT_SYSTIME_CHANGED_MIN || flag & VDAT_SYSTIME_CHANGED_HOUR)
	{
		VfxDateTime time;
		time.setCurrentTime();

		//hour
		VfxU32 hour;
		hour = time.getHour();
		m_timeHour[0]->setResId(IMG_ID_VAPP_SCREEN_LOCK_PAINTING_TIME_00 + hour / 10);
		m_timeHour[1]->setResId(IMG_ID_VAPP_SCREEN_LOCK_PAINTING_TIME_00 + hour % 10);

		//minute
		VfxU32 min;
		min = time.getMinute();
		m_timeMin[0]->setResId(IMG_ID_VAPP_SCREEN_LOCK_PAINTING_TIME_00 + min / 10);
		m_timeMin[1]->setResId(IMG_ID_VAPP_SCREEN_LOCK_PAINTING_TIME_00 + min % 10);
	}
}

void VappScreenLockPaintingTimeArea::reset(VfxBool isNoAnimation)
{
	VfxAutoAnimate::begin();
	VfxAutoAnimate::setDisable(isNoAnimation);
	setPos(0, LCD_HEIGHT);
	setOpacity(1.0f);
	setAnchor(0.0, 1.0f);
	VfxAutoAnimate::commit();
	m_state = STATE_NORMAL;
}

void VappScreenLockPaintingTimeArea::flyOut()
{
    VfxS32Timeline *tl;
    VFX_OBJ_CREATE(tl, VfxS32Timeline, this);
    tl->setTarget(this);
    tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Y);
    tl->setIsFromCurrent(VFX_TRUE);
    tl->setToValue(LCD_HEIGHT + getSize().height);
    tl->setDuration(250);
    tl->m_signalStopped.connect(this, &VappScreenLockPaintingTimeArea::onTimelineStopped);
    tl->start();
}

void VappScreenLockPaintingTimeArea::onTimelineStopped(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    m_signalUnlock.postEmit(this);
}

/*****************************************************************************
 * Screen Lock DragonFly Filter Class
 *****************************************************************************/
VappDragonFlyFilter::VappDragonFlyFilter():
    m_count(0)
{
}

void VappDragonFlyFilter::onInit()
{
    VfxFrameFilter::onInit();
    setResourceFromResId('UP', IMG_ID_VAPP_SCREEN_LOCK_PAINTING_FLY01);
    setResourceFromResId('DOWN', IMG_ID_VAPP_SCREEN_LOCK_PAINTING_FLY02);
}

VfxBool VappDragonFlyFilter::onProcess(VfxU8 * outBuf,VfxImageBuffer & inBuf,VfxFloat timing)
{
    //alternate two image every 5 frame
    VfxImageBuffer imgBuf;
    if(m_count%10 < 5)
    {
        getResource('UP', imgBuf);
    }
    else
    {
        getResource('DOWN', imgBuf);
    }
    VFX_DEV_ASSERT(imgBuf.ptr);

    gdi_img_buf_color_format_enum colorFormat;
    switch(inBuf.colorFormat)
    {
        case VRT_COLOR_TYPE_PARGB8888:
            colorFormat = GDI_IMG_BUF_COLOR_FORMAT_PARGB8888;
            break;
        case VRT_COLOR_TYPE_ARGB8888:
            colorFormat = GDI_IMG_BUF_COLOR_FORMAT_ARGB8888;
            break;
        default:
            VFX_DEV_ASSERT(VFX_FALSE); // only support ARGB8888 or PARGB8888
            return VFX_FALSE;
    }
    gdi_img_buf_struct src;
    src.color_format = colorFormat;
    src.pitch_bytes = imgBuf.pitchBytes;
    src.ptr = reinterpret_cast<VfxU8*>(imgBuf.ptr);

    gdi_img_buf_struct dst;
    dst.color_format = colorFormat;
    dst.pitch_bytes = inBuf.pitchBytes;
    dst.ptr = reinterpret_cast<VfxU8*>(outBuf);

    gdi_img_buf_copy(&dst, &src, inBuf.width, inBuf.height);

    m_count++;
    if(m_count >= 100)
    {
        m_count = 0;
    }
    return VFX_TRUE;
}

#endif /* defined(__MMI_VUI_SCREEN_LOCK_FACTORY__) && defined(__MMI_VUI_SCREEN_LOCK_PAINTING__) */

