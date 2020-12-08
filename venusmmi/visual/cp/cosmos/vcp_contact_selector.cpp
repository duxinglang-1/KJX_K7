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
 *  vcp_contact_selector.cpp
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  contact selector class
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_contact_selector.h"

// for button image
#include "mmi_rp_srv_venus_component_button_def.h"  

#if defined(__COSMOS_MMI_PACKAGE__) && (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
// for contact button and contact text frame
#include "mmi_rp_vapp_unifiedcomposer_def.h"
#include "mmi_rp_srv_venus_component_text_view_def.h"
#elif defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_SMS_COMPOSER__) 
#include "mmi_rp_vcui_sms_composer_def.h"
#include "mmi_rp_srv_venus_component_text_view_def.h"
#endif

/***************************************************************************** 
 * Class VcpContact
 *****************************************************************************/
VcpContact::VcpContact() : m_next(NULL)
{
    
}


VcpContact &VcpContact::operator =(const VcpContact &other)
{
    m_next = NULL;
    m_name = other.m_name;
    m_phoneNumber = other.m_phoneNumber;
    m_email = other.m_email;

    return *this;
}


VfxBool VcpContact::operator ==(const VcpContact &other) const
{
    if ((m_name == other.m_name) && (m_phoneNumber == other.m_phoneNumber) && (m_email == other.m_email))
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


VcpContact* VcpContact::append(VcpContact* contact)
{    
    if (m_next == NULL)
        m_next = contact;
    else
        m_next->append(contact);

    return contact;
}


/***************************************************************************** 
 * Class VcpContactSelector
 *****************************************************************************/

VcpContactSelector::VcpContactSelector() :
    m_inputbox(NULL),
    m_button(NULL),
    m_hintTextFrame(NULL),
    m_hintText(VFX_WSTR("To:")),
    m_contact(NULL),
    m_contactButton(NULL),
    m_moreButton(NULL),
    m_count(0),
    m_displayCount(0),
    m_isContactHide(VFX_TRUE),
    m_isHideContactList(VFX_FALSE),
    m_truncateText(NULL),
    m_contactText(NULL),
    m_hiliteBtnIdx(-1)
{
    // Initialize
}


void VcpContactSelector::onInit()
{
    VfxControl::onInit();

    // hint text
    VfxFontDesc fontDesc;
    //fontDesc.size = VFX_FONT_DESC_VF_SIZE(VCP_CONTACT_SELECTOR_CONTACT_HINT_FONT_SZIE);
	#if defined(__COSMOS_MMI_PACKAGE__)
		fontDesc = VFX_FONT_RES(VCP_FNT_TEXT_VIEW_TXT);
	#else
		fontDesc.size = VFX_FONT_DESC_VF_SIZE(VCP_CONTACT_SELECTOR_CONTACT_HINT_FONT_SZIE);
	#endif
    VFX_OBJ_CREATE(m_hintTextFrame, VfxTextFrame, this);
    m_hintTextFrame->setString(m_hintText);
    m_hintTextFrame->setPos(VfxPoint(0, 0));
    m_hintTextFrame->setColor(VFX_COLOR_BLACK);         /* set font color */
    m_hintTextFrame->setFont(fontDesc);
    m_hintTextFrame->forceUpdate();
    
    VFX_OBJ_CREATE(m_inputbox, VcpContactEditor, this);
    m_inputbox->setText(VFX_WSTR_EMPTY, VCP_CONTACT_SELECTOR_INPUTBOX_MAX_CHARS);
    m_inputbox->setPos(0, 0);
    m_inputbox->setBounds(VfxRect(
        0,
        0,
        VCP_CONTACT_SELECTOR_INPUTBOX_WIDTH,
        VCP_CONTACT_SELECTOR_INPUTBOX_HEIGHT));
    m_inputbox->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
    m_inputbox->setMarginFrame(VCP_TEXT_MARGIN_FRAME_LEFT, m_hintTextFrame);
    m_inputbox->setHint(VFX_WSTR_EMPTY);
   
    // connect signal
    m_inputbox->m_signalActivated.connect(this, &VcpContactSelector::onTextEditorActivated); /* connect the signal when editable mode is activated or deactivated*/
    m_inputbox->m_signalTextChanged.connect(this, &VcpContactSelector::onTextChanged);       /* connect the signal of any text changed */
    m_inputbox->setAlignParent(
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_NONE);
    // create button
    VFX_OBJ_CREATE(m_button, VcpButton, this);
    m_button->setBounds(VfxRect(0, 0, VCP_CONTACT_SELECTOR_BUTTON_WIDTH, VCP_CONTACT_SELECTOR_BUTTON_HEIGHT));
    m_button->m_signalClicked.connect(this, &VcpContactSelector::onButtonClick);
    m_button->setStyle(VCP_BUTTON_STYLE_DEFAULT);
    m_button->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    
#if defined(__COSMOS_MMI_PACKAGE__) && (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
    m_button->setImage(VcpStateImage(IMG_ID_VAPP_UC_CONTACT_ICON, 
                                    IMG_ID_VAPP_UC_CONTACT_ICON, 
                                    IMG_ID_VAPP_UC_CONTACT_ICON, 
                                    IMG_ID_VAPP_UC_CONTACT_ICON));
#elif defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_SMS_COMPOSER__) 
    m_button->setImage(VcpStateImage(IMG_ID_VCUI_SMSC_CONTACT_ICON, 
                                    IMG_ID_VCUI_SMSC_CONTACT_ICON, 
                                    IMG_ID_VCUI_SMSC_CONTACT_ICON, 
                                    IMG_ID_VCUI_SMSC_CONTACT_ICON));
#endif

    m_button->setId(VCP_CONTACT_SELECTOR_SEARCH_BTN_ID);
	   m_button->setAlignParent(
                    VFX_FRAME_ALIGNER_MODE_NONE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_NONE);

    m_signalBoundsChanged.connect(this, &VcpContactSelector::onBoundsChanged);

    checkUpdate();
}


void VcpContactSelector::onUpdate()
{
    VfxS32 height = 0;
    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VCP_CONTACT_SELECTOR_CONTACT_BUTTON_FONT_SZIE);

    VfxS32 csWidth = 0;
    // we use fixed width for contact selector which dependences on the screen width
    // so we need to get the screen which contains the component
    // if we use mainScreenSize, the size maybe not correct when switch screen
    // for example: A(composer screen) -> B(Camera screen) -> A
    // the mainScreenSize get here maybe the screen size of B which is Rotated
    VfxScreen *screen = findScreen();
    if (screen)
    {
        csWidth = screen->getBounds().getWidth() - 2 * VCP_CONTACT_SELECTOR_LR_GAP;
    }
    else
    {
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
        csWidth = mainScreenSize.width - 2 * VCP_CONTACT_SELECTOR_LR_GAP;
    }

    VcpStateImage contactBtnImageList;
#if defined(__COSMOS_MMI_PACKAGE__) && (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
    if (m_isContactHide)
    {
        contactBtnImageList.setImage(
            VfxImageSrc(IMG_ID_VAPP_UC_CONTACT_BTN_BG_NRL),
            VfxImageSrc(IMG_ID_VAPP_UC_CONTACT_BTN_BG_NRL),
            VfxImageSrc(IMG_ID_VAPP_UC_CONTACT_BTN_BG_NRL),
            VfxImageSrc(IMG_ID_VAPP_UC_CONTACT_BTN_BG_NRL));
    }
    else
    {
        contactBtnImageList.setImage(
            VfxImageSrc(IMG_ID_VAPP_UC_CONTACT_BTN_BG_NRL),
            VfxImageSrc(IMG_ID_VAPP_UC_CONTACT_BTN_BG_HLT),
            VfxImageSrc(IMG_ID_VAPP_UC_CONTACT_BTN_BG_NRL),
            VfxImageSrc(IMG_ID_VAPP_UC_CONTACT_BTN_BG_HLT));
    }
#elif defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_SMS_COMPOSER__) 
    if (m_isContactHide)
    {
        contactBtnImageList.setImage(
            VfxImageSrc(IMG_ID_VCUI_SMSC_CONTACT_BTN_BG_NRL),
            VfxImageSrc(IMG_ID_VCUI_SMSC_CONTACT_BTN_BG_NRL),
            VfxImageSrc(IMG_ID_VCUI_SMSC_CONTACT_BTN_BG_NRL),
            VfxImageSrc(IMG_ID_VCUI_SMSC_CONTACT_BTN_BG_NRL));
    }
    else
    {
        contactBtnImageList.setImage(
            VfxImageSrc(IMG_ID_VCUI_SMSC_CONTACT_BTN_BG_NRL),
            VfxImageSrc(IMG_ID_VCUI_SMSC_CONTACT_BTN_BG_HLT),
            VfxImageSrc(IMG_ID_VCUI_SMSC_CONTACT_BTN_BG_NRL),
            VfxImageSrc(IMG_ID_VCUI_SMSC_CONTACT_BTN_BG_HLT));
    }
#endif

    // set Inputbox and Search button position
    VfxS32 inputboxWidth = csWidth - VCP_CONTACT_SELECTOR_BUTTON_GAP - VCP_CONTACT_SELECTOR_BUTTON_WIDTH;
    m_inputbox->setPos(0, 0);
    m_inputbox->setSize(
        inputboxWidth,
        VCP_CONTACT_SELECTOR_INPUTBOX_HEIGHT);
    m_inputbox->setAlignParent(
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_NONE);
    // set search button position
   // m_button->setPos(csWidth - VCP_CONTACT_SELECTOR_BUTTON_WIDTH, 0);
    if(m_button->getState() == VCP_BUTTON_STATE_PRESSED)
    {
        m_button->setState(VCP_BUTTON_STATE_NORMAL);
    }
    m_button->setInnerRect(VfxRect(csWidth - VCP_CONTACT_SELECTOR_BUTTON_WIDTH, 0, VCP_CONTACT_SELECTOR_BUTTON_WIDTH, VCP_CONTACT_SELECTOR_BUTTON_HEIGHT));
    m_button->setAlignParent(
                    VFX_FRAME_ALIGNER_MODE_NONE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_NONE);
    if (m_contactButton)
    {
        for (VfxS32 i = 0; i < m_displayCount; i++)
        {
            VFX_OBJ_CLOSE(m_contactButton[i]);
        }
        VFX_FREE_MEM(m_contactButton);
        m_displayCount = 0;
    }

    if (m_moreButton)
    {
        VFX_OBJ_CLOSE(m_moreButton);
    }

    if (m_truncateText)
    {
        VFX_OBJ_CLOSE(m_truncateText);
    }

    if (m_contactText)
    {
        VFX_OBJ_CLOSE(m_contactText);
    }

    if (m_inputbox->isActive() && m_isHideContactList == VFX_TRUE)
    {
        return;
    }

#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)
    // show contacts in button, if contact length exceed two lines, show more button which indicate the total contacts number
    if (m_count > 0)
    {
        if (!m_isContactHide)
        {
            // expand the contact list and display under inputbox
            VFX_ALLOC_MEM(m_contactButton, m_count * sizeof(VcpButton *), this);
            VcpContact *pContact = m_contact;
            VfxS32 i = 0;
            VfxS32 xPos = 0;
            VfxS32 yPos = VCP_CONTACT_SELECTOR_INPUTBOX_HEIGHT + VCP_CONTACT_SELECTOR_TOP_GAP;
            VfxU8 lineNum = 0;
            VfxS32 offsetX = 0;

            vrt_size_struct mainScreenSize;
            vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

            if (m_truncateText)
            {
                VFX_OBJ_CLOSE(m_truncateText);
            }

            height = VCP_CONTACT_SELECTOR_CONTACT_BUTTON_HEIGHT;

            VfxS32 deleteBtnWidth = VCP_CONTACT_SELECTOR_CONTACT_DELETE_ICON_WIDTH;

            while (pContact && (lineNum < VCP_CONTACT_SELECTOR_MAX_LINE_NUM))
            {
                VFX_OBJ_CREATE(m_contactButton[i], VcpButton, this);
                if (!(pContact->m_name.isEmpty()))
                {
                    m_contactButton[i]->setText(pContact->m_name);
                }
                else if (!(pContact->m_phoneNumber.isEmpty()))
                {
                    m_contactButton[i]->setText(pContact->m_phoneNumber);
                }
                else if (!(pContact->m_email.isEmpty()))
                {
                    m_contactButton[i]->setText(pContact->m_email);
                }
                else
                {
                    VFX_ASSERT(0);
                }

                m_contactButton[i]->setMargin(
                    VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MARGIN,
                    VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MARGIN,
                    VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MARGIN,
                    VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MARGIN);
                m_contactButton[i]->setBgImageList(contactBtnImageList);
                m_contactButton[i]->setRect(VfxRect(xPos, yPos, 0, VCP_CONTACT_SELECTOR_CONTACT_BUTTON_HEIGHT));
                m_contactButton[i]->m_signalClicked.connect(this, &VcpContactSelector::onContactButtonClick);
                m_contactButton[i]->setTextColor(VFX_COLOR_BLACK, VFX_COLOR_WHITE, VFX_COLOR_GREY, VFX_COLOR_WHITE);
                if (lineNum == (VCP_CONTACT_SELECTOR_MAX_LINE_NUM - 1))
                {
                    m_contactButton[i]->setIsAutoResized(
                        VFX_TRUE,
                        VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MIN_WIDTH,
                        csWidth - VCP_CONTACT_SELECTOR_MORE_BTN_WIDTH - VCP_CONTACT_SELECTOR_RIGHT_GAP);
                }
                else
                {
                    m_contactButton[i]->setIsAutoResized(
                        VFX_TRUE,
                        VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MIN_WIDTH,
                        csWidth);
                }
                m_contactButton[i]->setTextFont(fontDesc);
                m_contactButton[i]->setId(i);

                // set highlight
                if (m_hiliteBtnIdx == i)
                {
                    m_contactButton[i]->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_RIGHT);
                    m_contactButton[i]->setIsHighlighted(VFX_TRUE);
                #if defined(__COSMOS_MMI_PACKAGE__) && (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
                    m_contactButton[i]->setImage(VcpStateImage(IMG_ID_VAPP_UC_CONTACT_BTN_DELETE, 
                                    IMG_ID_VAPP_UC_CONTACT_BTN_DELETE, 
                                    IMG_ID_VAPP_UC_CONTACT_BTN_DELETE, 
                                    IMG_ID_VAPP_UC_CONTACT_BTN_DELETE));
                #elif defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_SMS_COMPOSER__) 
                    m_contactButton[i]->setImage(VcpStateImage(IMG_ID_VCUI_SMSC_CONTACT_BTN_DELETE, 
                                    IMG_ID_VCUI_SMSC_CONTACT_BTN_DELETE, 
                                    IMG_ID_VCUI_SMSC_CONTACT_BTN_DELETE, 
                                    IMG_ID_VCUI_SMSC_CONTACT_BTN_DELETE));
                #endif
                    deleteBtnWidth = 0;
                }
                else
                {
                    m_contactButton[i]->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
                    m_contactButton[i]->setIsHighlighted(VFX_FALSE);
                }

                m_contactButton[i]->forceUpdate();

                offsetX += m_contactButton[i]->getBounds().getWidth();

                if (offsetX >= (csWidth - deleteBtnWidth) &&
                    lineNum < (VCP_CONTACT_SELECTOR_MAX_LINE_NUM - 1))
                {
                    offsetX = 0;

                    if (m_count > 1)
                    {
                        yPos += VCP_CONTACT_SELECTOR_CONTACT_BUTTON_HEIGHT + VCP_CONTACT_SELECTOR_LINE_GAP;
                        height += VCP_CONTACT_SELECTOR_CONTACT_BUTTON_HEIGHT + VCP_CONTACT_SELECTOR_LINE_GAP;
                    }
					deleteBtnWidth = VCP_CONTACT_SELECTOR_CONTACT_DELETE_ICON_WIDTH ;
                    lineNum++;

                    // new line
                    if (i > 0)
                    {
                        m_contactButton[i]->setPos(VfxPoint(offsetX, yPos));

                        if (i != m_count - 1)
                        {
                            // force update the button with new max width considering the more button width
                            m_contactButton[i]->setIsAutoResized(
                                VFX_TRUE,
                                VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MIN_WIDTH,
                                csWidth - VCP_CONTACT_SELECTOR_MORE_BTN_WIDTH - VCP_CONTACT_SELECTOR_RIGHT_GAP);
                            m_contactButton[i]->forceUpdate();
                        }

                        offsetX += m_contactButton[i]->getBounds().getWidth() + VCP_CONTACT_SELECTOR_CONTACT_GAP;
                    }
                }
                else if (offsetX > (csWidth - deleteBtnWidth - VCP_CONTACT_SELECTOR_MORE_BTN_WIDTH - VCP_CONTACT_SELECTOR_RIGHT_GAP) &&
                    (lineNum == (VCP_CONTACT_SELECTOR_MAX_LINE_NUM - 1)))
                {
                    // this is last line, need show more button
                    if (m_moreButton == NULL)
                    {
                        VFX_OBJ_CREATE(m_moreButton, VcpButton, this);
                    }

                    m_moreButton->setSize(VCP_CONTACT_SELECTOR_MORE_BTN_WIDTH, VCP_CONTACT_SELECTOR_CONTACT_BUTTON_HEIGHT);
                    m_moreButton->setTextFont(fontDesc);
                    VfxWString remainingCount;
                    remainingCount.format("%d", m_count);
                    m_moreButton->setText(remainingCount);
                    m_moreButton->setTextColor(VFX_COLOR_BLACK, VFX_COLOR_BLACK, VFX_COLOR_BLACK, VFX_COLOR_BLACK);
                    m_moreButton->setId(VCP_CONTACT_SELECTOR_MORE_BTN_ID);
                    m_moreButton->m_signalClicked.connect(this, &VcpContactSelector::onButtonClick);
                    m_moreButton->setIsAutoResized(VFX_TRUE, VCP_CONTACT_SELECTOR_MORE_BTN_WIDTH);
                    m_moreButton->setStyle(VCP_BUTTON_STYLE_DEFAULT);
                    m_moreButton->setMargin(
                                    VCP_CONTACT_SELECTOR_MORE_BTN_L_MARGIN,
                                    VCP_CONTACT_SELECTOR_MORE_BTN_T_MARGIN,
                                    VCP_CONTACT_SELECTOR_MORE_BTN_R_MARGIN,
                                    VCP_CONTACT_SELECTOR_MORE_BTN_B_MARGIN);

                    m_moreButton->forceUpdate();
                    m_moreButton->setPos(
                        csWidth - m_moreButton->getBounds().getWidth(),
                        yPos);

                    // close the contact which is exceed width
                    VFX_OBJ_CLOSE(m_contactButton[i]);
                    lineNum++;
                    break;
                }
                else
                {
                    offsetX += VCP_CONTACT_SELECTOR_CONTACT_GAP;
                }
                xPos = offsetX;
                pContact = pContact->m_next;
                i++;
            }
            m_displayCount = i;

            m_inputbox->setContactRect(VfxRect(
                0,
                m_inputbox->getSize().height + VCP_CONTACT_SELECTOR_TOP_GAP,
                getBounds().getWidth(),
                height));
        }
        else
        {
            // unfold the contact list and show the contact list within inputbox area
            VFX_ALLOC_MEM(m_contactButton, m_count * sizeof(VcpButton *), this);
            VcpContact *pContact = m_contact;
            VfxS32 i = 0;
            VfxS32 inputBoxLeftMargin, inputBoxRightMargin;
            m_inputbox->getMargins(&inputBoxLeftMargin, NULL, &inputBoxRightMargin, NULL);
            VfxS32 xPos = inputBoxLeftMargin + VCP_CONTACT_SELECTOR_LEFT_GAP;

            vrt_size_struct mainScreenSize;
            vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

            VFX_OBJ_CREATE(m_truncateText, VfxTextFrame, this);
            m_truncateText->setAnchor(0, 0.5f);
            m_truncateText->setFont(fontDesc);
            m_truncateText->setString(VFX_WSTR("..."));
            m_truncateText->setColor(VFX_COLOR_BLACK);
            m_truncateText->setIsUnhittable(VFX_TRUE);

            while (pContact)
            {
                VFX_OBJ_CREATE(m_contactButton[i], VcpButton, this);
                m_contactButton[i]->setAnchor(0, 0.5f);
                if (!(pContact->m_name.isEmpty()))
                {
                    m_contactButton[i]->setText(pContact->m_name);
                }
                else if (!(pContact->m_phoneNumber.isEmpty()))
                {
                    m_contactButton[i]->setText(pContact->m_phoneNumber);
                }
                else if (!(pContact->m_email.isEmpty()))
                {
                    m_contactButton[i]->setText(pContact->m_email);
                }
                else
                {
                    VFX_ASSERT(0);
                }
                m_contactButton[i]->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
                m_contactButton[i]->setMargin(
                    VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MARGIN,
                    VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MARGIN,
                    VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MARGIN,
                    VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MARGIN);
                m_contactButton[i]->setBgImageList(contactBtnImageList);
                // vertical center align with inputbox
                m_contactButton[i]->setPos(xPos, VCP_CONTACT_SELECTOR_INPUTBOX_HEIGHT / 2);
                m_contactButton[i]->setSize(0, VCP_CONTACT_SELECTOR_CONTACT_BUTTON_HEIGHT);
                m_contactButton[i]->m_signalClicked.connect(this, &VcpContactSelector::onContactButtonClick);
                m_contactButton[i]->setTextColor(VFX_COLOR_BLACK, VFX_COLOR_BLACK, VFX_COLOR_BLACK, VFX_COLOR_BLACK);
                m_contactButton[i]->setIsAutoResized(
                    VFX_TRUE,
                    VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MIN_WIDTH,
                    VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MAX_WIDTH);
                m_contactButton[i]->setTextFont(fontDesc);
                m_contactButton[i]->forceUpdate();
                m_contactButton[i]->setId(i);

                xPos += m_contactButton[i]->getBounds().getWidth() + VCP_CONTACT_SELECTOR_CONTACT_GAP;

                if (((i < m_count - 1) &&
                    (xPos > m_inputbox->getPos().x + m_inputbox->getBounds().getWidth() - VCP_CONTACT_SELECTOR_RIGHT_GAP - m_truncateText->getBounds().getWidth() - VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MARGIN * 2)) ||
                    (xPos > m_inputbox->getPos().x + m_inputbox->getBounds().getWidth() - VCP_CONTACT_SELECTOR_RIGHT_GAP))
                {
                    // display truncate text button
                    m_contactButton[i]->setText(VFX_WSTR("..."));
                    i++;
                    break;
                }

                pContact = pContact->m_next;
                i++;
            }

            VFX_OBJ_CLOSE(m_truncateText);
            m_displayCount = i;
        }
    }
#else
    // show contacts with text, always show more button which indicate the total contacts number
    // create contact list
    if (m_count > 0)
    {
        // concat all the contact as one string
        VfxS32 idx = 0;
        VfxS32 remainLen;
        VfxWChar contactText[201];
        remainLen = 200;
        contactText[0] = 0;
        VcpContact *p = m_contact;
        VfxS32 offset = 0;
        for (idx = 0; idx < m_count; idx++)
        {
            VfxWChar sepStr[2] = {L';', 0};
            if (!(p->m_name.isEmpty()))
            {
                vfx_sys_wcsncpy(contactText + offset, p->m_name.getBuf(), remainLen);
                remainLen -= p->m_name.getLength();
                offset += p->m_name.getLength();
            }
            else if (!(p->m_phoneNumber.isEmpty()))
            {
                vfx_sys_wcsncpy(contactText + offset, p->m_phoneNumber.getBuf(), remainLen);
                remainLen -= p->m_phoneNumber.getLength();
                offset += p->m_phoneNumber.getLength();
            }
            else if (!(p->m_email.isEmpty()))
            {
                vfx_sys_wcsncpy(contactText + offset, p->m_email.getBuf(), remainLen);
                remainLen -= p->m_email.getLength();
                offset += p->m_email.getLength();
            }
            else
            {
                VFX_ASSERT(0);
            }

            if (remainLen < 0)
                break;
            vfx_sys_wcsncpy(contactText + offset, sepStr, remainLen);
            remainLen--;
            offset++;
            if (remainLen <= 0)
                break;

            p = p->getNext();
        }

        VFX_OBJ_CREATE(m_contactText, VfxTextFrame, this);
        m_contactText->setString(VFX_WSTR_MEM(contactText));
#if defined(__COSMOS_MMI_PACKAGE__) && (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
        m_contactText->setColor(VFX_COLOR_RES(CLR_ID_VAPP_UC_CONTACT_TEXT_FRAME));
#elif defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_SMS_COMPOSER__) 
        m_contactText->setColor(VFX_COLOR_RES(CLR_ID_VCUI_SMSC_CONTACT_TEXT_FRAME));
#else
        m_contactText->setColor(VFX_COLOR_BLACK);
#endif
        m_contactText->setFont(fontDesc);
        m_contactText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

        if (!m_isContactHide)
        {
            // show contact list under inputbox

            // more button
            if (m_moreButton == NULL)
            {
                VFX_OBJ_CREATE(m_moreButton, VcpButton, this);
            }

            m_moreButton->setSize(VCP_CONTACT_SELECTOR_MORE_BTN_WIDTH, VCP_CONTACT_SELECTOR_CONTACT_BUTTON_HEIGHT);
            m_moreButton->setTextFont(fontDesc);
            VfxWString remainingCount;
            remainingCount.format("%d", m_count);
            m_moreButton->setText(remainingCount);
            m_moreButton->setTextColor(VFX_COLOR_BLACK, VFX_COLOR_BLACK, VFX_COLOR_BLACK, VFX_COLOR_BLACK);
            m_moreButton->setId(VCP_CONTACT_SELECTOR_MORE_BTN_ID);
            m_moreButton->m_signalClicked.connect(this, &VcpContactSelector::onButtonClick);
            m_moreButton->setIsAutoResized(VFX_TRUE, VCP_CONTACT_SELECTOR_MORE_BTN_WIDTH);
            m_moreButton->setStyle(VCP_BUTTON_STYLE_DEFAULT);
            m_moreButton->setMargin(
                            VCP_CONTACT_SELECTOR_MORE_BTN_L_MARGIN,
                            VCP_CONTACT_SELECTOR_MORE_BTN_T_MARGIN,
                            VCP_CONTACT_SELECTOR_MORE_BTN_R_MARGIN,
                            VCP_CONTACT_SELECTOR_MORE_BTN_B_MARGIN);
            m_moreButton->forceUpdate();
            m_moreButton->setPos(
                csWidth - m_moreButton->getBounds().getWidth(),
                VCP_CONTACT_SELECTOR_INPUTBOX_HEIGHT + VCP_CONTACT_SELECTOR_TOP_GAP);

            m_contactText->setAnchor(0, 0.5f);
            m_contactText->setPos(0,
                VCP_CONTACT_SELECTOR_INPUTBOX_HEIGHT + VCP_CONTACT_SELECTOR_TOP_GAP + VCP_CONTACT_SELECTOR_CONTACT_BUTTON_HEIGHT / 2);
            m_contactText->setSize(csWidth - VCP_CONTACT_SELECTOR_MORE_BTN_WIDTH - VCP_CONTACT_SELECTOR_CONTACT_GAP, 0);

            height = VCP_CONTACT_SELECTOR_CONTACT_BUTTON_HEIGHT;

            m_inputbox->setContactRect(VfxRect(
                0,
                m_inputbox->getSize().height + VCP_CONTACT_SELECTOR_TOP_GAP,
                getBounds().getWidth(),
                height));
        }
        else
        {
            // show contact list in inputbox
            VfxS32 inputBoxLeftMargin, inputBoxRightMargin;
            m_inputbox->getMargins(&inputBoxLeftMargin, NULL, &inputBoxRightMargin, NULL);
            VfxS32 xPos = inputBoxLeftMargin;
            VfxS32 yPos = VCP_CONTACT_SELECTOR_INPUTBOX_HEIGHT / 2;

            m_contactText->setAnchor(0, 0.5f);
            m_contactText->setPos(xPos, yPos);
            m_contactText->setSize(
                inputboxWidth - inputBoxLeftMargin - inputBoxRightMargin,
                0);
            m_contactText->setIsUnhittable(VFX_TRUE);

            m_inputbox->setContactRect(VfxRect(
                0,
                0,
                getBounds().getWidth(),
                VCP_CONTACT_SELECTOR_INPUTBOX_HEIGHT));
        }
    }
#endif

    if (height > 0)
    {
        setSize(
            csWidth + VCP_CONTACT_SELECTOR_ICON_SHADOW,
            VCP_CONTACT_SELECTOR_INPUTBOX_HEIGHT + VCP_CONTACT_SELECTOR_TOP_GAP + height + VCP_CONTACT_SELECTOR_BUTTOM_GAP);
    }
    else
    {
        setSize(
            csWidth + VCP_CONTACT_SELECTOR_ICON_SHADOW,
            VCP_CONTACT_SELECTOR_INPUTBOX_HEIGHT + VCP_CONTACT_SELECTOR_BUTTOM_GAP);
    }
}

void VcpContactSelector::onBoundsChanged(VfxFrame * frame, const VfxRect & rect)
{
    VFX_UNUSED(frame);
    VFX_UNUSED(rect);

    checkUpdate();
}

VfxBool VcpContactSelector::onPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        VfxPoint pos = event.getRelPos(this);
        VfxRect inputboxRect = m_inputbox->getBounds();
        if (inputboxRect.contains(pos) && !m_inputbox->isActive())
        {
            vfxPostInvoke1(m_inputbox, &VcpTextEditor::activate, VFX_TRUE);
        }
    }
    return VFX_FALSE;
}


void VcpContactSelector::onTextEditorActivated(VcpTextEditor *editor, VfxBool activated)
{
    if (activated)
    {
        // clear input box and display the all contact
        m_isContactHide = VFX_FALSE;
        m_isHideContactList = VFX_FALSE;
    }
    else
    {
        // put contact in inputbox area
        m_isContactHide = VFX_TRUE;
    }

    m_hiliteBtnIdx = -1;

    checkUpdate();
}


void VcpContactSelector::onTextChanged(VcpTextEditor *editor)
{
    VfxWChar *string = editor->getText();

    m_hiliteBtnIdx = -1;

    checkUpdate();

    // notify user
    m_signalTextChanged.emit(this, string);
}


void VcpContactSelector::onContactButtonClick(VfxObject* sender, VfxId id)
{
    VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

    // do not handle pen event when contact in hide mode
    if (m_isContactHide)
    {
        // activate the inputbox
        m_inputbox->activate();
        m_isContactHide = VFX_FALSE;
        checkUpdate();
        return;
    }

    // reset All other contact button state
    for (VfxU8 i = 0; i < m_displayCount; i++)
    {
        if (i != id)
        {
            m_contactButton[i]->setIsHighlighted(VFX_FALSE);
        }
    }

    if (button)
    {
        if (button->getIsHighlighted())
        {
           // delete the highlight contact
           remove(id);

           // clear hilite index
           m_hiliteBtnIdx = -1;
        }
        else
        {
            m_hiliteBtnIdx = id;
        }
    }

    checkUpdate();
}


void VcpContactSelector::onButtonClick(VfxObject *obj, VfxId id)
{
    // notify user
    m_hiliteBtnIdx = -1;

    checkUpdate();

    if (id == VCP_CONTACT_SELECTOR_SEARCH_BTN_ID)
    {
        m_signalSearchButtonClicked.emit();
    }
    else if (id == VCP_CONTACT_SELECTOR_MORE_BTN_ID)
    {
        m_signalMoreButtonClicked.emit(this);
    }
}


void VcpContactSelector::onDeinit()
{
    VfxControl::onDeinit();

    if (m_contactButton)
    {
        VFX_FREE_MEM(m_contactButton);
    }

    clear();
}


VfxBool VcpContactSelector::add(const VcpContact &contact)
{
    VcpContact *pContact;
    VFX_ALLOC_NEW(pContact, VcpContact, this);
    *pContact = contact;

    if (m_contact)
    {
        m_contact->append(pContact);
    }
    else
    {
        m_contact = pContact;
    }

    m_count++;

    m_signalContactChanged.emit(this, VCP_CONTACT_CHANGED_ADD);

    return VFX_TRUE;
}


VfxBool VcpContactSelector::add(VfxWString name, VfxWString phoneNumber, VfxWString email)
{
    VcpContact *pContact;
    VFX_ALLOC_NEW(pContact, VcpContact, this);
    pContact->m_name = name;
    pContact->m_phoneNumber= phoneNumber;
    pContact->m_email = email;

    if (m_contact)
    {
        m_contact->append(pContact);
    }
    else
    {
        m_contact = pContact;
    }

    m_count++;

    m_signalContactChanged.emit(this, VCP_CONTACT_CHANGED_ADD);

    return VFX_TRUE;
}


VfxBool VcpContactSelector::remove(VfxS32 index)
{
    VfxS32 curIndex = 0;
    VcpContact *pContact = m_contact;
    VcpContact *pPreContact = NULL;

    while (pContact)
    {
        if (curIndex == index)
        {
            if (pPreContact)
            {
                pPreContact->m_next = pContact->m_next;
            }
            else
            {
                // delete the header contact
                m_contact = pContact->m_next;
            }
            VFX_DELETE(pContact);
            m_count--;
            m_signalContactChanged.emit(this, VCP_CONTACT_CHANGED_DELETE);
            return VFX_TRUE;
        }

        pPreContact = pContact;
        pContact = pContact->m_next;
        curIndex++;
    }

    return VFX_FALSE;
}


VfxBool VcpContactSelector::remove(const VcpContact &contact)
{
    VfxS32 curIndex = 0;
    VcpContact *pContact = m_contact;
    VcpContact *pPreContact = NULL;

    while (pContact)
    {
        if (*pContact == contact)
        {
            if (pPreContact)
            {
                pPreContact->m_next = pContact->m_next;
            }
            else
            {
                // delete the header contact
                m_contact = pContact->m_next;
            }
            VFX_DELETE(pContact);
            m_count--;
            m_signalContactChanged.emit(this, VCP_CONTACT_CHANGED_DELETE);
            return VFX_TRUE;
        }

        pPreContact = pContact;
        pContact = pContact->m_next;
        curIndex++;
    }

    return VFX_FALSE;
}


void VcpContactSelector::clear()
{
    VcpContact *obj = m_contact;

    // Free contact object memory    
    while (obj)
    {
        obj = obj->m_next;
        VFX_DELETE(m_contact);
        m_contact = obj;
    }

    m_count = 0;
}


void VcpContactSelector::setHintText(const VfxWString &hint)
{
    if (m_hintText != hint)
    {
        m_hintText = hint;

        if (m_hintTextFrame)
        {
            m_inputbox->removeMarginFrame(VCP_TEXT_MARGIN_FRAME_LEFT, m_hintTextFrame);
            VFX_OBJ_CLOSE(m_hintTextFrame);
        }
        // hint text
        VfxFontDesc fontDesc;

        #if defined(__COSMOS_MMI_PACKAGE__)
            fontDesc = VFX_FONT_RES(VCP_FNT_TEXT_VIEW_TXT);
        #else
            fontDesc.size = VFX_FONT_DESC_VF_SIZE(VCP_CONTACT_SELECTOR_CONTACT_HINT_FONT_SZIE);
        #endif


        VFX_OBJ_CREATE(m_hintTextFrame, VfxTextFrame, this);
        m_hintTextFrame->setString(m_hintText);
        m_hintTextFrame->setPos(VfxPoint(0, 0));
        m_hintTextFrame->setColor(VFX_COLOR_BLACK);         /* set font color */
        m_hintTextFrame->setFont(fontDesc);
        m_hintTextFrame->forceUpdate();

        // set Hint to inputbox
        m_inputbox->setMarginFrame(VCP_TEXT_MARGIN_FRAME_LEFT, m_hintTextFrame);
    }
}


void VcpContactSelector::hideContact(VfxBool value)
{
    // show/hide the contact by setBounds
    if (value != m_isHideContactList)
    {
        if (value == VFX_TRUE)
        {
            setSize(getSize().width, VCP_CONTACT_SELECTOR_INPUTBOX_HEIGHT + VCP_CONTACT_SELECTOR_BUTTOM_GAP);
        }
        m_isHideContactList = value;
        checkUpdate();
    }
}


/***************************************************************************** 
 * Class VcpContactEditor
 *****************************************************************************/
VfxBool VcpContactEditor::onContainPoint(const VfxPoint &point) const
{
    if (m_rect.contains(point))
    {
        return VFX_TRUE;
    }

    return VcpTextEditor::onContainPoint(point);
}
