/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_callset_vt.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Video related frame
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"

extern "C" 
{

#include "GlobalResDef.h"
#include "CallSetSrvGprot.h"
#include "NotificationGprot.h"

#include "FileMgrGProt.h" /* SRV_FMGR_PATH_MAX_LEN */
#ifdef __MMI_USB_SUPPORT__
#include "UsbSrvGprot.h" /* srv_usb_is_in_mass_storage_mode */
#endif
#include "ShutdownSrvGprot.h" /* srv_shutdown_is_running */
#include "gdi_include.h" /* gdi_image_get_dimension_file */
}

#include "Mmi_rp_file_type_def.h" /* FMGR_FILTER */
#include "mmi_rp_srv_status_icons_def.h"
#include "Mmi_rp_srv_venus_component_tool_bar_def.h"
#include "Mmi_rp_vapp_callset_def.h"
#include "mmi_rp_app_cosmos_global_def.h"

#include "vcp_form.h"
#include "vcp_slider.h"
#include "vcp_segment_button.h"

#include "Vcui_phb_gprot.h"
#include "Vcui_secset_gprot.h"

#include "vapp_fmgr_cui_gprot.h"

#include "vapp_ucm_video_frame.h"
#include "Vapp_usb_gprot.h" /* vapp_usb_unavailable_popup */
#include "Vapp_ucm_res_def.h"

#include "vapp_callset.h"
#include "vapp_callset_vt.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
	/* layout definition */
#define VAPP_CALLSET_VT_VFRAME_W VAPP_UCM_RES_VT_PREVIEW_W
#define VAPP_CALLSET_VT_VFRAME_H VAPP_UCM_RES_VT_PREVIEW_H
	
#ifdef __MMI_MAINLCD_320X480__
#define VAPP_CALLSET_VT_SEGMENT_BUTTON_CELL_H 50
#define VAPP_CALLSET_VT_SLIDER_CELL_H 40
#define VAPP_CALLSET_VT_SLIDER_ICON_W 40
#define VAPP_CALLSET_VT_SLIDER_ICON_H 20
#define VAPP_CALLSET_VT_EV_FONT 25
	
#elif defined(__MMI_MAINLCD_480X800__)
#define VAPP_CALLSET_VT_SEGMENT_BUTTON_CELL_H 83
#define VAPP_CALLSET_VT_SLIDER_CELL_H 66
#define VAPP_CALLSET_VT_SLIDER_ICON_W 40
#define VAPP_CALLSET_VT_SLIDER_ICON_H 40
#define VAPP_CALLSET_VT_EV_FONT 25
	
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
#define VAPP_CALLSET_VT_SEGMENT_BUTTON_CELL_H 45
#define VAPP_CALLSET_VT_SLIDER_CELL_H 35
#define VAPP_CALLSET_VT_SLIDER_ICON_W 18
#define VAPP_CALLSET_VT_SLIDER_ICON_H 18
#define VAPP_CALLSET_VT_EV_FONT 10
	
#else /* __MMI_MAINLCD_320X480__ */
#define VAPP_CALLSET_VT_SEGMENT_BUTTON_CELL_H 50
#define VAPP_CALLSET_VT_SLIDER_CELL_H 40
#define VAPP_CALLSET_VT_SLIDER_ICON_W 15
#define VAPP_CALLSET_VT_SLIDER_ICON_H 15
#define VAPP_CALLSET_VT_EV_FONT 25
	
#endif /* __MMI_MAINLCD_320X480__ */
	
#pragma arm section code = "DYNAMIC_CODE_CALLSET_ROCODE", rodata = "DYNAMIC_CODE_CALLSET_RODATA" 
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
void VappCallSetPageVt::onInit()
{
    VfxPage::onInit(); // call base class

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT));
    setTopBar(bar);

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);

    VcpFormItemLauncherCell *launch;

    VFX_OBJ_CREATE(launch, VcpFormItemLauncherCell, m_form);
    launch->setMainText(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT_PREVIEW));
    launch->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    launch->m_signalTap.connect(this, &VappCallSetPageVt::onItemTap);
    m_form->addItem(launch, ID_FORM_LAUNCH_VT_PREVIEW);

    VFX_OBJ_CREATE(launch, VcpFormItemLauncherCell, m_form);
    launch->setMainText(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT_DIAL_MODE));
    launch->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    launch->m_signalTap.connect(this, &VappCallSetPageVt::onItemTap);
    m_form->addItem(launch, ID_FORM_LAUNCH_VT_DIAL_MODE);

    VFX_OBJ_CREATE(launch, VcpFormItemLauncherCell, m_form);
    launch->setMainText(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT_ANS_MODE));
    launch->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    launch->m_signalTap.connect(this, &VappCallSetPageVt::onItemTap);
    m_form->addItem(launch, ID_FORM_LAUNCH_VT_ANS_MODE);

    VcpFormItemSwitchCell *swh;
    VFX_OBJ_CREATE(swh, VcpFormItemSwitchCell, m_form);
    swh->setMainText(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT_OPEN_MIC));
    swh->m_signalSwitchChangeReq.connect(this, &VappCallSetPageVt::onSwitch);
    m_form->addItem(swh, ID_FORM_SWITCH_VT_OPEN_MIC);

    VFX_OBJ_CREATE(swh, VcpFormItemSwitchCell, m_form);
    swh->setMainText(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT_OPEN_SPEAKER));
    swh->m_signalSwitchChangeReq.connect(this, &VappCallSetPageVt::onSwitch);
    m_form->addItem(swh, ID_FORM_SWITCH_VT_OPEN_SPEAKER);

    updateForm();
}

void VappCallSetPageVt::onEnter(VfxBool isBackward)
{
    if (isBackward)
    {
        updateForm();
    }
}

void VappCallSetPageVt::updateForm()
{
    VcpFormItemLauncherCell *launch;

	// update dial mode
    launch = (VcpFormItemLauncherCell *)m_form->getItem(ID_FORM_LAUNCH_VT_DIAL_MODE);
    switch (srv_callset_vt_get_dial_mode())
    {
        case SRV_CALLSET_VT_DIAL_MODE_START_CAMERA:
            launch->setHintText(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT_START_CAM));
            break;

        case SRV_CALLSET_VT_DIAL_MODE_STOP_CAMERA:
            launch->setHintText(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT_STOP_CAM));
            break;
    }

	// update answer mode
    launch = (VcpFormItemLauncherCell *)m_form->getItem(ID_FORM_LAUNCH_VT_ANS_MODE);
    switch (srv_callset_vt_get_answer_mode())
    {
        case SRV_CALLSET_VT_ANSWER_MODE_START_CAMERA:
            launch->setHintText(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT_START_CAM));
            break;

        case SRV_CALLSET_VT_ANSWER_MODE_STOP_CAMERA:
            launch->setHintText(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT_STOP_CAM));
            break;

        case SRV_CALLSET_VT_ANSWER_MODE_PROMPT:
            launch->setHintText(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT_PROMPT));
            break;
    }


    VcpFormItemSwitchCell *swh;
	swh = (VcpFormItemSwitchCell *)m_form->getItem(ID_FORM_SWITCH_VT_OPEN_MIC);
    swh->setSwitchStatus(srv_callset_vt_get_mic_mode() ? VFX_TRUE : VFX_FALSE);

	swh = (VcpFormItemSwitchCell *)m_form->getItem(ID_FORM_SWITCH_VT_OPEN_SPEAKER);
    swh->setSwitchStatus(srv_callset_vt_get_speaker_mode() ? VFX_TRUE : VFX_FALSE);

}

void VappCallSetPageVt::onItemTap(VcpFormItemCell *item, VfxId id)
{
    switch (id)
    {
        case ID_FORM_LAUNCH_VT_PREVIEW:
            if (srv_ucm_query_call_count((srv_ucm_call_state_enum)SRV_UCM_CALL_STATE_ALL, 
                    SRV_UCM_VIDEO_CALL_TYPE, NULL))
            {
                VAPP_CALLSET_FAIL_POPUP(this, VFX_WSTR_RES(STR_GLOBAL_NOT_AVAILABLE_DURING_VIDEO_CALL));
                return;
            }
            VappCallSetPageVtPreview *pageVtPreview;
            VFX_OBJ_CREATE(pageVtPreview, VappCallSetPageVtPreview, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, pageVtPreview);
            break;

        case ID_FORM_LAUNCH_VT_DIAL_MODE:
            VappCallSetPageVtDialMode *pageVtDialMode;
            VFX_OBJ_CREATE(pageVtDialMode, VappCallSetPageVtDialMode, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, pageVtDialMode);
            break;

        case ID_FORM_LAUNCH_VT_ANS_MODE:
            VappCallSetPageVtAnsMode *pageVtAnsMode;
            VFX_OBJ_CREATE(pageVtAnsMode, VappCallSetPageVtAnsMode, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, pageVtAnsMode);
            break;
    }
}

void VappCallSetPageVt::onSwitch(VcpFormItemSwitchCell* item, VfxId id, VfxBool state)
{
    srv_callset_result_enum result;
    switch (id)
    {
        case ID_FORM_SWITCH_VT_OPEN_MIC:
            result = srv_callset_vt_set_mic_mode((MMI_BOOL)state);
            if (result != SRV_CALLSET_RESULT_OK)
            {
                VAPP_CALLSET_FAIL_POPUP(this, 
                    VFX_WSTR_RES(srv_callset_get_result_string_id(result)));
                item->setSwitchStatus(!state);
            }
            else
            {
                item->setSwitchStatus(state);
            }
            break;

        case ID_FORM_SWITCH_VT_OPEN_SPEAKER:
            result = srv_callset_vt_set_speaker_mode((MMI_BOOL)state);
            if (result != SRV_CALLSET_RESULT_OK)
            {
                VAPP_CALLSET_FAIL_POPUP(this, 
                    VFX_WSTR_RES(srv_callset_get_result_string_id(result)));
                item->setSwitchStatus(!state);
            }
            else
            {
                item->setSwitchStatus(state);
            }
            break;
			
		default:
			break;
    }
}


const VfxResId VappCallSetPageVtPreview::s_evStrId[VAPP_VT_VIDEOFRAME_EV_TOTAL] = 
{
	STR_ID_VAPP_CALLSET_EV_N4,
	STR_ID_VAPP_CALLSET_EV_N3,
	STR_ID_VAPP_CALLSET_EV_N2,
	STR_ID_VAPP_CALLSET_EV_N1,
	STR_ID_VAPP_CALLSET_EV_0,
	STR_ID_VAPP_CALLSET_EV_P1,
	STR_ID_VAPP_CALLSET_EV_P2,
	STR_ID_VAPP_CALLSET_EV_P3,
	STR_ID_VAPP_CALLSET_EV_P4
};

const srv_callset_vt_ev_enum VappCallSetPageVtPreview::s_evSrvVal[VAPP_VT_VIDEOFRAME_EV_TOTAL] = 
{
	SRV_CALLSET_VT_EV_N4,
	SRV_CALLSET_VT_EV_N3,
	SRV_CALLSET_VT_EV_N2,
	SRV_CALLSET_VT_EV_N1,
    SRV_CALLSET_VT_EV_0,
    SRV_CALLSET_VT_EV_P1,
    SRV_CALLSET_VT_EV_P2,
    SRV_CALLSET_VT_EV_P3,
    SRV_CALLSET_VT_EV_P4
};

VappCallSetPageVtPreview::VappCallSetPageVtPreview() : m_previewOnly(VFX_FALSE), m_status(NULL)
{
}

VappCallSetPageVtPreview::VappCallSetPageVtPreview(VfxBool previewOnly, VappCallSetVtStatusStruct *status) : 
    m_previewOnly(previewOnly), m_status(status)
{
}

void VappCallSetPageVtPreview::onInit()
{
    VfxPage::onInit(); // call base class

    mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, &VappCallSetPageVtPreview::onEvtHdlr, getObjHandle());


    m_needUpdateValue = VFX_FALSE;
    m_ready = VFX_FALSE;
    m_fmgr = GRP_ID_INVALID;
    m_waitForClose = VFX_FALSE;
    m_waitForCloseFmgr = VFX_FALSE;
    m_formAniTimer = NULL;
    m_isBg = VFX_FALSE;
	m_isSwitched = VFX_FALSE;
	
    if (m_status)
    {
        m_vFrame = m_status->videoFrame;

        if (m_vFrame)
        {
            this->addChildFrame(m_vFrame);
            //this->addChild(m_vFrame);
            //m_vFrame->setAnchor(0, 0);
            m_vFrame->setPos(LCD_WIDTH + 100, LCD_HEIGHT + 100);
        }
    }
    else
    {
        m_vFrame = NULL;
    }

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT_PREVIEW));
    setTopBar(bar);

    VcpForm *form;
    VFX_OBJ_CREATE(form, VcpForm, this);
    form->setSize(getSize());
    form->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);

    VcpFormItemCustomFrame *cust;

    /* segment button cell */
    VFX_OBJ_CREATE(cust, VcpFormItemCustomFrame, form);

    VfxFrame *frame;
    if (m_previewOnly)
    {
        m_segBtn = NULL;
    }
    else
    {
        VFX_OBJ_CREATE(frame, VfxFrame, cust);
        frame->setSize(LCD_WIDTH, VAPP_CALLSET_VT_SEGMENT_BUTTON_CELL_H);

        VFX_OBJ_CREATE(m_segBtn, VcpSegmentButton, frame);
        m_segBtn->setAnchor(0.5f, 0.5f);
        m_segBtn->setPos(LCD_WIDTH / 2, VAPP_CALLSET_VT_SEGMENT_BUTTON_CELL_H / 2);
        m_segBtn->setSize(LCD_WIDTH - 10, VAPP_CALLSET_VT_SEGMENT_BUTTON_CELL_H - 10);
        m_segBtn->setType(VCP_SEGMENT_BUTTON_TYPE_RADIO);
        m_segBtn->setStyle(VCP_SEGMENT_BUTTON_STYLE_TEXT_ONLY);
        m_segBtn->addButton(1, VcpStateImage(IMG_GLOBAL_EMPTY), VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT_CAM_FRONT));
        m_segBtn->addButton(2, VcpStateImage(IMG_GLOBAL_EMPTY), VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT_CAM_REAR));
        m_segBtn->addButton(3, VcpStateImage(IMG_GLOBAL_EMPTY), VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT_CAM_OFF));
        m_segBtn->m_signalButtonClicked.connect(this, &VappCallSetPageVtPreview::onSegBtnClicked);

        switch (getCamMode())
        {
            case SRV_CALLSET_VT_CAMERA_FRONT:
                m_segBtn->setButtonIsHighlighted(1, VFX_TRUE);
                break;

            case SRV_CALLSET_VT_CAMERA_BACK:
                m_segBtn->setButtonIsHighlighted(2, VFX_TRUE);
                break;

            case SRV_CALLSET_VT_CAMERA_OFF:
                m_segBtn->setButtonIsHighlighted(3, VFX_TRUE);
                break;
        }
        
        cust->attachCustomFrame(frame);
        form->addItem(cust);
        form->insertSeparator();
    }


    /* video frame cell */
    VFX_OBJ_CREATE(cust, VcpFormItemCustomFrame, form);

    VFX_OBJ_CREATE(m_vFrameCell, VfxFrame, cust);
    m_vFrameCell->setSize(LCD_WIDTH, VAPP_CALLSET_VT_VFRAME_H + 10);

    VFX_OBJ_CREATE(frame, VfxFrame, m_vFrameCell);/* fake video frame */
    frame->setSize(VAPP_CALLSET_VT_VFRAME_W, VAPP_CALLSET_VT_VFRAME_H);
#ifndef __MDP_VT_PREVIEW_UPSCALE_SUPPORT__
    if (VAPP_CALLSET_VT_VFRAME_W > 176 || VAPP_CALLSET_VT_VFRAME_H > 144)
    {
        m_vFrameCell->setSize(LCD_WIDTH, 144 + 10);
        frame->setSize(176, 144);
    }
#endif

    frame->setBgColor(VFX_COLOR_BLACK);
    frame->setAnchor(0.5f, 0.5f);
    frame->setPos(m_vFrameCell->getSize().width / 2, m_vFrameCell->getSize().height / 2 + 2);

    cust->attachCustomFrame(m_vFrameCell);
	cust->setHeight(m_vFrameCell->getSize().height + 4);
    form->addItem(cust);

    form->insertSeparator(cust);


    /* zoom slider cell */
    VFX_OBJ_CREATE(m_zoom, VcpFormItemCustomFrame, form);

    VFX_OBJ_CREATE(frame, VfxFrame, m_zoom);
    frame->setSize(LCD_WIDTH, VAPP_CALLSET_VT_SLIDER_CELL_H);

    VfxImageFrame *img;
    VFX_OBJ_CREATE(img, VfxImageFrame, frame);
    img->setAnchor(0.5f, 0.5f);
    img->setPos(VAPP_CALLSET_VT_SLIDER_ICON_W, VAPP_CALLSET_VT_SLIDER_CELL_H / 2);
    img->setSize(VAPP_CALLSET_VT_SLIDER_ICON_W, VAPP_CALLSET_VT_SLIDER_ICON_H);
    img->setResId(IMG_ID_CALLSET_VT_ZOOMOUT);
    img->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    VFX_OBJ_CREATE(m_sliZoom, VcpSlider, frame);
    m_sliZoom->setAnchor(0.5f, 0.5f);
    m_sliZoom->setPos(LCD_WIDTH / 2, VAPP_CALLSET_VT_SLIDER_CELL_H / 2);
    m_sliZoom->setLayout(VCP_SLIDER_LAYOUT_HORZ);
    m_sliZoom->setLength(LCD_WIDTH - VAPP_CALLSET_VT_SLIDER_ICON_W * 4);

    VFX_OBJ_CREATE(img, VfxImageFrame, frame);
    img->setAnchor(0.5f, 0.5f);
    img->setPos(LCD_WIDTH - VAPP_CALLSET_VT_SLIDER_ICON_W, VAPP_CALLSET_VT_SLIDER_CELL_H / 2);
    img->setSize(VAPP_CALLSET_VT_SLIDER_ICON_W, VAPP_CALLSET_VT_SLIDER_ICON_H);
    img->setResId(IMG_ID_CALLSET_VT_ZOOMIN);
    img->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    m_zoom->attachCustomFrame(frame);
    m_zoom->setIsHidden(
        (getCamMode() == SRV_CALLSET_VT_CAMERA_OFF) ?
        VFX_TRUE : VFX_FALSE);
    form->addItem(m_zoom);


    form->insertSeparator();


    /* ev slider cell */
    VFX_OBJ_CREATE(m_ev, VcpFormItemCustomFrame, form);

    VFX_OBJ_CREATE(frame, VfxFrame, m_ev);
    frame->setSize(LCD_WIDTH, VAPP_CALLSET_VT_SLIDER_CELL_H);

    VFX_OBJ_CREATE(img, VfxImageFrame, frame);
    img->setAnchor(0.5f, 0.5f);
    img->setPos(VAPP_CALLSET_VT_SLIDER_ICON_W, VAPP_CALLSET_VT_SLIDER_CELL_H / 2);
    img->setSize(VAPP_CALLSET_VT_SLIDER_ICON_W, VAPP_CALLSET_VT_SLIDER_ICON_H);
    img->setResId(IMG_ID_CALLSET_VT_EV);
    img->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    VFX_OBJ_CREATE(m_sliEv, VcpSlider, frame);
    m_sliEv->setAnchor(0.5f, 0.5f);
    m_sliEv->setPos(LCD_WIDTH / 2, VAPP_CALLSET_VT_SLIDER_CELL_H / 2);
    m_sliEv->setLayout(VCP_SLIDER_LAYOUT_HORZ);
    m_sliEv->setLength(LCD_WIDTH - VAPP_CALLSET_VT_SLIDER_ICON_W * 4);

    VFX_OBJ_CREATE(m_evText, VfxTextFrame, frame);
    m_evText->setAnchor(0.5f, 0.5f);
    m_evText->setPos(LCD_WIDTH - VAPP_CALLSET_VT_SLIDER_ICON_W, VAPP_CALLSET_VT_SLIDER_CELL_H / 2);
    m_evText->setSize(VAPP_CALLSET_VT_SLIDER_ICON_W * 2, VAPP_CALLSET_VT_SLIDER_ICON_H);
    m_evText->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    m_evText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_CALLSET_VT_EV_FONT), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
    m_evText->setString(VFX_WSTR("0 EV"));
    m_evText->setAutoFontSize(VFX_FALSE);

    m_evText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);

    m_ev->attachCustomFrame(frame);
    m_ev->setIsHidden(
        (getCamMode() == SRV_CALLSET_VT_CAMERA_OFF) ?
        VFX_TRUE : VFX_FALSE);
    form->addItem(m_ev);


    form->insertSeparator();


    /* night mode switch cell */
    VFX_OBJ_CREATE(m_niMode, VcpFormItemSwitchCell, form);
    m_niMode->setMainText(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT_NIGHT_MODE));
    m_niMode->setIsHidden(
        (getCamMode() == SRV_CALLSET_VT_CAMERA_OFF) ?
        VFX_TRUE : VFX_FALSE);
    form->addItem(m_niMode, 2);
	m_niMode->setSwitchStatus(getNightMode());
    m_niMode->m_signalSwitchChangeReq.connect(this, &VappCallSetPageVtPreview::onSwitch);
	m_niMode->m_signalToggleAnimationDone.connect(this, &VappCallSetPageVtPreview::onAniDone);
	
	
    /* Select picture cell */
    VFX_OBJ_CREATE(m_selPic, VcpFormItemLauncherCell, form);
    m_selPic->setMainText(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT_SEL_PIC));
    m_selPic->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_selPic->m_signalTap.connect(this, &VappCallSetPageVtPreview::onItemTap);
    m_selPic->setIsHidden(
        (getCamMode() != SRV_CALLSET_VT_CAMERA_OFF) ?
        VFX_TRUE : VFX_FALSE);
    form->addItem(m_selPic, 1);

}

void VappCallSetPageVtPreview::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, &VappCallSetPageVtPreview::onEvtHdlr, getObjHandle());

    if (m_status && m_status->videoFrame)
    {
        /* onExit isn't called when UCM app is not active */
        vFramePause();
        m_signalVFrameMastershipReturn.emit(this, m_status);
        /* pause before return the mastership */
    }

    VfxPage::onDeinit();
}

void VappCallSetPageVtPreview::onEntered(void)
{
    VfxPage::onEntered();

    if (getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

    if (!m_vFrame || (m_vFrame->getParentFrame() != m_vFrameCell))
    {
        /* don't update vFrame until VcpForm animation finishes (to achieve smooth animation) */
        VFX_OBJ_CREATE(m_formAniTimer, VfxTimer, this);
        m_formAniTimer->setStartDelay(250);
        m_formAniTimer->m_signalTick.connect(this, &VappCallSetPageVtPreview::startUpdateLocalView);
        m_formAniTimer->start();

        disableAllOp(VFX_TRUE);
    }
    else
    {
        if (inVtSession()||
            m_waitForClose)
        {
            /* resume hw layer display after vFrame is recovered to the scenario tree */
            vFramePause();

            disableAllOp(VFX_TRUE);

            m_isBg = VFX_FALSE;
            vFrameResume();
            m_ready = VFX_FALSE;
        }
        else
        {
            disableAllOp(VFX_TRUE);

            m_vFrame->start();
            m_ready = VFX_FALSE;
        }
    }
}

void VappCallSetPageVtPreview::onExit(VfxBool isBackward)
{
    if (getMainScr()->getIsSnapshotDrawing())
    {
        VfxPage::onExit(isBackward);
        return;
    }

    if (m_formAniTimer)
    {
        if (!isBackward && m_vFrame)
        {
            /* not first update; force update to ensure the parameter is up-to-date */
            startUpdateLocalView(m_formAniTimer);
        }
        else
        {
            VFX_OBJ_CLOSE(m_formAniTimer);
            m_formAniTimer = NULL;
        }
    }

    if (!m_vFrame)
    {
        /* may exit page before the first update local view */
        VfxPage::onExit(isBackward);
        return;
    }

    if (isBackward)
    {
        if (m_status && m_status->videoFrame)
        {
            /* disconnect all event handler before returning mastership in case it is called back between onExit and onDeinit */
            mmi_frm_cb_dereg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, &VappCallSetPageVtPreview::onEvtHdlr, getObjHandle());
            m_vFrame->m_signalVtEvent.disconnect(this, &VappCallSetPageVtPreview::onVFrameEvent);
            vFramePause();
            m_signalVFrameMastershipReturn.emit(this, m_status);
            /* pause before return the mastership */
        }
        else
        {
            /* stop v frame before pop page animation */
            /* in vt incall scenario, vt preview page stops and closes vFrame */
            m_vFrame->stop();
        }
        
        m_status  = NULL;
        m_vFrame = NULL;
    }
    else
    {
        /* forward scenario */
        if (inVtSession())
        {
            /* VT in call, not allow to stop vFrame */
            /* need to suspend hw layer display before vFrame is removed from the scenario tree */
            vFramePause();
        
            disableAllOp(VFX_TRUE);

            m_isBg = VFX_TRUE;
            vFrameResume();
            m_ready = VFX_FALSE;
        }
        else
        {
            /* destory vFrame to free memory */
            m_vFrame->stop();
        }
    }

    VfxPage::onExit(isBackward);
}

void VappCallSetPageVtPreview::startUpdateLocalView(VfxTimer *timer)
{
    if (m_formAniTimer)
    {
        VFX_OBJ_CLOSE(m_formAniTimer);
        m_formAniTimer = NULL;
    }

    if (!m_vFrame || (m_vFrame->getParentFrame() != m_vFrameCell))
    {
        if (!m_vFrame)
        {
            VFX_OBJ_CREATE(m_vFrame, VappVtVideoFrame, m_vFrameCell);
            m_vFrame->setParamAppId(getApp()->getGroupId());
        
        }
        else if (m_vFrame->getParentFrame() != m_vFrameCell)
        {
            /* share vFrame with other screens */
            m_vFrameCell->addChildFrame(m_vFrame);
            //m_vFrameCell->addChild(m_vFrame);
        }
        
        m_vFrame->setAnchor(0.5f, 0.5f);
        m_vFrame->setPos(m_vFrameCell->getSize().width / 2, m_vFrameCell->getSize().height / 2);
        m_vFrame->setSize(VAPP_CALLSET_VT_VFRAME_W + m_vFrame->getFrameMargin() * 2, VAPP_CALLSET_VT_VFRAME_H + m_vFrame->getFrameMargin() * 2);
        
        m_vFrame->setFrameRect(VAPP_VT_VIDEOFRAME_TYPE_LOCAL, VfxRect(VAPP_CALLSET_VT_VFRAME_W/2 + m_vFrame->getFrameMargin(), VAPP_CALLSET_VT_VFRAME_H/2 + m_vFrame->getFrameMargin(), VAPP_CALLSET_VT_VFRAME_W, VAPP_CALLSET_VT_VFRAME_H));

    #ifndef __MDP_VT_PREVIEW_UPSCALE_SUPPORT__
        if (VAPP_CALLSET_VT_VFRAME_W > 176 || VAPP_CALLSET_VT_VFRAME_H > 144)
        {
            m_vFrame->setSize(176 + m_vFrame->getFrameMargin() * 2, 144 + m_vFrame->getFrameMargin() * 2);
            m_vFrame->setFrameRect(VAPP_VT_VIDEOFRAME_TYPE_LOCAL, VfxRect(176/2 + m_vFrame->getFrameMargin(), 144/2 + m_vFrame->getFrameMargin(), 176, 144));
        }
    #endif

        m_vFrame->setParamHide(VAPP_VT_VIDEOFRAME_TYPE_LOCAL, VFX_FALSE);
        m_vFrame->setParamHide(VAPP_VT_VIDEOFRAME_TYPE_PEER, VFX_TRUE);
        
        updateLocalView();
        
        m_vFrame->m_signalVtEvent.connect(this, &VappCallSetPageVtPreview::onVFrameEvent);
        
        if (m_status && m_status->videoFrame)
        {
            /* share vFrame with other screens */
            vFrameResume();
            m_ready = VFX_FALSE;
        }
        else
        {
            m_vFrame->start();
            m_ready = VFX_FALSE;
        }
    }
    else
    {
        vFramePause();
        updateLocalView();
        vFrameResume();
        m_ready = VFX_FALSE;
    }

}

void VappCallSetPageVtPreview::updateLocalView()
{
    switch (getCamMode())
    {
        case SRV_CALLSET_VT_CAMERA_OFF:
            m_vFrame->setParamFrameMode(VAPP_VT_VIDEOFRAME_TYPE_LOCAL, VAPP_VT_VIDEOFRAME_SRC_IMAGE);
            
            WCHAR *buf;
            VFX_ALLOC_MEM(buf, ((SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH), this);
            memset(buf, 0, (SRV_FMGR_PATH_MAX_LEN + 1)*ENCODING_LENGTH);
            if (m_previewOnly && m_status)
            {
                mmi_ucs2ncpy((CHAR *)buf, (CHAR *)m_status->imagePath.getBuf(), SRV_FMGR_PATH_MAX_LEN);
            }
            else
            {
                srv_callset_vt_get_incall_image_path(SRV_FMGR_PATH_MAX_LEN, buf);
            }
            if (!mmi_ucs2strlen((CHAR *)buf))
            {
                m_vFrame->setParamFrameContent(VAPP_VT_VIDEOFRAME_TYPE_LOCAL, VfxImageSrc(IMG_ID_CALLSET_VT_DEFAULT_IMAGE));
            }
        #ifdef __MMI_USB_SUPPORT__
            else if (srv_usb_is_in_mass_storage_mode())
            {
                vapp_usb_unavailable_popup(0);
            }
        #endif /* __MMI_USB_SUPPORT__ */
            else if (m_vFrame->setParamFrameContent(VAPP_VT_VIDEOFRAME_TYPE_LOCAL, VfxImageSrc(VFX_WSTR_MEM(buf))) != VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR)
            {
            	VfxResId resId;
            	if (srv_fmgr_fs_path_exist(buf) != 0)
            	{
            		resId = STR_ID_VAPP_CALLSET_IMG_NOT_AVAILABLE;
            	}
				else
				{
					resId = STR_GLOBAL_INVALID_FORMAT;
				}
				buf[0] = buf[1] = 0;
                srv_callset_vt_set_incall_image_path(SRV_FMGR_PATH_MAX_LEN, buf);
                VAPP_CALLSET_FAIL_POPUP(this, VFX_WSTR_RES(resId));
				
                m_vFrame->setParamFrameContent(VAPP_VT_VIDEOFRAME_TYPE_LOCAL, VfxImageSrc(IMG_ID_CALLSET_VT_DEFAULT_IMAGE));
            }
            VFX_FREE_MEM(buf);
    
            m_vFrame->setParamSensorId(VAPP_VT_VIDEOFRAME_CAMERA_OFF);
            break;
    
        case SRV_CALLSET_VT_CAMERA_FRONT:
            m_vFrame->setParamFrameMode(VAPP_VT_VIDEOFRAME_TYPE_LOCAL, VAPP_VT_VIDEOFRAME_SRC_VIDEO);
            m_vFrame->setParamSensorId(VAPP_VT_VIDEOFRAME_CAMERA_FRONT);
            break;
    
        case SRV_CALLSET_VT_CAMERA_BACK:
            m_vFrame->setParamFrameMode(VAPP_VT_VIDEOFRAME_TYPE_LOCAL, VAPP_VT_VIDEOFRAME_SRC_VIDEO);
            m_vFrame->setParamSensorId(VAPP_VT_VIDEOFRAME_CAMERA_BACK);
            break;
    }

    /* get sensor capability shall be called AFTER the sensor is set (only allow to query the current sensor capability) */
    VappVtVideoFrameZoomCapStruct zoomCap;
    m_vFrame->getZoomCap(&zoomCap);
    m_sliZoom->setMinValue(0.0f);
    m_sliZoom->setMaxValue((VfxFloat)(zoomCap.stepNumber - 1));
    m_sliZoom->setTotalDiscreteStepsForPen(zoomCap.stepNumber - 1);
    m_sliZoom->m_signalThumbReleased.connect(this, &VappCallSetPageVtPreview::onSlideZoom);
    
    VappVtVideoFrameEvCapStruct evCap;
    m_vFrame->getEVCap(&evCap);
    m_sliEv->setMinValue((VfxFloat)(evCap.supportItem[0]));
    m_sliEv->setMaxValue((VfxFloat)(evCap.supportItem[evCap.count - 1]));
    m_sliEv->setTotalDiscreteStepsForPen(evCap.count - 1);
    m_sliEv->m_signalThumbReleased.connect(this, &VappCallSetPageVtPreview::onSlideEv);

    
    if (getCamMode() != SRV_CALLSET_VT_CAMERA_OFF)
    {
        /* set current value must after set min & max */
        m_sliZoom->setCurrentValue((VfxFloat)getZoom());

        VappVtVideoFrameEvEnum v = getVFrameAppEv(getEV());
        VfxU32 i;
		
        for (i = 0; i < evCap.count; i++)
        {
            if (evCap.supportItem[i] == v)
                break;
        }
		
        if (i == evCap.count)
        {
            /* not support, set to default */
            v = VAPP_VT_VIDEOFRAME_EV_0;

			setEV(SRV_CALLSET_VT_EV_0);
        }

        m_sliEv->setCurrentValue((VfxFloat)v);

		m_evText->setString(VFX_WSTR_RES(VappCallSetPageVtPreview::s_evStrId[v]));      

        m_niMode->setSwitchStatus(getNightMode());
        m_vFrame->setParamNightMode(getNightMode());

        m_needUpdateValue = VFX_TRUE;
    }
    else
    {
        m_needUpdateValue = VFX_FALSE;
    }

}

void VappCallSetPageVtPreview::updateLocalValue()
{
    if (getCamMode() != SRV_CALLSET_VT_CAMERA_OFF)
    {
        m_vFrame->setZoomValue((VfxU16)getZoom());

        VappVtVideoFrameEvEnum v = getVFrameAppEv(getEV());
        VFX_ASSERT(v != VAPP_VT_VIDEOFRAME_EV_TOTAL);

        m_vFrame->setEVValue(v);
    }
}

void VappCallSetPageVtPreview::onSegBtnClicked(VfxObject* sender, VfxId id)
{
    srv_callset_vt_camera_mode_enum ori_mode;
    ori_mode = srv_callset_vt_get_camera_mode();

    srv_callset_vt_camera_mode_enum mode;
    switch (id)
    {
        case 1:
            mode = SRV_CALLSET_VT_CAMERA_FRONT;
            break;

        case 2:
            mode = SRV_CALLSET_VT_CAMERA_BACK;
            break;

        case 3:
            mode = SRV_CALLSET_VT_CAMERA_OFF;
            break;

        default:
            return;
    }

    if (mode == getCamMode())
    {
        return;
    }

    if (!m_previewOnly)
    {
        srv_callset_result_enum result;
        result = srv_callset_vt_set_camera_mode(mode);
        if (result != SRV_CALLSET_RESULT_OK)
        {
            VAPP_CALLSET_FAIL_POPUP(this, VFX_WSTR_RES(srv_callset_get_result_string_id(result)));
            return;
        }
    }
    else if (m_status)
    {
        m_status->camMode = mode;
    }

    if (mode != SRV_CALLSET_VT_CAMERA_OFF)
    {
        m_zoom->setIsHidden(VFX_FALSE);
        m_ev->setIsHidden(VFX_FALSE);
        m_niMode->setIsHidden(VFX_FALSE);
        m_selPic->setIsHidden(VFX_TRUE);
    }
    else
    {
        m_zoom->setIsHidden(VFX_TRUE);
        m_ev->setIsHidden(VFX_TRUE);
        m_niMode->setIsHidden(VFX_TRUE);
        m_selPic->setIsHidden(VFX_FALSE);
    }

    disableAllOp(VFX_TRUE);

    VFX_OBJ_CREATE(m_formAniTimer, VfxTimer, this);
    m_formAniTimer->setStartDelay((ori_mode == SRV_CALLSET_VT_CAMERA_OFF) ? 500 : 0);
    /* delay updating local view for form animation when OFF -> FRONT or OFF -> to REAR */
    m_formAniTimer->m_signalTick.connect(this, &VappCallSetPageVtPreview::startUpdateLocalView);
    m_formAniTimer->start();

}

void VappCallSetPageVtPreview::onSlideZoom(VcpSlider* slider, VfxFloat value)
{
    if (!m_vFrame)
    {
        /* slider event is executed after mastership return (during page transition) */
        return;
    }

    VappVtVideoFrameErrorEnum result;
    result = m_vFrame->setZoomValue((VfxU16)value);

#ifndef WIN32
    if (result != VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
                             MMI_EVENT_INFO_BALLOON,
                             MMI_NMGR_BALLOON_TYPE_FAILURE,
                             (WCHAR*)GetString(STR_GLOBAL_ERROR));

        m_sliZoom->setCurrentValue((VfxFloat)getZoom());
        return;
    }
#endif /* WIN32 */

    if (!m_previewOnly)
    {
        srv_callset_vt_set_zoom(getCamMode(), (U8)value);
    }
    else if (m_status)
    {
        if (getCamMode() == SRV_CALLSET_VT_CAMERA_FRONT)
        {
            m_status->zoomFront = (U8)value;
        }
        else if (getCamMode() == SRV_CALLSET_VT_CAMERA_BACK)
        {
            m_status->zoomBack = (U8)value;
        }
    }
}

void VappCallSetPageVtPreview::onSlideEv(VcpSlider* slider, VfxFloat value)
{
    if (!m_vFrame)
    {
        /* slider event is executed after mastership return (during page transition) */
        return;
    }

    VfxU32 v = (VfxFloat)value;
    VappVtVideoFrameErrorEnum result;
    result = m_vFrame->setEVValue((VappVtVideoFrameEvEnum)v);
#ifndef WIN32
    if (result != VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
                             MMI_EVENT_INFO_BALLOON,
                             MMI_NMGR_BALLOON_TYPE_FAILURE,
                             (WCHAR*)GetString(STR_GLOBAL_ERROR));
        
        m_sliEv->setCurrentValue((VfxFloat)getVFrameAppEv(getEV()));
        return;
    }
#endif /* WIN32 */

	m_evText->setString(VFX_WSTR_RES(VappCallSetPageVtPreview::s_evStrId[v])); 

	setEV(getCallsetSrvVtEv((VappVtVideoFrameEvEnum)v));
}

void VappCallSetPageVtPreview::onSwitch(VcpFormItemSwitchCell* item, VfxId id, VfxBool state)
{
    if (!m_previewOnly)
    {
        srv_callset_result_enum result;
        result = srv_callset_vt_set_night_mode(getCamMode(), (MMI_BOOL)state);
        if (result != SRV_CALLSET_RESULT_OK)
        {
            VAPP_CALLSET_FAIL_POPUP(this, 
                VFX_WSTR_RES(srv_callset_get_result_string_id(result)));
            item->setSwitchStatus(!state);
            return;
        }
    }
    else if (m_status)
    {
        if (getCamMode() == SRV_CALLSET_VT_CAMERA_FRONT)
        {
            m_status->nightModeFront = state;
        }
        else if (getCamMode() == SRV_CALLSET_VT_CAMERA_BACK)
        {
            m_status->nightModeBack = state;
        }
    }

    item->setSwitchStatus(state);
	m_isSwitched = VFX_TRUE;
    /* update value after encoding path built */
    /* page transition animation blocks if encoding path is not built */

}


void VappCallSetPageVtPreview::onAniDone(VcpFormItemSwitchCell* item, VfxId id, VfxBool state)
{
	if ((m_vFrame == NULL) || !m_isSwitched)
	{
		return;
	}
	
    vFramePause();
    m_vFrame->setParamNightMode(state);

    disableAllOp(VFX_TRUE);

    vFrameResume();
    m_ready = VFX_FALSE;

    m_needUpdateValue = VFX_TRUE;

	m_isSwitched = VFX_FALSE;
}

void VappCallSetPageVtPreview::onItemTap(VcpFormItemCell *item, VfxId id)
{
    if (id != 1)
    {
        return;
    }

    FMGR_FILTER filter;
    
    FMGR_FILTER_INIT(&filter);
#if defined(__GDI_MEMORY_PROFILE_2__)   /* Able to select jpeg file if supported */
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPEG);
#endif 
    FMGR_FILTER_SET(&filter, FMGR_TYPE_GIF);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_BMP);    
    FMGR_FILTER_SET(&filter, FMGR_TYPE_WBMP);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_WBM);
#if defined(GDI_USING_PNG)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_PNG);
#endif 
#if defined(GDI_USING_M3D)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_M3D);
#endif
/* .SVG file is now not supported due to stack overflow */
#ifdef SVG12_SUPPORT
    FMGR_FILTER_SET(&filter, FMGR_TYPE_SVG);
#endif
#if defined(__DRM_V02__)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif /* defined(__DRM_V02__) */
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    m_fmgr = vcui_file_selector_create(
                        getApp()->getGroupId(),
                        (WCHAR*) L"root",
                        &filter,
                        VCUI_FILE_SELECTOR_STYLE_FILE_ONLY,
                        VCUI_FILE_SELECTOR_OPT_FIXED_PATH_ON | VCUI_FILE_SELECTOR_OPT_DRM_CHECK_SET_ON | VCUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FOLDER);

    if (m_fmgr != GRP_ID_INVALID)
    {
        mmi_frm_group_set_caller_proc(m_fmgr, &VappCallSetPageVtPreview::onEvtHdlr, getObjHandle());

        vcui_file_selector_run(m_fmgr);
    }

}

mmi_ret VappCallSetPageVtPreview::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_VCUI_FILE_SELECTOR_RESULT:
        {
            vcui_file_selector_result_event_struct *result =
                (vcui_file_selector_result_event_struct*) evt;

            if (result->result > 0)
            {
                WCHAR* path;
                VFX_ALLOC_MEM(path, ((SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH), this);

                vcui_file_selector_get_selected_filepath(
                    result->sender_id,
                    NULL,
                    path,
                    (SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH);

                VfxSize imgSize;
                gdi_image_get_dimension_file((S8*)path, &imgSize.width, &imgSize.height);
                if (!imgSize.width || imgSize.width > 1024 ||
                        !imgSize.height || imgSize.height > 1024)
                {
                    VAPP_CALLSET_FAIL_POPUP(this, 
                        VFX_WSTR_RES(STR_GLOBAL_INVALID_FORMAT));

                    /* fmgr cui handles the error popups */
                    vcui_file_selector_close(result->sender_id);
                    m_fmgr = GRP_ID_INVALID;
                    VFX_FREE_MEM(path);
                    return MMI_RET_OK;
                }

                if (inVtSession())
                {
                    vFramePause();
                }

                if (m_vFrame->setParamFrameContent(VAPP_VT_VIDEOFRAME_TYPE_LOCAL, VfxImageSrc(VFX_WSTR_MEM(path))) != VAPP_VT_VIDEOFRAME_ERROR_NO_ERROR)
                {
                    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
                                         MMI_EVENT_INFO_BALLOON,
                                         MMI_NMGR_BALLOON_TYPE_FAILURE,
                                         (WCHAR*)GetString(STR_GLOBAL_INVALID_FORMAT));
                }
                else
                {
                    if (!m_previewOnly)
                    {
                        srv_callset_result_enum result;
                        result = srv_callset_vt_set_incall_image_path(SRV_FMGR_PATH_MAX_LEN, path);
                        if (result != SRV_CALLSET_RESULT_OK)
                        {
                            VAPP_CALLSET_FAIL_POPUP(this, 
                                VFX_WSTR_RES(srv_callset_get_result_string_id(result)));
                            VFX_FREE_MEM(path);
                            return VfxPage::onProc(evt);;
                        }
                    }
                    else if (m_status)
                    {
                        m_status->imagePath = VFX_WSTR_MEM(path);
                    }
                }

                VFX_FREE_MEM(path);

                if (inVtSession())
                {
                    vFrameResume();
                    /* close fmgr cui after bgResume ready */
                    m_waitForCloseFmgr = VFX_TRUE;
                }
                else
                {
                    vcui_file_selector_close(result->sender_id);
                    m_fmgr = GRP_ID_INVALID;
                }

            }
            else
            {
                /* fmgr cui handles the error popups */
                vcui_file_selector_close(result->sender_id);
                m_fmgr = GRP_ID_INVALID;
            }
            break;
        }
        
        case EVT_ID_SRV_UCM_STATUS_CHANGE:
        {
            if (m_status && m_status->videoFrame)
            {
                if (!inVtSession()||
                    srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL))
                {
                    srv_ucm_index_info_struct index_list[SRV_UCM_MAX_CALL];
                    if (inVtSession()&&
                            srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, index_list))
                    {
                        /* case 1. 1A VT -> preview page -> 1 new W, need to exit preview page
                         * case 2. 1A VT + 1W -> preview page -> release 1W */
                        srv_ucm_call_info_struct call_info;
                        if (!srv_ucm_query_call_data(index_list[0], &call_info) ||
                                call_info.is_disconnecting)
                        {
                            /* case 2. 1A VT + 1W -> preview page -> release 1W
                             *          not new incoming call, don't exit preview page
                             */
                            break;
                        }
                    }

                    if (!srv_shutdown_is_running())
                    {
                        if (!inVtSession())
                        {
                            m_waitForClose = VFX_TRUE; /* set is wait for close to TRUE for onEnter during set to active group */
                        }

                        /* not allow to return mastership in the background, set active first */
                        mmi_frm_set_active_group(getApp()->getGroupId());

                        if (!inVtSession())
                        {
                            m_waitForClose = VFX_FALSE;
                        }
                    }

                    /* VT active call releases or new incoming call */
                    disableAllOp(VFX_TRUE);

                    if (m_fmgr != GRP_ID_INVALID)
                    {
                        m_waitForClose = VFX_TRUE;
                        vcui_file_selector_close(m_fmgr);
                        m_fmgr = GRP_ID_INVALID;
                    }
                    else if (m_ready)
                    {
                        postExit();
                    }
                    else
                    {
                        m_waitForClose = VFX_TRUE;
                    }
                }
            }
            else
            {
                /* doesn't share vFrame with in call screen */
                if (inVtSession())
                {
                    /* new VT active call */
                    /* may receive ucm status change during vt in call (ex. 1A1W -> release 1W)
                     * 1. not in-call adjust local image scenario and 
                     * 2. there is an active VT call
                     */
                    /* hw layer is not allow to be > 2, close VT preview page */

                    if (m_fmgr != GRP_ID_INVALID)
                    {
                        vcui_file_selector_close(m_fmgr);
                        m_fmgr = GRP_ID_INVALID;
                    }

                    /* to prevent multiple VappUcmVtVideoFrame instance, close vFrame before entering VT in call screen */
					VFX_OBJ_CLOSE(m_vFrame);
                    postExit();
                }
            }
            break;
        }

    }
    
    return VfxPage::onProc(evt);
}

mmi_ret VappCallSetPageVtPreview::onEvtHdlr(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_UCM_STATUS_CHANGE:
        case EVT_ID_VCUI_FILE_SELECTOR_RESULT:
        {
            VappCallSetPageVtPreview *page;
			page = (VappCallSetPageVtPreview *)handleToObject((VfxObjHandle)evt->user_data);
			if (page != NULL)
			{
            return page->onProc(evt);
        }
    }
    }

    return MMI_RET_OK;
}

void VappCallSetPageVtPreview::onVFrameEvent(VappVtVideoFrameEvtEnum evt, VfxS32 param)
{
    switch (evt)
    {
        case VAPP_VT_VIDEOFRAME_EVENT_START:
        case VAPP_VT_VIDEOFRAME_EVENT_RESUME:
            m_ready = VFX_TRUE;

        #ifdef WIN32
            if (m_needUpdateValue)
            {
                updateLocalValue();
                m_needUpdateValue = VFX_FALSE;
            }
        #endif /* WIN32 */

            if (!m_needUpdateValue) /* update EV / Zoom value needs to wait for ENC_PATH_BUILT */
            {
                disableAllOp(VFX_FALSE);
            }

            if (m_waitForCloseFmgr)
            {
                vcui_file_selector_close(m_fmgr);
                m_fmgr = GRP_ID_INVALID;
                m_waitForCloseFmgr = VFX_FALSE;
            }

            if (m_waitForClose)
            {
                m_waitForClose = VFX_FALSE;
                postExit();
            }
            break;

        case VAPP_VT_VIDEOFRAME_EVENT_ENC_PATH_BUILT:
            if (m_needUpdateValue)
            {
                updateLocalValue();
                disableAllOp(VFX_FALSE);
                m_needUpdateValue = VFX_FALSE;
            }
            break;

    }
}

VfxBool VappCallSetPageVtPreview::onKeyInput(VfxKeyEvent & event)
{
    if (!m_ready
    #ifndef WIN32
        || m_needUpdateValue
    #endif
        )
    {
        /* block all keys */
        /* page transition animation blocks if encoding path is not built */
        return VFX_TRUE;
    }

    return VfxPage::onKeyInput(event);

}

void VappCallSetPageVtPreview::disableAllOp(VfxBool isDisable)
{
    m_zoom->setIsDisabled(isDisable);
    m_ev->setIsDisabled(isDisable);
    m_niMode->setIsDisabled(isDisable);
    m_selPic->setIsDisabled(isDisable);
    if (!m_previewOnly)
    {
        m_segBtn->setButtonIsDisabled(1, isDisable);
        m_segBtn->setButtonIsDisabled(2, isDisable);
        m_segBtn->setButtonIsDisabled(3, isDisable);
    }
}

void VappCallSetPageVtPreview::postExit()
{
    /* exit after VRT commit, to avoid video frame operations during SSE effect (close CUI) */
    VfxTimer *timer;
    VFX_OBJ_CREATE(timer, VfxTimer, this);
    timer->m_signalTick.connect(this, &VappCallSetPageVtPreview::onPostExit);
    timer->start(); 
}

void VappCallSetPageVtPreview::onPostExit(VfxTimer *timer)
{
    exit();
}

void VappCallSetPageVtPreview::vFramePause()
{
    if (!m_ready)
    {
        MMI_ASSERT(!m_isBg);
        m_vFrame->abortResume();
        return;
    }

    if (m_isBg)
    {
        m_vFrame->backgroundPause();
    }
    else
    {
        m_vFrame->pause();
    }
}

void VappCallSetPageVtPreview::vFrameResume()
{
    m_ready = VFX_FALSE;

    if (m_isBg)
    {
        m_vFrame->backgroundResume();
    }
    else
    {
        m_vFrame->resume();
    }
}

VappVtVideoFrameEvEnum VappCallSetPageVtPreview::getVFrameAppEv(srv_callset_vt_ev_enum ev)
{
	for (VfxU32 i = 0; i < VAPP_VT_VIDEOFRAME_EV_TOTAL; i++)
    {
		if (ev == VappCallSetPageVtPreview::s_evSrvVal[i])
		{
			return (VappVtVideoFrameEvEnum)i;
		}
	}

    return VAPP_VT_VIDEOFRAME_EV_TOTAL;
 }

srv_callset_vt_ev_enum VappCallSetPageVtPreview::getCallsetSrvVtEv(VappVtVideoFrameEvEnum ev)
{
        
	return ((ev < VAPP_VT_VIDEOFRAME_EV_TOTAL) ? VappCallSetPageVtPreview::s_evSrvVal[ev] : SRV_CALLSET_VT_EV_INVALID);
}

srv_callset_vt_camera_mode_enum VappCallSetPageVtPreview::getCamMode(void) const
{
	 if (m_previewOnly && (m_status != NULL))
	 {
	 	return m_status->camMode;
	 }

	 return srv_callset_vt_get_camera_mode();
}

VfxBool VappCallSetPageVtPreview::getNightMode(void) const
{
	if (m_previewOnly && (m_status != NULL)) 
	{
		return ((getCamMode() == SRV_CALLSET_VT_CAMERA_FRONT) ? m_status->nightModeFront : m_status->nightModeBack);
	}

	return (srv_callset_vt_get_night_mode(getCamMode()) ? VFX_TRUE : VFX_FALSE);
}

srv_callset_vt_ev_enum VappCallSetPageVtPreview::getEV(void) const
{
	if (m_previewOnly && (m_status != NULL))
	{
		return ((getCamMode() == SRV_CALLSET_VT_CAMERA_FRONT) ? m_status->evFront : m_status->evBack);
	}

	return srv_callset_vt_get_ev(getCamMode());
}

void VappCallSetPageVtPreview::setEV(const srv_callset_vt_ev_enum &ev)
{
    if (!m_previewOnly)
    {
        srv_callset_vt_set_ev(getCamMode(), ev);
    }
    else if (m_status != NULL)
    {
        if (getCamMode() == SRV_CALLSET_VT_CAMERA_FRONT)
        {
            m_status->evFront = ev;
        }
        else if (getCamMode() == SRV_CALLSET_VT_CAMERA_BACK)
        {
            m_status->evBack = ev;
        }
    }
}

VfxU8 VappCallSetPageVtPreview::getZoom(void) const
{
    if (m_previewOnly && (m_status != NULL))
    {
        return ((getCamMode() == SRV_CALLSET_VT_CAMERA_FRONT) ? m_status->zoomFront : m_status->zoomBack);
    }

    return srv_callset_vt_get_zoom(getCamMode());
}

VfxBool VappCallSetPageVtPreview::inVtSession(void) const
{
    if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VIDEO_CALL_TYPE, NULL)
    #ifdef __MMI_EM_PROFILING_VT_LOOKBACK__
/* under construction !*/
    #endif /* __MMI_EM_PROFILING_VT_LOOKBACK__ */
        )
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

void VappCallSetPageVtDialMode::onInit()
{
    VfxPage::onInit(); // call base class

    VcpTitleBar *titlebar;
    VFX_OBJ_CREATE(titlebar, VcpTitleBar, this);
    titlebar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT_DIAL_MODE));
    setTopBar(titlebar);

    m_count = 2;

    switch (srv_callset_vt_get_dial_mode())
    {
        case SRV_CALLSET_VT_DIAL_MODE_STOP_CAMERA:
            m_activateIndex = 1;
            break;

        default:
            m_activateIndex = 0;
            break;
    }

    VcpListMenu *menu;
    VFX_OBJ_CREATE(menu, VcpListMenu, this);
    menu->setPos(0,0);
    menu->setSize(getSize());
    menu->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);
    menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    menu->setContentProvider(this);
    menu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK);
    menu->m_signalItemSelectionStateChanged.connect(this, &VappCallSetPageVtDialMode::onSelect);
    menu->m_signalItemTapped.connect(this, &VappCallSetPageVtDialMode::onTapped);
}

VfxBool VappCallSetPageVtDialMode::getItemText(
    VfxU32 index,                    
    VcpListMenuFieldEnum fieldType,  
    VfxWString &text,                
    VcpListMenuTextColorEnum &color  
    )
{
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;

    switch (index)
    {
        case 0:
            text = VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT_START_CAM);
            break;

        case 1:
            text = VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT_STOP_CAM);
            break;

        default:
            return VFX_FALSE;
    }

    return VFX_TRUE;
}

VfxU32 VappCallSetPageVtDialMode::getCount() const {return m_count;}

VcpListMenuItemStateEnum VappCallSetPageVtDialMode::getItemState(
    VfxU32 index   
    ) const 
{
    return (index == m_activateIndex) ?
                VCP_LIST_MENU_ITEM_STATE_SELECTED : VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

void VappCallSetPageVtDialMode::onSelect(
    VcpListMenu* menu, 
    VfxU32 index, 
    VcpListMenuItemStateEnum state
    )
{
    if (state != VCP_LIST_MENU_ITEM_STATE_SELECTED)
    {
        return;
    }

    srv_callset_result_enum result;
    switch (index)
    {
        case 0:
            result = srv_callset_vt_set_dial_mode(SRV_CALLSET_VT_DIAL_MODE_START_CAMERA);
            break;

        case 1:
            result = srv_callset_vt_set_dial_mode(SRV_CALLSET_VT_DIAL_MODE_STOP_CAMERA);
            break;

        default:
            return;
    }

    if (result != SRV_CALLSET_RESULT_OK)
    {
        VAPP_CALLSET_FAIL_POPUP(this, VFX_WSTR_RES(srv_callset_get_result_string_id(result)));
    }   

    m_activateIndex = index;
}

void VappCallSetPageVtDialMode::onTapped(
    VcpListMenu* menu,
    VfxU32 index)
{
    getMainScr()->popPage();
}


void VappCallSetPageVtAnsMode::onInit()
{
    VfxPage::onInit(); // call base class

    VcpTitleBar *titlebar;
    VFX_OBJ_CREATE(titlebar, VcpTitleBar, this);
    titlebar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT_ANS_MODE));
    setTopBar(titlebar);

    m_count = 3;

    switch (srv_callset_vt_get_answer_mode())
    {
        case SRV_CALLSET_VT_ANSWER_MODE_STOP_CAMERA:
            m_activateIndex = 1;
            break;

        case SRV_CALLSET_VT_ANSWER_MODE_PROMPT:
            m_activateIndex = 2;
            break;

        default:
            m_activateIndex = 0;
            break;
    }

    VcpListMenu *menu;
    VFX_OBJ_CREATE(menu, VcpListMenu, this);
    menu->setPos(0,0);
    menu->setSize(getSize());
    menu->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);
    menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    menu->setContentProvider(this);
    menu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK);
    menu->m_signalItemSelectionStateChanged.connect(this, &VappCallSetPageVtAnsMode::onSelect);
    menu->m_signalItemTapped.connect(this, &VappCallSetPageVtAnsMode::onTapped);
}

VfxBool VappCallSetPageVtAnsMode::getItemText(
    VfxU32 index,
    VcpListMenuFieldEnum fieldType,  
    VfxWString &text,                
    VcpListMenuTextColorEnum &color  
    )
{
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;

    switch (index)
    {
        case 0:
            text = VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT_START_CAM);
            break;

        case 1:
            text = VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT_STOP_CAM);
            break;

        case 2:
            text = VFX_WSTR_RES(STR_ID_VAPP_CALLSET_VT_PROMPT);
            break;

        default:
            return VFX_FALSE;
    }

    return VFX_TRUE;
}

VfxU32 VappCallSetPageVtAnsMode::getCount() const {return m_count;}

VcpListMenuItemStateEnum VappCallSetPageVtAnsMode::getItemState(
    VfxU32 index   
    ) const 
{
    return (index == m_activateIndex) ?
                VCP_LIST_MENU_ITEM_STATE_SELECTED : VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

void VappCallSetPageVtAnsMode::onSelect(
    VcpListMenu* menu, 
    VfxU32 index, 
    VcpListMenuItemStateEnum state
    )
{
    if (state != VCP_LIST_MENU_ITEM_STATE_SELECTED)
    {
        return;
    }

    srv_callset_result_enum result;
    switch (index)
    {
        case 0:
            result = srv_callset_vt_set_answer_mode(SRV_CALLSET_VT_ANSWER_MODE_START_CAMERA);
            break;

        case 1:
            result = srv_callset_vt_set_answer_mode(SRV_CALLSET_VT_ANSWER_MODE_STOP_CAMERA);
            break;

        case 2:
            result = srv_callset_vt_set_answer_mode(SRV_CALLSET_VT_ANSWER_MODE_PROMPT);
            break;

        default:
            return;
    }

    if (result != SRV_CALLSET_RESULT_OK)
    {
        VAPP_CALLSET_FAIL_POPUP(this, VFX_WSTR_RES(srv_callset_get_result_string_id(result)));
    }   

    m_activateIndex = index;
}

void VappCallSetPageVtAnsMode::onTapped(
    VcpListMenu* menu,
    VfxU32 index)
{
    getMainScr()->popPage();
}

#pragma arm section code, rodata
