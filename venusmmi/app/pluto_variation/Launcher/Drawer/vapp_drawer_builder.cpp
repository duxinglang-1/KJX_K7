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
 *  vapp_drawer_builder.cpp
 *
 * Project:
 * --------
 *  Launcher
 *
 * Description:
 * ------------
 *  Launcher drawer
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

#include "vrt_datatype.h"
#include "vrt_system.h"

#include "vfx_container.h"
#include "vfx_object.h"

#include "vcp_include.h"
#include "vapp_drawer_gprot.h"
#include "vapp_drawer.h"
#include "vapp_drawer_builder.h"
#include "vapp_drawer_page_menu.h"
#include "vapp_drawer_shortcut_bar.h" // for vappDrawerGetAppDataCache
#include "vcp_page_menu_util.h"
#include "mmi_rp_vapp_drawer_def.h"

extern "C"
{
#include "AppMgrSrvGprot.h"
}

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif 


//#define DRAWER_MEMORY_TEST
//#define DRAWER_MEMORY_TEST_PAGE_COUNT 6
//#define DRAWER_MEMORY_TEST_APP_COUNT_PER_PAGE 12

// cell content layout
#if defined(__MMI_MAINLCD_480X800__)
static const VfxS32 DRAWER_CELL_VISIBLE_WIDTH = 120;
static const VfxS32 DRAWER_CELL_VISIBLE_HEIGHT = 122;

static const VfxS32 DRAWER_CELL_APP_ICON_WIDTH = 72;
static const VfxS32 DRAWER_CELL_APP_ICON_HEIGHT = 72;
static const VfxS32 DRAWER_CELL_APP_ICON_POS_X = (DRAWER_CELL_VISIBLE_WIDTH - DRAWER_CELL_APP_ICON_WIDTH) / 2;
static const VfxS32 DRAWER_CELL_APP_ICON_POS_Y = 11;

static const VfxS32 DRAWER_CELL_ICON_BG_SHADOW_OFFSET_X = 10; // (80 - ??) / 2
static const VfxS32 DRAWER_CELL_ICON_BG_SHADOW_OFFSET_Y = 2;

static const VfxS32 DRAWER_CELL_SMALL_ICON_WIDTH = 26;
static const VfxS32 DRAWER_CELL_SMALL_ICON_HEIGHT = 26;
static const VfxS32 DRAWER_CELL_SMALL_ICON_OFFSET_X = 39 + 3;
static const VfxS32 DRAWER_CELL_SMALL_ICON_OFFSET_Y = 40 + 3;

static const VfxS32 DRAWER_CELL_TITLE_BASE_X_MARGIN = 2;

static const VfxS32 DRAWER_CELL_TITLE_BG_OFFSET_X = DRAWER_CELL_TITLE_BASE_X_MARGIN;
static const VfxS32 DRAWER_CELL_TITLE_BG_OFFSET_Y = 88;
static const VfxS32 DRAWER_CELL_TITLE_BG_WIDTH = DRAWER_CELL_VISIBLE_WIDTH - 2 * DRAWER_CELL_TITLE_BASE_X_MARGIN;
static const VfxS32 DRAWER_CELL_TITLE_BG_HEIGHT = 23 + 3 * 2;

static const VfxS32 DRAWER_CELL_TITLE_BG_X_MARGIN = 8;

static const VfxS32 DRAWER_CELL_TITLE_OFFSET_X = DRAWER_CELL_TITLE_BASE_X_MARGIN + DRAWER_CELL_TITLE_BG_X_MARGIN;
static const VfxS32 DRAWER_CELL_TITLE_OFFSET_Y = 94;
static const VfxS32 DRAWER_CELL_TITLE_WIDTH = DRAWER_CELL_VISIBLE_WIDTH - 2 * DRAWER_CELL_TITLE_BASE_X_MARGIN - 2 * DRAWER_CELL_TITLE_BG_X_MARGIN;
static const VfxS32 DRAWER_CELL_TITLE_HEIGHT = 23;

static const VfxS32 DRAWER_CELL_TITLE_FONT_SIZE = 19; // font size 21 = real size 23

static const VfxS32 DRAWER_CELL_BADGE_OFFSET_Y = 6;
static const VfxS32 DRAWER_CELL_BADGE_FONT_SIZE = 23;

static const VfxS32 DRAWER_CELL_UNINSTALL_ICON_POS_X = 48;
static const VfxS32 DRAWER_CELL_UNINSTALL_ICON_POS_Y = 6;

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
static const VfxS32 DRAWER_CELL_VISIBLE_WIDTH = 80;
#if defined(__MMI_MAINLCD_240X320__)
static const VfxS32 DRAWER_CELL_VISIBLE_HEIGHT = 73 + 1;
#else
static const VfxS32 DRAWER_CELL_VISIBLE_HEIGHT = 75 + 1;
#endif

static const VfxS32 DRAWER_CELL_APP_ICON_WIDTH = 38;
static const VfxS32 DRAWER_CELL_APP_ICON_HEIGHT = 38;
static const VfxS32 DRAWER_CELL_APP_ICON_POS_X = (DRAWER_CELL_VISIBLE_WIDTH - DRAWER_CELL_APP_ICON_WIDTH) / 2;
static const VfxS32 DRAWER_CELL_APP_ICON_POS_Y = 10;

static const VfxS32 DRAWER_CELL_ICON_BG_SHADOW_OFFSET_X = 10; // (80 - 60) / 2
static const VfxS32 DRAWER_CELL_ICON_BG_SHADOW_OFFSET_Y = 2;

static const VfxS32 DRAWER_CELL_SMALL_ICON_WIDTH = 12;
static const VfxS32 DRAWER_CELL_SMALL_ICON_HEIGHT = 12;
static const VfxS32 DRAWER_CELL_SMALL_ICON_OFFSET_X = 22;
static const VfxS32 DRAWER_CELL_SMALL_ICON_OFFSET_Y = 22;

static const VfxS32 DRAWER_CELL_TITLE_BASE_X_MARGIN = 0;

static const VfxS32 DRAWER_CELL_TITLE_BG_OFFSET_X = DRAWER_CELL_TITLE_BASE_X_MARGIN;
static const VfxS32 DRAWER_CELL_TITLE_BG_OFFSET_Y = 50;
static const VfxS32 DRAWER_CELL_TITLE_BG_WIDTH = DRAWER_CELL_VISIBLE_WIDTH - 2 * DRAWER_CELL_TITLE_BASE_X_MARGIN;
static const VfxS32 DRAWER_CELL_TITLE_BG_HEIGHT = 16;

static const VfxS32 DRAWER_CELL_TITLE_BG_X_MARGIN = 3;

static const VfxS32 DRAWER_CELL_TITLE_OFFSET_X = DRAWER_CELL_TITLE_BASE_X_MARGIN + DRAWER_CELL_TITLE_BG_X_MARGIN;
static const VfxS32 DRAWER_CELL_TITLE_OFFSET_Y = 52;
static const VfxS32 DRAWER_CELL_TITLE_WIDTH = DRAWER_CELL_VISIBLE_WIDTH - 2 * DRAWER_CELL_TITLE_BASE_X_MARGIN - 2 * DRAWER_CELL_TITLE_BG_X_MARGIN;
static const VfxS32 DRAWER_CELL_TITLE_HEIGHT = 14;

static const VfxS32 DRAWER_CELL_TITLE_FONT_SIZE = 11; // font size 11 = real size 12

static const VfxS32 DRAWER_CELL_BADGE_OFFSET_Y = 6;
static const VfxS32 DRAWER_CELL_BADGE_FONT_SIZE = 12;

static const VfxS32 DRAWER_CELL_UNINSTALL_ICON_POS_X = 48;
static const VfxS32 DRAWER_CELL_UNINSTALL_ICON_POS_Y = 6;

#else // default HVGA 320X480
static const VfxS32 DRAWER_CELL_VISIBLE_WIDTH = 80;
static const VfxS32 DRAWER_CELL_VISIBLE_HEIGHT = 90;

static const VfxS32 DRAWER_CELL_APP_ICON_WIDTH = 48;
static const VfxS32 DRAWER_CELL_APP_ICON_HEIGHT = 48;
static const VfxS32 DRAWER_CELL_APP_ICON_POS_X = (DRAWER_CELL_VISIBLE_WIDTH - DRAWER_CELL_APP_ICON_WIDTH) / 2;
static const VfxS32 DRAWER_CELL_APP_ICON_POS_Y = 13;

static const VfxS32 DRAWER_CELL_ICON_BG_SHADOW_OFFSET_X = 5; // (80 - ??) / 2
static const VfxS32 DRAWER_CELL_ICON_BG_SHADOW_OFFSET_Y = 2;

static const VfxS32 DRAWER_CELL_SMALL_ICON_WIDTH = 18;
static const VfxS32 DRAWER_CELL_SMALL_ICON_HEIGHT = 18;
static const VfxS32 DRAWER_CELL_SMALL_ICON_OFFSET_X = 26;
static const VfxS32 DRAWER_CELL_SMALL_ICON_OFFSET_Y = 26;

static const VfxS32 DRAWER_CELL_TITLE_BASE_X_MARGIN = 0;

static const VfxS32 DRAWER_CELL_TITLE_BG_OFFSET_X = DRAWER_CELL_TITLE_BASE_X_MARGIN;
static const VfxS32 DRAWER_CELL_TITLE_BG_OFFSET_Y = 65;
static const VfxS32 DRAWER_CELL_TITLE_BG_WIDTH = DRAWER_CELL_VISIBLE_WIDTH - 2 * DRAWER_CELL_TITLE_BASE_X_MARGIN;
static const VfxS32 DRAWER_CELL_TITLE_BG_HEIGHT = 19;

static const VfxS32 DRAWER_CELL_TITLE_BG_X_MARGIN = 3;

static const VfxS32 DRAWER_CELL_TITLE_OFFSET_X = DRAWER_CELL_TITLE_BASE_X_MARGIN + DRAWER_CELL_TITLE_BG_X_MARGIN;
static const VfxS32 DRAWER_CELL_TITLE_OFFSET_Y = 68;
static const VfxS32 DRAWER_CELL_TITLE_WIDTH = DRAWER_CELL_VISIBLE_WIDTH - 2 * DRAWER_CELL_TITLE_BASE_X_MARGIN - 2 * DRAWER_CELL_TITLE_BG_X_MARGIN;
static const VfxS32 DRAWER_CELL_TITLE_HEIGHT = 15;

static const VfxS32 DRAWER_CELL_TITLE_FONT_SIZE = 12; // font size 13 = real size 15

static const VfxS32 DRAWER_CELL_BADGE_OFFSET_Y = 5;
static const VfxS32 DRAWER_CELL_BADGE_FONT_SIZE = 15;

static const VfxS32 DRAWER_CELL_UNINSTALL_ICON_POS_X = 48;
static const VfxS32 DRAWER_CELL_UNINSTALL_ICON_POS_Y = 6;

#endif

static const VfxS32 DRAWER_CELL_LIST_CNTX_MEMORY_SIZE = 5 * 1024;


/*****************************************************************************
 * Local Variable
 *****************************************************************************/

static VfxU8 s_vappDrawerCellListCntxMemPool[DRAWER_CELL_LIST_CNTX_MEMORY_SIZE];


/*****************************************************************************
 * Class VappDrawerCellStableFrame
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappDrawerCellStableFrame", VappDrawerCellStableFrame, VfxFrame);

VappDrawerCellStableFrame::VappDrawerCellStableFrame(mmi_app_package_name_struct *appPackageName, VfxImageSrc *appImage, VfxWString *appString) :
    m_appPackageName(appPackageName),
    m_appImage(appImage),
    m_appString(appString),
    m_appStringWidth(-1),
    m_onBottomBar(VFX_FALSE),
    m_isPreinstall(VFX_FALSE),
    m_isTextFrameHidden(VFX_FALSE),
    m_editMode(VFX_FALSE)
{
}

void VappDrawerCellStableFrame::updateOnBottomBar(VfxBool onBottomBar)
{
    if (m_onBottomBar != onBottomBar)
    {
        m_onBottomBar = onBottomBar;

        if (m_isTextFrameHidden)
        {
            return;
        }
        
        invalidate();
    }
}

void VappDrawerCellStableFrame::updateIsPreinstall(VfxBool isPreinstall)
{
    if (m_isPreinstall != isPreinstall)
    {
        m_isPreinstall = isPreinstall;

        invalidate();
    }
}

void VappDrawerCellStableFrame::updateTextFrameHidden(VfxBool isTextFrameHidden)
{
    if (m_isTextFrameHidden != isTextFrameHidden)
    {
        m_isTextFrameHidden = isTextFrameHidden;

        invalidate();
    }
}

void VappDrawerCellStableFrame::updateEditMode(VfxBool editMode)
{
    if (m_editMode != editMode)
    {
        m_editMode = editMode;

        invalidate();
    }
}

void VappDrawerCellStableFrame::onDraw(VfxDrawContext &dc)
{
    drawIcon(dc);

    drawTitle(dc);
}

void VappDrawerCellStableFrame::drawIcon(VfxDrawContext &dc)
{
    if (m_editMode)
    {
        // Draw app icon shadow
        dc.drawImageFromRes(DRAWER_CELL_ICON_BG_SHADOW_OFFSET_X,
                            DRAWER_CELL_ICON_BG_SHADOW_OFFSET_Y,
                            IMG_ID_VAPP_DRAWER_ICON_SHADOW);
    }
    
    // Draw app icon
    VfxBool isSmallIcon = VFX_FALSE;
    VfxBool isMRE = VFX_FALSE;
    VfxBool isJava = VFX_FALSE;
    VfxBool isWidget = VFX_FALSE;
    srv_appmgr_app_package_type_enum type = srv_appmgr_get_app_package_type(*m_appPackageName);
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

    if (isMRE || isJava)
    {
        if ((m_appImage->getSize().width < DRAWER_CELL_APP_ICON_WIDTH / 2) &&
            (m_appImage->getSize().height < DRAWER_CELL_APP_ICON_HEIGHT / 2))
        {
            isSmallIcon = VFX_TRUE;
        }
    }

    if (isSmallIcon)
    {
        if (isMRE)
        {
            dc.drawImageFromRes(DRAWER_CELL_APP_ICON_POS_X,
                                DRAWER_CELL_APP_ICON_POS_Y,
                                IMG_ID_VAPP_DRAWER_ICON_MRE_RESIZE);
        }
        else if (isJava)
        {
            dc.drawImageFromRes(DRAWER_CELL_APP_ICON_POS_X,
                                DRAWER_CELL_APP_ICON_POS_Y,
                                IMG_ID_VAPP_DRAWER_ICON_JAVA_RESIZE);
        }

        VfxRect imageRect(DRAWER_CELL_APP_ICON_POS_X + DRAWER_CELL_SMALL_ICON_OFFSET_X,
                          DRAWER_CELL_APP_ICON_POS_Y + DRAWER_CELL_SMALL_ICON_OFFSET_Y,
                          DRAWER_CELL_SMALL_ICON_WIDTH,
                          DRAWER_CELL_SMALL_ICON_HEIGHT);
        dc.drawResizedImage(imageRect, *m_appImage);
    }
    else
    {
        if (isMRE || isWidget || isJava)
        {
            VfxRect imageRect(DRAWER_CELL_APP_ICON_POS_X,
                              DRAWER_CELL_APP_ICON_POS_Y,
                              DRAWER_CELL_APP_ICON_WIDTH,
                              DRAWER_CELL_APP_ICON_HEIGHT);
            dc.drawResizedImage(imageRect, *m_appImage);
        }
        else
        {
            dc.drawImage(DRAWER_CELL_APP_ICON_POS_X,
                         DRAWER_CELL_APP_ICON_POS_Y,
                         *m_appImage);
        }
    }

    if (m_isPreinstall)
    {
        // Draw preinstall image
        dc.drawImageFromRes(DRAWER_CELL_APP_ICON_POS_X,
                            DRAWER_CELL_APP_ICON_POS_Y,
                            IMG_ID_VAPP_DRAWER_ICON_PREINSTALL_APP);
    }
}

void VappDrawerCellStableFrame::drawTitle(VfxDrawContext &dc)
{
    if (!m_isTextFrameHidden)
    {
        VfxFontDesc fontDesc;
        fontDesc.size = VFX_FONT_DESC_VF_SIZE(DRAWER_CELL_TITLE_FONT_SIZE);
        dc.setFont(fontDesc);
        dc.setFillColor(VFX_COLOR_WHITE);

        if (m_appStringWidth == -1)
        {
            m_appStringWidth = fontDesc.measureStr(*m_appString).width;
        }
        
        vrt_text_dir_type_enum dir = vrt_sys_get_text_dir();
        
        if (m_appStringWidth <= DRAWER_CELL_TITLE_WIDTH)
        {
            if (m_onBottomBar)
            {
                VfxRect imageRect(DRAWER_CELL_TITLE_BG_OFFSET_X + (DRAWER_CELL_TITLE_WIDTH - m_appStringWidth) / 2,
                                  DRAWER_CELL_TITLE_BG_OFFSET_Y,
                                  m_appStringWidth + DRAWER_CELL_TITLE_BG_X_MARGIN * 2,
                                  DRAWER_CELL_TITLE_BG_HEIGHT);
                dc.drawResizedImageFromRes(imageRect, IMG_ID_VAPP_DRAWER_FONT_BG);
            }
            
            if (dir == MG_TEXT_DIR_TYPE_L2R)
            {
                dc.drawText(DRAWER_CELL_TITLE_OFFSET_X + (DRAWER_CELL_TITLE_WIDTH - m_appStringWidth) / 2,
                            DRAWER_CELL_TITLE_OFFSET_Y,
                            *m_appString);
            }
            else
            {
                dc.drawText((DRAWER_CELL_VISIBLE_WIDTH - 1) - (DRAWER_CELL_TITLE_OFFSET_X + (DRAWER_CELL_TITLE_WIDTH - m_appStringWidth) / 2),
                            DRAWER_CELL_TITLE_OFFSET_Y,
                            *m_appString);
            }
        }
        else
        {
            if (m_onBottomBar)
            {
                VfxRect imageRect(DRAWER_CELL_TITLE_BG_OFFSET_X,
                                  DRAWER_CELL_TITLE_BG_OFFSET_Y,
                                  DRAWER_CELL_TITLE_BG_WIDTH,
                                  DRAWER_CELL_TITLE_BG_HEIGHT);
                dc.drawResizedImageFromRes(imageRect, IMG_ID_VAPP_DRAWER_FONT_BG);
            }
            
            dc.setEllipsis(VFX_WSTR("..."));
            if (dir == MG_TEXT_DIR_TYPE_L2R)
            {
                dc.drawTextTruncated(DRAWER_CELL_TITLE_OFFSET_X,
                                     DRAWER_CELL_TITLE_OFFSET_Y,
                                     *m_appString,
                                     DRAWER_CELL_TITLE_WIDTH);
            }
            else
            {
                dc.drawTextTruncated((DRAWER_CELL_VISIBLE_WIDTH - 1) - DRAWER_CELL_TITLE_OFFSET_X,
                                     DRAWER_CELL_TITLE_OFFSET_Y,
                                     *m_appString,
                                     DRAWER_CELL_TITLE_WIDTH);
            }
        }
    }
}


/*****************************************************************************
 * Class VappDrawerCell
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappDrawerCell", VappDrawerCell, VcpPageMenuCell);

VfxContext *VappDrawerCell::s_cellListCntx = NULL;
VfxList <VappDrawerCell *> VappDrawerCell::s_cellList;

VappDrawerCell::VappDrawerCell():
    m_firstDisplay(VFX_TRUE),
    m_onBottomBar(VFX_FALSE),
    m_editMode(VFX_FALSE),
    m_isPreinstall(VFX_FALSE),
    m_isBadgeHidden(VFX_FALSE),
    m_isTextFrameHidden(VFX_FALSE),
    m_isInstalled(VFX_FALSE),
    m_stableFrameContainer(NULL),
    m_appUninstallBtn(NULL),
    m_badgeBgFrame(NULL),
    m_badgeTextFrame(NULL)
{
    memset(m_appName, 0, MMI_APP_NAME_MAX_LEN);
    memset(m_cellBadge, 0, sizeof(m_cellBadge));
}

VappDrawerCell::VappDrawerCell(const VfxImageSrc & image, const VfxWString & title):
    m_cellImage(image),
    m_cellTitle(title),
    m_firstDisplay(VFX_TRUE),
    m_onBottomBar(VFX_FALSE),
    m_editMode(VFX_FALSE),
    m_isPreinstall(VFX_FALSE),
    m_isBadgeHidden(VFX_FALSE),
    m_isTextFrameHidden(VFX_FALSE),
    m_isInstalled(VFX_FALSE),
    m_stableFrameContainer(NULL),
    m_appUninstallBtn(NULL),
    m_badgeBgFrame(NULL),
    m_badgeTextFrame(NULL)
{
    memset(m_appName, 0, MMI_APP_NAME_MAX_LEN);
    memset(m_cellBadge, 0, sizeof(m_cellBadge));
}

void VappDrawerCell::setCellAppName(mmi_app_package_name_struct appName)
{
    strncpy(m_appName, appName, MMI_APP_NAME_MAX_LEN - 1);
}

void VappDrawerCell::getCellAppName(mmi_app_package_name_struct & result)
{
    strncpy(result, m_appName, MMI_APP_NAME_MAX_LEN - 1);
}

void VappDrawerCell::setOnBottomBar(VfxBool onBottomBar)
{
    if (m_onBottomBar != onBottomBar)
    {
        m_onBottomBar = onBottomBar;

        if (m_stableFrameContainer == NULL)
        {
            return;
        }

        m_stableFrameContainer->updateOnBottomBar(m_onBottomBar);
    }
}

void VappDrawerCell::setEditMode(VfxBool editMode)
{
    if (m_editMode != editMode)
    {
        m_editMode = editMode;

        if (m_stableFrameContainer == NULL)
        {
            return;
        }
        
        updateEditMode(m_editMode);
    }
    
    setBadgeHidden(editMode);
}

void VappDrawerCell::setIsPreinstall(VfxBool isPreinstall)
{
    if (m_isPreinstall != isPreinstall)
    {
        m_isPreinstall = isPreinstall;

        if (m_stableFrameContainer == NULL)
        {
            return;
        }
        
        m_stableFrameContainer->updateIsPreinstall(m_isPreinstall);
    }
}

void VappDrawerCell::setBadge(VfxWChar *badge)
{
    memcpy(m_cellBadge, badge, sizeof(m_cellBadge));
    
    if (m_stableFrameContainer == NULL)
    {
        return;
    }
    
    updateBadge();
}

void VappDrawerCell::setBadgeHidden(VfxBool isHidden)
{
    if (m_isBadgeHidden != isHidden)
    {
        m_isBadgeHidden = isHidden;

        updateBadge();
        
        if (m_badgeBgFrame)
        {
            m_badgeBgFrame->setHidden(isHidden);
        }
        if (m_badgeTextFrame)
        {
            m_badgeTextFrame->setHidden(isHidden);
        }
    }
}

void VappDrawerCell::setTextFrameHidden(VfxBool isHidden)
{
    if (isHidden)
    {
        setSize(DRAWER_CELL_VISIBLE_WIDTH, DRAWER_CELL_TITLE_OFFSET_Y);
    }

    if (m_isTextFrameHidden != isHidden)
    {
        m_isTextFrameHidden = isHidden;

        if (m_stableFrameContainer == NULL)
        {
            return;
        }
        
        m_stableFrameContainer->updateOnBottomBar(m_onBottomBar);
        m_stableFrameContainer->updateTextFrameHidden(m_isTextFrameHidden);
    }
}

void VappDrawerCell::setIsInstalled(VfxBool isInstalled)
{
    setIsUnhittable(!isInstalled);

    if (m_isInstalled != isInstalled)
    {
        m_isInstalled = isInstalled;
        
        updateIsInstalled(m_isInstalled);
    }
}

void VappDrawerCell::updateEditMode(VfxBool editMode)
{
    if (m_stableFrameContainer == NULL)
    {
        return;
    }
    m_stableFrameContainer->updateEditMode(editMode);
    
    if (editMode)
    {
        if (m_appUninstallBtn)
        {
            m_appUninstallBtn->setHidden(VFX_FALSE);
            m_appUninstallBtn->bringToFront();
        }
    }
    else
    {
        if (m_appUninstallBtn)
        {
            m_appUninstallBtn->setHidden(VFX_TRUE);
        }
    }

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    if (strncmp(m_appName, "native.mtk.desktop", MMI_APP_NAME_MAX_LEN) == 0)
    {
        if (editMode)
        {
            m_stableFrameContainer->setOpacity(0.3f);
        }
        else
        {
            m_stableFrameContainer->setOpacity(1.0f);
        }
    }
    VfxAutoAnimate::commit();
}

void VappDrawerCell::updateBadge()
{
    if (m_isBadgeHidden)
    {
        return;
    }
    
    VfxBool isCacheModeFreeze = VFX_FALSE;
    if (getCacheMode() == VFX_CACHE_MODE_FREEZE)
    {
        isCacheModeFreeze = VFX_TRUE;
        setCacheMode(VFX_CACHE_MODE_AUTO);
    }
    
    if (!(m_cellBadge[0] == 0 && m_cellBadge[1] == 0))
    {
        // Badge background
        VfxImageSrc badgeBg(IMG_ID_VAPP_DRAWER_ICON_BADGE_BG);
        if (m_badgeBgFrame == NULL)
        {
            VFX_OBJ_CREATE(m_badgeBgFrame, VfxImageFrame, this);
            m_badgeBgFrame->setImgContent(badgeBg);
            m_badgeBgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
            m_badgeBgFrame->bringToFront();
        }
        VfxFontDesc fontDesc;
        fontDesc.size = VFX_FONT_DESC_VF_SIZE(DRAWER_CELL_BADGE_FONT_SIZE);
        m_badgeBgFrame->setSize(VFX_MAX(fontDesc.measureStr(m_cellBadge).width + badgeBg.getSize().width / 2, badgeBg.getSize().width),
                                badgeBg.getSize().height);
        m_badgeBgFrame->setPos(getSize().width - m_badgeBgFrame->getSize().width, DRAWER_CELL_BADGE_OFFSET_Y);
        m_badgeBgFrame->setHidden(m_isBadgeHidden);
    
        // Badge text
        if (m_badgeTextFrame == NULL)
        {
            VFX_OBJ_CREATE(m_badgeTextFrame, VfxTextFrame, m_badgeBgFrame);
            m_badgeTextFrame->setFont(fontDesc);
            m_badgeTextFrame->setColor(VFX_COLOR_WHITE);
            m_badgeTextFrame->setAnchor(0.5f, 0.55f);
            m_badgeTextFrame->setAutoResized(VFX_TRUE);
            m_badgeTextFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        }
        VfxWString badgeText;
        m_badgeTextFrame->setString(badgeText.loadFromMem(m_cellBadge));
        m_badgeTextFrame->setPos(m_badgeBgFrame->getSize().width / 2, m_badgeBgFrame->getSize().height / 2);
        m_badgeTextFrame->setHidden(m_isBadgeHidden);
    }
    else
    {
        if (m_badgeTextFrame != NULL)
        {
            VFX_OBJ_CLOSE(m_badgeTextFrame);
        }
        if (m_badgeBgFrame != NULL)
        {
            VFX_OBJ_CLOSE(m_badgeBgFrame);
        }
    }
    
    if (isCacheModeFreeze)
    {
        setCacheMode(VFX_CACHE_MODE_FREEZE);
    }
}

void VappDrawerCell::updateIsInstalled(VfxBool isInstalled)
{
    if (isInstalled)
    {
        if (m_appUninstallBtn == NULL)
        {
            VfxImageSrc imgSrc(IMG_ID_VAPP_DRAWER_APP_UNINSTALL);
            VFX_OBJ_CREATE(m_appUninstallBtn, VcpImageButton, this);
            m_appUninstallBtn->setHidden(VFX_TRUE);
            m_appUninstallBtn->setImage(VcpStateImage(IMG_ID_VAPP_DRAWER_APP_UNINSTALL));
            m_appUninstallBtn->setPos(DRAWER_CELL_UNINSTALL_ICON_POS_X, DRAWER_CELL_UNINSTALL_ICON_POS_Y);
            m_appUninstallBtn->setSize(imgSrc.getSize());
            m_appUninstallBtn->m_signalClicked.connect(this, &VappDrawerCell::onUninstallBtnClicked);

            setNeedSetExactPos(VFX_TRUE);
        }
    }
    else
    {
        VFX_OBJ_CLOSE(m_appUninstallBtn);
        
        setNeedSetExactPos(VFX_FALSE);
    }
}

void VappDrawerCell::onUninstallBtnClicked(VfxObject *obj, VfxId id)
{
    vapp_drawer_uninstall_app(this);
}

VfxBool VappDrawerCell::isFirstDisplay()
{
    return m_firstDisplay;
}

mmi_ret VappDrawerCell::eventHandler(mmi_event_struct *event)
{
    switch (event->evt_id)
    {
        // Update badge info
        case EVT_ID_SRV_APPMGR_UPDATE_BADGE:
        {
        #ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("MEH", SA_start);
        #endif
            
            srv_appmgr_update_event_struct *updateEvt = (srv_appmgr_update_event_struct *)event;
            srv_app_info_struct info;
            mmi_ret result = srv_appmgr_get_app_package_info(updateEvt->app_name, &info);
            VFX_ASSERT(result != MMI_RET_ERR);
            
        #ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("MEH", SA_stop);
        #endif
            
            for (VfxList <VappDrawerCell *>::It i = s_cellList.begin(); !i.isNull(); ++i)
            {
                mmi_app_package_name_struct cellAppName;
                (*i)->getCellAppName(cellAppName);
                if (strncmp(updateEvt->app_name, cellAppName, MMI_APP_NAME_MAX_LEN) == 0)
                {
                    (*i)->setBadge(info.badge);
                }
            }
            
            break;
        }
            
        default:
            break;
    }
    
    return MMI_RET_OK;
}

void VappDrawerCell::onCellDisplay()
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
        
        VfxU8 *imageMem = NULL;
        VfxBool isCached = vappDrawerGetAppDataCache(m_appName, &imageMem);
        m_cellImage = VfxImageSrc(imageMem);
        
        if (!isCached)
        {
            if (info.image.type == MMI_IMAGE_SRC_TYPE_RES_ID)
            {
                m_cellImage = VfxImageSrc(info.image.data.res_id);
            }
            else if(info.image.type == MMI_IMAGE_SRC_TYPE_ROM_MEMORY)
            {
                m_cellImage = VfxImageSrc(info.image.data.image.image_ptr, info.image.data.image.image_len);
            }
            else if (info.image.type == MMI_IMAGE_SRC_TYPE_PATH)
            {
                VfxWString path;
                path.loadFromMem(info.image.data.path);
                m_cellImage = VfxImageSrc(path);
            }
            else if (info.image.type == MMI_IMAGE_SRC_TYPE_NULL)
            {
                m_cellImage = VfxImageSrc(IMG_ID_VAPP_DRAWER_ICON_HOME);
            }
            else
            {
                VFX_ASSERT(VFX_FALSE);
            }
        }
        
        setBadge(info.badge);
    }

    // create a stable items container
    VFX_OBJ_CREATE_EX(m_stableFrameContainer, VappDrawerCellStableFrame, this, (&m_appName, &m_cellImage, &m_cellTitle));
    m_stableFrameContainer->setSize(DRAWER_CELL_VISIBLE_WIDTH, DRAWER_CELL_VISIBLE_HEIGHT);
    m_stableFrameContainer->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_TRANSLUCENT);

    // update state
    m_stableFrameContainer->updateOnBottomBar(m_onBottomBar);
    m_stableFrameContainer->updateIsPreinstall(m_isPreinstall);
    m_stableFrameContainer->updateTextFrameHidden(m_isTextFrameHidden);
    updateEditMode(m_editMode);
    updateBadge();
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MOC", SA_stop);
#endif
}

void VappDrawerCell::onInit()
{
    VcpPageMenuCell::onInit();

    // init size
    setSize(DRAWER_CELL_VISIBLE_WIDTH, DRAWER_CELL_VISIBLE_HEIGHT);

    // default hidden on creation
    setHidden(VFX_TRUE);

    // Create context for cell list
    if (s_cellListCntx == NULL)
    {
        VFX_OBJ_CREATE(s_cellListCntx, VfxContext, VFX_SYS_GLOBAL_CONTEXT);
        s_cellListCntx->assignPool(s_vappDrawerCellListCntxMemPool, DRAWER_CELL_LIST_CNTX_MEMORY_SIZE);
    }
    
    // Create cell list and insert cell in list to manage all cells
    if (s_cellList.getHandle() == NULL)
    {
        s_cellList.init(s_cellListCntx);
        mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UPDATE_BADGE, &VappDrawerCell::eventHandler, NULL);
    }
    s_cellList.pushBack(this);
}

void VappDrawerCell::onDeinit()
{
    // Remove cell from list and delete cell list if list is empty
    s_cellList.remove(this);
    if (s_cellList.empty())
    {
        s_cellList.deinit();
        mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_UPDATE_BADGE, &VappDrawerCell::eventHandler, NULL);
    }
    
    VcpPageMenuCell::onDeinit();
}


/*****************************************************************************
 * Class VappDrawerBuilder
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappDrawerBuilder", VappDrawerBuilder, VfxObject);

VappDrawerBuilder::VappDrawerBuilder():
    m_orderData(NULL),
    m_orderDataCount(0),
    m_groupData(NULL),
    m_groupDataCount(0)
{
}

void VappDrawerBuilder::setAppOrderData(mmi_app_package_name_struct orderData[], VfxS32 count)
{
    m_orderData = orderData;
    m_orderDataCount = count;
}

void VappDrawerBuilder::setAppGroupData(mmi_app_package_name_struct groupData[], VfxS32 count)
{
    m_groupData = groupData;
    m_groupDataCount = count;
}

void VappDrawerBuilder::loadMenu(VappDrawerPageMenu * menu)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MLM", SA_start);
#endif

    initFrames(menu);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MLM", SA_stop);
#endif
}

void VappDrawerBuilder::initFrames(VappDrawerPageMenu * menu)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MIF", SA_start);
#endif

    mmi_app_package_name_struct *preInstalledAppArray = NULL;
    U32 preInstalledAppCount = srv_appmgr_get_app_package_num(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE);
    if (preInstalledAppCount)
    {
        VFX_SYS_ALLOC_MEM(preInstalledAppArray, sizeof(mmi_app_package_name_struct) * preInstalledAppCount );
        mmi_ret result;
        result = srv_appmgr_get_app_package_list(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE, preInstalledAppArray, preInstalledAppCount);
        VFX_ASSERT(result != MMI_RET_ERR);
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
            isPreInstalled = isPreInstalledApp(m_orderData[i], preInstalledAppArray, preInstalledAppCount);
        }
        VappDrawerCell * cell = ::createDrawerCell(m_orderData[i], menu, isPreInstalled);
        cell->setOnBottomBar(VFX_FALSE);
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

    VfxS32 groupCellIndex = 0;
    for (VfxS32 i = 0; i < m_groupDataCount; ++i)
    {
        if ( (strncmp(m_groupData[i], "", MMI_APP_NAME_MAX_LEN) == 0) ||
            (strncmp(m_groupData[i], "DELETED", MMI_APP_NAME_MAX_LEN) == 0) )
        {
            ++groupCellIndex;
            continue;
        }

        VfxBool isPreInstalled = VFX_FALSE;
        if (preInstalledAppArray)
        {
            isPreInstalled = isPreInstalledApp(m_groupData[i], preInstalledAppArray, preInstalledAppCount);
        }
        VappDrawerCell * cell = ::createDrawerCell(m_groupData[i], menu, isPreInstalled);
        cell->setOnBottomBar(VFX_TRUE);
        menu->setGroupMenuItem(groupCellIndex, cell);

        ++groupCellIndex;
    }
    
    if (preInstalledAppArray)
    {
        VFX_SYS_FREE_MEM(preInstalledAppArray);
    }
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MIF", SA_stop);
#endif
}

VfxS32 VappDrawerBuilder::repositionFrameIndex(VappDrawerPageMenu * menu, VfxS32 index)
{
    if (index < menu->getMaxPageCount() * menu->getMenuItemCountPerPage() )
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

void VappDrawerBuilder::saveMenu(VappDrawerPageMenu * menu)
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
            VappDrawerCell * cosmosCell = (VappDrawerCell *)cell;
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

    // save group data
    VfxS32 groupOrderIndex = 0;
    for (VfxS32 j = 0; j < 4 && groupOrderIndex < m_groupDataCount; ++j)
    {
        VcpPageMenuCell * cell = menu->getGroupMenuItem(j);
        if (cell == NULL)
        {
            strncpy(m_groupData[groupOrderIndex], "DELETED", MMI_APP_NAME_MAX_LEN);
            ++groupOrderIndex;
            continue;
        }
        VappDrawerCell * cosmosCell = (VappDrawerCell *)cell;
        cosmosCell->getCellAppName(m_groupData[groupOrderIndex]);
        ++groupOrderIndex;
    }
}


VappDrawerCell * createDrawerCellRaw(VfxImageSrc image, const VfxWString &title, VfxFrame * parent)
{
    // create the cell
    VappDrawerCell * cell;
    VFX_OBJ_CREATE_EX(cell, VappDrawerCell, parent, (image, title));

    return cell;
}

VappDrawerCell * createDrawerCell(mmi_app_package_name_struct & appName, VfxObject * parent, VfxBool preinstall)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MCC", SA_start);
#endif
    VappDrawerCell * cell;
    VFX_OBJ_CREATE(cell, VappDrawerCell, parent);
    cell->setCellAppName(appName);
    cell->setOnBottomBar(VFX_TRUE);
    cell->setIsPreinstall(preinstall);
    cell->setHidden(VFX_TRUE);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MCC", SA_stop);
#endif

    return cell;
}

VfxBool isPreInstalledApp(mmi_app_package_name_struct appName, mmi_app_package_name_struct preInstalledApp[], VfxU32 preInstalledAppCount)
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

VfxBool isInstalledApp(mmi_app_package_name_struct appName, mmi_app_package_name_struct installedApp[], VfxU32 installedAppCount)
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

