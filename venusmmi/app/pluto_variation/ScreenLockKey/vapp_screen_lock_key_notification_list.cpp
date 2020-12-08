/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_screen_lock_key_notification_list.cpp
 *
 * Project:
 * --------
 *  MAUI
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_SCREEN_LOCK_KEY__) && defined(__MMI_NCENTER_SUPPORT__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_include.h"
#include "vapp_screen_lock_key_def.h"
#include "vapp_screen_lock_key_notification_list.h"
#include "vapp_screen_lock_key_notification_cell.h"
#include "mmi_rp_app_venus_screen_lock_key_def.h"

#include "vfx_container.h"
#include "vsrv_ncenter.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "ScrlockerScreenLockKey.h"
#include "mmi_frm_scenario_gprot.h"

#if defined(__MMI_NSS_SUPPORT__)
#include "NotificationSettingSrvGprot.h"
#endif

#if defined(__MRE_AM__)
#include "AppMgrSrvGprot.h"
#include "MMIDataType.h"
#endif

#include "app_datetime.h"
#include "gdi_include.h"

#include "UcmSrvGprot.h"

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * VappScreenLockKeyNotificationList
 *****************************************************************************/

VfxBool VappScreenLockKeyNotificationList::m_isInCall = VFX_FALSE;
VfxBool VappScreenLockKeyNotificationList::m_shallTraverse = VFX_FALSE;
VfxDateTime VappScreenLockKeyNotificationList::m_createTime;


VappScreenLockKeyNotificationContex VappScreenLockKeyNotificationList::s_notiTbl[] = 
{
    {APP_CALLLOG, 		 VAPP_SCREEN_LOCK_KEY_NOTIFICATION_CALLLOG, NULL, VSRV_NSTATUS_END},
    {APP_UNIFIEDMESSAGE, VAPP_SCREEN_LOCK_KEY_NOTIFICATION_MSG, 	NULL, VSRV_NSTATUS_END},
#if defined(__MMI_EMAIL__)
    {APP_EMAIL, 		 VAPP_SCREEN_LOCK_KEY_NOTIFICATION_MAIL, 	NULL, VSRV_NSTATUS_END},
#endif
#if defined(__MMI_SNS_CENTER__)
    {APP_SNS, 			 VAPP_SCREEN_LOCK_KEY_NOTIFICATION_SNS, 	NULL, VSRV_NSTATUS_END},
#endif
#if defined(__MRE_AM__)
    {APP_AM, 			 VAPP_SCREEN_LOCK_KEY_NOTIFICATION_MRE, 	NULL, VSRV_NSTATUS_END},
#endif
    {0, 				 VAPP_SCREEN_LOCK_KEY_NOTIFICATION_TOTAL, 	NULL, VSRV_NSTATUS_END}
};


VFX_IMPLEMENT_CLASS("VappScreenLockKeyNotificationList", VappScreenLockKeyNotificationList, VcpVarHeightMenu);

VappScreenLockKeyNotificationList::VappScreenLockKeyNotificationList() : 
	VcpVarHeightMenu(LAYOUT_NORMAL),
	m_isChecked(VFX_FALSE)
{

}

void VappScreenLockKeyNotificationList::onInit()
{
	VcpVarHeightMenu::onInit();

	setBounds(VfxRect(0, 0, NOTI_LIST_WIDTH, 0));
	setDefaultHeight(NOTI_HEIGHT*MAX_CELL_NUM);

	if (vapp_screen_lock_key_is_first_enter())
	{
		m_isInCall = VFX_FALSE;
		m_shallTraverse = VFX_FALSE;
		
		//applib_time_struct current_time;
		//applib_dt_get_rtc_time(&current_time);
		//m_createTime.setDateTime(&current_time);

		m_createTime.setCurrentTime();
	}
	else if (m_isInCall)
	{
		m_isInCall = VFX_FALSE;
		checkNotifications();
	}
	else if (m_shallTraverse)
	{
		checkNotifications();
	}

	m_nCenter = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
}

void VappScreenLockKeyNotificationList::onDeinit()
{
	m_isInCall = srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0;

	m_shallTraverse = !mmi_frm_is_in_backward_scenario();
	
	VcpVarHeightMenu::onDeinit();
}

void VappScreenLockKeyNotificationList::checkNotifications()
{
#if 0
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
#else

	if (!m_shallTraverse)
		return;

	VfxList <VsrvNotification*> notiList;
	notiList.init(this);

	//sort the notifications order by time stamp	
	m_nCenter = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
	VfxList <VsrvNGroup*>::It itg = m_nCenter->getNGroups();
	
	for (; !itg.isNull(); ++itg)
	{
		//traverse all groups
		
		VsrvNGroup *group = (*itg);
		VfxS32 idx = getIndex(group->getId());
		
		if (idx != -1 && checkSettingByGroupId(group->getId()))
		{
			//traverse all notifications in group

			VfxList <VsrvNotification*>::It itn = group->getNotifications();
			
		    for (; !itn.isNull(); ++itn)
		    {
				VfxList <VsrvNotification*>::It itl = notiList.begin();
				VsrvNotification *noti = (*itn);

				if (checkAvailable(noti) && noti->getTimeStamp().compareWith(m_createTime) != VfxDateTime::LESS)
				{
					for (; !itl.isNull(); ++itl)
	                {
	                	VsrvNotification *noti_in_list = (*itl);
	                    if (noti->getTimeStamp().compareWith(noti_in_list->getTimeStamp()) != VfxDateTime::LESS)
	                    {
	                        break;             
	                    }                         
	                }

					notiList.insert(itl, noti);        
				}
		    }			
		}
	}

	//show the notifications in the notiList
	
	VfxList <VsrvNotification*>::It itl = notiList.begin();
	for (; !itl.isNull(); ++itl)
	{
		VsrvNotification *noti = (*itl);
		VfxS32 idx = getIndex(noti->getGroupId());
    	s_notiTbl[idx].noti = noti;

		VappScreenLockKeyNotificationContex *ptr = &s_notiTbl[idx];
		VappScreenLockKeyNotificationContex **pptr = &ptr;

		addItem((VfxId)noti, NOTI_HEIGHT, pptr, sizeof(pptr));
	}
#endif
}

VappScreenLockKeyNotificationList::ActionEnum VappScreenLockKeyNotificationList::onNotify(VsrvNotification * notify,VsrvNStatusType status)
{
	VappScreenLockKeyNotificationList::ActionEnum ret = UNSUPPORT;

	VfxS32 idx = getIndex(notify->getGroupId());

	VAPP_LOCK_LOG((TRC_VAPP_SCREEN_LOCK_KEY_PN_SUPPORT_IDX, idx, status));

	if (idx != -1 && checkAvailable(notify) && checkSettingByGroupId(notify->getGroupId()))
	{
		if (!m_shallTraverse)
			m_shallTraverse = VFX_TRUE;
	
		s_notiTbl[idx].noti = notify;
		s_notiTbl[idx].status = status;

		VappScreenLockKeyNotificationContex *ptr = &s_notiTbl[idx];
		VappScreenLockKeyNotificationContex **pptr = &ptr;
	
		switch (status)
		{
			case VSRV_NSTATUS_CREATE:
			case VSRV_NSTATUS_UPDATE:
			#if 1
				if (getCellCount() == 0)
				{
					addItem((VfxId)notify, NOTI_HEIGHT, pptr, sizeof(pptr));
					ret = ADD;
				}					
				else if (getItemIndex((VfxId)notify) == -1)
				{
					VfxS32 idx = 0;
					VfxS32 count = getCellCount();
					
					for (; idx < count; idx++)
					{
						VsrvNotification *noti_in_list =  (VsrvNotification*)getItemId(idx);
						if (notify->getTimeStamp().compareWith(noti_in_list->getTimeStamp()) != VfxDateTime::LESS) 
						{
							break;
						}
					}
					
					insertItem((VfxId)notify, NOTI_HEIGHT, idx, pptr, sizeof(pptr));
					
					if (idx == 0)
					{
						updateItem((VfxS32)1);
					}
					
					ret = ADD;
				}
				else
				{
					VfxS32 idx = getItemIndex((VfxId)notify);
					if (idx == 0)
					{
						updateItem((VfxId)notify);
					}
					else
					{
						VsrvNotification *noti_in_list =  (VsrvNotification*)getItemId(0);
						if (notify->getTimeStamp().compareWith(noti_in_list->getTimeStamp()) != VfxDateTime::LESS) 
						{
							removeItem((VfxId)notify);
							insertItem((VfxId)notify, NOTI_HEIGHT, 0, pptr, sizeof(pptr));
							updateItem((VfxS32)1);
						}
						else
						{
							updateItem((VfxId)notify);
						}
					}					
					ret = UPDATE;
				}
			#else
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
				break;

			case VSRV_NSTATUS_CLOSE:
				VfxBool update = getItemIndex((VfxId)notify) == 0 && getCellCount() > 1;
                removeItem((VfxId)notify);
				if (update)
				{
					updateItem((VfxS32)0);
				}
				ret = CLOSE;
				break;
		}
		
	}

	return ret;
}

/*****************************************************************************
 * override: VcpVarHeightMenu
 *****************************************************************************/

VfxFrame* VappScreenLockKeyNotificationList::createCell(VfxS32 group, VfxS32 pos)
{
	VAPP_LOCK_LOG((TRC_VAPP_SCREEN_LOCK_KEY_PN_CREATE, group, pos));
	
	VappScreenLockKeyNotificationCell *cell;
	VFX_OBJ_CREATE_EX(cell, VappScreenLockKeyNotificationCell, this, (VcpMenuPos(group, pos)));
	cell->setCreateTime(m_createTime);

	VappScreenLockKeyNotificationContex** pptr = (VappScreenLockKeyNotificationContex**)m_items[pos].m_userData;
	
 
    switch((*pptr)->id)
    {   
    	case VAPP_SCREEN_LOCK_KEY_NOTIFICATION_MSG:
			cell->setIcon(VfxImageSrc(IMG_ID_VAPP_SCRLOCK_PN_MSG));
			break;
			
    	case VAPP_SCREEN_LOCK_KEY_NOTIFICATION_CALLLOG:
			cell->setIcon(VfxImageSrc(IMG_ID_VAPP_SCRLOCK_PN_CALL));
			break;
			
	#if defined(__MMI_EMAIL__)
	    case VAPP_SCREEN_LOCK_KEY_NOTIFICATION_MAIL:
			cell->setIcon(VfxImageSrc(IMG_ID_VAPP_SCRLOCK_PN_MAIL));
			break;
	#endif
	#if defined(__MMI_SNS_CENTER__)
	    case VAPP_SCREEN_LOCK_KEY_NOTIFICATION_SNS:
			cell->setIcon(VfxImageSrc(IMG_ID_VAPP_SCRLOCK_PN_SNS));
			break;
	#endif
	#if defined(__MRE_AM__)
	    case VAPP_SCREEN_LOCK_KEY_NOTIFICATION_MRE:
			cell->setIcon(VfxImageSrc(IMG_ID_VAPP_SCRLOCK_PN_MRE));
			break;
	#endif			
			
		default:
			break;
    }

	cell->layout(0);
	cell->setNotify((VsrvNotification*)m_items[pos].m_id);
	cell->checkNotifications();
	cell->sendToBack();

	return cell;
}

void VappScreenLockKeyNotificationList::onCloseCell(VfxS32 group,VfxS32 pos,VfxFrame * cellFrame)
{
	VFX_OBJ_CLOSE(cellFrame);
}

/*****************************************************************************
 * NCenter Data
 *****************************************************************************/

VfxS32 VappScreenLockKeyNotificationList::getIndex(VsrvNGroupId id)
{
#if defined(__MRE_AM__)
	mmi_app_package_name_struct app_name;
	srv_appmgr_get_app_package_name_by_id(id, app_name);
	srv_appmgr_app_package_type_enum app_type = srv_appmgr_get_app_package_type(app_name);
	if (app_type == SRV_APPMGR_MRE_APP_PACKAGE_TYPE)
	{
		return VAPP_SCREEN_LOCK_KEY_NOTIFICATION_MRE;
	}
	else
#endif
	{
		return getIndexByGroupId(id);
	}
}

VfxS32 VappScreenLockKeyNotificationList::getIndexByGroupId(VsrvNGroupId id)
{
	for (VfxS32 i = 0; i < VAPP_SCREEN_LOCK_KEY_NOTIFICATION_TOTAL; i++)
	{
		if (id == s_notiTbl[i].app_id)
		{
			return i;
		}
	}

	return -1;
}

VfxBool VappScreenLockKeyNotificationList::checkAvailable(VsrvNotification * notify)
{
	return 	notify->getIsStable() && 
			notify->getType() == VSRV_NOTIFICATION_TYPE_EVENT;
}

VfxBool VappScreenLockKeyNotificationList::checkSettingByGroupId(VsrvNGroupId id)
{
#if defined(__MMI_NSS_SUPPORT__)
	VfxU16 setting;
	mmi_srv_nss_get_setting(id, NSS_SETTING_LOCK_SCRN, &setting);
	return (setting == SETTING_ON);
#else
	return VFX_TRUE;
#endif
}


#endif
