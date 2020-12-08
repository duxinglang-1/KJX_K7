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
 *  vapp_helloworld.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_CLOG_USAGE_H__
#define __VAPP_CLOG_USAGE_H__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#include "MMIDataType.h"
#include "mmi_features.h"
#include "CallLogSrvGprot.h"
#include "CallLogSrvIprot.h" 
}
#endif


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
 #if (defined(__MMI_CLOG_CALL_TIME__) || defined(__MMI_CLOG_CALL_COST__) || defined(__MMI_CLOG_SMS_COUNT__) || defined(__MMI_CLOG_GPRS_COUNT__))
extern "C" mmi_ret vapp_clog_usage_init(mmi_event_struct *evt);


/*****************************************************************************
 * Class VappClogUsageMain
 ****************************************************************************/
class VappClogUsageMain : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappClogUsageMain);

public:
    VappClogUsageMain();

    void checkResetUsage();

    void onTimeChanged(VfxU32 flag);
    
    void onUpdateUsage();

#ifdef __MMI_CLOG_GPRS_COUNT__
    static VfxS32 resetGPRScb (void *user_data,
                       srv_clog_gprs_reset_req_struct *req_data,
                       MMI_BOOL more, srv_clog_ret_enum ret);
#endif

    VfxSignal0 m_signalUpdateUsage;
};

/***************************************************************************** 
* Class 
*****************************************************************************/

class VappClogUsageSIMPage : public VfxPage, public IVcpListMenuContentProvider
{
public:
    VappClogUsageSIMPage();
    
// Override
public:
    virtual void onInit();

    void onItemTapped(VcpFormItemCell* cell, VfxId cell_id);

    enum ListSIMOrder //Don't modify this order
    {
        LIST_SIM1 = 0,
        LIST_SIM2,
        LIST_SIM_TOTAL
    };
private:
    VcpForm *m_form;
};


class VappClogUsagePage : public VfxPage
{
public:
    
    VappClogUsagePage();
    
    VappClogUsagePage(mmi_sim_enum simID);

public:
    
    virtual void onInit();    
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);
    static mmi_ret listener(mmi_event_struct* evt);

    void updateUsageData();

    void onFormClick(VcpFormItemCell* cell, VfxId cell_id);
    mmi_ret onProc(mmi_event_struct *evt);
    
#ifdef __MMI_CLOG_GPRS_COUNT__

    void createGPRSCountForm();

    void getGPRSCountData();
    
    static VfxS32 getGPRSCountDataCbk(void *user_data,
                             srv_clog_gprs_get_req_struct *req_data,
                             const srv_clog_gprs_data_struct *gprs_data,
                             MMI_BOOL more, srv_clog_ret_enum ret);
    
    void convertGPRSCount(VfxU64 count, VfxWString & str);
    
#endif /* __MMI_CLOG_GPRS_COUNT__ */

#ifdef __MMI_CLOG_SMS_COUNT__

    void createSMSCountForm();

    void getSMSCountData();

#endif /* __MMI_CLOG_SMS_COUNT__ */

#ifdef __MMI_CLOG_CALL_TIME__

    void createCallTimeForm();

    void getCallTimeData();
    
#endif /* __MMI_CLOG_CALL_TIME__ */

#ifdef __MMI_CLOG_CALL_COST__

    void createCallCostForm();

    void getCallCostData();

    void onCCPassPin2Cb();
    
    static VfxS32 getCallCostDataCbk(void *user_data, mmi_sim_enum sim_id, U32 fields,
                                     const srv_clog_ccost_data_struct *data, 
                                     MMI_BOOL more, srv_clog_ret_enum ret);
#endif /* __MMI_CLOG_CALL_COST__ */
  

public:
    enum FormCellID
    {
        ID_GPRS_CAPTION,
        ID_GPRS_MONTHLY_ALL,
        ID_GPRS_MONTHLY_RECEIVE,
        ID_GPRS_MONTHLY_SENT,
        ID_GPRS_THRESHOLD,
        ID_SMS_CAPTION,
        ID_SMS_MONTHLY_RECEIVE,
        ID_SMS_MONTHLY_SENT,
        ID_CT_CAPTION,
        ID_CT_MONTHLY_OUTGOING,
        ID_CT_MONTHLY_INCOMING,
        ID_CC_CAPTION,
        ID_CC_LAST_CALL_COST,
        ID_CC_TOTAL_COST,
        ID_CC_CLEAR_COST,
        ID_CC_SET_MAX_COST,
        ID_CC_SET_PPU,
        ID_TOTAL
    };
    
private:
    VcpForm        *m_form;
    mmi_sim_enum    m_simID;
    VfxId           m_focusFormCellId;

#ifdef __MMI_CLOG_CALL_COST__
    VfxU32          m_maxCost;
    VfxWChar        m_price[SRV_CLOG_CCOST_MAX_PPU_LEN + 1];
    VfxWChar        m_unit[SRV_CLOG_CCOST_MAX_CURRENCY_LEN + 1];
#endif
};

#endif 
#ifdef __MMI_CLOG_CALL_COST__

class VappClogUsageCCMaxPage : public VfxPage
{
public:
    VappClogUsageCCMaxPage();
    VappClogUsageCCMaxPage(mmi_sim_enum simID, VfxU32 maxCost);
    
    void onInit();
    void onToolBarClick(VfxObject* sender, VfxId btnID);
    
    void saveCCMax();
    static VfxS32 VappClogUsageCCMaxPage::saveCCMaxCbk(void *user_data,
            mmi_sim_enum sim_id, U32 fields, srv_clog_ret_enum ret);

public:

    enum CCMaxEnum
    {
        MAX_COST_VALUE = 16777215, /* 3 bytes: 2^23 + 2^22 + 2^11 + ... +2^1 + 2^0 */
        MAX_COST_STR_LENGTH = 8
    };
private:
    VcpForm       *m_form;
    mmi_sim_enum   m_simID;
    VfxU32         m_maxCost;
};


class VappClogUsageCCPPUPage : public VfxPage
{
public:
    VappClogUsageCCPPUPage(){};
    VappClogUsageCCPPUPage(mmi_sim_enum simID, VfxWChar *price, VfxWChar *unit);
    
    void onInit();
    void onToolBarClick(VfxObject* sender, VfxId btnID);

    void saveCCPPU();
    static VfxS32 saveCCPPUCbk(void *user_data,
            mmi_sim_enum sim_id, U32 fields, srv_clog_ret_enum ret);

private:
    VcpForm        *m_form;
    mmi_sim_enum    m_simID;
    VfxWChar       *m_price;
    VfxWChar       *m_unit;    
    VcpFormItemTextInput *m_priceCell;    
    VcpFormItemTextInput *m_unitCell;
};
#endif /* __MMI_CLOG_CALL_COST__ */


// show two string in one line, e.g. 'Monthly Incoming    2hr30mins'
class VappClogUsageCell: public VcpFormItemCell
{
public:
    virtual VfxBool onPenInput(VfxPenEvent &event);
    
	virtual void onCellTap(VfxPenEvent &event);
};


#endif /* __VAPP_CLOG_USAGE_H__ */

