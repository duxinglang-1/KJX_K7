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
 *  vapp_launcher_mm_builder.h
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


#ifndef __VAPP_LAUNCHER_MM_BUILDER_H__
#define __VAPP_LAUNCHER_MM_BUILDER_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_LAUNCHER_MM__


/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMIDatatype.h"

#include "vfx_container.h"
#include "vfx_font_desc.h"
#include "vfx_image_src.h"
#include "vfx_object.h"
#include "vfx_text_frame.h"
#include "vfx_timer.h"

#include "vcp_page_menu_util.h"
#include "vcp_image_button.h"

#include "vapp_launcher_mm_page_menu.h"

extern "C"
{
#include "AppMgrSrvGprot.h"
}


/*****************************************************************************
 * Static Constant
 *****************************************************************************/

#if defined(__MMI_MAINLCD_480X800__)
static const VfxS32 VAPP_LAUNCHER_MM_CELL_TITLE_FONT_SIZE = 19; // font size 21 = real size 23

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
static const VfxS32 VAPP_LAUNCHER_MM_CELL_TITLE_FONT_SIZE = 12; // font size 11 = real size 12

#else // default HVGA 320X480
static const VfxS32 VAPP_LAUNCHER_MM_CELL_TITLE_FONT_SIZE = 13; // font size 13 = real size 15

#endif


/*****************************************************************************
 * Pre-declaration
 *****************************************************************************/

class VappLauncherMmCell;

struct VappLauncherMmAppOrderDataStruct;
struct VappLauncherMmAppFolderDataStruct;


/*****************************************************************************
 * Global Function
 *****************************************************************************/

VappLauncherMmCell *vappLauncherMmCreateCell(mmi_app_package_name_struct &appName, VfxObject *parent, VfxBool preinstall);

VappLauncherMmCell *vappLauncherMmCreateCellRaw(VfxImageSrc image, const VfxWString &title, VfxFrame *parent);

VfxBool vappLauncherMmisPreInstalledApp(mmi_app_package_name_struct appName, mmi_app_package_name_struct preInstalledApp[], VfxU32 preInstalledAppCount);
VfxBool vappLauncherMmIsInstalledApp(mmi_app_package_name_struct appName, mmi_app_package_name_struct installedApp[], VfxU32 installedAppCount);


/*****************************************************************************
 * Class VappLauncherMmCellList
 *****************************************************************************/

class VappLauncherMmCellList : public VfxObject
{
    VFX_DECLARE_CLASS(VappLauncherMmCellList);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappLauncherMmCellList);

// Constructor / Destructor
public:
    VappLauncherMmCellList() {};
    virtual ~VappLauncherMmCellList() {};

// Method
public:
    void init(IVfxAllocatable *owner)
    {
        m_cellList.init(owner);
    };
    
    void deinit()
    {
        m_cellList.deinit();
    };
    
    VfxList <VappLauncherMmCell *>::It begin()
    {
        return m_cellList.begin();
    };
    
    VfxBool empty() const
    {
        return m_cellList.empty();
    };
    
    void pushBack(VappLauncherMmCell *const &cell)
    {
        m_cellList.pushBack(cell);
    };
    
    void remove(VappLauncherMmCell *const &cell)
    {
        m_cellList.remove(cell);
    };
    
    vrt_list_handle getHandle() const
    {
        return m_cellList.getHandle();
    };
    
// Variable
private:
    VfxList <VappLauncherMmCell *> m_cellList;
};


/*****************************************************************************
 * Class VappLauncherMmCellStableFrame
 *****************************************************************************/

class VappLauncherMmCellStableFrame : public VfxFrame
{
    VFX_DECLARE_CLASS(VappLauncherMmCellStableFrame);

// Declaration
private:
    enum
    {
        // APP name font effect
        VAPP_LAUNCHER_MM_CELL_APP_NAME_SHADOW_DEGREE        = 270,
        VAPP_LAUNCHER_MM_CELL_APP_NAME_SHADOW_DISTANT       = 2,
        VAPP_LAUNCHER_MM_CELL_APP_NAME_SHADOW_RANGE         = 1,
        VAPP_LAUNCHER_MM_CELL_APP_NAME_SHADOW_TRANSPARENCY  = 80
    };

// Constructor / Destructor
public:
    VappLauncherMmCellStableFrame(){}
    VappLauncherMmCellStableFrame(mmi_app_package_name_struct *appPackageName, VfxImageSrc *appImage, VfxWString *appString);

// Method
public:
    void updateIsPreinstall(VfxBool isPreinstall);
    void updateTextFrameHidden(VfxBool isTextFrameHidden);

    static void createIconBgImageBuffer(IVfxAllocatable *cntx);
    static void closeIconBgImageBuffer();
    
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
    
    VfxBool                     m_isPreinstall;
    VfxBool                     m_isTextFrameHidden;
    
    static VfxImageBuffer       s_iconBg;
    static VfxU8                *s_iconBgImageBuffer;
    
// Implementation
private:
    void drawIcon(VfxDrawContext &dc);
    void drawTitle(VfxDrawContext &dc);
};


/*****************************************************************************
 * Class VappLauncherMmCell
 *****************************************************************************/

class VappLauncherMmCell : public VcpPageMenuCell
{
    VFX_DECLARE_CLASS(VappLauncherMmCell);

// Constructor / Destructor
public:
    VappLauncherMmCell(){}
    VappLauncherMmCell(const VfxImageSrc &image, const VfxWString &title);

// Method
public:
    void setCellAppName(mmi_app_package_name_struct appName);
    void getCellAppName(mmi_app_package_name_struct &result);

    void setCellTitle(VfxWString title);
    void getCellTitle(VfxWString *title);
    
    void setEditMode(VfxBool editMode);
    void setIsPreinstall(VfxBool isPreinstall);
    VfxBool getIsPreinstall();
    void setBadge(VfxWChar *badge);
    void setBadgeHidden(VfxBool isHidden);
    void setTextFrameHidden(VfxBool isHidden);
    void setIsInstalled(VfxBool isInstalled);
    void setUninstalledButtonHidden(VfxBool isHidden);

    // The animation of scaling the deleting icon.
    void scaleDeletingIcon();

    void setFolderFrameScale(VfxBool isScale);
    void setFolderFrameHidden(VfxBool isHidden);

    // MAUI_03228575
    // Set the image to be a null image
    void resetCellImage() {m_cellImage.setNull();}

// Override
public:
    virtual void onCellDisplay();

protected:
    virtual void onInit();
    virtual void onDeinit();
    
//signal
public:
    VfxSignal1 <VfxBool > m_signalDeleteIconScaled;

// Variable
private:
    mmi_app_package_name_struct m_appName;
    VfxImageSrc                 m_cellImage;
    VfxWString                  m_cellTitle;
    VfxWChar                    m_cellBadge[SRV_APPMGR_BADGE_MAX_LEN + 1];
    
    VfxBool                     m_firstDisplay;
    VfxBool                     m_editMode;
    VfxBool                     m_isPreinstall;
    VfxBool                     m_isBadgeHidden;
    VfxBool                     m_isTextFrameHidden;
    VfxBool                     m_isInstalled;    
    VfxBool                     m_isUninstalledButtonHidden;
    VfxBool                     m_isFolderFrameScale;
    VfxBool                     m_isFolderFrameHidden;

    VfxFrame                        *m_folderIconFrame;
    VappLauncherMmCellStableFrame   *m_stableFrameContainer;
    VcpImageButton                  *m_appUninstallBtn;
    VfxFrame                        *m_badgeBgFrame;
    VfxTextFrame                    *m_badgeTextFrame;

    VfxTransformTimeline                *m_scaleDeletingIconTimeline;
    
// Implementation
private:
    void updateEditMode(VfxBool editMode);
    void updateBadge();
    void updateIsInstalled(VfxBool isInstalled);
    void updateUninstalledButtonHidden(VfxBool isHidden);
    void onUninstallBtnClicked(VfxObject *obj, VfxId id);
    void onScaleTimelineStop(VfxBaseTimeline *timeline, VfxBool isComplete);

    static mmi_ret eventHandler(mmi_event_struct *event);
};


/*****************************************************************************
 * Class VappLauncherMmBuilder
 *****************************************************************************/

class VappLauncherMmBuilder : public VfxObject
{
    VFX_DECLARE_CLASS(VappLauncherMmBuilder);

// Constructor / Destructor
public:
    VappLauncherMmBuilder();

// Method
public:
    void setFolderData(VappLauncherMmAppFolderDataStruct allFolderData[], VfxS32 count);
    
    void setAppOrderData(VappLauncherMmAppOrderDataStruct orderData[], VfxS32 count);
    void setAppGroupData(VappLauncherMmAppOrderDataStruct groupData[], VfxS32 count);

    void loadMenu(VappLauncherMmPageMenu *menu, mmi_app_package_name_struct *uninstallingCellAppPackageName, VappLauncherMmCell **uninstallingCell);
    void saveMenu(VappLauncherMmPageMenu *menu);

// Variable
private:
    VappLauncherMmAppFolderDataStruct   *m_allFolderData;
    VfxS32                              m_allFolderDataCount;
    
    VappLauncherMmAppOrderDataStruct    *m_orderData;
    VfxS32                              m_orderDataCount;
    VappLauncherMmAppOrderDataStruct    *m_groupData;
    VfxS32                              m_groupDataCount;

// Implementation
private:
    VfxS32 repositionFrameIndex(VappLauncherMmPageMenu *menu, VfxS32 index);
};


#endif // __MMI_VUI_LAUNCHER_MM__


#endif // __VAPP_LAUNCHER_MM_BUILDER_H__

