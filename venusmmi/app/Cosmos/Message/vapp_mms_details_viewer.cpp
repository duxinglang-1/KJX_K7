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
 *  vapp_mms_details_viewer.cpp
 *
 * Project:
 * --------
 *  
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *
 ============================================================================
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#include "vapp_msg_features.h"

#ifdef __MMI_MMS_2__
#include "vadp_mmi_frm.h"
#include "vfx_uc_include.h"
#include "vcp_text_view.h"
#include "vcp_app_scr.h"
#include "vcp_include.h"
#include "ui_core\mvc\vfx_mmi.h"

#include "vcp_status_icon_bar.h"
#include "vcp_page_panel.h"
#include "vcp_list_menu.h"
#include "vcp_popup.h"
#include "vcp_image_button.h"
#include "vapp_mms_details_viewer.h"
#include "fileMgrGProt.h"
#include "mmi_include.h"
#include "ctype.h" 
#include "kal_release.h"
#include "MMIDataType.h"
#include "mmi_include.h"
#include "kal_trace.h"
#include "SettingProfile.h"
#include "fileMgrGProt.h"
#include "Fs_type.h"
#include "med_api.h"
#include "med_smalloc.h"
#include "gdi_include.h"
#include "gdi_layer.h"
/* Venus MMI headers: */
#include "ui_core\base\vfx_datatype.h"
#include "ui_core\base\vfx_base.h"
#include "trc\vadp_app_trc.h"
#include "MMI_features.h"



#include "mmi_include.h"
#include "ctype.h" 
#include "kal_release.h"
#include "MMIDataType.h"
#include "mmi_include.h"
#include "kal_trace.h"
#include "SettingProfile.h"
#include "fileMgrGProt.h"
#include "Fs_type.h"
#include "med_api.h"
#include "med_smalloc.h"
#include "gdi_include.h"
#include "gdi_layer.h"

#include "CubeAppGprot.h"
#include "CubeAppProt.h"
#include "CubeApp\vadp_p2v_cube.h"
#include "CubeApp\vadp_v2p_cube.h"

/* Venus MMI headers: */
#include "ui_core\base\vfx_datatype.h"
#include "ui_core\base\vfx_base.h"
#include "trc\vadp_app_trc.h"
#include "DateTimeGprot.h"
#include "vapp_mms_toolbar.h"
#include "mmi_rp_vapp_mms_def.h"
extern "C"
{
#include "MMSSRVGProt.h"
#include "MMSSRVProt.h"
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGProt.h"
}
//#include "vcp_msg_contact_bar.h"
#include "vapp_mms_lite_viewer.h"
#include "vapp_mms_viewer.h"
#include "vapp_mms_toolbar.h"
#include "vapp_mms_viewer.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "vapp_mms_appcore.h"
#include "vapp_mms_common.h"

VFX_IMPLEMENT_CLASS("VappMmsDetailsViewer", VappMmsDetailsViewer, VfxControl);

void VappMmsDetailsViewer::onInit(void)
{
    VfxControl::onInit();
    //setBgColor(VFX_COLOR_WHITE);	
    setBgColor(VFX_COLOR_RES(VAPP_MMS_VIEWER_TEXT_BACKGROUND_COLOR));
    mmi_frm_cb_reg_event(EVT_ID_SRV_SHOW_BGSR_POPUP, VappMmsDetailsViewer::listener, getObjHandle());
    //draw();
}
void VappMmsDetailsViewer::onDeinit(void)
{
    VfxControl::onDeinit();
    if(m_download)
    {
        VFX_OBJ_CLOSE(m_download);
        m_download = NULL;
    }
    if(m_indicator)
    {
        VFX_OBJ_CLOSE(m_indicator);
        m_indicator = NULL;
    }
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SHOW_BGSR_POPUP, VappMmsDetailsViewer::listener, getObjHandle());
}

void VappMmsDetailsViewer::setData(VappMmsViewerData *data)
{
    m_data = data;
    m_msg_id = m_data->getMsgId();
    setAlignParent(
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE);
    if ((m_data->getMsgInfo()->result == MMA_RESULT_OK) && (m_data->getMsgInfo()->isRead == MMI_FALSE))
    {
        U8 error = 0;
        U8 srv_result = 0;
        srv_mms_um_refresh_ind_struct req;
        mma_folder_enum folder_id = mma_get_box(m_msg_id);
        srv_result = srv_mms_set_read_status(m_msg_id, (kal_bool)MMI_TRUE, &error);
        if(srv_result == SRV_MMS_RESULT_OK)
        {
            if(error == MMA_RESULT_OK)
            {
                srv_mms_show_status_icon();
                m_data->getMsgInfo()->isRead = MMI_TRUE;
            }
            memset(&req, 0, sizeof(srv_mms_um_refresh_ind_struct));
            req.msg_box_type = folder_id;
            req.refresh_type = SRV_UM_REFRESH_MSG_STATUS_CHANGED;
            req.msg_id = m_msg_id;
            srv_mms_um_refresh_msg_list(&req); 
        }
    }
	draw();
}

VfxBool VappMmsDetailsViewer::draw(void)
{

    mmi_umms_app_dtmgr_msg_info_data_struct * msg_info = m_data->getMsgInfo();
    mmi_sim_enum  sim_id = vapp_mms_convert_mma_sim_to_mmi_sim(msg_info->msg_sim_info);
    if( msg_info->result == MMA_RESULT_FAIL_FILE_CORRUPTED
    || msg_info->result == MMA_RESULT_FAIL_UNSUPPORT_MMS_TYPE)
    {
        VfxTextFrame *txt_subject;
        VfxWString txt;
        txt.loadFromRes(STR_ID_VAPP_MMS_CORRUPTED_MESSAGE);
        VFX_OBJ_CREATE(txt_subject, VfxTextFrame, this);
        txt_subject->setPos(VAPP_MMS_DETAILS_SUBJECT_LEFT_MARGIN, VAPP_MMS_DETAILS_SUBJECT_UPPER_MARGIN);
        txt_subject->setSize(getSize().width - VAPP_MMS_DETAILS_SUBJECT_LEFT_MARGIN - VAPP_MMS_DETAILS_BUTTON_RIGHT_MARGIN, VAPP_MMS_SUBJECT_FONT_SIZE);
        txt_subject->setColor(VFX_COLOR_RES(VAPP_MMS_VIEWER_TEXT_COLOR));     
        txt_subject->setString(txt);
        txt_subject->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_MMS_SUBJECT_FONT_SIZE)));
        txt_subject->setAutoResized(VFX_TRUE);        
        txt_subject->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        txt_subject->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
        txt_subject->setAlignParent(VFX_FRAME_ALIGNER_SIDE_LEFT, VFX_FRAME_ALIGNER_MODE_SIDE);
        txt_subject->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, VFX_FRAME_ALIGNER_MODE_SIDE);
        txt_subject->forceUpdate();

        if(msg_info->receive_date)
        {
            VfxTextFrame *recv_date;
            VfxWString str7;
            VFX_OBJ_CREATE(recv_date, VfxTextFrame, this);
            recv_date->setPos(0, VAPP_MMS_DETAILS_SUBJECT_UPPER_MARGIN + VAPP_MMS_BUTTON_DATE_MARGIN + VAPP_MMS_SUBJECT_FONT_SIZE);
            recv_date->setSize(getSize().width - VAPP_MMS_DATE_RIGHT_MARGIN, VAPP_MMS_SIZE_FONT_SIZE);
            recv_date->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_MMS_SIZE_FONT_SIZE)));
            recv_date->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
            recv_date->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
            recv_date->setAutoResized(VFX_FALSE);
            recv_date->setAlignParent(VFX_FRAME_ALIGNER_SIDE_LEFT, VFX_FRAME_ALIGNER_MODE_SIDE);
            recv_date->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, VFX_FRAME_ALIGNER_MODE_SIDE);
            VfxU32 localSec = 0;
            applib_time_struct dateTime;
            VfxU32 flags;
            memset(&dateTime, 0, sizeof(applib_time_struct));
            localSec = applib_dt_sec_utc_to_local(msg_info->receive_date);
            mmi_dt_utc_sec_2_mytime(localSec, &dateTime, MMI_FALSE);
            VfxDateTime time;
            time.setDateTime(&dateTime);
            VfxWChar buf[80];
            memset(buf, 0, sizeof(VfxWChar)*80);
            //if (isToday(m_event[idx]->time))
            {
            flags = VFX_DATE_TIME_DATE_YEAR            |
            VFX_DATE_TIME_DATE_MONTH           |
            VFX_DATE_TIME_DATE_DAY             |
            VFX_DATE_TIME_TIME_HOUR            |
            VFX_DATE_TIME_TIME_MINUTE         /* |
                    VFX_DATE_TIME_TIME_SECOND */;         
                    }
                    /* else
                    {
                    flags = VFX_DATE_TIME_DATE_MASK;
                    }*/

            time.getDateTimeString(flags, (VfxWChar *)buf, sizeof(buf));
            str7 = VFX_WSTR_MEM(buf);
            recv_date->setString(str7);
            recv_date->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));
            recv_date->forceUpdate();
        }
        return VFX_FALSE;
    }
    mmi_umms_app_dtmgr_xml_header_info_struct *header_info = m_data->getHeaderInfo();
#ifdef __MMI_MMS_NOT_ALLOW_USER_DOWNLOAD_CORRUPTED_MMS_MSG__
    if(msg_info->msg_type == MMA_MSG_TYPE_NOTIFICATION)
    {
        switch (msg_info->notification_error_type)
        {
            case MMI_UMMS_STOP_CORRUPT_DWNLD:
            {
                VappMmsPopup popup(STR_ID_VAPP_MMS_NOTIFICATION_CORRUPT, VCP_POPUP_TYPE_FAILURE, findScreen(), NULL);           
                popup.displayPopup();
                return VFX_TRUE;
            }
            case MMI_UMMS_STOP_UNRECONIZED_NOTIFICATION:
            {
                VappMmsPopup popup(STR_ID_VAPP_MMS_NOTIFICATION_UNRECOGNIZED, VCP_POPUP_TYPE_FAILURE, findScreen(), NULL);           
                popup.displayPopup();
                return VFX_TRUE;
            }
        }
    }

#endif /* __MMI_MMS_NOT_ALLOW_USER_DOWNLOAD_CORRUPTED_MMS_MSG__ */ 
    VfxTextFrame *txt_subject;
    VFX_OBJ_CREATE(txt_subject, VfxTextFrame, this);
    txt_subject->setPos(VAPP_MMS_DETAILS_SUBJECT_LEFT_MARGIN, VAPP_MMS_DETAILS_SUBJECT_UPPER_MARGIN);
    txt_subject->setSize(getSize().width - VAPP_MMS_DETAILS_SUBJECT_LEFT_MARGIN - VAPP_MMS_DETAILS_BUTTON_RIGHT_MARGIN, VAPP_MMS_SUBJECT_FONT_SIZE);
    VfxWString str(STR_ID_VAPP_MMS_SUBJECT);
    VfxWString str2;
    str2.loadFromMem(msg_info->subject);
    str += str2;
    txt_subject->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    txt_subject->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    txt_subject->setAutoFontSize(VFX_FALSE); 
    txt_subject->setAutoResized(VFX_TRUE);
    txt_subject->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    txt_subject->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_MMS_SUBJECT_FONT_SIZE)));
    txt_subject->setString(str);
    txt_subject->setColor(VFX_COLOR_RES(VAPP_MMS_VIEWER_TEXT_COLOR));
    txt_subject->setAlignParent(VFX_FRAME_ALIGNER_SIDE_LEFT, VFX_FRAME_ALIGNER_MODE_SIDE);
    txt_subject->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, VFX_FRAME_ALIGNER_MODE_SIDE);
    txt_subject->forceUpdate();
    //VfxFontDesc font_des =  txt_subject->getFont();
    VfxTextFrame *txt_size;
    VfxWString str3;
    VfxWString str4;
    char str5[10];
    VfxWString str6;
    VfxU32 msg_size;
    VFX_OBJ_CREATE(txt_size, VfxTextFrame, this);
    txt_size->setPos(VAPP_MMS_DETAILS_SUBJECT_LEFT_MARGIN, VAPP_MMS_DETAILS_SUBJECT_UPPER_MARGIN + VAPP_MMS_SUBJECT_FONT_SIZE + VAPP_MMS_DETAILS_TEXT_MARGIN);
    txt_size->setSize(getSize().width - VAPP_MMS_DETAILS_SUBJECT_LEFT_MARGIN, VAPP_MMS_SIZE_FONT_SIZE);
    str3.loadFromRes(STR_ID_VAPP_MMS_SIZE);
    str3 += VFX_WSTR(" ");
    memset(str5,0,10);
    if(msg_info->msg_type == MMA_MSG_TYPE_NOTIFICATION)
    {
        msg_size = header_info->download_size;
    }
    else
    {
        msg_size = msg_info->msg_size;
    }

    if(msg_size >= 1024)
    {
        sprintf(str5,"%d",msg_size/1024);
    }
    else
    {
        sprintf(str5,"%d",msg_size);
    }
    str4.format("%s", str5);
    str3 += str4;
    if(msg_size >= 1024)
    {
        str6.loadFromRes(STR_ID_VAPP_MMS_KB);
    }
    else
    {
        str6.loadFromRes(STR_ID_VAPP_MMS_BYTES);
    }
    str3 += VFX_WSTR(" ");
    str3 += str6;
    txt_size->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    txt_size->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    txt_size->setAutoFontSize(VFX_FALSE); 
    txt_size->setAutoResized(VFX_TRUE); 
    txt_size->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_MMS_SIZE_FONT_SIZE)));
    txt_size->setString(str3);
    txt_size->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));
    txt_size->setAlignParent(VFX_FRAME_ALIGNER_SIDE_LEFT, VFX_FRAME_ALIGNER_MODE_SIDE);
    txt_size->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, VFX_FRAME_ALIGNER_MODE_SIDE);
    txt_size->forceUpdate();
    if(msg_info->msg_type == MMA_MSG_TYPE_NOTIFICATION)
    {
        if(!m_download)
        {
            VFX_OBJ_CREATE(m_download, VcpButton, this);
            m_download->setIsAutoResized(VFX_FALSE);
            m_download->setPos(getSize().width - VAPP_MMS_DETAILS_BUTTON_RIGHT_MARGIN - VAPP_MMS_DETAILS_BUTTON_WIDTH, VAPP_MMS_DETAILS_BUTTON_UPPER_MARGIN);
            m_download->setSize(VAPP_MMS_DETAILS_BUTTON_WIDTH, VAPP_MMS_DETAILS_BUTTON_HEIGHT);
            m_download->setTextFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_MMS_BUTTON_FONT_SIZE)));
            //m_download->setTextFont(font_des);
            m_download->setText(VFX_WSTR_RES(STR_GLOBAL_DOWNLOAD));
            m_download->setBgImageList(VcpStateImage(IMG_ID_VENUS_MMS_BG_N, IMG_ID_VENUS_MMS_BG_P, IMG_ID_VENUS_MMS_BG_D, 0));
            m_download->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
            //m_download->setTextColor( VFX_COLOR_BLACK, VfxColor(128, 0, 0, 0), VfxColor(128, 0, 0, 0), VFX_COLOR_BLACK);
            //m_download->setTextColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_BAR));
            //m_download->setAlignParent(VFX_FRAME_ALIGNER_SIDE_LEFT, VFX_FRAME_ALIGNER_MODE_SIDE);
            m_download->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, VFX_FRAME_ALIGNER_MODE_SIDE);
            if(/*!(srv_sim_ctrl_is_inserted(sim_id))*/!srv_sim_ctrl_is_available(sim_id) || (SRV_MODE_SWITCH_OFF == srv_mode_switch_get_network_mode(sim_id)))
            {
                m_download->setIsDisabled(VFX_TRUE);
            }
            if(srv_mms_bgsr_get_msg_status(m_msg_id) == SRV_MMS_BGSR_STATUS_DOWNLOADING)
            {
                VappMmsViewerPage* details_page = (VappMmsViewerPage *)VappMmsViewerPage::getMyPage();
                VappMmsToolBar  * t_bar =(VappMmsToolBar  *)details_page->getToolBar(VFX_PAGE_BAR_LOCATION_BOTTOM) ;
                if(t_bar)
                {
                    t_bar->updatToolbar();
                }
                m_download->setIsDisabled(VFX_TRUE);
                if(!m_indicator)
                {
                    VFX_OBJ_CREATE(m_indicator, VcpActivityIndicator, this);
                    m_indicator->setPos(VfxPoint(m_download->getPos().x - VAPP_MMS_BUTTON_STATUS_ICON_MARGIN - VAPP_MMS_STATUS_ICON_SIZE, VAPP_MMS_DETAILS_STATUS_ICON_UPPER_MARGIN));
                    m_indicator->setSize(VAPP_MMS_STATUS_ICON_SIZE,VAPP_MMS_STATUS_ICON_SIZE);
                    //m_indicator->setAlignParent(VFX_FRAME_ALIGNER_SIDE_LEFT, VFX_FRAME_ALIGNER_MODE_SIDE);
                    m_indicator->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, VFX_FRAME_ALIGNER_MODE_SIDE);
                    m_indicator->start();
                }
            } 
            m_download->m_signalClicked.connect(this, &VappMmsDetailsViewer::onClickDownload);
        }
    }

    if(msg_info->msg_type == MMA_MSG_TYPE_JAVA)
    {
        VfxTextFrame *txt_info;
        VFX_OBJ_CREATE(txt_info, VfxTextFrame, this);
        txt_info->setPos(VAPP_MMS_DETAILS_SUBJECT_LEFT_MARGIN, VAPP_MMS_DETAILS_SUBJECT_UPPER_MARGIN + VAPP_MMS_SUBJECT_FONT_SIZE + VAPP_MMS_DETAILS_TEXT_MARGIN + VAPP_MMS_SIZE_FONT_SIZE + VAPP_MMS_DETAILS_TEXT_MARGIN);
        txt_info->setSize(getSize().width - VAPP_MMS_DETAILS_SUBJECT_LEFT_MARGIN, VAPP_MMS_SUBJECT_FONT_SIZE);
        VfxWString str;
        str.loadFromRes(STR_ID_VAPP_MMS_READ_ONLY_BY_JAVA);
        txt_info->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        txt_info->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
        txt_info->setAutoFontSize(VFX_FALSE); 
        txt_info->setAutoResized(VFX_TRUE); 
        txt_info->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_MMS_SUBJECT_FONT_SIZE)));
        txt_info->setString(str);
        txt_info->setColor(VFX_COLOR_RES(VAPP_MMS_VIEWER_TEXT_COLOR));
        txt_info->forceUpdate();
    }
    VfxTextFrame *recv_date;
    VfxWString str7;
    VFX_OBJ_CREATE(recv_date, VfxTextFrame, this);
    recv_date->setPos(0, VAPP_MMS_DETAILS_BUTTON_UPPER_MARGIN + VAPP_MMS_BUTTON_DATE_MARGIN + VAPP_MMS_DETAILS_BUTTON_HEIGHT);
    recv_date->setSize(getSize().width - VAPP_MMS_DATE_RIGHT_MARGIN, VAPP_MMS_SIZE_FONT_SIZE);
    recv_date->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_MMS_SIZE_FONT_SIZE)));
    recv_date->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    recv_date->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
    recv_date->setAutoFontSize(VFX_FALSE); 
    recv_date->setAutoResized(VFX_TRUE);
    recv_date->setAlignParent(VFX_FRAME_ALIGNER_SIDE_LEFT, VFX_FRAME_ALIGNER_MODE_SIDE);
    recv_date->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, VFX_FRAME_ALIGNER_MODE_SIDE);
    VfxU32 localSec = 0;
    applib_time_struct dateTime;
    VfxU32 flags;
    memset(&dateTime, 0, sizeof(applib_time_struct));
    localSec = applib_dt_sec_utc_to_local(msg_info->receive_date);
    mmi_dt_utc_sec_2_mytime(localSec, &dateTime, MMI_FALSE);
    VfxDateTime time;
    time.setDateTime(&dateTime);
    VfxWChar buf[80];
    memset(buf, 0, sizeof(VfxWChar)*80);
    //if (isToday(m_event[idx]->time))
    {
    flags = VFX_DATE_TIME_DATE_YEAR            |
    VFX_DATE_TIME_DATE_MONTH           |
    VFX_DATE_TIME_DATE_DAY             |
    VFX_DATE_TIME_TIME_HOUR            |
    VFX_DATE_TIME_TIME_MINUTE         /* |
        VFX_DATE_TIME_TIME_SECOND */;         
        }
        /* else
        {
        flags = VFX_DATE_TIME_DATE_MASK;
        }*/

    time.getDateTimeString(flags, (VfxWChar *)buf, sizeof(buf));
    str7 = VFX_WSTR_MEM(buf);
    recv_date->setString(str7);
    recv_date->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));
    recv_date->forceUpdate();
    return VFX_TRUE;
}
void VappMmsDetailsViewer::onClickDownload(VfxObject *obj, VfxId id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxU32 current_secs_since_1970 = 0;
    //VfxU32 size_available = 0;
    //VfxU32 used_bytes = 0;
    //VfxU32 phone_size_available = 0;
    //VfxU32 card_size_available = 0;
    // VfxU8 prefer_storage = 0;
    //VfxU32 time = 0;
    //VfxBool result = 0;
    srv_mms_download_req_struct req;
    mmi_umms_app_dtmgr_msg_info_data_struct * msg_info = m_data->getMsgInfo();
    mmi_umms_app_dtmgr_xml_header_info_struct *header_info = m_data->getHeaderInfo();
    mmi_sim_enum  sim_id = vapp_mms_convert_mma_sim_to_mmi_sim(msg_info->msg_sim_info);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__

    VfxU8 check_storage = SRV_MMS_CARD_MEMORY_OK;
    if(header_info)
    {
        check_storage = srv_mms_check_memory_usage(header_info->download_size);
    }
    if(check_storage == SRV_MMS_CARD_NOT_PRESENT_USE_PHONE)
    {
        mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_MMS_INFO,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_INFO,
        (WCHAR*)GetString(STR_ID_VAPP_MMS_SAVE_TO_PHONE));
        srv_mms_set_prefered_storage(E_PREFER_STORAGE_MODE_PHONE,0);
    }
    else if(check_storage == SRV_MMS_CARD_PHONE_FULL_USE_CARD_MEM)
    {
        mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_MMS_INFO,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_INFO,
        (WCHAR*)GetString(STR_ID_VAPP_MMS_SAVE_TO_MEMORY_CARD));
        srv_mms_set_prefered_storage(E_PREFER_STORAGE_MODE_CARD,0);
    }
    else if(check_storage == SRV_MMS_CARD_FULL_USE_PHONE_MEM)
    {
        mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_MMS_INFO,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_INFO,
        (WCHAR*)GetString(STR_ID_VAPP_MMS_SAVE_TO_PHONE));
        srv_mms_set_prefered_storage(E_PREFER_STORAGE_MODE_PHONE,0);
    }
    else if(check_storage == SRV_MMS_CARD_NOT_ENOUGH_MEMORY)
    {
        mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_MMS_INFO,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_INFO,
        (WCHAR*)GetString(STR_ID_VAPP_MMS_MEMORY_CARD_PHONE_BOTH_FULL));
        return ;
    }
#endif/*__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__*/

    if(srv_sim_ctrl_chv1_is_blocked(sim_id))
    {
        mmi_frm_nmgr_balloon(
                                MMI_SCENARIO_ID_MMS_INFO,
                                MMI_EVENT_INFO_BALLOON,
                                MMI_NMGR_BALLOON_TYPE_INFO,
                                (WCHAR*)GetString(STR_GLOBAL_UNAVAILABLE_SIM));
        return;
    }
    if(!srv_mode_switch_is_network_service_available())
    {
        mmi_frm_nmgr_balloon(
                                MMI_SCENARIO_ID_MMS_INFO,
                                MMI_EVENT_INFO_BALLOON,
                                MMI_NMGR_BALLOON_TYPE_INFO,
                                (WCHAR*)GetString(STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE));
        return;
    }

    current_secs_since_1970 = srv_mms_get_current_utc_time();
    if (current_secs_since_1970 > msg_info->expiry_time)
    {
        mmi_frm_nmgr_balloon(
                            MMI_SCENARIO_ID_MMS_INFO,
                            MMI_EVENT_INFO_BALLOON,
                            MMI_NMGR_BALLOON_TYPE_FAILURE,
                            (WCHAR*)GetString(STR_ID_VAPP_MMS_NOTIFICATION_EXPIRED));
        return;
    }

    /*time = (msg_info->expiry_time - msg_info->receive_date) - (current_secs_since_1970 -
                                                   msg_info->receive_date);*/ 
    memset(&req, 0, sizeof(srv_mms_download_req_struct));

    req.sim_id = msg_info->msg_sim_info;
    req.msg_id = m_msg_id;
    req.storage_type = msg_info->storage_location;
#ifdef __MMI_MMS_ITERATOR_VIEWER__
    //ret_val = mmi_umms_app_core_prepare_data_before_deinit(&other_msg_data, &folder_id, &um_data);
#endif
       
    srv_mms_download(&req);
    if(srv_mms_bgsr_get_msg_status(m_msg_id) == SRV_MMS_BGSR_STATUS_DOWNLOADING)
    {
        srv_mms_bgsr_popup_data  popup_data;
        VappMmsViewerPage* details_page = (VappMmsViewerPage* )VappMmsViewerPage::getMyPage();
        VappMmsToolBar  * t_bar =(VappMmsToolBar  *)details_page->getToolBar(VFX_PAGE_BAR_LOCATION_BOTTOM) ;
        if(t_bar)
        {
            t_bar->updatToolbar();
        }
        m_download->setIsDisabled(VFX_TRUE);
        if(!m_indicator)
        {
            VFX_OBJ_CREATE(m_indicator, VcpActivityIndicator, this);
            m_indicator->setPos(m_download->getPos().x - VAPP_MMS_BUTTON_STATUS_ICON_MARGIN - VAPP_MMS_STATUS_ICON_SIZE, VAPP_MMS_DETAILS_STATUS_ICON_UPPER_MARGIN);
            m_indicator->setSize(VAPP_MMS_STATUS_ICON_SIZE,VAPP_MMS_STATUS_ICON_SIZE);
            // m_indicator->setAlignParent(VFX_FRAME_ALIGNER_SIDE_LEFT, VFX_FRAME_ALIGNER_MODE_SIDE);
            m_indicator->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, VFX_FRAME_ALIGNER_MODE_SIDE);
            m_indicator->start();
        }
        /*Updating Lite Viewer*/
        memset(&popup_data,0, sizeof(srv_mms_bgsr_popup_data));
        popup_data.rsp_type = SRV_MMS_BGSR_RSP_TYPE_NONE;
        popup_data.msg_id = m_msg_id;
        popup_data.result = 0;
        srv_mms_send_events_ex(EVT_ID_SRV_SHOW_BGSR_POPUP, (void *)(&popup_data));
    }
#ifdef __MMI_MMS_ROAMING_NO_ACCEPT_SUPPORT__
    srv_mms_delete_single_msg_from_notify_list(m_msg_id);
#endif/*__MMI_MMS_ROAMING_NO_ACCEPT_SUPPORT__*/ 
}
mmi_ret VappMmsDetailsViewer::listener(mmi_event_struct* evt)
{
    srv_mms_base_event_struct* param =  (srv_mms_base_event_struct*) evt;
    VappMmsDetailsViewer* details_viewer =  (VappMmsDetailsViewer*)VfxObject::handleToObject((param->user_data));
    srv_mms_bgsr_popup_data * sender_data =  (srv_mms_bgsr_popup_data*)  param->sender_data;
    if(details_viewer &&  details_viewer->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsDetailsViewer)))
    {
        switch (param->evt_id)
        {
            case EVT_ID_SRV_SHOW_BGSR_POPUP:
                if((details_viewer->m_msg_id == sender_data->msg_id) && (SRV_MMS_BGSR_RSP_TYPE_NONE != sender_data->rsp_type))
                {
                    VappMmsViewerPage* details_page = (VappMmsViewerPage *)VappMmsViewerPage::getMyPage();
                    VappMmsToolBar  * t_bar =(VappMmsToolBar  *)details_page->getToolBar(VFX_PAGE_BAR_LOCATION_BOTTOM) ;
                    t_bar->updatToolbar();
                    details_viewer->m_download->setIsDisabled(VFX_FALSE);
                    if(sender_data->new_msg_id)
                    {
                        if(((VappMmsViewerPage *)VappMmsViewerPage::getMyPage())->isActive())
                        {
                            //VappMmsViewerPage* view_page;
                            //VFX_OBJ_CREATE_EX(view_page, VappMmsViewerPage, details_viewer->findScreen(),(MODE_STOP, sender_data->new_msg_id));
                            details_page->getMyData()->setBasicProp(sender_data->new_msg_id);
                            if(details_viewer->m_indicator)
                            {
                                details_viewer->m_indicator->stop();
                                VFX_OBJ_CLOSE(details_viewer->m_indicator);
                                details_viewer->m_indicator = NULL;
                            }
                            //details_page->getMainScr()->popPage();
                            //view_page->getMainScr()->pushPage(0,view_page);
                            VcpPagePanel *panel  = (VcpPagePanel *)details_viewer->getParent();
                            panel->switchTo(
                                            panel->getFirstChildFrame(),
                                            VCP_PAGE_EFFECT_FADE_IN,
                                            0,
                                            VCP_PAGE_DIRECTION_FROM_LEFT,
                                            VFX_TRUE);
                        }
                        else
                        {
                            if(details_viewer->m_indicator)
                            {
                                details_viewer->m_indicator->stop();
                                VFX_OBJ_CLOSE(details_viewer->m_indicator);
                                details_viewer->m_indicator = NULL;
                            }
                            details_page->getMainScr()->popPage();
                        }
                        return MMI_RET_OK;
                    }
                    if(details_viewer->m_indicator)
                    {
                        details_viewer->m_indicator->stop();
                        VFX_OBJ_CLOSE(details_viewer->m_indicator);
                        details_viewer->m_indicator = NULL;
                    }
                }
            break;
        }
    }
    return MMI_RET_OK;
}
void VappMmsDetailsViewer::setBounds(const VfxRect &value)
{
    VfxControl::setBounds(value);
}

#endif  /* __MMI_MMS_2__  */
