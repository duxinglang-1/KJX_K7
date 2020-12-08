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
 *  vapp_dtcnt.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file defines interfaces for other app
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_DTCNT_H__
#define __VAPP_DTCNT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __TCPIP__
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_dtcnt_def.h"
#include "vapp_dtcnt_gprot.h"
#include "mmi_frm_utility_gprot.h"
extern "C"
{
#include "DtcntSrvGprot.h"
#include "DtcntSrvIprot.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define DTCNT_READY_CHECK_NUM 10
#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
#define __DTCNT_SIM_HOT_SWAP_SUPPORT__
#endif
#ifdef __MMI_CCA_SUPPORT__
#define __COSMOS_DTCNT_CCA_SUPPORT__
#endif
/***************************************************************************** 
 * Typedef
 *****************************************************************************/


/***************************************************************************** 
 * Struct related NVRAM
 *****************************************************************************/


/*******************************************************************************
* Export API 
*******************************************************************************/


/***************************************************************************** 
 * Class VappDtcntDispItem
 *****************************************************************************/

/*
 * DESCRIPTION
 *  this class use to record some basic info for some an account
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntDispItem : public VfxBase
{

// constructor / destructor
public:
    VappDtcntDispItem() :
        m_profileId(0),
        m_connectionType(0),
        m_simInfo(0),
        m_bearerType(0),
        m_readOnly(0),
        m_accountType(SRV_DTCNT_PROF_TYPE_USER_CONF)
    {
    }
    VappDtcntDispItem(VfxU32 profileId, VfxU8 connType, VfxU8 simInfo,
			VfxU8 bearerType, VfxU8 readOnly, srv_dtcnt_prof_acc_type_enum accountType) :
    m_profileId(profileId),
    m_connectionType(connType),
    m_simInfo(simInfo),
    m_bearerType(bearerType),
    m_readOnly(readOnly),
    m_accountType(accountType)
    {
    }
    virtual ~VappDtcntDispItem() {}

// method
public:
    // get
    VfxU32 getProfileId()       {return m_profileId;}
    VfxU8  getConnectionType()  {return m_connectionType;}
    VfxU8  getSimInfo()         {return m_simInfo;}
    VfxU8  getBearerType()      {return m_bearerType;}
    VfxU8  getReadOnly()        {return m_readOnly;}
    srv_dtcnt_prof_acc_type_enum  getAccountType()     {return m_accountType;}

    // set
    void setProfileId(VfxU32 profileId)             {m_profileId = profileId;}
    void setConnectionType(VfxU8 connectionType)    {m_connectionType = connectionType;}
    void setSimInfo(VfxU8 simInfo)                  {m_simInfo = simInfo;}
    void setBearerType(VfxU8 bearerType)            {m_bearerType = bearerType;}
    void setReadOnly(VfxU8 readOnly)                {m_readOnly = readOnly;}
    void setAccountType(srv_dtcnt_prof_acc_type_enum accountType) {m_accountType = accountType;}
 
private:
    VfxU32 m_profileId;
    VfxU8 m_connectionType;
    VfxU8 m_simInfo;
    VfxU8 m_bearerType;
    VfxU8 m_readOnly;
    srv_dtcnt_prof_acc_type_enum m_accountType;
} ;


/***************************************************************************** 
 * Class VappDtcntDispItemList
 *****************************************************************************/

/*
 * DESCRIPTION
 *  this class use to record some basic info for all accounts and provide some interface
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntDispItemList : public VfxBase
{
public:
    VappDtcntDispItemList() {}
    ~VappDtcntDispItemList() {}
public:
    // use to get full account name for encode account
    static VfxBool getFullAccountName(
        VfxU32 acctId,                      // account id
        VfxWChar *dest,                     // buffer for account name    
        VfxU8 len,                          // length of VfxWChar, not byte length
        VappDtcntGetAcctNameTypeEnum type   // get account name type
    );

    // following api is internal
    // get account number
    static VfxU32 getAcctNum() {return m_acctNum;}

    // get dafault account id
    //static VfxU32 getDefaultProfileId() {return m_defaultProfileId;}

    // set default account id when account id exist
    //static void setDefaultProfileId(VfxU32 acctId) {m_defaultProfileId = acctId;}

    // set profile id as default and sync to service
    static srv_dtcnt_result_enum setDefaultProfileIdToSrv(VfxU32 acctId);

    // add account item
    static void addAcctItem(VappDtcntDispItem acctItem);

    // update account item
    static void updateAcctItem(VappDtcntDispItem acctItem);

    // delete account item
    static void deleteAcctItem(VfxU32 accountId);

    static VappDtcntDispItem* getAccountItem(VfxU32 index) {return &m_acctItems[index];}
    
    // get currently editing account id, for CCA replace only, editing account id not allow to be replaced
    static VfxU32 getCurrEditProfileId() {return m_currEidtProfileId;}

    // set current editing account id
    static void setCurrEditProfileId(VfxU32 acctId) {m_currEidtProfileId = acctId;}

    // check account id is in use or not
    static VfxBool isAccountInUse(VfxU32 accountId);

    // check account id is use_proxy info or not
    static VfxBool isAccountUseProxy(VfxU32 accountId);

    // get sim name
    static VfxWString getSimName(VfxU32 simIndex);
     
    static MMI_BOOL getApnlist(U32 *ids, U32 *num_ids, srv_dtcnt_sim_type_enum sim_type);
     
#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__
    static void resetAcctItem();
    
    static void resetAcctInUse();
     
    static void deleteAcctInUse(VfxU8 accountId);

    static void addAcctInUse(VfxU8 accountId);
#endif
     
private:
    static VappDtcntDispItem m_acctItems[VAPP_DTCNT_PROF_MAX_ACCOUNT_NUM];
    static VfxU32 m_acctNum;
#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__
    static VfxU8 m_acctidsInUse[VAPP_DTCNT_PROF_MAX_ACCOUNT_NUM]; // for record the account in use when hotswap
    static VfxU8 m_acctidsInUseNum; // number of account in use when hotswap
#endif
    //static VfxU32 m_defaultProfileId;
    static VfxU32 m_currEidtProfileId;
} ;


/***************************************************************************** 
 * Class VappDtcntReadyCheck
 *****************************************************************************/

/*
 * DESCRIPTION
 *  this class use to check data account is ready or not
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntReadyCheck : public VfxBase
{
public:
    VappDtcntReadyCheck() {}
    ~VappDtcntReadyCheck() {}

public:
    // use this api to check data account is ready or not, 
    // if not ready, register callback; or return VFX_TRUE if ready
    static VfxBool dtcntReadyCheck(
        FuncPtr readyCallback, // callback function
        VfxBool withScrLock    // need to lock screen or not     
    );
    static void executeReadyCheckCB(); //
    static void setIsDtcntReady(VfxBool readyFlag) {m_isDtcntReady = readyFlag;}
    static VfxBool getIsDtcntReady() {return m_isDtcntReady;}

private:
    static VfxBool m_isDtcntReady;                          // ready flag
    static FuncPtr m_readyCheckCB[DTCNT_READY_CHECK_NUM];   // call back function
} ;


/***************************************************************************** 
 * Class VappDtcntAcctValidity
 *****************************************************************************/

/*
 * DESCRIPTION
 *  this class use to record app info and check validity of account
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */

class VappDtcntAcctValidity : public VfxBase
{
public:
    // check data account id valid or not, for other app
    static VappDtcntAcctValidTypeEnum isAcctValid(
        VfxU32 encodedAcctId,               // encode data account profile
        VfxBool bearerFallback = VFX_FALSE  // need to check one or two account, if VFX_TRUE check two, or just check primary account
    );

    // following api is used internal
    // this used for isAcctValid to simplify code size
    static VfxBool isSingleAcctValid(VfxU32 encodedAcctId);

    // sync invalid app info to service
    static void syncInvalidInfowithSrv();
} ;


/***************************************************************************** 
 * Class VappDtcntSimAvailableInfo
 *****************************************************************************/

/*
 * DESCRIPTION
 *  this class use to record some sim available info for data account
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */

class VappDtcntSimAvailableInfo : public VfxBase
{
public:
    // this api need be executed in vappDtcntInit function
    // use it to check the sim availalble status and number
    static void resetAvailableSim();

    // the following api need be executed after init() was executed once;
    static VfxU32 getAvailableSimNum() {return s_availableSimNum;}
    static VfxU32 getAvailableSimIndex(VfxU32 slot) {return s_availableSimIndex[slot];}
    static mmi_sim_enum getAvailableSimEnum(VfxU32 slot);

private:
    static VfxU32 s_availableSimNum;
    static VfxU32 s_availableSimIndex[MMI_SIM_TOTAL];
} ;

/***************************************************************************** 
 * Class VappDtcntSimAvailableListener
 *****************************************************************************/

/*
 * DESCRIPTION
 *  this class use to record some sim available info for data account
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__
class VappDtcntSimAvailableListener : public VfxObject
{
VFX_OBJ_DECLARE_SINGLETON_CLASS(VappDtcntSimAvailableListener);

public:
    VappDtcntSimAvailableListener() {}
    virtual ~VappDtcntSimAvailableListener() {}

public:
    VfxSignal2<VfxBool,mmi_sim_enum>  m_signalSimChangedEvent; // true -available and false - unavailable
} ;
#endif

void vapp_dtcnt_set_titlebar(VfxResId title_res_id, VfxPage *page);

void vapp_dtcnt_set_titlebar(const VfxWString &titleStr, VfxPage *page);

void setListMenuFormat(VcpListMenu *listmenu, VcpListMenuCellStyleEnum cellStyle,VcpListMenuModeEnum menuMode, VcpListMenuControlModeEnum ctrlMode);

#endif
#endif /* __VAPP_DTCNT_H__ */
