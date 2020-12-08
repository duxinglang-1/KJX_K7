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
 *  vapp_drawer_builder.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#ifndef __VAPP_DRAWER_BUILDER_H__
#define __VAPP_DRAWER_BUILDER_H__

#include "MMIDatatype.h"
#include "vfx_container.h"
#include "vfx_context.h"
#include "vfx_text_frame.h"
#include "vcp_page_menu_util.h"
#include "vcp_image_button.h"
#include "vapp_drawer_page_menu.h"

extern "C" {
#include "AppMgrSrvGprot.h"
}


/*****************************************************************************
 * Class VappDrawerCellStableFrame
 *****************************************************************************/

class VappDrawerCellStableFrame : public VfxFrame
{
    VFX_DECLARE_CLASS(VappDrawerCellStableFrame);

// Constructor / Destructor
public:
    VappDrawerCellStableFrame(){}
    VappDrawerCellStableFrame(mmi_app_package_name_struct *appPackageName, VfxImageSrc *appImage, VfxWString *appString);

// Method
public:
    void updateOnBottomBar(VfxBool onBottomBar);
    void updateIsPreinstall(VfxBool isPreinstall);
    void updateTextFrameHidden(VfxBool isTextFrameHidden);
    void updateEditMode(VfxBool editMode);
    
// Override
protected:
    // Overrde to provide the content of the frame.
    virtual void onDraw(
        VfxDrawContext &dc          // The draw context to draw in
    );
    
// Variable
private:
    mmi_app_package_name_struct *m_appPackageName;
    VfxImageSrc                 *m_appImage;
    VfxWString                  *m_appString;
    VfxS32                      m_appStringWidth;
    
    VfxBool                     m_onBottomBar;
    VfxBool                     m_isPreinstall;
    VfxBool                     m_isTextFrameHidden;
    VfxBool                     m_editMode;
    
// Implementation
private:
    void drawIcon(VfxDrawContext &dc);
    void drawTitle(VfxDrawContext &dc);
};


/***************************************************************************** 
 * Class VappDrawerCell
 *****************************************************************************/

class VappDrawerCell : public VcpPageMenuCell
{
    VFX_DECLARE_CLASS(VappDrawerCell);

public:
    VappDrawerCell();
    VappDrawerCell(const VfxImageSrc & image, const VfxWString & title);

    void setCellAppName(mmi_app_package_name_struct appName);
    void getCellAppName(mmi_app_package_name_struct & result);

    void setOnBottomBar(VfxBool onBottomBar);
    void setIsPreinstall(VfxBool isPreinstall);
    void setEditMode(VfxBool editMode);
    void setBadge(VfxWChar *badge);
    void setBadgeHidden(VfxBool isHidden);
    void setTextFrameHidden(VfxBool isHidden);
    void setIsInstalled(VfxBool isInstalled);

    VfxBool isFirstDisplay();

    static mmi_ret eventHandler(mmi_event_struct *event);
    
    virtual void onCellDisplay();

protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    void updateEditMode(VfxBool editMode);
    void updateBadge();
    void updateIsInstalled(VfxBool isInstalled);

    void onUninstallBtnClicked(VfxObject *obj, VfxId id);

    VfxImageSrc                 m_cellImage;
    VfxWString                  m_cellTitle;
    VfxWChar                    m_cellBadge[SRV_APPMGR_BADGE_MAX_LEN + 1];

    mmi_app_package_name_struct m_appName;
    VfxBool                     m_firstDisplay;
    VfxBool                     m_onBottomBar;
    VfxBool                     m_editMode;
    VfxBool                     m_isPreinstall;
    VfxBool                     m_isBadgeHidden;
    VfxBool                     m_isTextFrameHidden;
    VfxBool                     m_isInstalled;

    VappDrawerCellStableFrame   *m_stableFrameContainer;
    VcpImageButton              *m_appUninstallBtn;
    VfxFrame                    *m_badgeBgFrame;
    VfxTextFrame                *m_badgeTextFrame;

    static VfxContext                   *s_cellListCntx;
    static VfxList <VappDrawerCell *>   s_cellList;
};

class VappDrawerBuilder : public VfxObject
{
    VFX_DECLARE_CLASS(VappDrawerBuilder);
    
public:
    VappDrawerBuilder();

    void setAppOrderData(mmi_app_package_name_struct orderData[], VfxS32 count);
    void setAppGroupData(mmi_app_package_name_struct groupData[], VfxS32 count);

    void loadMenu(VappDrawerPageMenu * menu);
    void saveMenu(VappDrawerPageMenu * menu);

private:
    mmi_app_package_name_struct *   m_orderData;
    VfxS32                          m_orderDataCount;
    mmi_app_package_name_struct *   m_groupData;
    VfxS32                          m_groupDataCount;


    void initFrames(VappDrawerPageMenu * menu);
    VfxS32 repositionFrameIndex(VappDrawerPageMenu * menu, VfxS32 index);
    void reorderFrames(VappDrawerPageMenu * menu);
};

VappDrawerCell * createDrawerCell(mmi_app_package_name_struct & appName, VfxObject * parent, VfxBool preinstall);
VappDrawerCell * createDrawerCellRaw(VfxImageSrc image, const VfxWString &title, VfxFrame * parent);

VfxBool isPreInstalledApp(mmi_app_package_name_struct appName, mmi_app_package_name_struct preInstalledApp[], VfxU32 preInstalledAppCount);
VfxBool isInstalledApp(mmi_app_package_name_struct appName, mmi_app_package_name_struct installedApp[], VfxU32 installedAppCount);

#endif // __VAPP_DRAWER_BUILDER_H__

