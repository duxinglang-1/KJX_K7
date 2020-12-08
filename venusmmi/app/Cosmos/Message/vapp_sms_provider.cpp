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
 *  vapp_sms_provider.cpp
 *
 * Project:
 * --------
 *  Venus
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
#include "vapp_sms_provider.h"
#include "mmi_rp_app_vapp_sms_def.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappSmsProvider", VappSmsProvider, VfxObject);

VappSmsProvider::VappSmsProvider() : 
				m_msgID(SRV_SMS_INVALID_MSG_ID),
				m_changeReadFlag(VFX_FALSE),
				m_content(NULL),
				m_contentSize(0),
				m_isDataValid(VFX_FALSE),
				m_isUpdate(VFX_FALSE),
				m_isReading(VFX_FALSE),
				m_needReadAgain(VFX_FALSE),
				m_currHandle(SRV_SMS_INVALID_HANDLE),
				m_msgData(NULL)							
{
}


void VappSmsProvider::read(VfxU16 msgID, VfxBool changeReadFlag)
{
	m_msgID = msgID;
	m_changeReadFlag = changeReadFlag;

    m_isMsgValid = (srv_sms_is_msg_exist(m_msgID)? VFX_TRUE: VFX_FALSE);

	update();
}

void VappSmsProvider::update(void)
{
    if (m_isMsgValid)
	{
		if (m_isReading)
		{
			m_needReadAgain = VFX_TRUE;
			return;
		}
		m_isReading = VFX_TRUE;

		VFX_FREE_MEM(m_content);
		VFX_FREE_MEM(m_msgData);

	    m_isDataValid = VFX_FALSE;

		VFX_ALLOC_MEM(m_content, MAX_CONTENT_LEN, this);
		VFX_ALLOC_MEM(m_msgData, sizeof(srv_sms_msg_data_struct), this);
	    m_msgData->content_buff = (S8*)m_content;
	    m_msgData->para_flag = (srv_sms_para_enum)(SRV_SMS_PARA_CONTENT_BUFF | SRV_SMS_PARA_ORI_8BIT_DATA);
	    m_msgData->content_buff_size = MAX_CONTENT_LEN;
	    m_currHandle = srv_sms_read_msg(
				            m_msgID,
				            (MMI_BOOL)m_changeReadFlag,
				            m_msgData,
				            &VappSmsProvider::onReadMsgDone,
				            getObjHandle());
	}
	else
	{
		m_signalReadDone.emit(VFX_FALSE);
	}
}

VfxBool VappSmsProvider::isDataValid(void)
{
	return m_isDataValid;
}

VfxU16 VappSmsProvider::getMsgID(void)
{
	return m_msgID;
}

void VappSmsProvider::setMsgID(VfxU16 msgID)
{
	m_msgID = msgID;
}

VfxWChar* VappSmsProvider::getContent(void)
{
	return m_content;
}

VfxU32 VappSmsProvider::getContentSize(void)
{
	return m_contentSize;
}

void VappSmsProvider::getTimeStatmp(VfxDateTime *timestatmp)
{
	MYTIME time;

	srv_sms_get_msg_timestamp(m_msgID, &time);

	timestatmp->setDate(time.nYear, time.nMonth, time.nDay);
	timestatmp->setTime(time.nHour, time.nMin, time.nSec);
}

srv_sms_sim_enum VappSmsProvider::getSimID(void)
{
	return srv_sms_get_msg_sim_id(m_msgID);
}

srv_sms_status_enum VappSmsProvider::getStatus(void)
{
	return srv_sms_get_msg_status(m_msgID);
}

srv_sms_storage_enum VappSmsProvider::getStorageType(void)
{
	return srv_sms_get_msg_storage_type(m_msgID);
}

srv_sms_box_enum VappSmsProvider::getBoxType(void)
{
	srv_sms_status_enum status;
	srv_sms_storage_enum storageType;
	srv_sms_folder_enum folderId;

	status = srv_sms_get_msg_status(m_msgID);
	storageType = srv_sms_get_msg_storage_type(m_msgID);
	folderId = srv_sms_get_msg_folder_id(m_msgID);

	return srv_sms_get_list_type(status, storageType, folderId);
}

VfxU16 VappSmsProvider::getPID(void)
{
	return srv_sms_get_msg_pid(m_msgID);
}

#ifdef __MMI_SMS_PORT_MSG__ 
VfxU16 VappSmsProvider::getDestPort(void)
{
	return srv_sms_get_msg_port(m_msgID);
}
#endif
srv_sms_send_status_enum VappSmsProvider::getSendStatus(void)
{
	return srv_sms_get_unsent_msg_status(m_msgID);
}

srv_sms_folder_enum VappSmsProvider::getFolderID(void)
{
	return srv_sms_get_msg_folder_id(m_msgID);
}
#ifdef __MMI_SMS_PORT_MSG__ 

VfxBool VappSmsProvider::isPortRegMsg(void)
{
	VappSmsPortReg *portReg = VFX_OBJ_GET_INSTANCE(VappSmsPortReg);
	VfxU16 port = getDestPort();

	return portReg->findPort(port);
}
#endif
VfxBool VappSmsProvider::isNotSupportMsg(void)
{
	VfxBool result = VFX_FALSE;
	srv_sms_status_enum msgStatus;

	msgStatus = getStatus();

	if (msgStatus & SRV_SMS_STATUS_UNSUPPORTED)
	{
	#ifdef __MMI_SMS_PORT_MSG__ 
		result = (!isPortRegMsg());
	#else
		result = VFX_TRUE;
	#endif
	}

	return result;
}

VappSmsProvider& VappSmsProvider::operator = (const VappSmsProvider& rightProvider)
{
    m_msgID = rightProvider.m_msgID;
    m_changeReadFlag = rightProvider.m_changeReadFlag;
	m_isMsgValid = rightProvider.m_isMsgValid;
	m_isDataValid = rightProvider.m_isDataValid;
	m_currHandle = NULL;

	if (!m_isDataValid)
	{
		read(m_msgID, m_changeReadFlag);
	}
	else
	{
		if (m_content)
		{
			VFX_FREE_MEM(m_content);
			m_contentSize = 0;
		}

		if (rightProvider.m_content)
		{
			VfxU32 contentSize;

			m_contentSize = rightProvider.m_contentSize;
			contentSize = rightProvider.m_contentSize + sizeof(VfxWChar);

			VFX_ALLOC_MEM(m_content, contentSize, this);
			memcpy(m_content, rightProvider.m_content, contentSize);
		}
		else
		{
			m_content = NULL;
			m_contentSize = 0;
		}
	}

    return *this;
}

void VappSmsProvider::onInit(void)
{
    /* Super Class onInit */
    VfxObject::onInit();

    mmi_frm_cb_reg_event(EVT_ID_SRV_SMS_DEL_MSG, &VappSmsProvider::onMsgChanged, getObjHandle());
	mmi_frm_cb_reg_event(EVT_ID_SRV_SMS_UPDATE_MSG, &VappSmsProvider::onMsgChanged, getObjHandle());
	mmi_frm_cb_reg_event(EVT_ID_SRV_SMS_UPDATE_UNSENT_MSG_STATUS, &VappSmsProvider::onMsgChanged, getObjHandle());
}


void VappSmsProvider::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SMS_DEL_MSG, &VappSmsProvider::onMsgChanged, getObjHandle());
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SMS_UPDATE_MSG, &VappSmsProvider::onMsgChanged, getObjHandle());
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SMS_UPDATE_UNSENT_MSG_STATUS, &VappSmsProvider::onMsgChanged, getObjHandle());

	abortRead();

	VFX_FREE_MEM(m_content);
	VFX_FREE_MEM(m_msgData);

    VfxObject::onDeinit();
}

void VappSmsProvider::abortRead()
{
	if (m_currHandle != SRV_SMS_INVALID_HANDLE)
	{
		srv_sms_abort(m_currHandle, NULL, NULL);
	}
}

mmi_ret VappSmsProvider::onMsgChanged(mmi_event_struct *param)
{
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)param;
    VappSmsProvider *currProvider = (VappSmsProvider *)VfxObject::handleToObject((VfxObjHandle)param->user_data);
	if (currProvider == NULL)
		return MMI_RET_OK;
    VfxU16 currMsgID = currProvider->getMsgID();

    switch (param->evt_id)
    {
        case EVT_ID_SRV_SMS_DEL_MSG:
        {
            srv_sms_event_delete_struct *event_info;
            event_info = (srv_sms_event_delete_struct*)event_data->event_info;

            if (event_info->msg_id == currMsgID)
            {
                currProvider->m_isMsgValid = VFX_FALSE;
            	currProvider->m_signalMsgDeleted.emit();
            }
            break;
        }

        case EVT_ID_SRV_SMS_UPDATE_MSG:
        {
            srv_sms_event_update_struct *event_info;
            event_info = (srv_sms_event_update_struct*)event_data->event_info;

            if (event_info->msg_id == currMsgID)
            {
				currProvider->m_isUpdate = VFX_TRUE;
					currProvider->update();
				}
            break;
        }

		case EVT_ID_SRV_SMS_UPDATE_UNSENT_MSG_STATUS:
		{
    		srv_sms_event_update_unsent_msg_status_struct *event_info;

    		event_info = (srv_sms_event_update_unsent_msg_status_struct*)event_data->event_info;

            if (event_info->msg_id == currMsgID)
			{
        		currProvider->m_signalMsgChanged.emit();
			}
			break;
		}

        default:
        {
            VFX_ASSERT(0);
        }
    }

    return MMI_RET_OK;
}

void VappSmsProvider::onReadMsgDone(srv_sms_callback_struct *callbackData)
{
	VfxObjHandle objHandle = (VfxObjHandle)callbackData->user_data;
    VappSmsProvider *currProvider = (VappSmsProvider*)VfxObject::handleToObject(objHandle);

	if (currProvider)
	{
		srv_sms_read_msg_cb_struct *cbData = (srv_sms_read_msg_cb_struct*)callbackData->action_data;
		const VfxWChar *content = NULL;
		VfxWChar *tempContent = NULL;
		VfxU32 contentSize = 0;

    	//VFX_DEV_ASSERT(currProvider->isKindOf(VFX_OBJ_CLASS_INFO(VappSmsProvider)));
		if (currProvider->m_needReadAgain)
		{
			currProvider->m_isReading = VFX_FALSE;
			currProvider->m_needReadAgain = VFX_FALSE;
			currProvider->m_signalReadAgain.emit();
			return;
		}
		if (!callbackData->result)
		{
			currProvider->m_isReading = VFX_FALSE;
			if (callbackData->cause == SRV_SMS_CAUSE_MEM_INSUFFICIENT)
			{
				currProvider->m_signalReadAgain.emit();
			}
			else
			{
				currProvider->m_signalReadDone.emit(callbackData->result? VFX_TRUE: VFX_FALSE);
			}
		}

	    else
	    {
			if (currProvider->isNotSupportMsg())
			{
				content = vfxSysResGetStr(STR_ID_VAPP_SMS_NOT_SUPPORT);
				contentSize = vfx_sys_wcslen(content) * sizeof(VfxWChar);
			}
			else
			{
				srv_sms_msg_data_struct *msgData = cbData->msg_data;

				contentSize = msgData->content_size;
				content = (VfxWChar*)msgData->content_buff;
			}
	        currProvider->m_isDataValid = VFX_TRUE;

		VfxU32 allocSize = contentSize + sizeof(VfxWChar);

		VFX_ALLOC_MEM(tempContent, allocSize, currProvider);

        if ((contentSize > 0) && (content != NULL))
        {
    		memcpy(tempContent, content, contentSize);
        }

        memset(((VfxChar*)tempContent + contentSize), 0, sizeof(VfxWChar));

		VFX_FREE_MEM(currProvider->m_msgData);
		VFX_FREE_MEM(currProvider->m_content);

		currProvider->m_content = tempContent;
		currProvider->m_contentSize = contentSize;
		currProvider->m_currHandle = SRV_SMS_INVALID_HANDLE;
			currProvider->m_isReading = VFX_FALSE;
		if (currProvider->m_isUpdate)
		{
            	currProvider->m_signalMsgChanged.emit();
			}
			else
			{
				currProvider->m_signalReadDone.emit(callbackData->result? VFX_TRUE: VFX_FALSE);
			}
		}
		}
	}

#ifdef __MMI_SMS_PORT_MSG__ 

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappSmsPortReg);

VfxBool VappSmsPortReg::registerPort(
                VfxU16 port,
                VfxWString& appName,
                VfxImageSrc& appImage,
                VappSmsPortRegCallback callback,
                void* userData)
{
	VfxBool result = VFX_TRUE;

	if (m_total < MAX_PORT_REG_NUM)
	{
		m_portTable[m_total].m_port = port;
		m_portTable[m_total].m_appName = appName;
		m_portTable[m_total].m_appImage = appImage;
		m_portTable[m_total].m_callback = callback;
		m_portTable[m_total].m_userData = userData;
		m_total++;
	}
	else
	{
		result = VFX_FALSE;
	}

	return result;
}

void VappSmsPortReg::unregPort(VfxU16 port)
{
	VfxU16 i;

	for (i = 0; i < m_total; i++)
	{
		if (m_portTable[i].m_port == port)
		{
			break;
		}
	}

	if (i < m_total)
	{
		for (VfxU16 j = i; j < (m_total - 1); j++)
		{
			memcpy(&m_portTable[j], &m_portTable[j + 1], sizeof(VappSmsPortRegEntry));
		}

		m_portTable[m_total].m_port = 0;
		m_portTable[m_total].m_appName.setNull();
		m_portTable[m_total].m_appImage.setNull();
		m_portTable[m_total].m_callback = NULL;
		m_portTable[m_total].m_userData = NULL;
		m_total--;
	}
}

VfxBool VappSmsPortReg::dispatch(VfxU16 port, VfxChar* data, VfxU32 dataSize)
{
	VappSmsPortRegEntry *entry = getEntry(port);

	if (entry)
	{
		entry->m_callback(data, dataSize, entry->m_userData);	
		return VFX_TRUE;
	}
	else
	{
		return VFX_FALSE;
	}
}

VfxBool VappSmsPortReg::getAppInfo(VfxU16 port, VfxWString& appName, VfxImageSrc& appImage)
{
	VappSmsPortRegEntry *entry = getEntry(port);

	if (entry)
	{
		appName = entry->m_appName;
		appImage = entry->m_appImage;
		return VFX_TRUE;
	}
	else
	{
		return VFX_FALSE;
	}
}

VfxBool VappSmsPortReg::findPort(VfxU16 port)
{
	if (getEntry(port))
	{
		return VFX_TRUE;
	}
	else
	{
		return VFX_FALSE;
	}
}

VfxU16 VappSmsPortReg::getAppImageResId(VfxU16 port)
{
	VappSmsPortRegEntry *entry = getEntry(port);

	if (entry)
	{
		return (VfxU16)entry->m_appImage.getResId();
	}
	else
	{
		return 0;
	}
}

const VfxWChar* VappSmsPortReg::getAppName(VfxU16 port)
{
	VappSmsPortRegEntry *entry = getEntry(port);

	if (entry)
	{
		return entry->m_appName.getBuf();
	}
	else
	{
		return NULL;
	}
}

VappSmsPortRegEntry* VappSmsPortReg::getEntry(VfxU16 port)
{
	VappSmsPortRegEntry *entry = NULL;
	VfxU32 i;

	for (i = 0; i < m_total; i++)
	{
		if (m_portTable[i].m_port == port)
		{
			entry = &m_portTable[i];
			break;
		}
	}

	return entry;
}
#endif

