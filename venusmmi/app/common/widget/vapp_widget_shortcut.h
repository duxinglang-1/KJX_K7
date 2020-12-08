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
 *  vapp_widget_shortcut.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the shortcut widget.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_WIDGET_SHORTCUT_H
#define VAPP_WIDGET_SHORTCUT_H

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_FACTORY__) && defined(__COSMOS_MMI_PACKAGE__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_launcher_cosmos_mm_builder.h"
#include "vapp_widget.h"
#include "vapp_widget_primitive.h"
#include "MMIDatatype.h"

/*****************************************************************************
 * Shortcut Content Frame
 *****************************************************************************/

class VappWidgetShortcut;


class VappWidgetShortcutContent : public VfxControl
{
    VFX_DECLARE_CLASS(VappWidgetShortcutContent);

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetShortcutContent();

// Signal
public:
    // This signal is emitted when the shortcut changes its highlight.
    VfxSignal1 <
        VfxBool                         // [IN] Highlight or not
    > m_signalHighlightChanged;

    // This signal is emitted when the user taps the shortcut.
    VfxSignal0 m_signalTapped;

// Method
public:
    // This function creates this shortcut content associated with the specified
    // shortcut widget.
    //
    // NOTE: at present, you cannot create view twice for the same object.
    void createView(
        VappWidgetShortcut *shortcut    // [IN] Shortcut widget
    );

    // This function hides or unhides the counter on the shortcut frame.
    void setCounterHidden(
        VfxBool isHidden    // [IN] Hidden or not
    );

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

    // Please refer to VfxControl.
    virtual VfxBool onPenInput(
        VfxPenEvent &event
    );

private:
    void OnTimerOut(VfxTimer *timer);

// Variable
private:
    // Main menu cell.
    VappLauncherCosmosMmCell *m_cell;

    VfxTimer *m_timer;
};


/*****************************************************************************
 * Shortcut Widget
 *****************************************************************************/

class VappWidgetShortcut : public VappWidget
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetShortcut);

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetShortcut();

    // Default destructor
    ~VappWidgetShortcut();

// Method
public:
    // This function sets the application package name of this shortcut.
    void setPackage(
        const VfxS32 package  // [IN] Application name
    );

    // This function gets the application package name of this shortcut.
    // RETURNS: application name.
    const VfxS32 getPackage();

    // This function checks if this application is a pre-installed application.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isPreInstalled() const;

// Override
public:
    // Please refer to VappWidget.
    virtual VappWidgetId getId() const;

    // Please refer to VappWidget.
    virtual VfxS32 getName(
        VfxWChar *string,
        VfxS32 size
    ) const;

    // Please refer to VappWidget.
    virtual VfxSize getMaxSize() const;

    // Please refer to VappWidget.
    virtual VfxFrame *createIcon(
        VfxObject *parentObj
    );

    void updateContent();

// Override
protected:
    // Please refer to VappWidget.
    virtual void onCreateView();

    // Please refer to VappWidget.
    virtual void onReleaseView();

    // Please refer to VappWidget.
    virtual void onSerializeView(VfxArchive *ar);

    // Please refer to VappWidget.
    virtual void onRestoreView(VfxArchive *ar);

    // Please refer to VappWidget.
    virtual void onEnterEditMode();

    // Please refer to VappWidget.
    virtual void onExitEditMode();

    // Please refer to VappWidget.
    virtual VfxPoint onGetEditButtonOffset();

// Enum
private:
    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
        MAX_SIZE_WIDTH = 120,
        MAX_SIZE_HEIGHT = 120,
        ICON_HEIGHT = 94,
        EDIT_BUTTON_OFFSET_X = 25,
        EDIT_BUTTON_OFFSET_Y = 33
    #elif defined(__MMI_MAINLCD_320X480__)
        MAX_SIZE_WIDTH = 80,
        MAX_SIZE_HEIGHT = 84,
        ICON_HEIGHT = 74,
        EDIT_BUTTON_OFFSET_X = 23,
        EDIT_BUTTON_OFFSET_Y = 25
    #elif defined(__MMI_MAINLCD_240X400__)
        MAX_SIZE_WIDTH = 60,
        MAX_SIZE_HEIGHT = 71,
        ICON_HEIGHT = 59,
        EDIT_BUTTON_OFFSET_X = 19,
        EDIT_BUTTON_OFFSET_Y = 15
    #else /* defined(__MMI_MAINLCD_240X320__) */
        MAX_SIZE_WIDTH = 60,
        MAX_SIZE_HEIGHT = 70,
        ICON_HEIGHT = 59,
        EDIT_BUTTON_OFFSET_X = 18,
        EDIT_BUTTON_OFFSET_Y = 15
    #endif /* /* defined(__MMI_MAINLCD_240X320__) */
    };

// Variable
private:
    // App package name, which is used as an ID for application manager.
    VfxS32 m_package;

    // Content frame of the shortcut.
    VappWidgetShortcutContent *m_content;

    // Opacity when the user taps the shortcut.
    static const VfxFloat s_opacityTapped;

// Implementation
private:
    // This function checks if this shortcut is a native APP's shortcut.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isNativeApp() const;

    // This function creates the content of this shortcut.
    // RETURNS: shortcut content frame.
    VappWidgetShortcutContent *createContent();

    // This function handles the signal when the content is tapped.
    void onContentTapped();

    // This function handles the signal when the content changes its highlight.
    void onHighlightChanged(
        VfxBool isHighlighted   // [IN] Highlight or not
    );

    // This function post-invokes the shortcut.
    void onPostInvoke(
        void *userData      // [IN] User data
    );

    // This function post-deletes the shortcut.
    void onPostDelete(
        void *userData      // [IN] User data
    );

    // This function clears the allocated memory.
    void clear();

    static mmi_ret eventHandler(mmi_event_struct *event);

    void uninstallUpdate(const mmi_app_package_char *package);
};


/*****************************************************************************
 * Shortcut Widget Manager
 *****************************************************************************/
 
class VappWidgetShortcutManager : public VfxObject
{
    VFX_DECLARE_CLASS(VappWidgetShortcutManager);

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetShortcutManager();

    // Default destructor
    ~VappWidgetShortcutManager();

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxObject.
    virtual void onDeinit();

// Method
public:
    static mmi_ret eventHandler(mmi_event_struct *event);

    // This function gets the instance of the manager.
    // RETURNS: manager.
    static VappWidgetShortcutManager *getInstance();

    // This function adds MRE widget to the manager.
    static void add(
        VappWidgetShortcut *widget   // [IN] Manager
    );

    // This function removes the MRE widget from the manager.
    static void remove(
        VappWidgetShortcut *widget   // [IN] Manager
    );

// Variable
private:
    // Widget manager.
    static VappWidgetShortcutManager *s_mgr;    

    // Widget list.
    VfxObjList m_shortcutList;

};

#endif /* defined(__MMI_VUI_WIDGET_FACTORY__) && defined(__COSMOS_MMI_PACKAGE__) */
#endif /* VAPP_WIDGET_SHORTCUT_H */

