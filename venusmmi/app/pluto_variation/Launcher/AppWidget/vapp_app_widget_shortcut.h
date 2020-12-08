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
 *  vapp_app_widget_shortcut.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_APP_WIDGET_SHORTCUT_H
#define VAPP_APP_WIDGET_SHORTCUT_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_app_widget.h"
#include "vapp_app_widget_primitive.h"
#include "vapp_drawer_builder.h"


/*****************************************************************************
 * Shortcut Widget
 *****************************************************************************/

class VappAppWidgetShortcut : public VappAppWidget
{
    VAPP_APP_WIDGET_DECLARE_CLASS(VappAppWidgetShortcut);

// Constructor / Destructor
public:
    // Default constructor
    VappAppWidgetShortcut();

    // Default destructor
    ~VappAppWidgetShortcut();

// Method
public:
    // This function sets the application package name of this shortcut.
    void setPackage(
        const VfxChar *package  // [IN] Application name
    );

    // This function gets the application package name of this shortcut.
    // RETURNS: application name.
    const VfxChar *getPackage();

    // This function checks if this application is a pre-installed application.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isPreInstalled() const;

// Override
public:
    // Please refer to VappAppWidget.
    virtual VappAppWidgetId getId() const;

    // Please refer to VappAppWidget.
    virtual VfxS32 getName(
        VfxWChar *string,
        VfxS32 size
    ) const;

    // Please refer to VappAppWidget.
    virtual VfxSize getMaxSize() const;

    // Please refer to VappAppWidget.
    virtual VfxFrame *createIcon(
        VfxObject *parentObj
    );

    // Please refer to VappAppWidget.
    virtual void onTap(
        const VfxPoint &pos
    );

// Override
protected:
    // Please refer to VfxControl.
    virtual VfxBool onPenInput(
        VfxPenEvent &event
    );

    // Please refer to VappAppWidget.
    virtual void onDrag(
        VfxPenEvent &event
    );

    // Please refer to VappAppWidget.
    virtual void onCreateView();

    // Please refer to VappAppWidget.
    virtual void onReleaseView();

    // Please refer to VappAppWidget.
    virtual void onEnterEditMode();

    // Please refer to VappAppWidget.
    virtual void onExitEditMode();

    // Please refer to VappAppWidget.
    virtual VfxPoint onGetEditButtonOffset();

// Enum
private:
    enum
    {
        ICON_HEIGHT = 59,
        EDIT_BUTTON_OFFSET_X = 24,
        EDIT_BUTTON_OFFSET_Y = 23,
        HORIZ_TILE_NUM = 1,
        VERTI_TILE_NUM = 1
    };

// Variable
private:
    // App package name, which is used as an ID for application manager.
    VfxChar *m_package;

    // Main menu cell.
    VappDrawerCell *m_cell;

// Implementation
private:

    // This function checks if this shortcut is a native APP's shortcut.
    // RETURNS: On yes, return VFX_TRUE; otherwise, return VFX_FALSE.
    VfxBool isNativeApp() const;

    // This function creates the shortcut content cell.
    // RETURNS: app icon cell.
    VappDrawerCell *createCell();

    // This function sets the highlight effect on or off.
    void setHighlighted(
        VfxBool isOn    // [IN] On or off
    );

    static mmi_ret eventHandler(mmi_event_struct *event);

    void uninstallUpdate(const mmi_app_package_char *package);

    // This function post-deletes the shortcut.
    void onPostDelete(
        void *userData      // [IN] User data
    );

    // This function clears the allocated memory.
    void clear();
};

#endif /* defined(__MMI_VUI_LAUNCHER__) */
#endif /* VAPP_APP_WIDGET_SHORTCUT_H */

