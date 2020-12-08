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
 *
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 *
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
#include "Vapp_ncenter_base_cell.h"

#if defined(__MMI_NCENTER_SUPPORT__) && !defined(__MMI_KEY_ONLY_NCENTER__)

#include "vcp_res.h"
#include "vapp_ncenter.h"
#include "vsrv_ncenter.h"

#include "vcp_global_popup.h"


#include "vapp_platform_context.h"
#if defined(__MMI_VUI_COSMOS_CP__)
#include "mmi_rp_app_cosmos_global_def.h"
#endif /* defined(__MMI_VUI_COSMOS_CP__) */    




/***************************************************************************** 
 * Class VappNCenterBaseCell
 *****************************************************************************/


VappNCenterBaseCell::VappNCenterBaseCell()
{
	m_noti = NULL;
	m_menu = NULL;
	m_maxMoveOffset = 0;
}

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

VfxBool VappNCenterBaseCell::onPenInput(VfxPenEvent & event)
{
    if (!m_menu || !m_noti)
    {
        VFX_ASSERT(0);        
    }
    
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
       VcpMenuPos menuPos = VcpMenuPos(0, m_menu->getItemIndex((VfxId)m_noti)); 
       VFX_ASSERT(menuPos.isValid());    

       m_menu->setFocusItem(menuPos, VFX_TRUE);
       m_maxMoveOffset = 0;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
       m_menu->clearFocusItem();       
       if (m_maxMoveOffset <= 30)  // tap
       {        
            if (m_noti->getAutoLaunch())
            {
                VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
                NCenter->requestLeave(m_noti);
            }
            else
            {
                VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);

                VfxBool autoClose = m_noti->getAutoClose(VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_TAP);
                VfxS32 serialNum = m_noti->getSerialNum();                               
                vsrv_ncenter_send_intent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_TAP, m_noti);

                if (autoClose && nm->checkNotification(m_noti) && m_noti->getSerialNum() == serialNum)
                {
                    vsrv_ncenter_send_intent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_CLOSE, m_noti);

                    VsrvNotification* temp = m_noti;
                    m_noti = NULL;                    
                    VSRV_NOTIFICATION_CLOSE(temp); //set NULL to tmp so not access invalid m_noti
                }
            }                
            
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
           m_menu->clearFocusItem();
       }
    }else if (event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
        m_menu->clearFocusItem();
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
    m_mainText->setColor(VAPP_NCENTER_CLR_TEXT_MAIN);    

    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_SIZE);
    m_mainText->setFont(fontDesc);         
    m_mainText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_mainText->setBounds(VfxRect(0, 0, VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_WIDTH, 0));
    m_mainText->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);

    VFX_OBJ_CREATE(m_subText, VfxTextFrame, this);
    m_subText->setAnchor(0, 1.0f);
    m_subText->setPos(VAPP_NCENTER_EVENT_CELL_SUB_TEXT_X, VAPP_NCENTER_EVENT_CELL_HEIGHT - VAPP_NCENTER_EVENT_CELL_SUB_TEXT_Y);
    m_subText->setColor(VAPP_NCENTER_CLR_TEXT_SUB); 

    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_NCENTER_EVENT_CELL_SUB_TEXT_SIZE);
    m_subText->setFont(fontDesc);        
    m_subText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_subText->setBounds(VfxRect(0, 0, VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_WIDTH - VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_WIDTH, 0));
    m_subText->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

    VFX_OBJ_CREATE(m_rightText, VfxTextFrame, this);
    m_rightText->setAnchor(1.0f, 1.0f);
    m_rightText->setPos(VAPP_NCENTER_EVENT_CELL_WIDTH - VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_X, VAPP_NCENTER_EVENT_CELL_HEIGHT - VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_Y);   
    m_rightText->setColor(VAPP_NCENTER_CLR_TEXT_SUB); 

    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_SIZE);
    m_rightText->setFont(fontDesc);            
    m_rightText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_rightText->setBounds(VfxRect(0, 0, VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_WIDTH, 0));
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
		VfxU32 flg;
        if (notiTime.getYear() == currTime.getYear()&&
            notiTime.getMonth() == currTime.getMonth() &&
            notiTime.getDay() == currTime.getDay())
        {
            flg = VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE; 
        }
        else
        {
            flg = VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY;                                        
        }           
		setRightText(notiTime.getDateTimeString(flg)); 

        VfxSize oriSize = getSize();      
        
        setSize(VAPP_NCENTER_EVENT_CELL_WIDTH, VAPP_NCENTER_EVENT_CELL_HEIGHT);
		VfxFloat anchorY;
		VfxS32 posY;
		VfxS32 width;
        if (m_subText->getString().isEmpty())
        {
        	anchorY = 0.5f;
			posY = getSize().height/2;
            width = VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_WIDTH - VAPP_NCENTER_EVENT_CELL_RIGHT_TEXT_WIDTH;        
        }
        else
        {
        	anchorY = 0.0f;
            posY = VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_Y;
            width = VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_WIDTH;                
		}
        m_mainText->setAnchor(0.0f, anchorY);
        m_mainText->setPos(VAPP_NCENTER_EVENT_CELL_MAIN_TEXT_X, posY);		
		m_mainText->setBounds(VfxRect(0, 0, width, 0));			
		m_mainText->setAlignParent(
						VFX_FRAME_ALIGNER_MODE_SIDE, 
						VFX_FRAME_ALIGNER_MODE_SIDE, 
						VFX_FRAME_ALIGNER_MODE_SIDE, 
						VFX_FRAME_ALIGNER_MODE_NONE
						); 		   
        setSize(oriSize);
    }     
}


/***************************************************************************** 
 * Class VappNCenterOngoingCell
 *****************************************************************************/

typedef struct 
{
    MMI_EVT_PARAM_HEADER
    VfxS32 popup_handle;
} vapp_ncenter_ongoing_cell_cancel_popup_event_struct;



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
    m_mainText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_mainText->setBounds(VfxRect(0, 0, VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_WIDTH, 0));
    m_mainText->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);

    VFX_OBJ_CREATE(m_subText, VfxTextFrame, this);
    m_subText->setAnchor(0, 1.0f);
    m_subText->setPos(VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_X, VAPP_NCENTER_ONGOING_CELL_HEIGHT - VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_Y);
    m_subText->setColor(VAPP_NCENTER_CLR_TEXT_SUB);
    
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_SIZE);
    m_subText->setFont(fontDesc);
    m_subText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_subText->setBounds(VfxRect(0, 0, VAPP_NCENTER_ONGOING_CELL_SUB_TEXT_WIDTH, 0));
    m_subText->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

    VFX_OBJ_CREATE(m_closeButton, VcpImageButton, this);
    m_closeButton->setAnchor(1.0f, 0.5f);
    m_closeButton->setPos(VAPP_NCENTER_ONGOING_CELL_WIDTH - VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_X, VAPP_NCENTER_ONGOING_CELL_HEIGHT/2);
    m_closeButton->setSize(VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_WIDTH, VAPP_NCENTER_ONGOING_CELL_CLOSE_BUTTON_HEIGHT);    
    m_closeButton->setImage(VcpStateImage(VAPP_IMG_NCENTER_CLOSE_ICON));
    
    m_closeButton->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);
    m_closeButton->m_signalClicked.connect(this, &VappNCenterOngoingCell::onButtonClickInt);

}




static void VappNCenterOngoingCellOnPopupExit(VfxId id, void *userData)
{
    if(id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        VsrvNotification* noti = (VsrvNotification*) userData;
        VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);        
        if (nm->checkNotification(noti))
        {
            VfxBool autoClose = noti->getAutoClose(VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_TERMINATE);
            VfxS32 serialNum = noti->getSerialNum();                                 
            vsrv_ncenter_send_intent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_TERMINATE, noti);
            if (autoClose && nm->checkNotification(noti) && noti->getSerialNum() == serialNum)
            {
                vsrv_ncenter_send_intent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_CLOSE, noti);
                VSRV_NOTIFICATION_CLOSE(noti);
            }                   
        }
    }
}


static mmi_ret vapp_ncenter_ongoing_cell_cancel_popup(mmi_event_struct *evt)
{
    vapp_ncenter_ongoing_cell_cancel_popup_event_struct *evnt = (vapp_ncenter_ongoing_cell_cancel_popup_event_struct *)evt;
    VfxS32 popuphandle = evnt->popup_handle;
    
    if (popuphandle != 0)
    {
#ifdef __COSMOS_MMI_PACKAGE__ 
        vcp_global_popup_cancel(popuphandle);    
#else
        VcpConfirmPopup *popup = (VcpConfirmPopup *)VfxObject::handleToObject((VfxObjHandle)popuphandle);
        if (popup)
        {
            popup->exit(VFX_FALSE);        
        }    
#endif       
    }
    
    return MMI_RET_OK;
}
    
void VappNCenterOngoingCell::onPopupButtonClicked(
    VfxObject* sender, //sender 
    VfxId id //
    )
{    
    VappNCenterOngoingCellOnPopupExit(id, m_noti);
}


void VappNCenterOngoingCell::onDeinit()
{
    vapp_ncenter_ongoing_cell_cancel_popup_event_struct postInvoke;
    MMI_FRM_INIT_EVENT(&postInvoke, 0);
    postInvoke.popup_handle = m_popupHandle;
    MMI_FRM_POST_EVENT(&postInvoke, vapp_ncenter_ongoing_cell_cancel_popup, NULL);    
    
//    VappNCenter *nc = VFX_OBJ_GET_INSTANCE(VappNCenter);
//    vfxPostInvoke1(nc, &VappNCenter::cancelPopup, m_popupHandle);
    VappNCenterBaseCell::onDeinit();  
}


#ifdef __COSMOS_MMI_PACKAGE__    

static MMI_BOOL VappNCenterOngoingCellCallback(mmi_scenario_id scen_id, void *user_data)
{   
    //dummy
    return MMI_TRUE;
}

#endif




void VappNCenterOngoingCell::onButtonClickInt(VfxObject* sender, VfxId id)
{
    onButtonClick(sender, id);
    
#ifdef __COSMOS_MMI_PACKAGE__    
    // notify after popup shown to avoid showing popup stops warning tone
    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_WARNING, &VappNCenterOngoingCellCallback, this);
#endif    
}

void VappNCenterOngoingCell::onButtonClick(VfxObject* sender, VfxId id)
{           
#ifdef __COSMOS_MMI_PACKAGE__   
        m_popupHandle = vcp_global_popup_show_confirm_two_button_str(GRP_ID_ROOT,
                                    VCP_POPUP_TYPE_WARNING,
                                    getQuestionText(),
                                    VFX_WSTR_RES(STR_GLOBAL_OK),
                                    VFX_WSTR_RES(STR_GLOBAL_CANCEL),
                                    VCP_POPUP_BUTTON_TYPE_WARNING,
                                    VCP_POPUP_BUTTON_TYPE_CANCEL,
                                    &VappNCenterOngoingCellOnPopupExit,
                                    m_noti);        
#else        
        VappNCenter *nc = VFX_OBJ_GET_INSTANCE(VappNCenter);
        VappNCenterScr *scr = nc->getNCenterScr();
        if (scr)
        {
            VcpConfirmPopup *popup = NULL;
            VFX_OBJ_CREATE (popup, VcpConfirmPopup, scr);
            popup->setInfoType(VCP_POPUP_TYPE_WARNING);
            popup->setText(getQuestionText());
            popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            popup->setCustomButton(
                              VFX_WSTR_RES(STR_GLOBAL_OK), 
                              VFX_WSTR_RES(STR_GLOBAL_CANCEL), 
                              VCP_POPUP_BUTTON_TYPE_WARNING,
                              VCP_POPUP_BUTTON_TYPE_CANCEL
                              );
            popup->m_signalButtonClicked.connect(this, &VappNCenterOngoingCell::onPopupButtonClicked);
            popup->setAutoDestory(VFX_TRUE);
            popup->show(VFX_TRUE);
 
            m_popupHandle = (VfxS32)popup->getObjHandle();
        }
#endif                
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
		VfxFloat anchorY;
		VfxS32 posY;
        if (m_subText->getString().isEmpty())
        {
        	anchorY = 0.5f;
			posY = getSize().height/2;
        }        
        else
        {
        	anchorY = 0.0f;
			posY = VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_Y;
        }	
        m_mainText->setAnchor(0.0f, anchorY);
		m_mainText->setPos(VAPP_NCENTER_ONGOING_CELL_MAIN_TEXT_X, posY);
		m_mainText->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE); 		   
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
	switch (m_type)
	{
	    case VAPP_NCENTER_LIST_CELL_TYPE_HEADER:
	    {
	        VsrvNGroupSingleTitle *group = (VsrvNGroupSingleTitle *)(getMenu()->getItemId(m_menupos.pos));
	        VfxTextFrame *text = (VfxTextFrame *)m_content.get();
	        if (text)
	        {
	            text->setString(group->getTitle());
	        }
			break;
	    }
	    case VAPP_NCENTER_LIST_CELL_TYPE_EVENT:
	    {        
	        VappNCenterEventCell *item = (VappNCenterEventCell *)m_content.get();
	        if (item)
	        {
	            item->updateElements();        
	        }
			break;
	    }
	    case VAPP_NCENTER_LIST_CELL_TYPE_ONGOING:
	    {
	        VappNCenterOngoingCell *item = (VappNCenterOngoingCell *)m_content.get();
	        if (item)
	        {
	            item->updateElements();
	        }
	        break;
	    }
	    case VAPP_NCENTER_LIST_CELL_TYPE_CUSTOM_EVENT:
		case VAPP_NCENTER_LIST_CELL_TYPE_CUSTOM_ONGOING:
	    {
	        VsrvNCell *item = (VsrvNCell *)m_content.get();
	        VsrvNotificationCustom *noti = (VsrvNotificationCustom*)item->getNotification();        
	        VFX_OBJ_CLOSE(item);                        
	        item = noti->createView(VSRV_NVIEWER_TYPE_VAPP_NCENTER, this);
	        item->setSize(getSize());               
	        item->sendToBack();
	        item->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);            
	        setContentFrame(item); 
			break;
	    }
		default:
			break;
	}
}

void VappNCenterListCell::setContentFrame(VfxFrame *content)
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
    
#ifndef __MMI_VUI_COSMOS_CP__

VfxBool VappNCenterListLayout::checkIsFocusable(VfxS32 index)
{
    VfxBool ret = VFX_TRUE;
    VappNCenterList *menu = (VappNCenterList *)m_pMenu;   
    
    VappNCenterListCellStruct *data = (VappNCenterListCellStruct *)menu->getItemData(index);        

    if (data)
    {               
        if (data->type == VAPP_NCENTER_LIST_CELL_TYPE_HEADER)
        {
             ret = VFX_FALSE;
        }
        else
        {
            VsrvNotification* noti = (VsrvNotification*) menu->getItemId(index);

            if (noti->getFlag() & VSRV_NOTIFICATION_FLAG_NO_FOCUS)
            {
                ret = VFX_FALSE;
            }
        }    
    }

    return ret;
                    
}

 
VfxBool VappNCenterListLayout::navDir(NavDirEnum dir)
{
    VfxBool ret = VcpVarHeightMenuLayout::navDir(dir);

    if (m_pMenu && (dir == NAV_DIR_UP || dir == NAV_DIR_DOWN) )
    {
        VappNCenterList *menu = (VappNCenterList *)m_pMenu;
        VcpMenuPos focusItem = m_pMenu->getFocusItem();        
        VcpMenuPos focusMarginItem = m_pMenu->getFocusMarginItem();
		VfxS32 st;

        if (focusMarginItem.isValid())
        {
            VfxS32 focusIndex = 0;
            if (focusMarginItem.group == VCP_BASE_MENU_MARGIN_AREA_TOP)
            {
                while(!checkIsFocusable(focusIndex))
                {
                    focusIndex++;
                }
            }
            else if (focusMarginItem.group == VCP_BASE_MENU_MARGIN_AREA_BOTTOM)
            {
                focusIndex = menu->getCellCount() - 1;             
                while(!checkIsFocusable(focusIndex))
                {
                    focusIndex--;
                }
            }
            focusItem = VcpMenuPos(0, focusIndex);            
        }
        else
        {
            if (dir == NAV_DIR_UP)
            {
            	st = -1;
            }
            else
            {
            	st = 1;
            }
            while(!checkIsFocusable(focusItem.pos))
            {
                focusItem.pos += st;
            }            
        }
        if (focusItem.pos == -1)
        {
            VfxS32 focusIndex = 0;
            while(!checkIsFocusable(focusIndex))
            {
                focusIndex++;
            }
            setFocusItem(VcpMenuPos(0, focusIndex));
            menu->makeVisible(VfxRect(0, 0, menu->getSize().width, menu->getSize().height), VFX_TRUE);
        }
        else if (focusItem.pos == menu->getCellCount())
        {
            VfxS32 focusIndex = menu->getCellCount() - 1;             
            while(!checkIsFocusable(focusIndex))
            {
                focusIndex--;
            }
            setFocusItem(VcpMenuPos(0, focusIndex));
        }
        else
        {
            setFocusItem(focusItem);        
        }
        ret = VFX_TRUE;        
    }
    
    return ret;
}

#endif

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
            text->setPos(VAPP_NCENTER_EVENT_CELL_ICON_X, (cell->getSize().height + 1) / 2 + 2); //+2 because bg shift down 2 pixels            
            text->setFullLineHeightMode(VFX_FALSE);
            text->setAutoResized(VFX_TRUE);            
            text->setString(group->getTitle());
            text->setFont(VfxFontDesc(VAPP_NCENTER_CAPTION_FONT_SIZE, VFX_FE1_9));                                 
            cell->setContentFrame(text);
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
            item->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

            if (VcpMenuPos(group, pos) == getFocusItem())
            {
                item->setHighlight(VFX_TRUE);
            }

            cell->setContentFrame(item);

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
            item->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
            if (VcpMenuPos(group, pos) == getFocusItem())
            {
                item->setHighlight(VFX_TRUE);
            }

            cell->setContentFrame(item);
            
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
            cell->setSize(getSize().width, noti->getHeight());
            cell->setContentFrame(item);                            
            item->setSize(cell->getSize());
            item->sendToBack();
            item->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);            


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

void VappNCenterList::onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag)
{   
     cell->setRect(rect);   
}


void VappNCenterList::onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos preFocusItem)
{
    m_signalFocusIndexChange.emit(focusItem, preFocusItem);
}

void VappNCenterList::onTouchCell(VcpMenuPos cellPos, VcpBaseMenu::CellTouchTypeEnum touchType, VfxPoint pt, VfxFrame *cell)
{
    if (touchType == VcpBaseMenu::TouchTap)
    {
        VappNCenterListCell* listCell = (VappNCenterListCell*) cell;
        VsrvNotification *noti = NULL;
		switch (listCell->getType())
		{
	        case VAPP_NCENTER_LIST_CELL_TYPE_EVENT:
			case VAPP_NCENTER_LIST_CELL_TYPE_ONGOING:
	        {
	            VappNCenterBaseCell* content = (VappNCenterBaseCell*) listCell->getContentFrame();
	            if (content)
	            {
	               noti = (VsrvNotification *) content->getNotification();
	            }
				break;
	        }
	        case VAPP_NCENTER_LIST_CELL_TYPE_CUSTOM_EVENT:
			case VAPP_NCENTER_LIST_CELL_TYPE_CUSTOM_ONGOING:
	        {
	            VsrvNCell* content = (VsrvNCell*) listCell->getContentFrame();
	            if (content)
	            {
	               noti = (VsrvNotification *) content->getNotification();
	            }
				break;
	        }
			default:
				break;
		}
        if (noti)
        {
            if (noti->getAutoLaunch())
            {
                VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
                NCenter->requestLeave(noti);
            }
            else
            {
                VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
                VfxBool autoClose = noti->getAutoClose(VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_TAP);
                VfxS32 serialNum = noti->getSerialNum();                               
                vsrv_ncenter_send_intent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_TAP, noti);

                if (autoClose && nm->checkNotification(noti) && noti->getSerialNum() == serialNum)
                {
                    vsrv_ncenter_send_intent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_CLOSE, noti);
                    VSRV_NOTIFICATION_CLOSE(noti);
                }
            }      
        }
    }
    

}


/***************************************************************************** 
 * Class VappNCenterClearCell 
 *****************************************************************************/
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



#endif /* defined(__MMI_NCENTER_SUPPORT__) && !defined(__MMI_KEY_ONLY_NCENTER__) */

