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
 *  vapp_dtcnt_wlan_core.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __TCPIP__
#include "mmi_features.h"
#ifdef __MMI_WLAN_FEATURES__
#include "vapp_dtcnt_wlan_core.h"
#include "vcp_global_popup.h"
#include "vfx_context.h"
#include "vapp_ncenter_gprot.h"             /* vapp_ncenter_disable_leave() */

#ifdef __MMI_OP01_WIFI__
extern "C"
{
	#include "DmSrvGprot.h"					/* srv_dm_lawmo_is_locked() */
	#include "USBDeviceGprot.h"			    /* mmi_usb_webcam_is_active() */
	#include "ReminderSrvGprot.h"			/* srv_reminder_is_expiring() */
	#include "UcmSrvGprot.h"               	/* srv_ucm_is_any_call() */
	#include "ScrLockerGprot.h"				/* mmi_scr_locker_is_locked() */
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef __WIFI_SLIM__
	const VfxU32 g_memSize = 7.5 * 1024; // __WIFI_SLIM__ define in option.mak
#else
	const VfxU32 g_memSize = 20 * 1024;
#endif // __WIFI_SLIM__

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
static VfxU32 g_vappDtcntWlanMemPool[g_memSize / sizeof(VfxU32)];

/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C" void InitDtcntWlanApp()
{
    VFX_TRACE(("------->Data account wlan init<-------\n"));
    // VappWlanSentry::RegisterDtcntServiceEvents();
    VappWlanSentry::PowerOnWifi();
}

/***************************************************************************** 
 * Class VappWlanRepository
 *****************************************************************************/
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappWlanRepository);
void VappWlanRepository::onInit()
{
	VFX_OBJ_CREATE(m_context, VfxContext, VFX_SYS_GLOBAL_CONTEXT);	
	m_context->assignPool((VfxU8 *)g_vappDtcntWlanMemPool, g_memSize);
	Subject::onInit();
}

VappWlanRepository::VappWlanRepository(): 
    m_wlanCuiId(0), m_wlanSettingCuiId(0),
    m_savedApListNum (0), m_scanApListNum (0)
{
    VFX_TRACE(("===VappWlanRepository default constructor===\n"));
    m_observerList = VfxObjList();
    m_savedApList = VappApList();
    m_scanApList = VappApList();
}
    
VappWlanRepository::~VappWlanRepository()
{
    destroyApList(&m_scanApList);
    destroyApList(&m_savedApList);
    destroyObjectList(&m_observerList);
    VFX_TRACE(("===VappWlanRepository deconstructor===\n"));
}

VfxContext* VappWlanRepository::getContext()
{
    return m_context;
}

mmi_id VappWlanRepository::getWlanCuiId()
{
    return m_wlanCuiId;
}

void VappWlanRepository::setWlanCuiId(const mmi_id gid)
{
    m_wlanCuiId = gid;
}

void VappWlanRepository::initializeRepository(VfxObject* obj)
{
    VFX_TRACE(("===Initialize VappWlanRepository===\n"));
    // Reset all kinds of counters
    m_scanApListNum = 0;
    m_savedApListNum = 0;
    m_blockedApListNum = 0;
    m_rememberedApListNum = 0;	
	m_usefulApListNum = 0;
    m_infraApNum = 0;
    m_adhocApNum = 0;  	
	m_connNum = 0;
    m_macInfoStr = VFX_WSTR_RES(STR_ID_VAPP_WLAN_MAC_ADDR);
    // Reset connected ap
    memset(&m_connectBaseInfo, 0, sizeof(VappWlanBaseInfo));
    memset(&m_apToBeActivated, 0, sizeof(VappWlanProfile));
    // Init AP list
    m_savedApList = VappApList();
    m_scanApList = VappApList();
    // Reset connection info
    m_isConnectAbort = VFX_FALSE;
    m_isCertListShow = VFX_FALSE;
	// Reset Tethering info
	m_IsWLANByOffTethering = VFX_FALSE;
    // Reset Conn type
    m_connProcType = WLAN_CONN_TOTAL;
	m_connTypeSequence[0] = ALL_PROFILE_ENABLE;
    // Reset auto conn. cb
	m_autoConnCb = NULL;
	// Reset WPS status machine 
	m_wpsStatus = WLAN_WPS_STATUS_NULL;
	// Reset UI status machine
	m_uiFlow = WLAN_UI_NONE;
}

void VappWlanRepository::syncWithDtcntStorage()
{
    srv_dtcnt_result_enum result;
    srv_dtcnt_store_prof_qry_struct profileQry; 
    srv_dtcnt_store_prof_data_struct profileInfo;
    srv_dtcnt_prof_wlan_struct wlanProfile;
    VappWlanProfile * appProfile;
    VfxBool isModified = VFX_FALSE;
    VfxS8 index, pos;
    VfxU32 temp, totalProfile;
    VfxU32 profileIdArray[SRV_DTCNT_STORE_IDS_QRY_MAX_SIZE];
	
	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_STORAGE_CLASS_SIZE, 
		sizeof(VappWlanProfile), sizeof(VappWlanBaseInfo), sizeof(VappAPListEntry));	
	
	vfx_sys_mem_pool_status_struct old, output;
	m_context->statistics(old);	
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_STORAGE_ROOM_TOTAL_SIZE, old.total_size, old.used_size);

    VFX_TRACE(("------->Start to update dtcnt wifi repository<-------\n"));
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_INIT_BEGIN);
    memset(&profileQry, 0, sizeof(srv_dtcnt_store_prof_qry_struct));
    memset(&wlanProfile, 0, sizeof(srv_dtcnt_prof_wlan_struct));
    VFX_OBJ_CREATE(appProfile, VappWlanProfile, this);

	m_context->statistics(output);	
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_STORAGE_PROFILE_SIZE, output.used_size - old.used_size, output.used_size);

    profileQry.qry_info.filters = SRV_DTCNT_STORE_QRY_TYPE_BEARER_TYPE;
    profileQry.qry_info.bearer_qry_info = SRV_DTCNT_BEARER_WIFI;
    result = srv_dtcnt_store_qry_ids(&profileQry);
    
    VFX_TRACE(("------->Total of profile in store: %d<-------\n", profileQry.num_ids));
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_INIT_QRY_NUM, profileQry.num_ids);
    for (index = 0, pos = 0; index < profileQry.num_ids; index++)
    {
        if(0 != profileQry.ids[index])
        {
            profileIdArray[pos++] = profileQry.ids[index];  // initialize profile id array
            VFX_TRACE(("------->Profile ID: %d<-------\n", profileIdArray[index]));
        }
    }
    totalProfile = pos;
    
    if (result != SRV_DTCNT_RESULT_SUCCESS || totalProfile > SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM)
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_INIT_FAILED, result);
        return;
    }
    
    // Rearrange profile id's array
    for(index = totalProfile; index > 0; index--)
    {
        for(pos = 1; pos < index; pos++)
        {
            if(profileIdArray[pos] < profileIdArray[pos - 1])
            {
                temp = profileIdArray[pos];
                profileIdArray[pos] = profileIdArray[pos - 1];
                profileIdArray[pos - 1] = temp;

                isModified = VFX_TRUE;
            }   
        }

        if(VFX_FALSE == isModified)
        {
            break;
        }
        else
        {
            isModified = VFX_FALSE;
        }
    }
    // Query profile's info
    for (index = 0; index < (VfxS8)totalProfile; index++)
    {
        profileInfo.prof_type = SRV_DTCNT_BEARER_WIFI;
        profileInfo.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;
        profileInfo.prof_data = &wlanProfile;

        result =  srv_dtcnt_store_qry_prof(profileIdArray[index], &profileInfo);        
        VFX_TRACE(("------->Query id %d \t Profile %d<-------\n", profileIdArray[index], wlanProfile.profile_id));
    
        VappWlanToolbox::initAppProfileBySrvProfile (appProfile, &wlanProfile);
        if(appProfile->getPriority () > 0 && appProfile->getSsidLen () > 0)
        {
            // Set its match type as 
            appProfile->setApMatchType (WLAN_AP_SAVED);
            VFX_TRACE(("------->Add ap(%s) into saved ap list, its profile id is %d, priority is %d<-------\n", 
                    wlanProfile.ssid, wlanProfile.profile_id, wlanProfile.priority));
            VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_INIT_ADD_AP, wlanProfile.ssid_len, 
				wlanProfile.profile_id, wlanProfile.priority, wlanProfile.auth_mode, wlanProfile.encrypt_mode);
            insertApIntoSavedList(VFX_FALSE, appProfile);
        }
    }

    VFX_TRACE(("------->Adhoc ap's num %d \t Infra ap's num %d<-------\n", 
                m_adhocApNum, m_infraApNum));
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_INIT_STATISTIC, m_adhocApNum, m_infraApNum);
    updateApList ();
    
    // Auto power on wifi if possible 
    srv_dtcnt_wlan_auto_pw_on();

    //     Power saving mode
    srv_dtcnt_wlan_power_mode_enum powerSavingMode;
    result = srv_dtcnt_wlan_get_power_mode (&powerSavingMode);
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_POWER_SAVING_MODE_INIT, result, powerSavingMode);
    if(SRV_DTCNT_RESULT_SUCCESS == result)
    {
        m_powerSavingMode = powerSavingMode;
    }
    else
    {
        m_powerSavingMode = SRV_DTCNT_WLAN_WLAN_POWER_MODE_TOTAL;
    }
	
	VFX_OBJ_CLOSE(appProfile);
}

srv_dtcnt_wlan_power_mode_enum VappWlanRepository::getPowerSavingMode() const
{
    return m_powerSavingMode;
}

void VappWlanRepository::setPowerSavingMode(srv_dtcnt_wlan_power_mode_enum powerSavingMode)
{
    m_powerSavingMode = powerSavingMode;
}

const VfxU8* VappWlanRepository::getMacAddr() const
{
    return m_macAddr;
}

void VappWlanRepository::setMacAddr(const VfxU8* macAddr)
{
    memcpy(m_macAddr, macAddr, MAC_ADDR_LEN_MAX);    
}

VfxWString VappWlanRepository::getMacInfoStr() const
{
    return m_macInfoStr;
}

void VappWlanRepository::setMacInfoStr(const VfxWString& macInfo)
{
    m_macInfoStr = macInfo;
}

VfxU32 VappWlanRepository::getScanJobId() const
{
    return m_scanJobId;
}

void VappWlanRepository::setScanJobId(const VfxU32 jobId)
{
    m_scanJobId = jobId;
}

VfxBool VappWlanRepository::getIsScanAbort() const
{
    return m_isScanAbort;
}

void VappWlanRepository::setIsScanAbort(const VfxBool isScanAbort)
{
    m_isScanAbort = isScanAbort;
}

VAPP_WLAN_CONN_PROC_TYPE VappWlanRepository::getConnProcType() const
{
    return m_connProcType;
}

void VappWlanRepository::setConnProcType(VAPP_WLAN_CONN_PROC_TYPE procType)
{
    m_connProcType = procType;
}

supc_abm_cause_enum VappWlanRepository::getConnFailType() const
{
	return m_connFailType;
}

void VappWlanRepository::setConnFailType(supc_abm_cause_enum failType)
{
    m_connFailType = failType;
}

vcui_wlan_auto_conn_cb_func_ptr VappWlanRepository::getAutoConnCb() const
{
    return m_autoConnCb;
}

void VappWlanRepository::setAutoConnCb(vcui_wlan_auto_conn_cb_func_ptr autoConnCb)
{
    m_autoConnCb = autoConnCb;
}

VfxBool VappWlanRepository::getIsInsert() const
{
    return m_isInsertAp;
}

void VappWlanRepository::setIsInsert(const VfxBool isInsert)
{
    m_isInsertAp = isInsert;
}


VfxBool VappWlanRepository::getIsConnectAbort() const
{
    return m_isConnectAbort;
}

void VappWlanRepository::setIsConnectAbort(const VfxBool isConnectAbort)
{
    m_isConnectAbort = isConnectAbort;
}

VfxBool VappWlanRepository::getIsWLANByOffTethering() const
{
	return m_IsWLANByOffTethering;
}

void VappWlanRepository::setIsWLANByOffTethering(const VfxBool check)
{
	m_IsWLANByOffTethering = check;
}

srv_dtcnt_wlan_scan_result_enum VappWlanRepository::getScanRresult()
{
    return m_scanResult;
}

void VappWlanRepository::setScanResult(srv_dtcnt_wlan_scan_result_enum result)
{
    m_scanResult = result;
}

VfxU8 VappWlanRepository::getScanApListNum() const
{
    return m_scanApListNum;
}

void VappWlanRepository::setScanApListNum(VfxU8 apListNum)
{
    m_scanApListNum = apListNum;
}

void VappWlanRepository::updateScanApList(const supc_abm_bss_info_struct** apList)
{
    VappWlanBaseInfo *savedAP;
    VappAPListEntry  *entry;
    VfxBool           isFound = VFX_FALSE;
	VfxU32			  scanApNum = m_scanApListNum;
	
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_SCAN_RESULT, scanApNum);
    VFX_TRACE(("------->Total of acess points (%d)<-------\n", scanApNum));
    /**********************************************************/
    //  Empty the scan list if receive scan result successfully
    destroyApList (&m_scanApList);
    resetSavedApList();
    /**********************************************************/
	vfx_sys_mem_pool_status_struct old, output;
	m_context->statistics(old);	
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_STORAGE_CURRENT_USED_SIZE, old.used_size, __LINE__);

    VappWlanBaseInfo *baseInfo = NULL;	
	VFX_OBJ_CREATE (baseInfo, VappWlanBaseInfo, this);
	
	m_context->statistics(output);	
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_STORAGE_BASEINFO_SIZE, output.used_size - old.used_size, output.used_size);
	
    for (VfxU32 index = 0; index < scanApNum && index < WNDRV_MAX_SCAN_RESULTS_NUM; index++)
    {
        /* Discard hidden AP */
        if (apList[index]->ssid_len == 0 || apList[index]->ssid[0] == 0)
        {
        	m_scanApListNum--;
            continue;
        }
#ifdef __WAPI_SUPPORT__
#ifdef __MMI_HIDE_WAPI__
        /* If support WAPI and hide WAPI from MMI, then ignore this AP */
        if (apList[index]->wapi_ie_info_p == KAL_TRUE)
        {
        	m_scanApListNum--;
            continue;
        }                
#endif /* __MMI_HIDE_WAPI__ */
#endif
        // initialize the profile
        VappWlanToolbox::initWlanRegularInfo (baseInfo);
        initProfileByBssInfo(apList[index], baseInfo);
        // Go through the saved list and set flag as FALSE
        isFound = VFX_FALSE;
        entry = m_savedApList.getValidHead ();
        // Mark the match type for each ap in the list
        while(NULL != entry)
        {
            savedAP = (VappWlanBaseInfo*)entry->get();
            
            if(VFX_TRUE == VappWlanToolbox::isSameAP (savedAP, baseInfo))
            {
                isFound = VFX_TRUE;
                VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_SCAN_FOUND, baseInfo->getSsidLen ());
                VFX_TRACE(("------->profile(%s) has been found in the saved list<-------\n", baseInfo->getSsid ()));
                // update RSSI
                savedAP->setRssi (baseInfo->getRssi ());
				//savedAP->setApCharset(profile->getApCharset ());//to do..
                // WLAN_AP_SEARCH_SAVED_CONNECTED
                if(VFX_TRUE == VappWlanToolbox::isSameAP (&m_connectBaseInfo, savedAP))
                {
                    savedAP->setApMatchType (WLAN_AP_SEARCH_SAVED_CONNECTED);

					setIsScanResultUseful(VFX_TRUE);
                }
                // WLAN_AP_SEARCH_SAVED
                else
                {
                    savedAP->setApMatchType (WLAN_AP_SEARCH_SAVED);
					if(SRV_DTCNT_WLAN_AP_BLACK_LIST != savedAP->getApMgrType())
					{						
						setIsScanResultUseful(VFX_TRUE);
					}
                }
				m_scanApListNum--;
                break;
            }         
            entry = entry->getValidNext ();
        } /* end of while */
        
        if(!isFound)
        {
            VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_SCAN_NOT_FOUND, baseInfo->getSsidLen ());
            VFX_TRACE(("------->profile(%s) not found in the saved list<-------\n", baseInfo->getSsid ()));

			setIsScanResultUseful(VFX_TRUE);
			
			// WLAN_AP_SEARCH
            baseInfo->setApMatchType (WLAN_AP_SEARCH);
			
            // Not found! Add it into the end of scan list
            m_scanApList.append (baseInfo);
            VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_SCAN_ADD, baseInfo->getApMatchType ());
            VFX_TRACE(("------->add it into scan list, set its type as %d<-------\n", m_scanApList.getEntry (baseInfo)->get ()->getApMatchType ()));
        }
    } /* end of for */
    
	// Release memory
	VFX_OBJ_CLOSE (baseInfo);
   
    // Refresh the display ap list 
    updateApList();
}

void VappWlanRepository::updateApList()
{
	VfxU8                   rememberedApNum = 0;
	VfxU8                   blockedApNum = 0;
	VfxU8                   usefulApNum = 0;
    VappWlanBaseInfo     *profile;    
    VappAPListEntry         *entry;
    
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UPDATE_AP_LIST_START);
    setCurWlanStatus();
	updateSavedApMatchType();
    if(SRV_DTCNT_WLAN_STATUS_CONNECTED == m_curWlanStatus)
    {
	    rememberedApNum ++;
	    usefulApNum ++;
    }

#ifndef __MMI_OP01_WIFI__
	entry = m_scanApList.getValidHead ();
	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UPDATE_AP_LIST_GO_THROUGH, m_scanApList.getValidCount ());
	VFX_TRACE(("------->Go through scan list(%d)<-------\n", m_scanApList.getValidCount ()));
	while(NULL != entry)
	{
		profile = (VappWlanBaseInfo *)entry->get();
		VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UPDATE_AP_LIST_ADD, 
				profile->getSsidLen (), profile->getApMatchType (), profile->getApMgrType(),
				profile->getPriority (),profile->getAuthMode(), profile->getEncryptMode());
		VFX_TRACE(("------->Add profile(%s) type(%d)<-------\n", profile->getSsid (), profile->getApMatchType ())); 
		m_usefulApPointArray[usefulApNum++] = profile;
		entry = entry->getValidNext ();
	}
#endif

	entry = m_savedApList.getValidHead ();
	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UPDATE_AP_LIST_GO_THROUGH, m_savedApList.getValidCount ());
    VFX_TRACE(("------->Go through saved list(%d)<-------\n", m_savedApList.getValidCount ()));
    while(NULL != entry)
    {
        profile = (VappWlanBaseInfo *)entry->get();
#ifdef __MMI_OP01_WIFI__  			
		if(SRV_DTCNT_WLAN_AP_DEFAULT == profile->getApMgrType() && 
			WLAN_AP_SAVED_CONNECTED != profile->getApMatchType() &&
			WLAN_AP_SEARCH_SAVED_CONNECTED != profile->getApMatchType() )
		{
			m_usefulApPointArray[usefulApNum++] = profile;					
			m_rememberedApPointArray[rememberedApNum++] = profile;
			VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UPDATE_AP_LIST_ADD, 
	     		profile->getSsidLen (), profile->getApMatchType (), profile->getApMgrType(),
	     		profile->getPriority (), profile->getAuthMode(), profile->getEncryptMode());
	     	VFX_TRACE(("------->Add profile(%s)<-------\n", profile->getSsid ()));	
		}	
#else
		//whether saveAp is connected Ap
		if( WLAN_AP_SAVED_CONNECTED != profile->getApMatchType() &&
			WLAN_AP_SEARCH_SAVED_CONNECTED != profile->getApMatchType() )
		{
			if(SRV_DTCNT_WLAN_AP_BLACK_LIST == profile->getApMgrType())
			{
				m_blockedApPointArray[blockedApNum++] = profile;
			}
			else if(SRV_DTCNT_WLAN_AP_USER_DEFINE == profile->getApMgrType() ||
					SRV_DTCNT_WLAN_AP_DEFAULT == profile->getApMgrType())
			{
				m_rememberedApPointArray[rememberedApNum++] = profile;
				m_usefulApPointArray[usefulApNum++] = profile;
			}
			VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UPDATE_AP_LIST_ADD, 
	     		profile->getSsidLen (), profile->getApMatchType (), profile->getApMgrType(),
	     		profile->getPriority (), profile->getAuthMode(), profile->getEncryptMode());
	     	VFX_TRACE(("------->Add profile(%s)<-------\n", profile->getSsid ()));	
		}
#endif
        entry = entry->getValidNext ();
    }
	
#ifdef __MMI_OP01_WIFI__  
    entry = m_scanApList.getValidHead ();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UPDATE_AP_LIST_GO_THROUGH, m_scanApList.getValidCount ());
    VFX_TRACE(("------->Go through scan list(%d)<-------\n", m_scanApList.getValidCount ()));
    while(NULL != entry)
    {
	    profile = (VappWlanBaseInfo *)entry->get();	
		m_usefulApPointArray[usefulApNum++] = profile;	
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UPDATE_AP_LIST_ADD, 
           profile->getSsidLen (), profile->getApMatchType (), profile->getApMgrType(),
           profile->getPriority (), profile->getAuthMode(), profile->getEncryptMode());
        VFX_TRACE(("------->Add profile(%s) type(%d)<-------\n", profile->getSsid (), profile->getApMatchType ()));
        entry = entry->getValidNext ();
    }

    entry = m_savedApList.getValidHead ();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UPDATE_AP_LIST_GO_THROUGH, m_savedApList.getValidCount ());
    VFX_TRACE(("------->Go through saved list(%d)<-------\n", m_savedApList.getValidCount ()));
    while(NULL != entry)
    {		
        profile = (VappWlanBaseInfo *)entry->get();
		if(SRV_DTCNT_WLAN_AP_DEFAULT != profile->getApMgrType())
		{
			//whether saveAp is connected Ap
			if( WLAN_AP_SAVED_CONNECTED != profile->getApMatchType() &&
				WLAN_AP_SEARCH_SAVED_CONNECTED != profile->getApMatchType() )
        	{	
				if(SRV_DTCNT_WLAN_AP_BLACK_LIST == profile->getApMgrType())
				{
					m_blockedApPointArray[blockedApNum++] = profile;
				}
				else if(SRV_DTCNT_WLAN_AP_USER_DEFINE == profile->getApMgrType())
				{
					m_rememberedApPointArray[rememberedApNum++] = profile;
					m_usefulApPointArray[usefulApNum++] = profile;
				}
				VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UPDATE_AP_LIST_ADD, 
            		profile->getSsidLen (), profile->getApMatchType (), profile->getApMgrType(),
            		profile->getPriority (), profile->getAuthMode(), profile->getEncryptMode());
        		VFX_TRACE(("------->Add profile(%s) type(%d)<-------\n", profile->getSsid (), profile->getApMatchType ()));
			}
		}
        entry = entry->getValidNext ();
    }
#endif	

	m_usefulApListNum = usefulApNum;   
	m_blockedApListNum = blockedApNum;
	m_rememberedApListNum = rememberedApNum;	
	m_savedApListNum = m_blockedApListNum + m_rememberedApListNum;

    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UPDATE_AP_LIST_END);
}


void VappWlanRepository::updateSavedApMatchType()
{
    VappAPListEntry         	*entry;
    VAPP_WLAN_AP_CHANGE_ENUM    connApMatchType;
	VappWlanBaseInfo 		*profile;
	
    entry = m_savedApList.getValidHead ();
    while(NULL != entry)
    {		
        profile = (VappWlanBaseInfo *)entry->get();	
		if(SRV_DTCNT_WLAN_STATUS_CONNECTED == m_curWlanStatus && 
							VappWlanToolbox::isSameAP (&m_connectBaseInfo, profile))
		{
			// set profile's match type
			if(WLAN_AP_SEARCH == profile->getApMatchType () ||
				WLAN_AP_SEARCH_SAVED == profile->getApMatchType ())
			{
				profile->setApMatchType (WLAN_AP_SEARCH_SAVED_CONNECTED);
			}
			else if(WLAN_AP_SAVED == profile->getApMatchType ())
			{
				profile->setApMatchType (WLAN_AP_SAVED_CONNECTED);
			}
			m_usefulApPointArray[0] = profile;
			m_rememberedApPointArray[0] = profile;
		 	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UPDATE_AP_LIST_ADD, 
	     		profile->getSsidLen (), profile->getApMatchType (), profile->getApMgrType(),
	     		profile->getPriority (), profile->getAuthMode(), profile->getEncryptMode());
	     	VFX_TRACE(("------->Add profile(%s)<-------\n", profile->getSsid ()));		 

		}
		else	 /* reset previous connection's match type */
		{
			connApMatchType = profile->getApMatchType ();
			if(WLAN_AP_SEARCH_SAVED_CONNECTED == connApMatchType)
			{
				profile->setApMatchType (WLAN_AP_SEARCH_SAVED);
			}
			else if(WLAN_AP_SAVED_CONNECTED == connApMatchType)
			{
				profile->setApMatchType (WLAN_AP_SAVED);
			}
		}		
        entry = entry->getValidNext ();
    }
}

void VappWlanRepository::resetSavedApList()
{
    VappWlanBaseInfo     *profile;
    VappAPListEntry     *entry;
    
    entry = m_savedApList.getValidHead ();
    // Reset the match type for AP in the saved list
    while(NULL != entry)
    {
        profile = (VappWlanBaseInfo*)entry->get();
        profile->setApMatchType (WLAN_AP_SAVED);
        
        entry = entry->getValidNext ();
    } /* end of while */
}

void VappWlanRepository::destroyApList(VappApList* apList)
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_DESTORY_AP_LIST, apList->getValidCount ());
    apList->clear ();  
}

void VappWlanRepository::destroyObjectList(VfxObjList* objList)
{
    VfxObjListEntry     *entry;

    VFX_TRACE(("Total of object entry: %d-------\n", objList->getValidCount ()));
    entry = objList->getValidHead ();
    while(NULL != entry)
    {
        VfxObjListEntry *next = entry->getValidNext ();
        VfxObject* obj = entry->get ();
        VFX_OBJ_CLOSE(obj);
        entry = next;
    }
    objList->clear ();  
}

VappWlanBaseInfo* VappWlanRepository::getConnectedAP()
{
    return &m_connectBaseInfo;
}

void VappWlanRepository::setConnectedAP(VappWlanBaseInfo* ap)
{
    if(ap)
    {
        VappWlanToolbox::cloneWlanBaseInfo (ap, &m_connectBaseInfo);
    }
}

void VappWlanRepository::resetConnectedAP()
{
    memset(&m_connectBaseInfo, 0, sizeof(VappWlanBaseInfo));
}

VappWlanProfile* VappWlanRepository::getApToBeActivated()
{
  return &m_apToBeActivated;
}

void VappWlanRepository::setApToBeActivated(VappWlanProfile* profile)
{
    memset(&m_apToBeActivated, 0, sizeof(VappWlanProfile));
    if(profile)
    {
        VappWlanToolbox::cloneWlanProfile (profile, &m_apToBeActivated);
    }
} 

srv_dtcnt_wlan_status_enum VappWlanRepository::getCurWlanStatus() const
{
    return m_curWlanStatus;
}

void VappWlanRepository::setCurWlanStatus()
{
    m_curWlanStatus = srv_dtcnt_wlan_status();
}

VcpFormItemLauncherCell* VappWlanRepository::getSettingCellInstance()
{
    return m_settingCell;
}

void VappWlanRepository::setSettingCellInstance(VcpFormItemLauncherCell* cell)
{
    m_settingCell = cell;
}

VcpFormItemSwitchCell* VappWlanRepository::getSettingSwitchCellInstance() 
{
    return m_settingSwitchCell;
}

void VappWlanRepository::setSettingSwitchCellInstance( VcpFormItemSwitchCell* cell)
{
    m_settingSwitchCell = cell;
}

VfxU32 VappWlanRepository::getRootCAId()
{
    return m_rootCaId;
}

void VappWlanRepository::setRootCAId(VfxU32 rootCaId)
{
    m_rootCaId = rootCaId;
}

VfxU32 VappWlanRepository::getUserCAId()
{
    return m_userCaId;
}

void VappWlanRepository::setUserCAId(VfxU32 userCaId)
{
    m_userCaId = userCaId;
}

VfxU32 VappWlanRepository::getWapiAseId()
{
    return m_wapiAseId;
}

void VappWlanRepository::setWapiAseId(VfxU32 aseId)
{
    m_wapiAseId = aseId;
}

VfxU32 VappWlanRepository::getWapiClientId()
{
    return m_wapiClientId;
}

void VappWlanRepository::setWapiClientId(VfxU32 clientId)
{
    m_wapiClientId = clientId;
}

VfxBool VappWlanRepository::getIsDeleteApProc() const
{
    return m_isDeleteAp;
}

void VappWlanRepository::setIsDeleteApProc(VfxBool isDelete)
{
    m_isDeleteAp = isDelete;
}

VfxBool VappWlanRepository::getIsCertListShow() const
{
    return m_isCertListShow;
}

void VappWlanRepository::setIsCertListShow(VfxBool isShow)
{
    m_isCertListShow = isShow;
}

VAPP_WLAN_WPS_CONN_TYPE VappWlanRepository::getWPSConnType() const
{
    return m_connType;
}

void VappWlanRepository::setWPSConnType(VAPP_WLAN_WPS_CONN_TYPE connType)
{
    m_connType = connType;
}

VfxS32 VappWlanRepository::getConnDuration() const
{
    return m_connDuration;
}

void VappWlanRepository::setConnDuration(VfxS32 duration)
{
    m_connDuration = duration;
}

VfxMsec VappWlanRepository::getCurrentSystemTime() const
{
    return m_currSystemTime;
}

void VappWlanRepository::setCurrentSystemTime(VfxMsec curTime)
{
    m_currSystemTime = curTime;
}

VfxU32 VappWlanRepository::getPinCode() const
{
    return m_pinCode;
}

void VappWlanRepository::setPinCode(VfxU32 pinCode)
{
    m_pinCode = pinCode;
}

void VappWlanRepository::setWpsInfo(VfxU8 action, VfxU32 value)
{
    if(0 == action)         // countdown, it is seconds
    {
        setConnDuration (value);
    }
    else if(1 == action)   // pin, it is seconds
    {
        setPinCode (value);
    }
}

void VappWlanRepository::setWpsStatus(VAPP_WLAN_WPS_STATUS status)
{
	m_wpsStatus =  status;
}

VAPP_WLAN_WPS_STATUS VappWlanRepository::getWpsStatus()
{
	return m_wpsStatus ;
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
#endif

void VappWlanRepository::setWlanSettingCuiId(const mmi_id gid)
{
    m_wlanSettingCuiId = gid;
}

mmi_id VappWlanRepository::getWlanSettingCuiId() const
{
    return m_wlanSettingCuiId;
}

supc_connection_type_enum VappWlanRepository::getCnfConnType()
{	
	return m_cnfConnType;
}

void VappWlanRepository::setCnfConnType(supc_connection_type_enum connType)
{	
	 m_cnfConnType = connType;
}

supc_connection_type_enum VappWlanRepository::getAPConnTypeSequence(VfxS32 number)
{	
	return m_connTypeSequence[number];
}
	
void VappWlanRepository::setAPConnTypeSequence(supc_connection_type_enum tempConnType)
{
	m_connTypeSequence[m_connNum] = tempConnType;			
    m_connNum++;
}

void VappWlanRepository::updateAPConnTypeSequence()
{
	VfxU8 temp = 0;
	
	for(temp = 0; temp < m_connNum - 1 && m_connNum >= 1 ; temp++)
	{
		m_connTypeSequence[temp] = m_connTypeSequence[temp+1];
	}	
	
	if(m_connNum > 0)
	{
		m_connNum--;
	}
	
	if (m_connNum == 0)
	{
		m_connTypeSequence[0] = ALL_PROFILE_ENABLE;
	}
}

VfxU8 VappWlanRepository::getAPConnNum()
{
	return m_connNum;
}

VappAPListEntry* VappWlanRepository::findProfileWithLowestPriority(srv_dtcnt_wlan_network_type_enum networkType)
{
    if(networkType == SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA && m_infraApNum == 0)
    {
        return NULL;
    }

    if(networkType == SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC && m_adhocApNum == 0)
    {
        return NULL;
    }
    
    VfxU8 priority = 0;
    VappAPListEntry 	*entry = m_savedApList.getValidHead ();
    VappAPListEntry 	*lowestOne = NULL;
    VappWlanBaseInfo *item = NULL;
    // Go through the saved ap list
    while(NULL != entry)
    {
        item = (VappWlanBaseInfo *)entry->get();
        if(item->getNetworkType () == networkType && 
           item->getPriority () > priority &&
           SRV_DTCNT_WLAN_AP_DEFAULT != item->getApMgrType()) // default Ap can't replace.
        {
            priority = item->getPriority ();
            lowestOne = entry;       // The higher the value it is, the lowest the priority it is
        }
        entry = entry->getValidNext ();
    }

    return lowestOne;
}

void VappWlanRepository::editSearchProfile(VappWlanProfile* originalProfile, VappWlanProfile* profile)
{
    VappAPListEntry *entry;
    
    // 1. Find profile in the scan list
    entry = m_scanApList.getEntry (originalProfile);
    if(NULL == entry)
    {   
        VFX_TRACE(("------->Not found<-------\n"));
        // return;   // Cannot find
    }
    else
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_EDIT_SEARCH_NETWORK_START, originalProfile->getSsidLen ());
        // Remove it from scan list if found
        if(VFX_FALSE == m_scanApList.removeOne (originalProfile))
        {
            VFX_TRACE(("------->Remove profile (%s) failed<-------\n", originalProfile->getSsid ()));
            return;
        }
        else
        {
            VFX_TRACE(("------->Remove profile (%s) successfully<-------\n", originalProfile->getSsid ()));
        }
    }
    
    // 2. set new profile's priority, add ap into saved list
    // profile->setPriority (getSavedApNum () + 1);
    insertApIntoSavedList (VFX_TRUE, profile);
}

void VappWlanRepository::editSavedProfile(VappWlanProfile* profile)
{
    VappAPListEntry* entry;
    
    // 1. Find profile according to the profile id
    entry = m_savedApList.findOne (profile->getProfileId ());
    if(NULL == entry)
    {   
        VFX_TRACE(("------->Not found<-------\n"));
        VappWlanSentry::showGlobalPopup (GRP_ID_ROOT, NULL, STR_ID_VAPP_WLAN_ERR_AP_NOT_EXISTED);
        return;   // Cannot find
    }
    else
    {
        // The original priority maybe changed during edit it
        // Adjust the priority if changed
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_EDIT_SAVED_NETWORK_PRE_START, 
                    profile->getPriority (), entry->get ()->getPriority ());
        profile->setPriority (entry->get ()->getPriority ());
        
        // Modify counter
        if(SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA == entry->get ()->getNetworkType ())
        {
            --m_infraApNum;
        }
        else
        {
            --m_adhocApNum;
        }
    }
    // 2. Remove it from saved list according to id if found
    if(VFX_FALSE == m_savedApList.removeOne (profile->getProfileId ()))
    {
        VFX_TRACE(("------->Remove profile (%d) failed<-------\n", profile->getProfileId ()));
        return;
    }
    else
    {
        VFX_TRACE(("------->Remove profile (%d) successfully<-------\n", profile->getProfileId ()));
    }
    // 3. Insert profile into the saved list
    VFX_TRACE(("==> Add ap(%s) into list and its priority is %d\n", 
                            profile->getSsid (), profile->getPriority ()));
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_EDIT_SAVED_NETWORK_START, profile->getProfileId ());
    if(SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA == profile->getNetworkType ())
    {
        m_savedApList.insertAt (m_adhocApNum, profile);
        ++m_infraApNum;
    }
    else
    {
        m_savedApList.prepend (profile);
        ++m_adhocApNum;
    }
    // 4. Update data in the nvram according to profile id
    updateProfileInDtcntStore(SRV_DTCNT_WLAN_PROF_FIELD_ALL, profile);
}

srv_dtcnt_result_enum VappWlanRepository::saveProfileInDtcntStore(VfxU32 fields, VappWlanProfile *appProfile)
{
    srv_dtcnt_result_enum result;
    srv_dtcnt_prof_wlan_struct saveProfile;
    srv_dtcnt_store_prof_data_struct *storeProfile;

    initSrvProfileByAppProfile(VFX_FALSE, appProfile, &saveProfile);
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_STORAGE_PROFILE_CLIENT_CA_ID, 
        appProfile->getClientCaId (), saveProfile.client_ca_id);
    // Check the network type once again for CR MAUI_02735563
    switch(saveProfile.network_type)
    {
    case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
        break;
    case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
        break;
    default:
        VFX_ASSERT(0);
    }

    VFX_ALLOC_MEM (storeProfile, sizeof(srv_dtcnt_store_prof_data_struct), this);
    
    storeProfile->prof_data = &saveProfile;
    storeProfile->prof_fields = fields;
    storeProfile->prof_type = SRV_DTCNT_BEARER_WIFI;

    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_STORAGE_ADD_START, saveProfile.auth_mode, saveProfile.encrypt_mode);
    result =  srv_dtcnt_store_add_prof(storeProfile, &(saveProfile.profile_id));
    
    if(SRV_DTCNT_RESULT_SUCCESS == result)
    {
        // SET AP's PROFILE ID!!!
        appProfile->setProfileId (saveProfile.profile_id);
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_STORAGE_ADD_SUCCESS, appProfile->getProfileId ());
        VFX_TRACE(("------->Store completed! Profile ID: %d-------\n", appProfile->getProfileId ()));
    }
    else
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_STORAGE_ADD_FAILED, result);
        VFX_TRACE(("------->Store failed!-------\n"));
    }

    VFX_FREE_MEM (storeProfile);

    return result;
}

srv_dtcnt_result_enum VappWlanRepository::updateProfileInDtcntStoreByBaseInfo(VfxU32 fields, VappWlanBaseInfo *baseInfo)
{	
    srv_dtcnt_result_enum result;
	VappWlanProfile *profile = NULL;
	VFX_OBJ_CREATE(profile, VappWlanProfile, this);	
	VappWlanToolbox::getAppProfileByAppBaseInfo(baseInfo, profile);
	result = updateProfileInDtcntStore (fields, profile); 	
	VFX_OBJ_CLOSE(profile);
	return result;
}

srv_dtcnt_result_enum VappWlanRepository::updateProfileInDtcntStore(VfxU32 fields, VappWlanProfile *appProfile)
{
    srv_dtcnt_result_enum result;
    srv_dtcnt_prof_wlan_struct udpateProfile;
    srv_dtcnt_store_prof_data_struct *storeProfile;

    initSrvProfileByAppProfile(VFX_FALSE, appProfile, &udpateProfile);

    VFX_ALLOC_MEM (storeProfile, sizeof(srv_dtcnt_store_prof_data_struct), this);

    storeProfile->prof_data = &udpateProfile;
    storeProfile->prof_fields = fields;
    storeProfile->prof_type = SRV_DTCNT_BEARER_WIFI;

    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_STORAGE_UPDATE_START, appProfile->getSsidLen(),
		appProfile->getAuthMode(), appProfile->getEncryptMode());
    result =  srv_dtcnt_store_update_prof(appProfile->getProfileId (), storeProfile);

    if(SRV_DTCNT_RESULT_SUCCESS == result)
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_STORAGE_UPDATE_SUCCESS, udpateProfile.profile_id);
        VFX_TRACE(("------->Update completed! Profile ID: %d-------\n", udpateProfile.profile_id));
    }
    else
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_STORAGE_UPDATE_FAILED, result);
        VFX_TRACE(("------->Update failed! Fail reason: %d-------\n", result));
    }
        
    VFX_FREE_MEM (storeProfile);
    
    return result;
}

srv_dtcnt_result_enum VappWlanRepository::removeProfileFromDtcntStore(VappWlanBaseInfo* baseInfo)
{
    srv_dtcnt_result_enum result;

    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_STORAGE_REMOVE_START, baseInfo->getProfileId ());
    result = srv_dtcnt_store_delete_prof (baseInfo->getProfileId (), MMI_TRUE, NULL, NULL);

    if(SRV_DTCNT_RESULT_SUCCESS == result)
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_STORAGE_REMOVE_SUCCESS);
        VFX_TRACE(("------->Delete AP(%s) from ap list successfully!-------\n", baseInfo->getSsid ()));
    }
    else
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_STORAGE_REMOVE_FAILED, result);
        VFX_TRACE(("------->Delete AP(%s) from ap list failed!-------\n", baseInfo->getSsid ()));
    }

    return result;
}


void VappWlanRepository::afterConnectedSuccess(srv_dtcnt_wlan_conn_res_struct* connRes)
{
    VappWlanBaseInfo*        baseInfo = NULL;	
    VappAPListEntry*            entry;
    VAPP_WLAN_AP_CHANGE_ENUM    apMatchType;

    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_FIND_PROFILE, connRes->profile_id);
    entry = m_savedApList.findOne (connRes->profile_id);
    if(entry)
    {
        baseInfo = entry->get ();
        ASSERT(baseInfo != NULL);
    }
    else
    {
        if(VFX_FALSE == findInApList(&m_apToBeActivated))
        {
            // connect success, but AP don't exist in scanAP list.           
            VappWlanSentry::SendDisconnectRequest ()  ;          
            return;
        }
        else
        {
            baseInfo = getInApList(&m_apToBeActivated);
            if((baseInfo->getSsidLen () != connRes->ssid_len) ||
               (strncmp((const char*)baseInfo->getSsid (), (const char*)connRes->ssid, connRes->ssid_len) != 0))
            {
                // user connect another AP just when one AP connect success, m_apToBeActivated has changed.
                return;
            }
        }
        
        // If AP has already been activated, return
        if(VappWlanToolbox::isSameAP(&m_connectBaseInfo, baseInfo))
        {
            VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_ALREADY_ACTIVATED, baseInfo->getProfileId ());
            baseInfo->setChannelNumber (connRes->channel_number);    //update the channel number
			//set UI status machine
			if(SRV_DTCNT_WLAN_AP_DEFAULT == baseInfo->getApMgrType())
			{
				setWlanUiFlow (WLAN_UI_WAIT_FOR_IP_UPDATE);
			}
			else
			{			
				setWlanUiFlow (WLAN_UI_NONE);
			}
			return;
        }
    }
	
    baseInfo->setChannelNumber (connRes->channel_number);    //update the channel number
    apMatchType = baseInfo->getApMatchType ();               //get match type
    if(WLAN_AP_SEARCH == apMatchType)
    {
        if(m_scanApList.contains (baseInfo) == VFX_TRUE)
        {
        	if(SRV_DTCNT_WLAN_AP_UNKNOW == baseInfo->getApMgrType())
			{
				//set Ap Mgr Type
				baseInfo->setApMgrType(SRV_DTCNT_WLAN_AP_USER_DEFINE);
			}			
            baseInfo->setApMatchType (WLAN_AP_SEARCH_SAVED_CONNECTED);
            if(m_savedApList.contains (baseInfo) == VFX_FALSE)
            {
                VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_INSERT);
                baseInfo->setPriority (1);
				
				// get activatedAp by baseInfo	
			    VappWlanProfile *activatedAp = NULL;
			 	VFX_OBJ_CREATE(activatedAp, VappWlanProfile, this);
				VappWlanToolbox::getAppProfileByAppBaseInfo(baseInfo, activatedAp);
			    // save user input after connect successfully
			    VappWlanToolbox::saveSecurityInfo (&m_apToBeActivated, activatedAp);
				
			    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_RESULT_SUCCESS_AP_WEP_KEY, 
			            activatedAp->getWepKeyIndex (),
			            activatedAp->getWepKeyLen (),
			            activatedAp->getWepKeyFormat (),
			            strlen((const char*)activatedAp->getWepKey ()));
			    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_RESULT_SUCCESS_AP_ENCRYPT_MODE, 
			            connRes->encry_mode, activatedAp->getEncryptMode (), __LINE__);
			            
                insertApIntoSavedListAfterConnected(VFX_TRUE, activatedAp);

                // conn succ, AP will have profileId. So update baseInfo profileId.
				baseInfo->setProfileId(activatedAp->getProfileId());
				
				VFX_OBJ_CLOSE(activatedAp);
            }
            // Set connection as current highlighted ap
            setConnectedAP(baseInfo);
            VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_REMOVE);
            m_scanApList.removeOne (baseInfo);
        }
    }
    else
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_DO_NOTHING);
        // update ap's match type
        if(WLAN_AP_SEARCH_SAVED == apMatchType)
        {
            baseInfo->setApMatchType (WLAN_AP_SEARCH_SAVED_CONNECTED);
        }
        else if(WLAN_AP_SAVED == apMatchType)
        {
            baseInfo->setApMatchType (WLAN_AP_SAVED_CONNECTED);
        }
        VFX_TRACE(("===== Set current connection's status (%d)=====\n",
                                            baseInfo->getApMatchType ()));
        VfxU8 oldPriority = baseInfo->getPriority ();
        if(1 != oldPriority)
        {
            baseInfo->setPriority (1);
            updatePriorityAfterConnected(VFX_TRUE, oldPriority, baseInfo);
        }
        // Set connection as current highlighted ap
        setConnectedAP(baseInfo);
    }
	
	//set UI status machine
	if(SRV_DTCNT_WLAN_AP_DEFAULT == baseInfo->getApMgrType())
	{
		setWlanUiFlow (WLAN_UI_WAIT_FOR_IP_UPDATE);
	}
	else
	{			
		setWlanUiFlow (WLAN_UI_NONE);
	}			
    // Set current status  
    setCurWlanStatus ();
    // Refresh the display ap list and save ap pointer list
    updateApList();
}

void VappWlanRepository::afterAbortConnect()
{
    VappWlanProfile* activatedAp = NULL;
    
    activatedAp = getApToBeActivated ();
    if(activatedAp != NULL)
    {
        // Clean the incorrect password user input
        if(activatedAp->getApMatchType () == WLAN_AP_SEARCH)
        {
            VappWlanToolbox::cleanSecurityInfo(activatedAp);
        }
    }
    // Set connection as none
    resetConnectedAP();
    // Set current status  
    setCurWlanStatus ();
    // Refresh the display ap list and save ap pointer list
    updateApList();
}

void VappWlanRepository::afterConnectedFailed(VfxU32 profileId)
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
#endif

	//set UI status machine
	setWlanUiFlow (WLAN_UI_NONE);
    // Set connection as none
    resetConnectedAP();
    // Set current status  
    setCurWlanStatus ();
    // Refresh the display ap list and save ap pointer list
    updateApList();
}

#ifdef __WPS_SUPPORT__
void VappWlanRepository::afterConnectedSuccessByWps(srv_dtcnt_wlan_conn_res_struct* connRes)
{
    VappWlanProfile	*activatedAp = NULL;
   	mmi_chset_enum 	ret_charset; 
	
    VFX_OBJ_CREATE (activatedAp, VappWlanProfile, this);
    VappWlanToolbox::initWlanProfile (activatedAp);

    // Set property
    activatedAp->setSsidLen (connRes->ssid_len);
    activatedAp->setSsid (connRes->ssid, connRes->ssid_len);
    activatedAp->setBssid (connRes->bssid);
    activatedAp->setChannelNumber (connRes->channel_number);                // Channel Number
    activatedAp->setConnType (connRes->conn_type);                          // Conn. Type
    activatedAp->setNetworkType (SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA);        // Network Type
    activatedAp->setAuthMode ((srv_dtcnt_wlan_auth_mode_enum)connRes->auth_type);           // Auth. Mode
    activatedAp->setEncryptMode ((srv_dtcnt_wlan_encrypt_mode_enum)connRes->encry_mode);    // Encrypt Mode
    activatedAp->setEapTtlsAuthType (connRes->eap_ttls_auth_type);          // EAP TTLS
    activatedAp->setEapPeapAuthType (connRes->eap_peap_auth_type);          // EAP PEAP
    // activatedAp->setPassphrase (connRes->passphase, connRes->passphase_len);
    activatedAp->clearPsk();    
	activatedAp->clearPassphrase();
    activatedAp->setPsk (connRes->passphase, connRes->passphase_len);

 	// Set AP's Name here
 	VfxU8   *name;
 	VFX_ALLOC_MEM(name, WLAN_PROF_NAME_LEN_MAX * ENCODING_LENGTH, this);
    memset(name, 0, WLAN_PROF_NAME_LEN_MAX * ENCODING_LENGTH);
 	custom_wlan_ssid_convert_ex(
		(CHAR *)activatedAp->getSsid (), 
		(CHAR *)name, 
		activatedAp->getSsidLen(), 
		&ret_charset);	
	activatedAp->setApName (name);
	activatedAp->setApCharset(ret_charset);
 	VFX_FREE_MEM (name);
 	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_SCAN_AP_CHARSET,
			activatedAp->getSsidLen (),
			activatedAp->getApCharset());

	// Set AP's Mgr type
#ifdef __MMI_OP01_WIFI__    
	if(SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA == activatedAp->getNetworkType()&&
		SRV_DTCNT_WLAN_AUTH_MODE_OPEN == activatedAp->getAuthMode()&&
		custom_wlan_is_operator_network((const char*)activatedAp->getSsid()))
	{	
		activatedAp->setApMgrType (SRV_DTCNT_WLAN_AP_DEFAULT);//set AP Mgr type
	}
#endif

	// CMCC or CMCC-EDU has been preseted in SavedAplist.
    if(VFX_FALSE == m_savedApList.contains (activatedAp))
    {   	
		activatedAp->setApMgrType (SRV_DTCNT_WLAN_AP_USER_DEFINE);//set AP Mgr type
        activatedAp->setApMatchType (WLAN_AP_SEARCH_SAVED_CONNECTED);
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_INSERT);
        activatedAp->setPriority (1);
        insertApIntoSavedListAfterConnected(VFX_TRUE, activatedAp);
        // Set connection as current highlighted ap
        setConnectedAP(activatedAp);
    }
    else
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_DO_NOTHING);
        VappAPListEntry *onlyOne = m_savedApList.getEntry (activatedAp);
        VappWlanBaseInfo *itsYou = onlyOne->get ();
        VFX_ASSERT (itsYou);
		
		// Set AP's Mgr type, if AP is in blacklist, change mgr type to USER_DEFINE and update dtnct store
		if(SRV_DTCNT_WLAN_AP_BLACK_LIST == itsYou->getApMgrType()) 
		{
			itsYou->setApMgrType(SRV_DTCNT_WLAN_AP_USER_DEFINE);			
            updateProfileInDtcntStoreByBaseInfo (SRV_DTCNT_WLAN_PROF_FIELD_AP_TYPE, itsYou);
		}
		// Set AP's Match type
        itsYou->setApMatchType (WLAN_AP_SEARCH_SAVED_CONNECTED);
		
        VfxU8 oldPriority = itsYou->getPriority ();
        if(1 != oldPriority)
        {
            itsYou->setPriority (1);
            updatePriorityAfterConnected(VFX_TRUE, oldPriority, itsYou);
        }
        // Set connection as current highlighted ap
        setConnectedAP(itsYou);
    }
    // Filter newly connected AP from scan AP list
    VappAPListEntry* entry = m_scanApList.getEntry (activatedAp);
    if(entry)   // Found
    {
        m_scanApList.removePos (entry);
    }
	//set UI status machine	, CMCC don't has WPS conn?
	if(SRV_DTCNT_WLAN_AP_USER_DEFINE == activatedAp->getApMgrType())
	{	
		setWlanUiFlow (WLAN_UI_WAIT_FOR_IP_UPDATE);
	}
	else
	{		
		setWlanUiFlow (WLAN_UI_NONE);
	}
    // Set current status  
    setCurWlanStatus ();
    // Refresh the display ap list and save ap pointer list
    updateApList();

    VFX_OBJ_CLOSE (activatedAp);
}

void VappWlanRepository::afterConnectedFailedByWps(srv_dtcnt_wlan_conn_res_struct* connRes)
{
	//set UI status machine	
	setWlanUiFlow (WLAN_UI_NONE);
    // Set connection as none
    resetConnectedAP();
    // Set current status  
    setCurWlanStatus ();
    // Refresh the display ap list and save ap pointer list
    updateApList();
}

void VappWlanRepository::afterReceiveWPSInfoEvt(srv_dtcnt_wlan_wps_info_evt_struct* wpsInfo)
{
	VAPP_WLAN_WPS_STATUS wpsStatus = getWpsStatus();
	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_WPS_STATUS, wpsStatus); 
	
    if(wpsInfo->num == 1)
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_WPS_INFO, 
            wpsInfo->num, wpsInfo->info[0].action, wpsInfo->info[0].value);
		if(2 == wpsInfo->info[0].action && 1 == wpsInfo->info[0].value)
		{
			// WPS APs overLapped on, may be recieve OFF before ON.
			// VFX_ASSERT(WLAN_WPS_STATUS_INIT == wpsStatus);
			setWpsStatus(WLAN_WPS_STATUS_OVERLAP_ON);
		}
		else if(2 == wpsInfo->info[0].action && 0 == wpsInfo->info[0].value)
		{
			// WPS APs overLapped on, may be recieve OFF before ON.
			//VFX_ASSERT(WLAN_WPS_STATUS_OVERLAP_ON == wpsStatus);
			setWpsStatus(WLAN_WPS_STATUS_OVERLAP_OFF);			
		}
		else
		{
			//WPS INIT
        	setWpsInfo (wpsInfo->info[0].action, wpsInfo->info[0].value);
			setWpsStatus(WLAN_WPS_STATUS_INIT);
		}
    }
    else if(wpsInfo->num == 2)
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_WPS_INFO, 
            wpsInfo->num, wpsInfo->info[0].action, wpsInfo->info[0].value);        
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_WPS_INFO, 
            wpsInfo->num, wpsInfo->info[1].action, wpsInfo->info[1].value);
		if( (2 == wpsInfo->info[0].action && 1 == wpsInfo->info[0].value) || 
			(2 == wpsInfo->info[1].action && 1 == wpsInfo->info[0].value) )
		{
			// WPS APs overLapped on, may be recieve OFF before ON.
			//VFX_ASSERT(WLAN_WPS_STATUS_INIT == wpsStatus);
			setWpsStatus(WLAN_WPS_STATUS_OVERLAP_ON);
		}
		else if( (2 == wpsInfo->info[0].action && 0 == wpsInfo->info[0].value) || 
				 (2 == wpsInfo->info[1].action && 0 == wpsInfo->info[0].value) )
		{
			// WPS APs overLapped on, may be recieve OFF before ON.
			// VFX_ASSERT(WLAN_WPS_STATUS_OVERLAP_ON == wpsStatus);
			setWpsStatus(WLAN_WPS_STATUS_OVERLAP_OFF);
		}
		else
		{		
			//WPS INIT
       		setWpsInfo (wpsInfo->info[0].action, wpsInfo->info[0].value);
        	setWpsInfo (wpsInfo->info[1].action, wpsInfo->info[1].value);
			setWpsStatus(WLAN_WPS_STATUS_INIT);
		}
    }
}
#endif

VfxBool VappWlanRepository::afterReceiveConnectInd(srv_dtcnt_wlan_conn_res_struct* connRes)
{
    VappAPListEntry* entry = NULL;
    
    if(connRes->profile_id > 0)
    {
        entry = m_savedApList.findOne (connRes->profile_id);
    }
    else
    {
        entry = m_savedApList.search (connRes->bssid, connRes->ssid, (VfxU8)connRes->ssid_len);
    }
    
    if(NULL == entry || SRV_DTCNT_WLAN_AP_UNKNOW == entry->get()->getApMgrType())
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_IND_FAILED, connRes->profile_id, entry->get()->getApMgrType());
		srv_dtcnt_wlan_disconnect();
        return VFX_FALSE;
    }
    else
    {
        VappWlanBaseInfo *item = entry->get ();
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_IND_SUCCESS, 
            connRes->profile_id, item->getProfileId (), item->getSsidLen (), item->getPriority (), item->getApMatchType ());

		// Set AP's Mgr type, if AP is in blacklist, change mgr type to USER_DEFINE and update dtnct store
		if(SRV_DTCNT_WLAN_AP_BLACK_LIST == item->getApMgrType()) 
		{
			item->setApMgrType(SRV_DTCNT_WLAN_AP_USER_DEFINE);			
            updateProfileInDtcntStoreByBaseInfo (SRV_DTCNT_WLAN_PROF_FIELD_AP_TYPE, item);
		}
		
        VAPP_WLAN_AP_CHANGE_ENUM apMatchType = item->getApMatchType ();
        if(WLAN_AP_SEARCH == apMatchType ||
           WLAN_AP_SEARCH_SAVED == apMatchType)
        {
            item->setApMatchType (WLAN_AP_SEARCH_SAVED_CONNECTED);
        }
        else if(WLAN_AP_SAVED == apMatchType)
        {
            item->setApMatchType (WLAN_AP_SAVED_CONNECTED);
        }
		//set UI status machine
		if(SRV_DTCNT_WLAN_AP_DEFAULT == item->getApMgrType())
		{
			setWlanUiFlow (WLAN_UI_WAIT_FOR_IP_UPDATE);
		}
		else
		{			
			setWlanUiFlow (WLAN_UI_NONE);
		}	
        // Set channel number for the connected ap
        item->setChannelNumber (connRes->channel_number);
        // Set connection as current highlighted ap
        setConnectedAP(item);
        // Set current status  
        setCurWlanStatus ();
        // Refresh the display ap list and save ap pointer list
        updateApList();
    }
    return VFX_TRUE;
}

void VappWlanRepository::afterDisconnected()
{
	//set UI status machine	
	setWlanUiFlow (WLAN_UI_NONE);
    // Set current status  
    setCurWlanStatus ();
    // Reset connected ap
    memset(&m_connectBaseInfo, 0, sizeof(VappWlanBaseInfo));
    // Refresh the display ap list
    updateApList();
}

void VappWlanRepository::afterDeinit()
{
	//set UI status machine	
	setWlanUiFlow (WLAN_UI_NONE);
    // Set current status  
    setCurWlanStatus ();
    // Reset connected ap
    memset(&m_connectBaseInfo, 0, sizeof(VappWlanBaseInfo));
    // Refresh the display ap list
    updateApList();
}


void VappWlanRepository::afterUpdateIpAddr(srv_dtcnt_wlan_ipaddr_update_struct *ipAddrUpdate)
{
    VappWlanBaseInfo *connectApBaseInfo = NULL;
	VappWlanProfile		*connectApProfile = NULL;

    // Check connected Ap's SSID length
    if(SRV_DTCNT_WLAN_STATUS_CONNECTED != m_curWlanStatus || 
       0 == m_connectBaseInfo.getSsidLen ())
    {
        return;
    }
    else
    {
		connectApBaseInfo = getInApList(&m_connectBaseInfo);	
		if(connectApBaseInfo == NULL || WLAN_AP_SEARCH == connectApBaseInfo->getApMatchType())
		{
			return;
		}

		VFX_OBJ_CREATE(connectApProfile, VappWlanProfile, this);
		VappWlanToolbox::initAppProfileByAppBaseInfo(connectApBaseInfo, connectApProfile);
		
		// update tcp/ip settings in the saved ap list
        connectApProfile->setIpAddr (ipAddrUpdate->ip_addr);
        connectApProfile->setNetmask (ipAddrUpdate->netmask);
        connectApProfile->setGateway (ipAddrUpdate->gateway);
        connectApProfile->setDns1 (ipAddrUpdate->dns1);
        connectApProfile->setDns2 (ipAddrUpdate->dns2);
			
		// update info for the connected ap in the nvram
		updateProfileInDtcntStore(
				SRV_DTCNT_WLAN_PROF_FIELD_DHCP |
				SRV_DTCNT_WLAN_PROF_FIELD_IP |
				SRV_DTCNT_WLAN_PROF_FIELD_NETMASK |
				SRV_DTCNT_WLAN_PROF_FIELD_GATEWAY |
				SRV_DTCNT_WLAN_PROF_FIELD_DNS1 |
				SRV_DTCNT_WLAN_PROF_FIELD_DNS2,
				connectApProfile);
		
		VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_UPDATE_IP_ADDR, ipAddrUpdate->ip_addr[0], ipAddrUpdate->ip_addr[1], ipAddrUpdate->ip_addr[2], ipAddrUpdate->ip_addr[3]);
		VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_UPDATE_NETMASK, ipAddrUpdate->netmask[0], ipAddrUpdate->netmask[1], ipAddrUpdate->netmask[2], ipAddrUpdate->netmask[3]);
		VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_UPDATE_GATEWAY, ipAddrUpdate->gateway[0], ipAddrUpdate->gateway[1], ipAddrUpdate->gateway[2], ipAddrUpdate->gateway[3]);
		VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_UPDATE_DNS1, ipAddrUpdate->dns1[0], ipAddrUpdate->dns1[1], ipAddrUpdate->dns1[2], ipAddrUpdate->dns1[3]);
		VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_UPDATE_DNS2, ipAddrUpdate->dns2[0], ipAddrUpdate->dns2[1], ipAddrUpdate->dns2[2], ipAddrUpdate->dns2[3]);

		VFX_OBJ_CLOSE(connectApProfile);
	}
}

void VappWlanRepository::afterChangeIpAddr(srv_dtcnt_wlan_ipaddr_change_qry_evt_struct* ipAddrChangeEvt)
{
    VappWlanProfile 	*profile = NULL;	
    VappWlanBaseInfo *baseInfo = NULL;
    srv_dtcnt_wlan_ipaddr_update_struct ipAddrStruct;
    MMI_BOOL        useDHCP;
	supc_connection_type_enum connType = getAPConnTypeSequence(0); 
#ifdef  __WPS_SUPPORT__	
    VfxBool inWpsConn = VFX_FALSE;   
#endif /* __WPS_SUPPORT__*/
	VfxBool isCreateObj = VFX_FALSE;

	if( getAPConnNum() > 1)
	{
		// Not sure that whether this event happen before or after connect_cnf
		// so ignore the event when connNum > 1.
		return;
	}
	
#ifdef  __WPS_SUPPORT__			
	if( START_WPS_PIN == connType || START_WPS_PBC == connType )
	{
		inWpsConn = VFX_TRUE;
	}  
#endif /* __WPS_SUPPORT__*/

    /// ? Not sure that whether this event happen before or after connect_cnf
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CHANGE_IP_ADDR_START, m_curWlanStatus);
    if(SRV_DTCNT_WLAN_STATUS_CONNECTED == m_curWlanStatus)
    {
        baseInfo = &m_connectBaseInfo;
    }
    else
    {
#ifdef  __WPS_SUPPORT__	
		if(inWpsConn)
        {
            profile = &m_apToBeActivated;
        }
        else
        {
        	baseInfo = getInApList(&m_apToBeActivated);
        }
#else      
		baseInfo = getInApList(&m_apToBeActivated);
#endif
    }

	//if profile and baseInfo are NULL, do nothing.
	if(profile != NULL || baseInfo != NULL)
	{
	    if(profile == NULL)
	    {
		 	VFX_OBJ_CREATE(profile, VappWlanProfile, this);
			VappWlanToolbox::getAppProfileByAppBaseInfo(baseInfo, profile);
			isCreateObj = VFX_TRUE;
		}
		
	    memcpy(ipAddrStruct.ip_addr, profile->getIpAddr (), SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
	    memcpy(ipAddrStruct.netmask, profile->getNetmask (), SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
	    memcpy(ipAddrStruct.gateway, profile->getGateway (), SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
	    memcpy(ipAddrStruct.dns1, profile->getDns1 (), SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
	    memcpy(ipAddrStruct.dns2, profile->getDns2 (), SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);	
		
	    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CHANGE_USE_DHCP, profile->getUseDhcp ());
	    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CHANGE_IP_ADDR, ipAddrStruct.ip_addr[0], ipAddrStruct.ip_addr[1], ipAddrStruct.ip_addr[2], ipAddrStruct.ip_addr[3]);
	    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CHANGE_NETMASK, ipAddrStruct.netmask[0], ipAddrStruct.netmask[1], ipAddrStruct.netmask[2], ipAddrStruct.netmask[3]);
	    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CHANGE_GATEWAY, ipAddrStruct.gateway[0], ipAddrStruct.gateway[1], ipAddrStruct.gateway[2], ipAddrStruct.gateway[3]);
	    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CHANGE_DNS1, ipAddrStruct.dns1[0], ipAddrStruct.dns1[1], ipAddrStruct.dns1[2], ipAddrStruct.dns1[3]);
	    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CHANGE_DNS2, ipAddrStruct.dns2[0], ipAddrStruct.dns2[1], ipAddrStruct.dns2[2], ipAddrStruct.dns2[3]);

	    if(profile->getUseDhcp ())
	    {
	       	useDHCP = MMI_TRUE;
	    }
	    else
	    {
	        useDHCP = MMI_FALSE;
	    }
	    ipAddrChangeEvt->ipaddr_change_cb(useDHCP, &ipAddrStruct);
	}
	
	if(VFX_TRUE == isCreateObj)
	{
		VFX_OBJ_CLOSE(profile);
	}
}

void VappWlanRepository::afterInsertApIntoSavedList(VappWlanProfile* profile)
{
    VFX_TRACE(("------->Insert<-------\n"));
    if(m_savedApList.contains (profile) == VFX_FALSE)
    {
    	// get add Ap type
		VAPP_WLAN_ADD_AP_TYPE apType = getAddApType();
		switch(apType)
		{
		case VAPP_WLAN_ADD_SAVED_AP:
			profile->setApMgrType(SRV_DTCNT_WLAN_AP_USER_DEFINE);
			break;
		case VAPP_WLAN_ADD_BLOCKED_AP:
			profile->setApMgrType(SRV_DTCNT_WLAN_AP_BLACK_LIST);
			break;			
		case VAPP_WLAN_ADD_REMEMBER_AP:
			profile->setApMgrType(SRV_DTCNT_WLAN_AP_USER_DEFINE);
			break;	
		default :
			VFX_ASSERT(NULL);
		}
		
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_ADD_NEW_NETWORK_START);
        // profile->setPriority (getSavedApNum () + 1);
        insertApIntoSavedList(VFX_TRUE, profile);
        VFX_TRACE(("------->New ap's profile id: %d!<-------\n", profile->getProfileId ()));
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_ADD_NEW_NETWORK_END, profile->getProfileId ());
        // Refresh the display ap list and save ap pointer list
        updateApList();
    }
}

void VappWlanRepository::afterEditAp(VappWlanProfile* originalProfile, VappWlanProfile* profile)
{
    VFX_TRACE(("------->Edit<-------\n"));
    if(WLAN_AP_SEARCH == originalProfile->getApMatchType ())
    {
        // Set its match type as WLAN_AP_SEARCH_SAVED
        profile->setApMatchType (WLAN_AP_SEARCH_SAVED);
        editSearchProfile (originalProfile, profile);
    }
    else
    {
        editSavedProfile (profile);
    }
    
    // update ap list and saved array
    updateApList();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_EDIT_NETWORK_END);
}

void VappWlanRepository::afterRemoveApFromList(VfxU8 index, VappWlanBaseInfo * const *apList)
{
    VappWlanBaseInfo *item = NULL;
    VappWlanBaseInfo *baseInfo = NULL;
	
	baseInfo = apList[index];
	switch(baseInfo->getApMatchType())
	{
	case WLAN_AP_SEARCH_SAVED:
	case WLAN_AP_SAVED:		
	    if(m_savedApList.contains (baseInfo) == VFX_TRUE)
	    {
	        VfxU8 priority = baseInfo->getPriority ();
	        VFX_TRACE(("------->Remove %s from saved ap list!<-------\n",
	            baseInfo->getSsid ()));
	        VFX_TRACE(("------->Its profile id is %d \t priority: %d!<-------\n",
	            baseInfo->getProfileId (), baseInfo->getPriority()));
	        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_DELETE_NETWORK_START,
	            baseInfo->getSsidLen (), baseInfo->getProfileId (), baseInfo->getPriority ());
	        // 1. modify counter
	        if(SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA == baseInfo->getNetworkType ())
	            --m_infraApNum;
	        else
	            --m_adhocApNum;
	        // 2. remove it from dtcnt wlan storage
	        removeProfileFromDtcntStore (baseInfo);
	        // 3. remove it from saved list
	        m_savedApList.removeOne (baseInfo);

	        VappAPListEntry *entry = m_savedApList.getValidHead ();
	        // Go through the saved list
	        while(NULL != entry)
	        {
	            item = (VappWlanBaseInfo *)entry->get();
	            if(item->getPriority () > priority)
	            {
	                VfxU8 prePriority = item->getPriority ();
	                item->setPriority (prePriority - 1);

					// update property of each ap in the dtcnt wlan storage
	                updateProfileInDtcntStoreByBaseInfo (SRV_DTCNT_WLAN_PROF_FIELD_PRIORITY, item); 
					
	                VFX_TRACE(("------->Change AP(%s)'s priority as %d<-------\n",
	                            item->getSsid (), item->getPriority ()));
	            }
	            entry = entry->getValidNext ();
	        }
	        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_DELETE_NETWORK_END);
	    }	
		break;		
	case WLAN_AP_SEARCH:
	    m_scanApList.removeOne (baseInfo);
		break;
	case WLAN_AP_SEARCH_SAVED_CONNECTED:
	case WLAN_AP_SAVED_CONNECTED:
	default :
		VFX_ASSERT(NULL);
	}	
}

void VappWlanRepository::afterChangePriority(VappWlanBaseInfo** m_tempSavedApList, VfxU8* priorityList)
{
    VfxU8 index = 0;
    VfxU8 total = getRememberedApNum ();
    VfxU8 count = 0;
    VappAPListEntry 	*entry = NULL;
    VappWlanBaseInfo *item = NULL; 

    for(; index < total; index++)
    {
        // 1. Go through the temp ap list
        // Update priority of each ap in the saved list
        entry = m_savedApList.getEntry (m_tempSavedApList[index]);
        if(entry != NULL)
        {
            item = entry->get ();
            VFX_TRACE(("------->Profile(%s)'s <-------\n", 
                item->getSsid ()));
            VFX_TRACE(("------->Change priority from %d to %d <-------\n", 
                item->getPriority (), priorityList[count]));
            VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_CHANGE_NETWORK_PRIORITY, 
                item->getProfileId (), item->getPriority (), priorityList[count]);
            item->setPriority (priorityList[count]);

        // 2. Update property of each ap in the dtcnt wlan storage
            updateProfileInDtcntStoreByBaseInfo (SRV_DTCNT_WLAN_PROF_FIELD_PRIORITY, item);
        }
        count++;
    }
}

void VappWlanRepository::afterRefreshConnectedAP(srv_dtcnt_wlan_curr_ap_info_struct* currApInfo)
{
	VappAPListEntry 	*entry = NULL;
	VappWlanBaseInfo *item = NULL;
	
    setCurWlanStatus ();	
	m_connectBaseInfo.setRssi (currApInfo->rssi);
	if(currApInfo->current_data_rate == 0)
	{
    	m_connectBaseInfo.setMaxRate (currApInfo->ht_current_data_rate);  
	}
	else
	{		
    	m_connectBaseInfo.setMaxRate (currApInfo->current_data_rate);  
	}
	
    entry = m_savedApList.getValidHead ();
    while(NULL != entry)
    {		
        item = (VappWlanBaseInfo *)entry->get();	
		if(SRV_DTCNT_WLAN_STATUS_CONNECTED == m_curWlanStatus && 
							VappWlanToolbox::isSameAP (&m_connectBaseInfo, item))
		{
		    item->setRssi (currApInfo->rssi);
			if(currApInfo->current_data_rate == 0)
			{
		    	item->setMaxRate (currApInfo->ht_current_data_rate);  
			}
			else
			{		
		    	item->setMaxRate (currApInfo->current_data_rate);  
			}
			return;
		}		
        entry = entry->getValidNext ();
    }
}

void VappWlanRepository::updateApPriorityInDbSrv(VfxBool isStore, VfxU8 replacedPriority, VappWlanProfile* newOne)
{
    VappAPListEntry 	*entry = m_savedApList.getValidHead ();
    VappWlanBaseInfo *item = NULL;
	
    // 1. Update all ap's priority in Db Srv
    if(VFX_TRUE == isStore)
    {
        while(entry)
        {
            item = entry->get ();
            VFX_TRACE(("SSID: %s \t Priority: %d replaced one's priority: %d\n", 
                item->getSsid (), item->getPriority (), replacedPriority));
            VFX_TRACE(("Profile ID %d Newly added profile's profile ID: %d\n", 
                item->getProfileId (), newOne->getProfileId ()));
            if(isStore)
            {
                // update property of each ap in the dtcnt wlan storage
                updateProfileInDtcntStoreByBaseInfo (SRV_DTCNT_WLAN_PROF_FIELD_PRIORITY, item); 
            }        
            entry = entry->getNext ();
        }
    }
}

void VappWlanRepository::insertApIntoSavedList(VfxBool isStore, VappWlanProfile* profile)
{
    VfxU8 replacedPriority = 0;
    VappAPListEntry* lowestOne;
    srv_dtcnt_wlan_network_type_enum ApNetworkType;  
		
    // 1. Verify whether the count of ap reached maxium
    //    Yes. Replace one ap which has the same type as new one
    //    If there is no ap with same type existed, replace the ap which has lowest priority
    
    // 2. If not, insert ap into saved list
    //    a. if network type is infra, insert it after the last ad-hoc ap in the list
    //    b. if network type is adhoc, insert it in the first position of list
    if(WLAN_SAVED_AP_LIST_NUM_MAX == m_savedApList.getValidCount ())
    {
        if(SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA == profile->getNetworkType ())
        {
            // if all the ap's network type in the list is adhoc, then remove the one has lowest priority
            if(WLAN_SAVED_AP_LIST_NUM_MAX == m_adhocApNum)
            {
                // 1. Find the ap which has lowest priority and its type is ADHOC
                lowestOne = findProfileWithLowestPriority (SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC);
                replacedPriority = lowestOne->get ()->getPriority ();
                profile->setPriority (replacedPriority);
                
                // 2. Replace new profile into dtcnt profile storage
                if(VFX_TRUE == isStore)
                {
                    removeProfileFromDtcntStore (lowestOne->get ());
                    saveProfileInDtcntStore (SRV_DTCNT_WLAN_PROF_FIELD_ALL, profile);
                }
                
                // 3. Remove the last adhoc ap in the list and append a new one
                VFX_TRACE(("==> Remove ap(%s) from list and its priority is %d\n", 
                    lowestOne->get()->getSsid (), lowestOne->get ()->getPriority ()));
                m_savedApList.removePos (lowestOne);
                m_savedApList.append(profile);

                // 4. Update all ap's priority
                updateApPriorityInDbSrv(isStore, replacedPriority, profile);
                
                // 5. modify counter
                ++m_infraApNum;
                --m_adhocApNum;
            }
            else
            {
                // 1. set priority as same as the replaced one
                VFX_TRACE(("==> The num of infra ap is %d\n", m_infraApNum));
                VFX_TRACE(("==> The num of adhoc ap is %d\n", m_adhocApNum));
                lowestOne = findProfileWithLowestPriority (SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA);				
				if(NULL == lowestOne)//only default AP is infra network.
				{
					lowestOne = findProfileWithLowestPriority (SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC);
				}				
				ApNetworkType = lowestOne->get ()->getNetworkType();			
                replacedPriority = lowestOne->get ()->getPriority ();
                profile->setPriority (replacedPriority);            
                // 2. Save profile into dtcnt profile storage
                if(VFX_TRUE == isStore)
                {
                    removeProfileFromDtcntStore (lowestOne->get ());
                    saveProfileInDtcntStore (SRV_DTCNT_WLAN_PROF_FIELD_ALL, profile);
                }               
                // 3. Remove the last ap in the list and insert a new one
                VFX_TRACE(("==> Remove ap(%s) from list and its priority is %d\n", 
                    lowestOne->get()->getSsid (), lowestOne->get ()->getPriority ()));				
                m_savedApList.removePos (lowestOne);				
				// default CMCC AP can't delete, so need to verify network type
				if(SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA == ApNetworkType)
                {
                	m_savedApList.insertAt (m_adhocApNum, profile);
				}
				else
				{
					m_savedApList.insertAt (m_adhocApNum - 1, profile);
					// modify counter
                	++m_infraApNum;
                	--m_adhocApNum;
				}				
                // 4. Update all ap's priority
                updateApPriorityInDbSrv(isStore, replacedPriority, profile);
            }
        }
        else
        {
            // 1. set priority as same as the replaced one
            if(m_adhocApNum > 0)
            {
                lowestOne = findProfileWithLowestPriority (SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC);
            }
            else /* the num of adhoc ap is 0 */
            {
                lowestOne = findProfileWithLowestPriority (SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA);
                
                --m_infraApNum;
                ++m_adhocApNum;
            }
            replacedPriority = lowestOne->get ()->getPriority ();
            profile->setPriority (replacedPriority);
            
            // 2. Save profile into dtcnt profile storage
            if(VFX_TRUE == isStore)
            {
                removeProfileFromDtcntStore (lowestOne->get ());
                saveProfileInDtcntStore (SRV_DTCNT_WLAN_PROF_FIELD_ALL, profile);
            }
            
            // 3. Remove the first one ap in the list
            VFX_TRACE(("==> Remove ap(%s) from list and its priority is %d\n", 
                lowestOne->get()->getSsid (), lowestOne->get ()->getPriority ()));
            m_savedApList.removePos (lowestOne);
            m_savedApList.prepend (profile);

            // 4. Update all ap's priority
            updateApPriorityInDbSrv(isStore, replacedPriority, profile);
        }
    }
    else
    {
        VFX_TRACE(("=========> Profile's SSID: %s \t priority: %d\n", profile->getSsid (), profile->getPriority ()));
        if(isStore)
        {
            switch(profile->getNetworkType ())
            {
            case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
                // 1. set priority as the count of infra ap
                profile->setPriority (m_infraApNum + 1);
                // 2. save profile into dtcnt profile storage
                saveProfileInDtcntStore (SRV_DTCNT_WLAN_PROF_FIELD_ALL, profile);
                // 3. query the priority of newly added profile
                VFX_ASSERT(VappWlanToolbox::checkPriorityInSrvDb(profile));
                // 4. adjust the other ad-hoc profile's priority
                if(m_adhocApNum != 0)
                {
                    VappAPListEntry 	*entry = m_savedApList.getValidHead ();
                    VappWlanBaseInfo	*item = NULL;
					
                    while(entry)
                    {
                        item = entry->get ();
                        VFX_TRACE(("SSID: %s \t Priority: %d replaced one's priority: %d\n", 
                            item->getSsid (), item->getPriority (), m_infraApNum + 1));
                        if(item->getPriority () > m_infraApNum)
                        {
                            VfxU8 priority = item->getPriority ();
                            item->setPriority (priority + 1);
							
							// update property of each ap in the dtcnt wlan storage
                            updateProfileInDtcntStoreByBaseInfo (SRV_DTCNT_WLAN_PROF_FIELD_PRIORITY, item); 							
                        }
                        entry = entry->getNext ();
                    }					
                }
                
                break;
            case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
                // 1. set priority as the count of adhoc ap
                profile->setPriority (m_infraApNum + m_adhocApNum + 1);
                // 2. Save profile into dtcnt profile storage
                saveProfileInDtcntStore (SRV_DTCNT_WLAN_PROF_FIELD_ALL, profile);
                // 3. query the priority of newly added profile
                VFX_ASSERT(VappWlanToolbox::checkPriorityInSrvDb(profile));
                break;
            default:
                VFX_ASSERT(0);
            }
        }
        // 3. insert the new one and modify counter
        VFX_TRACE(("==> Add ap(%s) into list and its priority is %d\n", 
                profile->getSsid (), profile->getPriority ()));
        if(SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA == profile->getNetworkType ())
        {        
        	// on bootUp proc, CMCC is high than CMCC-EDU.
            m_savedApList.insertAt (m_adhocApNum + m_infraApNum, profile);
            ++m_infraApNum;
        }
        else
        {
            m_savedApList.prepend (profile);
            ++m_adhocApNum;
        }
    }
}

void VappWlanRepository::insertApIntoSavedListAfterConnected(VfxBool isStore, VappWlanProfile *profile)
{
    VappAPListEntry			*lowestOne = NULL;
    VappAPListEntry			*entry = NULL;
    VappWlanBaseInfo		*item = NULL;
    VfxU8            		priority = 0;
    VfxU8            		replacedPriority = 0;
    srv_dtcnt_wlan_network_type_enum ApNetworkType = SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA;  
    
    // 1. Verify whether the count of ap reached maxium
    //    Yes. Remove ap which has same network type and the lowest priority
    //    If there is no ap with same type existed, replace the ap which has lowest priority
    
    // 2. If not, insert ap into saved list at first place
    if(WLAN_SAVED_AP_LIST_NUM_MAX == m_savedApList.getValidCount ())
    {
        if(SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA == profile->getNetworkType ())
        {
            // if all the ap's network type in the list is adhoc, then remove the one has lowest priority
            if(WLAN_SAVED_AP_LIST_NUM_MAX == m_adhocApNum)
            {
                // 1. Find the ap which has lowest priority and its type is ADHOC
                lowestOne = findProfileWithLowestPriority (SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC);
                replacedPriority = lowestOne->get ()->getPriority ();
                // 2. Save profile into dtcnt profile storage
                if(VFX_TRUE == isStore)
                {
                    removeProfileFromDtcntStore (lowestOne->get());
                    saveProfileInDtcntStore (SRV_DTCNT_WLAN_PROF_FIELD_ALL, profile);
                }
                // 3. Remove the last adhoc ap in the list and append a new one
                VFX_TRACE(("==> Remove ap(%s) from list and its priority is %d\n", 
                    lowestOne->get()->getSsid (), lowestOne->get ()->getPriority ()));
                m_savedApList.removePos (lowestOne);
                m_savedApList.append(profile);
                // 4. modify counter
                ++m_infraApNum;
                --m_adhocApNum;

            }
            else
            {
                // 1. set priority as same as the replaced one
                VFX_TRACE(("==> The num of infra ap is %d\n", m_infraApNum));
                VFX_TRACE(("==> The num of adhoc ap is %d\n", m_adhocApNum));
                lowestOne = findProfileWithLowestPriority (SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA);				
				if(NULL == lowestOne)//only default AP is infra network.
				{
					lowestOne = findProfileWithLowestPriority (SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC);
				}
				ApNetworkType = lowestOne->get ()->getNetworkType();	
                replacedPriority = lowestOne->get ()->getPriority ();
                // 2. Save profile into dtcnt profile storage
                if(VFX_TRUE == isStore)
                {
                    removeProfileFromDtcntStore (lowestOne->get());
                    saveProfileInDtcntStore (SRV_DTCNT_WLAN_PROF_FIELD_ALL, profile);
                }
                // 3. Remove the last ap in the list and insert a new one
                VFX_TRACE(("==> Remove ap(%s) from list and its priority is %d\n", 
                    lowestOne->get()->getSsid (), lowestOne->get ()->getPriority ()));
                m_savedApList.removePos (lowestOne);
				// default CMCC AP can't delete, so need to verify network type
				if(SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA == ApNetworkType)
                {
                	m_savedApList.insertAt (m_adhocApNum, profile);
				}
				else
				{
					m_savedApList.insertAt (m_adhocApNum - 1, profile); 
					// modify counter
                	++m_infraApNum;
                	--m_adhocApNum;
				}	
            }
        }
        else
        {
            // 1. set priority as same as the replaced one
            if(m_adhocApNum > 0)
            {
                lowestOne = findProfileWithLowestPriority (SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC);
            }
            else /* the num of adhoc ap is 0 */
            {
                lowestOne = findProfileWithLowestPriority (SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA);
                
                --m_infraApNum;
                ++m_adhocApNum;
            }
            replacedPriority = lowestOne->get ()->getPriority ();
            // 2. Save profile into dtcnt profile storage
            if(VFX_TRUE == isStore)
            {
                removeProfileFromDtcntStore (lowestOne->get());
                saveProfileInDtcntStore (SRV_DTCNT_WLAN_PROF_FIELD_ALL, profile);
            }
            // 3. Remove the first one ap in the list
            VFX_TRACE(("==> Remove ap(%s) from list and its priority is %d\n", 
                lowestOne->get()->getSsid (), lowestOne->get ()->getPriority ()));
            m_savedApList.removePos (lowestOne);
            m_savedApList.prepend (profile);
        }

        updatePriorityAfterConnected(isStore, replacedPriority, profile);
    }
    else        
    {
        VFX_TRACE(("=========> Profile's SSID: %d \t priority: %d\n", profile->getSsid (), profile->getPriority ()));
        // 1. set priority as same as the replaced one
        // profile->setPriority (getSavedApNum () + 1);
        // 2. save profile into dtcnt profile storage
        if(VFX_TRUE == isStore)
        {
            saveProfileInDtcntStore (SRV_DTCNT_WLAN_PROF_FIELD_ALL, profile);
            profile->setPriority (1);
            updateProfileInDtcntStore (SRV_DTCNT_WLAN_PROF_FIELD_PRIORITY, profile);
            VFX_ASSERT(VappWlanToolbox::checkPriorityInSrvDb(profile));
        }
        // 3. insert the new one and modify counter
        VFX_TRACE(("==> Add ap(%s) into list and its priority is %d\n", 
                profile->getSsid (), profile->getPriority ()));
        if(SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA == profile->getNetworkType ())
        {
            m_savedApList.insertAt (m_adhocApNum, profile);
            ++m_infraApNum;
        }
        else
        {
            m_savedApList.prepend (profile);
            ++m_adhocApNum;
        }
        // 4. update all aps' priority since the connected ap has the highest priority(1)
        entry = m_savedApList.getValidHead ();		
        while(entry)
        {
            item = entry->get ();
            VFX_TRACE(("SSID: %s \t Priority: %d\n", item->getSsid (), item->getPriority ()));
            VFX_TRACE(("Profile ID %d Newly added profile's profile ID: %d\n", 
                item->getProfileId (), profile->getProfileId ()));
            if(item->getProfileId () != profile->getProfileId ())
            {
                priority = item->getPriority ();
                item->setPriority (priority + 1);
                VFX_TRACE(("Change its priority as %d\n", item->getPriority ()));
                if(isStore)
                {
                    // update property of each ap in the dtcnt wlan storage
                    updateProfileInDtcntStoreByBaseInfo (SRV_DTCNT_WLAN_PROF_FIELD_PRIORITY, item); 
                }
            }
            entry = entry->getNext ();
        }			
    }
}

void VappWlanRepository::updatePriorityAfterConnected(VfxBool isStore, VfxU8 replacedPriority, VappWlanBaseInfo *baseInfo)
{
    VappAPListEntry			*entry = NULL;
    VappWlanBaseInfo		*item = NULL;
    VfxU8            		priority = 0;
	
    // update all aps' priority since the connected ap has the highest priority(1)
    entry = m_savedApList.getValidHead ();    
    while(entry)
    {
        item = entry->get ();
        VFX_TRACE(("SSID: %s \t Priority: %d replaced one's priority: %d\n", 
            item->getSsid (), item->getPriority (), replacedPriority));
        VFX_TRACE(("Profile ID %d Newly added profile's profile ID: %d\n", 
            item->getProfileId (), baseInfo->getProfileId ()));
        
        if(item->getProfileId () != baseInfo->getProfileId () &&
           item->getPriority () < replacedPriority)
        {
            priority = item->getPriority ();
            item->setPriority (priority + 1);
            VFX_TRACE(("Change its priority as %d\n", item->getPriority ()));
        }
/*
		else if(item->getProfileId () == baseInfo->getProfileId ())
		{
			priority = baseInfo->getPriority ();
            item->setPriority (priority);
		}
 */
		
        if(isStore)
        {
            // update property of each ap in the dtcnt wlan storage
            updateProfileInDtcntStoreByBaseInfo (SRV_DTCNT_WLAN_PROF_FIELD_PRIORITY, item); 
        }
        
        entry = entry->getNext ();
    }
}

void VappWlanRepository::updateMacAddress()
{
    VfxChar*    tempBuf;
    VfxWChar*   tempBufUnicode;
    const VfxU8* macAddr = getMacAddr ();

    VfxWString  macAddrValue;
    VfxWString  macAddrInfo = VFX_WSTR_RES(STR_ID_VAPP_WLAN_MAC_ADDR);

    VFX_ALLOC_MEM(tempBuf, MAC_ADDR_LEN_MAX * 3, this);
    VFX_ALLOC_MEM(tempBufUnicode, MAC_ADDR_LEN_MAX * 3 * ENCODING_LENGTH, this);
    memset(tempBuf, 0, MAC_ADDR_LEN_MAX * 3);
    memset(tempBufUnicode, 0, MAC_ADDR_LEN_MAX * 3 * ENCODING_LENGTH);

    if(SRV_DTCNT_WLAN_STATUS_INACTIVE == srv_dtcnt_wlan_status())
    {
        
    }
    else
    {
        sprintf(tempBuf, 
            "%02x:%02x:%02x:%02x:%02x:%02x",
            macAddr[0], macAddr[1], macAddr[2], macAddr[3], macAddr[4], macAddr[5]);
        mmi_asc_to_ucs2((CHAR*)tempBufUnicode, (CHAR*)tempBuf);
        macAddrValue.loadFromMem (tempBufUnicode);
        macAddrInfo += macAddrValue;
    }

    setMacInfoStr (macAddrInfo);
    VFX_FREE_MEM(tempBuf);
    VFX_FREE_MEM(tempBufUnicode);
}


void VappWlanRepository::registerObserver (Observer* o)
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OBSERVER_REGISTER, 19);
    m_observerList.append ((VfxObject*) o);
}

void VappWlanRepository::removeObserver (Observer* o)
{
    if(VFX_TRUE == m_observerList.contains ((VfxObject*) o))
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OBSERVER_DEREGISTER, 85);
        m_observerList.removeOne ((VfxObject*) o);
    }
}

void VappWlanRepository::notifyObservers (SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg)
{
    Observer *observer;

    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OBSERVER_NOTIFY, msg);
    VfxObjListEntry *entry = m_observerList.getValidHead ();
    // Go through the observer list
    while(NULL != entry)
    {
        observer = (Observer *)entry->get();
        // Whether it is the message which is subscibed by observer
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OBSERVER_NOTIFY_ALL, 98, observer->getSubscribe());
        VFX_TRACE(("Message: %d Subscriber: %d\n", msg, observer->getSubscribe()));
        if((observer->getSubscribe() & msg) > 0)
        {
            observer->UpdatePage (msg);
        }
        entry = entry->getValidNext ();
    }
}

VfxBool VappWlanRepository::findInApList(const VappWlanBaseInfo* ap)
{
    VfxU8 total = getUsefulApNum ();
    for(VfxU8 index = 0; index < total; index++)
    {
        if(VappWlanToolbox::isSameAP (ap, m_usefulApPointArray[index]))
        {
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

VappWlanBaseInfo* VappWlanRepository::getInApList(const VappWlanBaseInfo *ap)
{
    VfxU8 total = getUsefulApNum ();
    for(VfxU8 index = 0; index < total; index++)
    {
        if(VappWlanToolbox::isSameAP (ap, m_usefulApPointArray[index]))
        {
            return m_usefulApPointArray[index];
        }
    }
    return NULL;
}

VappWlanBaseInfo* VappWlanRepository::getInApListBySrvInfo(srv_dtcnt_prof_wlan_struct *srvInfo)
{
    if(NULL == srvInfo)
        return NULL;
        
    VfxU8 total = getUsefulApNum ();
    for(VfxU8 index = 0; index < total; index++)
    {
        if((srvInfo->ssid_len == m_usefulApPointArray[index]->getSsidLen ()) && 
           (0 == strncmp((const char*)srvInfo->ssid, (const char*)m_usefulApPointArray[index]->getSsid (), srvInfo->ssid_len )) &&
           (srvInfo->network_type == m_usefulApPointArray[index]->getNetworkType ()) &&
           (srvInfo->auth_mode == m_usefulApPointArray[index]->getAuthMode ()) &&
           (srvInfo->encrypt_mode == m_usefulApPointArray[index]->getEncryptMode ()))
        {
            return m_usefulApPointArray[index];
        }
    }
    return NULL;
}

void VappWlanRepository::initProfileByBssInfo(const supc_abm_bss_info_struct* bssInfo, VappWlanBaseInfo* baseInfo)
{
    VfxU8 *name;
	mmi_chset_enum ret_charset;

    /***  Initialize bss info part  ***/
    // set ap's ssid and ssid length
    baseInfo->setBssid (bssInfo->bssid);
    baseInfo->setSsid(bssInfo->ssid, bssInfo->ssid_len);
    baseInfo->setSsidLen (bssInfo->ssid_len);
    // set ap's privacy
    baseInfo->setPrivacy(bssInfo->privacy);
    baseInfo->setRssi (bssInfo->rssi);
    baseInfo->setChannelNumber (bssInfo->channel_number);
    baseInfo->setMaxRate (bssInfo->max_rate);

 	VFX_ALLOC_MEM(name, WLAN_PROF_NAME_LEN_MAX * ENCODING_LENGTH, this);
    memset(name, 0, WLAN_PROF_NAME_LEN_MAX * ENCODING_LENGTH);
 	custom_wlan_ssid_convert_ex(
		(CHAR *)baseInfo->getSsid (), 
		(CHAR *)name, 
		baseInfo->getSsidLen(), 
		&ret_charset);	
	baseInfo->setApName (name);
	baseInfo->setApCharset(ret_charset);
 	VFX_FREE_MEM (name);
 	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_SCAN_AP_CHARSET,
			baseInfo->getSsidLen (),
			baseInfo->getApCharset());	
	
    // set ap's network type
    switch (bssInfo->network_type)
    {
        case WNDRV_SUPC_NETWORK_AUTO_UNKNOWN:
            baseInfo->setNetworkType (SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA);
            break;
        case WNDRV_SUPC_NETWORK_IBSS:
            baseInfo->setNetworkType (SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC);
            break;
        case WNDRV_SUPC_NETWORK_INFRASTRUCTURE:
            baseInfo->setNetworkType (SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA);
            break;
    }
    // set ap's auth. mode and encryption mode
    if (bssInfo->rsn_ie_info_p == VFX_TRUE)
    {
    	// when auth. mode is WPA2 or WPA2+PSK, the default encryption mode is AES/CCMP
        if (bssInfo->rsn_ie_info.group_cipher & WPA_CIPHER_CCMP ||
            bssInfo->rsn_ie_info.pairwise_cipher & WPA_CIPHER_CCMP)
        {
            baseInfo->setEncryptMode (SRV_DTCNT_WLAN_ENCRYPT_MODE_AES);
        }
        else if (bssInfo->rsn_ie_info.group_cipher & WPA_CIPHER_TKIP ||
            bssInfo->rsn_ie_info.pairwise_cipher & WPA_CIPHER_TKIP)
        {
            baseInfo->setEncryptMode (SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP);
        }

        if(bssInfo->network_type == WNDRV_SUPC_NETWORK_IBSS)
        {
            if (bssInfo->rsn_ie_info.key_mgmt & WPA_KEY_MGMT_WPA_NONE)
            {
                //whether WPA WPA2 PSK can be searched??  
                baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK);//check adhoc WPA2PSK???
            }
			else
			{				
                baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_TOTAL);// no support
			}
        }
        else if(bssInfo->network_type == WNDRV_SUPC_NETWORK_INFRASTRUCTURE)
        {
            if (bssInfo->rsn_ie_info.key_mgmt & WPA_KEY_MGMT_PSK)
            {
                //whether WPA WPA2 PSK can be searched??  
                baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK);
            }
#ifndef  WIFI_AUTH_PSK_ONLY
			else if (bssInfo->rsn_ie_info.key_mgmt & WPA_KEY_MGMT_IEEE8021X)
            {
                //whether WPA WPA2 Enterprise can be searched??  
                baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY);
            }
#endif
        }
    }
    else if (bssInfo->wpa_ie_info_p == VFX_TRUE)
    {
    	// when auth. mode is WPA or WPA+PSK, the default encryption mode is TKIP
		if (bssInfo->wpa_ie_info.group_cipher & WPA_CIPHER_TKIP ||
            bssInfo->wpa_ie_info.pairwise_cipher & WPA_CIPHER_TKIP)
        {
            baseInfo->setEncryptMode (SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP);
        }
		else if (bssInfo->wpa_ie_info.group_cipher & WPA_CIPHER_CCMP ||
            bssInfo->wpa_ie_info.pairwise_cipher & WPA_CIPHER_CCMP)
        {
            baseInfo->setEncryptMode (SRV_DTCNT_WLAN_ENCRYPT_MODE_AES);
        }
		 
        if(bssInfo->network_type == WNDRV_SUPC_NETWORK_IBSS)
        {
            if (bssInfo->wpa_ie_info.key_mgmt & WPA_KEY_MGMT_WPA_NONE)
            {
                baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK);
            }
			else
			{				
                baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_TOTAL);// no support
			}
        }
        else if(bssInfo->network_type == WNDRV_SUPC_NETWORK_INFRASTRUCTURE)
        {
            if (bssInfo->wpa_ie_info.key_mgmt & WPA_KEY_MGMT_PSK)
            {
                baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK);
            }
#ifndef  WIFI_AUTH_PSK_ONLY			
            else if (bssInfo->wpa_ie_info.key_mgmt & WPA_KEY_MGMT_IEEE8021X)
            {
                baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY);
            }
#endif			
        }
    }
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    else if (bssInfo->wapi_ie_info_p == VFX_TRUE)
    {
        if (bssInfo->wapi_ie_info.group_cipher & WAPI_CIPHER_SMS4 ||
            bssInfo->wapi_ie_info.pairwise_cipher & WAPI_CIPHER_SMS4)
        {
            baseInfo->setEncryptMode (SRV_DTCNT_WLAN_ENCRYPT_MODE_WPI);
        }
        if(bssInfo->network_type == WNDRV_SUPC_NETWORK_INFRASTRUCTURE)
        {
            if (bssInfo->wapi_ie_info.key_mgmt & WAPI_KEY_MGMT_PSK)
            {
                baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK);
                baseInfo->setEncryptMode (SRV_DTCNT_WLAN_ENCRYPT_MODE_WPI);
            }
            else if (bssInfo->wapi_ie_info.key_mgmt & WAPI_KEY_MGMT_WAI)
            {
                baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT);
                baseInfo->setEncryptMode (SRV_DTCNT_WLAN_ENCRYPT_MODE_WPI);
            }
        }
    }
#endif /* __MMI_HIDE_WAPI__ */
#endif
    else if (bssInfo->privacy > 0)
    {
        if(bssInfo->network_type == WNDRV_SUPC_NETWORK_INFRASTRUCTURE)
        {
            baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_WEP);
        }
        else if (bssInfo->network_type == WNDRV_SUPC_NETWORK_IBSS)
        {
            baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_WEP);
        }
        baseInfo->setEncryptMode (SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP);
    }
    else
    {
        baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_OPEN);
        baseInfo->setEncryptMode (SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE);
    }
    // Set ap as a searched profile
    baseInfo->setApMatchType (WLAN_AP_SEARCH);

#ifdef __MMI_OP01_WIFI__    
    if(SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA == baseInfo->getNetworkType()&&
       	SRV_DTCNT_WLAN_AUTH_MODE_OPEN == baseInfo->getAuthMode()&&
        custom_wlan_is_operator_network((const char*)baseInfo->getSsid()))
    {
		baseInfo->setApMgrType (SRV_DTCNT_WLAN_AP_DEFAULT);
    }
	else
	{
		baseInfo->setApMgrType (SRV_DTCNT_WLAN_AP_UNKNOW);
	}
#else	
	baseInfo->setApMgrType (SRV_DTCNT_WLAN_AP_UNKNOW);
#endif	
}

VfxBool VappWlanRepository::checkIsApExisted(const VappWlanProfile* appProfile)
{
    VappWlanProfile         *item;    
    VappAPListEntry         *entry;

    entry = m_savedApList.getValidHead ();
    while(NULL != entry)
    {
        item = (VappWlanProfile *)entry->get();

        if(item->getProfileId () == appProfile->getProfileId ())
        {
            entry = entry->getValidNext ();
            continue;
        }
        
        if((item->getSsidLen () == appProfile->getSsidLen ()) && 
           (strcmp((const char*)item->getSsid (), (const char*)appProfile->getSsid ()) == 0) &&
           (item->getNetworkType () == appProfile->getNetworkType ()) &&
           (item->getAuthMode () == appProfile->getAuthMode ()) &&
           (item->getEncryptMode () == appProfile->getEncryptMode ()))
        {
           return VFX_TRUE;
        }
        
        entry = entry->getValidNext ();
    }
    return VFX_FALSE;
}

void VappWlanRepository::initSrvProfileByAppProfile(VfxBool isConn, const VappWlanProfile* appProfile, srv_dtcnt_prof_wlan_struct *srvProfile)
{
    VfxChar*   passphrase;    
    VFX_ALLOC_MEM(passphrase, SRV_DTCNT_PROF_MAX_WEP_KEY_LEN + 1, this);
   
    memset(srvProfile, 0, sizeof(srv_dtcnt_prof_wlan_struct)); 
    
    strncpy((char*)srvProfile->ssid, (char*)appProfile->getSsid(), SRV_DTCNT_PROF_MAX_SSID_LEN);

    srvProfile->root_ca_id = appProfile->getRootCaId ();
    srvProfile->client_ca_id = appProfile->getClientCaId ();

#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    srvProfile->wapi_ase_id = appProfile->getWapiAseId ();
    srvProfile->wapi_client_id = appProfile->getWapiClientId ();
    srvProfile->wapi_psk_format = appProfile->getWapiPskFormat ();
    strncpy((char *)srvProfile->wapi_psk_str, (char *)appProfile->getWapiPskStr (), SRV_DTCNT_WAPI_PSK_STR_LEN);
    strncpy((char *)srvProfile->wapi_private_key_passwd_str, (char *)appProfile->getWapiPrivateKeyPasswdStr (), SRV_DTCNT_PROF_MAX_PW_LEN);
#endif /* __MMI_HIDE_WAPI__ */
#endif

    mmi_ucs2cpy((char*)srvProfile->ProfName, (char*)appProfile->getApName ());        
    srvProfile->priority = appProfile->getPriority ();
    srvProfile->profile_id = appProfile->getProfileId ();
    srvProfile->ssid_len = (VfxU8)appProfile->getSsidLen();
    srvProfile->channel = appProfile->getChannelNumber ();
    
    
    srvProfile->peap_version = appProfile->getPeapVersion ();
    
    strcpy((char*)srvProfile->username, (char*)appProfile->getUserName ());
    srvProfile->network_type = appProfile->getNetworkType ();
    
    strncpy((char *)srvProfile->password, (char *)appProfile->getPassword (), SRV_DTCNT_PROF_MAX_PW_LEN);
    srvProfile->auth_mode = appProfile->getAuthMode ();

    strncpy((char *)srvProfile->private_key_passwd, (char *)appProfile->getPrivateKeyPasswd (), SRV_DTCNT_PROF_MAX_PW_LEN);
    srvProfile->encrypt_mode = appProfile->getEncryptMode ();

    memcpy (srvProfile->passphrase, appProfile->getPassphrase (), SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN);
    memcpy (srvProfile->psk, appProfile->getPsk (), SRV_DTCNT_PROF_MAX_PSK_LEN);
    
    // strncpy((char *)srvProfile->psk, (char *)appProfile->getPsk (), SRV_DTCNT_PROF_MAX_PSK_LEN - 1);
    srvProfile->eap_auth_type = appProfile->getEapAuthType ();
    srvProfile->eap_peap_auth_type = appProfile->getEapPeapAuthType ();
    srvProfile->eap_ttls_auth_type = appProfile->getEapTtlsAuthType ();
    /* WEP KEY */
    srvProfile->wep_key_index = appProfile->getWepKeyIndex ();
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
#else
    srvProfile->wep_key_len = appProfile->getWepKeyLen ();
    srvProfile->wep_key_format = appProfile->getWepKeyFormat ();
    memcpy(srvProfile->wep_key, appProfile->getWepKey (), SRV_DTCNT_PROF_MAX_WEP_KEY_LEN + 1);
#endif

    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_CONN_WEP_KEY_INPUT, 
            srvProfile->wep_key_index, srvProfile->wep_key_len, srvProfile->wep_key_format);

    memcpy((char *)srvProfile->ip_addr, (char *)appProfile->getIpAddr (), SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    memcpy((char *)srvProfile->netmask, (char *)appProfile->getNetmask (), SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    memcpy((char *)srvProfile->gateway, (char *)appProfile->getGateway (), SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    memcpy((char *)srvProfile->dns1, (char *)appProfile->getDns1 (), SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    memcpy((char *)srvProfile->dns2, (char *)appProfile->getDns2 (), SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    if(VFX_TRUE == appProfile->getUseDhcp())
    {
        srvProfile->use_dhcp = MMI_TRUE;    
    }
    else
    {
        srvProfile->use_dhcp = MMI_FALSE;
    }
    
    memcpy(srvProfile->HomePage, appProfile->getHomePage (), SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1);
    memcpy(srvProfile->px_addr, appProfile->getPxAddr (), SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1);
    memcpy(srvProfile->px_authid, appProfile->getAuthId (), SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1);
    memcpy(srvProfile->px_authpw, appProfile->getAuthPw (), SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1);
    srvProfile->px_port = appProfile->getPxPort ();
    if(VFX_TRUE == appProfile->getUseProxy())
    {
        srvProfile->use_proxy = 1;    
    }
    else
    {
        srvProfile->use_proxy = 0;
    }

	srvProfile->ap_type = appProfile->getApMgrType();
		
    VFX_FREE_MEM (passphrase);  
}

void VappWlanRepository::autoConnStart (vcui_wlan_auto_conn_cb_func_ptr cb)
{
	VFX_ASSERT(cb);
	
    setAutoConnCb (cb);

    // set proc type internal use
    VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_AUTO_CONN_PROC_TYPE, getConnProcType (), __LINE__);
    setConnProcType (WLAN_CONN_AUTO);

    // send scan request
    VappWlanSentry::SendScanRequest ();
}

void VappWlanRepository::autoConnProc(VfxBool isValid, SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg)
{
	VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_AUTO_CONN_SCAN_VALID, isValid, msg, __LINE__);
    // ignore notification if not in auto conn. proc
    VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_AUTO_CONN_PROC_TYPE, getConnProcType (), __LINE__);
    if(WLAN_CONN_AUTO != getConnProcType ())
    {
        return;
    }

    // inform cbm result right now if result is not valid
    if(!isValid)
    {
        autoConnInform (VCUI_WLAN_AUTO_CONN_ACTION_CANCEL);
        return;
    }

    if(SUBSCRIBE_SCAN_MSG == msg)
    {    
        VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_AUTO_CONN_SCAN_RESULT, getScanRresult (), __LINE__);
        switch(getScanRresult ())
        {
        case SRV_DTCNT_WLAN_SCAN_RESULT_SUCCESS:    /* WLAN scan success */
            if(VFX_FALSE == getIsScanResultUseful())
            {
                // inform caller
                autoConnInform (VCUI_WLAN_AUTO_CONN_ACTION_CANCEL);
            }
            else
            {
                // check result
                autoConnRun();
            }
            break;
        case SRV_DTCNT_WLAN_SCAN_RESULT_FAILED:     /* WLAN scan failed */
        case SRV_DTCNT_WLAN_SCAN_RESULT_ABORTED:    /* WLAN scan service is aborted */
		case SRV_DTCNT_WLAN_SCAN_RESULT_DELETE:	
            // inform caller
            autoConnInform (VCUI_WLAN_AUTO_CONN_ACTION_CANCEL);
            break;
        default:
            VFX_ASSERT(0);
            break;
        }
    }
}

void VappWlanRepository::autoConnRun ()
{
    // add trace here
    VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_AUTO_CONN_START, __LINE__);

    // go through saved ap list to judge whether there is saved ap in the scan result
    if(m_rememberedApListNum > 0)
    {        
        // connect to saved ap according to priority
        srv_dtcnt_wlan_connect_by_db_prof (NULL, NULL);
    }
    else
    {
        autoConnInform (VCUI_WLAN_AUTO_CONN_ACTION_CANCEL);
	    VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_AUTO_CONN_DONE, __LINE__);
        return;
    }

    autoConnInform (VCUI_WLAN_AUTO_CONN_ACTION_START);
	VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_AUTO_CONN_DONE, __LINE__);
}


void VappWlanRepository::autoConnInform(VCUI_WLAN_AUTO_CONN_ACTION_ENUM action)
{
	vcui_wlan_auto_conn_cb_func_ptr cb = getAutoConnCb();
	
    if( cb )
    {
        // Add trace
        VFX_LOG(VFX_FUNC3, TRC_VCUI_WLAN_AUTO_CONN_CB_ACTION, action, __LINE__);
        cb(action);
    }

    setConnProcType (WLAN_CONN_TOTAL);
}

VappWlanBaseInfo* const * VappWlanRepository::getUsefulApArray() const
{
    return m_usefulApPointArray;
}

VappWlanBaseInfo* const * VappWlanRepository::getBlockedApArray() const
{
    return m_blockedApPointArray;
}

VappWlanBaseInfo* const * VappWlanRepository::getRememberedApArray() const
{
    return m_rememberedApPointArray;
}

VfxU8 VappWlanRepository::getSavedApNum() const
{
    return m_savedApListNum;
}

VfxBool VappWlanRepository::getIsEditAddressProc() const
{
    return m_isEditAddress;
}

void VappWlanRepository::setIsEditAddressProc(VfxBool isEdit)
{
    m_isEditAddress = isEdit;
}

VAPP_WLAN_ADD_AP_TYPE VappWlanRepository::getAddApType() const
{
	return m_addApType;
}
void VappWlanRepository::setAddApType(VAPP_WLAN_ADD_AP_TYPE apTpye)
{
	m_addApType =  apTpye;
}

void VappWlanRepository::setIsScanResultUseful(VfxBool check)
{
	m_isScanResultUseful = check;
}

VfxBool VappWlanRepository::getIsScanResultUseful() const 
{
	return m_isScanResultUseful;
}

void VappWlanRepository::afterForgetAp(VappWlanBaseInfo* baseInfo)
{
	m_scanApList.append(baseInfo);
}

VfxU8 VappWlanRepository::getBlockedApNum() const
{
    return m_blockedApListNum;
}

VfxU8 VappWlanRepository::getRememberedApNum() const
{
    return m_rememberedApListNum;
}

VfxU8 VappWlanRepository::getUsefulApNum() const
{
    return m_usefulApListNum;
}

void VappWlanRepository::setWlanUiFlow(VAPP_WLAN_UI_FLOW_ENUM flow)
{
	m_uiFlow = flow;
}
	
VAPP_WLAN_UI_FLOW_ENUM VappWlanRepository::getWlanUiFlow(void)
{
	return m_uiFlow;
}

void VappWlanRepository::setActionAfterLogout(VAPP_WLAN_CMCC_LOGOUT_ACTION action)
{
	m_actionAfterLogout = action;
}

VAPP_WLAN_CMCC_LOGOUT_ACTION VappWlanRepository::getActionAfterLogout(void)
{
	return m_actionAfterLogout;
}

#ifndef __MTK_TARGET__
void VappWlanRepository::ModisIpaddrUpdate ()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_ipaddr_update_evt_struct evt;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    /* notify Applications */
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_WLAN_IPADDR_UPDATE);
	
	evt.new_ipaddr.ip_addr[0] = 255; 
	evt.new_ipaddr.ip_addr[1] = 254; 
	evt.new_ipaddr.ip_addr[2] = 253; 
	evt.new_ipaddr.ip_addr[3] = 252; 
	evt.new_ipaddr.netmask[0] = 251; 
	evt.new_ipaddr.netmask[1] = 250; 
	evt.new_ipaddr.netmask[2] = 249; 
	evt.new_ipaddr.netmask[3] = 248; 
	evt.new_ipaddr.gateway[0] = 247; 
	evt.new_ipaddr.gateway[1] = 246; 
	evt.new_ipaddr.gateway[2] = 245; 
	evt.new_ipaddr.gateway[3] = 244; 
	evt.new_ipaddr.dns1[0] = 243; 
	evt.new_ipaddr.dns1[1] = 242; 
	evt.new_ipaddr.dns1[2] = 241; 
	evt.new_ipaddr.dns1[3] = 240; 
	evt.new_ipaddr.dns2[0] = 239; 
	evt.new_ipaddr.dns2[1] = 238; 
	evt.new_ipaddr.dns2[2] = 237; 
	evt.new_ipaddr.dns2[3] = 236; 
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}

void VappWlanRepository::ModisIpaddrChange()
{
    srv_dtcnt_wlan_ipaddr_change_cnf_evt_struct evt;
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_WLAN_IPADDR_CHANGE_CNF);
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);  
}
#endif

mmi_ret HandleDtcntServiceEvents(mmi_event_struct* param)
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_HDLR, param->evt_id);

    switch(param->evt_id)
    {
    /**********************************************************************************************/
    /*  WLAN Bearer Status Related Events                                                         */
    /**********************************************************************************************/
    /* post type, srv_dtcnt_wlan_active_evt_struct, must return MMI_RET_OK */   
    case EVT_ID_SRV_DTCNT_WLAN_ACTIVE:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_STATUS_ACTIVE);
        break;
    /* post type, srv_dtcnt_wlan_connected_evt_struct, must return MMI_RET_OK */
    case EVT_ID_SRV_DTCNT_WLAN_CONNECTED:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_STATUS_CONNECTED);
        break;
    /* post type, srv_dtcnt_wlan_inactive_evt_struct, must return MMI_RET_OK */
    case EVT_ID_SRV_DTCNT_WLAN_INACTIVE:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_STATUS_INACTIVE);
        break;
    /* post type, srv_dtcnt_wlan_scan_evt_struct, must return MMI_RET_OK */    
    case EVT_ID_SRV_DTCNT_WLAN_SCAN:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_STATUS_SCAN);
        break;
    /* post type, srv_dtcnt_wlan_conn_evt_struct, must return MMI_RET_OK */    
    case EVT_ID_SRV_DTCNT_WLAN_CONNECT:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_STATUS_CONNECT);
        break;
    /* post type, srv_dtcnt_wlan_bearer_status_evt_struct, must return MMI_RET_OK */    
    case EVT_ID_SRV_DTCNT_WLAN_BEARER_STATUS:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_STATUS_BEARER_STATUS);
        VappWlanSentry::responseBearerStatusEvent(param);
        break;

    /**********************************************************************************************/
    /*  SRV Indication Events                                                                     */
    /**********************************************************************************************/

    /* post type, srv_dtcnt_wlan_conn_ind_evt_struct, must return MMI_RET_OK */    
    case EVT_ID_SRV_DTCNT_WLAN_CONN_IND:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_IND_CONN);
        VappWlanSentry::responseConnectIndEvent(param);
        break;
    /* post type, srv_dtcnt_wlan_disc_ind_evt_struct, must return MMI_RET_OK */    
    case EVT_ID_SRV_DTCNT_WLAN_DISC_IND:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_IND_DISC);
        VappWlanSentry::responseDisconnectedEvent(param);
        break;
    /* post type, srv_dtcnt_wlan_ipaddr_update_evt_struct, must return MMI_RET_OK */    
    case EVT_ID_SRV_DTCNT_WLAN_IPADDR_UPDATE:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_IND_IPADDR_UPDATE);
        VappWlanSentry::responseUpdateIpAddrEvent(param);
        break;
    /* post type, srv_dtcnt_wlan_ipaddr_conflict_ind_evt_struct, must return MMI_RET_OK */    
    case EVT_ID_SRV_DTCNT_WLAN_IPADDR_CONFLICT_IND:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_IND_IPADDR_CONFLICT);
        VappWlanSentry::responseIpAddrConflictEvent(param);
        break;
    /* post type, srv_dtcnt_wlan_curr_ap_info_evt_struct, must return MMI_RET_OK */    
    case EVT_ID_SRV_DTCNT_WLAN_CURR_AP_INFO:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_IND_CURR_AP_INFO);
        VappWlanSentry::responseRefreshApStatusEvent(param);
        break;
    /* post type, srv_dtcnt_prov_ind_evt_struct, must return MMI_RET_OK, only DA APP can register this event */
    case EVT_ID_SRV_DTCNT_PROV_IND:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_IND_PROV);
        break;
    /* post type, srv_dtcnt_prov_install_res_ind_evt_struct, must return MMI_RET_OK, only DA APP can register this event */
    case EVT_ID_SRV_DTCNT_PROV_INSTALL_RES_IND:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_IND_PROV_INSTALL_RES);
        break;
    /* post type, srv_dtcnt_prov_done_ind_evt_struct, must return MMI_RET_OK, only DA APP can register this event */
    case EVT_ID_SRV_DTCNT_PROV_DONE_IND:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_IND_PROV_DONE);
        break;
    /* post type, srv_dtcnt_acct_update_ind_evt_struct, must return MMI_RET_OK */
    case EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_IND_ACCT_UPDATE);
        break;
    /* post type, srv_dtcnt_acct_delete_ind_evt_struct, must return MMI_RET_OK */
    case EVT_ID_SRV_DTCNT_ACCT_DELETE_IND:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_IND_ACCT_DELETE);
        break;
		
	/* post type, srv_dtcnt_wlan_conn_prof_evt_struct, must return MMI_RET_OK */ 
	case EVT_ID_SRV_DTCNT_WLAN_CONN_PROF:
		VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_IND_CONN_PROF);
		VappWlanSentry::responseConnReqProfEvent(param);
		break;
		
	/* post type, srv_dtcnt_wlan_sleep_evt_struct, must return MMI_RET_OK */ 
	case EVT_ID_SRV_DTCNT_WLAN_SLEEP:
		VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_IND_SLEEP);
		VappWlanSentry::responseSleepEvent(param);
		break;		

    /**********************************************************************************************/
    /*  APP Request Response Indication Events                                                    */
    /**********************************************************************************************/

    /* post type, srv_dtcnt_wlan_init_res_ind_evt_struct, must return MMI_RET_OK */    
    case EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_RES_IND_INIT);
        VappWlanSentry::responseInitEvent(param);
        break;
    /* post type, srv_dtcnt_wlan_deinit_res_ind_evt_struct, must return MMI_RET_OK */    
    case EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_RES_IND_DEINIT);
        VappWlanSentry::responseDeinitEvent(param);
        break;
    /* post type, srv_dtcnt_wlan_conn_res_ind_evt_struct, must return MMI_RET_OK */    
    case EVT_ID_SRV_DTCNT_WLAN_CONN_RES_IND:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_RES_IND_CONN);
        VappWlanSentry::responseConnectedEvent(param);
        break;
    /* post type, srv_dtcnt_wlan_disc_res_ind_evt_struct, must return MMI_RET_OK */    
    case EVT_ID_SRV_DTCNT_WLAN_DISC_RES_IND:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_RES_IND_DISC);
        VappWlanSentry::responseDisconnectedEvent(param);
        break;
    /* send type, srv_dtcnt_wlan_scan_res_ind_evt_struct, must return MMI_RET_OK, applications need to copy information directly */
    case EVT_ID_SRV_DTCNT_WLAN_SCAN_RES_IND:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_RES_IND_SCAN);
        VappWlanSentry::responseScanEvent(param);
        break;
	
    /**********************************************************************************************/
    /*  App/Srv Interaction Events                                                                */
    /**********************************************************************************************/
    
    /* send type, srv_dtcnt_wlan_ipaddr_change_qry_evt_struct, must return MMI_RET_OK, only DA APP can register this event */
    case EVT_ID_SRV_DTCNT_WLAN_IPADDR_CHANGE_QRY:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_IPADDR_CHANGE_QRY);
        VappWlanSentry::responseIpAddrChangedEvent(param);
        break;
    /* send type, srv_dtcnt_wifi_chip_invalid_evt_struct, must return MMI_RET_OK, only DA APP can register this event */
    case EVT_ID_SRV_DTCNT_WIFI_CHIP_INVALID:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_CHIP_INVALID);
        VappWlanSentry::responseChipInvaildEvent(param);
        break;

    /**********************************************************************************************/
    /*  Mode Switch Notification Events                                                           */
    /**********************************************************************************************/
    case EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_MODE_SWITCH_PRE_NOTIFY);
        VappWlanSentry::responsePreModeSwitch (param);
        break;        
    case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_MODE_SWITCH_FINISH_NOTIFY);
        VappWlanSentry::responseFinishModeSwitch (param);
        break;
        
    /**********************************************************************************************/
    /*  WPS in MAUI                                                                               */
    /**********************************************************************************************/
#ifdef __WPS_SUPPORT__
    case EVT_ID_SRV_DTCNT_WLAN_WPS_INFO:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_WPS_INFO_IND);
        VappWlanSentry::responseWPSInfoIndEvent (param);
        break;
#endif 

	case EVT_ID_VAPP_LANGUAGE_CHANGED:		
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_LANGUAGE_CHANGED);
		VappWlanSentry::responseUpdateLanguageEvent (param);
		break;

#ifdef __MMI_OP01_WIFI__			   
	case EVT_ID_SRV_DTCNT_WLAN_LOGOUT_IND: // may be phase out because 11B deactive event has delete.
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_LOGOUT_IND);
        VappWlanCMCCMgr::responseCMCCLogoutIndEvent(param);
		break;
			
	case EVT_ID_SRV_DTCNT_WLAN_IPADDR_CHANGE_CNF:
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_EVT_IPADDR_CHANGRE_CNF);
		VappWlanCMCCMgr::responseAddrChangeCnfEvent (param);
		break;
#endif

    default:
        break;
    }
    return MMI_RET_OK;
}

/***************************************************************************** 
 * Class VappWlanSentry
 *****************************************************************************/
mmi_ret VappWlanSentry::RegisterDtcntServiceEvents()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16     evt_id;
    mmi_ret ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (evt_id = EVT_ID_SRV_DTCNT_WLAN_ACTIVE; evt_id < EVT_ID_SRV_DTCNT_TOTAL; evt_id++)
    {
        ret = mmi_frm_cb_reg_event (evt_id, HandleDtcntServiceEvents, NULL);
        if (MMI_RET_OK == ret)
        {
            continue;
        }
        else
        {
            return ret;
        }
    }

    return MMI_RET_OK;
}

mmi_ret VappWlanSentry::DeregisterDtcntServiceEvents()
{
    U16     evt_id;
    mmi_ret ret;
    
    for (evt_id = EVT_ID_SRV_DTCNT_WLAN_ACTIVE; evt_id < EVT_ID_SRV_DTCNT_TOTAL; evt_id++)
    {
        ret = mmi_frm_cb_dereg_event (evt_id, HandleDtcntServiceEvents, NULL);
        if (MMI_RET_OK == ret)
        {
            continue;
        }
        else
        {
            return ret;
        }
    }

    return MMI_RET_OK;
}

void VappWlanSentry::PowerOnWifi()
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 
    s_houseKeeper->initializeRepository (NULL);
    s_houseKeeper->syncWithDtcntStorage ();
}

void VappWlanSentry::SendInitRequest ()
{
    VFX_TRACE(("===Send init request to dtcnt service===\n"));
    srv_dtcnt_wlan_init(NULL, NULL);
}

void VappWlanSentry::SendDeinitRequest ()
{
    srv_dtcnt_wlan_deinit(NULL, NULL);
}

void VappWlanSentry::SendScanRequest ()
{
    VfxU32 scanJobId;
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SEND_SCAN_REQ_START);
    /*
     *  Job ID > 0 : New scan job created successfully.
     *  Job ID = 0 : Can't create a new scan job.
     */
    scanJobId = srv_dtcnt_wlan_scan(NULL, NULL);
    s_houseKeeper->setIsScanAbort (VFX_FALSE);
    if(scanJobId > 0)
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SEND_SCAN_REQ_END, scanJobId);
        VFX_TRACE(("=== Job Id: %d ===\n", scanJobId));
        s_houseKeeper->setScanJobId(scanJobId);
    }
    else
    {
        // Error handling
    }
}

void VappWlanSentry::SendAbortScanRequest ()
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 
    VfxU32 scanJobId = s_houseKeeper->getScanJobId ();

    s_houseKeeper->setIsScanAbort (VFX_TRUE);
    if(scanJobId > 0)
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SEND_ABORT_SCAN_REQ);
        srv_dtcnt_wlan_scan_abort(scanJobId);
        s_houseKeeper->setScanJobId (0);
    }
}

void VappWlanSentry::SendConnectRequest ()
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    srv_dtcnt_wlan_conn_prof_struct connProfile;
    srv_dtcnt_prof_wlan_struct srvProfile, *updateProfile = NULL;
    srv_dtcnt_result_enum ret;

    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SEND_CONN_REQ_START);
    // store ap which is going to be activated just in case
    VappWlanProfile *appProfile = s_houseKeeper->getApToBeActivated ();
    s_houseKeeper->initSrvProfileByAppProfile(VFX_TRUE, appProfile, &srvProfile);
    
    VFX_TRACE(("SRV Profile - PSK: %s \t Passphrase: %s\n", srvProfile.psk, srvProfile.passphrase));
    VFX_TRACE(("WEP KEY: %s Length: %d\n", srvProfile.wep_key, strlen((const char*)srvProfile.wep_key)));
    VFX_TRACE(("Username: %s \t Password: %s\n", srvProfile.username, srvProfile.password));
    VFX_TRACE(("EAP: %d \t PEAH: %d \t TTLS: %d \t VERSION: %d\n", 
        srvProfile.eap_auth_type, srvProfile.eap_peap_auth_type, srvProfile.eap_ttls_auth_type, srvProfile.peap_version));
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_CONN_DEFAULT_INPUT, strlen((const char*)srvProfile.username), strlen((const char*)srvProfile.password));
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_CONN_WEP_KEY_LENGTH, strlen((const char*)srvProfile.wep_key));
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_CONN_EAP_INPUT, srvProfile.eap_auth_type, srvProfile.eap_peap_auth_type, srvProfile.eap_ttls_auth_type, srvProfile.peap_version);
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_CONN_PSK_PASSPHRASE, strlen((const char*)srvProfile.psk), strlen((const char*)srvProfile.passphrase));

    connProfile.num_prof  = 1;	
	updateProfile = &srvProfile;
    connProfile.prof_data = &updateProfile;
    connProfile.connect_type = ONE_PROFILE_SELECT;	
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SEND_CONN_REQ_PROC, connProfile.connect_type);
    ret = srv_dtcnt_wlan_connect_by_app_prof(&connProfile, NULL, NULL);
	
	if(SRV_DTCNT_WLAN_STATE_CONNECTED != srv_dtcnt_wlan_state())
	{
   		// update status icon bar
    	updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_SCANNING, VFX_TRUE);
	}
    
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SEND_CONN_REQ_END, ret);
}

void VappWlanSentry::SendAbortConnectRequest()
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    srv_dtcnt_result_enum result;
    
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SEND_ABORT_CONN_REQ_START);
    result = srv_dtcnt_wlan_disconnect();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SEND_ABORT_CONN_REQ_END, result);
    
    // Set flag and clean the security info user input
    s_houseKeeper->setIsConnectAbort (VFX_TRUE);
    VappWlanProfile* profile = s_houseKeeper->getApToBeActivated ();
    // Clean the password user input
    if(profile && profile->getApMatchType () == WLAN_AP_SEARCH)
    {
        VappWlanToolbox::cleanSecurityInfo(profile);
    }
    /* if add disconnect action into list, set connected ap as NULL */
    if(SRV_DTCNT_RESULT_PROCESSING == result)
    {
        // Todo: update status icon bar
#ifdef __MMI_OP01_WIFI__        
        updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_FOUND_WIFI, VFX_FALSE);
#else
		updateStatusIconBar (0, VFX_FALSE);
#endif	
    }
}

void VappWlanSentry::SendDisconnectRequest ()
{
    srv_dtcnt_result_enum result;
    
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SEND_DISC_REQ_START);
    result = srv_dtcnt_wlan_disconnect();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SEND_DISC_REQ_END, result);
}

#ifdef __CERTMAN_SUPPORT__
void VappWlanSentry::SendSelectCACertRequest(VfxResId titleStrId)
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    VFX_TRACE(("===Send select ca cert. request to cert. manager ===\n"));
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SEND_CERT_ROOT_REQ);
    SetProtocolEventHandler(responseSelectCACertRequest, MSG_ID_MMI_CERTMAN_SELECT_CERT_RSP);
	
	VappCertmanInterfaces::vapp_certman_select_certificates_ind(
		MOD_MMI,
		VAPP_CERTMAN_ACTION_CANCEL,
		KAL_FALSE,
		0, // must 0, APP'id sync certman
		STR_GLOBAL_CANCEL,
		VAPP_CERTMAN_CERT_GROUP_ROOT_CA,
		VAPP_CERTMAN_PUBKEY_TYPE_EC_SIGN);

    s_houseKeeper->setIsCertListShow (VFX_TRUE);
    VappCertmanInterfaces::vapp_certman_select_certificates_ind(
        MOD_MMI,
        VAPP_CERTMAN_ACTION_OPEN,
        KAL_FALSE,
        0,
        titleStrId,
        VAPP_CERTMAN_CERT_GROUP_ROOT_CA,
        VAPP_CERTMAN_PUBKEY_TYPE_RSA_SIGN |
        VAPP_CERTMAN_PUBKEY_TYPE_DSA_SIGN |
        VAPP_CERTMAN_PUBKEY_TYPE_DH_ANSI_SIGN |
        VAPP_CERTMAN_PUBKEY_TYPE_DH_PKCS3_SIGN);

}

void VappWlanSentry::SendSelectUserCertRequest(VfxResId titleStrId)
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    VFX_TRACE(("===Send select user cert. request to cert. manager ===\n"));
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SEND_CERT_USER_REQ);
    SetProtocolEventHandler(responseSelectUserCertRequest, MSG_ID_MMI_CERTMAN_SELECT_CERT_RSP);
	
	VappCertmanInterfaces::vapp_certman_select_certificates_ind(
		MOD_MMI,
		VAPP_CERTMAN_ACTION_CANCEL,
		KAL_FALSE,
		0, // must 0, APP'id sync certman
		STR_GLOBAL_CANCEL,
		VAPP_CERTMAN_CERT_GROUP_ROOT_CA,
		VAPP_CERTMAN_PUBKEY_TYPE_EC_SIGN);

    s_houseKeeper->setIsCertListShow (VFX_TRUE);
    VappCertmanInterfaces::vapp_certman_select_certificates_ind(
        MOD_MMI,
        VAPP_CERTMAN_ACTION_OPEN,
        KAL_FALSE,
        0,
        titleStrId,
        VAPP_CERTMAN_CERT_GROUP_PERSONAL,
        VAPP_CERTMAN_PUBKEY_TYPE_RSA_SIGN |
        VAPP_CERTMAN_PUBKEY_TYPE_DSA_SIGN |
        VAPP_CERTMAN_PUBKEY_TYPE_DH_ANSI_SIGN |
        VAPP_CERTMAN_PUBKEY_TYPE_DH_PKCS3_SIGN);

}

void VappWlanSentry::SendSelectASECertRequest(VfxResId titleStrId)
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    VFX_TRACE(("===Send select ASE cert. request to cert. manager ===\n"));
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SEND_CERT_ASE_REQ);
    SetProtocolEventHandler(responseSelectASECertRequest, MSG_ID_MMI_CERTMAN_SELECT_CERT_RSP);
	
	VappCertmanInterfaces::vapp_certman_select_certificates_ind(
		MOD_MMI,
		VAPP_CERTMAN_ACTION_CANCEL,
		KAL_FALSE,
		0, // must 0, APP'id sync certman
		STR_GLOBAL_CANCEL,
		VAPP_CERTMAN_CERT_GROUP_ROOT_CA,
		VAPP_CERTMAN_PUBKEY_TYPE_EC_SIGN);

    s_houseKeeper->setIsCertListShow (VFX_TRUE);
    VappCertmanInterfaces::vapp_certman_select_certificates_ind(
        MOD_MMI,
        VAPP_CERTMAN_ACTION_OPEN,
        KAL_FALSE,
        0,
        titleStrId,
        VAPP_CERTMAN_CERT_GROUP_ROOT_CA,
        VAPP_CERTMAN_PUBKEY_TYPE_ALL);
        // VAPP_CERTMAN_PUBKEY_TYPE_EC_SIGN);
}

void VappWlanSentry::SendSelectClientCertRequest(VfxResId titleStrId)
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    VFX_TRACE(("===Send select ASE cert. request to cert. manager ===\n"));
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SEND_CERT_CLIENT_REQ);
    SetProtocolEventHandler(responseSelectClientCertRequest, MSG_ID_MMI_CERTMAN_SELECT_CERT_RSP);
	
	VappCertmanInterfaces::vapp_certman_select_certificates_ind(
		MOD_MMI,
		VAPP_CERTMAN_ACTION_CANCEL,
		KAL_FALSE,
		0, // must 0, APP'id sync certman
		STR_GLOBAL_CANCEL,
		VAPP_CERTMAN_CERT_GROUP_ROOT_CA,
		VAPP_CERTMAN_PUBKEY_TYPE_EC_SIGN);

    s_houseKeeper->setIsCertListShow (VFX_TRUE);
    VappCertmanInterfaces::vapp_certman_select_certificates_ind(
        MOD_MMI,
        VAPP_CERTMAN_ACTION_OPEN,
        KAL_FALSE,
        0,
        titleStrId,
        VAPP_CERTMAN_CERT_GROUP_PERSONAL,
        VAPP_CERTMAN_PUBKEY_TYPE_ALL);
        // VAPP_CERTMAN_PUBKEY_TYPE_EC_SIGN);
}

#endif

#ifdef __WPS_SUPPORT__
// WPS Request/Response
void VappWlanSentry::SendWPSConnectRequest ()
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    srv_dtcnt_wlan_conn_prof_struct connProfile;
    srv_dtcnt_prof_wlan_struct srvProfile, *updateProfile = NULL;
    srv_dtcnt_result_enum ret;

    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SEND_WPS_CONN_REQ_START);
    // store ap which is going to be activated just in case
    VappWlanProfile* appProfile = s_houseKeeper->getApToBeActivated ();
    s_houseKeeper->initSrvProfileByAppProfile(VFX_TRUE, appProfile, &srvProfile);
	
    connProfile.num_prof  = 1;
	updateProfile = &srvProfile;
    connProfile.prof_data = &updateProfile;
    connProfile.connect_type = appProfile->getConnType ();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SEND_WPS_CONN_REQ_PROC, connProfile.connect_type);
    ret = srv_dtcnt_wlan_connect_by_app_prof(&connProfile, NULL, NULL);

    // update status icon bar
    updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_SCANNING, VFX_TRUE);
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SEND_WPS_CONN_REQ_END, ret);
}

void VappWlanSentry::responseWPSInfoIndEvent(mmi_event_struct* param)
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    srv_dtcnt_wlan_wps_info_evt_struct* wpsInfoEvt = 
                                    (srv_dtcnt_wlan_wps_info_evt_struct*)param;
    if(wpsInfoEvt)
    {
        s_houseKeeper->afterReceiveWPSInfoEvt (wpsInfoEvt);
        
        VfxApp *app = vapp_dtcnt_wlan_find_app();           
		if(WLAN_WPS_STATUS_INIT == s_houseKeeper->getWpsStatus() &&
			NULL == app && 0 == s_houseKeeper->getWlanSettingCuiId())
		{
    		// WLAN setting Page don't exist, send disconn req to srv
    		SendDisconnectRequest();
    		return;
    	}
        s_houseKeeper->notifyObservers (SUBSCRIBE_WPS_INFO_MSG);
    }
}
#endif  /* __WPS_SUPPORT__ */

void VappWlanSentry::responseUpdateLanguageEvent(mmi_event_struct* param)
{	
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

	s_houseKeeper->updateMacAddress();	
}

void VappWlanSentry::responseBearerStatusEvent(mmi_event_struct* param)
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_WLAN_STATUS, srv_dtcnt_wlan_state());
    if(SRV_DTCNT_WLAN_STATE_CONNECT_WAIT == srv_dtcnt_wlan_state())
    {   
    	// status = connecting
    	updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_SCANNING, VFX_TRUE);
    }
	else if(SRV_DTCNT_WLAN_STATE_NULL == srv_dtcnt_wlan_state())
	{
		// status = NULL, deinit
    	updateStatusIconBar (0, VFX_FALSE);
    }
	else if(SRV_DTCNT_WLAN_STATE_CONNECTED != srv_dtcnt_wlan_state())
	{
		if( s_houseKeeper->getAPConnNum() != 0 )
		{
			updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_SCANNING, VFX_TRUE);	
		}
		else
		{
#ifdef __MMI_OP01_WIFI__        
            updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_FOUND_WIFI, VFX_FALSE);
#else
		    updateStatusIconBar (0, VFX_FALSE);
#endif	
		}
    }
	s_houseKeeper->updateApList();
    s_houseKeeper->notifyObservers(SUBSCRIBE_BEARER_STATUS_MSG);
}

void VappWlanSentry::responseSleepEvent(mmi_event_struct* param)
{
#ifdef __MMI_OP01_WIFI__
    VappWlanCMCCMgr::entryCMCCDeinitProc ();
#else
    VappWlanSentry::SendDeinitRequest ();
#endif
}

void VappWlanSentry::responseConnReqProfEvent(mmi_event_struct* param)
{	
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 
    VfxContext *context = s_houseKeeper->getContext();

	srv_dtcnt_wlan_conn_prof_evt_struct *connProf;
    connProf = (srv_dtcnt_wlan_conn_prof_evt_struct *)param;
	supc_connection_type_enum connType ;

	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_PROF, 
		(connProf->res).prof_num, (connProf->res).conn_type);	

	connType = (supc_connection_type_enum)((connProf->res).conn_type);
	s_houseKeeper->setAPConnTypeSequence(connType);

    // update m_apToBeActivated.
    if(ALL_PROFILE_ENABLE != connType)
    {
        srv_dtcnt_prof_wlan_struct *srvProfile = NULL;
        srvProfile = srv_dtcnt_wlan_get_connecting_prof();
        
        VappWlanBaseInfo *baseInfo = NULL;
        baseInfo = s_houseKeeper->getInApListBySrvInfo(srvProfile);   
        
        VappWlanProfile *appProfile = NULL;
        VFX_OBJ_CREATE(appProfile, VappWlanProfile, context);
        
        if(0 == connProf->res.prof_id[0])
        {
            // Scan AP
            VappWlanToolbox::initAppProfileBySrvProfile (appProfile, srvProfile);
            if(NULL == baseInfo)
            {
                // Scan AP has disappeared in ScanAPlist.            
            }
            else
            {
                appProfile->setApCharset(baseInfo->getApCharset());
            }
            // Set ap as a searched profile
            appProfile->setApMatchType (WLAN_AP_SEARCH);
        }
        else
        {
            // saved AP    
            if(NULL == baseInfo)
            {
                // Saved AP must be existed in Service.
                VFX_ASSERT(0);
            }       
            VappWlanToolbox::getAppProfileByAppBaseInfo(baseInfo, appProfile);
        }  
        appProfile->setConnType(connType);   
        s_houseKeeper->setApToBeActivated(appProfile);
        
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_UPDATE_ACTIVATED_AP_INFO, 
            appProfile->getProfileId(), appProfile->getApMatchType(), 
            appProfile->getApMgrType(), appProfile->getSsidLen (), appProfile->getPriority ());
            
        VFX_OBJ_CLOSE(appProfile);
    }
    
    s_houseKeeper->notifyObservers(SUBSCRIBE_CONNECT_REQUEST_MSG);   
    // update status icon bar
    updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_SCANNING, VFX_TRUE);
}

void VappWlanSentry::responseInitEvent(mmi_event_struct* param)
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    VFX_TRACE(("==============================================\n"));
    VFX_TRACE(("===> 1. Receive init event! \n"));
    const VfxU8*  macAddr;
    srv_dtcnt_wlan_init_res_ind_evt_struct *initEvt;
    VcpFormItemLauncherCell* settingCell;
    VcpFormItemSwitchCell*   switchCell;

    // update settings framework's cell if existed
    settingCell = s_houseKeeper->getSettingCellInstance ();
    switchCell = s_houseKeeper->getSettingSwitchCellInstance ();

    initEvt = (srv_dtcnt_wlan_init_res_ind_evt_struct *)param;

	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_INIT_RES, initEvt->res);
	//Init event has been terminated, keep the switch state.
    if(SRV_DTCNT_WLAN_REQ_RES_TERMINATED == initEvt->res || 
       SRV_DTCNT_WLAN_REQ_RES_DUPLICATED == initEvt->res || 
       SRV_DTCNT_WLAN_REQ_RES_FAILED == initEvt->res)
    {
    	// Get current wifi status 
   		VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_WLAN_STATUS, srv_dtcnt_wlan_state());
        if(SRV_DTCNT_WLAN_STATE_CONNECTED != srv_dtcnt_wlan_state())
    	{
#ifdef __MMI_OP01_WIFI__        
		    updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_FOUND_WIFI, VFX_FALSE);
#else
			updateStatusIconBar (0, VFX_FALSE);
#endif
    	}
			
		//if Conn num isn't 0 ,disable network mgr bar
		if( s_houseKeeper->getAPConnNum() != 0 )
		{
			updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_SCANNING, VFX_TRUE);	
		}	
			
		if(NULL != switchCell)
		{
			switchCell->setSwitchStatus (switchCell->getSwitchStatus());
			if(VFX_FALSE == switchCell->getSwitchStatus() && NULL != settingCell)
			{
				settingCell->setIsDisabled (VFX_TRUE);
			}
		}
        return;
    }
	
    s_houseKeeper->setMacAddr (initEvt->mac_addr);
    s_houseKeeper->updateMacAddress();
    
    macAddr = s_houseKeeper->getMacAddr ();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_INIT, 
            macAddr[0], macAddr[1], macAddr[2],
            macAddr[3], macAddr[4], macAddr[5]);

    // Power saving mode
    if(SRV_DTCNT_WLAN_WLAN_POWER_MODE_TOTAL != s_houseKeeper->getPowerSavingMode ())
    {
        srv_dtcnt_wlan_set_power_mode(
            s_houseKeeper->getPowerSavingMode (),
            setPowerSavingModeCallbackFunc,
            NULL);
    }
    
    // Notify observer
    s_houseKeeper->notifyObservers (SUBSCRIBE_INIT_MSG);

    // query the status of switching flight mode
    MMI_BOOL switching = srv_mode_switch_is_switching ();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_INIT_RSP, switching);
    
    if(NULL != settingCell)
    {
        if(MMI_FALSE == switching)
        {
            VFX_TRACE(("====> 2. Enable item! \n"));
            VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_ENABLE_SETTING);
            settingCell->setIsDisabled (VFX_FALSE);
        }
    }

    if(NULL != switchCell)
    {
        if(MMI_FALSE == switching)
        {
            VFX_TRACE(("====> 3. Swtich status! \n"));
            VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_ENABLE_SWITCH);
            switchCell->setSwitchStatus (VFX_TRUE);
        }
    }
    VFX_TRACE(("==============================================\n"));
}

void VappWlanSentry::responseScanEvent (mmi_event_struct* param)
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    srv_dtcnt_wlan_scan_res_ind_evt_struct  *scan_evt;
    srv_dtcnt_wlan_scan_result_struct       *ret;

    // Receive event from service then set scan useful as FALSE firstly
	s_houseKeeper->setIsScanResultUseful(VFX_FALSE);

    // Exception handler - Abort scan action
    if(VFX_TRUE == s_houseKeeper->getIsScanAbort ())
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_SCAN_ABORT);
        s_houseKeeper->setIsScanAbort (VFX_FALSE); //Reset flag
        // Ignore the scan result
        s_houseKeeper->autoConnProc(VFX_FALSE, SUBSCRIBE_MSG_TOTAL);
        return;
    }

    scan_evt = (srv_dtcnt_wlan_scan_res_ind_evt_struct *)param;
    ret = &(scan_evt->scan_res);
    
    s_houseKeeper->setScanResult(ret->result);
    s_houseKeeper->setScanApListNum (ret->ap_list_num);

    if(SRV_DTCNT_WLAN_SCAN_RESULT_SUCCESS == ret->result )
        // && ret->scan_job_id == s_houseKeeper->getScanJobId ())
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_SCAN_SUCCESS);
        s_houseKeeper->updateScanApList (ret->ap_list);
        s_houseKeeper->setCurWlanStatus ();
        s_houseKeeper->notifyObservers (SUBSCRIBE_SCAN_MSG);
    }
    else
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_SCAN_FAILED, ret->result);
		if(SRV_DTCNT_WLAN_SCAN_RESULT_DELETE == ret->result)
		{			
			// scan action has been terminate by srv when conn_waiting state
			s_houseKeeper->autoConnProc(VFX_TRUE, SUBSCRIBE_SCAN_MSG);
			return;
		}
		else
		{
			s_houseKeeper->notifyObservers (SUBSCRIBE_SCAN_MSG);
    	}
    }

	if(VFX_TRUE == s_houseKeeper->getIsScanResultUseful() &&
	   SRV_DTCNT_WLAN_STATUS_CONNECTED != srv_dtcnt_wlan_status())
	{
	    //need to update
#ifdef __MMI_OP01_WIFI__        
		updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_FOUND_WIFI, VFX_FALSE);
#else
		updateStatusIconBar (0, VFX_FALSE);
#endif	
	}

	if(VFX_FALSE == s_houseKeeper->getIsScanResultUseful())
	{
		// To do: update status bar icon
       	updateStatusIconBar (0, VFX_FALSE);
	}

    s_houseKeeper->autoConnProc(VFX_TRUE, SUBSCRIBE_SCAN_MSG);
}

void VappWlanSentry::responseConnectedEvent(mmi_event_struct* param)
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    VfxBool isByWps = VFX_FALSE;
    srv_dtcnt_wlan_conn_res_ind_evt_struct  *connResInd;
	srv_dtcnt_wlan_conn_res_struct *connRes;

    connResInd = (srv_dtcnt_wlan_conn_res_ind_evt_struct *)param;
    connRes = &(connResInd->conn_result);
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_RESULT, connRes->result);
    //conn event isn't useful, don't response.
    if( SRV_DTCNT_RESULT_SUCCESS != connRes->result && SRV_DTCNT_RESULT_FAILED != connRes->result )
    {	  
    	// Get current wifi status 
   		VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_WLAN_STATUS, srv_dtcnt_wlan_state());
    	if(SRV_DTCNT_WLAN_STATE_CONNECTED != srv_dtcnt_wlan_state())
    	{
    		updateStatusIconBar (0, VFX_FALSE);
    	}
			
		//if Conn num isn't 0 ,disable network mgr bar
		if( s_houseKeeper->getAPConnNum() != 0 )
		{
			updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_SCANNING, VFX_TRUE);	
		}	
        return;
    }
	
    supc_connection_type_enum	connType = s_houseKeeper->getAPConnTypeSequence(0); 
	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_NUMBER, s_houseKeeper->getAPConnNum(), connType);
	s_houseKeeper->setCnfConnType(connType);

	if( s_houseKeeper->getAPConnNum() != 0)
	{
		if( START_WPS_PIN == connType || START_WPS_PBC == connType )
		{
			isByWps = VFX_TRUE;
		}	
	}
	else
	{	
		isByWps = VFX_FALSE;
	}
	
	//update conn Sequence
	s_houseKeeper->updateAPConnTypeSequence();	
	if(s_houseKeeper->getAPConnNum() != 0)
	{
		//ConnNum isn't 0, so App can't	ignore conn_cnf event
		return;
	}
	
    if(VFX_TRUE == s_houseKeeper->getIsConnectAbort ())
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_ABORT);
        s_houseKeeper->setIsConnectAbort (VFX_FALSE);   // Reset flag
        s_houseKeeper->notifyObservers(SUBSCRIBE_DISCONNECT_MSG);
        // Ignore event
        return;
    }

    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_WPS_FLAG, isByWps);
    switch(connRes->result)
    {
        case SRV_DTCNT_RESULT_SUCCESS:     /* SUCCESS: connected */
            VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_RESULT_SUCCESS);
            if(VFX_FALSE == isByWps)
            {
                // Do afterConnected action
                s_houseKeeper->afterConnectedSuccess (connRes);
                // Notify observer             
                s_houseKeeper->notifyObservers(SUBSCRIBE_CONNECT_SUCCESS_MSG);
#ifndef __MTK_TARGET__
				s_houseKeeper->ModisIpaddrUpdate();
				//s_houseKeeper->ModisIpaddrChange();
#endif
            }
#ifdef __WPS_SUPPORT__
            else
            {
                s_houseKeeper->afterConnectedSuccessByWps (connRes);
                // Notify observer
                s_houseKeeper->notifyObservers(SUBSCRIBE_CONNECT_SUCCESS_MSG);
            }
#endif            
            // update status bar icon
            updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_CONNECT1, VFX_FALSE);
            break;
#if 0			
/* under construction !*/
/* under construction !*/
#endif			
        case SRV_DTCNT_RESULT_FAILED:      /* FAILD: connect failed */
            VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_RESULT_FAILED, connRes->cancel_by_discon, connRes->cause);
            if(connRes->cancel_by_discon)
            {
                s_houseKeeper->afterAbortConnect ();
                return;
            }
            
            if(VFX_FALSE == isByWps)
            {
                s_houseKeeper->afterConnectedFailed (connRes->profile_id);
            }
#ifdef __WPS_SUPPORT__            
            else
            {
                s_houseKeeper->afterConnectedFailedByWps (connRes);
            }
#endif            

            s_houseKeeper->setConnFailType(connRes->cause);
			s_houseKeeper->notifyObservers(SUBSCRIBE_CONNECT_FAIL_MSG);
			
            // To do: update status bar icon
#ifdef __MMI_OP01_WIFI__        
			updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_FOUND_WIFI, VFX_FALSE);
#else
			updateStatusIconBar (0, VFX_FALSE);
#endif	
            break;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_OP01_WIFI__        
/* under construction !*/
#else
/* under construction !*/
#endif	
/* under construction !*/
#endif
        default:
            break;
    }
}

void VappWlanSentry::responseConnectIndEvent(mmi_event_struct* param)
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    srv_dtcnt_wlan_conn_ind_evt_struct  *connIndEvt;
    srv_dtcnt_wlan_conn_res_struct      *connRes;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_TRACE(("===== SRV_DTCNT_RESULT_SUCCESS=====\n")); 

    connIndEvt = (srv_dtcnt_wlan_conn_ind_evt_struct *)param;
    connRes = &(connIndEvt->conn_result);

    VFX_TRACE(("--->To do: update status bar icon \n"));
    switch(connRes->result)
    {
        case SRV_DTCNT_RESULT_SUCCESS:     /* SUCCESS: connected */
            VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_RESULT_SUCCESS);
            if(s_houseKeeper->afterReceiveConnectInd (connRes))
            {
                // Notify observer                    
                s_houseKeeper->notifyObservers(SUBSCRIBE_CONNECT_SUCCESS_MSG);
                // update status bar icon
                updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_CONNECT1, VFX_FALSE);
            }
            else
            {
                // Not found
            }
            break;
        case SRV_DTCNT_RESULT_STATE_ERROR: /* STATE_ERROR: can't perform connect req */
            VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_RESULT_ERROR);
        case SRV_DTCNT_RESULT_FAILED:      /* FAILD: connect failed */
            VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_RESULT_FAILED);
         case SRV_DTCNT_RESULT_ABORTED:     /* ABORTED: preemptived by new connect req */
            VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_RESULT_ABORTED);
        case SRV_DTCNT_RESULT_TERMINATED:  /* TERMINATED: terminated by new disconnect req */
            VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CONN_RESULT_TERMINATED);
            // To do: update status bar icon
#ifdef __MMI_OP01_WIFI__        
			updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_FOUND_WIFI, VFX_FALSE);
#else
			updateStatusIconBar (0, VFX_FALSE);
#endif	
            break;
        default:
            break;
    }
}

void VappWlanSentry::responseDisconnectedEvent(mmi_event_struct* param)
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

	srv_dtcnt_wlan_disc_res_ind_evt_struct *disconnEvt = NULL;
	disconnEvt = (srv_dtcnt_wlan_disc_res_ind_evt_struct *)param;

	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_DISCONN_RES, disconnEvt->res);
	//dieconn event has been terminated, keep the switch state.
    if(SRV_DTCNT_WLAN_REQ_RES_TERMINATED == disconnEvt->res || 
       SRV_DTCNT_WLAN_REQ_RES_DUPLICATED == disconnEvt->res || 
       SRV_DTCNT_WLAN_REQ_RES_FAILED == disconnEvt->res)
    {
    	// Get current wifi status 
   		VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_WLAN_STATUS, srv_dtcnt_wlan_state());
        if(SRV_DTCNT_WLAN_STATE_CONNECTED != srv_dtcnt_wlan_state())
    	{
#ifdef __MMI_OP01_WIFI__        
		    updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_FOUND_WIFI, VFX_FALSE);
#else
			updateStatusIconBar (0, VFX_FALSE);
#endif
    	}
			
		//if Conn num isn't 0 ,disable network mgr bar
		if( s_houseKeeper->getAPConnNum() != 0 )
		{
			updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_SCANNING, VFX_TRUE);	
		}	
        return;
    }

	//trace status ui machine
#ifdef __MMI_OP01_WIFI__
	VappWlanCMCCMgr::entryCMCCProtalCertAbort();	
#endif 

    switch(s_houseKeeper->getWlanUiFlow ())
    {
        case WLAN_UI_DISC_AFTER_LOGIN_FAILED:
        case WLAN_UI_PORTAL_LOGOUT:
			s_houseKeeper->setWlanUiFlow (WLAN_UI_NONE);
            break;
        case WLAN_UI_ABORT_CONNECT:
            s_houseKeeper->setWlanUiFlow (WLAN_UI_NONE);
            return;
        default:
            break;
    }

    s_houseKeeper->afterDisconnected ();
    s_houseKeeper->notifyObservers(SUBSCRIBE_DISCONNECT_MSG);
    // To do: update status bar icon
#ifdef __MMI_OP01_WIFI__        
	updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_FOUND_WIFI, VFX_FALSE);
#else
	updateStatusIconBar (0, VFX_FALSE);
#endif	
}

void VappWlanSentry::responseDeinitEvent(mmi_event_struct* param)
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    srv_dtcnt_wlan_deinit_res_ind_evt_struct* evt = 
        (srv_dtcnt_wlan_deinit_res_ind_evt_struct*) param;
	
	mmi_id  wlanSettingCuiId;
	
    VcpFormItemLauncherCell* settingCell;
    VcpFormItemSwitchCell*   switchCell;
    // update settings framework's cell if existed
    settingCell = s_houseKeeper->getSettingCellInstance ();
    switchCell = s_houseKeeper->getSettingSwitchCellInstance ();

    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_DEINIT, evt->res);
    //Deinit event has been terminated, keep the switch state.
    if(SRV_DTCNT_WLAN_REQ_RES_TERMINATED == evt->res || 
       SRV_DTCNT_WLAN_REQ_RES_DUPLICATED == evt->res || 
       SRV_DTCNT_WLAN_REQ_RES_FAILED == evt->res)
    {
   		VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_WLAN_STATUS, srv_dtcnt_wlan_state());
    	if(SRV_DTCNT_WLAN_STATE_CONNECTED != srv_dtcnt_wlan_state())
    	{
#ifdef __MMI_OP01_WIFI__        
			updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_FOUND_WIFI, VFX_FALSE);
#else
			updateStatusIconBar (0, VFX_FALSE);
#endif
    	}
			
		//if Conn num isn't 0 ,disable network mgr bar
		if( s_houseKeeper->getAPConnNum() != 0 )
		{
			updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_SCANNING, VFX_TRUE);	
		}
			
		if(NULL != switchCell)
		{
			switchCell->setSwitchStatus (switchCell->getSwitchStatus());
			if(VFX_FALSE == switchCell->getSwitchStatus() && NULL != settingCell)
			{
				settingCell->setIsDisabled (VFX_TRUE);
			}
		}
        return;
    }
	
#ifdef __MMI_OP01_WIFI__
	VappWlanCMCCMgr::entryCMCCProtalCertAbort();
#endif
    
    VFX_TRACE(("==============================================\n"));
    VFX_TRACE(("===> 1. Receive deinit event! \n"));
    s_houseKeeper->afterDeinit ();
    updateStatusIconBar (0, VFX_FALSE);

	if(NULL != settingCell)
    {
        if(VFX_FALSE == settingCell->getIsDisabled())
        {
            VFX_TRACE(("====> 2. Disable item! \n"));
            VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_DISABLE_SETTING);
            settingCell->setIsDisabled (VFX_TRUE);
        }
    }
    if(NULL != switchCell)
    {
        VFX_TRACE(("====> 3. Swtich status! \n"));
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_SET_SWITCH, VFX_FALSE);
        switchCell->setSwitchStatus (VFX_FALSE);
    }
    
    VfxApp *app = vapp_dtcnt_wlan_find_app();       
    wlanSettingCuiId = s_houseKeeper->getWlanSettingCuiId();
    if(app || 0 != wlanSettingCuiId)
    {   
        // ncenter can't leave before screen switch. When APP close, screen will switch.
        vapp_ncenter_disable_leave();
            
        if(app)
        {
            VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_DEINIT_RSP, 0, app->getGroupId());
            VfxAppLauncher::terminate(app->getGroupId());
        }
        else if(0 != wlanSettingCuiId)
        {
            VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_DEINIT_RSP, 1, wlanSettingCuiId);        
            VfxAppLauncher::terminate(wlanSettingCuiId);                 
        }		
    }

	//WLAN CUI ANIMATE CLOSE WHEN RECIVER THE MESSAGE
	s_houseKeeper->notifyObservers(SUBSCRIBE_DEINIT_MSG);

    VFX_TRACE(("==============================================\n"));
}

void VappWlanSentry::responseUpdateIpAddrEvent(mmi_event_struct* param)
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    srv_dtcnt_wlan_ipaddr_update_evt_struct     *ipAddrUpdateEvt;
    srv_dtcnt_wlan_ipaddr_update_struct         *ipAddrUpdate;
    // For ap which use DHCP would receive this event to update ip addr        
    ipAddrUpdateEvt = (srv_dtcnt_wlan_ipaddr_update_evt_struct *)param;
    ipAddrUpdate = &(ipAddrUpdateEvt->new_ipaddr);
    s_houseKeeper->afterUpdateIpAddr (ipAddrUpdate);

#ifdef __MMI_OP01_WIFI__
	// Reset flag if AP use custom IP addr.
    if(WLAN_UI_WAIT_FOR_IP_UPDATE == s_houseKeeper->getWlanUiFlow ())
    {
        s_houseKeeper->setWlanUiFlow(WLAN_UI_NONE);
    }
	VappWlanCMCCMgr::entryCMCCPortalProc();
#endif
}

void VappWlanSentry::responseIpAddrConflictEvent(mmi_event_struct* param)
{
    VFX_TRACE(("--->To do: popup a prompt \n"));
    showGlobalPopup (GRP_ID_ROOT, NULL, STR_ID_VAPP_WLAN_ERR_IP_ADDR_CONFLICT);
}

void VappWlanSentry::responseIpAddrChangedEvent(mmi_event_struct* param)
{
    // only when scanAp connect success, MMI will receive this event?
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    srv_dtcnt_wlan_ipaddr_change_qry_evt_struct *ipAddrChangeEvt;

    // when user input tcp/ip settings manually not using DHCP, 
    // then wifi would receive this event after the connect action
    ipAddrChangeEvt = (srv_dtcnt_wlan_ipaddr_change_qry_evt_struct*)param;
    if(ipAddrChangeEvt->ipaddr_change_cb)
    {
        // before TCP/IP change, APP wound inform srv whether using DHCP
    	// If not using DHCP, APP wound inform srv the TCP/IP
        s_houseKeeper->afterChangeIpAddr (ipAddrChangeEvt);
    }
}

void VappWlanSentry::responseChipInvaildEvent(mmi_event_struct* param)
{
    VFX_TRACE(("--->To do: popup a prompt \n"));
	showGlobalPopup (GRP_ID_ROOT, NULL, STR_ID_VAPP_WLAN_ERR_CHIP_INVAILD);
}

void VappWlanSentry::responsePreModeSwitch(mmi_event_struct* param)
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 
#ifndef __COSMOS_WLAN_IN_FLGHT_MODE__	
    VcpFormItemLauncherCell* settingCell;    
#endif /* __COSMOS_WLAN_IN_FLGHT_MODE__ */
    VcpFormItemSwitchCell*   switchCell;
	
	srv_mode_switch_notify_struct *ModeEvt;	
	ModeEvt = (srv_mode_switch_notify_struct *)param;
	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_FLIGHT_MODE_SWITCHING_STATUE, 
		ModeEvt->curr_flight_mode, ModeEvt->select_flight_mode, srv_dtcnt_wlan_state());
	
    VFX_TRACE(("===> Before switch mode!\n"));    
#ifndef __COSMOS_WLAN_IN_FLGHT_MODE__	
    settingCell = s_houseKeeper->getSettingCellInstance ();
#endif /* __COSMOS_WLAN_IN_FLGHT_MODE__ */
    switchCell = s_houseKeeper->getSettingSwitchCellInstance ();
	
#ifndef __COSMOS_WLAN_IN_FLGHT_MODE__	
	if(NULL != settingCell)
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_DISABLE_SETTING);
        settingCell->setIsDisabled (VFX_TRUE);
    }
    if(NULL != switchCell)
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_DISABLE_SWITCH);
        switchCell->setIsDisabled (VFX_TRUE);
    }
#else 
	if(SRV_DTCNT_WLAN_STATUS_INACTIVE == srv_dtcnt_wlan_status () &&
	   SRV_MODE_SWITCH_ON == ModeEvt->curr_flight_mode &&
	   SRV_MODE_SWITCH_OFF == ModeEvt->select_flight_mode &&
	   NULL != switchCell && VFX_FALSE == switchCell->getSwitchStatus())
	{	
		// flight mode from on to off, MMI need know whether srv open WLAN. 
		if(MMI_TRUE == srv_dtcnt_wlan_need_init_check())
		{
			switchCell->showProcessInd();
		}
	}

	if(SRV_DTCNT_WLAN_STATUS_INACTIVE != srv_dtcnt_wlan_status () &&
	   SRV_MODE_SWITCH_OFF == ModeEvt->curr_flight_mode &&
	   SRV_MODE_SWITCH_ON == ModeEvt->select_flight_mode &&
	   NULL != switchCell && VFX_TRUE == switchCell->getSwitchStatus())
	{	
		switchCell->showProcessInd();
	}
#endif
}

void VappWlanSentry::responseFinishModeSwitch(mmi_event_struct* param)
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    srv_mode_switch_notify_struct *flightMode = (srv_mode_switch_notify_struct*)param;
    if(NULL == flightMode)
    {
        return;
    }
    
    VcpFormItemLauncherCell* settingCell;
    VcpFormItemSwitchCell*   switchCell;

    VFX_TRACE(("===> After switch mode!\n"));
    settingCell = s_houseKeeper->getSettingCellInstance ();
    switchCell = s_houseKeeper->getSettingSwitchCellInstance ();
    
    if(NULL != settingCell)
    {
        // Change mode into normal mode, enable setting cell according to current wifi status
        if (srv_mode_switch_is_network_service_available())
        {
            if(SRV_DTCNT_WLAN_STATUS_INACTIVE == srv_dtcnt_wlan_status ())
            {
                VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_DISABLE_SETTING);
                settingCell->setIsDisabled (VFX_TRUE);
            }
            else
            {
                VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_ENABLE_SETTING);
                settingCell->setIsDisabled (VFX_FALSE);
            }
        }
        // Change mode into flight mode, disable setting cell
        else
        {
            VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_DISABLE_SETTING);
            settingCell->setIsDisabled(VFX_TRUE);
        }
    }

    if(NULL != switchCell)
    {
        // Change mode into normal mode, enable switch cell according to current wifi status
        if (srv_mode_switch_is_network_service_available())
        {
            VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_ENABLE_SWITCH);
            switchCell->setIsDisabled(VFX_FALSE);
            
            if(SRV_DTCNT_WLAN_STATUS_INACTIVE == srv_dtcnt_wlan_status ())
            {
                VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_SET_SWITCH, VFX_FALSE);
                switchCell->setSwitchStatus (VFX_FALSE);
            }
            else
            {
                VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_SET_SWITCH, VFX_TRUE);
                switchCell->setSwitchStatus (VFX_TRUE);
            }
        }		
#ifndef __COSMOS_WLAN_IN_FLGHT_MODE__	
        // Change mode into flight mode, disable switch cell
        else
        {
            VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_DISABLE_SWITCH);
            switchCell->setIsDisabled(VFX_TRUE);
        }
#else
        else
        {
            VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_SET_SWITCH, VFX_FALSE);
            switchCell->setSwitchStatus (VFX_FALSE);
        }
#endif
    }
}

void VappWlanSentry::responseRefreshApStatusEvent(mmi_event_struct* param)
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

	srv_dtcnt_wlan_curr_ap_info_evt_struct  *currApInfoEvt;
    srv_dtcnt_wlan_curr_ap_info_struct      *currApInfo;
            
    currApInfoEvt = (srv_dtcnt_wlan_curr_ap_info_evt_struct *)param;
    currApInfo = &(currApInfoEvt->curr_ap_info);

    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_UPDATE_AP_STATUS, 
        s_houseKeeper->getCurWlanStatus (), currApInfo->rssi);
    s_houseKeeper->afterRefreshConnectedAP(currApInfo);
    s_houseKeeper->notifyObservers(SUBSCRIBE_CURR_AP_INFO_MSG);
    
    if(SRV_DTCNT_WLAN_STATUS_CONNECTED != s_houseKeeper->getCurWlanStatus () ||
      (0 == s_houseKeeper->getConnectedAP ()->getSsidLen ()))
    {
        return;
    }

    if(currApInfo->rssi > -40)
    {
        updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_CONNECT4, VFX_FALSE);
    }
    else if(currApInfo->rssi > -60)
    {
        updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_CONNECT3, VFX_FALSE);
    }
    else if(currApInfo->rssi > -80)
    {
        updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_CONNECT2, VFX_FALSE);
    }
    else 
    {
        updateStatusIconBar (IMG_ID_DTCNT_WLAN_STATUS_CONNECT1, VFX_FALSE);
    }
}

#ifdef __CERTMAN_SUPPORT__
void VappWlanSentry::responseSelectCACertRequest(void* data)
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    s_houseKeeper->setIsCertListShow (VFX_FALSE);

    VfxWString displayName = VFX_WSTR_RES(STR_GLOBAL_NONE);
    vapp_certman_select_cert_rsp_struct *certRsp;

    ClearProtocolEventHandler(MSG_ID_MMI_CERTMAN_SELECT_CERT_RSP);
    certRsp = (vapp_certman_select_cert_rsp_struct *)data;

    VFX_TRACE(("--->To do: Response from CACert manager: %d ID: %d\n", certRsp->result, certRsp->cert_ids[0]));
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CERT_ROOT, certRsp->result, certRsp->cert_ids[0]);
    if(certRsp->result)
    {
        s_houseKeeper->setRootCAId (certRsp->cert_ids[0]);
        // Notify observer if the cert. file changed
        s_houseKeeper->notifyObservers(SUBSCRIBE_SELECT_CA_MSG);
    }
    else
    {
    }
} 

void VappWlanSentry::responseSelectUserCertRequest(void* data)
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    s_houseKeeper->setIsCertListShow (VFX_FALSE);
    
    VfxWString displayName = VFX_WSTR_RES(STR_GLOBAL_NONE);
    vapp_certman_select_cert_rsp_struct *certRsp;

    ClearProtocolEventHandler(MSG_ID_MMI_CERTMAN_SELECT_CERT_RSP);
    certRsp = (vapp_certman_select_cert_rsp_struct *)data;

    VFX_TRACE(("--->To do: Response from UserCert manager: %d ID: %d\n", certRsp->result, certRsp->cert_ids[0]));
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CERT_USER, certRsp->result, certRsp->cert_ids[0]);
    if(certRsp->result)
    {        
        s_houseKeeper->setUserCAId (certRsp->cert_ids[0]);
        // Notify observer                    
        s_houseKeeper->notifyObservers(SUBSCRIBE_SELECT_USER_MSG);    
    }
    else
    {
    }
} 

void VappWlanSentry::responseSelectASECertRequest(void *data)
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    s_houseKeeper->setIsCertListShow (VFX_FALSE);
    
    VfxWString displayName = VFX_WSTR_RES(STR_GLOBAL_NONE);
    vapp_certman_select_cert_rsp_struct *certRsp;
    
    ClearProtocolEventHandler(MSG_ID_MMI_CERTMAN_SELECT_CERT_RSP);
    certRsp = (vapp_certman_select_cert_rsp_struct *)data;
    
    VFX_TRACE(("--->To do: Response from ASECert manager: %d ID: %d\n", certRsp->result, certRsp->cert_ids[0]));
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CERT_ASE, certRsp->result, certRsp->cert_ids[0]);
    if(certRsp->result)
    {        
        s_houseKeeper->setWapiAseId (certRsp->cert_ids[0]);
        // Notify observer                    
        s_houseKeeper->notifyObservers(SUBSCRIBE_SELECT_ASE_MSG);
    }
    else
    {
    }
}

void VappWlanSentry::responseSelectClientCertRequest(void *data)
{   
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    s_houseKeeper->setIsCertListShow (VFX_FALSE);
    
    vapp_certman_select_cert_rsp_struct *certRsp;

    ClearProtocolEventHandler(MSG_ID_MMI_CERTMAN_SELECT_CERT_RSP);
    certRsp = (vapp_certman_select_cert_rsp_struct *)data;
    
    VFX_TRACE(("--->To do: Response from ClientCert manager: %d ID: %d\n", certRsp->result, certRsp->cert_ids[0]));
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_CERT_CLIENT, certRsp->result, certRsp->cert_ids[0]);
    if(certRsp->result)
    {
        s_houseKeeper->setWapiClientId (certRsp->cert_ids[0]);
        // Notify observer                    
        s_houseKeeper->notifyObservers(SUBSCRIBE_SELECT_CLIENT_MSG);
    }
    else
    {
    }
}

#endif

void VappWlanSentry::updateStatusIconBar(VfxU16 imageId, VfxBool isAnimate)
{
    VFX_TRACE(("====> updateStatusIconBar: image id - %d\n", imageId));
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_STATUS_BAR_ICON, imageId, isAnimate);
    if(imageId == 0)
    {
        wgui_status_icon_bar_hide_icon(STATUS_ICON_WLAN_SIGNAL);
    }
    else
    {
        VFX_TRACE(("====> isAnimate: %d\n", isAnimate));
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_WLAN_SIGNAL);
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_WLAN_SIGNAL, imageId);
        if (isAnimate == VFX_TRUE)
        {
            wgui_status_icon_bar_set_icon_animate(STATUS_ICON_WLAN_SIGNAL);
        }
        wgui_status_icon_bar_update();
    }
}

void VappWlanSentry::showGlobalPopup(mmi_id gid, void* userData, VfxResId textId)
{
	VappWlanRepository *s_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

/*    
    vcp_global_popup_show_confirm_one_button_id(
                        gid,
                        VCP_POPUP_TYPE_WARNING, 
                        textId, 
                        STR_GLOBAL_OK, 
                        VCP_POPUP_BUTTON_TYPE_CANCEL,
                        globalPopupCallbackFunc,
                        userData);
*/
    vapp_nmgr_global_popup_show_confirm_one_button_id(
                        MMI_SCENARIO_ID_DEFAULT,
                        VCP_POPUP_TYPE_WARNING, 
                        textId, 
                        STR_GLOBAL_OK, 
                        VCP_POPUP_BUTTON_TYPE_NORMAL,
                        globalPopupCallbackFunc,
                        userData);

    // Store newly created popup's group id
    // s_houseKeeper->setPopupGid (newGroupId); 
    //VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_SHOW_FLIGHT_MODE_POPUP_START, newGroupId);
}

void VappWlanSentry::globalPopupCallbackFunc(VfxId id, void *userData)
{
/*
    mmi_id popupGid;

    popupGid = s_houseKeeper->getPopupGid ();
    if(popupGid != GRP_ID_INVALID)
    {
        vcp_global_popup_cancel (popupGid);
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_SHOW_FLIGHT_MODE_POPUP_END, popupGid);
    }
*/
    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        {
           //TO DO: handle button click here
           break;
        }

        case VCP_POPUP_BUTTON_NO_PRESSED:
        {
           //TO DO: handle the case for back key, end key
           //and someone invoke vapp_nmgr_global_popup_cancel
           break;
        }
    }
}

void VappWlanSentry::setPowerSavingModeCallbackFunc(void *user_data, srv_dtcnt_wlan_req_res_enum res)
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_POWER_SAVING_MODE_SAVE, res);
}

/***************************************************************************** 
 * Class VappWlanCMCCMgr
 *****************************************************************************/
#ifdef __MMI_OP01_WIFI__
VFX_IMPLEMENT_CLASS ("VappWlanCMCCMgr", VappWlanCMCCMgr, VfxObject);
srv_dtcnt_wlan_logout_cb_func_ptr VappWlanCMCCMgr::m_callback;

VappWlanCMCCMgr::VappWlanCMCCMgr()
{
}

void VappWlanCMCCMgr::onInit()
{
    VfxObject::onInit ();
}


void VappWlanCMCCMgr::onDeinit()
{
    VfxObject::onDeinit ();
}

void VappWlanCMCCMgr::entryCMCCPortalProc()
{
	VappWlanRepository *m_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    if(isAllowToShowScrn())
    {
        // start login procedure directly
        entryCMCCPortalCertRun();
    }
    else
    {
   	 	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_ENTRY_LOGIN_NO_AVAILABLE);
        if(SRV_DTCNT_WLAN_AP_DEFAULT == m_houseKeeper->getConnectedAP()->getApMgrType())
        {
            srv_dtcnt_wlan_disconnect ();
        }
    }

}

void VappWlanCMCCMgr::entryCMCCProtalCertAbort(void)
{
	VappWlanRepository *m_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_RSP_ABORT_STATUS, m_houseKeeper->getWlanUiFlow ());
	if((WLAN_UI_PORTAL_LOGIN == m_houseKeeper->getWlanUiFlow ()) ||
   	   (WLAN_UI_PORTAL_LOGOUT == m_houseKeeper->getWlanUiFlow ()))
	{
		//trace
		/*
		if(g_wlan_display_context.portal_cert_logout_gid != GRP_ID_INVALID)
		{
			// close popup
			mmi_alert_dismiss(g_wlan_display_context.portal_cert_logout_gid);
			g_wlan_display_context.portal_cert_logout_gid = GRP_ID_INVALID;
		}
		*/
		VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_RSP_ATUH_ABORT);
		vapp_dtcnt_wlan_auth_abort();
		m_houseKeeper->setWlanUiFlow (WLAN_UI_NONE);
	}
}

void VappWlanCMCCMgr::entryCMCCPortalCertRun(void)
{
	VappWlanRepository *m_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

	MMI_BOOL isAutoAuth = vapp_dtcnt_wlan_is_auto_auth();

    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_CERT_RUN_CURRENT_STATUS,
			m_houseKeeper->getWlanUiFlow (), srv_dtcnt_wlan_status(), isAutoAuth);  
	
    if((WLAN_UI_PORTAL_LOGIN != m_houseKeeper->getWlanUiFlow ()) &&
		MMI_TRUE == isAutoAuth)
    {
		if(SRV_DTCNT_WLAN_AP_DEFAULT == m_houseKeeper->getConnectedAP()->getApMgrType())
        {
			entryCMCCPortalCertLoginStart();
        }
    }
}

void VappWlanCMCCMgr::entryCMCCPortalCertLoginStart(void)
{   
	VappWlanRepository *m_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    //vapp_cmcc_wlan_auth_ret_enum login_status;
    
	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_ENTRY_LOGIN_START, m_houseKeeper->getWlanUiFlow ());

    if(WLAN_UI_PORTAL_LOGOUT == m_houseKeeper->getWlanUiFlow ())
    {
		VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_RSP_ATUH_ABORT);
		vapp_dtcnt_wlan_auth_abort();
        m_houseKeeper->setWlanUiFlow (WLAN_UI_NONE);
    }
    
    m_houseKeeper->setWlanUiFlow (WLAN_UI_PORTAL_LOGIN);
    // start to do portal certification
    // Only return VAPP_CMCC_WLAN_AUTH_WBLOCK, portal application will invoke callback		
	vapp_dtcnt_wlan_auth_login(entryCMCCPortalCertCallback);
/*	
	login_status = VAPP_CMCC_WLAN_AUTH_OK;////modis/////////////
	if(VAPP_CMCC_WLAN_AUTH_WBLOCK != login_status)
    {
        m_houseKeeper->setWlanUiFlow (WLAN_UI_NONE);
    }
  */  
 	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_ENTRY_LOGIN_DONE, m_houseKeeper->getWlanUiFlow ());
}

void VappWlanCMCCMgr::entryCMCCPortalCertLogoutStart()
{
	VappWlanRepository *m_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_ENTRY_LOGOUT_START, m_houseKeeper->getWlanUiFlow ());
	if(WLAN_UI_PORTAL_LOGIN == m_houseKeeper->getWlanUiFlow ())
	{		
		VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_RSP_ATUH_ABORT);
		vapp_dtcnt_wlan_auth_abort();
		m_houseKeeper->setWlanUiFlow  (WLAN_UI_NONE);
		srv_dtcnt_wlan_disconnect ();
	}
	else
	{
		// Start to logout
		m_houseKeeper->setWlanUiFlow (WLAN_UI_PORTAL_LOGOUT);		
		vapp_dtcnt_wlan_auth_logout(entryCMCCDisconnectProcCallback);
/*		
		vapp_cmcc_wlan_auth_ret_enum logout_status;
		logout_status = vapp_dtcnt_wlan_auth_logout(entryCMCCDisconnectProcCallback);
		m_houseKeeper->setWlanUiFlow (WLAN_UI_PORTAL_LOGOUT);
		VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_ENTRY_LOGOUT_STATUS, logout_status);
		if(VAPP_CMCC_WLAN_AUTH_WBLOCK == logout_status)
		{
			// Show global popup			
			VappWlanSentry::showGlobalPopup(GRP_ID_ROOT, NULL, STR_GLOBAL_PLEASE_WAIT);
		}
		else
		{
			entryCMCCDisconnectProcCallback (logout_status);
		}
 */		
	}
	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_ENTRY_LOGOUT_DONE, m_houseKeeper->getWlanUiFlow ());
}

void VappWlanCMCCMgr::entryCMCCPortalCertCallback(vapp_cmcc_wlan_auth_ret_enum ret)
{
	VappWlanRepository *m_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

    VFX_TRACE(("==============================================\n"));
    VFX_TRACE(("===> 1. Receive auth ret event! \n"));	
	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_ENTRY_LOGIN_CALLBACK, ret);

	VfxU8 portalResult = 0;

	VFX_ASSERT(VAPP_CMCC_WLAN_AUTH_WBLOCK != ret);// not sure.
	if(VAPP_CMCC_WLAN_AUTH_WBLOCK != ret)
    {
    	m_houseKeeper->setWlanUiFlow(WLAN_UI_NONE);
    }

    // Show popup
    switch(ret)
    {
    case VAPP_CMCC_WLAN_AUTH_OK:                 /* Login successfully */
    case VAPP_CMCC_WLAN_AUTH_NO_NEED_LOGIN:      /* Server response OK directly, could take it as CMCC_WLAN_AUTH_OK */
      	// conn popup
      	portalResult = 1;
      	mmi_frm_nmgr_notify_by_app(
      		MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_QUERY,
            entryCMCCShowPortalResult,
            &portalResult);  
        break;
    case VAPP_CMCC_WLAN_AUTH_NO_ACCOUNT:         /* User press NO in the setting screen */
        // break;
    case VAPP_CMCC_WLAN_AUTH_ABORTED:            /* Action aborted by user */
		// trace		  
        entryCMCCSendDiscReqAfterLoginFailed();
        break;      
    case VAPP_CMCC_WLAN_AUTH_WBLOCK:             /* Would block, callback will be called later */
    case VAPP_CMCC_WLAN_AUTH_PARA_ERROR:         /* Parameter error */
    case VAPP_CMCC_WLAN_AUTH_BUSY:               /* Previous login / logout activity not finished */
    case VAPP_CMCC_WLAN_AUTH_WPS_ERROR:          /* HTTP layer error  */
    case VAPP_CMCC_WLAN_AUTH_BEARER_ERROR:       /* WiFi AP is unreachable */
    case VAPP_CMCC_WLAN_AUTH_LOGIN_FAIL:         /* CMCC server response fail, maybe wrong user name or password */
		// fail popup
		portalResult = 0;
		mmi_frm_nmgr_notify_by_app(
      		MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_QUERY,
            entryCMCCShowPortalResult,
            &portalResult); 
		// Send disconnect request
        // trace
        entryCMCCSendDiscReqAfterLoginFailed ();
        break;
    default:
        break;
    }
}

MMI_BOOL VappWlanCMCCMgr::entryCMCCShowPortalResult(mmi_scenario_id scen_id, void *arg)
{
	VfxU8* result = (VfxU8*)arg;
    //trace
    if(1 == *result)
    {
    	vapp_nmgr_global_popup_show_confirm_one_button_id(
                        MMI_SCENARIO_ID_DEFAULT,
                        VCP_POPUP_TYPE_SUCCESS, 
                        STR_ID_VAPP_WLAN_LOGIN_SUCCESS, 
                        STR_GLOBAL_OK, 
                        VCP_POPUP_BUTTON_TYPE_NORMAL,
                        NULL,
                        NULL);
    }
    else if(0 == *result)
    {
    	vapp_nmgr_global_popup_show_confirm_one_button_id(
                        MMI_SCENARIO_ID_DEFAULT,
                        VCP_POPUP_TYPE_FAILURE, 
                        STR_ID_VAPP_WLAN_LOGIN_FAILED, 
                        STR_GLOBAL_OK, 
                        VCP_POPUP_BUTTON_TYPE_NORMAL,
                        NULL,
                        NULL);

    }  
    return MMI_TRUE;
}

void VappWlanCMCCMgr::entryCMCCDisconnectProcCallback(vapp_cmcc_wlan_auth_ret_enum ret)
{
	VappWlanRepository *m_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

	VAPP_WLAN_CMCC_LOGOUT_ACTION action = m_houseKeeper->getActionAfterLogout();	
	// trace

    // Reset flag
    m_houseKeeper->setWlanUiFlow (WLAN_UI_NONE);
	
    // Close popup
    
    // To do action after logout successfully
	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_ENTRY_LOGOUT_CALLBACK, action);
	entryCMCCActionAfterLogout(action);
}

void VappWlanCMCCMgr::entryCMCCActionAfterLogout(VAPP_WLAN_CMCC_LOGOUT_ACTION action)
{
	switch(action)
	{
	case WLAN_AP_CMCC_LOGOUT_MANUAL_CONN:
		VappWlanSentry::SendConnectRequest ();
		break;
	case WLAN_AP_CMCC_LOGOUT_WPS_CONN:
#ifdef __WPS_SUPPORT__
		VappWlanSentry::SendWPSConnectRequest ();
#endif
		break;		
	case WLAN_AP_CMCC_LOGOUT_DISCONN:
		VappWlanSentry::SendDisconnectRequest ();
		break;
	case WLAN_AP_CMCC_LOGOUT_DEINIT:
		VappWlanSentry::SendDeinitRequest ();
		break;
	default:
		break;
	}
}

void VappWlanCMCCMgr::entryCMCCSendDiscReqAfterLoginFailed()
{
	VappWlanRepository *m_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

	m_houseKeeper->setWlanUiFlow(WLAN_UI_DISC_AFTER_LOGIN_FAILED);
    srv_dtcnt_wlan_auth_cancel ();
}

void VappWlanCMCCMgr::responseAddrChangeCnfEvent(mmi_event_struct* evt)
{
	VappWlanRepository *m_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 
    VfxContext *context = m_houseKeeper->getContext();

	VappWlanBaseInfo *baseInfo = m_houseKeeper->getConnectedAP();
	VappWlanProfile *profile = NULL;
 	VFX_OBJ_CREATE(profile, VappWlanProfile, context);
	VappWlanToolbox::getAppProfileByAppBaseInfo(baseInfo, profile);
	
	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_RSP_ADDR_CHANGE_CNF_START, m_houseKeeper->getWlanUiFlow ());		
	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_RSP_ADDR_CHANGE_CNF_PROFILE_DETAIL,
		profile == NULL, profile->getUseDhcp(), profile->getSsidLen() , profile->getApMgrType());
	
	if( profile )
    {
        if(!profile->getUseDhcp())
        {
        	// Reset flag if AP use custom IP addr.
            if(WLAN_UI_WAIT_FOR_IP_UPDATE == m_houseKeeper->getWlanUiFlow ())
            {
                m_houseKeeper->setWlanUiFlow (WLAN_UI_NONE);
            }
            // If not to use DHCP, no need to wait for IP address update indication
            // If Popup "...transfer to WLAN..." and connected AP is CMCC's AP, then send disconnect request
            entryCMCCPortalProc();
        }
    }
    else
    {
        if(WLAN_UI_WAIT_FOR_IP_UPDATE == m_houseKeeper->getWlanUiFlow ())
        {
            m_houseKeeper->setWlanUiFlow (WLAN_UI_NONE);
        }
    }
	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_RSP_ADDR_CHANGE_CNF_DONE, m_houseKeeper->getWlanUiFlow ());

	VFX_OBJ_CLOSE(profile);
}

void VappWlanCMCCMgr::responseCMCCLogoutIndEvent(mmi_event_struct* param)
{
	VappWlanRepository *m_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

	srv_dtcnt_wlan_logout_evt_struct* logout_ind_evt
								= (srv_dtcnt_wlan_logout_evt_struct*)param;
	
	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_RSP_LOGOUT_IND_START, m_houseKeeper->getWlanUiFlow ());

	m_callback = NULL;
	if(logout_ind_evt)
	{
		m_callback = logout_ind_evt->rsp_callback;
	}

	if((WLAN_UI_PORTAL_LOGOUT != m_houseKeeper->getWlanUiFlow ()) &&
	   (SRV_DTCNT_WLAN_STATUS_CONNECTED == srv_dtcnt_wlan_status ()) &&
	   (SRV_DTCNT_WLAN_AP_DEFAULT == m_houseKeeper->getConnectedAP()->getApMgrType())&&
	   (WLAN_UI_WAIT_FOR_IP_UPDATE != m_houseKeeper->getWlanUiFlow ()))
	{
		// abort login if in progress
		entryCMCCProtalCertAbort();
		// start to logout
		m_houseKeeper->setWlanUiFlow (WLAN_UI_PORTAL_LOGOUT);
		vapp_dtcnt_wlan_auth_logout(entryCMCCLogoutIndCallback);
/*		
		vapp_cmcc_wlan_auth_ret_enum logout_status;
		m_houseKeeper->setWlanUiFlow (WLAN_UI_PORTAL_LOGOUT);
		logout_status = vapp_dtcnt_wlan_auth_logout(entryCMCCLogoutIndCallback);
		VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_RSP_LOGOUT_IND_STATUS, logout_status);
		if(VAPP_CMCC_WLAN_AUTH_WBLOCK != logout_status)
		{
			entryCMCCLogoutIndInformDtcntSrv(SRV_DTCNT_WLAN_LOGOUT_SUCC);
		}
 */
	}
	else
	{
		entryCMCCLogoutIndInformDtcntSrv(SRV_DTCNT_WLAN_LOGOUT_SUCC);
	}
	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_RSP_LOGOUT_IND_DONE, m_houseKeeper->getWlanUiFlow ());
}

void VappWlanCMCCMgr::entryCMCCLogoutIndCallback(vapp_cmcc_wlan_auth_ret_enum ret)
{	
    // Invoke callback
    if(VAPP_CMCC_WLAN_AUTH_OK == ret)
    {
        entryCMCCLogoutIndInformDtcntSrv(SRV_DTCNT_WLAN_LOGOUT_SUCC);
    }
    else
    {
        entryCMCCLogoutIndInformDtcntSrv(SRV_DTCNT_WLAN_LOGOUT_FAIL);
    }

}

void VappWlanCMCCMgr::entryCMCCLogoutIndInformDtcntSrv(srv_dtcnt_wlan_logout_rsp_enum rsp)
{
	//MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_AUTO_PORTAL_LOGOUT_IND_INFORM_DTCNT_SRV, rsp);
	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_RSP_LOGOUT_IND_INFORM_DTCNT_SRV, rsp, m_callback == NULL);
	if(m_callback)
    {
        m_callback(rsp);
    }
	m_callback = NULL;
}

VfxBool VappWlanCMCCMgr::isAllowToShowScrn(void)
{
#ifdef __DM_LAWMO_SUPPORT__
	if(srv_dm_lawmo_is_locked())
	{
		return VFX_FALSE;
	}
#endif /* __DM_LAWMO_SUPPORT__ */

#ifdef __MMI_USB_SUPPORT__
#ifdef __MMI_WEBCAM__
	if(mmi_usb_webcam_is_active())
	{
		return VFX_FALSE;
	}
#endif /* __MMI_WEBCAM__ */
#endif /* __MMI_USB_SUPPORT__ */

	if(mmi_scr_locker_is_locked ())
	{
		return VFX_FALSE;
	}
	
	if (srv_reminder_is_expiring())
	{
		return VFX_FALSE;
	}
	
	if (srv_ucm_is_any_call())
	{
		return VFX_FALSE;
	}
		
	return VFX_TRUE;
}

void VappWlanCMCCMgr::entryCMCCDeinitProc ()
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_ENTRY_DEINIT_PROC); 
	VappWlanRepository *m_houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 

	MMI_BOOL isAutoAuth = vapp_dtcnt_wlan_is_auto_auth();	
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_OP01_UI_CURRENT_STATUS,
			m_houseKeeper->getWlanUiFlow (), srv_dtcnt_wlan_status(), isAutoAuth);  

    if((WLAN_UI_PORTAL_LOGOUT != m_houseKeeper->getWlanUiFlow ()) &&  /* not in the logout proc */
       (SRV_DTCNT_WLAN_STATUS_CONNECTED == srv_dtcnt_wlan_status ()) &&
		SRV_DTCNT_WLAN_AP_DEFAULT == m_houseKeeper->getConnectedAP()->getApMgrType())
    {  	
    	m_houseKeeper->setActionAfterLogout(WLAN_AP_CMCC_LOGOUT_DEINIT);		
        VappWlanCMCCMgr::entryCMCCPortalCertLogoutStart ();
    }
	else
	{		
		VappWlanSentry::SendDeinitRequest ();
	}
}

#endif

/***************************************************************************** 
 * Class VappWlanToolbox
 *****************************************************************************/
srv_dtcnt_wlan_auth_mode_enum VappWlanToolbox::s_securityMode[SECURITY_INFRA_AUTH_MODE_MAX] = 
{ 
    SRV_DTCNT_WLAN_AUTH_MODE_OPEN,      /* authentication open */
    SRV_DTCNT_WLAN_AUTH_MODE_WEP,    /* shared */
#ifndef  WIFI_AUTH_PSK_ONLY
    SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X, /* 802.1x */
    SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY,       /* WPA */
    SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY,      /* WPA2 */
#endif    
    SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK,    /* WPAPSK */
    SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK,	  /* WPA2PSK */	
#ifdef  __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT,  /* WAPICERT */
    SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK    /* WAPIPSK */
#endif
#endif
};

srv_dtcnt_wlan_encrypt_mode_enum VappWlanToolbox::s_encryptionMode[ENCRYPTION_MODE_ARRAY_MAX] = 
{ 
    SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE,   /* unencrypt mode */
    //SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP,    /* WEP mode */
};

VfxBool VappWlanToolbox::isSameAP(const VappWlanBaseInfo* ap1, const VappWlanBaseInfo* ap2)
{
    if(NULL == ap1 || NULL == ap2)
        return VFX_FALSE;
    
    if((ap1->getSsidLen () == ap2->getSsidLen ()) && 
       (strcmp((const char*)ap1->getSsid (), (const char*)ap2->getSsid ()) == 0) &&
       (ap1->getNetworkType () == ap2->getNetworkType ()) &&
       (ap1->getAuthMode () == ap2->getAuthMode ()) &&
       (ap1->getEncryptMode () == ap2->getEncryptMode ()))
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

VfxU32 VappWlanToolbox::getNetworkTypeNum()
{
    return NETWORK_TYPE_ARRAY_MAX;
}

VfxU32 VappWlanToolbox::getSecurityModeNum(srv_dtcnt_wlan_network_type_enum networkType)
{
    switch(networkType)
    {
    case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:         /* infrasturcture mode */
        return SECURITY_INFRA_AUTH_MODE_MAX;
    case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:         /* ad-hoc mode */
        return SECURITY_ADHOC_AUTH_MODE_MAX;
    default:
        return 0;
    }
}

VfxU32 VappWlanToolbox::getEncryptionTypeNum(srv_dtcnt_wlan_auth_mode_enum authMode)
{
    VfxU32 number = 0;
    
    switch(authMode)
    {
    case SRV_DTCNT_WLAN_AUTH_MODE_OPEN:      /* authentication open */
        number = 1;
        break;
    case SRV_DTCNT_WLAN_AUTH_MODE_WEP:    /* shared */
    case SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X: /* 802.1x */
        number = 1;
        break;
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY:       /* WPA */
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK:    /* WPAPSK */
        number = 1;
        break;
#ifdef  __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    case SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT:  /* WAPICERT */
    case SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK:   /* WAPIPSK */
        number = 1;
        break;
#endif
#endif 
    default:
        break;
    }
    return number;
}

VfxU32 VappWlanToolbox::getWepKeyIndexNum()
{
    return WEP_KEY_INDEX_ARRAY_MAX;
}

VfxU32 VappWlanToolbox::getWepKeyEncryptNum()
{
    return WEP_KEY_ENCRYPT_ARRAY_MAX;
}

VfxU32 VappWlanToolbox::getWepKeyFormatNum()
{
    return WEP_KEY_FORMAT_ARRAY_MAX;
}

VfxU32 VappWlanToolbox::getWaiPskFormatNum()
{
    return WAI_KEY_FORMAT_ARRAY_MAX;
}

VfxWString VappWlanToolbox::getNetworkTypeStr(VfxU32 index)
{
	VfxWString networkTypeStr[NETWORK_TYPE_ARRAY_MAX] = 
	{ 
     	VFX_WSTR_RES(STR_ID_VAPP_WLAN_NETWORK_TYPE_INFRA), 
     	VFX_WSTR_RES(STR_ID_VAPP_WLAN_NETWORK_TYPE_ADHOC)
	};
	return networkTypeStr[index];
}

VfxWString VappWlanToolbox::getSecurityModeStr(VfxU32 index, srv_dtcnt_wlan_network_type_enum networkType)
{
    VfxWString securityModeStr[SECURITY_INFRA_AUTH_MODE_MAX];
    switch(networkType)
    {
    case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
        /* set security mode string array */
#ifndef  WIFI_AUTH_PSK_ONLY

        securityModeStr[0] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_OPEN);
        securityModeStr[1] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_SHARED);
        securityModeStr[2] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_IEEE8021X);
        // securityModeStr[3] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WPAPSK);
        securityModeStr[3] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WPAWPA2PSK); //MAUI_03327492
        securityModeStr[4] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WPA2PSK);
        // securityModeStr[5] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WPA);
        securityModeStr[5] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WPAWPA2); //MAUI_03327492
        securityModeStr[6] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WPA2);		
#ifdef  __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
        securityModeStr[7] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WAPI_CERT);
        securityModeStr[8] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WAPI_PSK);
#endif
#endif

#else
        securityModeStr[0] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_OPEN);
        securityModeStr[1] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_SHARED);
        // securityModeStr[2] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WPAPSK);
        securityModeStr[2] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WPAWPA2PSK); //MAUI_03327492
        securityModeStr[3] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WPA2PSK);	
#ifdef  __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
        securityModeStr[4] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WAPI_CERT);
        securityModeStr[5] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WAPI_PSK);
#endif
#endif

#endif  /* WIFI_AUTH_PSK_ONLY */
        break;
    case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
        securityModeStr[0] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_OPEN);
        securityModeStr[1] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_SHARED);
        securityModeStr[2] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_AUTH_MODE_WPA_NONE);
        break;
    default:
        break;
    }  
	return securityModeStr[index];
}

VfxWString VappWlanToolbox::getEncryptionModeStr(VfxU32 index, srv_dtcnt_wlan_auth_mode_enum authMode)
{
	VfxWString encryptionModeStr[ENCRYPTION_MODE_ARRAY_MAX];
    switch(authMode)
    {
    case SRV_DTCNT_WLAN_AUTH_MODE_OPEN:      /* authentication open */
        encryptionModeStr[0] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_ENCRYPT_MODE_NONE);
        break;
    case SRV_DTCNT_WLAN_AUTH_MODE_WEP:    /* shared */
    case SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X: /* 802.1x */
        encryptionModeStr[0] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_ENCRYPT_MODE_WEP);
        break;		
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY:       /* WPA */
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK:    /* WPAPSK */
        encryptionModeStr[0] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_ENCRYPT_MODE_TKIP);
        break;
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY:       /* WPA2 */
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK:    /* WPA2PSK */
        encryptionModeStr[0] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_ENCRYPT_MODE_AESCCMP);
        break;		
#ifdef  __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    case SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT:  /* WAPICERT */
    case SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK:   /* WAPIPSK */
        encryptionModeStr[0] = VFX_WSTR_RES(STR_ID_VAPP_WLAN_ENCRYPT_MODE_WPI);
        break;
#endif
#endif 
    default:
        break;
    }   
	return encryptionModeStr[index];
}

VfxWString VappWlanToolbox::getWepKeyIndexStr(VfxU32 index)
{
	VfxWString wepKeyIndexStr[WEP_KEY_INDEX_ARRAY_MAX] =
	{
		VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_INDEX_1),
		VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_INDEX_2),
		VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_INDEX_3),
		VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_INDEX_4)
	};
    return wepKeyIndexStr[index];
}

VfxWString VappWlanToolbox::getWepKeyEncryptStr(VfxU32 index)
{
	VfxWString wepKeyEncryptStr[WEP_KEY_ENCRYPT_ARRAY_MAX] =
	{
		VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_ENCRYPT_64),
		VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_ENCRYPT_128)
	};
    return wepKeyEncryptStr[index];
}

VfxWString VappWlanToolbox::getWepKeyFormatStr(VfxU32 index)
{
	VfxWString wepKeyFormatStr[WEP_KEY_FORMAT_ARRAY_MAX] =
	{
		VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_FORMAT_HEX),
		VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_FORMAT_ASCII)
	};
    return wepKeyFormatStr[index];
}

VfxWString VappWlanToolbox::getWaiKeyFormatStr(VfxU32 index)
{
	VfxWString waiKeyFormatStr[WAI_KEY_FORMAT_ARRAY_MAX] =
	{
		VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_FORMAT_HEX),
		VFX_WSTR_RES(STR_ID_VAPP_WLAN_WEP_FORMAT_ASCII)
	};	
    return waiKeyFormatStr[index];
}

srv_dtcnt_wlan_network_type_enum VappWlanToolbox::getNetworkType(VfxU32 index)
{
	srv_dtcnt_wlan_network_type_enum networkType[NETWORK_TYPE_ARRAY_MAX] = 
	{ 
		 SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA, 
		 SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC
	};
    return networkType[index];
}

srv_dtcnt_wlan_auth_mode_enum VappWlanToolbox::getSecurityMode(VfxU32 index)
{
    return s_securityMode[index];
}

srv_dtcnt_wlan_encrypt_mode_enum VappWlanToolbox::getEncryptionMode(VfxU32 index)
{
    return s_encryptionMode[index];
}

VfxU8 VappWlanToolbox::getWepKeyInUse(VfxU32 index)
{	
	VfxU8 wepKeyIndex[WEP_KEY_INDEX_ARRAY_MAX] = 
	{	
		0, 1, 2, 3
	};

    return wepKeyIndex[index];
}

srv_dtcnt_wlan_wep_key_encrypt_enum VappWlanToolbox::getWepKeyEncrypt(VfxU32 index)
{	
	srv_dtcnt_wlan_wep_key_encrypt_enum wepKeyEncrypt[WEP_KEY_ENCRYPT_ARRAY_MAX] =
	{
		SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_64,	/* 64 */
		SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_128	/* 128 */
	};
    return wepKeyEncrypt[index];
}

srv_dtcnt_wlan_wep_key_format_enum VappWlanToolbox::getWepKeyFormat(VfxU32 index)
{
	srv_dtcnt_wlan_wep_key_format_enum wepKeyFormat[WEP_KEY_FORMAT_ARRAY_MAX] = 
	{
		SRV_DTCNT_WLAN_WEP_KEY_FORMAT_HEX,	/* HEX encoded */
		SRV_DTCNT_WLAN_WEP_KEY_FORMAT_ASCII /* ASCII encoded */
	};
    return wepKeyFormat[index];
}

VfxU8 VappWlanToolbox::getWaiKeyFormat(VfxU32 index)
{
	VfxU8 waiKeyFormat[WAI_KEY_FORMAT_ARRAY_MAX] = 
	{
	    0, 1
	};
    return waiKeyFormat[index];
}

VfxU32 VappWlanToolbox::getNetworkTypeIndex(srv_dtcnt_wlan_network_type_enum networkTypeValue)
{
    VfxU32 index;
	srv_dtcnt_wlan_network_type_enum networkType[NETWORK_TYPE_ARRAY_MAX] = 
	{ 
		 SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA, 
		 SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC
	};
	
    for(index = 0; index < NETWORK_TYPE_ARRAY_MAX; index++)
    {
        if(networkTypeValue == networkType[index])
            break;
    }

    return index;
}

VfxU32 VappWlanToolbox::getSecurityModeIndex(srv_dtcnt_wlan_auth_mode_enum authMode)
{
    VfxU32 index;
    for(index = 0; index < SECURITY_INFRA_AUTH_MODE_MAX; index++)
    {
        if(authMode == s_securityMode[index])
            break;
    }

    return index;
}

VfxU32 VappWlanToolbox::getEncryptionModeIndex(srv_dtcnt_wlan_encrypt_mode_enum encryptionMode)
{
    VfxU32 index;
    for(index = 0; index < ENCRYPTION_MODE_ARRAY_MAX; index++)
    {
        if(encryptionMode == s_encryptionMode[index])
            break;
    }

    return index;
}

VfxU32 VappWlanToolbox::getWepKeyIndex(VfxU8 wepKeyIndexValue)
{
    VfxU32 index;
	VfxU8 wepKeyIndex[WEP_KEY_INDEX_ARRAY_MAX] = 
	{	
		0, 1, 2, 3
	};
	
    for(index = 0; index < WEP_KEY_INDEX_ARRAY_MAX; index++)
    {
        if(wepKeyIndexValue == wepKeyIndex[index])
            break;
    }

    return index;
}

VfxU32 VappWlanToolbox::getWepKeyEncryptIndex(srv_dtcnt_wlan_wep_key_encrypt_enum wepKeyEncryptValue)
{
    VfxU32 index;
	srv_dtcnt_wlan_wep_key_encrypt_enum wepKeyEncrypt[WEP_KEY_ENCRYPT_ARRAY_MAX] =
	{
		SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_64,	/* 64 */
		SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_128	/* 128 */
	};
	
    for(index = 0; index < WEP_KEY_ENCRYPT_ARRAY_MAX; index++)
    {
        if(wepKeyEncryptValue == wepKeyEncrypt[index])
            break;
    }

    return index;
}

VfxU32 VappWlanToolbox::getWepKeyFormatIndex(srv_dtcnt_wlan_wep_key_format_enum wepKeyFormatValue)
{
    VfxU32 index;
	srv_dtcnt_wlan_wep_key_format_enum wepKeyFormat[WEP_KEY_FORMAT_ARRAY_MAX] = 
	{
		SRV_DTCNT_WLAN_WEP_KEY_FORMAT_HEX,	/* HEX encoded */
		SRV_DTCNT_WLAN_WEP_KEY_FORMAT_ASCII /* ASCII encoded */
	};
	
    for(index = 0; index < WEP_KEY_FORMAT_ARRAY_MAX; index++)
    {
        if(wepKeyFormatValue == wepKeyFormat[index])
            break;
    }

    return index;
}

VfxU32 VappWlanToolbox::getWaiPskFormatIndex(VfxU32 waiPskFormatValue)
{
    VfxU32 index;
	VfxU8 waiKeyFormat[WAI_KEY_FORMAT_ARRAY_MAX] = 
	{
	    0, 1
	};
	
    for(index = 0; index < WAI_KEY_FORMAT_ARRAY_MAX; index++)
    {
        if(waiPskFormatValue == waiKeyFormat[index])
            break;
    }

    return index;
}

void VappWlanToolbox::setSecurityMode(srv_dtcnt_wlan_network_type_enum networkType)
{
    switch(networkType)
    {
    case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
        /* set security mode enum array */
#ifndef  WIFI_AUTH_PSK_ONLY

        s_securityMode[0] = SRV_DTCNT_WLAN_AUTH_MODE_OPEN;
        s_securityMode[1] = SRV_DTCNT_WLAN_AUTH_MODE_WEP;
        s_securityMode[2] = SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X;
        s_securityMode[3] = SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK;
        s_securityMode[4] = SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK;
        s_securityMode[5] = SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY;
        s_securityMode[6] = SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY;	
#ifdef  __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
        s_securityMode[7] = SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT;
        s_securityMode[8] = SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK;
#endif
#endif

#else
        s_securityMode[0] = SRV_DTCNT_WLAN_AUTH_MODE_OPEN;
        s_securityMode[1] = SRV_DTCNT_WLAN_AUTH_MODE_WEP;
        s_securityMode[2] = SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK;
        s_securityMode[3] = SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK;
#ifdef  __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
        s_securityMode[4] = SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT;
        s_securityMode[5] = SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK;
#endif
#endif

#endif  /* WIFI_AUTH_PSK_ONLY */
        break;
    case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:      
        s_securityMode[0] = SRV_DTCNT_WLAN_AUTH_MODE_OPEN;
        s_securityMode[1] = SRV_DTCNT_WLAN_AUTH_MODE_WEP;
        s_securityMode[2] = SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK;
        break;
    default:
        break;
    }
}

void VappWlanToolbox::setEncryptionMode(srv_dtcnt_wlan_auth_mode_enum authMode)
{
    switch(authMode)
    {
    case SRV_DTCNT_WLAN_AUTH_MODE_OPEN:      /* authentication open */
        s_encryptionMode[0] = SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE;
        break;
    case SRV_DTCNT_WLAN_AUTH_MODE_WEP:    /* shared */
    case SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X: /* 802.1x */
        s_encryptionMode[0] = SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP;
        break;		
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY:       /* WPA */
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK:    /* WPAPSK */
        s_encryptionMode[0] = SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP;
        break;
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY:       /* WPA2 */
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK:    /* WPA2PSK */
        s_encryptionMode[0] = SRV_DTCNT_WLAN_ENCRYPT_MODE_AES;
        break;		
#ifdef  __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    case SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT:  /* WAPICERT */
    case SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK:   /* WAPIPSK */
        s_encryptionMode[0] = SRV_DTCNT_WLAN_ENCRYPT_MODE_WPI;
        break;
#endif
#endif 
    default:
        break;
    }
}

void VappWlanToolbox::updateSecurityMode(
        srv_dtcnt_wlan_network_type_enum curNetworkType,
        srv_dtcnt_wlan_network_type_enum preNetworkType,
        srv_dtcnt_wlan_auth_mode_enum& authMode)
{
    
    switch(curNetworkType)
    {
    case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:  /* infrasturcture mode */
		switch(authMode)
        {       
        case SRV_DTCNT_WLAN_AUTH_MODE_TOTAL: /* No Support */
			authMode = SRV_DTCNT_WLAN_AUTH_MODE_OPEN;			
            break;
		default:
            break;
		}
        break;
    case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:  /* ad-hoc mode */
        switch(authMode)
        {
        case SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X: /* 802.1x */
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY:       /* WPA */
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY:      /* WPA2 */	
		case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK:  /* WPA2 PSK*/
		case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK:  /* WPA PSK*/	
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
        case SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT:  /* WAPICERT */
        case SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK:   /* WAPIPSK */
#endif /* __MMI_HIDE_WAPI__ */
#endif  
		case SRV_DTCNT_WLAN_AUTH_MODE_TOTAL: /* No Support */
            authMode = SRV_DTCNT_WLAN_AUTH_MODE_OPEN;
            break;
        default:
            break;
            
        }
        break;
    default:
        break;
    }
}

void VappWlanToolbox::updateEncryptionMode(
            srv_dtcnt_wlan_auth_mode_enum curAuthMode,
            srv_dtcnt_wlan_auth_mode_enum preAuthMode,
            srv_dtcnt_wlan_encrypt_mode_enum& encryptMode)
{
    switch (curAuthMode)
    {
    case SRV_DTCNT_WLAN_AUTH_MODE_OPEN:      /* authentication open */
        encryptMode = SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE;
        break;
    case SRV_DTCNT_WLAN_AUTH_MODE_WEP:    /* shared */
    case SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X: /* 802.1x */
        encryptMode = SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP;
        break;
	case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK:
	case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY:		
        encryptMode = SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP;
        break;	
	case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK:
	case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY:		
        encryptMode = SRV_DTCNT_WLAN_ENCRYPT_MODE_AES;
        break;				
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    case SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT:  /* WAPICERT */
    case SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK:   /* WAPIPSK */
        encryptMode = SRV_DTCNT_WLAN_ENCRYPT_MODE_WPI;
        break;
#endif /* __MMI_HIDE_WAPI__ */
#endif  
    default:
        encryptMode = SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE;
        break;
    }
}

void VappWlanToolbox::initWlanProfile(VappWlanProfile* profile)
{
    initAppProfile(profile);
    
    profile->setNetworkType (SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA);
    profile->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_OPEN);
    profile->setEncryptMode (SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE);
    profile->setEapAuthType (WLAN_EAP_TLS);
    profile->setEapAuthType (WLAN_EAP_AKA);

#ifdef WLAN_EAP_PEAP_SUPPORT
    profile->setEapPeapAuthType (WLAN_EAP_TLS);
#endif
#ifdef WLAN_EAP_TTLS_SUPPORT
#ifdef WLAN_EAP_SIM_SUPPORT
    profile->setEapTtlsAuthType (WLAN_EAP_SIM);
    profile->setEapTtlsAuthType (WLAN_EAP_AKA);
#else
    profile->setEapTtlsAuthType (WLAN_EAP_TLS);
    profile->setEapTtlsAuthType (WLAN_EAP_AKA);
#endif
#endif
    profile->setWepKeyLen (SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_64);
    profile->setWepKeyFormat (SRV_DTCNT_WLAN_WEP_KEY_FORMAT_HEX);
    profile->setPeapVersion (SUPC_PHASE1_PEAP_0 | SUPC_PHASE1_PEAP_1);
    profile->setUseDhcp (VFX_TRUE);
    profile->setUseProxy (VFX_FALSE);

	profile->setApCharset(CHSET_UTF8);

}

void VappWlanToolbox::initAppProfile(VappWlanProfile* appProfile)
{
    VfxWString  none = VFX_WSTR_RES(STR_GLOBAL_NONE);
    VfxU8 certName[SRV_DTCNT_PROF_MAX_USER_LEN + 1];

    memset(certName, 0, SRV_DTCNT_PROF_MAX_USER_LEN + 1);
    VappWlanToolbox::convertStrToAscii ((VfxChar*)certName, none, none.getLength ());

    appProfile->setProfileId (0);
    appProfile->setPriority (0);
    appProfile->setClientCaId (0);
    appProfile->setPxPort (0);
    appProfile->setRootCaId (0);
    appProfile->setWepKeyIndex (0);
    
    appProfile->setCaCertName (certName);
    appProfile->setUserCertName (certName); 

    appProfile->clearSsid ();
    appProfile->clearBssid();
    appProfile->clearWepKey();
    appProfile->clearIpAddr();
    appProfile->clearNetmask();
    appProfile->clearGateway();
    appProfile->clearDns1();
    appProfile->clearDns2();
    appProfile->clearpxAddr();
    appProfile->clearPxAuthId();
    appProfile->clearPxAuthPw();
    appProfile->clearHomePage();
    appProfile->clearUserName();
    appProfile->clearPassphrase();
    appProfile->clearPsk();
    appProfile->clearPassword();
    appProfile->clearPrivateKeyPasswd();
#ifdef __WAPI_SUPPORT__
    appProfile->setWapiPskFormat (0);
    appProfile->setWapiClientId (0);
    appProfile->setWapiAseId (0);    
    appProfile->clearWapiPskStr();
    appProfile->clearWapiPrivateKeyPasswdStr();
#endif
}

void VappWlanToolbox::initAppProfileWithDefaultEapValue(VappWlanProfile* appProfile)
{
    // Init
    appProfile->clearEapAuthType ();
    appProfile->clearEapPeapAuthType ();
    appProfile->clearEapTtlsAuthType ();
    
    appProfile->setEapAuthType (WLAN_EAP_PEAP);
    appProfile->setEapPeapAuthType (WLAN_EAP_MSCHAV2);
    appProfile->setEapPeapAuthType (WLAN_EAP_GTC);
    /// ???
    appProfile->setEapTtlsAuthType (WLAN_EAP_SIM);

    appProfile->setEapAuthType (WLAN_EAP_TTLS);
    appProfile->setEapTtlsAuthType (WLAN_EAP_SIM);
    appProfile->setEapTtlsAuthType (WLAN_EAP_MSCHAV2);
    appProfile->setEapTtlsAuthType (WLAN_MSCHAPV2);
    appProfile->setEapTtlsAuthType (WLAN_EAP_GTC);
    appProfile->setEapTtlsAuthType (WLAN_PAP);
    appProfile->setEapTtlsAuthType (WLAN_CHAP);
    appProfile->setEapTtlsAuthType (WLAN_MSCHAP);
    appProfile->setEapTtlsAuthType (WLAN_EAP_AKA);
    
    appProfile->setEapAuthType (WLAN_EAP_SIM);
    appProfile->setEapAuthType (WLAN_EAP_AKA);
}

void VappWlanToolbox::initAppProfileBySrvProfile(VappWlanProfile* appProfile, const srv_dtcnt_prof_wlan_struct* srvProfile)
{
	mmi_chset_enum ret_charset;
	
    appProfile->setSsid (srvProfile->ssid, srvProfile->ssid_len);

    appProfile->setRootCaId (srvProfile->root_ca_id);
    appProfile->setClientCaId (srvProfile->client_ca_id);

#ifdef __WAPI_SUPPORT__
    appProfile->setWapiAseId (srvProfile->wapi_ase_id);
    appProfile->setWapiClientId (srvProfile->wapi_client_id);
    appProfile->setWapiPskFormat (srvProfile->wapi_psk_format);
    appProfile->setWapiPskStr (srvProfile->wapi_psk_str);
    appProfile->setWapiPrivateKeyPasswdStr ((const VfxS8*)srvProfile->wapi_private_key_passwd_str);
#endif

    appProfile->setApName (srvProfile->ProfName);
    appProfile->setPriority (srvProfile->priority);
    appProfile->setProfileId (srvProfile->profile_id);
    appProfile->setSsidLen (srvProfile->ssid_len);
    appProfile->setChannelNumber(srvProfile->channel);
        
    appProfile->setPassphrase (srvProfile->passphrase);
    appProfile->setWepKey (srvProfile->wep_key);
    appProfile->setPeapVersion (srvProfile->peap_version);
        
    appProfile->setUserName (srvProfile->username);
    appProfile->setNetworkType (srvProfile->network_type);

    appProfile->setPassword (srvProfile->password);
    appProfile->setAuthMode (srvProfile->auth_mode);
    appProfile->setPrivateKeyPasswd (srvProfile->private_key_passwd);
    appProfile->setEncryptMode (srvProfile->encrypt_mode);
    appProfile->setPsk (srvProfile->psk);
    appProfile->resetEapAuthType (srvProfile->eap_auth_type);
    appProfile->resetEapPeapAuthType (srvProfile->eap_peap_auth_type);
    appProfile->resetEapTtlsAuthType (srvProfile->eap_ttls_auth_type);
    appProfile->setWepKeyIndex (srvProfile->wep_key_index);
    appProfile->setWepKeyLen ((srv_dtcnt_wlan_wep_key_encrypt_enum)srvProfile->wep_key_len);
    appProfile->setWepKeyFormat (srvProfile->wep_key_format);

    // TCP/IP settings
    if(MMI_TRUE == srvProfile->use_dhcp)
    {
        appProfile->setUseDhcp (VFX_TRUE);
    }
    else
    {
        appProfile->setUseDhcp (VFX_FALSE);
    }
    appProfile->setIpAddr (srvProfile->ip_addr);
    appProfile->setNetmask (srvProfile->netmask);
    appProfile->setGateway (srvProfile->gateway);
    appProfile->setDns1 (srvProfile->dns1);
    appProfile->setDns2 (srvProfile->dns2);
    
    // Advanced settings
    if(0 == srvProfile->use_proxy)
    {
        appProfile->setUseProxy (VFX_FALSE);
    }
    else
    {
        appProfile->setUseProxy (VFX_TRUE);
    }
    appProfile->setHomePage (srvProfile->HomePage);
    appProfile->setPxAddr (srvProfile->px_addr);
    appProfile->setPxPort (srvProfile->px_port);
    appProfile->setPxAuthId (srvProfile->px_authid);
    appProfile->setPxAuthPw (srvProfile->px_authpw);

	ret_charset = mmi_chset_guess(
                   (const char *)srvProfile->ssid,
                   srvProfile->ssid_len,
                   (mmi_chset_enum)0,
                   CHSET_GUESS_ALL);
	appProfile->setApCharset(ret_charset);
	
	// Ap mgr type
	appProfile->setApMgrType (srvProfile->ap_type);
}

void VappWlanToolbox::saveSecurityInfo(VappWlanProfile* src, VappWlanProfile* dst)
{   
    // Pre-shared key
    dst->setPassphrase(src->getPassphrase ());
    dst->setPsk (src->getPsk ());
    // WEP key
    dst->setWepKeyIndex(src->getWepKeyIndex());
    dst->setWepKeyFormat(src->getWepKeyFormat ());
    dst->setWepKeyLen(src->getWepKeyLen ());
    dst->setWepKey(src->getWepKey ());
    // User name & password
    dst->setUserName(src->getUserName ());
    dst->setPassword(src->getPassword ());
    // EAP Types
    dst->resetEapAuthType(src->getEapAuthType ());
    dst->resetEapPeapAuthType(src->getEapPeapAuthType ());
    dst->resetEapTtlsAuthType(src->getEapTtlsAuthType ());
#ifdef __WAPI_SUPPORT__
    // WAI PSK
    dst->setWapiPskFormat(src->getWapiPskFormat ());
    dst->setWapiPskStr(src->getWapiPskStr ());
    // WAI Cert.
    dst->setWapiAseId(src->getWapiAseId ());
    dst->setWapiClientId(src->getWapiClientId ());
    dst->setWapiPrivateKeyPasswdStr(src->getWapiPrivateKeyPasswdStr ());
#endif
}

void VappWlanToolbox::cleanSecurityInfo(VappWlanProfile* profile)
{
    profile->clearUserName ();
    profile->clearPassword ();
    profile->clearWepKey ();
    profile->clearPsk ();
    profile->clearPassphrase ();
    profile->clearPrivateKeyPasswd ();
#ifdef __WAPI_SUPPORT__
    profile->clearWapiPskStr ();
    profile->clearWapiPrivateKeyPasswdStr();
#endif

    // Reset EAP settings
    profile->clearEapAuthType ();
    profile->clearEapPeapAuthType ();
    profile->clearEapTtlsAuthType ();
    
    profile->setEapAuthType (WLAN_EAP_TLS);
#ifdef WLAN_EAP_PEAP_SUPPORT
    profile->setEapPeapAuthType (WLAN_EAP_TLS);
#endif
#ifdef WLAN_EAP_TTLS_SUPPORT
#ifdef WLAN_EAP_SIM_SUPPORT
    profile->setEapTtlsAuthType (WLAN_EAP_SIM);
#else
    profile->setEapTtlsAuthType (WLAN_EAP_TLS);
#endif
#endif

}

void VappWlanToolbox::cloneWlanProfile(VappWlanProfile* inProfile, VappWlanProfile* outProfile)
{
    initWlanProfile (outProfile);
    
    outProfile->setPrivacy(inProfile->getPrivacy ());
    outProfile->setBssid (inProfile->getBssid ());
    outProfile->setSsidLen(inProfile->getSsidLen ());
    outProfile->setSsid(inProfile->getSsid (), inProfile->getSsidLen ());
    outProfile->setRssi(inProfile->getRssi ());
    outProfile->setChannelNumber(inProfile->getChannelNumber ());
    outProfile->setMaxRate(inProfile->getMaxRate ());
    outProfile->setNumOfAp(inProfile->getNumOfAp ());

    outProfile->setApName(inProfile->getApName ());
    outProfile->setNetworkType(inProfile->getNetworkType ());
    outProfile->setAuthMode(inProfile->getAuthMode ());
    outProfile->setEncryptMode(inProfile->getEncryptMode ());
    outProfile->resetEapAuthType(inProfile->getEapAuthType ());
    outProfile->resetEapPeapAuthType(inProfile->getEapPeapAuthType ());
    outProfile->resetEapTtlsAuthType(inProfile->getEapTtlsAuthType ());
    outProfile->setWepKeyFormat(inProfile->getWepKeyFormat ());
    outProfile->setUseDhcp(inProfile->getUseDhcp ());
    outProfile->setIpAddr(inProfile->getIpAddr ());
    outProfile->setNetmask(inProfile->getNetmask ());
    outProfile->setGateway(inProfile->getGateway ());
    outProfile->setDns1(inProfile->getDns1 ());
    outProfile->setDns2(inProfile->getDns2 ());
    outProfile->setUseProxy (inProfile->getUseProxy ());
    outProfile->setPxAddr(inProfile->getPxAddr ());
    outProfile->setPxAuthId(inProfile->getAuthId ());
    outProfile->setPxAuthPw(inProfile->getAuthPw ());
    outProfile->setHomePage(inProfile->getHomePage ());
    outProfile->setPriority(inProfile->getPriority ());
    outProfile->setPxPort(inProfile->getPxPort ());
    outProfile->setProfileId(inProfile->getProfileId ());
    outProfile->setRootCaId(inProfile->getRootCaId ());
    outProfile->setClientCaId(inProfile->getClientCaId ());
    outProfile->setCaCertName(inProfile->getCaCertName ());
    outProfile->setUserCertName(inProfile->getUserCertName ());
#ifdef __WAPI_SUPPORT__
    outProfile->setWapiPskStr(inProfile->getWapiPskStr ());
    outProfile->setWapiPrivateKeyPasswdStr(inProfile->getWapiPrivateKeyPasswdStr ());
    outProfile->setWapiAseId(inProfile->getWapiAseId ());
    outProfile->setWapiClientId(inProfile->getWapiClientId ());
    outProfile->setWapiPskFormat(inProfile->getWapiPskFormat ());
#endif
    outProfile->setPeapVersion(inProfile->getPeapVersion ());
    outProfile->setWepKeyIndex(inProfile->getWepKeyIndex ());
    outProfile->setWepKeyLen(inProfile->getWepKeyLen ());
    outProfile->setUserName(inProfile->getUserName ());
    outProfile->setPassphrase(inProfile->getPassphrase ());
    outProfile->setPsk(inProfile->getPsk ());
    outProfile->setWepKey(inProfile->getWepKey ());
    outProfile->setPassword(inProfile->getPassword ());
    outProfile->setPrivateKeyPasswd(inProfile->getPrivateKeyPasswd ());
    outProfile->setApMatchType(inProfile->getApMatchType ());
    outProfile->setConnType (inProfile->getConnType ());
	outProfile->setApCharset (inProfile->getApCharset ());
    outProfile->setApMgrType ((srv_dtcnt_wlan_ap_type_enum)inProfile->getApMgrType());
}

void VappWlanToolbox::convertStrToAscii(VfxChar* outStr, VfxWString& inStr, VfxU32 length)
{
    mmi_wcs_n_to_asc(outStr, (WCHAR*)inStr.getBuf (), (length * ENCODING_LENGTH));
}

VfxBool VappWlanToolbox::convertHexToStr(VfxChar* outStr, VfxChar* inStr, VfxU32 length)
{
    VfxU32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (length % 2 != 0)
    {
        return VFX_FALSE;
    }

    memset(outStr, 0, length / 2 + 1);

    for (i = 0, j = 0; i < length; i++)
    {
        j = (i - i % 2) / 2;
        if (inStr[i] >= '0' && inStr[i] <= '9')
        {
            outStr[j] += (inStr[i] - '0') << 4 * ((i + 1) % 2);
        }
        else if (inStr[i] >= 'A' && inStr[i] <= 'F')
        {
            outStr[j] += (inStr[i] - 'A' + 0x0A) << 4 * ((i + 1) % 2);
        }
        else if (inStr[i] >= 'a' && inStr[i] <= 'f')
        {
            outStr[j] += (inStr[i] - 'a' + 0x0A) << 4 * ((i + 1) % 2);
        }
        else
        {
            return VFX_FALSE;
        }
    }
    return VFX_TRUE;

}

VfxBool VappWlanToolbox::checkHexString(const VfxU8* src, VfxU8 len)
{
    VfxU32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < len; index++)
    {
        if (src[index] >= '0' && src[index] <= '9')
        {
            continue;
        }
        else if (src[index] >= 'A' && src[index] <= 'F')
        {
            continue;
        }
        else if (src[index] >= 'a' && src[index] <= 'f')
        {
            continue;
        }
        else
        {
            return VFX_FALSE;
        }
    }
    return VFX_TRUE;

}

VfxBool VappWlanToolbox::checkAsciiString(const VfxU8* src, VfxU8 length)
{
    VfxU8 hexValue;

    while(length)
    {
        hexValue = (VfxU16)(*((VfxU8 *)src));
        if(hexValue < 0x7f && hexValue > 0x1f)
        {
            length--;
            src++;
        }
        else
        {
            return FALSE;
        }
    }

    return TRUE;

}

VfxS16 VappWlanToolbox::checkUrlString(const VfxU8* url, VfxBool isBlankUrlValid)
{
    VfxS16 ret;
    VfxU8 temp[HOME_PAGE_LEN_MAX];
    VfxU8 urlAscii[HOME_PAGE_LEN_MAX];
    VfxU8  uriSchmLen;
    applib_url_struct urlInfo; 

    // check the zero length
    if (MMI_FALSE == isBlankUrlValid)
    {
        if (!mmi_ucs2strlen((const CHAR *)url))
        {
            return APPLIB_URL_ERR_INVALID_PARAM;
        }
    }
    else
    {
        if (!mmi_ucs2strlen((const CHAR *)url))
        {
            return 0;
        }
    }

    memset(urlAscii, 0, HOME_PAGE_LEN_MAX);
    memset(temp, 0, HOME_PAGE_LEN_MAX);

    // convert the UCS2 URL string into UTF-8
    mmi_chset_ucs2_to_utf8_string((VfxU8*)urlAscii, HOME_PAGE_LEN_MAX, (VfxU8*)url);

    // parse the URL string by using Applib API
    if (!(VfxS32) applib_parse_url((const char *)urlAscii, &urlInfo))
    {
        // if there is an empty URI scheme in the URL then append the default ("http://")
        // URI scheme
        if (urlInfo.scheme_type == applib_scheme_empty)
        {
            uriSchmLen = strlen((const char*)HOME_PAGE_DEFAULT_URL);
            if (strlen((const char*)urlAscii) > (U32)(HOME_PAGE_LEN_MAX - uriSchmLen - 1))
            {
                strncpy((char*)temp, (const char*)urlAscii, HOME_PAGE_LEN_MAX - uriSchmLen - 1);
                temp[HOME_PAGE_LEN_MAX - uriSchmLen - 1] = '\0';
            }
            else
            {
                strcpy((char*) temp, (const char*) urlAscii);
            }
            strcpy((char*) urlAscii, (const char*) HOME_PAGE_DEFAULT_URL);
            strcat((char*) urlAscii, (const char*) temp);
            
            // check whether it contain HTTP or HTTPS URI scheme with empty host
            if (MMI_FALSE == isBlankUrlValid)
            {
                if (!(VfxS32) applib_parse_url((const char*) urlAscii, &urlInfo))
                {
                    if ((urlInfo.scheme_type == applib_scheme_http) || (urlInfo.scheme_type == applib_scheme_https))
                    {

                        if (!urlInfo.len[APPLIB_URL_HOST_PART])
                        {
                            return APPLIB_URL_ERR_INVALID_HOST;
                        }
                    }
                }
            }
        }
        // check whether it contain HTTP or HTTPS URI scheme with empty host
        else if ((urlInfo.scheme_type == applib_scheme_http) || (urlInfo.scheme_type == applib_scheme_https))
        {
            if (MMI_FALSE == isBlankUrlValid)
            {
                if (!urlInfo.len[APPLIB_URL_HOST_PART])
                {
                    return APPLIB_URL_ERR_INVALID_HOST;
                }
            }
        }
    }

    // validate the UTF-8 URL string by using Applib API
    ret = (VfxS16)applib_url_is_valid((const char *)urlAscii);
    if (ret == 0)
    {        
        mmi_chset_utf8_to_ucs2_string((VfxU8*) url, (HOME_PAGE_LEN_MAX) * ENCODING_LENGTH, (VfxU8*) urlAscii);
    }
    
    return ret;
}

VfxBool VappWlanToolbox::checkWepKey(VappWlanProfile* profile)
{
    const VfxU8* wepKey = profile->getWepKey ();
    VfxBool isValid = VFX_TRUE;
    
    switch(profile->getWepKeyLen ())
    {
        case SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_64:  /* 64 */
            if(profile->getWepKeyFormat () == SRV_DTCNT_WLAN_WEP_KEY_FORMAT_HEX)
            {
                if (strlen((const char*)wepKey) != WEP_KEY_LENGTH_64BITS_HEX ||
                    VFX_FALSE == VappWlanToolbox::checkHexString(wepKey, WEP_KEY_LENGTH_64BITS_HEX))
                {
                    isValid = VFX_FALSE;
                } 
            }
            else if(profile->getWepKeyFormat () == SRV_DTCNT_WLAN_WEP_KEY_FORMAT_ASCII)
            {
                if (strlen((const char*)wepKey) != WEP_KEY_LENGTH_64BITS_ASCII ||
                    VFX_FALSE == VappWlanToolbox::checkAsciiString(wepKey, WEP_KEY_LENGTH_64BITS_ASCII))
                {
                    isValid = VFX_FALSE;
                }

            }
            break;
        case SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_128: /* 128 */
            if(profile->getWepKeyFormat () == SRV_DTCNT_WLAN_WEP_KEY_FORMAT_HEX)
            {
                if (strlen((const char*)wepKey) != WEP_KEY_LENGTH_128BITS_HEX ||
                    VFX_FALSE == VappWlanToolbox::checkHexString(wepKey, WEP_KEY_LENGTH_128BITS_HEX))
                {
                    isValid = VFX_FALSE;
                } 
                
            }
            else if(profile->getWepKeyFormat () == SRV_DTCNT_WLAN_WEP_KEY_FORMAT_ASCII)
            {
                if (strlen((const char*)wepKey) != WEP_KEY_LENGTH_128BITS_ASCII ||
                    VFX_FALSE == VappWlanToolbox::checkAsciiString(wepKey, WEP_KEY_LENGTH_128BITS_ASCII))
                {
                    isValid = VFX_FALSE;
                }
            }
            break;
        default:
            isValid = VFX_FALSE;
            break;
    }

    return isValid;
 
}

VfxBool VappWlanToolbox::checkPriorityInSrvDb(VappWlanProfile* profile)
{
    srv_dtcnt_store_prof_data_struct profileInfo;
    srv_dtcnt_prof_wlan_struct wlanProfile;
    
    profileInfo.prof_type = SRV_DTCNT_BEARER_WIFI;
    profileInfo.prof_fields = SRV_DTCNT_WLAN_PROF_FIELD_PRIORITY;
    profileInfo.prof_data = &wlanProfile;
    srv_dtcnt_store_qry_prof(profile->getProfileId (), &profileInfo);
    //VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_ADD_NEW_NETWORK_PRIORITY, 
    //    wlanProfile.priority, profile->getPriority ());
    if(wlanProfile.priority == profile->getPriority ())
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

VfxBool VappWlanToolbox::checkAddress(VfxWChar* addrStr, VfxU8* addr, VfxBool isBlankValid, VfxBool isAllZeroValid)
{
    // emtpy
    if (VFX_FALSE == isBlankValid)
    {
        if (!mmi_wcslen((WCHAR*)addrStr))
        {
            return VFX_FALSE;
        }
    }
    else
    {
        if (!mmi_wcslen((WCHAR*)addrStr))
        {
            return VFX_TRUE;
        }
    }

    // get ip value
    VfxU16 ipAddress[IP_ADDRESS_PART_LEN_MAX]; /* use U16 to justify ip value > 255 */
    VfxChar tmpBuf[IP_ADDRESS_PART_LEN_MAX * 4];
    VfxChar *point, *p, *q;
    VfxS32 i = 0;
    mmi_wcs_to_asc((CHAR*)tmpBuf, (WCHAR*)addrStr);
    /* not allow blank space */
    if (strchr(tmpBuf, ' '))
    {
        return VFX_FALSE;
    }
    if (strstr(tmpBuf, "...") || strstr(tmpBuf, ".."))
    {
        return VFX_FALSE;
    }
    p = tmpBuf;
    while ((i < IP_ADDRESS_PART_LEN_MAX) && p)
    {
        point = strchr(p, '.');
        if (point)
        {
            q = point + 1;
            point = NULL;
        }
        else
        {
            q = NULL;
        }
        if (!p || !strlen(p))
        {
            return VFX_FALSE;
        }
        ipAddress[i] = atoi(p);
        p = q;
        if (ipAddress[i++] > 255)
        {
            return VFX_FALSE;
        }
    }
    if (i != IP_ADDRESS_PART_LEN_MAX || p)
    {
        return VFX_FALSE;
    }

    // check all zero of IP
    if (!isAllZeroValid)
    {
        if ((ipAddress[0] + ipAddress[1] + ipAddress[2] + ipAddress[3]) == 0)
        {
            return VFX_FALSE;
        }
    }

    // assign value
    for (i = 0; i < IP_ADDRESS_PART_LEN_MAX; i++)
    {
        addr[i] = (VfxU8)ipAddress[i];
    }    
    return VFX_TRUE;

}

VfxBool VappWlanToolbox::isUrlValid(const VfxChar* url)
{
    if(0 == applib_url_is_valid((const char *)url))
        return VFX_TRUE;
    else
        return VFX_FALSE;
}

void VappWlanToolbox::showInvalidPopup(const VfxWString &prompt, VfxScreen* scr)
{
    VcpConfirmPopup* invalidInputPopup;
    
    VFX_OBJ_CREATE (invalidInputPopup, VcpConfirmPopup, scr);
    invalidInputPopup->setInfoType (VCP_POPUP_TYPE_WARNING);
    invalidInputPopup->setText(prompt);
    invalidInputPopup->setButtonSet (VCP_CONFIRM_BUTTON_SET_OK);
    invalidInputPopup->setAutoDestory(VFX_TRUE);
    invalidInputPopup->show (VFX_TRUE);
}


void VappWlanToolbox::handleSegmentBtnEvent(
                        srv_dtcnt_wlan_network_type_enum curNetwork,
                        VappWlanProfile* profile)
{
    srv_dtcnt_wlan_network_type_enum preNetwork = profile->getNetworkType ();
    srv_dtcnt_wlan_auth_mode_enum curAuthMode;
    srv_dtcnt_wlan_auth_mode_enum preAuthMode = profile->getAuthMode ();
    srv_dtcnt_wlan_encrypt_mode_enum encryptMode = profile->getEncryptMode ();
    
    curAuthMode = preAuthMode;
    // Reset auth. mode if necessary
    VappWlanToolbox::updateSecurityMode (curNetwork, preNetwork, curAuthMode);
    // Set auth. mode property's content
    VappWlanToolbox::setSecurityMode (curNetwork);
    // Reset encrypt mode if auth. mode changed
    if(curAuthMode != preAuthMode)
    {
        VappWlanToolbox::updateEncryptionMode (curAuthMode, preAuthMode, encryptMode);    
        VappWlanToolbox::setEncryptionMode (curAuthMode);
        profile->setEncryptMode (encryptMode);
    }
    
    profile->setAuthMode (curAuthMode);
    profile->setNetworkType (curNetwork);

}

MMI_BOOL VappWlanToolbox::isTetheringInSwitching()
{
    // get wifi tethering's status
    MMI_BOOL isSwitching = srv_tethering_is_switching (SRV_TETHERING_TYPE_WIFI_HS);

    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_TETHERING_IS_SWITCHING, isSwitching);
    if(isSwitching)
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_INFO, 
            VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE).getBuf());
    }

    return isSwitching;
}

MMI_BOOL VappWlanToolbox::isFlightModeOn()
{
#ifdef __FLIGHT_MODE_SUPPORT__      
    // query the status of switching flight mode
    MMI_BOOL switching = srv_mode_switch_is_switching ();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_SETTING_INIT_RSP, switching);
#ifdef __COSMOS_WLAN_IN_FLGHT_MODE__
	// Not to change during switching flight mode
	if(MMI_TRUE == switching)
	{
		VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_LAUNCH_APP_FLIGHT_MODE_SWITCHING);
		mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_DEFAULT,
			MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_INFO, 
			VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE).getBuf());
		return MMI_TRUE;
	}
#else         
    // Not to change during switching flight mode and in flight mode
    if((MMI_TRUE == switching) ||
       (srv_mode_switch_is_network_service_available() == MMI_FALSE))
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_UI_LAUNCH_APP_FLIGHT_MODE);
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_INFO, 
            VFX_WSTR_RES(STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE).getBuf());
        return MMI_TRUE;
    }
#endif	
    return MMI_FALSE;
#else
    return MMI_FALSE;
#endif

}

void VappWlanToolbox::initWlanRegularInfo(VappWlanBaseInfo* profile)
{
	profile->setProfileId (0);
	profile->setPriority (0);
	profile->clearSsid ();
	profile->clearBssid();
	profile->setNetworkType (SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA);
	profile->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_OPEN);
	profile->setEncryptMode (SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE);
	profile->setApCharset(CHSET_UTF8);		
}

void VappWlanToolbox::initAppProfileByAppBaseInfo(VappWlanBaseInfo *src, VappWlanProfile* dest)
{	
	VappWlanToolbox::initWlanProfile(dest);
	VappWlanToolbox::cloneWlanBaseInfo(src, dest);	
}
 
void VappWlanToolbox::getAppProfileByAppBaseInfo(VappWlanBaseInfo* src, VappWlanProfile* dest)
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_GET_PROFILE_BY_BASE_INFO, 
        src->getProfileId(), src->getApMatchType(), src->getApMgrType(), src->getSsidLen (), src->getPriority ());

    // Profile which saved in dtcnt service will have profileId > 0. 
	if(src->getProfileId() > 0)
	{		
	    srv_dtcnt_prof_wlan_struct wlanProfile;
      	VappWlanToolbox::getSrvProfileByProfileId (&wlanProfile, src->getProfileId());
        VappWlanToolbox::initWlanProfile(dest);
        VappWlanToolbox::initAppProfileBySrvProfile (dest, &wlanProfile);
		VappWlanToolbox::cloneWlanBaseInfo(src, dest); //update parameter include Rssi,maxRate and so on
	}
	else
	{
		VappWlanToolbox::initAppProfileByAppBaseInfo(src, dest);	
    }
}

srv_dtcnt_result_enum VappWlanToolbox::getSrvProfileByProfileId(srv_dtcnt_prof_wlan_struct* profile, VfxU32 Id)
{
	memset(profile, 0, sizeof(srv_dtcnt_prof_wlan_struct));
	srv_dtcnt_store_prof_data_struct profileInfo;		
	srv_dtcnt_result_enum result;	
	profileInfo.prof_type = SRV_DTCNT_BEARER_WIFI;
	profileInfo.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;
	profileInfo.prof_data = profile;
	result =  srv_dtcnt_store_qry_prof(Id, &profileInfo);	 
	return result;
}

void VappWlanToolbox::cloneWlanBaseInfo(VappWlanBaseInfo* src, VappWlanBaseInfo* dest)
{
	dest->setBssid (src->getBssid());
	dest->setPrivacy (src->getPrivacy()); 	 
	dest->setSsidLen (src->getSsidLen()); 	  
	dest->setSsid (src->getSsid(), src->getSsidLen());
	dest->setRssi (src->getRssi());
	dest->setChannelNumber (src->getChannelNumber());
	dest->setMaxRate (src->getMaxRate());
	dest->setNumOfAp (src->getNumOfAp()); 	  
	dest->setApName (src->getApName());
	dest->setNetworkType (src->getNetworkType());
	dest->setAuthMode (src->getAuthMode());
	dest->setEncryptMode (src->getEncryptMode());
	dest->setPriority (src->getPriority());
	dest->setProfileId (src->getProfileId());
	dest->setApMatchType (src->getApMatchType()); 	  
	dest->setApCharset (src->getApCharset());
	dest->setApMgrType (src->getApMgrType()); 	
}

/***************************************************************************** 
 * Class VappAPListEntry
 *****************************************************************************/
VappAPListEntry*  VappAPListEntry::getValidPrev() const
{
    VappAPListEntry *i;
    for (i = m_prev; i != NULL; i = i->m_prev)
    {
        if (i->isValid())
        {
            break;
        }
    }
    return i;
}


VappAPListEntry*  VappAPListEntry::getValidNext() const
{
    VappAPListEntry *i;
    for (i = m_next; i != NULL; i = i->m_next)
    {
        if (i->isValid())
        {
            break;
        }
    }
    return i;
}

/***************************************************************************** 
 * Class VappApList
 *****************************************************************************/
VappAPListEntry *VappApList::getValidHead() const
{
    VappAPListEntry *i;
    for (i = m_head; i != NULL; i = i->m_next)
    {
        if (i->isValid())
        {
            break;
        }
    }
    return i;
}


VappAPListEntry *VappApList::getValidTail() const
{
    VappAPListEntry *i;
    for (i = m_tail; i != NULL; i = i->m_prev)
    {
        if (i->isValid())
        {
            break;
        }
    }
    return i;
}


VfxU32 VappApList::getEntryCount() const
{
    VfxU32 count = 0;
    VappAPListEntry *i;
    for (i = m_head; i != NULL; i = i->m_next)
    {
        count++;
    }
    return count;
}


VfxU32 VappApList::getValidCount() const
{
    VfxU32 count = 0;
    VappAPListEntry *i;
    
    for (i = m_head; i != NULL; i = i->m_next)
    {
        if (i->isValid())
        {
            count++;
        }
    }
    return count;
}

VappAPListEntry* VappApList::getPos(VfxU8 index) const
{
    VfxU8 count = 0;
    VappAPListEntry *i;

    for (i = m_head; i != NULL && count < index; i = i->m_next)
    {
        if (i->isValid())
        {
            count++;
        }
    }

    return i;
}

VappAPListEntry* VappApList::getEntry(VappWlanBaseInfo * obj) const
{
    VFX_OBJ_ASSERT_VALID(obj);
    
    VappAPListEntry *i;
    const VappWlanBaseInfo *profile;
    for (i = m_head; i != NULL; i = i->m_next)
    {
        profile = i->get ();
        if((profile->getSsidLen () == obj->getSsidLen ()) && 
           (strcmp((const char*)profile->getSsid (), (const char*)obj->getSsid ()) == 0) &&
           (profile->getNetworkType () == obj->getNetworkType ()) &&
           (profile->getAuthMode () == obj->getAuthMode ()) &&
           (profile->getEncryptMode () == obj->getEncryptMode ()))
        {
            return i;
        }
    }
    return NULL;

}

VappAPListEntry* VappApList::findOne(VfxU32 profileId)
{
    VappAPListEntry *i;
    const VappWlanBaseInfo *profile;
    for (i = m_head; i != NULL; i = i->m_next)
    {
        profile = i->get ();
        VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_RSP_FIND_PROFILE_IN_LIST, profile->getProfileId (), profileId);
        if(profile->getProfileId () == profileId)
        {
            return i;
        }
    }
    return NULL;

}

VappAPListEntry* VappApList::search(const VfxU8* bssid, const VfxU8* ssid, VfxU8 ssidLen)
{
    VappAPListEntry *i;
    const VappWlanBaseInfo *profile;
    for (i = m_head; i != NULL; i = i->m_next)
    {
        profile = i->get ();
        if((profile->getSsidLen () == ssidLen) && 
           (strncmp((const char*)profile->getSsid (), (const char*)ssid, ssidLen) == 0) &&
           (strncmp((const char*)profile->getBssid (), (const char*)bssid, WNDRV_MAC_ADDRESS_LEN) == 0))
        {
            return i;
        }
    }
    return NULL;

}


VfxBool VappApList::contains(VappWlanBaseInfo *obj) const
{
    VFX_OBJ_ASSERT_VALID(obj);
    
    VappAPListEntry *i;
    const VappWlanBaseInfo *profile;
    for (i = m_head; i != NULL; i = i->m_next)
    {
        profile = i->get ();
        if((profile->getSsidLen () == obj->getSsidLen ()) && 
           (strcmp((const char*)profile->getSsid (), (const char*)obj->getSsid ()) == 0) &&
           (profile->getNetworkType () == obj->getNetworkType ()) &&
           (profile->getAuthMode () == obj->getAuthMode ()) &&
           (profile->getEncryptMode () == obj->getEncryptMode ()))
        {
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}


VappAPListEntry *VappApList::append(VappWlanBaseInfo *obj)
{
    VFX_OBJ_ASSERT_VALID(obj);
	   
	VappAPListEntry *newEntry = NULL;  
	newEntry = createEntry(obj);

	// Let it be the first newEntry if list is empty
    if (m_head == NULL)
    {
        m_head = newEntry;
    }
    
    // Add to the tail of the list
    newEntry->m_next = NULL;
    newEntry->m_prev = m_tail;
    if (m_tail != NULL)
    {
        m_tail->m_next = newEntry;
    }
    m_tail = newEntry;

    return newEntry;
}


VappAPListEntry *VappApList::prepend(VappWlanBaseInfo *obj)
{
    VFX_OBJ_ASSERT_VALID(obj);
	
	VappAPListEntry *newEntry = NULL;	
	newEntry = createEntry(obj);

    // Let it be the last newEntry if list is empty
    if (m_tail == NULL)
    {
        m_tail = newEntry;
    }
    
    // Add to the front of the list
    newEntry->m_next = m_head;
    newEntry->m_prev = NULL;
    if (m_head != NULL)
    {
        m_head->m_prev = newEntry;
    }
    m_head = newEntry;

    return newEntry;
}

VappAPListEntry *VappApList::insertAfter(VappAPListEntry *entry, VappWlanBaseInfo *obj)
{
    VFX_ASSERT(entry != NULL);
    VFX_OBJ_ASSERT_VALID(obj);
    
	VappAPListEntry *newEntry = NULL;	
	newEntry = createEntry(obj);

    newEntry->m_prev = entry;
    newEntry->m_next = entry->m_next;
    
    if (entry->m_next != NULL)
    {
        entry->m_next->m_prev = newEntry;
    }
    else
    {
        m_tail = newEntry;
    }    
    entry->m_next = newEntry;

    return newEntry;
}


VappAPListEntry* VappApList::insertAt(VfxU8 index, VappWlanBaseInfo *obj)
{
    // VFX_ASSERT(index >= 0);
    VFX_OBJ_ASSERT_VALID(obj);

    VappAPListEntry* entry;
    VappAPListEntry* preEntry;
    
    if(index == 0)
    {
        entry = prepend (obj);
    }
    else
    {
        // Get previous entry
        preEntry = getPos (index - 1);
        VFX_OBJ_ASSERT_VALID(preEntry);

        // Insert object after this entry
        entry = insertAfter (preEntry, obj);
    }
    return entry;

}

VappAPListEntry* VappApList::createEntry(VappWlanBaseInfo *obj)
{
	VappWlanRepository *houseKeeper = VFX_OBJ_GET_INSTANCE(VappWlanRepository); 
	VfxContext *context = houseKeeper->getContext();

	vfx_sys_mem_pool_status_struct output,old;
	context->statistics(old);	
	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_STORAGE_CURRENT_USED_SIZE, old.used_size, __LINE__);

	VappAPListEntry *newEntry;
	VFX_ALLOC_NEW_EX(newEntry, VappAPListEntry, context, (obj));

	context->statistics(output);	
	VFX_LOG(VFX_FUNC3, TRC_VAPP_DTCNT_WLAN_STORAGE_NEW_ENTRY_SIZE, output.used_size - old.used_size, output.used_size);

	return newEntry;
}

void VappApList::removePos(VappAPListEntry *entry)
{
    VFX_ASSERT(entry != NULL);
    
    if (entry->m_prev != NULL)
    {
        entry->m_prev->m_next = entry->m_next;
    }
    else
    {
        VFX_ASSERT(m_head == entry);
        m_head = entry->m_next;
    }
    
    if (entry->m_next != NULL)
    {
        entry->m_next->m_prev = entry->m_prev;
    }
    else
    {
        VFX_ASSERT(m_tail == entry);
        m_tail = entry->m_prev;
    }
    
    entry->m_prev = NULL;
    entry->m_next = NULL;
    
    VFX_FREE_MEM(entry);
}


VfxBool VappApList::removeOne(VappWlanBaseInfo *obj)
{
    VFX_OBJ_ASSERT_VALID(obj);
    
    VappAPListEntry *i;
    const VappWlanBaseInfo *profile;
    for (i = m_head; i != NULL; i = i->m_next)
    {
        profile = i->get ();
        if((profile->getSsidLen () == obj->getSsidLen ()) && 
           (strcmp((const char*)profile->getSsid (), (const char*)obj->getSsid ()) == 0) &&
           (profile->getNetworkType () == obj->getNetworkType ()) &&
           (profile->getAuthMode () == obj->getAuthMode ()) &&
           (profile->getEncryptMode () == obj->getEncryptMode ()))
        {
            removePos(i);
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

VfxBool VappApList::removeOne(VfxU32 profileId)
{
    VappAPListEntry *i;
    const VappWlanBaseInfo *profile;
    for (i = m_head; i != NULL; i = i->m_next)
    {
        profile = i->get ();
        if(profile->getProfileId () == profileId)
        {
            removePos(i);
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

VfxU32 VappApList::removeAll(VappWlanBaseInfo *obj)
{
    VFX_OBJ_ASSERT_VALID(obj);

    VfxU32 remove_count = 0;
    VappAPListEntry *i = m_head;
    const VappWlanBaseInfo *profile;
    while (i != NULL)
    {
        VappAPListEntry *next = i->m_next;
        profile = i->get ();
        if((profile->getSsidLen () == obj->getSsidLen ()) && 
           (strcmp((const char*)profile->getSsid (), (const char*)obj->getSsid ()) == 0) &&
           (profile->getNetworkType () == obj->getNetworkType ()) &&
           (profile->getAuthMode () == obj->getAuthMode ()) &&
           (profile->getEncryptMode () == obj->getEncryptMode ()))
        {
            removePos(i);
            remove_count++;
        }
        
        i = next;
    }
    return remove_count;
}


void VappApList::removeAllInvalidate()
{
    VappAPListEntry *i = m_head;
    while (i != NULL)
    {
        VappAPListEntry *next = i->m_next;
        
        if (!i->m_ap.isValid())
        {
            removePos(i);
        }
        i = next;
    }
}


void VappApList::clear()
{
    VappAPListEntry *i = m_head;
    
    while (i != NULL)
    {
        VappAPListEntry *next = i->m_next;
        
		VFX_FREE_MEM(i);
        
        i = next;
    }
    
    m_head = NULL;
    m_tail = NULL;
}

#endif // __MMI_WLAN_FEATURES__
#endif // __TCPIP__

