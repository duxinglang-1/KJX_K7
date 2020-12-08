/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_hs_widget_profile.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: Profile
 *
 *  Author: 
 * -------
 *  Xudong Sun (MTK80223)
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
#ifndef __VAPP_HS_WIDGET_PROFILE_H__
#define __VAPP_HS_WIDGET_PROFILE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
//#include "vfx_uc_include.h"


#ifdef __MMI_VUI_HOMESCREEN_PROFILE__
#include "vapp_hs_widget_base.h"
#include "HomeScreen\vadp_v2p_widget_profile.h"
#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_signal.h"
#include "vfx_input_event.h"
#include "vfx_cpp_base.h"
#include "vfx_primitive_frame.h"
#include "vapp_hs_widget_cfg.h"
#include "vapp_hs_def.h"
#include "vfx_sys_memory.h"
#include "vfx_timer.h"
//#include "mmi_rp_app_venus_homescreen_wg_profile_def.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_HS_PROFILE_BUTTON_CLASS_NAME             "PROFILEBUTTON"

/***************************************************************************** 
 * Class VappHsWidgetProfileButton
 *****************************************************************************/

/*
 * VappHsWidgetProfileButton is a class that support the button of profile widget.
 *
 * EXAMPLE
 * <code>
 *  VappHsWidgetProfileButton *button;
 *  VFX_OBJ_CREATE(button, VappHsWidgetProfileButton, this);
 *  button->setPos(VfxPoint(13, 34));
 * </code>
 */ 
class VappHsWidgetProfileButton : public VfxControl
{
    VFX_DECLARE_CLASS(VappHsWidgetProfileButton);
    
// Constructor / Destructor    
public:
    // Default constructor
    VappHsWidgetProfileButton();

    // Destructor
    virtual ~VappHsWidgetProfileButton();

// Signal
public:
    // Pen down signal
    VfxSignal2 <VappHsWidgetProfileButton *, VfxPenEvent &> m_eventPenDown;

// Method
public:
    // Set image resource ID
    void setResId(
        VfxS32 imageId    // [IN] image ID
    );

// Override
public:
    // On init
    virtual void onInit();

    // On deinit
    virtual void onDeinit();

    // On pen input
    // RETURNS: VfxBool    
    virtual VfxBool onPenInput(VfxPenEvent &event);
    
// Variable
private:
    // Image frame
    VfxImageFrame *m_image; 

};

/***************************************************************************** 
 * Home screen widget: profile
 *****************************************************************************/
class VappHsWidgetProfile : public VappHsWidget
{
    VAPP_HS_WIDGET_CREATE(VappHsWidgetProfile);

// Declaration
private:
    //Position, offset
#if defined(__MMI_MAINLCD_320X480__)
    enum
    {
        PROFILE_LEFT_OFFSET_S_X = 7,    // The small profile start offset x
        PROFILE_LEFT_OFFSET_S_Y = 18,   // The small profile start offset y
        PROFILE_LEFT_OFFSET_L_X = 7,    // The large profile start offset x
        PROFILE_LEFT_OFFSET_L_Y = 0,    // The large profile start offset y
        PROFILE_GAP             = 2,    // Profile gap
        PROFILE_LARGE_SIZE_X    = 64,   // The large profile imge size x
        PROFILE_SMALL_SIZE_X    = 43,   // The small profile imge size x
        PROFILE_CURRBG_SIZE_X   = 82,   // The highlight profile background imge size x
        PROFILE_LARGE_OFFSET_X  = 9,    // The large profile offset x
        PROFILE_LARGE_OFFSET_Y  = 8,    // The large profile offset y
        PROFILE_BG_OFFSET_X     = 0,    // The profile background image offset x
        PROFILE_BG_OFFSET_Y     = 11     // The profile background image offset y
    };
#else /*__MMI_MAINLCD_320X480__*/
    enum
    {
        PROFILE_LEFT_OFFSET_S_X = 5,    // The small profile start offset x
        PROFILE_LEFT_OFFSET_S_Y = 14,   // The small profile start offset y
        PROFILE_LEFT_OFFSET_L_X = 5,    // The large profile start offset x
        PROFILE_LEFT_OFFSET_L_Y = 0,    // The large profile start offset y
        PROFILE_GAP             = 1,    // Profile gap
        PROFILE_LARGE_SIZE_X    = 44,   // The large profile imge size x
        PROFILE_SMALL_SIZE_X    = 31,   // The small profile imge size x
        PROFILE_CURRBG_SIZE_X   = 58,   // The highlight profile background imge size x
        PROFILE_LARGE_OFFSET_X  = 7,    // The large profile offset x
        PROFILE_LARGE_OFFSET_Y  = 7,    // The large profile offset y
        PROFILE_BG_OFFSET_X     = 0,    // The profile background image offset x
        PROFILE_BG_OFFSET_Y     = 8     // The profile background image offset y
    };
#endif /*__MMI_MAINLCD_320X480__*/

    //constant
    enum
    {
        PROFILE_WIDGET_MOVE_LENGTH      = 7,    //
        PROFILE_WIDGET_HIDDEN_TIMER     = 3000  //
    };

// Constructor / Destructor
public:

// Method
public:
    // get the image ID of widget bar icon
    // RETURNS: image ID
    virtual VfxU16 getIcon();

    // Get string resource ID for the name of this widget
    // RETURNS: string ID
    virtual VfxU16 getName();
    
    // create the whole widget content
    virtual void onCreateView();

    // release the whole widget content
    virtual void onReleaseView();

// Override
protected: 
    // On Init
    virtual void onInit();

    // On Deinit
    virtual void onDeinit();

    // On pen input
    // RETURNS: VfxBool     
    virtual VfxBool onPenInput(VfxPenEvent &event);

// Variable
private:
    // Current activated profile
    VfxU8 m_activatedProfile;
    
    // Highlight profile
    VfxU8 m_highlightProfile;
    
    // Display all flag
    VfxBool m_isDisplayAll;
    
    // Widget view created flag
    VfxBool m_isViewCreated;
    
    // Background image for profile widget
    VfxImageFrame *m_imageBg;
    
    //A rectangle image to distinguish between activated profile and others.
    VfxImageFrame *m_imageActivity;
    
    // Background image for highlight profiles
    VfxImageFrame *m_imageCurrBg;

    // All profiles object pointer.
    VappHsWidgetProfileButton * m_profiles[TOTLE_PROFILES];

    // Polling timer
    VfxTimer *m_timer;
    
    // Current pen down profile button
    VappHsWidgetProfileButton * m_penDownProfile;

// Implementation
private:
    // Update display the profile widget
    void updateDisplay(void);
    
    // Pen down handler
    void profilePenDownHdlr(
        VappHsWidgetProfileButton * profile_p,//[IN] the pointer to profile button object.
        VfxPenEvent &event  // [IN] pen event
    );

    // Pen up handler
    void profilePenUpHdlr(
        VappHsWidgetProfileButton * profile_p, //[IN] the pointer to profile button object.
        VfxPenEvent &event  // [IN] pen event
    );

    // Get profile id
    VfxU8 getProfileId(
        const VappHsWidgetProfileButton * profile_p //[IN] the pointer to profile button object.
    ) const;

    // Start polling timer
    void startSetHiddenTimer(void);

    // Stop polling timer
    void stopSetHiddenTimer(void);

    // Timer callback
    void setHiddenButton(
        VfxTimer *source    // [IN] timer
    );
    
};

#endif /*__MMI_VUI_HOMESCREEN_PROFILE__*/
#endif /* __VAPP_HS_WIDGET_PROFILE_H__ */

