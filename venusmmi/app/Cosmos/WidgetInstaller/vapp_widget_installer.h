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
 *  vapp_widget_installer.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_WIDGET_INSTALLER_H__
#define __VAPP_WIDGET_INSTALLER_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
class VappWidgetInstallerApp;
class VappWidgetInstallerScreen;
class VappWidgetInstallerPage;

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
enum VappWidgetInstallerAction
{
    VAPP_WGTINST_ACT_INSTALL_NONE,
    VAPP_WGTINST_ACT_INSTALL_CONT,
    VAPP_WGTINST_ACT_INSTALL_CANCEL,
    VAPP_WGTINST_ACT_SELECT_PHONE,
    VAPP_WGTINST_ACT_SELECT_MEMCARD,
    VAPP_WGTINST_ACT_POPUP_END
};


/***************************************************************************** 
 * Class VappWidgetInstallerApp
 *****************************************************************************/
class VappWidgetInstallerApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappWidgetInstallerApp);

// Enum
private:
    enum VappWidgetInstallerState
    {
        VAPP_WGTINST_STATE_NULL,
        VAPP_WGTINST_STATE_START,
        VAPP_WGTINST_STATE_QUERY,
        VAPP_WGTINST_STATE_CONT
    };

// Constructor
public:
    VappWidgetInstallerApp() : m_scrn(NULL), m_state(VAPP_WGTINST_STATE_NULL){}

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onDeinit();
    // Process close function. Invoke when application is closed in OOM scenario
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);

    // Continue close. Please refer VfxApp::continueClose
    virtual void continueClose(VfxAppCloseAnswerEnum answer);

// Method
public:
    // Callback function used to continue the installation
    void installWidgetCont(VfxS16 wgt_id, void* result);

    // Callback function used to finish the installation
    void installWidgetFinish(VfxS32 ret);

    static mmi_ret eventHandler(mmi_event_struct *evt);

// Helper function
private:
    // Get the page to display UI
    VappWidgetInstallerPage* getPage();

    // Signal handler used to receive action taken by user
    void onActionHandler(VappWidgetInstallerAction act);

// Data member
private:
    // Main screen
    VappWidgetInstallerScreen *m_scrn;

    // Installation state 
    VappWidgetInstallerState m_state;

    // Installed widget id
    VfxS16 m_id;
};


/***************************************************************************** 
 * Class VappWidgetInstallerScreen
 *****************************************************************************/
class VappWidgetInstallerScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappWidgetInstallerScreen);

// Constructor
public:
    VappWidgetInstallerScreen() : m_page(NULL) {};

// Override
public:
    virtual void on1stReady();

public:
    VappWidgetInstallerPage *m_page;
};


/***************************************************************************** 
 * Class VappWidgetInstallerPage
 *****************************************************************************/
class VappWidgetInstallerPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappWidgetInstallerPage);

private:

    // ID for tool bar and command popup
    enum VappWidgetInstallerId
    {
        ID_TOOLBAR_OK,
        ID_TOOLBAR_CANCEL,
        ID_DRIVE_PHONE,
        ID_DRIVE_MEMCARD,
        ID_DRIVE_CANCEL
    };

// Constructor
public:
   VappWidgetInstallerPage() 
   	: m_indicatorPopup(NULL)
   	{};

// Override
public:
    virtual void onInit();

// Method
private:
    // Display "Installing" indicator
    void displayIndicatorPopup();

    // Stop "Installing" indicator
    void stopIndicatorPopup();

    // Display popup
    void displayPopup(VcpPopupTypeEnum type, VfxResId id);

    // Display command popup to select drives
    void selectStorage();

    // Display installed widget information
    void displayWidgetInfo(void *result);

// Signal
private:
    VfxSignal1 <VappWidgetInstallerAction> m_signalAction;

// Properties
private:
    VcpIndicatorPopup *m_indicatorPopup;
    VfxWString m_text;

// Helper functions
private:
    void onPopupEnd(VfxObject* obj, VfxId id); 
    void eventHandler(VfxObject* obj, VfxId id);

friend class VappWidgetInstallerApp;
friend class VappWidgetInstallerScreen;
};


/***************************************************************************** 
 * Class VappWidgetPreInstallerPage
 *****************************************************************************/
class VappWidgetPreInstallerPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappWidgetPreInstallerPage);

// Override
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
};


#endif /* __VAPP_WIDGET_INSTALLER_H__ */

