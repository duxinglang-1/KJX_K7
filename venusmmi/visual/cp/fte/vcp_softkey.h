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
 *  vcp_softkey.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Softkey for Venus UI
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCP_SOFTKEY_H__
#define __VCP_SOFTKEY_H__


#ifndef __cplusplus
// If you don't allow C to include this file, remove following //
// #error "This header file can be used in C++ only."
#endif

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vcp_button.h"
#include "vfx_cpp_base.h"
#include "vfx_string.h"
#include "vfx_signal.h"
#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_frame.h"
#include "vfx_draw_context.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

#if defined(__MMI_MAINLCD_320X480__)
#define VCP_SOFTKEY_LRSK_WIDTH      80
#define VCP_SOFTKEY_CSK_WIDTH       0
#define VCP_SOFTKEY_HEIGHT          51
#else
#define VCP_SOFTKEY_LRSK_WIDTH   51
#define VCP_SOFTKEY_CSK_WIDTH    70
#define VCP_SOFTKEY_HEIGHT          38
#endif
#define VCP_SOFTKEY_BORDER_GAP      2
#define VCP_SOFTKEY_SHIFT_OFFSET    1
#define VCP_SOFTKEY_CLASS_NAME             "Softkey"


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

/*
 * Enum values which are used to describe different
 * types of softkey.
 */
enum VcpSoftkeyEnum
{
    // Is an enum value which represents the left softkey.
    VCP_SOFTKEY_LSK = 0,
    // Is an enum value which represents the right softkey.
    VCP_SOFTKEY_RSK,
    // Is an enum value which represents the center softkey.
    VCP_SOFTKEY_CSK,
    /* DOM-NOT_FOR_SDK-BEGIN */
    VCP_SOFTKEY_TOTAL
    /* DOM-NOT_FOR_SDK-END */
};

/*
 * Enum values which are used to describe different
 * event types of softkey.
 */
enum VcpSoftkeyEventEnum
{
    // Is an enum value which represents down event of softkey.
    VCP_SOFTKEY_DOWN = 0,
    // Is an enum value which represents up event of softkey.
    VCP_SOFTKEY_UP,
    // Is an enum value which represents long press event of softkey.
    VCP_SOFTKEY_LONGPRESS,
    /* DOM-NOT_FOR_SDK-BEGIN */
    VCP_SOFTKEY_EVENT_TOTAL
    /* DOM-NOT_FOR_SDK-END */
};

/*
 * Enum values which are used to describe content
 * align types of softkey.
 */
enum VcpSoftkeyContentAlignmentEnum
{
    // Is an enum value which represents softkey's content use left align.
    VCP_SOFTKEY_CONTENT_ALIGN_LEFT = 0,
    // Is an enum value which represents softkey's content use center align.
    VCP_SOFTKEY_CONTENT_ALIGN_CENTER,
    // Is an enum value which represents softkey's content use right align.
    VCP_SOFTKEY_CONTENT_ALIGN_RIGHT,
    /* DOM-NOT_FOR_SDK-BEGIN */
    VCP_SOFTKEY_CONTENT_ALIGN_TOTAL
    /* DOM-NOT_FOR_SDK-END */
};


// Callback of softkey which uses softkey event as the first parameter.
typedef VfxSignal1<VcpSoftkeyEventEnum> vcp_softkey_callback_type;

class VcpSoftkey;

/*****************************************************************************
 * Class VcpSoftkeyConfig
 *****************************************************************************/
 
 /*
 * VcpSoftkeyConfig is the helper class that store per-softkey config.
 *
 * EXAMPLE
 * <code>
 *  VcpSoftkeyConfig *m_softkeyConfig = new VcpSoftkeyConfig;
 * </code>
 */
class VcpSoftkeyConfig : public VfxBase
{
// Constructor / Destructor

public: 
    // <group DOM_Softkey_VcpSoftkeyConfig_Constructor/Destructor>
    friend class VcpSoftkey;
    
    // <group DOM_Softkey_VcpSoftkeyConfig_Constructor/Destructor>
    // Default constructor.
    VcpSoftkeyConfig();

    // <group DOM_Softkey_VcpSoftkeyConfig_Constructor/Destructor>
    // Destructor.
    ~VcpSoftkeyConfig();
    
// Implementation
private:

    // <group DOM_Softkey_VcpSoftkeyConfig_Implementation>
    // Softkey label.
    VfxWString m_label;
    // <group DOM_Softkey_VcpSoftkeyConfig_Implementation>
    // Softkey icon.
    VfxImageSrc m_icon;

    // <group DOM_Softkey_VcpSoftkeyConfig_Implementation>
    // Softkey is displayed (label or icon is not empty).
    VfxBool m_isDisplayed;

    // <group DOM_Softkey_VcpSoftkeyConfig_Implementation>
    // Softkey is disabled or not
    VfxBool m_isDisabled;
    
    // <group DOM_Softkey_VcpSoftkeyConfig_Implementation>
    // Event callback function.
    vcp_softkey_callback_type m_callback;
    
    // <group DOM_Softkey_VcpSoftkeyConfig_Implementation>
    // The next softkey setting.
    VcpSoftkeyConfig *m_next;
};

/*****************************************************************************
 * Class VcpSoftkeyConfig
 *****************************************************************************/
 
 /*
 * VcpSoftkey is the class that create a softkey bar.
 *
 * EXAMPLE
 * <code>
 *  VcpSoftkey *VFX_OBJ_CREATE(m_softkeybar, VcpSoftkey, this);
 * </code>
 */
class VcpSoftkey : public VfxControl
{
    VFX_DECLARE_CLASS(VcpSoftkey);

// Constructor / Destructor
public:
    // <group DOM_Softkey_VcpSoftkey_Constructor/Destructor>
    // Default constructor.
    VcpSoftkey();

// Method
public:
    // <group DOM_Softkey_VcpSoftkey_Method>
    // Is the color of text when text softkey in normal state.
    virtual const VfxColor &getNormalColor() const;
    // <group DOM_Softkey_VcpSoftkey_Method>
    // Is the color of text border when text softkey in normal state.
    virtual const VfxColor &getNormalBorderColor() const;
    // <group DOM_Softkey_VcpSoftkey_Method>
    // Is the color of text when text softkey in down state.
    virtual const VfxColor &getDownColor() const;
    // <group DOM_Softkey_VcpSoftkey_Method>
    // Is the color of text border when text softkey in down state.
    virtual const VfxColor &getDownBorderColor() const;
    // <group DOM_Softkey_VcpSoftkey_Method>
    // Is the border gap of softkey (LSK, RSK).
    virtual VfxS32 getBorderGap() const;
    // <group DOM_Softkey_VcpSoftkey_Method>
    // Is the shift offset of softkey (LSK, CSK, RSK).
    virtual VfxS32 getShiftOffset() const;

    // <group DOM_Softkey_VcpSoftkey_Property>
    virtual void setNormalColor(const VfxColor &value);
    // <group DOM_Softkey_VcpSoftkey_Method>
    virtual void setNormalBorderColor(const VfxColor &value);
    // <group DOM_Softkey_VcpSoftkey_Method>
    virtual void setDownColor(const VfxColor &value);
    // <group DOM_Softkey_VcpSoftkey_Method>
    virtual void setDownBorderColor(const VfxColor &value);
    // <group DOM_Softkey_VcpSoftkey_Method>
    virtual void setBorderGap(VfxS32 value);
    // <group DOM_Softkey_VcpSoftkey_Method>
    virtual void setShiftOffset(VfxS32 value);
    
// Method
public:
    // <group DOM_Softkey_VcpSoftkey_Method>
    // Set softkey info.
    void setSoftkey(
        VcpSoftkeyEnum sk,  // [IN] specify which softkey (LSK, CSK, RSK)
        const VfxWString &label, // [IN] label of softkey
        const VfxImageSrc &icon // [IN] icon of softkey
    );

    // <group DOM_Softkey_VcpSoftkey_Method>
    // Set the font of text softkey
    void setFont(
        const VfxFontDesc &font         // [IN] The font to set
    );

    // <group DOM_Softkey_VcpSoftkey_Method>
    // Set softkey background.
    void setSoftkeyBackground(
        VcpSoftkeyEnum sk,  // [IN] specify which softkey (LSK, CSK, RSK)
        const VfxImageSrc &background // [IN] background of softkey
    );
    
    // <group DOM_Softkey_VcpSoftkey_Method>
    // Get softkey's signal.
    // RETURNS: Softkey's signal
    vcp_softkey_callback_type & getCallback(
        VcpSoftkeyEnum sk // [IN] specify which softkey (LSK, CSK, RSK)
    ) const;

    // <group DOM_Softkey_VcpSoftkey_Method>
    // Push the current softkey config when we want to temporarily override softkey setting.
    void pushSoftkeyConfig(
        VcpSoftkeyEnum sk // [IN] specify which softkey (LSK, CSK, RSK)
    );
    
    // <group DOM_Softkey_VcpSoftkey_Method>
    // Restore the previous softkey config when we want to temporarily override softkey setting.
    void popSoftkeyConfig(
        VcpSoftkeyEnum sk // [IN] specify which softkey (LSK, CSK, RSK)
    );

    // <group DOM_Softkey_VcpSoftkey_Method>
    // Set background frame of softkey bar.
    void setSoftkeyBarBackground(
        VfxFrame *f // [IN] frame pointer of softkeybar'ss background 
    );
    
    // <group DOM_Softkey_VcpSoftkey_Method>
    // Get background frame of softkey bar.
    // RETURNS: Frame pointer of softkeybar's background
    VfxFrame *getSoftkeyBarBackground() const;

    // <group DOM_Softkey_VcpSoftkey_Method>
    // Set new width to softkey.
    void setSoftkeyWidth(
        VcpSoftkeyEnum sk, // [IN] specify which softkey (LSK, CSK, RSK)
        VfxS32 width // [IN] the new width of softkey
    );
    // <group DOM_Softkey_VcpSoftkey_Method>
    // Get the width of softkey.
    // RETURNS: Width of softkey.
    VfxS32 getSoftkeyWidth(
        VcpSoftkeyEnum sk // [IN] specify which softkey (LSK, CSK, RSK)
    );
    
    // <group DOM_Softkey_VcpSoftkey_Method>
    // Set placement of softkey background .
    void setSoftkeyBackgroundContentPlacement(
        VcpSoftkeyEnum sk,  // [IN] specify which softkey (LSK, CSK, RSK)
        VfxFrameContentPlacementTypeEnum value  // [IN] Content placement.
    );
/* DOM-NOT_FOR_SDK-BEGIN */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* DOM-NOT_FOR_SDK-END */

    // <group DOM_Softkey_VcpSoftkey_Method>
    // Hide the softkey.
    void hideSoftkey(
        VcpSoftkeyEnum sk // [IN] specify which softkey (LSK, CSK, RSK)
    );
  
    // <group DOM_Softkey_VcpSoftkey_Method>
    // Unhide the softkey.
    void unhideSoftkey(
        VcpSoftkeyEnum sk // [IN] specify which softkey (LSK, CSK, RSK)
    );

    // <group DOM_Softkey_VcpSoftkey_Method>
    // Disable the softkey.
    void disableSoftkey(
        VcpSoftkeyEnum sk,  // [IN] specify which softkey (LSK, CSK, RSK)
        VfxBool isDisabled  // [IN] disable softkey or not
    );

    // <group DOM_Softkey_VcpSoftkey_Method>
    // Disable all the softkeys.
    void disableSoftkey(
        VfxBool isDisabled // [IN] disable all softkeys or not
    );

// Override
protected:
    // <group DOM_Softkey_VcpSoftkey_Override>
    virtual void onInit();

    // <group DOM_Softkey_VcpSoftkey_Override>
    virtual void onDeinit();

    // <group DOM_Softkey_VcpSoftkey_Override>
    virtual void onDraw(VfxDrawContext &dc);

// Variable
protected:
    // <group DOM_Softkey_VcpSoftkey_Variable>
    // Buttons of softkeys.
    VcpButtonInternal *m_buttons[VCP_SOFTKEY_TOTAL];

    // <group DOM_Softkey_VcpSoftkey_Variable>
    // Softkey configurations.
    VcpSoftkeyConfig *m_softkeyConfig[VCP_SOFTKEY_TOTAL];


// Implementation
protected:
    // <group DOM_Softkey_VcpSoftkey_Implementation>
    // Assert if the softkey is invalid.
    void assertValidSoftkey(
        VcpSoftkeyEnum sk // [IN] specify which softkey (LSK, CSK, RSK)
    ) const;

    // <group DOM_Softkey_VcpSoftkey_Implementation>
    // Slot of LSK down's signal.
    // RETURNS: void
    void onEvent_LSKButtonDown();

    // <group DOM_Softkey_VcpSoftkey_Implementation>
    // Slot of LSK up's signal.
    // RETURNS: void
    void onEvent_LSKButtonUp();

    // <group DOM_Softkey_VcpSoftkey_Implementation>
    // Slot of LSK longpress's signal.
    // RETURNS: void
    void onEvent_LSKButtonLongpress();

    // <group DOM_Softkey_VcpSoftkey_Implementation>
    // Slot of RSK down's signal.
    // RETURNS: void
    void onEvent_RSKButtonDown();

    // <group DOM_Softkey_VcpSoftkey_Implementation>
    // Slot of RSK up's signal.
    // RETURNS: void
    void onEvent_RSKButtonUp();

    // <group DOM_Softkey_VcpSoftkey_Implementation>
    // Slot of RSK longpress's signal.
    // RETURNS: void
    void onEvent_RSKButtonLongpress();

    // <group DOM_Softkey_VcpSoftkey_Implementation>
    // Slot of CSK down's signal.
    // RETURNS: void
    void onEvent_CSKButtonDown();

    // <group DOM_Softkey_VcpSoftkey_Implementation>
    // Slot of CSK up's signal.
    // RETURNS: void
    void onEvent_CSKButtonUp();

    // <group DOM_Softkey_VcpSoftkey_Implementation>
    // Slot of CSK longpress's signal.
    // RETURNS: void
    void onEvent_CSKButtonLongpress();

private:
    // <group DOM_Softkey_VcpSoftkey_Implementation>
    VfxColor    m_normalColor;
    // <group DOM_Softkey_VcpSoftkey_Implementation>
    VfxColor    m_normalBorderColor;
    // <group DOM_Softkey_VcpSoftkey_Implementation>
    VfxColor    m_downColor;
    // <group DOM_Softkey_VcpSoftkey_Implementation>
    VfxColor    m_downBorderColor;
    // <group DOM_Softkey_VcpSoftkey_Implementation>
    VfxS32      m_borderGap;
    // <group DOM_Softkey_VcpSoftkey_Implementation>
    VfxS32      m_shiftOffset;
    
    // <group DOM_Softkey_VcpSoftkey_Implementation>
    // Background of softkey bar.
    VfxFrame *m_background;
    // <group DOM_Softkey_VcpSoftkey_Implementation>
    // Font for text softkey.
    VfxFontDesc m_font;
    // <group DOM_Softkey_VcpSoftkey_Implementation>
    // Relayout the softkey interior to center align in vertical direction.
    void realignSoftkey(VcpSoftkeyEnum sk);

    
    // <group DOM_Softkey_VcpSoftkey_Implementation>
    void onBoundsValueChanged(VfxFrame *source, const VfxRect &oldBounds);
    // <group DOM_Softkey_VcpSoftkey_Implementation>
    void textColorChanged();
};


#endif /* __VCP_SOFTKEY_H__ */

