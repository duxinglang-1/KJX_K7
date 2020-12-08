/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUVIOCALLY ACKNOWLEDGES AND AGREES
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
 *  vapp_drawer_builder.cpp
 *
 * Project:
 * --------
 *  Launcher
 *
 * Description:
 * ------------
 *  Launcher key mainmenu
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

#include "MMI_features.h"

#include "vcp_include.h"
#include "vapp_launcher_key_mainmenu.h"
#include "vapp_launcher_key_mainmenu_builder.h"
#include "vapp_launcher_key_mainmenu_page_menu.h"
#include "vapp_drawer_shortcut_bar.h" // for vappDrawerGetAppDataCache
#include "vcp_page_menu_util.h"

#include "vapp_launcher_key_mainmenu_gprot.h"
#include "mmi_rp_vapp_key_mainmenu_def.h"

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

extern "C" {
#include "AppMgrSrvGprot.h"
#include "UmSrvGprot.h"
#include "CallLogSrvGprot.h"
#ifdef __MMI_EMAIL__
#include "EmailSrvGprot.h"
#endif // __MMI_EMAIL__
#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif 

}



#ifdef __MMI_TOUCH_SCREEN__
#define __VAPP_KMM_SHOW_UNINSTALL_BTN__
#endif
//#define DRAWER_MEMORY_TEST
//#define DRAWER_MEMORY_TEST_PAGE_COUNT 6
//#define DRAWER_MEMORY_TEST_APP_COUNT_PER_PAGE 12

#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)  || defined(__MMI_MAINLCD_320X240__)
static const VfxS32 DRAWER_CELL_VISIBLE_WIDTH = 59; //60;
static const VfxS32 DRAWER_CELL_VISIBLE_HEIGHT = 67;

// normal icon
static const VfxS32 DRAWER_CELL_ICON_WIDTH = 53;
static const VfxS32 DRAWER_CELL_ICON_HEIGHT = 53;
static const VfxS32 DRAWER_CELL_ICON_OFFSET_X = 3; // (80 - 43) / 2
static const VfxS32 DRAWER_CELL_ICON_OFFSET_Y = 3;

// Highlight icon background
static const VfxS32 KMM_CELL_HIGHLIGHT_ICON_BG_X = 0;
static const VfxS32 KMM_CELL_HIGHLIGHT_ICON_BG_Y = 0;
static const VfxS32 KMM_CELL_HIGHLIGHT_ICON_BG_HIGHT = 59;
static const VfxS32 KMM_CELL_HIGHLIGHT_ICON_BG_WIDTH = 59;

// File icon path size
static const VfxS32 DRAWER_CELL_SMALL_ICON_WIDTH = 29;
static const VfxS32 DRAWER_CELL_SMALL_ICON_HEIGHT = 29;
static const VfxS32 DRAWER_CELL_SMALL_ICON_OFFSET_X = 12;
static const VfxS32 DRAWER_CELL_SMALL_ICON_OFFSET_Y = 12;

// text frame
#if defined(__MMI_MAINLCD_320X240__)
static const VfxS32 DRAWER_CELL_TITLE_BASE_X_MARGIN = 4;
#else
static const VfxS32 DRAWER_CELL_TITLE_BASE_X_MARGIN = 0;
#endif


static const VfxS32 DRAWER_CELL_TITLE_BG_X_MARGIN = 3;

static const VfxS32 DRAWER_CELL_TITLE_OFFSET_X = DRAWER_CELL_TITLE_BASE_X_MARGIN + DRAWER_CELL_TITLE_BG_X_MARGIN;
static const VfxS32 DRAWER_CELL_TITLE_OFFSET_Y = 54;
static const VfxS32 DRAWER_CELL_TITLE_WIDTH = DRAWER_CELL_VISIBLE_WIDTH - 2 * DRAWER_CELL_TITLE_BASE_X_MARGIN - 2 * DRAWER_CELL_TITLE_BG_X_MARGIN;
static const VfxS32 DRAWER_CELL_TITLE_HEIGHT = 13;

static const VfxS32 DRAWER_CELL_TITLE_FONT_SIZE = 11;

// app counter
static const VfxS32 DRAWER_CELL_COUNTER_OFFSET_Y = 6;
static const VfxS32 DRAWER_CELL_COUNTER_3DIGITS_WIDTH = 34;
static const VfxS32 DRAWER_CELL_COUNTER_FONT_SIZE = 12;

static const VfxS32 DRAWER_CELL_UNINSTALL_ICON_POS_X = 34;
static const VfxS32 DRAWER_CELL_UNINSTALL_ICON_POS_Y = 6;

#else // default HVGA 320X480
static const VfxS32 DRAWER_CELL_VISIBLE_WIDTH = 79;//80;
static const VfxS32 DRAWER_CELL_VISIBLE_HEIGHT = 94;

// normal icon
static const VfxS32 DRAWER_CELL_ICON_WIDTH = 70;
static const VfxS32 DRAWER_CELL_ICON_HEIGHT = 70;
static const VfxS32 DRAWER_CELL_ICON_OFFSET_X = 5;
static const VfxS32 DRAWER_CELL_ICON_OFFSET_Y = 8;

// Highlight icon background
static const VfxS32 KMM_CELL_HIGHLIGHT_ICON_BG_X = 1;
static const VfxS32 KMM_CELL_HIGHLIGHT_ICON_BG_Y = 4;
static const VfxS32 KMM_CELL_HIGHLIGHT_ICON_BG_HIGHT = 78;
static const VfxS32 KMM_CELL_HIGHLIGHT_ICON_BG_WIDTH = 78;

// File icon path size
static const VfxS32 DRAWER_CELL_SMALL_ICON_WIDTH = 37;
static const VfxS32 DRAWER_CELL_SMALL_ICON_HEIGHT = 37;
static const VfxS32 DRAWER_CELL_SMALL_ICON_OFFSET_X = 16;
static const VfxS32 DRAWER_CELL_SMALL_ICON_OFFSET_Y = 17;

// text frame
static const VfxS32 DRAWER_CELL_TITLE_BASE_X_MARGIN = 0;

static const VfxS32 DRAWER_CELL_TITLE_BG_X_MARGIN = 3;

static const VfxS32 DRAWER_CELL_TITLE_OFFSET_X = DRAWER_CELL_TITLE_BASE_X_MARGIN + DRAWER_CELL_TITLE_BG_X_MARGIN;
static const VfxS32 DRAWER_CELL_TITLE_OFFSET_Y = 80;
static const VfxS32 DRAWER_CELL_TITLE_WIDTH = DRAWER_CELL_VISIBLE_WIDTH - 2 * DRAWER_CELL_TITLE_BASE_X_MARGIN - 2 * DRAWER_CELL_TITLE_BG_X_MARGIN;
static const VfxS32 DRAWER_CELL_TITLE_HEIGHT = 14;

static const VfxS32 DRAWER_CELL_TITLE_FONT_SIZE = 12; // font size 13 = real size 15

// app counter
static const VfxS32 DRAWER_CELL_COUNTER_OFFSET_Y = 5;
static const VfxS32 DRAWER_CELL_COUNTER_3DIGITS_WIDTH = 42;
static const VfxS32 DRAWER_CELL_COUNTER_FONT_SIZE = 15;

// uninstall icon
static const VfxS32 DRAWER_CELL_UNINSTALL_ICON_POS_X = 48;
static const VfxS32 DRAWER_CELL_UNINSTALL_ICON_POS_Y = 6;

#endif

static const VfxColor DRAWER_CELL_TITLE_COLOR = VFX_COLOR_WHITE;
static VfxU8 g_vapp_key_mainmenu_preinsatll[VAPP_LAUNCHER_KEY_MM_MAX_CELL] = {0};
/*****************************************************************************
 * Class VappKeyMainmenuCell
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappKeyMainmenuCell", VappKeyMainmenuCell, VcpPageMenuCell);

VappKeyMainmenuCell::VappKeyMainmenuCell():
    m_cellCounter(-1),
    m_firstDisplay(VFX_TRUE),
    m_editMode(VFX_FALSE),
    m_isPreinstall(VFX_FALSE),
    m_isAppCounterHidden(VFX_FALSE),
    m_isTextFrameHidden(VFX_FALSE),
    m_isInstalled(VFX_FALSE),
    m_isHighlighted(VFX_FALSE),
	m_isBorderColor(VFX_FALSE),
    m_iconBgFrame(NULL),
    m_iconBgFrameEdit(NULL),
    m_iconFrame(NULL),
    m_smallIconFrame(NULL),
    m_textFrame(NULL),
    m_preinstallFrame(NULL),
    m_appCounterTextFrame(NULL),
    m_appCounterBgFrame(NULL),
    m_appUninstallBtn(NULL),
    m_highlightFrame(NULL),
    m_scrollText(NULL)
{
    memset(m_appName, 0, MMI_APP_NAME_MAX_LEN);
}

VappKeyMainmenuCell::VappKeyMainmenuCell(const VfxImageSrc & image, const VfxWString & title):
    m_cellImage(image),
    m_cellTitle(title),
    m_cellCounter(-1),
    m_firstDisplay(VFX_TRUE),
    m_editMode(VFX_FALSE),
    m_isPreinstall(VFX_FALSE),
    m_isAppCounterHidden(VFX_FALSE),
    m_isTextFrameHidden(VFX_FALSE),
    m_isInstalled(VFX_FALSE),
	m_isBorderColor(VFX_FALSE),
    m_iconBgFrame(NULL),
    m_iconBgFrameEdit(NULL),
    m_iconFrame(NULL),
    m_smallIconFrame(NULL),
    m_textFrame(NULL),
    m_preinstallFrame(NULL),
    m_appCounterTextFrame(NULL),
    m_appCounterBgFrame(NULL),
    m_appUninstallBtn(NULL)
{
    memset(m_appName, 0, MMI_APP_NAME_MAX_LEN);
}

void VappKeyMainmenuCell::setCellAppName(mmi_app_package_name_struct appName)
{
    strncpy(m_appName, appName, MMI_APP_NAME_MAX_LEN - 1);
}

void VappKeyMainmenuCell::getCellAppName(mmi_app_package_name_struct & result)
{
    strncpy(result, m_appName, MMI_APP_NAME_MAX_LEN - 1);
}

void VappKeyMainmenuCell::setEditMode(VfxBool editMode)
{

    m_editMode = editMode;

    updateEditMode(m_editMode);

    setAppCounterHidden(editMode);
}

void VappKeyMainmenuCell::setIsPreinstall(VfxBool isPreinstall)
{
    if (m_isPreinstall != isPreinstall)
    {
        m_isPreinstall = isPreinstall;

        if (m_iconFrame == NULL)
        {
            return;
        }
        
        updateIsPreinstall(m_isPreinstall);
    }
}

VfxBool VappKeyMainmenuCell::getIsPreinstall()
{
	return m_isPreinstall;
}
void VappKeyMainmenuCell::setAppCounter(VfxWString &appCounter)
{
    if (m_cellCounter != appCounter)
    {
        m_cellCounter = appCounter;
        
        if (m_iconFrame == NULL)
        {
            return;
        }
        
        updateAppCounter(m_cellCounter);
    }
}

void VappKeyMainmenuCell::setAppCounterHidden(VfxBool isHidden)
{
    if (m_isAppCounterHidden != isHidden)
    {
        m_isAppCounterHidden = isHidden;

        updateAppCounter(m_cellCounter);
        
        if (m_appCounterBgFrame)
        {
            m_appCounterBgFrame->setHidden(isHidden);
        }
        if (m_appCounterTextFrame)
        {
            m_appCounterTextFrame->setHidden(isHidden);
        }
    }
}

void VappKeyMainmenuCell::setTextFrameHidden(VfxBool isHidden)
{
    if (m_isTextFrameHidden != isHidden)
    {
        m_isTextFrameHidden = isHidden;

        updateTitle(m_cellTitle);
        updateTextFrameHidden(m_isTextFrameHidden);
    }
}

void VappKeyMainmenuCell::setIsInstalled(VfxBool isInstalled)
{
    setIsUnhittable(!isInstalled);

    if (m_isInstalled != isInstalled)
    {
        m_isInstalled = isInstalled;
        
        updateIsInstalled(m_isInstalled);
    }
}
void VappKeyMainmenuCell::setIsBorderColor(VfxBool isBorder)
{
	m_isBorderColor = isBorder;
}
void VappKeyMainmenuCell::setIsHighlighted(VfxBool isHighlighted, VfxBool update)
{
	if(m_isHighlighted != isHighlighted)
	{
		m_isHighlighted = isHighlighted;
		if(update)
		{
			updateHighlightFrame();
			startScroll();
		}
	}
}

void VappKeyMainmenuCell::updateIconImage(const VfxImageSrc & image)
{
    if (m_iconFrame == NULL)
    {
        return;
    }

    VfxBool needResize = VFX_FALSE;
    VfxBool isMRE = VFX_FALSE;
    VfxBool isJava = VFX_FALSE;
    VfxBool isWidget = VFX_FALSE;
    srv_appmgr_app_package_type_enum type = srv_appmgr_get_app_package_type(m_appName);
    if (type == SRV_APPMGR_MRE_APP_PACKAGE_TYPE)
    {
        isMRE = VFX_TRUE;
    }
    else if (type == SRV_APPMGR_JAVA_APP_PACKAGE_TYPE)
    {
        isJava = VFX_TRUE;
    }
#ifdef __GADGET_SUPPORT__
    else if (type == SRV_APPMGR_WIDGET_APP_PACKAGE_TYPE)
    {
        isWidget = VFX_TRUE;
    }
#endif

    if ((isMRE || isJava) && image.getType() != VFX_IMAGE_SRC_TYPE_RES_ID)
    {
        if ( (image.getSize().width > DRAWER_CELL_SMALL_ICON_WIDTH) || 
            (image.getSize().height > DRAWER_CELL_SMALL_ICON_HEIGHT) )
        {
            needResize = VFX_TRUE;
        }
    }

    if (needResize)
    {
        if (m_smallIconFrame == NULL)
        {
            VFX_OBJ_CREATE(m_smallIconFrame, VfxFrame, this);
        }
        m_smallIconFrame->setPos(m_iconFrame->getPos().x + DRAWER_CELL_SMALL_ICON_OFFSET_X,
                m_iconFrame->getPos().y + DRAWER_CELL_SMALL_ICON_OFFSET_Y);
        m_smallIconFrame->setSize(DRAWER_CELL_SMALL_ICON_WIDTH,
                DRAWER_CELL_SMALL_ICON_HEIGHT);
        m_smallIconFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
        m_smallIconFrame->setImgContent(image);
        m_smallIconFrame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_TRANSLUCENT);
    }
    else
    {
        m_iconFrame->setImgContent(image);
    }
}

void VappKeyMainmenuCell::updateTitle(const VfxWString & title)
{
    if (m_isTextFrameHidden)
    {
        return;
    }

    if (m_textFrame == NULL)
    {
        // add text frame
        VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);
        VfxFontDesc fontDesc;
        fontDesc.size = VFX_FONT_DESC_VF_SIZE(DRAWER_CELL_TITLE_FONT_SIZE);
#ifdef __VAPP_KMM_SHOW_MENU_BG__
		if(m_isBorderColor) // for home shortcut
#endif
		{
			fontDesc.effect = VFX_FONT_DESC_EFFECT_BORDER;
		}
        m_textFrame->setFont(fontDesc);
        m_textFrame->setColor(DRAWER_CELL_TITLE_COLOR);
        m_textFrame->setFullLineHeightMode(VFX_TRUE);
        m_textFrame->setAnchor(0.5f, 1.0f);
		m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        m_textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    }
    
    m_textFrame->setString(title);
	VfxS32 border_height = 0;
#ifdef __VAPP_KMM_SHOW_MENU_BG__
	if(m_isBorderColor)
#endif
    {
		border_height = 1;
    }
    m_textFrame->setSize(DRAWER_CELL_TITLE_WIDTH, 0);
    m_textFrame->setPos(DRAWER_CELL_TITLE_OFFSET_X + DRAWER_CELL_TITLE_WIDTH/2, DRAWER_CELL_TITLE_OFFSET_Y + DRAWER_CELL_TITLE_HEIGHT - 1);

}

void VappKeyMainmenuCell::updateIsPreinstall(VfxBool isPreinstall)
{
    if (isPreinstall)
    {
        if (m_preinstallFrame == NULL)
        {
            VFX_OBJ_CREATE(m_preinstallFrame, VfxFrame, this);
            m_preinstallFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_KMM_PREINSTALL_ICON));
            m_preinstallFrame->setSize(DRAWER_CELL_ICON_WIDTH, DRAWER_CELL_ICON_HEIGHT);
            m_preinstallFrame->setPos(DRAWER_CELL_ICON_OFFSET_X, DRAWER_CELL_ICON_OFFSET_Y);
        }
    }
    else
    {
        VFX_OBJ_CLOSE(m_preinstallFrame);
    }
}

void VappKeyMainmenuCell::updateEditMode(VfxBool editMode)
{
    if ((editMode) && (m_isHighlighted))
    {
        if (m_iconBgFrameEdit == NULL)
        {
            // add icon bg frame
            VFX_OBJ_CREATE(m_iconBgFrameEdit, VfxImageFrame, this);
            m_iconBgFrameEdit->setImgContent(VfxImageSrc(IMG_ID_VAPP_KMM_EDITOR_BG) );
#ifdef __MMI_MAINLCD_320X480__
            m_iconBgFrameEdit->setPos(DRAWER_CELL_ICON_OFFSET_X, DRAWER_CELL_ICON_OFFSET_Y);
#else
            m_iconBgFrameEdit->setPos(KMM_CELL_HIGHLIGHT_ICON_BG_X, KMM_CELL_HIGHLIGHT_ICON_BG_Y);
#endif
            m_iconBgFrameEdit->sendToBack();
        }
       // m_iconBgFrameEdit->setHidden(VFX_FALSE);
#ifdef __VAPP_KMM_SHOW_UNINSTALL_BTN__
        if (m_appUninstallBtn)
        {
            m_appUninstallBtn->setHidden(VFX_FALSE);
            m_appUninstallBtn->bringToFront();
        }
#endif
		m_highlightFrame->setHidden(VFX_TRUE);
    }
    else
    {
        if (m_iconBgFrameEdit)
        {
          //  m_iconBgFrameEdit->setHidden(VFX_TRUE);
          VFX_OBJ_CLOSE(m_iconBgFrameEdit);
        }
		if(m_isHighlighted && m_highlightFrame)
		{
			m_highlightFrame->setHidden(VFX_FALSE);
		}
#ifdef __VAPP_KMM_SHOW_UNINSTALL_BTN__

        if (m_appUninstallBtn)
        {
            m_appUninstallBtn->setHidden(VFX_TRUE);
        }
#endif
    }
}

void VappKeyMainmenuCell::updateAppCounter(VfxWString &appCounter)
{
    if (m_isAppCounterHidden)
    {
        return;
    }
    
    if (appCounter.isEmpty() == VFX_FALSE && appCounter != VFX_WSTR("0"))
    {
        if (m_appCounterBgFrame == NULL)
        {
            VFX_OBJ_CREATE(m_appCounterBgFrame, VfxImageFrame, this);
        }
        m_appCounterBgFrame->setHidden(m_isAppCounterHidden);
        m_appCounterBgFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_KMM_APP_COUNTER_BG) );
        m_appCounterBgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_appCounterBgFrame->bringToFront();
        if (appCounter.getLength() < 3)
        {
            m_appCounterBgFrame->setPos(getSize().width - m_appCounterBgFrame->getSize().width, DRAWER_CELL_COUNTER_OFFSET_Y);
        }
        else
        {
            m_appCounterBgFrame->setPos(getSize().width - DRAWER_CELL_COUNTER_3DIGITS_WIDTH, DRAWER_CELL_COUNTER_OFFSET_Y);
            m_appCounterBgFrame->setSize(DRAWER_CELL_COUNTER_3DIGITS_WIDTH, m_appCounterBgFrame->getSize().height);
        }

        if (m_appCounterTextFrame == NULL)
        {
            VFX_OBJ_CREATE(m_appCounterTextFrame, VfxTextFrame, m_appCounterBgFrame);
        }
        m_appCounterTextFrame->setHidden(m_isAppCounterHidden);
        VfxFontDesc fontDesc;
        fontDesc.size = VFX_FONT_DESC_VF_SIZE(DRAWER_CELL_COUNTER_FONT_SIZE);
        m_appCounterTextFrame->setFont(fontDesc);
        m_appCounterTextFrame->setColor(DRAWER_CELL_TITLE_COLOR);
        m_appCounterTextFrame->setPos(m_appCounterBgFrame->getSize().width / 2, m_appCounterBgFrame->getSize().height/ 2);
        m_appCounterTextFrame->setAnchor(0.55f, 0.55f);
        m_appCounterTextFrame->setAutoResized(VFX_TRUE);
        m_appCounterTextFrame->bringToFront();
		m_appCounterTextFrame->setString(appCounter);
    }
    else
    {
        if (m_appCounterTextFrame != NULL)
        {
            VFX_OBJ_CLOSE(m_appCounterTextFrame);
        }
        if (m_appCounterBgFrame != NULL)
        {
            VFX_OBJ_CLOSE(m_appCounterBgFrame);
        }
    }
}

void VappKeyMainmenuCell::updateTextFrameHidden(VfxBool textFrameHidden)
{
    if (m_textFrame)
    {
        m_textFrame->setHidden(textFrameHidden);
    }
}

void VappKeyMainmenuCell::updateIsInstalled(VfxBool isInstalled)
{
#ifdef __VAPP_KMM_SHOW_UNINSTALL_BTN__

    if (isInstalled)
    {
        if (m_appUninstallBtn == NULL)
        {
            VfxImageSrc imgSrc(IMG_ID_VAPP_KMM_APP_UNINSTALL);
            VFX_OBJ_CREATE(m_appUninstallBtn, VcpImageButton, this);
            m_appUninstallBtn->setHidden(VFX_TRUE);
            m_appUninstallBtn->setImage(VcpStateImage(IMG_ID_VAPP_KMM_APP_UNINSTALL));
            m_appUninstallBtn->setPos(DRAWER_CELL_UNINSTALL_ICON_POS_X, DRAWER_CELL_UNINSTALL_ICON_POS_Y);
            m_appUninstallBtn->setSize(imgSrc.getSize());
            m_appUninstallBtn->m_signalClicked.connect(this, &VappKeyMainmenuCell::onUninstallBtnClicked);

            setNeedSetExactPos(VFX_TRUE);
        }
    }
    else
    {
        VFX_OBJ_CLOSE(m_appUninstallBtn);
        
        setNeedSetExactPos(VFX_FALSE);
    }
#endif
}

void VappKeyMainmenuCell::startScroll()
{
	if(m_scrollText)
	{
		m_scrollText->startScroll();
	}
}

void VappKeyMainmenuCell::stopScroll()
{
	if(m_scrollText)
	{
		m_scrollText->stopScroll();
	}
}

void VappKeyMainmenuCell::updateHighlightFrame()
{
	if(m_firstDisplay)
	{
		onCellDisplay();
	}
	else if(m_isHighlighted)
	{
		VFX_OBJ_CREATE(m_highlightFrame, VfxFrame, this);
		m_highlightFrame->setSize(KMM_CELL_HIGHLIGHT_ICON_BG_WIDTH, KMM_CELL_HIGHLIGHT_ICON_BG_HIGHT);
	    m_highlightFrame->setPos(KMM_CELL_HIGHLIGHT_ICON_BG_X ,
								KMM_CELL_HIGHLIGHT_ICON_BG_Y);
		
		m_highlightFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_KMM_HIGHLIGHT_ICON) );
		insertChildFrameBefore(m_iconFrame,m_highlightFrame);
		// change to scrolling text	
		
		VfxSize size = m_textFrame->getFont().measureStr(m_cellTitle);

		if (size.width > DRAWER_CELL_TITLE_WIDTH)
		{
			m_textFrame->setHidden(VFX_TRUE);
	        VFX_OBJ_CREATE(m_scrollText, VcpMarquee, this);
			m_scrollText->setHalign(VcpMarquee::HALIGN_LEFT);
			m_scrollText->setValign(VcpMarquee::VALIGN_CENTER);
			m_scrollText->setSpeed(VcpMarquee::DEFAULT_SPEED / 3);
	        VfxFontDesc fontDesc;
	        fontDesc.size = VFX_FONT_DESC_VF_SIZE(DRAWER_CELL_TITLE_FONT_SIZE);
#ifdef __VAPP_KMM_SHOW_MENU_BG__
			if(m_isBorderColor) // for home shortcut
#endif
			{
				fontDesc.effect = VFX_FONT_DESC_EFFECT_BORDER;
			}
			m_scrollText->setMovableFrame(m_cellTitle, fontDesc);
	        m_scrollText->setTextColor(DRAWER_CELL_TITLE_COLOR);
		    m_scrollText->setSize(DRAWER_CELL_TITLE_WIDTH, m_textFrame->getSize().height);
        	m_scrollText->setPos(DRAWER_CELL_TITLE_OFFSET_X + DRAWER_CELL_TITLE_WIDTH/2, DRAWER_CELL_TITLE_OFFSET_Y+DRAWER_CELL_TITLE_HEIGHT-1);
			m_scrollText->setAnchor(0.5f, 1.0f);
			//m_scrollText->startScroll();   
		}
	}	
	else
	{
		if(m_highlightFrame)
			VFX_OBJ_CLOSE(m_highlightFrame);
		if(m_scrollText)
		{
			VFX_OBJ_CLOSE(m_scrollText);
			m_textFrame->setHidden(VFX_FALSE);
		}
	}
}

void VappKeyMainmenuCell::onUninstallBtnClicked(VfxObject *obj, VfxId id)
{
    vapp_key_mainmenu_uninstall_app(this);
}

VfxBool VappKeyMainmenuCell::isFirstDisplay()
{
    return m_firstDisplay;
}

mmi_ret eventHandler(mmi_event_struct *event)
{
    VappKeyMainmenuCell *cell = (VappKeyMainmenuCell *)event->user_data;

    switch (event->evt_id)
    {
		case EVT_ID_SRV_APPMGR_UPDATE_BADGE:
            {
				srv_appmgr_update_event_struct *evt = (srv_appmgr_update_event_struct*)event;
				if(strncmp(cell->m_appName, evt->app_name, MMI_APP_NAME_MAX_LEN) == 0)
            {
					srv_app_info_struct info;
					mmi_ret result = srv_appmgr_get_app_package_info(cell->m_appName, &info);
					VfxWString badge = VFX_WSTR_MEM(info.badge);
					cell->setAppCounter(badge);
				}
            }
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}
VfxResId vapp_kmm_get_icon_id(mmi_app_package_name_struct appName);
void VappKeyMainmenuCell::onCellDisplay()
{
    if (!m_firstDisplay)
    {
        return;
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MOC", SA_start);
#endif

    m_firstDisplay = VFX_FALSE;

    setHidden(VFX_FALSE);

    if (m_cellImage.isNull() && m_cellTitle.isNull())
    {
        // get app info
        srv_app_info_struct info;
        mmi_ret result = srv_appmgr_get_app_package_info(m_appName, &info);
        VFX_ASSERT(result != MMI_RET_ERR);
        m_cellTitle.loadFromMem(info.string);
        
		if(VFX_WSTR_MEM(info.badge).isEmpty() != VFX_TRUE)
		{
			VfxWString badge = VFX_WSTR_MEM(info.badge);
			setAppCounter(badge);
		}       

        if (info.image.type == MMI_IMAGE_SRC_TYPE_RES_ID)
        {
			// map new image for key launcher 
			VfxResId new_icon = vapp_kmm_get_icon_id(m_appName);
			if(new_icon == 0)
				new_icon = info.image.data.res_id;
			m_cellImage = VfxImageSrc(new_icon);
        }
        else if (info.image.type == MMI_IMAGE_SRC_TYPE_PATH)
        {
			VfxU8 *imageMem = NULL;
			VfxBool isCached = vappDrawerGetAppDataCache(m_appName, &imageMem);
			if(isCached)
			{
				m_cellImage = VfxImageSrc(imageMem);
			}
			else
			{
				VfxWString path;
				path.loadFromMem(info.image.data.path);
				m_cellImage = VfxImageSrc(path);
			}
        }
        else if(info.image.type == MMI_IMAGE_SRC_TYPE_ROM_MEMORY)
        {
        		m_cellImage = VfxImageSrc(info.image.data.image.image_ptr, info.image.data.image.image_len);
        }
        else
        {
            VFX_ASSERT(VFX_FALSE);
        }

    }

    // add icon bg frame
    VFX_OBJ_CREATE(m_iconBgFrame, VfxImageFrame, this);
    m_iconBgFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_KMM_ICON_BG));
    m_iconBgFrame->setPos(DRAWER_CELL_ICON_OFFSET_X, DRAWER_CELL_ICON_OFFSET_Y);

    // add icon frame
    VFX_OBJ_CREATE(m_iconFrame, VfxFrame, this);
    m_iconFrame->setSize(DRAWER_CELL_ICON_WIDTH, DRAWER_CELL_ICON_HEIGHT);
    m_iconFrame->setPos(DRAWER_CELL_ICON_OFFSET_X,
                        DRAWER_CELL_ICON_OFFSET_Y);
    m_iconFrame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_TRANSLUCENT);

    // update state
    updateIconImage(m_cellImage);
    updateTitle(m_cellTitle);
    updateEditMode(m_editMode);
    updateIsPreinstall(m_isPreinstall);
    updateAppCounter(m_cellCounter);
    updateTextFrameHidden(m_isTextFrameHidden);
	updateHighlightFrame();
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MOC", SA_stop);
#endif
}

void VappKeyMainmenuCell::onInit()
{
    VcpPageMenuCell::onInit();

    // init size
    setSize(DRAWER_CELL_VISIBLE_WIDTH, DRAWER_CELL_VISIBLE_HEIGHT);

    // default hidden on creation
    setHidden(VFX_TRUE);

    return;
}

void VappKeyMainmenuCell::onDeinit()
{
	 mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_UPDATE_BADGE, eventHandler, this);
    VcpPageMenuCell::onDeinit();
}

void VappKeyMainmenuCell::registerBadgeEvent()
{
	mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UPDATE_BADGE,  &eventHandler, this);
}

/*****************************************************************************
 * Class VappDrawerBuilder
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappKeyMainmenuBuilder", VappKeyMainmenuBuilder, VfxObject);

VappKeyMainmenuBuilder::VappKeyMainmenuBuilder():
    m_orderData(NULL),
    m_orderDataCount(0)
{
}

void VappKeyMainmenuBuilder::setAppOrderData(mmi_app_package_name_struct orderData[], VfxS32 count)
{
    m_orderData = orderData;
    m_orderDataCount = count;
}

void VappKeyMainmenuBuilder::loadMenu(VappKeyMainmenuPageMenu * menu, VfxBool preInstallChanged)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MLM", SA_start);
#endif

    initFrames(menu, preInstallChanged);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MLM", SA_stop);
#endif
}

void VappKeyMainmenuBuilder::initFrames(VappKeyMainmenuPageMenu * menu, VfxBool preInstallChanged)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MIF", SA_start);
#endif

    mmi_app_package_name_struct *preInstalledAppArray = NULL;
#ifdef __MAUI_SOFTWARE_LA__
		SLA_CustomLogging("MPI", SA_start);
#endif
	U32 preInstalledAppCount = 0;
	if(preInstallChanged)
	{
	    preInstalledAppCount = srv_appmgr_get_app_package_num(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE);
#ifdef __MAUI_SOFTWARE_LA__
		SLA_CustomLogging("MPI", SA_stop);
#endif

		if (preInstalledAppCount)
	    {
	        VFX_SYS_ALLOC_MEM(preInstalledAppArray, sizeof(mmi_app_package_name_struct) * preInstalledAppCount );
	        mmi_ret result;
#ifdef __MAUI_SOFTWARE_LA__
			SLA_CustomLogging("MPA", SA_start);
#endif

	        result = srv_appmgr_get_app_package_list(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE, preInstalledAppArray, preInstalledAppCount);
#ifdef __MAUI_SOFTWARE_LA__
			SLA_CustomLogging("MPA", SA_stop);
#endif

			VFX_ASSERT(result != MMI_RET_ERR);
	    }

	}
    VfxS32 cellIndex = 0;
    VfxS32 pageCount = 0;
#ifdef DRAWER_MEMORY_TEST
    for (VfxS32 j = 0; j < DRAWER_MEMORY_TEST_PAGE_COUNT; ++j)
    for (VfxS32 i = 0; i < DRAWER_MEMORY_TEST_APP_COUNT_PER_PAGE; ++i)
#else
    for (VfxS32 i = 0; i < m_orderDataCount; ++i)
#endif
    {
        if (strncmp(m_orderData[i], "DELETED", MMI_APP_NAME_MAX_LEN) == 0)
        {
            continue;
        }
        if (strncmp(m_orderData[i], "", MMI_APP_NAME_MAX_LEN) == 0)
        {
            if (i > 0 && strncmp(m_orderData[i - 1], "", MMI_APP_NAME_MAX_LEN) == 0)
            {
                break;
            }
            cellIndex = (cellIndex + menu->getMenuItemCountPerPage() - 1) / menu->getMenuItemCountPerPage() * menu->getMenuItemCountPerPage();
            continue;
        }

        VfxBool isPreInstalled = VFX_FALSE;
        if (preInstalledAppArray)
        {
            isPreInstalled = isKmmPreInstalledApp(m_orderData[i], preInstalledAppArray, preInstalledAppCount);
        }
        else if(preInstallChanged)
        {
        	isPreInstalled = VFX_FALSE;
        }
		else
		{
			isPreInstalled = g_vapp_key_mainmenu_preinsatll[cellIndex] ? VFX_TRUE : VFX_FALSE;
		}
        VappKeyMainmenuCell * cell = ::createKmmCell(m_orderData[i], menu->getContainer(), isPreInstalled);
        // reposition if necessary
        cellIndex = repositionFrameIndex(menu, cellIndex);
        menu->setMenuItem(cellIndex, cell);

        ++cellIndex;
        pageCount = VFX_MAX( (cellIndex + menu->getMenuItemCountPerPage() - 1) / menu->getMenuItemCountPerPage(), pageCount);
    }

#ifdef DRAWER_MEMORY_TEST
    menu->setPageCount(DRAWER_MEMORY_TEST_PAGE_COUNT);
#else
    menu->setPageCount(pageCount);
#endif
    
    if (preInstalledAppArray)
    {
        VFX_SYS_FREE_MEM(preInstalledAppArray);
    }
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MIF", SA_stop);
#endif
}

VfxS32 VappKeyMainmenuBuilder::repositionFrameIndex(VappKeyMainmenuPageMenu * menu, VfxS32 index)
{
    if (index < menu->getMaxPageCount() * menu->getMenuItemCountPerPage()  && menu->getMenuItem(index) == NULL)
    {
        return index;
    }

    for (VfxS32 pageIndex = menu->getMaxPageCount() - 1; pageIndex >= 0; --pageIndex)
    {
        for (VfxS32 i = 0; i < menu->getMenuItemCountPerPage(); ++i)
        {
            const VfxS32 index = pageIndex * menu->getMenuItemCountPerPage() + i;
            {
                if (menu->getMenuItem(index) == NULL)
                {
                    return index;
                }
            }
        }
    }
    VFX_ASSERT(VFX_FALSE);
    return index;
}

void VappKeyMainmenuBuilder::saveMenu(VappKeyMainmenuPageMenu * menu)
{
    VfxS32 orderIndex = 0;
    for (VfxS32 i = 0; i < menu->getPageCount(); ++i)
    {
        for (VfxS32 j = 0; j < menu->getMenuItemCountPerPage(); ++j)
        {
            VcpPageMenuCell * cell = menu->getMenuItem(i * menu->getMenuItemCountPerPage() + j);
            if (cell == NULL)
            {
                break;
            }
            VappKeyMainmenuCell * cosmosCell = (VappKeyMainmenuCell *)cell;
            cosmosCell->getCellAppName(m_orderData[orderIndex]);
            ++orderIndex;
        }
        strncpy(m_orderData[orderIndex], "", MMI_APP_NAME_MAX_LEN);
        ++orderIndex;
    }

    // fill the remaining order data with empty string
    for (VfxS32 i = orderIndex; i < m_orderDataCount; ++i)
    {
        strncpy(m_orderData[orderIndex], "", MMI_APP_NAME_MAX_LEN);
    }
}
void VappKeyMainmenuBuilder::savePreinstallInfo(VappKeyMainmenuPageMenu * menu)
{
	VfxS32 orderIndex = 0;
    for (VfxS32 i = 0; i < menu->getPageCount(); ++i)
    {
        for (VfxS32 j = 0; j < menu->getMenuItemCountPerPage(); ++j)
        {
        	orderIndex = i * menu->getMenuItemCountPerPage() + j;
            VcpPageMenuCell * cell = menu->getMenuItem(orderIndex);
            if (cell == NULL)
            {
                g_vapp_key_mainmenu_preinsatll[orderIndex] = 0;
            }
			else
			{
				VappKeyMainmenuCell * mmCell = (VappKeyMainmenuCell *)cell;
				g_vapp_key_mainmenu_preinsatll[orderIndex] = mmCell->getIsPreinstall() ? 1 : 0;
			}
        }
    }
}

#ifdef __MMI_EMAIL__
static void srvEmailAllMsgUnreadNotifyCallback(srv_email_all_msg_unread_notify_type type, U32 num, void *userdata)
{
    vapp_kmm_email_unread_notify_evt_struct evt;
    
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_KMM_EMAIL_UNREAD_NOTIFY);
    MMI_FRM_CB_EMIT_EVENT(&evt);
}

static void srvEmailAppInitStateCallback(
                srv_email_init_state_enum state,
                S32 err_type,
                void *user_data)
{
    if (state == SRV_EMAIL_INIT_STATE_READY)
    {
        vapp_kmm_email_unread_notify_evt_struct evt;
        
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_KMM_EMAIL_UNREAD_NOTIFY);
        MMI_FRM_CB_EMIT_EVENT(&evt);

        srv_email_acct_cache_notify_set(srvEmailAllMsgUnreadNotifyCallback, NULL);
    }
}
#endif // __MMI_EMAIL__

VappKeyMainmenuCell * createKmmCell(mmi_app_package_name_struct & appName, VfxObject * parent, VfxBool preinstall)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MCC", SA_start);
#endif
    VappKeyMainmenuCell * cell;
    VFX_OBJ_CREATE(cell, VappKeyMainmenuCell, parent);
    cell->setCellAppName(appName);
    cell->setIsPreinstall(preinstall);
    cell->setHidden(VFX_TRUE);
	//mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UPDATE_BADGE,  &eventHandler, cell);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MCC", SA_stop);
#endif
    return cell;
}

VfxBool isKmmPreInstalledApp(mmi_app_package_name_struct appName, mmi_app_package_name_struct preInstalledApp[], VfxU32 preInstalledAppCount)
{
    if (strncmp(appName, "mre", 3) != 0)
    {
        return VFX_FALSE;
    }
    for (VfxU32 i = 0; i < preInstalledAppCount; ++i)
    {
        if (strncmp(appName, preInstalledApp[i], MMI_APP_NAME_MAX_LEN) == 0)
        {
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

VfxBool isKmmInstalledApp(mmi_app_package_name_struct appName, mmi_app_package_name_struct installedApp[], VfxU32 installedAppCount)
{
    for (VfxU32 i = 0; i < installedAppCount; ++i)
    {
        if (strncmp(appName, installedApp[i], MMI_APP_NAME_MAX_LEN) == 0)
        {
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

#include "vapp_launcher_key_mainmenu_icons_table.h"
VfxResId vapp_kmm_get_icon_id(mmi_app_package_name_struct appName)
{
	VfxResId new_icon = 0;
	for(VfxS32 index = 0; index < vappKmmMapTableCount; index ++)
	{
		if(strncmp(appName, vappkeyMainmenuMapTAble[index].app_name,MMI_APP_NAME_MAX_LEN) == 0)
		{
			new_icon = vappkeyMainmenuMapTAble[index].image_icon;
			break;
		}
	}
	return new_icon;
}

