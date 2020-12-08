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
 *  vapp_dtcnt_init.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file is used to implement for data account initial
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __TCPIP__
#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vapp_dtcnt.h"
#include "vapp_dtcnt_init.h"
#include "vapp_dtcnt_xml.h"
#include "vapp_dtcnt_prov_adp.h"
#include "GlobalResDef.h"
#include "vcp_global_popup.h"
#include "mmi_rp_vapp_dtcnt_def.h"
#include "mmi_frm_utility_gprot.h"

extern "C"
{
#include "DtcntSrvGprot.h"
#include "DtcntSrvIprot.h"
#include "CbmSrvGprot.h"
#include "common_nvram_editor_data_item.h"
#include "cbm_api.h"
#include "SimCtrlSrvGprot.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "Unicodexdcl.h"

extern void *custom_config_get_account(kal_int32 type);
extern int mmi_custom_account_get_apptype(const char *name);

}


/*******************************************************************************
* Export API 
*******************************************************************************/
// data account app initialize part 1 (don't related to SIM card) in EVT_ID_SRV_BOOTUP_NORMAL_INIT 
extern "C" mmi_ret vapp_dtcnt_normal_init(mmi_event_struct *evt)
{
    return VappDtcntInitial::dtcntNormalInit(evt);
}

// data account app initialize part 2 in EVT_ID_SRV_BOOTUP_BEFORE_IDLE
void vappDtcntInit()
{
    VappDtcntInitial::dtcntInit();
}

extern "C" mmi_ret vappDtcntOnHomePlmnChanged(mmi_event_struct *evt)
{
    return VappDtcntInitial::dtcntOnHomePlmnChanged(evt);
}

extern "C" mmi_ret vappDtcntSimChanged(mmi_event_struct *evt)
{
    return VappDtcntInitial::dtcntSimChanged(evt);
}

extern "C" mmi_ret vappDtcntBearerInfoChanged(mmi_event_struct *evt)
{
    return VappDtcntInitial::dtcntBearerInfoChanged(evt);
}


extern "C" mmi_ret vapp_dtcnt_on_bootup_completed(mmi_event_struct *evt)
{
    return VappDtcntInitial::dtcntOnBootupCompleted(evt);
}


/***************************************************************************** 
* Class VappDtcntInitial
*****************************************************************************/
VfxBool VappDtcntInitial::s_dtcntFactory = VFX_FALSE;
srv_dtcnt_result_enum VappDtcntInitial::s_result = SRV_DTCNT_RESULT_SUCCESS;
srv_dtcnt_prof_gprs_struct VappDtcntInitial::s_gprsProfileSrv = {0};
srv_dtcnt_prof_csd_struct VappDtcntInitial::s_csdProfileSrv = {0};
VfxU16 VappDtcntInitial::s_accountName[MAX_DATA_ACCOUNT_NAME_LEN + 1] = {0};
VfxS8 VappDtcntInitial::s_address[MAX_DTCNT_LIST_ADDR_LEN] = {0};
VfxS32 VappDtcntInitial::s_dtcntFileExist = 0;
VfxS32 VappDtcntInitial::s_dtcntInitPLMN = 0;

VfxBool VappDtcntInitial::s_simChanged[MMI_SIM_TOTAL] = {0};
VfxS8 VappDtcntInitial::s_dtcntSim[MMI_SIM_TOTAL][VAPP_DTCNT_MAX_PLMN_LEN] = {0};
VfxWChar VappDtcntInitial::s_dtcntConf[MMI_SIM_TOTAL][VAPP_DTCNT_CONF_NAME_LEN] = {0};

VfxBool VappDtcntInitial::s_firstProcPlmnEvt = VFX_TRUE;
VfxU16 VappDtcntInitial::s_dtcntPlmnEvtNum = 0;
VfxU16 VappDtcntInitial::s_dtcntPlmnProcNum = 0;

#if (MMI_MAX_SIM_NUM >= 2)
VfxU32 VappDtcntInitial::s_simPreferFlag = 0; // don't show popup
#endif

mmi_ret VappDtcntInitial::dtcntNormalInit(mmi_event_struct *evt)
{    
    s_result = srv_dtcnt_store_create();
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_INIT, 1, s_result);

    if (s_result != SRV_DTCNT_RESULT_FS_ERROR)
    {
        s_result = srv_dtcnt_store_open();
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_INIT, 3, s_result);

        if (s_result == SRV_DTCNT_RESULT_FS_ERROR)
        {
            /* popup failure message */
            return MMI_RET_OK;
        }
        
        if (s_result == SRV_DTCNT_RESULT_RESET_FACTORY)
        {
            s_dtcntFactory = VFX_TRUE;
        }
    }

#ifdef __COSMOS_DTCNT_CCA_SUPPORT__
    vappDtcntProvRegEvent(NULL);
#endif

    return MMI_RET_OK;
}


void VappDtcntInitial::dtcntInit()
{
    VfxU32 i;
    
    if (s_result == SRV_DTCNT_RESULT_FS_ERROR)
    {
        return; // open database fail
    }
    s_dtcntInitPLMN |= VAPP_DTCNT_INIT;
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        s_simChanged[i] = VFX_TRUE; // initial value
    }
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_INIT, 4, 0);

    if (srv_sim_ctrl_get_one_available_sim())
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_INIT, 5, 0);
        VappDtcntSimAvailableInfo::resetAvailableSim();
        if (s_dtcntInitPLMN & VAPP_DTCNT_PLMN)
        {
            dtcntOnHomePlmnChanged(NULL);
        }
        
        return;
    }

    if (s_result == SRV_DTCNT_RESULT_FIRST_BOOTUP)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_INIT, 7, s_result);
    }
    else
    {
        VfxU8 simCardId[4 * VAPP_DTCNT_MAX_PLMN_LEN + 1];
        VfxS16 error;

        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_INIT, 9, s_result);
        memset(simCardId, 0, 4 * VAPP_DTCNT_MAX_PLMN_LEN + 1);
        ReadRecord(NVRAM_EF_DTCNT_SIM_ID_LID, 1, &simCardId, NVRAM_MAX_DTCNT_SIM_ID_SIZE, &error);
        if (simCardId[0] || simCardId[VAPP_DTCNT_MAX_PLMN_LEN] ||
            simCardId[VAPP_DTCNT_MAX_PLMN_LEN * 2] || simCardId[VAPP_DTCNT_MAX_PLMN_LEN * 3])
        {
            memset(simCardId, 0, 4 * VAPP_DTCNT_MAX_PLMN_LEN + 1);
            WriteRecord(NVRAM_EF_DTCNT_SIM_ID_LID, 1, &simCardId, NVRAM_MAX_DTCNT_SIM_ID_SIZE, &error);
            dtcntSimProfDelete();
        }
    }
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_INIT, 10, 0);

    dtcntGetDefinedProf();
}


mmi_ret VappDtcntInitial::dtcntOnHomePlmnChanged(mmi_event_struct *evt)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_PROCESS_SIM_CHANGE, 0);
    mmi_sim_enum sim_enum = MMI_SIM1;
    VfxU32 i;

    if(s_firstProcPlmnEvt)
    {
        for (i = 0; i < MMI_SIM_TOTAL; i++)
        {
            sim_enum = mmi_frm_index_to_sim(i);
            if (srv_sim_ctrl_is_available(sim_enum))
            {
                s_dtcntPlmnEvtNum++;
            }
        }
        s_firstProcPlmnEvt = MMI_FALSE;
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_ON_HOME_PLMN_CHANGED, 0, 1, s_dtcntPlmnEvtNum);
    }
    s_dtcntPlmnProcNum++;
    if (s_dtcntPlmnProcNum < s_dtcntPlmnEvtNum)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_ON_HOME_PLMN_CHANGED, 0, 2, s_dtcntPlmnProcNum);
        return MMI_RET_OK;
    }
    
    if (s_dtcntInitPLMN & VAPP_DTCNT_INIT_PLMN)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_PROCESS_SIM_CHANGE, 2);
        return MMI_RET_OK;
    }

    s_dtcntInitPLMN |= VAPP_DTCNT_PLMN;

    if ((s_dtcntInitPLMN & VAPP_DTCNT_INIT) != VAPP_DTCNT_INIT)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_PROCESS_SIM_CHANGE, 4);
        return MMI_RET_OK;
    }

    if (!dtcntIsSimCardChanged() && !s_dtcntFactory)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_PROCESS_SIM_CHANGE, 6);
        s_dtcntInitPLMN |= VAPP_DTCNT_INIT_PLMN;
        dtcntGetDefinedProf();

        return MMI_RET_OK;
    }

    if (s_dtcntFactory)
    {
        for (i = 0; i < MMI_SIM_TOTAL; i++)
        {
            s_simChanged[i] = MMI_TRUE;
        }
    }
    /* delete sim profile */
    dtcntSimProfDelete();

    /* add pre-install account */
    dtcntPreInstallParse();

    s_dtcntInitPLMN |= VAPP_DTCNT_INIT_PLMN;

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_PROCESS_SIM_CHANGE, 10);

    return MMI_RET_OK;
}


void VappDtcntInitial::dtcntAddConfigAccount()
{
    srv_dtcnt_store_prof_data_struct profInfo;
    VfxU32 acctId;
    VfxU8 simMatch;

#ifdef __MMI_GPRS_FEATURES__
    srv_dtcnt_prof_gprs_struct *gprsAccount, gprsAcctTmp;

    /* save gprs account */
    profInfo.prof_type = SRV_DTCNT_BEARER_GPRS;    
    profInfo.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;
    gprsAccount = (srv_dtcnt_prof_gprs_struct *)custom_config_get_account(SRV_DTCNT_BEARER_GPRS);
    
    while (gprsAccount)
    {
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        if (!gprsAccount->APN)
        {
            gprsAccount = (srv_dtcnt_prof_gprs_struct *)custom_config_get_account(SRV_DTCNT_BEARER_GPRS);
            continue;
        }
        gprsAcctTmp = *gprsAccount;
        gprsAccount = &gprsAcctTmp;
        simMatch = dtcntSimMatch(NULL, (VfxS8 *)gprsAccount->prof_common_header.user_data);

        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_ADD_CONFIG_ACCOUNT, 1, simMatch);

        /* add code to process sim match */

        if (simMatch)
        {
            gprsAccount->prof_common_header.sim_info = SRV_DTCNT_SIM_TYPE_1;
            profInfo.prof_data = gprsAccount;
            dtcntAddSimProf(simMatch, 
                &(gprsAccount->prof_common_header.sim_info), 
                &profInfo, 
                &acctId);
        }

        gprsAccount = (srv_dtcnt_prof_gprs_struct *)custom_config_get_account(SRV_DTCNT_BEARER_GPRS);
    }
#endif
#ifdef __TCPIP_OVER_CSD__
    srv_dtcnt_prof_csd_struct *csdAccount, csdAcctTmp;
    /* save csd account */
    profInfo.prof_type = SRV_DTCNT_BEARER_CSD;    
    profInfo.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;
    csdAccount = (srv_dtcnt_prof_csd_struct *)custom_config_get_account(SRV_DTCNT_BEARER_CSD);

    while (csdAccount)
    {
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        if (!csdAccount->DialNumber)
        {
            csdAccount = (srv_dtcnt_prof_csd_struct *)custom_config_get_account(SRV_DTCNT_BEARER_CSD);
            continue;
        }
        csdAcctTmp = *csdAccount;
        csdAccount = &csdAcctTmp;
        simMatch = dtcntSimMatch(NULL, (VfxS8 *)csdAccount->prof_common_header.user_data);
        
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_ADD_CONFIG_ACCOUNT, 2, simMatch);

        /* add code to process sim match */
        if (simMatch)
        {
            csdAccount->prof_common_header.sim_info = SRV_DTCNT_SIM_TYPE_1;
            profInfo.prof_data = csdAccount;
            dtcntAddSimProf(simMatch, 
                &(csdAccount->prof_common_header.sim_info), 
                &profInfo, 
                &acctId);
        }

        csdAccount = (srv_dtcnt_prof_csd_struct *)custom_config_get_account(SRV_DTCNT_BEARER_CSD);
    }
#endif
}


VfxU8 VappDtcntInitial::dtcntSimMatch(const VfxS8 *operate, const VfxS8 *code)
{
    const VfxChar *simId = "00000";
    VfxU8 simMatch = 0;
    VfxU32 i;
    
    if (code == NULL)
    {
        return simMatch;
    }
    
    if (strcmp((char*)code, (char*)simId) == 0)
    {
        for (i = 0; i < MMI_SIM_TOTAL; i++)
        {
            if ((s_dtcntSim[i][0] != 0) && s_simChanged[i])
            {
                simMatch += (U8)mmi_frm_index_to_sim(i);
            }
        }
    }
    else
    {
        for (i = 0; i < MMI_SIM_TOTAL; i++)
        {
            if ((s_dtcntSim[i][0] != 0) && strstr((char*)code, (char*)s_dtcntSim[i]) && s_simChanged[i])
            {
                simMatch += (U8)mmi_frm_index_to_sim(i);
            }
        }    
    }    
    return simMatch;
}


srv_dtcnt_result_enum VappDtcntInitial::dtcntAddSimProf(VfxU8 simMatch, 
                        srv_dtcnt_sim_type_enum *simInfo,    
                        srv_dtcnt_store_prof_data_struct *prof,
                        VfxU32 *acctId)
{
    srv_dtcnt_result_enum result = SRV_DTCNT_RESULT_FAILED;
    VfxU32 i;
    
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (simMatch & mmi_frm_index_to_sim(i))
        {
            *simInfo = (srv_dtcnt_sim_type_enum)(SRV_DTCNT_SIM_TYPE_1 + i);
            result = srv_dtcnt_store_add_prof(prof, acctId);
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_ADD_SIM_PROF, *acctId, result);
        }
    }
    return result;
}


void VappDtcntInitial::dtcntDeleteAnySimProfile(srv_dtcnt_sim_type_enum sim)
{
    srv_dtcnt_store_prof_qry_filter_struct deleteQuery;
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DELETE_ANY_SIM_PROFILE, sim);
    memset(&deleteQuery, 0, sizeof(deleteQuery));
    deleteQuery.filters = SRV_DTCNT_STORE_QRY_TYPE_ACC_TYPE | SRV_DTCNT_STORE_QRY_TYPE_SIM;
    deleteQuery.sim_qry_info = sim;

    /* Delete Factory Profile */
    deleteQuery.acc_type_info = SRV_DTCNT_PROF_TYPE_FACTORY_CONF;
    srv_dtcnt_store_delete_prof_by_qry(&deleteQuery, MMI_TRUE, NULL, (srv_dtcnt_store_delete_cb_func_ptr)dtcntBootupDeleteAccountCallback);

    /* Delete SIM Profile */
    deleteQuery.acc_type_info = SRV_DTCNT_PROF_TYPE_SIM_PROF;
    srv_dtcnt_store_delete_prof_by_qry(&deleteQuery, MMI_TRUE, NULL, (srv_dtcnt_store_delete_cb_func_ptr)dtcntBootupDeleteAccountCallback);

    /* Delete DM Profile */
    deleteQuery.acc_type_info = SRV_DTCNT_PROF_TYPE_DM_CONF;
    srv_dtcnt_store_delete_prof_by_qry(&deleteQuery, MMI_TRUE, NULL, (srv_dtcnt_store_delete_cb_func_ptr)dtcntBootupDeleteAccountCallback);
}


void VappDtcntInitial::dtcntSimProfDelete()
{
    VfxU32 i;
    
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (s_simChanged[i])
        {
            dtcntDeleteAnySimProfile((srv_dtcnt_sim_type_enum)(SRV_DTCNT_SIM_TYPE_1 + i));
        }
    }
}

VfxS32 VappDtcntInitial::dtcntIsConfFileExit()
{
#if defined(__XML_SUPPORT__)
    FS_HANDLE acctFileHandle;
    VfxU32 i,j;
    MMI_BOOL need_fs_open = MMI_TRUE;

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (!mmi_wcscmp(s_dtcntConf[i], s_dtcntConf[j]))
            {
                need_fs_open = MMI_FALSE;
                break;
            }
        }
        if (need_fs_open)
        {
            acctFileHandle = FS_Open((kal_wchar*)s_dtcntConf[i], FS_READ_ONLY);
            if (acctFileHandle >= FS_NO_ERROR)
            {
                FS_Close(acctFileHandle);
                s_dtcntFileExist += (S32)mmi_frm_index_to_sim(i);
            }
        }
        need_fs_open = MMI_TRUE;
    }
    return s_dtcntFileExist;
#else
    return 0;
#endif 
}

void VappDtcntInitial::dtcntPreInstallParse()
{
    VfxS32 acctFile;
    VfxU32 i;
    mmi_sim_enum simEnum = MMI_SIM1;
    #if defined(__XML_SUPPORT__)
    acctFile = dtcntIsConfFileExit();

    if (acctFile)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_PRE_INSTALL_PARSE, 1);

        for (i = 0; i < MMI_SIM_TOTAL; i++)
        {
            simEnum = mmi_frm_index_to_sim(i);
            if (acctFile & simEnum)
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_XML_PARSE_SIM, simEnum);
                s_dtcntFileExist -= simEnum;
                vapp_dtcnt_xml_parse(s_dtcntConf[i]);
                break;
            } 
        }
    }
    else
    #endif
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_PRE_INSTALL_PARSE, 3);

        dtcntAddConfigAccount();
        dtcntGetDefinedProf();
    }
}

void VappDtcntInitial::dtcntGetDefinedProf()
{
    srv_dtcnt_result_enum result;
    srv_dtcnt_store_prof_qry_struct acctIdQuery;   
    srv_dtcnt_connection_type_enum connType;
    srv_dtcnt_sim_type_enum simInfo;
    srv_dtcnt_bearer_enum bearer;
    VfxU32 i, j;
    MMI_BOOL ret;
    VfxU32 defaultId;
    srv_dtcnt_sim_type_enum simType;

    acctIdQuery.qry_info.filters = SRV_DTCNT_STORE_QRY_TYPE_ACC_TYPE;

    for (i = 0; i < SRV_DTCNT_PROF_TYPE_DM_CONF; i++)
    {
        acctIdQuery.qry_info.acc_type_info = (srv_dtcnt_prof_acc_type_enum)(SRV_DTCNT_PROF_TYPE_USER_CONF + i);
        result = srv_dtcnt_store_qry_ids(&acctIdQuery);

        if (result == SRV_DTCNT_RESULT_FS_ERROR || acctIdQuery.num_ids > SRV_DTCNT_PROF_MAX_ACCOUNT_NUM)
        {
            VappDtcntReadyCheck::setIsDtcntReady(VFX_FALSE);
            return;
        }
        for (j = 0; j < acctIdQuery.num_ids; j++)
        {
            srv_dtcnt_get_connection_type(acctIdQuery.ids[j], &connType);
            srv_dtcnt_get_sim_info(acctIdQuery.ids[j], &simInfo);
            bearer = srv_dtcnt_get_bearer_type(acctIdQuery.ids[j], SRV_DTCNT_ACCOUNT_PRIMARY);
            VappDtcntDispItem acctItem(acctIdQuery.ids[j], (VfxU8)connType, (VfxU8)simInfo,
                                        (VfxU8)bearer, 0, (srv_dtcnt_prof_acc_type_enum)(SRV_DTCNT_PROF_TYPE_USER_CONF + i));
            if (srv_dtcnt_acct_is_read_only(acctIdQuery.ids[j]))
            {
                acctItem.setReadOnly(1);
            }
            // add acct item
            VappDtcntDispItemList::addAcctItem(acctItem);
        }
    }
    
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        ret = srv_dtcnt_get_default_account((srv_dtcnt_sim_type_enum)(i + SRV_DTCNT_SIM_TYPE_1), &defaultId);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_GET_DEFAULT_ACCOUNT, (i + SRV_DTCNT_SIM_TYPE_1), defaultId, ret);
    }

    ret = srv_dtcnt_get_sim_preference(&simType);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_GET_SIM_PREFERENCE, simType, ret);
    mmi_sim_enum availSimEnum = MMI_SIM_NONE;
    availSimEnum = (mmi_sim_enum)srv_sim_ctrl_get_one_available_sim();
    if (!availSimEnum)
    {
        ret = srv_dtcnt_set_sim_preference(SRV_DTCNT_SIM_TYPE_NONE);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_SET_SIM_PREFERENCE, SRV_DTCNT_SIM_TYPE_NONE, ret);
    }
    else
    {
        VfxU32 availSimIndex = 0;
        availSimIndex = mmi_frm_sim_to_index(availSimEnum);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_GET_SIM_PREFERENCE, availSimEnum, availSimIndex);
        if (simType == SRV_DTCNT_SIM_TYPE_NONE ||
            !srv_sim_ctrl_is_available(mmi_frm_index_to_sim((U32)simType - 1)))
        {
            ret = srv_dtcnt_set_sim_preference((srv_dtcnt_sim_type_enum)(availSimIndex + 1));
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_SET_SIM_PREFERENCE, availSimIndex + 1, ret);
        #if (MMI_MAX_SIM_NUM >= 2)
            s_simPreferFlag = availSimIndex + 1;
        #endif
        }
    }
    VappDtcntAcctValidity::syncInvalidInfowithSrv(); 

    VappDtcntReadyCheck::setIsDtcntReady(VFX_TRUE);
    VappDtcntReadyCheck::executeReadyCheckCB();
}

void VappDtcntInitial::dtcntBootupDeleteAccountCallback(VfxU32 deletingAccId, void *user_data)
{
    return;
}


VfxBool VappDtcntInitial::dtcntIsSimCardChanged()
{
    VfxU8 simCardId[4 * VAPP_DTCNT_MAX_PLMN_LEN + 1];
    VfxS16 error;
    VfxBool simChange = MMI_FALSE;
    VfxS8 confName[VAPP_DTCNT_CONF_NAME_LEN * 2];
    VfxU8 *simCardIdTemp;
    VfxBool retn;
    VfxU32 i;
    
    memset(simCardId, 0, 4 * VAPP_DTCNT_MAX_PLMN_LEN + 1);
    ReadRecord(NVRAM_EF_DTCNT_SIM_ID_LID, 1, &simCardId, NVRAM_MAX_DTCNT_SIM_ID_SIZE, &error);

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {        
        simCardIdTemp = &simCardId[VAPP_DTCNT_MAX_PLMN_LEN * i];
        memset(s_dtcntSim[i], 0, VAPP_DTCNT_MAX_PLMN_LEN);
        retn = dtcntGetSimPlmn(mmi_frm_index_to_sim(i), s_dtcntSim[i]);    
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_SIM_CARD_CHANGED, 10, retn);
        if (!retn)
        {
            memset(s_dtcntSim[i], 0, VAPP_DTCNT_MAX_PLMN_LEN);
            if (strcmp((char*)s_dtcntSim[i], (char*)simCardIdTemp))
            {
                memset(simCardIdTemp, 0, VAPP_DTCNT_MAX_PLMN_LEN);
                simChange = VFX_TRUE;
            }
            else
            {
                s_simChanged[i] = VFX_FALSE;
            }
        }
        else
        {
            sprintf((char*)confName, "z:\\%s.xml", s_dtcntSim[i]);
            mmi_asc_to_ucs2((char*) s_dtcntConf[i], (char*) confName);
            //MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G6_DTCNT, "[DTCNT APP] sim id = %s-%s : 1", (char *)s_dtcntSim[i], (char *)simCardIdTemp);

            if (strcmp((char*)s_dtcntSim[i], (char*)simCardIdTemp)) /* SIM1 changed */
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_SIM_CARD_CHANGED, 11, 1); // sim1 changed
        
                strcpy((char*)simCardIdTemp, (char*)s_dtcntSim[i]);
                 simChange = MMI_TRUE;
            }
            else
            {
                s_simChanged[i] = MMI_FALSE;
            }
        }
    }
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_SIM_CARD_CHANGED, 50, simChange);

    if (simChange)
    {
        WriteRecord(NVRAM_EF_DTCNT_SIM_ID_LID, 1, &simCardId, NVRAM_MAX_DTCNT_SIM_ID_SIZE, &error);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_SIM_CARD_CHANGED, 51, simChange);
    }
    return simChange;
}


VfxBool VappDtcntInitial::dtcntGetSimPlmn(mmi_sim_enum sim, VfxS8 *out_buffer)
{
    VfxBool retn = VFX_FALSE;
    VfxS32 end = SRV_MAX_PLMN_LEN;
    VfxS32 digits_of_mnc;
    VfxChar imsi[SRV_MAX_IMSI_LEN + 1];
    VfxChar temp_mcc[SRV_MCC_LEN + 1];

    if (srv_sim_ctrl_is_available(sim))
    {
	MMI_BOOL ret = srv_sim_ctrl_get_home_plmn(sim, (CHAR*)out_buffer, VAPP_DTCNT_MAX_PLMN_LEN);
        retn = (ret == MMI_TRUE ? VFX_TRUE : VFX_FALSE);
        if (retn)
        {
            // get mnc length
            digits_of_mnc = (VfxS32)srv_sim_ctrl_get_mnc_len_in_ef_ad(sim); //TODO:            
            /*MMI_PRINT(
                MOD_MMI_CONN_APP, 
                MMI_CONN_TRC_G6_DTCNT, 
                "[DTCNT APP] srv_sim_ctrl_get_mnc_len_in_ef_ad, digits_of_mnc = %d, sim = %d",
                digits_of_mnc, sim);*/
            if ((digits_of_mnc != 0x2) || (digits_of_mnc != 0x3))
            {
                memset(temp_mcc, 0, (SRV_MCC_LEN + 1));
                strncpy((char*)temp_mcc, (char*)out_buffer, SRV_MCC_LEN);
                if (0 == strcmp((char*)temp_mcc, "405"))
                {
                    memset(imsi, 0, (SRV_MAX_IMSI_LEN + 1));
                    if (MMI_TRUE == srv_sim_ctrl_get_imsi(sim, (CHAR*)imsi, SRV_MAX_IMSI_LEN + 1))
                    {
                        switch(imsi[4])
                        {
                            case '0':
                            {
                                switch(imsi[5])
                                {
                                    case '1':
                                    case '5':
                                    case '6':
                                    case '7':
                                    case '8':
                                    case '9':
                                        digits_of_mnc = 2;
                                        break;
                                    default:
                                        digits_of_mnc = 3;
                                        break;
                                }
                            }
                            break;
                            case '1':
                            case '2':
                            {
                                digits_of_mnc = 2;
                            }
                            break;
                            case '4':
                            {
                                if(imsi[5] == '8')
                                {
                                    digits_of_mnc = 2;
                                }
                                else
                                {
                                    digits_of_mnc = 3;
                                }
                            }
                            break;
                            case '5':
                            case '6':
                            {
                                digits_of_mnc = 2;
                            }
                            break;
                            case '7':
                            {
                                if(imsi[5] == '0')
                                {
                                    digits_of_mnc = 2;
                                }
                                else
                                {
                                    digits_of_mnc = 3;
                                }
                            }
                            break;
                            default:
                            {
                                digits_of_mnc = 3;
                            }
                            break;
                        }                        
                        /*MMI_PRINT(
                            MOD_MMI_CONN_APP, 
                            MMI_CONN_TRC_G6_DTCNT, 
                            "[DTCNT APP] srv_sim_ctrl_get_imsi, imsi[4] = %c, imsi[5] = %c, digits_of_mnc = %d",
                            imsi[4], imsi[5], digits_of_mnc);*/
                        if (digits_of_mnc == 3)
                        {
                            strncpy((char*)out_buffer, (char*)&(imsi[1]), SRV_MAX_PLMN_LEN);
                        }
                    }
                }
            }
        }
        out_buffer[end] = 0;
    }

    return retn;
}


// following for xml parser functions
void *VappDtcntInitial::dtcntAccountItemStart(VfxS32 bearer)
{
    void *bearer_p = NULL;
    
    //initial global variable
    memset(s_accountName, 0x00, (MAX_DATA_ACCOUNT_NAME_LEN + 1) * sizeof(U16));
    memset(s_address, 0x00, (MAX_DTCNT_LIST_ADDR_LEN));
    
#ifdef __TCPIP_OVER_CSD__
    if(SRV_DTCNT_BEARER_CSD == bearer)
    {
        memset(&s_csdProfileSrv, 0, sizeof(srv_dtcnt_prof_csd_struct));
        s_csdProfileSrv.DialNumber = (U8*)s_address;
        s_csdProfileSrv.prof_common_header.AccountName = (U8*)s_accountName;
        s_csdProfileSrv.prof_common_header.px_service = SRV_DTCNT_PROF_PX_SRV_HTTP;
        s_csdProfileSrv.DataRate = SRV_DTCNT_PROF_CSD_RATE_NINE_SIX;
        s_csdProfileSrv.prof_common_header.acct_type = SRV_DTCNT_PROF_TYPE_FACTORY_CONF;
        bearer_p = &s_csdProfileSrv;
    }
#endif
#ifdef __MMI_GPRS_FEATURES__
    if(SRV_DTCNT_BEARER_GPRS == bearer)
    {
        memset(&s_gprsProfileSrv, 0, sizeof(srv_dtcnt_prof_gprs_struct));
        s_gprsProfileSrv.APN = (U8*)s_address;
        s_gprsProfileSrv.prof_common_header.AccountName = (U8*)s_accountName;
        s_gprsProfileSrv.prof_common_header.px_service = SRV_DTCNT_PROF_PX_SRV_HTTP;
        s_gprsProfileSrv.prof_common_header.acct_type = SRV_DTCNT_PROF_TYPE_FACTORY_CONF;
        bearer_p = &s_gprsProfileSrv;
    }
#endif
    return bearer_p;
}


VfxS32 VappDtcntInitial::dtcntGetItemVaule(VappDtcntParserItemTypeEnum option, const VfxChar* name)
{
    if (!name)
    {
        return 0;
    }
    switch (option)
    {
        case VAPP_DTCNT_PARSER_ITEM_TYPE_CONNECTION:
        {
            if (strcmp(name, "WAP") == 0)
            {
                return SRV_DTCNT_PROF_PX_SRV_CO_WSP;
            }
            else if (strcmp(name, "HTTP") == 0)
            {
                return SRV_DTCNT_PROF_PX_SRV_HTTP;
            }
            else
            {
            #if 0
/* under construction !*/
            #endif
                return SRV_DTCNT_PROF_PX_SRV_HTTP; 
            }
        }
        case VAPP_DTCNT_PARSER_ITEM_TYPE_APP:
        {
            return mmi_custom_account_get_apptype(name);
        }
        case VAPP_DTCNT_PARSER_ITEM_TYPE_DIAL_TYPE:
        {
            if (strcmp(name, "Analogue") == 0)
            {
                return 0;
            }
            else if (strcmp(name, "ISDN") == 0)
            {
                return 1;
            }
            else
            {
                return 0; 
            }
        }
        case VAPP_DTCNT_PARSER_ITEM_TYPE_DATA_RATE:
        {
            if (strcmp(name, "2.4") == 0)
            {
                return 0;
            }
            else if (strcmp(name, "4.8") == 0)
            {
                return 1;
            }
            else if (strcmp(name, "9.6") == 0)
            {
                return 2;
            }
            else if (strcmp(name, "14.4") == 0)
            {
                return 3; 
            }
            else if (strcmp(name, "Auto") == 0)
            {
                return 4;
            }
            else
            {
                return 2;
            }
        }
        case VAPP_DTCNT_PARSER_ITEM_TYPE_AUTH:
        {
            if (strcmp(name, "Normal") == 0)
            {
                return 0;
            }
            else if (strcmp(name, "Secure") == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        default:
        {
            return 0;
        }
    }
}


VfxBool VappDtcntInitial::dtcntGetIpAddress(VfxU8 *ip, const VfxChar *data)
{
    if (!data)
    {
        return VFX_FALSE;
    }
    //
    VfxChar tmp_buf[MAX_PART_IP_ADDRESS * 4];
    strcpy(tmp_buf, data);
    /* not allow blank space */
    if (strchr(tmp_buf, ' '))
    {
        return VFX_FALSE;
    }

    VfxChar *point, *p, *q;
    VfxS32 i = 0;
    p = tmp_buf;
    VfxU16 ip_address[MAX_PART_IP_ADDRESS]; /* use U16 to justify ip value > 255 */
    while ((i < MAX_PART_IP_ADDRESS) && p)
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
        ip_address[i] = atoi(p);
        p = q;
        if (ip_address[i++] > 255)
        {
            return VFX_FALSE;
        }
    }
    if (i != MAX_PART_IP_ADDRESS)
    {
        return VFX_FALSE;
    }
    for (i = 0; i < MAX_PART_IP_ADDRESS; i++)
    {
        ip[i] = (U8)ip_address[i];
    }
    return VFX_TRUE;
}


void VappDtcntInitial::dtcntAccountItemEnd(VfxS32 bearer, void *user_data)
{
    srv_dtcnt_store_prof_data_struct profInfo;
    U32 acctId;
    srv_dtcnt_result_enum result;
    srv_dtcnt_prof_gprs_struct *gprsProf;
    VfxU8 simMatch;
    VfxU32 i;

#ifdef __TCPIP_OVER_CSD__
    srv_dtcnt_prof_csd_struct *csdProf;

    if (bearer == SRV_DTCNT_BEARER_CSD)
    {
        // get data
        csdProf = (srv_dtcnt_prof_csd_struct*)user_data;
        
        profInfo.prof_type = SRV_DTCNT_BEARER_CSD;
        profInfo.prof_data = csdProf;
        profInfo.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;

        if (!strlen((char*)csdProf->DialNumber))
        {
            return;
        }
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        if (csdProf->prof_common_header.AppType & DTCNT_APPTYPE_DM)
        {
            csdProf->prof_common_header.acct_type = SRV_DTCNT_PROF_TYPE_DM_CONF;
        }
        else
        {            
            csdProf->prof_common_header.acct_type = SRV_DTCNT_PROF_TYPE_FACTORY_CONF;
        }
        //mmi_dtcnt_save_csd_display_context();
        simMatch = csdProf->prof_common_header.sim_info;
        for (i = 0; i < MMI_SIM_TOTAL; i++)
        {
            if (simMatch & mmi_frm_index_to_sim(i))
            {
                csdProf->prof_common_header.sim_info = (srv_dtcnt_sim_type_enum)(SRV_DTCNT_SIM_TYPE_1 + i);
                result = srv_dtcnt_store_add_prof(&profInfo, &acctId);
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_ADD_SIM_PROF, acctId, result);
            }
        }
    }
#endif
#ifdef __MMI_GPRS_FEATURES__
    if (bearer == SRV_DTCNT_BEARER_GPRS)
    {
        // get data
        gprsProf = (srv_dtcnt_prof_gprs_struct *)user_data;

        profInfo.prof_type = SRV_DTCNT_BEARER_GPRS;
        profInfo.prof_data = gprsProf;
        profInfo.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;

        if (!strlen((char*)gprsProf->APN))
        {
            return;
        }
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        if (gprsProf->prof_common_header.AppType & DTCNT_APPTYPE_DM)
        {
            gprsProf->prof_common_header.acct_type = SRV_DTCNT_PROF_TYPE_DM_CONF;
        }
        else
        {            
            gprsProf->prof_common_header.acct_type = SRV_DTCNT_PROF_TYPE_FACTORY_CONF;
        }
        //mmi_dtcnt_save_gprs_display_context();
        simMatch = gprsProf->prof_common_header.sim_info;
        for (i = 0; i < MMI_SIM_TOTAL; i++)
        {
            if (simMatch & mmi_frm_index_to_sim(i))
            {
                gprsProf->prof_common_header.sim_info = (srv_dtcnt_sim_type_enum)(SRV_DTCNT_SIM_TYPE_1 + i);
                result = srv_dtcnt_store_add_prof(&profInfo, &acctId);
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_ADD_SIM_PROF, acctId, result);
            }
        }
    }
#endif
}


void VappDtcntInitial::dtcntAccountParseEnd(VfxS32 ret)
{
#if defined(__XML_SUPPORT__)    
    VfxU32 i;
    mmi_sim_enum simEnum = MMI_SIM1;
    
    if (s_dtcntFileExist)
    {
        for (i = 0; i < MMI_SIM_TOTAL; i++)
        {
            simEnum = mmi_frm_index_to_sim(i);
            if (s_dtcntFileExist & simEnum)
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_XML_PARSE_SIM, simEnum);
                s_dtcntFileExist -= simEnum;
                vapp_dtcnt_xml_parse(s_dtcntConf[i]);
                break;
            }
        }
    }
    else
    {
        dtcntGetDefinedProf();
    }
#endif
    return;
}


mmi_ret VappDtcntInitial::dtcntOnBootupCompleted(mmi_event_struct *evt)
{
#if (MMI_MAX_SIM_NUM >= 2)
    if(s_simPreferFlag)
    {
        mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_NON_TONE, dtcntSimPreferChangedPopup, NULL);
    }
#endif
    return MMI_RET_OK;
}


MMI_BOOL VappDtcntInitial::dtcntSimPreferChangedPopup(mmi_scenario_id scen_id, void *arg)
{
#if (MMI_MAX_SIM_NUM >= 2)
    if (s_simPreferFlag >= 1)
    {        
        vcp_global_popup_show_confirm_one_button_id(
            GRP_ID_ROOT,
            VCP_POPUP_TYPE_INFO,
            STR_ID_VAPP_DTCNT_CHANGE_TO_SIM1 + s_simPreferFlag - 1,
            STR_GLOBAL_OK,
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            NULL,
            NULL);
    }
#endif    
    return MMI_TRUE;
}

mmi_ret VappDtcntInitial::dtcntSimChanged(mmi_event_struct *evt)
{
#ifdef  __DTCNT_SIM_HOT_SWAP_SUPPORT__
    srv_sim_ctrl_availability_changed_evt_struct *simChanged_evt;
    VfxU32 simIndex = 0;
    VfxU8 simCardId[4 * VAPP_DTCNT_MAX_PLMN_LEN + 1];
    VfxU8 simCardId_temp[VAPP_DTCNT_MAX_PLMN_LEN];
    srv_dtcnt_store_prof_qry_struct acct_id_query;
    //srv_dtcnt_result_enum result;
    U32 i;
    VfxU32 j;
    S16 error;

    simChanged_evt = (srv_sim_ctrl_availability_changed_evt_struct*)evt;
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_ON_SIM_DETECTED, simChanged_evt->is_available_before, simChanged_evt->sim);
    simIndex = mmi_frm_sim_to_index(simChanged_evt->sim);
    if(simChanged_evt->is_available_before != simChanged_evt->is_available_now)
    {    
        VappDtcntSimAvailableInfo::resetAvailableSim();
        if (MMI_TRUE == simChanged_evt->is_available_before)        
        {
            VappDtcntReadyCheck::setIsDtcntReady(VFX_FALSE);
            //delete account in data account service, call srv's interface(srv_dtcnt_store_delete_prof). when account is in use. Need to save it.
            memset(&acct_id_query, 0, sizeof(srv_dtcnt_store_prof_qry_struct));
            acct_id_query.qry_info.filters = SRV_DTCNT_STORE_QRY_TYPE_SIM | SRV_DTCNT_STORE_QRY_TYPE_ACC_TYPE;
            acct_id_query.qry_info.sim_qry_info = (srv_dtcnt_sim_type_enum)(simIndex + 1);
            for (i = SRV_DTCNT_PROF_TYPE_FACTORY_CONF; i < SRV_DTCNT_PROF_TYPE_TOTAL; i++)
            {
                acct_id_query.qry_info.acc_type_info = (srv_dtcnt_prof_acc_type_enum)i;
                srv_dtcnt_store_qry_ids(&acct_id_query);
                for(j = 0; j < acct_id_query.num_ids; j++)
                {
                    if (!VappDtcntDispItemList::isAccountInUse(acct_id_query.ids[j]))
                        {                    
                            srv_dtcnt_store_delete_prof(
                                acct_id_query.ids[j], 
                                MMI_TRUE, 
                                NULL, 
                                NULL);                        
                            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_DTCNT_ON_SIM_DETECTED_DELETED, acct_id_query.ids[j]);
                        }
                        else
                        {
                            VappDtcntDispItemList::addAcctInUse((U8)acct_id_query.ids[j]);
                        }
                    }
                }
            // update PLMN to NVRAM
            memset(simCardId, 0, 4 * VAPP_DTCNT_MAX_PLMN_LEN + 1);
            ReadRecord(NVRAM_EF_DTCNT_SIM_ID_LID, 1, &simCardId, NVRAM_MAX_DTCNT_SIM_ID_SIZE, &error);
            memset(simCardId_temp, 0, VAPP_DTCNT_MAX_PLMN_LEN);
            strcpy((char *)&simCardId[simIndex * VAPP_DTCNT_MAX_PLMN_LEN], (char *) simCardId_temp);
            WriteRecord(NVRAM_EF_DTCNT_SIM_ID_LID, 1, &simCardId, NVRAM_MAX_DTCNT_SIM_ID_SIZE, &error);
            dtcntGetDefinedProf();
            VFX_OBJ_GET_INSTANCE(VappDtcntSimAvailableListener)->m_signalSimChangedEvent.postEmit(VFX_FALSE, simChanged_evt->sim);
        }
        else //insert sim card
        {
            if(VFX_TRUE == VappDtcntReadyCheck::getIsDtcntReady())
            {
                s_dtcntInitPLMN = VAPP_DTCNT_INIT;
                for (i = 0; i < MMI_SIM_TOTAL; i++)
                {
                    s_simChanged[i] = VFX_TRUE; // initial value
                }
                VappDtcntDispItemList::resetAcctItem();
                VappDtcntDispItemList::resetAcctInUse();
                VFX_OBJ_GET_INSTANCE(VappDtcntSimAvailableListener)->m_signalSimChangedEvent.postEmit(VFX_TRUE, simChanged_evt->sim);
                VappDtcntReadyCheck::setIsDtcntReady(VFX_FALSE);
            }
        }
    }
    return MMI_RET_OK; 
#else
    return MMI_RET_OK; 
#endif
}

mmi_ret VappDtcntInitial::dtcntBearerInfoChanged(mmi_event_struct *evt)
{
#ifdef  __DTCNT_SIM_HOT_SWAP_SUPPORT__
	VfxU8 pure_id;
    
    srv_cbm_bearer_info_struct *event = (srv_cbm_bearer_info_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event->state == SRV_CBM_DEACTIVATED)
    {
        pure_id = cbm_get_original_account(event->account_id); 
		VappDtcntDispItemList::deleteAcctInUse(pure_id);
    }
    return MMI_RET_OK;
#else
    return MMI_RET_OK;
#endif
}
#endif
