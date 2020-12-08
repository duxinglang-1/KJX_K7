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
 *  vcp_popup.h
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
#ifndef __VCP_GLOBAL_POPUP_H__
#define __VCP_GLOBAL_POPUP_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vcp_app_scr.h"
#include "vcp_popup.h"
#include "vfx_datatype.h"
#include "vfx_app_cat_scr.h"
#include "vfx_object.h"
#include "vfx_base_popup.h"
#include "vcp_status_icon_bar.h"

extern "C" 
{
    #include "GlobalResDef.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/

// When globol popup screen exit, it will tell app the reuslt of user choose by
// this callback. The button id is defined by VcpConfirmPopup or VcpCommandPopup.
typedef void (*PopupCallBackPtr) (VfxId id, void *userData);
//For the generic global popup, this callback is used to get the popup pointer
// from the application
typedef VfxBasePopup* (*getPopUpHandleCB)(VfxObject* parent, void *userData);
#define VCP_GLOBAL_POPUP_INVALID_HANDLE  GRP_ID_INVALID

/***************************************************************************** 
 * Class VcpGlobalPopupScr
 *   VcpGlobalPopupScr show a small screen that snapshot the previous screen.
 *   then it can show a popup on this screen
 *****************************************************************************/
class VcpGlobalPopupScr : public VfxAppCatScr
{
    VFX_DECLARE_CLASS(VcpGlobalPopupScr);
// Constructor / Destructor
public:
    // <group DOM_GlobalPopup_VcpGlobalPopupScr_Constructor/Destructor>
    // Default constructor
    VcpGlobalPopupScr();
    // <group DOM_GlobalPopup_VcpGlobalPopupScr_Constructor/Destructor>
    VcpGlobalPopupScr(VfxScrRotateTypeEnum dir);

// Override
protected:
    // <group DOM_GlobalPopup_VcpGlobalPopupScr_Override>
    virtual void onInit();  
    // <group DOM_GlobalPopup_VcpGlobalPopupScr_Override>
    virtual void onExit(VfxBool isBackward);
    // <group DOM_GlobalPopup_VcpGlobalPopupScr_Override>
    virtual void onQueryRotateEx(VfxScreenRotateParam& param);
    // <group DOM_GlobalPopup_VcpGlobalPopupScr_Override>
    virtual void onRotate(const VfxScreenRotateParam &param);
	// <group DOM_GlobalPopup_VcpGlobalPopupScr_Override>
	virtual void onEntered(VfxBool isBackward);
    
// Method
public:
    // <group DOM_GlobalPopup_VcpGlobalPopupScr_Method>
    // set the call back
    void setCallBack(PopupCallBackPtr  callBack, void* userData)
    {
        m_callBack = callBack;
        m_userData = userData;
    }
    // <group DOM_GlobalPopup_VcpGlobalPopupScr_Method>
    // set popup
    void setPopup(VfxBasePopup *popup)
    {
        m_popup = popup;
    }
    // <group DOM_GlobalPopup_VcpGlobalPopupScr_Method>
    // get popup
    VfxBasePopup *getPopup()
    {
        return m_popup;
    }
    // <group DOM_GlobalPopup_VcpGlobalPopupScr_Method>
    // set group id
    void setGroupId(MMI_ID id)
    {
        m_groupId = id;
    }
    // <group DOM_GlobalPopup_VcpGlobalPopupScr_Method>
    // set direction
    void setDir(VfxScrRotateTypeEnum dir)
    {
        m_dir = dir;
    }
    
// Implementation
public :
    // <group DOM_GlobalPopup_VcpGlobalPopupScr_Implementation>
    void onButtonClicked(VfxObject* sender, VfxId id);
    // <group DOM_GlobalPopup_VcpGlobalPopupScr_Implementation>
    void onPopupStateChanged(VfxBasePopup* popup, VfxBasePopupStateEnum state);
    
// Variable
private: 
    // <group DOM_GlobalPopup_VcpGlobalPopupScr_Variable>
    VcpStatusIconBar *m_statusBar;
    // <group DOM_GlobalPopup_VcpGlobalPopupScr_Variable>
    PopupCallBackPtr  m_callBack;
    // <group DOM_GlobalPopup_VcpGlobalPopupScr_Variable>
    void *m_userData;
    // <group DOM_GlobalPopup_VcpGlobalPopupScr_Variable>
    VfxBool m_isBackWard;
    // <group DOM_GlobalPopup_VcpGlobalPopupScr_Variable>
    VfxId m_id;
    // <group DOM_GlobalPopup_VcpGlobalPopupScr_Variable>
    VfxBasePopup *m_popup;
    // <group DOM_GlobalPopup_VcpGlobalPopupScr_Variable>
    MMI_ID m_groupId;
    // <group DOM_GlobalPopup_VcpGlobalPopupScr_Variable>
    VfxScrRotateTypeEnum m_dir;
    // <group DOM_GlobalPopup_VcpGlobalPopupScr_Variable>
    VfxBool m_buttonPressed;

};


/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

// New API

// Show a confirm popup with one button and set string by res_id
VfxS32 vcp_global_popup_show_confirm_one_button_id(
        MMI_ID parentID,
        VcpPopupTypeEnum type, 
        VfxResId textResId, 
        VfxResId btnText1ResId, 
        VcpPopupButtonTypeEnum type1,
        PopupCallBackPtr callback,
        void *userData
        );

// Show a confirm popup with two button and set string by res_id
VfxS32 vcp_global_popup_show_confirm_two_button_id(
        MMI_ID parentID,
        VcpPopupTypeEnum type, 
        VfxResId textResId, 
        VfxResId btnText1ResId, 
        VfxResId btnText2ResId,
        VcpPopupButtonTypeEnum type1,
        VcpPopupButtonTypeEnum type2,
        PopupCallBackPtr callback,
        void *userData
        );

// please call those three function sequentially

// Create a command popup and set title string by res_id
VfxS32 vcp_global_popup_show_command_create_id(
        MMI_ID parentID,
        VfxResId textResId, 
        PopupCallBackPtr callback,
        void *userData
        );

// Add a command popup button and set button string by res_id
void vcp_global_popup_show_command_add_id(
        VfxS32 handle,
        VfxId id,                     
        VfxResId btnTextId,        
        VcpPopupButtonTypeEnum type
        );

// Show a command popup for res_id version
void vcp_global_popup_show_command_show_id(VfxS32 handle);


// Cancel a golbal popup by its handle
void vcp_global_popup_cancel(VfxS32 handle);

// string

// Show a confirm popup with one button and set string by string
VfxS32 vcp_global_popup_show_confirm_one_button_str(
        MMI_ID parentID,
        VcpPopupTypeEnum type, 
        const VfxWString &text, 
        const VfxWString &btnText1, 
        VcpPopupButtonTypeEnum type1,
        PopupCallBackPtr callback,
        void *userData
        );

// Show a confirm popup with two button and set string by res_id
VfxS32 vcp_global_popup_show_confirm_two_button_str(
        MMI_ID parentID,
        VcpPopupTypeEnum type, 
        const VfxWString &text, 
        const VfxWString &btnText1, 
        const VfxWString &btnText2,
        VcpPopupButtonTypeEnum type1,
        VcpPopupButtonTypeEnum type2,
        PopupCallBackPtr callback,
        void *userData
        );

// please call those three function sequentially

// Create a command popup and set title string by string
VfxS32 vcp_global_popup_show_command_create_str(
        MMI_ID parentID,
        const VfxWString &text, 
        PopupCallBackPtr callback,
        void *userData
        );

// Add a command popup button and set button string by string
void vcp_global_popup_show_command_add_str(
        VfxS32 handle,
        VfxId id,                     
        const VfxWString &btnText,         
        VcpPopupButtonTypeEnum type
        );

// Show a command popup for string version
void vcp_global_popup_show_command_show_str(VfxS32 handle);

//Show a generic global popup
VfxS32 vcp_global_popup_generic_create(MMI_ID parentID,
									   PopupCallBackPtr callback,
									   getPopUpHandleCB getPopupCB,
									   void* userData
									   );

#ifdef __cplusplus
} /* extern "C"*/
#endif 

/*****************************************************************************
 * Class VcpConfirmPopup
 *****************************************************************************/


#endif /* __VCP_GLOBAL_POPUP_H__ */

