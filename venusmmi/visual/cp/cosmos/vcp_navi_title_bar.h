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
 *  vcp_navi_title_bar.h
 *
 * Project:
 * --------
 *  FTO Components
 *
 * Description:
 * ------------
 *  Vinus Title Bar component
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_NAVI_TITLE_BAR_H__
#define __VCP_NAVI_TITLE_BAR_H__

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vfx_page_bar.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_config.h"
#include "vfx_cpp_base.h"
#include "vfx_primitive_frame.h"
#include "vfx_text_frame.h"
#include "MMIDataType.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"

#ifdef __COSMOS_3D_V10__
#define __VCP_TITLE_BAR_USE_3D_EFFECT__
#endif

#if defined(__MMI_VUI_COSMOS_CP__) 

class VcpFrameEffect;

/*****************************************************************************
 * Typedef
 *****************************************************************************/

// <group DOM_TitleBar_Macro&Enum_Enum>
// title bar style enum
enum VcpTitleBarStyleEnum
{
    VCP_TITLE_BAR_STYLE_BASE,       // the default style
    VCP_TITLE_BAR_STYLE_EMPTY,      // empty title bar style
    VCP_TITLE_BAR_STYLE_END_OF_ENUM // end of the enum
};


/*****************************************************************************
 * Class VcpTitleBar
 *****************************************************************************/
class VcpTitleBar : public VfxPageBar
{
    VFX_DECLARE_CLASS(VcpTitleBar);

    // Constructor / Destructor
public:	
    // Default constructor.
    VcpTitleBar();


    // Property
public:
    // <group DOM_TitleBar_VcpTitleBar_Property>
    // get the title string
    // RETURN: VfxWString
    VfxWString getTitle() const;

    // <group DOM_TitleBar_VcpTitleBar_Property>
    // set the title string
    // Default value: empty string
    void setTitle(
        const VfxWString& title             // [IN] the title string
        );

    void setTitle(
        const VfxWChar* title             // [IN] the title string
        );

    void setTitle(
        VfxResId titleId             // [IN] the title string
        );

    // <group DOM_TitleBar_VcpTitleBar_Property>
    // get title style
    VcpTitleBarStyleEnum getTitleStyle() const;

    // <group DOM_TitleBar_VcpTitleBar_Property>
    // set title style
    // Default value: VCP_TITLE_BAR_STYLE_BASE
    void setTitleStyle(
        VcpTitleBarStyleEnum style          // [IN] the title bar style
        );

    // <group DOM_TitleBar_VcpTitleBar_Property>
    // set background for the title bar
    void setTitleBackground(
        const VfxImageSrc & background      // [IN] the title bar background
        );

#ifdef __AFX_RT_TEST__
    VfxBool testGetTranslucent();
    void testSetTranslucent(VfxBool translucent);
    VfxScrRotateTypeEnum testGetRotation();
    void testSetRotation(VfxScrRotateTypeEnum rotation);
    void testForceUpdate();
    VfxImageFrame * testGetBackground();
    VfxTextFrame * testGetTitleControl();
#endif // __AFX_RT_TEST__


    // Method
public:

    // Override
protected:
    // <group DOM_TitleBar_VcpTitleBar_Override>
    virtual void onInit();

    // <group DOM_TitleBar_VcpTitleBar_Override>
    virtual void onUpdate();

    // <group DOM_TitleBar_VcpTitleBar_Override>
    virtual void onSetTranslucent(VfxBool translucent);

    // <group DOM_TitleBar_VcpTitleBar_Override>
    virtual void onSetRotate(VfxScrRotateTypeEnum rotation);

#ifdef __VCP_TITLE_BAR_USE_3D_EFFECT__
    virtual void onDeinit();

    virtual void onTransitionStop(VfxBool in, VfxS32 direction);
    
#endif // __VCP_TITLE_BAR_USE_3D_EFFECT__
    
    // Implementation
private:
    VfxImageFrame * m_background;
    VfxTextFrame * m_titleControl;

    VfxWString m_title;
    VfxBool m_translucent;
    VfxScrRotateTypeEnum m_rotation;
#ifdef __VCP_TITLE_BAR_USE_3D_EFFECT__
    VfxTimer * m_effectDelayTimer;
#endif
    VcpTitleBarStyleEnum m_titleStyle;
    VfxImageSrc m_backgroundImage;

    VcpFrameEffect * m_frameEffect;

    void updateBackground();
    void updateTitle();
    void updateTitleStyleBase();
    void updateTextFrame(VfxTextFrame * textFrame, S32 left, S32 top, S32 right, S32 bottom);

    void onBoundsChanged(VfxFrame *frame, const VfxRect &old);

#ifdef __VCP_TITLE_BAR_USE_3D_EFFECT__
    void onDelayedEffect(VfxTimer *source);

    void onActiveScreenEnter(VfxWeakPtr<VfxScreen> scr);

    void onActiveScreenExit(VfxWeakPtr<VfxScreen> scr);
    
#endif // __VCP_TITLE_BAR_USE_3D_EFFECT__
};

#endif /* #if defined (__MMI_VUI_COSMOS_CP__)  */
#endif /* __VCP_NAVI_TITLE_BAR_H__ */

