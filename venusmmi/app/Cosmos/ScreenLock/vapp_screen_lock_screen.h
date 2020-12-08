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
 *  vapp_screen_lock_screen.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SCREEN_LOCK_SCREEN_H__
#define __VAPP_SCREEN_LOCK_SCREEN_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"

#include "vapp_screen_lock_cosmos_unlock_item_factory.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
class VappScreenLockFrame;
class VappScreenLockTime;
class VappWallpaper;
class VappWidgetMusicPlayerInfoPanel;
class VappWidgetFmRadioPanel;
class VappScreenLockCard;
class VappScreenLock;

#define VAPP_SCREEN_LOCK_BACKLIGHT_OFF_TIME                8


/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappScreenLockScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappScreenLockScreen);
//constructor
public:
    VappScreenLockScreen();
    virtual ~VappScreenLockScreen();
    
// Override
public:
    virtual void on1stReady();

protected:
    virtual mmi_ret onProc(mmi_event_struct * evt);
};


class VappScreenLockPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappScreenLockPage);

// Constructor
public:
    VappScreenLockPage();

// Override
public:
    virtual void onInit();
    virtual void onDeinit();

    // stop back key while screen lock
    virtual void onBack();

    // application is activated
    virtual void onEnter(VfxBool isBackward);

    // application is inactivated, all belonging screens are invisible.
    virtual void onExit(VfxBool isBackward);

    // When the screen lock becomes active, this function is called.
    void onAppActive();

    // When the screen lock becomes inactive, this function is called.
    void onAppInactive();

    // When the screen lock becomes group snapshot active, this function is called.
    void onGroupSnapActive();

    // When the screen lock becomes group snapshot inactive, this function is called.    
    void onGroupSnapInactive();

private:
    void onUnlockHandler(VappScreenLock *frame);
    static mmi_ret eventHandler(mmi_event_struct *event);

    // handler when receiving sleep in event
    mmi_ret backlightOffHandler(mmi_event_struct *event);

    // handler when receiving sleep Out event
    mmi_ret backlightOnHandler(mmi_event_struct *event);

// Variable
private:
    VappScreenLock *m_screenLock;
};


#endif /* __VAPP_SCREEN_LOCK_SCREEN_H__ */

