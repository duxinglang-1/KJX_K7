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
 *  vsrv_clipboard.h
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  clipboard service class header file
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
 * removed!
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VSRV_CLIPBOARD_H__
#define __VSRV_CLIPBOARD_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
//#include "vfx_uc_include.h"
//#include "cp\vcp_pluto_control.h"
//#include "ime\vsrv_input_manager.h"
//#include "GUI\vadp_v2p_inputbox.h"
#include "vcp_button.h"

    #include "vfx_cpp_base.h"
    #include "vfx_frame.h"
    #include "vfx_basic_type.h"
    #include "vfx_input_event.h"
    #include "vfx_control.h"
    #include "vfx_datatype.h"
    #include "vfx_signal.h"
    #include "vfx_object.h"

extern "C"
{
#include "wgui_inputs.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__COSMOS_MMI_PACKAGE__)

#if defined(__MMI_MAINLCD_480X800__)
#define VCCP_FM_BTN_FONT_SIZE   26
#define VCCP_FM_LEFT_GAP        14
#define VCCP_FM_RIGHT_GAP       14
#define VCCP_FM_TOP_GAP         10
#define VCCP_FM_BOTTOM_GAP      10
#define VCCP_FM_BTN_HEIGHT      87
#define VCCP_FM_BTN_WIDTH       90
#define VCCP_FM_ARROW_HEIGHT    16
#define VCCP_FM_ARROW_WIDTH     25
#define VCCP_FM_ARROW_OVERLAP   18
#define VCCP_FM_LINE_HEIGHT     25
#define VCCP_FM_MENU_HEIGHT     (VCCP_FM_BTN_HEIGHT + VCCP_FM_UP_ARROW_HEIGHT)
#define VCCP_FM_RESIZE_WIDTH    10
#define VCCP_FM_BTN_LEFT_SHADOW    7
#define VCCP_FM_BTN_TOP_SHADOW     0
#define VCCP_FM_BTN_RIGHT_SHADOW   7
#define VCCP_FM_BTN_BOTTOM_SHADOW 17
#define VCCP_FM_BTN_TEXT_GAP      14
#define VCCP_FM_UP_ARROW_HEIGHT   15
#elif defined(__MMI_MAINLCD_320X480__)
#define VCCP_FM_BTN_FONT_SIZE   18
#define VCCP_FM_LEFT_GAP         8
#define VCCP_FM_RIGHT_GAP        8
#define VCCP_FM_TOP_GAP          5
#define VCCP_FM_BOTTOM_GAP       5
#define VCCP_FM_BTN_HEIGHT      55
#define VCCP_FM_BTN_WIDTH       56
#define VCCP_FM_ARROW_HEIGHT    12
#define VCCP_FM_ARROW_WIDTH     16
#define VCCP_FM_ARROW_OVERLAP    8
#define VCCP_FM_LINE_HEIGHT     25
#define VCCP_FM_MENU_HEIGHT     (VCCP_FM_BTN_HEIGHT + 5 + VCCP_FM_UP_ARROW_HEIGHT)
#define VCCP_FM_RESIZE_WIDTH    10
#define VCCP_FM_BTN_LEFT_SHADOW    3
#define VCCP_FM_BTN_TOP_SHADOW     0
#define VCCP_FM_BTN_RIGHT_SHADOW   3
#define VCCP_FM_BTN_BOTTOM_SHADOW  7
#define VCCP_FM_BTN_TEXT_GAP       8
#define VCCP_FM_UP_ARROW_HEIGHT   11
#else
#define VCCP_FM_BTN_FONT_SIZE   16
#define VCCP_FM_LEFT_GAP        10
#define VCCP_FM_RIGHT_GAP       10
#define VCCP_FM_TOP_GAP          5
#define VCCP_FM_BOTTOM_GAP       5
#define VCCP_FM_BTN_HEIGHT      47
#define VCCP_FM_BTN_WIDTH       46
#define VCCP_FM_ARROW_HEIGHT    10
#define VCCP_FM_ARROW_WIDTH     14
#define VCCP_FM_ARROW_OVERLAP    8
#define VCCP_FM_LINE_HEIGHT     25
#define VCCP_FM_MENU_HEIGHT     (VCCP_FM_BTN_HEIGHT + 3 + VCCP_FM_UP_ARROW_HEIGHT)
#define VCCP_FM_RESIZE_WIDTH    10
#define VCCP_FM_BTN_LEFT_SHADOW    3
#define VCCP_FM_BTN_TOP_SHADOW     0
#define VCCP_FM_BTN_RIGHT_SHADOW   3
#define VCCP_FM_BTN_BOTTOM_SHADOW  7
#define VCCP_FM_BTN_TEXT_GAP       5
#define VCCP_FM_UP_ARROW_HEIGHT    9
#endif

#else /* __COSMOS_MMI_PACKAGE__ */

#if defined(__MMI_MAINLCD_480X800__)
#define VCCP_FM_BTN_FONT_SIZE   22
#define VCCP_FM_LEFT_GAP        20
#define VCCP_FM_RIGHT_GAP       20
#define VCCP_FM_TOP_GAP         10
#define VCCP_FM_BOTTOM_GAP      10
#define VCCP_FM_BTN_HEIGHT      60
#define VCCP_FM_BTN_WIDTH       60
#define VCCP_FM_ARROW_HEIGHT    11
#define VCCP_FM_ARROW_WIDTH     34
#define VCCP_FM_ARROW_OVERLAP    5
#define VCCP_FM_LINE_HEIGHT     25
#define VCCP_FM_MENU_HEIGHT     (VCCP_FM_BTN_HEIGHT + VCCP_FM_ARROW_HEIGHT + VCCP_FM_UP_ARROW_HEIGHT)
#define VCCP_FM_RESIZE_WIDTH    10
#define VCCP_FM_UP_ARROW_HEIGHT 10
#else /* __MMI_MAINLCD_480X800__ */
#define VCCP_FM_BTN_FONT_SIZE   14
#define VCCP_FM_LEFT_GAP        10
#define VCCP_FM_RIGHT_GAP       10
#define VCCP_FM_TOP_GAP          5
#define VCCP_FM_BOTTOM_GAP       5
#define VCCP_FM_BTN_HEIGHT      37
#define VCCP_FM_BTN_WIDTH       60
#define VCCP_FM_ARROW_HEIGHT    11
#define VCCP_FM_ARROW_WIDTH     34
#define VCCP_FM_ARROW_OVERLAP    5
#define VCCP_FM_LINE_HEIGHT     25
#define VCCP_FM_MENU_HEIGHT     (VCCP_FM_BTN_HEIGHT + VCCP_FM_ARROW_HEIGHT + VCCP_FM_UP_ARROW_HEIGHT)
#define VCCP_FM_RESIZE_WIDTH    10
#define VCCP_FM_UP_ARROW_HEIGHT 10
#endif /* __MMI_MAINLCD_480X800__ */

#endif /* __COSMOS_MMI_PACKAGE__ */

#define VCCP_MAX_BUFFER_SIZE   WGUI_INPUTS_CLIPBOARD_MAX_SIZE

typedef enum
{
    VFX_CCP_CASCADING_MENU = 0,
    VFX_CCP_FLOATING_MENU,
    VFX_CCP_MENU_END
} VfxCcpMenuType;

typedef enum
{
    VFX_CCP_BTN_COPY = 0,
    VFX_CCP_BTN_CUT,
    VFX_CCP_BTN_COPY_ALL,
    VFX_CCP_BTN_CUT_ALL,
    VFX_CCP_BTN_PASTE,
    VFX_CCP_BTN_TOTAL
} VfxCcpBtnType;

typedef enum
{
    VFX_CCP_NOTIFY_COPY = 0,
    VFX_CCP_NOTIFY_CUT,
    VFX_CCP_NOTIFY_PASTE,
    VFX_CCP_NOTIFY_COPY_ALL,
    VFX_CCP_NOTIFY_CUT_ALL,
    VFX_CCP_NOTIFY_HIDE_MENU,
    VFX_CCP_CMD_GET_TEXT,
    VFX_CCP_CMD_GET_ALL_TEXT,
    VFX_CCP_CMD_DEL_TEXT,
    VFX_CCP_CMD_DEL_ALL_TEXT,
    VFX_CCP_CMD_INSERT_TEXT,
    VFX_CCP_REQ_IS_SELECTED_TEXT,
    VFX_CCP_REQ_IS_EMPTY,
    VFX_CCP_REQ_IS_READ_ONLY,
    VFX_CCP_REQ_IS_PASSWORD,
    VFX_CCP_END
} VfxCcpEventType;

typedef enum
{
    VFX_CCP_RET_NONE = 0,
    VFX_CCP_RET_OK,
    VFX_CCP_RET_MEMORY_NOT_ENOUGH,
    VFX_CCP_RET_MEMORY_ERROR,
    VFX_CCP_RET_NO_TEXT,
    VFX_CCP_RET_NO_TEXT_HIGHLIGH,
    VFX_CCP_RET_COPY_FAIL,
    VFX_CCP_RET_CUT_UNSUPPRT_CONTENT,
    VFX_CCP_RET_END
} VfxCcpRetType;

class VsrvClipboard;
class VfxClipboardMenu;
class VcpClipboardButton;

/*
 * DESCRIPTION
 *  Clipboard floating menu button class 
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VcpClipboardButton : public VfxControl
{
public:
    /*
     * Constructor / Destructor
     */
    VcpClipboardButton() { m_b_arrow = VFX_FALSE; }
public:
    /*
     * Methods
     */
    virtual void onInit();
    virtual void onDeinit();

    void onClipboardButtonBoundsChanged(VfxFrame *source, const VfxRect &oldBounds);

    void setArrow(VfxBool b_arrow, VfxBool isUp);

public:
    // button
    VcpButton *m_button;
#if defined(__COSMOS_MMI_PACKAGE__)
    VfxFontEffect *m_effect;
#endif

// Implement
private:
    void onBtnStateChanged(VfxObject *obj, VfxId id, VcpButtonStateEnum state);

private:
    VfxBool m_b_arrow;
    VfxBool m_isUp;
    VfxFrame *m_frameUpArrowDown, *m_frameUpArrowUp;      /* Arrow point to up */
    VfxFrame *m_frameDownArrowDown, *m_frameDownArrowUp;  /* Arrow point to down */
};


/*
 * DESCRIPTION
 *  Clipboard floating menu class 
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VfxClipboardMenu : public VfxControl
{
public:
    /*
     * Constructor / Destructor
     */
    VfxClipboardMenu() { }
public:
    /*
     * Methods
     */
    void onBtnClicked(VfxObject* obj, VfxId id);
    virtual void onInit();
    virtual void onDeinit();

    void create();
    VfxS32 createMenu(VfxS32 gap, VfxS32 fontSize = VCCP_FM_BTN_FONT_SIZE);
    void createButton(VfxS32 type, VfxS32 index, VfxS32 gap);
    void show();
    void hide();
    void move(VfxPoint p);

    VfxBool hitTest(const VfxPenEvent &event);

    void setArrowIsUp(VfxBool isUp) { m_arrowIsUp = isUp; }

public:
    /*
     * signal
     */
    VfxSignal1 <VfxCcpEventType> m_signalBtnEvent;

    VfxBool             m_menuStatus[VFX_CCP_BTN_TOTAL];
    VfxS32              m_count;
    
private:
    VcpClipboardButton *m_btn[VFX_CCP_BTN_TOTAL];
    VfxS32 m_arrowBtnIndex;
    VfxS32 m_arrowBtnOffset;
    VfxBool m_arrowIsUp;

};


/*
 * DESCRIPTION
 *  Clipboard service class 
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VsrvClipboard : public VfxObject
{
public:
    /*
     * Constructor / Destructor
     */

    VsrvClipboard(VfxFrame* client) { m_menuType = VFX_CCP_FLOATING_MENU; m_b_enable = VFX_TRUE; m_menu = NULL; m_client = client; }

public:
    /*
     * Methods
     */
    void showMenu(VfxCcpMenuType type, VfxPoint p1, VfxPoint p2);
    VfxBool hideMenu();
    void setMenu(VfxCcpMenuType type);
    void setFloatingMenu();
    VfxS32 getClipboardData(VfxWChar **string);
    VfxBool isEmpty();
    VfxCcpRetType setClipboardData(VfxWChar *string, VfxS32 len);
    VfxS32 copy();
    VfxS32 cut();
    VfxS32 paste();
    VfxS32 copyAll();
    VfxS32 cutAll();
    void enable();
    void disable();

    void onBtnEvent(VfxCcpEventType);

	VfxBool hitTest(const VfxPenEvent &event);

public:
    /*
     * signal
     */
    VfxSignal4 <VfxCcpEventType, VfxWChar**, VfxS32, VfxS32*> m_signalClipboardEvent;

private:
    void onPenEventProcessed(VfxPenEvent &event, VfxControl *control);

private:
    VfxBool m_b_enable;
    VfxClipboardMenu *m_menu;
    VfxCcpMenuType    m_menuType;
    VfxFrame* m_client;
};

#endif /* __VSRV_CLIPBOARD_H__ */


