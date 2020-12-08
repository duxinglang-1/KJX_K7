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
 *  vapp_bt_storage.cpp
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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

extern "C" {
#include "mmi_features.h"
#include "fs_errcode.h"
#include "fs_func.h"
#include "GlobalConstants.h"
#include "GlobalResDef.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "NotificationGprot.h"
#include "USBSrvGprot.h"
#include "FileMgrSrvGprot.h"
#include "mmi_rp_app_usbsrv_def.h"
}
#include "vfx_date_time.h" // for VfxDateTime
#include "mmi_rp_vapp_bt_main_def.h"
#include "vapp_ncenter_base_cell.h"
#include "vfx_date_time.h"
#include "vapp_usb_gprot.h"
#include "vapp_fmgr_cui_gprot.h"
#include "vapp_bt_main.h"
#include "vapp_bt_storage.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VbtStoragePage", VbtStoragePage, VfxPage);
//VFX_IMPLEMENT_CLASS("VbtReceiver", VbtReceiver, VfxObject);
//VFX_IMPLEMENT_CLASS("VbtRecvObject", VbtRecvObject, VfxObject);
VFX_IMPLEMENT_CLASS("VbtFmgrLauncher", VbtFmgrLauncher, VfxApp);

VbtStoragePage *VbtStoragePage::m_selfInstance;
VbtStorage VbtStorageSetting::m_storage = VbtStorage(0, 0);
VfxBool VbtRecvAgent::m_disable = VFX_FALSE;
VfxU32  VbtRecvAgent::m_instCount = 0;
mmi_id VbtFmgrLauncher::m_appID = 0;

VfxS32 VbtReceiver::m_localRecvCount = 0;
VfxS32 VbtReceiver::m_externalRecvCount = 0;


/***************************************************************************** 
 * Function
 *****************************************************************************/
void VbtStoragePage::onInit()
{
    VfxPage::onInit();
    
    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_BT_STORAGE));
    setTopBar(bar);

    VFX_OBJ_CREATE(m_list, VcpListMenu, this);

    m_list->setBounds(VfxRect(VfxPoint(0, 0), getSize()));

    m_list->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE);

    m_list->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK);
    m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);

    m_list->setContentProvider(this);

    m_list->m_signalItemTapped.connect(this, &VbtStoragePage::onListItemTabbed);
    
    m_driveList = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);

    m_selfInstance = this;
}

void VbtStoragePage::onDeinit()
{
    srv_fmgr_drivelist_destroy(m_driveList);
	

    m_selfInstance = NULL;
    VfxPage::onDeinit();
}

mmi_ret VbtStoragePage::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id) {
    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        
        m_list->resetAllItems(VFX_TRUE);
        break;

    case EVT_ID_USB_ENTER_MS_MODE:

        getMainScr()->popPage();

        break;

    default:
        break;
    }

    return MMI_RET_OK;
}


void VbtStoragePage::onListItemTabbed(VcpListMenu *list, VfxU32 index)
{
    if (index < (U32)srv_fmgr_drivelist_count(m_driveList))
    {
        VfxChar drive = (VfxChar)srv_fmgr_drivelist_get_drv_letter(m_driveList, index);
        if (drive != VbtStorageSetting::get().m_drive)
        {
            VbtStorageSetting::set(drive);
			VappBtSettingPage::storageCellUpdate();
        }

        getMainScr()->popPage();
    }
}

VfxBool VbtStoragePage::getItemText(
            VfxU32 index,
            VcpListMenuFieldEnum fieldType,
            VfxWString &text,
            VcpListMenuTextColorEnum &color)
{
    U8 drive = srv_fmgr_drivelist_get_drv_letter(m_driveList, index);

    text = VFX_WSTR_RES(srv_fmgr_drv_get_string(drive));

    return VFX_TRUE;
}

VfxBool VbtStoragePage::getItemIsDisabled(VfxU32 index) const
{
    U8 drive = srv_fmgr_drivelist_get_drv_letter(m_driveList, index);
    
    if (FS_GetDevStatus(drive, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
        return VFX_FALSE;

    return VFX_TRUE;
}

VcpListMenuItemStateEnum VbtStoragePage::getItemState(VfxU32 index) const
{
    VfxChar drive = (VfxChar)srv_fmgr_drivelist_get_drv_letter(m_driveList, index);

    if (drive == VbtStorageSetting::get().m_drive)
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;

    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

VfxU32 VbtStoragePage::getCount() const
{
    return srv_fmgr_drivelist_count(m_driveList);
}

mmi_ret VbtStoragePage::invokeProc(mmi_event_struct *evt)
{
    return onProc(evt);
}


extern "C"
mmi_ret vapp_bt_storage_change_hdlr(mmi_event_struct *event)
{
    VbtStoragePage *inst;
	inst = VbtStoragePage::getInstance();
    if (inst)
        inst->invokeProc(event);
	VappBtSettingPage::storageCellUpdate();

    return MMI_RET_OK;
}


void VbtStorageSetting::onInit(void * param)
{
    VfxChar drive;
    VfxS16 error;
    
    ReadValue(NVRAM_BT_STORAGE, &drive, DS_BYTE, &error);

    if (error != NVRAM_READ_SUCCESS ||
        !srv_fmgr_drv_is_valid((VfxU8)drive))
    {
        drive = SRV_FMGR_PUBLIC_DRV;
        WriteValue(NVRAM_BT_STORAGE, &drive, DS_BYTE, &error);
    }

    m_storage.m_drive = drive;
    m_storage.m_folder = NULL;
}

VbtStorage &VbtStorageSetting::get()
{
    return m_storage;
}

void VbtStorageSetting::set(VfxChar drive)
{
    VfxS16 error;

    WriteValue(NVRAM_BT_STORAGE, &m_storage.m_drive, DS_BYTE, &error);
    if (srv_fmgr_drv_is_valid((VfxU8)drive))
    {
        m_storage.m_drive = drive;
		WriteValue(NVRAM_BT_STORAGE, &drive, DS_BYTE, &error);
    }
}

void VbtRecvAgent::onInit(void *param)
{
    VfxS32 drvCount;
    SRV_FMGR_DRVLIST_HANDLE fh;
        
    fh = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE_ONLY);
    
    drvCount = srv_fmgr_drivelist_count(fh);
    
    for (VfxS32 i = 0; i < drvCount; i++)
    {
        VfxU8 drive = srv_fmgr_drivelist_get_drv_letter(fh, i);
        VfxWString path;
        path.format("%c:\\", drive);
        path += VFX_WSTR_MEM(TEMP_FOLDER);

        VfxS32 retval = FS_GetAttributes(path);
        if (retval >= FS_NO_ERROR && (retval & FS_ATTR_HIDDEN))
            FS_XDelete(path, FS_FILE_TYPE, NULL, 0);
    }

    srv_fmgr_drivelist_destroy(fh);
}

VbtReceiver *VbtRecvAgent::start(VfxObject *parent, VfxU32 option)
{
    VbtReceiver *recv;

    if (m_disable)
    {
        m_result = VBT_RECV_BLOCKED;
        return NULL;
    }

    VFX_OBJ_CREATE(recv, VbtReceiver, parent);

    VfxChar drive = m_storage.m_drive ? m_storage.m_drive : VbtStorageSetting::get().m_drive;

    {
        VbtRecvStorage storage(drive, TEMP_FOLDER, VFX_TRUE);
        if ((m_result = storage.create()) != VBT_RECV_SUCC)
        {
            VFX_OBJ_CLOSE(recv);
            return NULL;
        }
        VFX_OBJ_CREATE_EX(recv->m_tempObject, VbtRecvObject, recv, (storage));
        recv->m_tempObject->setName(NULL, VFX_TRUE, VFX_FALSE);
    }

    {
        VbtRecvStorage storage(drive, m_storage.m_folder);
        if ((m_result = storage.create()) != VBT_RECV_SUCC)
        {
            VFX_OBJ_CLOSE(recv);
            return NULL;
        }
        VFX_OBJ_CREATE_EX(recv->m_finalObject, VbtRecvObject, recv, (storage));
        recv->m_finalObject->setInfo(m_object);

        recv->m_finalObject->setName(m_object.m_name, VFX_FALSE, option & VBT_RECV_OPT_KEEP_NAME);
    }

    recv->m_option = option;
    
    recv->m_signalBegin.postEmit(recv, VBT_RECV_SUCC);

    vapp_bt_update_status(BT_NOTIFY_TRANS_BEGIN);
        
    m_instCount++;

    return recv;
}

void VbtRecvAgent::setObject(VfxWChar *name, VfxU32 size, VfxChar *type)
{
    m_object.m_name = name;
    m_object.m_size = size;
    m_object.m_type = type;
}

void VbtRecvAgent::setStorage(VfxChar drive, VfxWChar *folder)
{
    m_storage.m_drive = drive;
    if (folder)
        m_storage.m_folder = folder;
    else
        m_storage.m_folder = DEFAULT_FOLDER;
}

void VbtRecvAgent::enable()
{
    m_disable = VFX_FALSE;
}

void VbtRecvAgent::disable()
{
    m_disable = VFX_TRUE;
}

VfxBool VbtRecvAgent::isOngoing()
{
    return m_instCount ? VFX_TRUE:VFX_FALSE;
}

VfxBool VbtRecvAgent::isDisabled()
{
    return m_disable;
}

void VbtReceiver::abort(VfxS32 reason)
{
    m_tempObject->release();
    
    showResult(reason);

    m_signalEnd.postEmit(this, reason);
    
    VbtRecvAgent::m_instCount--;
    vapp_bt_update_status(BT_NOTIFY_TRANS_END);
    
    VfxObject* selfObj = this;
    VFX_OBJ_CLOSE(selfObj);
}

VbtRecvResult VbtReceiver::stop()
{
    VbtRecvResult reason = m_tempObject->finalize(*m_finalObject);

    if (reason == VBT_RECV_SUCC)
    {
        updateNCenter();
    }

    showResult(reason);
    
    m_signalEnd.postEmit(this, reason);

    VbtRecvAgent::m_instCount--;
    vapp_bt_update_status(BT_NOTIFY_TRANS_END);
    
    VfxObject* selfObj = this;
    VFX_OBJ_CLOSE(selfObj);

    return reason;
}

/*---------------------------------------------------------------------------*
 * Function: notifyEventCallback()
 * Description: NCenter2.0 cell clicked callback function.
 *---------------------------------------------------------------------------*/
void VbtReceiver::notifyEventCallback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize)
{
//local var:
	VfxU32 notifyId;
	mmi_id appGroupId;
//func implementation:
	notifyId = noti->getId();
	if(VSRV_NINTENT_TYPE_LAUNCH == intent.type)
	{
#ifdef __MMI_USB_SUPPORT__
		if (srv_usb_is_in_mass_storage_mode())
		{
			vapp_usb_unavailable_popup(0);
			return;
		}
		else
#endif        

		if (3 == notifyId && 
			!srv_fmgr_drv_is_accessible(SRV_FMGR_CARD_DRV))
		{
			mmi_frm_nmgr_balloon(
				MMI_SCENARIO_ID_DEFAULT,
				MMI_EVENT_INFO_BALLOON,
				MMI_NMGR_BALLOON_TYPE_INFO,
				(VfxWChar *)GetString(STR_GLOBAL_NO_MEMORY_CARD));
		}
		else
		{
			if (VbtFmgrLauncher::m_appID)
			{
				VfxAppLauncher::terminate(VbtFmgrLauncher::m_appID);
				VbtFmgrLauncher::m_appID = 0;
			}

			VfxBool appArg = (2 == notifyId);
			appGroupId = VfxAppLauncher::launch(
					VAPP_BT_FMGR_LAUNCHER, 
					VFX_OBJ_CLASS_INFO(VbtFmgrLauncher),
					GRP_ID_ROOT,
					&appArg, sizeof(VfxBool));
			if(GRP_ID_INVALID == appGroupId)
				return;
		}
	}
	if(VSRV_NINTENT_TYPE_LAUNCH == intent.type ||
		VSRV_NINTENT_TYPE_CLEAR == intent.type)
	{
		if(2 == notifyId)
		{
			m_localRecvCount = 0;
		}
		else
		{
			m_externalRecvCount = 0;
		}
		VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)VAPP_BT_SEND,notifyId);
	}
}

void VbtReceiver::updateNCenter()
{
	VfxU32 NotifyId;
	VfxS32 currentCount;
	VsrvNGroupSingleTitle *group;
	VfxWString subText;
	VfxResId strId;
	VsrvNotificationEvent* notify;
	
    if (m_option & VBT_RECV_OPT_BKGOUND)
        return;
	
    if (m_finalObject->getDrive() == (VfxChar)SRV_FMGR_PHONE_DRV)
    {
		NotifyId = 2;//Local recieve id.
		strId = STR_ID_VAPP_BT_SAVE_TO_PHONE;
		m_localRecvCount++;
		currentCount = m_localRecvCount;
    }
    else
    {
		NotifyId = 3;//external recieve id.
		m_externalRecvCount++;
		strId = STR_ID_VAPP_BT_SAVE_TO_CARD;
		currentCount = m_externalRecvCount;
    }
    
	VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle,(VAPP_BT_SEND));
	group->setTitle(VFX_WSTR_RES(STR_ID_VAPP_BLUETOOTH));
	VSRV_NOTIFICATION_CREATE_EX(notify, VsrvNotificationEvent,((VsrvNGroup*)group,NotifyId));
	notify->setIcon(VfxImageSrc(IMG_ID_VAPP_BT_NC_RECEIVE));	
	notify->setMainText(VFX_WSTR_RES(strId));
	notify->setAutoClose(VFX_FALSE);
	notify->setIntentCallback(&VbtReceiver::notifyEventCallback);

    subText.format("%d ", currentCount);
    if (currentCount > 1)
    { // 
		strId = STR_ID_VAPP_BT_FILES;
    }
    else
    {
		strId = STR_ID_VAPP_BT_FILE;
    }
    subText += VFX_WSTR_MEM((VfxWChar *)GetString(strId));
	VfxDateTime dataTime;
	dataTime.setCurrentTime();
	notify->setTimeStamp(dataTime);
	notify->setSubText(subText);
	notify->notify();
}

void VbtReceiver::showResult(VfxS32 result)
{
    if ((m_option & VBT_RECV_OPT_BKGOUND) &&
	        (result != VBT_RECV_MEMORY_FULL) &&
	        (result != VBT_RECV_MSDC_MISSED))
        return;
	
    MMI_STR_ID strID;

    switch (result) {
    case VBT_RECV_SUCC:
        strID = STR_ID_VAPP_BT_RECV_COMPLETE;
        break;

    case VBT_RECV_MEMORY_FULL:
        strID = STR_GLOBAL_NOT_ENOUGH_MEMORY;
        break;
        
    case VBT_RECV_MSDC_MISSED:
        strID = srv_fmgr_fs_error_get_string(FS_MSDC_NOT_PRESENT);
        break;

    case VBT_RECV_USER_ABORT:
        return;

    case VBT_RECV_FAIL:
    default:
        strID = STR_ID_VAPP_BT_RECV_FAIL;
        break;
    }
    
    mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_BLUETOOTH,
        MMI_NMGR_BALLOON_TYPE_INFO,
        (VfxWChar *)GetString(strID));
}

const VfxWChar *VbtReceiver::getPath()
{
    return m_tempObject->getPath();
}

VbtRecvStorage::VbtRecvStorage(VfxChar drive, const VfxWChar *folder, VfxBool hidden) :
    m_drive(drive),
    m_hidden(hidden),
    m_folder(VFX_WSTR_MEM(folder))
{
    if (m_drive)
    {
        m_path.format("%c:\\", m_drive);
        m_path += m_folder;
    }
}

VbtRecvResult VbtRecvStorage::create()
{
    if (!m_drive)
        return VBT_RECV_FAIL;

    if (m_path.isEmpty())
        return VBT_RECV_FAIL;
    
    VfxS32 retval = FS_GetAttributes(m_path);
    if (retval == FS_PATH_NOT_FOUND || 
        retval == FS_FILE_NOT_FOUND)
    {
        retval = FS_CreateDir(m_path);
        if (retval >= 0 && m_hidden)
            FS_SetAttributes(m_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
    }

    return (retval >= FS_NO_ERROR) ? VBT_RECV_SUCC : VBT_RECV_FAIL;
}

static const VfxWChar *getExtension(const VfxWChar *name);

VbtRecvObject::VbtRecvObject(const VbtRecvStorage &storage) :
        m_size(0),
        m_type(NULL),
        m_path(VFX_WSTR_MEM(NULL))
{
    m_storage = storage;
	VfxU32 len;

    const VfxWString &path = storage.getPath();
	len = path.getLength();
    if (len && path[len - 1] != '\\')
        m_storage.m_folder += VFX_WSTR_MEM((VfxWChar *)"\\");
    
    m_path = storage.getPath();
}


VbtRecvObject::~VbtRecvObject()
{
    VFX_FREE_MEM(m_type);
}

void VbtRecvObject::setInfo(const VbtObject &obj)
{
    if (obj.m_type)
    {
        VFX_ALLOC_MEM(m_type, vfx_sys_strlen(obj.m_type)+1, this);
        vfx_sys_strcpy(m_type, obj.m_type);
    }

    m_size = obj.m_size;
}

void VbtRecvObject::setName(const VfxWChar *name, VfxBool temp, VfxBool fixed)
{
    m_name = VbtObjectName(name, temp, fixed);
    m_path += VFX_WSTR_MEM(name);
}

VbtRecvResult VbtRecvObject::finalize(VbtRecvObject &newObj)
{
    VfxS32 retval;
    
    do {
        retval = FS_Rename(m_path, newObj.getPath());
    } while (retval == FS_FILE_EXISTS && newObj.update());

    if (retval == FS_FILE_EXISTS)
    {
        newObj.release();
        retval = FS_Rename(m_path, newObj.getPath());
    }

    if (retval < FS_NO_ERROR)
        release();

    return remapResult(retval);
}

VbtRecvResult VbtRecvObject::remapResult(VfxS32 retval)
{
    VbtRecvResult result;
    
    switch (retval) {
    case FS_NO_ERROR:
        result = VBT_RECV_SUCC;
        break;

    case FS_DISK_FULL:
        result = VBT_RECV_MEMORY_FULL;
        break;

    case FS_MSDC_MOUNT_ERROR:
    case FS_MSDC_READ_SECTOR_ERROR:
    case FS_MSDC_WRITE_SECTOR_ERROR:
    case FS_MSDC_DISCARD_SECTOR_ERROR:
    case FS_MSDC_PRESNET_NOT_READY:
    case FS_MSDC_NOT_PRESENT:
    case FS_MEDIA_CHANGED:
        result = VBT_RECV_MSDC_MISSED;
        break;

    default:
        result = VBT_RECV_FAIL;
        break;
    }

    return result;
}

void VbtRecvObject::release()
{
    FS_Delete(m_path);
}

VfxBool VbtRecvObject::update()
{
    if (!m_name.duplicate())
        return VFX_FALSE;

    VfxU32 pathLen = vfx_sys_wcslen(getPath());
    if (pathLen > MAX_PATH_LEN)
        m_name.truncate(pathLen - MAX_PATH_LEN);

    return VFX_TRUE;
}

const VfxWChar * VbtRecvObject::getPath()
{
    m_path = m_storage.getPath();
    m_path += VFX_WSTR_MEM(m_name);

    return m_path.getBuf();
}

VbtObjectName::VbtObjectName(const VfxWChar *name, VfxBool temp, VfxBool fixed) :
                m_name(VFX_WSTR_MEM(name)),
                m_fixed(fixed),
                m_truncate(VFX_FALSE),
                m_dupSeq(0)
{
    if (!valid(name))
    {
        if (temp)
            m_name.format("%08x.tmp", (U32)this);
        else
        {
            m_name = VFX_WSTR_MEM(DEFAULT_NAME);
            
            const VfxWChar *extension = getExtension(m_name);
            if (valid(extension))
                m_name += VFX_WSTR_MEM(extension);
        }
    }
}

void VbtObjectName::truncate(VfxU32 maxLength)
{
    VfxU32 nameLen = m_name.getLength();
    
    if (nameLen <= maxLength)
        return;
    
    VfxWChar *name = m_name.lockBuf(m_name.getLength()+1);
    
    const VfxWChar *extension = getExtension(name);
    VfxU32 extLen = vfx_sys_wcslen(extension);
    
    if (extension && 
        (extLen < MIN_EXT_LEN ||
         extLen < (nameLen - maxLength) + MIN_EXT_LEN))
    {
        VfxU32 moveLen = extLen < MIN_EXT_LEN ? (nameLen - maxLength) : (nameLen-maxLength+MIN_EXT_LEN)-extLen;
        VfxWChar *p = (VfxWChar *)extension;

        for (VfxU32 i = 0; *p && i != moveLen; i++,p++)
        {
            *(p-moveLen) = *p;
        }
    }
    
    name[maxLength] = '\0';

    m_name.unlockBuf();
}

VfxBool VbtObjectName::duplicate()
{
    if (m_dupSeq >= MAX_DUP_TIME || m_fixed)
        return VFX_FALSE;
    
    if (m_dupSeq)
    {
        VfxWChar prefix[8];
        kal_wsprintf(prefix, "Dup(%02d)", ++m_dupSeq);
        VfxWChar *name = m_name.lockBuf(m_name.getLength()+1);
        memcpy(name, prefix, (sizeof(prefix)-2));
        m_name.unlockBuf();
    }
    else
    {
        VfxWString prefix;
        VfxWString tempName = m_name;

        m_name = prefix.format("Dup(%02d)", ++m_dupSeq);
        m_name += tempName;
    }

    return VFX_TRUE;
}

VfxBool VbtObjectName::valid(const VfxWChar *name) const
{
    static const VfxChar lfn[] = ".+,;=[]";
    static const VfxChar sfn[] = " $%'-_@~`!(){}^#&0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    if (!name || vfx_sys_wcslen(name) == 0)
        return VFX_FALSE;

    for (VfxU32 i = 0; i != vfx_sys_wcslen(name); i++)
    {
        if (name[i] == 0xFFFF) // UCS2 convert failure mark
            return VFX_FALSE;

        if (name[i] < 0x80 && !strchr(lfn, (VfxChar)name[i]) && !strchr(sfn, (VfxChar)name[i]))
            return VFX_FALSE;
    }

    if (name[vfx_sys_wcslen(name)-1] == L'.')
        return VFX_FALSE;
    
    return VFX_TRUE;
}

static const VfxWChar *getExtension(const VfxWChar *name)
{
    if (!name || vfx_sys_wcslen(name) == 0)
        return NULL;
    
    for (VfxU32 i = 0; i != vfx_sys_wcslen(name); i++)
    {
        if (name[i] == L'.')
            return &name[i];
    }

    return NULL;
}

void VbtFmgrLauncher::onRun(void *args, VfxU32 argSize)
{
    VfxBool phone = *((VfxBool *)args);
    VfxWString path;

    if (phone)
        path.format("%c:\\", SRV_FMGR_PHONE_DRV);
    else
        path.format("%c:\\", SRV_FMGR_CARD_DRV);

    path += VFX_WSTR_MEM(DEFAULT_FOLDER);

    FMGR_FILTER filter;

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_ALL(&filter);
	mmi_id parentId;
	parentId = getGroupId();

    if (!vcui_folder_browser_launch(parentId, path, &filter))
        exit();

    m_appID = parentId;
}

mmi_ret VbtFmgrLauncher::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id) {
    case EVT_ID_VCUI_FOLDER_BROWSER_LAUNCH_QUIT:

        exit();
        m_appID = 0;

        return MMI_RET_OK;
    }
        
    return VfxApp::onProc(evt);
}

