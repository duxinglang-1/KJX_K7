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
 *  vapp_cal_main.cpp
 *
 * Project:
 * --------
 *  Cosmos
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

extern "C"
{
	#include "todolistsrvgprot.h"
}

#include "mmi_rp_srv_venus_component_segment_button_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_vapp_calendar_def.h"
#ifdef __MMI_VUI_COSMOS_CP__
#include "mmi_rp_app_cosmos_global_def.h"

#endif

#ifdef __MMI_SNS_CALENDAR__
extern "C"
{
  #include "SnsSrvGprot.h"
}
#endif

#include "vfx_adp_device.h"
#include "vfx_base_popup.h" // include for vcp_info_balloon.h
#include "vfx_date_time.h"
#include "vfx_screen.h"
#include "vfx_text_frame.h"

#include "vcp_date_picker.h"
#include "vcp_info_balloon.h"
#include "vcp_menu_popup.h"
#include "vcp_navi_title_bar.h"
#include "vcp_segment_button.h"
#include "vcp_status_icon_bar.h"
#include "vcp_tool_bar.h"

#include "vapp_cal_prot.h"
#include "vapp_cal_group_list.h"
#include "vapp_cal_list_mgr.h"
#include "vapp_cal_utility.h"
#include "vapp_cal_view_detail.h"
#include "vapp_cal_edit.h"
#include "vapp_cal_main.h"
#include "vapp_cal_main_view.h"
#include "vdat_systime.h"
extern "C"
{
#include "GeneralSettingSrvGprot.h"

}
#ifndef __MMI_VCALENDAR__
#pragma arm section code = "DYNAMIC_CODE_CLNDR_ROCODE", rodata = "DYNAMIC_CODE_CLNDR_RODATA"
#endif
/***************************************************************************** 
 * Class VappCalMainViewPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappCalMainViewPage", VappCalMainViewPage, VfxPage);
VappCalMainViewPage::VappCalMainViewPage()
    : m_opListWeakPtr(NULL),
    m_confirmPopupWeakPtr(NULL),
    m_contentFrame(NULL),
    m_menuFrame(NULL),
    m_menuFrame2(NULL),
    m_viewMenu(NULL),
    m_dailyMenu(NULL),
    m_topTxBg(NULL),
    m_titleSolar(NULL),
    m_titleLunar(NULL),
    m_dailyWeek(NULL),
    m_dailyLunar(NULL),
    m_hightlightBox(NULL),
    m_timeLine(NULL),
    m_timeLine2(NULL),
    m_viewType(VappCalMainViewPage::VAPP_CAL_MONTHLY_VIEW),
    m_typeSelected(0),
    m_selIdx(0),
#ifndef __LOW_COST_SUPPORT_COMMON__
    m_evtInfoBox(NULL),
#endif
    m_contentH(0),
    m_preButton(NULL),
    m_nextButton(NULL),
    m_nActiveTimeline(0),
    m_jobId(-1),
    m_count(0),
    m_eventbuffer(NULL)

{
    m_highlightDT.setCurrentTime();

    for (VfxU32 i = 0; i < VAPP_CAL_MAX_DAYS_PER_WEEK; i++)
    {
        m_weeklydate[i] = NULL;
    }
}
VappCalMainViewPage::VappCalMainViewPage(const VfxDateTime &dateTime)
    : m_opListWeakPtr(NULL),
    m_confirmPopupWeakPtr(NULL),
    m_contentFrame(NULL),
    m_menuFrame(NULL),
    m_menuFrame2(NULL),
    m_viewMenu(NULL),
    m_dailyMenu(NULL),
    m_highlightDT(dateTime),
    m_topTxBg(NULL),
    m_titleSolar(NULL),
    m_titleLunar(NULL),
    m_dailyWeek(NULL),
    m_dailyLunar(NULL),
    m_hightlightBox(NULL),
    m_timeLine(NULL),
    m_timeLine2(NULL),
    m_viewType(VappCalMainViewPage::VAPP_CAL_MONTHLY_VIEW),
    m_typeSelected(0),
    m_selIdx(0),
#ifndef __LOW_COST_SUPPORT_COMMON__
    m_evtInfoBox(NULL),
#endif
    m_contentH(0),
    m_preButton(NULL),
    m_nextButton(NULL),
    m_nActiveTimeline(0),
    m_jobId(-1),
    m_count(0),
    m_eventbuffer(NULL),
    m_multiDelete(VFX_FALSE)
{
    for (VfxU32 i = 0; i < VAPP_CAL_MAX_DAYS_PER_WEEK; i++)
    {
        m_weeklydate[i] = NULL;
    }

}

void VappCalMainViewPage::onInit()
{
   
    VfxPage::onInit();

    VcpStatusIconBar *statusBar;
    VFX_OBJ_CREATE(statusBar, VcpStatusIconBar, this);

    VcpToolBar *toolBar;
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);

    m_contentH = getSize().height - statusBar->getSize().height - toolBar->getSize().height;



    //create the loading text

    VFX_OBJ_CLOSE(statusBar);

    VFX_OBJ_CLOSE(toolBar);

    //setBgColor(VFX_COLOR_WHITE);	

    // 1 - Top bar
    VfxImageFrame *topFrame;
    VFX_OBJ_CREATE(topFrame, VfxImageFrame, this);
    topFrame->setResId(IMG_ID_VAPP_CAL_TITLE_BG);
    topFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    topFrame->setRect(0, 0, getSize().width, VAPP_CAL_TOP_BAR_HEIGHT);

    // 1.1 - Title infor
    VFX_OBJ_CREATE(m_topTxBg, VcpImageButton, topFrame);
    m_topTxBg->setId(VAPP_CAL_TITLE_BUTTON);
    m_topTxBg->setAnchor(0.5f, 0.5f);
    m_topTxBg->setPos((getSize().width >> 1), (VAPP_CAL_TOP_BAR_HEIGHT >> 1));
    m_topTxBg->setSize((VfxS32)(getSize().width * 0.6f), (VfxS32)(VAPP_CAL_TOP_BAR_HEIGHT * 0.8f));
    m_topTxBg->m_signalClicked.connect(this, &VappCalMainViewPage::onTopPanelClick);

    VFX_OBJ_CREATE(m_titleSolar, VfxTextFrame, m_topTxBg);
    m_titleSolar->setAnchor(0.5f,0.5f);
    m_titleSolar->setColor(VFX_COLOR_WHITE);
    m_titleSolar->setFont(VfxFontDesc(VAPP_CAL_TITLE_SOLOAR_FONT, VFX_FONT_DESC_ATTR_NORMAL, VFX_FE1_9));
    m_titleSolar->setSize(m_topTxBg->getSize().width, (VfxS32)(m_topTxBg->getSize().height * 0.6f));    
    m_titleSolar->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);

    VFX_OBJ_CREATE(m_titleLunar, VfxTextFrame, m_topTxBg);
    m_titleLunar->setAnchor(0.5f,0.5f);
    m_titleLunar->setColor(VFX_COLOR_WHITE);
    m_titleLunar->setFont(VfxFontDesc(VAPP_CAL_TITLE_LUNAR_FONT, VFX_FONT_DESC_ATTR_NORMAL, VFX_FE1_9));
    m_titleLunar->setSize(m_topTxBg->getSize().width, (VfxS32)(m_topTxBg->getSize().height * 0.4f));
    m_titleLunar->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);

    // 1.2 - top navigation button
    VFX_OBJ_CREATE(m_preButton, VcpImageButton, topFrame);
    m_preButton->setId(VAPP_CAL_PRE_BUTTON);
    m_preButton->setAnchor(0, 0.5f);
    m_preButton->setImage(
                    VcpStateImage(IMG_ID_VAPP_CAL_LEFT_ARROW, 0, 0, 0));
    m_preButton->setPos(
                    VAPP_CAL_TOP_BAR_BUTTON_MARGIN, 
                    (topFrame->getSize().height >> 1));
    m_preButton->setSize(VAPP_CAL_FINGER_TOUCH_SIZE, VAPP_CAL_FINGER_TOUCH_SIZE);
    m_preButton->setIsEffect(VFX_TRUE);
    m_preButton->setEffectRatio(1.1f);
    m_preButton->setEffectOffset(VfxPoint(VAPP_CAL_TOP_ARROW_OFFSIZE));
    m_preButton->m_signalClicked.connect(this, &VappCalMainViewPage::onTopPanelClick);

    VFX_OBJ_CREATE(m_nextButton, VcpImageButton, topFrame);
    m_nextButton->setId(VAPP_CAL_NEXT_BUTTON);
    m_nextButton->setAnchor(1, 0.5f);
    m_nextButton->setImage(
                    VcpStateImage(IMG_ID_VAPP_CAL_RIGHT_ARROW, 0, 0, 0));
    m_nextButton->setPos(
                    topFrame->getSize().width - VAPP_CAL_TOP_BAR_BUTTON_MARGIN, 
                    (topFrame->getSize().height >> 1));
    m_nextButton->setSize(VAPP_CAL_FINGER_TOUCH_SIZE, VAPP_CAL_FINGER_TOUCH_SIZE);
    m_nextButton->setIsEffect(VFX_TRUE);
    m_nextButton->setEffectRatio(1.1f);
    m_nextButton->setEffectOffset(VfxPoint(VAPP_CAL_TOP_ARROW_OFFSIZE));
    m_nextButton->m_signalClicked.connect(this, &VappCalMainViewPage::onTopPanelClick);


    // 3 - bottom bar
    VappCalViwerSwitchBar *bottomBar;
    VFX_OBJ_CREATE(bottomBar, VappCalViwerSwitchBar, this);
    bottomBar->setHeight(VAPP_CAL_BOTTOM_BAR_HEIGHT);
    bottomBar->onAddItem();
    
#ifdef __MMI_VUI_WIDGET_CALENDAR__
    VappCalendarApp *app = (VappCalendarApp*)getApp();
    if (app->m_ctx.type == VAPP_CAL_LAUNCH_BY_CAL)
    {
        bottomBar->setSegmentPressed(VappCalViwerSwitchBar::VAPP_CAL_SWITCH_TYPE_MONTH);
    } 
    else if (app->m_ctx.type == VAPP_CAL_LAUNCH_BY_WIDGET)
    {
        bottomBar->setSegmentPressed(VappCalViwerSwitchBar::VAPP_CAL_SWITCH_TYPE_DAY);
    }
#else
    
    bottomBar->setSegmentPressed(VappCalViwerSwitchBar::VAPP_CAL_SWITCH_TYPE_MONTH);
    
#endif /*__MMI_VUI_WIDGET_CALENDAR__*/
    setBottomBar(bottomBar);
    bottomBar->m_signalClicked.connect(this, &VappCalMainViewPage::onBottomPanelClick);

    m_contentFrame = NULL;

}


void VappCalMainViewPage::creatpage()
{
    // 2 - main content frame when enter calendar firstly
#ifdef __MMI_VUI_WIDGET_CALENDAR__
    VappCalendarApp *app = (VappCalendarApp*)getApp();

    if (app->m_ctx.type == VAPP_CAL_LAUNCH_BY_CAL)
    {
        m_highlightDT.setCurrentTime();
        m_viewType = VAPP_CAL_MONTHLY_VIEW;
    }    
    else if (app->m_ctx.type == VAPP_CAL_LAUNCH_BY_WIDGET)
    {
        m_highlightDT.setDateTime(&(app->m_ctx.dateTime));
        m_viewType = VAPP_CAL_DAILY_VIEW;
    }
#else
    m_highlightDT.setCurrentTime();
    m_viewType = VAPP_CAL_MONTHLY_VIEW;
#endif /*__MMI_VUI_WIDGET_CALENDAR__*/

    enterNewViewMode();

    // init some data
    VFX_OBJ_CREATE(m_timeLine, VfxPointTimeline, this);
    m_timeLine->m_signalStarted.connect(this, &VappCalMainViewPage::onTimeLineStart);
    m_timeLine->m_signalStopped.connect(this, &VappCalMainViewPage::onTimeLineStop);

    VFX_OBJ_CREATE(m_timeLine2, VfxPointTimeline, this);
    m_timeLine2->m_signalStarted.connect(this, &VappCalMainViewPage::onTimeLineStart);
    m_timeLine2->m_signalStopped.connect(this, &VappCalMainViewPage::onTimeLineStop);



    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappCalMainViewPage::onTimeChanged);
}

void VappCalMainViewPage::onDeinit()
{

    mmi_frm_cb_dereg_event(EVT_ID_SRV_TDL_EVENT_OP, updateEvtInfo, getObjHandle());	 
    
#if defined(__MMI_VCALENDAR__) || defined(__MMI_TASK_APP__)
    mmi_frm_cb_dereg_event(EVT_ID_SRV_TDL_OP, updateEvtInfo, getObjHandle());
#endif


    VFX_FREE_MEM(m_eventbuffer);

    if(m_jobId > 0)
    {
        mmi_frm_cb_dereg_event(EVT_ID_SRV_TDL_EVENT_SEARCH, &VappCalMainViewPage::onEventReady, getObjHandle());
        srv_tdl_event_search_end(m_jobId);
        m_jobId = -1;
    }

    VfxPage::onDeinit();
}


void VappCalMainViewPage::onTimeChanged(VfxU32 flag)
{

    if ((flag & VDAT_SYSTIME_CHANGED_DAY))
    {

        if(m_menuFrame2 != NULL)
        {
            return;
        }
        if(m_viewType == VAPP_CAL_MONTHLY_VIEW)
        {
            m_viewMenu->reset();
        }
    }

}

void VappCalMainViewPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

    if ((m_viewType == VAPP_CAL_DAILY_VIEW)||(m_viewType == VAPP_CAL_WEEKLY_VIEW))
    {
        m_preButton->setState(VCP_IMAGE_BUTTON_STATE_NORMAL);
        m_nextButton->setState(VCP_IMAGE_BUTTON_STATE_NORMAL);
        updateArrowState();
    }
}


void VappCalMainViewPage::onEntered()
{
    if (getDataChangeState())
    {
        setDataChangeState(VFX_FALSE);
        enterNewViewMode();
    }
}


VfxBool VappCalMainViewPage::onPenInput(VfxPenEvent &event)
{
    if (m_viewType == VAPP_CAL_WEEKLY_VIEW)
    {
        VfxPoint pos;
        pos = event.getRelPos(m_contentFrame);

        switch (event.type)
        {
            case VFX_PEN_EVENT_TYPE_DOWN:
            {
                if (pos.y <= VAPP_CAL_WEEKLY_WEEK_BAR_HEIGHT && pos.x >= VAPP_CAL_WEEKLY_F_CELL_WIDTH)
                {
                    applib_time_struct date;
                    date = m_highlightDT.getDateTime();

                    VfxS32 posIdx = (pos.x - VAPP_CAL_WEEKLY_F_CELL_WIDTH) / VAPP_CAL_WEEKLY_CELL_WIDTH + 1;

                    m_viewMenu->computePos2Date(posIdx, &date);

                    if (VappCalUtility::dateTimeIsOutOfBounder(date.nYear, VAPP_CAL_CATEGORY_PERSONAL))
                    {
                        break;
                    }

                    m_highlightDT.setDate(date.nYear, date.nMonth, date.nDay);
                    m_hightlightBox->setPos((posIdx - 1) * VAPP_CAL_WEEKLY_CELL_WIDTH + VAPP_CAL_WEEKLY_F_CELL_WIDTH, 0);
                    m_hightlightBox->setSize(VAPP_CAL_WEEKLY_CELL_WIDTH + 1,VAPP_CAL_WEEKLY_WEEK_BAR_HEIGHT);

                    return VFX_TRUE;
                }
                break;
            }
            default:
                break;
        }
    }

    return VfxPage::onPenInput(event);
}


VfxBool VappCalMainViewPage::onKeyInput(VfxKeyEvent & event)
{
    if ((event.type == VFX_KEY_EVENT_TYPE_UP)&&(event.keyCode == VFX_KEY_CODE_ARROW_LEFT ||
        event.keyCode == VFX_KEY_CODE_ARROW_RIGHT))
    {
        checkImageButton();
        updateArrowState();
    }

    if (m_menuFrame2 != NULL)
    {
        return VfxPage::onKeyInput(event);
    }

    if (m_nActiveTimeline != 0)
    {
        return VFX_TRUE;
    }

    if (event.type == VFX_KEY_EVENT_TYPE_DOWN ||
        event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS ||
        event.type == VFX_KEY_EVENT_TYPE_REPEAT)
    {
        if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT)
        {
            if (!m_preButton->getIsDisabled() &&
                computeNextDateTime(VFX_FALSE))
            {
                m_preButton->setState(VCP_IMAGE_BUTTON_STATE_PRESSED);

                shiftToNextMenu(VFX_FALSE);

                return VFX_TRUE;
            }
        }
        else if(event.keyCode == VFX_KEY_CODE_ARROW_RIGHT)
        {
            if (!m_nextButton->getIsDisabled() &&
                computeNextDateTime(VFX_TRUE))
            {
                m_nextButton->setState(VCP_IMAGE_BUTTON_STATE_PRESSED);
                shiftToNextMenu(VFX_TRUE);

                return VFX_TRUE;
            }
        }
      
    }

    return VfxPage::onKeyInput(event);
}

void VappCalMainViewPage::updateChanged(void)
{
#ifndef __LOW_COST_SUPPORT_COMMON__
    updateEvtList();
#endif
    if (m_viewType == VAPP_CAL_MONTHLY_VIEW ||
        m_viewType == VAPP_CAL_WEEKLY_VIEW)
    {
        m_viewMenu->updateChangedCell(m_eventbuffer,m_count);  
    }
}


mmi_ret VappCalMainViewPage::onEventReady(mmi_event_struct *param)
{
    srv_tdl_search_callback_struct* sEvent = (srv_tdl_search_callback_struct*)param; 
    VfxObject *obj = handleToObject((VfxObjHandle)param->user_data);
    if (obj == NULL)
    {
        return MMI_RET_OK;
    }
    VappCalMainViewPage *page = VFX_OBJ_DYNAMIC_CAST(obj, VappCalMainViewPage);
    if(page == NULL)
    {
        return MMI_RET_OK;
    }
    if(page->m_jobId != sEvent->job_id)
    {
        return MMI_RET_OK;
    }
    if(!sEvent->success)
    { 
        VappCalUtility::getSnsDataError();	 
    }
    page->m_count = sEvent->event_cnt;   

    if ((page->m_viewType == VappCalMainViewPage::VAPP_CAL_MONTHLY_VIEW)||(page->m_viewType == VappCalMainViewPage::VAPP_CAL_WEEKLY_VIEW))
    {
        if (page->m_count != 0)
        {
            VFX_ALLOC_MEM(page->m_eventbuffer, page->m_count * sizeof(srv_tdl_event_id_struct) , page);
            if( srv_tdl_event_search_get(page->m_jobId, page->m_eventbuffer,page->m_count* sizeof(srv_tdl_event_id_struct) , 0) < 0 )
            {
                VFX_ASSERT(0);
            }
        }

        srv_tdl_event_search_end(page->m_jobId);
        page->m_jobId = -1;
        mmi_frm_cb_dereg_event(EVT_ID_SRV_TDL_EVENT_SEARCH, &VappCalMainViewPage::onEventReady, page->getObjHandle());
        page->m_viewMenu->updateChangedCell(page->m_eventbuffer,page->m_count);
        page->m_viewMenu->reset();
        page->checkUpdate();
    }
    return MMI_RET_OK;
}

#ifndef __LOW_COST_SUPPORT_COMMON__

void VappCalMainViewPage::updateEvtList(void)
{
    if (m_viewType == VAPP_CAL_MONTHLY_VIEW)
    {
        if (m_evtInfoBoxWeakPtr.isValid())
        {
            VappCalDailyList *temp =m_evtInfoBoxWeakPtr.get();
            VFX_OBJ_CLOSE(temp);
        }

    }
}
#endif

void VappCalMainViewPage::enterNewViewMode()
{
    // MUST close the priously frame because the three frame use the same m_contentFrame;
    if(m_contentFrame != NULL )
    {
        VFX_OBJ_CLOSE(m_contentFrame);
    }

    if (m_typeSelected == VappCalViwerSwitchBar::VAPP_CAL_SWITCH_TYPE_MONTH)
    {
        m_viewType = VAPP_CAL_MONTHLY_VIEW;
    }
    else if (m_typeSelected == VappCalViwerSwitchBar::VAPP_CAL_SWITCH_TYPE_WEEK)
    {
        m_viewType = VAPP_CAL_WEEKLY_VIEW;
    }
    else if (m_typeSelected == VappCalViwerSwitchBar::VAPP_CAL_SWITCH_TYPE_DAY)
    {
        m_viewType = VAPP_CAL_DAILY_VIEW;
    }
   

    mmi_frm_cb_reg_event(EVT_ID_SRV_TDL_EVENT_OP, updateEvtInfo, getObjHandle());
    
#if defined(__MMI_VCALENDAR__) || defined(__MMI_TASK_APP__)
    mmi_frm_cb_reg_event(EVT_ID_SRV_TDL_OP, updateEvtInfo, getObjHandle());
#endif

    if (m_viewType == VAPP_CAL_MONTHLY_VIEW)
    {
        enterMonthly();
    }
    else if (m_viewType == VAPP_CAL_WEEKLY_VIEW)
    {
        enterWeekly();
    }
    else if (m_viewType == VAPP_CAL_DAILY_VIEW)
    {
        enterDaily();
    }

}

void VappCalMainViewPage::enterMonthly()
{
    m_viewType = VAPP_CAL_MONTHLY_VIEW;
    m_menuFrame2 = NULL;

    // main content frame
    VFX_OBJ_CREATE(m_contentFrame, VfxFrame, this);
    m_contentFrame->setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));	
    m_contentFrame->setPos(0, VAPP_CAL_TOP_BAR_HEIGHT - VAPP_CAL_TOP_BAR_SHARDOW_HEIGHT);
    m_contentFrame->setSize(getSize().width, m_contentH - (VAPP_CAL_TOP_BAR_HEIGHT - VAPP_CAL_TOP_BAR_SHARDOW_HEIGHT));


    // 2.1 - main content title background frame
    VfxImageFrame *titleBgFrame;
    VFX_OBJ_CREATE(titleBgFrame, VfxImageFrame, m_contentFrame);
    titleBgFrame->setResId(IMG_ID_VAPP_CAL_WEEK_BG);
    titleBgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    titleBgFrame->setPos(0, 0);
    titleBgFrame->setSize(getSize().width, VAPP_CAL_MONTHLY_WEEK_BAR_HEIGHT);

    for (VfxU8 i = VAPP_CAL_START_WEEKDAY; i < VAPP_CAL_MAX_DAYS_PER_WEEK; i++)
    {
        VfxTextFrame *daysTxFrame;
        VFX_OBJ_CREATE(daysTxFrame, VfxTextFrame, titleBgFrame);
        daysTxFrame->setAnchor(0.5f, 0.5f);
        daysTxFrame->setString((VfxResId)(STR_ID_VAPP_CAL_WEEK_SUN + i));
        daysTxFrame->setColor(VFX_COLOR_WHITE);
        daysTxFrame->setFont(VfxFontDesc(VAPP_CAL_MONTH_WEEKDAY_FONT, VFX_FONT_DESC_ATTR_NORMAL));
        daysTxFrame->setPos(
                    VAPP_CAL_MONTHLY_CELL_WIDTH * i + (VAPP_CAL_MONTHLY_CELL_WIDTH >> 1), 
                    (VAPP_CAL_MONTHLY_WEEK_BAR_HEIGHT >> 1) + VAPP_CAL_MONTHLY_WEEK_BAR_SHARDOW_H);
        daysTxFrame->setSize(VAPP_CAL_MONTHLY_CELL_WIDTH, VAPP_CAL_MONTHLY_WEEK_BAR_HEIGHT);
        daysTxFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    }

    // 2.2 - monthly main body
    VFX_OBJ_CREATE(m_menuFrame, VfxFrame, m_contentFrame);
    m_menuFrame->setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    m_menuFrame->setPos(0, VAPP_CAL_MONTHLY_WEEK_BAR_HEIGHT);
    m_menuFrame->setSize(
                m_contentFrame->getSize().width, 
                VAPP_CAL_MONTHLY_CELL_HEIGHT * VAPP_CAL_MONTHLY_ROW);
    createMenu(m_menuFrame);

#ifndef __LOW_COST_SUPPORT_COMMON__
    VFX_OBJ_CREATE_EX(
                m_evtInfoBox,
                VappCalDailyList,
                m_contentFrame, 
                (VAPP_CAL_MONTHLY_VIEW, m_highlightDT.getDateTime()));

    m_evtInfoBox->setShadowIsDisabled(VFX_TRUE);
    m_evtInfoBox->setContentProvider((IVcpListMenuContentProvider*)m_evtInfoBox);
    m_evtInfoBox->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
    m_evtInfoBox->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_TRIPLE_TEXT_EX);
    m_evtInfoBox->setPos(
                    0, 
                    m_menuFrame->getSize().height + VAPP_CAL_MONTHLY_WEEK_BAR_HEIGHT + VAPP_CAL_MONTHLY_EDIVIDER_HEIGHT);
    VfxS32 evtInfoHeight = m_contentFrame->getSize().height 
                            - VAPP_CAL_MONTHLY_WEEK_BAR_HEIGHT 
                            - VAPP_CAL_MONTHLY_EDIVIDER_HEIGHT
                            - m_menuFrame->getSize().height;
    if (evtInfoHeight <= 0)
    {
    // for 240 * 320, no evtInfobox to show 
        evtInfoHeight = 0;
    }

    m_evtInfoBox->setSize(m_contentFrame->getSize().width, evtInfoHeight);

    m_evtInfoBox->m_signalItemTapped.connect(this, &VappCalMainViewPage::onDailyMenuClick);
#endif

    // 2.x - should change title text frame
    updateTitle();
    updateArrowState();
}

void VappCalMainViewPage::enterWeekly()
{
    m_viewType = VAPP_CAL_WEEKLY_VIEW;

    // main content frame
    VFX_OBJ_CREATE(m_contentFrame, VfxFrame, this);
    m_contentFrame->setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));	
    m_contentFrame->setPos(0, VAPP_CAL_TOP_BAR_HEIGHT - VAPP_CAL_TOP_BAR_SHARDOW_HEIGHT);
    m_contentFrame->setSize(
                        getSize().width, 
                        m_contentH - (VAPP_CAL_TOP_BAR_HEIGHT - VAPP_CAL_TOP_BAR_SHARDOW_HEIGHT));

    // 2.1 - main content title background frame
    VfxFrame *titleBgFrame;
    VFX_OBJ_CREATE(titleBgFrame, VfxFrame, m_contentFrame);
    titleBgFrame->setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));//(VfxColor(255, 241, 241, 241));	
    titleBgFrame->setPos(0, 0);
    titleBgFrame->setSize(getSize().width, VAPP_CAL_WEEKLY_WEEK_BAR_HEIGHT);

    VfxImageFrame *daysBgFrame;
    VFX_OBJ_CREATE(daysBgFrame, VfxImageFrame, m_contentFrame);
    daysBgFrame->setResId(IMG_ID_VAPP_CAL_WEEK_BG);
    daysBgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    daysBgFrame->setPos(VAPP_CAL_WEEKLY_F_CELL_WIDTH, 0);
    daysBgFrame->setSize(getSize().width - VAPP_CAL_WEEKLY_F_CELL_WIDTH, (titleBgFrame->getSize().height >> 1));

    for (VfxU8 i = 0; i < 7; i++)
    {
        VfxTextFrame *daysTxFrame;
        VFX_OBJ_CREATE(daysTxFrame, VfxTextFrame, daysBgFrame);
        daysTxFrame->setAnchor(0.5f, 0.5f);
        daysTxFrame->setString((VfxResId)(STR_ID_VAPP_CAL_WEEK_SUN + i));
        daysTxFrame->setColor(VFX_COLOR_WHITE);
        daysTxFrame->setFont(VfxFontDesc(VAPP_CAL_WEEK_WEEKDAY_FONT, VFX_FONT_DESC_ATTR_NORMAL));
        daysTxFrame->setPos(
                    (VAPP_CAL_WEEKLY_CELL_WIDTH >> 1) + i * VAPP_CAL_WEEKLY_CELL_WIDTH, 
                    (daysBgFrame->getSize().height >> 1) + VAPP_CAL_MONTHLY_WEEK_BAR_SHARDOW_H);
        daysTxFrame->setSize(VAPP_CAL_WEEKLY_CELL_WIDTH, (titleBgFrame->getSize().height >> 1) - 2);
        daysTxFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    }

    for (VfxU8 i = 0; i < 7; i++)
    {
        VfxImageFrame *dateBgFrame;
        VFX_OBJ_CREATE(dateBgFrame, VfxImageFrame, titleBgFrame);
        dateBgFrame->setResId(IMG_ID_VAPP_CAL_TITLE2_BG);
        dateBgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        dateBgFrame->setPos(
                    VAPP_CAL_WEEKLY_F_CELL_WIDTH + 1 + i * VAPP_CAL_WEEKLY_CELL_WIDTH, 
                    (titleBgFrame->getSize().height >> 1));
        dateBgFrame->setSize(VAPP_CAL_WEEKLY_CELL_WIDTH - 1, (titleBgFrame->getSize().height >> 1));

        VFX_OBJ_CREATE(m_weeklydate[i], VfxTextFrame, dateBgFrame);
        m_weeklydate[i]->setAnchor(0.5f, 0.5f);
        m_weeklydate[i]->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
        m_weeklydate[i]->setFont(VfxFontDesc(VAPP_CAL_WEEK_WEEKDATE_FONT, VFX_FONT_DESC_ATTR_NORMAL));
        m_weeklydate[i]->setPos(
                            (VAPP_CAL_WEEKLY_CELL_WIDTH >> 1), 
                            (titleBgFrame->getSize().height >> 2));
        m_weeklydate[i]->setSize(VAPP_CAL_WEEKLY_CELL_WIDTH, (titleBgFrame->getSize().height >> 1) - 4);
        m_weeklydate[i]->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    }

    // 2.2 - scrollable body
    VFX_OBJ_CREATE(m_menuFrame, VfxFrame, m_contentFrame);
    m_menuFrame->setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    m_menuFrame->setPos(0, VAPP_CAL_WEEKLY_WEEK_BAR_HEIGHT);
    m_menuFrame->setSize(
                    m_contentFrame->getSize().width, 
                    m_contentFrame->getSize().height - VAPP_CAL_WEEKLY_WEEK_BAR_HEIGHT + 1);
    createMenu(m_menuFrame);

    VfxS32 posIdx;
    
    applib_time_struct applib_time = {0};
    applib_time = m_highlightDT.getDateTime();

    posIdx = m_viewMenu->computeDate2Pos(&applib_time);
    VFX_OBJ_CREATE(m_hightlightBox, VfxImageFrame, m_contentFrame);
    m_hightlightBox->setResId(IMG_ID_VAPP_CAL_DAY_SELECT);
    m_hightlightBox->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_hightlightBox->setAutoAnimate(VFX_TRUE);	
    m_hightlightBox->setSize(
    VAPP_CAL_WEEKLY_CELL_WIDTH + 1, 
    VAPP_CAL_WEEKLY_WEEK_BAR_HEIGHT);
    updateHighlightBox((VfxId)posIdx);

    // should change title text frame
    updateTitle();
    updateArrowState();
}

void VappCalMainViewPage::enterDaily()
{
    m_viewType = VAPP_CAL_DAILY_VIEW;

    // main content frame
    VFX_OBJ_CREATE(m_contentFrame, VfxFrame, this);
    //m_contentFrame->setBgColor(VFX_COLOR_WHITE);	
    m_contentFrame->setPos(0, VAPP_CAL_TOP_BAR_HEIGHT - VAPP_CAL_TOP_BAR_SHARDOW_HEIGHT);
    m_contentFrame->setSize(
                    getSize().width, 
                    m_contentH - (VAPP_CAL_TOP_BAR_HEIGHT - VAPP_CAL_TOP_BAR_SHARDOW_HEIGHT));

    VfxImageFrame *titleBgFrame;
    VFX_OBJ_CREATE(titleBgFrame, VfxImageFrame, m_contentFrame);
    titleBgFrame->setResId(IMG_ID_VAPP_CAL_DATE_BG);
    titleBgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    titleBgFrame->setPos(0, 0);
    titleBgFrame->setSize(getSize().width, VAPP_CAL_DAILY_LUNAR_BAR_HEIGHT);

    VFX_OBJ_CREATE(m_dailyWeek, VfxTextFrame, titleBgFrame);
    m_dailyWeek->setAnchor(0, 0.5f);
    m_dailyWeek->setString(m_highlightDT.getDateTimeString(VFX_DATE_TIME_DAY_NORMAL_NAME));
    m_dailyWeek->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    m_dailyWeek->setFont(VfxFontDesc(VAPP_CAL_DAY_WEEKDAY_FONT, VFX_FONT_DESC_ATTR_NORMAL));
    m_dailyWeek->setPos(
                VAPP_CAL_DAILY_WEEKDAY_L_MARGIN, 
                (VAPP_CAL_DAILY_LUNAR_BAR_HEIGHT >> 1));
    m_dailyWeek->setSize(VAPP_CAL_DAILY_WEEKDAY_WIDTH, VAPP_CAL_DAILY_LUNAR_BAR_HEIGHT);
    m_dailyWeek->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_dailyWeek->setFullLineHeightMode(VFX_FALSE);

    VFX_OBJ_CREATE(m_dailyLunar, VfxTextFrame, titleBgFrame);
    m_dailyLunar->setAnchor(0, 0.5f);
    m_dailyLunar->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));
    m_dailyLunar->setFont(VfxFontDesc(VAPP_CAL_DAY_LUNAR_FONT, VFX_FONT_DESC_ATTR_NORMAL));
    m_dailyLunar->setPos(
                    VAPP_CAL_DAILY_WEEKDAY_L_MARGIN + VAPP_CAL_DAILY_WEEKDAY_WIDTH, 
                    (VAPP_CAL_DAILY_LUNAR_BAR_HEIGHT >> 1));
    m_dailyLunar->setSize(getSize().width, VAPP_CAL_DAILY_LUNAR_BAR_HEIGHT);
    m_dailyLunar->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_dailyLunar->setFullLineHeightMode(VFX_FALSE);

    // daily list menu
    VFX_OBJ_CREATE(m_menuFrame, VfxFrame, m_contentFrame);
    m_menuFrame->setPos(0, VAPP_CAL_DAILY_LUNAR_BAR_HEIGHT);
    m_menuFrame->setSize(
    m_contentFrame->getSize().width, 
    m_contentFrame->getSize().height - VAPP_CAL_DAILY_LUNAR_BAR_HEIGHT);
    createMenu(m_menuFrame);

    // should change title text frame
    updateTitle();
    updateArrowState();

}


void VappCalMainViewPage::checkImageButton(void)
{
    if (m_preButton->getState() == VCP_IMAGE_BUTTON_STATE_PRESSED)
    {
        m_preButton->setState(VCP_IMAGE_BUTTON_STATE_NORMAL);
    }
    if (m_nextButton->getState() == VCP_IMAGE_BUTTON_STATE_PRESSED)
    {
        m_nextButton->setState(VCP_IMAGE_BUTTON_STATE_NORMAL);
    }
}

void VappCalMainViewPage::shiftToNextMenu(VfxBool is_next)
{
    if (m_contentFrame == NULL)
    {
    return;
    }

    // update title
    updateTitle();

    if (m_viewType == VAPP_CAL_WEEKLY_VIEW)
    {
        VFX_OBJ_CLOSE(m_menuFrame);

        VFX_OBJ_CREATE(m_menuFrame, VfxFrame, m_contentFrame);
        m_menuFrame->setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
        m_menuFrame->setPos(0, VAPP_CAL_WEEKLY_WEEK_BAR_HEIGHT);
        m_menuFrame->setSize(
                    m_contentFrame->getSize().width, 
                    m_contentFrame->getSize().height - VAPP_CAL_WEEKLY_WEEK_BAR_HEIGHT + 1);
        createMenu(m_menuFrame);

        VfxU16 posIdx;
        
        applib_time_struct applib_time = {0};
        applib_time = m_highlightDT.getDateTime();
        
        posIdx = m_viewMenu->computeDate2Pos(&applib_time);
        updateHighlightBox(posIdx);
    }
    else if (m_viewType == VAPP_CAL_DAILY_VIEW)
    {
        VFX_OBJ_CLOSE(m_menuFrame);

        VFX_OBJ_CREATE(m_menuFrame, VfxFrame, m_contentFrame);
        m_menuFrame->setPos(0, VAPP_CAL_DAILY_LUNAR_BAR_HEIGHT);
        m_menuFrame->setSize(
                        m_contentFrame->getSize().width, 
                        m_contentFrame->getSize().height - VAPP_CAL_DAILY_LUNAR_BAR_HEIGHT);
        createMenu(m_menuFrame);
    }
    else if (m_viewType == VAPP_CAL_MONTHLY_VIEW)
    {
        // for monthly view, should handle switch animation;
        VfxS32 posX;

        if (is_next)
        {
            posX = getSize().width;
        }
        else
        {
            posX = -(getSize().width - 1);
        }

        VFX_OBJ_CREATE(m_menuFrame2, VfxFrame, m_contentFrame);
        m_menuFrame2->setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
        m_menuFrame2->setPos(posX, VAPP_CAL_MONTHLY_WEEK_BAR_HEIGHT);
        m_menuFrame2->setSize(
                    m_contentFrame->getSize().width, 
                    VAPP_CAL_MONTHLY_CELL_HEIGHT * VAPP_CAL_MONTHLY_ROW + 1);
        createMenu(m_menuFrame2);

#ifndef __LOW_COST_SUPPORT_COMMON__
        creatEventBox();
#endif
        // the original menu and the temp menu will move towards the left or right
        m_timeLine->setTarget(m_menuFrame);
        m_timeLine->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        m_timeLine->setDurationTime(250);
        m_timeLine->setAutoReversed(VFX_TRUE);
        m_timeLine->setFromValue(m_menuFrame->getPos());
        m_timeLine->setToValue(VfxPoint(-posX, VAPP_CAL_MONTHLY_WEEK_BAR_HEIGHT));
        m_timeLine->start();

        m_timeLine2->setTarget(m_menuFrame2);
        m_timeLine2->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        m_timeLine2->setDurationTime(250);
        m_timeLine2->setAutoReversed(VFX_TRUE);
        m_timeLine2->setFromValue(m_menuFrame2->getPos());
        m_timeLine2->setToValue(VfxPoint(0, VAPP_CAL_MONTHLY_WEEK_BAR_HEIGHT));
        m_timeLine2->start();
    }
}

void VappCalMainViewPage::jumpToDate()
{
    // Popup date and time picker and select a date to jump
    VappCalDatePickerPopup *jumpPopup;

    VFX_OBJ_CREATE_EX(jumpPopup, VappCalDatePickerPopup, this, (VFX_TRUE));
    VcpDatePickerStruct date;
    date.year = m_highlightDT.getYear();
    date.month = m_highlightDT.getMonth();
    date.day = m_highlightDT.getDay();

    jumpPopup->m_datePicker->setDate(date);
    jumpPopup->setUsedByJumpToDate();
    jumpPopup->m_signalButtonClicked.connect(this, &VappCalMainViewPage::onJumpToDateClicked);
    jumpPopup->setAutoDestory(VFX_TRUE);
    jumpPopup->show(VFX_TRUE);
}

void VappCalMainViewPage::onTopPanelClick(VfxObject* sender, VfxId id)
{
    if (m_menuFrame2)
    {
        if(m_viewType != VAPP_CAL_MONTHLY_VIEW)
        {
            m_timeLine->stop();
            m_timeLine2->stop();
        }
        else
        {
            return;
        }
    }

    switch(id)
    {
    case VAPP_CAL_NEXT_BUTTON:
        if (computeNextDateTime(VFX_TRUE))
        {
            shiftToNextMenu(VFX_TRUE);
            updateArrowState();
        }
        break;
    case VAPP_CAL_PRE_BUTTON:
        if (computeNextDateTime(VFX_FALSE))
        {
            shiftToNextMenu(VFX_FALSE);
            updateArrowState();
        }
        break;
    case VAPP_CAL_TITLE_BUTTON:
        jumpToDate();
        break;
    default:
        break;
    }

}

void VappCalMainViewPage::onBottomPanelClick(VfxObject* sender, VfxId id)
{
    m_typeSelected = id;

    switch(id)
    {
    case VappCalViwerSwitchBar::VAPP_CAL_SWITCH_TYPE_LIST:
    {
        VappCalGroupListPage *listPage;
        VFX_OBJ_CREATE_EX(listPage, VappCalGroupListPage, getMainScr(), (VAPP_CAL_G_LIST_ENTRY_CALENDAR));
        getMainScr()->pushPage(0, listPage);
        break;
    }

    case VappCalViwerSwitchBar::VAPP_CAL_SWITCH_TYPE_ADD:
    {
        if (srv_tdl_is_full(SRV_TDL_VCAL_EVENT))
        {  
            m_typeSelected = 0;
            VcpConfirmPopup *popup;
            VFX_OBJ_CREATE(popup, VcpConfirmPopup, this);
            popup->setInfoType(VCP_POPUP_TYPE_FAILURE);
            popup->setText((VfxResId)STR_ID_VAPP_CAL_MEM_FULL);
            popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
            popup->setAutoDestory(VFX_TRUE);
            popup->show(VFX_TRUE);       
            break;
        }
        applib_time_struct applib_time = {0};
        applib_time = m_highlightDT.getDateTime();

        VappCalEditPage *addPage;
        VFX_OBJ_CREATE_EX(
                    addPage, 
                    VappCalEditPage, 
                    getMainScr(), 
                    (SRV_TDL_VCAL_EVENT, 0, VAPP_CAL_OPERATION_TYPE_ADD, &applib_time));

        getMainScr()->pushPage(0, addPage);

        break;
    }
    case VappCalViwerSwitchBar::VAPP_CAL_SWITCH_TYPE_MONTH:
    case VappCalViwerSwitchBar::VAPP_CAL_SWITCH_TYPE_WEEK:
    case VappCalViwerSwitchBar::VAPP_CAL_SWITCH_TYPE_DAY:
    {
        // if do not change the viewer, return directly
        if (m_typeSelected == (m_viewType + VappCalViwerSwitchBar::VAPP_CAL_SWITCH_TYPE_MONTH))
        {
            return;
        }
        if ((m_menuFrame2)&&(m_viewType == VAPP_CAL_MONTHLY_VIEW)&&(id != VappCalViwerSwitchBar::VAPP_CAL_SWITCH_TYPE_MONTH))
        {

            onTimeLineStop(m_timeLine,VFX_TRUE);
            onTimeLineStop(m_timeLine2,VFX_TRUE);
        }


        mmi_frm_cb_dereg_event(EVT_ID_SRV_TDL_EVENT_OP, updateEvtInfo, getObjHandle());
        
#if defined(__MMI_VCALENDAR__) || defined(__MMI_TASK_APP__)
        mmi_frm_cb_dereg_event(EVT_ID_SRV_TDL_OP, updateEvtInfo, getObjHandle());
#endif

        if(m_viewType == VAPP_CAL_WEEKLY_VIEW)
        {
            m_viewMenu->stopScrolling();
        }
        else if(m_viewType == VAPP_CAL_DAILY_VIEW)
        {
            m_dailyMenu->stopScrolling();
        }

        enterNewViewMode();
        break;
    }

    default:
        break;
    }
}

#ifndef __LOW_COST_SUPPORT_COMMON__
void VappCalMainViewPage::creatEventBox()
{
    if (m_evtInfoBoxWeakPtr.isValid())
    {
        VappCalDailyList *temp = m_evtInfoBoxWeakPtr.get();
        VFX_OBJ_CLOSE(temp);
    } 

    VFX_OBJ_CREATE_EX(
                m_evtInfoBox,
                VappCalDailyList,
                m_contentFrame, 
                (VAPP_CAL_MONTHLY_VIEW, m_highlightDT.getDateTime()));

    m_evtInfoBox->setShadowIsDisabled(VFX_TRUE);
    m_evtInfoBox->setContentProvider((IVcpListMenuContentProvider*)m_evtInfoBox);
    m_evtInfoBox->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
    m_evtInfoBox->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_TRIPLE_TEXT_EX);
    m_evtInfoBox->setPos(
                        0, 
                        m_menuFrame->getSize().height + VAPP_CAL_MONTHLY_WEEK_BAR_HEIGHT + VAPP_CAL_MONTHLY_EDIVIDER_HEIGHT);
    VfxS32 evtInfoHeight = m_contentFrame->getSize().height 
                            - VAPP_CAL_MONTHLY_WEEK_BAR_HEIGHT 
                            - VAPP_CAL_MONTHLY_EDIVIDER_HEIGHT
                            - m_menuFrame->getSize().height;
    if (evtInfoHeight <= 0)
    {
    // for 240 * 320, no evtInfobox to show 
        evtInfoHeight = 0;
    }

    m_evtInfoBox->setSize(m_contentFrame->getSize().width, evtInfoHeight);

    m_evtInfoBox->m_signalItemTapped.connect(this, &VappCalMainViewPage::onDailyMenuClick);

    m_evtInfoBoxWeakPtr = m_evtInfoBox;
  
}
#endif


void VappCalMainViewPage::onMonthlyMenuClick(VfxObject* sender, VfxS32 posIdx)
{
    if (posIdx < 0)
    {
        return;
    }

    // compute the highlighted date
    applib_time_struct date;
    date = m_highlightDT.getDateTime();
    m_viewMenu->computePos2Date(posIdx, &date);

    if (VappCalUtility::dateTimeIsOutOfBounder(date.nYear, VAPP_CAL_CATEGORY_PERSONAL))
    {
        return;
    }

    m_highlightDT.setDate(date.nYear, date.nMonth, date.nDay);

    // move the highlightBox to the date higlighted
    VappCalMonthlyCell *cell = (VappCalMonthlyCell *)m_viewMenu->getCellIfPresent(0, posIdx);
    if (!cell->getDisabled())
    {
        updateHighlightBox(posIdx);

#ifndef __LOW_COST_SUPPORT_COMMON__
        creatEventBox();
#endif

    }
    else
    {
        if (m_menuFrame2)
        {
            return;
        }

        if (posIdx < VAPP_CAL_MAX_DAYS_PER_WEEK)
        {
            shiftToNextMenu(VFX_FALSE);
        }
        else if (posIdx > 28)
        {
            shiftToNextMenu(VFX_TRUE);
        }
    }

    // update the lunar title	
    updateTitleLunarStr();
}

void VappCalMainViewPage::onWeeklyMenuClick(VfxObject* sender, VfxS32 posIdx)
{
    if (posIdx < 0)
    {
        return;
    }
    if (posIdx % VAPP_CAL_WEEKLY_COLUMN == 0)
    {
        return;
    }

    // 1-compute the highlighted date and time clicked
    applib_time_struct date;
    date = m_highlightDT.getDateTime();

    m_viewMenu->computePos2Date(posIdx, &date);

    if (VappCalUtility::dateTimeIsOutOfBounder(date.nYear, VAPP_CAL_CATEGORY_PERSONAL))
    {
        return;
    }

    m_highlightDT.setDate(date.nYear, date.nMonth, date.nDay);

    // 2-move highlightBox to the date highlighted
    updateHighlightBox(posIdx);
}

void VappCalMainViewPage::onDailyMenuClick(VcpListMenu* sender, VfxId menuId)
{
    VappCalDailyList *list;
    list = VFX_OBJ_DYNAMIC_CAST(sender, VappCalDailyList);
    if (list == NULL)
    {
        return;
    }

    VappCalViewDetailPage *viewPage;


    srv_tdl_event_id_struct *buffer = list->GetEventbuffer() ;
    VFX_OBJ_CREATE_EX(
                viewPage, 
                VappCalViewDetailPage,
                getMainScr(),
                (SRV_TDL_VCAL_EVENT,*(buffer + menuId)) );

    getMainScr()->pushPage(0, viewPage);

}

void VappCalMainViewPage::onDailyMenuLongTap(VcpListMenu *sender, VfxId id)
{
    VappCalDailyList *list;
    list = VFX_OBJ_DYNAMIC_CAST(sender, VappCalDailyList);
    if (list == NULL)
    {
        return;
    }

    if (list->getMenuMode() != VCP_LIST_MENU_MODE_NORMAL)
    {
        return;
    }

    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);

    m_selIdx = id;


    srv_tdl_event_struct *buffer;
    VFX_ALLOC_MEM(buffer,sizeof(srv_tdl_event_struct),this);
    srv_tdl_event_id_struct* eventBuffer = m_dailyMenu->GetEventbuffer();
    srv_tdl_event_get(
                buffer, 
                sizeof(srv_tdl_event_struct), 
                (eventBuffer + m_selIdx)->source_id,
                (eventBuffer + m_selIdx)->event_id);

    VcpMenuPopup *opList;
    VFX_OBJ_CREATE(opList, VcpMenuPopup, this);
    opList->setTitle((VfxWChar *)buffer->subject);
    opList->addItem(0, (VfxResId)STR_ID_VAPP_CAL_DELETE);

    if (buffer->src_id != SRV_TDL_EVENT_SOURCE_LOCAL)
    {
        opList->removeItem(opList->getItemById(0));

        opList->addItem(1, (VfxResId)STR_ID_VAPP_CAL_CANCEL);
    }

    opList->m_signalMenuCallback.connect(this, &VappCalMainViewPage::onOptionListClicked);
    opList->show(VFX_TRUE);


    VFX_FREE_MEM(buffer);

    m_opListWeakPtr = opList;
}

void VappCalMainViewPage::onOptionListClicked(VcpMenuPopup* sender, VcpMenuPopupEventEnum evtEnum, VcpMenuPopupItem* item)
{
    if (evtEnum == VCP_MENU_POPUP_EVENT_ITEM_SELECTED && item->getId() == 0)
    {
        srv_tdl_event_struct *buffer;
        VFX_ALLOC_MEM(buffer,sizeof(srv_tdl_event_struct),this);
        srv_tdl_event_id_struct* eventBuffer = m_dailyMenu->GetEventbuffer();
        srv_tdl_event_get(
                    buffer, 
                    sizeof(srv_tdl_event_struct), 
                    (eventBuffer + m_selIdx)->source_id,
                    (eventBuffer + m_selIdx)->event_id);


        VcpConfirmPopup *confirmPopup;
        VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, this);
        confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
        confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        confirmPopup->setCustomButton(
                            (VfxResId)STR_ID_VAPP_CAL_DELETE,
                            (VfxResId)STR_ID_VAPP_CAL_CANCEL,
                            VCP_POPUP_BUTTON_TYPE_WARNING,
                            VCP_POPUP_BUTTON_TYPE_CANCEL);
        if (!buffer->repeat.rule)
        {
            confirmPopup->setText((VfxResId)STR_ID_VAPP_CAL_DELETE_EVENT_ASK);
        }
        else
        {
            confirmPopup->setText((VfxResId)STR_ID_VAPP_CAL_DELETE_ALL_REPEAT_ASK);
        }
        VFX_FREE_MEM(buffer);

        confirmPopup->setAutoDestory(VFX_TRUE);    
        confirmPopup->m_signalButtonClicked.connect(this, &VappCalMainViewPage::onLongPressDelConfirm);
        confirmPopup->show(VFX_TRUE);

        m_confirmPopupWeakPtr = confirmPopup;
    }
}


void VappCalMainViewPage::onLongPressDelConfirm(VfxObject* sender, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {

        srv_tdl_event_id_struct* eventBuffer = m_dailyMenu->GetEventbuffer();
        srv_tdl_event_delete((eventBuffer + m_selIdx)->source_id,(eventBuffer + m_selIdx)->event_id);

    }
}


void VappCalMainViewPage::onJumpToDateClicked(VfxObject* sender, VfxId id)
{
    m_typeSelected = m_viewType + VappCalViwerSwitchBar::VAPP_CAL_SWITCH_TYPE_MONTH;

    if (id == VAPP_CAL_DATE_PICKER_POPUP_BTN_LEFT)
    {
        // today
        m_highlightDT.setCurrentTime();
    }
    else if (id == VAPP_CAL_DATE_PICKER_POPUP_BTN_RIGHT)
    {
        // go to date
        VappCalDatePickerPopup *picker = (VappCalDatePickerPopup *)sender;
        VcpDatePickerStruct date;
        date = picker->m_datePicker->getDate();
        m_highlightDT.setDate(date.year, date.month, date.day);
    }

    enterNewViewMode();
}


void VappCalMainViewPage::onTimeLineStart(VfxBaseTimeline *timeline)
{
    m_nActiveTimeline++;
}

void VappCalMainViewPage::onTimeLineStop(VfxBaseTimeline *timeline, VfxBool is_stop)
{
    if (!is_stop)
    {
        return;
    }

    if (m_nActiveTimeline > 0)
    {
        m_nActiveTimeline--;
    }

    if (timeline == m_timeLine)
    {

        VFX_OBJ_CLOSE(m_menuFrame);
        updateArrowState();
    }
    else if (timeline == m_timeLine2)
    {
        VFX_ASSERT(!m_menuFrame);
        m_menuFrame = m_menuFrame2;
        m_menuFrame2 = NULL;

        switch(m_viewType)
        {
            case VAPP_CAL_MONTHLY_VIEW:
            {
                m_menuFrame->setPos(0, VAPP_CAL_MONTHLY_WEEK_BAR_HEIGHT);

            }
                break;

            default:
                break;
        }

        checkImageButton();

    }
    else
    {
        VFX_ASSERT(0);
    }
}

VfxBool VappCalMainViewPage::computeNextDateTime(VfxBool is_next)
{
    applib_time_struct currTime, incTime, resultTime;

    memset(&incTime, 0, sizeof(applib_time_struct));
    currTime = m_highlightDT.getDateTime();

    switch(m_viewType)
    {
        case VAPP_CAL_MONTHLY_VIEW:
            incTime.nMonth = 1;
            break;
        case VAPP_CAL_WEEKLY_VIEW:
            incTime.nDay= 7;
            break;
        case VAPP_CAL_DAILY_VIEW:
            incTime.nDay = 1;
            break;
        default:
            break;
    }

    if (is_next)
    {
        IncrementTime(currTime, incTime, &resultTime);
    }
    else
    {
        DecrementTime(currTime, incTime, &resultTime);
    }

    if (m_viewType == VAPP_CAL_MONTHLY_VIEW)
    {
        resultTime.nDay = 1;
    }

    if (m_viewType == VAPP_CAL_WEEKLY_VIEW)
    {
        if (resultTime.nYear == VAPP_CAL_MIN_YEAR - 1)
        {
            if (1 == applib_dt_get_week_number(&resultTime))
            {
                resultTime.nYear = VAPP_CAL_MIN_YEAR;
                resultTime.nMonth = 1;
                resultTime.nDay = 1;
            }
            else if (52 == applib_dt_get_week_number(&resultTime))
            {
                resultTime.nYear = VAPP_CAL_MIN_YEAR;
                resultTime.nMonth = 1;
                resultTime.nDay = 1;
                m_highlightDT.setDateTime(&resultTime);
                return VFX_FALSE;

            }

        }
        else if (resultTime.nYear == VAPP_CAL_MAX_YEAR + 1)
        {
            if (1 == applib_dt_get_week_number(&resultTime))
            {
                resultTime.nYear = VAPP_CAL_MAX_YEAR;
                resultTime.nMonth = 12;
                resultTime.nDay = 31;
            }
            else if (2 == applib_dt_get_week_number(&resultTime))
            {
                resultTime.nYear = VAPP_CAL_MAX_YEAR;
                resultTime.nMonth = 12;
                resultTime.nDay = 31;
                m_highlightDT.setDateTime(&resultTime);
                return VFX_FALSE;
            }

        }

    }
    else if (resultTime.nYear > VAPP_CAL_MAX_YEAR || resultTime.nYear < VAPP_CAL_MIN_YEAR)
    {
        return VFX_FALSE;
    }

    m_highlightDT.setDateTime(&resultTime);
    return VFX_TRUE;
}


void  VappCalMainViewPage::updateArrowState()
{
    VfxBool isNextDisable = VFX_FALSE, isPreDisable = VFX_FALSE;

    switch(m_viewType)
    {
        case VAPP_CAL_MONTHLY_VIEW:
        {
            if (m_highlightDT.getYear() == VAPP_CAL_MAX_YEAR && m_highlightDT.getMonth() == 12)
            {
                isNextDisable = VFX_TRUE;
            }
            else
            {
                isNextDisable = VFX_FALSE;
            }

            if (m_highlightDT.getYear() == VAPP_CAL_MIN_YEAR && m_highlightDT.getMonth() == 1)
            {
                isPreDisable = VFX_TRUE;
            }
            else
            {
                isPreDisable = VFX_FALSE;
            }
            break;
        }

        case VAPP_CAL_WEEKLY_VIEW:
        {

            VfxU8 week;
            applib_time_struct applib_time = {0};
            applib_time = m_highlightDT.getDateTime();
            
            week = applib_dt_get_week_number(&applib_time);

            if (week == 53 && m_highlightDT.getYear() == VAPP_CAL_MAX_YEAR)
            {
                isNextDisable = VFX_TRUE;
            }
            else if (week == 1 && m_highlightDT.getYear() == VAPP_CAL_MAX_YEAR && m_highlightDT.getMonth() == 12)
            {
                isNextDisable = VFX_TRUE;
            }
            else
            {
                isNextDisable = VFX_FALSE;
            }

            if (week == 1 && m_highlightDT.getYear() == VAPP_CAL_MIN_YEAR)
            {
                isPreDisable = VFX_TRUE;	
            }
            else
            {
                isPreDisable = VFX_FALSE;	
            }
            break;
        }

        case VAPP_CAL_DAILY_VIEW:
        {
            if (m_highlightDT.getDay() == 31 && m_highlightDT.getYear() == VAPP_CAL_MAX_YEAR
            && m_highlightDT.getMonth() == 12)
            {
                isNextDisable = VFX_TRUE;
            }
            else
            {
                isNextDisable = VFX_FALSE;
            }

            if (m_highlightDT.getDay() == 1 && m_highlightDT.getYear() == VAPP_CAL_MIN_YEAR
            && m_highlightDT.getMonth() == 1)
            {
                isPreDisable = VFX_TRUE;	
            }
            else
            {
                isPreDisable = VFX_FALSE;	
            }
            break;
        }

        default:
            break;
    }

    if (isNextDisable)
    {
        m_nextButton->setIsDisabled(VFX_TRUE);
        m_nextButton->setOpacity(0.3f);
    }
    else
    {
        m_nextButton->setIsDisabled(VFX_FALSE);
        m_nextButton->setOpacity(1);
    }

    if (isPreDisable)
    {
        m_preButton->setIsDisabled(VFX_TRUE);
        m_preButton->setOpacity(0.3f);
    }
    else
    {
        m_preButton->setIsDisabled(VFX_FALSE);
        m_preButton->setOpacity(1);
    }
}


void VappCalMainViewPage::updateTitle()
{
//VfxBool isNextDisable = VFX_FALSE, isPreDisable = VFX_FALSE;

    switch(m_viewType)
    {
        case VAPP_CAL_MONTHLY_VIEW:
        {
            m_titleLunar->setHidden(VFX_FALSE);

            VfxU32 flags;
            flags = VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_YEAR 
                    | VFX_DATE_TIME_FORMAT_MONTH_ENGLISH_ABBR;

            m_titleSolar->setString(m_highlightDT.getDateTimeString(flags));

            if (IsChineseSet())
            {
                m_titleLunar->setHidden(VFX_FALSE);

                m_titleSolar->setPos(
                            m_topTxBg->getSize().width / 2, 
                            m_topTxBg->getSize().height * 0.3f);

                m_titleLunar->setPos(
                        m_topTxBg->getSize().width / 2,
                        (m_topTxBg->getSize().height >> 1) + (m_titleSolar->getPos().y));


                updateTitleLunarStr();
            }
            else
            {
                m_titleLunar->setHidden(VFX_TRUE);

                m_titleSolar->setPos(
                m_topTxBg->getSize().width / 2, 
                m_topTxBg->getSize().height / 2);	
            }

            break;
        }
        case VAPP_CAL_WEEKLY_VIEW:
        {
            m_titleLunar->setHidden(VFX_TRUE);

            VfxWChar dTStr[15] = {0};
            VfxU8 week;
            VfxU8 indexofhightlightTime;
            applib_time_struct today;
            applib_time_struct endofweek;
            indexofhightlightTime = applib_dt_dow(m_highlightDT.getYear(),m_highlightDT.getMonth(),m_highlightDT.getDay());
            
            applib_time_struct applib_time = {0};
            applib_time = m_highlightDT.getDateTime();
            
            week = applib_dt_get_week_number(&applib_time);

            applib_time_struct incrementofDay;
            memset(&incrementofDay,0x00,sizeof(applib_time_struct));

            today = m_highlightDT.getDateTime();

            incrementofDay.nDay = 6 - indexofhightlightTime;

            applib_dt_increase_time(&today,
                            &incrementofDay,&endofweek);

            srv_setting_date_format_enum dateFormat = srv_setting_get_date_format();
            if(SETTING_DATE_FORMAT_YYYY_MM_DD == dateFormat)
            {
                kal_wsprintf(dTStr, "%d.Week %2d", endofweek.nYear,week);
            }
            else
            {
                kal_wsprintf(dTStr, "Week %2d.%d", week, endofweek.nYear);
            }
            m_titleSolar->setString(VFX_WSTR_MEM(dTStr));
            m_titleSolar->setPos(
                        m_topTxBg->getSize().width >> 1, 
                        m_topTxBg->getSize().height >> 1);

            VfxU8 dateArray[8] = {0};
            
            
            VappCalBaseMenu::getWeeklyDate(&applib_time, dateArray);
            VfxWChar dTStr2[3] = {0};
            for (VfxU8 i = 0; i < 7; i++)
            {
                kal_wsprintf(dTStr2, "%d", dateArray[i]);
                m_weeklydate[i]->setString(VFX_WSTR_MEM(dTStr2));
            }

            break;
        }
        case VAPP_CAL_DAILY_VIEW:
        {
            m_titleLunar->setHidden(VFX_TRUE);

            VfxU32 flags;
            flags = VFX_DATE_TIME_DATE_MASK;

            m_titleSolar->setString(m_highlightDT.getDateTimeString(flags));

            m_titleSolar->setPos(
                            m_topTxBg->getSize().width >> 1, 
                            m_topTxBg->getSize().height >> 1);

            m_dailyWeek->setString(m_highlightDT.getDateTimeString(VFX_DATE_TIME_DAY_NORMAL_NAME));

            if (IsChineseSet())
            {
                m_dailyLunar->setHidden(VFX_FALSE);
                updateTitleLunarStr();
            }
            else
            {
                m_dailyLunar->setHidden(VFX_TRUE);
            }


            break;
        }
        default:
            break;
    }


}

void VappCalMainViewPage::updateTitleLunarStr()
{
    if (!IsChineseSet())
    {
        return;
    }

    VfxWString lunarStr;

    VappCalUtility::getLunarStringByDate(m_highlightDT.getDateTime(), lunarStr);

    if (m_viewType == VAPP_CAL_MONTHLY_VIEW)
    {
        m_titleLunar->setString(lunarStr);
    }
    else if (m_viewType == VAPP_CAL_DAILY_VIEW)
    {
        m_dailyLunar->setString(lunarStr);
    }
}

void VappCalMainViewPage::updateHighlightBox(VfxId posIdx)
{
    if (m_viewType == VAPP_CAL_MONTHLY_VIEW)
    {
        VcpMenuPos cellPos(0, posIdx);
        VfxRect r = m_viewMenu->getLayout()->queryCellRect(cellPos);
        m_hightlightBox->setPos(r.origin.x + VAPP_CAL_MONTHLY_MENU_POS_X - 1, r.origin.y - 1);
        m_hightlightBox->setSize(VAPP_CAL_MONTHLY_HIGHLIGHT_BOX_WIDTH ,VAPP_CAL_MONTHLY_HIGHLIGHT_BOX_HEIGHT);
        if (posIdx%7 == 0)
        {
            m_hightlightBox->setPos(r.origin.x + VAPP_CAL_MONTHLY_MENU_POS_X - 1 + VAPP_CAL_MONTHLY_MENU_HIGHTLIGHTBOX_MODIFY_LEFT , r.origin.y - 1);
            m_hightlightBox->setSize(r.size.width- VAPP_CAL_MONTHLY_MENU_HIGHTLIGHTBOX_MODIFY,VAPP_CAL_MONTHLY_HIGHLIGHT_BOX_HEIGHT);
        }
        else if (posIdx%7 == 6)
        {
            m_hightlightBox->setSize(r.size.width- VAPP_CAL_MONTHLY_MENU_HIGHTLIGHTBOX_MODIFY ,VAPP_CAL_MONTHLY_HIGHLIGHT_BOX_HEIGHT);
        }
        if (posIdx / 7 == 5)
        {
            m_hightlightBox->setSize(VAPP_CAL_MONTHLY_HIGHLIGHT_BOX_WIDTH,VAPP_CAL_MONTHLY_HIGHLIGHT_BOX_HEIGHT + VAPP_CAL_MONTHLY_MENU_HIGHTLIGHTBOX_HEIGHT_MODIFY);
            if (posIdx%7 == 0)
            {
                m_hightlightBox->setPos(r.origin.x + VAPP_CAL_MONTHLY_MENU_POS_X - 1 + VAPP_CAL_MONTHLY_MENU_HIGHTLIGHTBOX_MODIFY_LEFT , r.origin.y - 1);
                m_hightlightBox->setSize(r.size.width - VAPP_CAL_MONTHLY_MENU_HIGHTLIGHTBOX_MODIFY,VAPP_CAL_MONTHLY_HIGHLIGHT_BOX_HEIGHT + VAPP_CAL_MONTHLY_MENU_HIGHTLIGHTBOX_HEIGHT_MODIFY);

            }
            else if (posIdx%7 == 6)
            {
                m_hightlightBox->setSize(r.size.width- VAPP_CAL_MONTHLY_MENU_HIGHTLIGHTBOX_MODIFY ,VAPP_CAL_MONTHLY_HIGHLIGHT_BOX_HEIGHT + VAPP_CAL_MONTHLY_MENU_HIGHTLIGHTBOX_HEIGHT_MODIFY);

            }
        }
    }
    else if (m_viewType == VAPP_CAL_WEEKLY_VIEW)
    {
        VcpMenuPos cellPos(0, posIdx);
        VfxRect r = m_viewMenu->getLayout()->queryCellRect(cellPos);
        m_hightlightBox->setPos(r.origin.x, 0);
        m_hightlightBox->setSize(VAPP_CAL_WEEKLY_CELL_WIDTH + 1,VAPP_CAL_WEEKLY_WEEK_BAR_HEIGHT);
    }
    else
    {
        return;
    }
}

mmi_ret VappCalMainViewPage::updateEvtInfo(mmi_event_struct *param)
{
    VfxObject *obj = handleToObject((VfxObjHandle)param->user_data);
    if (obj == NULL)
    {
        return MMI_RET_OK;
    }
    VappCalMainViewPage *page = VFX_OBJ_DYNAMIC_CAST(obj, VappCalMainViewPage);
    if(page == NULL)
    {
        return MMI_RET_OK;
    }
    if(! page->isActive())
    {
        page->setDataChangeState(VFX_TRUE);
        return MMI_RET_OK;
    }
    page->enterNewViewMode();	
    return MMI_RET_OK;
}

void VappCalMainViewPage::setDataChangeState(VfxBool isMultiDelete)
{
    m_multiDelete = isMultiDelete;
}


VfxBool VappCalMainViewPage::getDataChangeState()
{
    return  m_multiDelete ;
}




void VappCalMainViewPage::createMenu(VfxFrame *parent)
{

    if(m_jobId > 0)
    {
        srv_tdl_event_search_end(m_jobId);
        mmi_frm_cb_dereg_event(EVT_ID_SRV_TDL_EVENT_SEARCH, &VappCalMainViewPage::onEventReady, getObjHandle());
        m_jobId = -1;
    }
    if(m_eventbuffer)
    {
        VFX_FREE_MEM(m_eventbuffer);
    }

    srv_tdl_search_filter_struct search_info;
    applib_time_struct curr_date;
    
    applib_time_struct applib_time = {0};
    applib_time = m_highlightDT.getDateTime();
    memcpy(&curr_date, &applib_time, sizeof(applib_time_struct));
    curr_date.nHour = 0;
    curr_date.nMin = 0;
    curr_date.nSec = 0;


    if (m_viewType == VAPP_CAL_MONTHLY_VIEW)
    {
        search_info.type = SRV_TDL_SEARCH_TYPE_MONTHLY;
        memcpy(&search_info.u.date_time, &curr_date, sizeof(applib_time_struct));
        srv_tdl_set_source_state(MMI_TRUE, SRV_TDL_EVENT_SOURCE_TOTAL);	
        m_jobId = srv_tdl_event_search_begin(&search_info, SRV_TDL_EVENT_SORT_START_TIME,SRV_TDL_EVENT_SOURCE_TOTAL);
        if (m_jobId > 0)
        {
            mmi_frm_cb_reg_event(EVT_ID_SRV_TDL_EVENT_SEARCH, &VappCalMainViewPage::onEventReady, getObjHandle());
        }
        else
        { 
            VFX_ASSERT(0);
        }
    #ifndef __LOW_COST_SUPPORT_COMMON__
        if (m_evtInfoBoxWeakPtr.isValid())
        {
            VappCalDailyList *temp = m_evtInfoBoxWeakPtr.get();
            VFX_OBJ_CLOSE(temp);
        }
   #endif
        VFX_OBJ_CREATE_EX(
                m_viewMenu, 
                VappCalBaseMenu,
                parent, 
                (VAPP_CAL_MONTHLY_VIEW,
                m_highlightDT.getDateTime()));

        m_viewMenu->setBgColor(VfxColor(0, 128, 128, 128));
        m_viewMenu->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_viewMenu->setPos(VAPP_CAL_MONTHLY_MENU_POS_X, 0);
        m_viewMenu->setSize(parent->getSize().width, parent->getSize().height);
        m_viewMenu->m_signalCellClicked.connect(this, &VappCalMainViewPage::onMonthlyMenuClick);

        VFX_OBJ_CREATE(m_hightlightBox, VfxImageFrame, parent);
        m_hightlightBox->setResId(IMG_ID_VAPP_CAL_DAY_SELECT);
        m_hightlightBox->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_hightlightBox->setSize(
                        VAPP_CAL_MONTHLY_HIGHLIGHT_BOX_WIDTH, 
                        VAPP_CAL_MONTHLY_HIGHLIGHT_BOX_HEIGHT);
        VfxU16 posIdx;
        applib_time_struct applib_time = {0};
        applib_time = m_highlightDT.getDateTime();
        posIdx = m_viewMenu->computeDate2Pos(&applib_time);
        updateHighlightBox(posIdx);
    }
    else if (m_viewType == VAPP_CAL_WEEKLY_VIEW)
    {

        search_info.type = SRV_TDL_SEARCH_TYPE_WEEKLY;
        memcpy(&search_info.u.weekly_search.date_time, &curr_date, sizeof(applib_time_struct));
        search_info.u.weekly_search.start_day_of_week = SRV_TDL_START_DAY_SUN;


        m_jobId = srv_tdl_event_search_begin(&search_info, SRV_TDL_EVENT_SORT_START_TIME,SRV_TDL_EVENT_SOURCE_TOTAL);
        if(m_jobId > 0)
        {
            mmi_frm_cb_reg_event(EVT_ID_SRV_TDL_EVENT_SEARCH, &VappCalMainViewPage::onEventReady, getObjHandle());
        }
        else
        { 
            VFX_ASSERT(0);
        }

        VFX_OBJ_CREATE_EX(
                    m_viewMenu, 
                    VappCalBaseMenu,
                    parent, 
                    (VAPP_CAL_WEEKLY_VIEW,
                    m_highlightDT.getDateTime()));
        m_viewMenu->setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
        m_viewMenu->setPos(0, 1);
        m_viewMenu->setSize(parent->getSize().width, parent->getSize().height);
        m_viewMenu->m_signalCellClicked.connect(this, &VappCalMainViewPage::onWeeklyMenuClick);
    }
    else if (m_viewType == VAPP_CAL_DAILY_VIEW)
    {
        VFX_OBJ_CREATE_EX(
                    m_dailyMenu, 
                    VappCalDailyList,
                    parent, 
                    (VAPP_CAL_DAILY_VIEW, m_highlightDT.getDateTime()));

        m_dailyMenu->setShadowIsDisabled(VFX_TRUE);
        m_dailyMenu->setContentProvider((IVcpListMenuContentProvider*)m_dailyMenu);	
        m_dailyMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_TRIPLE_TEXT_EX);
        m_dailyMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL);	
        m_dailyMenu->setPos(0, 0);
        m_dailyMenu->setSize(parent->getSize().width, parent->getSize().height);
        m_dailyMenu->m_signalItemTapped.connect(this, &VappCalMainViewPage::onDailyMenuClick);
        m_dailyMenu->m_signalItemLongTapped.connect(this, &VappCalMainViewPage::onDailyMenuLongTap);

    }
    else
    {
        VFX_ASSERT(0);
    }
}

/***************************************************************************** 
 * Class VappCalBaseMenu
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappCalBaseMenu", VappCalBaseMenu, VcpBaseMenu);
void VappCalBaseMenu::onInit()
{
    VcpBaseMenu::onInit();

    enableVerticalScrollIndicator(VFX_FALSE);

    if (m_viewType == VappCalMainViewPage::VAPP_CAL_MONTHLY_VIEW)
    {
        setMonthlyCellDisable();
    }
    memset(m_isExistEvt, 0, sizeof(m_isExistEvt));	

}



void VappCalBaseMenu::updateEvtFlag(srv_tdl_event_id_struct* m_eventbuffer, VfxU32 m_count)
{
    if (m_viewType == VappCalMainViewPage::VAPP_CAL_MONTHLY_VIEW)
    {
        setMonthlyCellEvtFlag(m_eventbuffer, m_count);

    }
    else if (m_viewType == VappCalMainViewPage::VAPP_CAL_WEEKLY_VIEW)
    {
        setWeeklyCellEvtFlag(m_eventbuffer, m_count); 
    }
}



void VappCalBaseMenu::updateChangedCell(srv_tdl_event_id_struct* m_eventbuffer, VfxU32 m_count)
{
    if (m_viewType != VappCalMainViewPage::VAPP_CAL_MONTHLY_VIEW &&
        m_viewType != VappCalMainViewPage::VAPP_CAL_WEEKLY_VIEW)
    {
        return;
    }

    VfxBool *buffer;
    VfxU32 len = (sizeof(VfxBool) * VAPP_CAL_WEEKLY_ROW * VAPP_CAL_WEEKLY_COLUMN);

    VFX_ALLOC_MEM(buffer, len, this);
    memcpy(buffer, m_isExistEvt, len);


    updateEvtFlag(m_eventbuffer, m_count);


    if (m_viewType == VappCalMainViewPage::VAPP_CAL_WEEKLY_VIEW)
    {
        len = VAPP_CAL_WEEKLY_ROW * VAPP_CAL_WEEKLY_COLUMN;
    }
    else
    {
        len = VAPP_CAL_MONTHLY_ROW * VAPP_CAL_MONTHLY_COLUMN;
    }

    for (VfxU32 i = 0; i < len; i++)
    {
        if (buffer[i] != m_isExistEvt[i])
        {
            VfxU32 flag = 0;

            VfxFrame *cell = getCell(VcpMenuPos(0, i), flag);
            VfxRect rec = cell->getRect();
            VFX_OBJ_CLOSE(cell);

            updateCell(rec, VcpMenuPos(0, i), flag);
        }
    }

    VFX_FREE_MEM(buffer);
}

VcpBaseMenuLayout* VappCalBaseMenu::createLayout()
{
    VappCalBaseLayout* layout;
    VFX_OBJ_CREATE_EX(layout, VappCalBaseLayout, this, (this));
    return layout;
}

VfxFrame* VappCalBaseMenu::createCell(VfxS32 group, VfxS32 pos)
{
    if (m_viewType == VappCalMainViewPage::VAPP_CAL_MONTHLY_VIEW)
    {
        VappCalMonthlyCell *cell;
        VFX_OBJ_CREATE_EX(cell, VappCalMonthlyCell, this, (pos));
        return cell;

    }
    else if (m_viewType == VappCalMainViewPage::VAPP_CAL_WEEKLY_VIEW)
    {
        VappCalWeeklyCell *cell;
        VFX_OBJ_CREATE_EX(cell, VappCalWeeklyCell, this, (pos));
        return cell;
    }
    else
    {   
        return NULL;
    }
}

void VappCalBaseMenu::onAfterCreateLayout()
{ 
    if (m_viewType == VappCalMainViewPage::VAPP_CAL_WEEKLY_VIEW)
    {
    //makeVisible(VcpMenuPos(0, VAPP_CAL_WEEKLY_COLUMN * 8), VFX_TRUE);
        VfxRect rect;
        rect = getLayout()->queryCellRect(VcpMenuPos(0, VAPP_CAL_WEEKLY_COLUMN * 9));


        //VfxRect VappCalBaseLayout::queryCellRect(VcpMenuPos pos)
        rect.size = ((VfxFrame*)getParent())->getSize();


        makeVisible(rect, VFX_TRUE);

    }
}  
  

void VappCalBaseMenu::onTouchCell(
                            VcpMenuPos cellPos,     
                            CellTouchTypeEnum touchType,   
                            VfxPoint pt,         
                            VfxFrame *cell)
{
    if (TouchDown != touchType)
    {
        return;
    }

    m_signalCellClicked.postEmit(this, cellPos.pos);
}

void VappCalBaseMenu::onUpdateCell(
                            const VfxRect &rect,   
                            VfxS32 group,          
                            VfxS32 pos,             
                            VfxFrame* cell,         
                            VfxU32 flag)
{ 
    cell->setRect(rect);

    if (m_viewType == VappCalMainViewPage::VAPP_CAL_MONTHLY_VIEW)
    {
        VappCalMonthlyCell* item = (VappCalMonthlyCell*) cell;
        item->setEvtExist(m_isExistEvt[pos]);
        item->setDisabled(m_isDisabled[pos]);
        item->setDate(m_day[pos]);
        item->setToday(checkCellIsToday(pos));
        //item->releaseAllChild();
        item->onUpdate();
    }
    else if (m_viewType == VappCalMainViewPage::VAPP_CAL_WEEKLY_VIEW)
    {
        if (pos % VAPP_CAL_WEEKLY_COLUMN == 0)
        {
            return;
        }
        else
        {
            VappCalWeeklyCell* item = (VappCalWeeklyCell*) cell;
            item->setEvtExist(m_isExistEvt[pos]);
            item->onUpdate();
        }
    }
}

void VappCalBaseMenu::onCloseCell(
                        VfxS32 group,           
                        VfxS32 pos,             
                        VfxFrame* cellFrame)
{
    VFX_OBJ_CLOSE(cellFrame);
}



void VappCalBaseMenu::setMonthlyCellEvtFlag(srv_tdl_event_id_struct* m_eventbuffer, VfxU32 m_count)

{
    memset(m_isExistEvt, 0, sizeof(m_isExistEvt));

    if((m_eventbuffer == NULL)||(m_count == 0))
    {
        return;
    }


    VfxU8 startIdx;
    for (startIdx = 0; startIdx < VAPP_CAL_MONTHLY_ROW * VAPP_CAL_MONTHLY_COLUMN; startIdx++)
    {
        if (!m_isDisabled[startIdx])
        {
            break;
        }
    }

    VfxBool *ptr = &m_isExistEvt[startIdx];

    VfxU16 index = 0;
    
    VfxU8 j = 0;
    VfxU8 dow_to_set = 0;
    VfxU8 dow_of_task = 0;
    VfxBool is_same_month;
    applib_time_struct start_time;
    applib_time_struct curr_date;

    memcpy(&curr_date, &m_dateTime, sizeof(applib_time_struct));
    curr_date.nHour = 0;
    curr_date.nMin = 0;
    curr_date.nSec = 0;



    srv_tdl_event_struct *pevent;
    VFX_ALLOC_MEM(pevent,sizeof(srv_tdl_event_struct),this);
    for (VfxU32 i = 0; i < m_count; i++)
    {
        srv_tdl_event_get(
                    pevent, 
                    sizeof(srv_tdl_event_struct), 
                    m_eventbuffer[i].source_id,
                    m_eventbuffer[i].event_id);

                                                
        memcpy(&start_time, &(pevent->start_time), sizeof(applib_time_struct));

        if ((curr_date.nMonth == start_time.nMonth) && 
        (curr_date.nYear == start_time.nYear))
        {
            is_same_month = VFX_TRUE;
        }
        else
        {
            is_same_month = VFX_FALSE;
        }

        switch (pevent->repeat.rule)
        {
            case VAPP_CAL_REPEAT_NEVER:
                curr_date.nDay = 1;
                if (is_same_month == VFX_TRUE)
                {
                    if ((start_time.nMonth == pevent->end_time.nMonth) && 
                    (start_time.nYear == pevent->end_time.nYear))
                    {
                        for (j = start_time.nDay; j <= pevent->end_time.nDay; j++)
                        {
                            ptr[j - 1] = VFX_TRUE;
                        }
                    }
                    else if (CompareTime(pevent->end_time, pevent->start_time, NULL))
                    {
                        for (j = start_time.nDay; j <= VAPP_CAL_MAX_DAYS_PER_MONTH; j++)
                        {
                            ptr[j - 1] = VFX_TRUE;
                        }
                    }
                                               
                }
                else if (CompareTime(curr_date, start_time, NULL) > 0 && 
                         CompareTime(pevent->end_time, curr_date, NULL) >= 0)
                {
                    if (curr_date.nMonth == pevent->end_time.nMonth && 
                        curr_date.nYear == pevent->end_time.nYear)
                    {
                        for (j = 1; j <= pevent->end_time.nDay; j++)
                        {
                            ptr[j - 1] = VFX_TRUE;
                        }
                    }
                    else
                    {
                        for (j = 1; j <= VAPP_CAL_MAX_DAYS_PER_MONTH; j++)
                        {
                            ptr[j - 1] = VFX_TRUE;
                        }
                    }
                }
                break;

            case VAPP_CAL_REPEAT_DAILY:
                if (FindMaxTime(&curr_date, &(start_time)) && is_same_month == VFX_FALSE)
                {
                    j = 1;
                }
                else if (is_same_month == VFX_TRUE)
                {
                    j = start_time.nDay;
                }
                else
                {
                    break;
                }
                for (; j <= VAPP_CAL_MAX_DAYS_PER_MONTH; j++)
                {
                    ptr[j - 1] = VFX_TRUE;
                }
                break;
                
            case VAPP_CAL_REPEAT_WEEKDAY:
                if (is_same_month == VFX_TRUE)
                {
                    dow_of_task = DOW(start_time.nYear, start_time.nMonth, start_time.nDay);
                    for (j = 0; j < VAPP_CAL_MAX_DAYS_PER_WEEK; j++)
                    {
                        if (pevent->repeat.dows & GetWeekDayMASK(j))
                        {
                            if (dow_of_task == j)
                            {
                                dow_to_set = start_time.nDay;
                            }
                            else if (dow_of_task < j)
                            {
                                dow_to_set = start_time.nDay + j - dow_of_task;
                            }
                            else
                            {
                                dow_to_set = 
                                    start_time.nDay + j - dow_of_task + VAPP_CAL_MAX_DAYS_PER_WEEK;
                            }

                            while (dow_to_set <= VAPP_CAL_MAX_DAYS_PER_MONTH)
                            {
                                ptr[dow_to_set - 1] = VFX_TRUE;
                                dow_to_set = dow_to_set + VAPP_CAL_MAX_DAYS_PER_WEEK;
                            }
                        }
                    }
                }
                else if (FindMaxTime(&curr_date, &(start_time)))
                {
                    dow_of_task = DOW(curr_date.nYear, curr_date.nMonth, 1);
                    for (j = 0; j < VAPP_CAL_MAX_DAYS_PER_WEEK; j++)
                    {
                        if (pevent->repeat.dows & GetWeekDayMASK(j))
                        {
                            if (dow_of_task == j)
                            {
                                dow_to_set = 1;
                            }
                            else if (dow_of_task < j)
                            {
                                dow_to_set = 1 + j - dow_of_task;
                            }
                            else
                            {
                                dow_to_set = 1 + j - dow_of_task + VAPP_CAL_MAX_DAYS_PER_WEEK;
                            }

                            while (dow_to_set <= VAPP_CAL_MAX_DAYS_PER_MONTH)
                            {
                                ptr[dow_to_set - 1] = VFX_TRUE;                
                                dow_to_set = dow_to_set + VAPP_CAL_MAX_DAYS_PER_WEEK;
                            }
                        }
                    }
                }

                break;

            case VAPP_CAL_REPEAT_WEEKLY:
                if (is_same_month == VFX_TRUE || FindMaxTime(&curr_date, &start_time))
                {
                    j = DOW(start_time.nYear, start_time.nMonth, start_time.nDay);

                    dow_of_task = DOW(curr_date.nYear, curr_date.nMonth, 1);

                    if (dow_of_task == j)
                    {
                        dow_to_set = 1;
                    }
                    else if (dow_of_task < j)
                    {
                        dow_to_set = 1 + j - dow_of_task;
                    }
                    else
                    {
                        dow_to_set = 1 + j - dow_of_task + VAPP_CAL_MAX_DAYS_PER_WEEK;
                    }

                    if (is_same_month == MMI_TRUE)
                    {
                        while (dow_to_set < start_time.nDay)
                        {
                            dow_to_set = dow_to_set + VAPP_CAL_MAX_DAYS_PER_WEEK;
                        }
                    }

                    while (dow_to_set <= VAPP_CAL_MAX_DAYS_PER_MONTH)
                    {
                        ptr[dow_to_set - 1] = VFX_TRUE;                 
                        dow_to_set = dow_to_set + VAPP_CAL_MAX_DAYS_PER_WEEK;
                    }
                }
                break;

            case VAPP_CAL_REPEAT_MONTHLY:
                if (is_same_month == VFX_TRUE || FindMaxTime(&curr_date, &start_time))
                {
                    index = start_time.nDay;
                    ptr[index - 1] = VFX_TRUE;
                }
                break;
                
            case VAPP_CAL_REPEAT_YEARLY:
                if (is_same_month == VFX_TRUE || 
                    (FindMaxTime(&curr_date, &start_time) && 
                    curr_date.nMonth == start_time.nMonth))
                {
                    index = start_time.nDay;
                    ptr[index - 1] = VFX_TRUE;        
                }
                break;
            default:
                break;
        }   /* End of switch */
    }   /* if Present */

    VFX_FREE_MEM(pevent);

}



void VappCalBaseMenu::setWeeklyCellEvtFlag(srv_tdl_event_id_struct* m_eventbuffer, VfxU32 m_count)
{
    memset(m_isExistEvt, 0, sizeof(m_isExistEvt));

    if((m_eventbuffer == NULL)||(m_count == 0))
        return;

    VfxU8 dow_to_set;
    VfxBool is_same_week;
    VfxS8 dow_of_event = 0;
    
    applib_time_struct *curr_date, start_time, curr_week_begin, next_week_begin, inc_time;

    curr_date = &m_dateTime;


     
    getFirstDayOfWeek(curr_date, &curr_week_begin);

    memset(&inc_time, 0, sizeof(applib_time_struct));
    inc_time.nDay = VAPP_CAL_MAX_DAYS_PER_WEEK;

    applib_dt_increase_time(
                        (applib_time_struct*)&curr_week_begin,
                        (applib_time_struct*)&inc_time,
                        (applib_time_struct*)&next_week_begin);

    //if it is the beyond the max time, set the next_week_begin to the max time
    applib_time_struct the_max_time;
    memset((void*)&the_max_time,0,sizeof(applib_time_struct));
    the_max_time.nYear = 2031;
    the_max_time.nMonth = 1;
    the_max_time.nDay = 1;

    if(!(applib_dt_compare_time( &the_max_time,&next_week_begin,NULL) == DT_TIME_GREATER) )
    {
        memcpy((void*)&next_week_begin,(void*)&the_max_time,sizeof(applib_time_struct));      
    }


    srv_tdl_event_struct *pevent;
    VFX_ALLOC_MEM(pevent,sizeof(srv_tdl_event_struct),this);
    for (VfxU32 i = 0; i < m_count; i++)
    {
        srv_tdl_event_get(
                pevent, 
                sizeof(srv_tdl_event_struct), 
                m_eventbuffer[i].source_id,
                m_eventbuffer[i].event_id);

        if (pevent->present == 1)
        {
            memcpy(&start_time, &(pevent->start_time), sizeof(applib_time_struct));
            if (applib_dt_compare_time(
                    (applib_time_struct*)&start_time, 
                    (applib_time_struct*)&curr_week_begin, 
                    NULL) >= DT_TIME_EQUAL &&
                applib_dt_compare_time(
                    (applib_time_struct*)&start_time,
                    (applib_time_struct*)&next_week_begin,
                    NULL) == DT_TIME_LESS)
            {
                is_same_week = VFX_TRUE;
            }
            else
            {
                is_same_week = VFX_FALSE;
            }
            switch (pevent->repeat.rule)
            {
                case VAPP_CAL_REPEAT_NEVER:
                    /* the pevent's start time is during this week */
                    if (is_same_week)
                    {
                        dow_to_set = applib_dt_dow(
                                                pevent->start_time.nYear, 
                                                pevent->start_time.nMonth, 
                                                pevent->start_time.nDay);
                        setWeeklyCellEvtFlagInt(
                                        (void *)pevent, 
                                        dow_to_set, 
                                        VFX_FALSE);
                    }
                    /* Start time is earlier than this week */
                    else if (CompareTime(pevent->start_time, curr_week_begin, NULL) < DT_TIME_EQUAL)
                    {
                        /* End time is later than next week begin. */
                        if (CompareTime(pevent->end_time, next_week_begin, NULL) > DT_TIME_EQUAL)
                        {
                            dow_to_set = 0xff;
                        }
                        /* End time is later than this week begin. */
                        else if (CompareTime(pevent->end_time, curr_week_begin, NULL) >= DT_TIME_EQUAL)
                        {
                            dow_to_set = applib_dt_dow(
                                            pevent->end_time.nYear, 
                                            pevent->end_time.nMonth, 
                                            pevent->end_time.nDay);
                        }
                        /* End time is before current week. */
                        else    
                        {
                            continue;
                        }
                        setWeeklyCellEvtFlagInt(
                                        pevent, 
                                        dow_to_set, 
                                        MMI_TRUE);
                    }
                    break;

                case VAPP_CAL_REPEAT_DAILY:
                {
                    /* Start time is earlier than this week */
                    if (FindMaxTime(&curr_week_begin, &(start_time)))
                    {
                        dow_to_set = 0;
                    }
                    /* Start time is in this week */
                    else if (is_same_week)
                    {
                        dow_to_set = applib_dt_dow(
                                            start_time.nYear, 
                                            start_time.nMonth, 
                                            start_time.nDay);
                    }
                    else
                    {
                        break;
                    }

                    VfxU8 the_max_day_index;
                    VfxU8 indexofday = applib_dt_dow(next_week_begin.nYear,next_week_begin.nMonth,next_week_begin.nDay);
                    if(indexofday == 0)
                    {
                        the_max_day_index = VAPP_CAL_MAX_DAYS_PER_WEEK;
                    }
                    else
                    {
                        the_max_day_index = indexofday;
                    }
                    for (; dow_to_set < the_max_day_index; dow_to_set++)
                    {
                        setWeeklyCellEvtFlagInt(
                                        pevent, 
                                        dow_to_set, 
                                        MMI_FALSE);                    
                    }
                }
                    break;
                    
                case VAPP_CAL_REPEAT_WEEKDAY:
                {
                    dow_of_event = (S32)DOW(
                                        start_time.nYear, 
                                        start_time.nMonth, 
                                        start_time.nDay);
                                        
                    VfxU8 the_max_day_index;
                    VfxU8 indexofday = applib_dt_dow(next_week_begin.nYear,next_week_begin.nMonth,next_week_begin.nDay);
                    if(indexofday == 0)
                    {
                        the_max_day_index = VAPP_CAL_MAX_DAYS_PER_WEEK;
                    }
                    else
                    {
                        the_max_day_index = indexofday;
                    }
                                        
                    for (dow_to_set = 0; dow_to_set < the_max_day_index; dow_to_set++)
                    {
                        if (pevent->repeat.dows &  GetWeekDayMASK(dow_to_set))
                        {
                            /* 
                             * event's start time is in selected week and the repeat days is
                             * larger than event's week day || event's start time is before 
                             * selected week day.
                             */
                            if ((is_same_week == MMI_TRUE && dow_to_set >= dow_of_event) ||
                                (is_same_week == MMI_FALSE && FindMaxTime(curr_date, &start_time)))
                            {
                                setWeeklyCellEvtFlagInt(
                                                    pevent, 
                                                    dow_to_set, 
                                                    MMI_FALSE);                    
                            }
                        }
                    }
                }
                    break;

                case VAPP_CAL_REPEAT_WEEKLY:
                {
                    if (is_same_week == MMI_TRUE || FindMaxTime(curr_date, &start_time))
                    {                        
                        dow_to_set = DOW(
                                        start_time.nYear, 
                                        start_time.nMonth, 
                                        start_time.nDay);
                        VfxU8 indexofday = applib_dt_dow(next_week_begin.nYear,next_week_begin.nMonth,next_week_begin.nDay);
                        if((indexofday != 0)&&(dow_to_set >= indexofday))
                        {
                            break;
                        }

                        setWeeklyCellEvtFlagInt(
                                        pevent, 
                                        dow_to_set, 
                                        MMI_FALSE);                    
                    }
                }
                    break;
                    
                case VAPP_CAL_REPEAT_MONTHLY:
                {
                    if (is_same_week == MMI_TRUE || (FindMaxTime(curr_date, &start_time)))
                    {
                        for (dow_to_set = 1; 
                             dow_to_set <= VAPP_CAL_MAX_DAYS_PER_WEEK; 
                             dow_to_set++)
                        {
                            dow_of_event = next_week_begin.nDay - dow_to_set;
                            if (dow_of_event > 0 && dow_of_event == start_time.nDay)
                            {   
                                start_time.nYear = next_week_begin.nYear;
                                start_time.nMonth = next_week_begin.nMonth;
                                break;
                            }
                            else if (dow_of_event <= 0)
                            {
                                dow_of_event += applib_dt_last_day_of_mon(
                                                            curr_week_begin.nMonth, 
                                                            curr_week_begin.nYear);
                                                    
                                if (dow_of_event == start_time.nDay)
                                {
                                    start_time.nYear = curr_week_begin.nYear;
                                    start_time.nMonth = curr_week_begin.nMonth;
                                    break;
                                }                                    
                            }
                        }  
                        if (dow_to_set <= VAPP_CAL_MAX_DAYS_PER_WEEK)
                        {
                            dow_to_set = DOW(start_time.nYear, start_time.nMonth, start_time.nDay);
                            VfxU8 indexofday = applib_dt_dow(next_week_begin.nYear,next_week_begin.nMonth,next_week_begin.nDay);
                            if((indexofday != 0)&&(dow_to_set >= indexofday))
                            {
                                break;
                            }

                            setWeeklyCellEvtFlagInt(
                                                pevent, 
                                                dow_to_set, 
                                                MMI_FALSE);  
                        }
                    }
                }
                    break;
                    
                case VAPP_CAL_REPEAT_YEARLY:
                {
                    if (is_same_week == MMI_TRUE || (FindMaxTime(curr_date, &start_time)))
                    {
                        for (dow_to_set = 1; dow_to_set <= VAPP_CAL_MAX_DAYS_PER_WEEK; dow_to_set++)
                        {
                            dow_of_event = next_week_begin.nDay - dow_to_set;
                            if (dow_of_event > 0 && 
                                (dow_of_event == start_time.nDay && 
                                 next_week_begin.nMonth == start_time.nMonth))
                            {    
                                start_time.nYear = next_week_begin.nYear;
                                start_time.nMonth = next_week_begin.nMonth;	
                                break;
                            }
                            else if (dow_of_event <= 0)
                            {
                                dow_of_event += applib_dt_last_day_of_mon(
                                                    curr_week_begin.nMonth, 
                                                    curr_week_begin.nYear);
                                                    
                                if (dow_of_event == start_time.nDay && 
                                    curr_week_begin.nMonth == start_time.nMonth)
                                {
                                    start_time.nYear = curr_week_begin.nYear;
                                    start_time.nMonth = curr_week_begin.nMonth;
                                    break;
                                }                                    
                            }
                        }  
                        if (dow_to_set <= VAPP_CAL_MAX_DAYS_PER_WEEK)
                        {
                            dow_to_set = DOW(
                                            start_time.nYear, 
                                            start_time.nMonth, 
                                            start_time.nDay);

                            setWeeklyCellEvtFlagInt(
                                            pevent, 
                                            dow_to_set, 
                                            MMI_FALSE);
                        }
                    }
                    break;                              
                }
                   
                default:
                    break;
            }   /* End of switch */
        }   /* if Present */
    }   /* end of For Loop */
    VFX_FREE_MEM(pevent);

}

void VappCalBaseMenu::setMonthlyCellDisable()
{
    memset(m_isDisabled, 0, sizeof(m_isDisabled));	
    memset(m_day, 0, sizeof(m_day));	

    VfxS8 i;
    VfxU8 firstDayOfMonth;
    VfxU8 daysOfMonth, daysOfLMonth;
    VfxU8 nextDaysOfMonth;
    VfxU8 startIdx = 0;
    applib_time_struct curr_time;

    curr_time = m_dateTime;

    applib_time_struct incTime, lastMonth;
    memset(&incTime, 0, sizeof(applib_time_struct));
    incTime.nMonth = 1;
    DecrementTime(curr_time, incTime, &lastMonth);

    daysOfLMonth = LastDayOfMonth(lastMonth.nMonth, lastMonth.nYear);

    // Last month
    firstDayOfMonth = DOW(curr_time.nYear, curr_time.nMonth, 1);
    for (i = 0; i < firstDayOfMonth; i++)
    {
        m_isDisabled[i] = VFX_TRUE;
        m_day[i] = (daysOfLMonth - (firstDayOfMonth - 1) + i);
    }

    // This month
    daysOfMonth = LastDayOfMonth(curr_time.nMonth, curr_time.nYear);
    startIdx = firstDayOfMonth;
    for (i = 0; i < daysOfMonth; i++)
    {
        m_isDisabled[i + startIdx] = VFX_FALSE;
        m_day[i + startIdx] = i + 1;
    }

    // Next month
    nextDaysOfMonth = 
        VAPP_CAL_MONTHLY_ROW * VAPP_CAL_MONTHLY_COLUMN - (firstDayOfMonth + daysOfMonth);
    startIdx = firstDayOfMonth + daysOfMonth;
    for (i = 0; i < nextDaysOfMonth; i++)
    {
        m_isDisabled[i + startIdx] = VFX_TRUE;
        m_day[i + startIdx] = i + 1;
    }
}


VappCalMainViewPage::VappCalViewTypeEnum VappCalBaseMenu::getMenuViewType()
{
    return m_viewType;
}

VfxBool VappCalBaseMenu::checkCellIsWeekend(VfxU8 pos)
{
    VfxBool result = VFX_FALSE;
    if (m_viewType == VappCalMainViewPage::VAPP_CAL_MONTHLY_VIEW)
    {
        VfxU8 remainder = (pos % VAPP_CAL_MONTHLY_COLUMN);
        if (remainder == 5 || remainder == 6)
        {
            result = VFX_TRUE;
        }
        else
        {
            result = VFX_FALSE;
        }
    }
    else if (m_viewType == VappCalMainViewPage::VAPP_CAL_WEEKLY_VIEW)
    {

    }

    return result;
}

VfxBool VappCalBaseMenu::checkCellIsToday(VfxU8 pos)
{
    applib_time_struct today;
    VfxU8 firstDayOfMonth;
    GetDateTime(&today);
    firstDayOfMonth = DOW(today.nYear, today.nMonth, 1);

    if (m_dateTime.nYear == today.nYear && 
        m_dateTime.nMonth == today.nMonth &&
        pos == today.nDay + firstDayOfMonth - 1)
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
}
  
VfxS32 VappCalBaseMenu::computeDate2Pos(applib_time_struct *date)
{
    VfxS32 pos = 0;
    if (m_viewType == VappCalMainViewPage::VAPP_CAL_MONTHLY_VIEW)
    {
        VfxU8 firstDayOfMonth;

        firstDayOfMonth = DOW(date->nYear, date->nMonth, 1);
        pos = firstDayOfMonth + date->nDay - 1;

    }
    else if (m_viewType == VappCalMainViewPage::VAPP_CAL_WEEKLY_VIEW)
    {
        VfxU8 dow;
        dow = (U8)applib_dt_dow(date->nYear, date->nMonth, date->nDay);
        pos = dow + 1;
    }

    return pos;
}

void VappCalBaseMenu::computePos2Date(VfxS32 pos, applib_time_struct *date)
{
    if (m_viewType == VappCalMainViewPage::VAPP_CAL_MONTHLY_VIEW)
    {
        VfxU8 daysOfLMonth, firstDayOfMonth, daysOfMonth;
        applib_time_struct incTime, lastMonth, nextMonth;

        memset(&incTime, 0, sizeof(applib_time_struct));
        incTime.nMonth = 1;
        DecrementTime(*date, incTime, &lastMonth);
        IncrementTime(*date, incTime, &nextMonth);

        daysOfLMonth = LastDayOfMonth(lastMonth.nMonth, lastMonth.nYear);
        daysOfMonth	= LastDayOfMonth(date->nMonth, date->nYear);
        firstDayOfMonth = DOW(date->nYear, date->nMonth, 1);

        if ((VfxU8)pos >= firstDayOfMonth && pos <= daysOfMonth + firstDayOfMonth - 1)
        {
            date->nDay = (VfxU8)pos - firstDayOfMonth + 1;
        }
        else if ((VfxU8)pos < firstDayOfMonth)//(VfxU8)pos >= 0
        {
            *date = lastMonth;
            date->nDay = daysOfLMonth - firstDayOfMonth + (VfxU8)pos + 1;
        }
        else
        {
            *date = nextMonth;
            date->nDay = (VfxU8)pos - daysOfMonth - firstDayOfMonth + 1;
        }
    }
    else if (m_viewType == VappCalMainViewPage::VAPP_CAL_WEEKLY_VIEW)
    {
        if (pos % VAPP_CAL_WEEKLY_COLUMN == 0)
        {
            return;
        }

        applib_time_struct incTime;
        applib_time_struct firstTime;
        VfxU8 col = pos % VAPP_CAL_WEEKLY_COLUMN;

        getFirstDayOfWeek(date, &firstTime);

        memset(&incTime, 0, sizeof(applib_time_struct));
        incTime.nDay = col - 1;

        applib_dt_increase_time(&firstTime, &incTime, date);
    }
}

void VappCalBaseMenu::getFirstDayOfWeek(const applib_time_struct* date, applib_time_struct* dateOutPut)
{
    VfxU8 day;
    applib_time_struct inc_time;

    memset(&inc_time, 0, sizeof(applib_time_struct));

    day = (U8)applib_dt_dow(
                        date->nYear, 
                        date->nMonth, 
                        date->nDay);

    inc_time.nDay = day;

    applib_dt_decrease_time(
                        (applib_time_struct*)date,
                        (applib_time_struct*)&inc_time,
                        (applib_time_struct*)dateOutPut);

    dateOutPut->nHour = 0;
    dateOutPut->nMin = 0;
    dateOutPut->nSec = 0;
}


void VappCalBaseMenu::setWeeklyCellEvtFlagInt(void* pEvent, VfxU8 dow, VfxBool startCheck)
{
    VfxS32 start_per_idx, totalCell, last_per_idx, daily_per_num;

    applib_time_struct task_duration, start_period, end_period;
    VfxU8 interval = VAPP_CAL_WEEKLY_TIME_INTERVAL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //srv_tdl_get_cache(
    //              (void**) &pevent, 
    //              sizeof(srv_tdl_event_short_struct),
    //              SRV_TDL_VCAL_EVENT, 
    //              storeIdx);	


    srv_tdl_event_struct *pevent = (srv_tdl_event_struct *)pEvent;



    /* calculate start period of event */
    if (!startCheck)
    {

        start_per_idx = pevent->start_time.nHour / interval;
       
        
        /* mark the period blocks of the event duration */
        memcpy(&start_period, &pevent->start_time, sizeof(applib_time_struct));
        memcpy(&end_period, &pevent->end_time, sizeof(applib_time_struct));

        /* adjust the start time to period base point */
        start_period.nHour = (start_period.nHour / interval) * interval; 
        start_period.nMin = start_period.nSec = 0;
        
        if (CompareTime(pevent->start_time, pevent->end_time, NULL) == DT_TIME_EQUAL)
        {
            end_period.nHour++;
        }
        else if (end_period.nMin > 0)
        {
            end_period.nHour++;
            end_period.nMin = 0;
        }
        else if ((pevent->end_time.nMin == 0) && (pevent->end_time.nHour == 0))
        {
            end_period.nHour++;
        }
        end_period.nHour = ((end_period.nHour / interval) + 
                        (end_period.nHour % interval)) * interval;

        end_period.nMin = end_period.nSec = 0;
        applib_get_time_difference(
                    (applib_time_struct*)&end_period,
                    (applib_time_struct*)&start_period,
                    (applib_time_struct*)&task_duration);
            
        /* Total period is more than one week */
        if (task_duration.nYear != 0 || task_duration.nMonth != 0)
        {
            totalCell = ((VAPP_CAL_MAX_DAYS_PER_WEEK + 1) * VAPP_CAL_HOURS_ONE_DAY) / interval;
        }
        else
        {
            totalCell = (task_duration.nHour + task_duration.nDay * VAPP_CAL_HOURS_ONE_DAY) / interval;
        }
    }
    else
    {
        memcpy(&end_period, &pevent->end_time, sizeof(applib_time_struct));
        if (end_period.nMin > 0)
        {
        /* adjust the end time to period base point */
            end_period.nHour = ((end_period.nHour / interval) + 1) * interval;
        }
        else if((pevent->end_time.nMin == 0) && (pevent->end_time.nHour == 0))
        {
            end_period.nHour = ((end_period.nHour / interval) + 1) * interval;
        }

        if (dow == 0xff)
        {
            /* fill in all the cell with the event */
            totalCell = (((VAPP_CAL_MAX_DAYS_PER_WEEK + 1) * VAPP_CAL_HOURS_ONE_DAY) / interval);
        }
        else
        {
            totalCell = ( dow  * VAPP_CAL_HOURS_ONE_DAY + end_period.nHour) / interval;
        }
        start_per_idx = 0;
        dow = 0;
    }
    
    daily_per_num = VAPP_CAL_HOURS_ONE_DAY / interval;
    last_per_idx = daily_per_num;

    for (; totalCell >= 1; totalCell--)
    {
        if (start_per_idx == last_per_idx)
        {
            /* within the boundary of the week */
            if (dow < VAPP_CAL_WEEKLY_COLUMN - 1)
            {
                dow++;
                start_per_idx = 0;
            }
            else
            {
                break;
            }
        }
        m_isExistEvt[start_per_idx * VAPP_CAL_WEEKLY_COLUMN + dow + 1] = VFX_TRUE;

        start_per_idx++;
    }

    return;
}

void VappCalBaseMenu::getWeeklyDate(const applib_time_struct *currDT, VfxU8 *dateArray)
{
    VfxU8 i, last_day, date;
    VfxS8 diff_day;
    applib_time_struct first_date_week, currDate;

    currDate = *currDT;

    memset(&first_date_week, 0, sizeof(applib_time_struct));

    getFirstDayOfWeek(&currDate, &first_date_week);

    diff_day = (VfxS8)(currDate.nDay - first_date_week.nDay);
    date = first_date_week.nDay;

    /* first day of week is date of previous month */
    if (diff_day < 0)
    {
        last_day = (S32)applib_dt_last_day_of_mon(first_date_week.nMonth, first_date_week.nYear);
    }
    else
    {
        last_day = (S32)applib_dt_last_day_of_mon(currDate.nMonth, currDate.nYear);
    }

    for (i = 0; i < VAPP_CAL_MAX_DAYS_PER_WEEK; i++, date++)
    {
        if (date > last_day)
        {
            date = 1;
        }
        dateArray[i] = date;
    }
}


/***************************************************************************** 
 * Class VappCalBaseLayout
 *****************************************************************************/
void VappCalBaseLayout::onInit()
{
    VcpBaseMenuLayout::onInit();

    m_menu = VFX_OBJ_DYNAMIC_CAST(m_pMenu, VappCalBaseMenu);

    VFX_ASSERT(m_menu != NULL);

    if (m_menu->getMenuViewType() == VappCalMainViewPage::VAPP_CAL_WEEKLY_VIEW)
    {
        m_cellWidth = VAPP_CAL_WEEKLY_CELL_WIDTH;
        m_cellHeight = VAPP_CAL_WEEKLY_CELL_HEIGHT;
        m_firstCellWidth = VAPP_CAL_WEEKLY_F_CELL_WIDTH;
        m_columnCount = VAPP_CAL_WEEKLY_COLUMN;
    }
    else if (m_menu->getMenuViewType() == VappCalMainViewPage::VAPP_CAL_MONTHLY_VIEW)
    {
        m_cellWidth = VAPP_CAL_MONTHLY_CELL_WIDTH;
        m_cellHeight = VAPP_CAL_MONTHLY_CELL_HEIGHT;
        m_columnCount = VAPP_CAL_MONTHLY_COLUMN;
    }
}

VcpBaseMenuLayout::ScrollDirEnum VappCalBaseLayout::getScrollDir()
{
    return SCROLLDIR_VERT;
}

VfxS32 VappCalBaseLayout::getCellCount(VfxS32 group)
{
    if (group != 0)
    {
        return 0;
    }

    if (m_menu->getMenuViewType() == VappCalMainViewPage::VAPP_CAL_WEEKLY_VIEW)
    {
        return (24 / VAPP_CAL_WEEKLY_TIME_INTERVAL) * m_columnCount;
    }
    else if (m_menu->getMenuViewType() == VappCalMainViewPage::VAPP_CAL_MONTHLY_VIEW)
    {
        return (VAPP_CAL_MONTHLY_ROW * m_columnCount);
    }

    return 0;
}

VfxS32 VappCalBaseLayout::getContentLength()
{
    if (m_menu->getMenuViewType() == VappCalMainViewPage::VAPP_CAL_WEEKLY_VIEW)
    {
        return m_cellHeight * (24 / VAPP_CAL_WEEKLY_TIME_INTERVAL) + VAPP_CAL_WEEKLY_MENU_EDGE;
    }
    else if (m_menu->getMenuViewType() == VappCalMainViewPage::VAPP_CAL_MONTHLY_VIEW)
    {
        return m_cellHeight * VAPP_CAL_MONTHLY_ROW;
    }
    return 0;
}

VfxRect VappCalBaseLayout::queryCellRect(VcpMenuPos pos)
{
    if (pos.group != 0 || pos.pos < -1 || pos.pos >= getCellCount(pos.group))
    {
        return VfxRect(-1, -1, 0, 0);
    }

    VfxS32 width, x, y;
    if (m_menu->getMenuViewType() == VappCalMainViewPage::VAPP_CAL_WEEKLY_VIEW)
    {
        if (pos.pos % m_columnCount == 0)
        {
            x = 0;
            width = m_firstCellWidth;
        }
        else
        {
            x = m_firstCellWidth + (pos.pos % m_columnCount  - 1) * m_cellWidth;
            width = m_cellWidth;
        }

        y = (pos.pos / m_columnCount) * m_cellHeight;

        return VfxRect(x, y, width + 1, m_cellHeight + 1);
    }
    else if (m_menu->getMenuViewType() == VappCalMainViewPage::VAPP_CAL_MONTHLY_VIEW)
    {
        x = (pos.pos % m_columnCount) * m_cellWidth;

        y = (pos.pos / m_columnCount) * m_cellHeight;

        return VfxRect(x, y, m_cellWidth, m_cellHeight);
    }

    return VfxRect(-1, -1, 0, 0);
}

VcpMenuRegion VappCalBaseLayout::queryRegion(const VfxRect& r)
{
    return VcpMenuRegion(
        getPosByPoint(r.origin),
        getPosByPoint(VfxPoint(r.getMaxX(), r.getMaxY()))
    );
}
    
VcpMenuPos VappCalBaseLayout::getPosByPoint(VfxPoint pt)
{
    VcpMenuPos pos;
    VfxS32 curr_col, curr_row;

    if (m_menu->getMenuViewType() == VappCalMainViewPage::VAPP_CAL_WEEKLY_VIEW)
    {
        pos.group = 0;

        curr_row = pt.y / m_cellHeight;

        if (pt.x < m_firstCellWidth)
        {
            curr_col = 0;
        }
        else
        {
            curr_col = (pt.x - m_firstCellWidth) / m_cellWidth + 1;
        }

        pos.pos = curr_row * m_columnCount + curr_col;

        return pos;
    }
    else if (m_menu->getMenuViewType() == VappCalMainViewPage::VAPP_CAL_MONTHLY_VIEW)
    {
        pos.group = 0;

        curr_row = pt.y / m_cellHeight;

        curr_col = pt.x / m_cellWidth;

        pos.pos = curr_row * m_columnCount + curr_col;
    }
    return pos;
}


/***************************************************************************** 
 * Class VappCalMonthlyCell
 *****************************************************************************/
void VappCalMonthlyCell::onInit()
{
    VfxControl::onInit();

    setAnchor(VfxFPoint(0.5, 0.5));	

    setBorderColor(VFX_COLOR_RES(VCP_COL_VAPP_CAL_WEEK_CELL_COLOR));
    setBorderWidth(1);

}

void VappCalMonthlyCell::onUpdate()
{
    if (m_isToday)
    {
        setImgContent(VfxImageSrc(IMG_ID_VAPP_CAL_TODAY));
    }
    
        setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    setAnchor(VfxFPoint(0.5f, 0.5f));	


    // set cell event image
    if (m_isExistEvt && !m_isDisabled)
    {
        VfxImageFrame *evtFrame;
        VFX_OBJ_CREATE(evtFrame, VfxImageFrame, this);
        evtFrame->setResId(IMG_ID_VAPP_CAL_TIPS);
        evtFrame->setAnchor(1.0F, 0.0F);
        evtFrame->setPos(getSize().width - 1, 0);
    }

    // set cell date string
    VfxWChar string[3] = {0};
    kal_wsprintf(string, "%d", getDate());
    VfxTextFrame *dayTxFrame;
    VFX_OBJ_CREATE(dayTxFrame, VfxTextFrame, this);
    dayTxFrame->setAnchor(VfxFPoint(0.5f, 0.5f));	
    dayTxFrame->setPos(VAPP_CAL_MONTHLY_CELL_WIDTH / 2, VAPP_CAL_MONTHLY_CELL_HEIGHT / 2);
    dayTxFrame->setString(VFX_WSTR_MEM(string));
    dayTxFrame->setFont(VfxFontDesc(VAPP_CAL_MONTH_CELL_FONT, VFX_FONT_DESC_ATTR_NORMAL));	
    dayTxFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);

    if (m_isDisabled)
    {
        dayTxFrame->setColor(VfxColor(255, 170, 170, 170));
    }
    else
    {
        if (m_isToday)
        {
            dayTxFrame->setColor(VFX_COLOR_WHITE);
        }
        else
        {
            dayTxFrame->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));//VfxColor(255, 15, 15, 15));
        }
    }
}

void VappCalMonthlyCell::setEvtExist(VfxBool isExistEvt)
{
    m_isExistEvt = isExistEvt;
}

void VappCalMonthlyCell::setDisabled(VfxBool isDisabled)
{
    m_isDisabled = isDisabled;
}

void VappCalMonthlyCell::setWeekend(VfxBool isWeekend)
{
    m_isWeekend = isWeekend;
}

void VappCalMonthlyCell::setDate(VfxU8 day)
{
    m_day = day;
}

void VappCalMonthlyCell::setToday(VfxBool isToday)
{
    m_isToday = isToday;
}

/***************************************************************************** 
 * Class VappCalWeeklyCell
 *****************************************************************************/
void VappCalWeeklyCell::onInit()
{
    VfxControl::onInit();

    setAnchor(VfxFPoint(0.5, 0.5));	
    setBorderColor(VFX_COLOR_RES(VCP_COL_VAPP_CAL_WEEK_CELL_COLOR));
    setBorderWidth(1);
    setIsOpaque(VFX_TRUE);

    if (m_posId % VAPP_CAL_WEEKLY_COLUMN == 0)
    {
        setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));//(VfxColor(255, 241, 241, 241));

        VfxWChar string[6] = {0};
        kal_wsprintf(string, "%d:00", m_posId / VAPP_CAL_WEEKLY_COLUMN * VAPP_CAL_WEEKLY_TIME_INTERVAL);

        VfxTextFrame *textFrame;
        VFX_OBJ_CREATE(textFrame, VfxTextFrame, this);
        textFrame->setAnchor(0.5f, 0.5f);
        textFrame->setString(VFX_WSTR_MEM(string));
        textFrame->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));
        textFrame->setFont(VfxFontDesc(VAPP_CAL_WEEK_CELL_TIME_FONT, VFX_FONT_DESC_ATTR_NORMAL));
        textFrame->setPos((VAPP_CAL_WEEKLY_F_CELL_WIDTH >> 1), (VAPP_CAL_WEEKLY_CELL_HEIGHT >> 1));
        textFrame->setSize(VAPP_CAL_WEEKLY_F_CELL_WIDTH, VAPP_CAL_WEEKLY_CELL_HEIGHT);
        textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    }
}

void VappCalWeeklyCell::onUpdate()
{
    if (getEvtExist())
    {
        //setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));//(VfxColor(255, 223, 255, 254));
        setBgColor(VFX_COLOR_RES(VCP_COL_VAPP_CAL_EVENT_COLOR));//VfxColor(255, 223, 255, 254));
    }
}

void VappCalWeeklyCell::setEvtExist(VfxBool isExistEvt)
{
    m_isExistEvt = isExistEvt;
}



/***************************************************************************** 
 * Class VappCalDailyList
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappCalDailyList", VappCalDailyList, VcpListMenu);
void VappCalDailyList::onInit()
{
    VcpListMenu::onInit();

    srv_tdl_set_source_state(MMI_TRUE, SRV_TDL_EVENT_SOURCE_TOTAL);
    srv_tdl_search_filter_struct filter;
    filter.type = SRV_TDL_SEARCH_TYPE_DAILY;
    memcpy(&filter.u.date_time, &m_dateTime, sizeof(MYTIME));
    m_jobId = srv_tdl_event_search_begin(&filter,SRV_TDL_EVENT_SORT_START_TIME,SRV_TDL_EVENT_SOURCE_TOTAL);

    if(m_jobId > 0)
    {
        mmi_frm_cb_reg_event(EVT_ID_SRV_TDL_EVENT_SEARCH, &VappCalDailyList::onEventReady, getObjHandle());
    }
    else
    { 
        VFX_ASSERT(0);
    }

   
}


void VappCalDailyList::onDeinit()
{
  
    if(m_eventbuffer)
    {
        VFX_FREE_MEM(m_eventbuffer);
    }
    if(m_jobId > 0)
    {
        srv_tdl_event_search_end(m_jobId);

        mmi_frm_cb_dereg_event(EVT_ID_SRV_TDL_EVENT_SEARCH, &VappCalDailyList::onEventReady, getObjHandle());
        m_jobId = -1;
    }

    VcpListMenu::onDeinit();
}

srv_tdl_event_id_struct *VappCalDailyList::GetEventbuffer() const
{
    return m_eventbuffer;
}



VfxBool VappCalDailyList::getItemText(
    VfxU32 index,                   
    VcpListMenuFieldEnum fieldType,  
    VfxWString &text,               
    VcpListMenuTextColorEnum &color)
{


    srv_tdl_event_struct *buffer;
    VFX_ALLOC_MEM(buffer,sizeof(srv_tdl_event_struct),this);
    srv_tdl_event_get(
                buffer, 
                sizeof(srv_tdl_event_struct), 
                m_eventbuffer[index].source_id,
                m_eventbuffer[index].event_id);



    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        text.loadFromMem((VfxWChar*) buffer->subject);
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1 ||
                fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT2)
    {
        VappCalUtility::getListItemDateTimeStr(
                                        fieldType, 
                                        SRV_TDL_VCAL_EVENT, 
                                        buffer,
                                        text);
    }

    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;

    VFX_FREE_MEM(buffer);
    return VFX_TRUE;
}


VfxU32 VappCalDailyList::getCount() const
{
    return m_count;
}

VfxBool VappCalDailyList::getItemImage(
                                VfxU32 index,                    
                                VcpListMenuFieldEnum fieldType,  
                                VfxImageSrc &image)
{

    srv_tdl_event_id_struct event_id = m_eventbuffer[index];
    setItemImagebyIdx(event_id, fieldType, image,this);

    return VFX_TRUE;
}

VfxBool VappCalDailyList::getMenuEmptyText(
                                        VfxWString &text,               
                                        VcpListMenuTextColorEnum &color)
{

    text.loadFromRes((VfxResId)m_stringId);
 
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    return VFX_TRUE;
}

VappCalListMgr* VappCalDailyList::getListMgr()
{
    return m_listMgr;
}


mmi_ret VappCalDailyList::onEventReady(mmi_event_struct *param)
{
    VfxObject *obj = handleToObject((VfxObjHandle)param->user_data);
    if (obj == NULL)
    {
        return MMI_RET_OK;
    }

    VappCalDailyList *dailyList = VFX_OBJ_DYNAMIC_CAST(obj, VappCalDailyList);
    if(dailyList == NULL)
    {
        return MMI_RET_OK;
    }

    srv_tdl_search_callback_struct* sEvent = (srv_tdl_search_callback_struct*)param;
    if(!sEvent->success)
    { 
        VappCalUtility::getSnsDataError();	 
    }


    if(dailyList->m_jobId != sEvent->job_id)
    {
        return MMI_RET_OK;
    }

    dailyList->m_count = sEvent->event_cnt;

    if(dailyList->m_count != 0)
    {
        VFX_ALLOC_MEM(dailyList->m_eventbuffer, dailyList->m_count * sizeof(srv_tdl_event_id_struct),dailyList);

        if( srv_tdl_event_search_get(dailyList->m_jobId, dailyList->m_eventbuffer,dailyList->m_count * sizeof(srv_tdl_event_id_struct) , 0) < 0)
        {
            VFX_ASSERT(0);
        }
    }
    dailyList->m_stringId = STR_ID_VAPP_CAL_NO_EVTS;

    srv_tdl_event_search_end(dailyList->m_jobId);
    dailyList->m_jobId = -1;
    mmi_frm_cb_dereg_event(EVT_ID_SRV_TDL_EVENT_SEARCH, &VappCalDailyList::onEventReady, dailyList->getObjHandle());

    dailyList->checkUpdate();
    dailyList->m_stringId = STR_ID_VAPP_CAL_NO_EVTS;

    return MMI_RET_OK;
}



void VappCalDailyList::setItemImagebyIdx(srv_tdl_event_id_struct event_id, VcpListMenuFieldEnum fieldType, VfxImageSrc &image, VfxObject* pram)
{
   
    VfxU16 iconMask;

    srv_tdl_event_struct *buffer;
    VFX_ALLOC_MEM(buffer,sizeof(srv_tdl_event_struct),pram);
    srv_tdl_event_get(
                buffer, 
                sizeof(srv_tdl_event_struct), 
                event_id.source_id,
                event_id.event_id);


    VfxU16 repeatType = VappCalEditPage::convertRepeatStoM((srv_tdl_repeat_rule_enum)buffer->repeat.rule);

    if (buffer->alarm.type == VAPP_CAL_REMINDER_NEVER)
    {
        if (repeatType == VAPP_CAL_REPEAT_NEVER)
        {
            iconMask = VAPP_CAL_NO_ICON;
        }
        else
        {
            iconMask = VAPP_CAL_ONLY_REPEAT_ICON;
        }
    }
    else
    {
        if (repeatType == VAPP_CAL_REPEAT_NEVER)
        {
            iconMask = VAPP_CAL_ONLY_ALARM_ICON;
        }
        else
        {
            iconMask = VAPP_CAL_TWO_ICON;
        }
    }

    if (fieldType == VCP_LIST_MENU_FIELD_ICON)
    {
        VfxU16 id;
        VAPP_CAL_CATEGORY_ENUM category;

        category = VappCalEditPage::convertCategoryStoM((srv_vcal_category_type_enum)buffer->category);
        id = IMG_ID_VAPP_CAL_PERSONAL + category;   //ordered
        image.setResId(id);

#ifdef __MMI_SNS_CALENDAR__
        if((event_id.source_id > SRV_TDL_EVENT_SOURCE_LOCAL)&&(event_id.source_id < SRV_TDL_EVENT_SOURCE_TOTAL))
        { 
            VfxWChar *path = srv_sns_get_provider_icon( srv_sns_provider_from_tdl_source( event_id.source_id),SRV_SNS_LOGO_SMALL);

            if (path)
            {
                image.setPath(VFX_WSTR_MEM(path));
            }
        }

#endif


    }
    else if (fieldType == VCP_LIST_MENU_FIELD_ICON_EXTRA1)
    {
        if (iconMask == VAPP_CAL_TWO_ICON)
        {
            image.setResId(IMG_ID_VAPP_CAL_REMINDER);
        }
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_ICON_EXTRA2)
    {
        if (iconMask == VAPP_CAL_TWO_ICON 
            || iconMask == VAPP_CAL_ONLY_REPEAT_ICON)
        {
            image.setResId(IMG_ID_VAPP_CAL_REPEAT);
        }
        else if (iconMask == VAPP_CAL_ONLY_ALARM_ICON)
        {
            image.setResId(IMG_ID_VAPP_CAL_REMINDER);
        }
    }
    VFX_FREE_MEM(buffer);

}

/***************************************************************************** 
 * Class VappCalViwerSwitchBar
 *****************************************************************************/
void VappCalViwerSwitchBar::onAddItem()
{
    VFX_OBJ_CREATE(m_addButton, VcpButton, this);
    m_addButton->setAnchor(0, 0);
    m_addButton->setImage(VcpStateImage(VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD));
    m_addButton->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_TOP);
    m_addButton->setText((VfxResId)STR_ID_VAPP_CAL_ADD);
    VfxFontDesc font_desc;
    font_desc.size = VFX_FONT_DESC_VF_SIZE(VCP_TOOL_BAR_BUTTON_FONT_SIZE);
    m_addButton->setTextFont(font_desc);
    m_addButton->setTextColor(VFX_COLOR_WHITE);
    m_addButton->m_signalClicked.connect(this, &VappCalViwerSwitchBar::onClick);

    // Apply the visual on teh button
    //m_addButton->changeVisual(VfxVisualFactory::create(VIS_ID_TOOLBAR_BUTTON, m_addButton));
    m_addButton->setBgImageList(VcpStateImage(VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL, 
                                                    VCP_IMG_TOOL_BAR_BUTTON_VISUAL_PRESSED, 
                                                    VCP_IMG_TOOL_BAR_BUTTON_VISUAL_DISABLED, 
                                                    VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL));
    m_addButton->setMargin(
                    VCP_TOOL_BAR_BUTTON_FONT_MARGIN_LEFT, 
                    VCP_TOOL_BAR_BUTTON_FONT_MARGIN_UP, 
                    VCP_TOOL_BAR_BUTTON_FONT_MARGIN_RIGHT, 
                    VCP_TOOL_BAR_BUTTON_FONT_MARGIN_DOWN);
    m_addButton->setPos(0, 0);
    m_addButton->setSize(VAPP_CAL_BOTTOM_BUTTON_WIDTH, VAPP_CAL_BOTTOM_BAR_HEIGHT);	

    VFX_OBJ_CREATE(m_listButton, VcpButton, this);
    m_listButton->setAnchor(1, 0);
    m_listButton->setImage(VcpStateImage(VCP_IMG_TOOL_BAR_COMMON_ITEM_LOGIN));
    m_listButton->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_TOP);
    m_listButton->setText((VfxResId)STR_ID_VAPP_CAL_EVENTS);
    m_listButton->setTextFont(font_desc);
    m_listButton->setTextColor(VFX_COLOR_WHITE);
    m_listButton->m_signalClicked.connect(this, &VappCalViwerSwitchBar::onClick);

    // Apply the visual on teh button
    //m_listButton->changeVisual(VfxVisualFactory::create(VIS_ID_TOOLBAR_BUTTON, m_listButton));
    m_listButton->setBgImageList(VcpStateImage(VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL, 
                                                VCP_IMG_TOOL_BAR_BUTTON_VISUAL_PRESSED, 
                                                VCP_IMG_TOOL_BAR_BUTTON_VISUAL_DISABLED, 
                                                VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL));
    m_listButton->setMargin(
                    VCP_TOOL_BAR_BUTTON_FONT_MARGIN_LEFT, 
                    VCP_TOOL_BAR_BUTTON_FONT_MARGIN_UP, 
                    VCP_TOOL_BAR_BUTTON_FONT_MARGIN_RIGHT, 
                    VCP_TOOL_BAR_BUTTON_FONT_MARGIN_DOWN);

    m_listButton->setPos(getSize().width, 0);
    m_listButton->setSize(VAPP_CAL_BOTTOM_BUTTON_WIDTH, VAPP_CAL_BOTTOM_BAR_HEIGHT);	

    VfxFrame *segButtonParent;
    VFX_OBJ_CREATE(segButtonParent,VfxFrame,this);
    segButtonParent->setImgContent(VfxImageSrc(VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL));
    segButtonParent->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    segButtonParent->setAnchor(0.5,0.5);
    segButtonParent->setPos(getBounds().getMidPoint());
    segButtonParent->setSize(getSize().width - VAPP_CAL_BOTTOM_BUTTON_WIDTH * 2, 
                        getSize().height);

    VFX_OBJ_CREATE(m_segButton, VcpSegmentButton, this);
    VcpStateImage monthStateImage;
    monthStateImage.setImage(VCP_IMG_SEGMENT_BUTTON_LEFT_N, 
                            VCP_IMG_SEGMENT_BUTTON_LEFT_P, 
                            VCP_IMG_SEGMENT_BUTTON_LEFT_H, 
                            VCP_IMG_SEGMENT_BUTTON_LEFT_D);
    VcpStateImage weekStateImage;
    weekStateImage.setImage(VCP_IMG_SEGMENT_BUTTON_MIDDLE_N, 
                            VCP_IMG_SEGMENT_BUTTON_MIDDLE_P, 
                            VCP_IMG_SEGMENT_BUTTON_MIDDLE_H, 
                            VCP_IMG_SEGMENT_BUTTON_MIDDLE_D);
    VcpStateImage dayStateImage;
    dayStateImage.setImage(VCP_IMG_SEGMENT_BUTTON_RIGHT_N, 
                            VCP_IMG_SEGMENT_BUTTON_RIGHT_P, 
                            VCP_IMG_SEGMENT_BUTTON_RIGHT_H, 
                            VCP_IMG_SEGMENT_BUTTON_RIGHT_D);
    m_segButton->setAnchor(VfxFPoint(0.5f, 0.5f));
    m_segButton->setPos(getBounds().getMidPoint());

    m_segButton->setWidth(getSize().width - VAPP_CAL_BOTTOM_BUTTON_WIDTH * 2 - VAPP_CAL_BOOTOM_SEGMENT_MARGIN);

    m_segButton->setSize(
                getSize().width - VAPP_CAL_BOTTOM_BUTTON_WIDTH * 2 - VAPP_CAL_BOOTOM_SEGMENT_MARGIN, 
                m_segButton->getSize().height);



    m_segButton->setType(VCP_SEGMENT_BUTTON_TYPE_RADIO);
    m_segButton->setStyle(VCP_SEGMENT_BUTTON_STYLE_TEXT_ONLY);
    if (getMainScr()->getSize().width < 320)
    {
        m_segButton->addButton(VAPP_CAL_SWITCH_TYPE_MONTH, monthStateImage, VFX_WSTR_RES(STR_ID_VAPP_CAL_MONTH_SHORT));
        m_segButton->addButton(VAPP_CAL_SWITCH_TYPE_WEEK, weekStateImage, VFX_WSTR_RES(STR_ID_VAPP_CAL_WEEK_SHORT));
        m_segButton->addButton(VAPP_CAL_SWITCH_TYPE_DAY, dayStateImage, VFX_WSTR_RES(STR_ID_VAPP_CAL_DAY_SHORT));
    }
    else
    {
        m_segButton->setFontSize(VAPP_CAL_SEGMENT_FONT);
        m_segButton->addButton(VAPP_CAL_SWITCH_TYPE_MONTH, monthStateImage, VFX_WSTR_RES(STR_ID_VAPP_CAL_MONTH));
        m_segButton->addButton(VAPP_CAL_SWITCH_TYPE_WEEK, weekStateImage, VFX_WSTR_RES(STR_ID_VAPP_CAL_WEEK));
        m_segButton->addButton(VAPP_CAL_SWITCH_TYPE_DAY, dayStateImage, VFX_WSTR_RES(STR_ID_VAPP_CAL_DAY));
    }
    m_segButton->m_signalButtonClicked.connect(this, &VappCalViwerSwitchBar::onClick);
}

void VappCalViwerSwitchBar::setSegmentPressed(VfxId id)
{
    m_segButton->setButtonIsHighlighted(id, VFX_TRUE);
}

void VappCalViwerSwitchBar::onClick(VfxObject *sender, VfxId id)
{
    VfxId switchType = VAPP_CAL_SWITCH_TYPE_LIST;
    if (sender == m_listButton)
    {
        switchType = VAPP_CAL_SWITCH_TYPE_LIST;
    }
    else if (sender == m_addButton)
    {
        switchType = VAPP_CAL_SWITCH_TYPE_ADD;
    }
    else if (sender == m_segButton)
    {
        switchType = id;
    }

    m_signalClicked.postEmit(this, switchType);
}
#ifndef __MMI_VCALENDAR__
#pragma arm section code, rodata
#endif

