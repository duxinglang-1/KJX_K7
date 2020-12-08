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
 *  vsrv_input_method_popup.h
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  The header file of popup for setting of input method
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VSRV_INPUT_METHOD_POPUP_H__
#define __VSRV_INPUT_METHOD_POPUP_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vcp_popup.h"
#ifdef  __COSMOS_MMI_PACKAGE__
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
// <group DOM_InputMethod_Typedef>
// the type for popup to tell the selected item
typedef void (*VsrvInputMethodPopupCb) (VfxS32);
typedef void (*VsrvInputMethodPopupCbExt) (void);


/***************************************************************************** 
 * Class VsrvInputMethodPopup
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VsrvInputMethodPopup is used to show the popup when the user wants to change input mode or
 *  writing language
 */
class VsrvInputMethodPopup : public VcpSelectPopup
{
// Constructor / Destructor
public:
    // <group DOM_InputMethod_VsrvInputMethodPopup_Constructor/Destructor>
    VsrvInputMethodPopup(
        const VfxWString &title,                // [IN] the title of popup
        const VfxWString *itemArray,            // [IN] the array of string to show
        VfxS32 count,                           // [IN] the count of array of string to show
        VfxS32 selectedItem,                    // [IN] the index of selected string
        VsrvInputMethodPopupCb cbFunc1,           // [IN] the callback funtion to tell outside the item user selected
		VsrvInputMethodPopupCbExt cbFunc2,
		VfxBool showEntrySettingButton,
		VfxBool m_showChangeModeButton
        );

// Method
public:
    // <group DOM_InputMethod_VsrvInputMethodPopup_Method>
    // confirm the current selection
    void confirmCurrentSelection();

// Override
protected:
    // <group DOM_InputMethod_VsrvInputMethodPopup_Override>
    virtual void onInit();

    // <group DOM_InputMethod_VsrvInputMethodPopup_Override>
    virtual void onDeinit();

    // <group DOM_InputMethod_VsrvInputMethodPopup_Override>
    virtual void onEnter();

#ifdef __MMI_IME_V3__
	    // <group DOM_InputMethod_VsrvInputMethodPopup_Override>
    virtual void onUpdate();
#endif
// Implementation
private:
    // <group DOM_InputMethod_VsrvInputMethodPopup_Implementation>
    // call this funtion when user selects one item
    void selectedItemChanged(
        VfxObject *sender,                      // [IN] the sender (no use)
        VfxId buttonId                          // [IN] the button clicked (no use)
        );

// Variable
private:
    // <group DOM_InputMethod_VsrvInputMethodPopup_Variable>
    // the title of popup
    VfxWString m_title;

    // <group DOM_InputMethod_VsrvInputMethodPopup_Variable>
    // the array of string to show
    const VfxWString *m_itemArray;

    // <group DOM_InputMethod_VsrvInputMethodPopup_Variable>
    // the count of array of string to show
    VfxS32 m_count;

    // <group DOM_InputMethod_VsrvInputMethodPopup_Variable>
    // the index of selected string
    VfxS32 m_selectedItem;

    // <group DOM_InputMethod_VsrvInputMethodPopup_Variable>
    // the callback funtion to tell outside the item user selected
    VsrvInputMethodPopupCb m_cbFunc1;
	VsrvInputMethodPopupCbExt m_cbFunc2;
	VfxBool m_showEntrySettingButton;
	VfxBool m_showChangeModeButton;

#ifdef __MMI_IME_V3__
	void onSelectionChanged(VfxObject* sender, VfxU32 index);
#endif
};
#endif
#endif /* __VSRV_INPUT_METHOD_POPUP_H__ */


