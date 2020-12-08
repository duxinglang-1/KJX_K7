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
 *  vapp_screen_lock_zipper.cpp
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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


#include "MMI_features.h"

#ifdef __MMI_VUI_SCREEN_LOCK_ZIPPER__
#if defined(__MMI_VUI_SCREEN_LOCK_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_screen_lock_def.h"
#include "vapp_screen_lock_native_factory.h"

#include "vapp_screen_lock_zipper.h"
#include "mmi_rp_vapp_screen_lock_zipper_def.h"
#include "vapp_screen_lock_zipper_time.h"


// for wallpaper setting api
#include "vapp_wallpaper_setting_method_gprot.h"

#include "vapp_wallpaper_kit.h"
//#include "vapp_widget_music_player.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "GpioSrvGProt.h"

#ifdef __cplusplus
}
#endif


/*****************************************************************************
 * Screen Lock Zipper Class
 *****************************************************************************/

VAPP_SCREEN_LOCK_SYS_PUBLISH_NATIVE(
    VappScreenLockZipper,
    VAPP_SCREEN_LOCK_TYPE_ZIPPER,
    VappScreenLockZipperPublisher);

VAPP_SCREEN_LOCK_IMPLEMENT_CLASS(VappScreenLockZipper, VappScreenLock);


VappScreenLockZipper::VappScreenLockZipper():
	m_wallpaper(NULL), 
	m_isSuspendWallpaper(VFX_FALSE)
{
	zipper_pull_status = VFX_FALSE;
    // Do nothing.
}

VappScreenLockId VappScreenLockZipper::getId() const
{
    return VappScreenLockId(VAPP_SCREEN_LOCK_SRC_NATIVE, 
                            VAPP_SCREEN_LOCK_TYPE_ZIPPER);
}


VfxS32 VappScreenLockZipper::getName(
    VfxWChar *string,
    VfxS32 size) const
{

    VFX_ASSERT(string && size > 0);
    const VfxWChar *str = vfxSysResGetStr(STR_ID_VAPP_SCREEN_LOCK_ZIPPER_SETTING_NAME);
    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);
    return vfx_sys_wcslen(string);
}

VfxFrame *VappScreenLockZipper::createIcon(
    VfxObject *parentObj)
{
    VfxImageFrame *icon;
    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_ID_VAPP_SCREEN_LOCK_ZIPPER_SETTING_ICON);

    return icon;
}


VfxS32 VappScreenLockZipper::getScreenshotNum() const
{
	return 1;
}


VfxFrame** VappScreenLockZipper::createScreenshot(
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
	screenshot[0]->setResId(IMG_ID_VAPP_SCREEN_LOCK_ZIPPER_SETTING_SNAPSHOT);
	return (VfxFrame**)screenshot;
}


VfxBool VappScreenLockZipper::onGetStatusBarTranslucent()
{
    return TRUE;
}


VfxResId VappScreenLockZipper::onGetStatusBarBg()
{
    return IMG_ID_VAPP_SCREEN_LOCK_ZIPPER_STATUS_BAR_BG;
}


void VappScreenLockZipper::onCreateView()
{
    // unlock screen bg
    initWallpaper();

	// Time and Operator area
	VFX_OBJ_CREATE(m_timeArea, VappZipperScreenLockTime, this);
	VfxSize size = VfxSize(getSize().width, VAPP_ZIPPER_SCREEN_LOCK_DATE_TIME_SIZE_HEIGHT);
	m_timeArea->setSize(size);
	m_timeArea->setAnchor(1.0, 1.0);
	m_timeArea->setPos(getSize().width, getSize().height);
	m_timeArea->setIsUnhittable(VFX_TRUE);

	//ring pull initial position. get this value from motion_sensor ???
	VfxS32 ring_pull_init_height = LCD_HEIGHT/5; 
	g_ring_pull_curr_height = ring_pull_init_height;

	//empty frame
	VFX_OBJ_CREATE(m_empty_frame, VfxFrame, this);
	m_empty_frame->setCacheMode(VFX_CACHE_MODE_PREVENT);
	//full locked image frame
	VFX_OBJ_CREATE(m_full_locked_frame, VfxImageFrame, m_empty_frame);
	m_full_locked_frame->setResId(IMG_ID_VAPP_SCREEN_LOCK_ZIPPER_FULL_LOCKED);
	m_full_locked_frame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_COLOR_KEY);
	m_empty_frame->setBounds(m_full_locked_frame->getBounds());

	// zipper left frame
	VFX_OBJ_CREATE(m_zipper_left_frame, VfxImageFrame, this);
	m_zipper_left_frame->setResId(IMG_ID_VAPP_SCREEN_LOCK_ZIPPER_LEFT);
	m_zipper_left_frame->setAnchor(1,1);
	m_zipper_left_frame->setPos(ZIPPER_LEFT_FRAME_POS_X,ring_pull_init_height+ZIPPER_LEFT_FRAME_RING_OFFSET);
	//zipper right frame
	VFX_OBJ_CREATE(m_zipper_right_frame, VfxImageFrame, this);
	m_zipper_right_frame->setResId(IMG_ID_VAPP_SCREEN_LOCK_ZIPPER_RIGHT);
	m_zipper_right_frame->setAnchor(0,1);
	m_zipper_right_frame->setPos(ZIPPER_RIGHT_FRAME_POS_X,ring_pull_init_height+ZIPPER_LEFT_FRAME_RING_OFFSET);

	//ring pull frame
	VFX_OBJ_CREATE(m_ring_pull_frame, VfxImageFrame, this);
	m_ring_pull_frame->setResId(IMG_ID_VAPP_SCREEN_LOCK_ZIPPER_BFD);
	m_ring_pull_frame->setPos(ZIPPER_RING_PULL_POS_X,ring_pull_init_height);

	//Enable zipper open area fame filter
	VFX_OBJ_CREATE(pFilter,ZipperOpenAreaFilter,this);
	m_empty_frame->setFilter(pFilter);

	m_timeArea->bringToFront();

}


void VappScreenLockZipper::onReleaseView()
{
	deinitWallpaper();
	VFX_OBJ_CLOSE(m_timeArea);

	VFX_OBJ_CLOSE(m_ring_pull_frame);
	VFX_OBJ_CLOSE(m_zipper_left_frame);
	VFX_OBJ_CLOSE(m_zipper_right_frame);
	VFX_OBJ_CLOSE(m_empty_frame);
	VFX_OBJ_CLOSE(pFilter);
}


void VappScreenLockZipper::onPageEnter()
{
    // use gpio service app timer, set 8s to dimming
    srv_backlight_set_timer(SRV_BACKLIGHT_SET_TIMER_BY_APP, 
                    VAPP_SCREEN_LOCK_ZIPPER_BACKLIGHT_OFF_TIME*0.7,
                    VAPP_SCREEN_LOCK_ZIPPER_BACKLIGHT_OFF_TIME);
	m_wallpaper->resume();
}


void VappScreenLockZipper::onPageExit()
{
    // restore app timer when lock is not active
    srv_backlight_set_timer(SRV_BACKLIGHT_RESTORE_TIMER_BY_APP, 0, 0);
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
	m_wallpaper->suspend();
}

VfxBool VappScreenLockZipper::onPenInput(
			VfxPenEvent &event			// [IN] The pen event to be handled
		)
{

 
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
        {
			VfxS32 width,height;
			suspendWallpaper();
			width = m_ring_pull_frame->getBounds().getWidth();
			height = m_ring_pull_frame->getBounds().getHeight();
			VfxPoint Pos = m_ring_pull_frame->getPos();
			if(event.pos.x>=Pos.x &&event.pos.x<=Pos.x+width && event.pos.y>=Pos.y &&event.pos.y<=Pos.y+height)
			{
				zipper_pull_status = VFX_TRUE;
				g_ring_pull_curr_height = m_ring_pull_frame->getPos().y;
			}
            break;
        }

        case VFX_PEN_EVENT_TYPE_UP:
        {
			if(zipper_pull_status == VFX_TRUE)
			{
				zipper_pull_status = VFX_FALSE;
				if(g_ring_pull_curr_height>=ZIPPER_UNLOCK_POS_Y)
				{
					onUnlockHandler(NULL,0);
				}
			}
			resumeWallpaper();
            break;
        }

        case VFX_PEN_EVENT_TYPE_MOVE:
        {
			if(zipper_pull_status == VFX_TRUE)
			{
				VfxS32 move_distance = event.pos.y - event.prevPos.y;
				VfxS32 target_pos = m_ring_pull_frame->getPos().y + move_distance;
				target_pos = target_pos < 0 ? 0:target_pos>ZIPPER_MAX_RING_POS_Y ? ZIPPER_MAX_RING_POS_Y:target_pos;
				m_zipper_left_frame->setPos(VfxPoint(ZIPPER_LEFT_FRAME_POS_X, target_pos + ZIPPER_LEFT_FRAME_RING_OFFSET));
				m_zipper_right_frame->setPos(VfxPoint(ZIPPER_RIGHT_FRAME_POS_X, target_pos + ZIPPER_LEFT_FRAME_RING_OFFSET));
				m_ring_pull_frame->setPos(VfxPoint(ZIPPER_RING_PULL_POS_X, target_pos));

				g_ring_pull_curr_height = target_pos;
			}
			            
            break;
        }
        
        case VFX_PEN_EVENT_TYPE_ABORT:
        {
            break;
        } 

        default:
            break;
    }
    return VFX_TRUE;


}



void VappScreenLockZipper::onUnlockHandler(VfxObject* sender, VfxId Id)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_PAGE_ON_UNLOCK_HANDLER, 200); 
    m_signalUnlock.postEmit(this);
}




void VappScreenLockZipper::initWallpaper()
{
    VappWallpaperSettingInterface *wallpaperInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
    wallpaperInterface->m_signalWallpaperIsUpdated.connect(this, &VappScreenLockZipper::wallpaperUpdatedHdlr);

    createWallpaper();
}


void VappScreenLockZipper::createWallpaper()
{
	m_wallpaper = VappWallpaperKit::createWallpaper(this, VAPP_WALLPAPER_SRC_LOCK);
	m_wallpaper->setBounds(0,0,LCD_WIDTH,LCD_HEIGHT);

}


void VappScreenLockZipper::releaseWallpaper()
{
    if(m_wallpaper)
    {
        VFX_OBJ_CLOSE(m_wallpaper);
    }
}


void VappScreenLockZipper::wallpaperUpdatedHdlr()
{
    releaseWallpaper();
    createWallpaper();
}


void VappScreenLockZipper::deinitWallpaper()
{
    VappWallpaperSettingInterface *wallpaperInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
    wallpaperInterface->m_signalWallpaperIsUpdated.disconnect(this, &VappScreenLockZipper::wallpaperUpdatedHdlr);

    releaseWallpaper();
}

void VappScreenLockZipper::suspendWallpaper()
{

    if (!m_isSuspendWallpaper &&
        m_wallpaper->isAllowSuspendOnPenDown())
    {
        m_isSuspendWallpaper = VFX_TRUE;
        m_wallpaper->suspend();
    }
}


void VappScreenLockZipper::resumeWallpaper()
{
    if (m_isSuspendWallpaper)
    {
        m_isSuspendWallpaper = VFX_FALSE;
        if (m_wallpaper)
    	{
       	 	m_wallpaper->resume();
    	}
    }
}


/*****************************************************************************
 * Class ZipperOpenAreaFilter
 *****************************************************************************/

void ZipperOpenAreaFilter::onInit()
{
    VfxFrameFilter::onInit();
}

void ZipperOpenAreaFilter::onDeinit()
{
	VfxFrameFilter::onDeinit();
}


VfxFrameFilter::BufferModeEnum ZipperOpenAreaFilter:: onGetBufferMode() const
{
    
	return VfxFrameFilter::BUFFER_MODE_IN_PLACE;
}

VfxBool ZipperOpenAreaFilter::onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat timing)
{
    if (inBuf.colorFormat == VRT_COLOR_TYPE_RGB565)
	{
		VfxU8 *out_pixel_p = (VfxU8 *)outBuf;
		VfxS32 filter_height = g_ring_pull_curr_height+15;
        VfxS32 i,j;
		out_pixel_p += filter_height*LCD_WIDTH*2;  
		for (i = filter_height; i >= 0; i--)
		{   
		  	VfxS32 width = (VfxS16)(filter_height-i)*ZIPPER_ANGLE;
			VfxS32 offset = LCD_WIDTH/2-width;
			if(offset<0)
				offset = 0;
			  
			for (j = offset; j < LCD_WIDTH-offset; j++)
			{ 		  
				*(out_pixel_p+j*2) = 0x1F;
				*(out_pixel_p+j*2+1)= 0x00;
			}
			out_pixel_p -= LCD_WIDTH*2;
		}

	}	

      return VFX_TRUE;
};

#endif /* defined(__MMI_VUI_SCREEN_LOCK_FACTORY__) */
#endif /* ifdef __MMI_VUI_SCREEN_LOCK_ZIPPER__ */


