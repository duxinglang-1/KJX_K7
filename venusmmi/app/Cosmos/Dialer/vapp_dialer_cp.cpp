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
 *  vapp_dialer_cp.cpp
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#include "vcp_form.h"
#include "vapp_dialer_cp.h"
#include "vfx_adp_device.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "resource_audio.h"
#include "ProfilesSrvGprot.h"
#include "PhbSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "NwUsabSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "mmi_rp_cui_dialer_def.h"
#include "mmi_rp_vapp_dialer_def.h"
#include "mmi_rp_vapp_calllog_def.h"
#include "mmi_rp_vapp_contact_def.h"
#include "mmi_rp_app_cosmos_global_def.h"

#ifdef __cplusplus
}
#endif

#include "vadp_v2p_input_server.h"
#include "vapp_sim_setting_gprot.h"
#include "vapp_contact_storage.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
void * Vcp_dialer_pad_g;

/***************************************************************************** 
 * Function
 *****************************************************************************/

/***************************************************************************** 
 * Class VcpImageButtonLongPress
 *****************************************************************************/
VfxBool VcpImageButtonLongPress::onPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_LONG_TAP)
    {
        m_longPressed.postEmit(this, getId());
    }

    return VcpImageButton::onPenInput(event);
}


/***************************************************************************** 
 * Class DialerLayout
 *****************************************************************************/
void DialerLayout::initClassicDialer()
{
#if defined(__MMI_MAINLCD_480X800__)
    m_keypadLeftMargin = 7;
    m_keypadKeyWidth = 152;
    m_keypadMiddleWidthMargin = 5;
    m_keypadRightMargin = 7;

    m_keypadUpMargin = 16;
    m_keypadKeyHeight = 68;
    m_keypadMiddleHeightMargin = 4;
    m_keypadDownMargin = 8;

    m_editLeftMargin = 8;
    m_editContactWidth = 70;
    m_editBoxWidth = 310;
    m_editBoxBackSpaceMargin = 8;
    m_editBackSpaceWidth = 70;
    m_editRightMargin = 7;

    m_editUpMargin = 16;
    m_editBoxHeight = 66;
    m_editDownMargin = 0;
#elif defined(__MMI_MAINLCD_320X480__)
    m_keypadLeftMargin = 4;
    m_keypadKeyWidth = 103;
    m_keypadMiddleWidthMargin = 2;
    m_keypadRightMargin = 3;

    m_keypadUpMargin = 5;
    m_keypadKeyHeight = 44;
    m_keypadMiddleHeightMargin = 2;
    m_keypadDownMargin = 1;

    m_editLeftMargin = 5;
    m_editContactWidth = 40;
    m_editBoxWidth = 226;
    m_editBoxBackSpaceMargin = 3;
    m_editBackSpaceWidth = 40;
    m_editRightMargin = 3;

    m_editUpMargin = 7;
    m_editBoxHeight = 39;
    m_editDownMargin = 5;
#else
#if defined(__MMI_DIALER_SLIM__) && defined(__MMI_MAINLCD_240X320__)
    m_keypadLeftMargin = 2;
#else
    m_keypadLeftMargin = 4;  
#endif 
    m_keypadKeyWidth = 77;
#if defined(__MMI_DIALER_SLIM__) && defined(__MMI_MAINLCD_240X320__)
    m_keypadMiddleWidthMargin = 2;
#else
    m_keypadMiddleWidthMargin = 1;
#endif
    m_keypadRightMargin = 3;

    m_keypadUpMargin = 4;
#if defined(__MMI_MAINLCD_240X320__)
#ifdef __MMI_DIALER_SLIM__
    m_keypadKeyHeight = 39;
#else
    m_keypadKeyHeight = 29;
#endif
    m_keypadMiddleHeightMargin = 2;
    m_keypadDownMargin = 1;

    m_editLeftMargin = 3;
#ifdef __MMI_DIALER_SLIM__
    m_editContactWidth = 35;
#else
    m_editContactWidth = 33;
#endif
    m_editBoxWidth = 164;
    m_editBoxBackSpaceMargin = 2;
#ifndef __MMI_DIALER_SLIM__
    m_editBackSpaceWidth = 35;
#else
    m_editBackSpaceWidth = 33;
#endif
    m_editRightMargin = 2;

    m_editUpMargin = 4;
#ifndef __MMI_DIALER_SLIM__
    m_editBoxHeight = 34;
#else
    m_editBoxHeight = 32;
#endif
    m_editDownMargin = 3;
#endif
#endif
}


void DialerLayout::initEditBeforeCall()
{
#if defined(__MMI_MAINLCD_480X800__)
    m_keypadLeftMargin = 13;
    m_keypadKeyWidth = 148;
    m_keypadMiddleWidthMargin = 5;
    m_keypadRightMargin = 13;

    m_keypadUpMargin = 16;
    m_keypadKeyHeight = 68;
    m_keypadMiddleHeightMargin = 4;
    m_keypadDownMargin = 10;

    m_editLeftMargin = 14;
    m_editContactWidth = 0;
    m_editBoxWidth = 379;
    m_editBoxBackSpaceMargin = 9;
    m_editBackSpaceWidth = 66;
    m_editRightMargin = 12;

    m_editUpMargin = 54;
    m_editBoxHeight= 66;
    m_editDownMargin = 8;
#elif defined(__MMI_MAINLCD_320X480__)
    m_keypadLeftMargin = 8;
    m_keypadKeyWidth = 100;
    m_keypadMiddleWidthMargin = 2;
    m_keypadRightMargin = 8;

    m_keypadUpMargin = 7;
    m_keypadKeyHeight = 44;
    m_keypadMiddleHeightMargin = 2;
    m_keypadDownMargin = 7;

    m_editLeftMargin = 9;
    m_editContactWidth = 0;
    m_editBoxWidth = 260;
    m_editBoxBackSpaceMargin = 3;
    m_editBackSpaceWidth = 40;
    m_editRightMargin = 8;

    m_editUpMargin = 34;
    m_editBoxHeight= 39;
    m_editDownMargin = 5;
#else
    m_keypadLeftMargin = 7;
    m_keypadKeyWidth = 74;
    m_keypadMiddleWidthMargin = 2;
    m_keypadRightMargin = 7;

    m_keypadUpMargin = 5;
    m_keypadKeyHeight = 34;
    m_keypadMiddleHeightMargin = 2;
    m_keypadDownMargin = 5;

    m_editLeftMargin = 8;
    m_editContactWidth = 0;
    m_editBoxWidth = 188;
    m_editBoxBackSpaceMargin = 3;
    m_editBackSpaceWidth = 34;
    m_editRightMargin = 7;

    m_editUpMargin = 28;
    m_editBoxHeight= 33;
    m_editDownMargin = 4;
#endif
}


#ifdef __MMI_VIDEO_TELEPHONY__
/***************************************************************************** 
 * Class VcpDialerButtonContent
 *****************************************************************************/
VcpDialerButtonContent::VcpDialerButtonContent()
{
    m_frmText = NULL;
    m_dialFrame = NULL;
    m_string = VFX_WSTR_NULL;
    m_imageId = 0;
}


VcpDialerButtonContent::VcpDialerButtonContent(const VfxWString &value, VfxS32 id)
{
    m_frmText = NULL;
    m_dialFrame = NULL;
    m_string = value;
    m_imageId = id;
    m_layout.initClassicDialer();
}


void VcpDialerButtonContent::onInit()
{
    VfxFrame::onInit();

    VFX_OBJ_CREATE(m_frmText, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_dialFrame, VfxImageFrame, this);

    m_dialFrame->setAnchor(0, 0.5);
    m_dialFrame->setPos(0, m_layout.m_keypadKeyHeight / 2);
    m_dialFrame->setSize(m_dialerImageHeight, m_dialerImageHeight);
    m_dialFrame->setResId(m_imageId);

    m_frmText->setString(m_string);
#if defined(__MMI_MAINLCD_480X800__)
    m_frmText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(30)));
#elif defined(__MMI_MAINLCD_320X480__)
    m_frmText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(18)));
#else
    m_frmText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(16)));
#endif
    m_frmText->setAnchor(0, 0.5);
    m_frmText->setIsUnhittable(VFX_TRUE);
    m_frmText->setPos(m_dialerImageHeight + 5, m_layout.m_keypadKeyHeight / 2);
    m_frmText->setSize((m_layout.m_keypadKeyWidth - m_dialerImageHeight) / 2, m_layout.m_keypadKeyHeight);
}


VfxU32 VcpDialerButtonContent::getWidth()
{
    return m_dialerImageHeight + 5 + m_frmText->getBounds().getWidth();
}


void VcpDialerButtonContent::setIsDisabled(VfxBool value)
{
    if (value)
    {
         m_frmText->setOpacity(0.3f);
         m_dialFrame->setOpacity(0.3f);
    }
}
#endif /* __MMI_VIDEO_TELEPHONY__ */


/***************************************************************************** 
 * Class VcpGroupButton
 *****************************************************************************/
VcpGroupButton::VcpGroupButton(DialBtnLayout layout, VcpGroupButtonTypeEnum type, mmi_sim_enum sim_type)
{
    m_videoCall = MMI_FALSE;
    m_layout = layout;
    m_type = type;
    m_preferSIM = sim_type;
}


mmi_sim_enum VcpGroupButton::getSingleInsertSIM()
{
    for (mmi_sim_enum i = MMI_SIM1; i <= MMI_SIM4; i = (mmi_sim_enum)(i<<1))
    {
        if (srv_sim_ctrl_is_inserted(i))
        {
            return i;
        }
    }

    return MMI_SIM_NONE;
}


void VcpGroupButton::onInit()
{
    VfxControl::onInit();

    m_simNum = srv_sim_ctrl_get_num_of_inserted();

    if (m_simNum == 0)
    {
        m_type = VCP_BUTTON_EMERGENCY;
    }
    else if (m_simNum == 1)
    {
        m_preferSIM = getSingleInsertSIM();
    }

    if (m_type == VCP_BUTTON_EMERGENCY)
    {
        m_simNum = 0;
        VFX_OBJ_CREATE(m_btnEmergencyCall, VcpImageButton, this);
    }

    if (m_type == VCP_BUTTON_SIM1 || m_type == VCP_BUTTON_SIM2 || m_type == VCP_BUTTON_SIM3 || m_type == VCP_BUTTON_SIM4)
    {
        m_simNum = 1;
        m_videoCall = MMI_FALSE;
    }

    if (m_type == VCP_BUTTON_ALL_TYPE)
    {
    #ifdef __MMI_VIDEO_TELEPHONY__
        m_videoCall = MMI_TRUE;
    #endif
    }

    if (m_simNum > 0)
    {
        VFX_OBJ_CREATE(m_callButton, VcpComboButton, this);
    }

    if (m_videoCall)
    {
    #ifdef __MMI_VIDEO_TELEPHONY__
        VFX_OBJ_CREATE(m_btnVideoCall, VcpImageButton, this);
        VFX_OBJ_CREATE_EX(m_videoFrame, VcpDialerButtonContent, m_btnVideoCall, (VFX_WSTR_RES(STR_GLOBAL_DIAL), IMG_ID_VAPP_CLOG_DETAIL_CALL_VIDEO));
    #endif /* __MMI_VIDEO_TELEPHONY__ */
    }

    placeComponent();
    setComponentAction();
}


void VcpGroupButton::setBtnStype(VcpGroupButton::VcpGroupButtonTypeEnum type)
{
    m_type = type;
}


mmi_sim_enum VcpGroupButton::getPreferSIM()
{
    if (m_preferSIM != MMI_SIM_NONE && srv_sim_ctrl_is_inserted(m_preferSIM))
    {
        return m_preferSIM;
    }

    VfxU8 value;
    VfxS16 error;
    ReadValue(NVRAM_DIALER_PREFER_SIM, &value, DS_BYTE, &error);
    if (value != MMI_SIM1 && value != MMI_SIM2 && value != MMI_SIM3 && value != MMI_SIM4 && value != MMI_SIM_NONE)
    {
        value = MMI_SIM1;
    }

    if (value != MMI_SIM_NONE && srv_sim_ctrl_is_inserted((mmi_sim_enum)value))
    {
        return (mmi_sim_enum)value;
    }
    else
    {
        return MMI_SIM_NONE;
    }
}


void VcpGroupButton::setPreferSIM(mmi_sim_enum type)
{
    m_preferSIM = type;
}


VcpGroupButton::VcpGroupButtonTypeEnum VcpGroupButton::getPreferType(mmi_sim_enum sim_type)
{
    switch (sim_type)
    {
        case MMI_SIM1:
            return VCP_BUTTON_SIM1;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
            return VCP_BUTTON_SIM2;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
            return VCP_BUTTON_SIM3;
    #if (MMI_MAX_SIM_NUM >= 4)
        case MMI_SIM4:
            return VCP_BUTTON_SIM4;
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        default:
            VFX_ASSERT(0);
            break;
    }

    return VCP_BUTTON_NONE;
}


void VcpGroupButton::placeVideoCall()
{
#ifdef __MMI_VIDEO_TELEPHONY__
    if (m_videoCall)
    {
        m_btnVideoCall->setRect(VfxRect(
                    #if defined(__MMI_MAINLCD_480X800__) || defined(__MMI_MAINLCD_320X480__)
                        LCD_WIDTH - m_layout.m_dialRightMargin - (LCD_WIDTH - m_layout.m_dialLeftMargin - m_layout.m_dialRightMargin - 2 * m_layout.m_dialerGapMargin) / 3,
                    #else
                        LCD_WIDTH - m_layout.m_dialRightMargin - (LCD_WIDTH - m_layout.m_dialLeftMargin - m_layout.m_dialRightMargin - 2 * m_layout.m_dialerGapMargin) / 3 - 2,
                    #endif
                        m_layout.m_dialerUpMargin,
                    #if defined(__MMI_MAINLCD_480X800__) || defined(__MMI_MAINLCD_320X480__)
                        (LCD_WIDTH - m_layout.m_dialLeftMargin - m_layout.m_dialRightMargin - 2 * m_layout.m_dialerGapMargin) / 3,
                    #else
                        (LCD_WIDTH - m_layout.m_dialLeftMargin - m_layout.m_dialRightMargin - 2 * m_layout.m_dialerGapMargin) / 3 + 4,
                    #endif
                        m_layout.m_dialerBtnHeight));
        m_btnVideoCall->setImage(VcpStateImage(IMG_ID_DIALER_VIDEO_CALL, IMG_ID_DIALER_VIDEO_CALL_PRESS, IMG_ID_DIALER_VIDEO_CALL_DISABLE, IMG_ID_DIALER_VIDEO_CALL));
        m_btnVideoCall->setIsStretchMode(VFX_TRUE);
        //m_btnVideoCall->setIsHapticTouchEnabled(VFX_TRUE);

        m_videoFrame->setAnchor(0.5, 0);
        m_videoFrame->setPos((LCD_WIDTH - m_layout.m_dialLeftMargin - m_layout.m_dialRightMargin - 2 * m_layout.m_dialerGapMargin) / 6, 0);
        m_videoFrame->setSize(m_videoFrame->getWidth(), m_layout.m_dialerBtnHeight);
        if (!srv_sim_ctrl_is_inserted(MMI_SIM1))
        {
            m_btnVideoCall->setIsDisabled(VFX_TRUE);
            m_videoFrame->setIsDisabled(VFX_TRUE);
        }
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */
}


void VcpGroupButton::placeCallButton()
{
#if defined(__MMI_MAINLCD_480X800__) || defined(__MMI_MAINLCD_320X480__)
    m_callButton->setPos(m_layout.m_dialLeftMargin + 1, m_layout.m_dialerUpMargin);
#else
    m_callButton->setPos(m_layout.m_dialLeftMargin, m_layout.m_dialerUpMargin);
#endif
    if (m_type == VCP_BUTTON_ALL_TYPE && m_videoCall)
    {
        m_callButton->setSize(
            #if defined(__MMI_MAINLCD_480X800__)
                (LCD_WIDTH - m_layout.m_dialRightMargin - m_layout.m_dialLeftMargin - 2 * m_layout.m_dialerGapMargin) / 3 * 2 + m_layout.m_dialerGapMargin - 3,
            #elif defined(__MMI_MAINLCD_320X480__)
                (LCD_WIDTH - m_layout.m_dialRightMargin - m_layout.m_dialLeftMargin - 2 * m_layout.m_dialerGapMargin) / 3 * 2 + m_layout.m_dialerGapMargin,
            #else
                (LCD_WIDTH - m_layout.m_dialRightMargin - m_layout.m_dialLeftMargin - 2 * m_layout.m_dialerGapMargin) / 3 * 2 + m_layout.m_dialerGapMargin + 2,
            #endif
                m_layout.m_dialerBtnHeight);
        placeVideoCall();
    }
    else
    {
        m_callButton->setSize(
            #if defined(__MMI_MAINLCD_480X800__) || defined(__MMI_MAINLCD_320X480__)
                LCD_WIDTH - m_layout.m_dialRightMargin - m_layout.m_dialLeftMargin - 2,
            #else
                LCD_WIDTH - m_layout.m_dialRightMargin - m_layout.m_dialLeftMargin,
            #endif
                m_layout.m_dialerBtnHeight);
    }

    //m_callButton->setText(VFX_WSTR_RES(STR_GLOBAL_DIAL));
    m_callButton->setText(STR_GLOBAL_DIAL);
    m_callButton->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_TEXT_CENTER);

    if (srv_sim_ctrl_get_num_of_inserted() > 1)
    {
        if (getPreferSIM() != MMI_SIM_NONE)
        {
            m_callButton->setHintText(vapp_sim_settings_get_sim_name(getPreferSIM()));
            m_callButton->setImage(VcpStateImage(ContactSim::getCallIconId(getPreferSIM())));
        }
        else
        {
            m_callButton->setHintText(VFX_WSTR_EMPTY);
            m_callButton->setImage(VcpStateImage(IMG_COSMOS_GEMINI_SIM_CALL));
        }
    }
    else
    {
        m_callButton->setImage(VcpStateImage(IMG_COSMOS_GEMINI_SIM_CALL));
    }

    if (getPreferSIM() != MMI_SIM_NONE && !(srv_mode_switch_get_current_mode() & getPreferSIM()))
    {
        m_callButton->setIsOnlyMainBtnDisabled(VFX_TRUE);
    }
    else
    {
        m_callButton->setIsOnlyMainBtnDisabled(VFX_FALSE);
    }
    
    if (getPreferSIM() == MMI_SIM_NONE && srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF)
    {
        m_callButton->setIsOnlyMainBtnDisabled(VFX_TRUE);
    }
    
    if (m_type == VCP_BUTTON_ALL_TYPE && m_simNum > 2)
    {
        m_callButton->setHasChildBtn(VFX_TRUE);
        m_callButton->setChildButtonIcon(VcpStateImage(IMG_COSMOS_GEMINI_BUTTON_SIM));
        m_callButton->setHasChildBtn(VFX_TRUE);
        if (srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF)
        {
            m_callButton->setChildIsDisabled(VFX_TRUE);
        }
    }
    else if (m_type == VCP_BUTTON_ALL_TYPE && m_simNum == 2)
    {
        m_callButton->setHasChildBtn(VFX_TRUE);
        m_callButton->setChildIsDisabled(VFX_FALSE);
        if (getPreferSIM() == MMI_SIM_NONE)
        {
            m_callButton->setChildButtonIcon(VcpStateImage(IMG_COSMOS_GEMINI_BUTTON_SIM));
            if (srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF)
            {
                m_callButton->setChildIsDisabled(VFX_TRUE);
            }
        }
        else
        {
            for (VfxU32 i = 0; i < MMI_MAX_SIM_NUM; i++)
            {
                mmi_sim_enum sim = mmi_frm_index_to_sim(i);
                if (srv_sim_ctrl_is_inserted(sim) && sim != getPreferSIM())
                {
                    m_callButton->setChildButtonIcon(VcpStateImage(ContactSim::getCallIconId(sim)));
                    if (!(srv_mode_switch_get_current_mode() & sim))
                    {
                        m_callButton->setChildIsDisabled(VFX_TRUE);
                        break;
                    }
                }
            }
        }
    }
    else
    {
        if (srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF)
        {
            m_callButton->setIsDisabled(VFX_TRUE);
        }
        else
        {
            m_callButton->setIsDisabled(VFX_FALSE);
        }
        m_callButton->setHasChildBtn(VFX_FALSE);
    }
}


void VcpGroupButton::placeComponent()
{
    if (m_type == VCP_BUTTON_EMERGENCY)
    {
        m_btnEmergencyCall->setRect(VfxRect(m_layout.m_dialLeftMargin,
                                m_layout.m_dialerUpMargin,
                                LCD_WIDTH - m_layout.m_dialLeftMargin - m_layout.m_dialRightMargin,
                                m_layout.m_dialerBtnHeight));
        m_btnEmergencyCall->setImage(VcpStateImage(IMG_ID_DIALER_EMERGENCY, IMG_ID_DIALER_EMERGENCY_PRESS, IMG_ID_DIALER_EMERGENCY_DISABLE, IMG_ID_DIALER_EMERGENCY));
        m_btnEmergencyCall->setIsStretchMode(VFX_TRUE);

        VfxTextFrame *m_frmText;
        VFX_OBJ_CREATE(m_frmText, VfxTextFrame, this);
       // m_frmText->setString(VFX_WSTR_RES(STR_ID_VAPP_DIALER_EMERGENCY));
        m_frmText->setString(STR_ID_VAPP_DIALER_EMERGENCY);
    #if defined(__MMI_MAINLCD_480X800__)
        m_frmText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(32)));
    #elif defined(__MMI_MAINLCD_320X480__)
        m_frmText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(22)));
    #else
        m_frmText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(16)));
    #endif
        m_frmText->setAnchor(0.5, 0.5);
        m_frmText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        m_frmText->setIsUnhittable(VFX_TRUE);
        m_frmText->setRect(VfxRect(m_layout.m_dialLeftMargin,
                        m_layout.m_dialerUpMargin,
                        LCD_WIDTH - m_layout.m_dialLeftMargin - m_layout.m_dialRightMargin,
                        m_layout.m_dialerBtnHeight));
    }
    else
    {
        placeCallButton();
    }
}


void VcpGroupButton::setComponentAction()
{
    if (m_type == VCP_BUTTON_EMERGENCY)
    {
        m_btnEmergencyCall->m_signalClicked.connect(this, &VcpGroupButton::onEmergencyClick);
    }
    else
    {
        m_callButton->m_signalChildBtnClicked.connect(this, &VcpGroupButton::onChildBtnClick);
        m_callButton->m_signalClicked.connect(this, &VcpGroupButton::onBtnClick);
    #ifdef __MMI_VIDEO_TELEPHONY__
        if (m_videoCall)
        {
            m_btnVideoCall->m_signalClicked.connect(this, &VcpGroupButton::onVideoClick);
        }
    #endif /* __MMI_VIDEO_TELEPHONY__ */
    }
}


void VcpGroupButton::onChildBtnClick(VcpButton* obj, VfxId id)
{
    if (m_simNum == 2 && getPreferSIM() != MMI_SIM_NONE)
    {
        for (mmi_sim_enum i = MMI_SIM1; i <= MMI_SIM4; i = (mmi_sim_enum)(i<<1))
        {
            if (srv_sim_ctrl_is_inserted(i) && (getPreferSIM() != i))
            {
                m_signalCallButtonPress.postEmit(getPreferType(i));
                return;
            }
        }
    }
    else
    {
        simChoosePopup();
    }
}


void VcpGroupButton::onBtnClick(VfxObject *obj, VfxId id)
{
    if (m_type != VCP_BUTTON_ALL_TYPE)
    {
        m_signalCallButtonPress.postEmit(m_type);
        return;
    }
    if (getPreferSIM() == MMI_SIM_NONE)
    {
        if (srv_sim_ctrl_get_num_of_inserted() == 1)
        {
            for (VfxU32 i = 0; i < MMI_MAX_SIM_NUM; i++)
            {
                if (srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(i)))
                {
                    m_signalCallButtonPress.postEmit(getPreferType(mmi_frm_index_to_sim(i)));
                    return;
                }
            }
        }
        simChoosePopup();
        return;
    }
    m_signalCallButtonPress.postEmit(getPreferType(getPreferSIM()));
}


#ifdef __MMI_VIDEO_TELEPHONY__
void VcpGroupButton::onVideoClick(VfxObject *obj, VfxId id)
{
    m_signalCallButtonPress.postEmit(VCP_BUTTON_VIDEO_CALL);
}
#endif /* __MMI_VIDEO_TELEPHONY__ */


void VcpGroupButton::onEmergencyClick(VfxObject *obj, VfxId id)
{
    m_signalCallButtonPress.postEmit(VCP_BUTTON_EMERGENCY);
}


void VcpGroupButton::simChoosePopup()
{
    VFX_OBJ_CREATE(m_menu, VcpMenuPopup, this);
    //m_menu->setTitle(VFX_WSTR_RES(STR_ID_VAPP_PHB_SELECT_SIM));
    m_menu->setTitle(STR_ID_VAPP_PHB_SELECT_SIM);
    for (VfxU32 i = 0; i < MMI_MAX_SIM_NUM; i++)
    {
        mmi_sim_enum sim = mmi_frm_index_to_sim(i);
        if (srv_sim_ctrl_is_inserted(sim))
        {
            if (getPreferSIM() == sim)
            {
                continue;
            }

            VfxId btnId = sim;
            //m_menu->addItem(btnId, VFX_WSTR_RES(VAPP_PHB_STR_CALL), ContactSim::getCallIcon(sim), VCP_MENU_POPUP_ITEM_TYPE_2);
            m_menu->addItem(btnId, VAPP_PHB_STR_CALL, ContactSim::getCallIcon(sim), VCP_MENU_POPUP_ITEM_TYPE_2);
            ((VcpMenuPopupItemType2 *)m_menu->getItemById(btnId))->setHintText(vapp_sim_settings_get_sim_name(sim));
            if (!(srv_mode_switch_get_current_mode() & sim))
            {
                m_menu->getItemById(btnId)->setIsDisabled(VFX_TRUE);
            }
        }
    }
    m_menu->m_signalMenuCallback.connect(this, &VcpGroupButton::onMenuClick);
    m_menu->show(VFX_TRUE);
}


void VcpGroupButton::onMenuClick(VcpMenuPopup* menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item)
{
    if (event == VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
    {
        m_signalCallButtonPress.postEmit(getPreferType((mmi_sim_enum)(item->getId())));
    }
}


void VcpGroupButton::refleshComboBtn()
{
    if (m_type != VCP_BUTTON_EMERGENCY)
    {
        placeCallButton();
    }
}


/***************************************************************************** 
 * Class VcpDialerPad
 *****************************************************************************/
VcpDialerPad::VcpDialerPad(VappDialerTypeEnum type, mmi_sim_enum sim_type)
{
    m_type = type;
    m_simType = sim_type;
    m_dialerPlus = NULL;
}


void VcpDialerPad::onInit()
{
    VfxControl::onInit();
   /* VFX_OBJ_CREATE(m_timer, VfxTimer, this);
    m_timer->setStartDelay(450);
    m_timer->setDuration(450);
    m_timer->m_signalTick.connect(this, &VcpDialerPad::onTimerNotify);*/
    Vcp_dialer_pad_g = this;

    setLayoutType();
    setBG();

#if defined(__MMI_DIALER_SLIM__) && defined(__MMI_MAINLCD_240X320__)
        for (VfxS32 i = VCP_BUTTON_DIALER_1; i < VCP_BUTTON_DIALER_END; i++)
        {
            VFX_OBJ_CREATE(m_btnDialer[i], VcpImageButtonLongPress, this);
            VFX_OBJ_CREATE(m_dialerText[i], VfxTextFrame, m_btnDialer[i]);
            if (m_type == VCP_DIALER_CLASSIC || m_type == VCP_DIALER_NEW_CALL)
            {
                VFX_OBJ_CREATE(m_dialerSubText[i], VfxTextFrame, m_btnDialer[i]);
    
            }
#ifdef __MMI_PHB_SPEED_DIAL__
            if (i >= VCP_BUTTON_DIALER_2 && i <= VCP_BUTTON_DIALER_9)
            {
                m_speedDial[i] = NULL;
            }
#endif /* __MMI_PHB_SPEED_DIAL_SUPPORT__ */
        }
#else   
    
        for (VfxS32 i = VCP_BUTTON_DIALER_1; i < VCP_BUTTON_DIALER_END; i++)
        {
            if (m_type == VCP_DIALER_CLASSIC || m_type == VCP_DIALER_NEW_CALL)
            {
                VFX_OBJ_CREATE(m_btnDialer[i], VcpImageButtonLongPress, this);
                VFX_OBJ_CREATE(m_dialerImage[i],  VfxControl, m_btnDialer[i]);
#ifdef __MMI_PHB_SPEED_DIAL__
                if (i >= VCP_BUTTON_DIALER_2 && i <= VCP_BUTTON_DIALER_9)
                {
                    m_speedDial[i] = NULL;
                }
#endif /* __MMI_PHB_SPEED_DIAL_SUPPORT__ */
            }
            else
            {
                VFX_OBJ_CREATE(m_btnDialer[i], VcpImageButtonLongPress, this);
                VFX_OBJ_CREATE(m_dialerText[i], VfxTextFrame, m_btnDialer[i]);
            }  
        }     
#endif

    VFX_OBJ_CREATE(m_btnBackSpace, VcpImageButtonLongPress, this);
    VFX_OBJ_CREATE(m_btnSaveToContact, VcpButton, this);
    VFX_OBJ_CREATE(m_editBox, VcpTextEditor, this);
    memset(m_inputBuffer, 0x00, sizeof(m_inputBuffer));
    m_isLongPress = VFX_FALSE;

    titleInit();
    setDialBtn();
    placeComponent();
    setComponentAction();
}   


void VcpDialerPad::refleshDialer()
{
#ifdef __MMI_PHB_SPEED_DIAL__
    placeSpeedDialList();
#endif /* __MMI_PHB_SPEED_DIAL__ */
    if (m_type != VCP_DIALER_NEW_CALL)
    {
        m_dialButton->setPreferSIM(getPreferSIM());
        m_dialButton->refleshComboBtn();
    }
}


void VcpDialerPad::registerExtraControl()
{
    //VFX_OBJ_GET_INSTANCE(VadpInputServerUI)->registerExtraControl(this);
}


void VcpDialerPad::unRegisterExtraControl()
{
    //VFX_OBJ_GET_INSTANCE(VadpInputServerUI)->unRegisterExtraControl(this);
}


void VcpDialerPad::titleInit()
{
    if (m_type != VCP_DIALER_CLASSIC && m_type != VCP_DIALER_NEW_CALL)
    {
        VFX_OBJ_CREATE(m_titleText, VfxTextFrame, this);
        m_titleText->setAnchor(0.5f, 0.5f);
        m_titleText->setPos(LCD_WIDTH / 2, m_layout.m_editUpMargin / 2);
        m_titleText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        m_titleText->setColor(VFX_COLOR_WHITE);

        if (m_type == VCP_DIALER_EDIT_BEFORE_CALL)
        {
           // m_titleText->setString(VFX_WSTR_RES(STR_GLOBAL_EDIT_BEFORE_CALL));
            m_titleText->setString(STR_GLOBAL_EDIT_BEFORE_CALL);
        }
        else if (m_type == VCP_DIALER_EMERGENCY)
        {
            //m_titleText->setString(VFX_WSTR_RES(STR_ID_VAPP_DIALER_EMERGENCY));
            m_titleText->setString(STR_ID_VAPP_DIALER_EMERGENCY);
        }
    #if defined(__MMI_MAINLCD_480X800__)
        m_titleText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(25)));
    #elif defined(__MMI_MAINLCD_320X480__)
        m_titleText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(18)));
    #else
        m_titleText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(14)));
    #endif
    }
}


VcpTextEditor * VcpDialerPad::getEditBox()
{
    return m_editBox;
}


void VcpDialerPad::placeDialer()
{
    for (VfxS32 i = VCP_BUTTON_DIALER_1; i < VCP_BUTTON_DIALER_END; i++)
    {
        m_btnDialer[i]->setRect(VfxRect(
            m_layout.m_keypadLeftMargin + (i % 3) * (m_layout.m_keypadKeyWidth + m_layout.m_keypadMiddleWidthMargin),
            m_layout.m_editUpMargin + m_layout.m_editBoxHeight + m_layout.m_editDownMargin + m_layout.m_keypadUpMargin + (i / 3) * (m_layout.m_keypadKeyHeight + m_layout.m_keypadMiddleHeightMargin),
            m_layout.m_keypadKeyWidth,
            m_layout.m_keypadKeyHeight));
        m_btnDialer[i]->setId(i);
        m_btnDialer[i]->setImage(
        VcpStateImage(IMG_ID_DIALER_KEY_BUTTON,
                      IMG_ID_DIALER_KEY_BUTTON_PRESS,
                      IMG_ID_DIALER_KEY_BUTTON_DISABLE,
                      IMG_ID_DIALER_KEY_BUTTON));
        m_btnDialer[i]->setIsStretchMode(VFX_TRUE);
    }
    
    for (VfxS32 i = VCP_BUTTON_DIALER_1; i < VCP_BUTTON_DIALER_END; i++)
    {
   #if defined (__MMI_MAINLCD_240X320__) && defined (__MMI_DIALER_SLIM__)

        m_dialerText[i]->setAnchor(0.5f, 0.5f);
        m_dialerText[i]->setPos(m_btnDialer[i]->getSize().width/2, 
        m_btnDialer[i]->getSize().height/2);
    
        m_dialerText[i]->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        m_dialerText[i]->setColor(VCP_FORM_DARK_FONT_COLOR);
        m_dialerText[i]->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(21)));
        if (m_type == VCP_DIALER_CLASSIC || m_type == VCP_DIALER_NEW_CALL)
        {
            m_dialerSubText[i]->setAnchor(0.5f, 0.5f);
            m_dialerSubText[i]->setPos(m_btnDialer[i]->getSize().width-16, 
            m_btnDialer[i]->getSize().height - 16);
            m_dialerSubText[i]->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
            m_dialerSubText[i]->setColor(VCP_FORM_DARK_FONT_COLOR);
            m_dialerSubText[i]->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(12)));
        }  
    #else
        {
            if (m_type == VCP_DIALER_CLASSIC || m_type == VCP_DIALER_NEW_CALL)
            {
                m_dialerImage[i]->setRect(VfxRect(
                    0,
                    0,
                    m_layout.m_keypadKeyWidth,
                    m_layout.m_keypadKeyHeight));
            }
            else
            {
                m_dialerText[i]->setAnchor(0.5f, 0.5f);
                m_dialerText[i]->setPos(m_btnDialer[i]->getSize().width/2, m_btnDialer[i]->getSize().height/2);
                m_dialerText[i]->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
                m_dialerText[i]->setColor(VCP_FORM_DARK_FONT_COLOR);
            #if defined(__MMI_MAINLCD_480X800__)
                m_dialerText[i]->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(42)));
            #elif defined(__MMI_MAINLCD_320X480__)
                m_dialerText[i]->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(28)));
            #else
                m_dialerText[i]->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(21)));
            #endif
            } 
        }
    #endif
  }
#if defined (__MMI_MAINLCD_240X320__) && defined (__MMI_DIALER_SLIM__)

    for (VfxS32 i = VCP_BUTTON_DIALER_1; i <= VCP_BUTTON_DIALER_9; i++)
    {
           VfxWString str;
           str.format("%d", i + 1);
           m_dialerText[i]->setString(str);
           if (i != VCP_BUTTON_DIALER_1 && (m_type == VCP_DIALER_CLASSIC || m_type ==  VCP_DIALER_NEW_CALL))
           {
                VfxWString substr = 'a ', ssubstr;
                   
               VfxS32 k;
               if(i== VCP_BUTTON_DIALER_7 || i== VCP_BUTTON_DIALER_9)
               {
                   k=3;
               }
               else 
               {
                   k=2;
               }
               for(VfxS32 j = 0; j <= k;j++)
               {
                   substr.format("%c", 'a' + 3 * (i-1) + j );
                   if (i== VCP_BUTTON_DIALER_8 || i== VCP_BUTTON_DIALER_9)
                   {
                       substr.format("%c",'a' + 3 * (i-1) + j + 1);
                   }
                   ssubstr += substr ;
                   //VfxWString().format("%c", index);
                  
               }
                m_dialerSubText[i]->setString(ssubstr);
            }
    }
 
#else 
       if (m_type == VCP_DIALER_CLASSIC || m_type == VCP_DIALER_NEW_CALL)
        {
            for (VfxS32 i = VCP_BUTTON_DIALER_1; i <= VCP_BUTTON_DIALER_9; i++)
            {
                m_dialerImage[i]->setImgContent(VfxImageSrc(IMG_ID_DIALER_KEY1 + i - VCP_BUTTON_DIALER_1));
            }
            m_dialerImage[VCP_BUTTON_DIALER_STAR]->setImgContent(VfxImageSrc(IMG_ID_DIALER_STAR));
            m_dialerImage[VCP_BUTTON_DIALER_0]->setImgContent(VfxImageSrc(IMG_ID_DIALER_KEY0));
            m_dialerImage[VCP_BUTTON_DIALER_POUND]->setImgContent(VfxImageSrc(IMG_ID_DIALER_POUND));
        }
        else
        {
            for (VfxS32 i = VCP_BUTTON_DIALER_1; i <= VCP_BUTTON_DIALER_9; i++)
            {
                VfxWString str;
                str.format("%d", i + 1);
                m_dialerText[i]->setString(str);
            }
        }

#endif /* (__MMI_MAINLCD_240X320__) && defined (__MMI_DIALER_SLIM_SEARCH__) */

       if (m_dialerPlus == NULL)
        {
            VFX_OBJ_CREATE(m_dialerPlus, VfxTextFrame, m_btnDialer[VCP_BUTTON_DIALER_0]);
         #if defined(__MMI_DIALER_SLIM__) && defined(__MMI_MAINLCD_240X320__)
            if(m_type == VCP_DIALER_CLASSIC || m_type == VCP_DIALER_NEW_CALL )
            {
                m_dialerPlus->setPos(m_btnDialer[VCP_BUTTON_DIALER_0]->getSize().width - 24, m_btnDialer[VCP_BUTTON_DIALER_0]->getSize().height-24 );
            }
            else
            {
                m_dialerPlus->setPos(m_btnDialer[VCP_BUTTON_DIALER_0]->getSize().width/2+ 8, 0);

            }
         #else 
            m_dialerPlus->setPos(m_btnDialer[VCP_BUTTON_DIALER_0]->getSize().width/2+ 8, 0);
         #endif
        #if defined(__MMI_MAINLCD_480X800__)
            m_dialerPlus->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(36)));
        #elif defined(__MMI_MAINLCD_320X480__)
            m_dialerPlus->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(23)));
        #else
            m_dialerPlus->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(18)));
        #endif
            m_dialerPlus->setColor(VCP_FORM_DARK_FONT_COLOR);
        #if defined(__MMI_DIALER_SLIM__) && defined(__MMI_MAINLCD_240X320__)
            m_dialerPlus->setString(VFX_WSTR("+"));
        #else
            if(m_type != VCP_DIALER_CLASSIC && m_type != VCP_DIALER_NEW_CALL)
            {
                m_dialerPlus->setString(VFX_WSTR("+"));
            }
        #endif
        }
     #if defined(__MMI_DIALER_SLIM__) && defined(__MMI_MAINLCD_240X320__)
            m_dialerText[VCP_BUTTON_DIALER_STAR]->setString(VFX_WSTR("*"));
            m_dialerText[VCP_BUTTON_DIALER_0]->setString(VFX_WSTR("0"));
            m_dialerText[VCP_BUTTON_DIALER_POUND]->setString(VFX_WSTR("#"));
     #else
        if( m_type != VCP_DIALER_CLASSIC && m_type != VCP_DIALER_NEW_CALL)
        {
            m_dialerText[VCP_BUTTON_DIALER_STAR]->setString(VFX_WSTR("*"));
            m_dialerText[VCP_BUTTON_DIALER_0]->setString(VFX_WSTR("0"));
            m_dialerText[VCP_BUTTON_DIALER_POUND]->setString(VFX_WSTR("#"));

        }

     #endif
}


#ifdef __MMI_PHB_SPEED_DIAL__
void VcpDialerPad::placeSpeedDialList()
{
    if (m_type == VCP_DIALER_CLASSIC)
    {
        for (VfxS32 i = VCP_BUTTON_DIALER_2; i <= VCP_BUTTON_DIALER_9; i++)
        {
            if (srv_phb_speed_dial_is_sync(i - VCP_BUTTON_DIALER_2))
            {
                if (m_speedDial[i] == NULL)
                {
                    VFX_OBJ_CREATE(m_speedDial[i], VfxControl, m_btnDialer[i]);
                }
            #if defined(__MMI_MAINLCD_480X800__)
                m_speedDial[i]->setPos(m_layout.m_keypadKeyWidth - 20, 6);
            #elif defined(__MMI_MAINLCD_320X480__)
                m_speedDial[i]->setPos(m_layout.m_keypadKeyWidth - 14, 3);
            #else
                m_speedDial[i]->setPos(m_layout.m_keypadKeyWidth - 10, 2);
            #endif
                m_speedDial[i]->setSize(12, 12);
                m_speedDial[i]->setImgContent(VfxImageSrc(IMG_ID_DIALER_SPEED_DIAL_BALL));
            }
            else
            {
                if (m_speedDial[i] != NULL)
                {
                    VFX_OBJ_CLOSE(m_speedDial[i]);
                }
            }
        }
    }
}
#endif /* __MMI_PHB_SPEED_DIAL__ */


void VcpDialerPad::placeComponent()
{
    if (m_type == VCP_DIALER_CLASSIC || m_type == VCP_DIALER_NEW_CALL)
    {
        m_editBox->setRect(
            LCD_WIDTH / 2,
            m_layout.m_editUpMargin,
            m_layout.m_editBoxWidth,
            m_layout.m_editBoxHeight);
        m_editBox->setAnchor(0.5f, 0);
    }
    else
    {
        m_editBox->setRect(
            m_layout.m_editLeftMargin,
            m_layout.m_editUpMargin,
            m_layout.m_editBoxWidth,
            m_layout.m_editBoxHeight);
    }
    m_editBox->setIME(IMM_INPUT_TYPE_PHONE_NUMBER, (IME_DISABLE_VK | IME_DISABLE_CANDIDATE_BOX | IME_PLUS_CHAR_HANDLING));
    m_editBox->setText(m_inputBuffer, 40, VFX_TRUE, VCP_TEXT_ENCODING_UCS2, NULL);
    m_editBox->setMaxLength(MMI_PHB_NUMBER_LENGTH + 1);
    m_editBox->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
#if defined(__MMI_MAINLCD_480X800__)
    m_editBox->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(35)));
#elif defined(__MMI_MAINLCD_320X480__)
    m_editBox->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(24)));
#else
    m_editBox->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(18)));
#endif
    m_editBox->setAlignMode(VCP_TEXT_ALIGN_MODE_RIGHT);
    if (m_type == VCP_DIALER_EDIT_BEFORE_CALL)
    {
        m_editBox->setCursorIndex(0);
        //m_editBox->activate();
    }

    placeDialer();

    m_btnSaveToContact->setRect(
        m_layout.m_editLeftMargin,
        m_layout.m_editUpMargin,
        m_layout.m_editContactWidth,
        m_layout.m_editContactWidth);
    m_btnSaveToContact->setBgImageList(VcpStateImage(IMG_ID_DIALER_ADD_CONTACT, IMG_ID_DIALER_ADD_CONTACT_PRESS, IMG_ID_DIALER_ADD_CONTACT_DISABLE, IMG_ID_DIALER_ADD_CONTACT));
    m_btnSaveToContact->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    m_btnSaveToContact->setIsHapticTouchEnabled(VFX_TRUE);

    if (m_type == VCP_DIALER_NEW_CALL || mmi_wcslen(m_editBox->getText()) == 0)
    {
        m_btnSaveToContact->setIsDisabled(VFX_TRUE);
    }

    m_btnBackSpace->setRect(
        LCD_WIDTH - m_layout.m_editRightMargin - m_layout.m_editBackSpaceWidth,
        m_layout.m_editUpMargin,
        m_layout.m_editBackSpaceWidth,
        m_layout.m_editBackSpaceWidth);
    m_btnBackSpace->setImage(VcpStateImage(IMG_ID_DIALER_BACKSPACE, IMG_ID_DIALER_BACKSPACE_PRESS, IMG_ID_DIALER_BACKSPACE_DISABLE, IMG_ID_DIALER_BACKSPACE));
    m_btnBackSpace->setIsHapticTouchEnabled(VFX_TRUE);

    m_dialButton->setRect(
        0,
        m_layout.m_editUpMargin + m_layout.m_editBoxHeight + m_layout.m_editDownMargin + m_layout.m_keypadUpMargin + m_layout.m_keypadKeyHeight * 4 + m_layout.m_keypadMiddleHeightMargin * 3,
        LCD_WIDTH,
        m_layout.m_keypadKeyHeight + m_layout.m_keypadDownMargin);
}


void VcpDialerPad::setComponentAction()
{
    for (VfxS32 i = VCP_BUTTON_DIALER_1; i < VCP_BUTTON_DIALER_END; i++)
    {
        m_btnDialer[i]->m_signalClicked.connect(this, &VcpDialerPad::onBtnClick);
        m_btnDialer[i]->m_signalStateChanged.connect(this, &VcpDialerPad::onBtnStateChange);
        ((VcpImageButtonLongPress *)m_btnDialer[i])->m_longPressed.connect(this, &VcpDialerPad::onBtnLongPress);
    }
    m_btnBackSpace->m_signalStateChanged.connect(this, &VcpDialerPad::onBtnBackSpaceClick);
    m_btnBackSpace->m_longPressed.connect(this, &VcpDialerPad::onBackSpaceLongPress);
    m_btnSaveToContact->m_signalClicked.connect(this, &VcpDialerPad::onBtnSaveToContactClick);
    m_editBox->m_signalTextChanged.connect(this, &VcpDialerPad::onEditContentChange);
}


void VcpDialerPad::onBtnClick(VfxObject *obj, VfxId id)
{
    if (id == VCP_BUTTON_DIALER_POUND)
    {
        m_signalDialerPress.postEmit((VcpDialerPad::VcpDialerButtonTypeEnum)id, m_editBox->getText());
    }
    //m_editBox->setFocused(VFX_TRUE);
}


void VcpDialerPad::onBtnLongPress(VfxObject* obj, VfxId id)
{
    m_isLongPress = VFX_TRUE;
    if ((id == 0 || id > (VfxId)VCP_BUTTON_DIALER_1)
#ifdef __MMI_PHB_SPEED_DIAL__
&& id <= (VfxId)VCP_BUTTON_DIALER_9
#endif /* __MMI_PHB_SPEED_DIAL__ */
&& m_type == VCP_DIALER_CLASSIC)
    {
        m_signalDialerLongPress.emit((VcpDialerButtonTypeEnum)id, NULL);
    }

    srv_prof_stop_tone(SRV_PROF_TONE_KEYPAD);
    m_editBox->setFocused(VFX_TRUE);
    if (id == VCP_BUTTON_DIALER_0)
    {
        VfxKeyEvent event;
        event.type = VFX_KEY_EVENT_TYPE_LONG_PRESS;
        event.keyCode = getKeyCode(VCP_BUTTON_DIALER_0);
        m_editBox->processKeyInput(event);
        StopTimer(DIALER_LONG_PRESS_TIMER);
        StartTimer(DIALER_LONG_PRESS_TIMER, 450, VcpDialerPad::onTimerNotify);

        //m_timer->start();
    }
}


void VcpDialerPad::onTimerNotify()
{
    VcpDialerPad * obj = (VcpDialerPad*)Vcp_dialer_pad_g;
    obj->onTimerNotifyRepeat();
}


void VcpDialerPad::onTimerNotifyRepeat()
{
    VfxKeyEvent event;
    event.type = VFX_KEY_EVENT_TYPE_REPEAT;
    event.keyCode = getKeyCode((VfxId)VCP_BUTTON_DIALER_0);
    m_editBox->processKeyInput(event);
    StopTimer(DIALER_LONG_PRESS_TIMER);
    StartTimer(DIALER_LONG_PRESS_TIMER, 450, VcpDialerPad::onTimerNotify);
}


void VcpDialerPad::keyTonePlay(VcpImageButton* obj)
{
    srv_prof_keypad_tone_type_enum tone_type;
    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_KEYPAD_TONE_TYPE, (void *)&tone_type);
    if (tone_type != SRV_PROF_KEYPAD_SILENT)
    {
        VfxId id = obj->getId();
        if (getKeyCode(id) != VFX_KEY_CODE_UNKNOWN)
        {
            srv_prof_play_tone_with_id(SRV_PROF_TONE_KEYPAD, getToneID(id), SRV_PROF_RING_TYPE_ONCE, NULL);
        }
    }
}


void VcpDialerPad::onBtnStateChange(VcpImageButton* obj, VcpImageButtonStateEnum state)
{
    if (state == VCP_BUTTON_STATE_NORMAL)
    {
        srv_prof_stop_tone(SRV_PROF_TONE_KEYPAD);
        m_editBox->setFocused(VFX_TRUE);
        VfxId id = obj->getId();
    #ifdef __MMI_PHB_SPEED_DIAL__   
        if (!m_isLongPress)
        {
            if ((id == 0 ||id > (VfxId)VCP_BUTTON_DIALER_1 )&& id <= (VfxId)VCP_BUTTON_DIALER_9)
            {
                VfxWString str;
                str.format("%d", id + 1);
                m_editBox->insertText((VfxWChar *)str.getBuf());
            }
            else if (id == (VfxId)VCP_BUTTON_DIALER_STAR)
            {
                m_editBox->insertText('*');
            }
            else if (id == (VfxId)VCP_BUTTON_DIALER_0)
            {
                m_editBox->insertText('0');
            }
            else if (id == (VfxId)VCP_BUTTON_DIALER_POUND)
            {
                m_editBox->insertText('#');
            }
            m_isLongPress = VFX_FALSE;
        }
        else
    #else 
        if ((id == 0 ||id > (VfxId)VCP_BUTTON_DIALER_1 )&& id <= (VfxId)VCP_BUTTON_DIALER_9)
        {
            VfxWString str;
            str.format("%d", id + 1);
            m_editBox->insertText((VfxWChar *)str.getBuf());
        }
        else if (id == (VfxId)VCP_BUTTON_DIALER_STAR)
        {
            m_editBox->insertText('*');
        }
        else if (id == (VfxId)VCP_BUTTON_DIALER_0 && !m_isLongPress ) //&& !m_timer->getIsEnabled())
        {
            m_editBox->insertText('0');
        }
        else if (id == (VfxId)VCP_BUTTON_DIALER_POUND)
        {
            m_editBox->insertText('#');
        }
    #endif
    #ifndef __MMI_PHB_SPEED_DIAL__
        if(m_isLongPress)
    #endif
        {
            VfxKeyEvent event;
            event.type = VFX_KEY_EVENT_TYPE_UP;
            event.keyCode = getKeyCode(VCP_BUTTON_DIALER_0);
            m_editBox->processKeyInput(event);
        }
        //m_timer->stop();
        StopTimer(DIALER_LONG_PRESS_TIMER);
    }
    else if (state == VCP_BUTTON_STATE_PRESSED)
    {
        m_isLongPress = VFX_FALSE;
        keyTonePlay(obj);
        if (m_type != VCP_DIALER_NEW_CALL)
        {
            vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN_VIBRATE);
        }
    }
}


VfxKeyCodeEnum VcpDialerPad::getKeyCode(VfxId id)
{
    VfxKeyCodeEnum key;

    if ((id == 0 || id >(VfxId) VCP_BUTTON_DIALER_1 )&& id <= VCP_BUTTON_DIALER_9)
    {
        key = (VfxKeyCodeEnum) (VFX_KEY_CODE_1 + id - VCP_BUTTON_DIALER_1);
    }
    else if (id == VCP_BUTTON_DIALER_0)
    {
        key = VFX_KEY_CODE_0;
    }
    else if (id == VCP_BUTTON_DIALER_STAR)
    {
        key = VFX_KEY_CODE_STAR;
    }
    else if (id == VCP_BUTTON_DIALER_POUND)
    {
        key = VFX_KEY_CODE_POUND;
    }
    else
    {
        key = VFX_KEY_CODE_UNKNOWN;
    }

    return key;
}


VfxU16 VcpDialerPad::getToneID(VfxId id)
{
    VfxU16 result;

    if ((id == 0 || id >(VfxId) VCP_BUTTON_DIALER_1) && id <= VCP_BUTTON_DIALER_9)
    {
        result = TONE_DTMF_1 + id - VCP_BUTTON_DIALER_1;
    }
    else if (id == VCP_BUTTON_DIALER_0)
    {
        result = TONE_DTMF_0;
    }
    else if (id == VCP_BUTTON_DIALER_STAR)
    {
        result = TONE_KEY_STAR;
    }
    else if (id == VCP_BUTTON_DIALER_POUND)
    {
        result = TONE_KEY_HASH;
    }
    else
    {
        result = TONE_DTMF_0;
    }

    return result;
}


void VcpDialerPad::onBtnBackSpaceClick(VcpImageButton* btn, VcpImageButtonStateEnum state)
{
    m_editBox->setFocused(VFX_TRUE);
    if (state == VCP_IMAGE_BUTTON_STATE_NORMAL)
    {
        m_editBox->deleteChars();
    }
}


void VcpDialerPad::onBackSpaceLongPress(VfxObject *obj, VfxId id)
{
    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
    m_editBox->setFocused(VFX_TRUE);
    m_editBox->deleteAll();
}


void VcpDialerPad::onBtnSaveToContactClick(VfxObject *obj, VfxId id)
{
    m_signalSaveToContactClick.postEmit(m_editBox->getText());
}


void VcpDialerPad::onEditContentChange(VcpTextEditor *edit_box)
{
    m_signalDialerStringChanged.postEmit(edit_box);

    if (mmi_wcslen(edit_box->getText()) && m_type != VCP_DIALER_NEW_CALL)
    {
        m_btnSaveToContact->setIsDisabled(VFX_FALSE);
    }
    else
    {
        m_btnSaveToContact->setIsDisabled(VFX_TRUE);
    }
    if (m_type != VCP_DIALER_NEW_CALL)
    {
        m_dialButton->setPreferSIM(getPreferSIM());
        m_dialButton->refleshComboBtn();
    }
}


void VcpDialerPad::setLayoutType()
{
    if (m_type == VCP_DIALER_CLASSIC || m_type == VCP_DIALER_NEW_CALL)
    {
        m_layout.initClassicDialer();
    }
    else
    {
        m_layout.initEditBeforeCall();
    }
}


void VcpDialerPad::setBG()
{
    VfxImageFrame *edit_backgroup;
    VFX_OBJ_CREATE(edit_backgroup, VfxImageFrame, this);
    if (m_type == VCP_DIALER_CLASSIC || m_type == VCP_DIALER_NEW_CALL)
    {
        edit_backgroup->setResId(IMG_ID_DIALER_TEXT_BG01);
    }
    else
    {
        edit_backgroup->setResId(IMG_ID_DIALER_EDITOR_BG);
    }
    edit_backgroup->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    edit_backgroup->setPos(0, 0);
    edit_backgroup->setSize(
                        LCD_WIDTH,
                    #if defined(__MMI_MAINLCD_480X800__)
                        m_layout.m_editBoxHeight + m_layout.m_editUpMargin + m_layout.m_editDownMargin + 20);
                    #elif defined(__MMI_MAINLCD_320X480__)
                        m_layout.m_editBoxHeight + m_layout.m_editUpMargin + m_layout.m_editDownMargin + 15);
                    #else
                        m_layout.m_editBoxHeight + m_layout.m_editUpMargin + m_layout.m_editDownMargin + 8);
                    #endif

    VfxImageFrame *dialer_backgroup;
    VFX_OBJ_CREATE(dialer_backgroup, VfxImageFrame, this);
    if (m_type == VCP_DIALER_CLASSIC || m_type == VCP_DIALER_NEW_CALL)
    {
        dialer_backgroup->setResId(IMG_ID_DIALER_TEXT_BG02);
        dialer_backgroup->setPos(0, m_layout.m_editBoxHeight + m_layout.m_editUpMargin + m_layout.m_editDownMargin);
    }
    else
    {
        dialer_backgroup->setResId(IMG_ID_DIALER_KEYBOARD_BG);
    #if defined(__MMI_MAINLCD_480X800__)
        dialer_backgroup->setPos(0, m_layout.m_editBoxHeight + m_layout.m_editUpMargin + m_layout.m_editDownMargin);
    #elif defined(__MMI_MAINLCD_320X480__)
        dialer_backgroup->setPos(0, m_layout.m_editBoxHeight + m_layout.m_editUpMargin + m_layout.m_editDownMargin);
    #else
        dialer_backgroup->setPos(0, m_layout.m_editBoxHeight + m_layout.m_editUpMargin + m_layout.m_editDownMargin - 3);
    #endif
    }
    dialer_backgroup->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    dialer_backgroup->setSize(
                        LCD_WIDTH,
                        m_layout.m_keypadUpMargin + m_layout.m_keypadKeyHeight * 5 + m_layout.m_keypadMiddleHeightMargin * 4 + m_layout.m_keypadDownMargin);
}


mmi_sim_enum VcpDialerPad::getPreferSIM()
{
    mmi_sim_enum ret;
    srv_phb_get_preferred_sim(
            m_editBox->getText(),
            MMI_PHB_INVALID_CONTACT_ID,
            SRV_PHB_NUMBER_OP_TYPE_DIAL,
            &ret);
    return ret;
}


void VcpDialerPad::setDialBtn()
{
    DialBtnLayout layout;
    layout.m_dialerUpMargin = m_layout.m_keypadMiddleHeightMargin;
    layout.m_dialerBtnHeight = m_layout.m_keypadKeyHeight;
    layout.m_dialerDownMargin = m_layout.m_keypadDownMargin;
    layout.m_dialLeftMargin = m_layout.m_keypadLeftMargin;
    layout.m_dialRightMargin = m_layout.m_keypadRightMargin;
    layout.m_dialerGapMargin = m_layout.m_keypadMiddleWidthMargin;

    if (m_type == VCP_DIALER_CLASSIC || m_type == VCP_DIALER_EDIT_BEFORE_CALL)
    {
        VFX_OBJ_CREATE_EX(m_dialButton, VcpGroupButton, this, (layout, VcpGroupButton::VCP_BUTTON_ALL_TYPE, getPreferSIM()));
    }
    else if (m_type == VCP_DIALER_EMERGENCY)
    {
        VFX_OBJ_CREATE_EX(m_dialButton, VcpGroupButton, this, (layout, VcpGroupButton::VCP_BUTTON_EMERGENCY, MMI_SIM_NONE));
    }
    else if (m_type == VCP_DIALER_NEW_CALL)
    {
        VFX_OBJ_CREATE_EX(
            m_dialButton,
            VcpGroupButton,
            this,
            (layout, (VcpGroupButton::VcpGroupButtonTypeEnum) m_simType, m_simType));
    }
}


/*void VcpDialerPad::setBtnNormal()
{
    VFX_OBJ_CLOSE(m_btnDialer[0]);
    VFX_OBJ_CREATE(m_btnDialer[0], VcpImageButtonLongPress, this);
    VFX_OBJ_CREATE(m_dialerImage[0],  VfxControl, m_btnDialer[0]);

    m_btnDialer[0]->setRect(VfxRect(
            m_layout.m_keypadLeftMargin + (0 % 3) * (m_layout.m_keypadKeyWidth + m_layout.m_keypadMiddleWidthMargin),
            m_layout.m_editUpMargin + m_layout.m_editBoxHeight + m_layout.m_editDownMargin + m_layout.m_keypadUpMargin + (0 / 3) * (m_layout.m_keypadKeyHeight + m_layout.m_keypadMiddleHeightMargin),
            m_layout.m_keypadKeyWidth,
    m_layout.m_keypadKeyHeight));
    m_btnDialer[0]->setId(0);
    m_btnDialer[0]->setImage(
    VcpStateImage(IMG_ID_DIALER_KEY_BUTTON,
                  IMG_ID_DIALER_KEY_BUTTON_PRESS,
                  IMG_ID_DIALER_KEY_BUTTON_DISABLE,
                  IMG_ID_DIALER_KEY_BUTTON));
    m_btnDialer[0]->setIsStretchMode(VFX_TRUE);

    m_dialerImage[0]->setRect(VfxRect(
            0,
            0,
            m_layout.m_keypadKeyWidth,
            m_layout.m_keypadKeyHeight));
    m_dialerImage[0]->setImgContent(VfxImageSrc(IMG_ID_DIALER_KEY1));

    m_btnDialer[0]->m_signalClicked.connect(this, &VcpDialerPad::onBtnClick);
    m_btnDialer[0]->m_signalStateChanged.connect(this, &VcpDialerPad::onBtnStateChange);
    ((VcpImageButtonLongPress *)m_btnDialer[0])->m_longPressed.connect(this, &VcpDialerPad::onBtnLongPress);
}*/

