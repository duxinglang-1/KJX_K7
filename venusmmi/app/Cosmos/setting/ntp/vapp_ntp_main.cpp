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
 *  Vapp_ntp_main.cpp
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "vapp_ntp_gprot.h"
#include "vapp_ntp_main.h"
#include "mmi_rp_vapp_setting_def.h"
#include "vdat_systime.h"
#include "vapp_dtcnt_gprot.h"
#include "vcui_dtcnt_select_gprot.h"
#include "mmi_conn_app_trc.h"

extern "C"{
#include "NtpSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGProt.h"
#include "custom_ntp_config.h"
}

/*****************************************************************************
 * VappNtpLaunchCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappNtpLaunchCell",
                    VappNtpLaunchCell,
                    VcpFormItemSwitchCell);
void VappNtpLaunchCell::onInit()
{
/*  setIsTappable(VFX_TRUE);
    VcpFormItemLauncherCell::onInit();
    setMainText(VFX_WSTR_RES(STR_ID_VAPP_SETTING_NTP_TIME_AUTO_UPDATE));
    setAccessory(VCPFORM_NEXT_ITEM_ICON);
*/
    
    VcpFormItemSwitchCell::onInit();

    setMainText(VFX_WSTR_RES(STR_ID_VAPP_SETTING_NTP_TIME_AUTO_UPDATE));
    m_signalSwitchChangeReq.connect(this, &VappNtpLaunchCell::onSwitch);

    setIsTappable(srv_ntp_availability_get() == MMI_TRUE);
    setSwitchStatus(srv_ntp_availability_get() == MMI_TRUE);
}

void VappNtpLaunchCell::onSwitch(VcpFormItemSwitchCell* sender,
                                 VfxId id, VfxBool status)
{
    srv_ntp_availability_set(status ? MMI_TRUE : MMI_FALSE);
    setIsTappable(status);
    setSwitchStatus(status);
}

void VappNtpLaunchCell::onCellTap(VfxPenEvent & event)
{
    //VcpFormItemLauncherCell::onCellTap(event);
    VcpFormItemSwitchCell::onCellTap(event);

    if(!srv_ntp_availability_get())
    {
    	return;
    }

#if defined(__MMI_OP01_WIFI__) && defined(__FLIGHT_MODE_SUPPORT__)
    if (srv_mode_switch_is_network_service_available() == MMI_FALSE)
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_INFO, 
            (WCHAR*)GetString(STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE));
        return;
    }
#endif

    if (srv_ntp_is_background_sync_running())
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_INFO, 
            (WCHAR*)GetString(STR_ID_VAPP_SETTING_NTP_SYNCING_BACKGROUND));
        return;
    }

    if(event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        VappNtpMainPage *page;
        VfxMainScr *mainScr = (VfxMainScr*)((VfxPage*)getParent())->findScreen();

        VFX_OBJ_CREATE(page, VappNtpMainPage, mainScr);
        mainScr->pushPage(0, page);
    }
}

/*****************************************************************************
 * VappNtpTextView
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappNtpTextView", VappNtpTextView, VfxTextFrame);
void VappNtpTextView::onInit()
{
    VfxTextFrame::onInit();
}

void VappNtpTextView::set(VfxU32 x,
                          VfxU32 y,
                          VfxBool center,
                          VfxBool bold,
                          const VfxWString & text,
                          VfxU32 fontSize,
                          const VfxColor &color,
                          VfxFontDescEffectEnum effect)
{
    setString(text);
    setPos(VfxPoint(x, y));

    if (center)
    {
        setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        setAnchor(0.5f, 0.0f);
    }
    else
    {
        setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    }

    VfxFontDesc font;
    font.size = VFX_FONT_DESC_VF_SIZE(fontSize);
    font.effect |= effect;
    setFont(font);
    setColor(color);
}


/*****************************************************************************
 * VappNtpMainPage, the main page of NTP
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappNtpMainPage", VappNtpMainPage, VfxPage);
VappNtpMainPage::VappNtpMainPage() :
    timerSec(NULL),
    timerMilliSec(NULL),
    timerSyncTimeOut(NULL),
    tzStr(VFX_WSTR_NULL),
    haveSentSyncCmd(VFX_FALSE)
{
}

VappNtpMainPage::~VappNtpMainPage()
{
    srv_ntp_abort();
}

void VappNtpMainPage::onInit()
{
    VfxPage::onInit();

    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
    toolBar->m_signalButtonTap.connect(this, &VappNtpMainPage::onToolBarClick);
    toolBar->addItem('SYNC',
                     VFX_WSTR_RES(STR_ID_VAPP_SETTING_NTP_SYNC_SYSTEM_TIME),
                     IMG_ID_VAPP_NTP_TOOLBAR_SYNC);
    toolBar->setDisableItem('SYNC', VFX_TRUE);
    setBottomBar(toolBar);

    VfxFrame *bgFrame;
    VFX_OBJ_CREATE(bgFrame, VfxFrame, this);
    bgFrame->setPos(0, 0);
    bgFrame->setSize(getSize().width, getSize().height);
    bgFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_NTP_PAGE_BG));
    bgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    // Atomic area
    VFX_OBJ_CREATE(atomicArea, VfxFrame, this);
    atomicArea->setPos(ATOMIC_LB_BG_X, ATOMIC_LB_BG_Y);
    atomicArea->setSize(ATOMIC_LB_BG_W, ATOMIC_LB_BG_H);
    atomicArea->setImgContent(VfxImageSrc(IMG_ID_VAPP_NTP_TAB_BG));
    atomicArea->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    atomicArea->setAutoAnimate(VFX_TRUE);

    // System area
    VFX_OBJ_CREATE(systemArea, VfxFrame, this);
    systemArea->setPos(SYSTEM_LB_BG_X, SYSTEM_LB_BG_Y);
    systemArea->setSize(SYSTEM_LB_BG_W, SYSTEM_LB_BG_H);
    systemArea->setImgContent(VfxImageSrc(IMG_ID_VAPP_NTP_TAB_BG));
    systemArea->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    systemArea->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(atomic_lb, VappNtpTextView, atomicArea);
    atomic_lb->set(ATOMIC_LB_X, ATOMIC_LB_Y, VFX_TRUE, VFX_TRUE, VFX_WSTR_RES(STR_ID_VAPP_SETTING_NTP_ATOMIC_CLOCK), ATOMIC_LB_SIZE, VFX_COLOR_WHITE, VFX_FE1_9);

    VFX_OBJ_CREATE(atomic_tz, VappNtpTextView, atomicArea);
    atomic_tz->set(ATOMIC_TZ_X, ATOMIC_TZ_Y, VFX_TRUE, VFX_FALSE, VFX_WSTR(""), ATOMIC_TZ_SIZE, NTP_COLOR_80);

    VFX_OBJ_CREATE(atomic_hm, VappNtpTextView, atomicArea);
    atomic_hm->set(ATOMIC_HM_X, ATOMIC_HM_Y, VFX_FALSE, VFX_TRUE, VFX_WSTR(""), ATOMIC_HM_SIZE, VFX_COLOR_BLACK);

    VFX_OBJ_CREATE(atomic_ms, VappNtpTextView, atomicArea);
    atomic_ms->set(ATOMIC_MS_X, ATOMIC_MS_Y, VFX_FALSE, VFX_TRUE, VFX_WSTR(""), ATOMIC_MS_SIZE, VFX_COLOR_BLACK);

    VFX_OBJ_CREATE(atomic_dt, VappNtpTextView, atomicArea);
    atomic_dt->set(ATOMIC_DT_X, ATOMIC_DT_Y, VFX_TRUE, VFX_FALSE, VFX_WSTR(""), ATOMIC_DT_SIZE, NTP_COLOR_80);

    VFX_OBJ_CREATE(system_lb, VappNtpTextView, systemArea);
    system_lb->set(SYSTEM_LB_X, SYSTEM_LB_Y, VFX_TRUE, VFX_TRUE, VFX_WSTR_RES(STR_ID_VAPP_SETTING_NTP_SYSTEM_TIME), SYSTEM_LB_SIZE, VFX_COLOR_WHITE, VFX_FE1_9);

    VFX_OBJ_CREATE(system_tz, VappNtpTextView, systemArea);
    system_tz->set(SYSTEM_TZ_X, SYSTEM_TZ_Y, VFX_TRUE, VFX_FALSE, VFX_WSTR(""), SYSTEM_TZ_SIZE, NTP_COLOR_80);

    VFX_OBJ_CREATE(system_hm, VappNtpTextView, systemArea);
    system_hm->set(SYSTEM_HM_X, SYSTEM_HM_Y, VFX_FALSE, VFX_TRUE, VFX_WSTR(""), SYSTEM_HM_SIZE, VFX_COLOR_BLACK);

    VFX_OBJ_CREATE(system_dt, VappNtpTextView, systemArea);
    system_dt->set(SYSTEM_DT_X, SYSTEM_DT_Y, VFX_TRUE, VFX_FALSE, VFX_WSTR(""), SYSTEM_DT_SIZE, NTP_COLOR_80);

    VFX_OBJ_CREATE(failNotify, VappNtpTextView, atomicArea);
    failNotify->set(FAIL_INFO_X, FAIL_INFO_Y, VFX_TRUE, VFX_FALSE,
#ifdef __MMI_MAINLCD_240X320__
        VFX_WSTR_RES(STR_ID_VAPP_SETTING_NTP_FAIL_INFO_SLIM),
#else
        VFX_WSTR_RES(STR_ID_VAPP_SETTING_NTP_FAIL_INFO),
#endif
        FAIL_INFO_SIZE, NTP_COLOR_80);
    failNotify->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    failNotify->setSize(FAIL_INFO_W, FAIL_INFO_H);

    VfxFontDesc btnFont(VFX_FONT_DESC_VF_SIZE(BTN_FONT_SIZE), VFX_FE1_4);

    VFX_OBJ_CREATE(updateBtn, VcpButton, atomicArea);
    updateBtn->setText(VFX_WSTR_RES(STR_ID_VAPP_SETTING_NTP_PRESS_TO_UPDATE));
    updateBtn->setTextFont(btnFont);
    updateBtn->setRect(BTN_UPDATE_X, BTN_UPDATE_Y, BTN_UPDATE_W, BTN_UPDATE_H);
    updateBtn->m_signalClicked.connect(this, &VappNtpMainPage::onBtnClick);

    VFX_OBJ_CREATE(settingBtn, VcpButton, atomicArea);
    settingBtn->setText(VFX_WSTR_RES(STR_GLOBAL_DATA_CONN_SETTING));
    updateBtn->setTextFont(btnFont);
    settingBtn->setRect(BTN_SET_X, BTN_SET_Y, BTN_SET_W, BTN_SET_H);
    settingBtn->m_signalClicked.connect(this, &VappNtpMainPage::onBtnClick);
    if (!srv_sim_ctrl_any_sim_is_available())
    {
        // disable data account item
        settingBtn->setIsDisabled(VFX_TRUE);
    }

    // connect to Minutes change signal
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappNtpMainPage::onSystemTimeChanged);

    // create seconds change timer
    resetTimer(&timerSec);
    updateSysTime();

    // anyway, create loading icon
    VFX_OBJ_CREATE(loading, VcpActivityIndicator, this);
    loading->setSize(NTP_LOADING_W, NTP_LOADING_H);
    loading->setPos(NTP_LOADING_X, NTP_LOADING_Y);

    // call service to get time from network
    S32 ret;
    ret = srv_ntp_sync(&VappNtpMainPage::onProcSrvRes, (void*)this);
    if (ret != 0)
    {
        updateFrameState(GET_RESULT_FAIL);
        return;
    }

    VFX_OBJ_CREATE(timerSyncTimeOut, VfxTimer, this);
    timerSyncTimeOut->setStartDelay(APP_NTP_SYNC_TIME_OUT * 1000);
    timerSyncTimeOut->setDuration(APP_NTP_SYNC_TIME_OUT * 1000);
    timerSyncTimeOut->m_signalTick.connect(this, &VappNtpMainPage::onTimerTick);
    timerSyncTimeOut->start();

    updateFrameState(WAITING);

    loading->start();
}

// update atomic time
void VappNtpMainPage::updateAtomicTime()
{
    applib_time_struct t;
    U32 utcSec;
    S64 ticksOffset = 0;

    if (haveSentSyncCmd)
    {
        U32 currTicks = 0;
        ticksOffset = offset;
        kal_get_time(&currTicks);
        utcSec = startSyncSec;
        ticksOffset += (U32)((double)(currTicks - startSyncTicks) * KAL_MILLISECS_PER_TICK);
        utcSec += (S32)(ticksOffset/1000);
    }
    else
    {
        applib_dt_get_rtc_time(&t);
        utcSec = applib_dt_mytime_2_utc_sec(&t, MMI_FALSE);
        utcSec += (U32)(offset/1000);
    }

    if (utcSec == currAtomicUTC)
    {
        // times are the same, no need to update
        return;
    }

    currAtomicUTC = utcSec;
    applib_dt_utc_sec_2_mytime((U32)utcSec, &t, MMI_FALSE);

    VfxDateTime dateTime;
    dateTime.setDateTime(&t);

    // atomic date
    atomic_dt->setString(dateTime.getDateTimeString(
                                VFX_DATE_TIME_DATE_YEAR |
                                VFX_DATE_TIME_DATE_MONTH |
                                VFX_DATE_TIME_DATE_DAY));

    // atomic time
    VfxWString time;
    time.format("%02d:%02d:%02d", t.nHour, t.nMin, t.nSec);
    atomic_hm->setString(time);
}

// update atomic time's millisecond
void VappNtpMainPage::updateAtomicMilliSec()
{
    U32 currTick;
    U32 milliSec = offset % 1000;

    kal_get_time(&currTick);
    milliSec += (U32)((double)(currTick - startTick) * KAL_MILLISECS_PER_TICK);
    milliSec %= 1000;
    milliSec /= 100;

    VfxWString milliSecStr;
    milliSecStr.format(".%d", milliSec);
    atomic_ms->setString(milliSecStr);
}

// update system time
void VappNtpMainPage::updateSysTime()
{
    applib_time_struct t;
    applib_dt_get_rtc_time(&t);

    VfxDateTime dateTime;
    dateTime.setCurrentTime();

    // system date
    system_dt->setString(dateTime.getDateTimeString(
                                VFX_DATE_TIME_DATE_YEAR |
                                VFX_DATE_TIME_DATE_MONTH |
                                VFX_DATE_TIME_DATE_DAY));

    // system time
    VfxWString time;
    time.format("%02d:%02d:%02d", t.nHour, t.nMin, t.nSec);
    system_hm->setString(time);

    if (tzStr.isEmpty())
    {
        // time zone
        VfxChar tz[16];
        applib_dt_get_tz_string(tz);

        VfxU32 zhours = (tz[1] - '0') * 10 + (tz[2] - '0');
        VfxU32 zminutes = ((tz[3] - '0') * 10 + (tz[4] - '0')) * 10 / 6;

        if (zhours == 0 && zminutes == 0)
        {
            tz[0] = ' ';
        }

        if (zminutes != 0)
        {
            if (zminutes % 10 == 0)
            {
                zminutes /= 10;
            }
            tzStr.format("GMT%c%d.%d", tz[0], zhours, zminutes);
        }
        else
        {
            tzStr.format("GMT%c%d", tz[0], zhours);
        }
        system_tz->setString(tzStr);
    }
}

// change frame state, hide/show, change position
void VappNtpMainPage::updateFrameState(VappNtpStateEnum state)
{
    if (state == GET_RESULT_FAIL)
    {
        atomic_tz->setHidden(VFX_TRUE);
        atomic_hm->setHidden(VFX_TRUE);
        atomic_ms->setHidden(VFX_TRUE);
        atomic_dt->setHidden(VFX_TRUE);
        failNotify->setHidden(VFX_FALSE);
        updateBtn->setHidden(VFX_FALSE);
        settingBtn->setHidden(VFX_FALSE);
        toolBar->setDisableItem('SYNC', VFX_TRUE);
    }
    else if (state == GET_RESULT_SUCC)
    {
        atomic_tz->setHidden(VFX_FALSE);
        atomic_hm->setHidden(VFX_FALSE);
        atomic_ms->setHidden(VFX_FALSE);
        atomic_dt->setHidden(VFX_FALSE);
        failNotify->setHidden(VFX_TRUE);
        updateBtn->setHidden(VFX_TRUE);
        settingBtn->setHidden(VFX_TRUE);

        toolBar->setDisableItem('SYNC', VFX_FALSE);
    }
    else if (state == WAITING)
    {
        atomic_tz->setHidden(VFX_TRUE);
        atomic_hm->setHidden(VFX_TRUE);
        atomic_ms->setHidden(VFX_TRUE);
        atomic_dt->setHidden(VFX_TRUE);
        failNotify->setHidden(VFX_TRUE);
        updateBtn->setHidden(VFX_TRUE);
        settingBtn->setHidden(VFX_TRUE);
        toolBar->setDisableItem('SYNC', VFX_TRUE);
    }

    VfxAutoAnimate::initAnimateBegin();
    if (state == GET_RESULT_FAIL)
    {
        atomicArea->setSize(ATOMIC_LB_BG_W, ATOMIC_LB_FAIL_BG_H);
        atomicArea->setPos(VfxPoint(ATOMIC_LB_BG_X, ATOMIC_LB_BG_Y - ATOMIC_MOVE_UP));
        systemArea->setPos(VfxPoint(SYSTEM_LB_BG_X, SYSTEM_LB_BG_Y + SYSTEM_MOVE_DOWN));
    }
    else if (state == GET_RESULT_SUCC)
    {
        atomicArea->setSize(ATOMIC_LB_BG_W, ATOMIC_LB_BG_H);
        atomicArea->setPos(VfxPoint(ATOMIC_LB_BG_X, ATOMIC_LB_BG_Y));
        systemArea->setPos(VfxPoint(SYSTEM_LB_BG_X, SYSTEM_LB_BG_Y));
    }
    else if (state == WAITING)
    {
        atomicArea->setSize(ATOMIC_LB_BG_W, ATOMIC_LB_BG_H);
        atomicArea->setPos(VfxPoint(ATOMIC_LB_BG_X, ATOMIC_LB_BG_Y));
        systemArea->setPos(VfxPoint(SYSTEM_LB_BG_X, SYSTEM_LB_BG_Y));
    }
    VfxAutoAnimate::initAnimateEnd();
}

// reset timer
void VappNtpMainPage::resetTimer(VfxTimer **timer)
{
    if (timer == &timerMilliSec)
    {
        if (timerMilliSec != NULL)
        {
            VFX_OBJ_CLOSE(timerMilliSec);
        }

        VFX_OBJ_CREATE(timerMilliSec, VfxTimer, this);
        timerMilliSec->setStartDelay(50);
        timerMilliSec->setDuration(50);
        timerMilliSec->m_signalTick.connect(this, &VappNtpMainPage::onTimerTick);
        timerMilliSec->start();

        kal_get_time(&startTick);
    }
    else if (timer == &timerSec)
    {
        if (timerSec != NULL)
        {
            VFX_OBJ_CLOSE(timerSec);
        }

        VFX_OBJ_CREATE(timerSec, VfxTimer, this);
        timerSec->setStartDelay(1000);
        timerSec->setDuration(1000);
        timerSec->m_signalTick.connect(this, &VappNtpMainPage::onTimerTick);
        timerSec->start();
    }
}

// getting time from NTP service proc
void VappNtpMainPage::onProcSrvRes(S32 result, S64 offset, void *userdata)
{
    VappNtpMainPage* page;
    page = VFX_OBJ_DYNAMIC_CAST((VappNtpMainPage*)userdata, VappNtpMainPage);

    if (page == NULL || !page->isValid())
    {
        return;
    }

    if (page->timerSyncTimeOut != NULL)
    {
        VFX_OBJ_CLOSE(page->timerSyncTimeOut);
    }

    page->loading->stop();
    page->offset = offset;

    if (result == 0)
    {
        // sucess
        page->updateFrameState(GET_RESULT_SUCC);
        page->atomic_tz->setString(page->tzStr);
        page->resetTimer(&page->timerMilliSec);
        page->updateAtomicTime();
        page->updateAtomicMilliSec();
    }
    else
    {
        // fail
        page->updateFrameState(GET_RESULT_FAIL);
    }
}

// setting time to phone proc
void VappNtpMainPage::onProcTimeSet(MMI_BOOL result, void *userdata)
{
    VappNtpMainPage* page;
    page = VFX_OBJ_DYNAMIC_CAST((VappNtpMainPage*)userdata, VappNtpMainPage);

    if (page == NULL)
    {
        return;
    }

    if (result)
    {
        return;
    }
    
    // if failed to set date time to phone, enable toolBar, and show popup
    page->toolBar->setDisableItem('SYNC', VFX_FALSE);

    VcpConfirmPopup *confirm;
    VFX_OBJ_CREATE(confirm, VcpConfirmPopup, page->findScreen());
    confirm->setInfoType(VCP_POPUP_TYPE_FAILURE);
    confirm->setText(VFX_WSTR_RES(STR_GLOBAL_FAILED));
    confirm->setAutoDestory(VFX_TRUE);
    confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    confirm->show(VFX_TRUE);
}

/* when system changed, this function will be executed. */
void VappNtpMainPage::onSystemTimeChanged(VfxU32 flag)
{
    if (haveSentSyncCmd)
    {
        offset = 0;
        haveSentSyncCmd = VFX_FALSE;
        startSyncSec = 0;
    }

    if (flag & VDAT_SYSTIME_CHANGED_YEAR)
    {
        applib_time_struct t;
        applib_dt_get_rtc_time(&t);
        if (t.nYear == DT_MIN_YEAR)
        {
            offset = 0;
        }
    }

    if (offset == 0)
    {
        resetTimer(&timerMilliSec);
        updateAtomicTime();
        updateAtomicMilliSec();
    }

    updateSysTime();
    resetTimer(&timerSec);
}

// timer expiry proc
void VappNtpMainPage::onTimerTick(VfxTimer *source)
{
    if (source == timerSec)
    {
        updateSysTime();
        if (offset == 0)
        {
            updateAtomicTime();
        }
    }
    else if (source == timerMilliSec)
    {
        if (offset != 0)
        {
            updateAtomicTime();
        }
        updateAtomicMilliSec();
    }
    else if (source == timerSyncTimeOut)
    {
        VFX_OBJ_CLOSE(timerSyncTimeOut);
        srv_ntp_abort();
        onProcSrvRes(-1, 0, (void*)(this));
    }
}

// toolbar clicking proc
void VappNtpMainPage::onToolBarClick(VfxObject *obj, VfxId id)
{
    if (id == 'SYNC')
    {
        haveSentSyncCmd = VFX_TRUE;

        applib_time_struct t;
        applib_dt_get_rtc_time(&t);

        startSyncSec = applib_dt_mytime_2_utc_sec(&t, MMI_FALSE);
        kal_get_time(&startSyncTicks);

        srv_ntp_update_time_to_phone(offset, &VappNtpMainPage::onProcTimeSet, this);

        toolBar->setDisableItem('SYNC', VFX_TRUE);
    }
}

// update/data account button clicking proc
void VappNtpMainPage::onBtnClick(VfxObject* sender, VfxId)
{
    if (sender == updateBtn)
    {
        // try again
        updateFrameState(WAITING);
        loading->start();
        srv_ntp_sync(&VappNtpMainPage::onProcSrvRes, (void*)this);

        VFX_OBJ_CREATE(timerSyncTimeOut, VfxTimer, this);
        timerSyncTimeOut->setStartDelay(APP_NTP_SYNC_TIME_OUT * 1000);
        timerSyncTimeOut->setDuration(APP_NTP_SYNC_TIME_OUT * 1000);
        timerSyncTimeOut->m_signalTick.connect(this, &VappNtpMainPage::onTimerTick);
        timerSyncTimeOut->start();
    }
    else if (sender == settingBtn)
    {
        // call data account CUI
        cui_dtcnt_select_run_struct run_struct;
        memset(&run_struct, 0, sizeof(cui_dtcnt_select_run_struct));

        run_struct.bearers = DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI;
        run_struct.app_id = srv_ntp_data_acct_app_id_get();
        for (S32 i = 0; i < MMI_SIM_TOTAL; ++i)
        {
            run_struct.sim_account_id[i] = srv_ntp_data_acct_get(i);
        }

        run_struct.sim_selection = CUI_DTCNT_SELECT_SIM_ALL;
        run_struct.option = CUI_DTCNT_SELECT_DEFAULT;
        run_struct.type = CUI_DTCNT_SELECT_TYPE_NORMAL;

        dtcntCuiId = vcui_dtcnt_select_create(getMainScr()->getGroupId());
        vfxSetCuiCallerScr(dtcntCuiId, getMainScr());
        vcui_dtcnt_select_set_param(dtcntCuiId, &run_struct);
        vcui_dtcnt_select_run(dtcntCuiId);
    }
}

// data account cui proc
mmi_ret VappNtpMainPage::onProc(mmi_event_struct* evt)
{
    cui_dtcnt_select_event_any_sim_selected_struct * dtcntEvt;

    dtcntEvt = (cui_dtcnt_select_event_any_sim_selected_struct*)evt;
    switch (evt->evt_id)
    {
        case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:
            if (dtcntEvt->selectSim != CUI_DTCNT_SIM_TOTAL)
            {
                srv_ntp_data_acct_set(dtcntEvt->accountId,
                                      (U32)dtcntEvt->selectSim);
            }
            break;
        case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
        case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
        case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:
        case CUI_DTCNT_SELECT_EVENT_CLOSE:
            vcui_dtcnt_select_close(dtcntCuiId);
            break;
    }
    return VfxPage::onProc(evt);
}


