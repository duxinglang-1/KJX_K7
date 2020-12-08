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
 *  vtst_rt_tool_bar.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Toolbar demo file
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
#if defined(__AFX_RT_TEST__)
     
#include "vtst_rt_main.h"
#include "vcp_include.h"
#include "vfx_mc_include.h"
#include "vfx_app.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_main_scr.h"
#include "vfx_page.h"
#include "vfx_string.h"
#include "vfx_basic_type.h"
#include "MMIDataType.h"
#include "vfx_cpp_base.h"
#include "vcp_tool_bar.h"
#include "vfx_sys_memory.h"
#include "vrt_datatype.h"
#include "vcp_button.h"
#include "vfx_font_desc.h"
#include "vfx_signal.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "vfx_frame.h"
#include "vfx_text_frame.h"
#include "vcp_segment_button.h"
#include "GlobalResDef.h"
#include "vcp_state_image.h"
#include "vfx_app_launcher.h"
#include "mmi_res_range_def.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Class VtstToolBarApp declaration
 *****************************************************************************/
#ifdef __MMI_MAINLCD_480X800__
    #define TBAR_SCR_WIDTH           480
    #define TBAR_SCR_HEIGHT          800
    #define TBAR_SCR_BUTTON_HEIGHT   30  
#elif defined(__MMI_MAINLCD_320X480__)
    #define TBAR_SCR_WIDTH           320
    #define TBAR_SCR_HEIGHT          480
    #define TBAR_SCR_BUTTON_HEIGHT   30  
#elif defined(__MMI_MAINLCD_240X400__)
    #define TBAR_SCR_WIDTH           240
    #define TBAR_SCR_HEIGHT          400
    #define TBAR_SCR_BUTTON_HEIGHT   20  
#elif defined(__MMI_MAINLCD_240X320__)
    #define TBAR_SCR_WIDTH           240
    #define TBAR_SCR_HEIGHT          320
    #define TBAR_SCR_BUTTON_HEIGHT   20  
#else 
    #define TBAR_SCR_WIDTH           240
    #define TBAR_SCR_HEIGHT          320
    #define TBAR_SCR_BUTTON_HEIGHT   20  
#endif

class VtstToolBarAppScr;

class VtstToolBarApp : public VfxApp
{
    VFX_DECLARE_CLASS(VtstToolBarApp);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
};


/***************************************************************************** 
 * Class VtstNaviAppScr declaration
 *****************************************************************************/

class VtstToolBarAppScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VtstToolBarAppScr);

// Override
protected:
    virtual void on1stReady();
};


/***************************************************************************** 
 * Class VtstToolBarAppBasePage declaration
 *****************************************************************************/

class VtstToolBarAppBasePage : public VfxPage
{
    VFX_DECLARE_CLASS(VtstToolBarAppBasePage);
public:
    VtstToolBarAppBasePage() {}

    void addFunc(const VfxWString &str, VfxId id);

protected:
    virtual void onInit();
    virtual void onFunc(VfxId funcId) {}

    enum {
        FUNC_ID_PREV = 1,
        FUNC_ID_NEXT,
        FUNC_ID_END_OF_ENUM
    };
    void _onClicked(VfxObject *obj, VfxId id);
        
private:
    VfxPoint        m_nextPos;
};



/***************************************************************************** 
 * Class VtstToolBarStartPage declaration
 *****************************************************************************/

class VtstToolBarStartPage : public VtstToolBarAppBasePage
{
    VFX_DECLARE_CLASS(VtstToolBarStartPage);

    // Constructor / Destructor
public:
    VtstToolBarStartPage() 
    {
        isEnable = VFX_TRUE;
        isTranslucent = VFX_FALSE;
    }

    S32 pageID;
    VfxBool isEnable;
    VfxBool isTranslucent;
    //void initTitleBar();
    void initToolBar(void);
	void onToolBarClick(VfxObject* sender, VfxId id);
    void onFolding(VfxObject* sender, VfxBool is_fold);
public:
    void onBoundsChanged(VfxFrame *frame, const VfxRect &old)
    {
        m_sb->setSize(m_seg_frame->getSize());
    }

    void onQueryRotateEx(const VfxScreenRotateParam &param)
    {
    }

    void onRotate(const VfxScreenRotateParam &param)
    {
        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        switch(param.rotateTo)
        {  
            case VFX_SCR_ROTATE_TYPE_NORMAL:                
            case VFX_SCR_ROTATE_TYPE_90:                
            case VFX_SCR_ROTATE_TYPE_180:                
            case VFX_SCR_ROTATE_TYPE_LANDSCAPE:
                //m_tool_bar->setLayout(param.rotateTo);
                break;
            default:
                break;
        }

         VtstToolBarAppBasePage::onRotate(param);
    }

    
// Override
protected:
    virtual void onInit();

    virtual void onFunc(VfxId funcId);


// implementation
public:
    //VcpNaviTitleBar * m_titleBar;
    VcpToolBar *m_tool_bar;
    VfxFrame *m_seg_frame;
    VcpSegmentButton *m_sb;
    VfxU32 m_but_count;
    VfxBool m_transparent;
};


/***************************************************************************** 
 * Class VtstToolBarApp implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstToolBarApp", VtstToolBarApp, VfxApp);

void VtstToolBarApp::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VtstToolBarAppScr *scr;
    VFX_OBJ_CREATE(scr, VtstToolBarAppScr, this);
    scr->show();
}

/***************************************************************************** 
 * Class VtstToolBarAppScr implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstToolBarAppScr", VtstToolBarAppScr, VfxMainScr);

void VtstToolBarAppScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VtstToolBarStartPage *page;
    VFX_OBJ_CREATE(page, VtstToolBarStartPage, this);
    page->pageID = 0;
    //page->initTitleBar();
    page->initToolBar();
    pushPage(VFX_ID_NULL, page);
}


/***************************************************************************** 
 * Class VtstToolBarAppBasePage implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstToolBarAppBasePage", VtstToolBarAppBasePage, VfxPage);

void VtstToolBarAppBasePage::onInit()
{
    VfxPage::onInit();    

    setBgColor(VFX_COLOR_AQUA);

    m_nextPos.x = TBAR_SCR_WIDTH/4;
    m_nextPos.y = 100;
}


void VtstToolBarAppBasePage::addFunc(const VfxWString &str, VfxId id)
{
    VcpButton *button;
    VFX_OBJ_CREATE(button, VcpButton, this);
    button->setAnchor(0.5f, 0.5f);
    button->setPos(m_nextPos);

    VfxFontDesc font;
    font.size = VFX_FONT_DESC_SIZE_SMALL;
    button->setTextFont(font);
    
    button->setText(str);
    button->setIsAutoResized(VFX_TRUE);
    button->setId(id);
    button->m_signalClicked.connect(this, &VtstToolBarAppBasePage::_onClicked);
    button->setSize(button->getSize().width, TBAR_SCR_BUTTON_HEIGHT);

    // move to next pos
    if(m_nextPos.x == TBAR_SCR_WIDTH/4)
    {
        m_nextPos.x = 3*(TBAR_SCR_WIDTH/4);
    }
    else
    {
        m_nextPos.x = TBAR_SCR_WIDTH/4;
        m_nextPos.y += TBAR_SCR_BUTTON_HEIGHT;
    }
}

void VtstToolBarAppBasePage::_onClicked(VfxObject *obj, VfxId id)
{
    onFunc(id);
}


/***************************************************************************** 
 * Class VtstToolBarStartPage implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstToolBarStartPage", VtstToolBarStartPage, VtstToolBarAppBasePage);

void VtstToolBarStartPage::onInit()
{
    VtstToolBarAppBasePage::onInit();

    addFunc(VFX_WSTR("prev"), VtstToolBarAppBasePage::FUNC_ID_PREV);
    addFunc(VFX_WSTR("next"), VtstToolBarAppBasePage::FUNC_ID_NEXT);
    addFunc(VFX_WSTR("Add button"), 250);
    addFunc(VFX_WSTR("Add before 2"), 251);
    addFunc(VFX_WSTR("Remove button"), 252);
    addFunc(VFX_WSTR("Add Seg x 2"), 253);
    addFunc(VFX_WSTR("Add Seg x 3"), 254);
    addFunc(VFX_WSTR("Remove Seg"), 255);
    addFunc(VFX_WSTR("Enable/Disable 3"), 256);
    addFunc(VFX_WSTR("Switch mode"), 257);
    addFunc(VFX_WSTR("Translucency"), 258);
    m_transparent = VFX_FALSE;
}

void VtstToolBarStartPage::initToolBar()
{
    VFX_OBJ_CREATE(m_tool_bar,VcpToolBar,this);

	m_tool_bar->m_signalButtonTap.connect(this, &VtstToolBarStartPage::onToolBarClick);
	m_tool_bar->m_signalBarFolded.connect(this, &VtstToolBarStartPage::onFolding);
    setBottomBar(m_tool_bar);

	//m_tool_bar->addItem('TBB1', VFX_WSTR("Click me"), VCP_IMG_TOOL_BAR_TEST_1);
    VfxWString tempString;
	tempString.loadFromRes(VCP_STR_TOOL_BAR_SETTINGS);
    m_tool_bar->addItem('TBB1', tempString, VCP_IMG_TOOL_BAR_COMMON_ITEM_SORT);
    tempString.loadFromRes(VCP_STR_TOOL_BAR_SORT);
    m_tool_bar->changeItem('TBB1', tempString, VCP_IMG_TOOL_BAR_COMMON_ITEM_SORT);
	m_but_count = 1;
}


void VtstToolBarStartPage::onFolding(VfxObject* sender, VfxBool is_fold)
{
	VfxFrame *f;
	VFX_OBJ_CREATE(f,VfxFrame,this);
	f->setPos(0, 50);
	f->setBounds(0, 0, TBAR_SCR_WIDTH, TBAR_SCR_BUTTON_HEIGHT);
	f->setBgColor(VFX_COLOR_YELLOW);

	VfxWString str(VFX_WSTR("Status : "));
    str += is_fold ? VFX_WSTR("Folded") : VFX_WSTR("Unfolded");

	VfxTextFrame *t;
	VFX_OBJ_CREATE(t,VfxTextFrame,this);
	t->setPos(10, 50);
	t->setString(str);
	t->setBgColor(VFX_COLOR_YELLOW);
	t->setColor(VFX_COLOR_BLUE);
	t->setBorderColor(VFX_COLOR_GREEN);
}


void VtstToolBarStartPage::onToolBarClick(VfxObject* sender, VfxId id)
{
	VfxFrame *f;
	VFX_OBJ_CREATE(f,VfxFrame,this);
	f->setPos(0, 10);
	f->setBounds(0, 0, TBAR_SCR_WIDTH, TBAR_SCR_BUTTON_HEIGHT);
	f->setBgColor(VFX_COLOR_YELLOW);

	VfxWString str(VFX_WSTR("Info : "));
	switch(id)
	{
	case 'TBB1':
			str+=VFX_WSTR("TBB1");
			break;
	case 'TBB2':
			str+=VFX_WSTR("TBB2");
			break;
	case 'TBB3':
			str+=VFX_WSTR("TBB3");
			break;
	case 'TBB4':
			str+=VFX_WSTR("TBB4");
			break;
	case 'TBB5':
			str+=VFX_WSTR("TBB5");
			break;
	case 'TBB6':
			str+=VFX_WSTR("TBB6");
			break;
	case 'TBB7':
			str+=VFX_WSTR("TBB7");
			break;
		default :
			str+=VFX_WSTR("NONE");
	}


	VfxTextFrame *t;
	VFX_OBJ_CREATE(t,VfxTextFrame,this);
	t->setPos(10, 10);
	t->setString(str);
	t->setBgColor(VFX_COLOR_YELLOW);
	t->setColor(VFX_COLOR_BLUE);
	t->setBorderColor(VFX_COLOR_GREEN);
}


void VtstToolBarStartPage:: onFunc(VfxId funcId)
{
	VfxBool result;
    switch(funcId)
    {
        case VtstToolBarAppBasePage::FUNC_ID_PREV:
            getMainScr()->popPage();
            break;
        case VtstToolBarAppBasePage::FUNC_ID_NEXT:
            if (pageID >= 4)
                break;
            VtstToolBarStartPage *page;
            VFX_OBJ_CREATE(page, VtstToolBarStartPage, getMainScr());
            page->pageID = pageID + 1;
            //page->initTitleBar();
            page->initToolBar();
            getMainScr()->pushPage(VFX_ID_NULL, page);
            break;
        case 250:
            {
                result = m_tool_bar->addItem('TBB1' + m_but_count, 
                                VFX_WSTR("Click"),
                                (VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD + m_but_count));

                if(result)
                    m_but_count++;
                break;
            }
        case 251:
            {
                result = m_tool_bar->addItem('TBB1' + m_but_count, 
                                VFX_WSTR("Click"),
                                (VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD + m_but_count), 'TBB2');

                if(result)
                    m_but_count++;
                break;
            }
        case 252:
			if(m_but_count > 1)
			{
	            result = m_tool_bar->removeItem('TBB0' + m_but_count);
	            if(result)
	                m_but_count--;
			}
            break;
        case 253:
            {
                m_seg_frame = m_tool_bar->addControlFrame(VCP_TOOL_BAR_SEGMENT_BUTTON_COUNT_TWO);
			
                if(m_seg_frame)
                {            
                    m_seg_frame->m_signalBoundsChanged.connect(this, &VtstToolBarStartPage::onBoundsChanged);
                    VfxTextFrame *tf;
                    VFX_OBJ_CREATE(tf,VfxTextFrame,m_seg_frame);
                    tf->setString(VFX_WSTR("2 Segment button Space"));

                    VFX_OBJ_CREATE(m_sb,VcpSegmentButton,m_seg_frame);
                    m_sb->setPos(0,0);
                    m_sb->setSize(m_seg_frame->getSize());
                    m_sb->addButton('ZZZ1', VcpStateImage(IMG_GLOBAL_L1), VFX_WSTR("item 1"));
                    m_sb->addButton('ZZZ2', VcpStateImage(IMG_GLOBAL_L2), VFX_WSTR("item 2"));
                }
				
                break;
            }
        case 254:
            {
                m_seg_frame = m_tool_bar->addControlFrame(VCP_TOOL_BAR_SEGMENT_BUTTON_COUNT_THREE);
				
                if(m_seg_frame)
                {            
                    m_seg_frame->m_signalBoundsChanged.connect(this, &VtstToolBarStartPage::onBoundsChanged);
                    VfxTextFrame *tf;
                    VFX_OBJ_CREATE(tf,VfxTextFrame,m_seg_frame);
                    tf->setPos(0,0);
                    tf->setSize(50,50);
                    tf->setString(VFX_WSTR("3x3"));

                    VFX_OBJ_CREATE(m_sb,VcpSegmentButton,m_seg_frame);
                    m_sb->setPos(0,0);
                    m_sb->setSize(m_seg_frame->getSize());
                    m_sb->addButton('ZZZ1', VcpStateImage(IMG_GLOBAL_L1), VFX_WSTR("item 1"));
                    m_sb->addButton('ZZZ2', VcpStateImage(IMG_GLOBAL_L2), VFX_WSTR("item 2"));
                    m_sb->addButton('ZZZ3', VcpStateImage(IMG_GLOBAL_L3), VFX_WSTR("item 3"));
                }
				break;
            }
        case 255:
                    result = m_tool_bar->removeControlFrame();
                    m_seg_frame = 0; 
                    m_sb = 0;
                    break;
        case 256:
            {
                isEnable = isEnable ? VFX_FALSE : VFX_TRUE;
                result = m_tool_bar->setDisableItem('TBB3', isEnable);
            }
            break;
        case 257:
            m_tool_bar->switchFoldMode();
            break;
        case 258:
            {
                isTranslucent = isTranslucent ? VFX_FALSE : VFX_TRUE;
                m_tool_bar->setTranslucent(isTranslucent);
            }
            break;
        default:
            break;
    }
}


VtstTestResultEnum vtst_rt_tool_bar(VfxU32 param)
{
    VFX_UNUSED(param);
    VfxAppLauncher::launchWithAsmSize( 
        APP1_BASE, 
        VFX_OBJ_CLASS_INFO(VtstToolBarApp),
        GRP_ID_ROOT, 204800 * 1,
        NULL, 0);
   return VTST_TR_OK;
}


#endif // __AFX_RT_TEST__


