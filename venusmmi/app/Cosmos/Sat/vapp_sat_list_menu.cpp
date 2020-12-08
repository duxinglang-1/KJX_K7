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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  Vapp_sat_list_menu.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements  SAT List Menu Class.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/***************************************************************************** 
 * Include
 *****************************************************************************/

#ifdef __cplusplus
   extern "C"{
#endif
   
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "ProfilesSrvGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "GpioSrvGprot.h"
#include "ImeGprot.h"
#include "gui.h"
#include "mmi_rp_app_charger_def.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_utility_gprot.h"
#include "FileMgrSrvGProt.h"
#include "PhoneSetupGprots.h"
#include "GlobalResDef.h"
#include "GeneralSettingSrvGprot.h"
#include "CustDataRes.h"
#include "UCMGProt.h"
#include "UcmSrvGprot.h"
#include "SatSrvGprot.h"
#include "SatCoreProt.h"
   
#ifdef BROWSER_SUPPORT
#include "Browser_api.h"
#endif /* BROWSER_SUPPORT */
   
#ifdef __cplusplus
   }
#endif
   
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vfx_cpp_base.h"
#include "vfx_class_info.h"
#include "vfx_page_bar.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_font_desc.h"

#include "vapp_sat.h"
#include "vapp_sat_base.h"
#include "vapp_sat_list_menu.h"
#include "mmi_rp_srv_sat_def.h"
#include "mmi_rp_vapp_sat_def.h"
#include "vadp_app_trc.h"
#include "vadp_app_trc_gen.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/***************************************************************************** 
 * Class VappSatListMenuCellMultiLine
 *****************************************************************************/

//VFX_IMPLEMENT_CLASS("VappSatListMenuCellMultiLine", VappSatListMenuCellMultiLine, VcpListMenuCellClientBaseFrame);

VappSatListMenuCellMultiLine::VappSatListMenuCellMultiLine() :
    m_marquee1(NULL),
    m_marquee2(NULL),
    m_text1(VFX_WSTR_NULL),
    m_text2(VFX_WSTR_NULL),
    m_textView1(NULL),
    m_textView2(NULL)
{
}


VappSatListMenuCellMultiLine::VappSatListMenuCellMultiLine(const VfxWString &text1, const VfxWString &text2) :
    m_marquee1(NULL),
    m_marquee2(NULL),
    m_text1(text1),
    m_text2(text2),
    m_textView1(NULL),
    m_textView2(NULL)
{
}


void VappSatListMenuCellMultiLine::onCreateElements()
{
    VcpListMenuCell *cell = getCell();

    if (!cell)
    {
        return;
    }

    VFX_OBJ_CREATE(m_marquee1, VcpMarquee, this);

    // text1
    m_marquee1->setMovableFrame(m_text1, VfxFontDesc(VCP_LIST_MENU_FONT_SIZE_MEDIUM));

    m_marquee1->setValign(VcpMarquee::VALIGN_CENTER);
    m_marquee1->setSpeed(VcpMarquee::DEFAULT_SPEED / 3);



    // rect1
    VFX_OBJ_CREATE(m_textView1, VfxTextFrame, this);
    m_textView1->setString(VFX_WSTR("W"));
    m_textView1->setFont(VfxFontDesc(VCP_LIST_MENU_FONT_SIZE_MEDIUM));


if(!m_text2.isNull())
{
	VFX_OBJ_CREATE(m_marquee2, VcpMarquee, this);
	m_marquee2->setMovableFrame(m_text2, VfxFontDesc(VFX_FONT_DESC_SIZE_SMALL));
	// text2
	m_marquee2->setValign(VcpMarquee::VALIGN_CENTER);
	m_marquee2->setSpeed(VcpMarquee::DEFAULT_SPEED / 3);



    // rect2
    VFX_OBJ_CREATE(m_textView2, VfxTextFrame, this);
    m_textView2->setString(VFX_WSTR("W"));
    m_textView2->setFont(VfxFontDesc(VCP_LIST_MENU_FONT_SIZE_SMALL));

}


}


void VappSatListMenuCellMultiLine::onCloseElements()
{
    VFX_OBJ_CLOSE(m_marquee1);
    VFX_OBJ_CLOSE(m_textView1);

	
	if(!m_text2.isNull())
	{
		VFX_OBJ_CLOSE(m_marquee2);
    VFX_OBJ_CLOSE(m_textView2);
}

}


void VappSatListMenuCellMultiLine::onLayoutElements()
{
    if (m_marquee1)
    {
        if(!m_marquee2)
        {
	        m_marquee1->setRect(VfxRect(LEFT_GAPS,
                        (getBounds().getHeight() - m_textView1->getBounds().getHeight()) / 2,
                        getRect().getWidth() - LEFT_GAPS - RIGHT_GAPS,
                        m_textView1->getRect().getHeight()));
		}
		else
		{
        m_marquee1->setRect(VfxRect(TEXT1_LEFT_GAPS,
                                TEXT1_TOP_GAPS,
                                getRect().getWidth() - TEXT1_LEFT_GAPS - TEXT1_RIGHT_GAPS,
                                m_textView1->getRect().getHeight()));

		}


        m_marquee1->startScroll();
        m_textView1->setHidden(VFX_TRUE);
    }

    if (m_marquee2)
    {
        m_marquee2->setRect(VfxRect(TEXT2_LEFT_GAPS,
                                getRect().getHeight() - 1 - TEXT2_BOTTOM_GAPS - m_textView2->getRect().getHeight(),
                                getRect().getWidth() - TEXT2_LEFT_GAPS - TEXT2_RIGHT_GAPS,
                                m_textView2->getRect().getHeight()));

        m_marquee2->startScroll();
        m_textView2->setHidden(VFX_TRUE);
    }
}


void VappSatListMenuCellMultiLine::onUpdateElements()
{
    if (m_marquee1)
    {
        m_marquee1->setTextColor(getCell()->getTextColor(VCP_LIST_MENU_TEXT_COLOR_NORMAL));
    }
 
    if (m_marquee2)
    {
        m_marquee2->setTextColor(getCell()->getTextColor(VCP_LIST_MENU_TEXT_COLOR_NORMAL));
    }
}


/*****************************************************************************
 * Class VappSatListMenuCellIconSingleLine
 *****************************************************************************/

//VFX_IMPLEMENT_CLASS("VappSatListMenuCellIconSingleLine", VappSatListMenuCellIconSingleLine, VcpListMenuCellClientBaseFrame);
#ifndef __SAT_DISABLE_ICON_SUPPORT__
VappSatListMenuCellIconSingleLine::VappSatListMenuCellIconSingleLine() :
    m_marquee(NULL),
    m_imageFrame(NULL),
    m_text(VFX_WSTR_NULL),
    m_imgSrc(NULL),
    m_textFrame(NULL)
{
}


VappSatListMenuCellIconSingleLine::VappSatListMenuCellIconSingleLine(const VfxImageSrc &imgScr, const VfxWString &text) :
    m_marquee(NULL),
    m_imageFrame(NULL),
    m_text(text),
    m_imgSrc(imgScr),
    m_textFrame(NULL)
{
}


void VappSatListMenuCellIconSingleLine::onCreateElements()
{
    VcpListMenuCell *cell = getCell();

    if (!cell)
    {
        return;
    }

    VFX_OBJ_CREATE(m_marquee, VcpMarquee, this);
    VFX_OBJ_CREATE(m_imageFrame, VfxImageFrame, this);

    // icon
    m_imageFrame->setImgContent(m_imgSrc);

    // text
    m_marquee->setMovableFrame(m_text, VfxFontDesc(VCP_LIST_MENU_FONT_SIZE_MEDIUM));
    m_marquee->setValign(VcpMarquee::VALIGN_CENTER);
 
    VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);
    m_textFrame->setString(VFX_WSTR("W"));
    m_textFrame->setFont(VfxFontDesc(VCP_LIST_MENU_FONT_SIZE_MEDIUM));
}


void VappSatListMenuCellIconSingleLine::onCloseElements()
{
    VFX_OBJ_CLOSE(m_marquee);
    VFX_OBJ_CLOSE(m_imageFrame);
    VFX_OBJ_CLOSE(m_textFrame);
}


void VappSatListMenuCellIconSingleLine::onLayoutElements()
{
    if (m_imageFrame)
    {
        m_imageFrame->setRect(VfxRect(IMG_LEFT_GAPS,
                                     (getBounds().getHeight() - m_imageFrame->getBounds().getHeight()) / 2,
                                     IMG_MAX_WIDTH,
                                     m_imageFrame->getRect().getHeight()));

        m_imageFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }

    if (m_marquee)
    {
        m_marquee->setRect(VfxRect(TEXT_LEFT_GAPS + IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH,
                                 (getBounds().getHeight() - m_textFrame->getBounds().getHeight()) / 2,
                                 getRect().getWidth() - TEXT_LEFT_GAPS - TEXT_RIGHT_GAPS - (IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH),
                                 m_textFrame->getRect().getHeight()));

        m_textFrame->setHidden(VFX_TRUE);

        m_marquee->startScroll();
    }
}


void VappSatListMenuCellIconSingleLine::onUpdateElements()
{
    if (m_marquee)
    {
        m_marquee->setTextColor(getCell()->getTextColor(VCP_LIST_MENU_TEXT_COLOR_NORMAL));
    }
}


/***************************************************************************** 
 * Class VappSatListMenuCellMultiLine
 *****************************************************************************/

//VFX_IMPLEMENT_CLASS("VappSatListMenuCellIconMultiLine", VappSatListMenuCellIconMultiLine, VcpListMenuCellClientBaseFrame);

VappSatListMenuCellIconMultiLine::VappSatListMenuCellIconMultiLine() :
    m_marquee1(NULL),
    m_marquee2(NULL),
    m_imageFrame(NULL),
    m_text1(VFX_WSTR_NULL),
    m_text2(VFX_WSTR_NULL),
    m_imgSrc(NULL),
    m_textView1(NULL),
    m_textView2(NULL)
{
}


VappSatListMenuCellIconMultiLine::VappSatListMenuCellIconMultiLine(const VfxImageSrc &imgScr, const VfxWString &text1, const VfxWString &text2) :
    m_marquee1(NULL),
    m_marquee2(NULL),
    m_imageFrame(NULL),
    m_text1(text1),
    m_text2(text2),
    m_imgSrc(imgScr),
    m_textView1(NULL),
    m_textView2(NULL)
{
}


void VappSatListMenuCellIconMultiLine::onCreateElements()
{
    VcpListMenuCell *cell = getCell();

    if (!cell)
    {
        return;
    }

    VFX_OBJ_CREATE(m_marquee1, VcpMarquee, this);
    VFX_OBJ_CREATE(m_marquee2, VcpMarquee, this);
    VFX_OBJ_CREATE(m_imageFrame, VfxImageFrame, this);

    // icon
    m_imageFrame->setImgContent(m_imgSrc);

    // text1
    m_marquee1->setMovableFrame(m_text1, VfxFontDesc(VCP_LIST_MENU_FONT_SIZE_MEDIUM));

    m_marquee1->setValign(VcpMarquee::VALIGN_CENTER);
     m_marquee1->setSpeed(VcpMarquee::DEFAULT_SPEED / 3);

    // text2
    m_marquee2->setMovableFrame(m_text2, VfxFontDesc(VFX_FONT_DESC_SIZE_SMALL));

    m_marquee2->setValign(VcpMarquee::VALIGN_CENTER);
     m_marquee2->setSpeed(VcpMarquee::DEFAULT_SPEED / 3);

    // rect1
    VFX_OBJ_CREATE(m_textView1, VfxTextFrame, this);
    m_textView1->setString(VFX_WSTR("W"));
    m_textView1->setFont(VfxFontDesc(VCP_LIST_MENU_FONT_SIZE_MEDIUM));

    // rect2
    VFX_OBJ_CREATE(m_textView2, VfxTextFrame, this);
    m_textView2->setString(VFX_WSTR("W"));
    m_textView2->setFont(VfxFontDesc(VCP_LIST_MENU_FONT_SIZE_SMALL));
}


void VappSatListMenuCellIconMultiLine::onCloseElements()
{
    VFX_OBJ_CLOSE(m_marquee1);
    VFX_OBJ_CLOSE(m_marquee2);
    VFX_OBJ_CLOSE(m_imageFrame);
    VFX_OBJ_CLOSE(m_textView1);
    VFX_OBJ_CLOSE(m_textView2);
}


void VappSatListMenuCellIconMultiLine::onLayoutElements()
{
    if (m_imageFrame)
    {
        m_imageFrame->setRect(VfxRect(IMG_LEFT_GAPS, (getBounds().getHeight() - m_imageFrame->getBounds().getHeight()) / 2,
                                      IMG_MAX_WIDTH, m_imageFrame->getRect().getHeight()));

        m_imageFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }

    if (m_marquee1)
    {
        m_marquee1->setRect(VfxRect(TEXT1_LEFT_GAPS + IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH,
                                      TEXT1_TOP_GAPS,
                                      getRect().getWidth() - TEXT1_LEFT_GAPS - TEXT1_RIGHT_GAPS - (IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH),
                                      m_textView1->getRect().getHeight()));

        m_marquee1->startScroll();
        m_textView1->setHidden(VFX_TRUE);
    }

    if (m_marquee2)
    {
        m_marquee2->setRect(VfxRect(TEXT2_LEFT_GAPS + IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH, 
                                      getRect().getHeight() - 1 - TEXT2_BOTTOM_GAPS - m_textView2->getRect().getHeight(),
                                      getRect().getWidth() - TEXT2_LEFT_GAPS - TEXT2_RIGHT_GAPS - (IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH),
                                      m_textView2->getRect().getHeight()));

        m_marquee2->startScroll();
        m_textView2->setHidden(VFX_TRUE);
    }
}


void VappSatListMenuCellIconMultiLine::onUpdateElements()
{
    if (m_marquee1)
    {
        m_marquee1->setTextColor(getCell()->getTextColor(VCP_LIST_MENU_TEXT_COLOR_NORMAL));
    }
 
    if (m_marquee2)
    {
        m_marquee2->setTextColor(getCell()->getTextColor(VCP_LIST_MENU_TEXT_COLOR_NORMAL));
    }
}

#endif //__SAT_DISABLE_ICON_SUPPORT__
/***************************************************************************** 
 * Class VappSatGroupListMenu
 *****************************************************************************/

//VFX_IMPLEMENT_CLASS("VappSatGroupListHeader", VappSatGroupListHeader, VcpGroupListMenuHeader);
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

/***************************************************************************** 
 * Class VappSatMenuPage
 *****************************************************************************/

//VFX_IMPLEMENT_CLASS("VappSatMenuPage", VappSatMenuPage, VappSatBasePage);

VappSatMenuPage::VappSatMenuPage() :
    m_isTitlebar(VFX_TRUE),
   // m_selectedIndex(0),
    //m_listMenu(NULL),
    m_cellStyle(VAPP_SAT_LIST_MENU_CELL_STYLE_SINGLE_TEXT)
    //m_menuCtrlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL)
{
}


VappSatMenuPage::VappSatMenuPage(srv_sat_proactive_sim_struct *cmdInfo) :
    VappSatBasePage(cmdInfo),
    m_isTitlebar(VFX_TRUE),
    m_groupNum(1),
   // m_selectedIndex(0),
   // m_listMenu(NULL),
    m_cellStyle(VAPP_SAT_LIST_MENU_CELL_STYLE_SINGLE_TEXT)
   // m_menuCtrlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL)
{
}


VappSatMenuPage::VappSatMenuPage(mmi_sim_enum simId, srv_sat_setup_menu_struct *mainmenu, VfxBool isTitlebar) :
    VappSatBasePage(simId, mainmenu),
    m_isTitlebar(isTitlebar),
    m_groupNum(1),
    //m_selectedIndex(0),
   // m_listMenu(NULL),
    m_cellStyle(VAPP_SAT_LIST_MENU_CELL_STYLE_SINGLE_TEXT)
   // m_menuCtrlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL)
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_MENU_PAGE_CONSTRUCT);
}

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
/* under construction !*/
/* under construction !*/
#endif
void VappSatMenuPage::onInit()
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_MENU_PAGE_ONINIT);

    VappSatBasePage::onInit();

    //VFX_OBJ_CREATE(m_listMenu, VappSatGroupListMenu, this);
	VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);

    // set list menu property
    m_listMenu->setContentProvider(this);
    m_listMenu->m_signalItemSelectionStateChanged.connect(this, &VappSatMenuPage::onItemStateChanged);
    m_listMenu->m_signalItemTapped.connect(this, &VappSatMenuPage::onItemTapped);
    m_listMenu->m_signalCmdButtonClicked.connect(this, &VappSatMenuPage::onCmdBtnTapped);
    m_listMenu->setSize(getSize());
    m_listMenu->setAlignParent(
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_SIDE);
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_CUSTOM);

    memset(m_itemText, 0, sizeof(m_itemText));
    memset(m_itemHint, 0, sizeof(m_itemHint));
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    memset(m_itemIcon, 0, sizeof(m_itemIcon));
#endif

    cmdParser();
    updateListMenu();
    setToolBar();
    addCmdTimer();
}


void VappSatMenuPage::onDeinit()
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_MENU_PAGE_ONDEINIT);

    cmdSessionEnd();

    //VFX_OBJ_CLOSE(m_listMenu);
    VappSatBasePage::onDeinit();
}


void VappSatMenuPage::onUpdate()
{
    VappSatBasePage::onUpdate();
}


mmi_ret VappSatMenuPage::onProc(mmi_event_struct *evt)
{
    mmi_ret ret = MMI_RET_DONT_CARE;

    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_MENU_PAGE_ONPROC, evt->evt_id);

    switch (evt->evt_id)
    {
        case EVT_ID_SRV_SAT_PROACTIVE_SIM:
        {
            srv_sat_proactive_sim_event_struct *event = (srv_sat_proactive_sim_event_struct *)evt;

            if (isDontCareCmd(event->proactive_sim))
            {
                ret = MMI_RET_DONT_CARE;
                break;
            }

            if (getCmdType() == SRV_SAT_CMD_SETUP_MENU)
            {
                setIsSent(VFX_FALSE);

                if (event->proactive_sim->cmd_type == SRV_SAT_CMD_SETUP_MENU)
                {
                    cmdParser();
                    updateListMenu();

                    ret = MMI_RET_OK;
                }

                break;
            }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            if (getCmdType() != SRV_SAT_CMD_SETUP_MENU)
            {
                VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_MENU_PAGE_EXIT);
                deleteCmdTimer();
                exit();
            }

            break;
        }

        case EVT_ID_SRV_SAT_SESSION_END:
        {
            srv_sat_session_end_event_struct *event = (srv_sat_session_end_event_struct *)evt;
            if (event->sim_id != getSimId())
            {
                break;
            }

            if (getCmdType() == SRV_SAT_CMD_SETUP_MENU)
            {
                setIsSent(VFX_FALSE);

                break;
            }

            getMainScr()->popPage();
            break;
        }

        default:
            break;
    }

    VappSatBasePage::onProc(evt);

    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_MENU_PAGE_ONPROC_RET, ret);

    return ret;
}


VfxBool VappSatMenuPage::onResponse(VappSatToolbarTypeEnum btnId)
{
    VfxBool ret = VFX_TRUE;

    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_MENU_PAGE_ONRESPONS, getSimId(), getCmdType(), btnId, getMenuId());

    if (getCmdType() == SRV_SAT_CMD_SETUP_MENU)
    {
        VFX_OBJ_GET_INSTANCE(VappSatMgr)->setMainMenuItemIndex(getSimId(), m_selectedIndex);
        ret = mmi_sat_setup_menu_response(getSimId(), convertBtnIdToRspId(btnId),  getMenuId());
    }
    else
    {
        ret = mmi_sat_select_item_response(getSimId(), convertBtnIdToRspId(btnId),  getMenuId());
    }

    return ret;
}


void VappSatMenuPage::cmdParser()
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_MENU_PAGE_CMDPARSER, getCmdType());

    switch (getCmdType())
    {
        case SRV_SAT_CMD_SETUP_MENU:
        {
            srv_sat_setup_menu_struct *menu_data = (srv_sat_setup_menu_struct *)getCmdData();

            VFX_OBJ_GET_INSTANCE(VappSatMgr)->setMainMenuItemIndex(getSimId(), -1);
           
            setInService(srv_sat_is_menu_present(getSimId()) ? VFX_TRUE : VFX_FALSE);
			 setTitleData(menu_data->icon, menu_data->alpha_id);
            setItemData((VfxS32)menu_data->num_of_item, menu_data->item_list);

            if (menu_data->help_available)
            {
                //setMenuCtrlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON);
				m_menuCtrlMode = VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON;
            }
            else
            {
                //setMenuCtrlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL);
                m_menuCtrlMode = VCP_LIST_MENU_CONTROL_MODE_NORMAL;
            }

            break;
        }

        case SRV_SAT_CMD_SELECT_ITEM:
        {
            srv_sat_select_item_struct *menu_data = (srv_sat_select_item_struct *)getCmdData();

            setTitleData(menu_data->icon, menu_data->alpha_id);
            setItemData((VfxS32)menu_data->num_of_item, menu_data->item_list);

            if (menu_data->help_available)
            {
                //setMenuCtrlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON);
                m_menuCtrlMode = VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON;
            }
            else
            {
                //setMenuCtrlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL);
				m_menuCtrlMode = VCP_LIST_MENU_CONTROL_MODE_NORMAL;
            }

            setTimerId(SAT_TIMER_NO_RESPONSE);
            setTimerDuration(VAPP_SAT_NO_RESPONSE_DURATION);
            break;
        }

        default:
            VFX_ASSERT(0);
            break;
    }
}


void VappSatMenuPage::setItemData(VfxS32 num, srv_sat_item_struct *items)
{
    VfxS32 max_items_num = num > MMI_SAT_MENU_ITEM_MAX_NUM ? MMI_SAT_MENU_ITEM_MAX_NUM : num;
	max_items_num = m_groupNum ? max_items_num : 0;
    setItemNum(max_items_num);

    for (VfxS32 i = 0; i < max_items_num; i++)
    {
        m_itemText[i] = (VfxU8 *)items[i].alpha_id;

#ifndef __SAT_DISABLE_ICON_SUPPORT__
        m_itemIcon[i] = (VfxU8 *)items[i].icon.data;
        if (m_itemIcon[i])
        {
            //setCellStyle(VAPP_SAT_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT);
            m_cellStyle = VAPP_SAT_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT;
        }
#endif //__SAT_DISABLE_ICON_SUPPORT__
        m_itemHint[i] = (VfxU8 *)mmi_sat_get_cmd_hint(items[i].next_action_ind, getCmdType());
        if (m_itemHint[i])
        {
#ifndef __SAT_DISABLE_ICON_SUPPORT__
            //if (getCellStyle() == VAPP_SAT_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT)
            if (m_cellStyle == VAPP_SAT_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT)
            {
                //setCellStyle(VAPP_SAT_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT);
                m_cellStyle = VAPP_SAT_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT;
            }
            else
            {
#endif  //__SAT_DISABLE_ICON_SUPPORT__  
                //setCellStyle(VAPP_SAT_LIST_MENU_CELL_STYLE_MULTI_TEXT);
                m_cellStyle = VAPP_SAT_LIST_MENU_CELL_STYLE_MULTI_TEXT;
#ifndef __SAT_DISABLE_ICON_SUPPORT__
            }
#endif  //__SAT_DISABLE_ICON_SUPPORT__
        }
    }
}


void VappSatMenuPage::setTitleData(srv_sat_icon_struct iconInfo, WCHAR *string)
{
    if (!m_isTitlebar)
    {
        return;
    }
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    if (!iconInfo.available || iconInfo.attr != SRV_SAT_ICON_SELF_EX || !m_groupNum)
    {
#endif //__SAT_DISABLE_ICON_SUPPORT__
        if (string == NULL || *string == '\0'|| !m_groupNum)
        {
            VfxS32 index = VFX_OBJ_GET_INSTANCE(VappSatMgr)->getMainMenuItemIndex(getSimId());
            if (index < 0)
            {
                string = (WCHAR *)srv_sat_get_menu_title(getSimId());
            }
            else
            {
                string = (WCHAR *)srv_sat_get_menu_item(getSimId(), (S32)index);
            }
        }
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    }
#endif //__SAT_DISABLE_ICON_SUPPORT__
    setTitleBar(VfxImageSrc(iconInfo.data), VFX_WSTR_MEM(string));
}


//VfxBool VappSatMenuPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
 VfxBool VappSatMenuPage::getItemText(
        VfxU32 index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxWString &text,               // [OUT] the text resource
        VcpListMenuTextColorEnum &color // [OUT] the text color
        )


{
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        if (m_itemText[index] != NULL )
        {
            text.loadFromMem((VfxWChar *)m_itemText[index]);
            color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        }
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        if (m_itemHint[index] != NULL )
        {
			text.loadFromMem((VfxWChar *)m_itemHint[index]);
            color = VCP_LIST_MENU_TEXT_COLOR_DISABLED;
        }
    }

    return VFX_TRUE;
}


VfxBool VappSatMenuPage::getItemTextFormat(VfxU32 index, VcpListMenuFieldEnum fieldType, VcpRichText &format)
{
    return VFX_FALSE;
}


VcpListMenuCellClientBaseFrame *VappSatMenuPage::getItemCustomContentFrame(VfxU32 index, VfxFrame *parentFrame)
{
    VFX_ASSERT(index < (VfxS32)getCount());

    VfxWString text;
    VcpListMenuTextColorEnum textColor;
    getItemText(index, VCP_LIST_MENU_FIELD_TEXT, text, textColor);

    VcpListMenuCellClientBaseFrame *obj = NULL;

    //switch (getCellStyle())
    switch(m_cellStyle)
    {
        case VAPP_SAT_LIST_MENU_CELL_STYLE_SINGLE_TEXT:
        {
            //VFX_OBJ_CREATE_EX(obj, VappSatListMenuCellSingleLine, parentFrame, (text));
            VFX_OBJ_CREATE_EX(obj, VappSatListMenuCellMultiLine, parentFrame, (text));
            break;
        }

        case VAPP_SAT_LIST_MENU_CELL_STYLE_MULTI_TEXT:
        {
            VfxWString text2;
            getItemText(index, VCP_LIST_MENU_FIELD_SUB_TEXT1, text2, textColor);

            VFX_OBJ_CREATE_EX(obj, VappSatListMenuCellMultiLine, parentFrame, (text, text2));
            break;
        }
#ifndef __SAT_DISABLE_ICON_SUPPORT__
        case VAPP_SAT_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT:
        {
            VfxImageSrc image;
            getItemImage(index, VCP_LIST_MENU_FIELD_ICON, image);
            VFX_OBJ_CREATE_EX(obj, VappSatListMenuCellIconSingleLine, parentFrame, (image, text));
            break;
        }

        case VAPP_SAT_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT:
        {
            VfxWString text2;
            getItemText(index, VCP_LIST_MENU_FIELD_SUB_TEXT1, text2, textColor);

            VfxImageSrc image;
            getItemImage(index, VCP_LIST_MENU_FIELD_ICON, image);

            VFX_OBJ_CREATE_EX(obj, VappSatListMenuCellIconMultiLine, parentFrame, (image, text, text2));
            break;
        }
#endif //__SAT_DISABLE_ICON_SUPPORT__
        default:
            break;
    }

    VFX_ASSERT(obj != NULL);

    return obj;
}


void VappSatMenuPage::closeItemCustomContentFrame(VfxU32 index, VcpListMenuCellClientBaseFrame *cell)
{
    VFX_OBJ_CLOSE(cell);
}


VcpListMenuItemStateEnum VappSatMenuPage::getItemState(VfxU32 index) const
{
    if (m_selectedIndex == index)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    else if (index > (VfxS32)m_listNum)
    {
        return VCP_LIST_MENU_ITEM_STATE_NONE;
    }
    else
    {
        return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }
}

#ifndef __SAT_DISABLE_ICON_SUPPORT__
VfxBool VappSatMenuPage::getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc &image)
{
    if (fieldType == VCP_LIST_MENU_FIELD_ICON)
    {
        if (m_itemIcon[index] != NULL)
        {
            image = VfxImageSrc(m_itemIcon[index]);
        }
    }

    if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL)
    {
        image.setResId(IMG_ID_VAPP_SAT_HELP);
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED)
    {
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED)
    {
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT)
    {
    }

    return VFX_TRUE;
}
#endif  //__SAT_DISABLE_ICON_SUPPORT__

VfxBool VappSatMenuPage::getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color)
{
	text.loadFromRes(STR_ID_VAPP_SAT_NO_SERVICES);

    return VFX_TRUE;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

VfxU8 VappSatMenuPage::getMenuId()
{
    srv_sat_item_struct *item = NULL;
    srv_sat_setup_menu_struct *main_menu = NULL;
    srv_sat_select_item_struct *sub_menu = NULL;

    if (getCmdType() == SRV_SAT_CMD_SETUP_MENU)
    {
        main_menu = (srv_sat_setup_menu_struct *)getCmdData();
        item = main_menu->item_list;
    }
    else
    {
        sub_menu = (srv_sat_select_item_struct *)getCmdData();
        item = sub_menu->item_list;
    }

    return item[m_selectedIndex].id;
}

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void VappSatMenuPage::setInService(VfxBool bVal)
{
    m_groupNum = 0;
    m_bInService = bVal;

    if (bVal)
    {
        m_groupNum = 1;
    }
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void VappSatMenuPage::updateListMenu()
{
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_FALSE);
    m_listMenu->setMenuControlMode(m_menuCtrlMode, VFX_FALSE);

    m_listMenu->resetAllItems(VFX_FALSE);
}


void VappSatMenuPage::onItemStateChanged(VcpListMenu *sender, VfxU32 pos, VcpListMenuItemStateEnum state)
{
    if (state == VCP_LIST_MENU_ITEM_STATE_SELECTED)
    {
        m_selectedIndex = pos;
    }
}


void VappSatMenuPage::onItemTapped(VcpListMenu *sender, VfxU32 pos)
{
    //if (pos < 0)
    //{
     //   return;
    //}

    m_selectedIndex = pos;

    //setTapType(SAT_LIST_ITEM_TAP);
    onMeResponse(this, TOOLBAR_OK);
}


void VappSatMenuPage::onCmdBtnTapped(VcpListMenu *sender, VfxU32 pos)
{
    m_selectedIndex = pos;

    //setTapType(SAT_LIST_ITEM_CMD_TAP);
    onMeResponse(this, TOOLBAR_HELP);
}

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
#endif

#if (MMI_MAX_SIM_NUM >= 2)
/***************************************************************************** 
 * Class VappSatMainMenuCtrlPage
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappSatMainMenuCtrlPage", VappSatMainMenuCtrlPage, VcpTabCtrlPage);

VappSatMainMenuCtrlPage::VappSatMainMenuCtrlPage()
{
	//memset(m_sat, NULL, x)m_sat[TAB_TOTAL - 1] = {NULL};
	for(S32 i = 0; i <= TAB_TOTAL - 1; i++)
{
		m_sat[i] = NULL;
		m_tabText[i + 1] = VFX_WSTR_NULL;
	}
	//m_sat[]
    //m_tabText[TAB_SIM1] = VFX_WSTR_NULL;
    m_tabIcon[TAB_SIM1] = VcpStateImage(IMG_ID_VAPP_SAT_SIM1);

    //m_tabText[TAB_SIM2] = VFX_WSTR_NULL;
    m_tabIcon[TAB_SIM2] = VcpStateImage(IMG_ID_VAPP_SAT_SIM2);

#if (MMI_MAX_SIM_NUM >= 3)
    //m_tabText[TAB_SIM3] = VFX_WSTR_NULL;
    m_tabIcon[TAB_SIM3] = VcpStateImage(IMG_ID_VAPP_SAT_SIM3);

#if (MMI_MAX_SIM_NUM >= 4)
    //m_tabText[TAB_SIM4] = VFX_WSTR_NULL;
    m_tabIcon[TAB_SIM4] = VcpStateImage(IMG_ID_VAPP_SAT_SIM4);

#endif
#endif
}


void VappSatMainMenuCtrlPage::onInit()
{
    VcpTabCtrlPage::onInit();
    getTabCtrl()->setIsHighlightedTextScrolling(VFX_TRUE);

    for (U32 i = 1; i <= MMI_SIM_TOTAL; i++)
    {
        mmi_sim_enum simId = (mmi_sim_enum)(1 << (i - 1));
        if (srv_sat_is_menu_present(simId))
        {
            addTab(i, m_tabText[i], m_tabIcon[i]);
            updateTab(simId);
        }
    }
}


VfxPage *VappSatMainMenuCtrlPage::onCreateTabPage(VfxId tabId)
{
    VfxPage *page = NULL;
	mmi_sim_enum sim_id = mmi_frm_index_to_sim(tabId - 1);
	VFX_OBJ_CREATE_EX(m_sat[tabId], VappSatMenuPage, getMainScr(), (sim_id, (srv_sat_setup_menu_struct *)srv_sat_get_setup_menu(sim_id), VFX_FALSE));
	page = m_sat[tabId];
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    VFX_ASSERT(page != NULL);

    return page;
}


mmi_ret VappSatMainMenuCtrlPage::processProc(mmi_event_struct *evt)
{
    onProc(evt);

    return VcpTabCtrlPage::processProc(evt);
}


void VappSatMainMenuCtrlPage::onTabSwitching(VfxId tabId)
{
	if(m_sat[tabId])
	{
        VfxBool isPresent = srv_sat_is_menu_present(MMI_SIM1) ? VFX_TRUE : VFX_FALSE;
        m_sat[tabId]->setInService(isPresent);
	}
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
/* under construction !*/
    #if (MMI_MAX_SIM_NUM >= 3)
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
    #if (MMI_MAX_SIM_NUM >= 4)
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
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
}


mmi_ret VappSatMainMenuCtrlPage::onProc(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_SRV_SAT_PROACTIVE_SIM)
    {
        srv_sat_proactive_sim_event_struct *event = (srv_sat_proactive_sim_event_struct *)evt;

        if (event->proactive_sim->cmd_type == SRV_SAT_CMD_SETUP_MENU)
        {
            srv_sat_setup_menu_struct *menu = (srv_sat_setup_menu_struct *)(&event->proactive_sim->cmd_data);
            if (menu->present)
            {
                updateTab(event->proactive_sim->sim_id);
            }
        }
    }

    return MMI_RET_OK;
}


void VappSatMainMenuCtrlPage::getTabTextIcon(mmi_sim_enum sim_id)
{
    S32 index = mmi_frm_sim_to_index(sim_id) + 1;
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    srv_sat_icon_struct *icon = (srv_sat_icon_struct *)&srv_sat_get_setup_menu(sim_id)->icon;
    if (icon->available)
    {
        m_tabIcon[index].setImage(VfxImageSrc(icon->data),
                                VfxImageSrc(VFX_IMAGE_SRC_TYPE_NULL),
                                VfxImageSrc(VFX_IMAGE_SRC_TYPE_NULL),
                                VfxImageSrc(VFX_IMAGE_SRC_TYPE_NULL));
    }
#endif  //__SAT_DISABLE_ICON_SUPPORT__

#ifndef __SAT_DISABLE_ICON_SUPPORT__
    if (!icon->available || icon->attr != SRV_SAT_ICON_SELF_EX)
    {
#endif  //__SAT_DISABLE_ICON_SUPPORT__
        //m_tabText[index] = VFX_WSTR_MEM(srv_sat_get_menu_title(sim_id));
		m_tabText[index].loadFromMem(srv_sat_get_menu_title(sim_id));
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    }
#endif  //__SAT_DISABLE_ICON_SUPPORT__
}


void VappSatMainMenuCtrlPage::updateTab(mmi_sim_enum sim_id)
{
    getTabTextIcon(sim_id);
	S32 index = mmi_frm_sim_to_index(sim_id) + 1;
	changeTab(index, m_tabText[index], m_tabIcon[index]);
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
    #if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}
#endif /* MMI_MAX_SIM_NUM >= 2 */
