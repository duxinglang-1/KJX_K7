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
 *  vapp_dtcnt_ui.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file defines data account app display and config
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

#ifndef __VAPP_DTCNT_UI_H__
#define __VAPP_DTCNT_UI_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __TCPIP__
#include "mmi_features.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_dtcnt_def.h"
#include "vapp_dtcnt_gprot.h"
#include "vapp_dtcnt.h"
extern "C"
{
#include "DtcntSrvIprot.h"
}
#include "mmi_res_range_def.h"
#ifdef __MMI_VUI_COSMOS_CP__
#include "mmi_rp_app_cosmos_global_def.h"
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VAPP_DTCNT_DETAIL_GAP_LEFT (10)
#define VAPP_DTCNT_DETAIL_GAP_RIGHT (10)
#define VAPP_DTCNT_DETAIL_GAP_TOP (0)
#define VAPP_DTCNT_CSD_DETAIL_SIZE (1024)
#define VAPP_DTCNT_GPRS_DETAIL_SIZE (1024)
#define VAPP_DTCNT_ADVANCED_DETAIL_BASE_SIZE (1024)
#define VAPP_DTCNT_ADVANCED_DETAIL_PROXY_SIZE (512)
#define VAPP_DTCNT_ADVANCED_DETAIL_OTHERS_SIZE (512)
#ifdef __MMI_VUI_COSMOS_CP__
#define VAPP_DTCNT_DEFAULT_TEXT_FONT_COLOR  VFX_COLOR_RES(CLR_COSMOS_TEXT_LINK)
#else
#define VAPP_DTCNT_DEFAULT_TEXT_FONT_COLOR   VfxColor(255, 110, 165, 50)
#endif


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    EVT_ID_DTCNT_SETTING_CLOSE = VAPP_DTCNT + 1,
    EVT_ID_DTCNT_SETTING_END
} vapp_dtcnt_setting_enum;

// list page type for data account
enum VappDtcntListTypeEnum
{
    VAPP_DTCNT_LIST_TYPE_DISPLAY_ACCOUNT = 0, // display accounts

    VAPP_DTCNT_LIST_TYPE_CHANGE_DFFAULT,  // change default account

    VAPP_DTCNT_LIST_TYPE_DELETE_ACCOUNT,  // delete account  

    VAPP_DTCNT_LIST_TYPE_END
} ;


// toolbar id for list page
enum VappDtcntListToolbarIdEnum
{
    VAPP_DTCNT_LIST_TOOLBAR_ID_ADD = 0,             // add account

    VAPP_DTCNT_LIST_TOOLBAR_ID_TO_CHANGE_DEFAULT,   //to change default account page

    VAPP_DTCNT_LIST_TOOLBAR_ID_TO_DELETE,           // to delete account page

    VAPP_DTCNT_LIST_TOOLBAR_ID_MARK_ALL,              // mark All

    VAPP_DTCNT_LIST_TOOLBAR_ID_DELETE,              // delete account

    VAPP_DTCNT_LIST_TOOLBAR_ID_CANCEL,              // cancel delete account

    VAPP_DTCNT_LIST_TOOLBAR_ID_END
} ;


enum VappDtcntPrepareListType
{
    VAPP_DTCNT_LIST_PREPARE_TYPE_SETTING = 0,
    VAPP_DTCNT_LIST_PREPARE_TYPE_PROVISIONING,
    VAPP_DTCNT_LIST_PREPARE_TYPE_TOTAL
} ;


enum VappDtcntAddAccoutType
{
    VAPP_DTCNT_ADD_ACCOUNT_TYPE_GPRS = 0,
    VAPP_DTCNT_ADD_ACCOUNT_TYPE_CSD,
    VAPP_DTCNT_ADD_ACCOUNT_TYPE_CANCEL,
    VAPP_DTCNT_ADD_ACCOUNT_TYPE_END
} ;


enum VappDtcntAccoutSettingType
{
    VAPP_DTCNT_ACCOUNT_SETTING_TYPE_ADD = 0,
    VAPP_DTCNT_ACCOUNT_SETTING_TYPE_EDIT,
    VAPP_DTCNT_ACCOUNT_SETTING_TYPE_VIEW,
    VAPP_DTCNT_ACCOUNT_SETTING_TYPE_END
} ;

/*******************************************************************************
* Export API 
*******************************************************************************/

/***************************************************************************** 
 * Class VappDtcntDisplayItemInfo
 *****************************************************************************/

/*
 * DESCRIPTION
 *  this is an account item with account name and address.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntDisplayItemInfo : public VfxObject
{

public:
    VappDtcntDisplayItemInfo() :
            m_profileId(0),
            m_connectionType(0),
            m_simInfo(0),
            m_bearerType(0),
            m_readOnly(0),
            m_accountType(SRV_DTCNT_PROF_TYPE_USER_CONF)
        {
	    m_name[0] = L'\0';
	    m_address[0] = L'\0';
        }
     virtual ~VappDtcntDisplayItemInfo() {}

// override
public:
    virtual void onInit();
    virtual void onDeinit();    

// method
public:
    // get
    VfxU32 getProfileId()       {return m_profileId;}
    VfxU8  getConnectionType()  {return m_connectionType;}
    VfxU8  getSimInfo()         {return m_simInfo;}
    VfxU8  getBearerType()      {return m_bearerType;}
    VfxU8  getReadOnly()        {return m_readOnly;}
    srv_dtcnt_prof_acc_type_enum  getAccountType()     {return m_accountType;}
    VfxWChar *getName() {return m_name;}
    VfxWChar *getAddress() {return m_address;}

    // set
    void setProfileId(VfxU32 profileId)             {m_profileId = profileId;}
    void setConnectionType(VfxU8 connectionType)    {m_connectionType = connectionType;}
    void setSimInfo(VfxU8 simInfo)                  {m_simInfo = simInfo;}
    void setBearerType(VfxU8 bearerType)            {m_bearerType = bearerType;}
    void setReadOnly(VfxU8 readOnly)                {m_readOnly = readOnly;}
    void setAccountType(srv_dtcnt_prof_acc_type_enum accountType) {m_accountType = accountType;}
    void setName(VfxWChar *name){mmi_wcscpy((WCHAR*)m_name, (WCHAR*)name);}
    void setAddress(VfxWChar *address){mmi_wcscpy((WCHAR*)m_address, (WCHAR*)address);} 

private:
    VfxU32 m_profileId;
    VfxU8 m_connectionType;
    VfxU8 m_simInfo;
    VfxU8 m_bearerType;
    VfxU8 m_readOnly;
    srv_dtcnt_prof_acc_type_enum m_accountType;
    VfxWChar m_name[MAX_DATA_ACCOUNT_NAME_LEN + 1];
    VfxWChar m_address[MAX_DTCNT_LIST_ADDR_LEN];
} ;


/***************************************************************************** 
 * Class VappDtcntListDisplayContext
 *****************************************************************************/

/*
 * DESCRIPTION
 *  data account app display context.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntListDisplayContext : public VfxObject
{

public:
    VappDtcntListDisplayContext() : m_listItemNumber(0){};
    virtual ~VappDtcntListDisplayContext() {}
 
public:
    //get/set
    VfxU32 getListItemNumber() {return m_listItemNumber;}

    VappDtcntDisplayItemInfo *getListInfo(VfxU32 index) {return m_listInfo[index];}

    void setListItemNumber(VfxU32 listItemNumber) {m_listItemNumber = listItemNumber;}

    void setListInfo(VfxU32 index, VappDtcntDisplayItemInfo *info);

    // other
    void arrangeAcctListInfo(
        VappDtcntDisplayItemInfo **ListInfo,  // list info, use const point of m_listInfo
        VfxU32 start,                       // start index of listinfo (included)
        VfxU32 end                          // end index of listinfo (not included)            
    );
    void swapListInfo(VappDtcntDisplayItemInfo *ListInfo1, VappDtcntDisplayItemInfo *ListInfo2);

    // prepare list info for setting or replace provisioning
    void prepareListInfo(
        srv_dtcnt_sim_type_enum simType, // sim type
        VappDtcntPrepareListType type // prepare data for setting or provisioning
    );

// override
public:
    virtual void onInit();
    virtual void onDeinit();
private:
    //
    VfxS32 m_listItemNumber;
    VappDtcntDisplayItemInfo *m_listInfo[VAPP_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM];
} ;

/***************************************************************************** 
 * Class VappDtcntCommonAccountData
 *****************************************************************************/

class VappDtcntCommonAccountData : public VfxObject
{

public:
    VappDtcntCommonAccountData();
    virtual ~VappDtcntCommonAccountData(){}
// override
public:
    virtual void onInit();
    virtual void onDeinit();

public:
    //get
    VfxWChar* getDataAccountName() {return m_dataAccountName;}
    VfxWChar* getUserName() {return m_userName;}
    VfxWChar* getPassword() {return m_password;}

    VfxWChar* getHomePage() {return m_homePage;}
    VfxU8 getConnectionType() {return m_connectionType;}
    VfxWChar* getProxyAddress() {return m_proxyAddress;}
    VfxU8 getUseProxy() {return m_useProxy;}
    VfxU8 getWapPortIndex() {return m_wapPortIndex;}

    VfxU16 getProxyPort() {return m_proxyPort;}
    VfxWChar* getProxyPortStr() {return m_proxyPortStr;}
    VfxWChar* getProxyUserName() {return m_proxyUserName;}
    VfxWChar* getProxyPassword() {return m_proxyPassword;}

    VfxU8*  getDnsPrimaryIp() {return m_dnsPrimaryIp;}
    VfxU8*  getDnsSecondaryIp() {return m_dnsSecondaryIp;}
    VfxU8*  getIp() {return m_ip;}
    VfxU8*  getSubmaskIp() {return m_submaskIp;}
    //VfxU8*  getProxyIp() {return m_proxyIp;}
    VfxWChar*  getDnsPrimaryIpDisplay() {return m_dnsPrimaryIpDisplay;}
    VfxWChar*  getDnsSecondaryIpDisplay() {return m_dnsSecondaryIpDisplay;}
    VfxWChar*  getIpDisplay() {return m_ipDisplay;}
    VfxWChar*  getSubmaskIpDisplay() {return m_submaskIpDisplay;}
    //VfxWChar*  getProxyIpDisplay() {return m_proxyIpDisplay;}

    //set 
    void setDataAccountName(VfxWChar *dataAccountName){mmi_ucs2cpy((CHAR*)m_dataAccountName, (CHAR*)dataAccountName);}
    void setUserName(VfxWChar *userName) {mmi_wcscpy((WCHAR*)m_userName, (WCHAR*)userName);}
    void setPassword(VfxWChar *password) {mmi_wcscpy((WCHAR*)m_password, (WCHAR*)password);}

    void setHomePage(VfxWChar *homePage) {mmi_wcscpy((WCHAR*)m_homePage, (WCHAR*)homePage);}
    void setConnectionType(VfxU8 connectionType) {m_connectionType = connectionType;}
    void setProxyAddress(VfxWChar *proxyAddress) {mmi_wcscpy((WCHAR*)m_proxyAddress, (WCHAR*)proxyAddress);}
    void setUseProxy(VfxU8 useProxy) {m_useProxy = useProxy;}
    void setWapPortIndex(VfxU8 wapPortIndex) {m_wapPortIndex = wapPortIndex;}

    void setProxyPort(VfxU16 proxyPort) {m_proxyPort = proxyPort;}
    void setProxyPortStr(VfxWChar* proxyPortStr) {mmi_wcscpy((WCHAR*)m_proxyPortStr, (WCHAR*)proxyPortStr);}
    void setProxyUserName(VfxWChar* proxyUserName) {mmi_wcscpy((WCHAR*)m_proxyUserName, (WCHAR*)proxyUserName);}
    void setProxyPassword(VfxWChar* proxyPassword) {mmi_wcscpy((WCHAR*)m_proxyPassword, (WCHAR*)proxyPassword);}    
    void setDnsPrimaryIp(VfxU8* ip);
    void setDnsSecondaryIp(VfxU8* ip);
    void setIp(VfxU8* ip);
    void setSubmaskIp(VfxU8* ip);
    //void setProxyIp(VfxU8* ip);
    void setDnsPrimaryIpDisplay(VfxWChar* ipDisplay) {mmi_wcscpy((WCHAR*)m_dnsPrimaryIpDisplay, (WCHAR*)ipDisplay);}
    void setDnsSecondaryIpDisplay(VfxWChar* ipDisplay) {mmi_wcscpy((WCHAR*)m_dnsSecondaryIpDisplay, (WCHAR*)ipDisplay);}
    void setIpDisplay(VfxWChar* ipDisplay) {mmi_wcscpy((WCHAR*)m_ipDisplay, (WCHAR*)ipDisplay);}
    void setSubmaskIpDisplay(VfxWChar* ipDisplay) {mmi_wcscpy((WCHAR*)m_submaskIpDisplay, (WCHAR*)ipDisplay);}
    //void setProxyIpDisplay(VfxWChar* ipDisplay) {mmi_wcscpy((WCHAR*)m_proxyIpDisplay, (WCHAR*)ipDisplay);}

protected:
    VfxWChar m_dataAccountName[MAX_DATA_ACCOUNT_NAME_LEN + 1];
    VfxWChar m_userName[SRV_DTCNT_PROF_MAX_USER_LEN + 1];
    VfxWChar m_password[SRV_DTCNT_PROF_MAX_PW_LEN + 1];

    VfxWChar m_homePage[MAX_ADDRESS_NAME_LEN];
    VfxU8 m_connectionType;
    VfxU8 m_useProxy;    
    VfxU8 m_wapPortIndex; // used for wap
    VfxU8 m_reserved;
    VfxWChar m_proxyAddress[SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN+1];
    VfxU16 m_proxyPort; // used for http only
    VfxWChar m_proxyPortStr[VAPP_DTCNT_MAX_PORT_LENGTH + 1];
    VfxWChar m_proxyUserName[SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1];
    VfxWChar m_proxyPassword[SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1];

    VfxU8  m_dnsPrimaryIp[MAX_PART_IP_ADDRESS];    
    VfxU8  m_dnsSecondaryIp[MAX_PART_IP_ADDRESS];    
    VfxU8  m_ip[MAX_PART_IP_ADDRESS];    
    VfxU8  m_submaskIp[MAX_PART_IP_ADDRESS];    
    //VfxU8  m_proxyIp[MAX_PART_IP_ADDRESS];
    VfxWChar  m_dnsPrimaryIpDisplay[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN * 4]; // for read only
    VfxWChar  m_dnsSecondaryIpDisplay[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN * 4];
    VfxWChar  m_ipDisplay[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN * 4];
    VfxWChar  m_submaskIpDisplay[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN * 4];
   // VfxWChar  m_proxyIpDisplay[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN * 4];
   srv_dtcnt_sim_type_enum m_simType;
} ;


class VappDtcntGPRSAccountData : public VappDtcntCommonAccountData
{

public:
    VappDtcntGPRSAccountData() :
        m_authType(0),
        m_reserved(0)
    {
	m_APN[0] = L'\0';
    }
    virtual ~VappDtcntGPRSAccountData() {}

// override
public:
    virtual void onInit();
    virtual void onDeinit();

// method
public:
    //get
    VfxU8 getAuthType() {return m_authType;}
    VfxWChar *getAPN() {return m_APN;}
    //set
    void setAuthType(VfxU8 authType) {m_authType = authType;}
    void setAPN(VfxWChar *APN) {mmi_wcscpy((WCHAR*)m_APN, (WCHAR*)APN);}
private:
    VfxU8       m_authType;
    VfxU8       m_reserved;
    VfxWChar    m_APN[SRV_DTCNT_PROF_MAX_APN_LEN + 1];
} ;

#ifdef __TCPIP_OVER_CSD__
class VappDtcntCSDAccountData : public VappDtcntCommonAccountData
{
    VFX_DECLARE_CLASS(VappDtcntCSDAccountData);
// constructor / destructor
public:
    VappDtcntCSDAccountData() :
        m_lineType(0),
        m_speed(2)
    {
	m_dialNumber[0] = L'\0';
    }
    virtual ~VappDtcntCSDAccountData() {}

// override
public:
    virtual void onInit();
    virtual void onDeinit();

// method
public:
    //get
    VfxU8 getLineType() {return m_lineType;}
    VfxU8 getSpeed() {return m_speed;}
    VfxWChar *getDialNumber() {return m_dialNumber;}
    //set
    void setLineType(VfxU8 lineType) {m_lineType = lineType;}
    void setSpeed(VfxU8 speed) {m_speed = speed;}
    void setDialNumber(VfxWChar *dialNumber) {mmi_wcscpy((WCHAR*)m_dialNumber, (WCHAR*)dialNumber);}

private:
    VfxU8       m_lineType; // line type
    VfxU8       m_speed; // speed
    VfxWChar    m_dialNumber[SRV_DTCNT_PROF_MAX_DIAL_NUM_LEN + 1];
} ;
#endif

/***************************************************************************** 
 * Class VappDtcntRightIconMultiTextFrame
 *****************************************************************************/

/*
 * DESCRIPTION
 *  this is a custom list frame class, which has an icon in the right.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntRightIconMultiTextFrame : public VcpListMenuCellMultiTextFrame
{

// constructor / destructor
public:
    VappDtcntRightIconMultiTextFrame() : m_imageFrame(NULL) {}
    virtual ~VappDtcntRightIconMultiTextFrame() {}

protected:
#if defined(__MMI_MAINLCD_320X480__)
    enum
    {
        IMG_LEFT_GAPS    = 10,
        IMG_RIGHT_GAPS   = 10,
        IMG_MAX_WIDTH    = 30
    };
#elif defined(__MMI_MAINLCD_480X800__)
    enum
    {
        IMG_LEFT_GAPS    = 14,
        IMG_RIGHT_GAPS   = 14,
        IMG_MAX_WIDTH    = 45
    };
#elif defined(__MMI_VUI_COSMOS_CP__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__))
    enum
    {
        IMG_LEFT_GAPS    = 8,
        IMG_RIGHT_GAPS   = 8,
        IMG_MAX_WIDTH    = 22
    };
#else /* Shell: QVGA / WQVGA */
    enum
    {
        IMG_LEFT_GAPS    = 11,
        IMG_RIGHT_GAPS   = 11,
        IMG_MAX_WIDTH    = 23
    };
#endif

// override
public:
    // the following functions will override its parent
    virtual void onCreateElements();
    virtual void onLayoutElements();
    virtual void onUpdateElements();

// variable
private:
    VfxImageFrame *m_imageFrame;
} ;


/***************************************************************************** 
 * Class VappDtcntGPRSPage
 *****************************************************************************/

/*
 * DESCRIPTION
 *  page for add/edit/view data account.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntGPRSPage : public VfxPage
{

public:
    VappDtcntGPRSPage():
        m_acctId(0),
        m_settingType(VAPP_DTCNT_ACCOUNT_SETTING_TYPE_ADD),
        m_gprsContext(NULL),
        m_gprsProfileSrvCntx(NULL),
        m_form(NULL),
        m_detail(NULL),
        m_authType(0),
        m_currActiveId(GPRS_ITEM_ID_ACCOUNT_NAME),
        m_simType(SRV_DTCNT_SIM_TYPE_1){}
    VappDtcntGPRSPage(VfxU32 acctId, VappDtcntAccoutSettingType settingType, srv_dtcnt_sim_type_enum simType) :
        m_acctId(acctId),
        m_settingType(settingType),
        m_gprsContext(NULL),
        m_gprsProfileSrvCntx(NULL),
        m_form(NULL),
        m_detail(NULL),
        m_authType(0),
        m_currActiveId(GPRS_ITEM_ID_ACCOUNT_NAME),
        m_simType(simType)
    {
    }
    virtual ~VappDtcntGPRSPage() {}

public:
    enum
    {
        GPRS_ITEM_ID_ACCOUNT_NAME = 0,
        GPRS_ITEM_ID_APN,
        GPRS_ITEM_ID_USERNAME,
        GPRS_ITEM_ID_PASSWORD,
        GPRS_ITEM_ID_AUTHTYPE,
        GPRS_ITEM_ID_ADVANCED_SETTING
    } ;
    
    enum
    {
        GPRS_DETAIL_ID_BASE = 0,
        GPRS_DETAIL_ID_ADVANCED
    } ;
    
    enum
    {
        GPRS_TOOLBAR_ID_SAVE = 0,
        GPRS_TOOLBAR_ID_CANCEL
    } ;

    enum
    {
        ID_GPRS_FUNCTIONBAR_PREV = 1,
        ID_GPRS_FUNCTIONBAR_NEXT,
        ID_GPRS_FUNCTIONBAR_SAVE
    } ;
    
public:
    virtual void onInit();
    virtual void onDeinit();

protected:

    void onGPRSToolBarTapped(
        VfxObject* sender,  // sender
        VfxId id            // id
    ) ;
    void onLaunchGPRSAdvancedSetting(
        VcpFormItemCell* sender, // Sender
        VfxId id // Sender id
    ) ;

    void onBtnAuthTypeTapped(
        VfxObject* sender, //sender 
        VfxId id //
    ) ;

    void onSelectAuthType(
        VfxBasePopup *sender,        // popup
        VfxBasePopupStateEnum state  // state
    ) ;

    void onBtnLaunchGPRSAdvancedSetting(
        VfxObject* sender, //sender 
        VfxId id //
    ) ;

    void onFunctionBarTap(
        VfxObject *sender,  // [IN] sender object
        VfxId id            // [IN] Toolbar id
    ) ;

    // connect signal function when text actived
    void onTextActivated(
        VcpTextEditor *sender,  // [IN] send object
        VfxBool  activated      // [IN] activate flag
    );

// method
public:
    void loadGPRSInitContext(
        VfxU32 acctId, // [IN] acctId
        srv_dtcnt_prof_gprs_struct *srvCntx, // [OUT] 
        VappDtcntGPRSAccountData *displayContext // [OUT]
    );

    void onBarSaveCommond();
    void createTextInput(VfxFrame* functionBar, VfxU32 resId, VfxWChar *text, 
				VfxS32 maxLen, VfxU32 inputType, VfxId itemId);
    void editGprsPage();
    void viewGprsPage();
#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__    
    void onSimChangeEvt(VfxBool flag, mmi_sim_enum sim);
#endif

private:
    VfxU32 m_acctId;
    VappDtcntAccoutSettingType m_settingType;
    VappDtcntGPRSAccountData *m_gprsContext;
    srv_dtcnt_prof_gprs_struct *m_gprsProfileSrvCntx;
    VcpForm *m_form;
    VfxWChar *m_detail;
    VfxU8  m_authType;
    VfxId  m_currActiveId;
    srv_dtcnt_sim_type_enum m_simType;
} ;


/***************************************************************************** 
 * Class VappDtcntCSDPage
 *****************************************************************************/

/*
 * DESCRIPTION
 *  page for add/edit/view data account.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
#ifdef __TCPIP_OVER_CSD__
class VappDtcntCSDPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappDtcntCSDPage);
// constructor / destructor
public:
    VappDtcntCSDPage():
        m_acctId(0),
        m_settingType(VAPP_DTCNT_ACCOUNT_SETTING_TYPE_ADD),
        m_csdContext(NULL),
        m_csdProfileSrvCntx(NULL),
        m_form(NULL),
        m_detail(NULL),
        m_lineType(0),
        m_speed(0),
        m_currActiveId(CSD_ITEM_ID_ACCOUNT_NAME),
        m_simType(SRV_DTCNT_SIM_TYPE_1)
    {
    }
        
    VappDtcntCSDPage(VfxU32 acctId, VappDtcntAccoutSettingType settingType, srv_dtcnt_sim_type_enum simType) :
        m_acctId(acctId),
        m_settingType(settingType),
        m_csdContext(NULL),
        m_csdProfileSrvCntx(NULL),
        m_form(NULL),
        m_detail(NULL),
        m_lineType(0),
        m_speed(0),
        m_currActiveId(CSD_ITEM_ID_ACCOUNT_NAME),
        m_simType(simType)
    {
    }
    virtual ~VappDtcntCSDPage() {}

public:
    enum
    {
        CSD_ITEM_ID_ACCOUNT_NAME = 0,
        CSD_ITEM_ID_NUMBER,
        CSD_ITEM_ID_USERNAME,
        CSD_ITEM_ID_PASSWORD,
        CSD_ITEM_ID_LINETYPE,
        CSD_ITEM_ID_SPEED,
        CSD_ITEM_ID_ADVANCED_SETTING
    } ;

    enum
    {
        CSD_DETAIL_ID_BASE = 0,
        CSD_DETAIL_ID_ADVANCED
    } ;
    
    enum
    {
        CSD_TOOLBAR_ID_SAVE = 0,
        CSD_TOOLBAR_ID_CANCEL
    } ;

    enum
    {
        ID_CSD_FUNCTIONBAR_PREV = 1,
        ID_CSD_FUNCTIONBAR_NEXT,
        ID_CSD_FUNCTIONBAR_SAVE
    } ;

public:
    virtual void onInit();
    virtual void onDeinit();

protected:

    void onCSDToolBarTapped(
        VfxObject* sender,  // sender
        VfxId id            // id
    ) ;
    void onLaunchCSDAdvancedSetting(
        VcpFormItemCell* sender, // Sender
        VfxId id // Sender id
    ) ;

    void onBtnLineTypeTapped(
        VfxObject* sender, //sender 
        VfxId id //
    ) ;

    void onSelectLineType(
        VfxBasePopup *sender,        // popup
        VfxBasePopupStateEnum state  // state
    ) ;

    void onBtnSpeedTypeTapped(
        VfxObject* sender, //sender 
        VfxId id //
    ) ;

    void onSelectSpeedType(
        VfxBasePopup *sender,        // popup
        VfxBasePopupStateEnum state  // state
    ) ;

    void onBtnLaunchCSDAdvancedSetting(
        VfxObject* sender, //sender 
        VfxId id //
    ) ;

    void onFunctionBarTap(
        VfxObject *sender,  // [IN] sender object
        VfxId id            // [IN] Toolbar id
    ) ;

    // connect signal function when text actived
    void onTextActivated(
        VcpTextEditor *sender,  // [IN] send object
        VfxBool  activated      // [IN] activate flag
    );
// method
public:
    void loadCSDInitContext(
        VfxU32 acctId, // [IN] acctId
        srv_dtcnt_prof_csd_struct *srvCntx, // [OUT] 
        VappDtcntCSDAccountData *displayContext // [OUT]
    );

    void onBarSaveCommond();
    void onSimChangeEvt(VfxBool flag, mmi_sim_enum sim);
private:
    VfxU32 m_acctId;
    VappDtcntAccoutSettingType m_settingType;
    VappDtcntCSDAccountData *m_csdContext;
    srv_dtcnt_prof_csd_struct *m_csdProfileSrvCntx;
    VcpForm *m_form;
    VfxWChar *m_detail; // used for readonly
    VfxU8  m_lineType;
    VfxU8  m_speed;
    VfxId  m_currActiveId;
    srv_dtcnt_sim_type_enum m_simType;
} ;
#endif

/***************************************************************************** 
 * Class VappDtcntAdvancedPage
 *****************************************************************************/

/*
 * DESCRIPTION
 *  page for add/edit/view data account.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntAdvancedPage : public VfxPage
{

public:
    VappDtcntAdvancedPage() {}
    VappDtcntAdvancedPage(VappDtcntAccoutSettingType type, VappDtcntCommonAccountData *data, srv_dtcnt_sim_type_enum simType, VfxBool flag) :
        m_settingType(type),
        m_commonContext(data),
        m_form(NULL),
        m_functionBar(NULL),
        m_detailBase(NULL),
        m_detailProxy(NULL),
        m_detailOthers(NULL),
        m_simType(simType),
        m_isGPRS(flag),
        m_connectionType(0),
        m_useProxy(0),
        m_wapPortIndex(0),
        m_currActiveId(ADVANCED_SETTING_ITEM_ID_HOMEPAGE)
    {
    }
    virtual ~VappDtcntAdvancedPage() {}

public:
    enum
    {
        ADVANCED_SETTING_TOOLBAR_ID_OK,
        ADVANCED_SETTING_TOOLBAR_ID_CANCEL
    } ;
    
    enum
    {
        ADVANCED_DETAIL_ID_BASE = 0,
        ADVANCED_DETAIL_ID_PROXY_CAPTION,
        ADVANCED_DETAIL_ID_PROXY,
        ADVANCED_DETAIL_ID_OTHERS_CAPTION,
        ADVANCED_DETAIL_ID_OTHERS
    } ;
    
    enum
    {
        ADVANCED_SETTING_ITEM_ID_HOMEPAGE = 0,
        ADVANCED_SETTING_ITEM_ID_PROXY_PROXY_ADDRESS,
        ADVANCED_SETTING_ITEM_ID_PROXY_PORT, // has two style for this
        ADVANCED_SETTING_ITEM_ID_PROXY_USERNAME,
        ADVANCED_SETTING_ITEM_ID_PROXY_PASSWORD,
        ADVANCED_SETTING_ITEM_ID_OTHERS_DNS1,
        ADVANCED_SETTING_ITEM_ID_OTHERS_DNS2,
        ADVANCED_SETTING_ITEM_ID_OTHERS_IP,
        ADVANCED_SETTING_ITEM_ID_OTHERS_SUBNET,
        ADVANCED_SETTING_ITEM_ID_CONNTYPE,
        ADVANCED_SETTING_ITEM_ID_PROXY_CAPTION,
        ADVANCED_SETTING_ITEM_ID_PROXY_SWITCH,      
        ADVANCED_SETTING_ITEM_ID_OTHERS_CAPTION       
    } ;

    enum
    {
        ID_ADVANCED_FUNCTIONBAR_PREV = 1,
        ID_ADVANCED_FUNCTIONBAR_NEXT,
        ID_ADVANCED_FUNCTIONBAR_OK
    } ;
    
// override
public:
    virtual void onInit();
    virtual void onDeinit();

protected:
    void onAdvancedToolBarTapped(
        VfxObject* sender,  // sender
        VfxId id            // id
    );

    void onProxySwitchChange(
        VcpFormItemSwitchCell* sender,  // Sender
        VfxId id,                       // Sender id
        VfxBool switchVal               // new switch value
    );

    void onBtnConnectionTypeTapped(
        VfxObject* sender, //sender 
        VfxId id //
    );

    void onSelectConnectionType(
        VfxBasePopup *sender,        // popup
        VfxBasePopupStateEnum state  // state
    ) ;

    void onBtnWapProxyPortTypeTapped(
        VfxObject* sender, //sender 
        VfxId id //
    );

    void onSelectWapProxyPort(
        VfxBasePopup *sender,        // popup
        VfxBasePopupStateEnum state  // state
    ) ;

    void onFunctionBarTap(
        VfxObject *sender,  // [IN] sender object
        VfxId id            // [IN] Toolbar id
    ) ;

    void onTextInsert(
        VfxWChar *str,  // [IN] current text string buf
        VfxS32 pos,     // [IN] will be inserted char
        VcpTextChangeEnum type,
        VfxBool *changed // [OUT] flad indicate to insert or not
    );


    // connect signal function when text actived
    void onTextActivated(
        VcpTextEditor *sender,  // [IN] send object
        VfxBool  activated      // [IN] activate flag
    );

public:
    // check homepage, 0 if success
    VfxS16 checkUrlValidity(VfxWChar *url, VfxBool isBlankValid);

    // check ip address
    VfxBool checkIpAddressValidity(
        VfxWChar *ipDisplayStr,    // [IN]
        VfxU8 *ip,              // [OUT] ipAddress
        VfxBool isBlankValid,   // [IN]
        VfxBool isAllZeroValid  // [IN]
    );

    // check proxy port
    VfxBool checkProxyPortValidity(VfxWChar *portStr);

    void displayComfirmPopup(VfxU16 resId);

    void onBarOKCommond();

    void createTextInput(VfxU32 resId, VfxWChar *text, VfxS32 maxLen,
							 VfxU32 inputType, VfxId itemId, VfxBool isInsert);

    void setItemState();

    void editAdvancePage();
	
    void viewAdvancePage();
#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__
    void onSimChangeEvt(VfxBool flag, mmi_sim_enum sim);
#endif    
private:
    VappDtcntAccoutSettingType m_settingType;
    VappDtcntCommonAccountData* m_commonContext;
    VcpForm *m_form;
    VcpFunctionBar *m_functionBar;
    VfxWChar *m_detailBase; // used for readonly
    VfxWChar *m_detailProxy; // used for readonly
    VfxWChar *m_detailOthers; // used for readonly
    srv_dtcnt_sim_type_enum m_simType;
    VfxBool m_isGPRS;
    VfxU8 m_connectionType;
    VfxU8 m_useProxy;    
    VfxU8 m_wapPortIndex; // used for wap
    VfxId m_currActiveId;
} ;

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
 * Class VappDtcntListPage
 *****************************************************************************/

/*
 * DESCRIPTION
 *  page for data account list.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntListPage : public VfxPageHandler, public IVcpListMenuContentProvider
{

public:
    VappDtcntListPage(srv_dtcnt_sim_type_enum simType, VfxMainScrEx *scr) : 
        m_listMenu(NULL), 
        m_toolBar(NULL), 
        m_titleBar(NULL), 
        m_listType(VAPP_DTCNT_LIST_TYPE_DISPLAY_ACCOUNT),
        m_listCntx(NULL),
        m_selectionState(NULL),
        m_disableState(NULL),
        m_markAll(VFX_FALSE),
        m_simType(simType),
        m_scr(scr)
    {
    }
    VappDtcntListPage() {}
    virtual ~VappDtcntListPage() {}

// override from Provider
public:
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );


    virtual VfxU32 getCount() const;

    virtual VfxBool getItemIsDisabled(
        VfxU32 index       // [IN] the index of item
        ) const;

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const;
    
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,        // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        );

    virtual VfxBool getItemTextFrameFormat(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxTextFrame *frame             // [OUT] the text frame
        );

    // Get the empty text resource for the text when list menu is empty
    virtual VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

// override
public:
    virtual void onPageInit(VfxPageEx *page);
    virtual void onPageDeinit(VfxPageEx *page);
    virtual void onPageEnter(VfxPageEx *page, VfxBool isBackward);
    virtual void onPageBack(VfxPageEx *page);

public:
    static VfxU8 getAcctNumExcludeSimProv(srv_dtcnt_sim_type_enum simType);
    void deleteSelectedAccount();
#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__
    void onSimChangeEvt(VfxBool flag, mmi_sim_enum sim);
#endif

// signal
protected:

    // item tapped
    void onListItemTapped(
        VcpListMenu *sender,    // list menu
        VfxU32 index            // list index
    );

    // item state changed in delete page
    void onItemStateChanged(
        VcpListMenu *sender, 
        VfxU32 index, 
        VcpListMenuItemStateEnum newState
    );

    // tool bar tapped
    void onToolBarTapped(
        VfxObject *sender,    // list menu
        VfxU32 index            // list index
    );

    // not delete confirm popup
    void onBtnNotAllowDelete(
        VfxObject* sender,     // sender 
        VfxId id          // id
    );

    void onDeleteConfirm(
        VfxObject* obj, 
        VfxId id
    );
    
    // add account signal 
    void onCommandPopupAddAccount(
        VfxObject* sender,     // sender 
        VfxId id          // id
    );

private:
    VcpListMenu *m_listMenu;
    VcpToolBar  *m_toolBar;
    VcpTitleBar *m_titleBar;
    VappDtcntListTypeEnum m_listType;
    VappDtcntListDisplayContext *m_listCntx;
    VfxBool *m_selectionState; // array for selection state
    VfxBool *m_disableState; // array for disable state
    VfxBool m_markAll;
    srv_dtcnt_sim_type_enum m_simType;
    VfxMainScrEx *m_scr;
};


/***************************************************************************** 
 * Class VappDtcntSimListPage
 *****************************************************************************/

/*
 * DESCRIPTION
 *  Sim list page.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntSimListPage : public VfxPageHandler, public IVcpListMenuContentProvider
{

public:
    VappDtcntSimListPage(VfxMainScrEx *scr) : m_listMenu(NULL), m_scr(scr) {};
    virtual ~VappDtcntSimListPage() {};

// override from Provider
public:
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );

    virtual VfxU32 getCount() const;

protected:
    void onListItemTapped(
        VcpListMenu *sender, // Sender
        VfxU32 index        // List item index
    ) ;

// Override
public:
    virtual void onPageInit(VfxPageEx *page);
#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__
    void onSimChangeEvt(VfxBool flag, mmi_sim_enum sim);
#endif
public:
    VcpListMenu *m_listMenu;
    VfxMainScrEx *m_scr;
};

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
#endif
/***************************************************************************** 
 * Class VappDtcntApp
 *****************************************************************************/

/*
 * DESCRIPTION
 *  App Class.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntApp : public VfxCui, public IVfxMainScrHandler
{
    VFX_DECLARE_CLASS(VappDtcntApp);

public:
    VappDtcntApp() {};
    virtual ~VappDtcntApp() {};

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onScr1stReady(VfxMainScrEx *scr);
    virtual void onDeinit(void);
//variable
public:
    //main screen instance
    //VappDtcntScreen     *m_mainScr;
};


/***************************************************************************** 
 * Class VappDtcntSettingCell
 *****************************************************************************/

/*
 * DESCRIPTION
 *  Data account setting Cell.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntSettingCell: public VcpFormItemLauncherCell
{
    VFX_DECLARE_CLASS(VappDtcntSettingCell);

public:
    virtual void onInit();
    void onTap(VcpFormItemCell* sender, VfxId senderId);
#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__
    void onSimChangeEvt(VfxBool flag, mmi_sim_enum sim);
#endif

};

void textEditorState(VcpForm *form, VfxId ActiveId, VfxBool isActived);

#endif
#endif /* __VAPP_DTCNT_UI_H__ */
