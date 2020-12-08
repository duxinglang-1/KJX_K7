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
 *  vsrv_input_method_popup.cpp
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  The source file of popup for setting of input method
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 /***************************************************************************** 
  * Include
  *****************************************************************************/
#include "vsrv_input_method_popup.h"
#include "ime\vadp_v2p_input_server.h"
#if defined ( __MMI_IME_V3__)
extern "C"
{
	#include "GlobalResDef.h"
    #include "mmi_rp_srv_editor_def.h"
}
#include "vapp_setting_input_method_setting.h"
#endif
#ifdef  __COSMOS_MMI_PACKAGE__
#if defined (__MMI_MAINLCD_480X800__)
	# define VSRV_INPUT_METHOD_BUTTON_SIZE 400
	# define VSRV_INPUT_METHOD_BUTTON_ROTATE_SIZE 505
	#define  VSRV_INPUT_METHOD_BUTTON_INIT_POS  21
#elif defined (__MMI_MAINLCD_320X480__)
	# define VSRV_INPUT_METHOD_BUTTON_SIZE 265
	# define VSRV_INPUT_METHOD_BUTTON_ROTATE_SIZE 315
	#define  VSRV_INPUT_METHOD_BUTTON_INIT_POS 16
#else
	# define VSRV_INPUT_METHOD_BUTTON_SIZE 205
	# define VSRV_INPUT_METHOD_BUTTON_ROTATE_SIZE 225
	#define  VSRV_INPUT_METHOD_BUTTON_INIT_POS 8
#endif

/***************************************************************************** 
 * Class VsrvInputMethodPopup
 *****************************************************************************/
VsrvInputMethodPopup::VsrvInputMethodPopup(const VfxWString &title, const VfxWString *itemArray, VfxS32 count, VfxS32 selectedItem,
								 VsrvInputMethodPopupCb cbFunc1 ,VsrvInputMethodPopupCbExt cbFunc2, VfxBool showEntrySettingButton, VfxBool showChangeModeButton) :
    m_title(title),
    m_itemArray(itemArray),
    m_count(count),
    m_selectedItem(selectedItem),
    m_cbFunc1(cbFunc1),
	m_cbFunc2(cbFunc2),
	m_showEntrySettingButton(showEntrySettingButton),
	m_showChangeModeButton(showChangeModeButton)
{
}


void VsrvInputMethodPopup::confirmCurrentSelection()
{
    // get the selected item and call callback
    VfxId selectedItem = getFirstSeletedId();
    m_cbFunc1((VfxS32)selectedItem);
}


void VsrvInputMethodPopup::onInit()
{
    VFX_OBJ_GET_INSTANCE(VfxTopLevel)->getActiveScr()->addChildFrame(this);

    VcpSelectPopup::onInit();

    // set the title of popup
    if (m_title.isNull() || m_title.isEmpty())
    {
        VFX_ASSERT(0);
    }
    setText(m_title);

    // set the type
#if defined ( __MMI_IME_V3__)
   setType(VCP_SELECT_POPUP_BUTTON_TYPE_SINGLE);
#else
    setType(VCP_SELECT_POPUP_BUTTON_TYPE_QUICK);
#endif
    // add the item
    if ((m_count <= 0) || (m_itemArray == NULL))
    {
        VFX_ASSERT(0);
    }
    if ((m_selectedItem < 0) || (m_selectedItem >= m_count))
    {
        VFX_ASSERT(0);
    }
    for (VfxS32 i = 0; i < m_count; i++)
    {
        if (i == m_selectedItem)
        {
            addItem((VfxId)i, m_itemArray[i], VFX_TRUE);
        }
        else
        {
            addItem((VfxId)i, m_itemArray[i], VFX_FALSE);
        }
    }

    // check the callback function
//   VFX_ASSERT(m_cbFunc != NULL);

    // set the auto destory
    setAutoDestory(VFX_FALSE);

    setCatchFocus(VFX_FALSE);

    // connect the signal
    m_signalButtonClicked.connect(this, &VsrvInputMethodPopup::selectedItemChanged);
#if defined ( __MMI_IME_V3__)
	  m_RadioMenu->m_signalQuickSelected.connect(this, &VsrvInputMethodPopup::onSelectionChanged);
#endif

    VadpInputServerUI *inputServerUI = VFX_OBJ_GET_INSTANCE(VadpInputServerUI); 

    inputServerUI->registerIMEPopupMenu(this);
}

#if defined ( __MMI_IME_V3__)
void VsrvInputMethodPopup::onSelectionChanged(VfxObject* sender, VfxU32 index)
{
	VsrvInputMethodPopup *self = const_cast<VsrvInputMethodPopup*>(this);
	confirmCurrentSelection();  
	VFX_OBJ_CLOSE(self);
}
#endif

void VsrvInputMethodPopup::onDeinit()
{
    VadpInputServerUI *inputServerUI = VFX_OBJ_GET_INSTANCE(VadpInputServerUI); 

	inputServerUI->leaveIMEPopupMenu(this);
    inputServerUI->unRegisterIMEPopupMenu(this);
    
    VcpSelectPopup::onDeinit();
}

void VsrvInputMethodPopup::onEnter()
{
    VadpInputServerUI *inputServerUI = VFX_OBJ_GET_INSTANCE(VadpInputServerUI); 

    inputServerUI->enterIMEPopupMenu(this);

    VcpSelectPopup::onEnter();
}


#if defined ( __MMI_IME_V3__)
void VsrvInputMethodPopup::onUpdate()
{
	VcpSelectPopup::onUpdate() ;
	VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
	//VfxMainScr* scr = dynamic_cast<VfxMainScr*>(topLevel->getActiveScr());
	VfxMainScr* scr = VFX_OBJ_DYNAMIC_CAST(topLevel->getActiveScr() , VfxMainScr);

	if((scr != NULL ) && m_showChangeModeButton && m_showEntrySettingButton)
	{
		/*Need to show IME Setting and Change Mode Icons*/
		m_button[0]->setImage((IMG_ID_IME_VK_CHANGE_SETTING));
		m_button[0]->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
		m_button[0]->setStyle(VCP_BUTTON_STYLE_DEFAULT);

		m_button[1]->setImage((IMG_ID_IME_VK_CHANGE_MODE));
		m_button[1]->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
		m_button[1]->setStyle(VCP_BUTTON_STYLE_DEFAULT);		
	}
	else if(scr != NULL && m_showEntrySettingButton)
	{
		/*Handwriting Mode ---> Hide Change Mode Icon */
		m_button[0]->setImage((IMG_ID_IME_VK_CHANGE_SETTING));
		m_button[0]->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
		m_button[0]->setStyle(VCP_BUTTON_STYLE_DEFAULT);

		VfxRect buttonRect ; 
		VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
		m_button[1]->setHidden(VFX_TRUE);
		buttonRect = m_button[0]->getInnerRect();
		if (topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_90 || topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_270)
		{
			buttonRect.size.width = VSRV_INPUT_METHOD_BUTTON_ROTATE_SIZE ;
		}
		else
		{
			buttonRect.size.width = VSRV_INPUT_METHOD_BUTTON_SIZE ;
		}
		m_button[0]->setInnerRect(buttonRect);
	}
	else if(m_showChangeModeButton)
	{
		/*Main Screen Not present --> Dont Show IME setting Icon [For JAVA]*/
		m_button[1]->setImage((IMG_ID_IME_VK_CHANGE_MODE));
		m_button[1]->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
		m_button[1]->setStyle(VCP_BUTTON_STYLE_DEFAULT);

		VfxRect buttonRect ; 
		VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
		m_button[0]->setHidden(VFX_TRUE);
		buttonRect = m_button[1]->getInnerRect();
		if (topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_90 || topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_270)
		{
			buttonRect.size.width = VSRV_INPUT_METHOD_BUTTON_ROTATE_SIZE ;
		}
		else
		{
			buttonRect.size.width = VSRV_INPUT_METHOD_BUTTON_SIZE ;
		}
		buttonRect.origin.x = VSRV_INPUT_METHOD_BUTTON_INIT_POS ;
		m_button[1]->setInnerRect(buttonRect);
	}
	else
	{
		/*Both Icons need not to show Like IMEv2 Design*/
		m_button[0]->setHidden(VFX_TRUE);
		m_button[1]->setHidden(VFX_TRUE);
	}
}
#endif

void VsrvInputMethodPopup::selectedItemChanged(VfxObject *sender, VfxId buttonId)
{

#if (defined (__MMI_IME_V3__) && defined(__COSMOS_MMI_PACKAGE__))
if (buttonId == VCP_SELECT_POPUP_BUTTON_CANCEL)
    {
        // get the selected item and call callback
        //VfxId selectedItem = getFirstSeletedId();
        
        
        // delete self
        VsrvInputMethodPopup *self = const_cast<VsrvInputMethodPopup*>(this);
		m_cbFunc2();
        VFX_OBJ_CLOSE(self);
    }
	else if(buttonId == VCP_SELECT_POPUP_BUTTON_OK)
	{
        VsrvInputMethodPopup *self = const_cast<VsrvInputMethodPopup*>(this);
        VFX_OBJ_CLOSE(self);
		VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);

		 //VfxMainScr* scr = dynamic_cast<VfxMainScr*>(topLevel->getActiveScr());
		VfxMainScr* scr = VFX_OBJ_DYNAMIC_CAST(topLevel->getActiveScr() , VfxMainScr);
		 if(scr != NULL)
		 {
			VappIMEInputMethodSetting(scr);
		 }
	}
	else
	{
		VsrvInputMethodPopup *self = const_cast<VsrvInputMethodPopup*>(this);
		VFX_OBJ_CLOSE(self);	
	}
#else
    if (buttonId == VCP_SELECT_POPUP_BUTTON_OK)
    {
        // get the selected item and call callback
        VfxId selectedItem = getFirstSeletedId();
        m_cbFunc1((VfxS32)selectedItem);
        
        // delete self
        VsrvInputMethodPopup *self = const_cast<VsrvInputMethodPopup*>(this);
        VFX_OBJ_CLOSE(self);
    }
#endif
}
#endif


