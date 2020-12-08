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
 *  vapp_dtcnt_wlan_core.h
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

#ifndef __VAPP_DTCNT_WLAN_CORE_H__
#define __VAPP_DTCNT_WLAN_CORE_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
extern "C"
{
    #include "kal_general_types.h"
    #include "app_url.h"
    #include "app_str.h"
    #include "Conversions.h"
    #include "DtcntSrvGprot.h"
//  #include "CertManMMIGprots.h"
    #include "ModeSwitchSrvGProt.h"
    #include "Wgui_categories_util.h"
    #include "TetheringSrvGprot.h"
    #include "GpioSrvGprot.h"
    #include "custom_wlan_ui_config.h"
}
#include "vapp_certman_gprot.h"
#include "mmi_rp_srv_status_icons_def.h"
#include "GlobalResDef.h"
#include "vcui_dtcnt_wlan_gprot.h"
#include "vapp_dtcnt_wlan_utils.h"
//#include "vapp_setting_framework_gprot.h"
#include "vapp_nmgr_gprot.h"
#include "mmi_rp_vapp_setting_def.h" /* EVT_ID_VAPP_LANGUAGE_CHANGED */

#ifdef __MMI_OP01_WIFI__
#include "vapp_dtcnt_wlan_cmcc_auth_ui.h"
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define BIT(n)              ( (kal_uint32)1 << (n) )
#define WLAN_SAVED_AP_LIST_NUM_MAX   SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM
#define WLAN_AP_LIST_NUM_MAX         SRV_DTCNT_WLAN_MAX_AP_LIST_NUM + WLAN_SAVED_AP_LIST_NUM_MAX
#ifdef __MMI_OP01_WIFI__
#define WLAN_PROXY_EXCLUSIVE_NUM_MAX SRV_DTCNT_MAX_WLAN_PROXY_EXCLUSIVE_IP_ADDR_NUM
#endif
#define MAC_ADDR_LEN_MAX            6
#define NETWORK_TYPE_ARRAY_MAX          2

#ifdef  __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__

#ifndef  WIFI_AUTH_PSK_ONLY
#define SECURITY_INFRA_AUTH_MODE_MAX    9//11//7
#else
#define SECURITY_INFRA_AUTH_MODE_MAX    6//7//5
#endif

#else

#ifndef  WIFI_AUTH_PSK_ONLY
#define SECURITY_INFRA_AUTH_MODE_MAX    7//9//5
#else
#define SECURITY_INFRA_AUTH_MODE_MAX    4//5//3
#endif

#endif  /* __MMI_HIDE_WAPI__ */
#else

#ifndef  WIFI_AUTH_PSK_ONLY
#define SECURITY_INFRA_AUTH_MODE_MAX    7//9//5
#else
#define SECURITY_INFRA_AUTH_MODE_MAX    4//5//3
#endif

#endif  /* __WAPI_SUPPORT__ */

#define SECURITY_ADHOC_AUTH_MODE_MAX    3
#define ENCRYPTION_MODE_ARRAY_MAX       1
/* WEP KEY SETTINGS */
#define WEP_KEY_INDEX_ARRAY_MAX         4
#define WEP_KEY_ENCRYPT_ARRAY_MAX       2
#define WEP_KEY_FORMAT_ARRAY_MAX        2
#define WAI_KEY_FORMAT_ARRAY_MAX        2
#define WEP_KEY_LENGTH_64BITS_HEX       10
#define WEP_KEY_LENGTH_64BITS_ASCII     5
#define WEP_KEY_LENGTH_128BITS_HEX      26
#define WEP_KEY_LENGTH_128BITS_ASCII    13
#define PASSPHRASE_KEY_LEN_MIN          8

#define AUTO_POWER_ON
/* WPA, WAPI Cipher type */
#define WPA_CIPHER_NONE             BIT(0)
#define WPA_CIPHER_WEP40            BIT(1)
#define WPA_CIPHER_WEP104           BIT(2)
#define WPA_CIPHER_TKIP             BIT(3)
#define WPA_CIPHER_CCMP             BIT(4)
#define WAPI_CIPHER_SMS4	        BIT(5)

/* WPA authentication algorithm */
#define WPA_AUTH_ALG_OPEN           BIT(0)
#define WPA_AUTH_ALG_SHARED         BIT(1)
#define WPA_AUTH_ALG_LEAP           BIT(2)

/* WPA protocol type */
#define WPA_PROTO_WPA               BIT(0)
#define WPA_PROTO_RSN               BIT(1)
#define WPA_PROTO_WAPI              BIT(2)

/* TCP/IP address */
#define IP_ADDRESS_PART_LEN_MAX         4

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    WLAN_AP_PROPERTY_NETWORK_TYPE,
    WLAN_AP_PROPERTY_AUTH_MODE,
    WLAN_AP_PROPERTY_ENCRYPTION_MODE,
    WLAN_AP_PROPERTY_WEP_KEY_INDEX,
    WLAN_AP_PROPERTY_WEP_KEY_ENCRYPT,
    WLAN_AP_PROPERTY_WEP_KEY_FORMAT,
    WLAN_AP_PROPERTY_WAI_KEY_FORMAT,
    WLAN_AP_PROPERTY_TOTAL
} VAPP_WLAN_AP_PROPERTY_TYPE_ENUM;


typedef enum
{
    WLAN_AP_EAP_TYPE_PAGE_ONE,
    WLAN_AP_EAP_TYPE_PAGE_TWO,
    WLAN_AP_EAP_TYPE_PAGE_THREE,
    WLAN_AP_EAP_TYPE_PAGE_TOTAL
} VAPP_WLAN_EAP_TYPE_PAGE_ENUM;

/***************************************************************************** 
 * Class Declaration
 *****************************************************************************/
class VappAPListEntry;
class VappApList;
#ifdef __MMI_OP01_WIFI__
class VappWlanCMCCMgr;
#endif
class VappWlanRepository;
class VappWlanSentry;
class VappWlanToolbox;

/***************************************************************************** 
 * Class VappAPListEntry
 *****************************************************************************/
/*
 * The entry of VappAPListEntry. Use VappAPListEntry::get to get the object pointer.
 * And VappAPListEntry::getPrev and VappAPListEntry::getNext can access the 
 * previous and next enrty of object list.
 *
 * SEE ALSO: VappAPList
 */
class VappAPListEntry : public VfxBase
{
// Method    
public:
    // Return the pointer to profile.
    // RETURNS: Pointer to the profile.
    VappWlanBaseInfo *get()
    {
        return &m_ap;
    }
    
    // Return the constant pointer to profile.
    // RETURNS: Constant pointer to the profile.
    const VappWlanBaseInfo *get() const
    {
        return &m_ap;
    }
    

    // Check whether the object of the entry is valid.
    //
    // RETURNS: Return VFX_TRUE if the object is valid, 
    //  otherwise return VFX_FALSE.
    VfxBool isValid() const
    {
        return m_ap.isValid();
    }


    // Get the prevous entry
    //
    // RETURNS: Pointer to the previous entry.
    VappAPListEntry*  getPrev() const
    {
        return m_prev;
    }
    
    // Get the next entry
    //
    // RETURNS: Pointer to the next entry.
    VappAPListEntry*  getNext() const
    {
        return m_next;
    }

    // Get the prevous entry contains a valid profile
    //
    // RETURNS: Pointer to the previous profile.
    VappAPListEntry*  getValidPrev() const;
    
    // Get the next entry contains a valid profile
    //
    // RETURNS: Pointer to the next entry.
    VappAPListEntry*  getValidNext() const;
        
private:    
    VappWlanBaseInfo  m_ap;    
    VappAPListEntry     *m_prev;
    VappAPListEntry     *m_next;

    // Internal Used. Construct with specified object. It can only be created in VappApList.
    VappAPListEntry(
        VappWlanBaseInfo *profile      // [IN] profile to be inserted into ap list.
    ) : 
        m_prev(NULL), m_next(NULL)
    {
        memcpy(&m_ap, profile, sizeof(VappWlanBaseInfo));
    }
        
    friend class VappApList;
};

/***************************************************************************** 
 * Class VappApList
 *****************************************************************************/

class VappApList : public VfxBase
{
// Constructor / Destructor   
public:
    // Default constructor
    VappApList() : m_head(NULL), m_tail(NULL)
    {
    }
        
    // Copy constructor
    /* 
    VappApList(
        const VappApList &other     // [IN] The other ap list to be copied
    ) : 
        m_head(NULL), m_tail(NULL)
    {
        assignWith(other);
    } 
    */
    
    // Destructor
    ~VappApList()
    {
        clear();
    }

// Method    
public:
    // Return the first entry
    //
    // RETURNS: The first entry. Return NULL if the list is emptry.
    VappAPListEntry *getHead() const
    {
        return m_head;
    }
    
    // Return the last entry
    //
    // RETURNS: The last entry. Return NULL if the list is emptry.
    VappAPListEntry *getTail() const
    {
        return m_tail;
    }


    // Return the first entry contains a valid profile.
    //
    // RETURNS: The first entry contains a valid profile. Return NULL if
    //  there is no valid profile.
    VappAPListEntry *getValidHead() const;
    
    // Return the last entry contains a valid profile.
    //
    // RETURNS: The last entry contains a valid profile. Return NULL if
    //  there is no valid profile.
    VappAPListEntry *getValidTail() const;


    // Check whether the ap list is empty.
    //
    // RETURNS: Return VFX_TRUE if the 
    VfxBool isEmpty() const
    {
        return m_head == NULL;
    }

    // Caculate the number of entries of the ap list.
    //
    // RETURNS: The number of entries.
    //
    // SEE ALSO: getEntryCount
    VfxU32 getEntryCount() const;

    // Caculate the number of entries contain a valid profile.
    //
    // RETURNS: The number of entries.
    //
    // SEE ALSO: getEntryCount
    VfxU32 getValidCount() const;

    // Get a valid profile at specific position.
    //
    // RETURNS: The entry at specific position.
    VappAPListEntry* getPos(VfxU8 index) const;

    // Get a valid profile.
    //
    // RETURNS: The entry at specific value.
    VappAPListEntry* getEntry(VappWlanBaseInfo *) const;

    VappAPListEntry* findOne(VfxU32 profileId);

    // Search one AP according to SSID and BSSID
    VappAPListEntry* search(const VfxU8* bssid, const VfxU8* ssid, VfxU8 ssidLen);

    // Return the object pointer of the first entry.
    //
    // RETURNS: The object pointer of the first entry. Return NULL if 
    //  the object list is emptry, or the object is closed.
    VappWlanBaseInfo *getFirst() const
    {
        return m_head->get();
    }
    
    // Return the object pointer of the last entry.
    //
    // RETURNS: The object pointer of the last entry. Return NULL if 
    //  the object list is emptry, or the object is closed.
    VappWlanBaseInfo *getLast() const
    {
        return m_tail->get();
    }

    // Return the object list whether contains the given object
    //
    // RETURNS: Return VFX_TRUE if the object list contains the given object. 
    //  Otherwise, return VFX_FALSE.
    VfxBool contains(
        VappWlanBaseInfo *obj              // [IN] The object to be test
    ) const;

    // Append an object to the tail of the list.
    //
    // RETURNS: The new entry appended
    VappAPListEntry *append(
        VappWlanBaseInfo *obj              // [IN] The object to be append.
    );

    // Append an object to the head of the list.
    //
    // RETURNS: The new entry appended
    VappAPListEntry *prepend(
        VappWlanBaseInfo *obj              // [IN] The object to be append.
    );

    // Insert an object after a given entry position.
    //
    // RETURNS: The new entry inserted
    VappAPListEntry *insertAt(VfxU8 index, VappWlanBaseInfo *obj);

    // Insert an object after a given entry position.
    //
    // RETURNS: The new entry inserted
    VappAPListEntry *insertAfter(
        VappAPListEntry *entry,           // [IN] The entry position to be inserted
        VappWlanBaseInfo *obj          // [IN] The object to be inserted
    );

    VappAPListEntry* createEntry(
        VappWlanBaseInfo *obj       // [IN] The object to be inserted
    );

    // Remove the entry of the given entry position.
    //
    // NOTE: Given entry will be deleted and do not access any more.
    void removePos(
        VappAPListEntry *entry      // [IN] The entry poisiton to be removed
    );

    // Search the first entry pointer to the given object and remove it.
    //
    // RETURNS: Return VFX_TRUE if remove an entry. Otherwise, return VFX_FALSE.
    VfxBool removeOne(
        VappWlanBaseInfo *obj    // [IN] The object to be remove from the object list
    );

    // Search the first entry pointer to the given object and remove it.
    //
    // RETURNS: Return VFX_TRUE if remove an entry. Otherwise, return VFX_FALSE.
    VfxBool removeOne(
        VfxU32 profileId            // [IN] The id of profile 
    );

        
    // Search the all entryies pointer to the given object and remove them.
    //
    // RETURNS: Return the number of entry has been removed.
    VfxU32 removeAll(
        VappWlanBaseInfo *obj    // [IN] The object to be remove from the object list
    );

    // Search the all entryies pointer to invalidate object and remove them.
    void removeAllInvalidate();
    
    // Clear all entris of the object list.
    void clear();

// Implementation
private:
    VappAPListEntry *m_head;
    VappAPListEntry *m_tail;

    // void assignWith(const VfxObjList &other);
};

#ifdef __MMI_OP01_WIFI__
class VappWlanCMCCMgr : public VfxObject
{
    VFX_DECLARE_CLASS(VappWlanCMCCMgr);
// Constructor / Destructor
public:
    VappWlanCMCCMgr();
    
// Override
public:
    virtual void onInit ();
    virtual void onDeinit ();
    
// Implement
public:
    static void responseCMCCLogoutIndEvent(mmi_event_struct* param);
    //static void responseAuthRetEvent(mmi_event_struct* param);
    static void responseAddrChangeCnfEvent(mmi_event_struct* param);   

    static void entryCMCCPortalCertRun(void);   
    static void entryCMCCPortalProc(void);    
    static void entryCMCCPortalCertLoginStart(void);
    static void entryCMCCProtalCertAbort(void);    
    static void entryCMCCActionAfterLogout(VAPP_WLAN_CMCC_LOGOUT_ACTION action) ;     
    static MMI_BOOL entryCMCCShowPortalResult(mmi_scenario_id scen_id, void *arg);
    static void entryCMCCPortalCertLogoutStart();
    static void entryCMCCDisconnectProcCallback(vapp_cmcc_wlan_auth_ret_enum ret);     
    static void entryCMCCLogoutIndCallback(vapp_cmcc_wlan_auth_ret_enum ret);
    static void entryCMCCPortalCertCallback(vapp_cmcc_wlan_auth_ret_enum ret);
    static void entryCMCCSendDiscReqAfterLoginFailed();
    static void entryCMCCLogoutIndInformDtcntSrv(srv_dtcnt_wlan_logout_rsp_enum rsp);
    static VfxBool isAllowToShowScrn(void);
    static void entryCMCCDeinitProc ();

// Variables
public:
	static srv_dtcnt_wlan_logout_cb_func_ptr m_callback;
};
#endif

class VappWlanRepository : public Subject
{
// Declaration
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappWlanRepository);

// Constructor / Destructor
private:
    VappWlanRepository();
    virtual ~VappWlanRepository();

// Method
public:

    mmi_id getWlanCuiId();
    void setWlanCuiId(const mmi_id gid);

    void setWlanSettingCuiId(const mmi_id gid);    
    mmi_id getWlanSettingCuiId() const;

    void initializeRepository(VfxObject* obj);
    void syncWithDtcntStorage();

    VfxU32 getScanJobId() const;
    void setScanJobId(const VfxU32 jobId);

    VfxBool getIsScanAbort() const;
    void setIsScanAbort(const VfxBool isScanAbort);

    VAPP_WLAN_CONN_PROC_TYPE getConnProcType() const;
    void setConnProcType(VAPP_WLAN_CONN_PROC_TYPE procType);

    supc_abm_cause_enum getConnFailType() const;
    void setConnFailType(supc_abm_cause_enum failType);    

    vcui_wlan_auto_conn_cb_func_ptr getAutoConnCb() const;
    void setAutoConnCb(vcui_wlan_auto_conn_cb_func_ptr autoConnCb);

    VfxBool getIsInsert() const;
    void setIsInsert(const VfxBool isInsert);

    srv_dtcnt_wlan_power_mode_enum getPowerSavingMode() const;
    void setPowerSavingMode(srv_dtcnt_wlan_power_mode_enum powerSavingMode);
    
    const VfxU8* getMacAddr() const;
    void setMacAddr(const VfxU8* macAddr);

    VfxWString getMacInfoStr() const;
    void setMacInfoStr(const VfxWString& macInfo);

    srv_dtcnt_wlan_scan_result_enum getScanRresult();
    void setScanResult(srv_dtcnt_wlan_scan_result_enum result);
    
    // saved ap list
    VfxU8 getSavedApNum() const;
    
    // search ap list    
    VfxU8 getScanApListNum() const;
    void setScanApListNum(VfxU8 apListNum);
    void updateScanApList(const supc_abm_bss_info_struct** apList);
 
    // ap list    
    void updateApList();

    VfxBool getIsConnectAbort() const;
    void setIsConnectAbort(const VfxBool isConnectAbort);

    VfxBool getIsWLANByOffTethering() const;
    void setIsWLANByOffTethering(const VfxBool check);

    VappWlanBaseInfo* getConnectedAP();
    void setConnectedAP(VappWlanBaseInfo* );
    void resetConnectedAP();

    VappWlanProfile* getApToBeActivated();
    void setApToBeActivated(VappWlanProfile*);

    srv_dtcnt_wlan_status_enum getCurWlanStatus() const;
    void setCurWlanStatus();

    VcpFormItemLauncherCell* getSettingCellInstance() ;
    void setSettingCellInstance(VcpFormItemLauncherCell* cell);

    VcpFormItemSwitchCell* getSettingSwitchCellInstance() ;
    void setSettingSwitchCellInstance(VcpFormItemSwitchCell* cell);

    VappAPListEntry* findProfileWithLowestPriority(srv_dtcnt_wlan_network_type_enum networkType);
    void editSearchProfile(VappWlanProfile*, VappWlanProfile* );
    void editSavedProfile(VappWlanProfile* );

    VfxU32 getRootCAId();
    void setRootCAId(VfxU32 rootCaId);
    
    VfxU32 getUserCAId();
    void setUserCAId(VfxU32 userCaId);

    VfxU32 getWapiAseId();
    void setWapiAseId(VfxU32);
    
    VfxU32 getWapiClientId();
    void setWapiClientId(VfxU32);

    VfxBool getIsDeleteApProc() const;
    void setIsDeleteApProc(VfxBool isDelete);

    VfxBool getIsCertListShow() const;
    void setIsCertListShow(VfxBool isShow);

    VAPP_WLAN_WPS_CONN_TYPE getWPSConnType() const;
    void setWPSConnType(VAPP_WLAN_WPS_CONN_TYPE);

    VfxS32 getConnDuration() const;
    void setConnDuration(VfxS32 duration);

    VfxMsec getCurrentSystemTime() const;
    void setCurrentSystemTime(VfxMsec curTime);

    VfxU32 getPinCode() const;
    void setPinCode(VfxU32 pinCode);

    void setWpsInfo(VfxU8 action, VfxU32 value);
    
    void setWpsStatus(VAPP_WLAN_WPS_STATUS status);   
    VAPP_WLAN_WPS_STATUS getWpsStatus();

#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    supc_connection_type_enum getCnfConnType() ; //conn_cnf's connect type
    void setCnfConnType( supc_connection_type_enum connType);
    supc_connection_type_enum getAPConnTypeSequence(VfxS32 number);
    void setAPConnTypeSequence(supc_connection_type_enum connType);
    void updateAPConnTypeSequence();
    VfxU8 getAPConnNum();    
   
    void setWlanUiFlow(VAPP_WLAN_UI_FLOW_ENUM flow);
    VAPP_WLAN_UI_FLOW_ENUM getWlanUiFlow(void);

    void setIsScanResultUseful(VfxBool check)  ; 
    VfxBool getIsScanResultUseful() const;  

    VAPP_WLAN_ADD_AP_TYPE getAddApType() const;
    void setAddApType(VAPP_WLAN_ADD_AP_TYPE apTpye);

    VfxBool getIsEditAddressProc() const;
    void setIsEditAddressProc(VfxBool isDelete);   

    void setProxyExclusiveListPtr(srv_dtcnt_wlan_proxy_exclusive_ip_addr_qry_struct *ptr) ;
    srv_dtcnt_wlan_proxy_exclusive_ip_addr_qry_struct* getProxyExclusiveListPtr() const;
    
    void updateSavedApMatchType();

    // useful ap list
    VfxU8 getUsefulApNum() const; 
    VappWlanBaseInfo* const * getUsefulApArray() const  ; 

    // block ap list    
    VfxU8 getBlockedApNum() const; 
    VappWlanBaseInfo* const * getBlockedApArray() const  ; 

    // remember ap list
    VfxU8 getRememberedApNum() const; 
    VappWlanBaseInfo* const * getRememberedApArray() const;
    
    void setActionAfterLogout(VAPP_WLAN_CMCC_LOGOUT_ACTION action);
    VAPP_WLAN_CMCC_LOGOUT_ACTION getActionAfterLogout(void);

    VfxContext* getContext();

// Overridable
public:
    virtual void registerObserver(Observer* o);
    virtual void removeObserver(Observer* o);
    virtual void notifyObservers(SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg);
    virtual vrt_allocator_handle getAllocator()
    {
        return m_context->getAllocator();
    }

// Overridable
protected:
	virtual void onInit();
    
// Variable
private:

    /* system memory pool context */
    VfxContext         *m_context;
    /* wlan cui id, when WLAN CUI is off, id is 0*/
    mmi_id              m_wlanCuiId;
    /* wlan setting cui id, when WLAN setting CUI is off, id is 0 */
    mmi_id              m_wlanSettingCuiId;    
    /* observer list */
    VfxObjList          m_observerList;
    /* saved ap list */
    VappApList          m_savedApList;
    /* saved ap list num */
    VfxU8               m_savedApListNum;
    /* the count of ap whose network type is infrastructure */
    VfxU8              m_infraApNum;
    /* the count of ap whose network type is ad-hoc */
    VfxU8              m_adhocApNum;

    /* current connected ap */
    VappWlanBaseInfo                m_connectBaseInfo;
    /* current wlan status */
    srv_dtcnt_wlan_status_enum      m_curWlanStatus;
    /* add or edit */
    VfxBool                         m_isInsertAp;
    
//  init event structure
    VfxU8               m_macAddr[MAC_ADDR_LEN_MAX];
    VfxWString          m_macInfoStr;

//  scan event structure
    /* scan result enum */
    srv_dtcnt_wlan_scan_result_enum m_scanResult;                                   
    /* total num of searched ap list */
    VfxU8                           m_scanApListNum;                               
    /* scan_job_id, 0xFFFFFF means scan result broadcasting */    
    VfxU32                          m_scanJobId;   
    /* scan ap list */
    VappApList                      m_scanApList;
    /* scan abort action flag */
    VfxBool                         m_isScanAbort;
    /* conn. proc type */
    VAPP_WLAN_CONN_PROC_TYPE        m_connProcType;

//  connect event structure
    VappWlanProfile                 m_apToBeActivated;    
    /* connect abort action flag */
    VfxBool                         m_isConnectAbort;

//  settings framework for Wi-Fi
    VcpFormItemSwitchCell              *m_settingSwitchCell;
    VcpFormItemLauncherCell            *m_settingCell;

//  Root & User Cert.
    VfxU32 m_rootCaId;
    VfxU32 m_userCaId;

//  ASE & Client Cert.
    VfxU32 m_wapiAseId;
    VfxU32 m_wapiClientId;

//  Delete AP
    VfxBool                             m_isDeleteAp;

//  Cert. list
    VfxBool                             m_isCertListShow;

//  WPS 
    VAPP_WLAN_WPS_CONN_TYPE             m_connType;
    VfxS32                              m_connDuration;
    VfxMsec                             m_currSystemTime;
    VfxU32                              m_pinCode;
    VAPP_WLAN_WPS_STATUS                m_wpsStatus;
    
//  Power saving mode
    srv_dtcnt_wlan_power_mode_enum      m_powerSavingMode;

//  turn on Wlan by closing tethering
    VfxBool                             m_IsWLANByOffTethering;

//  Connect type
    supc_connection_type_enum           m_connTypeSequence[10];
    VfxU8                               m_connNum;
    supc_connection_type_enum           m_cnfConnType;
    
//  Auto conn. callback function    
    vcui_wlan_auto_conn_cb_func_ptr     m_autoConnCb;

//  conn. fail type
    supc_abm_cause_enum                 m_connFailType;                

//  useful Ap in Scan result   
    VfxBool                             m_isScanResultUseful;

//  add AP type
    VAPP_WLAN_ADD_AP_TYPE               m_addApType;

//  UI status machine
    VAPP_WLAN_UI_FLOW_ENUM              m_uiFlow;
 
//  Edit Address
    VfxBool                             m_isEditAddress;

   /* useful ap list num */
    VfxU8                   m_usefulApListNum;   
    /* blocked ap list num */
    VfxU8                   m_blockedApListNum;
    /* remembered ap list num */
    VfxU8                   m_rememberedApListNum;	
    /* useful ap list array */
    VappWlanBaseInfo*       m_usefulApPointArray[WLAN_AP_LIST_NUM_MAX];       
    /* blocked ap list array */
    VappWlanBaseInfo*       m_blockedApPointArray[WLAN_SAVED_AP_LIST_NUM_MAX];  
    /* remembered ap list array */
    VappWlanBaseInfo*       m_rememberedApPointArray[WLAN_SAVED_AP_LIST_NUM_MAX];  
   
    VAPP_WLAN_CMCC_LOGOUT_ACTION        m_actionAfterLogout;
    
// signal Variable
public:
    // judge whether wifi can open in flight mode
    VfxSignal1<VfxBool>  m_signalOpenWLANInFlightMode;  

    // judge whether wifi tethering is turned off or not  
    VfxSignal1<VfxBool>  m_signalStopTethering;

    // inform WLAN the result what about turned off tethering.
    VfxSignal3<
        srv_tethering_type_enum, 
        MMI_BOOL, 
        void*>           m_signalInformWLAN;

// Implementation
public:
    VappWlanBaseInfo* getInApListBySrvInfo(srv_dtcnt_prof_wlan_struct *srvInfo);
    void initProfileByBssInfo(const supc_abm_bss_info_struct*, VappWlanBaseInfo*);
    void initSrvProfileByAppProfile(VfxBool isConn, const VappWlanProfile*, srv_dtcnt_prof_wlan_struct* );
    VfxBool checkIsApExisted(const VappWlanProfile* appProfile);
    void destroyApList(VappApList* apList);
    void destroyObjectList(VfxObjList* objList);
    void resetSavedApList();
    VfxBool findInApList(const VappWlanBaseInfo*);
    VappWlanBaseInfo* getInApList(const VappWlanBaseInfo* ap);
    
    srv_dtcnt_result_enum saveProfileInDtcntStore(VfxU32 , VappWlanProfile* );
    srv_dtcnt_result_enum updateProfileInDtcntStoreByBaseInfo(VfxU32 fields, VappWlanBaseInfo *baseInfo);
    srv_dtcnt_result_enum updateProfileInDtcntStore(VfxU32 fields, VappWlanProfile *appProfile);
    srv_dtcnt_result_enum removeProfileFromDtcntStore(VappWlanBaseInfo* profile);
    
    void afterConnectedSuccess(srv_dtcnt_wlan_conn_res_struct* connRes);
    void afterConnectedFailed(VfxU32 profileId);
    void afterAbortConnect();
#ifdef __WPS_SUPPORT__    
    void afterConnectedSuccessByWps(srv_dtcnt_wlan_conn_res_struct* connRes);
    void afterConnectedFailedByWps(srv_dtcnt_wlan_conn_res_struct* connRes);
    void afterReceiveWPSInfoEvt(srv_dtcnt_wlan_wps_info_evt_struct* wpsInfo);
#endif
    void afterDisconnected();
    void afterDeinit();
    VfxBool afterReceiveConnectInd(srv_dtcnt_wlan_conn_res_struct* connRes);
    void afterUpdateIpAddr(srv_dtcnt_wlan_ipaddr_update_struct* ipAddrUpdate);
    void afterChangeIpAddr(srv_dtcnt_wlan_ipaddr_change_qry_evt_struct* ipAddrChangeEvt);
    void afterInsertApIntoSavedList(VappWlanProfile* profile);
    void afterForgetAp(VappWlanBaseInfo* profile);
    void afterEditAp(VappWlanProfile* originalProfile, VappWlanProfile* profile);
    void afterRemoveApFromList(VfxU8 index, VappWlanBaseInfo* const * apList);
    void afterChangePriority(VappWlanBaseInfo **m_tempSavedApList, VfxU8* priorityList);
    void afterRefreshConnectedAP(srv_dtcnt_wlan_curr_ap_info_struct*);
    void updateApPriorityInDbSrv(VfxBool isStore, VfxU8 replacedPriority, VappWlanProfile* newOne);
    void insertApIntoSavedList(VfxBool isStore, VappWlanProfile* profile);
    void insertApIntoSavedListAfterConnected(VfxBool isStore, VappWlanProfile* profile);
    void updatePriorityAfterConnected(VfxBool isStore, VfxU8 replacedPriority, VappWlanBaseInfo *profile);
    void updateMacAddress();

    void autoConnStart (vcui_wlan_auto_conn_cb_func_ptr cb);
    void autoConnProc (VfxBool isValid, SUBSCRIBE_SRV_WLAN_EVENT_ENUM msg);
    void autoConnRun ();
    void autoConnInform (VCUI_WLAN_AUTO_CONN_ACTION_ENUM action);

#ifndef __MTK_TARGET__
    void ModisIpaddrUpdate ();
    void ModisIpaddrChange ();
#endif
};

class VappWlanSentry : public VfxBase
{
// Declaration

// Constructor / Destructor
public:
    VappWlanSentry()
    {
        VFX_TRACE(("===VappWlanSentry constructor===\n"));
    }
    
    ~VappWlanSentry ()
    {
        VFX_TRACE(("===VappWlanSentry deconstructor===\n"));
    }

// Method

// Overridable

// Override

// Variable
   
// Implementation
public:
    // Register events from data account service
    static mmi_ret RegisterDtcntServiceEvents();
    // Deregister events from data account service
    static mmi_ret DeregisterDtcntServiceEvents();
    // Power on wifi
    static void PowerOnWifi();
    // Handle events from data account service
    // static mmi_ret HandleDtcntServiceEvents(mmi_event_struct* param);

public:
    static void SendInitRequest();
    static void SendDeinitRequest();
    static void SendScanRequest();
    static void SendAbortScanRequest();
    static void SendConnectRequest();
    static void SendAbortConnectRequest();
    static void SendDisconnectRequest();
#ifdef __CERTMAN_SUPPORT__
    static void SendSelectCACertRequest(VfxResId titleStrId);
    static void SendSelectUserCertRequest(VfxResId titleStrId);
    static void SendSelectASECertRequest(VfxResId titleStrId);
    static void SendSelectClientCertRequest(VfxResId titleStrId);
#endif

#ifdef __WPS_SUPPORT__
    static void SendWPSConnectRequest();
    static void responseWPSInfoIndEvent(mmi_event_struct* param);    
#endif

    static void responseUpdateLanguageEvent(mmi_event_struct* param);
    static void responseBearerStatusEvent(mmi_event_struct* param);    
    static void responseConnReqProfEvent(mmi_event_struct* param);    
    static void responseSleepEvent(mmi_event_struct* param);    
    static void responseInitEvent(mmi_event_struct* param);
    static void responseScanEvent(mmi_event_struct* param);
    static void responseConnectedEvent(mmi_event_struct* param);
    static void responseWPSConnectedEvent (mmi_event_struct* param);
    static void responseDisconnectedEvent(mmi_event_struct* param);
    static void responseDeinitEvent(mmi_event_struct* param);
    static void responseUpdateIpAddrEvent(mmi_event_struct* param);
    static void responseConnectIndEvent(mmi_event_struct* param);
    static void responseIpAddrConflictEvent(mmi_event_struct* param);
    static void responseIpAddrChangedEvent(mmi_event_struct* param);
    static void responseChipInvaildEvent(mmi_event_struct* param);
    static void responseRefreshApStatusEvent(mmi_event_struct* param);
#ifdef __CERTMAN_SUPPORT__
    static void responseSelectCACertRequest(void* data);
    static void responseSelectUserCertRequest(void* data);
    static void responseSelectASECertRequest(void *data);
    static void responseSelectClientCertRequest(void *data);
#endif
    static void responsePreModeSwitch(mmi_event_struct* param);
    static void responseFinishModeSwitch(mmi_event_struct* param);
    static void updateStatusIconBar(VfxU16 imageId, VfxBool isAnimate);
    static void showGlobalPopup(mmi_id gid, void* userData, VfxResId textId);
    static void globalPopupCallbackFunc(VfxId id, void *userData);
    static void setPowerSavingModeCallbackFunc(void *user_data, srv_dtcnt_wlan_req_res_enum res);
};

class VappWlanToolbox : public VfxBase
{
// Declaration

// Constructor / Destructor
public:
    VappWlanToolbox()
    {
        VFX_TRACE(("===VappWlanToolbox default constructor===\n"));
    }

    ~VappWlanToolbox()
    {
        VFX_TRACE(("===VappWlanToolbox deconstructor===\n"));
    }

// Method

// Overridable

// Override

// Variable
private:
    static srv_dtcnt_wlan_auth_mode_enum s_securityMode[SECURITY_INFRA_AUTH_MODE_MAX];
    static srv_dtcnt_wlan_encrypt_mode_enum s_encryptionMode[ENCRYPTION_MODE_ARRAY_MAX];

// Implementation
public:

    static VfxU32 getNetworkTypeNum();
    static VfxU32 getSecurityModeNum(srv_dtcnt_wlan_network_type_enum networkType);
    static VfxU32 getEncryptionTypeNum(srv_dtcnt_wlan_auth_mode_enum authMode);

    static VfxU32 getWepKeyIndexNum();
    static VfxU32 getWepKeyEncryptNum();
    static VfxU32 getWepKeyFormatNum();
    static VfxU32 getWaiPskFormatNum();
    
    static VfxWString getNetworkTypeStr(VfxU32 index);
    static VfxWString getSecurityModeStr(VfxU32 index, srv_dtcnt_wlan_network_type_enum networkType);
    static VfxWString getEncryptionModeStr(VfxU32 index, srv_dtcnt_wlan_auth_mode_enum authMode);

    static VfxWString getWepKeyIndexStr(VfxU32 index);
    static VfxWString getWepKeyEncryptStr(VfxU32 index);
    static VfxWString getWepKeyFormatStr(VfxU32 index);

    static VfxU32 getWepKeyIndex(VfxU8 wepKeyIndex);
    static VfxU32 getWepKeyEncryptIndex(srv_dtcnt_wlan_wep_key_encrypt_enum wepKeyEncrypt);
    static VfxU32 getWepKeyFormatIndex(srv_dtcnt_wlan_wep_key_format_enum wepKeyFormat);
    static VfxU32 getWaiPskFormatIndex(VfxU32 waiPskFormat);

    static VfxU8 getWepKeyInUse(VfxU32 index);
    static srv_dtcnt_wlan_wep_key_encrypt_enum getWepKeyEncrypt(VfxU32 index);
    static srv_dtcnt_wlan_wep_key_format_enum getWepKeyFormat(VfxU32 index);

    static VfxWString getWaiKeyFormatStr(VfxU32 index);
    static VfxU8 getWaiKeyFormat(VfxU32 index);

    static srv_dtcnt_wlan_network_type_enum getNetworkType(VfxU32 index);
    static srv_dtcnt_wlan_auth_mode_enum getSecurityMode(VfxU32 index);
    static srv_dtcnt_wlan_encrypt_mode_enum getEncryptionMode(VfxU32 index);

    static VfxU32 getNetworkTypeIndex(srv_dtcnt_wlan_network_type_enum networkType);
    static VfxU32 getSecurityModeIndex(srv_dtcnt_wlan_auth_mode_enum authMode);
    static VfxU32 getEncryptionModeIndex(srv_dtcnt_wlan_encrypt_mode_enum encryptionMode);
    
    static void setSecurityMode(srv_dtcnt_wlan_network_type_enum networkType);
    static void setEncryptionMode(srv_dtcnt_wlan_auth_mode_enum authMode);
    
    static void updateSecurityMode(
            srv_dtcnt_wlan_network_type_enum curNetworkType,
            srv_dtcnt_wlan_network_type_enum preNetworkType,
            srv_dtcnt_wlan_auth_mode_enum& authMode);
    static void updateEncryptionMode(
            srv_dtcnt_wlan_auth_mode_enum curAuthMode,
            srv_dtcnt_wlan_auth_mode_enum preAuthMode,
            srv_dtcnt_wlan_encrypt_mode_enum& encryptMode);
    
    static VfxBool isSameAP(const VappWlanBaseInfo* , const VappWlanBaseInfo* );   
    static void initWlanProfile(VappWlanProfile* profile);
    static void initAppProfile(VappWlanProfile* appProfile);
    static void initAppProfileBySrvProfile(VappWlanProfile* appProfile, const srv_dtcnt_prof_wlan_struct* srvProfile);
    static void initAppProfileWithDefaultEapValue(VappWlanProfile* appProfile);
    static void saveSecurityInfo(VappWlanProfile* src, VappWlanProfile* dst);
    static void cleanSecurityInfo(VappWlanProfile* profile);
    static void cloneWlanProfile(VappWlanProfile* inProfile, VappWlanProfile* outProfile);
    static void convertStrToAscii(VfxChar* outStr, VfxWString& inStr, VfxU32 length);
    static VfxBool convertHexToStr(VfxChar* outStr, VfxChar* inStr, VfxU32 length);
    static VfxBool checkHexString(const VfxU8* src, VfxU8 len);
    static VfxBool checkAsciiString(const VfxU8* src, VfxU8 length);
    static VfxBool checkWepKey(VappWlanProfile* profile);
    static VfxBool checkPriorityInSrvDb(VappWlanProfile* profile);
    static VfxBool checkAddress(VfxWChar* addrStr, VfxU8* addr, VfxBool isBlankValid, VfxBool isAllZeroValid);
    static VfxS16 checkUrlString(const VfxU8* url, VfxBool isBlankUrlValid);
    static VfxBool isUrlValid(const VfxChar* url);
    static void showInvalidPopup(const VfxWString &prompt, VfxScreen* scr);
    static void handleSegmentBtnEvent(srv_dtcnt_wlan_network_type_enum, VappWlanProfile* );
    static MMI_BOOL isTetheringInSwitching();
    static MMI_BOOL isFlightModeOn();
    static MMI_BOOL isAllowToShowScrn(void);
   
    static void initWlanRegularInfo(VappWlanBaseInfo* );
    static void initAppProfileByAppBaseInfo(VappWlanBaseInfo *, VappWlanProfile* );   
    static void getAppProfileByAppBaseInfo(VappWlanBaseInfo* , VappWlanProfile* );
    static srv_dtcnt_result_enum getSrvProfileByProfileId(srv_dtcnt_prof_wlan_struct* , VfxU32 );
    static void cloneWlanBaseInfo(VappWlanBaseInfo* , VappWlanBaseInfo* );
};

/* External interface */
#ifdef __cplusplus
extern "C" {
#endif
    extern MMI_ID vapp_dtcnt_wlan_launch(void* param, U32 param_size);
    extern VfxApp* vapp_dtcnt_wlan_find_app(void);
    extern mmi_ret HandleDtcntServiceEvents(mmi_event_struct* param);
    // WLAN setting CUI
    extern mmi_id vcui_dtcnt_wlan_setting_create(mmi_id parent_gid, void *user_data);
    extern void vcui_dtcnt_wlan_setting_run(mmi_id cui_gid);   
    extern void vcui_dtcnt_wlan_setting_close(mmi_id cui_gid);
#ifdef __cplusplus
}
#endif

#endif
