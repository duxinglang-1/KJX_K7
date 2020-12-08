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
 *  vapp_dtcnt.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file implements interfaces for other app
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
// vcp control
#ifdef __TCPIP__

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vapp_dtcnt.h" 
extern "C"
{
#include "DtcntSrvGprot.h"
#include "DtcntSrvIprot.h"
#include "MMI_conn_app_trc.h"
#include "cbm_consts.h"
#include "TetheringSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "cbm_api.h"
}
#include "mmi_rp_vapp_dtcnt_def.h"
#include "vapp_sim_setting_gprot.h"

/***************************************************************************** 
* Static Declaration
*****************************************************************************/


/***************************************************************************** 
* Global Variable
*****************************************************************************/


/***************************************************************************** 
* Local Function
*****************************************************************************/


/***************************************************************************** 
* Global Function
*****************************************************************************/
  

/***************************************************************************** 
* Class VappDtcntDispItemList
*****************************************************************************/
VappDtcntDispItem VappDtcntDispItemList::m_acctItems[VAPP_DTCNT_PROF_MAX_ACCOUNT_NUM];
VfxU32 VappDtcntDispItemList::m_acctNum = 0;
//VfxU32 VappDtcntDispItemList::m_defaultProfileId = 0;
VfxU32 VappDtcntDispItemList::m_currEidtProfileId = CBM_INVALID_NWK_ACCT_ID;
#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__
VfxU8 VappDtcntDispItemList::m_acctidsInUse[VAPP_DTCNT_PROF_MAX_ACCOUNT_NUM];
VfxU8 VappDtcntDispItemList::m_acctidsInUseNum = 0;

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappDtcntSimAvailableListener);
#endif

#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__
void VappDtcntDispItemList::resetAcctItem()
{
	m_acctNum = 0;
   	memset(m_acctItems, 0, sizeof(VappDtcntDispItemList)* VAPP_DTCNT_PROF_MAX_ACCOUNT_NUM);
}

void VappDtcntDispItemList::resetAcctInUse()
{
	m_acctidsInUseNum = 0;
   	memset(m_acctidsInUse, 0, sizeof(m_acctidsInUse));
}

void VappDtcntDispItemList::addAcctInUse(VfxU8 accountId)
{
	m_acctidsInUse[m_acctidsInUseNum++] = accountId;
	MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_ON_SIM_DETECTED_UNDELETED, accountId, m_acctidsInUseNum);
}

void VappDtcntDispItemList::deleteAcctInUse(VfxU8 accountId)
{
	VfxU32 i, j;
	
	MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_ON_BEARER_INFO, accountId, m_acctidsInUseNum);
	for (i = 0; i < m_acctidsInUseNum; i++)
    {
        if (accountId == m_acctidsInUse[i])
        {
            srv_dtcnt_store_delete_prof(
                        m_acctidsInUse[i], 
                        MMI_TRUE, 
                        NULL, 
                        NULL);
            for (j = i; j + 1 < m_acctidsInUseNum; j++)
            {
                m_acctidsInUse[i] = m_acctidsInUse[i + 1];
            }
            m_acctidsInUseNum--;                
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_ON_BEARER_INFO, accountId, m_acctidsInUseNum);
            break;
        }
    }
}
#endif


VfxBool VappDtcntDispItemList::getFullAccountName(VfxU32 acctId, VfxWChar * dest, VfxU8 len, VappDtcntGetAcctNameTypeEnum type)
{
    // dest is null
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_GET_FULL_ACCOUNT_NAME, acctId, dest, len, type);
    if(dest == NULL)
    {
        return VFX_FALSE;
    }
    VfxBool retVal = VFX_FALSE;
    cbm_account_info_struct acctInfo;
    cbm_decode_data_account_id_ext(acctId, &acctInfo);

    #ifdef __MMI_WLAN_FEATURES__
    if (acctInfo.account[0].account_id == CBM_WIFI_ACCT_ID)
    {
        mmi_wcsncpy((WCHAR*)dest, (WCHAR*)GetString(STR_ID_VAPP_DTCNT_USED_WLAN), len);
        return MMI_TRUE;
    }
    #endif
	// When no sim card available
    if (!srv_sim_ctrl_any_sim_is_available())
    {
        mmi_wcsncpy((WCHAR*)dest, (WCHAR*)GetString(STR_ID_VAPP_DTCNT_NO_AVAILABLE_ACCOUNT), len);
        return MMI_TRUE;
    }
    // specail case for USB
    if (acctInfo.account[0].account_id == CBM_USB_TR_PS_ACCT_ID)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_GET_FULL_ACCOUNT_NAME, acctInfo.account[0].account_id, 0, 0, 0);
        acctInfo.account[0].account_id = (U8)srv_tethering_usb_qurey_acct_id();
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_GET_FULL_ACCOUNT_NAME, acctInfo.account[0].account_id, 0, 0, 0);
    }

    if (acctInfo.account[0].account_id == CBM_DEFAULT_ACCT_ID)
    {
        VfxU32 outAcctId;
        srv_dtcnt_result_enum result;
        result = srv_dtcnt_get_auto_acc_id(acctId, &outAcctId);

        if (result != SRV_DTCNT_RESULT_SUCCESS) // no accounts
        {
            mmi_wcsncpy((WCHAR*)dest, (WCHAR*)GetString(STR_ID_VAPP_DTCNT_NO_AVAILABLE_ACCOUNT), len);
            return MMI_TRUE;
        }
        else
        {
            acctInfo.account[0].account_id = cbm_get_original_account(outAcctId);
            if (acctInfo.account[0].account_id == CBM_DEFAULT_ACCT_ID)
            {
                mmi_wcsncpy((WCHAR*)dest, (WCHAR*)GetString(STR_ID_VAPP_DTCNT_NO_AVAILABLE_ACCOUNT), len);
                return MMI_TRUE;
            }
        }
    }

    srv_dtcnt_prof_str_info_qry_struct acctData;
    MMI_BOOL ret;
    acctData.dest_len = len;
    acctData.dest = (S8*)dest;
    ret = srv_dtcnt_get_account_name(
            acctInfo.account[0].account_id,
            &acctData,
            SRV_DTCNT_ACCOUNT_PRIMARY); 
    if (ret)
    {
        VfxU32 availSimNum;
        availSimNum = VappDtcntSimAvailableInfo::getAvailableSimNum();
        if (availSimNum > 1)
        {
            srv_dtcnt_sim_type_enum simType = SRV_DTCNT_SIM_TYPE_1;
            WCHAR tempSimInfo[DATA_ACCOUNT_NAME_SUFFIX_LEN + 1];
            srv_dtcnt_get_sim_info(acctInfo.account[0].account_id, &simType);
            kal_wsprintf((WCHAR*)tempSimInfo, "(SIM %d)", simType);
            mmi_wcscat((WCHAR*)dest, (WCHAR*)tempSimInfo);
        }
        return MMI_TRUE;
    }

    if (!retVal) /* for single */
    {
        mmi_wcscpy((WCHAR*)dest, (WCHAR*)GetString(STR_ID_VAPP_DTCNT_NO_AVAILABLE_ACCOUNT));
    }
    return retVal;
}


srv_dtcnt_result_enum VappDtcntDispItemList::setDefaultProfileIdToSrv(VfxU32 acctId)
{
    srv_dtcnt_store_prof_data_struct profInfo;
    srv_dtcnt_result_enum result = SRV_DTCNT_RESULT_FAILED;
    VfxU64 appType;

    if (SRV_DTCNT_BEARER_CSD == srv_dtcnt_get_bearer_type(acctId, SRV_DTCNT_ACCOUNT_PRIMARY))
    { 
        srv_dtcnt_prof_csd_struct csdProfSrv;
        profInfo.prof_type = SRV_DTCNT_BEARER_CSD;
        profInfo.prof_data = &csdProfSrv;
        profInfo.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;
    
        srv_dtcnt_store_qry_prof(acctId, &profInfo);
        appType = csdProfSrv.prof_common_header.AppType;
        
        profInfo.prof_type = SRV_DTCNT_BEARER_CSD;
        profInfo.prof_data = &csdProfSrv;
        profInfo.prof_fields = SRV_DTCNT_PROF_FIELD_APP_TYPE;
        memset(&csdProfSrv, 0, sizeof(srv_dtcnt_prof_gprs_struct));
        csdProfSrv.prof_common_header.AppType = appType | 0x01;
        result = srv_dtcnt_store_update_prof(acctId, &profInfo);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_SET_DEFAULT_PROFILE, acctId, result);
    }
    else if (SRV_DTCNT_BEARER_GPRS == srv_dtcnt_get_bearer_type(acctId, SRV_DTCNT_ACCOUNT_PRIMARY))
    {
        srv_dtcnt_prof_gprs_struct gprsProfSrv;
        profInfo.prof_type = SRV_DTCNT_BEARER_GPRS;
        profInfo.prof_data = &gprsProfSrv;
        profInfo.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;
    
        srv_dtcnt_store_qry_prof(acctId, &profInfo);
        appType = gprsProfSrv.prof_common_header.AppType;
        
        profInfo.prof_type = SRV_DTCNT_BEARER_GPRS;
        profInfo.prof_data = &gprsProfSrv;
        profInfo.prof_fields = SRV_DTCNT_PROF_FIELD_APP_TYPE;
        memset(&gprsProfSrv, 0, sizeof(srv_dtcnt_prof_gprs_struct));
        gprsProfSrv.prof_common_header.AppType = appType | 0x01;
        result = srv_dtcnt_store_update_prof(acctId, &profInfo);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_SET_DEFAULT_PROFILE, acctId, result);
    }    

    return result;
}

void VappDtcntDispItemList::addAcctItem(VappDtcntDispItem acctItem)
{
    VfxU32 i;
    VfxU32 acctId;
    acctId = acctItem.getProfileId();
    for (i = 0; i < m_acctNum; i++)
    {
        if (m_acctItems[i].getProfileId() == acctId)
        {
            return;
        }
    }
    memcpy(&m_acctItems[m_acctNum], &acctItem, sizeof(VappDtcntDispItem));
    m_acctNum++;
}


void VappDtcntDispItemList::updateAcctItem(VappDtcntDispItem acctItem)
{
    VfxU32 i;
    VfxU32 acctId;
    acctId = acctItem.getProfileId();
    for (i = 0; i < m_acctNum; i++)
    {
        if (m_acctItems[i].getProfileId() == acctId)
        {
            memcpy(&m_acctItems[i], &acctItem, sizeof(VappDtcntDispItem));
            break;
        }
    }
}

void VappDtcntDispItemList::deleteAcctItem(VfxU32 acctId)
{
    VfxU32 i, j;
    for (i = 0; i < VAPP_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
    {
        if (m_acctItems[i].getProfileId() == acctId)
        {
            for (j = i; j < m_acctNum - 1; j++)
            {
                // consider operator "="
                memcpy(&m_acctItems[j], &m_acctItems[j + 1], sizeof(VappDtcntDispItem));
            }
            memset(&m_acctItems[j], 0, sizeof(VappDtcntDispItem));
            m_acctNum--;
            break;
        }
    }
}

VfxBool VappDtcntDispItemList::isAccountInUse(VfxU32 accountId)
{
    cbm_bearer_state_enum status = CBM_DEACTIVATED;
    VfxU32 acctId;
    VfxU32 i;
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        acctId = cbm_encode_data_account_id(accountId, (cbm_sim_id_enum)(CBM_SIM_ID_SIM1 + i), 0, KAL_FALSE);
        status = (cbm_bearer_state_enum)cbm_get_bearer_status(acctId);
        
        if (status == CBM_ACTIVATED || 
            status == CBM_ACTIVATING ||
            status == CBM_DEACTIVATING)
        {
            return VFX_TRUE;
        }
    }

    // special use because of USB tethering
    VfxU32 pureId; // get from USB tethering
    pureId = (U32)cbm_get_original_account(srv_tethering_usb_qurey_acct_id());
    if (accountId == pureId)
    {
        for (i = 0; i < MMI_SIM_TOTAL; i++)
        {
            acctId = cbm_encode_data_account_id(CBM_USB_TR_PS_ACCT_ID, (cbm_sim_id_enum)(CBM_SIM_ID_SIM1 + i), 0, KAL_FALSE);    
            status = (cbm_bearer_state_enum)cbm_get_bearer_status(acctId);        
            if (status == CBM_ACTIVATED || 
                status == CBM_ACTIVATING ||
                status == CBM_DEACTIVATING)
            {
                return MMI_TRUE;
            }
        }
    }

    return VFX_FALSE;
}


VfxBool VappDtcntDispItemList::isAccountUseProxy(VfxU32 accountId)
{
    VfxBool result = VFX_FALSE;
    srv_dtcnt_prof_proxy_info_struct temp_proxy_info;
    if (MMI_TRUE == srv_dtcnt_get_proxy_info(
                        accountId,
                        &temp_proxy_info,
                        SRV_DTCNT_ACCOUNT_PRIMARY))
    {            
        if (temp_proxy_info.use_proxy)
        {
            result = VFX_TRUE;
        }
        else
        {
            result = VFX_FALSE;
        }
    }
    return result;
}


VfxWString VappDtcntDispItemList::getSimName(VfxU32 simIndex)
{
    VfxWString str;
    mmi_sim_enum simEnum = MMI_SIM1;
    simEnum = mmi_frm_index_to_sim(simIndex);
    str = vapp_sim_settings_get_sim_name_with_sim_id(simEnum);
    return str;
}

MMI_BOOL VappDtcntDispItemList::getApnlist(U32 *ids, U32 *num_ids, srv_dtcnt_sim_type_enum sim_type)
{
#ifdef __MMI_GPRS_FEATURES__
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;
    U32 gprsNum = 0, apnNumber = 0;
    U32 gprsArray[VAPP_DTCNT_PROF_MAX_ACCOUNT_NUM];
	
	srv_dtcnt_prof_str_info_qry_struct acct_data;
	U8 data_account_addr[MAX_DTCNT_LIST_ADDR_LEN * ENCODING_LENGTH];
	srv_dtcnt_prof_str_info_qry_struct acct_data_temp;
	U8 data_account_addr_temp[MAX_DTCNT_LIST_ADDR_LEN * ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


	if (!ids || !num_ids)
    {
        return MMI_FALSE;
    }
	acct_data.dest_len = MAX_DTCNT_LIST_ADDR_LEN * ENCODING_LENGTH;
    acct_data.dest = (char *)data_account_addr;

	acct_data_temp.dest_len = MAX_DTCNT_LIST_ADDR_LEN * ENCODING_LENGTH;
	acct_data_temp.dest = (char *)data_account_addr_temp;

    
    for (i = 0; i < m_acctNum; i++)
    {
        if(m_acctItems[i].getSimInfo() == sim_type)
        {
            if (m_acctItems[i].getBearerType() == DATA_ACCOUNT_BEARER_GPRS)
            {            
                gprsArray[gprsNum++] = m_acctItems[i].getProfileId();
            }
        }
    }
    
    *num_ids = 0; 
    if (gprsNum == 0)
    {
        return MMI_TRUE;
    }
    ids[apnNumber++] = gprsArray[0];
    for (i = 1; i < gprsNum; i++)
    {
        for (j = 0; j < i; j++)
        {
        	srv_dtcnt_get_apn(gprsArray[j], &acct_data , SRV_DTCNT_ACCOUNT_PRIMARY);
			srv_dtcnt_get_apn(gprsArray[i], &acct_data_temp, SRV_DTCNT_ACCOUNT_PRIMARY);
            if (mmi_ucs2icmp(acct_data_temp.dest, acct_data.dest) == 0)
            {
                break;
            }
        }
        if (i == j)
        {
            ids[apnNumber++] = gprsArray[i];
        }
    }
    *num_ids = apnNumber;
    return MMI_TRUE;
#else
    return MMI_FALSE;
#endif
}

/***************************************************************************** 
* Class VappDtcntReadyCheck
*****************************************************************************/

VfxBool VappDtcntReadyCheck::m_isDtcntReady = VFX_FALSE;
FuncPtr VappDtcntReadyCheck::m_readyCheckCB[DTCNT_READY_CHECK_NUM] = {0};

// register callback or return VFX_TRUE
VfxBool VappDtcntReadyCheck::dtcntReadyCheck(FuncPtr readyCallback, VfxBool withScrLock)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_READY_CHECK, m_isDtcntReady);
    if (m_isDtcntReady == VFX_TRUE)
    {
        return VFX_TRUE;
    }
    else
    {
        if (withScrLock)
        {
            ClearInputEventHandler(MMI_DEVICE_ALL);
            ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        }
        VfxU32 i;
        for (i = 0; i < DTCNT_READY_CHECK_NUM; i++)
        {
            if(!m_readyCheckCB[i])
            {
                m_readyCheckCB[i] = readyCallback;
                return VFX_FALSE;
            }
        }
    }
    return VFX_FALSE;
}


// execute callback function
void VappDtcntReadyCheck::executeReadyCheckCB()
{
    VfxU32 i;
    for (i = 0; i < DTCNT_READY_CHECK_NUM; i++)
    {
        if (m_readyCheckCB[i])
        {
            m_readyCheckCB[i]();
            m_readyCheckCB[i] = NULL;
        }
    }
}


/***************************************************************************** 
 * Class VappDtcntAcctValidity
 *****************************************************************************/

VappDtcntAcctValidTypeEnum VappDtcntAcctValidity::isAcctValid(VfxU32 encodedAcctId, VfxBool bearerFallback)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_ACCOUNT_ID_VALID, encodedAcctId, bearerFallback);
    cbm_account_info_struct acctInfo;
    cbm_decode_data_account_id_ext(encodedAcctId, &acctInfo);

    VfxU32 primaryId;
    
    primaryId = cbm_encode_data_account_id(
        acctInfo.account[0].account_id,
        acctInfo.account[0].sim_id,
        acctInfo.app_id,
        acctInfo.account[0].is_always_ask);
    //VFX_TRACE(());
#ifdef __MMI_CBM_BEARER_FALLBACK__
    VfxU32 secondaryId;
    secondaryId = cbm_encode_data_account_id(
        acctInfo.account[1].account_id,
        acctInfo.account[1].sim_id,
        acctInfo.app_id,
        acctInfo.account[1].is_always_ask);
#endif
    #ifndef __MMI_CBM_BEARER_FALLBACK__
    if (isSingleAcctValid(primaryId))
    {
        return DTCNT_ACCT_VALID_FIRST;
    }
    else
    {
        return DTCNT_ACCT_VALID_NONE;
    }
    #else
    VfxBool primaryValid, secondaryValid;
    primaryValid = isSingleAcctValid(primaryId);
    if (!bearerFallback)
    {
        if (primaryValid)
        {
            return DTCNT_ACCT_VALID_FIRST;
        }
        else
        {
            return DTCNT_ACCT_VALID_NONE;
        }
    }
    else
    {
        secondaryValid = isSingleAcctValid(secondaryId);

        if (primaryValid && secondaryValid)
        {
            return DTCNT_ACCT_VALID_FULL;
        }
        else if (primaryValid)
        {
            return DTCNT_ACCT_VALID_FIRST;
        }
        else if (secondaryValid)
        {
            return DTCNT_ACCT_VALID_SECOND;
        }
        else
        {
            return DTCNT_ACCT_VALID_NONE;
        }
    }    
    #endif
}


VfxBool VappDtcntAcctValidity::isSingleAcctValid(VfxU32 encodedAcctId)
{
    // Not need to check gsm only and wlan only in FTO
    cbm_account_info_struct acctInfo;
    cbm_decode_data_account_id_ext(encodedAcctId, &acctInfo);

    VfxU32 acctId;
    acctId = acctInfo.account[0].account_id;

    #ifdef __MMI_CBM_ALWAYS_ASK__
    VfxBool isAlwaysAsk;
    isAlwaysAsk = (VfxBool)acctInfo.account[0].is_always_ask;
    #endif

    #ifdef __MMI_CBM_ALWAYS_ASK__
    if (isAlwaysAsk)
    {
        return VFX_TRUE;
    }
    #endif
    if (CBM_DEFAULT_ACCT_ID == acctId)
    {
        return VFX_TRUE;        
    }
    if (CBM_WIFI_ACCT_ID == acctId)
    {
    #ifdef __MMI_WLAN_FEATURES__        
        return VFX_TRUE;
    #else
        return VFX_FALSE;
    #endif
    }

    VfxU32 i;
    VfxU32 acctNum;
    VappDtcntDispItem* dispItem;
    acctNum = VappDtcntDispItemList::getAcctNum();
    
    for (i = 0; i < acctNum; i++)
    {
        dispItem = VappDtcntDispItemList::getAccountItem(i);
        if (dispItem->getProfileId() == acctId)
        {
            return VFX_TRUE;
        }
    }
    return VFX_FALSE; 
}


void VappDtcntAcctValidity::syncInvalidInfowithSrv()
{
    srv_dtcnt_prof_app_info_struct appInvalidInfo;
    memset(&appInvalidInfo, 0, sizeof(srv_dtcnt_prof_app_info_struct));
    srv_dtcnt_store_update_acc_apinfo(&appInvalidInfo); 
}

/***************************************************************************** 
* Class VappDtcntSimAvailableInfo
*****************************************************************************/

VfxU32 VappDtcntSimAvailableInfo::s_availableSimNum = 0;
VfxU32 VappDtcntSimAvailableInfo::s_availableSimIndex[MMI_SIM_TOTAL] = {0};

void VappDtcntSimAvailableInfo::resetAvailableSim()
{
    VfxU32 i;
    mmi_sim_enum simId;
    s_availableSimNum = 0;
    memset(s_availableSimIndex, 0, sizeof(s_availableSimIndex));
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        simId = mmi_frm_index_to_sim(i);
        if (srv_sim_ctrl_is_available(simId))
        {
            s_availableSimIndex[s_availableSimNum++] = i;
        }
    }
}


mmi_sim_enum VappDtcntSimAvailableInfo::getAvailableSimEnum(U32 slot)
{
    return mmi_frm_index_to_sim(s_availableSimIndex[slot]);
}

#endif
/*******************************************************************************
* Export API 
*******************************************************************************/
// mmi_dtcnt_get_full_account_name
extern "C" MMI_BOOL vapp_dtcnt_get_full_account_name(U32 acctId, WCHAR *dest, U8 len, VappDtcntGetAcctNameTypeEnum type)
{
#ifdef __TCPIP__
    return (MMI_BOOL)VappDtcntDispItemList::getFullAccountName((VfxU32)acctId, (VfxWChar*)dest, (VfxU8)len, type);
#else
    return MMI_FALSE;
#endif
}

void vapp_dtcnt_set_titlebar(VfxResId title_res_id, VfxPage * page)
{
    VcpTitleBar *m_topBar;
    VFX_OBJ_CREATE(m_topBar, VcpTitleBar, page);	
    m_topBar->setTitle(title_res_id);
    page->setTopBar(m_topBar);
}

void vapp_dtcnt_set_titlebar(const VfxWString &titleStr, VfxPage *page)
{
    VcpTitleBar *m_topBar;
    VFX_OBJ_CREATE(m_topBar, VcpTitleBar, page);	
    m_topBar->setTitle(titleStr);
    page->setTopBar(m_topBar);
}

void setListMenuFormat(VcpListMenu *listmenu, VcpListMenuCellStyleEnum cellStyle,VcpListMenuModeEnum menuMode, VcpListMenuControlModeEnum ctrlMode)
{
    listmenu->setCellStyle(cellStyle);
    listmenu->setMenuMode(menuMode, VFX_FALSE);
    listmenu->setMenuControlMode(ctrlMode);
    listmenu->setAlignParent(
	VFX_FRAME_ALIGNER_MODE_SIDE,
	VFX_FRAME_ALIGNER_MODE_SIDE,
	VFX_FRAME_ALIGNER_MODE_SIDE,
	VFX_FRAME_ALIGNER_MODE_SIDE);  

}

extern "C" MMI_BOOL vapp_dtcnt_get_apn_list_ids(U32 *ids, U32 *num_ids, srv_dtcnt_sim_type_enum sim_type)
{
#ifdef __TCPIP__
    return (MMI_BOOL)VappDtcntDispItemList::getApnlist(ids, num_ids, sim_type);
#else
    return MMI_FALSE;
#endif
}


// mmi_dtcnt_acct_is_valid
extern "C" VappDtcntAcctValidTypeEnum vapp_dtcnt_acct_is_valid(U32 encodedAcctId, MMI_BOOL bearerFallback)
{
#ifdef __TCPIP__
    VfxBool fallback = (bearerFallback == MMI_TRUE ? VFX_TRUE : VFX_FALSE);
    return VappDtcntAcctValidity::isAcctValid((VfxU32)encodedAcctId, fallback);
#else
    return DTCNT_ACCT_VALID_NONE;
#endif
}


// mmi_dtcnt_ready_check
extern "C" MMI_BOOL vapp_dtcnt_ready_check(FuncPtr readyCallback, MMI_BOOL withScrLock)
{
#ifdef __TCPIP__
    VfxBool scrLock = (withScrLock == MMI_TRUE ? VFX_TRUE : VFX_FALSE);
    return (MMI_BOOL)VappDtcntReadyCheck::dtcntReadyCheck(readyCallback, scrLock);
#else
    return MMI_FALSE;
#endif
}


// mmi_dtcnt_subscribe_account
extern "C" MMI_BOOL vapp_dtcnt_subscribe_account(U32 acctOld, U32 acctNew, U16 appStrId, U16 appIconId)
{
#ifdef __TCPIP__
    return MMI_TRUE;
#else
    return MMI_FALSE;
#endif

}


// mmi_dtcnt_get_invalid_name_str_id
VfxU16 vapp_dtcnt_get_invalid_name_str_id()
{
#ifdef __TCPIP__
    return STR_ID_VAPP_DTCNT_NAME_INVALID;
#else   
    return 0;
#endif
    
}


// mmi_dtcnt_get_default_name_str_id
VfxU16 vapp_dtcnt_get_default_name_str_id()
{
#ifdef __TCPIP__
    return STR_GLOBAL_AUTOMATIC;
#else
    return 0;
#endif
}

