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
 *  vapp_hs_widget_photo.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: photo album
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_HS_WIDGET_PHOTO_H__
#define __VAPP_HS_WIDGET_PHOTO_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_VUI_HOMESCREEN_PHOTO__
#include "vapp_hs_widget_base.h"
#include "HomeScreen\vadp_v2p_widget_photo.h"
#include "vapp_hs_def.h"
#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_signal.h"
#include "vfx_input_event.h"
#include "vfx_cpp_base.h"
#include "vfx_primitive_frame.h"
#include "vapp_hs_widget_cfg.h"
#include "vfx_sys_memory.h"
#include "vfx_draw_context.h"
#include "vfx_string.h"
#include "vfx_text_frame.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_HS_PHOTO_BUTTON_CLASS_NAME             "PHOTOBUTTON"

/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/***************************************************************************** 
 * Class VappHsWidgetPhotoButton
 *****************************************************************************/

/*
 * VappHsWidgetPhotoButton is a class that support the button of photo widget.
 *
 * EXAMPLE
 * <code>
 *  VappHsWidgetPhotoButton *button;
 *  VFX_OBJ_CREATE(button, VappHsWidgetPhotoButton, this);
 *  button->setPos(VfxPoint(13, 34));
 * </code>
 */ 
class VappHsWidgetPhotoButton : public VfxControl
{
    VFX_DECLARE_CLASS(VappHsWidgetPhotoButton);

// Constructor / Destructor    
public:
    // Default constructor
    VappHsWidgetPhotoButton();

    // Destructor
    virtual ~VappHsWidgetPhotoButton();

// Signal    
public:
    // Pen down signal
    VfxSignal1 <VfxPenEvent &> m_eventPenDown;

    // Pen up signal    
    VfxSignal1 <VfxPenEvent &> m_eventPenUp;

// Method
public:
    // Set image resource ID
    void setImage(
        VfxS32 upImage,     // [IN] up image ID
        VfxS32 downImage    // [IN] up image ID
    );

    // Set display flag    
    void setDisplay(
        VfxBool isDisplay   // [IN] display flag
    );

// Override    
private:
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

    // Up image resource ID
    VfxS32 m_imageUpId;

    // Down image resource ID
    VfxS32 m_imageDownId;
};


/***************************************************************************** 
 * Class VappHsWidgetPhoto
 *****************************************************************************/

/*
 * VappHsWidgetPhoto is a class that creates an photo widget.
 *
 * EXAMPLE
 * <code>
 *  VappHsWidgetPhoto *photo;
 *  VFX_OBJ_CREATE(photo, VappHsWidgetPhoto, this);
 * </code>
 */
class VappHsWidgetPhoto : public VappHsWidget
{
    VAPP_HS_WIDGET_CREATE(VappHsWidgetPhoto);

// Declaration
private:
    // The setting of photo widget
    enum
    {
    #ifdef __MMI_MAINLCD_320X480__
        DEFAULT_WIDTH   = 111,                               // Default width
        DEFAULT_HEIGHT  = 111, 
    #else
        DEFAULT_WIDTH   = 88,                               // Default width
        DEFAULT_HEIGHT  = 88,                               // Default height
    #endif
        MAX_WIDTH       = VAPP_WIDGET_PHOTO_MAX_WIDTH,      // Maximum width
        MAX_HEIGHT      = VAPP_WIDGET_PHOTO_MAX_HEIGHT,     // Maximum height
        MIN_WIDTH       = VAPP_WIDGET_PHOTO_MIN_WIDTH,      // Minimun width
        MIN_HEIGHT      = VAPP_WIDGET_PHOTO_MIN_HEIGHT      // Minimum height
    };

    // The border of photo widget
    enum
    {
        BORDER_H_TOP      = 11,      // Top pixels
        BORDER_H_BOTTOM   = 11,      // Bottom pixels
        BORDER_W_LEFT     = 11,      // Left pixels
        BORDER_W_RIGHT    = 11,      // Right pixels
        EXTEND_LEN        = 2       // Extend pixels
    };

    // The position of displaying image
    enum
    {
        IMAGE_OFFSET_X  = BORDER_W_LEFT,    // Offset x    
        IMAGE_OFFSET_Y  = BORDER_H_TOP      // Offset y
    };

    // The position of default string
    enum
    {
    #ifdef __MMI_MAINLCD_320X480__
        STR_OFFSET_X  = 0,      // Offset x    
        STR_OFFSET_Y  = 60      // Offset y
    #else
        STR_OFFSET_X  = 0,      // Offset x    
        STR_OFFSET_Y  = 50      // Offset y
    #endif
    };
    
// Constructor / Destructor     
public:
    // Default constructor
    VappHsWidgetPhoto();

    void launchApp();
    
// Override
public:
    // Get icon
    virtual VfxU16 getIcon();

    // Get name
    virtual VfxU16 getName();

    // Create the whole widget content
    virtual void onCreateView();

    // Release the whole widget content
    virtual void onReleaseView();

private:
    // On init
    virtual void onInit();
    
    // On pen input
    // RETURNS: VfxBool 
    virtual VfxBool onPenInput(
        VfxPenEvent &event
    );

    // On draw
    virtual void onDraw(
        VfxDrawContext &dc
    );

    virtual void onDirectLaunch();

// Variable
private:
    // Photo image frame
    VfxImageFrame *m_image;

    // File path
    VfxWString m_strFilename;

    // Button opacity
    VfxFloat m_butOpacity;

    // Default string
    VfxTextFrame    *m_strDefault;

};
/* use m_propertyContent to put background image and 
   use m_propertyContentPlacement = VF_FRAME_CONTENT_PLACEMENT_TYPE_TOP_LEFT.. */

#endif /* __MMI_VUI_HOMESCREEN_PHOTO__ */
#endif /* __VAPP_HS_WIDGET_PHOTO_H__ */
