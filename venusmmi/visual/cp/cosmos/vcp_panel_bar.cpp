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
 *  vcp_panel_bar.cpp
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Panel bar component
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C"
{
    #include "GlobalResDef.h"
}

#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vcp_res.h"

#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vcp_panel_bar.h"
#include "vfx_class_info.h"
#include "vfx_page_bar.h"
#include "vfx_datatype.h"
#include "vfx_frame.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "vfx_image_src.h"
#include "vfx_basic_type.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Class VcpPanelBar 
 *****************************************************************************/  
VFX_IMPLEMENT_CLASS("VcpPanelBar", VcpPanelBar, VfxPageBar);

VcpPanelBar::VcpPanelBar():
    m_portraitHeight(0),
    m_landscapeHeight(0)
{
}


void VcpPanelBar::onInit()
{
    VfxPageBar::onInit();

    setAutoAnimate(VFX_TRUE);

    setPos(0, 0);
    setImgContent(VfxImageSrc(VCP_IMG_PANEL_BAR_BACKGROUND_ID));
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    setIsCached(VFX_TRUE);

#if defined(__MMI_VUI_COSMOS_CP__)
    VfxFrame * shadowFrame;
    VFX_OBJ_CREATE(shadowFrame, VfxFrame, this);
    shadowFrame->setImgContent(VfxImageSrc(VCP_IMG_TOOL_BAR_SHADOW));
    shadowFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    shadowFrame->setSize(getSize().width, VCP_PANEL_BAR_SHADOW_HEIGHT);
    setShadowFrame(shadowFrame);
#endif

    resetLayout();
}


void VcpPanelBar::setHeight(VfxU32 common_height)
{
    m_portraitHeight = m_landscapeHeight = common_height;
    resetLayout();
}


void VcpPanelBar::setHeight(VfxU32 portrait_height, VfxU32 landscape_height)
{
    m_portraitHeight = portrait_height;
    m_landscapeHeight = landscape_height;
    resetLayout();
}


void VcpPanelBar::setBothHeights(const VcpPanelBarHeightsStruct &heights)
{
    m_portraitHeight = heights.portrait;
    m_landscapeHeight = heights.landscape;
    resetLayout();
}


void VcpPanelBar::getHeight(VfxU32 &portrait_height, VfxU32 &landscape_height) const
{
    portrait_height = m_portraitHeight;
    landscape_height = m_landscapeHeight;
}
        

void VcpPanelBar::resetLayout(void)
{
//    if(landscape)
//    {
//        VfxFrame::setPos(VfxPoint(VCP_PANEL_BAR_X, VCP_PANEL_BAR_Y - m_landscapeHeight));
//        VfxFrame::setSize(VfxSize(VCP_PANEL_BAR_WIDTH, m_landscapeHeight));
//    }
//    else
    {
        setPos(VfxPoint(VCP_PANEL_BAR_X, VCP_PANEL_BAR_Y - m_portraitHeight));
        setBounds(VfxRect(0, 0, VCP_PANEL_BAR_WIDTH, m_portraitHeight));
    }
}


void VcpPanelBar::onSetTranslucent(VfxBool translucent)
{
    setOpacity(translucent ? 0.5f : 1.0f);
}


