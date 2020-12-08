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
 *  vapp_shell_switch.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file defines the shell control application
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_SHELL_SCRLOCK_H__
#define __VAPP_SHELL_SCRLOCK_H__

#include "MMI_features.h"

#if defined(__MMI_VUI_SHELL_SCREEN_LOCK__)

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_frame.h"
#include "vfx_text_frame.h"
#include "vfx_datatype.h"
#include "vfx_primitive_frame.h"
#include "vcp_button.h"
#include "vfx_animation.h"
#include "vfx_object.h"
#include "vfx_cpp_base.h"
#include "vfx_signal.h"
#include "vfx_app_cat_scr.h"
#include "vcp_status_icon_bar.h"
#include "vcp_pluto_control.h"
#include "vcp_app_scr.h"
#include "vapp_op01_hs_cp.h"



#if defined __MMI_MAINLCD_320X480__

#define VAPP_SHELL_SCRLOCK_DATE_TIME_AREA_Y         336
#define VAPP_SHELL_SCRLOCK_DATE_TIME_AREA_HEIGHT    92

#define VAPP_SHELL_SCRLOCK_PROGRESS_Y               (VAPP_SHELL_SCRLOCK_DATE_TIME_AREA_Y + VAPP_SHELL_SCRLOCK_DATE_TIME_AREA_HEIGHT)
#define VAPP_SHELL_SCRLOCK_PROGRESS_HEIGHT          51
#define VAPP_SHELL_SCRLOCK_PROGRESS_WIDTH           240

#elif defined __MMI_MAINLCD_240X400__

#define VAPP_SHELL_SCRLOCK_DATE_TIME_AREA_Y         261
#define VAPP_SHELL_SCRLOCK_DATE_TIME_AREA_HEIGHT    87

#define VAPP_SHELL_SCRLOCK_PROGRESS_Y               (VAPP_SHELL_SCRLOCK_DATE_TIME_AREA_Y + VAPP_SHELL_SCRLOCK_DATE_TIME_AREA_HEIGHT)
#define VAPP_SHELL_SCRLOCK_PROGRESS_HEIGHT          51
#define VAPP_SHELL_SCRLOCK_PROGRESS_WIDTH           160

#elif defined __MMI_MAINLCD_240X320__

#define VAPP_SHELL_SCRLOCK_DATE_TIME_AREA_Y         191
#define VAPP_SHELL_SCRLOCK_DATE_TIME_AREA_HEIGHT    77

#define VAPP_SHELL_SCRLOCK_PROGRESS_Y               (VAPP_SHELL_SCRLOCK_DATE_TIME_AREA_Y + VAPP_SHELL_SCRLOCK_DATE_TIME_AREA_HEIGHT)
#define VAPP_SHELL_SCRLOCK_PROGRESS_HEIGHT          51
#define VAPP_SHELL_SCRLOCK_PROGRESS_WIDTH           160

#else
#error "Shell does not support this LCD resolution."
#endif

/***************************************************************************** 
 * Class VappShellScrLock
 *****************************************************************************/
class VappShellScrLockDateTimeArea : public VfxFrame
{
private:
    VfxFrame            *m_DateTimeBg;
    VfxTextFrame        *m_Time;
    VfxTextFrame        *m_AmPm;
    VfxTextFrame        *m_WeekDay;
    VfxTextFrame        *m_Date;

public:
    VappShellScrLockDateTimeArea();
    void timeUpdate(VfxU32 flag);

protected:
    // On init
    virtual void onInit();
    // On Deinit
    virtual void onDeinit();
};

class VappShellScrLockProgress : public VfxFrame
{
private:
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        TOP_MARGIN = 7,
        BOTTOM_MARGIN = 4
    #elif defined(__MMI_MAINLCD_240X400__)
        TOP_MARGIN = 6,
        BOTTOM_MARGIN = 3
    #else /* defined(__MMI_MAINLCD_240X320__) */
        TOP_MARGIN = 5,
        BOTTOM_MARGIN = 2
    #endif /* defined(__MMI_MAINLCD_240X320__) */
    };

private:
    VfxImageFrame       *m_bgImg;
    VfxImageFrame       *m_Progress;
    VfxTextFrame        *m_Text;
    VfxU8               m_value;
    VcpButton           *m_ActButton;
    VfxS32Timeline      *m_timeline;

public:
    VappShellScrLockProgress();
    void ButtonStateChange(VfxObject* sender, VfxId Id, VcpButtonStateEnum state);
    void TimeStop(VfxBaseTimeline * obj, VfxBool reason);
    void Start(void);
    void Cancel(void);
    VfxSignal0 m_event1;

protected:
    virtual void onInit();
};

class VappShellScrLockScr : public VfxAppCatScr
{
private:
    VcpStatusIconBar                *m_iconBar;
    VfxImageFrame                   *m_bgImg;
    VappShellScrLockDateTimeArea    *m_dateTimeArea;
    VappShellScrLockProgress        *m_progressBar;

public:
    VappShellScrLockScr();
    void ButtonHandler();

protected:
    virtual void onInit();
};

#endif /* defined(__MMI_VUI_SHELL_SCREEN_LOCK__) */
#endif /* __VAPP_SHELL_SCRLOCK_H__ */
