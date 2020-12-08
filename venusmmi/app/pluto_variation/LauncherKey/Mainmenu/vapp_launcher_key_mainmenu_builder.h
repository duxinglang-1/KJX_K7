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
 *  vapp_key_mainmenu_builder.h
 *
 * Project:
 * --------
 *  Key Launcher
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

#ifndef __VAPP_LAUNCHER_KEY_MAINMENU_BUILDER_H__
#define __VAPP_LAUNCHER_KEY_MAINMENU_BUILDER_H__

#include "MMIDatatype.h"
#include "vfx_text_frame.h"
#include "vcp_page_menu_util.h"
#include "vcp_image_button.h"
#include "vapp_launcher_key_mainmenu_page_menu.h"
#include "vcp_marquee.h"

extern "C" {
#include "AppMgrSrvGprot.h"
}

/***************************************************************************** 
 * Class
 *****************************************************************************/

class VappKeyMainmenuCell : public VcpPageMenuCell
{
    VFX_DECLARE_CLASS(VappKeyMainmenuCell);

public:
    VappKeyMainmenuCell();
    VappKeyMainmenuCell(const VfxImageSrc & image, const VfxWString & title);

    void setCellAppName(mmi_app_package_name_struct appName);
    void getCellAppName(mmi_app_package_name_struct & result);

    void setIsPreinstall(VfxBool isPreinstall);
    VfxBool getIsPreinstall();
    void setEditMode(VfxBool editMode);
	void setAppCounter(VfxWString &appCounter);
    void setAppCounterHidden(VfxBool isHidden);
    void setTextFrameHidden(VfxBool isHidden);
    void setIsInstalled(VfxBool isInstalled);
    void setIsHighlighted(VfxBool isHighlighted, VfxBool update);
	void setIsBorderColor(VfxBool isBorder);
    VfxBool isFirstDisplay();

    virtual void onCellDisplay();
    void registerBadgeEvent();
	void startScroll();
	void stopScroll();

protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    void updateIconImage(const VfxImageSrc & image);
    void updateTitle(const VfxWString & title);
    void updateEditMode(VfxBool editMode);
    void updateIsPreinstall(VfxBool isPreinstall);
	void updateAppCounter(VfxWString &appCounter);
    void updateTextFrameHidden(VfxBool textFrameHidden);
    void updateIsInstalled(VfxBool isInstalled);
    void updateHighlightFrame();
    void onUninstallBtnClicked(VfxObject *obj, VfxId id);

    VfxImageSrc                 m_cellImage;
    VfxWString                  m_cellTitle;
	VfxWString					m_cellCounter;

    VfxBool                     m_firstDisplay;
    VfxBool                     m_editMode;
    VfxBool                     m_isPreinstall;
    VfxBool                     m_isAppCounterHidden;
    VfxBool                     m_isTextFrameHidden;
    VfxBool                     m_isInstalled;
    VfxBool                     m_isHighlighted;
	VfxBool						m_isBorderColor;
    VfxFrame *                  m_iconBgFrame;
    VfxFrame *                  m_iconBgFrameEdit;
    VfxFrame *                  m_iconFrame;
    VfxFrame *                  m_smallIconFrame;
    VfxTextFrame *              m_textFrame;
    VfxFrame *                  m_preinstallFrame;
    VfxTextFrame *              m_appCounterTextFrame;
    VfxFrame *                  m_appCounterBgFrame;
    VcpImageButton *            m_appUninstallBtn;
    VfxFrame *                  m_highlightFrame;
    VcpMarquee *                m_scrollText;
public:
	mmi_app_package_name_struct m_appName;
};

class VappKeyMainmenuBuilder : public VfxObject
{
    VFX_DECLARE_CLASS(VappKeyMainmenuBuilder);
    
public:
    VappKeyMainmenuBuilder();

    void setAppOrderData(mmi_app_package_name_struct orderData[], VfxS32 count);

    void loadMenu(VappKeyMainmenuPageMenu * menu, VfxBool preInstallChanged);
    void saveMenu(VappKeyMainmenuPageMenu * menu);
    void savePreinstallInfo(VappKeyMainmenuPageMenu * menu);
private:
    mmi_app_package_name_struct *   m_orderData;
    VfxS32                          m_orderDataCount;


    void initFrames(VappKeyMainmenuPageMenu * menu, VfxBool preInstallChanged);
    VfxS32 repositionFrameIndex(VappKeyMainmenuPageMenu * menu, VfxS32 index);
    void reorderFrames(VappKeyMainmenuPageMenu * menu);
};

VappKeyMainmenuCell * createKmmCell(mmi_app_package_name_struct & appName, VfxObject * parent, VfxBool preinstall);

VfxBool isKmmPreInstalledApp(mmi_app_package_name_struct appName, mmi_app_package_name_struct preInstalledApp[], VfxU32 preInstalledAppCount);
VfxBool isKmmInstalledApp(mmi_app_package_name_struct appName, mmi_app_package_name_struct installedApp[], VfxU32 installedAppCount);

#endif // __VAPP_LAUNCHER_KEY_MAINMENU_BUILDER_H__

