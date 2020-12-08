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
 *  vapp_mms_viewer.cpp
 *
 * Project:
 * --------
 *  MMS Viewer
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------*/

// This include is for proc call
#include "MMI_features.h"
#include "vapp_msg_features.h"

#ifdef __MMI_MMS_2__
#include "mmi_rp_vapp_mms_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_app_usbsrv_def.h"
extern "C"
{
//#include "CommonScreens.h"
#include "GlobalDefs.h"
#include "SettingProfileEnum.h"
#include "MmsXMLDefSrv.h"
#include "MmsSrvGprot.h"
#include "MmsMemoryManagerSrv.h"
#include "DateTimeGprot.h"
#include "Mdi_datatype.h"
#include "Mdi_audio.h"
#include "ProfilesSrvGprot.h"
#include "UcmGprot.h"
#include "UcmSrvGprot.h"
//#include "SimDetectionGprot.h"
#include "ProfilesSrvGprot.h"
#include "MMSAppCommonGprot.h"
#include "wgui_categories_util.h"
//#include "SimDetectionStruct.h"
#include "mmi_inet_app_trc.h"
#include "GpioSrvGprot.h"
#include "mmi_rp_vapp_vol_dialog_def.h"
#include "mmi_rp_srv_prof_def.h"
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGProt.h"
}
#include "vapp_mms_common.h"
#include "vapp_mms_gprot.h"
#include "vadp_mmi_frm.h"
#include "vfx_uc_include.h"
#include "../xml/vfx_xml_loader.h"
#include "vcp_text_view.h"
#include "vcp_app_scr.h"
#include "vcp_button.h"

#include "vapp_video_player_cp.h"
#include "vapp_mms_viewer_cp.h"
#include "vapp_msg_contact_bar.h"
#include "vapp_mms_contact_provider.h"
#include "vapp_mms_data.h"
#include "vapp_mms_viewer.h"
#include "vapp_mms_appcore.h"
#include "vapp_mms_view_objects.h"
#include "vapp_mms_details_viewer.h"
#include "vapp_mms_use_details.h"
#include "vapp_vol_dialog_gprot.h"

#include "vcp_include.h"
#include "ui_core\mvc\vfx_mmi.h"

#include "vcp_status_icon_bar.h"
#include "vcp_page_panel.h"
#include "vcp_list_menu.h"
#include "vcp_popup.h"
#include "vcp_image_button.h"
#include "vapp_mms_gprot.h"
#include "vapp_uc_gprot.h"
#include "vapp_msg_gprot.h"

#define         TEMP_BUFFER_SIZE                  60
#define MMS_CLOCK_TIME 500
#define MMS_CLOCK_START_DELAY 500

#define MMS_BODY_ERROR_HANDLE(x) if(x->body == NULL) return;
#define MMS_BODY_ERROR_CP_HANDLE(x) if(x->body == NULL) {m_state = REDRAW_NONE;return;}

VfxPage * VappMmsViewerPage::myPage = NULL;
VfxU32 g_msg_id;
VappMmsViewerModeEnum g_mode = MODE_STOP;
extern "C" void mmi_app_deinit(void)
{
	
}

extern "C" void mmi_app_exit_scr(void)
{
    // Close application screen
    mmi_app_deinit();
}
//extern U16 vtst_contact_list_entry(U32 param);
extern "C" void vapp_mms_viewer_launch(U32 msg_id, mmi_id parent_id)
{
    VappMmsViewerStartStruct startData;
    memset(&startData, 0, sizeof(VappMmsViewerStartStruct));
    startData.msg_id = msg_id;
    VfxAppLauncher::launch( VAPP_MMS, 
                            VFX_OBJ_CLASS_INFO(VappMmsViewer),
                            parent_id,
                            (void*)&startData,
                            sizeof(VappMmsViewerStartStruct));
}

VFX_IMPLEMENT_CLASS("VappMmsViewer", VappMmsViewer, VfxCui);
void VappMmsViewer::onRun(void *args, VfxU32 argSize)
{
    VappMmsViewerStartStruct startData;
    memcpy(&startData, args, sizeof(VappMmsViewerStartStruct));
    VfxApp::onRun(args, argSize);
    if(isActive())
    {
        VFX_OBJ_CREATE_EX(m_scrn, VappMmsViewerScrn, this, (startData.index, startData.msg_id, startData.mode, startData.isPreview, startData.msg_location));
        m_scrn->show();
    }
    else
    {
        cui_vapp_mms_preview_evt_struct evt;
        MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CLOSE_MMS_PREVIEW,getGroupId());
        postToCaller((mmi_group_event_struct*)&evt);
    }

}

VFX_IMPLEMENT_CLASS("VappMmsViewerScrn", VappMmsViewerScrn, VfxMainScr);
VFX_IMPLEMENT_CLASS("VappMmsViewerPage", VappMmsViewerPage, VfxPage);
VFX_IMPLEMENT_CLASS("VappMmsViewerCp", VappMmsViewerCp, VappMsgViewerCp);
VFX_IMPLEMENT_CLASS("VappMmsVisual", VappMmsVisual, VfxControl);
//VFX_IMPLEMENT_CLASS("VappMmsViewer", VappMmsViewer, VfxApp);
void VappMmsViewerScrn :: on1stReady(void)
{
    VfxMainScr::on1stReady();
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
    VFX_OBJ_CREATE_EX(m_page, VappMmsViewerPage, this, (m_mode, m_msgId, m_isPreview, m_index, m_msg_location));
    this->pushPage(0, m_page);
}
void VappMmsViewerPage::onBack(void)
{
	
	COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_ON_BACK,m_mode, __LINE__); 
    if( m_mode == MODE_PLAY
        ||m_mode == MODE_PAUSE)
    {
        onPreviewPageFinish();
        return;
    }
    VfxPage::onBack();
}

void VappMmsViewerPage::onInit(void)
{
    VfxPage::onInit();
    VappMmsViewerPage::myPage = (VfxPage *)this;
    m_enter = VFX_FALSE;
    /*setAlignParent(
    VFX_FRAME_ALIGNER_MODE_SIDE, 
    VFX_FRAME_ALIGNER_MODE_SIDE, 
    VFX_FRAME_ALIGNER_MODE_SIDE, 
    VFX_FRAME_ALIGNER_MODE_SIDE);*/
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VappMmsViewerPage::listener, getObjHandle());
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, &VappMmsViewerPage::listener, getObjHandle());
#endif/*__MMI_USB_SUPPORT__*/
    VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    if (NCenter)
    {
        NCenter->m_signalEvent.connect(this, &VappMmsViewerPage::onNCenterStatus);
    }
    if(MODE_STOP == m_mode)
    { 
    
        ((VappMsgApp *)getMainScr()->getApp())->setSubMsgCareHomeKeyCb(&VappMmsViewerPage::checkmmspageisgetcontent,getObjHandle());
    }

    //setBgColor(VFX_COLOR_WHITE);
    
#ifdef __MMI_MMS_USE_ASM__  
    mmi_frm_cb_reg_event(EVT_ID_SRV_MMS_SERVICE_MEM_FREE_DONE, &VappMmsViewerPage::listener, getObjHandle());
#endif
    if(m_data->checkDataReady() == VFX_FALSE)
    {
        m_data->m_signalMmsViewerServiceDone.connect(this, &VappMmsViewerPage::onDataReady);
        if(m_data->getDataReady() == VFX_TRUE)
        {
            //show progress
            VFX_OBJ_CREATE(m_popup,VcpActivityIndicator,this);
            m_popup->setPos(getRect().getX() + (getSize().width / 2) - 20, getRect().getY()+ (getSize().height / 2) - 20);
            m_popup->setSize(40, 40);
            m_popup->start();
        }
        return;
    }
    draw();
}
void VappMmsViewerPage::onNCenterStatus(VappNCenterEventEnum evt)
{
    switch (evt)
    {
        case VAPP_NCENTER_EVENT_ENTERED:
            setbuttonstate(VCP_BUTTON_STATE_NORMAL);
            break;
        default:
            break;
    }
}
mmi_ret VappMmsViewerPage::listener(mmi_event_struct *param)
{
    VappMmsViewerPage *myData = (VappMmsViewerPage *)VfxObject::handleToObject((VfxObjHandle)param->user_data);
    if(myData && myData->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsViewerPage)) )
    {
        return myData->listenerInt(param);
    }
    return MMI_RET_OK;
}
mmi_ret VappMmsViewerPage::listenerInt(mmi_event_struct *param)
{
    switch(param->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
            if (m_msg_location == MMA_MSG_STORAGE_CARD1)
            {
                if(m_mode != MODE_STOP)
                {
                    onPreviewPageFinish();
                }
                else
                {
                    searchAndDelete();					
                }
            }
            break;
    #ifdef __MMI_USB_SUPPORT__
        case EVT_ID_USB_ENTER_MS_MODE:
            if(m_mode != MODE_STOP)
            {
                onPreviewPageFinish();
            }
            else
            {
                searchAndDelete();
            }
            break;
    #endif/*__MMI_USB_SUPPORT__*/
    #ifdef __MMI_MMS_USE_ASM__      
        case EVT_ID_SRV_MMS_SERVICE_MEM_FREE_DONE:
            
            if(VFX_TRUE == m_exited && m_mode == MODE_STOP && m_wait_data_done == VFX_TRUE)
            {               
            
            m_wait_data_done = VFX_FALSE;              
                ((VappMsgApp *)getMainScr()->getApp())->subMsgFreeHomeKey();
                return MMI_RET_OK;
            }
            else if(VFX_TRUE == m_exited && m_mode == MODE_PLAY && m_wait_data_done == VFX_TRUE)
            {
                
                m_wait_data_done = VFX_FALSE;
                ((VappMmsViewer *)getMainScr()->getApp())->callclosecontinue();
                return MMI_RET_OK;
            }
            else if(VFX_TRUE == m_preview_finish && m_mode == MODE_PLAY && m_wait_data_done == VFX_TRUE)
            {         
                m_wait_data_done = VFX_FALSE;
                onPreviewPageFinish();
                return MMI_RET_OK;
            }
            m_wait_data_done = VFX_FALSE;
            break;
    #endif        
        default:
            break;
    }
    return MMI_RET_OK;
}

void VappMmsViewerPage::searchAndDelete(void)
{
    VfxMainScr *scr = getMainScr();
    VfxBool del = VFX_FALSE;
    for(int i = 0; i < 4; i++)
    {
        VfxId id = scr->getTopPageId();
        while(id != 0)
        {
            switch(i)
            {
                case 0:
                    if((scr->getPage(id))->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsViewObjectsPage)))
                    {
                        del = VFX_TRUE;
                    }
                    break;
            #ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
                case 1:
                    if((scr->getPage(id))->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsUseDetailsPage)))
                    {
                        del = VFX_TRUE;
                    }
                    break;
            #endif/*__MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__*/
            #ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__
                case 2:
                    if((scr->getPage(id))->isKindOf(VFX_OBJ_CLASS_INFO(VappMMSReportsPage)))
                    {
                        del = VFX_TRUE;
                    }
                    break;
            #endif /*__MMI_MMS_REPORT_STATUS_SUPPORT__*/
                case 3:
                if((scr->getPage(id))->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsViewerPage)))
                {
                    del = VFX_TRUE;
                }
                break;
            }
            if(del == VFX_TRUE && id)
            {
                scr->closePage(id);
                del = VFX_FALSE;
                break;
            }
            id = scr->getPrevPageId(id);
        }
    }
}
void VappMmsViewerPage::onMediaEnd(srv_mms_viewer_object_type_enum type)
{
    if(m_clock->getClockState() != VappMmsClock::STATE_WAIT )
    {
        m_main_cp->handleMediaEnd((VfxU32)type);
    }
}

void VappMmsViewerPage::draw(void)
{
    if(m_noload == VFX_FALSE)
    {
        loadXML();
        loadAllComponentsFromXml();
        if(m_mode == MODE_STOP &&
           (getMsgType() != MMA_MSG_TYPE_MMS
           || (m_data->getMsgInfo())->result == MMA_RESULT_FAIL_FILE_CORRUPTED
           || (m_data->getMsgInfo())->result == MMA_RESULT_FAIL_UNSUPPORT_MMS_TYPE))
        {
            loadContactBar();
            VfxXmlLoader::loadEnd();
        }
    }
    setBgColor(VFX_COLOR_RES(VAPP_MMS_VIEWER_TEXT_BACKGROUND_COLOR));
    if(m_mode == MODE_STOP &&
        (getMsgType() != MMA_MSG_TYPE_MMS
        || (m_data->getMsgInfo())->result == MMA_RESULT_FAIL_FILE_CORRUPTED
        || (m_data->getMsgInfo())->result == MMA_RESULT_FAIL_UNSUPPORT_MMS_TYPE))
    {
        if(m_detail_viewer == NULL)
        {
            VFX_OBJ_CREATE(m_detail_viewer, VappMmsDetailsViewer, m_panel);
        }
        m_panel->setPos(m_detail_viewer->getRect().getX(), m_contact_bar->getRect().getMaxY());
        m_panel->setSize(getSize().width, getSize().height - m_contact_bar->getSize().height);
        m_detail_viewer->setBounds(m_panel->getBounds());
        m_main_cp->setBounds(m_panel->getBounds());
        m_panel->setCurrentFrame(m_detail_viewer);
        m_panel->m_signalFinished.connect(this, &VappMmsViewerPage::onDownloadDone);
        m_detail_viewer->setData(m_data);
        VFX_OBJ_CREATE(m_tool_bar,  VappMmsToolBar, this);
        m_tool_bar->setData(m_data);
        setBottomBar(m_tool_bar);
        alignAllChilds();	
        return;
    }
    VfxWString txt;
    m_panel->setCurrentFrame(m_main_cp);
    if(m_mode == MODE_STOP)
    {
        if(m_noload == VFX_FALSE)
        {
            loadContactBar();
            /*Tool bar and Bottom text to specify postions*/
            VFX_OBJ_CREATE(m_tool_bar,  VappMmsToolBar, this);
        }
        else
        {
            m_main_cp->setBounds(m_panel->getBounds());
        }
        m_noload = VFX_FALSE;
        m_tool_bar->setData(m_data);
        if(m_noload == VFX_FALSE)
        {
            setBottomBar(m_tool_bar);
        }
        applib_time_struct time1, time2;
        VfxWChar dttemp[TEMP_BUFFER_SIZE];
        FLOAT timezone;
        VfxWString txt1;
        timezone =  mmi_dt_get_tz();
        mmi_dt_utc_sec_2_mytime((U32) m_data->getMsgInfo()->receive_date, &time2, MMI_TRUE);
        mmi_dt_utc_to_rtc(timezone, time2, time1);
        memset(dttemp, 0x00, TEMP_BUFFER_SIZE);
        VfxDateTime time;
        time.setDateTime(&time1);
        time.getDateTimeString(VFX_DATE_TIME_DATE_MASK | VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE, dttemp, sizeof(dttemp));
        txt += VFX_WSTR("  ");
        txt += txt1.loadFromMem((PU16)dttemp);
        m_dt_txt->setString(txt);
        m_dt_txt->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
        VfxFontDesc font;
        font.size = VFX_FONT_DESC_VF_SIZE(DT_FONT_SIZE);
        VfxColor color(DT_FONT_A, DT_FONT_R, DT_FONT_G, DT_FONT_B);
        m_dt_txt->setFont(font);  
        m_dt_txt->setAutoResized(VFX_FALSE); 
        m_dt_txt->setColor(color);
        m_dt_txt->setMargins(   DATE_TIME_BAR_LEFT_MARGIN,
                                DATE_TIME_BAR_TOP_MARGIN,
                                DATE_TIME_BAR_RIGHT_MARGIN,
                                0);
        m_button_play->m_signalClicked.connect(this, &VappMmsViewerPage::onClick);
        m_prev->m_signalClicked.connect(this, &VappMmsViewerPage::onClickPrev);
        m_next->m_signalClicked.connect(this, &VappMmsViewerPage::onClickNext);
        if(m_data->checkViewerDataReady())
        {
            if(getMsgCntx()->total_slide_num == 1)
            {
                m_prev->setSize(0, m_prev->getSize().height);
                m_button_play->setPos(BUTTON_PLAY_ONLY_X, m_button_play->getRect().getY());
                m_button_play->setSize(BUTTON_PLAY_ONLY_WIDTH, m_button_play->getSize().height);
                m_next->setSize(0, m_next->getSize().height);
            }
            else
            {
                if((*(getMsgCntx()->current_slide))->prev == NULL)
                {
                    m_prev->setIsDisabled(VFX_TRUE);
                }
                else
                {
                    m_prev->setIsDisabled(VFX_FALSE);
                }
                if((*(getMsgCntx()->current_slide))->next == NULL)
                {
                    m_next->setIsDisabled(VFX_TRUE);
                }
                else
                {
                    m_next->setIsDisabled(VFX_FALSE);
                }
            }
        }
        else
        {
            m_button_play->setSize(0, m_button_play->getSize().height);
            m_prev->setSize(0,m_prev->getSize().height);
            m_next->setSize(0,m_next->getSize().height);
        }
    }
    else
    {
        m_clock = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("MMSClock")), VappMmsClock);
        m_clock->m_signalLastSlideEnd.connect(this, &VappMmsViewerPage::onLastSlideEnd);
        m_clock->m_signalSlideSwitch.connect(this, &VappMmsViewerPage::onSlideSwitch);
        m_clock->m_signalMediaEnd.connect(this, &VappMmsViewerPage::onMediaEnd);
        if(m_clock->getClockState() == VappMmsClock::STATE_NONE && m_data->checkViewerDataReady())
        {
            m_clock->startClock(VFX_FALSE);
        }
    }
    VfxU16 ucs[100], temp[10];
    VfxU32 titleheight = 0;
    mma_mms_description_struct *desc = srv_mms_get_desc_pointer();
    kal_wsprintf(temp, ": %d/%d", srv_mms_viewer_get_current_slide_num(), srv_mms_viewer_get_total_slide_num());
    mmi_ucs2cpy((S8 *)ucs, (S8 *)get_string(STR_ID_VAPP_MMS_SLIDE)) ;
    mmi_ucs2ncat((S8 *)ucs, (S8 *)temp, 10);
    txt.loadFromMem(ucs);
    if(m_mode == MODE_STOP)
    {
        titleheight = m_contact_bar->getRect().getMaxY();
        if(mmi_ucs2strlen((PS8)m_data->getMsgInfo()->subject) > 0)
        {
            VfxU16 ucs[SUBJECT_TOTAL_LEN];
            VfxWString txt;
            VfxFontDesc font;
            font.size = VFX_FONT_DESC_VF_SIZE(SUBJECT_FONT_SIZE);
            mmi_ucs2cpy((S8 *)ucs, (S8 *)get_string(STR_ID_VAPP_MMS_SUBJECT)) ;
            mmi_ucs2ncat((S8 *)ucs, (S8 *)m_data->getMsgInfo()->subject, MMA_MAX_SUBJECT_LEN);
            txt.loadFromMem(ucs);
            m_subject_txt->setAutoResized(VFX_TRUE);
            m_subject_txt->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
            m_subject_txt->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
            m_subject_txt->setFont(font);  
            m_subject_txt->setString(txt);
            m_subject_txt->setFullLineHeightMode(VFX_FALSE);
            if(m_contact_bar && m_contact_bar->getSize().height > 0)
            {
                m_subject_txt->setPos(VfxPoint(m_subject_txt->getRect().getX(), m_contact_bar->getRect().getMaxY() + SUBJECT_UPPER_MARGIN - m_contact_bar->getShadowHeight()));
            }
            else
            {
                m_subject_txt->setPos(VfxPoint(m_subject_txt->getRect().getX(), m_contact_bar->getRect().getMaxY() + SUBJECT_UPPER_MARGIN));
            }
            m_subject_txt->setSize(getSize().width - m_subject_txt->getRect().getX(), m_subject_txt->getRect().getHeight());
            titleheight = m_subject_txt->getRect().getMaxY();
        }
        else
        {
            VFX_OBJ_CLOSE(m_subject_txt);
            m_subject_txt = NULL;
            if(m_contact_bar && m_contact_bar->getSize().height > 0)
            {            
                titleheight = m_contact_bar->getRect().getMaxY() - m_contact_bar->getShadowHeight();
            }
            else
            {
                titleheight = m_contact_bar->getRect().getMaxY() ;
            }
        }
        m_dt_txt->setSize(getSize().width / 2,  m_dt_txt->getSize().height);
        m_dt_txt->setPos(getSize().width / 2,  getSize().height - m_dt_txt->getSize().height);
        m_dt_txt->setAlignParent(VFX_FRAME_ALIGNER_SIDE_BOTTOM, VFX_FRAME_ALIGNER_MODE_SIDE);
        m_button_play->setPos(m_button_play->getRect().getX(), m_dt_txt->getRect().getMinY() - m_button_play->getSize().height);
        m_prev->setPos(m_prev->getRect().getX(), m_dt_txt->getRect().getMinY() - m_prev->getSize().height);
        m_next->setPos(m_next->getRect().getX(), m_dt_txt->getRect().getMinY() - m_next->getSize().height);
        m_button_play->setAlignParent(VFX_FRAME_ALIGNER_SIDE_BOTTOM, VFX_FRAME_ALIGNER_MODE_SIDE);
        m_button_play->setBgImageList(VcpStateImage(IMG_ID_VENUS_MMS_BG_N, IMG_ID_VENUS_MMS_BG_P, IMG_ID_VENUS_MMS_BG_D, 0));
        m_prev->setBgImageList(VcpStateImage(IMG_ID_VENUS_MMS_BG_N, IMG_ID_VENUS_MMS_BG_P, IMG_ID_VENUS_MMS_BG_D, 0));
        m_next->setBgImageList(VcpStateImage(IMG_ID_VENUS_MMS_BG_N, IMG_ID_VENUS_MMS_BG_P, IMG_ID_VENUS_MMS_BG_D, 0));
        m_prev->setAlignParent(VFX_FRAME_ALIGNER_SIDE_BOTTOM, VFX_FRAME_ALIGNER_MODE_SIDE);
        m_next->setAlignParent(VFX_FRAME_ALIGNER_SIDE_BOTTOM, VFX_FRAME_ALIGNER_MODE_SIDE);
        VfxFontDesc font;
        font.size = VFX_FONT_DESC_VF_SIZE(DT_FONT_SIZE);
        VfxColor color(DT_FONT_A, DT_FONT_R, DT_FONT_G, DT_FONT_B);
        m_title_txt->setFont(font);  
        m_title_txt->setAutoResized(VFX_FALSE); 
        m_title_txt->setColor(color);
        m_title_txt->setMargins(SLIDE_BAR_LEFT_MARGIN,
                                DATE_TIME_BAR_TOP_MARGIN,
                                DATE_TIME_BAR_RIGHT_MARGIN,
                                0
                                );
        m_title_txt->setString(txt);
        m_title_txt->setPos(VfxPoint(m_title_txt->getRect().getX(), m_dt_txt->getRect().getY()));
        m_title_txt->setSize(getSize().width / 2,  m_dt_txt->getSize().height);
        m_title_txt->setAlignParent(VFX_FRAME_ALIGNER_SIDE_BOTTOM, VFX_FRAME_ALIGNER_MODE_SIDE);
        m_title_txt->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
        if(m_subject_txt)
        {	
            m_view_size_txt->setPos(VfxPoint(m_subject_txt->getPos().x, titleheight + MMS_VIEW_SIZE_TOP_MARGIN));
        }
        else
        {			
            m_view_size_txt->setPos(VfxPoint(MMS_VIEW_SIZE_LEFT_MARGIN, titleheight + MMS_VIEW_SIZE_TOP_MARGIN));
        }

        VfxWString str11;
        VfxWString str4;
        char str5[10];
        VfxWString str6;
        memset(str5,0,10);
        str4.loadFromRes(STR_ID_VAPP_MMS_SIZE);
        if(m_data->getMsgInfo()->msg_size>= 1024)
        {
            sprintf(str5,"%d",m_data->getMsgInfo()->msg_size/1024);
        }
        else
        {
            sprintf(str5,"%d",m_data->getMsgInfo()->msg_size);
        }
        str11.format("%s", str5);
        str4 += str11;
        if(m_data->getMsgInfo()->msg_size >= 1024)
        {
            str6.loadFromRes(STR_ID_VAPP_MMS_KB);
        }
        else
        {
            str6.loadFromRes(STR_ID_VAPP_MMS_BYTES);
        }
        str4 += VFX_WSTR(" ");
        str4 += str6;
        m_view_size_txt->setAutoFontSize(VFX_FALSE); 
        m_view_size_txt->setAutoResized(VFX_TRUE);
        font.size = VFX_FONT_DESC_VF_SIZE(MMS_VIEW_FONT_SIZE);
        m_view_size_txt->setFont(font);
        m_view_size_txt->setString(str4);
        m_view_size_txt->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
        m_view_size_txt->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));
        m_view_size_txt->forceUpdate();
    }
    else
    {
        VfxFontDesc font;
        VfxFrame *parent = (VfxFrame *)m_title_txt->getParent();
        font.size = VFX_FONT_DESC_VF_SIZE(TITLE_PLAY_FONT_SIZE);
        m_title_txt->setFont(font);  
        m_title_txt->setSize(getSize().width, parent->getSize().height);
        m_title_txt->setMargins(TITLE_PLAY_LEFT_MARGIN,
                                TITLE_PLAY_TOP_MARGIN,
                                0,
                                0);
        m_title_txt->setAutoResized(VFX_FALSE);
        m_title_txt->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
        m_button_play = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("m_button_play")), VcpButton);
        m_prev = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("previous")), VcpButton);
        m_next = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("next")), VcpButton);
        if(m_mode == MODE_PLAY)
        {
            m_button_play->setSize(0,0);
            m_prev->setSize(0,0);
            m_next->setSize(0,0);
        }
        m_title_txt->setString(txt);
    }		
	alignAllChilds();	
	VfxXmlLoader::loadEnd();
}

void VappMmsViewerPage::loadAllComponentsFromXml(void)
{
    m_panel = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("Panel")), VcpPagePanel);
    m_main_cp = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("MMSContent")), VappMmsViewerCp);
    if(m_mode == MODE_STOP)
    {
        m_dt_txt = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("DateTime")), VfxTextFrame);
        m_dt_txt->setAutoResized(VFX_FALSE);
        m_subject_txt = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("Subject")), VfxTextFrame);
        m_subject_txt->setAutoResized(VFX_FALSE);
        m_view_size_txt = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("MmsSize")), VfxTextFrame);	
        m_view_size_txt->setAutoResized(VFX_FALSE);	
    }
    m_detail_viewer = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("MMSContentEx")), VappMmsDetailsViewer);
    m_title_txt = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("Slider")), VfxTextFrame);
    m_title_txt->setAutoResized(VFX_FALSE);
    m_button_play = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("m_button_play")), VcpButton);
    m_prev = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("previous")), VcpButton);
    m_next = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("next")), VcpButton);
    m_button_play->setAutoAnimate(VFX_FALSE);
    m_prev->setAutoAnimate(VFX_FALSE);
    m_next->setAutoAnimate(VFX_FALSE);	
}
void VappMmsViewerPage::onDownloadDone( VfxFrame *frame,VfxBool done)
{
    if(done == VFX_TRUE)
    {
        m_noload = VFX_TRUE;
        if(m_detail_viewer && m_detail_viewer->isValid())
        {
            VFX_OBJ_CLOSE(m_detail_viewer);
        }
        m_detail_viewer = NULL;
        VappMmsViewerData *p_data;
        VFX_OBJ_CREATE_EX(p_data, VappMmsViewerData, this, (m_data->getMsgId(), VappMmsViewerData::MODE_FULL));
        VFX_OBJ_CLOSE(m_data);
        m_data = NULL;
        m_data = p_data;
        if(m_data->checkDataReady() == VFX_FALSE)
        {
            m_data->m_signalMmsViewerServiceDone.connect(this, &VappMmsViewerPage::onDataReady);
            if(m_data->getDataReady() == VFX_TRUE)
            {
                //show progress
                VFX_OBJ_CREATE(m_popup,VcpActivityIndicator,this);
                m_popup->setPos(getRect().getX() + (getSize().width / 2) - 20, getRect().getY()+ (getSize().height / 2) - 20);
                m_popup->setSize(40, 40);
                m_popup->start();
            }
            return;
        }
    }
}
void VappMmsViewerPage::alignAllChilds(void)
{
    if(m_contact_bar)
    {
        m_contact_bar->setAlignParent(VFX_FRAME_ALIGNER_SIDE_LEFT, VFX_FRAME_ALIGNER_MODE_SIDE);
        m_contact_bar->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, VFX_FRAME_ALIGNER_MODE_SIDE);
    }
    if(m_title_txt)
    {
        m_title_txt->setAlignParent(VFX_FRAME_ALIGNER_SIDE_LEFT, VFX_FRAME_ALIGNER_MODE_SIDE);
    }
    if(m_subject_txt)
    {
        m_subject_txt->setAlignParent(VFX_FRAME_ALIGNER_SIDE_LEFT, VFX_FRAME_ALIGNER_MODE_SIDE);
        m_subject_txt->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, VFX_FRAME_ALIGNER_MODE_SIDE);
        m_subject_txt->setColor(VFX_COLOR_RES(VAPP_MMS_VIEWER_TEXT_COLOR));
    }
    if(m_dt_txt)
    {
        m_dt_txt->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, VFX_FRAME_ALIGNER_MODE_SIDE);
    }
    if(m_clock)
    {
        m_clock->setAlignParent(VFX_FRAME_ALIGNER_SIDE_LEFT, VFX_FRAME_ALIGNER_MODE_SIDE);
        m_clock->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, VFX_FRAME_ALIGNER_MODE_SIDE);
    }
    if(m_panel)
    {
        m_panel->setAlignParent(VFX_FRAME_ALIGNER_SIDE_LEFT, VFX_FRAME_ALIGNER_MODE_SIDE);
        m_panel->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, VFX_FRAME_ALIGNER_MODE_SIDE);
    }
}
void VappMmsViewerPage::loadContactBar(void)
{
    m_contact_bar = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("ContactBar")), VappMsgContactBar);
    if(m_contact_bar)
    {
        VfxWString txt;
        mma_folder_enum m_box_type = mma_get_box(m_data->getMsgId());
        if(m_box_type == MMA_FOLDER_TEMPLATE || m_box_type == MMA_FOLDER_USRDEF_TEMPLATE)
        {
            m_contact_bar->setSize(0, 0);
            return;
        }
        if(m_box_type == MMA_FOLDER_INBOX
            || (m_box_type == MMA_FOLDER_ARCHIVE && m_data->getMsgInfo()->from_folder == MMA_FOLDER_INBOX))
        {
            if(m_data->getMsgInfo()->from_address_type == MMA_ADDR_TYPE_PHONE_NUMBER)
            {
                m_contact_bar->setContact(txt.loadFromMem(m_data->getMsgInfo()->from_address), VAPP_MSG_CONTACT_TYPE_PHONENUMBER);
            }
            else if(m_data->getMsgInfo()->from_address_type == MMA_ADDR_TYPE_EMAIL)
            {
                m_contact_bar->setContact(txt.loadFromMem(m_data->getMsgInfo()->from_address), VAPP_MSG_CONTACT_TYPE_EMAIL);
            }
            else
            {		
                m_contact_bar->setContact(txt, VAPP_MSG_CONTACT_TYPE_NONE);
            }
        }
        if(m_box_type == MMA_FOLDER_OUTBOX || m_box_type == MMA_FOLDER_SENT
            || (m_box_type == MMA_FOLDER_ARCHIVE && m_data->getMsgInfo()->from_folder == MMA_FOLDER_OUTBOX)
            ||  m_data->getMsgInfo()->from_folder == MMA_FOLDER_SENT)
        {
            if(m_data->getHeaderInfo()->to_head)
            {
                if(m_data->getHeaderInfo()->to_head->type == SRV_MMS_ADDRESS_TYPE_PHONE_NUMBER)
                {
                    m_contact_bar->setContact(txt.loadFromMem((PU16)m_data->getHeaderInfo()->to_head->addr), VAPP_MSG_CONTACT_TYPE_PHONENUMBER);
                }
                else if(m_data->getHeaderInfo()->to_head->type == SRV_MMS_ADDRESS_TYPE_EMAIL)
                {
                    m_contact_bar->setContact(txt.loadFromMem((PU16)m_data->getHeaderInfo()->to_head->addr), VAPP_MSG_CONTACT_TYPE_EMAIL);
                }
                else
                {		
                    m_contact_bar->setContact(txt, VAPP_MSG_CONTACT_TYPE_NONE);
                }
            }
        }
    #ifdef __COSMOS_MMS_VIEWER_CONTACT_BAR_STATUS_ICON__	
        if(m_box_type == MMA_FOLDER_INBOX
            || (m_box_type == MMA_FOLDER_ARCHIVE && m_data->getMsgInfo()->from_folder == MMA_FOLDER_INBOX))
        {
            VfxImageSrc img((VfxResId)IMG_ID_VENUS_MMS_RECEIVE);
            m_contact_bar->setStatusIcon(img);
        }
        else if(m_box_type == MMA_FOLDER_SENT
                || (m_box_type == MMA_FOLDER_ARCHIVE && m_data->getMsgInfo()->from_folder == MMA_FOLDER_SENT))
        {
            VfxImageSrc img((VfxResId)IMG_ID_VENUS_MMS_SEND);
            m_contact_bar->setStatusIcon(img);
        }
        else if(m_box_type == MMA_FOLDER_OUTBOX
                || (m_box_type == MMA_FOLDER_ARCHIVE && m_data->getMsgInfo()->from_folder == MMA_FOLDER_OUTBOX))
        {
            srv_mms_msg_status_enum status = srv_mms_get_msg_status(m_data->getMsgId());
            if(status == SRV_MMS_MSG_STATUS_SENDING_FAILED)
            {
                VfxImageSrc img((VfxResId)IMG_ID_VENUS_MMS_SEND_FAIL);
                m_contact_bar->setStatusIcon(img);
            }
        } 
    #endif/*__COSMOS_MMS_VIEWER_CONTACT_BAR_STATUS_ICON__*/
        VfxImageSrc img1(0), img2(0);
        if(getMsgCntx() && getMsgCntx()->show_attachment_icon == MMI_TRUE)
        {
            img1.setResId((VfxResId)IMG_ID_VENUS_MMS_ATTACHMENT);
        }
    #if(MMI_MAX_SIM_NUM == 4)
        if(m_data->getMsgInfo()->msg_sim_info == MMA_SIM_ID_SIM4)
        {
            img2.setResId((VfxResId)IMG_COSMOS_SIM4);
        }
        else 
    #endif /*MMI_MAX_SIM_NUM = n*/
    #if(MMI_MAX_SIM_NUM >= 3)
        if(m_data->getMsgInfo()->msg_sim_info == MMA_SIM_ID_SIM3)
        {
            img2.setResId((VfxResId)IMG_COSMOS_SIM3);
        }
        else
    #endif /*MMI_MAX_SIM_NUM = n*/
    #if(MMI_MAX_SIM_NUM >= 2)
        if(m_data->getMsgInfo()->msg_sim_info == MMA_SIM_ID_SIM2)
        {
            img2.setResId((VfxResId)IMG_COSMOS_SIM2);
        }
        else 
    #endif /*MMI_MAX_SIM_NUM = n*/
    #if(MMI_MAX_SIM_NUM > 1)
        if(m_data->getMsgInfo()->msg_sim_info == MMA_SIM_ID_SIM1)
        {
            img2.setResId((VfxResId)IMG_COSMOS_SIM1);
        }
    #endif /*MMI_MAX_SIM_NUM = n*/
        if(m_box_type != MMA_FOLDER_INBOX &&
            ((m_data->getHeaderInfo()->to_num + m_data->getHeaderInfo()->cc_num + m_data->getHeaderInfo()->bcc_num) > 0))
        {
            VappMmsContactProvider *contactProvider;
            VFX_OBJ_CREATE(contactProvider, VappMmsContactProvider, m_contact_bar);
            contactProvider->setMsgID(m_data->getMsgId());
            contactProvider->m_signalMmsClose.connect(this, &VappMmsViewerPage::onContactProviderCloseCall);
            m_contact_bar->setContact(contactProvider);
            m_contact_bar->setMode(VAPP_MSG_BAR_MODE_SHOW_LIST_ALWAYS);
        }
        m_contact_bar->setRightIcon(img2, img1);
        m_contact_bar->setSize(getSize().width, m_contact_bar->getSize().height);
    }
}

void VappMmsViewerPage::onContactProviderCloseCall(void)
{
    searchAndDelete();
}
#ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
void VappMmsViewerPage::onUseDetailsReady(void)
{
    if(m_tool_bar)
    {
        m_tool_bar->updatToolbar();
    }
}
#endif/*__MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__*/
void VappMmsViewerPage::setBounds(const VfxRect &value)
{
    VfxPage::setBounds(value);
    VappMmsViewerPage::myPage = (VfxPage *)this;
    if(getMsgType() != MMA_MSG_TYPE_MMS && m_mode == MODE_STOP)
    {
        return;
    }
    if(m_mode == MODE_STOP && m_button_play)
    {
        VfxU32 Y = 0;
        if(m_view_size_txt)
        {
            Y = m_view_size_txt->getRect().getMaxY();
        }
        else if(m_subject_txt)
        {
            Y = m_subject_txt->getRect().getMaxY();
        }
        else
        {
            Y = m_contact_bar->getRect().getMaxY();
        }
        m_panel->setPos(VfxPoint(0, Y));
        m_panel->setBounds(VfxRect(0, 0, getSize().width, m_button_play->getRect().getMinY() - Y));
        m_main_cp->setBounds(m_panel->getBounds());
        m_main_cp->setSize(getSize().width,m_button_play->getRect().getMinY() - Y - CP_MARGIN_BETWEEN_BUTTON);
        if(m_data->checkViewerDataReady())
        {
            handleResizeButton();
        }
    }
    else if(m_main_cp && m_button_play)
    {
        if(m_mode == MODE_PAUSE && m_data->checkViewerDataReady())
        {
            handleResizeButton();
        }
        m_panel->setSize(getSize().width, getPanelHeight());
        m_main_cp->setBounds(m_panel->getBounds());
        if(m_mode == MODE_PAUSE)
        {
            m_main_cp->setSize(getSize().width,getPanelHeight()- CP_MARGIN_BETWEEN_BUTTON);
        }
    }
}
void VappMmsViewerPage::deleteAllChilds(void)
{
    if(m_prev)
    {
        VFX_OBJ_CLOSE(m_prev);
        m_prev = NULL;
    }
    if(m_button_play)
    {
        VFX_OBJ_CLOSE(m_button_play);
        m_button_play = NULL;
    }
    if(m_next)
    {
        VFX_OBJ_CLOSE(m_next);
        m_next = NULL;
    }
    if(m_attach)
    {
        VFX_OBJ_CLOSE(m_attach);
        m_attach = NULL;
    }
    if(m_clock)
    {
        VFX_OBJ_CLOSE(m_clock);
        m_clock = NULL;
    }
    if(m_dt_txt)
    {
        VFX_OBJ_CLOSE(m_dt_txt);
        m_dt_txt = NULL;
    }
    if(m_subject_txt)
    {
        VFX_OBJ_CLOSE(m_subject_txt);
        m_subject_txt = NULL;
    }
    if(m_view_size_txt)
    {
        VFX_OBJ_CLOSE(m_view_size_txt);
        m_view_size_txt = NULL;
    }
    if(m_title_txt)
    {
        VFX_OBJ_CLOSE(m_title_txt);
        m_title_txt = NULL;
    }
    if(m_main_cp)
    {
        m_main_cp->deInitCp();
        VFX_OBJ_CLOSE(m_panel);
        m_panel = NULL;
        m_main_cp = NULL;
        m_detail_viewer = NULL;
    }
    if(m_contact_bar)
    {
        VFX_OBJ_CLOSE(m_contact_bar);
        m_contact_bar = NULL;
    }
    if(m_tool_bar)
    {
        VFX_OBJ_CLOSE(m_tool_bar);
        m_tool_bar = NULL;
    }
}
void VappMmsViewerPage::onDeinit(void)
{
    if(getMsgType() == MMA_MSG_TYPE_MMS && m_data->checkViewerDataReady())
    {
        m_data->checkDataReady();
        if(m_main_cp)
        {
            m_main_cp->deInitCpExt();
        }
    }
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VappMmsViewerPage::listener, getObjHandle());
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, &VappMmsViewerPage::listener, getObjHandle());
#endif/*__MMI_USB_SUPPORT__*/
#ifdef __MMI_MMS_USE_ASM__  
        mmi_frm_cb_dereg_event(EVT_ID_SRV_MMS_SERVICE_MEM_FREE_DONE, &VappMmsViewerPage::listener, getObjHandle());
#endif

    VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    if (NCenter)
    {
        NCenter->m_signalEvent.disconnect(this, &VappMmsViewerPage::onNCenterStatus);
    }
    if(MODE_STOP == m_mode)
    { 
    
        ((VappMsgApp *)getMainScr()->getApp())->setSubMsgCareHomeKeyCb(&VappMmsViewerPage::checkmmspageisgetcontent,getObjHandle());
    }
    VfxPage::onDeinit();

}
void VappMmsViewerPage::deleteAppInstance(void *user_data)
{
    VappMmsViewerPage *my_data = (VappMmsViewerPage *)VfxObject::handleToObject((VfxObjHandle)user_data);
    if(my_data && my_data->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsViewerPage)) )
    {
        my_data->getMainScr()->popPage();		
    }
}

VfxPageBar  *VappMmsViewerPage::getToolBar(VfxPageBarLocationEnum loc)
{
        return getBar(loc);
}

void VappMmsViewerPage::onClick(VfxObject *obj, VfxId id)
{
    mmi_id grpId = getMainScr()->getApp()->getGroupId();
    m_cui_id = cui_vapp_mms_view_mms_create(grpId, getMyData()->getMsgId(), getMyData()->getMyIndex(), m_msg_location);
    vfxSetCuiCallerScr(m_cui_id, getMainScr());
    cui_vapp_mms_preview_mms_run(m_cui_id);
}
void VappMmsViewerPage::onClickPause(VfxObject *obj, VfxId id)
{
    m_mode = MODE_PLAY;
    m_button_play->setSize(0, 0);
    m_prev->setSize(0, 0);
    m_next->setSize(0, 0);
    VappMmsAudioPlay *m_audio = m_main_cp->getAudio();
    mma_mms_description_struct *desc = srv_mms_get_desc_pointer();
    srv_mms_viewer_slide_struct * current_slide = desc->body->curr_slide;
    if(m_audio && current_slide->duration != 0)
    {
        m_audio->resumeAudio();
    }
    
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
    VappVideoPlayerComponent *m_video = (VappVideoPlayerComponent *)m_main_cp->getVideo();
    if(m_video && m_video->getState() == VGPS_PAUSED && current_slide->duration != 0 && m_main_cp->videoisfinished() != VFX_TRUE)
    {
        m_video->play(); 
        m_video->m_signalPlaybackFinished.connect(this, &VappMmsViewerCp::onVideoPlaybackFinish);
    }
#endif    
    m_panel->setSize(getSize().width, getPanelHeight());
    m_main_cp->setBounds(m_panel->getBounds());
    m_clock->startClock(VFX_TRUE);
}

VfxU32 VappMmsViewerPage::getPanelHeight(void)
{
    if(m_button_play->getSize().height == 0)
    {
        return getSize().height;
    }
    else
    {
        return (getSize().height - m_button_play->getSize().height - BUTTON_BOTTOM_MARGIN);
    }
}
#if(0)
void VappMmsViewerPage::onClickAttachment(VfxObject *obj, VfxId id)
{
    VappMmsAttachmentsPage *m_attachments;
    VFX_OBJ_CREATE(m_attachments, VappMmsAttachmentsPage, this);
    this->getMainScr()->pushPage(0, m_attachments);	
}
#endif
void VappMmsViewerPage::onClickNext(VfxObject *obj, VfxId id)
{
    mma_mms_description_struct *desc = srv_mms_get_desc_pointer();
    srv_mms_viewer_xml_msg_struct *msg_cntx = getMsgCntx();
    /*This check is because Venus Engine seems to send event even button's dimenstions are 0,0*/
    MMS_BODY_ERROR_HANDLE(desc);
    if(msg_cntx == NULL)
    {
        return;
    }
    srv_mms_viewer_slide_struct *current_slide = *(msg_cntx->current_slide);
#ifdef __DRM_SUPPORT__	
    if(current_slide->img.id)
    {
        VappMmsDrmHandler::stopConsumeRights(&(current_slide->img), m_data->getMyIndex());
    }
#endif/*__DRM_SUPPORT__*/	
    if(current_slide->next != NULL)
    {
        *(msg_cntx->current_slide)  = (*(msg_cntx->current_slide))->next;
    }
    m_slideCount = desc->body->curr_slide->slide_num;
    if(m_mode == MODE_PAUSE || m_mode == MODE_PLAY)
    {
        m_mode = MODE_PLAY;
        m_button_play->setSize(0, 0);
        m_prev->setSize(0, 0);
        m_next->setSize(0, 0);
        m_clock->setTime(0, 0, 0);
        m_clock->changeState(VappMmsClock::STATE_RUNNING);/*MAUI_03070027*/
        m_clock->startClock(VFX_FALSE);
    }
    m_main_cp->deInitCp();
    m_main_cp->setState(VappMmsViewerCp::REDRAW_NEEDED);
    upDateInternal();
}
void VappMmsViewerPage::handleRRRequest(void)
{
    /*Update COntact Bar*/
    VfxImageSrc img1(0), img2(0);
    if(getMsgCntx()->show_attachment_icon == MMI_TRUE)
    {
        img1.setResId((VfxResId)IMG_ID_VENUS_MMS_ATTACHMENT);
    }
#if(MMI_MAX_SIM_NUM == 4)
    if(m_data->getMsgInfo()->msg_sim_info == MMA_SIM_ID_SIM4)
    {
        img2.setResId((VfxResId)IMG_COSMOS_SIM4);
    }
    else 
#endif /*MMI_MAX_SIM_NUM = n*/
#if(MMI_MAX_SIM_NUM >= 3)
    if(m_data->getMsgInfo()->msg_sim_info == MMA_SIM_ID_SIM3)
    {
        img2.setResId((VfxResId)IMG_COSMOS_SIM3);
    }
    else
#endif /*MMI_MAX_SIM_NUM = n*/
#if(MMI_MAX_SIM_NUM >= 2)
    if(m_data->getMsgInfo()->msg_sim_info == MMA_SIM_ID_SIM2)
    {
        img2.setResId((VfxResId)IMG_COSMOS_SIM2);
    }
    else 
#endif /*MMI_MAX_SIM_NUM = n*/
#if(MMI_MAX_SIM_NUM > 1)
    if(m_data->getMsgInfo()->msg_sim_info == MMA_SIM_ID_SIM1)
    {
        img2.setResId((VfxResId)IMG_COSMOS_SIM1);
    }
#endif /*MMI_MAX_SIM_NUM = n*/
    if(m_contact_bar)
    {
        m_contact_bar->setRightIcon(img2, img1);
    }
    MmsRRResultTypeEnum result = m_data->decideReadReport();
	COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_RR_STATUS, result);
    if(result == MMS_SEND_RR_TRUE)
    {
        VcpConfirmPopup *rrConfirm;
        VFX_OBJ_CREATE(rrConfirm, VcpConfirmPopup, this);
        VfxWString txt(STR_ID_VAPP_MMS_VIEWER_SEND_RR_CONFIRM);
        rrConfirm->setText(txt);
        rrConfirm->setInfoType(VCP_POPUP_TYPE_QUESTION);

        rrConfirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        rrConfirm->setCustomButton(
                                    VFX_WSTR_RES(STR_GLOBAL_SEND),                                // [IN] button 1 text
                                    VFX_WSTR_RES(STR_ID_VAPP_MMS_VIEWER_SEND_RR_CONFIRM_DONT_SEND)  // [IN] button 2 text
                                    );
        rrConfirm->m_signalButtonClicked.connect(this, &VappMmsViewerPage::onConfirmRR);
        //rrConfirm->m_signalPopupState.connect(this, &VappMmsViewerPage::onDeleteCell);
        rrConfirm->setAutoDestory(VFX_FALSE);
        rrConfirm->show(VFX_TRUE);
        return;
    }
#if(MMI_MAX_SIM_NUM >= 2)
    else if(result == MMS_SEND_RR_ERROR)
    {
        VappMmsPopup m_popup(STR_ID_VAPP_MMS_SIM_INVALID, VCP_POPUP_TYPE_FAILURE, this, (clickOk)&VappMmsViewerPage::onClickRRErrorOk);           
        m_popup.displayPopup();
        return;
    }
#endif/*MMI_MAX_SIM_NUM*/
}

void VappMmsViewerPage::upDateInternal(void)
{
    if(m_title_txt)
    {
        VfxU16 ucs[100], temp[10];
        VfxWString txt;
        mma_mms_description_struct *desc = srv_mms_get_desc_pointer();
        kal_wsprintf(temp, ": %d/%d", srv_mms_viewer_get_current_slide_num(), srv_mms_viewer_get_total_slide_num());
        mmi_ucs2cpy((S8 *)ucs, (S8 *)get_string(STR_ID_VAPP_MMS_SLIDE)) ;
        mmi_ucs2ncat((S8 *)ucs, (S8 *)temp, 10);
        txt.loadFromMem(ucs);
        m_title_txt->setString(txt);
    }
    srv_mms_viewer_slide_struct *current_slide = *(getMsgCntx()->current_slide);
    if(m_mode == MODE_STOP)
    {
        if(current_slide->prev == NULL)
        {
            m_prev->setIsDisabled(VFX_TRUE);
        }
        else
        {
            m_prev->setIsDisabled(VFX_FALSE);
        }
        if(current_slide->next == NULL)
        {
            m_next->setIsDisabled(VFX_TRUE);
        }
        else
        {
            m_next->setIsDisabled(VFX_FALSE);
        }
    }
    handleResizeButton();
    setBounds(getBounds());
}
void VappMmsViewerPage::onClickPrev(VfxObject *obj, VfxId id)
{
    srv_mms_viewer_xml_msg_struct *msg_cntx = getMsgCntx();
    /*This check is because Venus Engine seems to send event even button's dimenstions are 0,0*/
    if(msg_cntx == NULL)
    {
        return;
    }
    mma_mms_description_struct *desc = srv_mms_get_desc_pointer();
    srv_mms_viewer_slide_struct *current_slide = *(msg_cntx->current_slide);
#ifdef __DRM_SUPPORT__	
    if(current_slide->img.id)
    {
        VappMmsDrmHandler::stopConsumeRights(&(current_slide->img), m_data->getMyIndex());
    }
#endif/*__DRM_SUPPORT__*/	
    if(current_slide->prev != NULL)
    {
        *(msg_cntx->current_slide)  = (*(msg_cntx->current_slide))->prev;
    }
    MMS_BODY_ERROR_HANDLE(desc);
    m_slideCount = desc->body->curr_slide->slide_num;
    if(m_mode == MODE_PAUSE || m_mode == MODE_PLAY)
    {
        m_mode = MODE_PLAY;
        m_button_play->setSize(0, 0);
        m_prev->setSize(0, 0);
        m_next->setSize(0, 0);
        m_clock->setTime(0, 0, 0);
        m_clock->changeState(VappMmsClock::STATE_RUNNING);/*MAUI_03070027*/
        m_clock->startClock(VFX_FALSE);
    }
    m_main_cp->deInitCp();
    m_main_cp->setState(VappMmsViewerCp::REDRAW_NEEDED);
    upDateInternal();
}
void VappMmsViewerCp::deInitCp(void)
{
    if(m_img_file_h)
    {
    #ifdef __DRM_SUPPORT__
        srv_mms_viewer_xml_msg_struct *msg_cntx;
        VappMmsViewerPage *parent = (VappMmsViewerPage *)m_page;
        msg_cntx = parent->getMsgCntx();
        if(msg_cntx)
        {
            srv_mms_viewer_slide_struct *current_slide = *(msg_cntx->current_slide);
            if(current_slide->img.id)
            {
                VappMmsDrmHandler::stopConsumeRights(&(current_slide->img), parent->m_data->getMyIndex());
            }
        }
    #endif		
        FS_Close(m_img_file_h);
        m_img_file_h = 0;
    }
    if(m_text_file_h)
        {
        FS_Close(m_text_file_h);
        m_text_file_h = 0;
    }
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
    if(m_video_file_h)
    {
        ((VappVideoPlayerComponent *)m_visual->getFrame())->closeFile();
        FS_Close(m_video_file_h);
        m_video_file_h = 0;
    }
    vidState = VIDEO_STATE_NONE;
#endif
    if(m_audio)
    {
        m_audio->deinitAudio();
        m_audio = NULL;
    }
    if(m_main_txt)
    {
        VFX_OBJ_CLOSE(m_main_txt);
        m_main_txt = NULL;
        m_visual = NULL;
    }
}
void VappMmsViewerCp::deInitCpExt(void)
{
	COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS,TRC_VAPP_MMS_DEINIT_CP,__LINE__); 

    if(m_img_file_h)
    {
        FS_Close(m_img_file_h);
        m_img_file_h = 0;
    }
    if(m_text_file_h)
    {
        FS_Close(m_text_file_h);
        m_text_file_h = 0;
    }
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
    if(m_video_file_h)
    {
        ((VappVideoPlayerComponent *)m_visual->getFrame())->closeFile();
        FS_Close(m_video_file_h);
        m_video_file_h = 0;
    }
    vidState = VIDEO_STATE_NONE;
#endif
    if(m_audio)
    {
        m_audio->deinitAudio();
        m_audio = NULL;
    }
    if(m_main_txt)
    {
        VFX_OBJ_CLOSE(m_main_txt);
        m_main_txt = NULL;
        m_visual = NULL;
    }
}
#ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
void VappMmsViewerCp::onUseDetailsReady(srv_mms_viewer_result_enum error)
{
    if(error == SRV_MMS_VIEWER_OK)
    {
        VFX_OBJ_CLOSE(m_main_txt);
        m_main_txt = NULL;
        ((VappMmsViewerPage *)m_page)->onUseDetailsReady();
        m_state = REDRAW_NEEDED;
        setBounds(getBounds());
    }
}
#endif/*__MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__*/
void VappMmsViewerCp::handleMediaEnd(VfxU32 type)
{
    srv_mms_viewer_object_type_enum type_obj = (srv_mms_viewer_object_type_enum)type;
    if(type_obj == SRV_MMS_OBJECT_TYPE_TEXT)
    {
        m_state = REDRAW_TEXT_NEEDED;
    }
    else
    {
        m_state = REDRAW_MEDIA_NEEDED;
    }
    setBounds(getBounds());
}
void VappMmsViewerPage::onFolding(VfxObject* sender, VfxBool is_fold)
{
	
}
/*void VappMmsViewerPage::onToolBarClick(VfxObject* sender, VfxId id)
{
	switch(id)
	{
		case 123:
			VappMmsViewObjectsPage *m_view_objects;
			VFX_OBJ_CREATE(m_view_objects, VappMmsViewObjectsPage, this);
			 this->getMainScr()->pushPage(0, m_view_objects);
			break;
		case 234:
			VappMmsUseDetailsPage *m_use_details;
			VFX_OBJ_CREATE(m_use_details, VappMmsUseDetailsPage, this);
			 this->getMainScr()->pushPage(0, m_use_details);
			break;
		case 345:
			m_tool_bar->setDisableItem(IMG_GLOBAL_L1, VFX_FALSE);
			break;
		case 456:
			m_tool_bar->setDisableItem(IMG_GLOBAL_L1, VFX_FALSE);
			break;
		case 678:
			m_tool_bar->setDisableItem(IMG_GLOBAL_L1, VFX_FALSE);
			break;
		case 789:
			m_tool_bar->setDisableItem(IMG_GLOBAL_L1, VFX_FALSE);
			break;
	}	
}*/
void VappMmsViewerCp::onInit(void)
{
    VappMsgViewerCp::onInit();
    m_page = (VfxPage *)getParent()->getParent();
    setimagerealysize(0,0);
    m_state = REDRAW_NEEDED;
}
void VappMmsViewerPage::setButtonStateAfterOpenFile(void)
{
    if((*(getMsgCntx()->current_slide))->prev == NULL)
    {
        m_prev->setIsDisabled(VFX_TRUE);
    }
    else
    {
        m_prev->setIsDisabled(VFX_FALSE);
    }
    if((*(getMsgCntx()->current_slide))->next == NULL)
    {
        m_next->setIsDisabled(VFX_TRUE);
    }
    else
    {
        m_next->setIsDisabled(VFX_FALSE);
    }
    m_button_play->setIsDisabled(VFX_FALSE);
}
void VappMmsViewerPage::setbuttonstate(VcpButtonStateEnum m_button_state)
{
    if(VCP_BUTTON_STATE_NORMAL == m_button_state)
    {
        if(m_prev)
        {
            if(VCP_BUTTON_STATE_PRESSED == m_prev->getState())
            {
                changeButtonState(m_prev,m_button_state);
            }
        }
        if(m_button_play)
        {
            if(VCP_BUTTON_STATE_PRESSED == m_button_play->getState())
            {
                changeButtonState(m_button_play,m_button_state);
            }
        }
        if(m_next)
        {
            if(VCP_BUTTON_STATE_PRESSED == m_next->getState())
            {
                changeButtonState(m_next,m_button_state);
            }
        }
    }
}
void VappMmsViewerPage::onExit(VfxBool isBackward)
{
	COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS,TRC_VAPP_MMS_VIEWER_PAGE_EXIT,__LINE__); 

    VfxPage::onExit(isBackward);
    if(getMainScr()->getIsSnapshotDrawing() == VFX_TRUE)
    {
		COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_ON_ENTER_PAGE, isBackward, 4, m_data->getIsPreview()); 
        return;
    }
    if(m_main_cp)
    {
        m_main_cp->onExit(isBackward);
    }
#ifdef __DRM_SUPPORT__	
    if(getMsgType() == MMA_MSG_TYPE_MMS && m_data->checkViewerDataReady())
    {
        m_data->checkDataReady();
        mma_mms_description_struct *desc = srv_mms_get_desc_pointer();
        MMS_BODY_ERROR_HANDLE(desc);
        srv_mms_viewer_xml_msg_struct *msg_cntx = getMsgCntx();
        if(msg_cntx)
        {
            srv_mms_viewer_slide_struct *current_slide = *(msg_cntx->current_slide);
            if(current_slide && current_slide->img.id)
            {
                VappMmsDrmHandler::stopConsumeRights(&(current_slide->img), m_data->getMyIndex());
            }
        }
    }
#endif/*__DRM_SUPPORT__*/	
    setbuttonstate(VCP_BUTTON_STATE_NORMAL);
    if( m_mode == MODE_PLAY
        ||m_mode == MODE_PAUSE)
    {
        onPreviewPageFinish();
        return;
    }
}
void VappMmsViewerCp::onExit(VfxBool isBackward)
{
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__

    VappVideoPlayerComponent *m_video = getVideo();
    COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS,TRC_VAPP_MMS_CP_EXIT,__LINE__); 
    if(m_video)
    {
        if(m_video_file_h)
        {
            ((VappVideoPlayerComponent *)m_visual->getFrame())->closeFile();
            FS_Close(m_video_file_h);
            m_video_file_h = 0;
            m_video->m_signalPlaybackFinished.disconnect(this, &VappMmsViewerCp::onVideoPlaybackFinish);
            mmi_frm_cb_dereg_event(EVT_ID_SRV_PROF_IS_PLAYING, &VappMmsViewerCp::listener, getObjHandle());                
        }
    }
 #endif
}
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
VfxBool VappMmsViewerCp::videoisfinished(void)
{
    if(vidState == VIDEO_STATE_PLAYBACK_FINISH || vidState == VIDEO_STATE_FAIL)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}
#endif
void VappMmsViewerCp::setimagerealysize(VfxS32 width, VfxS32 height)
{
	image_realy_size.width = width;
	image_realy_size.height = height;
}

void VappMmsViewerCp::getimagerealysize(VfxS32 *width,VfxS32 *height)
{
	*width = image_realy_size.width;
	*height = image_realy_size.height;
}
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
void VappMmsViewerCp::setopenfilestate(VfxBool b_open_file )
{
    m_opening_file = b_open_file;
}
VfxBool VappMmsViewerCp::getopenfilestate(void)
{
    return m_opening_file;
}
VappVideoPlayerState VappMmsViewerCp::getVideoState(void)
{
    VappVideoPlayerComponent *m_frame = (VappVideoPlayerComponent *)m_visual->getFrame();
    return m_frame->getState();
}


void VappMmsViewerCp::onVideoPlaybackFinish(VappVideoPlayerComponent* m_player, MDI_RESULT result)
{
    //close video on playback finish
    COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS,TRC_VAPP_MMS_VIDEO_FINISH,__LINE__); 
    
    if(getVideo())
    {
        onExit(VFX_TRUE);
        vidState = VIDEO_STATE_PLAYBACK_FINISH;
    }	
}
#endif
VappMmsViewerData * VappMmsViewerPage::getMyData(void)
{
	return m_data;
}

#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
mmi_ret VappMmsViewerCp::listener(mmi_event_struct *evt)
{
    vapp_vol_dialog_evt_struct *evt_sound = (vapp_vol_dialog_evt_struct *)evt;
    VappMmsViewerCp *cp_obj = (VappMmsViewerCp *)VfxObject::handleToObject((VfxObjHandle)evt_sound->user_data);
    if(evt_sound->evt_id == EVT_ID_SRV_PROF_IS_PLAYING 
        &&cp_obj
        && cp_obj->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsViewerCp)) && cp_obj->m_visual)
    {           
        return !MMI_RET_OK;
    }
    return MMI_RET_OK;
}
#endif
void VappMmsViewerCp::setBounds(const VfxRect &value)
{
	
	COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS,TRC_VAPP_MMS_CP_SET_BOUNDS,__LINE__); 
    mma_mms_description_struct *desc = srv_mms_get_desc_pointer();
    VappMsgViewerCp::setBounds(value);
    VfxU32 txt_len = 0;
    VfxS32 max = VFX_MAX(getBounds().size.width, getBounds().size.height);
    VappMmsViewerPage *parent = (VappMmsViewerPage *)getParent()->getParent();
    VappMmsViewerData *my_data = parent->getMyData();
	
	COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_CHECK_TYPE_AND_MODE,parent->getMsgType(),parent->getMode(),__LINE__); 
    if(parent->getMsgType() != MMA_MSG_TYPE_MMS && parent->getMode() == MODE_STOP)
    {
		
		COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_SET_BOUNDS_REURN,__LINE__); 
        return;
    }	
	
	COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_DRAW_STATE,m_state,__LINE__); 
    if(parent->getMyData()->checkViewerDataReady() == VFX_FALSE)
    {
        if(m_state == REDRAW_NEEDED)
        {
            parent->getMyData()->m_signalMmsViewerServiceDone.connect(this, &VappMmsViewerCp::onContentReady);
        #ifdef __MMI_MMS_USE_ASM__  
            parent->m_wait_data_done = VFX_TRUE;
        #endif
            parent->getMyData()->getViewerContentReady();
            showLoading();
        }
        m_state = REDRAW_NONE;
		COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_SET_BOUNDS_REURN,__LINE__); 		
        return;
    }
    MMS_BODY_ERROR_CP_HANDLE(desc)
    srv_mms_viewer_slide_struct * current_slide = desc->body->curr_slide;
	if(current_slide == NULL)
	{
		m_state = REDRAW_NONE;		
		COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_SET_BOUNDS_REURN,__LINE__); 		
		return;
	}
	/*Set Background Color*/
    if(current_slide->txt.id &&
       current_slide->txt.bg_color &&
       current_slide->txt.str_id == 0)
    {
        VfxU32 color_gdi = current_slide->txt.bg_color << 8;
        VfxColor color = convertFromGdiColorToColor(color_gdi);
        if(color != VfxColor(VFX_COLOR_BLACK))
        {
            setBgColor(color);
        }
    }
    else
    {
        VfxU32 color_gdi = parent->getMsgCntx()->background_color << 8;
        VfxColor color = convertFromGdiColorToColor(color_gdi);
        if(color != VfxColor(VFX_COLOR_BLACK))
        {
            setBgColor(color);
        }
    }
#ifdef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__	
    if(my_data->checkUseDetailsDataReady() == VFX_FALSE)
    {
        if(m_state == REDRAW_NEEDED)
        {
            VFX_OBJ_CREATE(m_main_txt, VcpTextView, this);
            m_main_txt->setPos(VfxPoint(0, 0));
            m_main_txt->setBounds(VfxRect(0, 0, getRect().getWidth(), getRect().getHeight()/ 2));
            m_main_txt->setText(VfxResId(STR_GLOBAL_PLEASE_WAIT), NULL);
            m_main_txt->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
            m_main_txt->setAlignMode(VCP_TEXT_ALIGN_MODE_CENTER);
            my_data->getUseDetailsDataReady();
            my_data->m_signalMmsViewerUseDetailsDone.connect(this, &VappMmsViewerCp::onUseDetailsReady);
            m_main_txt->setAlignParent(
                                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                                        VFX_FRAME_ALIGNER_MODE_SIDE);
            /*Set Text Background color forceful black, because text color will always*/
            /*be in contrast with backgound color, as bg color can never be black*/
            m_main_txt->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_BLACK);
        }
        COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_SET_BOUNDS_REURN,__LINE__); 		
        m_state = REDRAW_NONE;
        return;
    }
    else
    {
        parent->onUseDetailsReady();
    }
#endif/*__MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__*/	
    if( m_state != REDRAW_NEEDED
        && m_state != REDRAW_TEXT_NEEDED
        && m_state != REDRAW_MEDIA_NEEDED)
    {
        if(m_main_txt)
        {
            upDatecpLayout();
            upDateMediaBounds();
            //m_main_txt->forceUpdate();
            if(m_visual)
            {
                m_main_txt->UpdateViewForCustomFrame();
            }
        }
        COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_SET_BOUNDS_REURN,__LINE__); 		
        return;
    }
	if(parent->m_clock && parent->m_clock->getClockState() == VappMmsClock::STATE_NONE)
	{
		parent->m_clock->startClock(VFX_FALSE);
	}
	/*Delete all created frames*/
	if(m_visual && (m_state == REDRAW_MEDIA_NEEDED || m_state == REDRAW_NEEDED))
    {
        if(m_img_file_h)
        {
            FS_Close(m_img_file_h);
            m_img_file_h = 0;
        }
        
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
        if(m_video_file_h)
        {
            if(m_video_file_h)
            {
                ((VappVideoPlayerComponent *)m_visual->getFrame())->closeFile();
                FS_Close(m_video_file_h);
                m_video_file_h = 0;
            }
        }
    #endif
        if(m_visual->isValid())
        {
        
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
            vidState = VIDEO_STATE_NONE;
#endif
            VFX_OBJ_CLOSE(m_visual);
        }
        m_visual = NULL;
    }
	if(m_main_txt && m_state == REDRAW_NEEDED)
	{
    #if(0)
		if(parent->getMode() == MODE_PLAY )
		{
			m_main_txt->stopScroll(); 
		}
    #endif
		VFX_OBJ_CLOSE(m_main_txt);
		m_main_txt = NULL;
	}
	VfxS32 curTime = -1;
	if(parent->m_clock)
	{
		curTime = (VfxS32)parent->m_clock->getTime();
	}
	
    /****AUDIO PLAY****/
    if(current_slide->aud.id
        && parent->getMode() == MODE_PLAY
        && !m_audio
        && curTime >= (VfxS32)current_slide->aud.begin
        && current_slide->duration != 0)
    {
        VFX_OBJ_CREATE_EX(m_audio, VappMmsAudioPlay, this, (&(current_slide->aud), parent->m_data->getMyIndex()));
        COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_PLAY_AUDIO,__LINE__); 		
        m_audio->playAudio();
    }
    else if(curTime > (VfxS32)current_slide->aud.end && m_audio)
    {
        COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_DEINIT_AUDIO,__LINE__);		
        m_audio->deinitAudio();
        m_audio = NULL;
    }
    /****AUDIO PLAY****/
    /*Decide Image and text coordinates move to xml later on*/
	/*Decide Image and text coordinates move to xml later on*/
	if(m_state == REDRAW_NEEDED)
	{
		VFX_OBJ_CREATE(m_main_txt, VcpTextView, this);
	}
	upDatecpLayout();
	/****Image Display******/
    if(current_slide->img.id && (m_state == REDRAW_MEDIA_NEEDED || m_state == REDRAW_NEEDED))
    {
        VfxWString file_path_ext;
        srv_mms_get_filename_by_id(&(current_slide->img), m_vfname, &m_img_file_path, &m_img_file_h);
        if(!m_img_file_path)
        {
            m_state = REDRAW_NONE;
            COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_SET_BOUNDS_REURN,__LINE__); 		
            return;
        }
        VFX_OBJ_CREATE_EX(m_visual, VappMmsVisual, m_main_txt, (SRV_MMS_OBJECT_TYPE_IMAGE, &(current_slide->img)));
        VfxImageFrame *m_frame = (VfxImageFrame *)m_visual->getFrame();
        COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_SLIDE_DURATION,current_slide->duration,__LINE__);	
        COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_CURRENT_TIME,curTime,__LINE__);	
        COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_SLIDE_BEGIN_TIME,current_slide->img.begin,__LINE__);
        COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_SLIDE_END_TIME,current_slide->img.end,__LINE__);		
        if(parent->getMode() == MODE_STOP || current_slide->duration == 0 ||
            (curTime >= (VfxS32)current_slide->img.begin &&  curTime <= (VfxS32)current_slide->img.end))
        {
#ifdef __DRM_SUPPORT__
            VappMmsDrmHandler::updateRightsById(&(current_slide->img), VFX_FALSE, parent->m_data->getMyIndex());
            if(VappMmsDrmHandler::checkRightsById(&(current_slide->img), parent->m_data->getMyIndex()) == MMI_FALSE)
            {
                if(VappMmsDrmHandler::startConsumeRights(&(current_slide->img), m_img_file_path, VappMmsViewerCp::onImageRightsExpiry, (void*) this, parent->m_data->getMyIndex())  == MMI_FALSE)
                {
                    m_frame->setResId(VfxResId(IMG_ID_VENUS_MMS_DRM_DEFAULT));
                }
                else
                {
#endif				
                    m_frame->setPath(file_path_ext.loadFromMem(m_img_file_path));
                    setimagerealysize(m_frame->getSize().width, m_frame->getSize().height);
                    if(m_frame->getSize().width == 0 || m_frame->getSize().height == 0)
                    {
                        m_frame->setResId(VfxResId(IMG_ID_VENUS_MMS_CORRUPT_IMAGE));
                    #ifdef __DRM_SUPPORT__						
                        VappMmsDrmHandler::stopConsumeRights(&(current_slide->img), parent->m_data->getMyIndex());
                    #endif
                    }
            #ifdef __DRM_SUPPORT__

                }
            }
            else
            {
                m_frame->setResId(VfxResId(IMG_ID_VENUS_MMS_DRM_DEFAULT));
            }
            #endif			
        }
    }
	
/****Image Display******/

/****Video Display******/
	COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_VIDEO_STATE,vidState,__LINE__);	
	COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_PAGE_ONENTER,parent->m_enter,__LINE__);	
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
	if(parent->m_enter == VFX_TRUE)
    {
        if(current_slide->vid.id && vidState != VIDEO_STATE_PLAYBACK_FINISH
            && (m_state == REDRAW_MEDIA_NEEDED || m_state == REDRAW_NEEDED))
        {
            VfxU16 vfname[SRV_MMS_VIEWER_VFN_NUM_OF_WCHAR];
            VfxU16 *file_path = NULL;
            VfxWString file_path_ext;
            srv_mms_get_filename_by_id(&(current_slide->vid), vfname, &file_path, &m_video_file_h);
            if(!file_path)
            {
                m_state = REDRAW_NONE;
                return;
            }
            VFX_OBJ_CREATE_EX(m_visual, VappMmsVisual, m_main_txt, (SRV_MMS_OBJECT_TYPE_VIDEO, &(current_slide->vid)));
            COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_SLIDE_DURATION,current_slide->duration,__LINE__);	

            COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_CURRENT_TIME,curTime,__LINE__);	
            COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_SLIDE_BEGIN_TIME,current_slide->vid.begin,__LINE__);

            COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_SLIDE_END_TIME,current_slide->vid.end,__LINE__);	

            if(parent->getMode() == MODE_STOP || current_slide->duration == 0 ||
                (curTime >= current_slide->vid.begin &&  curTime <= current_slide->vid.end))
            {
                VappVideoPlayerComponent *m_frame = (VappVideoPlayerComponent *)m_visual->getFrame();
                m_frame->m_signalFileOpened.connect(this, &VappMmsViewerCp::onFileReady);
                m_frame->setHidden(VFX_TRUE);
                if(parent->m_clock)
                {
                    parent->m_clock->waitClock();
                }
                //COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_OPEN_FILE,__LINE__);	
                m_frame->openFile(file_path_ext.loadFromMem(file_path));
                m_opening_file = VFX_TRUE;
                parent->m_prev->setIsDisabled(VFX_TRUE);
                parent->m_next->setIsDisabled(VFX_TRUE);
                parent->m_button_play->setIsDisabled(VFX_TRUE);
                //show progress
                if(m_video_popup)
                {                
                    VFX_OBJ_CLOSE(m_video_popup);
                    m_video_popup = NULL;
                }
                VFX_OBJ_CREATE(m_video_popup,VcpActivityIndicator,this);
                m_video_popup->setPos(getRect().getX() + (getSize().width / 2) - 20, getRect().getY()+ (getSize().height / 2) - 20);
                m_video_popup->setSize(40, 40);
                m_video_popup->setAlignParent(
                            VFX_FRAME_ALIGNER_MODE_MID, 
                            VFX_FRAME_ALIGNER_MODE_MID, 
                            VFX_FRAME_ALIGNER_MODE_MID, 
                            VFX_FRAME_ALIGNER_MODE_MID);
                m_video_popup->start();
            }
        }
    }
#endif 
	upDateMediaBounds();
/****Video Display******/

/****Text Display*******/
	if(current_slide->txt.id && (m_state == REDRAW_TEXT_NEEDED /*|| m_state == REDRAW_MEDIA_NEEDED */|| m_state == REDRAW_NEEDED))
    {
        VappMmsViewerData *my_data = parent->getMyData();
        mmi_umms_app_dtmgr_viewer_info_data *viewer_info =  my_data->getViewerInfo();
        mmi_umms_app_dtmgr_viewer_cateory_info_data *cat_info = viewer_info->cat_info;
        COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_SLIDE_DURATION,current_slide->duration,__LINE__);	
        COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_CURRENT_TIME,curTime,__LINE__);	
        COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_SLIDE_BEGIN_TIME,current_slide->txt.begin,__LINE__);
        COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_SLIDE_END_TIME,current_slide->txt.end,__LINE__);
        if(current_slide->txt.str_id == 0)
        {
        #ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__	
            VcpIconTable *iconTable = VappUcEmoticon::getEmotionTablePointer();
            VfxU32 sizeTable = VappUcEmoticon::getEmotionTableSize();
            m_main_txt->setIconMode(VFX_TRUE, iconTable, sizeTable);
        #endif/*__MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__*/
            srv_mms_viewer_load_ucs2_txt_to_buffer(cat_info->slide_txt_buffer, SRV_MMS_TXT_BUF_UCS2_SIZE,  &(current_slide->txt));
            m_main_txt->setText((const VfxWChar *)cat_info->slide_txt_buffer, NULL);
            txt_len = mmi_ucs2strlen((PS8)cat_info->slide_txt_buffer);
        }
        else
        {
            m_main_txt->setText( VFX_WSTR_RES(STR_ID_VAPP_MMS_VIEWER_TEXT_STRIPPED), NULL);
        }
        m_main_txt->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
        /*Set Text Background color forceful black, because text color will always*/
        /*be in contrast with backgound color, as bg color can never be black*/
        m_main_txt->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_BLACK);
        if(parent->getMode() == MODE_STOP ||current_slide->duration == 0 ||
            ((curTime >= (VfxS32)current_slide->txt.begin) &&  curTime <= (VfxS32)current_slide->txt.end ) || current_slide->txt.begin == 0)
        {
            m_main_txt->setIsDrawContent(VFX_TRUE);
        }
        else
        {
            m_main_txt->setIsDrawContent(VFX_FALSE);
        }
        m_main_txt->setKeyword(
                            #ifdef __MMI_EMAIL__       
                                VCP_TEXT_KEYWORD_EMAIL |
                            #endif        
                                VCP_TEXT_KEYWORD_URL  |
                                VCP_TEXT_KEYWORD_PHONENUMBER);
        m_main_txt->m_signalKeywordClick.connect(this, &VappMmsViewerCp::onKeywordClicked); 
    }
    if(current_slide->img.id 
        
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
        || current_slide->vid.id
    #endif
        )
    {
        VcpRichTextCustomFrame format, *format1 = NULL;
        VcpTextStorage *storage = m_main_txt->getTextStorage();
        if(parent->getMsgCntx()->layout == SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_BOTTOM)
        {
            VappMmsViewerData *my_data = parent->getMyData();
            mmi_umms_app_dtmgr_viewer_info_data *viewer_info =  my_data->getViewerInfo();
            srv_mms_viewer_load_ucs2_txt_to_buffer(viewer_info->cat_info->slide_txt_buffer, SRV_MMS_TXT_BUF_UCS2_SIZE,  &(current_slide->txt));
            txt_len = mmi_ucs2strlen((PS8)viewer_info->cat_info->slide_txt_buffer);
			if(current_slide->txt.id == 0)
			{
				txt_len = 0;
			}
            format.setRange(txt_len, txt_len);
            format1 = (VcpRichTextCustomFrame *)storage->getRichTextFormat(txt_len);
        }
        else
        {
            format.setRange(0, 0);
            format1 = (VcpRichTextCustomFrame *)storage->getRichTextFormat(0);
        }
        if(current_slide->txt.id && m_state == REDRAW_MEDIA_NEEDED && parent->getMode() == MODE_STOP)//MAUI_03152188
        {
            if(format1 != NULL)
            {		
                format1->setFrame(m_visual);
            }
        }
        else
        {
            format.setFrame(m_visual);
            if(format1 != NULL)
            {
                m_main_txt->removeTextFormat(*format1);
            }
            format.setObjectAttribute(VCP_RICH_TEXT_OBJ_ARRT_MID_ALIGN);			
            m_main_txt->addTextFormat(format);
        }	
    }
	m_main_txt->m_signalTapEvent.disconnect(this, &VappMmsViewerCp::onTapEvent);
	m_main_txt->m_signalTapEvent.connect(this, &VappMmsViewerCp::onTapEvent);
	m_state = REDRAW_NONE;
}

VfxBool VappMmsClock::allowTimer(void)
{
    mma_mms_description_struct *desc = srv_mms_get_desc_pointer();
    srv_mms_viewer_slide_struct * current_slide = desc->body->curr_slide;
    if(current_slide->duration == 0)
    {
        return VFX_FALSE;
    }
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
    /*Because Video does not allow play in call, we should not leave the timer in call as well*/
    if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        if(current_slide->vid.id)
        {
            return VFX_FALSE;
        }
    }
#endif
    return VFX_TRUE;
}
void VappMmsViewerPage::checkmmspageisgetcontent(VfxBool & result,void *user_data)
{
    result = VFX_FALSE;
#ifdef __MMI_MMS_USE_ASM__  
	VappMmsViewerPage *myData = (VappMmsViewerPage *)VfxObject::handleToObject((VfxObjHandle)user_data);
    if(myData && myData->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsViewerPage)) )
    {       
    	if(myData->getMsgType() == MMA_MSG_TYPE_MMS && myData->m_wait_data_done == VFX_TRUE)
    	{
    	    myData->m_exited = VFX_TRUE;
    		result =  VFX_TRUE;
    	}
        else
        {       
            myData->m_exited = VFX_FALSE;
    		result = VFX_FALSE;
        }
    }

#endif    
}
VfxBool VappMmsViewerPage::checkmmsgetcontent()
{
#ifdef __MMI_MMS_USE_ASM__  

    if(getMsgType() == MMA_MSG_TYPE_MMS && m_wait_data_done == VFX_TRUE)
	{
	    m_exited = VFX_TRUE;
		return   VFX_TRUE;
	}
    else
    {       
    
        m_exited = VFX_FALSE;
		return  VFX_FALSE;
    }  
#else
    return VFX_FALSE;
#endif  
}

VfxBool VappMmsViewerPage::onKeyInput(VfxKeyEvent &event)
{
    if(getMsgType() == MMA_MSG_TYPE_MMS && m_data->checkViewerDataReady() == VFX_FALSE)
    {
        return VFX_TRUE;
    }
    
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
    if(m_main_cp)
    {
        if(VFX_TRUE == m_main_cp->getopenfilestate())
        {       
            return VFX_TRUE;
        }
    }
#endif    
    if(getMsgType() == MMA_MSG_TYPE_MMS)
    {
        srv_mms_viewer_xml_msg_struct *msg_cntx = getMsgCntx();
        srv_mms_viewer_slide_struct *current_slide = *(msg_cntx->current_slide);
        if(event.keyCode == VFX_KEY_CODE_ARROW_LEFT)
        {
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN
                || event.type == VFX_KEY_EVENT_TYPE_REPEAT)
            {
                if(msg_cntx && current_slide->prev)
                {
                    onClickPrev(this, 0);
                    changeButtonState(m_prev, VCP_BUTTON_STATE_PRESSED);
                    return VFX_TRUE;
                }
            }
            else if(event.type == VFX_KEY_EVENT_TYPE_UP)
            {
                changeButtonState(m_prev, VCP_BUTTON_STATE_NORMAL);
                return VFX_TRUE;
            }
        }
        if(event.keyCode == VFX_KEY_CODE_ARROW_RIGHT)
        {
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN 
                || event.type == VFX_KEY_EVENT_TYPE_REPEAT)
            {
                if(msg_cntx && current_slide->next)
                {
                    onClickNext(this, 0);
                    changeButtonState(m_next, VCP_BUTTON_STATE_PRESSED);
                    return VFX_TRUE;
                }
            }
            else if(event.type == VFX_KEY_EVENT_TYPE_UP)
            {
                changeButtonState(m_next, VCP_BUTTON_STATE_NORMAL);
                return VFX_TRUE;
            }
        }
        if(event.keyCode == VFX_KEY_CODE_CSK)
        {
            if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
            {
                if(m_mode == MODE_PLAY)
                {
                    m_mode = MODE_PAUSE;
                    handlePause();
                    changeButtonState(m_button_play, VCP_BUTTON_STATE_PRESSED);
                }
                else if(m_mode == MODE_PAUSE)
                {
                    onClickPause(this, 0);
                }
                else if(m_mode == MODE_STOP)
                {
                    onClick(this, 0);
                }
                return VFX_TRUE;
            }
            else if(event.type == VFX_KEY_EVENT_TYPE_UP)
            {
                changeButtonState(m_button_play, VCP_BUTTON_STATE_NORMAL);
                return VFX_TRUE;
            }
        }
    }
    if(event.keyCode == VFX_KEY_CODE_SEND)
    {
        if(event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            if(m_tool_bar && (m_tool_bar->getIsItemDisabled(VappMmsToolBar::ACTION_CALL) == VCP_TOOL_BAR_ITEM_ENABLED))
            {
                m_tool_bar->call();
                return VFX_TRUE;
            }
        }
    }
    return VfxPage::onKeyInput(event);
}

void VappMmsViewerPage::changeButtonState(VcpButton *button, VcpButtonStateEnum newState)
{
	if(button && button->getSize().height != 0)
	{
		button->setState(newState);
	}
}


void VappMmsViewerCp::upDatecpLayout(void)
{
	VfxU32 txt_Y = 0, img_Y = 0, txt_H = 0, img_H = 0, comm_X, comm_Y, comm_W, comm_H;
	mma_mms_description_struct *desc = srv_mms_get_desc_pointer();
	MMS_BODY_ERROR_HANDLE(desc);
	srv_mms_viewer_slide_struct * current_slide = desc->body->curr_slide;
	VappMmsViewerPage *parent = (VappMmsViewerPage *)getParent()->getParent();
	VappMmsViewerData *my_data = parent->getMyData();
	comm_X = CP_LEFT_MARGIN;
	comm_Y = CP_TOP_MARGIN;
	if(parent->m_contact_bar && parent->m_contact_bar->getSize().height > 0)
	{
		comm_Y -= parent->m_contact_bar->getShadowHeight();
	}
	comm_H = getSize().height - CP_TOP_MARGIN - CP_BOTTOM_MARGIN;
	comm_W = getSize().width - CP_LEFT_MARGIN - CP_RIGHT_MARGIN;
	if(current_slide->img.id)
	{
	}
	if(current_slide->txt.id)
	{
		txt_H = (comm_H  - CP_MARGIN_BETWEEN_OBJECTS)/ 2;
	}
	if(parent->getMsgCntx()->layout == SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_BOTTOM)
	{
		txt_Y = 0;
		img_Y = txt_Y + txt_H + CP_MARGIN_BETWEEN_OBJECTS;
	}
	else
	{
		img_Y = 0;
		txt_Y = img_Y + img_H + CP_MARGIN_BETWEEN_OBJECTS;
	}
	m_main_txt->setPos(VfxPoint(comm_X, comm_Y));
	m_main_txt->setBounds(VfxRect(0, 0, comm_W, comm_H));
	m_main_txt->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE);	
	COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_MAIN_TEXT_SIZE,comm_X,comm_Y,comm_W,comm_H,__LINE__); 
}
void VappMmsViewerCp::upDateMediaBounds(void)
{
    VfxS32 img_H = 0, img_W = 0;
    img_W = getSize().width - CP_LEFT_MARGIN - CP_RIGHT_MARGIN;
    img_H = (getSize().height - CP_TOP_MARGIN - CP_BOTTOM_MARGIN - CP_MARGIN_BETWEEN_OBJECTS) / 2; 
    COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_VIDEO_AND_IMAGE_FRAME_SIZE,img_W,img_H,__LINE__); 
    if(m_visual)
    {
		VfxAnimImageFrame *m_frame = (VfxAnimImageFrame *)m_visual->getFrame();
        if(m_frame->isKindOf(VFX_OBJ_CLASS_INFO(VfxAnimImageFrame)))
        {
            COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_IMAGE_SIZE,m_frame->getSize().width,m_frame->getSize().height,__LINE__); 
            VfxS32 width ,height;
            getimagerealysize(&width,&height);
            //if(m_frame->getSize().width > img_W)
            if(width > img_W)
            {
                m_frame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
                //img_H = m_frame->getSize().height * img_W / m_frame->getSize().width;
                img_H = height * img_W / width;
                if(img_H == 0)
                {
                    img_H = 2;
                }
            }
            else if(width > 0)
            {
                //img_W = m_frame->getSize().width;
                //img_H = m_frame->getSize().height;
                img_W = width;
                img_H = height;
            }
            if(getSize().width > CP_PAGE_WIDTH_PORTRAIT) //land scape handle
        {
            if(img_H > CP_IMAGE_SIZE_HEIGHT_LANDSCAPE)
            {
                img_H = CP_IMAGE_SIZE_HEIGHT_LANDSCAPE;
                    img_W = width * img_H / height;
                    
                if(img_W == 0)
                {
                    img_W = 2;
                }
                    else if(img_W > getSize().width)
                    {
                        img_W = getSize().width;
                        img_H = height * img_W / width;
                    }
                    
            }
        }
            else   // handle portrait
        {
            if(img_H > CP_IMAGE_SIZE_HEIGHT_PORTRAIT)
            {
                img_H = CP_IMAGE_SIZE_HEIGHT_PORTRAIT;
                    img_W = width * img_H / height;
                    
                if(img_W == 0)
                {
                    img_W = 2;
                }
                    else if(img_W > getSize().width)
                    {
                        img_W = getSize().width;
                        img_H = height * img_W / width;
                    }
            }
        }
			//m_frame->playImgContent(); // inform VRT this frame contains an animation image
            m_frame->play();
            m_frame->setIsCached(VFX_TRUE); // enable cache to optimize GIF display.
            m_frame->setIsOpaque(VFX_FALSE);
        }
        
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
        else if(m_frame->isKindOf(VFX_OBJ_CLASS_INFO(VappVideoPlayerComponent)))
        {
            VappVideoPlayerComponent *m_frame1 = (VappVideoPlayerComponent *)m_visual->getFrame();
            VfxS32 v_H = 0, v_W = 0;
            VfxS32 v_AH = 0, v_AW = 0;
            VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);/*Bug Fix MAUI_03068469*/
            m_frame1->getVideoAspectRatio(v_W, v_H);
            v_AW  = topLevel->getSize().width;
            v_AH = topLevel->getSize().height;
            COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_VIDEO_ASPECT_RATIO,v_W,v_H,__LINE__); 
            COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_TOP_LEVEL_SIZE,v_AW,v_AH,__LINE__); 
            if(v_W != 0 && v_H != 0
                && !(m_frame1->getState() == VGPS_CLOSED 
                ||m_frame1->getState() == VGPS_OPENING))
            {
                if(v_W > v_AW)
                {
                    v_H = v_H * v_AW / v_W;
                    if(v_H == 0)
                    {
                        v_H = 2;
                    }
                    v_W = v_AW;
                }
                if(v_H > v_AH)
                {
                    v_W = v_W * v_AH / v_H;
                    if(v_W == 0)
                    {	
                        v_W = 2;
                    }
                    v_H = v_AH;
                }
                img_W = v_W;
                img_H = v_H;
            }
            else
            {
                VappMmsViewerPage *Parent = (VappMmsViewerPage *)m_page;
                img_H = (Parent->getPanelHeightVideo() - CP_TOP_MARGIN - CP_BOTTOM_MARGIN - CP_MARGIN_BETWEEN_OBJECTS)/2;
            }
        }
    #endif
        m_visual->setPos(0, 0);
        m_frame->setPos(m_visual->getPos());
        m_visual->setSize(img_W, img_H);
        m_frame->setSize(m_visual->getSize());
        m_visual->setIsUnhittable(VFX_TRUE);
    }
}
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__

void VappMmsViewerCp::onFileReady(VappVideoPlayerComponent *m_player, MDI_RESULT result)
{
    VappMmsViewerPage *parent = (VappMmsViewerPage *)m_page;
    mma_mms_description_struct *desc = srv_mms_get_desc_pointer();
    MMS_BODY_ERROR_HANDLE(desc);
    srv_mms_viewer_slide_struct * current_slide = desc->body->curr_slide;
    VfxS32 curTime = -1;
	if(parent->m_clock && parent->getMode() == MODE_PLAY && parent->m_clock->allowTimer())
    {
        curTime = (VfxS32)parent->m_clock->getTime();
        parent->m_clock->ResumeClock();
    }
    m_opening_file = VFX_FALSE;
    parent->setButtonStateAfterOpenFile();
    if(m_video_popup)
    {
        VFX_OBJ_CLOSE(m_video_popup);
        m_video_popup = NULL;
    }
    if(MDI_RES_VDOPLY_SUCCEED == result)
    {
        upDateMediaBounds();
        m_main_txt->forceUpdate();
        m_player->setHidden(VFX_FALSE);
        //m_player->pause();
        if(curTime >= current_slide->vid.begin &&  curTime <= current_slide->vid.end
            && current_slide->duration != 0)
        {
            if(parent->getMode() != MODE_PAUSE)
            {
            
                mmi_frm_cb_reg_event(EVT_ID_SRV_PROF_IS_PLAYING, &VappMmsViewerCp::listener, getObjHandle());                
                m_player->play();   // play from start after open()
                m_player->m_signalPlaybackFinished.connect(this, &VappMmsViewerCp::onVideoPlaybackFinish);
            }
        }
        else if(parent->getMode() == MODE_PAUSE)
        {
            m_player->pause();
            m_player->m_signalPlaybackFinished.disconnect(this, &VappMmsViewerCp::onVideoPlaybackFinish);
            parent->m_clock->changeState(VappMmsClock::STATE_RUNNING);
        }
    }
    else
    {
        // handle various errors
        // Note: The player UI will change to error icon by itself.
        m_player->setHidden(VFX_FALSE);
        vidState = VIDEO_STATE_FAIL;
    }
}
#endif
VfxFrame *VappMmsVisual::getFrame(void)
{
    if(m_type == SRV_MMS_OBJECT_TYPE_IMAGE)
    {
        return m_image;
    }
    
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
    else if(m_type == SRV_MMS_OBJECT_TYPE_VIDEO)
    {
        return m_video;
    }
#endif

    return NULL;
}

void VappMmsViewerCp::onTapEvent(VcpTextView *obj, VcpTextTapAreaEnum are, VcpRichTextFormat * frame)
{
    VappMmsViewerPage *parent = (VappMmsViewerPage *)m_page;
    
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
    if(VFX_TRUE == getopenfilestate())
    {       
        return ;
    }
#endif
    if(frame && frame->getType() == VCP_RICH_TEXT_TYPE_CUSTOM_FRAME && parent->getMode() == MODE_STOP)
    {
        COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_ON_PEN_INPUT_VISUAL); 
        srv_mms_viewer_object_struct *obj = NULL;
        mma_mms_description_struct *desc = srv_mms_get_desc_pointer();
        obj = (m_visual->getObj())->object;
        if(obj)
        {
            VappMmsViewObjectsHandler *objHndl;
            MMS_BODY_ERROR_HANDLE(desc);
            VFX_OBJ_CREATE_EX(objHndl, VappMmsViewObjectsHandler, this, (obj, desc->body->curr_slide->slide_num - 1));
            objHndl->preview();
        }
    }
    else if(parent->getMode() == MODE_PLAY)
    {
        parent->onPenInput();
    }
}

#if(0)
VfxBool VappMmsVisual::onPenInput(VfxPenEvent &event)
{
	VappMmsViewerPage *parent = (VappMmsViewerPage *)VappMmsViewerPage::getMyPage();
	if(event.type == VFX_PEN_EVENT_TYPE_DOWN && parent->getMode() == MODE_STOP)
	{
		COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_ON_PEN_INPUT_VISUAL); 
		srv_mms_viewer_object_struct *obj = NULL;
		mma_mms_description_struct *desc = srv_mms_get_desc_pointer();
		obj = srv_mms_viewer_get_objects_from_id(m_id);
		if(obj && getFrame()->getSize().height != 0 && getFrame()->getSize().width != 0 )
		{
			VappMmsViewObjectsHandler *objHndl;
			MMS_BODY_ERROR_HANDLE(desc);
			VFX_OBJ_CREATE_EX(objHndl, VappMmsViewObjectsHandler, this, (obj, desc->body->curr_slide->slide_num - 1));
			objHndl->preview();
		}
	}
	return VfxControl::onPenInput(event);
}
#endif
void VappMmsViewerPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
    if (m_main_cp)
    {
    
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
        srv_mms_viewer_xml_msg_struct *msg_cntx = getMsgCntx();
        if(msg_cntx)
        {
            srv_mms_viewer_slide_struct *current_slide = *(msg_cntx->current_slide);
            if(current_slide->vid.id)
            {
                VappVideoPlayerComponent *m_video = m_main_cp->getVideo();
                if(m_video)
                {
                    m_video->startRotate();
                }
            }
        }
#endif
        if(param.rotateTo != param.rotateFrom)
        {
            m_main_cp->setAutoAnimate(VFX_TRUE);
            (m_main_cp->getParentFrame())->setAutoAnimate(VFX_TRUE);
        }
    }
    //return param.rotateTo;
}
void VappMmsViewerPage::onRotate(const VfxScreenRotateParam &param)
{
    switch(param.rotateTo)
    {  
        case VFX_SCR_ROTATE_TYPE_NORMAL:                
        case VFX_SCR_ROTATE_TYPE_90:                
        case VFX_SCR_ROTATE_TYPE_180:                
        case VFX_SCR_ROTATE_TYPE_LANDSCAPE:
        if(getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))
        {
            ((VcpToolBar *)getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))->setLayout(param.rotateTo);
        }
            break;
        default:
            break;
    }
    if (m_main_cp)
    {
    
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
        srv_mms_viewer_xml_msg_struct *msg_cntx = getMsgCntx();
        if(msg_cntx)
        {
            srv_mms_viewer_slide_struct *current_slide = *(msg_cntx->current_slide);
            if(current_slide->vid.id)
            {	
                VappVideoPlayerComponent *m_video = m_main_cp->getVideo();
                if(m_video)
                {
                    m_video->endRotate();
                }
            }
        }
#endif
        m_main_cp->setAutoAnimate(VFX_FALSE);
        (m_main_cp->getParentFrame())->setAutoAnimate(VFX_FALSE);
    }
    if(m_contact_bar)
    {
        m_contact_bar->onRotate();
    }
}
void VappMmsVisual::onInit(void)
{
    VfxControl::onInit();

    if(m_type == SRV_MMS_OBJECT_TYPE_IMAGE)
    {
		VFX_OBJ_CREATE(m_image, VfxAnimImageFrame, this);
    }
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
    else if(m_type == SRV_MMS_OBJECT_TYPE_VIDEO)
    {
        VappVideoPlayerPlayOption option;
        option.configAsMmsVideo(); 
        VappVideoPlayerComponent *video;
        VFX_OBJ_CREATE_EX(video, VappVideoPlayerComponent, this, (option));
        m_video = video;
    }
#endif    
}
VappMmsAudioPlay *VappMmsViewerCp::getAudio(void)
{
	return m_audio;
}
#ifdef __DRM_SUPPORT__
void VappMmsViewerCp::onImageRightsExpiry(void *data)
{
    VappMmsViewerCp *me = (VappMmsViewerCp *)data;
    VappMmsViewerPage *parent = (VappMmsViewerPage *)me->m_page;
    me->getAudio()->stopAudio();
    srv_mms_viewer_slide_struct *current_slide =  *(parent->getMsgCntx()->current_slide);
    VappMmsDrmHandler::stopConsumeRights(&(current_slide->img), parent->m_data->getMyIndex());
}
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
void VappMmsViewerCp::onVideoRightsExpiry(void *data)
{

}
#endif
void VappMmsViewerCp::onAudioRightsExpiry(void *data)
{
    VappMmsViewerCp *me = (VappMmsViewerCp *)data;
    VappMmsViewerPage *parent = (VappMmsViewerPage *)me->m_page;
    me->getAudio()->stopAudio();
    srv_mms_viewer_slide_struct *current_slide =  *(parent->getMsgCntx()->current_slide);
    VappMmsDrmHandler::updateRightsById(&(current_slide->aud), VFX_FALSE, parent->m_data->getMyIndex());
}
#endif/*__DRM_SUPPORT__*/
void VappMmsViewerCp::onKeywordClicked(VcpTextKeyWordEnum mode, VfxWChar *text, VfxS32 len)
{
    if(((VappMmsViewerPage *)m_page)->getMode() != MODE_STOP)
    {
        return;
    }
    VcpCommandPopup *m_commandPopup;
    VappMmsUseDetailHandler *m_useDetailsHdlr;
    VfxFrame *childFrame = getLastChildFrame();
    VfxU16 mode_ext = 0;
    while(childFrame != NULL)
    {
        if(childFrame->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsUseDetailHandler)))
        {
            VFX_OBJ_CLOSE(childFrame);
            break;
        }
        childFrame = childFrame->getPrevFrame();
    }
    VappMmsViewerData *my_data = ((VappMmsViewerPage *)m_page)->getMyData();
    switch(mode)
    {
        case VCP_TEXT_KEYWORD_EMAIL:
            mode_ext = APPLIB_ADDR_TYPE_EMAIL;
        break;
        case VCP_TEXT_KEYWORD_URL:
            mode_ext = APPLIB_ADDR_TYPE_URL;
        break;
        case VCP_TEXT_KEYWORD_PHONENUMBER:
            mode_ext = APPLIB_ADDR_TYPE_PHONENUMBER;
        break;
    }
    VFX_OBJ_CREATE_EX(m_useDetailsHdlr, VappMmsUseDetailHandler, this, ((PU16)text, len, mode_ext, my_data->getMsgInfo()->msg_sim_info));
    VFX_OBJ_CREATE(m_commandPopup, VcpCommandPopup, this);
    m_commandPopup->setAutoDestory(VFX_TRUE);
    VfxWString title1;
    U16 temp = *(U16 *)(text + len);
    *(U16 *)(text + len) = 0;
    title1.loadFromMem(text);
    *(U16 *)(text + len) = temp;
    m_commandPopup->setInfoType(VCP_POPUP_TYPE_INFO);
    m_commandPopup->setText(title1);
    switch (mode)
    {
        case VCP_TEXT_KEYWORD_EMAIL:
            m_commandPopup->addItem(VAPP_MMS_USE_DETAILS_SEND_EMAIL, VFX_WSTR_RES(STR_ID_VAPP_MMS_SEND_EMAIL));
            m_commandPopup->addItem(VAPP_MMS_USE_DETAILS_ADDRESSES_NEW_CONTACT, VFX_WSTR_RES(STR_ID_VAPP_MMS_ADD_AS_NEW_CONTACT));
            m_commandPopup->addItem(VAPP_MMS_USE_DETAILS_ADDRESSES_SAVE_TO_PHBOOK, VFX_WSTR_RES(STR_ID_VAPP_MMS_ADD_AS_EXISTING_CONTACT));
            m_commandPopup->m_signalButtonClicked.connect(m_useDetailsHdlr,&VappMmsUseDetailHandler::VappMmsUseEmailCb);
        break;
        case VCP_TEXT_KEYWORD_URL:
            m_commandPopup->m_signalButtonClicked.connect(m_useDetailsHdlr,&VappMmsUseDetailHandler::VappMmsUseUrlCb);
            m_commandPopup->addItem(VAPP_MMS_USE_DETAILS_ADDRESSES_GO_TO, VFX_WSTR_RES(STR_ID_VAPP_MMS_GO_TO_URL));
    #if defined( __MMI_VUI_SAVE_BOOKMARK_SUPPORT__) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
            m_commandPopup->addItem(VAPP_MMS_USE_DETAILS_ADDRESSES_ADD_BOOKMARK, VFX_WSTR_RES(STR_ID_VAPP_MMS_SAVE_TO_BOOKMARK));
    #endif
        break;
        case VCP_TEXT_KEYWORD_PHONENUMBER:
                m_commandPopup->addItem(VAPP_MMS_USE_DETAILS_ADDRESSES_EDIT_BEFORE_CALL, VFX_WSTR_RES(STR_ID_VAPP_MMS_EDIT_BEFORE_CALL));
                m_commandPopup->addItem(VAPP_MMS_USE_DETAILS_SEND_MESSAGE, VFX_WSTR_RES(STR_ID_VAPP_MMS_SEND_MESSAGE));
                m_commandPopup->addItem(VAPP_MMS_USE_DETAILS_ADDRESSES_NEW_CONTACT, VFX_WSTR_RES(STR_ID_VAPP_MMS_ADD_AS_NEW_CONTACT));
                m_commandPopup->addItem(VAPP_MMS_USE_DETAILS_ADDRESSES_SAVE_TO_PHBOOK, VFX_WSTR_RES(STR_ID_VAPP_MMS_ADD_AS_EXISTING_CONTACT));
                m_commandPopup->m_signalButtonClicked.connect(m_useDetailsHdlr,&VappMmsUseDetailHandler::VappMmsUseNumberCb);
        break;
        case VCP_TEXT_KEYWORD_USSD:
        // get USSD and goto USSD
        break;
        default:
        break;
    }
    m_commandPopup->addItem(VAPP_MMS_USE_DETAILS_TOTAL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
    m_commandPopup->setAutoDestory(VFX_TRUE);
    m_commandPopup->show(VFX_TRUE);
}
void VappMmsViewerPage::onDataReady(srv_mms_viewer_result_enum error, VfxS32 fileError)
{
    COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_ON_PAGE_DATA_READY, m_mode, error); 
    m_data->m_signalMmsViewerServiceDone.disconnect(this, &VappMmsViewerPage::onDataReady);

    if(m_popup)
    {
        VFX_OBJ_CLOSE(m_popup);
        m_popup = NULL;
    }
    m_error_type  = error;
    if(m_error_type != SRV_MMS_VIEWER_OK)
    {
        if(m_error_type == SRV_MMS_VIEWER_CORRUPT_MMS || 
        m_error_type == SRV_MMS_VIEWER_UNSUPPORT_MMS)
        {
            draw();
            return;
        }
        displayPopupAndExit();
        return;
    }
    m_msg_location = m_data->getMsgInfo()->storage_location;
    draw();		
}
void VappMmsViewerCp::onContentReady(srv_mms_viewer_result_enum error, VfxS32 fileError)
{
    COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_ON_PAGE_DATA_READY, MODE_STOP, error); 
    stopLoading();
    VappMmsViewerPage *parent = (VappMmsViewerPage *)m_page;
    mma_mms_description_struct *desc = srv_mms_get_desc_pointer();
    if(error != SRV_MMS_VIEWER_OK)
    {
        VappMmsPopup m_popup(STR_GLOBAL_ABORTING, VCP_POPUP_TYPE_FAILURE, parent, (clickOk)&VappMmsViewerPage::onClickOk);           
        m_popup.displayPopup();
        return;
    }
    m_state = REDRAW_NEEDED;
    MMS_BODY_ERROR_HANDLE(desc);
    parent->m_slideCount = desc->body->curr_slide->slide_num;
    parent->upDateInternal();
    parent->handleRRRequest();
    
#ifndef __MMI_MV_SUPPORT_USE_DETAIL_HIGHLIGHT__
    if(((VappMmsViewerPage *)m_page)->m_tool_bar)
    {      
    ((VappMmsViewerPage *)m_page)->m_tool_bar->updatToolbar(); // for MAUI_03185837
    }
#endif
}
void VappMmsViewerPage::onConfirmRR(VfxObject* obj, VfxId id)
{
    VfxBool send =  id == VCP_CONFIRM_POPUP_BUTTON_USER_1 ? VFX_TRUE : VFX_FALSE;
    MmsRRResultTypeEnum result = m_data->MmsHandleReadReport(send);
#if(MMI_MAX_SIM_NUM >= 2)
    if(result == MMS_SEND_RR_ERROR)
    {
        VappMmsPopup m_popup(STR_ID_VAPP_MMS_SIM_INVALID, VCP_POPUP_TYPE_FAILURE, this, (clickOk)&VappMmsViewerPage::onClickRRErrorOk);           
        m_popup.displayPopup();
        return;
    }
#endif/*MMI_MAX_SIM_NUM*/
    //draw();	
}
void VappMmsViewerPage::onLastSlideEnd(void)
{
	COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_LAST_SLIDE_ENDED);
	onPreviewPageFinish();
}
VfxBool VappMmsViewerPage::onPenInput(
        VfxPenEvent &event)
{
	COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_ON_PEN_INPUT_PAGE, m_mode); 
	return VfxPage::onPenInput(event);
}
void VappMmsViewerPage::handlePause(void)
{
    COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_PAUSE,__LINE__); 
    if(m_mode == MODE_PAUSE)
    {
    
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
        VappVideoPlayerComponent *m_video = m_main_cp->getVideo();
        if(m_video && (m_main_cp->videoisfinished() != VFX_TRUE)&&
            (m_video->canChangePlayPausedState() == VFX_FALSE  //can't pause video when rotate
            || VGPS_OPENING == m_main_cp->getVideoState()      // can't pause video when open file
            || VGPS_PAUSED == m_main_cp->getVideoState()))     //can't pause video after play file but the video don't really became playing
        {
            m_mode = MODE_PLAY;
            return;
        }
#endif        
        m_button_play->m_signalClicked.connect(this, &VappMmsViewerPage::onClickPause);
        if(getMsgCntx() && getMsgCntx()->total_slide_num > 1)
        {
            srv_mms_viewer_slide_struct *current_slide =  *(getMsgCntx()->current_slide);
            m_prev->m_signalClicked.connect(this, &VappMmsViewerPage::onClickPrev);
            if(current_slide->prev == NULL)
            {
                m_prev->setIsDisabled(VFX_TRUE);
            }
            else
            {
                m_prev->setIsDisabled(VFX_FALSE);
            }
            m_next->m_signalClicked.connect(this, &VappMmsViewerPage::onClickNext);
            if(current_slide->next == NULL)
            {
                m_next->setIsDisabled(VFX_TRUE);
            }
            else
            {
                m_next->setIsDisabled(VFX_FALSE);
            }
        }
        handleResizeButton();
        m_button_play->setAlignParent(VFX_FRAME_ALIGNER_SIDE_BOTTOM, VFX_FRAME_ALIGNER_MODE_SIDE);
        m_button_play->setBgImageList(VcpStateImage(IMG_ID_VENUS_MMS_BG_N, IMG_ID_VENUS_MMS_BG_P, IMG_ID_VENUS_MMS_BG_D, 0));
        m_prev->setBgImageList(VcpStateImage(IMG_ID_VENUS_MMS_BG_N, IMG_ID_VENUS_MMS_BG_P, IMG_ID_VENUS_MMS_BG_D, 0));
        m_next->setBgImageList(VcpStateImage(IMG_ID_VENUS_MMS_BG_N, IMG_ID_VENUS_MMS_BG_P, IMG_ID_VENUS_MMS_BG_D, 0));
        m_prev->setAlignParent(VFX_FRAME_ALIGNER_SIDE_BOTTOM, VFX_FRAME_ALIGNER_MODE_SIDE);
        m_next->setAlignParent(VFX_FRAME_ALIGNER_SIDE_BOTTOM, VFX_FRAME_ALIGNER_MODE_SIDE);
        VappMmsAudioPlay *m_audio = m_main_cp->getAudio();
        if(m_audio)
        {
            m_audio->pauseAudio();
        }		
        
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
		COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_VIDEO_STATE,m_video->getState(),__LINE__); 
        if(m_video && m_video->getState() == VGPS_PLAYING)
        {
            m_video->pause();
            m_video->m_signalPlaybackFinished.disconnect(this, &VappMmsViewerCp::onVideoPlaybackFinish);
        }
#endif
        m_clock->pauseClock();
        m_panel->setSize(getSize().width, getPanelHeight());
        m_main_cp->setBounds(m_panel->getBounds());
        m_main_cp->setSize(getSize().width,getPanelHeight()- CP_MARGIN_BETWEEN_BUTTON);
    }
}
void VappMmsViewerPage::handleResizeButton(void)
{
    if(m_data->checkViewerDataReady() == VFX_FALSE)
    {
        return;
    }
    VfxU32 gap1 = 8, gap2 = 5;
    if(m_mode == MODE_STOP)
    {
        VfxU32 gap1 = 0, gap2 = 0, side_button_size = 0, center_button_size = 0;
        if(getSize().width > PAGE_WIDTH_PORTRAIT)
        {
            side_button_size = BUTTON_PREV_WIDTH_LANDSCAPE;
            if(getMsgCntx() && getMsgCntx()->total_slide_num > 1)
            {
                center_button_size = BUTTON_PLAY_WIDTH_LANDSCAPE;
                m_prev->setSize(side_button_size, m_prev->getSize().height);
                gap2 = BUTTON_STOP_COMM_GAP;
                gap1 = BUTTON_LEFT_MARGIN;
            }
            else
            {
            center_button_size = BUTTON_PLAY_ONLY_WIDTH_LANDSCAPE;
            gap1 = BUTTON_PLAY_ONLY_X_LANDSCAPE;
            }
        }
        else
        {
            side_button_size = BUTTON_PREV_WIDTH;
            if(getMsgCntx() && getMsgCntx()->total_slide_num > 1)
            {
                center_button_size = BUTTON_PLAY_WIDTH;
                if(getMsgCntx()->total_slide_num > 1)
                {
                    center_button_size = BUTTON_PLAY_WIDTH;
                    m_prev->setSize(side_button_size, m_prev->getSize().height);
                    gap1 = BUTTON_LEFT_MARGIN;
                    gap2 = BUTTON_STOP_COMM_GAP;
                }
            }
            else
            {
                center_button_size = BUTTON_PLAY_ONLY_WIDTH;
                gap1 = BUTTON_PLAY_ONLY_X;
            }
        }
        m_button_play->setPos(gap1 + m_prev->getRect().getMaxX(), m_button_play->getRect().getY());
        m_button_play->setSize(center_button_size, m_button_play->getSize().height);
        if(getMsgCntx() && getMsgCntx()->total_slide_num > 1)
        {
            m_next->setPos(gap2 + m_button_play->getRect().getMaxX(), m_next->getRect().getY());
            m_next->setSize(side_button_size, m_next->getSize().height);
        }
        else
        {        
            m_next->setPos(gap2 + m_button_play->getRect().getMaxX(), m_next->getRect().getY());
        }
        return;
    }
    if(m_mode == MODE_PAUSE)
    {
        if(getMsgCntx() && getMsgCntx()->total_slide_num > 1)
        {
            m_prev->setPos(BUTTON_LEFT_MARGIN, getSize().height  - BUTTON_PAUSE_HEIGHT - BUTTON_BOTTOM_MARGIN);
            m_prev->setSize(BUTTON_PAUSE_PREV_WIDTH, BUTTON_PAUSE_HEIGHT);
            m_button_play->setPos(BUTTON_PAUSE_COMM_GAP + m_prev->getRect().getMaxX(), getSize().height - BUTTON_PAUSE_HEIGHT - BUTTON_BOTTOM_MARGIN);
            m_button_play->setSize(BUTTON_PAUSE_PLAY_WIDTH, BUTTON_PAUSE_HEIGHT);
            m_next->setPos(BUTTON_PAUSE_COMM_GAP + m_button_play->getRect().getMaxX(), getSize().height  - BUTTON_PAUSE_HEIGHT - BUTTON_BOTTOM_MARGIN);
            m_next->setSize(BUTTON_PAUSE_NEXT_WIDTH, BUTTON_PAUSE_HEIGHT);
            if(getSize().width > PAGE_WIDTH_PORTRAIT)
            {
                m_prev->setPos(gap1, getSize().height  - BUTTON_PAUSE_HEIGHT - BUTTON_BOTTOM_MARGIN);
                m_prev->setSize(BUTTON_PREV_WIDTH_LANDSCAPE, BUTTON_PAUSE_HEIGHT);
                m_button_play->setPos(gap2 + m_prev->getRect().getMaxX(), getSize().height - BUTTON_PAUSE_HEIGHT - BUTTON_BOTTOM_MARGIN);
                m_button_play->setSize(BUTTON_PLAY_WIDTH_LANDSCAPE, BUTTON_PAUSE_HEIGHT);
                m_next->setPos(gap2 + m_button_play->getRect().getMaxX(), getSize().height  - BUTTON_PAUSE_HEIGHT - BUTTON_BOTTOM_MARGIN);
                m_next->setSize(BUTTON_NEXT_WIDTH_LANDSCAPE, BUTTON_PAUSE_HEIGHT);
            }
        }
        else
        {
            m_button_play->setPos(BUTTON_PAUSE_PLAY_ONLY_X, getSize().height  - BUTTON_PAUSE_HEIGHT - BUTTON_BOTTOM_MARGIN);
            m_button_play->setSize(BUTTON_PAUSE_PLAY_ONLY_WIDTH, BUTTON_PAUSE_HEIGHT);
            if(getSize().width > PAGE_WIDTH_PORTRAIT)
            {
                m_button_play->setPos(BUTTON_PAUSE_PLAY_ONLY_X_LANDSCAPE, getSize().height - BUTTON_PAUSE_HEIGHT - BUTTON_BOTTOM_MARGIN);
                m_button_play->setSize(BUTTON_PLAY_ONLY_WIDTH_LANDSCAPE, BUTTON_PAUSE_HEIGHT);
            }
        }
    }
    if(m_button_play && m_prev->getSize().width == 0)
    {
        m_button_play->setAlignParent(VFX_FRAME_ALIGNER_SIDE_LEFT, VFX_FRAME_ALIGNER_MODE_SIDE);
        m_button_play->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, VFX_FRAME_ALIGNER_MODE_SIDE);
    }
}
void VappMmsViewerPage::onPenInput(void)
{
	m_mode = MODE_PAUSE;
	handlePause();
}
void VappMmsViewerPage::onSlideSwitch(void)
{
	deleteAllChilds();
	m_slideCount++;
	draw();
}
VappMmsViewerModeEnum VappMmsViewerPage::getMode(void)
{
	return m_mode;
}
void VappMmsViewerPage::onEntered(void)
{
    VfxPage::onEntered();	
    if(getMainScr()->getIsSnapshotDrawing() == VFX_TRUE)
    {
        return;
    }
    if(m_enter == VFX_FALSE)
    {
        m_enter = VFX_TRUE;	
        mma_mms_description_struct *desc = srv_mms_get_desc_pointer();	
        MMS_BODY_ERROR_HANDLE(desc);	
        srv_mms_viewer_slide_struct * current_slide = desc->body->curr_slide;	
        if(current_slide->vid.id)	
        {
            m_main_cp->setState(VappMmsViewerCp::REDRAW_MEDIA_NEEDED);		
            upDateInternal();	
        }
    }
    else
    {
        if(m_Backward)
        {
            if(getMsgType() == MMA_MSG_TYPE_MMS && m_data->checkViewerDataReady())
            {
                m_data->checkDataReady();
                mma_mms_description_struct *desc = srv_mms_get_desc_pointer();
                MMS_BODY_ERROR_HANDLE(desc);
                if(m_slideCount != desc->body->curr_slide->slide_num)
                {
                    m_slideCount = desc->body->curr_slide->slide_num;
                    m_main_cp->deInitCpExt();
                    m_main_cp->setState(VappMmsViewerCp::REDRAW_NEEDED);
                    upDateInternal();
                }
                else
                {
                    m_main_cp->startMediaRightsConsumption();
                }
            }
            else
            {	
                srv_mms_mem_mgr_copy_pools(m_data->getMyIndex(), APPLIB_MEM_AP_ID_UMMS);
            }
        }
    }
    if (m_contact_bar)
    {
        m_contact_bar->onRotate(); //for MAUI_03161995, required by mtk54037
    }
}
void VappMmsViewerPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);
	COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_ON_ENTER_PAGE, isBackward, m_mode, m_data->getIsPreview()); 
    if(getMainScr()->getIsSnapshotDrawing() == VFX_TRUE)
    {
		COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_ON_ENTER_PAGE, isBackward, 4, m_data->getIsPreview()); 
        return;
    }
    if(isBackward == VFX_TRUE)
    {
        if(m_mode == MODE_PLAY
        ||m_mode == MODE_PAUSE)
        {
            onPreviewPageFinish();
        }
    }
    m_Backward = isBackward;
}
void VappMmsViewerPage::loadXML(void)
{
	COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_ON_LOAD_XML, getMsgType(), m_mode);
    if(m_mode == MODE_STOP)
    {
        if(getMsgType() != MMA_MSG_TYPE_MMS)
        {
            VfxXmlLoader::loadBegin(this, VENUS_MMS_LAYOUT_NON_MMS_VIEWER);
        }
        else
        {
            VfxXmlLoader::loadBegin(this, VENUS_MMS_LAYOUT_MMS_VIEWER);
        }
    }
    else
    {
        VfxXmlLoader::loadBegin(this, VENUS_MMS_LAYOUT_MMS_VIEWER_PLAY);
    }
}

void VappMmsViewerPage::displayPopupAndExit(void)
{
    switch (m_error_type)
    {
        case SRV_MMS_VIEWER_PARSER_ERROR:
        case SRV_MMS_VIEWER_FILE_ERROR:
        {
            VappMmsPopup m_popup(STR_ID_VAPP_MMS_VIEWER_FILE_ERROR, VCP_POPUP_TYPE_FAILURE, this, (clickOk)&VappMmsViewerPage::onClickOk);           
            m_popup.displayPopup();
        }
        break;
        case SRV_MMS_VIEWER_OUT_OF_MEM:
        case SRV_MMS_VIEWER_OBJ_LIMIT_REACHED:
        {
            VappMmsPopup m_popup(STR_ID_VAPP_MMS_VIEWER_OUT_OF_MEMORY, VCP_POPUP_TYPE_FAILURE, this, (clickOk)&VappMmsViewerPage::onClickOk);           
            m_popup.displayPopup();
        }
        break;
        case SRV_MMS_VIEWER_NOT_ENOUGH_MEMORY:
        {
            VappMmsPopup m_popup(STR_GLOBAL_NOT_ENOUGH_MEMORY, VCP_POPUP_TYPE_FAILURE, this, (clickOk)&VappMmsViewerPage::onClickOk);           
            m_popup.displayPopup();
        }
        break;
        case SRV_MMS_VIEWER_ASM_ERROR:
        break;
        default:
        {
            VappMmsPopup m_popup(STR_GLOBAL_ABORTING, VCP_POPUP_TYPE_FAILURE, this, (clickOk)&VappMmsViewerPage::onClickOk);           
            m_popup.displayPopup();
        }
        break;
    }
}

void VappMmsPopup::displayPopup(void)
{
    VcpConfirmPopup *m_alertPopup = NULL;
    VfxWString txt(m_str_id);
    VFX_OBJ_CREATE(m_alertPopup, VcpConfirmPopup, m_memory);
    m_alertPopup->setInfoType(m_emotion);
    m_alertPopup->setText(txt);
    m_alertPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    // m_alertPopup->setAutoDestory(VFX_TRUE);
    m_alertPopup->show(VFX_TRUE);
    if(m_memFunc)
    {
        m_alertPopup->m_signalButtonClicked.connect(m_memory, m_memFunc);
    }
}

void VappMmsViewerPage::onClickOk(VfxObject* obj, VfxId id)
{
	this->getMainScr()->popPage();
}

void VappMmsViewerPage::onClickRRErrorOk(VfxObject* obj, VfxId id)
{
	draw();
}
VFX_IMPLEMENT_CLASS("VappMmsClock", VappMmsClock, VfxTextFrame);
VappMmsClock::clockState VappMmsClock::getClockState(void)
{
	return m_running;
}
void VappMmsClock::changeState(VappMmsClock::clockState newState)
{
    m_running = newState;
}

void VappMmsClock::onDrawInt(VfxTimer *timer)
{
    VfxU32 hrs, minutes, sec, total;
    VappMmsViewerPage *parent = NULL;
    mma_mms_description_struct *desc = NULL;
    srv_mms_viewer_slide_struct *current_slide = NULL;
    if(timer)
    {
        VfxU32 curr_tick = 0;
        timer->stop();
        getTime(&hrs, &minutes, &sec);
        kal_get_time(&curr_tick);
        if(kal_ticks_to_milli_secs(curr_tick - m_curr_tick)/ 1000 >= 1)
        {
            sec += kal_ticks_to_milli_secs(curr_tick - m_curr_tick)/ 1000;
            VfxU32 carry = sec / CLOCK_CONVERTOR;
            sec = sec % CLOCK_CONVERTOR;
            minutes = (minutes + carry) % CLOCK_CONVERTOR;
            carry = (minutes + carry) / CLOCK_CONVERTOR;
            hrs = (hrs + carry) % CLOCK_CONVERTOR;
            carry = (hrs + carry) / CLOCK_CONVERTOR;
            setTime(hrs, minutes, sec);
            m_curr_tick = curr_tick;
        }
        else
        {
            goto LeaveTimer;
        }
    }
    getTime(&hrs, &minutes, &sec);
    total = hrs * CLOCK_HRS + minutes * CLOCK_MINS + sec;
    srv_mms_viewer_xml_msg_struct *msg_cntx;
    parent = (VappMmsViewerPage *)VappMmsViewerPage::getMyPage();
    this->getParent();
    desc = srv_mms_get_desc_pointer();
    MMS_BODY_ERROR_HANDLE(desc);
    msg_cntx = parent->getMsgCntx();
	if(msg_cntx == NULL ||  m_running  == STATE_PAUSE || m_running  == STATE_WAIT)
	{
		return;
	}
	current_slide = *(msg_cntx->current_slide);
	if(msg_cntx && current_slide->duration != 0)
    {
        if(total >  current_slide->duration)
        {
            if(current_slide->next != NULL)
            {
                *(msg_cntx->current_slide)  = (*(msg_cntx->current_slide))->next;
                m_signalSlideSwitch.postEmit();
                return;
            }
            else
            {
                m_signalLastSlideEnd.postEmit();
                return;
            }
        }
        else
        {
            if(current_slide->img.id)
            {
                if(total == current_slide->img.end + 1)
                {
                #ifdef __DRM_SUPPORT__
                    VappMmsDrmHandler::stopConsumeRights(&(current_slide->img), parent->getMyData()->getMyIndex());
                #endif/*__DRM_SUPPORT__*/
                    m_signalMediaEnd.postEmit(SRV_MMS_OBJECT_TYPE_IMAGE);
                }
                else if(total == current_slide->img.begin)
                {
                    m_signalMediaEnd.postEmit(SRV_MMS_OBJECT_TYPE_IMAGE);
                }
            }
    #ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
            if(current_slide->vid.id)
            {
                if(total == current_slide->vid.end + 1)
                {
                    //VappMmsDrmHandler::stopConsumeRights(current_slide->vid.id);
                    //VappMmsDrmHandler::updateRightsById(current_slide->vid.id, VFX_FALSE);
                    m_signalMediaEnd.postEmit(SRV_MMS_OBJECT_TYPE_VIDEO);
                }
                else if(total == current_slide->vid.begin)
                {
                    if(total != 0)
                    {
                        m_signalMediaEnd.postEmit(SRV_MMS_OBJECT_TYPE_VIDEO);
                    }
                    else if (m_from_pause == VFX_FALSE)
                    {
                        m_signalMediaEnd.postEmit(SRV_MMS_OBJECT_TYPE_VIDEO);
                    }
                }
            }
       #endif     
            if(current_slide->aud.id)
            {
                if(total == current_slide->aud.end + 1)
                {
                #ifdef __DRM_SUPPORT__				
                    VappMmsDrmHandler::stopConsumeRights(&(current_slide->aud), parent->getMyData()->getMyIndex());
                #endif/*__DRM_SUPPORT__*/
                    m_signalMediaEnd.postEmit(SRV_MMS_OBJECT_TYPE_AUDIO);
                }
                else if(total == current_slide->aud.begin)
                {
                    m_signalMediaEnd.postEmit(SRV_MMS_OBJECT_TYPE_AUDIO);
                }
            }
            if(current_slide->txt.id)
            {
                if(total == current_slide->txt.end + 1 || (total == current_slide->txt.begin && m_from_pause == VFX_FALSE))
                {
                    m_signalMediaEnd.postEmit(SRV_MMS_OBJECT_TYPE_TEXT);
                }
            }
        }
    }
    {
    //COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_CLK_DRAW, minutes, sec);
    int timezone[4];
    timezone[0] = minutes / CLOCK_DECIMAL_CONVERTOR;
    timezone[1] = minutes % CLOCK_DECIMAL_CONVERTOR;
    timezone[2] = sec / CLOCK_DECIMAL_CONVERTOR;
    timezone[3] = sec % CLOCK_DECIMAL_CONVERTOR;
    char buffer[CLOCK_BUFF_LEN] = {0,};
    WCHAR buffer_passs[CLOCK_BUFF_LEN_UCS] = {0,};
    sprintf(buffer, "%d%d:%d%d", timezone[0], timezone[1], timezone[2], timezone[3]);
    mmi_asc_n_to_wcs(buffer_passs, buffer, CLOCK_BUFF_LEN);
    VfxWString txt;
    txt.loadFromMem((VfxWChar *)&buffer_passs);
    setString(txt);
    VfxFontDesc font;
    font.size = VFX_FONT_DESC_VF_SIZE(CLOCK_FONT_SIZE);
    setFont(font);  
    //setPos(parent_cp->getSize().width - getSize().width - CLOCK_RIGHT_MARGIN, getRect().getY());
    setMargins(0,
                CLOCK_TOP_MARGIN,
                0,
                CLOCK_BOTTOM_MARGIN);
    }

LeaveTimer:
    desc = srv_mms_get_desc_pointer();
    MMS_BODY_ERROR_HANDLE(desc);
    if(!allowTimer() ||m_running  == STATE_PAUSE ||m_running  == STATE_WAIT)
    {
        return;
    }
    if(timer == NULL)
    {
        VFX_OBJ_CREATE(timer, VfxTimer, getParent());
    }
    timer->setStartDelay(MMS_CLOCK_START_DELAY);
    timer->setDuration(MMS_CLOCK_TIME);
    timer->m_signalTick.connect(this, &VappMmsClock::onDrawInt);
    timer->start();
}
void VappMmsClock::onDraw(VfxDrawContext &dc)
{
    VfxTextFrame::onDraw(dc);
    VfxFrame *parent_cp = (VfxFrame *)this->getParent();
    setPos(parent_cp->getSize().width - getSize().width - CLOCK_RIGHT_MARGIN, getRect().getY());	
}
void VappMmsClock::startClock(VfxBool isfrompause )
{
    m_from_pause = isfrompause;
    if(m_running != STATE_WAIT)
    {
        m_running = STATE_RUNNING;
        kal_get_time(&m_curr_tick);
        onDrawInt(NULL);
    }
}
VfxU32 VappMmsClock::getTime(void)
{
	VfxU32 currTime ;
	VfxU32 hrs, minutes, sec;
	getTime(&hrs, &minutes, &sec);
	currTime = hrs * 3600 + minutes * 60 + sec;
	return currTime;
}
void VappMmsClock::getTime(VfxU32 *hrs,VfxU32 *minutes, VfxU32 *sec)
{
	*hrs = m_hrs;
	*minutes = m_min;
	*sec = m_sec;
}
void VappMmsClock::setTime(VfxU32 hrs, VfxU32 mins, VfxU32 sec)
{
	m_hrs = hrs;
	m_min = mins;
	m_sec = sec;
}
void VappMmsClock::pauseClock(void)
{
	m_running = STATE_PAUSE;
}
void VappMmsClock::waitClock(void)
{
	m_running = STATE_WAIT;
}
void VappMmsClock::ResumeClock(void)
{
    if(m_running == STATE_WAIT)
    {
        VfxTimer *timer = NULL;
        m_running = STATE_RUNNING;
        kal_get_time(&m_curr_tick);
        if(timer == NULL)
        {
            VFX_OBJ_CREATE(timer, VfxTimer, getParent());
        }
        timer->setStartDelay(MMS_CLOCK_START_DELAY);
        timer->setDuration(MMS_CLOCK_TIME);
        timer->m_signalTick.connect(this, &VappMmsClock::onDrawInt);
        timer->start();
    }
}
VFX_IMPLEMENT_CLASS("VappMmsAudioPlay", VappMmsAudioPlay, VfxControl);
VfxBool VappMmsAudioPlay::allowAudioPlay(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //MMI_ALERT_TYPE alertType = GetMtCallAlertTypeEnum();
	srv_prof_alert_type_enum alertType;
	srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_ALERT_TYPE ,(void*) (&alertType));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((alertType != SRV_PROF_ALERT_TYPE_VIB_AND_RING && alertType != SRV_PROF_ALERT_TYPE_VIB_THEN_RING && alertType != SRV_PROF_ALERT_TYPE_RING)
        || !(
        (srv_ucm_query_call_count((srv_ucm_call_state_enum)SRV_UCM_CALL_STATE_ALL, (srv_ucm_call_type_enum)SRV_UCM_CALL_TYPE_ALL, NULL) == 0)
        ||
        (
        srv_ucm_query_call_count((srv_ucm_call_state_enum)SRV_UCM_CALL_STATE_ALL, (srv_ucm_call_type_enum)SRV_UCM_CALL_TYPE_ALL, NULL) > 0
        && srv_ucm_query_call_count((srv_ucm_call_state_enum)SRV_UCM_CALL_STATE_ALL, (srv_ucm_call_type_enum)SRV_UCM_CSD_CALL_TYPE_ALL, NULL) > 0
        )
        )
        || ((srv_prof_is_profile_activated(SRV_PROF_MEETING_MODE)  == SRV_PROF_RET_SUCCESS) && alertType == SRV_PROF_ALERT_TYPE_VIB_ONLY)
        || (srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) == SRV_PROF_RET_SUCCESS))
    {
        /* If the profile setting is meeting or silent  */
        //        COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_CALLBACK_BLOCK_AUDIO);
        return VFX_FALSE;
    }
    return VFX_TRUE;
}

void VappMmsAudioPlay::playAudio(void)
{
    VfxU16 vfname[SRV_MMS_VIEWER_VFN_NUM_OF_WCHAR];
    /* set volume */
    mmi_frm_cb_reg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, &VappMmsAudioPlay::listener, getObjHandle());
	mmi_frm_cb_reg_event(EVT_ID_SRV_PROF_IS_PLAYING, &VappMmsAudioPlay::listener, getObjHandle());
    m_currVol = srv_prof_get_media_vol();
    if(allowAudioPlay() == VFX_TRUE)
    {
        mdi_audio_suspend_background_play();
        m_bgSuspend = VFX_TRUE;
    }
    if(srv_mms_get_filename_by_id(m_audio_obj, vfname, &m_file_path, &m_audioFileHandle))
    {
        if(m_file_path == NULL)
        {
            return;
        }
        VfxU32 audio_duration;
    #ifdef __DRM_SUPPORT__
        VappMmsDrmHandler::updateRightsById(m_audio_obj, VFX_FALSE, m_srv_index);
        if (VappMmsDrmHandler::checkRightsById(m_audio_obj, m_srv_index) == VFX_FALSE)
    #endif/*__DRM_SUPPORT__*/			
        {
            m_audioValid = VFX_TRUE;
        }
        if (mdi_audio_get_duration(m_file_path, &audio_duration) != MDI_AUDIO_SUCCESS)
        {
            m_audioValid = VFX_FALSE;
            //COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_AUDIO_PLAY_FAIL_GET_DUR);
        }
        if(m_audioPlaying == VFX_FALSE && m_audioValid == VFX_TRUE)
        {
        #ifdef __DRM_SUPPORT__
            VfxBool ret_val;
            ret_val= VappMmsDrmHandler::startConsumeRights(m_audio_obj, 
            m_file_path, VappMmsViewerCp::onAudioRightsExpiry, (void*) this, m_srv_index);
            //g_wgui_mv_cat_cntx.is_audio_start_play = MMI_FALSE;
            if (ret_val == VFX_TRUE)
            {
        #endif/*__DRM_SUPPORT__*/			
                if (mdi_audio_play_file(
                    m_file_path, 
                    DEVICE_AUDIO_PLAY_ONCE, 
                    NULL, 
                    mediaStoppedCallback,
                    (void *)getObjHandle()) == MDI_AUDIO_SUCCESS)
                {
                    m_audioPlaying = VFX_TRUE;
                    m_state = AUDIO_STATE_PLAY;
                    mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX(m_currVol));
                    //COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_AUDIO_PLAY_START);
                }
                else
                {
                    m_audioValid = VFX_FALSE;
                }
        #ifdef __DRM_SUPPORT__
            }
        #endif			
        }
    }
	else
	{
		//handle error
	}
}
void VappMmsAudioPlay::pauseAudio(void)
{
    if(m_state != AUDIO_STATE_PLAY)
    {
        return;
    }
    mdi_result ret = mdi_audio_pause(mediaStoppedCallback, (void *)getObjHandle());
    if (ret == MDI_AUDIO_SUCCESS)
    {
        m_state = AUDIO_STATE_PAUSE;
    }
    else
    {
        m_state = AUDIO_STATE_PAUSE_FAIL;
    #if defined(AAC_DECODE)
        if (mdi_audio_is_aac_file_seekable(m_file_path) == MMI_FALSE)
        {
            mdi_audio_stop_file();
            m_audioPlaying = VFX_FALSE;
            /* reset slide_time when best_paging and audio can not pause */
        }
        else
    #endif/*AAC_DECODE*/
        if (ret == MDI_AUDIO_END_OF_FILE)
        {
            mediaStoppedCallback(MDI_AUDIO_SUCCESS, (void *)getObjHandle());
        }
    }
}
void VappMmsAudioPlay::resumeAudio(void)
{
    if (m_state == AUDIO_STATE_PAUSE_FAIL
    #if defined(AAC_DECODE)
        && mdi_audio_is_aac_file_seekable(m_file_path) == MMI_FALSE
    #endif/*AAC_DECODE*/
    )
    {
        #ifdef __DRM_SUPPORT__
            /* do not consume right while resume */
            mdi_audio_drm_disable_consume_count();
        #endif /* __DRM_SUPPORT__ */
        if (mdi_audio_play_file(
            m_file_path, 
            DEVICE_AUDIO_PLAY_ONCE, 
            NULL, 
            mediaStoppedCallback, 
            (void *)getObjHandle()) == MDI_AUDIO_SUCCESS)
        {
            m_audioPlaying = VFX_TRUE;
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX(m_currVol));
            m_state = AUDIO_STATE_PLAY;               
        }
    }
    else if (m_state == AUDIO_STATE_PAUSE)
    {
        mdi_audio_resume(mediaStoppedCallback, (void *)getObjHandle());
        m_state = AUDIO_STATE_PLAY;
    }
}
void VappMmsAudioPlay::mediaStoppedCallback(mdi_result result, void *user_data)
{
	VappMmsAudioPlay *myData = (VappMmsAudioPlay *)VfxObject::handleToObject((VfxObjHandle)user_data);
	if(myData && myData->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsAudioPlay)) )
	{
		return myData->mediaStoppedCallbackInt(result);
	}
}
void VappMmsAudioPlay::mediaStoppedCallbackInt(mdi_result result)
{
    if(m_audioPlaying == VFX_FALSE)
    {
        return;
    }
    if ((result < 0) &&
        (result != MDI_AUDIO_END_OF_FILE))
    {
        deinitAudio();
        m_audioValid = VFX_FALSE;
    }
#ifdef __DRM_SUPPORT__

    switch (result)
    {
        case MDI_AUDIO_DRM_TIMEOUT:
        case MDI_AUDIO_DRM_PROHIBIT:
            if (m_audio_obj)
            {
                VappMmsViewerCp::onAudioRightsExpiry(NULL);
                deinitAudio();
            }
        return;
    }
    if (m_audio_obj)
    {
        VappMmsDrmHandler::stopConsumeRights(m_audio_obj, m_srv_index);
        deinitAudio();
        /* Audio stopped that is why this is called other than DRM case where we have to stop our self */
    }
#endif/*__DRM_SUPPORT__*/	
}
void VappMmsAudioPlay::deinitAudio(void)
{
    stopAudio();
    if(m_audioFileHandle)
    {
        FS_Close(m_audioFileHandle);
        m_audioFileHandle = 0;
    }
    mdi_audio_resume_background_play();
    mmi_frm_cb_dereg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, &VappMmsAudioPlay::listener, getObjHandle());
    
	mmi_frm_cb_dereg_event(EVT_ID_SRV_PROF_IS_PLAYING, &VappMmsAudioPlay::listener, getObjHandle());
}

mmi_ret VappMmsAudioPlay::listener(mmi_event_struct *evt)
{
    vapp_vol_dialog_evt_struct *evt_sound = (vapp_vol_dialog_evt_struct *)evt;
    VappMmsAudioPlay *aud_obj = (VappMmsAudioPlay *)VfxObject::handleToObject((VfxObjHandle)evt_sound->user_data);
    if(evt_sound->evt_id == EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE 
        &&aud_obj
        && aud_obj->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsAudioPlay))
        &&evt_sound->type == VAPP_VOL_DIALOG_IS_MEDIA)
    {
        return !MMI_RET_OK;
    }
    else if(evt_sound->evt_id == EVT_ID_SRV_PROF_IS_PLAYING 
        &&aud_obj
        && aud_obj->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsAudioPlay)))
    {           
        return !MMI_RET_OK;
    }
    return MMI_RET_OK;
}
void VappMmsAudioPlay::stopAudio(void)
{
    if(m_audioPlaying == VFX_TRUE)
    {
        m_audioPlaying = VFX_FALSE;
#ifdef __DRM_SUPPORT__		
        VappMmsDrmHandler::stopConsumeRights(m_audio_obj, m_srv_index);
#endif
        mdi_audio_stop_file();
    }
}
VfxBool VappMmsAudioPlay::onKeyInput(VfxKeyEvent& event)
{
	return VfxControl::onKeyInput(event);
}
extern "C" mmi_id cui_vapp_mms_view_mms_create(mmi_id parent_id,   U32 msg_id, U32 index, U8 msg_location)
{
    VappMmsViewerStartStruct startData;
    mmi_id cui_id;
    memset(&startData, 0, sizeof(VappMmsViewerStartStruct));
    startData.mode = MODE_PLAY;
    startData.msg_id = msg_id;
    startData.index = index;
    startData.isPreview = VFX_FALSE; 
    startData.msg_location = msg_location;
    cui_id = VfxAppLauncher::createCui(VCUI_MMS,
                                        VFX_OBJ_CLASS_INFO(VappMmsViewer),
                                        parent_id,
                                        (void *)&startData,
                                        sizeof(VappMmsViewerStartStruct));
    return cui_id;
}

extern "C" void cui_vapp_mms_preview_mms_run(mmi_id cui_id)
{
	VfxAppLauncher::runCui(cui_id);
}
extern "C" mmi_id cui_vapp_mms_preview_mms_create(mmi_id parent_id,   U32 msg_id)
{
    VappMmsViewerStartStruct startData;
    mmi_id cui_id;
    memset(&startData, 0, sizeof(VappMmsViewerStartStruct));
    startData.mode = MODE_PLAY;
    startData.msg_id = msg_id;
    startData.isPreview = VFX_TRUE; 
    cui_id = VfxAppLauncher::createCui(VCUI_MMS,
                                        VFX_OBJ_CLASS_INFO(VappMmsViewer),
                                        parent_id,
                                        (void *)&startData,
                                        sizeof(VappMmsViewerStartStruct));
    return cui_id;
}
mmi_ret VappMmsViewer::onProc(mmi_event_struct *evt)
{
	return VfxApp::onProc(evt);
}
#ifdef __MMI_MMS_USE_ASM__  
VfxAppCloseAnswerEnum VappMmsViewer::onProcessClose(VfxAppCloseOption options)
{
    if(m_scrn->m_page)
    {
        if(m_scrn->m_page->checkmmsgetcontent() == VFX_TRUE)
        {        

            return VFX_APP_CLOSE_ANSWER_LATER;
        }
    }
    return VFX_APP_CLOSE_ANSWER_YES;
}
void VappMmsViewer::callclosecontinue(void)
{
    continueClose(VFX_APP_CLOSE_ANSWER_YES);
}
#endif

extern "C" void cui_vapp_mms_preview_mms_close(mmi_id cui_id)
{
	VfxAppLauncher::terminate(cui_id);
}
mmi_ret VappMmsViewerPage::onProc(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_CLOSE_MMS_PREVIEW:
        if (m_cui_id != GRP_ID_INVALID)
        {
            cui_vapp_mms_preview_mms_close(m_cui_id);
        }
        break;
    }
    return VfxPage::onProc(evt);
}
void VappMmsViewerPage::onPreviewPageFinish(void)
{
    //COSMOS_MMS_TRACE(MMI_INET_TRC_G6_MMS, TRC_VAPP_MMS_PREVIEW_PAGE_FINISH, __LINE__); 
#ifdef __MMI_MMS_USE_ASM__      
     if(getMsgType() == MMA_MSG_TYPE_MMS && m_wait_data_done == VFX_TRUE)
    {     
    
        m_preview_finish = VFX_TRUE;
        return;
    } 
#endif     
    cui_vapp_mms_preview_evt_struct evt;
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CLOSE_MMS_PREVIEW, getApp()->getGroupId());
    VfxCui *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VfxCui);
    getMainScr()->popPage();
    app->postToCaller((mmi_group_event_struct*)&evt);
    srv_backlight_turn_off();
}
VfxU32 VappMmsViewerPage::getPanelHeightVideo(void)const
{    
    return getSize().height;
}
VfxColor VappMmsViewerCp::convertFromGdiColorToColor(VfxU32 incolor_32)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VfxColor color( (U8) (255),
    (U8) ((0xFF000000 & incolor_32) >> 24),
    (U8) ((0x00FF0000 & incolor_32) >> 16),
    (U8) ((0x0000FF00 & incolor_32) >> 8));
    return color;
}
void VappMmsViewerCp::setState(redrawStateEnum state)
{
	m_state = state;
}
void VappMmsViewerCp::startMediaRightsConsumption(void)
{
    srv_mms_viewer_xml_msg_struct *msg_cntx;
    VappMmsViewerPage *parent = (VappMmsViewerPage *)m_page;
    mma_mms_description_struct *desc = srv_mms_get_desc_pointer();
    MMS_BODY_ERROR_HANDLE(desc);
    msg_cntx = parent->getMsgCntx();
    if(msg_cntx == NULL)
    {
        return;
    }
    srv_mms_viewer_slide_struct *current_slide = *(msg_cntx->current_slide);
    if(current_slide->img.id && m_visual)
    {
        VfxImageFrame *m_frame = (VfxImageFrame *)m_visual->getFrame();
    #ifdef __DRM_SUPPORT__		
        VappMmsDrmHandler::updateRightsById(&(current_slide->img), VFX_FALSE, parent->m_data->getMyIndex());
        if(VappMmsDrmHandler::checkRightsById(&(current_slide->img), parent->m_data->getMyIndex()) == MMI_FALSE)
        {
            if(VappMmsDrmHandler::startConsumeRights(&(current_slide->img), m_img_file_path, VappMmsViewerCp::onImageRightsExpiry, (void*) this, parent->m_data->getMyIndex())  == MMI_FALSE)
            {
                m_frame->setResId(VfxResId(IMG_ID_VENUS_MMS_DRM_DEFAULT));
                upDateMediaBounds();	
                m_main_txt->UpdateViewForCustomFrame();
            }
            else
            {
    #endif				
                VfxWString file_path_ext;
                m_frame->setPath(file_path_ext.loadFromMem(m_img_file_path));
                if(m_frame->getSize().width == 0 || m_frame->getSize().height == 0)
                {
                    m_frame->setResId(VfxResId(IMG_ID_VENUS_MMS_CORRUPT_IMAGE));
                #ifdef __DRM_SUPPORT__					
                    VappMmsDrmHandler::stopConsumeRights(&(current_slide->img), parent->m_data->getMyIndex());
                #endif
                }
                upDateMediaBounds();
                m_main_txt->UpdateViewForCustomFrame();
    #ifdef __DRM_SUPPORT__				
            }
        }
        else
        {
            m_frame->setResId(VfxResId(IMG_ID_VENUS_MMS_DRM_DEFAULT));
            upDateMediaBounds();
            m_main_txt->UpdateViewForCustomFrame();
        }
    #endif		
    }
    
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
    else if(current_slide->vid.id)
    {
        m_state = REDRAW_MEDIA_NEEDED;
        setBounds(getBounds());
    }
#endif
}
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
VappVideoPlayerComponent *VappMmsViewerCp::getVideo(void)
{
    if(m_visual)
    {
        VfxFrame *myFrame = m_visual->getFrame();
        if(myFrame->isKindOf(VFX_OBJ_CLASS_INFO(VappVideoPlayerComponent)))
        {
            return (VappVideoPlayerComponent *)myFrame;
        }
        return NULL;
    }
    return NULL;
}
#endif
VFX_IMPLEMENT_CLASS("VappMmsContactProvider", VappMmsContactProvider, VappMsgContactProvider);
 void VappMmsContactProvider::setMsgID(VfxU32 msgID)
{
    m_msgID = msgID;
    srv_mms_result_enum result;
    m_alloc_fn = &VappMmsContactProvider::allocMem;
    m_free_fn = &VappMmsContactProvider::freeMem;
    mms_msg_addr_info = (p_srv_mms_msg_report_status *)m_alloc_fn(sizeof(p_srv_mms_msg_report_status)* 3, (void *)getObjHandle());
    memset(mms_msg_addr_info, 0, sizeof(p_srv_mms_msg_report_status) * 3);
    mms_msg_addr_info[0] = (srv_mms_msg_report_status_struct *)m_alloc_fn(sizeof(srv_mms_msg_report_status_struct)* 20, (void *)getObjHandle());
    mms_msg_addr_info[1] = (srv_mms_msg_report_status_struct *)m_alloc_fn(sizeof(srv_mms_msg_report_status_struct)* 20, (void *)getObjHandle());
    mms_msg_addr_info[2] = (srv_mms_msg_report_status_struct *)m_alloc_fn(sizeof(srv_mms_msg_report_status_struct)* 20, (void *)getObjHandle());
    result = (srv_mms_result_enum)srv_mms_get_mms_msg_addr_info(m_msgID,
                                                                mms_msg_addr_info,
                                                                &m_to_count,
                                                                &m_cc_count,
                                                                &m_bcc_count,
                                                                m_alloc_fn,
                                                                m_free_fn,
                                                                (void *)getObjHandle());
    if(result == SRV_MMS_RESULT_OK)
    {
        //take action
    }
}

VfxBool VappMmsContactProvider::getContact(VappMsgContact& contact, VcpMenuPos index)
{
    VfxBool result = VFX_TRUE;
    srv_mms_msg_status_enum status = srv_mms_get_msg_status(m_msgID);
    VfxS32 count = 0;
    switch(index.group)
    {
        case VAPP_CONTACT_TYPE_TO:
            count = m_to_count;
        break;
        case VAPP_CONTACT_TYPE_CC:
            count = m_cc_count;
        break;
        case VAPP_CONTACT_TYPE_BCC:
            count = m_bcc_count;
        break;
    }
    if (index.pos < count + 1)
    {
        VfxResId imageId = 0;
        contact.m_address.loadFromMem(mms_msg_addr_info[index.group][index.pos].address);
        if(mms_msg_addr_info[index.group][index.pos].addr_type == MMA_ADDR_TYPE_PHONE_NUMBER)
        {
            contact.m_type = VAPP_MSG_CONTACT_TYPE_PHONENUMBER;
        }
        else
        {
            contact.m_type = VAPP_MSG_CONTACT_TYPE_EMAIL;
        }
        switch(status)
        {
            case SRV_MMS_MSG_STATUS_SENDING:
                imageId = IMG_ID_VENUS_MMS_SENDING;
            break;
            case SRV_MMS_MSG_STATUS_WAITING:
            case SRV_MMS_MSG_STATUS_PENDING:
                imageId = IMG_ID_VENUS_MMS_WAITING;
            break;
            case SRV_MMS_MSG_STATUS_SENDING_FAILED:
                imageId = IMG_ID_VENUS_MMS_SEND_FAIL;
            break;
        }
        if(imageId)
        {
            contact.m_statusIcon.setResId(imageId);
        }
    }
    else
    {
        result = VFX_FALSE;
    }
return result;
}
VfxU32 VappMmsContactProvider::getCount(VfxU32 group) const
{
    switch(group)
    {
        case VAPP_CONTACT_TYPE_TO:
            return (m_to_count + 1);
        case VAPP_CONTACT_TYPE_CC:
            return (m_cc_count + 1);
        case VAPP_CONTACT_TYPE_BCC:
            return (m_bcc_count + 1);
    }
    return 0;
}
VfxBool VappMmsContactProvider::getHeaderText(VfxS32 group, VfxWString& address) const
{
    switch(group)
    {
        case VAPP_CONTACT_TYPE_TO:
            address.loadFromRes(STR_ID_VAPP_MMS_CONTACT_TO);
        break;
        case VAPP_CONTACT_TYPE_CC:
            address.loadFromRes(STR_ID_VAPP_MMS_CONTACT_CC);
        break;
        case VAPP_CONTACT_TYPE_BCC:
            address.loadFromRes(STR_ID_VAPP_MMS_CONTACT_BCC);
        break;
    }
    return VFX_TRUE;
}
VfxBool VappMmsContactProvider::isResendFailed(void)
{
    VfxBool result = VFX_FALSE;
    srv_mms_msg_status_enum status = srv_mms_get_msg_status(m_msgID);
    if (status == SRV_MMS_MSG_STATUS_SENDING_FAILED)
    {
        result = VFX_TRUE;
    }
    return result;
}
void VappMmsContactProvider::resendFailed(void)
{
    VappMmsViewerData *m_data = NULL;
    if(srv_mms_get_msg_status(m_msgID) != SRV_MMS_MSG_STATUS_SENDING_FAILED)
    {
        return;
    }
    VFX_OBJ_CREATE_EX(m_data, VappMmsViewerData, this, (m_msgID, VappMmsViewerData::MODE_LIGHT));
    if(m_data->checkMsgInfoDataReady() == VFX_FALSE)
    {
        VFX_OBJ_CLOSE(m_data);
        m_data = NULL;
        return ;
    }
    mmi_umms_app_dtmgr_msg_info_data_struct * msg_info = m_data->getMsgInfo();
    srv_mms_send_req_struct req; 
    mmi_sim_enum  sim_id = vapp_mms_convert_mma_sim_to_mmi_sim(msg_info->msg_sim_info);   
    if(srv_sim_ctrl_chv1_is_blocked(sim_id))
    {
        mmi_frm_nmgr_balloon(
                                MMI_SCENARIO_ID_MMS_INFO,
                                MMI_EVENT_INFO_BALLOON,
                                MMI_NMGR_BALLOON_TYPE_INFO,
                                (WCHAR*)GetString(STR_GLOBAL_UNAVAILABLE_SIM));
        VFX_OBJ_CLOSE(m_data);
        m_data = NULL;
        return;
    }
    if(!srv_mode_switch_is_network_service_available())
    {
        mmi_frm_nmgr_balloon(
                                MMI_SCENARIO_ID_MMS_INFO,
                                MMI_EVENT_INFO_BALLOON,
                                MMI_NMGR_BALLOON_TYPE_INFO,
                                (WCHAR*)GetString(STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE));
        VFX_OBJ_CLOSE(m_data);
        m_data = NULL;
        return;
    }
    memset(&req, 0, sizeof(srv_mms_send_req_struct));
    req.sim_id = msg_info->msg_sim_info;
    req.send_setting = SRV_MMS_SETTING_SAVE_AND_SEND;       /* SRV_MMS_SETTING_SAVE_AND_SEND;SRV_MMS_SETTING_SEND_ONLY */
    req.msg_id = m_msgID;
    req.is_rr = (kal_bool)VFX_FALSE;
    req.storage_type = msg_info->storage_location;
    VFX_OBJ_CLOSE(m_data);
    m_data = NULL;
    m_signalMmsClose.postEmit();
    mmi_umms_set_current_msg_id_in_view(0);
    srv_mms_send(&req);
}
void VappMmsContactProvider::onDeinit(void)
{
    VappMsgContactProvider::onDeinit();
    m_free_fn(mms_msg_addr_info[0]);
    m_free_fn(mms_msg_addr_info[1]);
    m_free_fn(mms_msg_addr_info[2]);
    m_free_fn(mms_msg_addr_info);
    mms_msg_addr_info = NULL;
}
VfxBool VappMmsContactProvider::hasGroupHeader(VfxS32 group) const
{
    VfxS32 count = 0;
    switch(group)
    {
        case VAPP_CONTACT_TYPE_TO:
            count = m_to_count + 1;
        break;
        case VAPP_CONTACT_TYPE_CC:
            count = m_cc_count + 1;
        break;
        case VAPP_CONTACT_TYPE_BCC:
            count = m_bcc_count + 1;
        break;
    }
    return VFX_TRUE ? count > 0 : 0;
}
VfxU32 VappMmsContactProvider::getGroupCount(void) const
{
	return 3;
}

VfxBool VappMmsContactProvider::getGroupPrefix(VfxU32 group, VfxWString& text) const
{
    switch(group)
    {
    #if(0)	
        case VAPP_CONTACT_TYPE_TO:
            if(m_to_count + 1 > 0)
            {
                text.loadFromRes(STR_ID_VAPP_MMS_CONTACT_TO);
                text += VFX_WSTR(": ");
                return VFX_TRUE;
            }
            break;
    #endif
        case VAPP_CONTACT_TYPE_CC:
            if(m_cc_count + 1 > 0)
            {
                text.loadFromRes(STR_ID_VAPP_MMS_CONTACT_CC_RECIPIENTS);
                return VFX_TRUE;
            }
            break;
        case VAPP_CONTACT_TYPE_BCC:
            if(m_bcc_count + 1 > 0)
            {
                text.loadFromRes(STR_ID_VAPP_MMS_CONTACT_BCC_RECIPIENTS);
                return VFX_TRUE;
            }
            break;
    }
return VFX_FALSE;
}
VfxBool VappMmsContactProvider::isShowMemberInBar(VfxU32 group) const
{
    switch(group)
    {
        case VAPP_CONTACT_TYPE_TO:
            if(m_to_count + 1 > 0)
            {
                return VFX_TRUE;
            }
            break;
        case VAPP_CONTACT_TYPE_CC:
            return VFX_FALSE;
        case VAPP_CONTACT_TYPE_BCC:
            return VFX_FALSE;
    }
    return VFX_FALSE;
}
VfxBool VappMmsContactProvider::isShowRecipientList(VfxWString& causeStr)
{
    if(SRV_MMS_MSG_STATUS_SENDING == srv_mms_get_msg_status(m_msgID))
	{
        causeStr.loadFromRes(STR_ID_VAPP_MMS_NOT_OPEN_RECIPIENT_LIST); 
		return VFX_FALSE;	
	}
	return VFX_TRUE;
}
void * VappMmsContactProvider::allocMem(U32 size, void *user_data)
{
    void *mem = NULL;
    VappMmsContactProvider *my_data = (VappMmsContactProvider *)VfxObject::handleToObject((VfxObjHandle)user_data);
    if(my_data && my_data->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsContactProvider)) )
    {
        VFX_ALLOC_MEM(mem, size, my_data);
    }
    return mem;
}
void  VappMmsContactProvider::freeMem(void *mem)
{
	VFX_FREE_MEM(mem);
}
#endif /* __MMI_MMS_2__   */
