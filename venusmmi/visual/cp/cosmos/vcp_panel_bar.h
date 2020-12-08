/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*******************************************************************************
 * Filename:
 * ---------
 *  vcp_panel_bar.h
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Panel bar component header
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_PANEL_BAR_H__
#define __VCP_PANEL_BAR_H__
#include "mmi_core\vfx_page_bar.h"

#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_basic_type.h"
#include "vfx_frame.h"
/***************************************************************************** 
 * Include
 *****************************************************************************/


/***************************************************************************** 
 * Define
 *****************************************************************************/


#define VCP_IMG_PANEL_BAR_BACKGROUND_ID    (VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL)

#ifdef __MMI_MAINLCD_480X800__
    #define VCP_PANEL_BAR_WIDTH             (480)
    #define VCP_PANEL_BAR_SHADOW_HEIGHT     (4)
    
    #define VCP_PANEL_BAR_X (0)
    #define VCP_PANEL_BAR_Y (800 - 1)
#elif defined(__MMI_MAINLCD_320X480__)
    #define VCP_PANEL_BAR_WIDTH             (320)
    #define VCP_PANEL_BAR_SHADOW_HEIGHT     (2)
    
    #define VCP_PANEL_BAR_X (0)
    #define VCP_PANEL_BAR_Y (480 - 1)
#elif defined(__MMI_MAINLCD_240X400__)
    #define VCP_PANEL_BAR_WIDTH             (240)
    #define VCP_PANEL_BAR_SHADOW_HEIGHT     (2)
    
    #define VCP_PANEL_BAR_X (0)
    #define VCP_PANEL_BAR_Y (400 - 1)
#elif defined(__MMI_MAINLCD_240X320__)
    #define VCP_PANEL_BAR_WIDTH             (240)
    #define VCP_PANEL_BAR_SHADOW_HEIGHT     (2)
    
    #define VCP_PANEL_BAR_X (0)
    #define VCP_PANEL_BAR_Y (320 - 1)
#else
    #define VCP_PANEL_BAR_WIDTH             (240)
    #define VCP_PANEL_BAR_SHADOW_HEIGHT     (2)
    
    #define VCP_PANEL_BAR_X (0)
    #define VCP_PANEL_BAR_Y (320 - 1)
#endif


/********************************************************
 * Structure used in XML
 * *******************************************************
 *   <Struct name="VcpPanelBarHeightsStruct">
 *       <Member    name="portrait"       type="VfxU32"/>
 *       <Member    name="landscape"      type="VfxU32"/>
 *   </Struct>
 *********************************************************/
struct VcpPanelBarHeightsStruct : public VfxBase
{
    VfxU32 portrait;            
    VfxU32 landscape;            
};


/*****************************************************************************
 * Class VcpPanelBar
 * VcpPanelBar - a Page Bar, displayed on bottom. Panel Bar and Tool Bar are mutually exclusive.
 *
 * EXAMPLE
 * <code>
 *  VcpPanelBar *panel;
 *  VFX_OBJ_CREATE(panel, VcpPanelBar, this);
 *  panel->setHeight(75, 50); // Portrait and landscape height
 * </code>
 *****************************************************************************/
class VcpPanelBar : public VfxPageBar
{
    VFX_DECLARE_CLASS(VcpPanelBar);

// Constructor / Destructor
public:
    // <group DOM_PanelBar_VcpPanelBar_Constructor/Destructor>
    // Default constructor.
    VcpPanelBar();

public:
    // <group DOM_PanelBar_VcpPanelBar_Method>
    // Sets the supplied height to both, landscape and portrait orientation.
    void setHeight(
        VfxU32 common_height                // [IN]  Same height for PORTRAIT and LANDSCAPE mode 
    );

    // <group DOM_PanelBar_VcpPanelBar_Method>
    // Sets different height to landscape and portrait orientation.
    void setHeight(
        VfxU32 portrait_height,                // [IN]  height for PORTRAIT mode 
        VfxU32 landscape_height                // [IN]  height for LANDSCAPE mode 
    );

    // <group DOM_PanelBar_VcpPanelBar_Method>
    // Supported for XML implementation.
    void setBothHeights(
        const VcpPanelBarHeightsStruct &heights      // [IN]  Both heights in struct form 
    );

    // <group DOM_PanelBar_VcpPanelBar_Method>
    // Returns different heights of both, landscape and portrait orientation.
    void getHeight(
        VfxU32 &portrait_height,            // [OUT]  height for PORTRAIT mode 
        VfxU32 &landscape_height            // [OUT]  height for LANDSCAPE mode 
    ) const;

private:
    // <group DOM_PanelBar_VcpPanelBar_Implementation>
    // Redraw the panel bar.
    void resetLayout(void);


public:

protected:
    // <group DOM_PanelBar_VcpPanelBar_Override>
    virtual void onInit();

    // <group DOM_PanelBar_VcpPanelBar_Override>
    virtual void onSetTranslucent(VfxBool translucent);

    // <group DOM_PanelBar_VcpPanelBar_Override>
    virtual void onSetRotate(VfxScrRotateTypeEnum rotate){}

private:
    // <group DOM_PanelBar_VcpPanelBar_Implementation>
    // Panelbar's height in PORTRAIT mode
    VfxU32 m_portraitHeight;            

    // <group DOM_PanelBar_VcpPanelBar_Implementation>
    // Panelbar's height in LANDSCAPE mode
    VfxU32 m_landscapeHeight;            

};


#endif /* __VCP_PANEL_BAR_H__ */

