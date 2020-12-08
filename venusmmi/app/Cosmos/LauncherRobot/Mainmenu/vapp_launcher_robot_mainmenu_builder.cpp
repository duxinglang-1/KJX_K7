/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *  vapp_launcher_robot_mainmenu_builder.cpp
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  Launcher Robot Mainmenu builder
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

#include "MMI_features.h"

#include "vfx_container.h"
#include "vfx_object.h"

#include "vfx_timer.h"
#include "vcp_include.h"
#include "vapp_mainmenu_gprot.h"
#include "vapp_launcher_robot_mainmenu_builder.h"
#include "mmi_rp_vapp_launcher_robot_mainmenu_def.h"

#ifndef __MMI_VUI_PLATFORM_CONTEXT_SLIM__
#include "vapp_platform_context.h"
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
 * Global Variable
 *****************************************************************************/

// cell content layout
#if defined(__MMI_MAINLCD_480X800__) //WVGA
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_VISIBLE_WIDTH = 120;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_VISIBLE_HEIGHT = 151;

static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_WIDTH_MAX = 96;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_HEIGHT_MAX = 96;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_WIDTH_MIN = 72;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_HEIGHT_MIN = 72;

static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_OFFSET_X = 15;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_OFFSET_Y = 105;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_WIDTH = 95;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_HEIGHT = 110;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_FONT_SIZE = 19; 

static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_BADGE_OFFSET_Y = 0;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_BADGE_OFFSET_X = 8;

static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_COUNTER_FONT_SIZE = 23;

#elif defined(__MMI_MAINLCD_240X320__) //QVGA
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_VISIBLE_WIDTH = 60;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_VISIBLE_HEIGHT = 82;

static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_WIDTH_MAX = 45;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_HEIGHT_MAX = 45;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_WIDTH_MIN = 38;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_HEIGHT_MIN = 38;

static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_OFFSET_X = 3;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_OFFSET_Y = 50;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_WIDTH = 54;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_HEIGHT = 85;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_FONT_SIZE = 11;

static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_BADGE_OFFSET_Y = 3;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_BADGE_OFFSET_X = 3;

static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_COUNTER_FONT_SIZE = 12;

#elif defined(__MMI_MAINLCD_240X400__) //WQVGA
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_VISIBLE_WIDTH = 60;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_VISIBLE_HEIGHT = 85;

static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_WIDTH_MAX = 45;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_HEIGHT_MAX = 45;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_WIDTH_MIN = 38;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_HEIGHT_MIN = 38;

static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_OFFSET_X = 1;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_OFFSET_Y = 55;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_WIDTH = 56;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_HEIGHT = 85;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_FONT_SIZE = 11;

static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_BADGE_OFFSET_Y = 0;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_BADGE_OFFSET_X = 6;

static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_COUNTER_FONT_SIZE = 12;

#else // default HVGA 320X480
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_VISIBLE_WIDTH = 80;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_VISIBLE_HEIGHT = 95;

static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_WIDTH_MAX = 57;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_HEIGHT_MAX = 57;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_WIDTH_MIN = 48;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_HEIGHT_MIN = 48;

static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_OFFSET_X = 6;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_OFFSET_Y = 65;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_WIDTH = 69;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_HEIGHT = 80;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_FONT_SIZE = 13;

static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_BADGE_OFFSET_Y = 0;
static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_BADGE_OFFSET_X = 6;

static const VfxS32 VAPP_LAUNCHER_ROBOT_MM_CELL_COUNTER_FONT_SIZE = 15;
#endif

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/*****************************************************************************
 * Class VappLauncherRobotMainmenuCell
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherRobotMainmenuCell", VappLauncherRobotMainmenuCell, VcpPageMenuCell);

VfxList <VappLauncherRobotMainmenuCell *> VappLauncherRobotMainmenuCell::s_cellList;

VappLauncherRobotMainmenuCell::VappLauncherRobotMainmenuCell(const VfxImageSrc & image, const VfxWString & title):
    m_cellImage(image),
    m_cellTitle(title),
    m_firstDisplay(VFX_TRUE),
    m_onBottomBar(VFX_FALSE),
    m_isPreinstall(VFX_FALSE),
    m_isBadgeHidden(VFX_FALSE),
    m_iconBgFrame(NULL),
    m_iconFrame(NULL),
    m_textFrame(NULL),
    m_preinstallFrame(NULL),
    m_stableFrameContainer(NULL),
    m_badgeBgFrame(NULL),
    m_badgeTextFrame(NULL)
{
    memset(m_appName, 0, MMI_APP_NAME_MAX_LEN);
    memset(m_cellBadge, 0, sizeof(m_cellBadge));
}

void VappLauncherRobotMainmenuCell::setCellAppName(mmi_app_package_name_struct appName)
{
    strncpy(m_appName, appName, MMI_APP_NAME_MAX_LEN - 1);
}


void VappLauncherRobotMainmenuCell::getCellAppName(mmi_app_package_name_struct & result)
{
    strncpy(result, m_appName, MMI_APP_NAME_MAX_LEN - 1);
}


void VappLauncherRobotMainmenuCell::setIsPreinstall(VfxBool isPreinstall)
{
    if (m_isPreinstall != isPreinstall)
    {
        m_isPreinstall = isPreinstall;

        if (m_iconBgFrame == NULL)
        {
            return;
        }

        updateIsPreinstall(m_isPreinstall);
    }
}


void VappLauncherRobotMainmenuCell::setBadge(VfxWChar *badge)
{
    memcpy(m_cellBadge, badge, sizeof(m_cellBadge));
        
        if (m_iconFrame == NULL)
        {
            return;
        }
        
    updateBadge();
}


void VappLauncherRobotMainmenuCell::setBadgeHidden(VfxBool isHidden)
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


void VappLauncherRobotMainmenuCell::updateIconImage(const VfxImageSrc & image)
{
    if (m_iconFrame == NULL)
    {
        return;
    }
    
    srv_appmgr_app_package_type_enum type = srv_appmgr_get_app_package_type(m_appName);

    if (type == SRV_APPMGR_MRE_APP_PACKAGE_TYPE || type == SRV_APPMGR_JAVA_APP_PACKAGE_TYPE)
    {
        if ((image.getSize().width < VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_WIDTH_MIN) &&
            (image.getSize().height < VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_HEIGHT_MIN))
        {
            // Enlarge size
            VfxRect imageRect((VAPP_LAUNCHER_ROBOT_MM_CELL_VISIBLE_WIDTH - VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_WIDTH_MIN) / 2,
                              (VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_OFFSET_Y- VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_HEIGHT_MIN) / 2,
                               VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_WIDTH_MIN,
                               VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_HEIGHT_MIN);
            
            m_iconFrame->setPos((VAPP_LAUNCHER_ROBOT_MM_CELL_VISIBLE_WIDTH-VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_WIDTH_MIN)/ 2,
                                (VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_OFFSET_Y- VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_HEIGHT_MIN) / 2);

            m_iconFrame->setSize(VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_WIDTH_MIN,VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_HEIGHT_MIN);
            m_iconFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
            m_iconFrame->setImgContent(image);
        }
        else if ((image.getSize().width > VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_WIDTH_MAX) &&
                 (image.getSize().height > VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_HEIGHT_MAX))
        {
            // Narrow size
            VfxRect imageRect((VAPP_LAUNCHER_ROBOT_MM_CELL_VISIBLE_WIDTH - VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_WIDTH_MAX) / 2,
                              (VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_OFFSET_Y - VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_HEIGHT_MAX) / 2,
                              VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_WIDTH_MAX,
                              VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_HEIGHT_MAX);
            
            m_iconFrame->setPos((VAPP_LAUNCHER_ROBOT_MM_CELL_VISIBLE_WIDTH-VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_WIDTH_MAX)/ 2,
                                (VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_OFFSET_Y- VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_HEIGHT_MAX) / 2);

            m_iconFrame->setSize(VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_WIDTH_MAX,VAPP_LAUNCHER_ROBOT_MM_CELL_APP_ICON_HEIGHT_MAX);
            m_iconFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
            m_iconFrame->setImgContent(image);


        }
        else
        {
            // The rest of normal apps.
            m_iconFrame->setPos((VAPP_LAUNCHER_ROBOT_MM_CELL_VISIBLE_WIDTH - image.getSize().width) / 2,
                                (VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_OFFSET_Y - image.getSize().height) / 2);

            m_iconFrame->setSize(image.getSize().width, image.getSize().height);
            m_iconFrame->setImgContent(image); 
        }
    }
    else
    {
        // The rest of normal apps.
        m_iconFrame->setPos((VAPP_LAUNCHER_ROBOT_MM_CELL_VISIBLE_WIDTH - image.getSize().width) / 2,
                            (VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_OFFSET_Y - image.getSize().height) / 2);

		m_iconFrame->setSize(image.getSize().width, image.getSize().height);
        m_iconFrame->setImgContent(image);        
    }
    
    if (m_isPreinstall && m_preinstallFrame)
    {
        VfxSize preInstallImageSize = VfxImageSrc(IMG_ID_VAPP_LAUNCHER_ROBOT_MM_ICON_PREINSTALL_APP).getSize();

        m_preinstallFrame->setPos((VAPP_LAUNCHER_ROBOT_MM_CELL_VISIBLE_WIDTH - preInstallImageSize.width)/2,
                                  (VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_OFFSET_Y- preInstallImageSize.height)/2);
        m_preinstallFrame->setSize(preInstallImageSize);
        m_preinstallFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_LAUNCHER_ROBOT_MM_ICON_PREINSTALL_APP));

    }    
}


void VappLauncherRobotMainmenuCell::updateTitle(const VfxWString & title)
{
    if (m_textFrame == NULL)
    {
        // add text frame
        VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, m_stableFrameContainer);
        VfxFontDesc fontDesc;
        fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_FONT_SIZE);
        m_textFrame->setFont(fontDesc);
        m_textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	m_textFrame->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
        m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        m_textFrame->setAutoResized(VFX_TRUE);
        m_textFrame->setColor(VFX_COLOR_WHITE);
    }
    
    m_textFrame->setString(title);
    m_textFrame->setPos(VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_OFFSET_X, VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_OFFSET_Y);
    m_textFrame->setSize(VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_WIDTH, VAPP_LAUNCHER_ROBOT_MM_CELL_TITLE_HEIGHT);
    m_textFrame->setLineGap(0);
}


void VappLauncherRobotMainmenuCell::updateIsPreinstall(VfxBool isPreinstall)
{
    if (isPreinstall)
    {
        if (m_preinstallFrame == NULL)
        {
            VFX_OBJ_CREATE(m_preinstallFrame, VfxFrame, this);
        }
    }
    else
    {
        VFX_OBJ_CLOSE(m_preinstallFrame);
    }
}


void VappLauncherRobotMainmenuCell::updateBadge()
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
        VfxImageSrc badgeBg(IMG_ID_VAPP_LAUNCHER_ROBOT_MM_APP_COUNTER_BG);
        if (m_badgeBgFrame == NULL)
        {
            VFX_OBJ_CREATE(m_badgeBgFrame, VfxImageFrame, this);
            m_badgeBgFrame->setImgContent(badgeBg);
            m_badgeBgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
            m_badgeBgFrame->bringToFront();
        }
        
        VfxFontDesc fontDesc;
        fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_LAUNCHER_ROBOT_MM_CELL_COUNTER_FONT_SIZE);
        m_badgeBgFrame->setSize(VFX_MAX(fontDesc.measureStr(m_cellBadge).width + badgeBg.getSize().width / 2, 
                                badgeBg.getSize().width), badgeBg.getSize().height);
        
        m_badgeBgFrame->setPos(getSize().width - m_badgeBgFrame->getSize().width - VAPP_LAUNCHER_ROBOT_MM_CELL_BADGE_OFFSET_X,
                               (m_iconFrame->getPos().y - m_badgeBgFrame->getSize().width / 6) + VAPP_LAUNCHER_ROBOT_MM_CELL_BADGE_OFFSET_Y);
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


mmi_ret VappLauncherRobotMainmenuCell::eventHandler(mmi_event_struct *event)
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
            
            for (VfxList <VappLauncherRobotMainmenuCell *>::It i = s_cellList.begin(); !i.isNull(); ++i)
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


void VappLauncherRobotMainmenuCell::onCellDisplay()
{
    if (!m_firstDisplay)
    {
        return;
    }

    m_firstDisplay = VFX_FALSE;

    setHidden(VFX_FALSE);

    // Create a stable items container
    VFX_OBJ_CREATE(m_stableFrameContainer, VfxFrame, this);
    m_stableFrameContainer->setSize(VAPP_LAUNCHER_ROBOT_MM_CELL_VISIBLE_WIDTH, VAPP_LAUNCHER_ROBOT_MM_CELL_VISIBLE_HEIGHT);
    
    // Add icon frame
    VFX_OBJ_CREATE(m_iconFrame, VfxFrame, m_stableFrameContainer);

    // Must set translucent for icons's opacity of java or MRE.
    m_iconFrame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_TRANSLUCENT);

    updateIsPreinstall(m_isPreinstall);

    // Update state
    updateIconImage(m_cellImage);

    updateTitle(m_cellTitle);

    updateBadge();
}


void VappLauncherRobotMainmenuCell::onInit()
{
    VcpPageMenuCell::onInit();

    // init size
    setSize(VAPP_LAUNCHER_ROBOT_MM_CELL_VISIBLE_WIDTH, VAPP_LAUNCHER_ROBOT_MM_CELL_VISIBLE_HEIGHT);

    // default hidden on creation
    setHidden(VFX_TRUE);

    // Since background is blac, so set the cell as black as well
    // to force to use 16bit decoding.
    setBgColor(VFX_COLOR_BLACK);

    // Create cell list and insert cell in list to manage all cells
    if (s_cellList.getHandle() == NULL)
    {
#ifdef __MMI_VUI_PLATFORM_CONTEXT_SLIM__
        s_cellList.init(this);
#else
        s_cellList.init(VFX_OBJ_GET_INSTANCE(VappPlatformContext));
#endif
        mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UPDATE_BADGE, &VappLauncherRobotMainmenuCell::eventHandler, NULL);
    }
    
    s_cellList.pushBack(this);
}

void VappLauncherRobotMainmenuCell::onDeinit()
{
    // Remove cell from list and delete cell list if list is empty
    s_cellList.remove(this);
    
    if (s_cellList.empty())
    {
        s_cellList.deinit();
        mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_UPDATE_BADGE, &VappLauncherRobotMainmenuCell::eventHandler, NULL);
    }
    
    VcpPageMenuCell::onDeinit();
}


VappLauncherRobotMainmenuCell * createMainmenuRobotCellRaw(VfxImageSrc image, const VfxWString &title, VfxFrame * parent)
{
    // create the cell
    VappLauncherRobotMainmenuCell * cell;
    VFX_OBJ_CREATE_EX(cell, VappLauncherRobotMainmenuCell, parent, (image, title));

    return cell;
}


VappLauncherRobotMainmenuCell *createMainmenuRobotCell(mmi_app_package_name_struct &appName, VfxObject *parent, VfxBool preinstall)
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
             //VfxU8 type = (VfxU8)gdi_image_get_type_from_mem((PS8)(info.image.data.image.image_ptr));
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

    VappLauncherRobotMainmenuCell * cell;
    VFX_OBJ_CREATE_EX(cell, VappLauncherRobotMainmenuCell, parent, (image, title));
    cell->setCellAppName(appName);
    cell->setBadge(info.badge);
    cell->setIsPreinstall(preinstall);
    cell->setHidden(VFX_TRUE);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("MM6", SA_stop);
#endif

    return cell;
}
