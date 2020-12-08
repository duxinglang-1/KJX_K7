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
 *   vapp_bt_page.cpp
 *
 * Project:
 * --------
 *   SLIM
 *
 * Description:
 * ------------
 *   Define base class of page for vapp_bt. 
 *
 * Author:
 * -------
 * -------
 *
*****************************************************************************
*
*****************************************************************************
*============================================================================
*			 HISTORY
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/


/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vapp_bt_page.h"
#include "mmi_rp_vapp_bt_main_def.h" // for STR_ID_VAPP_BT_PAIRED_DEV_EMPTY
#include "vcp_status_icon_bar.h" // for VcpStatusIconBar
#include "BtAudioSrvGprot.h" // for srv_btaud_is_audio_device




/*****************************************************************************
 * Define
 *****************************************************************************/

/*****************************************************************************
 * Class XXX implementation
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappBTPageBase", VappBTPageBase, VfxPage);

/*---------------------------------------------------------------------------*
 * Function: initDevLis()
 * Description: init Dev list of page.
 *---------------------------------------------------------------------------*/
void VappBTPageBase::initDevLis()
{
	VFX_LOG_FUNC;
//local var:
	
//func implementation:
	VFX_OBJ_CREATE(m_btDevListMenu, VcpListMenu, this);
    m_btDevListMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT_EX2);
    m_btDevListMenu->setContentProvider(this);
    m_btDevListMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
    m_btDevListMenu->setSize(getSize());
    m_btDevListMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_btDevListMenu->m_signalItemTapped.connect(this, &VappBTPageBase::onHitDevItem);
	
}

/*---------------------------------------------------------------------------*
 * Function: onDeinit()
 * Description: virtual function from VfxPage. Be called when deinitialization.
 *---------------------------------------------------------------------------*/
void VappBTPageBase::onDeinit()
{
    VFX_LOG_FUNC;
//local var:
	
//func implementation:
	if(m_serviceHandle > 0)
	{
        srv_bt_cm_reset_notify(m_serviceHandle);
		m_serviceHandle = 0;
	}
	VfxPage::onDeinit();
}

/*---------------------------------------------------------------------------*
 * Function: getItemText()
 * Description: virtual functoin from IVcpListMenuContentProvider.
 *    @return: VFX_TURE is success
 *---------------------------------------------------------------------------*/
VfxBool VappBTPageBase::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType,VfxWString &text,VcpListMenuTextColorEnum &color)
{
	VFX_LOG_FUNC1("index = %d", index);
//local var:
		const srv_bt_cm_dev_struct *dev_p;
 		VfxWChar *buff;

//func implementation:
	dev_p = getDevInfoByIndex(index);
    buff = text.lockBuf(SRV_BT_CM_BD_NAME_UCS2_LEN);
    mmi_chset_utf8_to_ucs2_string(
        (kal_uint8 *)buff, 
        SRV_BT_CM_BD_NAME_UCS2_LEN, 
        (kal_uint8 *)(dev_p->name));
    text.unlockBuf();
	return VFX_TRUE;
}

/*---------------------------------------------------------------------------*
 * Function: getItemImage()
 * Description: give image of list items.
 *    @return: VFX_TURE is success
 *---------------------------------------------------------------------------*/
VfxBool VappBTPageBase::getItemImage(VfxU32 index,VcpListMenuFieldEnum fieldType,VfxImageSrc &image)
{
    VFX_LOG_FUNC;
//local var:
	srv_bt_cm_dev_struct* dev_info;

	VfxResId imageSrcId;

//func implementation:
	dev_info = (srv_bt_cm_dev_struct*)getDevInfoByIndex(index);
	imageSrcId = 0;

	if (fieldType == VCP_LIST_MENU_FIELD_ICON)
	{
		VfxU32 devCod = dev_info->cod;
		if (devCod & SRV_BT_COMPUTER_MAJOR_DEVICE_MASK)
		{
			imageSrcId = IMG_ID_VAPP_BT_DEV_LAP;
		}
		else if (devCod & SRV_BT_PRINTER_IMAGING_MINOR_DEVICE_CLASS)
		{
			imageSrcId = IMG_ID_VAPP_BT_DEV_PRINTER;
		}
		else if (devCod & SRV_BT_PHONE_MAJOR_DEVICE_MASK)
		{
			imageSrcId = IMG_ID_VAPP_BT_DEV_MOB;
		}
		else if (devCod & SRV_BT_AUDIO_MAJOR_SERVICE_MASK)
        {
            imageSrcId = IMG_ID_VAPP_BT_DEV_AUDIO;
		}
		else
		{
			imageSrcId = IMG_ID_VAPP_BT_DEV_OTHER;
		}
		image.setResId(imageSrcId);
	}

	if (fieldType == VCP_LIST_MENU_FIELD_ICON_EXTRA1)
	{
		if (srv_bt_cm_is_dev_conn_active( &(dev_info->bd_addr)))
		{
			image.setResId(IMG_ID_VAPP_BT_DEV_CONNECTED);
		}  
	}

	return VFX_TRUE;	
}

/*---------------------------------------------------------------------------*
 * Function: getCount()
 * Description: the count of dev list.
 *    @return: return the dev list count.
 *---------------------------------------------------------------------------*/
VfxU32 VappBTPageBase::getCount() const
{
	VFX_LOG_FUNC1("return: %d", srv_bt_cm_get_dev_num(m_devType));
//local var:

//func implementation:
	return srv_bt_cm_get_dev_num(m_devType);
}

/*---------------------------------------------------------------------------*
 * Function: onHitDevItem()
 * Description: call back function, Be called when user hits a dev in the dev_list.
 *---------------------------------------------------------------------------*/
void VappBTPageBase::onHitDevItem(VcpListMenu* VcpListMenu, VfxU32 index)
{
	VFX_LOG_FUNC1("index = %d", index);
//local var:
	const srv_bt_cm_dev_struct* dev_Info;
//func implementation:
	dev_Info =  getDevInfoByIndex(index);
	onClickedDev(index, dev_Info);
}


/*---------------------------------------------------------------------------*
 * Function: getDevInfoByIndex()
 * Description: get the dev info by the index.
 *    @return: return the dev information.
 *---------------------------------------------------------------------------*/
const srv_bt_cm_dev_struct* VappBTPageBase::getDevInfoByIndex(VfxU32 index)
{
    VFX_LOG_FUNC;
//local var:
	
//func implementation:
	return srv_bt_cm_get_dev_info_by_index(index, m_devType);
}

/*---------------------------------------------------------------------------*
 * Function: popupBalloonMsg()
 * Description: popup a balloom message with aMsgSrtId.
 *---------------------------------------------------------------------------*/
void VappBTPageBase::popupBalloonMsg(VfxId aMsgSrtId)
{
    VFX_LOG_FUNC;
//local var:
	
//func implementation:
    mmi_frm_nmgr_balloon(
	    MMI_SCENARIO_ID_DEFAULT,
	    MMI_EVENT_INFO_BALLOON,
	    MMI_NMGR_BALLOON_TYPE_INFO,
		(WCHAR *)GetString(aMsgSrtId)
	    );
}

/*---------------------------------------------------------------------------*
 * Function: updateDevList()
 * Description: update the dev list.
 *---------------------------------------------------------------------------*/
void VappBTPageBase::updateDevList(srv_bt_cm_dev_type_enum aDevType)
{
	VFX_LOG_FUNC1("aDevType = %d", aDevType);
//local var:
	
//func implementation:
	m_devType = aDevType;
	m_btDevListMenu->resetAllItems();
}

/*---------------------------------------------------------------------------*
 * Function: setNotifyEvents()
 * Description: set notify events, and regist call back function to service.
 *    @return: VFX_TURE is success
 *---------------------------------------------------------------------------*/
VfxBool VappBTPageBase::setNotifyEvents(VfxU32 aEventMask)
{
//local var:
	
//func implementation:
	m_eventMask |= aEventMask;
	if(m_serviceHandle > 0)
	{
		//release old notifier.
        srv_bt_cm_reset_notify(m_serviceHandle);
	}
	m_serviceHandle = srv_bt_cm_set_notify(&VappBTPageBase::serviceEventsNotify, aEventMask, getObjHandle());
	return (m_serviceHandle > 0);
}


/*---------------------------------------------------------------------------*
 * Function: serviceEventsNotify()
 * Description: service event call back.
 *---------------------------------------------------------------------------*/
void VappBTPageBase::serviceEventsNotify(VfxU32 event, void* para)
{
    VFX_LOG_STATIC_FUNC;
//local var:
	VappBTPageBase* selfPage;
//func implementation:
	selfPage = (VappBTPageBase*)VfxObject::handleToObject(((srv_bt_cm_activate_struct*)para)->user_data);
	if(selfPage)
	{
		selfPage->handleBtEvents(event, para);
	}
}


/*****************************************************************************
 * Class VappBTSmallScr
 *****************************************************************************/
void VappBTSmallScr::onQueryRotateEx(VfxScreenRotateParam &param)
{
	VfxRenderer* renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
	param.rotateTo = renderer->getPreScreenRotateType();
}

void VappBTSmallScr::onRotate(const VfxScreenRotateParam & param)
{
    VfxAppScr::onRotate(param);
	if(m_statusBar)
	{
	    m_statusBar->setSize(getSize().width, m_statusBar->getSize().height);
	}
}
void VappBTSmallScr::onExit(VfxBool isBackward) //for issue fix
{
	if(m_haveStatusBar)
	{
		VFX_OBJ_CLOSE(m_statusBar);
	}
}

void VappBTSmallScr::onEntered(VfxBool isBackward)//for issue fix
{
	if(m_haveStatusBar)
	{
		addStatusBar();
	}
}

void VappBTSmallScr::addStatusBar()
{
	m_haveStatusBar = VFX_TRUE;
    VFX_OBJ_CREATE(m_statusBar, VcpStatusIconBar, this);
	m_statusBar->setSize(getSize().width, m_statusBar->getSize().height);
    m_statusBar->setAutoAnimate(VFX_TRUE);
    m_statusBar->setPos(0, 0);
}

//End of File
