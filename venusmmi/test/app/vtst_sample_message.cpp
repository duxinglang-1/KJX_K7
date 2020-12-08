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
 *  vtst_sample_message.cpp
 *
 * Project:
 * --------
 *  Venus Golden Sample : Message
 *
 * Description:
 * ------------
 *
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vtst_nonconst_menu.h"
#include "vcp_tabctrl_page.h"
#include "vtst_rt_main.h"
#include "mmi_rp_vtst_sample_def.h"

#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_frame.h"
#include "vfx_text_frame.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_image_src.h"
#include "vfx_font_desc.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_primitive_frame.h"
#include "vcp_list_menu.h"
#include "vfx_page.h"
#include "vfx_class_info.h"
#include "mmi_rp_srv_venus_component_tab_title_bar_def.h"
#include "vcp_state_image.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "vfx_main_scr.h"
#include "vfx_app.h"
#include "vfx_app_launcher.h"
#include "mmi_res_range_def.h"
#include "GlobalResDef.h"

/*****************************************************************************
 * Menu Test Implementation
 *****************************************************************************/

/*****************************************************************************
 * Class VcpMyMenu2
 *****************************************************************************/

static const VfxU32 MESSAGE_COUNT = 100;
static const VfxU32 MESSAGE_COUNT_INCREMENT = 10;
static const VfxU32 MESSAGE_TEXT_WIDTH = 240;
static const VfxU32 MESSAGE_TEXT_MIN_HEIGHT = 22;
static const VfxU32 MESSAGE_HORIZONTAL_TEXT_MARGIN = 10;
static const VfxU32 MESSAGE_VERTICAL_TEXT_MARGIN = 5;
static const VfxU32 MESSAGE_SIM_ICON_WIDTH = 18;
static const VfxU32 MESSAGE_SIM_ICON_MARGIN = 10;
static const VfxU32 MESSAGE_BOUND_WIDTH = MESSAGE_TEXT_WIDTH +
                        MESSAGE_HORIZONTAL_TEXT_MARGIN * 2 +
                        MESSAGE_SIM_ICON_WIDTH +
                        MESSAGE_SIM_ICON_MARGIN * 2;
static const VfxU32 MESSAGE_BOUND_BOTTOM_MARGIN_EXTRA = 10;
static const VfxU32 MESSAGE_BOUND_MIN_HEIGHT = 39;
static const VfxU32 MESSAGE_VERTICAL_BOUND_MARGIN = 5;
static const VfxU32 MESSAGE_HORIZONTAL_BOUND_MARGIN = 10;
static const VfxU32 MESSAGE_EXTRA_HEIGHT = 30;
static const VfxU32 MESSAGE_RELOAD_LAYOUT_MARGIN = 500;
static const VfxU32 MESSAGE_SAMPLE_COUNT = 10;

static const VfxWString & getDisplayStr(VfxU32 index)
{
    static const VfxWString strs[MESSAGE_SAMPLE_COUNT] =
    {
        VFX_WSTR("Andy, How about the vacation?"),
        VFX_WSTR("Just ok. May I have yoyo's ingotmantion"),
        VFX_WSTR("Her number is 13609900686, Email is firefox@coroflot.com, her website is www.coroflot.com/coffee"),
        VFX_WSTR("I am living at 201 Four Season Apartment, Welcome to my new home if you are free :)"),
        VFX_WSTR("The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog."),
        VFX_WSTR("The quick brown fox jumps over the lazy dog."),
        VFX_WSTR("The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog."),
        VFX_WSTR("The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog."),
        VFX_WSTR("The quick brown fox jumps over the lazy dog."),
        VFX_WSTR("The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.")
    };

    return strs[index % MESSAGE_SAMPLE_COUNT];
}

static const VfxWString & getDisplayDatetime(VfxU32 index)
{
    static const VfxWString strs[MESSAGE_SAMPLE_COUNT] =
    {
        VFX_WSTR("2010-04-02 10:05"),
        VFX_WSTR("2010-04-01 12:13"),
        VFX_WSTR("2010-04-02 10:05"),
        VFX_WSTR("2010-04-01 12:00"),
        VFX_WSTR("2010-04-02 12:00"),
        VFX_WSTR("2010-04-03 12:00"),
        VFX_WSTR("2010-04-04 12:00"),
        VFX_WSTR("2010-04-05 12:00"),
        VFX_WSTR("2010-04-06 12:00"),
        VFX_WSTR("2010-04-07 12:00"),
    };

    return strs[index % MESSAGE_SAMPLE_COUNT];
}

class VcpMyMenu2 : public VtstNonconstMenu
{
// Constructor / Destructor
public:
    VcpMyMenu2()
    {
        m_currentCellCount = MESSAGE_COUNT_INCREMENT;
    }

// Override
public:
    virtual VfxFrame* createCell(VfxS32 group, VfxS32 pos)
    {
        VfxId cellBoundImg = VTST_IMG_MESSAGE_CELL_SIM1;
        VfxId cellIconImg = VTST_IMG_SIM1;
        VfxTextFrame::AlignModeEnum align = VfxTextFrame::ALIGN_MODE_LEFT;
        if (pos % 2 == 1)
        {
            cellBoundImg = VTST_IMG_MESSAGE_CELL_SIM2;
            cellIconImg = VTST_IMG_SIM2;
        }
        align = VfxTextFrame::ALIGN_MODE_RIGHT;

        VfxFrame* cell;
        VFX_OBJ_CREATE(cell, VfxFrame, this);
        //cell->setBgColor(colorlst[pos % colorCnt]);

        // create the message bound
        VfxFrame* messageBound;
        VFX_OBJ_CREATE(messageBound, VfxFrame, cell);
        messageBound->setImgContent(VfxImageSrc(cellBoundImg));
        messageBound->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        messageBound->setPos(MESSAGE_HORIZONTAL_BOUND_MARGIN, MESSAGE_VERTICAL_BOUND_MARGIN);

        // create and layout the message text frame
        VfxTextFrame* text;
        VFX_OBJ_CREATE(text, VfxTextFrame, messageBound);
        VfxFontDesc font;
        font.size = VFX_FONT_DESC_VF_SIZE(16);
        text->setFont(font);
        text->setColor(VFX_COLOR_BLACK);
        text->setString(getDisplayStr(pos) );
        text->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
        text->setPos(MESSAGE_HORIZONTAL_TEXT_MARGIN, MESSAGE_VERTICAL_TEXT_MARGIN);
        text->setSize(MESSAGE_TEXT_WIDTH, 0);
        text->forceUpdate();

        // layout
        VfxU32 textHeight = text->getSize().height;
        textHeight = VFX_MAX(textHeight, MESSAGE_TEXT_MIN_HEIGHT);
        VfxU32 boundHeight = textHeight + MESSAGE_VERTICAL_TEXT_MARGIN * 2 + MESSAGE_BOUND_BOTTOM_MARGIN_EXTRA;
        boundHeight = VFX_MAX(boundHeight, MESSAGE_BOUND_MIN_HEIGHT);
        VfxU32 height = boundHeight + MESSAGE_VERTICAL_BOUND_MARGIN * 2 + MESSAGE_EXTRA_HEIGHT;

        // set the the message bound size
        messageBound->setSize(MESSAGE_BOUND_WIDTH, boundHeight);

        // create and layout the sim icon
        VfxImageFrame *simIcon;
        VFX_OBJ_CREATE(simIcon, VfxImageFrame, messageBound);
        simIcon->setResId(cellIconImg);
        simIcon->setAnchor(0.5f, 0.5f);
        simIcon->setPos(MESSAGE_BOUND_WIDTH - MESSAGE_SIM_ICON_WIDTH / 2 - MESSAGE_SIM_ICON_MARGIN, (boundHeight - MESSAGE_BOUND_BOTTOM_MARGIN_EXTRA) / 2);

        // create and layout the datetime text frame
        VfxTextFrame* datetimeText;
        VFX_OBJ_CREATE(datetimeText, VfxTextFrame, cell);
        datetimeText->setAutoResized(VFX_FALSE);
        datetimeText->setFont(font);
        datetimeText->setColor(VFX_COLOR_BLACK);
        datetimeText->setPos(MESSAGE_HORIZONTAL_BOUND_MARGIN, height - MESSAGE_EXTRA_HEIGHT);
        datetimeText->setAlignMode(align);
        datetimeText->setSize(MESSAGE_BOUND_WIDTH, MESSAGE_EXTRA_HEIGHT);
        datetimeText->setString(getDisplayDatetime(pos) );

        return cell;
    }

    virtual VfxU32 getNonconstCellCount()
    {
        return m_currentCellCount;
    }

    virtual VfxU32 getNonconstCellHeight(VfxU32 index)
    {
        VfxTextFrame* text;
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        VfxFontDesc font;
        font.size = VFX_FONT_DESC_VF_SIZE(16);
        text->setFont(font);
        text->setString(getDisplayStr(index) );
        text->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
        text->setSize(MESSAGE_TEXT_WIDTH, 0);
        text->forceUpdate();
        VfxU32 height = text->getSize().height;
        VFX_OBJ_CLOSE(text);
        height += MESSAGE_VERTICAL_TEXT_MARGIN * 2;
        height += MESSAGE_VERTICAL_BOUND_MARGIN * 2;
        height += MESSAGE_EXTRA_HEIGHT;
        height = VFX_MAX(height, MESSAGE_TEXT_MIN_HEIGHT);
        return height;
    }

    virtual void onNonconstViewChanged(VfxS32 y)
    {
        VfxU32 length = getLayoutContentSize().height;

        if (y + MESSAGE_RELOAD_LAYOUT_MARGIN > length && m_currentCellCount != MESSAGE_COUNT)
        {
            m_currentCellCount += MESSAGE_COUNT_INCREMENT;
            if (m_currentCellCount >= MESSAGE_COUNT)
            {
                m_currentCellCount = MESSAGE_COUNT;
            }
            updateLayout();
        }
    }

private:
    VfxU32 m_currentCellCount;
};

/*****************************************************************************
 * Class VtstMessageDialogPage declaration
 *****************************************************************************/

class VtstMessageDialogPage : public VfxPage, IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VtstMessageDialogPage);
public:
    VtstMessageDialogPage(): m_menu(NULL), m_name(NULL), m_titleBg(NULL) {}

// Override: for menu content provider
protected:
    virtual void onInit();
    virtual void setBounds(const VfxRect &value);

private:
    VcpMyMenu2 * m_menu;
    VfxTextFrame * m_name;
    VfxFrame * m_titleBg;
    VfxFrame * m_lineFrame;
};
/***************************************************************************** * Class VtstMessageDialogPage implementation *****************************************************************************/
VFX_IMPLEMENT_CLASS("VtstMessageDialogPage", VtstMessageDialogPage, VfxPage);

void VtstMessageDialogPage::onInit()
{
    VfxPage::onInit();

    VFX_OBJ_CREATE(m_menu, VcpMyMenu2, this);
    m_menu->setBgColor(VFX_COLOR_WHITE);

    VFX_OBJ_CREATE(m_titleBg, VfxFrame, this);
    m_titleBg->setBgColor(VFX_COLOR_WHITE);

    VFX_OBJ_CREATE(m_name, VfxTextFrame, this);
    m_name->setString(VFX_WSTR("Andy Sun") );
    m_name->setColor(VFX_COLOR_BLACK);
    m_name->setPos(5, 10);

    VFX_OBJ_CREATE(m_lineFrame, VfxFrame, this);
    m_lineFrame->setPos(0, 40);
    //m_lineFrame->setImgContent(VfxImageSrc(VTST_IMG_MESSAGE_LINE));
    //m_lineFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_lineFrame->setBgColor(VfxColor(255, 128, 128, 128) );
}

void VtstMessageDialogPage::setBounds(const VfxRect &value)
{
    VfxPage::setBounds(value);
    if (m_menu)
    {
        const VfxU32 margin = 40;
        m_menu->setSize(value.getWidth(), value.getHeight() - margin);
        m_menu->setPos(0, margin);

        m_titleBg->setSize(value.getWidth(), margin);
        //m_lineFrame->setSize(value.getWidth(), 4);
        m_lineFrame->setSize(value.getWidth(), 2);
    }
}

/*****************************************************************************
 * Class VtstMessageDialogTabPage implementation
 *****************************************************************************/

class VtstMessageDialogTabPage : public VcpTabCtrlPage
{
    VFX_DECLARE_CLASS(VtstMessageDialogTabPage);
protected:
    virtual void onInit()
    {
        VcpTabCtrlPage::onInit();
        addTab(1, VFX_WSTR("Profile"),   VcpStateImage(VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_CT));
        addTab(2, VFX_WSTR("Call log"), VcpStateImage(VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_CL));
        addTab(3, VFX_WSTR("Message"), VcpStateImage(VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_DL));
        //addTab(4, VFX_WSTR("SNS"), VcpStateImage(VCP_IMG_TOOL_BAR_TEST_5));
        setCurrTab(3);
    }

    virtual VfxPage *onCreateTabPage(VfxId tabId)
    {
        VfxPage *page = NULL;

        switch(tabId)
        {
        case 1:
        case 2:
            VFX_OBJ_CREATE(page, VfxPage, this);
            break;

        case 3:
            VFX_OBJ_CREATE(m_messagePage, VtstMessageDialogPage, this);
            page = m_messagePage;

            //m_messagePage->setPos(VfxPoint(10, 50));
            //m_messagePage->setBounds(VfxRect(0, 0, 300, 360));
            m_messagePage->setBgColor(VFX_COLOR_BLACK);
            break;

        default:
            break;
        }
        return page;
    }
private:
    VtstMessageDialogPage * m_messagePage;
};

VFX_IMPLEMENT_CLASS("VtstMessageDialogTabPage", VtstMessageDialogTabPage, VcpTabCtrlPage);


/*****************************************************************************
 * Class VtstMessageDialogScr declaration
 *****************************************************************************/

class VtstMessageDialogScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VtstMessageDialogScr);


// Override
protected:
    virtual void on1stReady();

private:
    VcpMyMenu2 *m_menu;
};

/*****************************************************************************
 * Class VtstNaviAppScr implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstMessageDialogScr", VtstMessageDialogScr, VfxMainScr);

void VtstMessageDialogScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VfxPage *page;
    VFX_OBJ_CREATE(page, VtstMessageDialogTabPage, this);
    pushPage(0, page);
}

/*****************************************************************************
 * Class VtstMessageDialogApp declaration
 *****************************************************************************/

class VtstMessageDialogApp : public VfxApp
{
    VFX_DECLARE_CLASS(VtstMessageDialogApp );

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
};

/*****************************************************************************
 * Class VtstMessageDialogApp implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstMessageDialogApp", VtstMessageDialogApp, VfxApp);

void VtstMessageDialogApp::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VtstMessageDialogScr *scr;
    VFX_OBJ_CREATE(scr, VtstMessageDialogScr, this);
    scr->show();
}

/*****************************************************************************
 * Global Function
 *****************************************************************************/

VtstTestResultEnum vtst_sample_message(VfxU32 param)
{
    VFX_UNUSED(param);
    VfxAppLauncher::launchWithAsmSize(
        APP1_BASE,
        VFX_OBJ_CLASS_INFO(VtstMessageDialogApp),
        GRP_ID_ROOT, 204800 * 1,
        NULL, 0);
   return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

