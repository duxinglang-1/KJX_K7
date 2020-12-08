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
 *  vapp_ncenter_system_cell.cpp
 *
 * Project:
 * --------
 *  COSMOS Notification Center
 *
 * Description:
 * ------------
 *  
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
#include "MMI_features.h"
#include "vfx_datatype.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"

#include "vapp_ncenter_system_cell.h"
// for single sim icon
#include "mmi_rp_app_ncenter_def.h"
#if defined(__MMI_VUI_COSMOS_CP__)
#include "mmi_rp_app_cosmos_global_def.h"
#endif /* defined(__MMI_VUI_COSMOS_CP__) */    
#include "vapp_ncenter_base_cell.h"
#include "vapp_sim_setting_gprot.h"




/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

// extern pluto setting api
#include "MMIDataType.h"
#include "NwNameSrvGprot.h"
#include "mmi_frm_utility_gprot.h"
#include "SimCtrlSrvGprot.h"
#include "GlobalResDef.h"

#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) 
#include "NetsetAppGprot.h"
#endif

#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define NC_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define NC_MIN(a, b) (((a) < (b)) ? (a) : (b))


#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
/***************************************************************************** 
 * Class VappNCenterSIMNameElement 
 *****************************************************************************/
VappNCenterSIMNameElement::VappNCenterSIMNameElement(VfxS32 simId):
    m_simId(simId)
{
    
}


void VappNCenterSIMNameElement::onInit()
{
    VfxFrame::onInit();
    setBgColor(VFX_COLOR_TRANSPARENT);

    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_SIZE);

    VFX_OBJ_CREATE(m_textSIMName, VfxTextFrame, this);

    m_textSIMName->setColor(VAPP_NCENTER_CLR_TEXT_SUB);
    m_textSIMName->setFont(fontDesc);
    m_textSIMName->forceUpdate();

    VFX_OBJ_CREATE(m_leftParenthesis, VfxTextFrame, this);
    m_leftParenthesis->setString(VFX_WSTR(" ("));   

    m_leftParenthesis->setColor(VAPP_NCENTER_CLR_TEXT_SUB);
    m_leftParenthesis->setFont(fontDesc);
    
    VFX_OBJ_CREATE(m_rightParenthesis, VfxTextFrame, this);
    m_rightParenthesis->setString(VFX_WSTR(")"));    
    m_rightParenthesis->setColor(VAPP_NCENTER_CLR_TEXT_SUB); 
    m_rightParenthesis->setFont(fontDesc);

    m_leftParenthesis->setHidden(VFX_TRUE);
    m_textSIMName->setHidden(VFX_TRUE);
    m_rightParenthesis->setHidden(VFX_TRUE);
}


void VappNCenterSIMNameElement::layout()
{
#if defined(__COSMOS_MMI_PACKAGE__)
    VfxWString simName = vapp_sim_settings_get_sim_name(mmi_frm_index_to_sim(m_simId)); 
#else
    VfxWString simName = VFX_WSTR_MEM((VfxWChar*)mmi_netset_get_sim_name(mmi_frm_index_to_sim(m_simId)));
#endif

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
    VfxS32 widthSimName = NC_MIN(maxWidthSimName, m_textSIMName->getSize().width);
    m_textSIMName->setAutoResized(VFX_FALSE);
    m_textSIMName->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_textSIMName->setSize(widthSimName, m_textSIMName->getSize().height);

    m_leftParenthesis->setPos(0, 0);
    m_textSIMName->setPos(m_leftParenthesis->getSize().width, 0);
    m_rightParenthesis->setPos(m_textSIMName->getPos().x + m_textSIMName->getSize().width, 0);

    setSize(getSize().width, m_textSIMName->getSize().height);
}
#endif /* defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */


/***************************************************************************** 
 * Class VappNCenterOperatorElement 
 *****************************************************************************/
VappNCenterOperatorElement::VappNCenterOperatorElement(VfxS32 simId):
    m_simId(simId),
    m_separatorL(NULL)
{
    
}

void VappNCenterOperatorElement::onInit()
{
    VfxFrame::onInit();

    setBgColor(VAPP_NCENTER_CLR_BACKGROUND);
    setSize(getParentFrame()->getSize().width, VAPP_NCENTER_EVENT_CELL_HEIGHT);

#if defined(__MMI_VUI_COSMOS_CP__)
    MMI_IMG_ID simImgRes[] = {IMG_COSMOS_SIM1, IMG_COSMOS_SIM2, IMG_COSMOS_SIM3, IMG_COSMOS_SIM4};
#else
    MMI_IMG_ID simImgRes[] = {IMG_GLOBAL_SIM1, IMG_GLOBAL_SIM2, IMG_GLOBAL_SIM3, IMG_GLOBAL_SIM4};
#endif 

    VfxFontDesc fontDesc;
    VFX_OBJ_CREATE(m_imgSim, VfxImageFrame, this);
#if (MMI_MAX_SIM_NUM == 1)
    m_imgSim->setResId(IMG_ID_VAPP_NCENTER_SINGLE_SIM_ICON);
#else
    m_imgSim->setResId(simImgRes[m_simId]);
#endif
    m_imgSim->setAnchor(0, 0.5);
    m_imgSim->setPos(VAPP_NCENTER_EVENT_CELL_ICON_X, VAPP_NCENTER_EVENT_CELL_HEIGHT/2);
    m_imgSim->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_NONE);
    m_imgSim->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    VFX_OBJ_CREATE(m_textOPN, VfxTextFrame, this);
    m_textOPN->setColor(VAPP_NCENTER_CLR_TEXT_MAIN);    
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_SIZE);
    m_textOPN->setFont(fontDesc);

    VFX_OBJ_CREATE(m_textSPN, VfxTextFrame, this);
    m_textSPN->setAnchor(0, 1.0f);    
    m_textSPN->setColor(VAPP_NCENTER_CLR_TEXT_SUB);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_NCENTER_EVENT_CELL_SUB_TEXT_SIZE);
    m_textSPN->setFont(fontDesc);

#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    VFX_OBJ_CREATE_EX(m_textSIMName, VappNCenterSIMNameElement, this, (m_simId));
#endif

    insertSeparator(this, VAPP_NCENTER_EVENT_CELL_HEIGHT);
    updateOperatorName(getParentFrame()->getSize().width);
}


void VappNCenterOperatorElement::insertSeparator(VfxFrame *target, VfxS32 posY)
{
    if(!m_separatorL)
    {
        VFX_OBJ_CREATE(m_separatorL, VfxImageFrame, target);

#if defined(__MMI_VUI_COSMOS_CP__)
        m_separatorL->setResId(IMG_COSMOS_SEPARATOR_LINE);
        m_separatorL->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_separatorL->setSize(target->getSize().width, m_separatorL->getSize().height);
#else
        m_separatorL->setBgColor(VAPP_NCENTER_CLR_SEPERATOR);
        m_separatorL->setSize(target->getSize().width, 1);
#endif
        
    }
    m_separatorL->setPos(0, posY - 2 );    
}


void VappNCenterOperatorElement::updateOperatorName(VfxS32 maxWidth)
{
    //srv_nw_name_changed_evt_struct *evt = (srv_nw_name_changed_evt_struct *)event;
    srv_nw_name_service_indication_struct tmp_indication;

    srv_nw_name_get_service_indication_string(mmi_frm_index_to_sim(m_simId), &tmp_indication);  
    m_textOPN->setString(VFX_WSTR_MEM(tmp_indication.line1));
    m_textSPN->setString(VFX_WSTR_MEM(tmp_indication.line2));

    if(mmi_wcslen(tmp_indication.line2))
    {
        m_textOPN->setAnchor(0, 0);
        m_textOPN->setPos(VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_X , VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_Y);
        m_textSPN->setPos(VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_X , VAPP_NCENTER_EVENT_CELL_HEIGHT - VAPP_NCENTER_EVENT_CELL_SUB_TEXT_Y);
        m_textSPN->setHidden(VFX_FALSE);
    }
    else
    {
        m_textOPN->setAnchor(0, 0.5);
        m_textOPN->setPos(VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_X , VAPP_NCENTER_EVENT_CELL_HEIGHT/2);
        m_textSPN->setHidden(VFX_TRUE);
    }

    VfxS32 tmpLen = NC_MAX( m_textOPN->getSize().width, m_textSPN->getSize().width); 
    VfxS32 width;
    VappNCenterOperatorCell *cell = (VappNCenterOperatorCell *)getParentFrame();
    if(NULL == cell->getFoldButton())
    {
        width = maxWidth - VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_X - tmpLen - VAPP_NCENTER_FOLD_BUTTON_GAP_X;   
    }
    else
    {
        width = maxWidth - VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_X - tmpLen - VAPP_NCENTER_FOLD_BUTTON_WIDTH - 2 * VAPP_NCENTER_FOLD_BUTTON_GAP_X;
    }

#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    VfxS32 height = getSize().height;
    m_textSIMName->setSize(VfxSize(width,height));
    m_textSIMName->layout();

    tmpLen = NC_MAX(m_textOPN->getPos().x + m_textOPN->getSize().width, m_textSPN->getPos().x + m_textSPN->getSize().width);
    m_textSIMName->setAnchor(0,0.5);
    m_textSIMName->setPos(tmpLen,getSize().height/2);
#endif

    setSize(getParentFrame()->getSize().width , VAPP_NCENTER_EVENT_CELL_HEIGHT);

}


/***************************************************************************** 
 * Class VappNCenterOperatorCell 
 *****************************************************************************/
VappNCenterOperatorCell::VappNCenterOperatorCell()
{
    m_noServiceText = NULL;
    m_separatorL = NULL;
    m_isFold = VFX_TRUE;
    m_foldButton = NULL;
}

void VappNCenterOperatorCell::onInit()
{
    VfxFrame::onInit();

    setBgColor(VAPP_NCENTER_CLR_BACKGROUND);
    setSize(getParentFrame()->getSize().width , MMI_SIM_TOTAL * VAPP_NCENTER_EVENT_CELL_HEIGHT);

    initOperatorNameCell();

    VFX_OBJ_CREATE(m_noServiceText, VfxTextFrame, this);
    VfxFontDesc fontDesc;
    m_noServiceText->setColor(VAPP_NCENTER_CLR_TEXT_MAIN);      
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_SIZE);
    m_noServiceText->setFont(fontDesc);
    m_noServiceText->setString(VFX_WSTR_RES(STR_ID_VAPP_NCENTER_SYS_CELL_NO_SERVICE));
    m_noServiceText->setAnchor(0, 0.5);
    m_noServiceText->setHidden(VFX_TRUE);    
    update(getParentFrame()->getSize().width);

    mmi_frm_cb_reg_event(EVT_ID_SRV_NW_NAME_CHANGED, &VappNCenterOperatorCell::eventHandler, this);
}


void VappNCenterOperatorCell::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_NW_NAME_CHANGED, &VappNCenterOperatorCell::eventHandler, this);
    VfxFrame::onDeinit();
}



mmi_ret VappNCenterOperatorCell::eventHandler(mmi_event_struct *event)
{
    MMI_ASSERT(event);
    VappNCenterOperatorCell* operatorNameCell = (VappNCenterOperatorCell *)event->user_data;

    switch (event->evt_id)
    {
        case EVT_ID_SRV_NW_NAME_CHANGED:
            operatorNameCell->update(operatorNameCell->getSize().width);
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


void VappNCenterOperatorCell::initOperatorNameCell()
{
    VfxS32 i;
    for(i = 0; i < MMI_SIM_TOTAL; i++)
    {
        VFX_OBJ_CREATE_EX(m_operElement[i], VappNCenterOperatorElement, this, (i));
    }
}


void VappNCenterOperatorCell::update(VfxS32 maxWidth)
{
    VfxS32 i;
    VfxS32 numSIMInsert = 0;
    for(i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if(!srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(i)))
        {
            m_operElement[i]->setHidden(VFX_TRUE);
            continue;
        }
        m_operElement[i]->setPos(0, numSIMInsert*VAPP_NCENTER_EVENT_CELL_HEIGHT);
        m_operElement[i]->setHidden(VFX_FALSE);
        numSIMInsert++;
    }

    if(numSIMInsert == 0)
    {
        m_noServiceText->setHidden(VFX_FALSE);
        m_noServiceText->setPos(VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_X , VAPP_NCENTER_EVENT_CELL_HEIGHT/2);
        insertSeparator(this, VAPP_NCENTER_EVENT_CELL_HEIGHT);  
    }

    if(numSIMInsert >= 1)
    {
        m_noServiceText->setHidden(VFX_TRUE);
        if(numSIMInsert > 1)
        {
            createFoldButton(VFX_TRUE);
        }
        else
        {
            createFoldButton(VFX_FALSE);
        }

        // update operator name cell content after set Cell Height
        // because fold icon is created after setCellHeight
        for(i = 0; i < MMI_SIM_TOTAL; i++)
        {
            if(!srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(i)))
            {
                continue;
            }
            m_operElement[i]->updateOperatorName(maxWidth);
        }

        if(getIsFold())
        {
            requestNCenterUpdate((VfxId)this, VAPP_NCENTER_EVENT_CELL_HEIGHT);
        }
        else
        {
            requestNCenterUpdate((VfxId)this, numSIMInsert*VAPP_NCENTER_EVENT_CELL_HEIGHT);
        }
    }
    else
    {
        requestNCenterUpdate((VfxId)this, VAPP_NCENTER_EVENT_CELL_HEIGHT);
        createFoldButton(VFX_FALSE);
    }
}


void VappNCenterOperatorCell::insertSeparator(VfxFrame *target, VfxS32 posY)
{
    if(!m_separatorL)
    {
        VFX_OBJ_CREATE(m_separatorL, VfxImageFrame, target);
#if defined(__MMI_VUI_COSMOS_CP__)
        m_separatorL->setResId(IMG_COSMOS_SEPARATOR_LINE);
        m_separatorL->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_separatorL->setSize(target->getSize().width, m_separatorL->getSize().height);
#else
        m_separatorL->setBgColor(VAPP_NCENTER_CLR_SEPERATOR);
        m_separatorL->setSize(target->getSize().width, 1);
#endif      
    }
    m_separatorL->setPos(0, posY - 2 );
}



void VappNCenterOperatorCell::createFoldButton(VfxBool isCreate){

    if (isCreate)
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);

        if(m_foldButton == NULL)
        {
            VFX_OBJ_CREATE(m_foldButton, VcpImageButton, this);
            m_foldButton->setAnchor(0.47f, 0.49f);
            m_foldButton->setImage(VcpStateImage(VAPP_IMG_NCENTER_FOLD_ICON));
            m_foldButton->setSize(VAPP_NCENTER_FOLD_BUTTON_WIDTH,VAPP_NCENTER_FOLD_BUTTON_HEIGHT);
            m_foldButton->setPos(getSize().width - 2 - VAPP_NCENTER_FOLD_BUTTON_GAP_X - VAPP_NCENTER_FOLD_BUTTON_WIDTH/2, VAPP_NCENTER_EVENT_CELL_HEIGHT/2);    
            m_foldButton->m_signalClicked.connect(this, &VappNCenterOperatorCell::onFoldButtonClick);   
        }
        VfxTransform tempTransform;
        tempTransform.type = VFX_TRANSFORM_TYPE_AFFINE;
        tempTransform.data.affine.rz = VFX_DEG_TO_RAD(m_isFold ? 180 : 0);
        m_foldButton->setTransform(tempTransform);

        VfxAutoAnimate::commit();
    }
    else
    {
        VFX_OBJ_CLOSE(m_foldButton);  
    }

}


void VappNCenterOperatorCell::onFoldButtonClick(VfxObject* sender, VfxId id)
{ 
    VFX_UNUSED(sender);
    VFX_UNUSED(id);

    setIsFold(!m_isFold);
}


void VappNCenterOperatorCell::setIsFold(VfxBool isFold)
{
       
    VfxTransform tempTransform;
    tempTransform.type = VFX_TRANSFORM_TYPE_AFFINE;
    
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_FALSE);
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);   
    VfxAutoAnimate::setDuration(300);    

    m_isFold = isFold;    

    if (m_foldButton)
    {
        if (!isFold)
        {      
            tempTransform.data.affine.rz = VFX_DEG_TO_RAD(0);
        }
        else
        {
            tempTransform.data.affine.rz = VFX_DEG_TO_RAD(180);
        }
        
        m_foldButton->setTransform(tempTransform);        
    }

    update(getSize().width);
    VfxAutoAnimate::commit();

}


