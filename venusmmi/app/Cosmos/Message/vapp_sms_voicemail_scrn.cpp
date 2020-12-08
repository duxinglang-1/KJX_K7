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
 *  vapp_sms_setting_content.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  SMS setting for Venus UI
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
 * removed!
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "GlobalResDef.h"
#include "vapp_sms_voicemail_scrn.h"
#include "vapp_sms_setting_scrn.h"
#include "mmi_rp_app_vapp_sms_def.h"
#include "Mmi_rp_srv_venus_component_tool_bar_def.h"
#include "vfx_xml_loader.h"
#include "mmi_rp_app_cosmos_global_def.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
    #include "app_usedetails.h"
    #include "UCMSrvGprot.h"
    #include "UCMGprot.h"
    #include "SsSrvGprot.h"
#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Class VappVmServerListPage
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappVmServerListPage", VappVmServerListPage, VfxPage);

void VappVmServerListPage::onInit()
{
    Super::onInit();

    VFX_OBJ_CREATE_EX(m_vmList, VoicemailServerList, this, (m_simId));

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle((VfxResId)STR_ID_VAPP_SMS_VM_SERVER);
    setTopBar(bar);

    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);

    VfxSize parentSize = getSize();
    m_listMenu->setSize(parentSize);
    m_listMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
    m_listMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_FALSE);
    m_listMenu->setContentProvider(this);
    m_listMenu->m_signalItemTapped.connect(this, &Self::onVmListItemTapped);
    m_listMenu->m_signalCmdButtonClicked.connect(this, &Self::onCallButtonClicked);
}

void VappVmServerListPage::onDeinit()
{
    m_listMenu->m_signalItemTapped.disconnect(this, &Self::onVmListItemTapped);
    m_listMenu->m_signalCmdButtonClicked.disconnect(this, &Self::onCallButtonClicked);
    VFX_OBJ_CLOSE(m_listMenu);
    VFX_OBJ_CLOSE(m_vmList);

    Super::onDeinit();
}

VfxU32 VappVmServerListPage::getCount() const
{
    return (VfxU32)m_vmList->getCount();
}

VfxBool VappVmServerListPage::getItemText(VfxU32 index,VcpListMenuFieldEnum fieldType,VfxWString &text, VcpListMenuTextColorEnum &color)
{
    VFX_ASSERT(index < SRV_SMS_MAX_MAILBOX_NUM);

    if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        const VfxWChar *name;
        name = m_vmList->getName(index);

        if (name[0] != '\0')
        {
            text.loadFromMem(name);
        }
        else
        {
            text.loadFromRes(STR_GLOBAL_EMPTY);
        }
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        const VfxWChar *number;
        number = m_vmList->getNumber(index);

        if (number[0] != '\0')
        {
            text.loadFromMem(number);
        }
        else
        {
            text.loadFromRes(STR_GLOBAL_EMPTY);
        }
    }
    return VFX_TRUE;
}

VfxBool VappVmServerListPage::getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        )
{
    VfxBool result = VFX_FALSE;
	VfxU8 sim_index = vapp_sms_sim_id_to_sim_index(m_simId);
    switch (fieldType)
    {
        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL:
		{
        #if (MMI_MAX_SIM_NUM >= 2)
			mmi_rp_app_cosmos_global_img_enum img_call_n[] = 
            {
					IMG_COSMOS_GEMINI_SIM1_LIST_CALL_N,
					IMG_COSMOS_GEMINI_SIM2_LIST_CALL_N,
            #if (MMI_MAX_SIM_NUM >= 3)
					IMG_COSMOS_GEMINI_SIM3_LIST_CALL_N,
				#if (MMI_MAX_SIM_NUM >= 4)
					IMG_COSMOS_GEMINI_SIM4_LIST_CALL_N
            #endif
			#endif  				
				};
			image.setResId(img_call_n[sim_index]);
        #else
			image.setResId(IMG_COSMOS_GEMINI_LIST_CALL_N);
		#endif
            result = VFX_TRUE;
            break;
    	}

        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT:
        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED:
		{
        #if (MMI_MAX_SIM_NUM >= 2)
			mmi_rp_app_cosmos_global_img_enum img_call_p[] = 
            {
					IMG_COSMOS_GEMINI_SIM1_LIST_CALL_P,
					IMG_COSMOS_GEMINI_SIM2_LIST_CALL_P,
            #if (MMI_MAX_SIM_NUM >= 3)
					IMG_COSMOS_GEMINI_SIM3_LIST_CALL_P,
				#if (MMI_MAX_SIM_NUM >= 4)
					IMG_COSMOS_GEMINI_SIM4_LIST_CALL_P
            #endif
            #endif
				};
			image.setResId(img_call_p[sim_index]);
        #else
			image.setResId(IMG_COSMOS_GEMINI_LIST_CALL_P);
		#endif
            result = VFX_TRUE;
            break;
		}

        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED:
		{
        #if (MMI_MAX_SIM_NUM >= 2)
			mmi_rp_app_cosmos_global_img_enum img_call_d[] = 
            {
					IMG_COSMOS_GEMINI_SIM1_LIST_CALL_D,
					IMG_COSMOS_GEMINI_SIM2_LIST_CALL_D,
            #if (MMI_MAX_SIM_NUM >= 3)
					IMG_COSMOS_GEMINI_SIM3_LIST_CALL_D,
				#if (MMI_MAX_SIM_NUM >= 4)
					IMG_COSMOS_GEMINI_SIM4_LIST_CALL_D
            #endif
            #endif							
				};
			image.setResId(img_call_d[sim_index]);
        #else
			image.setResId(IMG_COSMOS_GEMINI_LIST_CALL_D);
		#endif
            result = VFX_TRUE;
            break;
		}

        default :
            break;
    }

    return result;
}

void VappVmServerListPage::onVmListItemTapped(VcpListMenu *sender, VfxU32 index)
{
    VFX_ASSERT(index < SRV_SMS_MAX_MAILBOX_NUM);

    VappVmServerEditPage::VappSmsVmEditInitData data;
    data.simId = m_simId;
    data.vmIndex = index;
    VappVmServerEditPage *page;
    VFX_OBJ_CREATE_EX(page, VappVmServerEditPage, getMainScr(), (data));
    page->m_signalVmServerChanged.connect(this, &Self::onVmServerChanged);
    getMainScr()->pushPage(VFX_ID_NULL, page);
}

void VappVmServerListPage::onVmServerChanged(VfxObject *sender, VfxWString name, VfxWString number, VfxU8 index)
{
    m_vmList->setName(name.getBuf(), index);
    m_vmList->setNumber(number.getBuf(), index);
    m_listMenu->updateItem(index); 
}

void VappVmServerListPage::onCallButtonClicked(VcpListMenu *sender, VfxU32 index)
{
    mmi_ucm_make_call_para_struct make_call_para; 

    mmi_ucm_init_call_para(&make_call_para);
	VfxU8 sim_index = vapp_sms_sim_id_to_sim_index(m_simId);

	srv_ucm_call_type_enum call_type[] = 
		{
			SRV_UCM_VOICE_CALL_TYPE,
#if (MMI_MAX_SIM_NUM >= 2)
			SRV_UCM_VOICE_CALL_TYPE_SIM2,
		#if (MMI_MAX_SIM_NUM >= 3)
			SRV_UCM_VOICE_CALL_TYPE_SIM3,
		#if (MMI_MAX_SIM_NUM >= 4)
			SRV_UCM_VOICE_CALL_TYPE_SIM4
#endif
#endif
#endif
		};
	make_call_para.dial_type = call_type[sim_index];


    make_call_para.adv_para.module_id = SRV_UCM_MODULE_ORIGIN_VOICE_MAIL;

    U16 number[MAX_CC_ADDR_LEN+1];
    memcpy(number, m_vmList->getNumber(index), (MAX_CC_ADDR_LEN+1)*ENCODING_LENGTH);
    make_call_para.ucs2_num_uri = number;
    mmi_ucm_call_launch(0, &make_call_para);
}

void VappVmServerListPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}

/*****************************************************************************
 * Class VappVmServerEditPage Function
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappVmServerEditPage", VappVmServerEditPage, VfxPage);

void VappVmServerEditPage::onInit()
{
    Super::onInit();

    VoicemailServer::VoicemailServerInitData data;
    data.simId = m_simId;
    data.vmIndex = m_index;
    VFX_OBJ_CREATE_EX(m_vm, VoicemailServer, this, (data));

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle((VfxResId)STR_ID_VAPP_SMS_VM_EDIT);
    setTopBar(bar);

    VFX_OBJ_CREATE(m_form, VcpForm, this);

    VfxSize parentSize = getSize();
    m_form->setSize(parentSize);
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VcpFunctionBar *functionBar;
    VFX_OBJ_CREATE(functionBar, VcpFunctionBar, this);
    functionBar->addItem((VfxResId)STR_ID_VAPP_SMS_VK_PREV, (VfxId)ITEM_ID_FUNCBAR_PREV);
    functionBar->addItem((VfxResId)STR_ID_VAPP_SMS_VK_NEXT, (VfxId)ITEM_ID_FUNCBAR_NEXT);
    functionBar->addItem((VfxResId)STR_GLOBAL_SAVE, (VfxId)ITEM_ID_FUNCBAR_SAVE);
    functionBar->setItemSpecial(ITEM_ID_FUNCBAR_SAVE);
    functionBar->m_signalButtonTap.connect(this, &Self::onFunctionBarClicked);

    VcpFormItemTextInput *vmName;
    VFX_OBJ_CREATE(vmName, VcpFormItemTextInput, m_form);
    vmName->setLabelText((VfxResId)STR_ID_VAPP_SMS_VM_NAME);
    vmName->setLabelPosition(VCPFORM_TOP_LEFT);
    const VfxWChar *name = m_vm->getName();
    VcpTextEditor * nameEditor = vmName->getTextBox();
    if (name[0] != '\0')
    {
        nameEditor->setText(
            name,
            m_vm->getMaxNameLen(),
            VFX_FALSE,
            VCP_TEXT_ENCODING_GSM,
            NULL);
    }
    else
    {
        nameEditor->setText(
            VFX_WSTR_EMPTY,
            m_vm->getMaxNameLen(),
            VFX_FALSE,
            VCP_TEXT_ENCODING_GSM,
            NULL);
    }
    nameEditor->setIME(INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | IMM_INPUT_TYPE_SENTENCE | INPUT_TYPE_GSM_EXTENDED_HANDLING);
    nameEditor->setFunctionBar((VfxFrame*)functionBar, VFX_TRUE);
    nameEditor->m_signalActivated.connect(this, &Self::onTextActivated);
    nameEditor->setId(ITEM_ID_VM_EDITOR_NAME);
    m_form->addItem(vmName, ITEM_ID_VM_NAME);

    VcpFormItemTextInput *vmNumber;
    VFX_OBJ_CREATE(vmNumber, VcpFormItemTextInput, m_form);
    vmNumber->setLabelText((VfxResId)STR_ID_VAPP_SMS_VM_NUMBER);
    vmNumber->setLabelPosition(VCPFORM_TOP_LEFT);
    const VfxWChar *number = m_vm->getNumber();
    VcpTextEditor * numberEditor = vmNumber->getTextBox();
    if (number[0] != '\0')
    {
        numberEditor->setText(
            number,
            m_vm->getMaxNumberLen(),
            VFX_FALSE);
    }
    else
    {
        numberEditor->setText(
            VFX_WSTR_EMPTY,
            m_vm->getMaxNumberLen(),
            VFX_FALSE);
    }
    numberEditor->setIME(IMM_INPUT_TYPE_PHONE_NUMBER, IME_PLUS_CHAR_HANDLING);
    numberEditor->setFunctionBar((VfxFrame*)functionBar, VFX_TRUE);
    numberEditor->m_signalActivated.connect(this, &Self::onTextActivated);
    numberEditor->setId(ITEM_ID_VM_EDITOR_NUMBER);
    m_form->addItem(vmNumber, ITEM_ID_VM_NUMBER);

    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->addItem(
        ITEM_ID_TOOLBAR_SAVE,
        (VfxResId)STR_GLOBAL_SAVE,
        VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    m_toolBar->addItem(
        ITEM_ID_TOOLBAR_CANCLE,
        (VfxResId)STR_GLOBAL_CANCEL,
        VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect(this, &Self::onToolbarTapped);
    setBottomBar(m_toolBar);
}

void VappVmServerEditPage::onDeinit()
{
    m_toolBar->m_signalButtonTap.disconnect(this, &Self::onToolbarTapped);

    VcpFormItemTextInput *vmName = (VcpFormItemTextInput*)m_form->getItem(ITEM_ID_VM_NAME);
    VcpFormItemTextInput *vmNumber = (VcpFormItemTextInput*)m_form->getItem(ITEM_ID_VM_NUMBER);
    VcpTextEditor * nameEditor = vmName->getTextBox();
    nameEditor->m_signalActivated.disconnect(this, &Self::onTextActivated);
    VcpTextEditor * numberEditor = vmNumber->getTextBox();
    numberEditor->m_signalActivated.disconnect(this, &Self::onTextActivated);

    m_toolBar->m_signalButtonTap.disconnect(this, &Self::onToolbarTapped);

    VFX_OBJ_CLOSE(m_toolBar);
    VFX_OBJ_CLOSE(m_form);
    VFX_OBJ_CLOSE(m_vm);

    Super::onDeinit();
}

void VappVmServerEditPage::onToolbarTapped(VfxObject *sender, VfxId id)
{
    if (m_toolBar == sender)
    {
        if (id == ITEM_ID_TOOLBAR_SAVE)
        {
            onBarSaveCommond();
        }
        else if (id == ITEM_ID_TOOLBAR_CANCLE)
        {
            getMainScr()->popPage();
        }
    }
}

void VappVmServerEditPage::onFunctionBarClicked(VfxObject *sender, VfxId id)
{
    switch (id)
    {
        case ITEM_ID_FUNCBAR_PREV:
            onSetTextEditorState(ITEM_ID_VM_NAME, VFX_TRUE);
            break;

        case ITEM_ID_FUNCBAR_NEXT:
            onSetTextEditorState(ITEM_ID_VM_NUMBER, VFX_TRUE);
            break;

        case ITEM_ID_FUNCBAR_SAVE:
            onSetTextEditorState(ITEM_ID_VM_NAME, VFX_FALSE);
            onSetTextEditorState(ITEM_ID_VM_NUMBER, VFX_FALSE);
            onBarSaveCommond();
            break;

        default:
            break;
    }
}

void VappVmServerEditPage::onBarSaveCommond()
{
    VcpFormItemTextInput *vmName = (VcpFormItemTextInput*)m_form->getItem(ITEM_ID_VM_NAME);
    VcpFormItemTextInput *vmNumber = (VcpFormItemTextInput*)m_form->getItem(ITEM_ID_VM_NUMBER);
    const VfxWChar *name = vmName->getText().getBuf();
    const VfxWChar *number = vmNumber->getText().getBuf();
    
    if ((number[0] != '\0') 
        && ((applib_is_valid_number_unicode((kal_wchar*)number) == APPLIB_INVALID_NUMBER)
           || (srv_ss_is_valid_ss_string(vapp_sms_sim_id_to_mmi_sim(m_simId), (U8)mmi_ucs2strlen((S8*)number), (WCHAR*)number))
           )
        )
    {
        vmNumber->setWarningText((VfxResId)STR_GLOBAL_INVALID_NUMBER);
    }
    else
    {
        if ((mmi_wcscmp(name, m_vm->getName()) != 0) 
            || (mmi_wcscmp(number, m_vm->getNumber()) != 0)
            )
        {
            m_vm->saveVmServer(name, number);
    
            m_signalVmServerChanged.postEmit(this, vmName->getText(), vmNumber->getText(), m_index);
        }
    
        getMainScr()->popPage();
    }
}

void VappVmServerEditPage::onSetTextEditorState(VfxId id,VfxBool activated)
{
    VcpTextEditor *textEdit;
    VcpFormItemTextInput *textInput = NULL;
    textInput = (VcpFormItemTextInput *)m_form->getItem(id);
    if (textInput)
    {
        textEdit = textInput->getTextBox();

        if (activated)
        {
            textEdit->activate();
        }
        else
        {
            textEdit->deactivate();
        }
    }
}

void VappVmServerEditPage::onTextActivated(VcpTextEditor *sender, VfxBool  activated)
{
    VfxId currId = sender->getId();
    VcpFunctionBar *functionBar = (VcpFunctionBar *)sender->getFunctionBar();

    if (activated)
    {
        if (currId == ITEM_ID_VM_EDITOR_NAME)
        {
            functionBar->setDisableItem(ITEM_ID_FUNCBAR_PREV, VFX_TRUE);
            functionBar->setDisableItem(ITEM_ID_FUNCBAR_NEXT, VFX_FALSE);
        } 
        else if (currId == ITEM_ID_VM_EDITOR_NUMBER)
        {
            functionBar->setDisableItem(ITEM_ID_FUNCBAR_PREV, VFX_FALSE);
            functionBar->setDisableItem(ITEM_ID_FUNCBAR_NEXT, VFX_TRUE);
        }
        else
        {
            functionBar->setDisableItem(ITEM_ID_FUNCBAR_PREV, VFX_TRUE);
            functionBar->setDisableItem(ITEM_ID_FUNCBAR_NEXT, VFX_TRUE);
        }
    }
}

void VappVmServerEditPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}



