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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_desktop_popup_menu.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file defines the base of the popup menu.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_DESKTOP_POPUP_MENU_H
#define VAPP_DESKTOP_POPUP_MENU_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vfx_app_cat_scr.h"
#include "vapp_app_widget_primitive.h"


/*****************************************************************************
 * Desktop Popup Menu
 *****************************************************************************/

class VappDesktopPopupMenu : public VfxAppCatScr
{
   VFX_DECLARE_CLASS(VappDesktopPopupMenu);

// Constructor / Desctructor
public:
    // Default constructor.
    VappDesktopPopupMenu();

// Method
public:
    // Callback prototype.
    typedef void (*CallbackFunc)(const VappAppWidgetId &);

    // This function registers the selected callback.
    void registerCallback(
        CallbackFunc callback  // [IN] Callback
    );

// Method
protected:
    // This function closes this popup menu screen.
    void closeScreen();

    // This function gets the content bounds that client can layout their
    // components.
    // RETURNS: content bounds.
    VfxRect getContentBounds();

// Override
protected:
    // You can override this function to set your own title text on this popup
    // menu.
    virtual VfxBool getTitleText(
        VfxWString &text    // [OUT] Title text
    );

// Override
protected:
    // Please refer to VfxObject.
    virtual void onInit();

    // Please refer to VfxFrame.
    virtual VfxBool onKeyInput(
        VfxKeyEvent &event
    );

    // Please refer to VfxControl.
    VfxBool onPenInput(
        VfxPenEvent &event
    );

// Enum
private:
    enum
    {

    #if defined(__MMI_MAINLCD_480X800__)
        WIDTH = 420,
        HEIGHT = 660
    #elif defined(__MMI_MAINLCD_320X480__)
        WIDTH = 280,
        HEIGHT = 396
    #elif defined(__MMI_MAINLCD_240X400__)
        WIDTH = 210,
        HEIGHT = 330
    #else /* defined(__MMI_MAINLCD_240X320__) */
        WIDTH = 210,
        HEIGHT = 264
    #endif /* defined(__MMI_MAINLCD_240X320__) */

    };

// Variables
protected:
    // Callback function.
    CallbackFunc m_callback;

// Variables
private:
    // Background frame.
    VfxFrame *m_bgFrame;

    // Top bar of the popup menu.
    VfxImageFrame *m_topBar;

    // Bottom bar of the popup menu.
    VfxImageFrame *m_bottomBar;

// Implementation
private:
    // This function creates the background frame.
    void createBgFrame();

    // This function creates the top bar.
    void createTopBar();

    // This function creates the bottom bar.
    void createBottomBar();

    // This function gets the origin of the popup menu.
    // RETURN: Origin.
    VfxPoint getPopupOrigin() const;

    // This function close this popup menu.
    void onPostCloseScreen();
};

#endif /* defined(__MMI_VUI_LAUNCHER__) */
#endif /* VAPP_DESKTOP_POPUP_MENU_H */

