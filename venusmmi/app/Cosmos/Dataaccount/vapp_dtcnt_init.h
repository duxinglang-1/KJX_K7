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
 *  vapp_dtcnt_init.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file is used to define for data account initial
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_DTCNT_INIT_H__
#define __VAPP_DTCNT_INIT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __TCPIP__
#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vapp_dtcnt_gprot.h"
#include "vapp_dtcnt_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "MMIDatatype.h"

extern "C"
{
#include "SimCtrlSrvGprot.h"
#include "DtcntSrvIprot.h"
}

extern "C"
{
void vappDtcntInit();
}


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VAPP_DTCNT_MAX_PLMN_LEN (SRV_MAX_PLMN_LEN + 1)
#define VAPP_DTCNT_CONF_NAME_LEN 32


/*******************************************************************************
* Enum 
*******************************************************************************/

enum VappDtcntInitPLMN
{
    VAPP_DTCNT_INIT = 0x01,
    VAPP_DTCNT_PLMN = 0x02,
    VAPP_DTCNT_INIT_PLMN = 0x04,
    VAPP_DTCNT_INIT_PLMN_TOTAL
} ;


enum VappDtcntParserItemTypeEnum
{
    VAPP_DTCNT_PARSER_ITEM_TYPE_CONNECTION,
    VAPP_DTCNT_PARSER_ITEM_TYPE_APP,
    VAPP_DTCNT_PARSER_ITEM_TYPE_DIAL_TYPE,
    VAPP_DTCNT_PARSER_ITEM_TYPE_DATA_RATE,
    VAPP_DTCNT_PARSER_ITEM_TYPE_AUTH,
    VAPP_DTCNT_PARSER_ITEM_TYPE_TOTAL
} ;


/***************************************************************************** 
 * Class VappDtcntInitial
 *****************************************************************************/

/*
 * DESCRIPTION
 *  data account initial class
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */

class VappDtcntInitial : public VfxBase
{
public:
    // data account app initialize part which don't related to SIM card.
    static mmi_ret dtcntNormalInit(mmi_event_struct *evt);
    
    // data account init function, get data ready
    static void dtcntInit();

    // plmn changed function
    static mmi_ret dtcntOnHomePlmnChanged(mmi_event_struct *evt);

    // bootup completed evt
    static mmi_ret dtcntOnBootupCompleted(mmi_event_struct *evt);

    // global popup
    static MMI_BOOL dtcntSimPreferChangedPopup(mmi_scenario_id scen_id, void *arg);

    // add config account account
    static void dtcntAddConfigAccount();

    // check plmn match which sim card
    static VfxU8 dtcntSimMatch(
        const VfxS8 *operate,       // [IN] not need now
        const VfxS8 *code           // [IN] plmn
    );
    
    // add account to srv data base
    static srv_dtcnt_result_enum dtcntAddSimProf(
        VfxU8 simMatch,                            // [IN]     which sim
        srv_dtcnt_sim_type_enum *simInfo,       // [IN]     PLMN buffer to be filled in  
        srv_dtcnt_store_prof_data_struct *prof, // [IN]     profile data
        VfxU32 *acctId                          // [OUT]    account id
    );

    // delete factory config account by SIM
    static void dtcntDeleteAnySimProfile(srv_dtcnt_sim_type_enum sim);

    // delete factory config account
    static void dtcntSimProfDelete();

    // get account from config file or xml
    static void dtcntPreInstallParse();

    // get defined profile, not include DM
    static void dtcntGetDefinedProf();

    // delete callback when bootup
    static void dtcntBootupDeleteAccountCallback(VfxU32 deletingAccId, void *user_data);

    // check sim card is changed or not
    static VfxBool dtcntIsSimCardChanged();

    // get sim card's plmn
    static VfxBool dtcntGetSimPlmn(mmi_sim_enum sim, VfxS8 *out_buffer);

    // following function for xml parser
    static VfxS32 dtcntIsConfFileExit();
    static void *dtcntAccountItemStart(VfxS32 bearer);
    static VfxS32 dtcntGetItemVaule(VappDtcntParserItemTypeEnum option, const VfxChar *name);
    static VfxBool dtcntGetIpAddress(VfxU8 *ip, const VfxChar *data);
    static void dtcntAccountItemEnd(VfxS32 bearer, void *user_data);
    static void dtcntAccountParseEnd(VfxS32 ret);
    static VfxU16* getAccountName() {return s_accountName;}
    static VfxS8* getAddress() {return s_address;}
    static mmi_ret dtcntSimChanged(mmi_event_struct *evt);
    static mmi_ret dtcntBearerInfoChanged(mmi_event_struct * evt);
    
private:
    static VfxBool s_dtcntFactory; // is restore factory or not
    static srv_dtcnt_result_enum s_result; // database related op 
    static srv_dtcnt_prof_gprs_struct s_gprsProfileSrv;
    static srv_dtcnt_prof_csd_struct s_csdProfileSrv;
    static VfxU16 s_accountName[MAX_DATA_ACCOUNT_NAME_LEN + 1];
    static VfxS8 s_address[MAX_DTCNT_LIST_ADDR_LEN];
    static VfxS32 s_dtcntFileExist; // xml file name for all sim card existed or not
    static VfxS32 s_dtcntInitPLMN; // plmn and dtcnt init ready or not
    static VfxBool s_simChanged[MMI_SIM_TOTAL];
    static VfxS8 s_dtcntSim[MMI_SIM_TOTAL][VAPP_DTCNT_MAX_PLMN_LEN];
    static VfxWChar s_dtcntConf[MMI_SIM_TOTAL][VAPP_DTCNT_CONF_NAME_LEN];
    // for plmn evt, because need to proc the evt when the last plmn send at bootup 
    static VfxBool s_firstProcPlmnEvt;
    static VfxU16 s_dtcntPlmnEvtNum;
    static VfxU16 s_dtcntPlmnProcNum;
#if (MMI_MAX_SIM_NUM >= 2)
    static VfxU32 s_simPreferFlag; // don't show popup
#endif
} ;
#endif
#endif /* __VAPP_DTCNT_INIT_H__ */
