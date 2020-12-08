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
 *  vtst_rt_panel_bar.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  PanelBar demo file
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
 * Class VtstPanelBarApp declaration
 *****************************************************************************/
#ifdef __MMI_MAINLCD_480X800__
    #define PBAR_SCR_WIDTH           480
    #define PBAR_SCR_HEIGHT          800
    #define PBAR_SCR_BUTTON_HEIGHT   30  
#elif defined(__MMI_MAINLCD_320X480__)
    #define PBAR_SCR_WIDTH           320
    #define PBAR_SCR_HEIGHT          480
    #define PBAR_SCR_BUTTON_HEIGHT   30  
#elif defined(__MMI_MAINLCD_240X400__)
    #define PBAR_SCR_WIDTH           240
    #define PBAR_SCR_HEIGHT          400
    #define PBAR_SCR_BUTTON_HEIGHT   20  
#elif defined(__MMI_MAINLCD_240X320__)
    #define PBAR_SCR_WIDTH           240
    #define PBAR_SCR_HEIGHT          320
    #define PBAR_SCR_BUTTON_HEIGHT   20  
#else 
    #define PBAR_SCR_WIDTH           240
    #define PBAR_SCR_HEIGHT          320
    #define PBAR_SCR_BUTTON_HEIGHT   20  
#endif

class VtstPanelBarAppScr;

class VtstPanelBarApp : public VfxApp
{
    VFX_DECLARE_CLASS(VtstPanelBarApp);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
};


/***************************************************************************** 
 * Class VtstNaviAppScr declaration
 *****************************************************************************/

class VtstPanelBarAppScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VtstPanelBarAppScr);

// Override
protected:
    virtual void on1stReady();
};


/***************************************************************************** 
 * Class VtstPanelBarAppBasePage declaration
 *****************************************************************************/

class VtstPanelBarAppBasePage : public VfxPage
{
    VFX_DECLARE_CLASS(VtstPanelBarAppBasePage);
public:
    VtstPanelBarAppBasePage() {}

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
 * Class VtstPanelBarStartPage declaration
 *****************************************************************************/

class VtstPanelBarStartPage : public VtstPanelBarAppBasePage
{
    VFX_DECLARE_CLASS(VtstPanelBarStartPage);

    // Constructor / Destructor
public:
    VtstPanelBarStartPage() {}

    S32 pageID;
    //void initTitleBar();
    void initPanelBar(void);

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
            case VFX_SCR_ROTATE_TYPE_LANDSCAPE:
			case VFX_SCR_ROTATE_TYPE_180:
                break;
            default:
                break;
        }

         VtstPanelBarAppBasePage::onRotate(param);
    }
    
// Override
protected:
    virtual void onInit();

    virtual void onFunc(VfxId funcId);
    
    void onClick(VfxObject *obj, VfxId id);

// implementation
private:
    //VcpNaviTitleBar * m_titleBar;
    VcpPanelBar *m_panel_bar;
    VfxBool m_transparent;
    VfxTextFrame *m_text;
};


/***************************************************************************** 
 * Class VtstPanelBarApp implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstPanelBarApp", VtstPanelBarApp, VfxApp);

void VtstPanelBarApp::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VtstPanelBarAppScr *scr;
    VFX_OBJ_CREATE(scr, VtstPanelBarAppScr, this);
    scr->show();
}

/***************************************************************************** 
 * Class VtstPanelBarAppScr implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstPanelBarAppScr", VtstPanelBarAppScr, VfxMainScr);

void VtstPanelBarAppScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VtstPanelBarStartPage *page;
    VFX_OBJ_CREATE(page, VtstPanelBarStartPage, this);
    page->pageID = 0;
    //page->initTitleBar();
    page->initPanelBar();
    pushPage(VFX_ID_NULL, page);
}


/***************************************************************************** 
 * Class VtstPanelBarAppBasePage implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstPanelBarAppBasePage", VtstPanelBarAppBasePage, VfxPage);

void VtstPanelBarAppBasePage::onInit()
{
    VfxPage::onInit();    

    setBgColor(VFX_COLOR_AQUA);

    m_nextPos.x = PBAR_SCR_WIDTH/4;
    m_nextPos.y = 20;
}


void VtstPanelBarAppBasePage::addFunc(const VfxWString &str, VfxId id)
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
    button->m_signalClicked.connect(this, &VtstPanelBarAppBasePage::_onClicked);
    button->setSize(button->getSize().width, PBAR_SCR_BUTTON_HEIGHT);

    // move to next pos
    if(m_nextPos.x == PBAR_SCR_WIDTH/4)
    {
        m_nextPos.x = 3*(PBAR_SCR_WIDTH/4);
    }
    else
    {
        m_nextPos.x = PBAR_SCR_WIDTH/4;
        m_nextPos.y += PBAR_SCR_BUTTON_HEIGHT;
    }
}

void VtstPanelBarAppBasePage::_onClicked(VfxObject *obj, VfxId id)
{
    onFunc(id);
}


/***************************************************************************** 
 * Class VtstPanelBarStartPage implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstPanelBarStartPage", VtstPanelBarStartPage, VtstPanelBarAppBasePage);

void VtstPanelBarStartPage::onInit()
{
    VtstPanelBarAppBasePage::onInit();

    addFunc(VFX_WSTR("prev"), VtstPanelBarAppBasePage::FUNC_ID_PREV);
    addFunc(VFX_WSTR("next"), VtstPanelBarAppBasePage::FUNC_ID_NEXT);
    addFunc(VFX_WSTR("Change Height"), 252);
    addFunc(VFX_WSTR("Add button"), 253);
    addFunc(VFX_WSTR("Add image"), 254);
    addFunc(VFX_WSTR("Transparency Off"), 255);
    addFunc(VFX_WSTR("Transparency On"), 256);
    m_transparent = VFX_FALSE;

    VFX_OBJ_CREATE(m_text,VfxTextFrame,this);
    m_text->setPos(10, PBAR_SCR_HEIGHT/2);
    m_text->setSize(PBAR_SCR_WIDTH - 20, 50);
}

void VtstPanelBarStartPage::initPanelBar()
{
    VFX_OBJ_CREATE(m_panel_bar,VcpPanelBar,this);

    m_panel_bar->setHeight(50, 100);
    setBottomBar(m_panel_bar);
}


void VtstPanelBarStartPage::onClick(VfxObject *obj, VfxId id)
{
    m_text->setString(VFX_WSTR("Clicked"));
}


void VtstPanelBarStartPage:: onFunc(VfxId funcId)
{
	//VfxBool result;
    switch(funcId)
    {
        case VtstPanelBarAppBasePage::FUNC_ID_PREV:
            getMainScr()->popPage();
            break;
        case VtstPanelBarAppBasePage::FUNC_ID_NEXT:
            if (pageID >= 4)
                break;
            VtstPanelBarStartPage *page;
            VFX_OBJ_CREATE(page, VtstPanelBarStartPage, getMainScr());
            page->pageID = pageID + 1;
            page->initPanelBar();
            getMainScr()->pushPage(VFX_ID_NULL, page);
            break;
        case 252:
			{
                VfxU32 ph, lh;
                m_panel_bar->getHeight(ph,lh);
                ph = (ph == 100 ? 50 : 100);
				m_panel_bar->setHeight(ph);
				break;
			}
        case 253:
			{
                VcpButton *b;
                VFX_OBJ_CREATE(b,VcpButton,m_panel_bar);
                b->setPos(5,5);
                b->setSize(PBAR_SCR_WIDTH/4,PBAR_SCR_BUTTON_HEIGHT);
                b->setText(VFX_WSTR("Click me"));
                b->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
                b->m_signalClicked.connect(this, &VtstPanelBarStartPage::onClick);
                
				break;
			}
        case 254:
			{
                VfxFrame *img;
                VFX_OBJ_CREATE(img, VfxFrame, m_panel_bar);
                img->setPos(3*(PBAR_SCR_WIDTH/4), 10);
                img->setSize(50,50);
                img->setImgContent(VfxImageSrc(VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD));
				break;
			}
        case 255:
            {
                m_panel_bar->setTranslucent(VFX_FALSE);
                break;
            }
        case 256:
            {
                m_panel_bar->setTranslucent(VFX_TRUE);
                break;
            }
        default:
            break;
    }
}


VtstTestResultEnum vtst_rt_panel_bar(VfxU32 param)
{
    VFX_UNUSED(param);
    VfxAppLauncher::launchWithAsmSize( 
        APP1_BASE, 
        VFX_OBJ_CLASS_INFO(VtstPanelBarApp),
        GRP_ID_ROOT, 204800 * 1,
        NULL, 0);
   return VTST_TR_OK;
}


#endif // __AFX_RT_TEST__


