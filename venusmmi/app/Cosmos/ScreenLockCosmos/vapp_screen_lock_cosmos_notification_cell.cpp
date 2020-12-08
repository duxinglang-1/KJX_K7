/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *  vapp_screen_lock_cosmos_notification_cell.cpp
 *
 * Project:
 * --------
 *  COSMOS Screen Lock Notification Cell
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
// for the display of notification events
#include "vsrv_ncenter.h"
#include "vapp_platform_context.h"

#include "Vapp_screen_lock_cosmos_notification_cell.h"
#include "mmi_rp_vapp_screen_lock_cosmos_def.h"        //for the background

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#ifdef  __MMI_NSS_SUPPORT__
// for NSS support
#include "NotificationSettingSrvGprot.h" 
#endif
#include "AppMgrSrvGprot.h"                            // for query app info

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * Define
 *****************************************************************************/
#define VAPP_SLK_COSMOS_INVALID_ID 0xFFFFFFFF

/***************************************************************************** 
 * Class VappScreenLockLiberateNotiPanel
 *****************************************************************************/
VappScreenLockLiberateNotiPanel::VappScreenLockLiberateNotiPanel():
    m_isNotiShowed(VFX_FALSE),
    m_isNotiEmpty(VFX_TRUE),
    m_list(NULL),
    m_eventCount(0)
{
}


void VappScreenLockLiberateNotiPanel::onInit()
{
    VfxFrame::onInit();

    // Create list cell
    onCreateContentView(this);
}


void VappScreenLockLiberateNotiPanel::onDeinit()
{
    VFX_OBJ_CLOSE(m_list);
    
    VfxFrame::onDeinit();
}


void VappScreenLockLiberateNotiPanel::onCreateContentView(VfxFrame* parent)
{    
    //VFX_ASSERT(m_list == NULL);
        
    VFX_OBJ_CREATE(m_list, VappScreenLockCosmosNotificationList, parent);
    m_list->setPos(0, 0);
    //m_list->setSize(m_notiPanel->getSize());
    m_list->setSize(this->getSize());
    m_list->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

    VfxList <VappScreenLockCosmosNotificationGroupStruct> grouplist;
    grouplist.init(parent);

    VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);

    // Connect signal    
    nm->m_signalNStatus.connect(this, &VappScreenLockLiberateNotiPanel::onNotificationChanged);

    // To get all notification groups        
    VfxList <VsrvNGroup*>::It it = nm->getNGroups();
                    
    for (; !it.isNull(); ++it)
    {
        // Get all notification of a group
        VsrvNGroup* group = *it;
        VfxList <VsrvNotification*>::It itt = group->getNotifications();        
        for (; !itt.isNull() ; ++itt)
        {
            VsrvNotification *noti = *itt;
            if (checkNotification(noti))
            {                    
                VfxList <VappScreenLockCosmosNotificationGroupStruct>::It ittt = grouplist.begin();        
                for (; !ittt.isNull(); ++ittt)
                {
                    VappScreenLockCosmosNotificationGroupStruct data = *ittt;                        
                    VfxDateTime::CompareEnum result = noti->getTimeStamp().compareWith(data.groupTimeStamp);
                    if (result != VfxDateTime::LESS)
                    {
                        break;             
                    }                         
                }

                VappScreenLockCosmosNotificationGroupStruct data;
                data.group = group;
                data.groupTimeStamp = noti->getTimeStamp();

                if (ittt.isNull())
                {
                    grouplist.pushBack(data);
                }
                else
                {
                    grouplist.insert(ittt, data);        
                }
                break;
                
            }                
        }            
    }

    VfxId refId = VAPP_SLK_COSMOS_INVALID_ID;
    VfxList <VappScreenLockCosmosNotificationGroupStruct>::It ittt = grouplist.begin();
    for (; !ittt.isNull(); ++ittt)
    {
        VappScreenLockCosmosNotificationGroupStruct gdata = *ittt;                        
        VsrvNGroup* group = gdata.group;
        // TO check group type in order to get correct data
        /*
        if (group->getType() == VSRV_NGROUP_TYPE_SINGLE_TITLE)
        {
            VappScreenLockCosmosNotificationCellStruct data;
            data.timeStamp = gdata.groupTimeStamp;
            data.type = VAPP_SCREEN_LOCK_COSMOS_CELL_TYPE_HEADER;   
            m_list->addItem((VfxId)group, VAPP_SCREEN_LOCK_NOTI_CAPTION_HEIGHT, &data, sizeof(data));
            refId = (VfxId)group;
        }
        */
        VfxList <VsrvNotification*>::It itt = group->getNotifications();
        for (; !itt.isNull() ; ++itt)
        {
            VsrvNotification *noti = *itt;
            if (checkNotification(noti))
            {
                createCell(noti, refId);
                refId = (VfxId) noti;                
                m_isNotiEmpty = VFX_FALSE;
            }                            
        }                  
    }
}


VfxBool VappScreenLockLiberateNotiPanel::checkNotification(VsrvNotification *noti)
{
        U16 settingValue = 1;
    
#ifdef  __MMI_NSS_SUPPORT__
        //check APP's NSS setting
    mmi_srv_nss_get_setting(noti->getGroupId(), NSS_SETTING_LOCK_SCRN, &settingValue);
#endif
            
    if (settingValue && noti->getIsStable() && checkAppID(noti))
    {
        if (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT)
        {
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}


void VappScreenLockLiberateNotiPanel::createCell(VsrvNotification *noti, VfxId refId, VfxBool addBeforeRef)
{

    if (noti->getIsStable())
    {   
        if (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT)
        {
            m_eventCount++;

            VappScreenLockCosmosNotificationCellStruct data;
            data.timeStamp = noti->getTimeStamp();
            data.type = VAPP_SCREEN_LOCK_COSMOS_CELL_TYPE_EVENT;

            if (refId == VAPP_SLK_COSMOS_INVALID_ID)
            {
                m_list->addItem((VfxId) noti, VAPP_SCREEN_LOCK_NOTI_ONGOING_CELL_HEIGHT, &data, sizeof(data));
            }
            else
            {
                m_list->insertItem((VfxId) noti, VAPP_SCREEN_LOCK_NOTI_ONGOING_CELL_HEIGHT, refId, addBeforeRef, &data, sizeof(data));
            }
        }
    } 
}


void VappScreenLockLiberateNotiPanel::closeCell(VsrvNotification *noti)
{
    VfxBool removed = m_list->removeItem((VfxId)noti);

	if (removed)
	{		
		if (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT)
		{
			m_eventCount--;            
		}
	}   

}


void VappScreenLockLiberateNotiPanel::onNotificationChanged(VsrvNotification* noti, VsrvNStatusType status)
{
    // Only shows the type of nsrv event and sent by spefic apps.
    if (noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT && checkAppID(noti))
    { 
		// Submit the signal to screen lock to switch two panels.
        m_signalNotiChanged.emit();

        m_isNotiShowed = VFX_TRUE;        
        
        if (checkNotification(noti)|| m_list->getItemIndex((VfxId)noti) >=0)
        {
            VfxBool refresh = VFX_FALSE;
            VfxBool create = VFX_FALSE;
            VfxId refId = VAPP_SLK_COSMOS_INVALID_ID;
            VsrvNGroup *group = noti->getGroup();

            VfxS32 count = 0;
            VfxList <VsrvNotification*>::It itt;
            for (itt = group->getNotifications(); !itt.isNull() ; ++itt)
            {
                VsrvNotification *n = (*itt);
                if (checkNotification(n))
                {
                    count++;
                }                                   
            }   
            
            if (status == VSRV_NSTATUS_CREATE)
            {                                               
                if (count == 1)                
                {                       
                    create = VFX_TRUE;                               
                }                     
                else
                {               
                    refresh = VFX_TRUE;
                }
            }
            else if (status == VSRV_NSTATUS_UPDATE)
            {                                    
                VappScreenLockCosmosNotificationCellStruct* data = (VappScreenLockCosmosNotificationCellStruct*)m_list->getItemData((VfxId)noti);

                if (data)
                {
                    VfxDateTime::CompareEnum result = noti->getTimeStamp().compareWith(data->timeStamp);
                    if ((result == VfxDateTime::EQUAL || count == 1) && checkIsTheSameType(noti, data))
                    {
                        //m_list->updateItem((VfxId)group);
                        m_list->updateItem((VfxId)noti);
                    }                              
                    else
                    {
                        if (count == 0)
                        {
                            m_list->removeItem((VfxId)(noti->getGroup()));
                            closeCell(noti);     
                        }
                        else if (count == 1)
                        {
                            create = VFX_TRUE;
                        }
                        else
                        {
                            closeCell(noti);                             
                            refresh = VFX_TRUE;                
                        }
                    }
                }
                else
                {
                    create = VFX_TRUE;
                }
            }                               
            else if (status == VSRV_NSTATUS_CLOSE)
            {     
                closeCell(noti);    
                
                if (count == 1)
                {
                    m_list->removeItem((VfxId)(noti->getGroup()));
                    m_isNotiEmpty = VFX_TRUE;
                    m_signalNotiEmpty.emit();

                }
                else
                {
                    m_list->updateItem((VfxId)group);
                }                      
            }

            if (create)
            {
                /*if (group->getType() == VSRV_NGROUP_TYPE_SINGLE_TITLE)
                {
                    VappNCenterListCellStruct data;
                    data.type = VAPP_NCENTER_LIST_CELL_TYPE_HEADER;                    
                    data.timeStamp = noti->getTimeStamp();
                    m_list->insertItem((VfxId)group, VAPP_NCENTER_CAPTION_HEIGHT, 0, &data, sizeof(data));                        
                    refId = (VfxId)group;
                } */  
                if (refId == VAPP_SLK_COSMOS_INVALID_ID)
                {
                    if (m_list->getCellCount() == 0)
                    {
                        createCell(noti, refId, VFX_FALSE);  // add to back                      
                    }
                    else
                    {
                        refId = m_list->getItemId(0);
                        createCell(noti, refId, VFX_TRUE);
                    }
                }
                else
                {
                    createCell(noti, refId, VFX_FALSE);  // add to back         
                }
                m_isNotiEmpty = VFX_FALSE;
            }
            
            if (refresh)
            {
                m_list->updateItem((VfxId)group);
                VsrvNotification *target = noti->getPrevious();
                while(target)
                {
                    if (checkNotification(target))
                    {
                        break;                        
                    }
                    target = target->getPrevious();
                }
                if (target)
                {
                    createCell(noti, (VfxId)target, VFX_FALSE);                                        
                }
                else
                {
                    target = noti->getNext();
                    while(target)
                    {
                        if (checkNotification(target))
                        {
                            break;                        
                        }
                        target = target->getNext();
                    }
                    if (target)
                    {
                        createCell(noti, (VfxId)target, VFX_TRUE);
                        return;
                    }
                }                
                m_isNotiEmpty = VFX_FALSE;
            }           
        }        
    }
}


VfxBool VappScreenLockLiberateNotiPanel::checkIsTheSameType(VsrvNotification *noti, VappScreenLockCosmosNotificationCellStruct* data)
{
    if (data->type == VAPP_SCREEN_LOCK_COSMOS_CELL_TYPE_EVENT && noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT)
    {
        return VFX_TRUE;
    }
        
    if(noti->getType() == VSRV_NOTIFICATION_TYPE_CUSTOM)
    {
        VsrvNotificationCustom* cust = (VsrvNotificationCustom*)noti;       
        if (data->type == VAPP_SCREEN_LOCK_COSMOS_CELL_TYPE_EVENT && cust->getCategory() ==VSRV_NOTIFICAITON_CUSTOM_CATEGORY_EVENT)
        {
            return VFX_TRUE;
        }            
    }    
    return VFX_FALSE;
}


VfxBool VappScreenLockLiberateNotiPanel::checkAppID(VsrvNotification* noti)
{
    //
    // Only shows notifications which sent by specific 5 Apps.
    // CALLLOG,EMAIL,MSG,SNS,MRE
    //
    VfxU32 app_id;
    app_id = noti->getGroupId();
    
    if(app_id == VAPP_CALLLOG || app_id == VAPP_EMAIL || app_id == VAPP_MSG
        #ifdef __MMI_SNS_CENTER__
            || app_id == VAPP_SNS
        #endif
        )
    {
        return VFX_TRUE;
    }
    else
    {
        //
        // Check if it is MRE app type
        // app id -> package name
        //
        mmi_app_package_name_struct appName;
        srv_appmgr_get_app_package_name_by_id(app_id, appName);
        if (srv_appmgr_get_app_package_type(appName) == SRV_APPMGR_MRE_APP_PACKAGE_TYPE)
        {
            // MRE app type
            return VFX_TRUE;
        }
        else
        {
            // The rest of notifications which do not show on lock screen.
            return VFX_FALSE;
        }
    }
}

/***************************************************************************** 
 * Class VappScreenLockCosmosBaseCell
 *****************************************************************************/


VappScreenLockCosmosBaseCell::VappScreenLockCosmosBaseCell() :
    m_noti(NULL),
    m_maxMoveOffset(0)
{}

void VappScreenLockCosmosBaseCell::setNotification(VsrvNotification* noti)
{
    ASSERT(noti);
    m_noti = noti;
}


VsrvNotification* VappScreenLockCosmosBaseCell::getNotification()
{
    return m_noti;
}


#if 0 // No onPenInput in the current design.
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/***************************************************************************** 
 * Class VappScreenLockCosmosEventCell
 *****************************************************************************/


VappScreenLockCosmosEventCell::VappScreenLockCosmosEventCell() :
    m_icon(NULL),
    m_mainText(NULL),
    m_subText(NULL),
    m_rightText(NULL)
{}

void VappScreenLockCosmosEventCell::onInit()
{
    VappScreenLockCosmosBaseCell::onInit();
  
    setSize(VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_WIDTH, VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_HEIGHT);

    VFX_OBJ_CREATE(m_icon, VfxFrame, this);
    m_icon->setAnchor(0, 0.5f);
    m_icon->setImgContent(VfxImageSrc(IMG_ID_VAPP_SCREEN_LOCK_DEFAULT_EVENT_ICON));
    m_icon->setPos(VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_ICON_X, VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_HEIGHT/2);
    m_icon->setSize(VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_ICON_WIDTH, VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_ICON_HEIGHT);
    m_icon->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_NONE);
    m_icon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);


    VFX_OBJ_CREATE(m_mainText, VfxTextFrame, this);
    m_mainText->setPos(VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_MAIN_TEXT_X, VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_MAIN_TEXT_Y);
    m_mainText->setSize(VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_MAIN_TEXT_WIDTH, 1);    
	m_mainText->setColor(VFX_COLOR_WHITE); 

    VfxFontDesc fontDesc;
    fontDesc.effect = VFX_FE1_9;
	fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_MAIN_TEXT_SIZE);
    m_mainText->setFont(fontDesc);   
    VfxS32 tempHeight = m_mainText->getSize().height;    
    m_mainText->setAutoResized(VFX_FALSE);
    m_mainText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_mainText->setSize(VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_MAIN_TEXT_WIDTH, tempHeight);
    m_mainText->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);

    VFX_OBJ_CREATE(m_subText, VfxTextFrame, this);
    m_subText->setAnchor(0, 1.0f);
    m_subText->setPos(VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_SUB_TEXT_X, VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_HEIGHT - VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_SUB_TEXT_Y);
	m_subText->setColor(VfxColor(255,204,204,204));

    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_SUB_TEXT_SIZE);
    fontDesc.attr = VFX_FONT_DESC_ATTR_NORMAL;
    fontDesc.effect = VFX_FE1_9;
    m_subText->setFont(fontDesc);
    tempHeight = m_subText->getSize().height;
    m_subText->setAutoResized(VFX_TRUE);
    m_subText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_subText->setSize(VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_SUB_TEXT_WIDTH, tempHeight);
    m_subText->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

    VFX_OBJ_CREATE(m_rightText, VfxTextFrame, this);
    m_rightText->setAnchor(1.0f, 1.0f);
    m_rightText->setPos(VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_WIDTH - VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_RIGHT_TEXT_X, VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_HEIGHT - VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_RIGHT_TEXT_Y);   
	m_rightText->setColor(VfxColor(255,204,204,204));

    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_RIGHT_TEXT_SIZE);
    fontDesc.effect = VFX_FE1_9;    
    m_rightText->setFont(fontDesc);
    tempHeight = m_rightText->getSize().height;
    m_rightText->setAutoResized(VFX_FALSE);
    m_rightText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_rightText->setSize(VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_RIGHT_TEXT_WIDTH, tempHeight);
    m_rightText->setAlignParent(VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
}


void VappScreenLockCosmosEventCell::updateElements()
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

        if (m_subText->getString().isEmpty())
        {
            m_mainText->setAnchor(0.f, 0.5f);
            m_mainText->setPos(VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_MAIN_TEXT_X, (VfxS32)(getSize().height * 0.5));
            m_mainText->setSize(VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_MAIN_TEXT_WIDTH - VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_RIGHT_TEXT_WIDTH, m_mainText->getSize().height);        
            m_mainText->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);
        }      
    }     
}

/***************************************************************************** 
 * Class VappScreenLockCosmosNotificationCell 
 *****************************************************************************/

void VappScreenLockCosmosNotificationCell::onInit()
{
    VcpVarHeightMenuCell::onInit();
    
    setAutoAnimate(VFX_TRUE);    
    //setOpacity(0.5);

    // group header
    if (m_type == VAPP_SCREEN_LOCK_COSMOS_CELL_TYPE_HEADER)
    {
        setSize(VAPP_SCREEN_LOCK_NOTI_ONGOING_CELL_WIDTH, VAPP_SCREEN_LOCK_NOTI_CAPTION_HEIGHT);
        setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE); 
        setImgContent(VfxImageSrc(VCP_IMG_LIST_MENU_GROUP_HEADER_BG));
    }
    else
    {
        // the size of each cell
        setSize(VAPP_SCREEN_LOCK_NOTI_ONGOING_CELL_WIDTH, VAPP_SCREEN_LOCK_NOTI_ONGOING_CELL_HEIGHT);
        VfxFrame *seperator;
        VFX_OBJ_CREATE(seperator, VfxFrame, this);
        seperator->setImgContent(VfxImageSrc(IMG_ID_VAPP_SCREEN_LOCK_NOTIFICATION_LINE));        
        seperator->setRect(VfxRect(VfxPoint(0, getBounds().getMaxY()-1), 
                           VfxSize(getBounds().getWidth(),2)));     // minus 1 for the 2 pixs height of the seperator
        seperator->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        seperator->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    }
}


void VappScreenLockCosmosNotificationCell::onUpdate()
{
    VcpVarHeightMenuCell::onUpdate();
    /*if (m_type == VAPP_NCENTER_LIST_CELL_TYPE_HEADER)
    {
        VsrvNGroupSingleTitle *group = (VsrvNGroupSingleTitle *)(getMenu()->getItemId(m_menupos.pos));
        VfxTextFrame *text = (VfxTextFrame *)m_content.get();
        if (text)
        {
            text->setString(group->getTitle());
        }
    }
    else*/
    if (m_type == VAPP_SCREEN_LOCK_COSMOS_CELL_TYPE_EVENT)
    {        
        VappScreenLockCosmosEventCell *item = (VappScreenLockCosmosEventCell *)m_content.get();
        if (item)
        {
            item->updateElements();        
        }        
    }
    /*else if (m_type == VAPP_SCREEN_LOCK_COSMOS_CELL_TYPE_ONGOING)
    {
        VappNCenterOngoingCell *item = (VappNCenterOngoingCell *)m_content.get();
        if (item)
        {
            item->updateElements();
        }
    }*/
}


void VappScreenLockCosmosNotificationCell::setContent(VfxFrame *content)
{
    VFX_ASSERT(content);
    m_content = content;
}


VfxFrame* VappScreenLockCosmosNotificationList::createCell(VfxS32 group, VfxS32 pos)
{    
    VappScreenLockCosmosNotificationCellStruct *data = (VappScreenLockCosmosNotificationCellStruct *)m_items[pos].m_userData;
    VappScreenLockCosmosNotificationCell *cell;
    VFX_OBJ_CREATE_EX(cell, VappScreenLockCosmosNotificationCell, this, (VcpMenuPos(group, pos), data->type));
    cell->setSize(getSize().width, cell->getSize().height);	
    
    switch(data->type)
    {
        case VAPP_SCREEN_LOCK_COSMOS_CELL_TYPE_HEADER:
        {
            VsrvNGroupSingleTitle *group = (VsrvNGroupSingleTitle *)m_items[pos].m_id;
            VfxTextFrame *text;
            VFX_OBJ_CREATE(text, VfxTextFrame, cell);          
            text->setAnchor(0, 0.5);
            text->setPos(VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_ICON_X, cell->getSize().height / 2);
            text->setAutoResized(VFX_TRUE);
            text->setString(group->getTitle());
            text->setFont(VfxFontDesc(VAPP_SCREEN_LOCK_NOTI_CAPTION_FONT_SIZE, VFX_FE1_9));
            cell->setContent(text);
            break;
        }
        case VAPP_SCREEN_LOCK_COSMOS_CELL_TYPE_EVENT:
        {
            VsrvNotificationEvent *noti = (VsrvNotificationEvent *)m_items[pos].m_id;
            VappScreenLockCosmosEventCell *item;

            VFX_OBJ_CREATE(item, VappScreenLockCosmosEventCell, cell);       
            /*item->setSize(cell->getSize());
            item->setMainText(noti->getMainText());
            item->setSubText(noti->getSubText());                
            item->setRightText(noti->getTimeStamp().getDateTimeString(VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY));                        
            item->setIcon(noti->getIcon());
            item->setNotification(noti);
            item->sendToBack();*/
            item->setNotification(noti);
            item->setSize(cell->getSize());        
            item->updateElements();        
            item->sendToBack();  
            
            cell->setContent(item);
            
            break;
        }

        case VAPP_SCREEN_LOCK_COSMOS_CELL_TYPE_ONGOING:
        {
            // for further implementation
        }
        case VAPP_SCREEN_LOCK_COSMOS_CELL_TYPE_CUSTOM:
        {            
            // for further implementation
        }
    }
    
	cell->sendToBack();
    m_bkgd->sendToBack();

    return cell;
}

   
void VappScreenLockCosmosNotificationList::onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame)
{
    VFX_OBJ_CLOSE(cellFrame);
}


