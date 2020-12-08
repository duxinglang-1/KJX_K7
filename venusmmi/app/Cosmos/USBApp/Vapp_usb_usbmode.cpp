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
 *  vapp_usb_basecontext.cpp
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __USB_MMI_DEBUG__
#ifndef __MTK_TARGET__
#ifndef __MMI_USB_SUPPORT__
#define __MMI_USB_SUPPORT__
#endif
#endif
#endif
#include "MMI_features.h" 


#if defined(__MMI_USB_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
/***************************************************************************** 
* Include
*****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#include "gpiosrvgprot.h"
#include "CharBatSrvGProt.h"
#include "BootupSrvGprot.h"
#include "GlobalResDef.h"
#include "USBSrvIprot.h"
#include "USBSrvGprot.h"
}
#endif
#include "Vapp_usb_usbmode.h"
#include "../xml/vfx_xml_loader.h"
#include "mmi_rp_vapp_usbmmi_def.h"
#include "Vdat_systime.h"
#include "Vcp_global_popup.h"
#ifndef __LOW_COST_SUPPORT_COMMON__
#include "vcp_content_clone.h"

#ifdef __VENUS_3D_UI_ENGINE__
#include "vfx_shader.h"
#include "vfx_material.h"
#include "vfx_pass.h"
#include "vfx_polygon_mode.h"
#include "vfx_compositing_mode.h"
#include "vfx_blender.h"
#endif
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifndef __MMI_USB_SLIM__
/* For time calculate*/
#define CLOCK_TIME_12HOUR   12
#define CLOCK_TIME_MAX_LEN  10
#define CLOCK_TIME_SEC_PER_MIN  60
#define CLOCK_TIME_MIN_PER_HOUR 60
#define CLOCK_TIME_HOUR_PER_DAY 24
/* Time position*/
#define CLOCK_TIME_EMPTY_TEXT   "00:00"
#if defined(__MMI_MAINLCD_320X480__)
#define CLOCK_TIME_TEXT_Y   68
#define CLOCK_TIME_TEXT_SIZE    50//20
#define TIME_TYPE_TEXT_SIZE 16
#define TIME_TEXT_GAP_X 2
#elif defined(__MMI_MAINLCD_480X800__)
#define CLOCK_TIME_TEXT_Y   112
#define CLOCK_TIME_TEXT_SIZE    80
#define TIME_TYPE_TEXT_SIZE 26
#define TIME_TEXT_GAP_X 8
#elif defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__)
#define CLOCK_TIME_TEXT_Y   50
#define CLOCK_TIME_TEXT_SIZE    38
#define TIME_TYPE_TEXT_SIZE 13
#define TIME_TEXT_GAP_X 2

#else
#define CLOCK_TIME_TEXT_Y   68
#define CLOCK_TIME_TEXT_SIZE    50//
#define TIME_TYPE_TEXT_SIZE 16
#define TIME_TEXT_GAP_X 2
#endif
/* State text position*/
#define STATE_TEXT_SIZE 20
#define STATE_TEXT_GAP_Y    85
#endif
/* Battery position*/
#if defined(__MMI_MAINLCD_320X480__)
#define BAT_ICON_WIDTH  121
#define BAT_ICON_HEIGHT  57
#define BAT_ICON_DIST_TO_TIME_TEXT  104
#define BAT_ICON_REFLECTION_GAP_Y   0
#define BAT_ICON_REFLECT_OFFSET (0)
#elif defined(__MMI_MAINLCD_480X800__)
#define BAT_ICON_WIDTH  205
#define BAT_ICON_HEIGHT  100
#define BAT_ICON_DIST_TO_TIME_TEXT  169
#define BAT_ICON_REFLECTION_GAP_Y   0
#define BAT_ICON_REFLECT_OFFSET (4)
#elif defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__)
#define BAT_ICON_WIDTH  93
#define BAT_ICON_HEIGHT  45
#define BAT_ICON_DIST_TO_TIME_TEXT  58
#define BAT_ICON_REFLECTION_GAP_Y   0
#define BAT_ICON_REFLECT_OFFSET (2)
#else
#define BAT_ICON_WIDTH  121
#define BAT_ICON_HEIGHT  57
#define BAT_ICON_DIST_TO_TIME_TEXT  104
#define BAT_ICON_REFLECTION_GAP_Y   0
#define BAT_ICON_REFLECT_OFFSET (0)
#endif


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
VappUSBModeContext* VappUSBModeContext::m_inst = NULL;

/***************************************************************************** 
 * Function
 *****************************************************************************/

void VappUSBModeContext::initContext(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODECONTEXT_INITCONTEXT);
}

#ifndef __MMI_USB_SLIM__
void VappUSBModeContext::clockTimeHdlr(void *p)
{
    VappUSBModeContext *inst;
    mmi_eq_clock_tick_ind_struct *data = (mmi_eq_clock_tick_ind_struct*)p;

    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODECONTEXT_CLOCKTIMEHDLR);
    
    inst = VappUSBModeContext::getInst();
    if (!inst)
    {
        return;
    }

    inst->updateClock(data->rtc_time.rtc_hour, data->rtc_time.rtc_min);
}

void VappUSBModeContext::updateClock(VfxU8 h, VfxU8 m)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODECONTEXT_UPDATECLOCK, h, m);
    
    if (m_usbModeScrn)
    {
        m_usbModeScrn->updateTime(h, m);
    }
}
#endif

void VappUSBModeContext::MSModeConfirmCallback(VfxId id, void *userData)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        srv_usb_start_ms_shutdown();
        srv_usb_set_status(SRV_USBSTATUS_MS_PROC);
    }
    else if (id == VCP_CONFIRM_POPUP_BUTTON_USER_2)
    {
    }
}

MMI_BOOL VappUSBModeContext::ShowMSModeCallback(mmi_scenario_id scen_id, void *arg)
{
    MSModeConfirm();
    return MMI_TRUE;
}

void VappUSBModeContext::ShowMSMode(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODECONTEXT_SHOWMSMODE);
    srv_usb_set_status(SRV_USBSTATUS_MS_PROC);
}

void VappUSBModeContext::MSModeConfirm(void)
{
    vcp_global_popup_show_confirm_two_button_id(
        GRP_ID_ROOT,
        VCP_POPUP_TYPE_QUESTION, 
        STR_ID_VAPP_USB_CONFIG_MS_ONLY, 
        STR_GLOBAL_YES,
        STR_GLOBAL_NO,
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        VCP_POPUP_BUTTON_TYPE_CANCEL,
        &VappUSBModeContext::MSModeConfirmCallback,
        NULL
        );
}

VappUSBModeContext* VappUSBModeContext::getInst(void)
{
    return VappUSBModeContext::m_inst;
}

VfxU8 VappUSBModeContext::getChargingLevel(void)
{
    VfxU8 level;

    level = srv_charbat_get_battery_level();

    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODECONTEXT_GETCHARGINGLEVEL, level);

    if (level < SRV_CHARBAT_BATTERY_LEVEL_1)
        return 0;
    else
        return level - SRV_CHARBAT_BATTERY_LEVEL_1;
}

void VappUSBModeContext::showScreen(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODECONTEXT_SHOWSCREEN);

    updateChargingState();
    
    VFX_OBJ_CREATE(m_usbModeScrn, VappUSBModeScrn, getParent());
    m_usbModeScrn->updateChargingState(m_chargingMode, VappUSBModeContext::getChargingLevel());
    m_usbModeScrn->show();
    m_usbModeScrn->m_closeSingal.connect(this, &VappUSBModeContext::onScrnClose);
}

void VappUSBModeContext::closeScreen(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODECONTEXT_CLOSESCREEN);
    if (m_usbModeScrn)
        m_usbModeScrn->exit();
}

void VappUSBModeContext::updateChargingState(VfxU16 status, VfxU8 level)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODECONTEXT_UPDATECHARGINGSTATE, status, level);
    
    switch(status)
    {
        case PMIC_OVERCHARGECURRENT:
        case PMIC_INVALID_CHARGER:
        case PMIC_CHARGING_TIMEOUT:
        case PMIC_LOWCHARGECURRENT:
        case PMIC_CHARGE_BAD_CONTACT:
			{
				if(m_chargingMode == CHARGING_STATE_ERROR)
				{
				  return;
				}
			    else
				{
            m_chargingMode = CHARGING_STATE_ERROR;
			    }
            break;
        	}
            
            
        case PMIC_CHARGE_COMPLETE:
            m_chargingMode = CHARGING_STATE_COMPLETED;
            break;

        case PMIC_USB_CHARGER_IN:
        case PMIC_CHARGER_IN:
            m_chargingMode = CHARGING_STATE_CHARGING;
            break;

        case PMIC_CHARGER_OUT:
        case PMIC_USB_CHARGER_OUT:
        case PMIC_USB_NO_CHARGER_IN:
        case PMIC_USB_NO_CHARGER_OUT:
            m_chargingMode = CHARGING_STATE_NONE;
            break;

        case PMIC_VBAT_STATUS:
			{
				if(m_chargingMode == CHARGING_STATE_ERROR)
				{
				 return;
				}
			    else
			    {
            break;
			    }
        	}
            
        default:
            return;
    }
    if (m_usbModeScrn)
        m_usbModeScrn->updateChargingState(m_chargingMode, level);
}

void VappUSBModeContext::updateChargingState(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODECONTEXT_UPDATECHARGINGSTATE_NO_PARAM);
    
    if (srv_charbat_is_charging())
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_CHARGING);
        m_chargingMode = CHARGING_STATE_CHARGING;
    }
    else
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_NOT_CHARGING);
        m_chargingMode = CHARGING_STATE_COMPLETED;
    }
    if (m_usbModeScrn)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_SCRN_EXISTS, srv_charbat_get_battery_level());
        m_usbModeScrn->updateChargingState(m_chargingMode, getChargingLevel());
    }
}
void VappUSBModeContext::onScrnClose(void)
{
    m_closeSingal.emit();
}


void VappUSBModeScrn::on1stReady()
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODESCRN_ON1STREADY);
    
    VfxMainScr::on1stReady();

    // create and display first page
    VFX_OBJ_CREATE(m_page, VappUSBModePage, this);

    m_page->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_page->setImgContent(VfxImageSrc(IMG_ID_VAPP_USB_USBMODE_BG));
    m_page->m_closeSignal.connect(this, &VappUSBModeScrn::onPageClose);
    #ifndef __MMI_USB_SLIM__
    updateTime();
	VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappUSBModeScrn::onTimeChanged);
    #endif
    setCharging();
    pushPage(0, m_page);
}

void VappUSBModeScrn::onDeinit()
{
    VfxMainScr::onDeinit();
    #ifndef __MMI_USB_SLIM__

    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.disconnect(this, &VappUSBModeScrn::onTimeChanged);
    #endif
}
#ifndef __MMI_USB_SLIM__
void VappUSBModeScrn::updateTime(VfxU8 hour, VfxU8 min)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODESCRN_UPDATETIME, hour, min);
    
    m_hour = hour;
    m_min = min;

    setTime();
}

void VappUSBModeScrn::updateTime(void)
{
    VfxU32 h, m, s;
    VfxDateTime datetime;

    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODESCRN_UPDATETIME_NO_PARAM);
    
    datetime.setCurrentTime();
    datetime.getTime(&h, &m, &s);
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_SHOW_TIME, h, m, s);
    
    updateTime((VfxU8)h, (VfxU8)m);
}
void VappUSBModeScrn::setTime(void)
{
    VfxU8 hour;
    time_type_enum type;

    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODESCRN_SETTIME);
    
    if (m_page)
    {
        if (m_timeFormat == SETTING_TIME_FORMAT_12_HOURS)
        {
            if (m_hour >= CLOCK_TIME_12HOUR)
            {
                type = TIME_TYPE_PM;
                hour = m_hour - CLOCK_TIME_12HOUR;
            }
            else
            {
                type = TIME_TYPE_AM;
                hour = m_hour;
            }
            if (hour == 0)
            {
                hour = CLOCK_TIME_12HOUR;
            }
        }
        else
        {
            hour = m_hour;
            type = TIME_TYPE_NONE;
        }

        m_page->updateTime(hour, m_min, type);
    }
}
void VappUSBModeScrn::onTimeChanged(VfxU32 flag)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODESCRN_ONTIMECHANGED, flag);
    
    if ((flag & VDAT_SYSTIME_CHANGED_MIN))
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_HOUR_MIN, m_hour, m_min);
        
        m_min++;
        if (m_min >= CLOCK_TIME_MIN_PER_HOUR)
        {
            m_min = 0;
            m_hour++;
        }
        if (m_hour >= CLOCK_TIME_HOUR_PER_DAY)
        {
            m_hour = 0;
        }
        
        updateTime(m_hour, m_min);
    }
}

#endif

void VappUSBModeScrn::updateChargingState(charging_state_enum state, VfxU8 level)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODESCRN_UPDATECHARGINGSTATE, state, level);
    
    m_chargingState = state;
    if (m_chargingState != CHARGING_STATE_ERROR)
    {
        if (level < SRV_CHARBAT_BATTERY_LEVEL_1)
        {
            m_chargingLevel = 0;
        }
        else
        {
            m_chargingLevel = level - SRV_CHARBAT_BATTERY_LEVEL_1;
        }
    }
    setCharging();
    if (state == CHARGING_STATE_ERROR)
        showErrorPopup();
}

void VappUSBModeScrn::setCharging(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODESCRN_SETCHARGING);
    if (m_page)
    {
        m_page->updateCharging(m_chargingState, m_chargingLevel);
    }
}

void VappUSBModeScrn::showErrorPopup(void)
{
    VcpConfirmPopup *popup;
    
    VFX_OBJ_CREATE(popup, VcpConfirmPopup, this);
    popup->setInfoType(VCP_POPUP_TYPE_WARNING);
    popup->setText(STR_ID_VAPP_USB_CHARGING_ERROR);
    popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    popup->setAutoDestory(VFX_FALSE);
    popup->m_signalButtonClicked.connect(this, &VappUSBModeScrn::onAlertClicked);
    popup->show(VFX_TRUE);
}

void VappUSBModeScrn::onAlertClicked(VfxObject* sender, VfxId id)
{
    //sender->close();
}
void VappUSBModeScrn::onPageClose(void)
{
    m_closeSingal.emit();
}


void VappUSBModePage::onInit()
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODEPAGE_ONINIT);
    
    VfxPage::onInit(); // call base class

    /* Page size*/
    VfxSize size = getSize();

    setStatusBar(VFX_FALSE);
    #ifndef __MMI_USB_SLIM__
    /* Time text*/
    VFX_OBJ_CREATE(m_timeFrame, VfxTextFrame, this);

    m_timeFrame->setFullLineHeightMode(VFX_FALSE);
    m_timeFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(CLOCK_TIME_TEXT_SIZE), VFX_FONT_DESC_ATTR_NORMAL));
	m_timeFrame->setString(STR_ID_VAPP_USB_INIT_TIME);
    m_timeFrame->setColor(VFX_COLOR_WHITE);
    m_timeFrame->setAnchor(VfxFPoint(0, 1));

    /* Time type*/
    VFX_OBJ_CREATE(m_timeTypeFrame, VfxTextFrame, this);

    m_timeTypeFrame->setFullLineHeightMode(VFX_FALSE);
    m_timeTypeFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TIME_TYPE_TEXT_SIZE), VFX_FONT_DESC_ATTR_NORMAL));
    m_timeTypeFrame->setString(STR_ID_VAPP_USB_AM);
    m_timeFrame->setColor(VFX_COLOR_WHITE);
    m_timeTypeFrame->setAnchor(VfxFPoint(0, 1));

    VfxS32 x;
    VfxS32 y;
    
    if (srv_setting_get_time_format() == SETTING_TIME_FORMAT_12_HOURS)
    {
        x = (size.width - m_timeFrame->getSize().width - m_timeTypeFrame->getSize().width -TIME_TEXT_GAP_X) / 2;
    }
    else
    {
        x = (size.width - m_timeFrame->getSize().width -TIME_TEXT_GAP_X) / 2;
    }
    
    y = CLOCK_TIME_TEXT_Y + m_timeFrame->getSize().height;    
    m_timeFrame->setPos(x,y);
    
    x = m_timeFrame->getPos().x + m_timeFrame->getSize().width + TIME_TEXT_GAP_X;
    m_timeTypeFrame->setPos(x, y);
    #endif
    /* Charging state*/
    //VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);

    /* Charging animation*/
    VFX_OBJ_CREATE(m_imageFrame, VappUSBBatIcon, this);
    m_imageFrame->setPos((size.width - BAT_ICON_WIDTH) / 2, size.height/2);
    m_imageFrame->setSize(BAT_ICON_WIDTH,
        BAT_ICON_HEIGHT);
    #ifndef __MMI_USB_SLIM__
    setTexts();
    #endif
    setImage();

#ifndef __LOW_COST_SUPPORT_COMMON__

    /* */
#if defined(__VENUS_3D_UI_ENGINE__)
    VfxMaterial *mat;
    VFX_OBJ_CREATE_EX(mat, VfxMaterial, m_imageFrame, (2));

    // pass 0
    VfxPass *pass;
    VFX_OBJ_CREATE(pass, VfxPass, mat);
    mat->setPass(0, pass);

    // pass 1
    VFX_OBJ_CREATE(pass, VfxPass, mat);
    mat->setPass(1, pass);

    // Shader
    VfxShaderProgram *sp;
    VFX_OBJ_CREATE_EX(sp, VfxShaderProgram, pass, (VS_ID_VAPP_USB_REFLECTION, FS_ID_VAPP_USB_REFLECTION));
    pass->setShaderProgram(sp);

    VfxCompositingMode *comp;
    VFX_OBJ_CREATE(comp, VfxCompositingMode, pass);
    pass->setCompositingMode(comp);

    VfxBlender *blender;
    VFX_OBJ_CREATE(blender, VfxBlender, comp);
    comp->setBlender(blender);

    m_imageFrame->setMaterial(mat);

#elif !defined(__MMI_VUI_COSMOS_CP_SLIM__)
    VcpContentClone *reflect;
    VfxS32 refWdith;
    VfxS32 refHeight;

    refWdith = m_imageFrame->getSize().width;
    refHeight = m_imageFrame->getSize().height / 2;
    
    VFX_OBJ_CREATE(reflect, VcpContentClone, this);

    reflect->setPos(m_imageFrame->getPos().x, 
        m_imageFrame->getPos().y + m_imageFrame->getSize().height + BAT_ICON_REFLECTION_GAP_Y);
    reflect->setSize(refWdith, refHeight);
    reflect->setTargetFrame(m_imageFrame);
    reflect->setFilterType(VCP_CONTENT_CLONE_FILTER_TYPE_GRADIENT_REFLECTION);
    reflect->setIsOpaque(VFX_TRUE);
    reflect->setBgColor(VFX_COLOR_BLACK);
    reflect->setOutputAlpha(VFX_TRUE);
    reflect->setTargetRect(
        VfxRect(0, (refHeight - BAT_ICON_REFLECT_OFFSET), refWdith, (refHeight - BAT_ICON_REFLECT_OFFSET)));
    reflect->setHidden(VFX_FALSE);
#endif
#endif
	srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

}

void VappUSBModePage::updateCharging(charging_state_enum state, VfxU8 level)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODEPAGE_UPDATECHARGING, state, level);
    m_chargingState = state;
    m_level = level;

    setChargingIcon();
}
#ifndef __MMI_USB_SLIM__
void VappUSBModePage::updateTime(VfxU8 hour, VfxU8 min, time_type_enum type)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODEPAGE_UPDATETIME, hour, min, type);
    m_hour = hour;
    m_min = min;
    m_timeType = type;
    setTime();
    setTimeType();
}

void VappUSBModePage::setTexts(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODEPAGE_SETTEXTS);
    setTime();
    setTimeType();
}

void VappUSBModePage::setTime(void)
{
    VfxWChar time[CLOCK_TIME_MAX_LEN + 1];

    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODEPAGE_SETTIME);
       
    if (m_timeFrame)
    {
        kal_wsprintf(time, "%02d:%02d", m_hour, m_min);
        m_timeFrame->setString(time);
    }
}

void VappUSBModePage::setTimeType(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODEPAGE_SETTIMETYPE);
    
    if (m_timeTypeFrame)
    {
        switch(m_timeType)
        {
            case TIME_TYPE_NONE:
                m_timeTypeFrame->setString(VFX_WSTR_EMPTY);
                break;
                
            case TIME_TYPE_AM:
                m_timeTypeFrame->setString(STR_ID_VAPP_USB_AM);
                break;
                
            case TIME_TYPE_PM:
                m_timeTypeFrame->setString(STR_ID_VAPP_USB_PM);
                break;
                
            default:
                break;
        }

        if (m_timeFrame)
        {
            VfxS32 x;

            x = m_timeFrame->getPos().x + m_timeFrame->getSize().width + TIME_TEXT_GAP_X;
            m_timeTypeFrame->setPos(x, m_timeTypeFrame->getPos().y);
        }
    }
}
#endif

void VappUSBModePage::setImage(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODEPAGE_SETIMAGE);    
    setChargingIcon();
}

void VappUSBModePage::setChargingIcon(void)
{
    VappUSBBatIcon::StateEnum state;

    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODEPAGE_SETCHARGINGICON);
    
    if (m_imageFrame)
    {
        switch(m_chargingState)
        {
            case CHARGING_STATE_CHARGING:
                state = VappUSBBatIcon::STATE_BLINK;
                break;
                
            case CHARGING_STATE_NONE:
            case CHARGING_STATE_ERROR:
            case CHARGING_STATE_COMPLETED:
            default:
                state = VappUSBBatIcon::STATE_STATIC;
                break;
        }
        
        if (m_chargingState == CHARGING_STATE_COMPLETED)
        {
            m_level = VappUSBBatIcon::LEVEL_3;
        }
        m_imageFrame->update(state, (VappUSBBatIcon::LevelEnum)m_level);
    }
}

VfxBool VappUSBModePage::onKeyInput(VfxKeyEvent &event)
{
    VfxKeyCodeEnum keyCode;
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBMODEPAGE_ONKEYINPUT);

    keyCode = event.keyCode;

    if (keyCode == VFX_KEY_CODE_POWER ||
        keyCode == VFX_KEY_CODE_END)
    {
        if (mmi_frm_kbd_is_key_supported(KEY_POWER) == MMI_TRUE)
        {
            if (keyCode != VFX_KEY_CODE_POWER)
            {
                return VFX_TRUE;
            }
        }
        else
        {
            if (keyCode != VFX_KEY_CODE_END)
            {
                return VFX_TRUE;
            }
        }
        
        if (event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS)
        {
            switch(srv_bootup_get_booting_mode())
            {
                case SRV_BOOTUP_MODE_PRECHARGE:
                case SRV_BOOTUP_MODE_CHARGE:
                    srv_charbat_reset_pwron();
                    m_closeSignal.emit();
                    break;

                case SRV_BOOTUP_MODE_USB:
                    srv_usb_app_reset_poweron();
                    break;

                default:
                    break;
            }
            
            return VFX_TRUE;
        }
        else
        {
            return VFX_TRUE;
        }
    }
    else if (event.keyCode == VFX_KEY_CODE_HOME)
    {
        return VFX_TRUE;
    }
	else if (event.keyCode == VFX_KEY_CODE_BACK)
	{
		return VFX_TRUE;
	}

    return VfxPage::onKeyInput(event);
}

#endif /* __MMI_USB_SUPPORT__*/
