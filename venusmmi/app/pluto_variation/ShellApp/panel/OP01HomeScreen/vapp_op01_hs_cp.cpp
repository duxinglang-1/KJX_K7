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
 *  vapp_op01_hs_cp.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Internal UI componets of homescreen
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 /***************************************************************************** 
  * Include
  *****************************************************************************/
 
#include "MMI_features.h"
 
#ifdef __MMI_VUI_SHELL_OP01_HOMESCREEN__
 
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vcp_status_icon_bar.h"
#include "vdat_include.h"
#include "vadp_v2p_op01_hs.h"
#include "vapp_op01_hs_cp.h"
#include "mmi_rp_app_venus_shell_op01_hs_def.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __MMI_OP01_DCD_V30__
#include "DCDV30Gprot.h"
#include "mmi_rp_app_dcd_def.h"
#endif

#ifdef __cplusplus
}
#endif

#define OP01HS_TEXT_COLOR   VfxColor(255, 88, 88, 88)
#define OP01HS_TEXT_PRESSED_COLOR   VfxColor(255, 255, 222, 122) 


/*****************************************************************************
 * Class VappOp01HsNwInfo: network info class
 *****************************************************************************/
VappOp01HsNwInfo::VappOp01HsNwInfo() :
    m_nwNameText(NULL),
    m_nwStateText(NULL)
{
}

void VappOp01HsNwInfo::onInit()
{
    VfxFrame::onInit();

    VFX_OBJ_CREATE(m_nwNameText, VfxTextFrame, this);
    m_nwNameText->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_nwNameText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_nwNameText->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_MEDIUM, VFX_FONT_DESC_EFFECT_BORDER));
    m_nwNameText->setColor(VFX_COLOR_WHITE);
    m_nwNameText->setBorderColor(OP01HS_TEXT_COLOR);

    VFX_OBJ_CREATE(m_nwStateText, VfxTextFrame, this);
    m_nwStateText->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_nwStateText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_nwStateText->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_MEDIUM, VFX_FONT_DESC_EFFECT_BORDER));
    m_nwStateText->setColor(VFX_COLOR_WHITE);
    m_nwStateText->setBorderColor(OP01HS_TEXT_COLOR);
}

void VappOp01HsNwInfo::setNetworkName(const VfxWString &str)
{
    if (m_nwNameText)
    {
        m_nwNameText->setString(str);
        refineLayout();
    }
}

void VappOp01HsNwInfo::setNetworkStatus(const VfxWString &str)
{
    if (m_nwStateText)
    {
        m_nwStateText->setString(str);
        refineLayout();
    }
}

void VappOp01HsNwInfo::refineLayout()
{
    if (m_nwNameText->getString() && m_nwStateText->getString())
    {
        // Network name
        VfxRect bounds = m_nwNameText->getBounds();
        bounds.size.width = TWO_TEXT_WIDTH;
        m_nwNameText->setPos(0, 0);
        m_nwNameText->setBounds(bounds);
        

        // Network status
        bounds = m_nwStateText->getBounds();
        bounds.size.width = SINGLE_TEXT_WIDTH - TWO_TEXT_WIDTH;
        m_nwStateText->setPos(SECOND_TEXT_POS_X, 0);
        m_nwStateText->setBounds(bounds);
    }
    else
    {
        // Network name
        if (m_nwNameText->getString())
        {
            VfxRect bounds = m_nwNameText->getBounds();
            bounds.size.width = SINGLE_TEXT_WIDTH;
            m_nwNameText->setPos(0, 0);
            m_nwNameText->setBounds(bounds);
        }

        // Network status
        if (m_nwStateText->getString())
        {
            VfxRect bounds = m_nwStateText->getBounds();
            bounds.size.width = SINGLE_TEXT_WIDTH;
            m_nwStateText->setPos(0, 0);
            m_nwStateText->setBounds(bounds);
        }
    }
}


/********************************************************************************************* 
 * Class VappOp01HsIdleModeText: idle mode text class used for display SAT icon or song name
 ********************************************************************************************/

VappOp01HsIdleModeText::VappOp01HsIdleModeText() :
    m_idleModeText(NULL),
    m_idleModeIcon(NULL),
    m_idleModeStr(VFX_WSTR_NULL)
{
    m_bracketFrame[0] = NULL;
    m_bracketFrame[1] = NULL;
}

void VappOp01HsIdleModeText::onInit()
{
    VfxFrame::onInit();

    setBounds(VfxRect(0, 0, FRAME_WIDTH, FRAME_HEIGHT));

    VFX_OBJ_CREATE(m_idleModeIcon, VfxImageFrame, this);
    m_idleModeIcon->setPos(ICON_POS_X, ICON_POS_Y);
    m_idleModeIcon->setBounds(0, 0, ICON_WIDTH, ICON_WIDTH);
    m_idleModeIcon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    VFX_OBJ_CREATE(m_bracketFrame[0], VfxTextFrame, this);
    m_bracketFrame[0]->setAnchor(0.0f, 0.5f);
    m_bracketFrame[0]->setPos(BRACKET_POS_X1, FRAME_HEIGHT >> 1);
    m_bracketFrame[0]->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_MEDIUM, VFX_FONT_DESC_EFFECT_BORDER));
    m_bracketFrame[0]->setColor(VFX_COLOR_WHITE);
    m_bracketFrame[0]->setBorderColor(OP01HS_TEXT_COLOR);
    m_bracketFrame[0]->setString(VFX_WSTR("["));
    m_bracketFrame[0]->setHidden(VFX_TRUE);

    VFX_OBJ_CREATE(m_bracketFrame[1], VfxTextFrame, this);
    m_bracketFrame[1]->setAnchor(1.0f, 0.5f);
    m_bracketFrame[1]->setPos(BRACKET_POS_X2, FRAME_HEIGHT >> 1);
    m_bracketFrame[1]->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_MEDIUM, VFX_FONT_DESC_EFFECT_BORDER));
    m_bracketFrame[1]->setColor(VFX_COLOR_WHITE);
    m_bracketFrame[1]->setBorderColor(OP01HS_TEXT_COLOR);
    m_bracketFrame[1]->setString(VFX_WSTR("]"));
    m_bracketFrame[1]->setHidden(VFX_TRUE);

    VFX_OBJ_CREATE(m_idleModeText, VcpMarquee, this);
    m_idleModeText->setAnchor(0.5f, 0.5f);
    m_idleModeText->setPos(FRAME_WIDTH >> 1, FRAME_HEIGHT >> 1);
    m_idleModeText->setBounds(VfxRect(0, 0, TEXT_WIDTH, TEXT_HEIGHT));
    m_idleModeText->setTextColor(VFX_COLOR_WHITE, OP01HS_TEXT_COLOR);
    m_idleModeText->setHalign(VcpMarquee::HALIGN_CENTER);
    m_idleModeText->setSpeed(MARQUEE_SPEED);
}

void VappOp01HsIdleModeText::onDeinit()
{
    VfxFrame::onDeinit();
}

void VappOp01HsIdleModeText::setIdleModeText(const VfxWString &str)
{
    if (m_idleModeStr == str)
    {
        return;
    }
    
    if (str.isNull())
    {
        m_idleModeText->clearMovableFrame(); // stop scroll internally
        m_bracketFrame[0]->setHidden(VFX_TRUE);
        m_bracketFrame[1]->setHidden(VFX_TRUE);
    }
    else
    {
        m_idleModeText->setMovableFrame(str, VfxFontDesc(VFX_FONT_DESC_SIZE_MEDIUM, VFX_FONT_DESC_EFFECT_BORDER));
        m_idleModeText->startScroll();
        m_bracketFrame[0]->setHidden(VFX_FALSE);
        m_bracketFrame[1]->setHidden(VFX_FALSE);
    }

    m_idleModeStr = str;
}

void VappOp01HsIdleModeText::setIdleModeIcon(const VfxU8 *iconPtr)
{
    if (iconPtr == NULL)
    {
        m_idleModeIcon->setHidden(VFX_TRUE);
    }
    else
    {
        m_idleModeIcon->setHidden(VFX_FALSE);
        m_idleModeIcon->setImgContent(VfxImageSrc(iconPtr));
    }
}

/***************************************************************************** 
 * Home screen UI componet:  status icon class
 *****************************************************************************/

void VappHsStatusIcon::onInit()
{
    VfxControl::onInit();

    // set background image
    VfxImageFrame *bg_image;
    VFX_OBJ_CREATE(bg_image, VfxImageFrame, this);
    bg_image->setResId(VAPP_SHELL_IMG_OP01HS_STATUS_BAR);
    setBounds(bg_image->getBounds());

    // set statuc icon bar
    VcpStatusIconBar *icon_bar;
    VFX_OBJ_CREATE(icon_bar, VcpStatusIconBar, this);
    icon_bar->enableBackground(VFX_FALSE);
}

/*****************************************************************************
 * Class VappOp01HsHintBox: unread call/SMS/MMS info class
 *****************************************************************************/
VappOp01HsHintBox::VappOp01HsHintBox() :
    m_hintBoxBg(NULL),
    m_hintBoxIcon(NULL),
    m_hintStr(NULL),
    m_hintType(HINT_TYPE_NONE)
{
}

void VappOp01HsHintBox::onInit()
{
    VfxControl::onInit();

    VFX_OBJ_CREATE(m_hintBoxBg, VfxImageFrame, this);
    m_hintBoxBg->setPos(0, 0);
    m_hintBoxBg->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_HINT_BOX_NORMAL));

    VfxS32 posY = m_hintBoxBg->getBounds().size.height >> 1;

    VFX_OBJ_CREATE(m_hintBoxIcon, VfxImageFrame, this);
    m_hintBoxIcon->setPos(ICON_POS_X, posY);
    m_hintBoxIcon->setAnchor(0.0f, 0.5f);
    
    VFX_OBJ_CREATE(m_hintStr, VfxTextFrame, this);
    m_hintStr->setPos(TEXT_POS_X, posY);
    m_hintStr->setAnchor(0.5f, 0.5f);
    m_hintStr->setFont(VFX_FONT_DESC_MEDIUM);
    m_hintStr->setColor(VFX_COLOR_WHITE);

    VfxRect bounds = getBounds();
    bounds.size = m_hintBoxBg->getBounds().size;
    setBounds(bounds);
}

void VappOp01HsHintBox::setHintType(VappOP01HintTypeEnum type)
{
    m_hintType = type;

    switch (m_hintType)
    {
        case HINT_TYPE_CALL:
            m_hintBoxIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_MISSED_CALL_NORMAL));
            break;

        case HINT_TYPE_SMS:
            m_hintBoxIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_SMS_NORMAL));
            break;

        case HINT_TYPE_MMS:
            m_hintBoxIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_MMS_NORMAL));
            break;

        default:
            break;            
    }
}

void VappOp01HsHintBox::setHintState(VappOP01HintStateEnum state)
{
    if (state == HINT_STATE_NORMAL)
    {
        m_hintBoxBg->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_HINT_BOX_NORMAL));
        m_hintStr->setColor(VFX_COLOR_WHITE);
        switch (m_hintType)
        {
            case HINT_TYPE_CALL:
                m_hintBoxIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_MISSED_CALL_NORMAL));
                break;

            case HINT_TYPE_SMS:
                m_hintBoxIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_SMS_NORMAL));
                break;

            case HINT_TYPE_MMS:
                m_hintBoxIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_MMS_NORMAL));
                break;

            default:
                break;            
        }
    }
    else if (state == HINT_STATE_PRESSED)
    {
        m_hintBoxBg->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_HINT_BOX_PRESSED));
        m_hintStr->setColor(VFX_COLOR_BLACK);
        switch (m_hintType)
        {
            case HINT_TYPE_CALL:
                m_hintBoxIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_MISSED_CALL_PRESSED));
                break;

            case HINT_TYPE_SMS:
                m_hintBoxIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_SMS_PRESSED));
                break;

            case HINT_TYPE_MMS:
                m_hintBoxIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_MMS_PRESSED));
                break;

            default:
                break;            
        }
    }
}

void VappOp01HsHintBox::setHintStr(VfxS32 num)
{
    WCHAR strBuf[5];
    kal_wsprintf(strBuf, "%d", num);
    
    m_hintStr->setString(VFX_WSTR_MEM(strBuf));    
}

VfxBool VappOp01HsHintBox::onPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            setHintState(HINT_STATE_PRESSED);
            break;

        case VFX_PEN_EVENT_TYPE_UP:
        {
            VfxRect bounds = getBounds();
            if (bounds.contains(event.getRelPos(this)))
            {
                vfxPostInvoke0(this, &VappOp01HsHintBox::launchApp);
            }
            setHintState(HINT_STATE_NORMAL);
            break;
        }

        case VFX_PEN_EVENT_TYPE_MOVE:
        {
            VfxRect bounds = getBounds();
            if (bounds.contains(event.getRelPos(this)))
            {
                setHintState(HINT_STATE_PRESSED);
            }
            else
            {
                setHintState(HINT_STATE_NORMAL);
            }

            break;
        }

        default:
            break;
    }

    return VFX_TRUE;
}

void VappOp01HsHintBox::launchApp()
{
    switch (m_hintType)
    {
        case HINT_TYPE_CALL:
            vadp_v2p_hs_launch_call_inbox();
            break;

        case HINT_TYPE_SMS:
            vadp_v2p_hs_launch_sms_inbox();
            break;

        case HINT_TYPE_MMS:
            vadp_v2p_hs_launch_mms_inbox();
            break;

        default:
            break;
    }
}

/***************************************************************************** 
 * Class VappOp01HsSearchButton: search button class
 *****************************************************************************/
VappOp01HsSearchButton::VappOp01HsSearchButton() :
    m_buttonBg(NULL),
    m_searchIcon(NULL)
{
}

void VappOp01HsSearchButton::onInit()
{
    VfxControl::onInit();

    VFX_OBJ_CREATE(m_buttonBg, VfxImageFrame, this);
    m_buttonBg->setPos(0, 0);
    m_buttonBg->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_BUTTON_NORMAL_BG));

    VfxSize size = m_buttonBg->getBounds().size;

    VFX_OBJ_CREATE(m_searchIcon, VfxImageFrame, this);
    m_searchIcon->setPos(size.width >> 1, size.height >> 1);
    m_searchIcon->setAnchor(0.5f, 0.5f);
    m_searchIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_SEARCH_ICON_NORMAL));

    VfxRect bounds = getBounds();
    bounds.size = m_buttonBg->getBounds().size;
    setBounds(bounds);
}

VfxBool VappOp01HsSearchButton::onPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            setButtonState(BUTTON_STATE_PRESSED);
            break;

        case VFX_PEN_EVENT_TYPE_UP:
        {
            VfxRect bounds = getBounds();
            if (bounds.contains(event.getRelPos(this)))
            {
                vfxPostInvoke0(this, &VappOp01HsSearchButton::launchApp);
            }
            setButtonState(BUTTON_STATE_NORMAL);
            break;
        }

        case VFX_PEN_EVENT_TYPE_MOVE:
        {
            VfxRect bounds = getBounds();
            if (bounds.contains(event.getRelPos(this)))
            {
                setButtonState(BUTTON_STATE_PRESSED);
            }
            else
            {
                setButtonState(BUTTON_STATE_NORMAL);
            }

            break;            
        }

        default:
            break;
    }

    return VFX_TRUE;
}

void VappOp01HsSearchButton::launchApp()
{
    vadp_v2p_hs_launch_sms_inbox();
}

void VappOp01HsSearchButton::setButtonState(VappOP01ButtonStateEnum state)
{
    if (state == BUTTON_STATE_NORMAL)
    {
        m_buttonBg->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_BUTTON_NORMAL_BG));
        m_searchIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_SEARCH_ICON_NORMAL));
    }
    else if(state == BUTTON_STATE_PRESSED)
    {
        m_buttonBg->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_BUTTON_PRESSED_BG));
        m_searchIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_SEARCH_ICON_PRESSED));
    }
}


/***************************************************************************** 
 * Class VappOp01HsWlanSwitch: WLAN switch class
 *****************************************************************************/
VappOp01HsWlanSwitch::VappOp01HsWlanSwitch(VfxS32 status) :
    m_buttonBg(NULL),
    m_wlanIcon(NULL),
    m_IndFrame(NULL),
    m_indTimer(NULL),
    m_scrollIndex(0),
    m_wlanStatus(status)
{
    for (VfxS32 i = 0; i < 4; i++)
    {
        m_switchInd[i] = NULL;
    }
}

void VappOp01HsWlanSwitch::onInit()
{
    VfxControl::onInit();

    VFX_OBJ_CREATE(m_buttonBg, VfxImageFrame, this);
    m_buttonBg->setPos(0, 0);
    m_buttonBg->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_BUTTON_NORMAL_BG));

    VfxSize size = m_buttonBg->getBounds().size;

    VFX_OBJ_CREATE(m_wlanIcon, VfxImageFrame, this);
    m_wlanIcon->setPos(size.width >> 1, size.height >> 1);
    m_wlanIcon->setAnchor(0.5f, 0.5f);

    VFX_OBJ_CREATE(m_IndFrame, VfxFrame, this);
    m_IndFrame->setPos(IND_POS_X, IND_POS_Y);
    m_IndFrame->setBounds(0, 0, m_buttonBg->getBounds().getWidth(), IND_HEIGHT);

    VfxS32 posX = 0;
    for (VfxS32 i = 0; i < 4; i++)
    {
        VFX_OBJ_CREATE(m_switchInd[i], VfxImageFrame, m_IndFrame);
        m_switchInd[i]->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_WLAN_PROGRESS_DOT));
        m_switchInd[i]->setPos(posX, 0);
        posX += m_switchInd[i]->getSize().width + IND_GAP;
    }

    // Timer for indicator scrolling
    VFX_OBJ_CREATE(m_indTimer, VfxTimer, this);

    switch (m_wlanStatus)
    {
        case OP01_HS_WLAN_POWER_OFF:
            m_wlanIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_WLAN_DISABLE_ICON_NORMAL));
            m_IndFrame->setHidden(VFX_TRUE);
            break;

        case OP01_HS_WLAN_POWER_WAITING:
            m_wlanIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_WLAN_DISABLE_ICON_NORMAL));
            m_IndFrame->setHidden(VFX_FALSE);
            startScrollInd();
            break;

        case OP01_HS_WLAN_POWER_ON:
        case OP01_HS_WLAN_CONNECTED:
            m_wlanIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_WLAN_ENABLE_ICON_NORMAL));
            m_IndFrame->setHidden(VFX_TRUE);
            break;

        case OP01_HS_WLAN_CONNECT_WAITING:
            m_wlanIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_WLAN_ENABLE_ICON_NORMAL));
            m_IndFrame->setHidden(VFX_FALSE);
            startScrollInd();
            break;

        default:
            break;       
    }

    VfxRect bounds = getBounds();
    bounds.size = m_buttonBg->getBounds().size;
    setBounds(bounds);
}

VfxBool VappOp01HsWlanSwitch::onPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
        {
            if (m_indTimer->getIsEnabled())
            {
                return VFX_FALSE;
            }
            setWlanButtonState(WLAN_STATE_PRESSED);
            m_IndFrame->setHidden(VFX_TRUE);
            break;
        }

        case VFX_PEN_EVENT_TYPE_UP:
        {
            VfxRect bounds = getBounds();
            if (bounds.contains(event.getRelPos(this)))
            {
                startScrollInd();
                switchWlan();
            }
            setWlanButtonState(WLAN_STATE_NORMAL);
            break;
        }

        case VFX_PEN_EVENT_TYPE_MOVE:
        {
            VfxRect bounds = getBounds();
            if (bounds.contains(event.getRelPos(this)))
            {
                setWlanButtonState(WLAN_STATE_PRESSED);
            }
            else
            {
                setWlanButtonState(WLAN_STATE_NORMAL);
            }

            break;            
        }

        default:
            break;
    }

    return VFX_TRUE;
}

void VappOp01HsWlanSwitch::switchWlan()
{
    vadp_v2p_hs_switch_wlan_req();
}

void VappOp01HsWlanSwitch::startScrollInd()
{
    if (m_indTimer)
    {
        m_indTimer->m_signalTick.connect(this, &VappOp01HsWlanSwitch::onStartScrollInd);
        m_indTimer->setStartDelay(0);
        m_indTimer->setDuration(300);
        m_indTimer->start();
    }
}

void VappOp01HsWlanSwitch::onStartScrollInd(VfxTimer *timer)
{
    m_IndFrame->setHidden(VFX_FALSE);

    for (VfxS32 i = 0; i < IND_NUMBER; i++)
    {
        if (m_scrollIndex == IND_NUMBER)
        {
            m_IndFrame->setHidden(VFX_TRUE);
            break;            
        }
        
        if (i <= m_scrollIndex)
        {
            m_switchInd[i]->setHidden(VFX_FALSE);
        }
        else
        {
            m_switchInd[i]->setHidden(VFX_TRUE);
        }
    }

    m_scrollIndex++;
    if (m_scrollIndex == IND_NUMBER + 1)
    {
        m_scrollIndex = 0;
    }
}

void VappOp01HsWlanSwitch::setWlanButtonState(VappOP01WlanButtonStateEnum state)
{
    if (state == WLAN_STATE_NORMAL)
    {
        m_buttonBg->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_BUTTON_NORMAL_BG));
        if (m_wlanStatus == OP01_HS_WLAN_POWER_OFF)
        {
            m_wlanIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_WLAN_DISABLE_ICON_NORMAL));
        }
        else if (m_wlanStatus == OP01_HS_WLAN_POWER_WAITING)
        {
            m_wlanIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_WLAN_DISABLE_ICON_NORMAL));
        }
        else if (m_wlanStatus == OP01_HS_WLAN_POWER_ON)
        {
            m_wlanIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_WLAN_ENABLE_ICON_NORMAL));
        }
        else if (m_wlanStatus == OP01_HS_WLAN_CONNECT_WAITING)
        {
            m_wlanIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_WLAN_ENABLE_ICON_NORMAL));
        }
        else if (m_wlanStatus == OP01_HS_WLAN_CONNECTED)
        {
            m_wlanIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_WLAN_ENABLE_ICON_NORMAL));
        }
    }
    else if(state == WLAN_STATE_PRESSED)
    {
        m_buttonBg->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_BUTTON_PRESSED_BG));

        if (m_wlanStatus == OP01_HS_WLAN_CONNECTED)
        {
            m_wlanIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_WLAN_ENABLE_ICON_PRESSED));
        }
        else if (m_wlanStatus == OP01_HS_WLAN_POWER_ON)
        {
            m_wlanIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_WLAN_ENABLE_ICON_PRESSED));
        }
        else if (m_wlanStatus == OP01_HS_WLAN_POWER_OFF)
        {
            m_wlanIcon->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_WLAN_DISABLE_ICON_PRESSED));
        }
    }
}

void VappOp01HsWlanSwitch::updateButton()
{
    if (m_indTimer != NULL)
    {
        m_indTimer->stop();
    }

    m_wlanStatus = vadp_v2p_hs_get_wlan_state();
    m_IndFrame->setHidden(VFX_TRUE);
    m_scrollIndex = 0;
    setWlanButtonState(WLAN_STATE_NORMAL);
}

/***************************************************************************** 
 * Class VappOp01HsDateTime: date and time class
 *****************************************************************************/
VappOp01HsDateTime::VappOp01HsDateTime() :
    m_time(NULL),
    m_day(NULL)
{
}

void VappOp01HsDateTime::onInit()
{
    VfxControl::onInit();

    // Create time
    VFX_OBJ_CREATE(m_time, VcpDigitalTextClock, this);
    m_time->setFormatFlags(VFX_DATE_TIME_TIME_HOUR |
                           VFX_DATE_TIME_TIME_MINUTE);
    m_time->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_DIALER, VFX_FONT_DESC_EFFECT_BORDER));
    m_time->setTextColor(VFX_COLOR_WHITE);
    m_time->setTextBorderColor(OP01HS_TEXT_COLOR);
    m_time->setAnchor(1, 0);
    m_time->setTime();
    m_time->setBoundsAutoMinmize(VFX_TRUE);
    m_time->startClock();
    
    // Create day
    VFX_OBJ_CREATE(m_day, VcpDigitalTextClock, this);
    m_day->setFormatFlags(VFX_DATE_TIME_DATE_YEAR |
                          VFX_DATE_TIME_DATE_MONTH |
                          VFX_DATE_TIME_DATE_DAY |
                          VFX_DATE_TIME_DAY_SHORT_NAME);
    m_day->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_SMALL, VFX_FONT_DESC_EFFECT_BORDER));
    m_day->setTextColor(VFX_COLOR_WHITE);
    m_day->setTextBorderColor(OP01HS_TEXT_COLOR);
    m_day->setAnchor(1, 0);
    m_day->setTime();
    m_day->setBoundsAutoMinmize(VFX_TRUE);
    m_day->startClock();

    VfxS32 timeWidth = m_time->getBounds().size.width;
    VfxS32 dayWidth = m_day->getBounds().size.width;
    VfxS32 maxWidth = timeWidth > dayWidth ? timeWidth : dayWidth;
    VfxS32 maxHeight = m_time->getBounds().size.height + LINE_GAP + m_day->getBounds().size.height;

    VfxRect bounds = getBounds();
    bounds.size.width = maxWidth + 6/* from 01:11 to 01:02 the time bounds enlarge */;
    bounds.size.height = maxHeight + 3/* from 2030/12/31 11:59 PM to 2000/01/01 12:00 AM the day bounds enlarge */;
    setBounds(bounds);

    VfxS32 posX = bounds.size.width;
    VfxS32 posY = m_time->getBounds().size.height + LINE_GAP;
    m_time->setPos(posX, 0);
    m_day->setPos(posX, posY);
}

void VappOp01HsDateTime::setTextNormal()
{
    m_time->setTextColor(VFX_COLOR_WHITE);
    m_day->setTextColor(VFX_COLOR_WHITE);
}

void VappOp01HsDateTime::setTextPressed()
{
    m_time->setTextColor(OP01HS_TEXT_PRESSED_COLOR);
    m_day->setTextColor(OP01HS_TEXT_PRESSED_COLOR);
}

VfxBool VappOp01HsDateTime::onPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            setTextPressed();
            break;

        case VFX_PEN_EVENT_TYPE_UP:
        {
            VfxRect bounds = getBounds();
            if (bounds.contains(event.getRelPos(this)))
            {
                vfxPostInvoke0(this, &VappOp01HsDateTime::launchApp);
            }

            setTextNormal();
            break;
        }

        case VFX_PEN_EVENT_TYPE_MOVE:
        {
            VfxRect bounds = getBounds();
            if (bounds.contains(event.getRelPos(this)))
            {
                setTextPressed();
            }
            else
            {
                setTextNormal();
            }

            break;            
        }
        
        default:
            break;
    }

    return VFX_TRUE;
}

void VappOp01HsDateTime::launchApp()
{
    vadp_v2p_hs_launch_date_time();
}

/*****************************************************************************
 * Class VappOp01HsShctIcon: shortcut icon class
 *****************************************************************************/
VappOp01HsShctIcon::VappOp01HsShctIcon(VfxS32 index, VfxS32 resId, FuncPtr penHandler) :
    m_shctIndex(index),
    m_shctResId(resId),
    m_penHandler(penHandler)
{
    m_shctIconImg = NULL;
    m_shctState = SHCT_STATE_NORMAL;
    m_zoomTimeLine = NULL;
}

void VappOp01HsShctIcon::onInit()
{
    VfxControl::onInit();

    VFX_OBJ_CREATE(m_shctIconImg, VfxImageFrame, this);
    m_shctIconImg->setImgContent(VfxImageSrc(m_shctResId));
    m_shctIconImg->setAnchor(0.5f, 0.5f);
    m_shctIconImg->setPos(ICON_WIDTH >> 1, ICON_HEIGHT >> 1);

    VFX_OBJ_CREATE(m_zoomTimeLine, VfxTransformTimeline, this);
    
    setBounds(0, 0, ICON_WIDTH, ICON_HEIGHT);
}

VfxBool VappOp01HsShctIcon::onPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
        {
            m_shctState = SHCT_STATE_PRESSED;
            shctIconRoomIn();
            m_signalPressed.emit(m_shctIndex);
            break;
        }

        case VFX_PEN_EVENT_TYPE_UP:
        {
            if (m_shctState == SHCT_STATE_PRESSED)
            {
                shctIconRoomOut();
                m_signalNormal.emit(m_shctIndex);
                vfxPostInvoke0(this, &VappOp01HsShctIcon::launchApp);
            }
            break;
        }

        case VFX_PEN_EVENT_TYPE_MOVE:
        {
            VfxRect bounds = getBounds();
            if (!bounds.contains(event.getRelPos(this)))
            {
                m_shctState = SHCT_STATE_NORMAL;
                shctIconRoomOut();
                m_signalNormal.emit(m_shctIndex);
            }
            break;            
        }

        default:
            break;
    }

    return VFX_TRUE;
}

void VappOp01HsShctIcon::launchApp()
{
    if(m_penHandler != NULL)
    {
        m_penHandler();
    }    
}

void VappOp01HsShctIcon::shctIconRoomIn()
{
    VfxTransform trans;
    trans.type = VRT_TRANSFORM_TYPE_AFFINE;
    trans.data.affine.sx = 0.75f;
    trans.data.affine.sy = 0.75f;
    m_zoomTimeLine->setTarget(this);
    m_zoomTimeLine->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
    m_zoomTimeLine->setFromValue(getTransform());
    m_zoomTimeLine->setToValue(trans);
    m_zoomTimeLine->setDurationTime(100);
    m_zoomTimeLine->start();
}

void VappOp01HsShctIcon::shctIconRoomOut()
{
    VfxTransform trans;
    trans.type = VRT_TRANSFORM_TYPE_AFFINE;
    trans.data.affine.sx = 1.0f;
    trans.data.affine.sy = 1.0f;
    m_zoomTimeLine->setTarget(this);
    m_zoomTimeLine->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
    m_zoomTimeLine->setFromValue(getTransform());
    m_zoomTimeLine->setToValue(trans);
    m_zoomTimeLine->setDurationTime(100);
    m_zoomTimeLine->start();
}

/*****************************************************************************
 * Class VappOp01HsShctBar: shortcut bar class
 *****************************************************************************/
VappOp01HsShctBar::VappOp01HsShctBar() :
    m_shctBarBg(NULL),
    m_shctArea(NULL),
    m_shctCount(0),
    m_scrollingTl(NULL)
{
    for (VfxS32 i = 0; i < MAX_VIEW_CNT; i++)
    {
        m_shctHighlightBg[i] = NULL;
        m_shctIcon[i] = NULL;
    }

    m_arrowButton[0]= NULL;
    m_arrowButton[1]= NULL;

    m_scrollFromId = vadp_v2p_op01_hs_get_shct_first_icon_index();
    m_scrollToId = m_scrollFromId;
}

void VappOp01HsShctBar::onInit()
{
    VfxControl::onInit();

    // Init shortcut bar background
    VFX_OBJ_CREATE(m_shctBarBg, VfxImageFrame, this);
    m_shctBarBg->setPos(0, 0);
    m_shctBarBg->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_SC_BG));

    initShctItem();

    // Init left and right arrow
    VFX_OBJ_CREATE(m_arrowButton[0], VcpButtonInternal, this);
    m_arrowButton[0]->setPos(0, SC_BG_HEIGHT >> 1);
    m_arrowButton[0]->setAnchor(0, 0.5);
    m_arrowButton[0]->m_eventUp.connect(this, &VappOp01HsShctBar::onLeftArrowUp);

    VFX_OBJ_CREATE(m_arrowButton[1], VcpButtonInternal, this);
    m_arrowButton[1]->setAnchor(VfxFPoint(1, 0.5));
    m_arrowButton[1]->setPos(SC_BG_WIDTH, SC_BG_HEIGHT >> 1);
    m_arrowButton[1]->m_eventUp.connect(this, &VappOp01HsShctBar::onRightArrowUp);

    m_arrowButton[0]->setBackgroundUp(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_LEFT_ARROW_NORMAL), VFX_TRUE);
    m_arrowButton[0]->setBackgroundDown(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_LEFT_ARROW_PRESSED), VFX_TRUE);
    m_arrowButton[1]->setBackgroundUp(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_RIGHT_ARROW_NORMAL), VFX_TRUE);
    m_arrowButton[1]->setBackgroundDown(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_RIGHT_ARROW_PRESSED), VFX_TRUE);

    // Init scroll animation
    VFX_OBJ_CREATE(m_scrollingTl, VfxS32Timeline, this);
    m_scrollingTl->setTarget(m_shctArea);
    m_scrollingTl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_BOUNDS_ORIGIN_X);
    m_scrollingTl->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
    m_scrollingTl->setDurationTime(SCROLL_TL_DURATION);
    m_scrollingTl->setRepeatCount(1);
    m_scrollingTl->m_signalStopped.connect(this, &VappOp01HsShctBar::onScrollAnimStop);
    
    setBounds(0, 0, SC_BG_WIDTH, SC_BG_HEIGHT);
}

void VappOp01HsShctBar::onShctPressed(VfxS32 index)
{
    m_shctHighlightBg[index]->setHidden(VFX_FALSE);
}

void VappOp01HsShctBar::onShctNormal(VfxS32 index)
{
    m_shctHighlightBg[index]->setHidden(VFX_TRUE);
}

void VappOp01HsShctBar::onLeftArrowUp()
{
    m_scrollToId--;
    if (m_scrollToId < 0)
    {
        m_scrollToId += m_shctCount;
    }
    m_scrollFromId = m_scrollToId + 1;

    m_scrollingTl->setFromValue(m_scrollFromId * (ICON_WIDTH + ICON_GAP));
    m_scrollingTl->setToValue(m_scrollToId * (ICON_WIDTH + ICON_GAP));
    m_scrollingTl->start();
}

void VappOp01HsShctBar::onRightArrowUp()
{
    m_scrollToId++;
    if (m_scrollToId > m_shctCount)
    {
        m_scrollToId -= m_shctCount;
    }
    m_scrollFromId = m_scrollToId - 1;

    m_scrollingTl->setFromValue(m_scrollFromId * (ICON_WIDTH + ICON_GAP));
    m_scrollingTl->setToValue(m_scrollToId * (ICON_WIDTH + ICON_GAP));
    m_scrollingTl->start();
}

void VappOp01HsShctBar::onScrollAnimStop(VfxBaseTimeline *timeline, VfxBool isCompleted)
{ 
    VFX_UNUSED(timeline);
    VFX_UNUSED(isCompleted);

    VfxRect  bounds =  m_shctArea->getBounds();
    bounds.origin.x = m_scrollToId * (ICON_WIDTH + ICON_GAP);
    m_shctArea->setBounds(bounds);

    vadp_v2p_op01_hs_set_shct_first_icon_index(m_scrollToId);
}

void VappOp01HsShctBar::initShctItem()
{
    VfxS32 shctCount = 0;
    VfxS32 shctResId[MAX_CNT];
    FuncPtr shctPenHandler[MAX_CNT];

    vadp_v2p_op01_hs_get_shct_info(&shctCount, shctResId, shctPenHandler);
    m_shctCount = shctCount;

    if (m_shctCount > MAX_CNT)
    {
        m_shctCount = MAX_CNT;
    }

    VFX_OBJ_CREATE(m_shctArea, VfxControl, this);
    VfxS32 boundsW = 0;
    VfxS32 posX = 0;
    if (m_shctCount == 3)
    {
        boundsW = SC_AREA_WIDTH - ICON_WIDTH - ICON_GAP;
        posX = SC_AREA_POS_X;
    }
    else if (m_shctCount == 2)
    {
        boundsW = SC_AREA_WIDTH - ((ICON_WIDTH + ICON_GAP) << 1) ;
        posX = SC_AREA_POS_X + ICON_WIDTH + ICON_GAP;
    }
    else
    {
        boundsW = SC_AREA_WIDTH;
        posX = SC_AREA_POS_X;
    }
    m_shctArea->setPos(posX, 0);
    m_shctArea->setBounds(m_scrollToId * (ICON_WIDTH + ICON_GAP), 0, boundsW, SC_AREA_HEIGHT);

    VfxS32 extra_cnt = 0;
    if (m_shctCount <= MAX_CNT_PER_VIEW)
    {
        extra_cnt = m_shctCount;
    }
    else
    {
        extra_cnt = MAX_CNT_PER_VIEW;
    }

    for (VfxS32 index = 0; index < m_shctCount + extra_cnt; index++)
    {
        VfxS32 posX = ICON_GAP + (ICON_WIDTH >> 1) + (ICON_WIDTH + ICON_GAP) * index;
        VFX_OBJ_CREATE(m_shctHighlightBg[index], VfxImageFrame, m_shctArea);
        m_shctHighlightBg[index]->setPos(posX, SC_BG_HEIGHT >> 1);
        m_shctHighlightBg[index]->setAnchor(0.5f, 0.5f);
        m_shctHighlightBg[index]->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_SC_HIGHLIGHT));
        m_shctHighlightBg[index]->setHidden(VFX_TRUE);

        // Create shortcut icons
        if (index < m_shctCount)
        {
            VFX_OBJ_CREATE_EX(m_shctIcon[index], VappOp01HsShctIcon, m_shctArea, (index, shctResId[index], shctPenHandler[index]));
        }
        else
        {
            VFX_OBJ_CREATE_EX(m_shctIcon[index], VappOp01HsShctIcon, m_shctArea, (index, shctResId[index - m_shctCount], shctPenHandler[index - m_shctCount]));
        }
        m_shctIcon[index]->setPos(posX, SC_BG_HEIGHT >> 1);
        m_shctIcon[index]->setAnchor(0.5f, 0.5f);
        m_shctIcon[index]->m_signalPressed.connect(this, &VappOp01HsShctBar::onShctPressed);
        m_shctIcon[index]->m_signalNormal.connect(this, &VappOp01HsShctBar::onShctNormal);
    }
}

#ifdef __MMI_OP01_DCD_V30__
/***************************************************************************** 
 * Class VappOp01HsDCDMarquee: DCD content marquee class
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappOp01HsDCDMarquee", VappOp01HsDCDMarquee, VfxControl);

VappOp01HsDCDMarquee::VappOp01HsDCDMarquee() :
    m_movableFrame(NULL),
    m_scrollTimeline(NULL),
    m_isScrolling(VFX_FALSE),
    m_speed(MIDDLE_SPEED),
    m_startDelay(DELAY_TIME)
{
}

void VappOp01HsDCDMarquee::onInit()
{
    VfxControl::onInit();
}

void VappOp01HsDCDMarquee::onDeinit()
{
    clearMovableFrame();

    VfxControl::onDeinit();
}

void VappOp01HsDCDMarquee::setSpeed(VfxS32 value)
{
    m_speed = value;    
}

VfxS32 VappOp01HsDCDMarquee::getSpeed() const
{
    return m_speed;
}

void VappOp01HsDCDMarquee::setStartDelay(VfxMsec value)
{
    m_startDelay = value; 
}

VfxMsec VappOp01HsDCDMarquee::getStartDelay() const
{
    return m_startDelay;
}

VfxS32 VappOp01HsDCDMarquee::computeTimelineDuration(VfxS32 distance)
{
    return 1000 * VFX_ABS(distance) / getSpeed();
}

void VappOp01HsDCDMarquee::startTimeline()
{
    if (m_isScrolling)
    {
        VFX_DEV_ASSERT(m_scrollTimeline != NULL);
        // Do nothing.
        return;
    }
    
    VFX_DEV_ASSERT(m_scrollTimeline == NULL);

    if (!needScroll())
    {
        // No need to scroll, do nothing.
        return;
    }

    m_isScrolling = VFX_TRUE;
        
    VFX_OBJ_CREATE(m_scrollTimeline, VfxS32Timeline, this);

    VfxS32 marquee_height = getMarqueeBounds().getHeight();
    VfxS32 movable_height = getMovableBounds().getHeight();

    VFX_OBJ_ASSERT_VALID(m_movableFrame);

    VfxS32 from_y1, to_y1, duration1, start_time1;
    from_y1 = 0;
    to_y1 = -(movable_height - marquee_height);
    duration1 = computeTimelineDuration(from_y1 - to_y1);
    start_time1 = getStartDelay();

    // setup the timelines
    m_scrollTimeline->setTarget(m_movableFrame);        
    m_scrollTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Y);
    m_scrollTimeline->setFromValue(from_y1);
    m_scrollTimeline->setToValue(to_y1);
    m_scrollTimeline->setStartTime(start_time1);
    m_scrollTimeline->setDurationTime(duration1);
    m_scrollTimeline->setIsFromCurrent(VFX_FALSE);
    m_scrollTimeline->m_signalStopped.connect(this, &VappOp01HsDCDMarquee::onTimelineStop);
    m_scrollTimeline->start();
}


void VappOp01HsDCDMarquee::stopTimeline()
{
    if (!m_isScrolling)
    {
        // Do nothing
        return;
    }

    m_isScrolling = VFX_FALSE;    
    VFX_OBJ_CLOSE(m_scrollTimeline);
}

VfxBool VappOp01HsDCDMarquee::needScroll()
{
    VfxS32 marqueeHeight = getMarqueeBounds().getHeight();
    VfxS32 movableHeight = getMovableBounds().getHeight();

    return marqueeHeight < movableHeight ? VFX_TRUE : VFX_FALSE;
}

void VappOp01HsDCDMarquee::startScroll()
{
    startTimeline();
}

void VappOp01HsDCDMarquee::stopScroll()
{
    stopTimeline();
}

void VappOp01HsDCDMarquee::onTimelineStop(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);

    if (!isCompleted)
    {
        // Do nothing
        return;
    }
    
    stopTimeline();

    m_signalScrollFinished.postEmit(this);
}

void VappOp01HsDCDMarquee::clearMovableFrame()
{
    stopScroll();

    VFX_OBJ_CLOSE(m_movableFrame);
}

void VappOp01HsDCDMarquee::setMovableFrame(VfxFrame *frame)
{
    stopScroll();

    VFX_OBJ_CLOSE(m_movableFrame);

    VFX_OBJ_ASSERT_VALID(frame);
    frame->setParent(this);
    m_movableFrame = frame;

    invalidate();
}


/***************************************************************************** 
 * Class VappOp01HsDCDNewsArea: DCD news area class
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappOp01HsDCDNewsArea", VappOp01HsDCDNewsArea, VfxControl);
const VfxS32 VappOp01HsDCDNewsArea::s_penScrollThreshold = 15;

VappOp01HsDCDNewsArea::VappOp01HsDCDNewsArea() :
    m_newsImg(NULL),
    m_newsContent(NULL),
    m_scrollArea(NULL),
    m_channelName(NULL),
    m_contentHeight(0)
{
    for (VfxS32 i = 0; i < MAX_LINE_NUMBER; i++)
    {
        m_entryList[i] = NULL;
    }
}

void VappOp01HsDCDNewsArea::onInit()
{
    VfxControl::onInit();

    // Create news image
    VFX_OBJ_CREATE(m_newsImg, VfxImageFrame, this);
    m_newsImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_newsImg->setHasAnimateImage(VFX_TRUE);

	// Create news content
    creatNewsContent();
}

void VappOp01HsDCDNewsArea::creatNewsContent()
{
	VFX_OBJ_CREATE(m_newsContent, VappOp01HsDCDMarquee, this);
	m_newsContent->setPos(CONTENT_AREA_POS_X, CONTENT_AREA_POS_Y);

	dcd_idle_scroll_speed_enum scroll_speed = mmi_dcd_get_scroll_speed_ext();
	switch (scroll_speed)
	{
		case DCD_IDLE_SCROLL_FAST_SPEED:
			m_newsContent->setSpeed(VappOp01HsDCDMarquee::FAST_SPEED);
			break;

		case DCD_IDLE_SCROLL_MEDIUM_SPEED:
			m_newsContent->setSpeed(VappOp01HsDCDMarquee::MIDDLE_SPEED);
			break;

		case DCD_IDLE_SCROLL_SLOW_SPEED:
			m_newsContent->setSpeed(VappOp01HsDCDMarquee::SLOW_SPEED);
			break;

		default:
			VFX_ASSERT(0);
			break;
	}
	
	m_newsContent->setStartDelay(VappOp01HsDCDMarquee::DELAY_TIME);
	m_newsContent->setBounds(0, 0, CONTENT_WIDTH, CONTENT_HEIGHT);
	m_newsContent->setMovableFrame(getCurrentContent());
	m_newsContent->startScroll();

	m_newsContent->m_signalScrollFinished.connect(this, &VappOp01HsDCDNewsArea::onScrollStop);
}

void VappOp01HsDCDNewsArea::onScrollStop(VappOp01HsDCDMarquee *scrollFrame)
{
    scrollFrame->setMovableFrame(getNextContent());
    scrollFrame->startScroll();
}

void VappOp01HsDCDNewsArea::updateImg()
{
    if (m_newsImg)
    {
	    VfxWChar * newsImagePath = (VfxWChar*)mmi_dcd_get_news_image_ext();
	    if (!newsImagePath)
		{
		    m_newsImg->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_DCD_DEFAULT_ICON));
            m_newsImg->setBounds(0, 0, IMAGE_DEFAULT_WIDTH, IMAGE_DEFAULT_HEIGHT);
			m_newsImg->setPos(IMAGE_DEFAULT_POS_X, IMAGE_DEFAULT_POS_Y);
		}
		else
		{
			VfxWString imagePath = VFX_WSTR_MEM(newsImagePath);
			m_newsImg->setPath(imagePath);
            m_newsImg->setBounds(0, 0, IMAGE_WIDTH, IMAGE_HEIGHT);
			m_newsImg->setPos(IMAGE_POS_X, IMAGE_POS_Y);
		}
    }
}

void VappOp01HsDCDNewsArea::updateContent()
{
    if (m_newsContent)
    {
		m_newsContent->m_signalScrollFinished.disconnect(this, &VappOp01HsDCDNewsArea::onScrollStop);
        VFX_OBJ_CLOSE(m_newsContent);

        creatNewsContent();
    }
}

VfxBool VappOp01HsDCDNewsArea::onPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
        case VFX_PEN_EVENT_TYPE_MOVE:
            break;

        case VFX_PEN_EVENT_TYPE_UP:
        {
            if (getBounds().contains(event.getRelPos(this)))
            {
                if (event.pos.y - event.downPos.y > s_penScrollThreshold)
                {
                    scrollToNextNews(VFX_FALSE);
                }
                else if (event.pos.y - event.downPos.y < -s_penScrollThreshold)
                {
                    scrollToNextNews(VFX_TRUE);
                }
                else
                {
                    vfxPostInvoke0(this, &VappOp01HsDCDNewsArea::entryDCDChannelFirstPage);
                }
            }

            break;
        }

        default:
            break;
    }

    return VFX_TRUE;
}

void VappOp01HsDCDNewsArea::scrollToNextNews(VfxBool isNext)
{
    if (isNext)
    {
        m_newsContent->setMovableFrame(getNextContent());
    }
    else
    {
        m_newsContent->setMovableFrame(getPrevContent());
    }

    m_newsContent->startScroll();
}

VfxFrame* VappOp01HsDCDNewsArea::getCurrentContent()
{
    VFX_OBJ_CREATE(m_scrollArea, VfxFrame, this);
    VFX_OBJ_CREATE(m_channelName, VfxTextFrame, m_scrollArea);
    m_channelName->setPos(0, CONTENT_OFFSET_Y);
    m_channelName->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(CONTENT_FONT_SIZE)));
    m_channelName->setColor(VFX_COLOR_WHITE);

    void* agentHandle = mmi_dcd_get_agent_handle_ext();
	VfxS32 channel_count = mmi_dcd_get_channel_count_ext(agentHandle);
	VfxWString curChanTitle;
	if (channel_count > 0)
	{
		VfxBool weatherChannel = VFX_FALSE;
		void* curChanHandle = mmi_dcd_get_current_channel_handle_ext(agentHandle);
		weatherChannel = mmi_dcd_is_weather_channel(curChanHandle) ? VFX_TRUE : VFX_FALSE;

		if (weatherChannel && (channel_count == 1))
		{
			VfxWString presetContent = VFX_WSTR_MEM(mmi_dcd_get_preset_summary_ext(agentHandle));
			m_channelName->setString(presetContent);
		    m_channelName->setBounds(0, 0, CONTENT_WIDTH, CONTENT_LINE_HEIGHT);
		    m_channelName->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
			m_channelName->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
			m_contentHeight = m_channelName->getBounds().getHeight();
		}
		else
		{
			if (weatherChannel)
			{
				VfxS32 curChanIndex = mmi_dcd_get_current_idle_channel_index();
				curChanIndex++;
				if (curChanIndex >= channel_count)
				{
					curChanIndex = 0;
				}
				mmi_dcd_set_current_idle_channel_index(curChanIndex);
				curChanHandle = mmi_dcd_get_current_channel_handle_ext(agentHandle);
			}
			mmi_dcd_set_news_image_ext(curChanHandle);
			curChanTitle = VFX_WSTR_MEM(mmi_dcd_get_channel_title_ext(curChanHandle));
			m_channelName->setString(VFX_WSTR("[") += curChanTitle += VFX_WSTR("]"));
		
		    m_channelName->setBounds(0, 0, CONTENT_WIDTH, CONTENT_LINE_HEIGHT);
		    m_channelName->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
		    m_channelName->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);

		    m_contentHeight = CONTENT_LINE_HEIGHT + CONTENT_OFFSET_Y;
		    VfxWChar dot[2] = {0x2022, 0x0000}; // dot unicode value

			VfxS32 block_count = 0;
			VfxS32 i = 0;
			void * blockHandle = NULL;
			VfxS32 entryCount = 0;
			VfxS32 entryIndex = 0;
			void * entryHandle = NULL;
			VfxWString entryTitle;
			VfxU8  reachMax = 0;
			block_count = mmi_dcd_get_channel_block_count_ext(curChanHandle);

		    for (VfxS32 blockIndex = 0; blockIndex < block_count; blockIndex++)
		    {
				if (reachMax)
				{
					break;
				}
			    blockHandle = mmi_dcd_get_channel_block_handle_ext(curChanHandle, blockIndex);
				entryCount = mmi_dcd_get_block_entry_count_ext(blockHandle);

				for (entryIndex = 0; entryIndex < entryCount; entryIndex++)
				{
					entryHandle = mmi_dcd_get_block_entry_handle_ext(blockHandle, entryIndex);
					entryTitle = VFX_WSTR_MEM(mmi_dcd_get_entry_title(entryHandle));
			        VFX_OBJ_CREATE(m_entryList[i], VfxTextFrame, m_scrollArea);
			        m_entryList[i]->setPos(0, m_contentHeight);
			        m_entryList[i]->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(CONTENT_FONT_SIZE)));
			        m_entryList[i]->setColor(VFX_COLOR_WHITE);
					m_entryList[i]->setString(VFX_WSTR_MEM(dot) += VFX_WSTR(" ") += entryTitle);
			        m_entryList[i]->setBounds(0, 0, CONTENT_WIDTH, CONTENT_LINE_HEIGHT);
			        m_entryList[i]->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
			        m_entryList[i]->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
			        m_contentHeight += CONTENT_LINE_HEIGHT;
					i++;
					if (i >= MAX_LINE_NUMBER)
					{
						reachMax = 1;
						break;
					}
				}
		    }
		}
	}	
	else
	{	
		VfxWString presetContent = VFX_WSTR_MEM(mmi_dcd_get_preset_summary_ext(agentHandle));
		m_channelName->setString(presetContent);
	    m_channelName->setBounds(0, 0, CONTENT_WIDTH, CONTENT_LINE_HEIGHT);
	    m_channelName->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
		m_channelName->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
		m_contentHeight = m_channelName->getBounds().getHeight();
	}
    m_scrollArea->setBounds(0, 0, CONTENT_WIDTH, m_contentHeight);

	VfxWChar * newsImagePath = (VfxWChar*)mmi_dcd_get_news_image_ext();
	if (!newsImagePath)
	{
	    m_newsImg->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_DCD_DEFAULT_ICON));
        m_newsImg->setBounds(0, 0, IMAGE_DEFAULT_WIDTH, IMAGE_DEFAULT_HEIGHT);
		m_newsImg->setPos(IMAGE_DEFAULT_POS_X, IMAGE_DEFAULT_POS_Y);
	}
	else
	{
		VfxWString imagePath = VFX_WSTR_MEM(newsImagePath);
		m_newsImg->setPath(imagePath);
        m_newsImg->setBounds(0, 0, IMAGE_WIDTH, IMAGE_HEIGHT);
		m_newsImg->setPos(IMAGE_POS_X, IMAGE_POS_Y);
	}

    return m_scrollArea;
}

VfxFrame* VappOp01HsDCDNewsArea::getPrevContent()
{
    VFX_OBJ_CREATE(m_scrollArea, VfxFrame, this);
    VFX_OBJ_CREATE(m_channelName, VfxTextFrame, m_scrollArea);
    m_channelName->setPos(0, CONTENT_OFFSET_Y);
    m_channelName->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(CONTENT_FONT_SIZE)));
    m_channelName->setColor(VFX_COLOR_WHITE);


	void* agentHandle = mmi_dcd_get_agent_handle_ext();
	VfxS32 channel_count = mmi_dcd_get_channel_count_ext(agentHandle);

	if (channel_count > 0)
	{

		VfxS32 curChanIndex = mmi_dcd_get_current_idle_channel_index();
		curChanIndex--;
		if (curChanIndex < 0)
		{
			curChanIndex = channel_count - 1;
		}
		mmi_dcd_set_current_idle_channel_index(curChanIndex);
		void* curChanHandle = mmi_dcd_get_current_channel_handle_ext(agentHandle);
		VfxBool weatherChannel = VFX_FALSE;
		weatherChannel = mmi_dcd_is_weather_channel(curChanHandle) ? VFX_TRUE : VFX_FALSE;

		if (weatherChannel)
		{
			if (channel_count > 1)
			{
				curChanIndex--;
				if (curChanIndex < 0)
				{
					curChanIndex = channel_count - 1;
				}
				mmi_dcd_set_current_idle_channel_index(curChanIndex);
				curChanHandle = mmi_dcd_get_current_channel_handle_ext(agentHandle);
			}
			if (channel_count == 1)
			{
				VfxWString presetContent = VFX_WSTR_MEM(mmi_dcd_get_preset_summary_ext(agentHandle));
				m_channelName->setString(presetContent);
			    m_channelName->setBounds(0, 0, CONTENT_WIDTH, CONTENT_LINE_HEIGHT);
			    m_channelName->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
				m_channelName->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
				m_contentHeight = m_channelName->getBounds().getHeight();

				m_scrollArea->setBounds(0, 0, CONTENT_WIDTH, m_contentHeight);

			    return m_scrollArea;
			}
		}

		mmi_dcd_set_news_image_ext(curChanHandle);
		
		VfxWString curChanTitle = VFX_WSTR_MEM(mmi_dcd_get_channel_title_ext(curChanHandle));
		m_channelName->setString(VFX_WSTR("[") += curChanTitle += VFX_WSTR("]"));
	
	    m_channelName->setBounds(0, 0, CONTENT_WIDTH, CONTENT_LINE_HEIGHT);
	    m_channelName->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	    m_channelName->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);

	    m_contentHeight = CONTENT_LINE_HEIGHT + CONTENT_OFFSET_Y;
	    VfxWChar dot[2] = {0x2022, 0x0000}; // dot unicode value

		VfxS32 block_count = 0;
		VfxS32 i = 0;
		void * blockHandle = NULL;
		VfxS32 entryCount = 0;
		VfxS32 entryIndex = 0;
		void * entryHandle = NULL;
		VfxWString entryTitle;
		VfxU8  reachMax = 0;
		block_count = mmi_dcd_get_channel_block_count_ext(curChanHandle);

	    for (VfxS32 blockIndex = 0; blockIndex < block_count; blockIndex++)
	    {
			if (reachMax)
			{
				break;
			}
		    blockHandle = mmi_dcd_get_channel_block_handle_ext(curChanHandle, blockIndex);
			entryCount = mmi_dcd_get_block_entry_count_ext(blockHandle);

			for (entryIndex = 0; entryIndex < entryCount; entryIndex++)
			{
				entryHandle = mmi_dcd_get_block_entry_handle_ext(blockHandle, entryIndex);
				entryTitle = VFX_WSTR_MEM(mmi_dcd_get_entry_title(entryHandle));
		        VFX_OBJ_CREATE(m_entryList[i], VfxTextFrame, m_scrollArea);
		        m_entryList[i]->setPos(0, m_contentHeight);
		        m_entryList[i]->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(CONTENT_FONT_SIZE)));
		        m_entryList[i]->setColor(VFX_COLOR_WHITE);
				m_entryList[i]->setString(VFX_WSTR_MEM(dot) += VFX_WSTR(" ") += entryTitle);
		        m_entryList[i]->setBounds(0, 0, CONTENT_WIDTH, CONTENT_LINE_HEIGHT);
		        m_entryList[i]->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
		        m_entryList[i]->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
		        m_contentHeight += CONTENT_LINE_HEIGHT;
				i++;
				if (i >= MAX_LINE_NUMBER)
				{
					reachMax = 1;
					break;
				}
			}
	    }

	}
	else
	{
		VfxWString presetContent = VFX_WSTR_MEM(mmi_dcd_get_preset_summary_ext(agentHandle));
		m_channelName->setString(presetContent);
	    m_channelName->setBounds(0, 0, CONTENT_WIDTH, CONTENT_LINE_HEIGHT);
	    m_channelName->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
		m_channelName->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
		m_contentHeight = m_channelName->getBounds().getHeight();
	}

    m_scrollArea->setBounds(0, 0, CONTENT_WIDTH, m_contentHeight);
	
	VfxWChar * newsImagePath = (VfxWChar*)mmi_dcd_get_news_image_ext();
	if (!newsImagePath)
	{
	    m_newsImg->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_DCD_DEFAULT_ICON));
        m_newsImg->setBounds(0, 0, IMAGE_DEFAULT_WIDTH, IMAGE_DEFAULT_HEIGHT);
		m_newsImg->setPos(IMAGE_DEFAULT_POS_X, IMAGE_DEFAULT_POS_Y);
	}
	else
	{
		VfxWString imagePath = VFX_WSTR_MEM(newsImagePath);
		m_newsImg->setPath(imagePath);
        m_newsImg->setBounds(0, 0, IMAGE_WIDTH, IMAGE_HEIGHT);
		m_newsImg->setPos(IMAGE_POS_X, IMAGE_POS_Y);
	}
	
    return m_scrollArea;
}

VfxFrame* VappOp01HsDCDNewsArea::getNextContent()
{
    VFX_OBJ_CREATE(m_scrollArea, VfxFrame, this);
    VFX_OBJ_CREATE(m_channelName, VfxTextFrame, m_scrollArea);
    m_channelName->setPos(0, CONTENT_OFFSET_Y);
    m_channelName->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(CONTENT_FONT_SIZE)));
    m_channelName->setColor(VFX_COLOR_WHITE);

	void* agentHandle = mmi_dcd_get_agent_handle_ext();
	VfxS32 channel_count = mmi_dcd_get_channel_count_ext(agentHandle);
	
	if (channel_count > 0)
	{
		VfxS32 curChanIndex = mmi_dcd_get_current_idle_channel_index();
		curChanIndex++;
		if (curChanIndex >= channel_count)
		{
			curChanIndex = 0;
		}

		mmi_dcd_set_current_idle_channel_index(curChanIndex);
		void* curChanHandle = mmi_dcd_get_current_channel_handle_ext(agentHandle);
		VfxBool weatherChannel = VFX_FALSE;
		weatherChannel = mmi_dcd_is_weather_channel(curChanHandle) ? VFX_TRUE : VFX_FALSE;
		if (weatherChannel)
		{
			if (channel_count > 1)
			{
				curChanIndex++;
				if (curChanIndex >= channel_count)
				{
					curChanIndex = 0;
				}
				mmi_dcd_set_current_idle_channel_index(curChanIndex);
				curChanHandle = mmi_dcd_get_current_channel_handle_ext(agentHandle);
			}
			if (channel_count == 1)
			{
				VfxWString presetContent = VFX_WSTR_MEM(mmi_dcd_get_preset_summary_ext(agentHandle));
				m_channelName->setString(presetContent);
			    m_channelName->setBounds(0, 0, CONTENT_WIDTH, CONTENT_LINE_HEIGHT);
			    m_channelName->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
				m_channelName->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
				m_contentHeight = m_channelName->getBounds().getHeight();

				m_scrollArea->setBounds(0, 0, CONTENT_WIDTH, m_contentHeight);

			    return m_scrollArea;
			}
		}
		mmi_dcd_set_news_image_ext(curChanHandle);
		
		VfxWString curChanTitle = VFX_WSTR_MEM(mmi_dcd_get_channel_title_ext(curChanHandle));
		m_channelName->setString(VFX_WSTR("[") += curChanTitle += VFX_WSTR("]"));
	
	    m_channelName->setBounds(0, 0, CONTENT_WIDTH, CONTENT_LINE_HEIGHT);
	    m_channelName->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	    m_channelName->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);

	    m_contentHeight = CONTENT_LINE_HEIGHT + CONTENT_OFFSET_Y;
	    VfxWChar dot[2] = {0x2022, 0x0000}; // dot unicode value

		VfxS32 block_count = 0;
		VfxS32 i = 0;
		void * blockHandle = NULL;
		VfxS32 entryCount = 0;
		VfxS32 entryIndex = 0;
		void * entryHandle = NULL;
		VfxWString entryTitle;
		VfxU8  reachMax = 0;
		block_count = mmi_dcd_get_channel_block_count_ext(curChanHandle);

	    for (VfxS32 blockIndex = 0; blockIndex < block_count; blockIndex++)
	    {
			if (reachMax)
			{
				break;
			}
		    blockHandle = mmi_dcd_get_channel_block_handle_ext(curChanHandle, blockIndex);
			entryCount = mmi_dcd_get_block_entry_count_ext(blockHandle);

			for (entryIndex = 0; entryIndex < entryCount; entryIndex++)
			{
				entryHandle = mmi_dcd_get_block_entry_handle_ext(blockHandle, entryIndex);
				entryTitle = VFX_WSTR_MEM(mmi_dcd_get_entry_title(entryHandle));
		        VFX_OBJ_CREATE(m_entryList[i], VfxTextFrame, m_scrollArea);
		        m_entryList[i]->setPos(0, m_contentHeight);
		        m_entryList[i]->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(CONTENT_FONT_SIZE)));
		        m_entryList[i]->setColor(VFX_COLOR_WHITE);
				m_entryList[i]->setString(VFX_WSTR_MEM(dot) += VFX_WSTR(" ") += entryTitle);
		        m_entryList[i]->setBounds(0, 0, CONTENT_WIDTH, CONTENT_LINE_HEIGHT);
		        m_entryList[i]->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
		        m_entryList[i]->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
		        m_contentHeight += CONTENT_LINE_HEIGHT;
				i++;
				if (i >= MAX_LINE_NUMBER)
				{
					reachMax = 1;
					break;
				}
			}
	    }
	}
	else
	{
		VfxWString presetContent = VFX_WSTR_MEM(mmi_dcd_get_preset_summary_ext(agentHandle));
		m_channelName->setString(presetContent);
	    m_channelName->setBounds(0, 0, CONTENT_WIDTH, CONTENT_LINE_HEIGHT);
	    m_channelName->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
		m_channelName->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
		m_contentHeight = m_channelName->getBounds().getHeight();
	}

    m_scrollArea->setBounds(0, 0, CONTENT_WIDTH, m_contentHeight);
	
	VfxWChar * newsImagePath = (VfxWChar*)mmi_dcd_get_news_image_ext();
	if (!newsImagePath)
	{
	    m_newsImg->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_DCD_DEFAULT_ICON));
        m_newsImg->setBounds(0, 0, IMAGE_DEFAULT_WIDTH, IMAGE_DEFAULT_HEIGHT);
		m_newsImg->setPos(IMAGE_DEFAULT_POS_X, IMAGE_DEFAULT_POS_Y);
	}
	else
	{
		VfxWString imagePath = VFX_WSTR_MEM(newsImagePath);
		m_newsImg->setPath(imagePath);
        m_newsImg->setBounds(0, 0, IMAGE_WIDTH, IMAGE_HEIGHT);
		m_newsImg->setPos(IMAGE_POS_X, IMAGE_POS_Y);
	}
    return m_scrollArea;
}

void VappOp01HsDCDNewsArea::entryDCDChannelFirstPage()
{
	mmi_dcd_entry_channel_detail_from_idle();
}

void VappOp01HsDCDNewsArea::onDeinit()
{
    mmi_dcd_news_image_free_ext();
	mmi_dcd_preset_summary_free_ext();
    VfxControl::onDeinit();
}

/***************************************************************************** 
 * Class VappOp01HsDCDWeatherArea: DCD weather area class
 *****************************************************************************/
VappOp01HsDCDWeatherArea::VappOp01HsDCDWeatherArea() :
    m_weatherImg(NULL),
    m_cityName(NULL),
    m_temperatureValue(NULL)
{
}

void VappOp01HsDCDWeatherArea::onInit()
{
    VfxControl::onInit();
	creatWeatherContent();
}

void VappOp01HsDCDWeatherArea::creatWeatherContent()
{
	void* agentHandle = mmi_dcd_get_agent_handle_ext();
	void* weatherChanHandle = NULL;
	if (agentHandle)
	{
		VfxS32 channel_count = mmi_dcd_get_channel_count_ext(agentHandle);
		weatherChanHandle = mmi_dcd_get_weather_channel_ext(agentHandle);
	}

	VfxS32 imgposX = WEATHER_IMAGE_DEFAULT_POS_X;
	VfxS32 imgposY = WEATHER_IMAGE_DEFAULT_POS_Y;
	VfxS32 imgWidth = WEATHER_IMAGE_DEFAULT_WIDTH;
	VfxS32 imgHeight = WEATHER_IMAGE_DEFAULT_HEIGHT;
	VFX_OBJ_CREATE(m_weatherImg, VfxImageFrame, this);
	
	if (weatherChanHandle)
	{
		void* defaultCityHandle = mmi_dcd_get_default_city_ext(agentHandle, weatherChanHandle);
		if (defaultCityHandle)
		{
			// Whether image
			VfxWString imagePath = VFX_WSTR_MEM(mmi_dcd_get_city_weather_image_ext(defaultCityHandle));
			m_weatherImg->setPath(imagePath);
			imgWidth = WEATHER_IMAGE_WIDTH;
			imgHeight = WEATHER_IMAGE_HEIGHT;
			imgposX = WEATHER_IMAGE_POS_X;
			imgposY = WEATHER_IMAGE_POS_Y;

			// City name
			VfxWString defaultCityName = VFX_WSTR_MEM(mmi_dcd_get_city_name_ext(defaultCityHandle));
		    VFX_OBJ_CREATE(m_cityName, VfxTextFrame, this);
		    m_cityName->setPos(CITY_NEME_TEXT_POS_X, CITY_NEME_TEXT_POS_Y);
			m_cityName->setAnchor(0.5f, 0.5f);
		    m_cityName->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(CITY_NAME_TEXT_FONT_SIZE)));
		    m_cityName->setColor(VFX_COLOR_WHITE);
			m_cityName->setString(VFX_WSTR("[") += defaultCityName += VFX_WSTR("]"));	
		    m_cityName->setBounds(0, 0, CITY_NEME_TEXT_WIDTH, CITY_NEME_TEXT_HEIGHT);
			m_cityName->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
		    m_cityName->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

			// Temperature text
			VfxWString defaultCityTemperature = VFX_WSTR_MEM(mmi_dcd_get_city_temperature_ext(defaultCityHandle));
		    VFX_OBJ_CREATE(m_temperatureValue, VfxTextFrame, this);
		    m_temperatureValue->setPos(TEMPERATURE_TEXT_POS_X, TEMPERATURE_TEXT_POS_Y);
			m_temperatureValue->setAnchor(0.5f, 0.5f);
		    m_temperatureValue->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TEMPERATURE_TEXT_FONT_SIZE)));
		    m_temperatureValue->setColor(VFX_COLOR_WHITE);
			m_temperatureValue->setString(defaultCityTemperature);
		    m_temperatureValue->setBounds(0, 0, TEMPERATURE_TEXT_WIDTH, TEMPERATURE_TEXT_HIGHT);
			m_temperatureValue->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
		    m_temperatureValue->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
		}
		else
		{
			m_weatherImg->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_DCD_WEATHER_ICON));
		}
	}
	else
	{
	    m_weatherImg->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_DCD_WEATHER_ICON));
	}

    m_weatherImg->setPos(imgposX, imgposY);
	m_weatherImg->setAnchor(0.5f, 0.0f);
    m_weatherImg->setBounds(0, 0, imgWidth, imgHeight);
    m_weatherImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
}

void VappOp01HsDCDWeatherArea::update()
{
    if (m_weatherImg)
    {
        VFX_OBJ_CLOSE(m_weatherImg);
    }

    if (m_cityName)
    {
        VFX_OBJ_CLOSE(m_cityName);
    }

    if (m_temperatureValue)
    {
        VFX_OBJ_CLOSE(m_temperatureValue);
    }

    creatWeatherContent();
}

void VappOp01HsDCDWeatherArea::onDeinit()
{
    mmi_dcd_city_weather_image_free_ext();
    VfxControl::onDeinit();
}

VfxBool VappOp01HsDCDWeatherArea::onPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
        case VFX_PEN_EVENT_TYPE_MOVE:
            break;

        case VFX_PEN_EVENT_TYPE_UP:
        {
            VfxRect bounds = getBounds();
            if (bounds.contains(event.getRelPos(this)))
            {
                vfxPostInvoke0(this, &VappOp01HsDCDWeatherArea::EntryDCDWeatherFirstPage);
            }
            break;
        }

        default:
            break;
    }

    return VFX_TRUE;
}

void VappOp01HsDCDWeatherArea::EntryDCDWeatherFirstPage()
{
    mmi_dcd_entry_weather_channel_from_idle();
}

/***************************************************************************** 
 * Class VappOp01HsDCDBar: DCD bar class
 *****************************************************************************/
VappOp01HsDCDBar::VappOp01HsDCDBar() :
    m_dcdBarBg(NULL),
    m_dcdNewsArea(NULL),
    m_dcdWeatherArea(NULL)
{
}

void VappOp01HsDCDBar::onInit()
{
    VfxControl::onInit();

    VFX_OBJ_CREATE(m_dcdBarBg, VfxImageFrame, this);
    m_dcdBarBg->setPos(0, 0);
    m_dcdBarBg->setImgContent(VfxImageSrc(VAPP_SHELL_IMG_OP01HS_DCD_BG));

    VFX_OBJ_CREATE(m_dcdNewsArea, VappOp01HsDCDNewsArea, this);
    m_dcdNewsArea->setPos(0, 0);
    m_dcdNewsArea->setBounds(0, 0, NEWS_AREA_WIDTH, NEWS_AREA_HEIGHT);

    VFX_OBJ_CREATE(m_dcdWeatherArea, VappOp01HsDCDWeatherArea, this);
    m_dcdWeatherArea->setPos(WEATHER_AREA_POS_X, 0);
    m_dcdWeatherArea->setBounds(0, 0, WEATHER_AREA_WIDTH, WEATHER_AREA_HEIGHT);

    setBounds(0, 0, BG_WIDTH, BG_HEIGHT);
}

void VappOp01HsDCDBar::updateDCDNewsImgArea()
{
    if (m_dcdNewsArea)
    {
        m_dcdNewsArea->updateImg();
    }
}

void VappOp01HsDCDBar::updateDCDNewsContentArea()
{
    if (m_dcdNewsArea)
    {
        m_dcdNewsArea->updateContent();
    }
}

void VappOp01HsDCDBar::updateDCDWhetherArea()
{
    if (m_dcdWeatherArea)
    {
        m_dcdWeatherArea->update();
    }
}

#endif /* __MMI_OP01_DCD_V30__ */
#endif /* __MMI_VUI_SHELL_OP01_HOMESCREEN__ */

