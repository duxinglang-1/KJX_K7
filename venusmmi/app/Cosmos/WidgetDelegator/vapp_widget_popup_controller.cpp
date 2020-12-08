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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   vapp_popup_controller.cpp
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"
     
#ifdef __MMI_GADGET_SUPPORT__

#include "vfx_uc_include.h"
#include "vcp_popup.h"

#include "vapp_widget_delegator.h"
#include "vapp_widget_view.h"
#include "vapp_widget_popup_controller.h"
#include "mmi_rp_vapp_launcher_cosmos_def.h"


/*****************************************************************************
 * Static Declaration
 *****************************************************************************/

/*****************************************************************************
 * Function
 *****************************************************************************/
VfxBool VappWidgetPopupController::m_isPopup = VFX_FALSE;

extern "C" void vapp_widget_popup_close(VappWidgetPopupController *ptr)
{
    if (ptr == NULL)
    {
        return ;
    }
    
    VFX_OBJ_CLOSE(ptr);
}

VFX_IMPLEMENT_CLASS("VcpWidgetConfirmPopup", VcpWidgetConfirmPopup, VcpConfirmPopup);

VcpWidgetConfirmPopup::VcpWidgetConfirmPopup()
{
    //Do nothing
}

VfxBool VcpWidgetConfirmPopup::onKeyInput(VfxKeyEvent & event)
{
    if (event.keyCode == VFX_KEY_CODE_HOME 
        && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        m_signalButtonClicked.postEmit(this, VCP_POPUP_BUTTON_NO_PRESSED);
    }
    
    return VcpConfirmPopup::onKeyInput(event);
}



VFX_IMPLEMENT_CLASS("VappWidgetPopupController", VappWidgetPopupController, VfxControl);
 
VappWidgetPopupController::VappWidgetPopupController() : 
    m_callback(NULL), 
    m_userData(NULL), 
    m_isCalling(VFX_FALSE),
    m_id(VCP_POPUP_BUTTON_NO_PRESSED)
{
}

void VappWidgetPopupController::onDeinit()
{

    if (m_callback && m_isCalling == VFX_FALSE)
    {
        m_isCalling = VFX_TRUE;
        m_callback(m_id, m_userData);
        m_callback = NULL;
    }

    m_isPopup = VFX_FALSE;
	
	VfxControl::onDeinit();
}

VfxObject *VappWidgetPopupController::getParentObj()
{
    VfxObjListEntry *iter = VappWidgetDelegator::getHead(); 
    VfxObject *parentObj = NULL;

    VappWidgetView *viewApp = 
        (VappWidgetView *) VfxAppLauncher::findApp(VAPP_WIDGET_DELEGATOR, VFX_OBJ_CLASS_INFO(VappWidgetView), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);
    
    if (viewApp)
    {
        parentObj = viewApp->getTopScreen();
    }
    else if (iter)
    {
        VappWidgetDelegator *widget = (VappWidgetDelegator *)iter->get();
        parentObj = iter->get()->getParent();      
    }
   
    return parentObj;

}

 
void VappWidgetPopupController::showPopupWithOk(
    VfxObject *parentObj,
    const VfxWString &text)
{
    showPopup(parentObj, VCP_POPUP_TYPE_WARNING, VCP_CONFIRM_BUTTON_SET_OK, text);
}
 
void VappWidgetPopupController::showPopupWithYesNo(
    VfxObject *parentObj,
    const VfxWString &text)
{
    showPopup(parentObj, VCP_POPUP_TYPE_WARNING, VCP_CONFIRM_BUTTON_SET_YES_NO, text);
}
 
void VappWidgetPopupController::showQueryPopupWithYesNo(
    VfxObject *parentObj,
    const VfxWString &text)
{
    showPopup(parentObj, VCP_POPUP_TYPE_QUESTION, VCP_CONFIRM_BUTTON_SET_YES_NO, text);
}
 
 
void VappWidgetPopupController::showPopup(
    VfxObject *parentObj,
    VcpPopupTypeEnum type,              
    VcpConfirmPopupButtonSetEnum buttonSet, 
    const VfxWString &text)
{
    m_isPopup = VFX_TRUE;

    // show popup
    VFX_OBJ_CREATE(m_confirmPopup, VcpWidgetConfirmPopup, parentObj);
    m_confirmPopup->setInfoType(type);
    m_confirmPopup->setText(text);
    m_confirmPopup->setButtonSet(buttonSet);
    m_confirmPopup->m_signalButtonClicked.connect(this, &VappWidgetPopupController::onPopupButtonClicked);
    m_confirmPopup->setAutoDestory(VFX_FALSE);
    m_confirmPopup->show(VFX_TRUE);

    if (buttonSet == VCP_CONFIRM_BUTTON_SET_USER_DEFINE)
    {
        VfxWString btnText1 = VFX_WSTR_RES(STR_GLOBAL_DELETE);
        VfxWString btnText2 = VFX_WSTR_RES(STR_ID_VAPP_LAUNCHER_COSMOS_KEEP_IT);
        m_confirmPopup->setCustomButton(btnText1, btnText2, VCP_POPUP_BUTTON_TYPE_NORMAL, VCP_POPUP_BUTTON_TYPE_NORMAL);        
    }
}
 
void VappWidgetPopupController::onPopupButtonClicked(VfxObject *sender, VfxId id)
{
    if (id != VCP_CONFIRM_POPUP_BUTTON_YES && 
        id != VCP_CONFIRM_POPUP_BUTTON_NO && 
        id != VCP_CONFIRM_POPUP_BUTTON_OK &&
        id != VCP_CONFIRM_POPUP_BUTTON_CANCEL &&
        id != VCP_POPUP_BUTTON_NO_PRESSED)
    {
        return ;
    }

    m_id = id;

    VfxObjHandle handle = getObjHandle();

    if (m_confirmPopup)
    {
        VFX_OBJ_CLOSE(m_confirmPopup);
    }

    m_isPopup = VFX_FALSE;

    if (m_callback && m_isCalling == VFX_FALSE)
    {
        m_isCalling = VFX_TRUE;
        m_callback(id, m_userData);
		m_callback = NULL;
    }

    if (VfxObject::handleToObject(handle))
    {
        vapp_widget_popup_close(this);
    }
}

void VappWidgetPopupController::setCallback(cb_func cb, void *userData)
{
    m_callback = cb;
    m_userData = userData;
}

#endif
