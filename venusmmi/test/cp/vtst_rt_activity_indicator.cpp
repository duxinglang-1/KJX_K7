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
 *  vtst_rt_activity_indicator.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Activity Indicator demo file
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
#include "vfx_timer.h"
#include "vfx_cpp_base.h"
#include "vfx_input_event.h"
#include "vcp_popup.h"
#include "vfx_page.h"
#include "vfx_string.h"
#include "vfx_basic_type.h"
#include "MMIDataType.h"
#include "vcp_activity_indicator.h"
#include "vfx_sys_memory.h"
#include "vrt_datatype.h"
#include "vcp_button.h"
#include "vfx_font_desc.h"
#include "vfx_signal.h"
#include "vfx_frame.h"
#include "vfx_text_frame.h"
#include "vfx_app_launcher.h"
#include "mmi_res_range_def.h"
#include "GlobalResDef.h"
    
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Class VtstActivityIndicatorApp declaration
 *****************************************************************************/
#ifdef __MMI_MAINLCD_480X800__
    #define ACT_IND_SCR_WIDTH           480
    #define ACT_IND_SCR_HEIGHT          800
    #define ACT_IND_SCR_BUTTON_HEIGHT   30 
    #define ACT_IND_WIDTH               70
    #define ACT_IND_HEIGHT              70
#elif defined(__MMI_MAINLCD_320X480__)
    #define ACT_IND_SCR_WIDTH           320
    #define ACT_IND_SCR_HEIGHT          480
    #define ACT_IND_SCR_BUTTON_HEIGHT   30  
    #define ACT_IND_WIDTH               70
    #define ACT_IND_HEIGHT              70
#elif defined(__MMI_MAINLCD_240X400__)
    #define ACT_IND_SCR_WIDTH           240
    #define ACT_IND_SCR_HEIGHT          400
    #define ACT_IND_SCR_BUTTON_HEIGHT   20  
    #define ACT_IND_WIDTH               70
    #define ACT_IND_HEIGHT              70
#elif defined(__MMI_MAINLCD_240X320__)
    #define ACT_IND_SCR_WIDTH           240
    #define ACT_IND_SCR_HEIGHT          320
    #define ACT_IND_SCR_BUTTON_HEIGHT   20  
    #define ACT_IND_WIDTH               70
    #define ACT_IND_HEIGHT              70
#else 
    #define ACT_IND_SCR_WIDTH           240
    #define ACT_IND_SCR_HEIGHT          320
    #define ACT_IND_SCR_BUTTON_HEIGHT   20  
    #define ACT_IND_WIDTH               70
    #define ACT_IND_HEIGHT              70
#endif


class VtstActivityIndicatorAppScr;

class VtstActivityIndicatorApp : public VfxApp
{
    VFX_DECLARE_CLASS(VtstActivityIndicatorApp);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
};


/***************************************************************************** 
 * Class VtstNaviAppScr declaration
 *****************************************************************************/

class VtstActivityIndicatorAppScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VtstActivityIndicatorAppScr);
public:
    VtstActivityIndicatorAppScr():
        m_popup(NULL)
    {
    }

    void onTimerCallBack(VfxTimer *timer);
    void onCanceled(VfxObject* obj, VfxFloat curr_progress);
// Override
protected:
    virtual void on1stReady();
public:
    VcpIndicatorPopup *m_popup;
    static VfxU32 s_state;
    VfxTimer *m_timer;
};

VfxU32 VtstActivityIndicatorAppScr::s_state = 0;

    
/***************************************************************************** 
 * Class VtstActivityIndicatorAppBasePage declaration
 *****************************************************************************/

class VtstActivityIndicatorAppBasePage : public VfxPage
{
    VFX_DECLARE_CLASS(VtstActivityIndicatorAppBasePage);
public:
    VtstActivityIndicatorAppBasePage() {}

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
 * Class VtstActivityIndicatorStartPage declaration
 *****************************************************************************/

class VtstActivityIndicatorStartPage : public VtstActivityIndicatorAppBasePage
{
    VFX_DECLARE_CLASS(VtstActivityIndicatorStartPage);

    // Constructor / Destructor
public:
    VtstActivityIndicatorStartPage() {}

    S32 pageID;

	void onQueryRotateEx(const VfxScreenRotateParam &param)
	{
	}

	virtual void onRotate(const VfxScreenRotateParam &param)
	{
	    vrt_size_struct main_screen_size;
	    vrt_color_type_enum main_screen_color_format;
	    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

		VtstActivityIndicatorAppScr *parent = (VtstActivityIndicatorAppScr *)getParentFrame();
        if(parent->m_popup)
        {
            //parent->m_popup->onRotate(param);
        }
	    VtstActivityIndicatorAppBasePage::onRotate(param);
	}


// Override
protected:
    virtual void onInit();
    virtual void onFunc(VfxId funcId);

// implementation
private:
    //VcpNaviTitleBar * m_titleBar;
    VfxU32 m_but_count;
    VfxBool m_transparent;
	VcpActivityIndicator *m_waitingInd;
	VfxTimer *m_timer;
	//VcpIndicatorPopup *m_popup;
};
    
    
/***************************************************************************** 
 * Class VtstActivityIndicatorApp implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstActivityIndicatorApp", VtstActivityIndicatorApp, VfxApp);

void VtstActivityIndicatorApp::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VtstActivityIndicatorAppScr *scr;
    VFX_OBJ_CREATE(scr, VtstActivityIndicatorAppScr, this);
    scr->show();
}
    
/***************************************************************************** 
 * Class VtstActivityIndicatorAppScr implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstActivityIndicatorAppScr", VtstActivityIndicatorAppScr, VfxMainScr);

void VtstActivityIndicatorAppScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VtstActivityIndicatorStartPage *page;
    VFX_OBJ_CREATE(page, VtstActivityIndicatorStartPage, this);
    page->pageID = 0;
    pushPage(VFX_ID_NULL, page);
}


/***************************************************************************** 
 * Class VtstActivityIndicatorAppBasePage implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstActivityIndicatorAppBasePage", VtstActivityIndicatorAppBasePage, VfxPage);

void VtstActivityIndicatorAppBasePage::onInit()
{
    VfxPage::onInit();    

    setBgColor(VFX_COLOR_WHITE);

    m_nextPos.x = ACT_IND_SCR_WIDTH/4;
    m_nextPos.y = 20;
}

    
void VtstActivityIndicatorAppBasePage::addFunc(const VfxWString &str, VfxId id)
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
    button->m_signalClicked.connect(this, &VtstActivityIndicatorAppBasePage::_onClicked);
    button->setSize(button->getSize().width, ACT_IND_SCR_BUTTON_HEIGHT);

    // move to next pos
    if(m_nextPos.x == ACT_IND_SCR_WIDTH/4)
    {
        m_nextPos.x = 3*(ACT_IND_SCR_WIDTH/4);
    }
    else
    {
        m_nextPos.x = ACT_IND_SCR_WIDTH/4;
        m_nextPos.y += ACT_IND_SCR_BUTTON_HEIGHT;
    }
}

void VtstActivityIndicatorAppBasePage::_onClicked(VfxObject *obj, VfxId id)
{
    onFunc(id);
}

    
/***************************************************************************** 
 * Class VtstActivityIndicatorStartPage implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstActivityIndicatorStartPage", VtstActivityIndicatorStartPage, VtstActivityIndicatorAppBasePage);

void VtstActivityIndicatorStartPage::onInit()
{
    VtstActivityIndicatorAppBasePage::onInit();

	VFX_OBJ_CREATE(m_waitingInd, VcpActivityIndicator, this);

    addFunc(VFX_WSTR("prev"), VtstActivityIndicatorAppBasePage::FUNC_ID_PREV);
    addFunc(VFX_WSTR("next"), VtstActivityIndicatorAppBasePage::FUNC_ID_NEXT);
    addFunc(VFX_WSTR("Activity Indicator"), 250);
    addFunc(VFX_WSTR("Activity popup"), 258);
    addFunc(VFX_WSTR("Activity btn popup"), 260);
    m_transparent = VFX_FALSE;
}


void VtstActivityIndicatorStartPage:: onFunc(VfxId funcId)
{
    switch(funcId)
    {
        case VtstActivityIndicatorAppBasePage::FUNC_ID_PREV:
            getMainScr()->popPage();
            break;
        case VtstActivityIndicatorAppBasePage::FUNC_ID_NEXT:
            if (pageID >= 4)
                break;
            VtstActivityIndicatorStartPage *page;
            VFX_OBJ_CREATE(page, VtstActivityIndicatorStartPage, getMainScr());
            page->pageID = pageID + 1;
            getMainScr()->pushPage(VFX_ID_NULL, page);
            break;
        case 250:
			{
				static VfxBool curstate = VFX_FALSE;
                if(m_waitingInd)
                {
					if(curstate)
                {
						m_waitingInd->stop();						
					}
					else
					{
						m_waitingInd->setPos((ACT_IND_SCR_WIDTH - ACT_IND_WIDTH)/2, (ACT_IND_SCR_HEIGHT - ACT_IND_WIDTH)/2);
						m_waitingInd->setSize(ACT_IND_WIDTH, ACT_IND_HEIGHT);
						m_waitingInd->start();
					}
					curstate = !curstate;
                }
				break;
			}
        case 258:
            {
				VtstActivityIndicatorAppScr *parent = (VtstActivityIndicatorAppScr *)getParentFrame();
                if(!parent->m_popup)
                {
                    VFX_OBJ_CREATE(parent->m_popup,VcpIndicatorPopup,this);
                }
                parent->m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
                parent->m_popup->setText(VFX_WSTR("A quick brown fox jumps over the lazy dog. A quick brown fox jumps over the lazy dog. A quick brown fox jumps over the lazy dog."));
                parent->m_popup->setAutoDestory(VFX_FALSE);
                parent->m_popup->show(VFX_TRUE);

                VFX_OBJ_CREATE(parent->m_timer, VfxTimer, this);
                parent->m_timer->setStartDelay(5000);
                parent->m_timer->m_signalTick.connect(parent, &VtstActivityIndicatorAppScr::onTimerCallBack);
                parent->m_timer->start();
                parent->s_state = 2;
            }
            break;
        case 260:
            {
				VtstActivityIndicatorAppScr *parent = (VtstActivityIndicatorAppScr *)getParentFrame();
                if(!parent->m_popup)
                {
                    VFX_OBJ_CREATE(parent->m_popup,VcpIndicatorPopup,this);
                }
                parent->m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
                parent->m_popup->setText(VFX_WSTR("A quick brown fox jumps over the lazy dog. A quick brown fox jumps over the lazy dog. A quick brown fox jumps over the lazy dog."));
                parent->m_popup->setAutoDestory(VFX_FALSE);
                parent->m_popup->show(VFX_TRUE);
                parent->s_state = 2;
            }
            break;
        default:
            break;
    }
}


void VtstActivityIndicatorAppScr::onCanceled(VfxObject* obj, VfxFloat curr_progress)
{
    s_state = 0;
    m_timer->stop();
    m_popup->hide(VFX_TRUE);
    VFX_OBJ_CLOSE(m_popup);
}


void VtstActivityIndicatorAppScr::onTimerCallBack(VfxTimer *timer)
{
    switch(s_state)
    {
        // Activity Indicator
        case 2:
        case 3:
        {
            s_state = 0;
            m_popup->hide(VFX_TRUE);
            VFX_OBJ_CLOSE(m_popup);
            timer->stop();
            break;
        }

        // Progress Indicator
        case 4:
        {
            s_state = 0;
            m_popup->hide(VFX_TRUE);
            VFX_OBJ_CLOSE(m_popup);
            timer->stop();
            break;
        }
        case 5:
        {
            s_state = 6;
            timer->stop();
            m_popup->setProgress(0.75);
            timer->start();
            break;
        }
        case 6:
        {
            s_state = 4;
            timer->stop();
            m_popup->setProgress(1.0);
            timer->start();
            break;
        }

        // Progress Indicator + button
        case 7:
        {
            s_state = 0;
            timer->stop();
            m_popup->hide(VFX_TRUE);
            VFX_OBJ_CLOSE(m_popup);
            break;
        }
        case 8:
        {
            s_state = 9;
            timer->stop();
            m_popup->setProgress(0.75);
            timer->start();
            break;
        }
        case 9:
        {
            s_state = 7;
            timer->stop();
            m_popup->setProgress(1.0);
            timer->start();
            break;
        }
    }

}


VtstTestResultEnum vtst_rt_activity_indicator(VfxU32 param)
{
    VFX_UNUSED(param);
    VfxAppLauncher::launchWithAsmSize( 
        APP1_BASE, 
        VFX_OBJ_CLASS_INFO(VtstActivityIndicatorApp),
        GRP_ID_ROOT, 204800 * 1,
        NULL, 0);
   return VTST_TR_OK;
}
    
    
#endif // __AFX_RT_TEST__

    
