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
 *  vtst_rt_form.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Vcp Form  testing
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

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vtst_rt_main.h"
#include "vcp_form.h"
 #include "vfx_config.h"
 #include "vfx_cpp_base.h"
 #include "vfx_datatype.h"
 #include "vfx_frame.h"
 #include "vfx_sys_memory.h"
 #include "vfx_object.h"
 #include "vcp_image_button.h"
 #include "GlobalResDef.h"
 #include "vcp_state_image.h"
 #include "vcp_button.h"
 #include "vfx_string.h"
 #include "vfx_signal.h"
 #include "vfx_app_cat_scr.h"

/***************************************************************************/
//    VcpForm Testbed
/***************************************************************************/


class FormAppScreen : public VtstRtScr
{
public:
    typedef VtstRtScr Super;
	
public: 
	FormAppScreen():
		m_newId(1000),
		m_form(NULL)		
        {}
	virtual ~FormAppScreen(){}    

    void onRotate(const VfxScreenRotateParam &param)
    {
        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        if(m_form)
        {
            m_form->setSize(main_screen_size.width, main_screen_size.height - 80);
        }
        VtstRtScr::onRotate(param);
    }
	
	virtual void onInit();
	void onDeinit();
	void SwitchChangeReq(VcpFormItemSwitchCell* item, VfxId id, VfxBool newStatus);
	void onEmailAddRemoveClick(VcpFormItemRemovableTextEntry *item, VfxId id, VfxBool btnType);
	void onEmailAdd(VfxId id);
    void onSNSAdd(VfxId id);
    void onBigButton(VfxId id);
    void onBigArrowButton(VfxId id);        
    virtual VfxS32 phase(VfxS32 idx);
    VfxFrame *generateTopFrame();
	VfxId m_newId;
	VcpForm *m_form;		
}; 



void FormAppScreen ::onInit()
{
	Super::onInit(); 	
	VFX_OBJ_CREATE(m_form, VcpForm, this);
	m_form->setPos(0,10);
	m_form->setSize(getSize().width, (getSize().height*3)/4);

    m_form->setFocused(VFX_TRUE);
	VfxFrame *contactFrm;
	VFX_OBJ_CREATE(contactFrm, VfxFrame, m_form);
	contactFrm->setSize(m_form->getSize().width, 100);

    VcpImageButton *displayPicture;
    VFX_OBJ_CREATE(displayPicture , VcpImageButton , m_form);
    displayPicture->setSize(70, 70); 
	displayPicture->setPos(5, 10);
	displayPicture->setImage(VcpStateImage(IMG_GLOBAL_L1));
	VcpButton *name;
	VFX_OBJ_CREATE(name, VcpButton, contactFrm);
	name->setPos(displayPicture->getSize().width + 5, 10);
	name->setSize(name->getParentFrame()->getSize().width - 
					displayPicture->getSize().width - 20,
						name->getParentFrame()->getSize().height - 20 );
	name->setText(VFX_WSTR("Button on custom item. Left side is image"));	

    VcpFormItemCustomFrame *contact;
    VFX_OBJ_CREATE(contact, VcpFormItemCustomFrame , this);
    contact->attachCustomFrame(contactFrm);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	VcpFormItemCaption *emailCaption;
    VFX_OBJ_CREATE(emailCaption, VcpFormItemCaption, this);
	emailCaption->setText(VFX_WSTR("Caption item"));

    VcpFormItemRemovableTextEntry *emailEntry;
    VFX_OBJ_CREATE(emailEntry, VcpFormItemRemovableTextEntry, m_form);
    emailEntry->getLeftButton()->setText(VFX_WSTR("Email"));
	emailEntry->setMode(VFX_TRUE);
	emailEntry->m_signalAddRemoveClick.connect(this, &FormAppScreen::onEmailAddRemoveClick);

	VcpFormItemBigAddButton *addEmailBtn;
    VFX_OBJ_CREATE(addEmailBtn, VcpFormItemBigAddButton, this);
	addEmailBtn->setButtonText(VFX_WSTR("Add Email"));
	addEmailBtn->m_signalButtonClick.connect(this, &FormAppScreen::onEmailAdd);

	VcpFormItemCaption *SNSCaption;
    VFX_OBJ_CREATE(SNSCaption, VcpFormItemCaption, this);
	SNSCaption->setText(VFX_WSTR("SNS"));
    SNSCaption->setStyle(VCPFORM_STYLE2);

    VcpFormItemRemovableTextEntry *SNSEntry;
    VFX_OBJ_CREATE(SNSEntry, VcpFormItemRemovableTextEntry, m_form);
    SNSEntry->getLeftButton()->setText(VFX_WSTR("SNS"));

	VcpFormItemBigAddButton *addSNSBtn;
    VFX_OBJ_CREATE(addSNSBtn, VcpFormItemBigAddButton, this);
	addSNSBtn->setButtonText(VFX_WSTR("Scroll me to center)"));
    addSNSBtn->m_signalButtonClick.connect(this, &FormAppScreen::onSNSAdd);

	VcpFormItemBigArrowButton *randomArrowBtn;
	VFX_OBJ_CREATE(randomArrowBtn, VcpFormItemBigArrowButton, this);
	randomArrowBtn->setButtonText(VFX_WSTR("Scroll to bottom"));	
    randomArrowBtn->setHintText(VFX_WSTR("try me"));
    randomArrowBtn->m_signalButtonClick.connect(this, &FormAppScreen::onBigArrowButton);

	VcpFormItemLauncherCell *setting;
	VFX_OBJ_CREATE(setting, VcpFormItemLauncherCell, m_form);
	setting->setMainText(VFX_WSTR("Main text (disabled)"));
	setting->setHintText(VFX_WSTR("hint text"));
	setting->setAccessory(VCPFORM_NEXT_ITEM_ICON);

  	VcpFormItemLauncherCell *setting2;
	VFX_OBJ_CREATE(setting2, VcpFormItemLauncherCell, m_form);
	setting2->setMainText(VFX_WSTR("Main text"));
	setting2->setHintText(VFX_WSTR("hint text on right"));
	setting2->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    setting2->setHintPosition(VcpFormItemLauncherCell::HINT_POSITION_RIGHT_END);

	VcpFormItemAidButtonCell *AidBtnTypeSetting;
	VFX_OBJ_CREATE(AidBtnTypeSetting, VcpFormItemAidButtonCell, m_form);
	AidBtnTypeSetting->setMainText(VFX_WSTR("Main text"));
   AidBtnTypeSetting->setHintText(VFX_WSTR("Hint text"));
   AidBtnTypeSetting->setButtonText(VFX_WSTR("Label"));

    
    VcpFormItemSwitchCell *switchTypeSetting;
	VFX_OBJ_CREATE(switchTypeSetting, VcpFormItemSwitchCell, m_form);
	switchTypeSetting->setMainText(VFX_WSTR("Editor warning"));
    switchTypeSetting->setHintText(VFX_WSTR("Valid text"));
	switchTypeSetting->setSwitchStatus(VFX_FALSE);
	switchTypeSetting->m_signalSwitchChangeReq.connect(this, &FormAppScreen::SwitchChangeReq);

   VcpFormItemSwitchCell *ShowHideSwitch;
	VFX_OBJ_CREATE(ShowHideSwitch, VcpFormItemSwitchCell, m_form);
	ShowHideSwitch->setMainText(VFX_WSTR("Label position"));
    ShowHideSwitch->setHintText(VFX_WSTR("Left label"));
	ShowHideSwitch->setSwitchStatus(VFX_FALSE);
	ShowHideSwitch->m_signalSwitchChangeReq.connect(this, &FormAppScreen::SwitchChangeReq);
    
	VcpFormItemTextInput *textInput;
	VFX_OBJ_CREATE(textInput, VcpFormItemTextInput, m_form);
	textInput->setText(VFX_WSTR("type here"));
	textInput->setLabelText(VFX_WSTR("Left label"));
    textInput->setLabelPosition(VCPFORM_LEFT);
    textInput->setWarningText(VFX_WSTR("Invalid input"));

    VcpFormItemBigButton *bigButton;
    VFX_OBJ_CREATE(bigButton, VcpFormItemBigButton, m_form);
    bigButton->setButtonText(VFX_WSTR("Main button text"));
    bigButton->setHintText(VFX_WSTR("Scroll to top"));
    bigButton->m_signalButtonClick.connect(this, &FormAppScreen::onBigButton);

	m_form->addItem(contact,0);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	m_form->addItem(emailEntry, 5);
	m_form->addItem(addEmailBtn, 6);
	m_form->addItem(SNSCaption, 7);
	m_form->addItem(SNSEntry, 8);
	m_form->addItem(addSNSBtn, 9);
    m_form->insertItem(emailCaption, 5, 4);
	m_form->addItem(setting, 10);
	m_form->addItem(switchTypeSetting, 11);
    m_form->addItem(AidBtnTypeSetting, 12);
m_form->insertSeparator(9);
    m_form->addItem(ShowHideSwitch, 13);
    m_form->addItem(textInput, 14);
    m_form->addItem(randomArrowBtn, 15);
    m_form->addItem(setting2, 16);
    m_form->addItem(bigButton, 17);

	((VcpFormItemBigArrowButton*)(m_form->getItem(15)))->setLabelText(VFX_WSTR("Top Label"));
    //m_form->getItem(3)->setIsDisabled(VFX_TRUE);
    m_form->getItem(10)->setIsDisabled(VFX_TRUE);
    //m_form->getItem(6)->setIsDisabled(VFX_TRUE);
	//m_form->removeItem(1);
}

void FormAppScreen::onEmailAddRemoveClick(VcpFormItemRemovableTextEntry *item, VfxId id, VfxBool btnType)
{
	static VfxId newId = 1000;
	if(btnType)
	{
		VcpFormItemRemovableTextEntry *newEntry;
		VFX_OBJ_CREATE(newEntry, VcpFormItemRemovableTextEntry, this);
		newEntry->getLeftButton()->setText(VFX_WSTR("Email"));
		newEntry->getTextBox()->setHint(VFX_WSTR("Type here"));
		newEntry->m_signalAddRemoveClick.connect(this, &FormAppScreen::onEmailAddRemoveClick);
		m_form->insertItem(newEntry, id++);
	}
	else
	{
		m_form->removeItem(id);
	}
}
void FormAppScreen::onBigButton(VfxId id)
{
    m_form->scrollItemToView((VfxId)0, VCPFORM_SCROLL_TOP);
}

void FormAppScreen::onBigArrowButton(VfxId id)
{
    m_form->scrollItemToView(id, VCPFORM_SCROLL_BOTTOM);
}

void FormAppScreen::onSNSAdd(VfxId id)
{
    m_form->scrollItemToView(id, VCPFORM_SCROLL_CENTER);
}

void FormAppScreen::onEmailAdd(VfxId id)
{
		VcpFormItemRemovableTextEntry *newEntry;
		VFX_OBJ_CREATE(newEntry, VcpFormItemRemovableTextEntry, this);
		newEntry->getLeftButton()->setText(VFX_WSTR("Email"));
		newEntry->getTextBox()->setHint(VFX_WSTR("Type here"));
		newEntry->m_signalAddRemoveClick.connect(this, &FormAppScreen::onEmailAddRemoveClick);
		m_form->insertItem(newEntry, id, m_newId++);
}

void FormAppScreen::SwitchChangeReq(VcpFormItemSwitchCell* item, VfxId id, VfxBool newStatus)
{
    item->showProcessInd();

    if(id == 13)
    {
        VcpFormItemTextInput *target = (VcpFormItemTextInput*)(m_form->getItem(14));     
        if(newStatus)
        {
            target->setLabelPosition(VCPFORM_LEFT);
            target->setLabelText(VFX_WSTR("Left label"));
            item->setHintText(VFX_WSTR("Left"));
        }
        else
        {
            target->setLabelPosition(VCPFORM_TOP_LEFT);
            target->setLabelText(VFX_WSTR("Top label"));
            item->setHintText(VFX_WSTR("Top"));
        }
    }
    else if(id ==11)
    {
        VcpFormItemRemovableTextEntry *target = (VcpFormItemRemovableTextEntry*)(m_form->getItem(8));
        //VcpFormItemTextInput *target = (VcpFormItemTextInput*)(m_form->getItem(14));
    if(newStatus)
	{
            target->setWarningText(VFX_WSTR_EMPTY);
            m_form->insertSeparator(item);
            item->setHintText(VFX_WSTR("Valid input"));
	}
    else
	{
            target->setWarningText(VFX_WSTR("Invalid input"));
            m_form->removeSeparator(11);
            item->setHintText(VFX_WSTR("Invalid input"));
        }
	}

    item->setSwitchStatus(newStatus);

}

void FormAppScreen ::onDeinit()
{
    VFX_OBJ_CLOSE(m_form);

    Super::onDeinit();
}

VfxS32 FormAppScreen::phase(VfxS32 idx)
{
    if (idx == 0)
    {
        confirm(VFX_WSTR("Is it OK?"));
        return -1;
    }
    return VTST_RT_END_TESTCASE;
}

	
VtstTestResultEnum vtst_rt_vcp_form(VfxU32 param)
{
    VFX_UNUSED(param);
    VTST_START_SCRN(FormAppScreen);
    return VTST_TR_OK;
}


#endif



