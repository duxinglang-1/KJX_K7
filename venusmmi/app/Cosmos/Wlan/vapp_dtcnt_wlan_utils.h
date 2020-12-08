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
 *  vapp_dtcnt_wlan_utils.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_DTCNT_WLAN_UTILS_H__
#define __VAPP_DTCNT_WLAN_UTILS_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
#include "vapp_dtcnt_wlan_base.h"
#if defined(__MMI_VUI_COSMOS_CP__)
#include "mmi_rp_app_cosmos_global_def.h"
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class VappProfileInfoPopup
 *****************************************************************************/
class VappProfileInfoPopup : public VfxBasePopup
{
// Constructor / Destructor
public:
    VappProfileInfoPopup(); 

// Method
public:
    void setTitle(
        const VfxWString &title // [IN] title
        );
     // set confirm text
    void setText(
        const VfxWString &text                  // [IN] text
        );
     // set confirm text font description
    void setTextFont(
        const VfxFontDesc &font // [IN] text font description
        );
     // get confirm text
    const VfxWString& getText() const
    {
        return m_textFrame->getString();
    }
     // set confirm text font description
    const VfxFontDesc &getTextFont()
    {
        return m_textFrame->getFont();
    }
     // set text alignment mode
    void setTextAlignMode(
        VfxTextFrame::AlignModeEnum value // [IN] text Alignment mode
        );

// override
protected:
     virtual void onInit();
     virtual void onUpdate();
     virtual void onEnter();
     virtual void onExit();
     virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    );
     virtual void onPenInputOnOutside(VfxPenEvent &event);

// implenmention
private:
     void onButtonClick(VfxObject* sender, VfxId id);
     virtual VfxBool onKeyInput(VfxKeyEvent &event);
     
// Signal
public:
     // This singal is invoked when button is clicked
    // void YourClass::onButtonClicked(VfxObject* sender, VfxId id)
    VfxSignal2 <
        VfxObject*,     // sender 
        VfxId           // id
    > m_signalButtonClicked;
     
// Variable
protected:
    // <group DOM_Popup_VcpInputPopup_Variable>
    VfxFrame                        *m_background;
    // <group DOM_Popup_VcpInputPopup_Variable>
    VfxFrame                        *m_titleBg;
    // <group DOM_Popup_VcpInputPopup_Variable>
    VfxWString                      m_title;
    // <group DOM_Popup_VcpInputPopup_Variable>
    VfxTextFrame                    *m_titleFrame;
    // <group DOM_Popup_VcpInputPopup_Variable>
    VfxTextFrame                    *m_textFrame;
    // <group DOM_Popup_VcpInputPopup_Variable>
    VcpButton                       *m_discButton;
    // <group DOM_Popup_VcpInputPopup_Variable>
    VcpButton                       *m_cancelButton;
};

/***************************************************************************** 
 * Class VappWlanTimeLeftPopup
 *****************************************************************************/
class VappWlanTimeLeftPopup : public VcpConfirmPopup
{
   VFX_DECLARE_CLASS(VappWlanTimeLeftPopup);
// Constructor / Destructor
public:
// Constructor block.
    VappWlanTimeLeftPopup(); 

// override
protected:
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    
// Signal
public:
    VfxSignal1 <
        VfxU8           // status
    > m_signalHomeKeyClicked;
};

/***************************************************************************** 
 * Class VappWlanApListMenuCell
 *****************************************************************************/
class VappWlanApListMenuCell : public VcpListMenuCellMultiTextFrame
{
// Constructor / Destructor
public:

    VappWlanApListMenuCell();
    
    virtual ~VappWlanApListMenuCell(){}

// Override
public:

    virtual void onCreateElements();

    virtual void onCloseElements();

    virtual void onLayoutElements();

    virtual void onUpdateElements();

    // virtual VfxBool getText(VcpListMenuFieldEnum fieldType, VfxWString &text);    

// Variable
protected:

/* DOM-NOT_FOR_SDK-BEGIN */
#if defined(__MMI_MAINLCD_320X480__)
    enum
    {
        IMG_LEFT_GAPS    = 10,
        IMG_RIGHT_GAPS   = 10,
        IMG_MAX_WIDTH    = 30
    };
#elif defined(__MMI_MAINLCD_480X800__)
    enum
    {
        IMG_LEFT_GAPS    = 14,
        IMG_RIGHT_GAPS   = 14,
        IMG_MAX_WIDTH    = 48
    };
#elif defined(__MMI_VUI_COSMOS_CP__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__))
    enum
    {
        IMG_LEFT_GAPS    = 5,
        IMG_RIGHT_GAPS   = 5,
        IMG_MAX_WIDTH    = 25
    };
#else /* Shell: QVGA / WQVGA */
    enum
    {
        IMG_LEFT_GAPS    = 11,
        IMG_RIGHT_GAPS   = 11,
        IMG_MAX_WIDTH    = 23
    };
#endif    
/* DOM-NOT_FOR_SDK-END */

    // <group DOM_ListMenu_VcpListMenuCellIconSingleTextFrameEx_Variable>
    // The image element in this client frame
    VfxImageFrame *m_imageFrame;
};

/***************************************************************************** 
 * Class VappWlanAutoConnSwitch
 *****************************************************************************/
// #ifdef	__CBM_BEARER_SWITCH__
class VappWlanSettingSwitchButton : public VcpListMenuCellBaseControl
{
    VFX_DECLARE_CLASS(VappWlanSettingSwitchButton);

public:
    virtual void show() {};
    virtual void hide() {};
    void setSwitchStatus(VfxBool checked);
    void setId( VfxId id ); // [IN] User defined ID
    VfxId getId() const;
    
protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    void OnSwitchSignal(VcpSwitch *sender, VfxBool isChecked);

public:
    VfxSignal2 <VappWlanSettingSwitchButton*, VfxBool> m_signalSwitchChanged;

private:
    VfxBool     m_switchStatus;
    VcpSwitch   *m_switch;
    VfxU8       m_id;
};
// #endif /* __CBM_BEARER_SWITCH__ */

#endif 
