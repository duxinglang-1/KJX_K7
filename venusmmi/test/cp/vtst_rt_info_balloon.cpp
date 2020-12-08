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
 *  vtst_rt_info_balloon.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Info Balloon demo file
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
#include "vadp_mmi_frm.h"
#include "vfx_uc_include.h"
         
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
#include "vfx_sys_memory.h"
#include "vrt_datatype.h"
#include "vcp_button.h"
#include "vfx_font_desc.h"
#include "vfx_signal.h"
#include "vcp_info_balloon.h"
#include "GlobalResDef.h"
#include "vfx_app_launcher.h"
#include "mmi_res_range_def.h"
    
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Class VtstInfoBalloonApp declaration
 *****************************************************************************/

class VtstInfoBalloonAppScr;

class VtstInfoBalloonApp : public VfxApp
{
    VFX_DECLARE_CLASS(VtstInfoBalloonApp);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
};


/***************************************************************************** 
 * Class VtstNaviAppScr declaration
 *****************************************************************************/

class VtstInfoBalloonAppScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VtstInfoBalloonAppScr);

// Override
protected:
    virtual void on1stReady();
};

    
/***************************************************************************** 
 * Class VtstInfoBalloonAppBasePage declaration
 *****************************************************************************/

class VtstInfoBalloonAppBasePage : public VfxPage
{
    VFX_DECLARE_CLASS(VtstInfoBalloonAppBasePage);
public:
    VtstInfoBalloonAppBasePage() {}

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
 * Class VtstInfoBalloonStartPage declaration
 *****************************************************************************/

class VtstInfoBalloonStartPage : public VtstInfoBalloonAppBasePage
{
    VFX_DECLARE_CLASS(VtstInfoBalloonStartPage);

    // Constructor / Destructor
public:
    VtstInfoBalloonStartPage() {}

    S32 pageID;

// Override
protected:
    virtual void onInit();

    virtual void onFunc(VfxId funcId);

    virtual VfxBool onPenInput(VfxPenEvent & event);

// implementation
private:
    //VcpNaviTitleBar * m_titleBar;
    VfxU32 m_but_count;
    VfxBool m_transparent;
};
    
    
/***************************************************************************** 
 * Class VtstInfoBalloonApp implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstInfoBalloonApp", VtstInfoBalloonApp, VfxApp);

void VtstInfoBalloonApp::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VtstInfoBalloonAppScr *scr;
    VFX_OBJ_CREATE(scr, VtstInfoBalloonAppScr, this);
    scr->show();
}
    
/***************************************************************************** 
 * Class VtstInfoBalloonAppScr implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstInfoBalloonAppScr", VtstInfoBalloonAppScr, VfxMainScr);

void VtstInfoBalloonAppScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VtstInfoBalloonStartPage *page;
    VFX_OBJ_CREATE(page, VtstInfoBalloonStartPage, this);
    page->pageID = 0;
    //page->initTitleBar();
    pushPage(VFX_ID_NULL, page);
}


/***************************************************************************** 
 * Class VtstInfoBalloonAppBasePage implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstInfoBalloonAppBasePage", VtstInfoBalloonAppBasePage, VfxPage);

void VtstInfoBalloonAppBasePage::onInit()
{
    VfxPage::onInit();    

    setBgColor(VFX_COLOR_AQUA);

    m_nextPos.x = 70;
    m_nextPos.y = 100;
}

    
void VtstInfoBalloonAppBasePage::addFunc(const VfxWString &str, VfxId id)
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
    button->m_signalClicked.connect(this, &VtstInfoBalloonAppBasePage::_onClicked);

    // move to next pos
    if(m_nextPos.x == 70)
    {
        m_nextPos.x = 200;
    }
    else
    {
        m_nextPos.x = 70;
        m_nextPos.y += 40;
    }
}

void VtstInfoBalloonAppBasePage::_onClicked(VfxObject *obj, VfxId id)
{
    onFunc(id);
}

    
/***************************************************************************** 
 * Class VtstInfoBalloonStartPage implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstInfoBalloonStartPage", VtstInfoBalloonStartPage, VtstInfoBalloonAppBasePage);

void VtstInfoBalloonStartPage::onInit()
{
    VtstInfoBalloonAppBasePage::onInit();

    addFunc(VFX_WSTR("prev"), VtstInfoBalloonAppBasePage::FUNC_ID_PREV);
    addFunc(VFX_WSTR("next"), VtstInfoBalloonAppBasePage::FUNC_ID_NEXT);
    addFunc(VFX_WSTR("Failure balloon"), 250);
    addFunc(VFX_WSTR("Information balloon"), 251);
    addFunc(VFX_WSTR("Warning balloon"), 252);
    addFunc(VFX_WSTR("Success balloon"), 253);
    addFunc(VFX_WSTR("Progress balloon"), 254);
    addFunc(VFX_WSTR("Custom"), 255);
    m_transparent = VFX_FALSE;
}


VfxBool VtstInfoBalloonStartPage::onPenInput(VfxPenEvent & event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
	    balloon->addItem(VCP_INFO_BALLOON_TYPE_INFO, VFX_WSTR("This is an apple."), event.downPos);
		return VFX_TRUE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
	    balloon->moveCurrentUpperItem(event.pos);
		return VFX_TRUE;
    }

    return VtstInfoBalloonAppBasePage::onPenInput(event);
}


void VtstInfoBalloonStartPage::onFunc(VfxId funcId)
{
    //VfxBool result;
    switch(funcId)
    {
        case VtstInfoBalloonAppBasePage::FUNC_ID_PREV:
            getMainScr()->popPage();
            break;
        case VtstInfoBalloonAppBasePage::FUNC_ID_NEXT:
            if (pageID >= 4)
                break;
            VtstInfoBalloonStartPage *page;
            VFX_OBJ_CREATE(page, VtstInfoBalloonStartPage, getMainScr());
            page->pageID = pageID + 1;
            getMainScr()->pushPage(VFX_ID_NULL, page);
            break;
        case 250:
			{
				VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
				balloon->addItem(VCP_INFO_BALLOON_TYPE_FAILURE, VFX_WSTR("Failed balloon!"));
				break;
			}
        case 251:
			{
				VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
                balloon->cancelCurrentBottomItem();
				//balloon->addItem(VCP_INFO_BALLOON_TYPE_INFO, VFX_WSTR("Information balloon!"));
				break;
			}
        case 252:
			{
				VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
                balloon->cancelCurrentUpperItem();
				//balloon->addItem(VCP_INFO_BALLOON_TYPE_WARNING, VFX_WSTR("Warning balloon!"));
				break;
			}
        case 253:
			{
				VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
				balloon->addItem(VCP_INFO_BALLOON_TYPE_SUCCESS, VFX_WSTR("This is an apple. An apple a day keeps the doctor away! may be you eat an apple, You will like it"));
				break;
			}
        case 254:
			{
				VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
				//balloon->addItem(VCP_INFO_BALLOON_TYPE_PROGRESS, VFX_WSTR("XXX"), 100);
				break;
			}
        case 255:
			{
				VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
				balloon->addItem(IMG_GLOBAL_ERROR, VFX_WSTR("Custom icon image!"), VfxPoint(0,0));
				break;
			}
        default:
            break;
    }
}


VtstTestResultEnum vtst_rt_info_balloon(VfxU32 param)
{
    VFX_UNUSED(param);
    VfxAppLauncher::launchWithAsmSize( 
        APP1_BASE, 
        VFX_OBJ_CLASS_INFO(VtstInfoBalloonApp),
        GRP_ID_ROOT, 204800 * 1,
        NULL, 0);
   return VTST_TR_OK;
}
    
    
#endif // __AFX_RT_TEST__

    
