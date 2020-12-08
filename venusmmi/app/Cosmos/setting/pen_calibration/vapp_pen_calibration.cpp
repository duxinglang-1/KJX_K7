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
 *  vapp_pen_calibration.cpp
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_pen_calibration.h"
#include "mmi_rp_vapp_setting_def.h"
#include "mmi_rp_vcui_pen_calibration_def.h"
extern "C"
{
#include "PenCalibrationSrvGprot.h"
#include "mmi_msg_struct.h"
}
#include "vcp_global_popup.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_PEN_CALIBRATION_TARGET_SIZE    (41)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*for calibration download data check */

// for pen calibration app
VfxId VappPenCalibrationString[VAPP_CALIBRATION_POINT + 1] =
{
    STR_ID_VAPP_PEN_CALIBRATION_WELCOME_STRING,
    STR_ID_VAPP_PEN_CALIBRATION_POINT1_STRING,
    STR_ID_VAPP_PEN_CALIBRATION_POINT2_STRING,
    STR_ID_VAPP_PEN_CALIBRATION_POINT3_STRING
};
static mmi_id g_pen_calibration_cui_id;
VfxBool VappPenCalibrationCui::m_cuiIsLaunched = VFX_FALSE;

mmi_id vcui_pen_calibration_create(mmi_id parent_gid, void *user_data)
{
    if (!VappPenCalibrationCui::isAvailable())
	{
	    return 0;
	}
    
    mmi_id cui_id = VfxAppLauncher::createCui(
                                        VCUI_PEN_CALIBRATION,
                                        VFX_OBJ_CLASS_INFO(VappPenCalibrationCui),
                                        parent_gid,
                                        user_data,
                                        sizeof(user_data));
    return cui_id;
}

void vcui_pen_calibration_run(mmi_id cui_gid)
{
    VfxAppLauncher::runCui(cui_gid);
}

void vcui_pen_calibration_close(mmi_id cui_gid)
{
    VfxAppLauncher::terminate(cui_gid);
}

void vcui_pen_calibration_set_attribute(mmi_id cui_gid, cui_pen_calibration_attribute_enum attribute)
{
    VappPenCalibrationCui *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_gid), VappPenCalibrationCui);
    cui->setAttribute(attribute);
}

mmi_ret vapp_pen_calibration_proc(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_CUI_PEN_CALIBRATION_DONE || evt->evt_id == EVT_ID_CUI_PEN_CALIBRATION_CANCEL)
	{
	    vcui_pen_calibration_close(g_pen_calibration_cui_id);
        g_pen_calibration_cui_id = GRP_ID_INVALID;
	}
    return MMI_RET_OK;
}

void vapp_pen_calibration_launch(VfxMainScr *mainScr)
{
    VfxApp *app = mainScr->getApp();
    g_pen_calibration_cui_id = vcui_pen_calibration_create(app->getGroupId(), NULL);
    mmi_frm_group_set_caller_proc(g_pen_calibration_cui_id, &vapp_pen_calibration_proc, NULL);
    vcui_pen_calibration_run(g_pen_calibration_cui_id);
    vcui_pen_calibration_set_attribute(g_pen_calibration_cui_id, CUI_PEN_CALIBRATION_NORMAL_CALIBRATION);

}
extern "C"
{

static VfxBool g_vapp_pen_calibration_is_needed;
static mmi_id g_vapp_pen_calibration_app_id;
mmi_ret vapp_pen_calibration_pen_evt_hdlr(mmi_event_struct *evt)
{
    mmi_multi_touch_event_struct *touch_evt = (mmi_multi_touch_event_struct*)evt;
    if (g_vapp_pen_calibration_is_needed
        && touch_evt->touch_data[0].event == MMI_PEN_EVENT_DOWN)
    {
        if(g_vapp_pen_calibration_app_id)
	    {	    
	        VfxApp *app = VfxApp::getObject(g_vapp_pen_calibration_app_id);
            if(app && app->isActive())
            {
                return MMI_RET_OK;
            }
            else
            {
                VfxAppLauncher::terminate(g_vapp_pen_calibration_app_id);
                g_vapp_pen_calibration_app_id = GRP_ID_INVALID;
            }
        }
        g_vapp_pen_calibration_app_id = VfxAppLauncher::launch( 
            VAPP_PEN_CALIBRATION,
            VFX_OBJ_CLASS_INFO(VappPenCalibrationCui),
            GRP_ID_ROOT);
        vcui_pen_calibration_set_attribute(g_vapp_pen_calibration_app_id, CUI_PEN_CALIBRATION_FIRST_CALIBRATION);
        return MMI_RET_STOP_TOUCH_HANDLE;
	}
    return MMI_RET_OK;
}

mmi_ret vapp_pen_calibration_init(mmi_event_struct *evt)
{
    g_vapp_pen_calibration_is_needed = (srv_setting_pen_calibration_is_calibration_needed() == MMI_TRUE ? VFX_TRUE : VFX_FALSE);
    return MMI_RET_OK;
}
}
/***************************************************************************** 
 * Class 
 *****************************************************************************/
/***************************************************************************** 
 * VappPenCalibrationControl
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappPenCalibrationControl", VappPenCalibrationControl, VfxControl);
VfxBool VappPenCalibrationControl::onPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_UP)
	{
	    m_signalTap.emit();
	}
	return VFX_TRUE;
}
/***************************************************************************** 
 * VappPenCalibrationPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappPenCalibrationPage", VappPenCalibrationPage, VfxPage);
void VappPenCalibrationPage::onInit()
{
    setStatusBar(VFX_FALSE);
        
    VfxPage::onInit();
    setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
        
    VFX_OBJ_CREATE(m_backgroundFrame, VappPenCalibrationControl, this);
    m_backgroundFrame->setSize(LCD_WIDTH, LCD_HEIGHT);
    m_backgroundFrame->setBgColor(VFX_COLOR_BLACK);
    m_backgroundFrame->m_signalTap.connect(this, &VappPenCalibrationPage::onTap);

    VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);
    m_textFrame->setAnchor(0.5, 0.5);
    m_textFrame->setPos((LCD_WIDTH / 2), (LCD_HEIGHT / 3));
    m_textFrame->setSize((LCD_WIDTH * 4 / 5), (LCD_HEIGHT / 5));
    m_textFrame->setAutoResized(VFX_TRUE);
    m_textFrame->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    m_textFrame->setColor(VFX_COLOR_WHITE);
    m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_textFrame->setIsUnhittable(VFX_TRUE);

    VFX_OBJ_CREATE(m_imageFrame, VfxAnimImageFrame, this);
    m_imageFrame->setResId(IMG_ID_VAPP_SETTING_PEN_CALIBRATION_TARGET);
    m_imageFrame->setAnchor(0.5, 0.5);
    m_imageFrame->setSize(VAPP_PEN_CALIBRATION_TARGET_SIZE, VAPP_PEN_CALIBRATION_TARGET_SIZE);
    m_imageFrame->setIsUnhittable(VFX_TRUE);
    m_imageFrame->play();
 
}

void VappPenCalibrationPage::onEnter(VfxBool isBackward)
{
    if (isBackward && m_state != VAPP_PEN_CALIBRATION_WELCOME_PAGE)
    {
        m_signalRestart.emit();
    }
}

void VappPenCalibrationPage::drawPage()
{
    m_textFrame->setString(VappPenCalibrationString[m_state]);
    switch (m_state)
	{
	case VAPP_PEN_CALIBRATION_WELCOME_PAGE:
        m_imageFrame->setHidden(VFX_TRUE);
		break;
	case VAPP_PEN_CALIBRATION_POINT1_PAGE:
	case VAPP_PEN_CALIBRATION_POINT2_PAGE:
	case VAPP_PEN_CALIBRATION_POINT3_PAGE:
    {
        m_imageFrame->setHidden(VFX_FALSE);
        mmi_pen_point_struct *point = srv_setting_pen_calibration_get_point(m_state - 1);
        m_imageFrame->setPos(
            point->x,
            point->y);
		break;
    }
	default:
		ASSERT(0);
	}
}

VfxBool VappPenCalibrationPage::onKeyInput(VfxKeyEvent &event)
{
    if ((event.keyCode == VFX_KEY_CODE_HOME ||
         event.keyCode == VFX_KEY_CODE_BACK)&&
        event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        if (m_attribute == CUI_PEN_CALIBRATION_FIRST_CALIBRATION)
    	{
            return VFX_TRUE;	
    	}
        else if (m_attribute == CUI_PEN_CALIBRATION_NORMAL_CALIBRATION)
        {
            m_signalCancel.postEmit();
            if (event.keyCode == VFX_KEY_CODE_HOME || event.keyCode == VFX_KEY_CODE_END)
        	{
                    return VfxPage::onKeyInput(event);            	
        	}
	    return VFX_TRUE;
        }
    }
    return VfxPage::onKeyInput(event);    
}

/***************************************************************************** 
 * VappPenCalibrationCui
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappPenCalibrationCui", VappPenCalibrationCui, VfxCui);
void VappPenCalibrationCui::onRun(void* args, VfxU32 argSize)
{
    if (args)
    {
        m_userData = args;
    }
    
    VFX_OBJ_CREATE(m_mainScr, VfxMainScr, this);
    m_mainScr->setBgColor(VFX_COLOR_BLACK);
    m_mainScr->show();
    srv_setting_pen_calibration_pre_start();
    if (m_attribute == CUI_PEN_CALIBRATION_FIRST_CALIBRATION)
    {
	srv_setting_pen_calibration_update_default_data();
    }
    if (!m_currPage)
	{
    	VFX_OBJ_CREATE(m_currPage, VappPenCalibrationPage, m_mainScr);
        m_currPage->m_signalTap.connect(this, &VappPenCalibrationCui::onPenTapped);
        m_currPage->m_signalCancel.connect(this, &VappPenCalibrationCui::onCancel);
        m_currPage->m_signalRestart.connect(this, &VappPenCalibrationCui::onRestart);
        m_currPage->setAttribute(m_attribute);
        m_currPage->setState(m_pageState);
        m_mainScr->pushPage(0, m_currPage);
	}
}

void VappPenCalibrationCui::onDeinit()
{
    if (!m_calibrationDone &&(m_pageState != VAPP_PEN_CALIBRATION_WELCOME_PAGE))
	{
	    srv_setting_pen_calibration_cancel_calibration();
	}
    m_cuiIsLaunched = VFX_FALSE;
}

void VappPenCalibrationCui::setAttribute(cui_pen_calibration_attribute_enum attribute) 
{
    m_attribute = attribute;
    if (m_attribute == CUI_PEN_CALIBRATION_FIRST_CALIBRATION)
    {
	    srv_setting_pen_calibration_update_default_data();
    }
    m_currPage->setAttribute(m_attribute);
}

void VappPenCalibrationCui::onCancel()
{
    mmi_group_event_struct event;
    event.evt_id = EVT_ID_CUI_PEN_CALIBRATION_CANCEL;
    event.user_data = m_userData;
    event.sender_id = m_groupId;
    sendToCaller(&event);
}

void VappPenCalibrationCui::onRestart()
{
    m_pageState = VAPP_PEN_CALIBRATION_WELCOME_PAGE;
    m_currPage->setState(m_pageState);
#ifdef __MTK_TARGET__  
    srv_setting_pen_calibration_cancel_calibration();
    srv_setting_pen_calibration_pre_start();
#endif
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Pen calibration] onRestart");        
}  

void VappPenCalibrationCui::restartCalibration()
{
    m_pageState = VAPP_PEN_CALIBRATION_POINT1_PAGE;
    m_currPage->setState(m_pageState);
#ifdef __MTK_TARGET__  
    srv_setting_pen_calibration_restart(&VappPenCalibrationCui::CalibrationProc, this);
#endif
}

void VappPenCalibrationCui::onPenTapped()
{
    #ifdef __MTK_TARGET__
    if (m_pageState == VAPP_PEN_CALIBRATION_WELCOME_PAGE)
	{
        srv_setting_pen_calibration_start(&VappPenCalibrationCui::CalibrationProc, this);
	}
    #endif
    if (m_pageState == VAPP_PEN_CALIBRATION_POINT3_PAGE)
    {
        #ifndef __MTK_TARGET__
         // Display popup (Modis)
        onPenCalibrationRsp(VFX_TRUE);
        #endif
	    // Calibration done, wait for result (TARGET)
	return;        
    }
    else
    {
	m_pageState = (VappPenCalibrationPageEnum)(m_pageState + 1);    
        m_currPage->setState(m_pageState);
    }
}

void VappPenCalibrationCui::onCalibrationDone()
{    
	if (m_attribute == CUI_PEN_CALIBRATION_FIRST_CALIBRATION && g_vapp_pen_calibration_app_id != 0)
	{
	    // First calibration launched as an APP
	    g_vapp_pen_calibration_is_needed = VFX_FALSE;
        g_vapp_pen_calibration_app_id = 0;
	    VfxAppLauncher::terminate(getGroupId());
	}
    else
    {
    mmi_group_event_struct event;
    event.evt_id = EVT_ID_CUI_PEN_CALIBRATION_DONE;
    event.user_data = m_userData;
    event.sender_id = m_groupId;
    sendToCaller(&event);
}
}

VfxAppCloseAnswerEnum VappPenCalibrationCui::onProcessClose(VfxAppCloseOption options)
{
    if (m_attribute == CUI_PEN_CALIBRATION_FIRST_CALIBRATION)
     {
         return VFX_APP_CLOSE_ANSWER_NO;    
     }
     else if (m_attribute == CUI_PEN_CALIBRATION_NORMAL_CALIBRATION)
     {
         return VFX_APP_CLOSE_ANSWER_YES;
    }
    return VFX_APP_CLOSE_ANSWER_YES;    
}


void VappPenCalibrationCui::onPenCalibrationRsp(VfxBool result)
{
    if (result)
	{
	    m_calibrationDone = VFX_TRUE;
        onCalibrationDone();
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_SUCCESS, 
            VFX_WSTR_RES(STR_ID_VAPP_PEN_CALIBRATION_SUCCESS_INFO).getBuf());
#ifndef __MTK_TARGET__            
        srv_setting_pen_calibration_update_data_in_modis();
#endif
	}
#ifdef __MTK_TARGET__    
    else
    {
        restartCalibration();
    }   
#endif    
}
#ifdef __MTK_TARGET__
mmi_ret VappPenCalibrationCui::CalibrationProc(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_SRV_PEN_CALIBRATION_DONE)
	{
	    VfxObject *obj = (VfxObject*)evt->user_data;
        VappPenCalibrationCui *cui = VFX_OBJ_DYNAMIC_CAST(obj, VappPenCalibrationCui);
        if (cui)
    	{
    	    srv_setting_pen_calibration_event_struct *calibrationResult = (srv_setting_pen_calibration_event_struct*)evt;
    	    cui->onPenCalibrationRsp(calibrationResult->result);
    	}
	}
    return MMI_RET_OK;
}
#endif
