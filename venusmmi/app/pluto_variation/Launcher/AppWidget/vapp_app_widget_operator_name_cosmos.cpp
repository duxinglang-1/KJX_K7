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
 *  vapp_app_widget_operator_name_cosmos.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the cosmos style operator name widget.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#include "vapp_app_widget_def.h"

#if defined(__MMI_VUI_LAUNCHER__) && defined(VAPP_APP_WIDGET_OPERATOR_NAME)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMIDataType.h"
#include "vapp_app_widget.h"
#include "vapp_app_widget_operator_name_cosmos.h"
#include "mmi_rp_vapp_app_widget_operator_name_cosmos_def.h"
#include "vapp_sim_setting_gprot.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "NwNameSrvGprot.h"
#include "mmi_frm_utility_gprot.h"
#include "NetsetAppGprot.h"

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define OPERATOR_WIDGET_MIN(a, b) (((a) < (b)) ? (a) : (b))


#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
/***************************************************************************** 
 * Class VappAppWidgetSIMNameElementCosmos 
 *****************************************************************************/
VappAppWidgetSIMNameElementCosmos::VappAppWidgetSIMNameElementCosmos(VfxS32 simId):
    m_simId(simId),
    m_textSIMName(NULL),
    m_rightParenthesis(NULL),
    m_leftParenthesis(NULL)
{
    
}


void VappAppWidgetSIMNameElementCosmos::onInit()
{
    VfxFrame::onInit();
    setBgColor(VFX_COLOR_TRANSPARENT);

    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(SIM_NAME_FONT_SIZE);

    VFX_OBJ_CREATE(m_textSIMName, VfxTextFrame, this);
    m_textSIMName->setFont(fontDesc);
    m_textSIMName->forceUpdate();

    VFX_OBJ_CREATE(m_leftParenthesis, VfxTextFrame, this);
    m_leftParenthesis->setString(VFX_WSTR(" ("));
    m_leftParenthesis->setFont(fontDesc);
    
    VFX_OBJ_CREATE(m_rightParenthesis, VfxTextFrame, this);
    m_rightParenthesis->setString(VFX_WSTR(")"));
    m_rightParenthesis->setFont(fontDesc);

    m_leftParenthesis->setHidden(VFX_TRUE);
    m_textSIMName->setHidden(VFX_TRUE);
    m_rightParenthesis->setHidden(VFX_TRUE);
}


void VappAppWidgetSIMNameElementCosmos::layout()
{
    VfxWString simName = VFX_WSTR_MEM((VfxWChar*)mmi_netset_get_sim_name(mmi_frm_index_to_sim(m_simId)));
    if(simName.isEmpty())
    {
        setHidden(VFX_TRUE);
        return;
    }
    m_leftParenthesis->setHidden(VFX_FALSE);
    m_textSIMName->setHidden(VFX_FALSE);
    m_rightParenthesis->setHidden(VFX_FALSE);

    m_textSIMName->setAutoResized(VFX_TRUE);
    m_textSIMName->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_NONE);
    m_textSIMName->setString(simName);
    m_textSIMName->forceUpdate();

    VfxS32 maxWidthSimName = getSize().width - m_leftParenthesis->getSize().width - m_rightParenthesis->getSize().width;
    VfxS32 widthSimName = OPERATOR_WIDGET_MIN(maxWidthSimName, m_textSIMName->getSize().width);
    m_textSIMName->setAutoResized(VFX_FALSE);
    m_textSIMName->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_textSIMName->setSize(widthSimName, m_textSIMName->getSize().height);

    m_leftParenthesis->setPos(0, 0);
    m_textSIMName->setPos(m_leftParenthesis->getSize().width, 0);
    m_rightParenthesis->setPos(m_textSIMName->getPos().x + m_textSIMName->getSize().width, 0);

    setSize(getSize().width, m_textSIMName->getSize().height);
}
#endif


/***************************************************************************** 
 * Class VappAppWidgetOperatorElementCosmos 
 *****************************************************************************/
VappAppWidgetOperatorElementCosmos::VappAppWidgetOperatorElementCosmos(VfxS32 simId):
    m_simId(simId),
    m_textOPN(NULL),
    m_textSPN(NULL),
#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    m_textSIMName(NULL),
#endif
    m_seperateLineImg(NULL)
{
    
}

void VappAppWidgetOperatorElementCosmos::onInit()
{
    VfxFrame::onInit(); 
    setSize(getParentFrame()->getSize().width, ELEMENT_HEIGHT+2);
    
    MMI_IMG_ID simImgRes[] = {IMG_ID_VAPP_WIDGET_OPERATOR_NAME_COSMOS_ICON_SIM1, 
                              IMG_ID_VAPP_WIDGET_OPERATOR_NAME_COSMOS_ICON_SIM2, 
                              IMG_ID_VAPP_WIDGET_OPERATOR_NAME_COSMOS_ICON_SIM3, 
                              IMG_ID_VAPP_WIDGET_OPERATOR_NAME_COSMOS_ICON_SIM4};
    VfxFontDesc fontDesc;
    
    VFX_OBJ_CREATE(m_imgSim, VfxImageFrame, this);
    m_imgSim->setPos(SIM_ICON_OFFSET_X, SIM_ICON_OFFSET_Y);
    m_imgSim->setResId(simImgRes[m_simId]);

    VFX_OBJ_CREATE(m_textOPN, VfxTextFrame, this);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(OPERATOR_NAME_FONT_SIZE);
    m_textOPN->setFont(fontDesc);
    m_textOPN->setPos(m_imgSim->getPos().x+m_imgSim->getSize().width+OPN_OFFSET_X, OPN_OFFSET_Y);

    VFX_OBJ_CREATE(m_textSPN, VfxTextFrame, this);
    m_textSPN->setAnchor(0, 1.0f);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(SERVICE_NAME_FONT_SIZE);
    m_textSPN->setFont(fontDesc);
    m_textSPN->setPos(m_imgSim->getPos().x+m_imgSim->getSize().width+SPN_OFFSET_X, getSize().height-OPN_OFFSET_Y);

#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    VFX_OBJ_CREATE_EX(m_textSIMName, VappAppWidgetSIMNameElementCosmos, this, (m_simId));
#endif

    if(m_simId != MMI_SIM_TOTAL-1)
    {
        VFX_OBJ_CREATE(m_seperateLineImg, VfxImageFrame, this);
        m_seperateLineImg->setResId(IMG_ID_VAPP_WIDGET_OPERATOR_NAME_COSMOS_SEPERATE_LINE);
        m_seperateLineImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_seperateLineImg->setSize(getSize().width-2*SEPERATE_LINE_OFFSET, m_seperateLineImg->getSize().height);
        m_seperateLineImg->setPos(SEPERATE_LINE_OFFSET, ELEMENT_HEIGHT);
    }

    updateOperatorName();
}


void VappAppWidgetOperatorElementCosmos::updateOperatorName()
{
    srv_nw_name_service_indication_struct tmp_indication;

    srv_nw_name_get_service_indication_string(mmi_frm_index_to_sim(m_simId), &tmp_indication);  
    m_textOPN->setString(VFX_WSTR_MEM(tmp_indication.line1));
    m_textSPN->setString(VFX_WSTR_MEM(tmp_indication.line2));

    if(mmi_wcslen(tmp_indication.line2))
    {
        m_textOPN->setAnchor(0, 0);
        m_textOPN->setPos(m_imgSim->getPos().x+m_imgSim->getSize().width+OPN_OFFSET_X, OPN_OFFSET_Y);
        m_textSPN->setHidden(VFX_FALSE);
    }
    else
    {
        m_textOPN->setAnchor(0, 0.5);
        m_textOPN->setPos(m_textOPN->getPos().x, m_imgSim->getPos().y + m_imgSim->getSize().height/2);
        m_textSPN->setHidden(VFX_TRUE);
    }

#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    VfxS32 width = getSize().width - m_textOPN->getPos().x - m_textOPN->getSize().width - WHITE_GAP_OFFSET_X;
    VfxS32 height = m_textOPN->getSize().height;
    m_textSIMName->setSize(VfxSize(width,height));
    m_textSIMName->layout();

    m_textSIMName->setAnchor(m_textOPN->getAnchor());
    m_textSIMName->setPos(m_textOPN->getPos().x + m_textOPN->getSize().width + 1, m_textOPN->getPos().y);
#endif
}


/*****************************************************************************
 * Cosmos Style Operator Name Widget
 *****************************************************************************/
VAPP_APP_WIDGET_IMPLEMENT_CLASS(VappAppWidgetOperatorNameCosmos, VappAppWidget);


VappAppWidgetOperatorNameCosmos::VappAppWidgetOperatorNameCosmos():
    m_bgImg(NULL),
    m_bgTitleImg(NULL),
    m_title(NULL)
{
    for(VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
    {
        m_operElement[i] = NULL;
    }
}


VappAppWidgetId VappAppWidgetOperatorNameCosmos::getId() const
{
    return VappAppWidgetId(
            VAPP_APP_WIDGET_SRC_NATIVE,
            VAPP_APP_WIDGET_TYPE_OPERATOR_NAME_COSMOS);
}


VfxS32 VappAppWidgetOperatorNameCosmos::getName(VfxWChar *string, VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(STR_ID_VAPP_WIDGET_OPERATOR_NAME_COSMOS);

    VFX_ASSERT(string && size > 0);

    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);
}


VfxSize VappAppWidgetOperatorNameCosmos::getMaxSize() const
{
    VfxImageSrc bg(IMG_ID_VAPP_WIDGET_OPERATOR_NAME_COSMOS_BG);
    VfxS32 height = bg.getSize().height + 2 +  (MMI_SIM_TOTAL-1)* (CELL_HEIGHT+2);

    return VfxSize(WIDTH, height);
}


VfxFrame *VappAppWidgetOperatorNameCosmos::createIcon(VfxObject *parentObj)
{
    VfxImageFrame *icon;

    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_ID_VAPP_WIDGET_OPERATOR_NAME_COSMOS_ICON);

    return icon;
}


void VappAppWidgetOperatorNameCosmos::onCreateView()
{
    VFX_OBJ_CREATE(m_bgImg, VfxImageFrame, this);
    m_bgImg->setResId(IMG_ID_VAPP_WIDGET_OPERATOR_NAME_COSMOS_BG);
    m_bgImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    VfxS32 height = m_bgImg->getSize().height + 2 +  (MMI_SIM_TOTAL-1)* (CELL_HEIGHT+2);
    m_bgImg->setSize(WIDTH, height);
    setSize(WIDTH , height);

    VFX_OBJ_CREATE(m_bgTitleImg, VfxImageFrame, this);
    m_bgTitleImg->setResId(IMG_ID_VAPP_WIDGET_OPERATOR_NAME_COSMOS_BG_TITLE);
    m_bgTitleImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_bgTitleImg->setAnchor(0.5,0);
    m_bgTitleImg->setPos(getSize().width/2, TITLE_UP_GAP);
    m_bgTitleImg->setSize(TITLE_WIDTH, m_bgTitleImg->getSize().height);

    VFX_OBJ_CREATE(m_title, VfxTextFrame, this);
    m_title->setAnchor(0.5,0.5);
    m_title->setPos(getSize().width/2, m_bgTitleImg->getPos().y + m_bgTitleImg->getSize().height/2);
    VfxFontDesc fontDesc = VfxFontDesc(
        VFX_FONT_DESC_VF_SIZE(TITLE_FONT_SIZE), VFX_FONT_DESC_ATTR_BOLD, VFX_FE1_1); //VFX_FONT_DESC_EFFECT_NONE 
    m_title->setFont(fontDesc);
    m_title->setString(VFX_WSTR_RES(STR_ID_VAPP_WIDGET_OPERATOR_NAME_COSMOS));

    createOperatorNameElement();
    mmi_frm_cb_reg_event(EVT_ID_SRV_NW_NAME_CHANGED, &VappAppWidgetOperatorNameCosmos::eventHandler, this);
}



void VappAppWidgetOperatorNameCosmos::onReleaseView()
{
    VFX_OBJ_CLOSE(m_bgImg);
    VFX_OBJ_CLOSE(m_bgTitleImg);
    VFX_OBJ_CLOSE(m_title);
    releaseOperatorNameElement();
    mmi_frm_cb_dereg_event(EVT_ID_SRV_NW_NAME_CHANGED, &VappAppWidgetOperatorNameCosmos::eventHandler, this);

}


VfxPoint VappAppWidgetOperatorNameCosmos::onGetEditButtonOffset()
{
    return VfxPoint(WIDTH - EDIT_BUTTON_OFFSET_X, EDIT_BUTTON_OFFSET_Y);
}


mmi_ret VappAppWidgetOperatorNameCosmos::eventHandler(mmi_event_struct *event)
{
    MMI_ASSERT(event);
    VappAppWidgetOperatorNameCosmos* operatorNameWidget = (VappAppWidgetOperatorNameCosmos *)event->user_data;

    switch (event->evt_id)
    {
        case EVT_ID_SRV_NW_NAME_CHANGED:
            operatorNameWidget->update();
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


void VappAppWidgetOperatorNameCosmos::createOperatorNameElement()
{
    VfxS32 posY = TITLE_BAR_HEIGHT + SEPERATE_LINE_HEIGHT;
    
    for(VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
    {
        VFX_OBJ_CREATE_EX(m_operElement[i], VappAppWidgetOperatorElementCosmos, this, (i));
        m_operElement[i]->setPos(0, posY);
        posY += m_operElement[i]->getSize().height;
    }
}


void VappAppWidgetOperatorNameCosmos::releaseOperatorNameElement()
{
    VfxS32 i;
    for(i = 0; i < MMI_SIM_TOTAL; i++)
    {
        VFX_OBJ_CLOSE(m_operElement[i]);
    }
}


void VappAppWidgetOperatorNameCosmos::update()
{
    for(VfxS32 i = 0; i < MMI_SIM_TOTAL; i++)
    {
        m_operElement[i]->updateOperatorName();
    }
}
#endif /* defined(__MMI_VUI_LAUNCHER__) && defined(VAPP_APP_WIDGET_OPERATOR_NAME) */

