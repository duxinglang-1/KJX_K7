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
 *  vapp_launcher_cosmos_mm_builder.cpp
 *
 * Project:
 * --------
 *  Cosmos Launcher 2.0 - Launcher Cosmos
 *
 * Description:
 * ------------
 *  Launcher Cosmos Main Menu Builder
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


#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER_COSMOS__) || (defined(__MMI_VUI_WIDGET_FACTORY__) && defined(__COSMOS_MMI_PACKAGE__))


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vrt_datatype.h"
#include "vrt_system.h"

#include "vfx_container.h"
#include "vfx_object.h"
#include "vfx_text_frame.h"
#include "vfx_timer.h"

#include "vcp_include.h"
#include "vcp_page_menu_util.h"

#include "vapp_launcher_cosmos_mm.h"
#include "vapp_launcher_cosmos_mm_builder.h"
#include "vapp_launcher_cosmos_mm_default_order.h"
#include "vapp_launcher_cosmos_mm_gprot.h"
#include "vapp_launcher_cosmos_mm_page_menu.h"
#include "vapp_launcher_cosmos_mm_shortcut_bar.h"
#include "mmi_rp_vapp_launcher_cosmos_mm_def.h"

#ifndef __MMI_VUI_PLATFORM_CONTEXT_SLIM__
#include "vapp_platform_context.h"  // for VappPlatformContext
#endif

extern "C"
{
#include "AppMgrSrvGprot.h"
}

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif // __MTK_TARGET__

#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif 


/*****************************************************************************
 * Define
 *****************************************************************************/

//#define VAPP_LAUNCHER_COSMOS_MM_MEMORY_TEST
//#define VAPP_LAUNCHER_COSMOS_MM_MEMORY_TEST_PAGE_COUNT 10
//#define VAPP_LAUNCHER_COSMOS_MM_MEMORY_TEST_APP_COUNT_PER_PAGE 16


/*****************************************************************************
 * Global Variable
 *****************************************************************************/

// cell content layout
#if defined(__MMI_MAINLCD_480X800__)
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_WIDTH = 120;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_HEIGHT = 130;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_WIDTH_MAX = 96;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_HEIGHT_MAX = 96;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_WIDTH_MIN = 72;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_HEIGHT_MIN = 72;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BASE_X_MARGIN = 2;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_OFFSET_X = VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BASE_X_MARGIN;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_OFFSET_Y = 102;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_WIDTH = VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_WIDTH - 2 * VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BASE_X_MARGIN;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_HEIGHT = 23 + 3 * 2;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_X_MARGIN = 10;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_OFFSET_X = VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BASE_X_MARGIN + VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_X_MARGIN;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_OFFSET_Y = 106;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_WIDTH = VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_WIDTH - 2 * VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BASE_X_MARGIN - 2 * VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_X_MARGIN;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_HEIGHT = 23;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_BADGE_OFFSET_Y = 0;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_BADGE_FONT_SIZE = 23;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_UNINSTALL_ICON_POS_X = 0;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_UNINSTALL_ICON_POS_Y = 6;

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_WIDTH = 60;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_HEIGHT = 73;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_WIDTH_MAX = 45;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_HEIGHT_MAX = 45;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_WIDTH_MIN = 38;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_HEIGHT_MIN = 38;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BASE_X_MARGIN = 0;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_OFFSET_X = VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BASE_X_MARGIN;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_OFFSET_Y = 51;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_WIDTH = VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_WIDTH - 2 * VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BASE_X_MARGIN;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_HEIGHT = 15;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_X_MARGIN = 3;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_OFFSET_X = VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BASE_X_MARGIN + VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_X_MARGIN;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_OFFSET_Y = 52;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_WIDTH = VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_WIDTH - 2 * VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BASE_X_MARGIN - 2 * VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_X_MARGIN;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_HEIGHT = 13;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_BADGE_OFFSET_Y = 5;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_BADGE_FONT_SIZE = 12;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_UNINSTALL_ICON_POS_X = 0;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_UNINSTALL_ICON_POS_Y = 6;

#else // default HVGA 320X480
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_WIDTH = 80;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_HEIGHT = 90;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_WIDTH_MAX = 57;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_HEIGHT_MAX = 57;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_WIDTH_MIN = 48;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_HEIGHT_MIN = 48;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BASE_X_MARGIN = 1;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_OFFSET_X = VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BASE_X_MARGIN;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_OFFSET_Y = 65;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_WIDTH = VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_WIDTH - 2 * VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BASE_X_MARGIN;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_HEIGHT = 19;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_X_MARGIN = 7;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_OFFSET_X = VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BASE_X_MARGIN + VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_X_MARGIN;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_OFFSET_Y = 67;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_WIDTH = VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_WIDTH - 2 * VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BASE_X_MARGIN - 2 * VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_X_MARGIN;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_HEIGHT = 15;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_BADGE_OFFSET_Y = 4;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_BADGE_FONT_SIZE = 15;

static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_UNINSTALL_ICON_POS_X = 0;
static const VfxS32 VAPP_LAUNCHER_COSMOS_MM_CELL_UNINSTALL_ICON_POS_Y = 5;

#endif

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

VappLauncherCosmosMmCell *vappLauncherCosmosMmCreateCellRaw(VfxImageSrc image, const VfxWString &title, VfxFrame *parent)
{
    // create the cell
    VappLauncherCosmosMmCell *cell;
    VFX_OBJ_CREATE_EX(cell, VappLauncherCosmosMmCell, parent, (image, title));

    return cell;
}

VappLauncherCosmosMmCell *vappLauncherCosmosMmCreateCell(mmi_app_package_name_struct &appName, VfxObject *parent, VfxBool preinstall)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM6", SA_start);
#endif
    // get app info
    VfxImageSrc image;
    VfxWString title;
    srv_app_info_struct info;
    
    if (strncmp(appName, "native.mtk.launcher", MMI_APP_NAME_MAX_LEN) == 0)
    {
        image = VfxImageSrc(IMG_ID_VAPP_LAUNCHER_COSMOS_MM_ICON_HOME);
        title.loadFromRes(STR_ID_VAPP_LAUNCHER_COSMOS_MM_HOME);
    }
    else
    {
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("MM7", SA_start);
    #endif
        
        mmi_ret result = srv_appmgr_get_app_package_info(appName, &info);
        
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("MM7", SA_stop);
        SLA_CustomLogging("MM7", SA_start);
    #endif
        
        VFX_ASSERT(result != MMI_RET_ERR);
    
        if (info.image.type == MMI_IMAGE_SRC_TYPE_RES_ID)
        {
            image = VfxImageSrc(info.image.data.res_id);
        }
        else if(info.image.type == MMI_IMAGE_SRC_TYPE_ROM_MEMORY)
        {
            image = VfxImageSrc(info.image.data.image.image_ptr, info.image.data.image.image_len);
        }
        else if (info.image.type == MMI_IMAGE_SRC_TYPE_PATH)
        {
            VfxWString path;
            path.loadFromMem(info.image.data.path);
            image = VfxImageSrc(path);
        }
        else
        {
            VFX_ASSERT(VFX_FALSE);
        }
        title.loadFromMem(info.string);
        
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("MM7", SA_stop);
    #endif
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM6", SA_stop);
    SLA_CustomLogging("MM6", SA_start);
#endif

    VappLauncherCosmosMmCell * cell;
    VFX_OBJ_CREATE_EX(cell, VappLauncherCosmosMmCell, parent, (image, title));
    cell->setCellAppName(appName);
    if (strncmp(appName, "native.mtk.launcher", MMI_APP_NAME_MAX_LEN) != 0)
    {
        cell->setBadge(info.badge);
    }
    cell->setIsPreinstall(preinstall);
    cell->setHidden(VFX_TRUE);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM6", SA_stop);
#endif

    return cell;
}

VfxBool vappLauncherCosmosMmIsPreInstalledApp(mmi_app_package_name_struct appName, mmi_app_package_name_struct preInstalledApp[], VfxU32 preInstalledAppCount)
{
    srv_appmgr_app_package_type_enum type = srv_appmgr_get_app_package_type(appName);
    if (type != SRV_APPMGR_MRE_APP_PACKAGE_TYPE)
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

VfxBool vappLauncherCosmosMmIsInstalledApp(mmi_app_package_name_struct appName, mmi_app_package_name_struct installedApp[], VfxU32 installedAppCount)
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


/*****************************************************************************
 * Class VappLauncherCosmosMmCellList
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherCosmosMmCellList", VappLauncherCosmosMmCellList, VfxObject);
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappLauncherCosmosMmCellList);


/*****************************************************************************
 * Class VappLauncherCosmosMmCellStableFrame
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherCosmosMmCellStableFrame", VappLauncherCosmosMmCellStableFrame, VfxFrame);

VappLauncherCosmosMmCellStableFrame::VappLauncherCosmosMmCellStableFrame(mmi_app_package_name_struct *appPackageName, VfxImageSrc *appImage, VfxWString *appString) :
    m_appPackageName(appPackageName),
    m_appImage(appImage),
    m_appString(appString),
    m_onShortcut(VFX_FALSE),
    m_isPreinstall(VFX_FALSE),
    m_isTextFrameHidden(VFX_FALSE)
{
}

void VappLauncherCosmosMmCellStableFrame::updateOnShortcut(VfxBool onShortcut)
{
    if (m_onShortcut != onShortcut)
    {
        m_onShortcut = onShortcut;

        if (m_isTextFrameHidden)
        {
            return;
        }
        
        invalidate();
    }
}

void VappLauncherCosmosMmCellStableFrame::updateIsPreinstall(VfxBool isPreinstall)
{
    if (m_isPreinstall != isPreinstall)
    {
        m_isPreinstall = isPreinstall;

        invalidate();
    }
}

void VappLauncherCosmosMmCellStableFrame::updateTextFrameHidden(VfxBool isTextFrameHidden)
{
    if (m_isTextFrameHidden != isTextFrameHidden)
    {
        m_isTextFrameHidden = isTextFrameHidden;

        invalidate();
    }
}

void VappLauncherCosmosMmCellStableFrame::onDraw(VfxDrawContext &dc)
{
    drawIcon(dc);

    drawTitle(dc);
}

void VappLauncherCosmosMmCellStableFrame::drawIcon(VfxDrawContext &dc)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MDI", SA_start);
#endif

    // Draw app icon
    srv_appmgr_app_package_type_enum type = srv_appmgr_get_app_package_type(*m_appPackageName);
    if (type == SRV_APPMGR_MRE_APP_PACKAGE_TYPE || type == SRV_APPMGR_JAVA_APP_PACKAGE_TYPE)
    {
        if ((m_appImage->getSize().width < VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_WIDTH_MIN) &&
            (m_appImage->getSize().height < VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_HEIGHT_MIN))
        {
            // Enlarge size
            VfxRect imageRect((VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_WIDTH - VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_WIDTH_MIN) / 2,
                              (VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_OFFSET_Y - VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_HEIGHT_MIN) / 2,
                              VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_WIDTH_MIN,
                              VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_HEIGHT_MIN);
            dc.drawResizedImage(imageRect, *m_appImage);                                
        }
        else if ((m_appImage->getSize().width > VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_WIDTH_MAX) &&
                 (m_appImage->getSize().height > VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_HEIGHT_MAX))
        {
            // Narrow size
            VfxRect imageRect((VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_WIDTH - VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_WIDTH_MAX) / 2,
                              (VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_OFFSET_Y - VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_HEIGHT_MAX) / 2,
                              VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_WIDTH_MAX,
                              VAPP_LAUNCHER_COSMOS_MM_CELL_APP_ICON_HEIGHT_MAX);
            dc.drawResizedImage(imageRect, *m_appImage);                                
        }
        else
        {
            dc.drawImage((VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_WIDTH - m_appImage->getSize().width) / 2,
                         (VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_OFFSET_Y - m_appImage->getSize().height) / 2, *m_appImage);
        }
    }
    else
    {
        dc.drawImage((VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_WIDTH - m_appImage->getSize().width) / 2,
                     (VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_OFFSET_Y - m_appImage->getSize().height) / 2, *m_appImage);
    }

    if (m_isPreinstall)
    {
        VfxSize preInstallImageSize = VfxImageSrc(IMG_ID_VAPP_LAUNCHER_COSMOS_MM_ICON_PREINSTALL_APP).getSize();
        dc.drawImageFromRes((VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_WIDTH - preInstallImageSize.width) / 2,
                            (VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_OFFSET_Y - preInstallImageSize.height) / 2,
                            IMG_ID_VAPP_LAUNCHER_COSMOS_MM_ICON_PREINSTALL_APP);
    }
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MDI", SA_stop);
#endif
}

void VappLauncherCosmosMmCellStableFrame::drawTitle(VfxDrawContext &dc)
{
    if (!m_isTextFrameHidden)
    {
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("MDT", SA_start);
    #endif
    
        VfxFontDesc fontDesc;
        fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_FONT_SIZE);
        dc.setFont(fontDesc);
        dc.setFillColor(VFX_COLOR_WHITE);

    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("MDT", SA_stop);
    #endif
        
        VfxS32 stringWidth;
    #ifdef __MMI_VUI_LAUNCHER_COSMOS__
        if (m_onShortcut ||
            strncmp(*m_appPackageName, "native.mtk.launcher_cosmos_mm", MMI_APP_NAME_MAX_LEN) == 0 ||
            strncmp(*m_appPackageName, "native.mtk.launcher", MMI_APP_NAME_MAX_LEN) == 0)
        {
            stringWidth = fontDesc.measureStr(*m_appString).width;
        }
        else
        {
            stringWidth = vappLauncherCosmosMmGetStringWidth(*m_appPackageName);
            if (stringWidth == -1)
            {
                stringWidth = fontDesc.measureStr(*m_appString).width;
                vappLauncherCosmosMmSetStringWidth(*m_appPackageName, stringWidth);
            }
        }
    #else
        stringWidth = fontDesc.measureStr(*m_appString).width;
    #endif
        
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("MDT", SA_start);
    #endif
        
        vrt_text_dir_type_enum dir = vrt_sys_get_text_dir();
        VfxAdpFontEngine adpFont;
        VfxS32 max_height, ascent, dscent;
        adpFont.getCharInfoForAllLang(fontDesc, &max_height, &ascent, &dscent);
    
        if (stringWidth <= VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_WIDTH)
        {
            if (m_onShortcut)
            {
                VfxRect imageRect(VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_OFFSET_X + (VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_WIDTH - stringWidth) / 2,
                                  VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_OFFSET_Y,
                                  stringWidth + VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_X_MARGIN * 2,
                                  VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_HEIGHT);
                dc.drawResizedImageFromRes(imageRect, IMG_ID_VAPP_LAUNCHER_COSMOS_MM_FONT_BG);
            }
            
            if (dir == MG_TEXT_DIR_TYPE_L2R)
            {
                dc.drawTextBaseline(VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_OFFSET_X + (VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_WIDTH - stringWidth) / 2,
                                    VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_OFFSET_Y,
                                    stringWidth,
                                    VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_HEIGHT,
                                    ascent,
                                    *m_appString,
                                    m_appString->getLength());
            }
            else
            {
                dc.drawTextBaseline((VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_WIDTH - 1) - (VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_OFFSET_X + (VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_WIDTH - stringWidth) / 2),
                                    VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_OFFSET_Y,
                                    stringWidth,
                                    VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_HEIGHT,
                                    ascent,
                                    *m_appString,
                                    m_appString->getLength());
            }
        }
        else
        {
            if (m_onShortcut)
            {
                VfxRect imageRect(VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_OFFSET_X,
                                  VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_OFFSET_Y,
                                  VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_WIDTH,
                                  VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_BG_HEIGHT);
                dc.drawResizedImageFromRes(imageRect, IMG_ID_VAPP_LAUNCHER_COSMOS_MM_FONT_BG);
            }
            
            dc.setEllipsis(VFX_WSTR("..."));
            if (dir == MG_TEXT_DIR_TYPE_L2R)
            {
                VfxRect rect(VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_OFFSET_X,
                             VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_OFFSET_Y,
                             VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_WIDTH,
                             VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_HEIGHT);
                dc.drawTextTruncatedBaseline(rect,
                                             *m_appString,
                                             VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_WIDTH,
                                             ascent);
            }
            else
            {
                VfxRect rect((VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_WIDTH - 1) - VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_OFFSET_X,
                              VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_OFFSET_Y,
                             VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_WIDTH,
                             VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_HEIGHT);
                dc.drawTextTruncatedBaseline(rect,
                                             *m_appString,
                                             VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_WIDTH,
                                             ascent);
            }
        }
        
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("MDT", SA_stop);
    #endif
    }
}


/*****************************************************************************
 * Class VappLauncherCosmosMmCell
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherCosmosMmCell", VappLauncherCosmosMmCell, VcpPageMenuCell);

VappLauncherCosmosMmCell::VappLauncherCosmosMmCell(const VfxImageSrc & image, const VfxWString & title):
    m_cellImage(image),
    m_cellTitle(title),
    m_firstDisplay(VFX_TRUE),
    m_onShortcut(VFX_FALSE),
    m_editMode(VFX_FALSE),
    m_isPreinstall(VFX_FALSE),
    m_isBadgeHidden(VFX_FALSE),
    m_isTextFrameHidden(VFX_FALSE),
    m_isInstalled(VFX_FALSE),
    m_stableFrameContainer(NULL),
    m_appUninstallBtn(NULL),    
    m_badgeBgFrame(NULL),
    m_badgeTextFrame(NULL),
    m_scaleDeletingIconTimeline(NULL)
{
    memset(m_appName, 0, MMI_APP_NAME_MAX_LEN);
    memset(m_cellBadge, 0, sizeof(m_cellBadge));
}

void VappLauncherCosmosMmCell::setCellAppName(mmi_app_package_name_struct appName)
{
    strncpy(m_appName, appName, MMI_APP_NAME_MAX_LEN - 1);
}

void VappLauncherCosmosMmCell::getCellAppName(mmi_app_package_name_struct & result)
{
    strncpy(result, m_appName, MMI_APP_NAME_MAX_LEN - 1);
}

void VappLauncherCosmosMmCell::setOnShortcut(VfxBool onShortcut)
{
    if (m_onShortcut != onShortcut)
    {
        m_onShortcut = onShortcut;

        if (m_stableFrameContainer == NULL)
        {
            return;
        }

        m_stableFrameContainer->updateOnShortcut(m_onShortcut);
    }
}

void VappLauncherCosmosMmCell::setEditMode(VfxBool editMode)
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

void VappLauncherCosmosMmCell::setIsPreinstall(VfxBool isPreinstall)
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

void VappLauncherCosmosMmCell::setBadge(VfxWChar *badge)
{
    memcpy(m_cellBadge, badge, sizeof(m_cellBadge));
    
    if (m_stableFrameContainer == NULL)
    {
        return;
    }
    
    updateBadge();
}

void VappLauncherCosmosMmCell::setBadgeHidden(VfxBool isHidden)
{
    if (m_isBadgeHidden != isHidden)
    {
        m_isBadgeHidden = isHidden;

        if (m_stableFrameContainer == NULL)
        {
            return;
        }
        
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

void VappLauncherCosmosMmCell::setTextFrameHidden(VfxBool isHidden)
{
    if (isHidden)
    {
        setSize(VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_WIDTH, VAPP_LAUNCHER_COSMOS_MM_CELL_TITLE_OFFSET_Y);
    }

    if (m_isTextFrameHidden != isHidden)
    {
        m_isTextFrameHidden = isHidden;

        if (m_stableFrameContainer == NULL)
        {
            return;
        }
        
        m_stableFrameContainer->updateOnShortcut(m_onShortcut);
        m_stableFrameContainer->updateTextFrameHidden(m_isTextFrameHidden);
    }
}

void VappLauncherCosmosMmCell::onCellSerialize()
{
    m_firstDisplay = VFX_TRUE;

    VFX_OBJ_CLOSE(m_appUninstallBtn);
    VFX_OBJ_CLOSE(m_stableFrameContainer);
    VFX_OBJ_CLOSE(m_badgeTextFrame);
    VFX_OBJ_CLOSE(m_badgeBgFrame);
}

void VappLauncherCosmosMmCell::onCellDisplay()
{
    if (!m_firstDisplay)
    {
        return;
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM4", SA_start);
#endif

    m_firstDisplay = VFX_FALSE;

    setHidden(VFX_FALSE);
    setOpaqueMode(VFX_FRAME_OPAQUE_MODE_TRANSLUCENT);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM5", SA_start);
#endif
    
    // create a stable items container
    VFX_OBJ_CREATE_EX(m_stableFrameContainer, VappLauncherCosmosMmCellStableFrame, this, (&m_appName, &m_cellImage, &m_cellTitle));
    m_stableFrameContainer->setSize(VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_WIDTH, VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_HEIGHT);
    m_stableFrameContainer->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_TRANSLUCENT);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM5", SA_stop);
#endif

    m_stableFrameContainer->updateOnShortcut(m_onShortcut);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM5", SA_start);
#endif

    m_stableFrameContainer->updateIsPreinstall(m_isPreinstall);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM5", SA_stop);
#endif

    m_stableFrameContainer->updateTextFrameHidden(m_isTextFrameHidden);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM5", SA_start);
#endif

    updateEditMode(m_editMode);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM5", SA_stop);
#endif
    
    updateBadge();

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM4", SA_stop);
#endif

    // To upate/check if it needs delete icon.
    // Scenario: After delete a java app, the delete icon on the rest of java app still remains.
    updateIsInstalled(m_isInstalled);

}

void VappLauncherCosmosMmCell::onInit()
{
    VcpPageMenuCell::onInit();

    // init size
    setSize(VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_WIDTH, VAPP_LAUNCHER_COSMOS_MM_CELL_VISIBLE_HEIGHT);

    // default hidden on creation
    setHidden(VFX_TRUE);

    // Create cell list and insert cell in list to manage all cells
    if (VFX_OBJ_GET_INSTANCE(VappLauncherCosmosMmCellList)->getHandle() == NULL)
    {
#ifdef __MMI_VUI_PLATFORM_CONTEXT_SLIM__
        VFX_OBJ_GET_INSTANCE(VappLauncherCosmosMmCellList)->init(this);
#else
        VFX_OBJ_GET_INSTANCE(VappLauncherCosmosMmCellList)->init(VFX_OBJ_GET_INSTANCE(VappPlatformContext));
#endif
        mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UPDATE_BADGE, &VappLauncherCosmosMmCell::eventHandler, NULL);
    }
    VFX_OBJ_GET_INSTANCE(VappLauncherCosmosMmCellList)->pushBack(this);

    // The timeline of shrinking delete icon.
    VFX_OBJ_CREATE(m_scaleDeletingIconTimeline, VfxTransformTimeline, this);    
}

void VappLauncherCosmosMmCell::onDeinit()
{
    // Remove cell from list and delete cell list if list is empty
    VFX_OBJ_GET_INSTANCE(VappLauncherCosmosMmCellList)->remove(this);
    if (VFX_OBJ_GET_INSTANCE(VappLauncherCosmosMmCellList)->empty())
    {
        VFX_OBJ_GET_INSTANCE(VappLauncherCosmosMmCellList)->deinit();
        mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_UPDATE_BADGE, &VappLauncherCosmosMmCell::eventHandler, NULL);
    }
    
    VcpPageMenuCell::onDeinit();
}

//unInstall
void VappLauncherCosmosMmCell::setIsInstalled(VfxBool isInstalled)
{
    setIsUnhittable(!isInstalled);

    if (m_isInstalled != isInstalled)
    {
        m_isInstalled = isInstalled;
        
        updateIsInstalled(m_isInstalled);
    }
}

void VappLauncherCosmosMmCell::scaleDeletingIcon()
{
    VfxTransform tempTransformBegin;
    tempTransformBegin.type = VFX_TRANSFORM_TYPE_AFFINE;
    tempTransformBegin.data.affine.sx = m_stableFrameContainer->getTransform().data.affine.sx;
    tempTransformBegin.data.affine.sy = m_stableFrameContainer->getTransform().data.affine.sy;

    VfxTransform tempTransformTo;
    tempTransformTo.type = VFX_TRANSFORM_TYPE_AFFINE;
    tempTransformTo.data.affine.sx = tempTransformBegin.data.affine.sx /20;
    tempTransformTo.data.affine.sy = tempTransformBegin.data.affine.sy /20;
    tempTransformTo.data.affine.tx = tempTransformBegin.data.affine.tx +40.0f;
    tempTransformTo.data.affine.ty = tempTransformBegin.data.affine.ty +40.0f;    

    m_scaleDeletingIconTimeline->setTarget(m_stableFrameContainer);
    m_scaleDeletingIconTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);

    m_scaleDeletingIconTimeline->setDurationTime(200);
    m_scaleDeletingIconTimeline->setRepeatCount(1);
    m_scaleDeletingIconTimeline->setFromValue(tempTransformBegin);
    m_scaleDeletingIconTimeline->setToValue(tempTransformTo);
    m_scaleDeletingIconTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    m_scaleDeletingIconTimeline->m_signalStopped.connect(this, &VappLauncherCosmosMmCell::onScaleTimelineStop);

    m_scaleDeletingIconTimeline->start();
}

void VappLauncherCosmosMmCell::onScaleTimelineStop(VfxBaseTimeline * timeline,VfxBool isCompleted)
{
    if(isCompleted)
    {
        this->setOpacity(0.0f);
        // Emit a signal to reload mainmenu while deleting icon has been scaled.
        m_signalDeleteIconScaled.emit(VFX_TRUE);
    }
}

void VappLauncherCosmosMmCell::updateEditMode(VfxBool editMode)
{
    if (m_stableFrameContainer == NULL)
    {
        return;
    }
    
    // Support uninstall icon 
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
    VfxAutoAnimate::setDuration(250);

#ifdef __MMI_VUI_LAUNCHER_COSMOS__
    if (strncmp(m_appName, "native.mtk.launcher", MMI_APP_NAME_MAX_LEN) == 0)
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
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MM_ORGANIZE_UNCHANGABLE_PAGE_ITEM_COUNT; ++i)
    {
        if (strncmp(m_appName, vappLauncherCosmosMmDefaultOrder[VAPP_LAUNCHER_COSMOS_MM_BAR_CELL_COUNT+i], MMI_APP_NAME_MAX_LEN) == 0)
        {
            if (editMode)
            {
                m_stableFrameContainer->setOpacity(0.3f);
            }
            else
            {
                m_stableFrameContainer->setOpacity(1.0f);
            }
            break;
        }
    }
#endif

    VfxAutoAnimate::commit();
}

void VappLauncherCosmosMmCell::updateBadge()
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
        VfxImageSrc badgeBg(IMG_ID_VAPP_LAUNCHER_COSMOS_MM_ICON_BADGE_BG);
        if (m_badgeBgFrame == NULL)
        {
            VFX_OBJ_CREATE(m_badgeBgFrame, VfxImageFrame, this);
            m_badgeBgFrame->setImgContent(badgeBg);
            m_badgeBgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
            m_badgeBgFrame->bringToFront();
        }
        VfxFontDesc fontDesc;
        fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_LAUNCHER_COSMOS_MM_CELL_BADGE_FONT_SIZE);
        m_badgeBgFrame->setSize(VFX_MAX(fontDesc.measureStr(m_cellBadge).width + badgeBg.getSize().width / 2, badgeBg.getSize().width),
                                badgeBg.getSize().height);
        m_badgeBgFrame->setPos(getSize().width - m_badgeBgFrame->getSize().width, VAPP_LAUNCHER_COSMOS_MM_CELL_BADGE_OFFSET_Y);
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

void VappLauncherCosmosMmCell::updateIsInstalled(VfxBool isInstalled)
{
    if (isInstalled)
    {
        if (m_appUninstallBtn == NULL && m_stableFrameContainer)
        {
            VfxImageSrc imgSrc(IMG_ID_VAPP_LAUNCHER_COSMOS_MM_ICON_DELETE);
            
            //
            // Change the parent from this to stableframe in order to shrink both at the same time.
            //            
            VFX_OBJ_CREATE(m_appUninstallBtn, VcpImageButton, m_stableFrameContainer);
            m_appUninstallBtn->setFuzzy(VFX_FALSE);
            m_appUninstallBtn->setImage(VcpStateImage(IMG_ID_VAPP_LAUNCHER_COSMOS_MM_ICON_DELETE));
            m_appUninstallBtn->setPos(VAPP_LAUNCHER_COSMOS_MM_CELL_UNINSTALL_ICON_POS_X, VAPP_LAUNCHER_COSMOS_MM_CELL_UNINSTALL_ICON_POS_Y);
            m_appUninstallBtn->setSize(imgSrc.getSize());
            m_appUninstallBtn->setIsEffect(VFX_TRUE);
            m_appUninstallBtn->setEffectSize(VfxSize(imgSrc.getSize().height*2, imgSrc.getSize().width*2));
            m_appUninstallBtn->m_signalClicked.connect(this, &VappLauncherCosmosMmCell::onUninstallBtnClicked);

            setNeedSetExactPos(VFX_TRUE);

            // Check if it needs to show the del btn after on cell serialized.
            if (m_editMode)
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
        }
    }
    else
    {
        VFX_OBJ_CLOSE(m_appUninstallBtn);
        
        setNeedSetExactPos(VFX_FALSE);
    }
}

void VappLauncherCosmosMmCell::onUninstallBtnClicked(VfxObject *obj, VfxId id)
{

// 
// Wrap cosmos launcher compile option, 
// since there are only robot & fruit launcher on slim project.
//
#if defined(__MMI_VUI_LAUNCHER_COSMOS__)
    vappLauncherCosmosMmUninstallApp(this);
#endif    
}

mmi_ret VappLauncherCosmosMmCell::eventHandler(mmi_event_struct *event)
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
            
            for (VfxList <VappLauncherCosmosMmCell *>::It i = VFX_OBJ_GET_INSTANCE(VappLauncherCosmosMmCellList)->begin();
                 !i.isNull();
                 ++i)
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


#ifdef __MMI_VUI_LAUNCHER_COSMOS__
/*****************************************************************************
 * Class VappLauncherCosmosMmBuilder
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherCosmosMmBuilder", VappLauncherCosmosMmBuilder, VfxObject);

VappLauncherCosmosMmBuilder::VappLauncherCosmosMmBuilder():
    m_orderData(NULL),
    m_orderDataCount(0),
    m_groupData(NULL),
    m_groupDataCount(0)
{
}

void VappLauncherCosmosMmBuilder::setAppOrderData(VfxU32 orderData[], VfxS32 count)
{
    m_orderData = orderData;
    m_orderDataCount = count;
}

void VappLauncherCosmosMmBuilder::setAppGroupData(VfxU32 groupData[], VfxS32 count)
{
    m_groupData = groupData;
    m_groupDataCount = count;
}

void VappLauncherCosmosMmBuilder::loadMenu(VappLauncherCosmosMmPageMenu *menu, mmi_app_package_name_struct *uninstallingCellAppPackageName, VappLauncherCosmosMmCell **uninstallingCell)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM4", SA_start);
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
        
#ifdef VAPP_LAUNCHER_COSMOS_MM_MEMORY_TEST
    for (VfxS32 j = 0; j < VAPP_LAUNCHER_COSMOS_MM_MEMORY_TEST_PAGE_COUNT; ++j)
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_COSMOS_MM_MEMORY_TEST_APP_COUNT_PER_PAGE; ++i)
#else
    for (VfxS32 i = 0; i < m_orderDataCount; ++i)
#endif
    {
        if (m_orderData[i] == VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_DELETED)
        {
            continue;
        }
        if (m_orderData[i] == VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY)
        {
            if (i > 0 && m_orderData[i - 1] == VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY)
            {
                break;
            }
            cellIndex = (cellIndex + menu->getMenuItemCountPerPage() - 1) / menu->getMenuItemCountPerPage() * menu->getMenuItemCountPerPage();
            continue;
        }

        mmi_app_package_name_struct appPackageName;
        memset(appPackageName, 0, sizeof(mmi_app_package_name_struct));
        srv_appmgr_get_app_package_name_by_id(m_orderData[i], appPackageName);
        VfxBool isPreInstalled = VFX_FALSE;
        if (preInstalledAppArray)
        {
            isPreInstalled = vappLauncherCosmosMmIsPreInstalledApp(appPackageName, preInstalledAppArray, preInstalledAppCount);
        }
        VappLauncherCosmosMmCell * cell = ::vappLauncherCosmosMmCreateCell(appPackageName, menu, isPreInstalled);
        cell->setIsUnhittable(VFX_TRUE);

        // reposition if necessary
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("MM5", SA_start);
    #endif
            cellIndex = repositionFrameIndex(menu, cellIndex);
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("MM5", SA_stop);
    #endif
        menu->setMenuItem(cellIndex, cell);

        ++cellIndex;
        pageCount = VFX_MAX( (cellIndex + menu->getMenuItemCountPerPage() - 1) / menu->getMenuItemCountPerPage(), pageCount);

        if (uninstallingCellAppPackageName)
        {
            if (strncmp(*uninstallingCellAppPackageName, appPackageName, MMI_APP_NAME_MAX_LEN) == 0)
            {
                *uninstallingCell = cell;
            }
        }
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM4", SA_stop);
    SLA_CustomLogging("MM4", SA_start);
#endif
    
#ifdef VAPP_LAUNCHER_COSMOS_MM_MEMORY_TEST
    menu->setPageCount(VAPP_LAUNCHER_COSMOS_MM_MEMORY_TEST_PAGE_COUNT);
#else
    menu->setPageCount(pageCount);
#endif

    VfxS32 groupCellIndex = 0;
    for (VfxS32 i = 0; i < m_groupDataCount; ++i)
    {
        if (m_groupData[i] == VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY ||
            m_groupData[i] == VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_DELETED)
        {
            ++groupCellIndex;
            continue;
        }

        mmi_app_package_name_struct appPackageName;
        memset(appPackageName, 0, sizeof(mmi_app_package_name_struct));
        srv_appmgr_get_app_package_name_by_id(m_groupData[i], appPackageName);
        VfxBool isPreInstalled = VFX_FALSE;
        if (preInstalledAppArray)
        {
            isPreInstalled = vappLauncherCosmosMmIsPreInstalledApp(appPackageName, preInstalledAppArray, preInstalledAppCount);
        }
        VappLauncherCosmosMmCell * cell = ::vappLauncherCosmosMmCreateCell(appPackageName, menu, isPreInstalled);
        cell->setIsUnhittable(VFX_TRUE);
        menu->setGroupMenuItem(groupCellIndex, cell);

        ++groupCellIndex;

        if (uninstallingCellAppPackageName)
        {
            if (strncmp(*uninstallingCellAppPackageName, appPackageName, MMI_APP_NAME_MAX_LEN) == 0)
            {
                *uninstallingCell = cell;
            }
        }
    }
    
    if (preInstalledAppArray)
    {
        VFX_SYS_FREE_MEM(preInstalledAppArray);
    }
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM4", SA_stop);
#endif
}

void VappLauncherCosmosMmBuilder::saveMenu(VappLauncherCosmosMmPageMenu * menu)
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
            mmi_app_package_name_struct appPackageName;
            VappLauncherCosmosMmCell * cosmosCell = (VappLauncherCosmosMmCell *)cell;
            cosmosCell->getCellAppName(appPackageName);
            m_orderData[orderIndex] = srv_appmgr_get_id_by_app_package_name(appPackageName);
            ++orderIndex;
        }
        m_orderData[orderIndex] = VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY;
        ++orderIndex;
    }

    // fill the remaining order data with empty string
    for (VfxS32 i = orderIndex; i < m_orderDataCount; ++i)
    {
        m_orderData[orderIndex] = VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY;
    }

    // save group data
    VfxS32 groupOrderIndex = 0;
    for (VfxS32 j = 0; j < 4 && groupOrderIndex < m_groupDataCount; ++j)
    {
        VcpPageMenuCell * cell = menu->getGroupMenuItem(j);
        if (cell == NULL)
        {
            m_groupData[groupOrderIndex] = VAPP_LAUNCHER_COSMOS_MM_APP_ORDER_DATA_EMPTY;
            ++groupOrderIndex;
            continue;
        }
        mmi_app_package_name_struct appPackageName;
        VappLauncherCosmosMmCell * cosmosCell = (VappLauncherCosmosMmCell *)cell;
        cosmosCell->getCellAppName(appPackageName);
        m_groupData[groupOrderIndex] = srv_appmgr_get_id_by_app_package_name(appPackageName);
        ++groupOrderIndex;
    }
    
    vappLauncherCosmosMmClearStringWidth();
}

VfxS32 VappLauncherCosmosMmBuilder::repositionFrameIndex(VappLauncherCosmosMmPageMenu * menu, VfxS32 index)
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
#endif // __MMI_VUI_LAUNCHER_COSMOS__


#endif // defined(__MMI_VUI_LAUNCHER_COSMOS__) || (defined(__MMI_VUI_WIDGET_FACTORY__) && defined(__COSMOS_MMI_PACKAGE__))

