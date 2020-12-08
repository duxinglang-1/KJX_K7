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
 *  vapp_screen_lock_zipper.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the zipper screen lock class.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef VAPP_SCREEN_LOCK_ZIPPER_H
#define VAPP_SCREEN_LOCK_ZIPPER_H

#include "MMI_features.h"

#if defined(__MMI_VUI_SCREEN_LOCK_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_screen_lock_base.h"
#include "vcp_button.h"
#include "vapp_screen_lock_zipper_time.h"

#include "vfx_frame_filter.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VAPP_SCREEN_LOCK_ZIPPER_BACKLIGHT_OFF_TIME                8


#if defined(__MMI_MAINLCD_480X800__)
#define ZIPPER_LEFT_FRAME_POS_X      		250
#define ZIPPER_RIGHT_FRAME_POS_X     		233
#define ZIPPER_RING_PULL_POS_X       		175
#define ZIPPER_LEFT_FRAME_RING_OFFSET     	14
#define ZIPPER_ANGLE                 		0.37  
#define ZIPPER_MAX_RING_POS_Y               610
#define ZIPPER_UNLOCK_POS_Y          		550

#elif defined(__MMI_MAINLCD_320X480__)
#define ZIPPER_LEFT_FRAME_POS_X      		164
#define ZIPPER_RIGHT_FRAME_POS_X     		158
#define ZIPPER_RING_PULL_POS_X       		111
#define ZIPPER_LEFT_FRAME_RING_OFFSET     	10
#define ZIPPER_ANGLE                 		0.37  
#define ZIPPER_MAX_RING_POS_Y               380
#define ZIPPER_UNLOCK_POS_Y          		280

#elif defined(__MMI_MAINLCD_240X400__)
#define ZIPPER_LEFT_FRAME_POS_X      		124
#define ZIPPER_RIGHT_FRAME_POS_X     		117
#define ZIPPER_RING_PULL_POS_X       		83
#define ZIPPER_LEFT_FRAME_RING_OFFSET     	10
#define ZIPPER_ANGLE                 		0.37  
#define ZIPPER_MAX_RING_POS_Y               300
#define ZIPPER_UNLOCK_POS_Y          		260

#elif defined(__MMI_MAINLCD_240X320__)
#define ZIPPER_LEFT_FRAME_POS_X      		124
#define ZIPPER_RIGHT_FRAME_POS_X     		118
#define ZIPPER_RING_PULL_POS_X      		83
#define ZIPPER_LEFT_FRAME_RING_OFFSET     	10
#define ZIPPER_ANGLE                 		0.37  
#define ZIPPER_MAX_RING_POS_Y               240
#define ZIPPER_UNLOCK_POS_Y          		190


#else
#define ZIPPER_LEFT_FRAME_POS_X      		164
#define ZIPPER_RIGHT_FRAME_POS_X     		158
#define ZIPPER_RING_PULL_POS_X       		111
#define ZIPPER_LEFT_FRAME_RING_OFFSET     	10
#define ZIPPER_ANGLE                 		0.37  
#define ZIPPER_MAX_RING_POS_Y               380
#define ZIPPER_UNLOCK_POS_Y          		280


#endif


VfxS32  g_ring_pull_curr_height = 0;

class VappWallpaper;
class ZipperOpenAreaFilter;


/*****************************************************************************
 * Screen Lock ZipperOpenAreaFilter Class
 *****************************************************************************/

class ZipperOpenAreaFilter : public VfxFrameFilter
{
// Constructor
public:
	ZipperOpenAreaFilter(){};
	~ZipperOpenAreaFilter(){};
// Overridable
protected:
    virtual BufferModeEnum onGetBufferMode() const;
    virtual VfxBool onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat timing);
	virtual void onInit();
    virtual void onDeinit();
};


/*****************************************************************************
 * Screen Lock Zipper Class
 *****************************************************************************/
/*
 * Screen Lock Zipper Class
 */
class VappScreenLockZipper : public VappScreenLock
{
    VAPP_SCREEN_LOCK_DECLARE_CLASS(VappScreenLockZipper);

// Constructor / Destructor
public:
    // Default constructor
    VappScreenLockZipper();

// Override
public:
    virtual VappScreenLockId getId() const;

    // This function gets the number of the screenshots.
    // RETURNS: Number of screenshots.
    virtual VfxS32 getScreenshotNum() const;

    // This function creates the screenshots.
    // RETURNS: Array of the screenshots.
    virtual VfxFrame **createScreenshot(
        VfxObject *parent           // [IN] Parent of the screenshots
    ) const;

// Override
protected:
    virtual void onCreateView();
    virtual void onReleaseView();
    virtual void onPageEnter();
    virtual void onPageExit();
	virtual VfxBool onGetStatusBarTranslucent();
	virtual VfxResId onGetStatusBarBg();

    virtual VfxS32 getName(
        VfxWChar *string,           // [OUT] String buffer
        VfxS32 size                 // [IN] Buffer size in wchar
    ) const;

    virtual VfxFrame *createIcon(
        VfxObject *parentObj        // [IN] Parent object
    );
	
	virtual VfxBool onPenInput(
			VfxPenEvent &event			// [IN] The pen event to be handled
		);

// Method
private:
    void onUnlockHandler(VfxObject* sender, VfxId Id);

// Variable
private:

    // This function initializes the wallpaper.
    void initWallpaper();
    
    void createWallpaper();
    void releaseWallpaper();

    // This function deinitializes the wallpaper.
    void deinitWallpaper();

    void wallpaperUpdatedHdlr();
	
	void suspendWallpaper();

	void resumeWallpaper();


private:
	
	// Background image frame
    VappWallpaper               *m_wallpaper;


    // operator and time area
    VappZipperScreenLockTime     *m_timeArea;

	//full locked frame
	VfxImageFrame  * m_full_locked_frame;

	//ring pull frame
	VfxImageFrame  * m_ring_pull_frame;

	//zipper left frame
	VfxImageFrame  * m_zipper_left_frame;

	//zipper right frame
	VfxImageFrame  * m_zipper_right_frame;
	//empty_frame
	VfxFrame *m_empty_frame;
	//zipper open area filter
	ZipperOpenAreaFilter *pFilter;

	VfxBool zipper_pull_status;

	VfxBool m_isSuspendWallpaper;
	
};

#endif /* defined(__MMI_VUI_SCREEN_LOCK_FACTORY__) */
#endif /* VAPP_SCREEN_LOCK_ZIPPER_H */


