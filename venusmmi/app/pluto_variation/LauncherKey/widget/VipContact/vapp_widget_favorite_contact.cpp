/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_widget_favorite_contact.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the favorite contact widget for KeyLaucher project.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "GlobalResDef.h"
extern "C"
{
#include "phbcuigprot.h"
#include "ucmgprot.h"
#include "SmsAppGprot.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGprot.h"
#endif
}
#include "FileMgrSrvGprot.h"
#include "phbsrvgprot.h"
#include "mmi_rp_vapp_widget_favorite_contact_def.h"
#include "vapp_widget_favorite_contact.h"
#include "mmi_rp_srv_phb_def.h"
#include "vapp_widget_def.h"
#include "vapp_widget_native_factory.h"

VFX_IMPLEMENT_CLASS("VappWidgetContactPreView", VappWidgetContactPreView, VfxBasePopup);

VappWidgetContactPreView::VappWidgetContactPreView(VfxFrame* cell)
{
    m_item = (VappWidgetContactMenuCell *)cell;
}

void VappWidgetContactPreView::onInit(void)
{
    VfxBasePopup::onInit();
    setSize(CELL_PREVIEW_WIDTH, CELL_PREVIEW_HEIGHT);
    VfxKeypad::registerHandler(VFX_KEY_CODE_CSK, this);
    VfxKeypad::registerHandler(VFX_KEY_CODE_END, this);
    VfxKeypad::registerHandler(VFX_KEY_CODE_ARROW_UP, this);
    VfxKeypad::registerHandler(VFX_KEY_CODE_ARROW_DOWN, this);
    VFX_OBJ_CREATE(m_bgPic, VfxImageFrame, this);
    m_bgPic->setResId(IMG_ID_VAPP_WIDGET_CONTACT_BG_POP);
    m_bgPic->setSize(getSize());
    m_bgPic->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    VFX_OBJ_CREATE(m_name, VfxTextFrame, this);
    m_name->setString(m_item->getName());
    m_name->setFont(VfxFontDesc(CELL_HIGHLIGHT_CONTACT_NAME_FONT_SIZE));
    m_name->setSize(CELL_HIGHLIGHT_CONTACT_NAME_SIZE);
    m_name->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_name->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_name->setPos(CELL_HIGHLIGHT_CONTACT_NAME_POS);
    VFX_OBJ_CREATE(m_number, VfxTextFrame, this);
    m_number->setString(m_item->getNumber());
    m_number->setFont(VfxFontDesc(CELL_CONTACT_NUMBER_FONT_SIZE));
    m_number->setPos(CELL_CONTACT_NUMBER_POS);
    m_number->setSize(CELL_CONTACT_NUMBER_SIZE);
    m_number->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_number->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    VFX_OBJ_CREATE(m_callerPic, VfxImageFrame, this);
    if (m_item->getResType() == VFX_TRUE)
    {
        m_callerPic->setPath(m_item->getResPath());
    }
    else
    {
        m_callerPic->setResId(m_item->getResId());
    }
    m_callerPic->setSize(CELL_HIGHLIGHT_CONTACT_PIC_SIZE);
    m_callerPic->setPos(CELL_HIGHLIGHT_CONTACT_PIC_POS);
    m_callerPic->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    VcpStateImage m_imageList;
    m_imageList.setImage(
                    IMG_ID_VAPP_WIDGET_CONTACT_BG_POP_BUTTON_N,
                    IMG_ID_VAPP_WIDGET_CONTACT_BG_POP_BUTTON_H,
                    IMG_ID_VAPP_WIDGET_CONTACT_BG_POP_BUTTON_N,
                    IMG_ID_VAPP_WIDGET_CONTACT_BG_POP_BUTTON_H);
    VFX_OBJ_CREATE(m_btnCall, VcpButton, this);
    m_btnCall->setId(0);
    m_btnCall->setSize(CELL_PREVIEW_BUTTON_WIDTH, CELL_PREVIEW_BUTTON_HEIGHT);
    m_btnCall->setBgImageList(m_imageList);
    m_btnCall->setState(VCP_BUTTON_STATE_PRESSED);
    m_btnCall->setText(VfxWString(STR_GLOBAL_DIAL));
    m_btnCall->setTextFont(VfxFontDesc(CELL_PREVIEW_BUTTON_FONT_SIZE));
    m_btnCall->setTextColor(
                   VFX_COLOR_WHITE,
                   VFX_COLOR_WHITE,
                   VFX_COLOR_WHITE,
                   VFX_COLOR_WHITE);
    m_btnCall->setAnchor(0.5, 0.0);
    m_btnCall->setPos(getSize().width >> 1, CELL_PREVIEW_FIRST_BUTTON_Y);
    m_btnCall->m_signalClicked.connect(this, &VappWidgetContactPreView::onCall);
    m_btnCall->m_signalStateChanged.connect(this, &VappWidgetContactPreView::onStateChanged);
    
    VFX_OBJ_CREATE(m_btnSendMsg, VcpButton, this);
    m_btnSendMsg->setId(1);
    m_btnSendMsg->setSize(CELL_PREVIEW_BUTTON_WIDTH, CELL_PREVIEW_BUTTON_HEIGHT);
    m_btnSendMsg->setBgImageList(m_imageList);
    m_btnSendMsg->setText(VfxWString(STR_GLOBAL_SEND_MESSAGE));
    m_btnSendMsg->setTextFont(VfxFontDesc(CELL_PREVIEW_BUTTON_FONT_SIZE));
    m_btnSendMsg->setTextColor(
                      VFX_COLOR_WHITE,
                      VFX_COLOR_WHITE,
                      VFX_COLOR_WHITE,
                      VFX_COLOR_WHITE);
    m_btnSendMsg->setAnchor(0.5, 0.0);
    m_btnSendMsg->setPos(getSize().width >> 1, CELL_PREVIEW_FIRST_BUTTON_Y + CELL_PREVIEW_BUTTON_HEIGHT + CELL_PREVIEW_BUTTON_GAP);
    m_btnSendMsg->m_signalClicked.connect(this, &VappWidgetContactPreView::onSendMessage);
    m_btnSendMsg->m_signalStateChanged.connect(this, &VappWidgetContactPreView::onStateChanged);
    
    VFX_OBJ_CREATE(m_btnRemove, VcpButton, this);
    m_btnRemove->setId(2);
    m_btnRemove->setSize(CELL_PREVIEW_BUTTON_WIDTH, CELL_PREVIEW_BUTTON_HEIGHT);
    m_btnRemove->setBgImageList(m_imageList);
    m_btnRemove->setText(VfxWString(STR_GLOBAL_REMOVE));
    m_btnRemove->setTextFont(VfxFontDesc(CELL_PREVIEW_BUTTON_FONT_SIZE));
    m_btnRemove->setTextColor(
                     VFX_COLOR_WHITE,
                     VFX_COLOR_WHITE,
                     VFX_COLOR_WHITE,
                     VFX_COLOR_WHITE);
    m_btnRemove->setAnchor(0.5, 0.0);
    m_btnRemove->setPos(getSize().width >> 1, CELL_PREVIEW_FIRST_BUTTON_Y + 2 * (CELL_PREVIEW_BUTTON_HEIGHT + CELL_PREVIEW_BUTTON_GAP));
    m_btnRemove->m_signalClicked.connect(this, &VappWidgetContactPreView::onRemove);
    m_btnRemove->m_signalStateChanged.connect(this, &VappWidgetContactPreView::onStateChanged);

    VFX_OBJ_CREATE(m_warning, VfxTextFrame, this);
    m_warning->setString(VFX_WSTR_RES(STR_ID_VAPP_WIDGET_FAVORITE_CONTACT_WARNING));
    m_warning->setFont(VfxFontDesc(CELL_PREVIEW_WARNING_TEXT_FONT_SIZE));
    m_warning->setColor(VFX_COLOR_WHITE);
    m_warning->setBounds(VfxRect(0, 0, CELL_PREVIEW_BUTTON_WIDTH, CELL_PREVIEW_WARNING_TEXT_HEIGHT));
    m_warning->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    m_warning->setAnchor(1.0, 0.0);
    m_warning->setPos(0, 80);

    VFX_OBJ_CREATE(m_softKey, VcpSoftkey, this);
    m_softKey->setSoftkey(VCP_SOFTKEY_LSK, VfxWString(STR_GLOBAL_SELECT), VFX_IMAGE_SRC_NULL);
    m_softKey->setSoftkey(VCP_SOFTKEY_RSK, VfxWString(STR_GLOBAL_BACK), VFX_IMAGE_SRC_NULL);
    m_softKey->setSoftkeyWidth(VCP_SOFTKEY_LSK, LCD_WIDTH >> 1);
    m_softKey->setSoftkeyWidth(VCP_SOFTKEY_RSK, LCD_WIDTH >> 1);
    m_softKey->disableSoftkey(VCP_SOFTKEY_CSK, VFX_TRUE);
    m_softKey->setSize(CELL_PREVIEW_SOFTKEY_SIZE);
    m_softKey->setImgContent(VfxImageSrc(IMG_ID_VAPP_WIDGET_CONTACT_BG_SOFTKEY));
    m_softKey->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_softKey->setBorderGap(CELL_PREVIEW_SOFTKEY_BORDER_GAP);
    m_softKey->getCallback(VCP_SOFTKEY_LSK).connect(this, &VappWidgetContactPreView::onLskClicked);
    m_softKey->getCallback(VCP_SOFTKEY_RSK).connect(this, &VappWidgetContactPreView::onRskClicked);
    m_softKey->setAnchor(0.0, 1.0);
    m_softKey->setPos(CELL_PREVIEW_SOFTKEY_POS);
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->addChildFrame(m_softKey);

    m_isRemoveView = VFX_FALSE;
    m_highlightItem = 0;
}

void VappWidgetContactPreView::onCall(VfxObject *obj, VfxId id)
{
    m_item->Call();
}

void VappWidgetContactPreView::onSendMessage(VfxObject *obj, VfxId id)
{
    CHAR ascii_number[MMI_PHB_NUMBER_LENGTH + 1 + 1];
    mmi_sms_write_msg_para_struct sendData;
    memset(ascii_number, 0, sizeof(ascii_number));
    memset(&sendData, 0, sizeof(mmi_sms_write_msg_para_struct));
    if (m_item->getNumber().isNull())
    {
        ascii_number[0] = 0;
    }
    else
    {
        mmi_ucs2_n_to_asc(ascii_number, (CHAR*)(m_item->getNumber()).getBuf(), MMI_PHB_NUMBER_LENGTH + 1);
    }
    sendData.flag = MMI_SMS_ENTRY_WRITE_REPLY;
    sendData.ascii_addr = (U8*) ascii_number;
    mmi_sms_write_msg_lanch(0, &sendData);
}

void VappWidgetContactPreView::onRemove(VfxObject *obj, VfxId id)
{
    VfxAutoAnimate::begin();
    m_btnCall->setAnchor(0.0, 0.0);
    m_btnCall->setPos(LCD_WIDTH, m_btnCall->getPos().y);
    m_btnSendMsg->setAnchor(0.0, 0.0);
    m_btnSendMsg->setPos(LCD_WIDTH, m_btnSendMsg->getPos().y);
    m_btnRemove->setAnchor(0.0, 0.0);
    m_btnRemove->setPos(LCD_WIDTH, m_btnRemove->getPos().y);
    m_warning->setAnchor(0.5, 0.0);
    m_warning->setPos(CELL_PREVIEW_WIDTH >> 1, CELL_PREVIEW_FIRST_BUTTON_Y);
    VfxAutoAnimate::commit();
    m_softKey->setSoftkey(VCP_SOFTKEY_LSK, VfxWString(STR_GLOBAL_YES), VFX_IMAGE_SRC_NULL);
    m_softKey->setSoftkey(VCP_SOFTKEY_RSK, VfxWString(STR_GLOBAL_NO), VFX_IMAGE_SRC_NULL);

    m_isRemoveView = VFX_TRUE;
}

void VappWidgetContactPreView::onStateChanged(VfxObject *obj, VfxId id, VcpButtonStateEnum state)
{
    if (state == VCP_BUTTON_STATE_PRESSED && id != m_highlightItem)
    {
        changeHighlight(id, m_highlightItem);
    }
}

void VappWidgetContactPreView::changeHighlight(VfxU32 highlightIndex, VfxU32 preHighlighIndex)
{
    switch (preHighlighIndex)
    {
        case 0:
            m_btnCall->setIsHighlighted(VFX_FALSE);
            m_btnCall->setState(VCP_BUTTON_STATE_NORMAL);
            break;
        case 1:
            m_btnSendMsg->setIsHighlighted(VFX_FALSE);
            m_btnSendMsg->setState(VCP_BUTTON_STATE_NORMAL);
            break;
        case 2:
            m_btnRemove->setIsHighlighted(VFX_FALSE);
            m_btnRemove->setState(VCP_BUTTON_STATE_NORMAL);
            break;
    }
    switch (highlightIndex)
    {
        case 0:
            m_btnCall->setIsHighlighted(VFX_TRUE);
            m_btnCall->setState(VCP_BUTTON_STATE_PRESSED);
            break;
        case 1:
            m_btnSendMsg->setIsHighlighted(VFX_TRUE);
            m_btnSendMsg->setState(VCP_BUTTON_STATE_PRESSED);
            break;
        case 2:
            m_btnRemove->setIsHighlighted(VFX_TRUE);
            m_btnRemove->setState(VCP_BUTTON_STATE_PRESSED);
            break;            
    }
    m_highlightItem = highlightIndex;
}

void VappWidgetContactPreView::onLskClicked(VcpSoftkeyEventEnum key_event)
{
    if (key_event == VCP_SOFTKEY_UP)
    {
        if (m_isRemoveView == VFX_TRUE)
    {
        m_signalRemove.postEmit(m_item->getIndex());
        exit(VFX_TRUE);
	}
    else
    {
        if (m_highlightItem == 0)
        {
            onCall(NULL, 0);
        }
        else if (m_highlightItem == 1)
        {
            onSendMessage(NULL, 1);
        }
        else
        {
            onRemove(NULL, 2);
        }
    }
}
}

void VappWidgetContactPreView::onRskClicked(VcpSoftkeyEventEnum key_event)
{
    if (key_event == VCP_SOFTKEY_UP)
    {
        exit(VFX_TRUE);
	}
}

VfxBool VappWidgetContactPreView::onKeyInput(VfxKeyEvent & event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_UP)
    {
        switch (event.keyCode)
        {
            case VFX_KEY_CODE_LSK:
            case VFX_KEY_CODE_CSK:
                if (m_isRemoveView == VFX_TRUE)
                {
                    m_signalRemove.postEmit(m_item->getIndex());
                    exit(VFX_TRUE);
                }
                else
                {
                    if (m_highlightItem == 0)
                    {
                        onCall(NULL, 0);
                    }
                    else if (m_highlightItem == 1)
                    {
                        onSendMessage(NULL, 1);
                    }
                    else
                    {
                        onRemove(NULL, 2);
                    }
                }
                break;
            case VFX_KEY_CODE_RSK:
            case VFX_KEY_CODE_END:
                {
                    exit(VFX_TRUE);
                }
                break;
            case VFX_KEY_CODE_ARROW_UP:
                {
                    if (m_highlightItem > 0)
                    {
                        changeHighlight(m_highlightItem - 1, m_highlightItem);
                    }
                }
                break;
            case VFX_KEY_CODE_ARROW_DOWN:
                {
                    if (m_highlightItem < 2)
                    {
                        changeHighlight(m_highlightItem + 1, m_highlightItem);
                    }
                }
                break;
        }
    }
    return VFX_TRUE;
}

void VappWidgetContactPreView::onDeinit(void)
{
    VfxBasePopup::onDeinit();
    VFX_OBJ_CLOSE(m_name);
    VFX_OBJ_CLOSE(m_number);
    VFX_OBJ_CLOSE(m_callerPic);
    VFX_OBJ_CLOSE(m_btnCall);
    VFX_OBJ_CLOSE(m_btnSendMsg);
    VFX_OBJ_CLOSE(m_btnRemove);
    VFX_OBJ_CLOSE(m_softKey);
}


VFX_IMPLEMENT_CLASS("VappWidgetContactMenuCell", VappWidgetContactMenuCell, VfxFrame);
VappWidgetContactMenuCell::VappWidgetContactMenuCell(VfxU32 index):
    m_status(CELL_STATUS_NORMAL),
    m_isFromFile(VFX_FALSE),
    m_resId(IMG_ID_VAPP_WIDGET_CONTACT_DEFAULT_PIC),
    m_name(NULL),
    m_number(NULL),
    m_callerPic(NULL)    
{
    m_index = index;
    mmi_phb_vip_contact_struct * vipContact = srv_phb_vip_contact_get_entry(index);
    VfxU16 contactId = vipContact->store_index;
    if (contactId == SRV_PHB_INVALID_INDEX)
    {
        m_contactName.loadFromRes(STR_ID_VAPP_WIDGET_FAVORITE_CONTACT_ADD);
        m_status = CELL_STATUS_EMPTY;
    }
    else
    {
        srv_phb_contact contact = srv_phb_read_contact(contactId, NULL, NULL);
        VfxWChar *name = srv_phb_contact_get_name(contact);
        if (name == NULL)
        {
            m_contactName.loadFromRes(STR_GLOBAL_UNNAMED); 
        }
        else
        {
            m_contactName.loadFromMem(name);
        }
        srv_phb_iterator iter = srv_phb_contact_get_number_iterator(contact);
        srv_phb_number_struct * number;
        do
        {
            number = srv_phb_contact_get_number_next(&iter);
        }
        while (number && iter && number->is_default == MMI_FALSE);
        if (number != NULL)
        {
            m_contactNumber.loadFromMem(number->number);
        }
        srv_phb_res_struct *picture = srv_phb_contact_get_image(contact);
        if (picture
            #ifdef __MMI_USB_SUPPORT__
            && srv_usb_is_in_mass_storage_mode() == MMI_FALSE
            #endif
            )
        {
            if (picture->res_path[0])
            {
                if (srv_fmgr_fs_path_exist(picture->res_path) == 0)
                {
                    m_resPath.loadFromMem(picture->res_path);
                    m_isFromFile = VFX_TRUE;
                }
            }
            else if (!(picture->res_id & 0x8000))
            {
                m_resId = picture->res_id;
            }
        }

        srv_phb_free_contact(contact);
    }

}

void VappWidgetContactMenuCell::onInit()
{
    VfxFrame::onInit();
    if (m_status != CELL_STATUS_EMPTY)
    {
        if (m_index == ((VappWidgetContactMenu*)(getParentFrame()->getParentFrame()))->getFocusItem().pos)
        {
            m_status = CELL_STATUS_HIGHLIGHT;
        }
    }
    VFX_OBJ_CREATE(m_backGround, VfxImageFrame, this);
   
    VFX_OBJ_CREATE(m_name, VfxTextFrame, this);
    m_name->setString(m_contactName);

    VFX_OBJ_CREATE(m_number, VfxTextFrame, this);
    m_number->setString(m_contactNumber);
    
    VFX_OBJ_CREATE(m_callerPic, VfxImageFrame, this);

    switch (m_status)
    {
        case CELL_STATUS_EMPTY:
            if (srv_phb_vip_contact_get_count() == 0 || m_index == ((VappWidgetContactMenu*)(getParentFrame()->getParentFrame()))->getFocusItem().pos)
            {
                setEmpty(VFX_FALSE);
            }
            else
            {
                setNoContact(VFX_FALSE);
            }            
            break;

        case CELL_STATUS_HIGHLIGHT:
            setHighlight(VFX_FALSE);
            break;
            
        case CELL_STATUS_NORMAL:
            setNormal(VFX_FALSE);
            break;
    }    
}

//cell is empty
void VappWidgetContactMenuCell::setNoContact(VfxBool isAnim)
{
    m_status = CELL_STATUS_EMPTY;
    setSize(CELL_NORMAL_WIDTH, CELL_NORMAL_HEIGHT);
    m_backGround->setResId(IMG_ID_VAPP_WIDGET_CONTACT_BG_CELL_N);
    m_backGround->setSize(CELL_NORMAL_WIDTH, CELL_NORMAL_HEIGHT);
    m_backGround->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_name->setAnchor(0.0, 0.5);
    m_name->setPos(CELL_NO_CONTACT_NAME_POS);
    m_name->setFont(VfxFontDesc(CELL_NO_CONTACT_NAME_FONT_SIZE));
    m_callerPic->setResId(IMG_ID_VAPP_WIDGET_CONTACT_ADD_SMALL);
    m_callerPic->setSize(CELL_NO_CONTACT_PIC_SIZE);
    m_callerPic->setAnchor(0.0, 0.0);
    m_callerPic->setPos(CELL_NO_CONTACT_PIC_POS);
    m_callerPic->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
}

//list is empty
void VappWidgetContactMenuCell::setEmpty(VfxBool isAnim)
{
    m_status = CELL_STATUS_EMPTY_H;
    setSize(CELL_HIGHLIGHT_WIDTH, CELL_HIGHLIGHT_HEIGHT);
    m_backGround->setResId(IMG_ID_VAPP_WIDGET_CONTACT_BG_CELL_H);
    m_backGround->setSize(CELL_HIGHLIGHT_WIDTH, CELL_HIGHLIGHT_HEIGHT);
    m_backGround->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_name->setAnchor(0.0, 0.5);
    m_name->setPos(CELL_EMPTY_NAME_POS);
    m_name->setFont(VfxFontDesc(CELL_EMPTY_NAME_FONT_SIZE));
    m_callerPic->setResId(IMG_ID_VAPP_WIDGET_CONTACT_ADD_BIG);
    m_callerPic->setSize(CELL_EMPTY_PIC_SIZE);
    m_callerPic->setAnchor(0.0, 0.5);
    m_callerPic->setPos(CELL_EMPTY_PIC_POS);
    m_callerPic->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
}

void VappWidgetContactMenuCell::setHighlight(VfxBool isAnim)
{
    setSize(CELL_HIGHLIGHT_WIDTH, CELL_HIGHLIGHT_HEIGHT);
    m_status = CELL_STATUS_HIGHLIGHT;
    m_backGround->setResId(IMG_ID_VAPP_WIDGET_CONTACT_BG_CELL_H);
    m_backGround->setSize(CELL_HIGHLIGHT_WIDTH, CELL_HIGHLIGHT_HEIGHT);
    m_backGround->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    
    if (m_isFromFile)
    {
        m_callerPic->setPath(m_resPath);
    }
    else
    {
        m_callerPic->setResId(m_resId);
    }
    m_callerPic->setSize(CELL_HIGHLIGHT_CONTACT_PIC_SIZE);
    m_callerPic->setPos(CELL_HIGHLIGHT_CONTACT_PIC_POS);
    m_callerPic->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_callerPic->setHidden(VFX_FALSE);
        
    m_name->setFont(VfxFontDesc(CELL_HIGHLIGHT_CONTACT_NAME_FONT_SIZE));
    m_name->setAnchor(0.0, 0.0);
    m_name->setPos(CELL_HIGHLIGHT_CONTACT_NAME_POS);
    m_name->setSize(CELL_HIGHLIGHT_CONTACT_NAME_SIZE);
    m_name->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_name->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

    m_number->setFont(VfxFontDesc(CELL_CONTACT_NUMBER_FONT_SIZE));
    m_number->setAnchor(0.0, 0.0);
    m_number->setPos(CELL_CONTACT_NUMBER_POS);
    m_number->setSize(CELL_CONTACT_NUMBER_SIZE);
    m_number->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_number->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_number->setHidden(VFX_FALSE);
}

void VappWidgetContactMenuCell::setNormal(VfxBool isAnim)
{
    setSize(CELL_NORMAL_WIDTH, CELL_NORMAL_HEIGHT);
    m_status = CELL_STATUS_NORMAL;
    m_backGround->setResId(IMG_ID_VAPP_WIDGET_CONTACT_BG_CELL_N);
    m_backGround->setSize(CELL_NORMAL_WIDTH, CELL_NORMAL_HEIGHT);
    m_backGround->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_name->setFont(VfxFontDesc(CELL_NORMAL_CONTACT_NAME_FONT_SIZE));
    m_name->setAnchor(0.5, 0.5);
    m_name->setPos(CELL_NORMAL_CONTACT_NAME_POS);
    m_name->setSize(CELL_NORMAL_CONTACT_NAME_SIZE);
    m_name->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_name->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_callerPic->setHidden(VFX_TRUE);
    m_number->setHidden(VFX_TRUE);
}

void VappWidgetContactMenuCell::Call()
{
    mmi_ucm_make_call_para_struct param;
    VfxU16 number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
    if (m_contactNumber.isNull())
    {
        number[0] = 0;
    }
    else
    {
        mmi_wcsncpy(number, m_contactNumber.getBuf(), MMI_PHB_NUMBER_PLUS_LENGTH);
    }
    mmi_ucm_init_call_para(&param);
    param.dial_type                         = SRV_UCM_CALL_TYPE_ALL;
    param.ucs2_num_uri                      = number;
    param.adv_para.phb_data                 = NULL;
    param.adv_para.after_make_call_callback = NULL;
    param.adv_para.after_callback_user_data = NULL;
    mmi_ucm_call_launch(0, &param);
}
void VappWidgetContactMenuCell::onDeinit()
{
    VfxFrame::onDeinit();
    VFX_OBJ_CLOSE(m_name);
    VFX_OBJ_CLOSE(m_number);
    VFX_OBJ_CLOSE(m_callerPic);
    VFX_OBJ_CLOSE(m_backGround);
}


VappWidgetContactMenuLayout::VappWidgetContactMenuLayout(VcpBaseMenu *menu):
    VcpBaseMenuLayout(menu)
{
}

void VappWidgetContactMenuLayout::onInit()
{
    VcpBaseMenuLayout::onInit();
    m_cellHeight = CELL_NORMAL_HEIGHT;
}

void VappWidgetContactMenuLayout::onDeinit()
{
}

VfxS32 VappWidgetContactMenuLayout::getCellCount(VfxS32 group)
{
    m_cellCount = srv_phb_vip_contact_get_count();
    if (m_cellCount < MMI_PHB_VIP_CONTACT_COUNT)
    {
        m_cellCount += 1;
    }
    if (group == 0)
    {
        return m_cellCount;
    }
    return 0;
}

VfxS32 VappWidgetContactMenuLayout::getContentLength()
{
    return (getCellCount(0) - 1) * (CELL_NORMAL_HEIGHT + WIDGET_CONTACT_CELL_GAP) + CELL_HIGHLIGHT_HEIGHT;
}

VcpMenuPos VappWidgetContactMenuLayout::getCellByPos(VfxPoint pt)
{
    VcpMenuPos p(0, 0);
    VfxU32 index;
    VfxS32 distance = 0;
    VfxS32 cellCount = getCellCount(0);
    for (index = 0; index < MMI_PHB_VIP_CONTACT_COUNT; index ++)
    {
        if (index == getFocusItem().pos)
        {
            distance += CELL_HIGHLIGHT_HEIGHT;
        }
        else
        {
            distance += m_cellHeight;
        }
        if (distance > pt.y)
        {
            p.pos = index;
            break;
        }
    }
    if (index == MMI_PHB_VIP_CONTACT_COUNT)
    {
        p.pos = MMI_PHB_VIP_CONTACT_COUNT - 1;
    }
    return p;
}

VcpMenuRegion VappWidgetContactMenuLayout::queryRegion(const VfxRect & r)
{
    return VcpMenuRegion(getCellByPos(r.origin),
        getCellByPos(VfxPoint(r.getMaxX(), r.getMaxY())));
}

VfxRect VappWidgetContactMenuLayout::queryCellRect(VcpMenuPos pos)
{
    VfxS32 y = pos.pos * m_cellHeight + pos.pos * WIDGET_CONTACT_CELL_GAP;
    VfxS32 height = CELL_NORMAL_HEIGHT;
    if (getFocusItem() == pos)
    {
        height = CELL_HIGHLIGHT_HEIGHT;
    }
    if (pos.pos > getFocusItem().pos)
    {
        y += (CELL_HIGHLIGHT_HEIGHT - CELL_NORMAL_HEIGHT);
    }
    return VfxRect(0, y, CELL_NORMAL_WIDTH, height);
}

VFX_IMPLEMENT_CLASS("VappWidgetContactMenu", VappWidgetContactMenu, VcpBaseMenu);

VfxU32 VappWidgetContactMenu::m_highlightIndex = 0;
mmi_id VappWidgetContactMenu::m_groupId = 0;

void VappWidgetContactMenu::onInit()
{
    VcpBaseMenu::onInit();
    enableVerticalScrollIndicator(VFX_FALSE);
    m_tapCell = VFX_FALSE;
    updateMenu();
    VfxKeypad::registerHandler(VFX_KEY_CODE_CSK, this);
    VfxKeypad::registerHandler(VFX_KEY_CODE_ARROW_UP, this);
    VfxKeypad::registerHandler(VFX_KEY_CODE_ARROW_DOWN, this);
    VfxKeypad::registerHandler(VFX_KEY_CODE_SEND, this);
}
void VappWidgetContactMenu::onDeinit()
{
    VcpBaseMenu::onDeinit();
}

VcpBaseMenuLayout * VappWidgetContactMenu::createLayout()
{
    VFX_OBJ_CREATE_EX(m_layout, VappWidgetContactMenuLayout, this, (this));
    VcpMenuPos focus;
    focus.group = 0;
    focus.pos = getHighlightIndex();
    m_layout->setFocusItem(focus, VFX_TRUE);
    return m_layout;
}

VfxFrame * VappWidgetContactMenu::createCell(VfxS32 group, VfxS32 pos)
{
    VappWidgetContactMenuCell *cell;
    VFX_OBJ_CREATE_EX(cell, VappWidgetContactMenuCell, this, (pos));
    return cell;
}

void VappWidgetContactMenu::addNewContact()
{
    mmi_id cui_id;
    m_groupId = mmi_frm_group_create (GRP_ID_ROOT, GRP_ID_AUTO_GEN, VappWidgetContactMenu::onContactSelected, NULL);
    mmi_frm_group_enter(m_groupId, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cui_id = cui_phb_list_select_contact_create(m_groupId);
	cui_phb_list_select_contact_set_widget(cui_id, MMI_TRUE);
    cui_phb_list_select_contact_run(cui_id);
}

void VappWidgetContactMenu::updateMenu()
{
    VfxS32 menuHeight;
    VfxU32 contactCount = srv_phb_vip_contact_get_count();
    if (contactCount == 0)
    {
        m_highlightIndex = 0;
    }
    menuHeight = contactCount * (CELL_NORMAL_HEIGHT + WIDGET_CONTACT_CELL_GAP) + CELL_HIGHLIGHT_HEIGHT;
    if (menuHeight > WIDGET_CONTACT_MENU_HEIGHT)
    {
        menuHeight = WIDGET_CONTACT_MENU_HEIGHT;
    }
    setPos(0, 0);
    setSize(WIDGET_CONTACT_MENU_WIDTH, menuHeight);
    setCacheLen(menuHeight);
    
    ((VappWidgetContact*) getParent())->setSize(WIDGET_CONTACT_MENU_WIDTH, menuHeight);
}

void VappWidgetContactMenu::onCloseCell(VfxS32 group,VfxS32 pos,VfxFrame * cellFrame)
{
    VFX_OBJ_CLOSE(cellFrame);
}

void VappWidgetContactMenu::onTouchCell(
        VcpMenuPos          cellPos,
        CellTouchTypeEnum   touchType,
        VfxPoint            pt,
        VfxFrame            *cell
    )
{
    if (touchType == VcpBaseMenu::TouchTap)
    {
        m_highlightIndex = cellPos.pos;
        m_tapCell = VFX_TRUE;
    }
    if (touchType == VcpBaseMenu::TouchUp && m_highlightIndex == cellPos.pos && m_tapCell == VFX_TRUE)
    {
        m_tapCell = VFX_FALSE;
        VappWidgetContactMenuCell *item = (VappWidgetContactMenuCell *)cell;
        if (item->getStatus() == VappWidgetContactMenuCell::CELL_STATUS_EMPTY_H)
        {
            addNewContact();
        }
        else if (item->getStatus() == VappWidgetContactMenuCell::CELL_STATUS_NORMAL ||
            item->getStatus() == VappWidgetContactMenuCell::CELL_STATUS_EMPTY)
        {
            if (getFocusItem() == cellPos)
            {
                onFocusIndexChange(cellPos, VcpMenuPos(-1, -1));
            }
            m_layout->setFocusItem(cellPos, VFX_TRUE);
        }
        else
        {
            VFX_OBJ_CREATE_EX(m_preView, VappWidgetContactPreView, this, (cell));
            m_preView->m_signalRemove.connect(this, &VappWidgetContactMenu::onContactRemoved);
            m_preView->show(VFX_TRUE);
        }
    }
}

void VappWidgetContactMenu::onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos preFocusItem)
{
    if (!focusItem.isValid())
    {
        return;
    }
    VappWidgetContactMenuCell *cell = (VappWidgetContactMenuCell *)getCellIfPresent(focusItem.group, focusItem.pos);
    if (cell != NULL)
    {
        if (cell->getStatus() == VappWidgetContactMenuCell::CELL_STATUS_NORMAL)
        {
            cell->setHighlight(VFX_FALSE);
        }
        else if(cell->getStatus() == VappWidgetContactMenuCell::CELL_STATUS_EMPTY)
        {
            cell->setEmpty(VFX_FALSE);
        }
    }
    VfxS32 pos = preFocusItem.pos;
    VfxS32 group = preFocusItem.group;
    if (group != 0)
    {
        group = 0;
    }
    VappWidgetContactMenuCell *preCell = (VappWidgetContactMenuCell *)getCellIfPresent(group, pos);
    if (preCell != NULL)
    {
        if (preCell->getStatus() == VappWidgetContactMenuCell::CELL_STATUS_HIGHLIGHT)
        {
            preCell->setNormal(VFX_FALSE);
        }
        else
        {
            preCell->setNoContact(VFX_FALSE);
        }        
    }
    updateLayout();
}

void VappWidgetContactMenu::onUpdateCell(
        const VfxRect &rect,
        VfxS32 group,
        VfxS32 pos,
        VfxFrame* cell,
        VfxU32 flag
)
{
    cell->setPos(rect.origin.x, rect.origin.y); 
}

mmi_ret VappWidgetContactMenu::onContactSelected(mmi_event_struct* evt)
{
    if (evt->evt_id == EVT_ID_PHB_SELECT_CONTACT)
    {
        cui_phb_select_contact_result_struct *result = (cui_phb_select_contact_result_struct*) evt;
        srv_phb_contact contact = srv_phb_read_contact(result->store_index, NULL, NULL);
        VfxWChar *name = srv_phb_contact_get_name(contact);
        srv_phb_iterator iter = srv_phb_contact_get_number_iterator(contact);
        srv_phb_number_struct * number;
        do
        {
            number = srv_phb_contact_get_number_next(&iter);
        }
        while (number && iter && number->is_default == MMI_FALSE);
        srv_phb_update_vip_contact(
            m_highlightIndex,
            result->store_index,
            name,
            number->number,
            result->data_type
            );
        mmi_frm_group_close(m_groupId);
        srv_phb_free_contact(contact);
    }   
    return MMI_RET_OK;
}

VfxBool VappWidgetContactMenu::onKeyInput(VfxKeyEvent &event)
{
    switch (event.keyCode)
    {
        case VFX_KEY_CODE_ARROW_UP:
            if (event.type == VFX_KEY_EVENT_TYPE_UP ||
                event.type == VFX_KEY_EVENT_TYPE_REPEAT ||
                event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS)
            {
                if (event.type == VFX_KEY_EVENT_TYPE_REPEAT)
                {
                    m_isKeyRepeat = VFX_TRUE;
                }
                if (m_highlightIndex > 0)
                {
                    m_highlightIndex --;
                    m_layout->setFocusItem(VcpMenuPos(0, m_highlightIndex), VFX_TRUE);
                }
                else if (event.type != VFX_KEY_EVENT_TYPE_REPEAT && m_isKeyRepeat == VFX_FALSE)
                {
                    m_highlightIndex = m_layout->getCellCount(0) - 1;
                    m_layout->setFocusItem(VcpMenuPos(0, m_highlightIndex), VFX_TRUE);
                }
                if (event.type == VFX_KEY_EVENT_TYPE_UP)
                {
                    m_isKeyRepeat = VFX_FALSE;
                }
            }
            break;
        case VFX_KEY_CODE_ARROW_DOWN:
            if (event.type == VFX_KEY_EVENT_TYPE_UP ||
                event.type == VFX_KEY_EVENT_TYPE_REPEAT ||
                event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS)
            {
                if (event.type == VFX_KEY_EVENT_TYPE_REPEAT)
                {
                    m_isKeyRepeat = VFX_TRUE;
                }
                if (m_highlightIndex < m_layout->getCellCount(0) - 1)
                {
                    if (getCellIfPresent(0, m_highlightIndex + 1) != NULL)
                    {
                        m_highlightIndex ++;
                        m_layout->setFocusItem(VcpMenuPos(0, m_highlightIndex), VFX_TRUE);
                    }
                }
                else if (event.type != VFX_KEY_EVENT_TYPE_REPEAT && m_isKeyRepeat == VFX_FALSE)
                {
                    m_highlightIndex = 0;
                    m_layout->setFocusItem(VcpMenuPos(0, m_highlightIndex), VFX_TRUE);
                }
                if (event.type == VFX_KEY_EVENT_TYPE_UP)
                {
                    m_isKeyRepeat = VFX_FALSE;
                }
            }
            break;
        case VFX_KEY_CODE_CSK:
            if (event.type == VFX_KEY_EVENT_TYPE_UP)
            {
                VappWidgetContactMenuCell *cell = (VappWidgetContactMenuCell *)getCellIfPresent(0, m_highlightIndex);
                if (cell!= NULL)
                {
                    if (cell->getStatus() == VappWidgetContactMenuCell::CELL_STATUS_EMPTY_H)
                    {
                        addNewContact();
                    }
                    else
                    {
                        m_layout->setFocusItem(VcpMenuPos(0, m_highlightIndex), VFX_TRUE);
                        VFX_OBJ_CREATE_EX(m_preView, VappWidgetContactPreView, this, (cell));
                        m_preView->m_signalRemove.connect(this, &VappWidgetContactMenu::onContactRemoved);
                        m_preView->show(VFX_TRUE);
                    }
                }
            }
            break;
        case VFX_KEY_CODE_SEND:
            if (event.type == VFX_KEY_EVENT_TYPE_UP)
            {
                VappWidgetContactMenuCell *cell = (VappWidgetContactMenuCell *)getCellIfPresent(0, m_highlightIndex);
                if (cell->getStatus() == VappWidgetContactMenuCell::CELL_STATUS_HIGHLIGHT)
                {
                    cell->Call();
                }
            }
    }
    return VFX_TRUE;
}

void VappWidgetContactMenu::onContactRemoved(VfxU32 index)
{
    if (index < MMI_PHB_VIP_CONTACT_COUNT)
    {
        srv_phb_vip_contact_delete_entry(index);
        mmi_phb_vip_contact_struct * vipContact = srv_phb_vip_contact_get_entry(index);
        if (vipContact->store_index == SRV_PHB_INVALID_INDEX && m_highlightIndex > 0)
        {
            m_highlightIndex --;
        }
        if (m_layout->getCellCount(0) < 5)
        {
            updateMenu();
        }
        reset();
        setFocusItem(VcpMenuPos(0, m_highlightIndex), VFX_TRUE);
    }
}

void VappWidgetContactMenu::onDragEnd()
{
    VcpBaseMenu::onViewScrollEnd();
    VappWidgetContactMenuLayout *layout = (VappWidgetContactMenuLayout *)getLayout();
    if (layout == NULL)
    {
        return;
    }
    VcpMenuPos focusItem = getFocusItem();
    VcpMenuPos highlightPos = focusItem;
    //VcpMenuRegion visibleRegion = layout->queryRegion(getViewBounds());
    VcpMenuRegion visibleRegion = layout->queryRegion(m_view->getBounds());
    if (visibleRegion.begin == visibleRegion.end ||
        (visibleRegion.end.pos - visibleRegion.begin.pos + 1 == CELL_NORMAL_COUNT && focusItem.pos == (visibleRegion.end.pos + 1)))
    {
        return;
    }
    if (focusItem.isValid())
    {
        if (visibleRegion.isWithin(focusItem))
        {
            if (m_highlightIndex == focusItem.pos)
            {
                return;
            }
        }
        else
        {
            //highlightPos = layout->getCellByPos(getViewBounds().origin);
            highlightPos = layout->getCellByPos(m_view->getBounds().origin);
            if (!highlightPos.isValid())
            {
                return;
            }
        }
    }
    else
    {
        highlightPos = visibleRegion.begin;
    }
    m_highlightIndex = highlightPos.pos;
}


VAPP_WIDGET_SYS_PUBLISH_NATIVE(
    VappWidgetContact,
    VAPP_WIDGET_TYPE_FAVORITE_CONTACT,
    VappWidgetFavContactPublisher);


VAPP_WIDGET_IMPLEMENT_CLASS(VappWidgetContact, VappWidget);
VappWidgetId VappWidgetContact::getId() const
{
    return VappWidgetId(VAPP_WIDGET_SRC_NATIVE, VAPP_WIDGET_TYPE_FAVORITE_CONTACT);
}

void VappWidgetContact::onCreateView()
{
    VappWidget::onCreateView();
    m_indicator = NULL;
    m_menu = NULL;
    mmi_frm_cb_reg_event(EVT_ID_PHB_READY, VappWidgetContact::onPhbReady, this);
    #ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_reg_event(EVT_ID_USB_EXIT_MS_MODE, &VappWidgetContact::onMsModeExit, this);
    #endif
    createMenu();
}

mmi_ret VappWidgetContact::onPhbReady(mmi_event_struct * evt)
{
    if (evt->evt_id == EVT_ID_PHB_READY)
    {
        srv_phb_startup_evt_struct *event = (srv_phb_startup_evt_struct *)evt;
        if (event->phb_ready == MMI_TRUE)
        {
            VappWidgetContact *contactWidget = ((VappWidgetContact *)evt->user_data);
            if (contactWidget->isValid())
            {
                contactWidget->createMenu();
            }
        }
    }
    return MMI_OK;
}

mmi_ret VappWidgetContact::onMsModeExit(mmi_event_struct *evt)
{
    VappWidgetContact *contactWidget = ((VappWidgetContact *)evt->user_data);
    if (contactWidget->isValid())
    {
        contactWidget->resetMenu();
    }
    return MMI_RET_OK;
}

void VappWidgetContact::onReleaseView()
{
    VFX_OBJ_CLOSE(m_menu);
    VFX_OBJ_CLOSE(m_indicator);
    mmi_frm_cb_dereg_event(EVT_ID_PHB_READY, VappWidgetContact::onPhbReady, this);
    #ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_dereg_event(EVT_ID_USB_EXIT_MS_MODE, &VappWidgetContact::onMsModeExit, this);
    #endif
}

VfxSize VappWidgetContact::getMaxSize() const
{
    return VfxSize(50, 50);
}

VfxS32 VappWidgetContact::getName(VfxWChar *string, VfxS32 size)const
{
    const VfxWChar *str = vfxSysResGetStr(STR_ID_VAPP_WIDGET_FAVORITE_CONTACT);

    VFX_ASSERT(string && size > 0);

    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);
}

VfxFrame* VappWidgetContact::createIcon(VfxObject *parentObj)
{
    VfxImageFrame *icon;
    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_ID_VAPP_WIDGET_CONTACT);
    return icon;
}

void VappWidgetContact::setHidden(VfxBool value)
{
    VappWidget::setHidden(value);
    if (m_menu)
    {
        m_menu->setHidden(value);
    }
}

void VappWidgetContact::createMenu()
{
    if (srv_phb_startup_is_phb_ready() && m_menu == NULL)
    {
        if (m_indicator != NULL && m_indicator->isAnimating())
        {
            m_indicator->stop();
        }
        VFX_OBJ_CREATE(m_menu, VappWidgetContactMenu, this);
        m_menu->makeVisible(VcpMenuPos(0, m_menu->getHighlightIndex()), VFX_TRUE);
    }
    else
    {
        VFX_OBJ_CREATE(m_indicator, VcpWaitingIcon, this);
        m_indicator->setAnchor(0.5, 0.5);
        m_indicator->setPos(getSize().width >> 1, getSize().height >> 1);
        m_indicator->start();
    }
}

void VappWidgetContact::resetMenu()
{
    VFX_OBJ_CLOSE(m_menu);
    VFX_OBJ_CREATE(m_menu, VappWidgetContactMenu, this);
}
