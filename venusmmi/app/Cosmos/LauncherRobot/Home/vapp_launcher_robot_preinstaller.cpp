/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vapp_launcher_robot_preinstaller.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the pre-installer to configure the pre-installed
 *  widgets.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_widget_kit.h"
#include "vapp_launcher_robot_desktop.h"
#include "vapp_launcher_robot_preinstaller.h"

//
// Include C headers without extern "C" internally.
//
extern "C"
{

#include "lcd_sw_inc.h"
#include "AppMgrSrvGprot.h"

}


/*****************************************************************************
 * Pre-Installed Widget Configuration
 *****************************************************************************/

/*
 * Macro to add a pre-installed widget.
 */
#define VAPP_LAUNCHER_ROBOT_PREINSTALLER_CFG_ADD(_source, _type, _pageIdx, _x, _y)    \
    VappLauncherRobotPreinstaller::preInstallTableEntry(                             \
        _source,                                                            \
        _type,                                                              \
        _pageIdx,                                                           \
        _x,                                                                 \
        _y)

#define VAPP_LAUNCHER_ROBOT_PREINSTALLER_CFG_END()                                    \
    VappLauncherRobotPreinstaller::preInstallTableEntry()


/*
 * Registration:
 */
const VappLauncherRobotPreinstaller::preInstallTableEntry
VappLauncherRobotPreinstaller::s_preInstallTbl[] =
{
#if defined(__OP01_3G__)
    VAPP_LAUNCHER_ROBOT_PREINSTALLER_CFG_ADD(
        VAPP_WIDGET_SRC_SHORTCUT,
        "native.mtk.mobile_read",
        VappLauncherRobotDesktop::getCentraPageIndex(),
        0,
        0
    ),
    VAPP_LAUNCHER_ROBOT_PREINSTALLER_CFG_ADD(
        VAPP_WIDGET_SRC_SHORTCUT,
        "native.mtk.mobile_market",
        VappLauncherRobotDesktop::getCentraPageIndex(),
        1,
        0
    ),
    VAPP_LAUNCHER_ROBOT_PREINSTALLER_CFG_ADD(
        VAPP_WIDGET_SRC_SHORTCUT,
        "native.mtk.music_walkman",
        VappLauncherRobotDesktop::getCentraPageIndex(),
        2,
        0
    ),
    VAPP_LAUNCHER_ROBOT_PREINSTALLER_CFG_ADD(
        VAPP_WIDGET_SRC_SHORTCUT,
        "native.mtk.fetion",
        VappLauncherRobotDesktop::getCentraPageIndex(),
        3,
        0
    ),
#elif defined(__OP02_0200__)
    VAPP_LAUNCHER_ROBOT_PREINSTALLER_CFG_ADD(
        VAPP_WIDGET_SRC_SHORTCUT,
        "native.mtk.mobile_internet",
        VappLauncherRobotDesktop::getCentraPageIndex(),
        0,
        0
    ),
    VAPP_LAUNCHER_ROBOT_PREINSTALLER_CFG_ADD(
        VAPP_WIDGET_SRC_SHORTCUT,
        "native.mtk.wo_store",
        VappLauncherRobotDesktop::getCentraPageIndex(),
        1,
        0
    ),
#else /* Default Project */
#if defined(__MMI_VUI_WIDGET_GOOGLE__)
    VAPP_LAUNCHER_ROBOT_PREINSTALLER_CFG_ADD(
        VAPP_WIDGET_SRC_NATIVE,
        VAPP_WIDGET_TYPE_GOOGLE,
        VappLauncherRobotDesktop::getCentraPageIndex(),
        0,
        0
    ),
#else
#if defined (__MMI_BT_SUPPORT__) && defined(__MMI_WLAN_FEATURES__)
    VAPP_LAUNCHER_ROBOT_PREINSTALLER_CFG_ADD(
        VAPP_WIDGET_SRC_NATIVE,
        VAPP_WIDGET_TYPE_QUICK_SWITCH,
        VappLauncherRobotDesktop::getCentraPageIndex(),
        0,
        0
    ),
#endif

#ifdef __MMI_VUI_WIDGET_BAIDU_SEARCH__
    VAPP_LAUNCHER_ROBOT_PREINSTALLER_CFG_ADD(
        VAPP_WIDGET_SRC_NATIVE,
        VAPP_WIDGET_TYPE_BAIDU_SEARCH,
        VappLauncherRobotDesktop::getCentraPageIndex(),
        0,
        0
    ),
#endif

#if defined(__MMI_VUI_WIDGET_FM_RADIO__)
#if defined(__MMI_MAINLCD_240X320__)
    VAPP_LAUNCHER_ROBOT_PREINSTALLER_CFG_ADD(
        VAPP_WIDGET_SRC_NATIVE,
        VAPP_WIDGET_TYPE_FM_RADIO,
        VappLauncherRobotDesktop::getCentraPageIndex()-2,
        0,
        0
    ),
#else
    VAPP_LAUNCHER_ROBOT_PREINSTALLER_CFG_ADD(
        VAPP_WIDGET_SRC_NATIVE,
        VAPP_WIDGET_TYPE_FM_RADIO,
        VappLauncherRobotDesktop::getCentraPageIndex()-2,
        0,
        2
    ),
#endif
#endif

    VAPP_LAUNCHER_ROBOT_PREINSTALLER_CFG_ADD(
        VAPP_WIDGET_SRC_NATIVE,
        VAPP_WIDGET_TYPE_CALENDAR,
        VappLauncherRobotDesktop::getCentraPageIndex()-1,
        0,
        0
    ),

#ifdef __MMI_VUI_WIDGET_VIP_CONTACT__
    VAPP_LAUNCHER_ROBOT_PREINSTALLER_CFG_ADD(
        VAPP_WIDGET_SRC_NATIVE,
        VAPP_WIDGET_TYPE_VIP_CONTACT,
        VappLauncherRobotDesktop::getCentraPageIndex()+1,
        0,
        0
    ),
#endif

#if defined(__COSMOS_MUSICPLY__)
#if defined(__MMI_MAINLCD_240X320__)
    VAPP_LAUNCHER_ROBOT_PREINSTALLER_CFG_ADD(
        VAPP_WIDGET_SRC_NATIVE,
        VAPP_WIDGET_TYPE_MUSIC_PLAYER,
        VappLauncherRobotDesktop::getCentraPageIndex()+2,
        0,
        0
    ),
#else
    VAPP_LAUNCHER_ROBOT_PREINSTALLER_CFG_ADD(
        VAPP_WIDGET_SRC_NATIVE,
        VAPP_WIDGET_TYPE_MUSIC_PLAYER,
        VappLauncherRobotDesktop::getCentraPageIndex()+2,
        0,
        2
    ),
#endif
#endif

#endif /* defined(__MMI_VUI_WIDGET_GOOGLE__) */

#if defined(__MMI_VUI_SETTING_LAUNCHER_SELECTION__)
    VAPP_LAUNCHER_ROBOT_PREINSTALLER_CFG_ADD(
        VAPP_WIDGET_SRC_SHORTCUT,
        "native.mtk.launcher_shuttle",
        VappLauncherRobotDesktop::getCentraPageIndex(),
        0,
        0
    ),
#endif

#ifdef  __MMI_VUI_SETTING_SCREEN_LOCK_SELECTION__
    VAPP_LAUNCHER_ROBOT_PREINSTALLER_CFG_ADD(
        VAPP_WIDGET_SRC_SHORTCUT,
        "native.mtk.screen_lock_shuttle",
        VappLauncherRobotDesktop::getCentraPageIndex(),
        1,
        0
    ),
#endif

#ifdef __MMI_VUI_DOWNLOADABLE_APP_ICON__
    VAPP_LAUNCHER_ROBOT_PREINSTALLER_CFG_ADD(
        VAPP_WIDGET_SRC_SHORTCUT,
        "native.mtk.app_icon",
        VappLauncherRobotDesktop::getCentraPageIndex(),
        2,
        0
    ),
#endif

#if defined(__MMI_VUI_HOME_SCREEN_SWITCH_EFFECT__)
    VAPP_LAUNCHER_ROBOT_PREINSTALLER_CFG_ADD(
        VAPP_WIDGET_SRC_SHORTCUT,
        "native.mtk.launcher_robot_page_transition_setting",
        VappLauncherRobotDesktop::getCentraPageIndex(),
        2,
        0
    ),
#endif

#endif /* Default Project */

    VAPP_LAUNCHER_ROBOT_PREINSTALLER_CFG_END()
};


const VfxS32 VappLauncherRobotPreinstaller::s_sizeOfPreInstallTbl =
    sizeof(VappLauncherRobotPreinstaller::s_preInstallTbl) /
    sizeof(VappLauncherRobotPreinstaller::preInstallTableEntry) - 1;


/*****************************************************************************
 * Widget Pre-installer
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappLauncherRobotPreinstaller", VappLauncherRobotPreinstaller, VfxObject);


VappLauncherRobotPreinstaller::VappLauncherRobotPreinstaller()
{
    // Do nothing.
}


VappLauncherRobotPreinstaller::preInstallTableEntry::preInstallTableEntry() :
    m_source(VAPP_WIDGET_SRC_INVALID),
    m_typeKind(VappWidgetId::TYPE_KIND_UNKNOWN),
    m_pageIdx(0),
    m_pos()
{
    m_type.ival = 0;
}


VappLauncherRobotPreinstaller::preInstallTableEntry::preInstallTableEntry(
    VappWidgetSrcEnum source,
    VfxS32 type,
    VfxS32 pageIdx,
    VfxS32 x,
    VfxS32 y)
{
    //
    // Widget ID
    //
    m_source = source;
    m_typeKind = VappWidgetId::TYPE_KIND_INTEGER;
    m_type.ival = type;

    //
    // Position
    //
    m_pageIdx = pageIdx;
    
    VfxSize tileSize = VappLauncherRobotDesktop::getTileSize();

    VfxRect room = VappLauncherRobotDesktop::getRoom(tileSize, pageIdx, x, y);

    if (room == VFX_RECT_ZERO)
    {
        m_pos = VFX_POINT_ZERO;
    }
    else
    {
        m_pos.x = room.getMidX() - LCD_WIDTH * pageIdx;
        m_pos.y = room.getMidY();
    }
}


VappLauncherRobotPreinstaller::preInstallTableEntry::preInstallTableEntry(
    VappWidgetSrcEnum source,
    VfxChar *type,
    VfxS32 pageIdx,
    VfxS32 x,
    VfxS32 y)
{
    //
    // Widget Id
    //
    m_source = source;
    m_typeKind = VappWidgetId::TYPE_KIND_INTEGER;
    m_type.ival = srv_appmgr_get_id_by_app_package_name(type);

    //
    // Position
    //
    m_pageIdx = pageIdx;

    VfxSize tileSize = VappLauncherRobotDesktop::getTileSize();

    VfxRect room = VappLauncherRobotDesktop::getRoom(tileSize, pageIdx, x, y);

    if (room == VFX_RECT_ZERO)
    {
        m_pos = VFX_POINT_ZERO;
    }
    else
    {
        m_pos.x = room.getMidX() - LCD_WIDTH * pageIdx;
        m_pos.y = room.getMidY();
    }
}


VfxS32 VappLauncherRobotPreinstaller::getPreInstalledNum() const
{
    VappWidgetKit *kit = VFX_OBJ_GET_INSTANCE(VappWidgetKit);
    VfxS32 numFromKit = kit->getPreInstalledNum();

    return s_sizeOfPreInstallTbl + numFromKit;
}


VfxS32 VappLauncherRobotPreinstaller::getPreInstalledWidget(
    VappWidgetPreInstalled **preInstalled,
    VfxS32 size) const
{
    VfxS32 totalNum = getPreInstalledNum();

    if (totalNum <= 0 || totalNum > size)
    {
        return 0;
    }

    //
    // Get the pre-installed widgets in this installer.
    //
    VfxS32 idx;

    for (idx = 0; idx < s_sizeOfPreInstallTbl; idx++)
    {
        if (s_preInstallTbl[idx].m_typeKind == VappWidgetId::TYPE_KIND_INTEGER)
        {
            preInstalled[idx]->m_id.assignWith(
                s_preInstallTbl[idx].m_source,
                s_preInstallTbl[idx].m_type.ival);
        }
        else if (s_preInstallTbl[idx].m_typeKind == VappWidgetId::TYPE_KIND_STRING)
        {
            preInstalled[idx]->m_id.assignWith(
                s_preInstallTbl[idx].m_source,
                s_preInstallTbl[idx].m_type.sval);
        }

        preInstalled[idx]->m_pageIdx = s_preInstallTbl[idx].m_pageIdx;
        preInstalled[idx]->m_pos = s_preInstallTbl[idx].m_pos;
    }

    //
    // Get the pre-installed widgets from the widget kit.
    //
    // NOTE:
    // this part should be removed after gadget phased-out. Becaues after we
    // support download UI, it isn't general to put pre-installed widget
    // configuration in the widget factory. But, the factory can be used to
    // create widgets for different launchers.
    //
    VappWidgetKit *kit = VFX_OBJ_GET_INSTANCE(VappWidgetKit);
    VfxS32 numFromKit = kit->getPreInstalledNum();

    VfxS32 realNum = kit->getPreInstalledWidget(preInstalled + idx, size - idx);
    VFX_ASSERT(realNum == numFromKit && realNum + idx == totalNum);

    return idx + numFromKit;
}

