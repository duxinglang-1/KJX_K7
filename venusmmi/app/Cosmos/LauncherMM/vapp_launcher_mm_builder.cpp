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
 *  vapp_launcher_mm_builder.cpp
 *
 * Project:
 * --------
 *  Cosmos Launcher 2.0 - Launcher MM
 *
 * Description:
 * ------------
 *  Launcher MM Builder
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "MMI_features.h"

#ifdef __MMI_VUI_LAUNCHER_MM__


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vrt_datatype.h"
#include "vrt_system.h"

#include "vfx_cpp_base.h"
#include "vfx_container.h"
#include "vfx_context.h"
#include "vfx_image_src.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_text_frame.h"
#include "vfx_timer.h"

#include "vcp_include.h"
#include "vcp_page_menu_util.h"

#include "vapp_launcher_mm.h"
#include "vapp_launcher_mm_builder.h"
#include "vapp_launcher_mm_default_order.h"
#include "vapp_launcher_mm_gprot.h"
#include "vapp_launcher_mm_page_menu.h"
#include "mmi_rp_vapp_launcher_mm_def.h"

#ifndef __MMI_VUI_PLATFORM_CONTEXT_SLIM__
#include "vapp_platform_context.h"  // for VappPlatformContext
#endif

extern "C"
{
#include "AppMgrSrvGprot.h"
#include "gdi_const.h"
#include "gdi_include.h"
#include "gdi_primitive.h"
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

//#define VAPP_LAUNCHER_MM_MEMORY_TEST
//#define VAPP_LAUNCHER_MM_MEMORY_TEST_FOLDER_COUNT VAPP_LAUNCHER_MM_MAX_PAGE_FOLDER_DATA
//#define VAPP_LAUNCHER_MM_MEMORY_TEST_APP_COUNT_PER_FOLDER VAPP_LAUNCHER_MM_MAX_APP_DATA_PER_FOLDER
//#define VAPP_LAUNCHER_MM_MEMORY_TEST_PAGE_COUNT (VAPP_LAUNCHER_MM_MAX_PAGE_COUNT - 1)
//#define VAPP_LAUNCHER_MM_MEMORY_TEST_APP_COUNT_PER_PAGE (VAPP_LAUNCHER_MM_MAX_PAGE_CELL_COUNT / VAPP_LAUNCHER_MM_MAX_PAGE_COUNT)

/*****************************************************************************
 * Global Variable
 *****************************************************************************/

// cell content layout
#if defined(__MMI_MAINLCD_480X800__)
static const VfxS32 VAPP_LAUNCHER_MM_CELL_VISIBLE_WIDTH = 120;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_VISIBLE_HEIGHT = 144;

static const VfxS32 VAPP_LAUNCHER_MM_CELL_APP_ICON_WIDTH_MAX = 96;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_APP_ICON_HEIGHT_MAX = 96;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_APP_ICON_WIDTH_MIN = 72;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_APP_ICON_HEIGHT_MIN = 72;

static const VfxS32 VAPP_LAUNCHER_MM_CELL_TITLE_BASE_X_MARGIN = 2;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_TITLE_OFFSET_X = VAPP_LAUNCHER_MM_CELL_TITLE_BASE_X_MARGIN;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_TITLE_OFFSET_Y = 110;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_TITLE_WIDTH = VAPP_LAUNCHER_MM_CELL_VISIBLE_WIDTH - 2 * VAPP_LAUNCHER_MM_CELL_TITLE_BASE_X_MARGIN;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_TITLE_HEIGHT = VAPP_LAUNCHER_MM_CELL_VISIBLE_HEIGHT - VAPP_LAUNCHER_MM_CELL_TITLE_OFFSET_Y;

static const VfxS32 VAPP_LAUNCHER_MM_CELL_BADGE_OFFSET_Y = 0;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_BADGE_FONT_SIZE = 23;

static const VfxS32 VAPP_LAUNCHER_MM_CELL_UNINSTALL_ICON_POS_X = 0;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_UNINSTALL_ICON_POS_Y = 6;

// Folder
static const VfxFloat VAPP_LAUNCHER_MM_CELL_FOLDER_SCALE_FACTOR = 1.15f;

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
static const VfxS32 VAPP_LAUNCHER_MM_CELL_VISIBLE_WIDTH = 60;
#if defined(__MMI_MAINLCD_240X320__)
static const VfxS32 VAPP_LAUNCHER_MM_CELL_VISIBLE_HEIGHT = 70;
#else
static const VfxS32 VAPP_LAUNCHER_MM_CELL_VISIBLE_HEIGHT = 72;
#endif

static const VfxS32 VAPP_LAUNCHER_MM_CELL_APP_ICON_WIDTH_MAX = 45;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_APP_ICON_HEIGHT_MAX = 45;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_APP_ICON_WIDTH_MIN = 38;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_APP_ICON_HEIGHT_MIN = 38;

static const VfxS32 VAPP_LAUNCHER_MM_CELL_TITLE_BASE_X_MARGIN = 0;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_TITLE_OFFSET_X = VAPP_LAUNCHER_MM_CELL_TITLE_BASE_X_MARGIN;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_TITLE_OFFSET_Y = 54;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_TITLE_WIDTH = VAPP_LAUNCHER_MM_CELL_VISIBLE_WIDTH - 2 * VAPP_LAUNCHER_MM_CELL_TITLE_BASE_X_MARGIN;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_TITLE_HEIGHT = VAPP_LAUNCHER_MM_CELL_VISIBLE_HEIGHT - VAPP_LAUNCHER_MM_CELL_TITLE_OFFSET_Y;

static const VfxS32 VAPP_LAUNCHER_MM_CELL_BADGE_OFFSET_Y = 0;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_BADGE_FONT_SIZE = 12;

static const VfxS32 VAPP_LAUNCHER_MM_CELL_UNINSTALL_ICON_POS_X = 0;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_UNINSTALL_ICON_POS_Y = 6;

// Folder
static const VfxFloat VAPP_LAUNCHER_MM_CELL_FOLDER_SCALE_FACTOR = 1.25f;

#else // default HVGA 320X480
static const VfxS32 VAPP_LAUNCHER_MM_CELL_VISIBLE_WIDTH = 80;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_VISIBLE_HEIGHT = 88;

static const VfxS32 VAPP_LAUNCHER_MM_CELL_APP_ICON_WIDTH_MAX = 57;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_APP_ICON_HEIGHT_MAX = 57;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_APP_ICON_WIDTH_MIN = 48;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_APP_ICON_HEIGHT_MIN = 48;

static const VfxS32 VAPP_LAUNCHER_MM_CELL_TITLE_BASE_X_MARGIN = 1;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_TITLE_OFFSET_X = VAPP_LAUNCHER_MM_CELL_TITLE_BASE_X_MARGIN;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_TITLE_OFFSET_Y = 70;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_TITLE_WIDTH = VAPP_LAUNCHER_MM_CELL_VISIBLE_WIDTH - 2 * VAPP_LAUNCHER_MM_CELL_TITLE_BASE_X_MARGIN;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_TITLE_HEIGHT = VAPP_LAUNCHER_MM_CELL_VISIBLE_HEIGHT - VAPP_LAUNCHER_MM_CELL_TITLE_OFFSET_Y;

static const VfxS32 VAPP_LAUNCHER_MM_CELL_BADGE_OFFSET_Y = 0;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_BADGE_FONT_SIZE = 15;

static const VfxS32 VAPP_LAUNCHER_MM_CELL_UNINSTALL_ICON_POS_X = 0;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_UNINSTALL_ICON_POS_Y = 5;

// Folder
static const VfxFloat VAPP_LAUNCHER_MM_CELL_FOLDER_SCALE_FACTOR = 1.25f;

#endif

static const VfxFloat VAPP_LAUNCHER_MM_CELL_SCALE_DELETING_ICON_FACTOR = 20.0f;
static const VfxS32 VAPP_LAUNCHER_MM_CELL_SCALE_DELETING_ICON_DURATION = 200;


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

VappLauncherMmCell *vappLauncherMmCreateCellRaw(VfxImageSrc image, const VfxWString &title, VfxFrame *parent)
{
    // create the cell
    VappLauncherMmCell *cell;
    VFX_OBJ_CREATE_EX(cell, VappLauncherMmCell, parent, (image, title));

    return cell;
}

VappLauncherMmCell *vappLauncherMmCreateCell(mmi_app_package_name_struct &appName, VfxObject *parent, VfxBool preinstall)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM6", SA_start);
#endif
    // get app info
    VfxImageSrc image;
    VfxWString title;
    srv_app_info_struct info;

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

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM6", SA_stop);
    SLA_CustomLogging("MM6", SA_start);
#endif

    VappLauncherMmCell * cell;
    VFX_OBJ_CREATE_EX(cell, VappLauncherMmCell, parent, (image, title));
    cell->setCellAppName(appName);
    cell->setBadge(info.badge);
    cell->setIsPreinstall(preinstall);
    cell->setHidden(VFX_TRUE);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM6", SA_stop);
#endif

    return cell;
}

VfxBool vappLauncherMmisPreInstalledApp(mmi_app_package_name_struct appName, mmi_app_package_name_struct preInstalledApp[], VfxU32 preInstalledAppCount)
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

//uninstall
VfxBool vappLauncherMmIsInstalledApp(mmi_app_package_name_struct appName, 
mmi_app_package_name_struct installedApp[], VfxU32 installedAppCount)
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
 * Class VappLauncherMmCellList
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherMmCellList", VappLauncherMmCellList, VfxObject);
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappLauncherMmCellList);


/*****************************************************************************
 * Class VappLauncherMmCellStableFrame
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherMmCellStableFrame", VappLauncherMmCellStableFrame, VfxFrame);

VfxImageBuffer VappLauncherMmCellStableFrame::s_iconBg;
VfxU8 *VappLauncherMmCellStableFrame::s_iconBgImageBuffer = NULL;

VappLauncherMmCellStableFrame::VappLauncherMmCellStableFrame(mmi_app_package_name_struct *appPackageName, VfxImageSrc *appImage, VfxWString *appString) :
    m_appPackageName(appPackageName),
    m_appImage(appImage),
    m_appString(appString),
    m_isPreinstall(VFX_FALSE),
    m_isTextFrameHidden(VFX_FALSE)
{
}

void VappLauncherMmCellStableFrame::updateIsPreinstall(VfxBool isPreinstall)
{
    if (m_isPreinstall != isPreinstall)
    {
        m_isPreinstall = isPreinstall;

        invalidate();
    }
}

void VappLauncherMmCellStableFrame::updateTextFrameHidden(VfxBool isTextFrameHidden)
{
    if (m_isTextFrameHidden != isTextFrameHidden)
    {
        m_isTextFrameHidden = isTextFrameHidden;

        invalidate();
    }
}

void VappLauncherMmCellStableFrame::createIconBgImageBuffer(IVfxAllocatable *cntx)
{
    VfxS32 imgWidth = 0, imgHeight = 0;
    gdi_image_get_dimension_id(IMG_ID_VAPP_LAUNCHER_MM_ICON_BG, &imgWidth, &imgHeight);
    
    VfxS32 imgBufferSize = imgWidth * imgHeight * gdi_bits_per_pixel(GDI_COLOR_FORMAT_32) / 8;
    VFX_ALLOC_MEM_EX(s_iconBgImageBuffer, imgBufferSize, VFX_SYS_MEM_ALLOC_FLAG_FB, cntx);
    
    GDI_HANDLE imgLayer = GDI_LAYER_EMPTY_HANDLE;
    gdi_layer_create_cf_using_outside_memory(GDI_COLOR_FORMAT_32,
                                                   0,
                                                   0,
                                                   imgWidth,
                                                   imgHeight,
                                                   &imgLayer,
                                                   s_iconBgImageBuffer,
                                                   imgBufferSize);
    gdi_layer_push_and_set_active(imgLayer);
    gdi_image_draw_id(0, 0, IMG_ID_VAPP_LAUNCHER_MM_ICON_BG);
    gdi_layer_pop_and_restore_active();
    gdi_layer_free(imgLayer);

    s_iconBg.ptr = s_iconBgImageBuffer;
    s_iconBg.pitchBytes = imgWidth * 4;
    s_iconBg.width = imgWidth;
    s_iconBg.height = imgHeight;
    s_iconBg.colorFormat = VRT_COLOR_TYPE_ARGB8888;
}

void VappLauncherMmCellStableFrame::closeIconBgImageBuffer()
{
    VFX_FREE_MEM(s_iconBgImageBuffer);
}

void VappLauncherMmCellStableFrame::onDraw(VfxDrawContext &dc)
{
    drawIcon(dc);

    drawTitle(dc);
}

void VappLauncherMmCellStableFrame::drawIcon(VfxDrawContext &dc)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MDI", SA_start);
#endif

    // Draw icon background
    dc.drawImageBuffer((VAPP_LAUNCHER_MM_CELL_VISIBLE_WIDTH - s_iconBg.width) / 2,
                       VAPP_LAUNCHER_MM_CELL_VISIBLE_HEIGHT - s_iconBg.height,
                       s_iconBg);

    // Draw app icon
    srv_appmgr_app_package_type_enum type = srv_appmgr_get_app_package_type(*m_appPackageName);
    if (type == SRV_APPMGR_MRE_APP_PACKAGE_TYPE || type == SRV_APPMGR_JAVA_APP_PACKAGE_TYPE)
    {
        if ((m_appImage->getSize().width < VAPP_LAUNCHER_MM_CELL_APP_ICON_WIDTH_MIN) &&
            (m_appImage->getSize().height < VAPP_LAUNCHER_MM_CELL_APP_ICON_HEIGHT_MIN))
        {
            // Enlarge size
            VfxRect imageRect((VAPP_LAUNCHER_MM_CELL_VISIBLE_WIDTH - VAPP_LAUNCHER_MM_CELL_APP_ICON_WIDTH_MIN) / 2,
                              (VAPP_LAUNCHER_MM_CELL_TITLE_OFFSET_Y - VAPP_LAUNCHER_MM_CELL_APP_ICON_HEIGHT_MIN) / 2,
                              VAPP_LAUNCHER_MM_CELL_APP_ICON_WIDTH_MIN,
                              VAPP_LAUNCHER_MM_CELL_APP_ICON_HEIGHT_MIN);
            dc.drawResizedImage(imageRect, *m_appImage);                                
        }
        else if ((m_appImage->getSize().width > VAPP_LAUNCHER_MM_CELL_APP_ICON_WIDTH_MAX) &&
                 (m_appImage->getSize().height > VAPP_LAUNCHER_MM_CELL_APP_ICON_HEIGHT_MAX))
        {
            // Narrow size
            VfxRect imageRect((VAPP_LAUNCHER_MM_CELL_VISIBLE_WIDTH - VAPP_LAUNCHER_MM_CELL_APP_ICON_WIDTH_MAX) / 2,
                              (VAPP_LAUNCHER_MM_CELL_TITLE_OFFSET_Y - VAPP_LAUNCHER_MM_CELL_APP_ICON_HEIGHT_MAX) / 2,
                              VAPP_LAUNCHER_MM_CELL_APP_ICON_WIDTH_MAX,
                              VAPP_LAUNCHER_MM_CELL_APP_ICON_HEIGHT_MAX);
            dc.drawResizedImage(imageRect, *m_appImage);                                
        }
        else
        {
            dc.drawImage((VAPP_LAUNCHER_MM_CELL_VISIBLE_WIDTH - m_appImage->getSize().width) / 2,
                         (VAPP_LAUNCHER_MM_CELL_TITLE_OFFSET_Y - m_appImage->getSize().height) / 2, *m_appImage);
        }
    }
    else
    {
        dc.drawImage((VAPP_LAUNCHER_MM_CELL_VISIBLE_WIDTH - m_appImage->getSize().width) / 2,
                     (VAPP_LAUNCHER_MM_CELL_TITLE_OFFSET_Y - m_appImage->getSize().height) / 2, *m_appImage);
    }

    if (m_isPreinstall)
    {
        // Draw preinstall image
        VfxSize preInstallImageSize = VfxImageSrc(IMG_ID_VAPP_LAUNCHER_MM_ICON_PREINSTALL_APP).getSize();
        dc.drawImageFromRes((VAPP_LAUNCHER_MM_CELL_VISIBLE_WIDTH - preInstallImageSize.width) / 2,
                            (VAPP_LAUNCHER_MM_CELL_TITLE_OFFSET_Y - preInstallImageSize.height) / 2,
                            IMG_ID_VAPP_LAUNCHER_MM_ICON_PREINSTALL_APP);
    }
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MDI", SA_stop);
#endif
}

void VappLauncherMmCellStableFrame::drawTitle(VfxDrawContext &dc)
{
    if (!m_isTextFrameHidden)
    {
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("MDT", SA_start);
    #endif
    
        VfxFontDesc fontDesc;
        fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_LAUNCHER_MM_CELL_TITLE_FONT_SIZE);
        fontDesc.attr = VFX_FONT_DESC_ATTR_BOLD;
        fontDesc.effect = vappLauncherMmGetStringFontEffectId();
        dc.setFont(fontDesc);
        dc.setFillColor(VFX_COLOR_WHITE);
        
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("MDT", SA_stop);
    #endif

        VfxS32 stringWidth;
        if (strlen(*m_appPackageName) == 0)
        {
            stringWidth = fontDesc.measureStr(*m_appString).width;
        }
        else
        {
            stringWidth = vappLauncherMmGetStringWidth(*m_appPackageName);
            if (stringWidth == -1)
            {
                stringWidth = fontDesc.measureStr(*m_appString).width;
                vappLauncherMmSetStringWidth(*m_appPackageName, stringWidth);
            }
        }
    
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("MDT", SA_start);
    #endif
        
        vrt_text_dir_type_enum dir = vrt_sys_get_text_dir();
        VfxAdpFontEngine adpFont;
        VfxS32 max_height, ascent, dscent;
        adpFont.getCharInfoForAllLang(fontDesc, &max_height, &ascent, &dscent);
    
        if (stringWidth <= VAPP_LAUNCHER_MM_CELL_TITLE_WIDTH)
        {
            if (dir == MG_TEXT_DIR_TYPE_L2R)
            {
                dc.drawTextBaseline(VAPP_LAUNCHER_MM_CELL_TITLE_OFFSET_X + (VAPP_LAUNCHER_MM_CELL_TITLE_WIDTH - stringWidth) / 2,
                                    VAPP_LAUNCHER_MM_CELL_TITLE_OFFSET_Y,
                                    stringWidth,
                                    VAPP_LAUNCHER_MM_CELL_TITLE_HEIGHT,
                                    ascent,
                                    *m_appString,
                                    m_appString->getLength());
            }
            else
            {
                dc.drawTextBaseline((VAPP_LAUNCHER_MM_CELL_VISIBLE_WIDTH - 1) - (VAPP_LAUNCHER_MM_CELL_TITLE_OFFSET_X + (VAPP_LAUNCHER_MM_CELL_TITLE_WIDTH - stringWidth) / 2),
                                    VAPP_LAUNCHER_MM_CELL_TITLE_OFFSET_Y,
                                    stringWidth,
                                    VAPP_LAUNCHER_MM_CELL_TITLE_HEIGHT,
                                    ascent,
                                    *m_appString,
                                    m_appString->getLength());
            }
        }
        else
        {
            dc.setEllipsis(VFX_WSTR("..."));
            if (dir == MG_TEXT_DIR_TYPE_L2R)
            {
                VfxRect rect(VAPP_LAUNCHER_MM_CELL_TITLE_OFFSET_X,
                             VAPP_LAUNCHER_MM_CELL_TITLE_OFFSET_Y,
                             VAPP_LAUNCHER_MM_CELL_TITLE_WIDTH,
                             VAPP_LAUNCHER_MM_CELL_TITLE_HEIGHT);
                dc.drawTextTruncatedBaseline(rect,
                                             *m_appString,
                                             VAPP_LAUNCHER_MM_CELL_TITLE_WIDTH,
                                             ascent);
            }
            else
            {
                VfxRect rect((VAPP_LAUNCHER_MM_CELL_VISIBLE_WIDTH - 1) - VAPP_LAUNCHER_MM_CELL_TITLE_OFFSET_X,
                             VAPP_LAUNCHER_MM_CELL_TITLE_OFFSET_Y,
                             VAPP_LAUNCHER_MM_CELL_TITLE_WIDTH,
                             VAPP_LAUNCHER_MM_CELL_TITLE_HEIGHT);
                dc.drawTextTruncatedBaseline(rect,
                                             *m_appString,
                                             VAPP_LAUNCHER_MM_CELL_TITLE_WIDTH,
                                             ascent);
            }
        }
        
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("MDT", SA_stop);
    #endif
    }
}


/*****************************************************************************
 * Class VappLauncherMmCell
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherMmCell", VappLauncherMmCell, VcpPageMenuCell);

VappLauncherMmCell::VappLauncherMmCell(const VfxImageSrc & image, const VfxWString & title):
    m_cellImage(image),
    m_cellTitle(title),
    m_firstDisplay(VFX_TRUE),
    m_editMode(VFX_FALSE),
    m_isPreinstall(VFX_FALSE),
    m_isBadgeHidden(VFX_FALSE),
    m_isTextFrameHidden(VFX_FALSE),
    m_isInstalled(VFX_FALSE),
    m_isUninstalledButtonHidden(VFX_TRUE),
    m_isFolderFrameScale(VFX_FALSE),
    m_isFolderFrameHidden(VFX_TRUE),
    m_folderIconFrame(NULL),
    m_stableFrameContainer(NULL),
    m_appUninstallBtn(NULL),    
    m_badgeBgFrame(NULL),
    m_badgeTextFrame(NULL),
    m_scaleDeletingIconTimeline(NULL)    
{
    memset(m_appName, 0, MMI_APP_NAME_MAX_LEN);
    memset(m_cellBadge, 0, sizeof(m_cellBadge));
}

void VappLauncherMmCell::setCellAppName(mmi_app_package_name_struct appName)
{
    strncpy(m_appName, appName, MMI_APP_NAME_MAX_LEN - 1);
}

void VappLauncherMmCell::getCellAppName(mmi_app_package_name_struct & result)
{
    strncpy(result, m_appName, MMI_APP_NAME_MAX_LEN - 1);
}

void VappLauncherMmCell::setCellTitle(VfxWString title)
{
    m_cellTitle = title;
}

void VappLauncherMmCell::getCellTitle(VfxWString *title)
{
    *title = m_cellTitle;
}

void VappLauncherMmCell::setEditMode(VfxBool editMode)
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

void VappLauncherMmCell::setIsPreinstall(VfxBool isPreinstall)
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

VfxBool VappLauncherMmCell::getIsPreinstall()
{
    return m_isPreinstall;
}

void VappLauncherMmCell::setBadge(VfxWChar *badge)
{
    memcpy(m_cellBadge, badge, sizeof(m_cellBadge));
    
    if (m_stableFrameContainer == NULL)
    {
        return;
    }
    
    updateBadge();
}

void VappLauncherMmCell::setBadgeHidden(VfxBool isHidden)
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

void VappLauncherMmCell::setTextFrameHidden(VfxBool isHidden)
{
    if (m_isTextFrameHidden != isHidden)
    {
        m_isTextFrameHidden = isHidden;

        if (m_stableFrameContainer == NULL)
        {
            return;
        }
        
        m_stableFrameContainer->updateTextFrameHidden(m_isTextFrameHidden);
    }
}

void VappLauncherMmCell::setIsInstalled(VfxBool isInstalled)
{
    setIsUnhittable(!isInstalled);

    if (m_isInstalled != isInstalled)
    {
        m_isInstalled = isInstalled;
        
        updateIsInstalled(m_isInstalled);
    }
}

void VappLauncherMmCell::setUninstalledButtonHidden(VfxBool isHidden)
{
    if (m_isUninstalledButtonHidden != isHidden)
    {
        m_isUninstalledButtonHidden = isHidden;

        if (m_stableFrameContainer == NULL)
        {
            return;
        }

        updateUninstalledButtonHidden(isHidden);
    }
}

void VappLauncherMmCell::scaleDeletingIcon()
{
    VfxTransform tempTransformBegin;
    tempTransformBegin.type = VFX_TRANSFORM_TYPE_AFFINE;
    tempTransformBegin.data.affine.sx = m_stableFrameContainer->getTransform().data.affine.sx;
    tempTransformBegin.data.affine.sy = m_stableFrameContainer->getTransform().data.affine.sy;

    VfxTransform tempTransformTo;
    tempTransformTo.type = VFX_TRANSFORM_TYPE_AFFINE;
    tempTransformTo.data.affine.sx = tempTransformBegin.data.affine.sx / VAPP_LAUNCHER_MM_CELL_SCALE_DELETING_ICON_FACTOR;
    tempTransformTo.data.affine.sy = tempTransformBegin.data.affine.sy / VAPP_LAUNCHER_MM_CELL_SCALE_DELETING_ICON_FACTOR;
    tempTransformTo.data.affine.tx = tempTransformBegin.data.affine.tx + m_stableFrameContainer->getSize().width / 2;
    tempTransformTo.data.affine.ty = tempTransformBegin.data.affine.ty + m_stableFrameContainer->getSize().height / 2;    

    m_scaleDeletingIconTimeline->setTarget(m_stableFrameContainer);
    m_scaleDeletingIconTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);

    m_scaleDeletingIconTimeline->setDurationTime(VAPP_LAUNCHER_MM_CELL_SCALE_DELETING_ICON_DURATION);
    m_scaleDeletingIconTimeline->setRepeatCount(1);
    m_scaleDeletingIconTimeline->setFromValue(tempTransformBegin);
    m_scaleDeletingIconTimeline->setToValue(tempTransformTo);
    m_scaleDeletingIconTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    m_scaleDeletingIconTimeline->m_signalStopped.connect(this, &VappLauncherMmCell::onScaleTimelineStop);

    m_scaleDeletingIconTimeline->start();
}

void VappLauncherMmCell::setFolderFrameScale(VfxBool isScale)
{
    if (m_isFolderFrameScale != isScale)
    {
        m_isFolderFrameScale = isScale;

        if (m_folderIconFrame == NULL)
        {
            return;
        }
        
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        
        if (isScale)
        {
            VfxAutoAnimate::initAnimateBegin();
        
            m_folderIconFrame->setSize(VfxImageSrc(IMG_ID_VAPP_LAUNCHER_MM_FOLDER_ICON_BG).getSize().width * VAPP_LAUNCHER_MM_CELL_FOLDER_SCALE_FACTOR,
                                       VfxImageSrc(IMG_ID_VAPP_LAUNCHER_MM_FOLDER_ICON_BG).getSize().height * VAPP_LAUNCHER_MM_CELL_FOLDER_SCALE_FACTOR);
            
            VfxAutoAnimate::initAnimateEnd();
        }
        else
        {
            m_folderIconFrame->setSize(VfxImageSrc(IMG_ID_VAPP_LAUNCHER_MM_FOLDER_ICON_BG).getSize().width,
                                       VfxImageSrc(IMG_ID_VAPP_LAUNCHER_MM_FOLDER_ICON_BG).getSize().height);
        }
        
        VfxAutoAnimate::commit();
    }
}

void VappLauncherMmCell::setFolderFrameHidden(VfxBool isHidden)
{
    if (m_isFolderFrameHidden != isHidden)
    {
        m_isFolderFrameHidden = isHidden;

        if (!isHidden)
        {
            if (m_folderIconFrame == NULL)
            {
                VFX_OBJ_CREATE(m_folderIconFrame, VfxFrame, this);
                m_folderIconFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_LAUNCHER_MM_FOLDER_ICON_BG));
                m_folderIconFrame->setPos(getSize().width / 2, VAPP_LAUNCHER_MM_CELL_TITLE_OFFSET_Y / 2);
                m_folderIconFrame->setSize(m_folderIconFrame->getImgContent().getSize());
                m_folderIconFrame->setAnchor(0.5f, 0.5f);
                m_folderIconFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
                m_folderIconFrame->setAutoAnimate(VFX_TRUE);
            }
        }
        else
        {
            VFX_OBJ_CLOSE(m_folderIconFrame);
        }
    }
}

void VappLauncherMmCell::onCellDisplay()
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
    VFX_OBJ_CREATE_EX(m_stableFrameContainer, VappLauncherMmCellStableFrame, this, (&m_appName, &m_cellImage, &m_cellTitle));
    m_stableFrameContainer->setSize(VAPP_LAUNCHER_MM_CELL_VISIBLE_WIDTH, VAPP_LAUNCHER_MM_CELL_VISIBLE_HEIGHT);
    m_stableFrameContainer->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_TRANSLUCENT);
    m_stableFrameContainer->sendToBack();

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM5", SA_stop);
#endif

    m_stableFrameContainer->updateIsPreinstall(m_isPreinstall);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM5", SA_start);
#endif

    m_stableFrameContainer->updateTextFrameHidden(m_isTextFrameHidden);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM5", SA_stop);
#endif

    updateEditMode(m_editMode);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM5", SA_start);
#endif
    
    updateBadge();

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM5", SA_stop);
#endif

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM4", SA_stop);
#endif

    updateIsInstalled(m_isInstalled);
    updateUninstalledButtonHidden(m_isUninstalledButtonHidden);
}

void VappLauncherMmCell::onInit()
{
    VcpPageMenuCell::onInit();

    // init size
    setSize(VAPP_LAUNCHER_MM_CELL_VISIBLE_WIDTH, VAPP_LAUNCHER_MM_CELL_VISIBLE_HEIGHT);

    // default hidden on creation
    setHidden(VFX_TRUE);

    // Create cell list and insert cell in list to manage all cells
    if (VFX_OBJ_GET_INSTANCE(VappLauncherMmCellList)->getHandle() == NULL)
    {    
#ifdef __MMI_VUI_PLATFORM_CONTEXT_SLIM__
        VFX_OBJ_GET_INSTANCE(VappLauncherMmCellList)->init(this);
        VappLauncherMmCellStableFrame::createIconBgImageBuffer(this);
#else
        VFX_OBJ_GET_INSTANCE(VappLauncherMmCellList)->init(VFX_OBJ_GET_INSTANCE(VappPlatformContext));
        VfxContext *cntx = VFX_OBJ_GET_INSTANCE(VappPlatformContext);
        VappLauncherMmCellStableFrame::createIconBgImageBuffer(cntx);
#endif
        mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UPDATE_BADGE, &VappLauncherMmCell::eventHandler, NULL);
    }
    VFX_OBJ_GET_INSTANCE(VappLauncherMmCellList)->pushBack(this);

    VFX_OBJ_CREATE(m_scaleDeletingIconTimeline, VfxTransformTimeline, this);    

}

void VappLauncherMmCell::onDeinit()
{
    // Remove cell from list and delete cell list if list is empty
    VFX_OBJ_GET_INSTANCE(VappLauncherMmCellList)->remove(this);
    if (VFX_OBJ_GET_INSTANCE(VappLauncherMmCellList)->empty())
    {
        VFX_OBJ_GET_INSTANCE(VappLauncherMmCellList)->deinit();
        mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_UPDATE_BADGE, &VappLauncherMmCell::eventHandler, NULL);

        VappLauncherMmCellStableFrame::closeIconBgImageBuffer();
    }
    
    VcpPageMenuCell::onDeinit();
}

void VappLauncherMmCell::updateEditMode(VfxBool editMode)
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

    for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_ORGANIZE_UNCHANGABLE_PAGE_ITEM_COUNT; ++i)
    {
        if (strncmp(m_appName, vappLauncherMmDefaultOrder[VAPP_LAUNCHER_MM_BAR_CELL_COUNT+i], MMI_APP_NAME_MAX_LEN) == 0)
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
    VfxAutoAnimate::commit();
}

void VappLauncherMmCell::updateBadge()
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
        VfxImageSrc badgeBg(IMG_ID_VAPP_LAUNCHER_MM_ICON_BADGE_BG);
        if (m_badgeBgFrame == NULL)
        {
            VFX_OBJ_CREATE(m_badgeBgFrame, VfxImageFrame, this);
            m_badgeBgFrame->setImgContent(badgeBg);
            m_badgeBgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
            m_badgeBgFrame->bringToFront();
        }
        VfxFontDesc fontDesc;
        fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_LAUNCHER_MM_CELL_BADGE_FONT_SIZE);
        m_badgeBgFrame->setSize(VFX_MAX(fontDesc.measureStr(m_cellBadge).width + badgeBg.getSize().width / 2, badgeBg.getSize().width),
                                badgeBg.getSize().height);
        m_badgeBgFrame->setPos(getSize().width - m_badgeBgFrame->getSize().width, VAPP_LAUNCHER_MM_CELL_BADGE_OFFSET_Y);
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

void VappLauncherMmCell::updateIsInstalled(VfxBool isInstalled)
{
    if (isInstalled)
    {
        if (m_appUninstallBtn == NULL && m_stableFrameContainer)
        {
            VfxImageSrc imgSrc(IMG_ID_VAPP_LAUNCHER_MM_ICON_DELETE);
            VFX_OBJ_CREATE(m_appUninstallBtn, VcpImageButton, m_stableFrameContainer);//this
            m_appUninstallBtn->setFuzzy(VFX_FALSE);
            m_appUninstallBtn->setImage(VcpStateImage(IMG_ID_VAPP_LAUNCHER_MM_ICON_DELETE));
            m_appUninstallBtn->setPos(VAPP_LAUNCHER_MM_CELL_UNINSTALL_ICON_POS_X,VAPP_LAUNCHER_MM_CELL_UNINSTALL_ICON_POS_Y);
            m_appUninstallBtn->setSize(imgSrc.getSize());
            m_appUninstallBtn->setIsEffect(VFX_TRUE);
            m_appUninstallBtn->setEffectSize(VfxSize(imgSrc.getSize().height*2, imgSrc.getSize().width*2));
            m_appUninstallBtn->m_signalClicked.connect(this, &VappLauncherMmCell::onUninstallBtnClicked);

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

void VappLauncherMmCell::updateUninstalledButtonHidden(VfxBool isHidden)
{
    if (m_appUninstallBtn)
    {
        m_appUninstallBtn->setHidden(isHidden);
    }
}

void VappLauncherMmCell::onUninstallBtnClicked(VfxObject *obj, VfxId id)
{
    vappLauncherMmUninstallApp(this);
}

void VappLauncherMmCell::onScaleTimelineStop(VfxBaseTimeline * timeline,VfxBool isCompleted)
{
    if(isCompleted)
    {
        this->setOpacity(0.0f);
        // Emit a signal to reload mainmenu while deleting icon has been scaled.
        m_signalDeleteIconScaled.emit(VFX_TRUE);
    }
}

mmi_ret VappLauncherMmCell::eventHandler(mmi_event_struct *event)
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
            
            for (VfxList <VappLauncherMmCell *>::It i = VFX_OBJ_GET_INSTANCE(VappLauncherMmCellList)->begin();
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


/*****************************************************************************
 * Class VappLauncherMmBuilder
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherMmBuilder", VappLauncherMmBuilder, VfxObject);

VappLauncherMmBuilder::VappLauncherMmBuilder():
    m_allFolderData(NULL),
    m_allFolderDataCount(0),
    m_orderData(NULL),
    m_orderDataCount(0),
    m_groupData(NULL),
    m_groupDataCount(0)
{
}

void VappLauncherMmBuilder::setFolderData(VappLauncherMmAppFolderDataStruct allFolderData[], VfxS32 count)
{
    m_allFolderData = allFolderData;
    m_allFolderDataCount = count;
}

void VappLauncherMmBuilder::setAppOrderData(VappLauncherMmAppOrderDataStruct orderData[], VfxS32 count)
{
    m_orderData = orderData;
    m_orderDataCount = count;
}

void VappLauncherMmBuilder::setAppGroupData(VappLauncherMmAppOrderDataStruct groupData[], VfxS32 count)
{
    m_groupData = groupData;
    m_groupDataCount = count;
}

void VappLauncherMmBuilder::loadMenu(VappLauncherMmPageMenu *menu, mmi_app_package_name_struct *uninstallingCellAppPackageName, VappLauncherMmCell **uninstallingCell)
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

#ifdef VAPP_LAUNCHER_MM_MEMORY_TEST
    // Create folder cells
    VfxS32 folderCount = 0;
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MEMORY_TEST_FOLDER_COUNT; ++i)
    {
		VappLauncherMmCell *cell = ::vappLauncherMmCreateCellRaw(VfxImageSrc(),
																 VFX_WSTR("Folder"),
																 menu);
		cell->setIsUnhittable(VFX_TRUE);
		cell->setFolderFrameHidden(VFX_FALSE);

		menu->setMenuItem(i + VAPP_LAUNCHER_MM_MEMORY_TEST_PAGE_COUNT * VAPP_LAUNCHER_MM_MEMORY_TEST_APP_COUNT_PER_PAGE, cell);
    }
    menu->setFolderCount(VAPP_LAUNCHER_MM_MEMORY_TEST_FOLDER_COUNT);
#else
    // Create folder cells
    VfxS32 folderCount = 0;
    for (VfxS32 i = 0; i < m_allFolderDataCount; ++i)
    {
        if (m_allFolderData[i].index != VAPP_LAUNCHER_MM_APP_ORDER_DATA_INVALID_INDEX)
        {
            VfxWString folderText;
            VappLauncherMmCell *cell = ::vappLauncherMmCreateCellRaw(VfxImageSrc(),
                                                                     folderText.loadFromMem(m_allFolderData[i].name),
                                                                     menu);
            cell->setIsUnhittable(VFX_TRUE);
            cell->setFolderFrameHidden(VFX_FALSE);

            if (m_allFolderData[i].index >= VAPP_LAUNCHER_MM_BAR_CELL_COUNT)
            {
                menu->setMenuItem(m_allFolderData[i].index - VAPP_LAUNCHER_MM_BAR_CELL_COUNT, cell);
            }
            else
            {
                menu->setGroupMenuItem(m_allFolderData[i].index, cell);
            }

            ++folderCount;
        }
    }
    menu->setFolderCount(folderCount);
#endif
    
    // Create cells in page menu
    VfxS32 cellIndex = 0;
    VfxS32 pageCount = 0;
        
#ifdef VAPP_LAUNCHER_MM_MEMORY_TEST
    for (VfxS32 j = 0; j < VAPP_LAUNCHER_MM_MEMORY_TEST_PAGE_COUNT + VAPP_LAUNCHER_MM_MEMORY_TEST_APP_COUNT_PER_FOLDER; ++j)
    for (VfxS32 i = 0; i < VAPP_LAUNCHER_MM_MEMORY_TEST_APP_COUNT_PER_PAGE; ++i)
#else
    for (VfxS32 i = 0; i < m_orderDataCount; ++i)
#endif
    {
        if (m_orderData[i].appId == VAPP_LAUNCHER_MM_APP_ORDER_DATA_DELETED)
        {
            continue;
        }
        if (m_orderData[i].appId == VAPP_LAUNCHER_MM_APP_ORDER_DATA_EMPTY)
        {
            if (i > 0 && m_orderData[i - 1].appId == VAPP_LAUNCHER_MM_APP_ORDER_DATA_EMPTY)
            {
                break;
            }
            continue;
        }

        mmi_app_package_name_struct appPackageName;
        memset(appPackageName, 0, sizeof(mmi_app_package_name_struct));
        srv_appmgr_get_app_package_name_by_id(m_orderData[i].appId, appPackageName);
        VfxBool isPreInstalled = VFX_FALSE;
        if (preInstalledAppArray)
        {
            isPreInstalled = vappLauncherMmisPreInstalledApp(appPackageName, preInstalledAppArray, preInstalledAppCount);
        }
        VappLauncherMmCell *cell = ::vappLauncherMmCreateCell(appPackageName, menu, isPreInstalled);
        cell->setIsUnhittable(VFX_TRUE);

#ifdef VAPP_LAUNCHER_MM_MEMORY_TEST
        cellIndex = i + j * VAPP_LAUNCHER_MM_MEMORY_TEST_APP_COUNT_PER_PAGE;
#else
        cellIndex = m_orderData[i].index;
#endif

        
#ifdef VAPP_LAUNCHER_MM_MEMORY_TEST
		if (j >= VAPP_LAUNCHER_MM_MEMORY_TEST_PAGE_COUNT)
		{
			menu->setMenuItemInFolderIcon(i + VAPP_LAUNCHER_MM_MEMORY_TEST_PAGE_COUNT * VAPP_LAUNCHER_MM_MEMORY_TEST_APP_COUNT_PER_PAGE, j - VAPP_LAUNCHER_MM_MEMORY_TEST_PAGE_COUNT, cell);
			cell->setTextFrameHidden(VFX_TRUE);
		}
#else
        // Create cells in folder icon
        if (m_orderData[i].subindex != VAPP_LAUNCHER_MM_APP_ORDER_DATA_INVALID_INDEX)
        {
            menu->setMenuItemInFolderIcon(m_orderData[i].index, m_orderData[i].subindex, cell);
            cell->setTextFrameHidden(VFX_TRUE);
        }
#endif
        else
        {
        #ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("MM5", SA_start);
        #endif
        
            // reposition if necessary
            cellIndex = repositionFrameIndex(menu, cellIndex);
            
        #ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("MM5", SA_stop);
        #endif
        
            menu->setMenuItem(cellIndex, cell);
        }
        
        pageCount = VFX_MAX((cellIndex + menu->getMenuItemCountPerPage()) / menu->getMenuItemCountPerPage(), pageCount);

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
    
#ifdef VAPP_LAUNCHER_MM_MEMORY_TEST
    menu->setPageCount(VAPP_LAUNCHER_MM_MEMORY_TEST_PAGE_COUNT + 1);
#else
    menu->setPageCount(pageCount);
#endif

    for (VfxS32 i = 0; i < m_groupDataCount; ++i)
    {
        if (m_groupData[i].appId == VAPP_LAUNCHER_MM_APP_ORDER_DATA_EMPTY ||
            m_groupData[i].appId == VAPP_LAUNCHER_MM_APP_ORDER_DATA_DELETED)
        {
            continue;
        }

        mmi_app_package_name_struct appPackageName;
        memset(appPackageName, 0, sizeof(mmi_app_package_name_struct));
        srv_appmgr_get_app_package_name_by_id(m_groupData[i].appId, appPackageName);
        VfxBool isPreInstalled = VFX_FALSE;
        if (preInstalledAppArray)
        {
            isPreInstalled = vappLauncherMmisPreInstalledApp(appPackageName, preInstalledAppArray, preInstalledAppCount);
        }
        VappLauncherMmCell * cell = ::vappLauncherMmCreateCell(appPackageName, menu, isPreInstalled);
        cell->setIsUnhittable(VFX_TRUE);
        
#ifndef VAPP_LAUNCHER_MM_MEMORY_TEST
        // Create cells in folders
        if (m_groupData[i].subindex != VAPP_LAUNCHER_MM_APP_ORDER_DATA_INVALID_INDEX)
        {
            menu->setGroupMenuItemInFolderIcon(m_groupData[i].index, m_groupData[i].subindex, cell);
            cell->setTextFrameHidden(VFX_TRUE);
        }
        else
#endif
        {
            menu->setGroupMenuItem(m_groupData[i].index, cell);
        }
        
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

void VappLauncherMmBuilder::saveMenu(VappLauncherMmPageMenu * menu)
{
    // Clear all folder data
    for (VfxS32 i = 0; i < m_allFolderDataCount; ++i)
    {
        m_allFolderData[i].index = VAPP_LAUNCHER_MM_APP_ORDER_DATA_INVALID_INDEX;
        memset(m_allFolderData[i].name, 0, sizeof(m_allFolderData[i].name));
    }

    VfxS32 folderIndex = 0;
    VfxS32 orderIndex = 0;
    for (VfxS32 i = 0; i < menu->getPageCount(); ++i)
    {
        VfxBool isSkipInvalidCell = VFX_FALSE;
        for (VfxS32 j = 0; j < menu->getMenuItemCountPerPage(); ++j)
        {
            VfxS32 cellIndex = i * menu->getMenuItemCountPerPage() + j;
            VcpPageMenuCell *cell = menu->getMenuItem(cellIndex);
            
            if (isSkipInvalidCell)
            {
                --cellIndex;
            }
            
            if (cell == NULL)
            {
                // Check if is invalid cell or not
                if (menu->getInvalidCellPos().group == VCP_PAGE_MENU_GROUP_MAIN &&
                    menu->getInvalidCellPos().index == cellIndex &&
                    isSkipInvalidCell == VFX_FALSE)
                {
                    isSkipInvalidCell = VFX_TRUE;
                }
                
                continue;
            }
            
            mmi_app_package_name_struct appPackageName;
            VappLauncherMmCell *cosmosCell = (VappLauncherMmCell *)cell;
            cosmosCell->getCellAppName(appPackageName);
            if (strncmp(appPackageName, "", MMI_APP_NAME_MAX_LEN) == 0)
            {
                // Folder cell
                VfxWString folderName;
                cosmosCell->getCellTitle(&folderName);
                mmi_wcsncpy(m_allFolderData[folderIndex].name, folderName.getBuf(), VAPP_LAUNCHER_MM_APP_FOLDER_LENGTH + 1);
                m_allFolderData[folderIndex].index = cellIndex + VAPP_LAUNCHER_MM_BAR_CELL_COUNT;
                ++folderIndex;
                
                // Cells in folder
                for (VfxS32 k = 0; k < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++k)
                {
                    VcpPageMenuCell *cell = menu->getMenuItemInFolderIcon(i * menu->getMenuItemCountPerPage() + j, k);
                    if (cell == NULL)
                    {
                        break;
                    }
                    mmi_app_package_name_struct appName;
                    VappLauncherMmCell *cosmosCell = (VappLauncherMmCell *)cell;
                    cosmosCell->getCellAppName(appName);
                    m_orderData[orderIndex].index = cellIndex;
                    m_orderData[orderIndex].subindex = k;
                    m_orderData[orderIndex].appId = srv_appmgr_get_id_by_app_package_name(appName);
                    
                    ++orderIndex;
                }
            }
            else
            {
                // App cell
                m_orderData[orderIndex].index = cellIndex;
                m_orderData[orderIndex].subindex = VAPP_LAUNCHER_MM_APP_ORDER_DATA_INVALID_INDEX;
                m_orderData[orderIndex].appId = srv_appmgr_get_id_by_app_package_name(appPackageName);
                
                ++orderIndex;
            }
        }
        
        vappLauncherMmClearOrderData(&m_orderData[orderIndex]);
        
        ++orderIndex;
    }

    // fill the remaining order data with empty string
    for (VfxS32 i = orderIndex; i < m_orderDataCount; ++i)
    {
        vappLauncherMmClearOrderData(&m_orderData[orderIndex]);
    }

    // save group data
    VfxS32 groupOrderIndex = 0;
    for (VfxS32 j = 0; j < VAPP_LAUNCHER_MM_BAR_CELL_COUNT && groupOrderIndex < m_groupDataCount; ++j)
    {
        VcpPageMenuCell * cell = menu->getGroupMenuItem(j);
        if (cell == NULL)
        {
            for (VfxS32 k = 0; k < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++k)
            {
                vappLauncherMmClearOrderData(&m_groupData[groupOrderIndex]);
                
                ++groupOrderIndex;
            }
            
            continue;
        }
        
        mmi_app_package_name_struct appPackageName;
        VappLauncherMmCell *cosmosCell = (VappLauncherMmCell *)cell;
        cosmosCell->getCellAppName(appPackageName);
        if (strncmp(appPackageName, "", MMI_APP_NAME_MAX_LEN) == 0)
        {
            // Folder cell
            VfxWString folderName;
            cosmosCell->getCellTitle(&folderName);
            mmi_wcsncpy(m_allFolderData[folderIndex].name, folderName.getBuf(), VAPP_LAUNCHER_MM_APP_FOLDER_LENGTH + 1);
            m_allFolderData[folderIndex].index = j;
            ++folderIndex;
            
            // Cells in folder
            for (VfxS32 k = 0; k < VAPP_LAUNCHER_MM_MAX_APP_PER_FOLDER; ++k)
            {
                VcpPageMenuCell *cell = menu->getGroupMenuItemInFolderIcon(j, k);
                if (cell == NULL)
                {
                    vappLauncherMmClearOrderData(&m_groupData[groupOrderIndex]);
                    continue;
                }
                
                mmi_app_package_name_struct appName;
                VappLauncherMmCell *cosmosCell = (VappLauncherMmCell *)cell;
                cosmosCell->getCellAppName(appName);
                m_groupData[groupOrderIndex].index = j;
                m_groupData[groupOrderIndex].subindex = k;
                m_groupData[groupOrderIndex].appId = srv_appmgr_get_id_by_app_package_name(appName);
                
                ++groupOrderIndex;
            }
        }
        else
        {
            // App cell
            m_groupData[groupOrderIndex].index = j;
            m_groupData[groupOrderIndex].subindex = VAPP_LAUNCHER_MM_APP_ORDER_DATA_INVALID_INDEX;
            m_groupData[groupOrderIndex].appId = srv_appmgr_get_id_by_app_package_name(appPackageName);
            
            ++groupOrderIndex;
        }
    }
    
    vappLauncherMmClearStringWidth();
}

VfxS32 VappLauncherMmBuilder::repositionFrameIndex(VappLauncherMmPageMenu * menu, VfxS32 index)
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


#endif // __MMI_VUI_LAUNCHER_MM__

