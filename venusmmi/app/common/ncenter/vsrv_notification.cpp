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
 *  vapp_ncenter.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vsrv_notification.h"


#ifdef __MMI_NCENTER_SUPPORT__

#include "vsrv_ncenter.h"
#include "vapp_platform_context.h"
#include "kal_trace.h"

static VfxS32 s_serialNum = 0;


/***************************************************************************** 
 * define
 *****************************************************************************/

static vrt_bool vfx_nmanager_noti_equal(const void *value1, const void *value2)
{
    const VsrvNotification* rv1 = *(const VsrvNotification* *)value1;
    const VsrvNotification* rv2 = *(const VsrvNotification* *)value2;

    return rv1->getGroup() == rv2->getGroup() && rv1->getId() == rv2->getId() ? VFX_TRUE : VFX_FALSE;
}


/***************************************************************************** 
* Class VsrvNotification 
*****************************************************************************/

VsrvNotification::VsrvNotification()
{
    m_id = VSRV_NOTIFICATION_INVALID_ID;
    m_gid = VSRV_NGROUP_INVALID_ID;
    m_callback = NULL;
    m_userDataSize = 0;
    m_userData = NULL;
    m_isOnDeinit = VFX_FALSE;
	m_group = NULL;
    m_flag = VSRV_NOTIFICATION_FLAG_DEFAULT;
}
    

VsrvNotification::VsrvNotification(VsrvNGroup* group, VsrvNotificationId id)
{
    m_id = id;
    m_gid = group->getId();
    m_callback = NULL;
    m_userDataSize = 0;
    m_userData = NULL;
    m_isOnDeinit = VFX_FALSE;
    m_group = group;
    m_flag = VSRV_NOTIFICATION_FLAG_DEFAULT;
}

VsrvNotification::VsrvNotification(VsrvNGroupId gid, VsrvNotificationId id)
{
    m_id = id;
    m_gid = gid;
    m_callback = NULL;
    m_userDataSize = 0;
    m_userData = NULL;
    m_isOnDeinit = VFX_FALSE;
    m_group = NULL;
    m_flag = VSRV_NOTIFICATION_FLAG_DEFAULT;
}    

void VsrvNotification::_init(VfxObject* objParent)
{
    m_parentObj = objParent;

    onInit();
}

void VsrvNotification::_deinit()
{
    onDeinit();

    delete this;
}


void VsrvNotification::onInit()
{
    m_serialNum = s_serialNum++;
    m_timeStamp.setCurrentTime();    
}


void VsrvNotification::onDeinit()
{
    if (m_userData)
    {
        VFX_FREE_MEM(m_userData);
        m_userData = NULL;
        m_userDataSize = 0;
    }
}


void VsrvNotification::setIsStable(VfxBool isStable)
{
    VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
    VfxBool oldIsStable = m_flag & VSRV_NOTIFICATION_FLAG_STABLE ? VFX_TRUE : VFX_FALSE;
    _setFlag(VSRV_NOTIFICATION_FLAG_STABLE, isStable); 
    nm->broadcast(this, oldIsStable); 
    
}


void VsrvNotification::setFlag(VfxU32 flag, VfxBool on)
{
    _setFlag(flag & VSRV_NOTIFICATION_FLAG_MASK, on);
    setIsStable(VFX_FALSE);       
}

void VsrvNotification::_setFlag(VfxU32 flag, VfxBool on)
{
    if (on)
    {
       m_flag |= flag;
    }
    else
    {
       m_flag &= ~flag;
    }   
}


void VsrvNotification::setGroup(VsrvNGroup *group)
{
    m_group = group;

    if (group)
    {
        m_gid = group->getId();
    }
    else
    {
        m_gid = VSRV_NGROUP_INVALID_ID;
    }
   

    setIsStable(VFX_FALSE);    
}



void VsrvNotification::setIntentCallback(VsrvNitentFuncptr callback, void *userData, VfxU32 userDataSize)
{
    VFX_ASSERT((userData == NULL && userDataSize == 0) || (userData != NULL && userDataSize !=0));        
    VFX_ASSERT(userDataSize < NOTI_MEM_POOL_MARGIN_B);
    
    m_callback = callback;

    if (m_userData)
    {
        VFX_FREE_MEM(m_userData);
        m_userData = NULL;
        m_userDataSize = 0;
    }

    if (userData != NULL)
    {        
        m_userDataSize = userDataSize;
        VFX_ALLOC_MEM(m_userData, m_userDataSize, m_parentObj);            
        memcpy(m_userData, userData, m_userDataSize);
    }

    setIsStable(VFX_FALSE);
}


void VsrvNotification::notify()
{   
    if (m_group)
    {
        m_group->addNotification(this);
    }    
    setIsStable(VFX_TRUE);    
}

void VsrvNotification::processIntent(VsrvNIntent intent)
{
    if(m_callback)
    {
        m_callback(this, intent, m_userData, m_userDataSize);
    }    
  
}


VsrvNotification* VsrvNotification::getPrevious()
{
    if (m_group)
    {
        VfxList <VsrvNotification*>::It itt;
        for (itt = m_group->getNotifications(); !itt.isNull() ; ++itt)
        {
            VsrvNotification *n = (*itt);
            if (n == this)
            {
                break;
            }                                   
        }      
    
        if (!itt.isNull())
        {
            itt--;
            if (!itt.isNull())
            {
                return (*itt);
            }
        }          

    }
    
    return NULL;
}
VsrvNotification* VsrvNotification::getNext()
{
    if (m_group)
    {
        VfxList <VsrvNotification*>::It itt;
        for (itt = m_group->getNotifications(); !itt.isNull() ; ++itt)
        {
            VsrvNotification *n = (*itt);
            if (n == this)
            {
                break;
            }                                   
        }      
    
        if (!itt.isNull())
        {
            itt++;
            if (!itt.isNull())
            {
                return (*itt);
            }
        }          

    }
    
    return NULL;
}

/***************************************************************************** 
* Class VsrvNotificationOngoing 
*****************************************************************************/


VsrvNotificationOngoing::VsrvNotificationOngoing()    
{               
    m_flag &= ~VSRV_NOTIFICATION_FLAG_AUTO_CLOSE | VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_TERMINATE;
}
    

VsrvNotificationOngoing::VsrvNotificationOngoing(VsrvNGroup* group, VsrvNotificationId id) :   
    VsrvNotification(group, id)
{   
    m_flag &= ~VSRV_NOTIFICATION_FLAG_AUTO_CLOSE | VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_TERMINATE;

}

VsrvNotificationOngoing::VsrvNotificationOngoing(VsrvNGroupId gid, VsrvNotificationId id) :   
    VsrvNotification(gid, id)
{   
    m_flag &= ~VSRV_NOTIFICATION_FLAG_AUTO_CLOSE | VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_TERMINATE;
}    


/***************************************************************************** 
* Class VsrvNCell
*****************************************************************************/

VFX_IMPLEMENT_CLASS("VsrvNCell", VsrvNCell, VfxFrame);

    
VsrvNCell::VsrvNCell() : m_noti(NULL)
{       
}

void VsrvNCell::setNotification(VsrvNotificationCustom* noti)
{
    ASSERT(noti);
    m_noti = noti;
}

VsrvNotificationCustom* VsrvNCell::getNotification()
{
    return m_noti;
}

/***************************************************************************** 
* Class VsrvNotificationCustom
*****************************************************************************/
    
VsrvNotificationCustom::VsrvNotificationCustom() :
    m_category(VSRV_NOTIFICAITON_CUSTOM_CATEGORY_ONGOING),
    m_height(VSRV_NCELL_DEFAULT_HEIGHT)
{       
}
    

VsrvNotificationCustom::VsrvNotificationCustom(VsrvNGroup* group, VsrvNotificationId id) :   
    VsrvNotification(group, id),
    m_category(VSRV_NOTIFICAITON_CUSTOM_CATEGORY_ONGOING),
    m_height(VSRV_NCELL_DEFAULT_HEIGHT)    
{   
}

VsrvNotificationCustom::VsrvNotificationCustom(VsrvNGroupId gid, VsrvNotificationId id) :   
    VsrvNotification(gid, id),
    m_category(VSRV_NOTIFICAITON_CUSTOM_CATEGORY_ONGOING),
    m_height(VSRV_NCELL_DEFAULT_HEIGHT)
{   
}    

void VsrvNotificationCustom::setCategory(VsrvNotificationCustomCategory category)
{
    m_category = category;
    setIsStable(VFX_FALSE);
}

void VsrvNotificationCustom::onInit()
{
    VsrvNotification::onInit();

    m_infos.init(m_parentObj);
}

void VsrvNotificationCustom::processIntent(VsrvNIntent intent)
{
    VsrvNotification::processIntent(intent);
    
    VfxList <CustomViewInfo>::It it;
      
    for (it = m_infos.begin(); !it.isNull() ; ++it)
    {
        CustomViewInfo &info = *it;
        m_signalIntent.emit(this, intent, info.viewData, info.viewDataSize);                        
    }    

}


void VsrvNotificationCustom::onDeinit()
{     
    VfxList <CustomViewInfo>::It it;
      
    for (it = m_infos.begin(); !it.isNull() ; ++it)
    {   
        CustomViewInfo &info = *it;
        if (info.viewData)
        {
            VFX_FREE_MEM(info.viewData);
            info.viewData = NULL;
            info.viewDataSize = 0;
        }  
    
    }    

    VsrvNotification::onDeinit();
    
}

    

VfxBool VsrvNotificationCustom::addCustomViewInfo(VfxClassInfo* classInfo, VsrvNViewerType viewers, void* viewData, VfxU32 viewDataSize)
{
    VFX_ASSERT((viewData == NULL && viewDataSize == 0) || (viewData != NULL && viewDataSize !=0 ));
    VFX_ASSERT(viewDataSize < NOTI_MEM_POOL_MARGIN_B);


    VfxList <CustomViewInfo>::It it;
      
    for (it = m_infos.begin(); !it.isNull() ; ++it)
    {   
        CustomViewInfo &info = *it;
        if (info.viewers == viewers)
        {  
           info.classInfo = classInfo; 

           if (info.viewData)
           {
               VFX_FREE_MEM(info.viewData);
               info.viewData = NULL;
               info.viewDataSize = 0;
           }
           
           if (viewData != NULL)
           {
               info.viewDataSize = viewDataSize;
               VFX_ALLOC_MEM(info.viewData, info.viewDataSize, m_parentObj);            
               memcpy(info.viewData, viewData, info.viewDataSize);
           }
           setIsStable(VFX_FALSE);
           return VFX_TRUE;
        }
    }
    
    CustomViewInfo information;
    information.classInfo = classInfo;
    information.viewers = viewers;
    information.viewData = NULL;
    information.viewDataSize = 0;

    if (viewData != NULL)
    {        
        information.viewDataSize = viewDataSize;
        VFX_ALLOC_MEM(information.viewData, information.viewDataSize, m_parentObj);            
        memcpy(information.viewData, viewData, information.viewDataSize);    
    }     

    m_infos.pushBack(information);  
    setIsStable(VFX_FALSE);
    return VFX_TRUE;

}        
    


VfxBool VsrvNotificationCustom::removeCustomViewInfo(VsrvNViewerType viewers)
{
    VfxList <CustomViewInfo>::It it;
      
    for (it = m_infos.begin(); !it.isNull() ; ++it)
    {   
        CustomViewInfo &info = *it;
        if (info.viewers == viewers)
        {             
            if (info.viewData)
            {
                VFX_FREE_MEM(info.viewData);
                info.viewData = NULL;
                info.viewDataSize = 0;
            }
            break;
        }
    }

    if (!it.isNull())
    {
        m_infos.erase(it);
        setIsStable(VFX_FALSE);           
        return VFX_TRUE;      
    }             
    return VFX_FALSE;            

}        


    

VsrvNCell* VsrvNotificationCustom::createView(VsrvNViewerType viewer, VfxObject* objParent)
{
    VfxList <CustomViewInfo>::It it;      
    for (it = m_infos.begin(); !it.isNull() ; ++it)
    { 
        CustomViewInfo &info = *it;
        if(info.viewers & VSRV_NVIEWER_TYPE_GENERAL || info.viewers & viewer)
        {
            VfxObject *obj = info.classInfo->createObject(objParent);
            VsrvNCell *cell = VFX_OBJ_DYNAMIC_CAST(obj, VsrvNCell);
            
            if (cell)
            {
                cell->setNotification(this);
                m_signalIntent.connect(cell, &VsrvNCell::onProcessIntent);
                cell->onCreateView(info.viewData, info.viewDataSize);
                return cell;
            }
            else
            {
                VFX_OBJ_CLOSE(obj);
            }        
        }
        
    }
    
   
    return NULL;    
}




/***************************************************************************** 
* Class VsrvNGroup
*****************************************************************************/

VsrvNGroup::VsrvNGroup() :   
    m_id(VSRV_NGROUP_INVALID_ID), 
    m_parentGroup(NULL),
    m_isOnDeinit(VFX_FALSE)
{
    m_parentObj = NULL;
}
    

VsrvNGroup::VsrvNGroup(VsrvNGroupId id) :   
    m_id(id),
    m_parentGroup(NULL),
    m_isOnDeinit(VFX_FALSE)
{
    m_parentObj = NULL;
}

void VsrvNGroup::_init(VfxObject* objParent)
{ 
    m_parentObj = objParent;    
    onInit();
}

void VsrvNGroup::_deinit()
{
    onDeinit();    
    delete this;
}


void VsrvNGroup::onInit()
{
    m_notis.init(m_parentObj); 
    m_timeStamp.setCurrentTime();    
}


void VsrvNGroup::onDeinit()
{ 

    VfxList <VsrvNotification*> closeList;
    closeList.init(m_parentObj);

    VfxList <VsrvNotification*>::It it;
    for (it = m_notis.begin(); !it.isNull() ; ++it)
    {
        VsrvNotification *n = *it;
        closeList.pushBack(n);
    }           
    for (it = closeList.begin(); !it.isNull() ; ++it)
    {
        VsrvNotification *n = *it;
        VSRV_NOTIFICATION_CLOSE(n);        
    }
}



VfxBool VsrvNGroup::addNotification(VsrvNotification* noti)    
{
    VsrvNGroup* group = noti->getGroup();
    if (group)
    {
        group->removeNotification(noti);
    }    

    VfxList <VsrvNotification*>::It it;
    for (it = m_notis.begin(); !it.isNull() ; ++it)
    {
        VsrvNotification *n = *it;
        VfxDateTime::CompareEnum result = noti->getTimeStamp().compareWith(n->getTimeStamp());
        if (result != VfxDateTime::LESS)
        {
            break;             
        } 
    }

    VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
    vfx_sys_mem_pool_status_struct current;
    nm->m_context->statistics(current);

    if (it.isNull())
    {
        m_notis.pushBack(noti);
    }
    else
    {
        m_notis.insert(it, noti);
    }

    m_timeStamp = (*m_notis.begin())->getTimeStamp();              

    return VFX_TRUE;
    
}
VfxBool VsrvNGroup::removeNotification(VsrvNotification* noti)
{
    VfxList <VsrvNotification*>::It pos = m_notis.find(noti);
        
    if(!pos.isNull())
    {
        m_notis.erase(pos);
        return VFX_TRUE;
    }    
    
    return VFX_FALSE;
}

VfxBool VsrvNGroup::removeNotification(VsrvNotificationId id)
{
    VsrvNotification noti(this, id);
    VfxList <VsrvNotification*>::It pos = m_notis.find(&noti, vfx_nmanager_noti_equal);
    
    if(!pos.isNull())
    {
        m_notis.erase(pos);
        return VFX_TRUE;
    }   
    return VFX_FALSE;
}
VsrvNotification* VsrvNGroup::queryNotification(VsrvNotificationId id)
{
    VsrvNotification noti(this, id);
    VfxList <VsrvNotification*>::It pos = m_notis.find(&noti, vfx_nmanager_noti_equal);
    
    if(!pos.isNull())
    {        
        return *pos;
    }  
    return NULL;    
}


#endif /* __MMI_NCENTER_SUPPORT__ */
