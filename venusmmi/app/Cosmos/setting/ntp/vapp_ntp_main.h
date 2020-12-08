/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  Vapp_ntp_main.h
 *
 * Project:
 * --------
 *  MAUI
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
 *----------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_NTP_MAIN_H__
#define __VAPP_NTP_MAIN_H__

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_loading_popup.h"

#if defined(__MMI_MAINLCD_240X320__)
    #define NTP_LOADING_W (35)
    #define NTP_LOADING_Y (60)

    /////////////////// Atomic time //////////////////////
    #define ATOMIC_MOVE_UP      11

    // atomic background frame
    #define ATOMIC_LB_BG_X      5
    #define ATOMIC_LB_BG_Y      (6 + ATOMIC_MOVE_UP)
    #define ATOMIC_LB_BG_H      (ATOMIC_DT_Y + ATOMIC_DT_H + 8)
    #define ATOMIC_LB_FAIL_BG_H (BTN_SET_Y + BTN_SET_H + 8)

    // atomic lable
    #define ATOMIC_LB_Y     4
    #define ATOMIC_LB_SIZE  13

    // atomic time zone
    #define ATOMIC_TZ_Y     31
    #define ATOMIC_TZ_SIZE  13

    // atomic hour min sec
    #define ATOMIC_HM_X     41
    #define ATOMIC_HM_Y     (ATOMIC_TZ_Y + ATOMIC_TZ_H + 3)
    #define ATOMIC_HM_SIZE  30

    // atomic millisec
    #define ATOMIC_MS_X     162
    #define ATOMIC_MS_Y     (ATOMIC_HM_Y + 6)
    #define ATOMIC_MS_SIZE  22

    // atomic date
    #define ATOMIC_DT_Y     (ATOMIC_HM_Y + ATOMIC_HM_H + 3)
    #define ATOMIC_DT_SIZE  13

    // fail infomation
    #define FAIL_INFO_Y     28
    #define FAIL_INFO_SIZE  14

    #define BTN_FONT_SIZE   16

    // retry updating button
    #define BTN_UPDATE_X    5
    #define BTN_UPDATE_Y    (FAIL_INFO_Y + FAIL_INFO_H + 4)
    #define BTN_UPDATE_W    (LCD_WIDTH - 5*2 - 5 - 4)
    #define BTN_UPDATE_H    40

    // date account setting button
    #define BTN_SET_Y       (BTN_UPDATE_Y + BTN_UPDATE_H + 4)

    /////////////////// System time //////////////////////
    #define SYSTEM_MOVE_DOWN 17

    // system background frame
    #define SYSTEM_LB_BG_Y  (ATOMIC_LB_BG_Y + ATOMIC_LB_BG_H + 13)
    #define SYSTEM_LB_BG_H  (SYSTEM_DT_Y + SYSTEM_DT_H + 7)

    // system hour min
    #define SYSTEM_HM_X     57
    #define SYSTEM_HM_Y     (SYSTEM_TZ_Y + SYSTEM_TZ_H + 3)

    // system date
    #define SYSTEM_DT_Y     (SYSTEM_HM_Y + SYSTEM_HM_H + 3)

#elif defined(__MMI_MAINLCD_240X400__)
    #define NTP_LOADING_W (35)
    #define NTP_LOADING_Y (90)

    /////////////////// Atomic time //////////////////////
    #define ATOMIC_MOVE_UP      15

    // atomic background frame
    #define ATOMIC_LB_BG_X      5
    #define ATOMIC_LB_BG_Y      (16 + ATOMIC_MOVE_UP)
    #define ATOMIC_LB_BG_H      (ATOMIC_DT_Y + ATOMIC_DT_H + 13)
    #define ATOMIC_LB_FAIL_BG_H (BTN_SET_Y + BTN_SET_H + 13)

    // atomic lable
    #define ATOMIC_LB_Y     4
    #define ATOMIC_LB_SIZE  13

    // atomic time zone
    #define ATOMIC_TZ_Y     31
    #define ATOMIC_TZ_SIZE  13

    // atomic hour min sec
    #define ATOMIC_HM_X     44
    #define ATOMIC_HM_Y     (ATOMIC_TZ_Y + ATOMIC_TZ_H + 5)
    #define ATOMIC_HM_SIZE  35

    // atomic millisec
    #define ATOMIC_MS_X     176
    #define ATOMIC_MS_Y     (ATOMIC_HM_Y + 8)
    #define ATOMIC_MS_SIZE  25

    // atomic date
    #define ATOMIC_DT_Y     (ATOMIC_HM_Y + ATOMIC_HM_H + 5)
    #define ATOMIC_DT_SIZE  13

    // fail infomation
    #define FAIL_INFO_Y     31
    #define FAIL_INFO_SIZE  14

    #define BTN_FONT_SIZE   16

    // retry updating button
    #define BTN_UPDATE_X    5
    #define BTN_UPDATE_Y    (FAIL_INFO_Y + FAIL_INFO_H + 8)
    #define BTN_UPDATE_W    (LCD_WIDTH - 5*2 - 5 - 4)
    #define BTN_UPDATE_H    40

    // date account setting button
    #define BTN_SET_Y       (BTN_UPDATE_Y + BTN_UPDATE_H + 5)

    /////////////////// System time //////////////////////
    #define SYSTEM_MOVE_DOWN 22

    // system background frame
    #define SYSTEM_LB_BG_Y  (ATOMIC_LB_BG_Y + ATOMIC_LB_BG_H + 30)
    #define SYSTEM_LB_BG_H  (SYSTEM_DT_Y + SYSTEM_DT_H + 13)

    // system hour min
    #define SYSTEM_HM_X     50
    #define SYSTEM_HM_Y     (SYSTEM_TZ_Y + SYSTEM_TZ_H + 5)

    // system date
    #define SYSTEM_DT_Y     (SYSTEM_HM_Y + SYSTEM_HM_H + 5)

#elif defined(__MMI_MAINLCD_320X480__)
    #define NTP_LOADING_W (40)
    #define NTP_LOADING_Y (110)

    /////////////////// Atomic time //////////////////////
    #define ATOMIC_MOVE_UP      20

    // atomic background frame
    #define ATOMIC_LB_BG_X      10
    #define ATOMIC_LB_BG_Y      (18 + ATOMIC_MOVE_UP)
    #define ATOMIC_LB_BG_H      (ATOMIC_DT_Y + ATOMIC_DT_H + 16)
    #define ATOMIC_LB_FAIL_BG_H (BTN_SET_Y + BTN_SET_H + 16)

    // atomic lable
    #define ATOMIC_LB_Y     4
    #define ATOMIC_LB_SIZE  18

    // atomic time zone
    #define ATOMIC_TZ_Y     40
    #define ATOMIC_TZ_SIZE  18

    // atomic hour min sec
    #define ATOMIC_HM_X     53
    #define ATOMIC_HM_Y     (ATOMIC_TZ_Y + ATOMIC_TZ_H + 10)
    #define ATOMIC_HM_SIZE  45

    // atomic millisec
    #define ATOMIC_MS_X     225
    #define ATOMIC_MS_Y     (ATOMIC_HM_Y + 8)
    #define ATOMIC_MS_SIZE  35

    // atomic date
    #define ATOMIC_DT_Y     (ATOMIC_HM_Y + ATOMIC_HM_H + 10)
    #define ATOMIC_DT_SIZE  18

    // fail infomation
    #define FAIL_INFO_Y     40
    #define FAIL_INFO_SIZE  18

    #define BTN_FONT_SIZE   18

    // retry updating button
    #define BTN_UPDATE_X    11
    #define BTN_UPDATE_Y    (FAIL_INFO_Y + FAIL_INFO_H + 14)
    #define BTN_UPDATE_W    (LCD_WIDTH - 10*2 - 11 - 10)
    #define BTN_UPDATE_H    45

    // date account setting button
    #define BTN_SET_Y       (BTN_UPDATE_Y + BTN_UPDATE_H + 7)

    /////////////////// System time //////////////////////
    #define SYSTEM_MOVE_DOWN 25

    // system background frame
    #define SYSTEM_LB_BG_Y  (ATOMIC_LB_BG_Y + ATOMIC_LB_BG_H + 14)
    #define SYSTEM_LB_BG_H  (SYSTEM_DT_Y + SYSTEM_DT_H + 16)

    // system hour min
    #define SYSTEM_HM_X     65
    #define SYSTEM_HM_Y     (SYSTEM_TZ_Y + SYSTEM_TZ_H + 10)

    // system date
    #define SYSTEM_DT_Y     (SYSTEM_HM_Y + SYSTEM_HM_H + 10)

#elif defined(__MMI_MAINLCD_480X800__)

    #define NTP_LOADING_W (50)
    #define NTP_LOADING_Y (200)

    /////////////////// Atomic time //////////////////////
    #define ATOMIC_MOVE_UP      50

    // atomic background frame
    #define ATOMIC_LB_BG_X      12
    #define ATOMIC_LB_BG_Y      (31 + ATOMIC_MOVE_UP)
    #define ATOMIC_LB_BG_H      (ATOMIC_DT_Y + ATOMIC_DT_H + 24)
    #define ATOMIC_LB_FAIL_BG_H (BTN_SET_Y + BTN_SET_H + 24)

    // atomic lable
    #define ATOMIC_LB_Y     10
    #define ATOMIC_LB_SIZE  23

    // atomic time zone
    #define ATOMIC_TZ_Y     64
    #define ATOMIC_TZ_SIZE  23

    // atomic hour min sec
    #define ATOMIC_HM_X     76
    #define ATOMIC_HM_Y     (ATOMIC_TZ_Y + ATOMIC_TZ_H + 15)
    #define ATOMIC_HM_SIZE  70

    // atomic millisec
    #define ATOMIC_MS_X     345
    #define ATOMIC_MS_Y     (ATOMIC_HM_Y + 20)
    #define ATOMIC_MS_SIZE  45

    // atomic date
    #define ATOMIC_DT_Y     (ATOMIC_HM_Y + ATOMIC_HM_H + 15)
    #define ATOMIC_DT_SIZE  23

    // fail infomation
    #define FAIL_INFO_Y     70
    #define FAIL_INFO_SIZE  30

    #define BTN_FONT_SIZE   30

    // retry updating button
    #define BTN_UPDATE_X    23
    #define BTN_UPDATE_Y    (FAIL_INFO_Y + FAIL_INFO_H + 24)
    #define BTN_UPDATE_W    (LCD_WIDTH - 12*2 - 23 - 19)
    #define BTN_UPDATE_H    80

    // date account setting button
    #define BTN_SET_Y       (BTN_UPDATE_Y + BTN_UPDATE_H + 14)

    /////////////////// System time //////////////////////
    #define SYSTEM_MOVE_DOWN 70

    // system background frame
    #define SYSTEM_LB_BG_Y  (ATOMIC_LB_BG_Y + ATOMIC_LB_BG_H + 30)
    #define SYSTEM_LB_BG_H  (SYSTEM_DT_Y + SYSTEM_DT_H + 24)

    // system hour min
    #define SYSTEM_HM_X     92
    #define SYSTEM_HM_Y     (SYSTEM_TZ_Y + SYSTEM_TZ_H + 15)

    // system date
    #define SYSTEM_DT_Y     (SYSTEM_HM_Y + SYSTEM_HM_H + 15)
#endif

#define NTP_LOADING_X ((LCD_WIDTH - NTP_LOADING_W)/2)
#define NTP_LOADING_H (NTP_LOADING_W)

#define NTP_COLOR_80 VRT_COLOR_MAKE(255,80,80,80)

#define ATOMIC_LB_X     (LCD_WIDTH/2 - ATOMIC_LB_BG_X)
#define ATOMIC_TZ_X     (LCD_WIDTH/2 - ATOMIC_LB_BG_X)
#define ATOMIC_DT_X     (LCD_WIDTH/2 - ATOMIC_LB_BG_X)
#define FAIL_INFO_X     (LCD_WIDTH/2 - ATOMIC_LB_BG_X)
#define SYSTEM_LB_X     (LCD_WIDTH/2 - ATOMIC_LB_BG_X)
#define SYSTEM_TZ_X     (LCD_WIDTH/2 - ATOMIC_LB_BG_X)
#define SYSTEM_DT_X     (LCD_WIDTH/2 - ATOMIC_LB_BG_X)
#define ATOMIC_LB_BG_W  (LCD_WIDTH - ATOMIC_LB_BG_X * 2)
#define ATOMIC_TZ_H     ATOMIC_TZ_SIZE
#define ATOMIC_HM_H     ATOMIC_HM_SIZE
#define ATOMIC_DT_H     ATOMIC_DT_SIZE

#ifdef __MMI_MAINLCD_240X320__
#define FAIL_INFO_H     (FAIL_INFO_SIZE)
#else
#define FAIL_INFO_H     (FAIL_INFO_SIZE * 2)
#endif
#define FAIL_INFO_W     BTN_UPDATE_W
#define BTN_SET_X       BTN_UPDATE_X
#define BTN_SET_W       BTN_UPDATE_W
#define BTN_SET_H       BTN_UPDATE_H

// system lable
#define SYSTEM_LB_Y     ATOMIC_LB_Y
#define SYSTEM_LB_SIZE  ATOMIC_LB_SIZE
#define SYSTEM_LB_BG_X  ATOMIC_LB_BG_X
#define SYSTEM_LB_BG_W  (LCD_WIDTH - SYSTEM_LB_BG_X * 2)

// system time zone
#define SYSTEM_TZ_Y     ATOMIC_TZ_Y
#define SYSTEM_TZ_SIZE  ATOMIC_TZ_SIZE
#define SYSTEM_TZ_H     SYSTEM_TZ_SIZE
#define SYSTEM_HM_SIZE  ATOMIC_HM_SIZE
#define SYSTEM_DT_SIZE  ATOMIC_DT_SIZE
#define SYSTEM_HM_H     SYSTEM_HM_SIZE
#define SYSTEM_DT_H     SYSTEM_DT_SIZE

/*****************************************************************************
 * Class
 *****************************************************************************/
class VappNtpTextView : public VfxTextFrame
{
    VFX_DECLARE_CLASS(VappNtpTextView);

public:
    virtual void onInit();
    void set(VfxU32 x,
             VfxU32 y,
             VfxBool center,
             VfxBool bold,
             const VfxWString & text,
             VfxU32 fontSize,
             const VfxColor &color,
             VfxFontDescEffectEnum effect = VFX_FONT_DESC_EFFECT_NONE);
};

class VappNtpMainPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappNtpMainPage);

public:
    VappNtpMainPage();
   ~VappNtpMainPage();
    virtual void onInit();
    virtual mmi_ret onProc(mmi_event_struct* evt);

    enum VappNtpStateEnum
    {
        WAITING,
        GET_RESULT_SUCC,
        GET_RESULT_FAIL,
    };
private:
    void onToolBarClick(VfxObject *obj, VfxId id);
    void onSystemTimeChanged(VfxU32 flag);
    void onTimerTick(VfxTimer *source);
    void onBtnClick(VfxObject*, VfxId);

    void updateSysTime();
    void updateAtomicTime();
    void updateAtomicMilliSec();
    void updateFrameState(VappNtpStateEnum state);

    void resetTimer(VfxTimer **timer);

    static void onProcSrvRes(S32 result, S64 offset, void *userdata);
    static void onProcTimeSet(MMI_BOOL result, void *userdata);
private:
    VcpToolBar *toolBar;

    VfxFrame *atomicArea;
    VfxFrame *systemArea;

    VappNtpTextView *atomic_lb;
    VappNtpTextView *atomic_tz;
    VappNtpTextView *atomic_hm;
    VappNtpTextView *atomic_ms;
    VappNtpTextView *atomic_dt;

    VappNtpTextView *system_lb;
    VappNtpTextView *system_tz;
    VappNtpTextView *system_hm;
    VappNtpTextView *system_dt;

    VfxTimer        *timerSec;
    VfxTimer        *timerMilliSec;
    VfxTimer        *timerSyncTimeOut;
    VfxDateTime     *startSysTime;
    VcpActivityIndicator *loading;

    VcpFrameEffect *effectFront;

    /* case Fail */
    VappNtpTextView *failNotify;
    VcpButton *updateBtn;
    VcpButton *settingBtn;

    VfxWString tzStr;
    S64 offset;
    U64 currAtomicUTC;
    U32 startTick;

    /* for user clicking SYNC */
    U32 startSyncTicks;
    U32 startSyncSec;

    
    mmi_id dtcntCuiId;

    VfxBool haveSentSyncCmd;
};

#endif  /* __VAPP_NTP_MAIN_H__ */

