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
 *  vtst_sample_add_contact.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Cosmos Sample Screen - Add contact
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_config.h"

#if defined(__AFX_RT_TEST__)
#include "vcp_popup.h"
#include "vcp_form.h"
#include "vcp_button_util.h"
#include "vtst_rt_main.h"

#include "mmi_rp_vtst_sample_def.h"

#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_control.h"
#include "vfx_primitive_frame.h"
#include "vfx_text_frame.h"
#include "vfx_string.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_font_desc.h"
#include "vcp_button.h"
#include "vcp_state_image.h"
#include "vcp_text_editor.h"
#include "vcp_text_view.h"
#include "vfx_app.h"
#include "vfx_main_scr.h"
#include "vfx_page.h"
#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"
#include "vfx_signal.h"
#include "vfx_system.h"
#include "vfx_app_launcher.h"
#include "mmi_res_range_def.h"
#include "GlobalResDef.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"

/***************************************************************************** 
 * Class VtstSampleAddContactHeaderItem
 *****************************************************************************/
class VtstSampleAddContactHeaderItem : public VcpFormItemBase
{
    VFX_DECLARE_CLASS(VtstSampleAddContactHeaderItem);

// Override
protected:
    virtual void onInit();

// Implementation
private:
    enum
    {
        ITEM_WIDTH  = 320,
        ITEM_HEIGHT = 84,
        GAP         = 9,
        TXT_Y       = 18,
        TXT_Y_GAP   = 6
    };
};


VFX_IMPLEMENT_CLASS("VtstSampleAddContactHeaderItem", VtstSampleAddContactHeaderItem, VfxControl);


void VtstSampleAddContactHeaderItem::onInit()
{
    VcpFormItemBase::onInit();

    setSize(ITEM_WIDTH, ITEM_HEIGHT);

    VfxS32 x = GAP;
    VfxS32 y = GAP;

    // create thumbnail image
    VfxImageFrame *img;
    VFX_OBJ_CREATE(img, VfxImageFrame, this);
    img->setResId(IMG_VTST_SAMPLE_ADDCONTACT_CONTACT);
    img->setPos(x, y);

    x += img->getSize().width + GAP;
    y = TXT_Y;
    VfxTextFrame *txt;

    // create last name text
    VFX_OBJ_CREATE(txt, VfxTextFrame, this);
    txt->setString(VFX_WSTR("Last Name"));
    txt->setColor(VFX_COLOR_BLACK);
    txt->setPos(x, y);

    y += txt->getSize().height + TXT_Y_GAP;

    // create title text
    VFX_OBJ_CREATE(txt, VfxTextFrame, this);
    txt->setString(VFX_WSTR("Title"));
    txt->setColor(VFX_COLOR_GREY);
    txt->setFont(VFX_FONT_DESC_SMALL);
    txt->setPos(x, y);

    y += txt->getSize().height + TXT_Y_GAP;

    // create company text
    VFX_OBJ_CREATE(txt, VfxTextFrame, this);
    txt->setString(VFX_WSTR("Company"));
    txt->setColor(VFX_COLOR_GREY);
    txt->setFont(VFX_FONT_DESC_SMALL);
    txt->setPos(x, y);

    x = getSize().width - GAP;
    y = getSize().height - GAP;

    // create edit button
    VcpButton *btn;
    VFX_OBJ_CREATE(btn, VcpButton, this);
    btn->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    btn->setImage(VcpStateImage(IMG_VTST_SAMPLE_ADDCONTACT_EDIT));
    btn->setIsAutoResized(VFX_TRUE, 0, 0);
    btn->setAnchor(1.0, 1.0);
    btn->setPos(x, y);
}


/***************************************************************************** 
 * Class VtstSampleAddContactOtherItem
 *****************************************************************************/
class VtstSampleAddContactOtherItem : public VcpFormItemBase
{
    VFX_DECLARE_CLASS(VtstSampleAddContactOtherItem);

// Default Constructor
public:
    VtstSampleAddContactOtherItem() :
        m_title(NULL)
    {
        for (VfxS32 i = 0 ; i < 32 ; i++)
        {
            m_inputString[i] = 0;
        }
    }

// Override
protected:
    virtual void onInit();

// Method
public:
    virtual void setText(const VfxWString& string);

// Implementation
private:
    enum
    {
        ITEM_WIDTH  = 320,
        ITEM_HEIGHT = 56,
        TXT_WIDTH   = 90,
        INPUT_H     = 38,
        GAP         = 9
    };

    VfxTextFrame* m_title;
    VfxWChar m_inputString[32];
};


VFX_IMPLEMENT_CLASS("VtstSampleAddContactOtherItem", VtstSampleAddContactOtherItem, VfxControl);


void VtstSampleAddContactOtherItem::onInit()
{
    VcpFormItemBase::onInit();

    setSize(ITEM_WIDTH, ITEM_HEIGHT);

    // create title text frame
    VFX_OBJ_CREATE(m_title, VfxTextFrame, this);
    m_title->setSize(TXT_WIDTH, ITEM_HEIGHT - GAP * 2);
    m_title->setColor(VFX_COLOR_BLACK);
    m_title->setAnchor(0, 0.5);
    m_title->setPos(GAP, ITEM_HEIGHT / 2);

    // create input box
    VcpTextEditor *textEditor;
    VFX_OBJ_CREATE(textEditor, VcpTextEditor , this);
    textEditor->setAnchor(0, 0.5);
    textEditor->setPos(TXT_WIDTH + GAP * 2, ITEM_HEIGHT / 2);
    textEditor->setSize(ITEM_WIDTH - TXT_WIDTH - GAP * 3, INPUT_H);
    textEditor->setText(m_inputString, 32);
    textEditor->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
    textEditor->setHint(VFX_WSTR_EMPTY);
}


void VtstSampleAddContactOtherItem::setText(const VfxWString& string)
{
    m_title->setString(string);
}


/***************************************************************************** 
 * Class VtstSampleAddContact
 *****************************************************************************/
class VtstSampleAddContact : public VfxApp
{
    VFX_DECLARE_CLASS(VtstSampleAddContact);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
};

class VtstSampleAddContactScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VtstSampleAddContactScr);

// Override
protected:
    virtual void on1stReady();

private:
};


class VtstSampleAddContactPage : public VfxPage
{
    VFX_DECLARE_CLASS(VtstSampleAddContactPage);

// Override
protected:
    virtual void onInit();

private:
    enum
    {
        ID_TOOLBAR_SAVE,
        ID_TOOLBAR_CANCEL,
        ID_ADD_NUMBER = 10,
        ID_ADD_EMAIL,
        ID_ADD_SNS,
        ID_ADD_IM,
        ID_ADD_ADDRESS,
        ID_NUM_BASE = 999
    };
    enum
    {
        ITEM_WIDTH  = 320,
        BUTTON_W    = 305,
        BUTTON_H    = 45,
        TEXT_W      = 320,
        TEXT_H      = 25
    };

    VfxS32 m_num;
    VcpForm* form;

    void eventHandler(VfxObject* obj, VfxId id);
    void removableHandler(VcpFormItemRemovableTextEntry* obj, VfxId id, VfxBool isAdded);
};


VFX_IMPLEMENT_CLASS("VtstSampleAddContact", VtstSampleAddContact, VfxApp);

void VtstSampleAddContact::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VtstSampleAddContactScr *scr;
    VFX_OBJ_CREATE(scr, VtstSampleAddContactScr, this);
    scr->show();
}


VFX_IMPLEMENT_CLASS("VtstSampleAddContactScr", VtstSampleAddContactScr, VfxMainScr);

void VtstSampleAddContactScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VfxPage *page;
    VFX_OBJ_CREATE(page, VtstSampleAddContactPage, this);
    pushPage(0, page);
}


VFX_IMPLEMENT_CLASS("VtstSampleAddContactPage", VtstSampleAddContactPage, VfxPage);


static VfxWChar g_vtst_sample_add_contact_num_str[64] = {0};
static VfxWChar g_vtst_sample_add_contact_mail_str[64] = {0};


void VtstSampleAddContactPage::onInit()
{
    VfxPage::onInit();  // call base class

    // create title bar
    VcpTitleBar* titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VFX_WSTR("Add new contact"));    // set title text
    setTopBar(titleBar);                                // set as top bar of current page

    VcpFormItemRemovableTextEntry* removableItem;
    VcpFormItemBigAddButton *addBtn;
    VcpFormItemBigArrowButton *bigArrowBtn;

    // create tool bar
    VcpToolBar* toolbar; 
    VFX_OBJ_CREATE(toolbar,VcpToolBar,this);
    toolbar->addItem(ID_TOOLBAR_SAVE, VFX_WSTR("Save"), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);         // add tool bar "save" button
    toolbar->addItem(ID_TOOLBAR_CANCEL, VFX_WSTR("Cancel"), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);   // add tool bar "cancel" button
    toolbar->m_signalButtonTap.connect(this, &VtstSampleAddContactPage::eventHandler);              // connect tool bar signal
    setBottomBar(toolbar);                                                                          // set as bottom bar of current page

    // create form
    VFX_OBJ_CREATE(form, VcpForm, this);
    form->setSize(320, 380);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    // create contact header
    VtstSampleAddContactHeaderItem *contact;
    VFX_OBJ_CREATE(contact, VtstSampleAddContactHeaderItem, form);
    form->addItem(contact);

    // create number caption 
    form->addCaption(VFX_WSTR("Number"));

    m_num = ID_NUM_BASE;

    // create existed number item
    VFX_OBJ_CREATE(removableItem, VcpFormItemRemovableTextEntry, form);	
    removableItem->getLeftButton()->setText(VFX_WSTR("Mobile"));
    vfx_sys_wcscpy(g_vtst_sample_add_contact_num_str, VFX_WSTR("17892873656").getBuf());
    removableItem->getTextBox()->setText(g_vtst_sample_add_contact_num_str, 64);
    removableItem->m_signalAddRemoveClick.connect(this, &VtstSampleAddContactPage::removableHandler);
    removableItem->setId(m_num);
    form->addItem(removableItem, m_num);

    // create new number item
    VFX_OBJ_CREATE(removableItem, VcpFormItemRemovableTextEntry, form);	
    removableItem->getLeftButton()->setText(VFX_WSTR("Home"));
    removableItem->setMode(VFX_TRUE);
    removableItem->m_signalAddRemoveClick.connect(this, &VtstSampleAddContactPage::removableHandler);
    removableItem->setId(ID_ADD_NUMBER);
    form->addItem(removableItem, ID_ADD_NUMBER);

    // create E-mail caption 
    form->addCaption(VFX_WSTR("E-mail"));

    // create existed email item
    VFX_OBJ_CREATE(removableItem, VcpFormItemRemovableTextEntry, form);	
    removableItem->getLeftButton()->setText(VFX_WSTR("Work"));
    vfx_sys_wcscpy(g_vtst_sample_add_contact_mail_str, VFX_WSTR("huang@email.com").getBuf());
    removableItem->getTextBox()->setText(g_vtst_sample_add_contact_mail_str, 64);
    form->addItem(removableItem);

    // create SNS caption 
    form->addCaption(VFX_WSTR("SNS"));

    // create SNS account button
    VFX_OBJ_CREATE(addBtn, VcpFormItemBigAddButton, this);
    addBtn->setButtonText(VFX_WSTR("Add SNS account"));
    form->addItem(addBtn);

    // create IM caption
    VcpFormItemCaption *caption4;
    VFX_OBJ_CREATE(caption4, VcpFormItemCaption, form);
    caption4->setText(VFX_WSTR("IM"));
    form->addItem(caption4);

    // create IM account button
    VFX_OBJ_CREATE(addBtn, VcpFormItemBigAddButton, this);
    addBtn->setButtonText(VFX_WSTR("Add IM account"));
    form->addItem(addBtn);

    // create Other information caption
    VcpFormItemCaption *caption5;
    VFX_OBJ_CREATE(caption5, VcpFormItemCaption, form);
    caption5->setText(VFX_WSTR("Other information"));
    form->addItem(caption5);

    VtstSampleAddContactOtherItem* other;

    // create Birthday
    VFX_OBJ_CREATE(other, VtstSampleAddContactOtherItem, form);
    other->setText(VFX_WSTR("Birthday"));
    form->addItem(other);

    // create add address button
    VFX_OBJ_CREATE(addBtn, VcpFormItemBigAddButton, this);
    addBtn->setButtonText(VFX_WSTR("Add address"));
    form->addItem(addBtn);

    // create Note
    VFX_OBJ_CREATE(other, VtstSampleAddContactOtherItem, form);
    other->setText(VFX_WSTR("Note"));
    form->addItem(other);

    // create Contact settings caption 
    form->addCaption(VFX_WSTR("Contact settings"));

    // create group button
    VFX_OBJ_CREATE(bigArrowBtn, VcpFormItemBigArrowButton, form);
    bigArrowBtn->setButtonText(VFX_WSTR("Group"));
    bigArrowBtn->setHintText(VFX_WSTR("No group"));
    form->addItem(bigArrowBtn);

    // create ringtone button
    VFX_OBJ_CREATE(bigArrowBtn, VcpFormItemBigArrowButton, form);
    bigArrowBtn->setButtonText(VFX_WSTR("Rington"));
    bigArrowBtn->setHintText(VFX_WSTR("Default"));
    form->addItem(bigArrowBtn);

    // create priority sim card button
    VFX_OBJ_CREATE(bigArrowBtn, VcpFormItemBigArrowButton, form);
    bigArrowBtn->setButtonText(VFX_WSTR("Priority SIM card"));
    bigArrowBtn->setHintText(VFX_WSTR("Default card"));
    form->addItem(bigArrowBtn);

    // create storage button
    VcpFormItemBigArrowButton *randomArrowBtn;
    VFX_OBJ_CREATE(bigArrowBtn, VcpFormItemBigArrowButton, this);
    bigArrowBtn->setButtonText(VFX_WSTR("Storage"));	
    bigArrowBtn->setHintText(VFX_WSTR("Phone"));
    form->addItem(bigArrowBtn);

    // create string
    VcpFormItemCustomFrame *sometext;
    VFX_OBJ_CREATE(sometext, VcpFormItemCustomFrame, form);

    VfxTextFrame* txt;
    VFX_OBJ_CREATE(txt, VfxTextFrame, sometext);
    txt->setString(VFX_WSTR("Change storage will lost the information input."));
    txt->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    txt->setSize(TEXT_W, TEXT_H);
    txt->setColor(VFX_COLOR_GREY);
    txt->setFont(VFX_FONT_DESC_SMALL);
    txt->setAnchor(0.5, 0);
    txt->setPos(ITEM_WIDTH / 2, 0);
    sometext->setSize(txt->getSize());
    sometext->attachCustomFrame(txt);

    form->addItem(sometext);
}


void VtstSampleAddContactPage::eventHandler(VfxObject* obj, VfxId id)
{
    switch(id)
    {
        case ID_TOOLBAR_SAVE:
        case ID_TOOLBAR_CANCEL:
            getMainScr()->popPage();
            break;
        default:
            break;
    }
}


void VtstSampleAddContactPage::removableHandler(VcpFormItemRemovableTextEntry* obj, VfxId id, VfxBool isAdded)
{
    if (id == ID_ADD_NUMBER)
    {
        m_num++;

        VcpFormItemRemovableTextEntry* removableItem;
        VFX_OBJ_CREATE(removableItem, VcpFormItemRemovableTextEntry, form);	
    	removableItem->getLeftButton()->setText(VFX_WSTR("Mobile"));
    	removableItem->getTextBox()->setText(g_vtst_sample_add_contact_num_str, 64);
        removableItem->m_signalAddRemoveClick.connect(this, &VtstSampleAddContactPage::removableHandler);
        removableItem->setId(m_num);
    	form->insertItem(removableItem, ID_ADD_NUMBER, m_num);
    }
    else
    {
        form->removeItem(id);
    }
}


VtstTestResultEnum vtst_sample_add_contact(VfxU32 param)
{

    VfxAppLauncher::launchWithAsmSize( 
        APP1_BASE, 
        VFX_OBJ_CLASS_INFO(VtstSampleAddContact),
        GRP_ID_ROOT, 204800 * 1,
        NULL, 0);

    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__
