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
 *  vcp_button.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Button Utility for Venus UI
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_BUTTON_UTIL_H__
#define __VCP_BUTTON_UTIL_H__

#ifndef __cplusplus
// If you don't allow C to include this file, remove following //
// #error "This header file can be used in C++ only."
#endif

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_cpp_base.h"
#include "vfx_signal.h"
#include "vcp_button.h"
#if defined(__MMI_VUI_COSMOS_CP__) 

/*****************************************************************************
 * Define
 *****************************************************************************/


/*****************************************************************************
 * Typedef
 *****************************************************************************/

class VfxWString;

/*****************************************************************************
 * Class VcpArrowButton
 * A button with arrow icon
 *****************************************************************************/
class VcpArrowButton : public VcpButton
{
public:
    VcpArrowButton();
protected:
    // <group DOM_Button_VcpArrowButton_Override>
    // On init
    virtual void onInit();
    virtual void onUpdate();
public:
    void setHintText(VfxResId resId);    
    void setHintText(const VfxWChar *mem);
    void setHintText(const VfxWString &text);

    VfxWString getHintText() const;

private:    
    VfxTextFrame *m_hintFrame;
};

/*****************************************************************************
 * Class VcpAddButton
 * A button with add icon
 *****************************************************************************/
class VcpAddButton : public VcpButton
{
public:
    // <group DOM_Button_VcpAddButton_Override>
    // set text
    virtual void setText(VfxResId resId);
    virtual void setText(const VfxWChar *mem);
    virtual void setText(const VfxWString &str);

protected:
    // <group DOM_Button_VcpAddButton_Override>
    // On init
    virtual void onInit();

private:
    VfxRect m_defaultBoundary;
};


/*****************************************************************************
 * Class VcpSim1Button
 * Sim 1 style button
 *****************************************************************************/
class VcpSim1Button : public VcpButton
{
protected:
    // <group DOM_Button_VcpSim1Button_Override>
    // On init
    virtual void onInit();
};


/*****************************************************************************
 * Class VcpSim2Button
 * Sim 2 style button
 *****************************************************************************/
class VcpSim2Button : public VcpButton
{
protected:
    // <group DOM_Button_VcpSim2Button_Override>
    // On init
    virtual void onInit();
};


/*****************************************************************************
 * Class VcpCancelButton
 * A button with cancel icon
 *****************************************************************************/
class VcpCancelButton : public VcpButton
{
protected:
    // <group DOM_Button_VcpCancelButton_Override>
    // On init
    virtual void onInit();
};

/*****************************************************************************
 * Class VcpComboButton
 * A button with an extra child button
 *****************************************************************************/
class VcpComboButton : public VcpButton
{
public:
    // <group DOM_Button_VcpComboButton_Constructor/Destructor>
    VcpComboButton();

protected:
    // <group DOM_Button_VcpComboButton_Override>
    // On init
    virtual void onInit();

    // <group DOM_Button_VcpComboButton_Overridable>
    virtual void onChildBtnClick(VfxObject *btn, VfxId id);
    
    // <group DOM_Button_VcpComboButton_Override>
    virtual void onUpdate();
    
    // <group DOM_Button_VcpComboButton_Override>
    virtual VfxBool onPenInput(VfxPenEvent &event);
	
    // <group DOM_Button_VcpButton_Implementation>
    // Layout button
    virtual void layoutButton();
    
public:
    // <group DOM_Button_VcpComboButton_Override>
    virtual void updateItem();

    // <group DOM_Button_VcpComboButton_Override>
    virtual void setIsDisabled(VfxBool state);
    
    // <group DOM_Button_VcpComboButton_Override>
    void setChildIsDisabled(VfxBool state);

 // <group DOM_Button_VcpComboButton_Override>
    VfxBool getChildIsDisabled();

public:
    // <group DOM_Button_VcpComboButton_Property>
    // Default value : VFX_TRUE
    void setHasChildBtn(VfxBool value, VfxId id = VFX_ID_NULL);

    // <group DOM_Button_VcpComboButton_Property>
    VfxBool getHasChildBtn();

    // <group DOM_Button_VcpComboButton_Property>
    void setChildButtonIcon(const VcpStateImage &icon);

    // <group DOM_Button_VcpComboButton_Property>
    void setHintText(VfxResId resId);

    
    // <group DOM_Button_VcpComboButton_Property>
    void setHintText(const VfxWChar *mem);

    // <group DOM_Button_VcpComboButton_Property>
    void setHintText(const VfxWString &hint);

    // <group DOM_Button_VcpComboButton_Property>
    // Default value : VFX_FALSE
    // When this is true, main (left) button gets disabled, but child button still works
    void setIsOnlyMainBtnDisabled(VfxBool state);

    // <group DOM_Button_VcpComboButton_Property>
    VfxBool getIsOnlyMainBtnDisabled() const;

    // <group DOM_Button_VcpComboButton_Property>
    const VfxWString &getHintText();
    
    // <group DOM_Button_VcpComboButton_Property>
    const VcpStateImage & getChildButtonIcon() const;

    // <group DOM_Button_VcpComboButton_Event>
    // This signal is invoked when the child button is clicked
    // ex: connect to void YourClass::onButtonClicked(VcpButton* sender, VfxId Id)
    VfxSignal2 <VcpButton*, VfxId> m_signalChildBtnClicked;
private:    
    VcpStateImage m_childBtnIcon;
    VcpButton *m_childBtn;
    VfxTextFrame *m_hintTextFrame;
    VfxWString m_hintText;
    VfxBool m_isOnlyMainBtnDisabled;
};

/*****************************************************************************
 * Global Functions
 *****************************************************************************/

VcpButton * vcpCreateArrowButton(VfxObject * parent);
VcpButton * vcpCreateAddButton(VfxBool hasText, VfxObject * parent);
VcpButton * vcpCreateCancelButton(VfxObject * parent);

#endif /* #if defined (__MMI_VUI_COSMOS_CP__)  */ 
#endif /* __VCP_BUTTON_UTIL_H__ */

