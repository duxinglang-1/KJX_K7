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
 *  vtst_rt_option_menu.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for VcpOptionMenu
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vtst_rt_main.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vcp_option_menu.h"
#include "vfx_string.h"
#include "vfx_datatype.h"
#include "vfx_signal.h"
#ifdef __PLUTO_MMI_PACKAGE__ 
#include "mmi_rp_app_mainmenu_def.h"
#endif
#include "vfx_text_frame.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_app_cat_scr.h"

#define MENU_ID_ADD_NEXT_ITEM       777
#define MENU_ID_DELETE_NEXT_ITEM    888

/***************************************************************************** 
 * Control Test Implementation
 *****************************************************************************/

class VtstRtOptionMenu : public VtstRtScr
{
// Variable
public:

// Constructor / Destructor
public:
    VtstRtOptionMenu() : m_isMenuClosed(VFX_FALSE)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        VFX_OBJ_CREATE(m_menu, VcpOptionMenu, this);
        m_menu->setTitle(VFX_WSTR("I AM A TITLE"));

        VcpOptionMenuItem *item;

        item = m_menu->createMenuItem(MENU_ID_ADD_NEXT_ITEM, VFX_WSTR("ADD ONE NEXT ITEM"));
        m_menu->insertItem(NULL, NULL, item);

        item = m_menu->createMenuItem(MENU_ID_DELETE_NEXT_ITEM, VFX_WSTR("DELETE NEXT ITEM"));
        m_menu->insertItem(NULL, NULL, item);
        
        item = m_menu->createCheckMenuItem(999, VFX_WSTR("CHECK TEST"), VFX_TRUE);
        m_menu->insertItem(NULL, NULL, item);

        item = m_menu->createRadioMenuItem(999, VFX_WSTR("RADIO TEST 1"), VFX_TRUE);
        m_menu->insertItem(NULL, NULL, item);

        item = m_menu->createRadioMenuItem(999, VFX_WSTR("RADIO TEST 2"), VFX_TRUE);
        m_menu->insertItem(NULL, NULL, item);

        item = m_menu->createMenuItem(123, VFX_WSTR("TEXT 1"));
        m_menu->insertItem(NULL, NULL, item);

        VcpOptionMenuItem *subItem;
        subItem = m_menu->createMenuItem(123, VFX_WSTR("SUB TEXT" ));
        m_menu->appendItem(item, subItem);
        subItem = m_menu->createRadioMenuItem(124, VFX_WSTR("RADIO TEST 3"), VFX_FALSE);
        m_menu->appendItem(item, subItem);
        subItem = m_menu->createCheckMenuItem(124, VFX_WSTR("CHECK TEST 5"), VFX_FALSE);
        m_menu->appendItem(item, subItem);
        
        // connect menu callback signal
        m_menu->m_signalMenuCallback.connect(this, &VtstRtOptionMenu::menuCallack);

        // load test menu resource
#ifdef __PLUTO_MMI_PACKAGE__ 
        m_menu->loadFromRes(MAIN_MENU_SETTINGS_MENUID);
#endif
        // do it
        m_menu->showMenu();

        // info text
        VFX_OBJ_CREATE(m_info, VfxTextFrame, this);
        m_info->setPos(VfxPoint(0, 30));
        m_info->setBgColor(VFX_COLOR_WHITE);
        m_info->setColor(VFX_COLOR_BLACK); 
    }

    virtual void onDeinit()
    {
        if (!m_isMenuClosed)
        {
            m_menu->closeMenu();
        }

        VtstRtScr::onDeinit();
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        VFX_UNUSED(idx);
        
        setTitle(VFX_WSTR("Option Menu Test"));
        confirm(VFX_WSTR("Result is correct?"));
        
        return -1;
    }

    virtual VfxS32 start() {return 1;}

private:

void VtstRtOptionMenu::menuCallack(VcpOptionMenu* menu, VcpOptionMenu::VcpOptionMenuEventEnum event, VcpOptionMenuItem* item)
{
    if (event == VcpOptionMenu::VCP_OPTION_MENU_EVENT_ITEM_SELECTED)
    {   // item selected
        if (item->getId() == MENU_ID_ADD_NEXT_ITEM)
        {
            menu->insertItem(NULL, item, menu->createMenuItem(0, VFX_WSTR("TEST")));
        }
        else if (item->getId() == MENU_ID_DELETE_NEXT_ITEM)
        {
            if (item->getNextFrame())
            {
                menu->closeItem((VcpOptionMenuItem*)item->getNextFrame());
            }
        }

        VfxWString str;
        str.format("SELECTED ITEM ID %d", item->getId());                
        m_info->setString(str);
    }        
    else if (event == VcpOptionMenu::VCP_OPTION_MENU_EVENT_MENU_CLOSE)
    {
        m_info->setString(VFX_WSTR("CLOSED"));
        m_isMenuClosed = VFX_TRUE;
    }
    
}

    VfxTextFrame    *m_info;
    VcpOptionMenu   *m_menu;
    VfxBool         m_isMenuClosed;
};


VtstTestResultEnum vtst_rt_option_menu(VfxU32 param)
{
    VFX_UNUSED(param);

    VTST_START_SCRN(VtstRtOptionMenu);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

