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
 *  vcp_command_title.h
 *
 * Project:
 * --------
 *  Venus UI Components
 *
 * Description:
 * ------------
 *  Command title component
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_COMMAND_TITLE_H__
#define __VCP_COMMAND_TITLE_H__
 
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_datatype.h"
#include "vfx_object.h"
#include "vfx_control.h"
#include "vfx_class_info.h"
#include "vfx_string.h"
#include "vfx_frame.h"
#include "vfx_signal.h"
#include "vcp_state_image.h"
#include "vfx_cpp_base.h"
#include "vfx_text_frame.h"
#include "vfx_basic_type.h"
#include "vcp_button.h"
#include "vfx_weak_ptr.h"

class VcpCommandTitle;

// button callback funtion prototype
typedef VfxCallback2<VfxObject*, VfxId> VcpCommandTitleButtonCB;


/***************************************************************************** 
 * Class VcpCommandTitle
 *****************************************************************************/
class VcpCommandTitle : public VfxControl
{
    VFX_DECLARE_CLASS(VcpCommandTitle);

// Constructor / Destructor
public:
    // <group DOM_CommandTitle_VcpCommandTitle_Constructor/Destructor>
    // Default constructor
    VcpCommandTitle();

// Overridable
public:
    // <group DOM_CommandTitle_VcpCommandTitle_Overridable>
    // Set text of the title
    virtual void setText (
        const VfxWString &str       // [IN] Title text
    );

    // <group DOM_CommandTitle_VcpCommandTitle_Overridable>
    // Get string of the button
    // RETURNS: string object
    virtual VfxWString getText () const
    {
        return (m_frameText) ? (m_frameText->getString()) : (VFX_WSTR_NULL);
    }

    // <group DOM_CommandTitle_VcpCommandTitle_Overridable>
    // Set add-on frame item
    virtual void setAddOnFrame (
        VfxU32 index,               // [IN] index of the frame, should be 0 or 1
        VfxFrame *frame             // [IN] Add-on frame
    );

    // <group DOM_CommandTitle_VcpCommandTitle_Overridable>
    // Set add-on frame item with text button
    virtual void setAddOnTextButton (
        VfxU32 index,                   // [IN] index of the frame, should be 0 or 1
        const VfxWString &str,          // [IN] text
        VfxId id,                       // [IN] id of the button
        VcpCommandTitleButtonCB handler // [IN] button handler
    );

    // <group DOM_CommandTitle_VcpCommandTitle_Overridable>
    // Set add-on frame item with image button
    virtual void setAddOnImageButton (
        VfxU32 index,                   // [IN] index of the frame, should be 0 or 1
        const VcpStateImage &imageList, // [IN] image
        VfxId id,                       // [IN] id
        VcpCommandTitleButtonCB handler // [IN] button handler
    );

    // <group DOM_CommandTitle_VcpCommandTitle_Overridable>
    // enable / disable one button
    virtual void setButtonIsDisabled (
        VfxId id,                       // [IN] button ID
        VfxBool isDisabled              // [IN] whether it is enabled
    );

    // <group DOM_CommandTitle_VcpCommandTitle_Overridable>
    // get whether one button is enabled
    // RETURNS: VfxBool
    virtual VfxBool getButtonIsDisabled (
        VfxId id                        // [IN] button ID
    ) const ;

// Override
protected:
    virtual void onInit();
    virtual void onDeInit();
    virtual void onUpdate();

// Implementation
private:
    enum
    {
        MAX_ADDON_FRAMES = 2,   // max number of add-on frames
#if defined(__MMI_MAINLCD_320X480__)
        DEFAULT_HEIGHT = 46,
        BUTTON_MIN_WIDTH = 75,
        BUTTON_HEIGHT = 32,
#else
        DEFAULT_HEIGHT = 34,
        BUTTON_MIN_WIDTH = 51,
        BUTTON_HEIGHT = 26,
#endif
        GAP = 2                 // gap between text and add-on item  
    };

private:
    // Positive frame
    VfxFrame* m_frameAddOn[MAX_ADDON_FRAMES];

    // Middle text frame
    VfxTextFrame *m_frameText;

    // Size of text
    VfxSize m_sizeText;

    // title button
    VfxWeakPtr<VcpButton> m_button[MAX_ADDON_FRAMES];

    // title button callback function
    VcpCommandTitleButtonCB m_callback[MAX_ADDON_FRAMES];

    // title button user data
    VfxId m_buttonId[MAX_ADDON_FRAMES];

private:
    // update button while bounds change
    void onBoundsChanged(VfxFrame *frame, const VfxRect &old) {checkUpdate();}

    // default title button handle
    void buttonClick(VfxObject* sender, VfxId id);

    // on add-on item bounds change
    void onItemBoundsChange(VfxFrame *source, const VfxRect &oldBounds) {checkUpdate();}
};

#endif /* __VCP_COMMAND_TITLE_H__ */

