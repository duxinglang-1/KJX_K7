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
 * Vapp_app_manager.cpp
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifdef __COSMOS_MMI_PACKAGE__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_app_manager.h"
#ifdef __J2ME__
#include "vapp_JavaAgencySrc.h"
#endif //__J2ME__
#include "vapp_usb_gprot.h"

extern "C"
{
#include "ucmgprot.h" 
#include "browser_api.h"
#include "Conversions.h"
#include "vcui_dialer_gprot.h"//for telephone call
#include "mmi_rp_vapp_app_manager_def.h"
#include "vfx_adp_device.h"
#include "SimCtrlSrvGprot.h"
#ifdef __J2ME__
#include "j2me_custom.h"
#endif
}

/***************************************************************************** 
 * Main Entry
 *****************************************************************************/
extern "C" MMI_ID vapp_app_manager_launch(void *param, U32 param_size)
{
#ifdef __MMI_COSMOS_APP_MANAGER__

    if (VappUSBOperator::isMassStorageMode())
    {
        VappUSBOperator::showPopup();
        return 0;
    }
    
    VappAMApp::m_mmiId = VfxAppLauncher::launch( 
        VAPP_APP_MANAGER, 
        VFX_OBJ_CLASS_INFO(VappAMApp),
        GRP_ID_ROOT);
    VAPP_AM_TRACE1(VAPP_AM_ENTER_AM,VappAMApp::m_mmiId);

    return VappAMApp::m_mmiId;
#else
    return 0;
#endif    
}

extern "C" void vapp_app_manager_entry(void)
{
    // this function is use to avoid build error -_-||
    vapp_app_manager_launch(NULL,0);
}

/***************************************************************************** 
 * Trace Functions
 *****************************************************************************/
#ifdef DEBUG_INFORMATION
    VfxChar g_traceBuff[VAPP_AM_TRACE_GLOBAL_BUFF_SIZE];
    
    char* Vapp_AM_UCS2_to_ASCII(const VfxWChar* strUCS2)
    {
        if (strUCS2)
        {
            mmi_chset_convert(CHSET_UCS2,CHSET_ASCII,(char*)strUCS2,(char*)g_traceBuff,VAPP_AM_TRACE_GLOBAL_BUFF_SIZE);
        }
        else
        {
            memset(g_traceBuff,0,VAPP_AM_TRACE_GLOBAL_BUFF_SIZE);
        }
        return g_traceBuff;
    }
    char* Vapp_AM_UTF8_to_ASCII(const VfxChar* strUTF8)
    {  
        if (strUTF8)
        {
            mmi_chset_convert(CHSET_UTF8,CHSET_ASCII,(char*)strUTF8,(char*)g_traceBuff,VAPP_AM_TRACE_GLOBAL_BUFF_SIZE);
        }
        else
        {
            memset(g_traceBuff,0,VAPP_AM_TRACE_GLOBAL_BUFF_SIZE);
        }
        return g_traceBuff;
    }
#endif //DEBUG_INFORMATION

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define AM_MALLOC(ptr, size) \
        do\
        {\
            VFX_ALLOC_MEM(ptr,size,VappAMApp::getMainScr());\
            VAPP_AM_TRACE2(VAPP_AM_AM_MALLOC,ptr,size);\
        }while(0)    
#define AM_FREE(ptr) \
        do\
        {\
            VAPP_AM_TRACE1(VAPP_AM_AM_FREE,ptr);\
            VFX_FREE_MEM(ptr);\
        }while(0)


/***************************************************************************** 
 * Class VappUSBOperator
 *****************************************************************************/
void VappUSBOperator::onInit()
{
    VfxObject::onInit();
#ifdef __MMI_USB_SUPPORT__    
    mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE,enterMassStorageModeCB,this);
#endif    
}

mmi_ret VappUSBOperator::enterMassStorageModeCB(mmi_event_struct *param)
{
    VAPP_AM_TRACE(VAPP_AM_ENTER_MASSSTORAGE);
    VappUSBOperator* pThis = (VappUSBOperator*)param->user_data;
    if (pThis->isValid())
    {
        pThis->m_enterMSSignal.emit();
    }
    return MMI_OK;
}

VfxBool VappUSBOperator::isMassStorageMode()
{
#ifdef _AM_TEST_
    if (g_UT.getUTFlag() & VAPP_AM_TEST_MASSSTORAGE)
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
#endif //_AM_TEST_

#ifdef __MMI_USB_SUPPORT__
    return srv_usb_is_in_mass_storage_mode();
#else //__MMI_USB_SUPPORT__
    return VFX_FALSE;
#endif //__MMI_USB_SUPPORT__
};

void VappUSBOperator::showPopup()
{
#ifdef __MMI_USB_SUPPORT__      
    vapp_usb_unavailable_popup(0);
#endif
}

void VappUSBOperator::onDeinit()
{
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE,enterMassStorageModeCB,this);
#endif    
    VfxObject::onDeinit();
}

/***************************************************************************** 
 * Class VappInfo
 *****************************************************************************/
VfxS32 VappInfo::getAppInfo()
{
    VFX_ASSERT(m_pAdapter != NULL);

    if (!m_bGetInfo)
    {
        VfxS32 ret = m_pAdapter->getAppInfo(this);
        if (VAPP_AM_OK == ret)
        {
            m_bGetInfo = VFX_TRUE;
        }
        return ret;
    }
    return VAPP_AM_OK;    
}

VfxS32 VappInfo::getAppDetailInfo()
{
    VFX_ASSERT(m_pAdapter != NULL);
 
    if (!m_bGetDetail)
    {
        VfxS32 ret = m_pAdapter->getDetailAppInfo(this);
        if (VAPP_AM_OK == ret)
        {
            m_bGetDetail = VFX_TRUE;
        }
        return ret;
    }
    return VAPP_AM_OK;
}

VfxBool VappInfo::isExist()
{
    VFX_ASSERT(m_pAdapter != NULL);
    return m_pAdapter->isExist(this);
}

VfxBool VappInfo::isUpdating()
{
    VFX_ASSERT(m_pAdapter != NULL);
    return m_pAdapter->isUpdating(this);
}

VfxBool VappInfo::isRunning()
{
    VFX_ASSERT(m_pAdapter != NULL);
    return m_pAdapter->isRunning(this);
}

void VappInfo::releaseAppDetailInfo()
{
    // if memory is in short supply, we should release some infos
    VappDetailInfo* pInfo;
    VappDetailInfo* pTmp = m_pDetailInfoList;
    while (pTmp)
    {
        pInfo = pTmp;
        pTmp = pInfo->m_next;
        VFX_OBJ_CLOSE(pInfo);
    }
    m_pDetailInfoList = NULL;
    m_bGetDetail = VFX_FALSE;
}

VfxS32 VappInfo::checkUpdate()
{
    VFX_ASSERT(m_pAdapter != NULL);
    return m_pAdapter->checkUpdate(this);
}

VfxS32 VappInfo::updateApp()
{
    VFX_ASSERT(m_pAdapter != NULL);
    return m_pAdapter->updateApp(this); 
}

VfxS32 VappInfo::uninstallApp()
{
    VFX_ASSERT(m_pAdapter != NULL);
    return m_pAdapter->uninstallApp(this);
}

void VappInfo::appendDetailInfo(VappDetailInfo* pDetailInfo)
{
    VappDetailInfo* pInfo = m_pDetailInfoList;
    if (!m_pDetailInfoList)
    {
        m_pDetailInfoList = pDetailInfo;
    }
    else
    {
        if (pInfo->m_type == pDetailInfo->m_type)
        {
            return;
        }
        while (pInfo->m_next != NULL)
        {
            pInfo = pInfo->m_next;
            if (pInfo->m_type == pDetailInfo->m_type)
            {
                return;
            }
        }
        pInfo->m_next = pDetailInfo;
    }
    
}

void VappInfo::fresh()
{
    m_bGetInfo = VFX_FALSE;
    m_bGetDetail = VFX_FALSE;
}

#ifdef _AM_APP_TEST_
/***************************************************************************** 
 * Class VappTestInfoAdapter
 *****************************************************************************/
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappTestInfoAdapter); 
VappTestInfoAdapter::VappTestInfoAdapter()
{
    
}

VfxS32 VappTestInfoAdapter::startSrv()
{
    return 0;
}

void VappTestInfoAdapter::stopSrv()
{

}
VfxS32 VappTestInfoAdapter::getAppList(VappInfoList* pInfoList)
{
    VappInfo* pAppInfo;
    VfxWString str;
    for (VfxS32 i = 0; i < AM_APP_TEST_NUM; i++)
    {
        VFX_OBJ_CREATE(pAppInfo, VappInfo, this);
        pAppInfo->m_type = VappInfo::VAPP_AM_APP_TYPE_WIGHET;
        pAppInfo->m_pAdapter = this;
        pAppInfo->m_wstrAppName = VFX_WSTR("test");
        str.format("%d",i);
        pAppInfo->m_wstrAppName += str;
        pAppInfo->m_wstrAppName += VFX_WSTR("abcdefghijklmnopqrstuvwxyz");
        pInfoList->append(pAppInfo);
    }
	return 0;
}

VfxU32   VappTestInfoAdapter::m_count = 0;

VfxS32 VappTestInfoAdapter::getAppInfo(VappInfo* pAppInfo)
{
    pAppInfo->m_storage = m_count%2;
    m_count++;
    return 0;
}

VfxS32  VappTestInfoAdapter::getDetailAppInfo(VappInfo* pAppInfo)
{
    VappDetailInfo* pDetailInfo;
    //version
    VFX_OBJ_CREATE(pDetailInfo, VappDetailInfo, pAppInfo);
    pDetailInfo->m_type = VappDetailInfo::VAPP_AM_DETAIL_INFO_VERSION;
    pDetailInfo->m_wstrContent = VFX_WSTR("test version");
    pAppInfo->appendDetailInfo(pDetailInfo);
    
    //size
    VFX_OBJ_CREATE(pDetailInfo, VappDetailInfo, pAppInfo);
    pDetailInfo->m_type = VappDetailInfo::VAPP_AM_DETAIL_INFO_SIZE;
    pDetailInfo->m_wstrContent = VFX_WSTR("test size");
    pAppInfo->appendDetailInfo(pDetailInfo);

    //size
    VFX_OBJ_CREATE(pDetailInfo, VappDetailInfo, pAppInfo);
    pDetailInfo->m_type = VappDetailInfo::VAPP_AM_DETAIL_INFO_WEBSITE;
    pDetailInfo->m_wstrContent = VFX_WSTR("www.sina.com.cn\\12312341234123412341234123412341234123412341234");
    pAppInfo->appendDetailInfo(pDetailInfo);

    VFX_OBJ_CREATE(pDetailInfo, VappDetailInfo, pAppInfo);
    pDetailInfo->m_type = VappDetailInfo::VAPP_AM_DETAIL_INFO_NUMBER;
    pDetailInfo->m_wstrContent = VFX_WSTR("1234567");
    pAppInfo->appendDetailInfo(pDetailInfo);

    //auhorized
    VFX_OBJ_CREATE(pDetailInfo, VappDetailInfo, pAppInfo);
    pDetailInfo->m_type = VappDetailInfo::VAPP_AM_DETAIL_INFO_AUTHORIZED;
    pDetailInfo->m_wstrContent.setEmpty();
    pAppInfo->appendDetailInfo(pDetailInfo);

    //INTRODUCE
    VFX_OBJ_CREATE(pDetailInfo, VappDetailInfo, pAppInfo);
    pDetailInfo->m_type = VappDetailInfo::VAPP_AM_DETAIL_INFO_INTRODUCE;
    pDetailInfo->m_wstrContent = VFX_WSTR("auhorizedKJ:KJ:LKSDJFKL:Jhpoiuhiupaoisdfuhjasdhf;lkajsd;flkjasdlkfjas;ldkfhlkasdjfaklsdjfasdf");
    pAppInfo->appendDetailInfo(pDetailInfo);
    return 0;
}

VfxBool VappTestInfoAdapter::isExist(VappInfo* pAppInfo)
{
    return VFX_TRUE;
}

VfxBool VappTestInfoAdapter::isUpdating(VappInfo* pAppInfo)
{
    return VFX_FALSE;
}

VfxBool VappTestInfoAdapter::isRunning(VappInfo* pAppInfo)
{
    return VFX_FALSE;
}

void VappTestInfoAdapter::getSettings(VappBaseSettings* pSettings)
{

}


VfxS32 VappTestInfoAdapter::setSettings(const VappBaseSettings* pSettings)
{
    return 0;
}

VfxS32 VappTestInfoAdapter::checkUpdate(VappInfo* pAppInfo)
{
    return 0;
}

VfxS32 VappTestInfoAdapter::updateApp(VappInfo* pAppInfo)
{
    return 0;
}

VfxS32 VappTestInfoAdapter::uninstallApp(VappInfo* pAppInfo)
{
//	m_uninstallSignal.emit(VAPP_AM_OK);
    return 0;
}

#endif //_AM_APP_TEST_

#ifdef __GADGET_SUPPORT__
/***************************************************************************** 
 * Class VappWidgetInfoAdapter
 *****************************************************************************/
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappWidgetInfoAdapter);

VappWidgetInfoAdapter::VappWidgetInfoAdapter()
:m_bStarted(VFX_FALSE),m_pMem(NULL)
{
    
}

void VappWidgetInfoAdapter::translateTime(VfxU32 time, VfxWString& wstrTime)
{
    applib_time_struct time_struct;
    VfxDateTime dataTime;
    
    applib_dt_utc_sec_2_mytime(time, &time_struct, (kal_bool)VFX_FALSE);

    dataTime.setDateTime(&time_struct);
    wstrTime = dataTime.getDateTimeString(VFX_DATE_TIME_DATE_MASK);
//    wstrTime.format("%d-%d-%d",time_struct.nYear,time_struct.nMonth,time_struct.nDay);
}

void VappWidgetInfoAdapter::startCallback(void* user_data)
{
    VAPP_AM_TRACE1(VAPP_AM_WGT_START_CB,user_data);
    
    VappWidgetInfoAdapter* pWIA = (VappWidgetInfoAdapter*)VfxObject::handleToObject(user_data);
    if (pWIA && pWIA->isValid())
    {        
        pWIA->m_bStarted = VFX_TRUE;
        pWIA->m_startedSignal.emit();
    }
}

void VappWidgetInfoAdapter::getAppInfoCallback(srv_wgtmgr_wgt_detail_struct *info, void* user_data)
{
    VAPP_AM_TRACE1(VAPP_AM_WGT_GET_INFO_CB,user_data);
//    VAPP_AM_TRACE1(VAPP_AM_WGT_GET_INFO_CB_COPYRIGH,info->wgt_copyright);
//    VAPP_AM_TRACE1(VAPP_AM_WGT_GET_INFO_CB_AUTHOR,info->wgt_author);
    
    VappInfo* pAppInfo = (VappInfo*)VfxObject::handleToObject(user_data);
    if (pAppInfo && pAppInfo->isValid())
    {
        VappDetailInfo* pDetailInfo;
        //copyright
        if (info->wgt_copyright[0] != 0)
        {
            VFX_OBJ_CREATE(pDetailInfo, VappDetailInfo, pAppInfo);
            pDetailInfo->m_type = VappDetailInfo::VAPP_AM_DETAIL_INFO_COPYRIGHT;
            pDetailInfo->m_wstrContent = VFX_WSTR_MEM(info->wgt_copyright);
            pAppInfo->appendDetailInfo(pDetailInfo);
        }
        //author
        if (info->wgt_author[0] != 0)
        {
            VFX_OBJ_CREATE(pDetailInfo, VappDetailInfo, pAppInfo);
            pDetailInfo->m_type = VappDetailInfo::VAPP_AM_DETAIL_INFO_AUTHOR;
            pDetailInfo->m_wstrContent = VFX_WSTR_MEM(info->wgt_author);
            pAppInfo->appendDetailInfo(pDetailInfo);
        }
        //invoke ui function
        getInstance()->m_getInfoSignal.emit();
     }
}

void VappWidgetInfoAdapter::uninstallCallback(void* user_data)
{
    VAPP_AM_TRACE(VAPP_AM_WGT_UNINSTALL_CB);
    if (getInstance())
    {
	    getInstance()->m_uninstallSignal.emit(VAPP_AM_OK);
    }	    
}

VfxS32 VappWidgetInfoAdapter::startSrv()
{
    VAPP_AM_TRACE(VAPP_AM_WGT_START);
    
    AM_MALLOC(m_pMem,sizeof(srv_wgtmgr_wgt_asm_data_struct));   
    srv_wgtmgr_start(m_pMem, (srv_wgtmgr_start_cb_func_ptr)&VappWidgetInfoAdapter::startCallback,
                        this->getObjHandle());
    return VAPP_AM_OK;
}

void VappWidgetInfoAdapter::stopSrv()
{
    srv_wgtmgr_stop();
    AM_FREE(m_pMem);
    m_bStarted = VFX_FALSE;
}

//need to start wgt srv befor use this api
VfxS32 VappWidgetInfoAdapter::getAppList(VappInfoList* pInfoList)
{
    VAPP_AM_TRACE1(VAPP_AM_WGT_GET_APP_LIST_BEGIN,m_bStarted);
    
    if(!m_bStarted)
    {
        return VAPP_AM_ERR;
    }
    VfxS32 wgt_num = srv_wgtmgr_get_wgt_num(SRV_WGTMGR_WGT_TYPE_DOWNLOADED);    
    VAPP_AM_TRACE1(VAPP_AM_WGT_GET_NUM,wgt_num);
    
    if (wgt_num ==0)
    {
        return VAPP_AM_OK;
    }
    VfxS32* pList;
    AM_MALLOC(pList,wgt_num*sizeof(VfxS32));
    //need to start wgt srv befor use this api
    srv_wgtmgr_get_downloaded_wgt_list(pList);
    
    VappInfo* pAppInfo;
    VfxWChar wgt_name[SRV_WGTMGR_MAX_WGT_NAME_LEN+1];
    
    for (VfxS32 i = 0; i < wgt_num; i++)
    {
        VFX_OBJ_CREATE(pAppInfo, VappInfo, VappAMApp::getMainScr()->getApp());
        pAppInfo->m_appID = pList[i];
        pAppInfo->m_type = VappInfo::VAPP_AM_APP_TYPE_WIGHET;
        pAppInfo->m_pAdapter = this;
        // TODO: what should i do , if i got name failed?
        srv_wgtmgr_get_downloaded_wgt_name(pAppInfo->m_appID,
                            wgt_name,SRV_WGTMGR_MAX_WGT_NAME_LEN+1);
        pAppInfo->m_wstrAppName = VFX_WSTR_MEM(wgt_name);
        pInfoList->append(pAppInfo);
    }
    AM_FREE(pList);
    
    VAPP_AM_TRACE(VAPP_AM_WGT_GET_APP_LIST_END);

    return VAPP_AM_OK;
}

//need to start wgt srv befor use this api
VfxS32 VappWidgetInfoAdapter::getAppInfo(VappInfo* pAppInfo)
{
    VAPP_AM_TRACE2(VAPP_AM_WGT_GET_APP_INFO_BEGIN, m_bStarted, pAppInfo->m_appID);
    
    if(!m_bStarted)
    {
        return VAPP_AM_ERR;
    }
    
    VfxWChar icon_path[SRV_WGTMGR_MAX_WGT_ICON_PATH_LEN+1]={0};
    srv_wgtmgr_downloaded_wgt_info_struct   info_struct;
    VappDetailInfo* pDetailInfo;
    
    //icon path
    srv_wgtmgr_get_downloaded_wgt_icon_path(pAppInfo->m_appID, icon_path);
    pAppInfo->m_wstrIconPath = VFX_WSTR_MEM(icon_path);
    //main info, need to start wgt srv befor use this api
    srv_wgtmgr_get_downloaded_wgt_info(pAppInfo->m_appID,&info_struct);
    
    //app name
    pAppInfo->m_wstrAppName = VFX_WSTR_MEM(info_struct.name);
    //install name
    translateTime(info_struct.install_time,pAppInfo->m_wstrInstallTime);
    //install type , for us ,there are only 2 types
    if (SRV_WGTMGR_ATTR_PREINSTALL & info_struct.attribute)
    {
        pAppInfo->m_installtype = VappInfo::VAPP_AM_APP_INSTALL_TYPE_NATIVE;
    }
    else
    {
        pAppInfo->m_installtype = VappInfo::VAPP_AM_APP_INSTALL_TYPE_INSTALL;
    }
    //widget cant update 
    pAppInfo->m_bUpdatable = VFX_FALSE;
    //can uninstall ?
    if (SRV_WGTMGR_ATTR_UNDELETABLE & info_struct.attribute)
    {
        pAppInfo->m_bUninstallable = VFX_FALSE;
    }
    else
    {
        pAppInfo->m_bUninstallable = VFX_TRUE;
    }

    //detail informations
    //version
    if (info_struct.version[0] != 0)
    {
        VFX_OBJ_CREATE(pDetailInfo, VappDetailInfo, pAppInfo);
        pDetailInfo->m_type = VappDetailInfo::VAPP_AM_DETAIL_INFO_VERSION;
        pDetailInfo->m_wstrContent = VFX_WSTR_MEM(info_struct.version);
        pAppInfo->appendDetailInfo(pDetailInfo);
    }
    //size
    if (info_struct.size[0] != 0)
    {
        VFX_OBJ_CREATE(pDetailInfo, VappDetailInfo, pAppInfo);
        pDetailInfo->m_type = VappDetailInfo::VAPP_AM_DETAIL_INFO_SIZE;
        pDetailInfo->m_wstrContent = VFX_WSTR_MEM(info_struct.size);
        pAppInfo->appendDetailInfo(pDetailInfo);
    }
    //storage postion
    if (SRV_WGTMGR_DRIVE_MEMORY_CARD == 
                srv_wgtmgr_get_downloaded_wgt_installed_drive(pAppInfo->m_appID))
    {
        pAppInfo->m_storage = VappInfo::VAPP_AM_APP_POS_CARD;
    }
    else
    {
        pAppInfo->m_storage = VappInfo::VAPP_AM_APP_POS_PHONE;
    }

    VAPP_AM_TRACE(VAPP_AM_WGT_GET_APP_INFO_END);         
    return VAPP_AM_OK;            
}

VfxS32 VappWidgetInfoAdapter::getDetailAppInfo(VappInfo* pAppInfo)
{
    VAPP_AM_TRACE(VAPP_AM_WGT_GET_APP_DETAIL_INFO);
    
    srv_wgtmgr_get_downloaded_wgt_detail(
            pAppInfo->m_appID,
            (srv_wgtmgr_get_wgt_detail_cb_func_ptr)&VappWidgetInfoAdapter::getAppInfoCallback,
            pAppInfo->getObjHandle());
    return VAPP_AM_PROCESSING;            
}

VfxBool VappWidgetInfoAdapter::isExist(VappInfo* pAppInfo)
{
    if (SRV_WGTMGR_RET_OK == srv_wgtmgr_check_downloaded_wgt(pAppInfo->m_appID))
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

VfxBool VappWidgetInfoAdapter::isUpdating(VappInfo* pAppInfo)
{
    //widget can not update
    return VFX_FALSE;
}

VfxBool VappWidgetInfoAdapter::isRunning(VappInfo* pAppInfo)
{
    //we could uninstall widget disgard if it is running
    return VFX_FALSE;
}

void VappWidgetInfoAdapter::getSettings(VappBaseSettings* pSettings)
{
    srv_wgtmgr_network_access_enum network_ret;
    network_ret = srv_wgtmgr_get_network_access();
    pSettings->m_bNetWork = 
            SRV_WGTMGR_NETWORK_ACCESS_ALLOW == network_ret?VFX_TRUE:VFX_FALSE;
            
    pSettings->m_bWiFiOnly = srv_wgtmgr_is_wifi_only()?VFX_TRUE:VFX_FALSE;
}

VfxS32 VappWidgetInfoAdapter::setSettings(const VappBaseSettings* pSettings)
{
    if (pSettings->m_bNetWork)
    {
        srv_wgtmgr_set_network_access(SRV_WGTMGR_NETWORK_ACCESS_ALLOW);
    }
    else
    {
        srv_wgtmgr_set_network_access(SRV_WGTMGR_NETWORK_ACCESS_NO);
    }

    if (pSettings->m_bWiFiOnly)
    {
        srv_wgtmgr_set_wifi_only(MMI_TRUE);
    }
    else
    {
        srv_wgtmgr_set_wifi_only(MMI_FALSE);
    }
    return VAPP_AM_OK;
}

void VappWidgetInfoAdapter::getDataAccount(VappAMDataAccount* pDA, VfxU32 type)
{ 
#ifdef _AM_DATA_ACCOUNT_
    if (pDA)
    {
        pDA->m_runData.bearers = DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI; // bear type
        pDA->m_runData.app_id = srv_wgtmgr_get_da_app_id(); // use real app id
        pDA->m_runData.sim_selection = CUI_DTCNT_SELECT_SIM_ALL;// which sim card related account app want
        pDA->m_runData.option = CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY;
        pDA->m_runData.type = CUI_DTCNT_SELECT_TYPE_NORMAL; // type option, it is the same to 10A*/
        for (int i = 0; i < (int)MMI_SIM_TOTAL; i++)
    	{
            pDA->m_runData.sim_account_id[i] = srv_wgtmgr_get_default_data_account((srv_wgtmgr_sim_enum)i); // use last time selected sim1 account id
    	}
    }
#endif //_AM_DATA_ACCOUNT_
}

void VappWidgetInfoAdapter::setDataAccount(const VappAMDataAccount* pDA, VfxU32 type)
{
#ifdef _AM_DATA_ACCOUNT_
    if (pDA)
    {
		for (int i = 0; i < (int)MMI_SIM_TOTAL; i++)
    	{
            srv_wgtmgr_set_default_data_account((srv_wgtmgr_sim_enum)i,pDA->m_runData.sim_account_id[i]);
    	}		
    }
#endif //_AM_DATA_ACCOUNT_
}

VfxS32 VappWidgetInfoAdapter::checkUpdate(VappInfo* pAppInfo)
{
    return VAPP_AM_OK;
}

VfxS32 VappWidgetInfoAdapter::updateApp(VappInfo* pAppInfo)
{
    //widget can not update, but we return OK!
    return VAPP_AM_OK;
}

VfxS32 VappWidgetInfoAdapter::uninstallApp(VappInfo* pAppInfo)
{
    VAPP_AM_TRACE(VAPP_AM_WGT_UNINSTALL);
    
    srv_wgtmgr_delete_wgt(pAppInfo->m_appID,(srv_wgtmgr_delete_wgt_cb_func_ptr)&VappWidgetInfoAdapter::uninstallCallback,
                            pAppInfo);
    return VAPP_AM_PROCESSING;
}

#endif //__GADGET_SUPPORT__

#ifdef __J2ME__
/***************************************************************************** 
 * Class VappJavaInfoAdapter
 *****************************************************************************/
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappJavaInfoAdapter);  

VappJavaInfoAdapter::VappJavaInfoAdapter()
:m_pList(NULL)
{
    
}

VfxS32 VappJavaInfoAdapter::startSrv()
{
    return VAPP_AM_OK;
}
void VappJavaInfoAdapter::stopSrv()
{
    AM_FREE(m_pList);
}

VfxS32 VappJavaInfoAdapter::getAppList(VappInfoList* pInfoList)
{  
    VAPP_AM_TRACE(VAPP_AM_JAVA_GET_APP_LIST_BEGIN);

    if (srv_java_appfactory_is_busy())
    {
        return VAPP_AM_ERR;
    }
    
    VfxU32 java_num = srv_java_appfactory_get_reg_mid_num(SRV_APPMGR_JAVA_APP_PACKAGE_TYPE);
    VAPP_AM_TRACE1(VAPP_AM_JAVA_GET_NUM,java_num);
    
    if (0 == java_num)
    {
        return VAPP_AM_OK;
    }
    //m_pList will not release untill app terminate
    AM_FREE(m_pList);
    AM_MALLOC(m_pList,sizeof(mmi_app_package_name_struct)*java_num);
    if (srv_java_appfactory_get_reg_app_list(SRV_APPMGR_JAVA_APP_PACKAGE_TYPE,m_pList,java_num))
    {
        return VAPP_AM_ERR;
    }
    
    VappInfo* pAppInfo;
    for (VfxU32 i = 0; i < java_num; i++)
    {
        VFX_OBJ_CREATE(pAppInfo, VappInfo, VappAMApp::getMainScr()->getApp());
        pAppInfo->m_strApp= (VfxChar*)m_pList[i];
        pAppInfo->m_type = VappInfo::VAPP_AM_APP_TYPE_JAVA;
        pAppInfo->m_pAdapter = this;

        VfxWChar appName[256]={0};
        srv_java_appfactory_get_string(pAppInfo->m_strApp,appName);
        pAppInfo->m_wstrAppName = VFX_WSTR_MEM(appName);
        pInfoList->append(pAppInfo);
    }

    VAPP_AM_TRACE(VAPP_AM_JAVA_GET_APP_LIST_END);
    
    return VAPP_AM_OK;
}

VfxS32 VappJavaInfoAdapter::getAppInfo(VappInfo* pAppInfo)
{
    VAPP_AM_TRACE1(VAPP_AM_JAVA_GET_APP_INFO_BEGIN,Vapp_AM_UTF8_to_ASCII(pAppInfo->m_strApp));
    
    java_info_struct* info = NULL;
    if (MMI_RET_OK == srv_java_appfactory_get_mids_info(pAppInfo->m_strApp,&info))
    {
        //app install time
        VfxDateTime dataTime;
        dataTime.setDateTime(&(info->install_time));  
        pAppInfo->m_wstrInstallTime = dataTime.getDateTimeString(VFX_DATE_TIME_DATE_MASK);
        //pAppInfo->m_wstrInstallTime = VFX_WSTR_MEM(info->install_time);
        //app icon path
        pAppInfo->m_wstrIconPath = VFX_WSTR_MEM(info->icon_path);
        //app storage positon
        if (PHONE_DISK == info->storage_type)
        {
            pAppInfo->m_storage = VappInfo::VAPP_AM_APP_POS_PHONE;
        }
        else if (MEMORY_CARD == info->storage_type)
        {
            pAppInfo->m_storage = VappInfo::VAPP_AM_APP_POS_CARD;
        }
        //can uninstall ?
        pAppInfo->m_bUninstallable = info->can_be_uninstall?VFX_TRUE:VFX_FALSE;
        //can update ?
        pAppInfo->m_bUpdatable = info->can_be_update?VFX_TRUE:VFX_FALSE;
        //install type
        pAppInfo->m_installtype = pAppInfo->m_bUninstallable?VappInfo::VAPP_AM_APP_INSTALL_TYPE_INSTALL:
                                     VappInfo::VAPP_AM_APP_INSTALL_TYPE_NATIVE;   
        //detail informations
        //version
        VappDetailInfo* pDetailInfo;
        VFX_OBJ_CREATE(pDetailInfo, VappDetailInfo, pAppInfo);
        pDetailInfo->m_type = VappDetailInfo::VAPP_AM_DETAIL_INFO_VERSION;
        pDetailInfo->m_wstrContent = VFX_WSTR_MEM(info->mids_version);
        pAppInfo->appendDetailInfo(pDetailInfo);
        //size
        if (info->mids_size > 1024)
        { 
            info->mids_size = info->mids_size >> 10;
       
            VFX_OBJ_CREATE(pDetailInfo, VappDetailInfo, pAppInfo);
            pDetailInfo->m_type = VappDetailInfo::VAPP_AM_DETAIL_INFO_SIZE;        
            pDetailInfo->m_wstrContent.format("%d KB",info->mids_size);
            pAppInfo->appendDetailInfo(pDetailInfo);
        }
        //author
        if (info->mids_vendor && info->mids_vendor[0] != 0)
        {
            VFX_OBJ_CREATE(pDetailInfo, VappDetailInfo, pAppInfo);
            pDetailInfo->m_type = VappDetailInfo::VAPP_AM_DETAIL_INFO_AUTHOR;
            pDetailInfo->m_wstrContent = VFX_WSTR_MEM(info->mids_vendor);
            pAppInfo->appendDetailInfo(pDetailInfo);
        }
        //description
        if (info->mids_description && info->mids_description[0] != 0)
        {
            VFX_OBJ_CREATE(pDetailInfo, VappDetailInfo, pAppInfo);
            pDetailInfo->m_type = VappDetailInfo::VAPP_AM_DETAIL_INFO_INTRODUCE;
            pDetailInfo->m_wstrContent = VFX_WSTR_MEM(info->mids_description);
            pAppInfo->appendDetailInfo(pDetailInfo);
        }
        //authorized
        VFX_OBJ_CREATE(pDetailInfo, VappDetailInfo, pAppInfo);
        pDetailInfo->m_type = VappDetailInfo::VAPP_AM_DETAIL_INFO_AUTHORIZED;
        //load resource
        if (info->mids_authorized)
        {
            pDetailInfo->m_wstrContent = VFX_WSTR_RES(STR_ID_VAPP_AM_DETAIL_AUTHORIZE_Y);
        }
        else
        {
            pDetailInfo->m_wstrContent = VFX_WSTR_RES(STR_ID_VAPP_AM_DETAIL_AUTHORIZE_N);
        }
        pAppInfo->appendDetailInfo(pDetailInfo);
        //website       
        if (isURLString(info->mids_website))
        {
            VFX_OBJ_CREATE(pDetailInfo, VappDetailInfo, pAppInfo);
            pDetailInfo->m_type = VappDetailInfo::VAPP_AM_DETAIL_INFO_WEBSITE;
            pDetailInfo->m_wstrContent = VFX_WSTR_MEM(info->mids_website);
            pAppInfo->appendDetailInfo(pDetailInfo);
        }
        return VAPP_AM_OK;
    }

    VAPP_AM_TRACE(VAPP_AM_JAVA_GET_APP_INFO_END);
    
    return VAPP_AM_ERR;
                        
}

VfxS32 VappJavaInfoAdapter::getDetailAppInfo(VappInfo* pAppInfo)
{
    return VAPP_AM_OK;
}

VfxBool VappJavaInfoAdapter::isExist(VappInfo* pAppInfo)
{
    return srv_java_appfactory_is_app_exit(pAppInfo->m_strApp)?VFX_TRUE:VFX_FALSE;
}

VfxBool VappJavaInfoAdapter::isUpdating(VappInfo* pAppInfo)
{
    //java do not need us to check if is updating
    return VFX_FALSE;
}

VfxBool VappJavaInfoAdapter::isRunning(VappInfo* pAppInfo)
{
    return srv_java_appfactory_is_app_running(pAppInfo->m_strApp)?VFX_TRUE:VFX_FALSE;
}

void VappJavaInfoAdapter::getSettings(VappBaseSettings* pSettings)
{
    //do nothing
}

VfxS32 VappJavaInfoAdapter::setSettings(const VappBaseSettings* pSettings)
{
    //do nothing
    return VAPP_AM_OK;
}

VfxS32 VappJavaInfoAdapter::checkUpdate(VappInfo* pAppInfo)
{
    m_checkedUpdateSignal.emit(VAPP_AM_OK);
	return VAPP_AM_OK;
}

VfxS32 VappJavaInfoAdapter::updateApp(VappInfo* pAppInfo)
{
    VAPP_AM_TRACE(VAPP_AM_JAVA_UPATE_BEGIN);
    
    VappJavaMIDDetailControllor* pJavaCtl;
    VFX_OBJ_CREATE(pJavaCtl, VappJavaMIDDetailControllor, VappAMApp::getMainScr());
    
    pJavaCtl->updateMidsHandler(pAppInfo->m_strApp,VappAMApp::getMainScr());
    pAppInfo->fresh();
    VAPP_AM_TRACE(VAPP_AM_JAVA_UPATE_END);
    return VAPP_AM_OK;
}

VfxS32 VappJavaInfoAdapter::uninstallApp(VappInfo* pAppInfo)
{
    VAPP_AM_TRACE(VAPP_AM_JAVA_UNINSTALL_BEGIN);
    
    VappJavaMIDDetailControllor* pJavaCtl;
    VFX_OBJ_CREATE(pJavaCtl, VappJavaMIDDetailControllor, VappAMApp::getMainScr());
    
    pJavaCtl->deleteMidsHandler(pAppInfo->m_strApp,pAppInfo,
                                    &VappJavaInfoAdapter::uninstallCallback);

    VAPP_AM_TRACE(VAPP_AM_JAVA_UNINSTALL_END);
    
    return VAPP_AM_PROCESSING;
}

void VappJavaInfoAdapter::uninstallCallback(void * user_data, kal_int32 result)
{
    VAPP_AM_TRACE1(VAPP_AM_JAVA_UNINSTALL_CB,result);
    if (getInstance())
    {
        getInstance()->m_uninstallSignal.postEmit(VAPP_AM_OK);
    }        
}

VfxBool VappJavaInfoAdapter::isURLString(VfxWChar* str)
{
    CHAR tmpBuf[256];
    if (str && str[0] != 0)
    {
        if (kal_wstrlen(str) > 254)
        {
            return VFX_TRUE;
        }
        
        mmi_ucs2_to_asc(tmpBuf, (CHAR*)str);
        if (strstr(tmpBuf,"rtsp") || strstr(tmpBuf,"http"))
        {
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

#endif //__J2ME__
/***************************************************************************** 
 * Class VappMREInfoAdapter
 *****************************************************************************/
 
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappMREInfoAdapter);

VappMREInfoAdapter::VappMREInfoAdapter()
:m_pList(NULL)
{
    
}

VfxS32 VappMREInfoAdapter::startSrv()
{
    srv_mre_da_init();
    return VAPP_AM_OK;
}
void VappMREInfoAdapter::stopSrv()
{
    srv_mre_da_deinit();
    AM_FREE(m_pList);
}

VfxS32 VappMREInfoAdapter::getAppList(VappInfoList* pInfoList)
{  
    VAPP_AM_TRACE(VAPP_AM_MRE_GET_APP_LIST_BEGIN);
    
    VfxU32 MRE_num = srv_mre_appmgr_get_installed_app_num();

    VAPP_AM_TRACE1(VAPP_AM_MRE_GET_NUM,MRE_num);
    
    if (0 == MRE_num)
    {
        return VAPP_AM_OK;
    }
    //pList will not release untill app terminate
//    srv_app_package_name_struct* pList =NULL;
    AM_FREE(m_pList);
    AM_MALLOC(m_pList,sizeof(mmi_app_package_name_struct)*MRE_num);
    if (srv_mre_appmgr_get_installed_app_list(m_pList,MRE_num))
    {
        return VAPP_AM_ERR;
    }
    
    VappInfo* pAppInfo;
    for (VfxU32 i = 0; i < MRE_num; i++)
    {
        VFX_OBJ_CREATE(pAppInfo, VappInfo, VappAMApp::getMainScr()->getApp());
        pAppInfo->m_strApp= (VfxChar*)m_pList[i];
        pAppInfo->m_type = VappInfo::VAPP_AM_APP_TYPE_MRE;
        pAppInfo->m_pAdapter = this;
        //we need name to sort list. and app update can NOT change it's name!!
        VfxWChar appName[256]={0};
        srv_mre_appmgr_get_app_name(pAppInfo->m_strApp,appName);
        pAppInfo->m_wstrAppName = VFX_WSTR_MEM(appName);
        pInfoList->append(pAppInfo);
    }

    VAPP_AM_TRACE(VAPP_AM_MRE_GET_APP_LIST_END);
        
    return VAPP_AM_OK;
}

VfxS32 VappMREInfoAdapter::getAppInfo(VappInfo* pAppInfo)
{
    VAPP_AM_TRACE1(VAPP_AM_MRE_GET_APP_INFO_BEGIN,Vapp_AM_UTF8_to_ASCII(pAppInfo->m_strApp));
    
    //icon
    mmi_image_src_struct* pImg = NULL;
    AM_MALLOC(pImg,sizeof(mmi_image_src_struct));
    if (!pImg)
        return VAPP_AM_ERR;
    if (MMI_RET_OK == srv_mre_appmgr_get_app_image(pAppInfo->m_strApp,pImg))
    {
    
        if (MMI_IMAGE_SRC_TYPE_RES_ID == pImg->type)
        {
            pAppInfo->m_iconId = pImg->data.res_id;
        }
        else if (MMI_IMAGE_SRC_TYPE_PATH == pImg->type)
        {
            pAppInfo->m_wstrIconPath= VFX_WSTR_MEM(pImg->data.path);
        }
        else  if(MMI_IMAGE_SRC_TYPE_ROM_MEMORY == pImg->type)
      	{
      	    pAppInfo->m_memPtr = pImg->data.image.image_ptr;      
      	    pAppInfo->m_memLength=pImg->data.image.image_len;
      	}
    }
    AM_FREE(pImg);
    //installtime
    applib_time_struct time;
    if (srv_mre_appmgr_get_app_installed_time(pAppInfo->m_strApp,&time))
    {
        VfxDateTime dataTime;

        dataTime.setDateTime(&time);
        pAppInfo->m_wstrInstallTime = dataTime.getDateTimeString(VFX_DATE_TIME_DATE_MASK);
//        pAppInfo->m_wstrInstallTime.format("%d-%d-%d",time.nYear,time.nMonth,time.nDay);
    }
    //install type
    srv_mre_appmgr_app_type_enum install_type;
    install_type = srv_mre_appmgr_get_app_type(pAppInfo->m_strApp);
    if (SRV_MRE_APPMGR_APP_TYPE_LOCAL_INSTALL & install_type)
    {
        pAppInfo->m_installtype =  VappInfo::VAPP_AM_APP_INSTALL_TYPE_INSTALL;
    }
    else if (SRV_MRE_APPMGR_APP_TYPE_DOWNLOAD == install_type)
    {
        pAppInfo->m_installtype =  VappInfo::VAPP_AM_APP_INSTALL_TYPE_DOWNLOAD;
    }
    else if (SRV_MRE_APPMGR_APP_TYPE_ROM & install_type)
    {
        pAppInfo->m_installtype =  VappInfo::VAPP_AM_APP_INSTALL_TYPE_NATIVE;
    }
    //storage position
    srv_mre_appmgr_app_storage_position_enum storage_position;
    storage_position = srv_mre_appmgr_get_app_storage_position(pAppInfo->m_strApp);
    if (SRV_MRE_APPMGR_APP_POSITION_CARD == storage_position)
    {
        pAppInfo->m_storage = VappInfo::VAPP_AM_APP_POS_CARD;
    }
    else 
    {
        pAppInfo->m_storage = VappInfo::VAPP_AM_APP_POS_PHONE;
    }
    
#ifdef __MRE_LIB_NETWORK__  
    //MRE app always can update
    pAppInfo->m_bUpdatable = VFX_TRUE; 
#else
    pAppInfo->m_bUpdatable = VFX_FALSE;
#endif
    //can uninstall?
    pAppInfo->m_bUninstallable = srv_mre_appmgr_is_support_uninstall(pAppInfo->m_strApp)?VFX_TRUE:VFX_FALSE;

    VAPP_AM_TRACE(VAPP_AM_MRE_GET_APP_INFO_END);
    
    return VAPP_AM_OK;
}

VfxS32 VappMREInfoAdapter::getDetailAppInfo(VappInfo* pAppInfo)
{
    VAPP_AM_TRACE1(VAPP_AM_MRE_GET_APP_DETAIL_INFO_BEGIN, Vapp_AM_UTF8_to_ASCII(pAppInfo->m_strApp));
    
    VappDetailInfo* pDetailInfo;
    //app size
    VfxU32 size = srv_mre_appmgr_get_app_size(pAppInfo->m_strApp);
    if (size > 1024)
    {  
        size = size >> 10;
   
        VFX_OBJ_CREATE(pDetailInfo, VappDetailInfo, pAppInfo);
        pDetailInfo->m_type = VappDetailInfo::VAPP_AM_DETAIL_INFO_SIZE;        
        pDetailInfo->m_wstrContent.format("%d KB",size);
        pAppInfo->appendDetailInfo(pDetailInfo);
        
    }
    //app instruction
    if (srv_mre_appmgr_get_app_description(pAppInfo->m_strApp,NULL,&size) && size > 0)
    {
        VfxWChar* pMem = NULL;
        AM_MALLOC(pMem, (size+1)*sizeof(VfxWChar));
        if (!pMem)
            return VAPP_AM_ERR;
        if (srv_mre_appmgr_get_app_description(pAppInfo->m_strApp,pMem,&size))
        {
            VFX_OBJ_CREATE(pDetailInfo, VappDetailInfo, pAppInfo);
            pDetailInfo->m_type = VappDetailInfo::VAPP_AM_DETAIL_INFO_INTRODUCE;        
            pDetailInfo->m_wstrContent = VFX_WSTR_MEM(pMem);
            pAppInfo->appendDetailInfo(pDetailInfo);
        }
        AM_FREE(pMem);
    }
    //author
    if (srv_mre_appmgr_get_app_developer(pAppInfo->m_strApp,NULL,&size) && size > 0)
    {
        VfxWChar* pMem = NULL;
        AM_MALLOC(pMem, (size+1)*sizeof(VfxWChar));
        if (!pMem)
            return VAPP_AM_ERR;
        if (srv_mre_appmgr_get_app_developer(pAppInfo->m_strApp,pMem,&size))
        {
            VFX_OBJ_CREATE(pDetailInfo, VappDetailInfo, pAppInfo);
            pDetailInfo->m_type = VappDetailInfo::VAPP_AM_DETAIL_INFO_AUTHOR;        
            pDetailInfo->m_wstrContent = VFX_WSTR_MEM(pMem);
            pAppInfo->appendDetailInfo(pDetailInfo);
        }
        AM_FREE(pMem);
    }
    //telephone number
    //this number will less than 20 
    VfxWChar tel[20];
    if (srv_mre_appmgr_get_app_tel(pAppInfo->m_strApp,tel))
    {
        VFX_OBJ_CREATE(pDetailInfo, VappDetailInfo, pAppInfo);
        pDetailInfo->m_type = VappDetailInfo::VAPP_AM_DETAIL_INFO_NUMBER;        
        pDetailInfo->m_wstrContent = VFX_WSTR_MEM(tel);
        pAppInfo->appendDetailInfo(pDetailInfo);
    }

    VAPP_AM_TRACE(VAPP_AM_MRE_GET_APP_DETAIL_INFO_END);
    
    return VAPP_AM_OK;
}

VfxBool VappMREInfoAdapter::isExist(VappInfo* pAppInfo)
{
    VfxBool bRet = srv_mre_appmgr_is_app_exist(pAppInfo->m_strApp)?VFX_TRUE:VFX_FALSE;
    
    VAPP_AM_TRACE2(VAPP_AM_MRE_IS_EXIST,Vapp_AM_UTF8_to_ASCII(pAppInfo->m_strApp),bRet);
    
    return bRet;
}

VfxBool VappMREInfoAdapter::isUpdating(VappInfo* pAppInfo)
{
    VfxBool bRet = srv_mre_appmgr_is_bg_downloading(pAppInfo->m_strApp)?VFX_TRUE:VFX_FALSE;

    VAPP_AM_TRACE2(VAPP_AM_MRE_IS_UPDATING,Vapp_AM_UTF8_to_ASCII(pAppInfo->m_strApp),bRet);
    
    return bRet;
}

VfxBool VappMREInfoAdapter::isRunning(VappInfo* pAppInfo)
{
    VfxBool bRet = srv_mre_appmgr_is_bg_running(pAppInfo->m_strApp)?VFX_TRUE:VFX_FALSE;

    VAPP_AM_TRACE2(VAPP_AM_MRE_IS_RUNNING,Vapp_AM_UTF8_to_ASCII(pAppInfo->m_strApp),bRet);
    
    return bRet;
}

void VappMREInfoAdapter::getSettings(VappBaseSettings* pSettings)
{
    //
    pSettings->m_bWiFiOnly = srv_mre_da_get_account_id(SRV_MRE_DA_WIFI_ONLY)?VFX_TRUE:VFX_FALSE;
}

VfxS32 VappMREInfoAdapter::setSettings(const VappBaseSettings* pSettings)
{
    //
    srv_mre_da_set_account_id(SRV_MRE_DA_WIFI_ONLY,(U16)pSettings->m_bWiFiOnly);
    return VAPP_AM_OK;
}

VfxS32 VappMREInfoAdapter::checkUpdate(VappInfo* pAppInfo)
{
#ifdef __MRE_LIB_NETWORK__

    if (srv_mre_appmgr_check_update(pAppInfo->m_strApp,
                    (srv_mre_appmgr_app_update_check_cb_t)&VappMREInfoAdapter::checkUpdateCallback))
    {
        
        return VAPP_AM_OK;
    }
    else
    {
        m_checkedUpdateSignal.emit(VAPP_AM_ERR);
        return VAPP_AM_ERR;
    }
#else
    return VAPP_AM_OK;
#endif
 
}

VfxS32 VappMREInfoAdapter::updateApp(VappInfo* pAppInfo)
{
#ifdef __MRE_LIB_NETWORK__
    if (srv_mre_appmgr_app_update(
            m_appId,
            (U16*)m_fileName.getBuf(),
            &m_fileSize,
            &VappMREInfoAdapter::updateCallback,
            NULL))
    {
        return VAPP_AM_OK;
    }
    else
    {
        return VAPP_AM_ERR;
    }
#else
    return VAPP_AM_OK;
#endif
}

VfxS32 VappMREInfoAdapter::uninstallApp(VappInfo* pAppInfo)
{
    if (srv_mre_appmgr_app_uninstall(pAppInfo->m_strApp))
    {
//        m_uninstallSignal.emit(VAPP_AM_OK);
        return VAPP_AM_OK;
    }
    else
    {
        return VAPP_AM_ERR;
    }
}

void VappMREInfoAdapter::getDataAccount(VappAMDataAccount* pDA, VfxU32 type)
{
    // 
#ifdef _AM_DATA_ACCOUNT_
    
    if (pDA)
    {
        int j = VAPP_AM_MRE_DA_NO_PROXY == type?0:1;
    
        pDA->m_runData.bearers = DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI; // bear type
        pDA->m_runData.app_id = srv_mre_da_get_app_id((srv_mre_da_type)j); // use real app id
        pDA->m_runData.sim_selection = CUI_DTCNT_SELECT_SIM_ALL;// which sim card related account app want
        pDA->m_runData.option = VAPP_AM_MRE_DA_NO_PROXY == type?CUI_DTCNT_SELECT_WITHOUT_PROXY_ONLY:CUI_DTCNT_SELECT_WITH_PROXY_ONLY;
        pDA->m_runData.type = CUI_DTCNT_SELECT_TYPE_NORMAL; // type option, it is the same to 10A

        for (int i = 0; i < (int)MMI_SIM_TOTAL; i++)
    	{
            pDA->m_runData.sim_account_id[i] = srv_mre_da_get_account_id((srv_mre_da_type)(j+2*i)); // use last time selected sim1 account id
    	}			
    }

#endif
}

void VappMREInfoAdapter::setDataAccount(const VappAMDataAccount* pDA, VfxU32 type)
{
    // 
#ifdef _AM_DATA_ACCOUNT_
    if (pDA)
    {
		int j = VAPP_AM_MRE_DA_NO_PROXY == type?0:1;
		for (int i = 0; i < (int)MMI_SIM_TOTAL; i++)
    	{
            srv_mre_da_set_account_id((srv_mre_da_type)(j+2*i),pDA->m_runData.sim_account_id[i]); // use last time selected sim1 account id
    	}
    }
#endif
}

void VappMREInfoAdapter::enterDownLoadUI(VappInfo* pAppInfo)
{
    srv_mre_appmgr_download(pAppInfo->m_strApp);
}
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
#endif
/***************************************************************************** 
 * Class VappMREWidgetInfoAdapter
 *****************************************************************************/
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappMREVSOInfoAdapter);
VfxS32 VappMREVSOInfoAdapter::getAppList(VappInfoList* pInfoList)
{
    VAPP_AM_TRACE(VAPP_AM_MRE_GET_APP_LIST_BEGIN);
    
    VfxU32 MRE_num = srv_mre_appmgr_get_app_num(SRV_APPMGR_INSTALLED_VPP_PACKAGE_FLAG_TYPE);

    VAPP_AM_TRACE1(VAPP_AM_MRE_GET_NUM,MRE_num);
    
    if (0 == MRE_num)
    {
        return VAPP_AM_OK;
    }
    //pList will not release untill app terminate
    AM_FREE(m_pList);
    AM_MALLOC(m_pList,sizeof(mmi_app_package_name_struct)*MRE_num);
    if (srv_mre_appmgr_get_app_list(SRV_APPMGR_INSTALLED_VPP_PACKAGE_FLAG_TYPE,m_pList,MRE_num))
    {
        return VAPP_AM_ERR;
    }
    
    VappInfo* pAppInfo;
    for (VfxU32 i = 0; i < MRE_num; i++)
    {
        VFX_OBJ_CREATE(pAppInfo, VappInfo, VappAMApp::getMainScr()->getApp());
        pAppInfo->m_strApp= (VfxChar*)m_pList[i];
        pAppInfo->m_type = VappInfo::VAPP_AM_APP_TYPE_MRE_VSO;
        pAppInfo->m_pAdapter = this;
        //we need name to sort list. and app update can NOT change it's name!!
        VfxWChar appName[256]={0};
        srv_mre_appmgr_get_app_name(pAppInfo->m_strApp,appName);
        pAppInfo->m_wstrAppName = VFX_WSTR_MEM(appName);
        pInfoList->append(pAppInfo);
    }

    VAPP_AM_TRACE(VAPP_AM_MRE_GET_APP_LIST_END);
        
    return VAPP_AM_OK;
}



/***************************************************************************** 
 * Class VappInfoList
 *****************************************************************************/

VappInfoList::VappInfoList()
:m_index(0),m_pIndexEntry(NULL),m_pAdapter(NULL),m_bAlreadyGetList(VFX_FALSE)
{

}
    
void VappInfoList::setAddNotifyFunction(VfxObject* pObj, NotifyFun fun)
{
    m_signalAdd.connect(pObj, fun);
};

void VappInfoList::setRemoveNotifyFunction(VfxObject* pObj, NotifyFun fun)
{
    m_signalRemove.connect(pObj, fun);
};

void VappInfoList::setAdapter(IVappInfoAdapter* pAdapter)
{
    IVappInfoAdapter* pTmp = m_pAdapter;
    if (!m_pAdapter)
    {
        m_pAdapter = pAdapter;
        m_pAdapter->m_pNext = NULL;
        return;
    }
    
    while (pTmp->m_pNext)
    {
        pTmp = pTmp->m_pNext;;
    }
    pTmp->m_pNext = pAdapter; 
    pTmp->m_pNext->m_pNext = NULL;
};

VfxS32 VappInfoList::getAppListFromSrv()
{
    if (m_bAlreadyGetList)
        return VAPP_AM_OK;
        
    //now we support two kinds of app in a list
    VfxS32 result = VAPP_AM_ERR;
    if (!isEmpty())
    {
        clear();
    }
    
    if (m_pAdapter)
    {
        result = m_pAdapter->getAppList(this);
    }

    IVappInfoAdapter* pTmp = m_pAdapter;
    while (pTmp->m_pNext)
    {
        pTmp = pTmp->m_pNext;
        result |= pTmp->getAppList(this);
    }
    if (VAPP_AM_OK == result)
    {
        m_bAlreadyGetList = VFX_TRUE;
    }
    return result;
}

//
VfxObjListEntry* VappInfoList::append(VfxObject *obj)
{
    VappInfo* pAppInfo = (VappInfo*)obj;
    VfxObjListEntry* i;
    VfxObjListEntry* head;
    VfxObjListEntry* result;
    
    head = getHead();
    if (!head)
    {
        result = VfxObjList::append(obj);
    }
    else
    {
        i = getTail();
        while (i != head)
        {
            if (VappInfoComparetor::compare(pAppInfo, (VappInfo*)i->get()) > 0)
            {
               
                result = VfxObjList::insertAfter(i, obj); 
                m_signalAdd.emit();
                return result;
            }
            i = i->getPrev();
        };

        if (VappInfoComparetor::compare(pAppInfo, (VappInfo*)i->get()) > 0)
        {
            result = VfxObjList::insertAfter(i, obj); 
        }
        else
        {
            result = VfxObjList::prepend(obj);
        }
    }
    m_signalAdd.emit();
    return result;
}

VfxBool VappInfoList::removeOne(VfxObject *obj)
{
    if (obj == m_pIndexEntry->get())
    {
        m_pIndexEntry = NULL;
    }
    if (VfxObjList::removeOne(obj))
    {
        
        m_signalRemove.emit();
        return VFX_TRUE;
    }
    else 
    {
        return VFX_FALSE;
    }
};

inline VfxObject* VappInfoList::operator [](VfxU32 index)
{
    if (index > getValidCount())
        return NULL;

    if (NULL == m_pIndexEntry)
    {
        m_index = 0;
    }
    if (0 == m_index || ((index < m_index) && (m_index - index > index)))
    {
        VfxU32 count = 0;
        VfxObjListEntry *i;
        for (i = getHead(); i != NULL; i = i->getNext())
        {
            if (count == index)
            {
                m_index = index;
                m_pIndexEntry = i;
                return i->get();
            }
            count++;
        }
    }
    else if (index >= m_index)
    {
        VfxU32 count = 0;
        VfxObjListEntry *i;
        index -= m_index;
        
        for (i = m_pIndexEntry; i != NULL; i = i->getNext())
        {
            if (count == index)
            {
                m_index += index;
                m_pIndexEntry = i;
                return i->get();
            }
            count++;
        }
    }
    else
    {
        VfxU32 count = 0;
        VfxObjListEntry *i;
        index = m_index - index;
        
        for (i = m_pIndexEntry; i != NULL; i = i->getPrev())
        {
            if (count == index)
            {
                m_index -= index;
                m_pIndexEntry = i;
                return i->get();
            }
            count++;
        }
    }
    return NULL;
};

VfxWeakPtr<VappAMMainSrc>* VappAMApp::m_pMainSrc = NULL;
mmi_id VappAMApp::m_mmiId = 0;
static VappInfoList*    g_pAppInfoList = NULL;
static VappInfoList*    g_pWGTInfoList = NULL;

#ifdef __J2ME__
extern VfxId g_mmi_vjava_advanced_setting_page;
extern VfxId g_mmi_vjava_advanced_permission_page;
#endif


/***************************************************************************** 
 * Class VappAMApp
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappAMApp", VappAMApp, VfxApp);

void VappAMApp::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    m_bInited = VFX_FALSE;
    
    g_pAppInfoList = &m_AppInfoList;
    g_pWGTInfoList = &m_WidgetInfoList;

//    VappAdapterFactory::createInfoAdapter(VAPP_AM_ADPTER_MRE,this);
//    VappAdapterFactory::createInfoAdapter(VAPP_AM_ADPTER_JAVA,this);
//    VappAdapterFactory::createInfoAdapter(VAPP_AM_ADPTER_WGT,this);
    
    VappUSBOperator* pUSB;
    VFX_OBJ_CREATE(pUSB, VappUSBOperator, this);
    pUSB->m_enterMSSignal.connect(this, &VfxApp::exit);

    //create main screen
    VappAMMainSrc *pScr;
    VFX_OBJ_CREATE(pScr, VappAMMainSrc, this);
    m_MainSrc = pScr;
    VappAMApp::m_pMainSrc = &m_MainSrc;    

    //show main screen
    pScr->show();
}

void VappAMApp::initApp()
{
    //init adaptors
    IVappInfoAdapter* pAdptor;
    pAdptor = VappAdapterFactory::getInfoAdapter(VAPP_AM_ADPTER_MRE);
    if (pAdptor)
    {
        pAdptor->startSrv();
        g_pAppInfoList->setAdapter(pAdptor);
    }

    pAdptor = VappAdapterFactory::getInfoAdapter(VAPP_AM_ADPTER_JAVA); 
    if (pAdptor)
    {
        pAdptor->startSrv();
        g_pAppInfoList->setAdapter(pAdptor);
    }
 
    pAdptor = VappAdapterFactory::getInfoAdapter(VAPP_AM_ADPTER_WGT);
    if (pAdptor)
    {
        pAdptor->startSrv();
        g_pWGTInfoList->setAdapter(pAdptor);
    }

    pAdptor = VappAdapterFactory::getInfoAdapter(VAPP_AM_ADPTER_MRE_VSO);
    if (pAdptor)
    {
        pAdptor->startSrv();
        g_pAppInfoList->setAdapter(pAdptor);
    }
    
    
    VappAMMainSrc* pScr = (VappAMMainSrc*)getMainScr();
    if (pScr)
    {
        VappAMApp* pApp = (VappAMApp*)pScr->getApp();
        pApp->m_bInited = VFX_TRUE;
    }
}

void VappAMApp::onDeinit()
{
    if (m_bInited)
    {
        IVappInfoAdapter* pAdptor;

        pAdptor = VappAdapterFactory::getInfoAdapter(VAPP_AM_ADPTER_WGT);
        if (pAdptor)
        {
            pAdptor->stopSrv();
        }

        pAdptor = VappAdapterFactory::getInfoAdapter(VAPP_AM_ADPTER_JAVA);
        if (pAdptor)
        {
            pAdptor->stopSrv();
        }
       
        pAdptor = VappAdapterFactory::getInfoAdapter(VAPP_AM_ADPTER_MRE);
        if (pAdptor)
        {
            pAdptor->stopSrv();
        }

        pAdptor = VappAdapterFactory::getInfoAdapter(VAPP_AM_ADPTER_MRE_VSO);
        if (pAdptor)
        {
            pAdptor->stopSrv();
        }
        
        m_bInited = VFX_FALSE;
    }
    g_pWGTInfoList = NULL;
    g_pAppInfoList = NULL;
    VappAMApp::m_pMainSrc = NULL;
    VfxApp::onDeinit();
}

mmi_ret VappAMApp::onProc(mmi_event_struct *evt)
{
    VappAMMainSrc* pSrc = getMainScr();
    if (pSrc && pSrc->isValid())
    {
        //we let page who own data account to process event
        return pSrc->processProc(evt);
    }
    return VfxApp::onProc(evt);
}

/***************************************************************************** 
 * Class VappAMMainSrc
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappAMMainSrc", VappAMMainSrc, VfxMainScr);
void VappAMMainSrc::on1stReady()
{
#ifdef __MMI_COSMOS_APP_MANAGER__

    VfxMainScr::on1stReady();

    VappAMMainPage* pPage;
    VFX_OBJ_CREATE(pPage, VappAMMainPage, this);
    pushPage(VappAMMainPage::m_pageId, pPage);   
#endif    
}

/***************************************************************************** 
 * Class VappAdapterFactory
 *****************************************************************************/
//use this class to avoid too much compile option
IVappInfoAdapter* VappAdapterFactory::getInfoAdapter(VfxS32 type)
{
#ifdef _AM_APP_TEST_
    return (IVappInfoAdapter*)VappTestInfoAdapter::getInstance();
#endif //_AM_APP_TEST_

    if (VAPP_AM_ADPTER_MRE == type)
    {
        return (IVappInfoAdapter*)VappMREInfoAdapter::getInstance();
    }
    else if (VAPP_AM_ADPTER_JAVA == type)
    {
#ifdef __J2ME__
    return (IVappInfoAdapter*)VappJavaInfoAdapter::getInstance();
#else //__J2ME__
    return NULL;
#endif //__J2ME__     
    }
    else if (VAPP_AM_ADPTER_WGT == type)
    {
#ifdef __GADGET_SUPPORT__
    return (IVappInfoAdapter*)VappWidgetInfoAdapter::getInstance();
#else //__GADGET_SUPPORT__
    return NULL;
#endif //__GADGET_SUPPORT__    
    }
    else if (VAPP_AM_ADPTER_MRE_VSO == type)
    {
        return (IVappInfoAdapter*)VappMREVSOInfoAdapter::getInstance();
    }
    else
    {
        return NULL;
    }
}

IVappDataAccountAdapter* VappAdapterFactory::getDAAdapter(VfxS32 type)
{
    if (VAPP_AM_ADPTER_MRE == type)
    {
        return (IVappDataAccountAdapter*)VappMREInfoAdapter::getInstance();
    }
    else if (VAPP_AM_ADPTER_WGT == type)
    {
#ifdef __GADGET_SUPPORT__
    return (IVappDataAccountAdapter*)VappWidgetInfoAdapter::getInstance();
#else //__GADGET_SUPPORT__
    return NULL;
#endif //__GADGET_SUPPORT__    
    }
    else
    {
        return NULL;
    }
}

/***************************************************************************** 
 * Class VappDialerCUIInstance
 *****************************************************************************/
mmi_id VappDialerCUIInstance::m_id = 0;

void VappDialerCUIInstance::runInstance(const VfxWString &str)
{
    if (!m_id)
    {
        m_id = vcui_dialer_create(VappAMApp::m_mmiId);
    }
    vcui_dialer_set_dial_string(m_id, str);
    vcui_dialer_run(m_id);
}

void VappDialerCUIInstance::closeInstance()
{
    if (m_id)
    {
        vcui_dialer_close(m_id);
        m_id = 0;
    }
}

mmi_ret VappDialerCUIInstance::proc(mmi_event_struct *evt)
{
    if (EVT_ID_CUI_DIALER_CLOSE_REQ == evt->evt_id)
    {
        closeInstance();        
    }
	else if (EVT_ID_CUI_DIALER_CLOSED_IND == evt->evt_id)
	{
		m_id = 0;
	}
    return MMI_RET_OK;
}

#ifdef __MMI_COSMOS_APP_MANAGER__

#ifdef _AM_APP_TEST_
#define AM_APP_TEST_NUM 100
#endif //_AM_APP_TEST_

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
#ifdef _AM_TEST_
const wchar_t* AppName[] =
{
    L"À­À­",
    L"°¢",
    L"VApp",
    L"ANC",
    L"ABC",
    L"cbA",
    L"abc",
    L"±»",
    L"J°¢",
    L"JA",
    L"Wighet A",
    L"Wighet B",
    L"Wighet C",
    L"Wighet D",
    L"Wighet E",
};

const VfxU32 VappAMUTArrow::m_amUTFlagArrow[] = 
{
    VAPP_AM_TEST_UPDATING,
    VAPP_AM_TEST_RUNNING,
    VAPP_AM_TEST_INSTALLED,
    VAPP_AM_TEST_NOT_EXIST_CARD|VAPP_AM_TEST_MASSSTORAGE,
    VAPP_AM_TEST_NOT_EXIST_PHONE|VAPP_AM_TEST_MASSSTORAGE,
    VAPP_AM_TEST_NOT_EXIST_CARD,
    VAPP_AM_TEST_NOT_EXIST_PHONE,
    VAPP_AM_TEST_MASSSTORAGE,
    VAPP_AM_TEST_NO_MRE_UPDATE
};

VappAMUTArrow g_UT;

#endif //_AM_TEST_


const VfxId detail_info_list[] =
{
    STR_ID_VAPP_AM_DETAIL_INTRODUCE,
    STR_ID_VAPP_AM_DETAIL_SIZE,
    STR_ID_VAPP_AM_DETAIL_AUTHOR,
    STR_ID_VAPP_AM_DETAIL_COPYRIGHT,
    STR_ID_VAPP_AM_DETAIL_VERSION,
    STR_ID_VAPP_AM_DETAIL_AUTHORIZED,
    STR_ID_VAPP_AM_DETAIL_WEBSITE,
    STR_ID_VAPP_AM_DETAIL_NUMBER,
};


VfxId VappAMMainPage::m_pageId          = 1;
VfxId VappAMAppInfoPage::m_pageId       = 2;
VfxId VappAMSettingPage::m_pageId       = 3;
VfxId VappAMMRESettingPage::m_pageId    = 4;
#ifdef __GADGET_SUPPORT__
VfxId VappAMWGTSettingPage::m_pageId    = 5;
#endif //__GADGET_SUPPORT__


VscrPara                g_scrPara;

extern "C" mmi_ret vapp_app_manager_handle_evnet(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_format_event_struct *format_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN: 
        case EVT_ID_SRV_APPMGR_INSTALL_PACKAGE:
        case EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE:
            {
                if (g_pAppInfoList)
                {
                    g_pAppInfoList->fresh();
                }
                if (g_pWGTInfoList)
                {
                    g_pWGTInfoList->fresh();
                }
                
                VappAMMainSrc* pScr = VappAMApp::getMainScr();
                if (pScr)
                {
                    pScr->clearPopupStack();
#ifdef __J2ME__                    
                    pScr->closePage(g_mmi_vjava_advanced_permission_page);
                    pScr->closePage(g_mmi_vjava_advanced_setting_page);
#endif                    
                    pScr->closePage(VappAMAppInfoPage::m_pageId);
                    VappAMMainPage * pPage = (VappAMMainPage*)pScr->getPage(VappAMMainPage::m_pageId);
                    if (pPage)
                    {
                        pPage->update();
                    }
                }
            }
            break;
        default: 
            break;
    }
    return MMI_RET_OK;
}

/***************************************************************************** 
 * Class VscrPara
 *****************************************************************************/
VscrPara::VscrPara()
{
    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;
    
    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);
    m_size =  VfxSize(main_screen_size.width, main_screen_size.height);
}

VfxS32 VscrPara::width()
{
    return m_size.width;
}

VfxS32 VscrPara::height()
{
    return m_size.height;
}


//************************************************************************
//VappAMDataAccount class
//************************************************************************
VappAMDataAccount::VappAMDataAccount(VfxU32 type)
:m_pDAAdapter(NULL),m_type(0)
{
    if (VAPP_AM_DA_TYPE_WGT == type)
    {
        m_pDAAdapter = VappAdapterFactory::getDAAdapter(VAPP_AM_ADPTER_WGT);
    }
    else if (VAPP_AM_DA_TYPE_MRE == type)
    {
        m_pDAAdapter = VappAdapterFactory::getDAAdapter(VAPP_AM_ADPTER_MRE);        
    }
    else if (VAPP_AM_DA_TYPE_MRE_PROXY == type)
    {
        m_pDAAdapter = VappAdapterFactory::getDAAdapter(VAPP_AM_ADPTER_MRE); 
        m_type = VAPP_AM_MRE_DA_PROXY;
    }
    else
    {
#ifdef _AM_DATA_ACCOUNT_
        memset(&m_runData,0x00,sizeof(cui_dtcnt_select_run_struct));
        m_runData.bearers = DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_CSD; // bear type
//        m_runData.sim1_account_id = VAPP_DTCNT_AUTOMATIC_ID; // use last time selected sim1 account id
//        m_runData.sim2_account_id = VAPP_DTCNT_AUTOMATIC_ID; // use last time selected sim2 account id            
        m_runData.sim_selection = CUI_DTCNT_SELECT_SIM_ALL;// which sim card related account app want
        m_runData.option = CUI_DTCNT_SELECT_DEFAULT; // select option, add wap only option, others are the same to 10A
        m_runData.type = CUI_DTCNT_SELECT_TYPE_NORMAL; // type option, it is the same to 10A
#endif //_AM_DATA_ACCOUNT_
    }
    if (m_pDAAdapter)
    {
        m_pDAAdapter->getDataAccount(this, m_type);
    }
}

void VappAMDataAccount::show()
{
#ifdef _AM_DATA_ACCOUNT_
    m_mmiId = vcui_dtcnt_select_create(VappAMApp::m_mmiId);
    vcui_dtcnt_select_set_param(m_mmiId, &m_runData);
    vcui_dtcnt_select_run(m_mmiId);

    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND,onUpdate,this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_ACCT_DELETE_IND,onUpdate,this);
#endif //_AM_DATA_ACCOUNT_
}

void VappAMDataAccount::set()
{
    if (m_pDAAdapter)
    {
        m_pDAAdapter->setDataAccount(this, m_type);
    }
}

void VappAMDataAccount::close()
{
#ifdef _AM_DATA_ACCOUNT_
    vcui_dtcnt_select_close(m_mmiId);

    mmi_frm_cb_dereg_event(EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND,onUpdate,this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_DTCNT_ACCT_DELETE_IND,onUpdate,this);
#endif //_AM_DATA_ACCOUNT_
}

mmi_ret VappAMDataAccount::onUpdate(mmi_event_struct *param)
{
    VappAMDataAccount* pthis = (VappAMDataAccount*)param->user_data;
    if (pthis->isValid())
    {
        if (pthis->m_pDAAdapter)
        {
            pthis->m_pDAAdapter->getDataAccount(pthis, pthis->m_type);
        }
        for (int i = 0; i < (int)MMI_SIM_TOTAL; i++)
    	{
            vcui_dtcnt_select_set_account_id(pthis->m_mmiId, (cui_dtcnt_sim_enum)i, pthis->m_runData.sim_account_id[i]);
    	}
    }
    return MMI_RET_OK; 
}

mmi_ret VappAMDataAccount::onProc(mmi_event_struct *evt)
{
#ifdef _AM_DATA_ACCOUNT_
    
    switch(evt->evt_id)
    {
        case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:
        {
            cui_dtcnt_select_event_any_sim_selected_struct* dtcntEvt = (cui_dtcnt_select_event_any_sim_selected_struct*)evt;
            cui_dtcnt_sim_enum sim;
            sim = dtcntEvt->selectSim;
            m_runData.sim_account_id[sim] = dtcntEvt->accountId;
            set();
            break;
        }
        case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
        case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
        case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:
        case CUI_DTCNT_SELECT_EVENT_CLOSE:
            close();
            break;
        default:
            break;        
    }
#endif //_AM_DATA_ACCOUNT_
    return MMI_RET_OK;    
}


/***************************************************************************** 
 * Class VappAMItem
 *****************************************************************************/

VfxSize VappAMItem::m_itemSize = VfxSize(g_scrPara.width(),VAPP_AM_LIST_HEIGHT);

VFX_IMPLEMENT_CLASS("VappAMItem", VappAMItem, VcpListMenuCellClientBaseFrame);

VappAMItem::VappAMItem():m_pAppInfo(NULL)
{
}

VappAMItem::VappAMItem(VappInfo *pAppInfo):m_pAppInfo(pAppInfo)
{
}

VappAMItem::~VappAMItem()
{
    
}

void VappAMItem::onCreateElements()
{  
    VAPP_AM_TRACE2(VAPP_AM_CEATE_ELEMENT_BEGIN,m_pAppInfo->m_appID,Vapp_AM_UTF8_to_ASCII(m_pAppInfo->m_strApp));
    
    U32 xgap = VAPP_AM_LIST_MARGIN;
    U32 ygap = VAPP_AM_LIST_MARGIN;
    U32 x,y;
    
    setSize(m_itemSize);

    // create app icon background
/*    VfxImageFrame* bgFram;
    VFX_OBJ_CREATE(bgFram, VfxImageFrame, this);
    bgFram->setResId(VAPP_AM_IMG_APPICON_BG);
    bgFram->setAnchor(0.5,0.5);
    bgFram->setPos(x, y);*/
    
    x = VAPP_AM_LIST_APPICON_SIZE/2 + xgap;
    y = m_itemSize.height/2;
    
    
    // create app icon
    VFX_OBJ_CREATE(m_pAppIcon, VfxFrame, this);
    if (m_pAppInfo->m_iconId)
    {
        m_pAppIcon->setImgContent(VfxImageSrc(m_pAppInfo->m_iconId));
    }
    else if (m_pAppInfo->m_memPtr)
    {
        //VfxU8 type = (VfxU8)gdi_image_get_type_from_mem((PS8)m_pAppInfo->m_memPtr);
        m_pAppIcon->setImgContent(VfxImageSrc(m_pAppInfo->m_memPtr, m_pAppInfo->m_memLength));
    }
    else if (m_pAppInfo->m_wstrIconPath.isEmpty())
    {
        m_pAppIcon->setImgContent(VfxImageSrc(VAPP_AM_IMG_APPMANAGER));
    }
    else
    {
        m_pAppIcon->setImgContent(VfxImageSrc(m_pAppInfo->m_wstrIconPath));
    }
    m_pAppIcon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_pAppIcon->setIsCached(VFX_TRUE);
    m_pAppIcon->setBounds(0, 0, VAPP_AM_LIST_APPICON_SIZE, VAPP_AM_LIST_APPICON_SIZE);
    x = xgap;
    y = ygap;
    m_pAppIcon->setPos(x, y);


    VfxFontDesc fontDesc;      
     
    // create install time text
    VFX_OBJ_CREATE(m_pInstallTime, VfxTextFrame, this);
    m_pInstallTime->setString(m_pAppInfo->m_wstrInstallTime);
    m_pInstallTime->setColor(VFX_COLOR_RES(VAPP_AM_GREY));
    m_pInstallTime->setFont(VFX_FONT_DESC_SMALL);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_AM_LIST_APP_INSTALL_TIME_SIZE);
    m_pInstallTime->setFont(fontDesc);

    x = VAPP_AM_LIST_APPICON_SIZE + xgap*2;
    y = m_itemSize.height*3/5;
    m_pInstallTime->setPos(x, y);

    //create flag icons, these two icons have same size
    //icon presents storage position
    VfxU32 iconLength = 0;
    if(VappInfo::VAPP_AM_APP_POS_CARD == m_pAppInfo->m_storage)
    {
        VFX_OBJ_CREATE(m_pStorageIcon, VfxImageFrame, this);
        m_pStorageIcon->setResId(VAPP_AM_IMG_ON_CARD);
        
        x = m_itemSize.width - xgap - m_pStorageIcon->getSize().width - VAPP_AM_LIST_MARGIN_ICONS; 
        y = m_itemSize.height/2;
    
        m_pStorageIcon->setAnchor(1,0.5);
        m_pStorageIcon->setPos(x, y);
        
        iconLength = m_pStorageIcon->getSize().width + VAPP_AM_LIST_MARGIN_ICONS;
    }
    // 3 types of icons to present app type: pre-in,  download,  install
    VFX_OBJ_CREATE(m_pInstallTypeIcon, VfxImageFrame, this);
    VfxS32 imgId;
    if (VappInfo::VAPP_AM_APP_INSTALL_TYPE_INSTALL == m_pAppInfo->m_installtype)
    {
        imgId = VAPP_AM_IMG_LOCALINSTALL;
    }
    else if (VappInfo::VAPP_AM_APP_INSTALL_TYPE_DOWNLOAD == m_pAppInfo->m_installtype)
    {
        imgId = VAPP_AM_IMG_DOWNLOAD;
    }
    else
    {
        imgId = VAPP_AM_IMG_SYSTEM;
    }
    m_pInstallTypeIcon->setResId(imgId); 

    x = m_itemSize.width - xgap;
    y = m_itemSize.height/2;
    
    m_pInstallTypeIcon->setAnchor(1,0.5); 
    m_pInstallTypeIcon->setPos(x, y);

    iconLength += m_pInstallTypeIcon->getSize().width + 2*xgap;
    // create app name text
    x = VAPP_AM_LIST_APPICON_SIZE + xgap*2;
    y = m_itemSize.height*2/5;
    VfxU32 AppNameLength = m_itemSize.width - x - iconLength;
                           
    VFX_OBJ_CREATE(m_pAppName, VfxTextFrame, this);    
    m_pAppName->setSize(AppNameLength,VAPP_AM_LIST_APP_NAME_HEIGHT);
    m_pAppName->setAutoResized(VFX_FALSE);
    m_pAppName->setColor(VAPP_AM_BLACK);
    m_pAppName->setAnchor(0,0.5);
    m_pAppName->setPos(x, y);
    m_pAppName->setString(m_pAppInfo->m_wstrAppName);
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_AM_LIST_APP_NAME_SIZE);
    m_pAppName->setFont(fontDesc);
    m_pAppName->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    
    VAPP_AM_TRACE(VAPP_AM_CEATE_ELEMENT_END);
}
    
void VappAMItem::onCloseElements()
{
    
}
    
void VappAMItem::onLayoutElements()
{

}
    
void VappAMItem::onUpdateElements()
{
    // TODO: could update element here
    VcpListMenuCell* pCell = getCell();
    if (NULL == pCell)
    {
        return;
    }

    m_pAppName->setColor(pCell->getTextColor(VCP_LIST_MENU_TEXT_COLOR_NORMAL));
    m_pInstallTime->setColor(pCell->getTextColor(VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT));
}

VappInfo* VappAMItem::getAppInfo()
{
    return m_pAppInfo;
}


/***************************************************************************** 
 * Class VappAMListPage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappAMListMenu", VappAMListMenu, VcpListMenu);

VappAMListMenu::VappAMListMenu()
    :m_pAppInfoList(NULL)
{

}

VappAMListMenu::VappAMListMenu(VappInfoList* pInfoList)
    :m_pAppInfoList(pInfoList)
{

}

void VappAMListMenu::onInit()
{
    VcpListMenu::onInit();

    VappAMListMenuContentProvider* pProvider;
    VFX_OBJ_CREATE_EX(pProvider,VappAMListMenuContentProvider,this,(m_pAppInfoList));
    setContentProvider(pProvider);

    setItemHeight(VappAMItem::m_itemSize.height);
//    m_pAppInfoList->setRemoveNotifyFunction(this,(VappInfoList::NotifyFun)&VappAMListMenu::onRemoveItem);

    m_signalItemTapped.connect(this,&VappAMListMenu::onTap);
    m_signalItemLongTapped.connect(this,&VappAMListMenu::onLongTap);
}

void VappAMListMenu::onLongTap(VcpListMenu* pMenu, VfxU32 index)
{
    VfxObject*   pAppInfo = (VfxObject*)(*m_pAppInfoList)[index];
    m_signalLongTap.emit(pAppInfo);
}

void VappAMListMenu::onTap(VcpListMenu* pMenu, VfxU32 index)
{
    VfxObject*   pAppInfo = (VfxObject*)(*m_pAppInfoList)[index];
    m_signalTap.emit(pAppInfo);
}

void VappAMListMenu::onRemoveItem()
{
    resetAllItems(VFX_TRUE);
}


/***************************************************************************** 
 * Class VappAMListPage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappAMListPage", VappAMListPage, VfxPage);

VappAMListPage::VappAMListPage()
:m_pAppInfoList(NULL)
{

}

VappAMListPage::VappAMListPage(VappInfoList* pInfoList)
:m_pAppInfoList(pInfoList)
{

}

void VappAMListPage::onInit()
{
    VAPP_AM_TRACE(VAPP_AM_LIST_MENU_PAGE_INIT);
    
    VfxPage::onInit();
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    VFX_OBJ_CREATE_EX(m_pListMenu,VappAMListMenu,this,(m_pAppInfoList));
    m_pListMenu->setCacheLen(1000);
    m_pListMenu->setHidden(VFX_TRUE);
    VFX_OBJ_CREATE(m_pText,VfxTextFrame,this);
    m_pText->setColor(VAPP_AM_LOADING_GREY);
    m_pText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_AM_LIST_APP_NAME_SIZE)));
    m_pText->setString(VFX_WSTR_RES(STR_GLOBAL_LOADING)); 
    m_pText->setAutoResized(VFX_TRUE);
    m_pText->forceUpdate();

    m_pAppInfoList->setRemoveNotifyFunction(this,(VappInfoList::NotifyFun)&VappAMListPage::updatePage);
}

void VappAMListPage::updatePage()
{
    //get app list from service
    if (VAPP_AM_OK == m_pAppInfoList->getAppListFromSrv())
    {
        if (0 == m_pAppInfoList->getValidCount())
        {
            //no applications or widgets
            if (g_pAppInfoList == m_pAppInfoList)
            {
                m_pText->setString(VFX_WSTR_RES(STR_ID_VAPP_AM_NO_APPLICATIONS));    
            }
            else
            {
                m_pText->setString(VFX_WSTR_RES(STR_ID_VAPP_AM_NO_WIDGETS));
            }
            m_pText->setHidden(VFX_FALSE);
            m_pListMenu->setHidden(VFX_TRUE);
        }
        else
        {
            m_pText->setHidden(VFX_TRUE);
            m_pListMenu->setHidden(VFX_FALSE);
            m_pListMenu->resetAllItems(VFX_TRUE);
        }
    }
    else
    {
        //if error, it must be service not ready, so we get list after a while
        VfxTimer* pTimer;
        VFX_OBJ_CREATE(pTimer, VfxTimer, this);
        pTimer->setStartDelay(1000);
        pTimer->m_signalTick.connect(this,&VappAMListPage::onTime);
        pTimer->start();
        return;
    }
    
    if (m_pAppInfoList->m_pAdapter)
    {
        //in case srv start callback did not invoke yet
        m_pAppInfoList->m_pAdapter->m_startedSignal.connect(this,&VappAMListPage::updatePage);
        //update app need to update page
        m_pAppInfoList->m_pAdapter->m_updatedSignal.connect(this,&VappAMListPage::onUpdatePage);
    }
}

void VappAMListPage::setListBounds(const VfxRect& rect)
{
    m_pListMenu->setBounds(rect);
    m_pText->setAnchor(0.5,0.5);
    m_pText->setPos(rect.size.width/2,rect.size.height/2);
}
void VappAMListPage::setLongTapFunction(VfxObject* pObj, oFun fun)
{
    m_pListMenu->m_signalLongTap.connect(pObj, fun);
}

void VappAMListPage::setTapFunction(VfxObject* pObj, oFun fun)
{
    m_pListMenu->m_signalTap.connect(pObj, fun);
}

void VappAMListPage::onUpdatePage()
{
    m_pListMenu->resetAllItems(VFX_TRUE);
    VfxMainScr* pScr = getMainScr();
    if (pScr)
    {
        //if top page is the MRE detail information page, we need to update it
        VappAMAppInfoPage* pPage = (VappAMAppInfoPage*)pScr->getPage(pScr->getTopPageId());
        if (pPage->isKindOf(VFX_OBJ_CLASS_INFO(VappAMAppInfoPage))
            && VappInfo::VAPP_AM_APP_TYPE_MRE == pPage->m_pAppInfo->m_type)
        {
            pPage->m_pAppInfo->fresh();
            pPage->updatePage();
        }
    }
    
}

void VappAMListPage::onTime(VfxTimer *pTimer)
{
    VFX_OBJ_CLOSE(pTimer);
    if (this && this->isValid())
    {
        updatePage();
    }
}

/***************************************************************************** 
 * Class VappAMMainPage
 *****************************************************************************/
#ifdef _AM_FULL_SUPPORT_

VFX_IMPLEMENT_CLASS("VappAMMainPage", VappAMMainPage, VcpTabCtrlPage);

VappAMMainPage::VappAMMainPage()
:m_bFirstIn(VFX_TRUE)
{
    
}

void VappAMMainPage::onInit()
{  
    VAPP_AM_TRACE(VAPP_AM_MAIN_PAGE_INIT);
    
    VcpTabCtrlPage::onInit();
    
    //tool bar
    VcpToolBar* toolbar; 
    VFX_OBJ_CREATE(toolbar,VcpToolBar,this);
    toolbar->addItem(1, VFX_WSTR_RES(STR_ID_VAPP_AM_BTN_SETTINGS), VCP_IMG_TOOL_BAR_COMMON_ITEM_SETTING);  
    toolbar->m_signalButtonTap.connect(this, &VappAMMainPage::eventHandler);   
    setBottomBar(toolbar);  
        
    addTab(1, VFX_WSTR_RES(STR_ID_VAPP_AM_BTN_APPTAB), VcpStateImage(VAPP_AM_IMG_APP));
    addTab(2, VFX_WSTR_RES(STR_ID_VAPP_AM_BTN_WGTTAB), VcpStateImage(VAPP_AM_IMG_WIDGET));

    setCurrTab(1);
}

void VappAMMainPage::onEntered()
{    
    if (!m_bFirstIn)
    {
        return;
    }
    VfxTimer* pTimer;
    VFX_OBJ_CREATE(pTimer, VfxTimer, this);
    pTimer->setStartDelay(100);
    pTimer->m_signalTick.connect(this,&VappAMMainPage::onTime);
    pTimer->start();
    m_bFirstIn = VFX_FALSE;
}

void VappAMMainPage::onTabSwitched(VfxId tabId)
{
    if (2 == tabId)
    {
        VappAMListPage* pPage = (VappAMListPage*)getTabPage(2);
        vfxPostInvoke0(pPage,&VappAMListPage::updatePage);
    }
}

VfxPage *VappAMMainPage::onCreateTabPage(VfxId tabId) 
{ 
    VappAMListPage *pAmListpage = NULL; 
    //need to sub height of the tabbar
    VfxRect rect;
    // TODO:this function declared internal use, but i cant find any useful function else. So I use it!!
    rect = getPageRect();
    rect.origin.x = 0;
    rect.origin.y = 0;

    switch (tabId)
    {
    case 1:
        VFX_OBJ_CREATE_EX(pAmListpage, VappAMListPage, this, (g_pAppInfoList));
        pAmListpage->setLongTapFunction((VfxObject*)this,(oFun)&VappAMMainPage::onLongTap);
        pAmListpage->setTapFunction((VfxObject*)this,(oFun)&VappAMMainPage::onTap);
        pAmListpage->setListBounds(rect);
        break;
        
    case 2:
        VFX_OBJ_CREATE_EX(pAmListpage, VappAMListPage, this, (g_pWGTInfoList));        
        pAmListpage->setLongTapFunction((VfxObject*)this,(oFun)&VappAMMainPage::onLongTap);
        pAmListpage->setTapFunction((VfxObject*)this,(oFun)&VappAMMainPage::onTap);
        pAmListpage->setListBounds(rect);
        break;
        
    }
    return pAmListpage;        
};

void VappAMMainPage::eventHandler(VfxObject* pObj, VfxId id)
{
    //only setting event
    if (1 == id)
    {
        VappAMSettingPage* pPage;
        VFX_OBJ_CREATE(pPage, VappAMSettingPage, getMainScr());
        getMainScr()->pushPage(VappAMSettingPage::m_pageId, pPage);
    }
}


void VappAMMainPage::onTap(VfxObject* pObj)
{
    VappInfo* pAppInfo = (VappInfo*)pObj;
    VappAmUninstall* pUninstall;

    if (!pAppInfo->isExist())
    {
        //app do not exist!!!
        VFX_OBJ_CREATE_EX(pUninstall, VappAmUninstall, getMainScr(),(pAppInfo));
//        pUninstall->setAppInfo(pAppInfo);
        pUninstall->deleteApp();
    }
    else
    {
        VappAMAppInfoPage* pPage;
        VFX_OBJ_CREATE_EX(pPage, VappAMAppInfoPage, getMainScr(),(pAppInfo));
        pPage->showPage();
    }

}

void VappAMMainPage::onLongTap(VfxObject* pObj)
{
    VappInfo* pAppInfo = (VappInfo*)pObj;
    VappAmUninstall* pUninstall;
    //touch feedback
    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
    
    if (!pAppInfo->isExist())
    {
        //app do not exist!!!
        VFX_OBJ_CREATE_EX(pUninstall, VappAmUninstall, getMainScr(),(pAppInfo));
        pUninstall->deleteApp();      
    }
    else
    {
        VappAMMenuPopup* pPopup;
        VFX_OBJ_CREATE_EX(pPopup, VappAMMenuPopup, getMainScr(), (pAppInfo));
        pPopup->show(VFX_TRUE);
    }
}
//after main scr showed , we have some init and update list!
void VappAMMainPage::onTime(VfxTimer* pTime)
{
    VappAMApp::initApp();
    VappAMListPage* pPage = (VappAMListPage*)getTabPage(getCurrTab());
    vfxPostInvoke0(pPage,&VappAMListPage::updatePage);
}

void VappAMMainPage::update(void)
{
    VappAMListPage* pPage = (VappAMListPage*)getTabPage(getCurrTab());
    if (pPage)
    {
        vfxPostInvoke0(pPage,&VappAMListPage::updatePage);
    }
}
#else // _AM_FULL_SUPPORT_

VFX_IMPLEMENT_CLASS("VappAMMainPage", VappAMMainPage, VfxPage);

VappAMMainPage::VappAMMainPage()
:m_bFirstIn(VFX_TRUE)
{
    
}

void VappAMMainPage::onInit()
{  
    VAPP_AM_TRACE(VAPP_AM_MAIN_PAGE_INIT);
    
    VfxPage::onInit();
    //tile bar
    VcpTitleBar* pbar;
    VFX_OBJ_CREATE(pbar, VcpTitleBar, this);
    pbar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_AM_TITLE_MAIN_FULL));
    setTopBar(pbar); 

    //tool bar
    VcpToolBar* toolbar; 
    VFX_OBJ_CREATE(toolbar,VcpToolBar,this);
    toolbar->addItem(1, VFX_WSTR_RES(STR_ID_VAPP_AM_BTN_SETTINGS), VCP_IMG_TOOL_BAR_COMMON_ITEM_SETTING);  
    toolbar->m_signalButtonTap.connect(this, &VappAMMainPage::eventHandler);   
    setBottomBar(toolbar);
 
    VFX_OBJ_CREATE_EX(m_pAmListpage, VappAMListPage, this, (g_pAppInfoList));

    addChildFrame(m_pAmListpage);
    m_pAmListpage->setRect(getPageRect());
    
    m_pAmListpage->setLongTapFunction((VfxObject*)this,(oFun)&VappAMMainPage::onLongTap);
    m_pAmListpage->setTapFunction((VfxObject*)this,(oFun)&VappAMMainPage::onTap);
    m_pAmListpage->setListBounds(getPageRect());
    
    m_pAmListpage->setFocused(VFX_TRUE);
}

void VappAMMainPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);
    m_pAmListpage->processEnter(isBackward);
}

void VappAMMainPage::onEntered()
{    
    if (!m_bFirstIn)
    {
        return;
    }
    VfxTimer* pTimer;
    VFX_OBJ_CREATE(pTimer, VfxTimer, this);
    pTimer->setStartDelay(100);
    pTimer->m_signalTick.connect(this,&VappAMMainPage::onTime);
    pTimer->start();
    m_bFirstIn = VFX_FALSE;
}

void VappAMMainPage::eventHandler(VfxObject* pObj, VfxId id)
{
    //only setting event
    if (1 == id)
    {
        VappAMSettingPage* pPage;
        VFX_OBJ_CREATE(pPage, VappAMSettingPage, getMainScr());
        getMainScr()->pushPage(VappAMSettingPage::m_pageId, pPage);
    }
}


void VappAMMainPage::onTap(VfxObject* pObj)
{
    VappInfo* pAppInfo = (VappInfo*)pObj;
    VappAmUninstall* pUninstall;

    if (!pAppInfo->isExist())
    {
        //app do not exist!!!
        VFX_OBJ_CREATE_EX(pUninstall, VappAmUninstall, getMainScr(),(pAppInfo));
        pUninstall->deleteApp();
    }
    else
    {
        VappAMAppInfoPage* pPage;
        VFX_OBJ_CREATE_EX(pPage, VappAMAppInfoPage, getMainScr(),(pAppInfo));
        pPage->showPage();
    }
}

void VappAMMainPage::onLongTap(VfxObject* pObj)
{
    VappInfo* pAppInfo = (VappInfo*)pObj;
    VappAmUninstall* pUninstall;

    if (!pAppInfo->isExist())
    {
        //app do not exist!!!
        VFX_OBJ_CREATE_EX(pUninstall, VappAmUninstall, getMainScr(),(pAppInfo));
        pUninstall->deleteApp();      
    }
    else
    {
        VappAMMenuPopup* pPopup;
        VFX_OBJ_CREATE_EX(pPopup, VappAMMenuPopup, getMainScr(), (pAppInfo));
        pPopup->show(VFX_TRUE);
    }
}

//after main scr showed , we have some init and update list!
void VappAMMainPage::onTime(VfxTimer* pTime)
{
    VFX_OBJ_CLOSE(pTime);
    VappAMApp::initApp();
    m_pAmListpage->setListBounds(getPageRect());
    vfxPostInvoke0(m_pAmListpage,&VappAMListPage::updatePage);
}

void VappAMMainPage::update(void)
{
    if (m_pAmListpage)
    {
        vfxPostInvoke0(m_pAmListpage,&VappAMListPage::updatePage);
    }
}

#endif// _AM_FULL_SUPPORT_

/***************************************************************************** 
 * Class VappAMAppInfoItem
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappAMAppInfoItem", VappAMAppInfoItem, VcpFormItemBase);
void VappAMAppInfoItem::onInit()
{
    VcpFormItemBase::onInit();
    VfxFontDesc font;
    font.size = VFX_FONT_DESC_VF_SIZE(VAPP_AM_DETAIL_INFO_BIG_SIZE);
    VFX_OBJ_CREATE(m_pTitle,VfxTextFrame,this);
    m_pTitle->setFont(font);
    m_pTitle->setColor(VFX_COLOR_RES(VAPP_AM_BLACK));
    m_pTitle->setPos(VAPP_AM_DETAIL_MARGIN,0);
    
    font.size = VFX_FONT_DESC_VF_SIZE(VAPP_AM_DETAIL_INFO_SMALL_SIZE);
    
    VFX_OBJ_CREATE(m_pContent,VfxTextFrame,this);
    m_pContent->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    m_pContent->setPos(VAPP_AM_DETAIL_MARGIN,0);
    m_pContent->setBounds(VfxRect(0, 0, g_scrPara.width()-2*VAPP_AM_DETAIL_MARGIN, VAPP_AM_DETAIL_INFO_SMALL_SIZE));
    m_pContent->setAutoResized(VFX_TRUE);
    m_pContent->setFont(font);
    m_pContent->setColor(VFX_COLOR_RES(VAPP_AM_GREY));

    m_firstMargin = 0;
}

void VappAMAppInfoItem::setTitle(const VfxWString& wstrTitle)
{
    m_pTitle->setString(wstrTitle);
}

void VappAMAppInfoItem::setText(const VfxWString& wstrContent)
{
    m_pContent->setString(wstrContent);
}

void VappAMAppInfoItem::setFirst()
{
    m_firstMargin = VAPP_AM_DETAIL_MARGIN;
    m_pTitle->setPos(VAPP_AM_DETAIL_MARGIN,VAPP_AM_DETAIL_MARGIN);
}

void VappAMAppInfoItem::forceUpdate()
{
    m_pTitle->forceUpdate();
    
    VfxS32 height = m_pTitle->getSize().height + m_firstMargin;
    
    m_pContent->setPos(VAPP_AM_DETAIL_MARGIN, height);
    m_pContent->forceUpdate();
    height += m_pContent->getSize().height;
    setSize(g_scrPara.width(),height+VAPP_AM_DETAIL_GAP);
    invalidate();
}


/***************************************************************************** 
 * Class VappAMAppInfoKeyWord
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappAMAppInfoKeyWord", VappAMAppInfoKeyWord, VcpFormItemBase);

void VappAMAppInfoKeyWord::onInit()
{
    VcpFormItemBase::onInit();
    setSize(g_scrPara.width(),60);
    
    VfxFontDesc font;
    font.size = VFX_FONT_DESC_VF_SIZE(VAPP_AM_DETAIL_INFO_BIG_SIZE);
    VFX_OBJ_CREATE(m_pTitle,VfxTextFrame,this);
    m_pTitle->setFont(font);
    m_pTitle->setColor(VFX_COLOR_RES(VAPP_AM_BLACK));
    m_pTitle->setString(VFX_WSTR_RES(STR_ID_VAPP_AM_DETAIL_NUMBER));
    m_pTitle->setPos(VAPP_AM_DETAIL_MARGIN,0);
    m_pTitle->forceUpdate();
       
    VFX_OBJ_CREATE(m_pContent,VcpTextView,this);
    m_pContent->setPos(VAPP_AM_DETAIL_MARGIN,m_pTitle->getSize().height);
    m_pContent->setBounds(VfxRect(0, 0, getSize().width - 2*VAPP_AM_DETAIL_MARGIN, 0));
    m_pContent->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
    m_pContent->setAutoResized(VFX_TRUE);
    
    //   
    m_pContent->setKeyword(VCP_TEXT_KEYWORD_PHONENUMBER | VCP_TEXT_KEYWORD_URL);
    m_pContent->setColor(VCP_TEXT_NORMAL_TEXT_COLOR,VFX_COLOR_RES(VAPP_AM_GREY));
    m_pContent->m_signalKeywordClick.connect(this, &VappAMAppInfoKeyWord::onKeywordClicked);
}

void VappAMAppInfoKeyWord::setNumber(const VfxWString& wstrNumber)
{
    m_pTitle->setString(VFX_WSTR_RES(STR_ID_VAPP_AM_DETAIL_NUMBER));
    m_pContent->setText(wstrNumber);

    VfxFontDesc font;
    font.size = VFX_FONT_DESC_VF_SIZE(VAPP_AM_DETAIL_INFO_SMALL_SIZE);
    m_pContent->setFont(font);
    //
    m_pTitle->forceUpdate();
    
    VfxS32 height = m_pTitle->getSize().height;
    
    m_pContent->setPos(VAPP_AM_DETAIL_MARGIN, height);
    m_pContent->forceUpdate();
    height += m_pContent->getSize().height;
    setSize(g_scrPara.width(),height+VAPP_AM_DETAIL_GAP);
    invalidate();

}

void VappAMAppInfoKeyWord::setWebsize(const VfxWString& wstrWeb)
{
    m_pTitle->setString(VFX_WSTR_RES(STR_ID_VAPP_AM_DETAIL_WEBSITE));
    m_pContent->setText(wstrWeb);

    VfxFontDesc font;
    font.size = VFX_FONT_DESC_VF_SIZE(VAPP_AM_DETAIL_INFO_SMALL_SIZE);
    m_pContent->setFont(font);
    //
    m_pTitle->forceUpdate();
    
    VfxS32 height = m_pTitle->getSize().height;
    
    m_pContent->setPos(VAPP_AM_DETAIL_MARGIN, height);
    m_pContent->forceUpdate();
    height += m_pContent->getSize().height;
    setSize(g_scrPara.width(),height+VAPP_AM_DETAIL_GAP);
    invalidate();
}

void VappAMAppInfoKeyWord::onKeywordClicked(VcpTextKeyWordEnum mode, VfxWChar *text, VfxS32 len)
{
    //make a call
    if (VCP_TEXT_KEYWORD_PHONENUMBER == mode)
    {
        VfxWChar number[SRV_UCM_MAX_NUM_URI_LEN]={0};
        getPureNumber(text,number);

        VappDialerCUIInstance::runInstance(VFX_WSTR_MEM(number));
    }
    else if (VCP_TEXT_KEYWORD_URL == mode)
    {
#ifdef BROWSER_SUPPORT    
        wap_start_browser(WAP_BROWSER_GOTO_URL,(const U8*)text);
#endif        
    }
}

void VappAMAppInfoKeyWord::getPureNumber(VfxWChar* text, VfxWChar* outNumber)
{
    VfxU32 limit = 0;
    
    while (0 != *text && limit < SRV_UCM_MAX_NUM_URI_LEN)
    {
        if (*text >= 0x30 && *text <= 0x39)
        {
            *outNumber++ = *text;
        }
        text++;
        limit++;
    }
}


/***************************************************************************** 
 * Class VappAMAppInfoPage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappAMAppInfoPage", VappAMAppInfoPage, VfxPage);

VappAMAppInfoPage::VappAMAppInfoPage()
{
}

VappAMAppInfoPage::VappAMAppInfoPage(VappInfo* pAppInfo)
:m_pAppInfo(pAppInfo),m_pForm(NULL)
{   
}

void VappAMAppInfoPage::onInit()
{
    VAPP_AM_TRACE(VAPP_AM_INFO_PAGE_INIT);
    
    VfxPage::onInit();
    
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    //tile bar
    VcpTitleBar* pbar;
    VFX_OBJ_CREATE(pbar, VcpTitleBar, this);
    pbar->setTitle(m_pAppInfo->m_wstrAppName);
    setTopBar(pbar);  
    
    //tool bar
    m_pToolBar = NULL;
    if (m_pAppInfo->m_bUpdatable || m_pAppInfo->m_bUninstallable
            || VappInfo::VAPP_AM_APP_TYPE_JAVA == m_pAppInfo->m_type)
    {
        VFX_OBJ_CREATE(m_pToolBar,VcpToolBar,this);
        if (m_pAppInfo->m_bUpdatable)
        {
            m_pToolBar->addItem(1, VFX_WSTR_RES(STR_ID_VAPP_AM_BTN_CHECK_UPDATE), VAPP_AM_IMG_UPDATE);
        }
        if (m_pAppInfo->m_bUninstallable)
        {
            m_pToolBar->addItem(2, VFX_WSTR_RES(STR_ID_VAPP_AM_BTN_UNINSTALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
        }
        if (VappInfo::VAPP_AM_APP_TYPE_JAVA == m_pAppInfo->m_type)
        {
            m_pToolBar->addItem(3, VFX_WSTR_RES(STR_ID_VAPP_AM_BTN_ADV_SETTINGS), 
                                        VCP_IMG_TOOL_BAR_COMMON_ITEM_SETTING); 
#ifdef OGDR_SECURITY_SETTING
            m_pToolBar->addItem(4, VFX_WSTR_RES(STR_GLOBAL_RESTORE),
                                        VCP_IMG_TOOL_BAR_COMMON_ITEM_RESTORE);
#endif
        }
        m_pToolBar->m_signalButtonTap.connect(this, &VappAMAppInfoPage::eventHandler);   
        setBottomBar(m_pToolBar);
    }
    
}

void VappAMAppInfoPage::eventHandler(VfxObject* pObj, VfxId id)
{
#ifdef __J2ME__
    VappJavaMIDDetailControllor* pJavaCtl;
#endif
    VappAmUninstall* pUninstall;
    VappAmUpdate* pUpdate;
    
    if( m_pToolBar == (VcpToolBar*)pObj)
    {
        switch (id)
        {
            case 1:
                //update
                VFX_OBJ_CREATE_EX(pUpdate, VappAmUpdate, getMainScr(),(m_pAppInfo));                
                pUpdate->update();
                break;
                
            case 2:
                //uninstall
                VFX_OBJ_CREATE_EX(pUninstall, VappAmUninstall, getMainScr(),(m_pAppInfo));
                pUninstall->setNotifyFunction(this,(VappAmUninstall::notifyFunc)&VappAMAppInfoPage::onUninstall);              
                pUninstall->uninstall();                
                break;
                
            case 3:
#ifdef __J2ME__
                VAPP_AM_TRACE(VAPP_AM_ENTER_JAVA_SETTINGS);
                
                VFX_OBJ_CREATE(pJavaCtl, VappJavaMIDDetailControllor, VappAMApp::getMainScr());
                pJavaCtl->midsSettingHandler(m_pAppInfo->m_strApp,VappAMApp::getMainScr());
                
#endif
                break;
#ifdef OGDR_SECURITY_SETTING
            case 4:
#ifdef __J2ME__                
                VFX_OBJ_CREATE(pJavaCtl, VappJavaMIDDetailControllor, VappAMApp::getMainScr());
                pJavaCtl->midsRestoreHandler(m_pAppInfo->m_strApp,VappAMApp::getMainScr());
#endif                
                break;
#endif

            default:
                break;
        }
    }
}

void VappAMAppInfoPage::onUninstall(VfxS32 bRet)
{
    if (VAPP_AM_OK == bRet)
    {
        //app has uninstalled, need to exit this page
        getMainScr()->popPage();
    }
    else
    {
        //uninstalled failed, what should i do?
        // TODO: deal with failure? 
    }
}

void VappAMAppInfoPage::updatePage()
{
    //after app updated, may need to update page
    if (this->isValid())
    {
        m_pAppInfo->getAppInfo();
        m_pAppInfo->getAppDetailInfo();        
        updateInfo();
    }
}

void VappAMAppInfoPage::onUpdateInfo()
{
    if (this->isValid())
    {
        updateInfo();
        getMainScr()->pushPage(m_pageId,this);
    }
}

void VappAMAppInfoPage::showPage()
{
    m_pAppInfo->m_pAdapter->m_getInfoSignal.connect(this,&VappAMAppInfoPage::onUpdateInfo);
    if (VAPP_AM_OK == m_pAppInfo->getAppDetailInfo())
    {
        //already got detail info
        updateInfo();
        getMainScr()->pushPage(m_pageId,this);
    }
    //else  callback functions will show this page for us
    
}

void VappAMAppInfoPage::updateInfo()
{
    VFX_OBJ_CLOSE(m_pForm);
    VFX_OBJ_CREATE(m_pForm, VcpForm, this);
    
    m_pForm->setPos(0,0);
    m_pForm->setSize(getSize());
    
    m_pForm->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE, 
                VFX_FRAME_ALIGNER_MODE_SIDE, 
                VFX_FRAME_ALIGNER_MODE_SIDE, 
                VFX_FRAME_ALIGNER_MODE_SIDE);
    
    VfxU32  itemIndex = 0;
    VappAMAppInfoItem* pText;
    VFX_OBJ_CREATE(pText,VappAMAppInfoItem,m_pForm);
    pText->setTitle(VFX_WSTR_RES(STR_ID_VAPP_AM_DETAIL_APPNAME));
    pText->setText(m_pAppInfo->m_wstrAppName);
    pText->setFirst();
    pText->forceUpdate();
    m_pForm->addItem(pText, itemIndex++);

    VFX_OBJ_CREATE(pText,VappAMAppInfoItem,m_pForm);
    pText->setTitle(VFX_WSTR_RES(STR_ID_VAPP_AM_DETAIL_INSTALLTIME));
    pText->setText(m_pAppInfo->m_wstrInstallTime);
    pText->forceUpdate();
    m_pForm->addItem(pText, itemIndex++);

    VFX_OBJ_CREATE(pText,VappAMAppInfoItem,m_pForm);
    pText->setTitle(VFX_WSTR_RES(STR_ID_VAPP_AM_DETAIL_STORAGE));
    if (0 == m_pAppInfo->m_storage)
    {
        pText->setText(VFX_WSTR_RES(STR_ID_VAPP_AM_DETAIL_PHONE)); 
    }
    else if(1 == m_pAppInfo->m_storage)
    {
        pText->setText(VFX_WSTR_RES(STR_ID_VAPP_AM_DETAIL_CARD));  
    }
    pText->forceUpdate();
    m_pForm->addItem(pText, itemIndex++);
    
    VappDetailInfo* pInfo = m_pAppInfo->m_pDetailInfoList;
    while (pInfo != NULL)
    {
        if (VappDetailInfo::VAPP_AM_DETAIL_INFO_NUMBER == pInfo->m_type)
        {
            VappAMAppInfoKeyWord* pNumber;
            VFX_OBJ_CREATE(pNumber,VappAMAppInfoKeyWord,m_pForm);
            pNumber->setNumber(pInfo->m_wstrContent);
            m_pForm->addItem(pNumber,itemIndex++);
        }
        else if (VappDetailInfo::VAPP_AM_DETAIL_INFO_WEBSITE == pInfo->m_type)
        {
            VappAMAppInfoKeyWord* pWeb;
            VFX_OBJ_CREATE(pWeb,VappAMAppInfoKeyWord,m_pForm);
            pWeb->setWebsize(pInfo->m_wstrContent);
            m_pForm->addItem(pWeb,itemIndex++);
        }
        else
        {
            VFX_OBJ_CREATE(pText,VappAMAppInfoItem,m_pForm);
            pText->setTitle(VFX_WSTR_RES(detail_info_list[pInfo->m_type]));
            pText->setText(pInfo->m_wstrContent);
            pText->forceUpdate();
            m_pForm->addItem(pText, itemIndex++);            
        }
        pInfo = pInfo->m_next;
    }

    checkUpdate();
}


mmi_ret VappAMAppInfoPage::onProc(mmi_event_struct *evt)
{
    return VappDialerCUIInstance::proc(evt);
}

/***************************************************************************** 
 * Class VappAMSettingPage
 *****************************************************************************/
#ifdef _AM_BACK_DOOR_
extern "C" void vtst_rt_main_entry(void);
#endif    

VFX_IMPLEMENT_CLASS("VappAMSettingPage", VappAMSettingPage, VfxPage);

VappAMSettingPage::VappAMSettingPage()
{
}

void VappAMSettingPage::onInit()
{
    VAPP_AM_TRACE(VAPP_AM_SETTING_PAGE_INIT);
    
    VfxPage::onInit();
    //tile bar
    VcpTitleBar* pbar;
    VFX_OBJ_CREATE(pbar, VcpTitleBar, this);
    pbar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_AM_TITLE_SETTINGS));
    setTopBar(pbar);

    VcpForm* pForm;
    VFX_OBJ_CREATE(pForm, VcpForm, this);
    pForm->setPos(0,0);
    pForm->setSize(g_scrPara.width(), g_scrPara.height());
    
    //VcpFormItemLauncherCell *setting;
    VcpFormItemLauncherCell* pCell;
        
	VFX_OBJ_CREATE(pCell, VcpFormItemLauncherCell, pForm);
	pCell->setMainText(VFX_WSTR_RES(STR_ID_VAPP_AM_SETTINGS_MRE));
	pCell->setHintText(VFX_WSTR_RES(STR_ID_VAPP_AM_SETTINGS_MRE_L));
	pCell->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    pCell->m_signalTap.connect(this, &VappAMSettingPage::eventHandler);
    pForm->addItem(pCell, 0);   
#ifdef _J2ME_SUPPORT_SETTING_
    VFX_OBJ_CREATE(pCell, VcpFormItemLauncherCell, pForm);
	pCell->setMainText(VFX_WSTR_RES(STR_ID_VAPP_AM_SETTINGS_JAVA));
	pCell->setHintText(VFX_WSTR_RES(STR_ID_VAPP_AM_SETTINGS_JAVA_L));
	pCell->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    pCell->m_signalTap.connect(this, &VappAMSettingPage::eventHandler);
    pForm->addItem(pCell, 1);
#endif    
#ifdef __GADGET_SUPPORT__ 
    VFX_OBJ_CREATE(pCell, VcpFormItemLauncherCell, pForm);
	pCell->setMainText(VFX_WSTR_RES(STR_ID_VAPP_AM_SETTINGS_WGT));
	pCell->setHintText(VFX_WSTR_RES(STR_ID_VAPP_AM_SETTINGS_WGT_L));
	pCell->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    pCell->m_signalTap.connect(this, &VappAMSettingPage::eventHandler);
    pForm->addItem(pCell, 2);
#endif   
#ifdef _AM_BACK_DOOR_
    VFX_OBJ_CREATE(pCell, VcpFormItemLauncherCell, pForm);
	pCell->setMainText(VFX_WSTR("Install MRE app"));
	pCell->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    pCell->m_signalTap.connect(this, &VappAMSettingPage::eventHandler);
    pForm->addItem(pCell, 3);

    VFX_OBJ_CREATE(pCell, VcpFormItemLauncherCell, pForm);
	pCell->setMainText(VFX_WSTR("File Manager"));
	pCell->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    pCell->m_signalTap.connect(this, &VappAMSettingPage::eventHandler);
    pForm->addItem(pCell, 4);
#endif
}

void VappAMSettingPage::eventHandler(VcpFormItemCell* sender, VfxId id)
{

    VappAMMRESettingPage* pMREPage;   
#ifdef __GADGET_SUPPORT__     
    VappAMWGTSettingPage* pWGTPage; 
#endif    
    //Java support this page!
#ifdef _J2ME_SUPPORT_SETTING_    
    VappJavaGolbalSettingPage* pJavaPage;
#endif    
    switch (id)
    {    
        case 0://MRE setting  
        
            VFX_OBJ_CREATE(pMREPage, VappAMMRESettingPage, getMainScr());
            getMainScr()->pushPage(VappAMMRESettingPage::m_pageId, pMREPage);            
            break;

        case 1://java setting
#ifdef _J2ME_SUPPORT_SETTING_          
            VFX_OBJ_CREATE(pJavaPage, VappJavaGolbalSettingPage, getMainScr());
            getMainScr()->pushPage(100, pJavaPage);
#endif            
            break;
             
        case 2://wighet setting
#ifdef __GADGET_SUPPORT__        
            VFX_OBJ_CREATE(pWGTPage, VappAMWGTSettingPage, getMainScr());
            getMainScr()->pushPage(VappAMWGTSettingPage::m_pageId, pWGTPage);
#endif            
            break;
            
#ifdef _AM_BACK_DOOR_
        case 3:
            srv_MRE_appmgr_preinstall_app();
            break;

        case 4:
            vtst_rt_main_entry();
            break;
            
#endif
        default:
            break;
    }
}


/***************************************************************************** 
 * Class VappAMMRESettingPage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappAMMRESettingPage", VappAMMRESettingPage, VfxPage);

VappAMMRESettingPage::VappAMMRESettingPage()
#ifdef __MMI_MRE_DTCNT_SETTING__
:m_pDataAccount(NULL),m_pDataAccountPx(NULL),m_pCurDataAccount(NULL)
#endif
{
}

void VappAMMRESettingPage::onInit()
{
    VAPP_AM_TRACE(VAPP_AM_MRE_SETTING_PAGE_INIT);
    
    VfxPage::onInit();
    //tile bar
    VcpTitleBar* pbar;
    VFX_OBJ_CREATE(pbar, VcpTitleBar, this);
    pbar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_AM_SETTINGS_MRE));
    setTopBar(pbar);

    VcpForm* pForm;
    VFX_OBJ_CREATE(pForm, VcpForm, this);
    pForm->setPos(0,0);
    pForm->setSize(g_scrPara.width(), g_scrPara.height());
    
    //Network settings caption
    VfxU32 index = 0;
#ifdef __MMI_MRE_DTCNT_SETTING__  
    VcpFormItemCaption* pCaption;
    VFX_OBJ_CREATE(pCaption, VcpFormItemCaption, pForm);
    pCaption->setText(VFX_WSTR_RES(STR_ID_VAPP_AM_CAPTION_NEWWORK));
    pCaption->setStyle(VCPFORM_STYLE1);
    pForm->addItem(pCaption, index++);

    VappMREInfoAdapter* pAdptor = VappMREInfoAdapter::getInstance();   
    pAdptor->getSettings(&m_settings);
    
    //Wi-Fi Setting cell
#if _AM_WIFI_ONLY_//remove wifi only  
	VFX_OBJ_CREATE(m_wifiSetting, VcpFormItemSwitchCell, pForm);
	m_wifiSetting->setMainText(VFX_WSTR_RES(STR_ID_VAPP_AM_SETTINGS_WLAN));
	m_wifiSetting->setHintText(VFX_WSTR_RES(STR_ID_VAPP_AM_SETTINGS_WLAN_L));
	m_wifiSetting->setSwitchStatus(m_settings.m_bWiFiOnly);
	m_wifiSetting->setIsTappable(VFX_FALSE);
	m_wifiSetting->m_signalSwitchChangeReq.connect(this, &VappAMMRESettingPage::switchHandler);
    pForm->addItem(m_wifiSetting, index++);
#endif   
    //
    VfxBool bDisable = !srv_sim_ctrl_any_sim_is_available();
	VFX_OBJ_CREATE(m_pDACellPx, VcpFormItemLauncherCell, pForm);
	m_pDACellPx->setMainText(VFX_WSTR_RES(STR_ID_VAPP_AM_SETTINGS_DATAACCOUNT));
	m_pDACellPx->setHintText(VFX_WSTR_RES(STR_ID_VAPP_AM_SETTINGS_PROXY));
	m_pDACellPx->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_pDACellPx->m_signalTap.connect(this, &VappAMMRESettingPage::eventHandler);
    pForm->addItem(m_pDACellPx, index++);
    m_pDACellPx->setIsDisabled(bDisable);
    
    VFX_OBJ_CREATE(m_pDACell, VcpFormItemLauncherCell, pForm);
	m_pDACell->setMainText(VFX_WSTR_RES(STR_ID_VAPP_AM_SETTINGS_DATAACCOUNT));
	m_pDACell->setHintText(VFX_WSTR_RES(STR_ID_VAPP_AM_SETTINGS_NO_PROXY));
	m_pDACell->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_pDACell->m_signalTap.connect(this, &VappAMMRESettingPage::eventHandler);
    pForm->addItem(m_pDACell, index++);
    m_pDACell->setIsDisabled(bDisable);
#endif //__MMI_MRE_DTCNT_SETTING__
    VcpFormItemCaption* pMREVersion;
    VFX_OBJ_CREATE(pMREVersion, VcpFormItemCaption, pForm);
    pMREVersion->setText(VFX_WSTR_RES(STR_ID_VAPP_AM_DETAIL_VERSION));
    pMREVersion->setStyle(VCPFORM_STYLE1);
    pForm->addItem(pMREVersion, index++);
    
    WCHAR tmpbuf[64];
    VcpFormItemCell* pVersionCell;
    VFX_OBJ_CREATE(pVersionCell, VcpFormItemCell, pForm);
	kal_wsprintf(tmpbuf,"%d.%d.%02d",MRE_VERSION/1000,(MRE_VERSION%1000)/100,MRE_VERSION%100);
	pVersionCell->setMainText(VFX_WSTR_MEM(tmpbuf));
	pVersionCell->setIsTappable(VFX_FALSE);
    pForm->addItem(pVersionCell, index++);
}
#ifdef __MMI_MRE_DTCNT_SETTING__ 

void VappAMMRESettingPage::eventHandler(VcpFormItemCell* sender, VfxId id)
{
    if (id == m_pDACellPx->getId())
    {
        if (!m_pDataAccountPx)
        {
            VFX_OBJ_CREATE_EX(m_pDataAccountPx, VappAMDataAccount, this, (VappAMDataAccount::VAPP_AM_DA_TYPE_MRE_PROXY));            
        }
        m_pCurDataAccount = m_pDataAccountPx;
        m_pDataAccountPx->show();
    }
    else
    {
        if (!m_pDataAccount)
        {
            VFX_OBJ_CREATE_EX(m_pDataAccount, VappAMDataAccount, this, (VappAMDataAccount::VAPP_AM_DA_TYPE_MRE));            
        }
        m_pCurDataAccount = m_pDataAccount;
        m_pDataAccount->show();
    }
}

#endif //__MMI_MRE_DTCNT_SETTING__ 

#if _AM_WIFI_ONLY_ //remove wifi only
void VappAMMRESettingPage::switchHandler(VcpFormItemSwitchCell* sender, VfxId id, VfxBool bState)
{
    if (id == m_wifiSetting->getId())
    {
        m_wifiSetting->setSwitchStatus(!m_wifiSetting->getSwitchStatus());
        m_settings.m_bWiFiOnly = m_wifiSetting->getSwitchStatus();
        
        VappMREInfoAdapter* pAdptor = VappMREInfoAdapter::getInstance();   
        pAdptor->setSettings(&m_settings);
        //should disable Default Data Account

        m_pDACellPx->setIsDisabled(m_settings.m_bWiFiOnly);
        m_pDACell->setIsDisabled(m_settings.m_bWiFiOnly);
    }    
}
#endif

#ifdef __MMI_MRE_DTCNT_SETTING__

mmi_ret VappAMMRESettingPage::onProc(mmi_event_struct *evt)
{
    if (m_pCurDataAccount)
    {
        return m_pCurDataAccount->onProc(evt);
    }
    return MMI_RET_OK;
}
#endif


#ifdef __GADGET_SUPPORT__ 
/***************************************************************************** 
 * Class VappAMWGTSettingPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappAMWGTSettingPage", VappAMWGTSettingPage, VfxPage);

VappAMWGTSettingPage::VappAMWGTSettingPage()
:m_pDataAccount(NULL)
{
}

void VappAMWGTSettingPage::onInit()
{
    VAPP_AM_TRACE(VAPP_AM_WGT_SETTING_PAGE_INIT);
    
    VfxPage::onInit();
    //tile bar
    VcpTitleBar* pbar;
    VFX_OBJ_CREATE(pbar, VcpTitleBar, this);
    pbar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_AM_SETTINGS_WGT));
    setTopBar(pbar);

    VcpForm* pForm;
    VFX_OBJ_CREATE(pForm, VcpForm, this);
    pForm->setPos(0,0);
    pForm->setSize(g_scrPara.width(), g_scrPara.height());

    //Network settings caption
    VfxU32  index = 0;
    VcpFormItemCaption* pCaption;
    VFX_OBJ_CREATE(pCaption, VcpFormItemCaption, pForm);
    pCaption->setText(VFX_WSTR_RES(STR_ID_VAPP_AM_CAPTION_NEWWORK));
    pCaption->setStyle(VCPFORM_STYLE1);
    pForm->addItem(pCaption, index++);
  
    VappWidgetInfoAdapter* pAdptor = VappWidgetInfoAdapter::getInstance();   
    pAdptor->getSettings(&m_settings);

    //NetAccess Setting cell
	VFX_OBJ_CREATE(m_netAccess, VcpFormItemSwitchCell, pForm);
	m_netAccess->setMainText(VFX_WSTR_RES(STR_ID_VAPP_AM_SETTINGS_NEWWORK));
	m_netAccess->setHintText(VFX_WSTR_RES(STR_ID_VAPP_AM_SETTINGS_NEWWORK_L));
	m_netAccess->setSwitchStatus(m_settings.m_bNetWork);
	m_netAccess->setIsTappable(VFX_FALSE);
	m_netAccess->m_signalSwitchChangeReq.connect(this, &VappAMWGTSettingPage::switchHandler);
    pForm->addItem(m_netAccess, index++);
    
    //Wi-Fi Setting cell
#if _AM_WIFI_ONLY_ //remove wifi only    
	VFX_OBJ_CREATE(m_wifiSetting, VcpFormItemSwitchCell, pForm);
	m_wifiSetting->setMainText(VFX_WSTR_RES(STR_ID_VAPP_AM_SETTINGS_WLAN));
	m_wifiSetting->setHintText(VFX_WSTR_RES(STR_ID_VAPP_AM_SETTINGS_WLAN_L));
	m_wifiSetting->setSwitchStatus(m_settings.m_bWiFiOnly);
	m_wifiSetting->setIsTappable(VFX_FALSE);
	m_wifiSetting->m_signalSwitchChangeReq.connect(this, &VappAMWGTSettingPage::switchHandler);
    pForm->addItem(m_wifiSetting, index++);
#endif   
    //Data Account cell    
    VfxBool bDisable = !srv_sim_ctrl_any_sim_is_available();
	VFX_OBJ_CREATE(m_pDACell, VcpFormItemLauncherCell, pForm);
	m_pDACell->setMainText(VFX_WSTR_RES(STR_ID_VAPP_AM_SETTINGS_DATAACCOUNT));
	m_pDACell->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_pDACell->m_signalTap.connect(this, &VappAMWGTSettingPage::eventHandler);
    pForm->addItem(m_pDACell, index++);
    m_pDACell->setIsDisabled(bDisable);

}

void VappAMWGTSettingPage::eventHandler(VcpFormItemCell* sender, VfxId id)
{
    //Data Account 
    if (!m_pDataAccount)
    {
        VFX_OBJ_CREATE(m_pDataAccount, VappAMDataAccount, this);  
    }
    m_pDataAccount->show();     
}

void VappAMWGTSettingPage::switchHandler(VcpFormItemSwitchCell* sender, VfxId id, VfxBool bState)
{
    if (id == m_netAccess->getId())
    {
        //NetAccess Setting
        m_netAccess->setSwitchStatus(!m_netAccess->getSwitchStatus());
        m_settings.m_bNetWork = m_netAccess->getSwitchStatus();
    }
#if _AM_WIFI_ONLY_ //remove wifi only    
    else if (id == m_wifiSetting->getId())
    {
        //Wi-Fi Setting
        m_wifiSetting->setSwitchStatus(!m_wifiSetting->getSwitchStatus());
        m_settings.m_bWiFiOnly = m_wifiSetting->getSwitchStatus();

        m_pDACell->setIsDisabled(m_settings.m_bWiFiOnly);
    }
#endif    
    VappWidgetInfoAdapter* pAdptor = VappWidgetInfoAdapter::getInstance();   
    pAdptor->setSettings(&m_settings);
}

mmi_ret VappAMWGTSettingPage::onProc(mmi_event_struct *evt)
{
    if (m_pDataAccount)
    {
        return m_pDataAccount->onProc(evt); 
    }
    return MMI_RET_OK;
}

#endif //__GADGET_SUPPORT__
/***************************************************************************** 
 * Class VappAMMenuPopup
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappAMMenuPopup", VappAMMenuPopup, VcpMenuPopup);

VappAMMenuPopup::VappAMMenuPopup(VappInfo* pAppInfo)
:m_pAppInfo(pAppInfo)
{
}

void VappAMMenuPopup::onInit()
{
    VAPP_AM_TRACE(VAPP_AM_MENU_POPUP_INIT);
    
    VcpMenuPopup::onInit();

    setTitle(m_pAppInfo->m_wstrAppName);

    addItem(1,VFX_WSTR_RES(STR_ID_VAPP_AM_BTN_DETAIL));
    
    if (m_pAppInfo->m_bUpdatable)
    {

        addItem(2,VFX_WSTR_RES(STR_ID_VAPP_AM_BTN_CHECK_UPDATE));
    }
    
    if (m_pAppInfo->m_bUninstallable)
    {
        addItem(3,VFX_WSTR_RES(STR_ID_VAPP_AM_BTN_UNINSTALL));
    }
    
    if (VappInfo::VAPP_AM_APP_TYPE_JAVA == m_pAppInfo->m_type)
    {
        addItem(4,VFX_WSTR_RES(STR_ID_VAPP_AM_BTN_ADV_SETTINGS));
    }

    m_signalMenuCallback.connect(this,&VappAMMenuPopup::onSelect);

}

void VappAMMenuPopup::onSelect(VcpMenuPopup* pMenu, VcpMenuPopupEventEnum event, VcpMenuPopupItem* item)
{
    if (this != (VappAMMenuPopup*)pMenu)
        return;

    if (VCP_MENU_POPUP_EVENT_ITEM_SELECTED != event)
        return;
        
    VappAMAppInfoPage* pPage;
    VappAmUpdate* pUpdate;
    VappAmUninstall* pUninstall;
#ifdef __J2ME__    
    VappJavaMIDDetailControllor* pJavaCtl;
#endif
    switch (item->getId())
    {
        case 1:                
            VFX_OBJ_CREATE_EX(pPage, VappAMAppInfoPage, getParent(),(m_pAppInfo));
            //((VfxMainScr*)getParent())->pushPage(VappAMAppInfoPage::m_pageId, pPage);
            pPage->showPage();
            break;
            
        case 2:

            VFX_OBJ_CREATE_EX(pUpdate, VappAmUpdate, getParent(),(m_pAppInfo));
            pUpdate->update();
            break;
            
        case 3:               
            VFX_OBJ_CREATE_EX(pUninstall, VappAmUninstall, getParent(),(m_pAppInfo));
            pUninstall->uninstall();
            break;
            
        case 4:
#ifdef __J2ME__
            VAPP_AM_TRACE(VAPP_AM_ENTER_JAVA_SETTINGS);
            
            VFX_OBJ_CREATE(pJavaCtl, VappJavaMIDDetailControllor, getParent());
            pJavaCtl->midsSettingHandler(m_pAppInfo->m_strApp,(VfxMainScr*)getParent());
            VFX_OBJ_CLOSE(pJavaCtl);
#endif        
            break;

        default:
            break;
    }
}

/***************************************************************************** 
 * Class VappAmDeleteBasePopup
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappAmDeleteBasePopup", VappAmDeleteBasePopup, VcpConfirmPopup);
VappAmDeleteBasePopup::VappAmDeleteBasePopup()
:m_pAppInfo(NULL)
{
}

VappAmDeleteBasePopup::VappAmDeleteBasePopup(VappInfo* pAppInfo)
:m_pAppInfo(pAppInfo)
{
}

void VappAmDeleteBasePopup::onInit()
{
    VAPP_AM_TRACE(VAPP_AM_DELETE_POPUP_INIT);
    
    VcpConfirmPopup::onInit();
    
//    m_signalButtonClicked.connect(this,&VappAmDeletePopup::onClick);
    setAutoDestory(VFX_TRUE);
}

void VappAmDeleteBasePopup::onClick(VfxObject* pObj, VfxId id)
{
/*    VfxBool bRet = VFX_FALSE;
    VfxBool bAsync = VFX_FALSE;
    VfxWString wstrAppName = m_pAppInfo->m_wstrAppName;
    VfxMainScr* pMainScr = VappAMApp::getMainScr();
    VcpInfoBalloon *pBalloon;
    VfxWString wstr;

    if (id == m_deleteId)
    {
        if (VAPP_AM_OK ==  m_pAppInfo->uninstallApp())
        {
            bRet = VFX_TRUE;
        }
        else if (VAPP_AM_ERR == m_pAppInfo->uninstallApp())
        {
            bRet = VFX_FALSE;
        }
        else if (VAPP_AM_PROCESSING == m_pAppInfo->uninstallApp())
        {
            bRet = VFX_TRUE;
            bAsync = VFX_TRUE;
        }
        m_pAppInfo->uninstallApp();
        return;
        
        if(bRet)
        {
            if (VappInfo::VAPP_AM_APP_TYPE_WIGHET == m_pAppInfo->m_type)
            {
                if (g_pWGTInfoList)
                {
                    g_pWGTInfoList->removeOne(m_pAppInfo);
                }
            }
            else
            {
                if (g_pAppInfoList)
                {
                    g_pAppInfoList->removeOne(m_pAppInfo);
                }
            }
        }
        m_signalDelete.emit(bRet);
        
        //popup app deleted information
        //VFX_OBJ_CREATE_EX(pPopup, VappAmHasDelPopup, pMainScr,(wstrAppName));
        //pPopup->show(VFX_TRUE);
        if (m_bPopupAfterDel)
        {
            wstr += wstrAppName;
            wstr += VFX_WSTR(" has been uninstalled");
            pBalloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        	pBalloon->addItem(VCP_INFO_BALLOON_TYPE_INFO, wstr, 60);    
    	}
     } 
     // TODO: i should notify something//
     else
     {
        m_signalDelete.emit(VFX_FALSE);
     }*/
}
/*

/***************************************************************************** 
 * Class VappAmDeletePopup
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappAmDeletePopup", VappAmDeletePopup, VappAmDeleteBasePopup);

VappAmDeletePopup::VappAmDeletePopup()
{
}

VappAmDeletePopup::VappAmDeletePopup(VappInfo* pAppInfo)
:VappAmDeleteBasePopup(pAppInfo)
{
}

void VappAmDeletePopup::onInit()
{
    VappAmDeleteBasePopup::onInit();

    VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_UNINSTALL));
    strText += VFX_WSTR(" ");
    strText += m_pAppInfo->m_wstrAppName;
    strText += VFX_WSTR("?");
    
    setInfoType(VCP_POPUP_TYPE_WARNING);
    setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);   
    setText(strText);
    setCustomButton(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_UNINSTALL),
                    VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_CANCEL),
                    VCP_POPUP_BUTTON_TYPE_WARNING,
                    VCP_POPUP_BUTTON_TYPE_CANCEL); 
}

/***************************************************************************** 
 * Class VappAmDeleteCardPopup
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappAmDeleteCardPopup", VappAmDeleteCardPopup, VappAmDeleteBasePopup);

VappAmDeleteCardPopup::VappAmDeleteCardPopup()
{
}

VappAmDeleteCardPopup::VappAmDeleteCardPopup(VappInfo* pAppInfo)
:VappAmDeleteBasePopup(pAppInfo)
{
}

void VappAmDeleteCardPopup::onInit()
{
    VappAmDeleteBasePopup::onInit();

    VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_AM_NOT_FOUND_APP));
    
    setInfoType(VCP_POPUP_TYPE_QUESTION);
    setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);   
    setText(strText);
    setCustomButton(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_DELETE), VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_KEEP),
                            VCP_POPUP_BUTTON_TYPE_NORMAL, VCP_POPUP_BUTTON_TYPE_NORMAL); 
//    m_button[1]->setFocused(VFX_TRUE);
}

/***************************************************************************** 
 * Class VappAmDeletePhonePopup
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappAmDeletePhonePopup", VappAmDeletePhonePopup, VappAmDeleteBasePopup);

VappAmDeletePhonePopup::VappAmDeletePhonePopup()
{
}

VappAmDeletePhonePopup::VappAmDeletePhonePopup(VappInfo* pAppInfo)
:VappAmDeleteBasePopup(pAppInfo)
{
}

void VappAmDeletePhonePopup::onInit()
{
    VappAmDeleteBasePopup::onInit();

    VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_AM_NOT_FOUND_APP));
    
    setInfoType(VCP_POPUP_TYPE_FAILURE);
    setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
    setText(strText);

    setAutoDestory(VFX_TRUE);
}

/***************************************************************************** 
 * Class VappAmUpdatePopup
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappAmUpdatePopup", VappAmUpdatePopup, VcpIndicatorPopup);

VappAmUpdatePopup::VappAmUpdatePopup()
{
}

void VappAmUpdatePopup::onInit()
{
    VcpIndicatorPopup::onInit();
    setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    setText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_CHECKING));
}

//************************************************************************
//uninstall operator class
//************************************************************************
//parent MUST be VfxAppScr

VappAmUninstall::VappAmUninstall(VappInfo* pAppInfo)
:m_bShow(VFX_TRUE),m_pAppInfo(pAppInfo)
{
    
}

void VappAmUninstall::onInit()
{
    VfxObject::onInit();
    ASSERT(getParent()->isKindOf(VFX_OBJ_CLASS_INFO(VfxAppScr)));
}

void VappAmUninstall::setInfoPopup(VfxBool bShow)
{
    m_bShow = bShow;
}

void VappAmUninstall::uninstall()
{   
    VAPP_AM_TRACE(VAPP_AM_UNINSTALL);
    if (m_pAppInfo->isUpdating())
    {
        VcpConfirmPopup* pPopup;
        VFX_OBJ_CREATE(pPopup,VcpConfirmPopup,getParent());
        
        VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_CANT_FOR_UPDATING));    
        pPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
        pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
        pPopup->setText(strText);
        pPopup->show(VFX_TRUE);
        
        VappAmUninstall* pSelf = this;
        VFX_OBJ_CLOSE(pSelf);
        return;
    }
    else if (m_pAppInfo->isRunning())
    {
        VcpConfirmPopup* pPopup;
        VFX_OBJ_CREATE(pPopup,VcpConfirmPopup,getParent());
        
        VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_CANT_FOR_RUNNING));    
        pPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
        pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
        pPopup->setText(strText);
        pPopup->show(VFX_TRUE);
        
        VappAmUninstall* pSelf = this;
        VFX_OBJ_CLOSE(pSelf);
        return;
    }
    m_bShow = VFX_TRUE;
    m_pAppInfo->m_pAdapter->m_uninstallSignal.connect(this, &VappAmUninstall::uninstallCallback);
    VFX_OBJ_CREATE_EX(m_pPopup, VappAmDeletePopup, getParent(),(m_pAppInfo));
    m_pPopup->m_signalButtonClicked.connect(this,&VappAmUninstall::onClick);
    m_pPopup->show(VFX_TRUE);
}
    
void VappAmUninstall::deleteApp()
{
    VAPP_AM_TRACE(VAPP_AM_DELETE);

    m_bShow = VFX_FALSE;
    m_pAppInfo->m_pAdapter->m_uninstallSignal.connect(this, &VappAmUninstall::uninstallCallback);
    if (VappInfo::VAPP_AM_APP_POS_PHONE == m_pAppInfo->m_storage)
    {
        VFX_OBJ_CREATE_EX(m_pPopup, VappAmDeletePhonePopup, getParent(),(m_pAppInfo));        
    }
    else
    {
        VFX_OBJ_CREATE_EX(m_pPopup, VappAmDeleteCardPopup, getParent(),(m_pAppInfo));
    }
    m_pPopup->m_signalButtonClicked.connect(this,&VappAmUninstall::onClick);
    m_pPopup->show(VFX_TRUE);
}

void VappAmUninstall::setNotifyFunction(VfxObject* pObj,notifyFunc fun)
{
    m_notifySignal.connect(pObj, fun);
}

void VappAmUninstall::onClick(VfxObject* pObj, VfxId id)
{
    if (VCP_POPUP_BUTTON_NO_PRESSED == id)
    {
        //no button clicked
        m_notifySignal.emit(VAPP_AM_UNINSALL_CANCEL);
        VappAmUninstall* pSelf = this;
        VFX_OBJ_CLOSE(pSelf);
        return;
    }
    VfxWString wstrAppName = m_pAppInfo->m_wstrAppName;
    VfxMainScr* pMainScr = VappAMApp::getMainScr();
    VfxWString wstr;

    if (VCP_CONFIRM_POPUP_BUTTON_OK == id || VCP_CONFIRM_POPUP_BUTTON_USER_1 == id)
    {
	    if (VappInfo::VAPP_AM_APP_TYPE_WIGHET == m_pAppInfo->m_type)
        {
            if (g_pWGTInfoList)
            {
                VAPP_AM_TRACE1(VAPP_AM_REMOVE_LIST, m_pAppInfo);
                VFX_ASSERT(g_pWGTInfoList->removeOne(m_pAppInfo)!= VFX_FALSE);
            }
        }
        else
        {
            if (g_pAppInfoList)
            {
                VAPP_AM_TRACE1(VAPP_AM_REMOVE_LIST, m_pAppInfo);
                VFX_ASSERT(g_pAppInfoList->removeOne(m_pAppInfo)!= VFX_FALSE);
            }
        }
        
        VfxS32 result = m_pAppInfo->uninstallApp();
        if (VAPP_AM_ERR == result)
        {
            m_notifySignal.emit(VAPP_AM_UNINSALL_FAIL);            
        }
        else if (VAPP_AM_PROCESSING == result)
        {
 //           m_pPopup->hide(VFX_FALSE);
			VFX_OBJ_CREATE(m_pWaiting,VcpIndicatorPopup,getParent());

			m_pWaiting->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
			m_pWaiting->setText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_UNINSTALLING));
			m_pWaiting->show(VFX_TRUE);
            //wait callback function to process
            return;
        }
        else
        {
            //success
            
            m_notifySignal.emit(VAPP_AM_UNINSALL_OK);
            VfxWString wstrAppName;
            wstrAppName = m_pAppInfo->m_wstrAppName;
            if (m_bShow)
            {
                VfxWString wstr;
                wstr += wstrAppName;
                wstr += VFX_WSTR(" ");
                wstr += VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_UNINSTALLED);
                
            	mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
            	                     MMI_EVENT_INFO_BALLOON,
            	                     MMI_NMGR_BALLOON_TYPE_INFO,
            	                     (WCHAR*)wstr.getBuf());
            }
        }
    }   
    else
    {
        m_notifySignal.emit(VAPP_AM_UNINSALL_CANCEL);
    }
    
    VappAmUninstall* pSelf = this;
    VFX_OBJ_CLOSE(pSelf);
}

void VappAmUninstall::uninstallCallback(VfxS32 result)
{
    VAPP_AM_TRACE1(VAPP_AM_UNINSTALL_CB,this->isValid());
        
    if (this->isValid())
    {
        VfxWString wstrAppName;
        wstrAppName = m_pAppInfo->m_wstrAppName;
        m_pWaiting->exit(VFX_TRUE);
        if (VAPP_AM_OK == result)
        {            
            m_notifySignal.emit(VAPP_AM_UNINSALL_OK);
            if (m_bShow)
            {
                VfxWString wstr;
                wstr += wstrAppName;
                wstr += VFX_WSTR(" ");
                wstr += VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_UNINSTALLED);
                
            	mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
            	                     MMI_EVENT_INFO_BALLOON,
            	                     MMI_NMGR_BALLOON_TYPE_INFO,
            	                     (WCHAR*)wstr.getBuf());
            }
        }
        else
        {
            m_notifySignal.emit(VAPP_AM_UNINSALL_FAIL);
        }
        VappAmUninstall* pSelf = this;
        VFX_OBJ_CLOSE(pSelf);
    }    
}

//************************************************************************
//Update operator class
//************************************************************************
VappAmUpdate::VappAmUpdate(VappInfo* pAppInfo):m_pAppInfo(pAppInfo)
{
    
}

void VappAmUpdate::onInit()
{
    VfxObject::onInit();
    ASSERT(getParent()->isKindOf(VFX_OBJ_CLASS_INFO(VfxMainScr)));
    
    VFX_OBJ_CREATE(m_pUpdatePopup, VappAmUpdatePopup, getParent());
    m_pUpdatePopup->m_signalCanceled.connect(this,&VappAmUpdate::onCancelCheckUpdate);
}

void VappAmUpdate::update()
{
    VAPP_AM_TRACE(VAPP_AM_UPDATE);
    
    if (m_pAppInfo->isUpdating())
    { 
        //ONLY MRE App enter this
        if (VappInfo::VAPP_AM_APP_TYPE_MRE == m_pAppInfo->m_type)
        {        
            VappMREInfoAdapter::enterDownLoadUI(m_pAppInfo);           
        }
        
        VappAmUpdate* pSelf = this;
        VFX_OBJ_CLOSE(pSelf);
        return;
    }
    else if (m_pAppInfo->isRunning())
    {
        VcpConfirmPopup* pPopup;
        VFX_OBJ_CREATE(pPopup,VcpConfirmPopup,getParent());
        
        VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_CANT_FOR_RUNNING));    
        pPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
        pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);   
        pPopup->setText(strText);
        pPopup->show(VFX_TRUE);
        
        VappAmUpdate* pSelf = this;
        VFX_OBJ_CLOSE(pSelf);
        return;
    }
    m_pUpdatePopup->show(VFX_FALSE);
    
    m_pAppInfo->m_pAdapter->m_checkedUpdateSignal.connect(this,&VappAmUpdate::onCheckedUpdate);
    m_pAppInfo->checkUpdate();
    
#ifdef _AM_TEST_
    //just for demo
    VFX_OBJ_CREATE(m_pTimer, VfxTimer, this);
    m_pTimer->setStartDelay(5000);
    m_pTimer->m_signalTick.connect(this,&VappAmUpdate::onTime);
    m_pTimer->start();
#endif    
}

void VappAmUpdate::onCheckedUpdate(VfxS32 result)
{
    VAPP_AM_TRACE1(VAPP_AM_CHECKED_UPDATE,this->isValid());
    
    if (!this->isValid())
    {
        //this class is invalid!!
        return;
    }
    m_pUpdatePopup->exit(VFX_FALSE);
    if (VAPP_AM_OK == result)//can update
    {
        VcpConfirmPopup* pPopup;
        VFX_OBJ_CREATE(pPopup, VcpConfirmPopup, getParent());
        VfxWString strText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_UPDATE));
    
        pPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
        pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);   
        pPopup->setText(strText);
        pPopup->setCustomButton(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_UPDATE), 
                                VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_BTN_CANCEL),
                                VCP_POPUP_BUTTON_TYPE_NORMAL,
                                VCP_POPUP_BUTTON_TYPE_CANCEL);
        pPopup->m_signalButtonClicked.connect(this,&VappAmUpdate::onUpdateApp);
        pPopup->show(VFX_TRUE);
        return;
    }
    else if (VAPP_AM_NO_UPDATE == result)//no newer version to update
    {
#ifdef _AM_TEST_    
        VFX_OBJ_CLOSE(m_pTimer);
#endif        
        VcpConfirmPopup* pPopup;
        VFX_OBJ_CREATE(pPopup, VcpConfirmPopup, getParent());
        pPopup->setInfoType(VCP_POPUP_TYPE_INFO);
        pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        pPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_NO_NEW_VERSION));
        pPopup->show(VFX_TRUE); 
    }
    else //fail
    {
        VcpConfirmPopup* pPopup;
        VFX_OBJ_CREATE(pPopup, VcpConfirmPopup, getParent());
        pPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
        pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        pPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_NETWORK_FAIL));
        pPopup->show(VFX_TRUE);
    }
    VappAmUpdate* pSelf = this;
    VFX_OBJ_CLOSE(pSelf);
}

void VappAmUpdate::onUpdateApp(VfxObject* pObj, VfxId id)
{
    if (VCP_POPUP_BUTTON_NO_PRESSED == id)
    {
        //no button clicked
        VappAmUpdate* pSelf = this;
        VFX_OBJ_CLOSE(pSelf);
        return;
    }
    if (VCP_CONFIRM_POPUP_BUTTON_USER_1 == id)
    {
        if (VAPP_AM_OK == m_pAppInfo->updateApp())
        {
            //only MRE app update need to notify
            if (VappInfo::VAPP_AM_APP_TYPE_MRE == m_pAppInfo->m_type)
            {
                VfxWString wstr(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_START_UPDATE));
                
            	mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT,
            	                     MMI_EVENT_INFO_BALLOON,
            	                     MMI_NMGR_BALLOON_TYPE_INFO,
            	                     (WCHAR*)wstr.getBuf());
            }        	                     
        }
    }
    VappAmUpdate* pSelf = this;
    VFX_OBJ_CLOSE(pSelf);
}

void VappAmUpdate::onCancelCheckUpdate(VfxObject* pObj, VfxFloat f)
{
    //do nothing now
}

#ifdef _AM_TEST_
void VappAmUpdate::onTime(VfxTimer* pTime)
{
    VFX_OBJ_CLOSE(pTime);
    if (m_pUpdatePopup->isValid())
    {
        m_pUpdatePopup->hide(VFX_TRUE);
        
        VcpConfirmPopup* pPopup;
        VFX_OBJ_CREATE(pPopup, VcpConfirmPopup, getParent());
        pPopup->setInfoType(VCP_POPUP_TYPE_INFO);
        pPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        pPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_AM_POPUP_NO_NEW_VERSION));
        pPopup->show(VFX_TRUE);

    }
}
#endif

#endif // __MMI_COSMOS_APP_MANAGER__

#endif //__COSMOS_MMI_PACKAGE__
