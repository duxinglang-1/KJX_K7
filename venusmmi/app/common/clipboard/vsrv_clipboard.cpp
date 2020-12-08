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
 *  vsrv_clipboard.cpp
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  clipboard service class
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vsrv_clipboard.h"
//#include "CommonScreensResdef.h"

#include "mmi_rp_srv_venus_component_text_view_def.h"

    #include "vcp_button.h"
    #include "vfx_cpp_base.h"
    #include "vfx_sys_memory.h"
    #include "vfx_object.h"
    #include "vfx_frame.h"
    #include "mmi_rp_app_uiframework_def.h"
    #include "vfx_datatype.h"
    #include "vfx_basic_type.h"
    #include "vfx_signal.h"
    #include "vfx_input_event.h"
    #include "vfx_top_level.h"
    #include "custom_mmi_default_value.h"
    #include "MMIDataType.h"
    #include "vfx_control.h"
    #include "vfx_text_frame.h"
    #include "vrt_datatype.h"
    #include "lcd_sw_inc.h"
    #include "mmi_rp_srv_editor_def.h"
    #include "vfx_string.h"
    
    #include "vsrv_input_manager.h"

#if  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__) || defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
#include "vcp_vk.h"
#endif

#if defined(__COSMOS_MMI_PACKAGE__)
#include "vcp_info_balloon.h"
#endif

#include "GlobalResDef.h"

extern "C"
{
#include "mmi_clipboard_gprot.h"
#include "wgui_inputs.h"
#include "PixcomFontEngine.h"
#include "gui.h"
#include "CustDataRes.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/

typedef enum
{
    VFX_CCP_LEFT = 0,
    VFX_CCP_MID,
    VFX_CCP_RIGHT,
    VFX_CCP_SINGLE,
    VFX_CCP_MAX
} VfxCcpBtnFrameType;

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/***************************************************************************** 
 * Class VcpClipboardButton
 *****************************************************************************/

void VcpClipboardButton::onInit()
{
    VfxControl::onInit();

    m_isUp = VFX_FALSE;

#if defined(__COSMOS_MMI_PACKAGE__)
    // create font effect object
    m_effect = NULL;
    VFX_ALLOC_NEW(m_effect, VfxFontEffect, this);
    m_effect->setType(VFX_FONT_EFFECT_SHADOW);
    m_effect->setShadow(VFX_COLOR_BLACK,    // shadow color
        135,                                // degree of shadow color
        2,                                  // distant between the shadow original to the text original
        0,                                  // shadow range
        40                                  // shadow intensity
    );
#endif

    // create button
    VFX_OBJ_CREATE(m_button, VcpButton, this);
    m_button->m_signalStateChanged.connect(this, &VcpClipboardButton::onBtnStateChanged);
    m_button->setTextColor(VFX_COLOR_WHITE);
    m_button->setMargin(
        VCCP_FM_LEFT_GAP,
        VCCP_FM_TOP_GAP,
        VCCP_FM_RIGHT_GAP,
        VCCP_FM_BOTTOM_GAP);
    /* Button text font */
    VfxFontDesc btnFont(VFX_FONT_DESC_VF_SIZE(VCCP_FM_BTN_FONT_SIZE));
#if defined(__COSMOS_MMI_PACKAGE__)
    btnFont.effect = m_effect->getEffectId();
#endif

    m_button->setTextFont(btnFont);
    m_button->setIsAutoResized(VFX_TRUE, VCCP_FM_BTN_WIDTH);
    m_button->setSize(VCCP_FM_BTN_WIDTH, VCCP_FM_BTN_HEIGHT);
    
    VfxImageSrc buttonUpArrowDown, buttonUpArrowUp;
    VfxImageSrc buttonDownArrowDown, buttonDownArrowUp;
    
    VFX_OBJ_CREATE(m_frameUpArrowDown, VfxFrame, this);
    VFX_OBJ_CREATE(m_frameUpArrowUp, VfxFrame, this);
    VFX_OBJ_CREATE(m_frameDownArrowDown, VfxFrame, this);
    VFX_OBJ_CREATE(m_frameDownArrowUp, VfxFrame, this);
#if defined(__COSMOS_MMI_PACKAGE__)
    buttonUpArrowUp.setResId(VCP_IMG_TEXT_CLIPBOARD_FM_UP_ARROW_N);
    buttonUpArrowDown.setResId(VCP_IMG_TEXT_CLIPBOARD_FM_UP_ARROW_H);
    buttonDownArrowUp.setResId(VCP_IMG_TEXT_CLIPBOARD_FM_ARROW_N);
    buttonDownArrowDown.setResId(VCP_IMG_TEXT_CLIPBOARD_FM_ARROW_H);
#else
    buttonUpArrowUp.setResId(IMG_ID_VENUS_CLIPBOARD_FM_TOP_ARROW_N);
    buttonUpArrowDown.setResId(IMG_ID_VENUS_CLIPBOARD_FM_TOP_ARROW_H);
    buttonDownArrowUp.setResId(IMG_ID_VENUS_CLIPBOARD_FM_BOTTOM_ARROW_N);
    buttonDownArrowDown.setResId(IMG_ID_VENUS_CLIPBOARD_FM_BOTTOM_ARROW_H);
#endif
    /* Set frame content and placement */
    m_frameUpArrowUp->setImgContent(buttonUpArrowUp);
    m_frameUpArrowUp->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_frameUpArrowDown->setImgContent(buttonUpArrowDown);
    m_frameUpArrowDown->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_frameDownArrowUp->setImgContent(buttonDownArrowUp);
    m_frameDownArrowUp->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_frameDownArrowDown->setImgContent(buttonDownArrowDown);
    m_frameDownArrowDown->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    
    m_frameUpArrowUp->setBounds(VfxRect(0, 0, buttonUpArrowUp.getSize().width, buttonUpArrowUp.getSize().height));
    m_frameUpArrowDown->setBounds(VfxRect(0, 0, buttonUpArrowDown.getSize().width, buttonUpArrowDown.getSize().height));
    m_frameDownArrowUp->setBounds(VfxRect(0, 0, buttonDownArrowUp.getSize().width, buttonDownArrowUp.getSize().height));
    m_frameDownArrowDown->setBounds(VfxRect(0, 0, buttonDownArrowDown.getSize().width, buttonDownArrowDown.getSize().height));

    m_frameDownArrowUp->setHidden(VFX_TRUE);
    m_frameDownArrowDown->setHidden(VFX_TRUE);
    m_frameUpArrowUp->setHidden(VFX_TRUE);
    m_frameUpArrowDown->setHidden(VFX_TRUE);

    m_signalBoundsChanged.connect(this, &VcpClipboardButton::onClipboardButtonBoundsChanged);
}


void VcpClipboardButton::onDeinit()
{
#if defined(__COSMOS_MMI_PACKAGE__)
    if (m_effect)
    {
        VFX_DELETE(m_effect);
    }
#endif
    VfxControl::onDeinit();
}


void VcpClipboardButton::onClipboardButtonBoundsChanged(VfxFrame *source, const VfxRect &oldBounds)
{
    VFX_UNUSED(source);
    VFX_UNUSED(oldBounds);

    m_frameDownArrowUp->setPos(VfxPoint(this->getSize().width / 2 - VCCP_FM_ARROW_WIDTH / 2, VCCP_FM_BTN_HEIGHT - VCCP_FM_ARROW_OVERLAP));
    m_frameDownArrowDown->setPos(VfxPoint(this->getSize().width / 2 - VCCP_FM_ARROW_WIDTH / 2, VCCP_FM_BTN_HEIGHT - VCCP_FM_ARROW_OVERLAP));
    m_frameUpArrowUp->setPos(VfxPoint(this->getSize().width / 2 - VCCP_FM_ARROW_WIDTH / 2, -VCCP_FM_UP_ARROW_HEIGHT));
    m_frameUpArrowDown->setPos(VfxPoint(this->getSize().width / 2 - VCCP_FM_ARROW_WIDTH / 2, -VCCP_FM_UP_ARROW_HEIGHT));
}


void VcpClipboardButton::setArrow(VfxBool b_arrow, VfxBool isUp)
{
    m_b_arrow = b_arrow;
    m_isUp = isUp;

    if (b_arrow == VFX_TRUE)
    {
        if (isUp)
        {
            m_frameDownArrowUp->setHidden(VFX_TRUE);
            m_frameUpArrowUp->setHidden(VFX_FALSE);
        }
        else
        {
            m_frameDownArrowUp->setHidden(VFX_FALSE);
            m_frameUpArrowUp->setHidden(VFX_TRUE);
        }   
        m_frameDownArrowDown->setHidden(VFX_TRUE);
        m_frameUpArrowDown->setHidden(VFX_TRUE);
    }
    else
    {
        m_frameDownArrowUp->setHidden(VFX_TRUE);
        m_frameDownArrowDown->setHidden(VFX_TRUE);
        m_frameUpArrowUp->setHidden(VFX_TRUE);
        m_frameUpArrowDown->setHidden(VFX_TRUE);
    }
}


void VcpClipboardButton::onBtnStateChanged(VfxObject *obj, VfxId id, VcpButtonStateEnum state)
{
    if (m_b_arrow)
    {
        if (state == VCP_BUTTON_STATE_PRESSED)
        {
            if (m_isUp)
            {
                m_frameUpArrowUp->setHidden(VFX_TRUE);
                m_frameUpArrowDown->setHidden(VFX_FALSE);
                m_frameDownArrowUp->setHidden(VFX_TRUE);
                m_frameDownArrowDown->setHidden(VFX_TRUE);
            }
            else
            {
                m_frameDownArrowUp->setHidden(VFX_TRUE);
                m_frameDownArrowDown->setHidden(VFX_FALSE);
                m_frameUpArrowUp->setHidden(VFX_TRUE);
                m_frameUpArrowDown->setHidden(VFX_TRUE);
            }
        }
        else
        {
            if (m_isUp)
            {
                m_frameUpArrowUp->setHidden(VFX_FALSE);
                m_frameUpArrowDown->setHidden(VFX_TRUE);
                m_frameDownArrowUp->setHidden(VFX_TRUE);
                m_frameDownArrowDown->setHidden(VFX_TRUE);
            }
            else
            {
                m_frameDownArrowUp->setHidden(VFX_FALSE);
                m_frameDownArrowDown->setHidden(VFX_TRUE);
                m_frameUpArrowUp->setHidden(VFX_TRUE);
                m_frameUpArrowDown->setHidden(VFX_TRUE);
            }
        }
    }
}


/***************************************************************************** 
 * Class VsrvClipboard
 *****************************************************************************/

void VsrvClipboard::showMenu(VfxCcpMenuType type, VfxPoint p1, VfxPoint p2)
{
    VfxPoint p;

    if (m_menu)
    {
        hideMenu();
    }
    
    VFX_OBJ_CREATE(m_menu, VfxClipboardMenu, m_client);

    // add menu to top level child
    VFX_OBJ_GET_INSTANCE(VfxTopLevel)->addChildFrame(m_menu);
    
    m_menu->m_signalBtnEvent.connect(this, &VsrvClipboard::onBtnEvent);

    VfxPen *vfxPenPtr = VFX_OBJ_GET_INSTANCE(VfxPen);

    vfxPenPtr->m_signalEventProcessed.connect(this, &VsrvClipboard::onPenEventProcessed);

    m_menu->setPosZ(VFX_TOP_LEVEL_Z_POPUP - 1);

    setMenu(type);

    switch (type)
    {
    case VFX_CCP_FLOATING_MENU:
        p.x = (p1.x + p2.x) / 2;
        if (p1.y - VCCP_FM_MENU_HEIGHT < 0 && p1.y > 0)
        {
            p.y = p2.y + VCCP_FM_MENU_HEIGHT;
            m_menu->setArrowIsUp(VFX_TRUE);
        }
        else
        {
            p.y = p1.y;
            m_menu->setArrowIsUp(VFX_FALSE);
        }
        m_menu->setPos(p);
        m_menu->show();
        break;
    case VFX_CCP_CASCADING_MENU:
        break;
    }
}


void VsrvClipboard::onPenEventProcessed(VfxPenEvent &event, VfxControl *control)
{
    if (m_menu)
    {
        /* Hide menu when pen down on other control */
        if (event.type == VFX_PEN_EVENT_TYPE_DOWN && !hitTest(event))
        {
        #if  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__) || defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)
            // if pen down on VK, do not hide menu because we may need to replace the highlihght string
            // if we hide menu, the highlight will be cleared.
            VcpVK *ctrl = VFX_OBJ_DYNAMIC_CAST(control, VcpVK);
            if (!ctrl)
        #endif
            {
                hideMenu();
            }
        }
    }
}


VfxBool VsrvClipboard::hideMenu()
{
    if (m_menu)
    {
        m_signalClipboardEvent.postEmit(VFX_CCP_NOTIFY_HIDE_MENU, NULL, 0, NULL);
        m_menu->hide();
        VFX_OBJ_CLOSE(m_menu);
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


void VsrvClipboard::setMenu(VfxCcpMenuType type)
{
    switch (type)
    {
    case VFX_CCP_CASCADING_MENU:
        break;
    case VFX_CCP_FLOATING_MENU:
        setFloatingMenu();
        break;
    default:
        break;
    }      
}

VfxBool VsrvClipboard::hitTest(const VfxPenEvent &event)
{
    if (m_menu)
    {
        return m_menu->hitTest(event);
    }

    return VFX_FALSE;
}


void VsrvClipboard::setFloatingMenu()
{
    VfxS32 len = 0;
    VfxS32 b_ro = 0;
    VfxS32 b_empty = 0;
    VfxBool b_clb_empty = this->isEmpty();
    VfxS32 b_pwd = 0;

    /* Config menu item according to client type */
    m_signalClipboardEvent.emit(VFX_CCP_REQ_IS_SELECTED_TEXT, NULL, 0, &len);
    m_signalClipboardEvent.emit(VFX_CCP_REQ_IS_READ_ONLY, NULL, 0, &b_ro);
    m_signalClipboardEvent.emit(VFX_CCP_REQ_IS_EMPTY, NULL, 0, &b_empty);
    m_signalClipboardEvent.emit(VFX_CCP_REQ_IS_PASSWORD, NULL, 0, &b_pwd);

    m_menu->m_count = 0;
    /* Copy */
    if (len > 0 && (b_pwd == 0))
    {
        m_menu->m_menuStatus[VFX_CCP_BTN_COPY] = VFX_TRUE;
        m_menu->m_count++;
    }
    else
    {
        m_menu->m_menuStatus[VFX_CCP_BTN_COPY] = VFX_FALSE;
    }

    /* Cut */
    if ((len > 0) && (b_ro == 0) && (b_pwd == 0))
    {
        m_menu->m_menuStatus[VFX_CCP_BTN_CUT] = VFX_TRUE;
        m_menu->m_count++;
    }
    else
    {
        m_menu->m_menuStatus[VFX_CCP_BTN_CUT] = VFX_FALSE;
    }

    /* Paste */
    if ((b_clb_empty == VFX_FALSE) && (b_ro == 0))
    {
        m_menu->m_menuStatus[VFX_CCP_BTN_PASTE] = VFX_TRUE;
        m_menu->m_count++;
    }
    else
    {
        m_menu->m_menuStatus[VFX_CCP_BTN_PASTE] = VFX_FALSE;
    }

    /* Copy All */
    if ((b_empty == 0) && (len == 0) && (b_pwd == 0))
    {
        m_menu->m_menuStatus[VFX_CCP_BTN_COPY_ALL] = VFX_TRUE;
        m_menu->m_count++;
    }
    else
    {
        m_menu->m_menuStatus[VFX_CCP_BTN_COPY_ALL] = VFX_FALSE;
    }

    /* Cut All */
    if ((b_empty == 0) && (len == 0) && (b_ro == 0) && (b_pwd == 0))
    {
        m_menu->m_menuStatus[VFX_CCP_BTN_CUT_ALL] = VFX_TRUE;
        m_menu->m_count++;
    }
    else
    {
        m_menu->m_menuStatus[VFX_CCP_BTN_CUT_ALL] = VFX_FALSE;
    }
}


VfxBool VsrvClipboard::isEmpty()
{
    mmi_clipboard_unicodetext_data_struct *cb_data;

    /* get the text context from the clipboard */
    cb_data = (mmi_clipboard_unicodetext_data_struct*)mmi_clipboard_get_data_by_type(MMI_CLIPBOARD_FORMAT_UNICODETEXT);
    if (cb_data != NULL && cb_data->len > 0)
    {
        return VFX_FALSE;
    }
    else
    {
        return VFX_TRUE;
    }
}


void VsrvClipboard::onBtnEvent(VfxCcpEventType type)
{
    switch (type)
    {
    case VFX_CCP_NOTIFY_COPY:
        copy();
        break;
    case VFX_CCP_NOTIFY_CUT:
        cut();
        break;
    case VFX_CCP_NOTIFY_PASTE:
        paste();
        break;
    case VFX_CCP_NOTIFY_COPY_ALL:
        copyAll();
        break;
    case VFX_CCP_NOTIFY_CUT_ALL:
        cutAll();
        break;
    default:
        break;
    }

    hideMenu();
}

VfxS32 VsrvClipboard::copy()
{
    VfxWChar *string = NULL;
    VfxS32 len = 0;

    m_signalClipboardEvent.emit(VFX_CCP_CMD_GET_TEXT, &string, 0, &len);

    if (len > 0)
    {
        setClipboardData(string, len);
    }
    
    m_signalClipboardEvent.emit(VFX_CCP_NOTIFY_COPY, NULL, 0, NULL);

    return len;
}


VfxS32 VsrvClipboard::cut()
{
    VfxWChar *string = NULL;
    VfxS32 len = 0;

    m_signalClipboardEvent.emit(VFX_CCP_CMD_GET_TEXT, &string, 0, &len);

    if (len > 0)
    {
        setClipboardData(string, len);
    }

    m_signalClipboardEvent.emit(VFX_CCP_CMD_DEL_TEXT, &string, len, NULL);

    m_signalClipboardEvent.emit(VFX_CCP_NOTIFY_CUT, NULL, 0, NULL);
    return len;
}


VfxS32 VsrvClipboard::paste()
{
    VfxWChar *string = NULL;
    VfxS32 len = 0;
    VfxS32 ret_len = 0;
    
    len = getClipboardData(&string);
    m_signalClipboardEvent.emit(VFX_CCP_CMD_INSERT_TEXT, &string, len, &ret_len);

    m_signalClipboardEvent.emit(VFX_CCP_NOTIFY_PASTE, NULL, 0, NULL);
    return ret_len;
}


VfxS32 VsrvClipboard::copyAll()
{
    VfxWChar *string = NULL;
    VfxS32 len = 0;

    m_signalClipboardEvent.emit(VFX_CCP_CMD_GET_ALL_TEXT, &string, 0, &len);

    if (len > 0)
    {
        setClipboardData(string, len);
    }

    m_signalClipboardEvent.emit(VFX_CCP_NOTIFY_COPY_ALL, NULL, 0, NULL);
    return len;
}


VfxS32 VsrvClipboard::cutAll()
{
    VfxWChar *string = NULL;
    VfxS32 len = 0;

    m_signalClipboardEvent.emit(VFX_CCP_CMD_GET_ALL_TEXT, &string, 0, &len);

    if (len > 0)
    {
        setClipboardData(string, len);
    }

    m_signalClipboardEvent.emit(VFX_CCP_CMD_DEL_ALL_TEXT, NULL, 0, NULL);

    m_signalClipboardEvent.emit(VFX_CCP_NOTIFY_CUT_ALL, NULL, 0, NULL);
    return len;
}


VfxS32 VsrvClipboard::getClipboardData(VfxWChar **string)
{
    mmi_clipboard_unicodetext_data_struct *cb_data;

    /* get the text context from the clipboard */
    cb_data = (mmi_clipboard_unicodetext_data_struct*)mmi_clipboard_get_data_by_type(MMI_CLIPBOARD_FORMAT_UNICODETEXT);

    if (cb_data != NULL && cb_data->len > 0)
    {
        *string = (VfxWChar *)cb_data->data; /* get the text from the clipboard */
        return cb_data->len;
    }
    else
    {
        return 0;
    }
}


VfxCcpRetType VsrvClipboard::setClipboardData(VfxWChar *string, VfxS32 len)
{
    mmi_clipboard_unicodetext_data_struct cb_data;
    VfxS32 free_space;
    mmi_clipboard_handle handle;

    /* Free space should subtract the cb_data.len size */
    free_space = VCCP_MAX_BUFFER_SIZE;

    if (string != NULL && len > 0)
    {
        cb_data.len = (len) > (S32)(free_space / ENCODING_LENGTH) ? (free_space / ENCODING_LENGTH) : len;
        cb_data.data = (PS8)string;
        handle  = mmi_clipboard_set_data(MMI_CLIPBOARD_FORMAT_UNICODETEXT, (void*)&cb_data);
        if (handle)
        {
            if (len <= (S32)(free_space / ENCODING_LENGTH))
            {
                return VFX_CCP_RET_OK;
            }
            else
            {
            #if defined(__COSMOS_MMI_PACKAGE__)
                VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
                balloon->addItem(
                    VCP_INFO_BALLOON_TYPE_INFO,
                    VFX_WSTR_RES(STR_ID_CLIPBOARD_TRUNCATE_FOR_MEMORY));
            #endif
                return VFX_CCP_RET_MEMORY_NOT_ENOUGH;
            }
        }
        else
        {
            /* error handling */
        #if defined(__COSMOS_MMI_PACKAGE__)
            VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
            balloon->addItem(
                VCP_INFO_BALLOON_TYPE_INFO,
                VFX_WSTR_RES(STR_GLOBAL_NOT_ENOUGH_MEMORY));
        #endif
            return VFX_CCP_RET_MEMORY_ERROR;
        }
    }
    else
    {
        return VFX_CCP_RET_NO_TEXT;
    }
}


/***************************************************************************** 
 * Class VfxClipboardMenu
 *****************************************************************************/
void VfxClipboardMenu::onBtnClicked(VfxObject* obj, VfxId id)
{
    switch (id)
    {
    case VFX_CCP_BTN_COPY:
        this->m_signalBtnEvent.emit(VFX_CCP_NOTIFY_COPY);
        break;
    case VFX_CCP_BTN_CUT:
        this->m_signalBtnEvent.emit(VFX_CCP_NOTIFY_CUT);
        break;
    case VFX_CCP_BTN_COPY_ALL:
        this->m_signalBtnEvent.emit(VFX_CCP_NOTIFY_COPY_ALL);
        break;
    case VFX_CCP_BTN_CUT_ALL:
        this->m_signalBtnEvent.emit(VFX_CCP_NOTIFY_CUT_ALL);
        break;
    case VFX_CCP_BTN_PASTE:
        this->m_signalBtnEvent.emit(VFX_CCP_NOTIFY_PASTE);
        break;
    default:
        break;
    }
}


void VfxClipboardMenu::onInit()
{
    VfxS32 i = 0;

    VfxControl::onInit();

    for (i = 0; i < VFX_CCP_BTN_TOTAL; i++)
    {
        m_btn[i] = NULL;
    }

    m_arrowIsUp = VFX_FALSE;
}


void VfxClipboardMenu::onDeinit()
{
    VfxControl::onDeinit();
}


VfxBool VfxClipboardMenu::hitTest(const VfxPenEvent &event)
{
    VfxS32 i;
    VfxPoint point;
    
    for (i = 0; i < VFX_CCP_BTN_TOTAL; i++)
    {
        if ((m_menuStatus[i] == VFX_TRUE))
        {
            point = event.getRelPos(m_btn[i]);
            
            //if (m_btn[i]->hitTest(point))
            if (m_btn[i]->containPoint(point))
                return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}

void VfxClipboardMenu::createButton(VfxS32 type, VfxS32 index, VfxS32 gap)
{
    if (m_count <= 0 || m_count > 3)
    {
        return;
    }

    vrt_size_struct mainScreenSize;
    vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
    VfxS32 screenWidth = mainScreenSize.width;

    /* Create button */
    if (m_btn[type])
    {
        VFX_OBJ_CLOSE(m_btn[type]);
    }
    VFX_OBJ_CREATE(m_btn[type], VcpClipboardButton, this);

    VfxCcpBtnFrameType btnFrameType = VFX_CCP_LEFT;
    VfxResId string_id = 0;

    /* Set background frame */
    if (m_count == 1)
    {
        btnFrameType = VFX_CCP_SINGLE;
        m_arrowBtnIndex = type;
        m_btn[type]->setArrow(VFX_TRUE, m_arrowIsUp);
    }
    else if (m_count == 2)
    {
        if (index == 0)
        {
            /* Left button */
            btnFrameType = VFX_CCP_LEFT;
            if (this->getPos().x < screenWidth / 2)
            {
                m_arrowBtnIndex = type;
                m_btn[type]->setArrow(VFX_TRUE, m_arrowIsUp);
            }
        }
        else
        {
            /* Right button */
            btnFrameType = VFX_CCP_RIGHT;
            if (this->getPos().x >= screenWidth / 2)
            {
                m_arrowBtnIndex = type;
                m_btn[type]->setArrow(VFX_TRUE, m_arrowIsUp);
            }
        }
    }
    else if (m_count == 3)
    {
        if (index == 0)
        {
            /* Left button */
            btnFrameType = VFX_CCP_LEFT;
            if (this->getPos().x >= 0 && this->getPos().x < screenWidth / 3)
            {
                m_arrowBtnIndex = type;
                m_btn[type]->setArrow(VFX_TRUE, m_arrowIsUp);
            }
        }
        else if (index  == 1)
        {
            /* Middle button */
            btnFrameType = VFX_CCP_MID;
            if (this->getPos().x >= screenWidth / 3 && this->getPos().x < (2 * screenWidth / 3))
            {
                m_arrowBtnIndex = type;
                m_btn[type]->setArrow(VFX_TRUE, m_arrowIsUp);
            }
        }
        else if (index == 2)
        {
            /* Right button */
            btnFrameType = VFX_CCP_RIGHT;
            if (this->getPos().x >= (2 * screenWidth / 3) && this->getPos().x < screenWidth)
            {
                m_arrowBtnIndex = type;
                m_btn[type]->setArrow(VFX_TRUE, m_arrowIsUp);
            }
        }
    }
 
    switch (btnFrameType)
    {
    case VFX_CCP_LEFT:
    #if defined(__COSMOS_MMI_PACKAGE__)
        m_btn[type]->m_button->setBgImageList(VcpStateImage(
                        VCP_IMG_TEXT_CLIPBOARD_FM_LEFT_N,
                        VCP_IMG_TEXT_CLIPBOARD_FM_LEFT_H,
                        VCP_IMG_TEXT_CLIPBOARD_FM_LEFT_N,
                        VCP_IMG_TEXT_CLIPBOARD_FM_LEFT_N));
        m_btn[type]->m_button->setMargin(
            VCCP_FM_BTN_LEFT_SHADOW + VCCP_FM_BTN_TEXT_GAP,
            VCCP_FM_BTN_TOP_SHADOW,
            VCCP_FM_BTN_TEXT_GAP,
            VCCP_FM_BTN_BOTTOM_SHADOW);
    #else
        m_btn[type]->m_button->setBgImageList(VcpStateImage(
                        IMG_ID_VENUS_CLIPBOARD_FM_LEFT_N,
                        IMG_ID_VENUS_CLIPBOARD_FM_LEFT_H,
                        IMG_ID_VENUS_CLIPBOARD_FM_LEFT_N,
                        IMG_ID_VENUS_CLIPBOARD_FM_LEFT_N));
    #endif
        break;
    case VFX_CCP_RIGHT:
    #if defined(__COSMOS_MMI_PACKAGE__)
        m_btn[type]->m_button->setBgImageList(VcpStateImage(
                        VCP_IMG_TEXT_CLIPBOARD_FM_RIGHT_N,
                        VCP_IMG_TEXT_CLIPBOARD_FM_RIGHT_H,
                        VCP_IMG_TEXT_CLIPBOARD_FM_RIGHT_N,
                        VCP_IMG_TEXT_CLIPBOARD_FM_RIGHT_N));
        m_btn[type]->m_button->setMargin(
            VCCP_FM_BTN_TEXT_GAP,
            VCCP_FM_BTN_TOP_SHADOW,
            VCCP_FM_BTN_RIGHT_SHADOW + VCCP_FM_BTN_TEXT_GAP,
            VCCP_FM_BTN_BOTTOM_SHADOW);
    #else
        m_btn[type]->m_button->setBgImageList(VcpStateImage(
                        IMG_ID_VENUS_CLIPBOARD_FM_RIGHT_N,
                        IMG_ID_VENUS_CLIPBOARD_FM_RIGHT_H,
                        IMG_ID_VENUS_CLIPBOARD_FM_RIGHT_N,
                        IMG_ID_VENUS_CLIPBOARD_FM_RIGHT_N));
    #endif
        break;
    case VFX_CCP_MID:
    #if defined(__COSMOS_MMI_PACKAGE__)
        m_btn[type]->m_button->setBgImageList(VcpStateImage(
                        VCP_IMG_TEXT_CLIPBOARD_FM_MIDDLE_N,
                        VCP_IMG_TEXT_CLIPBOARD_FM_MIDDLE_H,
                        VCP_IMG_TEXT_CLIPBOARD_FM_MIDDLE_N,
                        VCP_IMG_TEXT_CLIPBOARD_FM_MIDDLE_N));
        m_btn[type]->m_button->setMargin(
            VCCP_FM_BTN_TEXT_GAP,
            VCCP_FM_BTN_TOP_SHADOW,
            VCCP_FM_BTN_TEXT_GAP,
            VCCP_FM_BTN_BOTTOM_SHADOW);
    #else
        m_btn[type]->m_button->setBgImageList(VcpStateImage(
                        IMG_ID_VENUS_CLIPBOARD_FM_MIDDLE_N,
                        IMG_ID_VENUS_CLIPBOARD_FM_MIDDLE_H,
                        IMG_ID_VENUS_CLIPBOARD_FM_MIDDLE_N,
                        IMG_ID_VENUS_CLIPBOARD_FM_MIDDLE_N));
    #endif
        break;
    case VFX_CCP_SINGLE:
    #if defined(__COSMOS_MMI_PACKAGE__)
        m_btn[type]->m_button->setBgImageList(VcpStateImage(
                        VCP_IMG_TEXT_CLIPBOARD_FM_SINGLE_N,
                        VCP_IMG_TEXT_CLIPBOARD_FM_SINGLE_H,
                        VCP_IMG_TEXT_CLIPBOARD_FM_SINGLE_N,
                        VCP_IMG_TEXT_CLIPBOARD_FM_SINGLE_N));
        m_btn[type]->m_button->setMargin(
            VCCP_FM_BTN_LEFT_SHADOW + VCCP_FM_BTN_TEXT_GAP,
            VCCP_FM_BTN_TOP_SHADOW,
            VCCP_FM_BTN_RIGHT_SHADOW + VCCP_FM_BTN_TEXT_GAP,
            VCCP_FM_BTN_BOTTOM_SHADOW);
    #else
        m_btn[type]->m_button->setBgImageList(VcpStateImage(
                        IMG_ID_VENUS_CLIPBOARD_FM_SINGLE_N,
                        IMG_ID_VENUS_CLIPBOARD_FM_SINGLE_H,
                        IMG_ID_VENUS_CLIPBOARD_FM_SINGLE_N,
                        IMG_ID_VENUS_CLIPBOARD_FM_SINGLE_N));
    #endif
        break;
    default:
        return;
    }

    switch (type)
    {
    case VFX_CCP_BTN_COPY:
        m_btn[type]->m_button->m_signalClicked.connect(this, &VfxClipboardMenu::onBtnClicked);
        m_btn[type]->m_button->setId(type);
        string_id = STR_ID_CLIPBOARD_COPY;
        break;
    case VFX_CCP_BTN_CUT:
        m_btn[type]->m_button->m_signalClicked.connect(this, &VfxClipboardMenu::onBtnClicked);
        m_btn[type]->m_button->setId(type);
        string_id = STR_ID_CLIPBOARD_CUT;
        break;
    case VFX_CCP_BTN_PASTE:
        m_btn[type]->m_button->m_signalClicked.connect(this, &VfxClipboardMenu::onBtnClicked);
        m_btn[type]->m_button->setId(type);
        string_id = STR_ID_CLIPBOARD_PASTE;
        break;
    case VFX_CCP_BTN_COPY_ALL:
        m_btn[type]->m_button->m_signalClicked.connect(this, &VfxClipboardMenu::onBtnClicked);
        m_btn[type]->m_button->setId(type);
        string_id = STR_ID_CLIPBOARD_COPY_ALL;
        break;
    case VFX_CCP_BTN_CUT_ALL:
        m_btn[type]->m_button->m_signalClicked.connect(this, &VfxClipboardMenu::onBtnClicked);
        m_btn[type]->m_button->setId(type);
        string_id = STR_ID_CLIPBOARD_CUT_ALL;
        break;
    }

    m_btn[type]->m_button->setText(string_id);
    m_btn[type]->m_button->forceUpdate();
    m_btn[type]->setBounds(VfxRect(0, -VCCP_FM_UP_ARROW_HEIGHT, m_btn[type]->m_button->getBounds().getWidth(), VCCP_FM_MENU_HEIGHT));
}


VfxS32 VfxClipboardMenu::createMenu(VfxS32 gap, VfxS32 fontSize)
{
    VfxS32 i;
    VfxS32 index = 0; /* button index */
    VfxS32 xWidth = 0;
    VfxBool f_arrow = VFX_FALSE;

    VfxFontDesc btnFont;
    
    m_arrowBtnIndex = -1;
    m_arrowBtnOffset = 0;
    for (i = 0; i < VFX_CCP_BTN_TOTAL; i++)
    {
        if (m_menuStatus[i] == VFX_TRUE)
        {
            createButton(i, index, gap);
            if (fontSize != VCCP_FM_BTN_FONT_SIZE)
            {
                // change button font size and update
                btnFont = m_btn[i]->m_button->getTextFont();
                btnFont.size = VFX_FONT_DESC_VF_SIZE(fontSize);
                m_btn[i]->m_button->setTextFont(btnFont);
                m_btn[i]->m_button->forceUpdate();
                m_btn[i]->setBounds(VfxRect(0, -VCCP_FM_UP_ARROW_HEIGHT, m_btn[i]->m_button->getBounds().getWidth(), VCCP_FM_MENU_HEIGHT));
            }
            m_btn[i]->setPos(VfxPoint(xWidth, 0));
            if (!f_arrow)
            {
                if (m_arrowBtnIndex == -1)
                {
                    m_arrowBtnOffset += m_btn[i]->getSize().width;
                }
                else
                {
                    m_arrowBtnOffset += m_btn[i]->getSize().width / 2;
                    f_arrow = VFX_TRUE;
                }
            }
            xWidth += m_btn[i]->getSize().width;
            index++;
        }
    }

    this->setBounds(VfxRect(0, 0, xWidth, VCCP_FM_MENU_HEIGHT));

    return index;
}


void VfxClipboardMenu::create()
{
    VfxS32 xWidth = 0;
    VfxS32 btn_cnt = 0;
    VfxS32 gap = VCCP_FM_LEFT_GAP + VCCP_FM_RIGHT_GAP;

    vrt_size_struct mainScreenSize;
    vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
    VfxS32 screenWidth = mainScreenSize.width;

    do
    {
        btn_cnt = createMenu(gap);

        /* No available button */
        if (btn_cnt <= 0)
        {
            return;
        }
    
        gap -= VCCP_FM_RESIZE_WIDTH;
    } while (this->getSize().width >= screenWidth && (gap >= 0));

    // desc button font size if menu wider than screen width
    VfxS32 fontSize = (VCCP_FM_BTN_FONT_SIZE - 1);
    while (getSize().width > screenWidth && fontSize > 0)
    {
        btn_cnt = createMenu(gap, fontSize);

        /* No available button */
        if (btn_cnt <= 0)
        {
            return;
        }

        fontSize--;
    }

    /* Move */
    xWidth = this->getSize().width;
    this->setPos(VfxPoint(this->getPos().x - m_arrowBtnOffset, this->getPos().y - VCCP_FM_MENU_HEIGHT));
    if (this->getPos().x + xWidth > screenWidth)
    {
        this->setPos(VfxPoint(screenWidth - xWidth, this->getPos().y));
    }

    if (this->getPos().x <= 0)
    {
        this->setPos(VfxPoint(0, this->getPos().y));
    }

    if (this->getPos().y < 0)
    {
        this->setPos(VfxPoint(this->getPos().x, 0));
    }

    if (this->getPos().y + VCCP_FM_MENU_HEIGHT >= mainScreenSize.height)
    {
        this->setPos(VfxPoint(this->getPos().x, mainScreenSize.height - VCCP_FM_MENU_HEIGHT));
    }
}


void VfxClipboardMenu::show()
{
    this->create();
    setHidden(VFX_FALSE);
}

void VfxClipboardMenu::hide()
{
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
#endif

}

void VfxClipboardMenu::move(VfxPoint p)
{
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    VfxPoint pos;

    pos = convertPointTo(p, topLevel);
    this->setPos(pos);
}
