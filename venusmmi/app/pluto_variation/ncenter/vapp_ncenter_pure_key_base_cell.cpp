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
 *  vapp_ncenter_base_cell.cpp
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "Vapp_ncenter_pure_key_base_cell.h"

#if defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_KEY_ONLY_NCENTER__)

#include "vcp_res.h"
#include "vapp_ncenter_pure_key.h"
#include "vsrv_ncenter.h"

#include "vcp_global_popup.h"


#include "vapp_platform_context.h"
#if defined(__MMI_VUI_COSMOS_CP__)
#include "mmi_rp_app_cosmos_global_def.h"
#endif /* defined(__MMI_VUI_COSMOS_CP__) */    


extern "C" 
{
    #include "GlobalResDef.h"
}


/***************************************************************************** 
 * Class VappNCenterBaseCell
 *****************************************************************************/


VappNCenterBaseCell::VappNCenterBaseCell() :
    m_noti(NULL),
    m_menu(NULL),
    m_maxMoveOffset(0)
{}

void VappNCenterBaseCell::onInit()
{
    VfxControl::onInit();
    VfxFrame *parentFrame = getParentFrame();
    while(parentFrame)
    {
        VappNCenterList *parentList = VFX_OBJ_DYNAMIC_CAST(parentFrame, VappNCenterList); 
        if (parentList != NULL)
        {
            m_menu = parentList;
            break;
        }              
        parentFrame = parentFrame->getParentFrame();
    }     

    ASSERT(m_menu);

    m_menu->m_signalFocusIndexChange.connect(this, &VappNCenterBaseCell::onFocusIndexChange);
    
    registerKeyHandler(VFX_KEY_CODE_ARROW_UP);
    registerKeyHandler(VFX_KEY_CODE_ARROW_DOWN);
    registerKeyHandler(VFX_KEY_CODE_ARROW_LEFT);
    registerKeyHandler(VFX_KEY_CODE_ARROW_RIGHT);
    registerKeyHandler(VFX_KEY_CODE_LSK);
    registerKeyHandler(VFX_KEY_CODE_RSK);
    registerKeyHandler(VFX_KEY_CODE_CSK);
    
}

void VappNCenterBaseCell::onDeinit()
{
    m_menu->m_signalFocusIndexChange.disconnect(this, &VappNCenterBaseCell::onFocusIndexChange);    
    VfxControl::onDeinit();
}


void VappNCenterBaseCell::setNotification(VsrvNotification* noti)
{
    VFX_ASSERT(noti);
    m_noti = noti;
}

VsrvNotification* VappNCenterBaseCell::getNotification()
{
    return m_noti;
}


VfxBool VappNCenterBaseCell::onKeyInput(VfxKeyEvent &event)
{
    return VFX_FALSE;    
}

VfxBool VappNCenterBaseCell::onPenInput(VfxPenEvent & event)
{
    static VfxBool isFocusChanged = VFX_FALSE;
    if (!m_menu || !m_noti)
    {
        VFX_ASSERT(0);        
    }
    
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        VcpMenuPos menuPos = VcpMenuPos(0, m_menu->getItemIndex((VfxId)m_noti)); 
        VcpMenuPos oldPos;
        VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
        VFX_ASSERT(menuPos.isValid());

        if (NCenter->isFocusOnQuickSetting() == VFX_TRUE)
        {
           NCenter->clearQuickSettingFocus();
        }
        oldPos = m_menu->getFocusItem();
        if (oldPos.pos != menuPos.pos)
        {
            isFocusChanged = VFX_TRUE;
            NCenter->setLSKString(STR_GLOBAL_OPTIONS);
        }
        else
        {
            isFocusChanged = VFX_FALSE;
        }
        m_menu->setFocusItem(menuPos, VFX_TRUE);
        m_maxMoveOffset = 0;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        //m_menu->clearFocusItem();       
        if (m_maxMoveOffset <= 30)  // tap
        {        
            if (isFocusChanged == VFX_FALSE)
            {
                if (m_noti->getAutoLaunch())
                {
                    VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
                    NCenter->requestLeave(m_noti);
                }
                else
                {
                    VfxBool autoClose = m_noti->getAutoClose(VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_TAP);
                    vsrv_ncenter_send_intent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_TAP, m_noti);
                    if (autoClose)
                    {
                        vsrv_ncenter_send_intent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_CLOSE, m_noti);
                        VSRV_NOTIFICATION_CLOSE(m_noti);
                    }
                }      
            }
            isFocusChanged = VFX_FALSE;
        }  
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {   
       VfxPoint dowmpt = event.getRelDownPos(this);
       VfxPoint pt     = event.getRelPos(this);
       
       VfxS32 xoffset = VFX_ABS(pt.x - dowmpt.x);
       VfxS32 yoffset = VFX_ABS(pt.y - dowmpt.y);
       
       m_maxMoveOffset = yoffset > m_maxMoveOffset ? yoffset : m_maxMoveOffset;
       m_maxMoveOffset = xoffset > m_maxMoveOffset ? xoffset : m_maxMoveOffset;

       if (m_maxMoveOffset > 30)
       {
           //m_menu->clearFocusItem();
       }
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
        //m_menu->clearFocusItem();
    }
    
    return VFX_TRUE;   
}


void VappNCenterBaseCell::setHighlight(VfxBool isHighlight)
{
    if (isHighlight)
    {
        setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
#if defined(__MMI_VUI_COSMOS_CP__)        
       setImgContent(VfxImageSrc(VCP_IMG_LIST_MENU_HIGHLIGHT_ITEM_BACKGROUND));
#else
       setImgContent(VfxImageSrc(VAPP_IMG_NCENTER_LIST_HIGHLIGHT_BACKGROUND));
#endif
    }
    else
    {
        setImgContent(VFX_IMAGE_SRC_NULL);
    }   
}

void VappNCenterBaseCell::onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos preFocusItem)
{
    
    VcpMenuPos menuPos = VcpMenuPos(0, m_menu->getItemIndex((VfxId)m_noti)); 
    VFX_ASSERT(menuPos.isValid());    

    if(menuPos == focusItem)
    {
        setHighlight(VFX_TRUE);
    }
    if(menuPos == preFocusItem)
    {
        setHighlight(VFX_FALSE);
    }    
}


/***************************************************************************** 
 * Class VappNCenterEventCell
 *****************************************************************************/


VappNCenterEventCell::VappNCenterEventCell() :
    m_icon(NULL),
    m_mainText(NULL),
    m_subText(NULL),
    m_rightText(NULL)
{}

void VappNCenterEventCell::onInit()
{
    VappNCenterBaseCell::onInit();
  
    setSize(VAPP_NCENTER_EVENT_CELL_WIDTH, VAPP_NCENTER_EVENT_CELL_HEIGHT);

    VFX_OBJ_CREATE(m_icon, VfxFrame, this);
    m_icon->setAnchor(0, 0.5f);
    m_icon->setPos(VAPP_NCENTER_EVENT_CELL_ICON_X, VAPP_NCENTER_EVENT_CELL_HEIGHT/2);
    m_icon->setSize(VAPP_NCENTER_EVENT_CELL_ICON_WIDTH, VAPP_NCENTER_EVENT_CELL_ICON_HEIGHT);
    m_icon->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_NONE);
    m_icon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_icon->setImgContent(VfxImageSrc(VAPP_IMG_NCENTER_DEFAULT_EVENT_ICON));


    VFX_OBJ_CREATE(m_mainText, VfxTextFrame, this);
    m_mainText->setPos(VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_X, VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_Y);
    m_mainText->setSize(VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_WIDTH, 1);    
    m_mainText->setColor(VAPP_NCENTER_CLR_TEXT_MAIN);    

    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_SIZE);
    m_mainText->setFont(fontDesc);   
    VfxS32 tempHeight = m_mainText->getSize().height;    
    m_mainText->setAutoResized(VFX_FALSE);
    m_mainText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_mainText->setSize(VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_WIDTH, tempHeight);
    m_mainText->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);

    VFX_OBJ_CREATE(m_subText, VfxTextFrame, this);
    m_subText->setAnchor(0, 1.0f);
    m_subText->setPos(VAPP_NCENTER_EVENT_CELL_SUB_TEXT_X, VAPP_NCENTER_EVENT_CELL_HEIGHT - VAPP_NCENTER_EVENT_CELL_SUB_TEXT_Y);
    m_subText->setColor(VAPP_NCENTER_CLR_TEXT_SUB); 

    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_NCENTER_EVENT_CELL_SUB_TEXT_SIZE);
    m_subText->setFont(fontDesc);    
    tempHeight = m_subText->getSize().height;
    m_subText->setAutoResized(VFX_TRUE);
    m_subText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_subText->setSize(VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_WIDTH - VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_WIDTH, tempHeight);
    m_subText->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

    VFX_OBJ_CREATE(m_rightText, VfxTextFrame, this);
    m_rightText->setAnchor(1.0f, 1.0f);
    m_rightText->setPos(VAPP_NCENTER_EVENT_CELL_WIDTH - VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_X, VAPP_NCENTER_EVENT_CELL_HEIGHT - VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_Y);   
    m_rightText->setColor(VAPP_NCENTER_CLR_TEXT_SUB); 

    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_SIZE);
    m_rightText->setFont(fontDesc);    
    tempHeight = m_rightText->getSize().height;
    m_rightText->setAutoResized(VFX_FALSE);
    m_rightText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_rightText->setSize(VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_WIDTH, tempHeight);
    m_rightText->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_rightText->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);


}

void VappNCenterEventCell::setHighlight(VfxBool isHighlight)
{
    VappNCenterBaseCell::setHighlight(isHighlight);
    if (isHighlight)
    {
        m_mainText->setColor(VAPP_NCENTER_CLR_TEXT_MAIN_HIGHLIGHT);
        m_subText->setColor(VAPP_NCENTER_CLR_TEXT_SUB_HIGHLIGHT);
        m_rightText->setColor(VAPP_NCENTER_CLR_TEXT_SUB_HIGHLIGHT);
    }
    else
    {

        m_mainText->setColor(VAPP_NCENTER_CLR_TEXT_MAIN);  
        m_subText->setColor(VAPP_NCENTER_CLR_TEXT_SUB);
        m_rightText->setColor(VAPP_NCENTER_CLR_TEXT_SUB);
    }        
}


void VappNCenterEventCell::updateElements()
{           
    if (m_noti)
    {
        VsrvNotificationEvent* noti = (VsrvNotificationEvent*)m_noti;
                  
        setMainText(noti->getMainText());
        setSubText(noti->getSubText());
        setIcon(noti->getIcon());

        VfxDateTime currTime, notiTime = noti->getTimeStamp();
        currTime.setCurrentTime();
        if (notiTime.getYear() == currTime.getYear()&&
            notiTime.getMonth() == currTime.getMonth() &&
            notiTime.getDay() == currTime.getDay())
        {
            setRightText(noti->getTimeStamp().getDateTimeString(VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE)); 
        }
        else
        {
            setRightText(noti->getTimeStamp().getDateTimeString(VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY));                                        
        }           

        VfxSize oriSize = getSize();      
        
        setSize(VAPP_NCENTER_EVENT_CELL_WIDTH, VAPP_NCENTER_EVENT_CELL_HEIGHT);

        if (m_subText->getString().isEmpty())
        {
            m_mainText->setAnchor(0.0f, 0.5f);
            m_mainText->setPos(VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_X, (VfxS32)(getSize().height * 0.5));
            m_mainText->setSize(VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_WIDTH - VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_WIDTH, m_mainText->getSize().height);        
            m_mainText->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);
            
        }
        else
        {
            m_mainText->setAnchor(0.0f, 0.0f);
            m_mainText->setPos(VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_X, VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_Y);
            m_mainText->setSize(VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_WIDTH, m_mainText->getSize().height);                
            m_mainText->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);            
        }

        setSize(oriSize);
    }     
}


/***************************************************************************** 
 * Class VappNCenterOngoingCell
 *****************************************************************************/


VappNCenterOngoingCell::VappNCenterOngoingCell() :
    m_icon(NULL),
    m_mainText(NULL),
    m_subText(NULL),
    m_closeButton(NULL),
    m_popupHandle(0)
{}


void VappNCenterOngoingCell::onInit()
{
    VappNCenterBaseCell::onInit();  

    setSize(VAPP_NCENTER_ONGOING_CELL_WIDTH, VAPP_NCENTER_ONGOING_CELL_HEIGHT);

    VFX_OBJ_CREATE(m_icon, VfxFrame, this);
    m_icon->setAnchor(0, 0.5f);
    m_icon->setPos(VAPP_NCENTER_ONGOING_CELL_ICON_X, VAPP_NCENTER_ONGOING_CELL_HEIGHT/2);
    m_icon->setSize(VAPP_NCENTER_ONGOING_CELL_ICON_WIDTH, VAPP_NCENTER_ONGOING_CELL_ICON_HEIGHT);
    m_icon->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_NONE);
    m_icon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE); 
    m_icon->setImgContent(VfxImageSrc(VAPP_IMG_NCENTER_DEFAULT_EVENT_ICON));

    VFX_OBJ_CREATE(m_mainText, VfxTextFrame, this);
    m_mainText->setPos(VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_X, VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_Y);
    m_mainText->setColor(VAPP_NCENTER_CLR_TEXT_MAIN);    

    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_SIZE);
    m_mainText->setFont(fontDesc);
    VfxS32 tempHeight = m_mainText->getSize().height;    
    m_mainText->setAutoResized(VFX_FALSE);
    m_mainText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_mainText->setSize(VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_WIDTH, tempHeight);
    m_mainText->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);

    VFX_OBJ_CREATE(m_subText, VfxTextFrame, this);
    m_subText->setAnchor(0, 1.0f);
    m_subText->setPos(VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_X, VAPP_NCENTER_ONGOING_CELL_HEIGHT - VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_Y);
    m_subText->setColor(VAPP_NCENTER_CLR_TEXT_SUB);
    
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_SIZE);
    m_subText->setFont(fontDesc);
    tempHeight = m_subText->getSize().height;   
    m_subText->setAutoResized(VFX_TRUE);
    m_subText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_subText->setSize(VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_WIDTH, tempHeight);
    m_subText->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
}

void VappNCenterOngoingCell::onDeinit()
{
    VappNCenterBaseCell::onDeinit();  
}


void VappNCenterOngoingCell::setHighlight(VfxBool isHighlight)
{
    VappNCenterBaseCell::setHighlight(isHighlight);
    if (isHighlight)
    {
        m_mainText->setColor(VAPP_NCENTER_CLR_TEXT_MAIN_HIGHLIGHT);
        m_subText->setColor(VAPP_NCENTER_CLR_TEXT_SUB_HIGHLIGHT);
    }
    else
    {
        m_mainText->setColor(VAPP_NCENTER_CLR_TEXT_MAIN);  
        m_subText->setColor(VAPP_NCENTER_CLR_TEXT_SUB);
    }        
}

void VappNCenterOngoingCell::updateElements()
{
    if (m_noti)
    {
        VsrvNotificationOngoing* noti = (VsrvNotificationOngoing*)m_noti;
        setMainText(noti->getMainText());
        setSubText(noti->getSubText());
        setQuestionText(noti->getQuestionText());
        setIcon(noti->getIcon());

        if (m_subText->getString().isEmpty())
        {
            m_mainText->setAnchor(0.0f, 0.5f);
            m_mainText->setPos(VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_X, (VfxS32)(getSize().height * 0.5));
            m_mainText->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);            
        }        
        else
        {
            m_mainText->setAnchor(0.0f, 0.0f);
            m_mainText->setPos(VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_X, VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_Y);
            m_mainText->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);            
        }
    }     
}


/***************************************************************************** 
 * Class VappNCenterListCell 
 *****************************************************************************/



void VappNCenterListCell::onInit()
{
    VcpVarHeightMenuCell::onInit();
    
    setAutoAnimate(VFX_TRUE);    


    setBgColor(VAPP_NCENTER_CLR_BACKGROUND);

    if (m_type == VAPP_NCENTER_LIST_CELL_TYPE_HEADER)
    {
        setSize(VAPP_NCENTER_ONGOING_CELL_WIDTH, VAPP_NCENTER_CAPTION_HEIGHT);
        VfxFrame *frame;
        VFX_OBJ_CREATE(frame, VfxFrame, this);
        frame->setPos(0, 2);
        frame->setSize(VAPP_NCENTER_ONGOING_CELL_WIDTH, VAPP_NCENTER_CAPTION_HEIGHT - 2);

#if defined(__MMI_VUI_COSMOS_CP__)        
        frame->setImgContent(VfxImageSrc(VCP_IMG_LIST_MENU_GROUP_HEADER_BG));    
#else
        frame->setImgContent(VfxImageSrc(VAPP_IMG_NCENTER_LIST_GROUP_HEADER_BG));    
#endif
        frame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);          
        frame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    }
    else
    {
        setSize(VAPP_NCENTER_ONGOING_CELL_WIDTH, VAPP_NCENTER_ONGOING_CELL_HEIGHT);
        VfxFrame *seperator;
        VFX_OBJ_CREATE(seperator, VfxFrame, this);
#if defined(__MMI_VUI_COSMOS_CP__)
        seperator->setImgContent(VfxImageSrc(IMG_COSMOS_SEPARATOR_LINE));
        seperator->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
#else
        seperator->setBgColor(VAPP_NCENTER_CLR_SEPERATOR);
#endif


        seperator->setRect(VfxRect(VfxPoint(0, getBounds().getMaxY()), VfxSize(getBounds().getWidth(), 1)));    
        seperator->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    }
}

void VappNCenterListCell::onUpdate()
{
    VcpVarHeightMenuCell::onUpdate();
    if (m_type == VAPP_NCENTER_LIST_CELL_TYPE_HEADER)
    {
        VsrvNGroupSingleTitle *group = (VsrvNGroupSingleTitle *)(getMenu()->getItemId(m_menupos.pos));
        VfxTextFrame *text = (VfxTextFrame *)m_content.get();
        if (text)
        {
            text->setString(group->getTitle());
        }
    }
    else if (m_type == VAPP_NCENTER_LIST_CELL_TYPE_EVENT)
    {        
        VappNCenterEventCell *item = (VappNCenterEventCell *)m_content.get();
        if (item)
        {
            item->updateElements();        
        }        
    }
    else if (m_type == VAPP_NCENTER_LIST_CELL_TYPE_ONGOING)
    {
        VappNCenterOngoingCell *item = (VappNCenterOngoingCell *)m_content.get();
        if (item)
        {
            item->updateElements();
        }
        
    }
}

void VappNCenterListCell::setContent(VfxFrame *content)
{
    VFX_ASSERT(content);
    m_content = content;
}

/***************************************************************************** 
 * Class VappNCenterListLayout
 *****************************************************************************/

VappNCenterListLayout::VappNCenterListLayout(VappNCenterList *menu) :
    VcpVarHeightMenuLayout(menu)    
{
}
    
VfxS32 VappNCenterListLayout::getNextFocusItem(VfxS32 index, NavDirEnum dir)
{
    VfxS32 focusIndex = index;
    VappNCenterList *menu = (VappNCenterList *)m_pMenu;
    VappNCenterListCellStruct *data = NULL;
    VsrvNotification* noti;

    data = (VappNCenterListCellStruct *)menu->getItemData(focusIndex);
    noti = (VsrvNotification*) getVarHeightMenu()->getItemId(focusIndex);

    while(((data && data->type == VAPP_NCENTER_LIST_CELL_TYPE_HEADER)) || 
        (((VfxId)noti != VCP_VAR_HEIGHT_MENU_INVALID_ID) && (noti->getFlag() & VSRV_NOTIFICATION_FLAG_NO_CLEAR_BUTTON)))
    {
        if (dir == NAV_DIR_UP)
        {
            focusIndex--;
        }
        else if (dir == NAV_DIR_DOWN)
        {
            focusIndex++;
        }

        if ((focusIndex < 0) || (focusIndex >= menu->getCellCount()))
        {
            focusIndex = -1;
            break;
        }
        else
        {
            data = (VappNCenterListCellStruct *)menu->getItemData(focusIndex);  
            noti = (VsrvNotification*) getVarHeightMenu()->getItemId(focusIndex);
        }
    }

    return focusIndex;

}

VfxBool VappNCenterListLayout::navDir(NavDirEnum dir)
{
    VfxBool ret = VcpVarHeightMenuLayout::navDir(dir);

#ifndef __MMI_VUI_COSMOS_CP__
    if (m_pMenu && (dir == NAV_DIR_UP || dir == NAV_DIR_DOWN) )
    {
        VappNCenterList *menu = (VappNCenterList *)m_pMenu;
        VcpMenuPos focusItem = m_pMenu->getFocusItem();        
        VcpMenuPos focusMarginItem = m_pMenu->getFocusMarginItem();

        if (focusMarginItem.isValid())
        {
            VfxS32 focusIndex = 0;
            if (focusMarginItem.group == VCP_BASE_MENU_MARGIN_AREA_TOP)
            {
                focusIndex = getNextFocusItem(0, NAV_DIR_DOWN);
            }
            else if (focusMarginItem.group == VCP_BASE_MENU_MARGIN_AREA_BOTTOM)
            {
                focusIndex = menu->getCellCount() - 1;             
            }
            focusItem = VcpMenuPos(0, focusIndex);            
        }
        else
        {
            VfxS32 focusIndex = getNextFocusItem(focusItem.pos, dir);
            focusItem = VcpMenuPos(0, focusIndex);   
        }

        setFocusItem(focusItem);
    }
#endif
    
    return ret;

}

/***************************************************************************** 
 * Class VappNCenterList
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappNCenterList", VappNCenterList, VcpVarHeightMenu);

VcpBaseMenuLayout* VappNCenterList::createLayout()
{
    VappNCenterListLayout *layout;    
    VFX_OBJ_CREATE_EX(layout, VappNCenterListLayout, this, (this));
    return layout;
}


VfxFrame* VappNCenterList::createCell(VfxS32 group, VfxS32 pos)
{    
    VappNCenterListCellStruct *data = (VappNCenterListCellStruct *)m_items[pos].m_userData;
    VappNCenterListCell *cell;
    VFX_OBJ_CREATE_EX(cell, VappNCenterListCell, this, (VcpMenuPos(group, pos), data->type));
    cell->setSize(getSize().width, cell->getSize().height);

    VappNCenter *nc = VFX_OBJ_GET_INSTANCE(VappNCenter);
    if (!nc->getNCenterEntered())
    {
        cell->setCacheMode(VFX_CACHE_MODE_FREEZE);
    }
        
    switch(data->type)
    {
        case VAPP_NCENTER_LIST_CELL_TYPE_HEADER:
        {
            VsrvNGroupSingleTitle *group = (VsrvNGroupSingleTitle *)m_items[pos].m_id;
            VfxTextFrame *text;
            VFX_OBJ_CREATE(text, VfxTextFrame, cell);          
            text->setAnchor(0, 0.5);
            text->setPos(VAPP_NCENTER_EVENT_CELL_ICON_X, cell->getSize().height / 2 + 1); //+1 because bg shift down 2 pixels
            text->setFullLineHeightMode(VFX_FALSE);
            text->setAutoResized(VFX_TRUE);       
            if ((VfxId)APP_NCENTER == (VfxId)group)
            {
                text->setString(STR_ID_VAPP_NCENTER_ONGOING);
            }
            else
            {
                text->setString(group->getTitle());
            }
            text->setFont(VfxFontDesc(VAPP_NCENTER_CAPTION_FONT_SIZE, VFX_FE1_9));                                 
            cell->setContent(text);
            break;
        }
        case VAPP_NCENTER_LIST_CELL_TYPE_EVENT:
        {
            VsrvNotificationEvent *noti = (VsrvNotificationEvent *)m_items[pos].m_id;
            VappNCenterEventCell *item;

            VFX_OBJ_CREATE(item, VappNCenterEventCell, cell);       
            item->setNotification(noti);
            item->setSize(cell->getSize());        
            item->updateElements();        
            item->sendToBack();        
            if (VcpMenuPos(group, pos) == getFocusItem())
            {
                item->setHighlight(VFX_TRUE);
            }

            cell->setContent(item);

            break;
        }
        case VAPP_NCENTER_LIST_CELL_TYPE_ONGOING:
        {
            VsrvNotificationOngoing *noti = (VsrvNotificationOngoing *)m_items[pos].m_id;
            VappNCenterOngoingCell *item;            
            VFX_OBJ_CREATE(item, VappNCenterOngoingCell, cell);        
            item->setNotification(noti);
            item->setSize(cell->getSize());            
            item->updateElements();        
            item->sendToBack();
            if (VcpMenuPos(group, pos) == getFocusItem())
            {
                item->setHighlight(VFX_TRUE);
            }

            cell->setContent(item);
            
            break;
        }
        case VAPP_NCENTER_LIST_CELL_TYPE_CUSTOM_EVENT:
        case VAPP_NCENTER_LIST_CELL_TYPE_CUSTOM_ONGOING:
        {            
            VsrvNotificationCustom *noti = (VsrvNotificationCustom*)m_items[pos].m_id;
            VsrvNCell *item = noti->createView(VSRV_NVIEWER_TYPE_VAPP_NCENTER, cell);
            vsrv_ncenter_send_intent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_ENTER, noti);           
            if (nc->getNCenterEntered())
            {
                vsrv_ncenter_send_intent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_ENTERED, noti);
            }
            cell->setSize(getSize().width, item->getSize().height);
            cell->setContent(item);                            
            item->setSize(cell->getSize());
            item->sendToBack();


            break;
        }               
    }

    
    cell->sendToBack();
    m_bkgd->sendToBack();
    
    return cell;
}

   
void VappNCenterList::onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame)
{
    VFX_OBJ_CLOSE(cellFrame);
}

void VappNCenterList::onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos preFocusItem)
{
    m_signalFocusIndexChange.emit(focusItem, preFocusItem);
}

void VappNCenterList::onTouchCell(VcpMenuPos cellPos, VcpBaseMenu::CellTouchTypeEnum touchType, VfxPoint pt, VfxFrame *cell)
{
    //empty
}

VfxBool VappNCenterList::onKeyInput(VfxKeyEvent &event)
{
    //VfxBool ret = VcpVarHeightMenu::onKeyInput(event);
    return VFX_FALSE;
}

void VappNCenterList::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    return;
}


/***************************************************************************** 
 * Class VappNCenterClearCell 
 *****************************************************************************/

VappNCenterClearCell::VappNCenterClearCell()
{};

void VappNCenterClearCell::onInit()
{
    VfxControl::onInit();

    setBgColor(VAPP_NCENTER_CLR_BACKGROUND);
    setSize(VAPP_NCENTER_ONGOING_CELL_WIDTH, VAPP_NCENTER_CLEAR_CELL_HEIGHT);
    setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_clearButton, VcpButton, this);
    m_clearButton->setAnchor(0.5, 0.5);
    m_clearButton->setPos(VAPP_NCENTER_ONGOING_CELL_WIDTH/2, VAPP_NCENTER_CLEAR_CELL_HEIGHT/2);
    m_clearButton->setIsAutoResized(VFX_TRUE, 0, VAPP_NCENTER_CLEAR_CELL_BUTTON_WIDTH);
    m_clearButton->setText(VFX_WSTR_RES(STR_ID_VAPP_NCENTER_CLEAR_NOTIFICATION));
    m_clearButton->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    
}


#endif /* defined(__MMI_NCENTER_SUPPORT__) */

