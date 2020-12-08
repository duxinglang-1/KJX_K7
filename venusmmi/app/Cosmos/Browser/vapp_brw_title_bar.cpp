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
 *  vapp_brw_title_bar.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _VAPP_BRW_TITLEBAR_CPP_
#define _VAPP_BRW_TITLEBAR_CPP_


#include "MMI_features.h" 
#ifdef __MMI_BROWSER_2__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_brw_title_bar.h"
#include "mmi_rp_vapp_browser_def.h"
#include "vapp_brw_main.h"

/*extern "C"
{
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__) 
#include "dcmgr.h" // DCM
#endif
}*/

//#pragma arm section code = "DYNAMIC_CODE_BROWSER_ROCODE", rodata = "DYNAMIC_CODE_BROWSER_RODATA"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
static const S32 VCP_BRW_TITLE_BAR_TITLE_MARGIN_TOP = 3;
static const S32 VCP_BRW_TITLE_BAR_TITLE_MARGIN_BOTTOM = 4;
//static const S32 VCP_BRW_TITLE_BAR_TITLE_MARGIN_SUBTITLE = 4;
static const S32 VCP_BRW_TITLE_BAR_TITLE_MARGIN_HORIZONTAL = 4;
/***************************************************************************** 
 * Function
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappBrwTitleBar", VappBrwTitleBar, VcpTitleBar);

VappBrwTitleBar::VappBrwTitleBar() :
	m_titleControl(NULL),
	m_textInput(NULL),
	m_editorIcon(NULL),
	m_isHitEditorIcon(VFX_FALSE),
	m_fullScreenIcon(NULL)
	
{
}


void VappBrwTitleBar::setRightIcon(const VfxImageSrc& image)
{
    setRightIconInt(image, 0);
    checkUpdate();
}

void VappBrwTitleBar::setEditorIcon(const VfxImageSrc& image)
{
    setEditorIconInt(image, 0);
    checkUpdate();
}

void VappBrwTitleBar::enableHomePageTap(VfxBool enable)
{
    if(m_homePageIcon)
    {
        if(enable)
        {
            m_homePageIcon->setIsDisabled(VFX_FALSE);
            m_homePageIcon->setOpacity(1.0f);
        }
        else
        {
            m_homePageIcon->setIsDisabled(VFX_TRUE);
            m_homePageIcon->setOpacity(0.5f);
        }
    }
    checkUpdate();
}

void VappBrwTitleBar::enableScreenModeIconTap(VfxBool enable)
{
    if(m_fullScreenIcon)
    {
        if(enable)
        {
            m_fullScreenIcon->setIsDisabled(VFX_FALSE);
            m_fullScreenIcon->setOpacity(1.0f);
        }
        else
        {
            m_fullScreenIcon->setIsDisabled(VFX_TRUE);
            m_fullScreenIcon->setOpacity(0.5f);
        }
    }
    checkUpdate();
}

void VappBrwTitleBar::onInit(void)
{
    VcpTitleBar::onInit();
	
	VFX_OBJ_CREATE(m_textInput, VcpTextView , this);
	VFX_OBJ_CREATE(m_homePageIcon, VcpButton, this);
	
    setTitleBackground(VfxImageSrc(IMG_ID_VAPP_BRW_WEBSITE_BG));
    setTitleStyle(VCP_TITLE_BAR_STYLE_EMPTY);
    VfxS32 scrnWidth = getParentFrame()->getSize().width;
    setSize(scrnWidth, BAR_HEIGHT);
    setBgColor(VfxColor(VFX_COLOR_GREY));
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

	m_homePageIcon->setId(HOME_PAGE_BUTTON);
	m_homePageIcon->setPos(PORTRAIT_BG_X, PORTRAIT_BG_Y);
	m_homePageIcon->setSize(PORTRAIT_BG_WIDTH,PORTRAIT_BG_WIDTH);
	m_homePageIcon->setBgImageList(VcpStateImage(IMG_ID_VAPP_BRW_BUTTON_BG,IMG_ID_VAPP_BRW_BUTTON_BG,0,0));
	m_homePageIcon->setImage(VcpStateImage(IMG_ID_VAPP_BRW_HOMEPAGE_ICON,IMG_ID_VAPP_BRW_HOMEPAGE_ICON,0,0));
	m_homePageIcon->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_homePageIcon->setState(VCP_BUTTON_STATE_NORMAL);
	m_homePageIcon->m_signalClicked.connect(this, &VappBrwTitleBar::onClickHomePageIcon);
	


    //VFX_OBJ_CREATE(m_textInput, VcpTextView , this);
    VfxS32 pos_x = (PORTRAIT_BG_X + PORTRAIT_BG_WIDTH + RIGHT_IMG_MARGIN);
    VfxS32 editorWidth = scrnWidth - (pos_x + PORTRAIT_BG_X );
    m_textInput->setPos(pos_x, PORTRAIT_BG_Y);
    m_textInput->setBounds(VfxRect(0, 0, editorWidth, ADDRESS_HEIGHT));
    m_textInput->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
    m_textInput->disableBackground(VFX_FALSE);
    VfxFontDesc font;/* set text without any text format*/
    font.size = VFX_FONT_DESC_VF_SIZE(TEXT_FONT_SIZE);
    m_textInput->setFont(font);
    registerKeyHandler(VFX_KEY_CODE_SPECIAL_ALL_IME_SYM_KEYS);
}

void VappBrwTitleBar::onDeinit(void)
{
    unregisterKeyHandler(VFX_KEY_CODE_SPECIAL_ALL_IME_SYM_KEYS);
    VcpTitleBar::onDeinit();
}

VfxBool VappBrwTitleBar::onKeyInput(VfxKeyEvent &event)
{
	VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
	#ifndef __MMI_BRW_SLIM__
	if(!m_brwApp->scr->page->m_homePage)
        return VFX_FALSE;
	#endif
    m_editorKeyInput.emit(event);
    return VFX_TRUE;
}

void VappBrwTitleBar::onUpdate(void)
{
    VcpTitleBar::onUpdate();

    VfxS32 rightOffset = RIGHT_IMG_OFFSET;
    if (m_fullScreenIcon != NULL)
    {
        rightOffset += (RIGHT_IMG_WIDTH + RIGHT_IMG_MARGIN) ;
    }
    VfxS32 scrnWidth = getParentFrame()->getSize().width;
    VfxS32 pos_x;
    if(m_homePageIcon)
    {
        pos_x = (PORTRAIT_BG_X + PORTRAIT_BG_WIDTH + RIGHT_IMG_MARGIN);
    }
    else
    {
        pos_x = (PORTRAIT_BG_X);
    }
    VfxS32 editorWidth = scrnWidth - (pos_x + rightOffset );
	if(m_textInput)
	{
    m_textInput->setPos(pos_x, PORTRAIT_BG_Y);
    m_textInput->setBounds(VfxRect(0, 0, editorWidth, ADDRESS_HEIGHT));
	}
    

    if (m_editorIcon)
    {
        m_editorIcon->setPos((editorWidth + pos_x - EDITOR_ICON_WIDTH), PORTRAIT_BG_Y);
        m_editorIcon->setBounds(0, 0, EDITOR_ICON_WIDTH, ADDRESS_HEIGHT);
    }

    if (m_fullScreenIcon != NULL)
    {
        pos_x = scrnWidth - (RIGHT_IMG_OFFSET+ RIGHT_IMG_WIDTH);
        m_fullScreenIcon->setPos(pos_x, PORTRAIT_BG_Y);
        m_fullScreenIcon->setSize(RIGHT_IMG_WIDTH, RIGHT_IMG_WIDTH);
    }
    updateTitleText();
}

VfxBool VappBrwTitleBar::onPenInput(VfxPenEvent& event)
{
    VfxPoint relPoint = event.getRelPos(this);
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
        {
         
            if (m_editorIcon)
            {
                VfxPoint imgRelPoint;
                imgRelPoint = m_editorIcon->convertPointFrom(relPoint, this);
                if (m_editorIcon->containPoint(imgRelPoint))
                {
                    m_isHitEditorIcon = VFX_TRUE;					
                }
            }
            break;
        }

        case VFX_PEN_EVENT_TYPE_UP:
        {
            if (m_isHitEditorIcon && m_editorIcon)
            {
                VfxPoint imgRelPoint;
                imgRelPoint = m_editorIcon->convertPointFrom(relPoint, this);
                m_isHitEditorIcon = VFX_FALSE;
                if (m_editorIcon->containPoint(imgRelPoint))
                {
                    m_editorIconTap.emit();
                }
            }
            break;
        }
        default:
            break;
    }
    return VFX_TRUE;
}

void VappBrwTitleBar::setRightIconInt(const VfxImageSrc& image, VfxU32 index)
{
	VcpButton *imgFrame = m_fullScreenIcon;
    VfxS32 scrnWidth = getParentFrame()->getSize().width;
   
    if (imgFrame == NULL)
    {
        VFX_OBJ_CREATE(m_fullScreenIcon, VcpButton, this);
		m_fullScreenIcon->setId(FULL_SCREEN_BUTTON);
		m_fullScreenIcon->setBgImageList(VcpStateImage(IMG_ID_VAPP_BRW_BUTTON_BG,IMG_ID_VAPP_BRW_BUTTON_BG,0,0));
		m_fullScreenIcon->setImage(VcpStateImage(IMG_ID_VAPP_BRW_FULLSCREEN,IMG_ID_VAPP_BRW_FULLSCREEN,0,0));
		m_fullScreenIcon->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
		m_fullScreenIcon->setState(VCP_BUTTON_STATE_NORMAL);
		m_fullScreenIcon->m_signalClicked.connect(this, &VappBrwTitleBar::onClickRightIcon);
    }
}

void VappBrwTitleBar::setHomePageIcon()
{
    if(!m_homePageIcon)
    {
        VFX_OBJ_CREATE(m_homePageIcon, VcpButton, this);
		m_homePageIcon->setPos(PORTRAIT_BG_X, PORTRAIT_BG_Y);
		m_homePageIcon->setSize(PORTRAIT_BG_WIDTH,PORTRAIT_BG_WIDTH);
		m_homePageIcon->setBgImageList(VcpStateImage(IMG_ID_VAPP_BRW_BUTTON_BG,IMG_ID_VAPP_BRW_BUTTON_BG,0,0));
		m_homePageIcon->setImage(VcpStateImage(IMG_ID_VAPP_BRW_HOMEPAGE_ICON,IMG_ID_VAPP_BRW_HOMEPAGE_ICON,0,0));
		m_homePageIcon->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
		m_homePageIcon->setState(VCP_BUTTON_STATE_NORMAL);
        checkUpdate();
    }
}

void VappBrwTitleBar::deleteRightIcon(void)
{
    if(m_fullScreenIcon)
    {
       
        VFX_OBJ_CLOSE(m_fullScreenIcon);
        checkUpdate();
    }
}

void VappBrwTitleBar::deleteEditorIcon(void)
{
    if(m_editorIcon)
    {
        VFX_OBJ_CLOSE(m_editorIcon);
        m_textInput->setMargins(0, 0, -EDITOR_ICON_WIDTH, 0);
        checkUpdate();
    }
}

void VappBrwTitleBar::deleteHomePageIcon(void)
{
    if(m_homePageIcon)
    {
        VFX_OBJ_CLOSE(m_homePageIcon);
        checkUpdate();
    }
}


void VappBrwTitleBar::setEditorIconInt(const VfxImageSrc& image, VfxU32 index)
{
    if (m_editorIcon == NULL)
    {
        VFX_OBJ_CREATE(m_editorIcon, VfxImageFrame, this);
        m_editorIcon->bringToFront();
        m_textInput->setMargins(0, 0, EDITOR_ICON_WIDTH, 0);
    }
    m_editorIcon->setImgContent(image);
}


void VappBrwTitleBar::portraitPenDownEffect(void)
{
    m_homePageIcon->setOpacity(0.5f);
    
}

void VappBrwTitleBar::portraitPenUpEffect(void)
{
    m_homePageIcon->setOpacity(1.0f);
    
}

void VappBrwTitleBar::onClickHomePageIcon(VfxObject *obj, VfxId id)
{
    m_homePageIconTap.emit();
}

void VappBrwTitleBar::onClickRightIcon(VfxObject *obj, VfxId id)
{
    m_screenModeIconTap.emit();
}

void VappBrwTitleBar::updateTitleText()
{
    if (m_titleControl == NULL)
    {
        VFX_OBJ_CREATE(m_titleControl, VfxTextFrame, this);
    }
    const S32 left = VCP_BRW_TITLE_BAR_TITLE_MARGIN_HORIZONTAL;
    const S32 top = VCP_BRW_TITLE_BAR_TITLE_MARGIN_TOP;
    const S32 right = getSize().width - VCP_BRW_TITLE_BAR_TITLE_MARGIN_HORIZONTAL;
    const S32 bottom = PORTRAIT_BG_Y - VCP_BRW_TITLE_BAR_TITLE_MARGIN_BOTTOM;
    m_titleControl->setString(getTitleText());
    updateTitleTextFrame(m_titleControl, left, top, right, bottom);
    m_titleControl->setColor(VfxColor(VFX_COLOR_WHITE));
    m_titleControl->setAutoAnimate(VFX_TRUE);
}

VfxWString VappBrwTitleBar::getTitleText()
{
    return m_title;
}

void VappBrwTitleBar::updateTitleTextFrame(VfxTextFrame * textFrame, S32 left, S32 top, S32 right, S32 bottom)
{
    const S32 maxWidth = right - left;
    const S32 centerY = (top + bottom) / 2;
    const S32 maxHeight = bottom - top;
    textFrame->setAnchor(VfxFPoint(0.5f, 0.5f));
    textFrame->setSize(maxWidth, maxHeight);
    textFrame->setPos(getSize().width / 2, centerY);
    textFrame->setMargins(left, 0, getSize().width - right, 0);
    textFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
    VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
    VFX_FRAME_ALIGNER_MODE_SIDE);
    textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    VfxFontDesc font;

	font.size = VFX_FONT_DESC_VF_SIZE(TEXT_FONT_SIZE);
    font.effect |= VFX_FE1_9;
    textFrame->setFont(font);
    textFrame->setAutoFontSize(VFX_TRUE);
}

//#pragma arm section code, rodata

#endif

#endif /* _VAPP_BRW_TITLEBAR_CPP_ */
