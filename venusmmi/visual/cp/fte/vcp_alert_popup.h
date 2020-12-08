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
 *  vcp_alert_popup.h
 *
 * Project:
 * --------
 *  Venus UI Component
 *
 * Description:
 * ------------
 *  Venus Cube Component
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCP_ALERT_POPUP_H__
#define __VCP_ALERT_POPUP_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vcp_button.h"
#include "vfx_base_popup.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_image_src.h"
#include "vfx_text_frame.h"
#include "vfx_cpp_base.h"
#include "vfx_input_event.h"
#include "vfx_timer.h"
#include "vfx_frame.h"
#include "vfx_object.h"
#include "vfx_signal.h"
#include "vcp_popup_data_type.h"

#if defined(__MMI_MAINLCD_320X480__)


    // VcpAlertPopup
    #define VCP_ALERT_POPUP_WIDTH                   (280)
    #define VCP_ALERT_POPUP_HEIGHT                  (141)
    
    #define VCP_ALERT_POPUP_ICON_Y                  (67)
    #define VCP_ALERT_POPUP_ICON_WIDTH              (74)
    #define VCP_ALERT_POPUP_ICON_HEIGHT             (67)
     
    #define VCP_ALERT_POPUP_TEXT_Y                  (117)
    #define VCP_ALERT_POPUP_TEXT_WIDTH              (250)
    
#elif defined(__MMI_MAINLCD_240X400__)
    // VcpAlertPopup
    #define VCP_ALERT_POPUP_WIDTH                   (218)
    #define VCP_ALERT_POPUP_HEIGHT                  (120)
    
    #define VCP_ALERT_POPUP_ICON_Y                  (55)
    #define VCP_ALERT_POPUP_ICON_WIDTH              (62)
    #define VCP_ALERT_POPUP_ICON_HEIGHT             (51)
     
    #define VCP_ALERT_POPUP_TEXT_Y                  (107)
    #define VCP_ALERT_POPUP_TEXT_WIDTH              (187)

#elif defined(__MMI_MAINLCD_240X320__)
    // VcpAlertPopup
    #define VCP_ALERT_POPUP_WIDTH                   (218)
    #define VCP_ALERT_POPUP_HEIGHT                  (120)
    
    #define VCP_ALERT_POPUP_ICON_Y                  (55)
    #define VCP_ALERT_POPUP_ICON_WIDTH              (62)
    #define VCP_ALERT_POPUP_ICON_HEIGHT             (51)
     
    #define VCP_ALERT_POPUP_TEXT_Y                  (107)
    #define VCP_ALERT_POPUP_TEXT_WIDTH              (187)

#else
    // VcpAlertPopup
    #define VCP_ALERT_POPUP_WIDTH                   (280)
    #define VCP_ALERT_POPUP_HEIGHT                  (141)
    
    #define VCP_ALERT_POPUP_ICON_Y                  (67)
    #define VCP_ALERT_POPUP_ICON_WIDTH              (74)
    #define VCP_ALERT_POPUP_ICON_HEIGHT             (67)
     
    #define VCP_ALERT_POPUP_TEXT_Y                  (117)
    #define VCP_ALERT_POPUP_TEXT_WIDTH              (250)
#endif

/*****************************************************************************
 * Class VcpAlertPopup
 *  VcpAlertPopup show alert popup. user can set its infoType to show different
 *  kinds of alert popup. the infoType is the same as plutommi. it decide the 
 *  warning tone, image icon, and the duration of this alert popup. User can
 *  also change those propertis by calling correspond API.
 *
 * EXAMPLE
 * <code>
 *  VcpAlertPopup *m_alertPopup;
 *  VFX_OBJ_CREATE(m_alertPopup, VcpAlertPopup, this);
 *  m_alertPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
 *  m_alertPopup->setText(VFX_WSTR("You are FAIL!"));
 *  m_alertPopup->show(VFX_TRUE);
 * </code>
 *****************************************************************************/
class VcpAlertPopup : public VfxBasePopup
{
// Constructor / Destructor
public:
    // <group DOM_AlertPopup_VcpAlertPopup_Constructor/Destructor>
    VcpAlertPopup(); 

// Method
public:
    // <group DOM_AlertPopup_VcpAlertPopup_Method>
    // set alart popup duration
    void setDuration(
        VfxMsec mSec        // [IN] duration
        )
    {
        m_duration = mSec;
    }
    // <group DOM_AlertPopup_VcpAlertPopup_Method>
    // set alart text
    void setText(
        const VfxWString &text  // [IN] text
        );
    
    // <group DOM_AlertPopup_VcpAlertPopup_Method>
    // set alart text font description
    void setTextFont(
        const VfxFontDesc &font // [IN] text font description
        );

    // <group DOM_AlertPopup_VcpAlertPopup_Method>
    // set alart infomation type
    void setInfoType(
        VcpPopupTypeEnum type   // [IN] information type
        );

    // <group DOM_AlertPopup_VcpAlertPopup_Method>
    // get alart popup duration
    VfxMsec getDuration()
    {
        return m_duration;
    }
    // <group DOM_AlertPopup_VcpAlertPopup_Method>
    // get alart text
    const VfxWString& getText() const
    {
        return m_textFrame->getString();
        //return m_textViewer->getText();
    }
    // <group DOM_AlertPopup_VcpAlertPopup_Method>
    // set alart text font description
    const VfxFontDesc &getTextFont()
    {
        return m_textFrame->getFont();
    }

    // <group DOM_AlertPopup_VcpAlertPopup_Method>
    // get alart infomation type
    VcpPopupTypeEnum getInfoType()
    {
        return m_infoType;
    }

    // <group DOM_AlertPopup_VcpAlertPopup_Method>
    // set icon image
    void setImage(
        const VfxImageSrc &imgScr         // [IN] image
        );
    // <group DOM_AlertPopup_VcpAlertPopup_Method>
    // set text alignment mode
    void setTextAlignMode(
        VfxTextFrame::AlignModeEnum value // [IN] text Alignment mode
        );
    

// Override
protected:
    // <group DOM_AlertPopup_VcpAlertPopup_Override>
    virtual void onInit();
    // <group DOM_AlertPopup_VcpAlertPopup_Override>
    virtual VfxBool onPenInput(VfxPenEvent &event);
    // <group DOM_AlertPopup_VcpAlertPopup_Override>
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    
    // <group DOM_AlertPopup_VcpAlertPopup_Override>
    virtual void onEnter();
    // <group DOM_AlertPopup_VcpAlertPopup_Override>
    virtual void onExit();    
    // <group DOM_AlertPopup_VcpAlertPopup_Override>
    virtual void onUpdate();
    // <group DOM_AlertPopup_VcpAlertPopup_Override>
    virtual VfxBool needPushHistory() const;
    // <group DOM_AlertPopup_VcpAlertPopup_Override>
    virtual void onPenInputOnOutside(VfxPenEvent &event);

	// <group DOM_AlertPopup_VcpAlertPopup_Override>
    virtual void onPlayTone();
    // <group DOM_AlertPopup_VcpAlertPopup_Override>
    virtual void onStopTone();

// Implementation
private:
    // <group DOM_AlertPopup_VcpAlertPopup_Implementation>
    void onTimerStop(VfxTimer *source);

// Variable
protected:
    // <group DOM_AlertPopup_VcpAlertPopup_Variable>
    VfxMsec                         m_duration;
    // <group DOM_AlertPopup_VcpAlertPopup_Variable>
    VfxFrame                        *m_background;
    // <group DOM_AlertPopup_VcpAlertPopup_Variable>
    VfxFrame                        *m_icon;
    // <group DOM_AlertPopup_VcpAlertPopup_Variable>
    VfxTextFrame                    *m_textFrame;
    // <group DOM_AlertPopup_VcpAlertPopup_Variable>
    VcpPopupTypeEnum                m_infoType; 
    // <group DOM_AlertPopup_VcpAlertPopup_Variable>
    VfxS32                          m_textHeight;

private:
    // <group DOM_AlertPopup_VcpAlertPopup_Variable>
    VfxTimer        *m_timer;

};

#endif /* __VCP_POPUP_H__ */

